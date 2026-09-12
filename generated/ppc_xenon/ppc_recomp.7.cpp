#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82171C48"))) PPC_WEAK_FUNC(sub_82171C48);
PPC_FUNC_IMPL(__imp__sub_82171C48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r11,48(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// bgt cr6,0x82171c84
	if (cr6.gt) goto loc_82171C84;
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// b 0x82171c90
	goto loc_82171C90;
loc_82171C84:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
loc_82171C90:
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// bgt cr6,0x82171cac
	if (cr6.gt) goto loc_82171CAC;
	// lbz r10,9(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// b 0x82171cb8
	goto loc_82171CB8;
loc_82171CAC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r10,r7
	ctx.r10.s64 = ctx.r7.s8;
loc_82171CB8:
	// lbz r7,5(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// bgt cr6,0x82171cd4
	if (cr6.gt) goto loc_82171CD4;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// b 0x82171ce0
	goto loc_82171CE0;
loc_82171CD4:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// extsb r11,r7
	r11.s64 = ctx.r7.s8;
loc_82171CE0:
	// lwz r9,52(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// rlwinm r5,r11,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r7,r10,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r8,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r5,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r8,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821712f0
	ctx.lr = 0x82171D24;
	sub_821712F0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82171D34"))) PPC_WEAK_FUNC(sub_82171D34);
PPC_FUNC_IMPL(__imp__sub_82171D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171D38"))) PPC_WEAK_FUNC(sub_82171D38);
PPC_FUNC_IMPL(__imp__sub_82171D38) {
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
	// bl 0x823d91f0
	ctx.lr = 0x82171D40;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x82171d78
	if (cr6.gt) goto loc_82171D78;
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// extsb r28,r10
	r28.s64 = ctx.r10.s8;
	// b 0x82171d84
	goto loc_82171D84;
loc_82171D78:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// extsb r28,r9
	r28.s64 = ctx.r9.s8;
loc_82171D84:
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x82171da0
	if (cr6.gt) goto loc_82171DA0;
	// lbz r10,9(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// extsb r29,r10
	r29.s64 = ctx.r10.s8;
	// b 0x82171dac
	goto loc_82171DAC;
loc_82171DA0:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r9,1(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r29,r9
	r29.s64 = ctx.r9.s8;
loc_82171DAC:
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x82171dc8
	if (cr6.gt) goto loc_82171DC8;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// extsb r30,r11
	r30.s64 = r11.s8;
	// b 0x82171dd4
	goto loc_82171DD4;
loc_82171DC8:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// extsb r30,r10
	r30.s64 = ctx.r10.s8;
loc_82171DD4:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82171c48
	ctx.lr = 0x82171DE0;
	sub_82171C48(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r7,r30,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r28,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r29,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,112
	r31.s64 = ctx.r1.s64 + 112;
	// vmulfp128 v58,v59,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r7,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r9,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r8,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// vaddfp128 v57,v62,v58
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32)));
	// vaddfp128 v56,v61,v58
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32)));
	// vaddfp128 v55,v60,v58
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821712f0
	ctx.lr = 0x82171E44;
	sub_821712F0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82171E4C"))) PPC_WEAK_FUNC(sub_82171E4C);
