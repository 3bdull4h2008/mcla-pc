#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8225BAA4"))) PPC_WEAK_FUNC(sub_8225BAA4);
PPC_FUNC_IMPL(__imp__sub_8225BAA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225BAA8"))) PPC_WEAK_FUNC(sub_8225BAA8);
PPC_FUNC_IMPL(__imp__sub_8225BAA8) {
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
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x8225BAC0;
	sub_82130528(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,64
	ctx.r3.s64 = 64;
	// stw r11,-5084(r31)
	PPC_STORE_U32(r31.u32 + -5084, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8225BAD4;
	sub_82130528(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f11,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x8225bb48
	if (cr6.eq) goto loc_8225BB48;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stfs f11,12(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f12,-13300(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13300);
	ctx.f12.f64 = double(temp.f32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lfs f10,-13304(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13304);
	ctx.f10.f64 = double(temp.f32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// lfs f9,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f10,16(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f9,20(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f0,56(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// b 0x8225bb4c
	goto loc_8225BB4C;
loc_8225BB48:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8225BB4C:
	// lwz r11,-5084(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lfs f10,32668(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32668);
	ctx.f10.f64 = double(temp.f32);
	// lwz r11,-5084(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stb r8,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r8.u8);
	// lis r3,-256
	ctx.r3.s64 = -16777216;
	// lwz r11,-5084(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-5084(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// lfs f0,27640(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27640);
	f0.f64 = double(temp.f32);
	// li r10,-256
	ctx.r10.s64 = -256;
	// stfs f0,32(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// ori r9,r3,255
	ctx.r9.u64 = ctx.r3.u64 | 255;
	// stfs f13,36(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// stfs f13,40(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f0,44(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 44, temp.u32);
	// lfs f12,30712(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 30712);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,48(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 48, temp.u32);
	// stfs f12,52(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// lfs f9,31016(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31016);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,56(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stfs f11,60(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// stw r10,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r10.u32);
	// lwz r11,-5084(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// stw r9,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r9.u32);
	// lwz r11,-5084(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// stw r8,68(r11)
	PPC_STORE_U32(r11.u32 + 68, ctx.r8.u32);
	// lwz r11,-5084(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// stw r7,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r7.u32);
	// bl 0x82259e00
	ctx.lr = 0x8225BBEC;
	sub_82259E00(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-5080(r6)
	PPC_STORE_U32(ctx.r6.u32 + -5080, r11.u32);
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

__attribute__((alias("__imp__sub_8225BC0C"))) PPC_WEAK_FUNC(sub_8225BC0C);
PPC_FUNC_IMPL(__imp__sub_8225BC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225BC10"))) PPC_WEAK_FUNC(sub_8225BC10);
PPC_FUNC_IMPL(__imp__sub_8225BC10) {
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
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,73
	r11.s64 = r11.s64 + 73;
	// stwx r8,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r8.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
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
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
	// lwz r7,0(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r6,r10,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// rlwinm r5,r6,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r4,8(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lvx128 v63,r5,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8225BC9C"))) PPC_WEAK_FUNC(sub_8225BC9C);
PPC_FUNC_IMPL(__imp__sub_8225BC9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225BCA0"))) PPC_WEAK_FUNC(sub_8225BCA0);
PPC_FUNC_IMPL(__imp__sub_8225BCA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r7,32
	ctx.r7.s64 = 32;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// lwz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stwx r5,r4,r3
	PPC_STORE_U32(ctx.r4.u32 + ctx.r3.u32, ctx.r5.u32);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
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
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lvx128 v63,r5,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8225BD20"))) PPC_WEAK_FUNC(sub_8225BD20);
PPC_FUNC_IMPL(__imp__sub_8225BD20) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8225a4b0
	ctx.lr = 0x8225BD48;
	sub_8225A4B0(ctx, base);
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

__attribute__((alias("__imp__sub_8225BD64"))) PPC_WEAK_FUNC(sub_8225BD64);
PPC_FUNC_IMPL(__imp__sub_8225BD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225BD68"))) PPC_WEAK_FUNC(sub_8225BD68);
PPC_FUNC_IMPL(__imp__sub_8225BD68) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8225a5e0
	ctx.lr = 0x8225BD90;
	sub_8225A5E0(ctx, base);
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

__attribute__((alias("__imp__sub_8225BDAC"))) PPC_WEAK_FUNC(sub_8225BDAC);
PPC_FUNC_IMPL(__imp__sub_8225BDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225BDB0"))) PPC_WEAK_FUNC(sub_8225BDB0);
PPC_FUNC_IMPL(__imp__sub_8225BDB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r5,r3
	PPC_STORE_U32(ctx.r5.u32 + ctx.r3.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// rotlwi r11,r11,5
	r11.u64 = __builtin_rotateleft32(r11.u32, 5);
	// sth r5,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, ctx.r5.u16);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// stw r6,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8225BE44"))) PPC_WEAK_FUNC(sub_8225BE44);
PPC_FUNC_IMPL(__imp__sub_8225BE44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225BE48"))) PPC_WEAK_FUNC(sub_8225BE48);
PPC_FUNC_IMPL(__imp__sub_8225BE48) {
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
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// stwx r8,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r8.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// lwz r5,8(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// rotlwi r8,r10,5
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 5);
	// lwz r6,8(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// sth r5,12(r11)
	PPC_STORE_U16(r11.u32 + 12, ctx.r5.u16);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8225BED8"))) PPC_WEAK_FUNC(sub_8225BED8);
PPC_FUNC_IMPL(__imp__sub_8225BED8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32218
	r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-32320
	ctx.r3.s64 = r11.s64 + -32320;
	// b 0x8225ae58
	sub_8225AE58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8225BEE8"))) PPC_WEAK_FUNC(sub_8225BEE8);
PPC_FUNC_IMPL(__imp__sub_8225BEE8) {
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
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lvx128 v63,r4,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8225BF5C"))) PPC_WEAK_FUNC(sub_8225BF5C);
PPC_FUNC_IMPL(__imp__sub_8225BF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225BF60"))) PPC_WEAK_FUNC(sub_8225BF60);
PPC_FUNC_IMPL(__imp__sub_8225BF60) {
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
	// lwz r8,8(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lvx128 v63,r4,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8225BFD4"))) PPC_WEAK_FUNC(sub_8225BFD4);
PPC_FUNC_IMPL(__imp__sub_8225BFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225BFD8"))) PPC_WEAK_FUNC(sub_8225BFD8);
PPC_FUNC_IMPL(__imp__sub_8225BFD8) {
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
	ctx.lr = 0x8225BFE0;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16280
	ctx.r10.s64 = r11.s64 + 16280;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x822587b8
	ctx.lr = 0x8225C014;
	sub_822587B8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225c04c
	if (cr6.eq) goto loc_8225C04C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225C03C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225c050
	if (!cr6.eq) goto loc_8225C050;
loc_8225C04C:
	// li r11,0
	r11.s64 = 0;
loc_8225C050:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C05C"))) PPC_WEAK_FUNC(sub_8225C05C);
PPC_FUNC_IMPL(__imp__sub_8225C05C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C060"))) PPC_WEAK_FUNC(sub_8225C060);
PPC_FUNC_IMPL(__imp__sub_8225C060) {
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
	ctx.lr = 0x8225C068;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16216
	ctx.r10.s64 = r11.s64 + 16216;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82258870
	ctx.lr = 0x8225C09C;
	sub_82258870(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225c0d4
	if (cr6.eq) goto loc_8225C0D4;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225C0C4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225c0d8
	if (!cr6.eq) goto loc_8225C0D8;
loc_8225C0D4:
	// li r11,0
	r11.s64 = 0;
loc_8225C0D8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C0E4"))) PPC_WEAK_FUNC(sub_8225C0E4);
PPC_FUNC_IMPL(__imp__sub_8225C0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C0E8"))) PPC_WEAK_FUNC(sub_8225C0E8);
PPC_FUNC_IMPL(__imp__sub_8225C0E8) {
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
	ctx.lr = 0x8225C0F0;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16440
	ctx.r10.s64 = r11.s64 + 16440;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82258870
	ctx.lr = 0x8225C124;
	sub_82258870(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225c15c
	if (cr6.eq) goto loc_8225C15C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225C14C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225c160
	if (!cr6.eq) goto loc_8225C160;
loc_8225C15C:
	// li r11,0
	r11.s64 = 0;
loc_8225C160:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C16C"))) PPC_WEAK_FUNC(sub_8225C16C);
PPC_FUNC_IMPL(__imp__sub_8225C16C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C170"))) PPC_WEAK_FUNC(sub_8225C170);
PPC_FUNC_IMPL(__imp__sub_8225C170) {
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
	ctx.lr = 0x8225C178;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16056
	ctx.r10.s64 = r11.s64 + 16056;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82258928
	ctx.lr = 0x8225C1AC;
	sub_82258928(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225c1e4
	if (cr6.eq) goto loc_8225C1E4;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225C1D4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225c1e8
	if (!cr6.eq) goto loc_8225C1E8;
loc_8225C1E4:
	// li r11,0
	r11.s64 = 0;
loc_8225C1E8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C1F4"))) PPC_WEAK_FUNC(sub_8225C1F4);
PPC_FUNC_IMPL(__imp__sub_8225C1F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C1F8"))) PPC_WEAK_FUNC(sub_8225C1F8);
PPC_FUNC_IMPL(__imp__sub_8225C1F8) {
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
	ctx.lr = 0x8225C200;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16472
	ctx.r10.s64 = r11.s64 + 16472;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x822589e0
	ctx.lr = 0x8225C234;
	sub_822589E0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225c26c
	if (cr6.eq) goto loc_8225C26C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225C25C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225c270
	if (!cr6.eq) goto loc_8225C270;
loc_8225C26C:
	// li r11,0
	r11.s64 = 0;
loc_8225C270:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C27C"))) PPC_WEAK_FUNC(sub_8225C27C);
PPC_FUNC_IMPL(__imp__sub_8225C27C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C280"))) PPC_WEAK_FUNC(sub_8225C280);
PPC_FUNC_IMPL(__imp__sub_8225C280) {
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
	ctx.lr = 0x8225C288;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16120
	ctx.r10.s64 = r11.s64 + 16120;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82258a98
	ctx.lr = 0x8225C2BC;
	sub_82258A98(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225c2f4
	if (cr6.eq) goto loc_8225C2F4;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225C2E4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225c2f8
	if (!cr6.eq) goto loc_8225C2F8;
loc_8225C2F4:
	// li r11,0
	r11.s64 = 0;
loc_8225C2F8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C304"))) PPC_WEAK_FUNC(sub_8225C304);
PPC_FUNC_IMPL(__imp__sub_8225C304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C308"))) PPC_WEAK_FUNC(sub_8225C308);
PPC_FUNC_IMPL(__imp__sub_8225C308) {
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
	ctx.lr = 0x8225C310;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16696
	ctx.r10.s64 = r11.s64 + 16696;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82258a98
	ctx.lr = 0x8225C344;
	sub_82258A98(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225c37c
	if (cr6.eq) goto loc_8225C37C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225C36C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225c380
	if (!cr6.eq) goto loc_8225C380;
loc_8225C37C:
	// li r11,0
	r11.s64 = 0;
loc_8225C380:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C38C"))) PPC_WEAK_FUNC(sub_8225C38C);
PPC_FUNC_IMPL(__imp__sub_8225C38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C390"))) PPC_WEAK_FUNC(sub_8225C390);
PPC_FUNC_IMPL(__imp__sub_8225C390) {
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
	ctx.lr = 0x8225C398;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16184
	ctx.r10.s64 = r11.s64 + 16184;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82277ac8
	ctx.lr = 0x8225C3CC;
	sub_82277AC8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225c404
	if (cr6.eq) goto loc_8225C404;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225C3F4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225c408
	if (!cr6.eq) goto loc_8225C408;
loc_8225C404:
	// li r11,0
	r11.s64 = 0;
loc_8225C408:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C414"))) PPC_WEAK_FUNC(sub_8225C414);
PPC_FUNC_IMPL(__imp__sub_8225C414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C418"))) PPC_WEAK_FUNC(sub_8225C418);
PPC_FUNC_IMPL(__imp__sub_8225C418) {
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
	ctx.lr = 0x8225C420;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,-5092
	r31.s64 = r11.s64 + -5092;
	// lwz r11,-5092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5092);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225c62c
	if (!cr6.eq) goto loc_8225C62C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8225C440;
	sub_82130528(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225c454
	if (cr6.eq) goto loc_8225C454;
	// bl 0x821d5408
	ctx.lr = 0x8225C450;
	sub_821D5408(ctx, base);
	// b 0x8225c458
	goto loc_8225C458;
loc_8225C454:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_8225C458:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r7,r10,-12544
	ctx.r7.s64 = ctx.r10.s64 + -12544;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// addi r9,r11,29856
	ctx.r9.s64 = r11.s64 + 29856;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32219
	ctx.r8.s64 = -2111504384;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r8,29848
	ctx.r4.s64 = ctx.r8.s64 + 29848;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r30,r10,-13404
	r30.s64 = ctx.r10.s64 + -13404;
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// std r3,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r3.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-5088(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -5088);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8225c4d4
	if (!cr6.eq) goto loc_8225C4D4;
	// bl 0x8225b500
	ctx.lr = 0x8225C4D0;
	sub_8225B500(ctx, base);
	// lwz r11,-5088(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -5088);
loc_8225C4D4:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r10,-13368
	ctx.r7.s64 = ctx.r10.s64 + -13368;
	// addi r6,r9,-13344
	ctx.r6.s64 = ctx.r9.s64 + -13344;
	// addi r5,r8,-13320
	ctx.r5.s64 = ctx.r8.s64 + -13320;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r11,16
	r11.s64 = 16;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r7,r4,-13284
	ctx.r7.s64 = ctx.r4.s64 + -13284;
	// addi r6,r8,-13260
	ctx.r6.s64 = ctx.r8.s64 + -13260;
	// addi r5,r30,-13236
	ctx.r5.s64 = r30.s64 + -13236;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,36
	ctx.r9.s64 = 36;
	// li r11,40
	r11.s64 = 40;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r7,r4,-13212
	ctx.r7.s64 = ctx.r4.s64 + -13212;
	// addi r6,r8,-13188
	ctx.r6.s64 = ctx.r8.s64 + -13188;
	// addi r5,r30,-13164
	ctx.r5.s64 = r30.s64 + -13164;
	// li r10,44
	ctx.r10.s64 = 44;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r11,52
	r11.s64 = 52;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r7,r4,-13140
	ctx.r7.s64 = ctx.r4.s64 + -13140;
	// addi r6,r8,-13116
	ctx.r6.s64 = ctx.r8.s64 + -13116;
	// addi r5,r30,-13092
	ctx.r5.s64 = r30.s64 + -13092;
	// li r10,56
	ctx.r10.s64 = 56;
	// li r9,60
	ctx.r9.s64 = 60;
	// li r11,64
	r11.s64 = 64;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r7,r4,-13068
	ctx.r7.s64 = ctx.r4.s64 + -13068;
	// addi r6,r8,-13044
	ctx.r6.s64 = ctx.r8.s64 + -13044;
	// addi r5,r30,-13020
	ctx.r5.s64 = r30.s64 + -13020;
	// li r10,68
	ctx.r10.s64 = 68;
	// li r9,72
	ctx.r9.s64 = 72;
	// li r11,76
	r11.s64 = 76;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x8225C5D8;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8225C5E8;
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
	ctx.lr = 0x8225C604;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-12960
	ctx.r4.s64 = ctx.r8.s64 + -12960;
	// bl 0x821d4b00
	ctx.lr = 0x8225C614;
	sub_821D4B00(ctx, base);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x8225C62C;
	sub_821C0548(ctx, base);
loc_8225C62C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C634"))) PPC_WEAK_FUNC(sub_8225C634);
PPC_FUNC_IMPL(__imp__sub_8225C634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C638"))) PPC_WEAK_FUNC(sub_8225C638);
PPC_FUNC_IMPL(__imp__sub_8225C638) {
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
	ctx.lr = 0x8225C640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,2
	r30.s64 = 2;
	// addi r31,r28,1464
	r31.s64 = r28.s64 + 1464;
loc_8225C650:
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82237910
	ctx.lr = 0x8225C658;
	sub_82237910(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82238140
	ctx.lr = 0x8225C660;
	sub_82238140(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225c680
	if (cr6.eq) goto loc_8225C680;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225C680;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8225C680:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x8225c650
	if (!cr0.eq) goto loc_8225C650;
	// addi r31,r28,52
	r31.s64 = r28.s64 + 52;
	// li r30,15
	r30.s64 = 15;
loc_8225C694:
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82237910
	ctx.lr = 0x8225C69C;
	sub_82237910(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82238140
	ctx.lr = 0x8225C6A4;
	sub_82238140(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225c6c4
	if (cr6.eq) goto loc_8225C6C4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225C6C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8225C6C4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// bne 0x8225c694
	if (!cr0.eq) goto loc_8225C694;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225c73c
	if (cr6.eq) goto loc_8225C73C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8225C6E8;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8225C700;
	sub_82130588(ctx, base);
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// beq cr6,0x8225c720
	if (cr6.eq) goto loc_8225C720;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8225C720;
	sub_82130588(ctx, base);
loc_8225C720:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225c734
	if (cr6.eq) goto loc_8225C734;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8225C734;
	sub_82130588(ctx, base);
loc_8225C734:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8225C73C;
	sub_82130588(ctx, base);
loc_8225C73C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// stw r30,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r30.u32);
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225c78c
	if (cr6.eq) goto loc_8225C78C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4296(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// bl 0x824ebcc8
	ctx.lr = 0x8225C76C;
	sub_824EBCC8(ctx, base);
	// lwz r31,8(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225c788
	if (cr6.eq) goto loc_8225C788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x8225C780;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8225C788;
	sub_82130588(ctx, base);
loc_8225C788:
	// stw r30,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r30.u32);
loc_8225C78C:
	// stw r30,2144(r28)
	PPC_STORE_U32(r28.u32 + 2144, r30.u32);
	// stw r30,2140(r28)
	PPC_STORE_U32(r28.u32 + 2140, r30.u32);
	// stw r30,2136(r28)
	PPC_STORE_U32(r28.u32 + 2136, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C7A0"))) PPC_WEAK_FUNC(sub_8225C7A0);
PPC_FUNC_IMPL(__imp__sub_8225C7A0) {
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
	ctx.lr = 0x8225C7A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225c7d0
	if (cr6.eq) goto loc_8225C7D0;
	// rlwinm r3,r31,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x8225C7CC;
	sub_82130528(ctx, base);
	// b 0x8225c7d4
	goto loc_8225C7D4;
loc_8225C7D0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8225C7D4:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// beq cr6,0x8225c7fc
	if (cr6.eq) goto loc_8225C7FC;
	// rlwinm r3,r29,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x8225C7EC;
	sub_82130528(ctx, base);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// sth r29,14(r30)
	PPC_STORE_U16(r30.u32 + 14, r29.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8225C7FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r29,14(r30)
	PPC_STORE_U16(r30.u32 + 14, r29.u16);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8225C810"))) PPC_WEAK_FUNC(sub_8225C810);
PPC_FUNC_IMPL(__imp__sub_8225C810) {
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
	ctx.lr = 0x8225C818;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225c860
	if (cr6.eq) goto loc_8225C860;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225C844;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225C850;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225c864
	if (!cr6.eq) goto loc_8225C864;
loc_8225C860:
	// li r11,0
	r11.s64 = 0;
loc_8225C864:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225c898
	if (cr6.eq) goto loc_8225C898;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16280
	ctx.r10.s64 = r11.s64 + 16280;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225aed0
	ctx.lr = 0x8225C890;
	sub_8225AED0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225C898:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C8A4"))) PPC_WEAK_FUNC(sub_8225C8A4);
PPC_FUNC_IMPL(__imp__sub_8225C8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C8A8"))) PPC_WEAK_FUNC(sub_8225C8A8);
PPC_FUNC_IMPL(__imp__sub_8225C8A8) {
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
	ctx.lr = 0x8225C8B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225c8f8
	if (cr6.eq) goto loc_8225C8F8;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225C8DC;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225C8E8;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225c8fc
	if (!cr6.eq) goto loc_8225C8FC;
loc_8225C8F8:
	// li r11,0
	r11.s64 = 0;
loc_8225C8FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225c930
	if (cr6.eq) goto loc_8225C930;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16568
	ctx.r10.s64 = r11.s64 + 16568;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225b070
	ctx.lr = 0x8225C928;
	sub_8225B070(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225C930:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C93C"))) PPC_WEAK_FUNC(sub_8225C93C);
PPC_FUNC_IMPL(__imp__sub_8225C93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C940"))) PPC_WEAK_FUNC(sub_8225C940);
PPC_FUNC_IMPL(__imp__sub_8225C940) {
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
	ctx.lr = 0x8225C948;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225c990
	if (cr6.eq) goto loc_8225C990;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225C974;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225C980;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225c994
	if (!cr6.eq) goto loc_8225C994;
loc_8225C990:
	// li r11,0
	r11.s64 = 0;
loc_8225C994:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225c9c8
	if (cr6.eq) goto loc_8225C9C8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16216
	ctx.r10.s64 = r11.s64 + 16216;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225b158
	ctx.lr = 0x8225C9C0;
	sub_8225B158(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225C9C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225C9D4"))) PPC_WEAK_FUNC(sub_8225C9D4);
PPC_FUNC_IMPL(__imp__sub_8225C9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225C9D8"))) PPC_WEAK_FUNC(sub_8225C9D8);
PPC_FUNC_IMPL(__imp__sub_8225C9D8) {
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
	ctx.lr = 0x8225C9E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ca28
	if (cr6.eq) goto loc_8225CA28;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225CA0C;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225CA18;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225ca2c
	if (!cr6.eq) goto loc_8225CA2C;
loc_8225CA28:
	// li r11,0
	r11.s64 = 0;
loc_8225CA2C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ca60
	if (cr6.eq) goto loc_8225CA60;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16440
	ctx.r10.s64 = r11.s64 + 16440;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225b158
	ctx.lr = 0x8225CA58;
	sub_8225B158(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225CA60:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225CA6C"))) PPC_WEAK_FUNC(sub_8225CA6C);
PPC_FUNC_IMPL(__imp__sub_8225CA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225CA70"))) PPC_WEAK_FUNC(sub_8225CA70);
PPC_FUNC_IMPL(__imp__sub_8225CA70) {
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
	ctx.lr = 0x8225CA78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cac0
	if (cr6.eq) goto loc_8225CAC0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225CAA4;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225CAB0;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225cac4
	if (!cr6.eq) goto loc_8225CAC4;
loc_8225CAC0:
	// li r11,0
	r11.s64 = 0;
loc_8225CAC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225caf8
	if (cr6.eq) goto loc_8225CAF8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16056
	ctx.r10.s64 = r11.s64 + 16056;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225b240
	ctx.lr = 0x8225CAF0;
	sub_8225B240(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225CAF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225CB04"))) PPC_WEAK_FUNC(sub_8225CB04);
PPC_FUNC_IMPL(__imp__sub_8225CB04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225CB08"))) PPC_WEAK_FUNC(sub_8225CB08);
PPC_FUNC_IMPL(__imp__sub_8225CB08) {
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
	ctx.lr = 0x8225CB10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cb58
	if (cr6.eq) goto loc_8225CB58;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225CB3C;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225CB48;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225cb5c
	if (!cr6.eq) goto loc_8225CB5C;
loc_8225CB58:
	// li r11,0
	r11.s64 = 0;
loc_8225CB5C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cb90
	if (cr6.eq) goto loc_8225CB90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16472
	ctx.r10.s64 = r11.s64 + 16472;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225b328
	ctx.lr = 0x8225CB88;
	sub_8225B328(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225CB90:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225CB9C"))) PPC_WEAK_FUNC(sub_8225CB9C);
PPC_FUNC_IMPL(__imp__sub_8225CB9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225CBA0"))) PPC_WEAK_FUNC(sub_8225CBA0);
PPC_FUNC_IMPL(__imp__sub_8225CBA0) {
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
	ctx.lr = 0x8225CBA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cbf0
	if (cr6.eq) goto loc_8225CBF0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225CBD4;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225CBE0;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225cbf4
	if (!cr6.eq) goto loc_8225CBF4;
loc_8225CBF0:
	// li r11,0
	r11.s64 = 0;
loc_8225CBF4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cc28
	if (cr6.eq) goto loc_8225CC28;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16120
	ctx.r10.s64 = r11.s64 + 16120;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225b410
	ctx.lr = 0x8225CC20;
	sub_8225B410(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225CC28:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225CC34"))) PPC_WEAK_FUNC(sub_8225CC34);
PPC_FUNC_IMPL(__imp__sub_8225CC34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225CC38"))) PPC_WEAK_FUNC(sub_8225CC38);
PPC_FUNC_IMPL(__imp__sub_8225CC38) {
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
	ctx.lr = 0x8225CC40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cc88
	if (cr6.eq) goto loc_8225CC88;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225CC6C;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225CC78;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225cc8c
	if (!cr6.eq) goto loc_8225CC8C;
loc_8225CC88:
	// li r11,0
	r11.s64 = 0;
loc_8225CC8C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ccc0
	if (cr6.eq) goto loc_8225CCC0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16696
	ctx.r10.s64 = r11.s64 + 16696;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225b410
	ctx.lr = 0x8225CCB8;
	sub_8225B410(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225CCC0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225CCCC"))) PPC_WEAK_FUNC(sub_8225CCCC);
PPC_FUNC_IMPL(__imp__sub_8225CCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225CCD0"))) PPC_WEAK_FUNC(sub_8225CCD0);
PPC_FUNC_IMPL(__imp__sub_8225CCD0) {
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
	ctx.lr = 0x8225CCD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cd20
	if (cr6.eq) goto loc_8225CD20;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225CD04;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82269388
	ctx.lr = 0x8225CD10;
	sub_82269388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225cd24
	if (!cr6.eq) goto loc_8225CD24;
loc_8225CD20:
	// li r11,0
	r11.s64 = 0;
loc_8225CD24:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cd58
	if (cr6.eq) goto loc_8225CD58;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,16184
	ctx.r10.s64 = r11.s64 + 16184;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82279be0
	ctx.lr = 0x8225CD50;
	sub_82279BE0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8225CD58:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225CD64"))) PPC_WEAK_FUNC(sub_8225CD64);
PPC_FUNC_IMPL(__imp__sub_8225CD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225CD68"))) PPC_WEAK_FUNC(sub_8225CD68);
PPC_FUNC_IMPL(__imp__sub_8225CD68) {
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
	ctx.lr = 0x8225CD70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225cddc
	if (cr6.lt) goto loc_8225CDDC;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225CD98;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225cdbc
	if (!cr6.eq) goto loc_8225CDBC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225CDB0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cddc
	if (cr6.eq) goto loc_8225CDDC;
loc_8225CDBC:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225bfd8
	ctx.lr = 0x8225CDD4;
	sub_8225BFD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225CDDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225CDE8"))) PPC_WEAK_FUNC(sub_8225CDE8);
PPC_FUNC_IMPL(__imp__sub_8225CDE8) {
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
	ctx.lr = 0x8225CDF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225ce5c
	if (cr6.lt) goto loc_8225CE5C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225CE18;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225ce3c
	if (!cr6.eq) goto loc_8225CE3C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225CE30;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ce5c
	if (cr6.eq) goto loc_8225CE5C;
loc_8225CE3C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225c060
	ctx.lr = 0x8225CE54;
	sub_8225C060(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225CE5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225CE68"))) PPC_WEAK_FUNC(sub_8225CE68);
PPC_FUNC_IMPL(__imp__sub_8225CE68) {
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
	ctx.lr = 0x8225CE70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225cedc
	if (cr6.lt) goto loc_8225CEDC;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225CE98;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225cebc
	if (!cr6.eq) goto loc_8225CEBC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225CEB0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cedc
	if (cr6.eq) goto loc_8225CEDC;
loc_8225CEBC:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225c0e8
	ctx.lr = 0x8225CED4;
	sub_8225C0E8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225CEDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225CEE8"))) PPC_WEAK_FUNC(sub_8225CEE8);
PPC_FUNC_IMPL(__imp__sub_8225CEE8) {
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
	ctx.lr = 0x8225CEF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225cf5c
	if (cr6.lt) goto loc_8225CF5C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225CF18;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225cf3c
	if (!cr6.eq) goto loc_8225CF3C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225CF30;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cf5c
	if (cr6.eq) goto loc_8225CF5C;
loc_8225CF3C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225c170
	ctx.lr = 0x8225CF54;
	sub_8225C170(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225CF5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225CF68"))) PPC_WEAK_FUNC(sub_8225CF68);
PPC_FUNC_IMPL(__imp__sub_8225CF68) {
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
	ctx.lr = 0x8225CF70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225cfdc
	if (cr6.lt) goto loc_8225CFDC;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225CF98;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225cfbc
	if (!cr6.eq) goto loc_8225CFBC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225CFB0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225cfdc
	if (cr6.eq) goto loc_8225CFDC;
loc_8225CFBC:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225c1f8
	ctx.lr = 0x8225CFD4;
	sub_8225C1F8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225CFDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225CFE8"))) PPC_WEAK_FUNC(sub_8225CFE8);
PPC_FUNC_IMPL(__imp__sub_8225CFE8) {
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
	ctx.lr = 0x8225CFF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225d05c
	if (cr6.lt) goto loc_8225D05C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225D018;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225d03c
	if (!cr6.eq) goto loc_8225D03C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225D030;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d05c
	if (cr6.eq) goto loc_8225D05C;
loc_8225D03C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225c280
	ctx.lr = 0x8225D054;
	sub_8225C280(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D05C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D068"))) PPC_WEAK_FUNC(sub_8225D068);
PPC_FUNC_IMPL(__imp__sub_8225D068) {
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
	ctx.lr = 0x8225D070;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225d0dc
	if (cr6.lt) goto loc_8225D0DC;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225D098;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225d0bc
	if (!cr6.eq) goto loc_8225D0BC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225D0B0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d0dc
	if (cr6.eq) goto loc_8225D0DC;
loc_8225D0BC:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225c308
	ctx.lr = 0x8225D0D4;
	sub_8225C308(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D0DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D0E8"))) PPC_WEAK_FUNC(sub_8225D0E8);
PPC_FUNC_IMPL(__imp__sub_8225D0E8) {
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
	ctx.lr = 0x8225D0F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225d15c
	if (cr6.lt) goto loc_8225D15C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225D118;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225d13c
	if (!cr6.eq) goto loc_8225D13C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225D130;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d15c
	if (cr6.eq) goto loc_8225D15C;
loc_8225D13C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225c390
	ctx.lr = 0x8225D154;
	sub_8225C390(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D15C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D168"))) PPC_WEAK_FUNC(sub_8225D168);
PPC_FUNC_IMPL(__imp__sub_8225D168) {
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
	ctx.lr = 0x8225D170;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16568
	ctx.r10.s64 = r11.s64 + 16568;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8225afb8
	ctx.lr = 0x8225D1A4;
	sub_8225AFB8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225d1dc
	if (cr6.eq) goto loc_8225D1DC;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8225D1CC;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225d1e0
	if (!cr6.eq) goto loc_8225D1E0;
loc_8225D1DC:
	// li r11,0
	r11.s64 = 0;
loc_8225D1E0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225D1EC"))) PPC_WEAK_FUNC(sub_8225D1EC);
PPC_FUNC_IMPL(__imp__sub_8225D1EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225D1F0"))) PPC_WEAK_FUNC(sub_8225D1F0);
PPC_FUNC_IMPL(__imp__sub_8225D1F0) {
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
	// addi r4,r11,-14432
	ctx.r4.s64 = r11.s64 + -14432;
	// addi r3,r10,-12368
	ctx.r3.s64 = ctx.r10.s64 + -12368;
	// bl 0x82554798
	ctx.lr = 0x8225D210;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-16976
	ctx.r4.s64 = ctx.r9.s64 + -16976;
	// addi r3,r8,-12388
	ctx.r3.s64 = ctx.r8.s64 + -12388;
	// bl 0x82554798
	ctx.lr = 0x8225D224;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-16824
	ctx.r4.s64 = ctx.r7.s64 + -16824;
	// addi r3,r6,-12408
	ctx.r3.s64 = ctx.r6.s64 + -12408;
	// bl 0x82554798
	ctx.lr = 0x8225D238;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-16680
	ctx.r4.s64 = ctx.r5.s64 + -16680;
	// addi r3,r3,-12424
	ctx.r3.s64 = ctx.r3.s64 + -12424;
	// bl 0x82554798
	ctx.lr = 0x8225D24C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-22312
	ctx.r4.s64 = r11.s64 + -22312;
	// addi r3,r10,-12452
	ctx.r3.s64 = ctx.r10.s64 + -12452;
	// bl 0x82554798
	ctx.lr = 0x8225D260;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-16664
	ctx.r4.s64 = ctx.r9.s64 + -16664;
	// addi r3,r8,-12480
	ctx.r3.s64 = ctx.r8.s64 + -12480;
	// bl 0x82554798
	ctx.lr = 0x8225D274;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-16544
	ctx.r4.s64 = ctx.r7.s64 + -16544;
	// addi r3,r6,-12508
	ctx.r3.s64 = ctx.r6.s64 + -12508;
	// bl 0x82554798
	ctx.lr = 0x8225D288;
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

__attribute__((alias("__imp__sub_8225D298"))) PPC_WEAK_FUNC(sub_8225D298);
PPC_FUNC_IMPL(__imp__sub_8225D298) {
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
	ctx.lr = 0x8225D2A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D2C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225d2fc
	if (cr6.eq) goto loc_8225D2FC;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225d2f4
	if (cr6.eq) goto loc_8225D2F4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225d2fc
	if (!cr6.eq) goto loc_8225D2FC;
loc_8225D2F4:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225d300
	goto loc_8225D300;
loc_8225D2FC:
	// li r11,0
	r11.s64 = 0;
loc_8225D300:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d33c
	if (cr6.eq) goto loc_8225D33C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225cd68
	ctx.lr = 0x8225D334;
	sub_8225CD68(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D33C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D348"))) PPC_WEAK_FUNC(sub_8225D348);
PPC_FUNC_IMPL(__imp__sub_8225D348) {
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
	ctx.lr = 0x8225D350;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225d3ac
	if (cr6.eq) goto loc_8225D3AC;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225d3a4
	if (cr6.eq) goto loc_8225D3A4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225d3ac
	if (!cr6.eq) goto loc_8225D3AC;
loc_8225D3A4:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225d3b0
	goto loc_8225D3B0;
loc_8225D3AC:
	// li r11,0
	r11.s64 = 0;
loc_8225D3B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d3ec
	if (cr6.eq) goto loc_8225D3EC;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225cde8
	ctx.lr = 0x8225D3E4;
	sub_8225CDE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D3EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D3F8"))) PPC_WEAK_FUNC(sub_8225D3F8);
PPC_FUNC_IMPL(__imp__sub_8225D3F8) {
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
	ctx.lr = 0x8225D400;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225d45c
	if (cr6.eq) goto loc_8225D45C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225d454
	if (cr6.eq) goto loc_8225D454;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225d45c
	if (!cr6.eq) goto loc_8225D45C;
loc_8225D454:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225d460
	goto loc_8225D460;
loc_8225D45C:
	// li r11,0
	r11.s64 = 0;
loc_8225D460:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d49c
	if (cr6.eq) goto loc_8225D49C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225ce68
	ctx.lr = 0x8225D494;
	sub_8225CE68(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D49C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D4A8"))) PPC_WEAK_FUNC(sub_8225D4A8);
PPC_FUNC_IMPL(__imp__sub_8225D4A8) {
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
	ctx.lr = 0x8225D4B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D4D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225d50c
	if (cr6.eq) goto loc_8225D50C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225d504
	if (cr6.eq) goto loc_8225D504;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225d50c
	if (!cr6.eq) goto loc_8225D50C;
loc_8225D504:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225d510
	goto loc_8225D510;
loc_8225D50C:
	// li r11,0
	r11.s64 = 0;
loc_8225D510:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d54c
	if (cr6.eq) goto loc_8225D54C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225cee8
	ctx.lr = 0x8225D544;
	sub_8225CEE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D54C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D558"))) PPC_WEAK_FUNC(sub_8225D558);
PPC_FUNC_IMPL(__imp__sub_8225D558) {
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
	ctx.lr = 0x8225D560;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225d5bc
	if (cr6.eq) goto loc_8225D5BC;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225d5b4
	if (cr6.eq) goto loc_8225D5B4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225d5bc
	if (!cr6.eq) goto loc_8225D5BC;
loc_8225D5B4:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225d5c0
	goto loc_8225D5C0;
loc_8225D5BC:
	// li r11,0
	r11.s64 = 0;
loc_8225D5C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d5fc
	if (cr6.eq) goto loc_8225D5FC;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225cf68
	ctx.lr = 0x8225D5F4;
	sub_8225CF68(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D5FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D608"))) PPC_WEAK_FUNC(sub_8225D608);
PPC_FUNC_IMPL(__imp__sub_8225D608) {
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
	ctx.lr = 0x8225D610;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225d66c
	if (cr6.eq) goto loc_8225D66C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225d664
	if (cr6.eq) goto loc_8225D664;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225d66c
	if (!cr6.eq) goto loc_8225D66C;
loc_8225D664:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225d670
	goto loc_8225D670;
loc_8225D66C:
	// li r11,0
	r11.s64 = 0;
loc_8225D670:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d6ac
	if (cr6.eq) goto loc_8225D6AC;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225cfe8
	ctx.lr = 0x8225D6A4;
	sub_8225CFE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D6AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D6B8"))) PPC_WEAK_FUNC(sub_8225D6B8);
PPC_FUNC_IMPL(__imp__sub_8225D6B8) {
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
	ctx.lr = 0x8225D6C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D6E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225d71c
	if (cr6.eq) goto loc_8225D71C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225d714
	if (cr6.eq) goto loc_8225D714;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225d71c
	if (!cr6.eq) goto loc_8225D71C;
loc_8225D714:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225d720
	goto loc_8225D720;
loc_8225D71C:
	// li r11,0
	r11.s64 = 0;
loc_8225D720:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d75c
	if (cr6.eq) goto loc_8225D75C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225d068
	ctx.lr = 0x8225D754;
	sub_8225D068(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D75C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D768"))) PPC_WEAK_FUNC(sub_8225D768);
PPC_FUNC_IMPL(__imp__sub_8225D768) {
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
	ctx.lr = 0x8225D770;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D798;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225d7cc
	if (cr6.eq) goto loc_8225D7CC;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225d7c4
	if (cr6.eq) goto loc_8225D7C4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225d7cc
	if (!cr6.eq) goto loc_8225D7CC;
loc_8225D7C4:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225d7d0
	goto loc_8225D7D0;
loc_8225D7CC:
	// li r11,0
	r11.s64 = 0;
loc_8225D7D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d80c
	if (cr6.eq) goto loc_8225D80C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225d0e8
	ctx.lr = 0x8225D804;
	sub_8225D0E8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D80C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D818"))) PPC_WEAK_FUNC(sub_8225D818);
PPC_FUNC_IMPL(__imp__sub_8225D818) {
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
	ctx.lr = 0x8225D820;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225d88c
	if (cr6.lt) goto loc_8225D88C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8225D848;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225d86c
	if (!cr6.eq) goto loc_8225D86C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8225D860;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d88c
	if (cr6.eq) goto loc_8225D88C;
loc_8225D86C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8225d168
	ctx.lr = 0x8225D884;
	sub_8225D168(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225D88C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225D898"))) PPC_WEAK_FUNC(sub_8225D898);
PPC_FUNC_IMPL(__imp__sub_8225D898) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-12528
	ctx.r3.s64 = ctx.r10.s64 + -12528;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130000
	ctx.lr = 0x8225D8BC;
	sub_82130000(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-5052(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -5052);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x8225d8d4
	if (!cr6.eq) goto loc_8225D8D4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-5052(r11)
	PPC_STORE_U32(r11.u32 + -5052, ctx.r10.u32);
loc_8225D8D4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225d8ec
	if (cr6.eq) goto loc_8225D8EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8225c638
	ctx.lr = 0x8225D8E4;
	sub_8225C638(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8225D8EC;
	sub_82130588(ctx, base);
loc_8225D8EC:
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

__attribute__((alias("__imp__sub_8225D900"))) PPC_WEAK_FUNC(sub_8225D900);
PPC_FUNC_IMPL(__imp__sub_8225D900) {
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
	ctx.lr = 0x8225D908;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225d9fc
	if (cr6.eq) goto loc_8225D9FC;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225d9fc
	if (cr0.eq) goto loc_8225D9FC;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225d9f8
	if (!cr6.gt) goto loc_8225D9F8;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225D948:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225d9e4
	if (cr6.eq) goto loc_8225D9E4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225D980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225d9e4
	if (!cr6.eq) goto loc_8225D9E4;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225d9e4
	if (cr6.eq) goto loc_8225D9E4;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225d9e4
	if (!cr6.eq) goto loc_8225D9E4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225D9B0;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225d9e4
	if (!cr6.eq) goto loc_8225D9E4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d298
	ctx.lr = 0x8225D9D8;
	sub_8225D298(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225D9E4:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225d948
	if (cr6.lt) goto loc_8225D948;
loc_8225D9F8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225D9FC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225DA04"))) PPC_WEAK_FUNC(sub_8225DA04);
PPC_FUNC_IMPL(__imp__sub_8225DA04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225DA08"))) PPC_WEAK_FUNC(sub_8225DA08);
PPC_FUNC_IMPL(__imp__sub_8225DA08) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ba28
	ctx.lr = 0x8225DA30;
	sub_8226BA28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8225da5c
	if (cr6.eq) goto loc_8225DA5C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d348
	ctx.lr = 0x8225DA5C;
	sub_8225D348(ctx, base);
loc_8225DA5C:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_8225DA78"))) PPC_WEAK_FUNC(sub_8225DA78);
PPC_FUNC_IMPL(__imp__sub_8225DA78) {
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
	ctx.lr = 0x8225DA80;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225db74
	if (cr6.eq) goto loc_8225DB74;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225db74
	if (cr0.eq) goto loc_8225DB74;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225db70
	if (!cr6.gt) goto loc_8225DB70;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225DAC0:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225DAD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225db5c
	if (cr6.eq) goto loc_8225DB5C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225DAF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225db5c
	if (!cr6.eq) goto loc_8225DB5C;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225db5c
	if (cr6.eq) goto loc_8225DB5C;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225db5c
	if (!cr6.eq) goto loc_8225DB5C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225DB28;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225db5c
	if (!cr6.eq) goto loc_8225DB5C;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d348
	ctx.lr = 0x8225DB50;
	sub_8225D348(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225DB5C:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225dac0
	if (cr6.lt) goto loc_8225DAC0;
loc_8225DB70:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225DB74:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225DB7C"))) PPC_WEAK_FUNC(sub_8225DB7C);
PPC_FUNC_IMPL(__imp__sub_8225DB7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225DB80"))) PPC_WEAK_FUNC(sub_8225DB80);
PPC_FUNC_IMPL(__imp__sub_8225DB80) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ba28
	ctx.lr = 0x8225DBA8;
	sub_8226BA28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8225dbd4
	if (cr6.eq) goto loc_8225DBD4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d3f8
	ctx.lr = 0x8225DBD4;
	sub_8225D3F8(ctx, base);
loc_8225DBD4:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_8225DBF0"))) PPC_WEAK_FUNC(sub_8225DBF0);
PPC_FUNC_IMPL(__imp__sub_8225DBF0) {
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
	ctx.lr = 0x8225DBF8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225dcec
	if (cr6.eq) goto loc_8225DCEC;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225dcec
	if (cr0.eq) goto loc_8225DCEC;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225dce8
	if (!cr6.gt) goto loc_8225DCE8;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225DC38:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225DC50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225dcd4
	if (cr6.eq) goto loc_8225DCD4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225DC70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225dcd4
	if (!cr6.eq) goto loc_8225DCD4;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225dcd4
	if (cr6.eq) goto loc_8225DCD4;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225dcd4
	if (!cr6.eq) goto loc_8225DCD4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225DCA0;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225dcd4
	if (!cr6.eq) goto loc_8225DCD4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d3f8
	ctx.lr = 0x8225DCC8;
	sub_8225D3F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225DCD4:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225dc38
	if (cr6.lt) goto loc_8225DC38;
loc_8225DCE8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225DCEC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225DCF4"))) PPC_WEAK_FUNC(sub_8225DCF4);
PPC_FUNC_IMPL(__imp__sub_8225DCF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225DCF8"))) PPC_WEAK_FUNC(sub_8225DCF8);
PPC_FUNC_IMPL(__imp__sub_8225DCF8) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ba28
	ctx.lr = 0x8225DD20;
	sub_8226BA28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8225dd4c
	if (cr6.eq) goto loc_8225DD4C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d4a8
	ctx.lr = 0x8225DD4C;
	sub_8225D4A8(ctx, base);
loc_8225DD4C:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_8225DD68"))) PPC_WEAK_FUNC(sub_8225DD68);
PPC_FUNC_IMPL(__imp__sub_8225DD68) {
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
	ctx.lr = 0x8225DD70;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225de64
	if (cr6.eq) goto loc_8225DE64;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225de64
	if (cr0.eq) goto loc_8225DE64;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225de60
	if (!cr6.gt) goto loc_8225DE60;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225DDB0:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225DDC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225de4c
	if (cr6.eq) goto loc_8225DE4C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225DDE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225de4c
	if (!cr6.eq) goto loc_8225DE4C;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225de4c
	if (cr6.eq) goto loc_8225DE4C;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225de4c
	if (!cr6.eq) goto loc_8225DE4C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225DE18;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225de4c
	if (!cr6.eq) goto loc_8225DE4C;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d4a8
	ctx.lr = 0x8225DE40;
	sub_8225D4A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225DE4C:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225ddb0
	if (cr6.lt) goto loc_8225DDB0;
loc_8225DE60:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225DE64:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225DE6C"))) PPC_WEAK_FUNC(sub_8225DE6C);
PPC_FUNC_IMPL(__imp__sub_8225DE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225DE70"))) PPC_WEAK_FUNC(sub_8225DE70);
PPC_FUNC_IMPL(__imp__sub_8225DE70) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ba28
	ctx.lr = 0x8225DE98;
	sub_8226BA28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8225dec4
	if (cr6.eq) goto loc_8225DEC4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d558
	ctx.lr = 0x8225DEC4;
	sub_8225D558(ctx, base);
loc_8225DEC4:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_8225DEE0"))) PPC_WEAK_FUNC(sub_8225DEE0);
PPC_FUNC_IMPL(__imp__sub_8225DEE0) {
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
	ctx.lr = 0x8225DEE8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225dfdc
	if (cr6.eq) goto loc_8225DFDC;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225dfdc
	if (cr0.eq) goto loc_8225DFDC;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225dfd8
	if (!cr6.gt) goto loc_8225DFD8;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225DF28:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225DF40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225dfc4
	if (cr6.eq) goto loc_8225DFC4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225DF60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225dfc4
	if (!cr6.eq) goto loc_8225DFC4;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225dfc4
	if (cr6.eq) goto loc_8225DFC4;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225dfc4
	if (!cr6.eq) goto loc_8225DFC4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225DF90;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225dfc4
	if (!cr6.eq) goto loc_8225DFC4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d558
	ctx.lr = 0x8225DFB8;
	sub_8225D558(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225DFC4:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225df28
	if (cr6.lt) goto loc_8225DF28;
loc_8225DFD8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225DFDC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225DFE4"))) PPC_WEAK_FUNC(sub_8225DFE4);
PPC_FUNC_IMPL(__imp__sub_8225DFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225DFE8"))) PPC_WEAK_FUNC(sub_8225DFE8);
PPC_FUNC_IMPL(__imp__sub_8225DFE8) {
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
	ctx.lr = 0x8225DFF0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e0e4
	if (cr6.eq) goto loc_8225E0E4;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225e0e4
	if (cr0.eq) goto loc_8225E0E4;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225e0e0
	if (!cr6.gt) goto loc_8225E0E0;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225E030:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E048;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225e0cc
	if (cr6.eq) goto loc_8225E0CC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E068;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225e0cc
	if (!cr6.eq) goto loc_8225E0CC;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225e0cc
	if (cr6.eq) goto loc_8225E0CC;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225e0cc
	if (!cr6.eq) goto loc_8225E0CC;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225E098;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225e0cc
	if (!cr6.eq) goto loc_8225E0CC;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d608
	ctx.lr = 0x8225E0C0;
	sub_8225D608(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225E0CC:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225e030
	if (cr6.lt) goto loc_8225E030;
loc_8225E0E0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225E0E4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225E0EC"))) PPC_WEAK_FUNC(sub_8225E0EC);
PPC_FUNC_IMPL(__imp__sub_8225E0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225E0F0"))) PPC_WEAK_FUNC(sub_8225E0F0);
PPC_FUNC_IMPL(__imp__sub_8225E0F0) {
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
	ctx.lr = 0x8225E0F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e1ec
	if (cr6.eq) goto loc_8225E1EC;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225e1ec
	if (cr0.eq) goto loc_8225E1EC;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225e1e8
	if (!cr6.gt) goto loc_8225E1E8;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225E138:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225e1d4
	if (cr6.eq) goto loc_8225E1D4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225e1d4
	if (!cr6.eq) goto loc_8225E1D4;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225e1d4
	if (cr6.eq) goto loc_8225E1D4;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225e1d4
	if (!cr6.eq) goto loc_8225E1D4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225E1A0;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225e1d4
	if (!cr6.eq) goto loc_8225E1D4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d6b8
	ctx.lr = 0x8225E1C8;
	sub_8225D6B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225E1D4:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225e138
	if (cr6.lt) goto loc_8225E138;
loc_8225E1E8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225E1EC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225E1F4"))) PPC_WEAK_FUNC(sub_8225E1F4);
PPC_FUNC_IMPL(__imp__sub_8225E1F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225E1F8"))) PPC_WEAK_FUNC(sub_8225E1F8);
PPC_FUNC_IMPL(__imp__sub_8225E1F8) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ba28
	ctx.lr = 0x8225E220;
	sub_8226BA28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8225e24c
	if (cr6.eq) goto loc_8225E24C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d768
	ctx.lr = 0x8225E24C;
	sub_8225D768(ctx, base);
loc_8225E24C:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_8225E268"))) PPC_WEAK_FUNC(sub_8225E268);
PPC_FUNC_IMPL(__imp__sub_8225E268) {
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
	ctx.lr = 0x8225E270;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e364
	if (cr6.eq) goto loc_8225E364;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225e364
	if (cr0.eq) goto loc_8225E364;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225e360
	if (!cr6.gt) goto loc_8225E360;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225E2B0:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E2C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225e34c
	if (cr6.eq) goto loc_8225E34C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E2E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225e34c
	if (!cr6.eq) goto loc_8225E34C;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225e34c
	if (cr6.eq) goto loc_8225E34C;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225e34c
	if (!cr6.eq) goto loc_8225E34C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225E318;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225e34c
	if (!cr6.eq) goto loc_8225E34C;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225d768
	ctx.lr = 0x8225E340;
	sub_8225D768(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225E34C:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225e2b0
	if (cr6.lt) goto loc_8225E2B0;
loc_8225E360:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225E364:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225E36C"))) PPC_WEAK_FUNC(sub_8225E36C);
PPC_FUNC_IMPL(__imp__sub_8225E36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225E370"))) PPC_WEAK_FUNC(sub_8225E370);
PPC_FUNC_IMPL(__imp__sub_8225E370) {
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
	ctx.lr = 0x8225E378;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E3A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225e3d4
	if (cr6.eq) goto loc_8225E3D4;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8225e3cc
	if (cr6.eq) goto loc_8225E3CC;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8225e3d4
	if (!cr6.eq) goto loc_8225E3D4;
loc_8225E3CC:
	// li r11,1
	r11.s64 = 1;
	// b 0x8225e3d8
	goto loc_8225E3D8;
loc_8225E3D4:
	// li r11,0
	r11.s64 = 0;
loc_8225E3D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e414
	if (cr6.eq) goto loc_8225E414;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8225d818
	ctx.lr = 0x8225E40C;
	sub_8225D818(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8225E414:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225E420"))) PPC_WEAK_FUNC(sub_8225E420);
PPC_FUNC_IMPL(__imp__sub_8225E420) {
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
	ctx.lr = 0x8225E428;
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
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225E444;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225e4a4
	if (cr6.eq) goto loc_8225E4A4;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// addi r3,r10,-12356
	ctx.r3.s64 = ctx.r10.s64 + -12356;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130000
	ctx.lr = 0x8225E474;
	sub_82130000(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r29,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r29.u8);
	// ld r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U64(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r8,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, ctx.r8.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// bl 0x8225d900
	ctx.lr = 0x8225E498;
	sub_8225D900(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82259390
	ctx.lr = 0x8225E4A4;
	sub_82259390(ctx, base);
loc_8225E4A4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8225E4AC"))) PPC_WEAK_FUNC(sub_8225E4AC);
PPC_FUNC_IMPL(__imp__sub_8225E4AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225E4B0"))) PPC_WEAK_FUNC(sub_8225E4B0);
PPC_FUNC_IMPL(__imp__sub_8225E4B0) {
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
	ctx.lr = 0x8225E4B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r11,-12304
	ctx.r3.s64 = r11.s64 + -12304;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x8225E4DC;
	sub_82130000(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r27,-1
	r27.s64 = -1;
	// li r28,0
	r28.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r29,20
	ctx.r10.s64 = r29.s64 + 20;
loc_8225E4F0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x8225e510
	if (!cr6.eq) goto loc_8225E510;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// beq cr6,0x8225e514
	if (cr6.eq) goto loc_8225E514;
loc_8225E510:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8225E514:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225e534
	if (!cr6.eq) goto loc_8225E534;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,96
	ctx.r10.s64 = ctx.r10.s64 + 96;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// blt cr6,0x8225e4f0
	if (cr6.lt) goto loc_8225E4F0;
	// b 0x8225e54c
	goto loc_8225E54C;
loc_8225E534:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r27,r11
	r27.u64 = r11.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r28,r11,16
	r28.s64 = r11.s64 + 16;
loc_8225E54C:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8225E55C;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e5a4
	if (cr6.eq) goto loc_8225E5A4;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8225e594
	if (cr6.eq) goto loc_8225E594;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x8225e5a8
	goto loc_8225E5A8;
loc_8225E594:
	// lwz r10,17892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x8225e5a8
	goto loc_8225E5A8;
loc_8225E5A4:
	// li r31,0
	r31.s64 = 0;
loc_8225E5A8:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x8225e688
	if (cr6.lt) goto loc_8225E688;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E5CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225E5E4;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225e66c
	if (cr6.eq) goto loc_8225E66C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225e688
	if (!cr6.eq) goto loc_8225E688;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// bl 0x8232a7b0
	ctx.lr = 0x8225E62C;
	sub_8232A7B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x8225E648;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// li r11,1
	r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r11,12(r30)
	PPC_STORE_U8(r30.u32 + 12, r11.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225da78
	ctx.lr = 0x8225E66C;
	sub_8225DA78(ctx, base);
loc_8225E66C:
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e688
	if (cr6.eq) goto loc_8225E688;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82259440
	ctx.lr = 0x8225E688;
	sub_82259440(ctx, base);
loc_8225E688:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225E690"))) PPC_WEAK_FUNC(sub_8225E690);
PPC_FUNC_IMPL(__imp__sub_8225E690) {
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
	ctx.lr = 0x8225E698;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r11,-12252
	ctx.r3.s64 = r11.s64 + -12252;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x8225E6BC;
	sub_82130000(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r27,-1
	r27.s64 = -1;
	// li r28,0
	r28.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r29,20
	ctx.r10.s64 = r29.s64 + 20;
loc_8225E6D0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x8225e6f0
	if (!cr6.eq) goto loc_8225E6F0;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// beq cr6,0x8225e6f4
	if (cr6.eq) goto loc_8225E6F4;
loc_8225E6F0:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8225E6F4:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225e714
	if (!cr6.eq) goto loc_8225E714;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,96
	ctx.r10.s64 = ctx.r10.s64 + 96;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// blt cr6,0x8225e6d0
	if (cr6.lt) goto loc_8225E6D0;
	// b 0x8225e72c
	goto loc_8225E72C;
loc_8225E714:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r27,r11
	r27.u64 = r11.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r28,r11,16
	r28.s64 = r11.s64 + 16;
loc_8225E72C:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8225E73C;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e784
	if (cr6.eq) goto loc_8225E784;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8225e774
	if (cr6.eq) goto loc_8225E774;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x8225e788
	goto loc_8225E788;
loc_8225E774:
	// lwz r10,17892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x8225e788
	goto loc_8225E788;
loc_8225E784:
	// li r31,0
	r31.s64 = 0;
loc_8225E788:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x8225e864
	if (cr6.lt) goto loc_8225E864;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E7AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225E7C4;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225e848
	if (cr6.eq) goto loc_8225E848;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// lbz r11,113(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 113);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x8225e864
	if (!cr6.eq) goto loc_8225E864;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x8225E824;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// li r11,1
	r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r11,12(r30)
	PPC_STORE_U8(r30.u32 + 12, r11.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225dbf0
	ctx.lr = 0x8225E848;
	sub_8225DBF0(ctx, base);
loc_8225E848:
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e864
	if (cr6.eq) goto loc_8225E864;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822595c8
	ctx.lr = 0x8225E864;
	sub_822595C8(ctx, base);
loc_8225E864:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225E86C"))) PPC_WEAK_FUNC(sub_8225E86C);
PPC_FUNC_IMPL(__imp__sub_8225E86C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225E870"))) PPC_WEAK_FUNC(sub_8225E870);
PPC_FUNC_IMPL(__imp__sub_8225E870) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8225E878;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r11,-12200
	ctx.r3.s64 = r11.s64 + -12200;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x8225E89C;
	sub_82130000(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r27,-1
	r27.s64 = -1;
	// li r28,0
	r28.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r29,20
	ctx.r10.s64 = r29.s64 + 20;
loc_8225E8B0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x8225e8d0
	if (!cr6.eq) goto loc_8225E8D0;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// beq cr6,0x8225e8d4
	if (cr6.eq) goto loc_8225E8D4;
loc_8225E8D0:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8225E8D4:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225e8f4
	if (!cr6.eq) goto loc_8225E8F4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,96
	ctx.r10.s64 = ctx.r10.s64 + 96;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// blt cr6,0x8225e8b0
	if (cr6.lt) goto loc_8225E8B0;
	// b 0x8225e90c
	goto loc_8225E90C;
loc_8225E8F4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r27,r11
	r27.u64 = r11.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r28,r11,16
	r28.s64 = r11.s64 + 16;
loc_8225E90C:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8225E91C;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225e964
	if (cr6.eq) goto loc_8225E964;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8225e954
	if (cr6.eq) goto loc_8225E954;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x8225e968
	goto loc_8225E968;
loc_8225E954:
	// lwz r10,17892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x8225e968
	goto loc_8225E968;
loc_8225E964:
	// li r31,0
	r31.s64 = 0;
loc_8225E968:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x8225ea58
	if (cr6.lt) goto loc_8225EA58;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225E98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225E9A4;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225ea28
	if (cr6.eq) goto loc_8225EA28;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// lbz r11,113(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 113);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x8225ea58
	if (!cr6.eq) goto loc_8225EA58;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x8225EA04;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// li r11,1
	r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r11,32(r30)
	PPC_STORE_U8(r30.u32 + 32, r11.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225dd68
	ctx.lr = 0x8225EA28;
	sub_8225DD68(ctx, base);
loc_8225EA28:
	// lbz r11,32(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ea58
	if (cr6.eq) goto loc_8225EA58;
	// li r11,16
	r11.s64 = 16;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82259790
	ctx.lr = 0x8225EA58;
	sub_82259790(ctx, base);
loc_8225EA58:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225EA60"))) PPC_WEAK_FUNC(sub_8225EA60);
PPC_FUNC_IMPL(__imp__sub_8225EA60) {
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
	ctx.lr = 0x8225EA68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r11,-12148
	ctx.r3.s64 = r11.s64 + -12148;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130000
	ctx.lr = 0x8225EA88;
	sub_82130000(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8225EA98;
	sub_822B6308(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225eadc
	if (cr6.eq) goto loc_8225EADC;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8225ead0
	if (cr6.eq) goto loc_8225EAD0;
	// addi r11,r11,101
	r11.s64 = r11.s64 + 101;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r10,r3
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// b 0x8225eae0
	goto loc_8225EAE0;
loc_8225EAD0:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r11,r3
	r29.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// b 0x8225eae0
	goto loc_8225EAE0;
loc_8225EADC:
	// li r29,0
	r29.s64 = 0;
loc_8225EAE0:
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x822b6308
	ctx.lr = 0x8225EAE8;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225eb30
	if (cr6.eq) goto loc_8225EB30;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8225eb20
	if (cr6.eq) goto loc_8225EB20;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x8225eb34
	goto loc_8225EB34;
loc_8225EB20:
	// lwz r10,17892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x8225eb34
	goto loc_8225EB34;
loc_8225EB30:
	// li r31,0
	r31.s64 = 0;
loc_8225EB34:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225EB58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225EB78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225EB90;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225ec3c
	if (cr6.eq) goto loc_8225EC3C;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x8225EBDC;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x8225EBF8;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lwz r4,68(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lwz r3,68(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// bl 0x8232a8e8
	ctx.lr = 0x8225EC18;
	sub_8232A8E8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// li r11,1
	r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r11,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r11.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8225dee0
	ctx.lr = 0x8225EC3C;
	sub_8225DEE0(ctx, base);
loc_8225EC3C:
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ec58
	if (cr6.eq) goto loc_8225EC58;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822598e0
	ctx.lr = 0x8225EC58;
	sub_822598E0(ctx, base);
loc_8225EC58:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225EC60"))) PPC_WEAK_FUNC(sub_8225EC60);
PPC_FUNC_IMPL(__imp__sub_8225EC60) {
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
	ctx.lr = 0x8225EC68;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r11,-12100
	ctx.r3.s64 = r11.s64 + -12100;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130000
	ctx.lr = 0x8225EC84;
	sub_82130000(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8225EC94;
	sub_822B6308(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225ed88
	if (cr6.eq) goto loc_8225ED88;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8225eccc
	if (cr6.eq) goto loc_8225ECCC;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x8225ecd8
	goto loc_8225ECD8;
loc_8225ECCC:
	// lwz r10,17892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
loc_8225ECD8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225ed88
	if (cr6.eq) goto loc_8225ED88;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225ECF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225ed88
	if (cr6.eq) goto loc_8225ED88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225ED0C;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225ed70
	if (cr6.eq) goto loc_8225ED70;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ed88
	if (cr6.eq) goto loc_8225ED88;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225ed88
	if (cr6.eq) goto loc_8225ED88;
	// lbz r11,114(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 114);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ed88
	if (cr6.eq) goto loc_8225ED88;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x8225ED4C;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ed88
	if (cr6.eq) goto loc_8225ED88;
	// li r11,1
	r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r11,4(r30)
	PPC_STORE_U8(r30.u32 + 4, r11.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225e268
	ctx.lr = 0x8225ED70;
	sub_8225E268(ctx, base);
loc_8225ED70:
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ed88
	if (cr6.eq) goto loc_8225ED88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82259c08
	ctx.lr = 0x8225ED88;
	sub_82259C08(ctx, base);
loc_8225ED88:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8225ED90"))) PPC_WEAK_FUNC(sub_8225ED90);
PPC_FUNC_IMPL(__imp__sub_8225ED90) {
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
	ctx.lr = 0x8225ED98;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r26,-1
	r26.s64 = -1;
	// bl 0x82387a18
	ctx.lr = 0x8225EDB0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ede0
	if (cr6.eq) goto loc_8225EDE0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225EDC8;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8225ede0
	if (!cr6.eq) goto loc_8225EDE0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8225EDE0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-12060
	ctx.r3.s64 = r11.s64 + -12060;
	// bl 0x82130000
	ctx.lr = 0x8225EDF0;
	sub_82130000(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r27,0
	r27.s64 = 0;
	// mr r31,r27
	r31.u64 = r27.u64;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8225eea0
	if (!cr6.gt) goto loc_8225EEA0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_8225EE10:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// bne cr6,0x8225ee24
	if (!cr6.eq) goto loc_8225EE24;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// bne cr6,0x8225ee40
	if (!cr6.eq) goto loc_8225EE40;
loc_8225EE24:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x8225ee10
	if (cr6.lt) goto loc_8225EE10;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8225EE40:
	// mr r26,r31
	r26.u64 = r31.u64;
	// bl 0x82387a18
	ctx.lr = 0x8225EE48;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ee68
	if (cr6.eq) goto loc_8225EE68;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225dfe8
	ctx.lr = 0x8225EE68;
	sub_8225DFE8(ctx, base);
loc_8225EE68:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,-5064(r11)
	PPC_STORE_U32(r11.u32 + -5064, r31.u32);
	// bl 0x82258b50
	ctx.lr = 0x8225EE7C;
	sub_82258B50(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x822578f8
	ctx.lr = 0x8225EEA0;
	sub_822578F8(ctx, base);
loc_8225EEA0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8225EEAC"))) PPC_WEAK_FUNC(sub_8225EEAC);
PPC_FUNC_IMPL(__imp__sub_8225EEAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225EEB0"))) PPC_WEAK_FUNC(sub_8225EEB0);
PPC_FUNC_IMPL(__imp__sub_8225EEB0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8225EEB8;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// bl 0x82387a18
	ctx.lr = 0x8225EEE0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ef04
	if (cr6.eq) goto loc_8225EF04;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225EEF8;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225ef9c
	if (cr6.eq) goto loc_8225EF9C;
loc_8225EF04:
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-27688
	ctx.r9.s64 = r11.s64 + -27688;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r3,r8,-11920
	ctx.r3.s64 = ctx.r8.s64 + -11920;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x8225EF3C;
	sub_82130000(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// sth r11,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r11.u16);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// sth r11,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r11.u16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8225b8c0
	ctx.lr = 0x8225EF6C;
	sub_8225B8C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r7,-11972
	ctx.r3.s64 = ctx.r7.s64 + -11972;
	// bl 0x82130000
	ctx.lr = 0x8225EF80;
	sub_82130000(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x8225efb0
	if (cr6.gt) goto loc_8225EFB0;
	// lhz r10,94(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225ef9c
	if (cr6.eq) goto loc_8225EF9C;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x8225EF9C;
	sub_82130588(ctx, base);
loc_8225EF9C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8225EFB0:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lwz r28,88(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lwz r9,2192(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// twllei r31,0
	// addi r3,r4,-12028
	ctx.r3.s64 = ctx.r4.s64 + -12028;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r9,r5
	ctx.r10.s64 = ctx.r9.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// divw r6,r8,r31
	ctx.r6.s32 = ctx.r8.s32 / r31.s32;
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(r31.s32);
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r9,r31,r11
	ctx.r9.u64 = r31.u64 & ~r11.u64;
	// twlgei r9,-1
	// lwzx r31,r10,r28
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// rlwinm r11,r31,5,0,26
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsubs f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f5,f12,f10
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x8225F068;
	sub_82130000(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x8225F06C;
	sub_82387A18(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8225f08c
	if (cr6.eq) goto loc_8225F08C;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225dfe8
	ctx.lr = 0x8225F08C;
	sub_8225DFE8(ctx, base);
loc_8225F08C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82259b30
	ctx.lr = 0x8225F098;
	sub_82259B30(ctx, base);
	// lhz r10,94(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225f0ac
	if (cr6.eq) goto loc_8225F0AC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x8225F0AC;
	sub_82130588(ctx, base);
loc_8225F0AC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225F0C0"))) PPC_WEAK_FUNC(sub_8225F0C0);
PPC_FUNC_IMPL(__imp__sub_8225F0C0) {
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
	// bl 0x82387a18
	ctx.lr = 0x8225F0E0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f104
	if (cr6.eq) goto loc_8225F104;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225F0F8;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225f158
	if (cr6.eq) goto loc_8225F158;
loc_8225F104:
	// addi r11,r30,73
	r11.s64 = r30.s64 + 73;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r9,-11844
	ctx.r3.s64 = ctx.r9.s64 + -11844;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r30,r8,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r30,r31
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x82130000
	ctx.lr = 0x8225F124;
	sub_82130000(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x8225F128;
	sub_82387A18(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8225f14c
	if (cr6.eq) goto loc_8225F14C;
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8225e0f0
	ctx.lr = 0x8225F14C;
	sub_8225E0F0(ctx, base);
loc_8225F14C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r30,r31
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x82257a58
	ctx.lr = 0x8225F158;
	sub_82257A58(ctx, base);
loc_8225F158:
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

__attribute__((alias("__imp__sub_8225F170"))) PPC_WEAK_FUNC(sub_8225F170);
PPC_FUNC_IMPL(__imp__sub_8225F170) {
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
	ctx.lr = 0x8225F178;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f26c
	if (cr6.eq) goto loc_8225F26C;
	// addic. r26,r11,8
	xer.ca = r11.u32 > 4294967287;
	r26.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8225f26c
	if (cr0.eq) goto loc_8225F26C;
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225f268
	if (!cr6.gt) goto loc_8225F268;
	// addi r29,r26,8
	r29.s64 = r26.s64 + 8;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8225F1B8:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225F1D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225f254
	if (cr6.eq) goto loc_8225F254;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225F1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225f254
	if (!cr6.eq) goto loc_8225F254;
	// lwz r31,1220(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8225f254
	if (cr6.eq) goto loc_8225F254;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225f254
	if (!cr6.eq) goto loc_8225F254;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8225F220;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8225f254
	if (!cr6.eq) goto loc_8225F254;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8225e370
	ctx.lr = 0x8225F248;
	sub_8225E370(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8225F254:
	// lwz r11,3080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 3080);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8225f1b8
	if (cr6.lt) goto loc_8225F1B8;
loc_8225F268:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8225F26C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8225F274"))) PPC_WEAK_FUNC(sub_8225F274);
PPC_FUNC_IMPL(__imp__sub_8225F274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225F278"))) PPC_WEAK_FUNC(sub_8225F278);
PPC_FUNC_IMPL(__imp__sub_8225F278) {
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225F2A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x8225f560
	if (!cr6.eq) goto loc_8225F560;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82257678
	ctx.lr = 0x8225F2C4;
	sub_82257678(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r10,16280
	ctx.r9.s64 = ctx.r10.s64 + 16280;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f320
	if (!cr6.eq) goto loc_8225F320;
	// li r11,-1
	r11.s64 = -1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225c810
	ctx.lr = 0x8225F304;
	sub_8225C810(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82259390
	ctx.lr = 0x8225F31C;
	sub_82259390(ctx, base);
	// b 0x8225f560
	goto loc_8225F560;
loc_8225F320:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16568
	ctx.r9.s64 = ctx.r10.s64 + 16568;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f364
	if (!cr6.eq) goto loc_8225F364;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225c8a8
	ctx.lr = 0x8225F348;
	sub_8225C8A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225ba40
	ctx.lr = 0x8225F360;
	sub_8225BA40(ctx, base);
	// b 0x8225f560
	goto loc_8225F560;
loc_8225F364:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16216
	ctx.r9.s64 = ctx.r10.s64 + 16216;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f3b4
	if (!cr6.eq) goto loc_8225F3B4;
	// li r11,-1
	r11.s64 = -1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225c940
	ctx.lr = 0x8225F398;
	sub_8225C940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225e4b0
	ctx.lr = 0x8225F3B0;
	sub_8225E4B0(ctx, base);
	// b 0x8225f560
	goto loc_8225F560;
loc_8225F3B4:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16440
	ctx.r9.s64 = ctx.r10.s64 + 16440;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f404
	if (!cr6.eq) goto loc_8225F404;
	// li r11,-1
	r11.s64 = -1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225c9d8
	ctx.lr = 0x8225F3E8;
	sub_8225C9D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225e690
	ctx.lr = 0x8225F400;
	sub_8225E690(ctx, base);
	// b 0x8225f560
	goto loc_8225F560;
loc_8225F404:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16056
	ctx.r9.s64 = ctx.r10.s64 + 16056;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f454
	if (!cr6.eq) goto loc_8225F454;
	// li r11,-1
	r11.s64 = -1;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r11.u32);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225ca70
	ctx.lr = 0x8225F438;
	sub_8225CA70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225e870
	ctx.lr = 0x8225F450;
	sub_8225E870(ctx, base);
	// b 0x8225f560
	goto loc_8225F560;
loc_8225F454:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16472
	ctx.r9.s64 = ctx.r10.s64 + 16472;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f498
	if (!cr6.eq) goto loc_8225F498;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225cb08
	ctx.lr = 0x8225F47C;
	sub_8225CB08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225ea60
	ctx.lr = 0x8225F494;
	sub_8225EA60(ctx, base);
	// b 0x8225f560
	goto loc_8225F560;
loc_8225F498:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16120
	ctx.r9.s64 = ctx.r10.s64 + 16120;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f4dc
	if (!cr6.eq) goto loc_8225F4DC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225cba0
	ctx.lr = 0x8225F4C0;
	sub_8225CBA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82259b98
	ctx.lr = 0x8225F4D8;
	sub_82259B98(ctx, base);
	// b 0x8225f560
	goto loc_8225F560;
loc_8225F4DC:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16696
	ctx.r9.s64 = ctx.r10.s64 + 16696;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f520
	if (!cr6.eq) goto loc_8225F520;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225cc38
	ctx.lr = 0x8225F504;
	sub_8225CC38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82257a58
	ctx.lr = 0x8225F51C;
	sub_82257A58(ctx, base);
	// b 0x8225f560
	goto loc_8225F560;
loc_8225F520:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16184
	ctx.r9.s64 = ctx.r10.s64 + 16184;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8225f560
	if (!cr6.eq) goto loc_8225F560;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8225ccd0
	ctx.lr = 0x8225F548;
	sub_8225CCD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f560
	if (cr6.eq) goto loc_8225F560;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225ec60
	ctx.lr = 0x8225F560;
	sub_8225EC60(ctx, base);
loc_8225F560:
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

__attribute__((alias("__imp__sub_8225F578"))) PPC_WEAK_FUNC(sub_8225F578);
PPC_FUNC_IMPL(__imp__sub_8225F578) {
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
	ctx.lr = 0x8225F580;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225f5a8
	if (cr6.eq) goto loc_8225F5A8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r6,r11,-13108
	ctx.r6.s64 = r11.s64 + -13108;
	// b 0x8225f5b0
	goto loc_8225F5B0;
loc_8225F5A8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r6,r11,-13120
	ctx.r6.s64 = r11.s64 + -13120;
loc_8225F5B0:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// addi r3,r10,-11808
	ctx.r3.s64 = ctx.r10.s64 + -11808;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82130000
	ctx.lr = 0x8225F5D4;
	sub_82130000(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x8225F5D8;
	sub_82387A18(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x8225f5fc
	if (cr6.eq) goto loc_8225F5FC;
	// bl 0x8225e420
	ctx.lr = 0x8225F5F4;
	sub_8225E420(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8225F5FC:
	// bl 0x82259270
	ctx.lr = 0x8225F600;
	sub_82259270(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8225F608"))) PPC_WEAK_FUNC(sub_8225F608);
PPC_FUNC_IMPL(__imp__sub_8225F608) {
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
	ctx.lr = 0x8225F610;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225F630;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225f684
	if (cr6.eq) goto loc_8225F684;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r3,r11,-11768
	ctx.r3.s64 = r11.s64 + -11768;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8225F654;
	sub_82130000(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, ctx.r10.u8);
	// bl 0x8225f170
	ctx.lr = 0x8225F678;
	sub_8225F170(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8225ba40
	ctx.lr = 0x8225F684;
	sub_8225BA40(ctx, base);
loc_8225F684:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8225F68C"))) PPC_WEAK_FUNC(sub_8225F68C);
PPC_FUNC_IMPL(__imp__sub_8225F68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225F690"))) PPC_WEAK_FUNC(sub_8225F690);
PPC_FUNC_IMPL(__imp__sub_8225F690) {
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
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x8225f6dc
	if (!cr6.eq) goto loc_8225F6DC;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82256028
	ctx.lr = 0x8225F6CC;
	sub_82256028(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8225f6e0
	if (cr6.lt) goto loc_8225F6E0;
loc_8225F6DC:
	// li r11,0
	r11.s64 = 0;
loc_8225F6E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225f74c
	if (!cr6.eq) goto loc_8225F74C;
	// li r11,2
	r11.s64 = 2;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82256028
	ctx.lr = 0x8225F6FC;
	sub_82256028(ctx, base);
	// addi r10,r3,1600
	ctx.r10.s64 = ctx.r3.s64 + 1600;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// bl 0x82387a60
	ctx.lr = 0x8225F708;
	sub_82387A60(ctx, base);
	// ld r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 20);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r7,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, ctx.r7.u8);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225F728;
	sub_8226BF18(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x8225f748
	if (!cr6.eq) goto loc_8225F748;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8225da08
	ctx.lr = 0x8225F744;
	sub_8225DA08(ctx, base);
	// b 0x8225f74c
	goto loc_8225F74C;
loc_8225F748:
	// bl 0x8225e4b0
	ctx.lr = 0x8225F74C;
	sub_8225E4B0(ctx, base);
loc_8225F74C:
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

__attribute__((alias("__imp__sub_8225F764"))) PPC_WEAK_FUNC(sub_8225F764);
PPC_FUNC_IMPL(__imp__sub_8225F764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225F768"))) PPC_WEAK_FUNC(sub_8225F768);
PPC_FUNC_IMPL(__imp__sub_8225F768) {
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
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x8225f7b4
	if (!cr6.eq) goto loc_8225F7B4;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82256028
	ctx.lr = 0x8225F7A4;
	sub_82256028(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8225f7b8
	if (cr6.lt) goto loc_8225F7B8;
loc_8225F7B4:
	// li r11,0
	r11.s64 = 0;
loc_8225F7B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225f824
	if (!cr6.eq) goto loc_8225F824;
	// li r11,2
	r11.s64 = 2;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82256028
	ctx.lr = 0x8225F7D4;
	sub_82256028(ctx, base);
	// addi r10,r3,1600
	ctx.r10.s64 = ctx.r3.s64 + 1600;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// bl 0x82387a60
	ctx.lr = 0x8225F7E0;
	sub_82387A60(ctx, base);
	// ld r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 20);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r7,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, ctx.r7.u8);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225F800;
	sub_8226BF18(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x8225f820
	if (!cr6.eq) goto loc_8225F820;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8225db80
	ctx.lr = 0x8225F81C;
	sub_8225DB80(ctx, base);
	// b 0x8225f824
	goto loc_8225F824;
loc_8225F820:
	// bl 0x8225e690
	ctx.lr = 0x8225F824;
	sub_8225E690(ctx, base);
loc_8225F824:
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

__attribute__((alias("__imp__sub_8225F83C"))) PPC_WEAK_FUNC(sub_8225F83C);
PPC_FUNC_IMPL(__imp__sub_8225F83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225F840"))) PPC_WEAK_FUNC(sub_8225F840);
PPC_FUNC_IMPL(__imp__sub_8225F840) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r31,r11,16
	r31.s64 = r11.s64 + 16;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x8225f890
	if (!cr6.eq) goto loc_8225F890;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82256028
	ctx.lr = 0x8225F880;
	sub_82256028(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8225f894
	if (cr6.lt) goto loc_8225F894;
loc_8225F890:
	// li r11,0
	r11.s64 = 0;
loc_8225F894:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225f938
	if (!cr6.eq) goto loc_8225F938;
	// li r11,2
	r11.s64 = 2;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82256028
	ctx.lr = 0x8225F8B0;
	sub_82256028(ctx, base);
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,1600
	ctx.r8.s64 = ctx.r3.s64 + 1600;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,31016(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82257bf8
	ctx.lr = 0x8225F8E0;
	sub_82257BF8(ctx, base);
	// bl 0x82387a60
	ctx.lr = 0x8225F8E4;
	sub_82387A60(ctx, base);
	// ld r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U64(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// stb r10,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r10.u8);
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225F914;
	sub_8226BF18(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x8225f934
	if (!cr6.eq) goto loc_8225F934;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8225dcf8
	ctx.lr = 0x8225F930;
	sub_8225DCF8(ctx, base);
	// b 0x8225f938
	goto loc_8225F938;
loc_8225F934:
	// bl 0x8225e870
	ctx.lr = 0x8225F938;
	sub_8225E870(ctx, base);
loc_8225F938:
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

__attribute__((alias("__imp__sub_8225F950"))) PPC_WEAK_FUNC(sub_8225F950);
PPC_FUNC_IMPL(__imp__sub_8225F950) {
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
	ctx.lr = 0x8225F958;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r3,17892(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x8225F974;
	sub_822B62A0(ctx, base);
	// lwz r11,17892(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822b62a0
	ctx.lr = 0x8225F988;
	sub_822B62A0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r11,-11680
	ctx.r3.s64 = r11.s64 + -11680;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8225F9A0;
	sub_82130000(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8225F9B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8225f9e0
	if (!cr6.eq) goto loc_8225F9E0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225F9D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225fa34
	if (cr6.eq) goto loc_8225FA34;
loc_8225F9E0:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8225fa34
	if (cr6.lt) goto loc_8225FA34;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x8225fa34
	if (cr6.lt) goto loc_8225FA34;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stb r10,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225FA0C;
	sub_8226BF18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bne cr6,0x8225fa30
	if (!cr6.eq) goto loc_8225FA30;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8225de70
	ctx.lr = 0x8225FA28;
	sub_8225DE70(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8225FA30:
	// bl 0x8225ea60
	ctx.lr = 0x8225FA34;
	sub_8225EA60(ctx, base);
loc_8225FA34:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8225FA3C"))) PPC_WEAK_FUNC(sub_8225FA3C);
PPC_FUNC_IMPL(__imp__sub_8225FA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225FA40"))) PPC_WEAK_FUNC(sub_8225FA40);
PPC_FUNC_IMPL(__imp__sub_8225FA40) {
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
	ctx.lr = 0x8225FA48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x8225FA60;
	sub_822B62A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r10,-11628
	ctx.r3.s64 = ctx.r10.s64 + -11628;
	// bl 0x82130000
	ctx.lr = 0x8225FA74;
	sub_82130000(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8225FA88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8225fae8
	if (cr6.eq) goto loc_8225FAE8;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8225fae8
	if (cr6.lt) goto loc_8225FAE8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8225FAB4;
	sub_8226BF18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bne cr6,0x8225fae4
	if (!cr6.eq) goto loc_8225FAE4;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8225e1f8
	ctx.lr = 0x8225FAD0;
	sub_8225E1F8(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x8232ae60
	ctx.lr = 0x8225FADC;
	sub_8232AE60(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8225FAE4:
	// bl 0x8225ec60
	ctx.lr = 0x8225FAE8;
	sub_8225EC60(ctx, base);
loc_8225FAE8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8225FAF0"))) PPC_WEAK_FUNC(sub_8225FAF0);
PPC_FUNC_IMPL(__imp__sub_8225FAF0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8225ed90
	ctx.lr = 0x8225FB18;
	sub_8225ED90(ctx, base);
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

__attribute__((alias("__imp__sub_8225FB34"))) PPC_WEAK_FUNC(sub_8225FB34);
PPC_FUNC_IMPL(__imp__sub_8225FB34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225FB38"))) PPC_WEAK_FUNC(sub_8225FB38);
PPC_FUNC_IMPL(__imp__sub_8225FB38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32218
	r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-4432
	ctx.r3.s64 = r11.s64 + -4432;
	// b 0x8225acf0
	sub_8225ACF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8225FB48"))) PPC_WEAK_FUNC(sub_8225FB48);
PPC_FUNC_IMPL(__imp__sub_8225FB48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8225f0c0
	sub_8225F0C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8225FB58"))) PPC_WEAK_FUNC(sub_8225FB58);
PPC_FUNC_IMPL(__imp__sub_8225FB58) {
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
	ctx.lr = 0x8225FB60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,68(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// bl 0x8232a7b0
	ctx.lr = 0x8225FB80;
	sub_8232A7B0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225fc04
	if (cr6.eq) goto loc_8225FC04;
	// bl 0x82387a18
	ctx.lr = 0x8225FB90;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225fbf4
	if (cr6.eq) goto loc_8225FBF4;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225FBB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225fc04
	if (cr6.eq) goto loc_8225FC04;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// addi r3,r10,-11588
	ctx.r3.s64 = ctx.r10.s64 + -11588;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82130000
	ctx.lr = 0x8225FBE0;
	sub_82130000(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225f690
	ctx.lr = 0x8225FBEC;
	sub_8225F690(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8225FBF4:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82259440
	ctx.lr = 0x8225FC04;
	sub_82259440(ctx, base);
loc_8225FC04:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8225FC0C"))) PPC_WEAK_FUNC(sub_8225FC0C);
PPC_FUNC_IMPL(__imp__sub_8225FC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225FC10"))) PPC_WEAK_FUNC(sub_8225FC10);
PPC_FUNC_IMPL(__imp__sub_8225FC10) {
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
	ctx.lr = 0x8225FC18;
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
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_8225FC30:
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8225fc48
	if (!cr6.eq) goto loc_8225FC48;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x8225fc60
	if (cr6.eq) goto loc_8225FC60;
loc_8225FC48:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmpwi cr6,r31,15
	cr6.compare<int32_t>(r31.s32, 15, xer);
	// blt cr6,0x8225fc30
	if (cr6.lt) goto loc_8225FC30;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8225FC60:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225fce0
	if (cr6.lt) goto loc_8225FCE0;
	// bl 0x82387a18
	ctx.lr = 0x8225FC6C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225fcd0
	if (cr6.eq) goto loc_8225FCD0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225FC8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225fce0
	if (cr6.eq) goto loc_8225FCE0;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// addi r3,r10,-11532
	ctx.r3.s64 = ctx.r10.s64 + -11532;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82130000
	ctx.lr = 0x8225FCBC;
	sub_82130000(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225f768
	ctx.lr = 0x8225FCC8;
	sub_8225F768(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8225FCD0:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822595c8
	ctx.lr = 0x8225FCE0;
	sub_822595C8(ctx, base);
loc_8225FCE0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8225FCE8"))) PPC_WEAK_FUNC(sub_8225FCE8);
PPC_FUNC_IMPL(__imp__sub_8225FCE8) {
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
	ctx.lr = 0x8225FCF0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r31,r27,16
	r31.s64 = r27.s64 + 16;
	// li r10,14
	ctx.r10.s64 = 14;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// li r26,-1
	r26.s64 = -1;
loc_8225FD0C:
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// bge 0x8225fd0c
	if (!cr0.lt) goto loc_8225FD0C;
	// li r29,0
	r29.s64 = 0;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r29,2144(r27)
	PPC_STORE_U32(r27.u32 + 2144, r29.u32);
	// stw r29,2140(r27)
	PPC_STORE_U32(r27.u32 + 2140, r29.u32);
	// stw r29,2136(r27)
	PPC_STORE_U32(r27.u32 + 2136, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x8225FD38;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225fd48
	if (cr6.eq) goto loc_8225FD48;
	// bl 0x8225a858
	ctx.lr = 0x8225FD44;
	sub_8225A858(ctx, base);
	// b 0x8225fd4c
	goto loc_8225FD4C;
loc_8225FD48:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8225FD4C:
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r30.u32);
	// mr r28,r29
	r28.u64 = r29.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8225FD60;
	sub_823EAEF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82267860
	ctx.lr = 0x8225FD68;
	sub_82267860(ctx, base);
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822677a0
	ctx.lr = 0x8225FD74;
	sub_822677A0(ctx, base);
	// addi r30,r27,1460
	r30.s64 = r27.s64 + 1460;
loc_8225FD78:
	// stb r29,-4(r30)
	PPC_STORE_U8(r30.u32 + -4, r29.u8);
	// li r3,144
	ctx.r3.s64 = 144;
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// bl 0x82130528
	ctx.lr = 0x8225FD88;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225fd9c
	if (cr6.eq) goto loc_8225FD9C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82238260
	ctx.lr = 0x8225FD98;
	sub_82238260(ctx, base);
	// b 0x8225fda0
	goto loc_8225FDA0;
loc_8225FD9C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8225FDA0:
	// stw r28,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r28.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// stb r29,12(r30)
	PPC_STORE_U8(r30.u32 + 12, r29.u8);
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x8225fd78
	if (cr6.lt) goto loc_8225FD78;
	// li r30,15
	r30.s64 = 15;
loc_8225FDC0:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// li r3,144
	ctx.r3.s64 = 144;
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x8225FDD8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225fdec
	if (cr6.eq) goto loc_8225FDEC;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82238260
	ctx.lr = 0x8225FDE8;
	sub_82238260(ctx, base);
	// b 0x8225fdf0
	goto loc_8225FDF0;
loc_8225FDEC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8225FDF0:
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stb r29,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r29.u8);
	// stw r29,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r29.u32);
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// bne 0x8225fdc0
	if (!cr0.eq) goto loc_8225FDC0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225fe7c
	if (cr6.eq) goto loc_8225FE7C;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8225FE28;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225fe3c
	if (cr6.eq) goto loc_8225FE3C;
	// bl 0x824ebf78
	ctx.lr = 0x8225FE34;
	sub_824EBF78(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8225fe40
	goto loc_8225FE40;
loc_8225FE3C:
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8225FE40:
	// lis r11,-32218
	r11.s64 = -2111438848;
	// stw r31,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r31.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r10,r11,-3464
	ctx.r10.s64 = r11.s64 + -3464;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8225FE5C;
	sub_82130000(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r4,8(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,-10240(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// lwz r8,4296(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// bl 0x824ec120
	ctx.lr = 0x8225FE7C;
	sub_824EC120(ctx, base);
loc_8225FE7C:
	// stw r29,2144(r27)
	PPC_STORE_U32(r27.u32 + 2144, r29.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r29,2140(r27)
	PPC_STORE_U32(r27.u32 + 2140, r29.u32);
	// stw r29,2136(r27)
	PPC_STORE_U32(r27.u32 + 2136, r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8225FE94"))) PPC_WEAK_FUNC(sub_8225FE94);
PPC_FUNC_IMPL(__imp__sub_8225FE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8225FE98"))) PPC_WEAK_FUNC(sub_8225FE98);
PPC_FUNC_IMPL(__imp__sub_8225FE98) {
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
	ctx.lr = 0x8225FEA0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,3168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 3168);
	// lbz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8225fef0
	if (!cr6.eq) goto loc_8225FEF0;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lbz r9,114(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 114);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225fef0
	if (!cr6.eq) goto loc_8225FEF0;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lbz r9,114(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 114);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225ff48
	if (cr6.eq) goto loc_8225FF48;
loc_8225FEF0:
	// bl 0x82387a18
	ctx.lr = 0x8225FEF4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ff38
	if (cr6.eq) goto loc_8225FF38;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225FF14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225ff48
	if (cr6.eq) goto loc_8225FF48;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225f950
	ctx.lr = 0x8225FF30;
	sub_8225F950(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8225FF38:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822598e0
	ctx.lr = 0x8225FF48;
	sub_822598E0(ctx, base);
loc_8225FF48:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8225FF50"))) PPC_WEAK_FUNC(sub_8225FF50);
PPC_FUNC_IMPL(__imp__sub_8225FF50) {
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
	// bl 0x82387a18
	ctx.lr = 0x8225FF70;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225ffac
	if (cr6.eq) goto loc_8225FFAC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225FF90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225ffb8
	if (cr6.eq) goto loc_8225FFB8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8225fa40
	ctx.lr = 0x8225FFA8;
	sub_8225FA40(ctx, base);
	// b 0x8225ffb8
	goto loc_8225FFB8;
loc_8225FFAC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82259c08
	ctx.lr = 0x8225FFB8;
	sub_82259C08(ctx, base);
loc_8225FFB8:
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

__attribute__((alias("__imp__sub_8225FFD0"))) PPC_WEAK_FUNC(sub_8225FFD0);
PPC_FUNC_IMPL(__imp__sub_8225FFD0) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8225FFD8;
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// lwz r11,4(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 4);
	// addic. r24,r11,8
	xer.ca = r11.u32 > 4294967287;
	r24.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// beq 0x82260144
	if (cr0.eq) goto loc_82260144;
	// lwz r11,3080(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 3080);
	// li r22,0
	r22.s64 = 0;
	// mr r26,r22
	r26.u64 = r22.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82260144
	if (!cr6.gt) goto loc_82260144;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r27,r24,8
	r27.s64 = r24.s64 + 8;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8226001C:
	// lwz r28,0(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82260130
	if (cr6.eq) goto loc_82260130;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226003C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82260130
	if (cr6.eq) goto loc_82260130;
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226005c
	if (cr6.eq) goto loc_8226005C;
	// lwz r29,68(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// b 0x82260060
	goto loc_82260060;
loc_8226005C:
	// mr r29,r22
	r29.u64 = r22.u64;
loc_82260060:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82260078
	if (cr6.eq) goto loc_82260078;
	// lbz r11,114(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 114);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226007c
	if (!cr6.eq) goto loc_8226007C;
loc_82260078:
	// mr r30,r22
	r30.u64 = r22.u64;
loc_8226007C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82224ac8
	ctx.lr = 0x82260084;
	sub_82224AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260104
	if (cr6.eq) goto loc_82260104;
	// lwz r3,-6432(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -6432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82260104
	if (cr6.eq) goto loc_82260104;
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// subfc r10,r11,r22
	xer.ca = r22.u32 >= r11.u32;
	ctx.r10.s64 = r22.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82260104
	if (cr6.eq) goto loc_82260104;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822600C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,700(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 700);
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82260100
	if (cr6.eq) goto loc_82260100;
	// lwz r11,-5084(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -5084);
	// lfs f30,128(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 128);
	f30.f64 = double(temp.f32);
	// addi r4,r11,76
	ctx.r4.s64 = r11.s64 + 76;
	// bl 0x82241db0
	ctx.lr = 0x822600EC;
	sub_82241DB0(ctx, base);
	// fneg f0,f30
	ctx.fpscr.disableFlushMode();
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsel f1,f0,f31,f30
	ctx.f1.f64 = f0.f64 >= 0.0 ? f31.f64 : f30.f64;
	// bl 0x82241e38
	ctx.lr = 0x822600FC;
	sub_82241E38(ctx, base);
	// b 0x82260104
	goto loc_82260104;
loc_82260100:
	// bl 0x82241e20
	ctx.lr = 0x82260104;
	sub_82241E20(ctx, base);
loc_82260104:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260130
	if (cr6.eq) goto loc_82260130;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8232ae20
	ctx.lr = 0x82260118;
	sub_8232AE20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260130
	if (cr6.eq) goto loc_82260130;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8225ff50
	ctx.lr = 0x82260130;
	sub_8225FF50(ctx, base);
loc_82260130:
	// lwz r11,3080(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 3080);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,192
	r27.s64 = r27.s64 + 192;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8226001c
	if (cr6.lt) goto loc_8226001C;
loc_82260144:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82260154"))) PPC_WEAK_FUNC(sub_82260154);
PPC_FUNC_IMPL(__imp__sub_82260154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82260158"))) PPC_WEAK_FUNC(sub_82260158);
PPC_FUNC_IMPL(__imp__sub_82260158) {
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
	ctx.lr = 0x82260160;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,-5056(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5056);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82260188
	if (!cr6.gt) goto loc_82260188;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_82260188:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r3,r11,-11472
	ctx.r3.s64 = r11.s64 + -11472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x822601A0;
	sub_82130000(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x822601A4;
	sub_82387A18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// beq cr6,0x822601cc
	if (cr6.eq) goto loc_822601CC;
	// bl 0x8225f608
	ctx.lr = 0x822601C4;
	sub_8225F608(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822601CC:
	// bl 0x8225b9a8
	ctx.lr = 0x822601D0;
	sub_8225B9A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822601D8"))) PPC_WEAK_FUNC(sub_822601D8);
PPC_FUNC_IMPL(__imp__sub_822601D8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822601E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822602b0
	if (cr6.eq) goto loc_822602B0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822602b0
	if (cr6.eq) goto loc_822602B0;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822602b0
	if (cr6.eq) goto loc_822602B0;
	// bl 0x82387a18
	ctx.lr = 0x82260228;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260274
	if (cr6.eq) goto loc_82260274;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82260248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822602b0
	if (cr6.eq) goto loc_822602B0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225f840
	ctx.lr = 0x82260260;
	sub_8225F840(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-11404
	ctx.r3.s64 = r11.s64 + -11404;
	// bl 0x82130000
	ctx.lr = 0x8226026C;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82260274:
	// li r11,16
	r11.s64 = 16;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,31016(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82257bf8
	ctx.lr = 0x8226029C;
	sub_82257BF8(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82259790
	ctx.lr = 0x822602B0;
	sub_82259790(ctx, base);
loc_822602B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822602B8"))) PPC_WEAK_FUNC(sub_822602B8);
PPC_FUNC_IMPL(__imp__sub_822602B8) {
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
	// b 0x8225fb58
	sub_8225FB58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822602CC"))) PPC_WEAK_FUNC(sub_822602CC);
PPC_FUNC_IMPL(__imp__sub_822602CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822602D0"))) PPC_WEAK_FUNC(sub_822602D0);
PPC_FUNC_IMPL(__imp__sub_822602D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8225f578
	sub_8225F578(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822602E4"))) PPC_WEAK_FUNC(sub_822602E4);
PPC_FUNC_IMPL(__imp__sub_822602E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822602E8"))) PPC_WEAK_FUNC(sub_822602E8);
PPC_FUNC_IMPL(__imp__sub_822602E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8225fc10
	sub_8225FC10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822602F8"))) PPC_WEAK_FUNC(sub_822602F8);
PPC_FUNC_IMPL(__imp__sub_822602F8) {
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
	ctx.lr = 0x82260300;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x82387a18
	ctx.lr = 0x8226031C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260340
	if (cr6.eq) goto loc_82260340;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x82260334;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82260470
	if (cr6.eq) goto loc_82260470;
loc_82260340:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-27688
	ctx.r9.s64 = r11.s64 + -27688;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r8,-11360
	ctx.r3.s64 = ctx.r8.s64 + -11360;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x82260360;
	sub_82130000(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82258c50
	ctx.lr = 0x82260370;
	sub_82258C50(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x82260394
	if (cr6.gt) goto loc_82260394;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x8226038c
	if (cr6.lt) goto loc_8226038C;
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82258c50
	ctx.lr = 0x8226038C;
	sub_82258C50(ctx, base);
loc_8226038C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82260470
	if (!cr6.gt) goto loc_82260470;
loc_82260394:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// twllei r3,0
	// lwz r4,2192(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// li r31,0
	r31.s64 = 0;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r4,r5
	ctx.r10.s64 = ctx.r4.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// clrlwi r7,r11,1
	ctx.r7.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r6,r7,r3
	ctx.r6.s32 = ctx.r7.s32 / ctx.r3.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// mullw r4,r6,r3
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r3.s32);
	// andc r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 & ~ctx.r5.u64;
	// subf r7,r4,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r4.s64;
	// twlgei r3,-1
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82260470
	if (!cr6.gt) goto loc_82260470;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
loc_82260400:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bne cr6,0x82260460
	if (!cr6.eq) goto loc_82260460;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r30,20
	r11.s64 = r30.s64 + 20;
loc_82260414:
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8226042c
	if (cr6.eq) goto loc_8226042C;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r6,r31
	cr6.compare<int32_t>(ctx.r6.s32, r31.s32, xer);
	// beq cr6,0x8226047c
	if (cr6.eq) goto loc_8226047C;
loc_8226042C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmpwi cr6,r10,15
	cr6.compare<int32_t>(ctx.r10.s32, 15, xer);
	// blt cr6,0x82260414
	if (cr6.lt) goto loc_82260414;
	// li r11,0
	r11.s64 = 0;
loc_82260440:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82260460
	if (!cr6.eq) goto loc_82260460;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// beq cr6,0x82260460
	if (cr6.eq) goto loc_82260460;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x82260484
	if (cr6.eq) goto loc_82260484;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
loc_82260460:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82260400
	if (cr6.lt) goto loc_82260400;
loc_82260470:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8226047C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82260440
	goto loc_82260440;
loc_82260484:
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82260158
	ctx.lr = 0x82260498;
	sub_82260158(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822604A4"))) PPC_WEAK_FUNC(sub_822604A4);
PPC_FUNC_IMPL(__imp__sub_822604A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822604A8"))) PPC_WEAK_FUNC(sub_822604A8);
PPC_FUNC_IMPL(__imp__sub_822604A8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822604B0;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// bl 0x82387a18
	ctx.lr = 0x822604E0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260504
	if (cr6.eq) goto loc_82260504;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x822604F8;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822605a4
	if (cr6.eq) goto loc_822605A4;
loc_82260504:
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,-27688
	ctx.r4.s64 = r11.s64 + -27688;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// addi r3,r3,-11208
	ctx.r3.s64 = ctx.r3.s64 + -11208;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwzx r4,r10,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x82260544;
	sub_82130000(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// sth r11,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r11.u16);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8225b7d8
	ctx.lr = 0x82260574;
	sub_8225B7D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-11256
	ctx.r3.s64 = r11.s64 + -11256;
	// bl 0x82130000
	ctx.lr = 0x82260588;
	sub_82130000(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x822605b8
	if (cr6.gt) goto loc_822605B8;
	// lhz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822605a4
	if (cr6.eq) goto loc_822605A4;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x822605A4;
	sub_82130588(ctx, base);
loc_822605A4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_822605B8:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lwz r9,2192(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// twllei r31,0
	// addi r3,r4,-11308
	ctx.r3.s64 = ctx.r4.s64 + -11308;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r9,r5
	ctx.r10.s64 = ctx.r9.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// divw r6,r8,r31
	ctx.r6.s32 = ctx.r8.s32 / r31.s32;
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(r31.s32);
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r9,r31,r11
	ctx.r9.u64 = r31.u64 & ~r11.u64;
	// twlgei r9,-1
	// lwzx r31,r10,r26
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// rlwinm r10,r31,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsubs f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f5,f12,f10
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x82260670;
	sub_82130000(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82260158
	ctx.lr = 0x82260684;
	sub_82260158(ctx, base);
	// lhz r7,86(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82260698
	if (cr6.eq) goto loc_82260698;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x82260698;
	sub_82130588(ctx, base);
loc_82260698:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822606AC"))) PPC_WEAK_FUNC(sub_822606AC);
PPC_FUNC_IMPL(__imp__sub_822606AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822606B0"))) PPC_WEAK_FUNC(sub_822606B0);
PPC_FUNC_IMPL(__imp__sub_822606B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lbz r9,113(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 113);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
loc_822606CC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822606e4
	if (cr6.eq) goto loc_822606E4;
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x822606f8
	if (cr6.eq) goto loc_822606F8;
loc_822606E4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmpwi cr6,r10,15
	cr6.compare<int32_t>(ctx.r10.s32, 15, xer);
	// blt cr6,0x822606cc
	if (cr6.lt) goto loc_822606CC;
	// blr 
	return;
loc_822606F8:
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// b 0x822601d8
	sub_822601D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82260700"))) PPC_WEAK_FUNC(sub_82260700);
PPC_FUNC_IMPL(__imp__sub_82260700) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82260708;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r31,r29,48
	r31.s64 = r29.s64 + 48;
	// mr r28,r22
	r28.u64 = r22.u64;
	// li r23,1
	r23.s64 = 1;
	// li r24,-16
	r24.s64 = -16;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// li r25,80
	r25.s64 = 80;
	// addi r27,r11,-11100
	r27.s64 = r11.s64 + -11100;
loc_82260734:
	// lwz r11,-32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82260834
	if (cr6.eq) goto loc_82260834;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82260778
	if (!cr6.eq) goto loc_82260778;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x82256028
	ctx.lr = 0x82260750;
	sub_82256028(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// mr r11,r23
	r11.u64 = r23.u64;
	// blt cr6,0x82260764
	if (cr6.lt) goto loc_82260764;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82260764:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82260778
	if (!cr6.eq) goto loc_82260778;
	// stw r23,-32(r31)
	PPC_STORE_U32(r31.u32 + -32, r23.u32);
	// stw r22,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r22.u32);
loc_82260778:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82260834
	if (cr6.eq) goto loc_82260834;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x8226078C;
	sub_822A8108(ctx, base);
	// addi r21,r3,48
	r21.s64 = ctx.r3.s64 + 48;
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lvx128 v62,r0,r21
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82263680
	ctx.lr = 0x822607AC;
	sub_82263680(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x82264e80
	ctx.lr = 0x822607B4;
	sub_82264E80(ctx, base);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82260800
	if (cr6.eq) goto loc_82260800;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82260800
	if (cr6.eq) goto loc_82260800;
	// lbz r10,113(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 113);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822607e4
	if (!cr6.eq) goto loc_822607E4;
	// lbz r11,114(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 114);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260800
	if (cr6.eq) goto loc_82260800;
loc_822607E4:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x822607F4;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82260834
	if (!cr6.eq) goto loc_82260834;
loc_82260800:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r5,-24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -24);
	// lwz r4,-28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -28);
	// bl 0x82130000
	ctx.lr = 0x82260810;
	sub_82130000(ctx, base);
	// lwz r3,-3624(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x82260818;
	sub_8226BF18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260834
	if (cr6.eq) goto loc_82260834;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225f578
	ctx.lr = 0x82260834;
	sub_8225F578(ctx, base);
loc_82260834:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// cmpwi cr6,r28,15
	cr6.compare<int32_t>(r28.s32, 15, xer);
	// blt cr6,0x82260734
	if (cr6.lt) goto loc_82260734;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8225ffd0
	ctx.lr = 0x8226084C;
	sub_8225FFD0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82258da8
	ctx.lr = 0x82260854;
	sub_82258DA8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8226085C"))) PPC_WEAK_FUNC(sub_8226085C);
PPC_FUNC_IMPL(__imp__sub_8226085C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82260860"))) PPC_WEAK_FUNC(sub_82260860);
PPC_FUNC_IMPL(__imp__sub_82260860) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-11376
	ctx.r3.s64 = ctx.r10.s64 + -11376;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130000
	ctx.lr = 0x8226088C;
	sub_82130000(ctx, base);
	// li r3,2160
	ctx.r3.s64 = 2160;
	// bl 0x82130528
	ctx.lr = 0x82260894;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822608b0
	if (cr6.eq) goto loc_822608B0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8225fce8
	ctx.lr = 0x822608A4;
	sub_8225FCE8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// b 0x822608bc
	goto loc_822608BC;
loc_822608B0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_822608BC:
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

__attribute__((alias("__imp__sub_822608D4"))) PPC_WEAK_FUNC(sub_822608D4);
PPC_FUNC_IMPL(__imp__sub_822608D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822608D8"))) PPC_WEAK_FUNC(sub_822608D8);
PPC_FUNC_IMPL(__imp__sub_822608D8) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x822602f8
	ctx.lr = 0x82260908;
	sub_822602F8(ctx, base);
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

__attribute__((alias("__imp__sub_82260924"))) PPC_WEAK_FUNC(sub_82260924);
PPC_FUNC_IMPL(__imp__sub_82260924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82260928"))) PPC_WEAK_FUNC(sub_82260928);
PPC_FUNC_IMPL(__imp__sub_82260928) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32218
	r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,1192
	ctx.r3.s64 = r11.s64 + 1192;
	// b 0x8225ada0
	sub_8225ADA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82260938"))) PPC_WEAK_FUNC(sub_82260938);
PPC_FUNC_IMPL(__imp__sub_82260938) {
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
	// addi r4,r11,2144
	ctx.r4.s64 = r11.s64 + 2144;
	// addi r3,r10,-10180
	ctx.r3.s64 = ctx.r10.s64 + -10180;
	// bl 0x82554798
	ctx.lr = 0x82260958;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10088
	ctx.r4.s64 = ctx.r9.s64 + -10088;
	// addi r3,r8,-10192
	ctx.r3.s64 = ctx.r8.s64 + -10192;
	// bl 0x82554798
	ctx.lr = 0x8226096C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-24880
	ctx.r4.s64 = ctx.r7.s64 + -24880;
	// addi r3,r6,-10204
	ctx.r3.s64 = ctx.r6.s64 + -10204;
	// bl 0x82554798
	ctx.lr = 0x82260980;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-24864
	ctx.r4.s64 = ctx.r5.s64 + -24864;
	// addi r3,r3,-10224
	ctx.r3.s64 = ctx.r3.s64 + -10224;
	// bl 0x82554798
	ctx.lr = 0x82260994;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-24840
	ctx.r4.s64 = r11.s64 + -24840;
	// addi r3,r10,-10244
	ctx.r3.s64 = ctx.r10.s64 + -10244;
	// bl 0x82554798
	ctx.lr = 0x822609A8;
	sub_82554798(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10216
	ctx.r4.s64 = ctx.r9.s64 + -10216;
	// addi r3,r8,-10256
	ctx.r3.s64 = ctx.r8.s64 + -10256;
	// bl 0x82554798
	ctx.lr = 0x822609BC;
	sub_82554798(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-10240
	ctx.r4.s64 = ctx.r7.s64 + -10240;
	// addi r3,r6,-10268
	ctx.r3.s64 = ctx.r6.s64 + -10268;
	// bl 0x82554798
	ctx.lr = 0x822609D0;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-1296
	ctx.r4.s64 = ctx.r5.s64 + -1296;
	// addi r3,r3,-10288
	ctx.r3.s64 = ctx.r3.s64 + -10288;
	// bl 0x82554798
	ctx.lr = 0x822609E4;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-1224
	ctx.r4.s64 = r11.s64 + -1224;
	// addi r3,r10,-10312
	ctx.r3.s64 = ctx.r10.s64 + -10312;
	// bl 0x82554798
	ctx.lr = 0x822609F8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,696
	ctx.r4.s64 = ctx.r9.s64 + 696;
	// addi r3,r8,-10336
	ctx.r3.s64 = ctx.r8.s64 + -10336;
	// bl 0x82554798
	ctx.lr = 0x82260A0C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,720
	ctx.r4.s64 = ctx.r7.s64 + 720;
	// addi r3,r6,-10372
	ctx.r3.s64 = ctx.r6.s64 + -10372;
	// bl 0x82554798
	ctx.lr = 0x82260A20;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,744
	ctx.r4.s64 = ctx.r5.s64 + 744;
	// addi r3,r3,-10396
	ctx.r3.s64 = ctx.r3.s64 + -10396;
	// bl 0x82554798
	ctx.lr = 0x82260A34;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-1208
	ctx.r4.s64 = r11.s64 + -1208;
	// addi r3,r10,-10416
	ctx.r3.s64 = ctx.r10.s64 + -10416;
	// bl 0x82554798
	ctx.lr = 0x82260A48;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-24816
	ctx.r4.s64 = ctx.r9.s64 + -24816;
	// addi r3,r8,-10436
	ctx.r3.s64 = ctx.r8.s64 + -10436;
	// bl 0x82554798
	ctx.lr = 0x82260A5C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-17392
	ctx.r4.s64 = ctx.r7.s64 + -17392;
	// addi r3,r6,-10456
	ctx.r3.s64 = ctx.r6.s64 + -10456;
	// bl 0x82554798
	ctx.lr = 0x82260A70;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-24752
	ctx.r4.s64 = ctx.r5.s64 + -24752;
	// addi r3,r3,-10476
	ctx.r3.s64 = ctx.r3.s64 + -10476;
	// bl 0x82554798
	ctx.lr = 0x82260A84;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-24688
	ctx.r4.s64 = r11.s64 + -24688;
	// addi r3,r10,-10508
	ctx.r3.s64 = ctx.r10.s64 + -10508;
	// bl 0x82554798
	ctx.lr = 0x82260A98;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-17248
	ctx.r4.s64 = ctx.r9.s64 + -17248;
	// addi r3,r8,-10528
	ctx.r3.s64 = ctx.r8.s64 + -10528;
	// bl 0x82554798
	ctx.lr = 0x82260AAC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-24560
	ctx.r4.s64 = ctx.r7.s64 + -24560;
	// addi r3,r6,-10548
	ctx.r3.s64 = ctx.r6.s64 + -10548;
	// bl 0x82554798
	ctx.lr = 0x82260AC0;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,32008
	ctx.r4.s64 = ctx.r5.s64 + 32008;
	// addi r3,r3,-10572
	ctx.r3.s64 = ctx.r3.s64 + -10572;
	// bl 0x82554798
	ctx.lr = 0x82260AD4;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,32024
	ctx.r4.s64 = r11.s64 + 32024;
	// addi r3,r10,-10596
	ctx.r3.s64 = ctx.r10.s64 + -10596;
	// bl 0x82554798
	ctx.lr = 0x82260AE8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-17120
	ctx.r4.s64 = ctx.r9.s64 + -17120;
	// addi r3,r8,-10628
	ctx.r3.s64 = ctx.r8.s64 + -10628;
	// bl 0x82554798
	ctx.lr = 0x82260AFC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-17048
	ctx.r4.s64 = ctx.r7.s64 + -17048;
	// addi r3,r6,-10660
	ctx.r3.s64 = ctx.r6.s64 + -10660;
	// bl 0x82554798
	ctx.lr = 0x82260B10;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-24512
	ctx.r4.s64 = ctx.r5.s64 + -24512;
	// addi r3,r3,-10688
	ctx.r3.s64 = ctx.r3.s64 + -10688;
	// bl 0x82554798
	ctx.lr = 0x82260B24;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-24448
	ctx.r4.s64 = r11.s64 + -24448;
	// addi r3,r10,-10704
	ctx.r3.s64 = ctx.r10.s64 + -10704;
	// bl 0x82554798
	ctx.lr = 0x82260B38;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-24376
	ctx.r4.s64 = ctx.r9.s64 + -24376;
	// addi r3,r8,-10720
	ctx.r3.s64 = ctx.r8.s64 + -10720;
	// bl 0x82554798
	ctx.lr = 0x82260B4C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-24304
	ctx.r4.s64 = ctx.r7.s64 + -24304;
	// addi r3,r6,-10740
	ctx.r3.s64 = ctx.r6.s64 + -10740;
	// bl 0x82554798
	ctx.lr = 0x82260B60;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-24256
	ctx.r4.s64 = ctx.r5.s64 + -24256;
	// addi r3,r3,-10760
	ctx.r3.s64 = ctx.r3.s64 + -10760;
	// bl 0x82554798
	ctx.lr = 0x82260B74;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-24200
	ctx.r4.s64 = r11.s64 + -24200;
	// addi r3,r10,-10788
	ctx.r3.s64 = ctx.r10.s64 + -10788;
	// bl 0x82554798
	ctx.lr = 0x82260B88;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-24064
	ctx.r4.s64 = ctx.r9.s64 + -24064;
	// addi r3,r8,-10820
	ctx.r3.s64 = ctx.r8.s64 + -10820;
	// bl 0x82554798
	ctx.lr = 0x82260B9C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,2264
	ctx.r4.s64 = ctx.r7.s64 + 2264;
	// addi r3,r6,-10836
	ctx.r3.s64 = ctx.r6.s64 + -10836;
	// bl 0x82554798
	ctx.lr = 0x82260BB0;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,2344
	ctx.r4.s64 = ctx.r5.s64 + 2344;
	// addi r3,r3,-10860
	ctx.r3.s64 = ctx.r3.s64 + -10860;
	// bl 0x82554798
	ctx.lr = 0x82260BC4;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// addi r4,r11,-24008
	ctx.r4.s64 = r11.s64 + -24008;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-10880
	ctx.r3.s64 = ctx.r10.s64 + -10880;
	// bl 0x82554798
	ctx.lr = 0x82260BD8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-23968
	ctx.r4.s64 = ctx.r9.s64 + -23968;
	// addi r3,r8,-10900
	ctx.r3.s64 = ctx.r8.s64 + -10900;
	// bl 0x82554798
	ctx.lr = 0x82260BEC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-23880
	ctx.r4.s64 = ctx.r7.s64 + -23880;
	// addi r3,r6,-10920
	ctx.r3.s64 = ctx.r6.s64 + -10920;
	// bl 0x82554798
	ctx.lr = 0x82260C00;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-23816
	ctx.r4.s64 = ctx.r5.s64 + -23816;
	// addi r3,r3,-10940
	ctx.r3.s64 = ctx.r3.s64 + -10940;
	// bl 0x82554798
	ctx.lr = 0x82260C14;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-23800
	ctx.r4.s64 = r11.s64 + -23800;
	// addi r3,r10,-10964
	ctx.r3.s64 = ctx.r10.s64 + -10964;
	// bl 0x82554798
	ctx.lr = 0x82260C28;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-23712
	ctx.r4.s64 = ctx.r9.s64 + -23712;
	// addi r3,r8,-10988
	ctx.r3.s64 = ctx.r8.s64 + -10988;
	// bl 0x82554798
	ctx.lr = 0x82260C3C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-23568
	ctx.r4.s64 = ctx.r7.s64 + -23568;
	// addi r3,r6,-11004
	ctx.r3.s64 = ctx.r6.s64 + -11004;
	// bl 0x82554798
	ctx.lr = 0x82260C50;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-23520
	ctx.r4.s64 = ctx.r5.s64 + -23520;
	// addi r3,r3,-11020
	ctx.r3.s64 = ctx.r3.s64 + -11020;
	// bl 0x82554798
	ctx.lr = 0x82260C64;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-23472
	ctx.r4.s64 = r11.s64 + -23472;
	// addi r3,r10,-11036
	ctx.r3.s64 = ctx.r10.s64 + -11036;
	// bl 0x82554798
	ctx.lr = 0x82260C78;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-23440
	ctx.r4.s64 = ctx.r9.s64 + -23440;
	// addi r3,r8,-11052
	ctx.r3.s64 = ctx.r8.s64 + -11052;
	// bl 0x82554798
	ctx.lr = 0x82260C8C;
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

__attribute__((alias("__imp__sub_82260C9C"))) PPC_WEAK_FUNC(sub_82260C9C);
PPC_FUNC_IMPL(__imp__sub_82260C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82260CA0"))) PPC_WEAK_FUNC(sub_82260CA0);
PPC_FUNC_IMPL(__imp__sub_82260CA0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-5008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -5008);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82260cd4
	if (cr6.eq) goto loc_82260CD4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82260CD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82260CD4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-5008(r31)
	PPC_STORE_U32(r31.u32 + -5008, r11.u32);
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

__attribute__((alias("__imp__sub_82260CF0"))) PPC_WEAK_FUNC(sub_82260CF0);
PPC_FUNC_IMPL(__imp__sub_82260CF0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,-12348(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82391270
	ctx.lr = 0x82260D18;
	sub_82391270(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82260d48
	if (!cr6.eq) goto loc_82260D48;
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r9,r11,128
	ctx.r9.u64 = r11.u64 | 128;
	// stb r9,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r9.u8);
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82260D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82260D48:
	// lbz r11,76(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 76);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82260d74
	if (cr6.eq) goto loc_82260D74;
	// lwz r11,1888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1888);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lwz r11,1892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1892);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r10,1888(r31)
	PPC_STORE_U32(r31.u32 + 1888, ctx.r10.u32);
	// stw r9,1892(r31)
	PPC_STORE_U32(r31.u32 + 1892, ctx.r9.u32);
	// b 0x82260d8c
	goto loc_82260D8C;
loc_82260D74:
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260d8c
	if (cr6.eq) goto loc_82260D8C;
	// lwz r11,1892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1892);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1892(r31)
	PPC_STORE_U32(r31.u32 + 1892, r11.u32);
loc_82260D8C:
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

__attribute__((alias("__imp__sub_82260DA4"))) PPC_WEAK_FUNC(sub_82260DA4);
PPC_FUNC_IMPL(__imp__sub_82260DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82260DA8"))) PPC_WEAK_FUNC(sub_82260DA8);
PPC_FUNC_IMPL(__imp__sub_82260DA8) {
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
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r11,r11,240
	r11.s64 = r11.s64 + 240;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r7,272
	ctx.r7.s64 = 272;
	// li r6,64
	ctx.r6.s64 = 64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,288
	ctx.r5.s64 = 288;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,80
	ctx.r3.s64 = 80;
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lvx128 v59,r10,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,128(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lvx128 v58,r8,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,20(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lfs f0,36(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	f0.f64 = double(temp.f32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lwz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,592(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 592);
	// stw r5,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r5.u32);
	// bl 0x82331d40
	ctx.lr = 0x82260E40;
	sub_82331D40(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82260e5c
	if (cr6.eq) goto loc_82260E5C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// lbz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 564);
	// stb r10,96(r31)
	PPC_STORE_U8(r31.u32 + 96, ctx.r10.u8);
loc_82260E5C:
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

__attribute__((alias("__imp__sub_82260E70"))) PPC_WEAK_FUNC(sub_82260E70);
PPC_FUNC_IMPL(__imp__sub_82260E70) {
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
	// lis r30,-32120
	r30.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82260ee4
	if (cr6.eq) goto loc_82260EE4;
	// bl 0x822f10d0
	ctx.lr = 0x82260E9C;
	sub_822F10D0(ctx, base);
	// stfs f1,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// lwz r11,-7572(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lbz r10,14552(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14552);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82260eb8
	if (cr6.eq) goto loc_82260EB8;
	// lfs f0,14556(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14556);
	f0.f64 = double(temp.f32);
	// b 0x82260ebc
	goto loc_82260EBC;
loc_82260EB8:
	// lfs f0,14540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14540);
	f0.f64 = double(temp.f32);
loc_82260EBC:
	// stfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// lwz r11,-7572(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lbz r10,14552(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14552);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82260ed8
	if (cr6.eq) goto loc_82260ED8;
	// lfs f0,14548(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14548);
	f0.f64 = double(temp.f32);
	// b 0x82260ee0
	goto loc_82260EE0;
loc_82260ED8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82260EE0:
	// stfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
loc_82260EE4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// lwz r11,-7884(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7884);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lfs f0,-7892(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7892);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// bl 0x822e8b20
	ctx.lr = 0x82260F04;
	sub_822E8B20(ctx, base);
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

__attribute__((alias("__imp__sub_82260F1C"))) PPC_WEAK_FUNC(sub_82260F1C);
PPC_FUNC_IMPL(__imp__sub_82260F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82260F20"))) PPC_WEAK_FUNC(sub_82260F20);
PPC_FUNC_IMPL(__imp__sub_82260F20) {
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
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-7572(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82260f80
	if (cr6.eq) goto loc_82260F80;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,-17936(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r6,r9,3633
	ctx.r6.s64 = ctx.r9.s64 + 3633;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r5,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, temp.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stb r7,14552(r8)
	PPC_STORE_U8(ctx.r8.u32 + 14552, ctx.r7.u8);
	// stfs f0,14540(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 14540, temp.u32);
	// lwz r3,-7572(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// lfs f2,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f1518
	ctx.lr = 0x82260F80;
	sub_822F1518(ctx, base);
loc_82260F80:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stw r11,-7884(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7884, r11.u32);
	// bl 0x822e8a78
	ctx.lr = 0x82260F90;
	sub_822E8A78(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stfs f0,-7892(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -7892, temp.u32);
	// bl 0x822e8b50
	ctx.lr = 0x82260FA4;
	sub_822E8B50(ctx, base);
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

__attribute__((alias("__imp__sub_82260FB8"))) PPC_WEAK_FUNC(sub_82260FB8);
PPC_FUNC_IMPL(__imp__sub_82260FB8) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82260FE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82260FF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82261010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,36(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82261024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226103C;
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

__attribute__((alias("__imp__sub_82261054"))) PPC_WEAK_FUNC(sub_82261054);
PPC_FUNC_IMPL(__imp__sub_82261054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82261058"))) PPC_WEAK_FUNC(sub_82261058);
PPC_FUNC_IMPL(__imp__sub_82261058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-5008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82261074"))) PPC_WEAK_FUNC(sub_82261074);
PPC_FUNC_IMPL(__imp__sub_82261074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82261078"))) PPC_WEAK_FUNC(sub_82261078);
PPC_FUNC_IMPL(__imp__sub_82261078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-5008(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5008);
	// lbz r9,2620(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2620);
	// ori r8,r9,64
	ctx.r8.u64 = ctx.r9.u64 | 64;
	// stb r8,2620(r11)
	PPC_STORE_U8(r11.u32 + 2620, ctx.r8.u8);
	// lwz r11,-5008(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5008);
	// lbz r7,2620(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 2620);
	// rlwinm r6,r7,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,2620(r11)
	PPC_STORE_U8(r11.u32 + 2620, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822610B0"))) PPC_WEAK_FUNC(sub_822610B0);
PPC_FUNC_IMPL(__imp__sub_822610B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lbz r10,2620(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2620);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822610C4"))) PPC_WEAK_FUNC(sub_822610C4);
PPC_FUNC_IMPL(__imp__sub_822610C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822610C8"))) PPC_WEAK_FUNC(sub_822610C8);
PPC_FUNC_IMPL(__imp__sub_822610C8) {
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
	// addi r10,r11,-9824
	ctx.r10.s64 = r11.s64 + -9824;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,2608(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2608);
	// bl 0x82130588
	ctx.lr = 0x822610F8;
	sub_82130588(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261110
	if (cr6.eq) goto loc_82261110;
	// bl 0x82130588
	ctx.lr = 0x8226110C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82261110:
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

__attribute__((alias("__imp__sub_82261128"))) PPC_WEAK_FUNC(sub_82261128);
PPC_FUNC_IMPL(__imp__sub_82261128) {
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
	// li r3,2624
	ctx.r3.s64 = 2624;
	// bl 0x82130528
	ctx.lr = 0x8226113C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82261194
	if (cr6.eq) goto loc_82261194;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// addi r9,r10,-9824
	ctx.r9.s64 = ctx.r10.s64 + -9824;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,2608(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2608, r11.u32);
	// sth r11,2612(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2612, r11.u16);
	// sth r11,2614(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2614, r11.u16);
	// lbz r7,2620(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2620);
	// clrlwi r6,r7,30
	ctx.r6.u64 = ctx.r7.u32 & 0x3;
	// std r11,1880(r3)
	PPC_STORE_U64(ctx.r3.u32 + 1880, r11.u64);
	// stw r11,1892(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1892, r11.u32);
	// stw r11,1888(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1888, r11.u32);
	// stb r6,2620(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2620, ctx.r6.u8);
	// stw r11,2616(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2616, r11.u32);
	// stw r3,-5008(r8)
	PPC_STORE_U32(ctx.r8.u32 + -5008, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82261194:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r11,-5008(r10)
	PPC_STORE_U32(ctx.r10.u32 + -5008, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822611AC"))) PPC_WEAK_FUNC(sub_822611AC);
PPC_FUNC_IMPL(__imp__sub_822611AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822611B0"))) PPC_WEAK_FUNC(sub_822611B0);
PPC_FUNC_IMPL(__imp__sub_822611B0) {
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
	ctx.lr = 0x822611B8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32131
	r31.s64 = -2105737216;
	// addi r30,r31,29952
	r30.s64 = r31.s64 + 29952;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,29952(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29952);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822611D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,29952(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29952);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f1,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822611F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,18352
	ctx.r7.s64 = ctx.r8.s64 + 18352;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// stw r11,18352(r8)
	PPC_STORE_U32(ctx.r8.u32 + 18352, r11.u32);
	// stw r10,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// lwz r3,-4964(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -4964);
	// bl 0x82729d28
	ctx.lr = 0x8226121C;
	sub_82729D28(ctx, base);
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// bl 0x8258b088
	ctx.lr = 0x82261228;
	sub_8258B088(ctx, base);
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// bl 0x82587f88
	ctx.lr = 0x82261230;
	sub_82587F88(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-10016(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10016);
	// bl 0x82702808
	ctx.lr = 0x8226123C;
	sub_82702808(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lwz r3,-5148(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -5148);
	// bl 0x822b7710
	ctx.lr = 0x82261248;
	sub_822B7710(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r3,-3660(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -3660);
	// bl 0x8226a9c8
	ctx.lr = 0x82261254;
	sub_8226A9C8(ctx, base);
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lwz r3,-7796(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -7796);
	// bl 0x82130000
	ctx.lr = 0x82261260;
	sub_82130000(ctx, base);
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,72
	r26.s64 = 72;
	// lbzx r11,r26,r27
	r11.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r28,r11,17892
	r28.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82261288
	if (cr6.eq) goto loc_82261288;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x8226128c
	goto loc_8226128C;
loc_82261288:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_8226128C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82261358
	if (!cr6.gt) goto loc_82261358;
	// li r30,0
	r30.s64 = 0;
	// mr r24,r11
	r24.u64 = r11.u64;
loc_8226129C:
	// lbzx r11,r26,r27
	r11.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// beq cr6,0x822612b8
	if (cr6.eq) goto loc_822612B8;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x822612bc
	goto loc_822612BC;
loc_822612B8:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_822612BC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822612f8
	if (cr6.eq) goto loc_822612F8;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822612f0
	if (cr6.eq) goto loc_822612F0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822612E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822612f8
	if (cr6.eq) goto loc_822612F8;
loc_822612F0:
	// li r11,1
	r11.s64 = 1;
	// b 0x822612fc
	goto loc_822612FC;
loc_822612F8:
	// li r11,0
	r11.s64 = 0;
loc_822612FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226134c
	if (cr6.eq) goto loc_8226134C;
	// lbz r11,465(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 465);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226134c
	if (!cr6.eq) goto loc_8226134C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82261340;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,84(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	// bl 0x8233e1b0
	ctx.lr = 0x8226134C;
	sub_8233E1B0(ctx, base);
loc_8226134C:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8226129c
	if (!cr0.eq) goto loc_8226129C;
loc_82261358:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82261390
	if (cr6.eq) goto loc_82261390;
	// lis r11,6
	r11.s64 = 393216;
	// ori r10,r11,16985
	ctx.r10.u64 = r11.u64 | 16985;
	// lbzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226138c
	if (cr6.eq) goto loc_8226138C;
	// addis r3,r3,6
	ctx.r3.s64 = ctx.r3.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d95b8
	ctx.lr = 0x82261388;
	sub_826D95B8(ctx, base);
	// b 0x82261390
	goto loc_82261390;
loc_8226138C:
	// bl 0x826d8b48
	ctx.lr = 0x82261390;
	sub_826D8B48(ctx, base);
loc_82261390:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lwz r11,17120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17120);
	// lwz r4,-23452(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -23452);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// bl 0x8229e990
	ctx.lr = 0x822613A8;
	sub_8229E990(ctx, base);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x822b6130
	ctx.lr = 0x822613B0;
	sub_822B6130(ctx, base);
	// lwz r3,-4964(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -4964);
	// bl 0x827291d0
	ctx.lr = 0x822613B8;
	sub_827291D0(ctx, base);
	// bl 0x822e9368
	ctx.lr = 0x822613BC;
	sub_822E9368(ctx, base);
	// lwz r3,-23452(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23452);
	// bl 0x8256f040
	ctx.lr = 0x822613C4;
	sub_8256F040(ctx, base);
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// bl 0x82587f20
	ctx.lr = 0x822613CC;
	sub_82587F20(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,19620(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19620);
	// lwz r3,752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// bl 0x82477a30
	ctx.lr = 0x822613DC;
	sub_82477A30(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822613E4"))) PPC_WEAK_FUNC(sub_822613E4);
PPC_FUNC_IMPL(__imp__sub_822613E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822613E8"))) PPC_WEAK_FUNC(sub_822613E8);
PPC_FUNC_IMPL(__imp__sub_822613E8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bcdc8
	ctx.lr = 0x82261410;
	sub_823BCDC8(ctx, base);
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82261430
	if (cr6.eq) goto loc_82261430;
	// addi r3,r11,2192
	ctx.r3.s64 = r11.s64 + 2192;
	// ld r4,1880(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 1880);
	// bl 0x821ce288
	ctx.lr = 0x8226142C;
	sub_821CE288(ctx, base);
	// b 0x82261444
	goto loc_82261444;
loc_82261430:
	// addi r9,r11,2192
	ctx.r9.s64 = r11.s64 + 2192;
	// lwz r10,2192(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2192);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rldimi r8,r10,32,0
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r8.u64 & 0xFFFFFFFF);
	// std r8,1880(r31)
	PPC_STORE_U64(r31.u32 + 1880, ctx.r8.u64);
loc_82261444:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lwz r11,17120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17120);
	// lwz r4,-23452(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23452);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// bl 0x8229e8f0
	ctx.lr = 0x8226145C;
	sub_8229E8F0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,17892(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17892);
	// bl 0x822b60b0
	ctx.lr = 0x82261468;
	sub_822B60B0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,-4964(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4964);
	// bl 0x827290e8
	ctx.lr = 0x82261474;
	sub_827290E8(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,-4960(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4960);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82261488
	if (cr6.eq) goto loc_82261488;
	// bl 0x823c9968
	ctx.lr = 0x82261488;
	sub_823C9968(ctx, base);
loc_82261488:
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

__attribute__((alias("__imp__sub_822614A0"))) PPC_WEAK_FUNC(sub_822614A0);
PPC_FUNC_IMPL(__imp__sub_822614A0) {
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
	ctx.lr = 0x822614A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// lbzx r11,r28,r27
	r11.u64 = PPC_LOAD_U8(r28.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r11,17892
	r30.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x822614d4
	if (cr6.eq) goto loc_822614D4;
	// lwz r10,804(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x822614d8
	goto loc_822614D8;
loc_822614D4:
	// lwz r10,400(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_822614D8:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82261538
	if (!cr6.gt) goto loc_82261538;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
loc_822614E8:
	// lbzx r10,r28,r27
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r27.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82261500
	if (cr6.eq) goto loc_82261500;
	// add r10,r31,r11
	ctx.r10.u64 = r31.u64 + r11.u64;
	// lwz r3,404(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 404);
	// b 0x82261504
	goto loc_82261504;
loc_82261500:
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
loc_82261504:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226152c
	if (cr6.eq) goto loc_8226152C;
	// lwz r10,660(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 660);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x8226152c
	if (cr6.eq) goto loc_8226152C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_8226152C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822614e8
	if (!cr0.eq) goto loc_822614E8;
loc_82261538:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82261540"))) PPC_WEAK_FUNC(sub_82261540);
PPC_FUNC_IMPL(__imp__sub_82261540) {
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
	ctx.lr = 0x82261548;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r30,80
	ctx.r6.s64 = r30.s64 + 80;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r5,r30,64
	ctx.r5.s64 = r30.s64 + 64;
	// lfs f2,30712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f1,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x82261580;
	sub_822A9930(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lfs f0,104(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 104);
	f0.f64 = double(temp.f32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stfs f0,40(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 40, temp.u32);
	// stfs f0,36(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 36, temp.u32);
	// lwz r4,100(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// bl 0x8232c788
	ctx.lr = 0x8226159C;
	sub_8232C788(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82331d28
	ctx.lr = 0x822615A4;
	sub_82331D28(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822615cc
	if (cr6.eq) goto loc_822615CC;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r29,128(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// bl 0x82342718
	ctx.lr = 0x822615BC;
	sub_82342718(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a5578
	ctx.lr = 0x822615C8;
	sub_822A5578(ctx, base);
	// stfs f31,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
loc_822615CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82331d40
	ctx.lr = 0x822615D4;
	sub_82331D40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822615f0
	if (cr6.eq) goto loc_822615F0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r4,96(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 96);
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3e98
	ctx.lr = 0x822615F0;
	sub_822A3E98(ctx, base);
loc_822615F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822615FC"))) PPC_WEAK_FUNC(sub_822615FC);
PPC_FUNC_IMPL(__imp__sub_822615FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82261600"))) PPC_WEAK_FUNC(sub_82261600);
PPC_FUNC_IMPL(__imp__sub_82261600) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82261608;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82261638
	if (cr6.eq) goto loc_82261638;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x8226163c
	goto loc_8226163C;
loc_82261638:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_8226163C:
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822616dc
	if (!cr6.gt) goto loc_822616DC;
	// mr r30,r24
	r30.u64 = r24.u64;
	// addi r27,r23,16
	r27.s64 = r23.s64 + 16;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82261654:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82261670
	if (cr6.eq) goto loc_82261670;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x82261674
	goto loc_82261674;
loc_82261670:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82261674:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822616b0
	if (cr6.eq) goto loc_822616B0;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822616a8
	if (cr6.eq) goto loc_822616A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226169C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822616b0
	if (cr6.eq) goto loc_822616B0;
loc_822616A8:
	// li r11,1
	r11.s64 = 1;
	// b 0x822616b4
	goto loc_822616B4;
loc_822616B0:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_822616B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822616d0
	if (cr6.eq) goto loc_822616D0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r27,r27,112
	r27.s64 = r27.s64 + 112;
	// bl 0x82260da8
	ctx.lr = 0x822616D0;
	sub_82260DA8(ctx, base);
loc_822616D0:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82261654
	if (!cr0.eq) goto loc_82261654;
loc_822616DC:
	// addi r3,r23,1808
	ctx.r3.s64 = r23.s64 + 1808;
	// bl 0x82260e70
	ctx.lr = 0x822616E4;
	sub_82260E70(ctx, base);
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r9,r23,1896
	ctx.r9.s64 = r23.s64 + 1896;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
loc_822616F0:
	// std r24,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r24.u64);
	// lwz r3,-4964(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4964);
	// lwzx r11,r8,r3
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82261748
	if (cr6.eq) goto loc_82261748;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261748
	if (cr6.eq) goto loc_82261748;
loc_82261714:
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r5,30(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 30);
	// rlwinm r4,r5,0,0,16
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82261734
	if (cr6.eq) goto loc_82261734;
	// ld r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// or r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 | ctx.r6.u64;
	// std r5,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r5.u64);
loc_82261734:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r10,r10,1,62
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82261714
	if (!cr6.eq) goto loc_82261714;
	// lwz r3,-4964(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4964);
loc_82261748:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmpwi cr6,r8,88
	cr6.compare<int32_t>(ctx.r8.s32, 88, xer);
	// blt cr6,0x822616f0
	if (cr6.lt) goto loc_822616F0;
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r23,2216
	ctx.r4.s64 = r23.s64 + 2216;
	// bl 0x827288d8
	ctx.lr = 0x82261764;
	sub_827288D8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8226176C"))) PPC_WEAK_FUNC(sub_8226176C);
PPC_FUNC_IMPL(__imp__sub_8226176C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82261770"))) PPC_WEAK_FUNC(sub_82261770);
PPC_FUNC_IMPL(__imp__sub_82261770) {
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
	ctx.lr = 0x82261778;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x822617a8
	if (cr6.eq) goto loc_822617A8;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x822617ac
	goto loc_822617AC;
loc_822617A8:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_822617AC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82261848
	if (!cr6.gt) goto loc_82261848;
	// li r30,0
	r30.s64 = 0;
	// addi r27,r24,16
	r27.s64 = r24.s64 + 16;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_822617C0:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x822617dc
	if (cr6.eq) goto loc_822617DC;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x822617e0
	goto loc_822617E0;
loc_822617DC:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_822617E0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226181c
	if (cr6.eq) goto loc_8226181C;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82261814
	if (cr6.eq) goto loc_82261814;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226181c
	if (cr6.eq) goto loc_8226181C;
loc_82261814:
	// li r11,1
	r11.s64 = 1;
	// b 0x82261820
	goto loc_82261820;
loc_8226181C:
	// li r11,0
	r11.s64 = 0;
loc_82261820:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226183c
	if (cr6.eq) goto loc_8226183C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r27,r27,112
	r27.s64 = r27.s64 + 112;
	// bl 0x82261540
	ctx.lr = 0x8226183C;
	sub_82261540(ctx, base);
loc_8226183C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x822617c0
	if (!cr0.eq) goto loc_822617C0;
loc_82261848:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82261854;
	sub_822A39C8(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b34b0
	ctx.lr = 0x8226185C;
	sub_822B34B0(ctx, base);
	// addi r3,r24,1808
	ctx.r3.s64 = r24.s64 + 1808;
	// bl 0x82260f20
	ctx.lr = 0x82261864;
	sub_82260F20(ctx, base);
	// li r29,8
	r29.s64 = 8;
	// addi r28,r24,1896
	r28.s64 = r24.s64 + 1896;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_82261870:
	// lwz r11,-4964(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -4964);
	// lwzx r11,r29,r11
	r11.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822618b8
	if (cr6.eq) goto loc_822618B8;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822618b8
	if (cr6.eq) goto loc_822618B8;
loc_82261890:
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// and r10,r11,r30
	ctx.r10.u64 = r11.u64 & r30.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// bne cr6,0x822618a8
	if (!cr6.eq) goto loc_822618A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82728c48
	ctx.lr = 0x822618A8;
	sub_82728C48(ctx, base);
loc_822618A8:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rldicr r30,r30,1,62
	r30.u64 = __builtin_rotateleft64(r30.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82261890
	if (!cr6.eq) goto loc_82261890;
loc_822618B8:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmpwi cr6,r29,88
	cr6.compare<int32_t>(r29.s32, 88, xer);
	// blt cr6,0x82261870
	if (cr6.lt) goto loc_82261870;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,30436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 30436);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822618e8
	if (cr6.eq) goto loc_822618E8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822618E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822618E8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822618fc
	if (cr6.eq) goto loc_822618FC;
	// bl 0x82705918
	ctx.lr = 0x822618FC;
	sub_82705918(ctx, base);
loc_822618FC:
	// bl 0x82680580
	ctx.lr = 0x82261900;
	sub_82680580(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r24,2216
	ctx.r4.s64 = r24.s64 + 2216;
	// lwz r3,-4964(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -4964);
	// bl 0x82728960
	ctx.lr = 0x82261910;
	sub_82728960(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82261918"))) PPC_WEAK_FUNC(sub_82261918);
PPC_FUNC_IMPL(__imp__sub_82261918) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82261920;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82261950
	if (cr6.eq) goto loc_82261950;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82261954
	goto loc_82261954;
loc_82261950:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82261954:
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822619f4
	if (!cr6.gt) goto loc_822619F4;
	// mr r30,r24
	r30.u64 = r24.u64;
	// addi r27,r23,912
	r27.s64 = r23.s64 + 912;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_8226196C:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82261988
	if (cr6.eq) goto loc_82261988;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x8226198c
	goto loc_8226198C;
loc_82261988:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_8226198C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822619c8
	if (cr6.eq) goto loc_822619C8;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822619c0
	if (cr6.eq) goto loc_822619C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822619B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822619c8
	if (cr6.eq) goto loc_822619C8;
loc_822619C0:
	// li r11,1
	r11.s64 = 1;
	// b 0x822619cc
	goto loc_822619CC;
loc_822619C8:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_822619CC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822619e8
	if (cr6.eq) goto loc_822619E8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r27,r27,112
	r27.s64 = r27.s64 + 112;
	// bl 0x82260da8
	ctx.lr = 0x822619E8;
	sub_82260DA8(ctx, base);
loc_822619E8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8226196c
	if (!cr0.eq) goto loc_8226196C;
loc_822619F4:
	// addi r3,r23,1844
	ctx.r3.s64 = r23.s64 + 1844;
	// bl 0x82260e70
	ctx.lr = 0x822619FC;
	sub_82260E70(ctx, base);
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r9,r23,2056
	ctx.r9.s64 = r23.s64 + 2056;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
loc_82261A08:
	// std r24,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r24.u64);
	// lwz r3,-4964(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4964);
	// lwzx r11,r8,r3
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82261a60
	if (cr6.eq) goto loc_82261A60;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261a60
	if (cr6.eq) goto loc_82261A60;
loc_82261A2C:
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r5,30(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 30);
	// rlwinm r4,r5,0,0,16
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82261a4c
	if (cr6.eq) goto loc_82261A4C;
	// ld r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// or r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 | ctx.r6.u64;
	// std r5,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r5.u64);
loc_82261A4C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r10,r10,1,62
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82261a2c
	if (!cr6.eq) goto loc_82261A2C;
	// lwz r3,-4964(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4964);
loc_82261A60:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmpwi cr6,r8,88
	cr6.compare<int32_t>(ctx.r8.s32, 88, xer);
	// blt cr6,0x82261a08
	if (cr6.lt) goto loc_82261A08;
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r23,2376
	ctx.r4.s64 = r23.s64 + 2376;
	// bl 0x827288d8
	ctx.lr = 0x82261A7C;
	sub_827288D8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82261A84"))) PPC_WEAK_FUNC(sub_82261A84);
PPC_FUNC_IMPL(__imp__sub_82261A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82261A88"))) PPC_WEAK_FUNC(sub_82261A88);
PPC_FUNC_IMPL(__imp__sub_82261A88) {
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
	ctx.lr = 0x82261A90;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82261ac0
	if (cr6.eq) goto loc_82261AC0;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82261ac4
	goto loc_82261AC4;
loc_82261AC0:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82261AC4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82261b60
	if (!cr6.gt) goto loc_82261B60;
	// li r30,0
	r30.s64 = 0;
	// addi r27,r24,912
	r27.s64 = r24.s64 + 912;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82261AD8:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82261af4
	if (cr6.eq) goto loc_82261AF4;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x82261af8
	goto loc_82261AF8;
loc_82261AF4:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82261AF8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82261b34
	if (cr6.eq) goto loc_82261B34;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82261b2c
	if (cr6.eq) goto loc_82261B2C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261b34
	if (cr6.eq) goto loc_82261B34;
loc_82261B2C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82261b38
	goto loc_82261B38;
loc_82261B34:
	// li r11,0
	r11.s64 = 0;
loc_82261B38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261b54
	if (cr6.eq) goto loc_82261B54;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r27,r27,112
	r27.s64 = r27.s64 + 112;
	// bl 0x82261540
	ctx.lr = 0x82261B54;
	sub_82261540(ctx, base);
loc_82261B54:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82261ad8
	if (!cr0.eq) goto loc_82261AD8;
loc_82261B60:
	// addi r3,r24,1844
	ctx.r3.s64 = r24.s64 + 1844;
	// bl 0x82260f20
	ctx.lr = 0x82261B68;
	sub_82260F20(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// li r29,8
	r29.s64 = 8;
	// addi r28,r24,2056
	r28.s64 = r24.s64 + 2056;
	// lwz r3,-4964(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -4964);
loc_82261B78:
	// lwzx r11,r29,r3
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82261bd4
	if (cr6.eq) goto loc_82261BD4;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82261bd4
	if (cr6.eq) goto loc_82261BD4;
loc_82261B94:
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// and r10,r30,r11
	ctx.r10.u64 = r30.u64 & r11.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// bne cr6,0x82261bc0
	if (!cr6.eq) goto loc_82261BC0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r10,30(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 30);
	// rlwinm r9,r10,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261bc0
	if (cr6.eq) goto loc_82261BC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82728c48
	ctx.lr = 0x82261BC0;
	sub_82728C48(ctx, base);
loc_82261BC0:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rldicr r30,r30,1,62
	r30.u64 = __builtin_rotateleft64(r30.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82261b94
	if (!cr6.eq) goto loc_82261B94;
	// lwz r3,-4964(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -4964);
loc_82261BD4:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmpwi cr6,r29,88
	cr6.compare<int32_t>(r29.s32, 88, xer);
	// blt cr6,0x82261b78
	if (cr6.lt) goto loc_82261B78;
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r24,2376
	ctx.r4.s64 = r24.s64 + 2376;
	// bl 0x82728960
	ctx.lr = 0x82261BF0;
	sub_82728960(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82261BF8"))) PPC_WEAK_FUNC(sub_82261BF8);
PPC_FUNC_IMPL(__imp__sub_82261BF8) {
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
	ctx.lr = 0x82261C00;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,2620(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82261c28
	if (!cr6.eq) goto loc_82261C28;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261c40
	if (cr6.eq) goto loc_82261C40;
loc_82261C28:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261C40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82261C40:
	// bl 0x822614a0
	ctx.lr = 0x82261C44;
	sub_822614A0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r29,-12348(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 76);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261c64
	if (cr6.eq) goto loc_82261C64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391628
	ctx.lr = 0x82261C64;
	sub_82391628(ctx, base);
loc_82261C64:
	// lbz r11,76(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 76);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82261c7c
	if (cr6.eq) goto loc_82261C7C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391688
	ctx.lr = 0x82261C7C;
	sub_82391688(ctx, base);
loc_82261C7C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261df4
	if (cr6.eq) goto loc_82261DF4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r10,r11,-5004
	ctx.r10.s64 = r11.s64 + -5004;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261cac
	if (cr6.eq) goto loc_82261CAC;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// b 0x82261cb0
	goto loc_82261CB0;
loc_82261CAC:
	// li r11,0
	r11.s64 = 0;
loc_82261CB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261e08
	if (cr6.eq) goto loc_82261E08;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82261e08
	if (cr6.eq) goto loc_82261E08;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-4180
	ctx.r5.s64 = r11.s64 + -4180;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82261CE0;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82261e08
	if (cr6.eq) goto loc_82261E08;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,1888
	ctx.r4.s64 = r30.s64 + 1888;
	// bl 0x821be710
	ctx.lr = 0x82261CF8;
	sub_821BE710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82261D00;
	sub_821BE4F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lbz r10,2620(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// clrlwi r8,r10,25
	ctx.r8.u64 = ctx.r10.u32 & 0x7F;
	// rlwinm r7,r9,2,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x80;
	// xori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 ^ 128;
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// stb r5,2620(r30)
	PPC_STORE_U8(r30.u32 + 2620, ctx.r5.u8);
	// bl 0x821be4f0
	ctx.lr = 0x82261D28;
	sub_821BE4F0(ctx, base);
	// cntlzw r4,r3
	ctx.r4.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lbz r11,2620(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// li r5,2
	ctx.r5.s64 = 2;
	// rlwinm r10,r4,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// addi r4,r30,1880
	ctx.r4.s64 = r30.s64 + 1880;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwimi r11,r9,5,26,26
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x20) | (r11.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r11,2620(r30)
	PPC_STORE_U8(r30.u32 + 2620, r11.u8);
	// bl 0x821be710
	ctx.lr = 0x82261D50;
	sub_821BE710(ctx, base);
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82261D60;
	sub_821BE250(ctx, base);
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r4,r30,912
	ctx.r4.s64 = r30.s64 + 912;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82261D70;
	sub_821BE250(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r4,r30,1808
	ctx.r4.s64 = r30.s64 + 1808;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82261D80;
	sub_821BE250(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r4,r30,1844
	ctx.r4.s64 = r30.s64 + 1844;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82261D90;
	sub_821BE250(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r30,1896
	ctx.r4.s64 = r30.s64 + 1896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DA0;
	sub_821BE710(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r30,2056
	ctx.r4.s64 = r30.s64 + 2056;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DB0;
	sub_821BE710(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r30,2216
	ctx.r4.s64 = r30.s64 + 2216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DC0;
	sub_821BE710(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r30,2376
	ctx.r4.s64 = r30.s64 + 2376;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DD0;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,2616
	ctx.r4.s64 = r30.s64 + 2616;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DE0;
	sub_821BE710(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391568
	ctx.lr = 0x82261DEC;
	sub_82391568(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82261DF4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261E08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82261E08:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82261E10"))) PPC_WEAK_FUNC(sub_82261E10);
PPC_FUNC_IMPL(__imp__sub_82261E10) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82261E18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r3,-12348(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// li r4,20
	ctx.r4.s64 = 20;
	// stw r27,1892(r31)
	PPC_STORE_U32(r31.u32 + 1892, r27.u32);
	// beq cr6,0x82261f38
	if (cr6.eq) goto loc_82261F38;
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// li r12,163
	r12.s64 = 163;
	// and r10,r11,r12
	ctx.r10.u64 = r11.u64 & r12.u64;
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r9.u8);
	// bl 0x82390eb0
	ctx.lr = 0x82261E58;
	sub_82390EB0(ctx, base);
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lbzx r8,r25,r26
	ctx.r8.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82261e80
	if (cr6.eq) goto loc_82261E80;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82261e84
	goto loc_82261E84;
loc_82261E80:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82261E84:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82261f50
	if (!cr6.gt) goto loc_82261F50;
	// mr r30,r27
	r30.u64 = r27.u64;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82261E94:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82261eb0
	if (cr6.eq) goto loc_82261EB0;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x82261eb4
	goto loc_82261EB4;
loc_82261EB0:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82261EB4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82261ef0
	if (cr6.eq) goto loc_82261EF0;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82261ee8
	if (cr6.eq) goto loc_82261EE8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261EDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261ef0
	if (cr6.eq) goto loc_82261EF0;
loc_82261EE8:
	// li r11,1
	r11.s64 = 1;
	// b 0x82261ef4
	goto loc_82261EF4;
loc_82261EF0:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82261EF4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261f24
	if (cr6.eq) goto loc_82261F24;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82261f24
	if (cr6.eq) goto loc_82261F24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261F24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82261F24:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82261e94
	if (!cr0.eq) goto loc_82261E94;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82261F38:
	// stw r27,1888(r31)
	PPC_STORE_U32(r31.u32 + 1888, r27.u32);
	// bl 0x82390e08
	ctx.lr = 0x82261F40;
	sub_82390E08(ctx, base);
	// lbz r10,2620(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// li r11,1
	r11.s64 = 1;
	// rlwimi r10,r11,4,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stb r10,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r10.u8);
loc_82261F50:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82261F58"))) PPC_WEAK_FUNC(sub_82261F58);
PPC_FUNC_IMPL(__imp__sub_82261F58) {
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
	ctx.lr = 0x82261F60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x822614a0
	ctx.lr = 0x82261F70;
	sub_822614A0(ctx, base);
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82262040
	if (cr6.eq) goto loc_82262040;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// rlwinm r9,r9,0,29,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stb r9,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r9.u8);
	// lwz r3,-12348(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r8,76(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// rlwinm r7,r8,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// bl 0x82391688
	ctx.lr = 0x82261FA8;
	sub_82391688(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82262010
	if (cr6.eq) goto loc_82262010;
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82261fd4
	if (!cr6.eq) goto loc_82261FD4;
	// lwz r11,1892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1892);
	// lwz r10,1888(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1888);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82262010
	if (!cr6.lt) goto loc_82262010;
loc_82261FD4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261FE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,-12640(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12640);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82262004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,1888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1888);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,1892(r31)
	PPC_STORE_U32(r31.u32 + 1892, ctx.r6.u32);
loc_82262010:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8226201C;
	sub_822A39C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a5578
	ctx.lr = 0x82262024;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x82262034;
	sub_822A5578(ctx, base);
	// bl 0x822a2370
	ctx.lr = 0x82262038;
	sub_822A2370(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82262040:
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r9,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r9.u8);
	// lwz r29,-12348(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 76);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391628
	ctx.lr = 0x82262078;
	sub_82391628(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226208C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r8,r9,-4984
	ctx.r8.s64 = ctx.r9.s64 + -4984;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822620b0
	if (cr6.eq) goto loc_822620B0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// b 0x822620b4
	goto loc_822620B4;
loc_822620B0:
	// li r11,0
	r11.s64 = 0;
loc_822620B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-4180
	ctx.r5.s64 = r11.s64 + -4180;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca720
	ctx.lr = 0x822620E0;
	sub_821CA720(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,1888
	ctx.r4.s64 = r31.s64 + 1888;
	// bl 0x821be7e8
	ctx.lr = 0x822620F8;
	sub_821BE7E8(ctx, base);
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r4,r11,25,7,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// bl 0x821be528
	ctx.lr = 0x82262108;
	sub_821BE528(ctx, base);
	// lbz r10,2620(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821be528
	ctx.lr = 0x82262118;
	sub_821BE528(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,1880
	ctx.r4.s64 = r31.s64 + 1880;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x82262128;
	sub_821BE7E8(ctx, base);
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be3d8
	ctx.lr = 0x82262138;
	sub_821BE3D8(ctx, base);
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r4,r31,912
	ctx.r4.s64 = r31.s64 + 912;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be3d8
	ctx.lr = 0x82262148;
	sub_821BE3D8(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r4,r31,1808
	ctx.r4.s64 = r31.s64 + 1808;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be3d8
	ctx.lr = 0x82262158;
	sub_821BE3D8(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r4,r31,1844
	ctx.r4.s64 = r31.s64 + 1844;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be3d8
	ctx.lr = 0x82262168;
	sub_821BE3D8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r31,1896
	ctx.r4.s64 = r31.s64 + 1896;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x82262178;
	sub_821BE7E8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r31,2056
	ctx.r4.s64 = r31.s64 + 2056;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x82262188;
	sub_821BE7E8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r31,2216
	ctx.r4.s64 = r31.s64 + 2216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x82262198;
	sub_821BE7E8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r31,2376
	ctx.r4.s64 = r31.s64 + 2376;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x822621A8;
	sub_821BE7E8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,2616
	ctx.r4.s64 = r31.s64 + 2616;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x822621B8;
	sub_821BE7E8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391500
	ctx.lr = 0x822621C4;
	sub_82391500(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x822621CC;
	sub_821BE610(ctx, base);
loc_822621CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822621D4"))) PPC_WEAK_FUNC(sub_822621D4);
PPC_FUNC_IMPL(__imp__sub_822621D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822621D8"))) PPC_WEAK_FUNC(sub_822621D8);
PPC_FUNC_IMPL(__imp__sub_822621D8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822621E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,72
	r26.s64 = 72;
	// li r27,0
	r27.s64 = 0;
	// lbzx r11,r26,r25
	r11.u64 = PPC_LOAD_U8(r26.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82262210
	if (cr6.eq) goto loc_82262210;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82262214
	goto loc_82262214;
loc_82262210:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82262214:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822622e4
	if (!cr6.gt) goto loc_822622E4;
	// li r30,0
	r30.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82262224:
	// lbzx r11,r26,r25
	r11.u64 = PPC_LOAD_U8(r26.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82262240
	if (cr6.eq) goto loc_82262240;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x82262244
	goto loc_82262244;
loc_82262240:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82262244:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82262280
	if (cr6.eq) goto loc_82262280;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82262278
	if (cr6.eq) goto loc_82262278;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226226C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82262280
	if (cr6.eq) goto loc_82262280;
loc_82262278:
	// li r11,1
	r11.s64 = 1;
	// b 0x82262284
	goto loc_82262284;
loc_82262280:
	// li r11,0
	r11.s64 = 0;
loc_82262284:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822622d8
	if (cr6.eq) goto loc_822622D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82262298;
	sub_822A8108(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x822a8108
	ctx.lr = 0x822622A8;
	sub_822A8108(ctx, base);
	// lfs f13,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x822a8108
	ctx.lr = 0x822622B8;
	sub_822A8108(ctx, base);
	// lfs f12,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// xor r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 ^ r11.u64;
	// xor r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// xor r27,r7,r27
	r27.u64 = ctx.r7.u64 ^ r27.u64;
loc_822622D8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82262224
	if (!cr0.eq) goto loc_82262224;
loc_822622E4:
	// clrlwi r3,r27,31
	ctx.r3.u64 = r27.u32 & 0x1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822622F0"))) PPC_WEAK_FUNC(sub_822622F0);
PPC_FUNC_IMPL(__imp__sub_822622F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,-5008(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5008);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// lwz r11,16(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82262320"))) PPC_WEAK_FUNC(sub_82262320);
PPC_FUNC_IMPL(__imp__sub_82262320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lbz r9,2620(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2620);
	// rlwinm r8,r9,26,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226233C"))) PPC_WEAK_FUNC(sub_8226233C);
PPC_FUNC_IMPL(__imp__sub_8226233C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82262340"))) PPC_WEAK_FUNC(sub_82262340);
PPC_FUNC_IMPL(__imp__sub_82262340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lbz r10,2620(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2620);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82262370
	if (!cr6.eq) goto loc_82262370;
	// lwz r10,1888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1888);
	// lwz r11,1892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1892);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82262374
	if (!cr6.lt) goto loc_82262374;
loc_82262370:
	// li r11,0
	r11.s64 = 0;
loc_82262374:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82262384"))) PPC_WEAK_FUNC(sub_82262384);
PPC_FUNC_IMPL(__imp__sub_82262384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82262388"))) PPC_WEAK_FUNC(sub_82262388);
PPC_FUNC_IMPL(__imp__sub_82262388) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82262398:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82262398
	if (cr6.eq) goto loc_82262398;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lwz r3,-5008(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5008);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822623C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822623C4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822623c4
	if (cr6.eq) goto loc_822623C4;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822623E8"))) PPC_WEAK_FUNC(sub_822623E8);
PPC_FUNC_IMPL(__imp__sub_822623E8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,-12348(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82390f38
	ctx.lr = 0x82262410;
	sub_82390F38(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82262434
	if (!cr6.eq) goto loc_82262434;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82262434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82262434:
	// lbz r11,76(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226247c
	if (cr6.eq) goto loc_8226247C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822621d8
	ctx.lr = 0x8226244C;
	sub_822621D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82262468
	if (cr6.eq) goto loc_82262468;
	// lbz r11,52(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 52);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stb r10,52(r31)
	PPC_STORE_U8(r31.u32 + 52, ctx.r10.u8);
	// b 0x822624b0
	goto loc_822624B0;
loc_82262468:
	// lbz r11,52(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 52);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stb r10,52(r31)
	PPC_STORE_U8(r31.u32 + 52, ctx.r10.u8);
	// b 0x822624b0
	goto loc_822624B0;
loc_8226247C:
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822624b0
	if (cr6.eq) goto loc_822624B0;
	// lbz r11,52(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 52);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r31,r11,30,31,31
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// bl 0x822621d8
	ctx.lr = 0x82262498;
	sub_822621D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// beq cr6,0x822624b0
	if (cr6.eq) goto loc_822624B0;
	// lbz r11,2620(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stb r10,2620(r30)
	PPC_STORE_U8(r30.u32 + 2620, ctx.r10.u8);
loc_822624B0:
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

__attribute__((alias("__imp__sub_822624C8"))) PPC_WEAK_FUNC(sub_822624C8);
PPC_FUNC_IMPL(__imp__sub_822624C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x82262388
	sub_82262388(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822624E4"))) PPC_WEAK_FUNC(sub_822624E4);
PPC_FUNC_IMPL(__imp__sub_822624E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822624E8"))) PPC_WEAK_FUNC(sub_822624E8);
PPC_FUNC_IMPL(__imp__sub_822624E8) {
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
	// addi r4,r11,9416
	ctx.r4.s64 = r11.s64 + 9416;
	// addi r3,r10,-9672
	ctx.r3.s64 = ctx.r10.s64 + -9672;
	// bl 0x82554798
	ctx.lr = 0x82262508;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,8944
	ctx.r4.s64 = ctx.r9.s64 + 8944;
	// addi r3,r8,-9688
	ctx.r3.s64 = ctx.r8.s64 + -9688;
	// bl 0x82554798
	ctx.lr = 0x8226251C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,4216
	ctx.r4.s64 = ctx.r7.s64 + 4216;
	// addi r3,r6,-9716
	ctx.r3.s64 = ctx.r6.s64 + -9716;
	// bl 0x82554798
	ctx.lr = 0x82262530;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,8992
	ctx.r4.s64 = ctx.r5.s64 + 8992;
	// addi r3,r3,-9744
	ctx.r3.s64 = ctx.r3.s64 + -9744;
	// bl 0x82554798
	ctx.lr = 0x82262544;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,9024
	ctx.r4.s64 = r11.s64 + 9024;
	// addi r3,r10,-9780
	ctx.r3.s64 = ctx.r10.s64 + -9780;
	// bl 0x82554798
	ctx.lr = 0x82262558;
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

__attribute__((alias("__imp__sub_82262568"))) PPC_WEAK_FUNC(sub_82262568);
PPC_FUNC_IMPL(__imp__sub_82262568) {
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
	// bl 0x821c8ed8
	ctx.lr = 0x82262580;
	sub_821C8ED8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f0,12428(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	f0.f64 = double(temp.f32);
	// lfs f13,31296(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31296);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// lfs f12,15004(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15004);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// lfs f11,-9332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -9332);
	ctx.f11.f64 = double(temp.f32);
	// stw r6,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r6.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stfs f13,80(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stfs f12,84(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stfs f11,88(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// addi r10,r31,60
	ctx.r10.s64 = r31.s64 + 60;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
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

__attribute__((alias("__imp__sub_82262600"))) PPC_WEAK_FUNC(sub_82262600);
PPC_FUNC_IMPL(__imp__sub_82262600) {
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
	ctx.lr = 0x82262608;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x8226261C;
	sub_82180430(ctx, base);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r8,2
	ctx.r8.s64 = 2;
	// stb r11,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r11.u8);
	// stb r10,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// addi r4,r7,-9180
	ctx.r4.s64 = ctx.r7.s64 + -9180;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,128
	ctx.r7.s64 = 128;
	// li r6,128
	ctx.r6.s64 = 128;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226266C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-9192
	ctx.r4.s64 = ctx.r8.s64 + -9192;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r6,128
	ctx.r6.s64 = 128;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// li r7,128
	ctx.r7.s64 = 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822626A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// addi r29,r9,30576
	r29.s64 = ctx.r9.s64 + 30576;
	// addi r4,r8,-9216
	ctx.r4.s64 = ctx.r8.s64 + -9216;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
	// bl 0x821ca540
	ctx.lr = 0x822626C8;
	sub_821CA540(ctx, base);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-9244
	ctx.r4.s64 = ctx.r7.s64 + -9244;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822626E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-9272
	ctx.r4.s64 = ctx.r10.s64 + -9272;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8226270C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-9300
	ctx.r4.s64 = ctx.r7.s64 + -9300;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82262730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-9328
	ctx.r4.s64 = ctx.r10.s64 + -9328;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82262754;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82262760;
	sub_821C9A90(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82262768"))) PPC_WEAK_FUNC(sub_82262768);
PPC_FUNC_IMPL(__imp__sub_82262768) {
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
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x82262780;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262790
	if (cr6.eq) goto loc_82262790;
	// bl 0x82262568
	ctx.lr = 0x8226278C;
	sub_82262568(ctx, base);
	// b 0x82262794
	goto loc_82262794;
loc_82262790:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82262794:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,-4944
	r31.s64 = r11.s64 + -4944;
	// stw r3,-4944(r11)
	PPC_STORE_U32(r11.u32 + -4944, ctx.r3.u32);
	// bl 0x82262600
	ctx.lr = 0x822627A4;
	sub_82262600(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
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

__attribute__((alias("__imp__sub_822627BC"))) PPC_WEAK_FUNC(sub_822627BC);
PPC_FUNC_IMPL(__imp__sub_822627BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822627C0"))) PPC_WEAK_FUNC(sub_822627C0);
PPC_FUNC_IMPL(__imp__sub_822627C0) {
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
	ctx.lr = 0x822627C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x822627E4;
	sub_821C8FE0(ctx, base);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mulli r11,r30,368
	r11.s64 = r30.s64 * 368;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82264c90
	ctx.lr = 0x822627FC;
	sub_82264C90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82262804;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226280C"))) PPC_WEAK_FUNC(sub_8226280C);
PPC_FUNC_IMPL(__imp__sub_8226280C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82262810"))) PPC_WEAK_FUNC(sub_82262810);
PPC_FUNC_IMPL(__imp__sub_82262810) {
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
	ctx.lr = 0x82262818;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82262830;
	sub_821C8FE0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r31,32(r28)
	PPC_STORE_U32(r28.u32 + 32, r31.u32);
	// beq cr6,0x82262888
	if (cr6.eq) goto loc_82262888;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82262888
	if (cr6.eq) goto loc_82262888;
	// li r30,0
	r30.s64 = 0;
loc_82262850:
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82265fe0
	ctx.lr = 0x82262864;
	sub_82265FE0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82264fd0
	ctx.lr = 0x82262870;
	sub_82264FD0(ctx, base);
	// lwz r10,32(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82262850
	if (cr6.lt) goto loc_82262850;
loc_82262888:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82262890;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82262898"))) PPC_WEAK_FUNC(sub_82262898);
PPC_FUNC_IMPL(__imp__sub_82262898) {
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
	ctx.lr = 0x822628A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r29,36(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822628f4
	if (cr6.eq) goto loc_822628F4;
loc_822628B4:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822628e8
	if (cr6.eq) goto loc_822628E8;
	// li r31,0
	r31.s64 = 0;
loc_822628C8:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82266dd0
	ctx.lr = 0x822628D4;
	sub_82266DD0(ctx, base);
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,368
	r31.s64 = r31.s64 + 368;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822628c8
	if (cr6.lt) goto loc_822628C8;
loc_822628E8:
	// lwz r29,0(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x822628b4
	if (!cr6.eq) goto loc_822628B4;
loc_822628F4:
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82262948
	if (!cr6.eq) goto loc_82262948;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,-12556(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12556);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,-12572(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12572);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	f0.f64 = double(temp.f32);
	// fnmsubs f12,f0,f13,f12
	ctx.f12.f64 = double(float(-(f0.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// lfs f13,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsel f11,f12,f12,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f0,f10,f0,f11
	f0.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// stfs f0,-12556(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12556, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82262948:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,-12556(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12556, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226295C"))) PPC_WEAK_FUNC(sub_8226295C);
PPC_FUNC_IMPL(__imp__sub_8226295C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82262960"))) PPC_WEAK_FUNC(sub_82262960);
PPC_FUNC_IMPL(__imp__sub_82262960) {
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
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82262968;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9a4
	ctx.lr = 0x82262970;
	// addi r12,r1,-288
	r12.s64 = ctx.r1.s64 + -288;
	// bl 0x823dd524
	ctx.lr = 0x82262978;
	// stwu r1,-1728(r1)
	ea = -1728 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8226298C;
	sub_821C8FE0(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r10,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r10.u32);
	// beq cr6,0x82263108
	if (cr6.eq) goto loc_82263108;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-4920(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4920);
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822629dc
	if (!cr6.eq) goto loc_822629DC;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r11,-4920(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4920, r11.u32);
loc_822629C8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822629c8
	if (cr6.eq) goto loc_822629C8;
	// std r11,-4928(r9)
	PPC_STORE_U64(ctx.r9.u32 + -4928, r11.u64);
loc_822629DC:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822629dc
	if (cr6.eq) goto loc_822629DC;
	// ld r10,-4928(r9)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r9.u32 + -4928);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r24,0
	r24.s64 = 0;
	// subf r7,r10,r11
	ctx.r7.s64 = r11.s64 - ctx.r10.s64;
	// std r7,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,-9360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -9360);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lhz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// fmuls f15,f12,f0
	f15.f64 = double(float(ctx.f12.f64 * f0.f64));
	// blt cr6,0x82262b50
	if (cr6.lt) goto loc_82262B50;
	// addic. r6,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r6.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// beq 0x82262a70
	if (cr0.eq) goto loc_82262A70;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r10,r11,200
	ctx.r10.s64 = r11.s64 + 200;
loc_82262A38:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82262a50
	if (cr6.eq) goto loc_82262A50;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne cr6,0x82262a54
	if (!cr6.eq) goto loc_82262A54;
loc_82262A50:
	// li r11,1
	r11.s64 = 1;
loc_82262A54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82262a70
	if (!cr6.eq) goto loc_82262A70;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bne cr6,0x82262a38
	if (!cr6.eq) goto loc_82262A38;
loc_82262A70:
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mulli r11,r7,368
	r11.s64 = ctx.r7.s64 * 368;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r5,112
	ctx.r5.s64 = 112;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r4,144
	ctx.r4.s64 = 144;
	// lbz r9,331(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 331);
	// lvx128 v122,r11,r5
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82262aa0
	if (cr6.eq) goto loc_82262AA0;
	// lvx128 v123,r11,r4
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82262ad0
	goto loc_82262AD0;
loc_82262AA0:
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// twllei r8,0
	// divw r3,r9,r8
	ctx.r3.s32 = ctx.r9.s32 / ctx.r8.s32;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r3,r3,r8
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// mulli r11,r9,368
	r11.s64 = ctx.r9.s64 * 368;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// andc r9,r8,r3
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r3.u64;
	// twlgei r9,-1
	// lvx128 v123,r11,r6
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82262AD0:
	// addic. r9,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r9.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge 0x82262adc
	if (!cr0.lt) goto loc_82262ADC;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
loc_82262ADC:
	// mulli r11,r9,368
	r11.s64 = ctx.r9.s64 * 368;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r3,331(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 331);
	// lvx128 v124,r11,r5
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262afc
	if (cr6.eq) goto loc_82262AFC;
	// lvx128 v125,r11,r4
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82262b2c
	goto loc_82262B2C;
loc_82262AFC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// twllei r8,0
	// divw r5,r9,r8
	ctx.r5.s32 = ctx.r9.s32 / ctx.r8.s32;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r4,r5,r8
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// subf r3,r4,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r4.s64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// mulli r11,r3,368
	r11.s64 = ctx.r3.s64 * 368;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// andc r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// twlgei r4,-1
	// lvx128 v125,r5,r6
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82262B2C:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// beq cr6,0x82262b70
	if (cr6.eq) goto loc_82262B70;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// stw r7,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r7.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
	// b 0x82262b70
	goto loc_82262B70;
loc_82262B50:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v122,r0,r11
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v124,r0,r10
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v123,r0,r9
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r0,r8
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82262B70:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// lwz r30,-26876(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// bl 0x82189e20
	ctx.lr = 0x82262B8C;
	sub_82189E20(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82189e20
	ctx.lr = 0x82262B98;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x82262BA4;
	sub_8217F768(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r11,17320(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82262bbc
	if (!cr6.lt) goto loc_82262BBC;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_82262BBC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x82262BC4;
	sub_8217F768(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r11,r30,112
	r11.s64 = r30.s64 + 112;
	// lfs f27,-28964(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28964);
	f27.f64 = double(temp.f32);
	// lfs f28,-9152(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -9152);
	f28.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f29,-9156(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -9156);
	f29.f64 = double(temp.f32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// lfs f21,-12084(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -12084);
	f21.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f22,-15468(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -15468);
	f22.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f16,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f16.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lfs f26,-9160(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9160);
	f26.f64 = double(temp.f32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lfs f17,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	f17.f64 = double(temp.f32);
	// lfs f18,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f18.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f30,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f23,-9164(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -9164);
	f23.f64 = double(temp.f32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lfs f19,-9168(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -9168);
	f19.f64 = double(temp.f32);
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lfs f20,-31376(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -31376);
	f20.f64 = double(temp.f32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r20,-256
	r20.s64 = -16777216;
	// mr r23,r24
	r23.u64 = r24.u64;
	// li r19,-1
	r19.s64 = -1;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// lis r25,-32124
	r25.s64 = -2105278464;
	// lis r22,-32124
	r22.s64 = -2105278464;
	// addi r18,r11,-31664
	r18.s64 = r11.s64 + -31664;
	// addi r17,r10,-31648
	r17.s64 = ctx.r10.s64 + -31648;
	// addi r16,r9,2240
	r16.s64 = ctx.r9.s64 + 2240;
	// addi r15,r8,2528
	r15.s64 = ctx.r8.s64 + 2528;
	// addi r14,r7,29952
	r14.s64 = ctx.r7.s64 + 29952;
	// addi r21,r6,-31280
	r21.s64 = ctx.r6.s64 + -31280;
loc_82262C94:
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// vor128 v127,v122,v122
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)v122.u8));
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// vor128 v126,v123,v123
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// bne cr6,0x82262cb4
	if (!cr6.eq) goto loc_82262CB4;
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// vor128 v127,v124,v124
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// vor128 v126,v125,v125
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
loc_82262CB4:
	// lwz r3,-25232(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -25232);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82262CE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82178370
	ctx.lr = 0x82262CFC;
	sub_82178370(ctx, base);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x8217d5e8
	ctx.lr = 0x82262D04;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// lfs f1,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// fmr f4,f17
	ctx.f4.f64 = f17.f64;
	// fmr f3,f18
	ctx.f3.f64 = f18.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8217d460
	ctx.lr = 0x82262D1C;
	sub_8217D460(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x8217c658
	ctx.lr = 0x82262D28;
	sub_8217C658(ctx, base);
	// stfs f30,224(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stfs f31,232(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stfs f31,240(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f30,244(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f31,248(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f31,256(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lwz r3,-26876(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// stfs f31,260(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f30,264(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f31,272(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f31,276(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f16,280(r1)
	temp.f32 = float(f16.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// bl 0x8217ce80
	ctx.lr = 0x82262D68;
	sub_8217CE80(ctx, base);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// lvx128 v62,r21,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lvx128 v61,r21,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r21,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82256058
	ctx.lr = 0x82262DA8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262df4
	if (cr6.eq) goto loc_82262DF4;
	// bl 0x82256058
	ctx.lr = 0x82262DB4;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82262df4
	if (!cr6.eq) goto loc_82262DF4;
	// lfs f0,24(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 24);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f20
	ctx.f1.f64 = double(float(f0.f64 * f20.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82262DCC;
	sub_823DBAE8(ctx, base);
	// lfs f0,24(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 24);
	f0.f64 = double(temp.f32);
	// frsp f25,f1
	f25.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f0,f20
	ctx.f1.f64 = double(float(f0.f64 * f20.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x82262DDC;
	sub_823DBBC8(ctx, base);
	// lvx128 v61,r0,r15
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lvx128 v62,r0,r16
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r17
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r18
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82262e50
	goto loc_82262E50;
loc_82262DF4:
	// vsubfp128 v63,v126,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// lvx128 v61,r0,r15
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r16
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// vor128 v0,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lvx128 v60,r0,r17
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r18
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// vmsum3fp128 v59,v63,v63
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v58,v59
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vcmpeqfp128 v11,v58,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v57,v63,v6
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,200(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	f0.f64 = double(temp.f32);
	// lfs f25,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	f25.f64 = double(temp.f32);
loc_82262E50:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// vor128 v0,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v56,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v127.f32)));
	// vmsum3fp128 v55,v63,v63
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v54,v55
	simde_mm_store_ps(v54.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v55.f32))));
	// vor128 v12,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vcmpeqfp128 v11,v54,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v53,v63,v6
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f25
	ctx.f11.f64 = double(float(ctx.f13.f64 * f25.f64));
	// fmuls f10,f12,f25
	ctx.f10.f64 = double(float(ctx.f12.f64 * f25.f64));
	// fmadds f25,f12,f0,f11
	f25.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f11.f64));
	// fmsubs f1,f13,f0,f10
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64 - ctx.f10.f64));
	// fmr f2,f25
	ctx.f2.f64 = f25.f64;
	// bl 0x823dcdd8
	ctx.lr = 0x82262EBC;
	sub_823DCDD8(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// fsubs f24,f19,f9
	f24.f64 = double(float(f19.f64 - ctx.f9.f64));
	// bl 0x82256058
	ctx.lr = 0x82262EC8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262ee8
	if (cr6.eq) goto loc_82262EE8;
	// bl 0x82256058
	ctx.lr = 0x82262ED4;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82262ee8
	if (!cr6.eq) goto loc_82262EE8;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x82262eec
	goto loc_82262EEC;
loc_82262EE8:
	// fabs f0,f25
	ctx.fpscr.disableFlushMode();
	f0.u64 = f25.u64 & ~0x8000000000000000;
loc_82262EEC:
	// lfs f13,288(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f30,f0
	ctx.f12.f64 = double(float(f30.f64 - f0.f64));
	// lfs f11,308(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f13,f22
	ctx.f10.f64 = double(float(ctx.f13.f64 * f22.f64));
	// fmuls f9,f11,f21
	ctx.f9.f64 = double(float(ctx.f11.f64 * f21.f64));
	// stfs f10,288(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f9,308(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lfs f8,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fneg f1,f24
	ctx.f1.u64 = f24.u64 ^ 0x8000000000000000;
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmadds f25,f12,f23,f7
	f25.f64 = double(float(ctx.f12.f64 * f23.f64 + ctx.f7.f64));
	// bl 0x82235ee0
	ctx.lr = 0x82262F20;
	sub_82235EE0(ctx, base);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// bl 0x82235e30
	ctx.lr = 0x82262F2C;
	sub_82235E30(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82262F3C;
	sub_8217C088(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82262F40;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262f60
	if (cr6.eq) goto loc_82262F60;
	// bl 0x82256058
	ctx.lr = 0x82262F4C;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82262f60
	if (!cr6.eq) goto loc_82262F60;
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x82262f98
	goto loc_82262F98;
loc_82262F60:
	// lfs f0,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// lis r11,21845
	r11.s64 = 1431633920;
	// fmuls f13,f0,f15
	ctx.f13.f64 = double(float(f0.f64 * f15.f64));
	// ori r10,r11,21846
	ctx.r10.u64 = r11.u64 | 21846;
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,208(r1)
	PPC_STORE_U64(ctx.r1.u32 + 208, ctx.f12.u64);
	// lwz r9,212(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// mulhw r11,r9,r10
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r8,r9
	r11.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82262F98:
	// addi r11,r11,15
	r11.s64 = r11.s64 + 15;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x8217d9a0
	ctx.lr = 0x82262FA8;
	sub_8217D9A0(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x82262FB4;
	sub_8217BB68(ctx, base);
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// stfs f29,-26916(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r26.u32 + -26916, temp.u32);
	// fmr f8,f28
	ctx.f8.f64 = f28.f64;
	// stfs f28,-26924(r27)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// stw r9,-26892(r25)
	PPC_STORE_U32(r25.u32 + -26892, ctx.r9.u32);
	// lfs f0,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	f0.f64 = double(temp.f32);
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f7,f29
	ctx.f7.f64 = f29.f64;
	// lfs f5,-26908(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f4,-26928(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f1
	ctx.f2.f64 = ctx.f1.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82262FEC;
	sub_8217BC28(ctx, base);
	// stfs f27,-26916(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r26.u32 + -26916, temp.u32);
	// stfs f28,-26924(r27)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// lwz r9,-26892(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + -26892);
	// lfs f1,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// fmr f8,f28
	ctx.f8.f64 = f28.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f7,f27
	ctx.f7.f64 = f27.f64;
	// lfs f5,-26908(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f4,-26928(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fneg f2,f1
	ctx.f2.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// bl 0x8217bc28
	ctx.lr = 0x8226301C;
	sub_8217BC28(ctx, base);
	// stfs f29,-26916(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r26.u32 + -26916, temp.u32);
	// stfs f26,-26924(r27)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// lwz r9,-26892(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + -26892);
	// lfs f13,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmr f8,f26
	ctx.f8.f64 = f26.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f7,f29
	ctx.f7.f64 = f29.f64;
	// lfs f5,-26908(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f4,-26928(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f13
	ctx.f2.f64 = ctx.f13.f64;
	// fneg f1,f13
	ctx.f1.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// bl 0x8217bc28
	ctx.lr = 0x82263050;
	sub_8217BC28(ctx, base);
	// stfs f27,-26916(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r26.u32 + -26916, temp.u32);
	// lwz r9,-26892(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + -26892);
	// stfs f26,-26924(r27)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// fmr f8,f26
	ctx.f8.f64 = f26.f64;
	// lfs f1,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// fmr f7,f27
	ctx.f7.f64 = f27.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f5,-26908(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f1
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f4,-26928(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x82263080;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x82263084;
	sub_8217BC98(ctx, base);
	// lwz r3,-25232(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -25232);
	// li r11,1
	r11.s64 = 1;
	// stfs f30,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f30,148(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stw r20,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r20.u32);
	// stw r24,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r24.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r24,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r24.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stb r24,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, r24.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,167(r1)
	PPC_STORE_U8(ctx.r1.u32 + 167, r11.u8);
	// stb r11,168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 168, r11.u8);
	// stb r24,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r24.u8);
	// stb r24,165(r1)
	PPC_STORE_U8(ctx.r1.u32 + 165, r24.u8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822630D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x8217cb48
	ctx.lr = 0x822630D8;
	sub_8217CB48(ctx, base);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// cmpwi cr6,r23,2
	cr6.compare<int32_t>(r23.s32, 2, xer);
	// blt cr6,0x82262c94
	if (cr6.lt) goto loc_82262C94;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e20
	ctx.lr = 0x822630F0;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82189e20
	ctx.lr = 0x822630FC;
	sub_82189E20(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x8217c658
	ctx.lr = 0x82263108;
	sub_8217C658(ctx, base);
loc_82263108:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x821c9030
	ctx.lr = 0x82263110;
	sub_821C9030(ctx, base);
	// addi r1,r1,1728
	ctx.r1.s64 = ctx.r1.s64 + 1728;
	// addi r12,r1,-288
	r12.s64 = ctx.r1.s64 + -288;
	// bl 0x823dd7bc
	ctx.lr = 0x8226311C;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9f0
	ctx.lr = 0x82263124;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82263128"))) PPC_WEAK_FUNC(sub_82263128);
PPC_FUNC_IMPL(__imp__sub_82263128) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82263130;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82263144;
	sub_821C8FE0(ctx, base);
	// lwz r11,32(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822632b4
	if (cr6.eq) goto loc_822632B4;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x82263158;
	sub_82187BE0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fed0
	ctx.lr = 0x82263160;
	sub_8217FED0(ctx, base);
	// lis r21,-32131
	r21.s64 = -2105737216;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,17320(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8226317c
	if (!cr6.lt) goto loc_8226317C;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_8226317C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x82263184;
	sub_8217F768(ctx, base);
	// bl 0x82478d80
	ctx.lr = 0x82263188;
	sub_82478D80(ctx, base);
	// lwz r10,32(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// li r29,0
	r29.s64 = 0;
	// lhz r11,8(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263298
	if (cr6.eq) goto loc_82263298;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lis r11,0
	r11.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// ori r22,r11,54609
	r22.u64 = r11.u64 | 54609;
	// lis r25,-1
	r25.s64 = -65536;
	// lwz r11,-26892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_822631C0:
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r3,r10,r28
	ctx.r3.u64 = ctx.r10.u64 + r28.u64;
	// lwz r10,200(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822631e0
	if (cr6.eq) goto loc_822631E0;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// bne cr6,0x822631e4
	if (!cr6.eq) goto loc_822631E4;
loc_822631E0:
	// li r10,1
	ctx.r10.s64 = 1;
loc_822631E4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82263200
	if (cr6.eq) goto loc_82263200;
	// lwz r11,192(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// lwz r10,52(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 52);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r11,-26892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -26892);
loc_82263200:
	// lhz r10,-26892(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + -26892);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// rlwinm r8,r11,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// lwz r7,-6148(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + -6148);
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwimi r11,r6,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// mr r30,r11
	r30.u64 = r11.u64;
	// beq cr6,0x822632c4
	if (cr6.eq) goto loc_822632C4;
	// lbz r10,-6144(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822632c4
	if (cr6.eq) goto loc_822632C4;
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lbzx r10,r11,r22
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r22.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82263278
	if (!cr6.eq) goto loc_82263278;
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bne cr6,0x82263260
	if (!cr6.eq) goto loc_82263260;
	// lis r11,-4
	r11.s64 = -262144;
	// ori r11,r11,5649
	r11.u64 = r11.u64 | 5649;
	// b 0x82263268
	goto loc_82263268;
loc_82263260:
	// lis r11,-234
	r11.s64 = -15335424;
	// ori r11,r11,64529
	r11.u64 = r11.u64 | 64529;
loc_82263268:
	// stw r11,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, r11.u32);
loc_8226326C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82263270:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82265bb0
	ctx.lr = 0x82263278;
	sub_82265BB0(ctx, base);
loc_82263278:
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, r11.u32);
	// addi r28,r28,368
	r28.s64 = r28.s64 + 368;
	// lwz r10,32(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x822631c0
	if (cr6.lt) goto loc_822631C0;
loc_82263298:
	// lwz r11,17320(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 17320);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// cmpw cr6,r20,r11
	cr6.compare<int32_t>(r20.s32, r11.s32, xer);
	// ble cr6,0x822632ac
	if (!cr6.gt) goto loc_822632AC;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_822632AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822632B4;
	sub_8217F768(ctx, base);
loc_822632B4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x822632BC;
	sub_821C9030(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_822632C4:
	// lwz r11,-5052(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -5052);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226326c
	if (!cr6.eq) goto loc_8226326C;
	// lwz r11,32(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bge cr6,0x82263308
	if (!cr6.lt) goto loc_82263308;
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822632fc
	if (cr6.eq) goto loc_822632FC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82263300
	if (!cr6.eq) goto loc_82263300;
loc_822632FC:
	// li r11,1
	r11.s64 = 1;
loc_82263300:
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// b 0x82263270
	goto loc_82263270;
loc_82263308:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8226326c
	if (!cr6.eq) goto loc_8226326C;
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226332c
	if (cr6.eq) goto loc_8226332C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82263330
	if (!cr6.eq) goto loc_82263330;
loc_8226332C:
	// li r11,1
	r11.s64 = 1;
loc_82263330:
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// b 0x82263270
	goto loc_82263270;
}

__attribute__((alias("__imp__sub_82263338"))) PPC_WEAK_FUNC(sub_82263338);
PPC_FUNC_IMPL(__imp__sub_82263338) {
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
	ctx.lr = 0x82263340;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822633d8
	if (cr6.eq) goto loc_822633D8;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822633d8
	if (cr6.eq) goto loc_822633D8;
	// addi r10,r4,50
	ctx.r10.s64 = ctx.r4.s64 + 50;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r29,r10,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_82263378:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r11,r29,r3
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82263398
	if (cr6.eq) goto loc_82263398;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8226339c
	if (!cr6.eq) goto loc_8226339C;
loc_82263398:
	// li r11,1
	r11.s64 = 1;
loc_8226339C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822633c0
	if (cr6.eq) goto loc_822633C0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x822653a8
	ctx.lr = 0x822633B4;
	sub_822653A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822633e4
	if (!cr6.eq) goto loc_822633E4;
loc_822633C0:
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,368
	r31.s64 = r31.s64 + 368;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x82263378
	if (cr6.lt) goto loc_82263378;
loc_822633D8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822633E4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822633F0"))) PPC_WEAK_FUNC(sub_822633F0);
PPC_FUNC_IMPL(__imp__sub_822633F0) {
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
	// bl 0x823d91f8
	ctx.lr = 0x822633F8;
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82263590
	if (cr6.eq) goto loc_82263590;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82263444
	if (cr6.eq) goto loc_82263444;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82263448
	if (cr6.eq) goto loc_82263448;
loc_82263444:
	// li r11,0
	r11.s64 = 0;
loc_82263448:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82263590
	if (!cr6.eq) goto loc_82263590;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// ble cr6,0x82263590
	if (!cr6.gt) goto loc_82263590;
	// lhz r11,8(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82263590
	if (!cr6.lt) goto loc_82263590;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a8108
	ctx.lr = 0x82263470;
	sub_822A8108(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,48
	ctx.r10.s64 = 48;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v127,r11,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8148
	ctx.lr = 0x82263484;
	sub_822A8148(ctx, base);
	// lvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// vmsum3fp128 v60,v61,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// vor128 v59,v127,v127
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// lwz r5,48(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r11,r4,-31648
	r11.s64 = ctx.r4.s64 + -31648;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3732(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v58,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vrsqrtefp128 v56,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v56,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
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
	// vmulfp128 v55,v61,v6
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp128 v59,v55,v57,v59
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v57.f32)), simde_mm_load_ps(v59.f32)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8226352c
	if (cr6.eq) goto loc_8226352C;
	// li r11,400
	r11.s64 = 400;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v54,r28,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82263534
	goto loc_82263534;
loc_8226352C:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82263534:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mulli r10,r31,368
	ctx.r10.s64 = r31.s64 * 368;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r29,50
	ctx.r9.s64 = r29.s64 + 50;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r3
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82263564
	if (cr6.eq) goto loc_82263564;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82263568
	if (!cr6.eq) goto loc_82263568;
loc_82263564:
	// li r11,1
	r11.s64 = 1;
loc_82263568:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263590
	if (cr6.eq) goto loc_82263590;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x822653a8
	ctx.lr = 0x82263580;
	sub_822653A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82263594
	if (!cr6.eq) goto loc_82263594;
loc_82263590:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82263594:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822635A4"))) PPC_WEAK_FUNC(sub_822635A4);
PPC_FUNC_IMPL(__imp__sub_822635A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822635A8"))) PPC_WEAK_FUNC(sub_822635A8);
PPC_FUNC_IMPL(__imp__sub_822635A8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,-4944(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x822635CC;
	sub_821C8FE0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x822635DC;
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

__attribute__((alias("__imp__sub_822635F0"))) PPC_WEAK_FUNC(sub_822635F0);
PPC_FUNC_IMPL(__imp__sub_822635F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// b 0x82262810
	sub_82262810(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82263600"))) PPC_WEAK_FUNC(sub_82263600);
PPC_FUNC_IMPL(__imp__sub_82263600) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82263624;
	sub_822A8108(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82263648
	if (cr6.eq) goto loc_82263648;
	// li r11,400
	r11.s64 = 400;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82263654
	goto loc_82263654;
loc_82263648:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82263654:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// bl 0x82263338
	ctx.lr = 0x82263668;
	sub_82263338(ctx, base);
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

__attribute__((alias("__imp__sub_82263680"))) PPC_WEAK_FUNC(sub_82263680);
PPC_FUNC_IMPL(__imp__sub_82263680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mulli r10,r3,368
	ctx.r10.s64 = ctx.r3.s64 * 368;
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226369C"))) PPC_WEAK_FUNC(sub_8226369C);
PPC_FUNC_IMPL(__imp__sub_8226369C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822636A0"))) PPC_WEAK_FUNC(sub_822636A0);
PPC_FUNC_IMPL(__imp__sub_822636A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x822a8108
	ctx.lr = 0x822636C4;
	sub_822A8108(ctx, base);
	// li r10,48
	ctx.r10.s64 = 48;
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-9148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9148);
	ctx.f13.f64 = double(temp.f32);
	// ble cr6,0x82263760
	if (!cr6.gt) goto loc_82263760;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r30,32
	ctx.r8.s64 = r30.s64 + 32;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,72
	r11.s64 = r11.s64 + 72;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_8226370C:
	// lwzx r6,r8,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x82263750
	if (!cr6.eq) goto loc_82263750;
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// lfs f6,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f0,f2
	f0.f64 = double(float(sqrt(ctx.f2.f64)));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82263750
	if (!cr6.gt) goto loc_82263750;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
loc_82263750:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// addi r11,r11,368
	r11.s64 = r11.s64 + 368;
	// bne 0x8226370c
	if (!cr0.eq) goto loc_8226370C;
loc_82263760:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
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

__attribute__((alias("__imp__sub_8226377C"))) PPC_WEAK_FUNC(sub_8226377C);
PPC_FUNC_IMPL(__imp__sub_8226377C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263780"))) PPC_WEAK_FUNC(sub_82263780);
PPC_FUNC_IMPL(__imp__sub_82263780) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f1,-9148(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -9148);
	ctx.f1.f64 = double(temp.f32);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r11,r10,72
	r11.s64 = ctx.r10.s64 + 72;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_822637A8:
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x822637f4
	if (!cr6.eq) goto loc_822637F4;
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
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
	// fsqrts f0,f3
	f0.f64 = double(float(sqrt(ctx.f3.f64)));
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822637f4
	if (!cr6.gt) goto loc_822637F4;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_822637F4:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,368
	r11.s64 = r11.s64 + 368;
	// bne 0x822637a8
	if (!cr0.eq) goto loc_822637A8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82263804"))) PPC_WEAK_FUNC(sub_82263804);
PPC_FUNC_IMPL(__imp__sub_82263804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263808"))) PPC_WEAK_FUNC(sub_82263808);
PPC_FUNC_IMPL(__imp__sub_82263808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82262810
	sub_82262810(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226381C"))) PPC_WEAK_FUNC(sub_8226381C);
PPC_FUNC_IMPL(__imp__sub_8226381C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263820"))) PPC_WEAK_FUNC(sub_82263820);
PPC_FUNC_IMPL(__imp__sub_82263820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r10,-4944(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4944);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mulli r9,r4,92
	ctx.r9.s64 = ctx.r4.s64 * 92;
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r10,32(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// addi r9,r11,50
	ctx.r9.s64 = r11.s64 + 50;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,66
	r31.s64 = r11.s64 + 66;
	// mulli r10,r4,368
	ctx.r10.s64 = ctx.r4.s64 * 368;
	// stwx r3,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r3.u32);
	// lwz r11,-4944(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4944);
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stfsx f0,r3,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + r11.u32, temp.u32);
	// stwx r5,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r5.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82263894"))) PPC_WEAK_FUNC(sub_82263894);
PPC_FUNC_IMPL(__imp__sub_82263894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263898"))) PPC_WEAK_FUNC(sub_82263898);
PPC_FUNC_IMPL(__imp__sub_82263898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mulli r9,r9,368
	ctx.r9.s64 = ctx.r9.s64 * 368;
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r7,r10,50
	ctx.r7.s64 = ctx.r10.s64 + 50;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmpwi cr6,r6,3
	cr6.compare<int32_t>(ctx.r6.s32, 3, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r10,r10,66
	ctx.r10.s64 = ctx.r10.s64 + 66;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,1
	ctx.r6.s64 = 1;
	// stwx r6,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfsx f0,r7,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822638F0"))) PPC_WEAK_FUNC(sub_822638F0);
PPC_FUNC_IMPL(__imp__sub_822638F0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82263600
	ctx.lr = 0x82263914;
	sub_82263600(ctx, base);
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

__attribute__((alias("__imp__sub_82263930"))) PPC_WEAK_FUNC(sub_82263930);
PPC_FUNC_IMPL(__imp__sub_82263930) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x822633f0
	ctx.lr = 0x82263960;
	sub_822633F0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_82263980"))) PPC_WEAK_FUNC(sub_82263980);
PPC_FUNC_IMPL(__imp__sub_82263980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mulli r10,r8,368
	ctx.r10.s64 = ctx.r8.s64 * 368;
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822639AC"))) PPC_WEAK_FUNC(sub_822639AC);
PPC_FUNC_IMPL(__imp__sub_822639AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822639B0"))) PPC_WEAK_FUNC(sub_822639B0);
PPC_FUNC_IMPL(__imp__sub_822639B0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x822636a0
	ctx.lr = 0x822639E0;
	sub_822636A0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822639FC"))) PPC_WEAK_FUNC(sub_822639FC);
PPC_FUNC_IMPL(__imp__sub_822639FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263A00"))) PPC_WEAK_FUNC(sub_82263A00);
PPC_FUNC_IMPL(__imp__sub_82263A00) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82263A24;
	sub_821C8FE0(ctx, base);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x82263A2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82263a68
	if (cr6.eq) goto loc_82263A68;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
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
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// b 0x82263a6c
	goto loc_82263A6C;
loc_82263A68:
	// li r31,0
	r31.s64 = 0;
loc_82263A6C:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r31,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82263A80;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_82263A9C"))) PPC_WEAK_FUNC(sub_82263A9C);
PPC_FUNC_IMPL(__imp__sub_82263A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263AA0"))) PPC_WEAK_FUNC(sub_82263AA0);
PPC_FUNC_IMPL(__imp__sub_82263AA0) {
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
	ctx.lr = 0x82263AA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r11,26(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263ac4
	if (cr6.eq) goto loc_82263AC4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82263AC4;
	sub_82130588(ctx, base);
loc_82263AC4:
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263ad8
	if (cr6.eq) goto loc_82263AD8;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82263AD8;
	sub_82130588(ctx, base);
loc_82263AD8:
	// lhz r31,10(r30)
	r31.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82263b10
	if (cr6.eq) goto loc_82263B10;
	// lwz r29,4(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82263b08
	if (!cr6.gt) goto loc_82263B08;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82263AF4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82265240
	ctx.lr = 0x82263AFC;
	sub_82265240(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// bne 0x82263af4
	if (!cr0.eq) goto loc_82263AF4;
loc_82263B08:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82263B10;
	sub_82130588(ctx, base);
loc_82263B10:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82263B18"))) PPC_WEAK_FUNC(sub_82263B18);
PPC_FUNC_IMPL(__imp__sub_82263B18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// b 0x82263a00
	sub_82263A00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82263B24"))) PPC_WEAK_FUNC(sub_82263B24);
PPC_FUNC_IMPL(__imp__sub_82263B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263B28"))) PPC_WEAK_FUNC(sub_82263B28);
PPC_FUNC_IMPL(__imp__sub_82263B28) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// bl 0x82263a00
	ctx.lr = 0x82263B48;
	sub_82263A00(ctx, base);
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

__attribute__((alias("__imp__sub_82263B64"))) PPC_WEAK_FUNC(sub_82263B64);
PPC_FUNC_IMPL(__imp__sub_82263B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263B68"))) PPC_WEAK_FUNC(sub_82263B68);
PPC_FUNC_IMPL(__imp__sub_82263B68) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82263B90;
	sub_821C8FE0(ctx, base);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x82263bb0
	if (!cr6.eq) goto loc_82263BB0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82263be4
	goto loc_82263BE4;
loc_82263BB0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82263bf4
	if (cr6.eq) goto loc_82263BF4;
loc_82263BB8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x82263bd4
	if (cr6.eq) goto loc_82263BD4;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82263bb8
	if (!cr6.eq) goto loc_82263BB8;
	// b 0x82263bf4
	goto loc_82263BF4;
loc_82263BD4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_82263BE4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82263aa0
	ctx.lr = 0x82263BEC;
	sub_82263AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82263BF4;
	sub_82130588(ctx, base);
loc_82263BF4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82263BFC;
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

__attribute__((alias("__imp__sub_82263C14"))) PPC_WEAK_FUNC(sub_82263C14);
PPC_FUNC_IMPL(__imp__sub_82263C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263C18"))) PPC_WEAK_FUNC(sub_82263C18);
PPC_FUNC_IMPL(__imp__sub_82263C18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// b 0x82263b68
	sub_82263B68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82263C28"))) PPC_WEAK_FUNC(sub_82263C28);
PPC_FUNC_IMPL(__imp__sub_82263C28) {
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
	PPCRegister f31{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82263C30;
	// stfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-9136
	ctx.r4.s64 = ctx.r9.s64 + -9136;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// bl 0x823db670
	ctx.lr = 0x82263C70;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,10248(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821fd7c0
	ctx.lr = 0x82263C84;
	sub_821FD7C0(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// li r20,0
	r20.s64 = 0;
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// lwz r3,324(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// stb r20,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r20.u8);
	// stw r20,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r20.u32);
	// stw r8,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r8.u32);
	// bl 0x822031a8
	ctx.lr = 0x82263CA8;
	sub_822031A8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82263cc0
	if (cr6.eq) goto loc_82263CC0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82263CC0:
	// rlwinm r11,r19,1,0,30
	r11.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// li r18,1
	r18.s64 = 1;
	// add r11,r19,r11
	r11.u64 = r19.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// lwz r11,32(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82263d48
	if (!cr6.eq) goto loc_82263D48;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x82263f50
	if (!cr6.gt) goto loc_82263F50;
	// lis r11,32767
	r11.s64 = 2147418112;
	// addi r9,r31,40
	ctx.r9.s64 = r31.s64 + 40;
	// ori r22,r11,65535
	r22.u64 = r11.u64 | 65535;
loc_82263CFC:
	// cmpw cr6,r10,r19
	cr6.compare<int32_t>(ctx.r10.s32, r19.s32, xer);
	// beq cr6,0x82263d28
	if (cr6.eq) goto loc_82263D28;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r22
	cr6.compare<int32_t>(r11.s32, r22.s32, xer);
	// beq cr6,0x82263d28
	if (cr6.eq) goto loc_82263D28;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82263d28
	if (cr6.eq) goto loc_82263D28;
	// lwz r8,40(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bge cr6,0x82263d28
	if (!cr6.lt) goto loc_82263D28;
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
loc_82263D28:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// cmpw cr6,r10,r21
	cr6.compare<int32_t>(ctx.r10.s32, r21.s32, xer);
	// blt cr6,0x82263cfc
	if (cr6.lt) goto loc_82263CFC;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82263D48:
	// lwz r9,8(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r9,48(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82263d68
	if (!cr6.eq) goto loc_82263D68;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82263D68:
	// lwz r6,28(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mulli r8,r11,368
	ctx.r8.s64 = r11.s64 * 368;
	// lwz r3,36(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// lvx128 v63,r6,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r26,r8,r9
	r26.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r3,r10
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// add r27,r10,r11
	r27.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82264f38
	ctx.lr = 0x82263DA0;
	sub_82264F38(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82387a18
	ctx.lr = 0x82263DA8;
	sub_82387A18(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r28,r20
	r28.u64 = r20.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x82263eac
	if (!cr6.gt) goto loc_82263EAC;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r31,r31,36
	r31.s64 = r31.s64 + 36;
	// ori r22,r9,65535
	r22.u64 = ctx.r9.u64 | 65535;
	// addi r25,r11,-12656
	r25.s64 = r11.s64 + -12656;
	// addi r24,r10,-12632
	r24.s64 = ctx.r10.s64 + -12632;
loc_82263DD4:
	// cmpw cr6,r28,r19
	cr6.compare<int32_t>(r28.s32, r19.s32, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
	// lwz r30,-28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263e44
	if (cr6.eq) goto loc_82263E44;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x82263E18;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82263e44
	if (cr6.eq) goto loc_82263E44;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82263e44
	if (cr6.eq) goto loc_82263E44;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82263E34;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
loc_82263E44:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// bgt cr6,0x82263e98
	if (cr6.gt) goto loc_82263E98;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpw cr6,r10,r22
	cr6.compare<int32_t>(ctx.r10.s32, r22.s32, xer);
	// beq cr6,0x82263e74
	if (cr6.eq) goto loc_82263E74;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82263e98
	if (!cr6.eq) goto loc_82263E98;
loc_82263E74:
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// bne cr6,0x82263e9c
	if (!cr6.eq) goto loc_82263E9C;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r4,r11,64
	ctx.r4.s64 = r11.s64 + 64;
	// bl 0x82264f38
	ctx.lr = 0x82263E90;
	sub_82264F38(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82263e9c
	if (!cr6.lt) goto loc_82263E9C;
loc_82263E98:
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
loc_82263E9C:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// cmpw cr6,r28,r21
	cr6.compare<int32_t>(r28.s32, r21.s32, xer);
	// blt cr6,0x82263dd4
	if (cr6.lt) goto loc_82263DD4;
loc_82263EAC:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82263f50
	if (!cr6.eq) goto loc_82263F50;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// bne cr6,0x82263f50
	if (!cr6.eq) goto loc_82263F50;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,-4940(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4940);
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// beq cr6,0x82263ee8
	if (cr6.eq) goto loc_82263EE8;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// stw r29,-4940(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4940, r29.u32);
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x82263f10
	goto loc_82263F10;
loc_82263EE8:
	// lwz r10,-4936(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4936);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82263f0c
	if (!cr6.eq) goto loc_82263F0C;
	// cmpwi cr6,r18,1
	cr6.compare<int32_t>(r18.s32, 1, xer);
	// beq cr6,0x82263f24
	if (cr6.eq) goto loc_82263F24;
	// lwz r10,-4932(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4932);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x82263f28
	goto loc_82263F28;
loc_82263F0C:
	// lwz r6,-4932(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4932);
loc_82263F10:
	// cmpwi cr6,r18,1
	cr6.compare<int32_t>(r18.s32, 1, xer);
	// bne cr6,0x82263f28
	if (!cr6.eq) goto loc_82263F28;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x82263f28
	goto loc_82263F28;
loc_82263F24:
	// lwz r6,-4932(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4932);
loc_82263F28:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r18,-4936(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4936, r18.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r10,-9144
	ctx.r4.s64 = ctx.r10.s64 + -9144;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82263F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82263F50:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82263F60"))) PPC_WEAK_FUNC(sub_82263F60);
PPC_FUNC_IMPL(__imp__sub_82263F60) {
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
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82263F68;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-9136
	ctx.r4.s64 = ctx.r9.s64 + -9136;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// bl 0x823db670
	ctx.lr = 0x82263FA8;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x82263FBC;
	sub_821FD7C0(ctx, base);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r21,0
	r21.s64 = 0;
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// stb r21,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r21.u8);
	// stw r21,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r21.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// bl 0x822031a8
	ctx.lr = 0x82263FE0;
	sub_822031A8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82263ff8
	if (cr6.eq) goto loc_82263FF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82263FF8:
	// rlwinm r11,r24,1,0,30
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 1) & 0xFFFFFFFE;
	// li r20,1
	r20.s64 = 1;
	// add r11,r24,r11
	r11.u64 = r24.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r8,r11,r30
	ctx.r8.u64 = r11.u64 + r30.u64;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lwz r10,32(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x82264080
	if (!cr6.eq) goto loc_82264080;
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x82264254
	if (!cr6.gt) goto loc_82264254;
	// lis r11,32767
	r11.s64 = 2147418112;
	// addi r9,r30,40
	ctx.r9.s64 = r30.s64 + 40;
	// ori r7,r11,65535
	ctx.r7.u64 = r11.u64 | 65535;
loc_82264034:
	// cmpw cr6,r10,r24
	cr6.compare<int32_t>(ctx.r10.s32, r24.s32, xer);
	// beq cr6,0x82264060
	if (cr6.eq) goto loc_82264060;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// beq cr6,0x82264060
	if (cr6.eq) goto loc_82264060;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82264060
	if (cr6.eq) goto loc_82264060;
	// lwz r6,40(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bge cr6,0x82264060
	if (!cr6.lt) goto loc_82264060;
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
loc_82264060:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// cmpw cr6,r10,r22
	cr6.compare<int32_t>(ctx.r10.s32, r22.s32, xer);
	// blt cr6,0x82264034
	if (cr6.lt) goto loc_82264034;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82264080:
	// lwz r9,8(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r9,48(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822640a0
	if (!cr6.eq) goto loc_822640A0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_822640A0:
	// lwz r8,36(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r9,28(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// addi r5,r9,64
	ctx.r5.s64 = ctx.r9.s64 + 64;
	// add r27,r11,r10
	r27.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82263780
	ctx.lr = 0x822640C0;
	sub_82263780(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82387a18
	ctx.lr = 0x822640C8;
	sub_82387A18(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r28,r21
	r28.u64 = r21.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x822641b0
	if (!cr6.gt) goto loc_822641B0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r29,r30,36
	r29.s64 = r30.s64 + 36;
	// addi r26,r11,-12656
	r26.s64 = r11.s64 + -12656;
	// addi r25,r10,-12632
	r25.s64 = ctx.r10.s64 + -12632;
loc_822640EC:
	// cmpw cr6,r28,r24
	cr6.compare<int32_t>(r28.s32, r24.s32, xer);
	// beq cr6,0x822641a0
	if (cr6.eq) goto loc_822641A0;
	// lwz r30,-28(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822641b0
	if (cr6.eq) goto loc_822641B0;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822641a0
	if (cr6.eq) goto loc_822641A0;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226415c
	if (cr6.eq) goto loc_8226415C;
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
	ctx.lr = 0x82264130;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226415c
	if (cr6.eq) goto loc_8226415C;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226415c
	if (cr6.eq) goto loc_8226415C;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8226414C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822641a0
	if (cr6.eq) goto loc_822641A0;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x822641a0
	if (cr6.eq) goto loc_822641A0;
loc_8226415C:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,-4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -4);
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// bgt cr6,0x8226419c
	if (cr6.gt) goto loc_8226419C;
	// bne cr6,0x822641a0
	if (!cr6.eq) goto loc_822641A0;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r5,r11,64
	ctx.r5.s64 = r11.s64 + 64;
	// bl 0x82263780
	ctx.lr = 0x82264194;
	sub_82263780(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x822641a0
	if (!cr6.lt) goto loc_822641A0;
loc_8226419C:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
loc_822641A0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r22
	cr6.compare<int32_t>(r28.s32, r22.s32, xer);
	// blt cr6,0x822640ec
	if (cr6.lt) goto loc_822640EC;
loc_822641B0:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82264254
	if (!cr6.eq) goto loc_82264254;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x82264254
	if (!cr6.eq) goto loc_82264254;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,-4940(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4940);
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// beq cr6,0x822641ec
	if (cr6.eq) goto loc_822641EC;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// stw r31,-4940(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4940, r31.u32);
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x82264214
	goto loc_82264214;
loc_822641EC:
	// lwz r10,-4936(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4936);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82264210
	if (!cr6.eq) goto loc_82264210;
	// cmpwi cr6,r20,1
	cr6.compare<int32_t>(r20.s32, 1, xer);
	// beq cr6,0x82264228
	if (cr6.eq) goto loc_82264228;
	// lwz r10,-4932(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4932);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x8226422c
	goto loc_8226422C;
loc_82264210:
	// lwz r6,-4932(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4932);
loc_82264214:
	// cmpwi cr6,r20,1
	cr6.compare<int32_t>(r20.s32, 1, xer);
	// bne cr6,0x8226422c
	if (!cr6.eq) goto loc_8226422C;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x8226422c
	goto loc_8226422C;
loc_82264228:
	// lwz r6,-4932(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4932);
loc_8226422C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r20,-4936(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4936, r20.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r10,-9144
	ctx.r4.s64 = ctx.r10.s64 + -9144;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82264254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82264254:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82264264"))) PPC_WEAK_FUNC(sub_82264264);
PPC_FUNC_IMPL(__imp__sub_82264264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264268"))) PPC_WEAK_FUNC(sub_82264268);
PPC_FUNC_IMPL(__imp__sub_82264268) {
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
	ctx.lr = 0x82264270;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r4,36(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82264298
	if (cr6.eq) goto loc_82264298;
loc_82264284:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82263b68
	ctx.lr = 0x8226428C;
	sub_82263B68(ctx, base);
	// lwz r4,36(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82264284
	if (!cr6.eq) goto loc_82264284;
loc_82264298:
	// lwz r31,44(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822642d4
	if (cr6.eq) goto loc_822642D4;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822642AC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822642d4
	if (!cr6.eq) goto loc_822642D4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822642d4
	if (cr6.eq) goto loc_822642D4;
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
	ctx.lr = 0x822642D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822642D4:
	// lwz r31,48(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82264310
	if (cr6.eq) goto loc_82264310;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822642E8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82264310
	if (!cr6.eq) goto loc_82264310;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82264310
	if (cr6.eq) goto loc_82264310;
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
	ctx.lr = 0x82264310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82264310:
	// addi r30,r28,60
	r30.s64 = r28.s64 + 60;
	// li r29,4
	r29.s64 = 4;
loc_82264318:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82264354
	if (cr6.eq) goto loc_82264354;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8226432C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82264354
	if (!cr6.eq) goto loc_82264354;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82264354
	if (cr6.eq) goto loc_82264354;
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
	ctx.lr = 0x82264354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82264354:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82264318
	if (!cr0.eq) goto loc_82264318;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x82264368;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82264370"))) PPC_WEAK_FUNC(sub_82264370);
PPC_FUNC_IMPL(__imp__sub_82264370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82263b68
	sub_82263B68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82264384"))) PPC_WEAK_FUNC(sub_82264384);
PPC_FUNC_IMPL(__imp__sub_82264384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264388"))) PPC_WEAK_FUNC(sub_82264388);
PPC_FUNC_IMPL(__imp__sub_82264388) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82263c28
	ctx.lr = 0x822643B4;
	sub_82263C28(ctx, base);
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

__attribute__((alias("__imp__sub_822643D0"))) PPC_WEAK_FUNC(sub_822643D0);
PPC_FUNC_IMPL(__imp__sub_822643D0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82263f60
	ctx.lr = 0x822643FC;
	sub_82263F60(ctx, base);
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

__attribute__((alias("__imp__sub_82264418"))) PPC_WEAK_FUNC(sub_82264418);
PPC_FUNC_IMPL(__imp__sub_82264418) {
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
	// addi r4,r11,15144
	ctx.r4.s64 = r11.s64 + 15144;
	// addi r3,r10,-8680
	ctx.r3.s64 = ctx.r10.s64 + -8680;
	// bl 0x82554798
	ctx.lr = 0x82264438;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,17264
	ctx.r4.s64 = ctx.r9.s64 + 17264;
	// addi r3,r8,-8704
	ctx.r3.s64 = ctx.r8.s64 + -8704;
	// bl 0x82554798
	ctx.lr = 0x8226444C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,14344
	ctx.r4.s64 = ctx.r7.s64 + 14344;
	// addi r3,r6,-8748
	ctx.r3.s64 = ctx.r6.s64 + -8748;
	// bl 0x82554798
	ctx.lr = 0x82264460;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,13736
	ctx.r4.s64 = ctx.r5.s64 + 13736;
	// addi r3,r3,-8792
	ctx.r3.s64 = ctx.r3.s64 + -8792;
	// bl 0x82554798
	ctx.lr = 0x82264474;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,14368
	ctx.r4.s64 = r11.s64 + 14368;
	// addi r3,r10,-8836
	ctx.r3.s64 = ctx.r10.s64 + -8836;
	// bl 0x82554798
	ctx.lr = 0x82264488;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,14488
	ctx.r4.s64 = ctx.r9.s64 + 14488;
	// addi r3,r8,-8884
	ctx.r3.s64 = ctx.r8.s64 + -8884;
	// bl 0x82554798
	ctx.lr = 0x8226449C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,14576
	ctx.r4.s64 = ctx.r7.s64 + 14576;
	// addi r3,r6,-8924
	ctx.r3.s64 = ctx.r6.s64 + -8924;
	// bl 0x82554798
	ctx.lr = 0x822644B0;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,14640
	ctx.r4.s64 = ctx.r5.s64 + 14640;
	// addi r3,r3,-8960
	ctx.r3.s64 = ctx.r3.s64 + -8960;
	// bl 0x82554798
	ctx.lr = 0x822644C4;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,14720
	ctx.r4.s64 = r11.s64 + 14720;
	// addi r3,r10,-8992
	ctx.r3.s64 = ctx.r10.s64 + -8992;
	// bl 0x82554798
	ctx.lr = 0x822644D8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,14768
	ctx.r4.s64 = ctx.r9.s64 + 14768;
	// addi r3,r8,-9036
	ctx.r3.s64 = ctx.r8.s64 + -9036;
	// bl 0x82554798
	ctx.lr = 0x822644EC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,17288
	ctx.r4.s64 = ctx.r7.s64 + 17288;
	// addi r3,r6,-9076
	ctx.r3.s64 = ctx.r6.s64 + -9076;
	// bl 0x82554798
	ctx.lr = 0x82264500;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,17360
	ctx.r4.s64 = ctx.r5.s64 + 17360;
	// addi r3,r3,-9120
	ctx.r3.s64 = ctx.r3.s64 + -9120;
	// bl 0x82554798
	ctx.lr = 0x82264514;
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

