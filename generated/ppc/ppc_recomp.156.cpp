#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_8272C5D0) {
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
	// bl 0x82735348
	ctx.lr = 0x8272C5F0;
	sub_82735348(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c608
	if (cr6.eq) goto loc_8272C608;
	// bl 0x82130588
	ctx.lr = 0x8272C604;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8272C608:
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

PPC_WEAK_FUNC(sub_8272C5D0) {
	__imp__sub_8272C5D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272C620) {
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
	ctx.lr = 0x8272C628;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82735fb0
	ctx.lr = 0x8272C63C;
	sub_82735FB0(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r3,240
	ctx.r3.s64 = 240;
	// li r9,160
	ctx.r9.s64 = 160;
	// li r8,192
	ctx.r8.s64 = 192;
	// li r7,224
	ctx.r7.s64 = 224;
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,176
	ctx.r5.s64 = 176;
	// li r4,208
	ctx.r4.s64 = 208;
	// li r30,272
	r30.s64 = 272;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r10,-18532
	ctx.r10.s64 = ctx.r10.s64 + -18532;
	// li r29,5
	r29.s64 = 5;
	// stw r11,296(r31)
	PPC_STORE_U32(r31.u32 + 296, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stb r29,144(r31)
	PPC_STORE_U8(r31.u32 + 144, r29.u8);
	// stw r11,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r11.u32);
	// stw r11,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r11.u32);
	// stvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8272C620) {
	__imp__sub_8272C620(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272C6B0) {
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
	ctx.lr = 0x8272C6B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-18236
	ctx.r4.s64 = r11.s64 + -18236;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x823d90b0
	ctx.lr = 0x8272C6DC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c70c
	if (cr6.eq) goto loc_8272C70C;
	// li r3,304
	ctx.r3.s64 = 304;
	// bl 0x82130528
	ctx.lr = 0x8272C6EC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c834
	if (cr6.eq) goto loc_8272C834;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8272c620
	ctx.lr = 0x8272C704;
	sub_8272C620(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8272C70C:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-18248
	ctx.r4.s64 = r11.s64 + -18248;
	// bl 0x823d90b0
	ctx.lr = 0x8272C71C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c76c
	if (cr6.eq) goto loc_8272C76C;
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82130528
	ctx.lr = 0x8272C72C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272c834
	if (cr6.eq) goto loc_8272C834;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82735fb0
	ctx.lr = 0x8272C74C;
	sub_82735FB0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r9,r11,-19076
	ctx.r9.s64 = r11.s64 + -19076;
	// stb r10,144(r31)
	PPC_STORE_U8(r31.u32 + 144, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8272C76C:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-18260
	ctx.r4.s64 = r11.s64 + -18260;
	// bl 0x823d90b0
	ctx.lr = 0x8272C77C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c7ac
	if (cr6.eq) goto loc_8272C7AC;
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82130528
	ctx.lr = 0x8272C78C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c834
	if (cr6.eq) goto loc_8272C834;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82737910
	ctx.lr = 0x8272C7A4;
	sub_82737910(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8272C7AC:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-18268
	ctx.r4.s64 = r11.s64 + -18268;
	// bl 0x823d90b0
	ctx.lr = 0x8272C7BC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r3,160
	ctx.r3.s64 = 160;
	// beq cr6,0x8272c80c
	if (cr6.eq) goto loc_8272C80C;
	// bl 0x82130528
	ctx.lr = 0x8272C7CC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272c834
	if (cr6.eq) goto loc_8272C834;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82735fb0
	ctx.lr = 0x8272C7EC;
	sub_82735FB0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,12
	ctx.r10.s64 = 12;
	// addi r9,r11,-18804
	ctx.r9.s64 = r11.s64 + -18804;
	// stb r10,144(r31)
	PPC_STORE_U8(r31.u32 + 144, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8272C80C:
	// bl 0x82130528
	ctx.lr = 0x8272C810;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c834
	if (cr6.eq) goto loc_8272C834;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82735fb0
	ctx.lr = 0x8272C82C;
	sub_82735FB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8272C834:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272C6B0) {
	__imp__sub_8272C6B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272C840) {
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
	// bl 0x82732ad8
	ctx.lr = 0x8272C858;
	sub_82732AD8(ctx, base);
	// lwz r31,20(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272c888
	if (cr6.eq) goto loc_8272C888;
loc_8272C864:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,168(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8272C87C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8272c864
	if (!cr6.eq) goto loc_8272C864;
loc_8272C888:
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

PPC_WEAK_FUNC(sub_8272C840) {
	__imp__sub_8272C840(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272C89C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272C89C) {
	__imp__sub_8272C89C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272C8A0) {
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
	ctx.lr = 0x8272C8A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r11,-19112
	ctx.r9.s64 = r11.s64 + -19112;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8272c934
	if (cr6.eq) goto loc_8272C934;
	// addi r31,r29,20
	r31.s64 = r29.s64 + 20;
loc_8272C8D0:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8272c920
	if (cr6.eq) goto loc_8272C920;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne cr6,0x8272c8f0
	if (!cr6.eq) goto loc_8272C8F0;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_8272C8F0:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c904
	if (cr6.eq) goto loc_8272C904;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8272C904:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c918
	if (cr6.eq) goto loc_8272C918;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8272C918:
	// stw r30,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r30.u32);
	// stw r30,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r30.u32);
loc_8272C920:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8272a810
	ctx.lr = 0x8272C928;
	sub_8272A810(ctx, base);
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8272c8d0
	if (!cr6.eq) goto loc_8272C8D0;
loc_8272C934:
	// lbz r11,44(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 44);
	// addi r31,r29,28
	r31.s64 = r29.s64 + 28;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c94c
	if (cr6.eq) goto loc_8272C94C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8272C94C;
	sub_82130588(ctx, base);
loc_8272C94C:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// bl 0x82733160
	ctx.lr = 0x8272C968;
	sub_82733160(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8272C8A0) {
	__imp__sub_8272C8A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272C970) {
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
	// bl 0x8272c8a0
	ctx.lr = 0x8272C990;
	sub_8272C8A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c9a8
	if (cr6.eq) goto loc_8272C9A8;
	// bl 0x82130588
	ctx.lr = 0x8272C9A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8272C9A8:
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

PPC_WEAK_FUNC(sub_8272C970) {
	__imp__sub_8272C970(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272C9C0) {
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
	ctx.lr = 0x8272C9C8;
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
	// li r31,0
	r31.s64 = 0;
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
loc_8272C9E0:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272ca08
	if (cr6.eq) goto loc_8272CA08;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r31,20
	cr6.compare<int32_t>(r31.s32, 20, xer);
	// blt cr6,0x8272c9e0
	if (cr6.lt) goto loc_8272C9E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8272CA08:
	// lwz r11,88(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// li r3,48
	ctx.r3.s64 = 48;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,88(r30)
	PPC_STORE_U32(r30.u32 + 88, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8272CA1C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272ca44
	if (cr6.eq) goto loc_8272CA44;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8272c528
	ctx.lr = 0x8272CA30;
	sub_8272C528(ctx, base);
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8272CA44:
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272C9C0) {
	__imp__sub_8272C9C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272CA5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272CA5C) {
	__imp__sub_8272CA5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272CA60) {
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
	ctx.lr = 0x8272CA68;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// clrlwi r26,r31,24
	r26.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x8272ca84
	if (!cr6.eq) goto loc_8272CA84;
	// bl 0x82130000
	ctx.lr = 0x8272CA84;
	sub_82130000(ctx, base);
loc_8272CA84:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stb r31,92(r25)
	PPC_STORE_U8(r25.u32 + 92, r31.u8);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// addi r27,r11,30576
	r27.s64 = r11.s64 + 30576;
	// beq cr6,0x8272cad0
	if (cr6.eq) goto loc_8272CAD0;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r11,-18220
	ctx.r4.s64 = r11.s64 + -18220;
	// bl 0x821ca540
	ctx.lr = 0x8272CAA8;
	sub_821CA540(ctx, base);
	// bl 0x8272c440
	ctx.lr = 0x8272CAAC;
	sub_8272C440(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-23464(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23464);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8272CAC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272CAD0;
	sub_821C9A90(ctx, base);
loc_8272CAD0:
	// bl 0x824a59c8
	ctx.lr = 0x8272CAD4;
	sub_824A59C8(ctx, base);
	// bl 0x824d0a60
	ctx.lr = 0x8272CAD8;
	sub_824D0A60(ctx, base);
	// bl 0x824d0990
	ctx.lr = 0x8272CADC;
	sub_824D0990(ctx, base);
	// bl 0x824d07c8
	ctx.lr = 0x8272CAE0;
	sub_824D07C8(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r11,-18228
	r30.s64 = r11.s64 + -18228;
	// addi r5,r10,20312
	ctx.r5.s64 = ctx.r10.s64 + 20312;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-27428(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -27428);
	// bl 0x8272b9b8
	ctx.lr = 0x8272CB00;
	sub_8272B9B8(ctx, base);
	// li r3,108
	ctx.r3.s64 = 108;
	// lwz r29,-27428(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x8272CB0C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272cb20
	if (cr6.eq) goto loc_8272CB20;
	// bl 0x8275d550
	ctx.lr = 0x8272CB18;
	sub_8275D550(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8272cb24
	goto loc_8272CB24;
loc_8272CB20:
	// li r31,0
	r31.s64 = 0;
loc_8272CB24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272b068
	ctx.lr = 0x8272CB2C;
	sub_8272B068(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,20344
	ctx.r5.s64 = r11.s64 + 20344;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82490a08
	ctx.lr = 0x8272CB44;
	sub_82490A08(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cb64
	if (cr6.eq) goto loc_8272CB64;
	// bl 0x821bbea8
	ctx.lr = 0x8272CB64;
	sub_821BBEA8(ctx, base);
loc_8272CB64:
	// bl 0x824906d8
	ctx.lr = 0x8272CB68;
	sub_824906D8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272cb74
	if (cr6.eq) goto loc_8272CB74;
	// bl 0x821bbf00
	ctx.lr = 0x8272CB74;
	sub_821BBF00(ctx, base);
loc_8272CB74:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cb90
	if (cr6.eq) goto loc_8272CB90;
	// bl 0x821bbea8
	ctx.lr = 0x8272CB90;
	sub_821BBEA8(ctx, base);
loc_8272CB90:
	// bl 0x824d6890
	ctx.lr = 0x8272CB94;
	sub_824D6890(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272cba0
	if (cr6.eq) goto loc_8272CBA0;
	// bl 0x821bbf00
	ctx.lr = 0x8272CBA0;
	sub_821BBF00(ctx, base);
loc_8272CBA0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cbbc
	if (cr6.eq) goto loc_8272CBBC;
	// bl 0x821bbea8
	ctx.lr = 0x8272CBBC;
	sub_821BBEA8(ctx, base);
loc_8272CBBC:
	// bl 0x824a3f80
	ctx.lr = 0x8272CBC0;
	sub_824A3F80(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272cbcc
	if (cr6.eq) goto loc_8272CBCC;
	// bl 0x821bbf00
	ctx.lr = 0x8272CBCC;
	sub_821BBF00(ctx, base);
loc_8272CBCC:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cbe8
	if (cr6.eq) goto loc_8272CBE8;
	// bl 0x821bbea8
	ctx.lr = 0x8272CBE8;
	sub_821BBEA8(ctx, base);
loc_8272CBE8:
	// bl 0x8275d788
	ctx.lr = 0x8272CBEC;
	sub_8275D788(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272cbf8
	if (cr6.eq) goto loc_8272CBF8;
	// bl 0x821bbf00
	ctx.lr = 0x8272CBF8;
	sub_821BBF00(ctx, base);
loc_8272CBF8:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cc14
	if (cr6.eq) goto loc_8272CC14;
	// bl 0x821bbea8
	ctx.lr = 0x8272CC14;
	sub_821BBEA8(ctx, base);
loc_8272CC14:
	// bl 0x8275d588
	ctx.lr = 0x8272CC18;
	sub_8275D588(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272cc24
	if (cr6.eq) goto loc_8272CC24;
	// bl 0x821bbf00
	ctx.lr = 0x8272CC24;
	sub_821BBF00(ctx, base);
loc_8272CC24:
	// bl 0x82737260
	ctx.lr = 0x8272CC28;
	sub_82737260(ctx, base);
	// li r3,132
	ctx.r3.s64 = 132;
	// lwz r29,-27428(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x8272CC34;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272cc48
	if (cr6.eq) goto loc_8272CC48;
	// bl 0x82737458
	ctx.lr = 0x8272CC40;
	sub_82737458(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8272cc4c
	goto loc_8272CC4C;
loc_8272CC48:
	// li r30,0
	r30.s64 = 0;
loc_8272CC4C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8272b140
	ctx.lr = 0x8272CC54;
	sub_8272B140(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r11,20600
	ctx.r4.s64 = r11.s64 + 20600;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// bl 0x82490a08
	ctx.lr = 0x8272CC6C;
	sub_82490A08(ctx, base);
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cc88
	if (cr6.eq) goto loc_8272CC88;
	// bl 0x821bbea8
	ctx.lr = 0x8272CC88;
	sub_821BBEA8(ctx, base);
loc_8272CC88:
	// bl 0x8275dcc8
	ctx.lr = 0x8272CC8C;
	sub_8275DCC8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272cc98
	if (cr6.eq) goto loc_8272CC98;
	// bl 0x821bbf00
	ctx.lr = 0x8272CC98;
	sub_821BBF00(ctx, base);
loc_8272CC98:
	// bl 0x82729b10
	ctx.lr = 0x8272CC9C;
	sub_82729B10(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r9,r10,-21996
	ctx.r9.s64 = ctx.r10.s64 + -21996;
	// addi r4,r11,1952
	ctx.r4.s64 = r11.s64 + 1952;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272ccbc
	if (cr6.eq) goto loc_8272CCBC;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_8272CCBC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ca540
	ctx.lr = 0x8272CCC4;
	sub_821CA540(ctx, base);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r3,19684(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 19684);
	// bl 0x8275dfd0
	ctx.lr = 0x8272CCD0;
	sub_8275DFD0(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272CCD8;
	sub_821C9A90(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r9,r10,-21956
	ctx.r9.s64 = ctx.r10.s64 + -21956;
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cd00
	if (cr6.eq) goto loc_8272CD00;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// b 0x8272cd04
	goto loc_8272CD04;
loc_8272CD00:
	// li r11,0
	r11.s64 = 0;
loc_8272CD04:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cd18
	if (cr6.eq) goto loc_8272CD18;
	// lwz r11,19684(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 19684);
	// stw r10,580(r11)
	PPC_STORE_U32(r11.u32 + 580, ctx.r10.u32);
loc_8272CD18:
	// lis r11,-32141
	r11.s64 = -2106392576;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r11,-30968
	ctx.r9.s64 = r11.s64 + -30968;
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,19620(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19620);
	// bl 0x821d4268
	ctx.lr = 0x8272CD40;
	sub_821D4268(ctx, base);
	// lis r8,-32184
	ctx.r8.s64 = -2109210624;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r8,-10648
	ctx.r6.s64 = ctx.r8.s64 + -10648;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// lwz r11,-4964(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4964);
	// addi r10,r11,596
	ctx.r10.s64 = r11.s64 + 596;
	// lwz r8,8(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// stw r8,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r8.u32);
	// stw r6,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r6.u32);
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r10,608(r11)
	PPC_STORE_U32(r11.u32 + 608, ctx.r10.u32);
	// stw r7,604(r11)
	PPC_STORE_U32(r11.u32 + 604, ctx.r7.u32);
	// stw r8,600(r11)
	PPC_STORE_U32(r11.u32 + 600, ctx.r8.u32);
	// stw r9,596(r11)
	PPC_STORE_U32(r11.u32 + 596, ctx.r9.u32);
	// bne cr6,0x8272cdf8
	if (!cr6.eq) goto loc_8272CDF8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17120);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r31,40(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// bl 0x82728ce0
	ctx.lr = 0x8272CDC0;
	sub_82728CE0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8272CDD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// lwz r10,19684(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 19684);
	// lwz r11,-10404(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10404);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8272cdf8
	if (!cr6.lt) goto loc_8272CDF8;
	// stfs f0,32(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
loc_8272CDF8:
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x8272CE00;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272ce10
	if (cr6.eq) goto loc_8272CE10;
	// bl 0x82728710
	ctx.lr = 0x8272CE0C;
	sub_82728710(ctx, base);
	// b 0x8272ce14
	goto loc_8272CE14;
loc_8272CE10:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8272CE14:
	// stw r3,108(r25)
	PPC_STORE_U32(r25.u32 + 108, ctx.r3.u32);
	// li r7,6
	ctx.r7.s64 = 6;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x827322e8
	ctx.lr = 0x8272CE2C;
	sub_827322E8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,13052
	ctx.r3.s64 = r11.s64 + 13052;
	// bl 0x8218a4e8
	ctx.lr = 0x8272CE3C;
	sub_8218A4E8(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stw r3,-22000(r10)
	PPC_STORE_U32(ctx.r10.u32 + -22000, ctx.r3.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8272CA60) {
	__imp__sub_8272CA60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272CE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272CE4C) {
	__imp__sub_8272CE4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272CE50) {
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
	ctx.lr = 0x8272CE58;
	// stwu r1,-912(r1)
	ea = -912 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
loc_8272CE6C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8272ce6c
	if (!cr6.eq) goto loc_8272CE6C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// li r29,0
	r29.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r10,-18088
	ctx.r4.s64 = ctx.r10.s64 + -18088;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// bl 0x821ca540
	ctx.lr = 0x8272CEA0;
	sub_821CA540(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r9,-18100
	ctx.r4.s64 = ctx.r9.s64 + -18100;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x823dc018
	ctx.lr = 0x8272CEB4;
	sub_823DC018(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r31,r11,-18104
	r31.s64 = r11.s64 + -18104;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821fdd50
	ctx.lr = 0x8272CED4;
	sub_821FDD50(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272CEDC;
	sub_821C9A90(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272cf98
	if (cr6.eq) goto loc_8272CF98;
	// bl 0x822d7720
	ctx.lr = 0x8272CEEC;
	sub_822D7720(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-18132
	ctx.r4.s64 = r11.s64 + -18132;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// bl 0x823dc018
	ctx.lr = 0x8272CF00;
	sub_823DC018(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,131
	ctx.r6.s64 = 131;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// bl 0x82729b80
	ctx.lr = 0x8272CF18;
	sub_82729B80(ctx, base);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8272cf30
	if (!cr6.eq) goto loc_8272CF30;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-18208
	ctx.r3.s64 = r11.s64 + -18208;
	// bl 0x821bd618
	ctx.lr = 0x8272CF30;
	sub_821BD618(ctx, base);
loc_8272CF30:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r11,r29
	r11.u64 = r29.u64;
	// lwz r3,-24880(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24880);
	// stw r11,-24880(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24880, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272cf6c
	if (cr6.eq) goto loc_8272CF6C;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x8272cf6c
	if (!cr0.eq) goto loc_8272CF6C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272CF6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272CF6C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-8892
	ctx.r10.s64 = r11.s64 + -8892;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272cf8c
	if (cr6.eq) goto loc_8272CF8C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82729c80
	ctx.lr = 0x8272CF8C;
	sub_82729C80(ctx, base);
loc_8272CF8C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82728f90
	ctx.lr = 0x8272CF94;
	sub_82728F90(ctx, base);
	// stw r29,260(r30)
	PPC_STORE_U32(r30.u32 + 260, r29.u32);
loc_8272CF98:
	// addi r1,r1,912
	ctx.r1.s64 = ctx.r1.s64 + 912;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272CE50) {
	__imp__sub_8272CE50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272CFA0) {
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
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8272c9c0
	ctx.lr = 0x8272CFCC;
	sub_8272C9C0(ctx, base);
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

PPC_WEAK_FUNC(sub_8272CFA0) {
	__imp__sub_8272CFA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272CFE8) {
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
	// lis r11,-32141
	r11.s64 = -2106392576;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,-12384
	ctx.r4.s64 = r11.s64 + -12384;
	// addi r3,r10,-17760
	ctx.r3.s64 = ctx.r10.s64 + -17760;
	// bl 0x82554798
	ctx.lr = 0x8272D008;
	sub_82554798(ctx, base);
	// lis r9,-32141
	ctx.r9.s64 = -2106392576;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,-15792
	ctx.r4.s64 = ctx.r9.s64 + -15792;
	// addi r3,r8,-17784
	ctx.r3.s64 = ctx.r8.s64 + -17784;
	// bl 0x82554798
	ctx.lr = 0x8272D01C;
	sub_82554798(ctx, base);
	// lis r7,-32141
	ctx.r7.s64 = -2106392576;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,-18384
	ctx.r4.s64 = ctx.r7.s64 + -18384;
	// addi r3,r6,-17812
	ctx.r3.s64 = ctx.r6.s64 + -17812;
	// bl 0x82554798
	ctx.lr = 0x8272D030;
	sub_82554798(ctx, base);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,-18296
	ctx.r4.s64 = ctx.r5.s64 + -18296;
	// addi r3,r3,-17840
	ctx.r3.s64 = ctx.r3.s64 + -17840;
	// bl 0x82554798
	ctx.lr = 0x8272D044;
	sub_82554798(ctx, base);
	// lis r11,-32141
	r11.s64 = -2106392576;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,-23328
	ctx.r4.s64 = r11.s64 + -23328;
	// addi r3,r10,-17868
	ctx.r3.s64 = ctx.r10.s64 + -17868;
	// bl 0x82554798
	ctx.lr = 0x8272D058;
	sub_82554798(ctx, base);
	// lis r9,-32141
	ctx.r9.s64 = -2106392576;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,-23240
	ctx.r4.s64 = ctx.r9.s64 + -23240;
	// addi r3,r8,-17896
	ctx.r3.s64 = ctx.r8.s64 + -17896;
	// bl 0x82554798
	ctx.lr = 0x8272D06C;
	sub_82554798(ctx, base);
	// lis r7,-32141
	ctx.r7.s64 = -2106392576;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,-23160
	ctx.r4.s64 = ctx.r7.s64 + -23160;
	// addi r3,r6,-17932
	ctx.r3.s64 = ctx.r6.s64 + -17932;
	// bl 0x82554798
	ctx.lr = 0x8272D080;
	sub_82554798(ctx, base);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,-23104
	ctx.r4.s64 = ctx.r5.s64 + -23104;
	// addi r3,r3,-17964
	ctx.r3.s64 = ctx.r3.s64 + -17964;
	// bl 0x82554798
	ctx.lr = 0x8272D094;
	sub_82554798(ctx, base);
	// lis r11,-32141
	r11.s64 = -2106392576;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,-23080
	ctx.r4.s64 = r11.s64 + -23080;
	// addi r3,r10,-18000
	ctx.r3.s64 = ctx.r10.s64 + -18000;
	// bl 0x82554798
	ctx.lr = 0x8272D0A8;
	sub_82554798(ctx, base);
	// lis r9,-32141
	ctx.r9.s64 = -2106392576;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,-21104
	ctx.r4.s64 = ctx.r9.s64 + -21104;
	// addi r3,r8,-18024
	ctx.r3.s64 = ctx.r8.s64 + -18024;
	// bl 0x82554798
	ctx.lr = 0x8272D0BC;
	sub_82554798(ctx, base);
	// lis r7,-32141
	ctx.r7.s64 = -2106392576;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,-21088
	ctx.r4.s64 = ctx.r7.s64 + -21088;
	// addi r3,r6,-18068
	ctx.r3.s64 = ctx.r6.s64 + -18068;
	// bl 0x82554798
	ctx.lr = 0x8272D0D0;
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

PPC_WEAK_FUNC(sub_8272CFE8) {
	__imp__sub_8272CFE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D0E0) {
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
	// li r11,0
	r11.s64 = 0;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stb r11,148(r31)
	PPC_STORE_U8(r31.u32 + 148, r11.u8);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// beq cr6,0x8272d130
	if (cr6.eq) goto loc_8272D130;
	// stw r11,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, r11.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272d130
	if (!cr6.eq) goto loc_8272D130;
	// bl 0x821f6c50
	ctx.lr = 0x8272D130;
	sub_821F6C50(ctx, base);
loc_8272D130:
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272d144
	if (cr6.eq) goto loc_8272D144;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8272D144;
	sub_8213C218(ctx, base);
loc_8272D144:
	// lwz r3,140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272d158
	if (cr6.eq) goto loc_8272D158;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8272D158;
	sub_8213C218(ctx, base);
loc_8272D158:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272d16c
	if (cr6.eq) goto loc_8272D16C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x8272D16C;
	sub_8213C218(ctx, base);
loc_8272D16C:
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

PPC_WEAK_FUNC(sub_8272D0E0) {
	__imp__sub_8272D0E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D180) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, r11.u32);
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8272D180) {
	__imp__sub_8272D180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D190) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,112(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f12,104(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x8272d2bc
	if (cr6.lt) goto loc_8272D2BC;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// lbz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8272d2bc
	if (!cr6.lt) goto loc_8272D2BC;
	// fctiwz f0,f2
	f0.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// li r31,0
	r31.s64 = 0;
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// li r7,255
	ctx.r7.s64 = 255;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// lfs f0,-17424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -17424);
	f0.f64 = double(temp.f32);
	// addi r6,r30,64
	ctx.r6.s64 = r30.s64 + 64;
	// li r5,36
	ctx.r5.s64 = 36;
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r31.u32);
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// stw r9,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// stw r8,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r8.u32);
	// stb r7,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r7.u8);
	// stb r31,165(r1)
	PPC_STORE_U8(ctx.r1.u32 + 165, r31.u8);
	// stw r6,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stb r5,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r5.u8);
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// stw r4,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r4.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// beq cr6,0x8272d27c
	if (cr6.eq) goto loc_8272D27C;
	// lbz r10,119(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272d27c
	if (cr6.eq) goto loc_8272D27C;
	// lbz r11,62(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r5,r11,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272D27C;
	sub_821F7208(ctx, base);
loc_8272D27C:
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,81(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 81);
	// bl 0x82548fd0
	ctx.lr = 0x8272D298;
	sub_82548FD0(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272d2b4
	if (cr6.eq) goto loc_8272D2B4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c0c0
	ctx.lr = 0x8272D2B4;
	sub_8213C0C0(ctx, base);
loc_8272D2B4:
	// lfs f0,104(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 104);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 112, temp.u32);
loc_8272D2BC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8272D190) {
	__imp__sub_8272D190(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272D2D4) {
	__imp__sub_8272D2D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D2D8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r30,r11,-21904
	r30.s64 = r11.s64 + -21904;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_8272D2F8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272d318
	if (cr6.eq) goto loc_8272D318;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272D318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272D318:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,256
	r11.s64 = r30.s64 + 256;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8272d2f8
	if (cr6.lt) goto loc_8272D2F8;
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

PPC_WEAK_FUNC(sub_8272D2D8) {
	__imp__sub_8272D2D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,96(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// lwz r10,96(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8272d360
	if (!cr6.gt) goto loc_8272D360;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8272D360:
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

PPC_WEAK_FUNC(sub_8272D340) {
	__imp__sub_8272D340(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272D36C) {
	__imp__sub_8272D36C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21912(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21912);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8272d3c4
	if (cr6.eq) goto loc_8272D3C4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,63
	ctx.r9.s64 = 63;
	// addi r7,r11,-21904
	ctx.r7.s64 = r11.s64 + -21904;
loc_8272D390:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r10,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// lwz r10,96(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 96);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// ble cr6,0x8272d3b4
	if (!cr6.gt) goto loc_8272D3B4;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x8272d3bc
	goto loc_8272D3BC;
loc_8272D3B4:
	// bge cr6,0x8272d3cc
	if (!cr6.lt) goto loc_8272D3CC;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_8272D3BC:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x8272d390
	if (!cr6.gt) goto loc_8272D390;
loc_8272D3C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8272D3CC:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r7
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8272D370) {
	__imp__sub_8272D370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D3D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r5,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r5.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272D408;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lbz r8,62(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 62);
	// rlwinm r7,r8,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8272d438
	if (cr6.eq) goto loc_8272D438;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272d438
	if (cr6.eq) goto loc_8272D438;
	// lhz r11,32(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x8272d440
	goto loc_8272D440;
loc_8272D438:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
loc_8272D440:
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
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
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8272d4bc
	if (cr6.eq) goto loc_8272D4BC;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stw r10,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r10.u32);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r6,69(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 69);
	// lwz r7,77(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 77);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lwz r8,73(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 73);
	// stfs f0,88(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 88, temp.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,84(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
loc_8272D4BC:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// lfs f13,-31068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31068);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f13,112(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f13,116(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
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

PPC_WEAK_FUNC(sub_8272D3D8) {
	__imp__sub_8272D3D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lfs f13,104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,104(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,232(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 232);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8272D540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,100(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lbz r6,62(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 62);
	// rlwinm r5,r6,0,27,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8272d570
	if (cr6.eq) goto loc_8272D570;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272d570
	if (cr6.eq) goto loc_8272D570;
	// lhz r11,32(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x8272d578
	goto loc_8272D578;
loc_8272D570:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
loc_8272D578:
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
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
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272d5d8
	if (cr6.eq) goto loc_8272D5D8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,104(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x8272d5d8
	if (cr6.lt) goto loc_8272D5D8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x8272D5D8;
	sub_8213C218(ctx, base);
loc_8272D5D8:
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

PPC_WEAK_FUNC(sub_8272D500) {
	__imp__sub_8272D500(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272D5EC) {
	__imp__sub_8272D5EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D5F0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8272D5F8;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fsqrts f13,f1
	ctx.f13.f64 = double(float(sqrt(ctx.f1.f64)));
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r6,100(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// lwz r8,94(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 94);
	// lwz r5,106(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 106);
	// lwz r4,112(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	// lhz r10,98(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 98);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lhz r9,110(r7)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r7.u32 + 110);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// lhz r11,116(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 116);
	// extsw r10,r6
	ctx.r10.s64 = ctx.r6.s32;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lhz r5,104(r7)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + 104);
	// lbz r7,119(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfd f1,96(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// subf r9,r6,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r6.s64;
	// subf r6,r4,r11
	ctx.r6.s64 = r11.s64 - ctx.r4.s64;
	// extsw r5,r9
	ctx.r5.s64 = ctx.r9.s32;
	// extsw r11,r6
	r11.s64 = ctx.r6.s32;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f3,88(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f2,80(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fsubs f7,f12,f9
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f9.f64));
	// fsubs f6,f13,f11
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fsubs f5,f10,f11
	ctx.f5.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fcfid f10,f4
	ctx.f10.f64 = double(ctx.f4.s64);
	// fcfid f9,f3
	ctx.f9.f64 = double(ctx.f3.s64);
	// fcfid f13,f1
	ctx.f13.f64 = double(ctx.f1.s64);
	// fdivs f12,f8,f7
	ctx.f12.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// fcfid f8,f2
	ctx.f8.f64 = double(ctx.f2.s64);
	// fdivs f11,f6,f5
	ctx.f11.f64 = double(float(ctx.f6.f64 / ctx.f5.f64));
	// frsp f2,f10
	ctx.f2.f64 = double(float(ctx.f10.f64));
	// frsp f1,f9
	ctx.f1.f64 = double(float(ctx.f9.f64));
	// frsp f7,f13
	ctx.f7.f64 = double(float(ctx.f13.f64));
	// fsel f6,f12,f12,f31
	ctx.f6.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f31.f64;
	// fsel f4,f12,f12,f31
	ctx.f4.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f31.f64;
	// fsel f5,f11,f11,f31
	ctx.f5.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f31.f64;
	// fsel f3,f11,f11,f31
	ctx.f3.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f31.f64;
	// frsp f13,f8
	ctx.f13.f64 = double(float(ctx.f8.f64));
	// fsubs f12,f6,f0
	ctx.f12.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsubs f11,f5,f0
	ctx.f11.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsel f10,f12,f0,f4
	ctx.f10.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f4.f64;
	// fsel f9,f11,f0,f3
	ctx.f9.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f3.f64;
	// fsubs f8,f0,f10
	ctx.f8.f64 = double(float(f0.f64 - ctx.f10.f64));
	// fsubs f6,f0,f9
	ctx.f6.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fmadds f5,f8,f2,f7
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f2.f64 + ctx.f7.f64));
	// fmadds f4,f6,f1,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f13.f64));
	// fctidz f3,f5
	ctx.f3.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f3.u64);
	// lhz r28,102(r1)
	r28.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// fctidz f2,f4
	ctx.f2.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f2,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f2.u64);
	// lhz r26,94(r1)
	r26.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// beq cr6,0x8272d744
	if (cr6.eq) goto loc_8272D744;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f7208
	ctx.lr = 0x8272D744;
	sub_821F7208(ctx, base);
loc_8272D744:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272d898
	if (!cr6.eq) goto loc_8272D898;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// li r4,255
	ctx.r4.s64 = 255;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// li r25,36
	r25.s64 = 36;
	// stw r30,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r30.u32);
	// lfs f0,-17424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	f0.f64 = double(temp.f32);
	// stw r30,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r30.u32);
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r30,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r30.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stw r9,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r9.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r7,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// stw r30,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r30.u32);
	// stb r4,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r4.u8);
	// stb r30,181(r1)
	PPC_STORE_U8(ctx.r1.u32 + 181, r30.u8);
	// stb r25,182(r1)
	PPC_STORE_U8(ctx.r1.u32 + 182, r25.u8);
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r4,86(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 86);
	// bl 0x82549078
	ctx.lr = 0x8272D7DC;
	sub_82549078(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272d928
	if (cr6.eq) goto loc_8272D928;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// beq cr6,0x8272d820
	if (cr6.eq) goto loc_8272D820;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272d824
	goto loc_8272D824;
loc_8272D820:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8272D824:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82148f40
	ctx.lr = 0x8272D82C;
	sub_82148F40(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8272d860
	if (cr6.eq) goto loc_8272D860;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272d864
	goto loc_8272D864;
loc_8272D860:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8272D864:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82148f18
	ctx.lr = 0x8272D86C;
	sub_82148F18(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8213b860
	ctx.lr = 0x8272D878;
	sub_8213B860(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c0c0
	ctx.lr = 0x8272D88C;
	sub_8213C0C0(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_8272D898:
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// addi r31,r9,7216
	r31.s64 = ctx.r9.s64 + 7216;
	// beq cr6,0x8272d8d0
	if (cr6.eq) goto loc_8272D8D0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272d8d4
	goto loc_8272D8D4;
loc_8272D8D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8272D8D4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82148f40
	ctx.lr = 0x8272D8DC;
	sub_82148F40(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8272d910
	if (cr6.eq) goto loc_8272D910;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,11444(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272d914
	goto loc_8272D914;
loc_8272D910:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8272D914:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82148f18
	ctx.lr = 0x8272D91C;
	sub_82148F18(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8213b860
	ctx.lr = 0x8272D928;
	sub_8213B860(ctx, base);
loc_8272D928:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8272D5F0) {
	__imp__sub_8272D5F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272D934) {
	__imp__sub_8272D934(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272D938) {
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
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8248a510
	ctx.lr = 0x8272D95C;
	sub_8248A510(ctx, base);
	// lbz r11,303(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 303);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8272d974
	if (cr6.lt) goto loc_8272D974;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r3,r11,119
	ctx.r3.s64 = r11.s64 + 119;
	// b 0x8272d9fc
	goto loc_8272D9FC;
loc_8272D974:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8248a510
	ctx.lr = 0x8272D97C;
	sub_8248A510(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,212(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r30,12(r8)
	r30.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12);
	// bl 0x8248a510
	ctx.lr = 0x8272D998;
	sub_8248A510(ctx, base);
	// lwz r7,208(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// rotlwi r6,r30,2
	ctx.r6.u64 = __builtin_rotateleft32(r30.u32, 2);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r11,r6,r7
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// addi r3,r11,84
	ctx.r3.s64 = r11.s64 + 84;
	// bl 0x821c9790
	ctx.lr = 0x8272D9B0;
	sub_821C9790(ctx, base);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r7,118(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 118);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8272d9f8
	if (cr6.eq) goto loc_8272D9F8;
	// li r11,0
	r11.s64 = 0;
loc_8272D9C8:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r5,119(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 119);
	// cmplw cr6,r3,r5
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, xer);
	// beq cr6,0x8272da14
	if (cr6.eq) goto loc_8272DA14;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// blt cr6,0x8272d9c8
	if (cr6.lt) goto loc_8272D9C8;
loc_8272D9F8:
	// addi r3,r9,119
	ctx.r3.s64 = ctx.r9.s64 + 119;
loc_8272D9FC:
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
loc_8272DA14:
	// rlwinm r11,r10,1,23,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FE;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r3,r11,119
	ctx.r3.s64 = r11.s64 + 119;
	// b 0x8272d9fc
	goto loc_8272D9FC;
}

PPC_WEAK_FUNC(sub_8272D938) {
	__imp__sub_8272D938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DA30) {
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
	ctx.lr = 0x8272DA38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-13560
	ctx.r10.s64 = r11.s64 + -13560;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272dae0
	if (!cr6.eq) goto loc_8272DAE0;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r30,0
	r30.s64 = 0;
	// addi r27,r11,-21904
	r27.s64 = r11.s64 + -21904;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r29,r27
	r29.u64 = r27.u64;
	// addi r28,r11,-17376
	r28.s64 = r11.s64 + -17376;
loc_8272DA68:
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x8272DA70;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272dab0
	if (cr6.eq) goto loc_8272DAB0;
	// bl 0x8271e4c8
	ctx.lr = 0x8272DA80;
	sub_8271E4C8(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// bl 0x82548ba8
	ctx.lr = 0x8272DA9C;
	sub_82548BA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8271e618
	ctx.lr = 0x8272DAA4;
	sub_8271E618(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272d0e0
	ctx.lr = 0x8272DAAC;
	sub_8272D0E0(ctx, base);
	// b 0x8272dab4
	goto loc_8272DAB4;
loc_8272DAB0:
	// mr r31,r30
	r31.u64 = r30.u64;
loc_8272DAB4:
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r11,r27,256
	r11.s64 = r27.s64 + 256;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8272da68
	if (cr6.lt) goto loc_8272DA68;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r6,r11,-11456
	ctx.r6.s64 = r11.s64 + -11456;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x823dcf08
	ctx.lr = 0x8272DAE0;
	sub_823DCF08(ctx, base);
loc_8272DAE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8272DA30) {
	__imp__sub_8272DA30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DAE8) {
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
	// bl 0x8272d370
	ctx.lr = 0x8272DAF8;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272db14
	if (cr6.eq) goto loc_8272DB14;
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272db14
	if (cr6.eq) goto loc_8272DB14;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x8272DB14;
	sub_8213C218(ctx, base);
loc_8272DB14:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8272DAE8) {
	__imp__sub_8272DAE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272DB24) {
	__imp__sub_8272DB24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DB28) {
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
	// bl 0x8272d370
	ctx.lr = 0x8272DB38;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272db70
	if (cr6.eq) goto loc_8272DB70;
	// bl 0x8272d0e0
	ctx.lr = 0x8272DB44;
	sub_8272D0E0(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32141
	ctx.r9.s64 = -2106392576;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// addi r6,r9,-11456
	ctx.r6.s64 = ctx.r9.s64 + -11456;
	// addi r3,r8,-21904
	ctx.r3.s64 = ctx.r8.s64 + -21904;
	// lwz r11,-21912(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21912);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,-21912(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21912, r11.u32);
	// bl 0x823dcf08
	ctx.lr = 0x8272DB70;
	sub_823DCF08(ctx, base);
loc_8272DB70:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8272DB28) {
	__imp__sub_8272DB28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DB80) {
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
	ctx.lr = 0x8272DB88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r11,-21624(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21624);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8272dbd8
	if (!cr6.eq) goto loc_8272DBD8;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r11,-21624(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21624, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,-16732
	ctx.r3.s64 = ctx.r9.s64 + -16732;
	// bl 0x821c9790
	ctx.lr = 0x8272DBC8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a28
	ctx.lr = 0x8272DBD4;
	sub_82144A28(ctx, base);
	// stw r3,-21628(r30)
	PPC_STORE_U32(r30.u32 + -21628, ctx.r3.u32);
loc_8272DBD8:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8272dbf0
	if (!cr6.eq) goto loc_8272DBF0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8272DBF0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x821c9790
	ctx.lr = 0x8272DBFC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a28
	ctx.lr = 0x8272DC08;
	sub_82144A28(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272dc14
	if (!cr6.eq) goto loc_8272DC14;
	// lwz r3,-21628(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -21628);
loc_8272DC14:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8272DB80) {
	__imp__sub_8272DB80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DC1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272DC1C) {
	__imp__sub_8272DC1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DC20) {
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
	ctx.lr = 0x8272DC28;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r29,0
	r29.s64 = 0;
	// addi r27,r11,-21904
	r27.s64 = r11.s64 + -21904;
	// lwz r11,-21912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -21912);
	// subfic r11,r11,64
	xer.ca = r11.u32 <= 64;
	r11.s64 = 64 - r11.s64;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bge cr6,0x8272dcd4
	if (!cr6.lt) goto loc_8272DCD4;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// add r30,r11,r27
	r30.u64 = r11.u64 + r27.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r28,r11,29952
	r28.s64 = r11.s64 + 29952;
	// lfs f31,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f31.f64 = double(temp.f32);
loc_8272DC68:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8272dc98
	if (!cr6.gt) goto loc_8272DC98;
	// lfs f0,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// lfs f12,104(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x8272dc9c
	if (!cr6.lt) goto loc_8272DC9C;
loc_8272DC98:
	// li r11,0
	r11.s64 = 0;
loc_8272DC9C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272dcc0
	if (cr6.eq) goto loc_8272DCC0;
	// bl 0x8272d0e0
	ctx.lr = 0x8272DCAC;
	sub_8272D0E0(ctx, base);
	// lwz r11,-21912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -21912);
	// li r29,1
	r29.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,-21912(r31)
	PPC_STORE_U32(r31.u32 + -21912, r11.u32);
	// b 0x8272dcc4
	goto loc_8272DCC4;
loc_8272DCC0:
	// bl 0x8272d500
	ctx.lr = 0x8272DCC4;
	sub_8272D500(ctx, base);
loc_8272DCC4:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r11,r27,256
	r11.s64 = r27.s64 + 256;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8272dc68
	if (cr6.lt) goto loc_8272DC68;
loc_8272DCD4:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272dcf8
	if (cr6.eq) goto loc_8272DCF8;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r6,r11,-11456
	ctx.r6.s64 = r11.s64 + -11456;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x823dcf08
	ctx.lr = 0x8272DCF8;
	sub_823DCF08(ctx, base);
loc_8272DCF8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8272DC20) {
	__imp__sub_8272DC20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DD04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272DD04) {
	__imp__sub_8272DD04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DD08) {
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
	ctx.lr = 0x8272DD10;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x8272dd38
	if (!cr6.eq) goto loc_8272DD38;
loc_8272DD2C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8272DD38:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8272dd54
	if (!cr6.eq) goto loc_8272DD54;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272DD48;
	sub_8272DB80(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8272dd2c
	if (cr6.eq) goto loc_8272DD2C;
loc_8272DD54:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r31,r11,-21904
	r31.s64 = r11.s64 + -21904;
	// lwz r30,-21904(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -21904);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8272d3d8
	ctx.lr = 0x8272DD6C;
	sub_8272D3D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272dd2c
	if (cr6.eq) goto loc_8272DD2C;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r11,-11456
	ctx.r6.s64 = r11.s64 + -11456;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x823dcf08
	ctx.lr = 0x8272DD90;
	sub_823DCF08(ctx, base);
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-21912(r29)
	PPC_STORE_U32(r29.u32 + -21912, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8272DD08) {
	__imp__sub_8272DD08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DDA8) {
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
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272de38
	if (cr6.eq) goto loc_8272DE38;
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272de04
	if (cr6.eq) goto loc_8272DE04;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8272de08
	goto loc_8272DE08;
loc_8272DE04:
	// li r11,0
	r11.s64 = 0;
loc_8272DE08:
	// lwz r11,172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272de1c
	if (cr6.eq) goto loc_8272DE1C;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// bl 0x8213b860
	ctx.lr = 0x8272DE1C;
	sub_8213B860(ctx, base);
loc_8272DE1C:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r11,44(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// stw r8,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r8.u32);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
loc_8272DE38:
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

PPC_WEAK_FUNC(sub_8272DDA8) {
	__imp__sub_8272DDA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272DE4C) {
	__imp__sub_8272DE4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272DE50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// bl 0x823d91cc
	ctx.lr = 0x8272DE58;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823db9b8
	ctx.lr = 0x8272DE60;
	// li r12,-240
	r12.s64 = -240;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// lwz r10,132(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// lbz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8272e998
	if (!cr6.lt) goto loc_8272E998;
	// lbz r11,118(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 118);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272e998
	if (cr6.eq) goto loc_8272E998;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r26,0(r4)
	r26.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r27,4(r4)
	r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r18,12(r4)
	r18.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f29,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f28,11332(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11332);
	f28.f64 = double(temp.f32);
	// lfs f27,11368(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11368);
	f27.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lfs f30,11360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11360);
	f30.f64 = double(temp.f32);
	// lfs f25,-13028(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -13028);
	f25.f64 = double(temp.f32);
	// li r19,0
	r19.s64 = 0;
	// lfs f26,11328(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11328);
	f26.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f23,17032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17032);
	f23.f64 = double(temp.f32);
	// li r21,0
	r21.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// fmr f24,f29
	f24.f64 = f29.f64;
	// li r22,0
	r22.s64 = 0;
	// li r20,80
	r20.s64 = 80;
	// lis r23,-32114
	r23.s64 = -2104623104;
	// addi r17,r11,29952
	r17.s64 = r11.s64 + 29952;
	// addi r28,r10,7216
	r28.s64 = ctx.r10.s64 + 7216;
	// addi r25,r9,-17696
	r25.s64 = ctx.r9.s64 + -17696;
loc_8272DF08:
	// cmpw cr6,r22,r18
	cr6.compare<int32_t>(r22.s32, r18.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x8272df18
	if (!cr6.lt) goto loc_8272DF18;
	// li r11,0
	r11.s64 = 0;
loc_8272DF18:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272e560
	if (!cr6.eq) goto loc_8272E560;
	// rlwinm r31,r22,2,0,29
	r31.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r31,r26
	r11.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// lbz r10,165(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 165);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8272e558
	if (cr6.eq) goto loc_8272E558;
	// lwz r11,160(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x8272df54
	if (!cr6.eq) goto loc_8272DF54;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8272df58
	goto loc_8272DF58;
loc_8272DF54:
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
loc_8272DF58:
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x8272df68
	if (!cr6.eq) goto loc_8272DF68;
	// lwz r30,12(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x8272df6c
	goto loc_8272DF6C;
loc_8272DF68:
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8272DF6C:
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// vor128 v63,v127,v127
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8272dfd4
	if (cr6.eq) goto loc_8272DFD4;
	// lwzx r10,r31,r26
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// lwz r11,160(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// bne cr6,0x8272dfa0
	if (!cr6.eq) goto loc_8272DFA0;
	// lwz r5,28(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x8272dfa4
	goto loc_8272DFA4;
loc_8272DFA0:
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
loc_8272DFA4:
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// beq cr6,0x8272dfb4
	if (cr6.eq) goto loc_8272DFB4;
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
loc_8272DFB4:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8272DFCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8272DFD4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272e044
	if (cr6.eq) goto loc_8272E044;
	// lwzx r10,r31,r26
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// lwz r11,160(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// bne cr6,0x8272dff8
	if (!cr6.eq) goto loc_8272DFF8;
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// b 0x8272dffc
	goto loc_8272DFFC;
loc_8272DFF8:
	// lwz r5,28(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28);
loc_8272DFFC:
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// beq cr6,0x8272e00c
	if (cr6.eq) goto loc_8272E00C;
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
loc_8272E00C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8272E028;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,336
	ctx.r7.s64 = ctx.r1.s64 + 336;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8272E044:
	// lwzx r3,r31,r26
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x8272e06c
	if (!cr6.eq) goto loc_8272E06C;
	// lvx128 v61,r3,r20
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v127,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8272e074
	goto loc_8272E074;
loc_8272E06C:
	// lvx128 v59,r3,r20
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8272E074:
	// vmsum3fp128 v58,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// subf r10,r27,r11
	ctx.r10.s64 = r11.s64 - r27.s64;
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// lwz r30,-23464(r23)
	r30.u64 = PPC_LOAD_U32(r23.u32 + -23464);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r4,r7,1
	ctx.r4.u64 = ctx.r7.u64 ^ 1;
	// vrsqrtefp128 v57,v58
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vmulfp128 v56,v63,v57
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825a2aa8
	ctx.lr = 0x8272E0A0;
	sub_825A2AA8(ctx, base);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,20(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8272E0B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f13,296(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,264(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	f0.f64 = double(temp.f32);
	// lwz r4,60(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f13,260(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,292(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,256(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,288(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f9.f64 = double(temp.f32);
	// lwz r30,0(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// fmadds f8,f13,f10,f11
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f11.f64));
	// fmadds f7,f12,f9,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f23
	cr6.compare(ctx.f7.f64, f23.f64);
	// blt cr6,0x8272e180
	if (cr6.lt) goto loc_8272E180;
	// lfs f11,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f9,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f0,f8,f12,f7
	f0.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// ble cr6,0x8272e558
	if (!cr6.gt) goto loc_8272E558;
	// lwzx r11,r31,r26
	r11.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// fmr f24,f0
	f24.f64 = f0.f64;
	// lwz r10,160(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// bne cr6,0x8272e12c
	if (!cr6.eq) goto loc_8272E12C;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// b 0x8272e130
	goto loc_8272E130;
loc_8272E12C:
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
loc_8272E130:
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r19,r30
	r19.u64 = r30.u64;
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r9,r31,r26
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// lwz r11,160(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x8272e15c
	if (!cr6.eq) goto loc_8272E15C;
	// lwz r21,4(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x8272e160
	goto loc_8272E160;
loc_8272E15C:
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
loc_8272E160:
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x8272e174
	if (!cr6.eq) goto loc_8272E174;
	// lwz r24,28(r11)
	r24.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// b 0x8272df08
	goto loc_8272DF08;
loc_8272E174:
	// lwz r24,36(r11)
	r24.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// b 0x8272df08
	goto loc_8272DF08;
loc_8272E180:
	// lfs f0,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f0.f64 = double(temp.f32);
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f0.f64 = double(temp.f32);
	// lfs f13,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,34(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lfs f9,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f8,f10
	ctx.f8.f64 = double(float(sqrt(ctx.f10.f64)));
	// fmuls f0,f8,f25
	f0.f64 = double(float(ctx.f8.f64 * f25.f64));
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// blt cr6,0x8272e558
	if (cr6.lt) goto loc_8272E558;
	// lwz r7,44(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,50(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 50);
	// lwz r8,40(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lhz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// lwz r5,34(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// stw r7,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r7.u32);
	// extsh r4,r9
	ctx.r4.s64 = ctx.r9.s16;
	// stw r10,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// lfs f22,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	f22.f64 = double(temp.f32);
	// stw r8,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r8.u32);
	// lfs f13,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// std r4,304(r1)
	PPC_STORE_U64(ctx.r1.u32 + 304, ctx.r4.u64);
	// stw r5,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r5.u32);
	// lfs f10,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f0,f11
	ctx.f8.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f7,f11,f10
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fsel f4,f8,f11,f0
	ctx.f4.f64 = ctx.f8.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// lfd f12,304(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 304);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fsubs f6,f22,f13
	ctx.f6.f64 = double(float(f22.f64 - ctx.f13.f64));
	// fsubs f3,f4,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f10.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// fdivs f31,f3,f7
	f31.f64 = double(float(ctx.f3.f64 / ctx.f7.f64));
	// fmuls f1,f5,f30
	ctx.f1.f64 = double(float(ctx.f5.f64 * f30.f64));
	// fmadds f21,f6,f31,f13
	f21.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f13.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E224;
	sub_821493F8(ctx, base);
	// lwz r3,100(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// fmr f20,f1
	ctx.fpscr.disableFlushMode();
	f20.f64 = ctx.f1.f64;
	// lhz r11,38(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 38);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,328(r1)
	PPC_STORE_U64(ctx.r1.u32 + 328, ctx.r9.u64);
	// lfd f2,328(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 328);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(f0.f64 * f30.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E24C;
	sub_821493F8(ctx, base);
	// fsubs f12,f20,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f20.f64 - ctx.f1.f64));
	// lwz r8,142(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 142);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f12,f31,f1
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + ctx.f1.f64));
	// fmuls f20,f11,f13
	f20.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// bl 0x821e8080
	ctx.lr = 0x8272E26C;
	sub_821E8080(ctx, base);
	// lwz r7,100(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// addi r6,r29,64
	ctx.r6.s64 = r29.s64 + 64;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// stfs f20,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f20.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stw r6,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r6.u32);
	// stfs f29,244(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f29,248(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f10,f21,f22
	ctx.f10.f64 = double(float(f21.f64 - f22.f64));
	// lhz r3,63(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 63);
	// lfs f0,280(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 280);
	f0.f64 = double(temp.f32);
	// lvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v53,v54
	ctx.fpscr.enableFlushModeUnconditional();
	v53.f32[0] = log2f(v54.f32[0]);
	v53.f32[1] = log2f(v54.f32[1]);
	v53.f32[2] = log2f(v54.f32[2]);
	v53.f32[3] = log2f(v54.f32[3]);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// std r10,320(r1)
	PPC_STORE_U64(ctx.r1.u32 + 320, ctx.r10.u64);
	// vmulfp128 v52,v53,v63
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v63.f32)));
	// fsubs f9,f20,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(f20.f64 - f0.f64));
	// lfs f0,276(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 276);
	f0.f64 = double(temp.f32);
	// fsel f1,f10,f22,f21
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? f22.f64 : f21.f64;
	// stvx128 v52,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,240(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f27
	ctx.f7.f64 = double(float(ctx.f8.f64 * f27.f64));
	// lfd f6,320(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 320);
	// fsel f5,f9,f7,f0
	ctx.f5.f64 = ctx.f9.f64 >= 0.0 ? ctx.f7.f64 : f0.f64;
	// fcfid f4,f6
	ctx.f4.f64 = double(ctx.f6.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fmadds f2,f3,f30,f5
	ctx.f2.f64 = double(float(ctx.f3.f64 * f30.f64 + ctx.f5.f64));
	// stfs f2,160(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bl 0x823db918
	ctx.lr = 0x8272E2E4;
	sub_823DB918(ctx, base);
	// lbz r8,230(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 230);
	// lwz r11,80(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// lwz r3,136(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// addi r31,r29,136
	r31.s64 = r29.s64 + 136;
	// ori r7,r8,32
	ctx.r7.u64 = ctx.r8.u64 | 32;
	// fmuls f0,f1,f28
	f0.f64 = double(float(ctx.f1.f64 * f28.f64));
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r7,230(r1)
	PPC_STORE_U8(ctx.r1.u32 + 230, ctx.r7.u8);
	// stw r11,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r11.u32);
	// fmuls f13,f0,f26
	ctx.f13.f64 = double(float(f0.f64 * f26.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,272(r1)
	PPC_STORE_U64(ctx.r1.u32 + 272, ctx.f12.u64);
	// lwz r6,276(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// stw r6,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r6.u32);
	// bne cr6,0x8272e36c
	if (!cr6.eq) goto loc_8272E36C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8272e350
	if (cr6.eq) goto loc_8272E350;
	// lbz r10,119(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 119);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272e350
	if (cr6.eq) goto loc_8272E350;
	// lwz r10,100(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lbz r9,62(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 62);
	// rlwinm r5,r9,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272E350;
	sub_821F7208(ctx, base);
loc_8272E350:
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,54(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 54);
	// bl 0x825491f0
	ctx.lr = 0x8272E368;
	sub_825491F0(ctx, base);
	// b 0x8272e3f4
	goto loc_8272E3F4;
loc_8272E36C:
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// bl 0x8213b860
	ctx.lr = 0x8272E374;
	sub_8213B860(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272e3a8
	if (cr6.eq) goto loc_8272E3A8;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272e3ac
	goto loc_8272E3AC;
loc_8272E3A8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8272E3AC:
	// lfs f1,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82148cb0
	ctx.lr = 0x8272E3B4;
	sub_82148CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272e3e8
	if (cr6.eq) goto loc_8272E3E8;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272e3ec
	goto loc_8272E3EC;
loc_8272E3E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8272E3EC:
	// lwz r4,164(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// bl 0x82148c60
	ctx.lr = 0x8272E3F4;
	sub_82148C60(ctx, base);
loc_8272E3F4:
	// lwz r11,138(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 138);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x8272e548
	if (!cr6.gt) goto loc_8272E548;
	// lhz r11,128(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 128);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,312(r1)
	PPC_STORE_U64(ctx.r1.u32 + 312, ctx.r9.u64);
	// lfd f0,312(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 312);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * f30.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E428;
	sub_821493F8(ctx, base);
	// lhz r8,126(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 126);
	// fmr f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = ctx.f1.f64;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f1,f9,f30
	ctx.f1.f64 = double(float(ctx.f9.f64 * f30.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E44C;
	sub_821493F8(ctx, base);
	// fsubs f8,f22,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(f22.f64 - ctx.f1.f64));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f29,100(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f29,104(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r3,140(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r29,140
	r31.s64 = r29.s64 + 140;
	// lfs f0,280(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 280);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f13,276(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f7,f8,f31,f1
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f1.f64));
	// stfs f7,96(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v51,r0,r5
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v50,v51
	ctx.fpscr.enableFlushModeUnconditional();
	v50.f32[0] = log2f(v51.f32[0]);
	v50.f32[1] = log2f(v51.f32[1]);
	v50.f32[2] = log2f(v51.f32[2]);
	v50.f32[3] = log2f(v51.f32[3]);
	// vmulfp128 v49,v50,v63
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v63.f32)));
	// fsubs f6,f7,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(ctx.f7.f64 - f0.f64));
	// stvx128 v49,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f27
	ctx.f4.f64 = double(float(ctx.f5.f64 * f27.f64));
	// fsel f3,f6,f4,f13
	ctx.f3.f64 = ctx.f6.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// stfs f3,160(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bne cr6,0x8272e4c0
	if (!cr6.eq) goto loc_8272E4C0;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lwz r4,130(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 130);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825491f0
	ctx.lr = 0x8272E4BC;
	sub_825491F0(ctx, base);
	// b 0x8272e548
	goto loc_8272E548;
loc_8272E4C0:
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// bl 0x8213b860
	ctx.lr = 0x8272E4C8;
	sub_8213B860(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272e4fc
	if (cr6.eq) goto loc_8272E4FC;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272e500
	goto loc_8272E500;
loc_8272E4FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8272E500:
	// lfs f1,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82148cb0
	ctx.lr = 0x8272E508;
	sub_82148CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272e53c
	if (cr6.eq) goto loc_8272E53C;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272e540
	goto loc_8272E540;
loc_8272E53C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8272E540:
	// lwz r4,164(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// bl 0x82148c60
	ctx.lr = 0x8272E548;
	sub_82148C60(ctx, base);
loc_8272E548:
	// lfs f0,104(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 104);
	f0.f64 = double(temp.f32);
	// stfs f0,108(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 108, temp.u32);
	// lwz r11,44(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 44);
	// stw r11,120(r29)
	PPC_STORE_U32(r29.u32 + 120, r11.u32);
loc_8272E558:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// b 0x8272df08
	goto loc_8272DF08;
loc_8272E560:
	// lwz r10,100(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// lbz r9,67(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 67);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8272e584
	if (cr6.lt) goto loc_8272E584;
	// lwz r9,124(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// lwz r11,44(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 44);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x8272e998
	if (cr6.eq) goto loc_8272E998;
loc_8272E584:
	// lbz r11,68(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 68);
	// lwz r9,132(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bge cr6,0x8272e998
	if (!cr6.lt) goto loc_8272E998;
	// fmuls f28,f24,f25
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(f24.f64 * f25.f64));
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x8272e5b4
	if (cr6.eq) goto loc_8272E5B4;
	// lwz r11,142(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 142);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f31,f0,f28
	f31.f64 = double(float(f0.f64 * f28.f64));
	// b 0x8272e5b8
	goto loc_8272E5B8;
loc_8272E5B4:
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	f31.f64 = f28.f64;
loc_8272E5B8:
	// lwz r11,22(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// blt cr6,0x8272e998
	if (cr6.lt) goto loc_8272E998;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lhz r10,63(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 63);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r11,32232
	ctx.r6.s64 = r11.s64 + 32232;
	// addi r5,r9,24092
	ctx.r5.s64 = ctx.r9.s64 + 24092;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// extsh r30,r10
	r30.s64 = ctx.r10.s16;
	// bl 0x823dedd8
	ctx.lr = 0x8272E5F4;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272e658
	if (cr6.eq) goto loc_8272E658;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,116(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,104(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// blt cr6,0x8272e998
	if (cr6.lt) goto loc_8272E998;
	// stfs f0,116(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 116, temp.u32);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r10,96(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// lwz r11,-23452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// rotlwi r10,r9,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// clrlwi r6,r7,30
	ctx.r6.u64 = ctx.r7.u32 & 0x3;
	// cmpwi cr6,r6,2
	cr6.compare<int32_t>(ctx.r6.s32, 2, xer);
	// bne cr6,0x8272e658
	if (!cr6.eq) goto loc_8272E658;
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// lhz r10,65(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 65);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
loc_8272E658:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8272d938
	ctx.lr = 0x8272E664;
	sub_8272D938(ctx, base);
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x8272e6e8
	if (!cr6.lt) goto loc_8272E6E8;
	// lwz r9,22(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 22);
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f9,f31,f11
	ctx.f9.f64 = double(float(f31.f64 - ctx.f11.f64));
	// fmuls f1,f8,f30
	ctx.f1.f64 = double(float(ctx.f8.f64 * f30.f64));
	// fdivs f31,f9,f10
	f31.f64 = double(float(ctx.f9.f64 / ctx.f10.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E6B8;
	sub_821493F8(ctx, base);
	// extsw r6,r30
	ctx.r6.s64 = r30.s32;
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f1.f64;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f7,88(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f1,f5,f30
	ctx.f1.f64 = double(float(ctx.f5.f64 * f30.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E6D8;
	sub_821493F8(ctx, base);
	// fsubs f4,f26,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f26.f64 - ctx.f1.f64));
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmadds f31,f4,f31,f1
	f31.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f1.f64));
	// b 0x8272e710
	goto loc_8272E710;
loc_8272E6E8:
	// lhz r11,32(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * f30.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E70C;
	sub_821493F8(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
loc_8272E710:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821e8080
	ctx.lr = 0x8272E718;
	sub_821E8080(ctx, base);
	// lwz r10,100(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f29,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f29,104(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lhz r5,63(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 63);
	// lfs f0,280(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 280);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// stw r7,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r7.u32);
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// lfs f0,276(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 276);
	f0.f64 = double(temp.f32);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r11,-10432(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10432);
	// lvx128 v48,r0,r9
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v47,v48
	ctx.fpscr.enableFlushModeUnconditional();
	v47.f32[0] = log2f(v48.f32[0]);
	v47.f32[1] = log2f(v48.f32[1]);
	v47.f32[2] = log2f(v48.f32[2]);
	v47.f32[3] = log2f(v48.f32[3]);
	// vmulfp128 v46,v47,v63
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v63.f32)));
	// lbz r9,230(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 230);
	// fcfid f9,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(ctx.f12.s64);
	// ori r7,r9,32
	ctx.r7.u64 = ctx.r9.u64 | 32;
	// stb r7,230(r1)
	PPC_STORE_U8(ctx.r1.u32 + 230, ctx.r7.u8);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// stvx128 v46,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f27
	ctx.f10.f64 = double(float(ctx.f11.f64 * f27.f64));
	// fsel f8,f13,f10,f0
	ctx.f8.f64 = ctx.f13.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fmadds f6,f7,f30,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * f30.f64 + ctx.f8.f64));
	// stfs f6,160(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lwz r6,140(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmplw cr6,r21,r6
	cr6.compare<uint32_t>(r21.u32, ctx.r6.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8272e7ac
	if (cr6.eq) goto loc_8272E7AC;
	// lwz r11,80(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 80);
loc_8272E7AC:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r11.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82548fd0
	ctx.lr = 0x8272E7CC;
	sub_82548FD0(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272e858
	if (cr6.eq) goto loc_8272E858;
	// lwz r3,80(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272e808
	if (cr6.eq) goto loc_8272E808;
	// lbz r10,119(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272e808
	if (cr6.eq) goto loc_8272E808;
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r5,r10,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272E804;
	sub_821F7208(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8272E808:
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272e838
	if (cr6.eq) goto loc_8272E838;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272e83c
	goto loc_8272E83C;
loc_8272E838:
	// li r11,0
	r11.s64 = 0;
loc_8272E83C:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r10,172(r11)
	PPC_STORE_U32(r11.u32 + 172, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8213c0c0
	ctx.lr = 0x8272E858;
	sub_8213C0C0(ctx, base);
loc_8272E858:
	// lwz r11,134(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 134);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x8272e97c
	if (!cr6.gt) goto loc_8272E97C;
	// lhz r11,128(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 128);
	// lwz r10,122(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 122);
	// extsh r7,r11
	ctx.r7.s64 = r11.s16;
	// lwz r8,118(r19)
	ctx.r8.u64 = PPC_LOAD_U32(r19.u32 + 118);
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f10,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fsubs f13,f28,f0
	ctx.f13.f64 = double(float(f28.f64 - f0.f64));
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// fdivs f31,f13,f9
	f31.f64 = double(float(ctx.f13.f64 / ctx.f9.f64));
	// fmuls f1,f8,f30
	ctx.f1.f64 = double(float(ctx.f8.f64 * f30.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E8B0;
	sub_821493F8(ctx, base);
	// lhz r6,126(r19)
	ctx.r6.u64 = PPC_LOAD_U16(r19.u32 + 126);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f7,88(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f1,f5,f30
	ctx.f1.f64 = double(float(ctx.f5.f64 * f30.f64));
	// bl 0x821493f8
	ctx.lr = 0x8272E8D4;
	sub_821493F8(ctx, base);
	// fsubs f3,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(f28.f64 - ctx.f1.f64));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f29,104(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r11,134(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 134);
	// stfs f29,100(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,230(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 230);
	// lfs f0,280(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 280);
	f0.f64 = double(temp.f32);
	// lwz r3,80(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// lfs f13,276(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f4,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r7,r7,0,27,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// fmadds f2,f3,f31,f1
	ctx.f2.f64 = double(float(ctx.f3.f64 * f31.f64 + ctx.f1.f64));
	// stb r7,230(r1)
	PPC_STORE_U8(ctx.r1.u32 + 230, ctx.r7.u8);
	// fmuls f1,f2,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f4.f64));
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v44,v45
	ctx.fpscr.enableFlushModeUnconditional();
	v44.f32[0] = log2f(v45.f32[0]);
	v44.f32[1] = log2f(v45.f32[1]);
	v44.f32[2] = log2f(v45.f32[2]);
	v44.f32[3] = log2f(v45.f32[3]);
	// vmulfp128 v43,v44,v63
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v63.f32)));
	// fsubs f0,f1,f0
	ctx.fpscr.disableFlushModeUnconditional();
	f0.f64 = double(float(ctx.f1.f64 - f0.f64));
	// stvx128 v43,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f27
	ctx.f11.f64 = double(float(ctx.f12.f64 * f27.f64));
	// fsel f10,f0,f11,f13
	ctx.f10.f64 = f0.f64 >= 0.0 ? ctx.f11.f64 : ctx.f13.f64;
	// stfs f10,160(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// beq cr6,0x8272e96c
	if (cr6.eq) goto loc_8272E96C;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272e96c
	if (cr6.eq) goto loc_8272E96C;
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r5,r10,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272E96C;
	sub_821F7208(ctx, base);
loc_8272E96C:
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r4,114(r19)
	ctx.r4.u64 = PPC_LOAD_U32(r19.u32 + 114);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82549118
	ctx.lr = 0x8272E97C;
	sub_82549118(ctx, base);
loc_8272E97C:
	// lwz r11,44(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 44);
	// lwz r10,128(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,120(r29)
	PPC_STORE_U32(r29.u32 + 120, ctx.r9.u32);
	// stw r11,124(r29)
	PPC_STORE_U32(r29.u32 + 124, r11.u32);
	// stw r10,128(r29)
	PPC_STORE_U32(r29.u32 + 128, ctx.r10.u32);
loc_8272E998:
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// li r0,-240
	r0.s64 = -240;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dba04
	ctx.lr = 0x8272E9AC;
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_8272DE50) {
	__imp__sub_8272DE50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272E9B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x8272E9B8;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// lbz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8272ebfc
	if (!cr6.lt) goto loc_8272EBFC;
	// lbz r10,118(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 118);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272ebfc
	if (cr6.eq) goto loc_8272EBFC;
	// lbz r11,62(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272e9fc
	if (cr6.eq) goto loc_8272E9FC;
	// lbz r11,148(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272ebfc
	if (!cr6.eq) goto loc_8272EBFC;
loc_8272E9FC:
	// li r21,0
	r21.s64 = 0;
	// lwz r24,0(r4)
	r24.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r27,4(r4)
	r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r19,12(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r23,r21
	r23.u64 = r21.u64;
	// li r25,1
	r25.s64 = 1;
	// lis r20,-32119
	r20.s64 = -2104950784;
	// lis r22,-32114
	r22.s64 = -2104623104;
	// addi r28,r10,7216
	r28.s64 = ctx.r10.s64 + 7216;
	// addi r26,r11,29952
	r26.s64 = r11.s64 + 29952;
loc_8272EA2C:
	// cmpw cr6,r23,r19
	cr6.compare<int32_t>(r23.s32, r19.s32, xer);
	// mr r11,r25
	r11.u64 = r25.u64;
	// bge cr6,0x8272ea3c
	if (!cr6.lt) goto loc_8272EA3C;
	// mr r11,r21
	r11.u64 = r21.u64;
loc_8272EA3C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272ebfc
	if (!cr6.eq) goto loc_8272EBFC;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lwz r10,128(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lbz r9,67(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 67);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8272ea6c
	if (cr6.lt) goto loc_8272EA6C;
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// lwz r10,44(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272ebfc
	if (cr6.eq) goto loc_8272EBFC;
loc_8272EA6C:
	// rlwinm r31,r23,2,0,29
	r31.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r31,r24
	r11.u64 = PPC_LOAD_U32(r31.u32 + r24.u32);
	// lbz r10,165(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 165);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8272ebf4
	if (cr6.eq) goto loc_8272EBF4;
	// lwz r11,160(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x8272ea9c
	if (!cr6.eq) goto loc_8272EA9C;
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x8272eaa0
	goto loc_8272EAA0;
loc_8272EA9C:
	// lwz r4,36(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 36);
loc_8272EAA0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8272d938
	ctx.lr = 0x8272EAA8;
	sub_8272D938(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,-32452(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -32452);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272ebf4
	if (cr6.eq) goto loc_8272EBF4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821e8080
	ctx.lr = 0x8272EAC4;
	sub_821E8080(ctx, base);
	// lwzx r11,r31,r24
	r11.u64 = PPC_LOAD_U32(r31.u32 + r24.u32);
	// lwz r10,160(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// beq cr6,0x8272eae0
	if (cr6.eq) goto loc_8272EAE0;
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
loc_8272EAE0:
	// lbz r8,166(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 166);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// ori r7,r8,32
	ctx.r7.u64 = ctx.r8.u64 | 32;
	// stb r7,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r7.u8);
	// lwz r11,160(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x8272eb04
	if (!cr6.eq) goto loc_8272EB04;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8272EB04:
	// lwz r11,-10432(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + -10432);
	// lwz r11,140(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// mr r11,r21
	r11.u64 = r21.u64;
	// beq cr6,0x8272eb1c
	if (cr6.eq) goto loc_8272EB1C;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
loc_8272EB1C:
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r21.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x82548fd0
	ctx.lr = 0x8272EB38;
	sub_82548FD0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272ebc0
	if (cr6.eq) goto loc_8272EBC0;
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272eb74
	if (cr6.eq) goto loc_8272EB74;
	// lbz r10,119(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272eb74
	if (cr6.eq) goto loc_8272EB74;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r5,r10,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272EB70;
	sub_821F7208(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8272EB74:
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272eba4
	if (cr6.eq) goto loc_8272EBA4;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8272eba8
	goto loc_8272EBA8;
loc_8272EBA4:
	// mr r11,r21
	r11.u64 = r21.u64;
loc_8272EBA8:
	// stw r25,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r25.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c0c0
	ctx.lr = 0x8272EBC0;
	sub_8213C0C0(ctx, base);
loc_8272EBC0:
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// stb r25,148(r30)
	PPC_STORE_U8(r30.u32 + 148, r25.u8);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r11,44(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r9,128(r30)
	PPC_STORE_U32(r30.u32 + 128, ctx.r9.u32);
	// stw r8,120(r30)
	PPC_STORE_U32(r30.u32 + 120, ctx.r8.u32);
	// lwz r10,100(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// stw r11,124(r30)
	PPC_STORE_U32(r30.u32 + 124, r11.u32);
	// lbz r7,62(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 62);
	// rlwinm r6,r7,0,29,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8272ebfc
	if (!cr6.eq) goto loc_8272EBFC;
loc_8272EBF4:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// b 0x8272ea2c
	goto loc_8272EA2C;
loc_8272EBFC:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_8272E9B0) {
	__imp__sub_8272E9B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272EC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272EC04) {
	__imp__sub_8272EC04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272EC08) {
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
	ctx.lr = 0x8272EC10;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lbz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8272edf0
	if (!cr6.lt) goto loc_8272EDF0;
	// lbz r10,118(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 118);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272edf0
	if (cr6.eq) goto loc_8272EDF0;
	// lbz r11,62(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// li r21,1
	r21.s64 = 1;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272ec60
	if (cr6.eq) goto loc_8272EC60;
	// lbz r11,148(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272edf0
	if (!cr6.eq) goto loc_8272EDF0;
	// mr r20,r21
	r20.u64 = r21.u64;
loc_8272EC60:
	// li r23,0
	r23.s64 = 0;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// mr r22,r23
	r22.u64 = r23.u64;
	// ble cr6,0x8272edf0
	if (!cr6.gt) goto loc_8272EDF0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lis r25,-32119
	r25.s64 = -2104950784;
	// lis r26,-32114
	r26.s64 = -2104623104;
	// addi r28,r11,7216
	r28.s64 = r11.s64 + 7216;
	// addi r27,r10,29952
	r27.s64 = ctx.r10.s64 + 29952;
loc_8272EC8C:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lbz r9,67(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 67);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8272ecb0
	if (cr6.lt) goto loc_8272ECB0;
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r10,44(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272edf0
	if (cr6.eq) goto loc_8272EDF0;
loc_8272ECB0:
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272ede0
	if (cr6.eq) goto loc_8272EDE0;
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// bl 0x8272d938
	ctx.lr = 0x8272ECCC;
	sub_8272D938(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,-32452(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -32452);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272ede0
	if (cr6.eq) goto loc_8272EDE0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r21,148(r31)
	PPC_STORE_U8(r31.u32 + 148, r21.u8);
	// bl 0x821e8080
	ctx.lr = 0x8272ECEC;
	sub_821E8080(ctx, base);
	// lbz r8,166(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 166);
	// addi r10,r31,64
	ctx.r10.s64 = r31.s64 + 64;
	// lwz r11,-10432(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10432);
	// ori r7,r8,32
	ctx.r7.u64 = ctx.r8.u64 | 32;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stb r7,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r7.u8);
	// lwz r6,160(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// lwz r5,140(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// mr r11,r23
	r11.u64 = r23.u64;
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// beq cr6,0x8272ed20
	if (cr6.eq) goto loc_8272ED20;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_8272ED20:
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x82548fd0
	ctx.lr = 0x8272ED3C;
	sub_82548FD0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272edc4
	if (cr6.eq) goto loc_8272EDC4;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272ed78
	if (cr6.eq) goto loc_8272ED78;
	// lbz r10,119(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272ed78
	if (cr6.eq) goto loc_8272ED78;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r5,r10,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272ED74;
	sub_821F7208(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8272ED78:
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272eda8
	if (cr6.eq) goto loc_8272EDA8;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8272edac
	goto loc_8272EDAC;
loc_8272EDA8:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8272EDAC:
	// stw r21,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r21.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c0c0
	ctx.lr = 0x8272EDC4;
	sub_8213C0C0(ctx, base);
loc_8272EDC4:
	// lwz r11,44(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r9.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// stw r10,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r10.u32);
loc_8272EDE0:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r22,r20
	cr6.compare<int32_t>(r22.s32, r20.s32, xer);
	// blt cr6,0x8272ec8c
	if (cr6.lt) goto loc_8272EC8C;
loc_8272EDF0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8272EC08) {
	__imp__sub_8272EC08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272EDF8) {
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
	ctx.lr = 0x8272EE00;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lbz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8272eff8
	if (!cr6.lt) goto loc_8272EFF8;
	// lbz r10,118(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 118);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272eff8
	if (cr6.eq) goto loc_8272EFF8;
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8272ee3c
	if (cr6.eq) goto loc_8272EE3C;
	// lwz r21,0(r4)
	r21.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// b 0x8272ee40
	goto loc_8272EE40;
loc_8272EE3C:
	// mr r21,r23
	r21.u64 = r23.u64;
loc_8272EE40:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x8272eff8
	if (cr6.eq) goto loc_8272EFF8;
	// lbz r11,62(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272ee64
	if (cr6.eq) goto loc_8272EE64;
	// lbz r11,148(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272eff8
	if (!cr6.eq) goto loc_8272EFF8;
loc_8272EE64:
	// mr r22,r23
	r22.u64 = r23.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x8272eff8
	if (!cr6.gt) goto loc_8272EFF8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r28,r4,212
	r28.s64 = ctx.r4.s64 + 212;
	// li r25,1
	r25.s64 = 1;
	// lis r24,-32119
	r24.s64 = -2104950784;
	// lis r27,-32114
	r27.s64 = -2104623104;
	// addi r29,r11,7216
	r29.s64 = r11.s64 + 7216;
	// addi r26,r10,29952
	r26.s64 = ctx.r10.s64 + 29952;
loc_8272EE90:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lbz r9,67(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 67);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8272eeb4
	if (cr6.lt) goto loc_8272EEB4;
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r10,44(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272eff8
	if (cr6.eq) goto loc_8272EFF8;
loc_8272EEB4:
	// addic. r11,r28,-196
	xer.ca = r28.u32 > 195;
	r11.s64 = r28.s64 + -196;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8272efe8
	if (cr0.eq) goto loc_8272EFE8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,-184(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -184);
	// bl 0x8272d938
	ctx.lr = 0x8272EEC8;
	sub_8272D938(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-32452(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -32452);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272efe8
	if (cr6.eq) goto loc_8272EFE8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r25,148(r31)
	PPC_STORE_U8(r31.u32 + 148, r25.u8);
	// bl 0x821e8080
	ctx.lr = 0x8272EEE8;
	sub_821E8080(ctx, base);
	// lbz r7,166(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 166);
	// lwz r11,-10432(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10432);
	// addi r10,r31,64
	ctx.r10.s64 = r31.s64 + 64;
	// ori r6,r7,32
	ctx.r6.u64 = ctx.r7.u64 | 32;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stb r6,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r6.u8);
	// lwz r5,140(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// mr r11,r23
	r11.u64 = r23.u64;
	// beq cr6,0x8272ef18
	if (cr6.eq) goto loc_8272EF18;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_8272EF18:
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-32452(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -32452);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x82548fd0
	ctx.lr = 0x8272EF44;
	sub_82548FD0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272efcc
	if (cr6.eq) goto loc_8272EFCC;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272ef80
	if (cr6.eq) goto loc_8272EF80;
	// lbz r10,119(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272ef80
	if (cr6.eq) goto loc_8272EF80;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r5,r10,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272EF7C;
	sub_821F7208(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8272EF80:
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272efb0
	if (cr6.eq) goto loc_8272EFB0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8272efb4
	goto loc_8272EFB4;
loc_8272EFB0:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8272EFB4:
	// stw r25,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r25.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8213c0c0
	ctx.lr = 0x8272EFCC;
	sub_8213C0C0(ctx, base);
loc_8272EFCC:
	// lwz r11,44(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r9.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// stw r10,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r10.u32);
loc_8272EFE8:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r28,r28,208
	r28.s64 = r28.s64 + 208;
	// cmpw cr6,r22,r21
	cr6.compare<int32_t>(r22.s32, r21.s32, xer);
	// blt cr6,0x8272ee90
	if (cr6.lt) goto loc_8272EE90;
loc_8272EFF8:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_8272EDF8) {
	__imp__sub_8272EDF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F000) {
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
	ctx.lr = 0x8272F008;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// lfs f0,-13028(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13028);
	f0.f64 = double(temp.f32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r7,34(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// lfs f13,224(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x8272f304
	if (cr6.lt) goto loc_8272F304;
	// lhz r4,48(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lhz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 38);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsh r6,r4
	ctx.r6.s64 = ctx.r4.s16;
	// lwz r5,34(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// li r30,0
	r30.s64 = 0;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfs f0,-17424(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -17424);
	f0.f64 = double(temp.f32);
	// lwz r8,40(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lfs f13,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r9,255
	ctx.r9.s64 = 255;
	// lwz r4,50(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 50);
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// li r11,-1
	r11.s64 = -1;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r6,r28,64
	ctx.r6.s64 = r28.s64 + 64;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// stw r30,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r30.u32);
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r30.u32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// stw r30,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r30.u32);
	// stw r30,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r30.u32);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r30,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r30.u32);
	// lfd f11,104(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r11.u32);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// lfs f8,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// stb r9,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r9.u8);
	// lfs f7,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f8
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// fsubs f5,f7,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// stb r30,181(r1)
	PPC_STORE_U8(ctx.r1.u32 + 181, r30.u8);
	// lfs f3,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f3.f64 = double(temp.f32);
	// stb r8,182(r1)
	PPC_STORE_U8(ctx.r1.u32 + 182, ctx.r8.u8);
	// lfs f4,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f4.f64 = double(temp.f32);
	// stw r6,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r6.u32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// frsp f0,f9
	f0.f64 = double(float(ctx.f9.f64));
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// fdivs f12,f6,f5
	ctx.f12.f64 = double(float(ctx.f6.f64 / ctx.f5.f64));
	// fsubs f11,f0,f1
	ctx.f11.f64 = double(float(f0.f64 - ctx.f1.f64));
	// fmadds f10,f2,f12,f4
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f12.f64 + ctx.f4.f64));
	// fmadds f9,f11,f12,f1
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f1.f64));
	// fsubs f8,f10,f3
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f3.f64));
	// fsubs f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsel f1,f8,f3,f10
	ctx.f1.f64 = ctx.f8.f64 >= 0.0 ? ctx.f3.f64 : ctx.f10.f64;
	// fsel f6,f7,f0,f9
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// fmuls f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// stfs f5,112(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x823db918
	ctx.lr = 0x8272F150;
	sub_823DB918(ctx, base);
	// frsp f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lbz r11,182(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 182);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// ori r9,r11,32
	ctx.r9.u64 = r11.u64 | 32;
	// lfs f0,11332(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11332);
	f0.f64 = double(temp.f32);
	// stb r9,182(r1)
	PPC_STORE_U8(ctx.r1.u32 + 182, ctx.r9.u8);
	// lfs f13,11328(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 11328);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-10432(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10432);
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fmuls f2,f3,f13
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fctiwz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f1.u64);
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// lwz r7,140(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// beq cr6,0x8272f1a4
	if (cr6.eq) goto loc_8272F1A4;
	// lwz r11,80(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 80);
loc_8272F1A4:
	// lwz r3,136(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// addi r29,r28,136
	r29.s64 = r28.s64 + 136;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f25c
	if (!cr6.eq) goto loc_8272F25C;
	// lwz r3,80(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272f1e4
	if (cr6.eq) goto loc_8272F1E4;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f1e4
	if (cr6.eq) goto loc_8272F1E4;
	// lwz r11,100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r5,r10,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272F1E4;
	sub_821F7208(ctx, base);
loc_8272F1E4:
	// lwz r11,100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,58(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 58);
	// bl 0x82549078
	ctx.lr = 0x8272F1FC;
	sub_82549078(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f2ec
	if (cr6.eq) goto loc_8272F2EC;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272f23c
	if (cr6.eq) goto loc_8272F23C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
loc_8272F23C:
	// li r11,1
	r11.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,172(r30)
	PPC_STORE_U32(r30.u32 + 172, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8213c0c0
	ctx.lr = 0x8272F258;
	sub_8213C0C0(ctx, base);
	// b 0x8272f2ec
	goto loc_8272F2EC;
loc_8272F25C:
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x8213b860
	ctx.lr = 0x8272F264;
	sub_8213B860(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8272f2a0
	if (cr6.eq) goto loc_8272F2A0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,11444(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272f2a4
	goto loc_8272F2A4;
loc_8272F2A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8272F2A4:
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82148cb0
	ctx.lr = 0x8272F2AC;
	sub_82148CB0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272f2e0
	if (cr6.eq) goto loc_8272F2E0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8272f2e4
	goto loc_8272F2E4;
loc_8272F2E0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8272F2E4:
	// lwz r4,116(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x82148c60
	ctx.lr = 0x8272F2EC;
	sub_82148C60(ctx, base);
loc_8272F2EC:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f0,104(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 104);
	f0.f64 = double(temp.f32);
	// stfs f0,108(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 108, temp.u32);
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lwz r11,44(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// stw r11,120(r28)
	PPC_STORE_U32(r28.u32 + 120, r11.u32);
loc_8272F304:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272F000) {
	__imp__sub_8272F000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F30C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272F30C) {
	__imp__sub_8272F30C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F310) {
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
	ctx.lr = 0x8272F318;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// lbz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8272f4a8
	if (!cr6.lt) goto loc_8272F4A8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8272f374
	if (cr6.eq) goto loc_8272F374;
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x8272f368
	if (cr6.eq) goto loc_8272F368;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8272F368:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272f4a8
	if (!cr6.eq) goto loc_8272F4A8;
loc_8272F374:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// li r8,255
	ctx.r8.s64 = 255;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// lfs f0,-17424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	f0.f64 = double(temp.f32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r31.u32);
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r31.u32);
	// stw r10,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r10.u32);
	// stw r9,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// stb r8,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r8.u8);
	// stb r31,165(r1)
	PPC_STORE_U8(ctx.r1.u32 + 165, r31.u8);
	// stb r7,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r7.u8);
	// bne cr6,0x8272f3e8
	if (!cr6.eq) goto loc_8272F3E8;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
loc_8272F3E8:
	// lbz r11,70(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 70);
	// addi r10,r30,64
	ctx.r10.s64 = r30.s64 + 64;
	// ori r9,r11,32
	ctx.r9.u64 = r11.u64 | 32;
	// stw r10,20(r29)
	PPC_STORE_U32(r29.u32 + 20, ctx.r10.u32);
	// stb r9,70(r29)
	PPC_STORE_U8(r29.u32 + 70, ctx.r9.u8);
	// lwz r8,80(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// stw r8,32(r29)
	PPC_STORE_U32(r29.u32 + 32, ctx.r8.u32);
	// lwz r7,80(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x8272f434
	if (cr6.eq) goto loc_8272F434;
	// rotlwi r3,r7,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f434
	if (cr6.eq) goto loc_8272F434;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// rlwinm r5,r10,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// bl 0x821f7208
	ctx.lr = 0x8272F434;
	sub_821F7208(ctx, base);
loc_8272F434:
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82548fd0
	ctx.lr = 0x8272F44C;
	sub_82548FD0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f4a8
	if (cr6.eq) goto loc_8272F4A8;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8272f48c
	if (cr6.eq) goto loc_8272F48C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
loc_8272F48C:
	// li r11,1
	r11.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8213c0c0
	ctx.lr = 0x8272F4A8;
	sub_8213C0C0(ctx, base);
loc_8272F4A8:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272F310) {
	__imp__sub_8272F310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F4B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8272d370
	ctx.lr = 0x8272F4D8;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f518
	if (!cr6.eq) goto loc_8272F518;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272F4E8;
	sub_8272DB80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8272f524
	if (cr6.eq) goto loc_8272F524;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r10,86(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 86);
	// lwz r11,-32452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32452);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272f524
	if (cr6.eq) goto loc_8272F524;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272dd08
	ctx.lr = 0x8272F510;
	sub_8272DD08(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272f524
	if (cr6.eq) goto loc_8272F524;
loc_8272F518:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8272d5f0
	ctx.lr = 0x8272F524;
	sub_8272D5F0(ctx, base);
loc_8272F524:
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

PPC_WEAK_FUNC(sub_8272F4B0) {
	__imp__sub_8272F4B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F540) {
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
	ctx.lr = 0x8272F548;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272d370
	ctx.lr = 0x8272F55C;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f5dc
	if (!cr6.eq) goto loc_8272F5DC;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beq cr6,0x8272f5e4
	if (cr6.eq) goto loc_8272F5E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272F57C;
	sub_8272DB80(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8272f5e4
	if (cr6.eq) goto loc_8272F5E4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r30,r11,-21904
	r30.s64 = r11.s64 + -21904;
	// lwz r31,-21904(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -21904);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272d3d8
	ctx.lr = 0x8272F5A0;
	sub_8272D3D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f5e4
	if (cr6.eq) goto loc_8272F5E4;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r11,-11456
	ctx.r6.s64 = r11.s64 + -11456;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x823dcf08
	ctx.lr = 0x8272F5C4;
	sub_823DCF08(ctx, base);
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,-21912(r29)
	PPC_STORE_U32(r29.u32 + -21912, r11.u32);
	// beq cr6,0x8272f5e4
	if (cr6.eq) goto loc_8272F5E4;
loc_8272F5DC:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8272de50
	ctx.lr = 0x8272F5E4;
	sub_8272DE50(ctx, base);
loc_8272F5E4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272F540) {
	__imp__sub_8272F540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272F5EC) {
	__imp__sub_8272F5EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F5F0) {
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
	ctx.lr = 0x8272F5F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272d370
	ctx.lr = 0x8272F60C;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f68c
	if (!cr6.eq) goto loc_8272F68C;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beq cr6,0x8272f694
	if (cr6.eq) goto loc_8272F694;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272F62C;
	sub_8272DB80(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8272f694
	if (cr6.eq) goto loc_8272F694;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r30,r11,-21904
	r30.s64 = r11.s64 + -21904;
	// lwz r31,-21904(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -21904);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272d3d8
	ctx.lr = 0x8272F650;
	sub_8272D3D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f694
	if (cr6.eq) goto loc_8272F694;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r11,-11456
	ctx.r6.s64 = r11.s64 + -11456;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x823dcf08
	ctx.lr = 0x8272F674;
	sub_823DCF08(ctx, base);
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,-21912(r29)
	PPC_STORE_U32(r29.u32 + -21912, r11.u32);
	// beq cr6,0x8272f694
	if (cr6.eq) goto loc_8272F694;
loc_8272F68C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8272e9b0
	ctx.lr = 0x8272F694;
	sub_8272E9B0(ctx, base);
loc_8272F694:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272F5F0) {
	__imp__sub_8272F5F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272F69C) {
	__imp__sub_8272F69C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F6A0) {
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
	ctx.lr = 0x8272F6A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x8272d370
	ctx.lr = 0x8272F6BC;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f73c
	if (!cr6.eq) goto loc_8272F73C;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beq cr6,0x8272f748
	if (cr6.eq) goto loc_8272F748;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272F6DC;
	sub_8272DB80(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8272f748
	if (cr6.eq) goto loc_8272F748;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r30,r11,-21904
	r30.s64 = r11.s64 + -21904;
	// lwz r31,-21904(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -21904);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272d3d8
	ctx.lr = 0x8272F700;
	sub_8272D3D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f748
	if (cr6.eq) goto loc_8272F748;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r11,-11456
	ctx.r6.s64 = r11.s64 + -11456;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x823dcf08
	ctx.lr = 0x8272F724;
	sub_823DCF08(ctx, base);
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,-21912(r29)
	PPC_STORE_U32(r29.u32 + -21912, r11.u32);
	// beq cr6,0x8272f748
	if (cr6.eq) goto loc_8272F748;
loc_8272F73C:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8272ec08
	ctx.lr = 0x8272F748;
	sub_8272EC08(ctx, base);
loc_8272F748:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8272F6A0) {
	__imp__sub_8272F6A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F750) {
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
	ctx.lr = 0x8272F758;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x8272d370
	ctx.lr = 0x8272F768;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f7e8
	if (!cr6.eq) goto loc_8272F7E8;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beq cr6,0x8272f7f0
	if (cr6.eq) goto loc_8272F7F0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272F788;
	sub_8272DB80(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8272f7f0
	if (cr6.eq) goto loc_8272F7F0;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r30,r11,-21904
	r30.s64 = r11.s64 + -21904;
	// lwz r31,-21904(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -21904);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272d3d8
	ctx.lr = 0x8272F7AC;
	sub_8272D3D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f7f0
	if (cr6.eq) goto loc_8272F7F0;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r11,-11456
	ctx.r6.s64 = r11.s64 + -11456;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x823dcf08
	ctx.lr = 0x8272F7D0;
	sub_823DCF08(ctx, base);
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,-21912(r29)
	PPC_STORE_U32(r29.u32 + -21912, r11.u32);
	// beq cr6,0x8272f7f0
	if (cr6.eq) goto loc_8272F7F0;
loc_8272F7E8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8272edf8
	ctx.lr = 0x8272F7F0;
	sub_8272EDF8(ctx, base);
loc_8272F7F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272F750) {
	__imp__sub_8272F750(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F7F8) {
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
	// bl 0x8272d370
	ctx.lr = 0x8272F818;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f858
	if (!cr6.eq) goto loc_8272F858;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272F828;
	sub_8272DB80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8272f860
	if (cr6.eq) goto loc_8272F860;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r10,58(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 58);
	// lwz r11,-32452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32452);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272f860
	if (cr6.eq) goto loc_8272F860;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272dd08
	ctx.lr = 0x8272F850;
	sub_8272DD08(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272f860
	if (cr6.eq) goto loc_8272F860;
loc_8272F858:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8272f000
	ctx.lr = 0x8272F860;
	sub_8272F000(ctx, base);
loc_8272F860:
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

PPC_WEAK_FUNC(sub_8272F7F8) {
	__imp__sub_8272F7F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// bl 0x8272d370
	ctx.lr = 0x8272F8A0;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f8e0
	if (!cr6.eq) goto loc_8272F8E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272F8B0;
	sub_8272DB80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8272f8ec
	if (cr6.eq) goto loc_8272F8EC;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r10,81(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 81);
	// lwz r11,-32452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32452);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8272f8ec
	if (cr6.eq) goto loc_8272F8EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272dd08
	ctx.lr = 0x8272F8D8;
	sub_8272DD08(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272f8ec
	if (cr6.eq) goto loc_8272F8EC;
loc_8272F8E0:
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8272d190
	ctx.lr = 0x8272F8EC;
	sub_8272D190(ctx, base);
loc_8272F8EC:
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

PPC_WEAK_FUNC(sub_8272F878) {
	__imp__sub_8272F878(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F908) {
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
	ctx.lr = 0x8272F910;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x8272d370
	ctx.lr = 0x8272F924;
	sub_8272D370(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8272f9a4
	if (!cr6.eq) goto loc_8272F9A4;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beq cr6,0x8272f9b0
	if (cr6.eq) goto loc_8272F9B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db80
	ctx.lr = 0x8272F944;
	sub_8272DB80(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8272f9b0
	if (cr6.eq) goto loc_8272F9B0;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r30,r11,-21904
	r30.s64 = r11.s64 + -21904;
	// lwz r31,-21904(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -21904);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272d3d8
	ctx.lr = 0x8272F968;
	sub_8272D3D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272f9b0
	if (cr6.eq) goto loc_8272F9B0;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r11,-11456
	ctx.r6.s64 = r11.s64 + -11456;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x823dcf08
	ctx.lr = 0x8272F98C;
	sub_823DCF08(ctx, base);
	// lwz r11,-21912(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21912);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,-21912(r29)
	PPC_STORE_U32(r29.u32 + -21912, r11.u32);
	// beq cr6,0x8272f9b0
	if (cr6.eq) goto loc_8272F9B0;
loc_8272F9A4:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8272f310
	ctx.lr = 0x8272F9B0;
	sub_8272F310(ctx, base);
loc_8272F9B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8272F908) {
	__imp__sub_8272F908(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F9B8) {
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
	// bl 0x827361f0
	ctx.lr = 0x8272F9D0;
	sub_827361F0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-19076
	ctx.r9.s64 = r11.s64 + -19076;
	// stb r10,160(r31)
	PPC_STORE_U8(r31.u32 + 160, ctx.r10.u8);
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

PPC_WEAK_FUNC(sub_8272F9B8) {
	__imp__sub_8272F9B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272F9FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272F9FC) {
	__imp__sub_8272F9FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FA00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, r11.u8);
	// b 0x82735438
	sub_82735438(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8272FA00) {
	__imp__sub_8272FA00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FA0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272FA0C) {
	__imp__sub_8272FA0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FA10) {
	PPC_FUNC_PROLOGUE();
	// b 0x8248bf08
	sub_8248BF08(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8272FA10) {
	__imp__sub_8272FA10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272FA14) {
	__imp__sub_8272FA14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FA18) {
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
	ctx.lr = 0x8272FA20;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r29,0
	r29.s64 = 0;
	// addi r9,r11,-19560
	ctx.r9.s64 = r11.s64 + -19560;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x8272faf0
	if (!cr6.gt) goto loc_8272FAF0;
	// li r30,0
	r30.s64 = 0;
loc_8272FA48:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82130588
	ctx.lr = 0x8272FA54;
	sub_82130588(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r10,r30,r11
	ctx.r10.u64 = r30.u64 + r11.u64;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272fa7c
	if (cr6.eq) goto loc_8272FA7C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272FA7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272FA7C:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272faa4
	if (cr6.eq) goto loc_8272FAA4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272FAA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272FAA4:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272facc
	if (cr6.eq) goto loc_8272FACC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272FACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272FACC:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8272FADC;
	sub_82130588(ctx, base);
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,40
	r30.s64 = r30.s64 + 40;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x8272fa48
	if (cr6.lt) goto loc_8272FA48;
loc_8272FAF0:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82130588
	ctx.lr = 0x8272FAF8;
	sub_82130588(ctx, base);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x8272FB00;
	sub_82130588(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x8272FB08;
	sub_82130588(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21612);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272fb2c
	if (cr6.eq) goto loc_8272FB2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272FB2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272FB2C:
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x821870b8
	ctx.lr = 0x8272FB34;
	sub_821870B8(ctx, base);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r3,-21616(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -21616);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272fb50
	if (cr6.eq) goto loc_8272FB50;
	// bl 0x82130588
	ctx.lr = 0x8272FB48;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21616(r30)
	PPC_STORE_U32(r30.u32 + -21616, r11.u32);
loc_8272FB50:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8272FB58;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8272FA18) {
	__imp__sub_8272FA18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FB60) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823db9d4
	ctx.lr = 0x8272FB70;
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f6,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f4,f0,f6
	ctx.f4.f64 = double(float(f0.f64 * ctx.f6.f64));
	// lfs f8,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f2,f6,f0
	ctx.f2.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsubs f0,f3,f6
	f0.f64 = double(float(ctx.f3.f64 - ctx.f6.f64));
	// lfs f5,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f3,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f29,f5,f7
	f29.f64 = double(float(ctx.f5.f64 - ctx.f7.f64));
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f31,f3,f8
	f31.f64 = double(float(ctx.f3.f64 - ctx.f8.f64));
	// lfs f11,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f30,f12,f5
	f30.f64 = double(float(ctx.f12.f64 - ctx.f5.f64));
	// fsubs f28,f11,f3
	f28.f64 = double(float(ctx.f11.f64 - ctx.f3.f64));
	// lfs f12,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmadds f13,f8,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f13.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fmadds f4,f7,f5,f4
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fmuls f2,f2,f0
	ctx.f2.f64 = double(float(ctx.f2.f64 * f0.f64));
	// fmuls f27,f0,f0
	f27.f64 = double(float(f0.f64 * f0.f64));
	// lfs f11,18612(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 18612);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f0,f7,f7,f13
	f0.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f13.f64));
	// fmadds f8,f8,f3,f4
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f3.f64 + ctx.f4.f64));
	// fmadds f4,f31,f28,f2
	ctx.f4.f64 = double(float(f31.f64 * f28.f64 + ctx.f2.f64));
	// fmadds f7,f30,f30,f27
	ctx.f7.f64 = double(float(f30.f64 * f30.f64 + f27.f64));
	// fmadds f2,f5,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + f0.f64));
	// fmadds f0,f29,f30,f4
	f0.f64 = double(float(f29.f64 * f30.f64 + ctx.f4.f64));
	// fmadds f13,f28,f28,f7
	ctx.f13.f64 = double(float(f28.f64 * f28.f64 + ctx.f7.f64));
	// fmadds f7,f6,f6,f2
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f2.f64));
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fabs f6,f13
	ctx.f6.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fmadds f5,f3,f3,f7
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f11
	cr6.compare(ctx.f6.f64, ctx.f11.f64);
	// fnmsubs f4,f8,f12,f5
	ctx.f4.f64 = double(float(-(ctx.f8.f64 * ctx.f12.f64 - ctx.f5.f64)));
	// fnmsubs f3,f1,f1,f4
	ctx.f3.f64 = double(float(-(ctx.f1.f64 * ctx.f1.f64 - ctx.f4.f64)));
	// fmuls f2,f3,f13
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fmuls f1,f2,f10
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fmsubs f11,f0,f0,f1
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 - ctx.f1.f64));
	// blt cr6,0x8272fc74
	if (cr6.lt) goto loc_8272FC74;
	// fcmpu cr6,f11,f9
	cr6.compare(ctx.f11.f64, ctx.f9.f64);
	// blt cr6,0x8272fc74
	if (cr6.lt) goto loc_8272FC74;
	// fsqrts f10,f11
	ctx.f10.f64 = double(float(sqrt(ctx.f11.f64)));
	// li r3,1
	ctx.r3.s64 = 1;
	// fneg f9,f0
	ctx.f9.u64 = f0.u64 ^ 0x8000000000000000;
	// fsqrts f8,f11
	ctx.f8.f64 = double(float(sqrt(ctx.f11.f64)));
	// fmuls f7,f13,f12
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fsubs f6,f10,f0
	ctx.f6.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f5,f9,f8
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fdivs f4,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 / ctx.f7.f64));
	// stfs f4,0(r7)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fdivs f3,f5,f7
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f7.f64));
	// stfs f3,0(r8)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823dba20
	ctx.lr = 0x8272FC68;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8272FC74:
	// stfs f9,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stfs f9,0(r8)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823dba20
	ctx.lr = 0x8272FC88;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8272FB60) {
	__imp__sub_8272FB60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8272FC94) {
	__imp__sub_8272FC94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FC98) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8272FCA0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lfs f12,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,23772
	ctx.r3.s64 = 1557921792;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r4,104(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// lfs f11,40(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// ori r10,r3,64167
	ctx.r10.u64 = ctx.r3.u64 | 64167;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// rlwinm r9,r4,3,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF0;
	// lwz r11,-21616(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21616);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// stvx128 v1,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lvx128 v62,r9,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mulld r9,r9,r5
	ctx.r9.s64 = ctx.r9.s64 * ctx.r5.s64;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-21616(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21616);
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// clrlwi r6,r9,9
	ctx.r6.u64 = ctx.r9.u32 & 0x7FFFFF;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r9,r9,r4
	ctx.r9.s64 = ctx.r9.s64 * ctx.r4.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// fmuls f10,f0,f0
	ctx.f10.f64 = double(float(f0.f64 * f0.f64));
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f8,88(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// rldicl r4,r10,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// rotlwi r6,r9,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r11,-21616(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21616);
	// stvx128 v2,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r4,r6,9
	ctx.r4.u64 = ctx.r6.u32 & 0x7FFFFF;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f0,f0,f9
	ctx.f6.f64 = double(float(f0.f64 * f0.f64 + ctx.f9.f64));
	// lfd f7,88(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f5,f8
	ctx.f5.f64 = double(ctx.f8.s64);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r9,r6,r3
	ctx.r9.s64 = ctx.r6.s64 * ctx.r3.s64;
	// fsqrts f3,f6
	ctx.f3.f64 = double(float(sqrt(ctx.f6.f64)));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rldicl r3,r10,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// clrlwi r7,r10,9
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFF;
	// fmuls f1,f3,f11
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v60,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fcfid f4,f7
	ctx.f4.f64 = double(ctx.f7.s64);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// vspltw128 v13,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// frsp f13,f5
	ctx.f13.f64 = double(float(ctx.f5.f64));
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f2,88(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f2
	f0.f64 = double(ctx.f2.s64);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f12,f4
	ctx.f12.f64 = double(float(ctx.f4.f64));
	// vmaddfp v12,v1,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// frsp f11,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(f0.f64));
	// fmuls f10,f13,f1
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// lfs f0,-17024(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -17024);
	f0.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fmuls f9,f12,f1
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f1.f64));
	// fmuls f8,f11,f1
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// stvx128 v12,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f3,f9,f0,f7
	ctx.f3.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f7.f64));
	// stfs f3,100(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f4,f10,f0,f5
	ctx.f4.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f5.f64));
	// stfs f4,96(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f2,f8,f0,f6
	ctx.f2.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f6.f64));
	// stfs f2,104(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8272fb60
	ctx.lr = 0x8272FE64;
	sub_8272FB60(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,36
	ctx.r6.s64 = 36;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// vsubfp128 v11,v59,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v58,r29,r7
	temp.u32 = r29.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvlx128 v57,r29,r6
	temp.u32 = r29.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// lvlx128 v55,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v9,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v54,r0,r31
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v8,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vmaddfp v7,v11,v9,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsubfp128 v53,v7,v2
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vsubfp128 v6,v53,v54
	simde_mm_store_ps(ctx.v6.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// vmaddfp v5,v6,v10,v8
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v52,v5,v56
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v52,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bgt cr6,0x8272fed0
	if (cr6.gt) goto loc_8272FED0;
	// li r11,0
	r11.s64 = 0;
loc_8272FED0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r11.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8272FC98) {
	__imp__sub_8272FC98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8272FEE0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8272FEE8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// lwz r9,116(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8272ff24
	if (cr6.eq) goto loc_8272FF24;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
loc_8272FF08:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8272ff24
	if (!cr6.eq) goto loc_8272FF24;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8272ff08
	if (cr6.lt) goto loc_8272FF08;
loc_8272FF24:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x82730144
	if (!cr6.lt) goto loc_82730144;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217fed0
	ctx.lr = 0x8272FF34;
	sub_8217FED0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r3,6
	ctx.r3.s64 = 6;
	// xori r24,r10,1
	r24.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8217f768
	ctx.lr = 0x8272FF4C;
	sub_8217F768(ctx, base);
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r29,-32111
	r29.s64 = -2104426496;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,-21612(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8272FF7C;
	sub_8218A6E0(ctx, base);
	// lfs f13,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,-21612(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,124(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8272FFA8;
	sub_8218A6E0(ctx, base);
	// lfs f12,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,-21612(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,128(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8272FFD4;
	sub_8218A6E0(ctx, base);
	// lfs f11,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,-21612(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,132(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82730000;
	sub_8218A6E0(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r8,-31280
	ctx.r4.s64 = ctx.r8.s64 + -31280;
	// lwz r3,-26876(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82730014;
	sub_8217C088(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x82730020;
	sub_8217F768(ctx, base);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x82178430
	ctx.lr = 0x82730028;
	sub_82178430(ctx, base);
	// lwz r11,-21612(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82730040;
	sub_82189CE0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,-21612(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,136(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82187f40
	ctx.lr = 0x82730054;
	sub_82187F40(ctx, base);
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// ble cr6,0x82730130
	if (!cr6.gt) goto loc_82730130;
	// li r26,0
	r26.s64 = 0;
	// li r27,0
	r27.s64 = 0;
loc_82730070:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82730118
	if (cr6.lt) goto loc_82730118;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r10,r27,r11
	ctx.r10.u64 = r27.u64 + r11.u64;
	// lwz r10,36(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// add r10,r26,r10
	ctx.r10.u64 = r26.u64 + ctx.r10.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x82177bf8
	ctx.lr = 0x827300B0;
	sub_82177BF8(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82730110
	if (!cr6.gt) goto loc_82730110;
loc_827300BC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-21612(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// bl 0x82187b88
	ctx.lr = 0x827300C8;
	sub_82187B88(ctx, base);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r7,104(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// li r3,3
	ctx.r3.s64 = 3;
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// mullw r11,r8,r7
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x821795f8
	ctx.lr = 0x827300FC;
	sub_821795F8(ctx, base);
	// lwz r3,-21612(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// bl 0x82187ba8
	ctx.lr = 0x82730104;
	sub_82187BA8(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x827300bc
	if (cr6.lt) goto loc_827300BC;
loc_82730110:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82177c50
	ctx.lr = 0x82730118;
	sub_82177C50(ctx, base);
loc_82730118:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,40
	r27.s64 = r27.s64 + 40;
	// addi r26,r26,10
	r26.s64 = r26.s64 + 10;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// blt cr6,0x82730070
	if (cr6.lt) goto loc_82730070;
loc_82730130:
	// lwz r3,-21612(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -21612);
	// bl 0x82187bd0
	ctx.lr = 0x82730138;
	sub_82187BD0(ctx, base);
	// clrlwi r4,r24,24
	ctx.r4.u64 = r24.u32 & 0xFF;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x82730144;
	sub_8217F768(ctx, base);
loc_82730144:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8272FEE0) {
	__imp__sub_8272FEE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273014C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273014C) {
	__imp__sub_8273014C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82730150) {
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
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-16924
	ctx.r4.s64 = r11.s64 + -16924;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-21612(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21612);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82730184;
	sub_8218A568(ctx, base);
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,-21612(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21612);
	// addi r4,r10,-16944
	ctx.r4.s64 = ctx.r10.s64 + -16944;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x827301A0;
	sub_8218A568(ctx, base);
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lwz r11,-21612(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21612);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r9,-16964
	ctx.r4.s64 = ctx.r9.s64 + -16964;
	// bl 0x8218a568
	ctx.lr = 0x827301BC;
	sub_8218A568(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r3.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lwz r11,-21612(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21612);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r8,-16992
	ctx.r4.s64 = ctx.r8.s64 + -16992;
	// bl 0x8218a568
	ctx.lr = 0x827301D8;
	sub_8218A568(ctx, base);
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lwz r11,-21612(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21612);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r7,-17008
	ctx.r4.s64 = ctx.r7.s64 + -17008;
	// bl 0x8218a568
	ctx.lr = 0x827301F4;
	sub_8218A568(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lwz r11,-21612(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21612);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r6,-17020
	ctx.r4.s64 = ctx.r6.s64 + -17020;
	// bl 0x8218b688
	ctx.lr = 0x82730210;
	sub_8218B688(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_82730150) {
	__imp__sub_82730150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273022C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273022C) {
	__imp__sub_8273022C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82730230) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827303e8
	if (cr6.eq) goto loc_827303E8;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r11,23772
	r11.s64 = 1557921792;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// ori r10,r11,64167
	ctx.r10.u64 = r11.u64 | 64167;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,-21616(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21616);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lfs f12,-26384(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -26384);
	ctx.f12.f64 = double(temp.f32);
	// lis r31,-32256
	r31.s64 = -2113929216;
	// lis r30,-32256
	r30.s64 = -2113929216;
	// lfs f10,14348(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14348);
	ctx.f10.f64 = double(temp.f32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f8,32688(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32688);
	ctx.f8.f64 = double(temp.f32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f9,-29232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f9.f64 = double(temp.f32);
	// mulld r7,r7,r10
	ctx.r7.s64 = ctx.r7.s64 * ctx.r10.s64;
	// lfs f7,14884(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14884);
	ctx.f7.f64 = double(temp.f32);
	// lfs f0,3796(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 3796);
	f0.f64 = double(temp.f32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rldicl r3,r8,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// clrlwi r5,r8,9
	ctx.r5.u64 = ctx.r8.u32 & 0x7FFFFF;
	// std r5,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f13,-32(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f6,f11
	ctx.f6.f64 = double(float(ctx.f11.f64));
	// fmuls f13,f6,f10
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x827302cc
	if (!cr6.gt) goto loc_827302CC;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// b 0x827302e0
	goto loc_827302E0;
loc_827302CC:
	// fcmpu cr6,f13,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f8.f64);
	// ble cr6,0x827302dc
	if (!cr6.gt) goto loc_827302DC;
	// fmr f11,f9
	ctx.f11.f64 = ctx.f9.f64;
	// b 0x827302e0
	goto loc_827302E0;
loc_827302DC:
	// fmr f11,f7
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f7.f64;
loc_827302E0:
	// lwz r11,-21616(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21616);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r7,r7,r10
	ctx.r7.s64 = ctx.r7.s64 * ctx.r10.s64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rldicl r3,r8,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// clrlwi r5,r8,9
	ctx.r5.u64 = ctx.r8.u32 & 0x7FFFFF;
	// std r5,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f13,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f13,f5,f10
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f10.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x82730338
	if (cr6.gt) goto loc_82730338;
	// fcmpu cr6,f13,f8
	cr6.compare(ctx.f13.f64, ctx.f8.f64);
	// ble cr6,0x82730334
	if (!cr6.gt) goto loc_82730334;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x82730338
	goto loc_82730338;
loc_82730334:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f7.f64;
loc_82730338:
	// rlwinm r8,r6,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,-21616(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21616);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stfs f0,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// stfs f11,32(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 32, temp.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r8,r5,r7
	ctx.r8.s64 = ctx.r5.s64 * ctx.r7.s64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rldicl r3,r9,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// std r8,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// lfd f13,-32(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// fmuls f6,f8,f10
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// fcmpu cr6,f6,f7
	cr6.compare(ctx.f6.f64, ctx.f7.f64);
	// ble cr6,0x827303c0
	if (!cr6.gt) goto loc_827303C0;
	// fadds f13,f0,f9
	ctx.f13.f64 = double(float(f0.f64 + ctx.f9.f64));
	// stfs f13,84(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 84, temp.u32);
	// stfs f11,80(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 80, temp.u32);
	// fadds f13,f11,f9
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f9.f64));
	// fadds f12,f0,f9
	ctx.f12.f64 = double(float(f0.f64 + ctx.f9.f64));
	// stfs f13,128(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 128, temp.u32);
	// stfs f12,132(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 132, temp.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_827303C0:
	// fadds f13,f11,f9
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f9.f64));
	// stfs f13,80(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 80, temp.u32);
	// stfs f0,84(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 84, temp.u32);
	// fadds f13,f11,f9
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f9.f64));
	// fadds f12,f0,f9
	ctx.f12.f64 = double(float(f0.f64 + ctx.f9.f64));
	// stfs f13,128(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 128, temp.u32);
	// stfs f12,132(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 132, temp.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_827303E8:
	// rlwinm r11,r6,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// add r9,r6,r11
	ctx.r9.u64 = ctx.r6.u64 + r11.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// lfs f0,-16904(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16904);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stfs f0,36(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// stfs f0,80(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
	// stfs f0,84(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// stfs f0,128(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f0,132(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82730230) {
	__imp__sub_82730230(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82730424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82730424) {
	__imp__sub_82730424(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82730428) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82730430;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d8
	ctx.lr = 0x82730438;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f28,12(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	f28.f64 = double(temp.f32);
	// lfs f29,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fcmpu cr6,f28,f29
	cr6.compare(f28.f64, f29.f64);
	// beq cr6,0x827309d8
	if (cr6.eq) goto loc_827309D8;
	// lfs f0,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	f0.f64 = double(temp.f32);
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// lfs f13,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f0,f30
	ctx.f10.f64 = double(float(f0.f64 * f30.f64));
	// lfs f12,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 * f30.f64));
	// lfs f0,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// fmuls f9,f12,f30
	ctx.f9.f64 = double(float(ctx.f12.f64 * f30.f64));
	// stfs f30,108(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ble cr6,0x827304ac
	if (!cr6.gt) goto loc_827304AC;
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba24
	ctx.lr = 0x827304A8;
	// b 0x823d9238
	return;
loc_827304AC:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x827304b8
	if (!cr6.lt) goto loc_827304B8;
	// stfs f29,76(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
loc_827304B8:
	// li r26,48
	r26.s64 = 48;
	// fcmpu cr6,f13,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f29.f64);
	// bge cr6,0x82730738
	if (!cr6.lt) goto loc_82730738;
	// lfs f13,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// fadds f0,f13,f11
	f0.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// lfs f12,-21620(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21620);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x82730738
	if (!cr6.lt) goto loc_82730738;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f10,52(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r8,-7360
	ctx.r6.s64 = ctx.r8.s64 + -7360;
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// fmsubs f8,f12,f0,f11
	ctx.f8.f64 = double(float(ctx.f12.f64 * f0.f64 - ctx.f11.f64));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// stfs f7,4(r27)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r27.u32 + 4, temp.u32);
	// fsubs f6,f8,f10
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// stfs f6,52(r27)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r27.u32 + 52, temp.u32);
	// fsubs f5,f8,f9
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// stfs f5,100(r27)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r27.u32 + 100, temp.u32);
	// lfs f4,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v60,v61,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f4,f4
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f4.f64));
	// lfs f2,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f2.f64 = double(temp.f32);
	// vor128 v59,v61,v61
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lfs f0,-7360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -7360);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f1,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f11,f1,f1,f3
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f1.f64 + ctx.f3.f64));
	// fsqrts f10,f11
	ctx.f10.f64 = double(float(sqrt(ctx.f11.f64)));
	// fsqrts f9,f2
	ctx.f9.f64 = double(float(sqrt(ctx.f2.f64)));
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f6,f13,f8
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// stfs f6,84(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f5,f12,f8
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// stfs f5,88(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v62,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f4,68(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f4.f64 = double(temp.f32);
	// fneg f3,f4
	ctx.f3.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// stfs f3,68(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// lfs f0,-7368(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -7368);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f3,f0
	cr6.compare(ctx.f3.f64, f0.f64);
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x827305b8
	if (!cr6.lt) goto loc_827305B8;
	// stfs f29,68(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
loc_827305B8:
	// vspltisw128 v56,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// addi r28,r31,32
	r28.s64 = r31.s64 + 32;
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// lis r25,-32111
	r25.s64 = -2104426496;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// lis r11,23772
	r11.s64 = 1557921792;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// ori r30,r11,64167
	r30.u64 = r11.u64 | 64167;
	// lis r24,-32125
	r24.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vpermwi128 v54,v55,234
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x15));
	// vpermwi128 v53,v55,186
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x45));
	// lfs f31,14348(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14348);
	f31.f64 = double(temp.f32);
	// vpermwi128 v52,v55,174
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x51));
	// stvx128 v54,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-21616(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -21616);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r9,r9,r30
	ctx.r9.s64 = ctx.r9.s64 * r30.s64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rldicl r7,r10,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// lfs f0,-7372(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -7372);
	f0.f64 = double(temp.f32);
	// clrlwi r4,r6,9
	ctx.r4.u64 = ctx.r6.u32 & 0x7FFFFF;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmuls f8,f9,f28
	ctx.f8.f64 = double(float(ctx.f9.f64 * f28.f64));
	// fmuls f1,f8,f31
	ctx.f1.f64 = double(float(ctx.f8.f64 * f31.f64));
	// bl 0x82235e30
	ctx.lr = 0x8273065C;
	sub_82235E30(ctx, base);
	// lwz r11,-21616(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -21616);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r9,r9,r30
	ctx.r9.s64 = ctx.r9.s64 * r30.s64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rldicl r7,r10,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// clrlwi r4,r6,9
	ctx.r4.u64 = ctx.r6.u32 & 0x7FFFFF;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f7,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// lfs f0,-7372(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -7372);
	f0.f64 = double(temp.f32);
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmuls f3,f4,f28
	ctx.f3.f64 = double(float(ctx.f4.f64 * f28.f64));
	// fmuls f1,f3,f31
	ctx.f1.f64 = double(float(ctx.f3.f64 * f31.f64));
	// bl 0x82204cb8
	ctx.lr = 0x827306B0;
	sub_82204CB8(ctx, base);
	// lwz r11,-21616(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -21616);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r9,r9,r30
	ctx.r9.s64 = ctx.r9.s64 * r30.s64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rldicl r7,r10,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// lfs f0,-7372(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + -7372);
	f0.f64 = double(temp.f32);
	// clrlwi r4,r6,9
	ctx.r4.u64 = ctx.r6.u32 & 0x7FFFFF;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f2,80(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f11,f12,f28
	ctx.f11.f64 = double(float(ctx.f12.f64 * f28.f64));
	// fmuls f1,f11,f31
	ctx.f1.f64 = double(float(ctx.f11.f64 * f31.f64));
	// bl 0x82235ee0
	ctx.lr = 0x82730704;
	sub_82235EE0(ctx, base);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lvx128 v49,r0,r31
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r29
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,-7364
	r11.s64 = ctx.r3.s64 + -7364;
	// lvx128 v47,r0,r28
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v51,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vmulfp128 v46,v49,v50
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vmulfp128 v45,v48,v50
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v50.f32)));
	// vmulfp128 v44,v47,v50
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v46,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82730738:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v43,r0,r27
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r27,48
	r11.s64 = r27.s64 + 48;
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// addi r10,r27,96
	ctx.r10.s64 = r27.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// vaddfp128 v42,v43,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,32688(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 32688);
	f0.f64 = double(temp.f32);
	// stvx128 v42,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r11
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v40,v41,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r0,r10
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v38,v39,v63
	simde_mm_store_ps(v38.f32, simde_mm_add_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v38,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v34,v38,v38
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// lvx128 v36,r0,r11
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v63,v36,v36
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v36.u8));
	// lvx128 v37,r0,r27
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v35,v37,v36
	simde_mm_store_ps(v35.f32, simde_mm_add_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v36.f32)));
	// vaddfp128 v33,v35,v34
	simde_mm_store_ps(v33.f32, simde_mm_add_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v34.f32)));
	// stvx128 v33,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f7,84(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f9,92(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v32,v37,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v32.f32, simde_mm_sub_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v61,v63,v62
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v32,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v60,v62
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82730920
	if (cr6.eq) goto loc_82730920;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,32
	ctx.r9.s64 = r31.s64 + 32;
	// lvx128 v57,r0,r27
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r31,48
	ctx.r8.s64 = r31.s64 + 48;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r31,16
	ctx.r7.s64 = r31.s64 + 16;
	// vor128 v55,v59,v59
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// addi r5,r6,2384
	ctx.r5.s64 = ctx.r6.s64 + 2384;
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r4,2352
	ctx.r3.s64 = ctx.r4.s64 + 2352;
	// lvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r7
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v51,v58,v54
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v50,v52,v53
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vand128 v49,v57,v63
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v48,v58,v54
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v47,v52,v53
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v46,v51,v50
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vor128 v45,v63,v49
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// vmrghw128 v44,v51,v50
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v43,v48,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmsum4fp128 v42,v45,v46
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32), 0xFF));
	// vmsum4fp128 v41,v45,v43
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmsum4fp128 v40,v45,v44
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmrghw128 v39,v42,v45
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v38,v40,v41
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v37,v38,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// stvx128 v37,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r0,r9
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v34,v56,v63
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r31
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r0,r8
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v61,v35,v33
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v60,v36,v32
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrglw128 v59,v36,v32
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vor128 v58,v63,v34
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v34.u8)));
	// vmrglw128 v57,v35,v33
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrglw128 v56,v60,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v54,v60,v61
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v53,v59,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmsum4fp128 v52,v58,v56
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v56.f32), 0xFF));
	// vmsum4fp128 v51,v58,v54
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v54.f32), 0xFF));
	// vmsum4fp128 v50,v58,v53
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// vmrghw128 v49,v52,v58
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v48,v51,v50
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v47,v48,v49
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// stvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r7
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r9
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r8
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v44,v55,v63
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v46,r0,r31
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v40,v45,v42
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v41,v46,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v39,v46,v43
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vor128 v38,v63,v44
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v44.u8)));
	// vmrglw128 v37,v45,v42
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrglw128 v36,v41,v40
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v35,v41,v40
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v34,v39,v37
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmsum4fp128 v33,v38,v36
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v36.f32), 0xFF));
	// vmsum4fp128 v32,v38,v35
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v35.f32), 0xFF));
	// vmsum4fp128 v63,v38,v34
	simde_mm_store_ps(v63.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v34.f32), 0xFF));
	// vmrghw128 v61,v33,v38
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v60,v32,v63
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v59,v60,v61
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82730920:
	// lvx128 v58,r0,r27
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// vaddfp128 v57,v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// li r9,16
	ctx.r9.s64 = 16;
	// stvx128 v57,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v55,v56,v62
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v53,v54,v62
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f28,108(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + 108, temp.u32);
	// stfs f28,60(r27)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + 60, temp.u32);
	// stfs f28,12(r27)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + 12, temp.u32);
	// beq cr6,0x827309b0
	if (cr6.eq) goto loc_827309B0;
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v52,r0,r31
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r31,r26
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r27,16
	r11.s64 = r27.s64 + 16;
	// lvx128 v50,r31,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v49,v50,v51
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrglw128 v48,v50,v51
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// lvx128 v47,r31,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v46,v52,v47
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v44,v52,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v43,v46,v49
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v42,v44,v48
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrglw128 v41,v46,v49
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmsum3fp128 v40,v45,v43
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v43.f32), 0xEF));
	// vmsum3fp128 v39,v45,v42
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v42.f32), 0xEF));
	// vmsum3fp128 v38,v45,v41
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v41.f32), 0xEF));
	// vmrghw128 v37,v40,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v36,v38,v37
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v35,v37,v36
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// stvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827309B0:
	// lvx128 v34,r27,r9
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r27,112
	r11.s64 = r27.s64 + 112;
	// li r10,64
	ctx.r10.s64 = 64;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// stvx128 v34,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r27,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16900(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -16900);
	f0.f64 = double(temp.f32);
	// lfs f13,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f30,f0,f13
	ctx.f12.f64 = double(float(-(f30.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f12,68(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
loc_827309D8:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba24
	ctx.lr = 0x827309E4;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82730428) {
	__imp__sub_82730428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827309E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827309F0;
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f29.u64);
	// stfd f30,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82730acc
	if (!cr6.gt) goto loc_82730ACC;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
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
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,76(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dbae8
	ctx.lr = 0x82730A60;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lfs f1,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,29964(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 29964);
	f31.f64 = double(temp.f32);
	// fmuls f30,f0,f31
	f30.f64 = double(float(f0.f64 * f31.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x82730A78;
	sub_823DBBC8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,30712(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30712);
	f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f29,f13,f31
	f29.f64 = double(float(ctx.f13.f64 * f31.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82730A94;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r30,-32125
	r30.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-7372(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -7372);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(f0.f64 * f30.f64));
	// fmuls f31,f11,f31
	f31.f64 = double(float(ctx.f11.f64 * f31.f64));
	// bl 0x82235e30
	ctx.lr = 0x82730AB0;
	sub_82235E30(ctx, base);
	// lfs f0,-7372(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -7372);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmuls f1,f0,f29
	ctx.f1.f64 = double(float(f0.f64 * f29.f64));
	// bl 0x82204cb8
	ctx.lr = 0x82730AC0;
	sub_82204CB8(ctx, base);
	// lfs f0,-7372(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -7372);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// b 0x82730c6c
	goto loc_82730C6C;
loc_82730ACC:
	// lvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vmulfp128 v57,v1,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v58.f32)));
	// vspltisw128 v56,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_set1_epi32(int(0x0)));
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r5,112(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
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
	// lis r28,-32111
	r28.s64 = -2104426496;
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// lis r27,-32125
	r27.s64 = -2105344000;
	// ori r30,r6,64167
	r30.u64 = ctx.r6.u64 | 64167;
	// vpermwi128 v54,v55,234
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x15));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// vpermwi128 v53,v55,186
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x45));
	// vpermwi128 v52,v55,174
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x51));
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f10,68(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// stfs f12,72(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stvx128 v54,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-21616(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21616);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// mulld r9,r9,r30
	ctx.r9.s64 = ctx.r9.s64 * r30.s64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f31,14348(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14348);
	f31.f64 = double(temp.f32);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rldicl r7,r10,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// fdivs f6,f1,f7
	ctx.f6.f64 = double(float(ctx.f1.f64 / ctx.f7.f64));
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// lfs f0,-7372(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -7372);
	f0.f64 = double(temp.f32);
	// clrlwi r4,r6,9
	ctx.r4.u64 = ctx.r6.u32 & 0x7FFFFF;
	// lfs f5,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fneg f30,f6
	f30.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// fmuls f1,f2,f5
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f5.f64));
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// fmuls f1,f13,f31
	ctx.f1.f64 = double(float(ctx.f13.f64 * f31.f64));
	// bl 0x82235e30
	ctx.lr = 0x82730BBC;
	sub_82235E30(ctx, base);
	// lwz r11,-21616(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21616);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r9,r9,r30
	ctx.r9.s64 = ctx.r9.s64 * r30.s64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rldicl r7,r10,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// lfs f12,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-7372(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -7372);
	f0.f64 = double(temp.f32);
	// clrlwi r4,r6,9
	ctx.r4.u64 = ctx.r6.u32 & 0x7FFFFF;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmuls f6,f7,f30
	ctx.f6.f64 = double(float(ctx.f7.f64 * f30.f64));
	// fmuls f1,f6,f31
	ctx.f1.f64 = double(float(ctx.f6.f64 * f31.f64));
	// bl 0x82204cb8
	ctx.lr = 0x82730C18;
	sub_82204CB8(ctx, base);
	// lwz r11,-21616(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21616);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r9,r9,r30
	ctx.r9.s64 = ctx.r9.s64 * r30.s64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rldicl r7,r10,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// lfs f5,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lfs f0,-7372(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -7372);
	f0.f64 = double(temp.f32);
	// clrlwi r4,r6,9
	ctx.r4.u64 = ctx.r6.u32 & 0x7FFFFF;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmuls f1,f2,f5
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f5.f64));
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// fmuls f1,f13,f31
	ctx.f1.f64 = double(float(ctx.f13.f64 * f31.f64));
loc_82730C6C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235ee0
	ctx.lr = 0x82730C74;
	sub_82235EE0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_827309E8) {
	__imp__sub_827309E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82730C88) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82730C90;
	// stfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// li r24,0
	r24.s64 = 0;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lfs f31,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f31.f64 = double(temp.f32);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82730cd4
	if (cr6.eq) goto loc_82730CD4;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82730cd8
	if (cr6.eq) goto loc_82730CD8;
loc_82730CD4:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_82730CD8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82730cec
	if (cr6.eq) goto loc_82730CEC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82730CEC:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// mr r23,r24
	r23.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82730ebc
	if (!cr6.gt) goto loc_82730EBC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r24
	r30.u64 = r24.u64;
	// mr r25,r24
	r25.u64 = r24.u64;
	// li r22,-1
	r22.s64 = -1;
	// lfs f30,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f30.f64 = double(temp.f32);
loc_82730D10:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lbz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82730ea4
	if (cr6.eq) goto loc_82730EA4;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// addi r10,r11,24
	ctx.r10.s64 = r11.s64 + 24;
	// lfs f0,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,24(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// addi r26,r10,1
	r26.s64 = ctx.r10.s64 + 1;
	// lwz r29,16(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// ble cr6,0x82730d5c
	if (!cr6.gt) goto loc_82730D5C;
	// mr r26,r24
	r26.u64 = r24.u64;
loc_82730D5C:
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// mr r27,r24
	r27.u64 = r24.u64;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// mullw r7,r11,r8
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// mullw r6,r7,r9
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82730dd8
	if (cr6.eq) goto loc_82730DD8;
	// mr r28,r24
	r28.u64 = r24.u64;
loc_82730D8C:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82730428
	ctx.lr = 0x82730DA4;
	sub_82730428(ctx, base);
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r7,104(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r29,r29,144
	r29.s64 = r29.s64 + 144;
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// mullw r6,r8,r7
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r28,r28,80
	r28.s64 = r28.s64 + 80;
	// cmplw cr6,r27,r5
	cr6.compare<uint32_t>(r27.u32, ctx.r5.u32, xer);
	// blt cr6,0x82730d8c
	if (cr6.lt) goto loc_82730D8C;
loc_82730DD8:
	// add r10,r25,r26
	ctx.r10.u64 = r25.u64 + r26.u64;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// rlwinm r29,r10,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r29,r11
	ctx.r9.u64 = r29.u64 + r11.u64;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82730DFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r6,r29,r11
	ctx.r6.u64 = r29.u64 + r11.u64;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lbz r5,6(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82730e1c
	if (cr6.eq) goto loc_82730E1C;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x82730e20
	goto loc_82730E20;
loc_82730E1C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82730E20:
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r7,104(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// mullw r5,r8,r6
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r6.s32);
	// lwz r4,16(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mullw r11,r5,r7
	r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r5,r11,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x8244d5c0
	ctx.lr = 0x82730E54;
	sub_8244D5C0(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r10,r29,r11
	ctx.r10.u64 = r29.u64 + r11.u64;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82730E70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lfs f0,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82730ea0
	if (!cr6.gt) goto loc_82730EA0;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// stb r24,20(r11)
	PPC_STORE_U8(r11.u32 + 20, r24.u8);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r10,r30,r11
	ctx.r10.u64 = r30.u64 + r11.u64;
	// stw r22,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, r22.u32);
	// b 0x82730ea4
	goto loc_82730EA4;
loc_82730EA0:
	// stw r26,36(r11)
	PPC_STORE_U32(r11.u32 + 36, r26.u32);
loc_82730EA4:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r25,r25,10
	r25.s64 = r25.s64 + 10;
	// addi r30,r30,40
	r30.s64 = r30.s64 + 40;
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// blt cr6,0x82730d10
	if (cr6.lt) goto loc_82730D10;
loc_82730EBC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82730C88) {
	__imp__sub_82730C88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82730ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82730ECC) {
	__imp__sub_82730ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82730ED0) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82730ED8;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d4
	ctx.lr = 0x82730EE0;
	// li r12,-240
	r12.s64 = -240;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-224
	r12.s64 = -224;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// li r25,0
	r25.s64 = 0;
	// vor128 v125,v3,v3
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
	// ori r29,r10,64167
	r29.u64 = ctx.r10.u64 | 64167;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lis r26,-32111
	r26.s64 = -2104426496;
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// mullw. r8,r28,r9
	ctx.r8.s64 = int64_t(r28.s32) * int64_t(ctx.r9.s32);
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82730fb8
	if (cr0.eq) goto loc_82730FB8;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// lfs f0,-3884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3884);
	f0.f64 = double(temp.f32);
loc_82730F44:
	// lwz r11,-21616(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r7,r7,r29
	ctx.r7.s64 = ctx.r7.s64 * r29.s64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rldicl r4,r8,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r6,84(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// lwz r7,112(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// std r7,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r4,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r4.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fmuls f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// stfsx f6,r6,r9
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r9.u32, temp.u32);
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// mullw r11,r28,r3
	r11.s64 = int64_t(r28.s32) * int64_t(ctx.r3.s32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82730f44
	if (cr6.lt) goto loc_82730F44;
loc_82730FB8:
	// lwz r11,-21616(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r18,16
	r18.s64 = 16;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f27,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f27.f64 = double(temp.f32);
	// lfs f28,14348(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14348);
	f28.f64 = double(temp.f32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r8,r6,r29
	ctx.r8.s64 = ctx.r6.s64 * r29.s64;
	// lfs f31,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f31.f64 = double(temp.f32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rldicl r3,r10,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827312dc
	if (!cr6.gt) goto loc_827312DC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f8,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f8.f64 = double(temp.f32);
loc_8273100C:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827312cc
	if (cr6.eq) goto loc_827312CC;
	// mr r27,r25
	r27.u64 = r25.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
loc_82731024:
	// addi r30,r10,1
	r30.s64 = ctx.r10.s64 + 1;
	// twllei r11,0
	// divwu r10,r30,r11
	ctx.r10.u32 = r30.u32 / r11.u32;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// subf r11,r7,r30
	r11.s64 = r30.s64 - ctx.r7.s64;
	// ble cr6,0x827312b4
	if (!cr6.gt) goto loc_827312B4;
	// clrldi r10,r9,32
	ctx.r10.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// extsw r7,r28
	ctx.r7.s64 = r28.s32;
	// std r10,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f0,120(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// std r7,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// add r4,r11,r17
	ctx.r4.u64 = r11.u64 + r17.u64;
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// mr r11,r27
	r11.u64 = r27.u64;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f10,f31,f10
	ctx.f10.f64 = double(float(f31.f64 / ctx.f10.f64));
loc_8273107C:
	// lwz r10,-21616(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mulld r6,r6,r29
	ctx.r6.s64 = ctx.r6.s64 * r29.s64;
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// rldicl r7,r7,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r7,112(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// std r7,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// lfd f0,136(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f12,f31,f13
	ctx.f12.f64 = double(float(f31.f64 / ctx.f13.f64));
	// fmuls f0,f12,f9
	f0.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// beq cr6,0x827310e8
	if (cr6.eq) goto loc_827310E8;
	// rotlwi r10,r6,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// clrlwi r6,r10,9
	ctx.r6.u64 = ctx.r10.u32 & 0x7FFFFF;
	// std r6,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// lfd f12,144(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f7,f11
	ctx.f7.f64 = double(float(ctx.f11.f64));
	// fmsubs f6,f7,f28,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * f28.f64 - ctx.f8.f64));
	// fdivs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 / ctx.f13.f64));
	// fadds f0,f5,f0
	f0.f64 = double(float(ctx.f5.f64 + f0.f64));
loc_827310E8:
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// std r10,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r10.u64);
	// fsubs f0,f31,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - f0.f64));
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,112
	r23.s64 = ctx.r1.s64 + 112;
	// addi r24,r1,112
	r24.s64 = ctx.r1.s64 + 112;
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,104(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// lwz r21,80(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r22,r1,160
	r22.s64 = ctx.r1.s64 + 160;
	// mullw r20,r7,r28
	r20.s64 = int64_t(ctx.r7.s32) * int64_t(r28.s32);
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// divwu r19,r11,r20
	r19.u32 = r11.u32 / r20.u32;
	// mullw r16,r7,r9
	r16.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lfd f13,152(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fsubs f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 - f0.f64));
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mullw r7,r19,r20
	ctx.r7.s64 = int64_t(r19.s32) * int64_t(r20.s32);
	// frsp f7,f12
	ctx.f7.f64 = double(float(ctx.f12.f64));
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// subf r7,r7,r11
	ctx.r7.s64 = r11.s64 - ctx.r7.s64;
	// mullw r10,r16,r28
	ctx.r10.s64 = int64_t(r16.s32) * int64_t(r28.s32);
	// fmuls f13,f7,f10
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvlx128 v58,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v10,v63,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// lvlx128 v61,r0,r23
	temp.u32 = r23.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fsubs f5,f31,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f5.f64 = double(float(f31.f64 - ctx.f13.f64));
	// stfs f5,112(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvlx128 v59,r0,r24
	temp.u32 = r24.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v11,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// fadds f6,f7,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 + f31.f64));
	// vmaddfp v0,v0,v11,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// fmuls f12,f6,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// vmulfp128 v12,v127,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v60.f32)));
	// addi r23,r1,112
	r23.s64 = ctx.r1.s64 + 112;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stfs f12,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// rlwinm r6,r10,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lvlx128 v56,r0,r23
	temp.u32 = r23.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v55,v56,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vmaddfp v8,v0,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// fsubs f4,f31,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f4.f64 = double(float(f31.f64 - ctx.f12.f64));
	// stfs f4,112(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vsubfp128 v53,v0,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v127.f32)));
	// lvlx128 v54,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// twllei r20,0
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stvx128 v8,r6,r21
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r4
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v7,v52,v55
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v55.f32)));
	// vspltw128 v9,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// stvx128 v53,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f3,f13,f13
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// vmaddfp v0,v6,v9,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// lfs f13,164(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f2,f13,f13,f3
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f3.f64));
	// vsubfp128 v51,v0,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v127.f32)));
	// fmadds f1,f12,f12,f2
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f2.f64));
	// fsqrts f7,f1
	ctx.f7.f64 = double(float(sqrt(ctx.f1.f64)));
	// stvx128 v51,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,184(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f13,f13
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f5,f12,f12,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fmadds f4,f11,f11,f5
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f5.f64));
	// fsqrts f3,f4
	ctx.f3.f64 = double(float(sqrt(ctx.f4.f64)));
	// fdivs f2,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 / ctx.f3.f64));
	// fmuls f0,f2,f0
	f0.f64 = double(float(ctx.f2.f64 * f0.f64));
	// bne cr6,0x82731238
	if (!cr6.eq) goto loc_82731238;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_82731238:
	// fsel f0,f0,f0,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f27.f64;
	// addi r24,r1,112
	r24.s64 = ctx.r1.s64 + 112;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r23,r1,100
	r23.s64 = ctx.r1.s64 + 100;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mullw r7,r10,r28
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r28.s32);
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// divwu r22,r11,r7
	r22.u32 = r11.u32 / ctx.r7.u32;
	// twllei r7,0
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// fsel f0,f13,f31,f0
	f0.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : f0.f64;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mullw r7,r22,r7
	ctx.r7.s64 = int64_t(r22.s32) * int64_t(ctx.r7.s32);
	// fsubs f12,f31,f0
	ctx.f12.f64 = double(float(f31.f64 - f0.f64));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// subf r7,r7,r11
	ctx.r7.s64 = r11.s64 - ctx.r7.s64;
	// mullw r10,r10,r28
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r28.s32);
	// lvlx128 v50,r0,r23
	temp.u32 = r23.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// cmpw cr6,r8,r28
	cr6.compare<int32_t>(ctx.r8.s32, r28.s32, xer);
	// lvlx128 v49,r0,r24
	temp.u32 = r24.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r7,r10,r6
	ctx.r7.u64 = ctx.r10.u64 + ctx.r6.u64;
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vmulfp128 v12,v127,v48
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v48.f32)));
	// vmaddfp v11,v0,v13,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r7,r18
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8273107c
	if (cr6.lt) goto loc_8273107C;
loc_827312B4:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// add r27,r27,r28
	r27.u64 = r27.u64 + r28.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82731024
	if (cr6.lt) goto loc_82731024;
loc_827312CC:
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// blt cr6,0x8273100c
	if (cr6.lt) goto loc_8273100C;
loc_827312DC:
	// lwz r9,116(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// mr r21,r25
	r21.u64 = r25.u64;
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82731314
	if (cr6.eq) goto loc_82731314;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
loc_827312F8:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82731314
	if (cr6.eq) goto loc_82731314;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x827312f8
	if (cr6.lt) goto loc_827312F8;
loc_82731314:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82731320
	if (!cr6.eq) goto loc_82731320;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82731320:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r24,r25
	r24.u64 = r25.u64;
	// rlwinm r15,r8,3,0,28
	r15.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r15,r11
	ctx.r7.u64 = r15.u64 + r11.u64;
	// stfs f27,24(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r7.u32 + 24, temp.u32);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r6,r15,r11
	ctx.r6.u64 = r15.u64 + r11.u64;
	// stb r9,20(r6)
	PPC_STORE_U8(ctx.r6.u32 + 20, ctx.r9.u8);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r4,r15,r11
	ctx.r4.u64 = r15.u64 + r11.u64;
	// stw r5,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r5.u32);
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r15,r11
	r11.u64 = r15.u64 + r11.u64;
	// lwz r16,16(r11)
	r16.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// ble cr6,0x827318c8
	if (!cr6.gt) goto loc_827318C8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// li r19,112
	r19.s64 = 112;
	// li r20,64
	r20.s64 = 64;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// lfs f29,-6176(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6176);
	f29.f64 = double(temp.f32);
	// lfs f30,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f30.f64 = double(temp.f32);
	// b 0x82731398
	goto loc_82731398;
loc_82731394:
	// li r25,0
	r25.s64 = 0;
loc_82731398:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827318b8
	if (!cr6.gt) goto loc_827318B8;
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r25.u32);
loc_827313AC:
	// li r14,0
	r14.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82731894
	if (!cr6.gt) goto loc_82731894;
	// rlwinm r11,r21,3,0,28
	r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r21,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r21,r11
	r11.u64 = r21.u64 + r11.u64;
	// add r10,r21,r10
	ctx.r10.u64 = r21.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r22,r10,4,0,27
	r22.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r11,r16
	r30.u64 = r11.u64 + r16.u64;
loc_827313D4:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82731888
	if (cr6.eq) goto loc_82731888;
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r25,r24,-1
	r25.s64 = r24.s64 + -1;
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// vor128 v2,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mullw r6,r9,r28
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(r28.s32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// vor128 v1,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// add r27,r7,r14
	r27.u64 = ctx.r7.u64 + r14.u64;
	// mullw r5,r9,r24
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(r24.s32);
	// divwu r4,r27,r6
	ctx.r4.u32 = r27.u32 / ctx.r6.u32;
	// mullw r11,r5,r28
	r11.s64 = int64_t(ctx.r5.s32) * int64_t(r28.s32);
	// mullw r3,r4,r6
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// subf r10,r3,r27
	ctx.r10.s64 = r27.s64 - ctx.r3.s64;
	// mullw r9,r25,r9
	ctx.r9.s64 = int64_t(r25.s32) * int64_t(ctx.r9.s32);
	// twllei r6,0
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// mullw r7,r9,r28
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r28.s32);
	// rlwinm r9,r6,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 + ctx.r10.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r5,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r17
	ctx.r6.u64 = r17.u64;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// stfs f0,8(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f31,12(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,48(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 48, temp.u32);
	// stfs f10,52(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 52, temp.u32);
	// stfs f11,56(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 56, temp.u32);
	// stfs f31,60(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 60, temp.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lfs f8,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,96(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 96, temp.u32);
	// stfs f7,100(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 100, temp.u32);
	// stfs f8,104(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r30.u32 + 104, temp.u32);
	// stfs f31,108(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 108, temp.u32);
	// stvx128 v126,r30,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r30,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r30,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8272fc98
	ctx.lr = 0x827314C4;
	sub_8272FC98(ctx, base);
	// lwz r11,-21616(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r9,r3,r29
	ctx.r9.s64 = ctx.r3.s64 * r29.s64;
	// lbz r23,96(r1)
	r23.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rldicl r8,r10,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rotlwi r7,r10,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r11,-21616(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// clrlwi r5,r7,9
	ctx.r5.u64 = ctx.r7.u32 & 0x7FFFFF;
	// std r5,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r5.u64);
	// lfd f5,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r9,r4,r29
	ctx.r9.s64 = ctx.r4.s64 * r29.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// fmuls f2,f3,f28
	ctx.f2.f64 = double(float(ctx.f3.f64 * f28.f64));
	// rldicl r9,r10,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rotlwi r7,r10,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,-21616(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// clrlwi r5,r7,9
	ctx.r5.u64 = ctx.r7.u32 & 0x7FFFFF;
	// std r5,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r5.u64);
	// lfd f1,144(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r9,r4,r29
	ctx.r9.s64 = ctx.r4.s64 * r29.s64;
	// fmuls f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 * f28.f64));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// rotlwi r9,r3,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lfs f7,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f7.f64 = double(temp.f32);
	// clrlwi r7,r9,9
	ctx.r7.u64 = ctx.r9.u32 & 0x7FFFFF;
	// std r7,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// lfd f3,136(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// lfs f6,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f2,f7,f6
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f7.f64 + ctx.f6.f64));
	// lfs f11,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// lfs f10,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f8.f64 = double(temp.f32);
	// stfs f5,184(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f0,f1,f9
	f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// fmadds f4,f12,f10,f8
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f4,180(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fmadds f13,f0,f28,f11
	ctx.f13.f64 = double(float(f0.f64 * f28.f64 + ctx.f11.f64));
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// beq cr6,0x827315c8
	if (cr6.eq) goto loc_827315C8;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f0,-7372(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -7372);
	f0.f64 = double(temp.f32);
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// b 0x827315e8
	goto loc_827315E8;
loc_827315C8:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f30
	ctx.f1.f64 = double(float(f0.f64 - f30.f64));
	// fcmpu cr6,f1,f27
	cr6.compare(ctx.f1.f64, f27.f64);
	// bge cr6,0x827315e8
	if (!cr6.lt) goto loc_827315E8;
	// li r23,1
	r23.s64 = 1;
	// stb r23,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r23.u8);
loc_827315E8:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r11,r15,r11
	r11.u64 = PPC_LOAD_U32(r15.u32 + r11.u32);
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r4,r11,r22
	ctx.r4.u64 = r11.u64 + r22.u64;
	// bl 0x827309e8
	ctx.lr = 0x82731608;
	sub_827309E8(ctx, base);
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82730230
	ctx.lr = 0x8273161C;
	sub_82730230(ctx, base);
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// mullw r5,r9,r28
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(r28.s32);
	// vor128 v2,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vor128 v1,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// divwu r11,r27,r5
	r11.u32 = r27.u32 / ctx.r5.u32;
	// twllei r5,0
	// mullw r5,r11,r5
	ctx.r5.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// mullw r10,r9,r25
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(r25.s32);
	// subf r11,r5,r27
	r11.s64 = r27.s64 - ctx.r5.s64;
	// mullw r10,r10,r28
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r28.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// mullw r9,r9,r24
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r24.s32);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r5,r9,r28
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(r28.s32);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// add r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 + r11.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// mr r6,r17
	ctx.r6.u64 = r17.u64;
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stfs f0,8(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// addi r23,r21,1
	r23.s64 = r21.s64 + 1;
	// stfs f31,12(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// addi r22,r22,80
	r22.s64 = r22.s64 + 80;
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// stfs f10,52(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 52, temp.u32);
	// stfs f11,56(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 56, temp.u32);
	// stfs f31,60(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 60, temp.u32);
	// stfs f9,48(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 48, temp.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f8,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,96(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 96, temp.u32);
	// stfs f7,100(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 100, temp.u32);
	// stfs f8,104(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r30.u32 + 104, temp.u32);
	// stfs f31,108(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 108, temp.u32);
	// stvx128 v126,r30,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r30,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r30,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8272fc98
	ctx.lr = 0x8273170C;
	sub_8272FC98(ctx, base);
	// lwz r11,-21616(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r10,r3,r29
	ctx.r10.s64 = ctx.r3.s64 * r29.s64;
	// lbz r25,96(r1)
	r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rldicl r8,r10,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// clrlwi r4,r6,9
	ctx.r4.u64 = ctx.r6.u32 & 0x7FFFFF;
	// lwz r11,-21616(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// lfd f5,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r10,r3,r29
	ctx.r10.s64 = ctx.r3.s64 * r29.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// fmuls f2,f3,f28
	ctx.f2.f64 = double(float(ctx.f3.f64 * f28.f64));
	// rldicl r9,r10,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rotlwi r7,r10,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// clrlwi r5,r7,9
	ctx.r5.u64 = ctx.r7.u32 & 0x7FFFFF;
	// std r5,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r5.u64);
	// lwz r11,-21616(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21616);
	// lfd f1,120(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r10,r4,r29
	ctx.r10.s64 = ctx.r4.s64 * r29.s64;
	// frsp f9,f0
	ctx.f9.f64 = double(float(f0.f64));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// fmuls f3,f9,f28
	ctx.f3.f64 = double(float(ctx.f9.f64 * f28.f64));
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// rotlwi r9,r3,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lfs f4,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f4.f64 = double(temp.f32);
	// lfs f12,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi r7,r9,9
	ctx.r7.u64 = ctx.r9.u32 & 0x7FFFFF;
	// lfs f11,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// std r7,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r7.u64);
	// lfd f7,160(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// lfs f10,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// lfs f8,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f5,f4
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// fmadds f13,f1,f28,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * f28.f64 + ctx.f13.f64));
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fmadds f2,f2,f8,f12
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + ctx.f12.f64));
	// stfs f2,200(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// fmadds f0,f3,f10,f11
	f0.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f11.f64));
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// beq cr6,0x82731814
	if (cr6.eq) goto loc_82731814;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f0,-7372(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -7372);
	f0.f64 = double(temp.f32);
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// b 0x82731834
	goto loc_82731834;
loc_82731814:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f30
	ctx.f1.f64 = double(float(f0.f64 - f30.f64));
	// fcmpu cr6,f1,f27
	cr6.compare(ctx.f1.f64, f27.f64);
	// bge cr6,0x82731834
	if (!cr6.lt) goto loc_82731834;
	// li r25,1
	r25.s64 = 1;
	// stb r25,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r25.u8);
loc_82731834:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r11,r15,r11
	r11.u64 = PPC_LOAD_U32(r15.u32 + r11.u32);
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r4,r11,r22
	ctx.r4.u64 = r11.u64 + r22.u64;
	// bl 0x827309e8
	ctx.lr = 0x82731854;
	sub_827309E8(ctx, base);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// rlwinm r11,r27,2,0,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfsx f0,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 * f29.f64));
	// stfsx f13,r11,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, temp.u32);
	// bl 0x82730230
	ctx.lr = 0x8273187C;
	sub_82730230(ctx, base);
	// addi r21,r23,1
	r21.s64 = r23.s64 + 1;
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// addi r22,r22,80
	r22.s64 = r22.s64 + 80;
loc_82731888:
	// addi r14,r14,1
	r14.s64 = r14.s64 + 1;
	// cmpw cr6,r14,r28
	cr6.compare<int32_t>(r14.s32, r28.s32, xer);
	// blt cr6,0x827313d4
	if (cr6.lt) goto loc_827313D4;
loc_82731894:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r10,r28
	ctx.r8.u64 = ctx.r10.u64 + r28.u64;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// blt cr6,0x827313ac
	if (cr6.lt) goto loc_827313AC;
loc_827318B8:
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// cmplw cr6,r24,r11
	cr6.compare<uint32_t>(r24.u32, r11.u32, xer);
	// blt cr6,0x82731394
	if (cr6.lt) goto loc_82731394;
loc_827318C8:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// li r0,-240
	r0.s64 = -240;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-224
	r0.s64 = -224;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba20
	ctx.lr = 0x827318EC;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82730ED0) {
	__imp__sub_82730ED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827318F0) {
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
	ctx.lr = 0x827318F8;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,-232
	ctx.r4.s64 = ctx.r10.s64 + -232;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x82731918;
	sub_821CA540(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r5,r9,5276
	ctx.r5.s64 = ctx.r9.s64 + 5276;
	// addi r4,r8,-16664
	ctx.r4.s64 = ctx.r8.s64 + -16664;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82731938;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82731cc4
	if (cr6.eq) goto loc_82731CC4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x8273194C;
	sub_821D1CD0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-16676
	ctx.r4.s64 = r11.s64 + -16676;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x82731960;
	sub_821CF7B8(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16692
	r31.s64 = r11.s64 + -16692;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731978;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82731994
	if (cr6.eq) goto loc_82731994;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731990;
	sub_821D0938(ctx, base);
	// stfs f1,40(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 40, temp.u32);
loc_82731994:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16720
	r31.s64 = r11.s64 + -16720;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x827319AC;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827319c8
	if (cr6.eq) goto loc_827319C8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x827319C4;
	sub_821D0938(ctx, base);
	// stfs f1,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 32, temp.u32);
loc_827319C8:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16748
	r31.s64 = r11.s64 + -16748;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x827319E0;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827319fc
	if (cr6.eq) goto loc_827319FC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x827319F8;
	sub_821D0938(ctx, base);
	// stfs f1,36(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 36, temp.u32);
loc_827319FC:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16768
	r31.s64 = r11.s64 + -16768;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731A14;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731a34
	if (cr6.eq) goto loc_82731A34;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731A2C;
	sub_821D0938(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stfs f1,-7372(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -7372, temp.u32);
loc_82731A34:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16784
	r31.s64 = r11.s64 + -16784;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731A4C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731a68
	if (cr6.eq) goto loc_82731A68;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731A64;
	sub_821D0938(ctx, base);
	// stfs f1,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
loc_82731A68:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16796
	r31.s64 = r11.s64 + -16796;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731A80;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731a9c
	if (cr6.eq) goto loc_82731A9C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731A98;
	sub_821D0938(ctx, base);
	// stfs f1,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
loc_82731A9C:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16924
	r31.s64 = r11.s64 + -16924;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731AB4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731ad0
	if (cr6.eq) goto loc_82731AD0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731ACC;
	sub_821D0938(ctx, base);
	// stfs f1,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
loc_82731AD0:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16944
	r31.s64 = r11.s64 + -16944;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731AE8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731b04
	if (cr6.eq) goto loc_82731B04;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731B00;
	sub_821D0938(ctx, base);
	// stfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 20, temp.u32);
loc_82731B04:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16964
	r31.s64 = r11.s64 + -16964;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731B1C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731b38
	if (cr6.eq) goto loc_82731B38;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731B34;
	sub_821D0938(ctx, base);
	// stfs f1,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 24, temp.u32);
loc_82731B38:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16992
	r31.s64 = r11.s64 + -16992;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731B50;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731b6c
	if (cr6.eq) goto loc_82731B6C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731B68;
	sub_821D0938(ctx, base);
	// stfs f1,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 28, temp.u32);
loc_82731B6C:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16812
	r31.s64 = r11.s64 + -16812;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731B84;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731ba4
	if (cr6.eq) goto loc_82731BA4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r11,-7360
	ctx.r5.s64 = r11.s64 + -7360;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0a08
	ctx.lr = 0x82731BA4;
	sub_821D0A08(ctx, base);
loc_82731BA4:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16840
	r31.s64 = r11.s64 + -16840;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731BBC;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731bdc
	if (cr6.eq) goto loc_82731BDC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731BD4;
	sub_821D0938(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stfs f1,-7368(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -7368, temp.u32);
loc_82731BDC:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16860
	r31.s64 = r11.s64 + -16860;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731BF4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731c14
	if (cr6.eq) goto loc_82731C14;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731C0C;
	sub_821D0938(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stfs f1,-7364(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -7364, temp.u32);
loc_82731C14:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16876
	r31.s64 = r11.s64 + -16876;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731C2C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731c48
	if (cr6.eq) goto loc_82731C48;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r30,48
	ctx.r5.s64 = r30.s64 + 48;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0a08
	ctx.lr = 0x82731C48;
	sub_821D0A08(ctx, base);
loc_82731C48:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16888
	r31.s64 = r11.s64 + -16888;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731C60;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731c7c
	if (cr6.eq) goto loc_82731C7C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r30,64
	ctx.r5.s64 = r30.s64 + 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0a08
	ctx.lr = 0x82731C7C;
	sub_821D0A08(ctx, base);
loc_82731C7C:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-16896
	r31.s64 = r11.s64 + -16896;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82731C94;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82731cb0
	if (cr6.eq) goto loc_82731CB0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x82731CAC;
	sub_821D0938(ctx, base);
	// stfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
loc_82731CB0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x82731CB8;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_82731CC4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82731CCC;
	sub_821C9A90(ctx, base);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_827318F0) {
	__imp__sub_827318F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82731CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82731CD4) {
	__imp__sub_82731CD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82731CD8) {
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
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82731CE0;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,160(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827322c4
	if (!cr6.eq) goto loc_827322C4;
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// stb r11,160(r30)
	PPC_STORE_U8(r30.u32 + 160, r11.u8);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r10,-16608
	ctx.r4.s64 = ctx.r10.s64 + -16608;
	// bl 0x82735660
	ctx.lr = 0x82731D28;
	sub_82735660(ctx, base);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r8,-16620
	ctx.r4.s64 = ctx.r8.s64 + -16620;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v126,r0,r9
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82731D44;
	sub_82735660(ctx, base);
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r4,-16632
	ctx.r4.s64 = ctx.r4.s64 + -16632;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82731D68;
	sub_82735660(ctx, base);
	// addi r11,r1,272
	r11.s64 = ctx.r1.s64 + 272;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r10,-16644
	ctx.r4.s64 = ctx.r10.s64 + -16644;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v125,r0,r11
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82731D84;
	sub_82735660(ctx, base);
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r31,48
	r31.s64 = 48;
	// li r10,16
	ctx.r10.s64 = 16;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// addi r7,r8,2384
	ctx.r7.s64 = ctx.r8.s64 + 2384;
	// lvx128 v56,r11,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r31
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v50,v56,v56
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// lvx128 v52,r11,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v48,v55,v55
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vor128 v44,v52,v52
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// addi r4,r6,2352
	ctx.r4.s64 = ctx.r6.s64 + 2352;
	// vor128 v46,v54,v54
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vmrghw128 v53,v55,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v49,v52,v54
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrglw128 v51,v55,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vand128 v61,v126,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v45,v48,v50
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vand128 v60,v127,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v47,v52,v54
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// vmrghw128 v42,v44,v46
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v58,v62,v61
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vmrglw128 v43,v48,v50
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vor128 v41,v56,v56
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vmrglw128 v38,v53,v49
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vor128 v39,v55,v55
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vmrghw128 v34,v53,v49
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vor128 v57,v62,v60
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vmrghw128 v36,v51,v47
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrglw128 v40,v44,v46
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// lvx128 v33,r0,r5
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v32,v45,v42
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vor128 v37,v54,v54
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vor128 v35,v55,v55
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vmsum4fp128 v60,v58,v38
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v38.f32), 0xFF));
	// vand128 v59,v125,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v56,v45,v42
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v61,v43,v40
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmsum4fp128 v55,v58,v36
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v36.f32), 0xFF));
	// vmsum4fp128 v54,v58,v34
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v34.f32), 0xFF));
	// vmrghw128 v53,v39,v41
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrglw128 v52,v39,v41
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmsum4fp128 v51,v57,v32
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v32.f32), 0xFF));
	// vor128 v50,v44,v44
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_load_si128((simde__m128i*)v44.u8));
	// vand128 v49,v33,v63
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v48,v41,v41
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vor128 v46,v44,v44
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_load_si128((simde__m128i*)v44.u8));
	// vmrghw128 v47,v50,v37
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vor128 v44,v37,v37
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_load_si128((simde__m128i*)v37.u8));
	// vmrghw128 v45,v35,v48
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrglw128 v43,v50,v37
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vor128 v41,v62,v59
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmrglw128 v38,v35,v48
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vor128 v39,v62,v49
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// vmrglw128 v36,v53,v47
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmsum4fp128 v37,v57,v61
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// vmrghw128 v42,v46,v44
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmsum4fp128 v35,v57,v56
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32), 0xFF));
	// vmrglw128 v40,v46,v44
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// vmrghw128 v34,v52,v43
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// vmrghw128 v33,v53,v47
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmsum4fp128 v61,v41,v36
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v36.f32), 0xFF));
	// vmrglw128 v32,v45,v42
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// vmrghw128 v59,v45,v42
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// addi r8,r1,368
	ctx.r8.s64 = ctx.r1.s64 + 368;
	// vmrghw128 v63,v38,v40
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmsum4fp128 v56,v41,v34
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v34.f32), 0xFF));
	// vmrghw128 v52,v51,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmsum4fp128 v53,v41,v33
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v33.f32), 0xFF));
	// vmsum4fp128 v51,v39,v32
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v32.f32), 0xFF));
	// vmrghw128 v50,v60,v58
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmsum4fp128 v48,v39,v59
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// vmsum4fp128 v49,v39,v63
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// vmrghw128 v47,v54,v55
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r6,r1,384
	ctx.r6.s64 = ctx.r1.s64 + 384;
	// addi r5,r1,400
	ctx.r5.s64 = ctx.r1.s64 + 400;
	// lwz r11,160(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// vmrghw128 v62,v47,v50
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v46,v35,v37
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v45,v61,v41
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// vmrghw128 v44,v46,v52
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// vmrghw128 v43,v53,v56
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v42,v51,v39
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v41,v48,v49
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v61,v43,v45
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// stvx128 v44,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v63,v41,v42
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82731f30
	if (!cr6.eq) goto loc_82731F30;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x82731f34
	goto loc_82731F34;