PPC_FUNC_IMPL(__imp__sub_82171E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171E50"))) PPC_WEAK_FUNC(sub_82171E50);
PPC_FUNC_IMPL(__imp__sub_82171E50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// extsb r11,r4
	r11.s64 = ctx.r4.s8;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stbx r5,r11,r10
	PPC_STORE_U8(r11.u32 + ctx.r10.u32, ctx.r5.u8);
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// stb r6,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82171E70"))) PPC_WEAK_FUNC(sub_82171E70);
PPC_FUNC_IMPL(__imp__sub_82171E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v1,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82171E7C"))) PPC_WEAK_FUNC(sub_82171E7C);
PPC_FUNC_IMPL(__imp__sub_82171E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171E80"))) PPC_WEAK_FUNC(sub_82171E80);
PPC_FUNC_IMPL(__imp__sub_82171E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v3,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stvx128 v2,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x821712f0
	ctx.lr = 0x82171EC0;
	sub_821712F0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82171ED0"))) PPC_WEAK_FUNC(sub_82171ED0);
PPC_FUNC_IMPL(__imp__sub_82171ED0) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82171ED8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lbz r11,66(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 66);
	// extsb r29,r11
	r29.s64 = r11.s8;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82171f58
	if (!cr6.gt) goto loc_82171F58;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_82171F0C:
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// rlwinm r10,r31,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lvx128 v63,r10,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821740d0
	ctx.lr = 0x82171F34;
	sub_821740D0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x82171f40
	if (!cr6.eq) goto loc_82171F40;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82171F40:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// and r30,r30,r3
	r30.u64 = r30.u64 & ctx.r3.u64;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// stwx r3,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, ctx.r3.u32);
	// blt cr6,0x82171f0c
	if (cr6.lt) goto loc_82171F0C;
loc_82171F58:
	// lis r12,160
	r12.s64 = 10485760;
	// ori r12,r12,41120
	r12.u64 = r12.u64 | 41120;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82171F7C"))) PPC_WEAK_FUNC(sub_82171F7C);
PPC_FUNC_IMPL(__imp__sub_82171F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171F80"))) PPC_WEAK_FUNC(sub_82171F80);
PPC_FUNC_IMPL(__imp__sub_82171F80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r11,65(r3)
	PPC_STORE_U8(ctx.r3.u32 + 65, r11.u8);
	// stb r11,67(r3)
	PPC_STORE_U8(ctx.r3.u32 + 67, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,66(r3)
	PPC_STORE_U8(ctx.r3.u32 + 66, r11.u8);
	// stfs f0,60(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stb r9,64(r3)
	PPC_STORE_U8(ctx.r3.u32 + 64, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82171FB4"))) PPC_WEAK_FUNC(sub_82171FB4);
PPC_FUNC_IMPL(__imp__sub_82171FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171FB8"))) PPC_WEAK_FUNC(sub_82171FB8);
PPC_FUNC_IMPL(__imp__sub_82171FB8) {
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
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82171fe4
	if (cr6.eq) goto loc_82171FE4;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82171868
	ctx.lr = 0x82171FE4;
	sub_82171868(ctx, base);
loc_82171FE4:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r30,0
	r30.s64 = 0;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82172000
	if (cr6.eq) goto loc_82172000;
	// addi r3,r11,-4
	ctx.r3.s64 = r11.s64 + -4;
	// bl 0x82130588
	ctx.lr = 0x82172000;
	sub_82130588(ctx, base);
loc_82172000:
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82130588
	ctx.lr = 0x8217200C;
	sub_82130588(ctx, base);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
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

__attribute__((alias("__imp__sub_82172028"))) PPC_WEAK_FUNC(sub_82172028);
PPC_FUNC_IMPL(__imp__sub_82172028) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82172030;
	// lbz r11,67(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 67);
	// li r29,0
	r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82172184
	if (!cr6.gt) goto loc_82172184;
	// li r31,0
	r31.s64 = 0;
	// li r30,1
	r30.s64 = 1;
loc_8217204C:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r7,0
	ctx.r7.s64 = 0;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r4,r10
	ctx.r4.s64 = ctx.r10.s8;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x8217216c
	if (!cr6.gt) goto loc_8217216C;
loc_82172068:
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpw cr6,r5,r4
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, xer);
	// bge cr6,0x8217207c
	if (!cr6.lt) goto loc_8217207C;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
loc_8217207C:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r9,5(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// bgt cr6,0x821720a0
	if (cr6.gt) goto loc_821720A0;
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// lbz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 8);
	// b 0x821720a8
	goto loc_821720A8;
loc_821720A0:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbzx r8,r9,r7
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
loc_821720A8:
	// lbz r9,5(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// bgt cr6,0x821720cc
	if (cr6.gt) goto loc_821720CC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lbz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// b 0x821720d8
	goto loc_821720D8;
loc_821720CC:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
loc_821720D8:
	// dcbt r0,r11
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x821720f8
	if (cr6.gt) goto loc_821720F8;
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// lbz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// b 0x82172100
	goto loc_82172100;
loc_821720F8:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lbzx r9,r10,r7
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r7.u32);
loc_82172100:
	// extsb r10,r9
	ctx.r10.s64 = ctx.r9.s8;
	// lwz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r28,1(r10)
	r28.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r10,r9
	ctx.r10.s64 = ctx.r9.s8;
	// extsb r9,r28
	ctx.r9.s64 = r28.s8;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// bne cr6,0x82172140
	if (!cr6.eq) goto loc_82172140;
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// bne cr6,0x82172140
	if (!cr6.eq) goto loc_82172140;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// slw r9,r30,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (r30.u32 << (ctx.r7.u8 & 0x3F));
	// andc r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ~ctx.r9.u64;
	// b 0x8217215c
	goto loc_8217215C;
loc_82172140:
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bne cr6,0x82172160
	if (!cr6.eq) goto loc_82172160;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x82172160
	if (!cr6.eq) goto loc_82172160;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// slw r9,r30,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (r30.u32 << (ctx.r7.u8 & 0x3F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_8217215C:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
loc_82172160:
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// cmpw cr6,r5,r4
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, xer);
	// blt cr6,0x82172068
	if (cr6.lt) goto loc_82172068;
loc_8217216C:
	// lbz r11,67(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 67);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8217204c
	if (cr6.lt) goto loc_8217204C;
loc_82172184:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82172188"))) PPC_WEAK_FUNC(sub_82172188);
PPC_FUNC_IMPL(__imp__sub_82172188) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91e8
	ctx.lr = 0x82172190;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// li r24,16
	r24.s64 = 16;
	// li r25,32
	r25.s64 = 32;
	// li r26,48
	r26.s64 = 48;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r30,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r30,r25
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lvx128 v60,r30,r26
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,2384
	ctx.r3.s64 = ctx.r5.s64 + 2384;
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lis r8,0
	ctx.r8.s64 = 0;
	// addi r9,r4,2352
	ctx.r9.s64 = ctx.r4.s64 + 2352;
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// lvx128 v127,r0,r3
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// vand128 v59,v60,v127
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v127.u8)));
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// vand128 v58,v63,v127
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v127.u8)));
	// lvx128 v126,r0,r9
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r9,r8,57792
	ctx.r9.u64 = ctx.r8.u64 | 57792;
	// vand128 v57,v62,v127
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v127.u8)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vor128 v55,v126,v59
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// vand128 v56,v61,v127
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v127.u8)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x821713c0
	ctx.lr = 0x82172268;
	sub_821713C0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82172404
	if (cr6.eq) goto loc_82172404;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r11,r29,1
	r11.s64 = r29.s64 + 65536;
	// vand128 v53,v54,v127
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v127.u8)));
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v50,r0,r8
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// vand128 v63,v51,v127
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v127.u8)));
	// addi r11,r11,-12976
	r11.s64 = r11.s64 + -12976;
	// vand128 v49,v52,v127
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v127.u8)));
	// vand128 v48,v50,v127
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v127.u8)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vor128 v47,v126,v53
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v48,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r9
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r8
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,708(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 708);
	f31.f64 = double(temp.f32);
	// lfs f30,704(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 704);
	f30.f64 = double(temp.f32);
	// bl 0x82171600
	ctx.lr = 0x82172308;
	sub_82171600(ctx, base);
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f1,696(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 696);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// addi r3,r3,-8848
	ctx.r3.s64 = ctx.r3.s64 + -8848;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// bl 0x8217d460
	ctx.lr = 0x82172324;
	sub_8217D460(ctx, base);
	// lwz r6,692(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// lwz r5,688(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// lfs f13,648(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 648);
	ctx.f13.f64 = double(temp.f32);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// lfs f0,652(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 652);
	f0.f64 = double(temp.f32);
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// lfs f6,708(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 708);
	ctx.f6.f64 = double(temp.f32);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lfs f4,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f4.f64 = double(temp.f32);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// addis r26,r29,1
	r26.s64 = r29.s64 + 65536;
	// lfs f5,704(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 704);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// addi r26,r26,-9840
	r26.s64 = r26.s64 + -9840;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f2,f7,f0
	ctx.f2.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fmuls f3,f8,f13
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fctiwz f13,f2
	ctx.f13.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// fctiwz f0,f3
	f0.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// frsp f2,f10
	ctx.f2.f64 = double(float(ctx.f10.f64));
	// frsp f3,f9
	ctx.f3.f64 = double(float(ctx.f9.f64));
	// bl 0x8217cc80
	ctx.lr = 0x821723C8;
	sub_8217CC80(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8217cfd0
	ctx.lr = 0x821723D8;
	sub_8217CFD0(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82174070
	ctx.lr = 0x821723E8;
	sub_82174070(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82174098
	ctx.lr = 0x821723F4;
	sub_82174098(ctx, base);
	// lis r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r6,52224
	ctx.r4.u64 = ctx.r6.u64 | 52224;
	// stwx r5,r29,r4
	PPC_STORE_U32(r29.u32 + ctx.r4.u32, ctx.r5.u32);
loc_82172404:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82172424"))) PPC_WEAK_FUNC(sub_82172424);
PPC_FUNC_IMPL(__imp__sub_82172424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82172428"))) PPC_WEAK_FUNC(sub_82172428);
PPC_FUNC_IMPL(__imp__sub_82172428) {
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
	PPCVRegister v115{};
	PPCVRegister v116{};
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
	// bl 0x823d91d8
	ctx.lr = 0x82172430;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9c0
	ctx.lr = 0x82172438;
	// addi r12,r1,-192
	r12.s64 = ctx.r1.s64 + -192;
	// bl 0x823dd4ec
	ctx.lr = 0x82172440;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,16
	r27.s64 = 16;
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,32
	r28.s64 = 32;
	// vor128 v115,v1,v1
	simde_mm_store_si128((simde__m128i*)v115.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// li r29,48
	r29.s64 = 48;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lvx128 v60,r6,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lvx128 v59,r6,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r6,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r11,2384
	r31.s64 = r11.s64 + 2384;
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r10,2352
	r26.s64 = ctx.r10.s64 + 2352;
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r6,r1,352
	ctx.r6.s64 = ctx.r1.s64 + 352;
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,384
	r11.s64 = ctx.r1.s64 + 384;
	// vand128 v57,v58,v63
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v62,r0,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,400
	ctx.r10.s64 = ctx.r1.s64 + 400;
	// vand128 v56,v61,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v55,v60,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// vand128 v54,v59,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// vor128 v53,v62,v57
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v56,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821713c0
	ctx.lr = 0x821724E8;
	sub_821713C0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82172a50
	if (cr6.eq) goto loc_82172A50;
	// vspltisw128 v52,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// vupkd3d128 v51,v52,4
	temp.f32 = 3.0f;
	temp.s32 += v52.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v52.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v51 = vTemp;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vpermwi128 v127,v51,234
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x15));
	// vpermwi128 v126,v51,186
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x45));
	// vpermwi128 v125,v51,174
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x51));
	// vpermwi128 v124,v51,171
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x54));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c568
	ctx.lr = 0x82172534;
	sub_8217C568(ctx, base);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v123,r0,r3
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,0
	ctx.r9.s64 = 0;
	// lvx128 v122,r3,r27
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r30,576
	r11.s64 = r30.s64 + 576;
	// vand128 v49,v50,v63
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r31,r1,416
	r31.s64 = ctx.r1.s64 + 416;
	// lvx128 v48,r0,r6
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// lvx128 v47,r0,r5
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,288
	ctx.r7.s64 = ctx.r1.s64 + 288;
	// lvx128 v46,r0,r4
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// vand128 v45,v48,v63
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// vand128 v44,v47,v63
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r26,r1,304
	r26.s64 = ctx.r1.s64 + 304;
	// vand128 v43,v46,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r25,r1,432
	r25.s64 = ctx.r1.s64 + 432;
	// vor128 v42,v62,v49
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// addi r23,r1,320
	r23.s64 = ctx.r1.s64 + 320;
	// lvx128 v121,r3,r28
	simde_mm_store_si128((simde__m128i*)v121.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r22,r1,448
	r22.s64 = ctx.r1.s64 + 448;
	// lvx128 v120,r3,r29
	simde_mm_store_si128((simde__m128i*)v120.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r21,r1,336
	r21.s64 = ctx.r1.s64 + 336;
	// lvx128 v119,r0,r11
	simde_mm_store_si128((simde__m128i*)v119.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r20,r1,464
	r20.s64 = ctx.r1.s64 + 464;
	// lvx128 v118,r11,r27
	simde_mm_store_si128((simde__m128i*)v118.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r9,r9,57792
	ctx.r9.u64 = ctx.r9.u64 | 57792;
	// lvx128 v117,r11,r28
	simde_mm_store_si128((simde__m128i*)v117.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v116,r11,r29
	simde_mm_store_si128((simde__m128i*)v116.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mullw r9,r24,r9
	ctx.r9.s64 = int64_t(r24.s32) * int64_t(ctx.r9.s32);
	// stvx128 v119,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v119.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,708(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 708);
	f31.f64 = double(temp.f32);
	// lfs f30,704(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 704);
	f30.f64 = double(temp.f32);
	// stvx128 v123,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v122,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v121,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v121.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v120,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v120.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v118,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v118.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v117,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v117.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v116,r0,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v116.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r31,r9,r10
	r31.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stvx128 v44,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82171600
	ctx.lr = 0x82172618;
	sub_82171600(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f1,696(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 696);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// addi r3,r3,-10832
	ctx.r3.s64 = ctx.r3.s64 + -10832;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// bl 0x8217d460
	ctx.lr = 0x82172634;
	sub_8217D460(ctx, base);
	// lwz r8,692(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 692);
	// lwz r7,688(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 688);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// lfs f0,648(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 648);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lfs f13,652(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 652);
	ctx.f13.f64 = double(temp.f32);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// addis r26,r31,1
	r26.s64 = r31.s64 + 65536;
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// lfs f31,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r26,r26,-11824
	r26.s64 = r26.s64 + -11824;
	// lfs f6,708(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 708);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,704(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 704);
	ctx.f5.f64 = double(temp.f32);
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// fmuls f3,f8,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmuls f2,f7,f13
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fctiwz f0,f3
	f0.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f13,f2
	ctx.f13.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
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
	// frsp f3,f9
	ctx.f3.f64 = double(float(ctx.f9.f64));
	// frsp f2,f10
	ctx.f2.f64 = double(float(ctx.f10.f64));
	// bl 0x8217cc80
	ctx.lr = 0x821726DC;
	sub_8217CC80(ctx, base);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8217cfd0
	ctx.lr = 0x821726EC;
	sub_8217CFD0(ctx, base);
	// lis r7,0
	ctx.r7.s64 = 0;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// ori r5,r7,52240
	ctx.r5.u64 = ctx.r7.u64 | 52240;
	// addi r6,r6,-13168
	ctx.r6.s64 = ctx.r6.s64 + -13168;
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stvx128 v115,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v115.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,-13040
	ctx.r10.s64 = ctx.r10.s64 + -13040;
	// stvx128 v126,r6,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r6,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r26,r31,1
	r26.s64 = r31.s64 + 65536;
	// stvx128 v124,r6,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r25,r31,1
	r25.s64 = r31.s64 + 65536;
	// lvx128 v41,r0,r11
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r26,-12912
	r26.s64 = r26.s64 + -12912;
	// addi r25,r25,-12784
	r25.s64 = r25.s64 + -12784;
	// stvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v40,r0,r9
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stvx128 v40,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r0,r7
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v123,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v122,r26,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v121,r26,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v121.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v120,r26,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v120.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v119,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v119.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v118,r25,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v118.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v117,r25,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v117.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v116,r25,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v116.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215e000
	ctx.lr = 0x82172788;
	sub_8215E000(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-12656
	r11.s64 = r11.s64 + -12656;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lvx128 v37,r0,r6
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v36,r0,r4
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// stvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r9
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215e000
	ctx.lr = 0x821727D0;
	sub_8215E000(ctx, base);
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r6,r6,-12528
	ctx.r6.s64 = ctx.r6.s64 + -12528;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lvx128 v33,r0,r8
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v32,r0,r7
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// stvx128 v33,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r6,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r6,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r6,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215e000
	ctx.lr = 0x82172818;
	sub_8215E000(ctx, base);
	// addis r7,r31,1
	ctx.r7.s64 = r31.s64 + 65536;
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// addi r7,r7,-12400
	ctx.r7.s64 = ctx.r7.s64 + -12400;
	// addi r6,r1,320
	ctx.r6.s64 = ctx.r1.s64 + 320;
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r7,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r7,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r7,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82171600
	ctx.lr = 0x82172858;
	sub_82171600(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lfs f8,696(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 696);
	ctx.f8.f64 = double(temp.f32);
	// fmr f28,f1
	f28.f64 = ctx.f1.f64;
	// lfs f0,-31064(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -31064);
	f0.f64 = double(temp.f32);
	// fmuls f30,f8,f0
	f30.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmr f29,f30
	f29.f64 = f30.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbf10
	ctx.lr = 0x82172878;
	sub_823DBF10(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(ctx.f1.f64));
	// lfs f26,704(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 704);
	f26.f64 = double(temp.f32);
	// lfs f25,708(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 708);
	f25.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217288C;
	sub_823DBBC8(ctx, base);
	// frsp f24,f1
	ctx.fpscr.disableFlushMode();
	f24.f64 = double(float(ctx.f1.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82172898;
	sub_823DBAE8(ctx, base);
	// frsp f23,f1
	ctx.fpscr.disableFlushMode();
	f23.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f27,f28
	ctx.f1.f64 = double(float(f27.f64 * f28.f64));
	// bl 0x823dccf0
	ctx.lr = 0x821728A4;
	sub_823DCCF0(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3732(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fmuls f29,f6,f13
	f29.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x821728C8;
	sub_823DBBC8(ctx, base);
	// frsp f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = double(float(ctx.f1.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbae8
	ctx.lr = 0x821728D4;
	sub_823DBAE8(ctx, base);
	// frsp f5,f1
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f4,f22,f22
	ctx.f4.f64 = double(float(f22.f64 * f22.f64));
	// lis r9,0
	ctx.r9.s64 = 0;
	// fmuls f3,f24,f24
	ctx.f3.f64 = double(float(f24.f64 * f24.f64));
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r11,0
	r11.s64 = 0;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fmadds f2,f5,f5,f4
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// ori r3,r3,57772
	ctx.r3.u64 = ctx.r3.u64 | 57772;
	// fmadds f1,f23,f23,f3
	ctx.f1.f64 = double(float(f23.f64 * f23.f64 + ctx.f3.f64));
	// ori r5,r5,57764
	ctx.r5.u64 = ctx.r5.u64 | 57764;
	// ori r4,r4,57768
	ctx.r4.u64 = ctx.r4.u64 | 57768;
	// stfs f31,144(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// ori r9,r9,57748
	ctx.r9.u64 = ctx.r9.u64 | 57748;
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// ori r8,r8,57752
	ctx.r8.u64 = ctx.r8.u64 | 57752;
	// lfs f29,14192(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14192);
	f29.f64 = double(temp.f32);
	// ori r7,r7,57756
	ctx.r7.u64 = ctx.r7.u64 | 57756;
	// stfsx f22,r31,r3
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, temp.u32);
	// ori r6,r6,57760
	ctx.r6.u64 = ctx.r6.u64 | 57760;
	// stfsx f25,r31,r5
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, temp.u32);
	// ori r11,r11,57780
	r11.u64 = r11.u64 | 57780;
	// stfsx f24,r31,r4
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// ori r10,r10,57776
	ctx.r10.u64 = ctx.r10.u64 | 57776;
	// stfsx f28,r31,r9
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, temp.u32);
	// stfsx f30,r31,r8
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, temp.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// fsqrts f13,f2
	ctx.f13.f64 = double(float(sqrt(ctx.f2.f64)));
	// stfsx f27,r31,r7
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, temp.u32);
	// stfs f26,152(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// stfsx f5,r31,r11
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f31,156(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r3,r3,-12080
	ctx.r3.s64 = ctx.r3.s64 + -12080;
	// stfsx f26,r31,r6
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, temp.u32);
	// stfsx f23,r31,r10
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, temp.u32);
	// stfs f29,140(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fsqrts f11,f1
	ctx.f11.f64 = double(float(sqrt(ctx.f1.f64)));
	// fmuls f10,f12,f5
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f5.f64));
	// fmuls f9,f12,f22
	ctx.f9.f64 = double(float(ctx.f12.f64 * f22.f64));
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fdivs f8,f0,f11
	ctx.f8.f64 = double(float(f0.f64 / ctx.f11.f64));
	// fneg f7,f10
	ctx.f7.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fneg f6,f9
	ctx.f6.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// stfs f6,96(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f5,f8,f23
	ctx.f5.f64 = double(float(ctx.f8.f64 * f23.f64));
	// fmuls f30,f8,f24
	f30.f64 = double(float(ctx.f8.f64 * f24.f64));
	// fneg f4,f7
	ctx.f4.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// stfs f4,128(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fneg f3,f7
	ctx.f3.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// stfs f3,132(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fneg f28,f5
	f28.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// fneg f27,f30
	f27.u64 = f30.u64 ^ 0x8000000000000000;
	// bl 0x8215e000
	ctx.lr = 0x821729F0;
	sub_8215E000(ctx, base);
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fneg f2,f28
	ctx.f2.u64 = f28.u64 ^ 0x8000000000000000;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fneg f1,f28
	ctx.f1.u64 = f28.u64 ^ 0x8000000000000000;
	// fneg f0,f25
	f0.u64 = f25.u64 ^ 0x8000000000000000;
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f27,112(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// stfs f30,116(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r3,-12016
	ctx.r3.s64 = ctx.r3.s64 + -12016;
	// stfs f2,128(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f1,132(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f29,136(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,144(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,156(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// bl 0x8215e000
	ctx.lr = 0x82172A50;
	sub_8215E000(ctx, base);
loc_82172A50:
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// addi r12,r1,-192
	r12.s64 = ctx.r1.s64 + -192;
	// bl 0x823dd784
	ctx.lr = 0x82172A5C;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba0c
	ctx.lr = 0x82172A64;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82172A68"))) PPC_WEAK_FUNC(sub_82172A68);
PPC_FUNC_IMPL(__imp__sub_82172A68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x82172A70;
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// ori r9,r10,57792
	ctx.r9.u64 = ctx.r10.u64 | 57792;
	// mullw r10,r17,r9
	ctx.r10.s64 = int64_t(r17.s32) * int64_t(ctx.r9.s32);
	// add. r18,r10,r11
	r18.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r18.s32, 0, xer);
	// beq 0x82172af4
	if (cr0.eq) goto loc_82172AF4;
	// addis r11,r18,1
	r11.s64 = r18.s64 + 65536;
	// li r24,0
	r24.s64 = 0;
	// addic. r11,r11,-13280
	xer.ca = r11.u32 > 13279;
	r11.s64 = r11.s64 + -13280;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82172ab0
	if (cr0.eq) goto loc_82172AB0;
	// stw r24,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r24.u32);
	// stw r24,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r24.u32);
loc_82172AB0:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r9,52224
	ctx.r8.u64 = ctx.r9.u64 | 52224;
	// lbz r7,10545(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10545);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lwzx r16,r18,r8
	r16.u64 = PPC_LOAD_U32(r18.u32 + ctx.r8.u32);
	// beq cr6,0x82172ad4
	if (cr6.eq) goto loc_82172AD4;
	// cmpwi cr6,r16,1
	cr6.compare<int32_t>(r16.s32, 1, xer);
	// bge cr6,0x82172b08
	if (!cr6.lt) goto loc_82172B08;
loc_82172AD4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82172af4
	if (cr6.eq) goto loc_82172AF4;
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r11,52264
	ctx.r9.u64 = r11.u64 | 52264;
	// ori r8,r10,52268
	ctx.r8.u64 = ctx.r10.u64 | 52268;
	// stwx r24,r18,r9
	PPC_STORE_U32(r18.u32 + ctx.r9.u32, r24.u32);
	// stwx r24,r18,r8
	PPC_STORE_U32(r18.u32 + ctx.r8.u32, r24.u32);
loc_82172AF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9218
	return;
loc_82172B08:
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r22,r24
	r22.u64 = r24.u64;
	// ori r9,r10,52272
	ctx.r9.u64 = ctx.r10.u64 | 52272;
	// mr r20,r24
	r20.u64 = r24.u64;
	// lwzx r10,r18,r9
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82172af4
	if (cr6.eq) goto loc_82172AF4;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// ori r8,r9,52276
	ctx.r8.u64 = ctx.r9.u64 | 52276;
	// lwzx r31,r18,r8
	r31.u64 = PPC_LOAD_U32(r18.u32 + ctx.r8.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82172af4
	if (cr6.eq) goto loc_82172AF4;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r24,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r24.u32);
	// stw r24,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r24.u32);
	// mr r19,r24
	r19.u64 = r24.u64;
	// ori r9,r10,52260
	ctx.r9.u64 = ctx.r10.u64 | 52260;
	// lwz r23,0(r11)
	r23.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r16,0
	cr6.compare<int32_t>(r16.s32, 0, xer);
	// lwzx r26,r18,r9
	r26.u64 = PPC_LOAD_U32(r18.u32 + ctx.r9.u32);
	// ble cr6,0x82172ca4
	if (!cr6.gt) goto loc_82172CA4;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r21,r18,268
	r21.s64 = r18.s64 + 268;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82172B6C:
	// lwz r11,20(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 20);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82172c94
	if (cr6.eq) goto loc_82172C94;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82172c94
	if (!cr6.eq) goto loc_82172C94;
	// lwz r30,8(r21)
	r30.u64 = PPC_LOAD_U32(r21.u32 + 8);
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// blt cr6,0x82172c94
	if (cr6.lt) goto loc_82172C94;
	// subfic r28,r30,16
	xer.ca = r30.u32 <= 16;
	r28.s64 = 16 - r30.s64;
	// add r25,r28,r30
	r25.u64 = r28.u64 + r30.u64;
	// cmpw cr6,r26,r25
	cr6.compare<int32_t>(r26.s32, r25.s32, xer);
	// blt cr6,0x82172ca4
	if (cr6.lt) goto loc_82172CA4;
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// blt cr6,0x82172ca4
	if (cr6.lt) goto loc_82172CA4;
	// mr r27,r29
	r27.u64 = r29.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82172bd8
	if (!cr6.gt) goto loc_82172BD8;
	// addi r10,r21,-268
	ctx.r10.s64 = r21.s64 + -268;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82172BC0:
	// lvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stvx128 v127,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bne 0x82172bc0
	if (!cr0.eq) goto loc_82172BC0;
loc_82172BD8:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82172c04
	if (!cr6.gt) goto loc_82172C04;
	// stvx128 v127,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r11,r11,-9
	r11.s64 = r11.s64 + -9;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// rlwinm r5,r11,0,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// bl 0x823dadd8
	ctx.lr = 0x82172BFC;
	sub_823DADD8(ctx, base);
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
loc_82172C04:
	// addi r11,r27,32
	r11.s64 = r27.s64 + 32;
	// li r10,4
	ctx.r10.s64 = 4;
loc_82172C0C:
	// addi r9,r11,-32
	ctx.r9.s64 = r11.s64 + -32;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r11,-16
	ctx.r8.s64 = r11.s64 + -16;
	// addi r7,r11,16
	ctx.r7.s64 = r11.s64 + 16;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v62,v63
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v57,v61,v59
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v56,v61,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrglw128 v55,v60,v57
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v54,v58,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v53,v58,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v52,v60,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vxor128 v51,v55,v55
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_setzero_si128());
	// vsubfp128 v50,v51,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// stvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x82172c0c
	if (!cr0.eq) goto loc_82172C0C;
	// subf r11,r28,r26
	r11.s64 = r26.s64 - r28.s64;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r17,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r17.u32);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// add r20,r25,r20
	r20.u64 = r25.u64 + r20.u64;
	// stw r24,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r24.u32);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// subf r26,r30,r11
	r26.s64 = r11.s64 - r30.s64;
loc_82172C94:
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// addi r21,r21,816
	r21.s64 = r21.s64 + 816;
	// cmpw cr6,r19,r16
	cr6.compare<int32_t>(r19.s32, r16.s32, xer);
	// blt cr6,0x82172b6c
	if (cr6.lt) goto loc_82172B6C;
loc_82172CA4:
	// addi r11,r22,3
	r11.s64 = r22.s64 + 3;
	// addi r30,r29,-256
	r30.s64 = r29.s64 + -256;
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpw cr6,r22,r11
	cr6.compare<int32_t>(r22.s32, r11.s32, xer);
	// bge cr6,0x82172cd8
	if (!cr6.lt) goto loc_82172CD8;
	// subf r31,r22,r11
	r31.s64 = r11.s64 - r22.s64;
loc_82172CBC:
	// li r5,256
	ctx.r5.s64 = 256;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x82172CCC;
	sub_823DA950(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,256
	r29.s64 = r29.s64 + 256;
	// bne 0x82172cbc
	if (!cr0.eq) goto loc_82172CBC;
loc_82172CD8:
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r11,52264
	ctx.r9.u64 = r11.u64 | 52264;
	// ori r8,r10,52268
	ctx.r8.u64 = ctx.r10.u64 | 52268;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r22,r18,r9
	PPC_STORE_U32(r18.u32 + ctx.r9.u32, r22.u32);
	// stwx r20,r18,r8
	PPC_STORE_U32(r18.u32 + ctx.r8.u32, r20.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82172D04"))) PPC_WEAK_FUNC(sub_82172D04);
PPC_FUNC_IMPL(__imp__sub_82172D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82172D08"))) PPC_WEAK_FUNC(sub_82172D08);
PPC_FUNC_IMPL(__imp__sub_82172D08) {
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
	ctx.lr = 0x82172D10;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lbz r10,10552(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10552);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82172d5c
	if (cr6.eq) goto loc_82172D5C;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82172d5c
	if (cr6.eq) goto loc_82172D5C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821716c0
	ctx.lr = 0x82172D4C;
	sub_821716C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82172d5c
	if (cr6.eq) goto loc_82172D5C;
	// li r31,1
	r31.s64 = 1;
loc_82172D5C:
	// clrlwi r22,r31,24
	r22.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82172d98
	if (cr6.eq) goto loc_82172D98;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// beq cr6,0x82172d84
	if (cr6.eq) goto loc_82172D84;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82171670
	ctx.lr = 0x82172D84;
	sub_82171670(ctx, base);
loc_82172D84:
	// lwz r3,12(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82172d98
	if (cr6.eq) goto loc_82172D98;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82171670
	ctx.lr = 0x82172D98;
	sub_82171670(ctx, base);
loc_82172D98:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// ori r9,r10,57792
	ctx.r9.u64 = ctx.r10.u64 | 57792;
	// mullw r10,r26,r9
	ctx.r10.s64 = int64_t(r26.s32) * int64_t(ctx.r9.s32);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82172dbc
	if (!cr0.eq) goto loc_82172DBC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_82172DBC:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,52224
	ctx.r9.u64 = ctx.r10.u64 | 52224;
	// lwzx r10,r11,r9
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82172ec4
	if (!cr6.gt) goto loc_82172EC4;
	// addi r30,r11,288
	r30.s64 = r11.s64 + 288;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// lis r28,1024
	r28.s64 = 67108864;
	// lis r24,4096
	r24.s64 = 268435456;
loc_82172DE0:
	// addic. r11,r30,-288
	xer.ca = r30.u32 > 287;
	r11.s64 = r30.s64 + -288;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82172eb8
	if (cr0.eq) goto loc_82172EB8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82172eb8
	if (cr6.eq) goto loc_82172EB8;
	// lwz r31,-32(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -32);
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// ori r7,r7,2
	ctx.r7.u64 = ctx.r7.u64 | 2;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lbz r11,66(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 66);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// extsb r6,r11
	ctx.r6.s64 = r11.s8;
	// bl 0x82175ad8
	ctx.lr = 0x82172E20;
	sub_82175AD8(ctx, base);
	// rlwinm r10,r3,0,5,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r10,r28
	cr6.compare<int32_t>(ctx.r10.s32, r28.s32, xer);
	// beq cr6,0x82172e3c
	if (cr6.eq) goto loc_82172E3C;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r24
	cr6.compare<int32_t>(r11.s32, r24.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82172e40
	if (!cr6.eq) goto loc_82172E40;
loc_82172E3C:
	// li r11,0
	r11.s64 = 0;
loc_82172E40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82172e5c
	if (!cr6.eq) goto loc_82172E5C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r10,r11,1
	ctx.r10.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82172eb8
	goto loc_82172EB8;
loc_82172E5C:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82172eb8
	if (cr6.eq) goto loc_82172EB8;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82172e8c
	if (!cr6.lt) goto loc_82172E8C;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r8.u32);
loc_82172E8C:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82172eb8
	if (!cr6.lt) goto loc_82172EB8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r31.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
loc_82172EB8:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r30,r30,816
	r30.s64 = r30.s64 + 816;
	// bne 0x82172de0
	if (!cr0.eq) goto loc_82172DE0;
loc_82172EC4:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82172edc
	if (cr6.eq) goto loc_82172EDC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82171750
	ctx.lr = 0x82172ED4;
	sub_82171750(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82171750
	ctx.lr = 0x82172EDC;
	sub_82171750(ctx, base);
loc_82172EDC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82172a68
	ctx.lr = 0x82172EE8;
	sub_82172A68(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82172EF4"))) PPC_WEAK_FUNC(sub_82172EF4);
PPC_FUNC_IMPL(__imp__sub_82172EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82172EF8"))) PPC_WEAK_FUNC(sub_82172EF8);
PPC_FUNC_IMPL(__imp__sub_82172EF8) {
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
	ctx.lr = 0x82172F00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r31,6(r3)
	r31.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82172f44
	if (cr6.eq) goto loc_82172F44;
	// lwz r28,0(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82172f3c
	if (!cr6.gt) goto loc_82172F3C;
	// lis r11,0
	r11.s64 = 0;
	// mr r30,r28
	r30.u64 = r28.u64;
	// ori r29,r11,57792
	r29.u64 = r11.u64 | 57792;
loc_82172F28:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821743b0
	ctx.lr = 0x82172F30;
	sub_821743B0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r30,r29
	r30.u64 = r30.u64 + r29.u64;
	// bne 0x82172f28
	if (!cr0.eq) goto loc_82172F28;
loc_82172F3C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x82172F44;
	sub_82130588(ctx, base);
loc_82172F44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82172F4C"))) PPC_WEAK_FUNC(sub_82172F4C);
PPC_FUNC_IMPL(__imp__sub_82172F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82172F50"))) PPC_WEAK_FUNC(sub_82172F50);
PPC_FUNC_IMPL(__imp__sub_82172F50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82172F74;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82172fac
	if (!cr6.gt) goto loc_82172FAC;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82172F8C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82172fa0
	if (cr6.eq) goto loc_82172FA0;
	// stfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
loc_82172FA0:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x82172f8c
	if (!cr0.eq) goto loc_82172F8C;
loc_82172FAC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82172FC0"))) PPC_WEAK_FUNC(sub_82172FC0);
PPC_FUNC_IMPL(__imp__sub_82172FC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,-30924(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30924);
	// addi r5,r7,2384
	ctx.r5.s64 = ctx.r7.s64 + 2384;
	// rlwinm r8,r6,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v60,r3,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// addi r8,r4,2352
	ctx.r8.s64 = ctx.r4.s64 + 2352;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v62,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v58,v60,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v56,v59,v62
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v53,v57,v57
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vsubfp128 v54,v55,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v57.f32)));
	// vor128 v52,v55,v55
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vaddfp128 v51,v52,v53
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// vand128 v50,v54,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v49,v51,v63
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v48,v50,v62
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpgtfp128 v47,v56,v49
	simde_mm_store_ps(v47.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v49.f32)));
	// vcmpgtfp128 v46,v48,v58
	simde_mm_store_ps(v46.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v58.f32)));
	// vor128 v45,v47,v46
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v46.u8)));
	// vand128 v44,v45,v63
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v43,v44,v61
	simde_mm_store_ps(v43.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v43.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// lwz r6,36(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r9,r7,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1;
	// lwz r5,32(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r4,r5
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, ctx.r10.u32);
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82173084
	if (!cr6.lt) goto loc_82173084;
	// li r11,0
	r11.s64 = 0;
loc_82173084:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217308C"))) PPC_WEAK_FUNC(sub_8217308C);
PPC_FUNC_IMPL(__imp__sub_8217308C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173090"))) PPC_WEAK_FUNC(sub_82173090);
PPC_FUNC_IMPL(__imp__sub_82173090) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r7,16
	ctx.r7.s64 = 16;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r11,-30924(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -30924);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r3,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// rlwinm r6,r5,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,-16
	ctx.r5.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,-16
	ctx.r4.s64 = ctx.r1.s64 + -16;
	// lvx128 v61,r10,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// vsubfp128 v58,v59,v61
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f0,r6,r5
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f13,r6,r4
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8217311c
	if (cr6.lt) goto loc_8217311C;
	// li r11,0
	r11.s64 = 0;
loc_8217311C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173134"))) PPC_WEAK_FUNC(sub_82173134);
PPC_FUNC_IMPL(__imp__sub_82173134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173138"))) PPC_WEAK_FUNC(sub_82173138);
PPC_FUNC_IMPL(__imp__sub_82173138) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r7,16
	ctx.r7.s64 = 16;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r11,-30924(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -30924);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r3,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// rlwinm r6,r5,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,-16
	ctx.r5.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,-16
	ctx.r4.s64 = ctx.r1.s64 + -16;
	// lvx128 v61,r10,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// vaddfp128 v58,v59,v61
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f0,r6,r5
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f13,r6,r4
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x821731c4
	if (cr6.lt) goto loc_821731C4;
	// li r11,0
	r11.s64 = 0;
loc_821731C4:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821731DC"))) PPC_WEAK_FUNC(sub_821731DC);
PPC_FUNC_IMPL(__imp__sub_821731DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821731E0"))) PPC_WEAK_FUNC(sub_821731E0);
PPC_FUNC_IMPL(__imp__sub_821731E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r11,r11,-28592
	r11.s64 = r11.s64 + -28592;
	// lwz r10,-28576(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28576);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82173218
	if (!cr6.eq) goto loc_82173218;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,-28576(r9)
	PPC_STORE_U32(ctx.r9.u32 + -28576, ctx.r10.u32);
	// lfs f0,14884(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
loc_82173218:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// addi r5,r1,-16
	ctx.r5.s64 = ctx.r1.s64 + -16;
	// lwz r11,-30924(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -30924);
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r4,r1,-16
	ctx.r4.s64 = ctx.r1.s64 + -16;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// vaddfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v59,v61,v62
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v58,v59,v60
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// vmulfp128 v57,v58,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f13,r3,r4
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82173284
	if (cr6.lt) goto loc_82173284;
	// li r11,0
	r11.s64 = 0;
loc_82173284:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217328C"))) PPC_WEAK_FUNC(sub_8217328C);
PPC_FUNC_IMPL(__imp__sub_8217328C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173290"))) PPC_WEAK_FUNC(sub_82173290);
PPC_FUNC_IMPL(__imp__sub_82173290) {
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
	ctx.lr = 0x82173298;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r9,-28544(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -28544);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lfs f31,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f31.f64 = double(temp.f32);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// addi r10,r10,-28560
	ctx.r10.s64 = ctx.r10.s64 + -28560;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x821732e8
	if (!cr6.eq) goto loc_821732E8;
	// ori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 | 1;
	// stfs f31,0(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f31,4(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f31,8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// stw r9,-28544(r8)
	PPC_STORE_U32(ctx.r8.u32 + -28544, ctx.r9.u32);
loc_821732E8:
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,0
	ctx.r8.s64 = 0;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// vmulfp128 v60,v61,v63
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82173410
	if (cr6.eq) goto loc_82173410;
	// addi r29,r1,100
	r29.s64 = ctx.r1.s64 + 100;
	// li r26,-1
	r26.s64 = -1;
loc_8217331C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r10,r9,30
	ctx.r10.u64 = ctx.r9.u32 & 0x3;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x82173374
	if (!cr6.eq) goto loc_82173374;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r31,r9,0,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x82173368
	if (cr6.eq) goto loc_82173368;
loc_82173344:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bl 0x82172fc0
	ctx.lr = 0x82173354;
	sub_82172FC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82173410
	if (!cr6.eq) goto loc_82173410;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bne cr6,0x82173344
	if (!cr6.eq) goto loc_82173344;
loc_82173368:
	// addi r29,r29,-4
	r29.s64 = r29.s64 + -4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x82173408
	goto loc_82173408;
loc_82173374:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lfsx f0,r10,r28
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	f0.f64 = double(temp.f32);
	// lfsx f12,r10,r27
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lfsx f11,r10,r8
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// ble cr6,0x8217339c
	if (!cr6.gt) goto loc_8217339C;
	// li r7,0
	ctx.r7.s64 = 0;
loc_8217339C:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x821733b0
	if (cr6.gt) goto loc_821733B0;
	// li r6,0
	ctx.r6.s64 = 0;
loc_821733B0:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// ble cr6,0x821733c8
	if (!cr6.gt) goto loc_821733C8;
	// li r10,0
	ctx.r10.s64 = 0;
loc_821733C8:
	// and r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 & ctx.r7.u64;
	// rlwinm r11,r9,0,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// not r8,r10
	ctx.r8.u64 = ~ctx.r10.u64;
	// addi r9,r11,12
	ctx.r9.s64 = r11.s64 + 12;
	// and r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 & ctx.r7.u64;
	// and r6,r11,r10
	ctx.r6.u64 = r11.u64 & ctx.r10.u64;
	// and r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// or r7,r5,r6
	ctx.r7.u64 = ctx.r5.u64 | ctx.r6.u64;
	// beq cr6,0x82173404
	if (cr6.eq) goto loc_82173404;
	// and r11,r8,r11
	r11.u64 = ctx.r8.u64 & r11.u64;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
loc_82173404:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_82173408:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217331c
	if (!cr6.eq) goto loc_8217331C;
loc_82173410:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8217341C"))) PPC_WEAK_FUNC(sub_8217341C);
PPC_FUNC_IMPL(__imp__sub_8217341C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173420"))) PPC_WEAK_FUNC(sub_82173420);
PPC_FUNC_IMPL(__imp__sub_82173420) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82173428;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// beq cr6,0x82173484
	if (cr6.eq) goto loc_82173484;
	// addi r31,r3,4
	r31.s64 = ctx.r3.s64 + 4;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x82173480
	if (cr6.eq) goto loc_82173480;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82173458:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// bl 0x82173090
	ctx.lr = 0x82173468;
	sub_82173090(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x82173474
	if (cr6.eq) goto loc_82173474;
	// mr r30,r31
	r30.u64 = r31.u64;
loc_82173474:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x82173458
	if (!cr6.eq) goto loc_82173458;
loc_82173480:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82173484:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82173490"))) PPC_WEAK_FUNC(sub_82173490);
PPC_FUNC_IMPL(__imp__sub_82173490) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82173498;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// beq cr6,0x821734f4
	if (cr6.eq) goto loc_821734F4;
	// addi r31,r3,4
	r31.s64 = ctx.r3.s64 + 4;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x821734f0
	if (cr6.eq) goto loc_821734F0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_821734C8:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// bl 0x82173138
	ctx.lr = 0x821734D8;
	sub_82173138(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x821734e4
	if (cr6.eq) goto loc_821734E4;
	// mr r30,r31
	r30.u64 = r31.u64;
loc_821734E4:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x821734c8
	if (!cr6.eq) goto loc_821734C8;
loc_821734F0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821734F4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82173500"))) PPC_WEAK_FUNC(sub_82173500);
PPC_FUNC_IMPL(__imp__sub_82173500) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82173508;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,1
	r30.s64 = 1;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// li r31,0
	r31.s64 = 0;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// sth r31,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r31.u16);
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// sth r31,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r31.u16);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stb r10,-30972(r8)
	PPC_STORE_U8(ctx.r8.u32 + -30972, ctx.r10.u8);
	// lis r4,-32131
	ctx.r4.s64 = -2105737216;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// stw r11,-30976(r9)
	PPC_STORE_U32(ctx.r9.u32 + -30976, r11.u32);
	// stb r11,-30968(r7)
	PPC_STORE_U8(ctx.r7.u32 + -30968, r11.u8);
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// stb r10,-30967(r5)
	PPC_STORE_U8(ctx.r5.u32 + -30967, ctx.r10.u8);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// mr r11,r30
	r11.u64 = r30.u64;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// stb r11,10544(r4)
	PPC_STORE_U8(ctx.r4.u32 + 10544, r11.u8);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
	// stb r9,-30970(r3)
	PPC_STORE_U8(ctx.r3.u32 + -30970, ctx.r9.u8);
	// stw r9,-30936(r6)
	PPC_STORE_U32(ctx.r6.u32 + -30936, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r10,10545(r8)
	PPC_STORE_U8(ctx.r8.u32 + 10545, ctx.r10.u8);
	// stb r30,46(r29)
	PPC_STORE_U8(r29.u32 + 46, r30.u8);
	// stb r31,47(r29)
	PPC_STORE_U8(r29.u32 + 47, r31.u8);
	// stb r31,48(r29)
	PPC_STORE_U8(r29.u32 + 48, r31.u8);
	// stb r31,49(r29)
	PPC_STORE_U8(r29.u32 + 49, r31.u8);
	// stb r31,50(r29)
	PPC_STORE_U8(r29.u32 + 50, r31.u8);
	// stw r11,-30932(r28)
	PPC_STORE_U32(r28.u32 + -30932, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x821735A4;
	sub_82130528(ctx, base);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// stw r3,-30928(r7)
	PPC_STORE_U32(ctx.r7.u32 + -30928, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r31.u32);
	// stw r31,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r31.u32);
	// stw r31,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r31.u32);
	// stb r31,44(r29)
	PPC_STORE_U8(r29.u32 + 44, r31.u8);
	// stb r30,45(r29)
	PPC_STORE_U8(r29.u32 + 45, r30.u8);
	// lwz r11,-30932(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -30932);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r11,r4,1
	r11.u64 = ctx.r4.u64 ^ 1;
	// stb r11,-30969(r6)
	PPC_STORE_U8(ctx.r6.u32 + -30969, r11.u8);
	// stw r31,40(r29)
	PPC_STORE_U32(r29.u32 + 40, r31.u32);
	// stw r31,36(r29)
	PPC_STORE_U32(r29.u32 + 36, r31.u32);
	// stw r31,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r31.u32);
	// stw r31,28(r29)
	PPC_STORE_U32(r29.u32 + 28, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821735FC"))) PPC_WEAK_FUNC(sub_821735FC);
PPC_FUNC_IMPL(__imp__sub_821735FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173600"))) PPC_WEAK_FUNC(sub_82173600);
PPC_FUNC_IMPL(__imp__sub_82173600) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// li r10,16
	ctx.r10.s64 = 16;
	// cmplw cr6,r4,r5
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, xer);
	// beq cr6,0x82173670
	if (cr6.eq) goto loc_82173670;
	// addi r9,r6,16
	ctx.r9.s64 = ctx.r6.s64 + 16;
	// lis r31,-32124
	r31.s64 = -2105278464;
loc_82173618:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,-30924(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + -30924);
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// cmplw cr6,r4,r5
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, xer);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v59,v61,v61
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// vor128 v57,v60,v60
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vsubfp128 v58,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vaddfp128 v56,v57,v59
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v59.f32)));
	// vminfp128 v55,v62,v58
	simde_mm_store_ps(v55.f32, simde_mm_min_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32)));
	// vmaxfp128 v54,v63,v56
	simde_mm_store_ps(v54.f32, simde_mm_max_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82173618
	if (!cr6.eq) goto loc_82173618;
loc_82173670:
	// lvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r6,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173688"))) PPC_WEAK_FUNC(sub_82173688);
PPC_FUNC_IMPL(__imp__sub_82173688) {
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
	// std r5,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r5.u64);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
loc_821736A8:
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x8217370c
	if (cr6.eq) goto loc_8217370C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821731e0
	ctx.lr = 0x821736BC;
	sub_821731E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821736d0
	if (cr6.eq) goto loc_821736D0;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// b 0x821736a8
	goto loc_821736A8;
loc_821736D0:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x8217370c
	if (cr6.eq) goto loc_8217370C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821731e0
	ctx.lr = 0x821736E8;
	sub_821731E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821736d0
	if (cr6.eq) goto loc_821736D0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x821736a8
	goto loc_821736A8;
loc_8217370C:
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

__attribute__((alias("__imp__sub_82173728"))) PPC_WEAK_FUNC(sub_82173728);
PPC_FUNC_IMPL(__imp__sub_82173728) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82173758
	if (cr6.eq) goto loc_82173758;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lbz r9,10577(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10577);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8217375c
	if (!cr6.eq) goto loc_8217375C;
loc_82173758:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8217375C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82173780
	if (!cr6.eq) goto loc_82173780;
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_82173780:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r5,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r5.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stw r4,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r4.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,10584(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 10584);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,31304(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31304);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vaddfp128 v60,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,29500(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29500);
	f0.f64 = double(temp.f32);
	// vsubfp128 v59,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r31,r1,144
	r31.s64 = ctx.r1.s64 + 144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82173290
	ctx.lr = 0x82173824;
	sub_82173290(ctx, base);
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
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

__attribute__((alias("__imp__sub_8217383C"))) PPC_WEAK_FUNC(sub_8217383C);
PPC_FUNC_IMPL(__imp__sub_8217383C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173840"))) PPC_WEAK_FUNC(sub_82173840);
PPC_FUNC_IMPL(__imp__sub_82173840) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-30928(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -30928);
	// bl 0x82130588
	ctx.lr = 0x82173864;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// stw r11,-30928(r30)
	PPC_STORE_U32(r30.u32 + -30928, r11.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821763b0
	ctx.lr = 0x82173878;
	sub_821763B0(ctx, base);
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82176418
	ctx.lr = 0x82173884;
	sub_82176418(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-30976(r10)
	PPC_STORE_U32(ctx.r10.u32 + -30976, r11.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821738a8
	if (cr6.eq) goto loc_821738A8;
	// bl 0x82130588
	ctx.lr = 0x821738A0;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_821738A8:
	// lwz r30,24(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821738d0
	if (cr6.eq) goto loc_821738D0;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821738c8
	if (cr6.eq) goto loc_821738C8;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821738C8;
	sub_82130588(ctx, base);
loc_821738C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821738D0;
	sub_82130588(ctx, base);
loc_821738D0:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x821738D8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82172ef8
	ctx.lr = 0x821738E0;
	sub_82172EF8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821738E8;
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

__attribute__((alias("__imp__sub_82173900"))) PPC_WEAK_FUNC(sub_82173900);
PPC_FUNC_IMPL(__imp__sub_82173900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91c0
	ctx.lr = 0x82173908;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d8
	ctx.lr = 0x82173910;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-6656(r1)
	ea = -6656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r9
	r18.u64 = ctx.r9.u64;
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lfs f29,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f29.f64 = double(temp.f32);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lfs f30,-31068(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31068);
	f30.f64 = double(temp.f32);
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// lfs f28,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f28.f64 = double(temp.f32);
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// li r26,0
	r26.s64 = 0;
	// li r24,16
	r24.s64 = 16;
	// lis r20,-32124
	r20.s64 = -2105278464;
loc_8217395C:
	// subf r11,r23,r28
	r11.s64 = r28.s64 - r23.s64;
	// li r10,1
	ctx.r10.s64 = 1;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// cmpw cr6,r11,r18
	cr6.compare<int32_t>(r11.s32, r18.s32, xer);
	// blt cr6,0x82173974
	if (cr6.lt) goto loc_82173974;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82173974:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821739d0
	if (cr6.eq) goto loc_821739D0;
	// addi r10,r23,3
	ctx.r10.s64 = r23.s64 + 3;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82173ca0
	if (cr6.eq) goto loc_82173CA0;
	// addi r26,r26,-1
	r26.s64 = r26.s64 + -1;
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r26,6448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6448, r26.u32);
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v63,r11,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r23,36(r11)
	r23.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,40(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// stvx128 v62,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,32(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8217395c
	goto loc_8217395C;
loc_821739D0:
	// lvx128 v61,r0,r22
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r25
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82173a08
	if (!cr6.gt) goto loc_82173A08;
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82173a18
	if (!cr6.gt) goto loc_82173A18;
	// li r29,0
	r29.s64 = 0;
	// b 0x82173a1c
	goto loc_82173A1C;
loc_82173A08:
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// li r29,1
	r29.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82173a1c
	if (cr6.gt) goto loc_82173A1C;
loc_82173A18:
	// li r29,2
	r29.s64 = 2;
loc_82173A1C:
	// rlwinm r31,r29,2,0,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lfsx f0,r31,r22
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + r22.u32);
	f0.f64 = double(temp.f32);
	// lfsx f13,r31,r25
	temp.u32 = PPC_LOAD_U32(r31.u32 + r25.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fmuls f31,f12,f28
	f31.f64 = double(float(ctx.f12.f64 * f28.f64));
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x82173688
	ctx.lr = 0x82173A4C;
	sub_82173688(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplw cr6,r30,r23
	cr6.compare<uint32_t>(r30.u32, r23.u32, xer);
	// beq cr6,0x82173a60
	if (cr6.eq) goto loc_82173A60;
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// bne cr6,0x82173b40
	if (!cr6.eq) goto loc_82173B40;
loc_82173A60:
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f30,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f30,144(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stfs f30,152(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// stfs f29,160(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// stfs f29,168(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// stfs f29,164(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82173600
	ctx.lr = 0x82173AAC;
	sub_82173600(ctx, base);
	// addi r7,r1,288
	ctx.r7.s64 = ctx.r1.s64 + 288;
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r25
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v54,v55,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// lfs f13,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82173af8
	if (!cr6.gt) goto loc_82173AF8;
	// lfs f13,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82173b08
	if (!cr6.gt) goto loc_82173B08;
	// li r29,0
	r29.s64 = 0;
	// b 0x82173b0c
	goto loc_82173B0C;
loc_82173AF8:
	// lfs f0,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f0.f64 = double(temp.f32);
	// li r29,1
	r29.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82173b0c
	if (cr6.gt) goto loc_82173B0C;
loc_82173B08:
	// li r29,2
	r29.s64 = 2;
loc_82173B0C:
	// rlwinm r31,r29,2,0,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lfsx f0,r31,r22
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + r22.u32);
	f0.f64 = double(temp.f32);
	// lfsx f13,r31,r25
	temp.u32 = PPC_LOAD_U32(r31.u32 + r25.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fmuls f31,f12,f28
	f31.f64 = double(float(ctx.f12.f64 * f28.f64));
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82173688
	ctx.lr = 0x82173B3C;
	sub_82173688(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82173B40:
	// cmplw cr6,r30,r23
	cr6.compare<uint32_t>(r30.u32, r23.u32, xer);
	// bne cr6,0x82173b50
	if (!cr6.eq) goto loc_82173B50;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// b 0x82173b5c
	goto loc_82173B5C;
loc_82173B50:
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// bne cr6,0x82173b5c
	if (!cr6.eq) goto loc_82173B5C;
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
loc_82173B5C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82173490
	ctx.lr = 0x82173B6C;
	sub_82173490(ctx, base);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82173420
	ctx.lr = 0x82173B80;
	sub_82173420(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,-30924(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + -30924);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r26,1
	ctx.r9.s64 = r26.s64 + 1;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,6448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6448, ctx.r9.u32);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r16,r1,176
	r16.s64 = ctx.r1.s64 + 176;
	// lvx128 v53,r11,r24
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r15,r1,192
	r15.s64 = ctx.r1.s64 + 192;
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// vsubfp128 v51,v52,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// addi r14,r1,192
	r14.s64 = ctx.r1.s64 + 192;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// addi r26,r1,192
	r26.s64 = ctx.r1.s64 + 192;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f0,r31,r7
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 4, temp.u32);
	// lwz r9,-30924(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + -30924);
	// lwz r10,0(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lvx128 v50,r10,r24
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v48,v49,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v48,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f13,r31,r4
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// lwz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,0(r21)
	PPC_STORE_U32(r21.u32 + 0, ctx.r8.u32);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r19
	ctx.r10.u64 = ctx.r10.u64 + r19.u64;
	// rlwinm r8,r10,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r9,r10,12
	ctx.r9.s64 = ctx.r10.s64 + 12;
	// add r5,r8,r29
	ctx.r5.u64 = ctx.r8.u64 + r29.u64;
	// stw r5,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r5.u32);
	// lvx128 v47,r0,r25
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// stfsx f31,r31,r16
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + r16.u32, temp.u32);
	// lvx128 v46,r0,r3
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r22
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r0,r14
	simde_mm_store_si128((simde__m128i*)(base + ((r14.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfsx f31,r31,r26
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + r26.u32, temp.u32);
	// lvx128 v44,r0,r15
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,40(r11)
	PPC_STORE_U32(r11.u32 + 40, r28.u32);
	// stw r9,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r9.u32);
	// stvx128 v46,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,36(r11)
	PPC_STORE_U32(r11.u32 + 36, r30.u32);
	// mr r28,r30
	r28.u64 = r30.u64;
	// lwz r26,6448(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 6448);
	// b 0x8217395c
	goto loc_8217395C;
loc_82173CA0:
	// addi r1,r1,6656
	ctx.r1.s64 = ctx.r1.s64 + 6656;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba24
	ctx.lr = 0x82173CAC;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82173CB0"))) PPC_WEAK_FUNC(sub_82173CB0);
PPC_FUNC_IMPL(__imp__sub_82173CB0) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82173CB8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f0.f64 = double(temp.f32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lfs f0,-31068(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31068);
	f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82173600
	ctx.lr = 0x82173D28;
	sub_82173600(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82173900
	ctx.lr = 0x82173D58;
	sub_82173900(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82173D60"))) PPC_WEAK_FUNC(sub_82173D60);
PPC_FUNC_IMPL(__imp__sub_82173D60) {
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
	ctx.lr = 0x82173D68;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,1
	r30.s64 = 1;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82173da0
	if (!cr6.eq) goto loc_82173DA0;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82172f50
	ctx.lr = 0x82173D9C;
	sub_82172F50(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_82173DA0:
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r6,r27,1
	ctx.r6.s64 = r27.s64 + 1;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82173cb0
	ctx.lr = 0x82173DC0;
	sub_82173CB0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82173e0c
	if (!cr6.eq) goto loc_82173E0C;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// beq cr6,0x82173df8
	if (cr6.eq) goto loc_82173DF8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82172f50
	ctx.lr = 0x82173DE8;
	sub_82172F50(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82173DF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82173E0C:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82173E1C"))) PPC_WEAK_FUNC(sub_82173E1C);
PPC_FUNC_IMPL(__imp__sub_82173E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173E20"))) PPC_WEAK_FUNC(sub_82173E20);
PPC_FUNC_IMPL(__imp__sub_82173E20) {
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
	ctx.lr = 0x82173E28;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,16383
	r11.s64 = 1073676288;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82173e4c
	if (!cr6.gt) goto loc_82173E4C;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82173E4C:
	// bl 0x82130528
	ctx.lr = 0x82173E50;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r28,0
	r28.s64 = 0;
	// beq cr6,0x82173e8c
	if (cr6.eq) goto loc_82173E8C;
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x82173e84
	if (cr0.lt) goto loc_82173E84;
	// addic. r10,r11,1
	xer.ca = r11.u32 > 4294967294;
	ctx.r10.s64 = r11.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// beq 0x82173e84
	if (cr0.eq) goto loc_82173E84;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82173E78:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82173e78
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82173E78;
loc_82173E84:
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82173e90
	goto loc_82173E90;
loc_82173E8C:
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_82173E90:
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lfs f0,-31068(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31068);
	f0.f64 = double(temp.f32);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r11,-30924(r6)
	PPC_STORE_U32(ctx.r6.u32 + -30924, r11.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lvlx128 v62,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lfs f0,-31400(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31400);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82173ff0
	if (!cr6.gt) goto loc_82173FF0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
loc_82173EFC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// vor128 v63,v61,v61
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// vor128 v62,v60,v60
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// lbz r10,66(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 66);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82173f38
	if (!cr6.gt) goto loc_82173F38;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
loc_82173F20:
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// vminfp128 v63,v59,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_min_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// vmaxfp128 v62,v59,v62
	simde_mm_store_ps(v62.f32, simde_mm_max_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// bne 0x82173f20
	if (!cr0.eq) goto loc_82173F20;
loc_82173F38:
	// vsubfp128 v58,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vaddfp128 v57,v62,v63
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r30,r1,112
	r30.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r7,r7,80
	ctx.r7.s64 = ctx.r7.s64 + 80;
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f7,f11,f0
	ctx.f7.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f8,100(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v56,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// stvx128 v57,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f4.f64 = double(temp.f32);
	// lfs f6,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f1,f6,f0
	ctx.f1.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f2,112(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f12,f5,f0
	ctx.f12.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fsqrts f11,f4
	ctx.f11.f64 = double(float(sqrt(ctx.f4.f64)));
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r30
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stwx r8,r6,r11
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, ctx.r8.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// blt cr6,0x82173efc
	if (cr6.lt) goto loc_82173EFC;
loc_82173FF0:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x82173FF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82174014
	if (cr6.eq) goto loc_82174014;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
	// stw r28,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r28.u32);
	// b 0x82174018
	goto loc_82174018;
loc_82174014:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_82174018:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add. r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x8217403c
	if (cr0.eq) goto loc_8217403C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82172f50
	ctx.lr = 0x82174038;
	sub_82172F50(ctx, base);
	// b 0x82174040
	goto loc_82174040;
loc_8217403C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82174040:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r29,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r29.u32);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r4
	ctx.r5.u64 = r11.u64 + ctx.r4.u64;
	// bl 0x82173d60
	ctx.lr = 0x82174064;
	sub_82173D60(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8217406C"))) PPC_WEAK_FUNC(sub_8217406C);
PPC_FUNC_IMPL(__imp__sub_8217406C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174070"))) PPC_WEAK_FUNC(sub_82174070);
PPC_FUNC_IMPL(__imp__sub_82174070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lis r11,0
	r11.s64 = 0;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,57696
	r11.u64 = r11.u64 | 57696;
	// ori r10,r10,57712
	ctx.r10.u64 = ctx.r10.u64 | 57712;
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174094"))) PPC_WEAK_FUNC(sub_82174094);
PPC_FUNC_IMPL(__imp__sub_82174094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174098"))) PPC_WEAK_FUNC(sub_82174098);
PPC_FUNC_IMPL(__imp__sub_82174098) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// addis r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 65536;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r8,-12272
	ctx.r8.s64 = ctx.r8.s64 + -12272;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r4,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r4,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821740D0"))) PPC_WEAK_FUNC(sub_821740D0);
PPC_FUNC_IMPL(__imp__sub_821740D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,0
	r11.s64 = 0;
	// vspltw v0,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xFF));
	// lis r10,0
	ctx.r10.s64 = 0;
	// vspltw v13,v1,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xAA));
	// lis r9,0
	ctx.r9.s64 = 0;
	// vspltw128 v63,v1,3
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x0));
	// lis r8,0
	ctx.r8.s64 = 0;
	// vspltw v12,v1,2
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x55));
	// ori r7,r11,53504
	ctx.r7.u64 = r11.u64 | 53504;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// ori r6,r10,53456
	ctx.r6.u64 = ctx.r10.u64 | 53456;
	// ori r5,r9,53568
	ctx.r5.u64 = ctx.r9.u64 | 53568;
	// ori r4,r8,53520
	ctx.r4.u64 = ctx.r8.u64 | 53520;
	// lis r11,0
	r11.s64 = 0;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v11,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,0
	ctx.r10.s64 = 0;
	// lvx128 v10,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r9,r11,53472
	ctx.r9.u64 = r11.u64 | 53472;
	// lvx128 v9,r3,r5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r3,r4
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r8,r10,53536
	ctx.r8.u64 = ctx.r10.u64 | 53536;
	// vmaddfp v6,v0,v7,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lvx128 v5,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r5,r7,53488
	ctx.r5.u64 = ctx.r7.u64 | 53488;
	// ori r4,r6,53552
	ctx.r4.u64 = ctx.r6.u64 | 53552;
	// lvx128 v4,r3,r8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r1,-80
	ctx.r10.s64 = ctx.r1.s64 + -80;
	// addi r9,r1,-80
	ctx.r9.s64 = ctx.r1.s64 + -80;
	// lvx128 v3,r3,r5
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,-48
	ctx.r8.s64 = ctx.r1.s64 + -48;
	// lvx128 v2,r3,r4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,-64
	ctx.r7.s64 = ctx.r1.s64 + -64;
	// vmaddfp v1,v13,v5,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// addi r6,r1,-32
	ctx.r6.s64 = ctx.r1.s64 + -32;
	// vmaddfp v31,v13,v4,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v29,v12,v2,v31
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v31.f32)));
	// lwz r11,-28540(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28540);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// vcmpgtfp128 v60,v30,v63
	simde_mm_store_ps(v60.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v59,v61,v30
	simde_mm_store_ps(v59.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v30.f32)));
	// vcmpgtfp128 v58,v29,v63
	simde_mm_store_ps(v58.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v57,v61,v29
	simde_mm_store_ps(v57.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v29.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r4,24(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// rlwimi r31,r30,0,18,18
	r31.u64 = (__builtin_rotateleft32(r30.u32, 0) & 0x2000) | (r31.u64 & 0xFFFFFFFFFFFFDFFF);
	// lwz r30,20(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwimi r31,r5,0,19,19
	r31.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0x1000) | (r31.u64 & 0xFFFFFFFFFFFFEFFF);
	// rlwinm r3,r3,0,8,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x800000;
	// lwz r8,40(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwimi r31,r4,0,24,24
	r31.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x80) | (r31.u64 & 0xFFFFFFFFFFFFFF7F);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// rlwinm r5,r31,0,17,24
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x7F80;
	// rlwinm r4,r7,0,11,11
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x100000;
	// rlwinm r5,r5,0,24,19
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFFF0FF;
	// rlwinm r7,r6,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x20;
	// or r3,r5,r3
	ctx.r3.u64 = ctx.r5.u64 | ctx.r3.u64;
	// rlwinm r9,r9,0,9,9
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x400000;
	// or r6,r3,r10
	ctx.r6.u64 = ctx.r3.u64 | ctx.r10.u64;
	// rlwinm r8,r8,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// rlwinm r5,r30,0,16,16
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8000;
	// or r3,r6,r9
	ctx.r3.u64 = ctx.r6.u64 | ctx.r9.u64;
	// or r10,r3,r8
	ctx.r10.u64 = ctx.r3.u64 | ctx.r8.u64;
	// rlwinm r11,r11,0,10,10
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200000;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// or r8,r9,r7
	ctx.r8.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 | ctx.r5.u64;
	// or r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 | r11.u64;
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217423C"))) PPC_WEAK_FUNC(sub_8217423C);
PPC_FUNC_IMPL(__imp__sub_8217423C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174240"))) PPC_WEAK_FUNC(sub_82174240);
PPC_FUNC_IMPL(__imp__sub_82174240) {
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
	PPCRegister f0{};
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
	// bl 0x823d91ec
	ctx.lr = 0x82174248;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r11,r11,-13280
	r11.s64 = r11.s64 + -13280;
	// addi r3,r3,-11824
	ctx.r3.s64 = ctx.r3.s64 + -11824;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// stw r30,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r30.u32);
	// bl 0x8217d5e8
	ctx.lr = 0x82174278;
	sub_8217D5E8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,-10832
	ctx.r3.s64 = ctx.r3.s64 + -10832;
	// bl 0x8217d5e8
	ctx.lr = 0x82174284;
	sub_8217D5E8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,-9840
	ctx.r3.s64 = ctx.r3.s64 + -9840;
	// bl 0x8217d5e8
	ctx.lr = 0x82174290;
	sub_8217D5E8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,-8848
	ctx.r3.s64 = ctx.r3.s64 + -8848;
	// bl 0x8217d5e8
	ctx.lr = 0x8217429C;
	sub_8217D5E8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
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
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r6,-12272
	ctx.r6.s64 = ctx.r6.s64 + -12272;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r11,0
	r11.s64 = 0;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r26,32
	r26.s64 = 32;
	// li r25,48
	r25.s64 = 48;
	// ori r11,r11,57684
	r11.u64 = r11.u64 | 57684;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r29,0
	r29.s64 = 0;
	// stvx128 v60,r6,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,0
	r28.s64 = 0;
	// stvx128 v59,r6,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r10,r10,52224
	ctx.r10.u64 = ctx.r10.u64 | 52224;
	// lis r9,0
	ctx.r9.s64 = 0;
	// stvx128 v63,r6,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,0
	ctx.r4.s64 = 0;
	// stbx r30,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r30.u8);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r27,0
	r27.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// stwx r30,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r30.u32);
	// ori r6,r29,57686
	ctx.r6.u64 = r29.u64 | 57686;
	// ori r9,r9,57685
	ctx.r9.u64 = ctx.r9.u64 | 57685;
	// ori r29,r28,52276
	r29.u64 = r28.u64 | 52276;
	// lis r11,32767
	r11.s64 = 2147418112;
	// ori r4,r4,57696
	ctx.r4.u64 = ctx.r4.u64 | 57696;
	// lvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r3,r3,57712
	ctx.r3.u64 = ctx.r3.u64 | 57712;
	// ori r28,r27,52272
	r28.u64 = r27.u64 | 52272;
	// stbx r30,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r30.u8);
	// ori r5,r5,57680
	ctx.r5.u64 = ctx.r5.u64 | 57680;
	// stwx r30,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, r30.u32);
	// ori r7,r11,65535
	ctx.r7.u64 = r11.u64 | 65535;
	// lvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,1
	ctx.r10.s64 = 1;
	// stvx128 v58,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// stvx128 v57,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stbx r10,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, ctx.r10.u8);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// addi r11,r11,-13256
	r11.s64 = r11.s64 + -13256;
	// stwx r30,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, r30.u32);
	// stwx r7,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r7.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82174398:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82174398
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82174398;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821743B0"))) PPC_WEAK_FUNC(sub_821743B0);
PPC_FUNC_IMPL(__imp__sub_821743B0) {
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
	ctx.lr = 0x821743B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// addis r29,r30,1
	r29.s64 = r30.s64 + 65536;
	// addi r29,r29,-13264
	r29.s64 = r29.s64 + -13264;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821743e0
	if (cr6.eq) goto loc_821743E0;
	// bl 0x82130588
	ctx.lr = 0x821743DC;
	sub_82130588(ctx, base);
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
loc_821743E0:
	// addis r29,r30,1
	r29.s64 = r30.s64 + 65536;
	// addi r29,r29,-13260
	r29.s64 = r29.s64 + -13260;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82174430
	if (cr6.eq) goto loc_82174430;
	// lwz r10,-16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// blt 0x82174428
	if (cr0.lt) goto loc_82174428;
loc_8217440C:
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r31,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r31.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// bge 0x8217440c
	if (!cr0.lt) goto loc_8217440C;
loc_82174428:
	// bl 0x82130588
	ctx.lr = 0x8217442C;
	sub_82130588(ctx, base);
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
loc_82174430:
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r11,57680
	ctx.r8.u64 = r11.u64 | 57680;
	// ori r7,r10,52224
	ctx.r7.u64 = ctx.r10.u64 | 52224;
	// ori r6,r9,57686
	ctx.r6.u64 = ctx.r9.u64 | 57686;
	// lis r5,32767
	ctx.r5.s64 = 2147418112;
	// addis r11,r30,1
	r11.s64 = r30.s64 + 65536;
	// ori r4,r5,65535
	ctx.r4.u64 = ctx.r5.u64 | 65535;
	// addi r11,r11,-13256
	r11.s64 = r11.s64 + -13256;
	// stwx r31,r30,r7
	PPC_STORE_U32(r30.u32 + ctx.r7.u32, r31.u32);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// stwx r4,r30,r8
	PPC_STORE_U32(r30.u32 + ctx.r8.u32, ctx.r4.u32);
	// stbx r31,r30,r6
	PPC_STORE_U8(r30.u32 + ctx.r6.u32, r31.u8);
	// li r10,7
	ctx.r10.s64 = 7;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82174470:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82174470
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82174470;
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r3,r3,-8848
	ctx.r3.s64 = ctx.r3.s64 + -8848;
	// bl 0x8217cb48
	ctx.lr = 0x82174488;
	sub_8217CB48(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r3,r3,-9840
	ctx.r3.s64 = ctx.r3.s64 + -9840;
	// bl 0x8217cb48
	ctx.lr = 0x82174494;
	sub_8217CB48(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r3,r3,-10832
	ctx.r3.s64 = ctx.r3.s64 + -10832;
	// bl 0x8217cb48
	ctx.lr = 0x821744A0;
	sub_8217CB48(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r3,r3,-11824
	ctx.r3.s64 = ctx.r3.s64 + -11824;
	// bl 0x8217cb48
	ctx.lr = 0x821744AC;
	sub_8217CB48(ctx, base);
	// addis r11,r30,1
	r11.s64 = r30.s64 + 65536;
	// addi r11,r11,-13280
	r11.s64 = r11.s64 + -13280;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r31,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r31.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821744CC"))) PPC_WEAK_FUNC(sub_821744CC);
PPC_FUNC_IMPL(__imp__sub_821744CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821744D0"))) PPC_WEAK_FUNC(sub_821744D0);
PPC_FUNC_IMPL(__imp__sub_821744D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v63{};
	// lwz r10,384(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r10,16
	cr6.compare<int32_t>(ctx.r10.s32, 16, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// addi r9,r10,8
	ctx.r9.s64 = ctx.r10.s64 + 8;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// subfic r10,r10,16
	xer.ca = ctx.r10.u32 <= 16;
	ctx.r10.s64 = 16 - ctx.r10.s64;
loc_821744FC:
	// lwz r8,384(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r8,r8,7
	ctx.r8.s64 = ctx.r8.s64 + 7;
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v63,r7,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,384(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// addi r6,r8,15
	ctx.r6.s64 = ctx.r8.s64 + 15;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lwzx r4,r5,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// stw r4,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r4.u32);
	// lwz r8,384(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r8,r3
	ctx.r7.u64 = ctx.r8.u64 + ctx.r3.u64;
	// lwz r6,-4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x821744fc
	if (!cr0.eq) goto loc_821744FC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217454C"))) PPC_WEAK_FUNC(sub_8217454C);
PPC_FUNC_IMPL(__imp__sub_8217454C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174550"))) PPC_WEAK_FUNC(sub_82174550);
PPC_FUNC_IMPL(__imp__sub_82174550) {
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
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82174558;
	// vspltw128 v63,v1,3
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x0));
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// li r21,0
	r21.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// vspltw v0,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xFF));
	// vspltw v13,v1,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xAA));
	// vspltw v12,v1,2
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x55));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// ble cr6,0x82174668
	if (!cr6.gt) goto loc_82174668;
	// li r22,128
	r22.s64 = 128;
	// li r23,176
	r23.s64 = 176;
	// li r24,192
	r24.s64 = 192;
	// li r25,240
	r25.s64 = 240;
	// li r26,64
	r26.s64 = 64;
	// li r27,112
	r27.s64 = 112;
	// li r28,48
	r28.s64 = 48;
	// li r29,144
	r29.s64 = 144;
	// li r30,208
	r30.s64 = 208;
	// li r31,80
	r31.s64 = 80;
	// li r3,16
	ctx.r3.s64 = 16;
	// li r6,160
	ctx.r6.s64 = 160;
	// li r7,224
	ctx.r7.s64 = 224;
	// li r8,96
	ctx.r8.s64 = 96;
	// li r9,32
	ctx.r9.s64 = 32;
loc_821745BC:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// lvx128 v11,r11,r22
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r11,r23
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r11,r24
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r11,r25
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r11,r26
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v5,v0,v7,v9
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v4,r11,r27
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v2,v0,v4,v6
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvx128 v1,r11,r28
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v31,v0,v1,v3
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// lvx128 v30,r11,r29
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r11,r30
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v28,r11,r31
	simde_mm_store_si128((simde__m128i*)v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v27,r11,r3
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v26,r11,r6
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v25,r11,r7
	simde_mm_store_si128((simde__m128i*)v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v24,v13,v8,v30
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(v30.f32)));
	// lvx128 v23,r11,r8
	simde_mm_store_si128((simde__m128i*)v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v22,r11,r9
	simde_mm_store_si128((simde__m128i*)v22.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v21,v13,v5,v29
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v20,v13,v2,v28
	simde_mm_store_ps(v20.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v19,v13,v31,v27
	simde_mm_store_ps(v19.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v18,v12,v24,v26
	simde_mm_store_ps(v18.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v24.f32)), simde_mm_load_ps(v26.f32)));
	// vmaddfp v17,v12,v21,v25
	simde_mm_store_ps(v17.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v21.f32)), simde_mm_load_ps(v25.f32)));
	// vmaddfp v16,v12,v20,v23
	simde_mm_store_ps(v16.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v20.f32)), simde_mm_load_ps(v23.f32)));
	// vmaddfp v15,v12,v19,v22
	simde_mm_store_ps(v15.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v19.f32)), simde_mm_load_ps(v22.f32)));
	// vmaxfp128 v61,v17,v18
	simde_mm_store_ps(v61.f32, simde_mm_max_ps(simde_mm_load_ps(v17.f32), simde_mm_load_ps(v18.f32)));
	// vmaxfp128 v60,v15,v16
	simde_mm_store_ps(v60.f32, simde_mm_max_ps(simde_mm_load_ps(v15.f32), simde_mm_load_ps(v16.f32)));
	// vmaxfp128 v59,v60,v61
	simde_mm_store_ps(v59.f32, simde_mm_max_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vcmpgtfp128. v58,v59,v63
	simde_mm_store_ps(v58.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v58.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82174670
	if (!cr6.eq) goto loc_82174670;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r21,r4
	cr6.compare<int32_t>(r21.s32, ctx.r4.s32, xer);
	// blt cr6,0x821745bc
	if (cr6.lt) goto loc_821745BC;
loc_82174668:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d922c
	return;
loc_82174670:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82174678"))) PPC_WEAK_FUNC(sub_82174678);
PPC_FUNC_IMPL(__imp__sub_82174678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v24{};
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
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r8,64
	ctx.r8.s64 = 64;
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
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vsldoi128 v0,v63,v62,4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8), 12));
	// vor128 v12,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vsldoi128 v10,v62,v63,12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8), 4));
	// vor128 v9,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// li r7,80
	ctx.r7.s64 = 80;
	// vspltw128 v60,v61,3
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x0));
	// vrlimi128 v13,v62,2,0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 228), 2));
	// vor128 v8,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// li r6,96
	ctx.r6.s64 = 96;
	// vrlimi128 v12,v62,4,0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 228), 4));
	// li r5,112
	ctx.r5.s64 = 112;
	// vrlimi128 v11,v62,6,0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 228), 6));
	// vsubfp128 v59,v63,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// vrlimi128 v9,v62,10,0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 228), 10));
	// vpkd3d128 v8,v62,0,3,0
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v62.f32[0] < 3.0f ? 3.0f : (v62.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v62.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v62.f32[1] < 3.0f ? 3.0f : (v62.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v62.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v62.f32[2] < 3.0f ? 3.0f : (v62.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v62.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v62.f32[3] < 3.0f ? 3.0f : (v62.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v62.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	ctx.v8.u32[0] = temp.u32;
	// vor128 v7,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vor128 v6,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vsel v5,v2,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// vsel v4,v1,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vsel v24,v4,v5,v13
	simde_mm_store_si128((simde__m128i*)v24.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v22,v4,v5,v12
	simde_mm_store_si128((simde__m128i*)v22.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vsel v21,v4,v5,v11
	simde_mm_store_si128((simde__m128i*)v21.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vsel v20,v4,v5,v10
	simde_mm_store_si128((simde__m128i*)v20.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vsel v19,v4,v5,v9
	simde_mm_store_si128((simde__m128i*)v19.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// stvx128 v24,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v18,v4,v5,v8
	simde_mm_store_si128((simde__m128i*)v18.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// stvx128 v22,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v20,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v19,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v18,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v5,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174724"))) PPC_WEAK_FUNC(sub_82174724);
PPC_FUNC_IMPL(__imp__sub_82174724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174728"))) PPC_WEAK_FUNC(sub_82174728);
PPC_FUNC_IMPL(__imp__sub_82174728) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82174730;
	// addi r11,r1,-48
	r11.s64 = ctx.r1.s64 + -48;
	// lwz r5,384(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 384);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v63,v63
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_setzero_si128());
	// ble cr6,0x821747d8
	if (!cr6.gt) goto loc_821747D8;
	// addi r11,r4,160
	r11.s64 = ctx.r4.s64 + 160;
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r7,-16
	ctx.r7.s64 = -16;
	// li r8,-32
	ctx.r8.s64 = -32;
loc_82174760:
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lvx128 v61,r11,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// rlwinm r4,r4,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r29,-8(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// rlwinm r31,r31,4,0,27
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r30,r30,4,0,27
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r29,r29,4,0,27
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r4,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r31,r3
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v56,v61,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32), 0xFF));
	// lvx128 v55,r30,r3
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v54,v62,v57
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32), 0xFF));
	// lvx128 v53,r29,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v52,v60,v55
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v55.f32), 0xFF));
	// vmsum4fp128 v51,v59,v53
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// vmaxfp128 v50,v54,v56
	simde_mm_store_ps(v50.f32, simde_mm_max_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v56.f32)));
	// vmaxfp128 v49,v51,v52
	simde_mm_store_ps(v49.f32, simde_mm_max_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32)));
	// vmaxfp128 v48,v49,v50
	simde_mm_store_ps(v48.f32, simde_mm_max_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vcmpgtfp128. v47,v48,v63
	simde_mm_store_ps(v47.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v47.f32), 0xF);
	// blt cr6,0x821747e0
	if (cr6.lt) goto loc_821747E0;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// blt cr6,0x82174760
	if (cr6.lt) goto loc_82174760;
loc_821747D8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d924c
	return;
loc_821747E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821747E8"))) PPC_WEAK_FUNC(sub_821747E8);
PPC_FUNC_IMPL(__imp__sub_821747E8) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x821747F0;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821748ec
	if (cr6.eq) goto loc_821748EC;
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// li r10,160
	ctx.r10.s64 = 160;
	// lwz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// li r8,144
	ctx.r8.s64 = 144;
	// rlwinm r7,r11,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// li r31,128
	r31.s64 = 128;
	// lvx128 v61,r6,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r6,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r7,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r9,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v57,v61,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// vmsum4fp128 v56,v60,v58
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v58.f32), 0xFF));
	// lvx128 v55,r11,r5
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r6,r31
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v53,v54,v55
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32), 0xFF));
	// vcmpgtfp128 v52,v57,v63
	simde_mm_store_ps(v52.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v51,v56,v63
	simde_mm_store_ps(v51.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v50,v53,v63
	simde_mm_store_ps(v50.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v49,v51,v52
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vor128 v48,v50,v49
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// vcmpequw128. v47,v48,v62
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v47.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821748e4
	if (!cr6.eq) goto loc_821748E4;
	// lwz r11,20(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// li r10,208
	ctx.r10.s64 = 208;
	// lwz r9,16(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// li r8,192
	ctx.r8.s64 = 192;
	// rlwinm r7,r11,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// li r31,176
	r31.s64 = 176;
	// lvx128 v46,r6,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r6,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r7,r5
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r9,r5
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v42,v46,v44
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v41,v45,v43
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// lvx128 v40,r11,r5
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r6,r31
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v38,v39,v40
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32), 0xFF));
	// vcmpgtfp128 v37,v42,v63
	simde_mm_store_ps(v37.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v36,v41,v63
	simde_mm_store_ps(v36.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v35,v38,v63
	simde_mm_store_ps(v35.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v34,v36,v37
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v37.u8)));
	// vor128 v33,v35,v34
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v34.u8)));
	// vcmpequw128. v32,v33,v62
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v32.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821748ec
	if (cr6.eq) goto loc_821748EC;
loc_821748E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d923c
	return;
loc_821748EC:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x821749c8
	if (!cr6.gt) goto loc_821749C8;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r30,16
	r30.s64 = 16;
	// li r31,-16
	r31.s64 = -16;
	// li r7,-32
	ctx.r7.s64 = -32;
loc_82174908:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// mulli r11,r11,400
	r11.s64 = r11.s64 * 400;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// lwz r8,384(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 384);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x821748e4
	if (!cr6.gt) goto loc_821748E4;
	// addi r10,r11,160
	ctx.r10.s64 = r11.s64 + 160;
	// addi r11,r11,72
	r11.s64 = r11.s64 + 72;
loc_8217492C:
	// lwz r28,4(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,0(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lvx128 v61,r10,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r26,-4(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// rlwinm r28,r28,4,0,27
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r25,-8(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// rlwinm r27,r27,4,0,27
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r26,r26,4,0,27
	r26.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v60,r10,r31
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r25,r25,4,0,27
	r25.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v59,r10,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r28,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r27,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v56,v61,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32), 0xFF));
	// lvx128 v55,r26,r5
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v54,v62,v57
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32), 0xFF));
	// lvx128 v53,r25,r5
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v52,v60,v55
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v55.f32), 0xFF));
	// vmsum4fp128 v51,v59,v53
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// vmaxfp128 v50,v54,v56
	simde_mm_store_ps(v50.f32, simde_mm_max_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v56.f32)));
	// vmaxfp128 v49,v51,v52
	simde_mm_store_ps(v49.f32, simde_mm_max_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32)));
	// vmaxfp128 v48,v49,v50
	simde_mm_store_ps(v48.f32, simde_mm_max_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vcmpgtfp128. v47,v48,v63
	simde_mm_store_ps(v47.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v47.f32), 0xF);
	// mfocrf r28,2
	r28.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r28,r28,0,24,24
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821749b8
	if (!cr6.eq) goto loc_821749B8;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x8217492c
	if (cr6.lt) goto loc_8217492C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d923c
	return;
loc_821749B8:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// cmpw cr6,r29,r4
	cr6.compare<int32_t>(r29.s32, ctx.r4.s32, xer);
	// blt cr6,0x82174908
	if (cr6.lt) goto loc_82174908;
loc_821749C8:
	// li r3,255
	ctx.r3.s64 = 255;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821749D0"))) PPC_WEAK_FUNC(sub_821749D0);
PPC_FUNC_IMPL(__imp__sub_821749D0) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x821749D8;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r10,160
	ctx.r10.s64 = 160;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r8,144
	ctx.r8.s64 = 144;
	// rlwinm r7,r11,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// rlwinm r9,r6,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// li r6,128
	ctx.r6.s64 = 128;
	// lvx128 v61,r4,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r7,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v57,v61,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// vmsum4fp128 v56,v60,v58
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v58.f32), 0xFF));
	// lvx128 v55,r9,r3
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r4,r6
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v53,v54,v55
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32), 0xFF));
	// vcmpgtfp128 v52,v57,v63
	simde_mm_store_ps(v52.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v51,v56,v63
	simde_mm_store_ps(v51.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v50,v53,v63
	simde_mm_store_ps(v50.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v49,v51,v52
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vor128 v48,v50,v49
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// vcmpequw128. v47,v48,v62
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v47.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82174ac0
	if (!cr6.eq) goto loc_82174AC0;
	// lwz r11,20(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r10,208
	ctx.r10.s64 = 208;
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// li r8,192
	ctx.r8.s64 = 192;
	// rlwinm r7,r11,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r6,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// li r6,176
	ctx.r6.s64 = 176;
	// lvx128 v46,r4,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r4,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r7,r3
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r11,r3
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v42,v46,v44
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v41,v45,v43
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// lvx128 v40,r9,r3
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r4,r6
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v38,v39,v40
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32), 0xFF));
	// vcmpgtfp128 v37,v42,v63
	simde_mm_store_ps(v37.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v36,v41,v63
	simde_mm_store_ps(v36.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgtfp128 v35,v38,v63
	simde_mm_store_ps(v35.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v34,v36,v37
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v37.u8)));
	// vor128 v33,v35,v34
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v34.u8)));
	// vcmpequw128. v32,v33,v62
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v32.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82174ac8
	if (cr6.eq) goto loc_82174AC8;
