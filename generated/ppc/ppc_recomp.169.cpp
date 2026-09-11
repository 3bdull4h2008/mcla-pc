#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_827A9404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9404) {
	__imp__sub_827A9404(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9408) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r5,r11,22704
	ctx.r5.s64 = r11.s64 + 22704;
	// addi r3,r10,3076
	ctx.r3.s64 = ctx.r10.s64 + 3076;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9408) {
	__imp__sub_827A9408(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9424) {
	__imp__sub_827A9424(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29800
	ctx.r3.s64 = r11.s64 + -29800;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9428) {
	__imp__sub_827A9428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9434) {
	__imp__sub_827A9434(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,24148
	ctx.r5.s64 = r11.s64 + 24148;
	// addi r3,r10,-12808
	ctx.r3.s64 = ctx.r10.s64 + -12808;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9438) {
	__imp__sub_827A9438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9454) {
	__imp__sub_827A9454(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9458) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stw r11,-12776(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12776, r11.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,32640
	ctx.r9.s64 = 2139095040;
	// lis r11,32704
	r11.s64 = 2143289344;
	// stw r10,-12788(r8)
	PPC_STORE_U32(ctx.r8.u32 + -12788, ctx.r10.u32);
	// stw r9,-12780(r7)
	PPC_STORE_U32(ctx.r7.u32 + -12780, ctx.r9.u32);
	// stw r11,-12784(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12784, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9458) {
	__imp__sub_827A9458(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A948C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A948C) {
	__imp__sub_827A948C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-12752
	ctx.r9.s64 = r11.s64 + -12752;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,-12752(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -12752, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9490) {
	__imp__sub_827A9490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A94B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-12736
	ctx.r9.s64 = r11.s64 + -12736;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A94B0) {
	__imp__sub_827A94B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A94C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,31568
	ctx.r5.s64 = r11.s64 + 31568;
	// addi r3,r10,-12716
	ctx.r3.s64 = ctx.r10.s64 + -12716;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A94C8) {
	__imp__sub_827A94C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A94E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A94E4) {
	__imp__sub_827A94E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A94E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r11,-29884
	ctx.r9.s64 = r11.s64 + -29884;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r9,44
	r11.s64 = ctx.r9.s64 + 44;
loc_827A94FC:
	// sth r8,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r8.u16);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r8,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r8.u16);
	// addi r11,r11,1540
	r11.s64 = r11.s64 + 1540;
	// bge 0x827a94fc
	if (!cr0.lt) goto loc_827A94FC;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stb r8,6212(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6212, ctx.r8.u8);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lis r6,-32132
	ctx.r6.s64 = -2105802752;
	// stw r11,6204(r9)
	PPC_STORE_U32(ctx.r9.u32 + 6204, r11.u32);
	// stw r10,6208(r9)
	PPC_STORE_U32(ctx.r9.u32 + 6208, ctx.r10.u32);
	// stw r9,-12720(r7)
	PPC_STORE_U32(ctx.r7.u32 + -12720, ctx.r9.u32);
	// addi r3,r6,-29768
	ctx.r3.s64 = ctx.r6.s64 + -29768;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A94E8) {
	__imp__sub_827A94E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,31740
	ctx.r5.s64 = r11.s64 + 31740;
	// addi r3,r10,-12696
	ctx.r3.s64 = ctx.r10.s64 + -12696;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9538) {
	__imp__sub_827A9538(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9554) {
	__imp__sub_827A9554(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-32624
	ctx.r5.s64 = r11.s64 + -32624;
	// addi r3,r10,-12628
	ctx.r3.s64 = ctx.r10.s64 + -12628;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9558) {
	__imp__sub_827A9558(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9574) {
	__imp__sub_827A9574(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-32612
	ctx.r5.s64 = r11.s64 + -32612;
	// addi r3,r10,-12668
	ctx.r3.s64 = ctx.r10.s64 + -12668;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9578) {
	__imp__sub_827A9578(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9594) {
	__imp__sub_827A9594(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9598) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-32600
	ctx.r5.s64 = r11.s64 + -32600;
	// addi r3,r10,-12648
	ctx.r3.s64 = ctx.r10.s64 + -12648;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9598) {
	__imp__sub_827A9598(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A95B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A95B4) {
	__imp__sub_827A95B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A95B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-31280
	ctx.r9.s64 = r11.s64 + -31280;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r5,r10,-12352
	ctx.r5.s64 = ctx.r10.s64 + -12352;
	// li r4,16
	ctx.r4.s64 = 16;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,32
	ctx.r3.s64 = 32;
	// lvx128 v62,r9,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// lvx128 v61,r9,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r9,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r5,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r5,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r5,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A95B8) {
	__imp__sub_827A95B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9604) {
	__imp__sub_827A9604(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-30524
	ctx.r5.s64 = r11.s64 + -30524;
	// addi r3,r10,-12384
	ctx.r3.s64 = ctx.r10.s64 + -12384;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9608) {
	__imp__sub_827A9608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9624) {
	__imp__sub_827A9624(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-30512
	ctx.r5.s64 = r11.s64 + -30512;
	// addi r3,r10,-12404
	ctx.r3.s64 = ctx.r10.s64 + -12404;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9628) {
	__imp__sub_827A9628(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9644) {
	__imp__sub_827A9644(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9648) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-29808
	ctx.r3.s64 = r11.s64 + -29808;
	// bl 0x821c9790
	ctx.lr = 0x827A9664;
	sub_821C9790(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r3,-12272(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12272, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9648) {
	__imp__sub_827A9648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A967C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A967C) {
	__imp__sub_827A967C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9680) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-29800
	ctx.r3.s64 = r11.s64 + -29800;
	// bl 0x821c9790
	ctx.lr = 0x827A969C;
	sub_821C9790(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r3,-12276(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12276, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9680) {
	__imp__sub_827A9680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A96B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A96B4) {
	__imp__sub_827A96B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A96B8) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-29792
	ctx.r3.s64 = r11.s64 + -29792;
	// bl 0x821c9790
	ctx.lr = 0x827A96D4;
	sub_821C9790(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r3,-12280(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12280, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A96B8) {
	__imp__sub_827A96B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A96EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A96EC) {
	__imp__sub_827A96EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A96F0) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-29784
	ctx.r3.s64 = r11.s64 + -29784;
	// bl 0x821c9790
	ctx.lr = 0x827A970C;
	sub_821C9790(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r3,-12284(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12284, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A96F0) {
	__imp__sub_827A96F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9724) {
	__imp__sub_827A9724(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29288
	ctx.r5.s64 = r11.s64 + -29288;
	// addi r3,r10,-12248
	ctx.r3.s64 = ctx.r10.s64 + -12248;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9728) {
	__imp__sub_827A9728(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9744) {
	__imp__sub_827A9744(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27604
	ctx.r5.s64 = r11.s64 + -27604;
	// addi r3,r10,-12112
	ctx.r3.s64 = ctx.r10.s64 + -12112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9748) {
	__imp__sub_827A9748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9764) {
	__imp__sub_827A9764(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27596
	ctx.r5.s64 = r11.s64 + -27596;
	// addi r3,r10,-12192
	ctx.r3.s64 = ctx.r10.s64 + -12192;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9768) {
	__imp__sub_827A9768(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9784) {
	__imp__sub_827A9784(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27580
	ctx.r5.s64 = r11.s64 + -27580;
	// addi r3,r10,-12032
	ctx.r3.s64 = ctx.r10.s64 + -12032;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9788) {
	__imp__sub_827A9788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A97A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A97A4) {
	__imp__sub_827A97A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A97A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27564
	ctx.r5.s64 = r11.s64 + -27564;
	// addi r3,r10,-12072
	ctx.r3.s64 = ctx.r10.s64 + -12072;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A97A8) {
	__imp__sub_827A97A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A97C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A97C4) {
	__imp__sub_827A97C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A97C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27548
	ctx.r5.s64 = r11.s64 + -27548;
	// addi r3,r10,-12092
	ctx.r3.s64 = ctx.r10.s64 + -12092;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A97C8) {
	__imp__sub_827A97C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A97E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A97E4) {
	__imp__sub_827A97E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A97E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27536
	ctx.r5.s64 = r11.s64 + -27536;
	// addi r3,r10,-12212
	ctx.r3.s64 = ctx.r10.s64 + -12212;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A97E8) {
	__imp__sub_827A97E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9804) {
	__imp__sub_827A9804(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27516
	ctx.r5.s64 = r11.s64 + -27516;
	// addi r3,r10,-12132
	ctx.r3.s64 = ctx.r10.s64 + -12132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9808) {
	__imp__sub_827A9808(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9824) {
	__imp__sub_827A9824(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9828) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27500
	ctx.r5.s64 = r11.s64 + -27500;
	// addi r3,r10,-12172
	ctx.r3.s64 = ctx.r10.s64 + -12172;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9828) {
	__imp__sub_827A9828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9844) {
	__imp__sub_827A9844(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27484
	ctx.r5.s64 = r11.s64 + -27484;
	// addi r3,r10,-12052
	ctx.r3.s64 = ctx.r10.s64 + -12052;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9848) {
	__imp__sub_827A9848(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9864) {
	__imp__sub_827A9864(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9868) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27468
	ctx.r5.s64 = r11.s64 + -27468;
	// addi r3,r10,-12152
	ctx.r3.s64 = ctx.r10.s64 + -12152;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9868) {
	__imp__sub_827A9868(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9884) {
	__imp__sub_827A9884(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-25088
	ctx.r5.s64 = r11.s64 + -25088;
	// addi r3,r10,-12008
	ctx.r3.s64 = ctx.r10.s64 + -12008;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9888) {
	__imp__sub_827A9888(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A98A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A98A4) {
	__imp__sub_827A98A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A98A8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-11952
	ctx.r3.s64 = r11.s64 + -11952;
	// bl 0x82163ee8
	ctx.lr = 0x827A98C0;
	sub_82163EE8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29720
	ctx.r3.s64 = ctx.r10.s64 + -29720;
	// bl 0x823d9a98
	ctx.lr = 0x827A98CC;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A98A8) {
	__imp__sub_827A98A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A98DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A98DC) {
	__imp__sub_827A98DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A98E0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-11912
	ctx.r3.s64 = r11.s64 + -11912;
	// bl 0x82163ee8
	ctx.lr = 0x827A98F8;
	sub_82163EE8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29712
	ctx.r3.s64 = ctx.r10.s64 + -29712;
	// bl 0x823d9a98
	ctx.lr = 0x827A9904;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A98E0) {
	__imp__sub_827A98E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9914) {
	__imp__sub_827A9914(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9918) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29704
	ctx.r3.s64 = r11.s64 + -29704;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9918) {
	__imp__sub_827A9918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9924) {
	__imp__sub_827A9924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9928) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17448
	ctx.r5.s64 = r11.s64 + -17448;
	// addi r3,r10,-10264
	ctx.r3.s64 = ctx.r10.s64 + -10264;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9928) {
	__imp__sub_827A9928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9944) {
	__imp__sub_827A9944(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17440
	ctx.r5.s64 = r11.s64 + -17440;
	// addi r3,r10,-10304
	ctx.r3.s64 = ctx.r10.s64 + -10304;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9948) {
	__imp__sub_827A9948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9964) {
	__imp__sub_827A9964(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17424
	ctx.r5.s64 = r11.s64 + -17424;
	// addi r3,r10,-10284
	ctx.r3.s64 = ctx.r10.s64 + -10284;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9968) {
	__imp__sub_827A9968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9984) {
	__imp__sub_827A9984(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-14576
	ctx.r5.s64 = r11.s64 + -14576;
	// addi r3,r10,-10124
	ctx.r3.s64 = ctx.r10.s64 + -10124;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9988) {
	__imp__sub_827A9988(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A99A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A99A4) {
	__imp__sub_827A99A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A99A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-14568
	ctx.r5.s64 = r11.s64 + -14568;
	// addi r3,r10,-10164
	ctx.r3.s64 = ctx.r10.s64 + -10164;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A99A8) {
	__imp__sub_827A99A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A99C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A99C4) {
	__imp__sub_827A99C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A99C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-14556
	ctx.r5.s64 = r11.s64 + -14556;
	// addi r3,r10,-10184
	ctx.r3.s64 = ctx.r10.s64 + -10184;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A99C8) {
	__imp__sub_827A99C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A99E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A99E4) {
	__imp__sub_827A99E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A99E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-14544
	ctx.r5.s64 = r11.s64 + -14544;
	// addi r3,r10,-10144
	ctx.r3.s64 = ctx.r10.s64 + -10144;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A99E8) {
	__imp__sub_827A99E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9A04) {
	__imp__sub_827A9A04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9A08) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r31,r30,-7824
	r31.s64 = r30.s64 + -7824;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6928
	ctx.lr = 0x827A9A2C;
	sub_824E6928(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// addi r11,r11,-4984
	r11.s64 = r11.s64 + -4984;
	// stw r11,-7824(r30)
	PPC_STORE_U32(r30.u32 + -7824, r11.u32);
	// bl 0x821f8840
	ctx.lr = 0x827A9A40;
	sub_821F8840(ctx, base);
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29680
	ctx.r3.s64 = r11.s64 + -29680;
	// bl 0x823d9a98
	ctx.lr = 0x827A9A4C;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827A9A08) {
	__imp__sub_827A9A08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9A64) {
	__imp__sub_827A9A64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9A68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-3112
	ctx.r5.s64 = r11.s64 + -3112;
	// addi r3,r10,-7108
	ctx.r3.s64 = ctx.r10.s64 + -7108;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9A68) {
	__imp__sub_827A9A68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9A84) {
	__imp__sub_827A9A84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9A88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-3100
	ctx.r5.s64 = r11.s64 + -3100;
	// addi r3,r10,-7068
	ctx.r3.s64 = ctx.r10.s64 + -7068;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9A88) {
	__imp__sub_827A9A88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9AA4) {
	__imp__sub_827A9AA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9AA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-3088
	ctx.r5.s64 = r11.s64 + -3088;
	// addi r3,r10,-7088
	ctx.r3.s64 = ctx.r10.s64 + -7088;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9AA8) {
	__imp__sub_827A9AA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9AC4) {
	__imp__sub_827A9AC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9AC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,23
	ctx.r9.s64 = 23;
	// addi r11,r11,-6984
	r11.s64 = r11.s64 + -6984;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_827A9ADC:
	// stb r10,-2(r11)
	PPC_STORE_U8(r11.u32 + -2, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r10.u8);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// stb r10,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r10.u8);
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// stw r10,6(r11)
	PPC_STORE_U32(r11.u32 + 6, ctx.r10.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x827a9adc
	if (!cr0.lt) goto loc_827A9ADC;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9AC8) {
	__imp__sub_827A9AC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9B04) {
	__imp__sub_827A9B04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23552
	ctx.r5.s64 = r11.s64 + 23552;
	// addi r3,r10,-6680
	ctx.r3.s64 = ctx.r10.s64 + -6680;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9B08) {
	__imp__sub_827A9B08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9B24) {
	__imp__sub_827A9B24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27408
	ctx.r5.s64 = r11.s64 + -27408;
	// addi r3,r10,-6428
	ctx.r3.s64 = ctx.r10.s64 + -6428;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9B28) {
	__imp__sub_827A9B28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9B44) {
	__imp__sub_827A9B44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9B48) {
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
	// lis r11,-32184
	r11.s64 = -2109210624;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-17552
	ctx.r5.s64 = r11.s64 + -17552;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A9B70;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-15152
	r11.s64 = ctx.r7.s64 + -15152;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9B48) {
	__imp__sub_827A9B48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9BBC) {
	__imp__sub_827A9BBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9BC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-15104
	ctx.r7.s64 = ctx.r8.s64 + -15104;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9BC0) {
	__imp__sub_827A9BC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9BE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17828
	ctx.r5.s64 = r11.s64 + -17828;
	// addi r3,r10,-6208
	ctx.r3.s64 = ctx.r10.s64 + -6208;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9BE0) {
	__imp__sub_827A9BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9BFC) {
	__imp__sub_827A9BFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17816
	ctx.r5.s64 = r11.s64 + -17816;
	// addi r3,r10,-6188
	ctx.r3.s64 = ctx.r10.s64 + -6188;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9C00) {
	__imp__sub_827A9C00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9C1C) {
	__imp__sub_827A9C1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17800
	ctx.r5.s64 = r11.s64 + -17800;
	// addi r3,r10,-6228
	ctx.r3.s64 = ctx.r10.s64 + -6228;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9C20) {
	__imp__sub_827A9C20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9C3C) {
	__imp__sub_827A9C3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9C40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-13588
	ctx.r7.s64 = ctx.r8.s64 + -13588;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9C40) {
	__imp__sub_827A9C40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9C60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-13580
	ctx.r7.s64 = ctx.r8.s64 + -13580;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9C60) {
	__imp__sub_827A9C60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-15872
	ctx.r5.s64 = r11.s64 + -15872;
	// addi r3,r10,-5168
	ctx.r3.s64 = ctx.r10.s64 + -5168;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9C80) {
	__imp__sub_827A9C80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9C9C) {
	__imp__sub_827A9C9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-14120
	ctx.r5.s64 = r11.s64 + -14120;
	// addi r3,r10,-5124
	ctx.r3.s64 = ctx.r10.s64 + -5124;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9CA0) {
	__imp__sub_827A9CA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9CBC) {
	__imp__sub_827A9CBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9CC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-12672
	ctx.r7.s64 = ctx.r8.s64 + -12672;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9CC0) {
	__imp__sub_827A9CC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9CE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-12664
	ctx.r7.s64 = ctx.r8.s64 + -12664;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9CE0) {
	__imp__sub_827A9CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-10168
	ctx.r5.s64 = r11.s64 + -10168;
	// addi r3,r10,-5028
	ctx.r3.s64 = ctx.r10.s64 + -5028;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9D00) {
	__imp__sub_827A9D00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9D1C) {
	__imp__sub_827A9D1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-10152
	ctx.r5.s64 = r11.s64 + -10152;
	// addi r3,r10,-5048
	ctx.r3.s64 = ctx.r10.s64 + -5048;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9D20) {
	__imp__sub_827A9D20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9D3C) {
	__imp__sub_827A9D3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-9656
	ctx.r5.s64 = r11.s64 + -9656;
	// addi r3,r10,-4984
	ctx.r3.s64 = ctx.r10.s64 + -4984;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9D40) {
	__imp__sub_827A9D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9D5C) {
	__imp__sub_827A9D5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-9644
	ctx.r5.s64 = r11.s64 + -9644;
	// addi r3,r10,-5004
	ctx.r3.s64 = ctx.r10.s64 + -5004;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9D60) {
	__imp__sub_827A9D60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9D7C) {
	__imp__sub_827A9D7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-7352
	ctx.r5.s64 = r11.s64 + -7352;
	// addi r3,r10,-4868
	ctx.r3.s64 = ctx.r10.s64 + -4868;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9D80) {
	__imp__sub_827A9D80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9D9C) {
	__imp__sub_827A9D9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9DA0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-4336
	ctx.r3.s64 = r11.s64 + -4336;
	// bl 0x821c8ed8
	ctx.lr = 0x827A9DB8;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29664
	ctx.r3.s64 = ctx.r10.s64 + -29664;
	// bl 0x823d9a98
	ctx.lr = 0x827A9DC4;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9DA0) {
	__imp__sub_827A9DA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9DD4) {
	__imp__sub_827A9DD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-3120
	ctx.r5.s64 = r11.s64 + -3120;
	// addi r3,r10,-4204
	ctx.r3.s64 = ctx.r10.s64 + -4204;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9DD8) {
	__imp__sub_827A9DD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9DF4) {
	__imp__sub_827A9DF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9DF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-11596
	ctx.r7.s64 = ctx.r8.s64 + -11596;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9DF8) {
	__imp__sub_827A9DF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9E18) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3556
	ctx.r3.s64 = r11.s64 + -3556;
	// bl 0x824f09d0
	ctx.lr = 0x827A9E30;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29552
	ctx.r3.s64 = ctx.r10.s64 + -29552;
	// bl 0x823d9a98
	ctx.lr = 0x827A9E3C;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9E18) {
	__imp__sub_827A9E18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9E4C) {
	__imp__sub_827A9E4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9E50) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3040
	ctx.r3.s64 = r11.s64 + -3040;
	// bl 0x824f09d0
	ctx.lr = 0x827A9E68;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29648
	ctx.r3.s64 = ctx.r10.s64 + -29648;
	// bl 0x823d9a98
	ctx.lr = 0x827A9E74;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9E50) {
	__imp__sub_827A9E50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9E84) {
	__imp__sub_827A9E84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9E88) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3348
	ctx.r3.s64 = r11.s64 + -3348;
	// bl 0x824f09d0
	ctx.lr = 0x827A9EA0;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29632
	ctx.r3.s64 = ctx.r10.s64 + -29632;
	// bl 0x823d9a98
	ctx.lr = 0x827A9EAC;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9E88) {
	__imp__sub_827A9E88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9EBC) {
	__imp__sub_827A9EBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9EC0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3404
	ctx.r3.s64 = r11.s64 + -3404;
	// bl 0x824f09d0
	ctx.lr = 0x827A9ED8;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29616
	ctx.r3.s64 = ctx.r10.s64 + -29616;
	// bl 0x823d9a98
	ctx.lr = 0x827A9EE4;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9EC0) {
	__imp__sub_827A9EC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9EF4) {
	__imp__sub_827A9EF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9EF8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3096
	ctx.r3.s64 = r11.s64 + -3096;
	// bl 0x824f09d0
	ctx.lr = 0x827A9F10;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29600
	ctx.r3.s64 = ctx.r10.s64 + -29600;
	// bl 0x823d9a98
	ctx.lr = 0x827A9F1C;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9EF8) {
	__imp__sub_827A9EF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9F2C) {
	__imp__sub_827A9F2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9F30) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3232
	ctx.r3.s64 = r11.s64 + -3232;
	// bl 0x824f09d0
	ctx.lr = 0x827A9F48;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29584
	ctx.r3.s64 = ctx.r10.s64 + -29584;
	// bl 0x823d9a98
	ctx.lr = 0x827A9F54;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9F30) {
	__imp__sub_827A9F30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9F64) {
	__imp__sub_827A9F64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9F68) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3500
	ctx.r3.s64 = r11.s64 + -3500;
	// bl 0x824f09d0
	ctx.lr = 0x827A9F80;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29568
	ctx.r3.s64 = ctx.r10.s64 + -29568;
	// bl 0x823d9a98
	ctx.lr = 0x827A9F8C;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9F68) {
	__imp__sub_827A9F68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9F9C) {
	__imp__sub_827A9F9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29536
	ctx.r3.s64 = r11.s64 + -29536;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9FA0) {
	__imp__sub_827A9FA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9FAC) {
	__imp__sub_827A9FAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1828
	ctx.r5.s64 = r11.s64 + -1828;
	// addi r3,r10,-3156
	ctx.r3.s64 = ctx.r10.s64 + -3156;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9FB0) {
	__imp__sub_827A9FB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9FCC) {
	__imp__sub_827A9FCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9FD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1812
	ctx.r5.s64 = r11.s64 + -1812;
	// addi r3,r10,-3424
	ctx.r3.s64 = ctx.r10.s64 + -3424;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9FD0) {
	__imp__sub_827A9FD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9FEC) {
	__imp__sub_827A9FEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1792
	ctx.r5.s64 = r11.s64 + -1792;
	// addi r3,r10,-3576
	ctx.r3.s64 = ctx.r10.s64 + -3576;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A9FF0) {
	__imp__sub_827A9FF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA00C) {
	__imp__sub_827AA00C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1784
	ctx.r5.s64 = r11.s64 + -1784;
	// addi r3,r10,-3176
	ctx.r3.s64 = ctx.r10.s64 + -3176;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA010) {
	__imp__sub_827AA010(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA02C) {
	__imp__sub_827AA02C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1768
	ctx.r5.s64 = r11.s64 + -1768;
	// addi r3,r10,-3292
	ctx.r3.s64 = ctx.r10.s64 + -3292;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA030) {
	__imp__sub_827AA030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA04C) {
	__imp__sub_827AA04C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1756
	ctx.r5.s64 = r11.s64 + -1756;
	// addi r3,r10,-3616
	ctx.r3.s64 = ctx.r10.s64 + -3616;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA050) {
	__imp__sub_827AA050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA06C) {
	__imp__sub_827AA06C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1740
	ctx.r5.s64 = r11.s64 + -1740;
	// addi r3,r10,-3444
	ctx.r3.s64 = ctx.r10.s64 + -3444;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA070) {
	__imp__sub_827AA070(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA08C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA08C) {
	__imp__sub_827AA08C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1724
	ctx.r5.s64 = r11.s64 + -1724;
	// addi r3,r10,-3272
	ctx.r3.s64 = ctx.r10.s64 + -3272;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA090) {
	__imp__sub_827AA090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA0AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA0AC) {
	__imp__sub_827AA0AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA0B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1712
	ctx.r5.s64 = r11.s64 + -1712;
	// addi r3,r10,-3596
	ctx.r3.s64 = ctx.r10.s64 + -3596;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA0B0) {
	__imp__sub_827AA0B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA0CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA0CC) {
	__imp__sub_827AA0CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA0D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1704
	ctx.r5.s64 = r11.s64 + -1704;
	// addi r3,r10,-3116
	ctx.r3.s64 = ctx.r10.s64 + -3116;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA0D0) {
	__imp__sub_827AA0D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA0EC) {
	__imp__sub_827AA0EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA0F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1692
	ctx.r5.s64 = r11.s64 + -1692;
	// addi r3,r10,-3136
	ctx.r3.s64 = ctx.r10.s64 + -3136;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA0F0) {
	__imp__sub_827AA0F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA10C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA10C) {
	__imp__sub_827AA10C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1676
	ctx.r5.s64 = r11.s64 + -1676;
	// addi r3,r10,-3252
	ctx.r3.s64 = ctx.r10.s64 + -3252;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA110) {
	__imp__sub_827AA110(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA12C) {
	__imp__sub_827AA12C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1316
	ctx.r5.s64 = r11.s64 + -1316;
	// addi r3,r10,8632
	ctx.r3.s64 = ctx.r10.s64 + 8632;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA130) {
	__imp__sub_827AA130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA14C) {
	__imp__sub_827AA14C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA150) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-2984
	ctx.r3.s64 = r11.s64 + -2984;
	// bl 0x82489428
	ctx.lr = 0x827AA168;
	sub_82489428(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29512
	ctx.r3.s64 = ctx.r10.s64 + -29512;
	// bl 0x823d9a98
	ctx.lr = 0x827AA174;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827AA150) {
	__imp__sub_827AA150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA184) {
	__imp__sub_827AA184(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA188) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,8796
	r30.s64 = r31.s64 + 8796;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-952
	ctx.r5.s64 = ctx.r10.s64 + -952;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA1C0;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8796(r31)
	PPC_STORE_U32(r31.u32 + 8796, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA1D0;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA1D8;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-956
	r11.s64 = r11.s64 + -956;
	// addi r3,r9,-29480
	ctx.r3.s64 = ctx.r9.s64 + -29480;
	// stw r11,8796(r31)
	PPC_STORE_U32(r31.u32 + 8796, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA1F0;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA188) {
	__imp__sub_827AA188(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA208) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,8828
	r30.s64 = r31.s64 + 8828;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-928
	ctx.r5.s64 = ctx.r10.s64 + -928;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA240;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA250;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA258;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-932
	r11.s64 = r11.s64 + -932;
	// addi r3,r9,-29392
	ctx.r3.s64 = ctx.r9.s64 + -29392;
	// stw r11,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA270;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA208) {
	__imp__sub_827AA208(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA288) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,8860
	r30.s64 = r31.s64 + 8860;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-900
	ctx.r5.s64 = ctx.r10.s64 + -900;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA2C0;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8860(r31)
	PPC_STORE_U32(r31.u32 + 8860, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA2D0;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA2D8;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-904
	r11.s64 = r11.s64 + -904;
	// addi r3,r9,-29304
	ctx.r3.s64 = ctx.r9.s64 + -29304;
	// stw r11,8860(r31)
	PPC_STORE_U32(r31.u32 + 8860, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA2F0;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA288) {
	__imp__sub_827AA288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r10,9000
	ctx.r3.s64 = ctx.r10.s64 + 9000;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82293e30
	sub_82293E30(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA308) {
	__imp__sub_827AA308(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA31C) {
	__imp__sub_827AA31C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,836
	ctx.r5.s64 = r11.s64 + 836;
	// addi r3,r10,9028
	ctx.r3.s64 = ctx.r10.s64 + 9028;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA320) {
	__imp__sub_827AA320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA33C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA33C) {
	__imp__sub_827AA33C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA340) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,860
	ctx.r5.s64 = r11.s64 + 860;
	// addi r3,r10,8980
	ctx.r3.s64 = ctx.r10.s64 + 8980;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA340) {
	__imp__sub_827AA340(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA35C) {
	__imp__sub_827AA35C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA360) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,888
	ctx.r5.s64 = r11.s64 + 888;
	// addi r3,r10,9048
	ctx.r3.s64 = ctx.r10.s64 + 9048;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA360) {
	__imp__sub_827AA360(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA37C) {
	__imp__sub_827AA37C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA380) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,908
	ctx.r5.s64 = r11.s64 + 908;
	// addi r3,r10,9008
	ctx.r3.s64 = ctx.r10.s64 + 9008;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA380) {
	__imp__sub_827AA380(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA39C) {
	__imp__sub_827AA39C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA3A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,928
	ctx.r5.s64 = r11.s64 + 928;
	// addi r3,r10,8960
	ctx.r3.s64 = ctx.r10.s64 + 8960;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA3A0) {
	__imp__sub_827AA3A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA3BC) {
	__imp__sub_827AA3BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA3C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// b 0x82293e18
	sub_82293E18(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA3C0) {
	__imp__sub_827AA3C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA3CC) {
	__imp__sub_827AA3CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA3D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29176
	ctx.r3.s64 = r11.s64 + -29176;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AA3D0) {
	__imp__sub_827AA3D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AA3DC) {
	__imp__sub_827AA3DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA3E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,15992
	r30.s64 = r31.s64 + 15992;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11632
	ctx.r5.s64 = ctx.r10.s64 + 11632;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA418;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,15992(r31)
	PPC_STORE_U32(r31.u32 + 15992, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA428;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA430;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11628
	r11.s64 = r11.s64 + 11628;
	// addi r3,r9,-29168
	ctx.r3.s64 = ctx.r9.s64 + -29168;
	// stw r11,15992(r31)
	PPC_STORE_U32(r31.u32 + 15992, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA448;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA3E0) {
	__imp__sub_827AA3E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA460) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16088
	r30.s64 = r31.s64 + 16088;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11664
	ctx.r5.s64 = ctx.r10.s64 + 11664;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA498;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16088(r31)
	PPC_STORE_U32(r31.u32 + 16088, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA4A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA4B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11660
	r11.s64 = r11.s64 + 11660;
	// addi r3,r9,-29080
	ctx.r3.s64 = ctx.r9.s64 + -29080;
	// stw r11,16088(r31)
	PPC_STORE_U32(r31.u32 + 16088, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA4C8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA460) {
	__imp__sub_827AA460(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA4E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16376
	r30.s64 = r31.s64 + 16376;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11704
	ctx.r5.s64 = ctx.r10.s64 + 11704;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA518;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16376(r31)
	PPC_STORE_U32(r31.u32 + 16376, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA528;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA530;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11700
	r11.s64 = r11.s64 + 11700;
	// addi r3,r9,-28992
	ctx.r3.s64 = ctx.r9.s64 + -28992;
	// stw r11,16376(r31)
	PPC_STORE_U32(r31.u32 + 16376, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA548;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA4E0) {
	__imp__sub_827AA4E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA560) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16664
	r30.s64 = r31.s64 + 16664;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11732
	ctx.r5.s64 = ctx.r10.s64 + 11732;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA598;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16664(r31)
	PPC_STORE_U32(r31.u32 + 16664, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA5A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA5B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11728
	r11.s64 = r11.s64 + 11728;
	// addi r3,r9,-28904
	ctx.r3.s64 = ctx.r9.s64 + -28904;
	// stw r11,16664(r31)
	PPC_STORE_U32(r31.u32 + 16664, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA5C8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA560) {
	__imp__sub_827AA560(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA5E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16312
	r30.s64 = r31.s64 + 16312;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11760
	ctx.r5.s64 = ctx.r10.s64 + 11760;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA618;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16312(r31)
	PPC_STORE_U32(r31.u32 + 16312, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA628;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA630;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11756
	r11.s64 = r11.s64 + 11756;
	// addi r3,r9,-28816
	ctx.r3.s64 = ctx.r9.s64 + -28816;
	// stw r11,16312(r31)
	PPC_STORE_U32(r31.u32 + 16312, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA648;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA5E0) {
	__imp__sub_827AA5E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA660) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16536
	r30.s64 = r31.s64 + 16536;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11796
	ctx.r5.s64 = ctx.r10.s64 + 11796;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA698;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16536(r31)
	PPC_STORE_U32(r31.u32 + 16536, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA6A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA6B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11792
	r11.s64 = r11.s64 + 11792;
	// addi r3,r9,-28728
	ctx.r3.s64 = ctx.r9.s64 + -28728;
	// stw r11,16536(r31)
	PPC_STORE_U32(r31.u32 + 16536, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA6C8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA660) {
	__imp__sub_827AA660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA6E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16600
	r30.s64 = r31.s64 + 16600;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11828
	ctx.r5.s64 = ctx.r10.s64 + 11828;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA718;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16600(r31)
	PPC_STORE_U32(r31.u32 + 16600, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA728;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA730;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11824
	r11.s64 = r11.s64 + 11824;
	// addi r3,r9,-28640
	ctx.r3.s64 = ctx.r9.s64 + -28640;
	// stw r11,16600(r31)
	PPC_STORE_U32(r31.u32 + 16600, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA748;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA6E0) {
	__imp__sub_827AA6E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA760) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16152
	r30.s64 = r31.s64 + 16152;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11852
	ctx.r5.s64 = ctx.r10.s64 + 11852;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA798;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16152(r31)
	PPC_STORE_U32(r31.u32 + 16152, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA7A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA7B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11848
	r11.s64 = r11.s64 + 11848;
	// addi r3,r9,-28552
	ctx.r3.s64 = ctx.r9.s64 + -28552;
	// stw r11,16152(r31)
	PPC_STORE_U32(r31.u32 + 16152, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA7C8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA760) {
	__imp__sub_827AA760(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA7E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16408
	r30.s64 = r31.s64 + 16408;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11880
	ctx.r5.s64 = ctx.r10.s64 + 11880;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA818;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16408(r31)
	PPC_STORE_U32(r31.u32 + 16408, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA828;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA830;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11876
	r11.s64 = r11.s64 + 11876;
	// addi r3,r9,-28464
	ctx.r3.s64 = ctx.r9.s64 + -28464;
	// stw r11,16408(r31)
	PPC_STORE_U32(r31.u32 + 16408, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA848;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA7E0) {
	__imp__sub_827AA7E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA860) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16280
	r30.s64 = r31.s64 + 16280;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11904
	ctx.r5.s64 = ctx.r10.s64 + 11904;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA898;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16280(r31)
	PPC_STORE_U32(r31.u32 + 16280, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA8A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA8B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11900
	r11.s64 = r11.s64 + 11900;
	// addi r3,r9,-28376
	ctx.r3.s64 = ctx.r9.s64 + -28376;
	// stw r11,16280(r31)
	PPC_STORE_U32(r31.u32 + 16280, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA8C8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA860) {
	__imp__sub_827AA860(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA8E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16568
	r30.s64 = r31.s64 + 16568;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11928
	ctx.r5.s64 = ctx.r10.s64 + 11928;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA918;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16568(r31)
	PPC_STORE_U32(r31.u32 + 16568, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA928;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA930;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11924
	r11.s64 = r11.s64 + 11924;
	// addi r3,r9,-28288
	ctx.r3.s64 = ctx.r9.s64 + -28288;
	// stw r11,16568(r31)
	PPC_STORE_U32(r31.u32 + 16568, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA948;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA8E0) {
	__imp__sub_827AA8E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA960) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16216
	r30.s64 = r31.s64 + 16216;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13380
	ctx.r5.s64 = ctx.r10.s64 + -13380;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA998;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16216(r31)
	PPC_STORE_U32(r31.u32 + 16216, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA9A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA9B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11948
	r11.s64 = r11.s64 + 11948;
	// addi r3,r9,-28200
	ctx.r3.s64 = ctx.r9.s64 + -28200;
	// stw r11,16216(r31)
	PPC_STORE_U32(r31.u32 + 16216, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA9C8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA960) {
	__imp__sub_827AA960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AA9E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16440
	r30.s64 = r31.s64 + 16440;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13364
	ctx.r5.s64 = ctx.r10.s64 + -13364;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAA18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16440(r31)
	PPC_STORE_U32(r31.u32 + 16440, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAA28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAA30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11956
	r11.s64 = r11.s64 + 11956;
	// addi r3,r9,-28112
	ctx.r3.s64 = ctx.r9.s64 + -28112;
	// stw r11,16440(r31)
	PPC_STORE_U32(r31.u32 + 16440, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAA48;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AA9E0) {
	__imp__sub_827AA9E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAA60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16056
	r30.s64 = r31.s64 + 16056;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13348
	ctx.r5.s64 = ctx.r10.s64 + -13348;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAA98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16056(r31)
	PPC_STORE_U32(r31.u32 + 16056, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAAA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAAB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11964
	r11.s64 = r11.s64 + 11964;
	// addi r3,r9,-28024
	ctx.r3.s64 = ctx.r9.s64 + -28024;
	// stw r11,16056(r31)
	PPC_STORE_U32(r31.u32 + 16056, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAAC8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAA60) {
	__imp__sub_827AAA60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAAE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16472
	r30.s64 = r31.s64 + 16472;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13336
	ctx.r5.s64 = ctx.r10.s64 + -13336;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAB18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16472(r31)
	PPC_STORE_U32(r31.u32 + 16472, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAB28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAB30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11972
	r11.s64 = r11.s64 + 11972;
	// addi r3,r9,-27936
	ctx.r3.s64 = ctx.r9.s64 + -27936;
	// stw r11,16472(r31)
	PPC_STORE_U32(r31.u32 + 16472, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAB48;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAAE0) {
	__imp__sub_827AAAE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAB60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16120
	r30.s64 = r31.s64 + 16120;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11984
	ctx.r5.s64 = ctx.r10.s64 + 11984;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAB98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16120(r31)
	PPC_STORE_U32(r31.u32 + 16120, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AABA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AABB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11980
	r11.s64 = r11.s64 + 11980;
	// addi r3,r9,-27848
	ctx.r3.s64 = ctx.r9.s64 + -27848;
	// stw r11,16120(r31)
	PPC_STORE_U32(r31.u32 + 16120, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AABC8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAB60) {
	__imp__sub_827AAB60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AABE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16696
	r30.s64 = r31.s64 + 16696;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12016
	ctx.r5.s64 = ctx.r10.s64 + 12016;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAC18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16696(r31)
	PPC_STORE_U32(r31.u32 + 16696, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAC28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAC30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12012
	r11.s64 = r11.s64 + 12012;
	// addi r3,r9,-27760
	ctx.r3.s64 = ctx.r9.s64 + -27760;
	// stw r11,16696(r31)
	PPC_STORE_U32(r31.u32 + 16696, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAC48;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AABE0) {
	__imp__sub_827AABE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAC60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16184
	r30.s64 = r31.s64 + 16184;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13320
	ctx.r5.s64 = ctx.r10.s64 + -13320;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAC98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16184(r31)
	PPC_STORE_U32(r31.u32 + 16184, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AACA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AACB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12048
	r11.s64 = r11.s64 + 12048;
	// addi r3,r9,-27672
	ctx.r3.s64 = ctx.r9.s64 + -27672;
	// stw r11,16184(r31)
	PPC_STORE_U32(r31.u32 + 16184, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AACC8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAC60) {
	__imp__sub_827AAC60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AACE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16248
	r30.s64 = r31.s64 + 16248;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12060
	ctx.r5.s64 = ctx.r10.s64 + 12060;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAD18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16248(r31)
	PPC_STORE_U32(r31.u32 + 16248, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAD28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAD30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12056
	r11.s64 = r11.s64 + 12056;
	// addi r3,r9,-27584
	ctx.r3.s64 = ctx.r9.s64 + -27584;
	// stw r11,16248(r31)
	PPC_STORE_U32(r31.u32 + 16248, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAD48;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AACE0) {
	__imp__sub_827AACE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAD60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16792
	r30.s64 = r31.s64 + 16792;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12084
	ctx.r5.s64 = ctx.r10.s64 + 12084;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAD98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16792(r31)
	PPC_STORE_U32(r31.u32 + 16792, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AADA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AADB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12080
	r11.s64 = r11.s64 + 12080;
	// addi r3,r9,-27496
	ctx.r3.s64 = ctx.r9.s64 + -27496;
	// stw r11,16792(r31)
	PPC_STORE_U32(r31.u32 + 16792, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AADC8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAD60) {
	__imp__sub_827AAD60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AADE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16344
	r30.s64 = r31.s64 + 16344;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12112
	ctx.r5.s64 = ctx.r10.s64 + 12112;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAE18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16344(r31)
	PPC_STORE_U32(r31.u32 + 16344, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAE28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAE30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12108
	r11.s64 = r11.s64 + 12108;
	// addi r3,r9,-27408
	ctx.r3.s64 = ctx.r9.s64 + -27408;
	// stw r11,16344(r31)
	PPC_STORE_U32(r31.u32 + 16344, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAE48;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AADE0) {
	__imp__sub_827AADE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAE60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16504
	r30.s64 = r31.s64 + 16504;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12136
	ctx.r5.s64 = ctx.r10.s64 + 12136;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAE98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16504(r31)
	PPC_STORE_U32(r31.u32 + 16504, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAEA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAEB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12132
	r11.s64 = r11.s64 + 12132;
	// addi r3,r9,-27320
	ctx.r3.s64 = ctx.r9.s64 + -27320;
	// stw r11,16504(r31)
	PPC_STORE_U32(r31.u32 + 16504, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAEC8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAE60) {
	__imp__sub_827AAE60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAEE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16024
	r30.s64 = r31.s64 + 16024;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12156
	ctx.r5.s64 = ctx.r10.s64 + 12156;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAF18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16024(r31)
	PPC_STORE_U32(r31.u32 + 16024, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAF28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAF30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12152
	r11.s64 = r11.s64 + 12152;
	// addi r3,r9,-27232
	ctx.r3.s64 = ctx.r9.s64 + -27232;
	// stw r11,16024(r31)
	PPC_STORE_U32(r31.u32 + 16024, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAF48;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAEE0) {
	__imp__sub_827AAEE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAF60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16760
	r30.s64 = r31.s64 + 16760;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12176
	ctx.r5.s64 = ctx.r10.s64 + 12176;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAF98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16760(r31)
	PPC_STORE_U32(r31.u32 + 16760, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAFA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAFB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12172
	r11.s64 = r11.s64 + 12172;
	// addi r3,r9,-27144
	ctx.r3.s64 = ctx.r9.s64 + -27144;
	// stw r11,16760(r31)
	PPC_STORE_U32(r31.u32 + 16760, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAFC8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAF60) {
	__imp__sub_827AAF60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AAFE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16728
	r30.s64 = r31.s64 + 16728;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12192
	ctx.r5.s64 = ctx.r10.s64 + 12192;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB018;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16728(r31)
	PPC_STORE_U32(r31.u32 + 16728, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB028;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB030;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12188
	r11.s64 = r11.s64 + 12188;
	// addi r3,r9,-27056
	ctx.r3.s64 = ctx.r9.s64 + -27056;
	// stw r11,16728(r31)
	PPC_STORE_U32(r31.u32 + 16728, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB048;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AAFE0) {
	__imp__sub_827AAFE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB060) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16632
	r30.s64 = r31.s64 + 16632;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12212
	ctx.r5.s64 = ctx.r10.s64 + 12212;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB098;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16632(r31)
	PPC_STORE_U32(r31.u32 + 16632, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB0A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB0B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12208
	r11.s64 = r11.s64 + 12208;
	// addi r3,r9,-26968
	ctx.r3.s64 = ctx.r9.s64 + -26968;
	// stw r11,16632(r31)
	PPC_STORE_U32(r31.u32 + 16632, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB0C8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AB060) {
	__imp__sub_827AB060(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB0E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4760
	ctx.r7.s64 = ctx.r8.s64 + -4760;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827AB0E0) {
	__imp__sub_827AB0E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4752
	ctx.r7.s64 = ctx.r8.s64 + -4752;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827AB100) {
	__imp__sub_827AB100(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB120) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4744
	ctx.r7.s64 = ctx.r8.s64 + -4744;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827AB120) {
	__imp__sub_827AB120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB140) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4736
	ctx.r7.s64 = ctx.r8.s64 + -4736;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827AB140) {
	__imp__sub_827AB140(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4728
	ctx.r7.s64 = ctx.r8.s64 + -4728;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827AB160) {
	__imp__sub_827AB160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB180) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16844
	r30.s64 = r31.s64 + 16844;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,14260
	ctx.r5.s64 = ctx.r10.s64 + 14260;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB1B8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16844(r31)
	PPC_STORE_U32(r31.u32 + 16844, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB1C8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB1D0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,14256
	r11.s64 = r11.s64 + 14256;
	// addi r3,r9,-26880
	ctx.r3.s64 = ctx.r9.s64 + -26880;
	// stw r11,16844(r31)
	PPC_STORE_U32(r31.u32 + 16844, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB1E8;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AB180) {
	__imp__sub_827AB180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,16376
	ctx.r5.s64 = r11.s64 + 16376;
	// addi r3,r10,16876
	ctx.r3.s64 = ctx.r10.s64 + 16876;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB200) {
	__imp__sub_827AB200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB21C) {
	__imp__sub_827AB21C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB220) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16896
	r30.s64 = r31.s64 + 16896;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,16360
	ctx.r5.s64 = ctx.r10.s64 + 16360;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB258;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16896(r31)
	PPC_STORE_U32(r31.u32 + 16896, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB268;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB270;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,16356
	r11.s64 = r11.s64 + 16356;
	// addi r3,r9,-26792
	ctx.r3.s64 = ctx.r9.s64 + -26792;
	// stw r11,16896(r31)
	PPC_STORE_U32(r31.u32 + 16896, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB288;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AB220) {
	__imp__sub_827AB220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB2A0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16928
	r30.s64 = r31.s64 + 16928;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17264
	ctx.r5.s64 = ctx.r10.s64 + 17264;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB2D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16928(r31)
	PPC_STORE_U32(r31.u32 + 16928, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB2E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB2F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17260
	r11.s64 = r11.s64 + 17260;
	// addi r3,r9,-26704
	ctx.r3.s64 = ctx.r9.s64 + -26704;
	// stw r11,16928(r31)
	PPC_STORE_U32(r31.u32 + 16928, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB308;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AB2A0) {
	__imp__sub_827AB2A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB320) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16960
	r30.s64 = r31.s64 + 16960;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17296
	ctx.r5.s64 = ctx.r10.s64 + 17296;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB358;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16960(r31)
	PPC_STORE_U32(r31.u32 + 16960, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB368;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB370;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17292
	r11.s64 = r11.s64 + 17292;
	// addi r3,r9,-26616
	ctx.r3.s64 = ctx.r9.s64 + -26616;
	// stw r11,16960(r31)
	PPC_STORE_U32(r31.u32 + 16960, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB388;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AB320) {
	__imp__sub_827AB320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB3A0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,17024
	r30.s64 = r31.s64 + 17024;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17632
	ctx.r5.s64 = ctx.r10.s64 + 17632;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB3D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,17024(r31)
	PPC_STORE_U32(r31.u32 + 17024, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB3E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB3F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17628
	r11.s64 = r11.s64 + 17628;
	// addi r3,r9,-26528
	ctx.r3.s64 = ctx.r9.s64 + -26528;
	// stw r11,17024(r31)
	PPC_STORE_U32(r31.u32 + 17024, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB408;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AB3A0) {
	__imp__sub_827AB3A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB420) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16992
	r30.s64 = r31.s64 + 16992;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17680
	ctx.r5.s64 = ctx.r10.s64 + 17680;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB458;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16992(r31)
	PPC_STORE_U32(r31.u32 + 16992, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB468;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB470;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17676
	r11.s64 = r11.s64 + 17676;
	// addi r3,r9,-26440
	ctx.r3.s64 = ctx.r9.s64 + -26440;
	// stw r11,16992(r31)
	PPC_STORE_U32(r31.u32 + 16992, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB488;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AB420) {
	__imp__sub_827AB420(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB4A0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,17056
	r30.s64 = r31.s64 + 17056;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17724
	ctx.r5.s64 = ctx.r10.s64 + 17724;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB4D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,17056(r31)
	PPC_STORE_U32(r31.u32 + 17056, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB4E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB4F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17720
	r11.s64 = r11.s64 + 17720;
	// addi r3,r9,-26352
	ctx.r3.s64 = ctx.r9.s64 + -26352;
	// stw r11,17056(r31)
	PPC_STORE_U32(r31.u32 + 17056, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB508;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827AB4A0) {
	__imp__sub_827AB4A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,19860
	ctx.r5.s64 = r11.s64 + 19860;
	// addi r3,r10,17124
	ctx.r3.s64 = ctx.r10.s64 + 17124;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB520) {
	__imp__sub_827AB520(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB53C) {
	__imp__sub_827AB53C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,21608
	ctx.r5.s64 = r11.s64 + 21608;
	// addi r3,r10,17236
	ctx.r3.s64 = ctx.r10.s64 + 17236;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB540) {
	__imp__sub_827AB540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB55C) {
	__imp__sub_827AB55C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,21620
	ctx.r5.s64 = r11.s64 + 21620;
	// addi r3,r10,17216
	ctx.r3.s64 = ctx.r10.s64 + 17216;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB560) {
	__imp__sub_827AB560(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB57C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB57C) {
	__imp__sub_827AB57C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,21636
	ctx.r5.s64 = r11.s64 + 21636;
	// addi r3,r10,17196
	ctx.r3.s64 = ctx.r10.s64 + 17196;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB580) {
	__imp__sub_827AB580(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB59C) {
	__imp__sub_827AB59C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB5A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,22088
	ctx.r5.s64 = r11.s64 + 22088;
	// addi r3,r10,17272
	ctx.r3.s64 = ctx.r10.s64 + 17272;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB5A0) {
	__imp__sub_827AB5A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB5BC) {
	__imp__sub_827AB5BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB5C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,22416
	ctx.r5.s64 = r11.s64 + 22416;
	// addi r3,r10,17300
	ctx.r3.s64 = ctx.r10.s64 + 17300;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB5C0) {
	__imp__sub_827AB5C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB5DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB5DC) {
	__imp__sub_827AB5DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB5E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23504
	ctx.r5.s64 = r11.s64 + 23504;
	// addi r3,r10,17392
	ctx.r3.s64 = ctx.r10.s64 + 17392;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB5E0) {
	__imp__sub_827AB5E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB5FC) {
	__imp__sub_827AB5FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB600) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23516
	ctx.r5.s64 = r11.s64 + 23516;
	// addi r3,r10,17352
	ctx.r3.s64 = ctx.r10.s64 + 17352;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB600) {
	__imp__sub_827AB600(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB61C) {
	__imp__sub_827AB61C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23528
	ctx.r5.s64 = r11.s64 + 23528;
	// addi r3,r10,17372
	ctx.r3.s64 = ctx.r10.s64 + 17372;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB620) {
	__imp__sub_827AB620(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB63C) {
	__imp__sub_827AB63C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23540
	ctx.r5.s64 = r11.s64 + 23540;
	// addi r3,r10,17412
	ctx.r3.s64 = ctx.r10.s64 + 17412;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB640) {
	__imp__sub_827AB640(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB65C) {
	__imp__sub_827AB65C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23552
	ctx.r5.s64 = r11.s64 + 23552;
	// addi r3,r10,17332
	ctx.r3.s64 = ctx.r10.s64 + 17332;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB660) {
	__imp__sub_827AB660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB67C) {
	__imp__sub_827AB67C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29248
	ctx.r5.s64 = r11.s64 + 29248;
	// addi r3,r10,17708
	ctx.r3.s64 = ctx.r10.s64 + 17708;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB680) {
	__imp__sub_827AB680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB69C) {
	__imp__sub_827AB69C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB6A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29264
	ctx.r5.s64 = r11.s64 + 29264;
	// addi r3,r10,17492
	ctx.r3.s64 = ctx.r10.s64 + 17492;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB6A0) {
	__imp__sub_827AB6A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB6BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827AB6BC) {
	__imp__sub_827AB6BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827AB6C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29288
	ctx.r5.s64 = r11.s64 + 29288;
	// addi r3,r10,17572
	ctx.r3.s64 = ctx.r10.s64 + 17572;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827AB6C0) {
	__imp__sub_827AB6C0(ctx, base);
}

