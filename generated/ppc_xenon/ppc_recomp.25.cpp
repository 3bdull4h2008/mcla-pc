#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8220821C"))) PPC_WEAK_FUNC(sub_8220821C);
PPC_FUNC_IMPL(__imp__sub_8220821C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82208220"))) PPC_WEAK_FUNC(sub_82208220);
PPC_FUNC_IMPL(__imp__sub_82208220) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r31,-10236(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x825ef808
	ctx.lr = 0x82208240;
	sub_825EF808(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821f9288
	ctx.lr = 0x82208250;
	sub_821F9288(ctx, base);
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

__attribute__((alias("__imp__sub_82208264"))) PPC_WEAK_FUNC(sub_82208264);
PPC_FUNC_IMPL(__imp__sub_82208264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82208268"))) PPC_WEAK_FUNC(sub_82208268);
PPC_FUNC_IMPL(__imp__sub_82208268) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r31,-10236(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x825ef808
	ctx.lr = 0x82208288;
	sub_825EF808(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821f9288
	ctx.lr = 0x82208298;
	sub_821F9288(ctx, base);
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

__attribute__((alias("__imp__sub_822082AC"))) PPC_WEAK_FUNC(sub_822082AC);
PPC_FUNC_IMPL(__imp__sub_822082AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822082B0"))) PPC_WEAK_FUNC(sub_822082B0);
PPC_FUNC_IMPL(__imp__sub_822082B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r3,4897
	ctx.r9.s64 = ctx.r3.s64 + 4897;
	// li r8,4256
	ctx.r8.s64 = 4256;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,-10028(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// lvx128 v1,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r7,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82654548
	sub_82654548(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822082D8"))) PPC_WEAK_FUNC(sub_822082D8);
PPC_FUNC_IMPL(__imp__sub_822082D8) {
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
	// bl 0x823d91ec
	ctx.lr = 0x822082E0;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r30,0(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,-1680(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -1680);
	// bl 0x821c9790
	ctx.lr = 0x822082FC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8220830C;
	sub_825ED480(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x82208314;
	sub_825EF9F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,7
	r11.s64 = 7;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// addi r27,r9,-18184
	r27.s64 = ctx.r9.s64 + -18184;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x82722440
	ctx.lr = 0x82208348;
	sub_82722440(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r26,r8,-13136
	r26.s64 = ctx.r8.s64 + -13136;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82722440
	ctx.lr = 0x82208360;
	sub_82722440(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r25,r7,-13144
	r25.s64 = ctx.r7.s64 + -13144;
	// stw r25,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r25.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9790
	ctx.lr = 0x82208378;
	sub_821C9790(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r31,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r11,36(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822083A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-12420
	ctx.r3.s64 = ctx.r10.s64 + -12420;
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x822083B4;
	sub_821C9790(ctx, base);
	// stw r3,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822083D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822083E8;
	sub_822A3998(ctx, base);
	// lwz r30,880(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822afa10
	ctx.lr = 0x822083F4;
	sub_822AFA10(ctx, base);
	// addi r6,r3,48
	ctx.r6.s64 = ctx.r3.s64 + 48;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822afa10
	ctx.lr = 0x8220840C;
	sub_822AFA10(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,92
	ctx.r10.s64 = ctx.r1.s64 + 92;
	// addi r9,r3,32
	ctx.r9.s64 = ctx.r3.s64 + 32;
	// lfs f0,32308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32308);
	f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vspltw128 v0,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v13,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822afa30
	ctx.lr = 0x82208448;
	sub_822AFA30(ctx, base);
	// li r7,4
	ctx.r7.s64 = 4;
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r30,-10236(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10236);
	// bl 0x825ef808
	ctx.lr = 0x82208464;
	sub_825EF808(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f9248
	ctx.lr = 0x82208470;
	sub_821F9248(ctx, base);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// li r4,32
	ctx.r4.s64 = 32;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// lvx128 v62,r3,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// lvx128 v60,r3,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// lvx128 v61,r3,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821713c0
	ctx.lr = 0x822084D8;
	sub_821713C0(ctx, base);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r6,r9,2384
	ctx.r6.s64 = ctx.r9.s64 + 2384;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r5,2352
	ctx.r10.s64 = ctx.r5.s64 + 2352;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// vand128 v59,v61,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v58,v60,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// vor128 v57,v62,v59
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// vor128 v56,v62,v58
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v55,v61,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v61,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v53,v63,v62
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrglw128 v52,v63,v62
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrglw128 v51,v53,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v50,v53,v55
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v49,v52,v54
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrglw128 v48,v53,v55
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v47,v53,v55
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmsum4fp128 v46,v57,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmsum4fp128 v45,v57,v50
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmsum4fp128 v44,v57,v49
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmrghw128 v40,v46,v57
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmsum4fp128 v43,v56,v48
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v48.f32), 0xFF));
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// vmsum4fp128 v42,v56,v49
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmsum4fp128 v41,v56,v47
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v47.f32), 0xFF));
	// vmrghw128 v39,v45,v44
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v38,v43,v56
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v37,v41,v42
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v36,v39,v40
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrghw128 v35,v37,v38
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// stvx128 v36,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82722860
	ctx.lr = 0x822085A4;
	sub_82722860(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82722860
	ctx.lr = 0x822085B4;
	sub_82722860(ctx, base);
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r25.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x822085C4;
	sub_821C9790(ctx, base);
	// stw r3,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
	// stw r31,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822085E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822085F0"))) PPC_WEAK_FUNC(sub_822085F0);
PPC_FUNC_IMPL(__imp__sub_822085F0) {
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
	ctx.lr = 0x822085F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-21276(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21276);
	// bl 0x821ca540
	ctx.lr = 0x82208618;
	sub_821CA540(ctx, base);
	// lis r29,-32119
	r29.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x82208628;
	sub_823058F8(ctx, base);
	// li r3,120
	ctx.r3.s64 = 120;
	// bl 0x82130528
	ctx.lr = 0x82208630;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82208648
	if (cr6.eq) goto loc_82208648;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r4,-21272(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21272);
	// bl 0x82698f60
	ctx.lr = 0x82208644;
	sub_82698F60(ctx, base);
	// b 0x8220864c
	goto loc_8220864C;
loc_82208648:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8220864C:
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r28,3600
	r28.s64 = r28.s64 + 3600;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x82208664;
	sub_82305870(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8220866C;
	sub_821C9A90(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,15480
	ctx.r4.s64 = r11.s64 + 15480;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82208688;
	sub_821C2FB0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r9,-12296
	ctx.r4.s64 = ctx.r9.s64 + -12296;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ld r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicr r7,r8,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// bl 0x82696dc0
	ctx.lr = 0x822086AC;
	sub_82696DC0(ctx, base);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,15608
	ctx.r4.s64 = ctx.r4.s64 + 15608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x822086C8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r10,-12308
	ctx.r4.s64 = ctx.r10.s64 + -12308;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r7,r9,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82696dc0
	ctx.lr = 0x822086EC;
	sub_82696DC0(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,15680
	ctx.r4.s64 = ctx.r8.s64 + 15680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82208708;
	sub_821C2FB0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r5,-12320
	ctx.r4.s64 = ctx.r5.s64 + -12320;
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// ld r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r6.u32 + 0);
	// rldicr r7,r11,32,63
	ctx.r7.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r6)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// bl 0x82696dc0
	ctx.lr = 0x8220872C;
	sub_82696DC0(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,15752
	ctx.r4.s64 = ctx.r10.s64 + 15752;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82208748;
	sub_821C2FB0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r8,-12336
	ctx.r4.s64 = ctx.r8.s64 + -12336;
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// rldicr r7,r7,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// bl 0x82696dc0
	ctx.lr = 0x8220876C;
	sub_82696DC0(ctx, base);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,15768
	ctx.r4.s64 = ctx.r4.s64 + 15768;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82208788;
	sub_821C2FB0(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// rldicr r7,r11,32,63
	ctx.r7.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r4,r10,-12344
	ctx.r4.s64 = ctx.r10.s64 + -12344;
	// ld r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82696dc0
	ctx.lr = 0x822087A8;
	sub_82696DC0(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,28632
	ctx.r4.s64 = ctx.r9.s64 + 28632;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x822087C4;
	sub_821C2FB0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r7,-12364
	ctx.r4.s64 = ctx.r7.s64 + -12364;
	// lwz r6,16(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// ld r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// rldicr r7,r6,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r8)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// bl 0x82696dc0
	ctx.lr = 0x822087E8;
	sub_82696DC0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82216880
	ctx.lr = 0x822087F0;
	sub_82216880(ctx, base);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82696c10
	ctx.lr = 0x822087F8;
	sub_82696C10(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82208800"))) PPC_WEAK_FUNC(sub_82208800);
PPC_FUNC_IMPL(__imp__sub_82208800) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82208808;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addis r26,r29,1
	r26.s64 = r29.s64 + 65536;
	// addi r26,r26,5960
	r26.s64 = r26.s64 + 5960;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// beq cr6,0x82208928
	if (cr6.eq) goto loc_82208928;
	// stfs f1,208(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,127
	ctx.r10.s64 = 127;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// subf r9,r10,r27
	ctx.r9.s64 = r27.s64 - ctx.r10.s64;
loc_82208840:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82208858
	if (cr6.eq) goto loc_82208858;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82208840
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82208840;
loc_82208858:
	// li r28,0
	r28.s64 = 0;
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,3912
	ctx.r3.s64 = ctx.r3.s64 + 3912;
	// bl 0x82204b10
	ctx.lr = 0x82208870;
	sub_82204B10(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82208890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addis r11,r29,1
	r11.s64 = r29.s64 + 65536;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r11,r11,6096
	r11.s64 = r11.s64 + 6096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r10,-12984
	r30.s64 = ctx.r10.s64 + -12984;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822088d8
	if (cr6.eq) goto loc_822088D8;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// ori r8,r10,6092
	ctx.r8.u64 = ctx.r10.u64 | 6092;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfsx f0,r29,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + ctx.r8.u32, temp.u32);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x822088D8;
	sub_825EE0E0(ctx, base);
loc_822088D8:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82208928
	if (!cr6.eq) goto loc_82208928;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r26,56(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822088F8;
	sub_82218310(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,-12968
	ctx.r4.s64 = ctx.r10.s64 + -12968;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8220890C;
	sub_825EE2D8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x8220891C;
	sub_825EE0E0(ctx, base);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,3628
	ctx.r8.u64 = ctx.r9.u64 | 3628;
	// stbx r28,r29,r8
	PPC_STORE_U8(r29.u32 + ctx.r8.u32, r28.u8);
loc_82208928:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82208930"))) PPC_WEAK_FUNC(sub_82208930);
PPC_FUNC_IMPL(__imp__sub_82208930) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82208938;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x82208968
	if (cr6.lt) goto loc_82208968;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bge cr6,0x8220896c
	if (!cr6.lt) goto loc_8220896C;
loc_82208968:
	// li r11,1
	r11.s64 = 1;
loc_8220896C:
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82208980
	if (cr6.eq) goto loc_82208980;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// b 0x82208990
	goto loc_82208990;
loc_82208980:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8220898C;
	sub_82218310(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82208990:
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// li r10,127
	ctx.r10.s64 = 127;
	// addi r11,r11,5964
	r11.s64 = r11.s64 + 5964;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r11,r30
	ctx.r9.s64 = r30.s64 - r11.s64;
loc_822089A4:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822089bc
	if (cr6.eq) goto loc_822089BC;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x822089a4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822089A4;
loc_822089BC:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r10,5960
	ctx.r8.u64 = ctx.r10.u64 | 5960;
	// ori r7,r9,6092
	ctx.r7.u64 = ctx.r9.u64 | 6092;
	// lwzx r6,r31,r8
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stfsx f31,r31,r7
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, temp.u32);
	// bne cr6,0x82208a48
	if (!cr6.eq) goto loc_82208A48;
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// ori r9,r11,6096
	ctx.r9.u64 = r11.u64 | 6096;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stbx r8,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, ctx.r8.u8);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82208A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-12984
	ctx.r4.s64 = ctx.r4.s64 + -12984;
	// lwz r3,56(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x82208A28;
	sub_825EE0E0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,-12968
	ctx.r4.s64 = r11.s64 + -12968;
	// bl 0x825ee2d8
	ctx.lr = 0x82208A3C;
	sub_825EE2D8(ctx, base);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,3628
	ctx.r9.u64 = ctx.r10.u64 | 3628;
	// stbx r29,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r29.u8);
loc_82208A48:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bne cr6,0x82208ad0
	if (!cr6.eq) goto loc_82208AD0;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-12272
	ctx.r4.s64 = r11.s64 + -12272;
	// lwz r31,-12440(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12440);
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x82208A74;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82208A88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r11,r28,8,0,23
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r9,-12280
	ctx.r4.s64 = ctx.r9.s64 + -12280;
	// li r6,0
	ctx.r6.s64 = 0;
	// add r5,r11,r26
	ctx.r5.u64 = r11.u64 + r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,-12440(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12440);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238da80
	ctx.lr = 0x82208AB0;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82208AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82208AD0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-12288
	ctx.r4.s64 = ctx.r10.s64 + -12288;
	// lwz r31,-12440(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x82208AE8;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,40(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82208AFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82208B08"))) PPC_WEAK_FUNC(sub_82208B08);
PPC_FUNC_IMPL(__imp__sub_82208B08) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82208B10;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-12248
	ctx.r4.s64 = ctx.r10.s64 + -12248;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82208B2C;
	sub_821F9FB8(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r30,r9,-12264
	r30.s64 = ctx.r9.s64 + -12264;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82208B48;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x82208B58;
	sub_825ED480(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82208f34
	if (cr6.eq) goto loc_82208F34;
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// lwz r25,188(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// lwz r24,124(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// lwz r23,220(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// lwz r22,156(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// addi r28,r28,15220
	r28.s64 = r28.s64 + 15220;
	// lwz r21,284(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// addi r30,r30,15816
	r30.s64 = r30.s64 + 15816;
	// lwz r20,92(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r29,0
	r29.s64 = 0;
	// lwz r19,252(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// addi r31,r31,12820
	r31.s64 = r31.s64 + 12820;
	// lwz r18,108(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r17,140(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r16,172(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lwz r15,204(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r14,236(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// b 0x82208bb8
	goto loc_82208BB8;
loc_82208BB4:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_82208BB8:
	// bl 0x825ef9f0
	ctx.lr = 0x82208BBC;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82208BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82208BD4;
	sub_825EF9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lfs f0,-4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	f0.f64 = double(temp.f32);
	// li r27,4
	r27.s64 = 4;
	// stfs f0,184(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,184(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r26,4
	r26.s64 = 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// stw r25,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r25.u32);
	// stw r27,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r27.u32);
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwz r10,80(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208C3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r24,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r24.u32);
	// stw r26,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r26.u32);
	// lfs f12,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f12,216(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208C78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,216(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// stw r23,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r23.u32);
	// stw r27,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r27.u32);
	// lfs f11,796(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 796);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bctrl 
	ctx.lr = 0x82208CB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,152(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// stw r22,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r22.u32);
	// stw r26,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r26.u32);
	// lfs f10,800(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 800);
	ctx.f10.f64 = double(temp.f32);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f10,280(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// lwz r10,80(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,280(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r21,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r21.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r27,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r27.u32);
	// lfs f9,804(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 804);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,88(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208D2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// stw r20,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r20.u32);
	// stw r26,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r26.u32);
	// lfs f8,1596(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1596);
	ctx.f8.f64 = double(temp.f32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f8,248(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bctrl 
	ctx.lr = 0x82208D68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,248(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// stw r19,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r19.u32);
	// stw r27,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r27.u32);
	// lfs f7,1600(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1600);
	ctx.f7.f64 = double(temp.f32);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r10,80(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208DA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r18,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r18.u32);
	// stw r26,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r26.u32);
	// lfs f6,1604(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1604);
	ctx.f6.f64 = double(temp.f32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f6,136(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,136(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// stw r17,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r17.u32);
	// stw r27,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r27.u32);
	// lfs f5,-200(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -200);
	ctx.f5.f64 = double(temp.f32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f5,168(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bctrl 
	ctx.lr = 0x82208E1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,168(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// stw r16,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r16.u32);
	// stw r26,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r26.u32);
	// lfs f4,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f4,200(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lwz r10,80(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208E58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,200(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r15,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r15.u32);
	// stw r27,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r27.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lfs f3,200(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 200);
	ctx.f3.f64 = double(temp.f32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f3,232(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bctrl 
	ctx.lr = 0x82208E94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,232(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// stw r14,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r14.u32);
	// stw r26,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r26.u32);
	// lfs f2,-4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -4);
	ctx.f2.f64 = double(temp.f32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f2,264(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bctrl 
	ctx.lr = 0x82208ED0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,264(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r6,268(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r27.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stfs f1,296(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// lwz r11,80(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82208F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,296(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	// lwz r9,300(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r29,20
	cr6.compare<int32_t>(r29.s32, 20, xer);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// blt cr6,0x82208bb4
	if (cr6.lt) goto loc_82208BB4;
loc_82208F34:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82208F3C"))) PPC_WEAK_FUNC(sub_82208F3C);
PPC_FUNC_IMPL(__imp__sub_82208F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82208F40"))) PPC_WEAK_FUNC(sub_82208F40);
PPC_FUNC_IMPL(__imp__sub_82208F40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826947a0
	ctx.lr = 0x82208F6C;
	sub_826947A0(ctx, base);
	// bl 0x823de058
	ctx.lr = 0x82208F70;
	sub_823DE058(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// bl 0x826947a0
	ctx.lr = 0x82208F80;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82208800
	ctx.lr = 0x82208F90;
	sub_82208800(ctx, base);
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

__attribute__((alias("__imp__sub_82208FAC"))) PPC_WEAK_FUNC(sub_82208FAC);
PPC_FUNC_IMPL(__imp__sub_82208FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82208FB0"))) PPC_WEAK_FUNC(sub_82208FB0);
PPC_FUNC_IMPL(__imp__sub_82208FB0) {
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
	ctx.lr = 0x82208FB8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826947a0
	ctx.lr = 0x82208FD0;
	sub_826947A0(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// ori r10,r11,3600
	ctx.r10.u64 = r11.u64 | 3600;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// bl 0x82695c78
	ctx.lr = 0x82208FE4;
	sub_82695C78(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r8,-12176
	ctx.r4.s64 = ctx.r8.s64 + -12176;
	// lwz r31,-10236(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// bl 0x82694ff0
	ctx.lr = 0x82208FFC;
	sub_82694FF0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82209008;
	sub_821F9FB8(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r7,-12184
	r11.s64 = ctx.r7.s64 + -12184;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82209020:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x82209020
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82209020;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,-12196
	ctx.r4.s64 = r11.s64 + -12196;
	// bl 0x82694ff0
	ctx.lr = 0x82209044;
	sub_82694FF0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82209048;
	sub_823DD7F0(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r10,-12204
	ctx.r5.s64 = ctx.r10.s64 + -12204;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82209064;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r30,56(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x826947a0
	ctx.lr = 0x82209074;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82209078;
	sub_823DD7F0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-12220
	ctx.r4.s64 = ctx.r9.s64 + -12220;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8220908C;
	sub_825EE0E0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10244(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8220909C;
	sub_82218310(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r7,-12236
	ctx.r4.s64 = ctx.r7.s64 + -12236;
	// bl 0x825ee2d8
	ctx.lr = 0x822090B0;
	sub_825EE2D8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822090B8"))) PPC_WEAK_FUNC(sub_822090B8);
PPC_FUNC_IMPL(__imp__sub_822090B8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-21704
	ctx.r4.s64 = ctx.r10.s64 + -21704;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x822090E8;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,312(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822090F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82209134
	if (!cr6.eq) goto loc_82209134;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-12168
	ctx.r4.s64 = r11.s64 + -12168;
	// bl 0x82691650
	ctx.lr = 0x82209114;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82209124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82209138
	if (cr6.eq) goto loc_82209138;
loc_82209134:
	// li r11,1
	r11.s64 = 1;
loc_82209138:
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

__attribute__((alias("__imp__sub_82209150"))) PPC_WEAK_FUNC(sub_82209150);
PPC_FUNC_IMPL(__imp__sub_82209150) {
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
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cc8
	ctx.lr = 0x82209174;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822091a0
	if (cr6.eq) goto loc_822091A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220918C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822091a0
	if (cr6.eq) goto loc_822091A0;
loc_82209198:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82209240
	goto loc_82209240;
loc_822091A0:
	// lis r11,5
	r11.s64 = 327680;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// ori r10,r11,4994
	ctx.r10.u64 = r11.u64 | 4994;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822091c4
	if (cr6.eq) goto loc_822091C4;
	// lbz r11,-6144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -6144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82209198
	if (cr6.eq) goto loc_82209198;
loc_822091C4:
	// bl 0x82207e88
	ctx.lr = 0x822091C8;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82209198
	if (!cr6.eq) goto loc_82209198;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207068
	ctx.lr = 0x822091E0;
	sub_82207068(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82209198
	if (!cr6.eq) goto loc_82209198;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8220923c
	if (cr6.eq) goto loc_8220923C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-12156
	ctx.r4.s64 = ctx.r10.s64 + -12156;
	// bl 0x82691650
	ctx.lr = 0x82209210;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,312(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82209220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8220923c
	if (cr6.eq) goto loc_8220923C;
	// lbz r11,-6144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -6144);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82209240
	if (cr6.eq) goto loc_82209240;
loc_8220923C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82209240:
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

__attribute__((alias("__imp__sub_82209258"))) PPC_WEAK_FUNC(sub_82209258);
PPC_FUNC_IMPL(__imp__sub_82209258) {
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
	ctx.lr = 0x82209260;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cc8
	ctx.lr = 0x82209274;
	sub_82641CC8(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r10,-6144(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822092a8
	if (cr6.eq) goto loc_822092A8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// addi r4,r11,-21652
	ctx.r4.s64 = r11.s64 + -21652;
	// bl 0x821f9fb8
	ctx.lr = 0x8220929C;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r29,1
	r29.s64 = 1;
	// bne cr6,0x822092ac
	if (!cr6.eq) goto loc_822092AC;
loc_822092A8:
	// li r29,0
	r29.s64 = 0;
loc_822092AC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822092ec
	if (cr6.eq) goto loc_822092EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822092C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822092ec
	if (cr6.eq) goto loc_822092EC;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822092ec
	if (!cr6.eq) goto loc_822092EC;
loc_822092E0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822092EC:
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,4994
	ctx.r10.u64 = r11.u64 | 4994;
	// lbzx r9,r30,r10
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220930c
	if (cr6.eq) goto loc_8220930C;
	// lbz r10,-6144(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822092e0
	if (cr6.eq) goto loc_822092E0;
loc_8220930C:
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4951
	ctx.r9.u64 = ctx.r10.u64 | 4951;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822092e0
	if (!cr6.eq) goto loc_822092E0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r10,-10220(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10220);
	// lbz r9,1168(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1168);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822092e0
	if (!cr6.eq) goto loc_822092E0;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82209384
	if (cr6.eq) goto loc_82209384;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-12156
	ctx.r4.s64 = ctx.r10.s64 + -12156;
	// bl 0x82691650
	ctx.lr = 0x82209358;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,312(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82209368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82209384
	if (cr6.eq) goto loc_82209384;
	// lbz r11,-6144(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + -6144);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82209388
	if (cr6.eq) goto loc_82209388;
loc_82209384:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82209388:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82209390"))) PPC_WEAK_FUNC(sub_82209390);
PPC_FUNC_IMPL(__imp__sub_82209390) {
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
	ctx.lr = 0x82209398;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,-10236(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x822093B4;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x822093C0;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822095d0
	if (cr6.eq) goto loc_822095D0;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822095d0
	if (cr6.eq) goto loc_822095D0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,-10244(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x826947a0
	ctx.lr = 0x822093E8;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x822093F4;
	sub_82218310(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826947a0
	ctx.lr = 0x82209404;
	sub_826947A0(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,10116
	ctx.r4.s64 = ctx.r10.s64 + 10116;
	// bl 0x823d90b0
	ctx.lr = 0x82209414;
	sub_823D90B0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822095b4
	if (cr6.eq) goto loc_822095B4;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82209428:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x8220944c
	if (cr6.eq) goto loc_8220944C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82209428
	if (cr6.eq) goto loc_82209428;
loc_8220944C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822095b4
	if (cr6.eq) goto loc_822095B4;
	// li r5,256
	ctx.r5.s64 = 256;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// subf r30,r31,r8
	r30.s64 = ctx.r8.s64 - r31.s64;
	// bl 0x823db670
	ctx.lr = 0x82209468;
	sub_823DB670(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r29,0
	r29.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stbx r29,r30,r11
	PPC_STORE_U8(r30.u32 + r11.u32, r29.u8);
	// bl 0x82203008
	ctx.lr = 0x82209480;
	sub_82203008(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-12104
	ctx.r4.s64 = ctx.r10.s64 + -12104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d90b0
	ctx.lr = 0x82209494;
	sub_823D90B0(ctx, base);
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823db670
	ctx.lr = 0x822094AC;
	sub_823DB670(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8220958c
	if (cr6.eq) goto loc_8220958C;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_822094BC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822094e0
	if (cr6.eq) goto loc_822094E0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822094bc
	if (cr6.eq) goto loc_822094BC;
loc_822094E0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8220958c
	if (cr6.eq) goto loc_8220958C;
	// li r11,7
	r11.s64 = 7;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r4,r10,-12116
	ctx.r4.s64 = ctx.r10.s64 + -12116;
	// bl 0x825ef9a8
	ctx.lr = 0x8220950C;
	sub_825EF9A8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x82209514;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8220952C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r31,1
	ctx.r4.s64 = r31.s64 + 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823db670
	ctx.lr = 0x8220953C;
	sub_823DB670(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r7,-12120
	ctx.r4.s64 = ctx.r7.s64 + -12120;
	// bl 0x823d90b0
	ctx.lr = 0x8220954C;
	sub_823D90B0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stb r29,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r29.u8);
	// bl 0x823dd7f0
	ctx.lr = 0x8220955C;
	sub_823DD7F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825ef9f0
	ctx.lr = 0x82209568;
	sub_825EF9F0(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,80(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8220957C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x825ef9a8
	ctx.lr = 0x82209584;
	sub_825EF9A8(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9244
	return;
loc_8220958C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x82209594;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822095AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9244
	return;
loc_822095B4:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826947a0
	ctx.lr = 0x822095C0;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x822095D0;
	sub_825EE2D8(ctx, base);
loc_822095D0:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822095D8"))) PPC_WEAK_FUNC(sub_822095D8);
PPC_FUNC_IMPL(__imp__sub_822095D8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822095E0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209600;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r3,92
	ctx.r3.s64 = ctx.r3.s64 + 92;
	// bl 0x823de058
	ctx.lr = 0x82209608;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,-10236(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x82209624;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82209630;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82209830
	if (cr6.eq) goto loc_82209830;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82209830
	if (cr6.eq) goto loc_82209830;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826947a0
	ctx.lr = 0x82209650;
	sub_826947A0(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,10116
	ctx.r4.s64 = r11.s64 + 10116;
	// bl 0x823d90b0
	ctx.lr = 0x82209660;
	sub_823D90B0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82209810
	if (cr6.eq) goto loc_82209810;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82209674:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82209698
	if (cr6.eq) goto loc_82209698;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82209674
	if (cr6.eq) goto loc_82209674;
loc_82209698:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82209810
	if (cr6.eq) goto loc_82209810;
	// li r5,256
	ctx.r5.s64 = 256;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// subf r30,r31,r8
	r30.s64 = ctx.r8.s64 - r31.s64;
	// bl 0x823db670
	ctx.lr = 0x822096B4;
	sub_823DB670(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r29,0
	r29.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stbx r29,r30,r11
	PPC_STORE_U8(r30.u32 + r11.u32, r29.u8);
	// bl 0x82203008
	ctx.lr = 0x822096CC;
	sub_82203008(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-12104
	ctx.r4.s64 = ctx.r10.s64 + -12104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d90b0
	ctx.lr = 0x822096E0;
	sub_823D90B0(ctx, base);
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823db670
	ctx.lr = 0x822096F8;
	sub_823DB670(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822097e4
	if (cr6.eq) goto loc_822097E4;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82209708:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8220972c
	if (cr6.eq) goto loc_8220972C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82209708
	if (cr6.eq) goto loc_82209708;
loc_8220972C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822097e4
	if (cr6.eq) goto loc_822097E4;
	// li r11,7
	r11.s64 = 7;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// addi r4,r10,-12116
	ctx.r4.s64 = ctx.r10.s64 + -12116;
	// bl 0x825ef9a8
	ctx.lr = 0x82209758;
	sub_825EF9A8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x82209760;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82209778;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r31,1
	ctx.r4.s64 = r31.s64 + 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823db670
	ctx.lr = 0x82209788;
	sub_823DB670(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r7,-12120
	ctx.r4.s64 = ctx.r7.s64 + -12120;
	// bl 0x823d90b0
	ctx.lr = 0x82209798;
	sub_823D90B0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stb r29,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r29.u8);
	// bl 0x823dd7f0
	ctx.lr = 0x822097A8;
	sub_823DD7F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x822097B4;
	sub_825EF9F0(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,80(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822097C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_822097E4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x822097EC;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82209810:
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f31.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826947a0
	ctx.lr = 0x82209820;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825ee188
	ctx.lr = 0x82209830;
	sub_825EE188(ctx, base);
loc_82209830:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8220983C"))) PPC_WEAK_FUNC(sub_8220983C);
PPC_FUNC_IMPL(__imp__sub_8220983C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82209840"))) PPC_WEAK_FUNC(sub_82209840);
PPC_FUNC_IMPL(__imp__sub_82209840) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82209848;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r3,92
	ctx.r3.s64 = ctx.r3.s64 + 92;
	// bl 0x823de058
	ctx.lr = 0x82209870;
	sub_823DE058(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,-10236(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x82209888;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82209894;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822098fc
	if (cr6.eq) goto loc_822098FC;
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r11,0
	r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// beq cr6,0x822098fc
	if (cr6.eq) goto loc_822098FC;
	// li r11,4
	r11.s64 = 4;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x826947a0
	ctx.lr = 0x822098D4;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x822098D8;
	sub_823DD7F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x822098E8;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82203058
	ctx.lr = 0x822098FC;
	sub_82203058(ctx, base);
loc_822098FC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82209908"))) PPC_WEAK_FUNC(sub_82209908);
PPC_FUNC_IMPL(__imp__sub_82209908) {
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
	ctx.lr = 0x82209910;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220992C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,-10236(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x82209944;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82209950;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822099e0
	if (cr6.eq) goto loc_822099E0;
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r11,0
	r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// beq cr6,0x822099e0
	if (cr6.eq) goto loc_822099E0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r29,92
	ctx.r4.s64 = r29.s64 + 92;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82209984;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825ef9a8
	ctx.lr = 0x82209990;
	sub_825EF9A8(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x826947a0
	ctx.lr = 0x822099A0;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x822099A4;
	sub_823DD7F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x822099B4;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x822099B8;
	sub_823DD7F0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x822099C8;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x825edfa0
	ctx.lr = 0x822099E0;
	sub_825EDFA0(ctx, base);
loc_822099E0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822099E8"))) PPC_WEAK_FUNC(sub_822099E8);
PPC_FUNC_IMPL(__imp__sub_822099E8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822099F0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r3,92
	ctx.r3.s64 = ctx.r3.s64 + 92;
	// bl 0x823de058
	ctx.lr = 0x82209A18;
	sub_823DE058(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,-10236(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x82209A30;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82209A3C;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82209abc
	if (cr6.eq) goto loc_82209ABC;
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r11,0
	r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// beq cr6,0x82209abc
	if (cr6.eq) goto loc_82209ABC;
	// li r11,4
	r11.s64 = 4;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x826947a0
	ctx.lr = 0x82209A7C;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82209A80;
	sub_823DD7F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x82209A90;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82209A94;
	sub_823DD7F0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x82209AA4;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x825edfa0
	ctx.lr = 0x82209ABC;
	sub_825EDFA0(ctx, base);
loc_82209ABC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82209AC8"))) PPC_WEAK_FUNC(sub_82209AC8);
PPC_FUNC_IMPL(__imp__sub_82209AC8) {
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
	ctx.lr = 0x82209AD0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,-10236(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x82209AEC;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82209AF8;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82209b80
	if (cr6.eq) goto loc_82209B80;
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r11,0
	r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// beq cr6,0x82209b80
	if (cr6.eq) goto loc_82209B80;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,-10244(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x826947a0
	ctx.lr = 0x82209B30;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x82209B3C;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825ef9a8
	ctx.lr = 0x82209B48;
	sub_825EF9A8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x826947a0
	ctx.lr = 0x82209B58;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82209B5C;
	sub_823DD7F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x82209B6C;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82203058
	ctx.lr = 0x82209B80;
	sub_82203058(ctx, base);
loc_82209B80:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82209B88"))) PPC_WEAK_FUNC(sub_82209B88);
PPC_FUNC_IMPL(__imp__sub_82209B88) {
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
	ctx.lr = 0x82209B90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,-10236(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x82209BAC;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82209BB8;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82209c30
	if (cr6.eq) goto loc_82209C30;
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r11,0
	r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// beq cr6,0x82209c30
	if (cr6.eq) goto loc_82209C30;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x82209BE8;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82209BEC;
	sub_823DD7F0(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x826947a0
	ctx.lr = 0x82209C08;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82209C0C;
	sub_823DD7F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x82209C1C;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82203058
	ctx.lr = 0x82209C30;
	sub_82203058(ctx, base);
loc_82209C30:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82209C38"))) PPC_WEAK_FUNC(sub_82209C38);
PPC_FUNC_IMPL(__imp__sub_82209C38) {
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
	ctx.lr = 0x82209C40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221df70
	ctx.lr = 0x82209C64;
	sub_8221DF70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82209d04
	if (cr6.eq) goto loc_82209D04;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221df98
	ctx.lr = 0x82209C78;
	sub_8221DF98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82209d04
	if (!cr6.eq) goto loc_82209D04;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209CA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82209d04
	if (cr6.eq) goto loc_82209D04;
	// addis r10,r31,4
	ctx.r10.s64 = r31.s64 + 262144;
	// addi r10,r10,1828
	ctx.r10.s64 = ctx.r10.s64 + 1828;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82209cc8
	if (!cr6.eq) goto loc_82209CC8;
	// li r11,0
	r11.s64 = 0;
loc_82209CC8:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r9,2272
	ctx.r5.s64 = ctx.r9.s64 + 2272;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,276(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 276);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82209CEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82209d7c
	if (cr6.eq) goto loc_82209D7C;
loc_82209CF8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82209D04:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// ori r9,r10,16216
	ctx.r9.u64 = ctx.r10.u64 | 16216;
	// addi r31,r11,2272
	r31.s64 = r11.s64 + 2272;
	// lbzx r8,r29,r9
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82209d4c
	if (!cr6.eq) goto loc_82209D4C;
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209D40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82209cf8
	if (!cr6.eq) goto loc_82209CF8;
loc_82209D4C:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,276(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209D6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82209d80
	if (!cr6.eq) goto loc_82209D80;
loc_82209D7C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82209D80:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82209D88"))) PPC_WEAK_FUNC(sub_82209D88);
PPC_FUNC_IMPL(__imp__sub_82209D88) {
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
	ctx.lr = 0x82209D90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221df70
	ctx.lr = 0x82209DB4;
	sub_8221DF70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82209e54
	if (cr6.eq) goto loc_82209E54;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221df98
	ctx.lr = 0x82209DC8;
	sub_8221DF98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82209e54
	if (!cr6.eq) goto loc_82209E54;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209DF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82209e54
	if (cr6.eq) goto loc_82209E54;
	// addis r10,r31,4
	ctx.r10.s64 = r31.s64 + 262144;
	// addi r10,r10,1828
	ctx.r10.s64 = ctx.r10.s64 + 1828;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82209e18
	if (!cr6.eq) goto loc_82209E18;
	// li r11,0
	r11.s64 = 0;
loc_82209E18:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r9,2272
	ctx.r5.s64 = ctx.r9.s64 + 2272;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,280(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 280);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82209E3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82209ecc
	if (cr6.eq) goto loc_82209ECC;
loc_82209E48:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82209E54:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// ori r9,r10,16216
	ctx.r9.u64 = ctx.r10.u64 | 16216;
	// addi r31,r11,2272
	r31.s64 = r11.s64 + 2272;
	// lbzx r8,r29,r9
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82209e9c
	if (!cr6.eq) goto loc_82209E9C;
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209E90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82209e48
	if (!cr6.eq) goto loc_82209E48;
loc_82209E9C:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,280(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 280);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209EBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82209ed0
	if (!cr6.eq) goto loc_82209ED0;
loc_82209ECC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82209ED0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82209ED8"))) PPC_WEAK_FUNC(sub_82209ED8);
PPC_FUNC_IMPL(__imp__sub_82209ED8) {
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
	ctx.lr = 0x82209EE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221df70
	ctx.lr = 0x82209F04;
	sub_8221DF70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82209fa4
	if (cr6.eq) goto loc_82209FA4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221df98
	ctx.lr = 0x82209F18;
	sub_8221DF98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82209fa4
	if (!cr6.eq) goto loc_82209FA4;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209F40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82209fa4
	if (cr6.eq) goto loc_82209FA4;
	// addis r10,r31,4
	ctx.r10.s64 = r31.s64 + 262144;
	// addi r10,r10,1828
	ctx.r10.s64 = ctx.r10.s64 + 1828;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82209f68
	if (!cr6.eq) goto loc_82209F68;
	// li r11,0
	r11.s64 = 0;
loc_82209F68:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r9,2272
	ctx.r5.s64 = ctx.r9.s64 + 2272;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,284(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 284);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82209F8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8220a01c
	if (cr6.eq) goto loc_8220A01C;
loc_82209F98:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82209FA4:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// ori r9,r10,16216
	ctx.r9.u64 = ctx.r10.u64 | 16216;
	// addi r31,r11,2272
	r31.s64 = r11.s64 + 2272;
	// lbzx r8,r29,r9
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82209fec
	if (!cr6.eq) goto loc_82209FEC;
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82209FE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82209f98
	if (!cr6.eq) goto loc_82209F98;
loc_82209FEC:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,284(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 284);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220A00C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8220a020
	if (!cr6.eq) goto loc_8220A020;
loc_8220A01C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8220A020:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8220A028"))) PPC_WEAK_FUNC(sub_8220A028);
PPC_FUNC_IMPL(__imp__sub_8220A028) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,1
	r11.s64 = 65536;
	// ori r10,r11,6112
	ctx.r10.u64 = r11.u64 | 6112;
	// lwzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lhz r8,6(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addis r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 65536;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// sth r7,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, ctx.r7.u16);
	// stw r6,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r6.u32);
	// beq cr6,0x8220a0ac
	if (cr6.eq) goto loc_8220A0AC;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stb r8,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r8.u8);
	// stb r11,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, r11.u8);
	// stb r11,26(r3)
	PPC_STORE_U8(ctx.r3.u32 + 26, r11.u8);
	// stb r11,154(r3)
	PPC_STORE_U8(ctx.r3.u32 + 154, r11.u8);
	// stb r11,282(r3)
	PPC_STORE_U8(ctx.r3.u32 + 282, r11.u8);
	// stb r11,410(r3)
	PPC_STORE_U8(ctx.r3.u32 + 410, r11.u8);
	// stb r11,538(r3)
	PPC_STORE_U8(ctx.r3.u32 + 538, r11.u8);
	// stb r11,666(r3)
	PPC_STORE_U8(ctx.r3.u32 + 666, r11.u8);
	// stb r11,730(r3)
	PPC_STORE_U8(ctx.r3.u32 + 730, r11.u8);
	// stb r11,762(r3)
	PPC_STORE_U8(ctx.r3.u32 + 762, r11.u8);
	// blr 
	return;
loc_8220A0AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220A0B4"))) PPC_WEAK_FUNC(sub_8220A0B4);
PPC_FUNC_IMPL(__imp__sub_8220A0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220A0B8"))) PPC_WEAK_FUNC(sub_8220A0B8);
PPC_FUNC_IMPL(__imp__sub_8220A0B8) {
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
	ctx.lr = 0x8220A0C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r30,128
	ctx.r3.s64 = r30.s64 + 128;
	// bl 0x822381b8
	ctx.lr = 0x8220A0D0;
	sub_822381B8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,-10004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// addi r29,r11,36
	r29.s64 = r11.s64 + 36;
	// lhz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220a194
	if (cr6.eq) goto loc_8220A194;
	// li r31,0
	r31.s64 = 0;
loc_8220A0F0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lbz r9,685(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 685);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8220a180
	if (!cr6.eq) goto loc_8220A180;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x826c72d8
	ctx.lr = 0x8220A10C;
	sub_826C72D8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8220a180
	if (cr6.eq) goto loc_8220A180;
	// lhz r11,196(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a180
	if (cr6.eq) goto loc_8220A180;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// lwz r9,192(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// twllei r11,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a180
	if (cr6.eq) goto loc_8220A180;
loc_8220A144:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// beq cr6,0x8220a160
	if (cr6.eq) goto loc_8220A160;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220a144
	if (!cr6.eq) goto loc_8220A144;
	// b 0x8220a180
	goto loc_8220A180;
loc_8220A160:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a180
	if (cr6.eq) goto loc_8220A180;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220a180
	if (cr6.eq) goto loc_8220A180;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822378f8
	ctx.lr = 0x8220A180;
	sub_822378F8(ctx, base);
loc_8220A180:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8220a0f0
	if (cr6.lt) goto loc_8220A0F0;
loc_8220A194:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8220A19C"))) PPC_WEAK_FUNC(sub_8220A19C);
PPC_FUNC_IMPL(__imp__sub_8220A19C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220A1A0"))) PPC_WEAK_FUNC(sub_8220A1A0);
PPC_FUNC_IMPL(__imp__sub_8220A1A0) {
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
	// bl 0x823d91e4
	ctx.lr = 0x8220A1A8;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd52c
	ctx.lr = 0x8220A1B8;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220A1D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220aa50
	if (cr6.eq) goto loc_8220AA50;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// stfs f31,160(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220A210;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// li r28,16
	r28.s64 = 16;
	// li r29,32
	r29.s64 = 32;
	// li r24,48
	r24.s64 = 48;
	// lwz r11,-17936(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17936);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lwz r10,-8092(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// addi r6,r11,45
	ctx.r6.s64 = r11.s64 + 45;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x8220a28c
	if (!cr6.eq) goto loc_8220A28C;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
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
	// vor128 v123,v63,v63
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// vpermwi128 v126,v62,234
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v125,v62,186
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v124,v62,174
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8220a540
	goto loc_8220A540;
loc_8220A28C:
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,72
	r27.s64 = 72;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// addi r11,r11,4272
	r11.s64 = r11.s64 + 4272;
	// lbzx r10,r27,r30
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r11,r28
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,17268
	ctx.r10.s64 = ctx.r10.s64 + 17268;
	// lvx128 v124,r11,r29
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v123,r11,r24
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x8220a2d8
	if (cr6.eq) goto loc_8220A2D8;
	// lwz r10,260(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8220a2f4
	if (!cr6.gt) goto loc_8220A2F4;
	// lwz r10,136(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x8220a2e8
	goto loc_8220A2E8;
loc_8220A2D8:
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8220a2f4
	if (!cr6.gt) goto loc_8220A2F4;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_8220A2E8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x8220a2f8
	if (!cr6.eq) goto loc_8220A2F8;
loc_8220A2F4:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8220A2F8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220a510
	if (cr6.eq) goto loc_8220A510;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x8220A30C;
	sub_822A3998(ctx, base);
	// lwz r31,48(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8220a4d4
	if (cr6.eq) goto loc_8220A4D4;
	// lbzx r11,r27,r30
	r11.u64 = PPC_LOAD_U8(r27.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// bne cr6,0x8220a32c
	if (!cr6.eq) goto loc_8220A32C;
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
loc_8220A32C:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r24
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x8220A364;
	sub_8255B9A8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lvx128 v127,r6,r29
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8255b9a8
	ctx.lr = 0x8220A374;
	sub_8255B9A8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v54,r5,r28
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82332098
	ctx.lr = 0x8220A38C;
	sub_82332098(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220a3ac
	if (cr6.eq) goto loc_8220A3AC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,180(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-12084(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,180(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
loc_8220A3AC:
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// vor128 v53,v127,v127
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbzx r9,r27,r30
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + r30.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vsubfp128 v0,v52,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v127.f32)));
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvlx128 v51,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vmaddfp128 v53,v0,v50,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v50.f32)), simde_mm_load_ps(v53.f32)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v49,v63,v62
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v48,v63,v62
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v47,v61,v60
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmrglw128 v46,v61,v60
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvlx128 v45,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v44,v45,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// vmrghw128 v43,v49,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmulfp128 v63,v0,v44
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v44.f32)));
	// vmrghw128 v42,v48,v46
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// vmrglw128 v41,v49,v47
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmsum3fp128 v40,v53,v43
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v43.f32), 0xEF));
	// vmsum3fp128 v39,v53,v42
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v42.f32), 0xEF));
	// vmsum3fp128 v38,v53,v41
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v41.f32), 0xEF));
	// vmrghw128 v37,v40,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v36,v38,v37
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v62,v37,v36
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// bne cr6,0x8220a454
	if (!cr6.eq) goto loc_8220A454;
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
loc_8220A454:
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v35,v61,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v59,r11,r29
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v34,v60,v63
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v33,v59,v63
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,228(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,196(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,212(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	f0.f64 = double(temp.f32);
	// fabs f9,f0
	ctx.f9.u64 = f0.u64 & ~0x8000000000000000;
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fabs f8,f13
	ctx.f8.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fadds f7,f10,f9
	ctx.f7.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// fadds f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f8.f64));
	// fadds f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f12.f64));
	// stfs f5,164(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// b 0x8220a540
	goto loc_8220A540;
loc_8220A4D4:
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,4272
	r11.s64 = r11.s64 + 4272;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v32,r0,r11
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r24
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8220a540
	goto loc_8220A540;
loc_8220A510:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r24
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220A540:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82238f88
	ctx.lr = 0x8220A548;
	sub_82238F88(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lwz r31,-10236(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A560;
	sub_821F7CA8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220a5cc
	if (cr6.eq) goto loc_8220A5CC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A578;
	sub_821F9248(ctx, base);
	// vspltisw128 v56,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// vupkd3d128 v55,v56,4
	temp.f32 = 3.0f;
	temp.s32 += v56.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v56.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v55 = vTemp;
	// vpermwi128 v54,v55,234
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x15));
	// vpermwi128 v53,v55,186
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x45));
	// vpermwi128 v52,v55,174
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x51));
	// stvx128 v54,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r30,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r30,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82204cb8
	ctx.lr = 0x8220A5AC;
	sub_82204CB8(ctx, base);
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,48(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f13,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fadds f9,f0,f11
	ctx.f9.f64 = double(float(f0.f64 + ctx.f11.f64));
	// stfs f10,48(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 48, temp.u32);
	// stfs f9,56(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 56, temp.u32);
loc_8220A5CC:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A5D8;
	sub_821F7CA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a638
	if (cr6.eq) goto loc_8220A638;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A5F0;
	sub_821F9248(ctx, base);
	// vspltisw128 v51,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// vupkd3d128 v50,v51,4
	temp.f32 = 3.0f;
	temp.s32 += v51.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v51.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v50 = vTemp;
	// vpermwi128 v49,v50,234
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x15));
	// vpermwi128 v48,v50,186
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x45));
	// vpermwi128 v47,v50,174
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x51));
	// stvx128 v49,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f0.f64 = double(temp.f32);
	// lfs f11,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,56(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fadds f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stfs f12,48(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f9,56(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
loc_8220A638:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A644;
	sub_821F9248(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r27,r30,16
	r27.s64 = r30.s64 + 16;
	// addi r26,r30,32
	r26.s64 = r30.s64 + 32;
	// addi r25,r30,48
	r25.s64 = r30.s64 + 48;
	// stvx128 v126,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v125,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v123,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821f7ca8
	ctx.lr = 0x8220A670;
	sub_821F7CA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a6a8
	if (cr6.eq) goto loc_8220A6A8;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A688;
	sub_821F9248(ctx, base);
	// lvx128 v46,r0,r30
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r27
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r26
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r25
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r3,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220A6A8:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A6B4;
	sub_821F7CA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a6fc
	if (cr6.eq) goto loc_8220A6FC;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A6CC;
	sub_821F9248(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r0,r9
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r3,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220A6FC:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A708;
	sub_821F9248(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r26,r30,32
	r26.s64 = r30.s64 + 32;
	// addi r27,r30,16
	r27.s64 = r30.s64 + 16;
	// lfs f30,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// stfs f30,20(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 20, temp.u32);
	// stfs f31,24(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 24, temp.u32);
	// stfs f31,16(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// lvx128 v38,r0,r10
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,36(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 36, temp.u32);
	// bl 0x821b9c70
	ctx.lr = 0x8220A73C;
	sub_821B9C70(ctx, base);
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v37,r0,r26
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lvx128 v35,r0,r27
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r25,r30,48
	r25.s64 = r30.s64 + 48;
	// vpermwi128 v34,v35,135
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0x78));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// vsubfp128 v36,v127,v37
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v36.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v37.f32)));
	// vpermwi128 v0,v35,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0x9C));
	// vpermwi128 v33,v36,99
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0x9C));
	// vpermwi128 v13,v36,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0x78));
	// vmulfp128 v12,v34,v33
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v33.f32)));
	// vnmsubfp v11,v0,v13,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r0,r9
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,692(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 692);
	// bl 0x8223efc8
	ctx.lr = 0x8220A784;
	sub_8223EFC8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A790;
	sub_821F7CA8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8220a7c8
	if (cr6.eq) goto loc_8220A7C8;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A7A8;
	sub_821F9248(ctx, base);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r25
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220A7C8:
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A7D4;
	sub_821F9248(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A7E4;
	sub_821F7CA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a860
	if (cr6.eq) goto loc_8220A860;
	// stfs f31,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f30,20(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 20, temp.u32);
	// addi r27,r30,16
	r27.s64 = r30.s64 + 16;
	// stfs f31,24(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 24, temp.u32);
	// addi r26,r30,32
	r26.s64 = r30.s64 + 32;
	// lfs f13,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 32, temp.u32);
	// stfs f31,36(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 36, temp.u32);
	// stfs f13,40(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 40, temp.u32);
	// bl 0x821b9c70
	ctx.lr = 0x8220A820;
	sub_821B9C70(ctx, base);
	// lvx128 v58,r0,r26
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v127,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v56,r0,r27
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v55,v56,135
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x78));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// vpermwi128 v0,v56,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x9C));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v54,v57,99
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x9C));
	// vpermwi128 v13,v57,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x78));
	// vmulfp128 v12,v55,v54
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v54.f32)));
	// vnmsubfp v11,v0,v13,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v52,v59,v53
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v52,r30,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220A860:
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A86C;
	sub_821F9248(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A87C;
	sub_821F7CA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a8ac
	if (cr6.eq) goto loc_8220A8AC;
	// lvx128 v51,r0,r30
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r30,r28
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r27,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r30,r29
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r27,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r30,r24
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r27,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8220a8d8
	goto loc_8220A8D8;
loc_8220A8AC:
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9238
	ctx.lr = 0x8220A8B8;
	sub_821F9238(ctx, base);
	// lvx128 v47,r0,r3
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r3,r28
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r27,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r3,r29
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r27,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r3,r24
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r27,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220A8D8:
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220A8F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220aa50
	if (cr6.eq) goto loc_8220AA50;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A908;
	sub_821F7CA8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r30,r11,-31280
	r30.s64 = r11.s64 + -31280;
	// beq cr6,0x8220a954
	if (cr6.eq) goto loc_8220A954;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A928;
	sub_821F9248(ctx, base);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r30,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r30,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220A954:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A960;
	sub_821F7CA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220a9a4
	if (cr6.eq) goto loc_8220A9A4;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A978;
	sub_821F9248(ctx, base);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r30,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r30,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220A9A4:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7ca8
	ctx.lr = 0x8220A9B0;
	sub_821F7CA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220aa50
	if (cr6.eq) goto loc_8220AA50;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9248
	ctx.lr = 0x8220A9C8;
	sub_821F9248(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,-12100
	ctx.r3.s64 = r11.s64 + -12100;
	// addi r30,r10,-21000
	r30.s64 = ctx.r10.s64 + -21000;
	// addi r26,r9,-22108
	r26.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8220A9E8;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8220A9FC;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220aa50
	if (cr6.eq) goto loc_8220AA50;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220AA14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v43,r0,r3
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// li r9,544
	ctx.r9.s64 = 544;
	// lvx128 v42,r3,r28
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r3,r29
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r3,r24
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,-10220(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// vor128 v39,v40,v40
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// lvx128 v38,r10,r9
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v37,v39,v38
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v37.f32, simde_mm_add_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v38.f32)));
	// stvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220AA50:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd7c4
	ctx.lr = 0x8220AA5C;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8220AA68"))) PPC_WEAK_FUNC(sub_8220AA68);
PPC_FUNC_IMPL(__imp__sub_8220AA68) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8220AA70;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d8
	ctx.lr = 0x8220AA78;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// mr r14,r8
	r14.u64 = ctx.r8.u64;
	// addi r20,r30,16
	r20.s64 = r30.s64 + 16;
	// lwz r29,-10236(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// li r21,16
	r21.s64 = 16;
	// lfs f28,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f28.f64 = double(temp.f32);
	// addi r19,r30,32
	r19.s64 = r30.s64 + 32;
	// addi r11,r29,4208
	r11.s64 = r29.s64 + 4208;
	// stfs f28,0(r14)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r14.u32 + 0, temp.u32);
	// li r22,32
	r22.s64 = 32;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r30,48
	r28.s64 = r30.s64 + 48;
	// li r23,48
	r23.s64 = 48;
	// addi r10,r29,4272
	ctx.r10.s64 = r29.s64 + 4272;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lvx128 v62,r0,r20
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// stvx128 v62,r11,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v61,r0,r19
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// stvx128 v61,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r17,r7
	r17.u64 = ctx.r7.u64;
	// lvx128 v60,r0,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r30
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r20
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r10,r21
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r19
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r22
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r28
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r23
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,17268(r24)
	r27.u64 = PPC_LOAD_U32(r24.u32 + 17268);
	// lfs f0,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stfs f0,10664(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 10664, temp.u32);
	// beq cr6,0x8220ab40
	if (cr6.eq) goto loc_8220AB40;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8220AB30;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220ab44
	if (!cr6.eq) goto loc_8220AB44;
loc_8220AB40:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8220AB44:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stb r11,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r11.u8);
	// lwz r11,-9920(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -9920);
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8220ab68
	if (!cr6.eq) goto loc_8220AB68;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r11,-9920(r10)
	PPC_STORE_U32(ctx.r10.u32 + -9920, r11.u32);
loc_8220AB68:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220b1d8
	if (cr6.eq) goto loc_8220B1D8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822a3998
	ctx.lr = 0x8220AB80;
	sub_822A3998(ctx, base);
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x8220AB88;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220abac
	if (!cr6.eq) goto loc_8220ABAC;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x8220AB9C;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8220abb0
	if (cr6.eq) goto loc_8220ABB0;
loc_8220ABAC:
	// li r11,1
	r11.s64 = 1;
loc_8220ABB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r11,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r11.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220b1d8
	if (!cr6.eq) goto loc_8220B1D8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,4200(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4200);
	f31.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r18,-32121
	r18.s64 = -2105081856;
	// addi r25,r11,-9984
	r25.s64 = r11.s64 + -9984;
	// lfs f29,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// ble cr6,0x8220add0
	if (!cr6.gt) goto loc_8220ADD0;
	// lwz r27,17268(r24)
	r27.u64 = PPC_LOAD_U32(r24.u32 + 17268);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8220ac84
	if (cr6.eq) goto loc_8220AC84;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8220AC00;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220ac84
	if (cr6.eq) goto loc_8220AC84;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822a3998
	ctx.lr = 0x8220AC18;
	sub_822A3998(ctx, base);
	// bl 0x822a5680
	ctx.lr = 0x8220AC1C;
	sub_822A5680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220ac84
	if (cr6.eq) goto loc_8220AC84;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8220ac84
	if (!cr6.eq) goto loc_8220AC84;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220ac58
	if (cr6.eq) goto loc_8220AC58;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8220ac5c
	if (cr6.eq) goto loc_8220AC5C;
loc_8220AC58:
	// li r11,0
	r11.s64 = 0;
loc_8220AC5C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220ac84
	if (!cr6.eq) goto loc_8220AC84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82207068
	ctx.lr = 0x8220AC70;
	sub_82207068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220ac84
	if (!cr6.eq) goto loc_8220AC84;
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = f30.f64;
	// b 0x8220ac8c
	goto loc_8220AC8C;
loc_8220AC84:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// bne cr6,0x8220acec
	if (!cr6.eq) goto loc_8220ACEC;
loc_8220AC8C:
	// addi r11,r29,4336
	r11.s64 = r29.s64 + 4336;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r21
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r22
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r11,r23
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r25,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r25,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r25,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4404(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4404);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// stfs f0,-9988(r18)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r18.u32 + -9988, temp.u32);
	// b 0x8220add0
	goto loc_8220ADD0;
loc_8220ACEC:
	// addi r11,r29,4336
	r11.s64 = r29.s64 + 4336;
	// lfs f0,4400(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4400);
	f0.f64 = double(temp.f32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// addi r7,r1,304
	ctx.r7.s64 = ctx.r1.s64 + 304;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v50,r11,r21
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lvx128 v49,r11,r22
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v48,r11,r23
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f0,0(r14)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r14.u32 + 0, temp.u32);
	// lfs f1,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822039c8
	ctx.lr = 0x8220AD40;
	sub_822039C8(ctx, base);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x822039c8
	ctx.lr = 0x8220AD50;
	sub_822039C8(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f3,4404(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4404);
	ctx.f3.f64 = double(temp.f32);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// stb r6,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, ctx.r6.u8);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lfs f2,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r26.u32);
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82205a18
	ctx.lr = 0x8220AD9C;
	sub_82205A18(ctx, base);
	// addi r11,r1,256
	r11.s64 = ctx.r1.s64 + 256;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vor128 v45,v47,v47
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// lvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v44,v45,v46
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v44.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32)));
	// stvx128 v47,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x8220ADD0;
	sub_82202EC0(ctx, base);
loc_8220ADD0:
	// lis r11,1
	r11.s64 = 65536;
	// li r29,0
	r29.s64 = 0;
	// ori r10,r11,6136
	ctx.r10.u64 = r11.u64 | 6136;
	// lwzx r11,r31,r10
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8220ae14
	if (cr6.eq) goto loc_8220AE14;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r8,r14
	ctx.r8.u64 = r14.u64;
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220AE10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r29,1
	r29.s64 = 1;
loc_8220AE14:
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x822a5680
	ctx.lr = 0x8220AE1C;
	sub_822A5680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220ae74
	if (cr6.eq) goto loc_8220AE74;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220ae74
	if (!cr6.eq) goto loc_8220AE74;
	// lfs f0,-9992(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + -9992);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bne cr6,0x8220ae4c
	if (!cr6.eq) goto loc_8220AE4C;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x8220ae5c
	if (cr6.eq) goto loc_8220AE5C;
loc_8220AE4C:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bne cr6,0x8220ae74
	if (!cr6.eq) goto loc_8220AE74;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x8220ae74
	if (!cr6.eq) goto loc_8220AE74;
loc_8220AE5C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x8220AE74;
	sub_82207EF0(ctx, base);
loc_8220AE74:
	// lis r11,1
	r11.s64 = 65536;
	// stfs f31,-9992(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r27.u32 + -9992, temp.u32);
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// ori r29,r11,16256
	r29.u64 = r11.u64 | 16256;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// add r27,r31,r29
	r27.u64 = r31.u64 + r29.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r10,r31,r29
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,380(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 380);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220AEA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r24,-32121
	r24.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10028);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8220AEBC;
	sub_82641CB0(ctx, base);
	// lwz r11,-10028(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10028);
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// li r4,19
	ctx.r4.s64 = 19;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8220AED0;
	sub_82641CB0(ctx, base);
	// lwz r11,-10028(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10028);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,48
	ctx.r4.s64 = 48;
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8220AEE8;
	sub_82641CB0(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82641cc8
	ctx.lr = 0x8220AEF4;
	sub_82641CC8(ctx, base);
	// cmplw cr6,r3,r16
	cr6.compare<uint32_t>(ctx.r3.u32, r16.u32, xer);
	// bne cr6,0x8220af20
	if (!cr6.eq) goto loc_8220AF20;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82641cc8
	ctx.lr = 0x8220AF04;
	sub_82641CC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220AF14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8220af70
	if (!cr6.eq) goto loc_8220AF70;
loc_8220AF20:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82641cc8
	ctx.lr = 0x8220AF28;
	sub_82641CC8(ctx, base);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// beq cr6,0x8220af70
	if (cr6.eq) goto loc_8220AF70;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82641cc8
	ctx.lr = 0x8220AF38;
	sub_82641CC8(ctx, base);
	// cmplw cr6,r3,r24
	cr6.compare<uint32_t>(ctx.r3.u32, r24.u32, xer);
	// beq cr6,0x8220af70
	if (cr6.eq) goto loc_8220AF70;
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// lvx128 v43,r0,r30
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,12656
	r11.s64 = r11.s64 + 12656;
	// stvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r20
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r11,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r19
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r0,r28
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// b 0x8220afa8
	goto loc_8220AFA8;
loc_8220AF70:
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// lfs f0,-9988(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r18.u32 + -9988);
	f0.f64 = double(temp.f32);
	// addi r11,r11,12656
	r11.s64 = r11.s64 + 12656;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r25,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r25,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r25,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220AFA8:
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r29,r29,12784
	r29.s64 = r29.s64 + 12784;
	// stfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220AFCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8220b064
	if (!cr6.eq) goto loc_8220B064;
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,492(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 492);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220AFEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220b024
	if (cr6.eq) goto loc_8220B024;
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,492(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 492);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220B008;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8220B018;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8220b064
	if (!cr6.eq) goto loc_8220B064;
loc_8220B024:
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,380(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 380);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220B050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,5
	ctx.r8.s64 = 327680;
	// li r7,0
	ctx.r7.s64 = 0;
	// ori r6,r8,4990
	ctx.r6.u64 = ctx.r8.u64 | 4990;
	// stbx r7,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, ctx.r7.u8);
	// b 0x8220b1d8
	goto loc_8220B1D8;
loc_8220B064:
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	f31.f64 = f29.f64;
	// bl 0x82387a18
	ctx.lr = 0x8220B06C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220b144
	if (cr6.eq) goto loc_8220B144;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-12068
	ctx.r3.s64 = r11.s64 + -12068;
	// bl 0x821fa230
	ctx.lr = 0x8220B084;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220B094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8220b144
	if (!cr6.eq) goto loc_8220B144;
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,440(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 440);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220B0B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220b144
	if (cr6.eq) goto loc_8220B144;
	// addis r25,r31,1
	r25.s64 = r31.s64 + 65536;
	// addi r25,r25,12768
	r25.s64 = r25.s64 + 12768;
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x8220b144
	if (cr6.eq) goto loc_8220B144;
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r3,12720
	ctx.r3.s64 = ctx.r3.s64 + 12720;
	// bl 0x821b9f50
	ctx.lr = 0x8220B0E4;
	sub_821B9F50(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b9f50
	ctx.lr = 0x8220B0F0;
	sub_821B9F50(ctx, base);
	// lvx128 v39,r0,r25
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r0,r28
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// vsubfp128 v37,v38,v39
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v37.f32, simde_mm_sub_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v39.f32)));
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// stvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,492(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 492);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220B118;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r7,668(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 668);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8220B12C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// ori r5,r6,12788
	ctx.r5.u64 = ctx.r6.u64 | 12788;
	// lfsx f13,r31,r5
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f31,f0,f13
	f31.f64 = double(float(f0.f64 - ctx.f13.f64));
	// b 0x8220b150
	goto loc_8220B150;
loc_8220B144:
	// vspltisw128 v36,0
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v36,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220B150:
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,380(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 380);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220B174;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,0(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// bl 0x82387a18
	ctx.lr = 0x8220B184;
	sub_82387A18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220b1c4
	if (cr6.eq) goto loc_8220B1C4;
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,440(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 440);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220B1A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220b1c4
	if (cr6.eq) goto loc_8220B1C4;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v35,r0,r28
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r11
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v33,v35,v34
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v33.f32, simde_mm_add_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v34.f32)));
	// stvx128 v33,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220B1C4:
	// lis r11,5
	r11.s64 = 327680;
	// stfs f28,0(r14)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r14.u32 + 0, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r9,r11,4990
	ctx.r9.u64 = r11.u64 | 4990;
	// stbx r10,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, ctx.r10.u8);
loc_8220B1D8:
	// lbz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8220b2a4
	if (!cr6.eq) goto loc_8220B2A4;
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,4944
	ctx.r10.u64 = r11.u64 | 4944;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220b2a4
	if (cr6.eq) goto loc_8220B2A4;
	// addis r11,r31,5
	r11.s64 = r31.s64 + 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// addi r11,r11,4864
	r11.s64 = r11.s64 + 4864;
	// ori r8,r10,4956
	ctx.r8.u64 = ctx.r10.u64 | 4956;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lvx128 v32,r0,r11
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r22
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r23
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f13,r31,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// lfs f0,-12072(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12072);
	f0.f64 = double(temp.f32);
	// lfs f12,0(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 + f0.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x8220b250
	if (!cr6.gt) goto loc_8220B250;
	// stfs f0,0(r17)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
loc_8220B250:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,-12076(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12076);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8220b28c
	if (!cr6.gt) goto loc_8220B28C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,11364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,0(r15)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r15.u32 + 0, temp.u32);
	// lfs f0,32312(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32312);
	f0.f64 = double(temp.f32);
	// lfs f13,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,0(r17)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
	// b 0x8220b2a4
	goto loc_8220B2A4;
loc_8220B28C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f13,-12080(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12080);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r15)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r15.u32 + 0, temp.u32);
	// stfs f13,0(r17)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
loc_8220B2A4:
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r9,r31,5
	ctx.r9.s64 = r31.s64 + 327680;
	// addi r9,r9,4994
	ctx.r9.s64 = ctx.r9.s64 + 4994;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// addi r11,r11,4272
	r11.s64 = r11.s64 + 4272;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r20
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r19
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220b374
	if (cr6.eq) goto loc_8220B374;
	// addis r11,r31,5
	r11.s64 = r31.s64 + 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// addi r11,r11,5008
	r11.s64 = r11.s64 + 5008;
	// ori r7,r10,5072
	ctx.r7.u64 = ctx.r10.u64 | 5072;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// ori r6,r8,5076
	ctx.r6.u64 = ctx.r8.u64 | 5076;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r3,r5,5080
	ctx.r3.u64 = ctx.r5.u64 | 5080;
	// stvx128 v56,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,5
	ctx.r4.s64 = 327680;
	// addis r10,r31,5
	ctx.r10.s64 = r31.s64 + 327680;
	// ori r8,r4,5084
	ctx.r8.u64 = ctx.r4.u64 | 5084;
	// addi r10,r10,4996
	ctx.r10.s64 = ctx.r10.s64 + 4996;
	// lvx128 v55,r11,r21
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r22
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r23
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f0,r31,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// lfsx f13,r31,r6
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r15)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r15.u32 + 0, temp.u32);
	// lfsx f12,r31,r3
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,0(r17)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
	// lfsx f11,r31,r8
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r14)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r14.u32 + 0, temp.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8220b368
	if (!cr6.eq) goto loc_8220B368;
	// stb r11,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r11.u8);
	// b 0x8220b374
	goto loc_8220B374;
loc_8220B368:
	// ble cr6,0x8220b374
	if (!cr6.gt) goto loc_8220B374;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_8220B374:
	// lis r11,5
	r11.s64 = 327680;
	// lvx128 v52,r0,r28
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r10,r31,5
	ctx.r10.s64 = r31.s64 + 327680;
	// ori r9,r11,5136
	ctx.r9.u64 = r11.u64 | 5136;
	// addi r10,r10,5152
	ctx.r10.s64 = ctx.r10.s64 + 5152;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// li r7,88
	ctx.r7.s64 = 88;
	// addi r6,r8,29952
	ctx.r6.s64 = ctx.r8.s64 + 29952;
	// lvx128 v51,r31,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// vsubfp128 v50,v52,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v51.f32)));
	// addis r4,r31,5
	ctx.r4.s64 = r31.s64 + 327680;
	// addi r3,r5,-31664
	ctx.r3.s64 = ctx.r5.s64 + -31664;
	// addi r4,r4,5088
	ctx.r4.s64 = ctx.r4.s64 + 5088;
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,4995
	ctx.r8.u64 = r11.u64 | 4995;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// ori r11,r9,5168
	r11.u64 = ctx.r9.u64 | 5168;
	// ori r5,r5,5176
	ctx.r5.u64 = ctx.r5.u64 | 5176;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r29,5
	r29.s64 = 327680;
	// ori r9,r9,5172
	ctx.r9.u64 = ctx.r9.u64 | 5172;
	// stvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v47,v50,v50
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// ori r29,r29,5180
	r29.u64 = r29.u64 | 5180;
	// lvlx128 v49,r6,r7
	temp.u32 = ctx.r6.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// lvx128 v13,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v48
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v48.f32)));
	// vor128 v12,v48,v48
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v46,v47,v9
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r30
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r20
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r4,r21
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r19
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r4,r22
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r28
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r4,r23
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfsx f0,r31,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// lbzx r8,r31,r8
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + ctx.r8.u32);
	// lfs f13,0(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfsx f13,r31,r5
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, temp.u32);
	// lfs f12,0(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stfsx f12,r31,r9
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, temp.u32);
	// lfs f11,0(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfsx f11,r31,r29
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + r29.u32, temp.u32);
	// beq cr6,0x8220b458
	if (cr6.eq) goto loc_8220B458;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82204480
	ctx.lr = 0x8220B458;
	sub_82204480(ctx, base);
loc_8220B458:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba24
	ctx.lr = 0x8220B464;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8220B468"))) PPC_WEAK_FUNC(sub_8220B468);
PPC_FUNC_IMPL(__imp__sub_8220B468) {
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
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,-16384
	ctx.r3.s64 = ctx.r3.s64 + -16384;
	// bl 0x82654e20
	ctx.lr = 0x8220B490;
	sub_82654E20(ctx, base);
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

__attribute__((alias("__imp__sub_8220B4AC"))) PPC_WEAK_FUNC(sub_8220B4AC);
PPC_FUNC_IMPL(__imp__sub_8220B4AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B4B0"))) PPC_WEAK_FUNC(sub_8220B4B0);
PPC_FUNC_IMPL(__imp__sub_8220B4B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// lwz r5,64(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220B4DC"))) PPC_WEAK_FUNC(sub_8220B4DC);
PPC_FUNC_IMPL(__imp__sub_8220B4DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B4E0"))) PPC_WEAK_FUNC(sub_8220B4E0);
PPC_FUNC_IMPL(__imp__sub_8220B4E0) {
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
	// beq cr6,0x8220b50c
	if (cr6.eq) goto loc_8220B50C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,68(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// blr 
	return;
loc_8220B50C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220B51C"))) PPC_WEAK_FUNC(sub_8220B51C);
PPC_FUNC_IMPL(__imp__sub_8220B51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B520"))) PPC_WEAK_FUNC(sub_8220B520);
PPC_FUNC_IMPL(__imp__sub_8220B520) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x82641cb0
	ctx.lr = 0x8220B558;
	sub_82641CB0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8264f998
	ctx.lr = 0x8220B560;
	sub_8264F998(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8220B580"))) PPC_WEAK_FUNC(sub_8220B580);
PPC_FUNC_IMPL(__imp__sub_8220B580) {
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
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x82641cb0
	ctx.lr = 0x8220B5B0;
	sub_82641CB0(ctx, base);
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

__attribute__((alias("__imp__sub_8220B5CC"))) PPC_WEAK_FUNC(sub_8220B5CC);
PPC_FUNC_IMPL(__imp__sub_8220B5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B5D0"))) PPC_WEAK_FUNC(sub_8220B5D0);
PPC_FUNC_IMPL(__imp__sub_8220B5D0) {
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
	ctx.lr = 0x8220B5D8;
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8220b624
	if (cr6.eq) goto loc_8220B624;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x8220B600;
	sub_82305870(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220B618;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x8220B624;
	sub_823058F8(ctx, base);
loc_8220B624:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8220B62C"))) PPC_WEAK_FUNC(sub_8220B62C);
PPC_FUNC_IMPL(__imp__sub_8220B62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B630"))) PPC_WEAK_FUNC(sub_8220B630);
PPC_FUNC_IMPL(__imp__sub_8220B630) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8220b684
	if (cr6.eq) goto loc_8220B684;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x8220B664;
	sub_82305870(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220B678;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x8220B684;
	sub_823058F8(ctx, base);
loc_8220B684:
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

__attribute__((alias("__imp__sub_8220B69C"))) PPC_WEAK_FUNC(sub_8220B69C);
PPC_FUNC_IMPL(__imp__sub_8220B69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B6A0"))) PPC_WEAK_FUNC(sub_8220B6A0);
PPC_FUNC_IMPL(__imp__sub_8220B6A0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,656(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220B6CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8220B6E8"))) PPC_WEAK_FUNC(sub_8220B6E8);
PPC_FUNC_IMPL(__imp__sub_8220B6E8) {
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
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cc8
	ctx.lr = 0x8220B710;
	sub_82641CC8(ctx, base);
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

__attribute__((alias("__imp__sub_8220B72C"))) PPC_WEAK_FUNC(sub_8220B72C);
PPC_FUNC_IMPL(__imp__sub_8220B72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B730"))) PPC_WEAK_FUNC(sub_8220B730);
PPC_FUNC_IMPL(__imp__sub_8220B730) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r30,r11,672
	r30.s64 = r11.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8220B75C;
	sub_82631F88(ctx, base);
	// lwz r11,184(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8220b770
	if (cr6.lt) goto loc_8220B770;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8220B770:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_8220B78C"))) PPC_WEAK_FUNC(sub_8220B78C);
PPC_FUNC_IMPL(__imp__sub_8220B78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B790"))) PPC_WEAK_FUNC(sub_8220B790);
PPC_FUNC_IMPL(__imp__sub_8220B790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r5,848(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 848);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// lwzx r11,r5,r7
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220B7D0"))) PPC_WEAK_FUNC(sub_8220B7D0);
PPC_FUNC_IMPL(__imp__sub_8220B7D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r5,848(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 848);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// lwzx r11,r5,r7
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220B810"))) PPC_WEAK_FUNC(sub_8220B810);
PPC_FUNC_IMPL(__imp__sub_8220B810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,848(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 848);
	// lwzx r5,r7,r6
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220B834"))) PPC_WEAK_FUNC(sub_8220B834);
PPC_FUNC_IMPL(__imp__sub_8220B834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B838"))) PPC_WEAK_FUNC(sub_8220B838);
PPC_FUNC_IMPL(__imp__sub_8220B838) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,336(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220B864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8220B880"))) PPC_WEAK_FUNC(sub_8220B880);
PPC_FUNC_IMPL(__imp__sub_8220B880) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,208(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220B898"))) PPC_WEAK_FUNC(sub_8220B898);
PPC_FUNC_IMPL(__imp__sub_8220B898) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,952(r31)
	PPC_STORE_U32(r31.u32 + 952, ctx.r10.u32);
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8220B8CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8220b8ec
	if (cr6.eq) goto loc_8220B8EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220B8EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8220B8EC:
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

__attribute__((alias("__imp__sub_8220B900"))) PPC_WEAK_FUNC(sub_8220B900);
PPC_FUNC_IMPL(__imp__sub_8220B900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,952(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 952);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220B918"))) PPC_WEAK_FUNC(sub_8220B918);
PPC_FUNC_IMPL(__imp__sub_8220B918) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lfs f3,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// b 0x826533e8
	sub_826533E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220B95C"))) PPC_WEAK_FUNC(sub_8220B95C);
PPC_FUNC_IMPL(__imp__sub_8220B95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B960"))) PPC_WEAK_FUNC(sub_8220B960);
PPC_FUNC_IMPL(__imp__sub_8220B960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// b 0x82205950
	sub_82205950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220B974"))) PPC_WEAK_FUNC(sub_8220B974);
PPC_FUNC_IMPL(__imp__sub_8220B974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B978"))) PPC_WEAK_FUNC(sub_8220B978);
PPC_FUNC_IMPL(__imp__sub_8220B978) {
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
	// bl 0x82207d30
	ctx.lr = 0x8220B990;
	sub_82207D30(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8220B9B0"))) PPC_WEAK_FUNC(sub_8220B9B0);
PPC_FUNC_IMPL(__imp__sub_8220B9B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220B9E0"))) PPC_WEAK_FUNC(sub_8220B9E0);
PPC_FUNC_IMPL(__imp__sub_8220B9E0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220B9E4"))) PPC_WEAK_FUNC(sub_8220B9E4);
PPC_FUNC_IMPL(__imp__sub_8220B9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220B9E8"))) PPC_WEAK_FUNC(sub_8220B9E8);
PPC_FUNC_IMPL(__imp__sub_8220B9E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addis r3,r11,5
	ctx.r3.s64 = r11.s64 + 327680;
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// b 0x8221bae8
	sub_8221BAE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220BA04"))) PPC_WEAK_FUNC(sub_8220BA04);
PPC_FUNC_IMPL(__imp__sub_8220BA04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220BA08"))) PPC_WEAK_FUNC(sub_8220BA08);
PPC_FUNC_IMPL(__imp__sub_8220BA08) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f7c90
	ctx.lr = 0x8220BA2C;
	sub_821F7C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220ba58
	if (!cr6.eq) goto loc_8220BA58;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4993
	ctx.r9.u64 = ctx.r10.u64 | 4993;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// li r11,0
	r11.s64 = 0;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8220ba5c
	if (cr6.eq) goto loc_8220BA5C;
loc_8220BA58:
	// li r11,1
	r11.s64 = 1;
loc_8220BA5C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8220BA80"))) PPC_WEAK_FUNC(sub_8220BA80);
PPC_FUNC_IMPL(__imp__sub_8220BA80) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r3,r11,192
	ctx.r3.s64 = r11.s64 + 192;
	// bl 0x826bde70
	ctx.lr = 0x8220BAB8;
	sub_826BDE70(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220bacc
	if (cr6.eq) goto loc_8220BACC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8220bad0
	goto loc_8220BAD0;
loc_8220BACC:
	// li r11,0
	r11.s64 = 0;
loc_8220BAD0:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_8220BAE8"))) PPC_WEAK_FUNC(sub_8220BAE8);
PPC_FUNC_IMPL(__imp__sub_8220BAE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// lwz r11,628(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 628);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220BB18"))) PPC_WEAK_FUNC(sub_8220BB18);
PPC_FUNC_IMPL(__imp__sub_8220BB18) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,644(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 644);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220BB4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8220BB6C"))) PPC_WEAK_FUNC(sub_8220BB6C);
PPC_FUNC_IMPL(__imp__sub_8220BB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220BB70"))) PPC_WEAK_FUNC(sub_8220BB70);
PPC_FUNC_IMPL(__imp__sub_8220BB70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,624(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 624);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220BB90"))) PPC_WEAK_FUNC(sub_8220BB90);
PPC_FUNC_IMPL(__imp__sub_8220BB90) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,640(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 640);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220BBC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_8220BBE4"))) PPC_WEAK_FUNC(sub_8220BBE4);
PPC_FUNC_IMPL(__imp__sub_8220BBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220BBE8"))) PPC_WEAK_FUNC(sub_8220BBE8);
PPC_FUNC_IMPL(__imp__sub_8220BBE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,620(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 620);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220BC08"))) PPC_WEAK_FUNC(sub_8220BC08);
PPC_FUNC_IMPL(__imp__sub_8220BC08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,636(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 636);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220BC3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_8220BC5C"))) PPC_WEAK_FUNC(sub_8220BC5C);
PPC_FUNC_IMPL(__imp__sub_8220BC5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220BC60"))) PPC_WEAK_FUNC(sub_8220BC60);
PPC_FUNC_IMPL(__imp__sub_8220BC60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82207240
	sub_82207240(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220BC80"))) PPC_WEAK_FUNC(sub_8220BC80);
PPC_FUNC_IMPL(__imp__sub_8220BC80) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220BC84"))) PPC_WEAK_FUNC(sub_8220BC84);
PPC_FUNC_IMPL(__imp__sub_8220BC84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220BC88"))) PPC_WEAK_FUNC(sub_8220BC88);
PPC_FUNC_IMPL(__imp__sub_8220BC88) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220bcb8
	if (cr6.eq) goto loc_8220BCB8;
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822072a8
	ctx.lr = 0x8220BCB4;
	sub_822072A8(ctx, base);
	// b 0x8220bcbc
	goto loc_8220BCBC;
loc_8220BCB8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8220BCBC:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220BCD8"))) PPC_WEAK_FUNC(sub_8220BCD8);
PPC_FUNC_IMPL(__imp__sub_8220BCD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220bd20
	if (cr6.eq) goto loc_8220BD20;
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,6108
	ctx.r10.s64 = ctx.r10.s64 + 6108;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220bd20
	if (cr6.eq) goto loc_8220BD20;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// bne cr6,0x8220bd20
	if (!cr6.eq) goto loc_8220BD20;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lbz r10,25(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 25);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220bd24
	if (cr6.eq) goto loc_8220BD24;
loc_8220BD20:
	// li r11,0
	r11.s64 = 0;
loc_8220BD24:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220BD34"))) PPC_WEAK_FUNC(sub_8220BD34);
PPC_FUNC_IMPL(__imp__sub_8220BD34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220BD38"))) PPC_WEAK_FUNC(sub_8220BD38);
PPC_FUNC_IMPL(__imp__sub_8220BD38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220bd64
	if (cr6.eq) goto loc_8220BD64;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r11,25(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_8220BD64:
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

__attribute__((alias("__imp__sub_8220BD78"))) PPC_WEAK_FUNC(sub_8220BD78);
PPC_FUNC_IMPL(__imp__sub_8220BD78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220BD8C"))) PPC_WEAK_FUNC(sub_8220BD8C);
PPC_FUNC_IMPL(__imp__sub_8220BD8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220BD90"))) PPC_WEAK_FUNC(sub_8220BD90);
PPC_FUNC_IMPL(__imp__sub_8220BD90) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-12632
	ctx.r10.s64 = r11.s64 + -12632;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8220BDBC;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220bdd4
	if (cr6.eq) goto loc_8220BDD4;
	// bl 0x82130588
	ctx.lr = 0x8220BDD0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8220BDD4:
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

__attribute__((alias("__imp__sub_8220BDEC"))) PPC_WEAK_FUNC(sub_8220BDEC);
PPC_FUNC_IMPL(__imp__sub_8220BDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220BDF0"))) PPC_WEAK_FUNC(sub_8220BDF0);
PPC_FUNC_IMPL(__imp__sub_8220BDF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,8(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stwx r9,r5,r11
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, ctx.r9.u32);
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
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
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// lwz r7,12(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lfs f11,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r6,r5,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r5,r9,2
	ctx.r5.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r7,r6,r11
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, ctx.r7.u32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f9,4(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f10,8(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lfs f8,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f6,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r7,r6,r11
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, ctx.r7.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f8,0(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f6,4(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f7,8(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220BF08"))) PPC_WEAK_FUNC(sub_8220BF08);
PPC_FUNC_IMPL(__imp__sub_8220BF08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,0(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stwx r4,r5,r11
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, ctx.r4.u32);
	// lfs f0,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
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
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lfs f11,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r9,2
	ctx.r3.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r5,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r5.u32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f9,4(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f10,8(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lfs f8,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f6,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r5,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r5.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f8,0(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f6,4(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f7,8(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
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
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220C018"))) PPC_WEAK_FUNC(sub_8220C018);
PPC_FUNC_IMPL(__imp__sub_8220C018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stwx r5,r6,r4
	PPC_STORE_U32(ctx.r6.u32 + ctx.r4.u32, ctx.r5.u32);
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r6,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r6.u32);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,2
	r11.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r8.u32);
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220C0D0"))) PPC_WEAK_FUNC(sub_8220C0D0);
PPC_FUNC_IMPL(__imp__sub_8220C0D0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8220C0D8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// lwz r5,40(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lwz r30,32(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// lwz r28,44(r6)
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	// lwz r27,48(r6)
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	// lwz r26,52(r6)
	r26.u64 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lwz r29,36(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// xori r25,r3,1
	r25.u64 = ctx.r3.u64 ^ 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r26,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r26.u32);
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// stb r25,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r25.u8);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8220C150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8220C160"))) PPC_WEAK_FUNC(sub_8220C160);
PPC_FUNC_IMPL(__imp__sub_8220C160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// bl 0x823d91d4
	ctx.lr = 0x8220C168;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd524
	ctx.lr = 0x8220C174;
	// stwu r1,-1536(r1)
	ea = -1536 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x8220cbd4
	if (cr6.gt) goto loc_8220CBD4;
	// lis r12,-32223
	r12.s64 = -2111766528;
	// addi r12,r12,-15952
	r12.s64 = r12.s64 + -15952;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8220C1E4;
	case 1:
		goto loc_8220C1E4;
	case 2:
		goto loc_8220CBD4;
	case 3:
		goto loc_8220C1E4;
	case 4:
		goto loc_8220C1F8;
	case 5:
		goto loc_8220C1F8;
	case 6:
		goto loc_8220CBD4;
	case 7:
		goto loc_8220CBD4;
	case 8:
		goto loc_8220C930;
	case 9:
		goto loc_8220CBD4;
	case 10:
		goto loc_8220C260;
	case 11:
		goto loc_8220CBD4;
	case 12:
		goto loc_8220CA8C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-15900(0)
	r17.u64 = PPC_LOAD_U32(-15900);
	// lwz r17,-15900(0)
	r17.u64 = PPC_LOAD_U32(-15900);
	// lwz r17,-13356(0)
	r17.u64 = PPC_LOAD_U32(-13356);
	// lwz r17,-15900(0)
	r17.u64 = PPC_LOAD_U32(-15900);
	// lwz r17,-15880(0)
	r17.u64 = PPC_LOAD_U32(-15880);
	// lwz r17,-15880(0)
	r17.u64 = PPC_LOAD_U32(-15880);
	// lwz r17,-13356(0)
	r17.u64 = PPC_LOAD_U32(-13356);
	// lwz r17,-13356(0)
	r17.u64 = PPC_LOAD_U32(-13356);
	// lwz r17,-14032(0)
	r17.u64 = PPC_LOAD_U32(-14032);
	// lwz r17,-13356(0)
	r17.u64 = PPC_LOAD_U32(-13356);
	// lwz r17,-15776(0)
	r17.u64 = PPC_LOAD_U32(-15776);
	// lwz r17,-13356(0)
	r17.u64 = PPC_LOAD_U32(-13356);
	// lwz r17,-13684(0)
	r17.u64 = PPC_LOAD_U32(-13684);
loc_8220C1E4:
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257a648
	ctx.lr = 0x8220C1F4;
	sub_8257A648(ctx, base);
	// b 0x8220cbd4
	goto loc_8220CBD4;
loc_8220C1F8:
	// lwz r27,204(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 204);
	// li r28,0
	r28.s64 = 0;
	// lwz r26,128(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// mr r30,r28
	r30.u64 = r28.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8220c240
	if (!cr6.gt) goto loc_8220C240;
loc_8220C210:
	// sth r30,60(r31)
	PPC_STORE_U16(r31.u32 + 60, r30.u16);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r11,140(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// bl 0x8257c088
	ctx.lr = 0x8220C230;
	sub_8257C088(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,16
	r28.s64 = r28.s64 + 16;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x8220c210
	if (cr6.lt) goto loc_8220C210;
loc_8220C240:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bne cr6,0x8220cbd4
	if (!cr6.eq) goto loc_8220CBD4;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257a648
	ctx.lr = 0x8220C25C;
	sub_8257A648(ctx, base);
	// b 0x8220cbd4
	goto loc_8220CBD4;
loc_8220C260:
	// lwz r11,176(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8220cbd4
	if (cr6.eq) goto loc_8220CBD4;
	// lbz r11,2484(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2484);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220c288
	if (cr6.eq) goto loc_8220C288;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x8220c288
	if (cr6.eq) goto loc_8220C288;
	// lhz r6,8(r19)
	ctx.r6.u64 = PPC_LOAD_U16(r19.u32 + 8);
	// b 0x8220c28c
	goto loc_8220C28C;
loc_8220C288:
	// li r6,-1
	ctx.r6.s64 = -1;
loc_8220C28C:
	// addi r23,r31,224
	r23.s64 = r31.s64 + 224;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576508
	ctx.lr = 0x8220C2A0;
	sub_82576508(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8220c314
	if (cr6.eq) goto loc_8220C314;
loc_8220C2AC:
	// lbz r11,2504(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2504);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220c314
	if (cr6.eq) goto loc_8220C314;
	// lwz r3,2496(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2496);
	// lwz r11,2500(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2500);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220c2dc
	if (cr6.eq) goto loc_8220C2DC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8220C2D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8220c2ec
	goto loc_8220C2EC;
loc_8220C2DC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8220C2EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8220C2EC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220c314
	if (!cr6.eq) goto loc_8220C314;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256e170
	ctx.lr = 0x8220C308;
	sub_8256E170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8220c2ac
	if (!cr6.eq) goto loc_8220C2AC;
loc_8220C314:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r28,0
	r28.s64 = 0;
	// lbz r10,-23460(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23460);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8220c34c
	if (!cr6.eq) goto loc_8220C34C;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r11,r1,106
	r11.s64 = ctx.r1.s64 + 106;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
loc_8220C338:
	// sth r28,-6(r11)
	PPC_STORE_U16(r11.u32 + -6, r28.u16);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r9,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r9.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x8220c338
	if (!cr0.eq) goto loc_8220C338;
loc_8220C34C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8220cbd4
	if (cr6.eq) goto loc_8220CBD4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r26,1
	r26.s64 = 1;
	// li r27,2
	r27.s64 = 2;
	// li r25,4
	r25.s64 = 4;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_8220C368:
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220c3d8
	if (!cr6.eq) goto loc_8220C3D8;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82204be0
	ctx.lr = 0x8220C38C;
	sub_82204BE0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// sth r28,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r28.u16);
	// sth r26,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r26.u16);
	// sth r27,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, r27.u16);
	// bl 0x8257c088
	ctx.lr = 0x8220C3D4;
	sub_8257C088(ctx, base);
	// b 0x8220c8c4
	goto loc_8220C8C4;
loc_8220C3D8:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8220c490
	if (!cr6.eq) goto loc_8220C490;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82582c08
	ctx.lr = 0x8220C3EC;
	sub_82582C08(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// bl 0x822030e0
	ctx.lr = 0x8220C3FC;
	sub_822030E0(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
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
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vpermwi128 v60,v61,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// vpermwi128 v59,v61,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v58,v61,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82576308
	ctx.lr = 0x8220C440;
	sub_82576308(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257a648
	ctx.lr = 0x8220C450;
	sub_8257A648(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8220c46c
	if (cr6.eq) goto loc_8220C46C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8220C46C;
	sub_8257DC50(ctx, base);
loc_8220C46C:
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576410
	ctx.lr = 0x8220C478;
	sub_82576410(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82582fd0
	ctx.lr = 0x8220C484;
	sub_82582FD0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x825824f8
	ctx.lr = 0x8220C48C;
	sub_825824F8(ctx, base);
	// b 0x8220c8c4
	goto loc_8220C8C4;
loc_8220C490:
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8220c65c
	if (!cr6.eq) goto loc_8220C65C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lhz r24,8(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x822030e0
	ctx.lr = 0x8220C4AC;
	sub_822030E0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// lvx128 v125,r0,r10
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822030e0
	ctx.lr = 0x8220C4C4;
	sub_822030E0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// lvx128 v124,r0,r9
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v127,v124,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v125.f32)));
	// bl 0x825822f0
	ctx.lr = 0x8220C4D8;
	sub_825822F0(ctx, base);
	// vmsum3fp128 v126,v127,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v126.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v127.f32), 0xEF));
	// lvlx128 v56,r30,r25
	temp.u32 = r30.u32 + r25.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// vspltw128 v1,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vrsqrtefp128 v57,v126
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// vrefp128 v2,v57
	simde_mm_store_ps(ctx.v2.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v57.f32)));
	// bl 0x82581500
	ctx.lr = 0x8220C4F4;
	sub_82581500(ctx, base);
	// vspltisw128 v55,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_set1_epi32(int(0x0)));
	// vor128 v0,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vspltisw128 v54,-1
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// vor128 v13,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vupkd3d128 v63,v55,4
	temp.f32 = 3.0f;
	temp.s32 += v55.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v55.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v63 = vTemp;
	// vor128 v12,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vpermwi128 v53,v55,24
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xE7));
	// vrlimi128 v13,v54,4,0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_permute_ps(simde_mm_load_ps(v54.f32), 228), 4));
	// vpermwi128 v52,v63,234
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// vpermwi128 v51,v63,186
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v50,v63,174
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// vsel v11,v0,v12,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// stvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v49,v11,24
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0xE7));
	// stvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v48,v49,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v53.f32)));
	cr6.setFromMask(simde_mm_load_ps(v48.f32), 0xF);
	// mfocrf r5,2
	ctx.r5.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r4,r5,0,24,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8220c5e8
	if (!cr6.eq) goto loc_8220C5E8;
	// vpermwi128 v47,v63,187
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x44));
	// vrsqrtefp128 v0,v126
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// vpermwi128 v46,v127,99
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// vor128 v12,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vpermwi128 v11,v127,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// vspltisw128 v45,1
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// vpermwi128 v44,v47,135
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x78));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// vpermwi128 v10,v47,99
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x9C));
	// vspltw128 v13,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vcuxwfp128 v43,v45,1
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v45.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vmulfp128 v9,v46,v44
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v44.f32)));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v43,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v11,v10,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v5,v12,v8,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v42,v6,v6
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v6.f32), 0xEF));
	// vmaddfp v4,v5,v7,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vrsqrtefp128 v0,v42
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v42.f32))));
	// vor128 v3,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// vmulfp128 v63,v127,v4
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vmulfp128 v1,v0,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v31,v43,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vpermwi128 v41,v63,135
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v2,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v30,v3,v1,v13
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v29,v30,v31,v0
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v63,v6,v29
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(v29.f32)));
	// vpermwi128 v40,v63,99
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v28,v63,135
	simde_mm_store_si128((simde__m128i*)v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmulfp128 v27,v40,v41
	simde_mm_store_ps(v27.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v41.f32)));
	// vnmsubfp v26,v28,v2,v27
	simde_mm_store_ps(v26.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v27.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v26,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8220C5E8:
	// vspltisw128 v39,1
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_set1_epi32(int(0x1)));
	// vaddfp128 v38,v125,v124
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v38.f32, simde_mm_add_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v124.f32)));
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vcuxwfp128 v37,v39,1
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v39.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vmulfp128 v36,v38,v37
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v37.f32)));
	// stvx128 v36,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82576308
	ctx.lr = 0x8220C60C;
	sub_82576308(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257a648
	ctx.lr = 0x8220C61C;
	sub_8257A648(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220c638
	if (cr6.eq) goto loc_8220C638;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8220C638;
	sub_8257DC50(ctx, base);
loc_8220C638:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576410
	ctx.lr = 0x8220C644;
	sub_82576410(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82582fd0
	ctx.lr = 0x8220C650;
	sub_82582FD0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82581548
	ctx.lr = 0x8220C658;
	sub_82581548(ctx, base);
	// b 0x8220c8c4
	goto loc_8220C8C4;
loc_8220C65C:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8220c8c4
	if (!cr6.eq) goto loc_8220C8C4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lhz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// lhz r24,6(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r22,8(r30)
	r22.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// lhz r30,10(r30)
	r30.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// bl 0x822030e0
	ctx.lr = 0x8220C680;
	sub_822030E0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822030e0
	ctx.lr = 0x8220C698;
	sub_822030E0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// lvx128 v125,r0,r9
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822030e0
	ctx.lr = 0x8220C6B0;
	sub_822030E0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// lvx128 v124,r0,r8
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822030e0
	ctx.lr = 0x8220C6C8;
	sub_822030E0(ctx, base);
	// lvx128 v35,r0,r3
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v34,1
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_set1_epi32(int(0x1)));
	// vaddfp128 v33,v125,v35
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v33.f32, simde_mm_add_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v35.f32)));
	// vspltisw128 v123,0
	simde_mm_store_si128((simde__m128i*)v123.u32, simde_mm_set1_epi32(int(0x0)));
	// vaddfp128 v32,v126,v35
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v35.f32)));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// vaddfp128 v63,v124,v35
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v35.f32)));
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// vcuxwfp128 v122,v34,1
	simde_mm_store_ps(v122.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v34.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// vaddfp128 v61,v126,v125
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v125.f32)));
	// vupkd3d128 v62,v123,4
	temp.f32 = 3.0f;
	temp.s32 += v123.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v123.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// vspltw128 v127,v62,3
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x0));
	// vsubfp128 v60,v33,v126
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v126.f32)));
	// vor128 v11,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vsubfp128 v59,v32,v125
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v125.f32)));
	// vor128 v10,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vsubfp128 v58,v63,v126
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v126.f32)));
	// vor128 v9,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vor128 v57,v122,v122
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_load_si128((simde__m128i*)v122.u8));
	// vaddfp128 v56,v61,v124
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v124.f32)));
	// vmulfp128 v40,v57,v57
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32)));
	// vsubfp128 v55,v60,v124
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v124.f32)));
	// vsubfp128 v54,v59,v124
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v124.f32)));
	// vsubfp128 v53,v58,v125
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v125.f32)));
	// vaddfp128 v52,v56,v35
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v35.f32)));
	// vmulfp128 v51,v57,v55
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v55.f32)));
	// vmulfp128 v50,v57,v54
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v54.f32)));
	// vmulfp128 v49,v57,v53
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v53.f32)));
	// vmsum3fp128 v126,v51,v51
	simde_mm_store_ps(v126.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmsum3fp128 v125,v50,v50
	simde_mm_store_ps(v125.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vmsum3fp128 v124,v49,v49
	simde_mm_store_ps(v124.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vrsqrtefp128 v0,v126
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// vor128 v48,v126,v126
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vrsqrtefp128 v13,v125
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v125.f32))));
	// vor128 v47,v125,v125
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// vrsqrtefp128 v12,v124
	simde_mm_store_ps(ctx.v12.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v124.f32))));
	// vor128 v46,v124,v124
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// vmulfp128 v45,v0,v0
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v44,v13,v13
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v8,v122,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v122,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v43,v12,v12
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v6,v122,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vnmsubfp128 v11,v48,v45,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v45.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v10,v47,v44,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v44.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v9,v46,v43,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v43.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v11,v8,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v4,v10,v7,v13
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v3,v9,v6,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v42,v51,v5
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v5.f32)));
	// vmulfp128 v41,v50,v4
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vmulfp128 v39,v49,v3
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(ctx.v3.f32)));
	// stvx128 v42,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v38,v40,v52
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v52.f32)));
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// stvx128 v39,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825807e0
	ctx.lr = 0x8220C7CC;
	sub_825807E0(ctx, base);
	// vrsqrtefp128 v0,v124
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v124.f32))));
	// vrsqrtefp128 v13,v126
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// vor128 v37,v124,v124
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// vrsqrtefp128 v12,v125
	simde_mm_store_ps(ctx.v12.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v125.f32))));
	// vor128 v36,v126,v126
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vor128 v2,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vcmpeqfp128 v1,v124,v123
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v123.f32)));
	// vor128 v31,v127,v127
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vcmpeqfp128 v30,v126,v123
	simde_mm_store_ps(v30.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v123.f32)));
	// vor128 v35,v125,v125
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// vcmpeqfp128 v29,v125,v123
	simde_mm_store_ps(v29.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v123.f32)));
	// vor128 v28,v127,v127
	simde_mm_store_si128((simde__m128i*)v28.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// vor128 v27,v123,v123
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// vor128 v26,v123,v123
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// vor128 v25,v123,v123
	simde_mm_store_si128((simde__m128i*)v25.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// vmulfp128 v34,v0,v0
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v33,v13,v13
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v32,v12,v12
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v24,v122,v0
	simde_mm_store_ps(v24.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v23,v122,v13
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v22,v122,v12
	simde_mm_store_ps(v22.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vnmsubfp128 v2,v37,v34,v2
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v34.f32)), simde_mm_load_ps(ctx.v2.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v31,v36,v33,v31
	simde_mm_store_ps(v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v33.f32)), simde_mm_load_ps(v31.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v28,v35,v32,v28
	simde_mm_store_ps(v28.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v32.f32)), simde_mm_load_ps(v28.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v21,v2,v24,v0
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v24.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v20,v31,v23,v13
	simde_mm_store_ps(v20.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v23.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v19,v28,v22,v12
	simde_mm_store_ps(v19.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(v22.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v18,v124,v21
	simde_mm_store_ps(v18.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v21.f32)));
	// vmulfp128 v17,v126,v20
	simde_mm_store_ps(v17.f32, simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v20.f32)));
	// vmulfp128 v16,v125,v19
	simde_mm_store_ps(v16.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v19.f32)));
	// vsel v15,v18,v27,v1
	simde_mm_store_si128((simde__m128i*)v15.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v27.u8))));
	// vsel v14,v17,v26,v30
	simde_mm_store_si128((simde__m128i*)v14.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)v17.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)v26.u8))));
	// vsel v0,v16,v25,v29
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)v16.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)v25.u8))));
	// vmrghw128 v63,v14,v15
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v15.u32), simde_mm_load_si128((simde__m128i*)v14.u32)));
	// vmrghw128 v62,v63,v0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82580018
	ctx.lr = 0x8220C86C;
	sub_82580018(ctx, base);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576308
	ctx.lr = 0x8220C878;
	sub_82576308(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,752
	ctx.r4.s64 = ctx.r1.s64 + 752;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257a648
	ctx.lr = 0x8220C888;
	sub_8257A648(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220c8a4
	if (cr6.eq) goto loc_8220C8A4;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8220C8A4;
	sub_8257DC50(ctx, base);
loc_8220C8A4:
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576410
	ctx.lr = 0x8220C8B0;
	sub_82576410(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x82582fd0
	ctx.lr = 0x8220C8BC;
	sub_82582FD0(ctx, base);
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x8257fe30
	ctx.lr = 0x8220C8C4;
	sub_8257FE30(ctx, base);
loc_8220C8C4:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256e170
	ctx.lr = 0x8220C8D4;
	sub_8256E170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8220cbd4
	if (cr6.eq) goto loc_8220CBD4;
	// lbz r11,2504(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2504);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220c368
	if (cr6.eq) goto loc_8220C368;
	// lwz r3,2496(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2496);
	// lwz r11,2500(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2500);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220c910
	if (cr6.eq) goto loc_8220C910;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8220C90C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8220c920
	goto loc_8220C920;
loc_8220C910:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8220C920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8220C920:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220c8c4
	if (cr6.eq) goto loc_8220C8C4;
	// b 0x8220c368
	goto loc_8220C368;
loc_8220C930:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825771a0
	ctx.lr = 0x8220C93C;
	sub_825771A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r25,16
	r25.s64 = 16;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x8220ca68
	if (cr6.eq) goto loc_8220CA68;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r28,0
	r28.s64 = 0;
	// addi r26,r11,-31472
	r26.s64 = r11.s64 + -31472;
loc_8220C958:
	// lhz r11,164(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220c990
	if (cr6.eq) goto loc_8220C990;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8220c990
	if (cr6.lt) goto loc_8220C990;
	// lwz r11,156(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 156);
	// lwz r10,144(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 144);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// bge cr6,0x8220c990
	if (!cr6.lt) goto loc_8220C990;
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8220c998
	goto loc_8220C998;
loc_8220C990:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_8220C998:
	// lwz r27,0(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8220ca4c
	if (cr6.eq) goto loc_8220CA4C;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82203400
	ctx.lr = 0x8220C9B8;
	sub_82203400(ctx, base);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v63,v60,v63
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8220c160
	ctx.lr = 0x8220CA04;
	sub_8220C160(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8220ca4c
	if (cr6.eq) goto loc_8220CA4C;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// clrlwi r4,r30,16
	ctx.r4.u64 = r30.u32 & 0xFFFF;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r7,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r7.u32);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// stw r5,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r5.u32);
	// bl 0x825789c0
	ctx.lr = 0x8220CA40;
	sub_825789C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578ab0
	ctx.lr = 0x8220CA4C;
	sub_82578AB0(ctx, base);
loc_8220CA4C:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575b68
	ctx.lr = 0x8220CA5C;
	sub_82575B68(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x8220c958
	if (!cr6.eq) goto loc_8220C958;
loc_8220CA68:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r11,-31488
	ctx.r10.s64 = r11.s64 + -31488;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v59,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8220cbcc
	goto loc_8220CBCC;
loc_8220CA8C:
	// lhz r22,146(r29)
	r22.u64 = PPC_LOAD_U16(r29.u32 + 146);
	// li r28,0
	r28.s64 = 0;
	// mr r27,r28
	r27.u64 = r28.u64;
	// mr r23,r22
	r23.u64 = r22.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x8220cbcc
	if (!cr6.gt) goto loc_8220CBCC;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r25,r28
	r25.u64 = r28.u64;
	// mr r24,r28
	r24.u64 = r28.u64;
loc_8220CAB0:
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// lwzx r28,r11,r24
	r28.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8220cbb4
	if (cr6.eq) goto loc_8220CBB4;
	// lwz r11,148(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 148);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8220caf0
	if (cr6.eq) goto loc_8220CAF0;
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// and r9,r10,r21
	ctx.r9.u64 = ctx.r10.u64 & r21.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220cbb4
	if (cr6.eq) goto loc_8220CBB4;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// and r10,r11,r20
	ctx.r10.u64 = r11.u64 & r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220cbb4
	if (cr6.eq) goto loc_8220CBB4;
loc_8220CAF0:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82576308
	ctx.lr = 0x8220CB04;
	sub_82576308(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825764c8
	ctx.lr = 0x8220CB10;
	sub_825764C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220cb94
	if (!cr6.eq) goto loc_8220CB94;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8220c160
	ctx.lr = 0x8220CB34;
	sub_8220C160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220cb94
	if (cr6.eq) goto loc_8220CB94;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// or r11,r7,r9
	r11.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// bl 0x82578a38
	ctx.lr = 0x8220CB78;
	sub_82578A38(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8220CB88;
	sub_8257DC50(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8220cbcc
	if (!cr6.eq) goto loc_8220CBCC;
loc_8220CB94:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576410
	ctx.lr = 0x8220CBA0;
	sub_82576410(ctx, base);
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x8220cbb4
	if (!cr6.eq) goto loc_8220CBB4;
	// lhz r11,146(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 146);
	// add r23,r11,r23
	r23.u64 = r11.u64 + r23.u64;
loc_8220CBB4:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// addi r26,r26,64
	r26.s64 = r26.s64 + 64;
	// cmpw cr6,r27,r22
	cr6.compare<int32_t>(r27.s32, r22.s32, xer);
	// blt cr6,0x8220cab0
	if (cr6.lt) goto loc_8220CAB0;
loc_8220CBCC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578dd8
	ctx.lr = 0x8220CBD4;
	sub_82578DD8(ctx, base);
loc_8220CBD4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575b48
	ctx.lr = 0x8220CBDC;
	sub_82575B48(ctx, base);
	// addi r1,r1,1536
	ctx.r1.s64 = ctx.r1.s64 + 1536;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd7bc
	ctx.lr = 0x8220CBE8;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8220CBF0"))) PPC_WEAK_FUNC(sub_8220CBF0);
PPC_FUNC_IMPL(__imp__sub_8220CBF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// lfs f1,27640(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82208930
	sub_82208930(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220CC10"))) PPC_WEAK_FUNC(sub_8220CC10);
PPC_FUNC_IMPL(__imp__sub_8220CC10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8220CC18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x8220CC30;
	sub_82305870(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82208b08
	ctx.lr = 0x8220CC38;
	sub_82208B08(ctx, base);
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// addi r29,r29,16256
	r29.s64 = r29.s64 + 16256;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220CC54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-12248
	ctx.r4.s64 = ctx.r9.s64 + -12248;
	// lwz r3,-10236(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8220CC68;
	sub_821F9FB8(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,196(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// lwz r4,56(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8220CC84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,109
	ctx.r4.s64 = 109;
	// bl 0x82641cb0
	ctx.lr = 0x8220CC90;
	sub_82641CB0(ctx, base);
	// addi r3,r3,2832
	ctx.r3.s64 = ctx.r3.s64 + 2832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8220CCA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,109
	ctx.r4.s64 = 109;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8220CCB4;
	sub_82641CB0(ctx, base);
	// addi r3,r3,2832
	ctx.r3.s64 = ctx.r3.s64 + 2832;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220CCC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,3568
	ctx.r3.s64 = ctx.r3.s64 + 3568;
	// bl 0x8223d300
	ctx.lr = 0x8220CCD4;
	sub_8223D300(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r8,-12464
	ctx.r4.s64 = ctx.r8.s64 + -12464;
	// bl 0x821f9fb8
	ctx.lr = 0x8220CCE4;
	sub_821F9FB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82720e28
	ctx.lr = 0x8220CCEC;
	sub_82720E28(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r29,r7,-11876
	r29.s64 = ctx.r7.s64 + -11876;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8220CD00;
	sub_821F9FB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82720e28
	ctx.lr = 0x8220CD08;
	sub_82720E28(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r6,-18768
	ctx.r4.s64 = ctx.r6.s64 + -18768;
	// bl 0x821f9fb8
	ctx.lr = 0x8220CD18;
	sub_821F9FB8(ctx, base);
	// lwz r5,56(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stb r3,315(r5)
	PPC_STORE_U8(ctx.r5.u32 + 315, ctx.r3.u8);
	// lwz r3,-10236(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8220CD30;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r5,5528(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 5528);
	// lwz r4,5532(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 5532);
	// bl 0x82722a00
	ctx.lr = 0x8220CD44;
	sub_82722A00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203740
	ctx.lr = 0x8220CD4C;
	sub_82203740(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220CD68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r8,-11900
	ctx.r4.s64 = ctx.r8.s64 + -11900;
	// lwz r27,56(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8220CD84;
	sub_82218310(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-11916
	ctx.r4.s64 = ctx.r7.s64 + -11916;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8220CD98;
	sub_825EE2D8(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r4,r6,-11940
	ctx.r4.s64 = ctx.r6.s64 + -11940;
	// lwz r29,56(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// bl 0x82218310
	ctx.lr = 0x8220CDAC;
	sub_82218310(ctx, base);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-11952
	ctx.r4.s64 = ctx.r4.s64 + -11952;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8220CDC0;
	sub_825EE2D8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,-18780
	ctx.r4.s64 = r11.s64 + -18780;
	// bl 0x821f9fb8
	ctx.lr = 0x8220CDD0;
	sub_821F9FB8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r8,-11956
	ctx.r4.s64 = ctx.r8.s64 + -11956;
	// lwz r31,56(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// bl 0x823db730
	ctx.lr = 0x8220CDEC;
	sub_823DB730(ctx, base);
	// cntlzw r7,r3
	ctx.r7.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r4,r6,-11964
	ctx.r4.s64 = ctx.r6.s64 + -11964;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8220CE04;
	sub_825EE0E0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r4,r5,-11976
	ctx.r4.s64 = ctx.r5.s64 + -11976;
	// lwz r11,-10232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10232);
	// addi r3,r11,10260
	ctx.r3.s64 = r11.s64 + 10260;
	// bl 0x82724108
	ctx.lr = 0x8220CE1C;
	sub_82724108(ctx, base);
	// lwz r11,-10232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10232);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r3,r11,10260
	ctx.r3.s64 = r11.s64 + 10260;
	// addi r4,r4,-11992
	ctx.r4.s64 = ctx.r4.s64 + -11992;
	// bl 0x82724108
	ctx.lr = 0x8220CE30;
	sub_82724108(ctx, base);
	// lwz r11,-10232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10232);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,10260
	ctx.r3.s64 = r11.s64 + 10260;
	// addi r4,r10,-12008
	ctx.r4.s64 = ctx.r10.s64 + -12008;
	// bl 0x82724108
	ctx.lr = 0x8220CE44;
	sub_82724108(ctx, base);
	// lwz r11,-10232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10232);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r3,r11,10260
	ctx.r3.s64 = r11.s64 + 10260;
	// addi r4,r9,-12024
	ctx.r4.s64 = ctx.r9.s64 + -12024;
	// bl 0x82724108
	ctx.lr = 0x8220CE58;
	sub_82724108(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x8220CE64;
	sub_823058F8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8220CE6C"))) PPC_WEAK_FUNC(sub_8220CE6C);
PPC_FUNC_IMPL(__imp__sub_8220CE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220CE70"))) PPC_WEAK_FUNC(sub_8220CE70);
PPC_FUNC_IMPL(__imp__sub_8220CE70) {
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
	ctx.lr = 0x8220CE78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,16
	r30.s64 = 16;
	// li r3,64
	ctx.r3.s64 = 64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// sth r30,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r30.u16);
	// bl 0x82130528
	ctx.lr = 0x8220CE94;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// sth r30,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r30.u16);
	// addis r31,r29,1
	r31.s64 = r29.s64 + 65536;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// lis r11,1
	r11.s64 = 65536;
	// addi r31,r31,6100
	r31.s64 = r31.s64 + 6100;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r30,r28
	r30.u64 = r28.u64;
	// ori r5,r11,6112
	ctx.r5.u64 = r11.u64 | 6112;
loc_8220CEBC:
	// stwx r27,r6,r28
	PPC_STORE_U32(ctx.r6.u32 + r28.u32, r27.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r10,r6,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220cf40
	if (cr6.eq) goto loc_8220CF40;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lbz r11,25(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220cf04
	if (!cr6.eq) goto loc_8220CF04;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220cef8
	if (cr6.eq) goto loc_8220CEF8;
	// lbz r11,24(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220cf04
	if (!cr6.eq) goto loc_8220CF04;
loc_8220CEF8:
	// stw r4,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r4.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// b 0x8220cf40
	goto loc_8220CF40;
loc_8220CF04:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82207240
	ctx.lr = 0x8220CF0C;
	sub_82207240(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r10,r29,r5
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + ctx.r5.u32);
	// lwzx r11,r6,r11
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220cf38
	if (cr6.eq) goto loc_8220CF38;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// lhz r11,6(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r8.u16);
loc_8220CF38:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r27,r6,r11
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, r27.u32);
loc_8220CF40:
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmpwi cr6,r6,64
	cr6.compare<int32_t>(ctx.r6.s32, 64, xer);
	// blt cr6,0x8220cebc
	if (cr6.lt) goto loc_8220CEBC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x8220cf84
	if (cr6.eq) goto loc_8220CF84;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// beq cr6,0x8220cf78
	if (cr6.eq) goto loc_8220CF78;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220cf78
	if (cr6.eq) goto loc_8220CF78;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8220CF78;
	sub_82130588(ctx, base);
loc_8220CF78:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c7480
	ctx.lr = 0x8220CF84;
	sub_826C7480(ctx, base);
loc_8220CF84:
	// lis r11,1
	r11.s64 = 65536;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// ori r10,r11,6108
	ctx.r10.u64 = r11.u64 | 6108;
	// stwx r27,r29,r10
	PPC_STORE_U32(r29.u32 + ctx.r10.u32, r27.u32);
	// bl 0x82130588
	ctx.lr = 0x8220CF98;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8220CFA0"))) PPC_WEAK_FUNC(sub_8220CFA0);
PPC_FUNC_IMPL(__imp__sub_8220CFA0) {
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
	ctx.lr = 0x8220CFA8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	r29.s64 = ctx.r3.s64 + 65536;
	// li r27,0
	r27.s64 = 0;
	// addi r29,r29,6104
	r29.s64 = r29.s64 + 6104;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// lhz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8220d01c
	if (!cr6.gt) goto loc_8220D01C;
	// addis r30,r3,1
	r30.s64 = ctx.r3.s64 + 65536;
	// addi r30,r30,6100
	r30.s64 = r30.s64 + 6100;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_8220CFD8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220d014
	if (cr6.eq) goto loc_8220D014;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bgt cr6,0x8220d014
	if (cr6.gt) goto loc_8220D014;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x8220cfd8
	if (cr6.lt) goto loc_8220CFD8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8220D014:
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x8220d028
	if (!cr6.eq) goto loc_8220D028;
loc_8220D01C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8220D028:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// sth r27,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r27.u16);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// sth r27,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r27.u16);
	// beq cr6,0x8220d050
	if (cr6.eq) goto loc_8220D050;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826c7480
	ctx.lr = 0x8220D04C;
	sub_826C7480(ctx, base);
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8220D050:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220d0e8
	if (cr6.eq) goto loc_8220D0E8;
	// stwx r28,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, r28.u32);
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// bge cr6,0x8220d0a8
	if (!cr6.lt) goto loc_8220D0A8;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_8220D080:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// cmpw cr6,r31,r7
	cr6.compare<int32_t>(r31.s32, ctx.r7.s32, xer);
	// blt cr6,0x8220d080
	if (cr6.lt) goto loc_8220D080;
loc_8220D0A8:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x8220d0ec
	if (cr6.eq) goto loc_8220D0EC;
	// lhz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x8220d0d8
	if (cr6.eq) goto loc_8220D0D8;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220d0d8
	if (cr6.eq) goto loc_8220D0D8;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8220D0D8;
	sub_82130588(ctx, base);
loc_8220D0D8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c7480
	ctx.lr = 0x8220D0E4;
	sub_826C7480(ctx, base);
	// b 0x8220d0ec
	goto loc_8220D0EC;
loc_8220D0E8:
	// stwx r28,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r28.u32);
loc_8220D0EC:
	// lhz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220d100
	if (cr6.eq) goto loc_8220D100;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x8220D100;
	sub_82130588(ctx, base);
loc_8220D100:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8220D10C"))) PPC_WEAK_FUNC(sub_8220D10C);
PPC_FUNC_IMPL(__imp__sub_8220D10C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D110"))) PPC_WEAK_FUNC(sub_8220D110);
PPC_FUNC_IMPL(__imp__sub_8220D110) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8220D118;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r4,109
	ctx.r4.s64 = 109;
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8220D13C;
	sub_82641CB0(ctx, base);
	// addi r31,r3,2832
	r31.s64 = ctx.r3.s64 + 2832;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701bd8
	ctx.lr = 0x8220D148;
	sub_82701BD8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r26,1
	r26.s64 = 1;
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// mr r27,r26
	r27.u64 = r26.u64;
	// bne cr6,0x8220d16c
	if (!cr6.eq) goto loc_8220D16C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x82700840
	ctx.lr = 0x8220D168;
	sub_82700840(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8220D16C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220D190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// lwz r3,-10236(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// bl 0x821f7c90
	ctx.lr = 0x8220D1A8;
	sub_821F7C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// li r24,0
	r24.s64 = 0;
	// lwz r11,-12012(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220d1dc
	if (cr6.eq) goto loc_8220D1DC;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// bne cr6,0x8220d1e0
	if (!cr6.eq) goto loc_8220D1E0;
loc_8220D1DC:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8220D1E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// lbz r11,788(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 788);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// bl 0x823bbf80
	ctx.lr = 0x8220D1FC;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bge cr6,0x8220d558
	if (!cr6.lt) goto loc_8220D558;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220d558
	if (cr6.eq) goto loc_8220D558;
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,4994
	ctx.r10.u64 = r11.u64 | 4994;
	// lbzx r9,r29,r10
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// addis r28,r29,1
	r28.s64 = r29.s64 + 65536;
	// addi r28,r28,6108
	r28.s64 = r28.s64 + 6108;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8220d358
	if (!cr6.eq) goto loc_8220D358;
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r30,r30,6100
	r30.s64 = r30.s64 + 6100;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220d358
	if (cr6.eq) goto loc_8220D358;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r24,789(r31)
	PPC_STORE_U8(r31.u32 + 789, r24.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,624(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 624);
	// lwz r5,8(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8220D28C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,616(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 616);
	// addi r5,r11,154
	ctx.r5.s64 = r11.s64 + 154;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220D2B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,616(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 616);
	// addi r5,r11,282
	ctx.r5.s64 = r11.s64 + 282;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8220D2D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,340(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// addi r4,r11,410
	ctx.r4.s64 = r11.s64 + 410;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220D2F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,616(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 616);
	// addi r5,r11,538
	ctx.r5.s64 = r11.s64 + 538;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8220D318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8220D330;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r26,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r26.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r3,r4,6116
	ctx.r3.u64 = ctx.r4.u64 | 6116;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfsx f0,r29,r3
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + ctx.r3.u32, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8220D358:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8220d558
	if (cr6.eq) goto loc_8220D558;
	// lbz r11,790(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 790);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220d44c
	if (cr6.eq) goto loc_8220D44C;
	// lfs f13,796(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 796);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r26
	r11.u64 = r26.u64;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8220d388
	if (cr6.lt) goto loc_8220D388;
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8220D388:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220d44c
	if (cr6.eq) goto loc_8220D44C;
	// addi r3,r9,666
	ctx.r3.s64 = ctx.r9.s64 + 666;
	// bl 0x826c2868
	ctx.lr = 0x8220D39C;
	sub_826C2868(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220d3d4
	if (cr6.eq) goto loc_8220D3D4;
	// li r11,2
	r11.s64 = 2;
	// stw r11,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r11.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r3,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r3.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r5,r11,762
	ctx.r5.s64 = r11.s64 + 762;
	// addi r4,r11,730
	ctx.r4.s64 = r11.s64 + 730;
	// bl 0x826c2700
	ctx.lr = 0x8220D3C4;
	sub_826C2700(ctx, base);
	// stb r24,790(r31)
	PPC_STORE_U8(r31.u32 + 790, r24.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8220D3D4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-12008
	ctx.r10.s64 = r11.s64 + -12008;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d434
	if (!cr6.eq) goto loc_8220D434;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbz r10,666(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 666);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220d434
	if (cr6.eq) goto loc_8220D434;
	// li r11,2
	r11.s64 = 2;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r11.u32);
	// addi r3,r10,-11824
	ctx.r3.s64 = ctx.r10.s64 + -11824;
	// bl 0x826c2868
	ctx.lr = 0x8220D40C;
	sub_826C2868(ctx, base);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r3,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r3.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r5,r11,762
	ctx.r5.s64 = r11.s64 + 762;
	// addi r4,r11,730
	ctx.r4.s64 = r11.s64 + 730;
	// bl 0x826c2700
	ctx.lr = 0x8220D424;
	sub_826C2700(ctx, base);
	// stb r24,790(r31)
	PPC_STORE_U8(r31.u32 + 790, r24.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8220D434:
	// li r11,2
	r11.s64 = 2;
	// stb r24,790(r31)
	PPC_STORE_U8(r31.u32 + 790, r24.u8);
	// stw r11,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8220D44C:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220d558
	if (cr6.eq) goto loc_8220D558;
	// lbz r11,790(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 790);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// lbz r11,25(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 25);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r8,r10,6124
	ctx.r8.u64 = ctx.r10.u64 | 6124;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d4c4
	if (!cr6.eq) goto loc_8220D4C4;
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220d4a4
	if (cr6.eq) goto loc_8220D4A4;
	// lwz r10,-12012(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + -12012);
	// lwz r10,2260(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2260);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8220d4c4
	if (cr6.eq) goto loc_8220D4C4;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8220d4c0
	if (!cr6.eq) goto loc_8220D4C0;
	// stbx r26,r29,r8
	PPC_STORE_U8(r29.u32 + ctx.r8.u32, r26.u8);
	// b 0x8220d4c0
	goto loc_8220D4C0;
loc_8220D4A4:
	// addis r11,r29,1
	r11.s64 = r29.s64 + 65536;
	// addi r11,r11,6116
	r11.s64 = r11.s64 + 6116;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x8220d4c4
	if (!cr6.lt) goto loc_8220D4C4;
loc_8220D4C0:
	// stb r26,25(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25, r26.u8);
loc_8220D4C4:
	// lbzx r11,r29,r8
	r11.u64 = PPC_LOAD_U8(r29.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220d558
	if (!cr6.eq) goto loc_8220D558;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbz r10,25(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 25);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220d558
	if (cr6.eq) goto loc_8220D558;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8220ce70
	ctx.lr = 0x8220D4EC;
	sub_8220CE70(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220D504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r24,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r24.u32);
	// stb r26,788(r31)
	PPC_STORE_U8(r31.u32 + 788, r26.u8);
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220d558
	if (cr6.eq) goto loc_8220D558;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-11844
	ctx.r3.s64 = r11.s64 + -11844;
	// bl 0x821fa230
	ctx.lr = 0x8220D524;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220D534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8220d558
	if (cr6.eq) goto loc_8220D558;
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r9,r11,6120
	ctx.r9.u64 = r11.u64 | 6120;
	// addi r3,r10,-11860
	ctx.r3.s64 = ctx.r10.s64 + -11860;
	// lfsx f1,r29,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821f7e38
	ctx.lr = 0x8220D558;
	sub_821F7E38(ctx, base);
loc_8220D558:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8220D564"))) PPC_WEAK_FUNC(sub_8220D564);
PPC_FUNC_IMPL(__imp__sub_8220D564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D568"))) PPC_WEAK_FUNC(sub_8220D568);
PPC_FUNC_IMPL(__imp__sub_8220D568) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82204918
	ctx.lr = 0x8220D5A0;
	sub_82204918(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220D5B0"))) PPC_WEAK_FUNC(sub_8220D5B0);
PPC_FUNC_IMPL(__imp__sub_8220D5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r4,r11,4897
	ctx.r4.s64 = r11.s64 + 4897;
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
	// rlwinm r8,r4,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
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
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// lwz r11,-10028(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// lvx128 v63,r8,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220D628"))) PPC_WEAK_FUNC(sub_8220D628);
PPC_FUNC_IMPL(__imp__sub_8220D628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r4,r11,4947
	ctx.r4.s64 = r11.s64 + 4947;
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
	// rlwinm r8,r4,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
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
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// lwz r11,-10028(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// lvx128 v63,r8,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220D6A0"))) PPC_WEAK_FUNC(sub_8220D6A0);
PPC_FUNC_IMPL(__imp__sub_8220D6A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// addi r7,r10,20388
	ctx.r7.s64 = ctx.r10.s64 + 20388;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r5,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220D6C8"))) PPC_WEAK_FUNC(sub_8220D6C8);
PPC_FUNC_IMPL(__imp__sub_8220D6C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220D6E4"))) PPC_WEAK_FUNC(sub_8220D6E4);
PPC_FUNC_IMPL(__imp__sub_8220D6E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D6E8"))) PPC_WEAK_FUNC(sub_8220D6E8);
PPC_FUNC_IMPL(__imp__sub_8220D6E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,344(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 344);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220D704"))) PPC_WEAK_FUNC(sub_8220D704);
PPC_FUNC_IMPL(__imp__sub_8220D704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D708"))) PPC_WEAK_FUNC(sub_8220D708);
PPC_FUNC_IMPL(__imp__sub_8220D708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r4,12(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// bne cr6,0x8220d740
	if (!cr6.eq) goto loc_8220D740;
	// lwz r11,848(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 848);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8220D740:
	// lwz r10,848(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 848);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r10,188(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 188);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,-4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220D76C"))) PPC_WEAK_FUNC(sub_8220D76C);
PPC_FUNC_IMPL(__imp__sub_8220D76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D770"))) PPC_WEAK_FUNC(sub_8220D770);
PPC_FUNC_IMPL(__imp__sub_8220D770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,788(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220D78C"))) PPC_WEAK_FUNC(sub_8220D78C);
PPC_FUNC_IMPL(__imp__sub_8220D78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D790"))) PPC_WEAK_FUNC(sub_8220D790);
PPC_FUNC_IMPL(__imp__sub_8220D790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,792(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 792);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220D7AC"))) PPC_WEAK_FUNC(sub_8220D7AC);
PPC_FUNC_IMPL(__imp__sub_8220D7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D7B0"))) PPC_WEAK_FUNC(sub_8220D7B0);
PPC_FUNC_IMPL(__imp__sub_8220D7B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x82208058
	sub_82208058(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220D7C0"))) PPC_WEAK_FUNC(sub_8220D7C0);
PPC_FUNC_IMPL(__imp__sub_8220D7C0) {
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
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r3,-32123
	ctx.r3.s64 = -2105212928;
	// addi r31,r3,23088
	r31.s64 = ctx.r3.s64 + 23088;
	// lwz r10,16(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rldicr r10,r7,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// ld r8,23088(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 23088);
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// lwz r7,12(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// ld r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// addi r3,r3,-19168
	ctx.r3.s64 = ctx.r3.s64 + -19168;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// bl 0x82634ec8
	ctx.lr = 0x8220D82C;
	sub_82634EC8(ctx, base);
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

__attribute__((alias("__imp__sub_8220D844"))) PPC_WEAK_FUNC(sub_8220D844);
PPC_FUNC_IMPL(__imp__sub_8220D844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D848"))) PPC_WEAK_FUNC(sub_8220D848);
PPC_FUNC_IMPL(__imp__sub_8220D848) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,3
	ctx.r3.s64 = ctx.r10.s64 + 196608;
	// addi r3,r3,-19168
	ctx.r3.s64 = ctx.r3.s64 + -19168;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8220D880;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8220D8A0"))) PPC_WEAK_FUNC(sub_8220D8A0);
PPC_FUNC_IMPL(__imp__sub_8220D8A0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,3
	ctx.r3.s64 = ctx.r10.s64 + 196608;
	// addi r3,r3,-19168
	ctx.r3.s64 = ctx.r3.s64 + -19168;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,656(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 656);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8220D8D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8220D8F4"))) PPC_WEAK_FUNC(sub_8220D8F4);
PPC_FUNC_IMPL(__imp__sub_8220D8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D8F8"))) PPC_WEAK_FUNC(sub_8220D8F8);
PPC_FUNC_IMPL(__imp__sub_8220D8F8) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821fa230
	ctx.lr = 0x8220D914;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,108(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220D928;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8220D940;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8220D958;
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

__attribute__((alias("__imp__sub_8220D96C"))) PPC_WEAK_FUNC(sub_8220D96C);
PPC_FUNC_IMPL(__imp__sub_8220D96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D970"))) PPC_WEAK_FUNC(sub_8220D970);
PPC_FUNC_IMPL(__imp__sub_8220D970) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821fa230
	ctx.lr = 0x8220D98C;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,112(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8220D9A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8220D9B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8220D9D0;
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

__attribute__((alias("__imp__sub_8220D9E4"))) PPC_WEAK_FUNC(sub_8220D9E4);
PPC_FUNC_IMPL(__imp__sub_8220D9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220D9E8"))) PPC_WEAK_FUNC(sub_8220D9E8);
PPC_FUNC_IMPL(__imp__sub_8220D9E8) {
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
	ctx.lr = 0x8220D9F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r31,r9,4672
	r31.u64 = ctx.r9.u64 | 4672;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// lwz r29,0(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82219fe8
	ctx.lr = 0x8220DA14;
	sub_82219FE8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82218d38
	ctx.lr = 0x8220DA1C;
	sub_82218D38(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x8221a440
	ctx.lr = 0x8220DA28;
	sub_8221A440(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8220DA30"))) PPC_WEAK_FUNC(sub_8220DA30);
PPC_FUNC_IMPL(__imp__sub_8220DA30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32224
	r11.s64 = -2111832064;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,22160
	ctx.r3.s64 = r11.s64 + 22160;
	// b 0x8220bdf0
	sub_8220BDF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DA40"))) PPC_WEAK_FUNC(sub_8220DA40);
PPC_FUNC_IMPL(__imp__sub_8220DA40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32224
	r11.s64 = -2111832064;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,13672
	ctx.r3.s64 = r11.s64 + 13672;
	// b 0x8220bf08
	sub_8220BF08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DA50"))) PPC_WEAK_FUNC(sub_8220DA50);
PPC_FUNC_IMPL(__imp__sub_8220DA50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addis r3,r11,5
	ctx.r3.s64 = r11.s64 + 327680;
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// b 0x8221a270
	sub_8221A270(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DA6C"))) PPC_WEAK_FUNC(sub_8220DA6C);
PPC_FUNC_IMPL(__imp__sub_8220DA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220DA70"))) PPC_WEAK_FUNC(sub_8220DA70);
PPC_FUNC_IMPL(__imp__sub_8220DA70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32224
	r11.s64 = -2111832064;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,22776
	ctx.r3.s64 = r11.s64 + 22776;
	// b 0x8220c018
	sub_8220C018(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DA80"))) PPC_WEAK_FUNC(sub_8220DA80);
PPC_FUNC_IMPL(__imp__sub_8220DA80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,616(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 616);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8220DAA0"))) PPC_WEAK_FUNC(sub_8220DAA0);
PPC_FUNC_IMPL(__imp__sub_8220DAA0) {
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
	// b 0x822048c0
	sub_822048C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DAB4"))) PPC_WEAK_FUNC(sub_8220DAB4);
PPC_FUNC_IMPL(__imp__sub_8220DAB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220DAB8"))) PPC_WEAK_FUNC(sub_8220DAB8);
PPC_FUNC_IMPL(__imp__sub_8220DAB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,-10028(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// b 0x8220ce70
	sub_8220CE70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DAE4"))) PPC_WEAK_FUNC(sub_8220DAE4);
PPC_FUNC_IMPL(__imp__sub_8220DAE4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220DAE8"))) PPC_WEAK_FUNC(sub_8220DAE8);
PPC_FUNC_IMPL(__imp__sub_8220DAE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32224
	r11.s64 = -2111832064;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,18016
	ctx.r3.s64 = r11.s64 + 18016;
	// b 0x8220bf08
	sub_8220BF08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DAF8"))) PPC_WEAK_FUNC(sub_8220DAF8);
PPC_FUNC_IMPL(__imp__sub_8220DAF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u32);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
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
	// lwz r5,8(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// lfs f1,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// b 0x822047b8
	sub_822047B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DB5C"))) PPC_WEAK_FUNC(sub_8220DB5C);
PPC_FUNC_IMPL(__imp__sub_8220DB5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220DB60"))) PPC_WEAK_FUNC(sub_8220DB60);
PPC_FUNC_IMPL(__imp__sub_8220DB60) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-11804
	ctx.r10.s64 = r11.s64 + -11804;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220dba4
	if (cr6.eq) goto loc_8220DBA4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x8220DB9C;
	sub_82270908(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_8220DBA4:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220dbbc
	if (cr6.eq) goto loc_8220DBBC;
	// bl 0x82130588
	ctx.lr = 0x8220DBB8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8220DBBC:
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

__attribute__((alias("__imp__sub_8220DBD4"))) PPC_WEAK_FUNC(sub_8220DBD4);
PPC_FUNC_IMPL(__imp__sub_8220DBD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220DBD8"))) PPC_WEAK_FUNC(sub_8220DBD8);
PPC_FUNC_IMPL(__imp__sub_8220DBD8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8220DBE0;
	// addi r31,r1,-368
	r31.s64 = ctx.r1.s64 + -368;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// bl 0x82203388
	ctx.lr = 0x8220DC10;
	sub_82203388(ctx, base);
	// lbz r11,2485(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2485);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220dc3c
	if (!cr6.eq) goto loc_8220DC3C;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82576128
	ctx.lr = 0x8220DC28;
	sub_82576128(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// stw r24,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r24.u32);
	// stw r28,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r28.u32);
	// stw r23,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r23.u32);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
loc_8220DC3C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825788a8
	ctx.lr = 0x8220DC44;
	sub_825788A8(ctx, base);
	// mr r25,r27
	r25.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8220dc58
	if (!cr6.eq) goto loc_8220DC58;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r25,-23452(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + -23452);
loc_8220DC58:
	// lwz r11,324(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 324);
	// li r22,0
	r22.s64 = 0;
	// mr r21,r22
	r21.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220dca4
	if (!cr6.eq) goto loc_8220DCA4;
	// li r12,-8192
	r12.s64 = -8192;
	// bl 0x823dbff4
	ctx.lr = 0x8220DC74;
	sub_823DBFF4(ctx, base);
	// lwz r11,0(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// stwux r11,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r1.u32 = ea;
	// li r12,-8192
	r12.s64 = -8192;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x8220DC88;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r8,4096
	ctx.r8.s64 = 4096;
	// stw r10,324(r30)
	PPC_STORE_U32(r30.u32 + 324, ctx.r10.u32);
	// li r21,1
	r21.s64 = 1;
	// sth r8,328(r30)
	PPC_STORE_U16(r30.u32 + 328, ctx.r8.u16);
	// stb r22,458(r30)
	PPC_STORE_U8(r30.u32 + 458, r22.u8);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
loc_8220DCA4:
	// lbz r11,2485(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2485);
	// mr r27,r22
	r27.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220dccc
	if (!cr6.eq) goto loc_8220DCCC;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82572cc8
	ctx.lr = 0x8220DCC0;
	sub_82572CC8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r29,1968(r30)
	PPC_STORE_U32(r30.u32 + 1968, r29.u32);
	// b 0x8220dcd0
	goto loc_8220DCD0;
loc_8220DCCC:
	// lwz r29,1968(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 1968);
loc_8220DCD0:
	// addi r11,r30,1968
	r11.s64 = r30.s64 + 1968;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8220ddd4
	if (cr6.eq) goto loc_8220DDD4;
	// mr r26,r11
	r26.u64 = r11.u64;
loc_8220DCE0:
	// cmplw cr6,r29,r20
	cr6.compare<uint32_t>(r29.u32, r20.u32, xer);
	// beq cr6,0x8220dd74
	if (cr6.eq) goto loc_8220DD74;
	// lwz r3,2488(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2488);
	// lwz r11,2492(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2492);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220dd08
	if (cr6.eq) goto loc_8220DD08;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8220DD04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8220dd14
	goto loc_8220DD14;
loc_8220DD08:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8220DD14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8220DD14:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220dd74
	if (cr6.eq) goto loc_8220DD74;
	// addi r28,r29,16
	r28.s64 = r29.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x825761f8
	ctx.lr = 0x8220DD30;
	sub_825761F8(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x8220c160
	ctx.lr = 0x8220DD4C;
	sub_8220C160(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220dd74
	if (cr6.eq) goto loc_8220DD74;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8220DD68;
	sub_8257DC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220ddd4
	if (!cr6.eq) goto loc_8220DDD4;
loc_8220DD74:
	// lbz r11,2485(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2485);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220ddb8
	if (!cr6.eq) goto loc_8220DDB8;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x825712e8
	ctx.lr = 0x8220DD8C;
	sub_825712E8(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpwi cr6,r27,127
	cr6.compare<int32_t>(r27.s32, 127, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// blt cr6,0x8220dda8
	if (cr6.lt) goto loc_8220DDA8;
	// li r11,127
	r11.s64 = 127;
loc_8220DDA8:
	// addi r11,r11,492
	r11.s64 = r11.s64 + 492;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, r29.u32);
	// b 0x8220ddcc
	goto loc_8220DDCC;
loc_8220DDB8:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpwi cr6,r27,128
	cr6.compare<int32_t>(r27.s32, 128, xer);
	// bge cr6,0x8220ddd4
	if (!cr6.lt) goto loc_8220DDD4;
	// lwz r29,0(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 0);
loc_8220DDCC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8220dce0
	if (!cr6.eq) goto loc_8220DCE0;
loc_8220DDD4:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220ddec
	if (cr6.eq) goto loc_8220DDEC;
	// stw r22,324(r30)
	PPC_STORE_U32(r30.u32 + 324, r22.u32);
	// sth r22,328(r30)
	PPC_STORE_U16(r30.u32 + 328, r22.u16);
	// stb r22,458(r30)
	PPC_STORE_U8(r30.u32 + 458, r22.u8);
loc_8220DDEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82475b38
	ctx.lr = 0x8220DDF4;
	sub_82475B38(ctx, base);
	// lbz r10,244(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 244);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220de10
	if (cr6.eq) goto loc_8220DE10;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23388
	ctx.r3.s64 = r11.s64 + -23388;
	// bl 0x821c8f70
	ctx.lr = 0x8220DE10;
	sub_821C8F70(ctx, base);
loc_8220DE10:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r31,368
	ctx.r1.s64 = r31.s64 + 368;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8220DE1C"))) PPC_WEAK_FUNC(sub_8220DE1C);
PPC_FUNC_IMPL(__imp__sub_8220DE1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220DE20"))) PPC_WEAK_FUNC(sub_8220DE20);
PPC_FUNC_IMPL(__imp__sub_8220DE20) {
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
	ctx.lr = 0x8220DE28;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// bl 0x8220a028
	ctx.lr = 0x8220DE44;
	sub_8220A028(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8220dee4
	if (cr6.eq) goto loc_8220DEE4;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lwz r11,340(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// lwz r8,332(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r27,324(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lbz r28,319(r1)
	r28.u64 = PPC_LOAD_U8(ctx.r1.u32 + 319);
	// lwz r29,308(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r26,300(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// lwz r25,292(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// stb r28,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r28.u8);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// bl 0x82205090
	ctx.lr = 0x8220DE9C;
	sub_82205090(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8220cfa0
	ctx.lr = 0x8220DEA8;
	sub_8220CFA0(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8220dec0
	if (cr6.eq) goto loc_8220DEC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
loc_8220DEC0:
	// lis r11,1
	r11.s64 = 65536;
	// ori r10,r11,6112
	ctx.r10.u64 = r11.u64 | 6112;
	// lwzx r9,r30,r10
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lhz r11,6(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r31,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r31.u32);
	// sth r7,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, ctx.r7.u16);
loc_8220DEE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8220DEF0"))) PPC_WEAK_FUNC(sub_8220DEF0);
PPC_FUNC_IMPL(__imp__sub_8220DEF0) {
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
	ctx.lr = 0x8220DEF8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220df6c
	if (cr6.eq) goto loc_8220DF6C;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r30,316(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// lwz r8,276(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r29,308(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r28,300(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lbz r27,295(r1)
	r27.u64 = PPC_LOAD_U8(ctx.r1.u32 + 295);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r26,284(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r29.u32);
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// stb r27,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r27.u8);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x8220de20
	ctx.lr = 0x8220DF64;
	sub_8220DE20(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
loc_8220DF6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8220DF78"))) PPC_WEAK_FUNC(sub_8220DF78);
PPC_FUNC_IMPL(__imp__sub_8220DF78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x8220cc10
	sub_8220CC10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DF88"))) PPC_WEAK_FUNC(sub_8220DF88);
PPC_FUNC_IMPL(__imp__sub_8220DF88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32223
	r11.s64 = -2111766528;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-8464
	ctx.r3.s64 = r11.s64 + -8464;
	// b 0x8220c0d0
	sub_8220C0D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8220DF98"))) PPC_WEAK_FUNC(sub_8220DF98);
PPC_FUNC_IMPL(__imp__sub_8220DF98) {
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
	ctx.lr = 0x8220DFA0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r31,r30,76
	r31.s64 = r30.s64 + 76;
	// addi r10,r11,-11796
	ctx.r10.s64 = r11.s64 + -11796;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lbz r9,92(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 92);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220dfcc
	if (cr6.eq) goto loc_8220DFCC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8220DFCC;
	sub_82130588(ctx, base);
loc_8220DFCC:
	// li r11,0
	r11.s64 = 0;
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x82608de8
	ctx.lr = 0x8220DFEC;
	sub_82608DE8(ctx, base);
	// addi r31,r30,64
	r31.s64 = r30.s64 + 64;
	// li r29,6
	r29.s64 = 6;
loc_8220DFF4:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// beq cr6,0x8220e018
	if (cr6.eq) goto loc_8220E018;
loc_8220E004:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8220E010;
	sub_82130588(ctx, base);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// bne cr6,0x8220e004
	if (!cr6.eq) goto loc_8220E004;
loc_8220E018:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stw r31,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r31.u32);
	// stw r31,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r31.u32);
	// bge 0x8220dff4
	if (!cr0.lt) goto loc_8220DFF4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8220E030"))) PPC_WEAK_FUNC(sub_8220E030);
PPC_FUNC_IMPL(__imp__sub_8220E030) {
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
	// bl 0x8220df98
	ctx.lr = 0x8220E050;
	sub_8220DF98(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220e068
	if (cr6.eq) goto loc_8220E068;
	// bl 0x82130588
	ctx.lr = 0x8220E064;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8220E068:
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

__attribute__((alias("__imp__sub_8220E080"))) PPC_WEAK_FUNC(sub_8220E080);
PPC_FUNC_IMPL(__imp__sub_8220E080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8220E088;
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f29.u64);
	// stfd f30,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824e0648
	ctx.lr = 0x8220E0AC;
	sub_824E0648(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r10,r11,-11608
	ctx.r10.s64 = r11.s64 + -11608;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82234788
	ctx.lr = 0x8220E0C4;
	sub_82234788(ctx, base);
	// addi r30,r31,128
	r30.s64 = r31.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82238ad8
	ctx.lr = 0x8220E0D0;
	sub_82238AD8(ctx, base);
	// lwz r3,44(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8220E0E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,224
	ctx.r3.s64 = r31.s64 + 224;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82237048
	ctx.lr = 0x8220E0F8;
	sub_82237048(ctx, base);
	// addis r7,r31,1
	ctx.r7.s64 = r31.s64 + 65536;
	// li r26,1
	r26.s64 = 1;
	// addi r7,r7,3408
	ctx.r7.s64 = ctx.r7.s64 + 3408;
	// li r30,0
	r30.s64 = 0;
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,3568
	ctx.r3.s64 = ctx.r3.s64 + 3568;
	// stb r26,64(r7)
	PPC_STORE_U8(ctx.r7.u32 + 64, r26.u8);
	// stb r26,65(r7)
	PPC_STORE_U8(ctx.r7.u32 + 65, r26.u8);
	// stb r30,66(r7)
	PPC_STORE_U8(ctx.r7.u32 + 66, r30.u8);
	// stb r26,144(r7)
	PPC_STORE_U8(ctx.r7.u32 + 144, r26.u8);
	// stb r26,145(r7)
	PPC_STORE_U8(ctx.r7.u32 + 145, r26.u8);
	// stb r30,146(r7)
	PPC_STORE_U8(ctx.r7.u32 + 146, r30.u8);
	// bl 0x8223d2b8
	ctx.lr = 0x8220E12C;
	sub_8223D2B8(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r7,r6,3596
	ctx.r7.u64 = ctx.r6.u64 | 3596;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lfs f29,14192(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f29.f64 = double(temp.f32);
	// ori r8,r10,3904
	ctx.r8.u64 = ctx.r10.u64 | 3904;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// lis r11,1
	r11.s64 = 65536;
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// ori r6,r5,3600
	ctx.r6.u64 = ctx.r5.u64 | 3600;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// stfsx f29,r31,r8
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, temp.u32);
	// ori r5,r4,3604
	ctx.r5.u64 = ctx.r4.u64 | 3604;
	// ori r4,r3,3605
	ctx.r4.u64 = ctx.r3.u64 | 3605;
	// ori r3,r11,3608
	ctx.r3.u64 = r11.u64 | 3608;
	// ori r7,r9,3908
	ctx.r7.u64 = ctx.r9.u64 | 3908;
	// stwx r30,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r30.u32);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stbx r26,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r26.u8);
	// addi r11,r11,3912
	r11.s64 = r11.s64 + 3912;
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// li r10,14
	ctx.r10.s64 = 14;
	// stwx r30,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r30.u32);
	// addi r9,r11,128
	ctx.r9.s64 = r11.s64 + 128;
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8220E1A0:
	// stfs f31,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,136
	ctx.r9.s64 = ctx.r9.s64 + 136;
	// bge 0x8220e1a0
	if (!cr0.lt) goto loc_8220E1A0;
	// addis r25,r31,1
	r25.s64 = r31.s64 + 65536;
	// stw r30,2048(r11)
	PPC_STORE_U32(r11.u32 + 2048, r30.u32);
	// addis r27,r31,1
	r27.s64 = r31.s64 + 65536;
	// stw r30,2044(r11)
	PPC_STORE_U32(r11.u32 + 2044, r30.u32);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r30,2040(r11)
	PPC_STORE_U32(r11.u32 + 2040, r30.u32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r8,1
	ctx.r8.s64 = 65536;
	// addi r25,r25,6092
	r25.s64 = r25.s64 + 6092;
	// addis r23,r31,1
	r23.s64 = r31.s64 + 65536;
	// addi r27,r27,6100
	r27.s64 = r27.s64 + 6100;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// ori r5,r9,6120
	ctx.r5.u64 = ctx.r9.u64 | 6120;
	// ori r6,r10,6108
	ctx.r6.u64 = ctx.r10.u64 | 6108;
	// stfs f31,0(r25)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// ori r4,r8,6124
	ctx.r4.u64 = ctx.r8.u64 | 6124;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r23,r23,6128
	r23.s64 = r23.s64 + 6128;
	// sth r30,4(r27)
	PPC_STORE_U16(r27.u32 + 4, r30.u16);
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// sth r30,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r30.u16);
	// addi r9,r3,-13280
	ctx.r9.s64 = ctx.r3.s64 + -13280;
	// lfs f0,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	f0.f64 = double(temp.f32);
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// stfsx f0,r31,r5
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, temp.u32);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// stwx r30,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r30.u32);
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// addi r29,r29,6132
	r29.s64 = r29.s64 + 6132;
	// stw r9,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r9.u32);
	// addi r11,r11,6144
	r11.s64 = r11.s64 + 6144;
	// addi r10,r10,12656
	ctx.r10.s64 = ctx.r10.s64 + 12656;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// addi r9,r9,12720
	ctx.r9.s64 = ctx.r9.s64 + 12720;
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// addi r4,r6,-13260
	ctx.r4.s64 = ctx.r6.s64 + -13260;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// addi r7,r10,32
	ctx.r7.s64 = ctx.r10.s64 + 32;
	// stw r30,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r30.u32);
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// addi r5,r9,48
	ctx.r5.s64 = ctx.r9.s64 + 48;
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stb r30,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r30.u8);
	// addi r4,r9,32
	ctx.r4.s64 = ctx.r9.s64 + 32;
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,1
	ctx.r3.s64 = 65536;
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,1
	ctx.r7.s64 = 65536;
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r9,16
	ctx.r8.s64 = ctx.r9.s64 + 16;
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r5,r3,12784
	ctx.r5.u64 = ctx.r3.u64 | 12784;
	// stvx128 v127,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r4,r7,12788
	ctx.r4.u64 = ctx.r7.u64 | 12788;
	// ori r3,r6,12792
	ctx.r3.u64 = ctx.r6.u64 | 12792;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfsx f31,r31,r5
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stfsx f31,r31,r4
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// stbx r30,r31,r3
	PPC_STORE_U8(r31.u32 + ctx.r3.u32, r30.u8);
	// lfs f0,31304(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31304);
	f0.f64 = double(temp.f32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lfs f13,-11616(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11616);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r3,r6,12796
	ctx.r3.u64 = ctx.r6.u64 | 12796;
	// li r29,30
	r29.s64 = 30;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// ori r10,r9,12800
	ctx.r10.u64 = ctx.r9.u64 | 12800;
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// stfsx f0,r31,r3
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, temp.u32);
	// ori r9,r8,12804
	ctx.r9.u64 = ctx.r8.u64 | 12804;
	// ori r8,r5,16216
	ctx.r8.u64 = ctx.r5.u64 | 16216;
	// ori r7,r4,16220
	ctx.r7.u64 = ctx.r4.u64 | 16220;
	// addi r28,r28,16224
	r28.s64 = r28.s64 + 16224;
	// stfsx f13,r31,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, temp.u32);
	// li r3,120
	ctx.r3.s64 = 120;
	// stfsx f30,r31,r9
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, temp.u32);
	// stbx r30,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r30.u8);
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// sth r29,4(r28)
	PPC_STORE_U16(r28.u32 + 4, r29.u16);
	// sth r29,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r29.u16);
	// bl 0x82130528
	ctx.lr = 0x8220E334;
	sub_82130528(ctx, base);
	// addis r22,r31,1
	r22.s64 = r31.s64 + 65536;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r3,120
	ctx.r3.s64 = 120;
	// addi r22,r22,16232
	r22.s64 = r22.s64 + 16232;
	// sth r29,4(r22)
	PPC_STORE_U16(r22.u32 + 4, r29.u16);
	// sth r29,6(r22)
	PPC_STORE_U16(r22.u32 + 6, r29.u16);
	// bl 0x82130528
	ctx.lr = 0x8220E350;
	sub_82130528(ctx, base);
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// addis r4,r31,1
	ctx.r4.s64 = r31.s64 + 65536;
	// stw r3,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r3.u32);
	// addi r6,r6,16240
	ctx.r6.s64 = ctx.r6.s64 + 16240;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r4,r4,16248
	ctx.r4.s64 = ctx.r4.s64 + 16248;
	// addi r11,r5,-12052
	r11.s64 = ctx.r5.s64 + -12052;
	// addis r24,r31,1
	r24.s64 = r31.s64 + 65536;
	// stw r28,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r28.u32);
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// addi r24,r24,16256
	r24.s64 = r24.s64 + 16256;
	// stw r22,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r22.u32);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82648e40
	ctx.lr = 0x8220E38C;
	sub_82648E40(ctx, base);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// ori r7,r10,4656
	ctx.r7.u64 = ctx.r10.u64 | 4656;
	// ori r6,r9,4660
	ctx.r6.u64 = ctx.r9.u64 | 4660;
	// ori r5,r8,4661
	ctx.r5.u64 = ctx.r8.u64 | 4661;
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// stbx r30,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r30.u8);
	// stbx r30,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r30.u8);
	// bl 0x8221bc80
	ctx.lr = 0x8220E3BC;
	sub_8221BC80(ctx, base);
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// ori r7,r4,4976
	ctx.r7.u64 = ctx.r4.u64 | 4976;
	// ori r6,r3,4980
	ctx.r6.u64 = ctx.r3.u64 | 4980;
	// ori r5,r11,4981
	ctx.r5.u64 = r11.u64 | 4981;
	// ori r4,r10,4982
	ctx.r4.u64 = ctx.r10.u64 | 4982;
	// ori r3,r9,4983
	ctx.r3.u64 = ctx.r9.u64 | 4983;
	// ori r11,r8,4984
	r11.u64 = ctx.r8.u64 | 4984;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stbx r30,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r30.u8);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stbx r30,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r30.u8);
	// lis r8,5
	ctx.r8.s64 = 327680;
	// stwx r10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r10.u32);
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// lis r7,5
	ctx.r7.s64 = 327680;
	// stbx r30,r31,r3
	PPC_STORE_U8(r31.u32 + ctx.r3.u32, r30.u8);
	// lis r6,5
	ctx.r6.s64 = 327680;
	// stbx r30,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r30.u8);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r29,5
	r29.s64 = 327680;
	// ori r9,r9,4985
	ctx.r9.u64 = ctx.r9.u64 | 4985;
	// ori r8,r8,4986
	ctx.r8.u64 = ctx.r8.u64 | 4986;
	// addis r28,r31,5
	r28.s64 = r31.s64 + 327680;
	// stbx r30,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r30.u8);
	// ori r22,r3,4991
	r22.u64 = ctx.r3.u64 | 4991;
	// stbx r30,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r30.u8);
	// ori r7,r7,4987
	ctx.r7.u64 = ctx.r7.u64 | 4987;
	// ori r6,r6,4988
	ctx.r6.u64 = ctx.r6.u64 | 4988;
	// ori r5,r5,4989
	ctx.r5.u64 = ctx.r5.u64 | 4989;
	// ori r4,r4,4990
	ctx.r4.u64 = ctx.r4.u64 | 4990;
	// ori r11,r11,4992
	r11.u64 = r11.u64 | 4992;
	// stbx r26,r31,r22
	PPC_STORE_U8(r31.u32 + r22.u32, r26.u8);
	// ori r10,r10,4993
	ctx.r10.u64 = ctx.r10.u64 | 4993;
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// ori r21,r29,5204
	r21.u64 = r29.u64 | 5204;
	// stbx r30,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r30.u8);
	// addi r28,r28,5208
	r28.s64 = r28.s64 + 5208;
	// stbx r30,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r30.u8);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// stbx r30,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r30.u8);
	// addi r29,r28,12
	r29.s64 = r28.s64 + 12;
	// addi r9,r3,-11804
	ctx.r9.s64 = ctx.r3.s64 + -11804;
	// stbx r30,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r30.u8);
	// stwx r30,r31,r21
	PPC_STORE_U32(r31.u32 + r21.u32, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r30.u32);
	// stw r30,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r30.u32);
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// bl 0x821b5a60
	ctx.lr = 0x8220E4A8;
	sub_821B5A60(ctx, base);
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x821b5a60
	ctx.lr = 0x8220E4B0;
	sub_821B5A60(ctx, base);
	// lis r8,5
	ctx.r8.s64 = 327680;
	// stw r30,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r30.u32);
	// addis r29,r31,5
	r29.s64 = r31.s64 + 327680;
	// ori r7,r8,5232
	ctx.r7.u64 = ctx.r8.u64 | 5232;
	// stw r30,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r30.u32);
	// stw r30,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r30.u32);
	// addi r29,r29,5280
	r29.s64 = r29.s64 + 5280;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// bl 0x826337a8
	ctx.lr = 0x8220E4D8;
	sub_826337A8(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stw r30,176(r29)
	PPC_STORE_U32(r29.u32 + 176, r30.u32);
	// addi r3,r29,184
	ctx.r3.s64 = r29.s64 + 184;
	// addi r5,r6,-14100
	ctx.r5.s64 = ctx.r6.s64 + -14100;
	// stw r30,180(r29)
	PPC_STORE_U32(r29.u32 + 180, r30.u32);
	// stw r5,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r5.u32);
	// bl 0x821c2f70
	ctx.lr = 0x8220E4F4;
	sub_821C2F70(ctx, base);
	// stb r26,204(r29)
	PPC_STORE_U8(r29.u32 + 204, r26.u8);
	// stw r30,208(r29)
	PPC_STORE_U32(r29.u32 + 208, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x8220E504;
	sub_82387928(ctx, base);
	// addis r11,r31,5
	r11.s64 = r31.s64 + 327680;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// addi r11,r11,5552
	r11.s64 = r11.s64 + 5552;
	// bne cr6,0x8220e520
	if (!cr6.eq) goto loc_8220E520;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// b 0x8220e528
	goto loc_8220E528;
loc_8220E520:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
loc_8220E528:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r9,32639
	ctx.r9.s64 = 2139029504;
	// ori r8,r10,49023
	ctx.r8.u64 = ctx.r10.u64 | 49023;
	// ori r6,r9,32767
	ctx.r6.u64 = ctx.r9.u64 | 32767;
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// stw r8,4600(r11)
	PPC_STORE_U32(r11.u32 + 4600, ctx.r8.u32);
	// lfs f0,-11620(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11620);
	f0.f64 = double(temp.f32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r6,4824(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4824, ctx.r6.u32);
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f0,4624(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4624, temp.u32);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f0,4848(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4848, temp.u32);
	// addi r10,r10,15816
	ctx.r10.s64 = ctx.r10.s64 + 15816;
	// lfs f0,-11624(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11624);
	f0.f64 = double(temp.f32);
	// addi r9,r9,15216
	ctx.r9.s64 = ctx.r9.s64 + 15216;
	// stfs f29,0(r25)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// addi r11,r11,12824
	r11.s64 = r11.s64 + 12824;
	// li r8,50
	ctx.r8.s64 = 50;
loc_8220E58C:
	// stfs f31,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stfs f31,-4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stfs f31,0(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f31,792(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 792, temp.u32);
	// stfs f31,796(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 796, temp.u32);
	// stfs f31,800(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 800, temp.u32);
	// stfs f31,1592(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 1592, temp.u32);
	// stfs f31,1596(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 1596, temp.u32);
	// stfs f31,1600(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 1600, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stfs f30,0(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f30,4(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// stfs f31,-200(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + -200, temp.u32);
	// stfs f30,0(r10)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f0,200(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 200, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8220e58c
	if (!cr0.eq) goto loc_8220E58C;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x8220E5E0;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8220e670
	if (cr6.eq) goto loc_8220E670;
	// li r11,796
	r11.s64 = 796;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// li r10,20
	ctx.r10.s64 = 20;
	// sth r30,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r30.u16);
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// li r3,15920
	ctx.r3.s64 = 15920;
	// stw r30,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r30.u32);
	// stb r30,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r30.u8);
	// sth r10,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r10.u16);
	// bl 0x82130528
	ctx.lr = 0x8220E614;
	sub_82130528(ctx, base);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lhz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// ori r9,r7,65535
	ctx.r9.u64 = ctx.r7.u64 | 65535;
	// stb r26,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r26.u8);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
	// sth r8,6(r29)
	PPC_STORE_U16(r29.u32 + 6, ctx.r8.u16);
	// clrlwi r8,r5,16
	ctx.r8.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8220e668
	if (cr6.eq) goto loc_8220E668;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
loc_8220E648:
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8220e648
	if (!cr6.eq) goto loc_8220E648;
loc_8220E668:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// b 0x8220e674
	goto loc_8220E674;
loc_8220E670:
	// mr r29,r30
	r29.u64 = r30.u64;
loc_8220E674:
	// lis r11,1
	r11.s64 = 65536;
	// li r26,16
	r26.s64 = 16;
	// ori r10,r11,6112
	ctx.r10.u64 = r11.u64 | 6112;
	// stwx r29,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r29.u32);
	// lhz r9,6(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 6);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8220e6a0
	if (!cr6.eq) goto loc_8220E6A0;
	// sth r26,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r26.u16);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8220E69C;
	sub_82130528(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
loc_8220E6A0:
	// sth r26,4(r27)
	PPC_STORE_U16(r27.u32 + 4, r26.u16);
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r9,r9,6104
	ctx.r9.s64 = ctx.r9.s64 + 6104;
	// lhz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220e6dc
	if (cr6.eq) goto loc_8220E6DC;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_8220E6C0:
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r30,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r30.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lhz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x8220e6c0
	if (cr6.lt) goto loc_8220E6C0;
loc_8220E6DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822085f0
	ctx.lr = 0x8220E6E4;
	sub_822085F0(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r11,-32224
	r11.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,14768
	ctx.r4.s64 = r11.s64 + 14768;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,-10232(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + -10232);
	// bl 0x821c2fb0
	ctx.lr = 0x8220E708;
	sub_821C2FB0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r9,-11648
	ctx.r4.s64 = ctx.r9.s64 + -11648;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ld r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicr r7,r8,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// bl 0x827212f8
	ctx.lr = 0x8220E72C;
	sub_827212F8(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-32040
	ctx.r4.s64 = ctx.r4.s64 + -32040;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,-10232(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + -10232);
	// bl 0x821c2fb0
	ctx.lr = 0x8220E74C;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,-11672
	ctx.r4.s64 = ctx.r10.s64 + -11672;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r7,r9,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x827212f8
	ctx.lr = 0x8220E770;
	sub_827212F8(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,-32224
	ctx.r4.s64 = ctx.r8.s64 + -32224;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,-10232(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + -10232);
	// bl 0x821c2fb0
	ctx.lr = 0x8220E790;
	sub_821C2FB0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r5,-11692
	ctx.r4.s64 = ctx.r5.s64 + -11692;
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// ld r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r6.u32 + 0);
	// rldicr r7,r11,32,63
	ctx.r7.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r6)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// bl 0x827212f8
	ctx.lr = 0x8220E7B4;
	sub_827212F8(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-32152
	ctx.r4.s64 = ctx.r10.s64 + -32152;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,-10232(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + -10232);
	// bl 0x821c2fb0
	ctx.lr = 0x8220E7D4;
	sub_821C2FB0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r8,-11712
	ctx.r4.s64 = ctx.r8.s64 + -11712;
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// rldicr r7,r7,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// bl 0x827212f8
	ctx.lr = 0x8220E7F8;
	sub_827212F8(ctx, base);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,24536
	ctx.r4.s64 = ctx.r4.s64 + 24536;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,-10232(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + -10232);
	// bl 0x821c2fb0
	ctx.lr = 0x8220E818;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// addi r4,r9,-11736
	ctx.r4.s64 = ctx.r9.s64 + -11736;
	// rldicr r7,r10,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x827212f8
	ctx.lr = 0x8220E83C;
	sub_827212F8(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,23928
	ctx.r4.s64 = ctx.r8.s64 + 23928;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,-10232(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + -10232);
	// bl 0x821c2fb0
	ctx.lr = 0x8220E85C;
	sub_821C2FB0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r5,-11756
	ctx.r4.s64 = ctx.r5.s64 + -11756;
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// ld r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r6.u32 + 0);
	// rldicr r7,r11,32,63
	ctx.r7.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r6)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// bl 0x827212f8
	ctx.lr = 0x8220E880;
	sub_827212F8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,3628
	ctx.r3.s64 = ctx.r3.s64 + 3628;
	// bl 0x823d9890
	ctx.lr = 0x8220E894;
	sub_823D9890(ctx, base);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// ori r9,r10,3760
	ctx.r9.u64 = ctx.r10.u64 | 3760;
	// stvx128 v127,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10024(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10024);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8220e8d8
	if (!cr6.eq) goto loc_8220E8D8;
	// li r3,13696
	ctx.r3.s64 = 13696;
	// bl 0x82130528
	ctx.lr = 0x8220E8B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220e8cc
	if (cr6.eq) goto loc_8220E8CC;
	// bl 0x822264d0
	ctx.lr = 0x8220E8C4;
	sub_822264D0(ctx, base);
	// stw r3,-10024(r29)
	PPC_STORE_U32(r29.u32 + -10024, ctx.r3.u32);
	// b 0x8220e8e4
	goto loc_8220E8E4;
loc_8220E8CC:
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r11,-10024(r29)
	PPC_STORE_U32(r29.u32 + -10024, r11.u32);
	// b 0x8220e8e4
	goto loc_8220E8E4;
loc_8220E8D8:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
loc_8220E8E4:
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// li r11,100
	r11.s64 = 100;
	// addi r6,r6,6256
	ctx.r6.s64 = ctx.r6.s64 + 6256;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
loc_8220E8F4:
	// stb r30,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r30.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// bne 0x8220e8f4
	if (!cr0.eq) goto loc_8220E8F4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r5,r7,-11772
	ctx.r5.s64 = ctx.r7.s64 + -11772;
	// addi r9,r10,-14596
	ctx.r9.s64 = ctx.r10.s64 + -14596;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// addi r8,r8,-14960
	ctx.r8.s64 = ctx.r8.s64 + -14960;
	// li r7,6400
	ctx.r7.s64 = 6400;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82202b98
	ctx.lr = 0x8220E930;
	sub_82202B98(ctx, base);
	// bl 0x82178848
	ctx.lr = 0x8220E934;
	sub_82178848(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8220e95c
	if (cr6.eq) goto loc_8220E95C;
	// bl 0x82178880
	ctx.lr = 0x8220E944;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220e95c
	if (cr6.eq) goto loc_8220E95C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-11780
	ctx.r4.s64 = r11.s64 + -11780;
	// b 0x8220e964
	goto loc_8220E964;
loc_8220E95C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-11792
	ctx.r4.s64 = r11.s64 + -11792;
loc_8220E964:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e06e0
	ctx.lr = 0x8220E96C;
	sub_824E06E0(ctx, base);
	// lis r29,-32119
	r29.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x8220E97C;
	sub_823058F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0558
	ctx.lr = 0x8220E984;
	sub_824E0558(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x8220E990;
	sub_82305870(ctx, base);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220E9A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r9,4994
	ctx.r6.u64 = ctx.r9.u64 | 4994;
	// ori r4,r7,4996
	ctx.r4.u64 = ctx.r7.u64 | 4996;
	// ori r5,r8,4995
	ctx.r5.u64 = ctx.r8.u64 | 4995;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32223
	r11.s64 = -2111766528;
	// stbx r30,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r30.u8);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r10,r11,-13328
	ctx.r10.s64 = r11.s64 + -13328;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// stbx r30,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r30.u8);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,21440
	ctx.r4.s64 = ctx.r9.s64 + 21440;
	// lwz r11,-12216(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12216);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r10,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r10.u32);
	// lwz r27,17268(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x821c2fb0
	ctx.lr = 0x8220EA04;
	sub_821C2FB0(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r11,5
	r11.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_8220EA10:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8220ea10
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8220EA10;
	// addi r10,r27,524
	ctx.r10.s64 = r27.s64 + 524;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8220EA34:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8220ea34
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8220EA34;
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lwz r27,17268(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21784
	ctx.r4.s64 = r11.s64 + 21784;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c2fb0
	ctx.lr = 0x8220EA68;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8220EA78:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8220ea78
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8220EA78;
	// addi r10,r27,544
	ctx.r10.s64 = r27.s64 + 544;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8220EA9C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8220ea9c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8220EA9C;
	// lwz r11,17268(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// addis r29,r31,5
	r29.s64 = r31.s64 + 327680;
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// addi r7,r9,0
	ctx.r7.s64 = ctx.r9.s64 + 0;
	// addi r29,r29,5212
	r29.s64 = r29.s64 + 5212;
	// stw r23,568(r11)
	PPC_STORE_U32(r11.u32 + 568, r23.u32);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// lwz r11,-12012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12012);
	// addi r5,r8,0
	ctx.r5.s64 = ctx.r8.s64 + 0;
	// stw r7,2184(r11)
	PPC_STORE_U32(r11.u32 + 2184, ctx.r7.u32);
	// stw r30,2192(r11)
	PPC_STORE_U32(r11.u32 + 2192, r30.u32);
	// addi r4,r6,21312
	ctx.r4.s64 = ctx.r6.s64 + 21312;
	// lwz r11,-12012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12012);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,2188(r11)
	PPC_STORE_U32(r11.u32 + 2188, ctx.r5.u32);
	// stw r30,2196(r11)
	PPC_STORE_U32(r11.u32 + 2196, r30.u32);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stw r4,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x8220EB04;
	sub_82130000(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwz r10,-9996(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -9996);
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8220eb58
	if (cr6.eq) goto loc_8220EB58;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r8,16(r28)
	PPC_STORE_U32(r28.u32 + 16, ctx.r8.u32);
	// beq cr6,0x8220eb48
	if (cr6.eq) goto loc_8220EB48;
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r28,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, r28.u32);
	// stw r28,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r28.u32);
	// stw r9,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r9.u32);
	// b 0x8220eb68
	goto loc_8220EB68;
loc_8220EB48:
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// stw r28,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r28.u32);
	// stw r9,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r9.u32);
	// b 0x8220eb68
	goto loc_8220EB68;
loc_8220EB58:
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// stw r30,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r30.u32);
	// stw r30,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r30.u32);
loc_8220EB68:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r10,20(r28)
	PPC_STORE_U32(r28.u32 + 20, ctx.r10.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8220EB98"))) PPC_WEAK_FUNC(sub_8220EB98);
PPC_FUNC_IMPL(__imp__sub_8220EB98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-11780
	ctx.r3.s64 = r11.s64 + -11780;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220EBA4"))) PPC_WEAK_FUNC(sub_8220EBA4);
PPC_FUNC_IMPL(__imp__sub_8220EBA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220EBA8"))) PPC_WEAK_FUNC(sub_8220EBA8);
PPC_FUNC_IMPL(__imp__sub_8220EBA8) {
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
	ctx.lr = 0x8220EBB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,1
	r11.s64 = 65536;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r9,r11,3600
	ctx.r9.u64 = r11.u64 | 3600;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r8,r10,-11608
	ctx.r8.s64 = ctx.r10.s64 + -11608;
	// lwzx r3,r30,r9
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220ebec
	if (cr6.eq) goto loc_8220EBEC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220EBEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8220EBEC:
	// addis r28,r30,1
	r28.s64 = r30.s64 + 65536;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r28,6112
	r28.s64 = r28.s64 + 6112;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8220ec38
	if (cr6.eq) goto loc_8220EC38;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220ec18
	if (cr6.eq) goto loc_8220EC18;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8220EC18;
	sub_82130588(ctx, base);
loc_8220EC18:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stb r29,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r29.u8);
	// bl 0x82130588
	ctx.lr = 0x8220EC34;
	sub_82130588(ctx, base);
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
loc_8220EC38:
	// addis r3,r30,5
	ctx.r3.s64 = r30.s64 + 327680;
	// addi r3,r3,5280
	ctx.r3.s64 = ctx.r3.s64 + 5280;
	// bl 0x82633b00
	ctx.lr = 0x8220EC44;
	sub_82633B00(ctx, base);
	// addis r31,r30,5
	r31.s64 = r30.s64 + 327680;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r31,r31,5208
	r31.s64 = r31.s64 + 5208;
	// addi r10,r11,-11804
	ctx.r10.s64 = r11.s64 + -11804;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220ec70
	if (cr6.eq) goto loc_8220EC70;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x8220EC6C;
	sub_82270908(ctx, base);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
loc_8220EC70:
	// addis r3,r30,5
	ctx.r3.s64 = r30.s64 + 327680;
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// bl 0x8221b710
	ctx.lr = 0x8220EC7C;
	sub_8221B710(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x826485c8
	ctx.lr = 0x8220EC88;
	sub_826485C8(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r3,16248
	ctx.r3.s64 = ctx.r3.s64 + 16248;
	// addi r31,r11,-12632
	r31.s64 = r11.s64 + -12632;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// bl 0x821d2028
	ctx.lr = 0x8220ECA0;
	sub_821D2028(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r3,r3,16240
	ctx.r3.s64 = ctx.r3.s64 + 16240;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// bl 0x821d2028
	ctx.lr = 0x8220ECB0;
	sub_821D2028(ctx, base);
	// addis r11,r30,1
	r11.s64 = r30.s64 + 65536;
	// addi r11,r11,16232
	r11.s64 = r11.s64 + 16232;
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220eccc
	if (cr6.eq) goto loc_8220ECCC;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8220ECCC;
	sub_82130588(ctx, base);
loc_8220ECCC:
	// addis r11,r30,1
	r11.s64 = r30.s64 + 65536;
	// addi r11,r11,16224
	r11.s64 = r11.s64 + 16224;
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8220ece8
	if (cr6.eq) goto loc_8220ECE8;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8220ECE8;
	sub_82130588(ctx, base);
loc_8220ECE8:
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r11,6144
	ctx.r9.u64 = r11.u64 | 6144;
	// addis r11,r30,1
	r11.s64 = r30.s64 + 65536;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// ori r7,r10,6128
	ctx.r7.u64 = ctx.r10.u64 | 6128;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r11,r11,6100
	r11.s64 = r11.s64 + 6100;
	// addi r5,r8,-13304
	ctx.r5.s64 = ctx.r8.s64 + -13304;
	// addi r4,r6,-14156
	ctx.r4.s64 = ctx.r6.s64 + -14156;
	// stwx r5,r30,r9
	PPC_STORE_U32(r30.u32 + ctx.r9.u32, ctx.r5.u32);
	// stwx r4,r30,r7
	PPC_STORE_U32(r30.u32 + ctx.r7.u32, ctx.r4.u32);
	// lhz r3,6(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220ed2c
	if (cr6.eq) goto loc_8220ED2C;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8220ED2C;
	sub_82130588(ctx, base);
loc_8220ED2C:
	// addi r3,r30,224
	ctx.r3.s64 = r30.s64 + 224;
	// bl 0x822364d8
	ctx.lr = 0x8220ED34;
	sub_822364D8(ctx, base);
	// addi r3,r30,128
	ctx.r3.s64 = r30.s64 + 128;
	// bl 0x8220df98
	ctx.lr = 0x8220ED3C;
	sub_8220DF98(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x822349a8
	ctx.lr = 0x8220ED44;
	sub_822349A8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e0430
	ctx.lr = 0x8220ED4C;
	sub_824E0430(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8220ED54"))) PPC_WEAK_FUNC(sub_8220ED54);
PPC_FUNC_IMPL(__imp__sub_8220ED54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220ED58"))) PPC_WEAK_FUNC(sub_8220ED58);
PPC_FUNC_IMPL(__imp__sub_8220ED58) {
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
	// lis r3,5
	ctx.r3.s64 = 327680;
	// ori r3,r3,5568
	ctx.r3.u64 = ctx.r3.u64 | 5568;
	// bl 0x82130528
	ctx.lr = 0x8220ED78;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220ed8c
	if (cr6.eq) goto loc_8220ED8C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8220e080
	ctx.lr = 0x8220ED88;
	sub_8220E080(ctx, base);
	// b 0x8220ed90
	goto loc_8220ED90;
loc_8220ED8C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8220ED90:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-10028(r11)
	PPC_STORE_U32(r11.u32 + -10028, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8220EDAC"))) PPC_WEAK_FUNC(sub_8220EDAC);
PPC_FUNC_IMPL(__imp__sub_8220EDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220EDB0"))) PPC_WEAK_FUNC(sub_8220EDB0);
PPC_FUNC_IMPL(__imp__sub_8220EDB0) {
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
	ctx.lr = 0x8220EDB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,224
	r29.s64 = r31.s64 + 224;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// addi r3,r29,628
	ctx.r3.s64 = r29.s64 + 628;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r30.u32);
	// sth r30,328(r31)
	PPC_STORE_U16(r31.u32 + 328, r30.u16);
	// stw r30,980(r31)
	PPC_STORE_U32(r31.u32 + 980, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x8220EE04;
	sub_823D9890(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,106
	ctx.r3.s64 = r29.s64 + 106;
	// bl 0x823d9890
	ctx.lr = 0x8220EE14;
	sub_823D9890(ctx, base);
	// stb r30,458(r31)
	PPC_STORE_U8(r31.u32 + 458, r30.u8);
	// addi r3,r31,1712
	ctx.r3.s64 = r31.s64 + 1712;
	// stw r30,2488(r31)
	PPC_STORE_U32(r31.u32 + 2488, r30.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r30,2492(r31)
	PPC_STORE_U32(r31.u32 + 2492, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,2496(r31)
	PPC_STORE_U32(r31.u32 + 2496, r30.u32);
	// addi r11,r31,2488
	r11.s64 = r31.s64 + 2488;
	// stw r30,2500(r31)
	PPC_STORE_U32(r31.u32 + 2500, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x8220EE3C;
	sub_823D9890(ctx, base);
	// addi r3,r31,1968
	ctx.r3.s64 = r31.s64 + 1968;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8220EE4C;
	sub_823D9890(ctx, base);
	// stw r30,2480(r31)
	PPC_STORE_U32(r31.u32 + 2480, r30.u32);
	// stb r30,2484(r31)
	PPC_STORE_U8(r31.u32 + 2484, r30.u8);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// stb r30,2485(r31)
	PPC_STORE_U8(r31.u32 + 2485, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,2504(r31)
	PPC_STORE_U8(r31.u32 + 2504, r30.u8);
	// addi r10,r11,19360
	ctx.r10.s64 = r11.s64 + 19360;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8220EE70;
	sub_82130000(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,2508(r31)
	PPC_STORE_U32(r31.u32 + 2508, r30.u32);
	// stw r11,2512(r31)
	PPC_STORE_U32(r31.u32 + 2512, r11.u32);
	// stw r11,2516(r31)
	PPC_STORE_U32(r31.u32 + 2516, r11.u32);
	// stb r9,2520(r31)
	PPC_STORE_U8(r31.u32 + 2520, ctx.r9.u8);
	// stw r30,2524(r31)
	PPC_STORE_U32(r31.u32 + 2524, r30.u32);
	// stw r30,2528(r31)
	PPC_STORE_U32(r31.u32 + 2528, r30.u32);
	// std r8,2488(r31)
	PPC_STORE_U64(r31.u32 + 2488, ctx.r8.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8220EEA8"))) PPC_WEAK_FUNC(sub_8220EEA8);
PPC_FUNC_IMPL(__imp__sub_8220EEA8) {
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-21500
	ctx.r10.s64 = r11.s64 + -21500;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x8220EED4;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821fd7c0
	ctx.lr = 0x8220EEE8;
	sub_821FD7C0(ctx, base);
	// lwz r3,228(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8220EF00"))) PPC_WEAK_FUNC(sub_8220EF00);
PPC_FUNC_IMPL(__imp__sub_8220EF00) {
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
	ctx.lr = 0x8220EF08;
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x823db670
	ctx.lr = 0x8220EF30;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821fd7c0
	ctx.lr = 0x8220EF44;
	sub_821FD7C0(ctx, base);
	// lwz r11,10248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// lwz r3,468(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// li r26,0
	r26.s64 = 0;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// stw r29,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r26,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, r26.u8);
	// stw r26,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r26.u32);
	// stw r11,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, r11.u32);
	// bne cr6,0x8220efe4
	if (!cr6.eq) goto loc_8220EFE4;
	// lwz r11,10244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10244);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,10244(r31)
	PPC_STORE_U32(r31.u32 + 10244, ctx.r9.u32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r28,r11,r31
	r28.u64 = r11.u64 + r31.u64;
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
	// addi r3,r30,92
	ctx.r3.s64 = r30.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x8220EF9C;
	sub_823DB670(ctx, base);
	// stw r26,160(r28)
	PPC_STORE_U32(r28.u32 + 160, r26.u32);
	// stw r29,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,324
	ctx.r3.s64 = ctx.r1.s64 + 324;
	// bl 0x823db670
	ctx.lr = 0x8220EFB4;
	sub_823DB670(ctx, base);
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// addi r4,r1,324
	ctx.r4.s64 = ctx.r1.s64 + 324;
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x8220EFC8;
	sub_823DA950(ctx, base);
	// stw r30,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r30.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821fcf28
	ctx.lr = 0x8220EFE0;
	sub_821FCF28(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8220EFE4:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8220EFEC"))) PPC_WEAK_FUNC(sub_8220EFEC);
PPC_FUNC_IMPL(__imp__sub_8220EFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8220EFF0"))) PPC_WEAK_FUNC(sub_8220EFF0);
PPC_FUNC_IMPL(__imp__sub_8220EFF0) {
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
	// bl 0x8220eba8
	ctx.lr = 0x8220F010;
	sub_8220EBA8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220f028
	if (cr6.eq) goto loc_8220F028;
	// bl 0x82130588
	ctx.lr = 0x8220F024;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8220F028:
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

__attribute__((alias("__imp__sub_8220F040"))) PPC_WEAK_FUNC(sub_8220F040);
PPC_FUNC_IMPL(__imp__sub_8220F040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x8220F048;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r19,-32119
	r19.s64 = -2104950784;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17944(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x8220F064;
	sub_82305870(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stb r25,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r25.u8);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// stb r25,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r25.u8);
	// addi r29,r11,-10256
	r29.s64 = r11.s64 + -10256;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8220F088;
	sub_821F9FB8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r28,1
	r28.s64 = 1;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmpwi cr6,r27,36
	cr6.compare<int32_t>(r27.s32, 36, xer);
	// addi r22,r11,-10268
	r22.s64 = r11.s64 + -10268;
	// addi r24,r10,-21664
	r24.s64 = ctx.r10.s64 + -21664;
	// addi r20,r9,-10284
	r20.s64 = ctx.r9.s64 + -10284;
	// beq cr6,0x8220f158
	if (cr6.eq) goto loc_8220F158;
	// cmpwi cr6,r27,40
	cr6.compare<int32_t>(r27.s32, 40, xer);
	// beq cr6,0x8220f158
	if (cr6.eq) goto loc_8220F158;
	// cmpwi cr6,r27,38
	cr6.compare<int32_t>(r27.s32, 38, xer);
	// beq cr6,0x8220f158
	if (cr6.eq) goto loc_8220F158;
	// cmpwi cr6,r27,14
	cr6.compare<int32_t>(r27.s32, 14, xer);
	// beq cr6,0x8220f158
	if (cr6.eq) goto loc_8220F158;
	// cmpwi cr6,r27,15
	cr6.compare<int32_t>(r27.s32, 15, xer);
	// beq cr6,0x8220f158
	if (cr6.eq) goto loc_8220F158;
	// cmpwi cr6,r27,200
	cr6.compare<int32_t>(r27.s32, 200, xer);
	// blt cr6,0x8220f0e4
	if (cr6.lt) goto loc_8220F0E4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-21652
	ctx.r4.s64 = r11.s64 + -21652;
	// b 0x8220f160
	goto loc_8220F160;
loc_8220F0E4:
	// cmpwi cr6,r27,150
	cr6.compare<int32_t>(r27.s32, 150, xer);
	// beq cr6,0x8220f130
	if (cr6.eq) goto loc_8220F130;
	// cmpwi cr6,r27,151
	cr6.compare<int32_t>(r27.s32, 151, xer);
	// beq cr6,0x8220f130
	if (cr6.eq) goto loc_8220F130;
	// cmpwi cr6,r27,152
	cr6.compare<int32_t>(r27.s32, 152, xer);
	// beq cr6,0x8220f130
	if (cr6.eq) goto loc_8220F130;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8220F108;
	sub_821F9FB8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,56(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// bl 0x825ee270
	ctx.lr = 0x8220F11C;
	sub_825EE270(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// lwz r3,56(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// addi r5,r1,81
	ctx.r5.s64 = ctx.r1.s64 + 81;
	// bl 0x825ee270
	ctx.lr = 0x8220F12C;
	sub_825EE270(ctx, base);
	// b 0x8220f16c
	goto loc_8220F16C;
loc_8220F130:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8220F13C;
	sub_821F9FB8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,56(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// bl 0x825ee270
	ctx.lr = 0x8220F150;
	sub_825EE270(ctx, base);
	// stb r28,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r28.u8);
	// b 0x8220f16c
	goto loc_8220F16C;
loc_8220F158:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-12248
	ctx.r4.s64 = r11.s64 + -12248;
loc_8220F160:
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8220F168;
	sub_821F9FB8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
loc_8220F16C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82210d20
	if (cr6.eq) goto loc_82210D20;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r18,56(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r26,r11,-10292
	r26.s64 = r11.s64 + -10292;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9790
	ctx.lr = 0x8220F18C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x8220F19C;
	sub_825ED480(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// addi r9,r11,-12116
	ctx.r9.s64 = r11.s64 + -12116;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// bl 0x821c9790
	ctx.lr = 0x8220F1C4;
	sub_821C9790(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x8220F1D4;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8220F1EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// beq cr6,0x8220f5c4
	if (cr6.eq) goto loc_8220F5C4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x8220F200;
	sub_82720E28(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// addi r4,r11,-10300
	ctx.r4.s64 = r11.s64 + -10300;
	// bl 0x825ee0e0
	ctx.lr = 0x8220F214;
	sub_825EE0E0(ctx, base);
	// cmpwi cr6,r27,100
	cr6.compare<int32_t>(r27.s32, 100, xer);
	// blt cr6,0x8220f274
	if (cr6.lt) goto loc_8220F274;
	// cmpwi cr6,r27,200
	cr6.compare<int32_t>(r27.s32, 200, xer);
	// bge cr6,0x8220f274
	if (!cr6.lt) goto loc_8220F274;
	// cmpwi cr6,r27,150
	cr6.compare<int32_t>(r27.s32, 150, xer);
	// beq cr6,0x8220f240
	if (cr6.eq) goto loc_8220F240;
	// cmpwi cr6,r27,151
	cr6.compare<int32_t>(r27.s32, 151, xer);
	// beq cr6,0x8220f240
	if (cr6.eq) goto loc_8220F240;
	// cmpwi cr6,r27,152
	cr6.compare<int32_t>(r27.s32, 152, xer);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bne cr6,0x8220f244
	if (!cr6.eq) goto loc_8220F244;
loc_8220F240:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_8220F244:
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8220F24C;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8220f274
	if (cr6.eq) goto loc_8220F274;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// bl 0x82203008
	ctx.lr = 0x8220F260;
	sub_82203008(ctx, base);
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r11,-10308
	ctx.r4.s64 = r11.s64 + -10308;
	// bl 0x82722678
	ctx.lr = 0x8220F274;
	sub_82722678(ctx, base);
loc_8220F274:
	// addis r29,r31,5
	r29.s64 = r31.s64 + 327680;
	// cmplwi cr6,r27,201
	cr6.compare<uint32_t>(r27.u32, 201, xer);
	// addi r29,r29,5504
	r29.s64 = r29.s64 + 5504;
	// bgt cr6,0x82210c9c
	if (cr6.gt) goto loc_82210C9C;
	// lis r12,-32223
	r12.s64 = -2111766528;
	// addi r12,r12,-3428
	r12.s64 = r12.s64 + -3428;
	// rlwinm r0,r27,2,0,29
	r0.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r27.u64) {
	case 0:
		goto loc_82210C9C;
	case 1:
		goto loc_8220F5CC;
	case 2:
		goto loc_8220F5DC;
	case 3:
		goto loc_8220F5EC;
	case 4:
		goto loc_8220F60C;
	case 5:
		goto loc_8220F61C;
	case 6:
		goto loc_8220F5CC;
	case 7:
		goto loc_8220F62C;
	case 8:
		goto loc_8220F63C;
	case 9:
		goto loc_8220F64C;
	case 10:
		goto loc_8220F65C;
	case 11:
		goto loc_8220F66C;
	case 12:
		goto loc_8220F67C;
	case 13:
		goto loc_8220F68C;
	case 14:
		goto loc_8220F67C;
	case 15:
		goto loc_8220F5CC;
	case 16:
		goto loc_82210C9C;
	case 17:
		goto loc_82210C9C;
	case 18:
		goto loc_82210C9C;
	case 19:
		goto loc_82210C9C;
	case 20:
		goto loc_82210C9C;
	case 21:
		goto loc_82210C9C;
	case 22:
		goto loc_82210C9C;
	case 23:
		goto loc_8220FBF0;
	case 24:
		goto loc_8220FC34;
	case 25:
		goto loc_8220FC78;
	case 26:
		goto loc_8220FCBC;
	case 27:
		goto loc_8220FD6C;
	case 28:
		goto loc_8220FD90;
	case 29:
		goto loc_82210C9C;
	case 30:
		goto loc_8220FEC8;
	case 31:
		goto loc_8220FF50;
	case 32:
		goto loc_82210000;
	case 33:
		goto loc_82210024;
	case 34:
		goto loc_82210088;
	case 35:
		goto loc_8221013C;
	case 36:
		goto loc_8220F5CC;
	case 37:
		goto loc_822101A0;
	case 38:
		goto loc_82210250;
	case 39:
		goto loc_822102D8;
	case 40:
		goto loc_82210360;
	case 41:
		goto loc_822103CC;
	case 42:
		goto loc_82210454;
	case 43:
		goto loc_822104DC;
	case 44:
		goto loc_82210520;
	case 45:
		goto loc_8221058C;
	case 46:
		goto loc_82210C9C;
	case 47:
		goto loc_82210C9C;
	case 48:
		goto loc_82210C9C;
	case 49:
		goto loc_82210C9C;
	case 50:
		goto loc_82210C9C;
	case 51:
		goto loc_82210C9C;
	case 52:
		goto loc_82210C9C;
	case 53:
		goto loc_82210C9C;
	case 54:
		goto loc_82210A14;
	case 55:
		goto loc_82210A7C;
	case 56:
		goto loc_82210B44;
	case 57:
		goto loc_82210BAC;
	case 58:
		goto loc_82210BF0;
	case 59:
		goto loc_82210C34;
	case 60:
		goto loc_82210C9C;
	case 61:
		goto loc_82210C9C;
	case 62:
		goto loc_82210C9C;
	case 63:
		goto loc_82210C9C;
	case 64:
		goto loc_82210C9C;
	case 65:
		goto loc_82210C9C;
	case 66:
		goto loc_82210C9C;
	case 67:
		goto loc_82210C9C;
	case 68:
		goto loc_82210C9C;
	case 69:
		goto loc_82210C9C;
	case 70:
		goto loc_82210C9C;
	case 71:
		goto loc_82210C9C;
	case 72:
		goto loc_82210C9C;
	case 73:
		goto loc_82210C9C;
	case 74:
		goto loc_82210C9C;
	case 75:
		goto loc_82210C9C;
	case 76:
		goto loc_82210C9C;
	case 77:
		goto loc_82210C9C;
	case 78:
		goto loc_82210C9C;
	case 79:
		goto loc_82210C9C;
	case 80:
		goto loc_82210C9C;
	case 81:
		goto loc_82210C9C;
	case 82:
		goto loc_82210C9C;
	case 83:
		goto loc_82210C9C;
	case 84:
		goto loc_82210C9C;
	case 85:
		goto loc_82210C9C;
	case 86:
		goto loc_82210C9C;
	case 87:
		goto loc_82210C9C;
	case 88:
		goto loc_82210C9C;
	case 89:
		goto loc_82210C9C;
	case 90:
		goto loc_82210C9C;
	case 91:
		goto loc_82210C9C;
	case 92:
		goto loc_82210C9C;
	case 93:
		goto loc_82210C9C;
	case 94:
		goto loc_82210C9C;
	case 95:
		goto loc_82210C9C;
	case 96:
		goto loc_82210C9C;
	case 97:
		goto loc_82210C9C;
	case 98:
		goto loc_82210C9C;
	case 99:
		goto loc_82210C9C;
	case 100:
		goto loc_82210C9C;
	case 101:
		goto loc_8220F5CC;
	case 102:
		goto loc_8220F5DC;
	case 103:
		goto loc_8220F5FC;
	case 104:
		goto loc_82210C9C;
	case 105:
		goto loc_82210C9C;
	case 106:
		goto loc_8220F5CC;
	case 107:
		goto loc_82210C9C;
	case 108:
		goto loc_82210C9C;
	case 109:
		goto loc_82210C9C;
	case 110:
		goto loc_82210C9C;
	case 111:
		goto loc_82210C9C;
	case 112:
		goto loc_82210C9C;
	case 113:
		goto loc_8220F6CC;
	case 114:
		goto loc_8220F7A0;
	case 115:
		goto loc_8220F828;
	case 116:
		goto loc_8220F868;
	case 117:
		goto loc_8220F8D0;
	case 118:
		goto loc_8220F910;
	case 119:
		goto loc_8220F9C0;
	case 120:
		goto loc_8220FA4C;
	case 121:
		goto loc_8220FAD8;
	case 122:
		goto loc_8220FB64;
	case 123:
		goto loc_82210C9C;
	case 124:
		goto loc_82210C9C;
	case 125:
		goto loc_82210C9C;
	case 126:
		goto loc_82210C9C;
	case 127:
		goto loc_82210C9C;
	case 128:
		goto loc_8220FD90;
	case 129:
		goto loc_8220FE40;
	case 130:
		goto loc_82210C9C;
	case 131:
		goto loc_82210C9C;
	case 132:
		goto loc_82210C9C;
	case 133:
		goto loc_82210C9C;
	case 134:
		goto loc_82210C9C;
	case 135:
		goto loc_82210C9C;
	case 136:
		goto loc_82210C9C;
	case 137:
		goto loc_82210C9C;
	case 138:
		goto loc_82210C9C;
	case 139:
		goto loc_82210C9C;
	case 140:
		goto loc_82210C9C;
	case 141:
		goto loc_82210C9C;
	case 142:
		goto loc_82210C9C;
	case 143:
		goto loc_82210C9C;
	case 144:
		goto loc_82210C9C;
	case 145:
		goto loc_8221065C;
	case 146:
		goto loc_822106C4;
	case 147:
		goto loc_82210704;
	case 148:
		goto loc_82210744;
	case 149:
		goto loc_822107A8;
	case 150:
		goto loc_82210810;
	case 151:
		goto loc_8221089C;
	case 152:
		goto loc_82210900;
	case 153:
		goto loc_82210988;
	case 154:
		goto loc_82210C9C;
	case 155:
		goto loc_82210C9C;
	case 156:
		goto loc_82210AE0;
	case 157:
		goto loc_82210C9C;
	case 158:
		goto loc_82210C9C;
	case 159:
		goto loc_82210C9C;
	case 160:
		goto loc_82210C9C;
	case 161:
		goto loc_82210C9C;
	case 162:
		goto loc_82210C9C;
	case 163:
		goto loc_82210C9C;
	case 164:
		goto loc_82210C9C;
	case 165:
		goto loc_82210C9C;
	case 166:
		goto loc_82210C9C;
	case 167:
		goto loc_82210C9C;
	case 168:
		goto loc_82210C9C;
	case 169:
		goto loc_82210C9C;
	case 170:
		goto loc_82210C9C;
	case 171:
		goto loc_82210C9C;
	case 172:
		goto loc_82210C9C;
	case 173:
		goto loc_82210C9C;
	case 174:
		goto loc_82210C9C;
	case 175:
		goto loc_82210C9C;
	case 176:
		goto loc_82210C9C;
	case 177:
		goto loc_82210C9C;
	case 178:
		goto loc_82210C9C;
	case 179:
		goto loc_82210C9C;
	case 180:
		goto loc_82210C9C;
	case 181:
		goto loc_82210C9C;
	case 182:
		goto loc_82210C9C;
	case 183:
		goto loc_82210C9C;
	case 184:
		goto loc_82210C9C;
	case 185:
		goto loc_82210C9C;
	case 186:
		goto loc_82210C9C;
	case 187:
		goto loc_82210C9C;
	case 188:
		goto loc_82210C9C;
	case 189:
		goto loc_82210C9C;
	case 190:
		goto loc_82210C9C;
	case 191:
		goto loc_82210C9C;
	case 192:
		goto loc_82210C9C;
	case 193:
		goto loc_82210C9C;
	case 194:
		goto loc_82210C9C;
	case 195:
		goto loc_82210C9C;
	case 196:
		goto loc_82210C9C;
	case 197:
		goto loc_82210C9C;
	case 198:
		goto loc_82210C9C;
	case 199:
		goto loc_82210C9C;
	case 200:
		goto loc_82210C9C;
	case 201:
		goto loc_8220F5CC;
	default:
		__builtin_unreachable();
	}
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,-2612(0)
	r17.u64 = PPC_LOAD_U32(-2612);
	// lwz r17,-2596(0)
	r17.u64 = PPC_LOAD_U32(-2596);
	// lwz r17,-2580(0)
	r17.u64 = PPC_LOAD_U32(-2580);
	// lwz r17,-2548(0)
	r17.u64 = PPC_LOAD_U32(-2548);
	// lwz r17,-2532(0)
	r17.u64 = PPC_LOAD_U32(-2532);
	// lwz r17,-2612(0)
	r17.u64 = PPC_LOAD_U32(-2612);
	// lwz r17,-2516(0)
	r17.u64 = PPC_LOAD_U32(-2516);
	// lwz r17,-2500(0)
	r17.u64 = PPC_LOAD_U32(-2500);
	// lwz r17,-2484(0)
	r17.u64 = PPC_LOAD_U32(-2484);
	// lwz r17,-2468(0)
	r17.u64 = PPC_LOAD_U32(-2468);
	// lwz r17,-2452(0)
	r17.u64 = PPC_LOAD_U32(-2452);
	// lwz r17,-2436(0)
	r17.u64 = PPC_LOAD_U32(-2436);
	// lwz r17,-2420(0)
	r17.u64 = PPC_LOAD_U32(-2420);
	// lwz r17,-2436(0)
	r17.u64 = PPC_LOAD_U32(-2436);
	// lwz r17,-2612(0)
	r17.u64 = PPC_LOAD_U32(-2612);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,-1040(0)
	r17.u64 = PPC_LOAD_U32(-1040);
	// lwz r17,-972(0)
	r17.u64 = PPC_LOAD_U32(-972);
	// lwz r17,-904(0)
	r17.u64 = PPC_LOAD_U32(-904);
	// lwz r17,-836(0)
	r17.u64 = PPC_LOAD_U32(-836);
	// lwz r17,-660(0)
	r17.u64 = PPC_LOAD_U32(-660);
	// lwz r17,-624(0)
	r17.u64 = PPC_LOAD_U32(-624);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,-312(0)
	r17.u64 = PPC_LOAD_U32(-312);
	// lwz r17,-176(0)
	r17.u64 = PPC_LOAD_U32(-176);
	// lwz r17,0(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r17,36(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	// lwz r17,136(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r17,316(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// lwz r17,-2612(0)
	r17.u64 = PPC_LOAD_U32(-2612);
	// lwz r17,416(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 416);
	// lwz r17,592(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 592);
	// lwz r17,728(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 728);
	// lwz r17,864(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 864);
	// lwz r17,972(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 972);
	// lwz r17,1108(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1108);
	// lwz r17,1244(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1244);
	// lwz r17,1312(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1312);
	// lwz r17,1420(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1420);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,2580(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2580);
	// lwz r17,2684(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2684);
	// lwz r17,2884(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2884);
	// lwz r17,2988(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2988);
	// lwz r17,3056(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3056);
	// lwz r17,3124(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3124);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,-2612(0)
	r17.u64 = PPC_LOAD_U32(-2612);
	// lwz r17,-2596(0)
	r17.u64 = PPC_LOAD_U32(-2596);
	// lwz r17,-2564(0)
	r17.u64 = PPC_LOAD_U32(-2564);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,-2612(0)
	r17.u64 = PPC_LOAD_U32(-2612);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,-2356(0)
	r17.u64 = PPC_LOAD_U32(-2356);
	// lwz r17,-2144(0)
	r17.u64 = PPC_LOAD_U32(-2144);
	// lwz r17,-2008(0)
	r17.u64 = PPC_LOAD_U32(-2008);
	// lwz r17,-1944(0)
	r17.u64 = PPC_LOAD_U32(-1944);
	// lwz r17,-1840(0)
	r17.u64 = PPC_LOAD_U32(-1840);
	// lwz r17,-1776(0)
	r17.u64 = PPC_LOAD_U32(-1776);
	// lwz r17,-1600(0)
	r17.u64 = PPC_LOAD_U32(-1600);
	// lwz r17,-1460(0)
	r17.u64 = PPC_LOAD_U32(-1460);
	// lwz r17,-1320(0)
	r17.u64 = PPC_LOAD_U32(-1320);
	// lwz r17,-1180(0)
	r17.u64 = PPC_LOAD_U32(-1180);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,-624(0)
	r17.u64 = PPC_LOAD_U32(-624);
	// lwz r17,-448(0)
	r17.u64 = PPC_LOAD_U32(-448);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,1628(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1628);
	// lwz r17,1732(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1732);
	// lwz r17,1796(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1796);
	// lwz r17,1860(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1860);
	// lwz r17,1960(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1960);
	// lwz r17,2064(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2064);
	// lwz r17,2204(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2204);
	// lwz r17,2304(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2304);
	// lwz r17,2440(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2440);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,2784(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2784);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,3228(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3228);
	// lwz r17,-2612(0)
	r17.u64 = PPC_LOAD_U32(-2612);
loc_8220F5C4:
	// bl 0x82720560
	ctx.lr = 0x8220F5C8;
	sub_82720560(ctx, base);
	// b 0x8220f274
	goto loc_8220F274;
loc_8220F5CC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r30,2
	r30.s64 = 2;
	// addi r29,r11,24324
	r29.s64 = r11.s64 + 24324;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F5DC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r29,r11,24348
	r29.s64 = r11.s64 + 24348;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F5EC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,3
	r30.s64 = 3;
	// addi r29,r11,28260
	r29.s64 = r11.s64 + 28260;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F5FC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,3
	r30.s64 = 3;
	// addi r29,r11,28732
	r29.s64 = r11.s64 + 28732;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F60C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,2
	r30.s64 = 2;
	// addi r29,r11,29212
	r29.s64 = r11.s64 + 29212;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F61C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r29,r11,28540
	r29.s64 = r11.s64 + 28540;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F62C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,6
	r30.s64 = 6;
	// addi r29,r11,28004
	r29.s64 = r11.s64 + 28004;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F63C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,4
	r30.s64 = 4;
	// addi r29,r11,28668
	r29.s64 = r11.s64 + 28668;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F64C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,2
	r30.s64 = 2;
	// addi r29,r11,28700
	r29.s64 = r11.s64 + 28700;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F65C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,3
	r30.s64 = 3;
	// addi r29,r11,28324
	r29.s64 = r11.s64 + 28324;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F66C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,2
	r30.s64 = 2;
	// addi r29,r11,28284
	r29.s64 = r11.s64 + 28284;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F67C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r29,r11,24340
	r29.s64 = r11.s64 + 24340;
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F68C:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5516
	ctx.r8.u64 = r11.u64 | 5516;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// ori r6,r10,5508
	ctx.r6.u64 = ctx.r10.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-10324
	ctx.r3.s64 = ctx.r7.s64 + -10324;
	// addi r11,r5,-10336
	r11.s64 = ctx.r5.s64 + -10336;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r28,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r28.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F6CC:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r11,r11,5548
	r11.u64 = r11.u64 | 5548;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// ori r10,r10,5540
	ctx.r10.u64 = ctx.r10.u64 | 5540;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r25,-32254
	r25.s64 = -2113798144;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// addi r26,r26,-10356
	r26.s64 = r26.s64 + -10356;
	// ori r8,r8,5524
	ctx.r8.u64 = ctx.r8.u64 | 5524;
	// lis r18,-32254
	r18.s64 = -2113798144;
	// stwx r26,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r26.u32);
	// addi r25,r25,-10368
	r25.s64 = r25.s64 + -10368;
	// ori r9,r9,5532
	ctx.r9.u64 = ctx.r9.u64 | 5532;
	// ori r7,r7,5516
	ctx.r7.u64 = ctx.r7.u64 | 5516;
	// stwx r25,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r25.u32);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r24,-32254
	r24.s64 = -2113798144;
	// lis r17,-32254
	r17.s64 = -2113798144;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// addi r11,r18,-10384
	r11.s64 = r18.s64 + -10384;
	// ori r5,r5,5544
	ctx.r5.u64 = ctx.r5.u64 | 5544;
	// addi r24,r24,-10404
	r24.s64 = r24.s64 + -10404;
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// addi r10,r17,-10324
	ctx.r10.s64 = r17.s64 + -10324;
	// ori r6,r6,5508
	ctx.r6.u64 = ctx.r6.u64 | 5508;
	// stwx r24,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r24.u32);
	// ori r4,r4,5536
	ctx.r4.u64 = ctx.r4.u64 | 5536;
	// stwx r10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r10.u32);
	// lis r30,5
	r30.s64 = 327680;
	// lis r16,-32254
	r16.s64 = -2113798144;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// lis r27,5
	r27.s64 = 327680;
	// li r8,20
	ctx.r8.s64 = 20;
	// ori r30,r30,5520
	r30.u64 = r30.u64 | 5520;
	// addi r9,r16,-10336
	ctx.r9.s64 = r16.s64 + -10336;
	// stwx r8,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r8.u32);
	// li r7,12
	ctx.r7.s64 = 12;
	// ori r3,r3,5528
	ctx.r3.u64 = ctx.r3.u64 | 5528;
	// stwx r9,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r9.u32);
	// ori r27,r27,5512
	r27.u64 = r27.u64 | 5512;
	// stwx r7,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r7.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,2
	ctx.r4.s64 = 2;
	// stwx r5,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r5.u32);
	// stwx r6,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, ctx.r6.u32);
	// li r30,6
	r30.s64 = 6;
	// stwx r28,r31,r27
	PPC_STORE_U32(r31.u32 + r27.u32, r28.u32);
	// stw r4,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r4.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F7A0:
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r3,r10,5532
	ctx.r3.u64 = ctx.r10.u64 | 5532;
	// ori r4,r11,5528
	ctx.r4.u64 = r11.u64 | 5528;
	// ori r10,r9,5524
	ctx.r10.u64 = ctx.r9.u64 | 5524;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r11,r11,-10404
	r11.s64 = r11.s64 + -10404;
	// li r30,4
	r30.s64 = 4;
	// addi r9,r9,-10384
	ctx.r9.s64 = ctx.r9.s64 + -10384;
	// stwx r11,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r11.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// lis r27,-32254
	r27.s64 = -2113798144;
	// stwx r9,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r4,r27,-10324
	ctx.r4.s64 = r27.s64 + -10324;
	// addi r3,r26,-10336
	ctx.r3.s64 = r26.s64 + -10336;
	// li r11,3
	r11.s64 = 3;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F828:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5516
	ctx.r8.u64 = r11.u64 | 5516;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// ori r6,r10,5508
	ctx.r6.u64 = ctx.r10.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-10420
	ctx.r3.s64 = ctx.r7.s64 + -10420;
	// addi r11,r5,-10336
	r11.s64 = ctx.r5.s64 + -10336;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r28,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r28.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F868:
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5524
	ctx.r6.u64 = r11.u64 | 5524;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5508
	r11.u64 = ctx.r9.u64 | 5508;
	// ori r9,r8,5520
	ctx.r9.u64 = ctx.r8.u64 | 5520;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// ori r8,r7,5512
	ctx.r8.u64 = ctx.r7.u64 | 5512;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r7,r5,-10420
	ctx.r7.s64 = ctx.r5.s64 + -10420;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r5,r3,-10324
	ctx.r5.s64 = ctx.r3.s64 + -10324;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r3,r10,-10336
	ctx.r3.s64 = ctx.r10.s64 + -10336;
	// stwx r28,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r28.u32);
	// li r10,14
	ctx.r10.s64 = 14;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// stwx r10,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// li r30,3
	r30.s64 = 3;
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F8D0:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5516
	ctx.r8.u64 = r11.u64 | 5516;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// ori r6,r10,5508
	ctx.r6.u64 = ctx.r10.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-10336
	ctx.r3.s64 = ctx.r7.s64 + -10336;
	// addi r11,r5,-10436
	r11.s64 = ctx.r5.s64 + -10436;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F910:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r11,r11,5540
	r11.u64 = r11.u64 | 5540;
	// ori r10,r10,5532
	ctx.r10.u64 = ctx.r10.u64 | 5532;
	// ori r9,r9,5524
	ctx.r9.u64 = ctx.r9.u64 | 5524;
	// lis r30,-32254
	r30.s64 = -2113798144;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// addi r30,r30,-10356
	r30.s64 = r30.s64 + -10356;
	// addi r27,r27,-10460
	r27.s64 = r27.s64 + -10460;
	// addi r26,r26,-10476
	r26.s64 = r26.s64 + -10476;
	// stwx r30,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r30.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// stwx r27,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r27.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// stwx r26,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r26.u32);
	// ori r6,r6,5536
	ctx.r6.u64 = ctx.r6.u64 | 5536;
	// lis r25,-32254
	r25.s64 = -2113798144;
	// lis r24,-32254
	r24.s64 = -2113798144;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// addi r11,r25,-10492
	r11.s64 = r25.s64 + -10492;
	// addi r10,r24,-10336
	ctx.r10.s64 = r24.s64 + -10336;
	// li r9,20
	ctx.r9.s64 = 20;
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// stwx r10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r10.u32);
	// ori r4,r4,5520
	ctx.r4.u64 = ctx.r4.u64 | 5520;
	// stwx r9,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r9.u32);
	// ori r3,r3,5512
	ctx.r3.u64 = ctx.r3.u64 | 5512;
	// li r8,24
	ctx.r8.s64 = 24;
	// li r7,13
	ctx.r7.s64 = 13;
	// li r6,2
	ctx.r6.s64 = 2;
	// stwx r8,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r8.u32);
	// stwx r7,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r7.u32);
	// li r30,5
	r30.s64 = 5;
	// stwx r28,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r28.u32);
	// stw r6,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r6.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220F9C0:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r4,r11,5532
	ctx.r4.u64 = r11.u64 | 5532;
	// ori r11,r10,5524
	r11.u64 = ctx.r10.u64 | 5524;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r3,r3,-10356
	ctx.r3.s64 = ctx.r3.s64 + -10356;
	// addi r10,r10,-10512
	ctx.r10.s64 = ctx.r10.s64 + -10512;
	// ori r9,r9,5516
	ctx.r9.u64 = ctx.r9.u64 | 5516;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// ori r8,r8,5508
	ctx.r8.u64 = ctx.r8.u64 | 5508;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// ori r7,r7,5528
	ctx.r7.u64 = ctx.r7.u64 | 5528;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r30,r30,-10492
	r30.s64 = r30.s64 + -10492;
	// addi r4,r27,-10336
	ctx.r4.s64 = r27.s64 + -10336;
	// li r3,20
	ctx.r3.s64 = 20;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// li r11,14
	r11.s64 = 14;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,4
	r30.s64 = 4;
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FA4C:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r4,r11,5532
	ctx.r4.u64 = r11.u64 | 5532;
	// ori r11,r10,5524
	r11.u64 = ctx.r10.u64 | 5524;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r3,r3,-10356
	ctx.r3.s64 = ctx.r3.s64 + -10356;
	// addi r10,r10,-10528
	ctx.r10.s64 = ctx.r10.s64 + -10528;
	// ori r9,r9,5516
	ctx.r9.u64 = ctx.r9.u64 | 5516;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// ori r8,r8,5508
	ctx.r8.u64 = ctx.r8.u64 | 5508;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// ori r7,r7,5528
	ctx.r7.u64 = ctx.r7.u64 | 5528;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r30,r30,-10492
	r30.s64 = r30.s64 + -10492;
	// addi r4,r27,-10336
	ctx.r4.s64 = r27.s64 + -10336;
	// li r3,20
	ctx.r3.s64 = 20;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// li r11,14
	r11.s64 = 14;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,4
	r30.s64 = 4;
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FAD8:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r4,r11,5532
	ctx.r4.u64 = r11.u64 | 5532;
	// ori r11,r10,5524
	r11.u64 = ctx.r10.u64 | 5524;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r3,r3,-10356
	ctx.r3.s64 = ctx.r3.s64 + -10356;
	// addi r10,r10,-10540
	ctx.r10.s64 = ctx.r10.s64 + -10540;
	// ori r9,r9,5516
	ctx.r9.u64 = ctx.r9.u64 | 5516;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// ori r8,r8,5508
	ctx.r8.u64 = ctx.r8.u64 | 5508;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// ori r7,r7,5528
	ctx.r7.u64 = ctx.r7.u64 | 5528;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r30,r30,-10492
	r30.s64 = r30.s64 + -10492;
	// addi r4,r27,-10336
	ctx.r4.s64 = r27.s64 + -10336;
	// li r3,20
	ctx.r3.s64 = 20;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// li r11,13
	r11.s64 = 13;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,4
	r30.s64 = 4;
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FB64:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r4,r11,5532
	ctx.r4.u64 = r11.u64 | 5532;
	// ori r11,r10,5524
	r11.u64 = ctx.r10.u64 | 5524;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r3,r3,-10356
	ctx.r3.s64 = ctx.r3.s64 + -10356;
	// addi r10,r10,-10548
	ctx.r10.s64 = ctx.r10.s64 + -10548;
	// ori r9,r9,5516
	ctx.r9.u64 = ctx.r9.u64 | 5516;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// ori r8,r8,5508
	ctx.r8.u64 = ctx.r8.u64 | 5508;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// ori r7,r7,5528
	ctx.r7.u64 = ctx.r7.u64 | 5528;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r30,r30,-10492
	r30.s64 = r30.s64 + -10492;
	// addi r4,r27,-10336
	ctx.r4.s64 = r27.s64 + -10336;
	// li r3,20
	ctx.r3.s64 = 20;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// li r11,13
	r11.s64 = 13;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,4
	r30.s64 = 4;
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FBF0:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5508
	ctx.r8.u64 = r11.u64 | 5508;
	// ori r6,r10,5516
	ctx.r6.u64 = ctx.r10.u64 | 5516;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// addi r3,r7,-10568
	ctx.r3.s64 = ctx.r7.s64 + -10568;
	// addi r11,r5,-10492
	r11.s64 = ctx.r5.s64 + -10492;
	// li r10,27
	ctx.r10.s64 = 27;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,2
	r30.s64 = 2;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stwx r28,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r28.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FC34:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5508
	ctx.r8.u64 = r11.u64 | 5508;
	// ori r6,r10,5516
	ctx.r6.u64 = ctx.r10.u64 | 5516;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// addi r3,r7,-10568
	ctx.r3.s64 = ctx.r7.s64 + -10568;
	// addi r11,r5,-10492
	r11.s64 = ctx.r5.s64 + -10492;
	// li r10,25
	ctx.r10.s64 = 25;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,2
	r30.s64 = 2;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stwx r28,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r28.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FC78:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5508
	ctx.r8.u64 = r11.u64 | 5508;
	// ori r6,r10,5516
	ctx.r6.u64 = ctx.r10.u64 | 5516;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// addi r3,r7,-10568
	ctx.r3.s64 = ctx.r7.s64 + -10568;
	// addi r11,r5,-10492
	r11.s64 = ctx.r5.s64 + -10492;
	// li r10,26
	ctx.r10.s64 = 26;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,2
	r30.s64 = 2;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stwx r28,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r28.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FCBC:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r11,r11,5508
	r11.u64 = r11.u64 | 5508;
	// ori r10,r10,5516
	ctx.r10.u64 = ctx.r10.u64 | 5516;
	// lis r30,-32254
	r30.s64 = -2113798144;
	// lis r28,-32254
	r28.s64 = -2113798144;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// addi r30,r30,-10592
	r30.s64 = r30.s64 + -10592;
	// addi r28,r28,-10612
	r28.s64 = r28.s64 + -10612;
	// ori r9,r9,5524
	ctx.r9.u64 = ctx.r9.u64 | 5524;
	// stwx r30,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r30.u32);
	// ori r8,r8,5532
	ctx.r8.u64 = ctx.r8.u64 | 5532;
	// stwx r28,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r28.u32);
	// ori r7,r7,5540
	ctx.r7.u64 = ctx.r7.u64 | 5540;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// lis r24,-32254
	r24.s64 = -2113798144;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// addi r11,r26,-10644
	r11.s64 = r26.s64 + -10644;
	// addi r27,r27,-10632
	r27.s64 = r27.s64 + -10632;
	// addi r10,r24,-10664
	ctx.r10.s64 = r24.s64 + -10664;
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// ori r6,r6,5512
	ctx.r6.u64 = ctx.r6.u64 | 5512;
	// stwx r27,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r27.u32);
	// ori r5,r5,5520
	ctx.r5.u64 = ctx.r5.u64 | 5520;
	// stwx r10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r10.u32);
	// ori r4,r4,5528
	ctx.r4.u64 = ctx.r4.u64 | 5528;
	// ori r3,r3,5536
	ctx.r3.u64 = ctx.r3.u64 | 5536;
	// li r9,24
	ctx.r9.s64 = 24;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// li r11,2
	r11.s64 = 2;
	// stwx r8,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r8.u32);
	// stwx r7,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r7.u32);
	// li r30,5
	r30.s64 = 5;
	// stwx r11,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r11.u32);
	// stwx r25,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r25.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FD6C:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r9,r11,5508
	ctx.r9.u64 = r11.u64 | 5508;
	// li r8,9
	ctx.r8.s64 = 9;
	// addi r7,r10,-10684
	ctx.r7.s64 = ctx.r10.s64 + -10684;
	// mr r30,r28
	r30.u64 = r28.u64;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stwx r7,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r7.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FD90:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r11,r11,5540
	r11.u64 = r11.u64 | 5540;
	// ori r10,r10,5532
	ctx.r10.u64 = ctx.r10.u64 | 5532;
	// ori r9,r9,5524
	ctx.r9.u64 = ctx.r9.u64 | 5524;
	// lis r30,-32254
	r30.s64 = -2113798144;
	// lis r28,-32254
	r28.s64 = -2113798144;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// addi r30,r30,-10700
	r30.s64 = r30.s64 + -10700;
	// addi r28,r28,-10716
	r28.s64 = r28.s64 + -10716;
	// addi r27,r27,-10736
	r27.s64 = r27.s64 + -10736;
	// stwx r30,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r30.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// stwx r28,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r28.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// stwx r27,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r27.u32);
	// ori r6,r6,5536
	ctx.r6.u64 = ctx.r6.u64 | 5536;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// lis r25,-32254
	r25.s64 = -2113798144;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// addi r11,r26,-10336
	r11.s64 = r26.s64 + -10336;
	// addi r10,r25,-10752
	ctx.r10.s64 = r25.s64 + -10752;
	// li r9,29
	ctx.r9.s64 = 29;
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// stwx r10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r10.u32);
	// ori r4,r4,5520
	ctx.r4.u64 = ctx.r4.u64 | 5520;
	// stwx r9,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r9.u32);
	// ori r3,r3,5512
	ctx.r3.u64 = ctx.r3.u64 | 5512;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,2
	ctx.r6.s64 = 2;
	// stwx r8,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r8.u32);
	// stwx r7,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r7.u32);
	// li r30,5
	r30.s64 = 5;
	// stwx r6,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, ctx.r6.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FE40:
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r3,r10,5532
	ctx.r3.u64 = ctx.r10.u64 | 5532;
	// ori r4,r11,5528
	ctx.r4.u64 = r11.u64 | 5528;
	// ori r10,r9,5524
	ctx.r10.u64 = ctx.r9.u64 | 5524;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r11,r11,-10772
	r11.s64 = r11.s64 + -10772;
	// li r30,4
	r30.s64 = 4;
	// addi r9,r9,-10788
	ctx.r9.s64 = ctx.r9.s64 + -10788;
	// stwx r11,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r11.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// lis r27,-32254
	r27.s64 = -2113798144;
	// stwx r9,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r4,r27,-10808
	ctx.r4.s64 = r27.s64 + -10808;
	// addi r3,r26,-10336
	ctx.r3.s64 = r26.s64 + -10336;
	// li r11,3
	r11.s64 = 3;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FEC8:
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r3,r10,5532
	ctx.r3.u64 = ctx.r10.u64 | 5532;
	// ori r4,r11,5528
	ctx.r4.u64 = r11.u64 | 5528;
	// ori r10,r9,5524
	ctx.r10.u64 = ctx.r9.u64 | 5524;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r11,r11,-10828
	r11.s64 = r11.s64 + -10828;
	// li r30,4
	r30.s64 = 4;
	// addi r9,r9,-10840
	ctx.r9.s64 = ctx.r9.s64 + -10840;
	// stwx r11,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r11.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// lis r27,-32254
	r27.s64 = -2113798144;
	// stwx r9,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r4,r27,-10492
	ctx.r4.s64 = r27.s64 + -10492;
	// addi r3,r26,-10336
	ctx.r3.s64 = r26.s64 + -10336;
	// li r11,3
	r11.s64 = 3;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8220FF50:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r11,r11,5540
	r11.u64 = r11.u64 | 5540;
	// ori r10,r10,5532
	ctx.r10.u64 = ctx.r10.u64 | 5532;
	// ori r9,r9,5524
	ctx.r9.u64 = ctx.r9.u64 | 5524;
	// lis r30,-32254
	r30.s64 = -2113798144;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// addi r30,r30,-10864
	r30.s64 = r30.s64 + -10864;
	// addi r27,r27,-10884
	r27.s64 = r27.s64 + -10884;
	// addi r26,r26,-10828
	r26.s64 = r26.s64 + -10828;
	// stwx r30,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r30.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// stwx r27,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r27.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// stwx r26,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r26.u32);
	// ori r6,r6,5536
	ctx.r6.u64 = ctx.r6.u64 | 5536;
	// lis r25,-32254
	r25.s64 = -2113798144;
	// lis r24,-32254
	r24.s64 = -2113798144;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// addi r11,r25,-10904
	r11.s64 = r25.s64 + -10904;
	// addi r10,r24,-10336
	ctx.r10.s64 = r24.s64 + -10336;
	// li r9,3
	ctx.r9.s64 = 3;
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// stwx r10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r10.u32);
	// ori r4,r4,5520
	ctx.r4.u64 = ctx.r4.u64 | 5520;
	// stwx r9,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r9.u32);
	// ori r3,r3,5512
	ctx.r3.u64 = ctx.r3.u64 | 5512;
	// li r8,23
	ctx.r8.s64 = 23;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,2
	ctx.r6.s64 = 2;
	// stwx r8,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r8.u32);
	// stwx r7,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r7.u32);
	// li r30,5
	r30.s64 = 5;
	// stwx r28,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r28.u32);
	// stw r6,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r6.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210000:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r9,r11,5508
	ctx.r9.u64 = r11.u64 | 5508;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r7,r10,-10916
	ctx.r7.s64 = ctx.r10.s64 + -10916;
	// mr r30,r28
	r30.u64 = r28.u64;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stwx r7,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r7.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210024:
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5524
	r11.u64 = ctx.r9.u64 | 5524;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// ori r9,r8,5512
	ctx.r9.u64 = ctx.r8.u64 | 5512;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// addi r7,r5,-10864
	ctx.r7.s64 = ctx.r5.s64 + -10864;
	// addi r5,r3,-10336
	ctx.r5.s64 = ctx.r3.s64 + -10336;
	// addi r3,r10,-10932
	ctx.r3.s64 = ctx.r10.s64 + -10932;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stwx r10,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// stwx r28,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r28.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210088:
	// lis r11,5
	r11.s64 = 327680;
	// lis r30,-32254
	r30.s64 = -2113798144;
	// ori r11,r11,5540
	r11.u64 = r11.u64 | 5540;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// addi r30,r30,-10956
	r30.s64 = r30.s64 + -10956;
	// ori r10,r10,5532
	ctx.r10.u64 = ctx.r10.u64 | 5532;
	// ori r9,r9,5524
	ctx.r9.u64 = ctx.r9.u64 | 5524;
	// stwx r30,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r30.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// lis r28,-32254
	r28.s64 = -2113798144;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r28,r28,-10976
	r28.s64 = r28.s64 + -10976;
	// addi r27,r27,-10996
	r27.s64 = r27.s64 + -10996;
	// addi r11,r26,-11008
	r11.s64 = r26.s64 + -11008;
	// stwx r28,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r28.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// stwx r27,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r27.u32);
	// ori r6,r6,5536
	ctx.r6.u64 = ctx.r6.u64 | 5536;
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// lis r25,-32254
	r25.s64 = -2113798144;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// addi r10,r25,-10336
	ctx.r10.s64 = r25.s64 + -10336;
	// li r9,9
	ctx.r9.s64 = 9;
	// li r8,23
	ctx.r8.s64 = 23;
	// stwx r10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r10.u32);
	// ori r4,r4,5520
	ctx.r4.u64 = ctx.r4.u64 | 5520;
	// stwx r9,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r9.u32);
	// ori r3,r3,5512
	ctx.r3.u64 = ctx.r3.u64 | 5512;
	// stwx r8,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r8.u32);
	// li r7,18
	ctx.r7.s64 = 18;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,2
	ctx.r5.s64 = 2;
	// stwx r7,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r7.u32);
	// li r30,5
	r30.s64 = 5;
	// stwx r6,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, ctx.r6.u32);
	// stw r5,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r5.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8221013C:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5520
	ctx.r6.u64 = r11.u64 | 5520;
	// ori r5,r10,5524
	ctx.r5.u64 = ctx.r10.u64 | 5524;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// ori r3,r9,5516
	ctx.r3.u64 = ctx.r9.u64 | 5516;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// ori r10,r8,5508
	ctx.r10.u64 = ctx.r8.u64 | 5508;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// ori r8,r7,5512
	ctx.r8.u64 = ctx.r7.u64 | 5512;
	// addi r7,r4,-11028
	ctx.r7.s64 = ctx.r4.s64 + -11028;
	// addi r4,r11,-11040
	ctx.r4.s64 = r11.s64 + -11040;
	// addi r11,r9,-10336
	r11.s64 = ctx.r9.s64 + -10336;
	// stwx r7,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r7.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r4,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, ctx.r4.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stwx r11,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r11.u32);
	// stwx r30,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r30.u32);
	// stwx r28,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r28.u32);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_822101A0:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r11,r11,5540
	r11.u64 = r11.u64 | 5540;
	// ori r10,r10,5532
	ctx.r10.u64 = ctx.r10.u64 | 5532;
	// ori r9,r9,5524
	ctx.r9.u64 = ctx.r9.u64 | 5524;
	// lis r30,-32254
	r30.s64 = -2113798144;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// addi r30,r30,-11064
	r30.s64 = r30.s64 + -11064;
	// addi r27,r27,-11080
	r27.s64 = r27.s64 + -11080;
	// addi r26,r26,-11096
	r26.s64 = r26.s64 + -11096;
	// stwx r30,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r30.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// stwx r27,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r27.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// stwx r26,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r26.u32);
	// ori r6,r6,5536
	ctx.r6.u64 = ctx.r6.u64 | 5536;
	// lis r25,-32254
	r25.s64 = -2113798144;
	// lis r24,-32254
	r24.s64 = -2113798144;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// addi r11,r25,-11108
	r11.s64 = r25.s64 + -11108;
	// addi r10,r24,-10644
	ctx.r10.s64 = r24.s64 + -10644;
	// li r9,4
	ctx.r9.s64 = 4;
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// stwx r10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r10.u32);
	// ori r4,r4,5520
	ctx.r4.u64 = ctx.r4.u64 | 5520;
	// stwx r9,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r9.u32);
	// ori r3,r3,5512
	ctx.r3.u64 = ctx.r3.u64 | 5512;
	// li r8,19
	ctx.r8.s64 = 19;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,2
	ctx.r6.s64 = 2;
	// stwx r8,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r8.u32);
	// stwx r28,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r28.u32);
	// li r30,5
	r30.s64 = 5;
	// stwx r7,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, ctx.r7.u32);
	// stw r6,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r6.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210250:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8221025C;
	sub_8238EC00(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r9,-11120
	ctx.r4.s64 = ctx.r9.s64 + -11120;
	// lwz r3,-24180(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x82210274;
	sub_8220EEA8(ctx, base);
	// addi r4,r3,92
	ctx.r4.s64 = ctx.r3.s64 + 92;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823895f8
	ctx.lr = 0x82210284;
	sub_823895F8(ctx, base);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bgt cr6,0x8220f5dc
	if (cr6.gt) goto loc_8220F5DC;
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5508
	ctx.r8.u64 = r11.u64 | 5508;
	// ori r6,r10,5516
	ctx.r6.u64 = ctx.r10.u64 | 5516;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-10336
	ctx.r3.s64 = ctx.r7.s64 + -10336;
	// addi r11,r5,-11144
	r11.s64 = ctx.r5.s64 + -11144;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r10,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_822102D8:
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r3,r10,5532
	ctx.r3.u64 = ctx.r10.u64 | 5532;
	// ori r4,r11,5528
	ctx.r4.u64 = r11.u64 | 5528;
	// ori r10,r9,5524
	ctx.r10.u64 = ctx.r9.u64 | 5524;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r11,r11,-11064
	r11.s64 = r11.s64 + -11064;
	// li r30,4
	r30.s64 = 4;
	// addi r9,r9,-11080
	ctx.r9.s64 = ctx.r9.s64 + -11080;
	// stwx r11,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r11.u32);
	// ori r8,r8,5516
	ctx.r8.u64 = ctx.r8.u64 | 5516;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// lis r27,-32254
	r27.s64 = -2113798144;
	// stwx r9,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// ori r7,r7,5508
	ctx.r7.u64 = ctx.r7.u64 | 5508;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r4,r27,-11096
	ctx.r4.s64 = r27.s64 + -11096;
	// addi r3,r26,-10644
	ctx.r3.s64 = r26.s64 + -10644;
	// li r11,19
	r11.s64 = 19;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210360:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// ori r10,r8,5524
	ctx.r10.u64 = ctx.r8.u64 | 5524;
	// ori r11,r9,5512
	r11.u64 = ctx.r9.u64 | 5512;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r7,r5,-10336
	ctx.r7.s64 = ctx.r5.s64 + -10336;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r5,r3,-11168
	ctx.r5.s64 = ctx.r3.s64 + -11168;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r3,r9,-11188
	ctx.r3.s64 = ctx.r9.s64 + -11188;
	// li r9,2
	ctx.r9.s64 = 2;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stwx r3,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// li r6,19
	ctx.r6.s64 = 19;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// stwx r7,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r7.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r6,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r6.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_822103CC:
	// lis r10,5
	ctx.r10.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r3,r10,5508
	ctx.r3.u64 = ctx.r10.u64 | 5508;
	// ori r4,r11,5520
	ctx.r4.u64 = r11.u64 | 5520;
	// ori r10,r9,5516
	ctx.r10.u64 = ctx.r9.u64 | 5516;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r11,r11,-11204
	r11.s64 = r11.s64 + -11204;
	// li r30,4
	r30.s64 = 4;
	// addi r9,r9,-10644
	ctx.r9.s64 = ctx.r9.s64 + -10644;
	// stwx r11,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r11.u32);
	// ori r8,r8,5512
	ctx.r8.u64 = ctx.r8.u64 | 5512;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// ori r7,r7,5524
	ctx.r7.u64 = ctx.r7.u64 | 5524;
	// stwx r9,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// lis r28,-32254
	r28.s64 = -2113798144;
	// ori r6,r6,5532
	ctx.r6.u64 = ctx.r6.u64 | 5532;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// addi r4,r28,-11168
	ctx.r4.s64 = r28.s64 + -11168;
	// addi r3,r27,-11188
	ctx.r3.s64 = r27.s64 + -11188;
	// li r11,2
	r11.s64 = 2;
	// stwx r4,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r4.u32);
	// li r10,24
	ctx.r10.s64 = 24;
	// stwx r3,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r3.u32);
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// stwx r10,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210454:
	// lis r10,5
	ctx.r10.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r3,r10,5508
	ctx.r3.u64 = ctx.r10.u64 | 5508;
	// ori r4,r11,5520
	ctx.r4.u64 = r11.u64 | 5520;
	// ori r10,r9,5516
	ctx.r10.u64 = ctx.r9.u64 | 5516;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r11,r11,-11224
	r11.s64 = r11.s64 + -11224;
	// li r30,4
	r30.s64 = 4;
	// addi r9,r9,-10644
	ctx.r9.s64 = ctx.r9.s64 + -10644;
	// stwx r11,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r11.u32);
	// ori r8,r8,5512
	ctx.r8.u64 = ctx.r8.u64 | 5512;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// ori r7,r7,5524
	ctx.r7.u64 = ctx.r7.u64 | 5524;
	// stwx r9,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// lis r28,-32254
	r28.s64 = -2113798144;
	// ori r6,r6,5532
	ctx.r6.u64 = ctx.r6.u64 | 5532;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// addi r4,r28,-11168
	ctx.r4.s64 = r28.s64 + -11168;
	// addi r3,r27,-11188
	ctx.r3.s64 = r27.s64 + -11188;
	// li r11,2
	r11.s64 = 2;
	// stwx r4,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r4.u32);
	// li r10,24
	ctx.r10.s64 = 24;
	// stwx r3,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r3.u32);
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// stwx r10,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_822104DC:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5508
	ctx.r8.u64 = r11.u64 | 5508;
	// ori r6,r10,5516
	ctx.r6.u64 = ctx.r10.u64 | 5516;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-10336
	ctx.r3.s64 = ctx.r7.s64 + -10336;
	// addi r11,r5,-11244
	r11.s64 = ctx.r5.s64 + -11244;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// li r10,19
	ctx.r10.s64 = 19;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r10,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210520:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// ori r10,r8,5524
	ctx.r10.u64 = ctx.r8.u64 | 5524;
	// ori r11,r9,5512
	r11.u64 = ctx.r9.u64 | 5512;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r7,r5,-10644
	ctx.r7.s64 = ctx.r5.s64 + -10644;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r5,r3,-11168
	ctx.r5.s64 = ctx.r3.s64 + -11168;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r3,r9,-11188
	ctx.r3.s64 = ctx.r9.s64 + -11188;
	// li r9,2
	ctx.r9.s64 = 2;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stwx r3,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// li r6,24
	ctx.r6.s64 = 24;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// stwx r7,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r7.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r6,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r6.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8221058C:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r11,r11,5508
	r11.u64 = r11.u64 | 5508;
	// ori r10,r10,5516
	ctx.r10.u64 = ctx.r10.u64 | 5516;
	// lis r26,-32254
	r26.s64 = -2113798144;
	// lis r25,-32254
	r25.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// addi r26,r26,-11040
	r26.s64 = r26.s64 + -11040;
	// addi r25,r25,-11028
	r25.s64 = r25.s64 + -11028;
	// ori r8,r8,5524
	ctx.r8.u64 = ctx.r8.u64 | 5524;
	// stwx r26,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r26.u32);
	// ori r6,r6,5532
	ctx.r6.u64 = ctx.r6.u64 | 5532;
	// stwx r25,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r25.u32);
	// ori r4,r4,5540
	ctx.r4.u64 = ctx.r4.u64 | 5540;
	// lis r24,-32254
	r24.s64 = -2113798144;
	// lis r18,-32254
	r18.s64 = -2113798144;
	// lis r17,-32254
	r17.s64 = -2113798144;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// lis r28,5
	r28.s64 = 327680;
	// lis r27,5
	r27.s64 = 327680;
	// addi r11,r18,-11288
	r11.s64 = r18.s64 + -11288;
	// addi r10,r17,-10336
	ctx.r10.s64 = r17.s64 + -10336;
	// addi r24,r24,-11264
	r24.s64 = r24.s64 + -11264;
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// ori r9,r9,5512
	ctx.r9.u64 = ctx.r9.u64 | 5512;
	// stwx r10,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r10.u32);
	// ori r7,r7,5520
	ctx.r7.u64 = ctx.r7.u64 | 5520;
	// stwx r24,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r24.u32);
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// ori r3,r3,5536
	ctx.r3.u64 = ctx.r3.u64 | 5536;
	// ori r28,r28,5548
	r28.u64 = r28.u64 | 5548;
	// lis r16,-32254
	r16.s64 = -2113798144;
	// ori r27,r27,5544
	r27.u64 = r27.u64 | 5544;
	// li r30,6
	r30.s64 = 6;
	// addi r8,r16,-11304
	ctx.r8.s64 = r16.s64 + -11304;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r4,4
	ctx.r4.s64 = 4;
	// stwx r8,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, ctx.r8.u32);
	// li r11,9
	r11.s64 = 9;
	// stwx r6,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r6.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r4,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r4.u32);
	// stwx r11,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r11.u32);
	// stwx r10,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, ctx.r10.u32);
	// stwx r30,r31,r27
	PPC_STORE_U32(r31.u32 + r27.u32, r30.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8221065C:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// ori r10,r8,5524
	ctx.r10.u64 = ctx.r8.u64 | 5524;
	// ori r11,r9,5512
	r11.u64 = ctx.r9.u64 | 5512;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r7,r5,-10492
	ctx.r7.s64 = ctx.r5.s64 + -10492;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r5,r3,-10336
	ctx.r5.s64 = ctx.r3.s64 + -10336;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r3,r9,-11320
	ctx.r3.s64 = ctx.r9.s64 + -11320;
	// li r9,2
	ctx.r9.s64 = 2;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r7,24
	ctx.r7.s64 = 24;
	// stwx r3,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// stwx r9,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r9.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r7,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r7.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_822106C4:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5508
	ctx.r8.u64 = r11.u64 | 5508;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// ori r6,r10,5516
	ctx.r6.u64 = ctx.r10.u64 | 5516;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-11336
	ctx.r3.s64 = ctx.r7.s64 + -11336;
	// addi r11,r5,-10336
	r11.s64 = ctx.r5.s64 + -10336;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210704:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5508
	ctx.r8.u64 = r11.u64 | 5508;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// ori r6,r10,5516
	ctx.r6.u64 = ctx.r10.u64 | 5516;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-11352
	ctx.r3.s64 = ctx.r7.s64 + -11352;
	// addi r11,r5,-10336
	r11.s64 = ctx.r5.s64 + -10336;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210744:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5524
	r11.u64 = ctx.r9.u64 | 5524;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// ori r9,r8,5512
	ctx.r9.u64 = ctx.r8.u64 | 5512;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// addi r7,r5,-10492
	ctx.r7.s64 = ctx.r5.s64 + -10492;
	// addi r5,r3,-10336
	ctx.r5.s64 = ctx.r3.s64 + -10336;
	// addi r3,r10,-11372
	ctx.r3.s64 = ctx.r10.s64 + -11372;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// stwx r30,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r30.u32);
	// stwx r10,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_822107A8:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5524
	ctx.r6.u64 = r11.u64 | 5524;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5508
	r11.u64 = ctx.r9.u64 | 5508;
	// ori r9,r8,5520
	ctx.r9.u64 = ctx.r8.u64 | 5520;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// ori r8,r7,5512
	ctx.r8.u64 = ctx.r7.u64 | 5512;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r7,r5,-10700
	ctx.r7.s64 = ctx.r5.s64 + -10700;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r5,r3,-11388
	ctx.r5.s64 = ctx.r3.s64 + -11388;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r3,r10,-10752
	ctx.r3.s64 = ctx.r10.s64 + -10752;
	// li r10,29
	ctx.r10.s64 = 29;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// stwx r10,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r7,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r7.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210810:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r4,r11,5532
	ctx.r4.u64 = r11.u64 | 5532;
	// ori r11,r10,5524
	r11.u64 = ctx.r10.u64 | 5524;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r3,r3,-11404
	ctx.r3.s64 = ctx.r3.s64 + -11404;
	// addi r10,r10,-11420
	ctx.r10.s64 = ctx.r10.s64 + -11420;
	// ori r9,r9,5516
	ctx.r9.u64 = ctx.r9.u64 | 5516;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// ori r8,r8,5508
	ctx.r8.u64 = ctx.r8.u64 | 5508;
	// lis r28,-32254
	r28.s64 = -2113798144;
	// ori r7,r7,5528
	ctx.r7.u64 = ctx.r7.u64 | 5528;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r30,r30,-10336
	r30.s64 = r30.s64 + -10336;
	// addi r4,r28,-10492
	ctx.r4.s64 = r28.s64 + -10492;
	// li r3,24
	ctx.r3.s64 = 24;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// li r11,3
	r11.s64 = 3;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,4
	r30.s64 = 4;
	// stwx r10,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_8221089C:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5520
	ctx.r6.u64 = r11.u64 | 5520;
	// ori r5,r10,5524
	ctx.r5.u64 = ctx.r10.u64 | 5524;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// ori r3,r9,5516
	ctx.r3.u64 = ctx.r9.u64 | 5516;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// ori r10,r8,5508
	ctx.r10.u64 = ctx.r8.u64 | 5508;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// ori r8,r7,5512
	ctx.r8.u64 = ctx.r7.u64 | 5512;
	// addi r7,r4,-11432
	ctx.r7.s64 = ctx.r4.s64 + -11432;
	// addi r4,r11,-10336
	ctx.r4.s64 = r11.s64 + -10336;
	// addi r11,r9,-10492
	r11.s64 = ctx.r9.s64 + -10492;
	// stwx r7,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r7.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r4,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, ctx.r4.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stwx r11,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r11.u32);
	// stwx r30,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r30.u32);
	// stwx r9,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r9.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210900:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r4,r11,5508
	ctx.r4.u64 = r11.u64 | 5508;
	// ori r11,r10,5516
	r11.u64 = ctx.r10.u64 | 5516;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r3,r3,-11448
	ctx.r3.s64 = ctx.r3.s64 + -11448;
	// addi r10,r10,-10336
	ctx.r10.s64 = ctx.r10.s64 + -10336;
	// ori r9,r9,5524
	ctx.r9.u64 = ctx.r9.u64 | 5524;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lis r28,-32254
	r28.s64 = -2113798144;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// ori r8,r8,5532
	ctx.r8.u64 = ctx.r8.u64 | 5532;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// ori r7,r7,5512
	ctx.r7.u64 = ctx.r7.u64 | 5512;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5528
	ctx.r5.u64 = ctx.r5.u64 | 5528;
	// li r30,4
	r30.s64 = 4;
	// addi r28,r28,-11460
	r28.s64 = r28.s64 + -11460;
	// addi r4,r27,-11488
	ctx.r4.s64 = r27.s64 + -11488;
	// li r3,2
	ctx.r3.s64 = 2;
	// stwx r28,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r28.u32);
	// li r11,3
	r11.s64 = 3;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r30,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r30.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210988:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r4,r11,5532
	ctx.r4.u64 = r11.u64 | 5532;
	// ori r11,r10,5524
	r11.u64 = ctx.r10.u64 | 5524;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r3,r3,-10356
	ctx.r3.s64 = ctx.r3.s64 + -10356;
	// addi r10,r10,-11504
	ctx.r10.s64 = ctx.r10.s64 + -11504;
	// ori r9,r9,5516
	ctx.r9.u64 = ctx.r9.u64 | 5516;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// ori r8,r8,5508
	ctx.r8.u64 = ctx.r8.u64 | 5508;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// ori r7,r7,5528
	ctx.r7.u64 = ctx.r7.u64 | 5528;
	// ori r6,r6,5520
	ctx.r6.u64 = ctx.r6.u64 | 5520;
	// ori r5,r5,5512
	ctx.r5.u64 = ctx.r5.u64 | 5512;
	// addi r30,r30,-10492
	r30.s64 = r30.s64 + -10492;
	// addi r4,r27,-10336
	ctx.r4.s64 = r27.s64 + -10336;
	// li r3,20
	ctx.r3.s64 = 20;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// li r11,13
	r11.s64 = 13;
	// stwx r4,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// li r30,4
	r30.s64 = 4;
	// stwx r28,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210A14:
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5524
	r11.u64 = ctx.r9.u64 | 5524;
	// ori r9,r8,5512
	ctx.r9.u64 = ctx.r8.u64 | 5512;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r7,r5,-10568
	ctx.r7.s64 = ctx.r5.s64 + -10568;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stwx r28,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r28.u32);
	// addi r5,r3,-10492
	ctx.r5.s64 = ctx.r3.s64 + -10492;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r3,r10,-10336
	ctx.r3.s64 = ctx.r10.s64 + -10336;
	// li r10,25
	ctx.r10.s64 = 25;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r7,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r7.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210A7C:
	// lis r11,5
	r11.s64 = 327680;
	// stw r25,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r25.u32);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5524
	r11.u64 = ctx.r9.u64 | 5524;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// ori r9,r8,5512
	ctx.r9.u64 = ctx.r8.u64 | 5512;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// addi r7,r5,-10568
	ctx.r7.s64 = ctx.r5.s64 + -10568;
	// addi r5,r3,-10492
	ctx.r5.s64 = ctx.r3.s64 + -10492;
	// addi r3,r10,-10336
	ctx.r3.s64 = ctx.r10.s64 + -10336;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r28,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r28.u32);
	// stwx r10,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210AE0:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5524
	r11.u64 = ctx.r9.u64 | 5524;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// ori r9,r8,5512
	ctx.r9.u64 = ctx.r8.u64 | 5512;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// addi r7,r5,-10492
	ctx.r7.s64 = ctx.r5.s64 + -10492;
	// addi r5,r3,-10336
	ctx.r5.s64 = ctx.r3.s64 + -10336;
	// addi r3,r10,-11520
	ctx.r3.s64 = ctx.r10.s64 + -11520;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// stwx r30,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r30.u32);
	// stwx r10,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210B44:
	// lis r11,5
	r11.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5524
	ctx.r6.u64 = r11.u64 | 5524;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5508
	r11.u64 = ctx.r9.u64 | 5508;
	// ori r9,r8,5520
	ctx.r9.u64 = ctx.r8.u64 | 5520;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// ori r8,r7,5512
	ctx.r8.u64 = ctx.r7.u64 | 5512;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r7,r5,-11080
	ctx.r7.s64 = ctx.r5.s64 + -11080;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r5,r3,-11108
	ctx.r5.s64 = ctx.r3.s64 + -11108;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r3,r10,-10644
	ctx.r3.s64 = ctx.r10.s64 + -10644;
	// li r30,3
	r30.s64 = 3;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r10,19
	ctx.r10.s64 = 19;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stwx r30,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r30.u32);
	// stwx r10,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210BAC:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5516
	ctx.r8.u64 = r11.u64 | 5516;
	// ori r6,r10,5508
	ctx.r6.u64 = ctx.r10.u64 | 5508;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-11108
	ctx.r3.s64 = ctx.r7.s64 + -11108;
	// addi r11,r5,-11536
	r11.s64 = ctx.r5.s64 + -11536;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r10,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210BF0:
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r11,5516
	ctx.r8.u64 = r11.u64 | 5516;
	// ori r6,r10,5508
	ctx.r6.u64 = ctx.r10.u64 | 5508;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r9,5512
	ctx.r4.u64 = ctx.r9.u64 | 5512;
	// li r30,2
	r30.s64 = 2;
	// addi r3,r7,-11080
	ctx.r3.s64 = ctx.r7.s64 + -11080;
	// addi r11,r5,-10644
	r11.s64 = ctx.r5.s64 + -10644;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// li r10,19
	ctx.r10.s64 = 19;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// stwx r10,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r10.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210C34:
	// lis r11,5
	r11.s64 = 327680;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r6,r11,5508
	ctx.r6.u64 = r11.u64 | 5508;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r11,r9,5524
	r11.u64 = ctx.r9.u64 | 5524;
	// ori r9,r8,5512
	ctx.r9.u64 = ctx.r8.u64 | 5512;
	// ori r4,r10,5516
	ctx.r4.u64 = ctx.r10.u64 | 5516;
	// ori r8,r7,5520
	ctx.r8.u64 = ctx.r7.u64 | 5520;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r7,r5,-10492
	ctx.r7.s64 = ctx.r5.s64 + -10492;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r5,r3,-11548
	ctx.r5.s64 = ctx.r3.s64 + -11548;
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r3,r10,-11572
	ctx.r3.s64 = ctx.r10.s64 + -11572;
	// li r10,2
	ctx.r10.s64 = 2;
	// stwx r5,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r5.u32);
	// li r7,10
	ctx.r7.s64 = 10;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// li r30,3
	r30.s64 = 3;
	// stwx r10,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// stwx r7,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r7.u32);
	// b 0x82210ca0
	goto loc_82210CA0;
loc_82210C9C:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_82210CA0:
	// addis r31,r31,5
	r31.s64 = r31.s64 + 327680;
	// lwz r4,56(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// addi r31,r31,5280
	r31.s64 = r31.s64 + 5280;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82210CC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8262ffe0
	ctx.lr = 0x82210CD0;
	sub_8262FFE0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82210CE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplw cr6,r23,r21
	cr6.compare<uint32_t>(r23.u32, r21.u32, xer);
	// bne cr6,0x82210d0c
	if (!cr6.eq) goto loc_82210D0C;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,56(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 56);
	// bl 0x825ee230
	ctx.lr = 0x82210CFC;
	sub_825EE230(ctx, base);
	// lbz r5,81(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lwz r3,56(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 56);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// b 0x82210d1c
	goto loc_82210D1C;
loc_82210D0C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82210d20
	if (cr6.eq) goto loc_82210D20;
	// lwz r3,56(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
loc_82210D1C:
	// bl 0x825ee230
	ctx.lr = 0x82210D20;
	sub_825EE230(ctx, base);
loc_82210D20:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x82210D2C;
	sub_823058F8(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82210D34"))) PPC_WEAK_FUNC(sub_82210D34);
PPC_FUNC_IMPL(__imp__sub_82210D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82210D38"))) PPC_WEAK_FUNC(sub_82210D38);
PPC_FUNC_IMPL(__imp__sub_82210D38) {
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
	// lwz r3,68(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82210D60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x822031a8
	ctx.lr = 0x82210D64;
	sub_822031A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8220f040
	ctx.lr = 0x82210D70;
	sub_8220F040(ctx, base);
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

__attribute__((alias("__imp__sub_82210D84"))) PPC_WEAK_FUNC(sub_82210D84);
PPC_FUNC_IMPL(__imp__sub_82210D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82210D88"))) PPC_WEAK_FUNC(sub_82210D88);
PPC_FUNC_IMPL(__imp__sub_82210D88) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82210D90;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,68(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// addis r26,r31,5
	r26.s64 = r31.s64 + 327680;
	// addi r26,r26,4660
	r26.s64 = r26.s64 + 4660;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82210DB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x822031a8
	ctx.lr = 0x82210DB8;
	sub_822031A8(ctx, base);
	// addi r11,r3,-4
	r11.s64 = ctx.r3.s64 + -4;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bgt cr6,0x82211130
	if (cr6.gt) goto loc_82211130;
	// lis r12,-32223
	r12.s64 = -2111766528;
	// addi r12,r12,3548
	r12.s64 = r12.s64 + 3548;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82210E04;
	case 1:
		goto loc_82210EA0;
	case 2:
		goto loc_82211130;
	case 3:
		goto loc_82211130;
	case 4:
		goto loc_82211130;
	case 5:
		goto loc_82211130;
	case 6:
		goto loc_82211130;
	case 7:
		goto loc_82211004;
	case 8:
		goto loc_8221103C;
	case 9:
		goto loc_822110D8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,3588(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3588);
	// lwz r17,3744(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3744);
	// lwz r17,4400(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 4400);
	// lwz r17,4400(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 4400);
	// lwz r17,4400(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 4400);
	// lwz r17,4400(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 4400);
	// lwz r17,4400(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 4400);
	// lwz r17,4100(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 4100);
	// lwz r17,4156(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 4156);
	// lwz r17,4312(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 4312);
loc_82210E04:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82210E18;
	sub_821F9FB8(ctx, base);
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r31,r31,16256
	r31.s64 = r31.s64 + 16256;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,56(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x82641cb0
	ctx.lr = 0x82210E34;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82210E44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82211128
	if (!cr6.eq) goto loc_82211128;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82210E5C;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82210E70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82210E7C;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82210E90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82210EA0:
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r28,r28,16256
	r28.s64 = r28.s64 + 16256;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82210EB4;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82210EC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82211128
	if (!cr6.eq) goto loc_82211128;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82210EDC;
	sub_822A39C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r9,-18768
	ctx.r4.s64 = ctx.r9.s64 + -18768;
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82210EF4;
	sub_821F9FB8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lwz r29,56(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// bl 0x8238f6b0
	ctx.lr = 0x82210F04;
	sub_8238F6B0(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,-27856(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82210F14;
	sub_8238EC00(ctx, base);
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r5,-11120
	ctx.r4.s64 = ctx.r5.s64 + -11120;
	// lwz r3,-24180(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x82210F2C;
	sub_8220EEA8(ctx, base);
	// addi r31,r3,92
	r31.s64 = ctx.r3.s64 + 92;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823895f8
	ctx.lr = 0x82210F40;
	sub_823895F8(ctx, base);
	// lwz r4,32(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// lwz r30,128(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// bgt cr6,0x82210fe8
	if (cr6.gt) goto loc_82210FE8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82210F60;
	sub_821E6800(ctx, base);
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82210F6C;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82210F80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82210F8C;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r7,788(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 788);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82210FA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bgt cr6,0x82210fac
	if (cr6.gt) goto loc_82210FAC;
	// li r30,-1
	r30.s64 = -1;
loc_82210FAC:
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82210FB8;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,692(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82210FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82210FE8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82210FF4;
	sub_821E6800(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82211004:
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// li r4,73
	ctx.r4.s64 = 73;
	// addi r31,r31,16256
	r31.s64 = r31.s64 + 16256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82211018;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211028;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82211128
	if (!cr6.eq) goto loc_82211128;
	// li r4,73
	ctx.r4.s64 = 73;
	// b 0x8221110c
	goto loc_8221110C;
loc_8221103C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82211050;
	sub_821F9FB8(ctx, base);
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r31,r31,16256
	r31.s64 = r31.s64 + 16256;
	// li r4,74
	ctx.r4.s64 = 74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,56(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x82641cb0
	ctx.lr = 0x8221106C;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8221107C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82211128
	if (!cr6.eq) goto loc_82211128;
	// li r4,74
	ctx.r4.s64 = 74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82211094;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822110A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,74
	ctx.r4.s64 = 74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822110B4;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822110C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_822110D8:
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// li r4,75
	ctx.r4.s64 = 75;
	// addi r31,r31,16256
	r31.s64 = r31.s64 + 16256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822110EC;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822110FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82211128
	if (!cr6.eq) goto loc_82211128;
	// li r4,75
	ctx.r4.s64 = 75;
loc_8221110C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82211114;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82211128:
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
loc_82211130:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82211138"))) PPC_WEAK_FUNC(sub_82211138);
PPC_FUNC_IMPL(__imp__sub_82211138) {
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
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8221118c
	if (cr6.eq) goto loc_8221118C;
	// rlwinm r11,r4,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r10,-10180
	ctx.r3.s64 = ctx.r10.s64 + -10180;
	// addis r31,r9,1
	r31.s64 = ctx.r9.s64 + 65536;
	// addi r31,r31,6256
	r31.s64 = r31.s64 + 6256;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x82211174;
	sub_82130000(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stb r8,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r8.u8);
	// addi r3,r7,-10208
	ctx.r3.s64 = ctx.r7.s64 + -10208;
	// bl 0x821e6800
	ctx.lr = 0x82211188;
	sub_821E6800(ctx, base);
	// b 0x822111f8
	goto loc_822111F8;
loc_8221118C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r31,r11,-21500
	r31.s64 = r11.s64 + -21500;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-11120
	ctx.r4.s64 = ctx.r9.s64 + -11120;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r30,-24180(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x822111B4;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x822111C8;
	sub_821FD7C0(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lwz r7,308(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// lwz r6,10248(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r8,-10244
	ctx.r3.s64 = ctx.r8.s64 + -10244;
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// addi r4,r7,92
	ctx.r4.s64 = ctx.r7.s64 + 92;
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// stw r6,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x822111F8;
	sub_82130000(ctx, base);
loc_822111F8:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
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

__attribute__((alias("__imp__sub_82211210"))) PPC_WEAK_FUNC(sub_82211210);
PPC_FUNC_IMPL(__imp__sub_82211210) {
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
	ctx.lr = 0x82211218;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-11120
	ctx.r4.s64 = ctx.r9.s64 + -11120;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x82211248;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x8221125C;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82211290
	if (!cr6.eq) goto loc_82211290;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_82211290:
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822042b0
	ctx.lr = 0x8221129C;
	sub_822042B0(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822112A4"))) PPC_WEAK_FUNC(sub_822112A4);
PPC_FUNC_IMPL(__imp__sub_822112A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822112A8"))) PPC_WEAK_FUNC(sub_822112A8);
PPC_FUNC_IMPL(__imp__sub_822112A8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x822112B0;
	// stfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822112D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// li r15,0
	r15.s64 = 0;
	// ori r22,r8,16256
	r22.u64 = ctx.r8.u64 | 16256;
	// lis r20,-32111
	r20.s64 = -2104426496;
	// li r18,1
	r18.s64 = 1;
	// lis r21,-32121
	r21.s64 = -2105081856;
	// lis r19,-32121
	r19.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822119ec
	if (cr6.eq) goto loc_822119EC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8221130C;
	sub_822A3998(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r30,48(r23)
	r30.u64 = PPC_LOAD_U32(r23.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221132C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x82211334;
	sub_82256058(ctx, base);
	// add r25,r31,r22
	r25.u64 = r31.u64 + r22.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,109
	ctx.r4.s64 = 109;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82211348;
	sub_82641CB0(ctx, base);
	// cntlzw r9,r28
	ctx.r9.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r7,5268(r29)
	PPC_STORE_U8(r29.u32 + 5268, ctx.r7.u8);
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// lwz r3,692(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 692);
	// lbz r5,240(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 240);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// rlwimi r4,r6,2,29,29
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r6.u32, 2) & 0x4) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFFB);
	// rlwinm r11,r5,30,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x1;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r9,r10,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// stb r10,240(r3)
	PPC_STORE_U8(ctx.r3.u32 + 240, ctx.r10.u8);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x82211398
	if (cr6.eq) goto loc_82211398;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82211398:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// beq cr6,0x82211628
	if (cr6.eq) goto loc_82211628;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82256028
	ctx.lr = 0x822113B0;
	sub_82256028(ctx, base);
	// lwz r11,3100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3100);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r27,r15
	r27.u64 = r15.u64;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82211420
	if (cr6.eq) goto loc_82211420;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// beq cr6,0x82211420
	if (cr6.eq) goto loc_82211420;
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bne cr6,0x82211424
	if (!cr6.eq) goto loc_82211424;
	// addi r29,r29,2400
	r29.s64 = r29.s64 + 2400;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822113EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82211424
	if (cr6.eq) goto loc_82211424;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x822a8678
	ctx.lr = 0x82211400;
	sub_822A8678(ctx, base);
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a86a8
	ctx.lr = 0x8221140C;
	sub_822A86A8(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// ble cr6,0x82211424
	if (!cr6.gt) goto loc_82211424;
	// fdivs f0,f31,f1
	f0.f64 = double(float(f31.f64 / ctx.f1.f64));
	// stfs f0,192(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 192, temp.u32);
	// b 0x82211424
	goto loc_82211424;
loc_82211420:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_82211424:
	// lwz r11,3100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3100);
	// li r4,109
	ctx.r4.s64 = 109;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,696(r31)
	PPC_STORE_U8(r31.u32 + 696, ctx.r9.u8);
	// lwz r11,3104(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3104);
	// addi r8,r11,-11
	ctx.r8.s64 = r11.s64 + -11;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r6,697(r31)
	PPC_STORE_U8(r31.u32 + 697, ctx.r6.u8);
	// bl 0x82641cb0
	ctx.lr = 0x82211458;
	sub_82641CB0(ctx, base);
	// addi r3,r3,1600
	ctx.r3.s64 = ctx.r3.s64 + 1600;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,644(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 644);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82211484
	if (cr6.eq) goto loc_82211484;
	// mr r27,r18
	r27.u64 = r18.u64;
loc_82211484:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822115f0
	if (cr6.eq) goto loc_822115F0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82256150
	ctx.lr = 0x82211498;
	sub_82256150(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,109
	ctx.r4.s64 = 109;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822114A8;
	sub_82641CB0(ctx, base);
	// addi r3,r3,1600
	ctx.r3.s64 = ctx.r3.s64 + 1600;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,624(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 624);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822114C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// subf r26,r26,r29
	r26.s64 = r29.s64 - r26.s64;
	// bl 0x82256030
	ctx.lr = 0x822114D0;
	sub_82256030(ctx, base);
	// subf r29,r3,r29
	r29.s64 = r29.s64 - ctx.r3.s64;
	// li r4,109
	ctx.r4.s64 = 109;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822114E0;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822114F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822115f0
	if (cr6.eq) goto loc_822115F0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82204a00
	ctx.lr = 0x82211504;
	sub_82204A00(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822115f0
	if (cr6.eq) goto loc_822115F0;
	// lbz r11,3764(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 3764);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822115f0
	if (cr6.eq) goto loc_822115F0;
	// cmpwi cr6,r26,20000
	cr6.compare<int32_t>(r26.s32, 20000, xer);
	// bge cr6,0x822115f0
	if (!cr6.lt) goto loc_822115F0;
	// cmpw cr6,r26,r29
	cr6.compare<int32_t>(r26.s32, r29.s32, xer);
	// beq cr6,0x822115f0
	if (cr6.eq) goto loc_822115F0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x822115f0
	if (!cr6.gt) goto loc_822115F0;
	// addis r4,r31,5
	ctx.r4.s64 = r31.s64 + 327680;
	// addi r4,r4,5204
	ctx.r4.s64 = ctx.r4.s64 + 5204;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82211564
	if (!cr6.eq) goto loc_82211564;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10012
	ctx.r3.s64 = r11.s64 + -10012;
	// bl 0x821e6810
	ctx.lr = 0x82211564;
	sub_821E6810(ctx, base);
loc_82211564:
	// cmpwi cr6,r26,10000
	cr6.compare<int32_t>(r26.s32, 10000, xer);
	// bgt cr6,0x8221160c
	if (cr6.gt) goto loc_8221160C;
	// li r11,1000
	r11.s64 = 1000;
	// divw r10,r29,r11
	ctx.r10.s32 = r29.s32 / r11.s32;
	// divw r9,r26,r11
	ctx.r9.s32 = r26.s32 / r11.s32;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x8221160c
	if (cr6.eq) goto loc_8221160C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10044
	ctx.r3.s64 = r11.s64 + -10044;
	// bl 0x821e6800
	ctx.lr = 0x8221158C;
	sub_821E6800(ctx, base);
	// cmpwi cr6,r29,10000
	cr6.compare<int32_t>(r29.s32, 10000, xer);
	// ble cr6,0x8221160c
	if (!cr6.gt) goto loc_8221160C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822115b8
	if (cr6.eq) goto loc_822115B8;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r18
	r11.u64 = r18.u64;
	// bne cr6,0x822115bc
	if (!cr6.eq) goto loc_822115BC;
loc_822115B8:
	// mr r11,r15
	r11.u64 = r15.u64;
loc_822115BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221160c
	if (!cr6.eq) goto loc_8221160C;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r6,r10,3998
	ctx.r6.s64 = ctx.r10.s64 + 3998;
	// addi r5,r9,-10052
	ctx.r5.s64 = ctx.r9.s64 + -10052;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// addi r4,r8,-10080
	ctx.r4.s64 = ctx.r8.s64 + -10080;
	// bl 0x821f3628
	ctx.lr = 0x822115EC;
	sub_821F3628(ctx, base);
	// b 0x8221160c
	goto loc_8221160C;
loc_822115F0:
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,5204
	ctx.r10.u64 = r11.u64 | 5204;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8221160c
	if (cr6.eq) goto loc_8221160C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8221160C;
	sub_8213C218(ctx, base);
loc_8221160C:
	// li r4,109
	ctx.r4.s64 = 109;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82211618;
	sub_82641CB0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r3,1600
	ctx.r3.s64 = ctx.r3.s64 + 1600;
	// bl 0x8264e998
	ctx.lr = 0x82211624;
	sub_8264E998(ctx, base);
	// b 0x82211644
	goto loc_82211644;
loc_82211628:
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,5204
	ctx.r10.u64 = r11.u64 | 5204;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82211644
	if (cr6.eq) goto loc_82211644;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x82211644;
	sub_8213C218(ctx, base);
loc_82211644:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82211658
	if (cr6.eq) goto loc_82211658;
	// stb r18,696(r31)
	PPC_STORE_U8(r31.u32 + 696, r18.u8);
loc_82211658:
	// bl 0x82387a18
	ctx.lr = 0x8221165C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82211690
	if (cr6.eq) goto loc_82211690;
	// lwz r11,-10236(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r22
	ctx.r3.u64 = r11.u64 + r22.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8221167C;
	sub_82641CB0(ctx, base);
	// addi r3,r3,1600
	ctx.r3.s64 = ctx.r3.s64 + 1600;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,608(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 608);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82211690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82211690:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822119c4
	if (cr6.eq) goto loc_822119C4;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// ori r9,r10,5252
	ctx.r9.u64 = ctx.r10.u64 | 5252;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// lwzx r7,r31,r9
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// lfs f13,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f12,0(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// beq cr6,0x822117c0
	if (cr6.eq) goto loc_822117C0;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822117c0
	if (cr6.eq) goto loc_822117C0;
	// addi r29,r11,-16
	r29.s64 = r11.s64 + -16;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822117c0
	if (cr6.eq) goto loc_822117C0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10028);
	// add r3,r11,r22
	ctx.r3.u64 = r11.u64 + r22.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822116F0;
	sub_82641CB0(ctx, base);
	// addi r11,r3,2192
	r11.s64 = ctx.r3.s64 + 2192;
	// lfs f10,196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 196);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f30
	cr6.compare(ctx.f10.f64, f30.f64);
	// ble cr6,0x822117c0
	if (!cr6.gt) goto loc_822117C0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,4120(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8221171c
	if (!cr6.gt) goto loc_8221171C;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// b 0x82211720
	goto loc_82211720;
loc_8221171C:
	// fmr f11,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f13.f64;
loc_82211720:
	// lfs f12,4112(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x82211730
	if (!cr6.gt) goto loc_82211730;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
loc_82211730:
	// lfs f13,4116(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82211740
	if (!cr6.gt) goto loc_82211740;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_82211740:
	// fadds f9,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,32688(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32688);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32664(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32664);
	ctx.f12.f64 = double(temp.f32);
	// fadds f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// fmuls f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fdivs f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 / ctx.f10.f64));
	// fsel f5,f6,f6,f30
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : f30.f64;
	// fsubs f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsel f3,f4,f0,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? f0.f64 : ctx.f5.f64;
	// stfs f3,192(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 192, temp.u32);
	// fcmpu cr6,f3,f12
	cr6.compare(ctx.f3.f64, ctx.f12.f64);
	// blt cr6,0x822117a0
	if (cr6.lt) goto loc_822117A0;
	// lbz r10,204(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 204);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822117a0
	if (!cr6.eq) goto loc_822117A0;
	// stb r18,204(r11)
	PPC_STORE_U8(r11.u32 + 204, r18.u8);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10096
	ctx.r3.s64 = r11.s64 + -10096;
	// bl 0x821fa358
	ctx.lr = 0x82211794;
	sub_821FA358(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r3,-10432(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10432);
	// bl 0x823261e8
	ctx.lr = 0x822117A0;
	sub_823261E8(ctx, base);
loc_822117A0:
	// lwz r11,-10028(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10028);
	// li r4,109
	ctx.r4.s64 = 109;
	// add r3,r11,r22
	ctx.r3.u64 = r11.u64 + r22.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822117B0;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822117C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822117C0:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r10,5256
	ctx.r8.u64 = ctx.r10.u64 | 5256;
	// ori r7,r9,5260
	ctx.r7.u64 = ctx.r9.u64 | 5260;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// ori r5,r6,5268
	ctx.r5.u64 = ctx.r6.u64 | 5268;
	// lwzx r4,r31,r8
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
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
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// stfs f8,0(r4)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r11,r31,r7
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwz r10,104(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// lfs f7,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwzx r7,r31,r5
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	// lfs f6,204(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 204);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,0(r7)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// bl 0x82387a18
	ctx.lr = 0x82211830;
	sub_82387A18(ctx, base);
	// lis r6,5
	ctx.r6.s64 = 327680;
	// ori r5,r6,5244
	ctx.r5.u64 = ctx.r6.u64 | 5244;
	// lwzx r4,r31,r5
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	// stb r3,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r3.u8);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822a5578
	ctx.lr = 0x82211848;
	sub_822A5578(ctx, base);
	// lis r11,5
	r11.s64 = 327680;
	// lbz r10,102(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 102);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// ori r8,r11,5248
	ctx.r8.u64 = r11.u64 | 5248;
	// lwzx r7,r31,r8
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// stb r10,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, ctx.r10.u8);
	// lwz r3,-7572(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x82211868;
	sub_82205248(ctx, base);
	// lis r6,5
	ctx.r6.s64 = 327680;
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// ori r3,r6,5240
	ctx.r3.u64 = ctx.r6.u64 | 5240;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r4,r10,-17592
	ctx.r4.s64 = ctx.r10.s64 + -17592;
	// lwzx r8,r31,r3
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r3,-24180(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + -24180);
	// lwz r11,128(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 128);
	// lfs f5,272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,276(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 276);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f3,f3
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f3.f64));
	// fmadds f1,f5,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fmadds f0,f4,f4,f1
	f0.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f1.f64));
	// fsqrts f1,f0
	ctx.f1.f64 = double(float(sqrt(f0.f64)));
	// bl 0x821fde10
	ctx.lr = 0x822118BC;
	sub_821FDE10(ctx, base);
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r3,84(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 84);
	// lwz r4,16(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// lwz r11,60(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x8223ff00
	ctx.lr = 0x822118D8;
	sub_8223FF00(ctx, base);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r8,96(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 96);
	// addi r4,r10,-13452
	ctx.r4.s64 = ctx.r10.s64 + -13452;
	// lwz r7,664(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 664);
	// lhz r6,18(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 18);
	// lfs f13,28(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// std r3,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r3.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// fadds f1,f10,f13
	ctx.f1.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// bl 0x825ee188
	ctx.lr = 0x82211914;
	sub_825EE188(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r4,109
	ctx.r4.s64 = 109;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// lfs f31,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	f31.f64 = double(temp.f32);
	// bl 0x82641cb0
	ctx.lr = 0x8221192C;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3648
	ctx.r3.s64 = ctx.r3.s64 + 3648;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8223fd98
	ctx.lr = 0x82211938;
	sub_8223FD98(ctx, base);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwz r8,236(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 236);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822119a4
	if (!cr6.eq) goto loc_822119A4;
	// lwz r29,72(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82211968
	if (cr6.eq) goto loc_82211968;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82337a48
	ctx.lr = 0x8221195C;
	sub_82337A48(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bne cr6,0x8221196c
	if (!cr6.eq) goto loc_8221196C;
loc_82211968:
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
loc_8221196C:
	// lwz r3,100(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 100);
	// bl 0x8223fcd8
	ctx.lr = 0x82211974;
	sub_8223FCD8(ctx, base);
	// lfs f1,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,100(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 100);
	// bl 0x8223fcf8
	ctx.lr = 0x82211980;
	sub_8223FCF8(ctx, base);
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r3,100(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 100);
	// bl 0x8223fd08
	ctx.lr = 0x8221198C;
	sub_8223FD08(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r29,100(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 100);
	// bl 0x82337a48
	ctx.lr = 0x82211998;
	sub_82337A48(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8223fd18
	ctx.lr = 0x822119A4;
	sub_8223FD18(ctx, base);
loc_822119A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,112(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 112);
	// lwz r4,68(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x82203ac8
	ctx.lr = 0x822119B4;
	sub_82203AC8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,3568
	ctx.r3.s64 = ctx.r3.s64 + 3568;
	// bl 0x8223d450
	ctx.lr = 0x822119C0;
	sub_8223D450(ctx, base);
	// b 0x82211a08
	goto loc_82211A08;
loc_822119C4:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,100(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 100);
	// bl 0x8223fcd8
	ctx.lr = 0x822119D0;
	sub_8223FCD8(ctx, base);
	// lwz r11,112(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 112);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,3568
	ctx.r3.s64 = ctx.r3.s64 + 3568;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r15,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r15.u32);
	// bl 0x8223d450
	ctx.lr = 0x822119E8;
	sub_8223D450(ctx, base);
	// b 0x82211a08
	goto loc_82211A08;
loc_822119EC:
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,5204
	ctx.r10.u64 = r11.u64 | 5204;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82211a08
	if (cr6.eq) goto loc_82211A08;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x82211A08;
	sub_8213C218(ctx, base);
loc_82211A08:
	// bl 0x82256058
	ctx.lr = 0x82211A0C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82211a30
	if (cr6.eq) goto loc_82211A30;
	// bl 0x82256058
	ctx.lr = 0x82211A18;
	sub_82256058(ctx, base);
	// lwz r11,3104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3104);
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x82211a30
	if (cr6.eq) goto loc_82211A30;
	// bl 0x82256058
	ctx.lr = 0x82211A28;
	sub_82256058(ctx, base);
	// lwz r27,8(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x82211a34
	goto loc_82211A34;
loc_82211A30:
	// li r27,-1
	r27.s64 = -1;
loc_82211A34:
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// bl 0x82256058
	ctx.lr = 0x82211A3C;
	sub_82256058(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82211a74
	if (cr6.eq) goto loc_82211A74;
	// lbz r11,3764(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 3764);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82211a74
	if (cr6.eq) goto loc_82211A74;
	// bl 0x82256028
	ctx.lr = 0x82211A58;
	sub_82256028(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82211a74
	if (!cr6.lt) goto loc_82211A74;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82256028
	ctx.lr = 0x82211A68;
	sub_82256028(ctx, base);
	// cmpwi cr6,r3,-3000
	cr6.compare<int32_t>(ctx.r3.s32, -3000, xer);
	// mr r29,r18
	r29.u64 = r18.u64;
	// bge cr6,0x82211a78
	if (!cr6.lt) goto loc_82211A78;
loc_82211A74:
	// mr r29,r15
	r29.u64 = r15.u64;
loc_82211A78:
	// lwz r11,-10236(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r29.u8);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,692(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// clrlwi r29,r29,24
	r29.u64 = r29.u32 & 0xFF;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// lbz r9,240(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 240);
	// rlwinm r8,r9,29,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1;
	// cmplw cr6,r8,r29
	cr6.compare<uint32_t>(ctx.r8.u32, r29.u32, xer);
	// beq cr6,0x82211ad4
	if (cr6.eq) goto loc_82211AD4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211AC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,240(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 240);
	// rlwimi r9,r29,3,28,28
	ctx.r9.u64 = (__builtin_rotateleft32(r29.u32, 3) & 0x8) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFF7);
	// stb r9,240(r30)
	PPC_STORE_U8(r30.u32 + 240, ctx.r9.u8);
loc_82211AD4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10116
	ctx.r3.s64 = r11.s64 + -10116;
	// bl 0x821fa230
	ctx.lr = 0x82211AE0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82211AF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82211b28
	if (!cr6.eq) goto loc_82211B28;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10132
	ctx.r3.s64 = r11.s64 + -10132;
	// bl 0x821fa230
	ctx.lr = 0x82211B08;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82211B18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r11,r15
	r11.u64 = r15.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82211b2c
	if (cr6.eq) goto loc_82211B2C;
loc_82211B28:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_82211B2C:
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// bl 0x82256058
	ctx.lr = 0x82211B34;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82211b4c
	if (cr6.eq) goto loc_82211B4C;
	// lwz r11,3104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3104);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mr r11,r18
	r11.u64 = r18.u64;
	// bgt cr6,0x82211b50
	if (cr6.gt) goto loc_82211B50;
loc_82211B4C:
	// mr r11,r15
	r11.u64 = r15.u64;
loc_82211B50:
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// stb r28,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, r28.u8);
	// bl 0x8264e598
	ctx.lr = 0x82211B5C;
	sub_8264E598(ctx, base);
	// stb r3,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r3.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822090b8
	ctx.lr = 0x82211B68;
	sub_822090B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82211bac
	if (cr6.eq) goto loc_82211BAC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82211b98
	if (cr6.eq) goto loc_82211B98;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r18
	r11.u64 = r18.u64;
	// beq cr6,0x82211b9c
	if (cr6.eq) goto loc_82211B9C;
loc_82211B98:
	// mr r11,r15
	r11.u64 = r15.u64;
loc_82211B9C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r15
	r11.u64 = r15.u64;
	// beq cr6,0x82211bb0
	if (cr6.eq) goto loc_82211BB0;
loc_82211BAC:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_82211BB0:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stb r11,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r11.u8);
	// addi r3,r10,-13240
	ctx.r3.s64 = ctx.r10.s64 + -13240;
	// bl 0x821fa230
	ctx.lr = 0x82211BC0;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,312(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 312);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82211BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r3,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r3.u8);
	// add r3,r31,r22
	ctx.r3.u64 = r31.u64 + r22.u64;
	// li r4,109
	ctx.r4.s64 = 109;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// bl 0x82641cb0
	ctx.lr = 0x82211BE4;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,612(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 612);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82211BF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// stb r3,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r3.u8);
	// lwz r3,-10220(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82211c48
	if (!cr6.eq) goto loc_82211C48;
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,4944
	ctx.r10.u64 = r11.u64 | 4944;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82211c48
	if (!cr6.eq) goto loc_82211C48;
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,4994
	ctx.r10.u64 = r11.u64 | 4994;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82211c4c
	if (cr6.eq) goto loc_82211C4C;
loc_82211C48:
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
loc_82211C4C:
	// lwz r11,-10236(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -10236);
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8221df70
	ctx.lr = 0x82211C5C;
	sub_8221DF70(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82211c84
	if (cr6.eq) goto loc_82211C84;
	// lwz r11,-10236(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8221df70
	ctx.lr = 0x82211C74;
	sub_8221DF70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82211c88
	if (cr6.eq) goto loc_82211C88;
loc_82211C84:
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
loc_82211C88:
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r29,-24180(r20)
	r29.u64 = PPC_LOAD_U32(r20.u32 + -24180);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stb r18,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r18.u8);
	// addi r30,r9,-21500
	r30.s64 = ctx.r9.s64 + -21500;
	// clrlwi r17,r10,24
	r17.u64 = ctx.r10.u32 & 0xFF;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// addi r4,r8,-10144
	ctx.r4.s64 = ctx.r8.s64 + -10144;
	// li r5,64
	ctx.r5.s64 = 64;
	// stb r17,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r17.u8);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x823db670
	ctx.lr = 0x82211CB8;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821fd7c0
	ctx.lr = 0x82211CCC;
	sub_821FD7C0(ctx, base);
	// lwz r11,340(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// lwz r7,10248(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r15,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, r15.u8);
	// stw r15,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, r15.u32);
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r30.u32);
	// stw r7,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r7.u32);
	// beq cr6,0x82211d04
	if (cr6.eq) goto loc_82211D04;
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stb r8,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r8.u8);
loc_82211D04:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82207068
	ctx.lr = 0x82211D0C;
	sub_82207068(ctx, base);
	// lwz r11,17268(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82211dec
	if (cr6.eq) goto loc_82211DEC;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82211d44
	if (cr6.eq) goto loc_82211D44;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82211d60
	if (!cr6.gt) goto loc_82211D60;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x82211d54
	goto loc_82211D54;
loc_82211D44:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82211d60
	if (!cr6.gt) goto loc_82211D60;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82211D54:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
	// bne cr6,0x82211d64
	if (!cr6.eq) goto loc_82211D64;
loc_82211D60:
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
loc_82211D64:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82211dec
	if (cr6.eq) goto loc_82211DEC;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x82211D7C;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// lwz r10,880(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 880);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r29,784(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 784);
	// bl 0x822a3998
	ctx.lr = 0x82211D98;
	sub_822A3998(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,880(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 880);
	// lwz r6,84(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// lwz r30,784(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 784);
	// bl 0x822a3998
	ctx.lr = 0x82211DB4;
	sub_822A3998(ctx, base);
	// lwz r5,880(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// addi r4,r30,-12
	ctx.r4.s64 = r30.s64 + -12;
	// addi r3,r29,-13
	ctx.r3.s64 = r29.s64 + -13;
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// lwz r8,84(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r11,784(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 784);
	// addi r6,r11,-11
	ctx.r6.s64 = r11.s64 + -11;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// or r3,r4,r9
	ctx.r3.u64 = ctx.r4.u64 | ctx.r9.u64;
	// or r15,r3,r7
	r15.u64 = ctx.r3.u64 | ctx.r7.u64;
loc_82211DEC:
	// clrlwi r29,r28,24
	r29.u64 = r28.u32 & 0xFF;
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r30,r11,4976
	r30.u64 = r11.u64 | 4976;
	// ori r16,r10,4981
	r16.u64 = ctx.r10.u64 | 4981;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82211e14
	if (cr6.eq) goto loc_82211E14;
	// lbzx r11,r31,r16
	r11.u64 = PPC_LOAD_U8(r31.u32 + r16.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82211e28
	if (cr6.eq) goto loc_82211E28;
loc_82211E14:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// beq cr6,0x82211e34
	if (cr6.eq) goto loc_82211E34;
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// beq cr6,0x82211e34
	if (cr6.eq) goto loc_82211E34;
loc_82211E28:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82206760
	ctx.lr = 0x82211E30;
	sub_82206760(ctx, base);
	// b 0x82211e50
	goto loc_82211E50;
loc_82211E34:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82211e50
	if (!cr6.eq) goto loc_82211E50;
	// lbzx r11,r31,r16
	r11.u64 = PPC_LOAD_U8(r31.u32 + r16.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82211e50
	if (cr6.eq) goto loc_82211E50;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82206890
	ctx.lr = 0x82211E50;
	sub_82206890(ctx, base);
loc_82211E50:
	// addis r18,r31,5
	r18.s64 = r31.s64 + 327680;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lbz r11,85(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// lis r9,5
	ctx.r9.s64 = 327680;
	// addi r18,r18,4980
	r18.s64 = r18.s64 + 4980;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// stwx r10,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r10.u32);
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lbz r5,0(r18)
	ctx.r5.u64 = PPC_LOAD_U8(r18.u32 + 0);
	// lis r3,5
	ctx.r3.s64 = 327680;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r30,5
	r30.s64 = 327680;
	// lis r28,5
	r28.s64 = 327680;
	// ori r19,r9,4982
	r19.u64 = ctx.r9.u64 | 4982;
	// ori r20,r8,4983
	r20.u64 = ctx.r8.u64 | 4983;
	// ori r21,r7,4984
	r21.u64 = ctx.r7.u64 | 4984;
	// ori r22,r6,4985
	r22.u64 = ctx.r6.u64 | 4985;
	// ori r23,r4,4986
	r23.u64 = ctx.r4.u64 | 4986;
	// ori r24,r3,4987
	r24.u64 = ctx.r3.u64 | 4987;
	// ori r25,r10,4989
	r25.u64 = ctx.r10.u64 | 4989;
	// ori r26,r30,4988
	r26.u64 = r30.u64 | 4988;
	// ori r27,r28,4991
	r27.u64 = r28.u64 | 4991;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbzx r11,r31,r16
	r11.u64 = PPC_LOAD_U8(r31.u32 + r16.u32);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbz r9,86(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbzx r10,r31,r19
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r19.u32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbzx r10,r31,r20
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r20.u32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbz r9,83(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbzx r10,r31,r21
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r21.u32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbzx r11,r31,r22
	r11.u64 = PPC_LOAD_U8(r31.u32 + r22.u32);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbzx r11,r31,r23
	r11.u64 = PPC_LOAD_U8(r31.u32 + r23.u32);
	// clrlwi r10,r14,24
	ctx.r10.u64 = r14.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbzx r10,r31,r24
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r24.u32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbzx r11,r31,r25
	r11.u64 = PPC_LOAD_U8(r31.u32 + r25.u32);
	// clrlwi r10,r17,24
	ctx.r10.u64 = r17.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbzx r11,r31,r26
	r11.u64 = PPC_LOAD_U8(r31.u32 + r26.u32);
	// clrlwi r10,r15,24
	ctx.r10.u64 = r15.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82211f58
	if (!cr6.eq) goto loc_82211F58;
	// lbz r9,81(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// li r11,0
	r11.s64 = 0;
	// lbzx r10,r31,r27
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r27.u32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82211f5c
	if (cr6.eq) goto loc_82211F5C;
loc_82211F58:
	// li r11,1
	r11.s64 = 1;
loc_82211F5C:
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// clrlwi r17,r11,24
	r17.u64 = r11.u32 & 0xFF;
	// bl 0x82641cb0
	ctx.lr = 0x82211F6C;
	sub_82641CB0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r29,2832
	r30.s64 = r29.s64 + 2832;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,2832(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 2832);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211F88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82211fc8
	if (cr6.eq) goto loc_82211FC8;
	// lwz r11,2624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 2624);
	// addi r28,r29,2624
	r28.s64 = r29.s64 + 2624;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211FAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82211fc8
	if (!cr6.eq) goto loc_82211FC8;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// b 0x82212038
	goto loc_82212038;
loc_82211FC8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82211FDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82212044
	if (!cr6.eq) goto loc_82212044;
	// lwz r11,2624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 2624);
	// addi r30,r29,2624
	r30.s64 = r29.s64 + 2624;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82212000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82212044
	if (cr6.eq) goto loc_82212044;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-11876
	ctx.r4.s64 = ctx.r10.s64 + -11876;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82212020;
	sub_821F9FB8(ctx, base);
	// lbz r9,68(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 68);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82212044
	if (!cr6.eq) goto loc_82212044;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82212038:
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82212044;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82212044:
	// clrlwi r11,r17,24
	r11.u64 = r17.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221206c
	if (cr6.eq) goto loc_8221206C;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8221206c
	if (!cr6.eq) goto loc_8221206C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82207190
	ctx.lr = 0x8221206C;
	sub_82207190(ctx, base);
loc_8221206C:
	// lbz r10,87(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82212094
	if (cr6.eq) goto loc_82212094;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82641cb0
	ctx.lr = 0x82212084;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82212094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82212094:
	// lbz r11,85(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// lbz r10,89(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// lbz r9,86(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r7,83(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// lbz r3,81(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// stb r11,0(r18)
	PPC_STORE_U8(r18.u32 + 0, r11.u8);
	// stbx r10,r31,r16
	PPC_STORE_U8(r31.u32 + r16.u32, ctx.r10.u8);
	// stbx r9,r31,r19
	PPC_STORE_U8(r31.u32 + r19.u32, ctx.r9.u8);
	// stbx r8,r31,r20
	PPC_STORE_U8(r31.u32 + r20.u32, ctx.r8.u8);
	// stbx r7,r31,r21
	PPC_STORE_U8(r31.u32 + r21.u32, ctx.r7.u8);
	// stbx r6,r31,r22
	PPC_STORE_U8(r31.u32 + r22.u32, ctx.r6.u8);
	// stbx r14,r31,r23
	PPC_STORE_U8(r31.u32 + r23.u32, r14.u8);
	// stbx r5,r31,r24
	PPC_STORE_U8(r31.u32 + r24.u32, ctx.r5.u8);
	// stbx r15,r31,r26
	PPC_STORE_U8(r31.u32 + r26.u32, r15.u8);
	// stbx r4,r31,r25
	PPC_STORE_U8(r31.u32 + r25.u32, ctx.r4.u8);
	// stbx r3,r31,r27
	PPC_STORE_U8(r31.u32 + r27.u32, ctx.r3.u8);
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_822120F4"))) PPC_WEAK_FUNC(sub_822120F4);
PPC_FUNC_IMPL(__imp__sub_822120F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822120F8"))) PPC_WEAK_FUNC(sub_822120F8);
PPC_FUNC_IMPL(__imp__sub_822120F8) {
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
	ctx.lr = 0x82212100;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,-24180(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x826947a0
	ctx.lr = 0x8221211C;
	sub_826947A0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826947a0
	ctx.lr = 0x8221212C;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8220ef00
	ctx.lr = 0x8221213C;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x82212150;
	sub_823DB670(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82212160"))) PPC_WEAK_FUNC(sub_82212160);
PPC_FUNC_IMPL(__imp__sub_82212160) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,-24180(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x826947a0
	ctx.lr = 0x82212190;
	sub_826947A0(ctx, base);
	// bl 0x823de058
	ctx.lr = 0x82212194;
	sub_823DE058(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// bl 0x826947a0
	ctx.lr = 0x822121A4;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x821fd878
	ctx.lr = 0x822121B4;
	sub_821FD878(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r10,9792
	ctx.r4.s64 = ctx.r10.s64 + 9792;
	// bl 0x823dc018
	ctx.lr = 0x822121D4;
	sub_823DC018(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f31,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822121FC"))) PPC_WEAK_FUNC(sub_822121FC);
PPC_FUNC_IMPL(__imp__sub_822121FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82212200"))) PPC_WEAK_FUNC(sub_82212200);
PPC_FUNC_IMPL(__imp__sub_82212200) {
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
	ctx.lr = 0x82212208;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82211210
	ctx.lr = 0x82212218;
	sub_82211210(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82212280
	if (cr6.eq) goto loc_82212280;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// rlwinm r11,r29,6,0,25
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 6) & 0xFFFFFFC0;
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// lwz r31,-10244(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// addis r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 65536;
	// addi r4,r4,6256
	ctx.r4.s64 = ctx.r4.s64 + 6256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x82212248;
	sub_82218310(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,-9948
	ctx.r4.s64 = ctx.r8.s64 + -9948;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822183b0
	ctx.lr = 0x8221225C;
	sub_822183B0(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r5,-9984
	ctx.r5.s64 = ctx.r5.s64 + -9984;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f1,3732(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82234d88
	ctx.lr = 0x82212280;
	sub_82234D88(ctx, base);
loc_82212280:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82211138
	ctx.lr = 0x8221228C;
	sub_82211138(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82212294"))) PPC_WEAK_FUNC(sub_82212294);
PPC_FUNC_IMPL(__imp__sub_82212294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82212298"))) PPC_WEAK_FUNC(sub_82212298);
PPC_FUNC_IMPL(__imp__sub_82212298) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822122A0;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addis r31,r30,1
	r31.s64 = r30.s64 + 65536;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r31,r31,3908
	r31.s64 = r31.s64 + 3908;
	// li r26,0
	r26.s64 = 0;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82212304
	if (cr6.eq) goto loc_82212304;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a5948
	ctx.lr = 0x822122DC;
	sub_822A5948(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82212304
	if (!cr6.eq) goto loc_82212304;
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r9,r11,3600
	ctx.r9.u64 = r11.u64 | 3600;
	// addi r4,r10,-13336
	ctx.r4.s64 = ctx.r10.s64 + -13336;
	// lwzx r3,r30,r9
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// bl 0x82696c88
	ctx.lr = 0x82212300;
	sub_82696C88(ctx, base);
	// stb r26,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r26.u8);
loc_82212304:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82212318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822125cc
	if (cr6.eq) goto loc_822125CC;
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r3,r3,3408
	ctx.r3.s64 = ctx.r3.s64 + 3408;
	// bl 0x82224930
	ctx.lr = 0x82212330;
	sub_82224930(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221234C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,17268(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822125c4
	if (cr6.eq) goto loc_822125C4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82212384
	if (cr6.eq) goto loc_82212384;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822123a0
	if (!cr6.gt) goto loc_822123A0;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x82212394
	goto loc_82212394;
loc_82212384:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822123a0
	if (!cr6.gt) goto loc_822123A0;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_82212394:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822123a4
	if (!cr6.eq) goto loc_822123A4;
loc_822123A0:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_822123A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822125c4
	if (cr6.eq) goto loc_822125C4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x822123B8;
	sub_822A3998(ctx, base);
	// lwz r29,48(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82212580
	if (cr6.eq) goto loc_82212580;
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x82212410
	if (cr6.eq) goto loc_82212410;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x82212410
	if (cr6.eq) goto loc_82212410;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-12248
	ctx.r4.s64 = ctx.r10.s64 + -12248;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82212408;
	sub_821F9FB8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82212428
	goto loc_82212428;
loc_82212410:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-12248
	ctx.r4.s64 = ctx.r10.s64 + -12248;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82212424;
	sub_821F9FB8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
loc_82212428:
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r9,-9908
	ctx.r4.s64 = ctx.r9.s64 + -9908;
	// bl 0x825ee230
	ctx.lr = 0x82212438;
	sub_825EE230(ctx, base);
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r11,-12640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221245c
	if (cr6.eq) goto loc_8221245C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82212460
	if (cr6.eq) goto loc_82212460;
loc_8221245C:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82212460:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82212488
	if (cr6.eq) goto loc_82212488;
	// bl 0x82387a18
	ctx.lr = 0x82212470;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82212488
	if (!cr6.eq) goto loc_82212488;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// b 0x822124b4
	goto loc_822124B4;
loc_82212488:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bb408
	ctx.lr = 0x82212494;
	sub_823BB408(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822124b0
	if (cr6.eq) goto loc_822124B0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f31,100(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	f31.f64 = double(temp.f32);
	// b 0x822124b4
	goto loc_822124B4;
loc_822124B0:
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = f30.f64;
loc_822124B4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6432);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822124D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r8,-9924
	ctx.r4.s64 = ctx.r8.s64 + -9924;
	// bl 0x825ee188
	ctx.lr = 0x822124E4;
	sub_825EE188(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822112a8
	ctx.lr = 0x822124F4;
	sub_822112A8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82206458
	ctx.lr = 0x82212500;
	sub_82206458(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x822068f8
	ctx.lr = 0x82212510;
	sub_822068F8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822090b8
	ctx.lr = 0x82212518;
	sub_822090B8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82212558
	if (cr6.eq) goto loc_82212558;
	// lwz r11,-12640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82212544
	if (cr6.eq) goto loc_82212544;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82212548
	if (cr6.eq) goto loc_82212548;
loc_82212544:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82212548:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221255c
	if (cr6.eq) goto loc_8221255C;
loc_82212558:
	// li r5,1
	ctx.r5.s64 = 1;
loc_8221255C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8220d110
	ctx.lr = 0x82212568;
	sub_8220D110(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8220a1a0
	ctx.lr = 0x82212574;
	sub_8220A1A0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822062b0
	ctx.lr = 0x82212580;
	sub_822062B0(ctx, base);
loc_82212580:
	// subf r11,r26,r29
	r11.s64 = r29.s64 - r26.s64;
	// addis r31,r30,5
	r31.s64 = r30.s64 + 327680;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r31,r31,4661
	r31.s64 = r31.s64 + 4661;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// lbz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// beq cr6,0x822125c4
	if (cr6.eq) goto loc_822125C4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82207190
	ctx.lr = 0x822125B0;
	sub_82207190(ctx, base);
	// subf r11,r26,r29
	r11.s64 = r29.s64 - r26.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stb r8,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r8.u8);
loc_822125C4:
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x82234440
	ctx.lr = 0x822125CC;
	sub_82234440(ctx, base);
loc_822125CC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwz r3,-10024(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10024);
	// bl 0x82227bd8
	ctx.lr = 0x822125DC;
	sub_82227BD8(ctx, base);
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

__attribute__((alias("__imp__sub_822125EC"))) PPC_WEAK_FUNC(sub_822125EC);
PPC_FUNC_IMPL(__imp__sub_822125EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822125F0"))) PPC_WEAK_FUNC(sub_822125F0);
PPC_FUNC_IMPL(__imp__sub_822125F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8220f040
	sub_8220F040(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82212604"))) PPC_WEAK_FUNC(sub_82212604);
PPC_FUNC_IMPL(__imp__sub_82212604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82212608"))) PPC_WEAK_FUNC(sub_82212608);
PPC_FUNC_IMPL(__imp__sub_82212608) {
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
	ctx.lr = 0x82212610;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82212200
	ctx.lr = 0x82212620;
	sub_82212200(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-11120
	ctx.r4.s64 = ctx.r9.s64 + -11120;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82212648;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x8221265C;
	sub_821FD7C0(ctx, base);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// lwz r8,308(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r11,0
	r11.s64 = 0;
	// ori r10,r7,6256
	ctx.r10.u64 = ctx.r7.u64 | 6256;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lwz r6,10248(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// addi r30,r8,92
	r30.s64 = ctx.r8.s64 + 92;
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// add r9,r31,r10
	ctx.r9.u64 = r31.u64 + ctx.r10.u64;
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// stw r6,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r6.u32);
loc_8221268C:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822126d4
	if (cr6.eq) goto loc_822126D4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// blt cr6,0x8221268c
	if (cr6.lt) goto loc_8221268C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-9832
	ctx.r5.s64 = ctx.r10.s64 + -9832;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82234d88
	ctx.lr = 0x822126CC;
	sub_82234D88(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_822126D4:
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// li r5,63
	ctx.r5.s64 = 63;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823db670
	ctx.lr = 0x822126EC;
	sub_823DB670(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r31,-10244(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x82212700;
	sub_82218310(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-9948
	ctx.r4.s64 = ctx.r9.s64 + -9948;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822183b0
	ctx.lr = 0x82212714;
	sub_822183B0(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r5,-9864
	ctx.r5.s64 = ctx.r5.s64 + -9864;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f1,3732(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82234d88
	ctx.lr = 0x82212738;
	sub_82234D88(ctx, base);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r3,r4,-9884
	ctx.r3.s64 = ctx.r4.s64 + -9884;
	// bl 0x821e6800
	ctx.lr = 0x82212744;
	sub_821E6800(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8221274C"))) PPC_WEAK_FUNC(sub_8221274C);
PPC_FUNC_IMPL(__imp__sub_8221274C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82212750"))) PPC_WEAK_FUNC(sub_82212750);
PPC_FUNC_IMPL(__imp__sub_82212750) {
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
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-10904
	ctx.r4.s64 = r11.s64 + -10904;
	// addi r3,r10,-7240
	ctx.r3.s64 = ctx.r10.s64 + -7240;
	// bl 0x82554798
	ctx.lr = 0x82212770;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,30464
	ctx.r4.s64 = ctx.r9.s64 + 30464;
	// addi r3,r8,-7272
	ctx.r3.s64 = ctx.r8.s64 + -7272;
	// bl 0x82554798
	ctx.lr = 0x82212784;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-19352
	ctx.r4.s64 = ctx.r7.s64 + -19352;
	// addi r3,r6,-7300
	ctx.r3.s64 = ctx.r6.s64 + -7300;
	// bl 0x82554798
	ctx.lr = 0x82212798;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,9712
	ctx.r4.s64 = ctx.r5.s64 + 9712;
	// addi r3,r3,-7320
	ctx.r3.s64 = ctx.r3.s64 + -7320;
	// bl 0x82554798
	ctx.lr = 0x822127AC;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-10832
	ctx.r4.s64 = r11.s64 + -10832;
	// addi r3,r10,-7344
	ctx.r3.s64 = ctx.r10.s64 + -7344;
	// bl 0x82554798
	ctx.lr = 0x822127C0;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-10712
	ctx.r4.s64 = ctx.r9.s64 + -10712;
	// addi r3,r8,-7368
	ctx.r3.s64 = ctx.r8.s64 + -7368;
	// bl 0x82554798
	ctx.lr = 0x822127D4;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-10592
	ctx.r4.s64 = ctx.r7.s64 + -10592;
	// addi r3,r6,-7392
	ctx.r3.s64 = ctx.r6.s64 + -7392;
	// bl 0x82554798
	ctx.lr = 0x822127E8;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,30536
	ctx.r4.s64 = ctx.r5.s64 + 30536;
	// addi r3,r3,-7420
	ctx.r3.s64 = ctx.r3.s64 + -7420;
	// bl 0x82554798
	ctx.lr = 0x822127FC;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,30584
	ctx.r4.s64 = r11.s64 + 30584;
	// addi r3,r10,-7444
	ctx.r3.s64 = ctx.r10.s64 + -7444;
	// bl 0x82554798
	ctx.lr = 0x82212810;
	sub_82554798(ctx, base);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,0
	ctx.r4.s64 = ctx.r9.s64 + 0;
	// addi r3,r8,-7468
	ctx.r3.s64 = ctx.r8.s64 + -7468;
	// bl 0x82554798
	ctx.lr = 0x82212824;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,30632
	ctx.r4.s64 = ctx.r7.s64 + 30632;
	// addi r3,r6,-7492
	ctx.r3.s64 = ctx.r6.s64 + -7492;
	// bl 0x82554798
	ctx.lr = 0x82212838;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-19280
	ctx.r4.s64 = ctx.r5.s64 + -19280;
	// addi r3,r3,-7508
	ctx.r3.s64 = ctx.r3.s64 + -7508;
	// bl 0x82554798
	ctx.lr = 0x8221284C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-10552
	ctx.r4.s64 = r11.s64 + -10552;
	// addi r3,r10,-7524
	ctx.r3.s64 = ctx.r10.s64 + -7524;
	// bl 0x82554798
	ctx.lr = 0x82212860;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-19232
	ctx.r4.s64 = ctx.r9.s64 + -19232;
	// addi r3,r8,-7540
	ctx.r3.s64 = ctx.r8.s64 + -7540;
	// bl 0x82554798
	ctx.lr = 0x82212874;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-19168
	ctx.r4.s64 = ctx.r7.s64 + -19168;
	// addi r3,r6,-7556
	ctx.r3.s64 = ctx.r6.s64 + -7556;
	// bl 0x82554798
	ctx.lr = 0x82212888;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-19072
	ctx.r4.s64 = ctx.r5.s64 + -19072;
	// addi r3,r3,-7572
	ctx.r3.s64 = ctx.r3.s64 + -7572;
	// bl 0x82554798
	ctx.lr = 0x8221289C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-18992
	ctx.r4.s64 = r11.s64 + -18992;
	// addi r3,r10,-7588
	ctx.r3.s64 = ctx.r10.s64 + -7588;
	// bl 0x82554798
	ctx.lr = 0x822128B0;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-18896
	ctx.r4.s64 = ctx.r9.s64 + -18896;
	// addi r3,r8,-7604
	ctx.r3.s64 = ctx.r8.s64 + -7604;
	// bl 0x82554798
	ctx.lr = 0x822128C4;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-10552
	ctx.r4.s64 = ctx.r7.s64 + -10552;
	// addi r3,r6,-7620
	ctx.r3.s64 = ctx.r6.s64 + -7620;
	// bl 0x82554798
	ctx.lr = 0x822128D8;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-10520
	ctx.r4.s64 = ctx.r5.s64 + -10520;
	// addi r3,r3,-7636
	ctx.r3.s64 = ctx.r3.s64 + -7636;
	// bl 0x82554798
	ctx.lr = 0x822128EC;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-18784
	ctx.r4.s64 = r11.s64 + -18784;
	// addi r3,r10,-7656
	ctx.r3.s64 = ctx.r10.s64 + -7656;
	// bl 0x82554798
	ctx.lr = 0x82212900;
	sub_82554798(ctx, base);
	// lis r9,-32157
	ctx.r9.s64 = -2107441152;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,10448
	ctx.r4.s64 = ctx.r9.s64 + 10448;
	// addi r3,r8,-7676
	ctx.r3.s64 = ctx.r8.s64 + -7676;
	// bl 0x82554798
	ctx.lr = 0x82212914;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-18712
	ctx.r4.s64 = ctx.r7.s64 + -18712;
	// addi r3,r6,-7692
	ctx.r3.s64 = ctx.r6.s64 + -7692;
	// bl 0x82554798
	ctx.lr = 0x82212928;
	sub_82554798(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-12200
	ctx.r4.s64 = ctx.r5.s64 + -12200;
	// addi r3,r3,-7704
	ctx.r3.s64 = ctx.r3.s64 + -7704;
	// bl 0x82554798
	ctx.lr = 0x8221293C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-10488
	ctx.r4.s64 = r11.s64 + -10488;
	// addi r3,r10,-7732
	ctx.r3.s64 = ctx.r10.s64 + -7732;
	// bl 0x82554798
	ctx.lr = 0x82212950;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-18640
	ctx.r4.s64 = ctx.r9.s64 + -18640;
	// addi r3,r8,-7764
	ctx.r3.s64 = ctx.r8.s64 + -7764;
	// bl 0x82554798
	ctx.lr = 0x82212964;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-18544
	ctx.r4.s64 = ctx.r7.s64 + -18544;
	// addi r3,r6,-7792
	ctx.r3.s64 = ctx.r6.s64 + -7792;
	// bl 0x82554798
	ctx.lr = 0x82212978;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-18480
	ctx.r4.s64 = ctx.r5.s64 + -18480;
	// addi r3,r3,-7820
	ctx.r3.s64 = ctx.r3.s64 + -7820;
	// bl 0x82554798
	ctx.lr = 0x8221298C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-18416
	ctx.r4.s64 = r11.s64 + -18416;
	// addi r3,r10,-7844
	ctx.r3.s64 = ctx.r10.s64 + -7844;
	// bl 0x82554798
	ctx.lr = 0x822129A0;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-18376
	ctx.r4.s64 = ctx.r9.s64 + -18376;
	// addi r3,r8,-7872
	ctx.r3.s64 = ctx.r8.s64 + -7872;
	// bl 0x82554798
	ctx.lr = 0x822129B4;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-18304
	ctx.r4.s64 = ctx.r7.s64 + -18304;
	// addi r3,r6,-7904
	ctx.r3.s64 = ctx.r6.s64 + -7904;
	// bl 0x82554798
	ctx.lr = 0x822129C8;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-18280
	ctx.r4.s64 = ctx.r5.s64 + -18280;
	// addi r3,r3,-7936
	ctx.r3.s64 = ctx.r3.s64 + -7936;
	// bl 0x82554798
	ctx.lr = 0x822129DC;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// addi r4,r11,-18176
	ctx.r4.s64 = r11.s64 + -18176;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-7968
	ctx.r3.s64 = ctx.r10.s64 + -7968;
	// bl 0x82554798
	ctx.lr = 0x822129F0;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-18152
	ctx.r4.s64 = ctx.r9.s64 + -18152;
	// addi r3,r8,-8000
	ctx.r3.s64 = ctx.r8.s64 + -8000;
	// bl 0x82554798
	ctx.lr = 0x82212A04;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-10384
	ctx.r4.s64 = ctx.r7.s64 + -10384;
	// addi r3,r6,-8032
	ctx.r3.s64 = ctx.r6.s64 + -8032;
	// bl 0x82554798
	ctx.lr = 0x82212A18;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-10352
	ctx.r4.s64 = ctx.r5.s64 + -10352;
	// addi r3,r3,-8068
	ctx.r3.s64 = ctx.r3.s64 + -8068;
	// bl 0x82554798
	ctx.lr = 0x82212A2C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-10320
	ctx.r4.s64 = r11.s64 + -10320;
	// addi r3,r10,-8084
	ctx.r3.s64 = ctx.r10.s64 + -8084;
	// bl 0x82554798
	ctx.lr = 0x82212A40;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-8328
	ctx.r4.s64 = ctx.r9.s64 + -8328;
	// addi r3,r8,-8104
	ctx.r3.s64 = ctx.r8.s64 + -8104;
	// bl 0x82554798
	ctx.lr = 0x82212A54;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,17952
	ctx.r4.s64 = ctx.r7.s64 + 17952;
	// addi r3,r6,-8124
	ctx.r3.s64 = ctx.r6.s64 + -8124;
	// bl 0x82554798
	ctx.lr = 0x82212A68;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,17960
	ctx.r4.s64 = ctx.r5.s64 + 17960;
	// addi r3,r3,-8144
	ctx.r3.s64 = ctx.r3.s64 + -8144;
	// bl 0x82554798
	ctx.lr = 0x82212A7C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-18080
	ctx.r4.s64 = r11.s64 + -18080;
	// addi r3,r10,-8160
	ctx.r3.s64 = ctx.r10.s64 + -8160;
	// bl 0x82554798
	ctx.lr = 0x82212A90;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-10304
	ctx.r4.s64 = ctx.r9.s64 + -10304;
	// addi r3,r8,-8188
	ctx.r3.s64 = ctx.r8.s64 + -8188;
	// bl 0x82554798
	ctx.lr = 0x82212AA4;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-10168
	ctx.r4.s64 = ctx.r7.s64 + -10168;
	// addi r3,r6,-8220
	ctx.r3.s64 = ctx.r6.s64 + -8220;
	// bl 0x82554798
	ctx.lr = 0x82212AB8;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-10080
	ctx.r4.s64 = ctx.r5.s64 + -10080;
	// addi r3,r3,-8252
	ctx.r3.s64 = ctx.r3.s64 + -8252;
	// bl 0x82554798
	ctx.lr = 0x82212ACC;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-9992
	ctx.r4.s64 = r11.s64 + -9992;
	// addi r3,r10,-8280
	ctx.r3.s64 = ctx.r10.s64 + -8280;
	// bl 0x82554798
	ctx.lr = 0x82212AE0;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-9872
	ctx.r4.s64 = ctx.r9.s64 + -9872;
	// addi r3,r8,-8308
	ctx.r3.s64 = ctx.r8.s64 + -8308;
	// bl 0x82554798
	ctx.lr = 0x82212AF4;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,30648
	ctx.r4.s64 = ctx.r7.s64 + 30648;
	// addi r3,r6,-8340
	ctx.r3.s64 = ctx.r6.s64 + -8340;
	// bl 0x82554798
	ctx.lr = 0x82212B08;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-18056
	ctx.r4.s64 = ctx.r5.s64 + -18056;
	// addi r3,r3,-8364
	ctx.r3.s64 = ctx.r3.s64 + -8364;
	// bl 0x82554798
	ctx.lr = 0x82212B1C;
	sub_82554798(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r3,r11,-8392
	ctx.r3.s64 = r11.s64 + -8392;
	// addi r4,r10,30680
	ctx.r4.s64 = ctx.r10.s64 + 30680;
	// bl 0x82554798
	ctx.lr = 0x82212B30;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,30704
	ctx.r4.s64 = ctx.r9.s64 + 30704;
	// addi r3,r8,-8412
	ctx.r3.s64 = ctx.r8.s64 + -8412;
	// bl 0x82554798
	ctx.lr = 0x82212B44;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-18000
	ctx.r4.s64 = ctx.r7.s64 + -18000;
	// addi r3,r6,-8444
	ctx.r3.s64 = ctx.r6.s64 + -8444;
	// bl 0x82554798
	ctx.lr = 0x82212B58;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-9752
	ctx.r4.s64 = ctx.r5.s64 + -9752;
	// addi r3,r3,-8456
	ctx.r3.s64 = ctx.r3.s64 + -8456;
	// bl 0x82554798
	ctx.lr = 0x82212B6C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-17944
	ctx.r4.s64 = r11.s64 + -17944;
	// addi r3,r10,-8476
	ctx.r3.s64 = ctx.r10.s64 + -8476;
	// bl 0x82554798
	ctx.lr = 0x82212B80;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,17968
	ctx.r4.s64 = ctx.r9.s64 + 17968;
	// addi r3,r8,-8500
	ctx.r3.s64 = ctx.r8.s64 + -8500;
	// bl 0x82554798
	ctx.lr = 0x82212B94;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-9680
	ctx.r4.s64 = ctx.r7.s64 + -9680;
	// addi r3,r6,-8520
	ctx.r3.s64 = ctx.r6.s64 + -8520;
	// bl 0x82554798
	ctx.lr = 0x82212BA8;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-9664
	ctx.r4.s64 = ctx.r5.s64 + -9664;
	// addi r3,r3,-8548
	ctx.r3.s64 = ctx.r3.s64 + -8548;
	// bl 0x82554798
	ctx.lr = 0x82212BBC;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,30808
	ctx.r4.s64 = r11.s64 + 30808;
	// addi r3,r10,-8576
	ctx.r3.s64 = ctx.r10.s64 + -8576;
	// bl 0x82554798
	ctx.lr = 0x82212BD0;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17912
	ctx.r4.s64 = ctx.r9.s64 + -17912;
	// addi r3,r8,-8596
	ctx.r3.s64 = ctx.r8.s64 + -8596;
	// bl 0x82554798
	ctx.lr = 0x82212BE4;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,30840
	ctx.r4.s64 = ctx.r7.s64 + 30840;
	// addi r3,r6,-8628
	ctx.r3.s64 = ctx.r6.s64 + -8628;
	// bl 0x82554798
	ctx.lr = 0x82212BF8;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,30936
	ctx.r4.s64 = ctx.r5.s64 + 30936;
	// addi r3,r3,-8656
	ctx.r3.s64 = ctx.r3.s64 + -8656;
	// bl 0x82554798
	ctx.lr = 0x82212C0C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-9648
	ctx.r4.s64 = r11.s64 + -9648;
	// addi r3,r10,-8672
	ctx.r3.s64 = ctx.r10.s64 + -8672;
	// bl 0x82554798
	ctx.lr = 0x82212C20;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,30984
	ctx.r4.s64 = ctx.r9.s64 + 30984;
	// addi r3,r8,-8696
	ctx.r3.s64 = ctx.r8.s64 + -8696;
	// bl 0x82554798
	ctx.lr = 0x82212C34;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,31032
	ctx.r4.s64 = ctx.r7.s64 + 31032;
	// addi r3,r6,-8724
	ctx.r3.s64 = ctx.r6.s64 + -8724;
	// bl 0x82554798
	ctx.lr = 0x82212C48;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,31080
	ctx.r4.s64 = ctx.r5.s64 + 31080;
	// addi r3,r3,-8744
	ctx.r3.s64 = ctx.r3.s64 + -8744;
	// bl 0x82554798
	ctx.lr = 0x82212C5C;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,31128
	ctx.r4.s64 = r11.s64 + 31128;
	// addi r3,r10,-8772
	ctx.r3.s64 = ctx.r10.s64 + -8772;
	// bl 0x82554798
	ctx.lr = 0x82212C70;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,31176
	ctx.r4.s64 = ctx.r9.s64 + 31176;
	// addi r3,r8,-8792
	ctx.r3.s64 = ctx.r8.s64 + -8792;
	// bl 0x82554798
	ctx.lr = 0x82212C84;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,31208
	ctx.r4.s64 = ctx.r7.s64 + 31208;
	// addi r3,r6,-8816
	ctx.r3.s64 = ctx.r6.s64 + -8816;
	// bl 0x82554798
	ctx.lr = 0x82212C98;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,31240
	ctx.r4.s64 = ctx.r5.s64 + 31240;
	// addi r3,r3,-8840
	ctx.r3.s64 = ctx.r3.s64 + -8840;
	// bl 0x82554798
	ctx.lr = 0x82212CAC;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-17792
	ctx.r4.s64 = r11.s64 + -17792;
	// addi r3,r10,-8868
	ctx.r3.s64 = ctx.r10.s64 + -8868;
	// bl 0x82554798
	ctx.lr = 0x82212CC0;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,31304
	ctx.r4.s64 = ctx.r9.s64 + 31304;
	// addi r3,r8,-8904
	ctx.r3.s64 = ctx.r8.s64 + -8904;
	// bl 0x82554798
	ctx.lr = 0x82212CD4;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-9616
	ctx.r4.s64 = ctx.r7.s64 + -9616;
	// addi r3,r6,-8932
	ctx.r3.s64 = ctx.r6.s64 + -8932;
	// bl 0x82554798
	ctx.lr = 0x82212CE8;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,31336
	ctx.r4.s64 = ctx.r5.s64 + 31336;
	// addi r3,r3,-8956
	ctx.r3.s64 = ctx.r3.s64 + -8956;
	// bl 0x82554798
	ctx.lr = 0x82212CFC;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,31376
	ctx.r4.s64 = r11.s64 + 31376;
	// addi r3,r10,-8988
	ctx.r3.s64 = ctx.r10.s64 + -8988;
	// bl 0x82554798
	ctx.lr = 0x82212D10;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,31400
	ctx.r4.s64 = ctx.r9.s64 + 31400;
	// addi r3,r8,-9020
	ctx.r3.s64 = ctx.r8.s64 + -9020;
	// bl 0x82554798
	ctx.lr = 0x82212D24;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17688
	ctx.r4.s64 = ctx.r7.s64 + -17688;
	// addi r3,r6,-9052
	ctx.r3.s64 = ctx.r6.s64 + -9052;
	// bl 0x82554798
	ctx.lr = 0x82212D38;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-17640
	ctx.r4.s64 = ctx.r5.s64 + -17640;
	// addi r3,r3,-9084
	ctx.r3.s64 = ctx.r3.s64 + -9084;
	// bl 0x82554798
	ctx.lr = 0x82212D4C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-17552
	ctx.r4.s64 = r11.s64 + -17552;
	// addi r3,r10,-9112
	ctx.r3.s64 = ctx.r10.s64 + -9112;
	// bl 0x82554798
	ctx.lr = 0x82212D60;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17520
	ctx.r4.s64 = ctx.r9.s64 + -17520;
	// addi r3,r8,-9140
	ctx.r3.s64 = ctx.r8.s64 + -9140;
	// bl 0x82554798
	ctx.lr = 0x82212D74;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17432
	ctx.r4.s64 = ctx.r7.s64 + -17432;
	// addi r3,r6,-9172
	ctx.r3.s64 = ctx.r6.s64 + -9172;
	// bl 0x82554798
	ctx.lr = 0x82212D88;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-17400
	ctx.r4.s64 = ctx.r5.s64 + -17400;
	// addi r3,r3,-9204
	ctx.r3.s64 = ctx.r3.s64 + -9204;
	// bl 0x82554798
	ctx.lr = 0x82212D9C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-9600
	ctx.r4.s64 = r11.s64 + -9600;
	// addi r3,r10,-9236
	ctx.r3.s64 = ctx.r10.s64 + -9236;
	// bl 0x82554798
	ctx.lr = 0x82212DB0;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-9568
	ctx.r4.s64 = ctx.r9.s64 + -9568;
	// addi r3,r8,-9268
	ctx.r3.s64 = ctx.r8.s64 + -9268;
	// bl 0x82554798
	ctx.lr = 0x82212DC4;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,17488
	ctx.r4.s64 = ctx.r7.s64 + 17488;
	// addi r3,r6,-9288
	ctx.r3.s64 = ctx.r6.s64 + -9288;
	// bl 0x82554798
	ctx.lr = 0x82212DD8;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-9544
	ctx.r4.s64 = ctx.r5.s64 + -9544;
	// addi r3,r3,-9304
	ctx.r3.s64 = ctx.r3.s64 + -9304;
	// bl 0x82554798
	ctx.lr = 0x82212DEC;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-8312
	ctx.r4.s64 = r11.s64 + -8312;
	// addi r3,r10,-9324
	ctx.r3.s64 = ctx.r10.s64 + -9324;
	// bl 0x82554798
	ctx.lr = 0x82212E00;
	sub_82554798(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17312
	ctx.r4.s64 = ctx.r9.s64 + -17312;
	// addi r3,r8,-9344
	ctx.r3.s64 = ctx.r8.s64 + -9344;
	// bl 0x82554798
	ctx.lr = 0x82212E14;
	sub_82554798(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17272
	ctx.r4.s64 = ctx.r7.s64 + -17272;
	// addi r3,r6,-9376
	ctx.r3.s64 = ctx.r6.s64 + -9376;
	// bl 0x82554798
	ctx.lr = 0x82212E28;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-17192
	ctx.r4.s64 = ctx.r5.s64 + -17192;
	// addi r3,r3,-9408
	ctx.r3.s64 = ctx.r3.s64 + -9408;
	// bl 0x82554798
	ctx.lr = 0x82212E3C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-17096
	ctx.r4.s64 = r11.s64 + -17096;
	// addi r3,r10,-9432
	ctx.r3.s64 = ctx.r10.s64 + -9432;
	// bl 0x82554798
	ctx.lr = 0x82212E50;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,31424
	ctx.r4.s64 = ctx.r9.s64 + 31424;
	// addi r3,r8,-9448
	ctx.r3.s64 = ctx.r8.s64 + -9448;
	// bl 0x82554798
	ctx.lr = 0x82212E64;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,31520
	ctx.r4.s64 = ctx.r7.s64 + 31520;
	// addi r3,r6,-9472
	ctx.r3.s64 = ctx.r6.s64 + -9472;
	// bl 0x82554798
	ctx.lr = 0x82212E78;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,31616
	ctx.r4.s64 = ctx.r5.s64 + 31616;
	// addi r3,r3,-9492
	ctx.r3.s64 = ctx.r3.s64 + -9492;
	// bl 0x82554798
	ctx.lr = 0x82212E8C;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,31728
	ctx.r4.s64 = r11.s64 + 31728;
	// addi r3,r10,-9516
	ctx.r3.s64 = ctx.r10.s64 + -9516;
	// bl 0x82554798
	ctx.lr = 0x82212EA0;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,31840
	ctx.r4.s64 = ctx.r9.s64 + 31840;
	// addi r3,r8,-9556
	ctx.r3.s64 = ctx.r8.s64 + -9556;
	// bl 0x82554798
	ctx.lr = 0x82212EB4;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,31904
	ctx.r4.s64 = ctx.r7.s64 + 31904;
	// addi r3,r6,-9600
	ctx.r3.s64 = ctx.r6.s64 + -9600;
	// bl 0x82554798
	ctx.lr = 0x82212EC8;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,31960
	ctx.r4.s64 = ctx.r5.s64 + 31960;
	// addi r3,r3,-9628
	ctx.r3.s64 = ctx.r3.s64 + -9628;
	// bl 0x82554798
	ctx.lr = 0x82212EDC;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,17992
	ctx.r4.s64 = r11.s64 + 17992;
	// addi r3,r10,-9652
	ctx.r3.s64 = ctx.r10.s64 + -9652;
	// bl 0x82554798
	ctx.lr = 0x82212EF0;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,18000
	ctx.r4.s64 = ctx.r9.s64 + 18000;
	// addi r3,r8,-9676
	ctx.r3.s64 = ctx.r8.s64 + -9676;
	// bl 0x82554798
	ctx.lr = 0x82212F04;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,18008
	ctx.r4.s64 = ctx.r7.s64 + 18008;
	// addi r3,r6,-9704
	ctx.r3.s64 = ctx.r6.s64 + -9704;
	// bl 0x82554798
	ctx.lr = 0x82212F18;
	sub_82554798(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-9496
	ctx.r4.s64 = ctx.r5.s64 + -9496;
	// addi r3,r3,-9728
	ctx.r3.s64 = ctx.r3.s64 + -9728;
	// bl 0x82554798
	ctx.lr = 0x82212F2C;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-9480
	ctx.r4.s64 = r11.s64 + -9480;
	// addi r3,r10,-9760
	ctx.r3.s64 = ctx.r10.s64 + -9760;
	// bl 0x82554798
	ctx.lr = 0x82212F40;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,31992
	ctx.r4.s64 = ctx.r9.s64 + 31992;
	// addi r3,r8,-9784
	ctx.r3.s64 = ctx.r8.s64 + -9784;
	// bl 0x82554798
	ctx.lr = 0x82212F54;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,32040
	ctx.r4.s64 = ctx.r7.s64 + 32040;
	// addi r3,r6,-9804
	ctx.r3.s64 = ctx.r6.s64 + -9804;
	// bl 0x82554798
	ctx.lr = 0x82212F68;
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

__attribute__((alias("__imp__sub_82212F78"))) PPC_WEAK_FUNC(sub_82212F78);
PPC_FUNC_IMPL(__imp__sub_82212F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82212fd0
	if (!cr6.lt) goto loc_82212FD0;
loc_82212F8C:
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r10,r8,16
	ctx.r10.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r4,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r4.u32);
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82212f8c
	if (cr6.lt) goto loc_82212F8C;
loc_82212FD0:
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82212FE4"))) PPC_WEAK_FUNC(sub_82212FE4);
PPC_FUNC_IMPL(__imp__sub_82212FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82212FE8"))) PPC_WEAK_FUNC(sub_82212FE8);
PPC_FUNC_IMPL(__imp__sub_82212FE8) {
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
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8221300C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82213040
	if (!cr6.gt) goto loc_82213040;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,5
	ctx.r9.s64 = 5;
loc_82213020:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82213034
	if (cr6.eq) goto loc_82213034;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_82213034:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x82213020
	if (!cr0.eq) goto loc_82213020;
loc_82213040:
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

__attribute__((alias("__imp__sub_82213054"))) PPC_WEAK_FUNC(sub_82213054);
PPC_FUNC_IMPL(__imp__sub_82213054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82213058"))) PPC_WEAK_FUNC(sub_82213058);
PPC_FUNC_IMPL(__imp__sub_82213058) {
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
	ctx.lr = 0x82213060;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82130528
	ctx.lr = 0x8221307C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// beq cr6,0x82213094
	if (cr6.eq) goto loc_82213094;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218fad0
	ctx.lr = 0x82213090;
	sub_8218FAD0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_82213094:
	// addi r11,r28,3
	r11.s64 = r28.s64 + 3;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stwx r5,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r5.u32);
	// lwz r3,-25232(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x822130B0;
	sub_82182150(ctx, base);
	// clrlwi r9,r27,24
	ctx.r9.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822130c8
	if (cr6.eq) goto loc_822130C8;
	// lwz r4,584(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 584);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x8218f8d0
	ctx.lr = 0x822130C8;
	sub_8218F8D0(ctx, base);
loc_822130C8:
	// add r11,r28,r31
	r11.u64 = r28.u64 + r31.u64;
	// stb r27,188(r11)
	PPC_STORE_U8(r11.u32 + 188, r27.u8);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822130DC"))) PPC_WEAK_FUNC(sub_822130DC);
PPC_FUNC_IMPL(__imp__sub_822130DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822130E0"))) PPC_WEAK_FUNC(sub_822130E0);
PPC_FUNC_IMPL(__imp__sub_822130E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r11,r4,102
	r11.s64 = ctx.r4.s64 + 102;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,2
	r11.s64 = 2;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// addi r10,r3,412
	ctx.r10.s64 = ctx.r3.s64 + 412;
	// lwzx r6,r5,r3
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
loc_82213100:
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// bne cr6,0x8221311c
	if (!cr6.eq) goto loc_8221311C;
	// addi r8,r11,-2
	ctx.r8.s64 = r11.s64 + -2;
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// beq cr6,0x8221311c
	if (cr6.eq) goto loc_8221311C;
	// li r9,1
	ctx.r9.s64 = 1;
loc_8221311C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// bne cr6,0x82213138
	if (!cr6.eq) goto loc_82213138;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// beq cr6,0x82213138
	if (cr6.eq) goto loc_82213138;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82213138:
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// bne cr6,0x82213150
	if (!cr6.eq) goto loc_82213150;
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// beq cr6,0x82213150
	if (cr6.eq) goto loc_82213150;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82213150:
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// bne cr6,0x8221316c
	if (!cr6.eq) goto loc_8221316C;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// beq cr6,0x8221316c
	if (cr6.eq) goto loc_8221316C;
	// li r9,1
	ctx.r9.s64 = 1;
loc_8221316C:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r8,r11,-2
	ctx.r8.s64 = r11.s64 + -2;
	// cmpwi cr6,r8,44
	cr6.compare<int32_t>(ctx.r8.s32, 44, xer);
	// blt cr6,0x82213100
	if (cr6.lt) goto loc_82213100;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822131cc
	if (!cr6.eq) goto loc_822131CC;
	// li r8,1
	ctx.r8.s64 = 1;
	// lhz r11,592(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 592);
	// lwz r9,588(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 588);
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r8,-32(r1)
	PPC_STORE_U8(ctx.r1.u32 + -32, ctx.r8.u8);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r4,-32(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// sth r7,592(r3)
	PPC_STORE_U16(ctx.r3.u32 + 592, ctx.r7.u16);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r3,588
	ctx.r9.s64 = ctx.r3.s64 + 588;
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_822131CC:
	// stwx r31,r5,r3
	PPC_STORE_U32(ctx.r5.u32 + ctx.r3.u32, r31.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822131D8"))) PPC_WEAK_FUNC(sub_822131D8);
PPC_FUNC_IMPL(__imp__sub_822131D8) {
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
	ctx.lr = 0x822131E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,58
	r11.s64 = ctx.r4.s64 + 58;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r4,r31
	ctx.r10.u64 = ctx.r4.u64 + r31.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lwzx r30,r11,r31
	r30.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stwx r28,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r28.u32);
	// addi r11,r4,3
	r11.s64 = ctx.r4.s64 + 3;
	// lbz r9,188(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 188);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// beq cr6,0x82213224
	if (cr6.eq) goto loc_82213224;
	// lwz r4,584(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 584);
	// b 0x82213228
	goto loc_82213228;
loc_82213224:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82213228:
	// bl 0x8218f8d0
	ctx.lr = 0x8221322C;
	sub_8218F8D0(ctx, base);
	// addi r11,r31,236
	r11.s64 = r31.s64 + 236;
	// li r10,11
	ctx.r10.s64 = 11;
loc_82213234:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// bne cr6,0x82213244
	if (!cr6.eq) goto loc_82213244;
	// li r29,1
	r29.s64 = 1;
loc_82213244:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// bne cr6,0x82213254
	if (!cr6.eq) goto loc_82213254;
	// li r29,1
	r29.s64 = 1;
loc_82213254:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// bne cr6,0x82213264
	if (!cr6.eq) goto loc_82213264;
	// li r29,1
	r29.s64 = 1;
loc_82213264:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// bne cr6,0x82213274
	if (!cr6.eq) goto loc_82213274;
	// li r29,1
	r29.s64 = 1;
loc_82213274:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82213234
	if (!cr0.eq) goto loc_82213234;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822132c8
	if (!cr6.eq) goto loc_822132C8;
	// lhz r11,592(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 592);
	// li r10,5
	ctx.r10.s64 = 5;
	// lwz r9,588(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 1);
	// stb r28,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r28.u8);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r5,r11,r8
	ctx.r5.u64 = r11.u64 + ctx.r8.u64;
	// sth r4,592(r31)
	PPC_STORE_U16(r31.u32 + 592, ctx.r4.u16);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r31,588
	ctx.r9.s64 = r31.s64 + 588;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_822132C8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822132D0"))) PPC_WEAK_FUNC(sub_822132D0);
PPC_FUNC_IMPL(__imp__sub_822132D0) {
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
	ctx.lr = 0x822132D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r30,58
	r11.s64 = r30.s64 + 58;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r31
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82213300
	if (cr6.eq) goto loc_82213300;
	// bl 0x822131d8
	ctx.lr = 0x82213300;
	sub_822131D8(ctx, base);
loc_82213300:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// stwx r28,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, r28.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82213330
	if (cr6.eq) goto loc_82213330;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82213330
	if (cr6.eq) goto loc_82213330;
	// bl 0x8218f8d0
	ctx.lr = 0x82213330;
	sub_8218F8D0(ctx, base);
loc_82213330:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82213338"))) PPC_WEAK_FUNC(sub_82213338);
PPC_FUNC_IMPL(__imp__sub_82213338) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r11,r31,102
	r11.s64 = r31.s64 + 102;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82213364
	if (cr6.eq) goto loc_82213364;
	// bl 0x822130e0
	ctx.lr = 0x82213364;
	sub_822130E0(ctx, base);
loc_82213364:
	// addi r11,r31,58
	r11.s64 = r31.s64 + 58;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82213380
	if (cr6.eq) goto loc_82213380;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822131d8
	ctx.lr = 0x82213380;
	sub_822131D8(ctx, base);
loc_82213380:
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

__attribute__((alias("__imp__sub_82213394"))) PPC_WEAK_FUNC(sub_82213394);
PPC_FUNC_IMPL(__imp__sub_82213394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82213398"))) PPC_WEAK_FUNC(sub_82213398);
PPC_FUNC_IMPL(__imp__sub_82213398) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x822133A0;
	// stwu r1,-1120(r1)
	ea = -1120 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r14,r4
	r14.u64 = ctx.r4.u64;
	// li r17,0
	r17.s64 = 0;
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// mr r16,r17
	r16.u64 = r17.u64;
	// bne cr6,0x822133c8
	if (!cr6.eq) goto loc_822133C8;
	// li r11,8
	r11.s64 = 8;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// b 0x822133cc
	goto loc_822133CC;
loc_822133C8:
	// stw r14,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r14.u32);
loc_822133CC:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r28,r14
	r28.u64 = r14.u64;
	// cmpw cr6,r14,r11
	cr6.compare<int32_t>(r14.s32, r11.s32, xer);
	// bgt cr6,0x822135f8
	if (cr6.gt) goto loc_822135F8;
	// lis r30,-32255
	r30.s64 = -2113863680;
	// lis r31,-32254
	r31.s64 = -2113798144;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r20,r30,-30140
	r20.s64 = r30.s64 + -30140;
	// addi r27,r31,-17804
	r27.s64 = r31.s64 + -17804;
	// addi r26,r3,-6760
	r26.s64 = ctx.r3.s64 + -6760;
	// addi r25,r4,-29628
	r25.s64 = ctx.r4.s64 + -29628;
	// addi r19,r5,-29624
	r19.s64 = ctx.r5.s64 + -29624;
	// addi r24,r6,-6772
	r24.s64 = ctx.r6.s64 + -6772;
	// addi r23,r7,-6792
	r23.s64 = ctx.r7.s64 + -6792;
	// addi r22,r8,-6800
	r22.s64 = ctx.r8.s64 + -6800;
	// addi r21,r9,30576
	r21.s64 = ctx.r9.s64 + 30576;
	// addi r18,r10,-6844
	r18.s64 = ctx.r10.s64 + -6844;
	// addi r29,r11,-6880
	r29.s64 = r11.s64 + -6880;
loc_82213434:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x82213470
	if (!cr6.eq) goto loc_82213470;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// li r10,127
	ctx.r10.s64 = 127;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// subf r9,r10,r29
	ctx.r9.s64 = r29.s64 - ctx.r10.s64;
loc_82213450:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82213468
	if (cr6.eq) goto loc_82213468;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82213450
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82213450;
loc_82213468:
	// stb r17,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r17.u8);
	// b 0x82213484
	goto loc_82213484;
loc_82213470:
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,127
	ctx.r4.s64 = 127;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82137a08
	ctx.lr = 0x82213484;
	sub_82137A08(ctx, base);
loc_82213484:
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// bl 0x821ca6a8
	ctx.lr = 0x8221349C;
	sub_821CA6A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822135e8
	if (cr6.eq) goto loc_822135E8;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x821d1cd0
	ctx.lr = 0x822134B0;
	sub_821D1CD0(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x821cf7b8
	ctx.lr = 0x822134C0;
	sub_821CF7B8(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x821cff40
	ctx.lr = 0x822134D0;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822135dc
	if (cr6.eq) goto loc_822135DC;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x821d0898
	ctx.lr = 0x822134E8;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x821cfe80
	ctx.lr = 0x822134F8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822135dc
	if (!cr6.eq) goto loc_822135DC;
loc_82213504:
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x821cfaa8
	ctx.lr = 0x82213514;
	sub_821CFAA8(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,96
	ctx.r4.s64 = 96;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x82137a08
	ctx.lr = 0x82213528;
	sub_82137A08(ctx, base);
	// li r4,92
	ctx.r4.s64 = 92;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db6d0
	ctx.lr = 0x82213534;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x82213544
	if (!cr6.eq) goto loc_82213544;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_82213544:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823c95b0
	ctx.lr = 0x82213554;
	sub_823C95B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822135c0
	if (!cr6.eq) goto loc_822135C0;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82213564;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82213584
	if (cr6.eq) goto loc_82213584;
	// bl 0x821e2748
	ctx.lr = 0x82213574;
	sub_821E2748(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// stw r17,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r17.u32);
	// b 0x82213588
	goto loc_82213588;
loc_82213584:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
loc_82213588:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,9
	ctx.r6.s64 = 9;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// bl 0x821e2940
	ctx.lr = 0x822135A0;
	sub_821E2940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822135c0
	if (cr6.eq) goto loc_822135C0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823ca788
	ctx.lr = 0x822135BC;
	sub_823CA788(ctx, base);
	// addi r16,r16,1
	r16.s64 = r16.s64 + 1;
loc_822135C0:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x821cfe80
	ctx.lr = 0x822135D0;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82213504
	if (cr6.eq) goto loc_82213504;
loc_822135DC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x822135E4;
	sub_821BE610(ctx, base);
	// stw r20,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r20.u32);
loc_822135E8:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// ble cr6,0x82213434
	if (!cr6.gt) goto loc_82213434;
loc_822135F8:
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// bne cr6,0x82213628
	if (!cr6.eq) goto loc_82213628;
	// addi r31,r15,588
	r31.s64 = r15.s64 + 588;
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x8221361c
	if (cr6.eq) goto loc_8221361C;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82212fe8
	ctx.lr = 0x82213618;
	sub_82212FE8(ctx, base);
	// b 0x82213620
	goto loc_82213620;
loc_8221361C:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
loc_82213620:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r16,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r16.u16);
loc_82213628:
	// lwz r11,584(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 584);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82213644
	if (!cr6.eq) goto loc_82213644;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-6900
	ctx.r3.s64 = r11.s64 + -6900;
	// bl 0x8217d9f8
	ctx.lr = 0x82213640;
	sub_8217D9F8(ctx, base);
	// stw r3,584(r15)
	PPC_STORE_U32(r15.u32 + 584, ctx.r3.u32);
loc_82213644:
	// addi r1,r1,1120
	ctx.r1.s64 = ctx.r1.s64 + 1120;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8221364C"))) PPC_WEAK_FUNC(sub_8221364C);
PPC_FUNC_IMPL(__imp__sub_8221364C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82213650"))) PPC_WEAK_FUNC(sub_82213650);
PPC_FUNC_IMPL(__imp__sub_82213650) {
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
	ctx.lr = 0x82213658;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r30,102
	r11.s64 = r30.s64 + 102;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221367c
	if (cr6.eq) goto loc_8221367C;
	// bl 0x822130e0
	ctx.lr = 0x8221367C;
	sub_822130E0(ctx, base);
loc_8221367C:
	// addi r11,r30,58
	r11.s64 = r30.s64 + 58;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221369c
	if (cr6.eq) goto loc_8221369C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822131d8
	ctx.lr = 0x8221369C;
	sub_822131D8(ctx, base);
loc_8221369C:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82213718
	if (cr6.eq) goto loc_82213718;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r29,-25232(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822136C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82181530
	ctx.lr = 0x822136D4;
	sub_82181530(ctx, base);
	// lwzx r29,r30,r31
	r29.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822136E0;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82213718
	if (!cr6.eq) goto loc_82213718;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82213718
	if (cr6.eq) goto loc_82213718;
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
	ctx.lr = 0x82213708;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82213718:
	// li r11,0
	r11.s64 = 0;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82213728"))) PPC_WEAK_FUNC(sub_82213728);
PPC_FUNC_IMPL(__imp__sub_82213728) {
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
	ctx.lr = 0x82213730;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	r27.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,232
	r30.s64 = r31.s64 + 232;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_8221374C:
	// lwz r10,176(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// cmplw cr6,r10,r29
	cr6.compare<uint32_t>(ctx.r10.u32, r29.u32, xer);
	// bne cr6,0x822137a0
	if (!cr6.eq) goto loc_822137A0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r27,176(r30)
	PPC_STORE_U32(r30.u32 + 176, r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82213774
	if (cr6.eq) goto loc_82213774;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822131d8
	ctx.lr = 0x82213774;
	sub_822131D8(ctx, base);
loc_82213774:
	// lwz r3,-220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -220);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8221379c
	if (cr6.eq) goto loc_8221379C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8221379c
	if (cr6.eq) goto loc_8221379C;
	// bl 0x8218f8d0
	ctx.lr = 0x8221379C;
	sub_8218F8D0(ctx, base);
loc_8221379C:
	// li r11,1
	r11.s64 = 1;
loc_822137A0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r28,44
	cr6.compare<int32_t>(r28.s32, 44, xer);
	// blt cr6,0x8221374c
	if (cr6.lt) goto loc_8221374C;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822137f8
	if (!cr6.eq) goto loc_822137F8;
	// lhz r11,592(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 592);
	// li r10,5
	ctx.r10.s64 = 5;
	// lwz r8,588(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// stb r27,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r27.u8);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r31,588
	r11.s64 = r31.s64 + 588;
	// sth r7,592(r31)
	PPC_STORE_U16(r31.u32 + 592, ctx.r7.u16);
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stwx r6,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r6.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r29.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_822137F8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82213800"))) PPC_WEAK_FUNC(sub_82213800);
PPC_FUNC_IMPL(__imp__sub_82213800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82213808;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// li r30,44
	r30.s64 = 44;
	// addi r31,r22,408
	r31.s64 = r22.s64 + 408;
	// lis r23,12288
	r23.s64 = 805306368;
loc_8221381C:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82213840
	if (cr6.eq) goto loc_82213840;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r10,r11,0,2,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r10,r23
	cr6.compare<int32_t>(ctx.r10.s32, r23.s32, xer);
	// bne cr6,0x82213840
	if (!cr6.eq) goto loc_82213840;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82213728
	ctx.lr = 0x82213840;
	sub_82213728(ctx, base);
loc_82213840:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8221381c
	if (!cr0.eq) goto loc_8221381C;
	// lhz r11,592(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 592);
	// li r25,0
	r25.s64 = 0;
	// mr r24,r25
	r24.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822139a8
	if (cr6.eq) goto loc_822139A8;
	// addi r26,r22,588
	r26.s64 = r22.s64 + 588;
	// mr r27,r25
	r27.u64 = r25.u64;
loc_82213868:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x822138a4
	if (!cr6.eq) goto loc_822138A4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r9,r23
	cr6.compare<int32_t>(ctx.r9.s32, r23.s32, xer);
	// bne cr6,0x822138a4
	if (!cr6.eq) goto loc_822138A4;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// stbx r25,r11,r27
	PPC_STORE_U8(r11.u32 + r27.u32, r25.u8);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// stw r25,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r25.u32);
loc_822138A4:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82213994
	if (!cr6.eq) goto loc_82213994;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt cr6,0x82213994
	if (cr6.gt) goto loc_82213994;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwinm r28,r10,0,2,3
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x30000000;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82213984
	if (cr6.eq) goto loc_82213984;
	// lwz r31,12(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82213918
	if (cr6.eq) goto loc_82213918;
loc_822138F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221390C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822138f8
	if (!cr6.eq) goto loc_822138F8;
loc_82213918:
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,40
	r31.s64 = 40;
	// cmpw cr6,r28,r23
	cr6.compare<int32_t>(r28.s32, r23.s32, xer);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// bne cr6,0x82213960
	if (!cr6.eq) goto loc_82213960;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x82213968
	if (!cr0.eq) goto loc_82213968;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221395C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82213968
	goto loc_82213968;
loc_82213960:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e5598
	ctx.lr = 0x82213968;
	sub_821E5598(ctx, base);
loc_82213968:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// stw r25,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r25.u32);
	// bl 0x821e2808
	ctx.lr = 0x82213984;
	sub_821E2808(ctx, base);
loc_82213984:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82212f78
	ctx.lr = 0x82213990;
	sub_82212F78(ctx, base);
	// b 0x8221399c
	goto loc_8221399C;
loc_82213994:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r27,r27,12
	r27.s64 = r27.s64 + 12;
loc_8221399C:
	// lhz r11,592(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 592);
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82213868
	if (cr6.lt) goto loc_82213868;
loc_822139A8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_822139B0"))) PPC_WEAK_FUNC(sub_822139B0);
PPC_FUNC_IMPL(__imp__sub_822139B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// li r9,44
	ctx.r9.s64 = 44;
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, r11.u8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822139D0:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822139d0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822139D0;
	// addi r10,r3,232
	ctx.r10.s64 = ctx.r3.s64 + 232;
	// li r9,44
	ctx.r9.s64 = 44;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822139E8:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822139e8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822139E8;
	// addi r10,r3,408
	ctx.r10.s64 = ctx.r3.s64 + 408;
	// li r9,44
	ctx.r9.s64 = 44;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82213A00:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82213a00
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82213A00;
	// stw r11,584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 584, r11.u32);
	// stw r11,588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 588, r11.u32);
	// sth r11,592(r3)
	PPC_STORE_U16(ctx.r3.u32 + 592, r11.u16);
	// sth r11,594(r3)
	PPC_STORE_U16(ctx.r3.u32 + 594, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82213A20"))) PPC_WEAK_FUNC(sub_82213A20);
PPC_FUNC_IMPL(__imp__sub_82213A20) {
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
	// lwz r31,584(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 584);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82213a74
	if (cr6.eq) goto loc_82213A74;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82213A4C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82213a74
	if (!cr6.eq) goto loc_82213A74;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82213a74
	if (cr6.eq) goto loc_82213A74;
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
	ctx.lr = 0x82213A74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82213A74:
	// lhz r11,594(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 594);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82213a88
	if (cr6.eq) goto loc_82213A88;
	// lwz r3,588(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 588);
	// bl 0x82130588
	ctx.lr = 0x82213A88;
	sub_82130588(ctx, base);
loc_82213A88:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82138a18
	ctx.lr = 0x82213A90;
	sub_82138A18(ctx, base);
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

__attribute__((alias("__imp__sub_82213AA8"))) PPC_WEAK_FUNC(sub_82213AA8);
PPC_FUNC_IMPL(__imp__sub_82213AA8) {
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
	ctx.lr = 0x82213AB0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x82213b64
	if (!cr6.eq) goto loc_82213B64;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,68
	r25.s64 = 68;
	// lwz r24,0(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r30,r31,r25
	PPC_STORE_U32(r31.u32 + r25.u32, r30.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821bc6b8
	ctx.lr = 0x82213AE8;
	sub_821BC6B8(ctx, base);
	// li r28,60
	r28.s64 = 60;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lwzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// li r27,0
	r27.s64 = 0;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// stb r27,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r27.u8);
	// stwx r9,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, ctx.r9.u32);
	// lwz r11,23572(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 23572);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,23572(r29)
	PPC_STORE_U32(r29.u32 + 23572, r11.u32);
	// beq cr6,0x82213b30
	if (cr6.eq) goto loc_82213B30;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82193090
	ctx.lr = 0x82213B30;
	sub_82193090(ctx, base);
loc_82213B30:
	// sth r27,2(r26)
	PPC_STORE_U16(r26.u32 + 2, r27.u16);
	// lis r4,12288
	ctx.r4.s64 = 805306368;
	// sth r27,0(r26)
	PPC_STORE_U16(r26.u32 + 0, r27.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2808
	ctx.lr = 0x82213B44;
	sub_821E2808(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8276d240
	ctx.lr = 0x82213B4C;
	sub_8276D240(ctx, base);
	// lwz r11,23572(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 23572);
	// stwx r27,r31,r25
	PPC_STORE_U32(r31.u32 + r25.u32, r27.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r29)
	PPC_STORE_U32(r29.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, r11.u32);
loc_82213B64:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82213B6C"))) PPC_WEAK_FUNC(sub_82213B6C);
PPC_FUNC_IMPL(__imp__sub_82213B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82213B70"))) PPC_WEAK_FUNC(sub_82213B70);
PPC_FUNC_IMPL(__imp__sub_82213B70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82213aa8
	sub_82213AA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82213B7C"))) PPC_WEAK_FUNC(sub_82213B7C);
PPC_FUNC_IMPL(__imp__sub_82213B7C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82213B80"))) PPC_WEAK_FUNC(sub_82213B80);
PPC_FUNC_IMPL(__imp__sub_82213B80) {
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
	ctx.lr = 0x82213B88;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r5,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r5.u32);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r4,r1,180
	ctx.r4.s64 = ctx.r1.s64 + 180;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823c95b0
	ctx.lr = 0x82213BA0;
	sub_823C95B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82213cf8
	if (cr6.eq) goto loc_82213CF8;
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82213cf8
	if (cr6.lt) goto loc_82213CF8;
	// addi r11,r27,102
	r11.s64 = r27.s64 + 102;
	// rlwinm r26,r11,2,0,29
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r26,r31
	r11.u64 = PPC_LOAD_U32(r26.u32 + r31.u32);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x82213cf8
	if (cr6.eq) goto loc_82213CF8;
	// addi r10,r27,58
	ctx.r10.s64 = r27.s64 + 58;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// beq cr6,0x82213cf8
	if (cr6.eq) goto loc_82213CF8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82213bf4
	if (cr6.eq) goto loc_82213BF4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822130e0
	ctx.lr = 0x82213BF4;
	sub_822130E0(ctx, base);
loc_82213BF4:
	// lhz r10,592(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 592);
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82213c50
	if (!cr6.gt) goto loc_82213C50;
	// lwz r9,588(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// addi r3,r31,588
	ctx.r3.s64 = r31.s64 + 588;
	// addi r11,r9,8
	r11.s64 = ctx.r9.s64 + 8;
loc_82213C18:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// beq cr6,0x82213c38
	if (cr6.eq) goto loc_82213C38;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// blt cr6,0x82213c18
	if (cr6.lt) goto loc_82213C18;
	// b 0x82213c50
	goto loc_82213C50;
loc_82213C38:
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// li r29,1
	r29.s64 = 1;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r28,r10,r9
	r28.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82212f78
	ctx.lr = 0x82213C50;
	sub_82212F78(ctx, base);
loc_82213C50:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82213c80
	if (cr6.eq) goto loc_82213C80;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82213cf4
	if (!cr6.eq) goto loc_82213CF4;
loc_82213C68:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822132d0
	ctx.lr = 0x82213C78;
	sub_822132D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82213C80:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,232
	r11.s64 = r31.s64 + 232;
loc_82213C88:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// beq cr6,0x82213c68
	if (cr6.eq) goto loc_82213C68;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,44
	cr6.compare<int32_t>(ctx.r10.s32, 44, xer);
	// blt cr6,0x82213c88
	if (cr6.lt) goto loc_82213C88;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,408
	r11.s64 = r31.s64 + 408;
loc_82213CAC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// beq cr6,0x82213cf4
	if (cr6.eq) goto loc_82213CF4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,44
	cr6.compare<int32_t>(ctx.r10.s32, 44, xer);
	// blt cr6,0x82213cac
	if (cr6.lt) goto loc_82213CAC;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r10,r11,0,2,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82213cf8
	if (!cr6.eq) goto loc_82213CF8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r10,15216
	ctx.r5.s64 = ctx.r10.s64 + 15216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821e27d8
	ctx.lr = 0x82213CF4;
	sub_821E27D8(ctx, base);
loc_82213CF4:
	// stwx r30,r26,r31
	PPC_STORE_U32(r26.u32 + r31.u32, r30.u32);
loc_82213CF8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82213D00"))) PPC_WEAK_FUNC(sub_82213D00);
PPC_FUNC_IMPL(__imp__sub_82213D00) {
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
	ctx.lr = 0x82213D08;
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// li r25,0
	r25.s64 = 0;
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// mr r24,r25
	r24.u64 = r25.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x82213e34
	if (!cr6.gt) goto loc_82213E34;
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82213D4C:
	// addi r11,r27,7
	r11.s64 = r27.s64 + 7;
	// lhz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r30,r25
	r30.u64 = r25.u64;
	// addi r27,r11,8
	r27.s64 = r11.s64 + 8;
	// mr r28,r25
	r28.u64 = r25.u64;
	// lwz r26,4(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821e49e0
	ctx.lr = 0x82213D70;
	sub_821E49E0(ctx, base);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stbx r25,r3,r9
	PPC_STORE_U8(ctx.r3.u32 + ctx.r9.u32, r25.u8);
	// beq cr6,0x82213e08
	if (cr6.eq) goto loc_82213E08;
	// mr r29,r26
	r29.u64 = r26.u64;
loc_82213D8C:
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpwi cr6,r8,10
	cr6.compare<int32_t>(ctx.r8.s32, 10, xer);
	// beq cr6,0x82213e08
	if (cr6.eq) goto loc_82213E08;
	// cmpwi cr6,r8,13
	cr6.compare<int32_t>(ctx.r8.s32, 13, xer);
	// beq cr6,0x82213e08
	if (cr6.eq) goto loc_82213E08;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82213dbc
	if (!cr6.eq) goto loc_82213DBC;
	// extsb r7,r23
	ctx.r7.s64 = r23.s8;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// beq cr6,0x82213e08
	if (cr6.eq) goto loc_82213E08;
loc_82213DBC:
	// cmplwi cr6,r11,34
	cr6.compare<uint32_t>(r11.u32, 34, xer);
	// bne cr6,0x82213dd0
	if (!cr6.eq) goto loc_82213DD0;
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r28,r11,27,31,31
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x82213de8
	goto loc_82213DE8;
loc_82213DD0:
	// addi r11,r21,-1
	r11.s64 = r21.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82213de8
	if (!cr6.lt) goto loc_82213DE8;
	// sth r10,0(r29)
	PPC_STORE_U16(r29.u32 + 0, ctx.r10.u16);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
loc_82213DE8:
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lhz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// bl 0x821e49e0
	ctx.lr = 0x82213DF8;
	sub_821E49E0(ctx, base);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82213d8c
	if (!cr6.eq) goto loc_82213D8C;
loc_82213E08:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r10,r23
	ctx.r10.s64 = r23.s8;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// sthx r25,r11,r26
	PPC_STORE_U16(r11.u32 + r26.u32, r25.u16);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// bne cr6,0x82213e34
	if (!cr6.eq) goto loc_82213E34;
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// cmpw cr6,r24,r22
	cr6.compare<int32_t>(r24.s32, r22.s32, xer);
	// blt cr6,0x82213d4c
	if (cr6.lt) goto loc_82213D4C;
loc_82213E34:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82213E40"))) PPC_WEAK_FUNC(sub_82213E40);
PPC_FUNC_IMPL(__imp__sub_82213E40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f13,1540(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1540);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f11,1532(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1532);
	ctx.f11.f64 = double(temp.f32);
	// lwz r10,1524(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1524);
	// lfs f12,1544(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1544);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f10,1536(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1536);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f8,f10,f12
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// lfs f7,1472(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1472);
	ctx.f7.f64 = double(temp.f32);
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f6,1468(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1468);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,1480(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1480);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,1476(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1476);
	ctx.f4.f64 = double(temp.f32);
	// fadds f3,f5,f7
	ctx.f3.f64 = double(float(ctx.f5.f64 + ctx.f7.f64));
	// fadds f2,f4,f6
	ctx.f2.f64 = double(float(ctx.f4.f64 + ctx.f6.f64));
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f0,f8,f0
	f0.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmadds f11,f6,f13,f1
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f1.f64));
	// fmadds f9,f2,f13,f1
	ctx.f9.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f1.f64));
	// fmadds f10,f3,f12,f0
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 + f0.f64));
	// fmadds f8,f7,f12,f0
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + f0.f64));
	// fctiwz f7,f11
	ctx.f7.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f7.u64);
	// fctiwz f5,f9
	ctx.f5.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f5.u64);
	// fctiwz f6,f10
	ctx.f6.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f6,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f6.u64);
	// lwz r9,-28(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	// fctiwz f4,f8
	ctx.f4.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// lwz r8,-20(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -20);
	// stfd f4,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f4.u64);
	// lwz r7,-12(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r6,-20(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -20);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stw r7,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r7.u32);
	// lwz r5,1524(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1524);
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// stw r6,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82213EE4"))) PPC_WEAK_FUNC(sub_82213EE4);
PPC_FUNC_IMPL(__imp__sub_82213EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82213EE8"))) PPC_WEAK_FUNC(sub_82213EE8);
PPC_FUNC_IMPL(__imp__sub_82213EE8) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82213f14
	if (!cr6.eq) goto loc_82213F14;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-17560
	ctx.r3.s64 = r11.s64 + -17560;
loc_82213F14:
	// bl 0x825f1ff8
	ctx.lr = 0x82213F18;
	sub_825F1FF8(ctx, base);
	// stw r3,1528(r31)
	PPC_STORE_U32(r31.u32 + 1528, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82213F30"))) PPC_WEAK_FUNC(sub_82213F30);
PPC_FUNC_IMPL(__imp__sub_82213F30) {
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
	ctx.lr = 0x82213F38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// addic. r31,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	r31.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// li r28,0
	r28.s64 = 0;
	// ble 0x82213fa4
	if (!cr0.gt) goto loc_82213FA4;
loc_82213F50:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82213F58;
	sub_821BE4F0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x82213fa4
	if (cr6.eq) goto loc_82213FA4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82213F6C;
	sub_821BE4F0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82213fa4
	if (cr6.eq) goto loc_82213FA4;
	// rlwinm r11,r3,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x82213f9c
	if (cr6.eq) goto loc_82213F9C;
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x82213fa4
	if (cr6.eq) goto loc_82213FA4;
loc_82213F9C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x82213f50
	if (cr6.gt) goto loc_82213F50;
loc_82213FA4:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82213FB8"))) PPC_WEAK_FUNC(sub_82213FB8);
PPC_FUNC_IMPL(__imp__sub_82213FB8) {
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
	ctx.lr = 0x82213FC0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,1460(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1460);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82214134
	if (cr6.lt) goto loc_82214134;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,1520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1520);
	f0.f64 = double(temp.f32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82214134
	if (cr6.gt) goto loc_82214134;
	// lfs f13,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82214134
	if (cr6.lt) goto loc_82214134;
	// lbz r11,48(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 48);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r31,1504
	ctx.r4.s64 = r31.s64 + 1504;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82214018
	if (!cr6.eq) goto loc_82214018;
	// addi r4,r31,1488
	ctx.r4.s64 = r31.s64 + 1488;
loc_82214018:
	// bl 0x821d2470
	ctx.lr = 0x8221401C;
	sub_821D2470(ctx, base);
	// lwz r10,1524(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,56(r10)
	PPC_STORE_U32(ctx.r10.u32 + 56, r11.u32);
	// lwz r9,1456(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1456);
	// lwz r11,1460(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1460);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// addi r10,r11,5
	ctx.r10.s64 = r11.s64 + 5;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r9,r31
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// bl 0x8217fff8
	ctx.lr = 0x82214050;
	sub_8217FFF8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8221405C;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x82214068;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x82214074;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x82214080;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8217f768
	ctx.lr = 0x8221408C;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,1552
	ctx.r3.s64 = r31.s64 + 1552;
	// bl 0x8217c658
	ctx.lr = 0x82214098;
	sub_8217C658(ctx, base);
	// lfs f0,1544(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1544);
	f0.f64 = double(temp.f32);
	// lfs f13,1536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1536);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,1472(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1472);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f9,1540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1540);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,1532(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1532);
	ctx.f8.f64 = double(temp.f32);
	// lwz r7,1524(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// lfs f7,1468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1468);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// lfs f0,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f5,f7,f9
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// fmadds f3,f11,f0,f10
	ctx.f3.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f10.f64));
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lfs f4,7444(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7444);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f1,f6,f0,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f5.f64));
	// lfs f2,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// fctiwz f0,f3
	f0.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fmr f3,f4
	ctx.f3.f64 = ctx.f4.f64;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// fctiwz f13,f1
	ctx.f13.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfiwx f13,r7,r5
	PPC_STORE_U32(ctx.r7.u32 + ctx.r5.u32, ctx.f13.u32);
	// lwz r9,1524(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// lwz r3,1528(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1528);
	// bl 0x825f0170
	ctx.lr = 0x82214128;
	sub_825F0170(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217c658
	ctx.lr = 0x82214134;
	sub_8217C658(ctx, base);
loc_82214134:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8221413C"))) PPC_WEAK_FUNC(sub_8221413C);
PPC_FUNC_IMPL(__imp__sub_8221413C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214140"))) PPC_WEAK_FUNC(sub_82214140);
PPC_FUNC_IMPL(__imp__sub_82214140) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,1452(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1452);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,1460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1460, ctx.r10.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,1520(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1520, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82214164"))) PPC_WEAK_FUNC(sub_82214164);
PPC_FUNC_IMPL(__imp__sub_82214164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214168"))) PPC_WEAK_FUNC(sub_82214168);
PPC_FUNC_IMPL(__imp__sub_82214168) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82214170;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,-1
	r11.s64 = -1;
	// li r28,0
	r28.s64 = 0;
	// stw r11,1460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1460, r11.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r3,20
	r29.s64 = ctx.r3.s64 + 20;
	// stw r28,1452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1452, r28.u32);
	// li r27,35
	r27.s64 = 35;
	// lfs f31,-6432(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6432);
	f31.f64 = double(temp.f32);
loc_82214198:
	// lfs f0,-8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x822141cc
	if (cr6.eq) goto loc_822141CC;
	// mr r31,r29
	r31.u64 = r29.u64;
	// li r30,7
	r30.s64 = 7;
loc_822141AC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822141c0
	if (cr6.eq) goto loc_822141C0;
	// bl 0x82130588
	ctx.lr = 0x822141BC;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_822141C0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822141ac
	if (!cr0.eq) goto loc_822141AC;
loc_822141CC:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,40
	r29.s64 = r29.s64 + 40;
	// bne 0x82214198
	if (!cr0.eq) goto loc_82214198;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822141E4"))) PPC_WEAK_FUNC(sub_822141E4);
PPC_FUNC_IMPL(__imp__sub_822141E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822141E8"))) PPC_WEAK_FUNC(sub_822141E8);
PPC_FUNC_IMPL(__imp__sub_822141E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,1460(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1460);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwz r10,1452(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1452);
	// lfs f13,1520(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1520);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r9,29952
	ctx.r8.s64 = ctx.r9.s64 + 29952;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// lfs f0,92(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 92);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,1520(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1520, temp.u32);
	// blt cr6,0x8221423c
	if (cr6.lt) goto loc_8221423C;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lfs f13,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// b 0x82214168
	sub_82214168(ctx, base);
	return;
loc_8221423C:
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lfs f13,52(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1460, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82214260"))) PPC_WEAK_FUNC(sub_82214260);
PPC_FUNC_IMPL(__imp__sub_82214260) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-6428
	ctx.r3.s64 = r11.s64 + -6428;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8221426C"))) PPC_WEAK_FUNC(sub_8221426C);
PPC_FUNC_IMPL(__imp__sub_8221426C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214270"))) PPC_WEAK_FUNC(sub_82214270);
PPC_FUNC_IMPL(__imp__sub_82214270) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-25632
	ctx.r5.s64 = r11.s64 + -25632;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1468
	ctx.r6.s64 = r31.s64 + 1468;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x822142AC;
	sub_824DF200(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-6396
	ctx.r5.s64 = ctx.r10.s64 + -6396;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1488
	ctx.r6.s64 = r31.s64 + 1488;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822142CC;
	sub_824DF200(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r9,-6412
	ctx.r5.s64 = ctx.r9.s64 + -6412;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1504
	ctx.r6.s64 = r31.s64 + 1504;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x822142EC;
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

__attribute__((alias("__imp__sub_82214304"))) PPC_WEAK_FUNC(sub_82214304);
PPC_FUNC_IMPL(__imp__sub_82214304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214308"))) PPC_WEAK_FUNC(sub_82214308);
PPC_FUNC_IMPL(__imp__sub_82214308) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,-6380
	ctx.r10.s64 = r11.s64 + -6380;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82214168
	ctx.lr = 0x8221432C;
	sub_82214168(ctx, base);
	// lwz r3,1524(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// bl 0x82130588
	ctx.lr = 0x82214334;
	sub_82130588(ctx, base);
	// lwz r3,1528(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1528);
	// bl 0x825f1de0
	ctx.lr = 0x8221433C;
	sub_825F1DE0(ctx, base);
	// addi r3,r31,1552
	ctx.r3.s64 = r31.s64 + 1552;
	// bl 0x8217cb48
	ctx.lr = 0x82214344;
	sub_8217CB48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0430
	ctx.lr = 0x8221434C;
	sub_824E0430(ctx, base);
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

__attribute__((alias("__imp__sub_82214360"))) PPC_WEAK_FUNC(sub_82214360);
PPC_FUNC_IMPL(__imp__sub_82214360) {
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
	// cmpw cr6,r6,r4
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, xer);
	// ble cr6,0x82214378
	if (!cr6.gt) goto loc_82214378;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
loc_82214378:
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// ble cr6,0x82214384
	if (!cr6.gt) goto loc_82214384;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
loc_82214384:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x82214390
	if (!cr6.eq) goto loc_82214390;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
loc_82214390:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x8221439c
	if (!cr6.eq) goto loc_8221439C;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
loc_8221439C:
	// extsw r11,r7
	r11.s64 = ctx.r7.s32;
	// extsw r10,r5
	ctx.r10.s64 = ctx.r5.s32;
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r8,r6
	ctx.r8.s64 = ctx.r6.s32;
	// fcfid f7,f0
	ctx.f7.f64 = double(f0.s64);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// frsp f6,f10
	ctx.f6.f64 = double(float(ctx.f10.f64));
	// stfs f6,1540(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1540, temp.u32);
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// stfs f3,1544(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1544, temp.u32);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// stfs f5,1536(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1536, temp.u32);
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// stfs f4,1532(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1532, temp.u32);
	// bl 0x82213e40
	ctx.lr = 0x82214400;
	sub_82213E40(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82214410"))) PPC_WEAK_FUNC(sub_82214410);
PPC_FUNC_IMPL(__imp__sub_82214410) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82214418;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d8
	ctx.lr = 0x82214420;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -12288);
	// stwu r1,-12544(r1)
	ea = -12544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// addi r3,r11,-6212
	ctx.r3.s64 = r11.s64 + -6212;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82130000
	ctx.lr = 0x82214444;
	sub_82130000(ctx, base);
	// lwz r10,1460(r14)
	ctx.r10.u64 = PPC_LOAD_U32(r14.u32 + 1460);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x82214458
	if (cr6.eq) goto loc_82214458;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x82214168
	ctx.lr = 0x82214458;
	sub_82214168(ctx, base);
loc_82214458:
	// li r11,-1
	r11.s64 = -1;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stw r11,1460(r14)
	PPC_STORE_U32(r14.u32 + 1460, r11.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - r31.s64;
loc_8221446C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r11,r10
	PPC_STORE_U8(r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8221446c
	if (!cr6.eq) goto loc_8221446C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-6220
	ctx.r4.s64 = r11.s64 + -6220;
	// bl 0x823d90b0
	ctx.lr = 0x82214490;
	sub_823D90B0(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822144b4
	if (!cr6.eq) goto loc_822144B4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-6228
	ctx.r4.s64 = r11.s64 + -6228;
	// bl 0x823d90b0
	ctx.lr = 0x822144AC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822144e0
	if (cr6.eq) goto loc_822144E0;
loc_822144B4:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_822144B8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822144b8
	if (!cr6.eq) goto loc_822144B8;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stb r25,-4(r10)
	PPC_STORE_U8(ctx.r10.u32 + -4, r25.u8);
loc_822144E0:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// addi r5,r10,-6232
	ctx.r5.s64 = ctx.r10.s64 + -6232;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// bl 0x821ca6a8
	ctx.lr = 0x82214504;
	sub_821CA6A8(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x82214538
	if (!cr6.eq) goto loc_82214538;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,-6236
	ctx.r5.s64 = r11.s64 + -6236;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// bl 0x821ca6a8
	ctx.lr = 0x8221452C;
	sub_821CA6A8(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x8221453c
	goto loc_8221453C;
loc_82214538:
	// li r11,1
	r11.s64 = 1;
loc_8221453C:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x82214aa8
	if (cr6.eq) goto loc_82214AA8;
	// clrlwi r15,r11,24
	r15.u64 = r11.u32 & 0xFF;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x82214564
	if (cr6.eq) goto loc_82214564;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// addi r3,r1,8256
	ctx.r3.s64 = ctx.r1.s64 + 8256;
	// bl 0x82213f30
	ctx.lr = 0x82214560;
	sub_82213F30(ctx, base);
	// b 0x82214570
	goto loc_82214570;
loc_82214564:
	// li r4,2048
	ctx.r4.s64 = 2048;
	// addi r3,r1,6208
	ctx.r3.s64 = ctx.r1.s64 + 6208;
	// bl 0x821be990
	ctx.lr = 0x82214570;
	sub_821BE990(ctx, base);
loc_82214570:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,32767
	ctx.r6.s64 = 2147418112;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f29,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lfs f28,-26872(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -26872);
	f28.f64 = double(temp.f32);
	// mr r21,r25
	r21.u64 = r25.u64;
	// mr r19,r25
	r19.u64 = r25.u64;
	// addi r26,r14,16
	r26.s64 = r14.s64 + 16;
	// li r23,46
	r23.s64 = 46;
	// ori r27,r6,65535
	r27.u64 = ctx.r6.u64 | 65535;
	// li r24,-1
	r24.s64 = -1;
	// addi r22,r11,-6276
	r22.s64 = r11.s64 + -6276;
	// addi r18,r10,-6248
	r18.s64 = ctx.r10.s64 + -6248;
	// addi r17,r9,-6268
	r17.s64 = ctx.r9.s64 + -6268;
	// addi r16,r8,-6308
	r16.s64 = ctx.r8.s64 + -6308;
loc_822145BC:
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// beq cr6,0x822145dc
	if (cr6.eq) goto loc_822145DC;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// addi r3,r1,8256
	ctx.r3.s64 = ctx.r1.s64 + 8256;
	// bl 0x82213f30
	ctx.lr = 0x822145D4;
	sub_82213F30(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// b 0x822145e8
	goto loc_822145E8;
loc_822145DC:
	// li r4,2048
	ctx.r4.s64 = 2048;
	// addi r3,r1,6208
	ctx.r3.s64 = ctx.r1.s64 + 6208;
	// bl 0x821be990
	ctx.lr = 0x822145E8;
	sub_821BE990(ctx, base);
loc_822145E8:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82214a88
	if (cr6.eq) goto loc_82214A88;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x82214604
	if (cr6.eq) goto loc_82214604;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// beq cr6,0x82214a88
	if (cr6.eq) goto loc_82214A88;
	// b 0x82214654
	goto loc_82214654;
loc_82214604:
	// addi r11,r1,6208
	r11.s64 = ctx.r1.s64 + 6208;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8221460C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8221460c
	if (!cr6.eq) goto loc_8221460C;
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// mr r11,r25
	r11.u64 = r25.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82214654
	if (!cr6.gt) goto loc_82214654;
	// addi r10,r1,8256
	ctx.r10.s64 = ctx.r1.s64 + 8256;
loc_82214638:
	// addi r8,r1,6208
	ctx.r8.s64 = ctx.r1.s64 + 6208;
	// lbzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// sth r6,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r6.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// blt cr6,0x82214638
	if (cr6.lt) goto loc_82214638;
loc_82214654:
	// sth r25,5184(r1)
	PPC_STORE_U16(ctx.r1.u32 + 5184, r25.u16);
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// sth r25,5696(r1)
	PPC_STORE_U16(ctx.r1.u32 + 5696, r25.u16);
	// addi r11,r1,4416
	r11.s64 = ctx.r1.s64 + 4416;
	// sth r25,3904(r1)
	PPC_STORE_U16(ctx.r1.u32 + 3904, r25.u16);
	// addi r10,r1,1344
	ctx.r10.s64 = ctx.r1.s64 + 1344;
	// sth r25,2880(r1)
	PPC_STORE_U16(ctx.r1.u32 + 2880, r25.u16);
	// li r6,256
	ctx.r6.s64 = 256;
	// sth r25,1856(r1)
	PPC_STORE_U16(ctx.r1.u32 + 1856, r25.u16);
	// addi r4,r1,8256
	ctx.r4.s64 = ctx.r1.s64 + 8256;
	// sth r25,3392(r1)
	PPC_STORE_U16(ctx.r1.u32 + 3392, r25.u16);
	// sth r25,832(r1)
	PPC_STORE_U16(ctx.r1.u32 + 832, r25.u16);
	// sth r25,1344(r1)
	PPC_STORE_U16(ctx.r1.u32 + 1344, r25.u16);
	// sth r25,4416(r1)
	PPC_STORE_U16(ctx.r1.u32 + 4416, r25.u16);
	// sth r25,2368(r1)
	PPC_STORE_U16(ctx.r1.u32 + 2368, r25.u16);
	// beq cr6,0x822146d4
	if (cr6.eq) goto loc_822146D4;
	// addi r9,r1,5184
	ctx.r9.s64 = ctx.r1.s64 + 5184;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r8,r1,3904
	ctx.r8.s64 = ctx.r1.s64 + 3904;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// addi r7,r1,2880
	ctx.r7.s64 = ctx.r1.s64 + 2880;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r10,r1,1856
	ctx.r10.s64 = ctx.r1.s64 + 1856;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r9,r1,3392
	ctx.r9.s64 = ctx.r1.s64 + 3392;
	// addi r8,r1,832
	ctx.r8.s64 = ctx.r1.s64 + 832;
	// addi r7,r1,2368
	ctx.r7.s64 = ctx.r1.s64 + 2368;
	// li r5,10
	ctx.r5.s64 = 10;
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82213d00
	ctx.lr = 0x822146D0;
	sub_82213D00(ctx, base);
	// b 0x82214708
	goto loc_82214708;
loc_822146D4:
	// addi r9,r1,3904
	ctx.r9.s64 = ctx.r1.s64 + 3904;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// addi r8,r1,2880
	ctx.r8.s64 = ctx.r1.s64 + 2880;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r10,r1,1856
	ctx.r10.s64 = ctx.r1.s64 + 1856;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r9,r1,3392
	ctx.r9.s64 = ctx.r1.s64 + 3392;
	// addi r8,r1,832
	ctx.r8.s64 = ctx.r1.s64 + 832;
	// addi r7,r1,2368
	ctx.r7.s64 = ctx.r1.s64 + 2368;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82213d00
	ctx.lr = 0x82214708;
	sub_82213D00(ctx, base);
loc_82214708:
	// addi r3,r1,2368
	ctx.r3.s64 = ctx.r1.s64 + 2368;
	// bl 0x823de3a8
	ctx.lr = 0x82214710;
	sub_823DE3A8(ctx, base);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// addi r4,r1,2368
	ctx.r4.s64 = ctx.r1.s64 + 2368;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x821e4958
	ctx.lr = 0x82214720;
	sub_821E4958(ctx, base);
	// addi r3,r1,4416
	ctx.r3.s64 = ctx.r1.s64 + 4416;
	// bl 0x823de3a8
	ctx.lr = 0x82214728;
	sub_823DE3A8(ctx, base);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// addi r4,r1,4416
	ctx.r4.s64 = ctx.r1.s64 + 4416;
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// bl 0x821e4958
	ctx.lr = 0x82214738;
	sub_821E4958(ctx, base);
	// addi r3,r1,1344
	ctx.r3.s64 = ctx.r1.s64 + 1344;
	// bl 0x823de3a8
	ctx.lr = 0x82214740;
	sub_823DE3A8(ctx, base);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// addi r4,r1,1344
	ctx.r4.s64 = ctx.r1.s64 + 1344;
	// addi r3,r1,4928
	ctx.r3.s64 = ctx.r1.s64 + 4928;
	// bl 0x821e4958
	ctx.lr = 0x82214750;
	sub_821E4958(ctx, base);
	// li r4,58
	ctx.r4.s64 = 58;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x823dd850
	ctx.lr = 0x8221475C;
	sub_823DD850(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,58
	ctx.r4.s64 = 58;
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// bl 0x823dd850
	ctx.lr = 0x8221476C;
	sub_823DD850(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82214794
	if (!cr6.eq) goto loc_82214794;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x823de058
	ctx.lr = 0x82214780;
	sub_823DE058(ctx, base);
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// bl 0x823de058
	ctx.lr = 0x8221478C;
	sub_823DE058(ctx, base);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// b 0x82214844
	goto loc_82214844;
loc_82214794:
	// addi r11,r1,320
	r11.s64 = ctx.r1.s64 + 320;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8221479C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8221479c
	if (!cr6.eq) goto loc_8221479C;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,11
	cr6.compare<uint32_t>(ctx.r10.u32, 11, xer);
	// bne cr6,0x82214a6c
	if (!cr6.eq) goto loc_82214A6C;
	// stb r25,3(r31)
	PPC_STORE_U8(r31.u32 + 3, r25.u8);
	// addi r30,r31,1
	r30.s64 = r31.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823de058
	ctx.lr = 0x822147D0;
	sub_823DE058(ctx, base);
	// stb r23,6(r31)
	PPC_STORE_U8(r31.u32 + 6, r23.u8);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmuls f31,f0,f28
	f31.f64 = double(float(f0.f64 * f28.f64));
	// bl 0x823de058
	ctx.lr = 0x822147E8;
	sub_823DE058(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// addi r11,r1,576
	r11.s64 = ctx.r1.s64 + 576;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// fadds f30,f13,f31
	f30.f64 = double(float(ctx.f13.f64 + f31.f64));
loc_822147F8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822147f8
	if (!cr6.eq) goto loc_822147F8;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,11
	cr6.compare<uint32_t>(ctx.r10.u32, 11, xer);
	// bne cr6,0x82214a74
	if (!cr6.eq) goto loc_82214A74;
	// stb r25,3(r28)
	PPC_STORE_U8(r28.u32 + 3, r25.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823de058
	ctx.lr = 0x82214828;
	sub_823DE058(ctx, base);
	// stb r23,6(r28)
	PPC_STORE_U8(r28.u32 + 6, r23.u8);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmuls f31,f0,f28
	f31.f64 = double(float(f0.f64 * f28.f64));
	// bl 0x823de058
	ctx.lr = 0x8221483C;
	sub_823DE058(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fadds f31,f13,f31
	f31.f64 = double(float(ctx.f13.f64 + f31.f64));
loc_82214844:
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x823def80
	ctx.lr = 0x82214850;
	sub_823DEF80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82214860
	if (!cr6.eq) goto loc_82214860;
	// fadds f29,f30,f29
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(f30.f64 + f29.f64));
	// b 0x822145bc
	goto loc_822145BC;
loc_82214860:
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x823def80
	ctx.lr = 0x8221486C;
	sub_823DEF80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82214888
	if (!cr6.eq) goto loc_82214888;
	// stfs f30,1468(r14)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r14.u32 + 1468, temp.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// stfs f31,1472(r14)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r14.u32 + 1472, temp.u32);
	// bl 0x82213e40
	ctx.lr = 0x82214884;
	sub_82213E40(ctx, base);
	// b 0x822145bc
	goto loc_822145BC;
loc_82214888:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x823def80
	ctx.lr = 0x82214894;
	sub_823DEF80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822148b0
	if (!cr6.eq) goto loc_822148B0;
	// stfs f30,1476(r14)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r14.u32 + 1476, temp.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// stfs f31,1480(r14)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r14.u32 + 1480, temp.u32);
	// bl 0x82213e40
	ctx.lr = 0x822148AC;
	sub_82213E40(ctx, base);
	// b 0x822145bc
	goto loc_822145BC;
loc_822148B0:
	// fadds f0,f30,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 + f29.f64));
	// stfs f0,-4(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + -4, temp.u32);
	// fadds f13,f31,f29
	ctx.f13.f64 = double(float(f31.f64 + f29.f64));
	// stfs f13,0(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x823de3a8
	ctx.lr = 0x822148C8;
	sub_823DE3A8(ctx, base);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x822148e0
	if (!cr6.gt) goto loc_822148E0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_822148E0:
	// bl 0x82130528
	ctx.lr = 0x822148E4;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,832
	ctx.r4.s64 = ctx.r1.s64 + 832;
	// bl 0x823da950
	ctx.lr = 0x822148F0;
	sub_823DA950(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,3904
	ctx.r3.s64 = ctx.r1.s64 + 3904;
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// bl 0x823de3a8
	ctx.lr = 0x82214900;
	sub_823DE3A8(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x82214918
	if (!cr6.gt) goto loc_82214918;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82214918:
	// bl 0x82130528
	ctx.lr = 0x8221491C;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,3904
	ctx.r4.s64 = ctx.r1.s64 + 3904;
	// bl 0x823da950
	ctx.lr = 0x82214928;
	sub_823DA950(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,3392
	ctx.r3.s64 = ctx.r1.s64 + 3392;
	// stw r11,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r11.u32);
	// bl 0x823de3a8
	ctx.lr = 0x82214938;
	sub_823DE3A8(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x82214950
	if (!cr6.gt) goto loc_82214950;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82214950:
	// bl 0x82130528
	ctx.lr = 0x82214954;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,3392
	ctx.r4.s64 = ctx.r1.s64 + 3392;
	// bl 0x823da950
	ctx.lr = 0x82214960;
	sub_823DA950(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,1856
	ctx.r3.s64 = ctx.r1.s64 + 1856;
	// stw r11,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r11.u32);
	// bl 0x823de3a8
	ctx.lr = 0x82214970;
	sub_823DE3A8(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x82214988
	if (!cr6.gt) goto loc_82214988;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82214988:
	// bl 0x82130528
	ctx.lr = 0x8221498C;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,1856
	ctx.r4.s64 = ctx.r1.s64 + 1856;
	// bl 0x823da950
	ctx.lr = 0x82214998;
	sub_823DA950(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,2880
	ctx.r3.s64 = ctx.r1.s64 + 2880;
	// stw r11,16(r26)
	PPC_STORE_U32(r26.u32 + 16, r11.u32);
	// bl 0x823de3a8
	ctx.lr = 0x822149A8;
	sub_823DE3A8(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x822149c0
	if (!cr6.gt) goto loc_822149C0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_822149C0:
	// bl 0x82130528
	ctx.lr = 0x822149C4;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,2880
	ctx.r4.s64 = ctx.r1.s64 + 2880;
	// bl 0x823da950
	ctx.lr = 0x822149D0;
	sub_823DA950(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,5696
	ctx.r3.s64 = ctx.r1.s64 + 5696;
	// stw r11,20(r26)
	PPC_STORE_U32(r26.u32 + 20, r11.u32);
	// bl 0x823de3a8
	ctx.lr = 0x822149E0;
	sub_823DE3A8(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x822149f8
	if (!cr6.gt) goto loc_822149F8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_822149F8:
	// bl 0x82130528
	ctx.lr = 0x822149FC;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,5696
	ctx.r4.s64 = ctx.r1.s64 + 5696;
	// bl 0x823da950
	ctx.lr = 0x82214A08;
	sub_823DA950(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,5184
	ctx.r3.s64 = ctx.r1.s64 + 5184;
	// stw r11,24(r26)
	PPC_STORE_U32(r26.u32 + 24, r11.u32);
	// bl 0x823de3a8
	ctx.lr = 0x82214A18;
	sub_823DE3A8(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x82214a30
	if (!cr6.gt) goto loc_82214A30;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82214A30:
	// bl 0x82130528
	ctx.lr = 0x82214A34;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,5184
	ctx.r4.s64 = ctx.r1.s64 + 5184;
	// bl 0x823da950
	ctx.lr = 0x82214A40;
	sub_823DA950(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// stw r11,28(r26)
	PPC_STORE_U32(r26.u32 + 28, r11.u32);
	// addi r4,r1,4928
	ctx.r4.s64 = ctx.r1.s64 + 4928;
	// bl 0x823db730
	ctx.lr = 0x82214A54;
	sub_823DB730(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,32(r26)
	PPC_STORE_U8(r26.u32 + 32, ctx.r9.u8);
	// addi r26,r26,40
	r26.s64 = r26.s64 + 40;
	// b 0x822145bc
	goto loc_822145BC;
loc_82214A6C:
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// b 0x82214a78
	goto loc_82214A78;
loc_82214A74:
	// addi r5,r1,576
	ctx.r5.s64 = ctx.r1.s64 + 576;
loc_82214A78:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r11,-6348
	ctx.r3.s64 = r11.s64 + -6348;
	// bl 0x82130000
	ctx.lr = 0x82214A88;
	sub_82130000(ctx, base);
loc_82214A88:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x821be610
	ctx.lr = 0x82214A90;
	sub_821BE610(ctx, base);
	// stw r21,1452(r14)
	PPC_STORE_U32(r14.u32 + 1452, r21.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,12544
	ctx.r1.s64 = ctx.r1.s64 + 12544;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba24
	ctx.lr = 0x82214AA4;
	// b 0x823d9210
	return;
loc_82214AA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,12544
	ctx.r1.s64 = ctx.r1.s64 + 12544;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba24
	ctx.lr = 0x82214AB8;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82214ABC"))) PPC_WEAK_FUNC(sub_82214ABC);
PPC_FUNC_IMPL(__imp__sub_82214ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214AC0"))) PPC_WEAK_FUNC(sub_82214AC0);
PPC_FUNC_IMPL(__imp__sub_82214AC0) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82214AC8;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x82214ADC;
	sub_824E0648(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r31,1552
	r29.s64 = r31.s64 + 1552;
	// addi r10,r11,-6380
	ctx.r10.s64 = r11.s64 + -6380;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8217d5e8
	ctx.lr = 0x82214AF4;
	sub_8217D5E8(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// li r7,35
	ctx.r7.s64 = 35;
	// li r30,0
	r30.s64 = 0;
	// lfs f0,-6432(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6432);
	f0.f64 = double(temp.f32);
loc_82214B08:
	// stfs f0,-36(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -36, temp.u32);
	// addi r10,r11,-28
	ctx.r10.s64 = r11.s64 + -28;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// li r9,7
	ctx.r9.s64 = 7;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82214B20:
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82214b20
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82214B20;
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r11,r11,40
	r11.s64 = r11.s64 + 40;
	// bne 0x82214b08
	if (!cr0.eq) goto loc_82214B08;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r30,1528(r31)
	PPC_STORE_U32(r31.u32 + 1528, r30.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,1452(r31)
	PPC_STORE_U32(r31.u32 + 1452, r30.u32);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r10,1460(r31)
	PPC_STORE_U32(r31.u32 + 1460, ctx.r10.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// stw r9,1464(r31)
	PPC_STORE_U32(r31.u32 + 1464, ctx.r9.u32);
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// stfs f30,1520(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 1520, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x82214B64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82214b74
	if (cr6.eq) goto loc_82214B74;
	// bl 0x825f2128
	ctx.lr = 0x82214B70;
	sub_825F2128(ctx, base);
	// b 0x82214b78
	goto loc_82214B78;
loc_82214B74:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82214B78:
	// stw r3,1524(r31)
	PPC_STORE_U32(r31.u32 + 1524, ctx.r3.u32);
	// li r11,1
	r11.s64 = 1;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r10,1524(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// ori r8,r9,8
	ctx.r8.u64 = ctx.r9.u64 | 8;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r7,1524(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// rlwimi r6,r11,0,29,31
	ctx.r6.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x7) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFF8);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// bl 0x82178848
	ctx.lr = 0x82214BA8;
	sub_82178848(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82214bc0
	if (cr6.eq) goto loc_82214BC0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f10,-6164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6164);
	ctx.f10.f64 = double(temp.f32);
	// b 0x82214bc8
	goto loc_82214BC8;
loc_82214BC0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f10,-6168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6168);
	ctx.f10.f64 = double(temp.f32);
loc_82214BC8:
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r10,1524(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r11,-8092(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-17424(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -17424);
	f0.f64 = double(temp.f32);
	// lfs f13,31308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6172(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -6172);
	ctx.f12.f64 = double(temp.f32);
	// lwz r4,420(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// lfs f11,-6176(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -6176);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,416(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 416);
	// stfs f31,52(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 52, temp.u32);
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f9
	ctx.f6.f64 = double(ctx.f9.s64);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fdivs f2,f3,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 / ctx.f10.f64));
	// stfs f2,48(r10)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 48, temp.u32);
	// stfs f0,1476(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1476, temp.u32);
	// stfs f13,1480(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1480, temp.u32);
	// stfs f12,1468(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1468, temp.u32);
	// stfs f11,1472(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 1472, temp.u32);
	// lwz r11,-8092(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// lwz r4,416(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 416);
	// lwz r5,420(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x82214360
	ctx.lr = 0x82214C68;
	sub_82214360(ctx, base);
	// lwz r11,-8092(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f6,f31
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = f31.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lwz r7,416(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 416);
	// lwz r6,420(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f2,f11
	ctx.f2.f64 = double(float(ctx.f11.f64));
	// frsp f3,f12
	ctx.f3.f64 = double(float(ctx.f12.f64));
	// bl 0x8217cc80
	ctx.lr = 0x82214CB4;
	sub_8217CC80(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stfs f31,1516(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1516, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f31,1488(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1488, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f31,1492(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1492, temp.u32);
	// stfs f31,1496(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1496, temp.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stfs f31,1500(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1500, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-13148(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	f0.f64 = double(temp.f32);
	// addi r4,r8,-6188
	ctx.r4.s64 = ctx.r8.s64 + -6188;
	// lfs f13,32680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32692(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32692);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,1504(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1504, temp.u32);
	// stfs f13,1508(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1508, temp.u32);
	// stfs f12,1512(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1512, temp.u32);
	// bl 0x824e06e0
	ctx.lr = 0x82214CFC;
	sub_824E06E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_82214D10"))) PPC_WEAK_FUNC(sub_82214D10);
PPC_FUNC_IMPL(__imp__sub_82214D10) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-6380
	ctx.r10.s64 = r11.s64 + -6380;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82214168
	ctx.lr = 0x82214D3C;
	sub_82214168(ctx, base);
	// lwz r3,1524(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// bl 0x82130588
	ctx.lr = 0x82214D44;
	sub_82130588(ctx, base);
	// lwz r3,1528(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1528);
	// bl 0x825f1de0
	ctx.lr = 0x82214D4C;
	sub_825F1DE0(ctx, base);
	// addi r3,r31,1552
	ctx.r3.s64 = r31.s64 + 1552;
	// bl 0x8217cb48
	ctx.lr = 0x82214D54;
	sub_8217CB48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0430
	ctx.lr = 0x82214D5C;
	sub_824E0430(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82214d74
	if (cr6.eq) goto loc_82214D74;
	// bl 0x82130588
	ctx.lr = 0x82214D70;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82214D74:
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

__attribute__((alias("__imp__sub_82214D8C"))) PPC_WEAK_FUNC(sub_82214D8C);
PPC_FUNC_IMPL(__imp__sub_82214D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214D90"))) PPC_WEAK_FUNC(sub_82214D90);
PPC_FUNC_IMPL(__imp__sub_82214D90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82214DB0;
	sub_823DBBC8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82214DC0;
	sub_823DBAE8(ctx, base);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v59,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v11,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vspltw128 v57,v59,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvlx128 v56,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vmulfp128 v55,v58,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v63,v57
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// vor128 v10,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v9,v11,v13,v12
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v8,v0,v10
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v7,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82214E44"))) PPC_WEAK_FUNC(sub_82214E44);
PPC_FUNC_IMPL(__imp__sub_82214E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214E48"))) PPC_WEAK_FUNC(sub_82214E48);
PPC_FUNC_IMPL(__imp__sub_82214E48) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-5056
	ctx.r9.s64 = r11.s64 + -5056;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82214e7c
	if (cr6.eq) goto loc_82214E7C;
	// bl 0x82130588
	ctx.lr = 0x82214E78;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82214E7C:
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

__attribute__((alias("__imp__sub_82214E90"))) PPC_WEAK_FUNC(sub_82214E90);
PPC_FUNC_IMPL(__imp__sub_82214E90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r31,r3,68
	r31.s64 = ctx.r3.s64 + 68;
	// addi r10,r11,-5044
	ctx.r10.s64 = r11.s64 + -5044;
	// li r30,6
	r30.s64 = 6;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82214EB8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82214ed8
	if (cr6.eq) goto loc_82214ED8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82214ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82214ED8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82214eb8
	if (!cr0.eq) goto loc_82214EB8;
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

__attribute__((alias("__imp__sub_82214EFC"))) PPC_WEAK_FUNC(sub_82214EFC);
PPC_FUNC_IMPL(__imp__sub_82214EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214F00"))) PPC_WEAK_FUNC(sub_82214F00);
PPC_FUNC_IMPL(__imp__sub_82214F00) {
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
	// bl 0x82214e90
	ctx.lr = 0x82214F20;
	sub_82214E90(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82214f38
	if (cr6.eq) goto loc_82214F38;
	// bl 0x82130588
	ctx.lr = 0x82214F34;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82214F38:
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

__attribute__((alias("__imp__sub_82214F50"))) PPC_WEAK_FUNC(sub_82214F50);
PPC_FUNC_IMPL(__imp__sub_82214F50) {
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
	// bl 0x824ea350
	ctx.lr = 0x82214F90;
	sub_824EA350(ctx, base);
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

__attribute__((alias("__imp__sub_82214FD4"))) PPC_WEAK_FUNC(sub_82214FD4);
PPC_FUNC_IMPL(__imp__sub_82214FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82214FD8"))) PPC_WEAK_FUNC(sub_82214FD8);
PPC_FUNC_IMPL(__imp__sub_82214FD8) {
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
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82214FF0;
	sub_822A39C8(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b0550
	ctx.lr = 0x82214FF8;
	sub_822B0550(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82215008"))) PPC_WEAK_FUNC(sub_82215008);
PPC_FUNC_IMPL(__imp__sub_82215008) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r8,r11,-8880
	ctx.r8.s64 = r11.s64 + -8880;
	// addi r7,r10,-20416
	ctx.r7.s64 = ctx.r10.s64 + -20416;
	// addi r6,r9,-5036
	ctx.r6.s64 = ctx.r9.s64 + -5036;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82215034"))) PPC_WEAK_FUNC(sub_82215034);
PPC_FUNC_IMPL(__imp__sub_82215034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82215038"))) PPC_WEAK_FUNC(sub_82215038);
PPC_FUNC_IMPL(__imp__sub_82215038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// b 0x8227f2c8
	sub_8227F2C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82215048"))) PPC_WEAK_FUNC(sub_82215048);
PPC_FUNC_IMPL(__imp__sub_82215048) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x82215088
	if (cr6.eq) goto loc_82215088;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822150a4
	if (!cr6.gt) goto loc_822150A4;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x82215098
	goto loc_82215098;
loc_82215088:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822150a4
	if (!cr6.gt) goto loc_822150A4;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_82215098:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822150a8
	if (!cr6.eq) goto loc_822150A8;
loc_822150A4:
	// li r11,0
	r11.s64 = 0;
loc_822150A8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822150c8
	if (cr6.eq) goto loc_822150C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x822150BC;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x8232bae8
	ctx.lr = 0x822150C8;
	sub_8232BAE8(ctx, base);
loc_822150C8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822150D8"))) PPC_WEAK_FUNC(sub_822150D8);
PPC_FUNC_IMPL(__imp__sub_822150D8) {
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
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r3,-12640(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12640);
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215114
	if (cr6.eq) goto loc_82215114;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x822151a8
	goto loc_822151A8;
loc_82215114:
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215130
	if (cr6.eq) goto loc_82215130;
	// lbz r11,10(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82215134
	if (cr6.eq) goto loc_82215134;
loc_82215130:
	// li r11,0
	r11.s64 = 0;
loc_82215134:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82215168
	if (!cr6.eq) goto loc_82215168;
	// bl 0x82387a18
	ctx.lr = 0x82215144;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,-12640(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12640);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215168
	if (cr6.eq) goto loc_82215168;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x822151a8
	goto loc_822151A8;
loc_82215168:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lbz r11,-7829(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -7829);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215190
	if (cr6.eq) goto loc_82215190;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lbz r4,-7831(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + -7831);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5b20
	ctx.lr = 0x8221518C;
	sub_822E5B20(ctx, base);
	// lwz r3,-12640(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12640);
loc_82215190:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// stb r11,-7829(r31)
	PPC_STORE_U8(r31.u32 + -7829, r11.u8);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822151A8:
	// bctrl 
	ctx.lr = 0x822151AC;
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

__attribute__((alias("__imp__sub_822151C4"))) PPC_WEAK_FUNC(sub_822151C4);
PPC_FUNC_IMPL(__imp__sub_822151C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822151C8"))) PPC_WEAK_FUNC(sub_822151C8);
PPC_FUNC_IMPL(__imp__sub_822151C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-7830(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -7830);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// b 0x822150d8
	sub_822150D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822151DC"))) PPC_WEAK_FUNC(sub_822151DC);
PPC_FUNC_IMPL(__imp__sub_822151DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822151E0"))) PPC_WEAK_FUNC(sub_822151E0);
PPC_FUNC_IMPL(__imp__sub_822151E0) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8221528c
	if (!cr6.eq) goto loc_8221528C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x8221520C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221528c
	if (cr6.eq) goto loc_8221528C;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82215220;
	sub_822A39C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x82215228;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221528c
	if (!cr6.eq) goto loc_8221528C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x8221523C;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221528c
	if (!cr6.eq) goto loc_8221528C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8221528c
	if (cr6.eq) goto loc_8221528C;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lbz r11,100(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221528c
	if (cr6.eq) goto loc_8221528C;
	// bl 0x822b33f0
	ctx.lr = 0x82215268;
	sub_822B33F0(ctx, base);
	// lwz r8,880(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stb r11,100(r8)
	PPC_STORE_U8(ctx.r8.u32 + 100, r11.u8);
	// lfs f3,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x8221528C;
	sub_82207EF0(ctx, base);
loc_8221528C:
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

__attribute__((alias("__imp__sub_822152A0"))) PPC_WEAK_FUNC(sub_822152A0);
PPC_FUNC_IMPL(__imp__sub_822152A0) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82215330
	if (!cr6.eq) goto loc_82215330;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x822152CC;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215330
	if (cr6.eq) goto loc_82215330;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822152E0;
	sub_822A39C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82215330
	if (cr6.eq) goto loc_82215330;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lbz r11,100(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82215330
	if (!cr6.eq) goto loc_82215330;
	// bl 0x822b33f0
	ctx.lr = 0x82215304;
	sub_822B33F0(ctx, base);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// bl 0x822b32d0
	ctx.lr = 0x8221530C;
	sub_822B32D0(ctx, base);
	// lwz r8,880(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stb r11,100(r8)
	PPC_STORE_U8(ctx.r8.u32 + 100, r11.u8);
	// lfs f3,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x82215330;
	sub_82207EF0(ctx, base);
loc_82215330:
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

__attribute__((alias("__imp__sub_82215344"))) PPC_WEAK_FUNC(sub_82215344);
PPC_FUNC_IMPL(__imp__sub_82215344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82215348"))) PPC_WEAK_FUNC(sub_82215348);
PPC_FUNC_IMPL(__imp__sub_82215348) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-6148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82215374
	if (cr6.eq) goto loc_82215374;
	// lbz r11,13(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215374
	if (cr6.eq) goto loc_82215374;
	// bl 0x822505b8
	ctx.lr = 0x82215374;
	sub_822505B8(ctx, base);
loc_82215374:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-12356(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12356);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82215390;
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

__attribute__((alias("__imp__sub_822153A0"))) PPC_WEAK_FUNC(sub_822153A0);
PPC_FUNC_IMPL(__imp__sub_822153A0) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826947a0
	ctx.lr = 0x822153C0;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x822153C4;
	sub_823DD7F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x822153D4;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x822153D8;
	sub_823DD7F0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822c7e78
	ctx.lr = 0x822153E0;
	sub_822C7E78(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x822153EC;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221541c
	if (cr6.eq) goto loc_8221541C;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82215400;
	sub_822A39C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a5578
	ctx.lr = 0x82215408;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8221541c
	if (cr6.eq) goto loc_8221541C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x82215418;
	sub_822A5578(ctx, base);
	// bl 0x822a0028
	ctx.lr = 0x8221541C;
	sub_822A0028(ctx, base);
loc_8221541C:
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

