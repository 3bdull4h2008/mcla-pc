#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_826CBBBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CBBBC) {
	__imp__sub_826CBBBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBBC0) {
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
	ctx.lr = 0x826CBBC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r31,24996(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 24996);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x826bde70
	ctx.lr = 0x826CBBEC;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cbc00
	if (cr6.eq) goto loc_826CBC00;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cbc88
	if (!cr6.eq) goto loc_826CBC88;
loc_826CBC00:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// sth r8,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r8.u16);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// beq cr6,0x826cbc54
	if (cr6.eq) goto loc_826CBC54;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r8,-4324
	ctx.r7.s64 = ctx.r8.s64 + -4324;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stb r10,9(r11)
	PPC_STORE_U8(r11.u32 + 9, ctx.r10.u8);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// b 0x826cbc58
	goto loc_826CBC58;
loc_826CBC54:
	// li r11,0
	r11.s64 = 0;
loc_826CBC58:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r28,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r28.u32);
	// stw r30,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r30.u32);
	// lwz r11,24996(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24996);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x82389998
	ctx.lr = 0x826CBC88;
	sub_82389998(ctx, base);
loc_826CBC88:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CBBC0) {
	__imp__sub_826CBBC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBC90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826CBC98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r30,24996(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 24996);
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// bl 0x826bde70
	ctx.lr = 0x826CBCBC;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cbcd0
	if (cr6.eq) goto loc_826CBCD0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cbd54
	if (!cr6.eq) goto loc_826CBD54;
loc_826CBCD0:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// sth r8,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r8.u16);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// beq cr6,0x826cbd24
	if (cr6.eq) goto loc_826CBD24;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r7,r9,-4300
	ctx.r7.s64 = ctx.r9.s64 + -4300;
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stb r10,9(r11)
	PPC_STORE_U8(r11.u32 + 9, ctx.r10.u8);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// b 0x826cbd28
	goto loc_826CBD28;
loc_826CBD24:
	// li r11,0
	r11.s64 = 0;
loc_826CBD28:
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// lwz r11,24996(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24996);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x82389998
	ctx.lr = 0x826CBD54;
	sub_82389998(ctx, base);
loc_826CBD54:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CBC90) {
	__imp__sub_826CBC90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CBD5C) {
	__imp__sub_826CBD5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBD60) {
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
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,24996(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x826bde70
	ctx.lr = 0x826CBD8C;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cbdc4
	if (cr6.eq) goto loc_826CBDC4;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826cbdc4
	if (cr6.eq) goto loc_826CBDC4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// stb r31,8(r5)
	PPC_STORE_U8(ctx.r5.u32 + 8, r31.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cbdc4
	if (cr6.eq) goto loc_826CBDC4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-20088
	ctx.r4.s64 = ctx.r10.s64 + -20088;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826CBDC4;
	sub_8268B770(ctx, base);
loc_826CBDC4:
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

PPC_WEAK_FUNC(sub_826CBD60) {
	__imp__sub_826CBD60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBDD8) {
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
	ctx.lr = 0x826CBDE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cbe2c
	if (cr6.eq) goto loc_826CBE2C;
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cbe0c
	if (cr6.eq) goto loc_826CBE0C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826CBE0C;
	sub_82130588(ctx, base);
loc_826CBE0C:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// stb r31,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r31.u8);
	// bl 0x82130588
	ctx.lr = 0x826CBE28;
	sub_82130588(ctx, base);
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
loc_826CBE2C:
	// lwz r30,4(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cbe6c
	if (cr6.eq) goto loc_826CBE6C;
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cbe4c
	if (cr6.eq) goto loc_826CBE4C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826CBE4C;
	sub_82130588(ctx, base);
loc_826CBE4C:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// stb r31,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r31.u8);
	// bl 0x82130588
	ctx.lr = 0x826CBE68;
	sub_82130588(ctx, base);
	// stw r31,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r31.u32);
loc_826CBE6C:
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cbeac
	if (cr6.eq) goto loc_826CBEAC;
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cbe8c
	if (cr6.eq) goto loc_826CBE8C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826CBE8C;
	sub_82130588(ctx, base);
loc_826CBE8C:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// stb r31,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r31.u8);
	// bl 0x82130588
	ctx.lr = 0x826CBEA8;
	sub_82130588(ctx, base);
	// stw r31,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r31.u32);
loc_826CBEAC:
	// addi r3,r29,12
	ctx.r3.s64 = r29.s64 + 12;
	// bl 0x82608de8
	ctx.lr = 0x826CBEB4;
	sub_82608DE8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CBDD8) {
	__imp__sub_826CBDD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CBEBC) {
	__imp__sub_826CBEBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBEC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826cbaf8
	sub_826CBAF8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CBEC0) {
	__imp__sub_826CBEC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826cbbc0
	sub_826CBBC0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CBED0) {
	__imp__sub_826CBED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBEE0) {
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
	// b 0x826cbc90
	sub_826CBC90(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CBEE0) {
	__imp__sub_826CBEE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBF44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CBF44) {
	__imp__sub_826CBF44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBF48) {
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
	ctx.lr = 0x826CBF50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r29,-32112
	r29.s64 = -2104492032;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,24996(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24996);
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826bde70
	ctx.lr = 0x826CBF78;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cbfac
	if (cr6.eq) goto loc_826CBFAC;
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826cbfac
	if (cr6.eq) goto loc_826CBFAC;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x826cb6c0
	ctx.lr = 0x826CBFA0;
	sub_826CB6C0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,24996(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24996);
	// bl 0x826cb9f8
	ctx.lr = 0x826CBFAC;
	sub_826CB9F8(ctx, base);
loc_826CBFAC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CBF48) {
	__imp__sub_826CBF48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CBFB4) {
	__imp__sub_826CBFB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBFB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r4,r7,24
	ctx.r4.u64 = ctx.r7.u32 & 0xFF;
	// b 0x826cbd60
	sub_826CBD60(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CBFB8) {
	__imp__sub_826CBFB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBFD8) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,24996(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24996);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x826bde70
	ctx.lr = 0x826CC00C;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cc028
	if (cr6.eq) goto loc_826CC028;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc028
	if (cr6.eq) goto loc_826CC028;
	// lbz r11,8(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// b 0x826cc02c
	goto loc_826CC02C;
loc_826CC028:
	// li r11,1
	r11.s64 = 1;
loc_826CC02C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
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
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CBFD8) {
	__imp__sub_826CBFD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CC04C) {
	__imp__sub_826CC04C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC050) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,24996(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24996);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r31,r5,24
	r31.u64 = ctx.r5.u32 & 0xFF;
	// bl 0x826bde70
	ctx.lr = 0x826CC094;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cc0ac
	if (cr6.eq) goto loc_826CC0AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc0ac
	if (cr6.eq) goto loc_826CC0AC;
	// stb r31,9(r11)
	PPC_STORE_U8(r11.u32 + 9, r31.u8);
loc_826CC0AC:
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

PPC_WEAK_FUNC(sub_826CC050) {
	__imp__sub_826CC050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC0C0) {
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
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-16704
	ctx.r4.s64 = r11.s64 + -16704;
	// addi r3,r10,-4080
	ctx.r3.s64 = ctx.r10.s64 + -4080;
	// bl 0x82554798
	ctx.lr = 0x826CC0E0;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-16688
	ctx.r4.s64 = ctx.r9.s64 + -16688;
	// addi r3,r8,-4112
	ctx.r3.s64 = ctx.r8.s64 + -4112;
	// bl 0x82554798
	ctx.lr = 0x826CC0F4;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-16672
	ctx.r4.s64 = ctx.r7.s64 + -16672;
	// addi r3,r6,-4148
	ctx.r3.s64 = ctx.r6.s64 + -4148;
	// bl 0x82554798
	ctx.lr = 0x826CC108;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-16568
	ctx.r4.s64 = ctx.r5.s64 + -16568;
	// addi r3,r3,-4184
	ctx.r3.s64 = ctx.r3.s64 + -4184;
	// bl 0x82554798
	ctx.lr = 0x826CC11C;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-16456
	ctx.r4.s64 = r11.s64 + -16456;
	// addi r3,r10,-4212
	ctx.r3.s64 = ctx.r10.s64 + -4212;
	// bl 0x82554798
	ctx.lr = 0x826CC130;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-16424
	ctx.r4.s64 = ctx.r9.s64 + -16424;
	// addi r3,r8,-4244
	ctx.r3.s64 = ctx.r8.s64 + -4244;
	// bl 0x82554798
	ctx.lr = 0x826CC144;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-16304
	ctx.r4.s64 = ctx.r7.s64 + -16304;
	// addi r3,r6,-4280
	ctx.r3.s64 = ctx.r6.s64 + -4280;
	// bl 0x82554798
	ctx.lr = 0x826CC158;
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

PPC_WEAK_FUNC(sub_826CC0C0) {
	__imp__sub_826CC0C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC168) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,117(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 117);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stb r4,118(r3)
	PPC_STORE_U8(ctx.r3.u32 + 118, ctx.r4.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CC168) {
	__imp__sub_826CC168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CC17C) {
	__imp__sub_826CC17C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC180) {
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
	ctx.lr = 0x826CC188;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r11,128(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc1e0
	if (cr6.eq) goto loc_826CC1E0;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_826CC1A8:
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826CC1C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,124(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stb r28,84(r7)
	PPC_STORE_U8(ctx.r7.u32 + 84, r28.u8);
	// lhz r6,128(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 128);
	// cmpw cr6,r29,r6
	cr6.compare<int32_t>(r29.s32, ctx.r6.s32, xer);
	// blt cr6,0x826cc1a8
	if (cr6.lt) goto loc_826CC1A8;
loc_826CC1E0:
	// li r11,1
	r11.s64 = 1;
	// stb r28,116(r30)
	PPC_STORE_U8(r30.u32 + 116, r28.u8);
	// stb r28,140(r30)
	PPC_STORE_U8(r30.u32 + 140, r28.u8);
	// stb r11,118(r30)
	PPC_STORE_U8(r30.u32 + 118, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CC180) {
	__imp__sub_826CC180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC1F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,128(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stb r9,140(r3)
	PPC_STORE_U8(ctx.r3.u32 + 140, ctx.r9.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_826CC214:
	// lwz r8,124(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stb r9,84(r7)
	PPC_STORE_U8(ctx.r7.u32 + 84, ctx.r9.u8);
	// lhz r6,128(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 128);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x826cc214
	if (cr6.lt) goto loc_826CC214;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CC1F8) {
	__imp__sub_826CC1F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC238) {
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
	ctx.lr = 0x826CC240;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,128(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc288
	if (cr6.eq) goto loc_826CC288;
	// li r30,0
	r30.s64 = 0;
loc_826CC25C:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826CC274;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x826cc25c
	if (cr6.lt) goto loc_826CC25C;
loc_826CC288:
	// lhz r11,136(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 136);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc2c8
	if (cr6.eq) goto loc_826CC2C8;
	// li r30,0
	r30.s64 = 0;
loc_826CC29C:
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826CC2B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,136(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 136);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x826cc29c
	if (cr6.lt) goto loc_826CC29C;
loc_826CC2C8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CC238) {
	__imp__sub_826CC238(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC2D0) {
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
	ctx.lr = 0x826CC2D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826CC2F4;
	sub_82218310(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r10,-8116
	ctx.r3.s64 = ctx.r10.s64 + -8116;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x823d9750
	ctx.lr = 0x826CC308;
	sub_823D9750(ctx, base);
	// lhz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826cc348
	if (cr6.eq) goto loc_826CC348;
	// li r29,0
	r29.s64 = 0;
loc_826CC31C:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826CC334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x826cc31c
	if (cr6.lt) goto loc_826CC31C;
loc_826CC348:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CC2D0) {
	__imp__sub_826CC2D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC350) {
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
	ctx.lr = 0x826CC358;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826cc3ec
	if (cr6.eq) goto loc_826CC3EC;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x826cc3ec
	if (!cr6.gt) goto loc_826CC3EC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826CC388;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823db670
	ctx.lr = 0x826CC398;
	sub_823DB670(ctx, base);
	// lhz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cc3ec
	if (cr6.eq) goto loc_826CC3EC;
	// li r30,0
	r30.s64 = 0;
loc_826CC3AC:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lbz r10,41(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cc3d8
	if (cr6.eq) goto loc_826CC3D8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CC3D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826CC3D8:
	// lhz r11,128(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826cc3ac
	if (cr6.lt) goto loc_826CC3AC;
loc_826CC3EC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CC350) {
	__imp__sub_826CC350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CC3F4) {
	__imp__sub_826CC3F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC3F8) {
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
	ctx.lr = 0x826CC400;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,118(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 118);
	// stbx r10,r11,r29
	PPC_STORE_U8(r11.u32 + r29.u32, ctx.r10.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lbz r9,116(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 116);
	// stbx r9,r11,r29
	PPC_STORE_U8(r11.u32 + r29.u32, ctx.r9.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lhz r27,128(r30)
	r27.u64 = PPC_LOAD_U16(r30.u32 + 128);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// stwx r27,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, r27.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// ble cr6,0x826cc4a8
	if (!cr6.gt) goto loc_826CC4A8;
	// li r28,0
	r28.s64 = 0;
loc_826CC45C:
	// lwz r10,124(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwzx r9,r10,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// stwx r8,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r8.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r6,124(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// lwzx r3,r6,r28
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r28.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CC49C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x826cc45c
	if (!cr0.eq) goto loc_826CC45C;
loc_826CC4A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CC3F8) {
	__imp__sub_826CC3F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC4B0) {
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
	ctx.lr = 0x826CC4B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,128(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc50c
	if (cr6.eq) goto loc_826CC50C;
	// li r29,0
	r29.s64 = 0;
loc_826CC4D8:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lbz r4,119(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 119);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826CC4F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x826cc4d8
	if (cr6.lt) goto loc_826CC4D8;
loc_826CC50C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,104(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r3,24996(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// bl 0x826cb780
	ctx.lr = 0x826CC51C;
	sub_826CB780(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cc538
	if (cr6.eq) goto loc_826CC538;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CC538;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826CC538:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CC4B0) {
	__imp__sub_826CC4B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC540) {
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
	ctx.lr = 0x826CC548;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,128(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc590
	if (cr6.eq) goto loc_826CC590;
	// li r31,0
	r31.s64 = 0;
loc_826CC564:
	// lwz r11,124(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826CC57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,128(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 128);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x826cc564
	if (cr6.lt) goto loc_826CC564;
loc_826CC590:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CC540) {
	__imp__sub_826CC540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC598) {
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
	ctx.lr = 0x826CC5A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cc5d4
	if (!cr6.eq) goto loc_826CC5D4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-3680
	ctx.r5.s64 = r11.s64 + -3680;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x8268b960
	ctx.lr = 0x826CC5D0;
	sub_8268B960(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
loc_826CC5D4:
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cc5fc
	if (!cr6.eq) goto loc_826CC5FC;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-3700
	ctx.r5.s64 = r11.s64 + -3700;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x8268b960
	ctx.lr = 0x826CC5F8;
	sub_8268B960(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
loc_826CC5FC:
	// lhz r11,128(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc630
	if (cr6.eq) goto loc_826CC630;
	// li r30,0
	r30.s64 = 0;
loc_826CC610:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x826d1e68
	ctx.lr = 0x826CC61C;
	sub_826D1E68(ctx, base);
	// lhz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x826cc610
	if (cr6.lt) goto loc_826CC610;
loc_826CC630:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CC598) {
	__imp__sub_826CC598(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC638) {
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
	ctx.lr = 0x826CC640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826cc66c
	if (cr6.eq) goto loc_826CC66C;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x826CC668;
	sub_8268B6D0(ctx, base);
	// stw r30,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r30.u32);
loc_826CC66C:
	// lwz r5,112(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826cc688
	if (cr6.eq) goto loc_826CC688;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x826CC684;
	sub_8268B6D0(ctx, base);
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
loc_826CC688:
	// lhz r11,128(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// mr r29,r30
	r29.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc6b8
	if (cr6.eq) goto loc_826CC6B8;
loc_826CC698:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x826d1ee8
	ctx.lr = 0x826CC6A4;
	sub_826D1EE8(ctx, base);
	// lhz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x826cc698
	if (cr6.lt) goto loc_826CC698;
loc_826CC6B8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CC638) {
	__imp__sub_826CC638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC6C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826cc6f8
	if (!cr6.gt) goto loc_826CC6F8;
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_826CC6D8:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 40);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826cc6ec
	if (cr6.eq) goto loc_826CC6EC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_826CC6EC:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x826cc6d8
	if (!cr0.eq) goto loc_826CC6D8;
loc_826CC6F8:
	// subf r11,r8,r9
	r11.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CC6C0) {
	__imp__sub_826CC6C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC708) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826CC710;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,116(r29)
	PPC_STORE_U8(r29.u32 + 116, ctx.r10.u8);
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r9,360(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826cc768
	if (cr6.eq) goto loc_826CC768;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r5,r11,-3660
	ctx.r5.s64 = r11.s64 + -3660;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826CC748;
	sub_82137A08(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f1,11368(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11368);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82234d88
	ctx.lr = 0x826CC768;
	sub_82234D88(ctx, base);
loc_826CC768:
	// lhz r11,136(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 136);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc7a4
	if (cr6.eq) goto loc_826CC7A4;
	// li r31,0
	r31.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_826CC780:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// lwz r3,18504(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 18504);
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x826b5cf0
	ctx.lr = 0x826CC790;
	sub_826B5CF0(ctx, base);
	// lhz r10,136(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 136);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x826cc780
	if (cr6.lt) goto loc_826CC780;
loc_826CC7A4:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,104(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// lwz r3,24996(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// bl 0x826cb780
	ctx.lr = 0x826CC7B4;
	sub_826CB780(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cc7d0
	if (cr6.eq) goto loc_826CC7D0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CC7D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826CC7D0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r10,-7076
	ctx.r4.s64 = ctx.r10.s64 + -7076;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826CC7E8;
	sub_8268B770(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CC708) {
	__imp__sub_826CC708(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC7F0) {
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
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CC7F0) {
	__imp__sub_826CC7F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CC80C) {
	__imp__sub_826CC80C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC810) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,117(r11)
	PPC_STORE_U8(r11.u32 + 117, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CC810) {
	__imp__sub_826CC810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc85c
	if (cr6.eq) goto loc_826CC85C;
	// lbz r11,116(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 116);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_826CC85C:
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

PPC_WEAK_FUNC(sub_826CC838) {
	__imp__sub_826CC838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc890
	if (cr6.eq) goto loc_826CC890;
	// lwz r11,104(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826CC890:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CC870) {
	__imp__sub_826CC870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC89C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CC89C) {
	__imp__sub_826CC89C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC8A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r9,117(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 117);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stb r10,118(r11)
	PPC_STORE_U8(r11.u32 + 118, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CC8A0) {
	__imp__sub_826CC8A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CC8D4) {
	__imp__sub_826CC8D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC8D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc914
	if (cr6.eq) goto loc_826CC914;
	// lbz r10,117(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 117);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826cc900
	if (!cr6.eq) goto loc_826CC900;
	// lbz r11,118(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 118);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc914
	if (cr6.eq) goto loc_826CC914;
loc_826CC900:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_826CC914:
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

PPC_WEAK_FUNC(sub_826CC8D8) {
	__imp__sub_826CC8D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CC928) {
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
	// lbz r11,112(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cca18
	if (!cr6.eq) goto loc_826CCA18;
	// lwz r11,104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x826cc9dc
	if (!cr6.eq) goto loc_826CC9DC;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826cc9dc
	if (cr6.eq) goto loc_826CC9DC;
	// lhz r11,124(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 124);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cca18
	if (cr6.eq) goto loc_826CCA18;
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
loc_826CC968:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// beq cr6,0x826cc99c
	if (cr6.eq) goto loc_826CC99C;
	// lhz r9,124(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 124);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826cc968
	if (cr6.lt) goto loc_826CC968;
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
loc_826CC99C:
	// lbz r11,116(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cc9b0
	if (cr6.eq) goto loc_826CC9B0;
	// li r11,1
	r11.s64 = 1;
	// stb r11,136(r3)
	PPC_STORE_U8(ctx.r3.u32 + 136, r11.u8);
loc_826CC9B0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r5,r3,-4
	ctx.r5.s64 = ctx.r3.s64 + -4;
	// addi r4,r10,-7052
	ctx.r4.s64 = ctx.r10.s64 + -7052;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826CC9C8;
	sub_8268B770(ctx, base);
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
loc_826CC9DC:
	// lwz r11,108(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x826cca18
	if (!cr6.eq) goto loc_826CCA18;
	// addi r5,r3,-4
	ctx.r5.s64 = ctx.r3.s64 + -4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x826cc6c0
	ctx.lr = 0x826CC9F4;
	sub_826CC6C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cca18
	if (cr6.eq) goto loc_826CCA18;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x826cc708
	ctx.lr = 0x826CCA08;
	sub_826CC708(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220a0b8
	ctx.lr = 0x826CCA18;
	sub_8220A0B8(ctx, base);
loc_826CCA18:
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

PPC_WEAK_FUNC(sub_826CC928) {
	__imp__sub_826CC928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CCA2C) {
	__imp__sub_826CCA2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCA30) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-28924
	ctx.r9.s64 = r11.s64 + -28924;
	// addi r8,r10,-21868
	ctx.r8.s64 = ctx.r10.s64 + -21868;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r7,-3612
	ctx.r4.s64 = ctx.r7.s64 + -3612;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x826CCA74;
	sub_823DB670(ctx, base);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r3,r5,-3632
	ctx.r3.s64 = ctx.r5.s64 + -3632;
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// addi r4,r6,-3620
	ctx.r4.s64 = ctx.r6.s64 + -3620;
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stb r11,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r11.u8);
	// stb r11,117(r31)
	PPC_STORE_U8(r31.u32 + 117, r11.u8);
	// stb r10,118(r31)
	PPC_STORE_U8(r31.u32 + 118, ctx.r10.u8);
	// stb r11,119(r31)
	PPC_STORE_U8(r31.u32 + 119, r11.u8);
	// stb r10,120(r31)
	PPC_STORE_U8(r31.u32 + 120, ctx.r10.u8);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// sth r11,128(r31)
	PPC_STORE_U16(r31.u32 + 128, r11.u16);
	// sth r11,130(r31)
	PPC_STORE_U16(r31.u32 + 130, r11.u16);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// sth r11,136(r31)
	PPC_STORE_U16(r31.u32 + 136, r11.u16);
	// sth r11,138(r31)
	PPC_STORE_U16(r31.u32 + 138, r11.u16);
	// stb r11,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r11.u8);
	// stb r11,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r11.u8);
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

PPC_WEAK_FUNC(sub_826CCA30) {
	__imp__sub_826CCA30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCAE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27208(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27208);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CCAE8) {
	__imp__sub_826CCAE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CCAF4) {
	__imp__sub_826CCAF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCAF8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x826cd078
	sub_826CD078(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CCAF8) {
	__imp__sub_826CCAF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCB00) {
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
	ctx.lr = 0x826CCB08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,-3620
	ctx.r9.s64 = r11.s64 + -3620;
	// addi r8,r10,-3632
	ctx.r8.s64 = ctx.r10.s64 + -3632;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// addi r29,r30,124
	r29.s64 = r30.s64 + 124;
	// stw r8,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r8.u32);
	// addi r28,r30,4
	r28.s64 = r30.s64 + 4;
	// lwz r9,124(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// lhz r7,128(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 128);
	// rotlwi r11,r7,2
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826ccb64
	if (cr6.eq) goto loc_826CCB64;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826CCB50:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826ccb50
	if (!cr6.eq) goto loc_826CCB50;
loc_826CCB64:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r31,r30,132
	r31.s64 = r30.s64 + 132;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r8.u16);
	// lwz r9,132(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// lhz r6,136(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 136);
	// rotlwi r11,r6,2
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826ccbb0
	if (cr6.eq) goto loc_826CCBB0;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826CCB9C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826ccb9c
	if (!cr6.eq) goto loc_826CCB9C;
loc_826CCBB0:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// bl 0x826cc638
	ctx.lr = 0x826CCBCC;
	sub_826CC638(ctx, base);
	// lhz r6,6(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826ccbe0
	if (cr6.eq) goto loc_826CCBE0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826CCBE0;
	sub_82130588(ctx, base);
loc_826CCBE0:
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ccbf4
	if (cr6.eq) goto loc_826CCBF4;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826CCBF4;
	sub_82130588(ctx, base);
loc_826CCBF4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826CCC08;
	sub_821D2028(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CCB00) {
	__imp__sub_826CCB00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCC10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ccc40
	if (cr6.eq) goto loc_826CCC40;
	// b 0x826cc708
	sub_826CC708(ctx, base);
	return;
loc_826CCC40:
	// li r11,0
	r11.s64 = 0;
	// stb r11,116(r3)
	PPC_STORE_U8(ctx.r3.u32 + 116, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CCC10) {
	__imp__sub_826CCC10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CCC4C) {
	__imp__sub_826CCC4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCC50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x826CCC58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbzx r10,r11,r27
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r27.u32);
	// stb r10,118(r31)
	PPC_STORE_U8(r31.u32 + 118, ctx.r10.u8);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// lbzx r9,r11,r27
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r27.u32);
	// stb r9,116(r31)
	PPC_STORE_U8(r31.u32 + 116, ctx.r9.u8);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// lwzx r30,r11,r27
	r30.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stw r8,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r8.u32);
	// beq cr6,0x826cce70
	if (cr6.eq) goto loc_826CCE70;
	// lhz r11,128(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// beq cr6,0x826cce2c
	if (cr6.eq) goto loc_826CCE2C;
	// addi r29,r31,124
	r29.s64 = r31.s64 + 124;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826b6228
	ctx.lr = 0x826CCCC0;
	sub_826B6228(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8247bb70
	ctx.lr = 0x826CCCCC;
	sub_8247BB70(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826cce70
	if (!cr6.gt) goto loc_826CCE70;
	// li r31,0
	r31.s64 = 0;
loc_826CCCD8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r11,r11,r27
	r11.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x826ccdf0
	if (cr6.gt) goto loc_826CCDF0;
	// lis r12,-32147
	r12.s64 = -2106785792;
	// addi r12,r12,-13044
	r12.s64 = r12.s64 + -13044;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-13012(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -13012);
	// lwz r19,-12988(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -12988);
	// lwz r19,-12964(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -12964);
	// lwz r19,-12940(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -12940);
	// lwz r19,-12916(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -12916);
	// lwz r19,-12892(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -12892);
	// lwz r19,-12868(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -12868);
	// lwz r19,-12844(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -12844);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x826CCD34;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccdec
	if (cr6.eq) goto loc_826CCDEC;
	// bl 0x826d0cd8
	ctx.lr = 0x826CCD40;
	sub_826D0CD8(ctx, base);
	// b 0x826ccdf0
	goto loc_826CCDF0;
	// li r3,120
	ctx.r3.s64 = 120;
	// bl 0x82130528
	ctx.lr = 0x826CCD4C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccdec
	if (cr6.eq) goto loc_826CCDEC;
	// bl 0x826d0ea0
	ctx.lr = 0x826CCD58;
	sub_826D0EA0(ctx, base);
	// b 0x826ccdf0
	goto loc_826CCDF0;
	// li r3,120
	ctx.r3.s64 = 120;
	// bl 0x82130528
	ctx.lr = 0x826CCD64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccdec
	if (cr6.eq) goto loc_826CCDEC;
	// bl 0x826d0fa0
	ctx.lr = 0x826CCD70;
	sub_826D0FA0(ctx, base);
	// b 0x826ccdf0
	goto loc_826CCDF0;
	// li r3,188
	ctx.r3.s64 = 188;
	// bl 0x82130528
	ctx.lr = 0x826CCD7C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccdec
	if (cr6.eq) goto loc_826CCDEC;
	// bl 0x826d10a0
	ctx.lr = 0x826CCD88;
	sub_826D10A0(ctx, base);
	// b 0x826ccdf0
	goto loc_826CCDF0;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x826CCD94;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccdec
	if (cr6.eq) goto loc_826CCDEC;
	// bl 0x826d11d0
	ctx.lr = 0x826CCDA0;
	sub_826D11D0(ctx, base);
	// b 0x826ccdf0
	goto loc_826CCDF0;
	// li r3,196
	ctx.r3.s64 = 196;
	// bl 0x82130528
	ctx.lr = 0x826CCDAC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccdec
	if (cr6.eq) goto loc_826CCDEC;
	// bl 0x826d1360
	ctx.lr = 0x826CCDB8;
	sub_826D1360(ctx, base);
	// b 0x826ccdf0
	goto loc_826CCDF0;
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x826CCDC4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccdec
	if (cr6.eq) goto loc_826CCDEC;
	// bl 0x826d15e8
	ctx.lr = 0x826CCDD0;
	sub_826D15E8(ctx, base);
	// b 0x826ccdf0
	goto loc_826CCDF0;
	// li r3,168
	ctx.r3.s64 = 168;
	// bl 0x82130528
	ctx.lr = 0x826CCDDC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccdec
	if (cr6.eq) goto loc_826CCDEC;
	// bl 0x826d1808
	ctx.lr = 0x826CCDE8;
	sub_826D1808(ctx, base);
	// b 0x826ccdf0
	goto loc_826CCDF0;
loc_826CCDEC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826CCDF0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stwx r3,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r3.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826CCE18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826cccd8
	if (!cr0.eq) goto loc_826CCCD8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826CCE2C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826cce70
	if (!cr6.gt) goto loc_826CCE70;
	// li r29,0
	r29.s64 = 0;
loc_826CCE38:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r3,r10,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826CCE64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x826cce38
	if (!cr0.eq) goto loc_826CCE38;
loc_826CCE70:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CCC50) {
	__imp__sub_826CCC50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCE78) {
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
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x826CCE8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccea8
	if (cr6.eq) goto loc_826CCEA8;
	// bl 0x826cca30
	ctx.lr = 0x826CCE98;
	sub_826CCA30(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826CCEA8:
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

PPC_WEAK_FUNC(sub_826CCE78) {
	__imp__sub_826CCE78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CCEBC) {
	__imp__sub_826CCEBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CCEC0) {
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
	ctx.lr = 0x826CCEC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27208
	r31.s64 = r11.s64 + -27208;
	// lwz r11,-27208(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cd070
	if (!cr6.eq) goto loc_826CD070;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826CCEE8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ccefc
	if (cr6.eq) goto loc_826CCEFC;
	// bl 0x821d5408
	ctx.lr = 0x826CCEF8;
	sub_821D5408(ctx, base);
	// b 0x826ccf00
	goto loc_826CCF00;
loc_826CCEFC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826CCF00:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-3600
	ctx.r7.s64 = ctx.r10.s64 + -3600;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,144
	ctx.r5.s64 = 144;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-12680
	ctx.r4.s64 = ctx.r8.s64 + -12680;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r8,r3,-24676
	ctx.r8.s64 = ctx.r3.s64 + -24676;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r10,104
	ctx.r10.s64 = 104;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// addi r10,r9,-24652
	ctx.r10.s64 = ctx.r9.s64 + -24652;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// li r9,40
	ctx.r9.s64 = 40;
	// addi r29,r7,-24628
	r29.s64 = ctx.r7.s64 + -24628;
	// addi r4,r4,-24604
	ctx.r4.s64 = ctx.r4.s64 + -24604;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// addi r3,r3,-24580
	ctx.r3.s64 = ctx.r3.s64 + -24580;
	// addi r5,r5,-24452
	ctx.r5.s64 = ctx.r5.s64 + -24452;
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r8,117
	ctx.r8.s64 = 117;
	// li r7,119
	ctx.r7.s64 = 119;
	// li r6,120
	ctx.r6.s64 = 120;
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// li r10,124
	ctx.r10.s64 = 124;
	// stw r7,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r7.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826ccfcc
	if (!cr6.eq) goto loc_826CCFCC;
	// bl 0x826d2a08
	ctx.lr = 0x826CCFC8;
	sub_826D2A08(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826CCFCC:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r8,r10,-24556
	ctx.r8.s64 = ctx.r10.s64 + -24556;
	// addi r7,r9,-24404
	ctx.r7.s64 = ctx.r9.s64 + -24404;
	// li r9,132
	ctx.r9.s64 = 132;
	// lwz r10,-27564(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// bne cr6,0x826cd000
	if (!cr6.eq) goto loc_826CD000;
	// bl 0x826b7f00
	ctx.lr = 0x826CCFFC;
	sub_826B7F00(ctx, base);
	// lwz r10,-27564(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826CD000:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,-24520
	ctx.r9.s64 = r11.s64 + -24520;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// bl 0x821d4458
	ctx.lr = 0x826CD01C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826CD02C;
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
	ctx.lr = 0x826CD048;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-24484
	ctx.r4.s64 = ctx.r6.s64 + -24484;
	// bl 0x821d4b00
	ctx.lr = 0x826CD058;
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
	ctx.lr = 0x826CD070;
	sub_821C0548(ctx, base);
loc_826CD070:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CCEC0) {
	__imp__sub_826CCEC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD078) {
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
	// bl 0x826ccb00
	ctx.lr = 0x826CD098;
	sub_826CCB00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd0b0
	if (cr6.eq) goto loc_826CD0B0;
	// bl 0x82130588
	ctx.lr = 0x826CD0AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826CD0B0:
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

PPC_WEAK_FUNC(sub_826CD078) {
	__imp__sub_826CD078(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD0C8) {
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
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-13296
	ctx.r4.s64 = r11.s64 + -13296;
	// addi r3,r10,-3432
	ctx.r3.s64 = ctx.r10.s64 + -3432;
	// bl 0x82554798
	ctx.lr = 0x826CD0E8;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-14352
	ctx.r4.s64 = ctx.r9.s64 + -14352;
	// addi r3,r8,-3456
	ctx.r3.s64 = ctx.r8.s64 + -3456;
	// bl 0x82554798
	ctx.lr = 0x826CD0FC;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-14320
	ctx.r4.s64 = ctx.r7.s64 + -14320;
	// addi r3,r6,-3484
	ctx.r3.s64 = ctx.r6.s64 + -3484;
	// bl 0x82554798
	ctx.lr = 0x826CD110;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-14280
	ctx.r4.s64 = ctx.r5.s64 + -14280;
	// addi r3,r3,-3512
	ctx.r3.s64 = ctx.r3.s64 + -3512;
	// bl 0x82554798
	ctx.lr = 0x826CD124;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-14224
	ctx.r4.s64 = r11.s64 + -14224;
	// addi r3,r10,-3540
	ctx.r3.s64 = ctx.r10.s64 + -3540;
	// bl 0x82554798
	ctx.lr = 0x826CD138;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-14176
	ctx.r4.s64 = ctx.r9.s64 + -14176;
	// addi r3,r8,-3560
	ctx.r3.s64 = ctx.r8.s64 + -3560;
	// bl 0x82554798
	ctx.lr = 0x826CD14C;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-14120
	ctx.r4.s64 = ctx.r7.s64 + -14120;
	// addi r3,r6,-3584
	ctx.r3.s64 = ctx.r6.s64 + -3584;
	// bl 0x82554798
	ctx.lr = 0x826CD160;
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

PPC_WEAK_FUNC(sub_826CD0C8) {
	__imp__sub_826CD0C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,8
	r11.s64 = ctx.r4.s64 + 8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CD170) {
	__imp__sub_826CD170(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD180) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826cd1dc
	if (cr6.eq) goto loc_826CD1DC;
	// addi r8,r4,8
	ctx.r8.s64 = ctx.r4.s64 + 8;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r3
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x826cd1c0
	if (!cr6.lt) goto loc_826CD1C0;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// blr 
	return;
loc_826CD1C0:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x826cd1cc
	if (!cr6.gt) goto loc_826CD1CC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_826CD1CC:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// blr 
	return;
loc_826CD1DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CD180) {
	__imp__sub_826CD180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD1E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD1E4) {
	__imp__sub_826CD1E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD1E8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826cd25c
	if (cr6.eq) goto loc_826CD25C;
	// addi r8,r30,8
	ctx.r8.s64 = r30.s64 + 8;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x826cd238
	if (!cr6.lt) goto loc_826CD238;
	// li r11,0
	r11.s64 = 0;
	// b 0x826cd244
	goto loc_826CD244;
loc_826CD238:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x826cd244
	if (!cr6.gt) goto loc_826CD244;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_826CD244:
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,18504(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18504);
	// lwzx r4,r8,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x826b5cf0
	ctx.lr = 0x826CD25C;
	sub_826B5CF0(ctx, base);
loc_826CD25C:
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
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

PPC_WEAK_FUNC(sub_826CD1E8) {
	__imp__sub_826CD1E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD288) {
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
	ctx.lr = 0x826CD290;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// sth r30,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r30.u16);
	// sth r30,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r30.u16);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// sth r30,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r30.u16);
	// sth r30,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r30.u16);
	// beq cr6,0x826cd2f4
	if (cr6.eq) goto loc_826CD2F4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x823db670
	ctx.lr = 0x826CD2E4;
	sub_823DB670(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x826CD2F0;
	sub_821C9790(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
loc_826CD2F4:
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CD288) {
	__imp__sub_826CD288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD314) {
	__imp__sub_826CD314(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD318) {
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
	// addi r31,r3,32
	r31.s64 = ctx.r3.s64 + 32;
	// li r30,3
	r30.s64 = 3;
loc_826CD334:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd34c
	if (cr6.eq) goto loc_826CD34C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826CD34C;
	sub_82130588(ctx, base);
loc_826CD34C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x826cd334
	if (!cr0.lt) goto loc_826CD334;
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

PPC_WEAK_FUNC(sub_826CD318) {
	__imp__sub_826CD318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD36C) {
	__imp__sub_826CD36C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD370) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x826CD378;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r27,r11,-3120
	r27.s64 = r11.s64 + -3120;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821cff40
	ctx.lr = 0x826CD39C;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd4b0
	if (cr6.eq) goto loc_826CD4B0;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r24,r8,-29628
	r24.s64 = ctx.r8.s64 + -29628;
	// addi r29,r9,-19848
	r29.s64 = ctx.r9.s64 + -19848;
	// addi r26,r10,9848
	r26.s64 = ctx.r10.s64 + 9848;
	// addi r25,r11,-29624
	r25.s64 = r11.s64 + -29624;
loc_826CD3CC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe20
	ctx.lr = 0x826CD3D8;
	sub_821CFE20(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CD3F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe20
	ctx.lr = 0x826CD3FC;
	sub_821CFE20(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826CD418;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238e8c0
	ctx.lr = 0x826CD420;
	sub_8238E8C0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x826CD434;
	sub_821CFF40(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826cd488
	if (cr6.eq) goto loc_826CD488;
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r23
	r30.u64 = r11.u64 + r23.u64;
loc_826CD448:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262e420
	ctx.lr = 0x826CD454;
	sub_8262E420(ctx, base);
	// lwz r11,18504(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 18504);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826b5450
	ctx.lr = 0x826CD468;
	sub_826B5450(ctx, base);
	// stw r3,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r3.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x826CD47C;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cd448
	if (!cr6.eq) goto loc_826CD448;
loc_826CD488:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe20
	ctx.lr = 0x826CD494;
	sub_821CFE20(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x826CD4A4;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cd3cc
	if (!cr6.eq) goto loc_826CD3CC;
loc_826CD4B0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_826CD370) {
	__imp__sub_826CD370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD4B8) {
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
	ctx.lr = 0x826CD4C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r11,-24320
	r29.s64 = r11.s64 + -24320;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_826CD4D8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x826CD4E4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826cd51c
	if (cr6.eq) goto loc_826CD51C;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,28
	r11.s64 = r29.s64 + 28;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x826cd4d8
	if (cr6.lt) goto loc_826CD4D8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-2688
	ctx.r3.s64 = r11.s64 + -2688;
	// bl 0x82130000
	ctx.lr = 0x826CD510;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826CD51C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CD4B8) {
	__imp__sub_826CD4B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD528) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x826c6dd0
	ctx.lr = 0x826CD550;
	sub_826C6DD0(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r9,r11,-24292
	ctx.r9.s64 = r11.s64 + -24292;
	// addi r7,r10,-24320
	ctx.r7.s64 = ctx.r10.s64 + -24320;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// addi r6,r31,72
	ctx.r6.s64 = r31.s64 + 72;
	// addi r5,r5,-2624
	ctx.r5.s64 = ctx.r5.s64 + -2624;
	// li r4,74
	ctx.r4.s64 = 74;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r10,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// bl 0x82137a08
	ctx.lr = 0x826CD588;
	sub_82137A08(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-2640
	ctx.r4.s64 = ctx.r8.s64 + -2640;
	// lwz r3,-10224(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826CD5A0;
	sub_8268B770(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x826c7710
	ctx.lr = 0x826CD5AC;
	sub_826C7710(ctx, base);
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

PPC_WEAK_FUNC(sub_826CD528) {
	__imp__sub_826CD528(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD5C4) {
	__imp__sub_826CD5C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD5C8) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r7,r9,-24320
	ctx.r7.s64 = ctx.r9.s64 + -24320;
	// addi r8,r11,-24292
	ctx.r8.s64 = r11.s64 + -24292;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r31,72
	ctx.r6.s64 = r31.s64 + 72;
	// addi r5,r11,-2624
	ctx.r5.s64 = r11.s64 + -2624;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// li r4,74
	ctx.r4.s64 = 74;
	// lwzx r7,r3,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826CD61C;
	sub_82137A08(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-2640
	ctx.r4.s64 = ctx.r9.s64 + -2640;
	// lwz r3,-10224(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826CD634;
	sub_8268B770(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x826c6ec0
	ctx.lr = 0x826CD640;
	sub_826C6EC0(ctx, base);
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

PPC_WEAK_FUNC(sub_826CD5C8) {
	__imp__sub_826CD5C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD658) {
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
	// bl 0x826cd528
	ctx.lr = 0x826CD670;
	sub_826CD528(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6e50
	ctx.lr = 0x826CD678;
	sub_826C6E50(ctx, base);
	// lwz r11,704(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 704);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826cd6a0
	if (cr6.eq) goto loc_826CD6A0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c4058
	ctx.lr = 0x826CD698;
	sub_826C4058(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,704(r31)
	PPC_STORE_U32(r31.u32 + 704, ctx.r10.u32);
loc_826CD6A0:
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

PPC_WEAK_FUNC(sub_826CD658) {
	__imp__sub_826CD658(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD6B4) {
	__imp__sub_826CD6B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD6B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,712(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 712);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd6cc
	if (cr6.eq) goto loc_826CD6CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826CD6CC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// b 0x826c3d98
	sub_826C3D98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CD6B8) {
	__imp__sub_826CD6B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD6DC) {
	__imp__sub_826CD6DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD6E0) {
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
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r9,712(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826cd72c
	if (!cr6.gt) goto loc_826CD72C;
	// lwz r10,708(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r10,r10,116
	ctx.r10.s64 = ctx.r10.s64 + 116;
loc_826CD710:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826cd720
	if (cr6.eq) goto loc_826CD720;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_826CD720:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,144
	ctx.r10.s64 = ctx.r10.s64 + 144;
	// bne 0x826cd710
	if (!cr0.eq) goto loc_826CD710;
loc_826CD72C:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x826cd754
	if (!cr6.eq) goto loc_826CD754;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826CD744;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x826c67f8
	ctx.lr = 0x826CD754;
	sub_826C67F8(ctx, base);
loc_826CD754:
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

PPC_WEAK_FUNC(sub_826CD6E0) {
	__imp__sub_826CD6E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD768) {
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
	ctx.lr = 0x826CD770;
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
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x826c6d38
	ctx.lr = 0x826CD788;
	sub_826C6D38(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cd528
	ctx.lr = 0x826CD798;
	sub_826CD528(ctx, base);
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd7d0
	if (cr6.eq) goto loc_826CD7D0;
	// li r29,0
	r29.s64 = 0;
loc_826CD7AC:
	// lwz r11,716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 716);
	// li r4,1
	ctx.r4.s64 = 1;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x826cc168
	ctx.lr = 0x826CD7BC;
	sub_826CC168(ctx, base);
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,144
	r29.s64 = r29.s64 + 144;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826cd7ac
	if (cr6.lt) goto loc_826CD7AC;
loc_826CD7D0:
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd814
	if (cr6.eq) goto loc_826CD814;
	// li r30,0
	r30.s64 = 0;
loc_826CD7E4:
	// lwz r11,708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826cc598
	ctx.lr = 0x826CD7F0;
	sub_826CC598(ctx, base);
	// lwz r11,708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826cc4b0
	ctx.lr = 0x826CD800;
	sub_826CC4B0(ctx, base);
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826cd7e4
	if (cr6.lt) goto loc_826CD7E4;
loc_826CD814:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CD768) {
	__imp__sub_826CD768(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD81C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD81C) {
	__imp__sub_826CD81C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD820) {
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
	ctx.lr = 0x826CD828;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x826cd5c8
	ctx.lr = 0x826CD834;
	sub_826CD5C8(ctx, base);
	// lhz r11,712(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 712);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd874
	if (cr6.eq) goto loc_826CD874;
	// li r31,0
	r31.s64 = 0;
loc_826CD848:
	// lwz r11,708(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 708);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc540
	ctx.lr = 0x826CD854;
	sub_826CC540(ctx, base);
	// lwz r11,708(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 708);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc638
	ctx.lr = 0x826CD860;
	sub_826CC638(ctx, base);
	// lhz r11,712(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 712);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,144
	r31.s64 = r31.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826cd848
	if (cr6.lt) goto loc_826CD848;
loc_826CD874:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CD820) {
	__imp__sub_826CD820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD87C) {
	__imp__sub_826CD87C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD880) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,686(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 686);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cd894
	if (!cr6.eq) goto loc_826CD894;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826CD894:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// b 0x826c3d98
	sub_826C3D98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CD880) {
	__imp__sub_826CD880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD8A4) {
	__imp__sub_826CD8A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD8A8) {
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
	ctx.lr = 0x826CD8B0;
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
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x826c6d38
	ctx.lr = 0x826CD8C8;
	sub_826C6D38(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826cd528
	ctx.lr = 0x826CD8D8;
	sub_826CD528(ctx, base);
	// lhz r11,720(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 720);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd920
	if (cr6.eq) goto loc_826CD920;
	// li r31,0
	r31.s64 = 0;
loc_826CD8EC:
	// lwz r11,716(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 716);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc4b0
	ctx.lr = 0x826CD8FC;
	sub_826CC4B0(ctx, base);
	// lwz r11,716(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 716);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc168
	ctx.lr = 0x826CD90C;
	sub_826CC168(ctx, base);
	// lhz r11,720(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 720);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,144
	r31.s64 = r31.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826cd8ec
	if (cr6.lt) goto loc_826CD8EC;
loc_826CD920:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CD8A8) {
	__imp__sub_826CD8A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD928) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,720(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 720);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cd93c
	if (cr6.eq) goto loc_826CD93C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826CD93C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// b 0x826c3d98
	sub_826C3D98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CD928) {
	__imp__sub_826CD928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CD94C) {
	__imp__sub_826CD94C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD950) {
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
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r9,720(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826cd99c
	if (!cr6.gt) goto loc_826CD99C;
	// lwz r10,716(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 716);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r10,r10,116
	ctx.r10.s64 = ctx.r10.s64 + 116;
loc_826CD980:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826cd990
	if (cr6.eq) goto loc_826CD990;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_826CD990:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,144
	ctx.r10.s64 = ctx.r10.s64 + 144;
	// bne 0x826cd980
	if (!cr0.eq) goto loc_826CD980;
loc_826CD99C:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x826cd9c4
	if (!cr6.eq) goto loc_826CD9C4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826CD9B4;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x826c67f8
	ctx.lr = 0x826CD9C4;
	sub_826C67F8(ctx, base);
loc_826CD9C4:
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

PPC_WEAK_FUNC(sub_826CD950) {
	__imp__sub_826CD950(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CD9D8) {
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
	ctx.lr = 0x826CD9E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x826c6d38
	ctx.lr = 0x826CD9F8;
	sub_826C6D38(ctx, base);
	// lhz r11,720(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 720);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cda4c
	if (cr6.eq) goto loc_826CDA4C;
	// li r31,0
	r31.s64 = 0;
loc_826CDA0C:
	// lwz r11,716(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 716);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc598
	ctx.lr = 0x826CDA18;
	sub_826CC598(ctx, base);
	// lwz r11,716(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 716);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc4b0
	ctx.lr = 0x826CDA28;
	sub_826CC4B0(ctx, base);
	// lwz r11,716(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 716);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc168
	ctx.lr = 0x826CDA38;
	sub_826CC168(ctx, base);
	// lhz r11,720(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 720);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,144
	r31.s64 = r31.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826cda0c
	if (cr6.lt) goto loc_826CDA0C;
loc_826CDA4C:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826cd528
	ctx.lr = 0x826CDA5C;
	sub_826CD528(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CD9D8) {
	__imp__sub_826CD9D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CDA64) {
	__imp__sub_826CDA64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDA68) {
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
	ctx.lr = 0x826CDA70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x826cd5c8
	ctx.lr = 0x826CDA7C;
	sub_826CD5C8(ctx, base);
	// lhz r11,720(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 720);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cdabc
	if (cr6.eq) goto loc_826CDABC;
	// li r31,0
	r31.s64 = 0;
loc_826CDA90:
	// lwz r11,716(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 716);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc540
	ctx.lr = 0x826CDA9C;
	sub_826CC540(ctx, base);
	// lwz r11,716(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 716);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc638
	ctx.lr = 0x826CDAA8;
	sub_826CC638(ctx, base);
	// lhz r11,720(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 720);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,144
	r31.s64 = r31.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826cda90
	if (cr6.lt) goto loc_826CDA90;
loc_826CDABC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CDA68) {
	__imp__sub_826CDA68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CDAC4) {
	__imp__sub_826CDAC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDAC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,688(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 688);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cdadc
	if (!cr6.eq) goto loc_826CDADC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826CDADC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// b 0x826c3d98
	sub_826C3D98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CDAC8) {
	__imp__sub_826CDAC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CDAEC) {
	__imp__sub_826CDAEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDAF0) {
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
	ctx.lr = 0x826CDAF8;
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
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x826c6d38
	ctx.lr = 0x826CDB10;
	sub_826C6D38(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826cd528
	ctx.lr = 0x826CDB20;
	sub_826CD528(ctx, base);
	// lhz r11,720(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 720);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cdb58
	if (cr6.eq) goto loc_826CDB58;
	// li r31,0
	r31.s64 = 0;
loc_826CDB34:
	// lwz r11,716(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 716);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826cc168
	ctx.lr = 0x826CDB44;
	sub_826CC168(ctx, base);
	// lhz r11,720(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 720);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,144
	r31.s64 = r31.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826cdb34
	if (cr6.lt) goto loc_826CDB34;
loc_826CDB58:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CDAF0) {
	__imp__sub_826CDAF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDB60) {
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
	// bl 0x826cd528
	ctx.lr = 0x826CDB80;
	sub_826CD528(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6e50
	ctx.lr = 0x826CDB88;
	sub_826C6E50(ctx, base);
	// lwz r11,704(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 704);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x826cdbc4
	if (!cr6.eq) goto loc_826CDBC4;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cdba8
	if (!cr6.eq) goto loc_826CDBA8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c70c8
	ctx.lr = 0x826CDBA8;
	sub_826C70C8(ctx, base);
loc_826CDBA8:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-10004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10004);
	// bl 0x826c3f20
	ctx.lr = 0x826CDBBC;
	sub_826C3F20(ctx, base);
	// lwz r3,-10004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10004);
	// bl 0x826c4388
	ctx.lr = 0x826CDBC4;
	sub_826C4388(ctx, base);
loc_826CDBC4:
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

PPC_WEAK_FUNC(sub_826CDB60) {
	__imp__sub_826CDB60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDBDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CDBDC) {
	__imp__sub_826CDBDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDBE0) {
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
	// bl 0x826cd5c8
	ctx.lr = 0x826CDBF8;
	sub_826CD5C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6f40
	ctx.lr = 0x826CDC00;
	sub_826C6F40(ctx, base);
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

PPC_WEAK_FUNC(sub_826CDBE0) {
	__imp__sub_826CDBE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDC14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CDC14) {
	__imp__sub_826CDC14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDC18) {
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
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826CDC34;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826cdc5c
	if (!cr6.gt) goto loc_826CDC5C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,-2
	ctx.r10.s64 = -2;
loc_826CDC44:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cdc50
	if (cr6.eq) goto loc_826CDC50;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_826CDC50:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826cdc44
	if (!cr0.eq) goto loc_826CDC44;
loc_826CDC5C:
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

PPC_WEAK_FUNC(sub_826CDC18) {
	__imp__sub_826CDC18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDC70) {
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
	ctx.lr = 0x826CDC78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mulli r3,r30,84
	ctx.r3.s64 = r30.s64 * 84;
	// bl 0x82130528
	ctx.lr = 0x826CDC88;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826cdcb4
	if (!cr6.gt) goto loc_826CDCB4;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_826CDC98:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826cdca8
	if (cr6.eq) goto loc_826CDCA8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d4360
	ctx.lr = 0x826CDCA8;
	sub_826D4360(ctx, base);
loc_826CDCA8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// bne 0x826cdc98
	if (!cr0.eq) goto loc_826CDC98;
loc_826CDCB4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CDC70) {
	__imp__sub_826CDC70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDCC0) {
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
	// rlwinm r3,r31,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x826CDCDC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826cdd0c
	if (!cr6.gt) goto loc_826CDD0C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,-2
	ctx.r9.s64 = -2;
	// li r10,0
	ctx.r10.s64 = 0;
loc_826CDCF0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cdd00
	if (cr6.eq) goto loc_826CDD00;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
loc_826CDD00:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x826cdcf0
	if (!cr0.eq) goto loc_826CDCF0;
loc_826CDD0C:
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

PPC_WEAK_FUNC(sub_826CDCC0) {
	__imp__sub_826CDCC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDD20) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x826cdd78
	if (cr6.eq) goto loc_826CDD78;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826cdd70
	if (cr6.eq) goto loc_826CDD70;
	// bl 0x826cdc18
	ctx.lr = 0x826CDD68;
	sub_826CDC18(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x826cdd78
	goto loc_826CDD78;
loc_826CDD70:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_826CDD78:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cddb0
	if (cr6.eq) goto loc_826CDDB0;
	// li r11,0
	r11.s64 = 0;
loc_826CDD88:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stwx r6,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r6.u32);
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// blt cr6,0x826cdd88
	if (cr6.lt) goto loc_826CDD88;
loc_826CDDB0:
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

PPC_WEAK_FUNC(sub_826CDD20) {
	__imp__sub_826CDD20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDDC8) {
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
	ctx.lr = 0x826CDDD0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,6
	r11.s64 = ctx.r4.s64 + 6;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// rlwinm r27,r11,3,0,28
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lhzx r10,r27,r29
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cde24
	if (cr6.eq) goto loc_826CDE24;
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// add r28,r11,r29
	r28.u64 = r11.u64 + r29.u64;
loc_826CDE00:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x826d44a8
	ctx.lr = 0x826CDE10;
	sub_826D44A8(ctx, base);
	// lhzx r11,r27,r29
	r11.u64 = PPC_LOAD_U16(r27.u32 + r29.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826cde00
	if (cr6.lt) goto loc_826CDE00;
loc_826CDE24:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826CDDC8) {
	__imp__sub_826CDDC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CDE2C) {
	__imp__sub_826CDE2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDE30) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826CDE5C;
	sub_822A3998(ctx, base);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826CDE64;
	sub_8238EFE8(ctx, base);
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// li r11,0
	r11.s64 = 0;
	// lhz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// blt cr6,0x826cdedc
	if (cr6.lt) goto loc_826CDEDC;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r8,r7,-3
	ctx.r8.s64 = ctx.r7.s64 + -3;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
loc_826CDE8C:
	// lfs f0,-24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x826cde9c
	if (!cr6.gt) goto loc_826CDE9C;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_826CDE9C:
	// lfs f0,-12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x826cdeac
	if (!cr6.gt) goto loc_826CDEAC;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
loc_826CDEAC:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x826cdebc
	if (!cr6.gt) goto loc_826CDEBC;
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
loc_826CDEBC:
	// lfs f0,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x826cdecc
	if (!cr6.gt) goto loc_826CDECC;
	// addi r3,r11,3
	ctx.r3.s64 = r11.s64 + 3;
loc_826CDECC:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x826cde8c
	if (cr6.lt) goto loc_826CDE8C;
loc_826CDEDC:
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// bge cr6,0x826cdf18
	if (!cr6.lt) goto loc_826CDF18;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_826CDEF8:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x826cdf08
	if (!cr6.gt) goto loc_826CDF08;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_826CDF08:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x826cdef8
	if (cr6.lt) goto loc_826CDEF8;
loc_826CDF18:
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

PPC_WEAK_FUNC(sub_826CDE30) {
	__imp__sub_826CDE30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDF30) {
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
	ctx.lr = 0x826CDF38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,5
	r11.s64 = 5;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r25,5
	r25.s64 = 5;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r27,r26,44
	r27.s64 = r26.s64 + 44;
	// stwx r11,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_826CDF68:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r30,4(r27)
	r30.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stwx r30,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r30.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// ble cr6,0x826cdfac
	if (!cr6.gt) goto loc_826CDFAC;
	// li r29,0
	r29.s64 = 0;
loc_826CDF8C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x826d4448
	ctx.lr = 0x826CDFA0;
	sub_826D4448(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// bne 0x826cdf8c
	if (!cr0.eq) goto loc_826CDF8C;
loc_826CDFAC:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r27,r27,8
	r27.s64 = r27.s64 + 8;
	// bne 0x826cdf68
	if (!cr0.eq) goto loc_826CDF68;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r26,145
	r11.s64 = r26.s64 + 145;
	// li r9,5
	ctx.r9.s64 = 5;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826CDFCC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x826cdfcc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826CDFCC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_826CDF30) {
	__imp__sub_826CDF30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CDFF4) {
	__imp__sub_826CDFF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CDFF8) {
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
	ctx.lr = 0x826CE000;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r25,r11,r28
	r25.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x826ce080
	if (!cr6.gt) goto loc_826CE080;
	// addi r27,r23,44
	r27.s64 = r23.s64 + 44;
	// mr r24,r25
	r24.u64 = r25.u64;
loc_826CE034:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r31,r11,r28
	r31.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826ce074
	if (!cr6.gt) goto loc_826CE074;
	// li r30,0
	r30.s64 = 0;
loc_826CE050:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826d4468
	ctx.lr = 0x826CE068;
	sub_826D4468(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// bne 0x826ce050
	if (!cr0.eq) goto loc_826CE050;
loc_826CE074:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r27,r27,8
	r27.s64 = r27.s64 + 8;
	// bne 0x826ce034
	if (!cr0.eq) goto loc_826CE034;
loc_826CE080:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r3,r23,145
	ctx.r3.s64 = r23.s64 + 145;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// bl 0x823da950
	ctx.lr = 0x826CE094;
	sub_823DA950(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_826CDFF8) {
	__imp__sub_826CDFF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE0A8) {
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
	ctx.lr = 0x826CE0B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// add r11,r4,r29
	r11.u64 = ctx.r4.u64 + r29.u64;
	// lbz r10,145(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 145);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826ce124
	if (!cr6.eq) goto loc_826CE124;
	// addi r11,r4,6
	r11.s64 = ctx.r4.s64 + 6;
	// li r30,0
	r30.s64 = 0;
	// rlwinm r27,r11,3,0,28
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r10,r27,r29
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ce124
	if (cr6.eq) goto loc_826CE124;
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// add r28,r11,r29
	r28.u64 = r11.u64 + r29.u64;
loc_826CE0EC:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x826ce110
	if (cr6.eq) goto loc_826CE110;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826ce110
	if (cr6.eq) goto loc_826CE110;
	// bl 0x826d03c8
	ctx.lr = 0x826CE110;
	sub_826D03C8(ctx, base);
loc_826CE110:
	// lhzx r11,r27,r29
	r11.u64 = PPC_LOAD_U16(r27.u32 + r29.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826ce0ec
	if (cr6.lt) goto loc_826CE0EC;
loc_826CE124:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CE0A8) {
	__imp__sub_826CE0A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CE12C) {
	__imp__sub_826CE12C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE130) {
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
	ctx.lr = 0x826CE138;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r5,184(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 184);
	// addi r11,r5,6
	r11.s64 = ctx.r5.s64 + 6;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r6,r10,r3
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x826ce1d0
	if (!cr6.gt) goto loc_826CE1D0;
	// rlwinm r11,r5,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r3
	r30.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
loc_826CE174:
	// lwz r8,-4(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826ce1c0
	if (cr6.eq) goto loc_826CE1C0;
	// addi r10,r29,4
	ctx.r10.s64 = r29.s64 + 4;
	// addi r11,r8,4
	r11.s64 = ctx.r8.s64 + 4;
loc_826CE188:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
	// beq cr6,0x826ce1ac
	if (cr6.eq) goto loc_826CE1AC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826ce188
	if (cr6.eq) goto loc_826CE188;
loc_826CE1AC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826ce1c0
	if (!cr6.eq) goto loc_826CE1C0;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x826ce2a8
	if (!cr6.eq) goto loc_826CE2A8;
loc_826CE1C0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r7,r7,84
	ctx.r7.s64 = ctx.r7.s64 + 84;
	// cmpw cr6,r31,r6
	cr6.compare<int32_t>(r31.s32, ctx.r6.s32, xer);
	// blt cr6,0x826ce174
	if (cr6.lt) goto loc_826CE174;
loc_826CE1D0:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x826ce208
	if (!cr6.gt) goto loc_826CE208;
	// rlwinm r11,r5,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r3
	r30.u64 = r11.u64 + ctx.r3.u64;
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r11,r9,8
	r11.s64 = ctx.r9.s64 + 8;
loc_826CE1EC:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x826ce2d8
	if (cr6.eq) goto loc_826CE2D8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x826ce1ec
	if (cr6.lt) goto loc_826CE1EC;
loc_826CE208:
	// lwz r9,180(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// cmpwi cr6,r9,-2
	cr6.compare<int32_t>(ctx.r9.s32, -2, xer);
	// beq cr6,0x826ce264
	if (cr6.eq) goto loc_826CE264;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x826ce264
	if (!cr6.gt) goto loc_826CE264;
	// rlwinm r11,r5,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r3
	r30.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_826CE230:
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ce254
	if (cr6.eq) goto loc_826CE254;
	// lwz r8,180(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 180);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x826ce254
	if (!cr6.eq) goto loc_826CE254;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r8,r28
	cr6.compare<int32_t>(ctx.r8.s32, r28.s32, xer);
	// bgt cr6,0x826ce314
	if (cr6.gt) goto loc_826CE314;
loc_826CE254:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// cmpw cr6,r31,r6
	cr6.compare<int32_t>(r31.s32, ctx.r6.s32, xer);
	// blt cr6,0x826ce230
	if (cr6.lt) goto loc_826CE230;
loc_826CE264:
	// addic. r11,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	r11.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x826ce29c
	if (cr0.lt) goto loc_826CE29C;
	// rlwinm r9,r5,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// mulli r10,r11,84
	ctx.r10.s64 = r11.s64 * 84;
	// add r30,r9,r3
	r30.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
loc_826CE284:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r8,r28
	cr6.compare<int32_t>(ctx.r8.s32, r28.s32, xer);
	// bgt cr6,0x826ce344
	if (cr6.gt) goto loc_826CE344;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-84
	ctx.r10.s64 = ctx.r10.s64 + -84;
	// bge 0x826ce284
	if (!cr0.lt) goto loc_826CE284;
loc_826CE29C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826CE2A8:
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x826d03c8
	ctx.lr = 0x826CE2B0;
	sub_826D03C8(ctx, base);
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// mulli r11,r31,84
	r11.s64 = r31.s64 * 84;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x826d4488
	ctx.lr = 0x826CE2CC;
	sub_826D4488(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826CE2D8:
	// mulli r31,r10,84
	r31.s64 = ctx.r10.s64 * 84;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ce2f0
	if (cr6.eq) goto loc_826CE2F0;
	// bl 0x826d03c8
	ctx.lr = 0x826CE2F0;
	sub_826D03C8(ctx, base);
loc_826CE2F0:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r3,r31,r11
	ctx.r3.u64 = r31.u64 + r11.u64;
	// bl 0x826d4488
	ctx.lr = 0x826CE308;
	sub_826D4488(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826CE314:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x826d03c8
	ctx.lr = 0x826CE31C;
	sub_826D03C8(ctx, base);
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// mulli r11,r31,84
	r11.s64 = r31.s64 * 84;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x826d4488
	ctx.lr = 0x826CE338;
	sub_826D4488(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826CE344:
	// mulli r31,r11,84
	r31.s64 = r11.s64 * 84;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ce35c
	if (cr6.eq) goto loc_826CE35C;
	// bl 0x826d03c8
	ctx.lr = 0x826CE35C;
	sub_826D03C8(ctx, base);
loc_826CE35C:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r3,r31,r11
	ctx.r3.u64 = r31.u64 + r11.u64;
	// bl 0x826d4488
	ctx.lr = 0x826CE374;
	sub_826D4488(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CE130) {
	__imp__sub_826CE130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE380) {
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
	ctx.lr = 0x826CE388;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826ce3f4
	if (cr6.eq) goto loc_826CE3F4;
	// lwz r11,184(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 184);
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,6
	ctx.r10.s64 = r11.s64 + 6;
	// rlwinm r26,r10,3,0,28
	r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r9,r26,r29
	ctx.r9.u64 = PPC_LOAD_U16(r26.u32 + r29.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826ce3f4
	if (cr6.eq) goto loc_826CE3F4;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// add r28,r11,r29
	r28.u64 = r11.u64 + r29.u64;
loc_826CE3C4:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bne cr6,0x826ce3e0
	if (!cr6.eq) goto loc_826CE3E0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826d44a8
	ctx.lr = 0x826CE3E0;
	sub_826D44A8(ctx, base);
loc_826CE3E0:
	// lhzx r11,r26,r29
	r11.u64 = PPC_LOAD_U16(r26.u32 + r29.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826ce3c4
	if (cr6.lt) goto loc_826CE3C4;
loc_826CE3F4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826CE380) {
	__imp__sub_826CE380(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CE3FC) {
	__imp__sub_826CE3FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE400) {
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
	ctx.lr = 0x826CE408;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826ce4b0
	if (!cr6.eq) goto loc_826CE4B0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x826cdc70
	ctx.lr = 0x826CE430;
	sub_826CDC70(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ce46c
	if (cr6.eq) goto loc_826CE46C;
	// li r30,0
	r30.s64 = 0;
loc_826CE444:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r11,r30,84
	r11.s64 = r30.s64 * 84;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x826d4398
	ctx.lr = 0x826CE458;
	sub_826D4398(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x826ce444
	if (cr6.lt) goto loc_826CE444;
loc_826CE46C:
	// lhz r29,4(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x826ce4a4
	if (!cr6.gt) goto loc_826CE4A4;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_826CE480:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CE498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// bne 0x826ce480
	if (!cr0.eq) goto loc_826CE480;
loc_826CE4A4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x826CE4AC;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_826CE4B0:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r10,r11,84
	ctx.r10.s64 = r11.s64 * 84;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CE400) {
	__imp__sub_826CE400(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE4D0) {
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
	// bne cr6,0x826ce514
	if (!cr6.eq) goto loc_826CE514;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x826ce50c
	if (cr6.eq) goto loc_826CE50C;
	// bl 0x826cdcc0
	ctx.lr = 0x826CE508;
	sub_826CDCC0(ctx, base);
	// b 0x826ce510
	goto loc_826CE510;
loc_826CE50C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826CE510:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826CE514:
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

PPC_WEAK_FUNC(sub_826CE4D0) {
	__imp__sub_826CE4D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE530) {
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
	ctx.lr = 0x826CE538;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c9790
	ctx.lr = 0x826CE558;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r11,r31,7
	r11.s64 = r31.s64 + 7;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x826bddb0
	ctx.lr = 0x826CE578;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ce590
	if (cr6.eq) goto loc_826CE590;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stb r28,48(r11)
	PPC_STORE_U8(r11.u32 + 48, r28.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826CE590:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-28196
	ctx.r9.s64 = r11.s64 + -28196;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r8,-2312
	ctx.r3.s64 = ctx.r8.s64 + -2312;
	// lwzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x826CE5B0;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CE530) {
	__imp__sub_826CE530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE5B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ce5e8
	if (cr6.eq) goto loc_826CE5E8;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// b 0x826cddc8
	sub_826CDDC8(ctx, base);
	return;
loc_826CE5E8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-2216
	ctx.r3.s64 = r11.s64 + -2216;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CE5B8) {
	__imp__sub_826CE5B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CE5F4) {
	__imp__sub_826CE5F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE5F8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ce630
	if (cr6.eq) goto loc_826CE630;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lbz r11,8741(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 8741);
	// b 0x826ce640
	goto loc_826CE640;
loc_826CE630:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-2136
	ctx.r3.s64 = r11.s64 + -2136;
	// bl 0x82130000
	ctx.lr = 0x826CE63C;
	sub_82130000(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_826CE640:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_826CE5F8) {
	__imp__sub_826CE5F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE660) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x826CE668;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lwz r3,-10020(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10020);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ce848
	if (cr6.eq) goto loc_826CE848;
	// bl 0x826bcc58
	ctx.lr = 0x826CE6A4;
	sub_826BCC58(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826ce854
	if (cr6.eq) goto loc_826CE854;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x826CE6C0;
	sub_823DB670(ctx, base);
	// stw r27,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r27.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x823db670
	ctx.lr = 0x826CE6D4;
	sub_823DB670(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x823db670
	ctx.lr = 0x826CE6E4;
	sub_823DB670(ctx, base);
	// stw r29,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r29.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826ce80c
	if (cr6.eq) goto loc_826CE80C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-1884
	ctx.r4.s64 = r11.s64 + -1884;
	// bl 0x823d90b0
	ctx.lr = 0x826CE700;
	sub_823D90B0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826ce728
	if (!cr6.eq) goto loc_826CE728;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-1892
	ctx.r4.s64 = r11.s64 + -1892;
	// bl 0x823d90b0
	ctx.lr = 0x826CE71C;
	sub_823D90B0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826ce80c
	if (cr6.eq) goto loc_826CE80C;
loc_826CE728:
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
	// beq cr6,0x826ce75c
	if (cr6.eq) goto loc_826CE75C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826ce778
	if (!cr6.gt) goto loc_826CE778;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x826ce76c
	goto loc_826CE76C;
loc_826CE75C:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826ce778
	if (!cr6.gt) goto loc_826CE778;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_826CE76C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826ce77c
	if (!cr6.eq) goto loc_826CE77C;
loc_826CE778:
	// li r11,0
	r11.s64 = 0;
loc_826CE77C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ce80c
	if (cr6.eq) goto loc_826CE80C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x826CE790;
	sub_822A3998(ctx, base);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826CE798;
	sub_8238EFE8(ctx, base);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8239c698
	ctx.lr = 0x826CE7A4;
	sub_8239C698(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826ce80c
	if (cr6.eq) goto loc_826CE80C;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8239c080
	ctx.lr = 0x826CE7BC;
	sub_8239C080(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r30,-10020(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + -10020);
	// bl 0x8239c2c8
	ctx.lr = 0x826CE7D4;
	sub_8239C2C8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fsubs f1,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 - f31.f64));
	// bl 0x826bcaf0
	ctx.lr = 0x826CE7E0;
	sub_826BCAF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x826ce7f4
	if (cr6.gt) goto loc_826CE7F4;
	// li r11,1
	r11.s64 = 1;
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// b 0x826ce80c
	goto loc_826CE80C;
loc_826CE7F4:
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x826ce808
	if (!cr6.eq) goto loc_826CE808;
	// li r11,3
	r11.s64 = 3;
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// b 0x826ce80c
	goto loc_826CE80C;
loc_826CE808:
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
loc_826CE80C:
	// lwz r11,-10020(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10020);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// bl 0x826ce130
	ctx.lr = 0x826CE824;
	sub_826CE130(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ce858
	if (!cr6.eq) goto loc_826CE858;
	// bl 0x826d0328
	ctx.lr = 0x826CE838;
	sub_826D0328(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_826CE848:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1968
	ctx.r3.s64 = r11.s64 + -1968;
	// bl 0x82130000
	ctx.lr = 0x826CE854;
	sub_82130000(ctx, base);
loc_826CE854:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826CE858:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_826CE660) {
	__imp__sub_826CE660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CE864) {
	__imp__sub_826CE864(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE868) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ce88c
	if (cr6.eq) goto loc_826CE88C;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// b 0x826ce530
	sub_826CE530(ctx, base);
	return;
loc_826CE88C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1872
	ctx.r3.s64 = r11.s64 + -1872;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CE868) {
	__imp__sub_826CE868(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r7,r3,44
	ctx.r7.s64 = ctx.r3.s64 + 44;
	// addi r5,r3,145
	ctx.r5.s64 = ctx.r3.s64 + 145;
loc_826CE8A8:
	// lbzx r10,r5,r6
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r6.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826ce8f0
	if (!cr6.eq) goto loc_826CE8F0;
	// lhz r8,4(r7)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826ce8ec
	if (!cr6.gt) goto loc_826CE8EC;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_826CE8C8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x826ce8dc
	if (cr6.eq) goto loc_826CE8DC;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bne cr6,0x826ce914
	if (!cr6.eq) goto loc_826CE914;
loc_826CE8DC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x826ce8c8
	if (cr6.lt) goto loc_826CE8C8;
loc_826CE8EC:
	// li r11,1
	r11.s64 = 1;
loc_826CE8F0:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ce91c
	if (cr6.eq) goto loc_826CE91C;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// cmpwi cr6,r6,5
	cr6.compare<int32_t>(ctx.r6.s32, 5, xer);
	// blt cr6,0x826ce8a8
	if (cr6.lt) goto loc_826CE8A8;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_826CE914:
	// li r11,0
	r11.s64 = 0;
	// b 0x826ce8f0
	goto loc_826CE8F0;
loc_826CE91C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CE898) {
	__imp__sub_826CE898(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CE924) {
	__imp__sub_826CE924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE928) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x826CE950;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r11,r31,7
	r11.s64 = r31.s64 + 7;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826bddb0
	ctx.lr = 0x826CE970;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ce980
	if (cr6.eq) goto loc_826CE980;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x826ce984
	goto loc_826CE984;
loc_826CE980:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826CE984:
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

PPC_WEAK_FUNC(sub_826CE928) {
	__imp__sub_826CE928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE99C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CE99C) {
	__imp__sub_826CE99C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CE9A0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r8,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// xori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 ^ 1;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// mtctr r30
	ctr.u64 = r30.u64;
	// bctrl 
	ctx.lr = 0x826CE9FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_826CE9A0) {
	__imp__sub_826CE9A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CEA1C) {
	__imp__sub_826CEA1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEA20) {
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
	ctx.lr = 0x826CEA28;
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r25,r11,30576
	r25.s64 = r11.s64 + 30576;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r10,-3108
	ctx.r4.s64 = ctx.r10.s64 + -3108;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821ca540
	ctx.lr = 0x826CEA4C;
	sub_821CA540(ctx, base);
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// rlwinm r29,r31,2,0,29
	r29.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r9,-28196
	r30.s64 = ctx.r9.s64 + -28196;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r5,r8,-32764
	ctx.r5.s64 = ctx.r8.s64 + -32764;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwzx r4,r29,r30
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// bl 0x821ca6a8
	ctx.lr = 0x826CEA74;
	sub_821CA6A8(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x826ceaa8
	if (!cr6.eq) goto loc_826CEAA8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826CEA88;
	sub_821C9A90(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwzx r5,r29,r30
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// addi r4,r11,-1728
	ctx.r4.s64 = r11.s64 + -1728;
	// addi r3,r10,-1784
	ctx.r3.s64 = ctx.r10.s64 + -1784;
	// bl 0x82130000
	ctx.lr = 0x826CEAA0;
	sub_82130000(ctx, base);
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9234
	return;
loc_826CEAA8:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d1cd0
	ctx.lr = 0x826CEAB0;
	sub_821D1CD0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r4,r11,32672
	ctx.r4.s64 = r11.s64 + 32672;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821cf7b8
	ctx.lr = 0x826CEAC4;
	sub_821CF7B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r23,r11,32660
	r23.s64 = r11.s64 + 32660;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x821cff40
	ctx.lr = 0x826CEADC;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cec38
	if (cr6.eq) goto loc_826CEC38;
	// addi r11,r31,7
	r11.s64 = r31.s64 + 7;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r29,0
	r29.s64 = 0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r26,r9,-29628
	r26.s64 = ctx.r9.s64 + -29628;
	// add r30,r11,r28
	r30.u64 = r11.u64 + r28.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r28,r10,9848
	r28.s64 = ctx.r10.s64 + 9848;
	// addi r27,r11,-29624
	r27.s64 = r11.s64 + -29624;
loc_826CEB18:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0898
	ctx.lr = 0x826CEB24;
	sub_821D0898(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821cfe20
	ctx.lr = 0x826CEB30;
	sub_821CFE20(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821cfaa8
	ctx.lr = 0x826CEB40;
	sub_821CFAA8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9790
	ctx.lr = 0x826CEB4C;
	sub_821C9790(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cebb0
	if (cr6.eq) goto loc_826CEBB0;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
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
	// beq cr6,0x826cebb0
	if (cr6.eq) goto loc_826CEBB0;
loc_826CEB7C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x826ceb98
	if (cr6.eq) goto loc_826CEB98;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ceb7c
	if (!cr6.eq) goto loc_826CEB7C;
	// b 0x826cebb0
	goto loc_826CEBB0;
loc_826CEB98:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cebb0
	if (cr6.eq) goto loc_826CEBB0;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826cec04
	if (!cr6.eq) goto loc_826CEC04;
loc_826CEBB0:
	// li r3,52
	ctx.r3.s64 = 52;
	// bl 0x82130528
	ctx.lr = 0x826CEBB8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826cebe4
	if (cr6.eq) goto loc_826CEBE4;
	// sth r29,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r29.u16);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// sth r29,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r29.u16);
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
	// stb r29,47(r31)
	PPC_STORE_U8(r31.u32 + 47, r29.u8);
	// stb r29,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r29.u8);
	// bl 0x823986d0
	ctx.lr = 0x826CEBE0;
	sub_823986D0(ctx, base);
	// b 0x826cebe8
	goto loc_826CEBE8;
loc_826CEBE4:
	// mr r31,r29
	r31.u64 = r29.u64;
loc_826CEBE8:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82389998
	ctx.lr = 0x826CEC04;
	sub_82389998(ctx, base);
loc_826CEC04:
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82398ca8
	ctx.lr = 0x826CEC10;
	sub_82398CA8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0898
	ctx.lr = 0x826CEC1C;
	sub_821D0898(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821cff40
	ctx.lr = 0x826CEC2C;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ceb18
	if (!cr6.eq) goto loc_826CEB18;
loc_826CEC38:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be610
	ctx.lr = 0x826CEC40;
	sub_821BE610(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826CEC48;
	sub_821C9A90(ctx, base);
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_826CEA20) {
	__imp__sub_826CEA20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEC50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cec70
	if (cr6.eq) goto loc_826CEC70;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x826ce380
	sub_826CE380(ctx, base);
	return;
loc_826CEC70:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-2048
	ctx.r3.s64 = r11.s64 + -2048;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CEC50) {
	__imp__sub_826CEC50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEC7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CEC7C) {
	__imp__sub_826CEC7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEC80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32147
	r11.s64 = -2106785792;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-6560
	ctx.r3.s64 = r11.s64 + -6560;
	// b 0x826ce9a0
	sub_826CE9A0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CEC80) {
	__imp__sub_826CEC80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEC90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,-10020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 ^ 1;
	// beq cr6,0x826cecc8
	if (cr6.eq) goto loc_826CECC8;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// b 0x826ce530
	sub_826CE530(ctx, base);
	return;
loc_826CECC8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1872
	ctx.r3.s64 = r11.s64 + -1872;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CEC90) {
	__imp__sub_826CEC90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CECD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CECD4) {
	__imp__sub_826CECD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CECD8) {
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
	ctx.lr = 0x826CECE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ced2c
	if (cr6.eq) goto loc_826CED2C;
	// addi r30,r11,8596
	r30.s64 = r11.s64 + 8596;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r30,145
	r29.s64 = r30.s64 + 145;
loc_826CED00:
	// lbzx r11,r29,r31
	r11.u64 = PPC_LOAD_U8(r29.u32 + r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ced18
	if (!cr6.eq) goto loc_826CED18;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826ce0a8
	ctx.lr = 0x826CED18;
	sub_826CE0A8(ctx, base);
loc_826CED18:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,5
	cr6.compare<int32_t>(r31.s32, 5, xer);
	// blt cr6,0x826ced00
	if (cr6.lt) goto loc_826CED00;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826CED2C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1712
	ctx.r3.s64 = r11.s64 + -1712;
	// bl 0x82130000
	ctx.lr = 0x826CED38;
	sub_82130000(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CECD8) {
	__imp__sub_826CECD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CED40) {
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
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cedb0
	if (cr6.eq) goto loc_826CEDB0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// bl 0x826ce928
	ctx.lr = 0x826CED7C;
	sub_826CE928(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ced8c
	if (cr6.eq) goto loc_826CED8C;
	// lbz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// b 0x826cedc0
	goto loc_826CEDC0;
loc_826CED8C:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-28196
	ctx.r9.s64 = r11.s64 + -28196;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r8,-1360
	ctx.r3.s64 = ctx.r8.s64 + -1360;
	// lwzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x826CEDAC;
	sub_82130000(ctx, base);
	// b 0x826cedbc
	goto loc_826CEDBC;
loc_826CEDB0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1440
	ctx.r3.s64 = r11.s64 + -1440;
	// bl 0x82130000
	ctx.lr = 0x826CEDBC;
	sub_82130000(ctx, base);
loc_826CEDBC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826CEDC0:
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

PPC_WEAK_FUNC(sub_826CED40) {
	__imp__sub_826CED40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEDD8) {
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
	ctx.lr = 0x826CEDE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r31,7
	r11.s64 = r31.s64 + 7;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// bl 0x82237920
	ctx.lr = 0x826CEE1C;
	sub_82237920(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// add r6,r31,r11
	ctx.r6.u64 = r31.u64 + r11.u64;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lwz r11,-10020(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10020);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addis r4,r11,1
	ctx.r4.s64 = r11.s64 + 65536;
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// addi r4,r4,27768
	ctx.r4.s64 = ctx.r4.s64 + 27768;
	// lhz r8,90(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 90);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// twllei r8,0
	// mulld r11,r11,r5
	r11.s64 = r11.s64 * ctx.r5.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r7,r11,1
	ctx.r7.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r5,r7,r8
	ctx.r5.s32 = ctx.r7.s32 / ctx.r8.s32;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// andc r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 & ~ctx.r3.u64;
	// mullw r8,r5,r8
	ctx.r8.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// twlgei r10,-1
	// subf r5,r8,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r8.s64;
	// beq cr6,0x826cef0c
	if (cr6.eq) goto loc_826CEF0C;
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_826CEE9C:
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826ceeac
	if (!cr6.eq) goto loc_826CEEAC;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_826CEEAC:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x826cef10
	if (cr6.eq) goto loc_826CEF10;
	// lwz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826cee9c
	if (!cr6.eq) goto loc_826CEE9C;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
loc_826CEED0:
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x826ceef8
	if (!cr6.lt) goto loc_826CEEF8;
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826ceed0
	if (cr6.eq) goto loc_826CEED0;
	// b 0x826cee9c
	goto loc_826CEE9C;
loc_826CEEF8:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826cee9c
	if (!cr6.eq) goto loc_826CEE9C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bne cr6,0x826cef10
	if (!cr6.eq) goto loc_826CEF10;
loc_826CEF0C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826CEF10:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CEDD8) {
	__imp__sub_826CEDD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEF18) {
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
	ctx.lr = 0x826CEF20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,84
	r30.s64 = ctx.r3.s64 + 84;
	// li r29,5
	r29.s64 = 5;
loc_826CEF2C:
	// lhz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826cefd0
	if (!cr6.gt) goto loc_826CEFD0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_826CEF40:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cef60
	if (!cr6.eq) goto loc_826CEF60;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x826cef40
	if (cr6.lt) goto loc_826CEF40;
	// b 0x826cefd0
	goto loc_826CEFD0;
loc_826CEF60:
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x822b7bd0
	ctx.lr = 0x826CEF78;
	sub_822B7BD0(ctx, base);
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82608de8
	ctx.lr = 0x826CEF80;
	sub_82608DE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x826CEF88;
	sub_82130588(ctx, base);
	// lhz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826cefbc
	if (!cr6.gt) goto loc_826CEFBC;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_826CEFA0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826cefbc
	if (!cr6.eq) goto loc_826CEFBC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x826cefa0
	if (cr6.lt) goto loc_826CEFA0;
loc_826CEFBC:
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826cef60
	if (!cr6.eq) goto loc_826CEF60;
loc_826CEFD0:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// bne 0x826cef2c
	if (!cr0.eq) goto loc_826CEF2C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CEF18) {
	__imp__sub_826CEF18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CEFE4) {
	__imp__sub_826CEFE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEFE8) {
	PPC_FUNC_PROLOGUE();
	// b 0x826cecd8
	sub_826CECD8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CEFE8) {
	__imp__sub_826CEFE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CEFEC) {
	__imp__sub_826CEFEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CEFF0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cf020
	if (cr6.eq) goto loc_826CF020;
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// bl 0x826ce898
	ctx.lr = 0x826CF01C;
	sub_826CE898(ctx, base);
	// b 0x826cf030
	goto loc_826CF030;
loc_826CF020:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1624
	ctx.r3.s64 = r11.s64 + -1624;
	// bl 0x82130000
	ctx.lr = 0x826CF02C;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_826CF030:
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

PPC_WEAK_FUNC(sub_826CEFF0) {
	__imp__sub_826CEFF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF050) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// beq cr6,0x826cf0a4
	if (cr6.eq) goto loc_826CF0A4;
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// bl 0x826ce928
	ctx.lr = 0x826CF088;
	sub_826CE928(ctx, base);
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
loc_826CF0A4:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1536
	ctx.r3.s64 = r11.s64 + -1536;
	// bl 0x82130000
	ctx.lr = 0x826CF0B0;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_826CF050) {
	__imp__sub_826CF050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF0D0) {
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
	// bl 0x826ced40
	ctx.lr = 0x826CF0F4;
	sub_826CED40(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_826CF0D0) {
	__imp__sub_826CF0D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CF114) {
	__imp__sub_826CF114(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF118) {
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
	ctx.lr = 0x826CF120;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r31,7
	r11.s64 = r31.s64 + 7;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// bl 0x82237920
	ctx.lr = 0x826CF15C;
	sub_82237920(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// add r7,r31,r11
	ctx.r7.u64 = r31.u64 + r11.u64;
	// ori r6,r8,64167
	ctx.r6.u64 = ctx.r8.u64 | 64167;
	// lwz r11,-10020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addis r5,r11,1
	ctx.r5.s64 = r11.s64 + 65536;
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + r30.u64;
	// addi r5,r5,27768
	ctx.r5.s64 = ctx.r5.s64 + 27768;
	// lhz r8,90(r4)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + 90);
	// lwz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// twllei r8,0
	// mulld r11,r3,r6
	r11.s64 = ctx.r3.s64 * ctx.r6.s64;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// clrlwi r7,r11,1
	ctx.r7.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r9,r7,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r4,r7,r8
	ctx.r4.s32 = ctx.r7.s32 / ctx.r8.s32;
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// addi r3,r9,-1
	ctx.r3.s64 = ctx.r9.s64 + -1;
	// andc r9,r8,r3
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r3.u64;
	// mullw r8,r4,r8
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// twlgei r9,-1
	// subf r5,r8,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r8.s64;
	// beq cr6,0x826cf2ac
	if (cr6.eq) goto loc_826CF2AC;
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_826CF1DC:
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826cf1f8
	if (!cr6.eq) goto loc_826CF1F8;
	// lbz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826cf1f8
	if (!cr6.eq) goto loc_826CF1F8;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_826CF1F8:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x826cf24c
	if (!cr6.eq) goto loc_826CF24C;
	// lbz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826cf2c4
	if (cr6.eq) goto loc_826CF2C4;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826cf1dc
	if (!cr6.eq) goto loc_826CF1DC;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
loc_826CF224:
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// bge cr6,0x826cf290
	if (!cr6.lt) goto loc_826CF290;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cf224
	if (cr6.eq) goto loc_826CF224;
	// b 0x826cf1dc
	goto loc_826CF1DC;
loc_826CF24C:
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826cf1dc
	if (!cr6.eq) goto loc_826CF1DC;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
loc_826CF268:
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// bge cr6,0x826cf290
	if (!cr6.lt) goto loc_826CF290;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cf268
	if (cr6.eq) goto loc_826CF268;
	// b 0x826cf1dc
	goto loc_826CF1DC;
loc_826CF290:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826cf1dc
	if (!cr6.eq) goto loc_826CF1DC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826cf2ac
	if (cr6.eq) goto loc_826CF2AC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826CF2AC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1264
	ctx.r3.s64 = r11.s64 + -1264;
	// bl 0x82130000
	ctx.lr = 0x826CF2B8;
	sub_82130000(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cedd8
	ctx.lr = 0x826CF2C4;
	sub_826CEDD8(ctx, base);
loc_826CF2C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CF118) {
	__imp__sub_826CF118(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CF2CC) {
	__imp__sub_826CF2CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF2D0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x826CF2D8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826CF2F4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826cf34c
	if (!cr6.gt) goto loc_826CF34C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r27,4
	r31.s64 = r27.s64 + 4;
	// li r29,0
	r29.s64 = 0;
	// li r28,10
	r28.s64 = 10;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_826CF314:
	// addic. r11,r31,-4
	xer.ca = r31.u32 > 3;
	r11.s64 = r31.s64 + -4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826cf340
	if (cr0.eq) goto loc_826CF340;
	// stfs f31,-4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -4, temp.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// li r4,10
	ctx.r4.s64 = 10;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826cdc18
	ctx.lr = 0x826CF338;
	sub_826CDC18(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
loc_826CF340:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// bne 0x826cf314
	if (!cr0.eq) goto loc_826CF314;
loc_826CF34C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CF2D0) {
	__imp__sub_826CF2D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CF35C) {
	__imp__sub_826CF35C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF360) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x826CF368;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// beq cr6,0x826cf3e0
	if (cr6.eq) goto loc_826CF3E0;
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
	// addi r29,r30,4
	r29.s64 = r30.s64 + 4;
loc_826CF388:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// stfs f0,0(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// beq cr6,0x826cf3c8
	if (cr6.eq) goto loc_826CF3C8;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x826cf3bc
	if (cr6.eq) goto loc_826CF3BC;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cf3bc
	if (cr6.eq) goto loc_826CF3BC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826CF3BC;
	sub_82130588(ctx, base);
loc_826CF3BC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826cdd20
	ctx.lr = 0x826CF3C8;
	sub_826CDD20(ctx, base);
loc_826CF3C8:
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// bne cr6,0x826cf388
	if (!cr6.eq) goto loc_826CF388;
loc_826CF3E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CF360) {
	__imp__sub_826CF360(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF3E8) {
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
	ctx.lr = 0x826CF3F0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// add r11,r26,r25
	r11.u64 = r26.u64 + r25.u64;
	// lbz r10,145(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 145);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826cf6b4
	if (!cr6.eq) goto loc_826CF6B4;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r10,r11,-28304
	ctx.r10.s64 = r11.s64 + -28304;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826cf42c
	if (!cr6.eq) goto loc_826CF42C;
	// cmpwi cr6,r26,4
	cr6.compare<int32_t>(r26.s32, 4, xer);
	// beq cr6,0x826cf6b4
	if (cr6.eq) goto loc_826CF6B4;
loc_826CF42C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826CF43C;
	sub_822A3998(ctx, base);
	// addi r10,r26,6
	ctx.r10.s64 = r26.s64 + 6;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lhzx r27,r9,r25
	r27.u64 = PPC_LOAD_U16(ctx.r9.u32 + r25.u32);
	// bl 0x826cde30
	ctx.lr = 0x826CF458;
	sub_826CDE30(ctx, base);
	// li r19,0
	r19.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r19,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r19.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// sth r19,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r19.u16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// sth r19,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r19.u16);
	// bl 0x826ce4d0
	ctx.lr = 0x826CF478;
	sub_826CE4D0(ctx, base);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// lwz r16,80(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ble cr6,0x826cf4c8
	if (!cr6.gt) goto loc_826CF4C8;
	// rlwinm r10,r26,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r11,r19
	r11.u64 = r19.u64;
	// add r7,r10,r25
	ctx.r7.u64 = ctx.r10.u64 + r25.u64;
	// mr r9,r16
	ctx.r9.u64 = r16.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_826CF498:
	// lwz r10,44(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// beq cr6,0x826cf4b8
	if (cr6.eq) goto loc_826CF4B8;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,180(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 180);
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
loc_826CF4B8:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// bne 0x826cf498
	if (!cr0.eq) goto loc_826CF498;
loc_826CF4C8:
	// rlwinm r11,r26,3,0,28
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r28,r11,r25
	r28.u64 = r11.u64 + r25.u64;
	// add r11,r31,r10
	r11.u64 = r31.u64 + ctx.r10.u64;
	// mr r21,r19
	r21.u64 = r19.u64;
	// rlwinm r20,r11,2,0,29
	r20.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// add r11,r20,r11
	r11.u64 = r20.u64 + r11.u64;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cf664
	if (cr6.eq) goto loc_826CF664;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r24,r19
	r24.u64 = r19.u64;
	// li r18,1
	r18.s64 = 1;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// addi r23,r10,-1140
	r23.s64 = ctx.r10.s64 + -1140;
loc_826CF508:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// mr r11,r19
	r11.u64 = r19.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// lwzx r29,r10,r24
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + r24.u32);
	// ble cr6,0x826cf568
	if (!cr6.gt) goto loc_826CF568;
	// mr r10,r16
	ctx.r10.u64 = r16.u64;
loc_826CF524:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,-2
	cr6.compare<int32_t>(ctx.r9.s32, -2, xer);
	// beq cr6,0x826cf544
	if (cr6.eq) goto loc_826CF544;
	// lbz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826cf544
	if (!cr6.eq) goto loc_826CF544;
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// beq cr6,0x826cf558
	if (cr6.eq) goto loc_826CF558;
loc_826CF544:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// blt cr6,0x826cf524
	if (cr6.lt) goto loc_826CF524;
	// b 0x826cf568
	goto loc_826CF568;
loc_826CF558:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r8,r18
	ctx.r8.u64 = r18.u64;
	// add r11,r11,r16
	r11.u64 = r11.u64 + r16.u64;
	// stb r18,4(r11)
	PPC_STORE_U8(r11.u32 + 4, r18.u8);
loc_826CF568:
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cf648
	if (!cr6.eq) goto loc_826CF648;
	// mr r30,r19
	r30.u64 = r19.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x826cf640
	if (!cr6.gt) goto loc_826CF640;
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_826CF588:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x826cf5a8
	if (cr6.eq) goto loc_826CF5A8;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x826cf588
	if (cr6.lt) goto loc_826CF588;
	// b 0x826cf640
	goto loc_826CF640;
loc_826CF5A8:
	// lwz r3,-10020(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10020);
	// bl 0x826bcc58
	ctx.lr = 0x826CF5B0;
	sub_826BCC58(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826cf118
	ctx.lr = 0x826CF5C0;
	sub_826CF118(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,247
	ctx.r6.s64 = 247;
	// lwz r4,52(r17)
	ctx.r4.u64 = PPC_LOAD_U32(r17.u32 + 52);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
	// bl 0x82398780
	ctx.lr = 0x826CF5D8;
	sub_82398780(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// bl 0x823db670
	ctx.lr = 0x826CF5EC;
	sub_823DB670(ctx, base);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x8239caa0
	ctx.lr = 0x826CF5F4;
	sub_8239CAA0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823db670
	ctx.lr = 0x826CF604;
	sub_823DB670(ctx, base);
	// lwz r11,76(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 76);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// bl 0x823db670
	ctx.lr = 0x826CF61C;
	sub_823DB670(ctx, base);
	// stw r29,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r29.u32);
	// stw r26,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r26.u32);
	// mulli r11,r30,84
	r11.s64 = r30.s64 * 84;
	// lwz r10,44(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// lbz r6,80(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 80);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x826d4488
	ctx.lr = 0x826CF640;
	sub_826D4488(ctx, base);
loc_826CF640:
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// beq cr6,0x826cf664
	if (cr6.eq) goto loc_826CF664;
loc_826CF648:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// add r11,r20,r11
	r11.u64 = r20.u64 + r11.u64;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpw cr6,r21,r10
	cr6.compare<int32_t>(r21.s32, ctx.r10.s32, xer);
	// blt cr6,0x826cf508
	if (cr6.lt) goto loc_826CF508;
loc_826CF664:
	// lhz r11,84(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// rotlwi r10,r11,3
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 3);
	// add r9,r10,r16
	ctx.r9.u64 = ctx.r10.u64 + r16.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// cmplw cr6,r9,r9
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r9.u32, xer);
	// beq cr6,0x826cf6a0
	if (cr6.eq) goto loc_826CF6A0;
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
loc_826CF680:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x826cf680
	if (!cr6.eq) goto loc_826CF680;
loc_826CF6A0:
	// lhz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cf6b4
	if (cr6.eq) goto loc_826CF6B4;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x82130588
	ctx.lr = 0x826CF6B4;
	sub_82130588(ctx, base);
loc_826CF6B4:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_826CF3E8) {
	__imp__sub_826CF3E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF6BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CF6BC) {
	__imp__sub_826CF6BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF6C0) {
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
	ctx.lr = 0x826CF6C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826cf790
	if (cr6.eq) goto loc_826CF790;
	// lwz r30,184(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	// li r31,0
	r31.s64 = 0;
	// addi r11,r30,6
	r11.s64 = r30.s64 + 6;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826cf72c
	if (!cr6.gt) goto loc_826CF72C;
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r28,r11,r29
	r28.u64 = r11.u64 + r29.u64;
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
loc_826CF708:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cf71c
	if (cr6.eq) goto loc_826CF71C;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x826cf73c
	if (cr6.eq) goto loc_826CF73C;
loc_826CF71C:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,84
	ctx.r10.s64 = ctx.r10.s64 + 84;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x826cf708
	if (cr6.lt) goto loc_826CF708;
loc_826CF72C:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x826d0328
	ctx.lr = 0x826CF734;
	sub_826D0328(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826CF73C:
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826ce530
	ctx.lr = 0x826CF750;
	sub_826CE530(ctx, base);
	// lwz r10,44(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// mulli r11,r31,84
	r11.s64 = r31.s64 * 84;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x826d4400
	ctx.lr = 0x826CF760;
	sub_826D4400(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cf79c
	if (cr6.eq) goto loc_826CF79C;
	// add r11,r30,r29
	r11.u64 = r30.u64 + r29.u64;
	// lbz r10,145(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 145);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826cf79c
	if (!cr6.eq) goto loc_826CF79C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826cf3e8
	ctx.lr = 0x826CF788;
	sub_826CF3E8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826CF790:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1096
	ctx.r3.s64 = r11.s64 + -1096;
	// bl 0x82130000
	ctx.lr = 0x826CF79C;
	sub_82130000(ctx, base);
loc_826CF79C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CF6C0) {
	__imp__sub_826CF6C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF7A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CF7A4) {
	__imp__sub_826CF7A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF7A8) {
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
	ctx.lr = 0x826CF7B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826cf834
	if (!cr6.gt) goto loc_826CF834;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_826CF7C8:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r7,r31,-4
	ctx.r7.s64 = r31.s64 + -4;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826cf800
	if (cr6.eq) goto loc_826CF800;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826CF7EC:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826cf7ec
	if (!cr6.eq) goto loc_826CF7EC;
loc_826CF800:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// lhz r5,10(r7)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + 10);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826cf828
	if (cr6.eq) goto loc_826CF828;
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x826CF828;
	sub_82130588(ctx, base);
loc_826CF828:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// bne 0x826cf7c8
	if (!cr0.eq) goto loc_826CF7C8;
loc_826CF834:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826CF83C;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CF7A8) {
	__imp__sub_826CF7A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CF844) {
	__imp__sub_826CF844(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF848) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x826cf898
	if (cr6.eq) goto loc_826CF898;
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// bl 0x826cf118
	ctx.lr = 0x826CF87C;
	sub_826CF118(ctx, base);
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
loc_826CF898:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1536
	ctx.r3.s64 = r11.s64 + -1536;
	// bl 0x82130000
	ctx.lr = 0x826CF8A4;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_826CF848) {
	__imp__sub_826CF848(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CF8C4) {
	__imp__sub_826CF8C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF8C8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x826CF8D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826cf994
	if (!cr6.eq) goto loc_826CF994;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x826cf2d0
	ctx.lr = 0x826CF8F8;
	sub_826CF2D0(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cf980
	if (cr6.eq) goto loc_826CF980;
	// li r28,0
	r28.s64 = 0;
loc_826CF90C:
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// add r9,r11,r27
	ctx.r9.u64 = r11.u64 + r27.u64;
	// addi r29,r10,4
	r29.s64 = ctx.r10.s64 + 4;
	// addi r30,r9,4
	r30.s64 = ctx.r9.s64 + 4;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// stfsx f0,r11,r27
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + r27.u32, temp.u32);
	// beq cr6,0x826cf96c
	if (cr6.eq) goto loc_826CF96C;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x826cf960
	if (cr6.eq) goto loc_826CF960;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cf960
	if (cr6.eq) goto loc_826CF960;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826CF960;
	sub_82130588(ctx, base);
loc_826CF960:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cdd20
	ctx.lr = 0x826CF96C;
	sub_826CDD20(ctx, base);
loc_826CF96C:
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r28,r11,16
	r28.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// blt cr6,0x826cf90c
	if (cr6.lt) goto loc_826CF90C;
loc_826CF980:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x826cf7a8
	ctx.lr = 0x826CF990;
	sub_826CF7A8(ctx, base);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
loc_826CF994:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826CF8C8) {
	__imp__sub_826CF8C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CF9BC) {
	__imp__sub_826CF9BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CF9C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-752
	ctx.r9.s64 = ctx.r10.s64 + -752;
	// addi r10,r3,145
	ctx.r10.s64 = ctx.r3.s64 + 145;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r9,1
	ctx.r9.s64 = 1;
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
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// sth r11,40(r3)
	PPC_STORE_U16(ctx.r3.u32 + 40, r11.u16);
	// sth r11,42(r3)
	PPC_STORE_U16(ctx.r3.u32 + 42, r11.u16);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// sth r11,48(r3)
	PPC_STORE_U16(ctx.r3.u32 + 48, r11.u16);
	// sth r11,50(r3)
	PPC_STORE_U16(ctx.r3.u32 + 50, r11.u16);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// sth r11,56(r3)
	PPC_STORE_U16(ctx.r3.u32 + 56, r11.u16);
	// sth r11,58(r3)
	PPC_STORE_U16(ctx.r3.u32 + 58, r11.u16);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// sth r11,64(r3)
	PPC_STORE_U16(ctx.r3.u32 + 64, r11.u16);
	// sth r11,66(r3)
	PPC_STORE_U16(ctx.r3.u32 + 66, r11.u16);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// sth r11,72(r3)
	PPC_STORE_U16(ctx.r3.u32 + 72, r11.u16);
	// sth r11,74(r3)
	PPC_STORE_U16(ctx.r3.u32 + 74, r11.u16);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// sth r11,80(r3)
	PPC_STORE_U16(ctx.r3.u32 + 80, r11.u16);
	// sth r11,82(r3)
	PPC_STORE_U16(ctx.r3.u32 + 82, r11.u16);
	// sth r11,90(r3)
	PPC_STORE_U16(ctx.r3.u32 + 90, r11.u16);
	// sth r11,88(r3)
	PPC_STORE_U16(ctx.r3.u32 + 88, r11.u16);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stb r11,95(r3)
	PPC_STORE_U8(ctx.r3.u32 + 95, r11.u8);
	// sth r11,102(r3)
	PPC_STORE_U16(ctx.r3.u32 + 102, r11.u16);
	// sth r11,100(r3)
	PPC_STORE_U16(ctx.r3.u32 + 100, r11.u16);
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r11.u32);
	// stb r11,107(r3)
	PPC_STORE_U8(ctx.r3.u32 + 107, r11.u8);
	// sth r11,114(r3)
	PPC_STORE_U16(ctx.r3.u32 + 114, r11.u16);
	// sth r11,112(r3)
	PPC_STORE_U16(ctx.r3.u32 + 112, r11.u16);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// stb r11,119(r3)
	PPC_STORE_U8(ctx.r3.u32 + 119, r11.u8);
	// sth r11,126(r3)
	PPC_STORE_U16(ctx.r3.u32 + 126, r11.u16);
	// sth r11,124(r3)
	PPC_STORE_U16(ctx.r3.u32 + 124, r11.u16);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stb r11,131(r3)
	PPC_STORE_U8(ctx.r3.u32 + 131, r11.u8);
	// sth r11,138(r3)
	PPC_STORE_U16(ctx.r3.u32 + 138, r11.u16);
	// sth r11,136(r3)
	PPC_STORE_U16(ctx.r3.u32 + 136, r11.u16);
	// stw r11,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, r11.u32);
	// stb r11,143(r3)
	PPC_STORE_U8(ctx.r3.u32 + 143, r11.u8);
	// stb r11,144(r3)
	PPC_STORE_U8(ctx.r3.u32 + 144, r11.u8);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// li r10,7
	ctx.r10.s64 = 7;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_826CFAB0:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x826cfab0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826CFAB0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CF9C0) {
	__imp__sub_826CF9C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CFAC0) {
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
	ctx.lr = 0x826CFAC8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r31,r25,144
	r31.s64 = r25.s64 + 144;
	// addi r10,r11,-752
	ctx.r10.s64 = r11.s64 + -752;
	// li r30,4
	r30.s64 = 4;
	// stw r10,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r10.u32);
loc_826CFAE4:
	// addi r31,r31,-12
	r31.s64 = r31.s64 + -12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82608de8
	ctx.lr = 0x826CFAF0;
	sub_82608DE8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x826cfae4
	if (!cr0.lt) goto loc_826CFAE4;
	// addi r27,r25,40
	r27.s64 = r25.s64 + 40;
	// li r26,4
	r26.s64 = 4;
	// addi r28,r27,44
	r28.s64 = r27.s64 + 44;
loc_826CFB04:
	// addi r28,r28,-8
	r28.s64 = r28.s64 + -8;
	// lhz r30,6(r28)
	r30.u64 = PPC_LOAD_U16(r28.u32 + 6);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cfb50
	if (cr6.eq) goto loc_826CFB50;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826cfb48
	if (!cr6.gt) goto loc_826CFB48;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_826CFB24:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CFB3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// bne 0x826cfb24
	if (!cr0.eq) goto loc_826CFB24;
loc_826CFB48:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826CFB50;
	sub_82130588(ctx, base);
loc_826CFB50:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// bge 0x826cfb04
	if (!cr0.lt) goto loc_826CFB04;
	// addi r31,r27,4
	r31.s64 = r27.s64 + 4;
	// li r30,4
	r30.s64 = 4;
loc_826CFB60:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826cfb7c
	if (cr6.eq) goto loc_826CFB7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x826cf7a8
	ctx.lr = 0x826CFB7C;
	sub_826CF7A8(ctx, base);
loc_826CFB7C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x826cfb60
	if (!cr0.lt) goto loc_826CFB60;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821d2028
	ctx.lr = 0x826CFB8C;
	sub_821D2028(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_826CFAC0) {
	__imp__sub_826CFAC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CFB94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CFB94) {
	__imp__sub_826CFB94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CFB98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x826CFBA0;
	// stwu r1,-976(r1)
	ea = -976 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r18,r11,30576
	r18.s64 = r11.s64 + 30576;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// addi r4,r10,-16884
	ctx.r4.s64 = ctx.r10.s64 + -16884;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821ca540
	ctx.lr = 0x826CFBC0;
	sub_821CA540(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r31,r11,-32764
	r31.s64 = r11.s64 + -32764;
	// addi r30,r10,-672
	r30.s64 = ctx.r10.s64 + -672;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x826CFBE8;
	sub_821CA6A8(ctx, base);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// cmplwi cr6,r17,0
	cr6.compare<uint32_t>(r17.u32, 0, xer);
	// bne cr6,0x826cfc20
	if (!cr6.eq) goto loc_826CFC20;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826CFBFC;
	sub_821C9A90(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,-1728
	ctx.r4.s64 = r11.s64 + -1728;
	// addi r3,r10,-716
	ctx.r3.s64 = ctx.r10.s64 + -716;
	// bl 0x82130000
	ctx.lr = 0x826CFC18;
	sub_82130000(ctx, base);
	// addi r1,r1,976
	ctx.r1.s64 = ctx.r1.s64 + 976;
	// b 0x823d9214
	return;
loc_826CFC20:
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d1cd0
	ctx.lr = 0x826CFC28;
	sub_821D1CD0(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// addi r4,r11,-732
	ctx.r4.s64 = r11.s64 + -732;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cf7b8
	ctx.lr = 0x826CFC3C;
	sub_821CF7B8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r16,r11,-7984
	r16.s64 = r11.s64 + -7984;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// bl 0x821cff40
	ctx.lr = 0x826CFC54;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826cff30
	if (cr6.eq) goto loc_826CFF30;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r31,-32256
	r31.s64 = -2113929216;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r26,r3,-3120
	r26.s64 = ctx.r3.s64 + -3120;
	// addi r29,r31,10380
	r29.s64 = r31.s64 + 10380;
	// addi r23,r4,-8388
	r23.s64 = ctx.r4.s64 + -8388;
	// addi r24,r5,-16112
	r24.s64 = ctx.r5.s64 + -16112;
	// addi r28,r6,-29628
	r28.s64 = ctx.r6.s64 + -29628;
	// addi r22,r7,-740
	r22.s64 = ctx.r7.s64 + -740;
	// addi r21,r8,-25240
	r21.s64 = ctx.r8.s64 + -25240;
	// addi r25,r9,-748
	r25.s64 = ctx.r9.s64 + -748;
	// addi r19,r10,9848
	r19.s64 = ctx.r10.s64 + 9848;
	// addi r30,r11,-29624
	r30.s64 = r11.s64 + -29624;
loc_826CFCB0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0898
	ctx.lr = 0x826CFCBC;
	sub_821D0898(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfe20
	ctx.lr = 0x826CFCC8;
	sub_821CFE20(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfaa8
	ctx.lr = 0x826CFCD8;
	sub_821CFAA8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238e818
	ctx.lr = 0x826CFCE0;
	sub_8238E818(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x826cea20
	ctx.lr = 0x826CFCF0;
	sub_826CEA20(ctx, base);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x826d4360
	ctx.lr = 0x826CFCF8;
	sub_826D4360(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFD08;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cfdc4
	if (cr6.eq) goto loc_826CFDC4;
	// rlwinm r11,r27,3,0,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// addi r31,r11,44
	r31.s64 = r11.s64 + 44;
loc_826CFD20:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFD30;
	sub_821CFF40(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0898
	ctx.lr = 0x826CFD3C;
	sub_821D0898(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfe20
	ctx.lr = 0x826CFD48;
	sub_821CFE20(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfaa8
	ctx.lr = 0x826CFD58;
	sub_821CFAA8(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x823db670
	ctx.lr = 0x826CFD68;
	sub_823DB670(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfe20
	ctx.lr = 0x826CFD74;
	sub_821CFE20(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0490
	ctx.lr = 0x826CFD80;
	sub_821D0490(ctx, base);
	// stw r3,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,176
	r15.s64 = ctx.r1.s64 + 176;
	// bl 0x826ce400
	ctx.lr = 0x826CFD94;
	sub_826CE400(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// bl 0x826d4398
	ctx.lr = 0x826CFD9C;
	sub_826D4398(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0898
	ctx.lr = 0x826CFDA8;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFDB8;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cfd20
	if (!cr6.eq) goto loc_826CFD20;
loc_826CFDC4:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFDD4;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cff00
	if (cr6.eq) goto loc_826CFF00;
	// rlwinm r11,r27,3,0,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// addi r27,r11,4
	r27.s64 = r11.s64 + 4;
loc_826CFDEC:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFDFC;
	sub_821CFF40(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0898
	ctx.lr = 0x826CFE08;
	sub_821D0898(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826cf8c8
	ctx.lr = 0x826CFE14;
	sub_826CF8C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfe20
	ctx.lr = 0x826CFE24;
	sub_821CFE20(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0528
	ctx.lr = 0x826CFE30;
	sub_821D0528(ctx, base);
	// stfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFE44;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cfed8
	if (cr6.eq) goto loc_826CFED8;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
loc_826CFE54:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFE64;
	sub_821CFF40(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0898
	ctx.lr = 0x826CFE70;
	sub_821D0898(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfe20
	ctx.lr = 0x826CFE7C;
	sub_821CFE20(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfaa8
	ctx.lr = 0x826CFE8C;
	sub_821CFAA8(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8238e8c0
	ctx.lr = 0x826CFE94;
	sub_8238E8C0(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// bl 0x821d0898
	ctx.lr = 0x826CFEBC;
	sub_821D0898(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFECC;
	sub_821CFF40(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826cfe54
	if (!cr6.eq) goto loc_826CFE54;
loc_826CFED8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0898
	ctx.lr = 0x826CFEE4;
	sub_821D0898(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFEF4;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cfdec
	if (!cr6.eq) goto loc_826CFDEC;
loc_826CFF00:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d0898
	ctx.lr = 0x826CFF0C;
	sub_821D0898(ctx, base);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x826d4388
	ctx.lr = 0x826CFF14;
	sub_826D4388(ctx, base);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cff40
	ctx.lr = 0x826CFF24;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cfcb0
	if (!cr6.eq) goto loc_826CFCB0;
loc_826CFF30:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x821be610
	ctx.lr = 0x826CFF38;
	sub_821BE610(ctx, base);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826CFF40;
	sub_821C9A90(ctx, base);
	// addi r1,r1,976
	ctx.r1.s64 = ctx.r1.s64 + 976;
	// b 0x823d9214
	return;
}

PPC_WEAK_FUNC(sub_826CFB98) {
	__imp__sub_826CFB98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CFF48) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826CFF50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r28,5
	r28.s64 = 5;
	// addi r31,r26,4
	r31.s64 = r26.s64 + 4;
	// li r27,12
	r27.s64 = 12;
loc_826CFF64:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826cf360
	ctx.lr = 0x826CFF90;
	sub_826CF360(ctx, base);
	// subf r10,r29,r30
	ctx.r10.s64 = r30.s64 - r29.s64;
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// divw r9,r10,r27
	ctx.r9.s32 = ctx.r10.s32 / r27.s32;
	// subf r7,r9,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r9.s64;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x826cff64
	if (!cr0.eq) goto loc_826CFF64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826cef18
	ctx.lr = 0x826CFFB8;
	sub_826CEF18(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,144(r26)
	PPC_STORE_U8(r26.u32 + 144, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826CFF48) {
	__imp__sub_826CFF48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CFFC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r11,-10020(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r9,r6,1
	ctx.r9.u64 = ctx.r6.u64 ^ 1;
	// beq cr6,0x826d0020
	if (cr6.eq) goto loc_826D0020;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// lbz r8,8741(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 8741);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r8,0
	ctx.r8.s64 = 0;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// stb r8,8741(r11)
	PPC_STORE_U8(r11.u32 + 8741, ctx.r8.u8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,-10020(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// b 0x826cf3e8
	sub_826CF3E8(ctx, base);
	return;
loc_826D0020:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-1016
	ctx.r3.s64 = r11.s64 + -1016;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826CFFC8) {
	__imp__sub_826CFFC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D002C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D002C) {
	__imp__sub_826D002C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0030) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,-10020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 ^ 1;
	// beq cr6,0x826d0094
	if (cr6.eq) goto loc_826D0094;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826d0088
	if (cr6.eq) goto loc_826D0088;
	// clrlwi r5,r10,24
	ctx.r5.u64 = ctx.r10.u32 & 0xFF;
	// addi r3,r11,8596
	ctx.r3.s64 = r11.s64 + 8596;
	// bl 0x826cf6c0
	ctx.lr = 0x826D0078;
	sub_826CF6C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D0088:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-840
	ctx.r3.s64 = r11.s64 + -840;
	// bl 0x82130000
	ctx.lr = 0x826D0094;
	sub_82130000(ctx, base);
loc_826D0094:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-928
	ctx.r3.s64 = r11.s64 + -928;
	// bl 0x82130000
	ctx.lr = 0x826D00A0;
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

PPC_WEAK_FUNC(sub_826D0030) {
	__imp__sub_826D0030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D00B0) {
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
	ctx.lr = 0x826D00B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0104
	if (cr6.eq) goto loc_826D0104;
	// addi r30,r11,8596
	r30.s64 = r11.s64 + 8596;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r30,145
	r29.s64 = r30.s64 + 145;
loc_826D00D8:
	// lbzx r11,r29,r31
	r11.u64 = PPC_LOAD_U8(r29.u32 + r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d00f0
	if (!cr6.eq) goto loc_826D00F0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cf3e8
	ctx.lr = 0x826D00F0;
	sub_826CF3E8(ctx, base);
loc_826D00F0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,5
	cr6.compare<int32_t>(r31.s32, 5, xer);
	// blt cr6,0x826d00d8
	if (cr6.lt) goto loc_826D00D8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826D0104:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-656
	ctx.r3.s64 = r11.s64 + -656;
	// bl 0x82130000
	ctx.lr = 0x826D0110;
	sub_82130000(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D00B0) {
	__imp__sub_826D00B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0118) {
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
	// bl 0x826cfac0
	ctx.lr = 0x826D0138;
	sub_826CFAC0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0150
	if (cr6.eq) goto loc_826D0150;
	// bl 0x82130588
	ctx.lr = 0x826D014C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D0150:
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

PPC_WEAK_FUNC(sub_826D0118) {
	__imp__sub_826D0118(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0168) {
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
	// bl 0x826cfb98
	ctx.lr = 0x826D0180;
	sub_826CFB98(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,144(r31)
	PPC_STORE_U8(r31.u32 + 144, r11.u8);
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

PPC_WEAK_FUNC(sub_826D0168) {
	__imp__sub_826D0168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D019C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D019C) {
	__imp__sub_826D019C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D01A0) {
	PPC_FUNC_PROLOGUE();
	// b 0x826d00b0
	sub_826D00B0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D01A0) {
	__imp__sub_826D01A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D01A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D01A4) {
	__imp__sub_826D01A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D01A8) {
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
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-6728
	ctx.r4.s64 = r11.s64 + -6728;
	// addi r3,r10,-172
	ctx.r3.s64 = ctx.r10.s64 + -172;
	// bl 0x82554798
	ctx.lr = 0x826D01C8;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-56
	ctx.r4.s64 = ctx.r9.s64 + -56;
	// addi r3,r8,-200
	ctx.r3.s64 = ctx.r8.s64 + -200;
	// bl 0x82554798
	ctx.lr = 0x826D01DC;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-5040
	ctx.r4.s64 = ctx.r7.s64 + -5040;
	// addi r3,r6,-224
	ctx.r3.s64 = ctx.r6.s64 + -224;
	// bl 0x82554798
	ctx.lr = 0x826D01F0;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-4120
	ctx.r4.s64 = ctx.r5.s64 + -4120;
	// addi r3,r3,-256
	ctx.r3.s64 = ctx.r3.s64 + -256;
	// bl 0x82554798
	ctx.lr = 0x826D0204;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-4112
	ctx.r4.s64 = r11.s64 + -4112;
	// addi r3,r10,-288
	ctx.r3.s64 = ctx.r10.s64 + -288;
	// bl 0x82554798
	ctx.lr = 0x826D0218;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,416
	ctx.r4.s64 = ctx.r9.s64 + 416;
	// addi r3,r8,-324
	ctx.r3.s64 = ctx.r8.s64 + -324;
	// bl 0x82554798
	ctx.lr = 0x826D022C;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-4992
	ctx.r4.s64 = ctx.r7.s64 + -4992;
	// addi r3,r6,-352
	ctx.r3.s64 = ctx.r6.s64 + -352;
	// bl 0x82554798
	ctx.lr = 0x826D0240;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,48
	ctx.r4.s64 = ctx.r5.s64 + 48;
	// addi r3,r3,-384
	ctx.r3.s64 = ctx.r3.s64 + -384;
	// bl 0x82554798
	ctx.lr = 0x826D0254;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-1976
	ctx.r4.s64 = r11.s64 + -1976;
	// addi r3,r10,-428
	ctx.r3.s64 = ctx.r10.s64 + -428;
	// bl 0x82554798
	ctx.lr = 0x826D0268;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-4016
	ctx.r4.s64 = ctx.r9.s64 + -4016;
	// addi r3,r8,-468
	ctx.r3.s64 = ctx.r8.s64 + -468;
	// bl 0x82554798
	ctx.lr = 0x826D027C;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-4976
	ctx.r4.s64 = ctx.r7.s64 + -4976;
	// addi r3,r6,-504
	ctx.r3.s64 = ctx.r6.s64 + -504;
	// bl 0x82554798
	ctx.lr = 0x826D0290;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-3888
	ctx.r4.s64 = ctx.r5.s64 + -3888;
	// addi r3,r3,-536
	ctx.r3.s64 = ctx.r3.s64 + -536;
	// bl 0x82554798
	ctx.lr = 0x826D02A4;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-6664
	ctx.r4.s64 = r11.s64 + -6664;
	// addi r3,r10,-568
	ctx.r3.s64 = ctx.r10.s64 + -568;
	// bl 0x82554798
	ctx.lr = 0x826D02B8;
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

PPC_WEAK_FUNC(sub_826D01A8) {
	__imp__sub_826D01A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D02C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r10,31
	ctx.r10.s64 = 31;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// li r10,30
	ctx.r10.s64 = 30;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_826D02E0:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x826d02e0
	if (!cr0.lt) goto loc_826D02E0;
	// li r11,0
	r11.s64 = 0;
	// stfs f0,380(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 380, temp.u32);
	// stfs f0,384(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 384, temp.u32);
	// stw r11,376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 376, r11.u32);
	// stw r11,388(r3)
	PPC_STORE_U32(ctx.r3.u32 + 388, r11.u32);
	// stw r11,392(r3)
	PPC_STORE_U32(ctx.r3.u32 + 392, r11.u32);
	// stw r11,396(r3)
	PPC_STORE_U32(ctx.r3.u32 + 396, r11.u32);
	// stw r11,400(r3)
	PPC_STORE_U32(ctx.r3.u32 + 400, r11.u32);
	// stw r11,404(r3)
	PPC_STORE_U32(ctx.r3.u32 + 404, r11.u32);
	// stw r11,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D02C8) {
	__imp__sub_826D02C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0324) {
	__imp__sub_826D0324(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0328) {
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
	// li r11,-1
	r11.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// li r10,-2
	ctx.r10.s64 = -2;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// stw r30,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
	// stw r10,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r10.u32);
	// stw r9,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r9.u32);
	// beq cr6,0x826d0394
	if (cr6.eq) goto loc_826D0394;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82727ab0
	ctx.lr = 0x826D037C;
	sub_82727AB0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x82727a58
	ctx.lr = 0x826D038C;
	sub_82727A58(ctx, base);
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x82130000
	ctx.lr = 0x826D0394;
	sub_82130000(ctx, base);
loc_826D0394:
	// li r11,1
	r11.s64 = 1;
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// stb r11,196(r31)
	PPC_STORE_U8(r31.u32 + 196, r11.u8);
	// stb r30,36(r31)
	PPC_STORE_U8(r31.u32 + 36, r30.u8);
	// stb r30,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r30.u8);
	// stw r30,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r30.u32);
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

PPC_WEAK_FUNC(sub_826D0328) {
	__imp__sub_826D0328(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D03C8) {
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
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0400
	if (cr6.eq) goto loc_826D0400;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x826ce868
	ctx.lr = 0x826D03F8;
	sub_826CE868(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
loc_826D0400:
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

PPC_WEAK_FUNC(sub_826D03C8) {
	__imp__sub_826D03C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0414) {
	__imp__sub_826D0414(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0418) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,172
	ctx.r9.s64 = r11.s64 + 172;
	// stw r10,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x826d0328
	ctx.lr = 0x826D0444;
	sub_826D0328(ctx, base);
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

PPC_WEAK_FUNC(sub_826D0418) {
	__imp__sub_826D0418(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D045C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D045C) {
	__imp__sub_826D045C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0460) {
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
	// addi r9,r11,172
	ctx.r9.s64 = r11.s64 + 172;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d04a4
	if (cr6.eq) goto loc_826D04A4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x826ce868
	ctx.lr = 0x826D049C;
	sub_826CE868(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
loc_826D04A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x826D04AC;
	sub_821D2028(ctx, base);
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

PPC_WEAK_FUNC(sub_826D0460) {
	__imp__sub_826D0460(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D04C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826D04C8;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// bl 0x826ce868
	ctx.lr = 0x826D04E8;
	sub_826CE868(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826d02c8
	ctx.lr = 0x826D04F0;
	sub_826D02C8(ctx, base);
	// stw r31,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, r31.u32);
	// stb r29,196(r31)
	PPC_STORE_U8(r31.u32 + 196, r29.u8);
	// li r8,300
	ctx.r8.s64 = 300;
	// li r7,412
	ctx.r7.s64 = 412;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82727908
	ctx.lr = 0x826D0514;
	sub_82727908(ctx, base);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D04C0) {
	__imp__sub_826D04C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0520) {
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
	// addi r9,r11,172
	ctx.r9.s64 = r11.s64 + 172;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d056c
	if (cr6.eq) goto loc_826D056C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x826ce868
	ctx.lr = 0x826D0564;
	sub_826CE868(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
loc_826D056C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x826D0574;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d058c
	if (cr6.eq) goto loc_826D058C;
	// bl 0x82130588
	ctx.lr = 0x826D0588;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D058C:
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

PPC_WEAK_FUNC(sub_826D0520) {
	__imp__sub_826D0520(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D05A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D05A4) {
	__imp__sub_826D05A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D05A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d05c8
	if (cr6.eq) goto loc_826D05C8;
	// lwz r11,188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826D05C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D05A8) {
	__imp__sub_826D05A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D05D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D05D4) {
	__imp__sub_826D05D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D05D8) {
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
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,172(r10)
	PPC_STORE_U32(ctx.r10.u32 + 172, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D05D8) {
	__imp__sub_826D05D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D05F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D05F4) {
	__imp__sub_826D05F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D05F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0618
	if (cr6.eq) goto loc_826D0618;
	// lwz r11,172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826D0618:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D05F8) {
	__imp__sub_826D05F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0624) {
	__imp__sub_826D0624(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0628) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0668
	if (cr6.eq) goto loc_826D0668;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,27785
	ctx.r8.u64 = ctx.r9.u64 | 27785;
	// lwz r10,-10020(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826d0668
	if (!cr6.eq) goto loc_826D0668;
	// lbz r11,196(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 196);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_826D0668:
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

PPC_WEAK_FUNC(sub_826D0628) {
	__imp__sub_826D0628(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D067C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D067C) {
	__imp__sub_826D067C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0680) {
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
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r7,196(r10)
	PPC_STORE_U8(ctx.r10.u32 + 196, ctx.r7.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0680) {
	__imp__sub_826D0680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D06A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne cr6,0x826d06c4
	if (!cr6.eq) goto loc_826D06C4;
	// li r11,0
	r11.s64 = 0;
loc_826D06C4:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D06A8) {
	__imp__sub_826D06A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D06CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D06CC) {
	__imp__sub_826D06CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D06D0) {
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
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D06D0) {
	__imp__sub_826D06D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D06EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D06EC) {
	__imp__sub_826D06EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D06F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0710
	if (cr6.eq) goto loc_826D0710;
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826D0710:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D06F0) {
	__imp__sub_826D06F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D071C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D071C) {
	__imp__sub_826D071C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0720) {
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
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0720) {
	__imp__sub_826D0720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D073C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D073C) {
	__imp__sub_826D073C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0740) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0760
	if (cr6.eq) goto loc_826D0760;
	// lwz r11,180(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826D0760:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0740) {
	__imp__sub_826D0740(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D076C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D076C) {
	__imp__sub_826D076C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0770) {
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
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,164(r10)
	PPC_STORE_U32(ctx.r10.u32 + 164, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0770) {
	__imp__sub_826D0770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D078C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D078C) {
	__imp__sub_826D078C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0790) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d07b0
	if (cr6.eq) goto loc_826D07B0;
	// lwz r11,164(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826D07B0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0790) {
	__imp__sub_826D0790(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D07BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D07BC) {
	__imp__sub_826D07BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D07C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,36
	r11.s64 = r11.s64 + 36;
	// bne cr6,0x826d07dc
	if (!cr6.eq) goto loc_826D07DC;
	// li r11,0
	r11.s64 = 0;
loc_826D07DC:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D07C0) {
	__imp__sub_826D07C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D07E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D07E4) {
	__imp__sub_826D07E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D07E8) {
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
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D07E8) {
	__imp__sub_826D07E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0804) {
	__imp__sub_826D0804(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0808) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0828
	if (cr6.eq) goto loc_826D0828;
	// lwz r11,168(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826D0828:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0808) {
	__imp__sub_826D0808(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0834) {
	__imp__sub_826D0834(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d0858
	if (cr6.eq) goto loc_826D0858;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r11,100
	r11.s64 = r11.s64 + 100;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826D0858:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r10,-1140
	ctx.r9.s64 = ctx.r10.s64 + -1140;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0838) {
	__imp__sub_826D0838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D086C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D086C) {
	__imp__sub_826D086C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x826d0328
	sub_826D0328(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D0870) {
	__imp__sub_826D0870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0884) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0884) {
	__imp__sub_826D0884(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0888) {
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
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0888) {
	__imp__sub_826D0888(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D08A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D08A4) {
	__imp__sub_826D08A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D08A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d08c8
	if (cr6.eq) goto loc_826D08C8;
	// lwz r11,184(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826D08C8:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D08A8) {
	__imp__sub_826D08A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D08D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D08D4) {
	__imp__sub_826D08D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D08D8) {
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
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d0918
	if (cr6.eq) goto loc_826D0918;
	// bl 0x826c5850
	ctx.lr = 0x826D0908;
	sub_826C5850(ctx, base);
	// stw r3,188(r30)
	PPC_STORE_U32(r30.u32 + 188, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// b 0x826d0924
	goto loc_826D0924;
loc_826D0918:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_826D0924:
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

PPC_WEAK_FUNC(sub_826D08D8) {
	__imp__sub_826D08D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D093C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D093C) {
	__imp__sub_826D093C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0940) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D0940) {
	__imp__sub_826D0940(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0960) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0960) {
	__imp__sub_826D0960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0964) {
	__imp__sub_826D0964(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0968) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r10,36
	ctx.r3.s64 = ctx.r10.s64 + 36;
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D0968) {
	__imp__sub_826D0968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0988) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0988) {
	__imp__sub_826D0988(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D098C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D098C) {
	__imp__sub_826D098C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0990) {
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
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,2264
	ctx.r4.s64 = r11.s64 + 2264;
	// addi r3,r10,632
	ctx.r3.s64 = ctx.r10.s64 + 632;
	// bl 0x82554798
	ctx.lr = 0x826D09B0;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,1448
	ctx.r4.s64 = ctx.r9.s64 + 1448;
	// addi r3,r8,608
	ctx.r3.s64 = ctx.r8.s64 + 608;
	// bl 0x82554798
	ctx.lr = 0x826D09C4;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,1496
	ctx.r4.s64 = ctx.r7.s64 + 1496;
	// addi r3,r6,588
	ctx.r3.s64 = ctx.r6.s64 + 588;
	// bl 0x82554798
	ctx.lr = 0x826D09D8;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,1528
	ctx.r4.s64 = ctx.r5.s64 + 1528;
	// addi r3,r3,568
	ctx.r3.s64 = ctx.r3.s64 + 568;
	// bl 0x82554798
	ctx.lr = 0x826D09EC;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,1576
	ctx.r4.s64 = r11.s64 + 1576;
	// addi r3,r10,548
	ctx.r3.s64 = ctx.r10.s64 + 548;
	// bl 0x82554798
	ctx.lr = 0x826D0A00;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,1664
	ctx.r4.s64 = ctx.r9.s64 + 1664;
	// addi r3,r8,532
	ctx.r3.s64 = ctx.r8.s64 + 532;
	// bl 0x82554798
	ctx.lr = 0x826D0A14;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,2368
	ctx.r4.s64 = ctx.r7.s64 + 2368;
	// addi r3,r6,512
	ctx.r3.s64 = ctx.r6.s64 + 512;
	// bl 0x82554798
	ctx.lr = 0x826D0A28;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,1704
	ctx.r4.s64 = ctx.r5.s64 + 1704;
	// addi r3,r3,492
	ctx.r3.s64 = ctx.r3.s64 + 492;
	// bl 0x82554798
	ctx.lr = 0x826D0A3C;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,1744
	ctx.r4.s64 = r11.s64 + 1744;
	// addi r3,r10,472
	ctx.r3.s64 = ctx.r10.s64 + 472;
	// bl 0x82554798
	ctx.lr = 0x826D0A50;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,1776
	ctx.r4.s64 = ctx.r9.s64 + 1776;
	// addi r3,r8,452
	ctx.r3.s64 = ctx.r8.s64 + 452;
	// bl 0x82554798
	ctx.lr = 0x826D0A64;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,1824
	ctx.r4.s64 = ctx.r7.s64 + 1824;
	// addi r3,r6,428
	ctx.r3.s64 = ctx.r6.s64 + 428;
	// bl 0x82554798
	ctx.lr = 0x826D0A78;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,1856
	ctx.r4.s64 = ctx.r5.s64 + 1856;
	// addi r3,r3,404
	ctx.r3.s64 = ctx.r3.s64 + 404;
	// bl 0x82554798
	ctx.lr = 0x826D0A8C;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,1904
	ctx.r4.s64 = r11.s64 + 1904;
	// addi r3,r10,388
	ctx.r3.s64 = ctx.r10.s64 + 388;
	// bl 0x82554798
	ctx.lr = 0x826D0AA0;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,1936
	ctx.r4.s64 = ctx.r9.s64 + 1936;
	// addi r3,r8,372
	ctx.r3.s64 = ctx.r8.s64 + 372;
	// bl 0x82554798
	ctx.lr = 0x826D0AB4;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,2408
	ctx.r4.s64 = ctx.r7.s64 + 2408;
	// addi r3,r6,344
	ctx.r3.s64 = ctx.r6.s64 + 344;
	// bl 0x82554798
	ctx.lr = 0x826D0AC8;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,1984
	ctx.r4.s64 = ctx.r5.s64 + 1984;
	// addi r3,r3,316
	ctx.r3.s64 = ctx.r3.s64 + 316;
	// bl 0x82554798
	ctx.lr = 0x826D0ADC;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,2024
	ctx.r4.s64 = r11.s64 + 2024;
	// addi r3,r10,292
	ctx.r3.s64 = ctx.r10.s64 + 292;
	// bl 0x82554798
	ctx.lr = 0x826D0AF0;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,2056
	ctx.r4.s64 = ctx.r9.s64 + 2056;
	// addi r3,r8,268
	ctx.r3.s64 = ctx.r8.s64 + 268;
	// bl 0x82554798
	ctx.lr = 0x826D0B04;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,2104
	ctx.r4.s64 = ctx.r7.s64 + 2104;
	// addi r3,r6,240
	ctx.r3.s64 = ctx.r6.s64 + 240;
	// bl 0x82554798
	ctx.lr = 0x826D0B18;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,2160
	ctx.r4.s64 = ctx.r5.s64 + 2160;
	// addi r3,r3,224
	ctx.r3.s64 = ctx.r3.s64 + 224;
	// bl 0x82554798
	ctx.lr = 0x826D0B2C;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,2184
	ctx.r4.s64 = r11.s64 + 2184;
	// addi r3,r10,200
	ctx.r3.s64 = ctx.r10.s64 + 200;
	// bl 0x82554798
	ctx.lr = 0x826D0B40;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,2216
	ctx.r4.s64 = ctx.r9.s64 + 2216;
	// addi r3,r8,176
	ctx.r3.s64 = ctx.r8.s64 + 176;
	// bl 0x82554798
	ctx.lr = 0x826D0B54;
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

PPC_WEAK_FUNC(sub_826D0990) {
	__imp__sub_826D0990(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0B64) {
	__imp__sub_826D0B64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0B68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27204(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27204);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0B68) {
	__imp__sub_826D0B68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0B74) {
	__imp__sub_826D0B74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0B78) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-28924
	ctx.r9.s64 = r11.s64 + -28924;
	// addi r8,r10,-21868
	ctx.r8.s64 = ctx.r10.s64 + -21868;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r7,1320
	ctx.r4.s64 = ctx.r7.s64 + 1320;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x826D0BC4;
	sub_823DB670(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// addi r3,r5,1260
	ctx.r3.s64 = ctx.r5.s64 + 1260;
	// li r11,0
	r11.s64 = 0;
	// addi r4,r6,1272
	ctx.r4.s64 = ctx.r6.s64 + 1272;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stb r11,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stb r11,41(r31)
	PPC_STORE_U8(r31.u32 + 41, r11.u8);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stb r11,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r11.u8);
	// stb r11,52(r31)
	PPC_STORE_U8(r31.u32 + 52, r11.u8);
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

PPC_WEAK_FUNC(sub_826D0B78) {
	__imp__sub_826D0B78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0C14) {
	__imp__sub_826D0C14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0C18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stb r11,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0C18) {
	__imp__sub_826D0C18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0C28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lbz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// stbx r10,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r10.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0C28) {
	__imp__sub_826D0C28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0C44) {
	__imp__sub_826D0C44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lbzx r10,r11,r4
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0C48) {
	__imp__sub_826D0C48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0C64) {
	__imp__sub_826D0C64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r10,-23540
	ctx.r8.s64 = ctx.r10.s64 + -23540;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r9,10380
	ctx.r4.s64 = ctx.r9.s64 + 10380;
	// addi r3,r6,1332
	ctx.r3.s64 = ctx.r6.s64 + 1332;
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// b 0x823d9750
	sub_823D9750(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D0C68) {
	__imp__sub_826D0C68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0C90) {
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
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x826d0cc0
	if (!cr6.eq) goto loc_826D0CC0;
	// lwz r11,-4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4);
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D0CC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826D0CC0:
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

PPC_WEAK_FUNC(sub_826D0C90) {
	__imp__sub_826D0C90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0CD4) {
	__imp__sub_826D0CD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0CD8) {
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
	// bl 0x826d0b78
	ctx.lr = 0x826D0CF4;
	sub_826D0B78(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,1364
	ctx.r8.s64 = ctx.r10.s64 + 1364;
	// addi r7,r9,1352
	ctx.r7.s64 = ctx.r9.s64 + 1352;
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// stb r6,41(r31)
	PPC_STORE_U8(r31.u32 + 41, ctx.r6.u8);
	// stb r11,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r11.u8);
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

PPC_WEAK_FUNC(sub_826D0CD8) {
	__imp__sub_826D0CD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0D3C) {
	__imp__sub_826D0D3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0D40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27200(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27200);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0D40) {
	__imp__sub_826D0D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0D4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0D4C) {
	__imp__sub_826D0D4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0D50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,-23508(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -23508);
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D0D50) {
	__imp__sub_826D0D50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0D70) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0D70) {
	__imp__sub_826D0D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0D74) {
	__imp__sub_826D0D74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0D78) {
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
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r10,-23540
	ctx.r8.s64 = ctx.r10.s64 + -23540;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r30,r9,1332
	r30.s64 = ctx.r9.s64 + 1332;
	// addi r4,r6,10380
	ctx.r4.s64 = ctx.r6.s64 + 10380;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x823d9750
	ctx.lr = 0x826D0DBC;
	sub_823D9750(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r5,1428
	ctx.r4.s64 = ctx.r5.s64 + 1428;
	// addi r5,r31,88
	ctx.r5.s64 = r31.s64 + 88;
	// bl 0x823d9750
	ctx.lr = 0x826D0DD0;
	sub_823D9750(ctx, base);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r4,r4,-19880
	ctx.r4.s64 = ctx.r4.s64 + -19880;
	// addi r3,r3,1412
	ctx.r3.s64 = ctx.r3.s64 + 1412;
	// bl 0x823d9750
	ctx.lr = 0x826D0DE8;
	sub_823D9750(ctx, base);
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

PPC_WEAK_FUNC(sub_826D0D78) {
	__imp__sub_826D0D78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0E00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r3,124
	ctx.r10.s64 = ctx.r3.s64 + 124;
	// lbz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// stbx r9,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// add r11,r10,r4
	r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lbz r8,124(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 124);
	// stbx r8,r10,r4
	PPC_STORE_U8(ctx.r10.u32 + ctx.r4.u32, ctx.r8.u8);
	// lbz r7,125(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 125);
	// stb r7,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r7.u8);
	// lbz r6,126(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 126);
	// stb r6,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r6.u8);
	// lbz r4,127(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 127);
	// stb r4,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r4.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0E00) {
	__imp__sub_826D0E00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0E50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r3,124
	r11.s64 = ctx.r3.s64 + 124;
	// lbzx r9,r10,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r11,r4
	ctx.r8.u64 = r11.u64 + ctx.r4.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lbzx r7,r11,r4
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// stb r7,124(r3)
	PPC_STORE_U8(ctx.r3.u32 + 124, ctx.r7.u8);
	// lbz r6,1(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// stb r6,125(r3)
	PPC_STORE_U8(ctx.r3.u32 + 125, ctx.r6.u8);
	// lbz r4,2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// stb r4,126(r3)
	PPC_STORE_U8(ctx.r3.u32 + 126, ctx.r4.u8);
	// lbz r11,3(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 3);
	// stb r11,127(r3)
	PPC_STORE_U8(ctx.r3.u32 + 127, r11.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0E50) {
	__imp__sub_826D0E50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0EA0) {
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
	// bl 0x826d0b78
	ctx.lr = 0x826D0EBC;
	sub_826D0B78(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,1464
	ctx.r9.s64 = r11.s64 + 1464;
	// addi r8,r10,1452
	ctx.r8.s64 = ctx.r10.s64 + 1452;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r7,88(r31)
	PPC_STORE_U8(r31.u32 + 88, ctx.r7.u8);
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

PPC_WEAK_FUNC(sub_826D0EA0) {
	__imp__sub_826D0EA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D0EF4) {
	__imp__sub_826D0EF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D0EF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27196(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27196);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D0EF8) {
	__imp__sub_826D0EF8(ctx, base);
}