loc_82731F30:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82731F34:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82731f9c
	if (cr6.eq) goto loc_82731F9C;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82731f4c
	if (!cr6.eq) goto loc_82731F4C;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x82731f50
	goto loc_82731F50;
loc_82731F4C:
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82731F50:
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82731f60
	if (!cr6.eq) goto loc_82731F60;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x82731f64
	goto loc_82731F64;
loc_82731F60:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82731F64:
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82731f74
	if (!cr6.eq) goto loc_82731F74;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x82731f78
	goto loc_82731F78;
loc_82731F74:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82731F78:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	f0.f64 = double(temp.f32);
	// lfs f13,276(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,280(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 280);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v125,r0,r10
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82731fa0
	goto loc_82731FA0;
loc_82731F9C:
	// vspltisw128 v125,0
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_set1_epi32(int(0x0)));
loc_82731FA0:
	// vsubfp128 v40,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v40.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// vsubfp128 v39,v61,v63
	simde_mm_store_ps(v39.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2528
	ctx.r9.s64 = r11.s64 + 2528;
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r7,-31648
	ctx.r5.s64 = ctx.r7.s64 + -31648;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,-31664
	ctx.r4.s64 = ctx.r6.s64 + -31664;
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32111
	ctx.r3.s64 = -2104426496;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// vpermwi128 v38,v40,99
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x9C));
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v37,v39,135
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0x78));
	// lwz r4,-21608(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + -21608);
	// vpermwi128 v12,v40,135
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x78));
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// vpermwi128 v11,v39,99
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0x9C));
	// vmulfp128 v10,v37,v38
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v38.f32)));
	// vnmsubfp v9,v11,v12,v10
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v36,v9,v9
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v9.f32), 0xEF));
	// vrsqrtefp128 v35,v36
	simde_mm_store_ps(v35.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v36.f32))));
	// vor128 v8,v36,v36
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v36.u8));
	// vcmpeqfp128 v7,v35,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v6,v35,v35
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v35.u8));
	// vsel v0,v6,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v63,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v3,v8,v5,v13
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v2,v3,v4,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v127,v9,v2
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v2.f32)));
	// bl 0x8247fee0
	ctx.lr = 0x82732038;
	sub_8247FEE0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82732144
	if (cr6.eq) goto loc_82732144;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v34,r10,r31
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// vsubfp128 v126,v63,v34
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v126.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v34.f32)));
	// lwz r11,160(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 160);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stvx128 v126,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82732084
	if (!cr6.eq) goto loc_82732084;
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x82732088
	goto loc_82732088;
