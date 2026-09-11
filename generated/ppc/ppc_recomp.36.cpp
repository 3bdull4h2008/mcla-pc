#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_822711E8) {
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
	// addi r10,r11,-1348
	ctx.r10.s64 = r11.s64 + -1348;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227122c
	if (cr6.eq) goto loc_8227122C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x82271224;
	sub_82270908(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_8227122C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271244
	if (cr6.eq) goto loc_82271244;
	// bl 0x82130588
	ctx.lr = 0x82271240;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82271244:
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

PPC_WEAK_FUNC(sub_822711E8) {
	__imp__sub_822711E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227125C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227125C) {
	__imp__sub_8227125C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271260) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r11,-1364
	ctx.r9.s64 = r11.s64 + -1364;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8227127C:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822712fc
	if (cr6.eq) goto loc_822712FC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822712c0
	if (!cr6.eq) goto loc_822712C0;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822712b8
	if (cr6.eq) goto loc_822712B8;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// b 0x822712e8
	goto loc_822712E8;
loc_822712B8:
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// b 0x822712e8
	goto loc_822712E8;
loc_822712C0:
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822712e0
	if (cr6.eq) goto loc_822712E0;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// b 0x822712e8
	goto loc_822712E8;
loc_822712E0:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_822712E8:
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_822712FC:
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stb r9,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r9.u8);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8227127c
	if (!cr6.eq) goto loc_8227127C;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82271260) {
	__imp__sub_82271260(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271320) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r11,-1356
	ctx.r9.s64 = r11.s64 + -1356;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8227133C:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822713bc
	if (cr6.eq) goto loc_822713BC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82271380
	if (!cr6.eq) goto loc_82271380;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82271378
	if (cr6.eq) goto loc_82271378;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// b 0x822713a8
	goto loc_822713A8;
loc_82271378:
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// b 0x822713a8
	goto loc_822713A8;
loc_82271380:
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822713a0
	if (cr6.eq) goto loc_822713A0;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// b 0x822713a8
	goto loc_822713A8;
loc_822713A0:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_822713A8:
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_822713BC:
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stb r9,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r9.u8);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8227133c
	if (!cr6.eq) goto loc_8227133C;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82271320) {
	__imp__sub_82271320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822713E0) {
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
	// bl 0x82271260
	ctx.lr = 0x82271400;
	sub_82271260(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271418
	if (cr6.eq) goto loc_82271418;
	// bl 0x82130588
	ctx.lr = 0x82271414;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82271418:
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

PPC_WEAK_FUNC(sub_822713E0) {
	__imp__sub_822713E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271430) {
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
	// bl 0x82271320
	ctx.lr = 0x82271450;
	sub_82271320(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271468
	if (cr6.eq) goto loc_82271468;
	// bl 0x82130588
	ctx.lr = 0x82271464;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82271468:
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

PPC_WEAK_FUNC(sub_82271430) {
	__imp__sub_82271430(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271480) {
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
	// addi r10,r11,-1340
	ctx.r10.s64 = r11.s64 + -1340;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82271260
	ctx.lr = 0x822714AC;
	sub_82271260(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822714c4
	if (cr6.eq) goto loc_822714C4;
	// bl 0x82130588
	ctx.lr = 0x822714C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822714C4:
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

PPC_WEAK_FUNC(sub_82271480) {
	__imp__sub_82271480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822714DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822714DC) {
	__imp__sub_822714DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822714E0) {
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
	// addi r10,r11,-1332
	ctx.r10.s64 = r11.s64 + -1332;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82271320
	ctx.lr = 0x8227150C;
	sub_82271320(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82271524
	if (cr6.eq) goto loc_82271524;
	// bl 0x82130588
	ctx.lr = 0x82271520;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82271524:
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

PPC_WEAK_FUNC(sub_822714E0) {
	__imp__sub_822714E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227153C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227153C) {
	__imp__sub_8227153C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271540) {
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
	ctx.lr = 0x82271548;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r31,r29,28896
	r31.s64 = r29.s64 + 28896;
	// addi r10,r11,-1340
	ctx.r10.s64 = r11.s64 + -1340;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,28896(r29)
	PPC_STORE_U32(r29.u32 + 28896, ctx.r10.u32);
	// bl 0x82271260
	ctx.lr = 0x82271568;
	sub_82271260(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r27,31
	r27.s64 = 31;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r11,-1348
	r30.s64 = r11.s64 + -1348;
loc_82271578:
	// addi r31,r31,-24
	r31.s64 = r31.s64 + -24;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82271598
	if (cr6.eq) goto loc_82271598;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x82271594;
	sub_82270908(ctx, base);
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
loc_82271598:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// bge 0x82271578
	if (!cr0.lt) goto loc_82271578;
	// addi r31,r29,27488
	r31.s64 = r29.s64 + 27488;
	// li r30,31
	r30.s64 = 31;
loc_822715A8:
	// addi r31,r31,-176
	r31.s64 = r31.s64 + -176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fd9b8
	ctx.lr = 0x822715B4;
	sub_824FD9B8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822715a8
	if (!cr0.lt) goto loc_822715A8;
	// addi r3,r29,528
	ctx.r3.s64 = r29.s64 + 528;
	// bl 0x824fd140
	ctx.lr = 0x822715C4;
	sub_824FD140(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82271540) {
	__imp__sub_82271540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822715CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822715CC) {
	__imp__sub_822715CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822715D0) {
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
	ctx.lr = 0x822715D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r26,16
	r30.s64 = r26.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f8730
	ctx.lr = 0x822715F0;
	sub_821F8730(ctx, base);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,4284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4284);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mulli r10,r8,10832
	ctx.r10.s64 = ctx.r8.s64 * 10832;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82271614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,6
	cr6.compare<uint32_t>(ctx.r3.u32, 6, xer);
	// bgt cr6,0x8227194c
	if (cr6.gt) goto loc_8227194C;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,5684
	r12.s64 = r12.s64 + 5684;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,5712(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 5712);
	// lwz r17,6476(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6476);
	// lwz r17,6140(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6140);
	// lwz r17,6212(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6212);
	// lwz r17,6212(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6212);
	// lwz r17,6476(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6476);
	// lwz r17,6168(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6168);
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82271698
	if (!cr6.eq) goto loc_82271698;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82274130
	ctx.lr = 0x8227166C;
	sub_82274130(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82271684;
	sub_822990D8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x82271690;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82271698:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822716dc
	if (!cr6.eq) goto loc_822716DC;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x822716B0;
	sub_823DA950(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,17
	ctx.r5.s64 = 17;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822716C8;
	sub_822990D8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x822716D4;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822716DC:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82271728
	if (!cr6.eq) goto loc_82271728;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x822716F4;
	sub_823DA950(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82272d90
	ctx.lr = 0x822716FC;
	sub_82272D90(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,18
	ctx.r5.s64 = 18;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82271714;
	sub_822990D8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x82271720;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82271728:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8227176c
	if (!cr6.eq) goto loc_8227176C;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82271740;
	sub_823DA950(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,19
	ctx.r5.s64 = 19;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82271758;
	sub_822990D8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x82271764;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8227176C:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822717b8
	if (!cr6.eq) goto loc_822717B8;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82271784;
	sub_823DA950(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82272d90
	ctx.lr = 0x8227178C;
	sub_82272D90(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822717A4;
	sub_822990D8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x822717B0;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822717B8:
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x8227194c
	if (!cr6.eq) goto loc_8227194C;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x822717D0;
	sub_823DA950(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,21
	ctx.r5.s64 = 21;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822717E8;
	sub_822990D8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x822717F4;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82272d90
	ctx.lr = 0x82271804;
	sub_82272D90(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x82271810;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,23
	ctx.r5.s64 = 23;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82271830;
	sub_822990D8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x8227183C;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
	// lwz r11,596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 596);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227194c
	if (!cr6.eq) goto loc_8227194C;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82271864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// addi r28,r11,112
	r28.s64 = r11.s64 + 112;
	// li r27,0
	r27.s64 = 0;
	// li r30,0
	r30.s64 = 0;
loc_82271878:
	// lwz r11,4288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4288);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8226fff8
	ctx.lr = 0x82271884;
	sub_8226FFF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822718b4
	if (!cr6.eq) goto loc_822718B4;
	// lwz r11,4288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4288);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481618
	ctx.lr = 0x822718A0;
	sub_82481618(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824e6358
	ctx.lr = 0x822718A8;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822718c8
	if (!cr6.eq) goto loc_822718C8;
loc_822718B4:
	// addi r30,r30,11824
	r30.s64 = r30.s64 + 11824;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmplwi cr6,r30,47296
	cr6.compare<uint32_t>(r30.u32, 47296, xer);
	// bne cr6,0x82271878
	if (!cr6.eq) goto loc_82271878;
	// b 0x822718e8
	goto loc_822718E8;
loc_822718C8:
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822718E0;
	sub_822990D8(ctx, base);
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// bne cr6,0x8227194c
	if (!cr6.eq) goto loc_8227194C;
loc_822718E8:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822718FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,-3
	ctx.r9.s64 = ctx.r3.s64 + -3;
	// stw r29,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r29.u32);
	// addi r3,r31,536
	ctx.r3.s64 = r31.s64 + 536;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r7,600(r31)
	PPC_STORE_U8(r31.u32 + 600, ctx.r7.u8);
	// bl 0x823da950
	ctx.lr = 0x82271920;
	sub_823DA950(ctx, base);
	// addi r30,r31,604
	r30.s64 = r31.s64 + 604;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6310
	ctx.lr = 0x8227192C;
	sub_824E6310(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// addi r8,r31,1176
	ctx.r8.s64 = r31.s64 + 1176;
	// addi r3,r6,-2984
	ctx.r3.s64 = ctx.r6.s64 + -2984;
	// addi r7,r31,616
	ctx.r7.s64 = r31.s64 + 616;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82486958
	ctx.lr = 0x8227194C;
	sub_82486958(ctx, base);
loc_8227194C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822739e8
	ctx.lr = 0x82271958;
	sub_822739E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822715D0) {
	__imp__sub_822715D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271960) {
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
	ctx.lr = 0x82271968;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82271988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82271d0c
	if (!cr6.eq) goto loc_82271D0C;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82257678
	ctx.lr = 0x822719A4;
	sub_82257678(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r10,8860
	r30.s64 = ctx.r10.s64 + 8860;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82271b30
	if (!cr6.eq) goto loc_82271B30;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82270478
	ctx.lr = 0x822719CC;
	sub_82270478(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82270748
	ctx.lr = 0x822719E4;
	sub_82270748(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x822704d0
	ctx.lr = 0x82271A00;
	sub_822704D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82272af0
	ctx.lr = 0x82271A18;
	sub_82272AF0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203310
	ctx.lr = 0x82271A20;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ori r27,r10,25904
	r27.u64 = ctx.r10.u64 | 25904;
	// beq cr6,0x82271a40
	if (cr6.eq) goto loc_82271A40;
	// lbz r11,278(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271b14
	if (cr6.eq) goto loc_82271B14;
loc_82271A40:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,-1372
	ctx.r8.s64 = r11.s64 + -1372;
	// stb r10,280(r30)
	PPC_STORE_U8(r30.u32 + 280, ctx.r10.u8);
	// stb r9,278(r30)
	PPC_STORE_U8(r30.u32 + 278, ctx.r9.u8);
	// addi r3,r1,124
	ctx.r3.s64 = ctx.r1.s64 + 124;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// bl 0x824e6310
	ctx.lr = 0x82271A64;
	sub_824E6310(ctx, base);
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82502300
	ctx.lr = 0x82271A70;
	sub_82502300(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822704d0
	ctx.lr = 0x82271A80;
	sub_822704D0(ctx, base);
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// ld r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// addi r31,r30,208
	r31.s64 = r30.s64 + 208;
	// li r28,8
	r28.s64 = 8;
	// std r7,124(r1)
	PPC_STORE_U64(ctx.r1.u32 + 124, ctx.r7.u64);
loc_82271A94:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82271aec
	if (cr6.eq) goto loc_82271AEC;
	// bl 0x8226fff8
	ctx.lr = 0x82271AA4;
	sub_8226FFF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82271aec
	if (!cr6.eq) goto loc_82271AEC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8226b020
	ctx.lr = 0x82271AB8;
	sub_8226B020(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82271aec
	if (!cr6.eq) goto loc_82271AEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// add r3,r26,r27
	ctx.r3.u64 = r26.u64 + r27.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// bl 0x822990d8
	ctx.lr = 0x82271AE0;
	sub_822990D8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r26,4312
	ctx.r3.s64 = r26.s64 + 4312;
	// bl 0x822976f8
	ctx.lr = 0x82271AEC;
	sub_822976F8(ctx, base);
loc_82271AEC:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x82271a94
	if (!cr0.eq) goto loc_82271A94;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r30,112
	ctx.r3.s64 = r30.s64 + 112;
	// bl 0x82130000
	ctx.lr = 0x82271B08;
	sub_82130000(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-1380
	ctx.r10.s64 = r11.s64 + -1380;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
loc_82271B14:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,14
	ctx.r5.s64 = 14;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// add r3,r26,r27
	ctx.r3.u64 = r26.u64 + r27.u64;
	// bl 0x822990d8
	ctx.lr = 0x82271B28;
	sub_822990D8(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9240
	return;
loc_82271B30:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16844
	ctx.r9.s64 = ctx.r10.s64 + 16844;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x82271bc0
	if (!cr6.eq) goto loc_82271BC0;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r10,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82270ca8
	ctx.lr = 0x82271B68;
	sub_82270CA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822959b8
	ctx.lr = 0x82271B7C;
	sub_822959B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x82296188
	ctx.lr = 0x82271B98;
	sub_82296188(ctx, base);
	// addis r3,r26,5
	ctx.r3.s64 = r26.s64 + 327680;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82271BB0;
	sub_822990D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822957a8
	ctx.lr = 0x82271BB8;
	sub_822957A8(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9240
	return;
loc_82271BC0:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16896
	ctx.r9.s64 = ctx.r10.s64 + 16896;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x82271c6c
	if (!cr6.eq) goto loc_82271C6C;
	// li r30,0
	r30.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// std r30,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r30.u64);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82270d90
	ctx.lr = 0x82271BF4;
	sub_82270D90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// lbz r11,96(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r30
	r11.u64 = r30.u64;
	// lwz r10,-10240(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r9,4288(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4288);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82271C24:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// cmpw cr6,r6,r8
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r8.s32, xer);
	// beq cr6,0x82271c4c
	if (cr6.eq) goto loc_82271C4C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,11824
	ctx.r10.s64 = ctx.r10.s64 + 11824;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x82271c24
	if (!cr6.eq) goto loc_82271C24;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9240
	return;
loc_82271C4C:
	// mulli r11,r11,11824
	r11.s64 = r11.s64 * 11824;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x82296cf8
	ctx.lr = 0x82271C64;
	sub_82296CF8(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9240
	return;
loc_82271C6C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,8796
	ctx.r9.s64 = ctx.r10.s64 + 8796;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82271cc0
	if (!cr6.eq) goto loc_82271CC0;
	// lwz r3,4296(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4296);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82271C9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,282(r11)
	PPC_STORE_U8(r11.u32 + 282, ctx.r10.u8);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9240
	return;
loc_82271CC0:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,8828
	ctx.r9.s64 = ctx.r10.s64 + 8828;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82271d0c
	if (!cr6.eq) goto loc_82271D0C;
	// lwz r3,4296(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4296);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82271CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82271d0c
	if (cr6.eq) goto loc_82271D0C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,282(r11)
	PPC_STORE_U8(r11.u32 + 282, ctx.r10.u8);
loc_82271D0C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82271960) {
	__imp__sub_82271960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271D14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82271D14) {
	__imp__sub_82271D14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271D18) {
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
	ctx.lr = 0x82271D20;
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
	// bl 0x82272a00
	ctx.lr = 0x82271D34;
	sub_82272A00(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x82271e68
	if (cr6.gt) goto loc_82271E68;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r11,4300(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82271d90
	if (cr6.eq) goto loc_82271D90;
	// addi r31,r30,16
	r31.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82502300
	ctx.lr = 0x82271D5C;
	sub_82502300(ctx, base);
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82464958
	ctx.lr = 0x82271D6C;
	sub_82464958(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271d90
	if (cr6.eq) goto loc_82271D90;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82502300
	ctx.lr = 0x82271D80;
	sub_82502300(ctx, base);
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82464790
	ctx.lr = 0x82271D90;
	sub_82464790(ctx, base);
loc_82271D90:
	// addi r31,r30,16
	r31.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7060
	ctx.lr = 0x82271D9C;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271db8
	if (cr6.eq) goto loc_82271DB8;
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x822999e0
	ctx.lr = 0x82271DB8;
	sub_822999E0(ctx, base);
loc_82271DB8:
	// lbz r11,277(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 277);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82271e68
	if (!cr6.eq) goto loc_82271E68;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7060
	ctx.lr = 0x82271DCC;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271e68
	if (cr6.eq) goto loc_82271E68;
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82299678
	ctx.lr = 0x82271DE8;
	sub_82299678(ctx, base);
	// lhz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// addi r29,r27,8
	r29.s64 = r27.s64 + 8;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82271e5c
	if (!cr6.gt) goto loc_82271E5C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_82271E00:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// beq cr6,0x82271e30
	if (cr6.eq) goto loc_82271E30;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x82271e00
	if (cr6.lt) goto loc_82271E00;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// bl 0x826cb850
	ctx.lr = 0x82271E28;
	sub_826CB850(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82271E30:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82271e5c
	if (cr6.lt) goto loc_82271E5C;
	// lwz r4,-10240(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,9
	ctx.r5.s64 = 9;
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82271E50;
	sub_822990D8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262cb88
	ctx.lr = 0x82271E5C;
	sub_8262CB88(ctx, base);
loc_82271E5C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// bl 0x826cb850
	ctx.lr = 0x82271E68;
	sub_826CB850(ctx, base);
loc_82271E68:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82271D18) {
	__imp__sub_82271D18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82271E70) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82271E78;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// addi r3,r25,12
	ctx.r3.s64 = r25.s64 + 12;
	// stw r29,4(r25)
	PPC_STORE_U32(r25.u32 + 4, r29.u32);
	// stw r29,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r29.u32);
	// bl 0x824e8de8
	ctx.lr = 0x82271E94;
	sub_824E8DE8(ctx, base);
	// addi r3,r25,528
	ctx.r3.s64 = r25.s64 + 528;
	// bl 0x824fc5a0
	ctx.lr = 0x82271E9C;
	sub_824FC5A0(ctx, base);
	// addi r30,r25,2016
	r30.s64 = r25.s64 + 2016;
	// li r11,32
	r11.s64 = 32;
	// stw r29,2000(r25)
	PPC_STORE_U32(r25.u32 + 2000, r29.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,1992(r25)
	PPC_STORE_U32(r25.u32 + 1992, r30.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1996(r25)
	PPC_STORE_U32(r25.u32 + 1996, r11.u32);
	// stw r29,2004(r25)
	PPC_STORE_U32(r25.u32 + 2004, r29.u32);
	// li r31,31
	r31.s64 = 31;
	// stw r10,2008(r25)
	PPC_STORE_U32(r25.u32 + 2008, ctx.r10.u32);
	// stb r9,2012(r25)
	PPC_STORE_U8(r25.u32 + 2012, ctx.r9.u8);
loc_82271EC8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fc050
	ctx.lr = 0x82271ED0;
	sub_824FC050(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,620
	r30.s64 = r30.s64 + 620;
	// bge 0x82271ec8
	if (!cr0.lt) goto loc_82271EC8;
	// addi r30,r25,21856
	r30.s64 = r25.s64 + 21856;
	// li r31,31
	r31.s64 = 31;
loc_82271EE4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fdb58
	ctx.lr = 0x82271EEC;
	sub_824FDB58(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// bge 0x82271ee4
	if (!cr0.lt) goto loc_82271EE4;
	// addi r11,r25,27488
	r11.s64 = r25.s64 + 27488;
	// li r10,31
	ctx.r10.s64 = 31;
loc_82271F00:
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r29.u32);
	// stw r29,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r29.u32);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// bge 0x82271f00
	if (!cr0.lt) goto loc_82271F00;
	// addi r24,r25,28128
	r24.s64 = r25.s64 + 28128;
	// lwz r20,0(r13)
	r20.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r21,60
	r21.s64 = 60;
	// li r22,31
	r22.s64 = 31;
	// addi r30,r24,16
	r30.s64 = r24.s64 + 16;
	// addi r23,r10,-26560
	r23.s64 = ctx.r10.s64 + -26560;
	// addi r19,r11,-1348
	r19.s64 = r11.s64 + -1348;
loc_82271F40:
	// stw r29,-12(r30)
	PPC_STORE_U32(r30.u32 + -12, r29.u32);
	// stw r29,-8(r30)
	PPC_STORE_U32(r30.u32 + -8, r29.u32);
	// stw r19,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r19.u32);
	// lwzx r31,r21,r20
	r31.u64 = PPC_LOAD_U32(r21.u32 + r20.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82271fe4
	if (cr6.eq) goto loc_82271FE4;
	// addi r26,r30,-4
	r26.s64 = r30.s64 + -4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82187a38
	ctx.lr = 0x82271F68;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82271fe4
	if (cr6.eq) goto loc_82271FE4;
	// lwz r27,0(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82271fec
	if (cr6.eq) goto loc_82271FEC;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d828
	ctx.lr = 0x82271F8C;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82271fc0
	if (cr6.eq) goto loc_82271FC0;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rotlwi r10,r27,0
	ctx.r10.u64 = __builtin_rotateleft32(r27.u32, 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
	// b 0x82271fec
	goto loc_82271FEC;
loc_82271FC0:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2378
	ctx.lr = 0x82271FD0;
	sub_821D2378(ctx, base);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r11,r29
	r11.u64 = r29.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
	// b 0x82271fec
	goto loc_82271FEC;
loc_82271FE4:
	// addi r26,r30,-4
	r26.s64 = r30.s64 + -4;
	// stw r29,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r29.u32);
loc_82271FEC:
	// lwzx r31,r21,r20
	r31.u64 = PPC_LOAD_U32(r21.u32 + r20.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82272080
	if (cr6.eq) goto loc_82272080;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82272004;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82272080
	if (cr6.eq) goto loc_82272080;
	// lwz r27,0(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82272084
	if (cr6.eq) goto loc_82272084;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d828
	ctx.lr = 0x82272028;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8227205c
	if (cr6.eq) goto loc_8227205C;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rotlwi r10,r27,0
	ctx.r10.u64 = __builtin_rotateleft32(r27.u32, 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x82272084
	goto loc_82272084;
loc_8227205C:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2378
	ctx.lr = 0x8227206C;
	sub_821D2378(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r11,r29
	r11.u64 = r29.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x82272084
	goto loc_82272084;
loc_82272080:
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
loc_82272084:
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// stw r29,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r29.u32);
	// addi r24,r24,24
	r24.s64 = r24.s64 + 24;
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bge 0x82271f40
	if (!cr0.lt) goto loc_82271F40;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r29,28904(r25)
	PPC_STORE_U32(r25.u32 + 28904, r29.u32);
	// stw r29,28900(r25)
	PPC_STORE_U32(r25.u32 + 28900, r29.u32);
	// addi r11,r25,28896
	r11.s64 = r25.s64 + 28896;
	// addi r9,r10,-1340
	ctx.r9.s64 = ctx.r10.s64 + -1340;
	// stw r29,28908(r25)
	PPC_STORE_U32(r25.u32 + 28908, r29.u32);
	// stw r29,28916(r25)
	PPC_STORE_U32(r25.u32 + 28916, r29.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r29,28912(r25)
	PPC_STORE_U32(r25.u32 + 28912, r29.u32);
	// stw r29,28920(r25)
	PPC_STORE_U32(r25.u32 + 28920, r29.u32);
	// stw r9,28896(r25)
	PPC_STORE_U32(r25.u32 + 28896, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_82271E70) {
	__imp__sub_82271E70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822720D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822720D4) {
	__imp__sub_822720D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822720D8) {
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
	ctx.lr = 0x822720E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x822720F0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82272104
	if (cr6.eq) goto loc_82272104;
	// bl 0x824fb7d8
	ctx.lr = 0x82272100;
	sub_824FB7D8(ctx, base);
	// b 0x82272108
	goto loc_82272108;
loc_82272104:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82272108:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82130528
	ctx.lr = 0x82272114;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82272124
	if (cr6.eq) goto loc_82272124;
	// bl 0x824f9150
	ctx.lr = 0x82272120;
	sub_824F9150(ctx, base);
	// b 0x82272128
	goto loc_82272128;
loc_82272124:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82272128:
	// li r11,1
	r11.s64 = 1;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// addi r24,r31,8
	r24.s64 = r31.s64 + 8;
	// bl 0x824e8de8
	ctx.lr = 0x82272144;
	sub_824E8DE8(ctx, base);
	// addi r29,r31,536
	r29.s64 = r31.s64 + 536;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6400
	ctx.lr = 0x82272150;
	sub_824E6400(ctx, base);
	// addi r3,r29,68
	ctx.r3.s64 = r29.s64 + 68;
	// bl 0x824e6310
	ctx.lr = 0x82272158;
	sub_824E6310(ctx, base);
	// addi r3,r29,80
	ctx.r3.s64 = r29.s64 + 80;
	// bl 0x824e1c10
	ctx.lr = 0x82272160;
	sub_824E1C10(ctx, base);
	// stw r30,1176(r31)
	PPC_STORE_U32(r31.u32 + 1176, r30.u32);
	// stw r30,1180(r31)
	PPC_STORE_U32(r31.u32 + 1180, r30.u32);
	// addi r3,r31,1184
	ctx.r3.s64 = r31.s64 + 1184;
	// bl 0x824e8c98
	ctx.lr = 0x82272170;
	sub_824E8C98(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82272178;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227219c
	if (cr6.eq) goto loc_8227219C;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// sth r30,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r30.u16);
	// sth r30,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r30.u16);
	// b 0x822721a0
	goto loc_822721A0;
loc_8227219C:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_822721A0:
	// stw r11,4280(r31)
	PPC_STORE_U32(r31.u32 + 4280, r11.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,43336
	ctx.r3.u64 = ctx.r3.u64 | 43336;
	// bl 0x82130528
	ctx.lr = 0x822721B0;
	sub_82130528(ctx, base);
	// li r25,4
	r25.s64 = 4;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822721e4
	if (cr6.eq) goto loc_822721E4;
	// addi r26,r3,8
	r26.s64 = ctx.r3.s64 + 8;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// li r28,3
	r28.s64 = 3;
	// mr r27,r26
	r27.u64 = r26.u64;
loc_822721CC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82274330
	ctx.lr = 0x822721D4;
	sub_82274330(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,10832
	r27.s64 = r27.s64 + 10832;
	// bge 0x822721cc
	if (!cr0.lt) goto loc_822721CC;
	// b 0x822721e8
	goto loc_822721E8;
loc_822721E4:
	// mr r26,r30
	r26.u64 = r30.u64;
loc_822721E8:
	// stw r26,4284(r31)
	PPC_STORE_U32(r31.u32 + 4284, r26.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,47304
	ctx.r3.u64 = ctx.r3.u64 | 47304;
	// bl 0x82130528
	ctx.lr = 0x822721F8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82272228
	if (cr6.eq) goto loc_82272228;
	// addi r26,r3,8
	r26.s64 = ctx.r3.s64 + 8;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// li r28,3
	r28.s64 = 3;
	// mr r27,r26
	r27.u64 = r26.u64;
loc_82272210:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82298550
	ctx.lr = 0x82272218;
	sub_82298550(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,11824
	r27.s64 = r27.s64 + 11824;
	// bge 0x82272210
	if (!cr0.lt) goto loc_82272210;
	// b 0x8227222c
	goto loc_8227222C;
loc_82272228:
	// mr r26,r30
	r26.u64 = r30.u64;
loc_8227222C:
	// stw r26,4288(r31)
	PPC_STORE_U32(r31.u32 + 4288, r26.u32);
	// li r3,28928
	ctx.r3.s64 = 28928;
	// bl 0x82130528
	ctx.lr = 0x82272238;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82272248
	if (cr6.eq) goto loc_82272248;
	// bl 0x82271e70
	ctx.lr = 0x82272244;
	sub_82271E70(ctx, base);
	// b 0x8227224c
	goto loc_8227224C;
loc_82272248:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8227224C:
	// stw r3,4292(r31)
	PPC_STORE_U32(r31.u32 + 4292, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r30,4296(r31)
	PPC_STORE_U32(r31.u32 + 4296, r30.u32);
	// stw r30,4300(r31)
	PPC_STORE_U32(r31.u32 + 4300, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x82272260;
	sub_82130528(ctx, base);
	// stw r3,4304(r31)
	PPC_STORE_U32(r31.u32 + 4304, ctx.r3.u32);
	// addi r28,r31,4312
	r28.s64 = r31.s64 + 4312;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822976a0
	ctx.lr = 0x82272270;
	sub_822976A0(ctx, base);
	// addi r3,r31,13928
	ctx.r3.s64 = r31.s64 + 13928;
	// bl 0x822976a0
	ctx.lr = 0x82272278;
	sub_822976A0(ctx, base);
	// stw r30,23544(r31)
	PPC_STORE_U32(r31.u32 + 23544, r30.u32);
	// stw r30,23548(r31)
	PPC_STORE_U32(r31.u32 + 23548, r30.u32);
	// addi r3,r31,23564
	ctx.r3.s64 = r31.s64 + 23564;
	// stw r30,23552(r31)
	PPC_STORE_U32(r31.u32 + 23552, r30.u32);
	// addi r11,r31,23544
	r11.s64 = r31.s64 + 23544;
	// stw r30,23556(r31)
	PPC_STORE_U32(r31.u32 + 23556, r30.u32);
	// stw r30,23560(r31)
	PPC_STORE_U32(r31.u32 + 23560, r30.u32);
	// bl 0x824ebf78
	ctx.lr = 0x82272298;
	sub_824EBF78(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,2
	ctx.r6.s64 = 2;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r4,r31,25900
	ctx.r4.s64 = r31.s64 + 25900;
	// addi r3,r31,23592
	ctx.r3.s64 = r31.s64 + 23592;
	// bl 0x821c2d88
	ctx.lr = 0x822722B0;
	sub_821C2D88(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// addi r3,r3,25900
	ctx.r3.s64 = ctx.r3.s64 + 25900;
	// bl 0x824ea428
	ctx.lr = 0x822722BC;
	sub_824EA428(ctx, base);
	// addis r11,r31,5
	r11.s64 = r31.s64 + 327680;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r11,r11,25904
	r11.s64 = r11.s64 + 25904;
	// addi r9,r10,-1332
	ctx.r9.s64 = ctx.r10.s64 + -1332;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// stw r30,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r30.u32);
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
	// stw r30,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r30.u32);
	// stw r30,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r30.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bl 0x82297350
	ctx.lr = 0x822722F0;
	sub_82297350(ctx, base);
	// lis r8,-32217
	ctx.r8.s64 = -2111373312;
	// stw r30,23544(r31)
	PPC_STORE_U32(r31.u32 + 23544, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,5584
	ctx.r7.s64 = ctx.r8.s64 + 5584;
	// stw r7,23548(r31)
	PPC_STORE_U32(r31.u32 + 23548, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x82272308;
	sub_82130000(ctx, base);
	// lis r6,-32217
	ctx.r6.s64 = -2111373312;
	// stw r3,23544(r31)
	PPC_STORE_U32(r31.u32 + 23544, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,6496
	ctx.r5.s64 = ctx.r6.s64 + 6496;
	// stw r30,23564(r31)
	PPC_STORE_U32(r31.u32 + 23564, r30.u32);
	// stw r5,23568(r31)
	PPC_STORE_U32(r31.u32 + 23568, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x82272324;
	sub_82130000(ctx, base);
	// stw r3,23564(r31)
	PPC_STORE_U32(r31.u32 + 23564, ctx.r3.u32);
	// stw r30,60(r29)
	PPC_STORE_U32(r29.u32 + 60, r30.u32);
	// addi r3,r29,68
	ctx.r3.s64 = r29.s64 + 68;
	// stb r30,64(r29)
	PPC_STORE_U8(r29.u32 + 64, r30.u8);
	// bl 0x824e6310
	ctx.lr = 0x82272338;
	sub_824E6310(ctx, base);
	// addi r3,r29,80
	ctx.r3.s64 = r29.s64 + 80;
	// bl 0x824e0a58
	ctx.lr = 0x82272340;
	sub_824E0A58(ctx, base);
	// addi r3,r29,640
	ctx.r3.s64 = r29.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821ce080
	ctx.lr = 0x8227234C;
	sub_821CE080(ctx, base);
	// stw r30,644(r29)
	PPC_STORE_U32(r29.u32 + 644, r30.u32);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r3,8632
	ctx.r3.s64 = ctx.r3.s64 + 8632;
	// bl 0x821c0750
	ctx.lr = 0x82272360;
	sub_821C0750(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_822720D8) {
	__imp__sub_822720D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227236C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227236C) {
	__imp__sub_8227236C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272370) {
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
	ctx.lr = 0x82272378;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821c9788
	ctx.lr = 0x82272384;
	sub_821C9788(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824fb560
	ctx.lr = 0x82272390;
	sub_824FB560(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82272394;
	sub_82130000(ctx, base);
	// addi r3,r30,1184
	ctx.r3.s64 = r30.s64 + 1184;
	// bl 0x824e8d70
	ctx.lr = 0x8227239C;
	sub_824E8D70(ctx, base);
	// addis r3,r30,5
	ctx.r3.s64 = r30.s64 + 327680;
	// addi r3,r3,25900
	ctx.r3.s64 = ctx.r3.s64 + 25900;
	// bl 0x82130000
	ctx.lr = 0x822723A8;
	sub_82130000(ctx, base);
	// lwz r3,4296(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4296);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822723BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,596(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 596);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82272428
	if (cr6.eq) goto loc_82272428;
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// addi r31,r30,536
	r31.s64 = r30.s64 + 536;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822723e8
	if (cr6.eq) goto loc_822723E8;
	// lwz r11,640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822723ec
	if (!cr6.eq) goto loc_822723EC;
loc_822723E8:
	// li r11,0
	r11.s64 = 0;
loc_822723EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82272428
	if (cr6.eq) goto loc_82272428;
	// lwz r11,1176(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1176);
	// addis r3,r30,5
	ctx.r3.s64 = r30.s64 + 327680;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// li r5,10
	ctx.r5.s64 = 10;
	// beq cr6,0x8227241c
	if (cr6.eq) goto loc_8227241C;
	// li r5,11
	ctx.r5.s64 = 11;
loc_8227241C:
	// bl 0x822990d8
	ctx.lr = 0x82272420;
	sub_822990D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f76b0
	ctx.lr = 0x82272428;
	sub_821F76B0(ctx, base);
loc_82272428:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,-2984
	ctx.r3.s64 = r11.s64 + -2984;
	// bl 0x82486c48
	ctx.lr = 0x82272438;
	sub_82486C48(ctx, base);
	// li r29,0
	r29.s64 = 0;
loc_8227243C:
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x82297a28
	ctx.lr = 0x8227244C;
	sub_82297A28(ctx, base);
	// addi r28,r29,12
	r28.s64 = r29.s64 + 12;
	// li r27,31
	r27.s64 = 31;
loc_82272454:
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// lwzx r31,r28,r11
	r31.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822724a4
	if (cr6.eq) goto loc_822724A4;
	// lbz r10,278(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822724a4
	if (cr6.eq) goto loc_822724A4;
	// lbz r10,277(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 277);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822724a4
	if (!cr6.eq) goto loc_822724A4;
	// add r4,r29,r11
	ctx.r4.u64 = r29.u64 + r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272a48
	ctx.lr = 0x82272488;
	sub_82272A48(ctx, base);
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x82296fa8
	ctx.lr = 0x82272498;
	sub_82296FA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4280(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4280);
	// bl 0x82271d18
	ctx.lr = 0x822724A4;
	sub_82271D18(ctx, base);
loc_822724A4:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x82272454
	if (!cr0.eq) goto loc_82272454;
	// addi r29,r29,11824
	r29.s64 = r29.s64 + 11824;
	// cmplwi cr6,r29,47296
	cr6.compare<uint32_t>(r29.u32, 47296, xer);
	// bne cr6,0x8227243c
	if (!cr6.eq) goto loc_8227243C;
	// lis r11,0
	r11.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// ori r29,r11,43328
	r29.u64 = r11.u64 | 43328;
loc_822724C8:
	// lwz r11,4284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4284);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82274b80
	ctx.lr = 0x822724D4;
	sub_82274B80(ctx, base);
	// addi r31,r31,10832
	r31.s64 = r31.s64 + 10832;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x822724c8
	if (cr6.lt) goto loc_822724C8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,4292(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4292);
	// bl 0x82299400
	ctx.lr = 0x822724EC;
	sub_82299400(ctx, base);
	// lwz r3,4300(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4300);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822724fc
	if (cr6.eq) goto loc_822724FC;
	// bl 0x82464d28
	ctx.lr = 0x822724FC;
	sub_82464D28(ctx, base);
loc_822724FC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82272370) {
	__imp__sub_82272370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272504) {
	__imp__sub_82272504(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272508) {
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
	ctx.lr = 0x82272510;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82272670
	if (cr6.eq) goto loc_82272670;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_8227252C:
	// lwz r11,4288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4288);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x822974f0
	ctx.lr = 0x82272538;
	sub_822974F0(ctx, base);
loc_82272538:
	// lwz r11,4288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4288);
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// addi r3,r30,144
	ctx.r3.s64 = r30.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x82272548;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82272564
	if (!cr6.eq) goto loc_82272564;
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82272568
	if (cr6.eq) goto loc_82272568;
loc_82272564:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82272568:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82272580
	if (!cr6.eq) goto loc_82272580;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272370
	ctx.lr = 0x8227257C;
	sub_82272370(ctx, base);
	// b 0x82272538
	goto loc_82272538;
loc_82272580:
	// addi r29,r29,11824
	r29.s64 = r29.s64 + 11824;
	// cmplwi cr6,r29,47296
	cr6.compare<uint32_t>(r29.u32, 47296, xer);
	// bne cr6,0x8227252c
	if (!cr6.eq) goto loc_8227252C;
	// lis r11,0
	r11.s64 = 0;
	// mr r30,r28
	r30.u64 = r28.u64;
	// ori r29,r11,43328
	r29.u64 = r11.u64 | 43328;
loc_82272598:
	// lwz r11,4284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4284);
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822733a0
	ctx.lr = 0x822725A4;
	sub_822733A0(ctx, base);
	// addi r30,r30,10832
	r30.s64 = r30.s64 + 10832;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x82272598
	if (cr6.lt) goto loc_82272598;
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// addi r3,r3,25900
	ctx.r3.s64 = ctx.r3.s64 + 25900;
	// bl 0x824ea578
	ctx.lr = 0x822725BC;
	sub_824EA578(ctx, base);
	// addi r30,r31,1184
	r30.s64 = r31.s64 + 1184;
	// addi r4,r31,23544
	ctx.r4.s64 = r31.s64 + 23544;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7fe8
	ctx.lr = 0x822725CC;
	sub_824E7FE8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7ef0
	ctx.lr = 0x822725D4;
	sub_824E7EF0(ctx, base);
	// lwz r3,4292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4292);
	// bl 0x82299088
	ctx.lr = 0x822725DC;
	sub_82299088(ctx, base);
	// lwz r3,4300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4300);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82272608
	if (cr6.eq) goto loc_82272608;
	// bl 0x82464c68
	ctx.lr = 0x822725EC;
	sub_82464C68(ctx, base);
	// lwz r30,4300(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4300);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82272608
	if (cr6.eq) goto loc_82272608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824650d0
	ctx.lr = 0x82272600;
	sub_824650D0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82272608;
	sub_82130588(ctx, base);
loc_82272608:
	// stw r28,4300(r31)
	PPC_STORE_U32(r31.u32 + 4300, r28.u32);
	// bl 0x824fba20
	ctx.lr = 0x82272610;
	sub_824FBA20(ctx, base);
	// lwz r3,4296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// bl 0x82299800
	ctx.lr = 0x82272618;
	sub_82299800(ctx, base);
	// lwz r3,4296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82272638
	if (cr6.eq) goto loc_82272638;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82272638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82272638:
	// stw r28,4296(r31)
	PPC_STORE_U32(r31.u32 + 4296, r28.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fb6a0
	ctx.lr = 0x82272648;
	sub_824FB6A0(ctx, base);
	// bl 0x824fa8a8
	ctx.lr = 0x8227264C;
	sub_824FA8A8(ctx, base);
	// lwz r10,23592(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 23592);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,23592
	ctx.r3.s64 = r31.s64 + 23592;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-1328
	ctx.r4.s64 = r11.s64 + -1328;
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8227266C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
loc_82272670:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82272508) {
	__imp__sub_82272508(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272678) {
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
	ctx.lr = 0x82272680;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82272508
	ctx.lr = 0x8227268C;
	sub_82272508(ctx, base);
	// lwz r11,4284(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822726c8
	if (cr6.eq) goto loc_822726C8;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// addi r3,r11,-8
	ctx.r3.s64 = r11.s64 + -8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822726c4
	if (cr6.eq) goto loc_822726C4;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822726C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822726c8
	goto loc_822726C8;
loc_822726C4:
	// bl 0x82130588
	ctx.lr = 0x822726C8;
	sub_82130588(ctx, base);
loc_822726C8:
	// lwz r11,4288(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4288);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82272708
	if (cr6.eq) goto loc_82272708;
	// lwz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// addi r29,r11,-8
	r29.s64 = r11.s64 + -8;
	// mulli r10,r9,11824
	ctx.r10.s64 = ctx.r9.s64 * 11824;
	// addic. r31,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r31.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// blt 0x82272700
	if (cr0.lt) goto loc_82272700;
loc_822726EC:
	// addi r30,r30,-11824
	r30.s64 = r30.s64 + -11824;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82297160
	ctx.lr = 0x822726F8;
	sub_82297160(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x822726ec
	if (!cr0.lt) goto loc_822726EC;
loc_82272700:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82272708;
	sub_82130588(ctx, base);
loc_82272708:
	// lwz r31,4292(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4292);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82272724
	if (cr6.eq) goto loc_82272724;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82271540
	ctx.lr = 0x8227271C;
	sub_82271540(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82272724;
	sub_82130588(ctx, base);
loc_82272724:
	// lwz r31,4280(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4280);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227274c
	if (cr6.eq) goto loc_8227274C;
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82272744
	if (cr6.eq) goto loc_82272744;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82272744;
	sub_82130588(ctx, base);
loc_82272744:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8227274C;
	sub_82130588(ctx, base);
loc_8227274C:
	// lwz r3,4304(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4304);
	// bl 0x82130588
	ctx.lr = 0x82272754;
	sub_82130588(ctx, base);
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82272770
	if (cr6.eq) goto loc_82272770;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f91e0
	ctx.lr = 0x82272768;
	sub_824F91E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82272770;
	sub_82130588(ctx, base);
loc_82272770:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227278c
	if (cr6.eq) goto loc_8227278C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fb820
	ctx.lr = 0x82272784;
	sub_824FB820(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8227278C;
	sub_82130588(ctx, base);
loc_8227278C:
	// addis r3,r28,5
	ctx.r3.s64 = r28.s64 + 327680;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// addi r10,r11,-1332
	ctx.r10.s64 = r11.s64 + -1332;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x82271320
	ctx.lr = 0x822727A4;
	sub_82271320(ctx, base);
	// addis r3,r28,5
	ctx.r3.s64 = r28.s64 + 327680;
	// addi r3,r3,25900
	ctx.r3.s64 = ctx.r3.s64 + 25900;
	// bl 0x824ea578
	ctx.lr = 0x822727B0;
	sub_824EA578(ctx, base);
	// addi r3,r28,23592
	ctx.r3.s64 = r28.s64 + 23592;
	// bl 0x821c1ab8
	ctx.lr = 0x822727B8;
	sub_821C1AB8(ctx, base);
	// addi r3,r28,23564
	ctx.r3.s64 = r28.s64 + 23564;
	// bl 0x82130000
	ctx.lr = 0x822727C0;
	sub_82130000(ctx, base);
	// addi r3,r28,13928
	ctx.r3.s64 = r28.s64 + 13928;
	// bl 0x822976f0
	ctx.lr = 0x822727C8;
	sub_822976F0(ctx, base);
	// addi r3,r28,4312
	ctx.r3.s64 = r28.s64 + 4312;
	// bl 0x822976f0
	ctx.lr = 0x822727D0;
	sub_822976F0(ctx, base);
	// addi r3,r28,1184
	ctx.r3.s64 = r28.s64 + 1184;
	// bl 0x824e87b8
	ctx.lr = 0x822727D8;
	sub_824E87B8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82272678) {
	__imp__sub_82272678(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822727E0) {
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
	// addi r9,r11,-1028
	ctx.r9.s64 = r11.s64 + -1028;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82272814
	if (cr6.eq) goto loc_82272814;
	// bl 0x82130588
	ctx.lr = 0x82272810;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82272814:
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

PPC_WEAK_FUNC(sub_822727E0) {
	__imp__sub_822727E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272828) {
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
	// addi r9,r11,-1020
	ctx.r9.s64 = r11.s64 + -1020;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8227285c
	if (cr6.eq) goto loc_8227285C;
	// bl 0x82130588
	ctx.lr = 0x82272858;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8227285C:
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

PPC_WEAK_FUNC(sub_82272828) {
	__imp__sub_82272828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addic. r11,r4,1
	xer.ca = ctx.r4.u32 > 4294967294;
	r11.s64 = ctx.r4.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,8788(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8788, ctx.r3.u32);
	// stw r4,8792(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8792, ctx.r4.u32);
	// beq 0x822728b4
	if (cr0.eq) goto loc_822728B4;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// addi r10,r10,8656
	ctx.r10.s64 = ctx.r10.s64 + 8656;
loc_82272898:
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// bne 0x82272898
	if (!cr0.eq) goto loc_82272898;
loc_822728B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82272870) {
	__imp__sub_82272870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822728BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822728BC) {
	__imp__sub_822728BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822728C0) {
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
	ctx.lr = 0x822728C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r31,r4,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r11,8656
	r30.s64 = r11.s64 + 8656;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r29,r30,4
	r29.s64 = r30.s64 + 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// lwzx r7,r31,r30
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lwzx r10,r31,r29
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// subf r5,r7,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r7.s64;
	// bl 0x826191b8
	ctx.lr = 0x822728F8;
	sub_826191B8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82272918
	if (cr6.eq) goto loc_82272918;
	// lwzx r11,r31,r29
	r11.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lwzx r10,r31,r30
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82272918:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822728C0) {
	__imp__sub_822728C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272924) {
	__imp__sub_82272924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272928) {
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
	ctx.lr = 0x82272930;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r11,r11,8656
	r11.s64 = r11.s64 + 8656;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// subf. r31,r7,r8
	r31.s64 = ctx.r8.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// ble 0x822729b8
	if (!cr0.gt) goto loc_822729B8;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82619268
	ctx.lr = 0x82272970;
	sub_82619268(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822729b8
	if (cr6.eq) goto loc_822729B8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,8788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8788);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822729bc
	if (cr6.eq) goto loc_822729BC;
	// li r11,1
	r11.s64 = 1;
	// lwz r10,92(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// slw r9,r11,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,92(r29)
	PPC_STORE_U32(r29.u32 + 92, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822729B8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822729BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82272928) {
	__imp__sub_82272928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822729C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822729C4) {
	__imp__sub_822729C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822729C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,208
	ctx.r10.s64 = ctx.r3.s64 + 208;
loc_822729D0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822729f4
	if (cr6.eq) goto loc_822729F4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x822729d0
	if (!cr6.eq) goto loc_822729D0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_822729F4:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822729C8) {
	__imp__sub_822729C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822729FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822729FC) {
	__imp__sub_822729FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272A00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// li r11,8
	r11.s64 = 8;
loc_82272A10:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82272a20
	if (cr6.eq) goto loc_82272A20;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_82272A20:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bne 0x82272a10
	if (!cr0.eq) goto loc_82272A10;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82272A00) {
	__imp__sub_82272A00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,26
	r11.s64 = ctx.r4.s64 + 26;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r11,r10,r3
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82272A30) {
	__imp__sub_82272A30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272A44) {
	__imp__sub_82272A44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272A48) {
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
	ctx.lr = 0x82272A50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r11,r28,208
	r11.s64 = r28.s64 + 208;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_82272A64:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beq cr6,0x82272a88
	if (cr6.eq) goto loc_82272A88;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// bne cr6,0x82272a64
	if (!cr6.eq) goto loc_82272A64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82272A88:
	// addi r30,r4,144
	r30.s64 = ctx.r4.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481578
	ctx.lr = 0x82272A94;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82272acc
	if (cr6.eq) goto loc_82272ACC;
	// addi r29,r28,16
	r29.s64 = r28.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824825f0
	ctx.lr = 0x82272AB0;
	sub_824825F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82272acc
	if (cr6.eq) goto loc_82272ACC;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824884a8
	ctx.lr = 0x82272ACC;
	sub_824884A8(ctx, base);
loc_82272ACC:
	// addi r11,r31,26
	r11.s64 = r31.s64 + 26;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// stb r27,5(r11)
	PPC_STORE_U8(r11.u32 + 5, r27.u8);
	// stb r27,6(r11)
	PPC_STORE_U8(r11.u32 + 6, r27.u8);
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82272A48) {
	__imp__sub_82272A48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272AEC) {
	__imp__sub_82272AEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272AF0) {
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
	ctx.lr = 0x82272AF8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r28,r25,8
	r28.s64 = r25.s64 + 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618830
	ctx.lr = 0x82272B14;
	sub_82618830(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,8792(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8792);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82272b84
	if (cr6.eq) goto loc_82272B84;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r24,1
	r24.s64 = 1;
	// addi r31,r10,8656
	r31.s64 = ctx.r10.s64 + 8656;
loc_82272B34:
	// lwz r10,100(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// slw r9,r24,r29
	ctx.r9.u64 = r29.u8 & 0x20 ? 0 : (r24.u32 << (r29.u8 & 0x3F));
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82272b74
	if (cr6.eq) goto loc_82272B74;
	// addi r30,r26,112
	r30.s64 = r26.s64 + 112;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618830
	ctx.lr = 0x82272B58;
	sub_82618830(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// subf r5,r10,r11
	ctx.r5.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x82618af8
	ctx.lr = 0x82272B70;
	sub_82618AF8(ctx, base);
	// lwz r11,8792(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8792);
loc_82272B74:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bne cr6,0x82272b34
	if (!cr6.eq) goto loc_82272B34;
loc_82272B84:
	// lwz r11,100(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// stw r11,204(r26)
	PPC_STORE_U32(r26.u32 + 204, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82272AF0) {
	__imp__sub_82272AF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272B94) {
	__imp__sub_82272B94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272B98) {
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
	ctx.lr = 0x82272BA0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r25,r29,8
	r25.s64 = r29.s64 + 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618830
	ctx.lr = 0x82272BBC;
	sub_82618830(ctx, base);
	// lis r24,-32121
	r24.s64 = -2105081856;
	// li r26,0
	r26.s64 = 0;
	// stw r26,100(r29)
	PPC_STORE_U32(r29.u32 + 100, r26.u32);
	// lwz r11,8792(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 8792);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82272c5c
	if (cr6.eq) goto loc_82272C5C;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r23,r26
	r23.u64 = r26.u64;
	// addi r31,r10,8656
	r31.s64 = ctx.r10.s64 + 8656;
	// li r22,1
	r22.s64 = 1;
	// lis r21,-32121
	r21.s64 = -2105081856;
loc_82272BE8:
	// lwz r10,204(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 204);
	// slw r28,r22,r26
	r28.u64 = r26.u8 & 0x20 ? 0 : (r22.u32 << (r26.u8 & 0x3F));
	// and r9,r28,r10
	ctx.r9.u64 = r28.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82272c48
	if (cr6.eq) goto loc_82272C48;
	// lwz r10,8788(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 8788);
	// add r10,r23,r10
	ctx.r10.u64 = r23.u64 + ctx.r10.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82272c48
	if (cr6.eq) goto loc_82272C48;
	// addi r30,r27,112
	r30.s64 = r27.s64 + 112;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618830
	ctx.lr = 0x82272C20;
	sub_82618830(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// subf r5,r10,r11
	ctx.r5.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x82618c80
	ctx.lr = 0x82272C38;
	sub_82618C80(ctx, base);
	// lwz r9,100(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// or r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 | r28.u64;
	// stw r8,100(r29)
	PPC_STORE_U32(r29.u32 + 100, ctx.r8.u32);
	// lwz r11,8792(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 8792);
loc_82272C48:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r23,r23,16
	r23.s64 = r23.s64 + 16;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// bne cr6,0x82272be8
	if (!cr6.eq) goto loc_82272BE8;
loc_82272C5C:
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82272C64;
	sub_82502300(ctx, base);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,0(r29)
	PPC_STORE_U64(r29.u32 + 0, r11.u64);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82272B98) {
	__imp__sub_82272B98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272C74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272C74) {
	__imp__sub_82272C74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272C78) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82272C80;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// addi r27,r29,8
	r27.s64 = r29.s64 + 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82618830
	ctx.lr = 0x82272C9C;
	sub_82618830(ctx, base);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// stw r28,100(r29)
	PPC_STORE_U32(r29.u32 + 100, r28.u32);
	// lwz r11,8792(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8792);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82272d2c
	if (cr6.eq) goto loc_82272D2C;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r24,r28
	r24.u64 = r28.u64;
	// addi r31,r10,8656
	r31.s64 = ctx.r10.s64 + 8656;
	// li r23,1
	r23.s64 = 1;
	// lis r22,-32121
	r22.s64 = -2105081856;
loc_82272CC8:
	// lwz r10,8788(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 8788);
	// add r10,r24,r10
	ctx.r10.u64 = r24.u64 + ctx.r10.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82272d18
	if (cr6.eq) goto loc_82272D18;
	// addi r30,r25,112
	r30.s64 = r25.s64 + 112;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618830
	ctx.lr = 0x82272CEC;
	sub_82618830(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// subf r5,r10,r11
	ctx.r5.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x82618c80
	ctx.lr = 0x82272D04;
	sub_82618C80(ctx, base);
	// lwz r8,100(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// slw r9,r23,r28
	ctx.r9.u64 = r28.u8 & 0x20 ? 0 : (r23.u32 << (r28.u8 & 0x3F));
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,100(r29)
	PPC_STORE_U32(r29.u32 + 100, ctx.r7.u32);
	// lwz r11,8792(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8792);
loc_82272D18:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bne cr6,0x82272cc8
	if (!cr6.eq) goto loc_82272CC8;
loc_82272D2C:
	// addi r3,r25,16
	ctx.r3.s64 = r25.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82272D34;
	sub_82502300(ctx, base);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,0(r29)
	PPC_STORE_U64(r29.u32 + 0, r11.u64);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82272C78) {
	__imp__sub_82272C78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272D44) {
	__imp__sub_82272D44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272D48) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,112
	ctx.r3.s64 = ctx.r3.s64 + 112;
	// b 0x82272928
	sub_82272928(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82272D48) {
	__imp__sub_82272D48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272D50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// b 0x82131c18
	sub_82131C18(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82272D50) {
	__imp__sub_82272D50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272D6C) {
	__imp__sub_82272D6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272D70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,26
	r11.s64 = ctx.r4.s64 + 26;
	// addi r5,r3,288
	ctx.r5.s64 = ctx.r3.s64 + 288;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// lwzx r11,r10,r3
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// b 0x824884a8
	sub_824884A8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82272D70) {
	__imp__sub_82272D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272D8C) {
	__imp__sub_82272D8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272D90) {
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
	// addi r30,r31,10116
	r30.s64 = r31.s64 + 10116;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ff658
	ctx.lr = 0x82272DB4;
	sub_824FF658(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82272de0
	if (!cr6.eq) goto loc_82272DE0;
	// addi r9,r31,10236
	ctx.r9.s64 = r31.s64 + 10236;
	// addi r8,r31,308
	ctx.r8.s64 = r31.s64 + 308;
	// li r7,50
	ctx.r7.s64 = 50;
	// addi r6,r31,312
	ctx.r6.s64 = r31.s64 + 312;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ff878
	ctx.lr = 0x82272DE0;
	sub_824FF878(ctx, base);
loc_82272DE0:
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

PPC_WEAK_FUNC(sub_82272D90) {
	__imp__sub_82272D90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272DF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10592(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10592);
	// b 0x824ff1f8
	sub_824FF1F8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82272DF8) {
	__imp__sub_82272DF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272E00) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10592(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10592);
	// b 0x824ff100
	sub_824FF100(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82272E00) {
	__imp__sub_82272E00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272E08) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10592(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10592);
	// b 0x824ff010
	sub_824FF010(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82272E08) {
	__imp__sub_82272E08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272E10) {
	PPC_FUNC_PROLOGUE();
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// li r8,2000
	ctx.r8.s64 = 2000;
	// addi r3,r3,10600
	ctx.r3.s64 = ctx.r3.s64 + 10600;
	// b 0x825005b8
	sub_825005B8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82272E10) {
	__imp__sub_82272E10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272E34) {
	__imp__sub_82272E34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272E38) {
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
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82272E4C;
	sub_821F8730(ctx, base);
	// bl 0x824e6d68
	ctx.lr = 0x82272E50;
	sub_824E6D68(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82272E38) {
	__imp__sub_82272E38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272E60) {
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
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x821f8730
	ctx.lr = 0x82272E7C;
	sub_821F8730(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824e6db0
	ctx.lr = 0x82272E84;
	sub_824E6DB0(ctx, base);
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

PPC_WEAK_FUNC(sub_82272E60) {
	__imp__sub_82272E60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272E98) {
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
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82272EAC;
	sub_821F8730(ctx, base);
	// bl 0x824e6e08
	ctx.lr = 0x82272EB0;
	sub_824E6E08(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82272E98) {
	__imp__sub_82272E98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272EC0) {
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
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82272ED4;
	sub_821F8730(ctx, base);
	// bl 0x824e6e50
	ctx.lr = 0x82272ED8;
	sub_824E6E50(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82272EC0) {
	__imp__sub_82272EC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272EE8) {
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
	// addi r3,r4,16
	ctx.r3.s64 = ctx.r4.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82272F08;
	sub_824E7110(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82272F14;
	sub_821F8730(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824e6e98
	ctx.lr = 0x82272F1C;
	sub_824E6E98(ctx, base);
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

PPC_WEAK_FUNC(sub_82272EE8) {
	__imp__sub_82272EE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272F34) {
	__imp__sub_82272F34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272F38) {
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
	// lbz r11,10824(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82272f68
	if (cr6.eq) goto loc_82272F68;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,10820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821326a8
	ctx.lr = 0x82272F68;
	sub_821326A8(ctx, base);
loc_82272F68:
	// li r5,28
	ctx.r5.s64 = 28;
	// lwz r3,10820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x82272F78;
	sub_8244D150(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82272F80;
	sub_821F8730(ctx, base);
	// lis r4,0
	ctx.r4.s64 = 0;
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r7,10820(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// ori r4,r4,65535
	ctx.r4.u64 = ctx.r4.u64 | 65535;
	// lwz r6,10816(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 10816);
	// bl 0x8244a688
	ctx.lr = 0x82272F98;
	sub_8244A688(ctx, base);
	// addi r11,r3,-997
	r11.s64 = ctx.r3.s64 + -997;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,10824(r31)
	PPC_STORE_U8(r31.u32 + 10824, ctx.r9.u8);
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

PPC_WEAK_FUNC(sub_82272F38) {
	__imp__sub_82272F38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82272FBC) {
	__imp__sub_82272FBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82272FC0) {
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
	ctx.lr = 0x82272FC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// lbz r11,10824(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273010
	if (cr6.eq) goto loc_82273010;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,10820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821326a8
	ctx.lr = 0x82273000;
	sub_821326A8(ctx, base);
	// lwz r3,10820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// bl 0x82450030
	ctx.lr = 0x82273008;
	sub_82450030(ctx, base);
	// stb r30,10824(r31)
	PPC_STORE_U8(r31.u32 + 10824, r30.u8);
	// b 0x82273030
	goto loc_82273030;
loc_82273010:
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82273018;
	sub_821F8730(ctx, base);
	// lis r4,0
	ctx.r4.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,10816(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 10816);
	// li r5,8
	ctx.r5.s64 = 8;
	// ori r4,r4,65535
	ctx.r4.u64 = ctx.r4.u64 | 65535;
	// bl 0x8244a688
	ctx.lr = 0x82273030;
	sub_8244A688(ctx, base);
loc_82273030:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82273050
	if (!cr6.eq) goto loc_82273050;
	// lwz r11,10816(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10816);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r9,10816(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10816);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r8.u32);
loc_82273050:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82272FC0) {
	__imp__sub_82272FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273058) {
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
	ctx.lr = 0x82273060;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x826187d0
	ctx.lr = 0x8227307C;
	sub_826187D0(ctx, base);
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bgt cr6,0x822730ec
	if (cr6.gt) goto loc_822730EC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826186f8
	ctx.lr = 0x82273094;
	sub_826186F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822730A0;
	sub_82618830(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822730cc
	if (cr6.eq) goto loc_822730CC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6390
	ctx.lr = 0x822730BC;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822730d0
	if (!cr6.eq) goto loc_822730D0;
loc_822730CC:
	// li r11,0
	r11.s64 = 0;
loc_822730D0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// bl 0x82618718
	ctx.lr = 0x822730E0;
	sub_82618718(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_822730EC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82273058) {
	__imp__sub_82273058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822730F8) {
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
	ctx.lr = 0x82273100;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x82273110;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x82273124;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227315c
	if (cr6.eq) goto loc_8227315C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,10
	ctx.r5.s64 = 10;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x8227314C;
	sub_82618390(ctx, base);
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82273158;
	sub_826188B8(ctx, base);
	// li r29,1
	r29.s64 = 1;
loc_8227315C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822731a0
	if (cr6.eq) goto loc_822731A0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822731a0
	if (cr6.eq) goto loc_822731A0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823eaef8
	ctx.lr = 0x82273178;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618670
	ctx.lr = 0x82273184;
	sub_82618670(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82618bc8
	ctx.lr = 0x82273198;
	sub_82618BC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822731A0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822730F8) {
	__imp__sub_822730F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822731AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822731AC) {
	__imp__sub_822731AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822731B0) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// stb r30,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r30.u8);
	// stb r30,277(r31)
	PPC_STORE_U8(r31.u32 + 277, r30.u8);
	// stb r30,278(r31)
	PPC_STORE_U8(r31.u32 + 278, r30.u8);
	// stb r30,279(r31)
	PPC_STORE_U8(r31.u32 + 279, r30.u8);
	// stb r30,280(r31)
	PPC_STORE_U8(r31.u32 + 280, r30.u8);
	// stb r30,281(r31)
	PPC_STORE_U8(r31.u32 + 281, r30.u8);
	// stb r30,282(r31)
	PPC_STORE_U8(r31.u32 + 282, r30.u8);
	// bl 0x82618780
	ctx.lr = 0x822731F0;
	sub_82618780(ctx, base);
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e6f20
	ctx.lr = 0x822731FC;
	sub_824E6F20(ctx, base);
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

PPC_WEAK_FUNC(sub_822731B0) {
	__imp__sub_822731B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82273214) {
	__imp__sub_82273214(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273218) {
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
	// bl 0x82618750
	ctx.lr = 0x82273230;
	sub_82618750(ctx, base);
	// addi r4,r31,28
	ctx.r4.s64 = r31.s64 + 28;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x82618640
	ctx.lr = 0x82273240;
	sub_82618640(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,8656
	ctx.r8.s64 = ctx.r9.s64 + 8656;
	// lwz r11,8792(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8792);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x826189a8
	ctx.lr = 0x82273268;
	sub_826189A8(ctx, base);
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

PPC_WEAK_FUNC(sub_82273218) {
	__imp__sub_82273218(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273280) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82273288;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-1020
	ctx.r10.s64 = r11.s64 + -1020;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e6310
	ctx.lr = 0x822732A4;
	sub_824E6310(ctx, base);
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e71c8
	ctx.lr = 0x822732B0;
	sub_824E71C8(ctx, base);
	// addi r29,r31,112
	r29.s64 = r31.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82618750
	ctx.lr = 0x822732BC;
	sub_82618750(ctx, base);
	// addi r4,r29,28
	ctx.r4.s64 = r29.s64 + 28;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x82618640
	ctx.lr = 0x822732CC;
	sub_82618640(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r7,r8,8656
	ctx.r7.s64 = ctx.r8.s64 + 8656;
	// lwz r11,8792(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8792);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// bl 0x826189a8
	ctx.lr = 0x822732F4;
	sub_826189A8(ctx, base);
	// stw r30,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r30.u32);
	// addi r11,r31,214
	r11.s64 = r31.s64 + 214;
	// stb r30,213(r31)
	PPC_STORE_U8(r31.u32 + 213, r30.u8);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// stb r30,221(r31)
	PPC_STORE_U8(r31.u32 + 221, r30.u8);
	// stw r30,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r30.u32);
	// stb r30,229(r31)
	PPC_STORE_U8(r31.u32 + 229, r30.u8);
	// stw r30,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r30.u32);
	// stb r30,237(r31)
	PPC_STORE_U8(r31.u32 + 237, r30.u8);
	// stw r30,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r30.u32);
	// stb r30,245(r31)
	PPC_STORE_U8(r31.u32 + 245, r30.u8);
	// stw r30,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r30.u32);
	// stb r30,253(r31)
	PPC_STORE_U8(r31.u32 + 253, r30.u8);
	// stw r30,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r30.u32);
	// stb r30,261(r31)
	PPC_STORE_U8(r31.u32 + 261, r30.u8);
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// stb r30,269(r31)
	PPC_STORE_U8(r31.u32 + 269, r30.u8);
loc_8227333C:
	// stb r30,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r30.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// stw r30,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, r30.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8227333c
	if (!cr0.eq) goto loc_8227333C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82618780
	ctx.lr = 0x8227335C;
	sub_82618780(ctx, base);
	// stw r30,92(r29)
	PPC_STORE_U32(r29.u32 + 92, r30.u32);
	// stb r30,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r30.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,277(r31)
	PPC_STORE_U8(r31.u32 + 277, r30.u8);
	// stb r30,278(r31)
	PPC_STORE_U8(r31.u32 + 278, r30.u8);
	// stb r30,279(r31)
	PPC_STORE_U8(r31.u32 + 279, r30.u8);
	// stb r30,280(r31)
	PPC_STORE_U8(r31.u32 + 280, r30.u8);
	// stb r30,281(r31)
	PPC_STORE_U8(r31.u32 + 281, r30.u8);
	// stb r30,282(r31)
	PPC_STORE_U8(r31.u32 + 282, r30.u8);
	// bl 0x82618780
	ctx.lr = 0x82273384;
	sub_82618780(ctx, base);
	// stw r30,92(r29)
	PPC_STORE_U32(r29.u32 + 92, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e6f20
	ctx.lr = 0x82273390;
	sub_824E6F20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82273280) {
	__imp__sub_82273280(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227339C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227339C) {
	__imp__sub_8227339C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822733A0) {
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
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x824e6f80
	ctx.lr = 0x822733C0;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273498
	if (cr6.eq) goto loc_82273498;
	// li r11,0
	r11.s64 = 0;
	// addi r31,r30,10116
	r31.s64 = r30.s64 + 10116;
	// stw r11,304(r30)
	PPC_STORE_U32(r30.u32 + 304, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ff658
	ctx.lr = 0x822733E0;
	sub_824FF658(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82273408
	if (cr6.eq) goto loc_82273408;
loc_822733EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x822733F4;
	sub_821C91B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ff658
	ctx.lr = 0x822733FC;
	sub_824FF658(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822733ec
	if (!cr6.eq) goto loc_822733EC;
loc_82273408:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ff600
	ctx.lr = 0x82273410;
	sub_824FF600(ctx, base);
	// addi r31,r30,10264
	r31.s64 = r30.s64 + 10264;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ffa78
	ctx.lr = 0x8227341C;
	sub_824FFA78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273444
	if (cr6.eq) goto loc_82273444;
loc_82273428:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82273430;
	sub_821C91B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ffa78
	ctx.lr = 0x82273438;
	sub_824FFA78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82273428
	if (!cr6.eq) goto loc_82273428;
loc_82273444:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ffa18
	ctx.lr = 0x8227344C;
	sub_824FFA18(ctx, base);
	// addi r31,r30,10600
	r31.s64 = r30.s64 + 10600;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82500428
	ctx.lr = 0x82273458;
	sub_82500428(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273480
	if (cr6.eq) goto loc_82273480;
loc_82273464:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x8227346C;
	sub_821C91B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82500428
	ctx.lr = 0x82273474;
	sub_82500428(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82273464
	if (!cr6.eq) goto loc_82273464;
loc_82273480:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825003d0
	ctx.lr = 0x82273488;
	sub_825003D0(ctx, base);
	// lwz r3,10592(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 10592);
	// bl 0x824febf0
	ctx.lr = 0x82273490;
	sub_824FEBF0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822731b0
	ctx.lr = 0x82273498;
	sub_822731B0(ctx, base);
loc_82273498:
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

PPC_WEAK_FUNC(sub_822733A0) {
	__imp__sub_822733A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822734B0) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82273500
	if (cr6.eq) goto loc_82273500;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x822734D4;
	sub_821F8730(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r11,5
	ctx.r3.s64 = r11.s64 + 327680;
	// addi r3,r3,25900
	ctx.r3.s64 = ctx.r3.s64 + 25900;
	// bl 0x824ea488
	ctx.lr = 0x822734F0;
	sub_824EA488(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82273504
	if (!cr6.eq) goto loc_82273504;
loc_82273500:
	// li r11,0
	r11.s64 = 0;
loc_82273504:
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

PPC_WEAK_FUNC(sub_822734B0) {
	__imp__sub_822734B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227351C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227351C) {
	__imp__sub_8227351C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273520) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82273570
	if (cr6.eq) goto loc_82273570;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82273544;
	sub_821F8730(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r11,5
	ctx.r3.s64 = r11.s64 + 327680;
	// addi r3,r3,25900
	ctx.r3.s64 = ctx.r3.s64 + 25900;
	// bl 0x824ea500
	ctx.lr = 0x82273560;
	sub_824EA500(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82273574
	if (!cr6.eq) goto loc_82273574;
loc_82273570:
	// li r11,0
	r11.s64 = 0;
loc_82273574:
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

PPC_WEAK_FUNC(sub_82273520) {
	__imp__sub_82273520(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227358C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227358C) {
	__imp__sub_8227358C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273590) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r3,208
	ctx.r9.s64 = ctx.r3.s64 + 208;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_822735AC:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822735e0
	if (cr6.eq) goto loc_822735E0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x822735ac
	if (!cr6.eq) goto loc_822735AC;
loc_822735C8:
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
loc_822735E0:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822735c8
	if (cr6.eq) goto loc_822735C8;
	// addi r11,r11,26
	r11.s64 = r11.s64 + 26;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r11,r3
	r31.u64 = r11.u64 + ctx.r3.u64;
	// stwx r10,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r10.u32);
	// stb r10,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r10.u8);
	// stb r10,6(r31)
	PPC_STORE_U8(r31.u32 + 6, ctx.r10.u8);
	// lwz r3,-10240(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// bl 0x82270220
	ctx.lr = 0x8227360C;
	sub_82270220(ctx, base);
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

PPC_WEAK_FUNC(sub_82273590) {
	__imp__sub_82273590(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82273624) {
	__imp__sub_82273624(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273628) {
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
	ctx.lr = 0x82273630;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824e6278
	ctx.lr = 0x82273648;
	sub_824E6278(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r27,r29,16
	r27.s64 = r29.s64 + 16;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r25,r11,1
	r25.s64 = r11.s64 + 1;
	// bl 0x824e70e0
	ctx.lr = 0x82273668;
	sub_824E70E0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822736f0
	if (cr6.eq) goto loc_822736F0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227367C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82273690
	if (!cr6.eq) goto loc_82273690;
	// cmpwi cr6,r25,1
	cr6.compare<int32_t>(r25.s32, 1, xer);
	// beq cr6,0x822736f0
	if (cr6.eq) goto loc_822736F0;
loc_82273690:
	// lwz r11,304(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 304);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822736f0
	if (!cr6.eq) goto loc_822736F0;
	// lwz r11,288(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 288);
	// addi r26,r29,288
	r26.s64 = r29.s64 + 288;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822736f0
	if (cr6.eq) goto loc_822736F0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82273590
	ctx.lr = 0x822736BC;
	sub_82273590(ctx, base);
	// lwz r11,608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// rlwinm r28,r10,27,31,31
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// beq cr6,0x822736f0
	if (cr6.eq) goto loc_822736F0;
	// bl 0x82296f70
	ctx.lr = 0x822736D8;
	sub_82296F70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x822736fc
	if (!cr6.eq) goto loc_822736FC;
loc_822736E4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82272a48
	ctx.lr = 0x822736F0;
	sub_82272A48(ctx, base);
loc_822736F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_822736FC:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82297030
	ctx.lr = 0x82273708;
	sub_82297030(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// cntlzw r11,r8
	r11.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r7,608(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r30,144
	ctx.r3.s64 = r30.s64 + 144;
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// bl 0x82486280
	ctx.lr = 0x82273744;
	sub_82486280(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822736e4
	if (cr6.eq) goto loc_822736E4;
	// stw r30,304(r29)
	PPC_STORE_U32(r29.u32 + 304, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82273628) {
	__imp__sub_82273628(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273760) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82273768;
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r26,r29,16
	r26.s64 = r29.s64 + 16;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227378C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273870
	if (cr6.eq) goto loc_82273870;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824e70f0
	ctx.lr = 0x822737A0;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822737b8
	if (!cr6.eq) goto loc_822737B8;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273870
	if (cr6.eq) goto loc_82273870;
loc_822737B8:
	// lwz r11,304(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 304);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82273870
	if (!cr6.eq) goto loc_82273870;
	// lwz r11,288(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 288);
	// addi r23,r29,288
	r23.s64 = r29.s64 + 288;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82273870
	if (cr6.eq) goto loc_82273870;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// li r28,0
	r28.s64 = 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r25,r11,1
	r25.s64 = r11.s64 + 1;
	// beq cr6,0x822737fc
	if (cr6.eq) goto loc_822737FC;
	// mr r27,r28
	r27.u64 = r28.u64;
	// b 0x8227380c
	goto loc_8227380C;
loc_822737FC:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r27,r9,1
	r27.u64 = ctx.r9.u64 ^ 1;
loc_8227380C:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x824ea838
	ctx.lr = 0x82273820;
	sub_824EA838(ctx, base);
	// bl 0x824f88f8
	ctx.lr = 0x82273824;
	sub_824F88F8(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824ea3b8
	ctx.lr = 0x82273838;
	sub_824EA3B8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82273590
	ctx.lr = 0x82273848;
	sub_82273590(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82273870
	if (cr6.eq) goto loc_82273870;
	// bl 0x82296f70
	ctx.lr = 0x82273858;
	sub_82296F70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x8227387c
	if (!cr6.eq) goto loc_8227387C;
loc_82273864:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82272a48
	ctx.lr = 0x82273870;
	sub_82272A48(ctx, base);
loc_82273870:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// b 0x823d9230
	return;
loc_8227387C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82297030
	ctx.lr = 0x82273888;
	sub_82297030(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-992
	ctx.r4.s64 = ctx.r10.s64 + -992;
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x82294f78
	ctx.lr = 0x8227389C;
	sub_82294F78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e9690
	ctx.lr = 0x822738B0;
	sub_824E9690(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,-1004
	ctx.r4.s64 = ctx.r9.s64 + -1004;
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x82294f78
	ctx.lr = 0x822738C4;
	sub_82294F78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e9690
	ctx.lr = 0x822738D8;
	sub_824E9690(ctx, base);
	// lwz r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r6,116(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// addi r4,r8,-1016
	ctx.r4.s64 = ctx.r8.s64 + -1016;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x82294f78
	ctx.lr = 0x822738FC;
	sub_82294F78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e9530
	ctx.lr = 0x82273910;
	sub_824E9530(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x822950f8
	ctx.lr = 0x82273920;
	sub_822950F8(ctx, base);
	// clrlwi r4,r24,24
	ctx.r4.u64 = r24.u32 & 0xFF;
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// lwz r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// stw r23,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r23.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// rlwinm r6,r3,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r30,144
	ctx.r3.s64 = r30.s64 + 144;
	// bl 0x824860e8
	ctx.lr = 0x82273958;
	sub_824860E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273864
	if (cr6.eq) goto loc_82273864;
	// stw r30,304(r29)
	PPC_STORE_U32(r29.u32 + 304, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82273760) {
	__imp__sub_82273760(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82273974) {
	__imp__sub_82273974(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273978) {
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
	ctx.lr = 0x82273980;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,10252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 10252);
	// bl 0x8229a100
	ctx.lr = 0x82273990;
	sub_8229A100(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822739dc
	if (cr6.eq) goto loc_822739DC;
	// addi r31,r29,16
	r31.s64 = r29.s64 + 16;
	// lwz r3,10252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 10252);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8229a180
	ctx.lr = 0x822739AC;
	sub_8229A180(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x822739B4;
	sub_821F8730(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r6,r29,80
	ctx.r6.s64 = r29.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// bl 0x824e8668
	ctx.lr = 0x822739D0;
	sub_824E8668(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822739DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82273978) {
	__imp__sub_82273978(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822739E8) {
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
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82273A18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,5
	cr6.compare<uint32_t>(ctx.r3.u32, 5, xer);
	// bne cr6,0x82273a44
	if (!cr6.eq) goto loc_82273A44;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82273A28;
	sub_821F8730(ctx, base);
	// bl 0x824e6d68
	ctx.lr = 0x82273A2C;
	sub_824E6D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273a44
	if (cr6.eq) goto loc_82273A44;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,10252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 10252);
	// bl 0x8229a888
	ctx.lr = 0x82273A44;
	sub_8229A888(ctx, base);
loc_82273A44:
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

PPC_WEAK_FUNC(sub_822739E8) {
	__imp__sub_822739E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82273A5C) {
	__imp__sub_82273A5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273A60) {
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
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,8916(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8916);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82273ac0
	if (!cr6.eq) goto loc_82273AC0;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r11,8916(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8916, r11.u32);
	// addi r31,r9,8892
	r31.s64 = ctx.r9.s64 + 8892;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa970
	ctx.lr = 0x82273A9C;
	sub_824FA970(ctx, base);
	// lis r8,-32132
	ctx.r8.s64 = -2105802752;
	// addi r3,r8,-29496
	ctx.r3.s64 = ctx.r8.s64 + -29496;
	// bl 0x823d9a98
	ctx.lr = 0x82273AA8;
	sub_823D9A98(ctx, base);
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
loc_82273AC0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,8892
	ctx.r3.s64 = r11.s64 + 8892;
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

PPC_WEAK_FUNC(sub_82273A60) {
	__imp__sub_82273A60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82273ADC) {
	__imp__sub_82273ADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273AE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x82273b30
	if (!cr6.eq) goto loc_82273B30;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,96(r4)
	PPC_STORE_U32(ctx.r4.u32 + 96, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82273b1c
	if (cr6.eq) goto loc_82273B1C;
	// stw r11,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_82273B1C:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_82273B30:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x82273b6c
	if (!cr6.eq) goto loc_82273B6C;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82273b90
	if (cr6.eq) goto loc_82273B90;
	// stw r11,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_82273B6C:
	// lwz r10,100(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,96(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	// stw r9,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, ctx.r9.u32);
	// lwz r8,96(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	// lwz r7,100(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// stw r7,100(r8)
	PPC_STORE_U32(ctx.r8.u32 + 100, ctx.r7.u32);
	// stw r11,96(r4)
	PPC_STORE_U32(ctx.r4.u32 + 96, r11.u32);
	// stw r11,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, r11.u32);
loc_82273B90:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82273AE0) {
	__imp__sub_82273AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273BA0) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x822730f8
	ctx.lr = 0x82273BC8;
	sub_822730F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273c10
	if (cr6.eq) goto loc_82273C10;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82273BE4;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273c10
	if (cr6.eq) goto loc_82273C10;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r30,100
	ctx.r4.s64 = r30.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82273C00;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82273c14
	if (!cr6.eq) goto loc_82273C14;
loc_82273C10:
	// li r11,0
	r11.s64 = 0;
loc_82273C14:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82273BA0) {
	__imp__sub_82273BA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273C30) {
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
	ctx.lr = 0x82273C38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x826187d0
	ctx.lr = 0x82273C54;
	sub_826187D0(ctx, base);
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bgt cr6,0x82273cc4
	if (cr6.gt) goto loc_82273CC4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826186f8
	ctx.lr = 0x82273C6C;
	sub_826186F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82273C78;
	sub_82618830(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273ca4
	if (cr6.eq) goto loc_82273CA4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275750
	ctx.lr = 0x82273C94;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82273ca8
	if (!cr6.eq) goto loc_82273CA8;
loc_82273CA4:
	// li r11,0
	r11.s64 = 0;
loc_82273CA8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// bl 0x82618738
	ctx.lr = 0x82273CB8;
	sub_82618738(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82273CC4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82273C30) {
	__imp__sub_82273C30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273CD0) {
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
	ctx.lr = 0x82273CD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x826187d0
	ctx.lr = 0x82273CF4;
	sub_826187D0(ctx, base);
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bgt cr6,0x82273d64
	if (cr6.gt) goto loc_82273D64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826186f8
	ctx.lr = 0x82273D0C;
	sub_826186F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82273D18;
	sub_82618830(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273d44
	if (cr6.eq) goto loc_82273D44;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226b338
	ctx.lr = 0x82273D34;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82273d48
	if (!cr6.eq) goto loc_82273D48;
loc_82273D44:
	// li r11,0
	r11.s64 = 0;
loc_82273D48:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// bl 0x82618718
	ctx.lr = 0x82273D58;
	sub_82618718(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82273D64:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82273CD0) {
	__imp__sub_82273CD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273D70) {
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
	ctx.lr = 0x82273D78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x826187d0
	ctx.lr = 0x82273D94;
	sub_826187D0(ctx, base);
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bgt cr6,0x82273e04
	if (cr6.gt) goto loc_82273E04;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826186f8
	ctx.lr = 0x82273DAC;
	sub_826186F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82273DB8;
	sub_82618830(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273de4
	if (cr6.eq) goto loc_82273DE4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x82273DD4;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82273de8
	if (!cr6.eq) goto loc_82273DE8;
loc_82273DE4:
	// li r11,0
	r11.s64 = 0;
loc_82273DE8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// bl 0x82618738
	ctx.lr = 0x82273DF8;
	sub_82618738(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82273E04:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82273D70) {
	__imp__sub_82273D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273E10) {
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
	ctx.lr = 0x82273E18;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x82273E3C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82273E48;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82273E58;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82273e7c
	if (cr6.eq) goto loc_82273E7C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82273ba0
	ctx.lr = 0x82273E6C;
	sub_82273BA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82273e80
	if (!cr6.eq) goto loc_82273E80;
loc_82273E7C:
	// li r30,0
	r30.s64 = 0;
loc_82273E80:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82273eb8
	if (cr6.eq) goto loc_82273EB8;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273eb0
	if (cr6.eq) goto loc_82273EB0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82273E9C;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82273EB0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82273EB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82273E10) {
	__imp__sub_82273E10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82273EC4) {
	__imp__sub_82273EC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273EC8) {
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
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,8656
	r11.s64 = r11.s64 + 8656;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwzx r5,r10,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// bl 0x82273c30
	ctx.lr = 0x82273F04;
	sub_82273C30(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82273EC8) {
	__imp__sub_82273EC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273F18) {
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
	ctx.lr = 0x82273F20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r11,8656
	r30.s64 = r11.s64 + 8656;
	// rlwinm r29,r26,2,0,29
	r29.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r30,4
	ctx.r9.s64 = r30.s64 + 4;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwzx r6,r29,r30
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwzx r8,r29,r9
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// subf r28,r6,r8
	r28.s64 = ctx.r8.s64 - ctx.r6.s64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82273c30
	ctx.lr = 0x82273F60;
	sub_82273C30(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r7,r31
	cr6.compare<int32_t>(ctx.r7.s32, r31.s32, xer);
	// beq cr6,0x82273fe8
	if (cr6.eq) goto loc_82273FE8;
	// li r25,1
	r25.s64 = 1;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// slw r11,r25,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r25.u32 << (r11.u8 & 0x3F));
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bgt cr6,0x82273fe8
	if (cr6.gt) goto loc_82273FE8;
	// subfic r11,r11,-1
	xer.ca = r11.u32 <= 4294967295;
	r11.s64 = -1 - r11.s64;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82273fe8
	if (cr6.lt) goto loc_82273FE8;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwzx r6,r29,r30
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82273cd0
	ctx.lr = 0x82273FA4;
	sub_82273CD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82273fe8
	if (cr6.eq) goto loc_82273FE8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r26,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,8788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8788);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82273fdc
	if (cr6.eq) goto loc_82273FDC;
	// lwz r11,92(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 92);
	// slw r10,r25,r26
	ctx.r10.u64 = r26.u8 & 0x20 ? 0 : (r25.u32 << (r26.u8 & 0x3F));
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// stw r9,92(r27)
	PPC_STORE_U32(r27.u32 + 92, ctx.r9.u32);
loc_82273FDC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82273FE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82273F18) {
	__imp__sub_82273F18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82273FF4) {
	__imp__sub_82273FF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82273FF8) {
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
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,8656
	r11.s64 = r11.s64 + 8656;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwzx r5,r10,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// bl 0x82273d70
	ctx.lr = 0x82274034;
	sub_82273D70(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82273FF8) {
	__imp__sub_82273FF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274048) {
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
	ctx.lr = 0x82274050;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r11,8656
	r30.s64 = r11.s64 + 8656;
	// rlwinm r29,r26,2,0,29
	r29.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r30,4
	ctx.r9.s64 = r30.s64 + 4;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwzx r6,r29,r30
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwzx r8,r29,r9
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// subf r27,r6,r8
	r27.s64 = ctx.r8.s64 - ctx.r6.s64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82273d70
	ctx.lr = 0x82274090;
	sub_82273D70(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r7,r31
	cr6.compare<uint32_t>(ctx.r7.u32, r31.u32, xer);
	// beq cr6,0x82274110
	if (cr6.eq) goto loc_82274110;
	// addi r11,r27,-1
	r11.s64 = r27.s64 + -1;
	// li r25,1
	r25.s64 = 1;
	// slw r10,r25,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (r25.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bgt cr6,0x82274110
	if (cr6.gt) goto loc_82274110;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwzx r6,r29,r30
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82273058
	ctx.lr = 0x822740CC;
	sub_82273058(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274110
	if (cr6.eq) goto loc_82274110;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r26,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,8788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8788);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82274104
	if (cr6.eq) goto loc_82274104;
	// lwz r11,92(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 92);
	// slw r10,r25,r26
	ctx.r10.u64 = r26.u8 & 0x20 ? 0 : (r25.u32 << (r26.u8 & 0x3F));
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// stw r9,92(r28)
	PPC_STORE_U32(r28.u32 + 92, ctx.r9.u32);
loc_82274104:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82274110:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82274048) {
	__imp__sub_82274048(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227411C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227411C) {
	__imp__sub_8227411C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274120) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,112
	ctx.r3.s64 = ctx.r3.s64 + 112;
	// b 0x82273f18
	sub_82273F18(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82274120) {
	__imp__sub_82274120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274128) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,112
	ctx.r3.s64 = ctx.r3.s64 + 112;
	// b 0x82274048
	sub_82274048(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82274128) {
	__imp__sub_82274128(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274130) {
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
	ctx.lr = 0x82274138;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6f80
	ctx.lr = 0x8227414C;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274164
	if (!cr6.eq) goto loc_82274164;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82274164:
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6f80
	ctx.lr = 0x82274170;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822741a8
	if (cr6.eq) goto loc_822741A8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6f80
	ctx.lr = 0x82274184;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822741a8
	if (cr6.eq) goto loc_822741A8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7120
	ctx.lr = 0x8227419C;
	sub_824E7120(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274210
	if (!cr6.eq) goto loc_82274210;
loc_822741A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822733a0
	ctx.lr = 0x822741B0;
	sub_822733A0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// stw r11,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r11.u32);
	// addi r3,r31,10116
	ctx.r3.s64 = r31.s64 + 10116;
	// stb r11,10112(r31)
	PPC_STORE_U8(r31.u32 + 10112, r11.u8);
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824ff5a8
	ctx.lr = 0x822741D0;
	sub_824FF5A8(ctx, base);
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// addi r3,r31,10264
	ctx.r3.s64 = r31.s64 + 10264;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824ff9a0
	ctx.lr = 0x822741E0;
	sub_824FF9A0(ctx, base);
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// addi r3,r31,10600
	ctx.r3.s64 = r31.s64 + 10600;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82500360
	ctx.lr = 0x822741F0;
	sub_82500360(ctx, base);
	// lwz r3,10592(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10592);
	// bl 0x824fded8
	ctx.lr = 0x822741F8;
	sub_824FDED8(ctx, base);
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82274208;
	sub_823DA950(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272f38
	ctx.lr = 0x82274210;
	sub_82272F38(ctx, base);
loc_82274210:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82274130) {
	__imp__sub_82274130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227421C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227421C) {
	__imp__sub_8227421C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274220) {
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
	ctx.lr = 0x82274228;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,8796
	ctx.r10.s64 = r11.s64 + 8796;
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
	// bl 0x82275ca8
	ctx.lr = 0x8227425C;
	sub_82275CA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82274294
	if (cr6.eq) goto loc_82274294;
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
	ctx.lr = 0x82274284;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82274298
	if (!cr6.eq) goto loc_82274298;
loc_82274294:
	// li r11,0
	r11.s64 = 0;
loc_82274298:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82274220) {
	__imp__sub_82274220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822742A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822742A4) {
	__imp__sub_822742A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822742A8) {
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
	ctx.lr = 0x822742B0;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,8828
	ctx.r10.s64 = r11.s64 + 8828;
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
	// bl 0x82275ca8
	ctx.lr = 0x822742E4;
	sub_82275CA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227431c
	if (cr6.eq) goto loc_8227431C;
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
	ctx.lr = 0x8227430C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82274320
	if (!cr6.eq) goto loc_82274320;
loc_8227431C:
	// li r11,0
	r11.s64 = 0;
loc_82274320:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822742A8) {
	__imp__sub_822742A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227432C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227432C) {
	__imp__sub_8227432C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274330) {
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
	ctx.lr = 0x82274338;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82273280
	ctx.lr = 0x82274344;
	sub_82273280(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-972
	ctx.r10.s64 = r11.s64 + -972;
	// addi r28,r31,312
	r28.s64 = r31.s64 + 312;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r29,49
	r29.s64 = 49;
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// stw r30,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r30.u32);
	// stw r30,296(r31)
	PPC_STORE_U32(r31.u32 + 296, r30.u32);
	// stw r30,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r30.u32);
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
	// stw r30,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r30.u32);
loc_82274374:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825006b8
	ctx.lr = 0x8227437C;
	sub_825006B8(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,196
	r28.s64 = r28.s64 + 196;
	// bge 0x82274374
	if (!cr0.lt) goto loc_82274374;
	// stb r30,10112(r31)
	PPC_STORE_U8(r31.u32 + 10112, r30.u8);
	// addi r3,r31,10116
	ctx.r3.s64 = r31.s64 + 10116;
	// bl 0x824ff7d0
	ctx.lr = 0x82274394;
	sub_824FF7D0(ctx, base);
	// stw r30,10236(r31)
	PPC_STORE_U32(r31.u32 + 10236, r30.u32);
	// stw r30,10240(r31)
	PPC_STORE_U32(r31.u32 + 10240, r30.u32);
	// li r3,2112
	ctx.r3.s64 = 2112;
	// stw r30,10244(r31)
	PPC_STORE_U32(r31.u32 + 10244, r30.u32);
	// stw r30,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822743AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822743bc
	if (cr6.eq) goto loc_822743BC;
	// bl 0x8229a428
	ctx.lr = 0x822743B8;
	sub_8229A428(ctx, base);
	// b 0x822743c0
	goto loc_822743C0;
loc_822743BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822743C0:
	// stw r3,10252(r31)
	PPC_STORE_U32(r31.u32 + 10252, ctx.r3.u32);
	// addi r3,r31,10264
	ctx.r3.s64 = r31.s64 + 10264;
	// stw r30,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r30.u32);
	// sth r30,10260(r31)
	PPC_STORE_U16(r31.u32 + 10260, r30.u16);
	// sth r30,10262(r31)
	PPC_STORE_U16(r31.u32 + 10262, r30.u16);
	// bl 0x824ff928
	ctx.lr = 0x822743D8;
	sub_824FF928(ctx, base);
	// stw r30,10584(r31)
	PPC_STORE_U32(r31.u32 + 10584, r30.u32);
	// stw r30,10588(r31)
	PPC_STORE_U32(r31.u32 + 10588, r30.u32);
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x82130528
	ctx.lr = 0x822743E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822743f8
	if (cr6.eq) goto loc_822743F8;
	// bl 0x824fef88
	ctx.lr = 0x822743F4;
	sub_824FEF88(ctx, base);
	// b 0x822743fc
	goto loc_822743FC;
loc_822743F8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822743FC:
	// stw r3,10592(r31)
	PPC_STORE_U32(r31.u32 + 10592, ctx.r3.u32);
	// addi r3,r31,10600
	ctx.r3.s64 = r31.s64 + 10600;
	// bl 0x825004d0
	ctx.lr = 0x82274408;
	sub_825004D0(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82274410;
	sub_82130528(ctx, base);
	// stw r3,10816(r31)
	PPC_STORE_U32(r31.u32 + 10816, ctx.r3.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8227441C;
	sub_82130528(ctx, base);
	// stw r3,10820(r31)
	PPC_STORE_U32(r31.u32 + 10820, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,10824(r31)
	PPC_STORE_U8(r31.u32 + 10824, r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82274330) {
	__imp__sub_82274330(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274430) {
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
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r3,10256
	ctx.r3.s64 = ctx.r3.s64 + 10256;
	// bl 0x8262e420
	ctx.lr = 0x82274450;
	sub_8262E420(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
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

PPC_WEAK_FUNC(sub_82274430) {
	__imp__sub_82274430(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274468) {
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
	// beq cr6,0x822744a8
	if (cr6.eq) goto loc_822744A8;
loc_82274488:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8227449c
	if (cr6.eq) goto loc_8227449C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82273ae0
	ctx.lr = 0x8227449C;
	sub_82273AE0(ctx, base);
loc_8227449C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274488
	if (!cr6.eq) goto loc_82274488;
loc_822744A8:
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

PPC_WEAK_FUNC(sub_82274468) {
	__imp__sub_82274468(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822744BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822744BC) {
	__imp__sub_822744BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822744C0) {
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
	ctx.lr = 0x822744C8;
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
	// blt cr6,0x82274534
	if (cr6.lt) goto loc_82274534;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x822744F0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274514
	if (!cr6.eq) goto loc_82274514;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x82274508;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274534
	if (cr6.eq) goto loc_82274534;
loc_82274514:
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
	// bl 0x82274220
	ctx.lr = 0x8227452C;
	sub_82274220(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82274534:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822744C0) {
	__imp__sub_822744C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274540) {
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
	ctx.lr = 0x82274548;
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
	// blt cr6,0x822745b4
	if (cr6.lt) goto loc_822745B4;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x82274570;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274594
	if (!cr6.eq) goto loc_82274594;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x82274588;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822745b4
	if (cr6.eq) goto loc_822745B4;
loc_82274594:
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
	// bl 0x822742a8
	ctx.lr = 0x822745AC;
	sub_822742A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822745B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82274540) {
	__imp__sub_82274540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822745C0) {
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
	ctx.lr = 0x822745C8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,8860
	ctx.r10.s64 = r11.s64 + 8860;
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
	// bl 0x82273e10
	ctx.lr = 0x822745FC;
	sub_82273E10(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82274634
	if (cr6.eq) goto loc_82274634;
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
	ctx.lr = 0x82274624;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82274638
	if (!cr6.eq) goto loc_82274638;
loc_82274634:
	// li r11,0
	r11.s64 = 0;
loc_82274638:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822745C0) {
	__imp__sub_822745C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274644) {
	__imp__sub_82274644(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274648) {
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
	ctx.lr = 0x82274650;
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
	ctx.lr = 0x82274678;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822746ac
	if (cr6.eq) goto loc_822746AC;
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
	// beq cr6,0x822746a4
	if (cr6.eq) goto loc_822746A4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x822746ac
	if (!cr6.eq) goto loc_822746AC;
loc_822746A4:
	// li r11,1
	r11.s64 = 1;
	// b 0x822746b0
	goto loc_822746B0;
loc_822746AC:
	// li r11,0
	r11.s64 = 0;
loc_822746B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822746ec
	if (cr6.eq) goto loc_822746EC;
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
	// bl 0x822744c0
	ctx.lr = 0x822746E4;
	sub_822744C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822746EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82274648) {
	__imp__sub_82274648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822746F8) {
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
	ctx.lr = 0x82274700;
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
	ctx.lr = 0x82274728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227475c
	if (cr6.eq) goto loc_8227475C;
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
	// beq cr6,0x82274754
	if (cr6.eq) goto loc_82274754;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227475c
	if (!cr6.eq) goto loc_8227475C;
loc_82274754:
	// li r11,1
	r11.s64 = 1;
	// b 0x82274760
	goto loc_82274760;
loc_8227475C:
	// li r11,0
	r11.s64 = 0;
loc_82274760:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227479c
	if (cr6.eq) goto loc_8227479C;
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
	// bl 0x82274540
	ctx.lr = 0x82274794;
	sub_82274540(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227479C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822746F8) {
	__imp__sub_822746F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822747A8) {
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
	ctx.lr = 0x822747B0;
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
	// blt cr6,0x8227481c
	if (cr6.lt) goto loc_8227481C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x822747D8;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822747fc
	if (!cr6.eq) goto loc_822747FC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x822747F0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227481c
	if (cr6.eq) goto loc_8227481C;
loc_822747FC:
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
	// bl 0x822745c0
	ctx.lr = 0x82274814;
	sub_822745C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227481C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822747A8) {
	__imp__sub_822747A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274828) {
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
	// lbz r10,281(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 281);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82274888
	if (cr6.eq) goto loc_82274888;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r4,281(r3)
	PPC_STORE_U8(ctx.r3.u32 + 281, ctx.r4.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// beq cr6,0x82274884
	if (cr6.eq) goto loc_82274884;
	// bl 0x82274648
	ctx.lr = 0x82274874;
	sub_82274648(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82274884:
	// bl 0x822746f8
	ctx.lr = 0x82274888;
	sub_822746F8(ctx, base);
loc_82274888:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82274828) {
	__imp__sub_82274828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274898) {
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
	ctx.lr = 0x822748A0;
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
	ctx.lr = 0x822748C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822748fc
	if (cr6.eq) goto loc_822748FC;
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
	// beq cr6,0x822748f4
	if (cr6.eq) goto loc_822748F4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x822748fc
	if (!cr6.eq) goto loc_822748FC;
loc_822748F4:
	// li r11,1
	r11.s64 = 1;
	// b 0x82274900
	goto loc_82274900;
loc_822748FC:
	// li r11,0
	r11.s64 = 0;
loc_82274900:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227493c
	if (cr6.eq) goto loc_8227493C;
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
	// bl 0x822747a8
	ctx.lr = 0x82274934;
	sub_822747A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227493C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82274898) {
	__imp__sub_82274898(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274948) {
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
	ctx.lr = 0x82274950;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r25,1
	r25.s64 = 1;
	// li r28,0
	r28.s64 = 0;
loc_8227496C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82274984;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822749b8
	if (cr6.eq) goto loc_822749B8;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822749b0
	if (cr6.eq) goto loc_822749B0;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x822749b8
	if (!cr6.eq) goto loc_822749B8;
loc_822749B0:
	// li r11,1
	r11.s64 = 1;
	// b 0x822749bc
	goto loc_822749BC;
loc_822749B8:
	// li r11,0
	r11.s64 = 0;
loc_822749BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274a40
	if (cr6.eq) goto loc_82274A40;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82274a30
	if (cr6.lt) goto loc_82274A30;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x822749F0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274a14
	if (!cr6.eq) goto loc_82274A14;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x82274A08;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274a30
	if (cr6.eq) goto loc_82274A30;
loc_82274A14:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822745c0
	ctx.lr = 0x82274A2C;
	sub_822745C0(ctx, base);
	// b 0x82274a34
	goto loc_82274A34;
loc_82274A30:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82274A34:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_82274A40:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8227496c
	if (cr6.lt) goto loc_8227496C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82274948) {
	__imp__sub_82274948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274A58) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824f0498
	ctx.lr = 0x82274A7C;
	sub_824F0498(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82618750
	ctx.lr = 0x82274A84;
	sub_82618750(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82618640
	ctx.lr = 0x82274A94;
	sub_82618640(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82272c78
	ctx.lr = 0x82274AA0;
	sub_82272C78(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82274898
	ctx.lr = 0x82274AC4;
	sub_82274898(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

PPC_WEAK_FUNC(sub_82274A58) {
	__imp__sub_82274A58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274ADC) {
	__imp__sub_82274ADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274AE0) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274b64
	if (cr6.eq) goto loc_82274B64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0498
	ctx.lr = 0x82274B0C;
	sub_824F0498(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82618750
	ctx.lr = 0x82274B14;
	sub_82618750(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82618640
	ctx.lr = 0x82274B24;
	sub_82618640(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82272b98
	ctx.lr = 0x82274B30;
	sub_82272B98(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82274948
	ctx.lr = 0x82274B4C;
	sub_82274948(ctx, base);
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,14
	ctx.r5.s64 = 14;
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82274B64;
	sub_822990D8(ctx, base);
loc_82274B64:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

PPC_WEAK_FUNC(sub_82274AE0) {
	__imp__sub_82274AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274B7C) {
	__imp__sub_82274B7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274B80) {
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
	ctx.lr = 0x82274B88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r6,304(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82274be8
	if (cr6.eq) goto loc_82274BE8;
	// lwz r11,288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82274be8
	if (cr6.eq) goto loc_82274BE8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82274bbc
	if (!cr6.eq) goto loc_82274BBC;
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x82274bd0
	goto loc_82274BD0;
loc_82274BBC:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272a48
	ctx.lr = 0x82274BC8;
	sub_82272A48(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82274BD0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,-10240(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82274BE4;
	sub_822990D8(ctx, base);
	// stw r29,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r29.u32);
loc_82274BE8:
	// lwz r11,10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10236);
	// addi r30,r31,10236
	r30.s64 = r31.s64 + 10236;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82274c20
	if (cr6.eq) goto loc_82274C20;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82274c10
	if (cr6.eq) goto loc_82274C10;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82274c10
	if (cr6.eq) goto loc_82274C10;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x82274c20
	if (!cr6.eq) goto loc_82274C20;
loc_82274C10:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x82274C1C;
	sub_821CE080(ctx, base);
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
loc_82274C20:
	// lhz r11,10260(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274c70
	if (cr6.eq) goto loc_82274C70;
	// lwz r11,10584(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10584);
	// addi r6,r31,10584
	ctx.r6.s64 = r31.s64 + 10584;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82274c70
	if (cr6.eq) goto loc_82274C70;
	// lhz r10,10260(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10260);
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r11,10256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// addi r3,r31,10264
	ctx.r3.s64 = r31.s64 + 10264;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r31,10256
	r11.s64 = r31.s64 + 10256;
	// lwz r5,-4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// bl 0x824ffc88
	ctx.lr = 0x82274C60;
	sub_824FFC88(ctx, base);
	// lhz r8,10260(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 10260);
	// addis r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 65536;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// sth r7,10260(r31)
	PPC_STORE_U16(r31.u32 + 10260, ctx.r7.u16);
loc_82274C70:
	// lwz r3,10592(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10592);
	// bl 0x824fed28
	ctx.lr = 0x82274C78;
	sub_824FED28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82274B80) {
	__imp__sub_82274B80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274C80) {
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
	ctx.lr = 0x82274C88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-972
	ctx.r10.s64 = r11.s64 + -972;
	// lwz r30,10592(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 10592);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82274cb8
	if (cr6.eq) goto loc_82274CB8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fefd8
	ctx.lr = 0x82274CB0;
	sub_824FEFD8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82274CB8;
	sub_82130588(ctx, base);
loc_82274CB8:
	// lwz r30,10252(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82274cdc
	if (cr6.eq) goto loc_82274CDC;
	// addi r3,r30,2092
	ctx.r3.s64 = r30.s64 + 2092;
	// bl 0x82274468
	ctx.lr = 0x82274CCC;
	sub_82274468(ctx, base);
	// addi r3,r30,2080
	ctx.r3.s64 = r30.s64 + 2080;
	// bl 0x82274468
	ctx.lr = 0x82274CD4;
	sub_82274468(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82274CDC;
	sub_82130588(ctx, base);
loc_82274CDC:
	// lbz r11,10824(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274cf8
	if (cr6.eq) goto loc_82274CF8;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,10820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821326a8
	ctx.lr = 0x82274CF8;
	sub_821326A8(ctx, base);
loc_82274CF8:
	// lwz r3,10816(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10816);
	// bl 0x82130588
	ctx.lr = 0x82274D00;
	sub_82130588(ctx, base);
	// lwz r3,10820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// bl 0x82130588
	ctx.lr = 0x82274D08;
	sub_82130588(ctx, base);
	// addi r3,r31,10600
	ctx.r3.s64 = r31.s64 + 10600;
	// bl 0x82500550
	ctx.lr = 0x82274D10;
	sub_82500550(ctx, base);
	// addi r3,r31,10264
	ctx.r3.s64 = r31.s64 + 10264;
	// bl 0x824ffc18
	ctx.lr = 0x82274D18;
	sub_824FFC18(ctx, base);
	// lhz r11,10262(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10262);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274d2c
	if (cr6.eq) goto loc_82274D2C;
	// lwz r3,10256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// bl 0x82130588
	ctx.lr = 0x82274D2C;
	sub_82130588(ctx, base);
loc_82274D2C:
	// addi r3,r31,10116
	ctx.r3.s64 = r31.s64 + 10116;
	// bl 0x824ff810
	ctx.lr = 0x82274D34;
	sub_824FF810(ctx, base);
	// addi r30,r31,10112
	r30.s64 = r31.s64 + 10112;
	// li r29,49
	r29.s64 = 49;
loc_82274D3C:
	// addi r30,r30,-196
	r30.s64 = r30.s64 + -196;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82274D48;
	sub_82130000(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x82274d3c
	if (!cr0.lt) goto loc_82274D3C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-1020
	ctx.r10.s64 = r11.s64 + -1020;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82274C80) {
	__imp__sub_82274C80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274D64) {
	__imp__sub_82274D64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274D68) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8229af08
	ctx.lr = 0x82274D88;
	sub_8229AF08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82274D98;
	sub_823DA950(ctx, base);
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

PPC_WEAK_FUNC(sub_82274D68) {
	__imp__sub_82274D68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274DB4) {
	__imp__sub_82274DB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274DB8) {
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
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82274DD8;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82274DDC;
	sub_824F97C0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f0da0
	ctx.lr = 0x82274DF4;
	sub_824F0DA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274e10
	if (cr6.eq) goto loc_82274E10;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f0d28
	ctx.lr = 0x82274E10;
	sub_824F0D28(ctx, base);
loc_82274E10:
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f0ce0
	ctx.lr = 0x82274E20;
	sub_824F0CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274e3c
	if (cr6.eq) goto loc_82274E3C;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f1558
	ctx.lr = 0x82274E3C;
	sub_824F1558(ctx, base);
loc_82274E3C:
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

PPC_WEAK_FUNC(sub_82274DB8) {
	__imp__sub_82274DB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274E54) {
	__imp__sub_82274E54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274E58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82274e7c
	if (cr6.lt) goto loc_82274E7C;
	// cmpwi cr6,r4,31
	cr6.compare<int32_t>(ctx.r4.s32, 31, xer);
	// bge cr6,0x82274e7c
	if (!cr6.lt) goto loc_82274E7C;
	// mulli r11,r4,220
	r11.s64 = ctx.r4.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// blr 
	return;
loc_82274E7C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82274E58) {
	__imp__sub_82274E58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274E84) {
	__imp__sub_82274E84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274E88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addis r11,r3,2
	r11.s64 = ctx.r3.s64 + 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,276
	r11.s64 = r11.s64 + 276;
loc_82274E94:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x82274eb8
	if (cr6.eq) goto loc_82274EB8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82274e94
	if (cr6.lt) goto loc_82274E94;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82274EB8:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82274E88) {
	__imp__sub_82274E88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274ECC) {
	__imp__sub_82274ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274ED0) {
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
	ctx.lr = 0x82274ED8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addis r31,r28,2
	r31.s64 = r28.s64 + 131072;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r31,276
	r31.s64 = r31.s64 + 276;
loc_82274EF0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274f10
	if (cr6.eq) goto loc_82274F10;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82274F04;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82274F08;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r29
	cr6.compare<uint64_t>(ctx.r3.u64, r29.u64, xer);
	// beq cr6,0x82274f2c
	if (cr6.eq) goto loc_82274F2C;
loc_82274F10:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// blt cr6,0x82274ef0
	if (cr6.lt) goto loc_82274EF0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82274F2C:
	// mulli r11,r30,220
	r11.s64 = r30.s64 * 220;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82274ED0) {
	__imp__sub_82274ED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82274F44) {
	__imp__sub_82274F44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274F48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addis r11,r3,2
	r11.s64 = ctx.r3.s64 + 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,276
	r11.s64 = r11.s64 + 276;
loc_82274F54:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x82274f78
	if (cr6.eq) goto loc_82274F78;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82274f54
	if (cr6.lt) goto loc_82274F54;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_82274F78:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82274F48) {
	__imp__sub_82274F48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82274F80) {
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
	ctx.lr = 0x82274F88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mulli r11,r30,220
	r11.s64 = r30.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r11,r11,2
	r11.s64 = r11.s64 + 131072;
	// addi r11,r11,292
	r11.s64 = r11.s64 + 292;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82275034
	if (cr6.eq) goto loc_82275034;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// li r8,8
	ctx.r8.s64 = 8;
	// lbz r7,22300(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 22300);
	// ori r6,r7,64
	ctx.r6.u64 = ctx.r7.u64 | 64;
	// stb r6,22300(r10)
	PPC_STORE_U8(ctx.r10.u32 + 22300, ctx.r6.u8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,22260
	r11.s64 = r11.s64 + 22260;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82274FD4:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82274fd4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82274FD4;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r31,17268(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82274FFC;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275034
	if (cr6.eq) goto loc_82275034;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x82275014;
	sub_822A3998(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82275034
	if (!cr6.eq) goto loc_82275034;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8227502C;
	sub_822A3998(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822a57a0
	ctx.lr = 0x82275034;
	sub_822A57A0(ctx, base);
loc_82275034:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82274F80) {
	__imp__sub_82274F80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227503C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227503C) {
	__imp__sub_8227503C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275040) {
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
	ctx.lr = 0x82275048;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82275064;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822750a0
	if (cr6.eq) goto loc_822750A0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8227507C;
	sub_822A3998(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822750a0
	if (!cr6.eq) goto loc_822750A0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82275094;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82275098;
	sub_822A5578(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822a0c20
	ctx.lr = 0x822750A0;
	sub_822A0C20(ctx, base);
loc_822750A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82275040) {
	__imp__sub_82275040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822750A8) {
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
	ctx.lr = 0x822750B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x822750D0;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275108
	if (cr6.eq) goto loc_82275108;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,700(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x821c9790
	ctx.lr = 0x822750F0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x822837b8
	ctx.lr = 0x82275108;
	sub_822837B8(ctx, base);
loc_82275108:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822750A8) {
	__imp__sub_822750A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275110) {
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
	ctx.lr = 0x82275118;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x82275138;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275164
	if (cr6.eq) goto loc_82275164;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,-12672(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12672);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x822837b8
	ctx.lr = 0x82275164;
	sub_822837B8(ctx, base);
loc_82275164:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82275110) {
	__imp__sub_82275110(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227516C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227516C) {
	__imp__sub_8227516C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275170) {
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
	ctx.lr = 0x82275178;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8227519C;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822751d8
	if (cr6.eq) goto loc_822751D8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822751B4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822751d8
	if (cr6.eq) goto loc_822751D8;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822751d8
	if (cr6.eq) goto loc_822751D8;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82342b70
	ctx.lr = 0x822751D8;
	sub_82342B70(ctx, base);
loc_822751D8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82275170) {
	__imp__sub_82275170(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822751E0) {
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
	ctx.lr = 0x822751E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82275204;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275238
	if (cr6.eq) goto loc_82275238;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8227521C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82275238
	if (cr6.eq) goto loc_82275238;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82275234;
	sub_822A3998(ctx, base);
	// bl 0x822a7388
	ctx.lr = 0x82275238;
	sub_822A7388(ctx, base);
loc_82275238:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822751E0) {
	__imp__sub_822751E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275240) {
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
	ctx.lr = 0x82275248;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r28,17268(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82275268;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275330
	if (cr6.eq) goto loc_82275330;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a3998
	ctx.lr = 0x82275280;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82275330
	if (cr6.eq) goto loc_82275330;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82275298;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822752B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,48(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lbz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,1672(r11)
	PPC_STORE_U8(r11.u32 + 1672, ctx.r5.u8);
	// lbz r4,1(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r3,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,1768(r11)
	PPC_STORE_U8(r11.u32 + 1768, ctx.r9.u8);
	// lbz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,1816(r11)
	PPC_STORE_U8(r11.u32 + 1816, ctx.r5.u8);
	// lbz r4,3(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 3);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r3,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,1864(r11)
	PPC_STORE_U8(r11.u32 + 1864, ctx.r9.u8);
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,1912(r11)
	PPC_STORE_U8(r11.u32 + 1912, ctx.r5.u8);
	// lbz r4,5(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r3,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,1720(r11)
	PPC_STORE_U8(r11.u32 + 1720, ctx.r9.u8);
loc_82275330:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82275240) {
	__imp__sub_82275240(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275338) {
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
	ctx.lr = 0x82275340;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8227535C;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275390
	if (cr6.eq) goto loc_82275390;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82275374;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82275390
	if (cr6.eq) goto loc_82275390;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8227538C;
	sub_822A3998(ctx, base);
	// bl 0x822a6de0
	ctx.lr = 0x82275390;
	sub_822A6DE0(ctx, base);
loc_82275390:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82275338) {
	__imp__sub_82275338(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275398) {
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
	ctx.lr = 0x822753A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x822753BC;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822753f8
	if (cr6.eq) goto loc_822753F8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x822753D4;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822753f8
	if (cr6.eq) goto loc_822753F8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822a3998
	ctx.lr = 0x822753F0;
	sub_822A3998(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x826809f8
	ctx.lr = 0x822753F8;
	sub_826809F8(ctx, base);
loc_822753F8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82275398) {
	__imp__sub_82275398(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275400) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addis r10,r3,2
	ctx.r10.s64 = ctx.r3.s64 + 131072;
	// li r11,1
	r11.s64 = 1;
	// addi r10,r10,508
	ctx.r10.s64 = ctx.r10.s64 + 508;
loc_8227540C:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82275434
	if (!cr6.eq) goto loc_82275434;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,220
	ctx.r10.s64 = ctx.r10.s64 + 220;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x8227540c
	if (cr6.lt) goto loc_8227540C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82275434:
	// mulli r11,r11,220
	r11.s64 = r11.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82275400) {
	__imp__sub_82275400(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275448) {
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
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x82275480
	if (!cr6.eq) goto loc_82275480;
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
loc_82275480:
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, r11.u32);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x8227549c
	if (!cr6.eq) goto loc_8227549C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, r11.u32);
loc_8227549C:
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// li r5,56
	ctx.r5.s64 = 56;
	// mulli r11,r11,56
	r11.s64 = r11.s64 * 56;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x822754B0;
	sub_823DA950(ctx, base);
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, ctx.r10.u32);
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

PPC_WEAK_FUNC(sub_82275448) {
	__imp__sub_82275448(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822754D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822754D4) {
	__imp__sub_822754D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822754D8) {
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
	ctx.lr = 0x822754E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r25,0
	r25.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r26,r28,52
	r26.s64 = r28.s64 + 52;
	// mr r29,r25
	r29.u64 = r25.u64;
	// mr r31,r25
	r31.u64 = r25.u64;
loc_82275500:
	// stb r25,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r25.u8);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826193a0
	ctx.lr = 0x82275514;
	sub_826193A0(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82275538
	if (cr6.eq) goto loc_82275538;
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// clrlwi r29,r10,16
	r29.u64 = ctx.r10.u32 & 0xFFFF;
	// lbzx r9,r11,r28
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// stbx r9,r31,r30
	PPC_STORE_U8(r31.u32 + r30.u32, ctx.r9.u8);
	// b 0x82275540
	goto loc_82275540;
loc_82275538:
	// lbzx r11,r31,r27
	r11.u64 = PPC_LOAD_U8(r31.u32 + r27.u32);
	// stbx r11,r31,r30
	PPC_STORE_U8(r31.u32 + r30.u32, r11.u8);
loc_82275540:
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// clrlwi r31,r11,16
	r31.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r31,52
	cr6.compare<uint32_t>(r31.u32, 52, xer);
	// blt cr6,0x82275500
	if (cr6.lt) goto loc_82275500;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_822754D8) {
	__imp__sub_822754D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275558) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,2804(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x8227556c
	if (!cr6.eq) goto loc_8227556C;
	// li r11,0
	r11.s64 = 0;
loc_8227556C:
	// mulli r11,r11,56
	r11.s64 = r11.s64 * 56;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82275558) {
	__imp__sub_82275558(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275578) {
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
	ctx.lr = 0x82275580;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r31,r29,52
	r31.s64 = r29.s64 + 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x8227559C;
	sub_82618830(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82618af8
	ctx.lr = 0x822755AC;
	sub_82618AF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822755BC;
	sub_82618830(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// mr r11,r27
	r11.u64 = r27.u64;
	// sth r27,88(r29)
	PPC_STORE_U16(r29.u32 + 88, r27.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82275628
	if (cr6.eq) goto loc_82275628;
loc_822755D4:
	// clrlwi r28,r11,16
	r28.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r28,52
	cr6.compare<uint32_t>(r28.u32, 52, xer);
	// bge cr6,0x82275628
	if (!cr6.lt) goto loc_82275628;
	// stb r27,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r27.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x822755F0;
	sub_82618F10(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275618
	if (cr6.eq) goto loc_82275618;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82275618
	if (cr6.eq) goto loc_82275618;
	// lhz r10,88(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 88);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,88(r29)
	PPC_STORE_U16(r29.u32 + 88, ctx.r10.u16);
loc_82275618:
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// bne cr6,0x822755d4
	if (!cr6.eq) goto loc_822755D4;
loc_82275628:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275654
	if (cr6.eq) goto loc_82275654;
	// lhz r5,88(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 88);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82275654
	if (cr6.eq) goto loc_82275654;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82618f80
	ctx.lr = 0x8227564C;
	sub_82618F80(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82275654:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82275578) {
	__imp__sub_82275578(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275660) {
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
	ctx.lr = 0x82275668;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x82275684;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822756c4
	if (cr6.eq) goto loc_822756C4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r4,r29,16
	ctx.r4.u64 = r29.u32 & 0xFFFF;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x822756AC;
	sub_82618390(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x822756B8;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822756C4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82275660) {
	__imp__sub_82275660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822756D0) {
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
	ctx.lr = 0x822756D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x826187f0
	ctx.lr = 0x822756F4;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227573c
	if (cr6.eq) goto loc_8227573C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x8227571C;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// bl 0x826188d8
	ctx.lr = 0x82275730;
	sub_826188D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227573C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// sth r28,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822756D0) {
	__imp__sub_822756D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227574C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227574C) {
	__imp__sub_8227574C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275750) {
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
	ctx.lr = 0x82275758;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// bl 0x82257568
	ctx.lr = 0x82275780;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822757ac
	if (cr6.eq) goto loc_822757AC;
	// addi r5,r30,-1
	ctx.r5.s64 = r30.s64 + -1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x8227579C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822757b0
	if (!cr6.eq) goto loc_822757B0;
loc_822757AC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822757B0:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// neg r9,r11
	ctx.r9.s64 = -r11.s64;
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82275750) {
	__imp__sub_82275750(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822757D0) {
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
	ctx.lr = 0x822757D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r29,r30,64
	r29.s64 = r30.s64 + 64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82293e18
	ctx.lr = 0x822757F4;
	sub_82293E18(ctx, base);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82275800:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82275858
	if (cr6.eq) goto loc_82275858;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227584c
	if (cr6.eq) goto loc_8227584C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82275854
	if (cr6.eq) goto loc_82275854;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82275800
	if (cr0.gt) goto loc_82275800;
	// b 0x82275858
	goto loc_82275858;
loc_8227584C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x82275858
	goto loc_82275858;
loc_82275854:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_82275858:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82293e60
	ctx.lr = 0x8227586C;
	sub_82293E60(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822757D0) {
	__imp__sub_822757D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
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
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// subf r9,r3,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r3.s64;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8227588C:
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x8227588c
	if (!cr0.eq) goto loc_8227588C;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,80
	r11.s64 = ctx.r4.s64 + 80;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,64(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 64);
	// stb r10,64(r3)
	PPC_STORE_U8(ctx.r3.u32 + 64, ctx.r10.u8);
	// addi r10,r3,80
	ctx.r10.s64 = ctx.r3.s64 + 80;
	// lbz r9,65(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 65);
	// stb r9,65(r3)
	PPC_STORE_U8(ctx.r3.u32 + 65, ctx.r9.u8);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,112
	r11.s64 = ctx.r4.s64 + 112;
	// lbz r8,96(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 96);
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
	// stb r8,96(r3)
	PPC_STORE_U8(ctx.r3.u32 + 96, ctx.r8.u8);
	// lbz r7,97(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 97);
	// stb r7,97(r3)
	PPC_STORE_U8(ctx.r3.u32 + 97, ctx.r7.u8);
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,144
	r11.s64 = ctx.r4.s64 + 144;
	// lbz r6,128(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 128);
	// addi r10,r3,144
	ctx.r10.s64 = ctx.r3.s64 + 144;
	// stb r6,128(r3)
	PPC_STORE_U8(ctx.r3.u32 + 128, ctx.r6.u8);
	// lbz r5,129(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 129);
	// stb r5,129(r3)
	PPC_STORE_U8(ctx.r3.u32 + 129, ctx.r5.u8);
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,176
	r11.s64 = ctx.r4.s64 + 176;
	// lbz r9,160(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 160);
	// addi r10,r3,176
	ctx.r10.s64 = ctx.r3.s64 + 176;
	// stb r9,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, ctx.r9.u8);
	// lbz r8,161(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 161);
	// stb r8,161(r3)
	PPC_STORE_U8(ctx.r3.u32 + 161, ctx.r8.u8);
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,208
	r11.s64 = ctx.r4.s64 + 208;
	// lbz r7,192(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 192);
	// addi r10,r3,208
	ctx.r10.s64 = ctx.r3.s64 + 208;
	// stb r7,192(r3)
	PPC_STORE_U8(ctx.r3.u32 + 192, ctx.r7.u8);
	// lbz r6,193(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 193);
	// stb r6,193(r3)
	PPC_STORE_U8(ctx.r3.u32 + 193, ctx.r6.u8);
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,240
	r11.s64 = ctx.r4.s64 + 240;
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,224(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 224);
	// addi r10,r3,240
	ctx.r10.s64 = ctx.r3.s64 + 240;
	// stb r5,224(r3)
	PPC_STORE_U8(ctx.r3.u32 + 224, ctx.r5.u8);
	// lbz r9,225(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 225);
	// stb r9,225(r3)
	PPC_STORE_U8(ctx.r3.u32 + 225, ctx.r9.u8);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,272
	r11.s64 = ctx.r4.s64 + 272;
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,256(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 256);
	// addi r10,r3,272
	ctx.r10.s64 = ctx.r3.s64 + 272;
	// stb r8,256(r3)
	PPC_STORE_U8(ctx.r3.u32 + 256, ctx.r8.u8);
	// lbz r7,257(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 257);
	// stb r7,257(r3)
	PPC_STORE_U8(ctx.r3.u32 + 257, ctx.r7.u8);
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,304
	r11.s64 = ctx.r4.s64 + 304;
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,288(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 288);
	// addi r10,r3,304
	ctx.r10.s64 = ctx.r3.s64 + 304;
	// stb r6,288(r3)
	PPC_STORE_U8(ctx.r3.u32 + 288, ctx.r6.u8);
	// lbz r5,289(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 289);
	// stb r5,289(r3)
	PPC_STORE_U8(ctx.r3.u32 + 289, ctx.r5.u8);
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,336
	r11.s64 = ctx.r4.s64 + 336;
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,320(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 320);
	// addi r10,r3,336
	ctx.r10.s64 = ctx.r3.s64 + 336;
	// stb r9,320(r3)
	PPC_STORE_U8(ctx.r3.u32 + 320, ctx.r9.u8);
	// lbz r8,321(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 321);
	// stb r8,321(r3)
	PPC_STORE_U8(ctx.r3.u32 + 321, ctx.r8.u8);
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r7,352(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 352);
	// stb r7,352(r3)
	PPC_STORE_U8(ctx.r3.u32 + 352, ctx.r7.u8);
	// addi r11,r4,368
	r11.s64 = ctx.r4.s64 + 368;
	// lbz r6,353(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 353);
	// stb r6,353(r3)
	PPC_STORE_U8(ctx.r3.u32 + 353, ctx.r6.u8);
	// addi r10,r3,368
	ctx.r10.s64 = ctx.r3.s64 + 368;
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,400
	r11.s64 = ctx.r4.s64 + 400;
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,384(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 384);
	// stb r5,384(r3)
	PPC_STORE_U8(ctx.r3.u32 + 384, ctx.r5.u8);
	// addi r10,r3,400
	ctx.r10.s64 = ctx.r3.s64 + 400;
	// lbz r9,385(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 385);
	// stb r9,385(r3)
	PPC_STORE_U8(ctx.r3.u32 + 385, ctx.r9.u8);
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,432
	r11.s64 = ctx.r4.s64 + 432;
	// addi r10,r3,432
	ctx.r10.s64 = ctx.r3.s64 + 432;
	// lbz r8,416(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 416);
	// stb r8,416(r3)
	PPC_STORE_U8(ctx.r3.u32 + 416, ctx.r8.u8);
	// lbz r7,417(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 417);
	// stb r7,417(r3)
	PPC_STORE_U8(ctx.r3.u32 + 417, ctx.r7.u8);
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,464
	r11.s64 = ctx.r4.s64 + 464;
	// lbz r6,448(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 448);
	// addi r10,r3,464
	ctx.r10.s64 = ctx.r3.s64 + 464;
	// stb r6,448(r3)
	PPC_STORE_U8(ctx.r3.u32 + 448, ctx.r6.u8);
	// lbz r5,449(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 449);
	// stb r5,449(r3)
	PPC_STORE_U8(ctx.r3.u32 + 449, ctx.r5.u8);
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,496
	r11.s64 = ctx.r4.s64 + 496;
	// stvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,480(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 480);
	// stb r10,480(r3)
	PPC_STORE_U8(ctx.r3.u32 + 480, ctx.r10.u8);
	// addi r10,r3,496
	ctx.r10.s64 = ctx.r3.s64 + 496;
	// lbz r9,481(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 481);
	// stb r9,481(r3)
	PPC_STORE_U8(ctx.r3.u32 + 481, ctx.r9.u8);
	// lvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,528
	r11.s64 = ctx.r4.s64 + 528;
	// stvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,528
	ctx.r10.s64 = ctx.r3.s64 + 528;
	// lbz r8,512(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 512);
	// stb r8,512(r3)
	PPC_STORE_U8(ctx.r3.u32 + 512, ctx.r8.u8);
	// lbz r7,513(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 513);
	// stb r7,513(r3)
	PPC_STORE_U8(ctx.r3.u32 + 513, ctx.r7.u8);
	// lvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,560
	r11.s64 = ctx.r4.s64 + 560;
	// stvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,560
	ctx.r10.s64 = ctx.r3.s64 + 560;
	// lbz r6,544(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 544);
	// stb r6,544(r3)
	PPC_STORE_U8(ctx.r3.u32 + 544, ctx.r6.u8);
	// lbz r5,545(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 545);
	// stb r5,545(r3)
	PPC_STORE_U8(ctx.r3.u32 + 545, ctx.r5.u8);
	// lvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,592
	r11.s64 = ctx.r4.s64 + 592;
	// stvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,576(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 576);
	// stb r10,576(r3)
	PPC_STORE_U8(ctx.r3.u32 + 576, ctx.r10.u8);
	// addi r10,r3,592
	ctx.r10.s64 = ctx.r3.s64 + 592;
	// lbz r9,577(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 577);
	// stb r9,577(r3)
	PPC_STORE_U8(ctx.r3.u32 + 577, ctx.r9.u8);
	// lvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,624
	r11.s64 = ctx.r4.s64 + 624;
	// stvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,624
	ctx.r10.s64 = ctx.r3.s64 + 624;
	// lbz r8,608(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 608);
	// stb r8,608(r3)
	PPC_STORE_U8(ctx.r3.u32 + 608, ctx.r8.u8);
	// lbz r7,609(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 609);
	// stb r7,609(r3)
	PPC_STORE_U8(ctx.r3.u32 + 609, ctx.r7.u8);
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,656
	r11.s64 = ctx.r4.s64 + 656;
	// stvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,656
	ctx.r10.s64 = ctx.r3.s64 + 656;
	// lbz r6,640(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 640);
	// stb r6,640(r3)
	PPC_STORE_U8(ctx.r3.u32 + 640, ctx.r6.u8);
	// lbz r5,641(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 641);
	// stb r5,641(r3)
	PPC_STORE_U8(ctx.r3.u32 + 641, ctx.r5.u8);
	// lvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,672(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 672);
	// stb r11,672(r3)
	PPC_STORE_U8(ctx.r3.u32 + 672, r11.u8);
	// addi r11,r4,688
	r11.s64 = ctx.r4.s64 + 688;
	// lbz r10,673(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 673);
	// stb r10,673(r3)
	PPC_STORE_U8(ctx.r3.u32 + 673, ctx.r10.u8);
	// addi r10,r3,688
	ctx.r10.s64 = ctx.r3.s64 + 688;
	// lvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,720
	r11.s64 = ctx.r4.s64 + 720;
	// stvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,704(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 704);
	// stb r9,704(r3)
	PPC_STORE_U8(ctx.r3.u32 + 704, ctx.r9.u8);
	// addi r10,r3,720
	ctx.r10.s64 = ctx.r3.s64 + 720;
	// lbz r8,705(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 705);
	// stb r8,705(r3)
	PPC_STORE_U8(ctx.r3.u32 + 705, ctx.r8.u8);
	// lvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,752
	r11.s64 = ctx.r4.s64 + 752;
	// stvx128 v42,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,752
	ctx.r10.s64 = ctx.r3.s64 + 752;
	// lbz r7,736(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 736);
	// stb r7,736(r3)
	PPC_STORE_U8(ctx.r3.u32 + 736, ctx.r7.u8);
	// lbz r6,737(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 737);
	// stb r6,737(r3)
	PPC_STORE_U8(ctx.r3.u32 + 737, ctx.r6.u8);
	// lvx128 v41,r0,r11
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,784
	r11.s64 = ctx.r4.s64 + 784;
	// stvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,768(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 768);
	// stb r5,768(r3)
	PPC_STORE_U8(ctx.r3.u32 + 768, ctx.r5.u8);
	// addi r10,r3,784
	ctx.r10.s64 = ctx.r3.s64 + 784;
	// lbz r9,769(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 769);
	// stb r9,769(r3)
	PPC_STORE_U8(ctx.r3.u32 + 769, ctx.r9.u8);
	// lvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,816
	r11.s64 = ctx.r4.s64 + 816;
	// stvx128 v40,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,800(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 800);
	// stb r8,800(r3)
	PPC_STORE_U8(ctx.r3.u32 + 800, ctx.r8.u8);
	// addi r10,r3,816
	ctx.r10.s64 = ctx.r3.s64 + 816;
	// lbz r7,801(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 801);
	// stb r7,801(r3)
	PPC_STORE_U8(ctx.r3.u32 + 801, ctx.r7.u8);
	// lvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,848
	r11.s64 = ctx.r4.s64 + 848;
	// lbz r6,832(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 832);
	// addi r10,r3,848
	ctx.r10.s64 = ctx.r3.s64 + 848;
	// stb r6,832(r3)
	PPC_STORE_U8(ctx.r3.u32 + 832, ctx.r6.u8);
	// lbz r5,833(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 833);
	// stb r5,833(r3)
	PPC_STORE_U8(ctx.r3.u32 + 833, ctx.r5.u8);
	// lvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,864(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 864);
	// stb r11,864(r3)
	PPC_STORE_U8(ctx.r3.u32 + 864, r11.u8);
	// addi r11,r4,880
	r11.s64 = ctx.r4.s64 + 880;
	// lbz r9,865(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 865);
	// addi r10,r3,880
	ctx.r10.s64 = ctx.r3.s64 + 880;
	// stb r9,865(r3)
	PPC_STORE_U8(ctx.r3.u32 + 865, ctx.r9.u8);
	// lvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,912
	r11.s64 = ctx.r4.s64 + 912;
	// stvx128 v37,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,896(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 896);
	// stb r8,896(r3)
	PPC_STORE_U8(ctx.r3.u32 + 896, ctx.r8.u8);
	// addi r10,r3,912
	ctx.r10.s64 = ctx.r3.s64 + 912;
	// lbz r7,897(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 897);
	// stb r7,897(r3)
	PPC_STORE_U8(ctx.r3.u32 + 897, ctx.r7.u8);
	// lvx128 v36,r0,r11
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,928(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 928);
	// stb r6,928(r3)
	PPC_STORE_U8(ctx.r3.u32 + 928, ctx.r6.u8);
	// addi r11,r4,944
	r11.s64 = ctx.r4.s64 + 944;
	// lbz r5,929(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 929);
	// addi r10,r3,944
	ctx.r10.s64 = ctx.r3.s64 + 944;
	// stb r5,929(r3)
	PPC_STORE_U8(ctx.r3.u32 + 929, ctx.r5.u8);
	// lvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,960(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 960);
	// stb r11,960(r3)
	PPC_STORE_U8(ctx.r3.u32 + 960, r11.u8);
	// addi r11,r4,976
	r11.s64 = ctx.r4.s64 + 976;
	// lbz r9,961(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 961);
	// addi r10,r3,976
	ctx.r10.s64 = ctx.r3.s64 + 976;
	// stb r9,961(r3)
	PPC_STORE_U8(ctx.r3.u32 + 961, ctx.r9.u8);
	// lvx128 v34,r0,r11
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,1008
	r11.s64 = ctx.r4.s64 + 1008;
	// stvx128 v34,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,992(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 992);
	// stb r8,992(r3)
	PPC_STORE_U8(ctx.r3.u32 + 992, ctx.r8.u8);
	// addi r10,r3,1008
	ctx.r10.s64 = ctx.r3.s64 + 1008;
	// lbz r7,993(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 993);
	// stb r7,993(r3)
	PPC_STORE_U8(ctx.r3.u32 + 993, ctx.r7.u8);
	// lvx128 v33,r0,r11
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,1024(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1024);
	// stb r6,16(r10)
	PPC_STORE_U8(ctx.r10.u32 + 16, ctx.r6.u8);
	// lbz r5,1025(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1025);
	// stb r5,17(r10)
	PPC_STORE_U8(ctx.r10.u32 + 17, ctx.r5.u8);
	// lbz r11,1040(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1040);
	// stb r11,1040(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1040, r11.u8);
	// lbz r10,1041(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1041);
	// stb r10,1041(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1041, ctx.r10.u8);
	// lbz r9,1042(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1042);
	// stb r9,1042(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1042, ctx.r9.u8);
	// lbz r8,1043(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1043);
	// stb r8,1043(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1043, ctx.r8.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82275878) {
	__imp__sub_82275878(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82275CA4) {
	__imp__sub_82275CA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275CA8) {
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
	ctx.lr = 0x82275CB0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x82275CD0;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82275CDC;
	sub_82618750(ctx, base);
	// subf r5,r31,r28
	ctx.r5.s64 = r28.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82275CEC;
	sub_82618640(ctx, base);
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r30,r10,1
	r30.u64 = ctx.r10.u64 ^ 1;
	// beq cr6,0x82275d30
	if (cr6.eq) goto loc_82275D30;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275d28
	if (cr6.eq) goto loc_82275D28;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82275D14;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_82275D28:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_82275D30:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82275CA8) {
	__imp__sub_82275CA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82275D3C) {
	__imp__sub_82275D3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275D40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82275D50:
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x82275d50
	if (!cr0.eq) goto loc_82275D50;
	// lbz r11,208(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 208);
	// stw r9,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r9.u32);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stw r9,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r9.u32);
	// stw r9,204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 204, ctx.r9.u32);
	// stb r10,208(r3)
	PPC_STORE_U8(ctx.r3.u32 + 208, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82275D40) {
	__imp__sub_82275D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82275D84) {
	__imp__sub_82275D84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275D88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,4
	ctx.r10.s64 = 4;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// stb r10,8(r9)
	PPC_STORE_U8(ctx.r9.u32 + 8, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82275D88) {
	__imp__sub_82275D88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82275DA4) {
	__imp__sub_82275DA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275DA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,5
	ctx.r10.s64 = 5;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// li r9,-1
	ctx.r9.s64 = -1;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82275DA8) {
	__imp__sub_82275DA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82275DCC) {
	__imp__sub_82275DCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275DD0) {
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
	// addi r9,r11,-572
	ctx.r9.s64 = r11.s64 + -572;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82275e04
	if (cr6.eq) goto loc_82275E04;
	// bl 0x82130588
	ctx.lr = 0x82275E00;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82275E04:
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

PPC_WEAK_FUNC(sub_82275DD0) {
	__imp__sub_82275DD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275E18) {
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
	// addi r9,r11,-488
	ctx.r9.s64 = r11.s64 + -488;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82275e4c
	if (cr6.eq) goto loc_82275E4C;
	// bl 0x82130588
	ctx.lr = 0x82275E48;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82275E4C:
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

PPC_WEAK_FUNC(sub_82275E18) {
	__imp__sub_82275E18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275E60) {
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
	ctx.lr = 0x82275E68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// addis r27,r29,2
	r27.s64 = r29.s64 + 131072;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r27,r27,6930
	r27.s64 = r27.s64 + 6930;
	// stb r11,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r11.u8);
	// bl 0x82388580
	ctx.lr = 0x82275E88;
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
	ctx.lr = 0x82275E9C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82275EA4;
	sub_824E70F0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82275efc
	if (cr6.eq) goto loc_82275EFC;
	// bl 0x82387b90
	ctx.lr = 0x82275EB4;
	sub_82387B90(ctx, base);
	// lwz r28,1340(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82275ef4
	if (!cr6.gt) goto loc_82275EF4;
	// addis r29,r29,2
	r29.s64 = r29.s64 + 131072;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r29,6900
	r29.s64 = r29.s64 + 6900;
loc_82275ED0:
	// bl 0x82387b90
	ctx.lr = 0x82275ED4;
	sub_82387B90(ctx, base);
	// add r11,r30,r3
	r11.u64 = r30.u64 + ctx.r3.u64;
	// addi r3,r11,3479
	ctx.r3.s64 = r11.s64 + 3479;
	// bl 0x82392a20
	ctx.lr = 0x82275EE0;
	sub_82392A20(ctx, base);
	// stbx r3,r29,r31
	PPC_STORE_U8(r29.u32 + r31.u32, ctx.r3.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,8176
	r30.s64 = r30.s64 + 8176;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x82275ed0
	if (cr6.lt) goto loc_82275ED0;
loc_82275EF4:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r11.u8);
loc_82275EFC:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82275E60) {
	__imp__sub_82275E60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82275F10) {
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
	ctx.lr = 0x82275F18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x82275F30;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ori r27,r10,276
	r27.u64 = ctx.r10.u64 | 276;
	// beq cr6,0x82275f7c
	if (cr6.eq) goto loc_82275F7C;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r28,r27
	r11.u64 = r28.u64 + r27.u64;
loc_82275F50:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// beq cr6,0x82275f74
	if (cr6.eq) goto loc_82275F74;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82275f50
	if (cr6.lt) goto loc_82275F50;
	// li r30,-1
	r30.s64 = -1;
	// b 0x82275f80
	goto loc_82275F80;
loc_82275F74:
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// b 0x82275f80
	goto loc_82275F80;
loc_82275F7C:
	// li r30,0
	r30.s64 = 0;
loc_82275F80:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x82275F8C;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275fc8
	if (cr6.eq) goto loc_82275FC8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x82275FA8;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82275fc8
	if (!cr6.eq) goto loc_82275FC8;
	// bl 0x822c4eb8
	ctx.lr = 0x82275FB8;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x82275FC0;
	sub_822C4EC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822cad90
	ctx.lr = 0x82275FC8;
	sub_822CAD90(ctx, base);
loc_82275FC8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82275FD4;
	sub_822A3998(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822a5d20
	ctx.lr = 0x82275FE0;
	sub_822A5D20(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276010
	if (cr6.eq) goto loc_82276010;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82276010
	if (cr6.eq) goto loc_82276010;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// extsb r5,r9
	ctx.r5.s64 = ctx.r9.s8;
	// lwz r3,17892(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17892);
	// bl 0x822b6470
	ctx.lr = 0x82276010;
	sub_822B6470(ctx, base);
loc_82276010:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x8227601C;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276130
	if (cr6.eq) goto loc_82276130;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82276034;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82276038;
	sub_824F97C0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f0ce0
	ctx.lr = 0x82276050;
	sub_824F0CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227606c
	if (!cr6.eq) goto loc_8227606C;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f14e8
	ctx.lr = 0x8227606C;
	sub_824F14E8(ctx, base);
loc_8227606C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82276088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822760A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r31,r28,r27
	r31.u64 = r28.u64 + r27.u64;
	// li r29,0
	r29.s64 = 0;
	// li r30,31
	r30.s64 = 31;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_822760B4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822760f4
	if (cr6.eq) goto loc_822760F4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822760C8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822760DC;
	sub_82270170(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82272ee8
	ctx.lr = 0x822760E4;
	sub_82272EE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822760f4
	if (cr6.eq) goto loc_822760F4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_822760F4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// bne 0x822760b4
	if (!cr0.eq) goto loc_822760B4;
	// cmpwi cr6,r29,5
	cr6.compare<int32_t>(r29.s32, 5, xer);
	// blt cr6,0x82276130
	if (cr6.lt) goto loc_82276130;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-468
	ctx.r4.s64 = ctx.r10.s64 + -468;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82276130;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82276130:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82275F10) {
	__imp__sub_82275F10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276138) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82276158;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822761bc
	if (cr6.eq) goto loc_822761BC;
	// bl 0x82388580
	ctx.lr = 0x8227616C;
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
	ctx.lr = 0x82276180;
	sub_82270170(ctx, base);
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r4,11780(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11780);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822761a8
	if (!cr6.eq) goto loc_822761A8;
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
loc_822761A8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822761BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822761BC:
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

PPC_WEAK_FUNC(sub_82276138) {
	__imp__sub_82276138(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822761D0) {
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
	ctx.lr = 0x822761D8;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8304(r1)
	ea = -8304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82387b90
	ctx.lr = 0x822761F4;
	sub_82387B90(ctx, base);
	// mulli r11,r28,8176
	r11.s64 = r28.s64 * 8176;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r31,r11,1360
	r31.s64 = r11.s64 + 1360;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238f648
	ctx.lr = 0x8227620C;
	sub_8238F648(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822763d8
	if (cr6.eq) goto loc_822763D8;
	// lis r11,2
	r11.s64 = 131072;
	// add r10,r28,r29
	ctx.r10.u64 = r28.u64 + r29.u64;
	// ori r9,r11,6900
	ctx.r9.u64 = r11.u64 | 6900;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822762ac
	if (!cr6.eq) goto loc_822762AC;
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227623C;
	sub_823924B0(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227624C;
	sub_823924B0(ctx, base);
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227625C;
	sub_823924B0(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227626C;
	sub_823924B0(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227627C;
	sub_823924B0(ctx, base);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227628C;
	sub_823924B0(ctx, base);
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227629C;
	sub_823924B0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x822762AC;
	sub_823924B0(ctx, base);
loc_822762AC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82276348
	if (cr6.eq) goto loc_82276348;
	// lbz r11,20(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 20);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x822762c8
	if (cr6.eq) goto loc_822762C8;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822763d8
	if (!cr6.eq) goto loc_822763D8;
loc_822762C8:
	// lwz r10,212(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822763d8
	if (cr6.eq) goto loc_822763D8;
	// lwz r11,8264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8264);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822762f8
	if (cr6.eq) goto loc_822762F8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x822762f8
	if (cr6.eq) goto loc_822762F8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822762fc
	if (!cr6.eq) goto loc_822762FC;
loc_822762F8:
	// li r11,1
	r11.s64 = 1;
loc_822762FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82276334
	if (!cr6.eq) goto loc_82276334;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b480
	ctx.lr = 0x82276310;
	sub_8229B480(ctx, base);
	// lwz r11,212(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// lwz r5,68(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8229bb30
	ctx.lr = 0x82276324;
	sub_8229BB30(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x8227632C;
	sub_8238ED78(ctx, base);
	// addi r1,r1,8304
	ctx.r1.s64 = ctx.r1.s64 + 8304;
	// b 0x823d9248
	return;
loc_82276334:
	// stw r28,22296(r10)
	PPC_STORE_U32(ctx.r10.u32 + 22296, r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x82276340;
	sub_8238ED78(ctx, base);
	// addi r1,r1,8304
	ctx.r1.s64 = ctx.r1.s64 + 8304;
	// b 0x823d9248
	return;
loc_82276348:
	// addis r31,r29,2
	r31.s64 = r29.s64 + 131072;
	// li r30,31
	r30.s64 = 31;
	// addi r31,r31,292
	r31.s64 = r31.s64 + 292;
loc_82276354:
	// lbz r11,-192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -192);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x82276368
	if (cr6.eq) goto loc_82276368;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822763cc
	if (!cr6.eq) goto loc_822763CC;
loc_82276368:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822763cc
	if (cr6.eq) goto loc_822763CC;
	// lwz r11,8264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8264);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82276398
	if (cr6.eq) goto loc_82276398;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82276398
	if (cr6.eq) goto loc_82276398;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8227639c
	if (!cr6.eq) goto loc_8227639C;
loc_82276398:
	// li r11,1
	r11.s64 = 1;
loc_8227639C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822763c8
	if (!cr6.eq) goto loc_822763C8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b480
	ctx.lr = 0x822763B0;
	sub_8229B480(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,68(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r4,-196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -196);
	// bl 0x8229bb30
	ctx.lr = 0x822763C4;
	sub_8229BB30(ctx, base);
	// b 0x822763cc
	goto loc_822763CC;
loc_822763C8:
	// stw r28,22296(r10)
	PPC_STORE_U32(ctx.r10.u32 + 22296, r28.u32);
loc_822763CC:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// bne 0x82276354
	if (!cr0.eq) goto loc_82276354;
loc_822763D8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x822763E0;
	sub_8238ED78(ctx, base);
	// addi r1,r1,8304
	ctx.r1.s64 = ctx.r1.s64 + 8304;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822761D0) {
	__imp__sub_822761D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822763E8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r31,0(r4)
	r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// bl 0x82388580
	ctx.lr = 0x82276404;
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
	ctx.lr = 0x82276418;
	sub_82270170(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82274128
	ctx.lr = 0x82276424;
	sub_82274128(ctx, base);
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

PPC_WEAK_FUNC(sub_822763E8) {
	__imp__sub_822763E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276438) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x82276458;
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
	ctx.lr = 0x8227646C;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82276474;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82276510
	if (cr6.eq) goto loc_82276510;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8227648C;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276510
	if (cr6.eq) goto loc_82276510;
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
	// beq cr6,0x822764c4
	if (cr6.eq) goto loc_822764C4;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x822764d0
	goto loc_822764D0;
loc_822764C4:
	// lwz r10,17892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
loc_822764D0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82276510
	if (cr6.eq) goto loc_82276510;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822764EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82276510
	if (cr6.eq) goto loc_82276510;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r7,16(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// lwz r6,12(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82680598
	ctx.lr = 0x82276510;
	sub_82680598(ctx, base);
loc_82276510:
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

PPC_WEAK_FUNC(sub_82276438) {
	__imp__sub_82276438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276528) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82276530;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8432(r1)
	ea = -8432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mulli r11,r30,220
	r11.s64 = r30.s64 * 220;
	// add r28,r11,r3
	r28.u64 = r11.u64 + ctx.r3.u64;
	// addis r31,r28,2
	r31.s64 = r28.s64 + 131072;
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r3,r11,22260
	ctx.r3.s64 = r11.s64 + 22260;
	// bl 0x8229b410
	ctx.lr = 0x82276564;
	sub_8229B410(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8216c9c0
	ctx.lr = 0x8227658C;
	sub_8216C9C0(ctx, base);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,30288(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x8238f550
	ctx.lr = 0x822765B0;
	sub_8238F550(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b4f0
	ctx.lr = 0x822765C0;
	sub_8229B4F0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x822765D0;
	sub_821E80F8(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8227680c
	if (cr6.eq) goto loc_8227680C;
	// bl 0x822c4eb8
	ctx.lr = 0x822765E0;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x822765E8;
	sub_822C4EC8(ctx, base);
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822a3998
	ctx.lr = 0x822765FC;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82276608;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82276618;
	sub_82270170(ctx, base);
	// bl 0x82272e98
	ctx.lr = 0x8227661C;
	sub_82272E98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82276688
	if (!cr6.eq) goto loc_82276688;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82276630;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82276640;
	sub_82270170(ctx, base);
	// bl 0x82272ec0
	ctx.lr = 0x82276644;
	sub_82272EC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82276680
	if (cr6.eq) goto loc_82276680;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r26,1220(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// bl 0x82388580
	ctx.lr = 0x8227665C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227666C;
	sub_82270170(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82272ee8
	ctx.lr = 0x82276674;
	sub_82272EE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82276688
	if (!cr6.eq) goto loc_82276688;
loc_82276680:
	// li r11,0
	r11.s64 = 0;
	// b 0x8227668c
	goto loc_8227668C;
loc_82276688:
	// li r11,1
	r11.s64 = 1;
loc_8227668C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82276720
	if (!cr6.eq) goto loc_82276720;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82393148
	ctx.lr = 0x822766A0;
	sub_82393148(ctx, base);
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766B0;
	sub_823924B0(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766C0;
	sub_823924B0(ctx, base);
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766D0;
	sub_823924B0(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766E0;
	sub_823924B0(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766F0;
	sub_823924B0(ctx, base);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x82276700;
	sub_823924B0(ctx, base);
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x82276710;
	sub_823924B0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x82276720;
	sub_823924B0(ctx, base);
loc_82276720:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e10
	ctx.lr = 0x8227672C;
	sub_822A8E10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82276734;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r26,-10240(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r25,4(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82388580
	ctx.lr = 0x82276748;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82276758;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82276760;
	sub_82272A30(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824818a0
	ctx.lr = 0x82276768;
	sub_824818A0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82270170
	ctx.lr = 0x82276778;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82276780;
	sub_82272A30(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824818a0
	ctx.lr = 0x82276788;
	sub_824818A0(ctx, base);
	// add r8,r29,r3
	ctx.r8.u64 = r29.u64 + ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// subfic r7,r8,8
	xer.ca = ctx.r8.u32 <= 8;
	ctx.r7.s64 = 8 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r29,r6,31
	r29.u64 = ctx.r6.u32 & 0x1;
	// bl 0x822577d0
	ctx.lr = 0x822767A4;
	sub_822577D0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// bl 0x822cadf0
	ctx.lr = 0x822767C4;
	sub_822CADF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8838
	ctx.lr = 0x822767CC;
	sub_822A8838(ctx, base);
	// bl 0x822387e8
	ctx.lr = 0x822767D0;
	sub_822387E8(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82238578
	ctx.lr = 0x822767E0;
	sub_82238578(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82238988
	ctx.lr = 0x822767E8;
	sub_82238988(ctx, base);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// addis r4,r28,2
	ctx.r4.s64 = r28.s64 + 131072;
	// ori r3,r5,292
	ctx.r3.u64 = ctx.r5.u64 | 292;
	// addi r4,r4,296
	ctx.r4.s64 = ctx.r4.s64 + 296;
	// lwzx r11,r28,r3
	r11.u64 = PPC_LOAD_U32(r28.u32 + ctx.r3.u32);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r9.u8);
loc_8227680C:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8238ed78
	ctx.lr = 0x82276814;
	sub_8238ED78(ctx, base);
	// addi r1,r1,8432
	ctx.r1.s64 = ctx.r1.s64 + 8432;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82276528) {
	__imp__sub_82276528(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276820) {
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
	ctx.lr = 0x82276828;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x822701c8
	ctx.lr = 0x8227684C;
	sub_822701C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481688
	ctx.lr = 0x82276874;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481590
	ctx.lr = 0x82276888;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x822768A0;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x822768B8;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// li r3,83
	ctx.r3.s64 = 83;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822768CC:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82299c98
	ctx.lr = 0x822768DC;
	sub_82299C98(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82276820) {
	__imp__sub_82276820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822768E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822768E4) {
	__imp__sub_822768E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822768E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r5,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// addis r11,r9,2
	r11.s64 = ctx.r9.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82276904:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x82276928
	if (cr6.eq) goto loc_82276928;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82276904
	if (cr6.lt) goto loc_82276904;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_82276928:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// li r10,220
	ctx.r10.s64 = 220;
	// divw r3,r11,r10
	ctx.r3.s32 = r11.s32 / ctx.r10.s32;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822768E8) {
	__imp__sub_822768E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276938) {
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
	ctx.lr = 0x82276940;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addis r11,r30,2
	r11.s64 = r30.s64 + 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82276958:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x822769c0
	if (cr6.eq) goto loc_822769C0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82276958
	if (cr6.lt) goto loc_82276958;
	// li r31,-1
	r31.s64 = -1;
loc_82276978:
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82276998
	if (cr6.eq) goto loc_82276998;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82275040
	ctx.lr = 0x82276998;
	sub_82275040(ctx, base);
loc_82276998:
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822769b8
	if (cr6.eq) goto loc_822769B8;
	// addi r5,r29,16
	ctx.r5.s64 = r29.s64 + 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82274f80
	ctx.lr = 0x822769B8;
	sub_82274F80(ctx, base);
loc_822769B8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822769C0:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// li r10,220
	ctx.r10.s64 = 220;
	// divw r31,r11,r10
	r31.s32 = r11.s32 / ctx.r10.s32;
	// b 0x82276978
	goto loc_82276978;
}

PPC_WEAK_FUNC(sub_82276938) {
	__imp__sub_82276938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822769D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,2808(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2808);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82276a14
	if (!cr6.gt) goto loc_82276A14;
	// lwz r11,2804(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2804);
	// lis r9,20971
	ctx.r9.s64 = 1374355456;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// ori r7,r9,34079
	ctx.r7.u64 = ctx.r9.u64 | 34079;
	// mulhw r6,r8,r7
	ctx.r6.s64 = (int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32)) >> 32;
	// srawi r11,r6,4
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	r11.s64 = ctx.r6.s32 >> 4;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mulli r4,r5,50
	ctx.r4.s64 = ctx.r5.s64 * 50;
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// mulli r11,r11,56
	r11.s64 = r11.s64 * 56;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
loc_82276A14:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822769D0) {
	__imp__sub_822769D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82276A1C) {
	__imp__sub_82276A1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276A20) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82276A28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r27,r31,52
	r27.s64 = r31.s64 + 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82618830
	ctx.lr = 0x82276A48;
	sub_82618830(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// sth r11,88(r31)
	PPC_STORE_U16(r31.u32 + 88, r11.u16);
loc_82276A54:
	// lbzx r11,r30,r28
	r11.u64 = PPC_LOAD_U8(r30.u32 + r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lbzx r10,r30,r29
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + r29.u32);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82276a84
	if (cr6.eq) goto loc_82276A84;
	// lhz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// li r4,1
	ctx.r4.s64 = 1;
	// stbx r11,r10,r31
	PPC_STORE_U8(ctx.r10.u32 + r31.u32, r11.u8);
	// lhz r11,88(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// sth r9,88(r31)
	PPC_STORE_U16(r31.u32 + 88, ctx.r9.u16);
loc_82276A84:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82618f70
	ctx.lr = 0x82276A8C;
	sub_82618F70(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r30,52
	cr6.compare<uint32_t>(r30.u32, 52, xer);
	// blt cr6,0x82276a54
	if (cr6.lt) goto loc_82276A54;
	// lhz r11,88(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// li r10,416
	ctx.r10.s64 = 416;
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// addi r9,r11,52
	ctx.r9.s64 = r11.s64 + 52;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// subfc r7,r10,r8
	xer.ca = ctx.r8.u32 >= ctx.r10.u32;
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r6,31
	ctx.r3.u64 = ctx.r6.u32 & 0x1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82276A20) {
	__imp__sub_82276A20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82276AC4) {
	__imp__sub_82276AC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276AC8) {
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
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276AEC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276b14
	if (cr6.eq) goto loc_82276B14;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82276B04;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276b18
	if (!cr6.eq) goto loc_82276B18;
loc_82276B14:
	// li r11,0
	r11.s64 = 0;
loc_82276B18:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276AC8) {
	__imp__sub_82276AC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82276B34) {
	__imp__sub_82276B34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276B38) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x82276B5C;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276b88
	if (cr6.eq) goto loc_82276B88;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,64
	ctx.r4.s64 = r30.s64 + 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82276B78;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276b8c
	if (!cr6.eq) goto loc_82276B8C;
loc_82276B88:
	// li r11,0
	r11.s64 = 0;
loc_82276B8C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276B38) {
	__imp__sub_82276B38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276BA8) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618fa0
	ctx.lr = 0x82276BCC;
	sub_82618FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276bf8
	if (cr6.eq) goto loc_82276BF8;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,64
	ctx.r4.s64 = r30.s64 + 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276BE8;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276bfc
	if (!cr6.eq) goto loc_82276BFC;
loc_82276BF8:
	// li r11,0
	r11.s64 = 0;
loc_82276BFC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276BA8) {
	__imp__sub_82276BA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276C18) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822559f0
	ctx.lr = 0x82276C40;
	sub_822559F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276c6c
	if (cr6.eq) goto loc_82276C6C;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,1056
	ctx.r4.s64 = r30.s64 + 1056;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82276C5C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276c70
	if (!cr6.eq) goto loc_82276C70;
loc_82276C6C:
	// li r11,0
	r11.s64 = 0;
loc_82276C70:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276C18) {
	__imp__sub_82276C18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82276C8C) {
	__imp__sub_82276C8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276C90) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82255ae0
	ctx.lr = 0x82276CB8;
	sub_82255AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276ce4
	if (cr6.eq) goto loc_82276CE4;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,1056
	ctx.r4.s64 = r30.s64 + 1056;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276CD4;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276ce8
	if (!cr6.eq) goto loc_82276CE8;
loc_82276CE4:
	// li r11,0
	r11.s64 = 0;
loc_82276CE8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276C90) {
	__imp__sub_82276C90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82276D04) {
	__imp__sub_82276D04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276D08) {
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
	ctx.lr = 0x82276D10;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82276D2C;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82276d6c
	if (cr6.eq) goto loc_82276D6C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82276D54;
	sub_82618390(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82276D60;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82276D6C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82276D08) {
	__imp__sub_82276D08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276D78) {
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
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f90
	ctx.lr = 0x82276D9C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276dc8
	if (cr6.eq) goto loc_82276DC8;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82276DB8;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276dcc
	if (!cr6.eq) goto loc_82276DCC;
loc_82276DC8:
	// li r11,0
	r11.s64 = 0;
loc_82276DCC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276D78) {
	__imp__sub_82276D78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276DE8) {
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
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276E0C;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276e38
	if (cr6.eq) goto loc_82276E38;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276E28;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276e3c
	if (!cr6.eq) goto loc_82276E3C;
loc_82276E38:
	// li r11,0
	r11.s64 = 0;
loc_82276E3C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276DE8) {
	__imp__sub_82276DE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276E58) {
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
	ctx.lr = 0x82276E60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82276E7C;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276eb4
	if (cr6.eq) goto loc_82276EB4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,7
	ctx.r5.s64 = 7;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82276EA4;
	sub_82618390(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82276EB0;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_82276EB4:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276edc
	if (cr6.eq) goto loc_82276EDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// bl 0x82618f70
	ctx.lr = 0x82276ECC;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276ee0
	if (!cr6.eq) goto loc_82276EE0;
loc_82276EDC:
	// li r11,0
	r11.s64 = 0;
loc_82276EE0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82276E58) {
	__imp__sub_82276E58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82276EEC) {
	__imp__sub_82276EEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276EF0) {
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
	// lbz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// bl 0x82618f70
	ctx.lr = 0x82276F14;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,1(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// bl 0x82618f70
	ctx.lr = 0x82276F2C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,2(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// bl 0x82618f70
	ctx.lr = 0x82276F44;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,3(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// bl 0x82618f70
	ctx.lr = 0x82276F5C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// bl 0x82618f70
	ctx.lr = 0x82276F74;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// bl 0x82618f70
	ctx.lr = 0x82276F8C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276fa0
	if (!cr6.eq) goto loc_82276FA0;
loc_82276F9C:
	// li r11,0
	r11.s64 = 0;
loc_82276FA0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276EF0) {
	__imp__sub_82276EF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82276FBC) {
	__imp__sub_82276FBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82276FC0) {
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
	// bl 0x82618f10
	ctx.lr = 0x82276FE0;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,1
	ctx.r4.s64 = r30.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82276FF8;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,2
	ctx.r4.s64 = r30.s64 + 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82277010;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,3
	ctx.r4.s64 = r30.s64 + 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82277028;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82277040;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,5
	ctx.r4.s64 = r30.s64 + 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82277058;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227706c
	if (!cr6.eq) goto loc_8227706C;
loc_82277068:
	// li r11,0
	r11.s64 = 0;
loc_8227706C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_82276FC0) {
	__imp__sub_82276FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277088) {
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
	ctx.lr = 0x82277090;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r29,0(r11)
	r29.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x822770B0;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822770f0
	if (cr6.eq) goto loc_822770F0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r4,r29,16
	ctx.r4.u64 = r29.u32 & 0xFFFF;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x822770D8;
	sub_82618390(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x822770E4;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822770F0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82277088) {
	__imp__sub_82277088(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822770FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822770FC) {
	__imp__sub_822770FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277100) {
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
	ctx.lr = 0x82277108;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x82277138;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277144;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277154;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277184
	if (cr6.eq) goto loc_82277184;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277184
	if (!cr6.eq) goto loc_82277184;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276ac8
	ctx.lr = 0x82277174;
	sub_82276AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277188
	if (!cr6.eq) goto loc_82277188;
loc_82277184:
	// li r31,0
	r31.s64 = 0;
loc_82277188:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822771b4
	if (cr6.eq) goto loc_822771B4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822771ac
	if (cr6.eq) goto loc_822771AC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822771A4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822771b0
	goto loc_822771B0;
loc_822771AC:
	// li r11,0
	r11.s64 = 0;
loc_822771B0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822771B4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822771d8
	if (cr6.eq) goto loc_822771D8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822771C8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822771dc
	if (cr6.eq) goto loc_822771DC;
loc_822771D8:
	// li r11,0
	r11.s64 = 0;
loc_822771DC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82277100) {
	__imp__sub_82277100(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822771E8) {
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
	ctx.lr = 0x822771F0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x82277214;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277220;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277230;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277254
	if (cr6.eq) goto loc_82277254;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229afa8
	ctx.lr = 0x82277244;
	sub_8229AFA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277258
	if (!cr6.eq) goto loc_82277258;
loc_82277254:
	// li r30,0
	r30.s64 = 0;
loc_82277258:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277290
	if (cr6.eq) goto loc_82277290;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277288
	if (cr6.eq) goto loc_82277288;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277274;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82277288:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277290:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822771E8) {
	__imp__sub_822771E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227729C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227729C) {
	__imp__sub_8227729C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822772A0) {
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
	ctx.lr = 0x822772A8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x822772D8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x822772E4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x822772F4;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277324
	if (cr6.eq) goto loc_82277324;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277324
	if (!cr6.eq) goto loc_82277324;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8229b0f8
	ctx.lr = 0x82277314;
	sub_8229B0F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277328
	if (!cr6.eq) goto loc_82277328;
loc_82277324:
	// li r31,0
	r31.s64 = 0;
loc_82277328:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82277354
	if (cr6.eq) goto loc_82277354;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227734c
	if (cr6.eq) goto loc_8227734C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277344;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82277350
	goto loc_82277350;
loc_8227734C:
	// li r11,0
	r11.s64 = 0;
loc_82277350:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82277354:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277378
	if (cr6.eq) goto loc_82277378;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277368;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227737c
	if (cr6.eq) goto loc_8227737C;
loc_82277378:
	// li r11,0
	r11.s64 = 0;
loc_8227737C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822772A0) {
	__imp__sub_822772A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277388) {
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
	ctx.lr = 0x82277390;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x822773B4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x822773C0;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x822773D0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822773f4
	if (cr6.eq) goto loc_822773F4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276b38
	ctx.lr = 0x822773E4;
	sub_82276B38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822773f8
	if (!cr6.eq) goto loc_822773F8;
loc_822773F4:
	// li r30,0
	r30.s64 = 0;
loc_822773F8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277430
	if (cr6.eq) goto loc_82277430;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277428
	if (cr6.eq) goto loc_82277428;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277414;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82277428:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277430:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82277388) {
	__imp__sub_82277388(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227743C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227743C) {
	__imp__sub_8227743C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277440) {
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
	ctx.lr = 0x82277448;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x82277478;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277484;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277494;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822774c4
	if (cr6.eq) goto loc_822774C4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822774c4
	if (!cr6.eq) goto loc_822774C4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276ba8
	ctx.lr = 0x822774B4;
	sub_82276BA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822774c8
	if (!cr6.eq) goto loc_822774C8;
loc_822774C4:
	// li r31,0
	r31.s64 = 0;
loc_822774C8:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822774f4
	if (cr6.eq) goto loc_822774F4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822774ec
	if (cr6.eq) goto loc_822774EC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822774E4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822774f0
	goto loc_822774F0;
loc_822774EC:
	// li r11,0
	r11.s64 = 0;
loc_822774F0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822774F4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277518
	if (cr6.eq) goto loc_82277518;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277508;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227751c
	if (cr6.eq) goto loc_8227751C;
loc_82277518:
	// li r11,0
	r11.s64 = 0;
loc_8227751C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82277440) {
	__imp__sub_82277440(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277528) {
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
	ctx.lr = 0x82277530;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x82277554;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277560;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277570;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277594
	if (cr6.eq) goto loc_82277594;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276c18
	ctx.lr = 0x82277584;
	sub_82276C18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277598
	if (!cr6.eq) goto loc_82277598;
loc_82277594:
	// li r30,0
	r30.s64 = 0;
loc_82277598:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822775d0
	if (cr6.eq) goto loc_822775D0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822775c8
	if (cr6.eq) goto loc_822775C8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x822775B4;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_822775C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_822775D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82277528) {
	__imp__sub_82277528(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822775DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822775DC) {
	__imp__sub_822775DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822775E0) {
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
	ctx.lr = 0x822775E8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x82277618;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277624;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277634;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277664
	if (cr6.eq) goto loc_82277664;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277664
	if (!cr6.eq) goto loc_82277664;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276c90
	ctx.lr = 0x82277654;
	sub_82276C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277668
	if (!cr6.eq) goto loc_82277668;
loc_82277664:
	// li r31,0
	r31.s64 = 0;
loc_82277668:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82277694
	if (cr6.eq) goto loc_82277694;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227768c
	if (cr6.eq) goto loc_8227768C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277684;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82277690
	goto loc_82277690;
loc_8227768C:
	// li r11,0
	r11.s64 = 0;
loc_82277690:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82277694:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822776b8
	if (cr6.eq) goto loc_822776B8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822776A8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822776bc
	if (cr6.eq) goto loc_822776BC;
loc_822776B8:
	// li r11,0
	r11.s64 = 0;
loc_822776BC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822775E0) {
	__imp__sub_822775E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822776C8) {
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
	ctx.lr = 0x822776D0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x822776F4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277700;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277710;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277734
	if (cr6.eq) goto loc_82277734;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276d08
	ctx.lr = 0x82277724;
	sub_82276D08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277738
	if (!cr6.eq) goto loc_82277738;
loc_82277734:
	// li r30,0
	r30.s64 = 0;
loc_82277738:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277770
	if (cr6.eq) goto loc_82277770;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277768
	if (cr6.eq) goto loc_82277768;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277754;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82277768:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277770:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822776C8) {
	__imp__sub_822776C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227777C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227777C) {
	__imp__sub_8227777C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277780) {
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
	ctx.lr = 0x82277788;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x822777AC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x822777B8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x822777C8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822777f0
	if (cr6.eq) goto loc_822777F0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618f90
	ctx.lr = 0x822777E0;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822777f4
	if (!cr6.eq) goto loc_822777F4;
loc_822777F0:
	// li r30,0
	r30.s64 = 0;
loc_822777F4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8227782c
	if (cr6.eq) goto loc_8227782C;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277824
	if (cr6.eq) goto loc_82277824;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277810;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82277824:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8227782C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82277780) {
	__imp__sub_82277780(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277838) {
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
	ctx.lr = 0x82277840;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x82277870;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8227787C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x8227788C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822778c0
	if (cr6.eq) goto loc_822778C0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822778c0
	if (!cr6.eq) goto loc_822778C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618f80
	ctx.lr = 0x822778B0;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822778c4
	if (!cr6.eq) goto loc_822778C4;
loc_822778C0:
	// li r31,0
	r31.s64 = 0;
loc_822778C4:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822778f0
	if (cr6.eq) goto loc_822778F0;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822778e8
	if (cr6.eq) goto loc_822778E8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822778E0;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822778ec
	goto loc_822778EC;
loc_822778E8:
	// li r11,0
	r11.s64 = 0;
loc_822778EC:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822778F0:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277914
	if (cr6.eq) goto loc_82277914;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277904;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82277918
	if (cr6.eq) goto loc_82277918;
loc_82277914:
	// li r11,0
	r11.s64 = 0;
loc_82277918:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82277838) {
	__imp__sub_82277838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82277924) {
	__imp__sub_82277924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277928) {
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
	ctx.lr = 0x82277930;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x82277954;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277960;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277970;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277994
	if (cr6.eq) goto loc_82277994;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276d78
	ctx.lr = 0x82277984;
	sub_82276D78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277998
	if (!cr6.eq) goto loc_82277998;
loc_82277994:
	// li r30,0
	r30.s64 = 0;
loc_82277998:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822779d0
	if (cr6.eq) goto loc_822779D0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822779c8
	if (cr6.eq) goto loc_822779C8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x822779B4;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_822779C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_822779D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82277928) {
	__imp__sub_82277928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822779DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822779DC) {
	__imp__sub_822779DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822779E0) {
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
	ctx.lr = 0x822779E8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x82277A18;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277A24;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277A34;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277a64
	if (cr6.eq) goto loc_82277A64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277a64
	if (!cr6.eq) goto loc_82277A64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276de8
	ctx.lr = 0x82277A54;
	sub_82276DE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277a68
	if (!cr6.eq) goto loc_82277A68;
loc_82277A64:
	// li r31,0
	r31.s64 = 0;
loc_82277A68:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82277a94
	if (cr6.eq) goto loc_82277A94;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277a8c
	if (cr6.eq) goto loc_82277A8C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277A84;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82277a90
	goto loc_82277A90;
loc_82277A8C:
	// li r11,0
	r11.s64 = 0;
loc_82277A90:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82277A94:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277ab8
	if (cr6.eq) goto loc_82277AB8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277AA8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82277abc
	if (cr6.eq) goto loc_82277ABC;
loc_82277AB8:
	// li r11,0
	r11.s64 = 0;
loc_82277ABC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822779E0) {
	__imp__sub_822779E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277AC8) {
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
	ctx.lr = 0x82277AD0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x82277AF4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277B00;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277B10;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277b34
	if (cr6.eq) goto loc_82277B34;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276e58
	ctx.lr = 0x82277B24;
	sub_82276E58(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277b38
	if (!cr6.eq) goto loc_82277B38;
loc_82277B34:
	// li r30,0
	r30.s64 = 0;
loc_82277B38:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277b70
	if (cr6.eq) goto loc_82277B70;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277b68
	if (cr6.eq) goto loc_82277B68;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277B54;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82277B68:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277B70:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82277AC8) {
	__imp__sub_82277AC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82277B7C) {
	__imp__sub_82277B7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277B80) {
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
	ctx.lr = 0x82277B88;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x82277BAC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277BB8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277BC8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277bec
	if (cr6.eq) goto loc_82277BEC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276ef0
	ctx.lr = 0x82277BDC;
	sub_82276EF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277bf0
	if (!cr6.eq) goto loc_82277BF0;
loc_82277BEC:
	// li r30,0
	r30.s64 = 0;
loc_82277BF0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277c28
	if (cr6.eq) goto loc_82277C28;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277c20
	if (cr6.eq) goto loc_82277C20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277C0C;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82277C20:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277C28:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82277B80) {
	__imp__sub_82277B80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82277C34) {
	__imp__sub_82277C34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277C38) {
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
	ctx.lr = 0x82277C40;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x82277C70;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277C7C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277C8C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277cbc
	if (cr6.eq) goto loc_82277CBC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277cbc
	if (!cr6.eq) goto loc_82277CBC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276fc0
	ctx.lr = 0x82277CAC;
	sub_82276FC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277cc0
	if (!cr6.eq) goto loc_82277CC0;
loc_82277CBC:
	// li r31,0
	r31.s64 = 0;
loc_82277CC0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82277cec
	if (cr6.eq) goto loc_82277CEC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277ce4
	if (cr6.eq) goto loc_82277CE4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277CDC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82277ce8
	goto loc_82277CE8;
loc_82277CE4:
	// li r11,0
	r11.s64 = 0;
loc_82277CE8:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82277CEC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277d10
	if (cr6.eq) goto loc_82277D10;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277D00;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82277d14
	if (cr6.eq) goto loc_82277D14;
loc_82277D10:
	// li r11,0
	r11.s64 = 0;
loc_82277D14:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82277C38) {
	__imp__sub_82277C38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82277D20) {
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
	ctx.lr = 0x82277D28;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8368(r1)
	ea = -8368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82299578
	ctx.lr = 0x82277D3C;
	sub_82299578(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// bl 0x821c9788
	ctx.lr = 0x82277D44;
	sub_821C9788(ctx, base);
	// addis r31,r29,2
	r31.s64 = r29.s64 + 131072;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// addi r31,r31,292
	r31.s64 = r31.s64 + 292;
	// li r23,-1
	r23.s64 = -1;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r22,-32121
	r22.s64 = -2105081856;
loc_82277D68:
	// lbz r11,-204(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -204);
	// addi r30,r31,-8
	r30.s64 = r31.s64 + -8;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x82277d98
	if (!cr6.eq) goto loc_82277D98;
	// lwz r11,-200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -200);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82277d98
	if (cr6.lt) goto loc_82277D98;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r24,1
	r24.s64 = 1;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bge cr6,0x82277d98
	if (!cr6.lt) goto loc_82277D98;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_82277D98:
	// lbz r11,-184(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -184);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x82277eb4
	if (!cr6.eq) goto loc_82277EB4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277eb4
	if (cr6.eq) goto loc_82277EB4;
	// lwz r10,16540(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16540);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x82277e1c
	if (!cr6.eq) goto loc_82277E1C;
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// lwz r4,68(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x8229bbc8
	ctx.lr = 0x82277DC8;
	sub_8229BBC8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,8280
	r11.s64 = r11.s64 + 8280;
	// addi r3,r11,8192
	ctx.r3.s64 = r11.s64 + 8192;
	// bl 0x82500848
	ctx.lr = 0x82277DD8;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277e1c
	if (cr6.eq) goto loc_82277E1C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,8280
	r11.s64 = r11.s64 + 8280;
	// addi r3,r11,8192
	ctx.r3.s64 = r11.s64 + 8192;
	// bl 0x82500830
	ctx.lr = 0x82277DF4;
	sub_82500830(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// beq cr6,0x82277e14
	if (cr6.eq) goto loc_82277E14;
	// lbz r10,22300(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,22300(r11)
	PPC_STORE_U8(r11.u32 + 22300, ctx.r9.u8);
	// b 0x82277e1c
	goto loc_82277E1C;
loc_82277E14:
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b450
	ctx.lr = 0x82277E1C;
	sub_8229B450(ctx, base);
loc_82277E1C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// lwz r11,8264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8264);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82277e44
	if (cr6.eq) goto loc_82277E44;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82277e44
	if (cr6.eq) goto loc_82277E44;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82277e48
	if (!cr6.eq) goto loc_82277E48;
loc_82277E44:
	// li r11,1
	r11.s64 = 1;
loc_82277E48:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277e94
	if (cr6.eq) goto loc_82277E94;
	// lwz r4,68(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x8229bbc8
	ctx.lr = 0x82277E5C;
	sub_8229BBC8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r3,r11,8192
	ctx.r3.s64 = r11.s64 + 8192;
	// bl 0x82500848
	ctx.lr = 0x82277E6C;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277eb4
	if (cr6.eq) goto loc_82277EB4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,8196
	ctx.r3.s64 = r11.s64 + 8196;
	// bl 0x82500830
	ctx.lr = 0x82277E84;
	sub_82500830(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x8229b450
	ctx.lr = 0x82277E90;
	sub_8229B450(ctx, base);
	// b 0x82277eb4
	goto loc_82277EB4;
loc_82277E94:
	// lwz r5,22296(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22296);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x82277eb4
	if (cr6.lt) goto loc_82277EB4;
	// addi r4,r30,-204
	ctx.r4.s64 = r30.s64 + -204;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822761d0
	ctx.lr = 0x82277EAC;
	sub_822761D0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r23,22296(r11)
	PPC_STORE_U32(r11.u32 + 22296, r23.u32);
loc_82277EB4:
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82277EBC;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// addi r11,r11,8280
	r11.s64 = r11.s64 + 8280;
	// addi r3,r11,8192
	ctx.r3.s64 = r11.s64 + 8192;
	// bl 0x82500848
	ctx.lr = 0x82277EE0;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r11,22300(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82277f7c
	if (!cr6.eq) goto loc_82277F7C;
	// bl 0x822912c8
	ctx.lr = 0x82277F20;
	sub_822912C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277f50
	if (cr6.eq) goto loc_82277F50;
	// lwz r3,-8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// bl 0x82291a20
	ctx.lr = 0x82277F34;
	sub_82291A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277f50
	if (!cr6.eq) goto loc_82277F50;
	// bl 0x822914e8
	ctx.lr = 0x82277F44;
	sub_822914E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
loc_82277F50:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82276528
	ctx.lr = 0x82277F5C;
	sub_82276528(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,22300(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,22300(r11)
	PPC_STORE_U8(r11.u32 + 22300, ctx.r9.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b450
	ctx.lr = 0x82277F78;
	sub_8229B450(ctx, base);
	// b 0x82278100
	goto loc_82278100;
loc_82277F7C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238f550
	ctx.lr = 0x82277F84;
	sub_8238F550(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82277F90;
	sub_822A3998(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b4f0
	ctx.lr = 0x82277FA4;
	sub_8229B4F0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82277FAC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82277FBC;
	sub_82270170(ctx, base);
	// bl 0x82272e98
	ctx.lr = 0x82277FC0;
	sub_82272E98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8227802c
	if (!cr6.eq) goto loc_8227802C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82277FD4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82277FE4;
	sub_82270170(ctx, base);
	// bl 0x82272ec0
	ctx.lr = 0x82277FE8;
	sub_82272EC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278024
	if (cr6.eq) goto loc_82278024;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r20,1220(r30)
	r20.u64 = PPC_LOAD_U32(r30.u32 + 1220);
	// bl 0x82388580
	ctx.lr = 0x82278000;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82278010;
	sub_82270170(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// bl 0x82272ee8
	ctx.lr = 0x82278018;
	sub_82272EE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8227802c
	if (!cr6.eq) goto loc_8227802C;
loc_82278024:
	// li r11,0
	r11.s64 = 0;
	// b 0x82278030
	goto loc_82278030;
loc_8227802C:
	// li r11,1
	r11.s64 = 1;
loc_82278030:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822780c4
	if (!cr6.eq) goto loc_822780C4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82393148
	ctx.lr = 0x82278044;
	sub_82393148(ctx, base);
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278054;
	sub_823924B0(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278064;
	sub_823924B0(ctx, base);
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278074;
	sub_823924B0(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278084;
	sub_823924B0(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278094;
	sub_823924B0(ctx, base);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x822780A4;
	sub_823924B0(ctx, base);
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x822780B4;
	sub_823924B0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x822780C4;
	sub_823924B0(ctx, base);
loc_822780C4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8e10
	ctx.lr = 0x822780D0;
	sub_822A8E10(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822aae48
	ctx.lr = 0x822780DC;
	sub_822AAE48(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,22300(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,22300(r11)
	PPC_STORE_U8(r11.u32 + 22300, ctx.r9.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b450
	ctx.lr = 0x822780F8;
	sub_8229B450(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x82278100;
	sub_8238ED78(ctx, base);
loc_82278100:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x82277d68
	if (cr6.lt) goto loc_82277D68;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278198
	if (cr6.eq) goto loc_82278198;
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82278124;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278198
	if (cr6.eq) goto loc_82278198;
	// lwz r11,-3624(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// subf r10,r25,r21
	ctx.r10.s64 = r21.s64 - r25.s64;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x82278198
	if (!cr6.gt) goto loc_82278198;
	// addis r11,r29,2
	r11.s64 = r29.s64 + 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82278154:
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// bne cr6,0x8227816c
	if (!cr6.eq) goto loc_8227816C;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x82278184
	if (!cr6.lt) goto loc_82278184;
loc_8227816C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82278154
	if (cr6.lt) goto loc_82278154;
	// addi r1,r1,8368
	ctx.r1.s64 = ctx.r1.s64 + 8368;
	// b 0x823d9228
	return;
loc_82278184:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// bl 0x8229a828
	ctx.lr = 0x82278198;
	sub_8229A828(ctx, base);
loc_82278198:
	// addi r1,r1,8368
	ctx.r1.s64 = ctx.r1.s64 + 8368;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_82277D20) {
	__imp__sub_82277D20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822781A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822781B0:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x822781b0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822781B0;
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// lwz r8,20(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r8,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r8.u32);
	// lwz r7,24(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
	// lwz r6,28(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// stw r6,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r6.u32);
	// lhz r5,32(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 32);
	// sth r5,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, ctx.r5.u16);
	// lhz r11,34(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 34);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// lhz r10,36(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 36);
	// sth r10,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r10.u16);
	// lhz r9,38(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 38);
	// sth r9,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r9.u16);
	// lhz r8,40(r4)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + 40);
	// sth r8,40(r3)
	PPC_STORE_U16(ctx.r3.u32 + 40, ctx.r8.u16);
	// lhz r7,42(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 42);
	// sth r7,42(r3)
	PPC_STORE_U16(ctx.r3.u32 + 42, ctx.r7.u16);
	// lbz r6,44(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 44);
	// stb r6,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, ctx.r6.u8);
	// lbz r5,48(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// lbz r11,48(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 48);
	// rlwimi r5,r11,0,24,24
	ctx.r5.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x80) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFF7F);
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stb r10,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r10.u8);
	// lbz r8,48(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 48);
	// rlwimi r9,r8,0,25,25
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0x40) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFBF);
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stb r7,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r7.u8);
	// lbz r5,48(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 48);
	// rlwimi r6,r5,0,26,26
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0x20) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r6,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r6.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822781A0) {
	__imp__sub_822781A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278260) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r8
	ctx.r9.u64 = r11.u64 + ctx.r8.u64;
	// addis r11,r9,2
	r11.s64 = ctx.r9.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82278288:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x822782a8
	if (cr6.eq) goto loc_822782A8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82278288
	if (cr6.lt) goto loc_82278288;
	// blr 
	return;
loc_822782A8:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addis r11,r11,2
	r11.s64 = r11.s64 + 131072;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,212(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addis r11,r8,2
	r11.s64 = ctx.r8.s64 + 131072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r11,292
	r11.s64 = r11.s64 + 292;
	// li r9,31
	ctx.r9.s64 = 31;
loc_822782E8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278304
	if (cr6.eq) goto loc_82278304;
	// lwz r10,16540(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16540);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x82278304
	if (!cr6.eq) goto loc_82278304;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
loc_82278304:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// bne 0x822782e8
	if (!cr0.eq) goto loc_822782E8;
	// lwz r6,4(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// addi r3,r3,8280
	ctx.r3.s64 = ctx.r3.s64 + 8280;
	// bge cr6,0x8227832c
	if (!cr6.lt) goto loc_8227832C;
	// lwz r7,8(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r5,68(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// b 0x8229b9b0
	sub_8229B9B0(ctx, base);
	return;
loc_8227832C:
	// lwz r5,68(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// b 0x8229ba60
	sub_8229BA60(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82278260) {
	__imp__sub_82278260(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82278334) {
	__imp__sub_82278334(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278338) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r8
	ctx.r9.u64 = r11.u64 + ctx.r8.u64;
	// addis r11,r9,2
	r11.s64 = ctx.r9.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82278360:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// beq cr6,0x82278380
	if (cr6.eq) goto loc_82278380;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82278360
	if (cr6.lt) goto loc_82278360;
	// blr 
	return;
loc_82278380:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addis r11,r11,2
	r11.s64 = r11.s64 + 131072;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,212(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r4,68(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// b 0x8229b5c8
	sub_8229B5C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82278338) {
	__imp__sub_82278338(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822783B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822783B4) {
	__imp__sub_822783B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822783B8) {
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
	ctx.lr = 0x822783C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// lwz r5,8(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 + r31.u64;
	// addis r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 131072;
	// addi r10,r10,84
	ctx.r10.s64 = ctx.r10.s64 + 84;
loc_822783F4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x82278418
	if (cr6.eq) goto loc_82278418;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,220
	ctx.r10.s64 = ctx.r10.s64 + 220;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x822783f4
	if (cr6.lt) goto loc_822783F4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82278418:
	// mulli r11,r11,220
	r11.s64 = r11.s64 * 220;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addis r6,r11,2
	ctx.r6.s64 = r11.s64 + 131072;
	// addi r6,r6,80
	ctx.r6.s64 = ctx.r6.s64 + 80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822784d4
	if (cr6.eq) goto loc_822784D4;
	// lwz r7,212(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 212);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822784d4
	if (cr6.eq) goto loc_822784D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822768e8
	ctx.lr = 0x82278444;
	sub_822768E8(ctx, base);
	// lbz r11,22300(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 22300);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278470
	if (cr6.eq) goto loc_82278470;
	// lhz r9,22292(r7)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r7.u32 + 22292);
	// lhz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 52);
	// subf r5,r9,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r9.s64;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822784d4
	if (cr6.lt) goto loc_822784D4;
loc_82278470:
	// lwz r11,212(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 212);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// lbz r10,22300(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,22300(r11)
	PPC_STORE_U8(r11.u32 + 22300, ctx.r9.u8);
	// lwz r7,212(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 212);
	// lhz r6,52(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 52);
	// sth r6,22292(r7)
	PPC_STORE_U16(ctx.r7.u32 + 22292, ctx.r6.u16);
	// blt cr6,0x822784d4
	if (cr6.lt) goto loc_822784D4;
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822784b4
	if (cr6.eq) goto loc_822784B4;
	// addi r5,r29,16
	ctx.r5.s64 = r29.s64 + 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274f80
	ctx.lr = 0x822784B4;
	sub_82274F80(ctx, base);
loc_822784B4:
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822784d4
	if (cr6.eq) goto loc_822784D4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275040
	ctx.lr = 0x822784D4;
	sub_82275040(ctx, base);
loc_822784D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822783B8) {
	__imp__sub_822783B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822784DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822784DC) {
	__imp__sub_822784DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822784E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,220
	ctx.r10.s64 = 220;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - r11.s64;
	// addis r8,r9,-2
	ctx.r8.s64 = ctx.r9.s64 + -131072;
	// addi r8,r8,-80
	ctx.r8.s64 = ctx.r8.s64 + -80;
	// divw r7,r8,r10
	ctx.r7.s32 = ctx.r8.s32 / ctx.r10.s32;
	// addic. r10,r7,1
	xer.ca = ctx.r7.u32 > 4294967294;
	ctx.r10.s64 = ctx.r7.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bltlr 
	if (cr0.lt) return;
	// mulli r9,r10,220
	ctx.r9.s64 = ctx.r10.s64 * 220;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// addis r11,r11,2
	r11.s64 = r11.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82278518:
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r3,r11,-4
	ctx.r3.s64 = r11.s64 + -4;
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// bne cr6,0x8227853c
	if (!cr6.eq) goto loc_8227853C;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x8227854c
	if (!cr6.lt) goto loc_8227854C;
loc_8227853C:
	// addic. r10,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r10.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// bge 0x82278518
	if (!cr0.lt) goto loc_82278518;
	// blr 
	return;
loc_8227854C:
	// b 0x8229a828
	sub_8229A828(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822784E0) {
	__imp__sub_822784E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278550) {
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
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// li r10,4
	ctx.r10.s64 = 4;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// stb r10,8(r9)
	PPC_STORE_U8(ctx.r9.u32 + 8, ctx.r10.u8);
	// bne cr6,0x822785cc
	if (!cr6.eq) goto loc_822785CC;
	// lwz r31,212(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82278608
	if (cr6.eq) goto loc_82278608;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32217
	ctx.r10.s64 = -2111373312;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,26936
	ctx.r8.s64 = ctx.r10.s64 + 26936;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// stw r9,22240(r31)
	PPC_STORE_U32(r31.u32 + 22240, ctx.r9.u32);
	// stw r8,22244(r31)
	PPC_STORE_U32(r31.u32 + 22244, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x822785B4;
	sub_82130000(ctx, base);
	// stw r3,22240(r31)
	PPC_STORE_U32(r31.u32 + 22240, ctx.r3.u32);
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
loc_822785CC:
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// bne cr6,0x82278608
	if (!cr6.eq) goto loc_82278608;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822785E0;
	sub_822A39C8(ctx, base);
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82278608
	if (cr6.eq) goto loc_82278608;
	// bl 0x82387b90
	ctx.lr = 0x822785F0;
	sub_82387B90(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,1344(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x822761d0
	ctx.lr = 0x82278608;
	sub_822761D0(ctx, base);
loc_82278608:
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

PPC_WEAK_FUNC(sub_82278550) {
	__imp__sub_82278550(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227861C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227861C) {
	__imp__sub_8227861C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278620) {
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
	// li r9,22304
	ctx.r9.s64 = 22304;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// beq cr6,0x8227866c
	if (cr6.eq) goto loc_8227866C;
	// mulli r3,r10,22304
	ctx.r3.s64 = ctx.r10.s64 * 22304;
	// bl 0x82130528
	ctx.lr = 0x82278668;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8227866C:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x8227867C;
	sub_821F10E0(ctx, base);
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

PPC_WEAK_FUNC(sub_82278620) {
	__imp__sub_82278620(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82278694) {
	__imp__sub_82278694(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278698) {
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
	ctx.lr = 0x822786A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x8229af08
	ctx.lr = 0x822786B0;
	sub_8229AF08(ctx, base);
	// addi r29,r31,60
	r29.s64 = r31.s64 + 60;
	// addi r30,r29,52
	r30.s64 = r29.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618750
	ctx.lr = 0x822786C0;
	sub_82618750(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
	// sth r11,144(r31)
	PPC_STORE_U16(r31.u32 + 144, r11.u16);
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// stb r11,146(r31)
	PPC_STORE_U8(r31.u32 + 146, r11.u8);
	// bl 0x82618750
	ctx.lr = 0x822786DC;
	sub_82618750(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618610
	ctx.lr = 0x822786F0;
	sub_82618610(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82278698) {
	__imp__sub_82278698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822786FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822786FC) {
	__imp__sub_822786FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278700) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r11,0(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// lhz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 0);
	// rlwinm r9,r11,25,7,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// rlwinm r8,r10,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// xor r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// rlwinm r10,r10,0,25,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// subfc r8,r10,r9
	xer.ca = ctx.r9.u32 >= ctx.r10.u32;
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// beq cr6,0x82278740
	if (cr6.eq) goto loc_82278740;
	// subfc r8,r9,r10
	xer.ca = ctx.r10.u32 >= ctx.r9.u32;
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
loc_82278740:
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r7,31
	ctx.r3.u64 = ctx.r7.u32 & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82278700) {
	__imp__sub_82278700(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8227874C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8227874C) {
	__imp__sub_8227874C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278750) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r9,5620(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5620);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82278764
	if (!cr6.eq) goto loc_82278764;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82278764:
	// lwz r11,5616(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5616);
	// lis r8,20971
	ctx.r8.s64 = 1374355456;
	// addi r10,r3,2812
	ctx.r10.s64 = ctx.r3.s64 + 2812;
	// lhz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// ori r5,r8,34079
	ctx.r5.u64 = ctx.r8.u64 | 34079;
	// rlwinm r4,r7,25,7,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// mulhw r3,r6,r5
	ctx.r3.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32)) >> 32;
	// srawi r11,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r11.s64 = ctx.r3.s32 >> 4;
	// clrlwi r8,r7,16
	ctx.r8.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// rlwinm r8,r8,0,25,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mulli r9,r11,50
	ctx.r9.s64 = r11.s64 * 50;
	// subf r7,r9,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r9.s64;
	// mulli r11,r7,56
	r11.s64 = ctx.r7.s64 * 56;
	// lhzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + ctx.r10.u32);
	// rlwinm r5,r6,25,7,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r11,r6,16
	r11.u64 = ctx.r6.u32 & 0xFFFF;
	// xor r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 ^ ctx.r4.u64;
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r8,16
	ctx.r10.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// subfc r9,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// beq cr6,0x822787d4
	if (cr6.eq) goto loc_822787D4;
	// subfc r9,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
loc_822787D4:
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,31
	r11.u64 = ctx.r8.u32 & 0x1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82278750) {
	__imp__sub_82278750(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822787EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822787EC) {
	__imp__sub_822787EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822787F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,5620(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5620);
	// li r8,50
	ctx.r8.s64 = 50;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r9,r3,2812
	ctx.r9.s64 = ctx.r3.s64 + 2812;
	// li r7,0
	ctx.r7.s64 = 0;
loc_82278808:
	// lwz r11,2804(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x8227881c
	if (!cr6.eq) goto loc_8227881C;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_8227881C:
	// mulli r10,r11,56
	ctx.r10.s64 = r11.s64 * 56;
	// lhz r11,0(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// lhzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r5,r10,25,7,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// rlwinm r6,r11,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// xor r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// rlwinm r10,r10,0,25,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// subfc r6,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	ctx.r6.s64 = ctx.r10.s64 - r11.s64;
	// beq cr6,0x82278860
	if (cr6.eq) goto loc_82278860;
	// subfc r6,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r6.s64 = r11.s64 - ctx.r10.s64;
loc_82278860:
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r5,31
	r11.u64 = ctx.r5.u32 & 0x1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r11,2808(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2808);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,2804(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,2808(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2808, ctx.r10.u32);
	// stw r11,2804(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2804, r11.u32);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x822788a0
	if (!cr6.eq) goto loc_822788A0;
	// stw r7,2804(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2804, ctx.r7.u32);
loc_822788A0:
	// lwz r11,5620(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5620);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82278808
	if (!cr6.eq) goto loc_82278808;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822787F0) {
	__imp__sub_822787F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822788B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822788B4) {
	__imp__sub_822788B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822788B8) {
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
	ctx.lr = 0x822788C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,50
	r30.s64 = 50;
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82278940
	if (cr6.eq) goto loc_82278940;
	// li r28,0
	r28.s64 = 0;
loc_822788E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275558
	ctx.lr = 0x822788E8;
	sub_82275558(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82278700
	ctx.lr = 0x822788F8;
	sub_82278700(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278940
	if (cr6.eq) goto loc_82278940;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82278940
	if (cr6.lt) goto loc_82278940;
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,2804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, ctx.r10.u32);
	// stw r11,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r11.u32);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x82278930
	if (!cr6.eq) goto loc_82278930;
	// stw r28,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r28.u32);
loc_82278930:
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822788e0
	if (!cr6.eq) goto loc_822788E0;
loc_82278940:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822788B8) {
	__imp__sub_822788B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278948) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822789b0
	if (cr6.eq) goto loc_822789B0;
loc_8227896C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x822789a4
	if (cr6.eq) goto loc_822789A4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822789a4
	if (!cr6.eq) goto loc_822789A4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e7c48
	ctx.lr = 0x82278998;
	sub_824E7C48(ctx, base);
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r10.u8);
loc_822789A4:
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8227896c
	if (!cr6.eq) goto loc_8227896C;
loc_822789B0:
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

PPC_WEAK_FUNC(sub_82278948) {
	__imp__sub_82278948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822789C8) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x8229afa8
	ctx.lr = 0x822789F0;
	sub_8229AFA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278a1c
	if (cr6.eq) goto loc_82278A1C;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82277088
	ctx.lr = 0x82278A0C;
	sub_82277088(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278a20
	if (!cr6.eq) goto loc_82278A20;
loc_82278A1C:
	// li r11,0
	r11.s64 = 0;
loc_82278A20:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

PPC_WEAK_FUNC(sub_822789C8) {
	__imp__sub_822789C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82278A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82278A3C) {
	__imp__sub_82278A3C(ctx, base);
}