loc_82174AC0:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d9240
	return;
loc_82174AC8:
	// li r30,1
	r30.s64 = 1;
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// ble cr6,0x82174b98
	if (!cr6.gt) goto loc_82174B98;
	// addi r7,r4,560
	ctx.r7.s64 = ctx.r4.s64 + 560;
	// li r31,16
	r31.s64 = 16;
	// li r4,-16
	ctx.r4.s64 = -16;
	// li r6,-32
	ctx.r6.s64 = -32;
loc_82174AE4:
	// lwz r8,224(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 224);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82174ac0
	if (!cr6.gt) goto loc_82174AC0;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// addi r11,r7,-88
	r11.s64 = ctx.r7.s64 + -88;
loc_82174AFC:
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lvx128 v61,r10,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,-4(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// rlwinm r29,r29,4,0,27
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r26,-8(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// rlwinm r28,r28,4,0,27
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r27,r27,4,0,27
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v60,r10,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r26,r26,4,0,27
	r26.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v59,r10,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r29,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r28,r3
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v56,v61,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32), 0xFF));
	// lvx128 v55,r27,r3
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v54,v62,v57
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32), 0xFF));
	// lvx128 v53,r26,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v52,v60,v55
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v55.f32), 0xFF));
	// vmsum4fp128 v51,v59,v53
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// vmaxfp128 v50,v54,v56
	simde_mm_store_ps(v50.f32, simde_mm_max_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v56.f32)));
	// vmaxfp128 v49,v51,v52
	simde_mm_store_ps(v49.f32, simde_mm_max_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32)));
	// vmaxfp128 v48,v49,v50
	simde_mm_store_ps(v48.f32, simde_mm_max_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vcmpgtfp128. v47,v48,v63
	simde_mm_store_ps(v47.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v47.f32), 0xF);
	// mfocrf r29,2
	r29.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r29,r29,0,24,24
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82174b88
	if (!cr6.eq) goto loc_82174B88;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x82174afc
	if (cr6.lt) goto loc_82174AFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d9240
	return;
loc_82174B88:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r7,r7,400
	ctx.r7.s64 = ctx.r7.s64 + 400;
	// cmpw cr6,r30,r5
	cr6.compare<int32_t>(r30.s32, ctx.r5.s32, xer);
	// blt cr6,0x82174ae4
	if (cr6.lt) goto loc_82174AE4;
loc_82174B98:
	// li r3,255
	ctx.r3.s64 = 255;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82174BA0"))) PPC_WEAK_FUNC(sub_82174BA0);
PPC_FUNC_IMPL(__imp__sub_82174BA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x82174BA8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r31,1
	r31.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// ble cr6,0x82174bfc
	if (!cr6.gt) goto loc_82174BFC;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// addi r30,r4,400
	r30.s64 = ctx.r4.s64 + 400;
loc_82174BCC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82174728
	ctx.lr = 0x82174BD8;
	sub_82174728(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82174bec
	if (cr6.eq) goto loc_82174BEC;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
loc_82174BEC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,400
	r30.s64 = r30.s64 + 400;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// blt cr6,0x82174bcc
	if (cr6.lt) goto loc_82174BCC;
loc_82174BFC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82174C08"))) PPC_WEAK_FUNC(sub_82174C08);
PPC_FUNC_IMPL(__imp__sub_82174C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vspltw128 v127,v1,3
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x0));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r11,r9
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c570
	ctx.lr = 0x82174C60;
	sub_8217C570(ctx, base);
	// vmulfp128 v63,v127,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v125.f32)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vmaddfp128 v63,v127,v126,v63
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v61,v62,v63
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c570
	ctx.lr = 0x82174C90;
	sub_8217C570(ctx, base);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// lfs f0,-30464(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -30464);
	f0.f64 = double(temp.f32);
	// fmuls f7,f11,f11
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f6,f8,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fmuls f1,f6,f0
	ctx.f1.f64 = double(float(ctx.f6.f64 * f0.f64));
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174CE8"))) PPC_WEAK_FUNC(sub_82174CE8);
PPC_FUNC_IMPL(__imp__sub_82174CE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v63{};
	// mulli r11,r4,816
	r11.s64 = ctx.r4.s64 * 816;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,276(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_82174D0C:
	// lwz r7,288(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 288);
	// rlwinm r6,r7,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82174d3c
	if (cr6.eq) goto loc_82174D3C;
	// lwz r7,268(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82174d3c
	if (!cr6.eq) goto loc_82174D3C;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82174D3C:
	// lwz r7,276(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x82174d0c
	if (cr6.lt) goto loc_82174D0C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174D54"))) PPC_WEAK_FUNC(sub_82174D54);
PPC_FUNC_IMPL(__imp__sub_82174D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174D58"))) PPC_WEAK_FUNC(sub_82174D58);
PPC_FUNC_IMPL(__imp__sub_82174D58) {
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
	// bl 0x823d91dc
	ctx.lr = 0x82174D60;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r8,9
	r11.u64 = ctx.r8.u32 & 0x7FFFFF;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// rlwinm r11,r11,0,30,9
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFC00003;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// rlwinm r25,r8,31,31,31
	r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x1;
	// rlwinm r24,r8,9,31,31
	r24.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 9) & 0x1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82174d9c
	if (!cr6.eq) goto loc_82174D9C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_82174D9C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// ori r8,r10,57792
	ctx.r8.u64 = ctx.r10.u64 | 57792;
	// li r21,0
	r21.s64 = 0;
	// mullw r10,r4,r8
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// add r27,r10,r11
	r27.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8217509c
	if (cr6.eq) goto loc_8217509C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addis r29,r27,1
	r29.s64 = r27.s64 + 65536;
	// lfs f11,8(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// addis r28,r27,1
	r28.s64 = r27.s64 + 65536;
	// lfs f10,0(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// addi r29,r29,-12080
	r29.s64 = r29.s64 + -12080;
	// lfs f9,4(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lfs f8,8(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r28,r28,-12016
	r28.s64 = r28.s64 + -12016;
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r26,0
	r26.s64 = 0;
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r31,0
	r31.s64 = 0;
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r30,0
	r30.s64 = 0;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f9,132(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f8,136(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x821ce9d8
	ctx.lr = 0x82174E2C;
	sub_821CE9D8(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174e40
	if (!cr6.gt) goto loc_82174E40;
	// lis r31,32
	r31.s64 = 2097152;
	// b 0x82174e50
	goto loc_82174E50;
loc_82174E40:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174e50
	if (!cr6.lt) goto loc_82174E50;
	// lis r31,16
	r31.s64 = 1048576;
loc_82174E50:
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174e64
	if (!cr6.gt) goto loc_82174E64;
	// ori r31,r31,8192
	r31.u64 = r31.u64 | 8192;
	// b 0x82174e74
	goto loc_82174E74;
loc_82174E64:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174e74
	if (!cr6.lt) goto loc_82174E74;
	// ori r31,r31,4096
	r31.u64 = r31.u64 | 4096;
loc_82174E74:
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174e88
	if (!cr6.gt) goto loc_82174E88;
	// ori r31,r31,32
	r31.u64 = r31.u64 | 32;
	// b 0x82174e98
	goto loc_82174E98;
loc_82174E88:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174e98
	if (!cr6.lt) goto loc_82174E98;
	// ori r31,r31,16
	r31.u64 = r31.u64 | 16;
loc_82174E98:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821ce9d8
	ctx.lr = 0x82174EA8;
	sub_821CE9D8(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174ebc
	if (!cr6.gt) goto loc_82174EBC;
	// oris r31,r31,128
	r31.u64 = r31.u64 | 8388608;
	// b 0x82174ecc
	goto loc_82174ECC;
loc_82174EBC:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174ecc
	if (!cr6.lt) goto loc_82174ECC;
	// oris r31,r31,64
	r31.u64 = r31.u64 | 4194304;
loc_82174ECC:
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174ee0
	if (!cr6.gt) goto loc_82174EE0;
	// ori r31,r31,32768
	r31.u64 = r31.u64 | 32768;
	// b 0x82174ef0
	goto loc_82174EF0;
loc_82174EE0:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174ef0
	if (!cr6.lt) goto loc_82174EF0;
	// ori r31,r31,16384
	r31.u64 = r31.u64 | 16384;
loc_82174EF0:
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174f04
	if (!cr6.gt) goto loc_82174F04;
	// ori r31,r31,128
	r31.u64 = r31.u64 | 128;
	// b 0x82174f14
	goto loc_82174F14;
loc_82174F04:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174f14
	if (!cr6.lt) goto loc_82174F14;
	// ori r31,r31,64
	r31.u64 = r31.u64 | 64;
loc_82174F14:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821ce9d8
	ctx.lr = 0x82174F24;
	sub_821CE9D8(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174f38
	if (!cr6.gt) goto loc_82174F38;
	// lis r30,32
	r30.s64 = 2097152;
	// b 0x82174f48
	goto loc_82174F48;
loc_82174F38:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174f48
	if (!cr6.lt) goto loc_82174F48;
	// lis r30,16
	r30.s64 = 1048576;
loc_82174F48:
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174f5c
	if (!cr6.gt) goto loc_82174F5C;
	// ori r30,r30,8192
	r30.u64 = r30.u64 | 8192;
	// b 0x82174f6c
	goto loc_82174F6C;
loc_82174F5C:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174f6c
	if (!cr6.lt) goto loc_82174F6C;
	// ori r30,r30,4096
	r30.u64 = r30.u64 | 4096;
loc_82174F6C:
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174f80
	if (!cr6.gt) goto loc_82174F80;
	// ori r30,r30,32
	r30.u64 = r30.u64 | 32;
	// b 0x82174f90
	goto loc_82174F90;
loc_82174F80:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174f90
	if (!cr6.lt) goto loc_82174F90;
	// ori r30,r30,16
	r30.u64 = r30.u64 | 16;
loc_82174F90:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821ce9d8
	ctx.lr = 0x82174FA0;
	sub_821CE9D8(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174fb4
	if (!cr6.gt) goto loc_82174FB4;
	// oris r30,r30,128
	r30.u64 = r30.u64 | 8388608;
	// b 0x82174fc4
	goto loc_82174FC4;
loc_82174FB4:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174fc4
	if (!cr6.lt) goto loc_82174FC4;
	// oris r30,r30,64
	r30.u64 = r30.u64 | 4194304;
loc_82174FC4:
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174fd8
	if (!cr6.gt) goto loc_82174FD8;
	// ori r30,r30,32768
	r30.u64 = r30.u64 | 32768;
	// b 0x82174fe8
	goto loc_82174FE8;
loc_82174FD8:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82174fe8
	if (!cr6.lt) goto loc_82174FE8;
	// ori r30,r30,16384
	r30.u64 = r30.u64 | 16384;
loc_82174FE8:
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82174ffc
	if (!cr6.gt) goto loc_82174FFC;
	// ori r30,r30,128
	r30.u64 = r30.u64 | 128;
	// b 0x8217500c
	goto loc_8217500C;
loc_82174FFC:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8217500c
	if (!cr6.lt) goto loc_8217500C;
	// ori r30,r30,64
	r30.u64 = r30.u64 | 64;
loc_8217500C:
	// lis r12,80
	r12.s64 = 5242880;
	// lis r11,80
	r11.s64 = 5242880;
	// ori r12,r12,20560
	r12.u64 = r12.u64 | 20560;
	// and r10,r30,r31
	ctx.r10.u64 = r30.u64 & r31.u64;
	// and r9,r31,r12
	ctx.r9.u64 = r31.u64 & r12.u64;
	// lis r12,240
	r12.s64 = 15728640;
	// ori r11,r11,20560
	r11.u64 = r11.u64 | 20560;
	// ori r12,r12,61680
	r12.u64 = r12.u64 | 61680;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// and r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 & r12.u64;
	// bne cr6,0x82175050
	if (!cr6.eq) goto loc_82175050;
	// lis r12,80
	r12.s64 = 5242880;
	// ori r12,r12,20560
	r12.u64 = r12.u64 | 20560;
	// and r9,r30,r12
	ctx.r9.u64 = r30.u64 & r12.u64;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x82175050
	if (!cr6.eq) goto loc_82175050;
	// li r26,1
	r26.s64 = 1;
loc_82175050:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217509c
	if (!cr6.eq) goto loc_8217509C;
	// lis r12,160
	r12.s64 = 10485760;
	// ori r12,r12,41120
	r12.u64 = r12.u64 | 41120;
	// and r11,r10,r12
	r11.u64 = ctx.r10.u64 & r12.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217509c
	if (cr6.eq) goto loc_8217509C;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82175098
	if (cr6.eq) goto loc_82175098;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175098
	if (!cr6.eq) goto loc_82175098;
	// lis r3,1024
	ctx.r3.s64 = 67108864;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_82175098:
	// lis r21,1024
	r21.s64 = 67108864;
loc_8217509C:
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,52224
	ctx.r10.u64 = r11.u64 | 52224;
	// lwzx r5,r27,r10
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x821750c0
	if (!cr6.eq) goto loc_821750C0;
	// oris r3,r21,2048
	ctx.r3.u64 = r21.u64 | 134217728;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_821750C0:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82175184
	if (!cr6.gt) goto loc_82175184;
	// addi r8,r27,288
	ctx.r8.s64 = r27.s64 + 288;
loc_821750D0:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,-12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82175174
	if (cr6.eq) goto loc_82175174;
	// lwz r11,-20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175174
	if (!cr6.eq) goto loc_82175174;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82175168
	if (!cr6.gt) goto loc_82175168;
	// lvx128 v62,r0,r23
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// addi r11,r8,-288
	r11.s64 = ctx.r8.s64 + -288;
loc_8217510C:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// vmsum3fp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bgt cr6,0x82175164
	if (cr6.gt) goto loc_82175164;
	// lvx128 v60,r0,r22
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// vmsum3fp128 v59,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bgt cr6,0x82175164
	if (cr6.gt) goto loc_82175164;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8217510c
	if (cr6.lt) goto loc_8217510C;
	// b 0x82175168
	goto loc_82175168;
loc_82175164:
	// li r7,1
	ctx.r7.s64 = 1;
loc_82175168:
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82175194
	if (cr6.eq) goto loc_82175194;
loc_82175174:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,816
	ctx.r8.s64 = ctx.r8.s64 + 816;
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// blt cr6,0x821750d0
	if (cr6.lt) goto loc_821750D0;
loc_82175184:
	// oris r3,r21,8192
	ctx.r3.u64 = r21.u64 | 536870912;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_82175194:
	// oris r3,r21,4096
	ctx.r3.u64 = r21.u64 | 268435456;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_821751A4"))) PPC_WEAK_FUNC(sub_821751A4);
PPC_FUNC_IMPL(__imp__sub_821751A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821751A8"))) PPC_WEAK_FUNC(sub_821751A8);
PPC_FUNC_IMPL(__imp__sub_821751A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r9,r10,57792
	ctx.r9.u64 = ctx.r10.u64 | 57792;
	// mullw r10,r4,r9
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x821751c8
	if (!cr0.eq) goto loc_821751C8;
loc_821751C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821751C8:
	// lis r10,0
	ctx.r10.s64 = 0;
	// addis r4,r11,1
	ctx.r4.s64 = r11.s64 + 65536;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r10,52272
	ctx.r8.u64 = ctx.r10.u64 | 52272;
	// addi r4,r4,-13280
	ctx.r4.s64 = ctx.r4.s64 + -13280;
	// ori r3,r9,52276
	ctx.r3.u64 = ctx.r9.u64 | 52276;
	// stw r4,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r4.u32);
	// lwzx r10,r11,r8
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821751c0
	if (cr6.eq) goto loc_821751C0;
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821751c0
	if (cr6.eq) goto loc_821751C0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821751c0
	if (cr6.eq) goto loc_821751C0;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x821751c0
	if (cr6.lt) goto loc_821751C0;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82175238"))) PPC_WEAK_FUNC(sub_82175238);
PPC_FUNC_IMPL(__imp__sub_82175238) {
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
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91ec
	ctx.lr = 0x82175240;
	// clrlwi r11,r6,9
	r11.u64 = ctx.r6.u32 & 0x7FFFFF;
	// rlwinm r11,r11,0,30,9
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFC00003;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82175258
	if (!cr6.eq) goto loc_82175258;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d923c
	return;
loc_82175258:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r6,31
	ctx.r9.u64 = ctx.r6.u32 & 0x1;
	// ori r8,r10,57792
	ctx.r8.u64 = ctx.r10.u64 | 57792;
	// li r3,0
	ctx.r3.s64 = 0;
	// mullw r10,r4,r8
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82175428
	if (cr6.eq) goto loc_82175428;
	// addis r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 65536;
	// addis r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 65536;
	// addi r7,r7,-12080
	ctx.r7.s64 = ctx.r7.s64 + -12080;
	// addi r4,r4,-12016
	ctx.r4.s64 = ctx.r4.s64 + -12016;
	// dcbt r0,r7
	// dcbt r0,r4
	// li r8,48
	ctx.r8.s64 = 48;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v11,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// li r11,32
	r11.s64 = 32;
	// vspltw128 v62,v63,3
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// lvx128 v9,r4,r8
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v10,r7,r8
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v7,v0,v11,v9
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v8,v0,v12,v10
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// lvx128 v5,r4,r9
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r7,r9
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// lvx128 v3,r4,r11
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v61,v62
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v4,r7,r11
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// addi r9,r1,-128
	ctx.r9.s64 = ctx.r1.s64 + -128;
	// addi r8,r1,-128
	ctx.r8.s64 = ctx.r1.s64 + -128;
	// addi r7,r1,-112
	ctx.r7.s64 = ctx.r1.s64 + -112;
	// addi r4,r1,-96
	ctx.r4.s64 = ctx.r1.s64 + -96;
	// addi r31,r1,-80
	r31.s64 = ctx.r1.s64 + -80;
	// lis r30,80
	r30.s64 = 5242880;
	// vmaddfp v1,v13,v5,v7
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v2,v13,v6,v8
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v30,v0,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// lwz r11,-28536(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -28536);
	// vmaddfp v31,v0,v4,v2
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// vcmpgtfp128 v58,v30,v62
	simde_mm_store_ps(v58.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v62.f32)));
	// vcmpgtfp128 v59,v31,v62
	simde_mm_store_ps(v59.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v62.f32)));
	// vcmpgtfp128 v57,v60,v31
	simde_mm_store_ps(v57.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v31.f32)));
	// vcmpgtfp128 v56,v60,v30
	simde_mm_store_ps(v56.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v30.f32)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r31,40(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r29,32(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r28,8(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r27,20(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r26,0(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r8,r8,0,8,8
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x800000;
	// lwz r7,56(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// rlwinm r7,r7,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x40;
	// lwz r4,48(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// rlwinm r4,r4,0,9,9
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x400000;
	// lwz r25,52(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwimi r25,r11,0,18,18
	r25.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x2000) | (r25.u64 & 0xFFFFFFFFFFFFDFFF);
	// rlwimi r25,r3,0,19,19
	r25.u64 = (__builtin_rotateleft32(ctx.r3.u32, 0) & 0x1000) | (r25.u64 & 0xFFFFFFFFFFFFEFFF);
	// rlwinm r3,r31,0,27,27
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x10;
	// rlwimi r25,r9,0,24,24
	r25.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x80) | (r25.u64 & 0xFFFFFFFFFFFFFF7F);
	// rlwinm r9,r29,0,11,11
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x100000;
	// rlwinm r11,r25,0,17,24
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x7F80;
	// rlwinm r11,r11,0,24,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF0FF;
	// or r8,r11,r8
	ctx.r8.u64 = r11.u64 | ctx.r8.u64;
	// rlwinm r11,r28,0,26,26
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x20;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r7,r27,0,16,16
	ctx.r7.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x8000;
	// or r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 | ctx.r4.u64;
	// rlwinm r8,r26,0,10,10
	ctx.r8.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x200000;
	// or r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 | ctx.r3.u64;
	// or r3,r4,r9
	ctx.r3.u64 = ctx.r4.u64 | ctx.r9.u64;
	// ori r9,r30,20560
	ctx.r9.u64 = r30.u64 | 20560;
	// or r11,r3,r11
	r11.u64 = ctx.r3.u64 | r11.u64;
	// or r7,r11,r7
	ctx.r7.u64 = r11.u64 | ctx.r7.u64;
	// lis r12,240
	r12.s64 = 15728640;
	// or r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 | ctx.r8.u64;
	// ori r12,r12,61680
	r12.u64 = r12.u64 | 61680;
	// and r11,r4,r12
	r11.u64 = ctx.r4.u64 & r12.u64;
	// lis r12,80
	r12.s64 = 5242880;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// ori r12,r12,20560
	r12.u64 = r12.u64 | 20560;
	// and r8,r4,r12
	ctx.r8.u64 = ctx.r4.u64 & r12.u64;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x821753f0
	if (!cr6.eq) goto loc_821753F0;
	// oris r3,r3,2048
	ctx.r3.u64 = ctx.r3.u64 | 134217728;
	// b 0x82175428
	goto loc_82175428;
loc_821753F0:
	// lis r12,160
	r12.s64 = 10485760;
	// ori r12,r12,41120
	r12.u64 = r12.u64 | 41120;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82175428
	if (cr6.eq) goto loc_82175428;
	// rlwinm r11,r6,31,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82175424
	if (cr6.eq) goto loc_82175424;
	// rlwinm r11,r6,9,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 9) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175424
	if (!cr6.eq) goto loc_82175424;
	// oris r3,r3,1024
	ctx.r3.u64 = ctx.r3.u64 | 67108864;
	// b 0x823d923c
	return;
loc_82175424:
	// oris r3,r3,1024
	ctx.r3.u64 = ctx.r3.u64 | 67108864;
loc_82175428:
	// lis r11,0
	r11.s64 = 0;
	// ori r9,r11,52224
	ctx.r9.u64 = r11.u64 | 52224;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x821754fc
	if (cr6.eq) goto loc_821754FC;
	// lvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// vspltw128 v54,v55,3
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x0));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// vxor128 v53,v54,v54
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_setzero_si128());
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,-132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -132, temp.u32);
	// vsubfp128 v62,v53,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// ble cr6,0x821754f8
	if (!cr6.gt) goto loc_821754F8;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// addi r8,r10,288
	ctx.r8.s64 = ctx.r10.s64 + 288;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82175478:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,-12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821754e8
	if (cr6.eq) goto loc_821754E8;
	// lwz r11,-20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821754e8
	if (!cr6.eq) goto loc_821754E8;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821754dc
	if (!cr6.gt) goto loc_821754DC;
	// addi r10,r8,-288
	ctx.r10.s64 = ctx.r8.s64 + -288;
loc_821754A8:
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v51,v52,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// vcmpgtfp128. v50,v51,v62
	simde_mm_store_ps(v50.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v62.f32)));
	cr6.setFromMask(simde_mm_load_ps(v50.f32), 0xF);
	// mfocrf r5,2
	ctx.r5.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r5,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x821754d8
	if (!cr6.eq) goto loc_821754D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x821754a8
	if (cr6.lt) goto loc_821754A8;
	// b 0x821754dc
	goto loc_821754DC;
loc_821754D8:
	// li r7,1
	ctx.r7.s64 = 1;
loc_821754DC:
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82175500
	if (cr6.eq) goto loc_82175500;
loc_821754E8:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,816
	ctx.r8.s64 = ctx.r8.s64 + 816;
	// cmpw cr6,r6,r4
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, xer);
	// blt cr6,0x82175478
	if (cr6.lt) goto loc_82175478;
loc_821754F8:
	// oris r3,r3,8192
	ctx.r3.u64 = ctx.r3.u64 | 536870912;
loc_821754FC:
	// b 0x823d923c
	return;
loc_82175500:
	// oris r3,r3,4096
	ctx.r3.u64 = ctx.r3.u64 | 268435456;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82175508"))) PPC_WEAK_FUNC(sub_82175508);
PPC_FUNC_IMPL(__imp__sub_82175508) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82175510;
	// stfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f29.u64);
	// stfd f30,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f30.u64);
	// stfd f31,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r8,9
	r11.u64 = ctx.r8.u32 & 0x7FFFFF;
	// clrlwi r31,r8,31
	r31.u64 = ctx.r8.u32 & 0x1;
	// rlwinm r11,r11,0,30,9
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFC00003;
	// rlwinm r20,r8,31,31,31
	r20.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x1;
	// rlwinm r19,r8,9,31,31
	r19.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 9) & 0x1;
	// rlwinm r21,r8,8,31,31
	r21.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175558
	if (!cr6.eq) goto loc_82175558;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f29,-136(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82175558:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r23,0
	r23.s64 = 0;
	// ori r9,r10,57792
	ctx.r9.u64 = ctx.r10.u64 | 57792;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mullw r10,r4,r9
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f10,164(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f9,168(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// add r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addis r24,r25,1
	r24.s64 = r25.s64 + 65536;
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addis r22,r25,1
	r22.s64 = r25.s64 + 65536;
	// stfs f10,180(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f11,192(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r24,r24,-12080
	r24.s64 = r24.s64 + -12080;
	// stfs f9,200(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r22,r22,-12016
	r22.s64 = r22.s64 + -12016;
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f12,216(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f11,208(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f10,148(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f9,152(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// beq cr6,0x82175710
	if (cr6.eq) goto loc_82175710;
	// li r9,32
	ctx.r9.s64 = 32;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,48
	ctx.r8.s64 = 48;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r10,2
	ctx.r10.s64 = 2;
	// lvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lvx128 v61,r7,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lvx128 v58,r7,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v59,v63,v62
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v56,v58,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// addi r7,r9,2352
	ctx.r7.s64 = ctx.r9.s64 + 2352;
	// addi r6,r8,2384
	ctx.r6.s64 = ctx.r8.s64 + 2384;
	// vmrglw128 v57,v63,v62
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrglw128 v55,v58,v61
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v61,v59,v56
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v59,v59,v56
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v60,v57,v55
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
loc_82175658:
	// addi r9,r11,-16
	ctx.r9.s64 = r11.s64 + -16;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// addi r7,r11,32
	ctx.r7.s64 = r11.s64 + 32;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v53,v54,v63
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v52,v62,v53
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vmsum4fp128 v51,v52,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// vmsum4fp128 v50,v52,v60
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v60.f32), 0xFF));
	// vmsum4fp128 v49,v52,v59
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// vmrghw128 v48,v51,v52
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v47,v49,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v46,v47,v48
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// stvx128 v46,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v44,v45,v63
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v43,v62,v44
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v44.u8)));
	// vmsum4fp128 v42,v43,v61
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// vmsum4fp128 v41,v43,v60
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v60.f32), 0xFF));
	// vmsum4fp128 v40,v43,v59
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// vmrghw128 v39,v42,v43
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v38,v40,v41
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v37,v38,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// stvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lvx128 v36,r0,r8
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v35,v36,v63
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v34,v62,v35
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v35.u8)));
	// vmsum4fp128 v33,v34,v61
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// vmsum4fp128 v32,v34,v60
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v60.f32), 0xFF));
	// vmsum4fp128 v58,v34,v59
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// vmrghw128 v57,v33,v34
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v56,v58,v32
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v55,v56,v57
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v53,v54,v63
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v52,v62,v53
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vmsum4fp128 v51,v52,v61
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// vmsum4fp128 v50,v52,v60
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v60.f32), 0xFF));
	// vmsum4fp128 v49,v52,v59
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// vmrghw128 v48,v51,v52
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v47,v49,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v46,v47,v48
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// stvx128 v46,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x82175658
	if (!cr0.eq) goto loc_82175658;