loc_82732084:
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82732088:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x827320b8
	if (cr6.eq) goto loc_827320B8;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x827320a0
	if (!cr6.eq) goto loc_827320A0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x827320a4
	goto loc_827320A4;
loc_827320A0:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_827320A4:
	// li r9,272
	ctx.r9.s64 = 272;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v33,r11,r9
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v126,v126,v33
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v126.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v33.f32)));
	// stvx128 v126,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827320B8:
	// vupkd3d128 v32,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v32 = vTemp;
	// addi r11,r1,336
	r11.s64 = ctx.r1.s64 + 336;
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// vpermwi128 v62,v32,234
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0x15));
	// vpermwi128 v61,v32,186
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0x45));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v32,174
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0x51));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r7,r8
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwz r4,160(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// bne cr6,0x82732104
	if (!cr6.eq) goto loc_82732104;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// b 0x82732108
	goto loc_82732108;
loc_82732104:
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
loc_82732108:
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r5,r9,-31616
	ctx.r5.s64 = ctx.r9.s64 + -31616;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82732128;
	sub_82202EC0(ctx, base);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8247a080
	ctx.lr = 0x82732134;
	sub_8247A080(ctx, base);
	// li r8,416
	ctx.r8.s64 = 416;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stvx128 v126,r28,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8247a838
	ctx.lr = 0x82732144;
	sub_8247A838(ctx, base);
loc_82732144:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// addi r5,r11,64
	ctx.r5.s64 = r11.s64 + 64;
	// lwz r7,160(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82732174
	if (cr6.eq) goto loc_82732174;
	// addi r5,r11,48
	ctx.r5.s64 = r11.s64 + 48;
	// bne cr6,0x8273217c
	if (!cr6.eq) goto loc_8273217C;
loc_82732174:
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// b 0x82732180
	goto loc_82732180;
loc_8273217C:
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
loc_82732180:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v3,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// vor128 v2,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lwz r11,-4964(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4964);
	// lwz r3,108(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// bl 0x82730ed0
	ctx.lr = 0x827321A0;
	sub_82730ED0(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lhz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-2288(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -2288);
	// bl 0x8258b6c8
	ctx.lr = 0x827321B4;
	sub_8258B6C8(ctx, base);
	// li r8,64
	ctx.r8.s64 = 64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r30,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r31,-32256
	r31.s64 = -2113929216;
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// addi r26,r1,416
	r26.s64 = ctx.r1.s64 + 416;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// lfs f0,3796(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r25,r1,432
	r25.s64 = ctx.r1.s64 + 432;
	// lfs f13,7444(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r3,-1
	ctx.r3.s64 = -1;
	// lfs f12,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f12.f64 = double(temp.f32);
	// sth r3,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r3.u16);
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// sth r11,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r11.u16);
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stb r11,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r11.u8);
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// fsubs f9,f0,f12
	ctx.f9.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fadds f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
	// lvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,2256
	ctx.r9.s64 = ctx.r9.s64 + 2256;
	// stvx128 v56,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,160
	r31.s64 = ctx.r1.s64 + 160;
	// addi r27,r1,176
	r27.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// sth r11,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r11.u16);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r11.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,2048
	ctx.r7.s64 = 2048;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-23452(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -23452);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// stvx128 v57,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x82732294;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827322ac
	if (cr6.eq) goto loc_827322AC;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lfs f0,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	f0.f64 = double(temp.f32);
	// stfs f0,-21620(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -21620, temp.u32);
	// b 0x827322bc
	goto loc_827322BC;
loc_827322AC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-13336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13336);
	f0.f64 = double(temp.f32);
	// stfs f0,-21620(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -21620, temp.u32);
