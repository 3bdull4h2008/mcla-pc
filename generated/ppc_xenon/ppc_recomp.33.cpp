#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82264524"))) PPC_WEAK_FUNC(sub_82264524);
PPC_FUNC_IMPL(__imp__sub_82264524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264528"))) PPC_WEAK_FUNC(sub_82264528);
PPC_FUNC_IMPL(__imp__sub_82264528) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-4944(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -4944);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226455c
	if (cr6.eq) goto loc_8226455C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82264268
	ctx.lr = 0x82264554;
	sub_82264268(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8226455C;
	sub_82130588(ctx, base);
loc_8226455C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-4944(r30)
	PPC_STORE_U32(r30.u32 + -4944, r11.u32);
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

__attribute__((alias("__imp__sub_8226457C"))) PPC_WEAK_FUNC(sub_8226457C);
PPC_FUNC_IMPL(__imp__sub_8226457C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264580"))) PPC_WEAK_FUNC(sub_82264580);
PPC_FUNC_IMPL(__imp__sub_82264580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,16
	r11.s64 = 16;
	// stw r11,256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 256, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226458C"))) PPC_WEAK_FUNC(sub_8226458C);
PPC_FUNC_IMPL(__imp__sub_8226458C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264590"))) PPC_WEAK_FUNC(sub_82264590);
PPC_FUNC_IMPL(__imp__sub_82264590) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82264598;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r6,2256
	ctx.r4.s64 = ctx.r6.s64 + 2256;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f0,208(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// stfs f0,212(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,128
	r27.s64 = ctx.r1.s64 + 128;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r3,-1
	ctx.r3.s64 = -1;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// sth r3,220(r1)
	PPC_STORE_U16(ctx.r1.u32 + 220, ctx.r3.u16);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// sth r11,222(r1)
	PPC_STORE_U16(ctx.r1.u32 + 222, r11.u16);
	// stb r11,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r11.u8);
	// lis r6,-32114
	ctx.r6.s64 = -2104623104;
	// sth r11,226(r1)
	PPC_STORE_U16(ctx.r1.u32 + 226, r11.u16);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r11.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r8,-1
	ctx.r8.s64 = -1;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,2048
	ctx.r7.s64 = 2048;
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-23452(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -23452);
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82574418
	ctx.lr = 0x82264684;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82264698
	if (cr6.eq) goto loc_82264698;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82264698:
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f31,12(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822646C8"))) PPC_WEAK_FUNC(sub_822646C8);
PPC_FUNC_IMPL(__imp__sub_822646C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822646E4"))) PPC_WEAK_FUNC(sub_822646E4);
PPC_FUNC_IMPL(__imp__sub_822646E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822646E8"))) PPC_WEAK_FUNC(sub_822646E8);
PPC_FUNC_IMPL(__imp__sub_822646E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r5,r11
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// lfs f1,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82264760"))) PPC_WEAK_FUNC(sub_82264760);
PPC_FUNC_IMPL(__imp__sub_82264760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32218
	r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,17808
	ctx.r3.s64 = r11.s64 + 17808;
	// b 0x822646e8
	sub_822646E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82264770"))) PPC_WEAK_FUNC(sub_82264770);
PPC_FUNC_IMPL(__imp__sub_82264770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32218
	r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,18120
	ctx.r3.s64 = r11.s64 + 18120;
	// b 0x822c9b10
	sub_822C9B10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82264780"))) PPC_WEAK_FUNC(sub_82264780);
PPC_FUNC_IMPL(__imp__sub_82264780) {
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
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,18272
	ctx.r4.s64 = r11.s64 + 18272;
	// addi r3,r10,-8360
	ctx.r3.s64 = ctx.r10.s64 + -8360;
	// bl 0x82554798
	ctx.lr = 0x822647A0;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,18288
	ctx.r4.s64 = ctx.r9.s64 + 18288;
	// addi r3,r8,-8384
	ctx.r3.s64 = ctx.r8.s64 + -8384;
	// bl 0x82554798
	ctx.lr = 0x822647B4;
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

__attribute__((alias("__imp__sub_822647C4"))) PPC_WEAK_FUNC(sub_822647C4);
PPC_FUNC_IMPL(__imp__sub_822647C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822647C8"))) PPC_WEAK_FUNC(sub_822647C8);
PPC_FUNC_IMPL(__imp__sub_822647C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822647D8"))) PPC_WEAK_FUNC(sub_822647D8);
PPC_FUNC_IMPL(__imp__sub_822647D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bne 0x8226481c
	if (!cr0.eq) goto loc_8226481C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82264808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_8226481C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82264830"))) PPC_WEAK_FUNC(sub_82264830);
PPC_FUNC_IMPL(__imp__sub_82264830) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822648c4
	if (!cr6.eq) goto loc_822648C4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-7976
	ctx.r3.s64 = r11.s64 + -7976;
	// bl 0x82478c30
	ctx.lr = 0x8226485C;
	sub_82478C30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822648c4
	if (cr6.eq) goto loc_822648C4;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// beq cr6,0x822648c4
	if (cr6.eq) goto loc_822648C4;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-7988
	ctx.r4.s64 = ctx.r10.s64 + -7988;
	// bl 0x8218a568
	ctx.lr = 0x82264888;
	sub_8218A568(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-8000
	ctx.r4.s64 = ctx.r8.s64 + -8000;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822648A4;
	sub_8218A568(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-8012
	ctx.r4.s64 = ctx.r6.s64 + -8012;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822648C0;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
loc_822648C4:
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

__attribute__((alias("__imp__sub_822648D8"))) PPC_WEAK_FUNC(sub_822648D8);
PPC_FUNC_IMPL(__imp__sub_822648D8) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82264950
	if (!cr6.eq) goto loc_82264950;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-7940
	ctx.r3.s64 = r11.s64 + -7940;
	// bl 0x82478c30
	ctx.lr = 0x82264904;
	sub_82478C30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264950
	if (cr6.eq) goto loc_82264950;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// beq cr6,0x82264948
	if (cr6.eq) goto loc_82264948;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-7952
	ctx.r4.s64 = ctx.r10.s64 + -7952;
	// bl 0x8218a568
	ctx.lr = 0x82264930;
	sub_8218A568(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
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
loc_82264948:
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_82264950:
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

__attribute__((alias("__imp__sub_82264964"))) PPC_WEAK_FUNC(sub_82264964);
PPC_FUNC_IMPL(__imp__sub_82264964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264968"))) PPC_WEAK_FUNC(sub_82264968);
PPC_FUNC_IMPL(__imp__sub_82264968) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82264970;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v58,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-7572(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7572);
	// stvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f5d98
	ctx.lr = 0x822649D4;
	sub_822F5D98(ctx, base);
	// lwz r3,-7572(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7572);
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f1688
	ctx.lr = 0x822649E0;
	sub_822F1688(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822649fc
	if (cr6.eq) goto loc_822649FC;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82264a04
	goto loc_82264A04;
loc_822649FC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82264A04:
	// lfs f12,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f11,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82264A44;
	sub_8218A6E0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82264A5C;
	sub_82189CE0(ctx, base);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82264a8c
	if (cr6.eq) goto loc_82264A8C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r10,80
	ctx.r6.s64 = ctx.r10.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82264A8C;
	sub_8218A6E0(ctx, base);
loc_82264A8C:
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82264abc
	if (cr6.eq) goto loc_82264ABC;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,-12556(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12556);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82264abc
	if (!cr6.lt) goto loc_82264ABC;
	// lfs f13,432(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 432);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,432(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 432, temp.u32);
loc_82264ABC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82264AC8"))) PPC_WEAK_FUNC(sub_82264AC8);
PPC_FUNC_IMPL(__imp__sub_82264AC8) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82264AD0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,128
	r29.s64 = ctx.r1.s64 + 128;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v58,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-7572(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7572);
	// stvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f5d98
	ctx.lr = 0x82264B34;
	sub_822F5D98(ctx, base);
	// lwz r3,-7572(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7572);
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f1688
	ctx.lr = 0x82264B40;
	sub_822F1688(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,240
	ctx.r6.s64 = 240;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,22080(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22080);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// lwz r10,-8092(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v56,r31,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfd f11,-7920(r3)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r3.u32 + -7920);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f10,-11620(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11620);
	ctx.f10.f64 = double(temp.f32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lvx128 v57,r11,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v55,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f9,f13,f13
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f13,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f7,f12,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fsub f5,f6,f11
	ctx.f5.f64 = ctx.f6.f64 - ctx.f11.f64;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f10.f64));
	// fsel f2,f3,f3,f0
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f3.f64 : f0.f64;
	// fsel f1,f3,f3,f0
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f3.f64 : f0.f64;
	// fsubs f0,f2,f31
	f0.f64 = double(float(ctx.f2.f64 - f31.f64));
	// fsel f13,f0,f31,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? f31.f64 : ctx.f1.f64;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// beq cr6,0x82264c04
	if (cr6.eq) goto loc_82264C04;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82264C04;
	sub_8218A6E0(ctx, base);
loc_82264C04:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82264c34
	if (cr6.eq) goto loc_82264C34;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,-12556(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12556);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82264c34
	if (!cr6.lt) goto loc_82264C34;
	// lfs f13,432(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 432);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,432(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 432, temp.u32);
loc_82264C34:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82264C40"))) PPC_WEAK_FUNC(sub_82264C40);
PPC_FUNC_IMPL(__imp__sub_82264C40) {
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
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264c64
	if (cr6.eq) goto loc_82264C64;
	// bl 0x8247a8d0
	ctx.lr = 0x82264C64;
	sub_8247A8D0(ctx, base);
loc_82264C64:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264c74
	if (cr6.eq) goto loc_82264C74;
	// bl 0x8247a8d0
	ctx.lr = 0x82264C74;
	sub_8247A8D0(ctx, base);
loc_82264C74:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r11.u32);
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

__attribute__((alias("__imp__sub_82264C90"))) PPC_WEAK_FUNC(sub_82264C90);
PPC_FUNC_IMPL(__imp__sub_82264C90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// li r6,64
	ctx.r6.s64 = 64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,80
	ctx.r7.s64 = 80;
	// li r10,96
	ctx.r10.s64 = 96;
	// li r11,144
	r11.s64 = 144;
	// lvx128 v63,r30,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,112
	ctx.r9.s64 = 112;
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,128
	ctx.r8.s64 = 128;
	// lvx128 v62,r30,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r7,r31,r30
	ctx.r7.s64 = r30.s64 - r31.s64;
	// lvx128 v61,r30,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r30,204
	ctx.r10.s64 = r30.s64 + 204;
	// lvx128 v60,r30,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,200
	r11.s64 = r31.s64 + 200;
	// lvx128 v59,r30,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,2
	ctx.r9.s64 = 2;
	// lvx128 v58,r30,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,160(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 160);
	// stb r8,160(r31)
	PPC_STORE_U8(r31.u32 + 160, ctx.r8.u8);
	// lbz r6,328(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 328);
	// stb r6,328(r31)
	PPC_STORE_U8(r31.u32 + 328, ctx.r6.u8);
	// lbz r5,329(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 329);
	// stb r5,329(r31)
	PPC_STORE_U8(r31.u32 + 329, ctx.r5.u8);
	// lbz r4,330(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 330);
	// stb r4,330(r31)
	PPC_STORE_U8(r31.u32 + 330, ctx.r4.u8);
	// lbz r3,331(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 331);
	// stb r3,331(r31)
	PPC_STORE_U8(r31.u32 + 331, ctx.r3.u8);
	// lfs f0,164(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 164);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lfs f13,168(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// lfs f12,176(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,176(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// lfs f11,180(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 180);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,180(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// lfs f10,188(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 188);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,188(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
loc_82264D54:
	// lwzx r8,r11,r7
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lfs f0,60(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// lwz r6,-204(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -204);
	// stw r6,-200(r11)
	PPC_STORE_U32(r11.u32 + -200, ctx.r6.u32);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
	// lfs f13,64(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,68(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// lwz r4,-200(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -200);
	// stw r4,-196(r11)
	PPC_STORE_U32(r11.u32 + -196, ctx.r4.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r3,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r3.u32);
	// lfs f12,68(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,72(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 72, temp.u32);
	// lwz r8,-196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -196);
	// stw r8,-192(r11)
	PPC_STORE_U32(r11.u32 + -192, ctx.r8.u32);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// lfs f11,72(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,76(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 76, temp.u32);
	// lwz r5,-192(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -192);
	// stw r5,-188(r11)
	PPC_STORE_U32(r11.u32 + -188, ctx.r5.u32);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// lfs f10,76(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,80(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
	// lwz r3,-188(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -188);
	// stw r3,-184(r11)
	PPC_STORE_U32(r11.u32 + -184, ctx.r3.u32);
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// lfs f9,80(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,84(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// lwz r6,-184(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -184);
	// stw r6,-180(r11)
	PPC_STORE_U32(r11.u32 + -180, ctx.r6.u32);
	// lwz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r5.u32);
	// lfs f8,84(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,88(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 88, temp.u32);
	// lwz r4,-180(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -180);
	// stw r4,-176(r11)
	PPC_STORE_U32(r11.u32 + -176, ctx.r4.u32);
	// lwz r3,24(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// stw r3,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r3.u32);
	// lfs f7,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,92(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 92, temp.u32);
	// lwz r8,-176(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -176);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stw r8,-172(r11)
	PPC_STORE_U32(r11.u32 + -172, ctx.r8.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x82264d54
	if (!cr0.eq) goto loc_82264D54;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264e34
	if (cr6.eq) goto loc_82264E34;
	// bl 0x8247a8d0
	ctx.lr = 0x82264E34;
	sub_8247A8D0(ctx, base);
loc_82264E34:
	// lwz r11,336(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 336);
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r11.u32);
	// beq cr6,0x82264e4c
	if (cr6.eq) goto loc_82264E4C;
	// bl 0x8247a8d0
	ctx.lr = 0x82264E4C;
	sub_8247A8D0(ctx, base);
loc_82264E4C:
	// lwz r11,340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 340);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r11.u32);
	// lwz r10,348(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 348);
	// stw r10,348(r31)
	PPC_STORE_U32(r31.u32 + 348, ctx.r10.u32);
	// lfs f0,172(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 172);
	f0.f64 = double(temp.f32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
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

__attribute__((alias("__imp__sub_82264E80"))) PPC_WEAK_FUNC(sub_82264E80);
PPC_FUNC_IMPL(__imp__sub_82264E80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91fc
	ctx.lr = 0x82264E88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-4336
	ctx.r4.s64 = r11.s64 + -4336;
	// bl 0x821c8fe0
	ctx.lr = 0x82264EA4;
	sub_821C8FE0(ctx, base);
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82264ef4
	if (cr6.eq) goto loc_82264EF4;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r8,r10,-12548
	ctx.r8.s64 = ctx.r10.s64 + -12548;
	// addi r7,r9,29952
	ctx.r7.s64 = ctx.r9.s64 + 29952;
	// lfs f12,-12548(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12548);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,464(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 464, temp.u32);
	// lfs f0,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r6,336(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// fmuls f13,f0,f12
	ctx.f13.f64 = double(float(f0.f64 * ctx.f12.f64));
	// stfs f13,468(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 468, temp.u32);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// bl 0x8247a8d0
	ctx.lr = 0x82264EF0;
	sub_8247A8D0(ctx, base);
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
loc_82264EF4:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264f08
	if (cr6.eq) goto loc_82264F08;
	// bl 0x8247a8d0
	ctx.lr = 0x82264F04;
	sub_8247A8D0(ctx, base);
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
loc_82264F08:
	// li r11,64
	r11.s64 = 64;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,112
	ctx.r10.s64 = 112;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r9,160(r31)
	PPC_STORE_U8(r31.u32 + 160, ctx.r9.u8);
	// stvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821c9030
	ctx.lr = 0x82264F30;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82264F38"))) PPC_WEAK_FUNC(sub_82264F38);
PPC_FUNC_IMPL(__imp__sub_82264F38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lbz r10,330(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 330);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82264f8c
	if (cr6.eq) goto loc_82264F8C;
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261be90
	ctx.lr = 0x82264F7C;
	sub_8261BE90(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82264F8C:
	// lfs f0,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82264FD0"))) PPC_WEAK_FUNC(sub_82264FD0);
PPC_FUNC_IMPL(__imp__sub_82264FD0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// li r11,112
	r11.s64 = 112;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r4,348(r31)
	PPC_STORE_U32(r31.u32 + 348, ctx.r4.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x822f1478
	ctx.lr = 0x82265020;
	sub_822F1478(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// lfs f0,11360(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11360);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x822f14c8
	ctx.lr = 0x82265044;
	sub_822F14C8(ctx, base);
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

__attribute__((alias("__imp__sub_8226505C"))) PPC_WEAK_FUNC(sub_8226505C);
PPC_FUNC_IMPL(__imp__sub_8226505C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265060"))) PPC_WEAK_FUNC(sub_82265060);
PPC_FUNC_IMPL(__imp__sub_82265060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r4,5
	ctx.r9.s64 = ctx.r4.s64 + 5;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r4,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r4.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82265074:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82265074
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82265074;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82265084"))) PPC_WEAK_FUNC(sub_82265084);
PPC_FUNC_IMPL(__imp__sub_82265084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265088"))) PPC_WEAK_FUNC(sub_82265088);
PPC_FUNC_IMPL(__imp__sub_82265088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r4,8
	ctx.r9.s64 = ctx.r4.s64 + 8;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r4,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r4.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8226509C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8226509c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8226509C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822650AC"))) PPC_WEAK_FUNC(sub_822650AC);
PPC_FUNC_IMPL(__imp__sub_822650AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822650B0"))) PPC_WEAK_FUNC(sub_822650B0);
PPC_FUNC_IMPL(__imp__sub_822650B0) {
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// beq cr6,0x822650e4
	if (cr6.eq) goto loc_822650E4;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822650E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822650E4:
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

__attribute__((alias("__imp__sub_822650FC"))) PPC_WEAK_FUNC(sub_822650FC);
PPC_FUNC_IMPL(__imp__sub_822650FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265100"))) PPC_WEAK_FUNC(sub_82265100);
PPC_FUNC_IMPL(__imp__sub_82265100) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x82265160
	if (cr6.eq) goto loc_82265160;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82265140
	if (cr6.eq) goto loc_82265140;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82265140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82265140:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82265160
	if (cr6.eq) goto loc_82265160;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82265160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82265160:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
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

__attribute__((alias("__imp__sub_8226517C"))) PPC_WEAK_FUNC(sub_8226517C);
PPC_FUNC_IMPL(__imp__sub_8226517C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265180"))) PPC_WEAK_FUNC(sub_82265180);
PPC_FUNC_IMPL(__imp__sub_82265180) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-7904
	ctx.r10.s64 = r11.s64 + -7904;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82619418
	ctx.lr = 0x822651AC;
	sub_82619418(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822651c4
	if (cr6.eq) goto loc_822651C4;
	// bl 0x82130588
	ctx.lr = 0x822651C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822651C4:
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

__attribute__((alias("__imp__sub_822651DC"))) PPC_WEAK_FUNC(sub_822651DC);
PPC_FUNC_IMPL(__imp__sub_822651DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822651E0"))) PPC_WEAK_FUNC(sub_822651E0);
PPC_FUNC_IMPL(__imp__sub_822651E0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-8032
	ctx.r10.s64 = r11.s64 + -8032;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82619418
	ctx.lr = 0x8226520C;
	sub_82619418(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82265224
	if (cr6.eq) goto loc_82265224;
	// bl 0x82130588
	ctx.lr = 0x82265220;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82265224:
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

__attribute__((alias("__imp__sub_8226523C"))) PPC_WEAK_FUNC(sub_8226523C);
PPC_FUNC_IMPL(__imp__sub_8226523C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265240"))) PPC_WEAK_FUNC(sub_82265240);
PPC_FUNC_IMPL(__imp__sub_82265240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82265264
	if (cr6.eq) goto loc_82265264;
	// bl 0x8247a8d0
	ctx.lr = 0x82265264;
	sub_8247A8D0(ctx, base);
loc_82265264:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82265274
	if (cr6.eq) goto loc_82265274;
	// bl 0x8247a8d0
	ctx.lr = 0x82265274;
	sub_8247A8D0(ctx, base);
loc_82265274:
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8226529c
	if (cr6.lt) goto loc_8226529C;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-7572(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f14c8
	ctx.lr = 0x8226529C;
	sub_822F14C8(ctx, base);
loc_8226529C:
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822652b8
	if (cr6.eq) goto loc_822652B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822652B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822652B8:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822652d4
	if (cr6.eq) goto loc_822652D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822652D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822652D4:
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

__attribute__((alias("__imp__sub_822652E8"))) PPC_WEAK_FUNC(sub_822652E8);
PPC_FUNC_IMPL(__imp__sub_822652E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-4336
	ctx.r4.s64 = r11.s64 + -4336;
	// bl 0x821c8fe0
	ctx.lr = 0x82265310;
	sub_821C8FE0(ctx, base);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r30,0
	r30.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r30,329(r31)
	PPC_STORE_U8(r31.u32 + 329, r30.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r10,328(r31)
	PPC_STORE_U8(r31.u32 + 328, ctx.r10.u8);
	// beq cr6,0x82265334
	if (cr6.eq) goto loc_82265334;
	// bl 0x8247a8d0
	ctx.lr = 0x82265330;
	sub_8247A8D0(ctx, base);
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
loc_82265334:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82265348
	if (cr6.eq) goto loc_82265348;
	// bl 0x8247a8d0
	ctx.lr = 0x82265344;
	sub_8247A8D0(ctx, base);
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
loc_82265348:
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r11.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82265378
	if (cr6.lt) goto loc_82265378;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-7572(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f14c8
	ctx.lr = 0x82265378;
	sub_822F14C8(ctx, base);
loc_82265378:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x82264830
	ctx.lr = 0x82265380;
	sub_82264830(ctx, base);
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// bl 0x822648d8
	ctx.lr = 0x82265388;
	sub_822648D8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82265390;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_822653A8"))) PPC_WEAK_FUNC(sub_822653A8);
PPC_FUNC_IMPL(__imp__sub_822653A8) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822653B0;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d8
	ctx.lr = 0x822653B8;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lbz r11,330(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 330);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822656f4
	if (cr6.eq) goto loc_822656F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r29,r31,64
	r29.s64 = r31.s64 + 64;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8261d980
	ctx.lr = 0x822653FC;
	sub_8261D980(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261d980
	ctx.lr = 0x82265410;
	sub_8261D980(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8261d980
	ctx.lr = 0x82265424;
	sub_8261D980(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8261d980
	ctx.lr = 0x82265438;
	sub_8261D980(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x8261b020
	ctx.lr = 0x82265458;
	sub_8261B020(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lfs f28,-9152(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -9152);
	f28.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f29,-9160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -9160);
	f29.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
	// beq cr6,0x822654a8
	if (cr6.eq) goto loc_822654A8;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x822654a8
	if (cr6.lt) goto loc_822654A8;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x822654a8
	if (cr6.gt) goto loc_822654A8;
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// blt cr6,0x822654a8
	if (cr6.lt) goto loc_822654A8;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x822654ac
	if (!cr6.gt) goto loc_822654AC;
loc_822654A8:
	// li r11,0
	r11.s64 = 0;
loc_822654AC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r26,96
	r26.s64 = 96;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226558c
	if (!cr6.eq) goto loc_8226558C;
	// lvx128 v63,r31,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v59,v61,v63
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261d980
	ctx.lr = 0x822654F0;
	sub_8261D980(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8261d980
	ctx.lr = 0x82265504;
	sub_8261D980(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261d980
	ctx.lr = 0x82265518;
	sub_8261D980(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8261d980
	ctx.lr = 0x8226552C;
	sub_8261D980(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x8261b020
	ctx.lr = 0x8226554C;
	sub_8261B020(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82265584
	if (cr6.eq) goto loc_82265584;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x82265584
	if (cr6.lt) goto loc_82265584;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x82265584
	if (cr6.gt) goto loc_82265584;
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// blt cr6,0x82265584
	if (cr6.lt) goto loc_82265584;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x82265588
	if (!cr6.gt) goto loc_82265588;
loc_82265584:
	// li r11,0
	r11.s64 = 0;
loc_82265588:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8226558C:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82265668
	if (!cr6.eq) goto loc_82265668;
	// lvx128 v58,r31,r26
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lvx128 v56,r0,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// vsubfp128 v54,v56,v58
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v58.f32)));
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261d980
	ctx.lr = 0x822655CC;
	sub_8261D980(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8261d980
	ctx.lr = 0x822655E0;
	sub_8261D980(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261d980
	ctx.lr = 0x822655F4;
	sub_8261D980(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8261d980
	ctx.lr = 0x82265608;
	sub_8261D980(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x8261b020
	ctx.lr = 0x82265628;
	sub_8261B020(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82265660
	if (cr6.eq) goto loc_82265660;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x82265660
	if (cr6.lt) goto loc_82265660;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x82265660
	if (cr6.gt) goto loc_82265660;
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// blt cr6,0x82265660
	if (cr6.lt) goto loc_82265660;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x82265664
	if (!cr6.gt) goto loc_82265664;
loc_82265660:
	// li r11,0
	r11.s64 = 0;
loc_82265664:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_82265668:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822656e0
	if (cr6.eq) goto loc_822656E0;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f12,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r27
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v53,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f10,184(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	ctx.f10.f64 = double(temp.f32);
	// lvlx128 v52,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// fmadds f0,f11,f13,f0
	f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + f0.f64));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fsubs f9,f0,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f9
	cr6.compare(ctx.f13.f64, ctx.f9.f64);
	// ble cr6,0x822656e0
	if (!cr6.gt) goto loc_822656E0;
	// lfs f12,180(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bge cr6,0x822656e0
	if (!cr6.lt) goto loc_822656E0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x822656DC;
	// b 0x823d9234
	return;
loc_822656E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x822656F0;
	// b 0x823d9234
	return;
loc_822656F4:
	// addi r10,r31,64
	ctx.r10.s64 = r31.s64 + 64;
	// lvx128 v51,r0,r27
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r28
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// vsubfp128 v0,v50,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r9,r11,-23776
	ctx.r9.s64 = r11.s64 + -23776;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v12,v51,v59
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v59.f32)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v49,v0,v12
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32), 0xEF));
	// vsubfp128 v63,v60,v49
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v49.f32)));
	// vcmpgefp128. v48,v62,v63
	simde_mm_store_ps(v48.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v48.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82265740
	if (cr6.eq) goto loc_82265740;
	// li r11,1
	r11.s64 = 1;
	// b 0x82265790
	goto loc_82265790;
loc_82265740:
	// vmsum3fp128 v47,v0,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// vsubfp128 v61,v47,v63
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgefp128. v46,v62,v61
	simde_mm_store_ps(v46.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v46.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r11,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82265768
	if (cr6.eq) goto loc_82265768;
	// vaddfp v12,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)));
	// li r11,2
	r11.s64 = 2;
	// b 0x82265790
	goto loc_82265790;
loc_82265768:
	// vaddfp128 v45,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// vupkd3d128 v44,v60,4
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v44 = vTemp;
	// li r11,0
	r11.s64 = 0;
	// vspltw128 v11,v44,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0x0));
	// vrefp128 v13,v45
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v45.f32)));
	// vor128 v10,v45,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v45.u8));
	// vnmsubfp v8,v13,v10,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v13,v8,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v6,v63,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v12,v0,v6,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
loc_82265790:
	// vaddfp128 v43,v12,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v43.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v59.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stvx128 v43,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822657b8
	if (!cr6.eq) goto loc_822657B8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,168(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-9152(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9152);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// b 0x822657bc
	goto loc_822657BC;
loc_822657B8:
	// lfs f0,168(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	f0.f64 = double(temp.f32);
loc_822657BC:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f9,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmuls f6,f10,f10
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f5,f7,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f12
	cr6.compare(ctx.f5.f64, ctx.f12.f64);
	// bge cr6,0x82265814
	if (!cr6.lt) goto loc_82265814;
	// lfs f13,184(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x82265814
	if (!cr6.gt) goto loc_82265814;
	// lfs f12,180(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// blt cr6,0x82265818
	if (cr6.lt) goto loc_82265818;
loc_82265814:
	// li r11,0
	r11.s64 = 0;
loc_82265818:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x82265828;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8226582C"))) PPC_WEAK_FUNC(sub_8226582C);
PPC_FUNC_IMPL(__imp__sub_8226582C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265830"))) PPC_WEAK_FUNC(sub_82265830);
PPC_FUNC_IMPL(__imp__sub_82265830) {
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82265838;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d4
	ctx.lr = 0x82265840;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r30,r11,-4912
	r30.s64 = r11.s64 + -4912;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,-4896(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4896);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// clrlwi r7,r11,31
	ctx.r7.u64 = r11.u32 & 0x1;
	// lfs f27,17032(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f27.f64 = double(temp.f32);
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8226589c
	if (!cr6.eq) goto loc_8226589C;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stfs f31,0(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f27,4(r30)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// stfs f31,8(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stw r11,-4896(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4896, r11.u32);
loc_8226589C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r4,-27692(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27692);
	// lfs f1,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82179778
	ctx.lr = 0x822658B0;
	sub_82179778(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// lfs f30,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fdivs f29,f30,f1
	f29.f64 = double(float(f30.f64 / ctx.f1.f64));
	// bl 0x8217f768
	ctx.lr = 0x822658C8;
	sub_8217F768(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r27,-25600(r8)
	r27.u64 = PPC_LOAD_U32(ctx.r8.u32 + -25600);
	// bl 0x8217f768
	ctx.lr = 0x822658DC;
	sub_8217F768(ctx, base);
	// li r7,112
	ctx.r7.s64 = 112;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,128
	ctx.r6.s64 = 128;
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f30,120(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v60,r31,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// vaddfp128 v59,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// lvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v0,v62,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vpermwi128 v58,v63,99
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v57,v63,135
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,-32124
	r28.s64 = -2105278464;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// vmulfp128 v13,v61,v58
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32)));
	// vor128 v12,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vor128 v11,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// vnmsubfp v0,v0,v11,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vpermwi128 v56,v0,99
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x9C));
	// stvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v10,v0,135
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x78));
	// vmulfp128 v9,v57,v56
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// vnmsubfp v8,v12,v10,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v8,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c088
	ctx.lr = 0x82265968;
	sub_8217C088(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x82265970;
	sub_8217D9A0(ctx, base);
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r29,66
	ctx.r6.s64 = r29.s64 + 66;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r5,-4288
	ctx.r4.s64 = ctx.r5.s64 + -4288;
	// lwzx r3,r7,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// lwzx r30,r10,r4
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// ble cr6,0x822659fc
	if (!cr6.gt) goto loc_822659FC;
	// addi r10,r29,50
	ctx.r10.s64 = r29.s64 + 50;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x822659cc
	if (!cr6.eq) goto loc_822659CC;
	// lvlx128 v55,r11,r31
	temp.u32 = r11.u32 + r31.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v53,r30,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v52,v53,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822659CC:
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82265a50
	if (!cr6.eq) goto loc_82265A50;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v51,r30,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v50,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmulfp128 v48,v51,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)));
	// stvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82265a50
	goto loc_82265A50;
loc_822659FC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v127,r30,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12424);
	f0.f64 = double(temp.f32);
	// lvx128 v126,r30,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82265A1C;
	sub_823DBAE8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vsubfp128 v47,v126,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,14884(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 + f30.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v46,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v45,v46,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vmaddfp128 v127,v47,v45,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v45.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82265A50:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// li r4,33
	ctx.r4.s64 = 33;
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lfs f11,104(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 * f29.f64));
	// lfs f29,96(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 96);
	f29.f64 = double(temp.f32);
	// lfs f0,15360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f28,100(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 100);
	f28.f64 = double(temp.f32);
	// fmuls f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f5,f10,f0
	ctx.f5.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fctiwz f4,f8
	ctx.f4.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f4.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f3,f7
	ctx.f3.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f3.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f2,f6
	ctx.f2.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f2,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f2.u64);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// fctiwz f1,f5
	ctx.f1.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f1,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f1.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r5,r6,8,16,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// or r11,r5,r7
	r11.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r8,r11,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 | ctx.r10.u64;
	// or r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 | ctx.r10.u64;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r10,r6,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r9,r5,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r31,r10,r11
	r31.u64 = ctx.r10.u64 | r11.u64;
	// or r29,r9,r11
	r29.u64 = ctx.r9.u64 | r11.u64;
	// bl 0x8217bb68
	ctx.lr = 0x82265AF4;
	sub_8217BB68(ctx, base);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// fmr f8,f31
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f31.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82265B1C;
	sub_8217BC28(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r11,-4848
	r30.s64 = r11.s64 + -4848;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
loc_82265B28:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// lfs f12,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmuls f3,f0,f28
	ctx.f3.f64 = double(float(f0.f64 * f28.f64));
	// fadds f2,f13,f27
	ctx.f2.f64 = double(float(ctx.f13.f64 + f27.f64));
	// fmuls f1,f12,f29
	ctx.f1.f64 = double(float(ctx.f12.f64 * f29.f64));
	// bl 0x8217bc28
	ctx.lr = 0x82265B5C;
	sub_8217BC28(ctx, base);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r11,r30,516
	r11.s64 = r30.s64 + 516;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82265b28
	if (cr6.lt) goto loc_82265B28;
	// bl 0x8217bc98
	ctx.lr = 0x82265B70;
	sub_8217BC98(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// bl 0x8217c088
	ctx.lr = 0x82265B80;
	sub_8217C088(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x82265B8C;
	sub_8217F768(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba20
	ctx.lr = 0x82265BA8;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82265BAC"))) PPC_WEAK_FUNC(sub_82265BAC);
PPC_FUNC_IMPL(__imp__sub_82265BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265BB0"))) PPC_WEAK_FUNC(sub_82265BB0);
PPC_FUNC_IMPL(__imp__sub_82265BB0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82265BB8;
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
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x82264830
	ctx.lr = 0x82265BD0;
	sub_82264830(ctx, base);
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// bl 0x822648d8
	ctx.lr = 0x82265BD8;
	sub_822648D8(ctx, base);
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r10,16
	ctx.r10.s64 = 16;
	// rlwinm r26,r28,2,0,29
	r26.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r9,-4288
	ctx.r7.s64 = ctx.r9.s64 + -4288;
	// stvx128 v63,r6,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r8,-4336
	ctx.r4.s64 = ctx.r8.s64 + -4336;
	// stvx128 v62,r5,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r26,r31
	r11.u64 = PPC_LOAD_U32(r26.u32 + r31.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwzx r8,r10,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stw r8,116(r9)
	PPC_STORE_U32(ctx.r9.u32 + 116, ctx.r8.u32);
	// bl 0x821c8fe0
	ctx.lr = 0x82265C28;
	sub_821C8FE0(ctx, base);
	// lwz r7,336(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r30,400
	r30.s64 = 400;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82265cb8
	if (cr6.eq) goto loc_82265CB8;
	// addi r11,r28,13
	r11.s64 = r28.s64 + 13;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// rotlwi r9,r7,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,48
	ctx.r8.s64 = 48;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfsx f0,r7,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// lis r29,-32256
	r29.s64 = -2113929216;
	// stfs f0,432(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 432, temp.u32);
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r7,116(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// lvx128 v61,r7,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// stvx128 v61,r4,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,176(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lfs f0,-4208(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -4208);
	f0.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f13,-12260(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12260);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r10,-7884
	ctx.r4.s64 = ctx.r10.s64 + -7884;
	// fdivs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fsel f8,f9,f9,f0
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f0.f64;
	// fsel f7,f9,f9,f0
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f0.f64;
	// fsubs f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f1,f6,f13,f7
	ctx.f1.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f7.f64;
	// bl 0x8247a6a0
	ctx.lr = 0x82265CB8;
	sub_8247A6A0(ctx, base);
loc_82265CB8:
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82265cd8
	if (cr6.eq) goto loc_82265CD8;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r9,64
	ctx.r9.s64 = 64;
	// lwz r8,116(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// lvx128 v60,r8,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82265CD8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82265CE0;
	sub_821C9030(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82265d08
	if (cr6.eq) goto loc_82265D08;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82265d0c
	if (!cr6.eq) goto loc_82265D0C;
loc_82265D08:
	// li r11,0
	r11.s64 = 0;
loc_82265D0C:
	// addi r9,r28,50
	ctx.r9.s64 = r28.s64 + 50;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r29,r9,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82265d2c
	if (cr6.eq) goto loc_82265D2C;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82265d30
	if (!cr6.eq) goto loc_82265D30;
loc_82265D2C:
	// li r27,0
	r27.s64 = 0;
loc_82265D30:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// stb r27,48(r11)
	PPC_STORE_U8(r11.u32 + 48, r27.u8);
	// lfs f2,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f2.f64 = double(temp.f32);
	// lwzx r6,r26,r31
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + r31.u32);
	// lfs f1,176(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	ctx.f1.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bl 0x82269648
	ctx.lr = 0x82265D60;
	sub_82269648(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r30,-7572(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lbz r10,14546(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 14546);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82265da4
	if (!cr6.eq) goto loc_82265DA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f10d0
	ctx.lr = 0x82265D7C;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82265d9c
	if (cr6.gt) goto loc_82265D9C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f10d0
	ctx.lr = 0x82265D90;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x82265da4
	if (!cr6.lt) goto loc_82265DA4;
loc_82265D9C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82265da8
	goto loc_82265DA8;
loc_82265DA4:
	// li r11,0
	r11.s64 = 0;
loc_82265DA8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82265dec
	if (!cr6.eq) goto loc_82265DEC;
	// lbz r11,329(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 329);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82265dec
	if (!cr6.eq) goto loc_82265DEC;
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82265dec
	if (cr6.eq) goto loc_82265DEC;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x82265dec
	if (!cr6.eq) goto loc_82265DEC;
	// lwz r11,348(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82265dec
	if (cr6.lt) goto loc_82265DEC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265830
	ctx.lr = 0x82265DEC;
	sub_82265830(ctx, base);
loc_82265DEC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82265DF4"))) PPC_WEAK_FUNC(sub_82265DF4);
PPC_FUNC_IMPL(__imp__sub_82265DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265DF8"))) PPC_WEAK_FUNC(sub_82265DF8);
PPC_FUNC_IMPL(__imp__sub_82265DF8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-4336
	ctx.r4.s64 = r11.s64 + -4336;
	// bl 0x821c8fe0
	ctx.lr = 0x82265E24;
	sub_821C8FE0(ctx, base);
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82265e8c
	if (cr6.eq) goto loc_82265E8C;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82265e8c
	if (cr6.eq) goto loc_82265E8C;
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82265e8c
	if (cr6.eq) goto loc_82265E8C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-7876
	ctx.r4.s64 = r11.s64 + -7876;
	// bl 0x8247bc80
	ctx.lr = 0x82265E54;
	sub_8247BC80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82265e8c
	if (cr6.lt) goto loc_82265E8C;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82265e74
	if (cr6.eq) goto loc_82265E74;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// b 0x82265e7c
	goto loc_82265E7C;
loc_82265E74:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82265E7C:
	// addi r11,r3,109
	r11.s64 = ctx.r3.s64 + 109;
	// lwz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82265E8C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82265E94;
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

__attribute__((alias("__imp__sub_82265EAC"))) PPC_WEAK_FUNC(sub_82265EAC);
PPC_FUNC_IMPL(__imp__sub_82265EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265EB0"))) PPC_WEAK_FUNC(sub_82265EB0);
PPC_FUNC_IMPL(__imp__sub_82265EB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r5,-32114
	ctx.r5.s64 = -2104623104;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,-11624(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// lwz r3,-23452(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -23452);
	// lfs f13,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// li r11,0
	r11.s64 = 0;
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r8,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r8.u16);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// sth r11,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r11.u16);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r11,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r11.u8);
	// sth r11,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r11.u16);
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r11.u32);
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82265fc4
	if (cr6.eq) goto loc_82265FC4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82574418
	ctx.lr = 0x82265F84;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82265fc4
	if (cr6.eq) goto loc_82265FC4;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lfs f8,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,176(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
loc_82265FC4:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

__attribute__((alias("__imp__sub_82265FDC"))) PPC_WEAK_FUNC(sub_82265FDC);
PPC_FUNC_IMPL(__imp__sub_82265FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265FE0"))) PPC_WEAK_FUNC(sub_82265FE0);
PPC_FUNC_IMPL(__imp__sub_82265FE0) {
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
	ctx.lr = 0x82265FE8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,160(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822661f8
	if (cr6.eq) goto loc_822661F8;
	// addi r28,r31,64
	r28.s64 = r31.s64 + 64;
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// li r27,80
	r27.s64 = 80;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,330(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 330);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266040
	if (cr6.eq) goto loc_82266040;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lvx128 v62,r31,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,172
	r11.s64 = 172;
	// vsubfp128 v13,v62,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v61,r31,r11
	temp.u32 = r31.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82266040:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f13,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// li r29,0
	r29.s64 = 0;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r5,-32114
	ctx.r5.s64 = -2104623104;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f31,208(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stw r29,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r29.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f31,212(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lfs f0,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lwz r3,-23452(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -23452);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r9,220(r1)
	PPC_STORE_U16(ctx.r1.u32 + 220, ctx.r9.u16);
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r29,222(r1)
	PPC_STORE_U16(ctx.r1.u32 + 222, r29.u16);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r29,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r29.u8);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// sth r29,226(r1)
	PPC_STORE_U16(ctx.r1.u32 + 226, r29.u16);
	// stw r29,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r29.u32);
	// beq cr6,0x8226611c
	if (cr6.eq) goto loc_8226611C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82574418
	ctx.lr = 0x822660F8;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8226611c
	if (cr6.eq) goto loc_8226611C;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// li r9,128
	ctx.r9.s64 = 128;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8226611C:
	// lbz r11,330(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 330);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822661e0
	if (cr6.eq) goto loc_822661E0;
	// lvx128 v57,r0,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// lvx128 v56,r31,r27
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// vsubfp128 v55,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r6,-31664
	ctx.r4.s64 = ctx.r6.s64 + -31664;
	// addi r3,r5,-31648
	ctx.r3.s64 = ctx.r5.s64 + -31648;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,-8040(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8040);
	f0.f64 = double(temp.f32);
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,104(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f31,100(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v54,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,96(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f11,104(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v51,v52,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vrsqrtefp128 v50,v51
	simde_mm_store_ps(v50.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v51.f32))));
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v12,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v50,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
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
	// vmulfp128 v49,v52,v6
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vor128 v48,v49,v49
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v47,v48,v53
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822661ec
	goto loc_822661EC;
loc_822661E0:
	// vspltisw128 v46,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,96
	r11.s64 = 96;
	// stvx128 v46,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822661EC:
	// stb r29,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r29.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265eb0
	ctx.lr = 0x822661F8;
	sub_82265EB0(ctx, base);
loc_822661F8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82266204"))) PPC_WEAK_FUNC(sub_82266204);
PPC_FUNC_IMPL(__imp__sub_82266204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266208"))) PPC_WEAK_FUNC(sub_82266208);
PPC_FUNC_IMPL(__imp__sub_82266208) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82266210;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d0
	ctx.lr = 0x82266218;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,80
	ctx.r9.s64 = 80;
	// li r8,96
	ctx.r8.s64 = 96;
	// li r7,112
	ctx.r7.s64 = 112;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r3,144
	ctx.r3.s64 = 144;
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
	// stw r30,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r30.u32);
	// li r28,-1
	r28.s64 = -1;
	// li r29,1
	r29.s64 = 1;
	// lfs f31,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f28,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f28.f64 = double(temp.f32);
	// addi r11,r31,264
	r11.s64 = r31.s64 + 264;
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,3
	ctx.r9.s64 = 3;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,128(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f28,132(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f31,136(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stb r30,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r30.u8);
	// lfs f0,14192(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
	// stfs f0,188(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
	// stvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r29,328(r31)
	PPC_STORE_U8(r31.u32 + 328, r29.u8);
	// stb r30,329(r31)
	PPC_STORE_U8(r31.u32 + 329, r30.u8);
	// stb r30,330(r31)
	PPC_STORE_U8(r31.u32 + 330, r30.u8);
	// stb r30,331(r31)
	PPC_STORE_U8(r31.u32 + 331, r30.u8);
	// stw r28,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r28.u32);
loc_822662B4:
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r9,-64(r11)
	PPC_STORE_U32(r11.u32 + -64, ctx.r9.u32);
	// stw r30,-264(r11)
	PPC_STORE_U32(r11.u32 + -264, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x822662b4
	if (!cr0.eq) goto loc_822662B4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,352(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// li r3,128
	ctx.r3.s64 = 128;
	// lfs f13,-8040(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8040);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31016(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,27636(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27636);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,30712(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30712);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f12,176(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f11,180(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stfs f10,184(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x8226631C;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82266340
	if (cr6.eq) goto loc_82266340;
	// bl 0x82619428
	ctx.lr = 0x8226632C;
	sub_82619428(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// addi r10,r11,-7904
	ctx.r10.s64 = r11.s64 + -7904;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82266344
	goto loc_82266344;
loc_82266340:
	// mr r29,r30
	r29.u64 = r30.u64;
loc_82266344:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r29,r3
	cr6.compare<uint32_t>(r29.u32, ctx.r3.u32, xer);
	// beq cr6,0x82266388
	if (cr6.eq) goto loc_82266388;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266368
	if (cr6.eq) goto loc_82266368;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266368:
	// stw r29,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82266388
	if (cr6.eq) goto loc_82266388;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266388;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266388:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r3,48
	ctx.r3.s64 = 48;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r30,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, r30.u32);
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r30,36(r9)
	PPC_STORE_U32(ctx.r9.u32 + 36, r30.u32);
	// lwz r8,192(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r30,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, r30.u32);
	// lwz r7,192(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r30,120(r7)
	PPC_STORE_U32(ctx.r7.u32 + 120, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822663B8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822663dc
	if (cr6.eq) goto loc_822663DC;
	// bl 0x82619428
	ctx.lr = 0x822663C8;
	sub_82619428(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// addi r10,r11,-8032
	ctx.r10.s64 = r11.s64 + -8032;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x822663e0
	goto loc_822663E0;
loc_822663DC:
	// mr r29,r30
	r29.u64 = r30.u64;
loc_822663E0:
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplw cr6,r29,r3
	cr6.compare<uint32_t>(r29.u32, ctx.r3.u32, xer);
	// beq cr6,0x82266424
	if (cr6.eq) goto loc_82266424;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266404
	if (cr6.eq) goto loc_82266404;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266404:
	// stw r29,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82266424
	if (cr6.eq) goto loc_82266424;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266424;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266424:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// stw r30,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, r30.u32);
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// stw r30,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, r30.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stw r28,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r28.u32);
	// bl 0x822652e8
	ctx.lr = 0x82266454;
	sub_822652E8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r28,r11,-4848
	r28.s64 = r11.s64 + -4848;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
	// lfs f30,-7864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7864);
	f30.f64 = double(temp.f32);
	// lfs f29,18204(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	f29.f64 = double(temp.f32);
loc_82266470:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// stfs f28,-8(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r29.u32 + -8, temp.u32);
	// stfs f31,-4(r29)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + -4, temp.u32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// stfs f31,0(r29)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmuls f27,f11,f29
	f27.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbae8
	ctx.lr = 0x822664A0;
	sub_823DBAE8(ctx, base);
	// frsp f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822664AC;
	sub_823DBBC8(ctx, base);
	// lfs f10,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// frsp f9,f1
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lfs f8,-8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f26
	ctx.f7.f64 = double(float(ctx.f10.f64 * f26.f64));
	// fmuls f6,f8,f26
	ctx.f6.f64 = double(float(ctx.f8.f64 * f26.f64));
	// addi r10,r28,520
	ctx.r10.s64 = r28.s64 + 520;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// fmadds f5,f8,f9,f7
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f7.f64));
	// stfs f5,-8(r29)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r29.u32 + -8, temp.u32);
	// fmsubs f4,f10,f9,f6
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 - ctx.f6.f64));
	// stfs f4,0(r29)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82266470
	if (cr6.lt) goto loc_82266470;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba1c
	ctx.lr = 0x822664F4;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822664F8"))) PPC_WEAK_FUNC(sub_822664F8);
PPC_FUNC_IMPL(__imp__sub_822664F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x823d91c0
	ctx.lr = 0x82266500;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9b8
	ctx.lr = 0x82266508;
	// li r12,-288
	r12.s64 = -288;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-272
	r12.s64 = -272;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,-4336
	ctx.r4.s64 = r11.s64 + -4336;
	// bl 0x821c8fe0
	ctx.lr = 0x82266530;
	sub_821C8FE0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f0,-12544(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12544);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f22,12424(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12424);
	f22.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f26,14980(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14980);
	f26.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f28,-7788(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -7788);
	f28.f64 = double(temp.f32);
	// lfs f21,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f21.f64 = double(temp.f32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lfs f23,14348(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14348);
	f23.f64 = double(temp.f32);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// lfs f27,15004(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 15004);
	f27.f64 = double(temp.f32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lfs f25,12428(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	f25.f64 = double(temp.f32);
	// lfs f29,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lis r27,-32130
	r27.s64 = -2105671680;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lis r29,23772
	r29.s64 = 1557921792;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// fmr f24,f31
	f24.f64 = f31.f64;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// fdivs f20,f31,f0
	f20.f64 = double(float(f31.f64 / f0.f64));
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lis r28,-32130
	r28.s64 = -2105671680;
	// addi r3,r3,-7812
	ctx.r3.s64 = ctx.r3.s64 + -7812;
	// addi r30,r30,17820
	r30.s64 = r30.s64 + 17820;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// li r17,0
	r17.s64 = 0;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r20,400
	r20.s64 = 400;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// ori r18,r29,64167
	r18.u64 = r29.u64 | 64167;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r21,-32120
	r21.s64 = -2105016320;
	// lis r15,-32115
	r15.s64 = -2104688640;
	// addi r23,r11,-12548
	r23.s64 = r11.s64 + -12548;
	// addi r25,r10,-4288
	r25.s64 = ctx.r10.s64 + -4288;
	// addi r27,r9,29952
	r27.s64 = ctx.r9.s64 + 29952;
	// addi r26,r8,2176
	r26.s64 = ctx.r8.s64 + 2176;
	// addi r16,r7,-7820
	r16.s64 = ctx.r7.s64 + -7820;
	// addi r22,r6,-7836
	r22.s64 = ctx.r6.s64 + -7836;
	// addi r19,r5,-7884
	r19.s64 = ctx.r5.s64 + -7884;
	// addi r14,r4,-7860
	r14.s64 = ctx.r4.s64 + -7860;
loc_82266624:
	// addi r11,r17,50
	r11.s64 = r17.s64 + 50;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8226667c
	if (cr6.eq) goto loc_8226667C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82266708
	if (!cr6.eq) goto loc_82266708;
	// addi r11,r17,66
	r11.s64 = r17.s64 + 66;
	// lfs f0,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 88);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r11,r31
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f20,f13
	ctx.f12.f64 = double(float(f0.f64 * f20.f64 + ctx.f13.f64));
	// stfsx f12,r11,r31
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// fsel f11,f12,f12,f29
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f29.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// fsubs f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fsel f24,f10,f31,f11
	f24.f64 = ctx.f10.f64 >= 0.0 ? f31.f64 : ctx.f11.f64;
	// blt cr6,0x82266708
	if (cr6.lt) goto loc_82266708;
	// li r10,0
	ctx.r10.s64 = 0;
	// stfsx f29,r11,r31
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// stwx r10,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r10.u32);
	// b 0x82266708
	goto loc_82266708;
loc_8226667C:
	// addi r11,r17,66
	r11.s64 = r17.s64 + 66;
	// lfs f0,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r11,r31
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f25,f12
	f0.f64 = double(float(f0.f64 * f25.f64 + ctx.f12.f64));
	// stfsx f0,r11,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x822666b0
	if (cr6.lt) goto loc_822666B0;
	// li r10,3
	ctx.r10.s64 = 3;
	// stfsx f29,r11,r31
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// stwx r10,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r10.u32);
	// b 0x822666b4
	goto loc_822666B4;
loc_822666B0:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_822666B4:
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82266708
	if (cr6.lt) goto loc_82266708;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266708
	if (!cr6.eq) goto loc_82266708;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// fsubs f0,f31,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - ctx.f13.f64));
	// li r9,32
	ctx.r9.s64 = 32;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lwzx r6,r8,r25
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r25.u32);
	// lvx128 v61,r6,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f14c8
	ctx.lr = 0x82266708;
	sub_822F14C8(ctx, base);
loc_82266708:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r9,-6144(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82266730
	if (cr6.eq) goto loc_82266730;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r11,156(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82266734
	if (!cr6.eq) goto loc_82266734;
loc_82266730:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82266734:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// clrlwi r28,r10,24
	r28.u64 = ctx.r10.u32 & 0xFF;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266790
	if (cr6.eq) goto loc_82266790;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82266788
	if (!cr6.eq) goto loc_82266788;
	// bl 0x82256058
	ctx.lr = 0x82266764;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266790
	if (cr6.eq) goto loc_82266790;
	// bl 0x82256058
	ctx.lr = 0x82266770;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82266790
	if (cr0.eq) goto loc_82266790;
	// bl 0x82256058
	ctx.lr = 0x8226677C;
	sub_82256058(ctx, base);
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82266790
	if (cr6.eq) goto loc_82266790;
loc_82266788:
	// li r11,1
	r11.s64 = 1;
	// b 0x82266794
	goto loc_82266794;
loc_82266790:
	// li r11,0
	r11.s64 = 0;
loc_82266794:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822667ac
	if (cr6.eq) goto loc_822667AC;
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = f29.f64;
	// b 0x822667b0
	goto loc_822667B0;
loc_822667AC:
	// fmr f0,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = f24.f64;
loc_822667B0:
	// addi r11,r17,13
	r11.s64 = r17.s64 + 13;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lwzx r8,r29,r31
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// beq cr6,0x822667d4
	if (cr6.eq) goto loc_822667D4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82266800
	if (cr6.eq) goto loc_82266800;
loc_822667D4:
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266800
	if (!cr6.eq) goto loc_82266800;
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82266800
	if (cr6.lt) goto loc_82266800;
	// stfs f29,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f29,148(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// stfs f29,152(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// bl 0x822f14c8
	ctx.lr = 0x82266800;
	sub_822F14C8(ctx, base);
loc_82266800:
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82266d38
	if (cr6.eq) goto loc_82266D38;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82266d38
	if (cr6.eq) goto loc_82266D38;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82266d38
	if (!cr6.eq) goto loc_82266D38;
	// lbz r11,329(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 329);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266870
	if (cr6.eq) goto loc_82266870;
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266870
	if (cr6.eq) goto loc_82266870;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266870
	if (!cr6.eq) goto loc_82266870;
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,464(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 464, temp.u32);
	// lfs f13,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lfs f0,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// bl 0x8247a8d0
	ctx.lr = 0x82266868;
	sub_8247A8D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r10.u32);
loc_82266870:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f12,176(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f0,-4208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4208);
	f0.f64 = double(temp.f32);
	// lfs f13,-12260(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12260);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fdivs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fsel f8,f9,f9,f29
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// fsubs f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsel f30,f7,f31,f8
	f30.f64 = ctx.f7.f64 >= 0.0 ? f31.f64 : ctx.f8.f64;
	// bne cr6,0x82266d98
	if (!cr6.eq) goto loc_82266D98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265fe0
	ctx.lr = 0x822668B0;
	sub_82265FE0(ctx, base);
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266be8
	if (!cr6.eq) goto loc_82266BE8;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-12540(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12540);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822668d0
	if (cr6.lt) goto loc_822668D0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_822668D0:
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// addi r30,r31,336
	r30.s64 = r31.s64 + 336;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822669b8
	if (!cr6.eq) goto loc_822669B8;
	// lbz r11,329(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 329);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822669b8
	if (!cr6.eq) goto loc_822669B8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-4916(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4916);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82266910
	if (!cr6.eq) goto loc_82266910;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
loc_82266910:
	// bl 0x824804d0
	ctx.lr = 0x82266914;
	sub_824804D0(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822669b8
	if (cr6.eq) goto loc_822669B8;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8247a6a0
	ctx.lr = 0x82266930;
	sub_8247A6A0(ctx, base);
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// lwzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// lvx128 v59,r9,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r8,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8247a020
	ctx.lr = 0x82266954;
	sub_8247A020(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x822650b0
	ctx.lr = 0x82266960;
	sub_822650B0(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,624(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 624);
	// addi r3,r11,672
	ctx.r3.s64 = r11.s64 + 672;
	// lwz r29,112(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82265100
	ctx.lr = 0x82266978;
	sub_82265100(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8247a838
	ctx.lr = 0x82266980;
	sub_8247A838(ctx, base);
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r5,120(r6)
	PPC_STORE_U32(ctx.r6.u32 + 120, ctx.r5.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r3,r11,120
	ctx.r3.s64 = r11.s64 + 120;
	// stw r3,148(r4)
	PPC_STORE_U32(ctx.r4.u32 + 148, ctx.r3.u32);
	// beq cr6,0x822669b8
	if (cr6.eq) goto loc_822669B8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822669B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822669B8:
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82266b64
	if (!cr6.eq) goto loc_82266B64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r9,-6144(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82266b64
	if (!cr6.eq) goto loc_82266B64;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwzx r29,r11,r25
	r29.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// beq cr6,0x82266ad4
	if (cr6.eq) goto loc_82266AD4;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// cmplwi cr6,r11,15
	cr6.compare<uint32_t>(r11.u32, 15, xer);
	// bgt cr6,0x82266ad4
	if (cr6.gt) goto loc_82266AD4;
	// lis r12,-32218
	r12.s64 = -2111438848;
	// addi r12,r12,27144
	r12.s64 = r12.s64 + 27144;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82266A48;
	case 1:
		goto loc_82266AD4;
	case 2:
		goto loc_82266AD4;
	case 3:
		goto loc_82266AA8;
	case 4:
		goto loc_82266A78;
	case 5:
		goto loc_82266A48;
	case 6:
		goto loc_82266A48;
	case 7:
		goto loc_82266A78;
	case 8:
		goto loc_82266A48;
	case 9:
		goto loc_82266AD4;
	case 10:
		goto loc_82266AD4;
	case 11:
		goto loc_82266AD4;
	case 12:
		goto loc_82266AD4;
	case 13:
		goto loc_82266AD4;
	case 14:
		goto loc_82266AD4;
	case 15:
		goto loc_82266A48;
	default:
		__builtin_unreachable();
	}
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27304(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27304);
	// lwz r17,27256(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27256);
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
	// lwz r17,27256(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27256);
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
loc_82266A48:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-4916(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4916);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x824804d0
	ctx.lr = 0x82266A5C;
	sub_824804D0(ctx, base);
	// stw r3,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266ad4
	if (cr6.eq) goto loc_82266AD4;
	// li r11,64
	r11.s64 = 64;
	// lvx128 v58,r29,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r3,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82266ad4
	goto loc_82266AD4;
loc_82266A78:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-4916(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4916);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x824804d0
	ctx.lr = 0x82266A8C;
	sub_824804D0(ctx, base);
	// stw r3,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266ad4
	if (cr6.eq) goto loc_82266AD4;
	// li r11,64
	r11.s64 = 64;
	// lvx128 v57,r29,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82266ad4
	goto loc_82266AD4;
loc_82266AA8:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-4916(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4916);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x824804d0
	ctx.lr = 0x82266ABC;
	sub_824804D0(ctx, base);
	// stw r3,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266ad4
	if (cr6.eq) goto loc_82266AD4;
	// li r11,64
	r11.s64 = 64;
	// lvx128 v56,r29,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82266AD4:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266b64
	if (cr6.eq) goto loc_82266B64;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// bl 0x8247a020
	ctx.lr = 0x82266AE8;
	sub_8247A020(ctx, base);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// lwz r4,196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// bl 0x822650b0
	ctx.lr = 0x82266AF4;
	sub_822650B0(ctx, base);
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lwz r11,624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 624);
	// lwz r29,116(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r3,r11,672
	ctx.r3.s64 = r11.s64 + 672;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82265100
	ctx.lr = 0x82266B0C;
	sub_82265100(ctx, base);
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// bl 0x8247a838
	ctx.lr = 0x82266B14;
	sub_8247A838(ctx, base);
	// lwz r10,340(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// lwz r9,136(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// lwz r3,256(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 256);
	// bl 0x8247bc80
	ctx.lr = 0x82266B28;
	sub_8247BC80(ctx, base);
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lwz r7,340(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// stw r3,344(r31)
	PPC_STORE_U32(r31.u32 + 344, ctx.r3.u32);
	// stw r7,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r7.u32);
	// lwz r6,340(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// stw r5,148(r6)
	PPC_STORE_U32(ctx.r6.u32 + 148, ctx.r5.u32);
	// beq cr6,0x82266b64
	if (cr6.eq) goto loc_82266B64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266B64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266B64:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266b78
	if (cr6.eq) goto loc_82266B78;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// bl 0x8247a020
	ctx.lr = 0x82266B78;
	sub_8247A020(ctx, base);
loc_82266B78:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266be8
	if (cr6.eq) goto loc_82266BE8;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// bl 0x8247a020
	ctx.lr = 0x82266B8C;
	sub_8247A020(ctx, base);
	// lwz r11,344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 344);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82266be8
	if (cr6.lt) goto loc_82266BE8;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x82266BA0;
	sub_822F10D0(ctx, base);
	// fcmpu cr6,f1,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f27.f64);
	// bge cr6,0x82266bbc
	if (!cr6.lt) goto loc_82266BBC;
	// fmuls f0,f1,f28
	f0.f64 = double(float(ctx.f1.f64 * f28.f64));
	// fsel f13,f0,f0,f29
	ctx.f13.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fsel f0,f12,f31,f13
	f0.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// b 0x82266bd4
	goto loc_82266BD4;
loc_82266BBC:
	// fsubs f0,f1,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f27.f64));
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// fsel f12,f13,f13,f29
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f29.f64;
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// fsel f10,f11,f31,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f31.f64 : ctx.f12.f64;
	// fsubs f0,f31,f10
	f0.f64 = double(float(f31.f64 - ctx.f10.f64));
loc_82266BD4:
	// lwz r11,344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 344);
	// lwz r10,340(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// addi r9,r11,109
	ctx.r9.s64 = r11.s64 + 109;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r8,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, temp.u32);
loc_82266BE8:
	// lwz r11,348(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82266d98
	if (cr6.lt) goto loc_82266D98;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266d98
	if (!cr6.eq) goto loc_82266D98;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	f0.f64 = double(temp.f32);
	// addi r11,r31,264
	r11.s64 = r31.s64 + 264;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,16
	ctx.r10.s64 = 16;
	// lwzx r30,r9,r25
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + r25.u32);
	// ble cr6,0x82266c4c
	if (!cr6.gt) goto loc_82266C4C;
	// stfs f29,352(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lvx128 v53,r30,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lvlx128 v55,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmulfp128 v52,v53,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// stvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f14c8
	ctx.lr = 0x82266C48;
	sub_822F14C8(ctx, base);
	// b 0x82266d98
	goto loc_82266D98;
loc_82266C4C:
	// li r11,32
	r11.s64 = 32;
	// lfs f0,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	f0.f64 = double(temp.f32);
	// lvx128 v127,r30,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f1,f0,f22
	ctx.f1.f64 = double(float(f0.f64 * f22.f64));
	// lvx128 v126,r30,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dbae8
	ctx.lr = 0x82266C64;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// vsubfp128 v51,v126,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lwz r11,-12640(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -12640);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// fadds f12,f13,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f13.f64 + f31.f64));
	// fmuls f11,f12,f21
	ctx.f11.f64 = double(float(ctx.f12.f64 * f21.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v50,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmaddfp128 v127,v51,v49,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82266cb0
	if (cr6.eq) goto loc_82266CB0;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82266cb4
	if (cr6.eq) goto loc_82266CB4;
loc_82266CB0:
	// li r11,0
	r11.s64 = 0;
loc_82266CB4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82266d24
	if (!cr6.eq) goto loc_82266D24;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// mulld r11,r11,r18
	r11.s64 = r11.s64 * r18.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r8,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// lfd f12,120(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// lfs f8,208(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 208);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,212(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 212);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lfs f10,352(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// fmadds f6,f7,f23,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f23.f64 + ctx.f13.f64));
	// fmadds f0,f6,f0,f10
	f0.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f10.f64));
	// stfs f0,352(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// ble cr6,0x82266d24
	if (!cr6.gt) goto loc_82266D24;
	// fsubs f0,f0,f26
	f0.f64 = double(float(f0.f64 - f26.f64));
	// stfs f0,352(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
loc_82266D24:
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// bl 0x822f14c8
	ctx.lr = 0x82266D34;
	sub_822F14C8(ctx, base);
	// b 0x82266d98
	goto loc_82266D98;
loc_82266D38:
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266d98
	if (!cr6.eq) goto loc_82266D98;
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266d80
	if (cr6.eq) goto loc_82266D80;
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,464(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 464, temp.u32);
	// lfs f13,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lfs f0,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// bl 0x8247a8d0
	ctx.lr = 0x82266D78;
	sub_8247A8D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r10.u32);
loc_82266D80:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266d98
	if (cr6.eq) goto loc_82266D98;
	// bl 0x8247a8d0
	ctx.lr = 0x82266D90;
	sub_8247A8D0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r11.u32);
loc_82266D98:
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// cmpwi cr6,r17,16
	cr6.compare<int32_t>(r17.s32, 16, xer);
	// blt cr6,0x82266624
	if (cr6.lt) goto loc_82266624;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c9030
	ctx.lr = 0x82266DAC;
	sub_821C9030(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// li r0,-288
	r0.s64 = -288;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-272
	r0.s64 = -272;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba04
	ctx.lr = 0x82266DC8;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82266DCC"))) PPC_WEAK_FUNC(sub_82266DCC);
PPC_FUNC_IMPL(__imp__sub_82266DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266DD0"))) PPC_WEAK_FUNC(sub_82266DD0);
PPC_FUNC_IMPL(__imp__sub_82266DD0) {
	PPC_FUNC_PROLOGUE();
	// b 0x822664f8
	sub_822664F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82266DD4"))) PPC_WEAK_FUNC(sub_82266DD4);
PPC_FUNC_IMPL(__imp__sub_82266DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266DD8"))) PPC_WEAK_FUNC(sub_82266DD8);
PPC_FUNC_IMPL(__imp__sub_82266DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,176(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 176, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266DEC"))) PPC_WEAK_FUNC(sub_82266DEC);
PPC_FUNC_IMPL(__imp__sub_82266DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266DF0"))) PPC_WEAK_FUNC(sub_82266DF0);
PPC_FUNC_IMPL(__imp__sub_82266DF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,180(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 180, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E04"))) PPC_WEAK_FUNC(sub_82266E04);
PPC_FUNC_IMPL(__imp__sub_82266E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266E08"))) PPC_WEAK_FUNC(sub_82266E08);
PPC_FUNC_IMPL(__imp__sub_82266E08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,168(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 168, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E1C"))) PPC_WEAK_FUNC(sub_82266E1C);
PPC_FUNC_IMPL(__imp__sub_82266E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266E20"))) PPC_WEAK_FUNC(sub_82266E20);
PPC_FUNC_IMPL(__imp__sub_82266E20) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82266e50
	if (!cr6.gt) goto loc_82266E50;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f13,-7912(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,188(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 188, temp.u32);
	// blr 
	return;
loc_82266E50:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,188(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 188, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E60"))) PPC_WEAK_FUNC(sub_82266E60);
PPC_FUNC_IMPL(__imp__sub_82266E60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,330(r9)
	PPC_STORE_U8(ctx.r9.u32 + 330, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E80"))) PPC_WEAK_FUNC(sub_82266E80);
PPC_FUNC_IMPL(__imp__sub_82266E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,172(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 172, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E94"))) PPC_WEAK_FUNC(sub_82266E94);
PPC_FUNC_IMPL(__imp__sub_82266E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266E98"))) PPC_WEAK_FUNC(sub_82266E98);
PPC_FUNC_IMPL(__imp__sub_82266E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,16
	ctx.r9.s64 = 16;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r8,r10,5
	ctx.r8.s64 = ctx.r10.s64 + 5;
	// stw r10,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r10.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82266EB4:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82266eb4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82266EB4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266EC4"))) PPC_WEAK_FUNC(sub_82266EC4);
PPC_FUNC_IMPL(__imp__sub_82266EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266EC8"))) PPC_WEAK_FUNC(sub_82266EC8);
PPC_FUNC_IMPL(__imp__sub_82266EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,16
	ctx.r9.s64 = 16;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r8,r10,8
	ctx.r8.s64 = ctx.r10.s64 + 8;
	// stw r10,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r10.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82266EE4:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82266ee4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82266EE4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266EF4"))) PPC_WEAK_FUNC(sub_82266EF4);
PPC_FUNC_IMPL(__imp__sub_82266EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266EF8"))) PPC_WEAK_FUNC(sub_82266EF8);
PPC_FUNC_IMPL(__imp__sub_82266EF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266F1C"))) PPC_WEAK_FUNC(sub_82266F1C);
PPC_FUNC_IMPL(__imp__sub_82266F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266F20"))) PPC_WEAK_FUNC(sub_82266F20);
PPC_FUNC_IMPL(__imp__sub_82266F20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82266f58
	if (cr6.eq) goto loc_82266F58;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,50
	r11.s64 = r11.s64 + 50;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82266F58:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266F6C"))) PPC_WEAK_FUNC(sub_82266F6C);
PPC_FUNC_IMPL(__imp__sub_82266F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266F70"))) PPC_WEAK_FUNC(sub_82266F70);
PPC_FUNC_IMPL(__imp__sub_82266F70) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f12,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-8(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// bne cr6,0x82266fac
	if (!cr6.eq) goto loc_82266FAC;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82266fac
	if (!cr6.eq) goto loc_82266FAC;
	// li r11,0
	r11.s64 = 0;
loc_82266FAC:
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// stb r11,331(r10)
	PPC_STORE_U8(ctx.r10.u32 + 331, r11.u8);
	// li r8,144
	ctx.r8.s64 = 144;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266FC4"))) PPC_WEAK_FUNC(sub_82266FC4);
PPC_FUNC_IMPL(__imp__sub_82266FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266FC8"))) PPC_WEAK_FUNC(sub_82266FC8);
PPC_FUNC_IMPL(__imp__sub_82266FC8) {
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
	// li r3,368
	ctx.r3.s64 = 368;
	// bl 0x82130528
	ctx.lr = 0x82266FE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226700c
	if (cr6.eq) goto loc_8226700C;
	// bl 0x82266208
	ctx.lr = 0x82266FF0;
	sub_82266208(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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
loc_8226700C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_8226702C"))) PPC_WEAK_FUNC(sub_8226702C);
PPC_FUNC_IMPL(__imp__sub_8226702C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267030"))) PPC_WEAK_FUNC(sub_82267030);
PPC_FUNC_IMPL(__imp__sub_82267030) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82267060
	if (cr6.eq) goto loc_82267060;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265240
	ctx.lr = 0x82267058;
	sub_82265240(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82267060;
	sub_82130588(ctx, base);
loc_82267060:
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

__attribute__((alias("__imp__sub_82267074"))) PPC_WEAK_FUNC(sub_82267074);
PPC_FUNC_IMPL(__imp__sub_82267074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267078"))) PPC_WEAK_FUNC(sub_82267078);
PPC_FUNC_IMPL(__imp__sub_82267078) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82264e80
	sub_82264E80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822670DC"))) PPC_WEAK_FUNC(sub_822670DC);
PPC_FUNC_IMPL(__imp__sub_822670DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822670E0"))) PPC_WEAK_FUNC(sub_822670E0);
PPC_FUNC_IMPL(__imp__sub_822670E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,80
	ctx.r10.s64 = 80;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r5,r6,r3
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, ctx.r5.u32);
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r8,160(r4)
	PPC_STORE_U8(ctx.r4.u32 + 160, ctx.r8.u8);
	// stvx128 v63,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267154"))) PPC_WEAK_FUNC(sub_82267154);
PPC_FUNC_IMPL(__imp__sub_82267154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267158"))) PPC_WEAK_FUNC(sub_82267158);
PPC_FUNC_IMPL(__imp__sub_82267158) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,112
	ctx.r10.s64 = 112;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// lvx128 v63,r5,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822671C4"))) PPC_WEAK_FUNC(sub_822671C4);
PPC_FUNC_IMPL(__imp__sub_822671C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822671C8"))) PPC_WEAK_FUNC(sub_822671C8);
PPC_FUNC_IMPL(__imp__sub_822671C8) {
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
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28616
	ctx.r4.s64 = r11.s64 + 28616;
	// addi r3,r10,-7372
	ctx.r3.s64 = ctx.r10.s64 + -7372;
	// bl 0x82554798
	ctx.lr = 0x822671E8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,28720
	ctx.r4.s64 = ctx.r9.s64 + 28720;
	// addi r3,r8,-7392
	ctx.r3.s64 = ctx.r8.s64 + -7392;
	// bl 0x82554798
	ctx.lr = 0x822671FC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,28792
	ctx.r4.s64 = ctx.r7.s64 + 28792;
	// addi r3,r6,-7416
	ctx.r3.s64 = ctx.r6.s64 + -7416;
	// bl 0x82554798
	ctx.lr = 0x82267210;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,28896
	ctx.r4.s64 = ctx.r5.s64 + 28896;
	// addi r3,r3,-7448
	ctx.r3.s64 = ctx.r3.s64 + -7448;
	// bl 0x82554798
	ctx.lr = 0x82267224;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28120
	ctx.r4.s64 = r11.s64 + 28120;
	// addi r3,r10,-7472
	ctx.r3.s64 = ctx.r10.s64 + -7472;
	// bl 0x82554798
	ctx.lr = 0x82267238;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,28144
	ctx.r4.s64 = ctx.r9.s64 + 28144;
	// addi r3,r8,-7504
	ctx.r3.s64 = ctx.r8.s64 + -7504;
	// bl 0x82554798
	ctx.lr = 0x8226724C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,28168
	ctx.r4.s64 = ctx.r7.s64 + 28168;
	// addi r3,r6,-7536
	ctx.r3.s64 = ctx.r6.s64 + -7536;
	// bl 0x82554798
	ctx.lr = 0x82267260;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,28192
	ctx.r4.s64 = ctx.r5.s64 + 28192;
	// addi r3,r3,-7560
	ctx.r3.s64 = ctx.r3.s64 + -7560;
	// bl 0x82554798
	ctx.lr = 0x82267274;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28256
	ctx.r4.s64 = r11.s64 + 28256;
	// addi r3,r10,-7588
	ctx.r3.s64 = ctx.r10.s64 + -7588;
	// bl 0x82554798
	ctx.lr = 0x82267288;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,28288
	ctx.r4.s64 = ctx.r9.s64 + 28288;
	// addi r3,r8,-7616
	ctx.r3.s64 = ctx.r8.s64 + -7616;
	// bl 0x82554798
	ctx.lr = 0x8226729C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,29016
	ctx.r4.s64 = ctx.r7.s64 + 29016;
	// addi r3,r6,-7640
	ctx.r3.s64 = ctx.r6.s64 + -7640;
	// bl 0x82554798
	ctx.lr = 0x822672B0;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,28312
	ctx.r4.s64 = ctx.r5.s64 + 28312;
	// addi r3,r3,-7672
	ctx.r3.s64 = ctx.r3.s64 + -7672;
	// bl 0x82554798
	ctx.lr = 0x822672C4;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28360
	ctx.r4.s64 = r11.s64 + 28360;
	// addi r3,r10,-7704
	ctx.r3.s64 = ctx.r10.s64 + -7704;
	// bl 0x82554798
	ctx.lr = 0x822672D8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,28408
	ctx.r4.s64 = ctx.r9.s64 + 28408;
	// addi r3,r8,-7724
	ctx.r3.s64 = ctx.r8.s64 + -7724;
	// bl 0x82554798
	ctx.lr = 0x822672EC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,28448
	ctx.r4.s64 = ctx.r7.s64 + 28448;
	// addi r3,r6,-7748
	ctx.r3.s64 = ctx.r6.s64 + -7748;
	// bl 0x82554798
	ctx.lr = 0x82267300;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,28528
	ctx.r4.s64 = ctx.r5.s64 + 28528;
	// addi r3,r3,-7784
	ctx.r3.s64 = ctx.r3.s64 + -7784;
	// bl 0x82554798
	ctx.lr = 0x82267314;
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

__attribute__((alias("__imp__sub_82267324"))) PPC_WEAK_FUNC(sub_82267324);
PPC_FUNC_IMPL(__imp__sub_82267324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267328"))) PPC_WEAK_FUNC(sub_82267328);
PPC_FUNC_IMPL(__imp__sub_82267328) {
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
	// clrlwi r31,r4,16
	r31.u64 = ctx.r4.u32 & 0xFFFF;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82267380
	if (!cr6.lt) goto loc_82267380;
loc_82267354:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r31,368
	r11.s64 = r31.s64 * 368;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r3,368
	ctx.r4.s64 = ctx.r3.s64 + 368;
	// bl 0x82264c90
	ctx.lr = 0x82267368;
	sub_82264C90(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// clrlwi r31,r10,16
	r31.u64 = ctx.r10.u32 & 0xFFFF;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82267354
	if (cr6.lt) goto loc_82267354;
loc_82267380:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
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

__attribute__((alias("__imp__sub_822673A8"))) PPC_WEAK_FUNC(sub_822673A8);
PPC_FUNC_IMPL(__imp__sub_822673A8) {
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
	ctx.lr = 0x822673B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mulli r3,r30,368
	ctx.r3.s64 = r30.s64 * 368;
	// bl 0x82130528
	ctx.lr = 0x822673C0;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822673ec
	if (!cr6.gt) goto loc_822673EC;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_822673D0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822673e0
	if (cr6.eq) goto loc_822673E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82266208
	ctx.lr = 0x822673E0;
	sub_82266208(ctx, base);
loc_822673E0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,368
	r31.s64 = r31.s64 + 368;
	// bne 0x822673d0
	if (!cr0.eq) goto loc_822673D0;
loc_822673EC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822673F8"))) PPC_WEAK_FUNC(sub_822673F8);
PPC_FUNC_IMPL(__imp__sub_822673F8) {
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
	// rlwinm r3,r31,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x82267414;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82267468
	if (!cr6.gt) goto loc_82267468;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,255
	ctx.r9.s64 = 255;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82267434:
	// addic. r7,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r7.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq 0x8226745c
	if (cr0.eq) goto loc_8226745C;
	// stfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stw r8,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r8.u32);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// stb r10,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r10.u8);
loc_8226745C:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82267434
	if (!cr0.eq) goto loc_82267434;
loc_82267468:
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

__attribute__((alias("__imp__sub_8226747C"))) PPC_WEAK_FUNC(sub_8226747C);
PPC_FUNC_IMPL(__imp__sub_8226747C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267480"))) PPC_WEAK_FUNC(sub_82267480);
PPC_FUNC_IMPL(__imp__sub_82267480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mulli r10,r4,368
	ctx.r10.s64 = ctx.r4.s64 * 368;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267490"))) PPC_WEAK_FUNC(sub_82267490);
PPC_FUNC_IMPL(__imp__sub_82267490) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267498"))) PPC_WEAK_FUNC(sub_82267498);
PPC_FUNC_IMPL(__imp__sub_82267498) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r4,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822674AC"))) PPC_WEAK_FUNC(sub_822674AC);
PPC_FUNC_IMPL(__imp__sub_822674AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822674B0"))) PPC_WEAK_FUNC(sub_822674B0);
PPC_FUNC_IMPL(__imp__sub_822674B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822674C4"))) PPC_WEAK_FUNC(sub_822674C4);
PPC_FUNC_IMPL(__imp__sub_822674C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822674C8"))) PPC_WEAK_FUNC(sub_822674C8);
PPC_FUNC_IMPL(__imp__sub_822674C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f1,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822674DC"))) PPC_WEAK_FUNC(sub_822674DC);
PPC_FUNC_IMPL(__imp__sub_822674DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822674E0"))) PPC_WEAK_FUNC(sub_822674E0);
PPC_FUNC_IMPL(__imp__sub_822674E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// mulli r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 * 368;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267510"))) PPC_WEAK_FUNC(sub_82267510);
PPC_FUNC_IMPL(__imp__sub_82267510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// b 0x82267328
	sub_82267328(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82267524"))) PPC_WEAK_FUNC(sub_82267524);
PPC_FUNC_IMPL(__imp__sub_82267524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267528"))) PPC_WEAK_FUNC(sub_82267528);
PPC_FUNC_IMPL(__imp__sub_82267528) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267540"))) PPC_WEAK_FUNC(sub_82267540);
PPC_FUNC_IMPL(__imp__sub_82267540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulli r10,r7,368
	ctx.r10.s64 = ctx.r7.s64 * 368;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267564"))) PPC_WEAK_FUNC(sub_82267564);
PPC_FUNC_IMPL(__imp__sub_82267564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267568"))) PPC_WEAK_FUNC(sub_82267568);
PPC_FUNC_IMPL(__imp__sub_82267568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stwx r8,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267588"))) PPC_WEAK_FUNC(sub_82267588);
PPC_FUNC_IMPL(__imp__sub_82267588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stfs f0,4(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822675AC"))) PPC_WEAK_FUNC(sub_822675AC);
PPC_FUNC_IMPL(__imp__sub_822675AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822675B0"))) PPC_WEAK_FUNC(sub_822675B0);
PPC_FUNC_IMPL(__imp__sub_822675B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// sth r7,8(r5)
	PPC_STORE_U16(ctx.r5.u32 + 8, ctx.r7.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822675D4"))) PPC_WEAK_FUNC(sub_822675D4);
PPC_FUNC_IMPL(__imp__sub_822675D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822675D8"))) PPC_WEAK_FUNC(sub_822675D8);
PPC_FUNC_IMPL(__imp__sub_822675D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stb r7,10(r5)
	PPC_STORE_U8(ctx.r5.u32 + 10, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822675FC"))) PPC_WEAK_FUNC(sub_822675FC);
PPC_FUNC_IMPL(__imp__sub_822675FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267600"))) PPC_WEAK_FUNC(sub_82267600);
PPC_FUNC_IMPL(__imp__sub_82267600) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stb r7,11(r5)
	PPC_STORE_U8(ctx.r5.u32 + 11, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267624"))) PPC_WEAK_FUNC(sub_82267624);
PPC_FUNC_IMPL(__imp__sub_82267624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267628"))) PPC_WEAK_FUNC(sub_82267628);
PPC_FUNC_IMPL(__imp__sub_82267628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r4,r7
	ctx.r4.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r8,r3,1
	ctx.r8.u64 = ctx.r3.u64 ^ 1;
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// stb r8,14(r11)
	PPC_STORE_U8(r11.u32 + 14, ctx.r8.u8);
	// stb r7,13(r11)
	PPC_STORE_U8(r11.u32 + 13, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267670"))) PPC_WEAK_FUNC(sub_82267670);
PPC_FUNC_IMPL(__imp__sub_82267670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267688"))) PPC_WEAK_FUNC(sub_82267688);
PPC_FUNC_IMPL(__imp__sub_82267688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stb r7,12(r5)
	PPC_STORE_U8(ctx.r5.u32 + 12, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822676AC"))) PPC_WEAK_FUNC(sub_822676AC);
PPC_FUNC_IMPL(__imp__sub_822676AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822676B0"))) PPC_WEAK_FUNC(sub_822676B0);
PPC_FUNC_IMPL(__imp__sub_822676B0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822676f0
	if (!cr6.gt) goto loc_822676F0;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f13,-7912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// blr 
	return;
loc_822676F0:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226770C"))) PPC_WEAK_FUNC(sub_8226770C);
PPC_FUNC_IMPL(__imp__sub_8226770C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267710"))) PPC_WEAK_FUNC(sub_82267710);
PPC_FUNC_IMPL(__imp__sub_82267710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,20(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267738"))) PPC_WEAK_FUNC(sub_82267738);
PPC_FUNC_IMPL(__imp__sub_82267738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stfs f0,16(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226775C"))) PPC_WEAK_FUNC(sub_8226775C);
PPC_FUNC_IMPL(__imp__sub_8226775C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267760"))) PPC_WEAK_FUNC(sub_82267760);
PPC_FUNC_IMPL(__imp__sub_82267760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,16(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267788"))) PPC_WEAK_FUNC(sub_82267788);
PPC_FUNC_IMPL(__imp__sub_82267788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 24);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822677A0"))) PPC_WEAK_FUNC(sub_822677A0);
PPC_FUNC_IMPL(__imp__sub_822677A0) {
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
	// lhz r11,10(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r31,r3,4
	r31.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822677e8
	if (!cr6.eq) goto loc_822677E8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x822677e0
	if (cr6.eq) goto loc_822677E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822673a8
	ctx.lr = 0x822677DC;
	sub_822673A8(ctx, base);
	// b 0x822677e4
	goto loc_822677E4;
loc_822677E0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822677E4:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_822677E8:
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

__attribute__((alias("__imp__sub_82267804"))) PPC_WEAK_FUNC(sub_82267804);
PPC_FUNC_IMPL(__imp__sub_82267804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267808"))) PPC_WEAK_FUNC(sub_82267808);
PPC_FUNC_IMPL(__imp__sub_82267808) {
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
	ctx.lr = 0x82267810;
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
	// ble cr6,0x82267840
	if (!cr6.gt) goto loc_82267840;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8226782C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82265240
	ctx.lr = 0x82267834;
	sub_82265240(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// bne 0x8226782c
	if (!cr0.eq) goto loc_8226782C;
loc_82267840:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x82267848;
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

__attribute__((alias("__imp__sub_82267860"))) PPC_WEAK_FUNC(sub_82267860);
PPC_FUNC_IMPL(__imp__sub_82267860) {
	PPC_FUNC_PROLOGUE();
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82267808
	ctx.lr = 0x82267880;
	sub_82267808(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82267888;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// sth r30,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r30.u16);
	// sth r30,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r30.u16);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x822678A0;
	sub_82130588(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// sth r30,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r30.u16);
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

__attribute__((alias("__imp__sub_822678C4"))) PPC_WEAK_FUNC(sub_822678C4);
PPC_FUNC_IMPL(__imp__sub_822678C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822678C8"))) PPC_WEAK_FUNC(sub_822678C8);
PPC_FUNC_IMPL(__imp__sub_822678C8) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// beq cr6,0x82267904
	if (cr6.eq) goto loc_82267904;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822673a8
	ctx.lr = 0x82267900;
	sub_822673A8(ctx, base);
	// b 0x82267908
	goto loc_82267908;
loc_82267904:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82267908:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
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

__attribute__((alias("__imp__sub_82267928"))) PPC_WEAK_FUNC(sub_82267928);
PPC_FUNC_IMPL(__imp__sub_82267928) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r30,4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lhz r9,10(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 10);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8226797c
	if (!cr6.eq) goto loc_8226797C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x82267974
	if (cr6.eq) goto loc_82267974;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822673a8
	ctx.lr = 0x82267970;
	sub_822673A8(ctx, base);
	// b 0x82267978
	goto loc_82267978;
loc_82267974:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82267978:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8226797C:
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

__attribute__((alias("__imp__sub_82267998"))) PPC_WEAK_FUNC(sub_82267998);
PPC_FUNC_IMPL(__imp__sub_82267998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r6,r7,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r5,20(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r5,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822679D8"))) PPC_WEAK_FUNC(sub_822679D8);
PPC_FUNC_IMPL(__imp__sub_822679D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r4,r6,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// stwx r8,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r8.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r8,20(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// lvx128 v63,r4,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267A4C"))) PPC_WEAK_FUNC(sub_82267A4C);
PPC_FUNC_IMPL(__imp__sub_82267A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267A50"))) PPC_WEAK_FUNC(sub_82267A50);
PPC_FUNC_IMPL(__imp__sub_82267A50) {
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
	ctx.lr = 0x82267A58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82267a98
	if (!cr6.eq) goto loc_82267A98;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// beq cr6,0x82267a90
	if (cr6.eq) goto loc_82267A90;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822673f8
	ctx.lr = 0x82267A8C;
	sub_822673F8(ctx, base);
	// b 0x82267a94
	goto loc_82267A94;
loc_82267A90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82267A94:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_82267A98:
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// lhz r10,6(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82267ad8
	if (!cr6.eq) goto loc_82267AD8;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// sth r28,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r28.u16);
	// beq cr6,0x82267ad0
	if (cr6.eq) goto loc_82267AD0;
	// rlwinm r3,r28,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x82267AC0;
	sub_82130528(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r28,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82267AD0:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_82267AD8:
	// sth r28,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82267AE4"))) PPC_WEAK_FUNC(sub_82267AE4);
PPC_FUNC_IMPL(__imp__sub_82267AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267AE8"))) PPC_WEAK_FUNC(sub_82267AE8);
PPC_FUNC_IMPL(__imp__sub_82267AE8) {
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
	ctx.lr = 0x82267AF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r30,r28,12
	r30.s64 = r28.s64 + 12;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82267b20
	if (cr6.eq) goto loc_82267B20;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822673f8
	ctx.lr = 0x82267B1C;
	sub_822673F8(ctx, base);
	// b 0x82267b24
	goto loc_82267B24;
loc_82267B20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82267B24:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// beq cr6,0x82267b4c
	if (cr6.eq) goto loc_82267B4C;
	// rlwinm r3,r29,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x82267B3C;
	sub_82130528(ctx, base);
	// stw r3,20(r28)
	PPC_STORE_U32(r28.u32 + 20, ctx.r3.u32);
	// sth r29,26(r28)
	PPC_STORE_U16(r28.u32 + 26, r29.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82267B4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r29,26(r28)
	PPC_STORE_U16(r28.u32 + 26, r29.u16);
	// stw r3,20(r28)
	PPC_STORE_U32(r28.u32 + 20, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82267B60"))) PPC_WEAK_FUNC(sub_82267B60);
PPC_FUNC_IMPL(__imp__sub_82267B60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82267a50
	sub_82267A50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82267B74"))) PPC_WEAK_FUNC(sub_82267B74);
PPC_FUNC_IMPL(__imp__sub_82267B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267B78"))) PPC_WEAK_FUNC(sub_82267B78);
PPC_FUNC_IMPL(__imp__sub_82267B78) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82267808
	ctx.lr = 0x82267B9C;
	sub_82267808(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82267BA4;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// sth r30,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r30.u16);
	// sth r30,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r30.u16);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82267BBC;
	sub_82130588(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// sth r30,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r30.u16);
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

__attribute__((alias("__imp__sub_82267BE0"))) PPC_WEAK_FUNC(sub_82267BE0);
PPC_FUNC_IMPL(__imp__sub_82267BE0) {
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
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30920
	ctx.r4.s64 = r11.s64 + 30920;
	// addi r3,r10,-6236
	ctx.r3.s64 = ctx.r10.s64 + -6236;
	// bl 0x82554798
	ctx.lr = 0x82267C00;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,31016
	ctx.r4.s64 = ctx.r9.s64 + 31016;
	// addi r3,r8,-6264
	ctx.r3.s64 = ctx.r8.s64 + -6264;
	// bl 0x82554798
	ctx.lr = 0x82267C14;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,31464
	ctx.r4.s64 = ctx.r7.s64 + 31464;
	// addi r3,r6,-6296
	ctx.r3.s64 = ctx.r6.s64 + -6296;
	// bl 0x82554798
	ctx.lr = 0x82267C28;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,31584
	ctx.r4.s64 = ctx.r5.s64 + 31584;
	// addi r3,r3,-6328
	ctx.r3.s64 = ctx.r3.s64 + -6328;
	// bl 0x82554798
	ctx.lr = 0x82267C3C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,31608
	ctx.r4.s64 = r11.s64 + 31608;
	// addi r3,r10,-6352
	ctx.r3.s64 = ctx.r10.s64 + -6352;
	// bl 0x82554798
	ctx.lr = 0x82267C50;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,29920
	ctx.r4.s64 = ctx.r9.s64 + 29920;
	// addi r3,r8,-6384
	ctx.r3.s64 = ctx.r8.s64 + -6384;
	// bl 0x82554798
	ctx.lr = 0x82267C64;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,29968
	ctx.r4.s64 = ctx.r7.s64 + 29968;
	// addi r3,r6,-6416
	ctx.r3.s64 = ctx.r6.s64 + -6416;
	// bl 0x82554798
	ctx.lr = 0x82267C78;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,29992
	ctx.r4.s64 = ctx.r5.s64 + 29992;
	// addi r3,r3,-6444
	ctx.r3.s64 = ctx.r3.s64 + -6444;
	// bl 0x82554798
	ctx.lr = 0x82267C8C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30016
	ctx.r4.s64 = r11.s64 + 30016;
	// addi r3,r10,-6476
	ctx.r3.s64 = ctx.r10.s64 + -6476;
	// bl 0x82554798
	ctx.lr = 0x82267CA0;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,30056
	ctx.r4.s64 = ctx.r9.s64 + 30056;
	// addi r3,r8,-6520
	ctx.r3.s64 = ctx.r8.s64 + -6520;
	// bl 0x82554798
	ctx.lr = 0x82267CB4;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,30088
	ctx.r4.s64 = ctx.r7.s64 + 30088;
	// addi r3,r6,-6552
	ctx.r3.s64 = ctx.r6.s64 + -6552;
	// bl 0x82554798
	ctx.lr = 0x82267CC8;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,30128
	ctx.r4.s64 = ctx.r5.s64 + 30128;
	// addi r3,r3,-6596
	ctx.r3.s64 = ctx.r3.s64 + -6596;
	// bl 0x82554798
	ctx.lr = 0x82267CDC;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30168
	ctx.r4.s64 = r11.s64 + 30168;
	// addi r3,r10,-6640
	ctx.r3.s64 = ctx.r10.s64 + -6640;
	// bl 0x82554798
	ctx.lr = 0x82267CF0;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,30208
	ctx.r4.s64 = ctx.r9.s64 + 30208;
	// addi r3,r8,-6680
	ctx.r3.s64 = ctx.r8.s64 + -6680;
	// bl 0x82554798
	ctx.lr = 0x82267D04;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,30248
	ctx.r4.s64 = ctx.r7.s64 + 30248;
	// addi r3,r6,-6716
	ctx.r3.s64 = ctx.r6.s64 + -6716;
	// bl 0x82554798
	ctx.lr = 0x82267D18;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,30320
	ctx.r4.s64 = ctx.r5.s64 + 30320;
	// addi r3,r3,-6752
	ctx.r3.s64 = ctx.r3.s64 + -6752;
	// bl 0x82554798
	ctx.lr = 0x82267D2C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30344
	ctx.r4.s64 = r11.s64 + 30344;
	// addi r3,r10,-6796
	ctx.r3.s64 = ctx.r10.s64 + -6796;
	// bl 0x82554798
	ctx.lr = 0x82267D40;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,31128
	ctx.r4.s64 = ctx.r9.s64 + 31128;
	// addi r3,r8,-6828
	ctx.r3.s64 = ctx.r8.s64 + -6828;
	// bl 0x82554798
	ctx.lr = 0x82267D54;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,31192
	ctx.r4.s64 = ctx.r7.s64 + 31192;
	// addi r3,r6,-6860
	ctx.r3.s64 = ctx.r6.s64 + -6860;
	// bl 0x82554798
	ctx.lr = 0x82267D68;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,30384
	ctx.r4.s64 = ctx.r5.s64 + 30384;
	// addi r3,r3,-6892
	ctx.r3.s64 = ctx.r3.s64 + -6892;
	// bl 0x82554798
	ctx.lr = 0x82267D7C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30480
	ctx.r4.s64 = r11.s64 + 30480;
	// addi r3,r10,-6924
	ctx.r3.s64 = ctx.r10.s64 + -6924;
	// bl 0x82554798
	ctx.lr = 0x82267D90;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,30520
	ctx.r4.s64 = ctx.r9.s64 + 30520;
	// addi r3,r8,-6964
	ctx.r3.s64 = ctx.r8.s64 + -6964;
	// bl 0x82554798
	ctx.lr = 0x82267DA4;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,30560
	ctx.r4.s64 = ctx.r7.s64 + 30560;
	// addi r3,r6,-7004
	ctx.r3.s64 = ctx.r6.s64 + -7004;
	// bl 0x82554798
	ctx.lr = 0x82267DB8;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,30600
	ctx.r4.s64 = ctx.r5.s64 + 30600;
	// addi r3,r3,-7040
	ctx.r3.s64 = ctx.r3.s64 + -7040;
	// bl 0x82554798
	ctx.lr = 0x82267DCC;
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

__attribute__((alias("__imp__sub_82267DDC"))) PPC_WEAK_FUNC(sub_82267DDC);
PPC_FUNC_IMPL(__imp__sub_82267DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267DE0"))) PPC_WEAK_FUNC(sub_82267DE0);
PPC_FUNC_IMPL(__imp__sub_82267DE0) {
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
	ctx.lr = 0x82267DE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82267e28
	if (cr6.eq) goto loc_82267E28;
	// addic. r30,r11,-1
	xer.ca = r11.u32 > 0;
	r30.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x82267e28
	if (cr0.lt) goto loc_82267E28;
	// addi r11,r30,13684
	r11.s64 = r30.s64 + 13684;
	// li r29,0
	r29.s64 = 0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r3
	r31.u64 = r11.u64 + ctx.r3.u64;
loc_82267E10:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82238408
	ctx.lr = 0x82267E18;
	sub_82238408(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bge 0x82267e10
	if (!cr0.lt) goto loc_82267E10;
loc_82267E28:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82267E30"))) PPC_WEAK_FUNC(sub_82267E30);
PPC_FUNC_IMPL(__imp__sub_82267E30) {
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
	ctx.lr = 0x82267E38;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r31,13684
	r11.s64 = r31.s64 + 13684;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82238408
	ctx.lr = 0x82267E58;
	sub_82238408(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r9,160(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// bge cr6,0x82267e8c
	if (!cr6.lt) goto loc_82267E8C;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82267E70:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r9,160(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82267e70
	if (cr6.lt) goto loc_82267E70;
loc_82267E8C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82267E94"))) PPC_WEAK_FUNC(sub_82267E94);
PPC_FUNC_IMPL(__imp__sub_82267E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267E98"))) PPC_WEAK_FUNC(sub_82267E98);
PPC_FUNC_IMPL(__imp__sub_82267E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r3,6
	cr6.compare<uint32_t>(ctx.r3.u32, 6, xer);
	// beq cr6,0x82267f48
	if (cr6.eq) goto loc_82267F48;
	// cmplwi cr6,r3,8
	cr6.compare<uint32_t>(ctx.r3.u32, 8, xer);
	// beq cr6,0x82267f48
	if (cr6.eq) goto loc_82267F48;
	// cmplwi cr6,r3,9
	cr6.compare<uint32_t>(ctx.r3.u32, 9, xer);
	// bne cr6,0x82268008
	if (!cr6.eq) goto loc_82268008;
	// cmplwi cr6,r4,21
	cr6.compare<uint32_t>(ctx.r4.u32, 21, xer);
	// bgt cr6,0x82268008
	if (cr6.gt) goto loc_82268008;
	// lis r12,-32218
	r12.s64 = -2111438848;
	// addi r12,r12,32464
	r12.s64 = r12.s64 + 32464;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_82267F28;
	case 1:
		goto loc_82267F30;
	case 2:
		goto loc_82267F28;
	case 3:
		goto loc_82267F30;
	case 4:
		goto loc_82267F30;
	case 5:
		goto loc_82267F30;
	case 6:
		goto loc_82267F28;
	case 7:
		goto loc_82267F28;
	case 8:
		goto loc_82268008;
	case 9:
		goto loc_82268008;
	case 10:
		goto loc_82268008;
	case 11:
		goto loc_82268008;
	case 12:
		goto loc_82267F30;
	case 13:
		goto loc_82267F30;
	case 14:
		goto loc_82267F28;
	case 15:
		goto loc_82267F28;
	case 16:
		goto loc_82268008;
	case 17:
		goto loc_82268008;
	case 18:
		goto loc_82268008;
	case 19:
		goto loc_82268008;
	case 20:
		goto loc_82267F38;
	case 21:
		goto loc_82267F40;
	default:
		__builtin_unreachable();
	}
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,32568(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32568);
	// lwz r17,32576(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32576);
loc_82267F28:
	// li r3,13
	ctx.r3.s64 = 13;
	// blr 
	return;
loc_82267F30:
	// li r3,12
	ctx.r3.s64 = 12;
	// blr 
	return;
loc_82267F38:
	// li r3,21
	ctx.r3.s64 = 21;
	// blr 
	return;
loc_82267F40:
	// li r3,20
	ctx.r3.s64 = 20;
	// blr 
	return;
loc_82267F48:
	// cmplwi cr6,r4,15
	cr6.compare<uint32_t>(ctx.r4.u32, 15, xer);
	// bgt cr6,0x82268008
	if (cr6.gt) goto loc_82268008;
	// lis r12,-32218
	r12.s64 = -2111438848;
	// addi r12,r12,32616
	r12.s64 = r12.s64 + 32616;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_82267FA8;
	case 1:
		goto loc_82267FB0;
	case 2:
		goto loc_82267FB8;
	case 3:
		goto loc_82267FC0;
	case 4:
		goto loc_82267FC8;
	case 5:
		goto loc_82267FD0;
	case 6:
		goto loc_82268008;
	case 7:
		goto loc_82267FD8;
	case 8:
		goto loc_82267FE0;
	case 9:
		goto loc_82267FE8;
	case 10:
		goto loc_82267FF0;
	case 11:
		goto loc_82267FF8;
	case 12:
		goto loc_82268000;
	case 13:
		goto loc_82268000;
	case 14:
		goto loc_82268000;
	case 15:
		goto loc_82268000;
	default:
		__builtin_unreachable();
	}
	// lwz r17,32680(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32680);
	// lwz r17,32688(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32688);
	// lwz r17,32696(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32696);
	// lwz r17,32704(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32704);
	// lwz r17,32712(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32712);
	// lwz r17,32720(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32720);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,32728(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32728);
	// lwz r17,32736(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32736);
	// lwz r17,32744(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32744);
	// lwz r17,32752(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32752);
	// lwz r17,32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32760);
	// lwz r17,-32768(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32768);
	// lwz r17,-32768(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32768);
	// lwz r17,-32768(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32768);
	// lwz r17,-32768(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32768);
loc_82267FA8:
	// li r3,7
	ctx.r3.s64 = 7;
	// blr 
	return;
loc_82267FB0:
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_82267FB8:
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_82267FC0:
	// li r3,6
	ctx.r3.s64 = 6;
	// blr 
	return;
loc_82267FC8:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_82267FD0:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_82267FD8:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_82267FE0:
	// li r3,10
	ctx.r3.s64 = 10;
	// blr 
	return;
loc_82267FE8:
	// li r3,29
	ctx.r3.s64 = 29;
	// blr 
	return;
loc_82267FF0:
	// li r3,28
	ctx.r3.s64 = 28;
	// blr 
	return;
loc_82267FF8:
	// li r3,9
	ctx.r3.s64 = 9;
	// blr 
	return;
loc_82268000:
	// li r3,19
	ctx.r3.s64 = 19;
	// blr 
	return;
loc_82268008:
	// li r3,1
	ctx.r3.s64 = 1;
}

__attribute__((alias("__imp__sub_82268010"))) PPC_WEAK_FUNC(sub_82268010);
PPC_FUNC_IMPL(__imp__sub_82268010) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82268030
	if (!cr6.lt) goto loc_82268030;
	// li r11,0
	r11.s64 = 0;
loc_82268030:
	// addi r11,r11,13684
	r11.s64 = r11.s64 + 13684;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r9,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// b 0x822384c0
	sub_822384C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82268050"))) PPC_WEAK_FUNC(sub_82268050);
PPC_FUNC_IMPL(__imp__sub_82268050) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82268054"))) PPC_WEAK_FUNC(sub_82268054);
PPC_FUNC_IMPL(__imp__sub_82268054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268058"))) PPC_WEAK_FUNC(sub_82268058);
PPC_FUNC_IMPL(__imp__sub_82268058) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r10,r10,13684
	ctx.r10.s64 = ctx.r10.s64 + 13684;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r6,r10,13684
	ctx.r6.s64 = ctx.r10.s64 + 13684;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// ble cr6,0x822680cc
	if (!cr6.gt) goto loc_822680CC;
	// addi r7,r10,13685
	ctx.r7.s64 = ctx.r10.s64 + 13685;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// stwx r3,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r3.u32);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r10,r10,13685
	ctx.r10.s64 = ctx.r10.s64 + 13685;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r9.u32);
	// lwz r9,-10028(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r6,r10,13685
	ctx.r6.s64 = ctx.r10.s64 + 13685;
	// addi r5,r10,13684
	ctx.r5.s64 = ctx.r10.s64 + 13684;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r9,128
	ctx.r3.s64 = ctx.r9.s64 + 128;
	// lwzx r5,r4,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x822388a8
	sub_822388A8(ctx, base);
	return;
loc_822680CC:
	// addi r7,r10,13683
	ctx.r7.s64 = ctx.r10.s64 + 13683;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// stwx r3,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r3.u32);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r10,r10,13683
	ctx.r10.s64 = ctx.r10.s64 + 13683;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r9.u32);
	// lwz r10,-10028(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r6,r10,13684
	ctx.r6.s64 = ctx.r10.s64 + 13684;
	// addi r5,r10,13683
	ctx.r5.s64 = ctx.r10.s64 + 13683;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r4,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x822388a8
	sub_822388A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82268114"))) PPC_WEAK_FUNC(sub_82268114);
PPC_FUNC_IMPL(__imp__sub_82268114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268118"))) PPC_WEAK_FUNC(sub_82268118);
PPC_FUNC_IMPL(__imp__sub_82268118) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822681c4
	if (!cr6.gt) goto loc_822681C4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8226814C:
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bne cr6,0x82268160
	if (!cr6.eq) goto loc_82268160;
	// li r10,5
	ctx.r10.s64 = 5;
	// b 0x82268180
	goto loc_82268180;
loc_82268160:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x82268170
	if (!cr6.eq) goto loc_82268170;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82268180
	goto loc_82268180;
loc_82268170:
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r10,r11,3
	ctx.r10.s64 = r11.s64 + 3;
loc_82268180:
	// addi r11,r31,13684
	r11.s64 = r31.s64 + 13684;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822681b4
	if (cr6.eq) goto loc_822681B4;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r10,38(r9)
	PPC_STORE_U8(ctx.r9.u32 + 38, ctx.r10.u8);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r6,r3,80
	ctx.r6.s64 = ctx.r3.s64 + 80;
	// bl 0x822384c0
	ctx.lr = 0x822681B4;
	sub_822384C0(ctx, base);
loc_822681B4:
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8226814c
	if (cr6.lt) goto loc_8226814C;
loc_822681C4:
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

__attribute__((alias("__imp__sub_822681E0"))) PPC_WEAK_FUNC(sub_822681E0);
PPC_FUNC_IMPL(__imp__sub_822681E0) {
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
	ctx.lr = 0x822681E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268268
	if (cr6.eq) goto loc_82268268;
	// addi r29,r11,128
	r29.s64 = r11.s64 + 128;
	// bl 0x822387e8
	ctx.lr = 0x82268210;
	sub_822387E8(ctx, base);
	// addi r11,r31,13684
	r11.s64 = r31.s64 + 13684;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,4
	ctx.r4.s64 = 4;
	// stwx r3,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r3.u32);
	// stb r10,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r10.u8);
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x82237b38
	ctx.lr = 0x82268230;
	sub_82237B38(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r4,r31,r30
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x82238688
	ctx.lr = 0x82268240;
	sub_82238688(ctx, base);
	// lwzx r7,r31,r30
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r9,38(r7)
	PPC_STORE_U8(ctx.r7.u32 + 38, ctx.r9.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822384c0
	ctx.lr = 0x82268268;
	sub_822384C0(ctx, base);
loc_82268268:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82268270"))) PPC_WEAK_FUNC(sub_82268270);
PPC_FUNC_IMPL(__imp__sub_82268270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x82268278;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addis r31,r26,1
	r31.s64 = r26.s64 + 65536;
	// addi r31,r31,-11228
	r31.s64 = r31.s64 + -11228;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226873c
	if (cr6.eq) goto loc_8226873C;
	// bl 0x82178848
	ctx.lr = 0x82268298;
	sub_82178848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r10,-21512
	ctx.r4.s64 = ctx.r10.s64 + -21512;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x822682B8;
	sub_825EE0E0(ctx, base);
	// lbz r5,159(r26)
	ctx.r5.u64 = PPC_LOAD_U8(r26.u32 + 159);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822682f0
	if (cr6.eq) goto loc_822682F0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-5356
	ctx.r4.s64 = r11.s64 + -5356;
	// bl 0x825ee0e0
	ctx.lr = 0x822682D4;
	sub_825EE0E0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r5,160(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// stb r10,159(r26)
	PPC_STORE_U8(r26.u32 + 159, ctx.r10.u8);
	// addi r4,r9,-5376
	ctx.r4.s64 = ctx.r9.s64 + -5376;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x825ee0e0
	ctx.lr = 0x822682F0;
	sub_825EE0E0(ctx, base);
loc_822682F0:
	// lwz r11,160(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82268324
	if (!cr6.gt) goto loc_82268324;
	// lbz r11,158(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5396
	ctx.r4.s64 = r11.s64 + -5396;
	// beq cr6,0x8226831c
	if (cr6.eq) goto loc_8226831C;
	// lwz r5,168(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// b 0x82268330
	goto loc_82268330;
loc_8226831C:
	// li r5,-1
	ctx.r5.s64 = -1;
	// b 0x82268330
	goto loc_82268330;
loc_82268324:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-5396
	ctx.r4.s64 = r11.s64 + -5396;
loc_82268330:
	// bl 0x825ee0e0
	ctx.lr = 0x82268334;
	sub_825EE0E0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5412
	ctx.r4.s64 = r11.s64 + -5412;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82268348;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5420
	ctx.r4.s64 = ctx.r10.s64 + -5420;
	// bl 0x825ee2d8
	ctx.lr = 0x8226835C;
	sub_825EE2D8(ctx, base);
	// lbz r8,156(r26)
	ctx.r8.u64 = PPC_LOAD_U8(r26.u32 + 156);
	// lis r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// ori r29,r9,54609
	r29.u64 = ctx.r9.u64 | 54609;
	// beq cr6,0x822683dc
	if (cr6.eq) goto loc_822683DC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,-5432
	ctx.r4.s64 = r11.s64 + -5432;
	// bl 0x825ee0e0
	ctx.lr = 0x82268384;
	sub_825EE0E0(ctx, base);
	// lbzx r10,r26,r29
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + r29.u32);
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822683b8
	if (cr6.eq) goto loc_822683B8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5448
	ctx.r4.s64 = r11.s64 + -5448;
	// bl 0x82218310
	ctx.lr = 0x822683A0;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5456
	ctx.r4.s64 = ctx.r10.s64 + -5456;
	// bl 0x825ee2d8
	ctx.lr = 0x822683B4;
	sub_825EE2D8(ctx, base);
	// b 0x822684e0
	goto loc_822684E0;
loc_822683B8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5472
	ctx.r4.s64 = r11.s64 + -5472;
	// bl 0x82218310
	ctx.lr = 0x822683C4;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5456
	ctx.r4.s64 = ctx.r10.s64 + -5456;
	// bl 0x825ee2d8
	ctx.lr = 0x822683D8;
	sub_825EE2D8(ctx, base);
	// b 0x822684e0
	goto loc_822684E0;
loc_822683DC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r4,r11,-5484
	ctx.r4.s64 = r11.s64 + -5484;
	// bl 0x82218310
	ctx.lr = 0x822683EC;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5456
	ctx.r4.s64 = ctx.r10.s64 + -5456;
	// bl 0x825ee2d8
	ctx.lr = 0x82268400;
	sub_825EE2D8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,17292(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17292);
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmplwi cr6,r11,15
	cr6.compare<uint32_t>(r11.u32, 15, xer);
	// bgt cr6,0x822684cc
	if (cr6.gt) goto loc_822684CC;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-31700
	r12.s64 = r12.s64 + -31700;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8226846C;
	case 1:
		goto loc_82268474;
	case 2:
		goto loc_8226847C;
	case 3:
		goto loc_82268484;
	case 4:
		goto loc_8226848C;
	case 5:
		goto loc_82268494;
	case 6:
		goto loc_822684CC;
	case 7:
		goto loc_8226849C;
	case 8:
		goto loc_822684A4;
	case 9:
		goto loc_822684AC;
	case 10:
		goto loc_822684B4;
	case 11:
		goto loc_822684BC;
	case 12:
		goto loc_822684C4;
	case 13:
		goto loc_822684C4;
	case 14:
		goto loc_822684C4;
	case 15:
		goto loc_822684C4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-31636(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31636);
	// lwz r17,-31628(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31628);
	// lwz r17,-31620(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31620);
	// lwz r17,-31612(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31612);
	// lwz r17,-31604(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31604);
	// lwz r17,-31596(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31596);
	// lwz r17,-31540(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31540);
	// lwz r17,-31588(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31588);
	// lwz r17,-31580(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31580);
	// lwz r17,-31572(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31572);
	// lwz r17,-31564(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31564);
	// lwz r17,-31556(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31556);
	// lwz r17,-31548(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31548);
	// lwz r17,-31548(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31548);
	// lwz r17,-31548(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31548);
	// lwz r17,-31548(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31548);
loc_8226846C:
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x822684d0
	goto loc_822684D0;
loc_82268474:
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x822684d0
	goto loc_822684D0;
loc_8226847C:
	// li r5,5
	ctx.r5.s64 = 5;
	// b 0x822684d0
	goto loc_822684D0;
loc_82268484:
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x822684d0
	goto loc_822684D0;
loc_8226848C:
	// li r5,4
	ctx.r5.s64 = 4;
	// b 0x822684d0
	goto loc_822684D0;
loc_82268494:
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x822684d0
	goto loc_822684D0;
loc_8226849C:
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684A4:
	// li r5,10
	ctx.r5.s64 = 10;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684AC:
	// li r5,29
	ctx.r5.s64 = 29;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684B4:
	// li r5,28
	ctx.r5.s64 = 28;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684BC:
	// li r5,9
	ctx.r5.s64 = 9;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684C4:
	// li r5,19
	ctx.r5.s64 = 19;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684CC:
	// li r5,1
	ctx.r5.s64 = 1;
loc_822684D0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-5432
	ctx.r4.s64 = r11.s64 + -5432;
	// bl 0x825ee0e0
	ctx.lr = 0x822684E0;
	sub_825EE0E0(ctx, base);
loc_822684E0:
	// lwz r11,160(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r28,r10,-5496
	r28.s64 = ctx.r10.s64 + -5496;
	// bne cr6,0x82268500
	if (!cr6.eq) goto loc_82268500;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5516
	ctx.r4.s64 = r11.s64 + -5516;
	// b 0x82268524
	goto loc_82268524;
loc_82268500:
	// ble cr6,0x8226853c
	if (!cr6.gt) goto loc_8226853C;
	// lbz r11,158(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226851c
	if (cr6.eq) goto loc_8226851C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5532
	ctx.r4.s64 = r11.s64 + -5532;
	// b 0x82268524
	goto loc_82268524;
loc_8226851C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5548
	ctx.r4.s64 = r11.s64 + -5548;
loc_82268524:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8226852C;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8226853C;
	sub_825EE2D8(ctx, base);
loc_8226853C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-5564
	ctx.r4.s64 = r11.s64 + -5564;
	// bl 0x825ee0e0
	ctx.lr = 0x82268550;
	sub_825EE0E0(ctx, base);
	// lbzx r10,r26,r29
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + r29.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// add r27,r26,r29
	r27.u64 = r26.u64 + r29.u64;
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x82251d70
	ctx.lr = 0x82268568;
	sub_82251D70(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// addi r4,r11,-5584
	ctx.r4.s64 = r11.s64 + -5584;
	// li r5,1
	ctx.r5.s64 = 1;
	// bne cr6,0x82268588
	if (!cr6.eq) goto loc_82268588;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82268588:
	// bl 0x825ee0e0
	ctx.lr = 0x8226858C;
	sub_825EE0E0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r5,r11,-5596
	ctx.r5.s64 = r11.s64 + -5596;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822685A0;
	sub_82137A08(ctx, base);
	// cmplwi cr6,r29,8
	cr6.compare<uint32_t>(r29.u32, 8, xer);
	// bgt cr6,0x82268658
	if (cr6.gt) goto loc_82268658;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-31296
	r12.s64 = r12.s64 + -31296;
	// rlwinm r0,r29,2,0,29
	r0.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r29.u64) {
	case 0:
		goto loc_822685E4;
	case 1:
		goto loc_822685F0;
	case 2:
		goto loc_822685FC;
	case 3:
		goto loc_82268608;
	case 4:
		goto loc_82268614;
	case 5:
		goto loc_82268658;
	case 6:
		goto loc_82268620;
	case 7:
		goto loc_8226862C;
	case 8:
		goto loc_82268638;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-31260(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31260);
	// lwz r17,-31248(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31248);
	// lwz r17,-31236(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31236);
	// lwz r17,-31224(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31224);
	// lwz r17,-31212(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31212);
	// lwz r17,-31144(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31144);
	// lwz r17,-31200(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31200);
	// lwz r17,-31188(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31188);
	// lwz r17,-31176(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31176);
loc_822685E4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5612
	ctx.r4.s64 = r11.s64 + -5612;
	// b 0x82268640
	goto loc_82268640;
loc_822685F0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5632
	ctx.r4.s64 = r11.s64 + -5632;
	// b 0x82268640
	goto loc_82268640;
loc_822685FC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r5,r11,-5660
	ctx.r5.s64 = r11.s64 + -5660;
	// b 0x8226864c
	goto loc_8226864C;
loc_82268608:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5676
	ctx.r4.s64 = r11.s64 + -5676;
	// b 0x82268640
	goto loc_82268640;
loc_82268614:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5696
	ctx.r4.s64 = r11.s64 + -5696;
	// b 0x82268640
	goto loc_82268640;
loc_82268620:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5728
	ctx.r4.s64 = r11.s64 + -5728;
	// b 0x82268640
	goto loc_82268640;
loc_8226862C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5756
	ctx.r4.s64 = r11.s64 + -5756;
	// b 0x82268640
	goto loc_82268640;
loc_82268638:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5788
	ctx.r4.s64 = r11.s64 + -5788;
loc_82268640:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82268648;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_8226864C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x825ee2d8
	ctx.lr = 0x82268658;
	sub_825EE2D8(ctx, base);
loc_82268658:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-5804
	ctx.r4.s64 = r11.s64 + -5804;
	// bl 0x825ee0e0
	ctx.lr = 0x8226866C;
	sub_825EE0E0(ctx, base);
	// lwz r10,168(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82268690
	if (!cr6.eq) goto loc_82268690;
	// lbz r11,158(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268690
	if (cr6.eq) goto loc_82268690;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5832
	ctx.r4.s64 = r11.s64 + -5832;
	// b 0x822686bc
	goto loc_822686BC;
loc_82268690:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822686d4
	if (cr6.eq) goto loc_822686D4;
	// lbz r11,158(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822686d4
	if (!cr6.eq) goto loc_822686D4;
	// lwz r11,160(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x822686d4
	if (!cr6.gt) goto loc_822686D4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5864
	ctx.r4.s64 = r11.s64 + -5864;
loc_822686BC:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822686C4;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x822686D4;
	sub_825EE2D8(ctx, base);
loc_822686D4:
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,54320
	ctx.r10.u64 = r11.u64 | 54320;
	// lbzx r9,r26,r10
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82268728
	if (cr6.eq) goto loc_82268728;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r4,r11,-5880
	ctx.r4.s64 = r11.s64 + -5880;
	// bl 0x82218310
	ctx.lr = 0x822686F8;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5892
	ctx.r4.s64 = ctx.r10.s64 + -5892;
	// bl 0x825ee2d8
	ctx.lr = 0x8226870C;
	sub_825EE2D8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r9,-5908
	ctx.r4.s64 = ctx.r9.s64 + -5908;
	// bl 0x825ee0e0
	ctx.lr = 0x82268720;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82268728:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-5908
	ctx.r4.s64 = r11.s64 + -5908;
	// bl 0x825ee0e0
	ctx.lr = 0x8226873C;
	sub_825EE0E0(ctx, base);
loc_8226873C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82268744"))) PPC_WEAK_FUNC(sub_82268744);
PPC_FUNC_IMPL(__imp__sub_82268744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268748"))) PPC_WEAK_FUNC(sub_82268748);
PPC_FUNC_IMPL(__imp__sub_82268748) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x8226875C;
	sub_82387928(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// addi r4,r9,-21652
	ctx.r4.s64 = ctx.r9.s64 + -21652;
	// li r8,10000
	ctx.r8.s64 = 10000;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// li r7,1450
	ctx.r7.s64 = 1450;
	// li r6,1450
	ctx.r6.s64 = 1450;
	// li r9,1
	ctx.r9.s64 = 1;
	// bne cr6,0x82268790
	if (!cr6.eq) goto loc_82268790;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r10,-5308
	ctx.r5.s64 = ctx.r10.s64 + -5308;
	// b 0x82268798
	goto loc_82268798;
loc_82268790:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r10,-5336
	ctx.r5.s64 = ctx.r10.s64 + -5336;
loc_82268798:
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x821fb938
	ctx.lr = 0x822687A0;
	sub_821FB938(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822687B0"))) PPC_WEAK_FUNC(sub_822687B0);
PPC_FUNC_IMPL(__imp__sub_822687B0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-21652
	ctx.r4.s64 = ctx.r10.s64 + -21652;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f96c8
	ctx.lr = 0x822687D8;
	sub_821F96C8(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,54308
	ctx.r7.u64 = ctx.r9.u64 | 54308;
	// ori r6,r8,54312
	ctx.r6.u64 = ctx.r8.u64 | 54312;
	// li r11,0
	r11.s64 = 0;
	// stwx r11,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r11.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
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

__attribute__((alias("__imp__sub_82268808"))) PPC_WEAK_FUNC(sub_82268808);
PPC_FUNC_IMPL(__imp__sub_82268808) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-13512(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// lfs f13,-4960(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4960);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82268854
	if (!cr6.gt) goto loc_82268854;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-4964(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4964);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82268854
	if (!cr6.lt) goto loc_82268854;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r9,-12360
	ctx.r8.s64 = ctx.r9.s64 + -12360;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// cmpwi cr6,r6,5
	cr6.compare<int32_t>(ctx.r6.s32, 5, xer);
	// bne cr6,0x82268854
	if (!cr6.eq) goto loc_82268854;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
loc_82268854:
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// lfs f0,356(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 356);
	f0.f64 = double(temp.f32);
	// stfs f0,-13512(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -13512, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226886C"))) PPC_WEAK_FUNC(sub_8226886C);
PPC_FUNC_IMPL(__imp__sub_8226886C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268870"))) PPC_WEAK_FUNC(sub_82268870);
PPC_FUNC_IMPL(__imp__sub_82268870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-13516(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13516);
	f0.f64 = double(temp.f32);
	// lfs f13,-4952(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4952);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822688bc
	if (!cr6.gt) goto loc_822688BC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-4956(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4956);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822688bc
	if (!cr6.lt) goto loc_822688BC;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r9,-12360
	ctx.r8.s64 = ctx.r9.s64 + -12360;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// cmpwi cr6,r6,6
	cr6.compare<int32_t>(ctx.r6.s32, 6, xer);
	// bne cr6,0x822688bc
	if (!cr6.eq) goto loc_822688BC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
loc_822688BC:
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// lfs f0,344(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 344);
	f0.f64 = double(temp.f32);
	// stfs f0,-13516(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -13516, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822688D4"))) PPC_WEAK_FUNC(sub_822688D4);
PPC_FUNC_IMPL(__imp__sub_822688D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822688D8"))) PPC_WEAK_FUNC(sub_822688D8);
PPC_FUNC_IMPL(__imp__sub_822688D8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82268910
	if (cr6.eq) goto loc_82268910;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lhz r30,8(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x82268914
	goto loc_82268914;
loc_82268910:
	// li r30,0
	r30.s64 = 0;
loc_82268914:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268924;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82268928;
	sub_822A8108(ctx, base);
	// mulli r11,r30,368
	r11.s64 = r30.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r10,r11,240
	ctx.r10.s64 = r11.s64 + 240;
	// lfs f0,244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 248);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,240(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 240);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// stw r30,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r30.u32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f0,32668(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32668);
	f0.f64 = double(temp.f32);
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// bge cr6,0x82268998
	if (!cr6.lt) goto loc_82268998;
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82268998
	if (!cr6.eq) goto loc_82268998;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268998:
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

__attribute__((alias("__imp__sub_822689B0"))) PPC_WEAK_FUNC(sub_822689B0);
PPC_FUNC_IMPL(__imp__sub_822689B0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822689e8
	if (cr6.eq) goto loc_822689E8;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lhz r30,8(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x822689ec
	goto loc_822689EC;
loc_822689E8:
	// li r30,0
	r30.s64 = 0;
loc_822689EC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822689FC;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82268A00;
	sub_822A8108(ctx, base);
	// mulli r11,r30,368
	r11.s64 = r30.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r10,r11,240
	ctx.r10.s64 = r11.s64 + 240;
	// lfs f0,244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 248);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,240(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 240);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f0,32668(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32668);
	f0.f64 = double(temp.f32);
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// ble cr6,0x82268a6c
	if (!cr6.gt) goto loc_82268A6C;
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82268a6c
	if (!cr6.eq) goto loc_82268A6C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268A6C:
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

__attribute__((alias("__imp__sub_82268A84"))) PPC_WEAK_FUNC(sub_82268A84);
PPC_FUNC_IMPL(__imp__sub_82268A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268A88"))) PPC_WEAK_FUNC(sub_82268A88);
PPC_FUNC_IMPL(__imp__sub_82268A88) {
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
	ctx.lr = 0x82268A90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,160(r29)
	PPC_STORE_U32(r29.u32 + 160, r11.u32);
	// ble 0x82268b28
	if (!cr0.gt) goto loc_82268B28;
	// lwz r31,168(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 168);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82268ae0
	if (!cr6.lt) goto loc_82268AE0;
	// mulli r11,r31,368
	r11.s64 = r31.s64 * 368;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r30,r11,176
	r30.s64 = r11.s64 + 176;
loc_82268AC0:
	// addi r4,r30,368
	ctx.r4.s64 = r30.s64 + 368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82264c90
	ctx.lr = 0x82268ACC;
	sub_82264C90(ctx, base);
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82268ac0
	if (cr6.lt) goto loc_82268AC0;
loc_82268AE0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82268b00
	if (cr6.eq) goto loc_82268B00;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x82268b04
	goto loc_82268B04;
loc_82268B00:
	// li r11,0
	r11.s64 = 0;
loc_82268B04:
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822523f0
	ctx.lr = 0x82268B10;
	sub_822523F0(ctx, base);
	// lwz r3,11584(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 11584);
	// bl 0x822635f0
	ctx.lr = 0x82268B18;
	sub_822635F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82252948
	ctx.lr = 0x82268B28;
	sub_82252948(ctx, base);
loc_82268B28:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82268B30"))) PPC_WEAK_FUNC(sub_82268B30);
PPC_FUNC_IMPL(__imp__sub_82268B30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x82268B38;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82387ba0
	ctx.lr = 0x82268B4C;
	sub_82387BA0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// addi r29,r11,-12360
	r29.s64 = r11.s64 + -12360;
	// lfs f31,30712(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82269098
	if (cr6.eq) goto loc_82269098;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwzx r6,r8,r29
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	// lwzx r27,r10,r7
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// xor r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// and r25,r3,r5
	r25.u64 = ctx.r3.u64 & ctx.r5.u64;
	// bne cr6,0x82268bdc
	if (!cr6.eq) goto loc_82268BDC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268BB4;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82268BB8;
	sub_822A5578(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x82268BC4;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268bdc
	if (cr6.eq) goto loc_82268BDC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268BDC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r29
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x82268c28
	if (!cr6.eq) goto loc_82268C28;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268BFC;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82268C00;
	sub_822A5578(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x82268C0C;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268c6c
	if (cr6.eq) goto loc_82268C6C;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82268c6c
	if (!cr6.eq) goto loc_82268C6C;
	// b 0x82268c58
	goto loc_82268C58;
loc_82268C28:
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// bne cr6,0x82268c6c
	if (!cr6.eq) goto loc_82268C6C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268C3C;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82268C40;
	sub_822A5578(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x82268C4C;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268c6c
	if (cr6.eq) goto loc_82268C6C;
loc_82268C58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252ab8
	ctx.lr = 0x82268C60;
	sub_82252AB8(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268C6C:
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// li r26,1
	r26.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268fe0
	if (cr6.eq) goto loc_82268FE0;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,14
	cr6.compare<int32_t>(ctx.r9.s32, 14, xer);
	// bne cr6,0x82268cbc
	if (!cr6.eq) goto loc_82268CBC;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82268cbc
	if (!cr6.eq) goto loc_82268CBC;
	// rlwinm r11,r25,0,22,22
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268cbc
	if (cr6.eq) goto loc_82268CBC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268a88
	ctx.lr = 0x82268CB0;
	sub_82268A88(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268CBC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,11
	cr6.compare<int32_t>(ctx.r9.s32, 11, xer);
	// beq cr6,0x82268cdc
	if (cr6.eq) goto loc_82268CDC;
	// lbz r11,22(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268d18
	if (cr6.eq) goto loc_82268D18;
loc_82268CDC:
	// rlwinm r11,r25,0,29,29
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268d18
	if (cr6.eq) goto loc_82268D18;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252948
	ctx.lr = 0x82268CF8;
	sub_82252948(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,11
	cr6.compare<int32_t>(ctx.r9.s32, 11, xer);
	// bne cr6,0x82268d14
	if (!cr6.eq) goto loc_82268D14;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268D14:
	// stb r26,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r26.u8);
loc_82268D18:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,12
	cr6.compare<int32_t>(ctx.r9.s32, 12, xer);
	// beq cr6,0x82268d38
	if (cr6.eq) goto loc_82268D38;
	// lbz r11,23(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 23);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268d74
	if (cr6.eq) goto loc_82268D74;
loc_82268D38:
	// rlwinm r11,r25,0,28,28
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268d74
	if (cr6.eq) goto loc_82268D74;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252948
	ctx.lr = 0x82268D54;
	sub_82252948(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,12
	cr6.compare<int32_t>(ctx.r9.s32, 12, xer);
	// bne cr6,0x82268d70
	if (!cr6.eq) goto loc_82268D70;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268D70:
	// stb r26,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r26.u8);
loc_82268D74:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,5
	cr6.compare<int32_t>(ctx.r9.s32, 5, xer);
	// beq cr6,0x82268d98
	if (cr6.eq) goto loc_82268D98;
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268e48
	if (cr6.eq) goto loc_82268E48;
loc_82268D98:
	// rlwinm r11,r27,0,19,19
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268dbc
	if (cr6.eq) goto loc_82268DBC;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,-13512(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// b 0x82268ddc
	goto loc_82268DDC;
loc_82268DBC:
	// rlwinm r11,r27,0,17,17
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268e44
	if (cr6.eq) goto loc_82268E44;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,-13512(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
loc_82268DDC:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,-4944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4944);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,14988(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f12,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	ctx.f12.f64 = double(temp.f32);
	// fsel f10,f11,f0,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsel f0,f9,f12,f10
	f0.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : ctx.f10.f64;
	// stfs f0,-13512(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -13512, temp.u32);
	// lwz r6,168(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r6,368
	r11.s64 = ctx.r6.s64 * 368;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// stfs f0,356(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 356, temp.u32);
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lfs f0,-13512(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f0,352(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 352, temp.u32);
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r5,r11,176
	ctx.r5.s64 = r11.s64 + 176;
	// bl 0x822627c0
	ctx.lr = 0x82268E3C;
	sub_822627C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268808
	ctx.lr = 0x82268E44;
	sub_82268808(ctx, base);
loc_82268E44:
	// stb r26,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r26.u8);
loc_82268E48:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,6
	cr6.compare<int32_t>(ctx.r9.s32, 6, xer);
	// beq cr6,0x82268e68
	if (cr6.eq) goto loc_82268E68;
	// lbz r11,21(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 21);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268f04
	if (cr6.eq) goto loc_82268F04;
loc_82268E68:
	// rlwinm r11,r27,0,16,16
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268e8c
	if (cr6.eq) goto loc_82268E8C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-13516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13516);
	f0.f64 = double(temp.f32);
	// lfs f13,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// b 0x82268eac
	goto loc_82268EAC;
loc_82268E8C:
	// rlwinm r11,r27,0,18,18
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268f00
	if (cr6.eq) goto loc_82268F00;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-13516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13516);
	f0.f64 = double(temp.f32);
	// lfs f13,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
loc_82268EAC:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,-4944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4944);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lfs f13,27640(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f12,-11624(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -11624);
	ctx.f12.f64 = double(temp.f32);
	// fsel f10,f11,f0,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsel f0,f9,f12,f10
	f0.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : ctx.f10.f64;
	// stfs f0,-13516(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -13516, temp.u32);
	// lwz r7,168(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r7,368
	r11.s64 = ctx.r7.s64 * 368;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// stfs f0,344(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 344, temp.u32);
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r5,r11,176
	ctx.r5.s64 = r11.s64 + 176;
	// bl 0x822627c0
	ctx.lr = 0x82268EF8;
	sub_822627C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268870
	ctx.lr = 0x82268F00;
	sub_82268870(ctx, base);
loc_82268F00:
	// stb r26,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r26.u8);
loc_82268F04:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,9
	cr6.compare<int32_t>(ctx.r9.s32, 9, xer);
	// beq cr6,0x82268f24
	if (cr6.eq) goto loc_82268F24;
	// lbz r11,24(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268fe0
	if (cr6.eq) goto loc_82268FE0;
loc_82268F24:
	// rlwinm r11,r25,0,25,25
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268fe0
	if (cr6.eq) goto loc_82268FE0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268F3C;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// ori r5,r9,54592
	ctx.r5.u64 = ctx.r9.u64 | 54592;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,-32122
	r28.s64 = -2105147392;
	// li r4,0
	ctx.r4.s64 = 0;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r28,2272
	r28.s64 = r28.s64 + 2272;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a3998
	ctx.lr = 0x82268FA0;
	sub_822A3998(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f1,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x82268FC0;
	sub_822A9930(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r29
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r29.u32);
	// cmpwi cr6,r6,9
	cr6.compare<int32_t>(ctx.r6.s32, 9, xer);
	// bne cr6,0x82268fdc
	if (!cr6.eq) goto loc_82268FDC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268FDC:
	// stb r26,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r26.u8);
loc_82268FE0:
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82269018
	if (cr6.eq) goto loc_82269018;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r29
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82269014
	if (cr6.eq) goto loc_82269014;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82269014
	if (cr6.eq) goto loc_82269014;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82269018
	if (!cr6.eq) goto loc_82269018;
loc_82269014:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82269018:
	// rlwinm r11,r25,0,23,23
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82269098
	if (cr6.eq) goto loc_82269098;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r29
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// beq cr6,0x8226906c
	if (cr6.eq) goto loc_8226906C;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226906c
	if (!cr6.eq) goto loc_8226906C;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x82269098
	if (!cr6.eq) goto loc_82269098;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252e10
	ctx.lr = 0x82269058;
	sub_82252E10(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// b 0x82269088
	goto loc_82269088;
loc_8226906C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252e10
	ctx.lr = 0x82269078;
	sub_82252E10(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,7
	cr6.compare<int32_t>(ctx.r9.s32, 7, xer);
loc_82269088:
	// bne cr6,0x82269094
	if (!cr6.eq) goto loc_82269094;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82269094:
	// stb r26,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r26.u8);
loc_82269098:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r29
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bgt cr6,0x822691fc
	if (cr6.gt) goto loc_822691FC;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-28476
	r12.s64 = r12.s64 + -28476;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82269108;
	case 1:
		goto loc_82269108;
	case 2:
		goto loc_82269108;
	case 3:
		goto loc_82269108;
	case 4:
		goto loc_82269130;
	case 5:
		goto loc_82269144;
	case 6:
		goto loc_82269144;
	case 7:
		goto loc_822691FC;
	case 8:
		goto loc_822691FC;
	case 9:
		goto loc_82269164;
	case 10:
		goto loc_822691FC;
	case 11:
		goto loc_82269164;
	case 12:
		goto loc_82269164;
	case 13:
		goto loc_822691C4;
	case 14:
		goto loc_82269184;
	case 15:
		goto loc_822691A4;
	case 16:
		goto loc_822691A4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-28408(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28408);
	// lwz r17,-28408(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28408);
	// lwz r17,-28408(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28408);
	// lwz r17,-28408(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28408);
	// lwz r17,-28368(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28368);
	// lwz r17,-28348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28348);
	// lwz r17,-28348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28348);
	// lwz r17,-28164(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28164);
	// lwz r17,-28164(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28164);
	// lwz r17,-28316(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28316);
	// lwz r17,-28164(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28164);
	// lwz r17,-28316(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28316);
	// lwz r17,-28316(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28316);
	// lwz r17,-28220(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28220);
	// lwz r17,-28284(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28284);
	// lwz r17,-28252(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28252);
	// lwz r17,-28252(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28252);
loc_82269108:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4632
	ctx.r5.s64 = r11.s64 + -4632;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x8226911C;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822688d8
	ctx.lr = 0x82269124;
	sub_822688D8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82269130:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822689b0
	ctx.lr = 0x82269138;
	sub_822689B0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82269144:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4712
	ctx.r5.s64 = r11.s64 + -4712;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x82269158;
	sub_82137A08(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82269164:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4800
	ctx.r5.s64 = r11.s64 + -4800;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x82269178;
	sub_82137A08(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82269184:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4880
	ctx.r5.s64 = r11.s64 + -4880;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x82269198;
	sub_82137A08(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_822691A4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4944
	ctx.r5.s64 = r11.s64 + -4944;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x822691B8;
	sub_82137A08(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_822691C4:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// lfs f13,-4304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4304);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,-4304(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4304, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822691fc
	if (!cr6.gt) goto loc_822691FC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,14(r31)
	PPC_STORE_U8(r31.u32 + 14, ctx.r9.u8);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-4304(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4304, temp.u32);
loc_822691FC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82269208"))) PPC_WEAK_FUNC(sub_82269208);
PPC_FUNC_IMPL(__imp__sub_82269208) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// bl 0x82255e68
	ctx.lr = 0x82269250;
	sub_82255E68(ctx, base);
	// lwz r7,3196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 3196);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,3196(r31)
	PPC_STORE_U32(r31.u32 + 3196, ctx.r7.u32);
	// lwz r6,3200(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 3200);
	// stw r6,3200(r31)
	PPC_STORE_U32(r31.u32 + 3200, ctx.r6.u32);
	// lwz r5,3204(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 3204);
	// stw r5,3204(r31)
	PPC_STORE_U32(r31.u32 + 3204, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_82269284"))) PPC_WEAK_FUNC(sub_82269284);
PPC_FUNC_IMPL(__imp__sub_82269284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269288"))) PPC_WEAK_FUNC(sub_82269288);
PPC_FUNC_IMPL(__imp__sub_82269288) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,3080(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3080);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822692b8
	if (!cr6.gt) goto loc_822692B8;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
loc_8226929C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x822692c0
	if (cr6.eq) goto loc_822692C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,192
	ctx.r10.s64 = ctx.r10.s64 + 192;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8226929c
	if (cr6.lt) goto loc_8226929C;
loc_822692B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822692C0:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822692D8"))) PPC_WEAK_FUNC(sub_822692D8);
PPC_FUNC_IMPL(__imp__sub_822692D8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,3080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3080);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x82145020
	ctx.lr = 0x82269300;
	sub_82145020(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82269328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8226935c
	if (cr6.eq) goto loc_8226935C;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// lwz r9,3080(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 3080);
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r8,r10,r9
	ctx.r8.s32 = ctx.r10.s32 / ctx.r9.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// andc r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// twllei r9,0
	// subf r31,r6,r10
	r31.s64 = ctx.r10.s64 - ctx.r6.s64;
	// twlgei r5,-1
loc_8226935C:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
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

__attribute__((alias("__imp__sub_82269388"))) PPC_WEAK_FUNC(sub_82269388);
PPC_FUNC_IMPL(__imp__sub_82269388) {
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
	// lwz r9,3080(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3080);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82269400
	if (!cr6.gt) goto loc_82269400;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
loc_822693B0:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// beq cr6,0x822693e4
	if (cr6.eq) goto loc_822693E4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,192
	ctx.r10.s64 = ctx.r10.s64 + 192;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822693b0
	if (cr6.lt) goto loc_822693B0;
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
loc_822693E4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82269418
	if (!cr6.eq) goto loc_82269418;
loc_82269400:
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
loc_82269418:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226942C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82269460
	if (cr6.eq) goto loc_82269460;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82269400
	if (cr6.eq) goto loc_82269400;
	// lbz r11,278(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82269400
	if (!cr6.eq) goto loc_82269400;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82269458;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82269400
	if (!cr6.eq) goto loc_82269400;
loc_82269460:
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

__attribute__((alias("__imp__sub_82269478"))) PPC_WEAK_FUNC(sub_82269478);
PPC_FUNC_IMPL(__imp__sub_82269478) {
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
	// stwu r1,-3312(r1)
	ea = -3312 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r31,0
	r31.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// bl 0x82250310
	ctx.lr = 0x822694B0;
	sub_82250310(ctx, base);
	// stw r31,3276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3276, r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r31,3280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3280, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,3284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3284, r31.u32);
	// bl 0x82269208
	ctx.lr = 0x822694C8;
	sub_82269208(ctx, base);
	// addi r1,r1,3312
	ctx.r1.s64 = ctx.r1.s64 + 3312;
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

__attribute__((alias("__imp__sub_822694E0"))) PPC_WEAK_FUNC(sub_822694E0);
PPC_FUNC_IMPL(__imp__sub_822694E0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822692d8
	ctx.lr = 0x82269500;
	sub_822692D8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8226951C"))) PPC_WEAK_FUNC(sub_8226951C);
PPC_FUNC_IMPL(__imp__sub_8226951C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269520"))) PPC_WEAK_FUNC(sub_82269520);
PPC_FUNC_IMPL(__imp__sub_82269520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32217
	r11.s64 = -2111373312;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-27528
	ctx.r4.s64 = r11.s64 + -27528;
	// addi r3,r10,-4260
	ctx.r3.s64 = ctx.r10.s64 + -4260;
	// b 0x82554798
	sub_82554798(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82269534"))) PPC_WEAK_FUNC(sub_82269534);
PPC_FUNC_IMPL(__imp__sub_82269534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269538"))) PPC_WEAK_FUNC(sub_82269538);
PPC_FUNC_IMPL(__imp__sub_82269538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32217
	r11.s64 = -2111373312;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-27424
	ctx.r4.s64 = r11.s64 + -27424;
	// addi r3,r10,-4236
	ctx.r3.s64 = ctx.r10.s64 + -4236;
	// b 0x82554798
	sub_82554798(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226954C"))) PPC_WEAK_FUNC(sub_8226954C);
PPC_FUNC_IMPL(__imp__sub_8226954C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269550"))) PPC_WEAK_FUNC(sub_82269550);
PPC_FUNC_IMPL(__imp__sub_82269550) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-3660
	ctx.r10.s64 = r11.s64 + -3660;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e6bc0
	ctx.lr = 0x8226957C;
	sub_822E6BC0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82269594
	if (cr6.eq) goto loc_82269594;
	// bl 0x82130588
	ctx.lr = 0x82269590;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82269594:
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

__attribute__((alias("__imp__sub_822695AC"))) PPC_WEAK_FUNC(sub_822695AC);
PPC_FUNC_IMPL(__imp__sub_822695AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822695B0"))) PPC_WEAK_FUNC(sub_822695B0);
PPC_FUNC_IMPL(__imp__sub_822695B0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-4216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4216);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822695e8
	if (cr6.eq) goto loc_822695E8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822695E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822695E8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r10,-4288
	r30.s64 = ctx.r10.s64 + -4288;
	// stw r11,-4216(r31)
	PPC_STORE_U32(r31.u32 + -4216, r11.u32);
	// mr r31,r30
	r31.u64 = r30.u64;
loc_822695FC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226961c
	if (cr6.eq) goto loc_8226961C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226961C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8226961C:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822695fc
	if (cr6.lt) goto loc_822695FC;
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

__attribute__((alias("__imp__sub_82269644"))) PPC_WEAK_FUNC(sub_82269644);
PPC_FUNC_IMPL(__imp__sub_82269644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269648"))) PPC_WEAK_FUNC(sub_82269648);
PPC_FUNC_IMPL(__imp__sub_82269648) {
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82269650;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d8
	ctx.lr = 0x82269658;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// fmr f29,f2
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f2.f64;
	// lbz r10,-12256(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82269a5c
	if (cr6.eq) goto loc_82269A5C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-4288
	ctx.r9.s64 = r11.s64 + -4288;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwzx r31,r10,r9
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bne cr6,0x82269a5c
	if (!cr6.eq) goto loc_82269A5C;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
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
	// li r4,0
	ctx.r4.s64 = 0;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,2
	ctx.r3.s64 = 2;
	// vpermwi128 v60,v61,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// vpermwi128 v59,v61,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// vpermwi128 v58,v61,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217f768
	ctx.lr = 0x822696D0;
	sub_8217F768(ctx, base);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,-26876(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822696E0;
	sub_8217C088(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x822696E8;
	sub_8217D9A0(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x8217bb68
	ctx.lr = 0x822696FC;
	sub_8217BB68(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	f0.f64 = double(temp.f32);
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lfs f12,120(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f10,124(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	ctx.f10.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f9,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lis r26,-32124
	r26.s64 = -2105278464;
	// lfs f31,15360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 15360);
	f31.f64 = double(temp.f32);
	// lis r25,-32124
	r25.s64 = -2105278464;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// lis r24,-32124
	r24.s64 = -2105278464;
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lis r23,-32124
	r23.s64 = -2105278464;
	// fmuls f0,f10,f31
	f0.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lis r22,-32124
	r22.s64 = -2105278464;
	// fmuls f12,f9,f31
	ctx.f12.f64 = double(float(ctx.f9.f64 * f31.f64));
	// lfs f3,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// lfs f30,17032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	f30.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f7,-26916(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fctiwz f10,f13
	ctx.f10.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f10.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f9,f11
	ctx.f9.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f9.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// fctiwz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r3,r8,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r3,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// bl 0x8217bc28
	ctx.lr = 0x822697B0;
	sub_8217BC28(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f12,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// li r29,0
	r29.s64 = 0;
	// lfs f10,136(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	ctx.f10.f64 = double(temp.f32);
	// addi r20,r11,-4176
	r20.s64 = r11.s64 + -4176;
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// fctiwz f4,f11
	ctx.f4.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f4,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f4.u64);
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f3,f9
	ctx.f3.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f3,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f3.u64);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lfs f8,140(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 140);
	ctx.f8.f64 = double(temp.f32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f7,128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 * f31.f64));
	// fmuls f5,f7,f31
	ctx.f5.f64 = double(float(ctx.f7.f64 * f31.f64));
	// fctiwz f2,f6
	ctx.f2.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f2,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f2.u64);
	// fctiwz f1,f5
	ctx.f1.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f1,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f1.u64);
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwimi r5,r6,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwimi r7,r4,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r7,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// ble cr6,0x8226987c
	if (!cr6.gt) goto loc_8226987C;
	// addi r30,r20,4
	r30.s64 = r20.s64 + 4;
	// b 0x82269838
	goto loc_82269838;
loc_82269834:
	// lwz r9,-26892(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + -26892);
loc_82269838:
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f3,f0,f29
	ctx.f3.f64 = double(float(f0.f64 * f29.f64));
	// lfs f12,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fadds f2,f13,f30
	ctx.f2.f64 = double(float(ctx.f13.f64 + f30.f64));
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f1,f12,f29
	ctx.f1.f64 = double(float(ctx.f12.f64 * f29.f64));
	// lfs f7,-26916(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x82269868;
	sub_8217BC28(ctx, base);
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82269834
	if (cr6.lt) goto loc_82269834;
loc_8226987C:
	// bl 0x8217bc98
	ctx.lr = 0x82269880;
	sub_8217BC98(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// li r3,4
	ctx.r3.s64 = 4;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f0,-31384(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31384);
	f0.f64 = double(temp.f32);
	// fmuls f28,f29,f0
	f28.f64 = double(float(f29.f64 * f0.f64));
	// bl 0x8217bb68
	ctx.lr = 0x8226989C;
	sub_8217BB68(ctx, base);
	// lfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	f0.f64 = double(temp.f32);
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// lfs f12,168(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f10,172(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 172);
	ctx.f10.f64 = double(temp.f32);
	// addi r30,r31,160
	r30.s64 = r31.s64 + 160;
	// lfs f9,160(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f31
	ctx.f8.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fmuls f7,f9,f31
	ctx.f7.f64 = double(float(ctx.f9.f64 * f31.f64));
	// li r21,0
	r21.s64 = 0;
	// fctiwz f6,f13
	ctx.f6.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f6.u64);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f5,f11
	ctx.f5.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f5,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f5.u64);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f4,f8
	ctx.f4.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f4,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f4.u64);
	// fctiwz f3,f7
	ctx.f3.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f3.u64);
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwimi r9,r6,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r9,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// stw r11,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, r11.u32);
	// ble cr6,0x82269a58
	if (!cr6.gt) goto loc_82269A58;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r31,r20,4
	r31.s64 = r20.s64 + 4;
loc_8226991C:
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// lfs f12,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lfs f8,12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// lfs f10,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f4,f8,f31
	ctx.f4.f64 = double(float(ctx.f8.f64 * f31.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lfs f3,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f3,f3,f29
	ctx.f3.f64 = double(float(ctx.f3.f64 * f29.f64));
	// lfs f1,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// fadds f2,f2,f30
	ctx.f2.f64 = double(float(ctx.f2.f64 + f30.f64));
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f1,f1,f29
	ctx.f1.f64 = double(float(ctx.f1.f64 * f29.f64));
	// lfs f7,-26916(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fctiwz f0,f13
	f0.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, f0.u64);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f13,f11
	ctx.f13.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f13,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f11,f4
	ctx.f11.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f11.u64);
	// fctiwz f12,f9
	ctx.f12.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f12,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lfs f4,-26928(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwimi r8,r10,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwimi r11,r7,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r11,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// bl 0x8217bc28
	ctx.lr = 0x822699B0;
	sub_8217BC28(ctx, base);
	// lfs f10,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f0,f10,f31
	f0.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lfs f9,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f9,f31
	ctx.f12.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fmuls f10,f13,f31
	ctx.f10.f64 = double(float(ctx.f13.f64 * f31.f64));
	// lfs f11,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f9,f11,f31
	ctx.f9.f64 = double(float(ctx.f11.f64 * f31.f64));
	// lfs f3,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f3,f3,f28
	ctx.f3.f64 = double(float(ctx.f3.f64 * f28.f64));
	// lfs f1,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// fadds f2,f2,f30
	ctx.f2.f64 = double(float(ctx.f2.f64 + f30.f64));
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f1,f1,f28
	ctx.f1.f64 = double(float(ctx.f1.f64 * f28.f64));
	// lfs f7,-26916(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, f0.u64);
	// fctiwz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// fctiwz f12,f10
	ctx.f12.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f11,f9
	ctx.f11.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// lfs f4,-26928(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stfd f12,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f12.u64);
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stfd f11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f11.u64);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rlwimi r5,r6,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r3,r5,16
	ctx.r3.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwimi r4,r3,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r4,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// bl 0x8217bc28
	ctx.lr = 0x82269A44;
	sub_8217BC28(ctx, base);
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// blt cr6,0x8226991c
	if (cr6.lt) goto loc_8226991C;
loc_82269A58:
	// bl 0x8217bc98
	ctx.lr = 0x82269A5C;
	sub_8217BC98(ctx, base);
loc_82269A5C:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba24
	ctx.lr = 0x82269A68;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82269A6C"))) PPC_WEAK_FUNC(sub_82269A6C);
PPC_FUNC_IMPL(__imp__sub_82269A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269A70"))) PPC_WEAK_FUNC(sub_82269A70);
PPC_FUNC_IMPL(__imp__sub_82269A70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f8
	ctx.lr = 0x82269A78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x82269A84;
	sub_824E0648(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-3644
	ctx.r8.s64 = r11.s64 + -3644;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f13,-13148(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// li r10,160
	ctx.r10.s64 = 160;
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// li r29,144
	r29.s64 = 144;
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lfs f12,27640(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27640);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f12,100(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// lfs f13,-29232(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,104(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lfs f12,-6172(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -6172);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,32680(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32680);
	ctx.f10.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f11,32692(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32692);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,112(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f11,116(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f10,120(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f12,128(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f13,140(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// stfs f11,132(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f10,136(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// lfs f13,3796(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,-12736(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12736);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	ctx.f8.f64 = double(temp.f32);
	// stfs f9,176(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f8,180(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,172(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stvx128 v63,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,192(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stfs f11,196(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f10,200(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// stfs f0,204(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// lfs f12,14884(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f13,216(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f13,220(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// stfs f12,224(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82269BA4"))) PPC_WEAK_FUNC(sub_82269BA4);
PPC_FUNC_IMPL(__imp__sub_82269BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269BA8"))) PPC_WEAK_FUNC(sub_82269BA8);
PPC_FUNC_IMPL(__imp__sub_82269BA8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-3644
	ctx.r10.s64 = r11.s64 + -3644;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e0430
	ctx.lr = 0x82269BD4;
	sub_824E0430(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82269bec
	if (cr6.eq) goto loc_82269BEC;
	// bl 0x82130588
	ctx.lr = 0x82269BE8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82269BEC:
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

__attribute__((alias("__imp__sub_82269C04"))) PPC_WEAK_FUNC(sub_82269C04);
PPC_FUNC_IMPL(__imp__sub_82269C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269C08"))) PPC_WEAK_FUNC(sub_82269C08);
PPC_FUNC_IMPL(__imp__sub_82269C08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-4204
	ctx.r10.s64 = r11.s64 + -4204;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82269c28
	if (cr6.eq) goto loc_82269C28;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-3596
	ctx.r3.s64 = r11.s64 + -3596;
	// blr 
	return;
loc_82269C28:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-3612
	ctx.r3.s64 = r11.s64 + -3612;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82269C34"))) PPC_WEAK_FUNC(sub_82269C34);
PPC_FUNC_IMPL(__imp__sub_82269C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269C38"))) PPC_WEAK_FUNC(sub_82269C38);
PPC_FUNC_IMPL(__imp__sub_82269C38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-3560
	ctx.r3.s64 = r11.s64 + -3560;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82269C44"))) PPC_WEAK_FUNC(sub_82269C44);
PPC_FUNC_IMPL(__imp__sub_82269C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269C48"))) PPC_WEAK_FUNC(sub_82269C48);
PPC_FUNC_IMPL(__imp__sub_82269C48) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-3228
	ctx.r5.s64 = r11.s64 + -3228;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269C84;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-3244
	ctx.r5.s64 = ctx.r10.s64 + -3244;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269CA4;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-3260
	ctx.r5.s64 = ctx.r9.s64 + -3260;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,48
	ctx.r6.s64 = r31.s64 + 48;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269CC4;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-3284
	ctx.r5.s64 = ctx.r8.s64 + -3284;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,80
	ctx.r6.s64 = r31.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269CE4;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-3304
	ctx.r5.s64 = ctx.r7.s64 + -3304;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,64
	ctx.r6.s64 = r31.s64 + 64;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269D04;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-3328
	ctx.r5.s64 = ctx.r6.s64 + -3328;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269D24;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-3344
	ctx.r5.s64 = ctx.r5.s64 + -3344;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,208
	ctx.r6.s64 = r31.s64 + 208;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269D44;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-3360
	ctx.r5.s64 = ctx.r4.s64 + -3360;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,212
	ctx.r6.s64 = r31.s64 + 212;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269D64;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-3380
	ctx.r5.s64 = r11.s64 + -3380;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82269D84;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-3400
	ctx.r5.s64 = ctx.r10.s64 + -3400;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82269DA4;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-3420
	ctx.r5.s64 = ctx.r9.s64 + -3420;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82269DC4;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-3440
	ctx.r5.s64 = ctx.r8.s64 + -3440;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82269DE4;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-3452
	ctx.r5.s64 = ctx.r7.s64 + -3452;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,192
	ctx.r6.s64 = r31.s64 + 192;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82269E04;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-3464
	ctx.r5.s64 = ctx.r6.s64 + -3464;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,176
	ctx.r6.s64 = r31.s64 + 176;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269E24;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-3480
	ctx.r5.s64 = ctx.r5.s64 + -3480;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,180
	ctx.r6.s64 = r31.s64 + 180;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269E44;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-3492
	ctx.r5.s64 = ctx.r4.s64 + -3492;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269E64;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-3520
	ctx.r5.s64 = r11.s64 + -3520;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,216
	ctx.r6.s64 = r31.s64 + 216;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269E84;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-3552
	ctx.r5.s64 = ctx.r10.s64 + -3552;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,220
	ctx.r6.s64 = r31.s64 + 220;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82269EA4;
	sub_824DF200(ctx, base);
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

__attribute__((alias("__imp__sub_82269EBC"))) PPC_WEAK_FUNC(sub_82269EBC);
PPC_FUNC_IMPL(__imp__sub_82269EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269EC0"))) PPC_WEAK_FUNC(sub_82269EC0);
PPC_FUNC_IMPL(__imp__sub_82269EC0) {
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
	ctx.lr = 0x82269EC8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x822e6a80
	ctx.lr = 0x82269ED8;
	sub_822E6A80(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82269ef4
	if (cr6.eq) goto loc_82269EF4;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82269EF4:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x82269EFC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82269f1c
	if (cr6.eq) goto loc_82269F1C;
	// bl 0x822e6d98
	ctx.lr = 0x82269F0C;
	sub_822E6D98(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-3660
	ctx.r10.s64 = r11.s64 + -3660;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82269f20
	goto loc_82269F20;
loc_82269F1C:
	// li r31,0
	r31.s64 = 0;
loc_82269F20:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e6c18
	ctx.lr = 0x82269F2C;
	sub_822E6C18(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822e6ad0
	ctx.lr = 0x82269F38;
	sub_822E6AD0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82269F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82269F5C"))) PPC_WEAK_FUNC(sub_82269F5C);
PPC_FUNC_IMPL(__imp__sub_82269F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269F60"))) PPC_WEAK_FUNC(sub_82269F60);
PPC_FUNC_IMPL(__imp__sub_82269F60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x82269f7c
	if (cr6.eq) goto loc_82269F7C;
	// b 0x82263128
	sub_82263128(ctx, base);
	return;
loc_82269F7C:
	// b 0x82262960
	sub_82262960(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82269F80"))) PPC_WEAK_FUNC(sub_82269F80);
PPC_FUNC_IMPL(__imp__sub_82269F80) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82269F84"))) PPC_WEAK_FUNC(sub_82269F84);
PPC_FUNC_IMPL(__imp__sub_82269F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269F88"))) PPC_WEAK_FUNC(sub_82269F88);
PPC_FUNC_IMPL(__imp__sub_82269F88) {
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
	ctx.lr = 0x82269FA0;
	sub_822E6F68(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-3208
	ctx.r10.s64 = r11.s64 + -3208;
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

__attribute__((alias("__imp__sub_82269FC4"))) PPC_WEAK_FUNC(sub_82269FC4);
PPC_FUNC_IMPL(__imp__sub_82269FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269FC8"))) PPC_WEAK_FUNC(sub_82269FC8);
PPC_FUNC_IMPL(__imp__sub_82269FC8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-3208
	ctx.r10.s64 = r11.s64 + -3208;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e6e68
	ctx.lr = 0x82269FF4;
	sub_822E6E68(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226a00c
	if (cr6.eq) goto loc_8226A00C;
	// bl 0x82130588
	ctx.lr = 0x8226A008;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226A00C:
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

__attribute__((alias("__imp__sub_8226A024"))) PPC_WEAK_FUNC(sub_8226A024);
PPC_FUNC_IMPL(__imp__sub_8226A024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A028"))) PPC_WEAK_FUNC(sub_8226A028);
PPC_FUNC_IMPL(__imp__sub_8226A028) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-3192
	ctx.r9.s64 = r11.s64 + -3192;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x8226A060;
	sub_822E5148(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-3664(r8)
	PPC_STORE_U32(ctx.r8.u32 + -3664, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x8226A074;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8226a08c
	if (cr6.eq) goto loc_8226A08C;
	// bl 0x82130588
	ctx.lr = 0x8226A088;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226A08C:
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

__attribute__((alias("__imp__sub_8226A0A4"))) PPC_WEAK_FUNC(sub_8226A0A4);
PPC_FUNC_IMPL(__imp__sub_8226A0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A0A8"))) PPC_WEAK_FUNC(sub_8226A0A8);
PPC_FUNC_IMPL(__imp__sub_8226A0A8) {
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
	// bl 0x823d91f4
	ctx.lr = 0x8226A0B0;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9cc
	ctx.lr = 0x8226A0B8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f26,-28880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28880);
	f26.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f27,-19928(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19928);
	f27.f64 = double(temp.f32);
	// lfs f29,-3164(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3164);
	f29.f64 = double(temp.f32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,-6172(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -6172);
	f31.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f25,-29232(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -29232);
	f25.f64 = double(temp.f32);
	// lfs f28,-26928(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -26928);
	f28.f64 = double(temp.f32);
	// li r29,0
	r29.s64 = 0;
	// lfs f30,32692(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32692);
	f30.f64 = double(temp.f32);
	// addi r31,r11,-4288
	r31.s64 = r11.s64 + -4288;
	// addi r28,r10,9572
	r28.s64 = ctx.r10.s64 + 9572;
	// addi r27,r9,-12248
	r27.s64 = ctx.r9.s64 + -12248;
loc_8226A110:
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r6,r30,r27
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + r27.u32);
	// bl 0x82137a08
	ctx.lr = 0x8226A128;
	sub_82137A08(ctx, base);
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x8226A130;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226a140
	if (cr6.eq) goto loc_8226A140;
	// bl 0x82269a70
	ctx.lr = 0x8226A13C;
	sub_82269A70(ctx, base);
	// b 0x8226a144
	goto loc_8226A144;
loc_8226A140:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226A144:
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// bl 0x824e06e0
	ctx.lr = 0x8226A154;
	sub_824E06E0(ctx, base);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8226A178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// bne cr6,0x8226a1dc
	if (!cr6.eq) goto loc_8226A1DC;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f30,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f30,116(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f30,120(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f28,124(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f30,128(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f30,132(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// stfs f30,136(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f28,140(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f30,144(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f30,148(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f30,152(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f25,156(r11)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f30,164(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
	// stfs f30,168(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f25,172(r11)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// b 0x8226a368
	goto loc_8226A368;
loc_8226A1DC:
	// cmpwi cr6,r29,13
	cr6.compare<int32_t>(r29.s32, 13, xer);
	// bne cr6,0x8226a244
	if (!cr6.eq) goto loc_8226A244;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f31,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f30,116(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f31,120(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f29,124(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f31,128(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f30,132(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f31,136(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f29,140(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f31,144(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f30,148(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f31,156(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f31,160(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
	// stfs f30,164(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
	// stfs f31,168(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f31,172(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// b 0x8226a36c
	goto loc_8226A36C;
loc_8226A244:
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x8226a2a0
	if (!cr6.eq) goto loc_8226A2A0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f30,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f31,116(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f31,120(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f29,124(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f30,128(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f31,132(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// stfs f31,136(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f29,140(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f30,144(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// stfs f31,148(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f31,156(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stfs f31,172(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// b 0x8226a360
	goto loc_8226A360;
loc_8226A2A0:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8226a308
	if (!cr6.eq) goto loc_8226A308;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f30,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f27,116(r11)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f31,120(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f29,124(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f30,128(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f27,132(r11)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// stfs f31,136(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f29,140(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f26,144(r11)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// stfs f28,148(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f31,156(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f26,160(r11)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
	// stfs f28,164(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
	// stfs f31,168(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f31,172(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// b 0x8226a36c
	goto loc_8226A36C;
loc_8226A308:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x8226a370
	if (!cr6.eq) goto loc_8226A370;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f30,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f30,116(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f30,120(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f28,124(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f30,128(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f30,132(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// stfs f30,136(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f28,140(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f30,144(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// stfs f31,148(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f29,156(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stfs f29,172(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
loc_8226A360:
	// stfs f31,168(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f31,164(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
loc_8226A368:
	// stfs f30,160(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
loc_8226A36C:
	// addi r10,r11,160
	ctx.r10.s64 = r11.s64 + 160;
loc_8226A370:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,18
	cr6.compare<int32_t>(r29.s32, 18, xer);
	// blt cr6,0x8226a110
	if (cr6.lt) goto loc_8226A110;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r10,r10,-4176
	ctx.r10.s64 = ctx.r10.s64 + -4176;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r31,r10,8
	r31.s64 = ctx.r10.s64 + 8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,32
	r11.s64 = 32;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// stw r11,-4212(r29)
	PPC_STORE_U32(r29.u32 + -4212, r11.u32);
	// lfs f29,18204(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18204);
	f29.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
loc_8226A3B0:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stfs f30,-8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// extsw r10,r30
	ctx.r10.s64 = r30.s32;
	// stfs f31,-4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -4, temp.u32);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// fmuls f28,f8,f29
	f28.f64 = double(float(ctx.f8.f64 * f29.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbae8
	ctx.lr = 0x8226A3F8;
	sub_823DBAE8(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(ctx.f1.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8226A404;
	sub_823DBBC8(ctx, base);
	// lfs f7,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// frsp f6,f1
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// lfs f5,-8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -8);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f7,f27
	ctx.f4.f64 = double(float(ctx.f7.f64 * f27.f64));
	// fmuls f3,f5,f27
	ctx.f3.f64 = double(float(ctx.f5.f64 * f27.f64));
	// lwz r11,-4212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -4212);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// fmadds f2,f5,f6,f4
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f6.f64 + ctx.f4.f64));
	// stfs f2,-8(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// fmsubs f1,f7,f6,f3
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f6.f64 - ctx.f3.f64));
	// stfs f1,0(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// blt cr6,0x8226a3b0
	if (cr6.lt) goto loc_8226A3B0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lfs f0,-3168(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3168);
	f0.f64 = double(temp.f32);
	// lfs f13,-3172(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -3172);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,-4208(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4208, temp.u32);
	// stfs f13,-12260(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + -12260, temp.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba18
	ctx.lr = 0x8226A468;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226A46C"))) PPC_WEAK_FUNC(sub_8226A46C);
PPC_FUNC_IMPL(__imp__sub_8226A46C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A470"))) PPC_WEAK_FUNC(sub_8226A470);
PPC_FUNC_IMPL(__imp__sub_8226A470) {
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
	ctx.lr = 0x8226A488;
	sub_822E6B38(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-3192
	ctx.r8.s64 = r11.s64 + -3192;
	// ori r7,r10,1
	ctx.r7.u64 = ctx.r10.u64 | 1;
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
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x8226A4BC;
	sub_822E5138(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r4,r5,-3156
	ctx.r4.s64 = ctx.r5.s64 + -3156;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// bl 0x8226a0a8
	ctx.lr = 0x8226A4CC;
	sub_8226A0A8(ctx, base);
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

__attribute__((alias("__imp__sub_8226A4E4"))) PPC_WEAK_FUNC(sub_8226A4E4);
PPC_FUNC_IMPL(__imp__sub_8226A4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A4E8"))) PPC_WEAK_FUNC(sub_8226A4E8);
PPC_FUNC_IMPL(__imp__sub_8226A4E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-3136
	ctx.r3.s64 = r11.s64 + -3136;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A4F4"))) PPC_WEAK_FUNC(sub_8226A4F4);
PPC_FUNC_IMPL(__imp__sub_8226A4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A4F8"))) PPC_WEAK_FUNC(sub_8226A4F8);
PPC_FUNC_IMPL(__imp__sub_8226A4F8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// lwz r3,-3664(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3664);
	// bl 0x82269ec0
	ctx.lr = 0x8226A520;
	sub_82269EC0(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x822e6c50
	ctx.lr = 0x8226A530;
	sub_822E6C50(ctx, base);
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

__attribute__((alias("__imp__sub_8226A544"))) PPC_WEAK_FUNC(sub_8226A544);
PPC_FUNC_IMPL(__imp__sub_8226A544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A548"))) PPC_WEAK_FUNC(sub_8226A548);
PPC_FUNC_IMPL(__imp__sub_8226A548) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-3156
	ctx.r10.s64 = r11.s64 + -3156;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822695b0
	ctx.lr = 0x8226A574;
	sub_822695B0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r7,r9,-3192
	ctx.r7.s64 = ctx.r9.s64 + -3192;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r3,-8092(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x8226A590;
	sub_822E5148(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-3664(r6)
	PPC_STORE_U32(ctx.r6.u32 + -3664, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x8226A5A4;
	sub_822E6940(ctx, base);
	// clrlwi r5,r30,31
	ctx.r5.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8226a5bc
	if (cr6.eq) goto loc_8226A5BC;
	// bl 0x82130588
	ctx.lr = 0x8226A5B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226A5BC:
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

__attribute__((alias("__imp__sub_8226A5D4"))) PPC_WEAK_FUNC(sub_8226A5D4);
PPC_FUNC_IMPL(__imp__sub_8226A5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A5D8"))) PPC_WEAK_FUNC(sub_8226A5D8);
PPC_FUNC_IMPL(__imp__sub_8226A5D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// li r31,-1
	r31.s64 = -1;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8226A5F4:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8226a5f4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8226A5F4;
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x8226a6ec
	if (cr6.eq) goto loc_8226A6EC;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8226a6ec
	if (!cr6.lt) goto loc_8226A6EC;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r10,r4,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// li r8,0
	ctx.r8.s64 = 0;
	// divw r11,r4,r9
	r11.s32 = ctx.r4.s32 / ctx.r9.s32;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// mullw r10,r9,r11
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// twllei r9,0
	// andc r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// twlgei r9,-1
	// subf r4,r10,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r10.s64;
	// cmpw cr6,r6,r30
	cr6.compare<int32_t>(ctx.r6.s32, r30.s32, xer);
	// bgt cr6,0x8226a6ec
	if (cr6.gt) goto loc_8226A6EC;
loc_8226A64C:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x8226a6c0
	if (cr6.lt) goto loc_8226A6C0;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x8226a6c0
	if (!cr6.lt) goto loc_8226A6C0;
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// addi r7,r4,1
	ctx.r7.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// bgt cr6,0x8226a6e0
	if (cr6.gt) goto loc_8226A6E0;
	// subf r9,r11,r7
	ctx.r9.s64 = ctx.r7.s64 - r11.s64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
loc_8226A684:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8226a6a8
	if (cr6.lt) goto loc_8226A6A8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8226a6a8
	if (!cr6.lt) goto loc_8226A6A8;
	// mullw r9,r9,r6
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// b 0x8226a6ac
	goto loc_8226A6AC;
loc_8226A6A8:
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
loc_8226A6AC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// ble cr6,0x8226a684
	if (!cr6.gt) goto loc_8226A684;
	// b 0x8226a6e0
	goto loc_8226A6E0;
loc_8226A6C0:
	// addi r10,r8,2
	ctx.r10.s64 = ctx.r8.s64 + 2;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// stwx r31,r9,r5
	PPC_STORE_U32(ctx.r9.u32 + ctx.r5.u32, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8226A6E0:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r30
	cr6.compare<int32_t>(ctx.r6.s32, r30.s32, xer);
	// ble cr6,0x8226a64c
	if (!cr6.gt) goto loc_8226A64C;
loc_8226A6EC:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A6F8"))) PPC_WEAK_FUNC(sub_8226A6F8);
PPC_FUNC_IMPL(__imp__sub_8226A6F8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8226a780
	if (cr6.lt) goto loc_8226A780;
	// lfs f12,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8226a780
	if (!cr6.lt) goto loc_8226A780;
	// lfs f12,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x8226a780
	if (cr6.lt) goto loc_8226A780;
	// lfs f11,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x8226a780
	if (!cr6.lt) goto loc_8226A780;
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-3072(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3072);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,0,r4
	PPC_STORE_U32(ctx.r4.u32, ctx.f11.u32);
	// lfs f10,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f6.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r3,r8,16
	ctx.r3.u64 = ctx.r8.u32 & 0xFFFF;
	// blr 
	return;
loc_8226A780:
	// li r11,0
	r11.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A794"))) PPC_WEAK_FUNC(sub_8226A794);
PPC_FUNC_IMPL(__imp__sub_8226A794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A798"))) PPC_WEAK_FUNC(sub_8226A798);
PPC_FUNC_IMPL(__imp__sub_8226A798) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8226a7bc
	if (cr6.lt) goto loc_8226A7BC;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8226a7bc
	if (!cr6.lt) goto loc_8226A7BC;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
loc_8226A7BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A7C4"))) PPC_WEAK_FUNC(sub_8226A7C4);
PPC_FUNC_IMPL(__imp__sub_8226A7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A7C8"))) PPC_WEAK_FUNC(sub_8226A7C8);
PPC_FUNC_IMPL(__imp__sub_8226A7C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8226a800
	if (cr6.lt) goto loc_8226A800;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8226a800
	if (!cr6.lt) goto loc_8226A800;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x8226a800
	if (cr6.lt) goto loc_8226A800;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// bge cr6,0x8226a800
	if (!cr6.lt) goto loc_8226A800;
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = r11.u32 & 0xFFFF;
	// blr 
	return;
loc_8226A800:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A808"))) PPC_WEAK_FUNC(sub_8226A808);
PPC_FUNC_IMPL(__imp__sub_8226A808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8226A810;
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x8226a910
	if (cr6.eq) goto loc_8226A910;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8226a910
	if (!cr6.lt) goto loc_8226A910;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r10,r4,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// li r31,0
	r31.s64 = 0;
	// divw r11,r4,r9
	r11.s32 = ctx.r4.s32 / ctx.r9.s32;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// mullw r6,r9,r11
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// andc r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// twllei r9,0
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// twlgei r10,-1
	// subf r4,r6,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r6.s64;
	// cmpw cr6,r7,r30
	cr6.compare<int32_t>(ctx.r7.s32, r30.s32, xer);
	// bgt cr6,0x8226a92c
	if (cr6.gt) goto loc_8226A92C;
loc_8226A860:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x8226a8e0
	if (cr6.lt) goto loc_8226A8E0;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// bge cr6,0x8226a8e0
	if (!cr6.lt) goto loc_8226A8E0;
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// addi r6,r4,1
	ctx.r6.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bgt cr6,0x8226a900
	if (cr6.gt) goto loc_8226A900;
	// subf r9,r11,r6
	ctx.r9.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
loc_8226A898:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8226a8c8
	if (cr6.lt) goto loc_8226A8C8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8226a8c8
	if (!cr6.lt) goto loc_8226A8C8;
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// lwz r29,28(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// b 0x8226a8cc
	goto loc_8226A8CC;
loc_8226A8C8:
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
loc_8226A8CC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// ble cr6,0x8226a898
	if (!cr6.gt) goto loc_8226A898;
	// b 0x8226a900
	goto loc_8226A900;
loc_8226A8E0:
	// addi r10,r8,2
	ctx.r10.s64 = ctx.r8.s64 + 2;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// stwx r31,r9,r5
	PPC_STORE_U32(ctx.r9.u32 + ctx.r5.u32, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8226A900:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r7,r30
	cr6.compare<int32_t>(ctx.r7.s32, r30.s32, xer);
	// ble cr6,0x8226a860
	if (!cr6.gt) goto loc_8226A860;
	// b 0x823d924c
	return;
loc_8226A910:
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,9
	ctx.r9.s64 = 9;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8226A920:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8226a920
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8226A920;
loc_8226A92C:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226A930"))) PPC_WEAK_FUNC(sub_8226A930);
PPC_FUNC_IMPL(__imp__sub_8226A930) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lhz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226a994
	if (!cr6.eq) goto loc_8226A994;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// beq cr6,0x8226a9b4
	if (cr6.eq) goto loc_8226A9B4;
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// li r11,-1
	r11.s64 = -1;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// sth r11,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, r11.u16);
	// blr 
	return;
loc_8226A994:
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8226a9b4
	if (cr6.eq) goto loc_8226A9B4;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
loc_8226A9B4:
	// li r11,-1
	r11.s64 = -1;
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// sth r11,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A9C8"))) PPC_WEAK_FUNC(sub_8226A9C8);
PPC_FUNC_IMPL(__imp__sub_8226A9C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lis r11,0
	r11.s64 = 0;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// ori r4,r11,65535
	ctx.r4.u64 = r11.u64 | 65535;
loc_8226A9E8:
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226aa80
	if (cr6.eq) goto loc_8226AA80;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// bge cr6,0x8226aa70
	if (!cr6.lt) goto loc_8226AA70;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8226aa44
	if (!cr6.eq) goto loc_8226AA44;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226aa64
	if (cr6.eq) goto loc_8226AA64;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// b 0x8226aa64
	goto loc_8226AA64;
loc_8226AA44:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226aa64
	if (cr6.eq) goto loc_8226AA64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
loc_8226AA64:
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
loc_8226AA70:
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226a9e8
	if (!cr6.eq) goto loc_8226A9E8;
loc_8226AA80:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// blt cr6,0x8226a9e8
	if (cr6.lt) goto loc_8226A9E8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226AA98"))) PPC_WEAK_FUNC(sub_8226AA98);
PPC_FUNC_IMPL(__imp__sub_8226AA98) {
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
	ctx.lr = 0x8226AAA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8226aac0
	if (!cr6.lt) goto loc_8226AAC0;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8226AAC0:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfs f0,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x8226aad4
	if (cr6.lt) goto loc_8226AAD4;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8226AAD4:
	// stfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lfs f13,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// lfs f12,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// bgt cr6,0x8226aaf0
	if (cr6.gt) goto loc_8226AAF0;
	// fmr f9,f13
	ctx.f9.f64 = ctx.f13.f64;
loc_8226AAF0:
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f9,0(r5)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bgt cr6,0x8226ab04
	if (cr6.gt) goto loc_8226AB04;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8226AB04:
	// stfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f7,f9,f12
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f5,f7,f7
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fsubs f6,f0,f13
	ctx.f6.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfd f12,32224(r11)
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + 32224);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfd f11,21560(r10)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 21560);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,-3072(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3072);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f4,f6,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// frsqrte f3,f4
	// fneg f2,f4
	ctx.f2.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// fmul f1,f3,f3
	ctx.f1.f64 = ctx.f3.f64 * ctx.f3.f64;
	// fmul f5,f3,f12
	ctx.f5.f64 = ctx.f3.f64 * ctx.f12.f64;
	// fnmsub f1,f1,f4,f11
	ctx.f1.f64 = -(ctx.f1.f64 * ctx.f4.f64 - ctx.f11.f64);
	// fmadd f5,f1,f5,f3
	ctx.f5.f64 = ctx.f1.f64 * ctx.f5.f64 + ctx.f3.f64;
	// fmul f3,f5,f5
	ctx.f3.f64 = ctx.f5.f64 * ctx.f5.f64;
	// fmul f1,f5,f12
	ctx.f1.f64 = ctx.f5.f64 * ctx.f12.f64;
	// fnmsub f12,f3,f4,f11
	ctx.f12.f64 = -(ctx.f3.f64 * ctx.f4.f64 - ctx.f11.f64);
	// fmadd f11,f12,f1,f5
	ctx.f11.f64 = ctx.f12.f64 * ctx.f1.f64 + ctx.f5.f64;
	// frsp f5,f11
	ctx.f5.f64 = double(float(ctx.f11.f64));
	// fsel f4,f2,f13,f5
	ctx.f4.f64 = ctx.f2.f64 >= 0.0 ? ctx.f13.f64 : ctx.f5.f64;
	// fmuls f3,f4,f7
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f7.f64));
	// fmuls f2,f6,f4
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f4.f64));
	// fmuls f1,f3,f10
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fmuls f12,f2,f10
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fadds f11,f9,f1
	ctx.f11.f64 = double(float(ctx.f9.f64 + ctx.f1.f64));
	// stfs f11,0(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fadds f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f10,4(r5)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lfs f9,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f0,f7,f1
	f0.f64 = double(float(ctx.f7.f64 - ctx.f1.f64));
	// fsubs f12,f9,f12
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f12,4(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8226abc0
	if (cr6.lt) goto loc_8226ABC0;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x8226abd4
	goto loc_8226ABD4;
loc_8226ABC0:
	// fmuls f0,f0,f8
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f8.f64));
	// fctiwz f11,f0
	ctx.f11.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r7,r11,1
	xer.ca = r11.u32 <= 1;
	ctx.r7.s64 = 1 - r11.s64;
loc_8226ABD4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lfs f11,-3068(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3068);
	ctx.f11.f64 = double(temp.f32);
	// bgt cr6,0x8226abf0
	if (cr6.gt) goto loc_8226ABF0;
	// li r11,0
	r11.s64 = 0;
	// b 0x8226ac04
	goto loc_8226AC04;
loc_8226ABF0:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f10,f0
	ctx.f10.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r11,r11,1
	xer.ca = r11.u32 <= 1;
	r11.s64 = 1 - r11.s64;
loc_8226AC04:
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x8226ac14
	if (cr6.lt) goto loc_8226AC14;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8226ac28
	goto loc_8226AC28;
loc_8226AC14:
	// fmuls f0,f12,f8
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// fctiwz f12,f0
	ctx.f12.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r8,r10,1
	xer.ca = ctx.r10.u32 <= 1;
	ctx.r8.s64 = 1 - ctx.r10.s64;
loc_8226AC28:
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x8226ac3c
	if (cr6.gt) goto loc_8226AC3C;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8226ac50
	goto loc_8226AC50;
loc_8226AC3C:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r10,r10,1
	xer.ca = ctx.r10.u32 <= 1;
	ctx.r10.s64 = 1 - ctx.r10.s64;
loc_8226AC50:
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x8226ac68
	if (!cr6.lt) goto loc_8226AC68;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_8226AC68:
	// add r11,r10,r8
	r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bge cr6,0x8226ac7c
	if (!cr6.lt) goto loc_8226AC7C;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
loc_8226AC7C:
	// extsw r11,r8
	r11.s64 = ctx.r8.s32;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// extsw r8,r7
	ctx.r8.s64 = ctx.r7.s32;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f9,96(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,29496(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 29496);
	f0.f64 = double(temp.f32);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// mullw r29,r10,r9
	r29.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// frsp f4,f10
	ctx.f4.f64 = double(float(ctx.f10.f64));
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f13,31304(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31304);
	ctx.f13.f64 = double(temp.f32);
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
	// fmuls f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f1,16(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// fmuls f5,f11,f0
	ctx.f5.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f5,12(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fmadds f0,f2,f13,f5
	f0.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fmadds f13,f3,f13,f1
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f13.f64 + ctx.f1.f64));
	// stfs f13,24(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// beq cr6,0x8226ad24
	if (cr6.eq) goto loc_8226AD24;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8226AD20;
	sub_82130528(ctx, base);
	// b 0x8226ad28
	goto loc_8226AD28;
loc_8226AD24:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226AD28:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// clrlwi r10,r29,16
	ctx.r10.u64 = r29.u32 & 0xFFFF;
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bne cr6,0x8226ad60
	if (!cr6.eq) goto loc_8226AD60;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// beq cr6,0x8226ad58
	if (cr6.eq) goto loc_8226AD58;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8226AD54;
	sub_82130528(ctx, base);
	// b 0x8226ad5c
	goto loc_8226AD5C;
loc_8226AD58:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226AD5C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8226AD60:
	// sth r29,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r29.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823d9890
	ctx.lr = 0x8226AD78;
	sub_823D9890(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226AD80"))) PPC_WEAK_FUNC(sub_8226AD80);
PPC_FUNC_IMPL(__imp__sub_8226AD80) {
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
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x8226a6f8
	ctx.lr = 0x8226AD9C;
	sub_8226A6F8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226ADAC"))) PPC_WEAK_FUNC(sub_8226ADAC);
PPC_FUNC_IMPL(__imp__sub_8226ADAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226ADB0"))) PPC_WEAK_FUNC(sub_8226ADB0);
PPC_FUNC_IMPL(__imp__sub_8226ADB0) {
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
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226ADE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r3,48
	ctx.r6.s64 = ctx.r3.s64 + 48;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226a6f8
	ctx.lr = 0x8226ADF4;
	sub_8226A6F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplw cr6,r9,r6
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, xer);
	// beq cr6,0x8226ae68
	if (cr6.eq) goto loc_8226AE68;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226a930
	ctx.lr = 0x8226AE14;
	sub_8226A930(ctx, base);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8226ae68
	if (cr6.eq) goto loc_8226AE68;
	// sth r5,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r5.u16);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x8226ae68
	if (!cr6.lt) goto loc_8226AE68;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// lwz r7,28(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r6,r11,r7
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8226ae60
	if (cr6.eq) goto loc_8226AE60;
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stw r31,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r31.u32);
loc_8226AE60:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// stwx r31,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r31.u32);
loc_8226AE68:
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

__attribute__((alias("__imp__sub_8226AE80"))) PPC_WEAK_FUNC(sub_8226AE80);
PPC_FUNC_IMPL(__imp__sub_8226AE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r3,-3660(r9)
	PPC_STORE_U32(ctx.r9.u32 + -3660, ctx.r3.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stb r10,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r10.u8);
	// stfs f0,44(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stb r10,37(r3)
	PPC_STORE_U8(ctx.r3.u32 + 37, ctx.r10.u8);
	// stb r10,38(r3)
	PPC_STORE_U8(ctx.r3.u32 + 38, ctx.r10.u8);
	// stb r11,39(r3)
	PPC_STORE_U8(ctx.r3.u32 + 39, r11.u8);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226AEE0"))) PPC_WEAK_FUNC(sub_8226AEE0);
PPC_FUNC_IMPL(__imp__sub_8226AEE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-3660(r10)
	PPC_STORE_U32(ctx.r10.u32 + -3660, r11.u32);
	// lhz r9,34(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 34);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226AF00"))) PPC_WEAK_FUNC(sub_8226AF00);
PPC_FUNC_IMPL(__imp__sub_8226AF00) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226AF04"))) PPC_WEAK_FUNC(sub_8226AF04);
PPC_FUNC_IMPL(__imp__sub_8226AF04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226AF08"))) PPC_WEAK_FUNC(sub_8226AF08);
PPC_FUNC_IMPL(__imp__sub_8226AF08) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r30,12
	ctx.r4.s64 = r30.s64 + 12;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// bl 0x824ea3b8
	ctx.lr = 0x8226AF48;
	sub_824EA3B8(ctx, base);
	// lwz r8,528(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 528);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,528(r31)
	PPC_STORE_U32(r31.u32 + 528, ctx.r8.u32);
	// lwz r7,532(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 532);
	// stw r7,532(r31)
	PPC_STORE_U32(r31.u32 + 532, ctx.r7.u32);
	// lwz r6,536(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 536);
	// stw r6,536(r31)
	PPC_STORE_U32(r31.u32 + 536, ctx.r6.u32);
	// ld r5,544(r30)
	ctx.r5.u64 = PPC_LOAD_U64(r30.u32 + 544);
	// std r5,544(r31)
	PPC_STORE_U64(r31.u32 + 544, ctx.r5.u64);
	// ld r4,552(r30)
	ctx.r4.u64 = PPC_LOAD_U64(r30.u32 + 552);
	// std r4,552(r31)
	PPC_STORE_U64(r31.u32 + 552, ctx.r4.u64);
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

__attribute__((alias("__imp__sub_8226AF8C"))) PPC_WEAK_FUNC(sub_8226AF8C);
PPC_FUNC_IMPL(__imp__sub_8226AF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226AF90"))) PPC_WEAK_FUNC(sub_8226AF90);
PPC_FUNC_IMPL(__imp__sub_8226AF90) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-2620
	ctx.r9.s64 = r11.s64 + -2620;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8226afc4
	if (cr6.eq) goto loc_8226AFC4;
	// bl 0x82130588
	ctx.lr = 0x8226AFC0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226AFC4:
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

__attribute__((alias("__imp__sub_8226AFD8"))) PPC_WEAK_FUNC(sub_8226AFD8);
PPC_FUNC_IMPL(__imp__sub_8226AFD8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-2588
	ctx.r9.s64 = r11.s64 + -2588;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8226b00c
	if (cr6.eq) goto loc_8226B00C;
	// bl 0x82130588
	ctx.lr = 0x8226B008;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226B00C:
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

__attribute__((alias("__imp__sub_8226B020"))) PPC_WEAK_FUNC(sub_8226B020);
PPC_FUNC_IMPL(__imp__sub_8226B020) {
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
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x8226B03C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226b058
	if (cr6.eq) goto loc_8226B058;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226b05c
	if (!cr6.eq) goto loc_8226B05C;
loc_8226B058:
	// li r11,0
	r11.s64 = 0;
loc_8226B05C:
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

__attribute__((alias("__imp__sub_8226B074"))) PPC_WEAK_FUNC(sub_8226B074);
PPC_FUNC_IMPL(__imp__sub_8226B074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B078"))) PPC_WEAK_FUNC(sub_8226B078);
PPC_FUNC_IMPL(__imp__sub_8226B078) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8226B080;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// ori r10,r10,32779
	ctx.r10.u64 = ctx.r10.u64 | 32779;
	// ori r9,r9,8
	ctx.r9.u64 = ctx.r9.u64 | 8;
	// ori r8,r8,9
	ctx.r8.u64 = ctx.r8.u64 | 9;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lis r7,4096
	ctx.r7.s64 = 268435456;
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lis r6,4096
	ctx.r6.s64 = 268435456;
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// lis r5,4096
	ctx.r5.s64 = 268435456;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// lis r31,4096
	r31.s64 = 268435456;
	// lis r30,4096
	r30.s64 = 268435456;
	// lis r29,4096
	r29.s64 = 268435456;
	// ori r7,r7,10
	ctx.r7.u64 = ctx.r7.u64 | 10;
	// ori r6,r6,11
	ctx.r6.u64 = ctx.r6.u64 | 11;
	// li r11,0
	r11.s64 = 0;
	// stw r7,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r7.u32);
	// ori r5,r5,12
	ctx.r5.u64 = ctx.r5.u64 | 12;
	// stw r6,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r6.u32);
	// ori r4,r4,14
	ctx.r4.u64 = ctx.r4.u64 | 14;
	// std r11,4(r3)
	PPC_STORE_U64(ctx.r3.u32 + 4, r11.u64);
	// ori r10,r31,15
	ctx.r10.u64 = r31.u64 | 15;
	// stw r5,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r5.u32);
	// ori r9,r30,16
	ctx.r9.u64 = r30.u64 | 16;
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// ori r8,r29,17
	ctx.r8.u64 = r29.u64 | 17;
	// stw r4,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r4.u32);
	// lis r28,4096
	r28.s64 = 268435456;
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// lis r27,4096
	r27.s64 = 268435456;
	// stw r9,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r9.u32);
	// lis r26,4096
	r26.s64 = 268435456;
	// stw r8,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r8.u32);
	// lis r25,4096
	r25.s64 = 268435456;
	// lis r24,4096
	r24.s64 = 268435456;
	// lis r23,4096
	r23.s64 = 268435456;
	// lis r22,4096
	r22.s64 = 268435456;
	// lis r21,4096
	r21.s64 = 268435456;
	// ori r7,r28,18
	ctx.r7.u64 = r28.u64 | 18;
	// ori r6,r27,33
	ctx.r6.u64 = r27.u64 | 33;
	// ori r5,r26,34
	ctx.r5.u64 = r26.u64 | 34;
	// stw r7,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r7.u32);
	// ori r4,r25,35
	ctx.r4.u64 = r25.u64 | 35;
	// stw r6,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r6.u32);
	// ori r11,r24,45
	r11.u64 = r24.u64 | 45;
	// stw r5,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r5.u32);
	// ori r10,r23,46
	ctx.r10.u64 = r23.u64 | 46;
	// stw r4,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r4.u32);
	// ori r9,r22,47
	ctx.r9.u64 = r22.u64 | 47;
	// stw r11,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, r11.u32);
	// ori r8,r21,48
	ctx.r8.u64 = r21.u64 | 48;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// lis r20,4096
	r20.s64 = 268435456;
	// stw r9,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r9.u32);
	// lis r19,4096
	r19.s64 = 268435456;
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// lis r18,4096
	r18.s64 = 268435456;
	// lis r17,4096
	r17.s64 = 268435456;
	// lis r16,8192
	r16.s64 = 536870912;
	// lis r15,4096
	r15.s64 = 268435456;
	// ori r7,r20,49
	ctx.r7.u64 = r20.u64 | 49;
	// ori r6,r19,50
	ctx.r6.u64 = r19.u64 | 50;
	// li r14,30
	r14.s64 = 30;
	// stw r7,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r7.u32);
	// ori r5,r18,51
	ctx.r5.u64 = r18.u64 | 51;
	// stw r6,172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 172, ctx.r6.u32);
	// ori r4,r17,52
	ctx.r4.u64 = r17.u64 | 52;
	// stw r14,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r14.u32);
	// ori r11,r16,53
	r11.u64 = r16.u64 | 53;
	// stw r5,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r5.u32);
	// ori r10,r15,54
	ctx.r10.u64 = r15.u64 | 54;
	// stw r4,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, ctx.r4.u32);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stw r11,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, r11.u32);
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// stw r10,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r10.u32);
	// ori r7,r9,55
	ctx.r7.u64 = ctx.r9.u64 | 55;
	// ori r6,r8,56
	ctx.r6.u64 = ctx.r8.u64 | 56;
	// lis r5,4096
	ctx.r5.s64 = 268435456;
	// stw r7,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, ctx.r7.u32);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// stw r6,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r6.u32);
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r10,r5,57
	ctx.r10.u64 = ctx.r5.u64 | 57;
	// ori r9,r4,58
	ctx.r9.u64 = ctx.r4.u64 | 58;
	// ori r8,r11,59
	ctx.r8.u64 = r11.u64 | 59;
	// stw r10,232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 232, ctx.r10.u32);
	// stw r9,240(r3)
	PPC_STORE_U32(ctx.r3.u32 + 240, ctx.r9.u32);
	// stw r8,248(r3)
	PPC_STORE_U32(ctx.r3.u32 + 248, ctx.r8.u32);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8226B1F4"))) PPC_WEAK_FUNC(sub_8226B1F4);
PPC_FUNC_IMPL(__imp__sub_8226B1F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B1F8"))) PPC_WEAK_FUNC(sub_8226B1F8);
PPC_FUNC_IMPL(__imp__sub_8226B1F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,34(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 34);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B214"))) PPC_WEAK_FUNC(sub_8226B214);
PPC_FUNC_IMPL(__imp__sub_8226B214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B218"))) PPC_WEAK_FUNC(sub_8226B218);
PPC_FUNC_IMPL(__imp__sub_8226B218) {
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
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823da950
	ctx.lr = 0x8226B23C;
	sub_823DA950(ctx, base);
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// addi r4,r30,80
	ctx.r4.s64 = r30.s64 + 80;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// stb r10,64(r31)
	PPC_STORE_U8(r31.u32 + 64, ctx.r10.u8);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r9,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r9.u32);
	// lwz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// bl 0x8226af08
	ctx.lr = 0x8226B268;
	sub_8226AF08(ctx, base);
	// lwz r7,640(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 640);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,640(r31)
	PPC_STORE_U32(r31.u32 + 640, ctx.r7.u32);
	// lwz r6,644(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 644);
	// stw r6,644(r31)
	PPC_STORE_U32(r31.u32 + 644, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8226B294"))) PPC_WEAK_FUNC(sub_8226B294);
PPC_FUNC_IMPL(__imp__sub_8226B294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B298"))) PPC_WEAK_FUNC(sub_8226B298);
PPC_FUNC_IMPL(__imp__sub_8226B298) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,700(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 700);
	// b 0x8227e750
	sub_8227E750(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226B2A0"))) PPC_WEAK_FUNC(sub_8226B2A0);
PPC_FUNC_IMPL(__imp__sub_8226B2A0) {
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
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226b2d4
	if (cr6.eq) goto loc_8226B2D4;
	// bl 0x824e70f0
	ctx.lr = 0x8226B2C4;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226b2d8
	if (!cr6.eq) goto loc_8226B2D8;
loc_8226B2D4:
	// li r11,0
	r11.s64 = 0;
loc_8226B2D8:
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

__attribute__((alias("__imp__sub_8226B2EC"))) PPC_WEAK_FUNC(sub_8226B2EC);
PPC_FUNC_IMPL(__imp__sub_8226B2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B2F0"))) PPC_WEAK_FUNC(sub_8226B2F0);
PPC_FUNC_IMPL(__imp__sub_8226B2F0) {
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
	// lwz r4,8(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82294df8
	ctx.lr = 0x8226B30C;
	sub_82294DF8(ctx, base);
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

__attribute__((alias("__imp__sub_8226B324"))) PPC_WEAK_FUNC(sub_8226B324);
PPC_FUNC_IMPL(__imp__sub_8226B324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B328"))) PPC_WEAK_FUNC(sub_8226B328);
PPC_FUNC_IMPL(__imp__sub_8226B328) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x82294d58
	sub_82294D58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226B330"))) PPC_WEAK_FUNC(sub_8226B330);
PPC_FUNC_IMPL(__imp__sub_8226B330) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x82294d98
	sub_82294D98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226B338"))) PPC_WEAK_FUNC(sub_8226B338);
PPC_FUNC_IMPL(__imp__sub_8226B338) {
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
	ctx.lr = 0x8226B340;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// rlwinm r30,r28,1,31,31
	r30.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0x1;
	// li r29,0
	r29.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x8226B360;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226b398
	if (cr6.eq) goto loc_8226B398;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x8226B388;
	sub_82618390(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x8226B394;
	sub_826188B8(ctx, base);
	// li r29,1
	r29.s64 = 1;
loc_8226B398:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226b3cc
	if (cr6.eq) goto loc_8226B3CC;
	// neg r11,r30
	r11.s64 = -r30.s64;
	// addi r5,r27,-1
	ctx.r5.s64 = r27.s64 + -1;
	// xor r11,r11,r28
	r11.u64 = r11.u64 ^ r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824e6390
	ctx.lr = 0x8226B3BC;
	sub_824E6390(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226b3d0
	if (!cr6.eq) goto loc_8226B3D0;
loc_8226B3CC:
	// li r11,0
	r11.s64 = 0;
loc_8226B3D0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226B3DC"))) PPC_WEAK_FUNC(sub_8226B3DC);
PPC_FUNC_IMPL(__imp__sub_8226B3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