loc_82175710:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// lis r27,240
	r27.s64 = 15728640;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ori r27,r27,61680
	r27.u64 = r27.u64 | 61680;
	// lfs f31,25488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 25488);
	f31.f64 = double(temp.f32);
	// beq cr6,0x821758dc
	if (cr6.eq) goto loc_821758DC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,80
	ctx.r9.s64 = 5242880;
	// li r26,0
	r26.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// addi r30,r1,100
	r30.s64 = ctx.r1.s64 + 100;
	// lfs f29,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
	// ori r29,r9,20560
	r29.u64 = ctx.r9.u64 | 20560;
loc_82175750:
	// lfs f0,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	f0.f64 = double(temp.f32);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f12,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r31,0
	r31.s64 = 0;
	// stfs f29,92(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x821ce9d8
	ctx.lr = 0x82175780;
	sub_821CE9D8(ctx, base);
	// lfs f0,224(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175794
	if (!cr6.gt) goto loc_82175794;
	// lis r31,32
	r31.s64 = 2097152;
	// b 0x821757a0
	goto loc_821757A0;
loc_82175794:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x821757a0
	if (!cr6.lt) goto loc_821757A0;
	// lis r31,16
	r31.s64 = 1048576;
loc_821757A0:
	// lfs f0,228(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x821757b4
	if (!cr6.gt) goto loc_821757B4;
	// ori r31,r31,8192
	r31.u64 = r31.u64 | 8192;
	// b 0x821757c0
	goto loc_821757C0;
loc_821757B4:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x821757c0
	if (!cr6.lt) goto loc_821757C0;
	// ori r31,r31,4096
	r31.u64 = r31.u64 | 4096;
loc_821757C0:
	// lfs f0,232(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x821757d4
	if (!cr6.gt) goto loc_821757D4;
	// ori r31,r31,32
	r31.u64 = r31.u64 | 32;
	// b 0x821757e0
	goto loc_821757E0;
loc_821757D4:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x821757e0
	if (!cr6.lt) goto loc_821757E0;
	// ori r31,r31,16
	r31.u64 = r31.u64 | 16;
loc_821757E0:
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821ce9d8
	ctx.lr = 0x821757F0;
	sub_821CE9D8(ctx, base);
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175804
	if (!cr6.gt) goto loc_82175804;
	// oris r31,r31,128
	r31.u64 = r31.u64 | 8388608;
	// b 0x82175810
	goto loc_82175810;
loc_82175804:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175810
	if (!cr6.lt) goto loc_82175810;
	// oris r31,r31,64
	r31.u64 = r31.u64 | 4194304;
loc_82175810:
	// lfs f0,244(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175824
	if (!cr6.gt) goto loc_82175824;
	// ori r31,r31,32768
	r31.u64 = r31.u64 | 32768;
	// b 0x82175830
	goto loc_82175830;
loc_82175824:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175830
	if (!cr6.lt) goto loc_82175830;
	// ori r31,r31,16384
	r31.u64 = r31.u64 | 16384;
loc_82175830:
	// lfs f0,248(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175844
	if (!cr6.gt) goto loc_82175844;
	// ori r31,r31,128
	r31.u64 = r31.u64 | 128;
	// b 0x82175850
	goto loc_82175850;
loc_82175844:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175850
	if (!cr6.lt) goto loc_82175850;
	// ori r31,r31,64
	r31.u64 = r31.u64 | 64;
loc_82175850:
	// lis r12,80
	r12.s64 = 5242880;
	// and r27,r31,r27
	r27.u64 = r31.u64 & r27.u64;
	// ori r12,r12,20560
	r12.u64 = r12.u64 | 20560;
	// and r11,r31,r12
	r11.u64 = r31.u64 & r12.u64;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bne cr6,0x82175878
	if (!cr6.eq) goto loc_82175878;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// li r26,1
	r26.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175888
	if (!cr6.eq) goto loc_82175888;
loc_82175878:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// blt cr6,0x82175750
	if (cr6.lt) goto loc_82175750;
loc_82175888:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821758dc
	if (!cr6.eq) goto loc_821758DC;
	// lis r12,160
	r12.s64 = 10485760;
	// ori r12,r12,41120
	r12.u64 = r12.u64 | 41120;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821758dc
	if (cr6.eq) goto loc_821758DC;
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821758d8
	if (cr6.eq) goto loc_821758D8;
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821758d8
	if (!cr6.eq) goto loc_821758D8;
	// oris r3,r27,1024
	ctx.r3.u64 = r27.u64 | 67108864;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_821758D8:
	// lis r23,1024
	r23.s64 = 67108864;
loc_821758DC:
	// lis r11,0
	r11.s64 = 0;
	// or r4,r27,r23
	ctx.r4.u64 = r27.u64 | r23.u64;
	// ori r10,r11,52224
	ctx.r10.u64 = r11.u64 | 52224;
	// lwzx r5,r25,r10
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + ctx.r10.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x8217590c
	if (!cr6.eq) goto loc_8217590C;
	// lis r3,2048
	ctx.r3.s64 = 134217728;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_8217590C:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82175aa8
	if (!cr6.gt) goto loc_82175AA8;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,128
	r31.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r25,268
	ctx.r7.s64 = r25.s64 + 268;
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8217595C:
	// lwz r11,20(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82175a98
	if (cr6.eq) goto loc_82175A98;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175a98
	if (!cr6.eq) goto loc_82175A98;
	// lwz r8,8(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82175a8c
	if (!cr6.gt) goto loc_82175A8C;
	// addi r10,r7,-268
	ctx.r10.s64 = ctx.r7.s64 + -268;
loc_8217598C:
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// vmsum3fp128 v45,v63,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// lfs f0,12(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f0.f64 = double(temp.f32);
	// stvx128 v45,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,288(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175a88
	if (cr6.gt) goto loc_82175A88;
	// vmsum3fp128 v44,v63,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// stvx128 v44,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,368(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175a88
	if (cr6.gt) goto loc_82175A88;
	// vmsum3fp128 v43,v63,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// stvx128 v43,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,256(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175a88
	if (cr6.gt) goto loc_82175A88;
	// vmsum3fp128 v42,v63,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// stvx128 v42,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,352(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175a88
	if (cr6.gt) goto loc_82175A88;
	// vmsum3fp128 v41,v63,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stvx128 v41,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,320(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175a88
	if (cr6.gt) goto loc_82175A88;
	// vmsum3fp128 v40,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// stvx128 v40,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,272(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175a88
	if (cr6.gt) goto loc_82175A88;
	// vmsum3fp128 v39,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// stvx128 v39,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,304(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175a88
	if (cr6.gt) goto loc_82175A88;
	// vmsum3fp128 v38,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// stvx128 v38,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,336(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175a88
	if (cr6.gt) goto loc_82175A88;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8217598c
	if (cr6.lt) goto loc_8217598C;
	// b 0x82175a8c
	goto loc_82175A8C;
loc_82175A88:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82175A8C:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82175ac0
	if (cr6.eq) goto loc_82175AC0;
loc_82175A98:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,816
	ctx.r7.s64 = ctx.r7.s64 + 816;
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// blt cr6,0x8217595c
	if (cr6.lt) goto loc_8217595C;
loc_82175AA8:
	// oris r3,r4,8192
	ctx.r3.u64 = ctx.r4.u64 | 536870912;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82175AC0:
	// oris r3,r4,4096
	ctx.r3.u64 = ctx.r4.u64 | 268435456;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82175AD8"))) PPC_WEAK_FUNC(sub_82175AD8);
PPC_FUNC_IMPL(__imp__sub_82175AD8) {
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
	// bl 0x823d91c8
	ctx.lr = 0x82175AE0;
	// stfd f29,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f29.u64);
	// stfd f30,-152(r1)
	PPC_STORE_U64(ctx.r1.u32 + -152, f30.u64);
	// stfd f31,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r7,9
	r11.u64 = ctx.r7.u32 & 0x7FFFFF;
	// mr r17,r5
	r17.u64 = ctx.r5.u64;
	// rlwinm r11,r11,0,30,9
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFC00003;
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// mr r16,r8
	r16.u64 = ctx.r8.u64;
	// rlwinm r20,r7,31,31,31
	r20.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x1;
	// rlwinm r19,r7,9,31,31
	r19.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 9) & 0x1;
	// rlwinm r21,r7,8,31,31
	r21.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0x1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82175b30
	if (!cr6.eq) goto loc_82175B30;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f29,-160(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// lfd f30,-152(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
loc_82175B30:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// ori r8,r10,57792
	ctx.r8.u64 = ctx.r10.u64 | 57792;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// mullw r10,r4,r8
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// lfs f31,25488(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 25488);
	f31.f64 = double(temp.f32);
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// lis r28,240
	r28.s64 = 15728640;
	// addis r26,r29,1
	r26.s64 = r29.s64 + 65536;
	// addis r22,r29,1
	r22.s64 = r29.s64 + 65536;
	// li r23,0
	r23.s64 = 0;
	// addi r26,r26,-12080
	r26.s64 = r26.s64 + -12080;
	// addi r22,r22,-12016
	r22.s64 = r22.s64 + -12016;
	// ori r28,r28,61680
	r28.u64 = r28.u64 | 61680;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82175d2c
	if (cr6.eq) goto loc_82175D2C;
	// li r24,0
	r24.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r18,0
	cr6.compare<int32_t>(r18.s32, 0, xer);
	// ble cr6,0x82175cd8
	if (!cr6.gt) goto loc_82175CD8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,80
	ctx.r9.s64 = 5242880;
	// addi r30,r17,8
	r30.s64 = r17.s64 + 8;
	// ori r25,r9,20560
	r25.u64 = ctx.r9.u64 | 20560;
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lfs f29,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
loc_82175BA0:
	// lfs f0,-8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -8);
	f0.f64 = double(temp.f32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lfs f13,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r31,0
	r31.s64 = 0;
	// stfs f29,92(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x821ce9d8
	ctx.lr = 0x82175BD0;
	sub_821CE9D8(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175be4
	if (!cr6.gt) goto loc_82175BE4;
	// lis r31,32
	r31.s64 = 2097152;
	// b 0x82175bf0
	goto loc_82175BF0;
loc_82175BE4:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175bf0
	if (!cr6.lt) goto loc_82175BF0;
	// lis r31,16
	r31.s64 = 1048576;
loc_82175BF0:
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175c04
	if (!cr6.gt) goto loc_82175C04;
	// ori r31,r31,8192
	r31.u64 = r31.u64 | 8192;
	// b 0x82175c10
	goto loc_82175C10;
loc_82175C04:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175c10
	if (!cr6.lt) goto loc_82175C10;
	// ori r31,r31,4096
	r31.u64 = r31.u64 | 4096;
loc_82175C10:
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175c24
	if (!cr6.gt) goto loc_82175C24;
	// ori r31,r31,32
	r31.u64 = r31.u64 | 32;
	// b 0x82175c30
	goto loc_82175C30;
loc_82175C24:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175c30
	if (!cr6.lt) goto loc_82175C30;
	// ori r31,r31,16
	r31.u64 = r31.u64 | 16;
loc_82175C30:
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821ce9d8
	ctx.lr = 0x82175C40;
	sub_821CE9D8(ctx, base);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175c54
	if (!cr6.gt) goto loc_82175C54;
	// oris r31,r31,128
	r31.u64 = r31.u64 | 8388608;
	// b 0x82175c60
	goto loc_82175C60;
loc_82175C54:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175c60
	if (!cr6.lt) goto loc_82175C60;
	// oris r31,r31,64
	r31.u64 = r31.u64 | 4194304;
loc_82175C60:
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175c74
	if (!cr6.gt) goto loc_82175C74;
	// ori r31,r31,32768
	r31.u64 = r31.u64 | 32768;
	// b 0x82175c80
	goto loc_82175C80;
loc_82175C74:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175c80
	if (!cr6.lt) goto loc_82175C80;
	// ori r31,r31,16384
	r31.u64 = r31.u64 | 16384;
loc_82175C80:
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82175c94
	if (!cr6.gt) goto loc_82175C94;
	// ori r31,r31,128
	r31.u64 = r31.u64 | 128;
	// b 0x82175ca0
	goto loc_82175CA0;
loc_82175C94:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82175ca0
	if (!cr6.lt) goto loc_82175CA0;
	// ori r31,r31,64
	r31.u64 = r31.u64 | 64;
loc_82175CA0:
	// lis r12,80
	r12.s64 = 5242880;
	// and r28,r31,r28
	r28.u64 = r31.u64 & r28.u64;
	// ori r12,r12,20560
	r12.u64 = r12.u64 | 20560;
	// and r11,r31,r12
	r11.u64 = r31.u64 & r12.u64;
	// cmplw cr6,r11,r25
	cr6.compare<uint32_t>(r11.u32, r25.u32, xer);
	// bne cr6,0x82175cc8
	if (!cr6.eq) goto loc_82175CC8;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// li r24,1
	r24.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175cd8
	if (!cr6.eq) goto loc_82175CD8;
loc_82175CC8:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmpw cr6,r27,r18
	cr6.compare<int32_t>(r27.s32, r18.s32, xer);
	// blt cr6,0x82175ba0
	if (cr6.lt) goto loc_82175BA0;
loc_82175CD8:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175d2c
	if (!cr6.eq) goto loc_82175D2C;
	// lis r12,160
	r12.s64 = 10485760;
	// ori r12,r12,41120
	r12.u64 = r12.u64 | 41120;
	// and r11,r28,r12
	r11.u64 = r28.u64 & r12.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82175d2c
	if (cr6.eq) goto loc_82175D2C;
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82175d28
	if (cr6.eq) goto loc_82175D28;
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175d28
	if (!cr6.eq) goto loc_82175D28;
	// oris r3,r28,1024
	ctx.r3.u64 = r28.u64 | 67108864;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f29,-160(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// lfd f30,-152(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
loc_82175D28:
	// lis r23,1024
	r23.s64 = 67108864;
loc_82175D2C:
	// lis r11,0
	r11.s64 = 0;
	// or r31,r28,r23
	r31.u64 = r28.u64 | r23.u64;
	// ori r10,r11,52224
	ctx.r10.u64 = r11.u64 | 52224;
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82175d5c
	if (!cr6.eq) goto loc_82175D5C;
	// lis r3,2048
	ctx.r3.s64 = 134217728;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f29,-160(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// lfd f30,-152(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
loc_82175D5C:
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82175e3c
	if (!cr6.gt) goto loc_82175E3C;
	// addi r6,r29,288
	ctx.r6.s64 = r29.s64 + 288;
loc_82175D6C:
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x82175d80
	if (cr6.eq) goto loc_82175D80;
	// lwz r11,-32(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32);
	// cmplw cr6,r11,r16
	cr6.compare<uint32_t>(r11.u32, r16.u32, xer);
	// beq cr6,0x82175e2c
	if (cr6.eq) goto loc_82175E2C;
loc_82175D80:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82175e2c
	if (cr6.eq) goto loc_82175E2C;
	// lwz r11,-20(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175e2c
	if (!cr6.eq) goto loc_82175E2C;
	// lwz r7,-12(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82175e20
	if (!cr6.gt) goto loc_82175E20;
	// addi r9,r6,-288
	ctx.r9.s64 = ctx.r6.s64 + -288;
loc_82175DB4:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r18,0
	cr6.compare<int32_t>(r18.s32, 0, xer);
	// ble cr6,0x82175e04
	if (!cr6.gt) goto loc_82175E04;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r17
	r11.u64 = r17.u64;
	// lfs f0,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	f0.f64 = double(temp.f32);
loc_82175DCC:
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// vmsum3fp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// stvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82175e00
	if (cr6.gt) goto loc_82175E00;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// blt cr6,0x82175dcc
	if (cr6.lt) goto loc_82175DCC;
	// b 0x82175e04
	goto loc_82175E04;
loc_82175E00:
	// li r5,1
	ctx.r5.s64 = 1;
loc_82175E04:
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82175e20
	if (!cr6.eq) goto loc_82175E20;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x82175db4
	if (cr6.lt) goto loc_82175DB4;
loc_82175E20:
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82175e54
	if (cr6.eq) goto loc_82175E54;
loc_82175E2C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r6,r6,816
	ctx.r6.s64 = ctx.r6.s64 + 816;
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// blt cr6,0x82175d6c
	if (cr6.lt) goto loc_82175D6C;
loc_82175E3C:
	// oris r3,r31,8192
	ctx.r3.u64 = r31.u64 | 536870912;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f29,-160(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// lfd f30,-152(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
loc_82175E54:
	// oris r3,r31,4096
	ctx.r3.u64 = r31.u64 | 268435456;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f29,-160(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// lfd f30,-152(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82175E6C"))) PPC_WEAK_FUNC(sub_82175E6C);
PPC_FUNC_IMPL(__imp__sub_82175E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175E70"))) PPC_WEAK_FUNC(sub_82175E70);
PPC_FUNC_IMPL(__imp__sub_82175E70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
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
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r11,-32255
	r11.s64 = -2113863680;
	// vspltisw128 v62,2
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x2)));
	// lwz r10,384(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// addi r9,r11,-30448
	ctx.r9.s64 = r11.s64 + -30448;
	// vspltisw128 v61,4
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x4)));
	// vspltisw128 v60,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// vslw128 v59,v63,v63
	v59.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v59.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v59.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v59.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v58,v1,v59
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vspltw128 v57,v63,1
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vspltw128 v56,v63,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v53,v63,2
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v55,v58,1
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xAA));
	// vspltw128 v54,v58,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vspltw128 v52,v58,2
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// vsraw128 v51,v55,v57
	v51.s32[0] = v55.s32[0] >> (v57.u8[0] & 0x1F);
	v51.s32[1] = v55.s32[1] >> (v57.u8[4] & 0x1F);
	v51.s32[2] = v55.s32[2] >> (v57.u8[8] & 0x1F);
	v51.s32[3] = v55.s32[3] >> (v57.u8[12] & 0x1F);
	// vsraw128 v50,v54,v56
	v50.s32[0] = v54.s32[0] >> (v56.u8[0] & 0x1F);
	v50.s32[1] = v54.s32[1] >> (v56.u8[4] & 0x1F);
	v50.s32[2] = v54.s32[2] >> (v56.u8[8] & 0x1F);
	v50.s32[3] = v54.s32[3] >> (v56.u8[12] & 0x1F);
	// vsraw128 v49,v52,v53
	v49.s32[0] = v52.s32[0] >> (v53.u8[0] & 0x1F);
	v49.s32[1] = v52.s32[1] >> (v53.u8[4] & 0x1F);
	v49.s32[2] = v52.s32[2] >> (v53.u8[8] & 0x1F);
	v49.s32[3] = v52.s32[3] >> (v53.u8[12] & 0x1F);
	// vand128 v48,v51,v62
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vand128 v47,v50,v61
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vand128 v46,v49,v60
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vor128 v45,v47,v48
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v48.u8)));
	// vor128 v44,v45,v46
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v46.u8)));
	// stvx128 v44,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,-16(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// stwx r6,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r6.u32);
	// lwz r11,384(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwzx r11,r5,r3
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// subfic r10,r11,7
	xer.ca = r11.u32 <= 7;
	ctx.r10.s64 = 7 - r11.s64;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// lwz r11,384(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// addi r8,r11,8
	ctx.r8.s64 = r11.s64 + 8;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r7,384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 384, ctx.r7.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82175F20"))) PPC_WEAK_FUNC(sub_82175F20);
PPC_FUNC_IMPL(__imp__sub_82175F20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v63{};
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
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x82175238
	ctx.lr = 0x82175F48;
	sub_82175238(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82175F58"))) PPC_WEAK_FUNC(sub_82175F58);
PPC_FUNC_IMPL(__imp__sub_82175F58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dd52c
	ctx.lr = 0x82175F6C;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,32
	r11.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r5,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v59,v61,v61
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_setzero_si128());
	// vxor128 v58,v60,v60
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_setzero_si128());
	// lvx128 v57,r4,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r4,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r5,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v54,v63,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v53,r5,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r8.u32);
	// vsubfp128 v52,v59,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32)));
	// vmrghw128 v51,v62,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vsubfp128 v50,v58,v60
	simde_mm_store_ps(v50.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32)));
	// vmrglw128 v49,v63,v56
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrglw128 v48,v62,v53
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v47,v57,v52
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v46,v55,v50
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrglw128 v45,v57,v52
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v44,v55,v50
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v1,v54,v47
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v127,v54,v47
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v126,v49,v45
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v125,v48,v44
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v124,v51,v46
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v123,v51,v46
	simde_mm_store_si128((simde__m128i*)v123.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// bl 0x82175e70
	ctx.lr = 0x82175FF4;
	sub_82175E70(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82175e70
	ctx.lr = 0x82176000;
	sub_82175E70(ctx, base);
	// vor128 v1,v123,v123
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82175e70
	ctx.lr = 0x8217600C;
	sub_82175E70(ctx, base);
	// vor128 v1,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82175e70
	ctx.lr = 0x82176018;
	sub_82175E70(ctx, base);
	// vor128 v1,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82175e70
	ctx.lr = 0x82176024;
	sub_82175E70(ctx, base);
	// vor128 v1,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82175e70
	ctx.lr = 0x82176030;
	sub_82175E70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821744d0
	ctx.lr = 0x82176038;
	sub_821744D0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dd7c4
	ctx.lr = 0x82176044;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176054"))) PPC_WEAK_FUNC(sub_82176054);
PPC_FUNC_IMPL(__imp__sub_82176054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176058"))) PPC_WEAK_FUNC(sub_82176058);
PPC_FUNC_IMPL(__imp__sub_82176058) {
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
	// bl 0x823d91ec
	ctx.lr = 0x82176060;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addis r5,r28,1
	ctx.r5.s64 = r28.s64 + 65536;
	// addis r4,r28,1
	ctx.r4.s64 = r28.s64 + 65536;
	// addi r5,r5,-12016
	ctx.r5.s64 = ctx.r5.s64 + -12016;
	// addi r4,r4,-12080
	ctx.r4.s64 = ctx.r4.s64 + -12080;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82175f58
	ctx.lr = 0x82176088;
	sub_82175F58(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,-1
	r11.s64 = r31.s64 + -1;
	// ori r9,r10,52224
	ctx.r9.u64 = ctx.r10.u64 | 52224;
	// mr r25,r11
	r25.u64 = r11.u64;
	// lwzx r10,r28,r9
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + ctx.r9.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x821760a8
	if (cr6.lt) goto loc_821760A8;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
loc_821760A8:
	// li r27,0
	r27.s64 = 0;
	// li r26,1
	r26.s64 = 1;
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x821761c0
	if (!cr6.gt) goto loc_821761C0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r31,r30,400
	r31.s64 = r30.s64 + 400;
	// addi r30,r11,-30448
	r30.s64 = r11.s64 + -30448;
loc_821760C8:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82174ce8
	ctx.lr = 0x821760D8;
	sub_82174CE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r27,384(r31)
	PPC_STORE_U32(r31.u32 + 384, r27.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821761b4
	if (cr6.eq) goto loc_821761B4;
	// ble cr6,0x821761a4
	if (!cr6.gt) goto loc_821761A4;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vspltisw128 v62,1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x1)));
	// vspltisw128 v61,2
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x2)));
	// vspltisw128 v60,4
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x4)));
	// vslw128 v59,v63,v63
	v59.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v59.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v59.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v59.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
loc_82176104:
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,384(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// vand128 v57,v58,v59
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v56,v63,1
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vspltw128 v54,v63,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// vspltw128 v52,v63,2
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// vspltw128 v55,v57,1
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xAA));
	// vspltw128 v53,v57,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v51,v57,2
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x55));
	// vsraw128 v50,v55,v56
	v50.s32[0] = v55.s32[0] >> (v56.u8[0] & 0x1F);
	v50.s32[1] = v55.s32[1] >> (v56.u8[4] & 0x1F);
	v50.s32[2] = v55.s32[2] >> (v56.u8[8] & 0x1F);
	v50.s32[3] = v55.s32[3] >> (v56.u8[12] & 0x1F);
	// vsraw128 v49,v53,v54
	v49.s32[0] = v53.s32[0] >> (v54.u8[0] & 0x1F);
	v49.s32[1] = v53.s32[1] >> (v54.u8[4] & 0x1F);
	v49.s32[2] = v53.s32[2] >> (v54.u8[8] & 0x1F);
	v49.s32[3] = v53.s32[3] >> (v54.u8[12] & 0x1F);
	// vsraw128 v48,v51,v52
	v48.s32[0] = v51.s32[0] >> (v52.u8[0] & 0x1F);
	v48.s32[1] = v51.s32[1] >> (v52.u8[4] & 0x1F);
	v48.s32[2] = v51.s32[2] >> (v52.u8[8] & 0x1F);
	v48.s32[3] = v51.s32[3] >> (v52.u8[12] & 0x1F);
	// vand128 v47,v50,v61
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vand128 v46,v49,v60
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vand128 v45,v48,v62
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vor128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v47.u8)));
	// vor128 v43,v44,v45
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v45.u8)));
	// stvx128 v43,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stwx r6,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r6.u32);
	// lwz r9,384(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r9,16
	ctx.r4.s64 = ctx.r9.s64 + 16;
	// lwzx r3,r5,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + r31.u32);
	// subfic r9,r3,7
	xer.ca = ctx.r3.u32 <= 7;
	ctx.r9.s64 = 7 - ctx.r3.s64;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwx r9,r8,r31
	PPC_STORE_U32(ctx.r8.u32 + r31.u32, ctx.r9.u32);
	// lwz r9,384(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// addi r7,r9,8
	ctx.r7.s64 = ctx.r9.s64 + 8;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r6,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r6.u32);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x82176104
	if (!cr0.eq) goto loc_82176104;
loc_821761A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r31,r31,400
	r31.s64 = r31.s64 + 400;
	// bl 0x821744d0
	ctx.lr = 0x821761B4;
	sub_821744D0(ctx, base);
loc_821761B4:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r25
	cr6.compare<int32_t>(r29.s32, r25.s32, xer);
	// blt cr6,0x821760c8
	if (cr6.lt) goto loc_821760C8;