loc_827322BC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8272f5f0
	ctx.lr = 0x827322C4;
	sub_8272F5F0(ctx, base);
loc_827322C4:
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82731CD8) {
	__imp__sub_82731CD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827322E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827322E4) {
	__imp__sub_827322E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827322E8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x827322F0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,-28076(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82732324
	if (!cr6.eq) goto loc_82732324;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
loc_82732324:
	// lis r30,-32111
	r30.s64 = -2104426496;
	// li r23,0
	r23.s64 = 0;
	// lwz r11,-21616(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21616);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82732364
	if (!cr6.eq) goto loc_82732364;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82732340;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273235c
	if (cr6.eq) goto loc_8273235C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ce460
	ctx.lr = 0x82732354;
	sub_821CE460(ctx, base);
	// stw r3,-21616(r30)
	PPC_STORE_U32(r30.u32 + -21616, ctx.r3.u32);
	// b 0x82732364
	goto loc_82732364;
loc_8273235C:
	// mr r11,r23
	r11.u64 = r23.u64;
	// stw r11,-21616(r30)
	PPC_STORE_U32(r30.u32 + -21616, r11.u32);
loc_82732364:
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// stw r29,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r29.u32);
	// lis r10,4095
	ctx.r10.s64 = 268369920;
	// stw r26,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r26.u32);
	// mullw r9,r11,r29
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// stw r28,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r28.u32);
	// stw r27,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r27.u32);
	// mullw r8,r9,r26
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r26.s32);
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r7,r10,65535
	ctx.r7.u64 = ctx.r10.u64 | 65535;
	// li r22,-1
	r22.s64 = -1;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x827323a0
	if (!cr6.gt) goto loc_827323A0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_827323A0:
	// bl 0x82130528
	ctx.lr = 0x827323A4;
	sub_82130528(ctx, base);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// mullw r11,r9,r29
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r29.s32);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x827323cc
	if (!cr6.gt) goto loc_827323CC;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_827323CC:
	// bl 0x82130528
	ctx.lr = 0x827323D0;
	sub_82130528(ctx, base);
	// lis r11,1638
	r11.s64 = 107347968;
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// ori r10,r11,26214
	ctx.r10.u64 = r11.u64 | 26214;
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bgt cr6,0x827323f4
	if (cr6.gt) goto loc_827323F4;
	// rlwinm r11,r27,2,0,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// b 0x827323f8
	goto loc_827323F8;
