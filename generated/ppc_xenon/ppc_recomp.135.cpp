#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8266C35C"))) PPC_WEAK_FUNC(sub_8266C35C);
PPC_FUNC_IMPL(__imp__sub_8266C35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266C360"))) PPC_WEAK_FUNC(sub_8266C360);
PPC_FUNC_IMPL(__imp__sub_8266C360) {
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
	ctx.lr = 0x8266C368;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C384;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,7
	ctx.r4.s64 = 7;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C3A4;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266C3B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r6,r31
	ctx.r3.u64 = ctx.r6.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C3CC;
	sub_82641CB0(ctx, base);
	// addi r31,r30,672
	r31.s64 = r30.s64 + 672;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8266C3DC;
	sub_82631F88(ctx, base);
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// mr r28,r11
	r28.u64 = r11.u64;
	// blt cr6,0x8266c3f0
	if (cr6.lt) goto loc_8266C3F0;
	// addi r28,r3,-1
	r28.s64 = ctx.r3.s64 + -1;
loc_8266C3F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8266C3F8;
	sub_82631F88(ctx, base);
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266c408
	if (cr6.lt) goto loc_8266C408;
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
loc_8266C408:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r8,r30,1832
	ctx.r8.s64 = r30.s64 + 1832;
	// lwz r11,1824(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1824);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r7,1828(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 1828);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,684(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 684);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266C440"))) PPC_WEAK_FUNC(sub_8266C440);
PPC_FUNC_IMPL(__imp__sub_8266C440) {
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
	ctx.lr = 0x8266C448;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r27,r11,-18768
	r27.s64 = r11.s64 + -18768;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C468;
	sub_821F9FB8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,2612
	r30.s64 = r11.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,56(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266C484;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266C494;
	sub_825ED480(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,1072
	ctx.r4.s64 = ctx.r10.s64 + 1072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x8266C4AC;
	sub_825EE0E0(ctx, base);
	// li r9,3
	ctx.r9.s64 = 3;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-13268
	ctx.r4.s64 = ctx.r8.s64 + -13268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266C4C8;
	sub_82722678(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stb r30,1840(r25)
	PPC_STORE_U8(r25.u32 + 1840, r30.u8);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r7,6136
	ctx.r4.s64 = ctx.r7.s64 + 6136;
	// addi r31,r6,-19728
	r31.s64 = ctx.r6.s64 + -19728;
	// addi r28,r5,-22108
	r28.s64 = ctx.r5.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8266C4F8;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8266C50C;
	sub_823DEDD8(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// bl 0x826209d8
	ctx.lr = 0x8266C51C;
	sub_826209D8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8266c5b4
	if (cr6.eq) goto loc_8266C5B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266C53C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r9,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// lvx128 v61,r9,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r9,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826208d0
	ctx.lr = 0x8266C594;
	sub_826208D0(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82625ac0
	ctx.lr = 0x8266C5B0;
	sub_82625AC0(ctx, base);
	// b 0x8266c5e4
	goto loc_8266C5E4;
loc_8266C5B4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82625f50
	ctx.lr = 0x8266C5E4;
	sub_82625F50(ctx, base);
loc_8266C5E4:
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stb r30,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r30.u8);
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C620;
	sub_821F9FB8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8266c648
	if (cr6.eq) goto loc_8266C648;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x8266C634;
	sub_82720E28(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-19772
	ctx.r4.s64 = r11.s64 + -19772;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827205a8
	ctx.lr = 0x8266C648;
	sub_827205A8(ctx, base);
loc_8266C648:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r31,r25,256
	r31.s64 = r25.s64 + 256;
	// addi r4,r11,29148
	ctx.r4.s64 = r11.s64 + 29148;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x8262ffe0
	ctx.lr = 0x8266C660;
	sub_8262FFE0(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// bl 0x821f9fb8
	ctx.lr = 0x8266C670;
	sub_821F9FB8(ctx, base);
	// lwz r9,256(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 256);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266C68C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8266C6A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266C6A8"))) PPC_WEAK_FUNC(sub_8266C6A8);
PPC_FUNC_IMPL(__imp__sub_8266C6A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8266C6B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C6CC;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,9
	ctx.r4.s64 = 9;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C6EC;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266C700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r29,672
	ctx.r3.s64 = r29.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8266C708;
	sub_82631F88(ctx, base);
	// lwz r11,856(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266c718
	if (cr6.lt) goto loc_8266C718;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8266C718:
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8266c9a8
	if (cr6.gt) goto loc_8266C9A8;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,-14536
	r12.s64 = r12.s64 + -14536;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8266C750;
	case 1:
		goto loc_8266C7B4;
	case 2:
		goto loc_8266C818;
	case 3:
		goto loc_8266C87C;
	case 4:
		goto loc_8266C8E0;
	case 5:
		goto loc_8266C944;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-14512(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14512);
	// lwz r19,-14412(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14412);
	// lwz r19,-14312(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14312);
	// lwz r19,-14212(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14212);
	// lwz r19,-14112(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14112);
	// lwz r19,-14012(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14012);
loc_8266C750:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C764;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,84
	ctx.r4.s64 = ctx.r10.s64 + 84;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C77C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C790;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C7A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C7B4:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C7C8;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14368
	ctx.r4.s64 = ctx.r10.s64 + 14368;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C7E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C7F4;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,11
	ctx.r5.s64 = 11;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C80C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C818:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C82C;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14400
	ctx.r4.s64 = ctx.r10.s64 + 14400;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C858;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C87C:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C890;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14456
	ctx.r4.s64 = ctx.r10.s64 + 14456;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C8A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C8BC;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C8D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C8E0:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C8F4;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14428
	ctx.r4.s64 = ctx.r10.s64 + 14428;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C90C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C920;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,9
	ctx.r5.s64 = 9;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C944:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C958;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14340
	ctx.r4.s64 = ctx.r10.s64 + 14340;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C984;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C99C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C9A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266C9B4"))) PPC_WEAK_FUNC(sub_8266C9B4);
PPC_FUNC_IMPL(__imp__sub_8266C9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266C9B8"))) PPC_WEAK_FUNC(sub_8266C9B8);
PPC_FUNC_IMPL(__imp__sub_8266C9B8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C9E8;
	sub_821F9FB8(ctx, base);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266CA04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8266CA10;
	sub_82630318(ctx, base);
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

__attribute__((alias("__imp__sub_8266CA28"))) PPC_WEAK_FUNC(sub_8266CA28);
PPC_FUNC_IMPL(__imp__sub_8266CA28) {
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
	ctx.lr = 0x8266CA30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r30,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r30.u32);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// stb r30,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r30.u8);
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266CA5C;
	sub_821F9FB8(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r10,14648
	ctx.r4.s64 = ctx.r10.s64 + 14648;
	// bl 0x825ee120
	ctx.lr = 0x8266CA70;
	sub_825EE120(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,10
	ctx.r8.s64 = 10;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r8,860(r31)
	PPC_STORE_U32(r31.u32 + 860, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r7,65(r31)
	PPC_STORE_U8(r31.u32 + 65, ctx.r7.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r30,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r30.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r30,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, r30.u8);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r11,648(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 648);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266CAAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r4,r10,29060
	ctx.r4.s64 = ctx.r10.s64 + 29060;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// bl 0x8262ffe0
	ctx.lr = 0x8266CAC4;
	sub_8262FFE0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// addi r4,r9,-10256
	ctx.r4.s64 = ctx.r9.s64 + -10256;
	// bl 0x821f9fb8
	ctx.lr = 0x8266CAD4;
	sub_821F9FB8(ctx, base);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,196(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// lwz r4,56(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266CAF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266CAF8"))) PPC_WEAK_FUNC(sub_8266CAF8);
PPC_FUNC_IMPL(__imp__sub_8266CAF8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8266CB00;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266CB24;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r9,14672
	r31.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266CB40;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266CB50;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r26,r8,2612
	r26.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9790
	ctx.lr = 0x8266CB6C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266CB7C;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8266CB94;
	sub_821C9790(ctx, base);
	// li r6,7
	ctx.r6.s64 = 7;
	// li r27,1
	r27.s64 = 1;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r22,0
	r22.s64 = 0;
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r22,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r22.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266CBB8;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266CBD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,65(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 65);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266CBE8;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266CC00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r5,4524(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 4524);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8266cc24
	if (!cr6.eq) goto loc_8266CC24;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266CC20;
	sub_825EE0E0(ctx, base);
	// stb r27,4524(r30)
	PPC_STORE_U8(r30.u32 + 4524, r27.u8);
loc_8266CC24:
	// li r11,6
	r11.s64 = 6;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x8266CC40;
	sub_82722678(ctx, base);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// mr r11,r22
	r11.u64 = r22.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266cda4
	if (cr6.eq) goto loc_8266CDA4;
	// addi r29,r30,4428
	r29.s64 = r30.s64 + 4428;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8266CC58:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266cd9c
	if (cr6.eq) goto loc_8266CD9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266cc58
	if (cr6.lt) goto loc_8266CC58;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8266CC78:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d020
	if (cr6.eq) goto loc_8266D020;
	// lbz r11,4501(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d020
	if (cr6.eq) goto loc_8266D020;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14304
	ctx.r4.s64 = ctx.r10.s64 + -14304;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266CCA4;
	sub_82218310(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CCBC;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266CCC4;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,-10240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266CCD8;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266CCE0;
	sub_824E7118(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-11016
	ctx.r4.s64 = ctx.r6.s64 + -11016;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CCF4;
	sub_827227B8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r4,-11024
	ctx.r4.s64 = ctx.r4.s64 + -11024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD08;
	sub_827227B8(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r3,-11032
	ctx.r4.s64 = ctx.r3.s64 + -11032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD1C;
	sub_827227B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,2440
	ctx.r4.s64 = r11.s64 + 2440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD30;
	sub_827227B8(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r10,-3656
	ctx.r4.s64 = ctx.r10.s64 + -3656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD44;
	sub_827227B8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,14332
	ctx.r4.s64 = ctx.r9.s64 + 14332;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD58;
	sub_827227B8(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266CD6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r29,64
	r11.s64 = r29.s64 + 64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266CD7C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266cd7c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266CD7C;
	// stb r22,73(r29)
	PPC_STORE_U8(r29.u32 + 73, r22.u8);
	// stb r22,72(r29)
	PPC_STORE_U8(r29.u32 + 72, r22.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8266CD9C:
	// mr r11,r22
	r11.u64 = r22.u64;
	// b 0x8266cc78
	goto loc_8266CC78;
loc_8266CDA4:
	// addi r23,r30,4428
	r23.s64 = r30.s64 + 4428;
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
loc_8266CDAC:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266ce78
	if (cr6.eq) goto loc_8266CE78;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266cdac
	if (cr6.lt) goto loc_8266CDAC;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8266CDCC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d020
	if (cr6.eq) goto loc_8266D020;
	// lbz r11,4501(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d020
	if (cr6.eq) goto loc_8266D020;
	// lwz r11,10248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r30,10248
	ctx.r3.s64 = r30.s64 + 10248;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266CDFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r29,40(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// ld r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U64(r29.u32 + 16);
	// bl 0x823dba80
	ctx.lr = 0x8266CE0C;
	sub_823DBA80(ctx, base);
	// lwz r7,28(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fdivs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// beq 0x8266ce80
	if (cr0.eq) goto loc_8266CE80;
	// lwz r8,52(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fdivs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 / ctx.f9.f64));
	// fmuls f31,f7,f0
	f31.f64 = double(float(ctx.f7.f64 * f0.f64));
	// b 0x8266ce88
	goto loc_8266CE88;
loc_8266CE78:
	// mr r11,r22
	r11.u64 = r22.u64;
	// b 0x8266cdcc
	goto loc_8266CDCC;
loc_8266CE80:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8266CE88:
	// stfd f1,32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r27,r30,10848
	r27.s64 = r30.s64 + 10848;
	// addi r26,r11,-5880
	r26.s64 = r11.s64 + -5880;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x823dc018
	ctx.lr = 0x8266CEA8;
	sub_823DC018(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// addi r25,r11,14620
	r25.s64 = r11.s64 + 14620;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8266CEB8:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266ceb8
	if (!cr6.eq) goto loc_8266CEB8;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8266CECC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x8266cecc
	if (!cr6.eq) goto loc_8266CECC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// addi r28,r30,10855
	r28.s64 = r30.s64 + 10855;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823dc018
	ctx.lr = 0x8266CF00;
	sub_823DC018(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_8266CF08:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266cf08
	if (!cr6.eq) goto loc_8266CF08;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8266CF1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x8266cf1c
	if (!cr6.eq) goto loc_8266CF1C;
	// lwz r11,16(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20268
	ctx.r4.s64 = ctx.r10.s64 + 20268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266CF50;
	sub_82722678(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266CF58;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,-10240(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266CF6C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266CF74;
	sub_824E7118(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-11016
	ctx.r4.s64 = ctx.r7.s64 + -11016;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CF88;
	sub_827227B8(ctx, base);
	// ld r11,16(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 16);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-11024
	ctx.r4.s64 = ctx.r6.s64 + -11024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266CFA4;
	sub_82722678(ctx, base);
	// lwz r8,28(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-11032
	ctx.r4.s64 = ctx.r9.s64 + -11032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x8266CFC0;
	sub_82722678(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r7,2440
	ctx.r4.s64 = ctx.r7.s64 + 2440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CFD4;
	sub_827227B8(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r6,-3656
	ctx.r4.s64 = ctx.r6.s64 + -3656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CFE8;
	sub_827227B8(ctx, base);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,184(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 184);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8266CFFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r23,64
	r11.s64 = r23.s64 + 64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266D00C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266d00c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266D00C;
	// stb r22,73(r23)
	PPC_STORE_U8(r23.u32 + 73, r22.u8);
	// stb r22,72(r23)
	PPC_STORE_U8(r23.u32 + 72, r22.u8);
loc_8266D020:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8266D02C"))) PPC_WEAK_FUNC(sub_8266D02C);
PPC_FUNC_IMPL(__imp__sub_8266D02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D030"))) PPC_WEAK_FUNC(sub_8266D030);
PPC_FUNC_IMPL(__imp__sub_8266D030) {
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
	ctx.lr = 0x8266D038;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266D058;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r9,14672
	r30.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266D074;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D084;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r26,r8,2612
	r26.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9790
	ctx.lr = 0x8266D0A0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D0B0;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8266D0C8;
	sub_821C9790(ctx, base);
	// li r6,7
	ctx.r6.s64 = 7;
	// li r26,1
	r26.s64 = 1;
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// li r25,0
	r25.s64 = 0;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stw r26,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r26.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D0EC;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266D104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,65(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D11C;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266D134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r5,4524(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 4524);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8266d158
	if (!cr6.eq) goto loc_8266D158;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266D154;
	sub_825EE0E0(ctx, base);
	// stb r26,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r26.u8);
loc_8266D158:
	// li r11,4
	r11.s64 = 4;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266D174;
	sub_82722678(ctx, base);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266d298
	if (cr6.eq) goto loc_8266D298;
	// addi r29,r31,4428
	r29.s64 = r31.s64 + 4428;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8266D18C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266d290
	if (cr6.eq) goto loc_8266D290;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266d18c
	if (cr6.lt) goto loc_8266D18C;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8266D1AC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d3f4
	if (cr6.eq) goto loc_8266D3F4;
	// lbz r11,4501(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d3f4
	if (cr6.eq) goto loc_8266D3F4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14304
	ctx.r4.s64 = ctx.r10.s64 + -14304;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D1D8;
	sub_82218310(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D1F0;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266D1F8;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,-10240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266D20C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266D214;
	sub_824E7118(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-11016
	ctx.r4.s64 = ctx.r6.s64 + -11016;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D228;
	sub_827227B8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r4,-11024
	ctx.r4.s64 = ctx.r4.s64 + -11024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D23C;
	sub_827227B8(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r3,-11032
	ctx.r4.s64 = ctx.r3.s64 + -11032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D250;
	sub_827227B8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266D264;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r29,64
	r11.s64 = r29.s64 + 64;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266D274:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266d274
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266D274;
	// stb r25,73(r29)
	PPC_STORE_U8(r29.u32 + 73, r25.u8);
	// stb r25,72(r29)
	PPC_STORE_U8(r29.u32 + 72, r25.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
loc_8266D290:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x8266d1ac
	goto loc_8266D1AC;
loc_8266D298:
	// addi r27,r31,4428
	r27.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8266D2A0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266d320
	if (cr6.eq) goto loc_8266D320;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266d2a0
	if (cr6.lt) goto loc_8266D2A0;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8266D2C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d3f4
	if (cr6.eq) goto loc_8266D3F4;
	// lbz r11,4501(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d3f4
	if (cr6.eq) goto loc_8266D3F4;
	// lwz r11,10248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r3,r31,10248
	ctx.r3.s64 = r31.s64 + 10248;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266D2F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r29,40(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// addi r28,r31,10864
	r28.s64 = r31.s64 + 10864;
	// stw r3,10868(r31)
	PPC_STORE_U32(r31.u32 + 10868, ctx.r3.u32);
	// stw r9,10864(r31)
	PPC_STORE_U32(r31.u32 + 10864, ctx.r9.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x82396fb8
	ctx.lr = 0x8266D30C;
	sub_82396FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// beq cr6,0x8266d328
	if (cr6.eq) goto loc_8266D328;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8266d330
	goto loc_8266D330;
loc_8266D320:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x8266d2c0
	goto loc_8266D2C0;
loc_8266D328:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6316
	ctx.r4.s64 = ctx.r10.s64 + 6316;
loc_8266D330:
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D338;
	sub_82218310(ctx, base);
	// stw r3,10872(r31)
	PPC_STORE_U32(r31.u32 + 10872, ctx.r3.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ld r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U64(r29.u32 + 24);
	// bl 0x8223de50
	ctx.lr = 0x8266D348;
	sub_8223DE50(ctx, base);
	// addi r29,r31,10876
	r29.s64 = r31.s64 + 10876;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// subf r10,r10,r29
	ctx.r10.s64 = r29.s64 - ctx.r10.s64;
loc_8266D358:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8266d358
	if (!cr6.eq) goto loc_8266D358;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,20268
	ctx.r4.s64 = r11.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266D380;
	sub_82722678(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,10868(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10868);
	// addi r4,r10,-11016
	ctx.r4.s64 = ctx.r10.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x8266D394;
	sub_827227B8(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,10872(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10872);
	// addi r4,r9,-11024
	ctx.r4.s64 = ctx.r9.s64 + -11024;
	// bl 0x827227b8
	ctx.lr = 0x8266D3A8;
	sub_827227B8(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r8,-11032
	ctx.r4.s64 = ctx.r8.s64 + -11032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D3BC;
	sub_827227B8(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266D3D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r27,64
	r11.s64 = r27.s64 + 64;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266D3E0:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266d3e0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266D3E0;
	// stb r25,73(r27)
	PPC_STORE_U8(r27.u32 + 73, r25.u8);
	// stb r25,72(r27)
	PPC_STORE_U8(r27.u32 + 72, r25.u8);
loc_8266D3F4:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266D3FC"))) PPC_WEAK_FUNC(sub_8266D3FC);
PPC_FUNC_IMPL(__imp__sub_8266D3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D400"))) PPC_WEAK_FUNC(sub_8266D400);
PPC_FUNC_IMPL(__imp__sub_8266D400) {
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
	ctx.lr = 0x8266D408;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8266d42c
	if (!cr6.gt) goto loc_8266D42C;
	// lwz r30,12(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// b 0x8266d430
	goto loc_8266D430;
loc_8266D42C:
	// li r30,0
	r30.s64 = 0;
loc_8266D430:
	// lwz r29,40(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U64(r29.u32 + 24);
	// bl 0x8223de50
	ctx.lr = 0x8266D440;
	sub_8223DE50(ctx, base);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8266d478
	if (!cr6.eq) goto loc_8266D478;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r10,-14304
	r30.s64 = ctx.r10.s64 + -14304;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D464;
	sub_82218310(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8266d4b0
	goto loc_8266D4B0;
loc_8266D478:
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x82396fb8
	ctx.lr = 0x8266D480;
	sub_82396FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266d494
	if (cr6.eq) goto loc_8266D494;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,8200(r31)
	PPC_STORE_U32(r31.u32 + 8200, r11.u32);
	// b 0x8266d4a0
	goto loc_8266D4A0;
loc_8266D494:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,6316
	ctx.r10.s64 = r11.s64 + 6316;
	// stw r10,8200(r31)
	PPC_STORE_U32(r31.u32 + 8200, ctx.r10.u32);
loc_8266D4A0:
	// lwz r6,8200(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8200);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
loc_8266D4B0:
	// mulli r11,r28,336
	r11.s64 = r28.s64 * 336;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,6848
	ctx.r3.s64 = r11.s64 + 6848;
	// bl 0x8266ac18
	ctx.lr = 0x8266D4C0;
	sub_8266AC18(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// stw r9,16(r27)
	PPC_STORE_U32(r27.u32 + 16, ctx.r9.u32);
	// stw r8,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8266D4E0"))) PPC_WEAK_FUNC(sub_8266D4E0);
PPC_FUNC_IMPL(__imp__sub_8266D4E0) {
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
	// bl 0x8266ca28
	ctx.lr = 0x8266D4FC;
	sub_8266CA28(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r4,r11,28652
	ctx.r4.s64 = r11.s64 + 28652;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x8262ffe0
	ctx.lr = 0x8266D514;
	sub_8262FFE0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-10256
	ctx.r4.s64 = ctx.r9.s64 + -10256;
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266D528;
	sub_821F9FB8(ctx, base);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,196(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// lwz r4,56(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266D544;
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

__attribute__((alias("__imp__sub_8266D55C"))) PPC_WEAK_FUNC(sub_8266D55C);
PPC_FUNC_IMPL(__imp__sub_8266D55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D560"))) PPC_WEAK_FUNC(sub_8266D560);
PPC_FUNC_IMPL(__imp__sub_8266D560) {
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
	ctx.lr = 0x8266D568;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266D584;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r9,14672
	r30.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,56(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266D5A0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D5B0;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r29,56(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r28,r8,2612
	r28.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9790
	ctx.lr = 0x8266D5CC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D5DC;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8266D5F4;
	sub_821C9790(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D618;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266D630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,65(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D648;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266D660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,4548(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r28,r11,-14304
	r28.s64 = r11.s64 + -14304;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8266d6a8
	if (cr6.eq) goto loc_8266D6A8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8223de50
	ctx.lr = 0x8266D680;
	sub_8223DE50(ctx, base);
	// addi r31,r31,8204
	r31.s64 = r31.s64 + 8204;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// subf r10,r10,r31
	ctx.r10.s64 = r31.s64 - ctx.r10.s64;
loc_8266D690:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8266d690
	if (!cr6.eq) goto loc_8266D690;
	// b 0x8266d6d4
	goto loc_8266D6D4;
loc_8266D6A8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D6B4;
	sub_82218310(ctx, base);
	// addi r31,r31,8204
	r31.s64 = r31.s64 + 8204;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8266D6BC:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8266d6bc
	if (!cr6.eq) goto loc_8266D6BC;
loc_8266D6D4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D6E0;
	sub_82218310(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,20268
	ctx.r4.s64 = r11.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D6F4;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266D6FC;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266D710;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266D718;
	sub_824E7118(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,-11016
	ctx.r4.s64 = ctx.r8.s64 + -11016;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D72C;
	sub_827227B8(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,17268(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// lwz r29,-10244(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x822a39c8
	ctx.lr = 0x8266D73C;
	sub_822A39C8(ctx, base);
	// bl 0x822a8d98
	ctx.lr = 0x8266D740;
	sub_822A8D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x8266D74C;
	sub_82218310(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-11024
	ctx.r4.s64 = ctx.r6.s64 + -11024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D760;
	sub_827227B8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-11032
	ctx.r4.s64 = ctx.r4.s64 + -11032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D774;
	sub_827227B8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266D77C"))) PPC_WEAK_FUNC(sub_8266D77C);
PPC_FUNC_IMPL(__imp__sub_8266D77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D780"))) PPC_WEAK_FUNC(sub_8266D780);
PPC_FUNC_IMPL(__imp__sub_8266D780) {
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
	// bl 0x8266d560
	ctx.lr = 0x8266D798;
	sub_8266D560(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826535f8
	ctx.lr = 0x8266D7A0;
	sub_826535F8(ctx, base);
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

__attribute__((alias("__imp__sub_8266D7B4"))) PPC_WEAK_FUNC(sub_8266D7B4);
PPC_FUNC_IMPL(__imp__sub_8266D7B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D7B8"))) PPC_WEAK_FUNC(sub_8266D7B8);
PPC_FUNC_IMPL(__imp__sub_8266D7B8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8266D7C0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266D7E0;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r9,14672
	r31.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266D7FC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D80C;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r26,r8,2612
	r26.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9790
	ctx.lr = 0x8266D828;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D838;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8266D850;
	sub_821C9790(ctx, base);
	// li r25,1
	r25.s64 = 1;
	// li r24,0
	r24.s64 = 0;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r27,7
	r27.s64 = 7;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// stw r24,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D874;
	sub_825EF9F0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r11,36(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266D88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,65(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 65);
	// li r10,3
	ctx.r10.s64 = 3;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D8A4;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266D8BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,4524(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 4524);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8266d8e0
	if (!cr6.eq) goto loc_8266D8E0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266D8DC;
	sub_825EE0E0(ctx, base);
	// stb r25,4524(r30)
	PPC_STORE_U8(r30.u32 + 4524, r25.u8);
loc_8266D8E0:
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-13284
	ctx.r4.s64 = r11.s64 + -13284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x8266D8F8;
	sub_82722678(ctx, base);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// mr r11,r24
	r11.u64 = r24.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266da58
	if (cr6.eq) goto loc_8266DA58;
	// addi r29,r30,4428
	r29.s64 = r30.s64 + 4428;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8266D910:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266da50
	if (cr6.eq) goto loc_8266DA50;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266d910
	if (cr6.lt) goto loc_8266D910;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8266D930:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dc50
	if (cr6.eq) goto loc_8266DC50;
	// lbz r11,4501(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dc50
	if (cr6.eq) goto loc_8266DC50;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14304
	ctx.r4.s64 = ctx.r10.s64 + -14304;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D95C;
	sub_82218310(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D974;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266D97C;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,-10240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266D990;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266D998;
	sub_824E7118(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-11016
	ctx.r4.s64 = ctx.r6.s64 + -11016;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9AC;
	sub_827227B8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r4,-11024
	ctx.r4.s64 = ctx.r4.s64 + -11024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9C0;
	sub_827227B8(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r3,-11032
	ctx.r4.s64 = ctx.r3.s64 + -11032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9D4;
	sub_827227B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,2440
	ctx.r4.s64 = r11.s64 + 2440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9E8;
	sub_827227B8(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r10,-3656
	ctx.r4.s64 = ctx.r10.s64 + -3656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9FC;
	sub_827227B8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,14332
	ctx.r4.s64 = ctx.r9.s64 + 14332;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266DA10;
	sub_827227B8(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266DA24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r29,64
	r11.s64 = r29.s64 + 64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266DA34:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266da34
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266DA34;
	// stb r24,73(r29)
	PPC_STORE_U8(r29.u32 + 73, r24.u8);
	// stb r24,72(r29)
	PPC_STORE_U8(r29.u32 + 72, r24.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_8266DA50:
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8266d930
	goto loc_8266D930;
loc_8266DA58:
	// addi r26,r30,4428
	r26.s64 = r30.s64 + 4428;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_8266DA60:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266dc58
	if (cr6.eq) goto loc_8266DC58;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266da60
	if (cr6.lt) goto loc_8266DA60;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8266DA80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dc50
	if (cr6.eq) goto loc_8266DC50;
	// lbz r11,4501(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dc50
	if (cr6.eq) goto loc_8266DC50;
	// lwz r11,10248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r30,10248
	ctx.r3.s64 = r30.s64 + 10248;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266DAB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r28,r30,10856
	r28.s64 = r30.s64 + 10856;
	// lwz r29,40(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// ld r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U64(r29.u32 + 16);
	// bl 0x823dba80
	ctx.lr = 0x8266DAC4;
	sub_823DBA80(ctx, base);
	// lwz r7,28(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r5,r6,-5880
	ctx.r5.s64 = ctx.r6.s64 + -5880;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// li r4,7
	ctx.r4.s64 = 7;
	// fdivs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82137a08
	ctx.lr = 0x8266DB08;
	sub_82137A08(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// addi r11,r11,14620
	r11.s64 = r11.s64 + 14620;
loc_8266DB14:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266db14
	if (!cr6.eq) goto loc_8266DB14;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8266DB28:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x8266db28
	if (!cr6.eq) goto loc_8266DB28;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20268
	ctx.r4.s64 = ctx.r10.s64 + 20268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DB5C;
	sub_82722678(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266DB64;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,-10240(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266DB78;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266DB80;
	sub_824E7118(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-11016
	ctx.r4.s64 = ctx.r7.s64 + -11016;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266DB94;
	sub_827227B8(ctx, base);
	// ld r11,16(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 16);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-11024
	ctx.r4.s64 = ctx.r6.s64 + -11024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DBB0;
	sub_82722678(ctx, base);
	// lwz r8,28(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-11032
	ctx.r4.s64 = ctx.r9.s64 + -11032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DBCC;
	sub_82722678(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r7,2440
	ctx.r4.s64 = ctx.r7.s64 + 2440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266DBE0;
	sub_827227B8(ctx, base);
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-3656
	ctx.r4.s64 = ctx.r6.s64 + -3656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DBFC;
	sub_82722678(ctx, base);
	// lwz r9,44(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,14332
	ctx.r4.s64 = ctx.r10.s64 + 14332;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DC18;
	sub_82722678(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266DC2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r26,64
	r11.s64 = r26.s64 + 64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266DC3C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266dc3c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266DC3C;
	// stb r24,73(r26)
	PPC_STORE_U8(r26.u32 + 73, r24.u8);
	// stb r24,72(r26)
	PPC_STORE_U8(r26.u32 + 72, r24.u8);
loc_8266DC50:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_8266DC58:
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8266da80
	goto loc_8266DA80;
}

__attribute__((alias("__imp__sub_8266DC60"))) PPC_WEAK_FUNC(sub_8266DC60);
PPC_FUNC_IMPL(__imp__sub_8266DC60) {
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
	ctx.lr = 0x8266DC68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266DC98;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r7,r8,15452
	ctx.r7.s64 = ctx.r8.s64 + 15452;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,15424
	ctx.r4.s64 = ctx.r6.s64 + 15424;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DCBC;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,15400
	ctx.r4.s64 = ctx.r4.s64 + 15400;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DCD4;
	sub_82633D40(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,15376
	ctx.r4.s64 = ctx.r3.s64 + 15376;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DCEC;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266DD44"))) PPC_WEAK_FUNC(sub_8266DD44);
PPC_FUNC_IMPL(__imp__sub_8266DD44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266DD48"))) PPC_WEAK_FUNC(sub_8266DD48);
PPC_FUNC_IMPL(__imp__sub_8266DD48) {
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
	// addi r31,r30,1408
	r31.s64 = r30.s64 + 1408;
	// lhz r11,1602(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1602);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dd78
	if (cr6.eq) goto loc_8266DD78;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DD78;
	sub_82130588(ctx, base);
loc_8266DD78:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DD80;
	sub_82633B00(ctx, base);
	// lhz r11,1394(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1394);
	// addi r31,r30,1200
	r31.s64 = r30.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dd98
	if (cr6.eq) goto loc_8266DD98;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DD98;
	sub_82130588(ctx, base);
loc_8266DD98:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DDA0;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1186);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ddb8
	if (cr6.eq) goto loc_8266DDB8;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DDB8;
	sub_82130588(ctx, base);
loc_8266DDB8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DDC0;
	sub_82633B00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266DDC8;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266DDE0"))) PPC_WEAK_FUNC(sub_8266DDE0);
PPC_FUNC_IMPL(__imp__sub_8266DDE0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8266DDE8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,15376
	ctx.r5.s64 = ctx.r10.s64 + 15376;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266DE18;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,16284
	ctx.r7.s64 = ctx.r8.s64 + 16284;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x8266DE2C;
	sub_82659E28(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,14592
	ctx.r4.s64 = ctx.r6.s64 + 14592;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DE44;
	sub_82633D40(ctx, base);
	// addi r29,r31,1232
	r29.s64 = r31.s64 + 1232;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,14564
	ctx.r4.s64 = ctx.r4.s64 + 14564;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DE5C;
	sub_82633D40(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r28,r31,1440
	r28.s64 = r31.s64 + 1440;
	// addi r4,r3,14512
	ctx.r4.s64 = ctx.r3.s64 + 14512;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DE74;
	sub_82633D40(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r27,r31,1648
	r27.s64 = r31.s64 + 1648;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14540
	ctx.r4.s64 = r11.s64 + 14540;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DE8C;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r26,r31,1856
	r26.s64 = r31.s64 + 1856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,14484
	ctx.r4.s64 = ctx.r10.s64 + 14484;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DEA4;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r26,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r26.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266DF2C"))) PPC_WEAK_FUNC(sub_8266DF2C);
PPC_FUNC_IMPL(__imp__sub_8266DF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266DF30"))) PPC_WEAK_FUNC(sub_8266DF30);
PPC_FUNC_IMPL(__imp__sub_8266DF30) {
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
	// addi r30,r31,1856
	r30.s64 = r31.s64 + 1856;
	// lhz r11,2050(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2050);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266df60
	if (cr6.eq) goto loc_8266DF60;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DF60;
	sub_82130588(ctx, base);
loc_8266DF60:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DF68;
	sub_82633B00(ctx, base);
	// lhz r11,1842(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1842);
	// addi r30,r31,1648
	r30.s64 = r31.s64 + 1648;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266df80
	if (cr6.eq) goto loc_8266DF80;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DF80;
	sub_82130588(ctx, base);
loc_8266DF80:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DF88;
	sub_82633B00(ctx, base);
	// lhz r11,1634(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1634);
	// addi r30,r31,1440
	r30.s64 = r31.s64 + 1440;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dfa0
	if (cr6.eq) goto loc_8266DFA0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DFA0;
	sub_82130588(ctx, base);
loc_8266DFA0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DFA8;
	sub_82633B00(ctx, base);
	// lhz r11,1426(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1426);
	// addi r30,r31,1232
	r30.s64 = r31.s64 + 1232;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dfc0
	if (cr6.eq) goto loc_8266DFC0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DFC0;
	sub_82130588(ctx, base);
loc_8266DFC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DFC8;
	sub_82633B00(ctx, base);
	// lhz r11,1218(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1218);
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dfe0
	if (cr6.eq) goto loc_8266DFE0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DFE0;
	sub_82130588(ctx, base);
loc_8266DFE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DFE8;
	sub_82633B00(ctx, base);
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e000
	if (cr6.eq) goto loc_8266E000;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8266E000;
	sub_82130588(ctx, base);
loc_8266E000:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8266E008;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266E010;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266E028"))) PPC_WEAK_FUNC(sub_8266E028);
PPC_FUNC_IMPL(__imp__sub_8266E028) {
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
	ctx.lr = 0x8266E030;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r29,848
	r31.s64 = r29.s64 + 848;
	// lhz r11,852(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 852);
	// lwz r9,848(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266e070
	if (cr6.eq) goto loc_8266E070;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8266E05C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266e05c
	if (!cr6.eq) goto loc_8266E05C;
loc_8266E070:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// addi r28,r11,17232
	r28.s64 = r11.s64 + 17232;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r6,r29,1856
	ctx.r6.s64 = r29.s64 + 1856;
	// clrlwi r9,r7,16
	ctx.r9.u64 = ctx.r7.u32 & 0xFFFF;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r30,r29,992
	r30.s64 = r29.s64 + 992;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// addi r5,r4,-4680
	ctx.r5.s64 = ctx.r4.s64 + -4680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r6,992(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// lwz r11,24(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266E0D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,992(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E0E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e10c
	if (!cr6.gt) goto loc_8266E10C;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1024
	ctx.r8.s64 = r29.s64 + 1024;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E10C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4744
	ctx.r5.s64 = ctx.r10.s64 + -4744;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E12C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e168
	if (!cr6.gt) goto loc_8266E168;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1440
	ctx.r8.s64 = r29.s64 + 1440;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E168:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E19C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e1c4
	if (!cr6.gt) goto loc_8266E1C4;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1232
	ctx.r8.s64 = r29.s64 + 1232;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E1C4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4764
	ctx.r5.s64 = ctx.r10.s64 + -4764;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E1E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E1F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e220
	if (!cr6.gt) goto loc_8266E220;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1648
	ctx.r8.s64 = r29.s64 + 1648;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E220:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266E228"))) PPC_WEAK_FUNC(sub_8266E228);
PPC_FUNC_IMPL(__imp__sub_8266E228) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8266E230;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,15424
	ctx.r5.s64 = ctx.r10.s64 + 15424;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266E260;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,17092
	ctx.r7.s64 = ctx.r8.s64 + 17092;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x8266E274;
	sub_82659E28(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,16392
	ctx.r4.s64 = ctx.r6.s64 + 16392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E28C;
	sub_82633D40(ctx, base);
	// addi r29,r31,1232
	r29.s64 = r31.s64 + 1232;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,16364
	ctx.r4.s64 = ctx.r4.s64 + 16364;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E2A4;
	sub_82633D40(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r28,r31,1440
	r28.s64 = r31.s64 + 1440;
	// addi r4,r3,16336
	ctx.r4.s64 = ctx.r3.s64 + 16336;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E2BC;
	sub_82633D40(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r27,r31,1648
	r27.s64 = r31.s64 + 1648;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,16312
	ctx.r4.s64 = r11.s64 + 16312;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E2D4;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8266E344"))) PPC_WEAK_FUNC(sub_8266E344);
PPC_FUNC_IMPL(__imp__sub_8266E344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266E348"))) PPC_WEAK_FUNC(sub_8266E348);
PPC_FUNC_IMPL(__imp__sub_8266E348) {
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
	// addi r30,r31,1648
	r30.s64 = r31.s64 + 1648;
	// lhz r11,1842(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1842);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e378
	if (cr6.eq) goto loc_8266E378;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E378;
	sub_82130588(ctx, base);
loc_8266E378:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E380;
	sub_82633B00(ctx, base);
	// lhz r11,1634(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1634);
	// addi r30,r31,1440
	r30.s64 = r31.s64 + 1440;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e398
	if (cr6.eq) goto loc_8266E398;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E398;
	sub_82130588(ctx, base);
loc_8266E398:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E3A0;
	sub_82633B00(ctx, base);
	// lhz r11,1426(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1426);
	// addi r30,r31,1232
	r30.s64 = r31.s64 + 1232;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e3b8
	if (cr6.eq) goto loc_8266E3B8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E3B8;
	sub_82130588(ctx, base);
loc_8266E3B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E3C0;
	sub_82633B00(ctx, base);
	// lhz r11,1218(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1218);
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e3d8
	if (cr6.eq) goto loc_8266E3D8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E3D8;
	sub_82130588(ctx, base);
loc_8266E3D8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E3E0;
	sub_82633B00(ctx, base);
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e3f8
	if (cr6.eq) goto loc_8266E3F8;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8266E3F8;
	sub_82130588(ctx, base);
loc_8266E3F8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8266E400;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266E408;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266E420"))) PPC_WEAK_FUNC(sub_8266E420);
PPC_FUNC_IMPL(__imp__sub_8266E420) {
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
	ctx.lr = 0x8266E428;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r29,848
	r31.s64 = r29.s64 + 848;
	// lhz r11,852(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 852);
	// lwz r9,848(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266e468
	if (cr6.eq) goto loc_8266E468;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8266E454:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266e454
	if (!cr6.eq) goto loc_8266E454;
loc_8266E468:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// addi r28,r11,17232
	r28.s64 = r11.s64 + 17232;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r30,r29,992
	r30.s64 = r29.s64 + 992;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lwz r11,992(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-4680
	ctx.r5.s64 = ctx.r6.s64 + -4680;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266E4A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,992(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266E4BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e4e4
	if (!cr6.gt) goto loc_8266E4E4;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1024
	ctx.r8.s64 = r29.s64 + 1024;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E4E4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4744
	ctx.r5.s64 = ctx.r10.s64 + -4744;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E518;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e540
	if (!cr6.gt) goto loc_8266E540;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1440
	ctx.r8.s64 = r29.s64 + 1440;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E540:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e59c
	if (!cr6.gt) goto loc_8266E59C;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1232
	ctx.r8.s64 = r29.s64 + 1232;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E59C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4764
	ctx.r5.s64 = ctx.r10.s64 + -4764;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E5BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E5D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e5f8
	if (!cr6.gt) goto loc_8266E5F8;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1648
	ctx.r8.s64 = r29.s64 + 1648;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E5F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266E600"))) PPC_WEAK_FUNC(sub_8266E600);
PPC_FUNC_IMPL(__imp__sub_8266E600) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x8266E608;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r28,r31,5052
	r28.s64 = r31.s64 + 5052;
	// lhz r11,5056(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5056);
	// lwz r9,5052(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 5052);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266e648
	if (cr6.eq) goto loc_8266E648;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8266E634:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266e634
	if (!cr6.eq) goto loc_8266E634;
loc_8266E648:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r30,r31,5024
	r30.s64 = r31.s64 + 5024;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// lwz r11,5048(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5048);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// stw r30,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r30.u32);
	// bgt cr6,0x8266e7b4
	if (cr6.gt) goto loc_8266E7B4;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r29,r10,17232
	r29.s64 = ctx.r10.s64 + 17232;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,-6512
	r12.s64 = r12.s64 + -6512;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8266E6A0;
	case 1:
		goto loc_8266E6E0;
	case 2:
		goto loc_8266E720;
	case 3:
		goto loc_8266E778;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-6496(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -6496);
	// lwz r19,-6432(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -6432);
	// lwz r19,-6368(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -6368);
	// lwz r19,-6280(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -6280);
loc_8266E6A0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r5,r10,-4680
	ctx.r5.s64 = ctx.r10.s64 + -4680;
	// addi r4,r9,17232
	ctx.r4.s64 = ctx.r9.s64 + 17232;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266E6C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,16392
	ctx.r4.s64 = ctx.r7.s64 + 16392;
	// lwz r5,788(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 788);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// b 0x8266e7b0
	goto loc_8266E7B0;
loc_8266E6E0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r5,r10,-4744
	ctx.r5.s64 = ctx.r10.s64 + -4744;
	// addi r4,r9,17232
	ctx.r4.s64 = ctx.r9.s64 + 17232;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266E704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,16336
	ctx.r4.s64 = ctx.r7.s64 + 16336;
	// lwz r5,788(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 788);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// b 0x8266e7b0
	goto loc_8266E7B0;
loc_8266E720:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,16364
	ctx.r4.s64 = ctx.r8.s64 + 16364;
	// lwz r6,788(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266E75C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8266E770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x8266e7b4
	if (cr6.gt) goto loc_8266E7B4;
loc_8266E778:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-4764
	ctx.r5.s64 = ctx.r10.s64 + -4764;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E798;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,16312
	ctx.r4.s64 = ctx.r8.s64 + 16312;
	// lwz r6,788(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_8266E7B0:
	// bctrl 
	ctx.lr = 0x8266E7B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8266E7B4:
	// addi r29,r31,672
	r29.s64 = r31.s64 + 672;
	// li r30,0
	r30.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82631f88
	ctx.lr = 0x8266E7C4;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e83c
	if (!cr6.gt) goto loc_8266E83C;
	// lis r27,-32120
	r27.s64 = -2105016320;
loc_8266E7D0:
	// lwz r3,-27856(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8266E7D8;
	sub_8238EC00(ctx, base);
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E7FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82389800
	ctx.lr = 0x8266E808;
	sub_82389800(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lhz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 16);
	// extsh r26,r7
	r26.s64 = ctx.r7.s16;
	// bl 0x8262e420
	ctx.lr = 0x8266E820;
	sub_8262E420(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r26,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r26.u32);
	// bl 0x82631f88
	ctx.lr = 0x8266E834;
	sub_82631F88(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266e7d0
	if (cr6.lt) goto loc_8266E7D0;
loc_8266E83C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266E844"))) PPC_WEAK_FUNC(sub_8266E844);
PPC_FUNC_IMPL(__imp__sub_8266E844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266E848"))) PPC_WEAK_FUNC(sub_8266E848);
PPC_FUNC_IMPL(__imp__sub_8266E848) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8266E850;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,18704
	ctx.r5.s64 = ctx.r10.s64 + 18704;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266E880;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r7,r8,17900
	ctx.r7.s64 = ctx.r8.s64 + 17900;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,6192
	ctx.r4.s64 = ctx.r6.s64 + 6192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E8A4;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,6212
	ctx.r4.s64 = ctx.r4.s64 + 6212;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E8BC;
	sub_82633D40(ctx, base);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,6232
	ctx.r4.s64 = ctx.r3.s64 + 6232;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E8D4;
	sub_82633D40(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r27,r31,1616
	r27.s64 = r31.s64 + 1616;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,6252
	ctx.r4.s64 = r11.s64 + 6252;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E8EC;
	sub_82633D40(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// stw r11,1832(r31)
	PPC_STORE_U32(r31.u32 + 1832, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,1836(r31)
	PPC_STORE_U16(r31.u32 + 1836, r11.u16);
	// sth r11,1838(r31)
	PPC_STORE_U16(r31.u32 + 1838, r11.u16);
	// stb r11,1840(r31)
	PPC_STORE_U8(r31.u32 + 1840, r11.u8);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r9.u16);
	// stwx r27,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8266E970"))) PPC_WEAK_FUNC(sub_8266E970);
PPC_FUNC_IMPL(__imp__sub_8266E970) {
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
	// lhz r11,1838(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1838);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e99c
	if (cr6.eq) goto loc_8266E99C;
	// lwz r3,1832(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1832);
	// bl 0x82130588
	ctx.lr = 0x8266E99C;
	sub_82130588(ctx, base);
loc_8266E99C:
	// lhz r11,1810(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1810);
	// addi r30,r31,1616
	r30.s64 = r31.s64 + 1616;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e9b4
	if (cr6.eq) goto loc_8266E9B4;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E9B4;
	sub_82130588(ctx, base);
loc_8266E9B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E9BC;
	sub_82633B00(ctx, base);
	// lhz r11,1602(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1602);
	// addi r30,r31,1408
	r30.s64 = r31.s64 + 1408;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e9d4
	if (cr6.eq) goto loc_8266E9D4;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E9D4;
	sub_82130588(ctx, base);
loc_8266E9D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E9DC;
	sub_82633B00(ctx, base);
	// lhz r11,1394(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1394);
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e9f4
	if (cr6.eq) goto loc_8266E9F4;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E9F4;
	sub_82130588(ctx, base);
loc_8266E9F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E9FC;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1186);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ea14
	if (cr6.eq) goto loc_8266EA14;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EA14;
	sub_82130588(ctx, base);
loc_8266EA14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EA1C;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266EA24;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266EA3C"))) PPC_WEAK_FUNC(sub_8266EA3C);
PPC_FUNC_IMPL(__imp__sub_8266EA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266EA40"))) PPC_WEAK_FUNC(sub_8266EA40);
PPC_FUNC_IMPL(__imp__sub_8266EA40) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8266EA48;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r29,r11,-18768
	r29.s64 = r11.s64 + -18768;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8266EA70;
	sub_821F9FB8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,56
	cr6.compare<int32_t>(r28.s32, 56, xer);
	// beq cr6,0x8266ec10
	if (cr6.eq) goto loc_8266EC10;
	// cmpwi cr6,r28,63
	cr6.compare<int32_t>(r28.s32, 63, xer);
	// beq cr6,0x8266ea9c
	if (cr6.eq) goto loc_8266EA9C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826537d0
	ctx.lr = 0x8266EA94;
	sub_826537D0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266EA9C:
	// lbz r11,1840(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1840);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266eabc
	if (cr6.eq) goto loc_8266EABC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8266c440
	ctx.lr = 0x8266EAB0;
	sub_8266C440(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266EABC:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266EAD4;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266EAE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8266ec04
	if (cr6.eq) goto loc_8266EC04;
	// addi r3,r30,672
	ctx.r3.s64 = r30.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x8266EAFC;
	sub_82203240(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8266ec04
	if (cr6.lt) goto loc_8266EC04;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266EB18;
	sub_825EE0E0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82657678
	ctx.lr = 0x8266EB20;
	sub_82657678(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r9,352
	ctx.r9.s64 = 352;
	// lwz r10,-10236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r26,r3,-22108
	r26.s64 = ctx.r3.s64 + -22108;
	// lfs f0,6076(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 6076);
	f0.f64 = double(temp.f32);
	// addi r4,r6,6060
	ctx.r4.s64 = ctx.r6.s64 + 6060;
	// addi r27,r5,-19728
	r27.s64 = ctx.r5.s64 + -19728;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8266EB6C;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8266EB80;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82625f50
	ctx.lr = 0x8266EBA4;
	sub_82625F50(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stb r11,1840(r30)
	PPC_STORE_U8(r30.u32 + 1840, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1120(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1120, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,372(r10)
	PPC_STORE_U8(ctx.r10.u32 + 372, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1427(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1427, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1401(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1401, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,375(r10)
	PPC_STORE_U8(ctx.r10.u32 + 375, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,374(r10)
	PPC_STORE_U8(ctx.r10.u32 + 374, r11.u8);
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266EBE8;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266ebf4
	if (cr6.eq) goto loc_8266EBF4;
	// bl 0x82720560
	ctx.lr = 0x8266EBF4;
	sub_82720560(ctx, base);
loc_8266EBF4:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,34
	ctx.r4.s64 = 34;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220f040
	ctx.lr = 0x8266EC04;
	sub_8220F040(ctx, base);
loc_8266EC04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266EC10:
	// lbz r11,1840(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1840);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ec30
	if (cr6.eq) goto loc_8266EC30;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8266c440
	ctx.lr = 0x8266EC24;
	sub_8266C440(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266EC30:
	// li r4,56
	ctx.r4.s64 = 56;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826537d0
	ctx.lr = 0x8266EC40;
	sub_826537D0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266EC48"))) PPC_WEAK_FUNC(sub_8266EC48);
PPC_FUNC_IMPL(__imp__sub_8266EC48) {
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
	ctx.lr = 0x8266EC50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// addi r30,r31,1832
	r30.s64 = r31.s64 + 1832;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// stw r5,1824(r31)
	PPC_STORE_U32(r31.u32 + 1824, ctx.r5.u32);
	// stw r6,1828(r31)
	PPC_STORE_U32(r31.u32 + 1828, ctx.r6.u32);
	// beq cr6,0x8266eca4
	if (cr6.eq) goto loc_8266ECA4;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8266ec98
	if (cr6.eq) goto loc_8266EC98;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ec98
	if (cr6.eq) goto loc_8266EC98;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8266EC98;
	sub_82130588(ctx, base);
loc_8266EC98:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c7480
	ctx.lr = 0x8266ECA4;
	sub_826C7480(ctx, base);
loc_8266ECA4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266ECB8;
	sub_821F9FB8(ctx, base);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266ECD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8266ECE0;
	sub_82630318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266ECE8"))) PPC_WEAK_FUNC(sub_8266ECE8);
PPC_FUNC_IMPL(__imp__sub_8266ECE8) {
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
	ctx.lr = 0x8266ECF0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,15400
	ctx.r5.s64 = ctx.r10.s64 + 15400;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,6
	ctx.r6.s64 = 6;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266ED20;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r7,r8,18740
	ctx.r7.s64 = ctx.r8.s64 + 18740;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,84
	ctx.r4.s64 = ctx.r6.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266ED44;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,14368
	ctx.r4.s64 = ctx.r4.s64 + 14368;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266ED5C;
	sub_82633D40(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,14400
	ctx.r4.s64 = ctx.r3.s64 + 14400;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266ED74;
	sub_82633D40(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r27,r31,1616
	r27.s64 = r31.s64 + 1616;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14456
	ctx.r4.s64 = r11.s64 + 14456;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266ED8C;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r26,r31,1824
	r26.s64 = r31.s64 + 1824;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,14428
	ctx.r4.s64 = ctx.r10.s64 + 14428;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266EDA4;
	sub_82633D40(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r25,r31,2032
	r25.s64 = r31.s64 + 2032;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,14340
	ctx.r4.s64 = ctx.r9.s64 + 14340;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266EDBC;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r25,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r25.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266EE5C"))) PPC_WEAK_FUNC(sub_8266EE5C);
PPC_FUNC_IMPL(__imp__sub_8266EE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266EE60"))) PPC_WEAK_FUNC(sub_8266EE60);
PPC_FUNC_IMPL(__imp__sub_8266EE60) {
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
	// addi r30,r31,2032
	r30.s64 = r31.s64 + 2032;
	// lhz r11,2226(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2226);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ee90
	if (cr6.eq) goto loc_8266EE90;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EE90;
	sub_82130588(ctx, base);
loc_8266EE90:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EE98;
	sub_82633B00(ctx, base);
	// lhz r11,2018(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2018);
	// addi r30,r31,1824
	r30.s64 = r31.s64 + 1824;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266eeb0
	if (cr6.eq) goto loc_8266EEB0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EEB0;
	sub_82130588(ctx, base);
loc_8266EEB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EEB8;
	sub_82633B00(ctx, base);
	// lhz r11,1810(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1810);
	// addi r30,r31,1616
	r30.s64 = r31.s64 + 1616;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266eed0
	if (cr6.eq) goto loc_8266EED0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EED0;
	sub_82130588(ctx, base);
loc_8266EED0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EED8;
	sub_82633B00(ctx, base);
	// lhz r11,1602(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1602);
	// addi r30,r31,1408
	r30.s64 = r31.s64 + 1408;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266eef0
	if (cr6.eq) goto loc_8266EEF0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EEF0;
	sub_82130588(ctx, base);
loc_8266EEF0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EEF8;
	sub_82633B00(ctx, base);
	// lhz r11,1394(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1394);
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ef10
	if (cr6.eq) goto loc_8266EF10;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EF10;
	sub_82130588(ctx, base);
loc_8266EF10:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EF18;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1186);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ef30
	if (cr6.eq) goto loc_8266EF30;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EF30;
	sub_82130588(ctx, base);
loc_8266EF30:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EF38;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266EF40;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266EF58"))) PPC_WEAK_FUNC(sub_8266EF58);
PPC_FUNC_IMPL(__imp__sub_8266EF58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8266EF60;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266EF6C;
	sub_82654318(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r29,r30,992
	r29.s64 = r30.s64 + 992;
	// addi r10,r11,19548
	ctx.r10.s64 = r11.s64 + 19548;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r28,9
	r28.s64 = 9;
	// li r31,0
	r31.s64 = 0;
	// addi r27,r11,14724
	r27.s64 = r11.s64 + 14724;
	// addi r26,r10,3998
	r26.s64 = ctx.r10.s64 + 3998;
loc_8266EF94:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266EFA4;
	sub_82633D40(ctx, base);
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// stw r31,220(r29)
	PPC_STORE_U32(r29.u32 + 220, r31.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r31,216(r29)
	PPC_STORE_U32(r29.u32 + 216, r31.u32);
	// stw r31,316(r29)
	PPC_STORE_U32(r29.u32 + 316, r31.u32);
	// stw r31,312(r29)
	PPC_STORE_U32(r29.u32 + 312, r31.u32);
	// stw r31,208(r29)
	PPC_STORE_U32(r29.u32 + 208, r31.u32);
	// stw r31,308(r29)
	PPC_STORE_U32(r29.u32 + 308, r31.u32);
	// stw r31,212(r29)
	PPC_STORE_U32(r29.u32 + 212, r31.u32);
	// stw r31,320(r29)
	PPC_STORE_U32(r29.u32 + 320, r31.u32);
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// bge 0x8266ef94
	if (!cr0.lt) goto loc_8266EF94;
	// addi r11,r30,4352
	r11.s64 = r30.s64 + 4352;
	// stw r31,4352(r30)
	PPC_STORE_U32(r30.u32 + 4352, r31.u32);
	// stw r31,4356(r30)
	PPC_STORE_U32(r30.u32 + 4356, r31.u32);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
	// stw r31,4360(r30)
	PPC_STORE_U32(r30.u32 + 4360, r31.u32);
	// stw r31,4364(r30)
	PPC_STORE_U32(r30.u32 + 4364, r31.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r31,4368(r30)
	PPC_STORE_U32(r30.u32 + 4368, r31.u32);
	// stw r31,4372(r30)
	PPC_STORE_U32(r30.u32 + 4372, r31.u32);
	// stw r31,4376(r30)
	PPC_STORE_U32(r30.u32 + 4376, r31.u32);
	// stw r31,4380(r30)
	PPC_STORE_U32(r30.u32 + 4380, r31.u32);
	// stw r31,4384(r30)
	PPC_STORE_U32(r30.u32 + 4384, r31.u32);
	// stw r31,4388(r30)
	PPC_STORE_U32(r30.u32 + 4388, r31.u32);
	// stw r31,4392(r30)
	PPC_STORE_U32(r30.u32 + 4392, r31.u32);
	// stw r31,4396(r30)
	PPC_STORE_U32(r30.u32 + 4396, r31.u32);
	// stw r31,4400(r30)
	PPC_STORE_U32(r30.u32 + 4400, r31.u32);
	// stw r31,4404(r30)
	PPC_STORE_U32(r30.u32 + 4404, r31.u32);
	// stw r31,4408(r30)
	PPC_STORE_U32(r30.u32 + 4408, r31.u32);
	// stw r31,4412(r30)
	PPC_STORE_U32(r30.u32 + 4412, r31.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266F028:
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8266f028
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266F028;
	// addi r10,r30,4428
	ctx.r10.s64 = r30.s64 + 4428;
	// stb r31,72(r11)
	PPC_STORE_U8(r11.u32 + 72, r31.u8);
	// stb r31,73(r11)
	PPC_STORE_U8(r11.u32 + 73, r31.u8);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// stw r31,4428(r30)
	PPC_STORE_U32(r30.u32 + 4428, r31.u32);
	// stw r31,4432(r30)
	PPC_STORE_U32(r30.u32 + 4432, r31.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r31,4436(r30)
	PPC_STORE_U32(r30.u32 + 4436, r31.u32);
	// stw r31,4440(r30)
	PPC_STORE_U32(r30.u32 + 4440, r31.u32);
	// stw r31,4444(r30)
	PPC_STORE_U32(r30.u32 + 4444, r31.u32);
	// stw r31,4448(r30)
	PPC_STORE_U32(r30.u32 + 4448, r31.u32);
	// stw r31,4452(r30)
	PPC_STORE_U32(r30.u32 + 4452, r31.u32);
	// stw r31,4456(r30)
	PPC_STORE_U32(r30.u32 + 4456, r31.u32);
	// stw r31,4460(r30)
	PPC_STORE_U32(r30.u32 + 4460, r31.u32);
	// stw r31,4464(r30)
	PPC_STORE_U32(r30.u32 + 4464, r31.u32);
	// stw r31,4468(r30)
	PPC_STORE_U32(r30.u32 + 4468, r31.u32);
	// stw r31,4472(r30)
	PPC_STORE_U32(r30.u32 + 4472, r31.u32);
	// stw r31,4476(r30)
	PPC_STORE_U32(r30.u32 + 4476, r31.u32);
	// stw r31,4480(r30)
	PPC_STORE_U32(r30.u32 + 4480, r31.u32);
	// stw r31,4484(r30)
	PPC_STORE_U32(r30.u32 + 4484, r31.u32);
	// stw r31,4488(r30)
	PPC_STORE_U32(r30.u32 + 4488, r31.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266F090:
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266f090
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266F090;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r31,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, r31.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r31,73(r10)
	PPC_STORE_U8(ctx.r10.u32 + 73, r31.u8);
	// stw r31,4504(r30)
	PPC_STORE_U32(r30.u32 + 4504, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,4508(r30)
	PPC_STORE_U32(r30.u32 + 4508, r31.u32);
	// stw r31,4512(r30)
	PPC_STORE_U32(r30.u32 + 4512, r31.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r31,4516(r30)
	PPC_STORE_U8(r30.u32 + 4516, r31.u8);
	// stfs f0,4520(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4520, temp.u32);
	// stb r9,4517(r30)
	PPC_STORE_U8(r30.u32 + 4517, ctx.r9.u8);
	// stb r31,4524(r30)
	PPC_STORE_U8(r30.u32 + 4524, r31.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266F0D8"))) PPC_WEAK_FUNC(sub_8266F0D8);
PPC_FUNC_IMPL(__imp__sub_8266F0D8) {
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
	ctx.lr = 0x8266F0E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,9
	r30.s64 = 9;
	// addi r31,r29,4352
	r31.s64 = r29.s64 + 4352;
loc_8266F0F0:
	// addi r31,r31,-336
	r31.s64 = r31.s64 + -336;
	// lhz r11,194(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f108
	if (cr6.eq) goto loc_8266F108;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266F108;
	sub_82130588(ctx, base);
loc_8266F108:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266F110;
	sub_82633B00(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8266f0f0
	if (!cr0.lt) goto loc_8266F0F0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266F120;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266F128"))) PPC_WEAK_FUNC(sub_8266F128);
PPC_FUNC_IMPL(__imp__sub_8266F128) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8266F130;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29060
	ctx.r8.s64 = r11.s64 + 29060;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,6
	ctx.r9.s64 = 6;
	// li r7,6
	ctx.r7.s64 = 6;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ef58
	ctx.lr = 0x8266F160;
	sub_8266EF58(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r20,r10,14704
	r20.s64 = ctx.r10.s64 + 14704;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r7,r8,20356
	ctx.r7.s64 = ctx.r8.s64 + 20356;
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// li r29,0
	r29.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r21,r11,212
	r21.s64 = r11.s64 + 212;
	// addi r11,r31,4544
	r11.s64 = r31.s64 + 4544;
	// stw r29,4548(r31)
	PPC_STORE_U32(r31.u32 + 4548, r29.u32);
	// addi r30,r10,560
	r30.s64 = ctx.r10.s64 + 560;
	// stw r29,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r29.u32);
	// lis r11,8192
	r11.s64 = 536870912;
	// stw r29,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r29.u32);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// stw r21,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r21.u32);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stw r20,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, r20.u32);
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// lis r7,4096
	ctx.r7.s64 = 268435456;
	// li r23,9
	r23.s64 = 9;
	// li r22,5
	r22.s64 = 5;
	// ori r24,r11,44
	r24.u64 = r11.u64 | 44;
	// ori r25,r10,36
	r25.u64 = ctx.r10.u64 | 36;
	// ori r26,r9,42
	r26.u64 = ctx.r9.u64 | 42;
	// ori r27,r8,41
	r27.u64 = ctx.r8.u64 | 41;
	// ori r28,r7,43
	r28.u64 = ctx.r7.u64 | 43;
loc_8266F1D0:
	// addi r3,r30,-536
	ctx.r3.s64 = r30.s64 + -536;
	// bl 0x824f9438
	ctx.lr = 0x8266F1D8;
	sub_824F9438(ctx, base);
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r11,r30,-512
	r11.s64 = r30.s64 + -512;
	// stw r22,-512(r30)
	PPC_STORE_U32(r30.u32 + -512, r22.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// std r29,-508(r30)
	PPC_STORE_U64(r30.u32 + -508, r29.u64);
	// stw r24,-500(r30)
	PPC_STORE_U32(r30.u32 + -500, r24.u32);
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// stw r25,-488(r30)
	PPC_STORE_U32(r30.u32 + -488, r25.u32);
	// stw r26,-480(r30)
	PPC_STORE_U32(r30.u32 + -480, r26.u32);
	// stw r27,-472(r30)
	PPC_STORE_U32(r30.u32 + -472, r27.u32);
	// stw r28,-464(r30)
	PPC_STORE_U32(r30.u32 + -464, r28.u32);
	// stb r9,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r9.u8);
	// stw r11,-520(r30)
	PPC_STORE_U32(r30.u32 + -520, r11.u32);
	// addi r30,r30,568
	r30.s64 = r30.s64 + 568;
	// bge 0x8266f1d0
	if (!cr0.lt) goto loc_8266F1D0;
	// stw r29,10252(r31)
	PPC_STORE_U32(r31.u32 + 10252, r29.u32);
	// addi r30,r31,10272
	r30.s64 = r31.s64 + 10272;
	// stw r29,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r29.u32);
	// addi r11,r31,10248
	r11.s64 = r31.s64 + 10248;
	// stw r29,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, r29.u32);
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// stw r21,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, r21.u32);
	// stw r20,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, r20.u32);
	// bl 0x824f9438
	ctx.lr = 0x8266F238;
	sub_824F9438(ctx, base);
	// lbz r6,10832(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 10832);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r22,10320(r31)
	PPC_STORE_U32(r31.u32 + 10320, r22.u32);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// std r29,10324(r31)
	PPC_STORE_U64(r31.u32 + 10324, r29.u64);
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// stw r24,10332(r31)
	PPC_STORE_U32(r31.u32 + 10332, r24.u32);
	// addi r9,r10,292
	ctx.r9.s64 = ctx.r10.s64 + 292;
	// stw r25,10344(r31)
	PPC_STORE_U32(r31.u32 + 10344, r25.u32);
	// stw r26,10352(r31)
	PPC_STORE_U32(r31.u32 + 10352, r26.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r27,10360(r31)
	PPC_STORE_U32(r31.u32 + 10360, r27.u32);
	// addi r10,r31,880
	ctx.r10.s64 = r31.s64 + 880;
	// stw r28,10368(r31)
	PPC_STORE_U32(r31.u32 + 10368, r28.u32);
	// addi r7,r8,29500
	ctx.r7.s64 = ctx.r8.s64 + 29500;
	// stb r5,10832(r31)
	PPC_STORE_U8(r31.u32 + 10832, ctx.r5.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,10312(r31)
	PPC_STORE_U32(r31.u32 + 10312, r11.u32);
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// lhz r4,884(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// sth r11,884(r31)
	PPC_STORE_U16(r31.u32 + 884, r11.u16);
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r11,29500(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 29500);
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r9,884(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,12(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,16(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,20(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8266F348"))) PPC_WEAK_FUNC(sub_8266F348);
PPC_FUNC_IMPL(__imp__sub_8266F348) {
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
	ctx.lr = 0x8266F350;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266F370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266f64c
	if (cr6.eq) goto loc_8266F64C;
	// lfs f0,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,4520(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// bl 0x82388580
	ctx.lr = 0x8266F390;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266F3A0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8266F3A8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f3e0
	if (cr6.eq) goto loc_8266F3E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266F3BC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266F3CC;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x8266F3D4;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266f414
	if (!cr6.eq) goto loc_8266F414;
loc_8266F3E0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,21160
	ctx.r4.s64 = ctx.r10.s64 + 21160;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x8266F3FC;
	sub_82289AB0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82643bb8
	ctx.lr = 0x8266F414;
	sub_82643BB8(ctx, base);
loc_8266F414:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r28,r31,4352
	r28.s64 = r31.s64 + 4352;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x8266f528
	if (cr6.eq) goto loc_8266F528;
loc_8266F430:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266f520
	if (cr6.eq) goto loc_8266F520;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266f430
	if (cr6.lt) goto loc_8266F430;
	// li r11,1
	r11.s64 = 1;
loc_8266F450:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f630
	if (cr6.eq) goto loc_8266F630;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f630
	if (cr6.eq) goto loc_8266F630;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8266f500
	if (!cr6.gt) goto loc_8266F500;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_8266F47C:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x8266f500
	if (!cr6.lt) goto loc_8266F500;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266F4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x8266f4e0
	if (cr6.lt) goto loc_8266F4E0;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_8266F4E0:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266afe8
	ctx.lr = 0x8266F4EC;
	sub_8266AFE8(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8266f47c
	if (cr6.lt) goto loc_8266F47C;
loc_8266F500:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266F510:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266f510
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266F510;
	// b 0x8266f614
	goto loc_8266F614;
loc_8266F520:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8266f450
	goto loc_8266F450;
loc_8266F528:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266f658
	if (cr6.eq) goto loc_8266F658;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266f528
	if (cr6.lt) goto loc_8266F528;
	// li r11,1
	r11.s64 = 1;
loc_8266F548:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f630
	if (cr6.eq) goto loc_8266F630;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f630
	if (cr6.eq) goto loc_8266F630;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8266f5f8
	if (!cr6.gt) goto loc_8266F5F8;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_8266F574:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x8266f5f8
	if (!cr6.lt) goto loc_8266F5F8;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266F598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x8266f5d8
	if (cr6.lt) goto loc_8266F5D8;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_8266F5D8:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266afe8
	ctx.lr = 0x8266F5E4;
	sub_8266AFE8(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8266f574
	if (cr6.lt) goto loc_8266F574;
loc_8266F5F8:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266F608:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266f608
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266F608;
loc_8266F614:
	// stb r27,73(r28)
	PPC_STORE_U8(r28.u32 + 73, r27.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r27,72(r28)
	PPC_STORE_U8(r28.u32 + 72, r27.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266F630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8266F630:
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8266f648
	if (cr6.eq) goto loc_8266F648;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8266F648:
	// bl 0x8266caf8
	ctx.lr = 0x8266F64C;
	sub_8266CAF8(ctx, base);
loc_8266F64C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8266F658:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8266f548
	goto loc_8266F548;
}

__attribute__((alias("__imp__sub_8266F660"))) PPC_WEAK_FUNC(sub_8266F660);
PPC_FUNC_IMPL(__imp__sub_8266F660) {
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
	ctx.lr = 0x8266F668;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// li r31,9
	r31.s64 = 9;
loc_8266F678:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9438
	ctx.lr = 0x8266F680;
	sub_824F9438(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bge 0x8266f678
	if (!cr0.lt) goto loc_8266F678;
	// li r26,0
	r26.s64 = 0;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// mr r31,r26
	r31.u64 = r26.u64;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8266F69C:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x8266F6A8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266F6B8;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// add r9,r30,r31
	ctx.r9.u64 = r30.u64 + r31.u64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8266f6fc
	if (cr6.gt) goto loc_8266F6FC;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x8266F6D4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266F6E4;
	sub_82270170(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = r30.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mulli r11,r10,196
	r11.s64 = ctx.r10.s64 * 196;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,312
	ctx.r3.s64 = r11.s64 + 312;
	// bl 0x82500658
	ctx.lr = 0x8266F6FC;
	sub_82500658(ctx, base);
loc_8266F6FC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpwi cr6,r31,10
	cr6.compare<int32_t>(r31.s32, 10, xer);
	// blt cr6,0x8266f69c
	if (cr6.lt) goto loc_8266F69C;
	// lhz r11,852(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 852);
	// addi r8,r28,848
	ctx.r8.s64 = r28.s64 + 848;
	// lwz r9,848(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266f744
	if (cr6.eq) goto loc_8266F744;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_8266F730:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266f730
	if (!cr6.eq) goto loc_8266F730;
loc_8266F744:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r28,1180
	ctx.r9.s64 = r28.s64 + 1180;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// li r5,10
	ctx.r5.s64 = 10;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
loc_8266F760:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266f798
	if (cr6.eq) goto loc_8266F798;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_8266F784:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266f784
	if (!cr6.eq) goto loc_8266F784;
loc_8266F798:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,336
	ctx.r9.s64 = ctx.r9.s64 + 336;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// bne 0x8266f760
	if (!cr0.eq) goto loc_8266F760;
	// stw r26,4504(r28)
	PPC_STORE_U32(r28.u32 + 4504, r26.u32);
	// addi r11,r28,4352
	r11.s64 = r28.s64 + 4352;
	// stw r26,4508(r28)
	PPC_STORE_U32(r28.u32 + 4508, r26.u32);
	// lwz r10,4352(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4352);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8266f7f0
	if (cr6.eq) goto loc_8266F7F0;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266f7f0
	if (!cr6.eq) goto loc_8266F7F0;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// stb r10,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r10.u8);
	// stb r10,73(r11)
	PPC_STORE_U8(r11.u32 + 73, ctx.r10.u8);
	// b 0x8266f7f4
	goto loc_8266F7F4;
loc_8266F7F0:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8266F7F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266F7FC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r28,4544
	r29.s64 = r28.s64 + 4544;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266F814;
	sub_82270170(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82272df8
	ctx.lr = 0x8266F828;
	sub_82272DF8(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266F830"))) PPC_WEAK_FUNC(sub_8266F830);
PPC_FUNC_IMPL(__imp__sub_8266F830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8266F838;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29060
	ctx.r8.s64 = r11.s64 + 29060;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,6
	ctx.r9.s64 = 6;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ef58
	ctx.lr = 0x8266F868;
	sub_8266EF58(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r22,r10,-18644
	r22.s64 = ctx.r10.s64 + -18644;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// addi r7,r8,21180
	ctx.r7.s64 = ctx.r8.s64 + 21180;
	// li r30,0
	r30.s64 = 0;
	// addi r23,r11,19036
	r23.s64 = r11.s64 + 19036;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r11,r31,4544
	r11.s64 = r31.s64 + 4544;
	// stw r30,4548(r31)
	PPC_STORE_U32(r31.u32 + 4548, r30.u32);
	// addi r29,r10,560
	r29.s64 = ctx.r10.s64 + 560;
	// stw r30,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r30.u32);
	// lis r11,4096
	r11.s64 = 268435456;
	// stw r30,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r30.u32);
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// stw r23,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r23.u32);
	// lis r9,8192
	ctx.r9.s64 = 536870912;
	// stw r22,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, r22.u32);
	// li r25,9
	r25.s64 = 9;
	// li r24,3
	r24.s64 = 3;
	// ori r26,r11,27
	r26.u64 = r11.u64 | 27;
	// ori r27,r10,30
	r27.u64 = ctx.r10.u64 | 30;
	// ori r28,r9,31
	r28.u64 = ctx.r9.u64 | 31;
loc_8266F8C8:
	// addi r3,r29,-536
	ctx.r3.s64 = r29.s64 + -536;
	// bl 0x824f9438
	ctx.lr = 0x8266F8D0;
	sub_824F9438(ctx, base);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r11,r29,-512
	r11.s64 = r29.s64 + -512;
	// stw r24,-512(r29)
	PPC_STORE_U32(r29.u32 + -512, r24.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// std r30,-508(r29)
	PPC_STORE_U64(r29.u32 + -508, r30.u64);
	// stw r26,-500(r29)
	PPC_STORE_U32(r29.u32 + -500, r26.u32);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// stw r27,-492(r29)
	PPC_STORE_U32(r29.u32 + -492, r27.u32);
	// stw r28,-480(r29)
	PPC_STORE_U32(r29.u32 + -480, r28.u32);
	// stb r9,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r9.u8);
	// stw r11,-520(r29)
	PPC_STORE_U32(r29.u32 + -520, r11.u32);
	// addi r29,r29,568
	r29.s64 = r29.s64 + 568;
	// bge 0x8266f8c8
	if (!cr0.lt) goto loc_8266F8C8;
	// stw r30,10252(r31)
	PPC_STORE_U32(r31.u32 + 10252, r30.u32);
	// addi r29,r31,10272
	r29.s64 = r31.s64 + 10272;
	// stw r30,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r30.u32);
	// addi r11,r31,10248
	r11.s64 = r31.s64 + 10248;
	// stw r30,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, r30.u32);
	// addi r3,r29,24
	ctx.r3.s64 = r29.s64 + 24;
	// stw r23,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, r23.u32);
	// stw r22,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, r22.u32);
	// bl 0x824f9438
	ctx.lr = 0x8266F928;
	sub_824F9438(ctx, base);
	// lbz r6,10832(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 10832);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r24,10320(r31)
	PPC_STORE_U32(r31.u32 + 10320, r24.u32);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// std r30,10324(r31)
	PPC_STORE_U64(r31.u32 + 10324, r30.u64);
	// addi r11,r29,48
	r11.s64 = r29.s64 + 48;
	// stw r26,10332(r31)
	PPC_STORE_U32(r31.u32 + 10332, r26.u32);
	// addi r9,r10,19116
	ctx.r9.s64 = ctx.r10.s64 + 19116;
	// stw r27,10340(r31)
	PPC_STORE_U32(r31.u32 + 10340, r27.u32);
	// stw r28,10352(r31)
	PPC_STORE_U32(r31.u32 + 10352, r28.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stb r5,10832(r31)
	PPC_STORE_U8(r31.u32 + 10832, ctx.r5.u8);
	// addi r10,r31,880
	ctx.r10.s64 = r31.s64 + 880;
	// stw r11,10312(r31)
	PPC_STORE_U32(r31.u32 + 10312, r11.u32);
	// addi r7,r8,29524
	ctx.r7.s64 = ctx.r8.s64 + 29524;
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,10848(r31)
	PPC_STORE_U32(r31.u32 + 10848, r30.u32);
	// sth r30,10852(r31)
	PPC_STORE_U16(r31.u32 + 10852, r30.u16);
	// sth r30,10854(r31)
	PPC_STORE_U16(r31.u32 + 10854, r30.u16);
	// stw r30,10856(r31)
	PPC_STORE_U32(r31.u32 + 10856, r30.u32);
	// lhz r4,884(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// sth r11,884(r31)
	PPC_STORE_U16(r31.u32 + 884, r11.u16);
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r11,29524(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 29524);
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,12(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8266FA00"))) PPC_WEAK_FUNC(sub_8266FA00);
PPC_FUNC_IMPL(__imp__sub_8266FA00) {
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
	ctx.lr = 0x8266FA08;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266FA28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266fd04
	if (cr6.eq) goto loc_8266FD04;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266FA3C;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266FA4C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8266FA54;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fa8c
	if (cr6.eq) goto loc_8266FA8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266FA68;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266FA78;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x8266FA80;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266fac0
	if (!cr6.eq) goto loc_8266FAC0;
loc_8266FA8C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,21160
	ctx.r4.s64 = ctx.r10.s64 + 21160;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x8266FAA8;
	sub_82289AB0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82643bb8
	ctx.lr = 0x8266FAC0;
	sub_82643BB8(ctx, base);
loc_8266FAC0:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// lfs f0,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	f0.f64 = double(temp.f32);
	// addi r28,r31,4352
	r28.s64 = r31.s64 + 4352;
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// li r27,0
	r27.s64 = 0;
	// stfs f13,4520(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x8266fbe0
	if (cr6.eq) goto loc_8266FBE0;
loc_8266FAE8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266fbd8
	if (cr6.eq) goto loc_8266FBD8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266fae8
	if (cr6.lt) goto loc_8266FAE8;
	// li r11,1
	r11.s64 = 1;
loc_8266FB08:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fce8
	if (cr6.eq) goto loc_8266FCE8;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fce8
	if (cr6.eq) goto loc_8266FCE8;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8266fbb8
	if (!cr6.gt) goto loc_8266FBB8;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_8266FB34:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x8266fbb8
	if (!cr6.lt) goto loc_8266FBB8;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266FB58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x8266fb98
	if (cr6.lt) goto loc_8266FB98;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_8266FB98:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b2a0
	ctx.lr = 0x8266FBA4;
	sub_8266B2A0(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8266fb34
	if (cr6.lt) goto loc_8266FB34;
loc_8266FBB8:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266FBC8:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266fbc8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266FBC8;
	// b 0x8266fccc
	goto loc_8266FCCC;
loc_8266FBD8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8266fb08
	goto loc_8266FB08;
loc_8266FBE0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266fd10
	if (cr6.eq) goto loc_8266FD10;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266fbe0
	if (cr6.lt) goto loc_8266FBE0;
	// li r11,1
	r11.s64 = 1;
loc_8266FC00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fce8
	if (cr6.eq) goto loc_8266FCE8;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fce8
	if (cr6.eq) goto loc_8266FCE8;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8266fcb0
	if (!cr6.gt) goto loc_8266FCB0;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_8266FC2C:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x8266fcb0
	if (!cr6.lt) goto loc_8266FCB0;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266FC50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x8266fc90
	if (cr6.lt) goto loc_8266FC90;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_8266FC90:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b2a0
	ctx.lr = 0x8266FC9C;
	sub_8266B2A0(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8266fc2c
	if (cr6.lt) goto loc_8266FC2C;
loc_8266FCB0:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266FCC0:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266fcc0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266FCC0;
loc_8266FCCC:
	// stb r27,73(r28)
	PPC_STORE_U8(r28.u32 + 73, r27.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r27,72(r28)
	PPC_STORE_U8(r28.u32 + 72, r27.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266FCE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8266FCE8:
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8266fd00
	if (cr6.eq) goto loc_8266FD00;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8266FD00:
	// bl 0x8266d030
	ctx.lr = 0x8266FD04;
	sub_8266D030(ctx, base);
loc_8266FD04:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8266FD10:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8266fc00
	goto loc_8266FC00;
}

__attribute__((alias("__imp__sub_8266FD18"))) PPC_WEAK_FUNC(sub_8266FD18);
PPC_FUNC_IMPL(__imp__sub_8266FD18) {
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
	ctx.lr = 0x8266FD20;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// li r31,9
	r31.s64 = 9;
loc_8266FD30:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9438
	ctx.lr = 0x8266FD38;
	sub_824F9438(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bge 0x8266fd30
	if (!cr0.lt) goto loc_8266FD30;
	// li r25,0
	r25.s64 = 0;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// mr r27,r25
	r27.u64 = r25.u64;
	// mr r31,r25
	r31.u64 = r25.u64;
	// lis r26,-32121
	r26.s64 = -2105081856;
loc_8266FD58:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x8266FD64;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266FD74;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// add r9,r30,r31
	ctx.r9.u64 = r30.u64 + r31.u64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8266fdbc
	if (cr6.gt) goto loc_8266FDBC;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x8266FD90;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266FDA0;
	sub_82270170(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = r30.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mulli r11,r10,196
	r11.s64 = ctx.r10.s64 * 196;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,312
	ctx.r3.s64 = r11.s64 + 312;
	// bl 0x82500658
	ctx.lr = 0x8266FDB8;
	sub_82500658(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_8266FDBC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpwi cr6,r31,10
	cr6.compare<int32_t>(r31.s32, 10, xer);
	// blt cr6,0x8266fd58
	if (cr6.lt) goto loc_8266FD58;
	// lhz r11,852(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 852);
	// addi r8,r28,848
	ctx.r8.s64 = r28.s64 + 848;
	// lwz r9,848(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266fe04
	if (cr6.eq) goto loc_8266FE04;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_8266FDF0:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266fdf0
	if (!cr6.eq) goto loc_8266FDF0;
loc_8266FE04:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r28,1180
	ctx.r9.s64 = r28.s64 + 1180;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// li r5,10
	ctx.r5.s64 = 10;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
loc_8266FE20:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266fe58
	if (cr6.eq) goto loc_8266FE58;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_8266FE44:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266fe44
	if (!cr6.eq) goto loc_8266FE44;
loc_8266FE58:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,336
	ctx.r9.s64 = ctx.r9.s64 + 336;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// bne 0x8266fe20
	if (!cr0.eq) goto loc_8266FE20;
	// stw r25,4504(r28)
	PPC_STORE_U32(r28.u32 + 4504, r25.u32);
	// addi r11,r28,4352
	r11.s64 = r28.s64 + 4352;
	// stw r25,4508(r28)
	PPC_STORE_U32(r28.u32 + 4508, r25.u32);
	// lwz r10,4352(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4352);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8266feb0
	if (cr6.eq) goto loc_8266FEB0;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266feb0
	if (!cr6.eq) goto loc_8266FEB0;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// stb r10,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r10.u8);
	// stb r10,73(r11)
	PPC_STORE_U8(r11.u32 + 73, ctx.r10.u8);
	// b 0x8266feb4
	goto loc_8266FEB4;
loc_8266FEB0:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_8266FEB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266FEBC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r28,4544
	r29.s64 = r28.s64 + 4544;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266FED4;
	sub_82270170(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82272df8
	ctx.lr = 0x8266FEE8;
	sub_82272DF8(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266FEF0"))) PPC_WEAK_FUNC(sub_8266FEF0);
PPC_FUNC_IMPL(__imp__sub_8266FEF0) {
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
	ctx.lr = 0x8266FEF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// addi r30,r31,10848
	r30.s64 = r31.s64 + 10848;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// stw r5,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, ctx.r5.u32);
	// stw r6,10856(r31)
	PPC_STORE_U32(r31.u32 + 10856, ctx.r6.u32);
	// stw r7,10860(r31)
	PPC_STORE_U32(r31.u32 + 10860, ctx.r7.u32);
	// beq cr6,0x8266ff50
	if (cr6.eq) goto loc_8266FF50;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8266ff44
	if (cr6.eq) goto loc_8266FF44;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ff44
	if (cr6.eq) goto loc_8266FF44;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8266FF44;
	sub_82130588(ctx, base);
loc_8266FF44:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c7480
	ctx.lr = 0x8266FF50;
	sub_826C7480(ctx, base);
loc_8266FF50:
	// li r11,0
	r11.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r11,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8266FF64;
	sub_82630318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266FF6C"))) PPC_WEAK_FUNC(sub_8266FF6C);
PPC_FUNC_IMPL(__imp__sub_8266FF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266FF70"))) PPC_WEAK_FUNC(sub_8266FF70);
PPC_FUNC_IMPL(__imp__sub_8266FF70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8266FF78;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r20,r11,3998
	r20.s64 = r11.s64 + 3998;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r10,28652
	ctx.r8.s64 = ctx.r10.s64 + 28652;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ef58
	ctx.lr = 0x8266FFAC;
	sub_8266EF58(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r23,r10,-18644
	r23.s64 = ctx.r10.s64 + -18644;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r31,4576
	ctx.r10.s64 = r31.s64 + 4576;
	// addi r7,r8,21988
	ctx.r7.s64 = ctx.r8.s64 + 21988;
	// li r30,0
	r30.s64 = 0;
	// addi r24,r11,19036
	r24.s64 = r11.s64 + 19036;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r11,r31,4552
	r11.s64 = r31.s64 + 4552;
	// stw r30,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r30.u32);
	// addi r26,r10,560
	r26.s64 = ctx.r10.s64 + 560;
	// stw r30,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r30.u32);
	// li r25,3
	r25.s64 = 3;
	// stw r30,4564(r31)
	PPC_STORE_U32(r31.u32 + 4564, r30.u32);
	// lis r11,4096
	r11.s64 = 268435456;
	// stw r24,4568(r31)
	PPC_STORE_U32(r31.u32 + 4568, r24.u32);
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// stw r23,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r23.u32);
	// lis r9,8192
	ctx.r9.s64 = 536870912;
	// mr r22,r25
	r22.u64 = r25.u64;
	// ori r27,r11,27
	r27.u64 = r11.u64 | 27;
	// ori r28,r10,30
	r28.u64 = ctx.r10.u64 | 30;
	// ori r29,r9,31
	r29.u64 = ctx.r9.u64 | 31;
loc_8267000C:
	// addi r3,r26,-536
	ctx.r3.s64 = r26.s64 + -536;
	// bl 0x824f9438
	ctx.lr = 0x82670014;
	sub_824F9438(ctx, base);
	// lbz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// addi r11,r26,-512
	r11.s64 = r26.s64 + -512;
	// stw r25,-512(r26)
	PPC_STORE_U32(r26.u32 + -512, r25.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// std r30,-508(r26)
	PPC_STORE_U64(r26.u32 + -508, r30.u64);
	// stw r27,-500(r26)
	PPC_STORE_U32(r26.u32 + -500, r27.u32);
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// stw r28,-492(r26)
	PPC_STORE_U32(r26.u32 + -492, r28.u32);
	// stw r29,-480(r26)
	PPC_STORE_U32(r26.u32 + -480, r29.u32);
	// stb r9,0(r26)
	PPC_STORE_U8(r26.u32 + 0, ctx.r9.u8);
	// stw r11,-520(r26)
	PPC_STORE_U32(r26.u32 + -520, r11.u32);
	// addi r26,r26,568
	r26.s64 = r26.s64 + 568;
	// bge 0x8267000c
	if (!cr0.lt) goto loc_8267000C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r26,r31,6848
	r26.s64 = r31.s64 + 6848;
	// mr r22,r25
	r22.u64 = r25.u64;
	// addi r21,r11,14724
	r21.s64 = r11.s64 + 14724;
loc_82670058:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x82670068;
	sub_82633D40(ctx, base);
	// stw r21,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r21.u32);
	// stw r30,220(r26)
	PPC_STORE_U32(r26.u32 + 220, r30.u32);
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// stw r30,216(r26)
	PPC_STORE_U32(r26.u32 + 216, r30.u32);
	// stw r30,316(r26)
	PPC_STORE_U32(r26.u32 + 316, r30.u32);
	// stw r30,312(r26)
	PPC_STORE_U32(r26.u32 + 312, r30.u32);
	// stw r30,208(r26)
	PPC_STORE_U32(r26.u32 + 208, r30.u32);
	// stw r30,308(r26)
	PPC_STORE_U32(r26.u32 + 308, r30.u32);
	// stw r30,212(r26)
	PPC_STORE_U32(r26.u32 + 212, r30.u32);
	// stw r30,320(r26)
	PPC_STORE_U32(r26.u32 + 320, r30.u32);
	// addi r26,r26,336
	r26.s64 = r26.s64 + 336;
	// bge 0x82670058
	if (!cr0.lt) goto loc_82670058;
	// stw r30,8224(r31)
	PPC_STORE_U32(r31.u32 + 8224, r30.u32);
	// addi r26,r31,8248
	r26.s64 = r31.s64 + 8248;
	// stw r30,8228(r31)
	PPC_STORE_U32(r31.u32 + 8228, r30.u32);
	// addi r11,r31,8220
	r11.s64 = r31.s64 + 8220;
	// stw r30,8232(r31)
	PPC_STORE_U32(r31.u32 + 8232, r30.u32);
	// addi r3,r26,24
	ctx.r3.s64 = r26.s64 + 24;
	// stw r24,8236(r31)
	PPC_STORE_U32(r31.u32 + 8236, r24.u32);
	// stw r23,8220(r31)
	PPC_STORE_U32(r31.u32 + 8220, r23.u32);
	// bl 0x824f9438
	ctx.lr = 0x826700BC;
	sub_824F9438(ctx, base);
	// addi r10,r31,8816
	ctx.r10.s64 = r31.s64 + 8816;
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// stw r25,8296(r31)
	PPC_STORE_U32(r31.u32 + 8296, r25.u32);
	// std r30,8300(r31)
	PPC_STORE_U64(r31.u32 + 8300, r30.u64);
	// addi r26,r31,8840
	r26.s64 = r31.s64 + 8840;
	// stw r27,8308(r31)
	PPC_STORE_U32(r31.u32 + 8308, r27.u32);
	// stw r28,8316(r31)
	PPC_STORE_U32(r31.u32 + 8316, r28.u32);
	// addi r3,r26,24
	ctx.r3.s64 = r26.s64 + 24;
	// stw r29,8328(r31)
	PPC_STORE_U32(r31.u32 + 8328, r29.u32);
	// lbz r10,8808(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 8808);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,8808(r31)
	PPC_STORE_U8(r31.u32 + 8808, ctx.r9.u8);
	// stw r11,8288(r31)
	PPC_STORE_U32(r31.u32 + 8288, r11.u32);
	// stw r30,8820(r31)
	PPC_STORE_U32(r31.u32 + 8820, r30.u32);
	// stw r30,8824(r31)
	PPC_STORE_U32(r31.u32 + 8824, r30.u32);
	// stw r30,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, r30.u32);
	// stw r24,8832(r31)
	PPC_STORE_U32(r31.u32 + 8832, r24.u32);
	// stw r23,8816(r31)
	PPC_STORE_U32(r31.u32 + 8816, r23.u32);
	// bl 0x824f9438
	ctx.lr = 0x82670108;
	sub_824F9438(ctx, base);
	// lbz r8,9400(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 9400);
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// stw r25,8888(r31)
	PPC_STORE_U32(r31.u32 + 8888, r25.u32);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// std r30,8892(r31)
	PPC_STORE_U64(r31.u32 + 8892, r30.u64);
	// stw r27,8900(r31)
	PPC_STORE_U32(r31.u32 + 8900, r27.u32);
	// addi r26,r31,9432
	r26.s64 = r31.s64 + 9432;
	// stw r28,8908(r31)
	PPC_STORE_U32(r31.u32 + 8908, r28.u32);
	// addi r10,r31,9408
	ctx.r10.s64 = r31.s64 + 9408;
	// stw r29,8920(r31)
	PPC_STORE_U32(r31.u32 + 8920, r29.u32);
	// addi r3,r26,24
	ctx.r3.s64 = r26.s64 + 24;
	// stb r7,9400(r31)
	PPC_STORE_U8(r31.u32 + 9400, ctx.r7.u8);
	// stw r11,8880(r31)
	PPC_STORE_U32(r31.u32 + 8880, r11.u32);
	// stw r30,9412(r31)
	PPC_STORE_U32(r31.u32 + 9412, r30.u32);
	// stw r30,9416(r31)
	PPC_STORE_U32(r31.u32 + 9416, r30.u32);
	// stw r30,9420(r31)
	PPC_STORE_U32(r31.u32 + 9420, r30.u32);
	// stw r24,9424(r31)
	PPC_STORE_U32(r31.u32 + 9424, r24.u32);
	// stw r23,9408(r31)
	PPC_STORE_U32(r31.u32 + 9408, r23.u32);
	// bl 0x824f9438
	ctx.lr = 0x82670154;
	sub_824F9438(ctx, base);
	// lbz r6,9992(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 9992);
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// stw r25,9480(r31)
	PPC_STORE_U32(r31.u32 + 9480, r25.u32);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// std r30,9484(r31)
	PPC_STORE_U64(r31.u32 + 9484, r30.u64);
	// stw r27,9492(r31)
	PPC_STORE_U32(r31.u32 + 9492, r27.u32);
	// addi r26,r31,10024
	r26.s64 = r31.s64 + 10024;
	// stw r28,9500(r31)
	PPC_STORE_U32(r31.u32 + 9500, r28.u32);
	// stw r29,9512(r31)
	PPC_STORE_U32(r31.u32 + 9512, r29.u32);
	// addi r3,r26,24
	ctx.r3.s64 = r26.s64 + 24;
	// stb r5,9992(r31)
	PPC_STORE_U8(r31.u32 + 9992, ctx.r5.u8);
	// stw r11,9472(r31)
	PPC_STORE_U32(r31.u32 + 9472, r11.u32);
	// addi r11,r31,10000
	r11.s64 = r31.s64 + 10000;
	// stw r30,10004(r31)
	PPC_STORE_U32(r31.u32 + 10004, r30.u32);
	// stw r30,10008(r31)
	PPC_STORE_U32(r31.u32 + 10008, r30.u32);
	// stw r30,10012(r31)
	PPC_STORE_U32(r31.u32 + 10012, r30.u32);
	// stw r24,10016(r31)
	PPC_STORE_U32(r31.u32 + 10016, r24.u32);
	// stw r23,10000(r31)
	PPC_STORE_U32(r31.u32 + 10000, r23.u32);
	// bl 0x824f9438
	ctx.lr = 0x826701A0;
	sub_824F9438(ctx, base);
	// lbz r3,10584(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 10584);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// stw r25,10072(r31)
	PPC_STORE_U32(r31.u32 + 10072, r25.u32);
	// ori r7,r3,128
	ctx.r7.u64 = ctx.r3.u64 | 128;
	// std r30,10076(r31)
	PPC_STORE_U64(r31.u32 + 10076, r30.u64);
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// stw r27,10084(r31)
	PPC_STORE_U32(r31.u32 + 10084, r27.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r28,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r28.u32);
	// stw r29,10104(r31)
	PPC_STORE_U32(r31.u32 + 10104, r29.u32);
	// addi r9,r4,19116
	ctx.r9.s64 = ctx.r4.s64 + 19116;
	// stb r7,10584(r31)
	PPC_STORE_U8(r31.u32 + 10584, ctx.r7.u8);
	// addi r10,r31,880
	ctx.r10.s64 = r31.s64 + 880;
	// addi r6,r8,29524
	ctx.r6.s64 = ctx.r8.s64 + 29524;
	// stw r11,10064(r31)
	PPC_STORE_U32(r31.u32 + 10064, r11.u32);
	// stw r9,10592(r31)
	PPC_STORE_U32(r31.u32 + 10592, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,29524(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 29524);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r9,884(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// stb r30,10600(r31)
	PPC_STORE_U8(r31.u32 + 10600, r30.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82670270"))) PPC_WEAK_FUNC(sub_82670270);
PPC_FUNC_IMPL(__imp__sub_82670270) {
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
	ctx.lr = 0x82670278;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r10,-28
	r30.s64 = ctx.r10.s64 + -28;
	// addi r29,r11,48
	r29.s64 = r11.s64 + 48;
	// stw r30,10592(r31)
	PPC_STORE_U32(r31.u32 + 10592, r30.u32);
	// addi r28,r31,8192
	r28.s64 = r31.s64 + 8192;
	// stw r30,10016(r31)
	PPC_STORE_U32(r31.u32 + 10016, r30.u32);
	// li r27,3
	r27.s64 = 3;
	// stw r29,10000(r31)
	PPC_STORE_U32(r31.u32 + 10000, r29.u32);
	// stw r30,9424(r31)
	PPC_STORE_U32(r31.u32 + 9424, r30.u32);
	// stw r29,9408(r31)
	PPC_STORE_U32(r31.u32 + 9408, r29.u32);
	// stw r30,8832(r31)
	PPC_STORE_U32(r31.u32 + 8832, r30.u32);
	// stw r29,8816(r31)
	PPC_STORE_U32(r31.u32 + 8816, r29.u32);
	// stw r30,8236(r31)
	PPC_STORE_U32(r31.u32 + 8236, r30.u32);
	// stw r29,8220(r31)
	PPC_STORE_U32(r31.u32 + 8220, r29.u32);
loc_826702BC:
	// addi r28,r28,-336
	r28.s64 = r28.s64 + -336;
	// lhz r11,194(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826702d4
	if (cr6.eq) goto loc_826702D4;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826702D4;
	sub_82130588(ctx, base);
loc_826702D4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x826702DC;
	sub_82633B00(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// bge 0x826702bc
	if (!cr0.lt) goto loc_826702BC;
	// stw r30,4568(r31)
	PPC_STORE_U32(r31.u32 + 4568, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r29.u32);
	// bl 0x8266f0d8
	ctx.lr = 0x826702F4;
	sub_8266F0D8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826702FC"))) PPC_WEAK_FUNC(sub_826702FC);
PPC_FUNC_IMPL(__imp__sub_826702FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82670300"))) PPC_WEAK_FUNC(sub_82670300);
PPC_FUNC_IMPL(__imp__sub_82670300) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82670308;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r8,r31,848
	ctx.r8.s64 = r31.s64 + 848;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82670348
	if (cr6.eq) goto loc_82670348;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82670334:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82670334
	if (!cr6.eq) goto loc_82670334;
loc_82670348:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r31,7036
	ctx.r9.s64 = r31.s64 + 7036;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// li r5,4
	ctx.r5.s64 = 4;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
loc_82670364:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8267039c
	if (cr6.eq) goto loc_8267039C;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_82670388:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82670388
	if (!cr6.eq) goto loc_82670388;
loc_8267039C:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,336
	ctx.r9.s64 = ctx.r9.s64 + 336;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// bne 0x82670364
	if (!cr0.eq) goto loc_82670364;
	// addi r11,r31,8248
	r11.s64 = r31.s64 + 8248;
	// li r29,1
	r29.s64 = 1;
	// stw r11,8232(r31)
	PPC_STORE_U32(r31.u32 + 8232, r11.u32);
	// addi r28,r31,8220
	r28.s64 = r31.s64 + 8220;
	// stw r29,8228(r31)
	PPC_STORE_U32(r31.u32 + 8228, r29.u32);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r10,r11,10
	ctx.r10.s64 = r11.s64 + 10;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r10,351
	cr6.compare<uint32_t>(ctx.r10.u32, 351, xer);
	// blt cr6,0x826703f0
	if (cr6.lt) goto loc_826703F0;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
loc_826703F0:
	// stw r10,10596(r31)
	PPC_STORE_U32(r31.u32 + 10596, ctx.r10.u32);
	// addi r11,r31,10592
	r11.s64 = r31.s64 + 10592;
	// addi r10,r31,8840
	ctx.r10.s64 = r31.s64 + 8840;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// addi r25,r31,8816
	r25.s64 = r31.s64 + 8816;
	// stw r10,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, ctx.r10.u32);
	// stw r29,8824(r31)
	PPC_STORE_U32(r31.u32 + 8824, r29.u32);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r9,r10,10
	ctx.r9.s64 = ctx.r10.s64 + 10;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r10,351
	cr6.compare<uint32_t>(ctx.r10.u32, 351, xer);
	// blt cr6,0x8267042c
	if (cr6.lt) goto loc_8267042C;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
loc_8267042C:
	// addi r9,r31,9432
	ctx.r9.s64 = r31.s64 + 9432;
	// stw r10,10596(r31)
	PPC_STORE_U32(r31.u32 + 10596, ctx.r10.u32);
	// stw r11,20(r25)
	PPC_STORE_U32(r25.u32 + 20, r11.u32);
	// addi r23,r31,9408
	r23.s64 = r31.s64 + 9408;
	// stw r9,9420(r31)
	PPC_STORE_U32(r31.u32 + 9420, ctx.r9.u32);
	// stw r29,9416(r31)
	PPC_STORE_U32(r31.u32 + 9416, r29.u32);
	// lwz r9,4544(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r8,r10,10
	ctx.r8.s64 = ctx.r10.s64 + 10;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,351
	cr6.compare<uint32_t>(ctx.r10.u32, 351, xer);
	// blt cr6,0x82670464
	if (cr6.lt) goto loc_82670464;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
loc_82670464:
	// stw r10,10596(r31)
	PPC_STORE_U32(r31.u32 + 10596, ctx.r10.u32);
	// addi r9,r31,10024
	ctx.r9.s64 = r31.s64 + 10024;
	// stw r11,20(r23)
	PPC_STORE_U32(r23.u32 + 20, r11.u32);
	// addi r22,r31,10000
	r22.s64 = r31.s64 + 10000;
	// stw r29,10008(r31)
	PPC_STORE_U32(r31.u32 + 10008, r29.u32);
	// stw r9,10012(r31)
	PPC_STORE_U32(r31.u32 + 10012, ctx.r9.u32);
	// lwz r9,4544(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r8,r10,10
	ctx.r8.s64 = ctx.r10.s64 + 10;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,351
	cr6.compare<uint32_t>(ctx.r10.u32, 351, xer);
	// blt cr6,0x8267049c
	if (cr6.lt) goto loc_8267049C;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
loc_8267049C:
	// li r21,0
	r21.s64 = 0;
	// stw r10,10596(r31)
	PPC_STORE_U32(r31.u32 + 10596, ctx.r10.u32);
	// stw r11,20(r22)
	PPC_STORE_U32(r22.u32 + 20, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r21.u32);
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r21.u32);
	// bl 0x82388580
	ctx.lr = 0x826704B8;
	sub_82388580(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r24,r31,8216
	r24.s64 = r31.s64 + 8216;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r20,4(r10)
	r20.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,-10240(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826704E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82270170
	ctx.lr = 0x826704F4;
	sub_82270170(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// bl 0x82272e08
	ctx.lr = 0x82670504;
	sub_82272E08(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bne cr6,0x82670544
	if (!cr6.eq) goto loc_82670544;
loc_82670510:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670518;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670528;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x8267052C;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82670530;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82670538;
	sub_821C91B8(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82670510
	if (cr6.eq) goto loc_82670510;
loc_82670544:
	// addi r31,r31,4352
	r31.s64 = r31.s64 + 4352;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r10,3
	ctx.r10.s64 = 3;
	// cmplwi cr6,r11,20
	cr6.compare<uint32_t>(r11.u32, 20, xer);
	// divwu r26,r11,r10
	r26.u32 = r11.u32 / ctx.r10.u32;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bge cr6,0x826706c0
	if (!cr6.lt) goto loc_826706C0;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82670584
	if (cr6.eq) goto loc_82670584;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82670584
	if (!cr6.eq) goto loc_82670584;
	// stb r29,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r29.u8);
	// mr r30,r31
	r30.u64 = r31.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670588
	goto loc_82670588;
loc_82670584:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670588:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670590;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826705A0;
	sub_82270170(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x826705B0;
	sub_82272E00(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x826705dc
	if (cr6.eq) goto loc_826705DC;
	// lbz r10,65(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826705dc
	if (!cr6.eq) goto loc_826705DC;
	// stb r29,65(r31)
	PPC_STORE_U8(r31.u32 + 65, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x826705e0
	goto loc_826705E0;
loc_826705DC:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_826705E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826705E8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826705F8;
	sub_82270170(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x82670608;
	sub_82272E00(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82670634
	if (cr6.eq) goto loc_82670634;
	// lbz r10,66(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 66);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82670634
	if (!cr6.eq) goto loc_82670634;
	// stb r29,66(r31)
	PPC_STORE_U8(r31.u32 + 66, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670638
	goto loc_82670638;
loc_82670634:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670638:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670640;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670650;
	sub_82270170(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x82670660;
	sub_82272E00(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r31,24
	r11.s64 = r31.s64 + 24;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8267068c
	if (cr6.eq) goto loc_8267068C;
	// lbz r10,67(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 67);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8267068c
	if (!cr6.eq) goto loc_8267068C;
	// stb r29,67(r31)
	PPC_STORE_U8(r31.u32 + 67, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670690
	goto loc_82670690;
loc_8267068C:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670690:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670698;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826706A8;
	sub_82270170(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82272e00
	ctx.lr = 0x826706B8;
	sub_82272E00(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
loc_826706C0:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x826706e4
	if (cr6.eq) goto loc_826706E4;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826706e4
	if (!cr6.eq) goto loc_826706E4;
	// stb r29,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r29.u8);
	// mr r30,r31
	r30.u64 = r31.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x826706e8
	goto loc_826706E8;
loc_826706E4:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_826706E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826706F0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670700;
	sub_82270170(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x82670710;
	sub_82272E00(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8267073c
	if (cr6.eq) goto loc_8267073C;
	// lbz r10,65(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8267073c
	if (!cr6.eq) goto loc_8267073C;
	// stb r29,65(r31)
	PPC_STORE_U8(r31.u32 + 65, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670740
	goto loc_82670740;
loc_8267073C:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670740:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670748;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670758;
	sub_82270170(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x82670768;
	sub_82272E00(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82670794
	if (cr6.eq) goto loc_82670794;
	// lbz r10,66(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 66);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82670794
	if (!cr6.eq) goto loc_82670794;
	// stb r29,66(r31)
	PPC_STORE_U8(r31.u32 + 66, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670798
	goto loc_82670798;
loc_82670794:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670798:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826707A0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826707B0;
	sub_82270170(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// rlwinm r5,r26,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x826707C0;
	sub_82272E00(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r31,24
	r11.s64 = r31.s64 + 24;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x826707ec
	if (cr6.eq) goto loc_826707EC;
	// lbz r10,67(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 67);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826707ec
	if (!cr6.eq) goto loc_826707EC;
	// stb r29,67(r31)
	PPC_STORE_U8(r31.u32 + 67, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x826707f0
	goto loc_826707F0;
loc_826707EC:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_826707F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826707F8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8267080C;
	sub_82270170(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82272e00
	ctx.lr = 0x8267081C;
	sub_82272E00(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82670824"))) PPC_WEAK_FUNC(sub_82670824);
PPC_FUNC_IMPL(__imp__sub_82670824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82670828"))) PPC_WEAK_FUNC(sub_82670828);
PPC_FUNC_IMPL(__imp__sub_82670828) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82670830;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8267085C;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r31,r9,14672
	r31.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r24,56(r25)
	r24.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82670878;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x82670888;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r31,56(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// addi r23,r8,2612
	r23.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821c9790
	ctx.lr = 0x826708A4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x825ed480
	ctx.lr = 0x826708B4;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x826708CC;
	sub_821C9790(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r31,0
	r31.s64 = 0;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x826708F0;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,65(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 65);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82670920;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82670938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// addi r4,r4,1072
	ctx.r4.s64 = ctx.r4.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8267094C;
	sub_825EE0E0(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-13284
	ctx.r4.s64 = r11.s64 + -13284;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82722678
	ctx.lr = 0x82670968;
	sub_82722678(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14304
	ctx.r4.s64 = ctx.r10.s64 + -14304;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8267097C;
	sub_82218310(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r8,20268
	ctx.r4.s64 = ctx.r8.s64 + 20268;
	// bl 0x827227b8
	ctx.lr = 0x82670994;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267099C;
	sub_82388580(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r3,-10240(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826709B0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x826709B8;
	sub_824E7118(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r4,-11016
	ctx.r4.s64 = ctx.r4.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x826709CC;
	sub_827227B8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r11,-11024
	ctx.r4.s64 = r11.s64 + -11024;
	// bl 0x827227b8
	ctx.lr = 0x826709E0;
	sub_827227B8(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r10,-11032
	ctx.r4.s64 = ctx.r10.s64 + -11032;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827227b8
	ctx.lr = 0x826709F4;
	sub_827227B8(ctx, base);
	// stw r28,4528(r30)
	PPC_STORE_U32(r30.u32 + 4528, r28.u32);
	// stw r27,4544(r30)
	PPC_STORE_U32(r30.u32 + 4544, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,4548(r30)
	PPC_STORE_U32(r30.u32 + 4548, r26.u32);
	// bl 0x82670300
	ctx.lr = 0x82670A08;
	sub_82670300(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,377(r11)
	PPC_STORE_U8(r11.u32 + 377, r31.u8);
	// bl 0x82630318
	ctx.lr = 0x82670A50;
	sub_82630318(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82670A58"))) PPC_WEAK_FUNC(sub_82670A58);
PPC_FUNC_IMPL(__imp__sub_82670A58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82670A60;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29060
	ctx.r8.s64 = r11.s64 + 29060;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,6
	ctx.r9.s64 = 6;
	// li r7,7
	ctx.r7.s64 = 7;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ef58
	ctx.lr = 0x82670A90;
	sub_8266EF58(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r21,r10,14684
	r21.s64 = ctx.r10.s64 + 14684;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// addi r7,r8,22796
	ctx.r7.s64 = ctx.r8.s64 + 22796;
	// li r29,0
	r29.s64 = 0;
	// addi r22,r11,484
	r22.s64 = r11.s64 + 484;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r11,r31,4544
	r11.s64 = r31.s64 + 4544;
	// stw r29,4548(r31)
	PPC_STORE_U32(r31.u32 + 4548, r29.u32);
	// addi r30,r10,560
	r30.s64 = ctx.r10.s64 + 560;
	// stw r29,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r29.u32);
	// lis r11,8192
	r11.s64 = 536870912;
	// stw r29,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r29.u32);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// stw r22,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r22.u32);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stw r21,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, r21.u32);
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// li r24,9
	r24.s64 = 9;
	// li r23,4
	r23.s64 = 4;
	// ori r25,r11,44
	r25.u64 = r11.u64 | 44;
	// ori r26,r10,36
	r26.u64 = ctx.r10.u64 | 36;
	// ori r27,r9,39
	r27.u64 = ctx.r9.u64 | 39;
	// ori r28,r8,40
	r28.u64 = ctx.r8.u64 | 40;
loc_82670AF8:
	// addi r3,r30,-536
	ctx.r3.s64 = r30.s64 + -536;
	// bl 0x824f9438
	ctx.lr = 0x82670B00;
	sub_824F9438(ctx, base);
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r11,r30,-512
	r11.s64 = r30.s64 + -512;
	// stw r23,-512(r30)
	PPC_STORE_U32(r30.u32 + -512, r23.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// std r29,-508(r30)
	PPC_STORE_U64(r30.u32 + -508, r29.u64);
	// stw r25,-500(r30)
	PPC_STORE_U32(r30.u32 + -500, r25.u32);
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// stw r26,-488(r30)
	PPC_STORE_U32(r30.u32 + -488, r26.u32);
	// stw r27,-480(r30)
	PPC_STORE_U32(r30.u32 + -480, r27.u32);
	// stw r28,-472(r30)
	PPC_STORE_U32(r30.u32 + -472, r28.u32);
	// stb r9,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r9.u8);
	// stw r11,-520(r30)
	PPC_STORE_U32(r30.u32 + -520, r11.u32);
	// addi r30,r30,568
	r30.s64 = r30.s64 + 568;
	// bge 0x82670af8
	if (!cr0.lt) goto loc_82670AF8;
	// stw r29,10252(r31)
	PPC_STORE_U32(r31.u32 + 10252, r29.u32);
	// addi r30,r31,10272
	r30.s64 = r31.s64 + 10272;
	// stw r29,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r29.u32);
	// addi r11,r31,10248
	r11.s64 = r31.s64 + 10248;
	// stw r29,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, r29.u32);
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// stw r22,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, r22.u32);
	// stw r21,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, r21.u32);
	// bl 0x824f9438
	ctx.lr = 0x82670B5C;
	sub_824F9438(ctx, base);
	// lbz r6,10832(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 10832);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r23,10320(r31)
	PPC_STORE_U32(r31.u32 + 10320, r23.u32);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// std r29,10324(r31)
	PPC_STORE_U64(r31.u32 + 10324, r29.u64);
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// stw r25,10332(r31)
	PPC_STORE_U32(r31.u32 + 10332, r25.u32);
	// addi r9,r10,564
	ctx.r9.s64 = ctx.r10.s64 + 564;
	// stw r26,10344(r31)
	PPC_STORE_U32(r31.u32 + 10344, r26.u32);
	// stw r27,10352(r31)
	PPC_STORE_U32(r31.u32 + 10352, r27.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r28,10360(r31)
	PPC_STORE_U32(r31.u32 + 10360, r28.u32);
	// addi r10,r31,880
	ctx.r10.s64 = r31.s64 + 880;
	// stb r5,10832(r31)
	PPC_STORE_U8(r31.u32 + 10832, ctx.r5.u8);
	// addi r7,r8,29540
	ctx.r7.s64 = ctx.r8.s64 + 29540;
	// stw r11,10312(r31)
	PPC_STORE_U32(r31.u32 + 10312, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// lhz r4,884(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// sth r11,884(r31)
	PPC_STORE_U16(r31.u32 + 884, r11.u16);
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r11,29540(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 29540);
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r9,884(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,12(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,16(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,20(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82670C88"))) PPC_WEAK_FUNC(sub_82670C88);
PPC_FUNC_IMPL(__imp__sub_82670C88) {
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
	ctx.lr = 0x82670C90;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670CB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82670f8c
	if (cr6.eq) goto loc_82670F8C;
	// lfs f0,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,4520(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// bl 0x82388580
	ctx.lr = 0x82670CD0;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82670CE0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82670CE8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670d20
	if (cr6.eq) goto loc_82670D20;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670CFC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670D0C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82670D14;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82670d54
	if (!cr6.eq) goto loc_82670D54;
loc_82670D20:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,21160
	ctx.r4.s64 = ctx.r10.s64 + 21160;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x82670D3C;
	sub_82289AB0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82643bb8
	ctx.lr = 0x82670D54;
	sub_82643BB8(ctx, base);
loc_82670D54:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r28,r31,4352
	r28.s64 = r31.s64 + 4352;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x82670e68
	if (cr6.eq) goto loc_82670E68;
loc_82670D70:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82670e60
	if (cr6.eq) goto loc_82670E60;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82670d70
	if (cr6.lt) goto loc_82670D70;
	// li r11,1
	r11.s64 = 1;
loc_82670D90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670f70
	if (cr6.eq) goto loc_82670F70;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670f70
	if (cr6.eq) goto loc_82670F70;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82670e40
	if (!cr6.gt) goto loc_82670E40;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_82670DBC:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82670e40
	if (!cr6.lt) goto loc_82670E40;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x82670e20
	if (cr6.lt) goto loc_82670E20;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_82670E20:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b530
	ctx.lr = 0x82670E2C;
	sub_8266B530(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82670dbc
	if (cr6.lt) goto loc_82670DBC;
loc_82670E40:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82670E50:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82670e50
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82670E50;
	// b 0x82670f54
	goto loc_82670F54;
loc_82670E60:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82670d90
	goto loc_82670D90;
loc_82670E68:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82670f98
	if (cr6.eq) goto loc_82670F98;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82670e68
	if (cr6.lt) goto loc_82670E68;
	// li r11,1
	r11.s64 = 1;
loc_82670E88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670f70
	if (cr6.eq) goto loc_82670F70;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670f70
	if (cr6.eq) goto loc_82670F70;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82670f38
	if (!cr6.gt) goto loc_82670F38;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_82670EB4:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82670f38
	if (!cr6.lt) goto loc_82670F38;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x82670f18
	if (cr6.lt) goto loc_82670F18;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_82670F18:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b530
	ctx.lr = 0x82670F24;
	sub_8266B530(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82670eb4
	if (cr6.lt) goto loc_82670EB4;
loc_82670F38:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82670F48:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82670f48
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82670F48;
loc_82670F54:
	// stb r27,73(r28)
	PPC_STORE_U8(r28.u32 + 73, r27.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r27,72(r28)
	PPC_STORE_U8(r28.u32 + 72, r27.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670F70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82670F70:
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82670f88
	if (cr6.eq) goto loc_82670F88;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82670F88:
	// bl 0x8266d7b8
	ctx.lr = 0x82670F8C;
	sub_8266D7B8(ctx, base);
loc_82670F8C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82670F98:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82670e88
	goto loc_82670E88;
}

__attribute__((alias("__imp__sub_82670FA0"))) PPC_WEAK_FUNC(sub_82670FA0);
PPC_FUNC_IMPL(__imp__sub_82670FA0) {
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
	// bl 0x8266f830
	ctx.lr = 0x82670FB8;
	sub_8266F830(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,23604
	ctx.r10.s64 = r11.s64 + 23604;
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

__attribute__((alias("__imp__sub_82670FDC"))) PPC_WEAK_FUNC(sub_82670FDC);
PPC_FUNC_IMPL(__imp__sub_82670FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82670FE0"))) PPC_WEAK_FUNC(sub_82670FE0);
PPC_FUNC_IMPL(__imp__sub_82670FE0) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// li r7,2
	ctx.r7.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8265b008
	ctx.lr = 0x82671004;
	sub_8265B008(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// addi r10,r11,-1508
	ctx.r10.s64 = r11.s64 + -1508;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82659e28
	ctx.lr = 0x82671018;
	sub_82659E28(ctx, base);
	// addi r3,r31,952
	ctx.r3.s64 = r31.s64 + 952;
	// bl 0x826597b8
	ctx.lr = 0x82671020;
	sub_826597B8(ctx, base);
	// addi r3,r31,976
	ctx.r3.s64 = r31.s64 + 976;
	// bl 0x82659db8
	ctx.lr = 0x82671028;
	sub_82659DB8(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x82659e28
	ctx.lr = 0x82671030;
	sub_82659E28(ctx, base);
	// addi r3,r31,1016
	ctx.r3.s64 = r31.s64 + 1016;
	// bl 0x826597b8
	ctx.lr = 0x82671038;
	sub_826597B8(ctx, base);
	// addi r3,r31,1040
	ctx.r3.s64 = r31.s64 + 1040;
	// bl 0x82659db8
	ctx.lr = 0x82671040;
	sub_82659DB8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,-28964(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -28964);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r7,-4144
	ctx.r10.s64 = ctx.r7.s64 + -4144;
	// stfs f0,1220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1220, temp.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f0,1224(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1224, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f13,1228(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1228, temp.u32);
	// addi r7,r6,18928
	ctx.r7.s64 = ctx.r6.s64 + 18928;
	// stb r11,1216(r31)
	PPC_STORE_U8(r31.u32 + 1216, r11.u8);
	// stw r11,1364(r31)
	PPC_STORE_U32(r31.u32 + 1364, r11.u32);
	// lfs f0,21528(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 21528);
	f0.f64 = double(temp.f32);
	// stw r9,1368(r31)
	PPC_STORE_U32(r31.u32 + 1368, ctx.r9.u32);
	// lfs f13,-6176(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -6176);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,1372(r31)
	PPC_STORE_U32(r31.u32 + 1372, ctx.r8.u32);
	// addi r3,r31,1424
	ctx.r3.s64 = r31.s64 + 1424;
	// stw r10,1360(r31)
	PPC_STORE_U32(r31.u32 + 1360, ctx.r10.u32);
	// stw r11,1380(r31)
	PPC_STORE_U32(r31.u32 + 1380, r11.u32);
	// stw r7,1376(r31)
	PPC_STORE_U32(r31.u32 + 1376, ctx.r7.u32);
	// stfs f0,1408(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1408, temp.u32);
	// stfs f13,1412(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1412, temp.u32);
	// bl 0x82634b60
	ctx.lr = 0x826710B4;
	sub_82634B60(ctx, base);
	// addi r3,r31,3216
	ctx.r3.s64 = r31.s64 + 3216;
	// bl 0x82634b60
	ctx.lr = 0x826710BC;
	sub_82634B60(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lis r5,-32155
	ctx.r5.s64 = -2107310080;
	// addi r3,r6,-3372
	ctx.r3.s64 = ctx.r6.s64 + -3372;
	// addi r4,r5,22568
	ctx.r4.s64 = ctx.r5.s64 + 22568;
	// stw r3,3216(r31)
	PPC_STORE_U32(r31.u32 + 3216, ctx.r3.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x826710DC;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826710EC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826710ec
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826710EC;
	// addi r10,r31,888
	ctx.r10.s64 = r31.s64 + 888;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82671110:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82671110
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82671110;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8267113C"))) PPC_WEAK_FUNC(sub_8267113C);
PPC_FUNC_IMPL(__imp__sub_8267113C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82671140"))) PPC_WEAK_FUNC(sub_82671140);
PPC_FUNC_IMPL(__imp__sub_82671140) {
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
	// bl 0x8266dd48
	ctx.lr = 0x82671160;
	sub_8266DD48(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671178
	if (cr6.eq) goto loc_82671178;
	// bl 0x82130588
	ctx.lr = 0x82671174;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671178:
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

__attribute__((alias("__imp__sub_82671190"))) PPC_WEAK_FUNC(sub_82671190);
PPC_FUNC_IMPL(__imp__sub_82671190) {
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
	// bl 0x8266df30
	ctx.lr = 0x826711B0;
	sub_8266DF30(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826711c8
	if (cr6.eq) goto loc_826711C8;
	// bl 0x82130588
	ctx.lr = 0x826711C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826711C8:
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

__attribute__((alias("__imp__sub_826711E0"))) PPC_WEAK_FUNC(sub_826711E0);
PPC_FUNC_IMPL(__imp__sub_826711E0) {
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
	// bl 0x8266e348
	ctx.lr = 0x82671200;
	sub_8266E348(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671218
	if (cr6.eq) goto loc_82671218;
	// bl 0x82130588
	ctx.lr = 0x82671214;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671218:
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

__attribute__((alias("__imp__sub_82671230"))) PPC_WEAK_FUNC(sub_82671230);
PPC_FUNC_IMPL(__imp__sub_82671230) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r31,5024
	r30.s64 = r31.s64 + 5024;
	// addi r7,r11,29148
	ctx.r7.s64 = r11.s64 + 29148;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r10,16392
	ctx.r5.s64 = ctx.r10.s64 + 16392;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// li r8,2
	ctx.r8.s64 = 2;
	// bl 0x82670fe0
	ctx.lr = 0x82671270;
	sub_82670FE0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r7,r8,24412
	ctx.r7.s64 = ctx.r8.s64 + 24412;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x82671284;
	sub_82659E28(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,5052(r31)
	PPC_STORE_U32(r31.u32 + 5052, r11.u32);
	// sth r11,5056(r31)
	PPC_STORE_U16(r31.u32 + 5056, r11.u16);
	// sth r11,5058(r31)
	PPC_STORE_U16(r31.u32 + 5058, r11.u16);
	// stb r11,5060(r31)
	PPC_STORE_U8(r31.u32 + 5060, r11.u8);
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

__attribute__((alias("__imp__sub_826712B4"))) PPC_WEAK_FUNC(sub_826712B4);
PPC_FUNC_IMPL(__imp__sub_826712B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826712B8"))) PPC_WEAK_FUNC(sub_826712B8);
PPC_FUNC_IMPL(__imp__sub_826712B8) {
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
	ctx.lr = 0x826712C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lhz r11,5058(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5058);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826712e0
	if (cr6.eq) goto loc_826712E0;
	// lwz r3,5052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5052);
	// bl 0x82130588
	ctx.lr = 0x826712E0;
	sub_82130588(ctx, base);
loc_826712E0:
	// lhz r11,5034(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5034);
	// addi r30,r31,5024
	r30.s64 = r31.s64 + 5024;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826712f8
	if (cr6.eq) goto loc_826712F8;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x826712F8;
	sub_82130588(ctx, base);
loc_826712F8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82671300;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826440a8
	ctx.lr = 0x82671308;
	sub_826440A8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671320
	if (cr6.eq) goto loc_82671320;
	// bl 0x82130588
	ctx.lr = 0x8267131C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671320:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82671328"))) PPC_WEAK_FUNC(sub_82671328);
PPC_FUNC_IMPL(__imp__sub_82671328) {
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
	// bl 0x8266e970
	ctx.lr = 0x82671348;
	sub_8266E970(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671360
	if (cr6.eq) goto loc_82671360;
	// bl 0x82130588
	ctx.lr = 0x8267135C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671360:
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

__attribute__((alias("__imp__sub_82671378"))) PPC_WEAK_FUNC(sub_82671378);
PPC_FUNC_IMPL(__imp__sub_82671378) {
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
	// bl 0x8266ee60
	ctx.lr = 0x82671398;
	sub_8266EE60(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826713b0
	if (cr6.eq) goto loc_826713B0;
	// bl 0x82130588
	ctx.lr = 0x826713AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826713B0:
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

__attribute__((alias("__imp__sub_826713C8"))) PPC_WEAK_FUNC(sub_826713C8);
PPC_FUNC_IMPL(__imp__sub_826713C8) {
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
	// bl 0x8266f0d8
	ctx.lr = 0x826713E8;
	sub_8266F0D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671400
	if (cr6.eq) goto loc_82671400;
	// bl 0x82130588
	ctx.lr = 0x826713FC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671400:
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

__attribute__((alias("__imp__sub_82671418"))) PPC_WEAK_FUNC(sub_82671418);
PPC_FUNC_IMPL(__imp__sub_82671418) {
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
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r31,4568
	r11.s64 = r31.s64 + 4568;
	// addi r9,r31,10272
	ctx.r9.s64 = r31.s64 + 10272;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r4,10844(r31)
	PPC_STORE_U32(r31.u32 + 10844, ctx.r4.u32);
	// addi r8,r31,848
	ctx.r8.s64 = r31.s64 + 848;
	// stw r11,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r11.u32);
	// addi r11,r31,10840
	r11.s64 = r31.s64 + 10840;
	// stw r10,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, ctx.r10.u32);
	// stw r11,4564(r31)
	PPC_STORE_U32(r31.u32 + 4564, r11.u32);
	// stw r9,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, ctx.r9.u32);
	// stw r7,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, ctx.r7.u32);
	// stw r11,10268(r31)
	PPC_STORE_U32(r31.u32 + 10268, r11.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r6,852(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r11,r6,2
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82671494
	if (cr6.eq) goto loc_82671494;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82671480:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82671480
	if (!cr6.eq) goto loc_82671480;
loc_82671494:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
	// stw r9,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r9.u32);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826714C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,4516(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826714e0
	if (cr6.eq) goto loc_826714E0;
	// bl 0x8266f660
	ctx.lr = 0x826714DC;
	sub_8266F660(ctx, base);
	// b 0x826714e4
	goto loc_826714E4;
loc_826714E0:
	// bl 0x8266b168
	ctx.lr = 0x826714E4;
	sub_8266B168(ctx, base);
loc_826714E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b1f8
	ctx.lr = 0x826714EC;
	sub_8266B1F8(ctx, base);
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

__attribute__((alias("__imp__sub_82671500"))) PPC_WEAK_FUNC(sub_82671500);
PPC_FUNC_IMPL(__imp__sub_82671500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82671508;
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82671528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267153C;
	sub_82388580(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8267154C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82671554;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671568;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671578;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82671580;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82671e00
	if (!cr6.gt) goto loc_82671E00;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x826715B8;
	sub_8221D6A8(ctx, base);
	// addi r11,r30,-55
	r11.s64 = r30.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82671de8
	if (cr6.gt) goto loc_82671DE8;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,5596
	r12.s64 = r12.s64 + 5596;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826717B0;
	case 1:
		goto loc_82671DC8;
	case 2:
		goto loc_82671BA0;
	case 3:
		goto loc_82671C98;
	case 4:
		goto loc_82671DE8;
	case 5:
		goto loc_82671600;
	case 6:
		goto loc_826716D8;
	case 7:
		goto loc_826718A0;
	case 8:
		goto loc_82671984;
	default:
		__builtin_unreachable();
	}
	// lwz r19,6064(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6064);
	// lwz r19,7624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7624);
	// lwz r19,7072(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7072);
	// lwz r19,7320(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7320);
	// lwz r19,7656(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7656);
	// lwz r19,5632(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 5632);
	// lwz r19,5848(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 5848);
	// lwz r19,6304(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6304);
	// lwz r19,6532(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6532);
loc_82671600:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8267160C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826716c8
	if (cr6.eq) goto loc_826716C8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x8267160c
	if (cr6.lt) goto loc_8267160C;
	// li r11,1
	r11.s64 = 1;
loc_8267162C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82671640:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826716d0
	if (cr6.eq) goto loc_826716D0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671640
	if (cr6.lt) goto loc_82671640;
	// li r11,1
	r11.s64 = 1;
loc_82671660:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671678;
	sub_821E6800(ctx, base);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// ble cr6,0x82671694
	if (!cr6.gt) goto loc_82671694;
	// li r11,7
	r11.s64 = 7;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
loc_82671694:
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x8266aa70
	ctx.lr = 0x826716A4;
	sub_8266AA70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x826716B0;
	sub_82671418(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826716C8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8267162c
	goto loc_8267162C;
loc_826716D0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671660
	goto loc_82671660;
loc_826716D8:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_826716E4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826717a0
	if (cr6.eq) goto loc_826717A0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826716e4
	if (cr6.lt) goto loc_826716E4;
	// li r11,1
	r11.s64 = 1;
loc_82671704:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82671718:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826717a8
	if (cr6.eq) goto loc_826717A8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671718
	if (cr6.lt) goto loc_82671718;
	// li r11,1
	r11.s64 = 1;
loc_82671738:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671750;
	sub_821E6800(ctx, base);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bge cr6,0x8267176c
	if (!cr6.lt) goto loc_8267176C;
	// li r11,12
	r11.s64 = 12;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
loc_8267176C:
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x8266aa70
	ctx.lr = 0x8267177C;
	sub_8266AA70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x82671788;
	sub_82671418(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826717A0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671704
	goto loc_82671704;
loc_826717A8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671738
	goto loc_82671738;
loc_826717B0:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_826717BC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671890
	if (cr6.eq) goto loc_82671890;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826717bc
	if (cr6.lt) goto loc_826717BC;
	// li r11,1
	r11.s64 = 1;
loc_826717DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826717F0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671898
	if (cr6.eq) goto loc_82671898;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826717f0
	if (cr6.lt) goto loc_826717F0;
	// li r11,1
	r11.s64 = 1;
loc_82671810:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x82671824;
	sub_82203240(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82671884
	if (!cr6.lt) goto loc_82671884;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x82671884
	if (cr6.eq) goto loc_82671884;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82671850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x8267185C;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x82671884
	if (cr6.eq) goto loc_82671884;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267186C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8267187C;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x82671884;
	sub_822734B0(ctx, base);
loc_82671884:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671890:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826717dc
	goto loc_826717DC;
loc_82671898:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671810
	goto loc_82671810;
loc_826718A0:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_826718AC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8267193c
	if (cr6.eq) goto loc_8267193C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826718ac
	if (cr6.lt) goto loc_826718AC;
	// li r11,1
	r11.s64 = 1;
loc_826718CC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826718E0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671944
	if (cr6.eq) goto loc_82671944;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826718e0
	if (cr6.lt) goto loc_826718E0;
	// li r11,1
	r11.s64 = 1;
loc_82671900:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r27,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r27.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267194c
	if (cr6.eq) goto loc_8267194C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x82671930;
	sub_8262FFE0(ctx, base);
	// stb r27,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r27.u8);
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// b 0x82671960
	goto loc_82671960;
loc_8267193C:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826718cc
	goto loc_826718CC;
loc_82671944:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671900
	goto loc_82671900;
loc_8267194C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28596
	ctx.r4.s64 = r11.s64 + 28596;
	// bl 0x8262ffe0
	ctx.lr = 0x82671958;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, ctx.r10.u8);
loc_82671960:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267196C;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x82671978;
	sub_82671418(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671984:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82671990:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671a18
	if (cr6.eq) goto loc_82671A18;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82671990
	if (cr6.lt) goto loc_82671990;
	// li r11,1
	r11.s64 = 1;
loc_826719B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// addi r29,r31,4352
	r29.s64 = r31.s64 + 4352;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826719C8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671a20
	if (cr6.eq) goto loc_82671A20;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826719c8
	if (cr6.lt) goto loc_826719C8;
	// li r11,1
	r11.s64 = 1;
loc_826719E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82671a28
	if (!cr6.eq) goto loc_82671A28;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82671A0C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671A18:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826719b0
	goto loc_826719B0;
loc_82671A20:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826719e8
	goto loc_826719E8;
loc_82671A28:
	// lbz r11,4517(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4517);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r27,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r27.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671b58
	if (cr6.eq) goto loc_82671B58;
	// stb r27,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r27.u8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29420
	ctx.r4.s64 = r11.s64 + 29420;
	// bl 0x8262ffe0
	ctx.lr = 0x82671A50;
	sub_8262FFE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671A58;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671A68;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82671A70;
	sub_824E7110(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671A7C;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,-10240(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// addi r30,r31,4544
	r30.s64 = r31.s64 + 4544;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x8266a7b0
	ctx.lr = 0x82671A94;
	sub_8266A7B0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x82671AA0;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82272df8
	ctx.lr = 0x82671AB4;
	sub_82272DF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82671b7c
	if (cr6.eq) goto loc_82671B7C;
loc_82671AC0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82671AC8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671b2c
	if (cr6.eq) goto loc_82671B2C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671ac8
	if (cr6.lt) goto loc_82671AC8;
	// li r11,1
	r11.s64 = 1;
loc_82671AE8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82671b34
	if (!cr6.eq) goto loc_82671B34;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671b34
	if (cr6.eq) goto loc_82671B34;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671B08;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671B18;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x82671B1C;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82671B20;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82671B28;
	sub_821C91B8(ctx, base);
	// b 0x82671ac0
	goto loc_82671AC0;
loc_82671B2C:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671ae8
	goto loc_82671AE8;
loc_82671B34:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82671B4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// b 0x82671b7c
	goto loc_82671B7C;
loc_82671B58:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x82671B64;
	sub_8262FFE0(ctx, base);
	// lwz r9,4508(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// beq cr6,0x82671b7c
	if (cr6.eq) goto loc_82671B7C;
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
loc_82671B7C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671B88;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x82671B94;
	sub_82671418(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671BA0:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82671BAC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671c88
	if (cr6.eq) goto loc_82671C88;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82671bac
	if (cr6.lt) goto loc_82671BAC;
	// li r11,1
	r11.s64 = 1;
loc_82671BCC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82671BE0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671c90
	if (cr6.eq) goto loc_82671C90;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671be0
	if (cr6.lt) goto loc_82671BE0;
	// li r11,1
	r11.s64 = 1;
loc_82671C00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82671c7c
	if (!cr6.gt) goto loc_82671C7C;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r11.u32);
	// bge 0x82671c28
	if (!cr0.lt) goto loc_82671C28;
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
loc_82671C28:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671c48
	if (cr6.eq) goto loc_82671C48;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r11.u32);
	// bge 0x82671c48
	if (!cr0.lt) goto loc_82671C48;
	// stw r27,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r27.u32);
loc_82671C48:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671C54;
	sub_821E6800(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,29060
	ctx.r4.s64 = ctx.r10.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82671C68;
	sub_8262FFE0(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// stb r9,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r9.u8);
	// bl 0x82671418
	ctx.lr = 0x82671C7C;
	sub_82671418(ctx, base);
loc_82671C7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671C88:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671bcc
	goto loc_82671BCC;
loc_82671C90:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671c00
	goto loc_82671C00;
loc_82671C98:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82671CA4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671db8
	if (cr6.eq) goto loc_82671DB8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82671ca4
	if (cr6.lt) goto loc_82671CA4;
	// li r11,1
	r11.s64 = 1;
loc_82671CC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82671CD8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671dc0
	if (cr6.eq) goto loc_82671DC0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671cd8
	if (cr6.lt) goto loc_82671CD8;
	// li r11,1
	r11.s64 = 1;
loc_82671CF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x82671c7c
	if (cr6.lt) goto loc_82671C7C;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// beq cr6,0x82671d78
	if (cr6.eq) goto loc_82671D78;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,10
	r30.s64 = r11.s64 + 10;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// bl 0x82388580
	ctx.lr = 0x82671D3C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671D4C;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x82671d78
	if (!cr6.gt) goto loc_82671D78;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671D60;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671D70;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// stw r10,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, ctx.r10.u32);
loc_82671D78:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671D84;
	sub_821E6800(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,29060
	ctx.r4.s64 = ctx.r10.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82671D98;
	sub_8262FFE0(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// stb r9,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r9.u8);
	// bl 0x82671418
	ctx.lr = 0x82671DAC;
	sub_82671418(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671DB8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671cc4
	goto loc_82671CC4;
loc_82671DC0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671cf8
	goto loc_82671CF8;
loc_82671DC8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82671DDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r9,-17880
	ctx.r3.s64 = ctx.r9.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x82671DE8;
	sub_821E6800(ctx, base);
loc_82671DE8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x82671DF8;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671E00:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82671E0C"))) PPC_WEAK_FUNC(sub_82671E0C);
PPC_FUNC_IMPL(__imp__sub_82671E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82671E10"))) PPC_WEAK_FUNC(sub_82671E10);
PPC_FUNC_IMPL(__imp__sub_82671E10) {
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
	// lhz r11,10854(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10854);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e40
	if (cr6.eq) goto loc_82671E40;
	// lwz r3,10848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10848);
	// bl 0x82130588
	ctx.lr = 0x82671E40;
	sub_82130588(ctx, base);
loc_82671E40:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, ctx.r9.u32);
	// stw r8,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, ctx.r8.u32);
	// stw r9,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, ctx.r9.u32);
	// stw r8,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, ctx.r8.u32);
	// bl 0x8266f0d8
	ctx.lr = 0x82671E6C;
	sub_8266F0D8(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82671e84
	if (cr6.eq) goto loc_82671E84;
	// bl 0x82130588
	ctx.lr = 0x82671E80;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671E84:
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

__attribute__((alias("__imp__sub_82671E9C"))) PPC_WEAK_FUNC(sub_82671E9C);
PPC_FUNC_IMPL(__imp__sub_82671E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82671EA0"))) PPC_WEAK_FUNC(sub_82671EA0);
PPC_FUNC_IMPL(__imp__sub_82671EA0) {
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
	ctx.lr = 0x82671EA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,351
	cr6.compare<uint32_t>(ctx.r4.u32, 351, xer);
	// blt cr6,0x82671ebc
	if (cr6.lt) goto loc_82671EBC;
	// addi r4,r4,31
	ctx.r4.s64 = ctx.r4.s64 + 31;
loc_82671EBC:
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// stw r4,10844(r31)
	PPC_STORE_U32(r31.u32 + 10844, ctx.r4.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r11,r31,10840
	r11.s64 = r31.s64 + 10840;
	// stw r10,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, ctx.r10.u32);
	// addi r9,r31,10272
	ctx.r9.s64 = r31.s64 + 10272;
	// stw r5,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, ctx.r5.u32);
	// li r28,1
	r28.s64 = 1;
	// stw r11,4564(r31)
	PPC_STORE_U32(r31.u32 + 4564, r11.u32);
	// li r29,0
	r29.s64 = 0;
	// stw r9,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, ctx.r9.u32);
	// stw r28,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r28.u32);
	// addi r30,r31,4544
	r30.s64 = r31.s64 + 4544;
	// stw r11,10268(r31)
	PPC_STORE_U32(r31.u32 + 10268, r11.u32);
	// addi r8,r31,848
	ctx.r8.s64 = r31.s64 + 848;
	// stb r29,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r29.u8);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r7,852(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r11,r7,2
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82671f30
	if (cr6.eq) goto loc_82671F30;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82671F1C:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82671f1c
	if (!cr6.eq) goto loc_82671F1C;
loc_82671F30:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r31,1180
	ctx.r9.s64 = r31.s64 + 1180;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
loc_82671F48:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82671f80
	if (cr6.eq) goto loc_82671F80;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_82671F6C:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82671f6c
	if (!cr6.eq) goto loc_82671F6C;
loc_82671F80:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,336
	ctx.r9.s64 = ctx.r9.s64 + 336;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// bne 0x82671f48
	if (!cr0.eq) goto loc_82671F48;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82671FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,4516(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// stw r29,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, r29.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82671fe0
	if (cr6.eq) goto loc_82671FE0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266fd18
	ctx.lr = 0x82671FD0;
	sub_8266FD18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b1f8
	ctx.lr = 0x82671FD8;
	sub_8266B1F8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82671FE0:
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x82671ff0
	if (cr6.gt) goto loc_82671FF0;
	// stw r28,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r28.u32);
loc_82671FF0:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r29,4508(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// bl 0x82388580
	ctx.lr = 0x82671FFC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r31,4352
	ctx.r3.s64 = r31.s64 + 4352;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,-10240(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x8266a7b0
	ctx.lr = 0x82672014;
	sub_8266A7B0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x82672020;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x82272e00
	ctx.lr = 0x82672030;
	sub_82272E00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b1f8
	ctx.lr = 0x82672038;
	sub_8266B1F8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82672040"))) PPC_WEAK_FUNC(sub_82672040);
PPC_FUNC_IMPL(__imp__sub_82672040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82672048;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82672064;
	sub_8238EC00(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267207C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// li r26,0
	r26.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r26,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r26.u8);
	// bl 0x82388580
	ctx.lr = 0x82672098;
	sub_82388580(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826720A8;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x826720B0;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826720C4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826720D4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x826720DC;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826721e4
	if (!cr6.gt) goto loc_826721E4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x82672114;
	sub_8221D6A8(ctx, base);
	// addi r11,r30,-55
	r11.s64 = r30.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x8267296c
	if (cr6.gt) goto loc_8267296C;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,8504
	r12.s64 = r12.s64 + 8504;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826723B4;
	case 1:
		goto loc_82672428;
	case 2:
		goto loc_8267274C;
	case 3:
		goto loc_82672840;
	case 4:
		goto loc_8267296C;
	case 5:
		goto loc_8267215C;
	case 6:
		goto loc_82672298;
	case 7:
		goto loc_82672454;
	case 8:
		goto loc_82672534;
	default:
		__builtin_unreachable();
	}
	// lwz r19,9140(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9140);
	// lwz r19,9256(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9256);
	// lwz r19,10060(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 10060);
	// lwz r19,10304(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 10304);
	// lwz r19,10604(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 10604);
	// lwz r19,8540(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8540);
	// lwz r19,8856(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8856);
	// lwz r19,9300(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9300);
	// lwz r19,9524(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9524);
loc_8267215C:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_82672164:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826721f0
	if (cr6.eq) goto loc_826721F0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672164
	if (cr6.lt) goto loc_82672164;
	// li r11,1
	r11.s64 = 1;
loc_82672184:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672198:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826721f8
	if (cr6.eq) goto loc_826721F8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672198
	if (cr6.lt) goto loc_82672198;
	// li r11,1
	r11.s64 = 1;
loc_826721B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,10860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10860);
	// lhz r10,10852(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10852);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82672200
	if (cr6.lt) goto loc_82672200;
loc_826721D8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x826721E4;
	sub_821E6800(ctx, base);
loc_826721E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826721F0:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672184
	goto loc_82672184;
loc_826721F8:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826721b8
	goto loc_826721B8;
loc_82672200:
	// lwz r9,10848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10848);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,10860(r31)
	PPC_STORE_U32(r31.u32 + 10860, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10856(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r6,r11,10
	ctx.r6.s64 = r11.s64 + 10;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
	// lwz r5,788(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwz r4,36(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// addi r11,r11,-40
	r11.s64 = r11.s64 + -40;
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// addze r30,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r30.s64 = temp.s64;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r4,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82672258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10220(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x82672274;
	sub_8262A058(ctx, base);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lwz r3,24588(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672280;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x8267228C;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672298:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_826722A0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826723a4
	if (cr6.eq) goto loc_826723A4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826722a0
	if (cr6.lt) goto loc_826722A0;
	// li r11,1
	r11.s64 = 1;
loc_826722C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826722D4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826723ac
	if (cr6.eq) goto loc_826723AC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826722d4
	if (cr6.lt) goto loc_826722D4;
	// li r11,1
	r11.s64 = 1;
loc_826722F4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,10860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10860);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x826721d8
	if (cr0.lt) goto loc_826721D8;
	// lwz r9,10848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10848);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,10860(r31)
	PPC_STORE_U32(r31.u32 + 10860, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10856(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r6,r11,10
	ctx.r6.s64 = r11.s64 + 10;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
	// lwz r5,788(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwz r9,36(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// addi r4,r11,-40
	ctx.r4.s64 = r11.s64 + -40;
	// srawi r11,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	r11.s64 = ctx.r4.s32 >> 2;
	// addze r30,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r30.s64 = temp.s64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82672364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10220(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x82672380;
	sub_8262A058(ctx, base);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lwz r3,24588(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267238C;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672398;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826723A4:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826722c0
	goto loc_826722C0;
loc_826723AC:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826722f4
	goto loc_826722F4;
loc_826723B4:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x826723BC;
	sub_82203240(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8267241c
	if (!cr6.lt) goto loc_8267241C;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8267241c
	if (cr6.eq) goto loc_8267241C;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826723E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x826723F4;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x8267241c
	if (cr6.eq) goto loc_8267241C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672404;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672414;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x8267241C;
	sub_822734B0(ctx, base);
loc_8267241C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672428:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267243C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r9,-17880
	ctx.r3.s64 = ctx.r9.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x82672448;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672454:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_8267245C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826724ec
	if (cr6.eq) goto loc_826724EC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x8267245c
	if (cr6.lt) goto loc_8267245C;
	// li r11,1
	r11.s64 = 1;
loc_8267247C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672490:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826724f4
	if (cr6.eq) goto loc_826724F4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672490
	if (cr6.lt) goto loc_82672490;
	// li r11,1
	r11.s64 = 1;
loc_826724B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r26,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r26.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826724fc
	if (cr6.eq) goto loc_826724FC;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x826724E0;
	sub_8262FFE0(ctx, base);
	// stb r26,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r26.u8);
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
	// b 0x82672510
	goto loc_82672510;
loc_826724EC:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x8267247c
	goto loc_8267247C;
loc_826724F4:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826724b0
	goto loc_826724B0;
loc_826724FC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28596
	ctx.r4.s64 = r11.s64 + 28596;
	// bl 0x8262ffe0
	ctx.lr = 0x82672508;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, ctx.r10.u8);
loc_82672510:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267251C;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672528;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672534:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_8267253C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826725c4
	if (cr6.eq) goto loc_826725C4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x8267253c
	if (cr6.lt) goto loc_8267253C;
	// li r11,1
	r11.s64 = 1;
loc_8267255C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// addi r29,r31,4352
	r29.s64 = r31.s64 + 4352;
	// mr r11,r26
	r11.u64 = r26.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82672574:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826725cc
	if (cr6.eq) goto loc_826725CC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672574
	if (cr6.lt) goto loc_82672574;
	// li r11,1
	r11.s64 = 1;
loc_82672594:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826725d4
	if (!cr6.eq) goto loc_826725D4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x826725B8;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826725C4:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x8267255c
	goto loc_8267255C;
loc_826725CC:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672594
	goto loc_82672594;
loc_826725D4:
	// lbz r11,4517(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4517);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r26,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r26.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82672704
	if (cr6.eq) goto loc_82672704;
	// stb r26,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r26.u8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29420
	ctx.r4.s64 = r11.s64 + 29420;
	// bl 0x8262ffe0
	ctx.lr = 0x826725FC;
	sub_8262FFE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672604;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672614;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8267261C;
	sub_824E7110(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672628;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,-10240(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r30,r31,4544
	r30.s64 = r31.s64 + 4544;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x8266a7b0
	ctx.lr = 0x82672640;
	sub_8266A7B0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x8267264C;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82272df8
	ctx.lr = 0x82672660;
	sub_82272DF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82672728
	if (cr6.eq) goto loc_82672728;
loc_8267266C:
	// mr r11,r26
	r11.u64 = r26.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82672674:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826726d8
	if (cr6.eq) goto loc_826726D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672674
	if (cr6.lt) goto loc_82672674;
	// li r11,1
	r11.s64 = 1;
loc_82672694:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826726e0
	if (!cr6.eq) goto loc_826726E0;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826726e0
	if (cr6.eq) goto loc_826726E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826726B4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826726C4;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x826726C8;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x826726CC;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x826726D4;
	sub_821C91B8(ctx, base);
	// b 0x8267266c
	goto loc_8267266C;
loc_826726D8:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672694
	goto loc_82672694;
loc_826726E0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826726F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// b 0x82672728
	goto loc_82672728;
loc_82672704:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x82672710;
	sub_8262FFE0(ctx, base);
	// lwz r9,4508(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// beq cr6,0x82672728
	if (cr6.eq) goto loc_82672728;
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
loc_82672728:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672734;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672740;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8267274C:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_82672754:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672830
	if (cr6.eq) goto loc_82672830;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672754
	if (cr6.lt) goto loc_82672754;
	// li r11,1
	r11.s64 = 1;
loc_82672774:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672788:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672838
	if (cr6.eq) goto loc_82672838;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672788
	if (cr6.lt) goto loc_82672788;
	// li r11,1
	r11.s64 = 1;
loc_826727A8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82672824
	if (!cr6.gt) goto loc_82672824;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r11.u32);
	// bge 0x826727d0
	if (!cr0.lt) goto loc_826727D0;
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
loc_826727D0:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826727f0
	if (cr6.eq) goto loc_826727F0;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r11.u32);
	// bge 0x826727f0
	if (!cr0.lt) goto loc_826727F0;
	// stw r26,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r26.u32);
loc_826727F0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82672804;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672818;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672824;
	sub_82671EA0(ctx, base);
loc_82672824:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672830:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672774
	goto loc_82672774;
loc_82672838:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826727a8
	goto loc_826727A8;
loc_82672840:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_82672848:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8267295c
	if (cr6.eq) goto loc_8267295C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672848
	if (cr6.lt) goto loc_82672848;
	// li r11,1
	r11.s64 = 1;
loc_82672868:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_8267287C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672964
	if (cr6.eq) goto loc_82672964;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8267287c
	if (cr6.lt) goto loc_8267287C;
	// li r11,1
	r11.s64 = 1;
loc_8267289C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x82672824
	if (cr6.lt) goto loc_82672824;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// beq cr6,0x8267291c
	if (cr6.eq) goto loc_8267291C;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,10
	r30.s64 = r11.s64 + 10;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// bl 0x82388580
	ctx.lr = 0x826728E0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826728F0;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x8267291c
	if (!cr6.gt) goto loc_8267291C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672904;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672914;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// stw r10,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, ctx.r10.u32);
loc_8267291C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82672930;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672944;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672950;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8267295C:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672868
	goto loc_82672868;
loc_82672964:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x8267289c
	goto loc_8267289C;
loc_8267296C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8267297C;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82672984"))) PPC_WEAK_FUNC(sub_82672984);
PPC_FUNC_IMPL(__imp__sub_82672984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82672988"))) PPC_WEAK_FUNC(sub_82672988);
PPC_FUNC_IMPL(__imp__sub_82672988) {
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
	// bl 0x82670270
	ctx.lr = 0x826729A8;
	sub_82670270(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826729c0
	if (cr6.eq) goto loc_826729C0;
	// bl 0x82130588
	ctx.lr = 0x826729BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826729C0:
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

__attribute__((alias("__imp__sub_826729D8"))) PPC_WEAK_FUNC(sub_826729D8);
PPC_FUNC_IMPL(__imp__sub_826729D8) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, ctx.r9.u32);
	// stw r8,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, ctx.r8.u32);
	// stw r9,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, ctx.r9.u32);
	// stw r8,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, ctx.r8.u32);
	// bl 0x8266f0d8
	ctx.lr = 0x82672A1C;
	sub_8266F0D8(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82672a34
	if (cr6.eq) goto loc_82672A34;
	// bl 0x82130588
	ctx.lr = 0x82672A30;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82672A34:
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

__attribute__((alias("__imp__sub_82672A4C"))) PPC_WEAK_FUNC(sub_82672A4C);
PPC_FUNC_IMPL(__imp__sub_82672A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82672A50"))) PPC_WEAK_FUNC(sub_82672A50);
PPC_FUNC_IMPL(__imp__sub_82672A50) {
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
	// li r8,10
	ctx.r8.s64 = 10;
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// addi r11,r31,10840
	r11.s64 = r31.s64 + 10840;
	// addi r7,r31,10272
	ctx.r7.s64 = r31.s64 + 10272;
	// stw r4,10844(r31)
	PPC_STORE_U32(r31.u32 + 10844, ctx.r4.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r10,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, ctx.r10.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r8,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, ctx.r8.u32);
	// addi r9,r31,848
	ctx.r9.s64 = r31.s64 + 848;
	// stw r11,4564(r31)
	PPC_STORE_U32(r31.u32 + 4564, r11.u32);
	// stw r7,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, ctx.r7.u32);
	// stw r6,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, ctx.r6.u32);
	// stw r11,10268(r31)
	PPC_STORE_U32(r31.u32 + 10268, r11.u32);
	// stb r30,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r30.u8);
	// lwz r8,848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r5,852(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r11,r5,2
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82672ad8
	if (cr6.eq) goto loc_82672AD8;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_82672AC4:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82672ac4
	if (!cr6.eq) goto loc_82672AC4;
loc_82672AD8:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r7.u16);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r11,648(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 648);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82672B04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// stw r30,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82672b20
	if (cr6.eq) goto loc_82672B20;
	// bl 0x8266f660
	ctx.lr = 0x82672B1C;
	sub_8266F660(ctx, base);
	// b 0x82672b24
	goto loc_82672B24;
loc_82672B20:
	// bl 0x8266b168
	ctx.lr = 0x82672B24;
	sub_8266B168(ctx, base);
loc_82672B24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b1f8
	ctx.lr = 0x82672B2C;
	sub_8266B1F8(ctx, base);
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

__attribute__((alias("__imp__sub_82672B44"))) PPC_WEAK_FUNC(sub_82672B44);
PPC_FUNC_IMPL(__imp__sub_82672B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82672B48"))) PPC_WEAK_FUNC(sub_82672B48);
PPC_FUNC_IMPL(__imp__sub_82672B48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82672B50;
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82672B70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672B84;
	sub_82388580(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82672B94;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82672B9C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672BB0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672BC0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82672BC8;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826733d8
	if (!cr6.gt) goto loc_826733D8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x82672C00;
	sub_8221D6A8(ctx, base);
	// addi r11,r30,-55
	r11.s64 = r30.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x826733c0
	if (cr6.gt) goto loc_826733C0;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,11300
	r12.s64 = r12.s64 + 11300;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82672DF8;
	case 1:
		goto loc_82672E6C;
	case 2:
		goto loc_82673198;
	case 3:
		goto loc_82673290;
	case 4:
		goto loc_826733C0;
	case 5:
		goto loc_82672C48;
	case 6:
		goto loc_82672D20;
	case 7:
		goto loc_82672E98;
	case 8:
		goto loc_82672F7C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,11768(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11768);
	// lwz r19,11884(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11884);
	// lwz r19,12696(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12696);
	// lwz r19,12944(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12944);
	// lwz r19,13248(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13248);
	// lwz r19,11336(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11336);
	// lwz r19,11552(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11552);
	// lwz r19,11928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11928);
	// lwz r19,12156(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12156);
loc_82672C48:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82672C54:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672d10
	if (cr6.eq) goto loc_82672D10;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672c54
	if (cr6.lt) goto loc_82672C54;
	// li r11,1
	r11.s64 = 1;
loc_82672C74:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672C88:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672d18
	if (cr6.eq) goto loc_82672D18;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672c88
	if (cr6.lt) goto loc_82672C88;
	// li r11,1
	r11.s64 = 1;
loc_82672CA8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672CC0;
	sub_821E6800(ctx, base);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// ble cr6,0x82672cdc
	if (!cr6.gt) goto loc_82672CDC;
	// li r11,2
	r11.s64 = 2;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
loc_82672CDC:
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x8266ab58
	ctx.lr = 0x82672CEC;
	sub_8266AB58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82672CF8;
	sub_82672A50(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672D10:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672c74
	goto loc_82672C74;
loc_82672D18:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672ca8
	goto loc_82672CA8;
loc_82672D20:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82672D2C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672de8
	if (cr6.eq) goto loc_82672DE8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672d2c
	if (cr6.lt) goto loc_82672D2C;
	// li r11,1
	r11.s64 = 1;
loc_82672D4C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672D60:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672df0
	if (cr6.eq) goto loc_82672DF0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672d60
	if (cr6.lt) goto loc_82672D60;
	// li r11,1
	r11.s64 = 1;
loc_82672D80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672D98;
	sub_821E6800(ctx, base);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bge cr6,0x82672db4
	if (!cr6.lt) goto loc_82672DB4;
	// li r11,6
	r11.s64 = 6;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
loc_82672DB4:
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x8266ab58
	ctx.lr = 0x82672DC4;
	sub_8266AB58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82672DD0;
	sub_82672A50(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672DE8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672d4c
	goto loc_82672D4C;
loc_82672DF0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672d80
	goto loc_82672D80;
loc_82672DF8:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x82672E00;
	sub_82203240(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82672e60
	if (!cr6.lt) goto loc_82672E60;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x82672e60
	if (cr6.eq) goto loc_82672E60;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82672E2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x82672E38;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x82672e60
	if (cr6.eq) goto loc_82672E60;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672E48;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672E58;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x82672E60;
	sub_822734B0(ctx, base);
loc_82672E60:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672E6C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82672E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r9,-17880
	ctx.r3.s64 = ctx.r9.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x82672E8C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672E98:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82672EA4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672f34
	if (cr6.eq) goto loc_82672F34;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672ea4
	if (cr6.lt) goto loc_82672EA4;
	// li r11,1
	r11.s64 = 1;
loc_82672EC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672ED8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672f3c
	if (cr6.eq) goto loc_82672F3C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672ed8
	if (cr6.lt) goto loc_82672ED8;
	// li r11,1
	r11.s64 = 1;
loc_82672EF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r27,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r27.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82672f44
	if (cr6.eq) goto loc_82672F44;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x82672F28;
	sub_8262FFE0(ctx, base);
	// stb r27,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r27.u8);
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// b 0x82672f58
	goto loc_82672F58;
loc_82672F34:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672ec4
	goto loc_82672EC4;
loc_82672F3C:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672ef8
	goto loc_82672EF8;
loc_82672F44:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28596
	ctx.r4.s64 = r11.s64 + 28596;
	// bl 0x8262ffe0
	ctx.lr = 0x82672F50;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, ctx.r10.u8);
loc_82672F58:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672F64;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82672F70;
	sub_82672A50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672F7C:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82672F88:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673010
	if (cr6.eq) goto loc_82673010;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672f88
	if (cr6.lt) goto loc_82672F88;
	// li r11,1
	r11.s64 = 1;
loc_82672FA8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// addi r29,r31,4352
	r29.s64 = r31.s64 + 4352;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82672FC0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673018
	if (cr6.eq) goto loc_82673018;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672fc0
	if (cr6.lt) goto loc_82672FC0;
	// li r11,1
	r11.s64 = 1;
loc_82672FE0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82673020
	if (!cr6.eq) goto loc_82673020;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82673004;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673010:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672fa8
	goto loc_82672FA8;
loc_82673018:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672fe0
	goto loc_82672FE0;
loc_82673020:
	// lbz r11,4517(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4517);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r27,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r27.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673150
	if (cr6.eq) goto loc_82673150;
	// stb r27,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r27.u8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29420
	ctx.r4.s64 = r11.s64 + 29420;
	// bl 0x8262ffe0
	ctx.lr = 0x82673048;
	sub_8262FFE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673050;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673060;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82673068;
	sub_824E7110(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673074;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,-10240(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// addi r30,r31,4544
	r30.s64 = r31.s64 + 4544;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x8266a7b0
	ctx.lr = 0x8267308C;
	sub_8266A7B0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x82673098;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82272df8
	ctx.lr = 0x826730AC;
	sub_82272DF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82673174
	if (cr6.eq) goto loc_82673174;
loc_826730B8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826730C0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673124
	if (cr6.eq) goto loc_82673124;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826730c0
	if (cr6.lt) goto loc_826730C0;
	// li r11,1
	r11.s64 = 1;
loc_826730E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267312c
	if (!cr6.eq) goto loc_8267312C;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267312c
	if (cr6.eq) goto loc_8267312C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673100;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673110;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x82673114;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82673118;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82673120;
	sub_821C91B8(ctx, base);
	// b 0x826730b8
	goto loc_826730B8;
loc_82673124:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826730e0
	goto loc_826730E0;
loc_8267312C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// b 0x82673174
	goto loc_82673174;
loc_82673150:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x8267315C;
	sub_8262FFE0(ctx, base);
	// lwz r9,4508(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// beq cr6,0x82673174
	if (cr6.eq) goto loc_82673174;
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
loc_82673174:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673180;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x8267318C;
	sub_82672A50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673198:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_826731A4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673280
	if (cr6.eq) goto loc_82673280;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826731a4
	if (cr6.lt) goto loc_826731A4;
	// li r11,1
	r11.s64 = 1;
loc_826731C4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826731D8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673288
	if (cr6.eq) goto loc_82673288;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826731d8
	if (cr6.lt) goto loc_826731D8;
	// li r11,1
	r11.s64 = 1;
loc_826731F8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82673274
	if (!cr6.gt) goto loc_82673274;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r11.u32);
	// bge 0x82673220
	if (!cr0.lt) goto loc_82673220;
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
loc_82673220:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673240
	if (cr6.eq) goto loc_82673240;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r11.u32);
	// bge 0x82673240
	if (!cr0.lt) goto loc_82673240;
	// stw r27,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r27.u32);
loc_82673240:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82673254;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673268;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82673274;
	sub_82672A50(ctx, base);
loc_82673274:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673280:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826731c4
	goto loc_826731C4;
loc_82673288:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826731f8
	goto loc_826731F8;
loc_82673290:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8267329C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826733b0
	if (cr6.eq) goto loc_826733B0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x8267329c
	if (cr6.lt) goto loc_8267329C;
	// li r11,1
	r11.s64 = 1;
loc_826732BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826732D0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826733b8
	if (cr6.eq) goto loc_826733B8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826732d0
	if (cr6.lt) goto loc_826732D0;
	// li r11,1
	r11.s64 = 1;
loc_826732F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x82673274
	if (cr6.lt) goto loc_82673274;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// beq cr6,0x82673370
	if (cr6.eq) goto loc_82673370;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,10
	r30.s64 = r11.s64 + 10;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// bl 0x82388580
	ctx.lr = 0x82673334;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673344;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x82673370
	if (!cr6.gt) goto loc_82673370;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673358;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673368;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// stw r10,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, ctx.r10.u32);
loc_82673370:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82673384;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673398;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x826733A4;
	sub_82672A50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826733B0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826732bc
	goto loc_826732BC;
loc_826733B8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826732f0
	goto loc_826732F0;
loc_826733C0:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x826733D0;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826733D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826733E4"))) PPC_WEAK_FUNC(sub_826733E4);
PPC_FUNC_IMPL(__imp__sub_826733E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826733E8"))) PPC_WEAK_FUNC(sub_826733E8);
PPC_FUNC_IMPL(__imp__sub_826733E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x826733F0;
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82673428
	if (!cr6.eq) goto loc_82673428;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673428:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673430;
	sub_82388580(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82673440;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82673448;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267358c
	if (cr6.eq) goto loc_8267358C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267345C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8267346C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82673474;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8267358c
	if (cr6.eq) goto loc_8267358C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x82673498;
	sub_8221D6A8(ctx, base);
	// addi r11,r29,-55
	r11.s64 = r29.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x826738e4
	if (cr6.gt) goto loc_826738E4;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,13500
	r12.s64 = r12.s64 + 13500;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826734E0;
	case 1:
		goto loc_82673554;
	case 2:
		goto loc_826737A8;
	case 3:
		goto loc_82673828;
	case 4:
		goto loc_826738E4;
	case 5:
		goto loc_8267358C;
	case 6:
		goto loc_8267358C;
	case 7:
		goto loc_82673598;
	case 8:
		goto loc_82673604;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13536(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13536);
	// lwz r19,13652(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13652);
	// lwz r19,14248(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14248);
	// lwz r19,14376(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14376);
	// lwz r19,14564(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14564);
	// lwz r19,13708(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13708);
	// lwz r19,13708(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13708);
	// lwz r19,13720(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13720);
	// lwz r19,13828(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13828);
loc_826734E0:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x826734E8;
	sub_82203240(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8267358c
	if (!cr6.lt) goto loc_8267358C;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8267358c
	if (cr6.eq) goto loc_8267358C;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82673514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x82673520;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x8267358c
	if (cr6.eq) goto loc_8267358C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673530;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673540;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x82673548;
	sub_822734B0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673554:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,4
	ctx.r10.s64 = 262144;
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r8,r10,64594
	ctx.r8.u64 = ctx.r10.u64 | 64594;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stbx r9,r7,r8
	PPC_STORE_U8(ctx.r7.u32 + ctx.r8.u32, ctx.r9.u8);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,736(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 736);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82673580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r3,r4,-17880
	ctx.r3.s64 = ctx.r4.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x8267358C;
	sub_821E6800(ctx, base);
loc_8267358C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673598:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// li r29,0
	r29.s64 = 0;
	// li r5,5
	ctx.r5.s64 = 5;
	// stb r29,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r29.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// beq cr6,0x826735cc
	if (cr6.eq) goto loc_826735CC;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28180
	ctx.r4.s64 = r11.s64 + 28180;
	// bl 0x8262ffe0
	ctx.lr = 0x826735C0;
	sub_8262FFE0(ctx, base);
	// stb r29,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r29.u8);
	// stw r29,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r29.u32);
	// b 0x826735e0
	goto loc_826735E0;
loc_826735CC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28220
	ctx.r4.s64 = r11.s64 + 28220;
	// bl 0x8262ffe0
	ctx.lr = 0x826735D8;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, ctx.r10.u8);
loc_826735E0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826735EC;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x826735F8;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673604:
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82673628
	if (!cr6.eq) goto loc_82673628;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8267361C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673628:
	// lbz r11,4517(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4517);
	// li r29,0
	r29.s64 = 0;
	// li r5,5
	ctx.r5.s64 = 5;
	// stb r29,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r29.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// beq cr6,0x82673760
	if (cr6.eq) goto loc_82673760;
	// stb r29,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r29.u8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28444
	ctx.r4.s64 = r11.s64 + 28444;
	// bl 0x8262ffe0
	ctx.lr = 0x82673654;
	sub_8262FFE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267365C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8267366C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82673674;
	sub_824E7110(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673680;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r30,r31,4352
	r30.s64 = r31.s64 + 4352;
	// lwz r6,-10240(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r28,r31,4544
	r28.s64 = r31.s64 + 4544;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x8266a7b0
	ctx.lr = 0x8267369C;
	sub_8266A7B0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x826736A8;
	sub_82270170(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82272df8
	ctx.lr = 0x826736BC;
	sub_82272DF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82673784
	if (cr6.eq) goto loc_82673784;
loc_826736C8:
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_826736D0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673734
	if (cr6.eq) goto loc_82673734;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826736d0
	if (cr6.lt) goto loc_826736D0;
	// li r11,1
	r11.s64 = 1;
loc_826736F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267373c
	if (!cr6.eq) goto loc_8267373C;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267373c
	if (cr6.eq) goto loc_8267373C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673710;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673720;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x82673724;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82673728;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82673730;
	sub_821C91B8(ctx, base);
	// b 0x826736c8
	goto loc_826736C8;
loc_82673734:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x826736f0
	goto loc_826736F0;
loc_8267373C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673754;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// b 0x82673784
	goto loc_82673784;
loc_82673760:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28180
	ctx.r4.s64 = r11.s64 + 28180;
	// bl 0x8262ffe0
	ctx.lr = 0x8267376C;
	sub_8262FFE0(ctx, base);
	// lwz r9,4508(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// beq cr6,0x82673784
	if (cr6.eq) goto loc_82673784;
	// stw r29,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r29.u32);
loc_82673784:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673790;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x8267379C;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826737A8:
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8267358c
	if (!cr6.gt) goto loc_8267358C;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r29,0
	r29.s64 = 0;
	// stw r11,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r11.u32);
	// bge 0x826737c8
	if (!cr0.lt) goto loc_826737C8;
	// stw r29,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r29.u32);
loc_826737C8:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826737e8
	if (cr6.eq) goto loc_826737E8;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r11.u32);
	// bge 0x826737e8
	if (!cr0.lt) goto loc_826737E8;
	// stw r29,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r29.u32);
loc_826737E8:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,28180
	ctx.r4.s64 = r11.s64 + 28180;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x826737FC;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673810;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x8267381C;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673828:
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x8267358c
	if (cr6.lt) goto loc_8267358C;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// beq cr6,0x826738a4
	if (cr6.eq) goto loc_826738A4;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,10
	r30.s64 = r11.s64 + 10;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// bl 0x82388580
	ctx.lr = 0x82673860;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673870;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x826738a4
	if (!cr6.gt) goto loc_826738A4;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x82673888;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673898;
	sub_82270170(ctx, base);
	// lwz r11,308(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// stw r10,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, ctx.r10.u32);
loc_826738A4:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,28180
	ctx.r4.s64 = r11.s64 + 28180;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x826738B8;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826738CC;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x826738D8;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826738E4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x826738F4;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826738FC"))) PPC_WEAK_FUNC(sub_826738FC);
PPC_FUNC_IMPL(__imp__sub_826738FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673900"))) PPC_WEAK_FUNC(sub_82673900);
PPC_FUNC_IMPL(__imp__sub_82673900) {
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
	// bl 0x8266ca28
	ctx.lr = 0x82673918;
	sub_8266CA28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x82673924;
	sub_82671418(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266caf8
	ctx.lr = 0x82673930;
	sub_8266CAF8(ctx, base);
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

__attribute__((alias("__imp__sub_82673944"))) PPC_WEAK_FUNC(sub_82673944);
PPC_FUNC_IMPL(__imp__sub_82673944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673948"))) PPC_WEAK_FUNC(sub_82673948);
PPC_FUNC_IMPL(__imp__sub_82673948) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// bl 0x8266ca28
	ctx.lr = 0x82673960;
	sub_8266CA28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x8267396C;
	sub_82671EA0(ctx, base);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// lwz r9,10856(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r8,r10,-40
	ctx.r8.s64 = ctx.r10.s64 + -40;
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x8267399C;
	sub_8262A058(ctx, base);
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

__attribute__((alias("__imp__sub_826739B0"))) PPC_WEAK_FUNC(sub_826739B0);
PPC_FUNC_IMPL(__imp__sub_826739B0) {
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
	ctx.lr = 0x826739B8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826739D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82673c84
	if (cr6.eq) goto loc_82673C84;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826739E4;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826739F4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x826739FC;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673a34
	if (cr6.eq) goto loc_82673A34;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673A10;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673A20;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82673A28;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82673a64
	if (!cr6.eq) goto loc_82673A64;
loc_82673A34:
	// lbz r11,10600(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82673a64
	if (!cr6.eq) goto loc_82673A64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,21160
	ctx.r4.s64 = ctx.r10.s64 + 21160;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x82673A5C;
	sub_82289AB0(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r8,10600(r31)
	PPC_STORE_U8(r31.u32 + 10600, ctx.r8.u8);
loc_82673A64:
	// addi r30,r31,4352
	r30.s64 = r31.s64 + 4352;
	// li r29,0
	r29.s64 = 0;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82673A74:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673c8c
	if (cr6.eq) goto loc_82673C8C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82673a74
	if (cr6.lt) goto loc_82673A74;
	// li r11,1
	r11.s64 = 1;
loc_82673A94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673c84
	if (cr6.eq) goto loc_82673C84;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673c84
	if (cr6.eq) goto loc_82673C84;
	// lwz r11,8224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8224);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r9,8228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8228);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,8232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8232);
	// addi r28,r10,19036
	r28.s64 = ctx.r10.s64 + 19036;
	// lwz r6,8240(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8240);
	// addi r27,r8,-18644
	r27.s64 = ctx.r8.s64 + -18644;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// bl 0x8266d400
	ctx.lr = 0x82673AF4;
	sub_8266D400(ctx, base);
	// lwz r11,8820(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8820);
	// lwz r10,8824(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8824);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r9,8828(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8828);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r8,8836(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8836);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// bl 0x8266d400
	ctx.lr = 0x82673B2C;
	sub_8266D400(ctx, base);
	// lwz r7,9412(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 9412);
	// lwz r6,9416(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 9416);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,9420(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9420);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,9428(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 9428);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// bl 0x8266d400
	ctx.lr = 0x82673B64;
	sub_8266D400(ctx, base);
	// lwz r9,10004(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10004);
	// lwz r8,10008(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 10008);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r7,10012(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 10012);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,10020(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 10020);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// bl 0x8266d400
	ctx.lr = 0x82673B9C;
	sub_8266D400(ctx, base);
	// lhz r3,852(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// rotlwi r9,r3,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// addi r5,r31,6848
	ctx.r5.s64 = r31.s64 + 6848;
	// sth r11,852(r31)
	PPC_STORE_U16(r31.u32 + 852, r11.u16);
	// addi r4,r31,7184
	ctx.r4.s64 = r31.s64 + 7184;
	// addi r8,r31,7520
	ctx.r8.s64 = r31.s64 + 7520;
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r7.u32);
	// addi r7,r31,7856
	ctx.r7.s64 = r31.s64 + 7856;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r6,852(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// rotlwi r9,r6,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// stwx r4,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r5,852(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r10.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r8,852(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// rotlwi r11,r8,2
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r10,184(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	// stw r11,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, r11.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673C60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r30,64
	r11.s64 = r30.s64 + 64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82673C70:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82673c70
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82673C70;
	// stb r29,73(r30)
	PPC_STORE_U8(r30.u32 + 73, r29.u8);
	// stb r29,72(r30)
	PPC_STORE_U8(r30.u32 + 72, r29.u8);
loc_82673C84:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82673C8C:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x82673a94
	goto loc_82673A94;
}

__attribute__((alias("__imp__sub_82673C94"))) PPC_WEAK_FUNC(sub_82673C94);
PPC_FUNC_IMPL(__imp__sub_82673C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673C98"))) PPC_WEAK_FUNC(sub_82673C98);
PPC_FUNC_IMPL(__imp__sub_82673C98) {
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
	// bl 0x8266ca28
	ctx.lr = 0x82673CB0;
	sub_8266CA28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82673CBC;
	sub_82672A50(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266d7b8
	ctx.lr = 0x82673CC8;
	sub_8266D7B8(ctx, base);
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

__attribute__((alias("__imp__sub_82673CDC"))) PPC_WEAK_FUNC(sub_82673CDC);
PPC_FUNC_IMPL(__imp__sub_82673CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673CE0"))) PPC_WEAK_FUNC(sub_82673CE0);
PPC_FUNC_IMPL(__imp__sub_82673CE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// bl 0x8266ca28
	ctx.lr = 0x82673CFC;
	sub_8266CA28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82673D08;
	sub_82671EA0(ctx, base);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// lwz r9,10856(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r8,r10,-40
	ctx.r8.s64 = ctx.r10.s64 + -40;
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x82673D38;
	sub_8262A058(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r4,r6,28180
	ctx.r4.s64 = ctx.r6.s64 + 28180;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// bl 0x8262ffe0
	ctx.lr = 0x82673D50;
	sub_8262FFE0(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r4,r4,-10256
	ctx.r4.s64 = ctx.r4.s64 + -10256;
	// lwz r3,-10236(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82673D64;
	sub_821F9FB8(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,196(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// lwz r4,56(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82673D80;
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

__attribute__((alias("__imp__sub_82673D98"))) PPC_WEAK_FUNC(sub_82673D98);
PPC_FUNC_IMPL(__imp__sub_82673D98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f1,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// stfs f0,992(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 992, temp.u32);
	// stfs f1,996(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 996, temp.u32);
	// lwz r7,1740(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r6,r7,0,14,14
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,17
	ctx.r4.s64 = 17;
	// b 0x821ed368
	sub_821ED368(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82673DF0"))) PPC_WEAK_FUNC(sub_82673DF0);
PPC_FUNC_IMPL(__imp__sub_82673DF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82673DF4"))) PPC_WEAK_FUNC(sub_82673DF4);
PPC_FUNC_IMPL(__imp__sub_82673DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673DF8"))) PPC_WEAK_FUNC(sub_82673DF8);
PPC_FUNC_IMPL(__imp__sub_82673DF8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673E24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82673e40
	if (!cr6.eq) goto loc_82673E40;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207190
	ctx.lr = 0x82673E40;
	sub_82207190(ctx, base);
loc_82673E40:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x82673E4C;
	sub_82630318(ctx, base);
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

__attribute__((alias("__imp__sub_82673E64"))) PPC_WEAK_FUNC(sub_82673E64);
PPC_FUNC_IMPL(__imp__sub_82673E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673E68"))) PPC_WEAK_FUNC(sub_82673E68);
PPC_FUNC_IMPL(__imp__sub_82673E68) {
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
	// bl 0x82653670
	ctx.lr = 0x82673E78;
	sub_82653670(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82673E80;
	sub_82216138(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,14,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82673ea4
	if (cr6.eq) goto loc_82673EA4;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,17
	ctx.r4.s64 = 17;
	// bl 0x821ec468
	ctx.lr = 0x82673EA4;
	sub_821EC468(ctx, base);
loc_82673EA4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82673EB4"))) PPC_WEAK_FUNC(sub_82673EB4);
PPC_FUNC_IMPL(__imp__sub_82673EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673EB8"))) PPC_WEAK_FUNC(sub_82673EB8);
PPC_FUNC_IMPL(__imp__sub_82673EB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x82653920
	ctx.lr = 0x82673EDC;
	sub_82653920(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673EF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82673f60
	if (cr6.eq) goto loc_82673F60;
	// lfs f0,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 992);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82673f48
	if (!cr6.gt) goto loc_82673F48;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x82673f40
	if (!cr6.lt) goto loc_82673F40;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82673F38;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// b 0x82673f4c
	goto loc_82673F4C;
loc_82673F40:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x82673f4c
	goto loc_82673F4C;
loc_82673F48:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_82673F4C:
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// stfs f0,996(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x82673f60
	if (cr6.gt) goto loc_82673F60;
	// stfs f31,996(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
loc_82673F60:
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

__attribute__((alias("__imp__sub_82673F7C"))) PPC_WEAK_FUNC(sub_82673F7C);
PPC_FUNC_IMPL(__imp__sub_82673F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673F80"))) PPC_WEAK_FUNC(sub_82673F80);
PPC_FUNC_IMPL(__imp__sub_82673F80) {
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
	// bl 0x822166e8
	ctx.lr = 0x82673F98;
	sub_822166E8(ctx, base);
	// li r3,43
	ctx.r3.s64 = 43;
	// bl 0x82216138
	ctx.lr = 0x82673FA0;
	sub_82216138(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r9.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
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

__attribute__((alias("__imp__sub_82673FD4"))) PPC_WEAK_FUNC(sub_82673FD4);
PPC_FUNC_IMPL(__imp__sub_82673FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673FD8"))) PPC_WEAK_FUNC(sub_82673FD8);
PPC_FUNC_IMPL(__imp__sub_82673FD8) {
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
	ctx.lr = 0x82673FE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673FFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82674050
	if (!cr6.eq) goto loc_82674050;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207190
	ctx.lr = 0x82674018;
	sub_82207190(ctx, base);
	// bl 0x822166e8
	ctx.lr = 0x8267401C;
	sub_822166E8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,17268(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82674030;
	sub_821E80F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674050
	if (cr6.eq) goto loc_82674050;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x82674048;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a93a8
	ctx.lr = 0x82674050;
	sub_822A93A8(ctx, base);
loc_82674050:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630318
	ctx.lr = 0x8267405C;
	sub_82630318(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674064"))) PPC_WEAK_FUNC(sub_82674064);
PPC_FUNC_IMPL(__imp__sub_82674064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674068"))) PPC_WEAK_FUNC(sub_82674068);
PPC_FUNC_IMPL(__imp__sub_82674068) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f3,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x826533e8
	ctx.lr = 0x82674098;
	sub_826533E8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,17268(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x826740AC;
	sub_821E80F8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826740fc
	if (cr6.eq) goto loc_826740FC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x826740C4;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a93a8
	ctx.lr = 0x826740D0;
	sub_822A93A8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x826740E8;
	sub_822AFCD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x826740F0;
	sub_822A5578(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
loc_826740FC:
	// bl 0x82216648
	ctx.lr = 0x82674100;
	sub_82216648(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82674108;
	sub_82216138(ctx, base);
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

__attribute__((alias("__imp__sub_8267411C"))) PPC_WEAK_FUNC(sub_8267411C);
PPC_FUNC_IMPL(__imp__sub_8267411C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674120"))) PPC_WEAK_FUNC(sub_82674120);
PPC_FUNC_IMPL(__imp__sub_82674120) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x82653920
	ctx.lr = 0x82674144;
	sub_82653920(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826741d8
	if (cr6.eq) goto loc_826741D8;
	// lfs f0,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 992);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x826741b0
	if (!cr6.gt) goto loc_826741B0;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x826741a8
	if (!cr6.lt) goto loc_826741A8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x826741A0;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// b 0x826741b4
	goto loc_826741B4;
loc_826741A8:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x826741b4
	goto loc_826741B4;
loc_826741B0:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_826741B4:
	// fsubs f13,f30,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f30.f64 - f0.f64));
	// lfs f0,996(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 996);
	f0.f64 = double(temp.f32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x826741d8
	if (cr6.gt) goto loc_826741D8;
	// stfs f31,996(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x826741d8
	if (!cr6.gt) goto loc_826741D8;
	// bl 0x82215a60
	ctx.lr = 0x826741D8;
	sub_82215A60(ctx, base);
loc_826741D8:
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

__attribute__((alias("__imp__sub_826741F4"))) PPC_WEAK_FUNC(sub_826741F4);
PPC_FUNC_IMPL(__imp__sub_826741F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826741F8"))) PPC_WEAK_FUNC(sub_826741F8);
PPC_FUNC_IMPL(__imp__sub_826741F8) {
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
	// bl 0x826538a8
	ctx.lr = 0x82674218;
	sub_826538A8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,25756
	ctx.r5.s64 = r11.s64 + 25756;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,996
	ctx.r6.s64 = r31.s64 + 996;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82674238;
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

__attribute__((alias("__imp__sub_82674250"))) PPC_WEAK_FUNC(sub_82674250);
PPC_FUNC_IMPL(__imp__sub_82674250) {
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
	// bl 0x826538a8
	ctx.lr = 0x82674270;
	sub_826538A8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,25756
	ctx.r5.s64 = r11.s64 + 25756;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3668
	ctx.r6.s64 = r31.s64 + 3668;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82674290;
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

__attribute__((alias("__imp__sub_826742A8"))) PPC_WEAK_FUNC(sub_826742A8);
PPC_FUNC_IMPL(__imp__sub_826742A8) {
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
	// bl 0x826538a8
	ctx.lr = 0x826742C8;
	sub_826538A8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,25756
	ctx.r5.s64 = r11.s64 + 25756;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1068
	ctx.r6.s64 = r31.s64 + 1068;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826742E8;
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

__attribute__((alias("__imp__sub_82674300"))) PPC_WEAK_FUNC(sub_82674300);
PPC_FUNC_IMPL(__imp__sub_82674300) {
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
	ctx.lr = 0x82674308;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r10,-12592
	r29.s64 = ctx.r10.s64 + -12592;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,208(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267432C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82674338;
	sub_825EE0E0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r8,-19772
	r30.s64 = ctx.r8.s64 + -19772;
	// lwz r6,468(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 468);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82674354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82674360;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674368"))) PPC_WEAK_FUNC(sub_82674368);
PPC_FUNC_IMPL(__imp__sub_82674368) {
	PPC_FUNC_PROLOGUE();
	// b 0x82633f38
	sub_82633F38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267436C"))) PPC_WEAK_FUNC(sub_8267436C);
PPC_FUNC_IMPL(__imp__sub_8267436C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674370"))) PPC_WEAK_FUNC(sub_82674370);
PPC_FUNC_IMPL(__imp__sub_82674370) {
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
	// bl 0x82634010
	ctx.lr = 0x82674388;
	sub_82634010(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
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

__attribute__((alias("__imp__sub_826743A4"))) PPC_WEAK_FUNC(sub_826743A4);
PPC_FUNC_IMPL(__imp__sub_826743A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826743A8"))) PPC_WEAK_FUNC(sub_826743A8);
PPC_FUNC_IMPL(__imp__sub_826743A8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x826743e4
	if (!cr6.eq) goto loc_826743E4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826743D0;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826743E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826743E4:
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

__attribute__((alias("__imp__sub_826743FC"))) PPC_WEAK_FUNC(sub_826743FC);
PPC_FUNC_IMPL(__imp__sub_826743FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674400"))) PPC_WEAK_FUNC(sub_82674400);
PPC_FUNC_IMPL(__imp__sub_82674400) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x826744ac
	if (!cr6.eq) goto loc_826744AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267443C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,246(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 246);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674470
	if (cr6.eq) goto loc_82674470;
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82674468
	if (cr6.eq) goto loc_82674468;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,744(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 744);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674468:
	// li r11,0
	r11.s64 = 0;
	// stb r11,246(r31)
	PPC_STORE_U8(r31.u32 + 246, r11.u8);
loc_82674470:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,756(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 756);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674484;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674498;
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
loc_826744AC:
	// bl 0x82630580
	ctx.lr = 0x826744B0;
	sub_82630580(ctx, base);
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

__attribute__((alias("__imp__sub_826744C4"))) PPC_WEAK_FUNC(sub_826744C4);
PPC_FUNC_IMPL(__imp__sub_826744C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826744C8"))) PPC_WEAK_FUNC(sub_826744C8);
PPC_FUNC_IMPL(__imp__sub_826744C8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82674504
	if (cr6.eq) goto loc_82674504;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x826744f4
	if (cr6.eq) goto loc_826744F4;
	// bl 0x826537d0
	ctx.lr = 0x826744F0;
	sub_826537D0(ctx, base);
	// b 0x82674524
	goto loc_82674524;
loc_826744F4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x82674500;
	sub_821E6800(ctx, base);
	// b 0x82674524
	goto loc_82674524;
loc_82674504:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82674510;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674524:
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

__attribute__((alias("__imp__sub_8267453C"))) PPC_WEAK_FUNC(sub_8267453C);
PPC_FUNC_IMPL(__imp__sub_8267453C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674540"))) PPC_WEAK_FUNC(sub_82674540);
PPC_FUNC_IMPL(__imp__sub_82674540) {
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
	// bl 0x82653b30
	ctx.lr = 0x82674550;
	sub_82653B30(ctx, base);
	// bl 0x82216788
	ctx.lr = 0x82674554;
	sub_82216788(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x82674558;
	sub_82215A60(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674568"))) PPC_WEAK_FUNC(sub_82674568);
PPC_FUNC_IMPL(__imp__sub_82674568) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r30,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4;
	// stw r11,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,26,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,25,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,24,24
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,21,21
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,20,20
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,19,19
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,18,18
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82674610
	if (cr6.eq) goto loc_82674610;
loc_826745EC:
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r11,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r11.u32);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// lwz r9,1008(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r4,r10,25828
	ctx.r4.s64 = ctx.r10.s64 + 25828;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674610:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,30,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,22,22
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,17,17
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267467c
	if (cr6.eq) goto loc_8267467C;
loc_8267464C:
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,126
	ctx.r9.s64 = r11.s64 + 126;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r8,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, ctx.r8.u32);
	// addi r4,r10,25800
	ctx.r4.s64 = ctx.r10.s64 + 25800;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r7,r11,r31
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267467C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267467C:
	// rlwinm r11,r30,0,27,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826746b8
	if (cr6.eq) goto loc_826746B8;
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r8,r11,126
	ctx.r8.s64 = r11.s64 + 126;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, ctx.r9.u32);
	// addi r4,r10,25768
	ctx.r4.s64 = ctx.r10.s64 + 25768;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r7,r11,r31
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826746B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826746B8:
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

__attribute__((alias("__imp__sub_826746D0"))) PPC_WEAK_FUNC(sub_826746D0);
PPC_FUNC_IMPL(__imp__sub_826746D0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653f28
	sub_82653F28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746D4"))) PPC_WEAK_FUNC(sub_826746D4);
PPC_FUNC_IMPL(__imp__sub_826746D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746D8"))) PPC_WEAK_FUNC(sub_826746D8);
PPC_FUNC_IMPL(__imp__sub_826746D8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653b30
	sub_82653B30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746DC"))) PPC_WEAK_FUNC(sub_826746DC);
PPC_FUNC_IMPL(__imp__sub_826746DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746E0"))) PPC_WEAK_FUNC(sub_826746E0);
PPC_FUNC_IMPL(__imp__sub_826746E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653670
	sub_82653670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746E4"))) PPC_WEAK_FUNC(sub_826746E4);
PPC_FUNC_IMPL(__imp__sub_826746E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746E8"))) PPC_WEAK_FUNC(sub_826746E8);
PPC_FUNC_IMPL(__imp__sub_826746E8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82674718
	if (cr6.eq) goto loc_82674718;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// bne cr6,0x8267474c
	if (!cr6.eq) goto loc_8267474C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r9,r11,24348
	ctx.r9.s64 = r11.s64 + 24348;
	// b 0x82674720
	goto loc_82674720;
loc_82674718:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
loc_82674720:
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8267474c
	if (!cr6.eq) goto loc_8267474C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82674738;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267474C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267474C:
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

__attribute__((alias("__imp__sub_82674764"))) PPC_WEAK_FUNC(sub_82674764);
PPC_FUNC_IMPL(__imp__sub_82674764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674768"))) PPC_WEAK_FUNC(sub_82674768);
PPC_FUNC_IMPL(__imp__sub_82674768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28644
	ctx.r4.s64 = r11.s64 + 28644;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// b 0x8262ffe0
	sub_8262FFE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267477C"))) PPC_WEAK_FUNC(sub_8267477C);
PPC_FUNC_IMPL(__imp__sub_8267477C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674780"))) PPC_WEAK_FUNC(sub_82674780);
PPC_FUNC_IMPL(__imp__sub_82674780) {
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
	ctx.lr = 0x82674788;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x826747a4
	if (!cr6.eq) goto loc_826747A4;
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8267481c
	if (cr6.eq) goto loc_8267481C;
loc_826747A4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r10,-10224
	r29.s64 = ctx.r10.s64 + -10224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826747C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee270
	ctx.lr = 0x826747D0;
	sub_825EE270(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826747E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8267481c
	if (cr6.eq) goto loc_8267481C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r31,80(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82653450
	ctx.lr = 0x82674814;
	sub_82653450(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8267481C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674828"))) PPC_WEAK_FUNC(sub_82674828);
PPC_FUNC_IMPL(__imp__sub_82674828) {
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
	// bl 0x82630580
	ctx.lr = 0x82674840;
	sub_82630580(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,804(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674854;
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

__attribute__((alias("__imp__sub_82674868"))) PPC_WEAK_FUNC(sub_82674868);
PPC_FUNC_IMPL(__imp__sub_82674868) {
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
	// bl 0x82674400
	ctx.lr = 0x82674880;
	sub_82674400(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28644
	ctx.r4.s64 = r11.s64 + 28644;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82674894;
	sub_8262FFE0(ctx, base);
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

__attribute__((alias("__imp__sub_826748A8"))) PPC_WEAK_FUNC(sub_826748A8);
PPC_FUNC_IMPL(__imp__sub_826748A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,24348
	ctx.r4.s64 = r11.s64 + 24348;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// b 0x8262ffe0
	sub_8262FFE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826748BC"))) PPC_WEAK_FUNC(sub_826748BC);
PPC_FUNC_IMPL(__imp__sub_826748BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826748C0"))) PPC_WEAK_FUNC(sub_826748C0);
PPC_FUNC_IMPL(__imp__sub_826748C0) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267491c
	if (cr6.eq) goto loc_8267491C;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x826748fc
	if (cr6.eq) goto loc_826748FC;
	// bl 0x826537d0
	ctx.lr = 0x826748E8;
	sub_826537D0(ctx, base);
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
loc_826748FC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82674950
	if (cr6.eq) goto loc_82674950;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// b 0x82674938
	goto loc_82674938;
loc_8267491C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82674950
	if (!cr6.eq) goto loc_82674950;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
loc_82674938:
	// bl 0x821e6800
	ctx.lr = 0x8267493C;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674950:
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

__attribute__((alias("__imp__sub_82674968"))) PPC_WEAK_FUNC(sub_82674968);
PPC_FUNC_IMPL(__imp__sub_82674968) {
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
	// bl 0x826535f8
	ctx.lr = 0x82674984;
	sub_826535F8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r9,2612
	r30.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x826749B0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x826749C0;
	sub_825ED480(ctx, base);
	// li r8,2
	ctx.r8.s64 = 2;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-13284
	ctx.r4.s64 = ctx.r7.s64 + -13284;
	// bl 0x82722678
	ctx.lr = 0x826749D8;
	sub_82722678(ctx, base);
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

__attribute__((alias("__imp__sub_826749F0"))) PPC_WEAK_FUNC(sub_826749F0);
PPC_FUNC_IMPL(__imp__sub_826749F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r5,1008(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1008, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674A00"))) PPC_WEAK_FUNC(sub_82674A00);
PPC_FUNC_IMPL(__imp__sub_82674A00) {
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
	// bl 0x82653b30
	ctx.lr = 0x82674A18;
	sub_82653B30(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// lwz r3,-19636(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19636);
	// bl 0x821e6800
	ctx.lr = 0x82674A3C;
	sub_821E6800(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r31,1000
	ctx.r4.s64 = r31.s64 + 1000;
	// lwz r3,-19632(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -19632);
	// bl 0x821e6810
	ctx.lr = 0x82674A4C;
	sub_821E6810(ctx, base);
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

__attribute__((alias("__imp__sub_82674A60"))) PPC_WEAK_FUNC(sub_82674A60);
PPC_FUNC_IMPL(__imp__sub_82674A60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674aa4
	if (cr6.eq) goto loc_82674AA4;
	// lfs f0,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 992);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,992(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
loc_82674AA4:
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

__attribute__((alias("__imp__sub_82674ABC"))) PPC_WEAK_FUNC(sub_82674ABC);
PPC_FUNC_IMPL(__imp__sub_82674ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674AC0"))) PPC_WEAK_FUNC(sub_82674AC0);
PPC_FUNC_IMPL(__imp__sub_82674AC0) {
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
	// bl 0x82653670
	ctx.lr = 0x82674AD8;
	sub_82653670(ctx, base);
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82674aec
	if (cr6.eq) goto loc_82674AEC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x82674AEC;
	sub_8213C218(ctx, base);
loc_82674AEC:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,-19628(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -19628);
	// bl 0x821e6800
	ctx.lr = 0x82674AF8;
	sub_821E6800(ctx, base);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r10,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674B18;
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

__attribute__((alias("__imp__sub_82674B2C"))) PPC_WEAK_FUNC(sub_82674B2C);
PPC_FUNC_IMPL(__imp__sub_82674B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674B30"))) PPC_WEAK_FUNC(sub_82674B30);
PPC_FUNC_IMPL(__imp__sub_82674B30) {
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
	ctx.lr = 0x82674B38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826535f8
	ctx.lr = 0x82674B44;
	sub_826535F8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,25856
	ctx.r4.s64 = r11.s64 + 25856;
	// bl 0x825ee120
	ctx.lr = 0x82674B58;
	sub_825EE120(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r30,r10,2612
	r30.s64 = ctx.r10.s64 + 2612;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82674B70;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x82674B80;
	sub_825ED480(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-13268
	ctx.r4.s64 = ctx.r9.s64 + -13268;
	// bl 0x82722678
	ctx.lr = 0x82674B90;
	sub_82722678(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r8,-12592
	ctx.r4.s64 = ctx.r8.s64 + -12592;
	// bl 0x825ee0e0
	ctx.lr = 0x82674BA4;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674BAC"))) PPC_WEAK_FUNC(sub_82674BAC);
PPC_FUNC_IMPL(__imp__sub_82674BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674BB0"))) PPC_WEAK_FUNC(sub_82674BB0);
PPC_FUNC_IMPL(__imp__sub_82674BB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// addi r11,r4,-55
	r11.s64 = ctx.r4.s64 + -55;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82674c30
	if (cr6.gt) goto loc_82674C30;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,19432
	r12.s64 = r12.s64 + 19432;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82674BF8;
	case 1:
		goto loc_82674C18;
	case 2:
		goto loc_82674C18;
	case 3:
		goto loc_82674C18;
	default:
		__builtin_unreachable();
	}
	// lwz r19,19448(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19448);
	// lwz r19,19480(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19480);
	// lwz r19,19480(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19480);
	// lwz r19,19480(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19480);
loc_82674BF8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82674C04;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674C18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674C18:
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
loc_82674C30:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x82674C38;
	sub_826537D0(ctx, base);
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

__attribute__((alias("__imp__sub_82674C4C"))) PPC_WEAK_FUNC(sub_82674C4C);
PPC_FUNC_IMPL(__imp__sub_82674C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674C50"))) PPC_WEAK_FUNC(sub_82674C50);
PPC_FUNC_IMPL(__imp__sub_82674C50) {
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
	// bl 0x82653670
	ctx.lr = 0x82674C60;
	sub_82653670(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82674C68;
	sub_82216138(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674C78"))) PPC_WEAK_FUNC(sub_82674C78);
PPC_FUNC_IMPL(__imp__sub_82674C78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674CA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674cec
	if (cr6.eq) goto loc_82674CEC;
	// lfs f0,1008(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1008);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,1008(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1008, temp.u32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82674cec
	if (!cr6.gt) goto loc_82674CEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674CE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,1008(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1008, temp.u32);
loc_82674CEC:
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

__attribute__((alias("__imp__sub_82674D04"))) PPC_WEAK_FUNC(sub_82674D04);
PPC_FUNC_IMPL(__imp__sub_82674D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674D08"))) PPC_WEAK_FUNC(sub_82674D08);
PPC_FUNC_IMPL(__imp__sub_82674D08) {
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
	// bl 0x82630158
	ctx.lr = 0x82674D24;
	sub_82630158(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r31,224
	ctx.r5.s64 = r31.s64 + 224;
	// addi r4,r11,20292
	ctx.r4.s64 = r11.s64 + 20292;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82722678
	ctx.lr = 0x82674D38;
	sub_82722678(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,208(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r4,r10,20268
	ctx.r4.s64 = ctx.r10.s64 + 20268;
	// bl 0x827227b8
	ctx.lr = 0x82674D4C;
	sub_827227B8(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,212(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r4,r9,-11016
	ctx.r4.s64 = ctx.r9.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x82674D60;
	sub_827227B8(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r4,r8,-11024
	ctx.r4.s64 = ctx.r8.s64 + -11024;
	// bl 0x827227b8
	ctx.lr = 0x82674D74;
	sub_827227B8(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,220(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// addi r4,r7,-11032
	ctx.r4.s64 = ctx.r7.s64 + -11032;
	// bl 0x827227b8
	ctx.lr = 0x82674D88;
	sub_827227B8(ctx, base);
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

__attribute__((alias("__imp__sub_82674DA0"))) PPC_WEAK_FUNC(sub_82674DA0);
PPC_FUNC_IMPL(__imp__sub_82674DA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674DCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674de4
	if (cr6.eq) goto loc_82674DE4;
	// lfs f0,1064(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1064);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,1064(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1064, temp.u32);
loc_82674DE4:
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

__attribute__((alias("__imp__sub_82674DFC"))) PPC_WEAK_FUNC(sub_82674DFC);
PPC_FUNC_IMPL(__imp__sub_82674DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674E00"))) PPC_WEAK_FUNC(sub_82674E00);
PPC_FUNC_IMPL(__imp__sub_82674E00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,216(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82674e20
	if (cr6.eq) goto loc_82674E20;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82674E20:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674E28"))) PPC_WEAK_FUNC(sub_82674E28);
PPC_FUNC_IMPL(__imp__sub_82674E28) {
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
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82674eb8
	if (cr6.eq) goto loc_82674EB8;
loc_82674E4C:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674E64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82674eb8
	if (cr6.eq) goto loc_82674EB8;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x82674eac
	if (!cr6.eq) goto loc_82674EAC;
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
	ctx.lr = 0x82674E94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,744(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 744);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674EAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674EAC:
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82674e4c
	if (!cr6.eq) goto loc_82674E4C;
loc_82674EB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630580
	ctx.lr = 0x82674EC0;
	sub_82630580(ctx, base);
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

__attribute__((alias("__imp__sub_82674ED8"))) PPC_WEAK_FUNC(sub_82674ED8);
PPC_FUNC_IMPL(__imp__sub_82674ED8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,6892
	ctx.r4.s64 = r11.s64 + 6892;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633e80
	ctx.lr = 0x82674EFC;
	sub_82633E80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,25884
	ctx.r8.s64 = ctx.r10.s64 + 25884;
	// stb r9,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_82674F28"))) PPC_WEAK_FUNC(sub_82674F28);
PPC_FUNC_IMPL(__imp__sub_82674F28) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82674f6c
	if (cr6.eq) goto loc_82674F6C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-14960
	ctx.r4.s64 = ctx.r10.s64 + -14960;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674F6C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653670
	ctx.lr = 0x82674F74;
	sub_82653670(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x82674F78;
	sub_822150D8(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x82674F7C;
	sub_82216648(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-21704
	ctx.r3.s64 = ctx.r10.s64 + -21704;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x82674F9C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674FB0;
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

__attribute__((alias("__imp__sub_82674FC8"))) PPC_WEAK_FUNC(sub_82674FC8);
PPC_FUNC_IMPL(__imp__sub_82674FC8) {
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
	// bl 0x82653670
	ctx.lr = 0x82674FD8;
	sub_82653670(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c4520
	ctx.lr = 0x82674FE4;
	sub_826C4520(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674FF4"))) PPC_WEAK_FUNC(sub_82674FF4);
PPC_FUNC_IMPL(__imp__sub_82674FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674FF8"))) PPC_WEAK_FUNC(sub_82674FF8);
PPC_FUNC_IMPL(__imp__sub_82674FF8) {
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
	ctx.lr = 0x82675000;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x8267500C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82675020
	if (cr6.eq) goto loc_82675020;
	// bl 0x82256058
	ctx.lr = 0x82675018;
	sub_82256058(ctx, base);
	// addi r28,r3,8
	r28.s64 = ctx.r3.s64 + 8;
	// b 0x82675024
	goto loc_82675024;
loc_82675020:
	// li r28,0
	r28.s64 = 0;
loc_82675024:
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82675030;
	sub_822A39C8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675044;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826750c4
	if (cr6.eq) goto loc_826750C4;
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826750c4
	if (cr6.eq) goto loc_826750C4;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
loc_8267506C:
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826750a8
	if (cr6.eq) goto loc_826750A8;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82675080;
	sub_822A39C8(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// beq cr6,0x826750a8
	if (cr6.eq) goto loc_826750A8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826750A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r25
	cr6.compare<int32_t>(ctx.r3.s32, r25.s32, xer);
	// beq cr6,0x826750c0
	if (cr6.eq) goto loc_826750C0;
loc_826750A8:
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// bne cr6,0x8267506c
	if (!cr6.eq) goto loc_8267506C;
	// b 0x826750c4
	goto loc_826750C4;
loc_826750C0:
	// li r23,1
	r23.s64 = 1;
loc_826750C4:
	// cmpwi cr6,r25,16
	cr6.compare<int32_t>(r25.s32, 16, xer);
	// addi r29,r31,1004
	r29.s64 = r31.s64 + 1004;
	// bgt cr6,0x826750ec
	if (cr6.gt) goto loc_826750EC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826750E8;
	sub_82137A08(ctx, base);
	// b 0x8267510c
	goto loc_8267510C;
loc_826750EC:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stb r11,1004(r31)
	PPC_STORE_U8(r31.u32 + 1004, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,2352
	ctx.r4.s64 = ctx.r10.s64 + 2352;
	// li r24,1
	r24.s64 = 1;
	// li r23,0
	r23.s64 = 0;
	// bl 0x8263b860
	ctx.lr = 0x8267510C;
	sub_8263B860(ctx, base);
loc_8267510C:
	// clrlwi r28,r24,24
	r28.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8267517c
	if (!cr6.eq) goto loc_8267517C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263b428
	ctx.lr = 0x82675124;
	sub_8263B428(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r25,1
	cr6.compare<int32_t>(r25.s32, 1, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// beq cr6,0x8267516c
	if (cr6.eq) goto loc_8267516C;
	// cmpwi cr6,r25,2
	cr6.compare<int32_t>(r25.s32, 2, xer);
	// beq cr6,0x82675160
	if (cr6.eq) goto loc_82675160;
	// cmpwi cr6,r25,3
	cr6.compare<int32_t>(r25.s32, 3, xer);
	// beq cr6,0x82675154
	if (cr6.eq) goto loc_82675154;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2348
	ctx.r4.s64 = ctx.r10.s64 + 2348;
	// b 0x82675174
	goto loc_82675174;
loc_82675154:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,26824
	ctx.r4.s64 = ctx.r10.s64 + 26824;
	// b 0x82675174
	goto loc_82675174;
loc_82675160:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,26820
	ctx.r4.s64 = ctx.r10.s64 + 26820;
	// b 0x82675174
	goto loc_82675174;
loc_8267516C:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,26816
	ctx.r4.s64 = ctx.r10.s64 + 26816;
loc_82675174:
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267517C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267517C:
	// clrlwi r30,r23,24
	r30.u64 = r23.u32 & 0xFF;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// cntlzw r9,r30
	ctx.r9.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// addi r27,r10,26800
	r27.s64 = ctx.r10.s64 + 26800;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r7,468(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// xori r26,r8,1
	r26.u64 = ctx.r8.u64 ^ 1;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826751A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826751B4;
	sub_825EE0E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cntlzw r6,r28
	ctx.r6.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r27,r5,26784
	r27.s64 = ctx.r5.s64 + 26784;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// xori r26,r4,1
	r26.u64 = ctx.r4.u64 ^ 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826751DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826751E8;
	sub_825EE0E0(ctx, base);
	// lwz r6,1008(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x82675254
	if (!cr6.gt) goto loc_82675254;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,26776
	ctx.r5.s64 = r11.s64 + 26776;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82675208;
	sub_82137A08(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,26744
	ctx.r4.s64 = ctx.r9.s64 + 26744;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82675220;
	sub_822183B0(ctx, base);
	// lwz r7,1024(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// addi r4,r8,26712
	ctx.r4.s64 = ctx.r8.s64 + 26712;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267523C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// b 0x82675268
	goto loc_82675268;
loc_82675254:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82675268:
	// bctrl 
	ctx.lr = 0x8267526C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// beq cr6,0x82675288
	if (cr6.eq) goto loc_82675288;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r6,r11,26704
	ctx.r6.s64 = r11.s64 + 26704;
	// b 0x8267528c
	goto loc_8267528C;
loc_82675288:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
loc_8267528C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8267529c
	if (cr6.eq) goto loc_8267529C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r11,26696
	ctx.r5.s64 = r11.s64 + 26696;
loc_8267529C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,26652
	ctx.r3.s64 = r11.s64 + 26652;
	// bl 0x82130000
	ctx.lr = 0x826752AC;
	sub_82130000(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826752B4"))) PPC_WEAK_FUNC(sub_826752B4);
PPC_FUNC_IMPL(__imp__sub_826752B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826752B8"))) PPC_WEAK_FUNC(sub_826752B8);
PPC_FUNC_IMPL(__imp__sub_826752B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,18504(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// lhz r11,4(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826752fc
	if (!cr6.gt) goto loc_826752FC;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_826752D4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826752e8
	if (!cr6.eq) goto loc_826752E8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_826752E8:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x826752d4
	if (!cr0.eq) goto loc_826752D4;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82675304
	if (!cr6.eq) goto loc_82675304;
loc_826752FC:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_82675304:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267530C"))) PPC_WEAK_FUNC(sub_8267530C);
PPC_FUNC_IMPL(__imp__sub_8267530C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82675310"))) PPC_WEAK_FUNC(sub_82675310);
PPC_FUNC_IMPL(__imp__sub_82675310) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,18508(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 18508);
	// bl 0x826b95b0
	ctx.lr = 0x82675338;
	sub_826B95B0(ctx, base);
	// lwz r11,18508(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 18508);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,508(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// stw r9,3684(r31)
	PPC_STORE_U32(r31.u32 + 3684, ctx.r9.u32);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r8,3688(r31)
	PPC_STORE_U32(r31.u32 + 3688, ctx.r8.u32);
	// lwz r3,18504(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18504);
	// bl 0x826b53f8
	ctx.lr = 0x82675358;
	sub_826B53F8(ctx, base);
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

__attribute__((alias("__imp__sub_82675370"))) PPC_WEAK_FUNC(sub_82675370);
PPC_FUNC_IMPL(__imp__sub_82675370) {
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
	// bl 0x82653670
	ctx.lr = 0x82675388;
	sub_82653670(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18504(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// bl 0x826b6228
	ctx.lr = 0x82675394;
	sub_826B6228(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,3692(r31)
	PPC_STORE_U32(r31.u32 + 3692, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_826753B0"))) PPC_WEAK_FUNC(sub_826753B0);
PPC_FUNC_IMPL(__imp__sub_826753B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826753DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267543c
	if (cr6.eq) goto loc_8267543C;
	// lfs f0,3664(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3664);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,3664(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3664, temp.u32);
	// bl 0x82387a18
	ctx.lr = 0x826753F8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826754b8
	if (cr6.eq) goto loc_826754B8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3664(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3664);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826754b8
	if (!cr6.gt) goto loc_826754B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267542C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,3664(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3664, temp.u32);
	// b 0x826754b8
	goto loc_826754B8;
loc_8267543C:
	// lwz r11,3692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3692);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82675490
	if (cr6.eq) goto loc_82675490;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826754b8
	if (!cr6.eq) goto loc_826754B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826754b8
	if (!cr6.eq) goto loc_826754B8;
	// li r11,3
	r11.s64 = 3;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r11,3692(r31)
	PPC_STORE_U32(r31.u32 + 3692, r11.u32);
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213338
	ctx.lr = 0x8267548C;
	sub_82213338(ctx, base);
	// b 0x826754b8
	goto loc_826754B8;
loc_82675490:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826754A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826754b8
	if (cr6.eq) goto loc_826754B8;
	// li r11,2
	r11.s64 = 2;
	// stw r11,3692(r31)
	PPC_STORE_U32(r31.u32 + 3692, r11.u32);
loc_826754B8:
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

__attribute__((alias("__imp__sub_826754D0"))) PPC_WEAK_FUNC(sub_826754D0);
PPC_FUNC_IMPL(__imp__sub_826754D0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x826754D8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227f588
	ctx.lr = 0x826754F4;
	sub_8227F588(ctx, base);
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227f588
	ctx.lr = 0x82675508;
	sub_8227F588(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267551C;
	sub_822A3998(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267552C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r25,r11,27136
	r25.s64 = r11.s64 + 27136;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// stfs f0,1064(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1064, temp.u32);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// lwz r29,-10244(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// addi r24,r10,2352
	r24.s64 = ctx.r10.s64 + 2352;
	// addi r28,r9,27124
	r28.s64 = ctx.r9.s64 + 27124;
	// addi r27,r8,27104
	r27.s64 = ctx.r8.s64 + 27104;
	// addi r23,r31,992
	r23.s64 = r31.s64 + 992;
	// addi r30,r11,-10244
	r30.s64 = r11.s64 + -10244;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bne cr6,0x826755b0
	if (!cr6.eq) goto loc_826755B0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82218310
	ctx.lr = 0x82675580;
	sub_82218310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// addi r4,r11,27092
	ctx.r4.s64 = r11.s64 + 27092;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x82675594;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// bl 0x82137a08
	ctx.lr = 0x826755AC;
	sub_82137A08(ctx, base);
	// b 0x826755e8
	goto loc_826755E8;
loc_826755B0:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x826755B8;
	sub_82218310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// addi r4,r11,27092
	ctx.r4.s64 = r11.s64 + 27092;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x826755CC;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r8,r20
	ctx.r8.u64 = r20.u64;
	// bl 0x82137a08
	ctx.lr = 0x826755E8;
	sub_82137A08(ctx, base);
loc_826755E8:
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r22,-1
	cr6.compare<int32_t>(r22.s32, -1, xer);
	// addi r29,r31,1024
	r29.s64 = r31.s64 + 1024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x82675634
	if (!cr6.eq) goto loc_82675634;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82218310
	ctx.lr = 0x82675604;
	sub_82218310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r11,27076
	ctx.r4.s64 = r11.s64 + 27076;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82675618;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x82675630;
	sub_82137A08(ctx, base);
	// b 0x8267566c
	goto loc_8267566C;
loc_82675634:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x8267563C;
	sub_82218310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r11,27076
	ctx.r4.s64 = r11.s64 + 27076;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82675650;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// bl 0x82137a08
	ctx.lr = 0x8267566C;
	sub_82137A08(ctx, base);
loc_8267566C:
	// cmpw cr6,r26,r22
	cr6.compare<int32_t>(r26.s32, r22.s32, xer);
	// bne cr6,0x82675680
	if (!cr6.eq) goto loc_82675680;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,27056
	ctx.r4.s64 = ctx.r10.s64 + 27056;
	// b 0x82675698
	goto loc_82675698;
loc_82675680:
	// cmpwi cr6,r21,2
	cr6.compare<int32_t>(r21.s32, 2, xer);
	// bne cr6,0x826756e4
	if (!cr6.eq) goto loc_826756E4;
	// cmpw cr6,r26,r22
	cr6.compare<int32_t>(r26.s32, r22.s32, xer);
	// bgt cr6,0x826756f4
	if (cr6.gt) goto loc_826756F4;
loc_82675690:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,27032
	ctx.r4.s64 = ctx.r10.s64 + 27032;
loc_82675698:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826756AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1056(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826756C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1060(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1060);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,344(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 344);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826756DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_826756E4:
	// cmpwi cr6,r21,1
	cr6.compare<int32_t>(r21.s32, 1, xer);
	// bne cr6,0x82675690
	if (!cr6.eq) goto loc_82675690;
	// cmpw cr6,r22,r26
	cr6.compare<int32_t>(r22.s32, r26.s32, xer);
	// ble cr6,0x82675690
	if (!cr6.gt) goto loc_82675690;
loc_826756F4:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,27012
	ctx.r4.s64 = ctx.r10.s64 + 27012;
	// b 0x82675698
	goto loc_82675698;
}

__attribute__((alias("__imp__sub_82675700"))) PPC_WEAK_FUNC(sub_82675700);
PPC_FUNC_IMPL(__imp__sub_82675700) {
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
	ctx.lr = 0x8267572C;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82675744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r4,r11,27144
	ctx.r4.s64 = r11.s64 + 27144;
	// li r5,3
	ctx.r5.s64 = 3;
	// bne cr6,0x82675764
	if (!cr6.eq) goto loc_82675764;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82675764:
	// bl 0x825ee0e0
	ctx.lr = 0x82675768;
	sub_825EE0E0(ctx, base);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267578c
	if (cr6.eq) goto loc_8267578C;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675788;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826757b4
	goto loc_826757B4;
loc_8267578C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-19772
	r31.s64 = ctx.r10.s64 + -19772;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826757A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x826757B4;
	sub_825EE0E0(ctx, base);
loc_826757B4:
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

__attribute__((alias("__imp__sub_826757CC"))) PPC_WEAK_FUNC(sub_826757CC);
PPC_FUNC_IMPL(__imp__sub_826757CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826757D0"))) PPC_WEAK_FUNC(sub_826757D0);
PPC_FUNC_IMPL(__imp__sub_826757D0) {
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
	ctx.lr = 0x826757D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,764
	ctx.r4.s64 = ctx.r10.s64 + 764;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x826757FC;
	sub_82691650(ctx, base);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r9,3998
	ctx.r4.s64 = ctx.r9.s64 + 3998;
	// stw r30,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r30.u32);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// stw r28,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r28.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267582C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r6,27172
	ctx.r4.s64 = ctx.r6.s64 + 27172;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x82675840;
	sub_8268DA78(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r29,r11,29572
	r29.s64 = r11.s64 + 29572;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r5,27160
	ctx.r4.s64 = ctx.r5.s64 + 27160;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// bl 0x8268da78
	ctx.lr = 0x82675864;
	sub_8268DA78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r30,860(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bgt cr6,0x82675898
	if (cr6.gt) goto loc_82675898;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82675898:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826758B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826347f0
	ctx.lr = 0x826758C0;
	sub_826347F0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826758D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826758f4
	if (cr6.eq) goto loc_826758F4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826758F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826758F4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826758FC"))) PPC_WEAK_FUNC(sub_826758FC);
PPC_FUNC_IMPL(__imp__sub_826758FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82675900"))) PPC_WEAK_FUNC(sub_82675900);
PPC_FUNC_IMPL(__imp__sub_82675900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// b 0x82675310
	sub_82675310(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267590C"))) PPC_WEAK_FUNC(sub_8267590C);
PPC_FUNC_IMPL(__imp__sub_8267590C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82675910"))) PPC_WEAK_FUNC(sub_82675910);
PPC_FUNC_IMPL(__imp__sub_82675910) {
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
	ctx.lr = 0x82675918;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x82675924;
	sub_82653B30(ctx, base);
	// bl 0x82216788
	ctx.lr = 0x82675928;
	sub_82216788(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x8267592C;
	sub_82215A60(ctx, base);
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,126
	ctx.r9.s64 = r11.s64 + 126;
	// addi r4,r10,25216
	ctx.r4.s64 = ctx.r10.s64 + 25216;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r8,r11,r31
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82675954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,992(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r27,r31,992
	r27.s64 = r31.s64 + 992;
	// addi r4,r6,27840
	ctx.r4.s64 = ctx.r6.s64 + 27840;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82675974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,1040(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// li r30,1
	r30.s64 = 1;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x826759bc
	if (!cr6.gt) goto loc_826759BC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,996
	r29.s64 = r31.s64 + 996;
	// addi r28,r11,3998
	r28.s64 = r11.s64 + 3998;
loc_82675990:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826759A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1040(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x82675990
	if (cr6.lt) goto loc_82675990;
loc_826759BC:
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,248
	ctx.r9.s64 = r11.s64 + 248;
	// addi r4,r10,25228
	ctx.r4.s64 = ctx.r10.s64 + 25228;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826759E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,852(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r8,848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, xer);
	// beq cr6,0x82675a1c
	if (cr6.eq) goto loc_82675A1C;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_82675A08:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82675a08
	if (!cr6.eq) goto loc_82675A08;
loc_82675A1C:
	// subf r9,r8,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// srawi r7,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r4,1040(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addic. r3,r4,1
	xer.ca = ctx.r4.u32 > 4294967294;
	ctx.r3.s64 = ctx.r4.s64 + 1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble 0x82675a7c
	if (!cr0.gt) goto loc_82675A7C;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
loc_82675A44:
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stwx r4,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r4.u32);
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// blt cr6,0x82675a44
	if (cr6.lt) goto loc_82675A44;
loc_82675A7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82675A84"))) PPC_WEAK_FUNC(sub_82675A84);
PPC_FUNC_IMPL(__imp__sub_82675A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82675A88"))) PPC_WEAK_FUNC(sub_82675A88);
PPC_FUNC_IMPL(__imp__sub_82675A88) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82675A90;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,62
	ctx.r4.s64 = 62;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 476);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675AAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653b30
	ctx.lr = 0x82675AB4;
	sub_82653B30(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82675AB8;
	sub_82256058(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82675ed8
	if (cr6.eq) goto loc_82675ED8;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82675afc
	if (cr6.eq) goto loc_82675AFC;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82675AE8:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82675ae8
	if (!cr6.eq) goto loc_82675AE8;
loc_82675AFC:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addi r4,r9,27976
	ctx.r4.s64 = ctx.r9.s64 + 27976;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// addi r24,r25,8
	r24.s64 = r25.s64 + 8;
	// sth r7,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r7.u16);
	// lwz r3,992(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82675B30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,992(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r29,0
	r29.s64 = 0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r27,1
	r27.s64 = 1;
	// li r10,25
	ctx.r10.s64 = 25;
	// stb r29,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, r29.u8);
	// addi r28,r11,32684
	r28.s64 = r11.s64 + 32684;
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r26,r31,1072
	r26.s64 = r31.s64 + 1072;
	// stb r29,209(r8)
	PPC_STORE_U8(ctx.r8.u32 + 209, r29.u8);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r7,992(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r27,212(r7)
	PPC_STORE_U32(ctx.r7.u32 + 212, r27.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r10,216(r11)
	PPC_STORE_U32(r11.u32 + 216, ctx.r10.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82137a08
	ctx.lr = 0x82675B98;
	sub_82137A08(ctx, base);
	// lwz r3,1012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82675BB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82256150
	ctx.lr = 0x82675BB8;
	sub_82256150(ctx, base);
	// lis r4,32767
	ctx.r4.s64 = 2147418112;
	// lwz r11,48(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 48);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// ori r26,r4,65535
	r26.u64 = ctx.r4.u64 | 65535;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// beq cr6,0x82675bdc
	if (cr6.eq) goto loc_82675BDC;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bge cr6,0x82675be0
	if (!cr6.lt) goto loc_82675BE0;
loc_82675BDC:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82675BE0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// addi r25,r31,1232
	r25.s64 = r31.s64 + 1232;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// xori r6,r9,1
	ctx.r6.u64 = ctx.r9.u64 ^ 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82137a08
	ctx.lr = 0x82675C04;
	sub_82137A08(ctx, base);
	// lwz r3,1052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1052);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82675C1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8223de50
	ctx.lr = 0x82675C28;
	sub_8223DE50(ctx, base);
	// lis r22,-32121
	r22.s64 = -2105081856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r6,27964
	ctx.r4.s64 = ctx.r6.s64 + 27964;
	// lwz r3,-10244(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82675C40;
	sub_822183B0(ctx, base);
	// lwz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r4,r5,27944
	ctx.r4.s64 = ctx.r5.s64 + 27944;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675C5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,996(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// li r23,19
	r23.s64 = 19;
	// stb r29,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, r29.u8);
	// lwz r8,996(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stb r29,209(r8)
	PPC_STORE_U8(ctx.r8.u32 + 209, r29.u8);
	// lwz r7,996(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stw r27,212(r7)
	PPC_STORE_U32(ctx.r7.u32 + 212, r27.u32);
	// lwz r6,996(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stw r23,216(r6)
	PPC_STORE_U32(ctx.r6.u32 + 216, r23.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r3.u16);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r4,40(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// cmpw cr6,r4,r26
	cr6.compare<int32_t>(ctx.r4.s32, r26.s32, xer);
	// beq cr6,0x82675cc8
	if (cr6.eq) goto loc_82675CC8;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8223de50
	ctx.lr = 0x82675CB4;
	sub_8223DE50(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,-10244(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10244);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r11,27932
	ctx.r4.s64 = r11.s64 + 27932;
	// b 0x82675cec
	goto loc_82675CEC;
loc_82675CC8:
	// lwz r26,-10244(r22)
	r26.u64 = PPC_LOAD_U32(r22.u32 + -10244);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r11,2352
	ctx.r4.s64 = r11.s64 + 2352;
	// bl 0x82218310
	ctx.lr = 0x82675CDC;
	sub_82218310(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,27932
	ctx.r4.s64 = ctx.r10.s64 + 27932;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82675CEC:
	// bl 0x822183b0
	ctx.lr = 0x82675CF0;
	sub_822183B0(ctx, base);
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,27912
	ctx.r4.s64 = r11.s64 + 27912;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82675D0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1000(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,27900
	ctx.r4.s64 = ctx.r8.s64 + 27900;
	// stb r29,208(r7)
	PPC_STORE_U8(ctx.r7.u32 + 208, r29.u8);
	// lwz r6,1000(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stb r29,209(r6)
	PPC_STORE_U8(ctx.r6.u32 + 209, r29.u8);
	// lwz r5,1000(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stw r27,212(r5)
	PPC_STORE_U32(ctx.r5.u32 + 212, r27.u32);
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stw r23,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, r23.u32);
	// lwz r8,1000(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r6.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r3,1004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675D68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1004(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// li r9,26
	ctx.r9.s64 = 26;
	// addi r26,r31,1120
	r26.s64 = r31.s64 + 1120;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stb r29,208(r8)
	PPC_STORE_U8(ctx.r8.u32 + 208, r29.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r7,1004(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// li r4,16
	ctx.r4.s64 = 16;
	// stb r29,209(r7)
	PPC_STORE_U8(ctx.r7.u32 + 209, r29.u8);
	// lwz r11,1004(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// stw r27,212(r11)
	PPC_STORE_U32(r11.u32 + 212, r27.u32);
	// lwz r10,1004(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// stw r9,216(r10)
	PPC_STORE_U32(ctx.r10.u32 + 216, ctx.r9.u32);
	// lwz r8,1004(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82137a08
	ctx.lr = 0x82675DC0;
	sub_82137A08(ctx, base);
	// lwz r3,1024(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82675DD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,109
	ctx.r3.s64 = 109;
	// bl 0x82204a48
	ctx.lr = 0x82675DE0;
	sub_82204A48(ctx, base);
	// addi r25,r3,2192
	r25.s64 = ctx.r3.s64 + 2192;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// mr r11,r27
	r11.u64 = r27.u64;
	// lfs f13,192(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,25092(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 25092);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82675e00
	if (cr6.lt) goto loc_82675E00;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82675E00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// addi r26,r31,1238
	r26.s64 = r31.s64 + 1238;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// xori r6,r9,1
	ctx.r6.u64 = ctx.r9.u64 ^ 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82137a08
	ctx.lr = 0x82675E24;
	sub_82137A08(ctx, base);
	// lwz r3,1064(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1064);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82675E3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,192(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f0,31016(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82137a08
	ctx.lr = 0x82675E68;
	sub_82137A08(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,-10244(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10244);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r4,27888
	ctx.r4.s64 = ctx.r4.s64 + 27888;
	// bl 0x822183b0
	ctx.lr = 0x82675E7C;
	sub_822183B0(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r4,r3,27868
	ctx.r4.s64 = ctx.r3.s64 + 27868;
	// lwz r3,1008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675E98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1008(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stb r29,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, r29.u8);
	// lwz r8,1008(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stb r29,209(r8)
	PPC_STORE_U8(ctx.r8.u32 + 209, r29.u8);
	// lwz r7,1008(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stw r27,212(r7)
	PPC_STORE_U32(ctx.r7.u32 + 212, r27.u32);
	// lwz r6,1008(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stw r23,216(r6)
	PPC_STORE_U32(ctx.r6.u32 + 216, r23.u32);
	// lwz r4,1008(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r3.u16);
	// stwx r4,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r4.u32);
loc_82675ED8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82675EE0"))) PPC_WEAK_FUNC(sub_82675EE0);
PPC_FUNC_IMPL(__imp__sub_82675EE0) {
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
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// lhz r11,996(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 996);
	// lwz r9,992(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82675f2c
	if (cr6.eq) goto loc_82675F2C;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82675F18:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82675f18
	if (!cr6.eq) goto loc_82675F18;
loc_82675F2C:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// li r7,6
	ctx.r7.s64 = 6;
	// subf r4,r9,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r9.s64;
	// li r5,4
	ctx.r5.s64 = 4;
	// sth r4,4(r6)
	PPC_STORE_U16(ctx.r6.u32 + 4, ctx.r4.u16);
	// li r4,60
	ctx.r4.s64 = 60;
	// lwz r3,-10004(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10004);
	// bl 0x826c6738
	ctx.lr = 0x82675F58;
	sub_826C6738(ctx, base);
	// lhz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 996);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82675f78
	if (cr6.eq) goto loc_82675F78;
	// bl 0x82387a18
	ctx.lr = 0x82675F68;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,3
	ctx.r3.s64 = 3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82675f7c
	if (cr6.eq) goto loc_82675F7C;
loc_82675F78:
	// li r3,2
	ctx.r3.s64 = 2;
loc_82675F7C:
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

__attribute__((alias("__imp__sub_82675F90"))) PPC_WEAK_FUNC(sub_82675F90);
PPC_FUNC_IMPL(__imp__sub_82675F90) {
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
	ctx.lr = 0x82675F98;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,62
	ctx.r4.s64 = 62;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 476);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675FB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82653b30
	ctx.lr = 0x82675FBC;
	sub_82653B30(ctx, base);
	// lhz r8,996(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 996);
	// addi r11,r29,992
	r11.s64 = r29.s64 + 992;
	// lwz r9,992(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// rotlwi r11,r8,2
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82675ff4
	if (cr6.eq) goto loc_82675FF4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82675FE0:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82675fe0
	if (!cr6.eq) goto loc_82675FE0;
loc_82675FF4:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,996(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 996);
	// addi r6,r29,992
	ctx.r6.s64 = r29.s64 + 992;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// li r7,6
	ctx.r7.s64 = 6;
	// sth r8,4(r6)
	PPC_STORE_U16(ctx.r6.u32 + 4, ctx.r8.u16);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwz r3,-10004(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10004);
	// bl 0x826c6738
	ctx.lr = 0x82676024;
	sub_826C6738(ctx, base);
	// lhz r10,852(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 852);
	// lwz r9,848(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// rotlwi r11,r10,2
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r28,r29,848
	r28.s64 = r29.s64 + 848;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8267605c
	if (cr6.eq) goto loc_8267605C;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82676048:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82676048
	if (!cr6.eq) goto loc_82676048;
loc_8267605C:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addi r3,r9,28052
	ctx.r3.s64 = ctx.r9.s64 + 28052;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r7.u16);
	// lhz r26,996(r29)
	r26.u64 = PPC_LOAD_U16(r29.u32 + 996);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// bl 0x82130000
	ctx.lr = 0x82676088;
	sub_82130000(ctx, base);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ble cr6,0x82676398
	if (!cr6.gt) goto loc_82676398;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x826304b0
	ctx.lr = 0x8267609C;
	sub_826304B0(ctx, base);
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// mr r30,r24
	r30.u64 = r24.u64;
	// mr r14,r24
	r14.u64 = r24.u64;
	// ble cr6,0x826763b4
	if (!cr6.gt) goto loc_826763B4;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r8,r8,24804
	ctx.r8.s64 = ctx.r8.s64 + 24804;
	// addi r7,r7,14248
	ctx.r7.s64 = ctx.r7.s64 + 14248;
	// li r21,1
	r21.s64 = 1;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r17,-32121
	r17.s64 = -2105081856;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// addi r18,r11,28020
	r18.s64 = r11.s64 + 28020;
	// addi r16,r10,32684
	r16.s64 = ctx.r10.s64 + 32684;
	// addi r15,r9,27988
	r15.s64 = ctx.r9.s64 + 27988;
loc_826760EC:
	// lwz r10,992(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// addi r11,r29,992
	r11.s64 = r29.s64 + 992;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwzx r20,r10,r9
	r20.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r8,656(r20)
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + 656);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmpwi cr6,r7,5
	cr6.compare<int32_t>(ctx.r7.s32, 5, xer);
	// beq cr6,0x82676114
	if (cr6.eq) goto loc_82676114;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x826c7370
	ctx.lr = 0x82676114;
	sub_826C7370(ctx, base);
loc_82676114:
	// lwz r11,656(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 656);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// beq cr6,0x8267612c
	if (cr6.eq) goto loc_8267612C;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8267612C:
	// addi r31,r20,200
	r31.s64 = r20.s64 + 200;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// bl 0x82130000
	ctx.lr = 0x82676140;
	sub_82130000(ctx, base);
	// addi r11,r30,250
	r11.s64 = r30.s64 + 250;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82676160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r7,r31,r29
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// li r8,18
	ctx.r8.s64 = 18;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// stb r24,208(r7)
	PPC_STORE_U8(ctx.r7.u32 + 208, r24.u8);
	// addi r27,r11,1256
	r27.s64 = r11.s64 + 1256;
	// lwzx r6,r31,r29
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// stb r24,209(r6)
	PPC_STORE_U8(ctx.r6.u32 + 209, r24.u8);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r11,r31,r29
	r11.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// stw r21,212(r11)
	PPC_STORE_U32(r11.u32 + 212, r21.u32);
	// lwzx r10,r31,r29
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// stw r8,216(r10)
	PPC_STORE_U32(ctx.r10.u32 + 216, ctx.r8.u32);
	// lwzx r9,r31,r29
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// stb r21,210(r9)
	PPC_STORE_U8(ctx.r9.u32 + 210, r21.u8);
	// lwzx r8,r31,r29
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lhz r7,4(r28)
	ctx.r7.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rotlwi r11,r7,2
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r6.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lhz r19,720(r20)
	r19.u64 = PPC_LOAD_U16(r20.u32 + 720);
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// bl 0x82137a08
	ctx.lr = 0x826761D0;
	sub_82137A08(ctx, base);
	// addi r8,r30,266
	ctx.r8.s64 = r30.s64 + 266;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r7,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + r29.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826761F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,656(r20)
	ctx.r4.u64 = PPC_LOAD_U32(r20.u32 + 656);
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r30,692
	r11.s64 = r30.s64 + 692;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r9,49
	ctx.r9.s64 = 49;
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// stb r24,1385(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1385, r24.u8);
	// beq cr6,0x82676220
	if (cr6.eq) goto loc_82676220;
	// li r9,48
	ctx.r9.s64 = 48;
loc_82676220:
	// stbx r9,r11,r29
	PPC_STORE_U8(r11.u32 + r29.u32, ctx.r9.u8);
	// addi r11,r30,274
	r11.s64 = r30.s64 + 274;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82676240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bge cr6,0x826763b4
	if (!cr6.lt) goto loc_826763B4;
	// mr r22,r24
	r22.u64 = r24.u64;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// ble cr6,0x82676370
	if (!cr6.gt) goto loc_82676370;
	// addi r9,r30,250
	ctx.r9.s64 = r30.s64 + 250;
	// rlwinm r11,r30,5,0,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r7,r30,692
	ctx.r7.s64 = r30.s64 + 692;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// add r31,r8,r29
	r31.u64 = ctx.r8.u64 + r29.u64;
	// addi r27,r11,1400
	r27.s64 = r11.s64 + 1400;
	// add r25,r9,r29
	r25.u64 = ctx.r9.u64 + r29.u64;
	// addi r26,r10,1256
	r26.s64 = ctx.r10.s64 + 1256;
loc_82676288:
	// stb r24,-128(r26)
	PPC_STORE_U8(r26.u32 + -128, r24.u8);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// stb r24,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r24.u8);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// stb r24,0(r25)
	PPC_STORE_U8(r25.u32 + 0, r24.u8);
	// bl 0x826c72a0
	ctx.lr = 0x826762A0;
	sub_826C72A0(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82676360
	if (cr6.eq) goto loc_82676360;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x826cc350
	ctx.lr = 0x826762B8;
	sub_826CC350(ctx, base);
	// lbz r11,116(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 116);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826762cc
	if (!cr6.eq) goto loc_826762CC;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_826762CC:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x826762DC;
	sub_82130000(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10244(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826762EC;
	sub_822183B0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r8,116(r23)
	ctx.r8.u64 = PPC_LOAD_U8(r23.u32 + 116);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r25,r25,2
	r25.s64 = r25.s64 + 2;
	// addi r26,r26,16
	r26.s64 = r26.s64 + 16;
	// addi r27,r27,32
	r27.s64 = r27.s64 + 32;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// stb r8,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, ctx.r8.u8);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r21,209(r7)
	PPC_STORE_U8(ctx.r7.u32 + 209, r21.u8);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r21,212(r6)
	PPC_STORE_U32(ctx.r6.u32 + 212, r21.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r24,210(r5)
	PPC_STORE_U8(ctx.r5.u32 + 210, r24.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lhz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r9,r4,1
	ctx.r9.s64 = ctx.r4.s64 + 1;
	// sth r9,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r9.u16);
	// stwx r3,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r3.u32);
	// bge cr6,0x826763b4
	if (!cr6.lt) goto loc_826763B4;
loc_82676360:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// cmpw cr6,r22,r19
	cr6.compare<int32_t>(r22.s32, r19.s32, xer);
	// blt cr6,0x82676288
	if (cr6.lt) goto loc_82676288;
	// lwz r26,92(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82676370:
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bge cr6,0x826763b4
	if (!cr6.lt) goto loc_826763B4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r14,r14,1
	r14.s64 = r14.s64 + 1;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// cmpw cr6,r14,r26
	cr6.compare<int32_t>(r14.s32, r26.s32, xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// blt cr6,0x826760ec
	if (cr6.lt) goto loc_826760EC;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9210
	return;
loc_82676398:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x826304b0
	ctx.lr = 0x826763A0;
	sub_826304B0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826763B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826763B4:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_826763BC"))) PPC_WEAK_FUNC(sub_826763BC);
PPC_FUNC_IMPL(__imp__sub_826763BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826763C0"))) PPC_WEAK_FUNC(sub_826763C0);
PPC_FUNC_IMPL(__imp__sub_826763C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,1032(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1032);
	// addi r9,r3,992
	ctx.r9.s64 = ctx.r3.s64 + 992;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826763f4
	if (cr6.eq) goto loc_826763F4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826763E0:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826763e0
	if (!cr6.eq) goto loc_826763E0;
loc_826763F4:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lwz r10,40(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// li r11,0
	r11.s64 = 0;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r6.u32);
	// stfs f0,3664(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 3664, temp.u32);
	// stw r11,3672(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3672, r11.u32);
	// stw r11,3680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3680, r11.u32);
	// stw r11,3676(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3676, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82676428"))) PPC_WEAK_FUNC(sub_82676428);
PPC_FUNC_IMPL(__imp__sub_82676428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,852(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 852);
	// addi r10,r3,848
	ctx.r10.s64 = ctx.r3.s64 + 848;
	// lwz r8,848(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82676460
	if (cr6.eq) goto loc_82676460;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_8267644C:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x8267644c
	if (!cr6.eq) goto loc_8267644C;
loc_82676460:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// sth r7,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r7.u16);
	// lwz r4,3672(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3672);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x826764d4
	if (!cr6.gt) goto loc_826764D4;
	// addi r11,r3,992
	r11.s64 = ctx.r3.s64 + 992;
	// addi r6,r3,1268
	ctx.r6.s64 = ctx.r3.s64 + 1268;
loc_8267648C:
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r8,3676(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3676);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x826764bc
	if (!cr6.eq) goto loc_826764BC;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// sth r7,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r7.u16);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
loc_826764BC:
	// lwz r9,3672(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3672);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r6,r6,240
	ctx.r6.s64 = ctx.r6.s64 + 240;
	// cmpw cr6,r5,r9
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r9.s32, xer);
	// blt cr6,0x8267648c
	if (cr6.lt) goto loc_8267648C;
loc_826764D4:
	// lwz r11,3676(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3676);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3676(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3676, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826764E4"))) PPC_WEAK_FUNC(sub_826764E4);
PPC_FUNC_IMPL(__imp__sub_826764E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826764E8"))) PPC_WEAK_FUNC(sub_826764E8);
PPC_FUNC_IMPL(__imp__sub_826764E8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x8267654c
	if (!cr6.eq) goto loc_8267654C;
	// lwz r11,3676(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3676);
	// lwz r10,3680(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bge cr6,0x82676534
	if (!cr6.lt) goto loc_82676534;
	// bl 0x821e6800
	ctx.lr = 0x82676520;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82676428
	ctx.lr = 0x82676528;
	sub_82676428(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// b 0x82676540
	goto loc_82676540;
loc_82676534:
	// bl 0x821e6800
	ctx.lr = 0x82676538;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
loc_82676540:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267654C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267654C:
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

__attribute__((alias("__imp__sub_82676564"))) PPC_WEAK_FUNC(sub_82676564);
PPC_FUNC_IMPL(__imp__sub_82676564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82676568"))) PPC_WEAK_FUNC(sub_82676568);
PPC_FUNC_IMPL(__imp__sub_82676568) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// addi r8,r10,28644
	ctx.r8.s64 = ctx.r10.s64 + 28644;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826765A0;
	sub_82654318(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,28740
	ctx.r8.s64 = ctx.r9.s64 + 28740;
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

__attribute__((alias("__imp__sub_826765C4"))) PPC_WEAK_FUNC(sub_826765C4);
PPC_FUNC_IMPL(__imp__sub_826765C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826765C8"))) PPC_WEAK_FUNC(sub_826765C8);
PPC_FUNC_IMPL(__imp__sub_826765C8) {
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
	ctx.lr = 0x826765D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r29,992
	r31.s64 = r29.s64 + 992;
	// addi r10,r11,29548
	ctx.r10.s64 = r11.s64 + 29548;
	// li r30,4
	r30.s64 = 4;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826765EC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267660c
	if (cr6.eq) goto loc_8267660C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267660C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267660C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826765ec
	if (!cr0.eq) goto loc_826765EC;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r11,r29,1040
	r11.s64 = r29.s64 + 1040;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r9,5568
	ctx.r9.s64 = ctx.r9.s64 + 5568;
loc_82676628:
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x82676628
	if (!cr0.lt) goto loc_82676628;
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676650
	if (cr6.eq) goto loc_82676650;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82676650;
	sub_82130588(ctx, base);
loc_82676650:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676664
	if (cr6.eq) goto loc_82676664;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82676664;
	sub_82130588(ctx, base);
loc_82676664:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267666C;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82676674;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8267667C;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676684;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267668C"))) PPC_WEAK_FUNC(sub_8267668C);
PPC_FUNC_IMPL(__imp__sub_8267668C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82676690"))) PPC_WEAK_FUNC(sub_82676690);
PPC_FUNC_IMPL(__imp__sub_82676690) {
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
	ctx.lr = 0x82676698;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r29,1012
	r31.s64 = r29.s64 + 1012;
	// addi r10,r11,30356
	ctx.r10.s64 = r11.s64 + 30356;
	// li r30,5
	r30.s64 = 5;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826766B4:
	// lwz r3,-20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826766d4
	if (cr6.eq) goto loc_826766D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826766D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826766D4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826766f4
	if (cr6.eq) goto loc_826766F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826766F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826766F4:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676714
	if (cr6.eq) goto loc_82676714;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676714;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676714:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676734
	if (cr6.eq) goto loc_82676734;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676734:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826766b4
	if (!cr0.eq) goto loc_826766B4;
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676758
	if (cr6.eq) goto loc_82676758;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82676758;
	sub_82130588(ctx, base);
loc_82676758:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267676c
	if (cr6.eq) goto loc_8267676C;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8267676C;
	sub_82130588(ctx, base);
loc_8267676C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676774;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x8267677C;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82676784;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267678C;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82676794"))) PPC_WEAK_FUNC(sub_82676794);
PPC_FUNC_IMPL(__imp__sub_82676794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82676798"))) PPC_WEAK_FUNC(sub_82676798);
PPC_FUNC_IMPL(__imp__sub_82676798) {
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
	ctx.lr = 0x826767A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r29,1032
	r31.s64 = r29.s64 + 1032;
	// addi r10,r11,31164
	ctx.r10.s64 = r11.s64 + 31164;
	// li r30,10
	r30.s64 = 10;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826767BC:
	// lwz r3,-40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826767dc
	if (cr6.eq) goto loc_826767DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826767DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826767DC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826767fc
	if (cr6.eq) goto loc_826767FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826767FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826767FC:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267681c
	if (cr6.eq) goto loc_8267681C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267681C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267681C:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267683c
	if (cr6.eq) goto loc_8267683C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267683C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267683C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826767bc
	if (!cr0.eq) goto loc_826767BC;
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676860
	if (cr6.eq) goto loc_82676860;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82676860;
	sub_82130588(ctx, base);
loc_82676860:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676874
	if (cr6.eq) goto loc_82676874;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82676874;
	sub_82130588(ctx, base);
loc_82676874:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267687C;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82676884;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8267688C;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676894;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267689C"))) PPC_WEAK_FUNC(sub_8267689C);
PPC_FUNC_IMPL(__imp__sub_8267689C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826768A0"))) PPC_WEAK_FUNC(sub_826768A0);
PPC_FUNC_IMPL(__imp__sub_826768A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r10,r11,31972
	ctx.r10.s64 = r11.s64 + 31972;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x8221fcc8
	sub_8221FCC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826768B0"))) PPC_WEAK_FUNC(sub_826768B0);
PPC_FUNC_IMPL(__imp__sub_826768B0) {
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
	ctx.lr = 0x826768B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r31,r29,1032
	r31.s64 = r29.s64 + 1032;
	// addi r10,r11,-32756
	ctx.r10.s64 = r11.s64 + -32756;
	// li r30,8
	r30.s64 = 8;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826768D4:
	// lwz r3,-32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826768f4
	if (cr6.eq) goto loc_826768F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826768F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826768F4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676914
	if (cr6.eq) goto loc_82676914;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676914:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676934
	if (cr6.eq) goto loc_82676934;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676934:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676954
	if (cr6.eq) goto loc_82676954;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676954:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826768d4
	if (!cr0.eq) goto loc_826768D4;
	// lhz r11,998(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 998);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676974
	if (cr6.eq) goto loc_82676974;
	// lwz r3,992(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// bl 0x82130588
	ctx.lr = 0x82676974;
	sub_82130588(ctx, base);
loc_82676974:
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267698c
	if (cr6.eq) goto loc_8267698C;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x8267698C;
	sub_82130588(ctx, base);
loc_8267698C:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826769a0
	if (cr6.eq) goto loc_826769A0;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x826769A0;
	sub_82130588(ctx, base);
loc_826769A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826769A8;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x826769B0;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x826769B8;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x826769C0;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826769C8"))) PPC_WEAK_FUNC(sub_826769C8);
PPC_FUNC_IMPL(__imp__sub_826769C8) {
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
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,764
	ctx.r4.s64 = ctx.r9.s64 + 764;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826543a0
	ctx.lr = 0x82676A08;
	sub_826543A0(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r6,r8,-31948
	ctx.r6.s64 = ctx.r8.s64 + -31948;
	// addi r5,r7,-4092
	ctx.r5.s64 = ctx.r7.s64 + -4092;
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r5,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r5.u32);
	// sth r4,1002(r31)
	PPC_STORE_U16(r31.u32 + 1002, ctx.r4.u16);
	// li r3,64
	ctx.r3.s64 = 64;
	// sth r30,1000(r31)
	PPC_STORE_U16(r31.u32 + 1000, r30.u16);
	// addi r11,r31,992
	r11.s64 = r31.s64 + 992;
	// bl 0x82130528
	ctx.lr = 0x82676A3C;
	sub_82130528(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// addi r9,r11,6560
	ctx.r9.s64 = r11.s64 + 6560;
	// stw r30,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r30.u32);
	// stw r10,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82676A74"))) PPC_WEAK_FUNC(sub_82676A74);
PPC_FUNC_IMPL(__imp__sub_82676A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82676A78"))) PPC_WEAK_FUNC(sub_82676A78);
PPC_FUNC_IMPL(__imp__sub_82676A78) {
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
	ctx.lr = 0x82676A80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-31140
	ctx.r9.s64 = r11.s64 + -31140;
	// li r4,17
	ctx.r4.s64 = 17;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x82676AA8;
	sub_82213650(ctx, base);
	// lhz r8,3634(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 3634);
	// addi r31,r29,3440
	r31.s64 = r29.s64 + 3440;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82676ac0
	if (cr6.eq) goto loc_82676AC0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82676AC0;
	sub_82130588(ctx, base);
loc_82676AC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676AC8;
	sub_82633B00(ctx, base);
	// addi r31,r29,3440
	r31.s64 = r29.s64 + 3440;
	// li r30,9
	r30.s64 = 9;
loc_82676AD0:
	// addi r31,r31,-240
	r31.s64 = r31.s64 + -240;
	// lhz r11,194(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676ae8
	if (cr6.eq) goto loc_82676AE8;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82676AE8;
	sub_82130588(ctx, base);
loc_82676AE8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676AF0;
	sub_82633B00(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x82676ad0
	if (!cr0.lt) goto loc_82676AD0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82676B00;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82676B08"))) PPC_WEAK_FUNC(sub_82676B08);
PPC_FUNC_IMPL(__imp__sub_82676B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x82676B10;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x82676B1C;
	sub_82653B30(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r16,0
	r16.s64 = 0;
	// li r18,-1
	r18.s64 = -1;
	// li r28,0
	r28.s64 = 0;
	// bl 0x826763c0
	ctx.lr = 0x82676B30;
	sub_826763C0(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,18508(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// bl 0x826b95b0
	ctx.lr = 0x82676B40;
	sub_826B95B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// lwz r26,8(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82676B5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r8,3688(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3688);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r22,r11,-14284
	r22.s64 = r11.s64 + -14284;
	// lwz r23,304(r3)
	r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	// subf. r11,r8,r26
	r11.s64 = r26.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r21,12
	r21.s64 = 12;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r17,r10,32684
	r17.s64 = ctx.r10.s64 + 32684;
	// beq 0x82676e2c
	if (cr0.eq) goto loc_82676E2C;
	// lis r10,15258
	ctx.r10.s64 = 999948288;
	// ori r30,r10,51711
	r30.u64 = ctx.r10.u64 | 51711;
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// blt cr6,0x82676b98
	if (cr6.lt) goto loc_82676B98;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82676B98:
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x82676BA8;
	sub_823DC018(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r4,r11,-30196
	ctx.r4.s64 = r11.s64 + -30196;
	// bl 0x822183b0
	ctx.lr = 0x82676BBC;
	sub_822183B0(ctx, base);
	// cmpw cr6,r26,r30
	cr6.compare<int32_t>(r26.s32, r30.s32, xer);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// blt cr6,0x82676bcc
	if (cr6.lt) goto loc_82676BCC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
loc_82676BCC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r25,r11,26932
	r25.s64 = r11.s64 + 26932;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x823dc018
	ctx.lr = 0x82676BE0;
	sub_823DC018(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r4,r11,26908
	ctx.r4.s64 = r11.s64 + 26908;
	// bl 0x822183b0
	ctx.lr = 0x82676BF4;
	sub_822183B0(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r4,r10,-30208
	ctx.r4.s64 = ctx.r10.s64 + -30208;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x827205a8
	ctx.lr = 0x82676C08;
	sub_827205A8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,18508(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// bl 0x826b92c8
	ctx.lr = 0x82676C14;
	sub_826B92C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// blt cr6,0x82676c28
	if (cr6.lt) goto loc_82676C28;
	// mr r11,r21
	r11.u64 = r21.u64;
loc_82676C28:
	// addi r10,r11,38
	ctx.r10.s64 = r11.s64 + 38;
	// lwz r11,18508(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// rlwinm r24,r10,2,0,29
	r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfsx f0,r24,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823dc018
	ctx.lr = 0x82676C50;
	sub_823DC018(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r9,26884
	ctx.r4.s64 = ctx.r9.s64 + 26884;
	// bl 0x822183b0
	ctx.lr = 0x82676C64;
	sub_822183B0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-26544
	ctx.r6.s64 = ctx.r8.s64 + -26544;
	// lwzx r4,r7,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwz r25,-10244(r29)
	r25.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82218310
	ctx.lr = 0x82676C80;
	sub_82218310(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-14244
	ctx.r4.s64 = ctx.r4.s64 + -14244;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822183b0
	ctx.lr = 0x82676C94;
	sub_822183B0(ctx, base);
	// cmpwi cr6,r30,12
	cr6.compare<int32_t>(r30.s32, 12, xer);
	// bne cr6,0x82676cc8
	if (!cr6.eq) goto loc_82676CC8;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// li r26,100
	r26.s64 = 100;
	// addi r4,r11,-14304
	ctx.r4.s64 = r11.s64 + -14304;
	// bl 0x82218310
	ctx.lr = 0x82676CB0;
	sub_82218310(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,-14348
	ctx.r4.s64 = ctx.r10.s64 + -14348;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82720588
	ctx.lr = 0x82676CC4;
	sub_82720588(ctx, base);
	// b 0x82676d30
	goto loc_82676D30;
loc_82676CC8:
	// extsw r10,r26
	ctx.r10.s64 = r26.s32;
	// lwz r11,18508(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// addi r9,r30,38
	ctx.r9.s64 = r30.s64 + 38;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfsx f11,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f10,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// fctiwz f8,f11
	ctx.f8.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r4,r6,-14348
	ctx.r4.s64 = ctx.r6.s64 + -14348;
	// lfs f0,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fsubs f7,f12,f10
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fdivs f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 / ctx.f9.f64));
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r26,84(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x827205a8
	ctx.lr = 0x82676D30;
	sub_827205A8(ctx, base);
loc_82676D30:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r4,r11,-30220
	ctx.r4.s64 = r11.s64 + -30220;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x827205a8
	ctx.lr = 0x82676D44;
	sub_827205A8(ctx, base);
	// lwz r3,18508(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// lwz r4,3688(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 3688);
	// bl 0x826b92c8
	ctx.lr = 0x82676D50;
	sub_826B92C8(ctx, base);
	// subf r10,r30,r3
	ctx.r10.s64 = ctx.r3.s64 - r30.s64;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// li r4,24
	ctx.r4.s64 = 24;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// xori r6,r8,1
	ctx.r6.u64 = ctx.r8.u64 ^ 1;
	// bl 0x82137a08
	ctx.lr = 0x82676D70;
	sub_82137A08(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82676D80;
	sub_822183B0(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r30,-10244(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82676D90;
	sub_82218310(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r7,26828
	ctx.r4.s64 = ctx.r7.s64 + 26828;
	// bl 0x82218310
	ctx.lr = 0x82676DA4;
	sub_82218310(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r6,26856
	ctx.r4.s64 = ctx.r6.s64 + 26856;
	// bl 0x82218310
	ctx.lr = 0x82676DB8;
	sub_82218310(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r4,r5,26936
	ctx.r4.s64 = ctx.r5.s64 + 26936;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82676DCC;
	sub_82218310(ctx, base);
	// lwz r4,3672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// li r7,11
	ctx.r7.s64 = 11;
	// mulli r11,r4,240
	r11.s64 = ctx.r4.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r7,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, ctx.r7.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r24,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r24.u32);
	// stw r25,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r25.u32);
	// stw r26,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r26.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r6,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r6.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r5,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r5.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_82676E2C:
	// li r26,0
	r26.s64 = 0;
	// bl 0x82256058
	ctx.lr = 0x82676E34;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676e4c
	if (cr6.eq) goto loc_82676E4C;
	// lwz r11,3104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3104);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bne cr6,0x82676e4c
	if (!cr6.eq) goto loc_82676E4C;
	// li r26,1
	r26.s64 = 1;
loc_82676E4C:
	// lwz r11,18508(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,3684(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3684);
	// addi r30,r10,3998
	r30.s64 = ctx.r10.s64 + 3998;
	// lwz r27,508(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// subf. r5,r9,r27
	ctx.r5.s64 = r27.s64 - ctx.r9.s64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne 0x82676e74
	if (!cr0.eq) goto loc_82676E74;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676f58
	if (cr6.eq) goto loc_82676F58;
loc_82676E74:
	// clrlwi r26,r26,24
	r26.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82676e94
	if (!cr6.eq) goto loc_82676E94;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-30240
	ctx.r4.s64 = r11.s64 + -30240;
	// bl 0x82218788
	ctx.lr = 0x82676E94;
	sub_82218788(ctx, base);
loc_82676E94:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-30256
	ctx.r4.s64 = r11.s64 + -30256;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82218788
	ctx.lr = 0x82676EAC;
	sub_82218788(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r10,-30272
	ctx.r4.s64 = ctx.r10.s64 + -30272;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x827205a8
	ctx.lr = 0x82676EC0;
	sub_827205A8(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82676ed4
	if (!cr6.eq) goto loc_82676ED4;
	// lwz r11,3684(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3684);
	// subf. r10,r11,r27
	ctx.r10.s64 = r27.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x82676f58
	if (!cr0.gt) goto loc_82676F58;
loc_82676ED4:
	// lwz r27,-10244(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r11,26960
	ctx.r4.s64 = r11.s64 + 26960;
	// bl 0x82218310
	ctx.lr = 0x82676EE8;
	sub_82218310(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r4,r10,26984
	ctx.r4.s64 = ctx.r10.s64 + 26984;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x82676EFC;
	sub_82218310(ctx, base);
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r21,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r21.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r26,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r26.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r7,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r7.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_82676F58:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,796(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 796);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82676fc4
	if (cr6.eq) goto loc_82676FC4;
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r7,r31,3440
	ctx.r7.s64 = r31.s64 + 3440;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r6,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r6.u32);
	// stw r21,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r21.u32);
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r30,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, r30.u32);
	// stw r30,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r30.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r5.u32);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
loc_82676FC4:
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82676fe0
	if (cr6.eq) goto loc_82676FE0;
	// mr r16,r11
	r16.u64 = r11.u64;
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, r11.u32);
loc_82676FE0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r19,-32121
	r19.s64 = -2105081856;
	// li r21,0
	r21.s64 = 0;
	// lwz r27,18504(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826770e4
	if (cr6.eq) goto loc_826770E4;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r25,0
	r25.s64 = 0;
	// li r23,14
	r23.s64 = 14;
	// addi r24,r11,-30296
	r24.s64 = r11.s64 + -30296;
loc_8267700C:
	// cmpwi cr6,r28,7
	cr6.compare<int32_t>(r28.s32, 7, xer);
	// bgt cr6,0x826770e4
	if (cr6.gt) goto loc_826770E4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bne cr6,0x826770d0
	if (!cr6.eq) goto loc_826770D0;
	// lwz r11,-10236(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10236);
	// addi r5,r10,92
	ctx.r5.s64 = ctx.r10.s64 + 92;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x8267703C;
	sub_82213B80(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r26,-10244(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// lwzx r11,r25,r11
	r11.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// bl 0x82218310
	ctx.lr = 0x82677054;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x822183b0
	ctx.lr = 0x82677064;
	sub_822183B0(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82677070;
	sub_82218310(ctx, base);
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r23,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r23.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r30,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r30.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r7,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r7.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_826770D0:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// blt cr6,0x8267700c
	if (cr6.lt) goto loc_8267700C;
loc_826770E4:
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// cmpw cr6,r11,r16
	cr6.compare<int32_t>(r11.s32, r16.s32, xer);
	// beq cr6,0x82677104
	if (cr6.eq) goto loc_82677104;
	// mr r16,r11
	r16.u64 = r11.u64;
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// li r28,0
	r28.s64 = 0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, r11.u32);
loc_82677104:
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r24,19
	r24.s64 = 19;
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r21,r11,-14748
	r21.s64 = r11.s64 + -14748;
	// beq cr6,0x82677314
	if (cr6.eq) goto loc_82677314;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r25,0
	r25.s64 = 0;
	// addi r22,r11,25056
	r22.s64 = r11.s64 + 25056;
	// addi r20,r10,30804
	r20.s64 = ctx.r10.s64 + 30804;
loc_82677134:
	// cmpwi cr6,r28,7
	cr6.compare<int32_t>(r28.s32, 7, xer);
	// bgt cr6,0x82677314
	if (cr6.gt) goto loc_82677314;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r10,9
	cr6.compare<int32_t>(ctx.r10.s32, 9, xer);
	// bne cr6,0x8267719c
	if (!cr6.eq) goto loc_8267719C;
	// cmpwi cr6,r18,-1
	cr6.compare<int32_t>(r18.s32, -1, xer);
	// bne cr6,0x8267718c
	if (!cr6.eq) goto loc_8267718C;
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r9,r31,992
	ctx.r9.s64 = r31.s64 + 992;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mulli r8,r11,240
	ctx.r8.s64 = r11.s64 * 240;
	// stw r10,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r10.u32);
	// lwz r10,1032(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// addi r10,r8,1040
	ctx.r10.s64 = ctx.r8.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// mr r18,r11
	r18.u64 = r11.u64;
	// stwx r10,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r10.u32);
loc_8267718C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r25,r11
	r11.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// b 0x82677298
	goto loc_82677298;
loc_8267719C:
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x82677214
	if (!cr6.eq) goto loc_82677214;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// lwzx r3,r25,r11
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826771BC;
	sub_823DEDD8(ctx, base);
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82677300
	if (cr6.eq) goto loc_82677300;
	// cmpwi cr6,r18,-1
	cr6.compare<int32_t>(r18.s32, -1, xer);
	// bne cr6,0x82677204
	if (!cr6.eq) goto loc_82677204;
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r8,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r8.u32);
	// mr r18,r11
	r18.u64 = r11.u64;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r9,r9,1040
	ctx.r9.s64 = ctx.r9.s64 + 1040;
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r7.u32);
	// stwx r9,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r9.u32);
loc_82677204:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r25,r11
	r11.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// b 0x82677298
	goto loc_82677298;
loc_82677214:
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82677300
	if (!cr6.eq) goto loc_82677300;
	// cmpwi cr6,r18,-1
	cr6.compare<int32_t>(r18.s32, -1, xer);
	// bne cr6,0x82677258
	if (!cr6.eq) goto loc_82677258;
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r8,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r8.u32);
	// mr r18,r11
	r18.u64 = r11.u64;
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// addi r9,r9,1040
	ctx.r9.s64 = ctx.r9.s64 + 1040;
	// stw r7,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r7.u32);
	// stwx r9,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r9.u32);
loc_82677258:
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8267726C;
	sub_82137A08(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r26,-10244(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// lwzx r11,r25,r11
	r11.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// bl 0x82218310
	ctx.lr = 0x82677284;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x822183b0
	ctx.lr = 0x82677294;
	sub_822183B0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
loc_82677298:
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826772A0;
	sub_82218310(ctx, base);
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r24,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r24.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r30.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r7.u32);
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_82677300:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82677134
	if (cr6.lt) goto loc_82677134;
loc_82677314:
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// cmpw cr6,r11,r16
	cr6.compare<int32_t>(r11.s32, r16.s32, xer);
	// beq cr6,0x826773b0
	if (cr6.eq) goto loc_826773B0;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82677334;
	sub_82137A08(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r26,r11,25364
	r26.s64 = r11.s64 + 25364;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822183b0
	ctx.lr = 0x8267734C;
	sub_822183B0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r26,-10244(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82218310
	ctx.lr = 0x8267735C;
	sub_82218310(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r10,-30316
	ctx.r4.s64 = ctx.r10.s64 + -30316;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82218310
	ctx.lr = 0x82677370;
	sub_82218310(ctx, base);
	// mulli r11,r18,240
	r11.s64 = r18.s64 * 240;
	// lwz r9,3680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r8,17
	ctx.r8.s64 = 17;
	// addi r10,r11,1040
	ctx.r10.s64 = r11.s64 + 1040;
	// li r18,-1
	r18.s64 = -1;
	// stw r8,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, ctx.r8.u32);
	// stw r25,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r25.u32);
	// stw r9,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r9.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r16,3672(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// stw r7,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, ctx.r7.u32);
loc_826773B0:
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// li r22,0
	r22.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826773ec
	if (!cr6.gt) goto loc_826773EC;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
loc_826773C4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r9,10
	cr6.compare<int32_t>(ctx.r9.s32, 10, xer);
	// beq cr6,0x826773dc
	if (cr6.eq) goto loc_826773DC;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x826773e0
	if (!cr6.eq) goto loc_826773E0;
loc_826773DC:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
loc_826773E0:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826773c4
	if (!cr0.eq) goto loc_826773C4;
loc_826773EC:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82677414
	if (cr6.eq) goto loc_82677414;
	// add r11,r22,r28
	r11.u64 = r22.u64 + r28.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// ble cr6,0x82677414
	if (!cr6.gt) goto loc_82677414;
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// li r28,0
	r28.s64 = 0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, r11.u32);
loc_82677414:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82677560
	if (cr6.eq) goto loc_82677560;
	// li r25,0
	r25.s64 = 0;
loc_82677428:
	// cmpwi cr6,r28,7
	cr6.compare<int32_t>(r28.s32, 7, xer);
	// bgt cr6,0x82677560
	if (cr6.gt) goto loc_82677560;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x8267744c
	if (cr6.eq) goto loc_8267744C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8267754c
	if (!cr6.eq) goto loc_8267754C;
loc_8267744C:
	// cmpwi cr6,r18,-1
	cr6.compare<int32_t>(r18.s32, -1, xer);
	// bne cr6,0x82677488
	if (!cr6.eq) goto loc_82677488;
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r9,r31,992
	ctx.r9.s64 = r31.s64 + 992;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mulli r8,r11,240
	ctx.r8.s64 = r11.s64 * 240;
	// stw r10,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r10.u32);
	// lwz r10,1032(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// addi r10,r8,1040
	ctx.r10.s64 = ctx.r8.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// mr r18,r11
	r18.u64 = r11.u64;
	// stwx r10,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r10.u32);
loc_82677488:
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8267749C;
	sub_82137A08(ctx, base);
	// lwz r11,-10236(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10236);
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// addi r5,r10,92
	ctx.r5.s64 = ctx.r10.s64 + 92;
	// bl 0x82213b80
	ctx.lr = 0x826774B8;
	sub_82213B80(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r25,r10
	r11.u64 = PPC_LOAD_U32(r25.u32 + ctx.r10.u32);
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// lwz r26,-10244(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82218310
	ctx.lr = 0x826774D0;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x822183b0
	ctx.lr = 0x826774E0;
	sub_822183B0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826774EC;
	sub_82218310(ctx, base);
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r24,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r24.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r30,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r30.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r7,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r7.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_8267754C:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82677428
	if (cr6.lt) goto loc_82677428;
loc_82677560:
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// cmpw cr6,r11,r16
	cr6.compare<int32_t>(r11.s32, r16.s32, xer);
	// beq cr6,0x826775f4
	if (cr6.eq) goto loc_826775F4;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82677580;
	sub_82137A08(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r28,r11,25328
	r28.s64 = r11.s64 + 25328;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822183b0
	ctx.lr = 0x82677598;
	sub_822183B0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r29,-10244(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x826775A8;
	sub_82218310(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-30336
	ctx.r4.s64 = ctx.r10.s64 + -30336;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x826775BC;
	sub_82218310(ctx, base);
	// mulli r11,r18,240
	r11.s64 = r18.s64 * 240;
	// lwz r9,3680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r8,13
	ctx.r8.s64 = 13;
	// addi r10,r11,1040
	ctx.r10.s64 = r11.s64 + 1040;
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// stw r9,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r9.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r28,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r28.u32);
	// stw r8,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, ctx.r8.u32);
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, ctx.r7.u32);
loc_826775F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82676428
	ctx.lr = 0x826775FC;
	sub_82676428(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82677604"))) PPC_WEAK_FUNC(sub_82677604);
PPC_FUNC_IMPL(__imp__sub_82677604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82677608"))) PPC_WEAK_FUNC(sub_82677608);
PPC_FUNC_IMPL(__imp__sub_82677608) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,28644
	ctx.r5.s64 = r11.s64 + 28644;
	// addi r4,r10,-29360
	ctx.r4.s64 = ctx.r10.s64 + -29360;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826544e0
	ctx.lr = 0x82677634;
	sub_826544E0(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-30172
	ctx.r8.s64 = ctx.r9.s64 + -30172;
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

__attribute__((alias("__imp__sub_82677658"))) PPC_WEAK_FUNC(sub_82677658);
PPC_FUNC_IMPL(__imp__sub_82677658) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r11,28644
	ctx.r5.s64 = r11.s64 + 28644;
	// addi r4,r10,5700
	ctx.r4.s64 = ctx.r10.s64 + 5700;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826544e0
	ctx.lr = 0x82677684;
	sub_826544E0(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-29340
	ctx.r8.s64 = ctx.r9.s64 + -29340;
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

__attribute__((alias("__imp__sub_826776A8"))) PPC_WEAK_FUNC(sub_826776A8);
PPC_FUNC_IMPL(__imp__sub_826776A8) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r11,28644
	ctx.r5.s64 = r11.s64 + 28644;
	// addi r4,r10,5616
	ctx.r4.s64 = ctx.r10.s64 + 5616;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826544e0
	ctx.lr = 0x826776D4;
	sub_826544E0(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-28524
	ctx.r8.s64 = ctx.r9.s64 + -28524;
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

__attribute__((alias("__imp__sub_826776F8"))) PPC_WEAK_FUNC(sub_826776F8);
PPC_FUNC_IMPL(__imp__sub_826776F8) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26892
	ctx.r4.s64 = ctx.r9.s64 + -26892;
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26904
	ctx.r5.s64 = ctx.r10.s64 + -26904;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// bl 0x826543a0
	ctx.lr = 0x82677738;
	sub_826543A0(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// addi r5,r8,-27708
	ctx.r5.s64 = ctx.r8.s64 + -27708;
	// li r11,2
	r11.s64 = 2;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r3,r6,30356
	ctx.r3.s64 = ctx.r6.s64 + 30356;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// addi r4,r10,30348
	ctx.r4.s64 = ctx.r10.s64 + 30348;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x826347f0
	ctx.lr = 0x82677780;
	sub_826347F0(ctx, base);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82677798;
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

__attribute__((alias("__imp__sub_826777B4"))) PPC_WEAK_FUNC(sub_826777B4);
PPC_FUNC_IMPL(__imp__sub_826777B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826777B8"))) PPC_WEAK_FUNC(sub_826777B8);
PPC_FUNC_IMPL(__imp__sub_826777B8) {
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
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x826777DC;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826777E4;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826777fc
	if (cr6.eq) goto loc_826777FC;
	// bl 0x82130588
	ctx.lr = 0x826777F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826777FC:
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

__attribute__((alias("__imp__sub_82677814"))) PPC_WEAK_FUNC(sub_82677814);
PPC_FUNC_IMPL(__imp__sub_82677814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82677818"))) PPC_WEAK_FUNC(sub_82677818);
PPC_FUNC_IMPL(__imp__sub_82677818) {
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
	ctx.lr = 0x82677820;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26864
	ctx.r4.s64 = ctx.r9.s64 + -26864;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26876
	ctx.r5.s64 = ctx.r10.s64 + -26876;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82677850;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r29,r27,1008
	r29.s64 = r27.s64 + 1008;
	// addi r7,r8,29548
	ctx.r7.s64 = ctx.r8.s64 + 29548;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r7,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r7.u32);
	// mr r31,r29
	r31.u64 = r29.u64;
	// li r30,3
	r30.s64 = 3;
	// addi r28,r11,5568
	r28.s64 = r11.s64 + 5568;
	// addi r26,r10,3998
	r26.s64 = ctx.r10.s64 + 3998;
loc_82677878:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677888;
	sub_826311F8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bge 0x82677878
	if (!cr0.lt) goto loc_82677878;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// stw r11,1040(r27)
	PPC_STORE_U32(r27.u32 + 1040, r11.u32);
	// addi r31,r27,672
	r31.s64 = r27.s64 + 672;
	// addi r4,r10,30348
	ctx.r4.s64 = ctx.r10.s64 + 30348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x826347f0
	ctx.lr = 0x826778B4;
	sub_826347F0(ctx, base);
	// lwz r9,672(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 672);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826778CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r27,992
	r30.s64 = r27.s64 + 992;
	// li r31,4
	r31.s64 = 4;
loc_826778D4:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x826778DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826778f4
	if (cr6.eq) goto loc_826778F4;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x826778F0;
	sub_82633D40(ctx, base);
	// b 0x826778f8
	goto loc_826778F8;
loc_826778F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826778F8:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r10,r3,188
	ctx.r10.s64 = ctx.r3.s64 + 188;
	// lwz r10,188(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// lhz r11,192(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 192);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// sth r8,192(r3)
	PPC_STORE_U16(ctx.r3.u32 + 192, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bne 0x826778d4
	if (!cr0.eq) goto loc_826778D4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82677934"))) PPC_WEAK_FUNC(sub_82677934);
PPC_FUNC_IMPL(__imp__sub_82677934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82677938"))) PPC_WEAK_FUNC(sub_82677938);
PPC_FUNC_IMPL(__imp__sub_82677938) {
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
	// bl 0x826765c8
	ctx.lr = 0x82677958;
	sub_826765C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82677970
	if (cr6.eq) goto loc_82677970;
	// bl 0x82130588
	ctx.lr = 0x8267796C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82677970:
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

__attribute__((alias("__imp__sub_82677988"))) PPC_WEAK_FUNC(sub_82677988);
PPC_FUNC_IMPL(__imp__sub_82677988) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82677990;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26824
	ctx.r4.s64 = ctx.r9.s64 + -26824;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26848
	ctx.r5.s64 = ctx.r10.s64 + -26848;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826779C0;
	sub_82654318(ctx, base);
	// lwz r6,496(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 496);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r24,496
	ctx.r3.s64 = r24.s64 + 496;
	// addi r7,r8,30356
	ctx.r7.s64 = ctx.r8.s64 + 30356;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// stw r7,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r7.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826779E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,672(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 672);
	// addi r31,r24,672
	r31.s64 = r24.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82677A00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r9,30276
	ctx.r4.s64 = ctx.r9.s64 + 30276;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826347f0
	ctx.lr = 0x82677A14;
	sub_826347F0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r27,r24,1232
	r27.s64 = r24.s64 + 1232;
	// addi r30,r24,1152
	r30.s64 = r24.s64 + 1152;
	// addi r31,r24,1012
	r31.s64 = r24.s64 + 1012;
	// li r26,5
	r26.s64 = 5;
	// li r28,0
	r28.s64 = 0;
	// li r20,1
	r20.s64 = 1;
	// li r21,-1
	r21.s64 = -1;
	// addi r23,r11,5568
	r23.s64 = r11.s64 + 5568;
	// addi r22,r10,30860
	r22.s64 = ctx.r10.s64 + 30860;
	// addi r25,r9,3998
	r25.s64 = ctx.r9.s64 + 3998;
loc_82677A48:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x82677A50;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677a88
	if (cr6.eq) goto loc_82677A88;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// bl 0x82633d40
	ctx.lr = 0x82677A68;
	sub_82633D40(ctx, base);
	// stw r22,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r22.u32);
	// stb r28,208(r29)
	PPC_STORE_U8(r29.u32 + 208, r28.u8);
	// addi r3,r29,220
	ctx.r3.s64 = r29.s64 + 220;
	// stb r28,210(r29)
	PPC_STORE_U8(r29.u32 + 210, r28.u8);
	// stw r20,212(r29)
	PPC_STORE_U32(r29.u32 + 212, r20.u32);
	// stw r21,216(r29)
	PPC_STORE_U32(r29.u32 + 216, r21.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82677A84;
	sub_821C2F70(ctx, base);
	// b 0x82677a8c
	goto loc_82677A8C;
loc_82677A88:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677A8C:
	// stw r29,-20(r31)
	PPC_STORE_U32(r31.u32 + -20, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677A98;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677ab4
	if (cr6.eq) goto loc_82677AB4;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677AB0;
	sub_826311F8(ctx, base);
	// b 0x82677ab8
	goto loc_82677AB8;
loc_82677AB4:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677AB8:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677AC4;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677ae0
	if (cr6.eq) goto loc_82677AE0;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677ADC;
	sub_826311F8(ctx, base);
	// b 0x82677ae4
	goto loc_82677AE4;
loc_82677AE0:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677AE4:
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677AF0;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677b10
	if (cr6.eq) goto loc_82677B10;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677B08;
	sub_826311F8(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// b 0x82677b14
	goto loc_82677B14;
loc_82677B10:
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_82677B14:
	// lwz r11,-20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// addi r4,r30,-80
	ctx.r4.s64 = r30.s64 + -80;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,-20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// sth r3,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r3.u16);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,-20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r6.u16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stwx r3,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u32);
	// stb r28,-80(r30)
	PPC_STORE_U8(r30.u32 + -80, r28.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82677B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r28.u8);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82677BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r28.u8);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82677BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r27,r27,2
	r27.s64 = r27.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82677a48
	if (!cr0.eq) goto loc_82677A48;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82677BF0"))) PPC_WEAK_FUNC(sub_82677BF0);
PPC_FUNC_IMPL(__imp__sub_82677BF0) {
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
	// bl 0x82676690
	ctx.lr = 0x82677C10;
	sub_82676690(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82677c28
	if (cr6.eq) goto loc_82677C28;
	// bl 0x82130588
	ctx.lr = 0x82677C24;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82677C28:
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

__attribute__((alias("__imp__sub_82677C40"))) PPC_WEAK_FUNC(sub_82677C40);
PPC_FUNC_IMPL(__imp__sub_82677C40) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82677C48;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26776
	ctx.r4.s64 = ctx.r9.s64 + -26776;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26800
	ctx.r5.s64 = ctx.r10.s64 + -26800;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82677C78;
	sub_82654318(ctx, base);
	// lwz r6,496(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 496);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r24,496
	ctx.r3.s64 = r24.s64 + 496;
	// addi r7,r8,31164
	ctx.r7.s64 = ctx.r8.s64 + 31164;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// stw r7,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r7.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82677C9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,672(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 672);
	// addi r31,r24,672
	r31.s64 = r24.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82677CB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r9,30316
	ctx.r4.s64 = ctx.r9.s64 + 30316;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826347f0
	ctx.lr = 0x82677CCC;
	sub_826347F0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r27,r24,1472
	r27.s64 = r24.s64 + 1472;
	// addi r30,r24,1312
	r30.s64 = r24.s64 + 1312;
	// addi r31,r24,1032
	r31.s64 = r24.s64 + 1032;
	// li r26,10
	r26.s64 = 10;
	// li r28,0
	r28.s64 = 0;
	// li r20,1
	r20.s64 = 1;
	// li r21,-1
	r21.s64 = -1;
	// addi r23,r11,5568
	r23.s64 = r11.s64 + 5568;
	// addi r22,r10,30860
	r22.s64 = ctx.r10.s64 + 30860;
	// addi r25,r9,3998
	r25.s64 = ctx.r9.s64 + 3998;
loc_82677D00:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x82677D08;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677d40
	if (cr6.eq) goto loc_82677D40;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// bl 0x82633d40
	ctx.lr = 0x82677D20;
	sub_82633D40(ctx, base);
	// stw r22,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r22.u32);
	// stb r28,208(r29)
	PPC_STORE_U8(r29.u32 + 208, r28.u8);
	// addi r3,r29,220
	ctx.r3.s64 = r29.s64 + 220;
	// stb r28,210(r29)
	PPC_STORE_U8(r29.u32 + 210, r28.u8);
	// stw r20,212(r29)
	PPC_STORE_U32(r29.u32 + 212, r20.u32);
	// stw r21,216(r29)
	PPC_STORE_U32(r29.u32 + 216, r21.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82677D3C;
	sub_821C2F70(ctx, base);
	// b 0x82677d44
	goto loc_82677D44;
loc_82677D40:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677D44:
	// stw r29,-40(r31)
	PPC_STORE_U32(r31.u32 + -40, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677D50;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677d6c
	if (cr6.eq) goto loc_82677D6C;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677D68;
	sub_826311F8(ctx, base);
	// b 0x82677d70
	goto loc_82677D70;
loc_82677D6C:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677D70:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677D7C;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677d98
	if (cr6.eq) goto loc_82677D98;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677D94;
	sub_826311F8(ctx, base);
	// b 0x82677d9c
	goto loc_82677D9C;
loc_82677D98:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677D9C:
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677DA8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677dc8
	if (cr6.eq) goto loc_82677DC8;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677DC0;
	sub_826311F8(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// b 0x82677dcc
	goto loc_82677DCC;
loc_82677DC8:
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_82677DCC:
	// lwz r11,-40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// addi r4,r30,-160
	ctx.r4.s64 = r30.s64 + -160;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,-40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// sth r3,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r3.u16);
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,-40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r6.u16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stwx r3,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u32);
	// stb r28,-160(r30)
	PPC_STORE_U8(r30.u32 + -160, r28.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82677E50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r28.u8);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82677E6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r28.u8);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82677E88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r27,r27,2
	r27.s64 = r27.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82677d00
	if (!cr0.eq) goto loc_82677D00;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82677EA8"))) PPC_WEAK_FUNC(sub_82677EA8);
PPC_FUNC_IMPL(__imp__sub_82677EA8) {
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
	// bl 0x82676798
	ctx.lr = 0x82677EC8;
	sub_82676798(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82677ee0
	if (cr6.eq) goto loc_82677EE0;
	// bl 0x82130588
	ctx.lr = 0x82677EDC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82677EE0:
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

__attribute__((alias("__imp__sub_82677EF8"))) PPC_WEAK_FUNC(sub_82677EF8);
PPC_FUNC_IMPL(__imp__sub_82677EF8) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,-26752
	ctx.r4.s64 = ctx.r9.s64 + -26752;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82677F34;
	sub_82654318(ctx, base);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// addi r7,r8,31972
	ctx.r7.s64 = ctx.r8.s64 + 31972;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82677F58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82677F70"))) PPC_WEAK_FUNC(sub_82677F70);
PPC_FUNC_IMPL(__imp__sub_82677F70) {
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
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,31972
	ctx.r10.s64 = r11.s64 + 31972;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8221fcc8
	ctx.lr = 0x82677F9C;
	sub_8221FCC8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82677fb4
	if (cr6.eq) goto loc_82677FB4;
	// bl 0x82130588
	ctx.lr = 0x82677FB0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82677FB4:
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

__attribute__((alias("__imp__sub_82677FCC"))) PPC_WEAK_FUNC(sub_82677FCC);
PPC_FUNC_IMPL(__imp__sub_82677FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82677FD0"))) PPC_WEAK_FUNC(sub_82677FD0);
PPC_FUNC_IMPL(__imp__sub_82677FD0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82677FD8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26704
	ctx.r4.s64 = ctx.r9.s64 + -26704;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26728
	ctx.r5.s64 = ctx.r10.s64 + -26728;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82678008;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r29,0
	r29.s64 = 0;
	// addi r7,r8,-32756
	ctx.r7.s64 = ctx.r8.s64 + -32756;
	// addi r31,r23,672
	r31.s64 = r23.s64 + 672;
	// stw r7,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,992(r23)
	PPC_STORE_U32(r23.u32 + 992, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r29,996(r23)
	PPC_STORE_U16(r23.u32 + 996, r29.u16);
	// sth r29,998(r23)
	PPC_STORE_U16(r23.u32 + 998, r29.u16);
	// lwz r6,672(r23)
	ctx.r6.u64 = PPC_LOAD_U32(r23.u32 + 672);
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82678040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,886(r23)
	ctx.r5.u64 = PPC_LOAD_U16(r23.u32 + 886);
	// addi r4,r4,30248
	ctx.r4.s64 = ctx.r4.s64 + 30248;
	// bl 0x826347f0
	ctx.lr = 0x82678054;
	sub_826347F0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r27,r29
	r27.u64 = r29.u64;
	// addi r25,r23,1400
	r25.s64 = r23.s64 + 1400;
	// addi r26,r23,1384
	r26.s64 = r23.s64 + 1384;
	// addi r30,r23,1256
	r30.s64 = r23.s64 + 1256;
	// addi r31,r23,1032
	r31.s64 = r23.s64 + 1032;
	// li r18,1
	r18.s64 = 1;
	// li r19,-1
	r19.s64 = -1;
	// addi r21,r11,5568
	r21.s64 = r11.s64 + 5568;
	// addi r20,r10,30860
	r20.s64 = ctx.r10.s64 + 30860;
	// addi r24,r9,-14748
	r24.s64 = ctx.r9.s64 + -14748;
	// addi r22,r8,3998
	r22.s64 = ctx.r8.s64 + 3998;
loc_82678090:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x82678098;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826780d0
	if (cr6.eq) goto loc_826780D0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// bl 0x82633d40
	ctx.lr = 0x826780B0;
	sub_82633D40(ctx, base);
	// stw r20,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r20.u32);
	// stb r29,208(r28)
	PPC_STORE_U8(r28.u32 + 208, r29.u8);
	// addi r3,r28,220
	ctx.r3.s64 = r28.s64 + 220;
	// stb r29,210(r28)
	PPC_STORE_U8(r28.u32 + 210, r29.u8);
	// stw r18,212(r28)
	PPC_STORE_U32(r28.u32 + 212, r18.u32);
	// stw r19,216(r28)
	PPC_STORE_U32(r28.u32 + 216, r19.u32);
	// bl 0x821c2f70
	ctx.lr = 0x826780CC;
	sub_821C2F70(ctx, base);
	// b 0x826780d4
	goto loc_826780D4;
loc_826780D0:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_826780D4:
	// stw r28,-32(r31)
	PPC_STORE_U32(r31.u32 + -32, r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826780E0;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826780fc
	if (cr6.eq) goto loc_826780FC;
	// stw r21,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r21.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x826311f8
	ctx.lr = 0x826780F8;
	sub_826311F8(ctx, base);
	// b 0x82678100
	goto loc_82678100;
loc_826780FC:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_82678100:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8267810C;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82678128
	if (cr6.eq) goto loc_82678128;
	// stw r21,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r21.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x826311f8
	ctx.lr = 0x82678124;
	sub_826311F8(ctx, base);
	// b 0x8267812c
	goto loc_8267812C;
loc_82678128:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_8267812C:
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678138;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82678158
	if (cr6.eq) goto loc_82678158;
	// stw r21,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r21.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x826311f8
	ctx.lr = 0x82678150;
	sub_826311F8(ctx, base);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// b 0x8267815c
	goto loc_8267815C;
loc_82678158:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8267815C:
	// lwz r11,-32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// addi r4,r30,-128
	ctx.r4.s64 = r30.s64 + -128;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,-32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// sth r3,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r3.u16);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,-32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r6.u16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stwx r3,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u32);
	// stb r29,-128(r30)
	PPC_STORE_U8(r30.u32 + -128, r29.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826781E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r29,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r29.u8);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826781FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r29,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r29.u8);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82678218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82137a08
	ctx.lr = 0x8267822C;
	sub_82137A08(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r25,r25,32
	r25.s64 = r25.s64 + 32;
	// cmpwi cr6,r27,8
	cr6.compare<int32_t>(r27.s32, 8, xer);
	// blt cr6,0x82678090
	if (cr6.lt) goto loc_82678090;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82678254"))) PPC_WEAK_FUNC(sub_82678254);
PPC_FUNC_IMPL(__imp__sub_82678254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82678258"))) PPC_WEAK_FUNC(sub_82678258);
PPC_FUNC_IMPL(__imp__sub_82678258) {
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
	// bl 0x826768b0
	ctx.lr = 0x82678278;
	sub_826768B0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82678290
	if (cr6.eq) goto loc_82678290;
	// bl 0x82130588
	ctx.lr = 0x8267828C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82678290:
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

__attribute__((alias("__imp__sub_826782A8"))) PPC_WEAK_FUNC(sub_826782A8);
PPC_FUNC_IMPL(__imp__sub_826782A8) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-25872
	ctx.r4.s64 = ctx.r9.s64 + -25872;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,26816
	ctx.r5.s64 = ctx.r10.s64 + 26816;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826782E8;
	sub_82654318(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,-26676
	ctx.r6.s64 = ctx.r7.s64 + -26676;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// lfs f0,11360(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11360);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,996(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// stw r11,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, r11.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,3998
	ctx.r4.s64 = ctx.r4.s64 + 3998;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82678324;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r3.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
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

__attribute__((alias("__imp__sub_8267835C"))) PPC_WEAK_FUNC(sub_8267835C);
PPC_FUNC_IMPL(__imp__sub_8267835C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82678360"))) PPC_WEAK_FUNC(sub_82678360);
PPC_FUNC_IMPL(__imp__sub_82678360) {
	PPC_FUNC_PROLOGUE();
	// b 0x82630318
	sub_82630318(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82678364"))) PPC_WEAK_FUNC(sub_82678364);
PPC_FUNC_IMPL(__imp__sub_82678364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82678368"))) PPC_WEAK_FUNC(sub_82678368);
PPC_FUNC_IMPL(__imp__sub_82678368) {
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
	ctx.lr = 0x82678370;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// lhz r11,1218(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1218);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82678394
	if (cr6.eq) goto loc_82678394;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82678394;
	sub_82130588(ctx, base);
loc_82678394:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267839C;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826783A4;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826783bc
	if (cr6.eq) goto loc_826783BC;
	// bl 0x82130588
	ctx.lr = 0x826783B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826783BC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826783C4"))) PPC_WEAK_FUNC(sub_826783C4);
PPC_FUNC_IMPL(__imp__sub_826783C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826783C8"))) PPC_WEAK_FUNC(sub_826783C8);
PPC_FUNC_IMPL(__imp__sub_826783C8) {
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
	ctx.lr = 0x826783D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,-24932
	ctx.r5.s64 = r11.s64 + -24932;
	// addi r4,r10,-24940
	ctx.r4.s64 = ctx.r10.s64 + -24940;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x826783FC;
	sub_8228F920(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r3,208
	ctx.r3.s64 = 208;
	// addi r8,r9,-25740
	ctx.r8.s64 = ctx.r9.s64 + -25740;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x82130528
	ctx.lr = 0x82678410;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678430
	if (cr6.eq) goto loc_82678430;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25756
	ctx.r4.s64 = r11.s64 + -25756;
	// bl 0x82633d40
	ctx.lr = 0x82678428;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82678434
	goto loc_82678434;
loc_82678430:
	// li r11,0
	r11.s64 = 0;
loc_82678434:
	// stw r11,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r11.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82678440;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678460
	if (cr6.eq) goto loc_82678460;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25768
	ctx.r4.s64 = r11.s64 + -25768;
	// bl 0x82633d40
	ctx.lr = 0x82678458;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82678464
	goto loc_82678464;
loc_82678460:
	// li r11,0
	r11.s64 = 0;
loc_82678464:
	// stw r11,948(r31)
	PPC_STORE_U32(r31.u32 + 948, r11.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82678470;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678490
	if (cr6.eq) goto loc_82678490;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25780
	ctx.r4.s64 = r11.s64 + -25780;
	// bl 0x82633d40
	ctx.lr = 0x82678488;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82678494
	goto loc_82678494;
loc_82678490:
	// li r11,0
	r11.s64 = 0;
loc_82678494:
	// stw r11,952(r31)
	PPC_STORE_U32(r31.u32 + 952, r11.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x826784A0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826784c0
	if (cr6.eq) goto loc_826784C0;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25792
	ctx.r4.s64 = r11.s64 + -25792;
	// bl 0x82633d40
	ctx.lr = 0x826784B8;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x826784c4
	goto loc_826784C4;
loc_826784C0:
	// li r11,0
	r11.s64 = 0;
loc_826784C4:
	// stw r11,956(r31)
	PPC_STORE_U32(r31.u32 + 956, r11.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826784D0;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r29,r11,5568
	r29.s64 = r11.s64 + 5568;
	// beq cr6,0x826784f8
	if (cr6.eq) goto loc_826784F8;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25796
	ctx.r4.s64 = r11.s64 + -25796;
	// bl 0x826311f8
	ctx.lr = 0x826784F4;
	sub_826311F8(ctx, base);
	// b 0x826784fc
	goto loc_826784FC;
loc_826784F8:
	// li r30,0
	r30.s64 = 0;
loc_826784FC:
	// stw r30,960(r31)
	PPC_STORE_U32(r31.u32 + 960, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678508;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82678528
	if (cr6.eq) goto loc_82678528;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25800
	ctx.r4.s64 = r11.s64 + -25800;
	// bl 0x826311f8
	ctx.lr = 0x82678524;
	sub_826311F8(ctx, base);
	// b 0x8267852c
	goto loc_8267852C;
loc_82678528:
	// li r30,0
	r30.s64 = 0;
loc_8267852C:
	// stw r30,964(r31)
	PPC_STORE_U32(r31.u32 + 964, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678538;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82678558
	if (cr6.eq) goto loc_82678558;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25804
	ctx.r4.s64 = r11.s64 + -25804;
	// bl 0x826311f8
	ctx.lr = 0x82678554;
	sub_826311F8(ctx, base);
	// b 0x8267855c
	goto loc_8267855C;
loc_82678558:
	// li r30,0
	r30.s64 = 0;
loc_8267855C:
	// stw r30,968(r31)
	PPC_STORE_U32(r31.u32 + 968, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678568;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82678588
	if (cr6.eq) goto loc_82678588;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25808
	ctx.r4.s64 = r11.s64 + -25808;
	// bl 0x826311f8
	ctx.lr = 0x82678584;
	sub_826311F8(ctx, base);
	// b 0x8267858c
	goto loc_8267858C;
loc_82678588:
	// li r30,0
	r30.s64 = 0;
loc_8267858C:
	// stw r30,972(r31)
	PPC_STORE_U32(r31.u32 + 972, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678598;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826785b8
	if (cr6.eq) goto loc_826785B8;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25820
	ctx.r4.s64 = r11.s64 + -25820;
	// bl 0x826311f8
	ctx.lr = 0x826785B4;
	sub_826311F8(ctx, base);
	// b 0x826785bc
	goto loc_826785BC;
loc_826785B8:
	// li r30,0
	r30.s64 = 0;
loc_826785BC:
	// stw r30,976(r31)
	PPC_STORE_U32(r31.u32 + 976, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826785C8;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826785e8
	if (cr6.eq) goto loc_826785E8;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25832
	ctx.r4.s64 = r11.s64 + -25832;
	// bl 0x826311f8
	ctx.lr = 0x826785E4;
	sub_826311F8(ctx, base);
	// b 0x826785ec
	goto loc_826785EC;
loc_826785E8:
	// li r30,0
	r30.s64 = 0;
loc_826785EC:
	// stw r30,980(r31)
	PPC_STORE_U32(r31.u32 + 980, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826785F8;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82678618
	if (cr6.eq) goto loc_82678618;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25844
	ctx.r4.s64 = r11.s64 + -25844;
	// bl 0x826311f8
	ctx.lr = 0x82678614;
	sub_826311F8(ctx, base);
	// b 0x8267861c
	goto loc_8267861C;
loc_82678618:
	// li r30,0
	r30.s64 = 0;
loc_8267861C:
	// stw r30,984(r31)
	PPC_STORE_U32(r31.u32 + 984, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678628;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8267864c
	if (cr6.eq) goto loc_8267864C;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25856
	ctx.r4.s64 = r11.s64 + -25856;
	// bl 0x826311f8
	ctx.lr = 0x82678644;
	sub_826311F8(ctx, base);
	// mr r11,r30
	r11.u64 = r30.u64;
	// b 0x82678650
	goto loc_82678650;
loc_8267864C:
	// li r11,0
	r11.s64 = 0;
loc_82678650:
	// stw r11,988(r31)
	PPC_STORE_U32(r31.u32 + 988, r11.u32);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// addi r11,r31,880
	r11.s64 = r31.s64 + 880;
	// lwz r5,944(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,944(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// addi r4,r6,30372
	ctx.r4.s64 = ctx.r6.s64 + 30372;
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,960(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 960);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,944(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,976(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// lwz r5,948(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 948);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r11,948(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 948);
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,964(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 964);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,948(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 948);
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 980);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lhz r10,852(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r11,848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r9,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r9.u16);
	// lwz r7,952(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// lwz r11,952(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// lhz r5,192(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r5,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r10,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r10.u16);
	// lwz r5,968(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 968);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,952(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,984(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 984);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lhz r10,852(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r11,848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// sth r9,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r9.u16);
	// lwz r7,956(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// lwz r11,956(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r5,192(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r8,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r8.u16);
	// lwz r5,972(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 972);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,956(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// sth r8,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r8.u16);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r5,988(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 988);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,30372(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 30372);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r6,884(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// rotlwi r10,r6,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r5.u16);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82678868"))) PPC_WEAK_FUNC(sub_82678868);
PPC_FUNC_IMPL(__imp__sub_82678868) {
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
	ctx.lr = 0x82678870;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82678894
	if (cr6.eq) goto loc_82678894;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82678894;
	sub_82130588(ctx, base);
loc_82678894:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8267889C;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826788A4;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826788bc
	if (cr6.eq) goto loc_826788BC;
	// bl 0x82130588
	ctx.lr = 0x826788B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826788BC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826788C4"))) PPC_WEAK_FUNC(sub_826788C4);
PPC_FUNC_IMPL(__imp__sub_826788C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826788C8"))) PPC_WEAK_FUNC(sub_826788C8);
PPC_FUNC_IMPL(__imp__sub_826788C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x826788D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r28,r11,3998
	r28.s64 = r11.s64 + 3998;
	// addi r4,r9,-24884
	ctx.r4.s64 = ctx.r9.s64 + -24884;
	// addi r8,r10,28644
	ctx.r8.s64 = ctx.r10.s64 + 28644;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82678904;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r26,0
	r26.s64 = 0;
	// addi r7,r8,-31140
	ctx.r7.s64 = ctx.r8.s64 + -31140;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r30,r31,1040
	r30.s64 = r31.s64 + 1040;
	// li r29,9
	r29.s64 = 9;
	// stw r26,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, r26.u32);
	// addi r27,r11,28084
	r27.s64 = r11.s64 + 28084;
loc_82678928:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82678938;
	sub_82633D40(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,240
	r30.s64 = r30.s64 + 240;
	// bge 0x82678928
	if (!cr0.lt) goto loc_82678928;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r31,3440
	ctx.r3.s64 = r31.s64 + 3440;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-24896
	ctx.r4.s64 = r11.s64 + -24896;
	// bl 0x82633d40
	ctx.lr = 0x8267895C;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r8,r10,27188
	ctx.r8.s64 = ctx.r10.s64 + 27188;
	// stw r9,3648(r31)
	PPC_STORE_U32(r31.u32 + 3648, ctx.r9.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,3440(r31)
	PPC_STORE_U32(r31.u32 + 3440, ctx.r8.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,496(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r26,3684(r31)
	PPC_STORE_U32(r31.u32 + 3684, r26.u32);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// stw r26,3688(r31)
	PPC_STORE_U32(r31.u32 + 3688, r26.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r5,3692(r31)
	PPC_STORE_U32(r31.u32 + 3692, ctx.r5.u32);
	// lfs f13,11360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,3664(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3664, temp.u32);
	// stfs f13,3668(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3668, temp.u32);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826789B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826789C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r5,-24916
	ctx.r5.s64 = ctx.r5.s64 + -24916;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213058
	ctx.lr = 0x826789E8;
	sub_82213058(ctx, base);
	// stw r3,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826789F8"))) PPC_WEAK_FUNC(sub_826789F8);
PPC_FUNC_IMPL(__imp__sub_826789F8) {
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
	// bl 0x82676a78
	ctx.lr = 0x82678A18;
	sub_82676A78(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82678a30
	if (cr6.eq) goto loc_82678A30;
	// bl 0x82130588
	ctx.lr = 0x82678A2C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82678A30:
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

__attribute__((alias("__imp__sub_82678A48"))) PPC_WEAK_FUNC(sub_82678A48);
PPC_FUNC_IMPL(__imp__sub_82678A48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r30,r11,3998
	r30.s64 = r11.s64 + 3998;
	// addi r4,r9,-24056
	ctx.r4.s64 = ctx.r9.s64 + -24056;
	// addi r8,r10,28644
	ctx.r8.s64 = ctx.r10.s64 + 28644;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82678A8C;
	sub_82654318(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// li r3,208
	ctx.r3.s64 = 208;
	// addi r5,r6,-24860
	ctx.r5.s64 = ctx.r6.s64 + -24860;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,11360(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stfs f0,1064(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1064, temp.u32);
	// stfs f13,1068(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1068, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x82678AB8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678ad4
	if (cr6.eq) goto loc_82678AD4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,11
	ctx.r5.s64 = 11;
	// bl 0x82633d40
	ctx.lr = 0x82678ACC;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82678ad8
	goto loc_82678AD8;
loc_82678AD4:
	// li r11,0
	r11.s64 = 0;
loc_82678AD8:
	// stw r11,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r11.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82678AE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678afc
	if (cr6.eq) goto loc_82678AFC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x82633d40
	ctx.lr = 0x82678AF8;
	sub_82633D40(ctx, base);
	// b 0x82678b00
	goto loc_82678B00;
loc_82678AFC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82678B00:
	// stw r3,1060(r31)
	PPC_STORE_U32(r31.u32 + 1060, ctx.r3.u32);
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,1056(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lwz r7,1060(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1060);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82678B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678B70;
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

__attribute__((alias("__imp__sub_82678B8C"))) PPC_WEAK_FUNC(sub_82678B8C);
PPC_FUNC_IMPL(__imp__sub_82678B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82678B90"))) PPC_WEAK_FUNC(sub_82678B90);
PPC_FUNC_IMPL(__imp__sub_82678B90) {
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
	ctx.lr = 0x82678B98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,62
	ctx.r4.s64 = 62;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 476);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653b30
	ctx.lr = 0x82678BBC;
	sub_82653B30(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82678BC0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678e08
	if (cr6.eq) goto loc_82678E08;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82678c00
	if (cr6.eq) goto loc_82678C00;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82678BEC:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82678bec
	if (!cr6.eq) goto loc_82678BEC;
loc_82678C00:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addi r4,r9,27976
	ctx.r4.s64 = ctx.r9.s64 + 27976;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r7.u16);
	// lwz r3,992(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82678C30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r29,0
	r29.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r27,1
	r27.s64 = 1;
	// li r10,25
	ctx.r10.s64 = 25;
	// stb r29,208(r8)
	PPC_STORE_U8(ctx.r8.u32 + 208, r29.u8);
	// addi r26,r9,32684
	r26.s64 = ctx.r9.s64 + 32684;
	// lwz r7,992(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// stb r29,209(r7)
	PPC_STORE_U8(ctx.r7.u32 + 209, r29.u8);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r27,212(r11)
	PPC_STORE_U32(r11.u32 + 212, r27.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r9,992(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r10,216(r9)
	PPC_STORE_U32(ctx.r9.u32 + 216, ctx.r10.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82137a08
	ctx.lr = 0x82678C98;
	sub_82137A08(ctx, base);
	// lwz r3,1032(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82678CB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r28,r31,1472
	r28.s64 = r31.s64 + 1472;
	// addi r3,r4,8988
	ctx.r3.s64 = ctx.r4.s64 + 8988;
	// bl 0x82221fd8
	ctx.lr = 0x82678CC0;
	sub_82221FD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// li r4,2
	ctx.r4.s64 = 2;
	// xori r6,r9,1
	ctx.r6.u64 = ctx.r9.u64 ^ 1;
	// bl 0x82137a08
	ctx.lr = 0x82678CE0;
	sub_82137A08(ctx, base);
	// lwz r3,1112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1112);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82678CF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r4,r6,25364
	ctx.r4.s64 = ctx.r6.s64 + 25364;
	// lwz r28,-10244(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + -10244);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82218310
	ctx.lr = 0x82678D10;
	sub_82218310(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r4,27964
	ctx.r4.s64 = ctx.r4.s64 + 27964;
	// bl 0x822183b0
	ctx.lr = 0x82678D24;
	sub_822183B0(ctx, base);
	// lwz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,27944
	ctx.r4.s64 = r11.s64 + 27944;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82678D40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r26,19
	r26.s64 = 19;
	// lwz r7,996(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,25328
	ctx.r4.s64 = ctx.r8.s64 + 25328;
	// stb r29,208(r7)
	PPC_STORE_U8(ctx.r7.u32 + 208, r29.u8);
	// lwz r6,996(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stb r29,209(r6)
	PPC_STORE_U8(ctx.r6.u32 + 209, r29.u8);
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stw r27,212(r5)
	PPC_STORE_U32(ctx.r5.u32 + 212, r27.u32);
	// lwz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stw r26,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, r26.u32);
	// lwz r8,996(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r6.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r28,-10244(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + -10244);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82218310
	ctx.lr = 0x82678D98;
	sub_82218310(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,27932
	ctx.r4.s64 = ctx.r4.s64 + 27932;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822183b0
	ctx.lr = 0x82678DAC;
	sub_822183B0(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r4,r3,27912
	ctx.r4.s64 = ctx.r3.s64 + 27912;
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678DC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1000(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stb r29,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, r29.u8);
	// lwz r8,1000(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stb r29,209(r8)
	PPC_STORE_U8(ctx.r8.u32 + 209, r29.u8);
	// lwz r7,1000(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stw r27,212(r7)
	PPC_STORE_U32(ctx.r7.u32 + 212, r27.u32);
	// lwz r6,1000(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stw r26,216(r6)
	PPC_STORE_U32(ctx.r6.u32 + 216, r26.u32);
	// lwz r5,1000(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r3.u16);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
loc_82678E08:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82678E10"))) PPC_WEAK_FUNC(sub_82678E10);
PPC_FUNC_IMPL(__imp__sub_82678E10) {
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
	ctx.lr = 0x82678E18;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x82678E24;
	sub_82653B30(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,8988
	ctx.r4.s64 = ctx.r9.s64 + 8988;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82678E4C;
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
	ctx.lr = 0x82678E60;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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
	// lwz r7,88(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// beq cr6,0x82678eb0
	if (cr6.eq) goto loc_82678EB0;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-24044
	ctx.r4.s64 = ctx.r10.s64 + -24044;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82678EA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_82678EB0:
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-29360
	ctx.r4.s64 = ctx.r10.s64 + -29360;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82678EC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82678EC8"))) PPC_WEAK_FUNC(sub_82678EC8);
PPC_FUNC_IMPL(__imp__sub_82678EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82678ED0;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x82678EDC;
	sub_82256058(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8267914c
	if (cr6.eq) goto loc_8267914C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,8988
	ctx.r4.s64 = ctx.r9.s64 + 8988;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82678F10;
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
	ctx.lr = 0x82678F24;
	sub_821FD7C0(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r11,-23772
	ctx.r4.s64 = r11.s64 + -23772;
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// stb r10,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r10.u8);
	// stw r10,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r10.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,3104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3104);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// lwz r31,308(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82679138
	if (cr6.gt) goto loc_82679138;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-28812
	r12.s64 = r12.s64 + -28812;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267904C;
	case 1:
		goto loc_82678F98;
	case 2:
		goto loc_82678FD4;
	case 3:
		goto loc_82679138;
	case 4:
		goto loc_82679010;
	case 5:
		goto loc_82679088;
	case 6:
		goto loc_82679138;
	case 7:
		goto loc_826790C4;
	case 8:
		goto loc_82679100;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-28596(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28596);
	// lwz r19,-28776(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28776);
	// lwz r19,-28716(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28716);
	// lwz r19,-28360(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28360);
	// lwz r19,-28656(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28656);
	// lwz r19,-28536(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28536);
	// lwz r19,-28360(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28360);
	// lwz r19,-28476(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28476);
	// lwz r19,-28416(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28416);
loc_82678F98:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678FB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82678fc8
	if (cr6.eq) goto loc_82678FC8;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23788
	ctx.r4.s64 = r11.s64 + -23788;
	// b 0x82679138
	goto loc_82679138;
loc_82678FC8:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23804
	ctx.r4.s64 = r11.s64 + -23804;
	// b 0x82679138
	goto loc_82679138;
loc_82678FD4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678FEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679004
	if (cr6.eq) goto loc_82679004;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23824
	ctx.r4.s64 = r11.s64 + -23824;
	// b 0x82679138
	goto loc_82679138;
loc_82679004:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23844
	ctx.r4.s64 = r11.s64 + -23844;
	// b 0x82679138
	goto loc_82679138;
loc_82679010:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679028;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679040
	if (cr6.eq) goto loc_82679040;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23864
	ctx.r4.s64 = r11.s64 + -23864;
	// b 0x82679138
	goto loc_82679138;
loc_82679040:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23884
	ctx.r4.s64 = r11.s64 + -23884;
	// b 0x82679138
	goto loc_82679138;
loc_8267904C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8267907c
	if (cr6.eq) goto loc_8267907C;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23904
	ctx.r4.s64 = r11.s64 + -23904;
	// b 0x82679138
	goto loc_82679138;
loc_8267907C:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23924
	ctx.r4.s64 = r11.s64 + -23924;
	// b 0x82679138
	goto loc_82679138;
loc_82679088:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826790A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826790b8
	if (cr6.eq) goto loc_826790B8;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23940
	ctx.r4.s64 = r11.s64 + -23940;
	// b 0x82679138
	goto loc_82679138;
loc_826790B8:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23956
	ctx.r4.s64 = r11.s64 + -23956;
	// b 0x82679138
	goto loc_82679138;
loc_826790C4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826790DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826790f4
	if (cr6.eq) goto loc_826790F4;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23972
	ctx.r4.s64 = r11.s64 + -23972;
	// b 0x82679138
	goto loc_82679138;
loc_826790F4:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23988
	ctx.r4.s64 = r11.s64 + -23988;
	// b 0x82679138
	goto loc_82679138;
loc_82679100:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679118;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679130
	if (cr6.eq) goto loc_82679130;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-24008
	ctx.r4.s64 = r11.s64 + -24008;
	// b 0x82679138
	goto loc_82679138;
loc_82679130:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-24028
	ctx.r4.s64 = r11.s64 + -24028;
loc_82679138:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267914C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267914C:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82679154"))) PPC_WEAK_FUNC(sub_82679154);
PPC_FUNC_IMPL(__imp__sub_82679154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679158"))) PPC_WEAK_FUNC(sub_82679158);
PPC_FUNC_IMPL(__imp__sub_82679158) {
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
	ctx.lr = 0x82679160;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826535f8
	ctx.lr = 0x8267916C;
	sub_826535F8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,8988
	ctx.r4.s64 = ctx.r9.s64 + 8988;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82679194;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821fd7c0
	ctx.lr = 0x826791A8;
	sub_821FD7C0(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// lwz r7,10248(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r11.u8);
	// stw r11,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r11.u32);
	// lwz r6,468(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// stw r7,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r7.u32);
	// lwz r31,324(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826791DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r5,2612
	r29.s64 = ctx.r5.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x826791F4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82679204;
	sub_825ED480(ctx, base);
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cntlzw r10,r4
	ctx.r10.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// addi r4,r11,620
	ctx.r4.s64 = r11.s64 + 620;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x82679228;
	sub_82722678(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82679230"))) PPC_WEAK_FUNC(sub_82679230);
PPC_FUNC_IMPL(__imp__sub_82679230) {
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
	ctx.lr = 0x82679238;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8267924C;
	sub_8238EC00(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r30,r10,-21500
	r30.s64 = ctx.r10.s64 + -21500;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r8,-11120
	ctx.r4.s64 = ctx.r8.s64 + -11120;
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r26,-24180(r9)
	r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24180);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x823db670
	ctx.lr = 0x82679278;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,10248(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 10248);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821fd7c0
	ctx.lr = 0x8267928C;
	sub_821FD7C0(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// lwz r11,324(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// li r31,0
	r31.s64 = 0;
	// lwz r7,10248(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 10248);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// addi r28,r11,92
	r28.s64 = r11.s64 + 92;
	// stb r31,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r31.u8);
	// stw r31,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r31.u32);
	// stw r7,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r7.u32);
	// bl 0x82256058
	ctx.lr = 0x826792B4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826792d4
	if (cr6.eq) goto loc_826792D4;
	// bl 0x82256058
	ctx.lr = 0x826792C0;
	sub_82256058(ctx, base);
	// addi r31,r3,8
	r31.s64 = ctx.r3.s64 + 8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826792d4
	if (cr6.eq) goto loc_826792D4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x826792d8
	goto loc_826792D8;
loc_826792D4:
	// li r11,-1
	r11.s64 = -1;
loc_826792D8:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,764
	ctx.r4.s64 = ctx.r9.s64 + 764;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r30,-10020(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82679300;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,340
	ctx.r3.s64 = r30.s64 + 340;
	// bl 0x826cac98
	ctx.lr = 0x8267930C;
	sub_826CAC98(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x82679408
	if (cr6.eq) goto loc_82679408;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823895f8
	ctx.lr = 0x82679328;
	sub_823895F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679408
	if (cr6.eq) goto loc_82679408;
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x82679408
	if (cr6.gt) goto loc_82679408;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// addi r11,r11,-8292
	r11.s64 = r11.s64 + -8292;
loc_82679350:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82679374
	if (cr6.eq) goto loc_82679374;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679350
	if (cr6.eq) goto loc_82679350;
loc_82679374:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679408
	if (cr6.eq) goto loc_82679408;
	// bl 0x82256058
	ctx.lr = 0x82679380;
	sub_82256058(ctx, base);
	// lbz r11,3774(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3774);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82679408
	if (!cr6.eq) goto loc_82679408;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,797(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 797);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82679408
	if (!cr6.eq) goto loc_82679408;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826793B0;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826793C4;
	sub_82270170(ctx, base);
	// bl 0x82272e38
	ctx.lr = 0x826793C8;
	sub_82272E38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82679408
	if (cr6.eq) goto loc_82679408;
	// lwz r11,496(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 496);
	// addi r3,r27,496
	ctx.r3.s64 = r27.s64 + 496;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826793EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r9,29196
	ctx.r4.s64 = ctx.r9.s64 + 29196;
	// addi r3,r27,256
	ctx.r3.s64 = r27.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82679400;
	sub_8262FFE0(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9240
	return;
loc_82679408:
	// lwz r11,3096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3096);
	// addi r3,r27,496
	ctx.r3.s64 = r27.s64 + 496;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// lwz r11,496(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 496);
	// bne cr6,0x8267942c
	if (!cr6.eq) goto loc_8267942C;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x8267943c
	goto loc_8267943C;
loc_8267942C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267943C:
	// bctrl 
	ctx.lr = 0x82679440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,27980
	ctx.r4.s64 = r11.s64 + 27980;
	// addi r3,r27,256
	ctx.r3.s64 = r27.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82679454;
	sub_8262FFE0(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8267945C"))) PPC_WEAK_FUNC(sub_8267945C);
PPC_FUNC_IMPL(__imp__sub_8267945C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679460"))) PPC_WEAK_FUNC(sub_82679460);
PPC_FUNC_IMPL(__imp__sub_82679460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// addi r11,r4,-55
	r11.s64 = ctx.r4.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82679620
	if (cr6.gt) goto loc_82679620;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-27496
	r12.s64 = r12.s64 + -27496;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82679604;
	case 1:
		goto loc_82679620;
	case 2:
		goto loc_82679604;
	case 3:
		goto loc_82679604;
	case 4:
		goto loc_82679620;
	case 5:
		goto loc_82679620;
	case 6:
		goto loc_82679620;
	case 7:
		goto loc_82679620;
	case 8:
		goto loc_826794BC;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-27132(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27132);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27132(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27132);
	// lwz r19,-27132(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27132);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27460(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27460);
loc_826794BC:
	// bl 0x82256058
	ctx.lr = 0x826794C0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82679604
	if (cr6.eq) goto loc_82679604;
	// bl 0x82256058
	ctx.lr = 0x826794CC;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82679604
	if (cr6.eq) goto loc_82679604;
	// bl 0x82256058
	ctx.lr = 0x826794DC;
	sub_82256058(ctx, base);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82679604
	if (cr6.eq) goto loc_82679604;
	// bl 0x82256058
	ctx.lr = 0x826794EC;
	sub_82256058(ctx, base);
	// lbz r11,3774(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3774);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82679604
	if (!cr6.eq) goto loc_82679604;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,797(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 797);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82679604
	if (!cr6.eq) goto loc_82679604;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267951C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82679530;
	sub_82270170(ctx, base);
	// bl 0x82272e38
	ctx.lr = 0x82679534;
	sub_82272E38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82679604
	if (cr6.eq) goto loc_82679604;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8267954C;
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
	ctx.lr = 0x82679564;
	sub_8220EEA8(ctx, base);
	// addi r31,r3,92
	r31.s64 = ctx.r3.s64 + 92;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823895f8
	ctx.lr = 0x82679578;
	sub_823895F8(ctx, base);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bgt cr6,0x8267960c
	if (cr6.gt) goto loc_8267960C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r11,-8292
	r11.s64 = r11.s64 + -8292;
loc_82679594:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826795b8
	if (cr6.eq) goto loc_826795B8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679594
	if (cr6.eq) goto loc_82679594;
loc_826795B8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8267960c
	if (cr6.eq) goto loc_8267960C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826795CC;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r4,r9,-23756
	ctx.r4.s64 = ctx.r9.s64 + -23756;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82691650
	ctx.lr = 0x826795F0;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82679604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82679604:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82679624
	goto loc_82679624;
loc_8267960C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82679618;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82679624
	goto loc_82679624;
loc_82679620:
	// bl 0x826537d0
	ctx.lr = 0x82679624;
	sub_826537D0(ctx, base);
loc_82679624:
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

__attribute__((alias("__imp__sub_8267963C"))) PPC_WEAK_FUNC(sub_8267963C);
PPC_FUNC_IMPL(__imp__sub_8267963C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679640"))) PPC_WEAK_FUNC(sub_82679640);
PPC_FUNC_IMPL(__imp__sub_82679640) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82653c88
	ctx.lr = 0x82679658;
	sub_82653C88(ctx, base);
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
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

__attribute__((alias("__imp__sub_82679678"))) PPC_WEAK_FUNC(sub_82679678);
PPC_FUNC_IMPL(__imp__sub_82679678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r3,9
	cr6.compare<uint32_t>(ctx.r3.u32, 9, xer);
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// bgt cr6,0x82679bc4
	if (cr6.gt) {
		// ERROR 82679BC4
		return;
	}
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-26976
	r12.s64 = r12.s64 + -26976;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		// ERROR: 0x82679BC4
		return;
	case 1:
		// ERROR: 0x82679BC4
		return;
	case 2:
		// ERROR: 0x82679BC4
		return;
	case 3:
		// ERROR: 0x82679BC4
		return;
	case 4:
		// ERROR: 0x82679BC4
		return;
	case 5:
		// ERROR: 0x82679BC4
		return;
	case 6:
		// ERROR: 0x82679854
		return;
	case 7:
		// ERROR: 0x82679BC4
		return;
	case 8:
		// ERROR: 0x8267984C
		return;
	case 9:
		// ERROR: 0x826796C8
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_826796A0"))) PPC_WEAK_FUNC(sub_826796A0);
PPC_FUNC_IMPL(__imp__sub_826796A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r19{};
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-26540(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26540);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-26548(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26548);
	// lwz r19,-26936(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26936);
	// cmplwi cr6,r4,29
	cr6.compare<uint32_t>(ctx.r4.u32, 29, xer);
	// bgt cr6,0x82679840
	if (cr6.gt) {
		sub_82679840(ctx, base);
		return;
	}
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-26904
	r12.s64 = r12.s64 + -26904;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		// ERROR: 0x82679760
		return;
	case 1:
		// ERROR: 0x82679760
		return;
	case 2:
		// ERROR: 0x82679770
		return;
	case 3:
		// ERROR: 0x82679770
		return;
	case 4:
		// ERROR: 0x82679800
		return;
	case 5:
		// ERROR: 0x82679800
		return;
	case 6:
		// ERROR: 0x82679800
		return;
	case 7:
		// ERROR: 0x82679800
		return;
	case 8:
		// ERROR: 0x82679800
		return;
	case 9:
		// ERROR: 0x82679800
		return;
	case 10:
		// ERROR: 0x82679800
		return;
	case 11:
		// ERROR: 0x82679800
		return;
	case 12:
		// ERROR: 0x82679810
		return;
	case 13:
		// ERROR: 0x82679810
		return;
	case 14:
		// ERROR: 0x82679810
		return;
	case 15:
		// ERROR: 0x82679810
		return;
	case 16:
		// ERROR: 0x82679810
		return;
	case 17:
		// ERROR: 0x82679810
		return;
	case 18:
		// ERROR: 0x82679810
		return;
	case 19:
		// ERROR: 0x82679810
		return;
	case 20:
		// ERROR: 0x82679820
		return;
	case 21:
		// ERROR: 0x82679830
		return;
	case 22:
		// ERROR: 0x82679780
		return;
	case 23:
		// ERROR: 0x82679790
		return;
	case 24:
		// ERROR: 0x826797A0
		return;
	case 25:
		// ERROR: 0x826797B0
		return;
	case 26:
		// ERROR: 0x826797C0
		return;
	case 27:
		// ERROR: 0x826797D0
		return;
	case 28:
		// ERROR: 0x826797E0
		return;
	case 29:
		// ERROR: 0x826797F0
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_826796E8"))) PPC_WEAK_FUNC(sub_826796E8);
PPC_FUNC_IMPL(__imp__sub_826796E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r19{};
	// lwz r19,-26784(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26784);
	// lwz r19,-26784(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26784);
	// lwz r19,-26768(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26768);
	// lwz r19,-26768(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26768);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26592(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26592);
	// lwz r19,-26576(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26576);
	// lwz r19,-26752(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26752);
	// lwz r19,-26736(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26736);
	// lwz r19,-26720(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26720);
	// lwz r19,-26704(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26704);
	// lwz r19,-26688(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26688);
	// lwz r19,-26672(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26672);
	// lwz r19,-26656(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26656);
	// lwz r19,-26640(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26640);
	// li r11,0
	r11.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82679770"))) PPC_WEAK_FUNC(sub_82679770);
PPC_FUNC_IMPL(__imp__sub_82679770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82679780"))) PPC_WEAK_FUNC(sub_82679780);
PPC_FUNC_IMPL(__imp__sub_82679780) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,128(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// blr 
	return;
}