loc_821761C0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821761CC"))) PPC_WEAK_FUNC(sub_821761CC);
PPC_FUNC_IMPL(__imp__sub_821761CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821761D0"))) PPC_WEAK_FUNC(sub_821761D0);
PPC_FUNC_IMPL(__imp__sub_821761D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
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
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8217624c
	if (cr6.eq) goto loc_8217624C;
	// lis r11,4095
	r11.s64 = 268369920;
	// rlwinm r3,r30,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// ble cr6,0x8217620c
	if (!cr6.gt) goto loc_8217620C;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8217620C:
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82130550
	ctx.lr = 0x82176214;
	sub_82130550(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// ble cr6,0x8217624c
	if (!cr6.gt) goto loc_8217624C;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8217622C:
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lvx128 v63,r8,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,80
	ctx.r10.s64 = ctx.r10.s64 + 80;
	// stvx128 v63,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x8217622c
	if (!cr0.eq) goto loc_8217622C;
loc_8217624C:
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

__attribute__((alias("__imp__sub_82176268"))) PPC_WEAK_FUNC(sub_82176268);
PPC_FUNC_IMPL(__imp__sub_82176268) {
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
	ctx.lr = 0x82176270;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,2047
	r11.s64 = 134152192;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bgt cr6,0x821762a4
	if (cr6.gt) goto loc_821762A4;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// li r10,-17
	ctx.r10.s64 = -17;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x821762a8
	if (!cr6.gt) goto loc_821762A8;
loc_821762A4:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_821762A8:
	// bl 0x82130528
	ctx.lr = 0x821762AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821762e4
	if (cr6.eq) goto loc_821762E4;
	// addi r28,r3,16
	r28.s64 = ctx.r3.s64 + 16;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// addic. r31,r29,-1
	xer.ca = r29.u32 > 0;
	r31.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// mr r30,r28
	r30.u64 = r28.u64;
	// blt 0x821762dc
	if (cr0.lt) goto loc_821762DC;
loc_821762C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821770f0
	ctx.lr = 0x821762D0;
	sub_821770F0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// bge 0x821762c8
	if (!cr0.lt) goto loc_821762C8;
loc_821762DC:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821762f0
	if (!cr6.eq) goto loc_821762F0;
loc_821762E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821762F0:
	// stw r29,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82176304"))) PPC_WEAK_FUNC(sub_82176304);
PPC_FUNC_IMPL(__imp__sub_82176304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176308"))) PPC_WEAK_FUNC(sub_82176308);
PPC_FUNC_IMPL(__imp__sub_82176308) {
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
	ctx.lr = 0x82176310;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,819
	r11.s64 = 53673984;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// ori r10,r11,13107
	ctx.r10.u64 = r11.u64 | 13107;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8217634c
	if (cr6.gt) goto loc_8217634C;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,-17
	ctx.r10.s64 = -17;
	// add r9,r29,r11
	ctx.r9.u64 = r29.u64 + r11.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// ble cr6,0x82176350
	if (!cr6.gt) goto loc_82176350;
loc_8217634C:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82176350:
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82130550
	ctx.lr = 0x82176358;
	sub_82130550(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82176390
	if (cr6.eq) goto loc_82176390;
	// addi r28,r3,16
	r28.s64 = ctx.r3.s64 + 16;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// addic. r31,r29,-1
	xer.ca = r29.u32 > 0;
	r31.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// mr r30,r28
	r30.u64 = r28.u64;
	// blt 0x82176388
	if (cr0.lt) goto loc_82176388;
loc_82176374:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82171f80
	ctx.lr = 0x8217637C;
	sub_82171F80(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// bge 0x82176374
	if (!cr0.lt) goto loc_82176374;
loc_82176388:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8217639c
	if (!cr6.eq) goto loc_8217639C;
loc_82176390:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8217639C:
	// stw r29,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821763B0"))) PPC_WEAK_FUNC(sub_821763B0);
PPC_FUNC_IMPL(__imp__sub_821763B0) {
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
	ctx.lr = 0x821763B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82176404
	if (cr6.eq) goto loc_82176404;
	// lwz r9,-16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// addi r29,r11,-16
	r29.s64 = r11.s64 + -16;
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// addic. r31,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r31.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// blt 0x821763fc
	if (cr0.lt) goto loc_821763FC;
loc_821763E8:
	// addi r30,r30,-32
	r30.s64 = r30.s64 + -32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82177130
	ctx.lr = 0x821763F4;
	sub_82177130(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x821763e8
	if (!cr0.lt) goto loc_821763E8;
loc_821763FC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82176404;
	sub_82130588(ctx, base);
loc_82176404:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82176418"))) PPC_WEAK_FUNC(sub_82176418);
PPC_FUNC_IMPL(__imp__sub_82176418) {
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
	ctx.lr = 0x82176420;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82176474
	if (cr6.eq) goto loc_82176474;
	// lwz r11,-16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	// addi r29,r10,-16
	r29.s64 = ctx.r10.s64 + -16;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// blt 0x8217646c
	if (cr0.lt) goto loc_8217646C;
loc_82176458:
	// addi r30,r30,-80
	r30.s64 = r30.s64 + -80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82171fb8
	ctx.lr = 0x82176464;
	sub_82171FB8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x82176458
	if (!cr0.lt) goto loc_82176458;
loc_8217646C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82176474;
	sub_82130588(ctx, base);
loc_82176474:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82176488"))) PPC_WEAK_FUNC(sub_82176488);
PPC_FUNC_IMPL(__imp__sub_82176488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82176490;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// blt cr6,0x821765a0
	if (cr6.lt) goto loc_821765A0;
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bgt cr6,0x821765a0
	if (cr6.gt) goto loc_821765A0;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r28,0(r6)
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82176594
	if (!cr6.gt) goto loc_82176594;
	// mr r25,r11
	r25.u64 = r11.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r27,r10,-29968
	r27.s64 = ctx.r10.s64 + -29968;
	// addi r26,r11,-29976
	r26.s64 = r11.s64 + -29976;
loc_821764CC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821764E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82176500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,24(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r28.u32 + 24, temp.u32);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82176580
	if (!cr6.gt) goto loc_82176580;
loc_82176510:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82176544;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82176560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82177170
	ctx.lr = 0x82176574;
	sub_82177170(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x82176510
	if (cr6.lt) goto loc_82176510;
loc_82176580:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82177188
	ctx.lr = 0x82176588;
	sub_82177188(ctx, base);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r28,r28,32
	r28.s64 = r28.s64 + 32;
	// bne 0x821764cc
	if (!cr0.eq) goto loc_821764CC;
loc_82176594:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_821765A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821765AC"))) PPC_WEAK_FUNC(sub_821765AC);
PPC_FUNC_IMPL(__imp__sub_821765AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821765B0"))) PPC_WEAK_FUNC(sub_821765B0);
PPC_FUNC_IMPL(__imp__sub_821765B0) {
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
	ctx.lr = 0x821765B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821763b0
	ctx.lr = 0x821765DC;
	sub_821763B0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82176418
	ctx.lr = 0x821765E8;
	sub_82176418(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-29944
	ctx.r4.s64 = r11.s64 + -29944;
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82176604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// blt cr6,0x8217665c
	if (cr6.lt) goto loc_8217665C;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bgt cr6,0x8217665c
	if (cr6.gt) goto loc_8217665C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-29956
	ctx.r4.s64 = ctx.r10.s64 + -29956;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82176634;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82176308
	ctx.lr = 0x82176640;
	sub_82176308(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82176268
	ctx.lr = 0x82176650;
	sub_82176268(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8217665C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82176668"))) PPC_WEAK_FUNC(sub_82176668);
PPC_FUNC_IMPL(__imp__sub_82176668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 544);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// stw r11,544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 544, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176678"))) PPC_WEAK_FUNC(sub_82176678);
PPC_FUNC_IMPL(__imp__sub_82176678) {
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
	// bl 0x823d91c0
	ctx.lr = 0x82176680;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9b4
	ctx.lr = 0x82176688;
	// stwu r1,-992(r1)
	ea = -992 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// blt cr6,0x82176f98
	if (cr6.lt) goto loc_82176F98;
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bgt cr6,0x82176f98
	if (cr6.gt) goto loc_82176F98;
	// lwz r30,0(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// lwz r29,0(r5)
	r29.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// bne cr6,0x82176c6c
	if (!cr6.eq) goto loc_82176C6C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r26,r11,-29624
	r26.s64 = r11.s64 + -29624;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821d0898
	ctx.lr = 0x821766C4;
	sub_821D0898(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// addi r23,r11,-29628
	r23.s64 = r11.s64 + -29628;
	// ble cr6,0x82176c4c
	if (!cr6.gt) goto loc_82176C4C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f19,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f19.f64 = double(temp.f32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f29,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f29.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f21,-29632(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29632);
	f21.f64 = double(temp.f32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f22,-31400(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31400);
	f22.f64 = double(temp.f32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lfs f20,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f20.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f19,156(r1)
	temp.f32 = float(f19.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stfs f19,172(r1)
	temp.f32 = float(f19.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// li r14,-46
	r14.s64 = -46;
	// li r15,-62
	r15.s64 = -62;
	// addi r16,r11,-29644
	r16.s64 = r11.s64 + -29644;
	// addi r21,r10,-29652
	r21.s64 = ctx.r10.s64 + -29652;
	// addi r22,r9,-29664
	r22.s64 = ctx.r9.s64 + -29664;
	// addi r20,r8,-29680
	r20.s64 = ctx.r8.s64 + -29680;
	// addi r19,r7,9848
	r19.s64 = ctx.r7.s64 + 9848;
	// addi r18,r6,10380
	r18.s64 = ctx.r6.s64 + 10380;
	// addi r17,r5,-29692
	r17.s64 = ctx.r5.s64 + -29692;
loc_82176748:
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82176758;
	sub_821CFE80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0228
	ctx.lr = 0x82176760;
	sub_821D0228(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x8217676C;
	sub_821D0898(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176778;
	sub_821D0898(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x821767A0;
	sub_821D0898(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821767BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r25,r30,78
	r25.s64 = r30.s64 + 78;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82137a08
	ctx.lr = 0x821767D0;
	sub_82137A08(ctx, base);
	// stfs f20,60(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f20.f64);
	PPC_STORE_U32(r30.u32 + 60, temp.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,68(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821767F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821d0898
	ctx.lr = 0x82176808;
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
	ctx.lr = 0x82176820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82171a68
	ctx.lr = 0x82176830;
	sub_82171A68(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x8217683C;
	sub_821D0898(ctx, base);
	// fmr f28,f22
	ctx.fpscr.disableFlushMode();
	f28.f64 = f22.f64;
	// fmr f23,f22
	f23.f64 = f22.f64;
	// stfs f28,144(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmr f24,f22
	f24.f64 = f22.f64;
	// stfs f23,148(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmr f25,f21
	f25.f64 = f21.f64;
	// stfs f24,152(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmr f26,f21
	f26.f64 = f21.f64;
	// stfs f25,160(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fmr f27,f21
	f27.f64 = f21.f64;
	// stfs f26,164(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f27,168(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82176950
	if (!cr6.gt) goto loc_82176950;
	// li r28,0
	r28.s64 = 0;
loc_82176878:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// stfs f31,128(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821768B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// stfs f30,132(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821768D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fcmpu cr6,f31,f28
	cr6.compare(f31.f64, f28.f64);
	// bge cr6,0x821768e0
	if (!cr6.lt) goto loc_821768E0;
	// fmr f28,f31
	f28.f64 = f31.f64;
loc_821768E0:
	// fcmpu cr6,f30,f23
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f23.f64);
	// bge cr6,0x821768ec
	if (!cr6.lt) goto loc_821768EC;
	// fmr f23,f30
	f23.f64 = f30.f64;
loc_821768EC:
	// fcmpu cr6,f1,f24
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f24.f64);
	// bge cr6,0x821768f8
	if (!cr6.lt) goto loc_821768F8;
	// fmr f24,f1
	f24.f64 = ctx.f1.f64;
loc_821768F8:
	// fcmpu cr6,f31,f25
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f25.f64);
	// ble cr6,0x82176904
	if (!cr6.gt) goto loc_82176904;
	// fmr f25,f31
	f25.f64 = f31.f64;
loc_82176904:
	// fcmpu cr6,f30,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f26.f64);
	// ble cr6,0x82176910
	if (!cr6.gt) goto loc_82176910;
	// fmr f26,f30
	f26.f64 = f30.f64;
loc_82176910:
	// fcmpu cr6,f1,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f27.f64);
	// ble cr6,0x8217691c
	if (!cr6.gt) goto loc_8217691C;
	// fmr f27,f1
	f27.f64 = ctx.f1.f64;
loc_8217691C:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lwz r10,-26(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + -26);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r28,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r28,16
	r28.s64 = r28.s64 + 16;
	// bne 0x82176878
	if (!cr0.eq) goto loc_82176878;
	// stfs f27,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f26,164(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f25,160(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f24,152(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f23,148(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f28,144(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
loc_82176950:
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// vaddfp128 v60,v63,v62
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmuls f10,f0,f29
	ctx.f10.f64 = double(float(f0.f64 * f29.f64));
	// fmuls f11,f12,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 * f29.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f9,f13,f29
	ctx.f9.f64 = double(float(ctx.f13.f64 * f29.f64));
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f19,108(r1)
	temp.f32 = float(f19.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v59,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f6.f64 = double(temp.f32);
	// lfs f8,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f3,f8,f29
	ctx.f3.f64 = double(float(ctx.f8.f64 * f29.f64));
	// lfs f5,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f2,f7,f29
	ctx.f2.f64 = double(float(ctx.f7.f64 * f29.f64));
	// fmuls f4,f5,f29
	ctx.f4.f64 = double(float(ctx.f5.f64 * f29.f64));
	// stfs f4,112(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fsqrts f1,f6
	ctx.f1.f64 = double(float(sqrt(ctx.f6.f64)));
	// stfs f3,116(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f2,120(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stvx128 v63,r25,r14
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + r14.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r25,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821d0898
	ctx.lr = 0x82176A00;
	sub_821D0898(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176A0C;
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
	ctx.lr = 0x82176A24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82171ad0
	ctx.lr = 0x82176A34;
	sub_82171AD0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176A40;
	sub_821D0898(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82176aa0
	if (!cr6.gt) goto loc_82176AA0;
loc_82176A4C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176A64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// extsb r27,r3
	r27.s64 = ctx.r3.s8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82176A80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsb r6,r3
	ctx.r6.s64 = ctx.r3.s8;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// extsb r4,r29
	ctx.r4.s64 = r29.s8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82171e50
	ctx.lr = 0x82176A94;
	sub_82171E50(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// blt cr6,0x82176a4c
	if (cr6.lt) goto loc_82176A4C;
loc_82176AA0:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176AAC;
	sub_821D0898(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82171b60
	ctx.lr = 0x82176AD4;
	sub_82171B60(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176AE0;
	sub_821D0898(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x82176c08
	if (!cr6.gt) goto loc_82176C08;
loc_82176AEC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176B04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176B14;
	sub_821D0898(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82171938
	ctx.lr = 0x82176B24;
	sub_82171938(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821719d0
	ctx.lr = 0x82176B34;
	sub_821719D0(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82176b78
	if (!cr6.gt) goto loc_82176B78;
loc_82176B40:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82171a30
	ctx.lr = 0x82176B6C;
	sub_82171A30(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82176b40
	if (cr6.lt) goto loc_82176B40;
loc_82176B78:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176B84;
	sub_821D0898(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176B9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176BAC;
	sub_821D0898(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82176bf0
	if (!cr6.gt) goto loc_82176BF0;
loc_82176BB8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821719f8
	ctx.lr = 0x82176BE4;
	sub_821719F8(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82176bb8
	if (cr6.lt) goto loc_82176BB8;
loc_82176BF0:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176BFC;
	sub_821D0898(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r24
	cr6.compare<int32_t>(r28.s32, r24.s32, xer);
	// blt cr6,0x82176aec
	if (cr6.lt) goto loc_82176AEC;
loc_82176C08:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176C14;
	sub_821D0898(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82176C1C;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82172028
	ctx.lr = 0x82176C24;
	sub_82172028(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// stb r11,-14(r25)
	PPC_STORE_U8(r25.u32 + -14, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176C38;
	sub_821D0898(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bne 0x82176748
	if (!cr0.eq) goto loc_82176748;
loc_82176C4C:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82176C58;
	sub_821D0898(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,992
	ctx.r1.s64 = ctx.r1.s64 + 992;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba00
	ctx.lr = 0x82176C68;
	// b 0x823d9210
	return;
loc_82176C6C:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82176f84
	if (!cr6.gt) goto loc_82176F84;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r17,r29
	r17.u64 = r29.u64;
	// addi r23,r8,-29708
	r23.s64 = ctx.r8.s64 + -29708;
	// addi r25,r7,-29720
	r25.s64 = ctx.r7.s64 + -29720;
	// addi r24,r6,-29736
	r24.s64 = ctx.r6.s64 + -29736;
	// addi r22,r5,-29744
	r22.s64 = ctx.r5.s64 + -29744;
	// addi r21,r4,-29752
	r21.s64 = ctx.r4.s64 + -29752;
	// addi r20,r9,-29760
	r20.s64 = ctx.r9.s64 + -29760;
	// addi r19,r10,-29968
	r19.s64 = ctx.r10.s64 + -29968;
	// addi r18,r11,-29976
	r18.s64 = r11.s64 + -29976;
loc_82176CB8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176CD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82176CEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,60(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 60, temp.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,68(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82176D0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82171a68
	ctx.lr = 0x82176D24;
	sub_82171A68(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82176da0
	if (!cr6.gt) goto loc_82176DA0;
	// li r28,0
	r28.s64 = 0;
loc_82176D30:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82176D64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82176D80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lwz r4,52(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// stfs f1,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// lvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r4,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r28,16
	r28.s64 = r28.s64 + 16;
	// bne 0x82176d30
	if (!cr0.eq) goto loc_82176D30;
loc_82176DA0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82171ad0
	ctx.lr = 0x82176DC8;
	sub_82171AD0(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82176e28
	if (!cr6.gt) goto loc_82176E28;
loc_82176DD4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176DEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// extsb r27,r3
	r27.s64 = ctx.r3.s8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82176E08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsb r6,r3
	ctx.r6.s64 = ctx.r3.s8;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// extsb r4,r29
	ctx.r4.s64 = r29.s8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82171e50
	ctx.lr = 0x82176E1C;
	sub_82171E50(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// blt cr6,0x82176dd4
	if (cr6.lt) goto loc_82176DD4;
loc_82176E28:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82171b60
	ctx.lr = 0x82176E50;
	sub_82171B60(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82176f60
	if (!cr6.gt) goto loc_82176F60;
loc_82176E5C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176E74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82171938
	ctx.lr = 0x82176E88;
	sub_82171938(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82176EA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821719d0
	ctx.lr = 0x82176EB0;
	sub_821719D0(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82176ef4
	if (!cr6.gt) goto loc_82176EF4;
loc_82176EBC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176ED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82171a30
	ctx.lr = 0x82176EE8;
	sub_82171A30(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82176ebc
	if (cr6.lt) goto loc_82176EBC;
loc_82176EF4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82176f54
	if (!cr6.gt) goto loc_82176F54;
loc_82176F1C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176F34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821719f8
	ctx.lr = 0x82176F48;
	sub_821719F8(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82176f1c
	if (cr6.lt) goto loc_82176F1C;
loc_82176F54:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// blt cr6,0x82176e5c
	if (cr6.lt) goto loc_82176E5C;
loc_82176F60:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82176F68;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82172028
	ctx.lr = 0x82176F70;
	sub_82172028(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// addic. r17,r17,-1
	xer.ca = r17.u32 > 0;
	r17.s64 = r17.s64 + -1;
	cr0.compare<int32_t>(r17.s32, 0, xer);
	// stb r11,64(r30)
	PPC_STORE_U8(r30.u32 + 64, r11.u8);
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// bne 0x82176cb8
	if (!cr0.eq) goto loc_82176CB8;
loc_82176F84:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,992
	ctx.r1.s64 = ctx.r1.s64 + 992;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba00
	ctx.lr = 0x82176F94;
	// b 0x823d9210
	return;
loc_82176F98:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,992
	ctx.r1.s64 = ctx.r1.s64 + 992;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba00
	ctx.lr = 0x82176FA8;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82176FAC"))) PPC_WEAK_FUNC(sub_82176FAC);
PPC_FUNC_IMPL(__imp__sub_82176FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176FB0"))) PPC_WEAK_FUNC(sub_82176FB0);
PPC_FUNC_IMPL(__imp__sub_82176FB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x82176FB8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x821765b0
	ctx.lr = 0x82176FD4;
	sub_821765B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x82176fec
	if (!cr6.eq) goto loc_82176FEC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82176FEC:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82176678
	ctx.lr = 0x82177000;
	sub_82176678(ctx, base);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82176488
	ctx.lr = 0x82177014;
	sub_82176488(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82177020"))) PPC_WEAK_FUNC(sub_82177020);
PPC_FUNC_IMPL(__imp__sub_82177020) {
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
	ctx.lr = 0x82177028;
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x82177050;
	sub_821CA6A8(ctx, base);
	// bl 0x821be8d8
	ctx.lr = 0x82177054;
	sub_821BE8D8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r9,-29556
	ctx.r3.s64 = ctx.r9.s64 + -29556;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82177068;
	sub_82130000(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82177094
	if (!cr6.eq) goto loc_82177094;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,-29620
	ctx.r5.s64 = r11.s64 + -29620;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// bl 0x82137a08
	ctx.lr = 0x82177088;
	sub_82137A08(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x823d924c
	return;
loc_82177094:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-29924
	ctx.r9.s64 = r11.s64 + -29924;
	// stw r10,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r10.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x821770B8;
	sub_821CF7B8(ctx, base);
	// addi r7,r31,12
	ctx.r7.s64 = r31.s64 + 12;
	// addi r6,r31,8
	ctx.r6.s64 = r31.s64 + 8;
	// addi r5,r31,20
	ctx.r5.s64 = r31.s64 + 20;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82176fb0
	ctx.lr = 0x821770D0;
	sub_82176FB0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x821770DC;
	sub_821BE610(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821761d0
	ctx.lr = 0x821770E4;
	sub_821761D0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821770F0"))) PPC_WEAK_FUNC(sub_821770F0);
PPC_FUNC_IMPL(__imp__sub_821770F0) {
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
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8217710C;
	sub_82130528(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_82177130"))) PPC_WEAK_FUNC(sub_82177130);
PPC_FUNC_IMPL(__imp__sub_82177130) {
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
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82177154
	if (cr6.eq) goto loc_82177154;
	// bl 0x82130588
	ctx.lr = 0x82177154;
	sub_82130588(ctx, base);
loc_82177154:
	// li r11,0
	r11.s64 = 0;
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

__attribute__((alias("__imp__sub_82177170"))) PPC_WEAK_FUNC(sub_82177170);
PPC_FUNC_IMPL(__imp__sub_82177170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82177184"))) PPC_WEAK_FUNC(sub_82177184);
PPC_FUNC_IMPL(__imp__sub_82177184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177188"))) PPC_WEAK_FUNC(sub_82177188);
PPC_FUNC_IMPL(__imp__sub_82177188) {
	PPC_FUNC_PROLOGUE();
	// lwz r4,20(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// addi r5,r4,16
	ctx.r5.s64 = ctx.r4.s64 + 16;
	// b 0x821712f0
	sub_821712F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177198"))) PPC_WEAK_FUNC(sub_82177198);
PPC_FUNC_IMPL(__imp__sub_82177198) {
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
	// bl 0x821789d8
	ctx.lr = 0x821771A8;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821771cc
	if (cr6.eq) goto loc_821771CC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r3,17004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821771CC:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r3,17012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17012);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821771E4"))) PPC_WEAK_FUNC(sub_821771E4);
PPC_FUNC_IMPL(__imp__sub_821771E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821771E8"))) PPC_WEAK_FUNC(sub_821771E8);
PPC_FUNC_IMPL(__imp__sub_821771E8) {
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
	// bl 0x821789d8
	ctx.lr = 0x821771F8;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217721c
	if (cr6.eq) goto loc_8217721C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r3,17008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8217721C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r3,17016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17016);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82177234"))) PPC_WEAK_FUNC(sub_82177234);
PPC_FUNC_IMPL(__imp__sub_82177234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177238"))) PPC_WEAK_FUNC(sub_82177238);
PPC_FUNC_IMPL(__imp__sub_82177238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-28908
	ctx.r10.s64 = r11.s64 + -28908;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177248"))) PPC_WEAK_FUNC(sub_82177248);
PPC_FUNC_IMPL(__imp__sub_82177248) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-28448
	ctx.r10.s64 = r11.s64 + -28448;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82177274
	if (cr6.eq) goto loc_82177274;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,1
	r11.s64 = 1;
	// stw r11,-9716(r10)
	PPC_STORE_U32(ctx.r10.u32 + -9716, r11.u32);
loc_82177274:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r11,-28268
	ctx.r10.s64 = r11.s64 + -28268;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82177294
	if (cr6.eq) goto loc_82177294;
	// bl 0x821861e8
	ctx.lr = 0x82177290;
	sub_821861E8(ctx, base);
	// b 0x82177298
	goto loc_82177298;
loc_82177294:
	// bl 0x82186110
	ctx.lr = 0x82177298;
	sub_82186110(ctx, base);
loc_82177298:
	// bl 0x82180a30
	ctx.lr = 0x8217729C;
	sub_82180A30(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r7,127
	ctx.r7.s64 = 127;
	// addi r3,r11,10696
	ctx.r3.s64 = r11.s64 + 10696;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8217f590
	ctx.lr = 0x821772B8;
	sub_8217F590(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// stw r3,-28532(r10)
	PPC_STORE_U32(ctx.r10.u32 + -28532, ctx.r3.u32);
	// stw r3,-25824(r9)
	PPC_STORE_U32(ctx.r9.u32 + -25824, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821772D8"))) PPC_WEAK_FUNC(sub_821772D8);
PPC_FUNC_IMPL(__imp__sub_821772D8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,30576
	ctx.r3.s64 = r11.s64 + 30576;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c9e10
	ctx.lr = 0x82177300;
	sub_821C9E10(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821863e0
	ctx.lr = 0x82177308;
	sub_821863E0(ctx, base);
	// lis r10,-256
	ctx.r10.s64 = -16777216;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stb r9,492(r31)
	PPC_STORE_U8(r31.u32 + 492, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_82177330"))) PPC_WEAK_FUNC(sub_82177330);
PPC_FUNC_IMPL(__imp__sub_82177330) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-28508
	ctx.r10.s64 = r11.s64 + -28508;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82177364
	if (cr6.eq) goto loc_82177364;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82177398
	goto loc_82177398;
loc_82177364:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-28528
	ctx.r10.s64 = r11.s64 + -28528;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82177380
	if (cr6.eq) goto loc_82177380;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82177398
	goto loc_82177398;
loc_82177380:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-28428
	ctx.r10.s64 = r11.s64 + -28428;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82177398
	if (cr6.eq) goto loc_82177398;
	// li r5,1
	ctx.r5.s64 = 1;
loc_82177398:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-28268
	ctx.r10.s64 = r11.s64 + -28268;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821773b8
	if (!cr6.eq) goto loc_821773B8;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x8217ac30
	ctx.lr = 0x821773B4;
	sub_8217AC30(ctx, base);
	// b 0x821773bc
	goto loc_821773BC;
loc_821773B8:
	// bl 0x8217d7b0
	ctx.lr = 0x821773BC;
	sub_8217D7B0(ctx, base);
loc_821773BC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_821773E8"))) PPC_WEAK_FUNC(sub_821773E8);
PPC_FUNC_IMPL(__imp__sub_821773E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-28268
	ctx.r10.s64 = r11.s64 + -28268;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82177400
	if (!cr6.eq) goto loc_82177400;
	// b 0x82179ea0
	sub_82179EA0(ctx, base);
	return;
loc_82177400:
	// b 0x8217d480
	sub_8217D480(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177404"))) PPC_WEAK_FUNC(sub_82177404);
PPC_FUNC_IMPL(__imp__sub_82177404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177408"))) PPC_WEAK_FUNC(sub_82177408);
PPC_FUNC_IMPL(__imp__sub_82177408) {
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
loc_82177414:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82177414
	if (cr6.eq) goto loc_82177414;
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f13,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// subf r7,r10,r11
	ctx.r7.s64 = r11.s64 - ctx.r10.s64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lfs f0,-29212(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29212);
	f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f12,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f12
	cr6.compare(ctx.f9.f64, ctx.f12.f64);
	// ble cr6,0x8217746c
	if (!cr6.gt) goto loc_8217746C;
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// b 0x82177488
	goto loc_82177488;
loc_8217746C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f12,-28916(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28916);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f0,-28920(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28920);
	f0.f64 = double(temp.f32);
	// fmadds f11,f13,f0,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// stfs f11,40(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
loc_82177488:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82177488
	if (cr6.eq) goto loc_82177488;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
loc_8217749C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8217749c
	if (cr6.eq) goto loc_8217749C;
	// std r11,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, r11.u64);
	// bl 0x82130000
	ctx.lr = 0x821774B4;
	sub_82130000(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821774C4"))) PPC_WEAK_FUNC(sub_821774C4);
PPC_FUNC_IMPL(__imp__sub_821774C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821774C8"))) PPC_WEAK_FUNC(sub_821774C8);
PPC_FUNC_IMPL(__imp__sub_821774C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
loc_821774C8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821774c8
	if (cr6.eq) goto loc_821774C8;
	// ld r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f13,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// subf r7,r10,r11
	ctx.r7.s64 = r11.s64 - ctx.r10.s64;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lfs f0,-29212(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29212);
	f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f12,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f12
	cr6.compare(ctx.f9.f64, ctx.f12.f64);
	// ble cr6,0x82177520
	if (!cr6.gt) goto loc_82177520;
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// blr 
	return;
loc_82177520:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f12,-28916(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28916);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f0,-28920(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28920);
	f0.f64 = double(temp.f32);
	// fmadds f11,f13,f0,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// stfs f11,32(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82177540"))) PPC_WEAK_FUNC(sub_82177540);
PPC_FUNC_IMPL(__imp__sub_82177540) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8217a068
	ctx.lr = 0x82177560;
	sub_8217A068(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821775ac
	if (cr6.eq) goto loc_821775AC;
	// lbz r11,492(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 492);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x821775ac
	if (cr6.eq) goto loc_821775AC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82178370
	ctx.lr = 0x82177598;
	sub_82178370(ctx, base);
	// lbz r10,492(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 492);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x821775ac
	if (!cr6.eq) goto loc_821775AC;
	// li r11,2
	r11.s64 = 2;
	// stb r11,492(r31)
	PPC_STORE_U8(r31.u32 + 492, r11.u8);
loc_821775AC:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821775ac
	if (cr6.eq) goto loc_821775AC;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
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

__attribute__((alias("__imp__sub_821775D8"))) PPC_WEAK_FUNC(sub_821775D8);
PPC_FUNC_IMPL(__imp__sub_821775D8) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_821775E4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821775e4
	if (cr6.eq) goto loc_821775E4;
	// ld r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f13,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// subf r7,r10,r11
	ctx.r7.s64 = r11.s64 - ctx.r10.s64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lfs f0,-29212(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29212);
	f0.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// lfs f11,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fsubs f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f8,f9
	ctx.f8.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f11
	cr6.compare(ctx.f8.f64, ctx.f11.f64);
	// ble cr6,0x8217763c
	if (!cr6.gt) goto loc_8217763C;
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// b 0x82177658
	goto loc_82177658;
loc_8217763C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f12,-28916(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28916);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f0,-28920(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28920);
	f0.f64 = double(temp.f32);
	// fmadds f10,f13,f0,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// stfs f10,36(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
loc_82177658:
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// lbz r8,492(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 492);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f11,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stb r11,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r11.u8);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stb r11,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r11.u8);
	// stb r11,118(r1)
	PPC_STORE_U8(ctx.r1.u32 + 118, r11.u8);
	// stb r10,119(r1)
	PPC_STORE_U8(ctx.r1.u32 + 119, ctx.r10.u8);
	// stb r10,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r10.u8);
	// bne cr6,0x8217769c
	if (!cr6.eq) goto loc_8217769C;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_8217769C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8217b7b0
	ctx.lr = 0x821776A4;
	sub_8217B7B0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821776B4"))) PPC_WEAK_FUNC(sub_821776B4);
PPC_FUNC_IMPL(__imp__sub_821776B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821776B8"))) PPC_WEAK_FUNC(sub_821776B8);
PPC_FUNC_IMPL(__imp__sub_821776B8) {
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
	// bl 0x821863c0
	ctx.lr = 0x821776C8;
	sub_821863C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821776ec
	if (cr6.eq) goto loc_821776EC;
	// bl 0x821863d0
	ctx.lr = 0x821776D8;
	sub_821863D0(ctx, base);
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
loc_821776EC:
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

__attribute__((alias("__imp__sub_82177700"))) PPC_WEAK_FUNC(sub_82177700);
PPC_FUNC_IMPL(__imp__sub_82177700) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-28908
	ctx.r10.s64 = r11.s64 + -28908;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82177724:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82177724
	if (cr6.eq) goto loc_82177724;
	// std r11,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r11.u64);
loc_82177738:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82177738
	if (cr6.eq) goto loc_82177738;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_8217774C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8217774c
	if (cr6.eq) goto loc_8217774C;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
loc_82177760:
	// mftb r10
	ctx.r10.u64 = __rdtsc();
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82177760
	if (cr6.eq) goto loc_82177760;
	// std r10,72(r31)
	PPC_STORE_U64(r31.u32 + 72, ctx.r10.u64);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lbz r8,493(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 493);
	// li r11,0
	r11.s64 = 0;
	// addi r7,r10,-28328
	ctx.r7.s64 = ctx.r10.s64 + -28328;
	// stb r11,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r11.u8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stb r11,50(r31)
	PPC_STORE_U8(r31.u32 + 50, r11.u8);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r30,r5,-28856
	r30.s64 = ctx.r5.s64 + -28856;
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cntlzw r4,r10
	ctx.r4.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// clrlwi r10,r8,26
	ctx.r10.u64 = ctx.r8.u32 & 0x3F;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// xori r8,r3,1
	ctx.r8.u64 = ctx.r3.u64 ^ 1;
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stb r10,493(r31)
	PPC_STORE_U8(r31.u32 + 493, ctx.r10.u8);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stb r8,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r8.u8);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stb r9,58(r31)
	PPC_STORE_U8(r31.u32 + 58, ctx.r9.u8);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// stw r9,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r9.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r9,-28856(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + -28856);
	// addi r10,r7,-28368
	ctx.r10.s64 = ctx.r7.s64 + -28368;
	// stw r9,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r9.u32);
	// addi r3,r8,-28868
	ctx.r3.s64 = ctx.r8.s64 + -28868;
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r7,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r7.u32);
	// addi r4,r31,428
	ctx.r4.s64 = r31.s64 + 428;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r9,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r9.u32);
	// lhz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// sth r8,104(r31)
	PPC_STORE_U16(r31.u32 + 104, ctx.r8.u16);
	// stb r11,56(r31)
	PPC_STORE_U8(r31.u32 + 56, r11.u8);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stfs f0,360(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 360, temp.u32);
	// stfs f0,356(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 356, temp.u32);
	// xori r10,r11,1
	ctx.r10.u64 = r11.u64 ^ 1;
	// stfs f0,352(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// stb r10,348(r31)
	PPC_STORE_U8(r31.u32 + 348, ctx.r10.u8);
	// ld r11,12540(r6)
	r11.u64 = PPC_LOAD_U64(ctx.r6.u32 + 12540);
	// std r11,364(r31)
	PPC_STORE_U64(r31.u32 + 364, r11.u64);
	// ld r11,12540(r6)
	r11.u64 = PPC_LOAD_U64(ctx.r6.u32 + 12540);
	// std r11,428(r31)
	PPC_STORE_U64(r31.u32 + 428, r11.u64);
	// bl 0x821a5cc0
	ctx.lr = 0x8217784C;
	sub_821A5CC0(ctx, base);
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

__attribute__((alias("__imp__sub_82177868"))) PPC_WEAK_FUNC(sub_82177868);
PPC_FUNC_IMPL(__imp__sub_82177868) {
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
	// addi r10,r11,-28908
	ctx.r10.s64 = r11.s64 + -28908;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82177894;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821778ac
	if (cr6.eq) goto loc_821778AC;
	// bl 0x82130588
	ctx.lr = 0x821778A8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821778AC:
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

__attribute__((alias("__imp__sub_821778C4"))) PPC_WEAK_FUNC(sub_821778C4);
PPC_FUNC_IMPL(__imp__sub_821778C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821778C8"))) PPC_WEAK_FUNC(sub_821778C8);
PPC_FUNC_IMPL(__imp__sub_821778C8) {
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
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lwz r31,-28532(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -28532);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821778fc
	if (cr6.eq) goto loc_821778FC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217eeb0
	ctx.lr = 0x821778F4;
	sub_8217EEB0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821778FC;
	sub_82130588(ctx, base);
loc_821778FC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-28532(r30)
	PPC_STORE_U32(r30.u32 + -28532, r11.u32);
	// bl 0x82181d58
	ctx.lr = 0x82177908;
	sub_82181D58(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8217792c
	if (cr6.eq) goto loc_8217792C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217792C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8217792C:
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

__attribute__((alias("__imp__sub_82177944"))) PPC_WEAK_FUNC(sub_82177944);
PPC_FUNC_IMPL(__imp__sub_82177944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177948"))) PPC_WEAK_FUNC(sub_82177948);
PPC_FUNC_IMPL(__imp__sub_82177948) {
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
	// bl 0x82177248
	ctx.lr = 0x82177958;
	sub_82177248(ctx, base);
	// bl 0x821883e0
	ctx.lr = 0x8217795C;
	sub_821883E0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821879d8
	ctx.lr = 0x82177964;
	sub_821879D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82186460
	ctx.lr = 0x8217796C;
	sub_82186460(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217797C"))) PPC_WEAK_FUNC(sub_8217797C);
PPC_FUNC_IMPL(__imp__sub_8217797C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177980"))) PPC_WEAK_FUNC(sub_82177980);
PPC_FUNC_IMPL(__imp__sub_82177980) {
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
	// bl 0x82189988
	ctx.lr = 0x82177998;
	sub_82189988(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-24780(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24780);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821779bc
	if (cr6.eq) goto loc_821779BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821779BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821779BC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821779e0
	if (cr6.eq) goto loc_821779E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821779E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821779E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821778c8
	ctx.lr = 0x821779E8;
	sub_821778C8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821779FC"))) PPC_WEAK_FUNC(sub_821779FC);
PPC_FUNC_IMPL(__imp__sub_821779FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177A00"))) PPC_WEAK_FUNC(sub_82177A00);
PPC_FUNC_IMPL(__imp__sub_82177A00) {
	PPC_FUNC_PROLOGUE();
	// b 0x82177408
	sub_82177408(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177A04"))) PPC_WEAK_FUNC(sub_82177A04);
PPC_FUNC_IMPL(__imp__sub_82177A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177A08"))) PPC_WEAK_FUNC(sub_82177A08);
PPC_FUNC_IMPL(__imp__sub_82177A08) {
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
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82177A24;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82177a50
	if (!cr6.eq) goto loc_82177A50;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82177a4c
	if (cr6.eq) goto loc_82177A4C;
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
	ctx.lr = 0x82177A4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82177A4C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82177A50:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82177A64"))) PPC_WEAK_FUNC(sub_82177A64);
PPC_FUNC_IMPL(__imp__sub_82177A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177A68"))) PPC_WEAK_FUNC(sub_82177A68);
PPC_FUNC_IMPL(__imp__sub_82177A68) {
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
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824221d8
	ctx.lr = 0x82177A88;
	sub_824221D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x82177aa4
	if (!cr6.eq) goto loc_82177AA4;
	// bl 0x821bbea8
	ctx.lr = 0x82177A98;
	sub_821BBEA8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82177AA0;
	sub_82130588(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x82177AA4;
	sub_821BBF00(ctx, base);
loc_82177AA4:
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

__attribute__((alias("__imp__sub_82177AC0"))) PPC_WEAK_FUNC(sub_82177AC0);
PPC_FUNC_IMPL(__imp__sub_82177AC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82422160
	sub_82422160(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177AC8"))) PPC_WEAK_FUNC(sub_82177AC8);
PPC_FUNC_IMPL(__imp__sub_82177AC8) {
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
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82177afc
	if (cr6.eq) goto loc_82177AFC;
	// lis r11,6690
	r11.s64 = 438435840;
	// lis r31,11552
	r31.s64 = 757071872;
	// ori r11,r11,407
	r11.u64 = r11.u64 | 407;
	// ori r31,r31,406
	r31.u64 = r31.u64 | 406;
	// b 0x82177b0c
	goto loc_82177B0C;
loc_82177AFC:
	// lis r11,11552
	r11.s64 = 757071872;
	// lis r31,6690
	r31.s64 = 438435840;
	// ori r11,r11,406
	r11.u64 = r11.u64 | 406;
	// ori r31,r31,407
	r31.u64 = r31.u64 | 407;
loc_82177B0C:
	// stw r11,17068(r10)
	PPC_STORE_U32(ctx.r10.u32 + 17068, r11.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217fed0
	ctx.lr = 0x82177B18;
	sub_8217FED0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217f768
	ctx.lr = 0x82177B24;
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

__attribute__((alias("__imp__sub_82177B3C"))) PPC_WEAK_FUNC(sub_82177B3C);
PPC_FUNC_IMPL(__imp__sub_82177B3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177B40"))) PPC_WEAK_FUNC(sub_82177B40);
PPC_FUNC_IMPL(__imp__sub_82177B40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,6690
	r11.s64 = 438435840;
	// ori r11,r11,407
	r11.u64 = r11.u64 | 407;
	// subf r10,r3,r11
	ctx.r10.s64 = r11.s64 - ctx.r3.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82177B58"))) PPC_WEAK_FUNC(sub_82177B58);
PPC_FUNC_IMPL(__imp__sub_82177B58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// ori r9,r10,407
	ctx.r9.u64 = ctx.r10.u64 | 407;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 - ctx.f1.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82177B80"))) PPC_WEAK_FUNC(sub_82177B80);
PPC_FUNC_IMPL(__imp__sub_82177B80) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82415d78
	ctx.lr = 0x82177B9C;
	sub_82415D78(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// ori r9,r10,407
	ctx.r9.u64 = ctx.r10.u64 | 407;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82177bd4
	if (!cr6.eq) goto loc_82177BD4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsubs f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 - ctx.f12.f64));
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_82177BD4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82416540
	ctx.lr = 0x82177BE0;
	sub_82416540(ctx, base);
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

__attribute__((alias("__imp__sub_82177BF4"))) PPC_WEAK_FUNC(sub_82177BF4);
PPC_FUNC_IMPL(__imp__sub_82177BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177BF8"))) PPC_WEAK_FUNC(sub_82177BF8);
PPC_FUNC_IMPL(__imp__sub_82177BF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// addi r4,r8,-27772
	ctx.r4.s64 = ctx.r8.s64 + -27772;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// subfic r3,r10,95
	xer.ca = ctx.r10.u32 <= 95;
	ctx.r3.s64 = 95 - ctx.r10.s64;
	// mulli r8,r3,21846
	ctx.r8.s64 = ctx.r3.s64 * 21846;
	// stwx r9,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r9.u32);
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// rlwinm r11,r8,16,16,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r11,32
	ctx.r4.s64 = r11.s64 + 32;
	// rldicr r11,r7,63,63
	r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// clrldi r8,r4,32
	ctx.r8.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// srd r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r8.u8 & 0x7F));
	// lwz r5,28(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// b 0x82415dc8
	sub_82415DC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177C4C"))) PPC_WEAK_FUNC(sub_82177C4C);
PPC_FUNC_IMPL(__imp__sub_82177C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177C50"))) PPC_WEAK_FUNC(sub_82177C50);
PPC_FUNC_IMPL(__imp__sub_82177C50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// subfic r5,r10,95
	xer.ca = ctx.r10.u32 <= 95;
	ctx.r5.s64 = 95 - ctx.r10.s64;
	// addi r7,r9,-27772
	ctx.r7.s64 = ctx.r9.s64 + -27772;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r11,r5,21846
	r11.s64 = ctx.r5.s64 * 21846;
	// lis r4,-32124
	ctx.r4.s64 = -2105278464;
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r11,r11,16,16,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// stwx r6,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r6.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,32
	ctx.r8.s64 = r11.s64 + 32;
	// lwz r3,-28076(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -28076);
	// rldicr r4,r9,63,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// clrldi r11,r8,32
	r11.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// li r7,0
	ctx.r7.s64 = 0;
	// srd r8,r4,r11
	ctx.r8.u64 = r11.u8 & 0x40 ? 0 : (ctx.r4.u64 >> (r11.u8 & 0x7F));
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// b 0x82415dc8
	sub_82415DC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177CA0"))) PPC_WEAK_FUNC(sub_82177CA0);
PPC_FUNC_IMPL(__imp__sub_82177CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x82415ee8
	sub_82415EE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177CB0"))) PPC_WEAK_FUNC(sub_82177CB0);
PPC_FUNC_IMPL(__imp__sub_82177CB0) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82177d7c
	if (cr6.eq) goto loc_82177D7C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82177d70
	if (!cr6.eq) goto loc_82177D70;
	// bl 0x82412178
	ctx.lr = 0x82177CE4;
	sub_82412178(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// blt cr6,0x82177d48
	if (cr6.lt) goto loc_82177D48;
	// beq cr6,0x82177d28
	if (cr6.eq) goto loc_82177D28;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bge cr6,0x82177d64
	if (!cr6.lt) goto loc_82177D64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// clrlwi r9,r10,20
	ctx.r9.u64 = ctx.r10.u32 & 0xFFF;
	// stw r9,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r9.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// clrlwi r7,r8,20
	ctx.r7.u64 = ctx.r8.u32 & 0xFFF;
	// stw r7,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r7.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82177D24;
	sub_82130588(ctx, base);
	// b 0x82177d74
	goto loc_82177D74;
loc_82177D28:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lis r4,-17280
	ctx.r4.s64 = -1132462080;
	// ori r4,r4,16384
	ctx.r4.u64 = ctx.r4.u64 | 16384;
	// rlwinm r3,r11,0,0,19
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// bl 0x821310f8
	ctx.lr = 0x82177D3C;
	sub_821310F8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82177D44;
	sub_82130588(ctx, base);
	// b 0x82177d74
	goto loc_82177D74;
loc_82177D48:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// rlwinm r3,r11,0,0,19
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// bl 0x821bc0b8
	ctx.lr = 0x82177D54;
	sub_821BC0B8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// rlwinm r3,r9,0,0,19
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFF000;
	// bl 0x821bc0b8
	ctx.lr = 0x82177D64;
	sub_821BC0B8(ctx, base);
loc_82177D64:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82177D6C;
	sub_82130588(ctx, base);
	// b 0x82177d74
	goto loc_82177D74;
loc_82177D70:
	// bl 0x824221d8
	ctx.lr = 0x82177D74;
	sub_824221D8(ctx, base);
loc_82177D74:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82177D7C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82177D90"))) PPC_WEAK_FUNC(sub_82177D90);
PPC_FUNC_IMPL(__imp__sub_82177D90) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82177dbc
	if (cr6.eq) goto loc_82177DBC;
	// bl 0x824221d8
	ctx.lr = 0x82177DB4;
	sub_824221D8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82177DBC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82177DD0"))) PPC_WEAK_FUNC(sub_82177DD0);
PPC_FUNC_IMPL(__imp__sub_82177DD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-28076(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82177DEC"))) PPC_WEAK_FUNC(sub_82177DEC);
PPC_FUNC_IMPL(__imp__sub_82177DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177DF0"))) PPC_WEAK_FUNC(sub_82177DF0);
PPC_FUNC_IMPL(__imp__sub_82177DF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-28076(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + r11.u64;
	// lwz r8,468(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 468);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82177E10"))) PPC_WEAK_FUNC(sub_82177E10);
PPC_FUNC_IMPL(__imp__sub_82177E10) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82415fc0
	ctx.lr = 0x82177E30;
	sub_82415FC0(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82177E48"))) PPC_WEAK_FUNC(sub_82177E48);
PPC_FUNC_IMPL(__imp__sub_82177E48) {
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
	// lis r31,-32124
	r31.s64 = -2105278464;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x824169d0
	ctx.lr = 0x82177E68;
	sub_824169D0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82415f78
	ctx.lr = 0x82177E74;
	sub_82415F78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82177e98
	if (!cr6.eq) goto loc_82177E98;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82177b80
	ctx.lr = 0x82177E84;
	sub_82177B80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82177E98:
	// bl 0x824221d8
	ctx.lr = 0x82177E9C;
	sub_824221D8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82177EB0"))) PPC_WEAK_FUNC(sub_82177EB0);
PPC_FUNC_IMPL(__imp__sub_82177EB0) {
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
	ctx.lr = 0x82177EB8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,68(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82177EF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8217805c
	if (cr6.eq) goto loc_8217805C;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// li r3,52
	ctx.r3.s64 = 52;
	// bne cr6,0x82177f58
	if (!cr6.eq) goto loc_82177F58;
	// bl 0x82130528
	ctx.lr = 0x82177F18;
	sub_82130528(ctx, base);
	// lwz r26,308(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r1,132
	r11.s64 = ctx.r1.s64 + 132;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82430a20
	ctx.lr = 0x82177F54;
	sub_82430A20(ctx, base);
	// b 0x82177ff4
	goto loc_82177FF4;
loc_82177F58:
	// cmpwi cr6,r24,3
	cr6.compare<int32_t>(r24.s32, 3, xer);
	// bne cr6,0x82177fac
	if (!cr6.eq) goto loc_82177FAC;
	// bl 0x82130528
	ctx.lr = 0x82177F64;
	sub_82130528(ctx, base);
	// lwz r26,308(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r11,r1,132
	r11.s64 = ctx.r1.s64 + 132;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82430b08
	ctx.lr = 0x82177FA8;
	sub_82430B08(ctx, base);
	// b 0x82177ff4
	goto loc_82177FF4;
loc_82177FAC:
	// bl 0x82130528
	ctx.lr = 0x82177FB0;
	sub_82130528(ctx, base);
	// lwz r26,308(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r11,r1,132
	r11.s64 = ctx.r1.s64 + 132;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82430938
	ctx.lr = 0x82177FF4;
	sub_82430938(ctx, base);
loc_82177FF4:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// oris r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 2097152;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x821bc028
	ctx.lr = 0x82178010;
	sub_821BC028(ctx, base);
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82178030
	if (cr6.eq) goto loc_82178030;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821bc028
	ctx.lr = 0x8217802C;
	sub_821BC028(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_82178030:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// rlwimi r10,r31,0,0,19
	ctx.r10.u64 = (__builtin_rotateleft32(r31.u32, 0) & 0xFFFFF000) | (ctx.r10.u64 & 0xFFFFFFFF00000FFF);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// rlwimi r9,r28,0,0,19
	ctx.r9.u64 = (__builtin_rotateleft32(r28.u32, 0) & 0xFFFFF000) | (ctx.r9.u64 & 0xFFFFFFFF00000FFF);
	// stw r9,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
loc_8217805C:
	// cmplwi cr6,r28,1
	cr6.compare<uint32_t>(r28.u32, 1, xer);
	// bne cr6,0x821781d8
	if (!cr6.eq) goto loc_821781D8;
	// lis r23,-32124
	r23.s64 = -2105278464;
	// lwz r11,-24876(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -24876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217807c
	if (!cr6.eq) goto loc_8217807C;
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// beq cr6,0x821781d8
	if (cr6.eq) goto loc_821781D8;
loc_8217807C:
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// li r3,52
	ctx.r3.s64 = 52;
	// beq cr6,0x82178130
	if (cr6.eq) goto loc_82178130;
	// cmpwi cr6,r24,3
	cr6.compare<int32_t>(r24.s32, 3, xer);
	// beq cr6,0x821780e0
	if (cr6.eq) goto loc_821780E0;
	// bl 0x82130528
	ctx.lr = 0x82178094;
	sub_82130528(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r26,308(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824309a8
	ctx.lr = 0x821780DC;
	sub_824309A8(ctx, base);
	// b 0x82178170
	goto loc_82178170;
loc_821780E0:
	// bl 0x82130528
	ctx.lr = 0x821780E4;
	sub_82130528(ctx, base);
	// lwz r26,308(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r28,0
	r28.s64 = 0;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r11,-1
	r11.s64 = -1;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82430b68
	ctx.lr = 0x8217812C;
	sub_82430B68(ctx, base);
	// b 0x82178170
	goto loc_82178170;
loc_82178130:
	// bl 0x82130528
	ctx.lr = 0x82178134;
	sub_82130528(ctx, base);
	// lwz r26,308(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r28,0
	r28.s64 = 0;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82430a90
	ctx.lr = 0x82178170;
	sub_82430A90(ctx, base);
loc_82178170:
	// lwz r11,-24876(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -24876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217818c
	if (cr6.eq) goto loc_8217818C;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// bl 0x82183748
	ctx.lr = 0x82178184;
	sub_82183748(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x8217819c
	goto loc_8217819C;
loc_8217818C:
	// lis r4,-17280
	ctx.r4.s64 = -1132462080;
	// ori r4,r4,16384
	ctx.r4.u64 = ctx.r4.u64 | 16384;
	// bl 0x82130b50
	ctx.lr = 0x82178198;
	sub_82130B50(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
loc_8217819C:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82430c38
	ctx.lr = 0x821781B4;
	sub_82430C38(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821781c8
	if (cr6.eq) goto loc_821781C8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
loc_821781C8:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
loc_821781D8:
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bne cr6,0x82178220
	if (!cr6.eq) goto loc_82178220;
	// li r10,18
	ctx.r10.s64 = 18;
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82410c50
	ctx.lr = 0x82178204;
	sub_82410C50(ctx, base);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// beq cr6,0x821781c8
	if (cr6.eq) goto loc_821781C8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
loc_82178220:
	// cmpwi cr6,r24,3
	cr6.compare<int32_t>(r24.s32, 3, xer);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x82178258
	if (!cr6.eq) goto loc_82178258;
	// li r10,17
	ctx.r10.s64 = 17;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x82410c50
	ctx.lr = 0x8217823C;
	sub_82410C50(ctx, base);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// beq cr6,0x821781c8
	if (cr6.eq) goto loc_821781C8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
loc_82178258:
	// li r10,3
	ctx.r10.s64 = 3;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82410c50
	ctx.lr = 0x82178264;
	sub_82410C50(ctx, base);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// beq cr6,0x821782dc
	if (cr6.eq) goto loc_821782DC;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r11,r11,20,12,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// rlwinm r31,r10,20,12,31
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821782ac
	if (cr6.eq) goto loc_821782AC;
	// rlwinm r29,r11,12,0,19
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82132600
	ctx.lr = 0x8217829C;
	sub_82132600(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x821782AC;
	sub_823D9890(ctx, base);
loc_821782AC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821782d0
	if (cr6.eq) goto loc_821782D0;
	// rlwinm r31,r31,12,0,19
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 12) & 0xFFFFF000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82132600
	ctx.lr = 0x821782C0;
	sub_82132600(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x821782D0;
	sub_823D9890(ctx, base);
loc_821782D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
loc_821782DC:
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821782F0"))) PPC_WEAK_FUNC(sub_821782F0);
PPC_FUNC_IMPL(__imp__sub_821782F0) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82415f78
	ctx.lr = 0x82178314;
	sub_82415F78(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8217832C"))) PPC_WEAK_FUNC(sub_8217832C);
PPC_FUNC_IMPL(__imp__sub_8217832C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178330"))) PPC_WEAK_FUNC(sub_82178330);
PPC_FUNC_IMPL(__imp__sub_82178330) {
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
	// lis r31,-32124
	r31.s64 = -2105278464;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82416ca8
	ctx.lr = 0x82178354;
	sub_82416CA8(ctx, base);
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82177b80
	ctx.lr = 0x8217835C;
	sub_82177B80(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82178370"))) PPC_WEAK_FUNC(sub_82178370);
PPC_FUNC_IMPL(__imp__sub_82178370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// subfic r8,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r8.s64 = 0 - r11.s64;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r5,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r10.s64;
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// subfe r11,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r10,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r7.s64;
	// lis r3,-32131
	ctx.r3.s64 = -2105737216;
	// rlwimi r6,r11,0,27,27
	ctx.r6.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x10) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFEF);
	// subfe r8,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// lis r7,6690
	ctx.r7.s64 = 438435840;
	// rlwimi r6,r8,0,26,26
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0x20) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFDF);
	// lwz r11,17068(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 17068);
	// ori r5,r7,407
	ctx.r5.u64 = ctx.r7.u64 | 407;
	// clrlwi r6,r6,26
	ctx.r6.u64 = ctx.r6.u32 & 0x3F;
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// bne cr6,0x821783c8
	if (!cr6.eq) goto loc_821783C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 - ctx.f1.f64));
loc_821783C8:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x824195e8
	sub_824195E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821783E4"))) PPC_WEAK_FUNC(sub_821783E4);
PPC_FUNC_IMPL(__imp__sub_821783E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821783E8"))) PPC_WEAK_FUNC(sub_821783E8);
PPC_FUNC_IMPL(__imp__sub_821783E8) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824221d8
	ctx.lr = 0x82178404;
	sub_824221D8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8217841c
	if (!cr6.eq) goto loc_8217841C;
	// bl 0x821bbea8
	ctx.lr = 0x82178410;
	sub_821BBEA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82178418;
	sub_82130588(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x8217841C;
	sub_821BBF00(ctx, base);
loc_8217841C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82178430"))) PPC_WEAK_FUNC(sub_82178430);
PPC_FUNC_IMPL(__imp__sub_82178430) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82178468
	if (cr6.eq) goto loc_82178468;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r10,-27736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -27736);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x82178468
	if (cr6.eq) goto loc_82178468;
	// stw r3,-27736(r11)
	PPC_STORE_U32(r11.u32 + -27736, ctx.r3.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82417e88
	ctx.lr = 0x82178468;
	sub_82417E88(ctx, base);
loc_82178468:
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

__attribute__((alias("__imp__sub_8217847C"))) PPC_WEAK_FUNC(sub_8217847C);
PPC_FUNC_IMPL(__imp__sub_8217847C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178480"))) PPC_WEAK_FUNC(sub_82178480);
PPC_FUNC_IMPL(__imp__sub_82178480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r8,r10,17228
	ctx.r8.s64 = ctx.r10.s64 + 17228;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// b 0x8241cd88
	sub_8241CD88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821784A4"))) PPC_WEAK_FUNC(sub_821784A4);
PPC_FUNC_IMPL(__imp__sub_821784A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821784A8"))) PPC_WEAK_FUNC(sub_821784A8);
PPC_FUNC_IMPL(__imp__sub_821784A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x8241d220
	sub_8241D220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821784B4"))) PPC_WEAK_FUNC(sub_821784B4);
PPC_FUNC_IMPL(__imp__sub_821784B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821784B8"))) PPC_WEAK_FUNC(sub_821784B8);
PPC_FUNC_IMPL(__imp__sub_821784B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x821784C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r30,r31,-28224
	r30.s64 = r31.s64 + -28224;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-28224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28224);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r8,64(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82410c50
	ctx.lr = 0x821784F0;
	sub_82410C50(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lwz r8,64(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r3,-28224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28224);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,-27732(r29)
	PPC_STORE_U32(r29.u32 + -27732, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r29,r29,-27732
	r29.s64 = r29.s64 + -27732;
	// bl 0x82410c50
	ctx.lr = 0x82178524;
	sub_82410C50(ctx, base);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,16(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r5,40(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,-28224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28224);
	// bl 0x82410d70
	ctx.lr = 0x82178540;
	sub_82410D70(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r6,16(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,-28224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28224);
	// stw r11,-27812(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27812, r11.u32);
	// bl 0x82410d70
	ctx.lr = 0x82178564;
	sub_82410D70(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lbz r7,528(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 528);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// subfic r6,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r7.s64;
	// stw r3,-28080(r9)
	PPC_STORE_U32(ctx.r9.u32 + -28080, ctx.r3.u32);
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// lwz r3,-28076(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -28076);
	// rlwinm r11,r5,0,25,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x7C;
	// rlwinm r11,r11,0,27,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x82415238
	ctx.lr = 0x82178590;
	sub_82415238(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82178598"))) PPC_WEAK_FUNC(sub_82178598);
PPC_FUNC_IMPL(__imp__sub_82178598) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// addi r7,r9,17152
	ctx.r7.s64 = ctx.r9.s64 + 17152;
	// addi r31,r8,-27796
	r31.s64 = ctx.r8.s64 + -27796;
	// rlwinm r11,r3,10,0,21
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 10) & 0xFFFFFC00;
	// rlwinm r10,r4,10,0,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 10) & 0xFFFFFC00;
	// stb r6,-27796(r8)
	PPC_STORE_U8(ctx.r8.u32 + -27796, ctx.r6.u8);
	// stw r11,-4(r7)
	PPC_STORE_U32(ctx.r7.u32 + -4, r11.u32);
	// stw r10,17152(r9)
	PPC_STORE_U32(ctx.r9.u32 + 17152, ctx.r10.u32);
	// stw r5,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, ctx.r5.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821785CC"))) PPC_WEAK_FUNC(sub_821785CC);
PPC_FUNC_IMPL(__imp__sub_821785CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821785D0"))) PPC_WEAK_FUNC(sub_821785D0);
PPC_FUNC_IMPL(__imp__sub_821785D0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x821785D8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r27,-32131
	r27.s64 = -2105737216;
	// addi r10,r11,-27192
	ctx.r10.s64 = r11.s64 + -27192;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82178600
	if (cr6.eq) goto loc_82178600;
	// lis r11,6690
	r11.s64 = 438435840;
	// ori r11,r11,407
	r11.u64 = r11.u64 | 407;
	// stw r11,17068(r27)
	PPC_STORE_U32(r27.u32 + 17068, r11.u32);
loc_82178600:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,124
	ctx.r5.s64 = 124;
	// addi r31,r11,-28224
	r31.s64 = r11.s64 + -28224;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x82178618;
	sub_823D9890(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-27436
	ctx.r3.s64 = r11.s64 + -27436;
	// bl 0x821c0750
	ctx.lr = 0x82178630;
	sub_821C0750(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r7,r10,-27316
	ctx.r7.s64 = ctx.r10.s64 + -27316;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r30,17004(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17004);
	// lwz r29,17008(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17008);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// beq cr6,0x82178668
	if (cr6.eq) goto loc_82178668;
	// lis r11,6690
	r11.s64 = 438435840;
	// ori r11,r11,447
	r11.u64 = r11.u64 | 447;
	// b 0x8217868c
	goto loc_8217868C;
loc_82178668:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-25064
	ctx.r10.s64 = r11.s64 + -25064;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,6184
	r11.s64 = 405274624;
	// beq cr6,0x82178688
	if (cr6.eq) goto loc_82178688;
	// ori r11,r11,32646
	r11.u64 = r11.u64 | 32646;
	// b 0x8217868c
	goto loc_8217868C;
loc_82178688:
	// ori r11,r11,390
	r11.u64 = r11.u64 | 390;
loc_8217868C:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lis r11,10280
	r11.s64 = 673710080;
	// ori r11,r11,262
	r11.u64 = r11.u64 | 262;
	// lbz r9,17024(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 17024);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821786d4
	if (!cr6.eq) goto loc_821786D4;
	// lwz r9,500(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 500);
	// mr r11,r28
	r11.u64 = r28.u64;
	// lwz r8,484(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 484);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stw r29,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r29.u32);
	// stw r9,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r9.u32);
	// stw r8,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r8.u32);
loc_821786D4:
	// li r6,1
	ctx.r6.s64 = 1;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r10,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r10.u32);
	// lwz r11,17020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17020);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82178704
	if (cr6.eq) goto loc_82178704;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// slw r11,r6,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r6.u32 << (r11.u8 & 0x3F));
	// b 0x82178708
	goto loc_82178708;
loc_82178704:
	// lis r11,-32768
	r11.s64 = -2147483648;
loc_82178708:
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// extsw r11,r30
	r11.s64 = r30.s32;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// extsw r9,r29
	ctx.r9.s64 = r29.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lbz r11,2745(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2745);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r7,17260
	ctx.r3.s64 = ctx.r7.s64 + 17260;
	// lwz r5,17068(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 17068);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r9,r11,17152
	ctx.r9.s64 = r11.s64 + 17152;
	// lwzx r11,r4,r3
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	// cntlzw r4,r10
	ctx.r4.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// lwz r10,-4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// lis r27,-32122
	r27.s64 = -2105147392;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lfs f0,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// lis r25,-32122
	r25.s64 = -2105147392;
	// stw r30,2760(r4)
	PPC_STORE_U32(ctx.r4.u32 + 2760, r30.u32);
	// xori r7,r3,1
	ctx.r7.u64 = ctx.r3.u64 ^ 1;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r7,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r7.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// fdivs f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 / ctx.f10.f64));
	// fdivs f0,f0,f9
	f0.f64 = double(float(f0.f64 / ctx.f9.f64));
	// stfs f13,2764(r25)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r25.u32 + 2764, temp.u32);
	// stfs f0,2756(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 2756, temp.u32);
	// stw r4,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r4.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// stw r29,2736(r5)
	PPC_STORE_U32(ctx.r5.u32 + 2736, r29.u32);
	// stw r11,-27556(r26)
	PPC_STORE_U32(r26.u32 + -27556, r11.u32);
	// beq cr6,0x8217883c
	if (cr6.eq) goto loc_8217883C;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8217883c
	if (cr6.eq) goto loc_8217883C;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r8,420(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// addi r9,r31,72
	ctx.r9.s64 = r31.s64 + 72;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r7,6
	ctx.r7.s64 = 6;
	// std r28,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, r28.u64);
	// std r28,8(r5)
	PPC_STORE_U64(ctx.r5.u32 + 8, r28.u64);
	// std r28,16(r5)
	PPC_STORE_U64(ctx.r5.u32 + 16, r28.u64);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82178828:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82178828
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82178828;
loc_8217883C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82178844"))) PPC_WEAK_FUNC(sub_82178844);
PPC_FUNC_IMPL(__imp__sub_82178844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178848"))) PPC_WEAK_FUNC(sub_82178848);
PPC_FUNC_IMPL(__imp__sub_82178848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bcd84
	ctx.lr = 0x8217885C;
	__imp__XGetVideoMode(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217887C"))) PPC_WEAK_FUNC(sub_8217887C);
PPC_FUNC_IMPL(__imp__sub_8217887C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178880"))) PPC_WEAK_FUNC(sub_82178880);
PPC_FUNC_IMPL(__imp__sub_82178880) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bcd84
	ctx.lr = 0x82178894;
	__imp__XGetVideoMode(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821788B4"))) PPC_WEAK_FUNC(sub_821788B4);
PPC_FUNC_IMPL(__imp__sub_821788B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821788B8"))) PPC_WEAK_FUNC(sub_821788B8);
PPC_FUNC_IMPL(__imp__sub_821788B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// beq cr6,0x821788e8
	if (cr6.eq) goto loc_821788E8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-27800
	ctx.r10.s64 = r11.s64 + -27800;
	// beq cr6,0x821788e0
	if (cr6.eq) goto loc_821788E0;
	// lwz r4,88(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// b 0x82178904
	goto loc_82178904;
loc_821788E0:
	// lwz r4,52(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// b 0x82178904
	goto loc_82178904;
loc_821788E8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// beq cr6,0x82178900
	if (cr6.eq) goto loc_82178900;
	// addi r10,r11,-27800
	ctx.r10.s64 = r11.s64 + -27800;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x82178904
	goto loc_82178904;
loc_82178900:
	// lwz r4,-27800(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27800);
loc_82178904:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-27296
	ctx.r3.s64 = r11.s64 + -27296;
	// b 0x8218baa0
	sub_8218BAA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178910"))) PPC_WEAK_FUNC(sub_82178910);
PPC_FUNC_IMPL(__imp__sub_82178910) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stb r3,17024(r11)
	PPC_STORE_U8(r11.u32 + 17024, ctx.r3.u8);
	// bl 0x821785d0
	ctx.lr = 0x82178928;
	sub_821785D0(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r4,r9,-28224
	ctx.r4.s64 = ctx.r9.s64 + -28224;
	// lwz r3,-28076(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// bl 0x82413270
	ctx.lr = 0x8217893C;
	sub_82413270(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217894C"))) PPC_WEAK_FUNC(sub_8217894C);
PPC_FUNC_IMPL(__imp__sub_8217894C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178950"))) PPC_WEAK_FUNC(sub_82178950);
PPC_FUNC_IMPL(__imp__sub_82178950) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82413330
	ctx.lr = 0x82178968;
	sub_82413330(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r3,-27744(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27744);
	// bl 0x82413330
	ctx.lr = 0x82178974;
	sub_82413330(ctx, base);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,17164(r9)
	PPC_STORE_U32(ctx.r9.u32 + 17164, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82178990"))) PPC_WEAK_FUNC(sub_82178990);
PPC_FUNC_IMPL(__imp__sub_82178990) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x824132f0
	ctx.lr = 0x821789A8;
	sub_824132F0(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r3,-27744(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27744);
	// bl 0x824132f0
	ctx.lr = 0x821789B4;
	sub_824132F0(ctx, base);
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,56
	ctx.r8.s64 = 56;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r11,17164(r7)
	PPC_STORE_U32(ctx.r7.u32 + 17164, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821789D8"))) PPC_WEAK_FUNC(sub_821789D8);
PPC_FUNC_IMPL(__imp__sub_821789D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,17164(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17164);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821789FC"))) PPC_WEAK_FUNC(sub_821789FC);
PPC_FUNC_IMPL(__imp__sub_821789FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178A00"))) PPC_WEAK_FUNC(sub_82178A00);
PPC_FUNC_IMPL(__imp__sub_82178A00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r3,17020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17020);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82178A0C"))) PPC_WEAK_FUNC(sub_82178A0C);
PPC_FUNC_IMPL(__imp__sub_82178A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178A10"))) PPC_WEAK_FUNC(sub_82178A10);
PPC_FUNC_IMPL(__imp__sub_82178A10) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8241a918
	ctx.lr = 0x82178A2C;
	sub_8241A918(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82178A44"))) PPC_WEAK_FUNC(sub_82178A44);
PPC_FUNC_IMPL(__imp__sub_82178A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178A48"))) PPC_WEAK_FUNC(sub_82178A48);
PPC_FUNC_IMPL(__imp__sub_82178A48) {
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
	// beq cr6,0x82178ab0
	if (cr6.eq) goto loc_82178AB0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82178a8c
	if (cr6.eq) goto loc_82178A8C;
	// bl 0x824221d8
	ctx.lr = 0x82178A78;
	sub_824221D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82178A8C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,-27816(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27816);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82178AA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82178AB0;
	sub_82130588(ctx, base);
loc_82178AB0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82178AC4"))) PPC_WEAK_FUNC(sub_82178AC4);
PPC_FUNC_IMPL(__imp__sub_82178AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178AC8"))) PPC_WEAK_FUNC(sub_82178AC8);
PPC_FUNC_IMPL(__imp__sub_82178AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x8241b6f0
	sub_8241B6F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178ADC"))) PPC_WEAK_FUNC(sub_82178ADC);
PPC_FUNC_IMPL(__imp__sub_82178ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178AE0"))) PPC_WEAK_FUNC(sub_82178AE0);
PPC_FUNC_IMPL(__imp__sub_82178AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x8241b178
	sub_8241B178(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178AF4"))) PPC_WEAK_FUNC(sub_82178AF4);
PPC_FUNC_IMPL(__imp__sub_82178AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178AF8"))) PPC_WEAK_FUNC(sub_82178AF8);
PPC_FUNC_IMPL(__imp__sub_82178AF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-27772
	ctx.r9.s64 = ctx.r10.s64 + -27772;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// stw r11,36(r9)
	PPC_STORE_U32(ctx.r9.u32 + 36, r11.u32);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// stw r11,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, r11.u32);
	// b 0x8218c9a8
	sub_8218C9A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178B20"))) PPC_WEAK_FUNC(sub_82178B20);
PPC_FUNC_IMPL(__imp__sub_82178B20) {
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
	ctx.lr = 0x82178B28;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r30,r11,-27732
	r30.s64 = r11.s64 + -27732;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-27788(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -27788);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82432d28
	ctx.lr = 0x82178B54;
	sub_82432D28(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82178b84
	if (!cr6.eq) goto loc_82178B84;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218de38
	ctx.lr = 0x82178B80;
	sub_8218DE38(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82178B84:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82412810
	ctx.lr = 0x82178B90;
	sub_82412810(ctx, base);
	// bl 0x82412158
	ctx.lr = 0x82178B94;
	sub_82412158(ctx, base);
	// lwz r11,-27788(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -27788);
	// li r7,16
	ctx.r7.s64 = 16;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// bl 0x82410c00
	ctx.lr = 0x82178BB4;
	sub_82410C00(ctx, base);
	// lwz r4,116(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lwz r10,156(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// lwz r8,148(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r7,144(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lhz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82432438
	ctx.lr = 0x82178BF4;
	sub_82432438(ctx, base);
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lwz r10,148(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lis r5,4
	ctx.r5.s64 = 262144;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r6,4
	ctx.r6.s64 = 4;
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rlwinm r7,r9,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x824313a0
	ctx.lr = 0x82178C1C;
	sub_824313A0(ctx, base);
	// lwz r11,-27788(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -27788);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// bl 0x8240f220
	ctx.lr = 0x82178C30;
	sub_8240F220(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82178C3C"))) PPC_WEAK_FUNC(sub_82178C3C);
PPC_FUNC_IMPL(__imp__sub_82178C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178C40"))) PPC_WEAK_FUNC(sub_82178C40);
PPC_FUNC_IMPL(__imp__sub_82178C40) {
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
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// lbz r7,199(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 199);
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// subfic r9,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r9.s64 = 0 - r11.s64;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r10,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r10.s64;
	// add r6,r4,r6
	ctx.r6.u64 = ctx.r4.u64 + ctx.r6.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r7,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r7.s64;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// rlwimi r9,r10,0,27,27
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x10) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFEF);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// subfe r10,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// lis r7,6690
	ctx.r7.s64 = 438435840;
	// rlwimi r9,r10,0,26,26
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x20) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFDF);
	// ori r4,r7,407
	ctx.r4.u64 = ctx.r7.u64 | 407;
	// add r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 + ctx.r5.u64;
	// clrlwi r6,r9,26
	ctx.r6.u64 = ctx.r9.u32 & 0x3F;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x82178cb8
	if (!cr6.eq) goto loc_82178CB8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 - ctx.f1.f64));
loc_82178CB8:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r9,204(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x824195e8
	ctx.lr = 0x82178CD8;
	sub_824195E8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82178CE8"))) PPC_WEAK_FUNC(sub_82178CE8);
PPC_FUNC_IMPL(__imp__sub_82178CE8) {
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
	// addi r31,r11,-27704
	r31.s64 = r11.s64 + -27704;
	// lwz r11,-396(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -396);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-396(r31)
	PPC_STORE_U32(r31.u32 + -396, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82178d68
	if (!cr6.eq) goto loc_82178D68;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82414b78
	ctx.lr = 0x82178D24;
	sub_82414B78(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r11,-21092(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21092);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82178d48
	if (!cr6.eq) goto loc_82178D48;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-21080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21080);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82178d4c
	if (cr6.eq) goto loc_82178D4C;
loc_82178D48:
	// li r11,1
	r11.s64 = 1;
loc_82178D4C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82178d68
	if (!cr6.eq) goto loc_82178D68;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,-27296
	ctx.r3.s64 = r11.s64 + -27296;
	// bl 0x8218baa0
	ctx.lr = 0x82178D68;
	sub_8218BAA0(ctx, base);
loc_82178D68:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82178D7C"))) PPC_WEAK_FUNC(sub_82178D7C);
PPC_FUNC_IMPL(__imp__sub_82178D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178D80"))) PPC_WEAK_FUNC(sub_82178D80);
PPC_FUNC_IMPL(__imp__sub_82178D80) {
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
	// add r11,r3,r5
	r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// add r10,r4,r6
	ctx.r10.u64 = ctx.r4.u64 + ctx.r6.u64;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lis r31,-32124
	r31.s64 = -2105278464;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82415c80
	ctx.lr = 0x82178DB8;
	sub_82415C80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82416530
	ctx.lr = 0x82178DC4;
	sub_82416530(ctx, base);
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

__attribute__((alias("__imp__sub_82178DD8"))) PPC_WEAK_FUNC(sub_82178DD8);
PPC_FUNC_IMPL(__imp__sub_82178DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x82416530
	sub_82416530(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178DE8"))) PPC_WEAK_FUNC(sub_82178DE8);
PPC_FUNC_IMPL(__imp__sub_82178DE8) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r31,-27716(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -27716);
	// stw r4,-27716(r11)
	PPC_STORE_U32(r11.u32 + -27716, ctx.r4.u32);
	// lwz r3,-28076(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// bl 0x824143f8
	ctx.lr = 0x82178E14;
	sub_824143F8(ctx, base);
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

__attribute__((alias("__imp__sub_82178E2C"))) PPC_WEAK_FUNC(sub_82178E2C);
PPC_FUNC_IMPL(__imp__sub_82178E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178E30"))) PPC_WEAK_FUNC(sub_82178E30);
PPC_FUNC_IMPL(__imp__sub_82178E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// bl 0x823d91fc
	ctx.lr = 0x82178E38;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r8,r10,-27552
	ctx.r8.s64 = ctx.r10.s64 + -27552;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// rlwinm r9,r31,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r11,r11,256
	r11.s64 = r11.s64 + 256;
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,32
	ctx.r7.s64 = 32;
	// stvx128 v63,r9,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v59,r11,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v57,v62,v61
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v58,v59,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// vmrghw128 v56,v62,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v55,v59,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrglw128 v54,v57,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v53,v57,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v52,v56,v55
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v51,v56,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821cf1a0
	ctx.lr = 0x82178ECC;
	sub_821CF1A0(ctx, base);
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lvx128 v50,r0,r30
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// vspltw128 v49,v50,3
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x0));
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// vspltw128 v0,v50,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x55));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// vspltw128 v12,v50,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xAA));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v48,r0,r7
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v10,v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmulfp128 v8,v49,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32)));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lvx128 v9,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-28076(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -28076);
	// vmaddfp v7,v0,v13,v8
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v6,v12,v11,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v5,v10,v9,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v5,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82416190
	ctx.lr = 0x82178F2C;
	sub_82416190(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82178F34"))) PPC_WEAK_FUNC(sub_82178F34);
PPC_FUNC_IMPL(__imp__sub_82178F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178F38"))) PPC_WEAK_FUNC(sub_82178F38);
PPC_FUNC_IMPL(__imp__sub_82178F38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,17060(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17060);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82178f5c
	if (!cr6.gt) goto loc_82178F5C;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r3,r9,-28072
	ctx.r3.s64 = ctx.r9.s64 + -28072;
	// blr 
	return;
loc_82178F5C:
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82178F6C"))) PPC_WEAK_FUNC(sub_82178F6C);
PPC_FUNC_IMPL(__imp__sub_82178F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178F70"))) PPC_WEAK_FUNC(sub_82178F70);
PPC_FUNC_IMPL(__imp__sub_82178F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82178F78;
	// stfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f30.u64);
	// stfd f31,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	r27.s64 = 0;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// mr r20,r27
	r20.u64 = r27.u64;
	// beq cr6,0x8217903c
	if (cr6.eq) goto loc_8217903C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lbz r9,20(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 20);
	// rlwinm r6,r11,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// rlwinm r4,r11,8,24,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// rlwinm r3,r11,16,24,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// clrlwi r7,r11,24
	ctx.r7.u64 = r11.u32 & 0xFF;
	// std r4,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r4.u64);
	// std r3,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r3.u64);
	// lfd f12,128(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// lfd f13,112(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r7,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f10,128(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// lfd f11,112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,136(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// beq cr6,0x8217902c
	if (cr6.eq) goto loc_8217902C;
	// li r20,256
	r20.s64 = 256;
loc_8217902C:
	// lbz r11,21(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 21);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217903c
	if (cr6.eq) goto loc_8217903C;
	// ori r20,r20,512
	r20.u64 = r20.u64 | 512;
loc_8217903C:
	// lis r18,-32131
	r18.s64 = -2105737216;
	// lwz r11,17060(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 17060);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82179184
	if (!cr6.gt) goto loc_82179184;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,-28072
	r31.s64 = r11.s64 + -28072;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// mr r21,r27
	r21.u64 = r27.u64;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r24,r27
	r24.u64 = r27.u64;
	// li r19,3
	r19.s64 = 3;
	// lis r22,-32124
	r22.s64 = -2105278464;
	// addi r26,r11,17200
	r26.s64 = r11.s64 + 17200;
loc_82179078:
	// slw r4,r19,r24
	ctx.r4.u64 = r24.u8 & 0x20 ? 0 : (r19.u32 << (r24.u8 & 0x3F));
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// bl 0x8241bd08
	ctx.lr = 0x82179084;
	sub_8241BD08(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// beq cr6,0x821790e4
	if (cr6.eq) goto loc_821790E4;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821790B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-28076(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82420ba8
	ctx.lr = 0x821790E4;
	sub_82420BA8(ctx, base);
loc_821790E4:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82179150
	if (cr6.eq) goto loc_82179150;
	// lfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r30,12(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// bl 0x82177b58
	ctx.lr = 0x821790F8;
	sub_82177B58(ctx, base);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82179110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-27692(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -27692);
	// lwz r29,-28076(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// neg r9,r11
	ctx.r9.s64 = -r11.s64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// rlwinm r4,r9,26,0,5
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0xFC000000;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// or r4,r4,r20
	ctx.r4.u64 = ctx.r4.u64 | r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82420ba8
	ctx.lr = 0x82179150;
	sub_82420BA8(ctx, base);
loc_82179150:
	// lwz r11,17060(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 17060);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r24,r24,2
	r24.s64 = r24.s64 + 2;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// blt cr6,0x82179078
	if (cr6.lt) goto loc_82179078;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// bl 0x8241bd08
	ctx.lr = 0x82179174;
	sub_8241BD08(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82179184:
	// lis r30,-32124
	r30.s64 = -2105278464;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x821791dc
	if (cr6.eq) goto loc_821791DC;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821791A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r11,-28076(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82420ba8
	ctx.lr = 0x821791DC;
	sub_82420BA8(ctx, base);
loc_821791DC:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82179278
	if (cr6.eq) goto loc_82179278;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// ori r9,r10,407
	ctx.r9.u64 = ctx.r10.u64 | 407;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r11,r11,17200
	r11.s64 = r11.s64 + 17200;
	// bne cr6,0x82179218
	if (!cr6.eq) goto loc_82179218;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f31,f0,f13
	f31.f64 = double(float(f0.f64 - ctx.f13.f64));
	// b 0x8217921c
	goto loc_8217921C;
loc_82179218:
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
loc_8217921C:
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r31,12(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82179234;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lwz r4,-28076(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// lwz r11,-27692(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27692);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// neg r4,r11
	ctx.r4.s64 = -r11.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r11,r4,26,0,5
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0xFC000000;
	// or r4,r11,r20
	ctx.r4.u64 = r11.u64 | r20.u64;
	// bl 0x82420ba8
	ctx.lr = 0x82179278;
	sub_82420BA8(ctx, base);
loc_82179278:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82179288"))) PPC_WEAK_FUNC(sub_82179288);
PPC_FUNC_IMPL(__imp__sub_82179288) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x82418018
	sub_82418018(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821792A0"))) PPC_WEAK_FUNC(sub_821792A0);
PPC_FUNC_IMPL(__imp__sub_821792A0) {
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
	ctx.lr = 0x821792A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x821792d4
	if (cr6.eq) goto loc_821792D4;
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// ble cr6,0x821792d8
	if (!cr6.gt) goto loc_821792D8;
loc_821792D4:
	// lwz r27,4(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_821792D8:
	// lis r31,-32124
	r31.s64 = -2105278464;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82417e40
	ctx.lr = 0x821792E8;
	sub_82417E40(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82179334
	if (cr6.eq) goto loc_82179334;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82179334
	if (!cr6.eq) goto loc_82179334;
	// bl 0x824179a8
	ctx.lr = 0x8217930C;
	sub_824179A8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82179334
	if (!cr6.eq) goto loc_82179334;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82424eb0
	ctx.lr = 0x82179334;
	sub_82424EB0(ctx, base);
loc_82179334:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// addi r30,r11,-27772
	r30.s64 = r11.s64 + -27772;
	// beq cr6,0x82179360
	if (cr6.eq) goto loc_82179360;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// beq cr6,0x82179360
	if (cr6.eq) goto loc_82179360;
	// stw r28,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r28.u32);
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82417e88
	ctx.lr = 0x82179360;
	sub_82417E88(ctx, base);
loc_82179360:
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// lwz r4,12(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// bl 0x82415ee8
	ctx.lr = 0x8217936C;
	sub_82415EE8(ctx, base);
	// lwz r7,12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// lwz r5,28(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// bl 0x82415dc8
	ctx.lr = 0x8217938C;
	sub_82415DC8(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,17168
	ctx.r10.s64 = r11.s64 + 17168;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// rlwinm r9,r25,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8241d620
	ctx.lr = 0x821793B0;
	sub_8241D620(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82415dc8
	ctx.lr = 0x821793D4;
	sub_82415DC8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821793DC"))) PPC_WEAK_FUNC(sub_821793DC);
PPC_FUNC_IMPL(__imp__sub_821793DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821793E0"))) PPC_WEAK_FUNC(sub_821793E0);
PPC_FUNC_IMPL(__imp__sub_821793E0) {
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
	ctx.lr = 0x821793E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x82417e40
	ctx.lr = 0x8217940C;
	sub_82417E40(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82179458
	if (cr6.eq) goto loc_82179458;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82179458
	if (!cr6.eq) goto loc_82179458;
	// bl 0x824179a8
	ctx.lr = 0x82179430;
	sub_824179A8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82179458
	if (!cr6.eq) goto loc_82179458;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82424eb0
	ctx.lr = 0x82179458;
	sub_82424EB0(ctx, base);
loc_82179458:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r30,r11,-27772
	r30.s64 = r11.s64 + -27772;
	// beq cr6,0x82179484
	if (cr6.eq) goto loc_82179484;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x82179484
	if (cr6.eq) goto loc_82179484;
	// stw r29,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r29.u32);
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82417e88
	ctx.lr = 0x82179484;
	sub_82417E88(ctx, base);
loc_82179484:
	// lwz r7,12(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// lwz r5,28(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// bl 0x82415dc8
	ctx.lr = 0x821794A4;
	sub_82415DC8(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,17168
	ctx.r10.s64 = r11.s64 + 17168;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// rlwinm r9,r27,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8241d230
	ctx.lr = 0x821794C4;
	sub_8241D230(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82415dc8
	ctx.lr = 0x821794E8;
	sub_82415DC8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821794F0"))) PPC_WEAK_FUNC(sub_821794F0);
PPC_FUNC_IMPL(__imp__sub_821794F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r23{};
	PPCRegister temp{};
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r3,7
	cr6.compare<uint32_t>(ctx.r3.u32, 7, xer);
	// bgt cr6,0x82179580
	if (cr6.gt) {
		// ERROR 82179580
		return;
	}
	// lis r12,-32232
	r12.s64 = -2112356352;
	// addi r12,r12,-27372
	r12.s64 = r12.s64 + -27372;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_82179534;
	case 1:
		goto loc_82179540;
	case 2:
		goto loc_82179550;
	case 3:
		goto loc_82179578;
	case 4:
		goto loc_8217955C;
	case 5:
		goto loc_8217955C;
	case 6:
		goto loc_82179568;
	case 7:
		goto loc_82179578;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-27340(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -27340);
	// lwz r16,-27328(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -27328);
	// lwz r16,-27312(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -27312);
	// lwz r16,-27272(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -27272);
	// lwz r16,-27300(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -27300);
	// lwz r16,-27300(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -27300);
	// lwz r16,-27288(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -27288);
	// lwz r16,-27272(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -27272);
loc_82179534:
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
loc_82179540:
	// srawi r11,r4,1
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	r11.s64 = ctx.r4.s32 >> 1;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
loc_82179550:
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
loc_8217955C:
	// addi r11,r4,-2
	r11.s64 = ctx.r4.s64 + -2;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
loc_82179568:
	// srawi r11,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	r11.s64 = ctx.r4.s32 >> 2;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
loc_82179578:
	// li r11,3
	r11.s64 = 3;
}

__attribute__((alias("__imp__sub_82179588"))) PPC_WEAK_FUNC(sub_82179588);
PPC_FUNC_IMPL(__imp__sub_82179588) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,17168
	ctx.r9.s64 = r11.s64 + 17168;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x821794f0
	ctx.lr = 0x821795B4;
	sub_821794F0(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r11,r5,3064
	r11.s64 = ctx.r5.s64 + 3064;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,-28076(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// lwzx r8,r7,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// mullw r9,r3,r8
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8241d620
	ctx.lr = 0x821795E8;
	sub_8241D620(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821795F8"))) PPC_WEAK_FUNC(sub_821795F8);
PPC_FUNC_IMPL(__imp__sub_821795F8) {
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
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r9,17168
	ctx.r7.s64 = ctx.r9.s64 + 17168;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwzx r6,r8,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// rlwinm r9,r6,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x821794f0
	ctx.lr = 0x82179624;
	sub_821794F0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// addi r11,r8,3064
	r11.s64 = ctx.r8.s64 + 3064;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r10,-28076(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28076);
	// lwzx r7,r9,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// mullw r9,r3,r7
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8241d230
	ctx.lr = 0x82179658;
	sub_8241D230(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82179668"))) PPC_WEAK_FUNC(sub_82179668);
PPC_FUNC_IMPL(__imp__sub_82179668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// add r10,r11,r6
	ctx.r10.u64 = r11.u64 + ctx.r6.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// rlwinm r7,r8,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// rldicr r8,r3,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// subf r10,r9,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r9.s64;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lwz r3,-28076(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -28076);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// srad r10,r8,r7
	temp.u64 = ctx.r7.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	xer.ca = (ctx.r8.s64 < 0) & (((ctx.r8.s64 >> temp.u64) << temp.u64) != ctx.r8.s64);
	ctx.r10.s64 = ctx.r8.s64 >> temp.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// srd r7,r10,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r9.u8 & 0x7F));
	// b 0x82417678
	sub_82417678(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821796AC"))) PPC_WEAK_FUNC(sub_821796AC);
PPC_FUNC_IMPL(__imp__sub_821796AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821796B0"))) PPC_WEAK_FUNC(sub_821796B0);
PPC_FUNC_IMPL(__imp__sub_821796B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bne cr6,0x821796d0
	if (!cr6.eq) goto loc_821796D0;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8241ec40
	sub_8241EC40(ctx, base);
	return;
loc_821796D0:
	// b 0x8241ec40
	sub_8241EC40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821796D4"))) PPC_WEAK_FUNC(sub_821796D4);
PPC_FUNC_IMPL(__imp__sub_821796D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821796D8"))) PPC_WEAK_FUNC(sub_821796D8);
PPC_FUNC_IMPL(__imp__sub_821796D8) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8241dc98
	ctx.lr = 0x821796F4;
	sub_8241DC98(ctx, base);
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

__attribute__((alias("__imp__sub_82179710"))) PPC_WEAK_FUNC(sub_82179710);
PPC_FUNC_IMPL(__imp__sub_82179710) {
	PPC_FUNC_PROLOGUE();
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8241de08
	sub_8241DE08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179718"))) PPC_WEAK_FUNC(sub_82179718);
PPC_FUNC_IMPL(__imp__sub_82179718) {
	PPC_FUNC_PROLOGUE();
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8241de08
	sub_8241DE08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179720"))) PPC_WEAK_FUNC(sub_82179720);
PPC_FUNC_IMPL(__imp__sub_82179720) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8241e088
	ctx.lr = 0x82179744;
	sub_8241E088(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82179758
	if (!cr6.eq) goto loc_82179758;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82179760
	goto loc_82179760;
loc_82179758:
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82179760:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_82179778"))) PPC_WEAK_FUNC(sub_82179778);
PPC_FUNC_IMPL(__imp__sub_82179778) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// bge cr6,0x82179788
	if (!cr6.lt) goto loc_82179788;
	// neg r11,r4
	r11.s64 = -ctx.r4.s64;
loc_82179788:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82179794:
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821797a4
	if (cr6.eq) goto loc_821797A4;
	// fmuls f0,f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f1.f64));
loc_821797A4:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821797b8
	if (cr6.eq) goto loc_821797B8;
	// fmuls f1,f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// b 0x82179794
	goto loc_82179794;
loc_821797B8:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x821797c8
	if (!cr6.lt) goto loc_821797C8;
	// fdivs f1,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f13.f64 / f0.f64));
	// blr 
	return;
loc_821797C8:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821797D0"))) PPC_WEAK_FUNC(sub_821797D0);
PPC_FUNC_IMPL(__imp__sub_821797D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,17164(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17164);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x821797f8
	if (!cr6.eq) goto loc_821797F8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x82179800
	goto loc_82179800;
loc_821797F8:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_82179800:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217982C"))) PPC_WEAK_FUNC(sub_8217982C);
PPC_FUNC_IMPL(__imp__sub_8217982C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179830"))) PPC_WEAK_FUNC(sub_82179830);
PPC_FUNC_IMPL(__imp__sub_82179830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,17164(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17164);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x82179858
	if (!cr6.eq) goto loc_82179858;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x82179860
	goto loc_82179860;
loc_82179858:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_82179860:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217988C"))) PPC_WEAK_FUNC(sub_8217988C);
PPC_FUNC_IMPL(__imp__sub_8217988C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179890"))) PPC_WEAK_FUNC(sub_82179890);
PPC_FUNC_IMPL(__imp__sub_82179890) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,17164(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17164);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x821798b8
	if (!cr6.eq) goto loc_821798B8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x821798c0
	goto loc_821798C0;
loc_821798B8:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_821798C0:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821798EC"))) PPC_WEAK_FUNC(sub_821798EC);
PPC_FUNC_IMPL(__imp__sub_821798EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821798F0"))) PPC_WEAK_FUNC(sub_821798F0);
PPC_FUNC_IMPL(__imp__sub_821798F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,17164(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17164);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x82179918
	if (!cr6.eq) goto loc_82179918;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x82179920
	goto loc_82179920;
loc_82179918:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_82179920:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f0,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	f0.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217994C"))) PPC_WEAK_FUNC(sub_8217994C);
PPC_FUNC_IMPL(__imp__sub_8217994C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179950"))) PPC_WEAK_FUNC(sub_82179950);
PPC_FUNC_IMPL(__imp__sub_82179950) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r10,17164(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17164);
	// lwz r5,17004(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17004);
	// lwz r6,17012(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17012);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// beq cr6,0x82179990
	if (cr6.eq) goto loc_82179990;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
loc_82179990:
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r4,-32131
	ctx.r4.s64 = -2105737216;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lwz r7,17008(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17008);
	// lwz r8,17016(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 17016);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// beq cr6,0x821799dc
	if (cr6.eq) goto loc_821799DC;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_821799DC:
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r4,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// beq cr6,0x82179a18
	if (cr6.eq) goto loc_82179A18;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
loc_82179A18:
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// beq cr6,0x82179a54
	if (cr6.eq) goto loc_82179A54;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82179A54:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f12,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f0,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r9,6690
	ctx.r9.s64 = 438435840;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,17068(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// ori r11,r9,407
	r11.u64 = ctx.r9.u64 | 407;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// bne cr6,0x82179aa8
	if (!cr6.eq) goto loc_82179AA8;
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
loc_82179AA8:
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// lfs f0,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// bne cr6,0x82179abc
	if (!cr6.eq) goto loc_82179ABC;
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
loc_82179ABC:
	// stfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82416540
	ctx.lr = 0x82179AD0;
	sub_82416540(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82179AE0"))) PPC_WEAK_FUNC(sub_82179AE0);
PPC_FUNC_IMPL(__imp__sub_82179AE0) {
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
	// lis r31,-32124
	r31.s64 = -2105278464;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82416ca8
	ctx.lr = 0x82179B04;
	sub_82416CA8(ctx, base);
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82177b80
	ctx.lr = 0x82179B0C;
	sub_82177B80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x824169d0
	ctx.lr = 0x82179B18;
	sub_824169D0(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r31,r11,-27732
	r31.s64 = r11.s64 + -27732;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82179b38
	if (cr6.eq) goto loc_82179B38;
	// bl 0x824221d8
	ctx.lr = 0x82179B30;
	sub_824221D8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82179B38:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82179b50
	if (cr6.eq) goto loc_82179B50;
	// bl 0x824221d8
	ctx.lr = 0x82179B48;
	sub_824221D8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82179B50:
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lwz r3,-28080(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28080);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82179b6c
	if (cr6.eq) goto loc_82179B6C;
	// bl 0x824221d8
	ctx.lr = 0x82179B64;
	sub_824221D8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-28080(r31)
	PPC_STORE_U32(r31.u32 + -28080, r11.u32);
loc_82179B6C:
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lwz r3,-27812(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -27812);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82179b88
	if (cr6.eq) goto loc_82179B88;
	// bl 0x824221d8
	ctx.lr = 0x82179B80;
	sub_824221D8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-27812(r31)
	PPC_STORE_U32(r31.u32 + -27812, r11.u32);
loc_82179B88:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82179B9C"))) PPC_WEAK_FUNC(sub_82179B9C);
PPC_FUNC_IMPL(__imp__sub_82179B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179BA0"))) PPC_WEAK_FUNC(sub_82179BA0);
PPC_FUNC_IMPL(__imp__sub_82179BA0) {
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
	// addi r10,r11,-27616
	ctx.r10.s64 = r11.s64 + -27616;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82179bcc
	if (cr6.eq) goto loc_82179BCC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82179BCC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// addi r31,r11,-28224
	r31.s64 = r11.s64 + -28224;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r11,-28076(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// stb r4,528(r31)
	PPC_STORE_U8(r31.u32 + 528, ctx.r4.u8);
	// stw r3,17020(r10)
	PPC_STORE_U32(ctx.r10.u32 + 17020, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82179c08
	if (cr6.eq) goto loc_82179C08;
	// bl 0x82179ae0
	ctx.lr = 0x82179BF4;
	sub_82179AE0(ctx, base);
	// bl 0x821785d0
	ctx.lr = 0x82179BF8;
	sub_821785D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// bl 0x82413270
	ctx.lr = 0x82179C04;
	sub_82413270(ctx, base);
	// bl 0x821784b8
	ctx.lr = 0x82179C08;
	sub_821784B8(ctx, base);
loc_82179C08:
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

__attribute__((alias("__imp__sub_82179C20"))) PPC_WEAK_FUNC(sub_82179C20);
PPC_FUNC_IMPL(__imp__sub_82179C20) {
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
	ctx.lr = 0x82179C28;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// stw r28,-27780(r11)
	PPC_STORE_U32(r11.u32 + -27780, r28.u32);
	// lwz r3,-28092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28092);
	// bl 0x82415fc0
	ctx.lr = 0x82179C44;
	sub_82415FC0(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// li r31,0
	r31.s64 = 0;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lwz r10,-27744(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27744);
	// li r11,-1
	r11.s64 = -1;
	// std r31,0(r7)
	PPC_STORE_U64(ctx.r7.u32 + 0, r31.u64);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// std r31,8(r7)
	PPC_STORE_U64(ctx.r7.u32 + 8, r31.u64);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// std r31,16(r7)
	PPC_STORE_U64(ctx.r7.u32 + 16, r31.u64);
	// addi r29,r8,-27772
	r29.s64 = ctx.r8.s64 + -27772;
	// lwz r9,17060(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 17060);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// std r31,24(r7)
	PPC_STORE_U64(ctx.r7.u32 + 24, r31.u64);
	// stw r10,-28076(r30)
	PPC_STORE_U32(r30.u32 + -28076, ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// li r7,0
	ctx.r7.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// ble cr6,0x82179cbc
	if (!cr6.gt) goto loc_82179CBC;
	// addi r8,r29,-300
	ctx.r8.s64 = r29.s64 + -300;
	// li r5,18
	ctx.r5.s64 = 18;
	// b 0x82179cc8
	goto loc_82179CC8;
loc_82179CBC:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
loc_82179CC8:
	// bl 0x8241abb8
	ctx.lr = 0x82179CCC;
	sub_8241ABB8(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r11,36(r29)
	PPC_STORE_U32(r29.u32 + 36, r11.u32);
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// stw r31,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r31.u32);
	// stw r31,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r31.u32);
	// bl 0x8218c9a8
	ctx.lr = 0x82179CEC;
	sub_8218C9A8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// bl 0x824169d0
	ctx.lr = 0x82179CF8;
	sub_824169D0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// bl 0x82415f78
	ctx.lr = 0x82179D04;
	sub_82415F78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82179d18
	if (!cr6.eq) goto loc_82179D18;
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// bl 0x82177b80
	ctx.lr = 0x82179D14;
	sub_82177B80(ctx, base);
	// b 0x82179d1c
	goto loc_82179D1C;
loc_82179D18:
	// bl 0x824221d8
	ctx.lr = 0x82179D1C;
	sub_824221D8(ctx, base);
loc_82179D1C:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82179d2c
	if (cr6.eq) goto loc_82179D2C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824221d8
	ctx.lr = 0x82179D2C;
	sub_824221D8(ctx, base);
loc_82179D2C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82179D34"))) PPC_WEAK_FUNC(sub_82179D34);
PPC_FUNC_IMPL(__imp__sub_82179D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179D38"))) PPC_WEAK_FUNC(sub_82179D38);
PPC_FUNC_IMPL(__imp__sub_82179D38) {
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
	ctx.lr = 0x82179D40;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,-27744(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -27744);
	// bl 0x8241b048
	ctx.lr = 0x82179D5C;
	sub_8241B048(ctx, base);
	// lwz r3,-27744(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -27744);
	// bl 0x8241b318
	ctx.lr = 0x82179D64;
	sub_8241B318(ctx, base);
	// lwz r3,-27744(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -27744);
	// bl 0x824219f8
	ctx.lr = 0x82179D6C;
	sub_824219F8(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r11,-27772
	r30.s64 = r11.s64 + -27772;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// stw r11,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r11.u32);
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r31.u32);
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r31.u32);
	// stw r31,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r31.u32);
	// stw r31,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r31.u32);
	// lwz r11,-28092(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28092);
	// stw r11,-28076(r8)
	PPC_STORE_U32(ctx.r8.u32 + -28076, r11.u32);
	// bl 0x8218c9a8
	ctx.lr = 0x82179DA8;
	sub_8218C9A8(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82179e88
	if (cr6.eq) goto loc_82179E88;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-27780(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -27780);
	// bl 0x8241a9c0
	ctx.lr = 0x82179DD0;
	sub_8241A9C0(ctx, base);
	// lwz r3,-44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -44);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82179DF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82179e50
	if (cr6.eq) goto loc_82179E50;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82130528
	ctx.lr = 0x82179E04;
	sub_82130528(ctx, base);
	// lwz r11,-27780(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -27780);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8241a9c0
	ctx.lr = 0x82179E28;
	sub_8241A9C0(ctx, base);
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r10,r11,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r30.u32);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r31,-27780(r28)
	PPC_STORE_U32(r28.u32 + -27780, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82179E50:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r10,-27132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -27132);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-27132(r11)
	PPC_STORE_U32(r11.u32 + -27132, ctx.r10.u32);
	// cmpwi cr6,r10,25
	cr6.compare<int32_t>(ctx.r10.s32, 25, xer);
	// bne cr6,0x82179e70
	if (!cr6.eq) goto loc_82179E70;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// stw r10,-27132(r11)
	PPC_STORE_U32(r11.u32 + -27132, ctx.r10.u32);
loc_82179E70:
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-27780(r28)
	PPC_STORE_U32(r28.u32 + -27780, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82179E88:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r31,-27780(r11)
	PPC_STORE_U32(r11.u32 + -27780, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82179E9C"))) PPC_WEAK_FUNC(sub_82179E9C);
PPC_FUNC_IMPL(__imp__sub_82179E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179EA0"))) PPC_WEAK_FUNC(sub_82179EA0);
PPC_FUNC_IMPL(__imp__sub_82179EA0) {
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
	ctx.lr = 0x82179EA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r28,r11,-27656
	r28.s64 = r11.s64 + -27656;
	// lwz r3,-160(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -160);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82179EC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82132608
	ctx.lr = 0x82179ECC;
	sub_82132608(ctx, base);
	// lwz r3,-160(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -160);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82179eec
	if (cr6.eq) goto loc_82179EEC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82179EEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82179EEC:
	// lwz r3,-52(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -52);
	// bl 0x82130588
	ctx.lr = 0x82179EF4;
	sub_82130588(ctx, base);
	// bl 0x8217f758
	ctx.lr = 0x82179EF8;
	sub_8217F758(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-27296
	ctx.r3.s64 = r11.s64 + -27296;
	// bl 0x8218c638
	ctx.lr = 0x82179F04;
	sub_8218C638(ctx, base);
	// bl 0x8217d480
	ctx.lr = 0x82179F08;
	sub_8217D480(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82179F0C;
	sub_82130000(ctx, base);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// li r27,0
	r27.s64 = 0;
	// lwz r31,-27784(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -27784);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82179f48
	if (cr6.eq) goto loc_82179F48;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824221d8
	ctx.lr = 0x82179F28;
	sub_824221D8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82179f40
	if (!cr6.eq) goto loc_82179F40;
	// bl 0x821bbea8
	ctx.lr = 0x82179F34;
	sub_821BBEA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82179F3C;
	sub_82130588(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x82179F40;
	sub_821BBF00(ctx, base);
loc_82179F40:
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r11,-27784(r30)
	PPC_STORE_U32(r30.u32 + -27784, r11.u32);
loc_82179F48:
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lwz r31,-28088(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -28088);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82179f80
	if (cr6.eq) goto loc_82179F80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824221d8
	ctx.lr = 0x82179F60;
	sub_824221D8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82179f78
	if (!cr6.eq) goto loc_82179F78;
	// bl 0x821bbea8
	ctx.lr = 0x82179F6C;
	sub_821BBEA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82179F74;
	sub_82130588(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x82179F78;
	sub_821BBF00(ctx, base);
loc_82179F78:
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r11,-28088(r30)
	PPC_STORE_U32(r30.u32 + -28088, r11.u32);
loc_82179F80:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_82179F84:
	// addi r29,r28,-32
	r29.s64 = r28.s64 + -32;
	// lwzx r11,r31,r29
	r11.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82179fd4
	if (cr6.eq) goto loc_82179FD4;
	// rotlwi r30,r11,0
	r30.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82179fd4
	if (cr6.eq) goto loc_82179FD4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82179FA8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82179fd0
	if (!cr6.eq) goto loc_82179FD0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82179fd0
	if (cr6.eq) goto loc_82179FD0;
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
	ctx.lr = 0x82179FD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82179FD0:
	// stwx r27,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, r27.u32);
loc_82179FD4:
	// lwzx r30,r31,r28
	r30.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8217a014
	if (cr6.eq) goto loc_8217A014;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82179FE8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8217a010
	if (!cr6.eq) goto loc_8217A010;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8217a010
	if (cr6.eq) goto loc_8217A010;
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
	ctx.lr = 0x8217A010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8217A010:
	// stwx r27,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, r27.u32);
loc_8217A014:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r31,32
	cr6.compare<int32_t>(r31.s32, 32, xer);
	// blt cr6,0x82179f84
	if (cr6.lt) goto loc_82179F84;
	// bl 0x82179ae0
	ctx.lr = 0x8217A024;
	sub_82179AE0(ctx, base);
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lwz r3,-28092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28092);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8217a040
	if (cr6.eq) goto loc_8217A040;
	// bl 0x82413218
	ctx.lr = 0x8217A038;
	sub_82413218(ctx, base);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r11,-28092(r31)
	PPC_STORE_U32(r31.u32 + -28092, r11.u32);
loc_8217A040:
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lwz r3,-27744(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -27744);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8217a05c
	if (cr6.eq) goto loc_8217A05C;
	// bl 0x82413218
	ctx.lr = 0x8217A054;
	sub_82413218(ctx, base);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r11,-27744(r31)
	PPC_STORE_U32(r31.u32 + -27744, r11.u32);
loc_8217A05C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8217A064"))) PPC_WEAK_FUNC(sub_8217A064);
PPC_FUNC_IMPL(__imp__sub_8217A064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217A068"))) PPC_WEAK_FUNC(sub_8217A068);
PPC_FUNC_IMPL(__imp__sub_8217A068) {
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
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-27772
	ctx.r9.s64 = ctx.r10.s64 + -27772;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// stw r11,36(r9)
	PPC_STORE_U32(ctx.r9.u32 + 36, r11.u32);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// stw r11,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, r11.u32);
	// bl 0x8218c9a8
	ctx.lr = 0x8217A0A4;
	sub_8218C9A8(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r7,6690
	ctx.r7.s64 = 438435840;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// ori r6,r7,447
	ctx.r6.u64 = ctx.r7.u64 | 447;
	// lwz r5,-28080(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -28080);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// cmpw cr6,r4,r6
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r6.s32, xer);
	// bne cr6,0x8217a0d8
	if (!cr6.eq) goto loc_8217A0D8;
	// lwz r9,28(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// lwz r10,-27692(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -27692);
	// rlwimi r9,r10,20,6,11
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 20) & 0x3F00000) | (ctx.r9.u64 & 0xFFFFFFFFFC0FFFFF);
	// stw r9,28(r5)
	PPC_STORE_U32(ctx.r5.u32 + 28, ctx.r9.u32);
	// lwz r5,-28080(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -28080);
loc_8217A0D8:
	// lis r30,-32124
	r30.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// bl 0x82416ca8
	ctx.lr = 0x8217A0E8;
	sub_82416CA8(ctx, base);
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// bl 0x82177b80
	ctx.lr = 0x8217A0F0;
	sub_82177B80(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// lwz r4,-27812(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27812);
	// bl 0x824169d0
	ctx.lr = 0x8217A100;
	sub_824169D0(ctx, base);
	// bl 0x8217fff8
	ctx.lr = 0x8217A104;
	sub_8217FFF8(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r4,-27692(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -27692);
	// lfs f1,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82179778
	ctx.lr = 0x8217A114;
	sub_82179778(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 / ctx.f1.f64));
	// bl 0x8217f6f0
	ctx.lr = 0x8217A124;
	sub_8217F6F0(ctx, base);
	// bl 0x8218cca8
	ctx.lr = 0x8217A128;
	sub_8218CCA8(ctx, base);
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

__attribute__((alias("__imp__sub_8217A140"))) PPC_WEAK_FUNC(sub_8217A140);
PPC_FUNC_IMPL(__imp__sub_8217A140) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9c4
	ctx.lr = 0x8217A158;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// fmr f26,f3
	f26.f64 = ctx.f3.f64;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// addi r30,r11,-28100
	r30.s64 = r11.s64 + -28100;
	// fmr f24,f4
	f24.f64 = ctx.f4.f64;
	// fmr f31,f5
	f31.f64 = ctx.f5.f64;
	// lwz r11,-27784(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27784);
	// fmr f27,f6
	f27.f64 = ctx.f6.f64;
	// fmr f29,f7
	f29.f64 = ctx.f7.f64;
	// fmr f25,f8
	f25.f64 = ctx.f8.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmr f23,f9
	f23.f64 = ctx.f9.f64;
	// beq cr6,0x8217a1b8
	if (cr6.eq) goto loc_8217A1B8;
	// lwz r10,364(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 364);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8217a1b8
	if (cr6.eq) goto loc_8217A1B8;
	// stw r11,364(r30)
	PPC_STORE_U32(r30.u32 + 364, r11.u32);
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82417e88
	ctx.lr = 0x8217A1B8;
	sub_82417E88(ctx, base);
loc_8217A1B8:
	// bl 0x82178ce8
	ctx.lr = 0x8217A1BC;
	sub_82178CE8(ctx, base);
	// li r6,28
	ctx.r6.s64 = 28;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8241cd88
	ctx.lr = 0x8217A1D0;
	sub_8241CD88(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8217a2a4
	if (cr6.eq) goto loc_8217A2A4;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r9,268(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lis r11,6690
	r11.s64 = 438435840;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// ori r11,r11,407
	r11.u64 = r11.u64 | 407;
	// lwz r7,17068(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,7444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// bne cr6,0x8217a208
	if (!cr6.eq) goto loc_8217A208;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// b 0x8217a20c
	goto loc_8217A20C;
loc_8217A208:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_8217A20C:
	// stfs f28,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// stfs f30,4(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f27,20(r3)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f29,24(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lwz r7,17068(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// bne cr6,0x8217a240
	if (!cr6.eq) goto loc_8217A240;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// b 0x8217a244
	goto loc_8217A244;
loc_8217A240:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_8217A244:
	// stw r8,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r8.u32);
	// stfs f26,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f30,32(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f25,48(r3)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f29,52(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lwz r11,17068(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x8217a27c
	if (!cr6.eq) goto loc_8217A27C;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// b 0x8217a280
	goto loc_8217A280;
loc_8217A27C:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_8217A280:
	// stfs f28,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// stfs f24,60(r3)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f13,64(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f27,76(r3)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f23,80(r3)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x8241d220
	ctx.lr = 0x8217A2A4;
	sub_8241D220(ctx, base);
loc_8217A2A4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// bne 0x8217a2c0
	if (!cr0.eq) goto loc_8217A2C0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82414b78
	ctx.lr = 0x8217A2C0;
	sub_82414B78(ctx, base);
loc_8217A2C0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba10
	ctx.lr = 0x8217A2CC;
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

__attribute__((alias("__imp__sub_8217A2E0"))) PPC_WEAK_FUNC(sub_8217A2E0);
PPC_FUNC_IMPL(__imp__sub_8217A2E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9c4
	ctx.lr = 0x8217A2F4;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// fmr f26,f3
	f26.f64 = ctx.f3.f64;
	// fmr f24,f4
	f24.f64 = ctx.f4.f64;
	// fmr f31,f5
	f31.f64 = ctx.f5.f64;
	// lwz r11,-27784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27784);
	// fmr f27,f6
	f27.f64 = ctx.f6.f64;
	// fmr f29,f7
	f29.f64 = ctx.f7.f64;
	// fmr f25,f8
	f25.f64 = ctx.f8.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmr f23,f9
	f23.f64 = ctx.f9.f64;
	// beq cr6,0x8217a350
	if (cr6.eq) goto loc_8217A350;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r9,-27736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27736);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x8217a350
	if (cr6.eq) goto loc_8217A350;
	// stw r11,-27736(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27736, r11.u32);
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82417e88
	ctx.lr = 0x8217A350;
	sub_82417E88(ctx, base);
loc_8217A350:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82414b78
	ctx.lr = 0x8217A35C;
	sub_82414B78(ctx, base);
	// li r6,28
	ctx.r6.s64 = 28;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8241cd88
	ctx.lr = 0x8217A370;
	sub_8241CD88(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8217a444
	if (cr6.eq) goto loc_8217A444;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r9,268(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lis r11,6690
	r11.s64 = 438435840;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// ori r11,r11,407
	r11.u64 = r11.u64 | 407;
	// lwz r7,17068(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,7444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// bne cr6,0x8217a3a8
	if (!cr6.eq) goto loc_8217A3A8;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// b 0x8217a3ac
	goto loc_8217A3AC;
loc_8217A3A8:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_8217A3AC:
	// stfs f28,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// stfs f30,4(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f27,20(r3)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f29,24(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lwz r7,17068(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// bne cr6,0x8217a3e0
	if (!cr6.eq) goto loc_8217A3E0;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// b 0x8217a3e4
	goto loc_8217A3E4;
loc_8217A3E0:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_8217A3E4:
	// stw r8,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r8.u32);
	// stfs f26,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f30,32(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f25,48(r3)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f29,52(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lwz r11,17068(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x8217a41c
	if (!cr6.eq) goto loc_8217A41C;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// b 0x8217a420
	goto loc_8217A420;
loc_8217A41C:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_8217A420:
	// stfs f28,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// stfs f24,60(r3)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f13,64(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f27,76(r3)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f23,80(r3)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x8241d220
	ctx.lr = 0x8217A444;
	sub_8241D220(ctx, base);
loc_8217A444:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82414b78
	ctx.lr = 0x8217A450;
	sub_82414B78(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba10
	ctx.lr = 0x8217A45C;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217A46C"))) PPC_WEAK_FUNC(sub_8217A46C);
PPC_FUNC_IMPL(__imp__sub_8217A46C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217A470"))) PPC_WEAK_FUNC(sub_8217A470);
PPC_FUNC_IMPL(__imp__sub_8217A470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8217A478;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r4,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r4.u32);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// stw r11,404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 404, r11.u32);
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// li r15,0
	r15.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r14,r10,17200
	r14.s64 = ctx.r10.s64 + 17200;
	// beq cr6,0x8217a4dc
	if (cr6.eq) goto loc_8217A4DC;
	// li r9,7
	ctx.r9.s64 = 7;
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8217A4C4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8217a4c4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8217A4C4;
	// b 0x8217a4f0
	goto loc_8217A4F0;
loc_8217A4DC:
	// lis r11,-256
	r11.s64 = -16777216;
	// stfs f31,0(r14)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r14.u32 + 0, temp.u32);
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// stw r11,8(r14)
	PPC_STORE_U32(r14.u32 + 8, r11.u32);
	// stw r10,12(r14)
	PPC_STORE_U32(r14.u32 + 12, ctx.r10.u32);
loc_8217A4F0:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r20,r11,-28072
	r20.s64 = r11.s64 + -28072;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// cmplwi cr6,r17,0
	cr6.compare<uint32_t>(r17.u32, 0, xer);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r16,r11,17164
	r16.s64 = r11.s64 + 17164;
	// stw r31,296(r20)
	PPC_STORE_U32(r20.u32 + 296, r31.u32);
	// beq cr6,0x8217a554
	if (cr6.eq) goto loc_8217A554;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217A530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r17)
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8217A548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r19,60(r17)
	r19.u64 = PPC_LOAD_U32(r17.u32 + 60);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// b 0x8217a5b0
	goto loc_8217A5B0;
loc_8217A554:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r7,56
	ctx.r7.s64 = 56;
	// lwz r10,0(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// lwzx r11,r7,r11
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8217a574
	if (!cr6.eq) goto loc_8217A574;
	// lwz r28,17004(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17004);
	// b 0x8217a57c
	goto loc_8217A57C;
loc_8217A574:
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwz r28,17012(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17012);
loc_8217A57C:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8217a58c
	if (!cr6.eq) goto loc_8217A58C;
	// lwz r25,17008(r8)
	r25.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17008);
	// b 0x8217a594
	goto loc_8217A594;
loc_8217A58C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r25,17016(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_8217A594:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-27316
	ctx.r10.s64 = r11.s64 + -27316;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// subfic r9,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r9.s64 = 0 - r11.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,30
	r11.u64 = ctx.r8.u32 & 0x3;
	// addi r19,r11,2
	r19.s64 = r11.s64 + 2;
loc_8217A5B0:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// cmpwi cr6,r18,1
	cr6.compare<int32_t>(r18.s32, 1, xer);
	// bgt cr6,0x8217a5c8
	if (cr6.gt) goto loc_8217A5C8;
	// li r10,80
	ctx.r10.s64 = 80;
	// b 0x8217a5dc
	goto loc_8217A5DC;
loc_8217A5C8:
	// cmpwi cr6,r18,2
	cr6.compare<int32_t>(r18.s32, 2, xer);
	// bne cr6,0x8217a5d8
	if (!cr6.eq) goto loc_8217A5D8;
	// li r10,80
	ctx.r10.s64 = 80;
	// b 0x8217a5e8
	goto loc_8217A5E8;
loc_8217A5D8:
	// li r10,40
	ctx.r10.s64 = 40;
loc_8217A5DC:
	// cmpwi cr6,r18,1
	cr6.compare<int32_t>(r18.s32, 1, xer);
	// li r11,16
	r11.s64 = 16;
	// ble cr6,0x8217a5ec
	if (!cr6.gt) goto loc_8217A5EC;
loc_8217A5E8:
	// li r11,8
	r11.s64 = 8;
loc_8217A5EC:
	// clrlwi r9,r31,31
	ctx.r9.u64 = r31.u32 & 0x1;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8217a680
	if (cr6.eq) goto loc_8217A680;
	// addi r9,r25,31
	ctx.r9.s64 = r25.s64 + 31;
	// rlwinm r5,r10,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0xFFFFFC00;
	// rlwinm r4,r9,0,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFE0;
	// li r9,160
	ctx.r9.s64 = 160;
	// divw r3,r4,r11
	ctx.r3.s32 = ctx.r4.s32 / r11.s32;
	// rotlwi r7,r4,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// divw r10,r5,r3
	ctx.r10.s32 = ctx.r5.s32 / ctx.r3.s32;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// divwu r10,r10,r9
	ctx.r10.u32 = ctx.r10.u32 / ctx.r9.u32;
	// andc r31,r11,r7
	r31.u64 = r11.u64 & ~ctx.r7.u64;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// twllei r11,0
	// add r11,r10,r6
	r11.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r4,r27,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r11,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// rotlwi r5,r5,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// subf r11,r4,r7
	r11.s64 = ctx.r7.s64 - ctx.r4.s64;
	// addi r10,r5,-1
	ctx.r10.s64 = ctx.r5.s64 + -1;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// subf r6,r27,r7
	ctx.r6.s64 = ctx.r7.s64 - r27.s64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// andc r5,r3,r10
	ctx.r5.u64 = ctx.r3.u64 & ~ctx.r10.u64;
	// rotlwi r10,r4,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// divw r11,r4,r6
	r11.s32 = ctx.r4.s32 / ctx.r6.s32;
	// twllei r3,0
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// stw r11,-104(r16)
	PPC_STORE_U32(r16.u32 + -104, r11.u32);
	// twlgei r31,-1
	// andc r11,r6,r3
	r11.u64 = ctx.r6.u64 & ~ctx.r3.u64;
	// twllei r6,0
	// twlgei r5,-1
	// twlgei r11,-1
	// b 0x8217a700
	goto loc_8217A700;
loc_8217A680:
	// addi r8,r28,159
	ctx.r8.s64 = r28.s64 + 159;
	// li r9,160
	ctx.r9.s64 = 160;
	// rlwinm r5,r11,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// divwu r11,r8,r9
	r11.u32 = ctx.r8.u32 / ctx.r9.u32;
	// rlwinm r4,r27,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r6,r5,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// twllei r10,0
	// rlwinm r3,r3,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// divw r31,r3,r10
	r31.s32 = ctx.r3.s32 / ctx.r10.s32;
	// rotlwi r11,r3,1
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// divw r8,r5,r31
	ctx.r8.s32 = ctx.r5.s32 / r31.s32;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// rlwinm r8,r8,0,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFE0;
	// andc r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 & ~ctx.r5.u64;
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// subf r5,r27,r8
	ctx.r5.s64 = ctx.r8.s64 - r27.s64;
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// andc r4,r31,r6
	ctx.r4.u64 = r31.u64 & ~ctx.r6.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// twllei r31,0
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r11,r11,r5
	r11.s32 = r11.s32 / ctx.r5.s32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// twlgei r3,-1
	// stw r11,-104(r16)
	PPC_STORE_U32(r16.u32 + -104, r11.u32);
	// andc r6,r5,r10
	ctx.r6.u64 = ctx.r5.u64 & ~ctx.r10.u64;
	// twllei r5,0
	// twlgei r4,-1
	// twlgei r6,-1
loc_8217A700:
	// addi r11,r7,159
	r11.s64 = ctx.r7.s64 + 159;
	// addi r10,r8,31
	ctx.r10.s64 = ctx.r8.s64 + 31;
	// divwu r11,r11,r9
	r11.u32 = r11.u32 / ctx.r9.u32;
	// rlwinm r26,r10,0,0,26
	r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFE0;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r21,r15
	r21.u64 = r15.u64;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
	// rlwinm r24,r9,5,0,26
	r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
loc_8217A724:
	// addi r29,r20,384
	r29.s64 = r20.s64 + 384;
	// lis r23,-32124
	r23.s64 = -2105278464;
	// lis r22,-32124
	r22.s64 = -2105278464;
	// lwzx r30,r31,r29
	r30.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8217a7ac
	if (cr6.eq) goto loc_8217A7AC;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x8217a864
	if (cr6.eq) goto loc_8217A864;
	// addi r11,r16,-136
	r11.s64 = r16.s64 + -136;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// bne cr6,0x8217a798
	if (!cr6.eq) goto loc_8217A798;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217A768;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r24
	cr6.compare<int32_t>(ctx.r3.s32, r24.s32, xer);
	// bne cr6,0x8217a798
	if (!cr6.eq) goto loc_8217A798;
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217A784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r26
	cr6.compare<int32_t>(ctx.r3.s32, r26.s32, xer);
	// bne cr6,0x8217a798
	if (!cr6.eq) goto loc_8217A798;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// cmpw cr6,r11,r19
	cr6.compare<int32_t>(r11.s32, r19.s32, xer);
	// beq cr6,0x8217a864
	if (cr6.eq) goto loc_8217A864;
loc_8217A798:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// cmpwi cr6,r31,32
	cr6.compare<int32_t>(r31.s32, 32, xer);
	// blt cr6,0x8217a724
	if (cr6.lt) goto loc_8217A724;
	// b 0x8217a86c
	goto loc_8217A86C;
loc_8217A7AC:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82180430
	ctx.lr = 0x8217A7B8;
	sub_82180430(ctx, base);
	// lwz r3,-25232(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -25232);
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// stb r15,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r15.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r15,168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 168, r15.u8);
	// stw r11,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r11.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stb r10,178(r1)
	PPC_STORE_U8(ctx.r1.u32 + 178, ctx.r10.u8);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stw r15,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r15.u32);
	// addi r4,r8,-27860
	ctx.r4.s64 = ctx.r8.s64 + -27860;
	// li r8,32
	ctx.r8.s64 = 32;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217A804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,-27692(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + -27692);
	// addi r8,r20,416
	ctx.r8.s64 = r20.s64 + 416;
	// lwz r11,-25232(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -25232);
	// rlwinm r31,r21,2,0,29
	r31.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r3,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r3.u32);
	// stw r19,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r19.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stw r10,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r10.u32);
	// addi r4,r7,-27880
	ctx.r4.s64 = ctx.r7.s64 + -27880;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,56(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 56);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217A854;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r20,384
	ctx.r9.s64 = r20.s64 + 384;
	// addi r8,r16,-136
	ctx.r8.s64 = r16.s64 + -136;
	// stwx r3,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r3.u32);
	// stwx r18,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r18.u32);
loc_8217A864:
	// cmpwi cr6,r21,8
	cr6.compare<int32_t>(r21.s32, 8, xer);
	// blt cr6,0x8217a87c
	if (cr6.lt) goto loc_8217A87C;
loc_8217A86C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r11,-27984
	ctx.r3.s64 = r11.s64 + -27984;
	// bl 0x821bd618
	ctx.lr = 0x8217A87C;
	sub_821BD618(ctx, base);
loc_8217A87C:
	// lwz r11,396(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lwz r8,-104(r16)
	ctx.r8.u64 = PPC_LOAD_U32(r16.u32 + -104);
	// stw r17,448(r20)
	PPC_STORE_U32(r20.u32 + 448, r17.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r11,452(r20)
	PPC_STORE_U32(r20.u32 + 452, r11.u32);
	// ble cr6,0x8217a91c
	if (!cr6.gt) goto loc_8217A91C;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r20,4
	r11.s64 = r20.s64 + 4;
loc_8217A8A0:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// beq cr6,0x8217a8dc
	if (cr6.eq) goto loc_8217A8DC;
	// subf r6,r27,r24
	ctx.r6.s64 = r24.s64 - r27.s64;
	// stw r15,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r15.u32);
	// mullw r9,r10,r6
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// mullw r4,r5,r6
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// stw r4,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r4.u32);
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + r27.u64;
	// cmpw cr6,r28,r9
	cr6.compare<int32_t>(r28.s32, ctx.r9.s32, xer);
	// bge cr6,0x8217a8d0
	if (!cr6.lt) goto loc_8217A8D0;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
loc_8217A8D0:
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r25,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r25.u32);
	// b 0x8217a908
	goto loc_8217A908;
loc_8217A8DC:
	// subf r6,r27,r26
	ctx.r6.s64 = r26.s64 - r27.s64;
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// stw r15,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, r15.u32);
	// mullw r9,r10,r6
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// mullw r4,r5,r6
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + r27.u64;
	// cmpw cr6,r25,r9
	cr6.compare<int32_t>(r25.s32, ctx.r9.s32, xer);
	// bge cr6,0x8217a904
	if (!cr6.lt) goto loc_8217A904;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
loc_8217A904:
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
loc_8217A908:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x8217a8a0
	if (cr6.lt) goto loc_8217A8A0;
loc_8217A91C:
	// lis r29,-32124
	r29.s64 = -2105278464;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-28076(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -28076);
	// bl 0x82415d78
	ctx.lr = 0x8217A92C;
	sub_82415D78(ctx, base);
	// addi r30,r20,384
	r30.s64 = r20.s64 + 384;
	// lwz r4,-27692(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + -27692);
	// rlwinm r31,r21,2,0,29
	r31.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x82183c40
	ctx.lr = 0x8217A940;
	sub_82183C40(ctx, base);
	// addi r11,r20,416
	r11.s64 = r20.s64 + 416;
	// lwz r3,-25232(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -25232);
	// lwzx r5,r31,r30
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwzx r6,r31,r11
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8217A974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,8(r14)
	ctx.r9.u64 = PPC_LOAD_U16(r14.u32 + 8);
	// lwz r11,8(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 8);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lbz r5,8(r14)
	ctx.r5.u64 = PPC_LOAD_U8(r14.u32 + 8);
	// clrlwi r3,r9,24
	ctx.r3.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r6,r11,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// lwz r8,404(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// lfs f0,15364(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15364);
	f0.f64 = double(temp.f32);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// stw r28,17004(r4)
	PPC_STORE_U32(ctx.r4.u32 + 17004, r28.u32);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// stw r25,17008(r10)
	PPC_STORE_U32(ctx.r10.u32 + 17008, r25.u32);
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,120(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// beq cr6,0x8217aa3c
	if (cr6.eq) goto loc_8217AA3C;
	// lbz r11,20(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217aa34
	if (!cr6.eq) goto loc_8217AA34;
	// lbz r11,21(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 21);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217aa3c
	if (cr6.eq) goto loc_8217AA3C;
loc_8217AA34:
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// b 0x8217aa40
	goto loc_8217AA40;
loc_8217AA3C:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8217AA40:
	// lwz r11,296(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 296);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8217aa54
	if (cr6.eq) goto loc_8217AA54;
	// ori r4,r4,2
	ctx.r4.u64 = ctx.r4.u64 | 2;
loc_8217AA54:
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8217aa64
	if (cr6.eq) goto loc_8217AA64;
	// ori r4,r4,4
	ctx.r4.u64 = ctx.r4.u64 | 4;
loc_8217AA64:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// ori r9,r10,407
	ctx.r9.u64 = ctx.r10.u64 | 407;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x8217aa88
	if (!cr6.eq) goto loc_8217AA88;
	// lfs f0,0(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 - f0.f64));
	// b 0x8217aa8c
	goto loc_8217AA8C;
loc_8217AA88:
	// lfs f1,0(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
loc_8217AA8C:
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// lwz r9,12(r14)
	ctx.r9.u64 = PPC_LOAD_U32(r14.u32 + 12);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwz r5,-104(r16)
	ctx.r5.u64 = PPC_LOAD_U32(r16.u32 + -104);
	// lwz r3,-28076(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -28076);
	// bl 0x8241be78
	ctx.lr = 0x8217AAA4;
	sub_8241BE78(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-28076(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -28076);
	// bl 0x82416540
	ctx.lr = 0x8217AAB0;
	sub_82416540(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8217AABC"))) PPC_WEAK_FUNC(sub_8217AABC);
PPC_FUNC_IMPL(__imp__sub_8217AABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217AAC0"))) PPC_WEAK_FUNC(sub_8217AAC0);
PPC_FUNC_IMPL(__imp__sub_8217AAC0) {
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
	ctx.lr = 0x8217AAC8;
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bgt cr6,0x8217aae8
	if (cr6.gt) goto loc_8217AAE8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x823d923c
	return;
loc_8217AAE8:
	// bl 0x821bbea8
	ctx.lr = 0x8217AAEC;
	sub_821BBEA8(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8217AAF4;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821bbf00
	ctx.lr = 0x8217AAFC;
	sub_821BBF00(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// ble cr6,0x8217abd4
	if (!cr6.gt) goto loc_8217ABD4;
	// lis r5,-32131
	ctx.r5.s64 = -2105737216;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r10,r1,98
	ctx.r10.s64 = ctx.r1.s64 + 98;
	// addi r11,r29,16
	r11.s64 = r29.s64 + 16;
	// mr r28,r30
	r28.u64 = r30.u64;
	// addi r4,r5,17136
	ctx.r4.s64 = ctx.r5.s64 + 17136;
	// addi r3,r8,17072
	ctx.r3.s64 = ctx.r8.s64 + 17072;
loc_8217AB4C:
	// lwz r8,-16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// cmplw cr6,r6,r8
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, xer);
	// beq cr6,0x8217ab70
	if (cr6.eq) goto loc_8217AB70;
	// addi r9,r8,2
	ctx.r9.s64 = ctx.r8.s64 + 2;
	// lhz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// sthx r5,r8,r31
	PPC_STORE_U16(ctx.r8.u32 + r31.u32, ctx.r5.u16);
loc_8217AB70:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lwz r29,-12(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// rlwinm r27,r8,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r26,-16(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// lwz r25,-8(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lbzx r5,r29,r4
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + ctx.r4.u32);
	// lwzx r8,r27,r3
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// stb r7,6(r10)
	PPC_STORE_U8(ctx.r10.u32 + 6, ctx.r7.u8);
	// sth r26,-2(r10)
	PPC_STORE_U16(ctx.r10.u32 + -2, r26.u16);
	// stb r25,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r25.u8);
	// stb r5,7(r10)
	PPC_STORE_U8(ctx.r10.u32 + 7, ctx.r5.u8);
	// stw r8,2(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2, ctx.r8.u32);
	// bne cr6,0x8217abc4
	if (!cr6.eq) goto loc_8217ABC4;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
loc_8217ABC4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r11,r11,28
	r11.s64 = r11.s64 + 28;
	// bne 0x8217ab4c
	if (!cr0.eq) goto loc_8217AB4C;
loc_8217ABD4:
	// li r11,255
	r11.s64 = 255;
	// sth r7,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r7.u16);
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// stb r7,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r7.u8);
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r28,r10
	ctx.r6.u64 = r28.u64 + ctx.r10.u64;
	// li r11,-1
	r11.s64 = -1;
	// stb r7,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, ctx.r7.u8);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r7,90(r1)
	PPC_STORE_U8(ctx.r1.u32 + 90, ctx.r7.u8);
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r5,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r5.u32);
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// bl 0x82417f90
	ctx.lr = 0x8217AC20;
	sub_82417F90(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8217AC30"))) PPC_WEAK_FUNC(sub_8217AC30);
PPC_FUNC_IMPL(__imp__sub_8217AC30) {
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
	ctx.lr = 0x8217AC38;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,56
	ctx.r9.s64 = 56;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// addi r28,r11,17064
	r28.s64 = r11.s64 + 17064;
	// addi r3,r8,-27172
	ctx.r3.s64 = ctx.r8.s64 + -27172;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,100(r28)
	PPC_STORE_U32(r28.u32 + 100, r11.u32);
	// bl 0x821c0750
	ctx.lr = 0x8217AC64;
	sub_821C0750(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8217ac7c
	if (cr6.eq) goto loc_8217AC7C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// stw r11,16988(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16988, r11.u32);
loc_8217AC7C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bcd84
	ctx.lr = 0x8217AC84;
	__imp__XGetVideoMode(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-27316
	ctx.r10.s64 = r11.s64 + -27316;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217acac
	if (cr6.eq) goto loc_8217ACAC;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r4,r11,-27692
	ctx.r4.s64 = r11.s64 + -27692;
	// addi r3,r10,-27576
	ctx.r3.s64 = ctx.r10.s64 + -27576;
	// bl 0x821c0750
	ctx.lr = 0x8217ACAC;
	sub_821C0750(ctx, base);
loc_8217ACAC:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r31,r11,17004
	r31.s64 = r11.s64 + 17004;
	// addi r3,r10,-27596
	ctx.r3.s64 = ctx.r10.s64 + -27596;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c0750
	ctx.lr = 0x8217ACC4;
	sub_821C0750(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r29,r11,17008
	r29.s64 = r11.s64 + 17008;
	// addi r3,r9,-27416
	ctx.r3.s64 = ctx.r9.s64 + -27416;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c0750
	ctx.lr = 0x8217ACDC;
	sub_821C0750(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lis r8,14
	ctx.r8.s64 = 917504;
	// addi r30,r11,-28224
	r30.s64 = r11.s64 + -28224;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r7,r8,4096
	ctx.r7.u64 = ctx.r8.u64 | 4096;
	// stw r10,484(r30)
	PPC_STORE_U32(r30.u32 + 484, ctx.r10.u32);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mullw r6,r10,r11
	ctx.r6.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// stw r11,500(r30)
	PPC_STORE_U32(r30.u32 + 500, r11.u32);
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// bgt cr6,0x8217ad30
	if (cr6.gt) goto loc_8217AD30;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x8217ad1c
	if (!cr6.eq) goto loc_8217AD1C;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_8217AD1C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8217ad6c
	if (!cr6.eq) goto loc_8217AD6C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// b 0x8217ad68
	goto loc_8217AD68;
loc_8217AD30:
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x8217ad4c
	if (!cr6.eq) goto loc_8217AD4C;
	// cmplwi cr6,r11,1280
	cr6.compare<uint32_t>(r11.u32, 1280, xer);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// blt cr6,0x8217ad48
	if (cr6.lt) goto loc_8217AD48;
	// li r9,1280
	ctx.r9.s64 = 1280;
loc_8217AD48:
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_8217AD4C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8217ad6c
	if (!cr6.eq) goto loc_8217AD6C;
	// cmplwi cr6,r10,720
	cr6.compare<uint32_t>(ctx.r10.u32, 720, xer);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// blt cr6,0x8217ad68
	if (cr6.lt) goto loc_8217AD68;
	// li r11,720
	r11.s64 = 720;
loc_8217AD68:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8217AD6C:
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// lbz r4,528(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 528);
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,17012(r8)
	PPC_STORE_U32(ctx.r8.u32 + 17012, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,17016(r7)
	PPC_STORE_U32(ctx.r7.u32 + 17016, r11.u32);
	// li r11,1
	r11.s64 = 1;
	// stb r10,2745(r6)
	PPC_STORE_U8(ctx.r6.u32 + 2745, ctx.r10.u8);
	// lis r3,-32131
	ctx.r3.s64 = -2105737216;
	// stb r9,2744(r5)
	PPC_STORE_U8(ctx.r5.u32 + 2744, ctx.r9.u8);
	// stw r11,524(r30)
	PPC_STORE_U32(r30.u32 + 524, r11.u32);
	// lwz r3,17020(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 17020);
	// bl 0x82179ba0
	ctx.lr = 0x8217ADAC;
	sub_82179BA0(ctx, base);
	// bl 0x821785d0
	ctx.lr = 0x8217ADB0;
	sub_821785D0(ctx, base);
	// lbz r11,428(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 428);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217adc4
	if (cr6.eq) goto loc_8217ADC4;
	// li r6,1
	ctx.r6.s64 = 1;
loc_8217ADC4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-27356
	ctx.r10.s64 = r11.s64 + -27356;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217addc
	if (cr6.eq) goto loc_8217ADDC;
	// ori r6,r6,8
	ctx.r6.u64 = ctx.r6.u64 | 8;
loc_8217ADDC:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r9,r10,-27336
	ctx.r9.s64 = ctx.r10.s64 + -27336;
	// addi r31,r11,-28076
	r31.s64 = r11.s64 + -28076;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217ae20
	if (!cr6.eq) goto loc_8217AE20;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r5,2752(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 2752);
	// bl 0x82413588
	ctx.lr = 0x8217AE14;
	sub_82413588(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bge cr6,0x8217ae24
	if (!cr6.lt) goto loc_8217AE24;
loc_8217AE20:
	// li r11,1
	r11.s64 = 1;
loc_8217AE24:
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// cntlzw r9,r28
	ctx.r9.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// rlwinm r29,r9,27,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// stw r11,-28092(r10)
	PPC_STORE_U32(ctx.r10.u32 + -28092, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r5,-27744
	ctx.r8.s64 = ctx.r5.s64 + -27744;
	// stb r29,16986(r6)
	PPC_STORE_U8(ctx.r6.u32 + 16986, r29.u8);
	// li r6,8
	ctx.r6.s64 = 8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82413588
	ctx.lr = 0x8217AE64;
	sub_82413588(ctx, base);
	// lis r4,-32131
	ctx.r4.s64 = -2105737216;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stb r29,16987(r4)
	PPC_STORE_U8(ctx.r4.u32 + 16987, r29.u8);
	// beq cr6,0x8217ae80
	if (cr6.eq) goto loc_8217AE80;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-27760
	ctx.r3.s64 = r11.s64 + -27760;
	// bl 0x821bd618
	ctx.lr = 0x8217AE80;
	sub_821BD618(ctx, base);
loc_8217AE80:
	// bl 0x821784b8
	ctx.lr = 0x8217AE84;
	sub_821784B8(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,-28080(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -28080);
	// bl 0x82416ca8
	ctx.lr = 0x8217AE98;
	sub_82416CA8(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,-27812(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27812);
	// bl 0x824169d0
	ctx.lr = 0x8217AEA8;
	sub_824169D0(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-27016
	ctx.r3.s64 = r11.s64 + -27016;
	// lwz r11,-26932(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26932);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8217af58
	if (!cr6.eq) goto loc_8217AF58;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// li r8,6
	ctx.r8.s64 = 6;
	// stw r7,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// li r7,9
	ctx.r7.s64 = 9;
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r7,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r7.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r7,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r7.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// sth r9,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, ctx.r9.u16);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// stw r8,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r7,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r7.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// sth r8,52(r3)
	PPC_STORE_U16(ctx.r3.u32 + 52, ctx.r8.u16);
	// stw r9,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r9.u32);
	// stw r8,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r8.u32);
	// stw r11,-26932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -26932, r11.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// stw r8,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r8.u32);
	// sth r7,80(r3)
	PPC_STORE_U16(ctx.r3.u32 + 80, ctx.r7.u16);
loc_8217AF58:
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r31,r9,-27128
	r31.s64 = ctx.r9.s64 + -27128;
	// bne cr6,0x8217b034
	if (!cr6.eq) goto loc_8217B034;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-26932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -26932, r11.u32);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// li r11,2
	r11.s64 = 2;
	// sth r10,24(r31)
	PPC_STORE_U16(r31.u32 + 24, ctx.r10.u16);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// li r11,6
	r11.s64 = 6;
	// stw r10,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r10.u32);
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r10,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// sth r9,52(r31)
	PPC_STORE_U16(r31.u32 + 52, ctx.r9.u16);
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r9,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r9.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,80(r31)
	PPC_STORE_U16(r31.u32 + 80, r11.u16);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r9,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r9.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// sth r10,108(r31)
	PPC_STORE_U16(r31.u32 + 108, ctx.r10.u16);
loc_8217B034:
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8217aac0
	ctx.lr = 0x8217B03C;
	sub_8217AAC0(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r11,-27784(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27784, r11.u32);
	// bl 0x8217aac0
	ctx.lr = 0x8217B054;
	sub_8217AAC0(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// stw r3,-28088(r9)
	PPC_STORE_U32(ctx.r9.u32 + -28088, ctx.r3.u32);
	// bl 0x82130000
	ctx.lr = 0x8217B060;
	sub_82130000(ctx, base);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r31,r7,-27296
	r31.s64 = ctx.r7.s64 + -27296;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,17000(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17000);
	// bl 0x8218c760
	ctx.lr = 0x8217B07C;
	sub_8218C760(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-27772
	ctx.r4.s64 = ctx.r6.s64 + -27772;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218b688
	ctx.lr = 0x8217B090;
	sub_8218B688(ctx, base);
	// stw r3,476(r30)
	PPC_STORE_U32(r30.u32 + 476, ctx.r3.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-27784
	ctx.r4.s64 = ctx.r5.s64 + -27784;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218b688
	ctx.lr = 0x8217B0A8;
	sub_8218B688(ctx, base);
	// stw r3,424(r30)
	PPC_STORE_U32(r30.u32 + 424, ctx.r3.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,-27796
	ctx.r4.s64 = ctx.r4.s64 + -27796;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218b688
	ctx.lr = 0x8217B0C0;
	sub_8218B688(ctx, base);
	// stw r3,512(r30)
	PPC_STORE_U32(r30.u32 + 512, ctx.r3.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-27816
	ctx.r4.s64 = r11.s64 + -27816;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218b688
	ctx.lr = 0x8217B0D8;
	sub_8218B688(ctx, base);
	// stw r3,432(r30)
	PPC_STORE_U32(r30.u32 + 432, ctx.r3.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-27828
	ctx.r4.s64 = ctx.r10.s64 + -27828;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218b688
	ctx.lr = 0x8217B0F0;
	sub_8218B688(ctx, base);
	// stw r3,520(r30)
	PPC_STORE_U32(r30.u32 + 520, ctx.r3.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-27840
	ctx.r4.s64 = ctx.r9.s64 + -27840;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218a568
	ctx.lr = 0x8217B108;
	sub_8218A568(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// stw r3,-28096(r8)
	PPC_STORE_U32(ctx.r8.u32 + -28096, ctx.r3.u32);
	// bl 0x8217d7b0
	ctx.lr = 0x8217B114;
	sub_8217D7B0(ctx, base);
	// lis r28,-32131
	r28.s64 = -2105737216;
	// lwz r11,17160(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17160);
	// addi r7,r11,256
	ctx.r7.s64 = r11.s64 + 256;
	// rlwinm r3,r7,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x8217B128;
	sub_82130528(ctx, base);
	// lis r31,-32131
	r31.s64 = -2105737216;
	// stw r3,516(r30)
	PPC_STORE_U32(r30.u32 + 516, ctx.r3.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// lwz r11,29848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29848);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,29848(r31)
	PPC_STORE_U32(r31.u32 + 29848, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8217B144;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8217b1a4
	if (cr6.eq) goto loc_8217B1A4;
	// lis r26,-32131
	r26.s64 = -2105737216;
	// lwz r27,516(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 516);
	// li r6,1028
	ctx.r6.s64 = 1028;
	// lwz r28,17160(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 17160);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,17156(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17156);
	// bl 0x82132578
	ctx.lr = 0x8217B170;
	sub_82132578(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,17156(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 17156);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821d2208
	ctx.lr = 0x8217B18C;
	sub_821D2208(ctx, base);
	// lwz r11,29848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29848);
	// stw r3,408(r30)
	PPC_STORE_U32(r30.u32 + 408, ctx.r3.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,29848(r31)
	PPC_STORE_U32(r31.u32 + 29848, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_8217B1A4:
	// lwz r10,29848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 29848);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r11,408(r30)
	PPC_STORE_U32(r30.u32 + 408, r11.u32);
	// stw r10,29848(r31)
	PPC_STORE_U32(r31.u32 + 29848, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8217B1C0"))) PPC_WEAK_FUNC(sub_8217B1C0);
PPC_FUNC_IMPL(__imp__sub_8217B1C0) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8217B1C8;
	// stfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f29.u64);
	// stfd f30,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// bl 0x8217d9d8
	ctx.lr = 0x8217B1FC;
	sub_8217D9D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8217b268
	if (cr6.eq) goto loc_8217B268;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217B218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// fdivs f31,f30,f12
	f31.f64 = double(float(f30.f64 / ctx.f12.f64));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8217B24C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r5,r3
	ctx.r5.s64 = ctx.r3.s32;
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f11,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fdivs f13,f30,f9
	ctx.f13.f64 = double(float(f30.f64 / ctx.f9.f64));
	// b 0x8217b274
	goto loc_8217B274;
loc_8217B268:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fmr f31,f13
	f31.f64 = ctx.f13.f64;
loc_8217B274:
	// extsw r11,r27
	r11.s64 = r27.s32;
	// lwz r10,324(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// extsw r6,r30
	ctx.r6.s64 = r30.s32;
	// lwz r8,332(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// extsw r4,r25
	ctx.r4.s64 = r25.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// extsw r5,r24
	ctx.r5.s64 = r24.s32;
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// std r6,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r6.u64);
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// extsw r11,r26
	r11.s64 = r26.s32;
	// lfd f10,120(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// std r5,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r5.u64);
	// lfd f8,96(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r9,r28
	ctx.r9.s64 = r28.s32;
	// lfd f9,128(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// extsw r7,r29
	ctx.r7.s64 = r29.s32;
	// std r3,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r3.u64);
	// lfd f5,120(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f7,128(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// std r7,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f11,112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f1,f0
	ctx.f1.f64 = double(f0.s64);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fcfid f4,f8
	ctx.f4.f64 = double(ctx.f8.s64);
	// fcfid f3,f9
	ctx.f3.f64 = double(ctx.f9.s64);
	// fcfid f2,f5
	ctx.f2.f64 = double(ctx.f5.s64);
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// frsp f8,f4
	ctx.f8.f64 = double(float(ctx.f4.f64));
	// frsp f4,f3
	ctx.f4.f64 = double(float(ctx.f3.f64));
	// frsp f3,f2
	ctx.f3.f64 = double(float(ctx.f2.f64));
	// frsp f2,f1
	ctx.f2.f64 = double(float(ctx.f1.f64));
	// frsp f9,f6
	ctx.f9.f64 = double(float(ctx.f6.f64));
	// frsp f1,f12
	ctx.f1.f64 = double(float(ctx.f12.f64));
	// frsp f12,f11
	ctx.f12.f64 = double(float(ctx.f11.f64));
	// frsp f11,f10
	ctx.f11.f64 = double(float(ctx.f10.f64));
	// fmuls f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmuls f8,f4,f31
	ctx.f8.f64 = double(float(ctx.f4.f64 * f31.f64));
	// fsubs f4,f2,f0
	ctx.f4.f64 = double(float(ctx.f2.f64 - f0.f64));
	// fmuls f6,f9,f31
	ctx.f6.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fmuls f9,f3,f13
	ctx.f9.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fsubs f3,f1,f0
	ctx.f3.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsubs f2,f12,f0
	ctx.f2.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsubs f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 - f0.f64));
	// bl 0x8217a140
	ctx.lr = 0x8217B350;
	sub_8217A140(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f30,-88(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8217B364"))) PPC_WEAK_FUNC(sub_8217B364);
PPC_FUNC_IMPL(__imp__sub_8217B364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217B368"))) PPC_WEAK_FUNC(sub_8217B368);
PPC_FUNC_IMPL(__imp__sub_8217B368) {
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
	ctx.lr = 0x8217B370;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r9,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r9.u32);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8217b424
	if (cr6.eq) goto loc_8217B424;
loc_8217B39C:
	// addi r11,r1,228
	r11.s64 = ctx.r1.s64 + 228;
	// lhz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// lhz r9,6(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lhz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lbz r3,3(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 3);
	// add r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 + r11.u64;
	// lbz r4,2(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// add r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 + ctx.r10.u64;
	// lbz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// srawi r6,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r5.s32 >> 4;
	// srawi r5,r7,4
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 4;
	// srawi r7,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	ctx.r7.s64 = r11.s32 >> 4;
	// add r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 + ctx.r9.u64;
	// srawi r11,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	r11.s64 = ctx.r10.s32 >> 4;
	// add r10,r4,r8
	ctx.r10.u64 = ctx.r4.u64 + ctx.r8.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// add r6,r6,r27
	ctx.r6.u64 = ctx.r6.u64 + r27.u64;
	// add r5,r5,r28
	ctx.r5.u64 = ctx.r5.u64 + r28.u64;
	// add r4,r7,r27
	ctx.r4.u64 = ctx.r7.u64 + r27.u64;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x8217b1c0
	ctx.lr = 0x8217B414;
	sub_8217B1C0(ctx, base);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8217b39c
	if (!cr6.eq) goto loc_8217B39C;
loc_8217B424:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8217B430"))) PPC_WEAK_FUNC(sub_8217B430);
PPC_FUNC_IMPL(__imp__sub_8217B430) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8217B438;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r25,0
	r25.s64 = 0;
	// addi r22,r11,17164
	r22.s64 = r11.s64 + 17164;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r21,-32124
	r21.s64 = -2105278464;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// mr r26,r25
	r26.u64 = r25.u64;
	// lwz r11,-104(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -104);
	// addi r24,r10,-27776
	r24.s64 = ctx.r10.s64 + -27776;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8217b63c
	if (!cr6.gt) goto loc_8217B63C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r30,r24,-296
	r30.s64 = r24.s64 + -296;
	// mr r27,r25
	r27.u64 = r25.u64;
	// li r23,3
	r23.s64 = 3;
	// lfs f31,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f31.f64 = double(temp.f32);
	// lis r20,-32124
	r20.s64 = -2105278464;
	// addi r31,r11,17200
	r31.s64 = r11.s64 + 17200;
loc_8217B48C:
	// slw r4,r23,r27
	ctx.r4.u64 = r27.u8 & 0x20 ? 0 : (r23.u32 << (r27.u8 & 0x3F));
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// bl 0x8241bd08
	ctx.lr = 0x8217B498;
	sub_8241BD08(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lbz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r11,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r4,r9,24
	ctx.r4.u64 = ctx.r9.u32 & 0xFF;
	// std r8,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r8.u64);
	// lfd f11,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// fcfid f7,f0
	ctx.f7.f64 = double(f0.s64);
	// lwz r3,156(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 156);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// stw r7,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r6,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r6.u32);
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f6,f10
	ctx.f6.f64 = double(float(ctx.f10.f64));
	// fmuls f1,f5,f31
	ctx.f1.f64 = double(float(ctx.f5.f64 * f31.f64));
	// stfs f1,164(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmuls f0,f4,f31
	f0.f64 = double(float(ctx.f4.f64 * f31.f64));
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fmuls f13,f3,f31
	ctx.f13.f64 = double(float(ctx.f3.f64 * f31.f64));
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// fmuls f2,f6,f31
	ctx.f2.f64 = double(float(ctx.f6.f64 * f31.f64));
	// stfs f2,168(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// beq cr6,0x8217b574
	if (cr6.eq) goto loc_8217B574;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217B53C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82177b58
	ctx.lr = 0x8217B544;
	sub_82177B58(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82420ba8
	ctx.lr = 0x8217B574;
	sub_82420BA8(ctx, base);
loc_8217B574:
	// lwz r3,152(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8217b590
	if (cr6.eq) goto loc_8217B590;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x8217b5b4
	goto loc_8217B5B4;
loc_8217B590:
	// lwz r3,-25232(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -25232);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217B5A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8217B5B4:
	// bctrl 
	ctx.lr = 0x8217B5B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// lwz r10,-27692(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + -27692);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217b5d8
	if (cr6.eq) goto loc_8217B5D8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8217b5d8
	if (!cr6.eq) goto loc_8217B5D8;
	// li r4,256
	ctx.r4.s64 = 256;
	// b 0x8217b5e0
	goto loc_8217B5E0;
loc_8217B5D8:
	// neg r11,r10
	r11.s64 = -ctx.r10.s64;
	// rlwinm r4,r11,26,0,5
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0xFC000000;
loc_8217B5E0:
	// lbz r11,21(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 21);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217b5f0
	if (cr6.eq) goto loc_8217B5F0;
	// ori r4,r4,512
	ctx.r4.u64 = ctx.r4.u64 | 512;
loc_8217B5F0:
	// lfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82177b58
	ctx.lr = 0x8217B5F8;
	sub_82177B58(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82420ba8
	ctx.lr = 0x8217B624;
	sub_82420BA8(ctx, base);
	// lwz r11,-104(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -104);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,2
	r27.s64 = r27.s64 + 2;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8217b48c
	if (cr6.lt) goto loc_8217B48C;
loc_8217B63C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// bl 0x8241bd08
	ctx.lr = 0x8217B648;
	sub_8241BD08(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8241c308
	ctx.lr = 0x8217B670;
	sub_8241C308(ctx, base);
	// lwz r3,-25232(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -25232);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8217B690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,152(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217b798
	if (!cr6.eq) goto loc_8217B798;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8217b798
	if (!cr6.eq) goto loc_8217B798;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8217B6B8;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8217B6C4;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x8217B6D0;
	sub_8217F768(ctx, base);
	// lwz r3,-25232(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -25232);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217B6E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8217d9a0
	ctx.lr = 0x8217B6EC;
	sub_8217D9A0(ctx, base);
	// lwz r8,0(r13)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r7,56
	ctx.r7.s64 = 56;
	// lwz r9,0(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// lis r5,-32131
	ctx.r5.s64 = -2105737216;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwzx r11,r7,r8
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// lwz r6,17008(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 17008);
	// lwz r8,17016(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 17016);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// beq cr6,0x8217b724
	if (cr6.eq) goto loc_8217B724;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
loc_8217B724:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// lwz r5,17004(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17004);
	// lwz r7,17012(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17012);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// beq cr6,0x8217b74c
	if (cr6.eq) goto loc_8217B74C;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
loc_8217B74C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217b1c0
	ctx.lr = 0x8217B774;
	sub_8217B1C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8217B780;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8217B78C;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x8217B798;
	sub_8217F768(ctx, base);
loc_8217B798:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,-104(r22)
	PPC_STORE_U32(r22.u32 + -104, r11.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8217B7AC"))) PPC_WEAK_FUNC(sub_8217B7AC);
PPC_FUNC_IMPL(__imp__sub_8217B7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217B7B0"))) PPC_WEAK_FUNC(sub_8217B7B0);
PPC_FUNC_IMPL(__imp__sub_8217B7B0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8217B7B8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x8217B7C4;
	sub_82130000(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r29,r11,-27296
	r29.s64 = r11.s64 + -27296;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r29,48
	ctx.r4.s64 = r29.s64 + 48;
	// lwz r5,-28096(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28096);
	// lwz r11,11724(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11724);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,11724(r10)
	PPC_STORE_U32(ctx.r10.u32 + 11724, r11.u32);
	// bl 0x82189ce0
	ctx.lr = 0x8217B7F4;
	sub_82189CE0(ctx, base);
	// lis r31,-32124
	r31.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82415ee8
	ctx.lr = 0x8217B804;
	sub_82415EE8(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82415dc8
	ctx.lr = 0x8217B820;
	sub_82415DC8(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82415dc8
	ctx.lr = 0x8217B83C;
	sub_82415DC8(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82415dc8
	ctx.lr = 0x8217B858;
	sub_82415DC8(ctx, base);
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82415dc8
	ctx.lr = 0x8217B874;
	sub_82415DC8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82417c70
	ctx.lr = 0x8217B880;
	sub_82417C70(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x824179b8
	ctx.lr = 0x8217B88C;
	sub_824179B8(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// mr r30,r28
	r30.u64 = r28.u64;
	// rldicr r27,r11,63,63
	r27.u64 = __builtin_rotateleft64(r11.u64, 63) & 0xFFFFFFFFFFFFFFFF;
loc_8217B89C:
	// addi r11,r30,32
	r11.s64 = r30.s64 + 32;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r5,0
	ctx.r5.s64 = 0;
	// clrldi r10,r11,32
	ctx.r10.u64 = r11.u64 & 0xFFFFFFFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// srd r6,r27,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x40 ? 0 : (r27.u64 >> (ctx.r10.u8 & 0x7F));
	// bl 0x82410f88
	ctx.lr = 0x8217B8B8;
	sub_82410F88(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r30,19
	cr6.compare<uint32_t>(r30.u32, 19, xer);
	// ble cr6,0x8217b89c
	if (!cr6.gt) goto loc_8217B89C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82417e88
	ctx.lr = 0x8217B8D0;
	sub_82417E88(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r30,r11,-27624
	r30.s64 = r11.s64 + -27624;
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r28,-148(r30)
	PPC_STORE_U32(r30.u32 + -148, r28.u32);
	// stw r28,-144(r30)
	PPC_STORE_U32(r30.u32 + -144, r28.u32);
	// stw r28,-140(r30)
	PPC_STORE_U32(r30.u32 + -140, r28.u32);
	// stw r28,-136(r30)
	PPC_STORE_U32(r30.u32 + -136, r28.u32);
	// stw r11,-112(r30)
	PPC_STORE_U32(r30.u32 + -112, r11.u32);
	// bl 0x8218baa0
	ctx.lr = 0x8217B8FC;
	sub_8218BAA0(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// addi r27,r11,-27732
	r27.s64 = r11.s64 + -27732;
	// mr r26,r28
	r26.u64 = r28.u64;
	// lwz r11,17060(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17060);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8217b95c
	if (!cr6.gt) goto loc_8217B95C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8217b950
	if (cr6.eq) goto loc_8217B950;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217B938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-27788(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -27788);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r8,r9,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// cmplw cr6,r3,r8
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r8.u32, xer);
	// beq cr6,0x8217b954
	if (cr6.eq) goto loc_8217B954;
loc_8217B950:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8217B954:
	// clrlwi r26,r11,24
	r26.u64 = r11.u32 & 0xFF;
	// bl 0x8217b430
	ctx.lr = 0x8217B95C;
	sub_8217B430(ctx, base);
loc_8217B95C:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217bb10
	if (!cr6.eq) goto loc_8217BB10;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8217ba84
	if (cr6.eq) goto loc_8217BA84;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r10,8(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rlwinm r5,r10,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// rlwinm r4,r10,8,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// rlwinm r3,r10,16,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFF;
	// lwz r11,-28080(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28080);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// std r4,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r4.u64);
	// std r3,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r3.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lfd f12,120(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// std r6,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r6.u64);
	// lfd f11,112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lfd f10,120(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// lis r7,6690
	ctx.r7.s64 = 438435840;
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lfs f0,15364(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15364);
	f0.f64 = double(temp.f32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// ori r5,r7,447
	ctx.r5.u64 = ctx.r7.u64 | 447;
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// li r4,768
	ctx.r4.s64 = 768;
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,136(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmpw cr6,r3,r5
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r5.s32, xer);
	// bne cr6,0x8217ba24
	if (!cr6.eq) goto loc_8217BA24;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-27692(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27692);
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r9,r10,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFC000000;
	// ori r4,r9,768
	ctx.r4.u64 = ctx.r9.u64 | 768;
loc_8217BA24:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f1,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// ori r9,r10,407
	ctx.r9.u64 = ctx.r10.u64 | 407;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x8217ba4c
	if (!cr6.eq) goto loc_8217BA4C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 - ctx.f1.f64));
loc_8217BA4C:
	// lwz r11,-27788(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -27788);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r6,12(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// lwzx r6,r11,r27
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82420ba8
	ctx.lr = 0x8217BA80;
	sub_82420BA8(ctx, base);
	// b 0x8217bb10
	goto loc_8217BB10;
loc_8217BA84:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r9,r10,447
	ctx.r9.u64 = ctx.r10.u64 | 447;
	// lwz r11,-28080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28080);
	// lwz r8,40(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x8217bab4
	if (!cr6.eq) goto loc_8217BAB4;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-27692(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27692);
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r4,r10,26,0,5
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFC000000;
loc_8217BAB4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// ori r9,r10,407
	ctx.r9.u64 = ctx.r10.u64 | 407;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x8217bad8
	if (!cr6.eq) goto loc_8217BAD8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8217bae0
	goto loc_8217BAE0;
loc_8217BAD8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
loc_8217BAE0:
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-27788(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -27788);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r6,r11,r27
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82420ba8
	ctx.lr = 0x8217BB10;
	sub_82420BA8(ctx, base);
loc_8217BB10:
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82419e90
	ctx.lr = 0x8217BB18;
	sub_82419E90(ctx, base);
	// lwz r11,-27788(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -27788);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r27
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82419e98
	ctx.lr = 0x8217BB30;
	sub_82419E98(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r10,-27788(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -27788);
	// addi r8,r9,-27456
	ctx.r8.s64 = ctx.r9.s64 + -27456;
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r11,-27788(r29)
	PPC_STORE_U32(r29.u32 + -27788, r11.u32);
	// beq cr6,0x8217bb5c
	if (cr6.eq) goto loc_8217BB5C;
	// lwz r3,-28076(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -28076);
	// bl 0x82412990
	ctx.lr = 0x8217BB5C;
	sub_82412990(ctx, base);
loc_8217BB5C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8217BB64"))) PPC_WEAK_FUNC(sub_8217BB64);
PPC_FUNC_IMPL(__imp__sub_8217BB64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217BB68"))) PPC_WEAK_FUNC(sub_8217BB68);
PPC_FUNC_IMPL(__imp__sub_8217BB68) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-21092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21092);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217bba8
	if (!cr6.eq) goto loc_8217BBA8;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-21080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21080);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8217bbac
	if (cr6.eq) goto loc_8217BBAC;
loc_8217BBA8:
	// li r11,1
	r11.s64 = 1;
loc_8217BBAC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217bbd4
	if (!cr6.eq) goto loc_8217BBD4;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fed0
	ctx.lr = 0x8217BBC0;
	sub_8217FED0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// bl 0x821788b8
	ctx.lr = 0x8217BBD4;
	sub_821788B8(ctx, base);
loc_8217BBD4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-28088(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28088);
	// bl 0x82178430
	ctx.lr = 0x8217BBE0;
	sub_82178430(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82178480
	ctx.lr = 0x8217BBF0;
	sub_82178480(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-26904
	ctx.r9.s64 = ctx.r10.s64 + -26904;
	// stw r30,-26904(r10)
	PPC_STORE_U32(ctx.r10.u32 + -26904, r30.u32);
	// stw r3,-16(r9)
	PPC_STORE_U32(ctx.r9.u32 + -16, ctx.r3.u32);
	// stw r31,-8(r9)
	PPC_STORE_U32(ctx.r9.u32 + -8, r31.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
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

__attribute__((alias("__imp__sub_8217BC24"))) PPC_WEAK_FUNC(sub_8217BC24);
PPC_FUNC_IMPL(__imp__sub_8217BC24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217BC28"))) PPC_WEAK_FUNC(sub_8217BC28);
PPC_FUNC_IMPL(__imp__sub_8217BC28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r11,r11,-26900
	r11.s64 = r11.s64 + -26900;
	// lwz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r10,-20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -20);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8217bc58
	if (cr6.eq) goto loc_8217BC58;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8217bc58
	if (!cr6.eq) goto loc_8217BC58;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
loc_8217BC58:
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r10,-20(r11)
	PPC_STORE_U32(r11.u32 + -20, ctx.r10.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stfs f1,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f2,4(r7)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f3,8(r7)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// stfs f4,12(r7)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// stfs f5,16(r7)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r7.u32 + 16, temp.u32);
	// stfs f6,20(r7)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r7.u32 + 20, temp.u32);
	// stw r9,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, ctx.r9.u32);
	// stfs f7,28(r7)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r7.u32 + 28, temp.u32);
	// stfs f8,32(r7)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r7.u32 + 32, temp.u32);
	// blr 
	return;
}