loc_827323F4:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_827323F8:
	// bl 0x82130528
	ctx.lr = 0x827323FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82732448
	if (cr6.eq) goto loc_82732448;
	// addic. r10,r27,-1
	xer.ca = r27.u32 > 0;
	ctx.r10.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x82732440
	if (cr0.lt) goto loc_82732440;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r11,r3,24
	r11.s64 = ctx.r3.s64 + 24;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8273241C:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r23,-24(r11)
	PPC_STORE_U32(r11.u32 + -24, r23.u32);
	// stb r23,-4(r11)
	PPC_STORE_U8(r11.u32 + -4, r23.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r23,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r23.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// addi r11,r11,40
	r11.s64 = r11.s64 + 40;
	// bge 0x8273241c
	if (!cr0.lt) goto loc_8273241C;
loc_82732440:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273244c
	goto loc_8273244C;
loc_82732448:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8273244C:
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8218fe20
	ctx.lr = 0x82732458;
	sub_8218FE20(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821902b0
	ctx.lr = 0x8273246C;
	sub_821902B0(ctx, base);
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821904a8
	ctx.lr = 0x8273247C;
	sub_821904A8(ctx, base);
	// li r6,7
	ctx.r6.s64 = 7;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82190640
	ctx.lr = 0x82732490;
	sub_82190640(ctx, base);
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// mr r25,r23
	r25.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827325fc
	if (!cr6.gt) goto loc_827325FC;
	// lis r11,819
	r11.s64 = 53673984;
	// lis r10,1365
	ctx.r10.s64 = 89456640;
	// addi r28,r26,-1
	r28.s64 = r26.s64 + -1;
	// addi r26,r26,-1
	r26.s64 = r26.s64 + -1;
	// mr r30,r23
	r30.u64 = r23.u64;
	// ori r24,r11,13107
	r24.u64 = r11.u64 | 13107;
	// ori r27,r10,21845
	r27.u64 = ctx.r10.u64 | 21845;
loc_827324BC:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mullw r10,r11,r26
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r26.s32);
	// mullw r9,r10,r29
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r29.s32);
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r24
	cr6.compare<uint32_t>(r11.u32, r24.u32, xer);
	// bgt cr6,0x827324e8
	if (cr6.gt) goto loc_827324E8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// b 0x827324ec
	goto loc_827324EC;
loc_827324E8:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_827324EC:
	// bl 0x82130528
	ctx.lr = 0x827324F0;
	sub_82130528(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stwx r3,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, ctx.r3.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mullw r9,r10,r28
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r28.s32);
	// mullw r11,r9,r29
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r29.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r8,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x821b4838
	ctx.lr = 0x82732524;
	sub_821B4838(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r6,0
	ctx.r6.s64 = 0;
	// add r7,r30,r11
	ctx.r7.u64 = r30.u64 + r11.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r3,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r3.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// mullw r11,r3,r28
	r11.s64 = int64_t(ctx.r3.s32) * int64_t(r28.s32);
	// mullw r11,r11,r29
	r11.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x821b4838
	ctx.lr = 0x8273255C;
	sub_821B4838(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r6,0
	ctx.r6.s64 = 0;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r3,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r3.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mullw r7,r8,r28
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r28.s32);
	// mullw r11,r7,r29
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(r29.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x821b4838
	ctx.lr = 0x82732594;
	sub_821B4838(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// stw r3,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r3.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mullw r9,r10,r26
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r26.s32);
	// mullw r11,r9,r29
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r29.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bgt cr6,0x827325d4
	if (cr6.gt) goto loc_827325D4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// b 0x827325d8
	goto loc_827325D8;
loc_827325D4:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_827325D8:
	// bl 0x82130528
	ctx.lr = 0x827325DC;
	sub_82130528(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// addi r30,r30,40
	r30.s64 = r30.s64 + 40;
	// stw r3,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r3.u32);
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// blt cr6,0x827324bc
	if (cr6.lt) goto loc_827324BC;
loc_827325FC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r30,r10,-16572
	r30.s64 = ctx.r10.s64 + -16572;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82732628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r23.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,-21612(r7)
	PPC_STORE_U32(ctx.r7.u32 + -21612, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82732660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82187150
	ctx.lr = 0x82732678;
	sub_82187150(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r30,r10,30576
	r30.s64 = ctx.r10.s64 + 30576;
	// addi r4,r9,3748
	ctx.r4.s64 = ctx.r9.s64 + 3748;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x82732694;
	sub_821CA540(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-16580
	ctx.r4.s64 = ctx.r7.s64 + -16580;
	// lwz r3,-25232(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -25232);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827326B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x827326C4;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82730150
	ctx.lr = 0x827326CC;
	sub_82730150(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827318f0
	ctx.lr = 0x827326D4;
	sub_827318F0(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-16596
	ctx.r3.s64 = ctx.r10.s64 + -16596;
	// bl 0x821c9790
	ctx.lr = 0x827326E4;
	sub_821C9790(ctx, base);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,-21608(r9)
	PPC_STORE_U32(ctx.r9.u32 + -21608, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_827322E8) {
	__imp__sub_827322E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827326FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827326FC) {
	__imp__sub_827326FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732700) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82732708;
	// stwu r1,-816(r1)
	ea = -816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// mr r14,r7
	r14.u64 = ctx.r7.u64;
	// li r19,0
	r19.s64 = 0;
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// stw r19,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r19.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r19,0(r16)
	PPC_STORE_U32(r16.u32 + 0, r19.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r19,0(r14)
	PPC_STORE_U32(r14.u32 + 0, r19.u32);
	// addi r4,r11,13552
	ctx.r4.s64 = r11.s64 + 13552;
	// stw r19,0(r15)
	PPC_STORE_U32(r15.u32 + 0, r19.u32);
	// bl 0x821d0898
	ctx.lr = 0x82732740;
	sub_821D0898(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82732758;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r18,r11,-29624
	r18.s64 = r11.s64 + -29624;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x821d0898
	ctx.lr = 0x82732770;
	sub_821D0898(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82732970
	if (!cr6.gt) goto loc_82732970;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r21,r4,-29628
	r21.s64 = ctx.r4.s64 + -29628;
	// addi r20,r5,13528
	r20.s64 = ctx.r5.s64 + 13528;
	// addi r27,r6,-16244
	r27.s64 = ctx.r6.s64 + -16244;
	// addi r26,r7,13536
	r26.s64 = ctx.r7.s64 + 13536;
	// addi r25,r8,13520
	r25.s64 = ctx.r8.s64 + 13520;
	// addi r24,r9,12868
	r24.s64 = ctx.r9.s64 + 12868;
	// addi r23,r10,13508
	r23.s64 = ctx.r10.s64 + 13508;
	// addi r22,r11,13500
	r22.s64 = r11.s64 + 13500;
loc_827327B8:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x827327C4;
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
	ctx.lr = 0x827327DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x827327E8;
	sub_821D0898(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x827327F4;
	sub_821D0898(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82732810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823dc018
	ctx.lr = 0x8273281C;
	sub_823DC018(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823d90b0
	ctx.lr = 0x82732828;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82732834
	if (cr6.eq) goto loc_82732834;
	// stb r19,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r19.u8);
loc_82732834:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82732840;
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
	ctx.lr = 0x82732858;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// xori r28,r8,1
	r28.u64 = ctx.r8.u64 ^ 1;
	// bl 0x823d90b0
	ctx.lr = 0x82732870;
	sub_823D90B0(ctx, base);
	// cntlzw r7,r3
	ctx.r7.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// xori r29,r6,1
	r29.u64 = ctx.r6.u64 ^ 1;
	// bl 0x823d90b0
	ctx.lr = 0x82732888;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273289c
	if (cr6.eq) goto loc_8273289C;
	// lwz r11,0(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r15)
	PPC_STORE_U32(r15.u32 + 0, r11.u32);
loc_8273289C:
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827328b4
	if (cr6.eq) goto loc_827328B4;
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r16)
	PPC_STORE_U32(r16.u32 + 0, r11.u32);
loc_827328B4:
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827328e0
	if (!cr6.eq) goto loc_827328E0;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r11.u32);
	// beq cr6,0x827328e0
	if (cr6.eq) goto loc_827328E0;
	// lwz r11,0(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r14)
	PPC_STORE_U32(r14.u32 + 0, r11.u32);
loc_827328E0:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x827328EC;
	sub_821D0898(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82732908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82732924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82732940;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273295C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82732968;
	sub_821D0898(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x827327b8
	if (!cr0.eq) goto loc_827327B8;
loc_82732970:
	// addi r1,r1,816
	ctx.r1.s64 = ctx.r1.s64 + 816;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82732700) {
	__imp__sub_82732700(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732978) {
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
	ctx.lr = 0x82732980;
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
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827329AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r26,24
	ctx.r9.u64 = r26.u32 & 0xFF;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82732a14
	if (!cr6.eq) goto loc_82732A14;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827329EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// lwz r31,140(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82732a10
	if (cr6.eq) goto loc_82732A10;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735580
	ctx.lr = 0x82732A08;
	sub_82735580(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735280
	ctx.lr = 0x82732A10;
	sub_82735280(ctx, base);
loc_82732A10:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82732A14:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82732978) {
	__imp__sub_82732978(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82732A1C) {
	__imp__sub_82732A1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732A20) {
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
	// bl 0x821bbea8
	ctx.lr = 0x82732A3C;
	sub_821BBEA8(ctx, base);
	// li r3,368
	ctx.r3.s64 = 368;
	// bl 0x82130528
	ctx.lr = 0x82732A44;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82732a58
	if (cr6.eq) goto loc_82732A58;
	// bl 0x82735b68
	ctx.lr = 0x82732A50;
	sub_82735B68(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82732a5c
	goto loc_82732A5C;
loc_82732A58:
	// li r31,0
	r31.s64 = 0;
loc_82732A5C:
	// bl 0x821bbf00
	ctx.lr = 0x82732A60;
	sub_821BBF00(ctx, base);
	// li r3,368
	ctx.r3.s64 = 368;
	// bl 0x82130528
	ctx.lr = 0x82732A68;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82732a7c
	if (cr6.eq) goto loc_82732A7C;
	// bl 0x82735b68
	ctx.lr = 0x82732A74;
	sub_82735B68(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82732a80
	goto loc_82732A80;
loc_82732A7C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82732A80:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a2b28
	ctx.lr = 0x82732A8C;
	sub_824A2B28(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821bbea8
	ctx.lr = 0x82732A94;
	sub_821BBEA8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82732ab4
	if (cr6.eq) goto loc_82732AB4;
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
	ctx.lr = 0x82732AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82732AB4:
	// bl 0x821bbf00
	ctx.lr = 0x82732AB8;
	sub_821BBF00(ctx, base);
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

PPC_WEAK_FUNC(sub_82732A20) {
	__imp__sub_82732A20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82732AD4) {
	__imp__sub_82732AD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732AD8) {
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
	ctx.lr = 0x82732AE0;
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
	// ble cr6,0x82732b1c
	if (!cr6.gt) goto loc_82732B1C;
	// li r30,0
	r30.s64 = 0;
loc_82732AF8:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,168(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82732B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82732af8
	if (!cr0.eq) goto loc_82732AF8;
loc_82732B1C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82732AD8) {
	__imp__sub_82732AD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82732B24) {
	__imp__sub_82732B24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732B28) {
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
	ctx.lr = 0x82732B30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r29,0
	r29.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// lhz r11,16(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82732bc0
	if (cr6.eq) goto loc_82732BC0;
	// li r30,0
	r30.s64 = 0;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
loc_82732B58:
	// cmpw cr6,r29,r25
	cr6.compare<int32_t>(r29.s32, r25.s32, xer);
	// bge cr6,0x82732bc0
	if (!cr6.lt) goto loc_82732BC0;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwzx r31,r11,r30
	r31.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82732bac
	if (cr6.eq) goto loc_82732BAC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82732B84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82732bac
	if (cr6.eq) goto loc_82732BAC;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,408(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 408);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82732bac
	if (cr6.eq) goto loc_82732BAC;
	// lfs f0,416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 416);
	f0.f64 = double(temp.f32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stfs f0,0(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
loc_82732BAC:
	// lhz r11,16(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 16);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x82732b58
	if (cr6.lt) goto loc_82732B58;
loc_82732BC0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82732B28) {
	__imp__sub_82732B28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82732BCC) {
	__imp__sub_82732BCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732BD0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82732BD8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// lhz r11,16(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82732ce8
	if (cr6.eq) goto loc_82732CE8;
	// li r27,0
	r27.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
loc_82732C00:
	// cmpw cr6,r28,r24
	cr6.compare<int32_t>(r28.s32, r24.s32, xer);
	// bge cr6,0x82732ce8
	if (!cr6.lt) goto loc_82732CE8;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// lwzx r31,r11,r27
	r31.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82732C24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82732cd4
	if (cr6.eq) goto loc_82732CD4;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,408(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 408);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82732cd4
	if (cr6.eq) goto loc_82732CD4;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,416(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 416, temp.u32);
	// lwz r9,412(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 412);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,256
	r11.s64 = r11.s64 + 256;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lwz r23,276(r9)
	r23.u64 = PPC_LOAD_U32(ctx.r9.u32 + 276);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bl 0x825031a8
	ctx.lr = 0x82732C78;
	sub_825031A8(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,232(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82732C8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825286e8
	ctx.lr = 0x82732C9C;
	sub_825286E8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b4de0
	ctx.lr = 0x82732CA4;
	sub_821B4DE0(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r11,184(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82732CC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,188(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 188);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82732CD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82732CD4:
	// lhz r11,16(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 16);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x82732c00
	if (cr6.lt) goto loc_82732C00;
loc_82732CE8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82732BD0) {
	__imp__sub_82732BD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82732CF4) {
	__imp__sub_82732CF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732CF8) {
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
	ctx.lr = 0x82732D00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,16(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82732d88
	if (cr6.eq) goto loc_82732D88;
	// li r30,0
	r30.s64 = 0;
loc_82732D20:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r31,r11,r30
	r31.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82732d74
	if (cr6.eq) goto loc_82732D74;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82732D44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82732d74
	if (cr6.eq) goto loc_82732D74;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,408(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 408);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82732d74
	if (cr6.eq) goto loc_82732D74;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82732d70
	if (cr6.eq) goto loc_82732D70;
	// bl 0x824a8e40
	ctx.lr = 0x82732D6C;
	sub_824A8E40(ctx, base);
	// b 0x82732d74
	goto loc_82732D74;
loc_82732D70:
	// bl 0x824a8f08
	ctx.lr = 0x82732D74;
	sub_824A8F08(ctx, base);
loc_82732D74:
	// lhz r11,16(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82732d20
	if (cr6.lt) goto loc_82732D20;
loc_82732D88:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82732CF8) {
	__imp__sub_82732CF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732D90) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82732D98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,20(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82732e14
	if (cr6.eq) goto loc_82732E14;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
loc_82732DB4:
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// bge cr6,0x82732e14
	if (!cr6.lt) goto loc_82732E14;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r31,16(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82732e08
	if (cr6.eq) goto loc_82732E08;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82732DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82732e08
	if (cr6.eq) goto loc_82732E08;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,408(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 408);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82732e08
	if (cr6.eq) goto loc_82732E08;
	// lfs f0,416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 416);
	f0.f64 = double(temp.f32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
loc_82732E08:
	// lwz r28,4(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82732db4
	if (!cr6.eq) goto loc_82732DB4;
loc_82732E14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82732D90) {
	__imp__sub_82732D90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732E20) {
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
	ctx.lr = 0x82732E28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,20(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82732f24
	if (cr6.eq) goto loc_82732F24;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
loc_82732E44:
	// cmpw cr6,r29,r26
	cr6.compare<int32_t>(r29.s32, r26.s32, xer);
	// bge cr6,0x82732f24
	if (!cr6.lt) goto loc_82732F24;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r31,16(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82732E68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82732f18
	if (cr6.eq) goto loc_82732F18;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,408(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 408);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82732f18
	if (cr6.eq) goto loc_82732F18;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,416(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 416, temp.u32);
	// lwz r9,412(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 412);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,256
	r11.s64 = r11.s64 + 256;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r25,276(r9)
	r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + 276);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bl 0x825031a8
	ctx.lr = 0x82732EBC;
	sub_825031A8(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,232(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82732ED0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825286e8
	ctx.lr = 0x82732EE0;
	sub_825286E8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b4de0
	ctx.lr = 0x82732EE8;
	sub_821B4DE0(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r11,184(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82732F04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,188(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 188);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82732F18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82732F18:
	// lwz r27,4(r27)
	r27.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82732e44
	if (!cr6.eq) goto loc_82732E44;
loc_82732F24:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82732E20) {
	__imp__sub_82732E20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732F30) {
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
	ctx.lr = 0x82732F38;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,20(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82732fac
	if (cr6.eq) goto loc_82732FAC;
loc_82732F4C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,16(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82732fa0
	if (cr6.eq) goto loc_82732FA0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82732F70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82732fa0
	if (cr6.eq) goto loc_82732FA0;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,408(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 408);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82732fa0
	if (cr6.eq) goto loc_82732FA0;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82732f9c
	if (cr6.eq) goto loc_82732F9C;
	// bl 0x824a8e40
	ctx.lr = 0x82732F98;
	sub_824A8E40(ctx, base);
	// b 0x82732fa0
	goto loc_82732FA0;
loc_82732F9C:
	// bl 0x824a8f08
	ctx.lr = 0x82732FA0;
	sub_824A8F08(ctx, base);
loc_82732FA0:
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82732f4c
	if (!cr6.eq) goto loc_82732F4C;
loc_82732FAC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82732F30) {
	__imp__sub_82732F30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82732FB4) {
	__imp__sub_82732FB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82732FB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82732fec
	if (!cr6.gt) goto loc_82732FEC;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
loc_82732FCC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beq cr6,0x82733088
	if (cr6.eq) goto loc_82733088;
	// bgt cr6,0x82732fec
	if (cr6.gt) goto loc_82732FEC;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// blt cr6,0x82732fcc
	if (cr6.lt) goto loc_82732FCC;
loc_82732FEC:
	// lhz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// ble cr6,0x82733020
	if (!cr6.gt) goto loc_82733020;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
loc_82733004:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// lwz r6,-4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// bne 0x82733004
	if (!cr0.eq) goto loc_82733004;
loc_82733020:
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r3,24
	ctx.r9.s64 = ctx.r3.s64 + 24;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r10.u16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r4,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, ctx.r4.u32);
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// ble cr6,0x8273306c
	if (!cr6.gt) goto loc_8273306C;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
loc_82733050:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// bne 0x82733050
	if (!cr0.eq) goto loc_82733050;
loc_8273306C:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, r11.u16);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r5,r6,r9
	PPC_STORE_U32(ctx.r6.u32 + ctx.r9.u32, ctx.r5.u32);
	// blr 
	return;
loc_82733088:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82732FB8) {
	__imp__sub_82732FB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733090) {
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
	ctx.lr = 0x82733098;
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
	// beq cr6,0x827330c0
	if (cr6.eq) goto loc_827330C0;
	// bl 0x8217d890
	ctx.lr = 0x827330B4;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_827330C0:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82733150
	if (cr6.eq) goto loc_82733150;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_827330E0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82733138
	if (cr6.eq) goto loc_82733138;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82733138
	if (cr6.eq) goto loc_82733138;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8273310C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82733138
	if (cr6.eq) goto loc_82733138;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82733120;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x82735f60
	ctx.lr = 0x82733134;
	sub_82735F60(ctx, base);
	// b 0x8273313c
	goto loc_8273313C;
loc_82733138:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_8273313C:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x827330e0
	if (cr6.lt) goto loc_827330E0;
loc_82733150:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82733090) {
	__imp__sub_82733090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273315C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273315C) {
	__imp__sub_8273315C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733160) {
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
	ctx.lr = 0x82733168;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r10,-16232
	ctx.r9.s64 = ctx.r10.s64 + -16232;
	// lhz r11,16(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 16);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827331e8
	if (!cr6.gt) goto loc_827331E8;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82733190:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827331b8
	if (cr6.eq) goto loc_827331B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,160(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827331B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827331B8:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827331dc
	if (cr6.eq) goto loc_827331DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827331DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827331DC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82733190
	if (!cr0.eq) goto loc_82733190;
loc_827331E8:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82733208
	if (cr6.eq) goto loc_82733208;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82733208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82733208:
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273321c
	if (cr6.eq) goto loc_8273321C;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x8273321C;
	sub_82130588(ctx, base);
loc_8273321C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2810
	ctx.lr = 0x82733224;
	sub_821D2810(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82733160) {
	__imp__sub_82733160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273322C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273322C) {
	__imp__sub_8273322C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733230) {
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
	ctx.lr = 0x82733238;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-4964(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r29,8(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x821c9790
	ctx.lr = 0x82733260;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d7638
	ctx.lr = 0x8273326C;
	sub_822D7638(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827333f4
	if (!cr6.eq) goto loc_827333F4;
	// lwz r31,8(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x827332a8
	if (cr6.eq) goto loc_827332A8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x82733290;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d7638
	ctx.lr = 0x8273329C;
	sub_822D7638(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827333f4
	if (!cr6.eq) goto loc_827333F4;
loc_827332A8:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,-16028
	ctx.r4.s64 = r11.s64 + -16028;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x823dc018
	ctx.lr = 0x827332BC;
	sub_823DC018(ctx, base);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82732a20
	ctx.lr = 0x827332C4;
	sub_82732A20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x827332CC;
	sub_821A5CC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82733330
	if (cr6.eq) goto loc_82733330;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-31280
	ctx.r5.s64 = r11.s64 + -31280;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8248aa28
	ctx.lr = 0x827332F0;
	sub_8248AA28(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8248a828
	ctx.lr = 0x827332FC;
	sub_8248A828(ctx, base);
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8273331c
	if (!cr6.eq) goto loc_8273331C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8248a3b0
	ctx.lr = 0x82733310;
	sub_8248A3B0(ctx, base);
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82733320
	if (cr6.eq) goto loc_82733320;
loc_8273331C:
	// bl 0x824aae80
	ctx.lr = 0x82733320;
	sub_824AAE80(ctx, base);
loc_82733320:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8248ae08
	ctx.lr = 0x82733328;
	sub_8248AE08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82489ce8
	ctx.lr = 0x82733330;
	sub_82489CE8(ctx, base);
loc_82733330:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735be0
	ctx.lr = 0x82733338;
	sub_82735BE0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,13536
	ctx.r4.s64 = r11.s64 + 13536;
	// bl 0x823d90b0
	ctx.lr = 0x82733348;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82733358
	if (cr6.eq) goto loc_82733358;
	// li r11,1
	r11.s64 = 1;
	// stb r11,308(r31)
	PPC_STORE_U8(r31.u32 + 308, r11.u8);
loc_82733358:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82733380
	if (!cr6.eq) goto loc_82733380;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,-16144
	ctx.r3.s64 = r11.s64 + -16144;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// bl 0x82130000
	ctx.lr = 0x82733374;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x823d9248
	return;
loc_82733380:
	// lhz r11,20(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 20);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// blt cr6,0x8273339c
	if (cr6.lt) goto loc_8273339C;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r11,-16200
	ctx.r3.s64 = r11.s64 + -16200;
	// bl 0x821bd618
	ctx.lr = 0x8273339C;
	sub_821BD618(ctx, base);
loc_8273339C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8249e270
	ctx.lr = 0x827333A4;
	sub_8249E270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827333c8
	if (!cr6.eq) goto loc_827333C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x827333cc
	if (cr6.lt) goto loc_827333CC;
loc_827333C8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_827333CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735db0
	ctx.lr = 0x827333D4;
	sub_82735DB0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,8(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x821c9790
	ctx.lr = 0x827333E4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82732fb8
	ctx.lr = 0x827333F4;
	sub_82732FB8(ctx, base);
loc_827333F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82733230) {
	__imp__sub_82733230(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733400) {
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
	ctx.lr = 0x82733408;
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
	// beq cr6,0x82733430
	if (cr6.eq) goto loc_82733430;
	// bl 0x8217d890
	ctx.lr = 0x82733424;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82733430:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827334c4
	if (cr6.eq) goto loc_827334C4;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_82733450:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827334ac
	if (cr6.eq) goto loc_827334AC;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827334ac
	if (cr6.eq) goto loc_827334AC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8273347C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x827334ac
	if (cr6.eq) goto loc_827334AC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82733490;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwzx r5,r27,r26
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x827363a0
	ctx.lr = 0x827334A8;
	sub_827363A0(ctx, base);
	// b 0x827334b0
	goto loc_827334B0;
loc_827334AC:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_827334B0:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82733450
	if (cr6.lt) goto loc_82733450;
loc_827334C4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82733400) {
	__imp__sub_82733400(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827334D0) {
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
	ctx.lr = 0x827334D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x827334E8;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82733574
	if (!cr6.gt) goto loc_82733574;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_82733500:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82733568
	if (cr6.eq) goto loc_82733568;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82733564
	if (cr6.eq) goto loc_82733564;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82733564
	if (cr6.eq) goto loc_82733564;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82733534;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82733564
	if (cr6.eq) goto loc_82733564;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82733548;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwzx r5,r28,r27
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x827363a0
	ctx.lr = 0x82733560;
	sub_827363A0(ctx, base);
	// b 0x82733568
	goto loc_82733568;
loc_82733564:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_82733568:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82733500
	if (!cr0.eq) goto loc_82733500;
loc_82733574:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_827334D0) {
	__imp__sub_827334D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733580) {
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
	// bl 0x821d2970
	ctx.lr = 0x827335A0;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-19128
	ctx.r10.s64 = r11.s64 + -19128;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x827335B4;
	sub_821B5A60(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827335d4
	if (cr6.eq) goto loc_827335D4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x827335C8;
	sub_8217D890(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_827335D4:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82733090
	ctx.lr = 0x827335E4;
	sub_82733090(ctx, base);
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

PPC_WEAK_FUNC(sub_82733580) {
	__imp__sub_82733580(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733600) {
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
	// bl 0x82733160
	ctx.lr = 0x82733620;
	sub_82733160(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82733638
	if (cr6.eq) goto loc_82733638;
	// bl 0x82130588
	ctx.lr = 0x82733634;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82733638:
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

PPC_WEAK_FUNC(sub_82733600) {
	__imp__sub_82733600(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733650) {
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
	ctx.lr = 0x82733658;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x82733668;
	sub_821D2970(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-16232
	ctx.r9.s64 = ctx.r10.s64 + -16232;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// sth r29,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r29.u16);
	// beq cr6,0x827336a0
	if (cr6.eq) goto loc_827336A0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827334d0
	ctx.lr = 0x8273369C;
	sub_827334D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_827336A0:
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82733650) {
	__imp__sub_82733650(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827336B0) {
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
	ctx.lr = 0x827336B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82733724
	if (cr6.eq) goto loc_82733724;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82733724
	if (cr6.eq) goto loc_82733724;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x827336EC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82733724
	if (cr6.eq) goto loc_82733724;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82733700;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273372c
	if (cr6.eq) goto loc_8273372C;
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x82733580
	ctx.lr = 0x8273371C;
	sub_82733580(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82733724:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8273372C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_827336B0) {
	__imp__sub_827336B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82733734) {
	__imp__sub_82733734(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733738) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82733740;
	// stwu r1,-832(r1)
	ea = -832 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82130528
	ctx.lr = 0x8273375C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82733770
	if (cr6.eq) goto loc_82733770;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8272c260
	ctx.lr = 0x8273376C;
	sub_8272C260(ctx, base);
	// b 0x82733774
	goto loc_82733774;
loc_82733770:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82733774:
	// stw r3,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,13552
	ctx.r4.s64 = r11.s64 + 13552;
	// li r14,0
	r14.s64 = 0;
	// li r15,0
	r15.s64 = 0;
	// bl 0x821d0898
	ctx.lr = 0x82733790;
	sub_821D0898(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827337A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r17,r11,-29624
	r17.s64 = r11.s64 + -29624;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// bl 0x821d0898
	ctx.lr = 0x827337C0;
	sub_821D0898(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82733a30
	if (!cr6.gt) goto loc_82733A30;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lis r30,-32131
	r30.s64 = -2105737216;
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r21,r3,13544
	r21.s64 = ctx.r3.s64 + 13544;
	// addi r27,r30,30576
	r27.s64 = r30.s64 + 30576;
	// addi r26,r4,-16244
	r26.s64 = ctx.r4.s64 + -16244;
	// addi r25,r5,13536
	r25.s64 = ctx.r5.s64 + 13536;
	// addi r24,r6,-29628
	r24.s64 = ctx.r6.s64 + -29628;
	// addi r23,r7,13528
	r23.s64 = ctx.r7.s64 + 13528;
	// addi r22,r8,13520
	r22.s64 = ctx.r8.s64 + 13520;
	// addi r20,r9,12868
	r20.s64 = ctx.r9.s64 + 12868;
	// addi r19,r10,13508
	r19.s64 = ctx.r10.s64 + 13508;
	// addi r18,r11,13500
	r18.s64 = r11.s64 + 13500;
loc_8273381C:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82733828;
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
	ctx.lr = 0x82733840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x8273384C;
	sub_821D0898(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82733858;
	sub_821D0898(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82733874;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823dc018
	ctx.lr = 0x82733880;
	sub_823DC018(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823d90b0
	ctx.lr = 0x8273388C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273389c
	if (cr6.eq) goto loc_8273389C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
loc_8273389C:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x827338A8;
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
	ctx.lr = 0x827338C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821d0898
	ctx.lr = 0x827338D8;
	sub_821D0898(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827338F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82733910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8273392C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82733948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82733954;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823d90b0
	ctx.lr = 0x82733960;
	sub_823D90B0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823d90b0
	ctx.lr = 0x8273396C;
	sub_823D90B0(ctx, base);
	// cntlzw r5,r3
	ctx.r5.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// xori r29,r4,1
	r29.u64 = ctx.r4.u64 ^ 1;
	// bne cr6,0x827339b8
	if (!cr6.eq) goto loc_827339B8;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273399c
	if (!cr6.eq) goto loc_8273399C;
	// addi r14,r14,1
	r14.s64 = r14.s64 + 1;
	// cmpwi cr6,r14,24576
	cr6.compare<int32_t>(r14.s32, 24576, xer);
	// b 0x827339a4
	goto loc_827339A4;
loc_8273399C:
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// cmpwi cr6,r15,512
	cr6.compare<int32_t>(r15.s32, 512, xer);
loc_827339A4:
	// bgt cr6,0x82733a20
	if (cr6.gt) goto loc_82733A20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827339b8
	if (!cr6.eq) goto loc_827339B8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821b9c70
	ctx.lr = 0x827339B8;
	sub_821B9C70(ctx, base);
loc_827339B8:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ca540
	ctx.lr = 0x827339C4;
	sub_821CA540(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827339EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x827339F8;
	sub_821C9A90(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82733a20
	if (cr6.eq) goto loc_82733A20;
	// lhz r11,16(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 16);
	// addi r10,r28,12
	ctx.r10.s64 = r28.s64 + 12;
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,16(r28)
	PPC_STORE_U16(r28.u32 + 16, ctx.r7.u16);
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
loc_82733A20:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bne 0x8273381c
	if (!cr0.eq) goto loc_8273381C;
loc_82733A30:
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82733738) {
	__imp__sub_82733738(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733A38) {
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
	ctx.lr = 0x82733A40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x82733A50;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r26,8
	ctx.r3.s64 = r26.s64 + 8;
	// addi r10,r11,-16232
	ctx.r10.s64 = r11.s64 + -16232;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// bl 0x827336b0
	ctx.lr = 0x82733A64;
	sub_827336B0(ctx, base);
	// addi r23,r26,12
	r23.s64 = r26.s64 + 12;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82733400
	ctx.lr = 0x82733A78;
	sub_82733400(ctx, base);
	// lhz r5,18(r26)
	ctx.r5.u64 = PPC_LOAD_U16(r26.u32 + 18);
	// lhz r4,16(r26)
	ctx.r4.u64 = PPC_LOAD_U16(r26.u32 + 16);
	// cmplw cr6,r4,r5
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, xer);
	// beq cr6,0x82733a94
	if (cr6.eq) goto loc_82733A94;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-16008
	ctx.r3.s64 = r11.s64 + -16008;
	// bl 0x82130000
	ctx.lr = 0x82733A94;
	sub_82130000(ctx, base);
loc_82733A94:
	// lhz r11,16(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 16);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82733ad4
	if (!cr6.gt) goto loc_82733AD4;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82733AAC:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82735850
	ctx.lr = 0x82733AB8;
	sub_82735850(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82733ac8
	if (cr6.eq) goto loc_82733AC8;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_82733AC8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82733aac
	if (!cr0.eq) goto loc_82733AAC;
loc_82733AD4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f7288
	ctx.lr = 0x82733AE4;
	sub_822F7288(ctx, base);
	// lhz r11,16(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82733b94
	if (!cr6.gt) goto loc_82733B94;
	// mr r27,r11
	r27.u64 = r11.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r28,0
	r28.s64 = 0;
	// addi r25,r11,-26560
	r25.s64 = r11.s64 + -26560;
loc_82733B00:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwzx r29,r11,r28
	r29.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82735898
	ctx.lr = 0x82733B10;
	sub_82735898(ctx, base);
	// lwz r31,12(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82733b6c
	if (cr6.eq) goto loc_82733B6C;
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x82733B2C;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82733b54
	if (cr6.eq) goto loc_82733B54;
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
	// b 0x82733b68
	goto loc_82733B68;
loc_82733B54:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x82733B64;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_82733B68:
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82733B6C:
	// stw r31,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r31.u32);
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// lwz r31,140(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735580
	ctx.lr = 0x82733B80;
	sub_82735580(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735280
	ctx.lr = 0x82733B88;
	sub_82735280(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x82733b00
	if (!cr0.eq) goto loc_82733B00;
loc_82733B94:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82733A38) {
	__imp__sub_82733A38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733BA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82733a38
	sub_82733A38(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82733BA0) {
	__imp__sub_82733BA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733BAC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82733BAC) {
	__imp__sub_82733BAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733BB0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82733BB8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// lfs f1,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822da7e8
	ctx.lr = 0x82733BCC;
	sub_822DA7E8(ctx, base);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r29,-1
	r29.s64 = -1;
	// ori r30,r10,65535
	r30.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// ble cr6,0x82733bec
	if (!cr6.gt) goto loc_82733BEC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82733BEC:
	// bl 0x82130528
	ctx.lr = 0x82733BF0;
	sub_82130528(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823d9890
	ctx.lr = 0x82733C04;
	sub_823D9890(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82733c18
	if (!cr6.gt) goto loc_82733C18;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82733C18:
	// bl 0x82130528
	ctx.lr = 0x82733C1C;
	sub_82130528(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f0,-15528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15528);
	f0.f64 = double(temp.f32);
	// blt cr6,0x82733c84
	if (cr6.lt) goto loc_82733C84;
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_82733C4C:
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
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
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + r11.u64;
	// stfs f0,4(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stfs f0,-4(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + -4, temp.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfsx f0,r3,r9
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82733c4c
	if (!cr0.eq) goto loc_82733C4C;
loc_82733C84:
	// cmpw cr6,r6,r7
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, xer);
	// bge cr6,0x82733ca8
	if (!cr6.lt) goto loc_82733CA8;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r6,r7
	r11.s64 = ctx.r7.s64 - ctx.r6.s64;
loc_82733C94:
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82733c94
	if (!cr0.eq) goto loc_82733C94;
loc_82733CA8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82733BB0) {
	__imp__sub_82733BB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733CB0) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82680098
	ctx.lr = 0x82733CDC;
	sub_82680098(ctx, base);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x82733d30
	if (cr6.lt) goto loc_82733D30;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x82733d30
	if (!cr6.lt) goto loc_82733D30;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt cr6,0x82733d30
	if (cr6.lt) goto loc_82733D30;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733d30
	if (!cr6.lt) goto loc_82733D30;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// add. r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733d30
	if (!cr0.gt) goto loc_82733D30;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// b 0x82733d34
	goto loc_82733D34;
loc_82733D30:
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
loc_82733D34:
	// addi r11,r6,-1
	r11.s64 = ctx.r6.s64 + -1;
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82733d84
	if (cr6.lt) goto loc_82733D84;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733d84
	if (!cr6.lt) goto loc_82733D84;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82733d84
	if (cr6.lt) goto loc_82733D84;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// bge cr6,0x82733d84
	if (!cr6.lt) goto loc_82733D84;
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// add. r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x82733d84
	if (!cr0.gt) goto loc_82733D84;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// b 0x82733d88
	goto loc_82733D88;
loc_82733D84:
	// stw r5,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r5.u32);
loc_82733D88:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82733dd0
	if (cr6.lt) goto loc_82733DD0;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733dd0
	if (!cr6.lt) goto loc_82733DD0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt cr6,0x82733dd0
	if (cr6.lt) goto loc_82733DD0;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bge cr6,0x82733dd0
	if (!cr6.lt) goto loc_82733DD0;
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// add. r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x82733dd0
	if (!cr0.gt) goto loc_82733DD0;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// b 0x82733dd4
	goto loc_82733DD4;
loc_82733DD0:
	// stw r5,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r5.u32);
loc_82733DD4:
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82733e20
	if (cr6.lt) goto loc_82733E20;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733e20
	if (!cr6.lt) goto loc_82733E20;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82733e20
	if (cr6.lt) goto loc_82733E20;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// bge cr6,0x82733e20
	if (!cr6.lt) goto loc_82733E20;
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733e20
	if (!cr0.gt) goto loc_82733E20;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// b 0x82733e24
	goto loc_82733E24;
loc_82733E20:
	// stw r5,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r5.u32);
loc_82733E24:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x82733e6c
	if (cr6.lt) goto loc_82733E6C;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x82733e6c
	if (!cr6.lt) goto loc_82733E6C;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82733e6c
	if (cr6.lt) goto loc_82733E6C;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733e6c
	if (!cr6.lt) goto loc_82733E6C;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add. r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733e6c
	if (!cr0.gt) goto loc_82733E6C;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// b 0x82733e70
	goto loc_82733E70;
loc_82733E6C:
	// stw r5,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r5.u32);
loc_82733E70:
	// addi r10,r6,1
	ctx.r10.s64 = ctx.r6.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82733ebc
	if (cr6.lt) goto loc_82733EBC;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82733ebc
	if (!cr6.lt) goto loc_82733EBC;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82733ebc
	if (cr6.lt) goto loc_82733EBC;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// bge cr6,0x82733ebc
	if (!cr6.lt) goto loc_82733EBC;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733ebc
	if (!cr0.gt) goto loc_82733EBC;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// stw r3,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r3.u32);
	// b 0x82733ec0
	goto loc_82733EC0;
loc_82733EBC:
	// stw r5,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r5.u32);
loc_82733EC0:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82733f08
	if (cr6.lt) goto loc_82733F08;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82733f08
	if (!cr6.lt) goto loc_82733F08;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt cr6,0x82733f08
	if (cr6.lt) goto loc_82733F08;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bge cr6,0x82733f08
	if (!cr6.lt) goto loc_82733F08;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733f08
	if (!cr0.gt) goto loc_82733F08;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r4,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r4.u32);
	// b 0x82733f0c
	goto loc_82733F0C;
loc_82733F08:
	// stw r5,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r5.u32);
loc_82733F0C:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82733f54
	if (cr6.lt) goto loc_82733F54;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82733f54
	if (!cr6.lt) goto loc_82733F54;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82733f54
	if (cr6.lt) goto loc_82733F54;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// bge cr6,0x82733f54
	if (!cr6.lt) goto loc_82733F54;
	// mullw r11,r11,r7
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r7.s32);
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733f54
	if (!cr0.gt) goto loc_82733F54;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r8.u32);
	// b 0x82733f58
	goto loc_82733F58;
loc_82733F54:
	// stw r5,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r5.u32);
loc_82733F58:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x82733fa0
	if (cr6.lt) goto loc_82733FA0;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x82733fa0
	if (!cr6.lt) goto loc_82733FA0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82733fa0
	if (cr6.lt) goto loc_82733FA0;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733fa0
	if (!cr6.lt) goto loc_82733FA0;
	// mullw r11,r11,r7
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r7.s32);
	// add. r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733fa0
	if (!cr0.gt) goto loc_82733FA0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r8.u32);
	// b 0x82733fa4
	goto loc_82733FA4;
loc_82733FA0:
	// stw r5,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r5.u32);
loc_82733FA4:
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

PPC_WEAK_FUNC(sub_82733CB0) {
	__imp__sub_82733CB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82733FBC) {
	__imp__sub_82733FBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82733FC0) {
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
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-15520
	ctx.r9.s64 = r11.s64 + -15520;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x82733FF8;
	sub_822E5148(ctx, base);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-10404(r8)
	PPC_STORE_U32(ctx.r8.u32 + -10404, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x8273400C;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82734024
	if (cr6.eq) goto loc_82734024;
	// bl 0x82130588
	ctx.lr = 0x82734020;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82734024:
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

PPC_WEAK_FUNC(sub_82733FC0) {
	__imp__sub_82733FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273403C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273403C) {
	__imp__sub_8273403C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82734040) {
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
	// bl 0x822e6b38
	ctx.lr = 0x8273405C;
	sub_822E6B38(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,24
	ctx.r10.s64 = 1572864;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-15520
	ctx.r8.s64 = r11.s64 + -15520;
	// ori r7,r10,40946
	ctx.r7.u64 = ctx.r10.u64 | 40946;
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
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x82734090;
	sub_822E5138(ctx, base);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// addi r4,r5,-15496
	ctx.r4.s64 = ctx.r5.s64 + -15496;
	// li r30,0
	r30.s64 = 0;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// bl 0x822da7b0
	ctx.lr = 0x827340AC;
	sub_822DA7B0(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// lfs f0,3796(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
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

PPC_WEAK_FUNC(sub_82734040) {
	__imp__sub_82734040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827340D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,13500
	ctx.r3.s64 = r11.s64 + 13500;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827340D8) {
	__imp__sub_827340D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827340E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827340E4) {
	__imp__sub_827340E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827340E8) {
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
	// addi r10,r11,-15496
	ctx.r10.s64 = r11.s64 + -15496;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x82734110;
	sub_82130588(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82734118;
	sub_82130588(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r7,r9,-15520
	ctx.r7.s64 = ctx.r9.s64 + -15520;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r3,-8092(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x82734134;
	sub_822E5148(ctx, base);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-10404(r6)
	PPC_STORE_U32(ctx.r6.u32 + -10404, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x82734148;
	sub_822E6940(ctx, base);
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

PPC_WEAK_FUNC(sub_827340E8) {
	__imp__sub_827340E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273415C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273415C) {
	__imp__sub_8273415C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82734160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// bl 0x823d91cc
	ctx.lr = 0x82734168;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823db9c4
	ctx.lr = 0x82734170;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,20(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// lwzx r24,r10,r11
	r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8273447c
	if (cr6.eq) goto loc_8273447C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f27,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f27.f64 = double(temp.f32);
	// lfs f23,-12072(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12072);
	f23.f64 = double(temp.f32);
	// li r18,96
	r18.s64 = 96;
	// lfs f26,31020(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31020);
	f26.f64 = double(temp.f32);
	// lis r20,1024
	r20.s64 = 67108864;
	// lfs f28,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f28.f64 = double(temp.f32);
	// lis r17,4096
	r17.s64 = 268435456;
	// lfs f24,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f24.f64 = double(temp.f32);
	// lis r21,-32243
	r21.s64 = -2113077248;
	// lfs f25,-6172(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -6172);
	f25.f64 = double(temp.f32);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r23,-32119
	r23.s64 = -2104950784;
	// lis r19,-32115
	r19.s64 = -2104688640;
	// lis r22,-32119
	r22.s64 = -2104950784;
loc_827341DC:
	// lhz r11,30(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 30);
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82734470
	if (cr6.eq) goto loc_82734470;
	// lwz r26,16(r24)
	r26.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82734204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bne cr6,0x82734220
	if (!cr6.eq) goto loc_82734220;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8248a510
	ctx.lr = 0x82734214;
	sub_8248A510(ctx, base);
	// lbz r11,308(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 308);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82734470
	if (cr6.eq) goto loc_82734470;
loc_82734220:
	// lwz r11,19684(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 19684);
	// lwz r3,16(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// lfs f31,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f31.f64 = double(temp.f32);
	// bl 0x8248a510
	ctx.lr = 0x82734230;
	sub_8248A510(ctx, base);
	// lfs f30,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f30,f25
	cr6.compare(f30.f64, f25.f64);
	// bge cr6,0x82734284
	if (!cr6.lt) goto loc_82734284;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82734250;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x82734274
	if (cr6.eq) goto loc_82734274;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273426C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x82734284
	if (!cr6.eq) goto loc_82734284;
loc_82734274:
	// lwz r11,156(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82734284
	if (cr6.eq) goto loc_82734284;
	// fmr f30,f24
	ctx.fpscr.disableFlushMode();
	f30.f64 = f24.f64;
loc_82734284:
	// lwz r11,16(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,184(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,180(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,176(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-15540(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + -15540);
	f0.f64 = double(temp.f32);
	// lvx128 v1,r11,r18
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f29,f31,f0
	f29.f64 = double(float(f31.f64 * f0.f64));
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// fsubs f6,f12,f10
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmuls f5,f7,f7
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fsubs f4,f11,f9
	ctx.f4.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// fmadds f3,f6,f6,f5
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// fmadds f2,f4,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fsubs f31,f1,f30
	f31.f64 = double(float(ctx.f1.f64 - f30.f64));
	// fcmpu cr6,f31,f28
	cr6.compare(f31.f64, f28.f64);
	// bge cr6,0x827342e0
	if (!cr6.lt) goto loc_827342E0;
	// fmr f31,f28
	f31.f64 = f28.f64;
loc_827342E0:
	// lfs f0,192(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 192);
	f0.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bge cr6,0x82734348
	if (!cr6.lt) goto loc_82734348;
	// lwz r3,112(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 112);
	// bl 0x8217c148
	ctx.lr = 0x82734304;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82734324
	if (cr6.eq) goto loc_82734324;
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x8273431c
	if (!cr6.gt) goto loc_8273431C;
	// li r11,0
	r11.s64 = 0;
loc_8273431C:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// b 0x82734334
	goto loc_82734334;
loc_82734324:
	// lfs f0,196(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 196);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bge cr6,0x82734348
	if (!cr6.lt) goto loc_82734348;
loc_82734334:
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f31,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f26.f64);
	// ble cr6,0x82734344
	if (!cr6.gt) goto loc_82734344;
	// li r11,0
	r11.s64 = 0;
loc_82734344:
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
loc_82734348:
	// lfs f0,200(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 200);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bge cr6,0x8273436c
	if (!cr6.lt) goto loc_8273436C;
	// fcmpu cr6,f31,f23
	cr6.compare(f31.f64, f23.f64);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x82734368
	if (cr6.lt) goto loc_82734368;
	// li r11,0
	r11.s64 = 0;
loc_82734368:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
loc_8273436C:
	// lfs f0,192(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 192);
	f0.f64 = double(temp.f32);
	// clrlwi r31,r30,24
	r31.u64 = r30.u32 & 0xFF;
	// fdivs f13,f30,f0
	ctx.f13.f64 = double(float(f30.f64 / f0.f64));
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// fnmsubs f12,f30,f27,f13
	ctx.f12.f64 = double(float(-(f30.f64 * f27.f64 - ctx.f13.f64)));
	// fsel f11,f12,f12,f28
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f28.f64;
	// fsubs f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 - f29.f64));
	// fsel f30,f10,f29,f11
	f30.f64 = ctx.f10.f64 >= 0.0 ? f29.f64 : ctx.f11.f64;
	// bne cr6,0x8273439c
	if (!cr6.eq) goto loc_8273439C;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827343e4
	if (cr6.eq) goto loc_827343E4;
loc_8273439C:
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r4,-17936(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + -17936);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-17628(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -17628);
	// bl 0x82175238
	ctx.lr = 0x827343B0;
	sub_82175238(ctx, base);
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r11,r20
	cr6.compare<int32_t>(r11.s32, r20.s32, xer);
	// beq cr6,0x827343cc
	if (cr6.eq) goto loc_827343CC;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r17
	cr6.compare<int32_t>(r11.s32, r17.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x827343d0
	if (!cr6.eq) goto loc_827343D0;
loc_827343CC:
	// li r11,0
	r11.s64 = 0;
loc_827343D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// and r9,r11,r31
	ctx.r9.u64 = r11.u64 & r31.u64;
	// and r29,r10,r11
	r29.u64 = ctx.r10.u64 & r11.u64;
	// clrlwi r30,r9,24
	r30.u64 = ctx.r9.u32 & 0xFF;
loc_827343E4:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82734408
	if (!cr6.eq) goto loc_82734408;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82734408
	if (!cr6.eq) goto loc_82734408;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82734470
	if (cr6.eq) goto loc_82734470;
loc_82734408:
	// lwz r11,-4964(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -4964);
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// cntlzw r6,r10
	ctx.r6.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// stw r26,112(r11)
	PPC_STORE_U32(r11.u32 + 112, r26.u32);
	// subfic r4,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r4.s64 = 0 - ctx.r8.s64;
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// subfe r10,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r4.u64 + ctx.r4.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r9,r5,0,26,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x3E;
	// xori r7,r3,1
	ctx.r7.u64 = ctx.r3.u64 ^ 1;
	// rlwinm r8,r10,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// rlwinm r9,r9,0,30,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// lwz r11,-4964(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -4964);
	// addi r10,r11,116
	ctx.r10.s64 = r11.s64 + 116;
	// stw r7,116(r11)
	PPC_STORE_U32(r11.u32 + 116, ctx.r7.u32);
	// stw r4,116(r11)
	PPC_STORE_U32(r11.u32 + 116, ctx.r4.u32);
	// lwz r11,-4964(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -4964);
	// stfs f30,120(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f31,124(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// bl 0x8248a518
	ctx.lr = 0x82734470;
	sub_8248A518(ctx, base);
loc_82734470:
	// lwz r24,24(r24)
	r24.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x827341dc
	if (!cr6.eq) goto loc_827341DC;
loc_8273447C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dba10
	ctx.lr = 0x82734488;
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_82734160) {
	__imp__sub_82734160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273448C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273448C) {
	__imp__sub_8273448C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82734490) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// cmpwi cr6,r4,1024
	cr6.compare<int32_t>(ctx.r4.s32, 1024, xer);
	// stw r4,-21564(r11)
	PPC_STORE_U32(r11.u32 + -21564, ctx.r4.u32);
	// bgt cr6,0x8273493c
	if (cr6.gt) goto loc_8273493C;
	// beq cr6,0x82734918
	if (cr6.eq) goto loc_82734918;
	// addi r11,r4,-2
	r11.s64 = ctx.r4.s64 + -2;
	// cmplwi cr6,r11,254
	cr6.compare<uint32_t>(r11.u32, 254, xer);
	// bgt cr6,0x827349c4
	if (cr6.gt) goto loc_827349C4;
	// lis r12,-32141
	r12.s64 = -2106392576;
	// addi r12,r12,17624
	r12.s64 = r12.s64 + 17624;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,18644(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18644);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82729438
	ctx.lr = 0x827348E4;
	sub_82729438(ctx, base);
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8273490C;
	sub_8217C088(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,-4964(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4964);
	// b 0x827349c0
	goto loc_827349C0;
loc_82734918:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x82734924;
	sub_82205248(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827349c4
	if (cr6.eq) goto loc_827349C4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// b 0x827349c0
	goto loc_827349C0;
loc_8273493C:
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,32768
	ctx.r10.u64 = r11.u64 | 32768;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82734994
	if (cr6.gt) goto loc_82734994;
	// cmplwi cr6,r4,32768
	cr6.compare<uint32_t>(ctx.r4.u32, 32768, xer);
	// beq cr6,0x82734970
	if (cr6.eq) goto loc_82734970;
	// cmpwi cr6,r4,2048
	cr6.compare<int32_t>(ctx.r4.s32, 2048, xer);
	// beq cr6,0x82734918
	if (cr6.eq) goto loc_82734918;
	// cmpwi cr6,r4,4096
	cr6.compare<int32_t>(ctx.r4.s32, 4096, xer);
	// bne cr6,0x827349c4
	if (!cr6.eq) goto loc_827349C4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// b 0x827349c0
	goto loc_827349C0;
loc_82734970:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82729438
	ctx.lr = 0x82734980;
	sub_82729438(ctx, base);
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
loc_82734994:
	// lis r11,8
	r11.s64 = 524288;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x827349bc
	if (cr6.eq) goto loc_827349BC;
	// lis r11,16
	r11.s64 = 1048576;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bne cr6,0x827349c4
	if (!cr6.eq) goto loc_827349C4;
	// lwz r11,-4964(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4964);
	// lwz r3,108(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// bl 0x8272fee0
	ctx.lr = 0x827349BC;
	sub_8272FEE0(ctx, base);
loc_827349BC:
	// lwz r3,-4964(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4964);
loc_827349C0:
	// bl 0x8272ac98
	ctx.lr = 0x827349C4;
	sub_8272AC98(ctx, base);
loc_827349C4:
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

PPC_WEAK_FUNC(sub_82734490) {
	__imp__sub_82734490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827349D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,24(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827349ec
	if (cr6.eq) goto loc_827349EC;
	// lwz r10,20(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
loc_827349EC:
	// lwz r11,20(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82734a04
	if (cr6.eq) goto loc_82734A04;
	// lwz r10,24(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// b 0x82734a30
	goto loc_82734A30;
loc_82734A04:
	// lhz r11,28(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 28);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82734a30
	if (cr6.lt) goto loc_82734A30;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// bne cr6,0x82734a30
	if (!cr6.eq) goto loc_82734A30;
	// lwz r9,24(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
loc_82734A30:
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r11.u32);
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// sth r10,28(r4)
	PPC_STORE_U16(ctx.r4.u32 + 28, ctx.r10.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827349D8) {
	__imp__sub_827349D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82734A48) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82734A50;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r27,r28,48
	r27.s64 = r28.s64 + 48;
	// addi r29,r30,48
	r29.s64 = r30.s64 + 48;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lhz r25,28(r31)
	r25.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82680098
	ctx.lr = 0x82734A80;
	sub_82680098(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8248a510
	ctx.lr = 0x82734A88;
	sub_8248A510(ctx, base);
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82734abc
	if (cr6.eq) goto loc_82734ABC;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8248a510
	ctx.lr = 0x82734AA0;
	sub_8248A510(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-12736(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12736);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82734abc
	if (cr6.lt) goto loc_82734ABC;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// b 0x82734ad0
	goto loc_82734AD0;
loc_82734ABC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x822da900
	ctx.lr = 0x82734ACC;
	sub_822DA900(ctx, base);
	// extsh r5,r3
	ctx.r5.s64 = ctx.r3.s16;
loc_82734AD0:
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82734b48
	if (!cr6.eq) goto loc_82734B48;
	// lwz r31,16(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x82734AE8;
	sub_8248A510(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82734b0c
	if (cr6.eq) goto loc_82734B0C;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x82734B00;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x82734b10
	if (!cr6.eq) goto loc_82734B10;
loc_82734B0C:
	// lwz r4,176(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 176);
loc_82734B10:
	// lfs f3,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f2,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r11,-15332
	ctx.r3.s64 = r11.s64 + -15332;
	// stfd f3,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f3.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x82734B40;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734B48:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82734c08
	if (!cr6.lt) goto loc_82734C08;
	// extsh r11,r25
	r11.s64 = r25.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82734b7c
	if (cr6.lt) goto loc_82734B7C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827349d8
	ctx.lr = 0x82734B68;
	sub_827349D8(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-15360
	ctx.r3.s64 = r11.s64 + -15360;
	// bl 0x82130000
	ctx.lr = 0x82734B74;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734B7C:
	// lfs f1,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f3,56(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 56);
	ctx.f3.f64 = double(temp.f32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lfs f2,52(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// addi r3,r11,-15384
	ctx.r3.s64 = r11.s64 + -15384;
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x82734BAC;
	sub_82130000(ctx, base);
	// lfs f6,72(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 72);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lfs f4,68(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 68);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// addi r3,r10,-15472
	ctx.r3.s64 = ctx.r10.s64 + -15472;
	// lfs f2,64(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 64);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stfd f6,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f6.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// stfd f5,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f5.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// stfd f4,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f4.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x82734C00;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734C08:
	// lwz r10,80(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82734d0c
	if (!cr6.lt) goto loc_82734D0C;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lfsx f13,r10,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-15528(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -15528);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82734c38
	if (!cr6.eq) goto loc_82734C38;
	// lfs f0,52(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 52);
	f0.f64 = double(temp.f32);
	// stfsx f0,r10,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, temp.u32);
loc_82734C38:
	// extsh r10,r25
	ctx.r10.s64 = r25.s16;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82734d0c
	if (cr6.eq) goto loc_82734D0C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82734ccc
	if (!cr6.gt) goto loc_82734CCC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827349d8
	ctx.lr = 0x82734C58;
	sub_827349D8(ctx, base);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwzx r6,r8,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82734c84
	if (!cr6.eq) goto loc_82734C84;
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r26.u32);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stwx r31,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r31.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734C84:
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lwzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r7,19684(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19684);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// beq cr6,0x82734cbc
	if (cr6.eq) goto loc_82734CBC;
loc_82734CA4:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// ble cr6,0x82734d14
	if (!cr6.gt) goto loc_82734D14;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82734ca4
	if (!cr6.eq) goto loc_82734CA4;
loc_82734CBC:
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
loc_82734CCC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827349d8
	ctx.lr = 0x82734CD8;
	sub_827349D8(ctx, base);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82734cf0
	if (cr6.eq) goto loc_82734CF0;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
loc_82734CF0:
	// stw r26,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r26.u32);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stwx r31,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r31.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
loc_82734D0C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734D14:
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// bne cr6,0x82734d24
	if (!cr6.eq) goto loc_82734D24;
	// stw r31,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r31.u32);
	// b 0x82734cf0
	goto loc_82734CF0;
loc_82734D24:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82734d4c
	if (!cr6.eq) goto loc_82734D4C;
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r26.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stwx r31,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r31.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734D4C:
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82734A48) {
	__imp__sub_82734A48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82734D68) {
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
	// bl 0x827340e8
	ctx.lr = 0x82734D88;
	sub_827340E8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82734da0
	if (cr6.eq) goto loc_82734DA0;
	// bl 0x82130588
	ctx.lr = 0x82734D9C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82734DA0:
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

PPC_WEAK_FUNC(sub_82734D68) {
	__imp__sub_82734D68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82734DB8) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82734DC0;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d4
	ctx.lr = 0x82734DC8;
	// li r12,-224
	r12.s64 = -224;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r5,r31,128
	ctx.r5.s64 = r31.s64 + 128;
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r6,r11,45
	ctx.r6.s64 = r11.s64 + 45;
	// li r9,48
	ctx.r9.s64 = 48;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwzx r10,r4,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// stw r10,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r10.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r5,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r5,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r5,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,19620(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x82475e00
	ctx.lr = 0x82734E48;
	sub_82475E00(ctx, base);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f12,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r9,736
	ctx.r9.s64 = 736;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r27,1
	r27.s64 = 1;
	// lfs f0,-1540(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -1540);
	f0.f64 = double(temp.f32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lfs f31,-15264(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -15264);
	f31.f64 = double(temp.f32);
	// lfs f0,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lfd f1,-15272(r6)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r6.u32 + -15272);
	// stb r27,776(r11)
	PPC_STORE_U8(r11.u32 + 776, r27.u8);
	// lwz r5,112(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lfs f10,712(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 712);
	ctx.f10.f64 = double(temp.f32);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// stfs f9,192(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// lfs f8,712(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 712);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f7,196(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// bl 0x823dbf10
	ctx.lr = 0x82734EC8;
	sub_823DBF10(ctx, base);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// li r22,0
	r22.s64 = 0;
	// addi r16,r31,176
	r16.s64 = r31.s64 + 176;
	// stw r22,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r22.u32);
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmuls f5,f6,f31
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64));
	// stfs f5,200(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// bl 0x82680098
	ctx.lr = 0x82734EFC;
	sub_82680098(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r22
	r11.u64 = r22.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14884(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stb r11,-21560(r10)
	PPC_STORE_U8(ctx.r10.u32 + -21560, r11.u8);
	// lfs f31,92(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	f31.f64 = double(temp.f32);
	// fmuls f29,f31,f0
	f29.f64 = double(float(f31.f64 * f0.f64));
	// lfs f4,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f4.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,-31324(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31324);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r9,-32224
	r11.s64 = ctx.r9.s64 + -32224;
	// fmuls f28,f31,f13
	f28.f64 = double(float(f31.f64 * ctx.f13.f64));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f30,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f30.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f12,14976(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14976);
	ctx.f12.f64 = double(temp.f32);
	// li r4,512
	ctx.r4.s64 = 512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f27,f31,f12
	f27.f64 = double(float(f31.f64 * ctx.f12.f64));
	// fadds f3,f4,f29
	ctx.f3.f64 = double(float(ctx.f4.f64 + f29.f64));
	// fdivs f2,f3,f31
	ctx.f2.f64 = double(float(ctx.f3.f64 / f31.f64));
	// fadds f0,f2,f0
	f0.f64 = double(float(ctx.f2.f64 + f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r29,100(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82734160
	ctx.lr = 0x82734F80;
	sub_82734160(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// stfs f31,156(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r20,r27
	r20.u64 = r27.u64;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r21,r27
	r21.u64 = r27.u64;
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// mr r24,r22
	r24.u64 = r22.u64;
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r25,r22
	r25.u64 = r22.u64;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// mr r26,r22
	r26.u64 = r22.u64;
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f1,f11,f12
	ctx.f1.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// stfs f31,144(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f29,160(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f30,164(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f29,168(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// bl 0x823dba38
	ctx.lr = 0x82734FD8;
	sub_823DBA38(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f9,92(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f1,f8,f9
	ctx.f1.f64 = double(float(ctx.f8.f64 / ctx.f9.f64));
	// fctiwz f7,f10
	ctx.f7.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f7.u64);
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823dba38
	ctx.lr = 0x82734FF8;
	sub_823DBA38(ctx, base);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// mullw r7,r29,r29
	ctx.r7.s64 = int64_t(r29.s32) * int64_t(r29.s32);
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r22.u32);
	// rlwinm r15,r7,2,0,29
	r15.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r15,0
	cr6.compare<int32_t>(r15.s32, 0, xer);
	// blt cr6,0x8273525c
	if (cr6.lt) goto loc_8273525C;
	// lwz r17,112(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r14,120(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// add r23,r11,r17
	r23.u64 = r11.u64 + r17.u64;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// li r19,-1
	r19.s64 = -1;
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r18,-1
	r18.s64 = -1;
	// lfs f29,-14120(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -14120);
	f29.f64 = double(temp.f32);
	// mr r29,r17
	r29.u64 = r17.u64;
	// mr r28,r14
	r28.u64 = r14.u64;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r30,r30,r14
	r30.u64 = r30.u64 + r14.u64;
loc_82735054:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x827351a0
	if (cr6.lt) goto loc_827351A0;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x827351a0
	if (!cr6.lt) goto loc_827351A0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x827351a0
	if (cr6.lt) goto loc_827351A0;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bge cr6,0x827351a0
	if (!cr6.lt) goto loc_827351A0;
	// mullw r11,r29,r11
	r11.s64 = int64_t(r29.s32) * int64_t(r11.s32);
	// add. r5,r11,r28
	ctx.r5.u64 = r11.u64 + r28.u64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble 0x827351a0
	if (!cr0.gt) goto loc_827351A0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827351a0
	if (cr6.eq) goto loc_827351A0;
	// extsw r9,r30
	ctx.r9.s64 = r30.s32;
	// stfs f30,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// extsw r10,r23
	ctx.r10.s64 = r23.s32;
	// vor128 v56,v126,v126
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f0,120(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,136(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stfs f30,140(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r17,-1
	ctx.r4.s64 = r17.s64 + -1;
	// cmpw cr6,r29,r4
	cr6.compare<int32_t>(r29.s32, ctx.r4.s32, xer);
	// lfsx f0,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v56,v55,v127,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v127.f32)), simde_mm_load_ps(v56.f32)));
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8273512c
	if (cr6.lt) goto loc_8273512C;
	// addi r11,r17,1
	r11.s64 = r17.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bgt cr6,0x8273512c
	if (cr6.gt) goto loc_8273512C;
	// addi r11,r14,-1
	r11.s64 = r14.s64 + -1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8273512c
	if (cr6.lt) goto loc_8273512C;
	// addi r11,r14,1
	r11.s64 = r14.s64 + 1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bgt cr6,0x8273512c
	if (cr6.gt) goto loc_8273512C;
	// stfs f27,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// b 0x82735130
	goto loc_82735130;
loc_8273512C:
	// stfs f28,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_82735130:
	// lfs f13,4(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r16.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f31,f29
	ctx.f12.f64 = double(float(f31.f64 + f29.f64));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f10,8(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,0(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmuls f3,f11,f11
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f2,f8,f8,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f3.f64));
	// fmadds f0,f5,f5,f2
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fcmpu cr6,f0,f4
	cr6.compare(f0.f64, ctx.f4.f64);
	// bgt cr6,0x82735190
	if (cr6.gt) goto loc_82735190;
	// fsqrts f0,f0
	f0.f64 = double(float(sqrt(f0.f64)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,512
	ctx.r4.s64 = 512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fsel f1,f12,f30,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f30.f64 : ctx.f13.f64;
	// bl 0x82734160
	ctx.lr = 0x8273518C;
	sub_82734160(ctx, base);
	// b 0x827351a0
	goto loc_827351A0;
loc_82735190:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x8273525c
	if (cr6.eq) goto loc_8273525C;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x8273525c
	if (cr6.eq) goto loc_8273525C;
loc_827351A0:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// beq cr6,0x827351fc
	if (cr6.eq) goto loc_827351FC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827351d4
	if (cr6.eq) goto loc_827351D4;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r24,r20
	cr6.compare<int32_t>(r24.s32, r20.s32, xer);
	// bne cr6,0x82735248
	if (!cr6.eq) goto loc_82735248;
	// mr r26,r22
	r26.u64 = r22.u64;
	// b 0x82735244
	goto loc_82735244;
loc_827351D4:
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// cmpw cr6,r24,r18
	cr6.compare<int32_t>(r24.s32, r18.s32, xer);
	// bne cr6,0x82735248
	if (!cr6.eq) goto loc_82735248;
	// mr r26,r22
	r26.u64 = r22.u64;
	// li r27,1
	r27.s64 = 1;
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// addi r18,r18,-1
	r18.s64 = r18.s64 + -1;
	// b 0x82735248
	goto loc_82735248;
loc_827351FC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735224
	if (cr6.eq) goto loc_82735224;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// cmpw cr6,r25,r21
	cr6.compare<int32_t>(r25.s32, r21.s32, xer);
	// bne cr6,0x82735248
	if (!cr6.eq) goto loc_82735248;
	// li r26,1
	r26.s64 = 1;
	// li r27,1
	r27.s64 = 1;
	// b 0x82735248
	goto loc_82735248;
loc_82735224:
	// addi r25,r25,-1
	r25.s64 = r25.s64 + -1;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// cmpw cr6,r25,r19
	cr6.compare<int32_t>(r25.s32, r19.s32, xer);
	// bne cr6,0x82735248
	if (!cr6.eq) goto loc_82735248;
	// li r26,1
	r26.s64 = 1;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r19,r19,-1
	r19.s64 = r19.s64 + -1;
loc_82735244:
	// mr r27,r22
	r27.u64 = r22.u64;
loc_82735248:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// cmpw cr6,r11,r15
	cr6.compare<int32_t>(r11.s32, r15.s32, xer);
	// ble cr6,0x82735054
	if (!cr6.gt) goto loc_82735054;
loc_8273525C:
	// stw r22,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r22.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// li r0,-224
	r0.s64 = -224;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba20
	ctx.lr = 0x8273527C;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82734DB8) {
	__imp__sub_82734DB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	// lhz r9,30(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 30);
	// li r10,-32768
	ctx.r10.s64 = -32768;
	// li r4,1
	ctx.r4.s64 = 1;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// sth r8,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, ctx.r8.u16);
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,156(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 156);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_82735280) {
	__imp__sub_82735280(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827352A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827352A8) {
	__imp__sub_827352A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827352B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827352B4) {
	__imp__sub_827352B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827352B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2272
	ctx.r3.s64 = r11.s64 + 2272;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827352B8) {
	__imp__sub_827352B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827352C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827352C4) {
	__imp__sub_827352C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827352C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827352D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x824900a8
	ctx.lr = 0x827352E0;
	sub_824900A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82735304
	if (cr6.eq) goto loc_82735304;
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82735304
	if (!cr6.gt) goto loc_82735304;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8272f6a0
	ctx.lr = 0x82735304;
	sub_8272F6A0(ctx, base);
loc_82735304:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827352C8) {
	__imp__sub_827352C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82735318;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8248fb40
	ctx.lr = 0x82735328;
	sub_8248FB40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272f750
	ctx.lr = 0x82735338;
	sub_8272F750(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82735310) {
	__imp__sub_82735310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735344) {
	__imp__sub_82735344(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735348) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14924
	ctx.r10.s64 = r11.s64 + -14924;
	// lhz r4,146(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 146);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82735380
	if (cr6.eq) goto loc_82735380;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f1348
	ctx.lr = 0x82735380;
	sub_822F1348(ctx, base);
loc_82735380:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db28
	ctx.lr = 0x82735388;
	sub_8272DB28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82489ce8
	ctx.lr = 0x82735390;
	sub_82489CE8(ctx, base);
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

PPC_WEAK_FUNC(sub_82735348) {
	__imp__sub_82735348(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827353A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827353A4) {
	__imp__sub_827353A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827353A8) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17600(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273541c
	if (cr6.eq) goto loc_8273541C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-17596(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17596);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273541c
	if (cr6.eq) goto loc_8273541C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// bl 0x82689ee8
	ctx.lr = 0x827353E8;
	sub_82689EE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735414
	if (cr6.eq) goto loc_82735414;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
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
loc_82735414:
	// li r11,0
	r11.s64 = 0;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
loc_8273541C:
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

PPC_WEAK_FUNC(sub_827353A8) {
	__imp__sub_827353A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735434) {
	__imp__sub_82735434(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735438) {
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
	// bl 0x8248af18
	ctx.lr = 0x82735450;
	sub_8248AF18(ctx, base);
	// lhz r4,146(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 146);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273546c
	if (cr6.eq) goto loc_8273546C;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f1358
	ctx.lr = 0x8273546C;
	sub_822F1358(ctx, base);
loc_8273546C:
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

PPC_WEAK_FUNC(sub_82735438) {
	__imp__sub_82735438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735480) {
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
	ctx.lr = 0x82735488;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r10,-12497(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12497);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735508
	if (cr6.eq) goto loc_82735508;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// lwz r11,-21552(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21552);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827354dc
	if (!cr6.eq) goto loc_827354DC;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r11,-21552(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21552, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-16732
	ctx.r4.s64 = ctx.r9.s64 + -16732;
	// bl 0x82144a20
	ctx.lr = 0x827354D8;
	sub_82144A20(ctx, base);
	// stw r3,-21556(r30)
	PPC_STORE_U32(r30.u32 + -21556, ctx.r3.u32);
loc_827354DC:
	// lwz r4,176(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x827354f4
	if (cr6.eq) goto loc_827354F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a20
	ctx.lr = 0x827354F0;
	sub_82144A20(ctx, base);
	// stw r3,352(r29)
	PPC_STORE_U32(r29.u32 + 352, ctx.r3.u32);
loc_827354F4:
	// lwz r11,352(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 352);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82735504
	if (!cr6.eq) goto loc_82735504;
	// lwz r11,-21556(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21556);
loc_82735504:
	// stw r11,352(r29)
	PPC_STORE_U32(r29.u32 + 352, r11.u32);
loc_82735508:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82735480) {
	__imp__sub_82735480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735510) {
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
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82740f18
	ctx.lr = 0x82735534;
	sub_82740F18(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r9,r10,-14656
	ctx.r9.s64 = ctx.r10.s64 + -14656;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lhz r7,30(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// clrlwi r6,r7,17
	ctx.r6.u64 = ctx.r7.u32 & 0x7FFF;
	// sth r8,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r8.u16);
	// sth r6,30(r31)
	PPC_STORE_U16(r31.u32 + 30, ctx.r6.u16);
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

PPC_WEAK_FUNC(sub_82735510) {
	__imp__sub_82735510(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735580) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10404(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10404);
	// bl 0x82734a48
	ctx.lr = 0x827355A8;
	sub_82734A48(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-3660(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3660);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827355d8
	if (cr6.eq) goto loc_827355D8;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827355d8
	if (cr6.eq) goto loc_827355D8;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x827355d8
	if (!cr6.eq) goto loc_827355D8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226adb0
	ctx.lr = 0x827355D8;
	sub_8226ADB0(ctx, base);
loc_827355D8:
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

PPC_WEAK_FUNC(sub_82735580) {
	__imp__sub_82735580(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827355EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827355EC) {
	__imp__sub_827355EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827355F0) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8248a510
	ctx.lr = 0x8273560C;
	sub_8248A510(ctx, base);
	// lwz r11,336(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 336);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,340(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 340);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lfs f1,344(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 344);
	ctx.f1.f64 = double(temp.f32);
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

PPC_WEAK_FUNC(sub_827355F0) {
	__imp__sub_827355F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735634) {
	__imp__sub_82735634(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735638) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x8248a510
	ctx.lr = 0x8273564C;
	sub_8248A510(ctx, base);
	// lfs f1,344(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 344);
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

PPC_WEAK_FUNC(sub_82735638) {
	__imp__sub_82735638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82735668;
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
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
	// vpermwi128 v127,v62,234
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v126,v62,186
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v125,v62,174
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// bl 0x8248a510
	ctx.lr = 0x827356A4;
	sub_8248A510(ctx, base);
	// lwz r3,180(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735724
	if (cr6.eq) goto loc_82735724;
	// lwz r30,12(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82735724
	if (cr6.eq) goto loc_82735724;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827356D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735724
	if (cr6.eq) goto loc_82735724;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r9,96
	ctx.r9.s64 = 96;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mulli r10,r10,224
	ctx.r10.s64 = ctx.r10.s64 * 224;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lvx128 v60,r8,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// beq cr6,0x8273571c
	if (cr6.eq) goto loc_8273571C;
	// li r11,16
	r11.s64 = 16;
	// stvx128 v127,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// stvx128 v126,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8273571C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82735728
	goto loc_82735728;
loc_82735724:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82735728:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82735660) {
	__imp__sub_82735660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735748) {
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
	// bl 0x8248c058
	ctx.lr = 0x82735760;
	sub_8248C058(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x82735768;
	sub_8248A510(ctx, base);
	// bl 0x8249e270
	ctx.lr = 0x8273576C;
	sub_8249E270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82735798
	if (!cr6.eq) goto loc_82735798;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,2048
	ctx.r4.s64 = 2048;
	// bl 0x8258e640
	ctx.lr = 0x82735788;
	sub_8258E640(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,256
	ctx.r4.s64 = 256;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8258e640
	ctx.lr = 0x82735798;
	sub_8258E640(ctx, base);
loc_82735798:
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

PPC_WEAK_FUNC(sub_82735748) {
	__imp__sub_82735748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827357AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827357AC) {
	__imp__sub_827357AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827357B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r4,146(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 146);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// b 0x822f1358
	sub_822F1358(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827357B0) {
	__imp__sub_827357B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827357CC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827357CC) {
	__imp__sub_827357CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827357D0) {
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
	// addi r10,r11,-14924
	ctx.r10.s64 = r11.s64 + -14924;
	// lhz r4,146(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 146);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82735810
	if (cr6.eq) goto loc_82735810;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f1348
	ctx.lr = 0x82735810;
	sub_822F1348(ctx, base);
loc_82735810:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db28
	ctx.lr = 0x82735818;
	sub_8272DB28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82489ce8
	ctx.lr = 0x82735820;
	sub_82489CE8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735838
	if (cr6.eq) goto loc_82735838;
	// bl 0x82130588
	ctx.lr = 0x82735834;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82735838:
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

PPC_WEAK_FUNC(sub_827357D0) {
	__imp__sub_827357D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735850) {
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
	// lwz r11,156(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273587c
	if (cr6.eq) goto loc_8273587C;
	// bl 0x8248a510
	ctx.lr = 0x8273586C;
	sub_8248A510(ctx, base);
	// lwz r11,348(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82735880
	if (!cr6.eq) goto loc_82735880;
loc_8273587C:
	// li r11,0
	r11.s64 = 0;
loc_82735880:
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

PPC_WEAK_FUNC(sub_82735850) {
	__imp__sub_82735850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735894) {
	__imp__sub_82735894(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735898) {
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
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827358fc
	if (cr6.eq) goto loc_827358FC;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// sth r11,146(r31)
	PPC_STORE_U16(r31.u32 + 146, r11.u16);
	// lwz r11,-7572(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827358fc
	if (cr6.eq) goto loc_827358FC;
	// bl 0x8248a510
	ctx.lr = 0x827358D8;
	sub_8248A510(ctx, base);
	// lwz r4,348(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827358fc
	if (cr6.eq) goto loc_827358FC;
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822f1338
	ctx.lr = 0x827358F8;
	sub_822F1338(ctx, base);
	// sth r3,146(r31)
	PPC_STORE_U16(r31.u32 + 146, ctx.r3.u16);
loc_827358FC:
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

PPC_WEAK_FUNC(sub_82735898) {
	__imp__sub_82735898(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735914) {
	__imp__sub_82735914(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735918) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x82735934;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x8273593C;
	sub_8248A510(ctx, base);
	// lwz r30,352(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 352);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r10,86(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 86);
	// lwz r11,-32452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32452);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82735a20
	if (cr6.eq) goto loc_82735A20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82735968;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,62(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 62);
	// rlwinm r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82735998
	if (cr6.eq) goto loc_82735998;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735998
	if (cr6.eq) goto loc_82735998;
	// lhz r11,32(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// b 0x8273599c
	goto loc_8273599C;
loc_82735998:
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
loc_8273599C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f13,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,90(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 90);
	// addi r9,r11,-12352
	ctx.r9.s64 = r11.s64 + -12352;
	// lfs f11,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,52(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	f0.f64 = double(temp.f32);
	// fmuls f9,f10,f10
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fsubs f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	f0.f64 = double(temp.f32);
	// fsubs f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f6,f11,f0
	ctx.f6.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fmuls f5,f8,f8
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f4,f7,f7,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f5.f64));
	// fmadds f1,f6,f6,f4
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f1,f9
	cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// bgt cr6,0x82735a18
	if (cr6.gt) goto loc_82735A18;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735a0c
	if (cr6.eq) goto loc_82735A0C;
	// lbz r11,85(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 85);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735a18
	if (cr6.eq) goto loc_82735A18;
loc_82735A0C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272f4b0
	ctx.lr = 0x82735A14;
	sub_8272F4B0(ctx, base);
	// b 0x82735a20
	goto loc_82735A20;
loc_82735A18:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272dae8
	ctx.lr = 0x82735A20;
	sub_8272DAE8(ctx, base);
loc_82735A20:
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

PPC_WEAK_FUNC(sub_82735918) {
	__imp__sub_82735918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735A38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735a88
	if (cr6.eq) goto loc_82735A88;
	// lwz r10,376(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 376);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735a88
	if (cr6.eq) goto loc_82735A88;
	// lwz r11,364(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82735a88
	if (!cr6.eq) goto loc_82735A88;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lhz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwz r11,-23452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// cmpwi cr6,r7,2
	cr6.compare<int32_t>(ctx.r7.s32, 2, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_82735A88:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82735A38) {
	__imp__sub_82735A38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735A90) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// bl 0x82489dc0
	ctx.lr = 0x82735AD4;
	sub_82489DC0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// bl 0x82741078
	ctx.lr = 0x82735AFC;
	sub_82741078(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,92(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// bl 0x822a7c08
	ctx.lr = 0x82735B08;
	sub_822A7C08(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82735b4c
	if (!cr6.eq) goto loc_82735B4C;
loc_82735B14:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,320(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 320);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stfs f0,44(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 44, temp.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// bl 0x822a7c08
	ctx.lr = 0x82735B40;
	sub_822A7C08(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82735b14
	if (cr6.eq) goto loc_82735B14;
loc_82735B4C:
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

PPC_WEAK_FUNC(sub_82735A90) {
	__imp__sub_82735A90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735B64) {
	__imp__sub_82735B64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735B68) {
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
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8249ee08
	ctx.lr = 0x82735B84;
	sub_8249EE08(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-14616
	ctx.r9.s64 = r11.s64 + -14616;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,336(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// stfs f0,340(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// stw r11,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r11.u32);
	// stfs f0,344(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stw r11,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r11.u32);
	// stw r11,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r11.u32);
	// stw r11,360(r31)
	PPC_STORE_U32(r31.u32 + 360, r11.u32);
	// stw r11,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r11.u32);
	// bl 0x82735480
	ctx.lr = 0x82735BC4;
	sub_82735480(ctx, base);
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

PPC_WEAK_FUNC(sub_82735B68) {
	__imp__sub_82735B68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735BDC) {
	__imp__sub_82735BDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735BE0) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822fe3a8
	ctx.lr = 0x82735BFC;
	sub_822FE3A8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735c74
	if (cr6.eq) goto loc_82735C74;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735c2c
	if (cr6.eq) goto loc_82735C2C;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x82735C20;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x82735c30
	if (!cr6.eq) goto loc_82735C30;
loc_82735C2C:
	// lwz r4,176(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 176);
loc_82735C30:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f8718
	ctx.lr = 0x82735C40;
	sub_822F8718(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735c74
	if (cr6.eq) goto loc_82735C74;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x82735C54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735c64
	if (cr6.eq) goto loc_82735C64;
	// bl 0x822fe3a8
	ctx.lr = 0x82735C60;
	sub_822FE3A8(ctx, base);
	// b 0x82735c68
	goto loc_82735C68;
loc_82735C64:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82735C68:
	// stw r3,348(r31)
	PPC_STORE_U32(r31.u32 + 348, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822f1538
	ctx.lr = 0x82735C74;
	sub_822F1538(ctx, base);
loc_82735C74:
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

PPC_WEAK_FUNC(sub_82735BE0) {
	__imp__sub_82735BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735C88) {
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
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-14656
	ctx.r8.s64 = ctx.r10.s64 + -14656;
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// rlwinm r7,r11,0,16,16
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x82735cf4
	if (cr6.eq) goto loc_82735CF4;
	// clrlwi r11,r11,17
	r11.u64 = r11.u32 & 0x7FFF;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// sth r11,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r11.u16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10404(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10404);
	// bl 0x827349d8
	ctx.lr = 0x82735CDC;
	sub_827349D8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,-3660(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3660);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735cf4
	if (cr6.eq) goto loc_82735CF4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226a930
	ctx.lr = 0x82735CF4;
	sub_8226A930(ctx, base);
loc_82735CF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82740ec0
	ctx.lr = 0x82735CFC;
	sub_82740EC0(ctx, base);
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

PPC_WEAK_FUNC(sub_82735C88) {
	__imp__sub_82735C88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735D10) {
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
	// bl 0x82735c88
	ctx.lr = 0x82735D30;
	sub_82735C88(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735d48
	if (cr6.eq) goto loc_82735D48;
	// bl 0x82130588
	ctx.lr = 0x82735D44;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82735D48:
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

PPC_WEAK_FUNC(sub_82735D10) {
	__imp__sub_82735D10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735D60) {
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
	// bl 0x8249efb8
	ctx.lr = 0x82735D78;
	sub_8249EFB8(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-14616
	ctx.r10.s64 = r11.s64 + -14616;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82735be0
	ctx.lr = 0x82735D8C;
	sub_82735BE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735480
	ctx.lr = 0x82735D94;
	sub_82735480(ctx, base);
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

PPC_WEAK_FUNC(sub_82735D60) {
	__imp__sub_82735D60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735DAC) {
	__imp__sub_82735DAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735DB0) {
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
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r30,12(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// beq cr6,0x82735e20
	if (cr6.eq) goto loc_82735E20;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bne cr6,0x82735e20
	if (!cr6.eq) goto loc_82735E20;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82599f10
	ctx.lr = 0x82735DF0;
	sub_82599F10(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ble cr6,0x82735e54
	if (!cr6.gt) goto loc_82735E54;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,24408
	ctx.r6.s64 = ctx.r10.s64 + 24408;
	// addi r5,r9,24380
	ctx.r5.s64 = ctx.r9.s64 + 24380;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823dedd8
	ctx.lr = 0x82735E1C;
	sub_823DEDD8(ctx, base);
	// b 0x82735e2c
	goto loc_82735E2C;
loc_82735E20:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82735e54
	if (!cr6.eq) goto loc_82735E54;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82735E2C:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735e54
	if (cr6.eq) goto loc_82735E54;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,128(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,344(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,336(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// stfs f12,340(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// b 0x82735ec8
	goto loc_82735EC8;
loc_82735E54:
	// lfs f0,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	f0.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fabs f10,f13
	ctx.f10.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lfs f11,16(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,32(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fabs f7,f9
	ctx.f7.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// addi r11,r31,336
	r11.s64 = r31.s64 + 336;
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fsubs f6,f10,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsubs f5,f7,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fsel f4,f6,f10,f12
	ctx.f4.f64 = ctx.f6.f64 >= 0.0 ? ctx.f10.f64 : ctx.f12.f64;
	// stfs f4,340(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// fsel f3,f5,f7,f8
	ctx.f3.f64 = ctx.f5.f64 >= 0.0 ? ctx.f7.f64 : ctx.f8.f64;
	// stfs f3,336(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// fmuls f13,f1,f1
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fmadds f12,f2,f2,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f13.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// stfs f11,344(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// lfs f10,336(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 336);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,340(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 340);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f8,336(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f7,340(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
loc_82735EC8:
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

PPC_WEAK_FUNC(sub_82735DB0) {
	__imp__sub_82735DB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735EE0) {
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
	ctx.lr = 0x82735EE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82735f4c
	if (cr6.eq) goto loc_82735F4C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82735f4c
	if (cr6.eq) goto loc_82735F4C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82735F1C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82735f4c
	if (cr6.eq) goto loc_82735F4C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82735F30;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x821c96f8
	ctx.lr = 0x82735F44;
	sub_821C96F8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82735F4C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82735EE0) {
	__imp__sub_82735EE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82735F5C) {
	__imp__sub_82735F5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735F60) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82735f9c
	if (cr6.eq) goto loc_82735F9C;
	// bl 0x8249efb8
	ctx.lr = 0x82735F80;
	sub_8249EFB8(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-14616
	ctx.r10.s64 = r11.s64 + -14616;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82735be0
	ctx.lr = 0x82735F94;
	sub_82735BE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735480
	ctx.lr = 0x82735F9C;
	sub_82735480(ctx, base);
loc_82735F9C:
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

PPC_WEAK_FUNC(sub_82735F60) {
	__imp__sub_82735F60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82735FB0) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82735FB8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x8248aa28
	ctx.lr = 0x82735FCC;
	sub_8248AA28(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r23,r28,152
	r23.s64 = r28.s64 + 152;
	// addi r10,r11,-14924
	ctx.r10.s64 = r11.s64 + -14924;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x82735ee0
	ctx.lr = 0x82735FE4;
	sub_82735EE0(ctx, base);
	// addi r24,r28,156
	r24.s64 = r28.s64 + 156;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82735ee0
	ctx.lr = 0x82735FF0;
	sub_82735EE0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// clrlwi r8,r31,24
	ctx.r8.u64 = r31.u32 & 0xFF;
	// stb r31,145(r28)
	PPC_STORE_U8(r28.u32 + 145, r31.u8);
	// stb r9,144(r28)
	PPC_STORE_U8(r28.u32 + 144, ctx.r9.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82736010
	if (cr6.eq) goto loc_82736010;
	// li r11,3
	r11.s64 = 3;
	// b 0x82736044
	goto loc_82736044;
loc_82736010:
	// lwz r3,92(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 92);
	// bl 0x8249e270
	ctx.lr = 0x82736018;
	sub_8249E270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82736040
	if (!cr6.eq) goto loc_82736040;
	// lwz r11,92(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 92);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// li r11,2
	r11.s64 = 2;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82736044
	if (cr6.lt) goto loc_82736044;
loc_82736040:
	// li r11,1
	r11.s64 = 1;
loc_82736044:
	// stw r11,128(r28)
	PPC_STORE_U32(r28.u32 + 128, r11.u32);
	// li r22,0
	r22.s64 = 0;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r27,r22
	r27.u64 = r22.u64;
	// stw r22,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r22.u32);
	// addi r25,r11,-14604
	r25.s64 = r11.s64 + -14604;
loc_8273605C:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8273606C;
	sub_823DC018(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82735660
	ctx.lr = 0x8273607C;
	sub_82735660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736094
	if (cr6.eq) goto loc_82736094;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpwi cr6,r27,100
	cr6.compare<int32_t>(r27.s32, 100, xer);
	// blt cr6,0x8273605c
	if (cr6.lt) goto loc_8273605C;
loc_82736094:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x827361dc
	if (cr6.eq) goto loc_827361DC;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x827360A4;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827360d0
	if (cr6.eq) goto loc_827360D0;
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// rlwinm r3,r27,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// bl 0x82130528
	ctx.lr = 0x827360C4;
	sub_82130528(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x827360d4
	goto loc_827360D4;
loc_827360D0:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_827360D4:
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x827360E0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273610c
	if (cr6.eq) goto loc_8273610C;
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// rlwinm r3,r27,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// bl 0x82130528
	ctx.lr = 0x82736100;
	sub_82130528(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x82736110
	goto loc_82736110;
loc_8273610C:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82736110:
	// stw r11,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r11.u32);
	// mr r31,r22
	r31.u64 = r22.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82736180
	if (!cr6.gt) goto loc_82736180;
	// mr r29,r22
	r29.u64 = r22.u64;
	// mr r30,r22
	r30.u64 = r22.u64;
	// li r26,-1
	r26.s64 = -1;
loc_8273612C:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8273613C;
	sub_823DC018(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82735660
	ctx.lr = 0x8273614C;
	sub_82735660(ctx, base);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r23)
	ctx.r8.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// stwx r26,r7,r29
	PPC_STORE_U32(ctx.r7.u32 + r29.u32, r26.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// blt cr6,0x8273612c
	if (cr6.lt) goto loc_8273612C;
loc_82736180:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827361e0
	if (cr6.eq) goto loc_827361E0;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// sth r22,146(r28)
	PPC_STORE_U16(r28.u32 + 146, r22.u16);
	// lwz r11,-7572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827361e0
	if (cr6.eq) goto loc_827361E0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8248a510
	ctx.lr = 0x827361A8;
	sub_8248A510(ctx, base);
	// lwz r4,348(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827361e0
	if (cr6.eq) goto loc_827361E0;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r6,r28,16
	ctx.r6.s64 = r28.s64 + 16;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822f1338
	ctx.lr = 0x827361C8;
	sub_822F1338(ctx, base);
	// sth r3,146(r28)
	PPC_STORE_U16(r28.u32 + 146, ctx.r3.u16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r22,148(r28)
	PPC_STORE_U32(r28.u32 + 148, r22.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_827361DC:
	// sth r22,146(r28)
	PPC_STORE_U16(r28.u32 + 146, r22.u16);
loc_827361E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r22,148(r28)
	PPC_STORE_U32(r28.u32 + 148, r22.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82735FB0) {
	__imp__sub_82735FB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827361F0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8248c620
	ctx.lr = 0x82736208;
	sub_8248C620(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// addi r10,r11,-14924
	ctx.r10.s64 = r11.s64 + -14924;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82735ee0
	ctx.lr = 0x8273621C;
	sub_82735EE0(ctx, base);
	// addi r3,r31,156
	ctx.r3.s64 = r31.s64 + 156;
	// bl 0x82735ee0
	ctx.lr = 0x82736224;
	sub_82735EE0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825953b0
	ctx.lr = 0x82736234;
	sub_825953B0(ctx, base);
	// lbz r9,145(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 145);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273624c
	if (cr6.eq) goto loc_8273624C;
	// li r11,3
	r11.s64 = 3;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// b 0x8273629c
	goto loc_8273629C;
loc_8273624C:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x8249e270
	ctx.lr = 0x82736254;
	sub_8249E270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82736284
	if (!cr6.eq) goto loc_82736284;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82736284
	if (!cr6.lt) goto loc_82736284;
	// li r11,2
	r11.s64 = 2;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// b 0x8273629c
	goto loc_8273629C;
loc_82736284:
	// li r11,1
	r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825953b0
	ctx.lr = 0x8273629C;
	sub_825953B0(ctx, base);
loc_8273629C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17600(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736384
	if (cr6.eq) goto loc_82736384;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-17596(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17596);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82736384
	if (cr6.eq) goto loc_82736384;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// bl 0x82689ee8
	ctx.lr = 0x827362C8;
	sub_82689EE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273637c
	if (cr6.eq) goto loc_8273637C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// rlwinm r4,r11,16,24,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// rlwinm r3,r11,24,24,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// fcfid f8,f12
	ctx.f8.f64 = double(ctx.f12.s64);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f0,-14596(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -14596);
	f0.f64 = double(temp.f32);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// lfs f13,15360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15360);
	ctx.f13.f64 = double(temp.f32);
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// lis r11,-1
	r11.s64 = -65536;
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// fmuls f4,f7,f0
	ctx.f4.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64));
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// fmuls f1,f4,f13
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fmuls f12,f2,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fmuls f0,f3,f0
	f0.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fctiwz f11,f1
	ctx.f11.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f9,f12
	ctx.f9.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmuls f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64));
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// fctiwz f8,f10
	ctx.f8.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwimi r11,r8,8,16,23
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r6,r11,r7
	ctx.r6.u64 = r11.u64 | ctx.r7.u64;
	// rlwimi r9,r6,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r9.u32);
	// b 0x82736384
	goto loc_82736384;
loc_8273637C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
loc_82736384:
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

PPC_WEAK_FUNC(sub_827361F0) {
	__imp__sub_827361F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273639C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273639C) {
	__imp__sub_8273639C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827363A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lbz r10,144(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32141
	r12.s64 = -2106392576;
	// addi r12,r12,25552
	r12.s64 = r12.s64 + 25552;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_827363A0) {
	__imp__sub_827363A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827363D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r19{};
	// lwz r19,25588(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25588);
	// lwz r19,25604(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25604);
	// lwz r19,25680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25680);
	// lwz r19,25680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25680);
	// lwz r19,25680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25680);
	// lwz r19,25620(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25620);
	// lwz r19,25636(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25636);
	// lwz r19,25652(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25652);
	// lwz r19,25664(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x827361f0
	sub_827361F0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827363D0) {
	__imp__sub_827363D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736404) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x82737d68
	sub_82737D68(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82736404) {
	__imp__sub_82736404(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736414) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x8272f9b8
	sub_8272F9B8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82736414) {
	__imp__sub_82736414(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736424) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x82737968
	sub_82737968(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82736424) {
	__imp__sub_82736424(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736434) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-14592
	ctx.r3.s64 = r11.s64 + -14592;
	// b 0x821bd618
	sub_821BD618(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82736434) {
	__imp__sub_82736434(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736440) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x827376e0
	sub_827376E0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82736440) {
	__imp__sub_82736440(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736450) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82736450) {
	__imp__sub_82736450(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736454) {
	__imp__sub_82736454(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736458) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,20284
	ctx.r3.s64 = r11.s64 + 20284;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82736458) {
	__imp__sub_82736458(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736464) {
	__imp__sub_82736464(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21132);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82736468) {
	__imp__sub_82736468(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736474) {
	__imp__sub_82736474(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-14188
	ctx.r3.s64 = r11.s64 + -14188;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82736478) {
	__imp__sub_82736478(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736484) {
	__imp__sub_82736484(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21128);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82736488) {
	__imp__sub_82736488(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736494) {
	__imp__sub_82736494(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736498) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-14156
	ctx.r3.s64 = r11.s64 + -14156;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82736498) {
	__imp__sub_82736498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827364A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827364A4) {
	__imp__sub_827364A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827364A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21124(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21124);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827364A8) {
	__imp__sub_827364A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827364B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827364B4) {
	__imp__sub_827364B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827364B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-14124
	ctx.r3.s64 = r11.s64 + -14124;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827364B8) {
	__imp__sub_827364B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827364C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827364C4) {
	__imp__sub_827364C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827364C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21120(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21120);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827364C8) {
	__imp__sub_827364C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827364D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827364D4) {
	__imp__sub_827364D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827364D8) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827364E0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r31,r11,17268
	r31.s64 = r11.s64 + 17268;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x8273652c
	if (cr6.eq) goto loc_8273652C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82736548
	if (!cr6.gt) goto loc_82736548;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x8273653c
	goto loc_8273653C;
loc_8273652C:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82736548
	if (!cr6.gt) goto loc_82736548;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_8273653C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8273654c
	if (!cr6.eq) goto loc_8273654C;
loc_82736548:
	// li r11,0
	r11.s64 = 0;
loc_8273654C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736634
	if (cr6.eq) goto loc_82736634;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x82736560;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r29,224
	r31.s64 = r29.s64 + 224;
	// lwz r30,1216(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 1216);
	// bl 0x822a3998
	ctx.lr = 0x82736578;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x8273657C;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lfs f0,224(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 224);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f13,228(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,232(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsubs f12,f9,f12
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// beq cr6,0x827365cc
	if (cr6.eq) goto loc_827365CC;
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f11.f64));
	// fmadds f9,f0,f0,f10
	ctx.f9.f64 = double(float(f0.f64 * f0.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// ble cr6,0x827365cc
	if (!cr6.gt) goto loc_827365CC;
	// li r30,0
	r30.s64 = 0;
loc_827365CC:
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736634
	if (cr6.eq) goto loc_82736634;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v1,v63,v61
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// bl 0x8247a588
	ctx.lr = 0x82736620;
	sub_8247A588(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82736634
	if (cr6.eq) goto loc_82736634;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_82736634:
	// stw r30,512(r29)
	PPC_STORE_U32(r29.u32 + 512, r30.u32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r11,-14112
	ctx.r4.s64 = r11.s64 + -14112;
	// bl 0x8247a6a0
	ctx.lr = 0x8273664C;
	sub_8247A6A0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827364D8) {
	__imp__sub_827364D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736658) {
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
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lbz r9,-21548(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -21548);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273668c
	if (cr6.eq) goto loc_8273668C;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x8247a8d0
	sub_8247A8D0(ctx, base);
	return;
loc_8273668C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,136(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
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

PPC_WEAK_FUNC(sub_82736658) {
	__imp__sub_82736658(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827366A8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827366A8) {
	__imp__sub_827366A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827366AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827366AC) {
	__imp__sub_827366AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827366B0) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82130000
	ctx.lr = 0x827366C8;
	sub_82130000(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736730
	if (cr6.eq) goto loc_82736730;
	// lwz r10,612(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 612);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82736730
	if (cr6.eq) goto loc_82736730;
	// rlwinm r10,r10,28,29,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x7;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r8,r10,109
	ctx.r8.s64 = ctx.r10.s64 + 109;
	// addi r7,r9,29952
	ctx.r7.s64 = ctx.r9.s64 + 29952;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfsx f12,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-7176(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -7176);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f11,f0,f13,f12
	ctx.f11.f64 = double(float(-(f0.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsel f10,f11,f11,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// fsel f9,f11,f11,f0
	ctx.f9.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// fsubs f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f7,f8,f13,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f13.f64 : ctx.f9.f64;
	// stfsx f7,r10,r11
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
loc_82736730:
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

PPC_WEAK_FUNC(sub_827366B0) {
	__imp__sub_827366B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736744) {
	__imp__sub_82736744(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736748) {
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
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82130528
	ctx.lr = 0x8273675C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736778
	if (cr6.eq) goto loc_82736778;
	// bl 0x8275e7a8
	ctx.lr = 0x82736768;
	sub_8275E7A8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82736778:
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

PPC_WEAK_FUNC(sub_82736748) {
	__imp__sub_82736748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273678C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273678C) {
	__imp__sub_8273678C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736790) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827367bc
	if (cr6.eq) goto loc_827367BC;
	// bl 0x824905e0
	ctx.lr = 0x827367B0;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14224
	ctx.r10.s64 = r11.s64 + -14224;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_827367BC:
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

PPC_WEAK_FUNC(sub_82736790) {
	__imp__sub_82736790(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827367D0) {
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
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82130528
	ctx.lr = 0x827367E4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736800
	if (cr6.eq) goto loc_82736800;
	// bl 0x8275ed38
	ctx.lr = 0x827367F0;
	sub_8275ED38(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82736800:
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

PPC_WEAK_FUNC(sub_827367D0) {
	__imp__sub_827367D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736814) {
	__imp__sub_82736814(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736818) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82736844
	if (cr6.eq) goto loc_82736844;
	// bl 0x824905e0
	ctx.lr = 0x82736838;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14204
	ctx.r10.s64 = r11.s64 + -14204;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82736844:
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

PPC_WEAK_FUNC(sub_82736818) {
	__imp__sub_82736818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736858) {
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x8273686C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736888
	if (cr6.eq) goto loc_82736888;
	// bl 0x8275ede8
	ctx.lr = 0x82736878;
	sub_8275EDE8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82736888:
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

PPC_WEAK_FUNC(sub_82736858) {
	__imp__sub_82736858(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273689C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273689C) {
	__imp__sub_8273689C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827368A0) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827368cc
	if (cr6.eq) goto loc_827368CC;
	// bl 0x824905e0
	ctx.lr = 0x827368C0;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14172
	ctx.r10.s64 = r11.s64 + -14172;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_827368CC:
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

PPC_WEAK_FUNC(sub_827368A0) {
	__imp__sub_827368A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827368E0) {
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
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x827368F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736910
	if (cr6.eq) goto loc_82736910;
	// bl 0x8275eea0
	ctx.lr = 0x82736900;
	sub_8275EEA0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82736910:
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

PPC_WEAK_FUNC(sub_827368E0) {
	__imp__sub_827368E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736924) {
	__imp__sub_82736924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736928) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82736954
	if (cr6.eq) goto loc_82736954;
	// bl 0x824905e0
	ctx.lr = 0x82736948;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14140
	ctx.r10.s64 = r11.s64 + -14140;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82736954:
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

PPC_WEAK_FUNC(sub_82736928) {
	__imp__sub_82736928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736968) {
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
	// bl 0x821d2028
	ctx.lr = 0x82736988;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827369a0
	if (cr6.eq) goto loc_827369A0;
	// bl 0x82130588
	ctx.lr = 0x8273699C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827369A0:
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

PPC_WEAK_FUNC(sub_82736968) {
	__imp__sub_82736968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827369B8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82736a44
	if (cr6.eq) goto loc_82736A44;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827369f8
	if (cr6.eq) goto loc_827369F8;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r4,r11,-14072
	ctx.r4.s64 = r11.s64 + -14072;
	// bl 0x8247bc80
	ctx.lr = 0x827369F0;
	sub_8247BC80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82736a18
	if (!cr6.lt) goto loc_82736A18;
loc_827369F8:
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// rlwinm r10,r11,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r10,612(r31)
	PPC_STORE_U32(r31.u32 + 612, ctx.r10.u32);
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
loc_82736A18:
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r3,109
	ctx.r9.s64 = ctx.r3.s64 + 109;
	// rlwinm r8,r11,0,28,24
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF8F;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// or r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 | ctx.r10.u64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r4,r6,8
	ctx.r4.u64 = ctx.r6.u64 | 8;
	// lfs f0,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r4,612(r31)
	PPC_STORE_U32(r31.u32 + 612, ctx.r4.u32);
	// stfsx f0,r5,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, temp.u32);
loc_82736A44:
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

PPC_WEAK_FUNC(sub_827369B8) {
	__imp__sub_827369B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736A58) {
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
	// beq cr6,0x82736ad0
	if (cr6.eq) goto loc_82736AD0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82736a94
	if (cr6.eq) goto loc_82736A94;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82736A90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82736a9c
	goto loc_82736A9C;
loc_82736A94:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_82736A9C:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-29148
	ctx.r4.s64 = r11.s64 + -29148;
	// bl 0x823d9188
	ctx.lr = 0x82736AA8;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82736ad0
	if (cr6.eq) goto loc_82736AD0;
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
loc_82736AD0:
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

PPC_WEAK_FUNC(sub_82736A58) {
	__imp__sub_82736A58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736AE8) {
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
	// beq cr6,0x82736b60
	if (cr6.eq) goto loc_82736B60;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82736b24
	if (cr6.eq) goto loc_82736B24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82736B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82736b2c
	goto loc_82736B2C;
loc_82736B24:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_82736B2C:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-28760
	ctx.r4.s64 = r11.s64 + -28760;
	// bl 0x823d9188
	ctx.lr = 0x82736B38;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82736b60
	if (cr6.eq) goto loc_82736B60;
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
loc_82736B60:
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

PPC_WEAK_FUNC(sub_82736AE8) {
	__imp__sub_82736AE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736B78) {
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
	// beq cr6,0x82736bf0
	if (cr6.eq) goto loc_82736BF0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82736bb4
	if (cr6.eq) goto loc_82736BB4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82736BB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82736bbc
	goto loc_82736BBC;
loc_82736BB4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_82736BBC:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-29220
	ctx.r4.s64 = r11.s64 + -29220;
	// bl 0x823d9188
	ctx.lr = 0x82736BC8;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82736bf0
	if (cr6.eq) goto loc_82736BF0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
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
loc_82736BF0:
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

PPC_WEAK_FUNC(sub_82736B78) {
	__imp__sub_82736B78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736C08) {
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
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736c3c
	if (cr6.eq) goto loc_82736C3C;
	// bl 0x821bbea8
	ctx.lr = 0x82736C3C;
	sub_821BBEA8(ctx, base);
loc_82736C3C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21120(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21120);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82736c54
	if (cr6.eq) goto loc_82736C54;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x82736C54;
	sub_821BFA90(ctx, base);
loc_82736C54:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736c60
	if (cr6.eq) goto loc_82736C60;
	// bl 0x821bbf00
	ctx.lr = 0x82736C60;
	sub_821BBF00(ctx, base);
loc_82736C60:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736c7c
	if (cr6.eq) goto loc_82736C7C;
	// bl 0x821bbea8
	ctx.lr = 0x82736C7C;
	sub_821BBEA8(ctx, base);
loc_82736C7C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21124(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21124);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82736c94
	if (cr6.eq) goto loc_82736C94;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x82736C94;
	sub_821BFA90(ctx, base);
loc_82736C94:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736ca0
	if (cr6.eq) goto loc_82736CA0;
	// bl 0x821bbf00
	ctx.lr = 0x82736CA0;
	sub_821BBF00(ctx, base);
loc_82736CA0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736cbc
	if (cr6.eq) goto loc_82736CBC;
	// bl 0x821bbea8
	ctx.lr = 0x82736CBC;
	sub_821BBEA8(ctx, base);
loc_82736CBC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21128(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21128);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82736cd4
	if (cr6.eq) goto loc_82736CD4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x82736CD4;
	sub_821BFA90(ctx, base);
loc_82736CD4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736ce0
	if (cr6.eq) goto loc_82736CE0;
	// bl 0x821bbf00
	ctx.lr = 0x82736CE0;
	sub_821BBF00(ctx, base);
loc_82736CE0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736cfc
	if (cr6.eq) goto loc_82736CFC;
	// bl 0x821bbea8
	ctx.lr = 0x82736CFC;
	sub_821BBEA8(ctx, base);
loc_82736CFC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21132(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21132);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82736d14
	if (cr6.eq) goto loc_82736D14;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x82736D14;
	sub_821BFA90(ctx, base);
loc_82736D14:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736d20
	if (cr6.eq) goto loc_82736D20;
	// bl 0x821bbf00
	ctx.lr = 0x82736D20;
	sub_821BBF00(ctx, base);
loc_82736D20:
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

PPC_WEAK_FUNC(sub_82736C08) {
	__imp__sub_82736C08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736D38) {
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
	ctx.lr = 0x82736D40;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
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
	ctx.lr = 0x82736D5C;
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
	ctx.lr = 0x82736D70;
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
	ctx.lr = 0x82736D84;
	sub_824A5B20(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82736db0
	if (cr6.eq) goto loc_82736DB0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,116(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// bl 0x824a5b00
	ctx.lr = 0x82736D9C;
	sub_824A5B00(ctx, base);
	// bl 0x82736a58
	ctx.lr = 0x82736DA0;
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
	// blt cr6,0x82736ef4
	if (cr6.lt) goto loc_82736EF4;
loc_82736DB0:
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
	ctx.lr = 0x82736DCC;
	sub_824804D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// bne cr6,0x82736e0c
	if (!cr6.eq) goto loc_82736E0C;
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
	ctx.lr = 0x82736DF4;
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
	ctx.lr = 0x82736E08;
	sub_824804D0(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_82736E0C:
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736ef4
	if (cr6.eq) goto loc_82736EF4;
	// addi r4,r27,32
	ctx.r4.s64 = r27.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a178
	ctx.lr = 0x82736E24;
	sub_8247A178(ctx, base);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82736e78
	if (cr6.eq) goto loc_82736E78;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r4,r11,-14112
	ctx.r4.s64 = r11.s64 + -14112;
	// bl 0x8247bc80
	ctx.lr = 0x82736E40;
	sub_8247BC80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82736e78
	if (cr6.lt) goto loc_82736E78;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,25816
	ctx.r4.s64 = r11.s64 + 25816;
	// bl 0x822ed130
	ctx.lr = 0x82736E58;
	sub_822ED130(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r7,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r7.u32);
loc_82736E78:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736ea8
	if (cr6.eq) goto loc_82736EA8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// bl 0x824a5b00
	ctx.lr = 0x82736E90;
	sub_824A5B00(ctx, base);
	// bl 0x82736ae8
	ctx.lr = 0x82736E94;
	sub_82736AE8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8247a128
	ctx.lr = 0x82736EA4;
	sub_8247A128(ctx, base);
	// b 0x82736ee0
	goto loc_82736EE0;
loc_82736EA8:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736ef4
	if (cr6.eq) goto loc_82736EF4;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,108(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// bl 0x824a5b00
	ctx.lr = 0x82736EC0;
	sub_824A5B00(ctx, base);
	// bl 0x82736b78
	ctx.lr = 0x82736EC4;
	sub_82736B78(ctx, base);
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
	ctx.lr = 0x82736EE0;
	sub_8247A020(ctx, base);
loc_82736EE0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827369b8
	ctx.lr = 0x82736EEC;
	sub_827369B8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a838
	ctx.lr = 0x82736EF4;
	sub_8247A838(ctx, base);
loc_82736EF4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82736D38) {
	__imp__sub_82736D38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82736EFC) {
	__imp__sub_82736EFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736F00) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,26440
	ctx.r5.s64 = r11.s64 + 26440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x82736F30;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,26512
	ctx.r5.s64 = ctx.r5.s64 + 26512;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x82736F80;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82736FC4;
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

PPC_WEAK_FUNC(sub_82736F00) {
	__imp__sub_82736F00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82736FD8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,26576
	ctx.r5.s64 = r11.s64 + 26576;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x82737008;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,26648
	ctx.r5.s64 = ctx.r5.s64 + 26648;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x82737058;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8273709C;
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

PPC_WEAK_FUNC(sub_82736FD8) {
	__imp__sub_82736FD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827370B0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,26712
	ctx.r5.s64 = r11.s64 + 26712;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827370E0;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,26784
	ctx.r5.s64 = ctx.r5.s64 + 26784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x82737130;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82737174;
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

PPC_WEAK_FUNC(sub_827370B0) {
	__imp__sub_827370B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737188) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,26848
	ctx.r5.s64 = r11.s64 + 26848;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827371B8;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,26920
	ctx.r5.s64 = ctx.r5.s64 + 26920;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x82737208;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8273724C;
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

PPC_WEAK_FUNC(sub_82737188) {
	__imp__sub_82737188(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737260) {
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
	ctx.lr = 0x82737268;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// li r3,120
	ctx.r3.s64 = 120;
	// lwz r28,-27428(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x8273727C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273729c
	if (cr6.eq) goto loc_8273729C;
	// bl 0x8275e9e0
	ctx.lr = 0x8273728C;
	sub_8275E9E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14096
	ctx.r10.s64 = r11.s64 + -14096;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x827372a0
	goto loc_827372A0;
loc_8273729C:
	// li r31,0
	r31.s64 = 0;
loc_827372A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82736f00
	ctx.lr = 0x827372A8;
	sub_82736F00(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r29,r11,-18228
	r29.s64 = r11.s64 + -18228;
	// addi r5,r10,20284
	ctx.r5.s64 = ctx.r10.s64 + 20284;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82490a08
	ctx.lr = 0x827372C8;
	sub_82490A08(ctx, base);
	// li r3,124
	ctx.r3.s64 = 124;
	// lwz r28,-27428(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x827372D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827372e8
	if (cr6.eq) goto loc_827372E8;
	// bl 0x8275f3f8
	ctx.lr = 0x827372E0;
	sub_8275F3F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x827372ec
	goto loc_827372EC;
loc_827372E8:
	// li r31,0
	r31.s64 = 0;
loc_827372EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82736fd8
	ctx.lr = 0x827372F4;
	sub_82736FD8(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r5,r11,20424
	ctx.r5.s64 = r11.s64 + 20424;
	// addi r4,r10,-14064
	ctx.r4.s64 = ctx.r10.s64 + -14064;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82490a08
	ctx.lr = 0x82737310;
	sub_82490A08(ctx, base);
	// li r3,124
	ctx.r3.s64 = 124;
	// lwz r28,-27428(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x8273731C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737330
	if (cr6.eq) goto loc_82737330;
	// bl 0x8275f140
	ctx.lr = 0x82737328;
	sub_8275F140(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82737334
	goto loc_82737334;
loc_82737330:
	// li r31,0
	r31.s64 = 0;
loc_82737334:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827370b0
	ctx.lr = 0x8273733C;
	sub_827370B0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20512
	ctx.r5.s64 = r11.s64 + 20512;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82490a08
	ctx.lr = 0x82737354;
	sub_82490A08(ctx, base);
	// li r3,104
	ctx.r3.s64 = 104;
	// lwz r30,-27428(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x82737360;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737374
	if (cr6.eq) goto loc_82737374;
	// bl 0x8275f260
	ctx.lr = 0x8273736C;
	sub_8275F260(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82737378
	goto loc_82737378;
loc_82737374:
	// li r31,0
	r31.s64 = 0;
loc_82737378:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82737188
	ctx.lr = 0x82737380;
	sub_82737188(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20568
	ctx.r5.s64 = r11.s64 + 20568;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82490a08
	ctx.lr = 0x82737398;
	sub_82490A08(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827373b8
	if (cr6.eq) goto loc_827373B8;
	// bl 0x821bbea8
	ctx.lr = 0x827373B8;
	sub_821BBEA8(ctx, base);
loc_827373B8:
	// bl 0x8275ebd0
	ctx.lr = 0x827373BC;
	sub_8275EBD0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827373c8
	if (cr6.eq) goto loc_827373C8;
	// bl 0x821bbf00
	ctx.lr = 0x827373C8;
	sub_821BBF00(ctx, base);
loc_827373C8:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827373e4
	if (cr6.eq) goto loc_827373E4;
	// bl 0x821bbea8
	ctx.lr = 0x827373E4;
	sub_821BBEA8(ctx, base);
loc_827373E4:
	// bl 0x8275fee0
	ctx.lr = 0x827373E8;
	sub_8275FEE0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827373f4
	if (cr6.eq) goto loc_827373F4;
	// bl 0x821bbf00
	ctx.lr = 0x827373F4;
	sub_821BBF00(ctx, base);
loc_827373F4:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82737410
	if (cr6.eq) goto loc_82737410;
	// bl 0x821bbea8
	ctx.lr = 0x82737410;
	sub_821BBEA8(ctx, base);
loc_82737410:
	// bl 0x8275f440
	ctx.lr = 0x82737414;
	sub_8275F440(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82737420
	if (cr6.eq) goto loc_82737420;
	// bl 0x821bbf00
	ctx.lr = 0x82737420;
	sub_821BBF00(ctx, base);
loc_82737420:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273743c
	if (cr6.eq) goto loc_8273743C;
	// bl 0x821bbea8
	ctx.lr = 0x8273743C;
	sub_821BBEA8(ctx, base);
loc_8273743C:
	// bl 0x8275f5a0
	ctx.lr = 0x82737440;
	sub_8275F5A0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273744c
	if (cr6.eq) goto loc_8273744C;
	// bl 0x821bbf00
	ctx.lr = 0x8273744C;
	sub_821BBF00(ctx, base);
loc_8273744C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82737260) {
	__imp__sub_82737260(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82737454) {
	__imp__sub_82737454(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737458) {
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
	// bl 0x8275da68
	ctx.lr = 0x82737470;
	sub_8275DA68(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r11,-13736
	ctx.r9.s64 = r11.s64 + -13736;
	// addi r8,r10,-13768
	ctx.r8.s64 = ctx.r10.s64 + -13768;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
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

PPC_WEAK_FUNC(sub_82737458) {
	__imp__sub_82737458(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827374A0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-100
	ctx.r3.s64 = ctx.r3.s64 + -100;
	// b 0x827374a8
	sub_827374A8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827374A0) {
	__imp__sub_827374A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827374A8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bne cr6,0x827374d4
	if (!cr6.eq) goto loc_827374D4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_827374D4:
	// bl 0x82548b50
	ctx.lr = 0x827374D8;
	sub_82548B50(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,-15292
	ctx.r9.s64 = r11.s64 + -15292;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x827374fc
	if (cr6.eq) goto loc_827374FC;
	// bl 0x82130588
	ctx.lr = 0x827374F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827374FC:
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

PPC_WEAK_FUNC(sub_827374A8) {
	__imp__sub_827374A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82737514) {
	__imp__sub_82737514(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737518) {
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
	// beq cr6,0x82737590
	if (cr6.eq) goto loc_82737590;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82737554
	if (cr6.eq) goto loc_82737554;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82737550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8273755c
	goto loc_8273755C;
loc_82737554:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_8273755C:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-29000
	ctx.r4.s64 = r11.s64 + -29000;
	// bl 0x823d9188
	ctx.lr = 0x82737568;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82737590
	if (cr6.eq) goto loc_82737590;
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
loc_82737590:
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

PPC_WEAK_FUNC(sub_82737518) {
	__imp__sub_82737518(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827375A8) {
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
	// beq cr6,0x82737620
	if (cr6.eq) goto loc_82737620;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827375e4
	if (cr6.eq) goto loc_827375E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827375E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827375ec
	goto loc_827375EC;
loc_827375E4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_827375EC:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,18408
	ctx.r4.s64 = r11.s64 + 18408;
	// bl 0x823d9188
	ctx.lr = 0x827375F8;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82737620
	if (cr6.eq) goto loc_82737620;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
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
loc_82737620:
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

PPC_WEAK_FUNC(sub_827375A8) {
	__imp__sub_827375A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737638) {
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
	ctx.lr = 0x82737640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x824a5b20
	ctx.lr = 0x8273765C;
	sub_824A5B20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827376d4
	if (cr6.eq) goto loc_827376D4;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x824a5b00
	ctx.lr = 0x82737674;
	sub_824A5B00(ctx, base);
	// bl 0x82737518
	ctx.lr = 0x82737678;
	sub_82737518(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824a5b20
	ctx.lr = 0x8273768C;
	sub_824A5B20(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827376a8
	if (cr6.eq) goto loc_827376A8;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x824a5b00
	ctx.lr = 0x827376A4;
	sub_824A5B00(ctx, base);
	// bl 0x827375a8
	ctx.lr = 0x827376A8;
	sub_827375A8(ctx, base);
loc_827376A8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827376BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x827376C4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8272f908
	ctx.lr = 0x827376D4;
	sub_8272F908(ctx, base);
loc_827376D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82737638) {
	__imp__sub_82737638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827376DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827376DC) {
	__imp__sub_827376DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827376E0) {
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
	// bl 0x827361f0
	ctx.lr = 0x827376F8;
	sub_827361F0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-18804
	ctx.r10.s64 = r11.s64 + -18804;
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

PPC_WEAK_FUNC(sub_827376E0) {
	__imp__sub_827376E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273771C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273771C) {
	__imp__sub_8273771C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737720) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// stw r4,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// rlwinm r10,r11,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r10,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82737720) {
	__imp__sub_82737720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273773C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273773C) {
	__imp__sub_8273773C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737740) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x82735918
	ctx.lr = 0x8273775C;
	sub_82735918(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x82737768;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82737878
	if (cr6.eq) goto loc_82737878;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8273777C;
	sub_822A39C8(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82737780;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lfs f12,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsubs f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f0,-6836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -6836);
	f0.f64 = double(temp.f32);
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// lfs f13,-6828(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -6828);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f12,f10
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmuls f4,f0,f0
	ctx.f4.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f3,f7,f7,f6
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f0,f5,f5,f3
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fcmpu cr6,f0,f4
	cr6.compare(f0.f64, ctx.f4.f64);
	// bgt cr6,0x82737834
	if (cr6.gt) goto loc_82737834;
	// fmuls f12,f13,f13
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x82737834
	if (cr6.lt) goto loc_82737834;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,-6832(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6832);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82737878
	if (!cr6.lt) goto loc_82737878;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,-6824(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6824);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82737878
	if (!cr6.gt) goto loc_82737878;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737878
	if (cr6.eq) goto loc_82737878;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82737878
	if (!cr6.eq) goto loc_82737878;
	// bl 0x824a8e40
	ctx.lr = 0x82737830;
	sub_824A8E40(ctx, base);
	// b 0x82737878
	goto loc_82737878;
loc_82737834:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737878
	if (cr6.eq) goto loc_82737878;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82737878
	if (cr6.eq) goto loc_82737878;
	// fmuls f13,f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lis r31,-32111
	r31.s64 = -2104426496;
	// li r11,1
	r11.s64 = 1;
	// lbz r30,-21548(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + -21548);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8273786c
	if (cr6.lt) goto loc_8273786C;
	// li r11,0
	r11.s64 = 0;
loc_8273786C:
	// stb r11,-21548(r31)
	PPC_STORE_U8(r31.u32 + -21548, r11.u8);
	// bl 0x824a8f08
	ctx.lr = 0x82737874;
	sub_824A8F08(ctx, base);
	// stb r30,-21548(r31)
	PPC_STORE_U8(r31.u32 + -21548, r30.u8);
loc_82737878:
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

PPC_WEAK_FUNC(sub_82737740) {
	__imp__sub_82737740(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, r11.u32);
	// b 0x82735438
	sub_82735438(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82737890) {
	__imp__sub_82737890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8273789C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8273789C) {
	__imp__sub_8273789C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827378A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lwz r3,128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// bl 0x82257af0
	ctx.lr = 0x827378CC;
	sub_82257AF0(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,80(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lfs f1,31016(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827378F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// bl 0x82332a00
	ctx.lr = 0x827378F8;
	sub_82332A00(ctx, base);
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

PPC_WEAK_FUNC(sub_827378A0) {
	__imp__sub_827378A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82737910) {
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
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82735fb0
	ctx.lr = 0x82737930;
	sub_82735FB0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r9,r11,-13100
	ctx.r9.s64 = r11.s64 + -13100;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r10,144(r31)
	PPC_STORE_U8(r31.u32 + 144, ctx.r10.u8);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r8.u32);
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

PPC_WEAK_FUNC(sub_82737910) {
	__imp__sub_82737910(ctx, base);
}

