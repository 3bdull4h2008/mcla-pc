#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8218610C"))) PPC_WEAK_FUNC(sub_8218610C);
PPC_FUNC_IMPL(__imp__sub_8218610C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186110"))) PPC_WEAK_FUNC(sub_82186110);
PPC_FUNC_IMPL(__imp__sub_82186110) {
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
	// li r3,76
	ctx.r3.s64 = 76;
	// bl 0x82130528
	ctx.lr = 0x8218612C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218613c
	if (cr6.eq) goto loc_8218613C;
	// bl 0x82185d80
	ctx.lr = 0x82186138;
	sub_82185D80(ctx, base);
	// b 0x82186140
	goto loc_82186140;
loc_8218613C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82186140:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186154
	if (cr6.eq) goto loc_82186154;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,-25232(r11)
	PPC_STORE_U32(r11.u32 + -25232, ctx.r3.u32);
loc_82186154:
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

__attribute__((alias("__imp__sub_82186168"))) PPC_WEAK_FUNC(sub_82186168);
PPC_FUNC_IMPL(__imp__sub_82186168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25236);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186174"))) PPC_WEAK_FUNC(sub_82186174);
PPC_FUNC_IMPL(__imp__sub_82186174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186178"))) PPC_WEAK_FUNC(sub_82186178);
PPC_FUNC_IMPL(__imp__sub_82186178) {
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
	// bl 0x821d2970
	ctx.lr = 0x82186198;
	sub_821D2970(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,-21892
	ctx.r8.s64 = ctx.r10.s64 + -21892;
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x821378b8
	ctx.lr = 0x821861C8;
	sub_821378B8(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_821861E8"))) PPC_WEAK_FUNC(sub_821861E8);
PPC_FUNC_IMPL(__imp__sub_821861E8) {
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
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x82186208;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218622c
	if (cr6.eq) goto loc_8218622C;
	// bl 0x82180360
	ctx.lr = 0x82186218;
	sub_82180360(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-22028
	ctx.r10.s64 = r11.s64 + -22028;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82186230
	goto loc_82186230;
loc_8218622C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82186230:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186244
	if (cr6.eq) goto loc_82186244;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,-25232(r11)
	PPC_STORE_U32(r11.u32 + -25232, ctx.r3.u32);
loc_82186244:
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

__attribute__((alias("__imp__sub_8218625C"))) PPC_WEAK_FUNC(sub_8218625C);
PPC_FUNC_IMPL(__imp__sub_8218625C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186260"))) PPC_WEAK_FUNC(sub_82186260);
PPC_FUNC_IMPL(__imp__sub_82186260) {
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
	// bl 0x82180370
	ctx.lr = 0x82186280;
	sub_82180370(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186298
	if (cr6.eq) goto loc_82186298;
	// bl 0x82130588
	ctx.lr = 0x82186294;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82186298:
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

__attribute__((alias("__imp__sub_821862B0"))) PPC_WEAK_FUNC(sub_821862B0);
PPC_FUNC_IMPL(__imp__sub_821862B0) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x821862CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821862f0
	if (cr6.eq) goto loc_821862F0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82186178
	ctx.lr = 0x821862DC;
	sub_82186178(ctx, base);
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
loc_821862F0:
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

__attribute__((alias("__imp__sub_82186308"))) PPC_WEAK_FUNC(sub_82186308);
PPC_FUNC_IMPL(__imp__sub_82186308) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8218631C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82186340
	if (cr6.eq) goto loc_82186340;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r4,r11,-22752
	ctx.r4.s64 = r11.s64 + -22752;
	// bl 0x82186178
	ctx.lr = 0x82186330;
	sub_82186178(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82186340:
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

__attribute__((alias("__imp__sub_82186354"))) PPC_WEAK_FUNC(sub_82186354);
PPC_FUNC_IMPL(__imp__sub_82186354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186358"))) PPC_WEAK_FUNC(sub_82186358);
PPC_FUNC_IMPL(__imp__sub_82186358) {
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
	// addi r10,r11,-21892
	ctx.r10.s64 = r11.s64 + -21892;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x82186388;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82180398
	ctx.lr = 0x82186390;
	sub_82180398(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821863a8
	if (cr6.eq) goto loc_821863A8;
	// bl 0x82130588
	ctx.lr = 0x821863A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821863A8:
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

__attribute__((alias("__imp__sub_821863C0"))) PPC_WEAK_FUNC(sub_821863C0);
PPC_FUNC_IMPL(__imp__sub_821863C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lbz r3,-24872(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -24872);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821863CC"))) PPC_WEAK_FUNC(sub_821863CC);
PPC_FUNC_IMPL(__imp__sub_821863CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821863D0"))) PPC_WEAK_FUNC(sub_821863D0);
PPC_FUNC_IMPL(__imp__sub_821863D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-24872(r10)
	PPC_STORE_U8(ctx.r10.u32 + -24872, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821863E0"))) PPC_WEAK_FUNC(sub_821863E0);
PPC_FUNC_IMPL(__imp__sub_821863E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r11,-24864
	r11.s64 = r11.s64 + -24864;
	// li r8,63
	ctx.r8.s64 = 63;
loc_821863F0:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82186438
	if (cr6.eq) goto loc_82186438;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82186444
	if (cr6.eq) goto loc_82186444;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82186450
	if (cr6.eq) goto loc_82186450;
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
	// bgt 0x821863f0
	if (cr0.gt) goto loc_821863F0;
loc_82186438:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// blr 
	return;
loc_82186444:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r10.u8);
	// blr 
	return;
loc_82186450:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218645C"))) PPC_WEAK_FUNC(sub_8218645C);
PPC_FUNC_IMPL(__imp__sub_8218645C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186460"))) PPC_WEAK_FUNC(sub_82186460);
PPC_FUNC_IMPL(__imp__sub_82186460) {
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
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x8218647C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82186494
	if (cr6.eq) goto loc_82186494;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-21228
	ctx.r10.s64 = r11.s64 + -21228;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82186498
	goto loc_82186498;
loc_82186494:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82186498:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821864ac
	if (cr6.eq) goto loc_821864AC;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,-24780(r11)
	PPC_STORE_U32(r11.u32 + -24780, ctx.r3.u32);
loc_821864AC:
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

__attribute__((alias("__imp__sub_821864C0"))) PPC_WEAK_FUNC(sub_821864C0);
PPC_FUNC_IMPL(__imp__sub_821864C0) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// b 0x82192448
	sub_82192448(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821864D8"))) PPC_WEAK_FUNC(sub_821864D8);
PPC_FUNC_IMPL(__imp__sub_821864D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-24760
	ctx.r3.s64 = r11.s64 + -24760;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821864E4"))) PPC_WEAK_FUNC(sub_821864E4);
PPC_FUNC_IMPL(__imp__sub_821864E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821864E8"))) PPC_WEAK_FUNC(sub_821864E8);
PPC_FUNC_IMPL(__imp__sub_821864E8) {
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
	ctx.lr = 0x821864F0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// li r20,0
	r20.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// li r26,16
	r26.s64 = 16;
	// mr r31,r20
	r31.u64 = r20.u64;
	// li r27,7
	r27.s64 = 7;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x82186554
	if (!cr6.eq) goto loc_82186554;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// li r31,1
	r31.s64 = 1;
	// stw r20,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r20.u32);
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// stw r26,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r26.u32);
	// stw r27,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r27.u32);
loc_82186554:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// bne cr6,0x82186598
	if (!cr6.eq) goto loc_82186598;
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r26.u32);
	// stw r27,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r27.u32);
loc_82186598:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8218fe90
	ctx.lr = 0x821865A4;
	sub_8218FE90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821865e4
	if (cr6.eq) goto loc_821865E4;
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r26.u32);
	// stw r27,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r27.u32);
loc_821865E4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8218fe68
	ctx.lr = 0x821865F0;
	sub_8218FE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r22,4
	r22.s64 = 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186630
	if (cr6.eq) goto loc_82186630;
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r9.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r26.u32);
	// stw r27,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r27.u32);
loc_82186630:
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// mr r23,r20
	r23.u64 = r20.u64;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
	// li r25,5
	r25.s64 = 5;
loc_82186644:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8218fe40
	ctx.lr = 0x82186650;
	sub_8218FE40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186688
	if (cr6.eq) goto loc_82186688;
	// stw r28,-8(r30)
	PPC_STORE_U32(r30.u32 + -8, r28.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r25,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r25.u32);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
	// stw r27,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r27.u32);
	// addi r30,r30,28
	r30.s64 = r30.s64 + 28;
loc_82186688:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// cmpwi cr6,r23,8
	cr6.compare<int32_t>(r23.s32, 8, xer);
	// blt cr6,0x82186644
	if (cr6.lt) goto loc_82186644;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x821866dc
	if (!cr6.eq) goto loc_821866DC;
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// lwz r10,276(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r26.u32);
	// stw r27,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r27.u32);
loc_821866DC:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// li r9,9
	ctx.r9.s64 = 9;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// bne cr6,0x82186724
	if (!cr6.eq) goto loc_82186724;
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// lwz r10,284(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r26.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
loc_82186724:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// li r10,8
	ctx.r10.s64 = 8;
	// rlwinm r8,r11,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,16
	cr6.compare<uint32_t>(ctx.r8.u32, 16, xer);
	// bne cr6,0x82186758
	if (!cr6.eq) goto loc_82186758;
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r20,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r20.u32);
	// stw r22,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r22.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
loc_82186758:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// rlwinm r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,32
	cr6.compare<uint32_t>(ctx.r8.u32, 32, xer);
	// bne cr6,0x82186794
	if (!cr6.eq) goto loc_82186794;
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r3,r31,1
	ctx.r3.s64 = r31.s64 + 1;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// stw r22,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r22.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_82186794:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_821867A0"))) PPC_WEAK_FUNC(sub_821867A0);
PPC_FUNC_IMPL(__imp__sub_821867A0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x821867A8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r17,r10
	r17.u64 = ctx.r10.u64;
	// mr r14,r9
	r14.u64 = ctx.r9.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r26,0
	r26.s64 = 0;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// stw r25,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, r25.u32);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// li r16,1
	r16.s64 = 1;
	// mr r23,r26
	r23.u64 = r26.u64;
	// addi r15,r11,-16224
	r15.s64 = r11.s64 + -16224;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x82186840
	if (!cr6.eq) goto loc_82186840;
	// stw r20,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r20.u32);
	// stw r26,4(r22)
	PPC_STORE_U32(r22.u32 + 4, r26.u32);
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,8(r22)
	PPC_STORE_U32(r22.u32 + 8, r11.u32);
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// beq cr6,0x82186820
	if (cr6.eq) goto loc_82186820;
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x8218682c
	goto loc_8218682C;
loc_82186820:
	// ld r11,8(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rlwinm r10,r11,2,26,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3C;
	// lwzx r11,r10,r15
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r15.u32);
loc_8218682C:
	// stw r11,12(r22)
	PPC_STORE_U32(r22.u32 + 12, r11.u32);
	// mr r23,r16
	r23.u64 = r16.u64;
	// ld r11,8(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// stw r10,16(r22)
	PPC_STORE_U32(r22.u32 + 16, ctx.r10.u32);
loc_82186840:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r28,6
	r28.s64 = 6;
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x821868bc
	if (!cr6.eq) goto loc_821868BC;
	// mulli r11,r23,28
	r11.s64 = r23.s64 * 28;
	// lwz r10,324(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// stw r20,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r20.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r5,r6,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r5,2
	cr6.compare<uint32_t>(ctx.r5.u32, 2, xer);
	// beq cr6,0x82186894
	if (cr6.eq) goto loc_82186894;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// b 0x821868a4
	goto loc_821868A4;
loc_82186894:
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,60,4
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 60) & 0xFFFFFFFFFFFFFFF;
	// rlwinm r8,r9,2,26,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r10,r8,r15
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r15.u32);
loc_821868A4:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,60,4
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 60) & 0xFFFFFFFFFFFFFFF;
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
loc_821868BC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r18,7
	r18.s64 = 7;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// bne cr6,0x82186938
	if (!cr6.eq) goto loc_82186938;
	// mulli r11,r23,28
	r11.s64 = r23.s64 * 28;
	// lwz r10,332(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// stw r20,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r20.u32);
	// stw r18,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r18.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r5,r6,0,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r5,4
	cr6.compare<uint32_t>(ctx.r5.u32, 4, xer);
	// beq cr6,0x82186910
	if (cr6.eq) goto loc_82186910;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// b 0x82186920
	goto loc_82186920;
loc_82186910:
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,56,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 56) & 0xFFFFFFFFFFFFFF;
	// rlwinm r8,r9,2,26,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r10,r8,r15
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r15.u32);
loc_82186920:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,56,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 56) & 0xFFFFFFFFFFFFFF;
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
loc_82186938:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// bne cr6,0x821869b0
	if (!cr6.eq) goto loc_821869B0;
	// mulli r11,r23,28
	r11.s64 = r23.s64 * 28;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r20,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r20.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r6,r7,0,28,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r6,8
	cr6.compare<uint32_t>(ctx.r6.u32, 8, xer);
	// beq cr6,0x82186988
	if (cr6.eq) goto loc_82186988;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// b 0x82186998
	goto loc_82186998;
loc_82186988:
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,52,12
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 52) & 0xFFFFFFFFFFFFF;
	// rlwinm r8,r9,2,26,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r10,r8,r15
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r15.u32);
loc_82186998:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,52,12
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 52) & 0xFFFFFFFFFFFFF;
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
loc_821869B0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r9,8
	ctx.r9.s64 = 8;
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// bne cr6,0x82186a18
	if (!cr6.eq) goto loc_82186A18;
	// mulli r11,r23,28
	r11.s64 = r23.s64 * 28;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// stw r20,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r20.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r26,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r26.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r8,r10,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,16
	cr6.compare<uint32_t>(ctx.r8.u32, 16, xer);
	// beq cr6,0x821869f0
	if (cr6.eq) goto loc_821869F0;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// b 0x82186a00
	goto loc_82186A00;
loc_821869F0:
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r8,r10,48,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 48) & 0xFFFFFFFFFFFF;
	// rlwinm r7,r8,2,26,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3C;
	// lwzx r10,r7,r15
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r15.u32);
loc_82186A00:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r8,r10,48,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 48) & 0xFFFFFFFFFFFF;
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
loc_82186A18:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,32
	cr6.compare<uint32_t>(ctx.r10.u32, 32, xer);
	// bne cr6,0x82186a7c
	if (!cr6.eq) goto loc_82186A7C;
	// mulli r11,r23,28
	r11.s64 = r23.s64 * 28;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r20,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r20.u32);
	// stw r16,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r16.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,32
	cr6.compare<uint32_t>(ctx.r9.u32, 32, xer);
	// beq cr6,0x82186a54
	if (cr6.eq) goto loc_82186A54;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// b 0x82186a64
	goto loc_82186A64;
loc_82186A54:
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,44,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 44) & 0xFFFFFFFFFFF;
	// rlwinm r8,r9,2,26,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r10,r8,r15
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r15.u32);
loc_82186A64:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,44,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 44) & 0xFFFFFFFFFFF;
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
loc_82186A7C:
	// mulli r11,r23,28
	r11.s64 = r23.s64 * 28;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// li r29,24
	r29.s64 = 24;
	// li r27,28
	r27.s64 = 28;
	// addi r31,r11,12
	r31.s64 = r11.s64 + 12;
	// li r21,5
	r21.s64 = 5;
	// li r19,3
	r19.s64 = 3;
loc_82186A98:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218fe40
	ctx.lr = 0x82186AA4;
	sub_8218FE40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186ba8
	if (cr6.eq) goto loc_82186BA8;
	// stw r20,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, r20.u32);
	// slw r10,r16,r28
	ctx.r10.u64 = r28.u8 & 0x20 ? 0 : (r16.u32 << (r28.u8 & 0x3F));
	// stw r21,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, r21.u32);
	// lwz r9,0(r17)
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// stw r9,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r9.u32);
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,0(r17)
	PPC_STORE_U32(r17.u32 + 0, ctx.r8.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// cmplw cr6,r6,r10
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r10.u32, xer);
	// beq cr6,0x82186ae8
	if (cr6.eq) goto loc_82186AE8;
	// li r11,0
	r11.s64 = 0;
	// b 0x82186afc
	goto loc_82186AFC;
loc_82186AE8:
	// ld r11,8(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// extsw r10,r29
	ctx.r10.s64 = r29.s32;
	// srd r9,r11,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwinm r8,r9,2,26,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r11,r8,r15
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r15.u32);
loc_82186AFC:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// extsw r24,r29
	r24.s64 = r29.s32;
	// cmpwi cr6,r26,7
	cr6.compare<int32_t>(r26.s32, 7, xer);
	// ld r11,8(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// srd r10,r11,r24
	ctx.r10.u64 = r24.u8 & 0x40 ? 0 : (r11.u64 >> (r24.u8 & 0x7F));
	// clrlwi r9,r10,28
	ctx.r9.u64 = ctx.r10.u32 & 0xF;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// bge cr6,0x82186b9c
	if (!cr6.lt) goto loc_82186B9C;
	// addi r25,r26,1
	r25.s64 = r26.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x8218fe40
	ctx.lr = 0x82186B2C;
	sub_8218FE40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186b9c
	if (cr6.eq) goto loc_82186B9C;
	// ld r11,8(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// extsw r10,r27
	ctx.r10.s64 = r27.s32;
	// srd r9,r11,r24
	ctx.r9.u64 = r24.u8 & 0x40 ? 0 : (r11.u64 >> (r24.u8 & 0x7F));
	// srd r8,r11,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r10.u8 & 0x7F));
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rotlwi r6,r9,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// xor r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 ^ ctx.r6.u64;
	// clrlwi r4,r5,28
	ctx.r4.u64 = ctx.r5.u32 & 0xF;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x82186b9c
	if (!cr6.eq) goto loc_82186B9C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82186b74
	if (!cr6.eq) goto loc_82186B74;
	// stw r19,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r19.u32);
	// b 0x82186b80
	goto loc_82186B80;
loc_82186B74:
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x82186b9c
	if (!cr6.eq) goto loc_82186B9C;
	// stw r18,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r18.u32);
loc_82186B80:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r26,r25
	r26.u64 = r25.u64;
loc_82186B9C:
	// lwz r25,300(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
loc_82186BA8:
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r27,60
	cr6.compare<int32_t>(r27.s32, 60, xer);
	// blt cr6,0x82186a98
	if (cr6.lt) goto loc_82186A98;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218fe68
	ctx.lr = 0x82186BCC;
	sub_8218FE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186c38
	if (cr6.eq) goto loc_82186C38;
	// mulli r11,r23,28
	r11.s64 = r23.s64 * 28;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r20,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r20.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r14)
	ctx.r9.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r10,0(r14)
	ctx.r10.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,0(r14)
	PPC_STORE_U32(r14.u32 + 0, ctx.r8.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r6,r7,0,17,17
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r6,16384
	cr6.compare<uint32_t>(ctx.r6.u32, 16384, xer);
	// beq cr6,0x82186c18
	if (cr6.eq) goto loc_82186C18;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82186c24
	goto loc_82186C24;
loc_82186C18:
	// lbz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// rlwinm r9,r10,2,26,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3C;
	// lwzx r10,r9,r15
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + r15.u32);
loc_82186C24:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// lbz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// clrlwi r9,r10,28
	ctx.r9.u64 = ctx.r10.u32 & 0xF;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
loc_82186C38:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218fe90
	ctx.lr = 0x82186C44;
	sub_8218FE90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186cb8
	if (cr6.eq) goto loc_82186CB8;
	// mulli r11,r23,28
	r11.s64 = r23.s64 * 28;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// stw r20,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r20.u32);
	// stw r19,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r19.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r7,r8,0,16,16
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r7,32768
	cr6.compare<uint32_t>(ctx.r7.u32, 32768, xer);
	// beq cr6,0x82186c8c
	if (cr6.eq) goto loc_82186C8C;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82186c9c
	goto loc_82186C9C;
loc_82186C8C:
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,4,60
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 4) & 0xF;
	// rlwinm r8,r9,2,26,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r10,r8,r15
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r15.u32);
loc_82186C9C:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r3,r23,1
	ctx.r3.s64 = r23.s64 + 1;
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// rldicl r9,r10,4,60
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 4) & 0xF;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_82186CB8:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82186CC4"))) PPC_WEAK_FUNC(sub_82186CC4);
PPC_FUNC_IMPL(__imp__sub_82186CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186CC8"))) PPC_WEAK_FUNC(sub_82186CC8);
PPC_FUNC_IMPL(__imp__sub_82186CC8) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82186d14
	if (cr6.eq) goto loc_82186D14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82186CF8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82186d14
	if (cr6.eq) goto loc_82186D14;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821916f8
	ctx.lr = 0x82186D14;
	sub_821916F8(ctx, base);
loc_82186D14:
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

__attribute__((alias("__imp__sub_82186D2C"))) PPC_WEAK_FUNC(sub_82186D2C);
PPC_FUNC_IMPL(__imp__sub_82186D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186D30"))) PPC_WEAK_FUNC(sub_82186D30);
PPC_FUNC_IMPL(__imp__sub_82186D30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_82186D50:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82186d50
	if (cr6.eq) goto loc_82186D50;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186D90"))) PPC_WEAK_FUNC(sub_82186D90);
PPC_FUNC_IMPL(__imp__sub_82186D90) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82186D98;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bge cr6,0x82186f00
	if (!cr6.lt) goto loc_82186F00;
	// add r11,r4,r5
	r11.u64 = ctx.r4.u64 + ctx.r5.u64;
	// clrlwi r9,r6,24
	ctx.r9.u64 = ctx.r6.u32 & 0xFF;
	// rlwinm r8,r11,29,3,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrlwi r6,r11,27
	ctx.r6.u64 = r11.u32 & 0x1F;
	// neg r31,r9
	r31.s64 = -ctx.r9.s64;
	// slw r4,r10,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// lwzx r5,r8,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// rlwinm r7,r11,29,3,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// xor r6,r31,r5
	ctx.r6.u64 = r31.u64 ^ ctx.r5.u64;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// and r4,r4,r6
	ctx.r4.u64 = ctx.r4.u64 & ctx.r6.u64;
	// clrlwi r6,r11,27
	ctx.r6.u64 = r11.u32 & 0x1F;
	// xor r7,r4,r5
	ctx.r7.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// slw r5,r10,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// stwx r7,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u32);
	// clrlwi r6,r11,27
	ctx.r6.u64 = r11.u32 & 0x1F;
	// addi r8,r3,8
	ctx.r8.s64 = ctx.r3.s64 + 8;
	// slw r29,r10,r6
	r29.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// rlwinm r7,r11,29,3,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// rlwinm r4,r11,29,3,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// lwz r30,0(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r28,r11,27
	r28.u64 = r11.u32 & 0x1F;
	// clrlwi r26,r11,27
	r26.u64 = r11.u32 & 0x1F;
	// xor r6,r30,r31
	ctx.r6.u64 = r30.u64 ^ r31.u64;
	// slw r28,r10,r28
	r28.u64 = r28.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r28.u8 & 0x3F));
	// and r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 & ctx.r6.u64;
	// slw r26,r10,r26
	r26.u64 = r26.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r26.u8 & 0x3F));
	// xor r6,r5,r30
	ctx.r6.u64 = ctx.r5.u64 ^ r30.u64;
	// rlwinm r5,r11,29,3,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// add r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r8,r3,12
	ctx.r8.s64 = ctx.r3.s64 + 12;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// rlwinm r6,r11,29,3,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// slw r30,r10,r7
	r30.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r7.u8 & 0x3F));
	// lwz r27,0(r9)
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r7,r11,29,3,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// mr r25,r27
	r25.u64 = r27.u64;
	// xor r27,r27,r31
	r27.u64 = r27.u64 ^ r31.u64;
	// and r29,r29,r27
	r29.u64 = r29.u64 & r27.u64;
	// clrlwi r27,r11,27
	r27.u64 = r11.u32 & 0x1F;
	// xor r29,r29,r25
	r29.u64 = r29.u64 ^ r25.u64;
	// stw r29,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r29.u32);
	// add r9,r4,r8
	ctx.r9.u64 = ctx.r4.u64 + ctx.r8.u64;
	// slw r4,r10,r27
	ctx.r4.u64 = r27.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r27.u8 & 0x3F));
	// addi r8,r3,16
	ctx.r8.s64 = ctx.r3.s64 + 16;
	// lwz r29,0(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r27,r29
	r27.u64 = r29.u64;
	// xor r29,r29,r31
	r29.u64 = r29.u64 ^ r31.u64;
	// and r29,r28,r29
	r29.u64 = r28.u64 & r29.u64;
	// xor r29,r29,r27
	r29.u64 = r29.u64 ^ r27.u64;
	// stw r29,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r29.u32);
	// add r9,r5,r8
	ctx.r9.u64 = ctx.r5.u64 + ctx.r8.u64;
	// addi r8,r3,20
	ctx.r8.s64 = ctx.r3.s64 + 20;
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// xor r29,r29,r31
	r29.u64 = r29.u64 ^ r31.u64;
	// and r30,r30,r29
	r30.u64 = r30.u64 & r29.u64;
	// xor r5,r30,r5
	ctx.r5.u64 = r30.u64 ^ ctx.r5.u64;
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// add r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 + ctx.r8.u64;
	// addi r8,r3,24
	ctx.r8.s64 = ctx.r3.s64 + 24;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// xor r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 ^ r31.u64;
	// and r5,r26,r5
	ctx.r5.u64 = r26.u64 & ctx.r5.u64;
	// xor r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// add r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// xor r7,r8,r31
	ctx.r7.u64 = ctx.r8.u64 ^ r31.u64;
	// addi r8,r3,28
	ctx.r8.s64 = ctx.r3.s64 + 28;
	// and r6,r4,r7
	ctx.r6.u64 = ctx.r4.u64 & ctx.r7.u64;
	// clrlwi r4,r11,27
	ctx.r4.u64 = r11.u32 & 0x1F;
	// xor r5,r6,r5
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// rlwinm r7,r11,29,3,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// slw r3,r10,r4
	ctx.r3.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r4.u8 & 0x3F));
	// lwzx r11,r7,r8
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// xor r9,r11,r31
	ctx.r9.u64 = r11.u64 ^ r31.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// and r6,r3,r9
	ctx.r6.u64 = ctx.r3.u64 & ctx.r9.u64;
	// xor r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r10.u64;
	// stwx r5,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r5.u32);
	// b 0x823d923c
	return;
loc_82186F00:
	// add r9,r4,r5
	ctx.r9.u64 = ctx.r4.u64 + ctx.r5.u64;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r9,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// clrlwi r8,r6,24
	ctx.r8.u64 = ctx.r6.u32 & 0xFF;
	// clrlwi r7,r9,27
	ctx.r7.u64 = ctx.r9.u32 & 0x1F;
	// li r6,1
	ctx.r6.s64 = 1;
	// neg r5,r8
	ctx.r5.s64 = -ctx.r8.s64;
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// slw r3,r6,r7
	ctx.r3.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r7.u8 & 0x3F));
	// xor r9,r5,r4
	ctx.r9.u64 = ctx.r5.u64 ^ ctx.r4.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// and r7,r3,r9
	ctx.r7.u64 = ctx.r3.u64 & ctx.r9.u64;
	// xor r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// stwx r6,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r6.u32);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82186F40"))) PPC_WEAK_FUNC(sub_82186F40);
PPC_FUNC_IMPL(__imp__sub_82186F40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwinm r3,r10,31,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186F50"))) PPC_WEAK_FUNC(sub_82186F50);
PPC_FUNC_IMPL(__imp__sub_82186F50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwinm r3,r10,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186F60"))) PPC_WEAK_FUNC(sub_82186F60);
PPC_FUNC_IMPL(__imp__sub_82186F60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// not r9,r10
	ctx.r9.u64 = ~ctx.r10.u64;
	// clrlwi r3,r9,31
	ctx.r3.u64 = ctx.r9.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186F74"))) PPC_WEAK_FUNC(sub_82186F74);
PPC_FUNC_IMPL(__imp__sub_82186F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186F78"))) PPC_WEAK_FUNC(sub_82186F78);
PPC_FUNC_IMPL(__imp__sub_82186F78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,3
	r11.s64 = ctx.r4.s64 + 3;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// add r8,r10,r5
	ctx.r8.u64 = ctx.r10.u64 + ctx.r5.u64;
	// slw r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// and r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 & ctx.r4.u64;
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186FA8"))) PPC_WEAK_FUNC(sub_82186FA8);
PPC_FUNC_IMPL(__imp__sub_82186FA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,11
	r11.s64 = ctx.r4.s64 + 11;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// add r8,r10,r5
	ctx.r8.u64 = ctx.r10.u64 + ctx.r5.u64;
	// slw r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// and r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 & ctx.r4.u64;
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186FD8"))) PPC_WEAK_FUNC(sub_82186FD8);
PPC_FUNC_IMPL(__imp__sub_82186FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,19
	r11.s64 = ctx.r4.s64 + 19;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// add r8,r10,r5
	ctx.r8.u64 = ctx.r10.u64 + ctx.r5.u64;
	// slw r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// and r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 & ctx.r4.u64;
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82187008"))) PPC_WEAK_FUNC(sub_82187008);
PPC_FUNC_IMPL(__imp__sub_82187008) {
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
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82187030:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82187030
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82187030;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8218704C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8218704c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8218704C;
	// li r31,0
	r31.s64 = 0;
loc_8218705C:
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82186d90
	ctx.lr = 0x82187074;
	sub_82186D90(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// blt cr6,0x8218705c
	if (cr6.lt) goto loc_8218705C;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82186d90
	ctx.lr = 0x82187098;
	sub_82186D90(ctx, base);
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

__attribute__((alias("__imp__sub_821870B4"))) PPC_WEAK_FUNC(sub_821870B4);
PPC_FUNC_IMPL(__imp__sub_821870B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821870B8"))) PPC_WEAK_FUNC(sub_821870B8);
PPC_FUNC_IMPL(__imp__sub_821870B8) {
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
	ctx.lr = 0x821870C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82187144
	if (cr6.eq) goto loc_82187144;
	// bl 0x82177a68
	ctx.lr = 0x821870D4;
	sub_82177A68(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82187144
	if (!cr6.eq) goto loc_82187144;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r30,r11,-24772
	r30.s64 = r11.s64 + -24772;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82237920
	ctx.lr = 0x821870FC;
	sub_82237920(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82187144
	if (cr6.eq) goto loc_82187144;
loc_82187108:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// beq cr6,0x82187130
	if (cr6.eq) goto loc_82187130;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82186d30
	ctx.lr = 0x8218711C;
	sub_82186D30(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82187108
	if (!cr6.eq) goto loc_82187108;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82187130:
	// bl 0x821bbea8
	ctx.lr = 0x82187134;
	sub_821BBEA8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821bf8c8
	ctx.lr = 0x82187140;
	sub_821BF8C8(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x82187144;
	sub_821BBF00(ctx, base);
loc_82187144:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218714C"))) PPC_WEAK_FUNC(sub_8218714C);
PPC_FUNC_IMPL(__imp__sub_8218714C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187150"))) PPC_WEAK_FUNC(sub_82187150);
PPC_FUNC_IMPL(__imp__sub_82187150) {
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
	ctx.lr = 0x82187158;
	// stwu r1,-2080(r1)
	ea = -2080 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// stw r3,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r3.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r4,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r4.u32);
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// stw r5,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r5.u32);
	// stw r6,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// addi r30,r1,160
	r30.s64 = ctx.r1.s64 + 160;
	// mr r29,r31
	r29.u64 = r31.u64;
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
	// addi r27,r11,-21216
	r27.s64 = r11.s64 + -21216;
loc_82187188:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821871ac
	if (cr6.eq) goto loc_821871AC;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// subf r5,r30,r11
	ctx.r5.s64 = r11.s64 - r30.s64;
	// bl 0x82190090
	ctx.lr = 0x821871A4;
	sub_82190090(ctx, base);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
	// b 0x821871c0
	goto loc_821871C0;
loc_821871AC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dc018
	ctx.lr = 0x821871BC;
	sub_823DC018(ctx, base);
	// addi r30,r30,3
	r30.s64 = r30.s64 + 3;
loc_821871C0:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x82187188
	if (cr6.lt) goto loc_82187188;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stb r31,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r31.u8);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r27,r11,-24772
	r27.s64 = r11.s64 + -24772;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x825edac0
	ctx.lr = 0x821871F0;
	sub_825EDAC0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8218721c
	if (cr6.eq) goto loc_8218721C;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218721c
	if (!cr6.eq) goto loc_8218721C;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82177ac0
	ctx.lr = 0x82187210;
	sub_82177AC0(ctx, base);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r1,r1,2080
	ctx.r1.s64 = ctx.r1.s64 + 2080;
	// b 0x823d9240
	return;
loc_8218721C:
	// bl 0x821bbea8
	ctx.lr = 0x82187220;
	sub_821BBEA8(ctx, base);
	// li r10,63
	ctx.r10.s64 = 63;
	// addi r11,r1,232
	r11.s64 = ctx.r1.s64 + 232;
	// li r9,6
	ctx.r9.s64 = 6;
loc_8218722C:
	// stw r31,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, r31.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r31,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// sth r31,16(r11)
	PPC_STORE_U16(r11.u32 + 16, r31.u16);
	// addi r11,r11,28
	r11.s64 = r11.s64 + 28;
	// bge 0x8218722c
	if (!cr0.lt) goto loc_8218722C;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// mr r30,r31
	r30.u64 = r31.u64;
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// addi r29,r1,144
	r29.s64 = ctx.r1.s64 + 144;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r31.u32);
loc_82187278:
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82187300
	if (cr6.eq) goto loc_82187300;
	// lbz r11,6(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// addi r10,r1,116
	ctx.r10.s64 = ctx.r1.s64 + 116;
	// addi r9,r1,140
	ctx.r9.s64 = ctx.r1.s64 + 140;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r8,r1,124
	ctx.r8.s64 = ctx.r1.s64 + 124;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// beq cr6,0x821872d4
	if (cr6.eq) goto loc_821872D4;
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// mulli r3,r30,28
	ctx.r3.s64 = r30.s64 * 28;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,136
	ctx.r9.s64 = ctx.r1.s64 + 136;
	// addi r8,r1,132
	ctx.r8.s64 = ctx.r1.s64 + 132;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// bl 0x821864e8
	ctx.lr = 0x821872D0;
	sub_821864E8(ctx, base);
	// b 0x821872fc
	goto loc_821872FC;
loc_821872D4:
	// mulli r11,r30,28
	r11.s64 = r30.s64 * 28;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,136
	ctx.r9.s64 = ctx.r1.s64 + 136;
	// addi r8,r1,132
	ctx.r8.s64 = ctx.r1.s64 + 132;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// bl 0x821867a0
	ctx.lr = 0x821872FC;
	sub_821867A0(ctx, base);
loc_821872FC:
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
loc_82187300:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x82187278
	if (cr6.lt) goto loc_82187278;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8217aac0
	ctx.lr = 0x8218731C;
	sub_8217AAC0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82187358
	if (cr6.eq) goto loc_82187358;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82187354
	if (!cr6.eq) goto loc_82187354;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x824a5248
	ctx.lr = 0x82187344;
	sub_824A5248(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x82187348;
	sub_821BBF00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,2080
	ctx.r1.s64 = ctx.r1.s64 + 2080;
	// b 0x823d9240
	return;
loc_82187354:
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
loc_82187358:
	// bl 0x821bbf00
	ctx.lr = 0x8218735C;
	sub_821BBF00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,2080
	ctx.r1.s64 = ctx.r1.s64 + 2080;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82187368"))) PPC_WEAK_FUNC(sub_82187368);
PPC_FUNC_IMPL(__imp__sub_82187368) {
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
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r9,r10,-21228
	ctx.r9.s64 = ctx.r10.s64 + -21228;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r10,-24780(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -24780);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x821873b4
	if (!cr6.eq) goto loc_821873B4;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// stw r10,-24780(r11)
	PPC_STORE_U32(r11.u32 + -24780, ctx.r10.u32);
	// addi r3,r9,-24772
	ctx.r3.s64 = ctx.r9.s64 + -24772;
	// bl 0x8229d838
	ctx.lr = 0x821873B4;
	sub_8229D838(ctx, base);
loc_821873B4:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821873cc
	if (cr6.eq) goto loc_821873CC;
	// bl 0x82130588
	ctx.lr = 0x821873C8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821873CC:
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

__attribute__((alias("__imp__sub_821873E4"))) PPC_WEAK_FUNC(sub_821873E4);
PPC_FUNC_IMPL(__imp__sub_821873E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821873E8"))) PPC_WEAK_FUNC(sub_821873E8);
PPC_FUNC_IMPL(__imp__sub_821873E8) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,72
	ctx.r4.s64 = 72;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8218741C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82187438
	if (cr6.eq) goto loc_82187438;
	// bl 0x82188cf8
	ctx.lr = 0x82187428;
	sub_82188CF8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82187438:
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

__attribute__((alias("__imp__sub_8218744C"))) PPC_WEAK_FUNC(sub_8218744C);
PPC_FUNC_IMPL(__imp__sub_8218744C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187450"))) PPC_WEAK_FUNC(sub_82187450);
PPC_FUNC_IMPL(__imp__sub_82187450) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,80
	ctx.r4.s64 = 80;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82187484;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821874a0
	if (cr6.eq) goto loc_821874A0;
	// bl 0x82193870
	ctx.lr = 0x82187490;
	sub_82193870(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821874A0:
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

__attribute__((alias("__imp__sub_821874B4"))) PPC_WEAK_FUNC(sub_821874B4);
PPC_FUNC_IMPL(__imp__sub_821874B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821874B8"))) PPC_WEAK_FUNC(sub_821874B8);
PPC_FUNC_IMPL(__imp__sub_821874B8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-20884
	ctx.r4.s64 = r11.s64 + -20884;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x821874E8;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218758c
	if (cr6.eq) goto loc_8218758C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r4,r10,-29624
	ctx.r4.s64 = ctx.r10.s64 + -29624;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82187510;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-20892
	ctx.r4.s64 = ctx.r8.s64 + -20892;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82187524;
	sub_821CFE80(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82187538
	if (cr6.eq) goto loc_82187538;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0228
	ctx.lr = 0x82187538;
	sub_821D0228(ctx, base);
loc_82187538:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218754C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821932c8
	ctx.lr = 0x82187558;
	sub_821932C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8218756c
	if (!cr6.eq) goto loc_8218756C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821875e4
	goto loc_821875E4;
loc_8218756C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-29628
	ctx.r4.s64 = ctx.r10.s64 + -29628;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82187588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821875e0
	goto loc_821875E0;
loc_8218758C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-20892
	ctx.r4.s64 = r11.s64 + -20892;
	// bl 0x821cfe80
	ctx.lr = 0x8218759C;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821875b0
	if (cr6.eq) goto loc_821875B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0228
	ctx.lr = 0x821875B0;
	sub_821D0228(ctx, base);
loc_821875B0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821875C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821932c8
	ctx.lr = 0x821875D0;
	sub_821932C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821875e4
	if (cr6.eq) goto loc_821875E4;
loc_821875E0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821875E4:
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

__attribute__((alias("__imp__sub_821875FC"))) PPC_WEAK_FUNC(sub_821875FC);
PPC_FUNC_IMPL(__imp__sub_821875FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187600"))) PPC_WEAK_FUNC(sub_82187600);
PPC_FUNC_IMPL(__imp__sub_82187600) {
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
	ctx.lr = 0x82187608;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r5,r11,-20868
	ctx.r5.s64 = r11.s64 + -20868;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x82187630;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82187644
	if (!cr6.eq) goto loc_82187644;
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d924c
	return;
loc_82187644:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x8218764C;
	sub_821D1CD0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x8218765C;
	sub_821CF7B8(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82187674;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r8,r9,-30140
	ctx.r8.s64 = ctx.r9.s64 + -30140;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x821be610
	ctx.lr = 0x8218768C;
	sub_821BE610(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82187698"))) PPC_WEAK_FUNC(sub_82187698);
PPC_FUNC_IMPL(__imp__sub_82187698) {
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
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r9,r10,-20924
	ctx.r9.s64 = ctx.r10.s64 + -20924;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r10,-24728(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x821876d0
	if (!cr6.eq) goto loc_821876D0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-24728(r11)
	PPC_STORE_U32(r11.u32 + -24728, ctx.r10.u32);
loc_821876D0:
	// clrlwi r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821876e8
	if (cr6.eq) goto loc_821876E8;
	// bl 0x82130588
	ctx.lr = 0x821876E4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821876E8:
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

__attribute__((alias("__imp__sub_821876FC"))) PPC_WEAK_FUNC(sub_821876FC);
PPC_FUNC_IMPL(__imp__sub_821876FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187700"))) PPC_WEAK_FUNC(sub_82187700);
PPC_FUNC_IMPL(__imp__sub_82187700) {
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
	ctx.lr = 0x82187708;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x821877ac
	if (!cr6.gt) goto loc_821877AC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// addi r27,r11,-26560
	r27.s64 = r11.s64 + -26560;
loc_82187728:
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8218778c
	if (cr6.eq) goto loc_8218778C;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d828
	ctx.lr = 0x82187744;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8218776c
	if (cr6.eq) goto loc_8218776C;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x82187780
	goto loc_82187780;
loc_8218776C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2378
	ctx.lr = 0x8218777C;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_82187780:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8218778C:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821877a0
	if (cr6.eq) goto loc_821877A0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82189310
	ctx.lr = 0x821877A0;
	sub_82189310(ctx, base);
loc_821877A0:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82187728
	if (!cr0.eq) goto loc_82187728;
loc_821877AC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821877B4"))) PPC_WEAK_FUNC(sub_821877B4);
PPC_FUNC_IMPL(__imp__sub_821877B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821877B8"))) PPC_WEAK_FUNC(sub_821877B8);
PPC_FUNC_IMPL(__imp__sub_821877B8) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82187804
	if (cr6.eq) goto loc_82187804;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x821877E8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82187804
	if (cr6.eq) goto loc_82187804;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82193d98
	ctx.lr = 0x82187804;
	sub_82193D98(ctx, base);
loc_82187804:
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

__attribute__((alias("__imp__sub_8218781C"))) PPC_WEAK_FUNC(sub_8218781C);
PPC_FUNC_IMPL(__imp__sub_8218781C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187820"))) PPC_WEAK_FUNC(sub_82187820);
PPC_FUNC_IMPL(__imp__sub_82187820) {
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
	ctx.lr = 0x82187828;
	// stwu r1,-848(r1)
	ea = -848 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x82187840;
	sub_821CA540(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r30,r11,-24488
	r30.s64 = r11.s64 + -24488;
	// addi r29,r10,-20692
	r29.s64 = ctx.r10.s64 + -20692;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82187868;
	sub_821CA6A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82187994
	if (cr6.eq) goto loc_82187994;
	// bl 0x821be8d8
	ctx.lr = 0x82187878;
	sub_821BE8D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82187994
	if (cr6.eq) goto loc_82187994;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-20724
	ctx.r3.s64 = r11.s64 + -20724;
	// bl 0x82130000
	ctx.lr = 0x82187890;
	sub_82130000(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca490
	ctx.lr = 0x821878A0;
	sub_821CA490(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d1ce8
	ctx.lr = 0x821878B4;
	sub_821D1CE8(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x821878C4;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82187970
	if (cr6.eq) goto loc_82187970;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r24,0
	r24.s64 = 0;
	// addi r30,r8,-20732
	r30.s64 = ctx.r8.s64 + -20732;
	// addi r29,r9,-20736
	r29.s64 = ctx.r9.s64 + -20736;
	// addi r25,r10,-20772
	r25.s64 = ctx.r10.s64 + -20772;
	// addi r27,r11,-20784
	r27.s64 = r11.s64 + -20784;
loc_821878F0:
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db6d0
	ctx.lr = 0x821878FC;
	sub_823DB6D0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82187958
	if (cr6.eq) goto loc_82187958;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823db730
	ctx.lr = 0x82187910;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82187920
	if (!cr6.eq) goto loc_82187920;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821bd618
	ctx.lr = 0x82187920;
	sub_821BD618(ctx, base);
loc_82187920:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823db730
	ctx.lr = 0x8218792C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82187948
	if (cr6.eq) goto loc_82187948;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823db730
	ctx.lr = 0x82187940;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82187958
	if (!cr6.eq) goto loc_82187958;
loc_82187948:
	// stb r24,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r24.u8);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82188e50
	ctx.lr = 0x82187958;
	sub_82188E50(ctx, base);
loc_82187958:
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x82187968;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821878f0
	if (!cr6.eq) goto loc_821878F0;
loc_82187970:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be610
	ctx.lr = 0x82187978;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r10.u32);
	// bl 0x821c9a90
	ctx.lr = 0x8218798C;
	sub_821C9A90(ctx, base);
	// addi r1,r1,848
	ctx.r1.s64 = ctx.r1.s64 + 848;
	// b 0x823d9234
	return;
loc_82187994:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-20820
	ctx.r3.s64 = r11.s64 + -20820;
	// bl 0x82130000
	ctx.lr = 0x821879A4;
	sub_82130000(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r31,r10,-28368
	r31.s64 = ctx.r10.s64 + -28368;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82188e50
	ctx.lr = 0x821879B8;
	sub_82188E50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82188e50
	ctx.lr = 0x821879C4;
	sub_82188E50(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821879CC;
	sub_821C9A90(ctx, base);
	// addi r1,r1,848
	ctx.r1.s64 = ctx.r1.s64 + 848;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821879D4"))) PPC_WEAK_FUNC(sub_821879D4);
PPC_FUNC_IMPL(__imp__sub_821879D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821879D8"))) PPC_WEAK_FUNC(sub_821879D8);
PPC_FUNC_IMPL(__imp__sub_821879D8) {
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
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x821879F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82187a0c
	if (cr6.eq) goto loc_82187A0C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-20852
	ctx.r10.s64 = r11.s64 + -20852;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82187a10
	goto loc_82187A10;
loc_82187A0C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82187A10:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82187a24
	if (cr6.eq) goto loc_82187A24;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,-24728(r11)
	PPC_STORE_U32(r11.u32 + -24728, ctx.r3.u32);
loc_82187A24:
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

__attribute__((alias("__imp__sub_82187A38"))) PPC_WEAK_FUNC(sub_82187A38);
PPC_FUNC_IMPL(__imp__sub_82187A38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble 0x82187a94
	if (!cr0.gt) goto loc_82187A94;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_82187A54:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x82187a74
	if (cr6.lt) goto loc_82187A74;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x82187a78
	if (cr6.lt) goto loc_82187A78;
loc_82187A74:
	// li r11,0
	r11.s64 = 0;
loc_82187A78:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// blt cr6,0x82187a54
	if (cr6.lt) goto loc_82187A54;
loc_82187A94:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82187A9C"))) PPC_WEAK_FUNC(sub_82187A9C);
PPC_FUNC_IMPL(__imp__sub_82187A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187AA0"))) PPC_WEAK_FUNC(sub_82187AA0);
PPC_FUNC_IMPL(__imp__sub_82187AA0) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-20332
	ctx.r4.s64 = r11.s64 + -20332;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82187AD0;
	sub_8218A568(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82187af4
	if (cr6.eq) goto loc_82187AF4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-20340
	ctx.r5.s64 = r11.s64 + -20340;
	// bl 0x8218a958
	ctx.lr = 0x82187AF0;
	sub_8218A958(ctx, base);
	// b 0x82187b48
	goto loc_82187B48;
loc_82187AF4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-20364
	ctx.r4.s64 = r11.s64 + -20364;
	// bl 0x8218a568
	ctx.lr = 0x82187B04;
	sub_8218A568(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82187b4c
	if (cr6.eq) goto loc_82187B4C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r6,r11,-20372
	ctx.r6.s64 = r11.s64 + -20372;
	// addi r5,r10,-20384
	ctx.r5.s64 = ctx.r10.s64 + -20384;
	// bl 0x8218a868
	ctx.lr = 0x82187B28;
	sub_8218A868(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82194498
	ctx.lr = 0x82187B34;
	sub_82194498(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82187b4c
	if (cr6.eq) goto loc_82187B4C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82194258
	ctx.lr = 0x82187B48;
	sub_82194258(ctx, base);
loc_82187B48:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82187B4C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x82187b68
	if (!cr6.lt) goto loc_82187B68;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r11.u8);
	// stb r10,11(r31)
	PPC_STORE_U8(r31.u32 + 11, ctx.r10.u8);
	// b 0x82187b6c
	goto loc_82187B6C;
loc_82187B68:
	// stb r30,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r30.u8);
loc_82187B6C:
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

__attribute__((alias("__imp__sub_82187B84"))) PPC_WEAK_FUNC(sub_82187B84);
PPC_FUNC_IMPL(__imp__sub_82187B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187B88"))) PPC_WEAK_FUNC(sub_82187B88);
PPC_FUNC_IMPL(__imp__sub_82187B88) {
	PPC_FUNC_PROLOGUE();
	// addi r5,r3,16
	ctx.r5.s64 = ctx.r3.s64 + 16;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// b 0x8218bb08
	sub_8218BB08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187B94"))) PPC_WEAK_FUNC(sub_82187B94);
PPC_FUNC_IMPL(__imp__sub_82187B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187B98"))) PPC_WEAK_FUNC(sub_82187B98);
PPC_FUNC_IMPL(__imp__sub_82187B98) {
	PPC_FUNC_PROLOGUE();
	// addi r5,r3,16
	ctx.r5.s64 = ctx.r3.s64 + 16;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// b 0x8218acf0
	sub_8218ACF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187BA4"))) PPC_WEAK_FUNC(sub_82187BA4);
PPC_FUNC_IMPL(__imp__sub_82187BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187BA8"))) PPC_WEAK_FUNC(sub_82187BA8);
PPC_FUNC_IMPL(__imp__sub_82187BA8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// b 0x8218ad48
	sub_8218AD48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187BB0"))) PPC_WEAK_FUNC(sub_82187BB0);
PPC_FUNC_IMPL(__imp__sub_82187BB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,14(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r9,r10,-24720
	ctx.r9.s64 = ctx.r10.s64 + -24720;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82187BCC"))) PPC_WEAK_FUNC(sub_82187BCC);
PPC_FUNC_IMPL(__imp__sub_82187BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187BD0"))) PPC_WEAK_FUNC(sub_82187BD0);
PPC_FUNC_IMPL(__imp__sub_82187BD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21088(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21088, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82187BE0"))) PPC_WEAK_FUNC(sub_82187BE0);
PPC_FUNC_IMPL(__imp__sub_82187BE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stw r3,23648(r11)
	PPC_STORE_U32(r11.u32 + 23648, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82187BEC"))) PPC_WEAK_FUNC(sub_82187BEC);
PPC_FUNC_IMPL(__imp__sub_82187BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187BF0"))) PPC_WEAK_FUNC(sub_82187BF0);
PPC_FUNC_IMPL(__imp__sub_82187BF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r3,23648(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 23648);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82187BFC"))) PPC_WEAK_FUNC(sub_82187BFC);
PPC_FUNC_IMPL(__imp__sub_82187BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187C00"))) PPC_WEAK_FUNC(sub_82187C00);
PPC_FUNC_IMPL(__imp__sub_82187C00) {
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
	ctx.lr = 0x82187C08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r11,-24720
	r30.s64 = r11.s64 + -24720;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_82187C1C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82187c3c
	if (cr6.eq) goto loc_82187C3C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x82187C34;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82187c58
	if (cr6.eq) goto loc_82187C58;
loc_82187C3C:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,1024
	r11.s64 = r30.s64 + 1024;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82187c1c
	if (cr6.lt) goto loc_82187C1C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82187C58:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82187C64"))) PPC_WEAK_FUNC(sub_82187C64);
PPC_FUNC_IMPL(__imp__sub_82187C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187C68"))) PPC_WEAK_FUNC(sub_82187C68);
PPC_FUNC_IMPL(__imp__sub_82187C68) {
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
	// addi r10,r11,-20308
	ctx.r10.s64 = r11.s64 + -20308;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x82130588
	ctx.lr = 0x82187C94;
	sub_82130588(ctx, base);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82130588
	ctx.lr = 0x82187C9C;
	sub_82130588(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x82130588
	ctx.lr = 0x82187CA4;
	sub_82130588(ctx, base);
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x82130588
	ctx.lr = 0x82187CAC;
	sub_82130588(ctx, base);
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82187cc8
	if (cr6.eq) goto loc_82187CC8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821948c8
	ctx.lr = 0x82187CC0;
	sub_821948C8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82187CC8;
	sub_82130588(ctx, base);
loc_82187CC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82194ac8
	ctx.lr = 0x82187CD0;
	sub_82194AC8(ctx, base);
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

__attribute__((alias("__imp__sub_82187CE8"))) PPC_WEAK_FUNC(sub_82187CE8);
PPC_FUNC_IMPL(__imp__sub_82187CE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,14(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r9,r10,-24720
	ctx.r9.s64 = ctx.r10.s64 + -24720;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,104(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82187D04"))) PPC_WEAK_FUNC(sub_82187D04);
PPC_FUNC_IMPL(__imp__sub_82187D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187D08"))) PPC_WEAK_FUNC(sub_82187D08);
PPC_FUNC_IMPL(__imp__sub_82187D08) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,23648(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 23648);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82187d58
	if (!cr6.eq) goto loc_82187D58;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fed0
	ctx.lr = 0x82187D3C;
	sub_8217FED0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// beq cr6,0x82187d54
	if (cr6.eq) goto loc_82187D54;
	// addi r10,r11,23656
	ctx.r10.s64 = r11.s64 + 23656;
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// b 0x82187d58
	goto loc_82187D58;
loc_82187D54:
	// lwz r11,23656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 23656);
loc_82187D58:
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lbzx r7,r8,r30
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + r30.u32);
	// rotlwi r11,r7,4
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 4);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lhz r3,-4(r6)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r6.u32 + -4);
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

__attribute__((alias("__imp__sub_82187D94"))) PPC_WEAK_FUNC(sub_82187D94);
PPC_FUNC_IMPL(__imp__sub_82187D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187D98"))) PPC_WEAK_FUNC(sub_82187D98);
PPC_FUNC_IMPL(__imp__sub_82187D98) {
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
	// lwz r31,68(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82187dd4
	if (cr6.eq) goto loc_82187DD4;
	// addi r30,r3,16
	r30.s64 = ctx.r3.s64 + 16;
loc_82187DBC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821945c8
	ctx.lr = 0x82187DC8;
	sub_821945C8(ctx, base);
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82187dbc
	if (!cr6.eq) goto loc_82187DBC;
loc_82187DD4:
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

__attribute__((alias("__imp__sub_82187DEC"))) PPC_WEAK_FUNC(sub_82187DEC);
PPC_FUNC_IMPL(__imp__sub_82187DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187DF0"))) PPC_WEAK_FUNC(sub_82187DF0);
PPC_FUNC_IMPL(__imp__sub_82187DF0) {
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
	ctx.lr = 0x82187DF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lhz r11,12(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82187e94
	if (!cr6.gt) goto loc_82187E94;
	// mr r26,r11
	r26.u64 = r11.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r31,1
	r31.s64 = 1;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// addi r28,r10,-20204
	r28.s64 = ctx.r10.s64 + -20204;
	// addi r29,r11,-20220
	r29.s64 = r11.s64 + -20220;
loc_82187E2C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8218a838
	ctx.lr = 0x82187E3C;
	sub_8218A838(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82187e88
	if (cr6.eq) goto loc_82187E88;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8218a868
	ctx.lr = 0x82187E5C;
	sub_8218A868(ctx, base);
	// lwz r11,-25232(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -25232);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82180b90
	ctx.lr = 0x82187E6C;
	sub_82180B90(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82187e88
	if (cr6.eq) goto loc_82187E88;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// bl 0x82189ce0
	ctx.lr = 0x82187E88;
	sub_82189CE0(ctx, base);
loc_82187E88:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bne 0x82187e2c
	if (!cr0.eq) goto loc_82187E2C;
loc_82187E94:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82187E9C"))) PPC_WEAK_FUNC(sub_82187E9C);
PPC_FUNC_IMPL(__imp__sub_82187E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187EA0"))) PPC_WEAK_FUNC(sub_82187EA0);
PPC_FUNC_IMPL(__imp__sub_82187EA0) {
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
	ctx.lr = 0x82187EA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,64(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// bl 0x82195720
	ctx.lr = 0x82187EB8;
	sub_82195720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82187f34
	if (cr6.eq) goto loc_82187F34;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821957d8
	ctx.lr = 0x82187EC8;
	sub_821957D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82187f34
	if (cr6.eq) goto loc_82187F34;
loc_82187ED4:
	// lwz r31,68(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82187f28
	if (cr6.eq) goto loc_82187F28;
loc_82187EE0:
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x823db730
	ctx.lr = 0x82187EEC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82187f04
	if (cr6.eq) goto loc_82187F04;
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82187ee0
	if (!cr6.eq) goto loc_82187EE0;
	// b 0x82187f28
	goto loc_82187F28;
loc_82187F04:
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82187f28
	if (cr6.eq) goto loc_82187F28;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821949a0
	ctx.lr = 0x82187F1C;
	sub_821949A0(ctx, base);
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821945c8
	ctx.lr = 0x82187F28;
	sub_821945C8(ctx, base);
loc_82187F28:
	// lwz r30,24(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82187ed4
	if (!cr6.eq) goto loc_82187ED4;
loc_82187F34:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82187F3C"))) PPC_WEAK_FUNC(sub_82187F3C);
PPC_FUNC_IMPL(__imp__sub_82187F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187F40"))) PPC_WEAK_FUNC(sub_82187F40);
PPC_FUNC_IMPL(__imp__sub_82187F40) {
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
	ctx.lr = 0x82187F48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,23648(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 23648);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82187f90
	if (!cr6.eq) goto loc_82187F90;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fed0
	ctx.lr = 0x82187F74;
	sub_8217FED0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// beq cr6,0x82187f8c
	if (cr6.eq) goto loc_82187F8C;
	// addi r10,r11,23656
	ctx.r10.s64 = r11.s64 + 23656;
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// b 0x82187f90
	goto loc_82187F90;
loc_82187F8C:
	// lwz r11,23656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 23656);
loc_82187F90:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82187fa0
	if (cr6.eq) goto loc_82187FA0;
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x82187fb0
	goto loc_82187FB0;
loc_82187FA0:
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbzx r11,r11,r30
	r11.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
loc_82187FB0:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,-21076(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21076, r11.u32);
	// beq cr6,0x82187ff0
	if (cr6.eq) goto loc_82187FF0;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// stb r28,-21095(r8)
	PPC_STORE_U8(ctx.r8.u32 + -21095, r28.u8);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// stw r10,-21088(r7)
	PPC_STORE_U32(ctx.r7.u32 + -21088, ctx.r10.u32);
	// lhz r3,-4(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + -4);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82187FF0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82187FFC"))) PPC_WEAK_FUNC(sub_82187FFC);
PPC_FUNC_IMPL(__imp__sub_82187FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188000"))) PPC_WEAK_FUNC(sub_82188000);
PPC_FUNC_IMPL(__imp__sub_82188000) {
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
	ctx.lr = 0x82188008;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82187f40
	ctx.lr = 0x82188028;
	sub_82187F40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8218806c
	if (!cr6.gt) goto loc_8218806C;
	// addi r26,r30,16
	r26.s64 = r30.s64 + 16;
loc_8218803C:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8218bb08
	ctx.lr = 0x8218804C;
	sub_8218BB08(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82190b98
	ctx.lr = 0x82188058;
	sub_82190B98(ctx, base);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218ad48
	ctx.lr = 0x82188060;
	sub_8218AD48(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x8218803c
	if (cr6.lt) goto loc_8218803C;
loc_8218806C:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21088(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21088, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82188080"))) PPC_WEAK_FUNC(sub_82188080);
PPC_FUNC_IMPL(__imp__sub_82188080) {
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
	ctx.lr = 0x82188088;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82187f40
	ctx.lr = 0x821880AC;
	sub_82187F40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x821880f4
	if (!cr6.gt) goto loc_821880F4;
	// addi r25,r30,16
	r25.s64 = r30.s64 + 16;
loc_821880C0:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8218bb08
	ctx.lr = 0x821880D0;
	sub_8218BB08(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82190bb8
	ctx.lr = 0x821880E0;
	sub_82190BB8(ctx, base);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218ad48
	ctx.lr = 0x821880E8;
	sub_8218AD48(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x821880c0
	if (cr6.lt) goto loc_821880C0;
loc_821880F4:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21088(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21088, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82188108"))) PPC_WEAK_FUNC(sub_82188108);
PPC_FUNC_IMPL(__imp__sub_82188108) {
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
	ctx.lr = 0x82188110;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8219a1c8
	ctx.lr = 0x8218811C;
	sub_8219A1C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821973a8
	ctx.lr = 0x82188128;
	sub_821973A8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,56(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x82198180
	ctx.lr = 0x82188138;
	sub_82198180(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82188188
	if (cr6.eq) goto loc_82188188;
	// lwz r31,68(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218817c
	if (cr6.eq) goto loc_8218817C;
loc_82188150:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82196d80
	ctx.lr = 0x8218815C;
	sub_82196D80(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82188170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82188150
	if (!cr6.eq) goto loc_82188150;
loc_8218817C:
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82188184;
	sub_82130000(ctx, base);
	// b 0x82188198
	goto loc_82188198;
loc_82188188:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r4,56(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r3,r11,-20192
	ctx.r3.s64 = r11.s64 + -20192;
	// bl 0x82130000
	ctx.lr = 0x82188198;
	sub_82130000(ctx, base);
loc_82188198:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821881a8
	if (cr6.eq) goto loc_821881A8;
	// bl 0x82199818
	ctx.lr = 0x821881A8;
	sub_82199818(ctx, base);
loc_821881A8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82197448
	ctx.lr = 0x821881B0;
	sub_82197448(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821881B8"))) PPC_WEAK_FUNC(sub_821881B8);
PPC_FUNC_IMPL(__imp__sub_821881B8) {
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
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82183870
	ctx.lr = 0x821881D4;
	sub_82183870(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,-23160
	r11.s64 = r11.s64 + -23160;
	// lwz r7,2048(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 2048);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82188234
	if (!cr6.gt) goto loc_82188234;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_821881F0:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_821881F8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x8218821c
	if (cr6.eq) goto loc_8218821C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821881f8
	if (cr6.eq) goto loc_821881F8;
loc_8218821C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82188238
	if (cr6.eq) goto loc_82188238;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// cmpw cr6,r3,r7
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, xer);
	// blt cr6,0x821881f0
	if (cr6.lt) goto loc_821881F0;
loc_82188234:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82188238:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82188248"))) PPC_WEAK_FUNC(sub_82188248);
PPC_FUNC_IMPL(__imp__sub_82188248) {
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
	ctx.lr = 0x82188250;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821881b8
	ctx.lr = 0x8218825C;
	sub_821881B8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x821883d8
	if (!cr6.lt) goto loc_821883D8;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r31,r11,-23160
	r31.s64 = r11.s64 + -23160;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,2048(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2048);
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r10,r31
	ctx.r3.u64 = ctx.r10.u64 + r31.u64;
	// stw r11,2048(r31)
	PPC_STORE_U32(r31.u32 + 2048, r11.u32);
	// bl 0x82183870
	ctx.lr = 0x8218828C;
	sub_82183870(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r11,-23696
	r11.s64 = r11.s64 + -23696;
	// addi r8,r10,-20156
	ctx.r8.s64 = ctx.r10.s64 + -20156;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r29,r7,r11
	r29.u64 = ctx.r7.u64 + r11.u64;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
loc_821882B4:
	// lbz r11,0(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x821882d8
	if (cr6.eq) goto loc_821882D8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821882b4
	if (cr6.eq) goto loc_821882B4;
loc_821882D8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821882e8
	if (!cr6.eq) goto loc_821882E8;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x82188340
	goto loc_82188340;
loc_821882E8:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r30
	r11.u64 = r30.u64;
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - r30.s64;
loc_821882F4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x821882f4
	if (!cr6.eq) goto loc_821882F4;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,-20160
	ctx.r10.s64 = ctx.r10.s64 + -20160;
loc_82188314:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82188314
	if (!cr6.eq) goto loc_82188314;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82188328:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82188328
	if (!cr6.eq) goto loc_82188328;
loc_82188340:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_82188348:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82188348
	if (!cr6.eq) goto loc_82188348;
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// lwz r11,2048(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2048);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// rotlwi r9,r7,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r6,r8,-27772
	ctx.r6.s64 = ctx.r8.s64 + -27772;
	// add r31,r9,r10
	r31.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r30,r11,-1
	r30.s64 = r11.s64 + -1;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8218838C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8218838c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8218838C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x821883AC;
	sub_821C9790(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r4,r11,-27796
	ctx.r4.s64 = r11.s64 + -27796;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x821883C4;
	sub_823DA950(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x821883D0;
	sub_821C9790(ctx, base);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821883D8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821883E0"))) PPC_WEAK_FUNC(sub_821883E0);
PPC_FUNC_IMPL(__imp__sub_821883E0) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-20156
	ctx.r3.s64 = r11.s64 + -20156;
	// bl 0x82188248
	ctx.lr = 0x821883FC;
	sub_82188248(ctx, base);
	// lis r31,-32131
	r31.s64 = -2105737216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r31,23656
	ctx.r10.s64 = r31.s64 + 23656;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r3,r9,-20140
	ctx.r3.s64 = ctx.r9.s64 + -20140;
	// stw r11,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, r11.u32);
	// bl 0x82188248
	ctx.lr = 0x82188418;
	sub_82188248(ctx, base);
	// stw r3,23656(r31)
	PPC_STORE_U32(r31.u32 + 23656, ctx.r3.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r3,r8,-20148
	ctx.r3.s64 = ctx.r8.s64 + -20148;
	// bl 0x82188248
	ctx.lr = 0x82188428;
	sub_82188248(ctx, base);
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// li r11,-1
	r11.s64 = -1;
	// stw r3,23660(r7)
	PPC_STORE_U32(ctx.r7.u32 + 23660, ctx.r3.u32);
	// stw r11,23648(r6)
	PPC_STORE_U32(ctx.r6.u32 + 23648, r11.u32);
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

__attribute__((alias("__imp__sub_82188450"))) PPC_WEAK_FUNC(sub_82188450);
PPC_FUNC_IMPL(__imp__sub_82188450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,14(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r9,r10,-24720
	ctx.r9.s64 = ctx.r10.s64 + -24720;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lhz r3,100(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 100);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218846C"))) PPC_WEAK_FUNC(sub_8218846C);
PPC_FUNC_IMPL(__imp__sub_8218846C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188470"))) PPC_WEAK_FUNC(sub_82188470);
PPC_FUNC_IMPL(__imp__sub_82188470) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,68(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82188478"))) PPC_WEAK_FUNC(sub_82188478);
PPC_FUNC_IMPL(__imp__sub_82188478) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821884a4
	if (cr6.eq) goto loc_821884A4;
loc_82188484:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82188484
	if (!cr6.eq) goto loc_82188484;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stw r4,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r4.u32);
	// blr 
	return;
loc_821884A4:
	// stw r4,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821884AC"))) PPC_WEAK_FUNC(sub_821884AC);
PPC_FUNC_IMPL(__imp__sub_821884AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821884B0"))) PPC_WEAK_FUNC(sub_821884B0);
PPC_FUNC_IMPL(__imp__sub_821884B0) {
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
	ctx.lr = 0x821884B8;
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
	// beq cr6,0x8218851c
	if (cr6.eq) goto loc_8218851C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8218851c
	if (cr6.eq) goto loc_8218851C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x821884EC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8218851c
	if (cr6.eq) goto loc_8218851C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82188500;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82194a60
	ctx.lr = 0x82188514;
	sub_82194A60(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8218851C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8218852C"))) PPC_WEAK_FUNC(sub_8218852C);
PPC_FUNC_IMPL(__imp__sub_8218852C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188530"))) PPC_WEAK_FUNC(sub_82188530);
PPC_FUNC_IMPL(__imp__sub_82188530) {
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
	// bl 0x82187c68
	ctx.lr = 0x82188550;
	sub_82187C68(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82188568
	if (cr6.eq) goto loc_82188568;
	// bl 0x82130588
	ctx.lr = 0x82188564;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82188568:
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

__attribute__((alias("__imp__sub_82188580"))) PPC_WEAK_FUNC(sub_82188580);
PPC_FUNC_IMPL(__imp__sub_82188580) {
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
	ctx.lr = 0x82188588;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,64(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 64);
	// bl 0x82195720
	ctx.lr = 0x82188598;
	sub_82195720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821886a0
	if (cr6.eq) goto loc_821886A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821957d8
	ctx.lr = 0x821885A8;
	sub_821957D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821886a0
	if (cr6.eq) goto loc_821886A0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r27,r11,-20332
	r27.s64 = r11.s64 + -20332;
loc_821885BC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x823db730
	ctx.lr = 0x821885C8;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821885dc
	if (!cr6.eq) goto loc_821885DC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r11,9(r28)
	PPC_STORE_U8(r28.u32 + 9, r11.u8);
	// b 0x82188694
	goto loc_82188694;
loc_821885DC:
	// lwz r31,68(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// addi r29,r28,68
	r29.s64 = r28.s64 + 68;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218860c
	if (cr6.eq) goto loc_8218860C;
loc_821885EC:
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x823db730
	ctx.lr = 0x821885F8;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82188668
	if (cr6.eq) goto loc_82188668;
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821885ec
	if (!cr6.eq) goto loc_821885EC;
loc_8218860C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82188630
	if (cr6.eq) goto loc_82188630;
loc_8218861C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r11,24
	r31.s64 = r11.s64 + 24;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218861c
	if (!cr6.eq) goto loc_8218861C;
loc_82188630:
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x82188638;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82188654
	if (cr6.eq) goto loc_82188654;
	// bl 0x821947c0
	ctx.lr = 0x82188644;
	sub_821947C0(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821949a0
	ctx.lr = 0x82188650;
	sub_821949A0(ctx, base);
	// b 0x82188694
	goto loc_82188694;
loc_82188654:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// bl 0x821949a0
	ctx.lr = 0x82188664;
	sub_821949A0(ctx, base);
	// b 0x82188694
	goto loc_82188694;
loc_82188668:
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82188694
	if (cr6.eq) goto loc_82188694;
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
loc_82188694:
	// lwz r30,24(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821885bc
	if (!cr6.eq) goto loc_821885BC;
loc_821886A0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82187d98
	ctx.lr = 0x821886A8;
	sub_82187D98(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821886B0"))) PPC_WEAK_FUNC(sub_821886B0);
PPC_FUNC_IMPL(__imp__sub_821886B0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r9,r11,-23160
	ctx.r9.s64 = r11.s64 + -23160;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r30,2048(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2048);
	// bne cr6,0x821886f8
	if (!cr6.eq) goto loc_821886F8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-20072
	ctx.r3.s64 = r11.s64 + -20072;
	// bl 0x82130000
	ctx.lr = 0x821886EC;
	sub_82130000(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x821886F4;
	sub_82130528(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
loc_821886F8:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r9,r10,-24720
	ctx.r9.s64 = ctx.r10.s64 + -24720;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r11,108(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// ble cr6,0x82188748
	if (!cr6.gt) goto loc_82188748;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_82188720:
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stb r6,1(r8)
	PPC_STORE_U8(ctx.r8.u32 + 1, ctx.r6.u8);
	// bne 0x82188720
	if (!cr0.eq) goto loc_82188720;
loc_82188748:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-27828
	ctx.r4.s64 = r11.s64 + -27828;
	// bl 0x8218b688
	ctx.lr = 0x8218875C;
	sub_8218B688(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82188770
	if (cr6.eq) goto loc_82188770;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-20132
	ctx.r3.s64 = r11.s64 + -20132;
	// bl 0x821bd618
	ctx.lr = 0x82188770;
	sub_821BD618(ctx, base);
loc_82188770:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82188784;
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

__attribute__((alias("__imp__sub_8218879C"))) PPC_WEAK_FUNC(sub_8218879C);
PPC_FUNC_IMPL(__imp__sub_8218879C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821887A0"))) PPC_WEAK_FUNC(sub_821887A0);
PPC_FUNC_IMPL(__imp__sub_821887A0) {
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
	ctx.lr = 0x821887A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x821887B8;
	sub_82130528(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,108(r27)
	PPC_STORE_U32(r27.u32 + 108, ctx.r3.u32);
	// bl 0x823d9890
	ctx.lr = 0x821887C8;
	sub_823D9890(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-23160
	ctx.r10.s64 = r11.s64 + -23160;
	// lwz r10,2048(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2048);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82188828
	if (!cr6.gt) goto loc_82188828;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r25,r27,8
	r25.s64 = r27.s64 + 8;
	// addi r30,r11,-23696
	r30.s64 = r11.s64 + -23696;
	// li r28,0
	r28.s64 = 0;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
loc_821887F0:
	// lwz r11,108(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 108);
	// li r31,0
	r31.s64 = 0;
	// add r29,r28,r11
	r29.u64 = r28.u64 + r11.u64;
loc_821887FC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8218a4a8
	ctx.lr = 0x82188808;
	sub_8218A4A8(ctx, base);
	// stbx r3,r31,r29
	PPC_STORE_U8(r31.u32 + r29.u32, ctx.r3.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// blt cr6,0x821887fc
	if (cr6.lt) goto loc_821887FC;
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// bne 0x821887f0
	if (!cr0.eq) goto loc_821887F0;
loc_82188828:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82188830"))) PPC_WEAK_FUNC(sub_82188830);
PPC_FUNC_IMPL(__imp__sub_82188830) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82188838;
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -176, f29.u64);
	// stfd f30,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r27,0
	r27.s64 = 0;
	// addi r14,r11,-19824
	r14.s64 = r11.s64 + -19824;
	// lhz r26,20(r28)
	r26.u64 = PPC_LOAD_U16(r28.u32 + 20);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x821888c8
	if (!cr6.gt) goto loc_821888C8;
	// addi r30,r28,8
	r30.s64 = r28.s64 + 8;
	// li r31,1
	r31.s64 = 1;
	// mr r29,r26
	r29.u64 = r26.u64;
loc_82188870:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218a6a0
	ctx.lr = 0x82188890;
	sub_8218A6A0(ctx, base);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218a838
	ctx.lr = 0x821888A0;
	sub_8218A838(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821888bc
	if (cr6.eq) goto loc_821888BC;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821888bc
	if (!cr6.eq) goto loc_821888BC;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_821888BC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bne 0x82188870
	if (!cr0.eq) goto loc_82188870;
loc_821888C8:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82188918
	if (cr6.eq) goto loc_82188918;
	// rlwinm r11,r27,2,0,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x821888E0;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82188910
	if (!cr6.gt) goto loc_82188910;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_821888F4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82188904
	if (cr6.eq) goto loc_82188904;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821956a0
	ctx.lr = 0x82188904;
	sub_821956A0(ctx, base);
loc_82188904:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// bne 0x821888f4
	if (!cr0.eq) goto loc_821888F4;
loc_82188910:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8218891c
	goto loc_8218891C;
loc_82188918:
	// li r11,0
	r11.s64 = 0;
loc_8218891C:
	// stw r11,96(r28)
	PPC_STORE_U32(r28.u32 + 96, r11.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// sth r27,102(r28)
	PPC_STORE_U16(r28.u32 + 102, r27.u16);
	// ble cr6,0x82188be4
	if (!cr6.gt) goto loc_82188BE4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r27,-32255
	r27.s64 = -2113863680;
	// lis r26,-32255
	r26.s64 = -2113863680;
	// lfs f29,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f29.f64 = double(temp.f32);
	// lis r25,-32255
	r25.s64 = -2113863680;
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lis r31,-32255
	r31.s64 = -2113863680;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
	// li r30,1
	r30.s64 = 1;
	// addi r27,r27,-19848
	r27.s64 = r27.s64 + -19848;
	// addi r26,r26,-19864
	r26.s64 = r26.s64 + -19864;
	// addi r25,r25,-19888
	r25.s64 = r25.s64 + -19888;
	// addi r24,r31,-19900
	r24.s64 = r31.s64 + -19900;
	// addi r23,r3,-19912
	r23.s64 = ctx.r3.s64 + -19912;
	// addi r22,r4,-19924
	r22.s64 = ctx.r4.s64 + -19924;
	// addi r21,r5,-19932
	r21.s64 = ctx.r5.s64 + -19932;
	// addi r20,r6,-19940
	r20.s64 = ctx.r6.s64 + -19940;
	// addi r19,r7,-19948
	r19.s64 = ctx.r7.s64 + -19948;
	// addi r18,r8,-19956
	r18.s64 = ctx.r8.s64 + -19956;
	// addi r17,r9,-19964
	r17.s64 = ctx.r9.s64 + -19964;
	// addi r16,r10,-19976
	r16.s64 = ctx.r10.s64 + -19976;
	// addi r15,r11,-19988
	r15.s64 = r11.s64 + -19988;
loc_821889B8:
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a838
	ctx.lr = 0x821889C8;
	sub_8218A838(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82188bd0
	if (cr6.eq) goto loc_82188BD0;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a6a0
	ctx.lr = 0x821889F4;
	sub_8218A6A0(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82188bd0
	if (!cr6.eq) goto loc_82188BD0;
	// lhz r11,100(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 100);
	// lwz r10,96(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// sth r7,100(r28)
	PPC_STORE_U16(r28.u32 + 100, ctx.r7.u16);
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82189dc0
	ctx.lr = 0x82188A40;
	sub_82189DC0(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a868
	ctx.lr = 0x82188A58;
	sub_8218A868(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a868
	ctx.lr = 0x82188A70;
	sub_8218A868(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a868
	ctx.lr = 0x82188A88;
	sub_8218A868(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a868
	ctx.lr = 0x82188AA0;
	sub_8218A868(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a868
	ctx.lr = 0x82188AB8;
	sub_8218A868(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a8c8
	ctx.lr = 0x82188AD0;
	sub_8218A8C8(ctx, base);
	// stfs f1,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a8c8
	ctx.lr = 0x82188AE8;
	sub_8218A8C8(ctx, base);
	// stfs f1,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a8c8
	ctx.lr = 0x82188B00;
	sub_8218A8C8(ctx, base);
	// stfs f1,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a958
	ctx.lr = 0x82188B18;
	sub_8218A958(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r6,0
	ctx.r6.s64 = 0;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r9,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r9.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a958
	ctx.lr = 0x82188B3C;
	sub_8218A958(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a868
	ctx.lr = 0x82188B54;
	sub_8218A868(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a868
	ctx.lr = 0x82188B6C;
	sub_8218A868(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a958
	ctx.lr = 0x82188B84;
	sub_8218A958(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218a958
	ctx.lr = 0x82188B9C;
	sub_8218A958(ctx, base);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// cmpwi cr6,r8,6
	cr6.compare<int32_t>(ctx.r8.s32, 6, xer);
	// stw r7,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r7.u32);
	// beq cr6,0x82188bd0
	if (cr6.eq) goto loc_82188BD0;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82188bd0
	if (cr6.eq) goto loc_82188BD0;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
loc_82188BD0:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// bne 0x821889b8
	if (!cr0.eq) goto loc_821889B8;
loc_82188BE4:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82188BF8"))) PPC_WEAK_FUNC(sub_82188BF8);
PPC_FUNC_IMPL(__imp__sub_82188BF8) {
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
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218c638
	ctx.lr = 0x82188C14;
	sub_8218C638(ctx, base);
	// lhz r9,14(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r10,r11,-24720
	ctx.r10.s64 = r11.s64 + -24720;
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r11,r8,r10
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82189bd0
	ctx.lr = 0x82188C34;
	sub_82189BD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821886b0
	ctx.lr = 0x82188C3C;
	sub_821886B0(ctx, base);
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

__attribute__((alias("__imp__sub_82188C50"))) PPC_WEAK_FUNC(sub_82188C50);
PPC_FUNC_IMPL(__imp__sub_82188C50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// lwz r7,16(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// lwz r6,20(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r6,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r6.u32);
	// lwz r5,24(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// lwz r10,32(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// lfs f0,36(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	f0.f64 = double(temp.f32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lfs f13,40(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// lfs f12,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,44(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// lbz r9,48(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 48);
	// stb r9,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r9.u8);
	// lwz r8,52(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	// stw r8,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
	// lwz r7,56(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	// stw r7,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r7.u32);
	// lwz r6,60(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	// stw r6,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r6.u32);
	// lwz r5,64(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 64);
	// stw r5,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r5.u32);
	// lwz r11,68(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// lwz r10,72(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// lwz r9,76(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	// stw r9,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82188CF4"))) PPC_WEAK_FUNC(sub_82188CF4);
PPC_FUNC_IMPL(__imp__sub_82188CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188CF8"))) PPC_WEAK_FUNC(sub_82188CF8);
PPC_FUNC_IMPL(__imp__sub_82188CF8) {
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
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82194a70
	ctx.lr = 0x82188D14;
	sub_82194A70(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// addi r10,r11,-20308
	ctx.r10.s64 = r11.s64 + -20308;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821884b0
	ctx.lr = 0x82188D28;
	sub_821884B0(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// lwz r11,-13192(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13192);
	// stb r11,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r11.u8);
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

__attribute__((alias("__imp__sub_82188D60"))) PPC_WEAK_FUNC(sub_82188D60);
PPC_FUNC_IMPL(__imp__sub_82188D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r10,14(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r9,-24720
	ctx.r8.s64 = ctx.r9.s64 + -24720;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r4,r11
	ctx.r6.u64 = ctx.r4.u64 + r11.u64;
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,96(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 96);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82188c50
	sub_82188C50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188D90"))) PPC_WEAK_FUNC(sub_82188D90);
PPC_FUNC_IMPL(__imp__sub_82188D90) {
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
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// bl 0x8218c110
	ctx.lr = 0x82188DB8;
	sub_8218C110(ctx, base);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// sth r30,100(r31)
	PPC_STORE_U16(r31.u32 + 100, r30.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r30,102(r31)
	PPC_STORE_U16(r31.u32 + 102, r30.u16);
	// stw r30,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r30.u32);
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

__attribute__((alias("__imp__sub_82188DE4"))) PPC_WEAK_FUNC(sub_82188DE4);
PPC_FUNC_IMPL(__imp__sub_82188DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188DE8"))) PPC_WEAK_FUNC(sub_82188DE8);
PPC_FUNC_IMPL(__imp__sub_82188DE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82188DF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,108(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// bl 0x82130588
	ctx.lr = 0x82188E00;
	sub_82130588(ctx, base);
	// lhz r31,102(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 102);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82188e38
	if (cr6.eq) goto loc_82188E38;
	// lwz r29,96(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82188e30
	if (!cr6.gt) goto loc_82188E30;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82188E1C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82188E24;
	sub_82130000(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// bne 0x82188e1c
	if (!cr0.eq) goto loc_82188E1C;
loc_82188E30:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82188E38;
	sub_82130588(ctx, base);
loc_82188E38:
	// addi r3,r28,8
	ctx.r3.s64 = r28.s64 + 8;
	// bl 0x8218c6b0
	ctx.lr = 0x82188E40;
	sub_8218C6B0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82188E48;
	sub_821D2AA0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82188E50"))) PPC_WEAK_FUNC(sub_82188E50);
PPC_FUNC_IMPL(__imp__sub_82188E50) {
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
	ctx.lr = 0x82188E58;
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r23,0
	r23.s64 = 0;
	// addi r28,r11,-24720
	r28.s64 = r11.s64 + -24720;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r25,r23
	r25.u64 = r23.u64;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82188E78:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82188ea4
	if (cr6.eq) goto loc_82188EA4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r28,1024
	ctx.r10.s64 = r28.s64 + 1024;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82188e78
	if (cr6.lt) goto loc_82188E78;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d9234
	return;
loc_82188EA4:
	// cmpwi cr6,r25,-1
	cr6.compare<int32_t>(r25.s32, -1, xer);
	// bne cr6,0x82188eb8
	if (!cr6.eq) goto loc_82188EB8;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d9234
	return;
loc_82188EB8:
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x82188EC0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82188ed4
	if (cr6.eq) goto loc_82188ED4;
	// bl 0x82188d90
	ctx.lr = 0x82188ECC;
	sub_82188D90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82188ed8
	goto loc_82188ED8;
loc_82188ED4:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_82188ED8:
	// rlwinm r27,r25,2,0,29
	r27.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stwx r11,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, r11.u32);
	// bl 0x821c9ab0
	ctx.lr = 0x82188EE8;
	sub_821C9AB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// bl 0x821d2a58
	ctx.lr = 0x82188EF4;
	sub_821D2A58(ctx, base);
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821c9790
	ctx.lr = 0x82188F04;
	sub_821C9790(ctx, base);
	// lwzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r5,9
	ctx.r5.s64 = 9;
	// addi r4,r8,-19804
	ctx.r4.s64 = ctx.r8.s64 + -19804;
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwzx r7,r27,r28
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// stw r9,104(r7)
	PPC_STORE_U32(ctx.r7.u32 + 104, ctx.r9.u32);
	// bl 0x823dd800
	ctx.lr = 0x82188F2C;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82188ff8
	if (cr6.eq) goto loc_82188FF8;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821ca980
	ctx.lr = 0x82188F44;
	sub_821CA980(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,-19812
	ctx.r10.s64 = ctx.r10.s64 + -19812;
loc_82188F50:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82188f50
	if (!cr6.eq) goto loc_82188F50;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82188F64:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82188f64
	if (!cr6.eq) goto loc_82188F64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x82188F90;
	sub_821CA540(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9ab0
	ctx.lr = 0x82188F98;
	sub_821C9AB0(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82188F9C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82188f9c
	if (!cr6.eq) goto loc_82188F9C;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82188FB0:
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
	// bne cr6,0x82188fb0
	if (!cr6.eq) goto loc_82188FB0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r11,-19816
	r31.s64 = r11.s64 + -19816;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x821ca6a8
	ctx.lr = 0x82188FE8;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82188FF4;
	sub_821C9A90(ctx, base);
	// b 0x82189064
	goto loc_82189064;
loc_82188FF8:
	// addi r11,r1,368
	r11.s64 = ctx.r1.s64 + 368;
	// li r10,255
	ctx.r10.s64 = 255;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// subf r9,r10,r26
	ctx.r9.s64 = r26.s64 - ctx.r10.s64;
loc_8218900C:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82189024
	if (cr6.eq) goto loc_82189024;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8218900c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8218900C;
loc_82189024:
	// stb r23,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r23.u8);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r31,r10,-19816
	r31.s64 = ctx.r10.s64 + -19816;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x821c9c50
	ctx.lr = 0x82189040;
	sub_821C9C50(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// bl 0x821ca6a8
	ctx.lr = 0x82189060;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_82189064:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x821890a4
	if (!cr6.eq) goto loc_821890A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x82189078;
	sub_821CA540(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x82189090;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8218909C;
	sub_821C9A90(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821890cc
	if (cr6.eq) goto loc_821890CC;
loc_821890A4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821be990
	ctx.lr = 0x821890B4;
	sub_821BE990(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dd7f0
	ctx.lr = 0x821890BC;
	sub_823DD7F0(ctx, base);
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// stw r3,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x821890CC;
	sub_821BE610(ctx, base);
loc_821890CC:
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x8218c760
	ctx.lr = 0x821890E0;
	sub_8218C760(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82189118
	if (!cr6.eq) goto loc_82189118;
	// lwzx r31,r27,r28
	r31.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82189108
	if (cr6.eq) goto loc_82189108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82188de8
	ctx.lr = 0x82189100;
	sub_82188DE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82189108;
	sub_82130588(ctx, base);
loc_82189108:
	// li r3,-1
	ctx.r3.s64 = -1;
	// stwx r23,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, r23.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d9234
	return;
loc_82189118:
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// bl 0x82188830
	ctx.lr = 0x82189120;
	sub_82188830(ctx, base);
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// bl 0x821887a0
	ctx.lr = 0x82189128;
	sub_821887A0(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82189134"))) PPC_WEAK_FUNC(sub_82189134);
PPC_FUNC_IMPL(__imp__sub_82189134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189138"))) PPC_WEAK_FUNC(sub_82189138);
PPC_FUNC_IMPL(__imp__sub_82189138) {
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
	ctx.lr = 0x82189140;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8218915c
	if (!cr6.eq) goto loc_8218915C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_8218915C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9ab0
	ctx.lr = 0x82189164;
	sub_821C9AB0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8218916C;
	sub_821C9790(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r29,r11,-24720
	r29.s64 = r11.s64 + -24720;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8218917C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82189194
	if (cr6.eq) goto loc_82189194;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// beq cr6,0x821892e4
	if (cr6.eq) goto loc_821892E4;
loc_82189194:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r29,1024
	ctx.r10.s64 = r29.s64 + 1024;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8218917c
	if (cr6.lt) goto loc_8218917C;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r11,28
	r11.s64 = 28;
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821891C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82189250
	if (!cr6.eq) goto loc_82189250;
	// li r11,60
	r11.s64 = 60;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82189250
	if (!cr6.eq) goto loc_82189250;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19556
	ctx.r4.s64 = r11.s64 + -19556;
	// li r5,11
	ctx.r5.s64 = 11;
	// bl 0x823da950
	ctx.lr = 0x821891F4;
	sub_823DA950(ctx, base);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_821891FC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821891fc
	if (!cr6.eq) goto loc_821891FC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82189210:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82189210
	if (!cr6.eq) goto loc_82189210;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82188e50
	ctx.lr = 0x82189234;
	sub_82188E50(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x82189304
	if (!cr6.eq) goto loc_82189304;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82188e50
	ctx.lr = 0x82189248;
	sub_82188E50(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x82189304
	if (!cr6.eq) goto loc_82189304;
loc_82189250:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lbz r10,23664(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 23664);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82189270
	if (cr6.eq) goto loc_82189270;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-19624
	ctx.r3.s64 = r11.s64 + -19624;
	// bl 0x821bd618
	ctx.lr = 0x82189270;
	sub_821BD618(ctx, base);
loc_82189270:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-19636
	ctx.r4.s64 = r11.s64 + -19636;
	// bl 0x823d90b0
	ctx.lr = 0x82189280;
	sub_823D90B0(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r30,r9,1
	r30.u64 = ctx.r9.u64 ^ 1;
	// rlwinm r31,r30,2,0,29
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r31,r29
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821892a8
	if (!cr6.eq) goto loc_821892A8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-19700
	ctx.r3.s64 = r11.s64 + -19700;
	// bl 0x821bd618
	ctx.lr = 0x821892A8;
	sub_821BD618(ctx, base);
loc_821892A8:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r11,-21108(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21108);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-21108(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21108, r11.u32);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bge cr6,0x821892f0
	if (!cr6.lt) goto loc_821892F0;
	// lwzx r11,r31,r29
	r11.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r10,-19748
	ctx.r3.s64 = ctx.r10.s64 + -19748;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130000
	ctx.lr = 0x821892D8;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_821892E4:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_821892F0:
	// bne cr6,0x82189300
	if (!cr6.eq) goto loc_82189300;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-19792
	ctx.r3.s64 = r11.s64 + -19792;
	// bl 0x82130000
	ctx.lr = 0x82189300;
	sub_82130000(ctx, base);
loc_82189300:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82189304:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218930C"))) PPC_WEAK_FUNC(sub_8218930C);
PPC_FUNC_IMPL(__imp__sub_8218930C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189310"))) PPC_WEAK_FUNC(sub_82189310);
PPC_FUNC_IMPL(__imp__sub_82189310) {
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
	ctx.lr = 0x82189318;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821954d0
	ctx.lr = 0x82189328;
	sub_821954D0(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r29,r31,68
	r29.s64 = r31.s64 + 68;
	// addi r10,r11,-20308
	ctx.r10.s64 = r11.s64 + -20308;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821884b0
	ctx.lr = 0x82189340;
	sub_821884B0(ctx, base);
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82189360
	if (cr6.eq) goto loc_82189360;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82189354;
	sub_8217D890(ctx, base);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r10.u32);
loc_82189360:
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82189380
	if (cr6.eq) goto loc_82189380;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82189374;
	sub_8217D890(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r10.u32);
loc_82189380:
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821893a0
	if (cr6.eq) goto loc_821893A0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82189394;
	sub_8217D890(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
loc_821893A0:
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821893c0
	if (cr6.eq) goto loc_821893C0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x821893B4;
	sub_8217D890(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
loc_821893C0:
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821893f0
	if (cr6.eq) goto loc_821893F0;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-23180
	ctx.r10.s64 = r11.s64 + -23180;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821893f0
	if (cr6.eq) goto loc_821893F0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82195618
	ctx.lr = 0x821893F0;
	sub_82195618(ctx, base);
loc_821893F0:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82189404
	if (cr6.eq) goto loc_82189404;
	// bl 0x82195a98
	ctx.lr = 0x82189400;
	sub_82195A98(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
loc_82189404:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x82189138
	ctx.lr = 0x8218940C;
	sub_82189138(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lbz r4,9(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 9);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// bl 0x82187aa0
	ctx.lr = 0x82189420;
	sub_82187AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821886b0
	ctx.lr = 0x82189428;
	sub_821886B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82189434"))) PPC_WEAK_FUNC(sub_82189434);
PPC_FUNC_IMPL(__imp__sub_82189434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189438"))) PPC_WEAK_FUNC(sub_82189438);
PPC_FUNC_IMPL(__imp__sub_82189438) {
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
	ctx.lr = 0x82189440;
	// stwu r1,-1408(r1)
	ea = -1408 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82189478
	if (!cr6.eq) goto loc_82189478;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9234
	return;
loc_82189478:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82189138
	ctx.lr = 0x82189480;
	sub_82189138(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// bne cr6,0x8218949c
	if (!cr6.eq) goto loc_8218949C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-19544
	ctx.r3.s64 = r11.s64 + -19544;
	// bl 0x821bd618
	ctx.lr = 0x8218949C;
	sub_821BD618(ctx, base);
loc_8218949C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821894b0
	if (cr6.eq) goto loc_821894B0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821378b8
	ctx.lr = 0x821894AC;
	sub_821378B8(ctx, base);
	// stw r3,56(r23)
	PPC_STORE_U32(r23.u32 + 56, ctx.r3.u32);
loc_821894B0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821894c4
	if (cr6.eq) goto loc_821894C4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821378b8
	ctx.lr = 0x821894C0;
	sub_821378B8(ctx, base);
	// stw r3,60(r23)
	PPC_STORE_U32(r23.u32 + 60, ctx.r3.u32);
loc_821894C4:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821894e8
	if (cr6.eq) goto loc_821894E8;
	// lbz r11,10(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 10);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stb r10,10(r23)
	PPC_STORE_U8(r23.u32 + 10, ctx.r10.u8);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x821378b8
	ctx.lr = 0x821894E0;
	sub_821378B8(ctx, base);
	// stw r3,52(r23)
	PPC_STORE_U32(r23.u32 + 52, ctx.r3.u32);
	// b 0x821894f4
	goto loc_821894F4;
loc_821894E8:
	// lbz r11,10(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 10);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,10(r23)
	PPC_STORE_U8(r23.u32 + 10, ctx.r10.u8);
loc_821894F4:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r27,14(r23)
	PPC_STORE_U16(r23.u32 + 14, r27.u16);
	// beq cr6,0x82189508
	if (cr6.eq) goto loc_82189508;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// b 0x8218950c
	goto loc_8218950C;
loc_82189508:
	// li r11,-1
	r11.s64 = -1;
loc_8218950C:
	// stw r11,64(r23)
	PPC_STORE_U32(r23.u32 + 64, r11.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lhz r10,14(r23)
	ctx.r10.u64 = PPC_LOAD_U16(r23.u32 + 14);
	// addi r4,r23,16
	ctx.r4.s64 = r23.s64 + 16;
	// addi r9,r11,-24720
	ctx.r9.s64 = r11.s64 + -24720;
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82189bd0
	ctx.lr = 0x82189530;
	sub_82189BD0(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82187aa0
	ctx.lr = 0x8218953C;
	sub_82187AA0(ctx, base);
	// lwz r30,1492(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1492);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x82189918
	if (cr6.eq) goto loc_82189918;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82189920
	if (!cr6.eq) goto loc_82189920;
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// bne cr6,0x821896a0
	if (!cr6.eq) goto loc_821896A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821378b8
	ctx.lr = 0x82189560;
	sub_821378B8(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,48(r23)
	PPC_STORE_U32(r23.u32 + 48, ctx.r3.u32);
	// addi r10,r11,-23180
	ctx.r10.s64 = r11.s64 + -23180;
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82189690
	if (cr6.eq) goto loc_82189690;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,56(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// addi r5,r23,68
	ctx.r5.s64 = r23.s64 + 68;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82195618
	ctx.lr = 0x82189590;
	sub_82195618(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82189690
	if (cr6.eq) goto loc_82189690;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821895B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82189940
	if (cr6.eq) goto loc_82189940;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r29,r11,-29624
	r29.s64 = r11.s64 + -29624;
	// addi r31,r10,-29628
	r31.s64 = ctx.r10.s64 + -29628;
loc_821895D0:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_821895D8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821895fc
	if (cr6.eq) goto loc_821895FC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821895d8
	if (cr6.eq) goto loc_821895D8;
loc_821895FC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82189940
	if (cr6.eq) goto loc_82189940;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d0898
	ctx.lr = 0x82189610;
	sub_821D0898(ctx, base);
loc_82189610:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218962C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82189668
	if (cr6.eq) goto loc_82189668;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_8218963C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82189660
	if (cr6.eq) goto loc_82189660;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8218963c
	if (cr6.eq) goto loc_8218963C;
loc_82189660:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82189610
	if (!cr6.eq) goto loc_82189610;
loc_82189668:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82189684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821895d0
	if (!cr6.eq) goto loc_821895D0;
	// b 0x82189940
	goto loc_82189940;
loc_82189690:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82194cb8
	ctx.lr = 0x8218969C;
	sub_82194CB8(ctx, base);
	// b 0x82189940
	goto loc_82189940;
loc_821896A0:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r10,r11,-23180
	ctx.r10.s64 = r11.s64 + -23180;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218985c
	if (cr6.eq) goto loc_8218985C;
	// lwz r4,56(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218985c
	if (cr6.eq) goto loc_8218985C;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r23,68
	ctx.r5.s64 = r23.s64 + 68;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82195618
	ctx.lr = 0x821896D0;
	sub_82195618(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82189940
	if (cr6.eq) goto loc_82189940;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_821896E4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821896e4
	if (!cr6.eq) goto loc_821896E4;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// bl 0x82130528
	ctx.lr = 0x82189708;
	sub_82130528(ctx, base);
	// stw r3,48(r23)
	PPC_STORE_U32(r23.u32 + 48, ctx.r3.u32);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
loc_82189710:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x82189710
	if (!cr6.eq) goto loc_82189710;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r4,48(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 48);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-20164
	ctx.r5.s64 = r11.s64 + -20164;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82189748;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82189940
	if (cr6.eq) goto loc_82189940;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r4,48(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 48);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-29924
	ctx.r9.s64 = r11.s64 + -29924;
	// stw r10,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r10.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r9,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r9.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cf7b8
	ctx.lr = 0x82189778;
	sub_821CF7B8(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x82189788;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82189844
	if (cr6.eq) goto loc_82189844;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r30,r11,-29624
	r30.s64 = r11.s64 + -29624;
	// addi r31,r10,-29628
	r31.s64 = ctx.r10.s64 + -29628;
loc_821897A0:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_821897A8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821897cc
	if (cr6.eq) goto loc_821897CC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821897a8
	if (cr6.eq) goto loc_821897A8;
loc_821897CC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82189844
	if (cr6.eq) goto loc_82189844;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x821897E0;
	sub_821D0898(ctx, base);
loc_821897E0:
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x821897F0;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8218982c
	if (cr6.eq) goto loc_8218982C;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_82189800:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82189824
	if (cr6.eq) goto loc_82189824;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82189800
	if (cr6.eq) goto loc_82189800;
loc_82189824:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821897e0
	if (!cr6.eq) goto loc_821897E0;
loc_8218982C:
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x8218983C;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821897a0
	if (!cr6.eq) goto loc_821897A0;
loc_82189844:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8218984C;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r10.u32);
	// b 0x82189940
	goto loc_82189940;
loc_8218985C:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82189860:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82189860
	if (!cr6.eq) goto loc_82189860;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// bl 0x82130528
	ctx.lr = 0x82189884;
	sub_82130528(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r3,48(r23)
	PPC_STORE_U32(r23.u32 + 48, ctx.r3.u32);
loc_8218988C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x8218988c
	if (!cr6.eq) goto loc_8218988C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r4,0(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-20164
	ctx.r5.s64 = r11.s64 + -20164;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x821898C4;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82189940
	if (cr6.eq) goto loc_82189940;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r4,0(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-29924
	ctx.r9.s64 = r11.s64 + -29924;
	// stw r10,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, ctx.r10.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r9,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, ctx.r9.u32);
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821cf7b8
	ctx.lr = 0x821898F4;
	sub_821CF7B8(ctx, base);
	// addi r4,r1,768
	ctx.r4.s64 = ctx.r1.s64 + 768;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82194cb8
	ctx.lr = 0x82189900;
	sub_82194CB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x82189908;
	sub_821BE610(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r7,r8,-30140
	ctx.r7.s64 = ctx.r8.s64 + -30140;
	// stw r7,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, ctx.r7.u32);
	// b 0x82189940
	goto loc_82189940;
loc_82189918:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82189940
	if (cr6.eq) goto loc_82189940;
loc_82189920:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821378b8
	ctx.lr = 0x82189928;
	sub_821378B8(ctx, base);
	// stw r3,48(r23)
	PPC_STORE_U32(r23.u32 + 48, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r23,68
	ctx.r5.s64 = r23.s64 + 68;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82195548
	ctx.lr = 0x82189940;
	sub_82195548(ctx, base);
loc_82189940:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82189968;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,40(r23)
	PPC_STORE_U32(r23.u32 + 40, ctx.r3.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821886b0
	ctx.lr = 0x82189974;
	sub_821886B0(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82188580
	ctx.lr = 0x8218997C;
	sub_82188580(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82189988"))) PPC_WEAK_FUNC(sub_82189988);
PPC_FUNC_IMPL(__imp__sub_82189988) {
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
	ctx.lr = 0x82189990;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r8,r9,23656
	ctx.r8.s64 = ctx.r9.s64 + 23656;
	// addi r29,r11,-24720
	r29.s64 = r11.s64 + -24720;
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r31,r29
	r31.u64 = r29.u64;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, r11.u32);
	// li r28,0
	r28.s64 = 0;
	// stw r10,23656(r9)
	PPC_STORE_U32(ctx.r9.u32 + 23656, ctx.r10.u32);
loc_821899BC:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821899dc
	if (cr6.eq) goto loc_821899DC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82188de8
	ctx.lr = 0x821899D0;
	sub_82188DE8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821899D8;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_821899DC:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,1024
	r11.s64 = r29.s64 + 1024;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x821899bc
	if (cr6.lt) goto loc_821899BC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821899F4"))) PPC_WEAK_FUNC(sub_821899F4);
PPC_FUNC_IMPL(__imp__sub_821899F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821899F8"))) PPC_WEAK_FUNC(sub_821899F8);
PPC_FUNC_IMPL(__imp__sub_821899F8) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-14916
	ctx.r4.s64 = r11.s64 + -14916;
	// bl 0x821c8fe0
	ctx.lr = 0x82189A20;
	sub_821C8FE0(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r11,r11,-18000
	r11.s64 = r11.s64 + -18000;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r31,r9
	r31.u64 = ctx.r9.u64;
	// beq cr6,0x82189a78
	if (cr6.eq) goto loc_82189A78;
loc_82189A3C:
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// beq cr6,0x82189a5c
	if (cr6.eq) goto loc_82189A5C;
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// lwz r31,80(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82189a3c
	if (!cr6.eq) goto loc_82189A3C;
	// b 0x82189a78
	goto loc_82189A78;
loc_82189A5C:
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// beq cr6,0x82189a78
	if (cr6.eq) goto loc_82189A78;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_82189A78:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82189A80;
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

__attribute__((alias("__imp__sub_82189A9C"))) PPC_WEAK_FUNC(sub_82189A9C);
PPC_FUNC_IMPL(__imp__sub_82189A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189AA0"))) PPC_WEAK_FUNC(sub_82189AA0);
PPC_FUNC_IMPL(__imp__sub_82189AA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// b 0x823da950
	sub_823DA950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189AC8"))) PPC_WEAK_FUNC(sub_82189AC8);
PPC_FUNC_IMPL(__imp__sub_82189AC8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189ACC"))) PPC_WEAK_FUNC(sub_82189ACC);
PPC_FUNC_IMPL(__imp__sub_82189ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189AD0"))) PPC_WEAK_FUNC(sub_82189AD0);
PPC_FUNC_IMPL(__imp__sub_82189AD0) {
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
	ctx.lr = 0x82189AD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82189b64
	if (cr6.eq) goto loc_82189B64;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_82189AF8:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lbzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82189b50
	if (!cr6.eq) goto loc_82189B50;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82189b50
	if (cr6.eq) goto loc_82189B50;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82189B20;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82189b48
	if (!cr6.eq) goto loc_82189B48;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82189b48
	if (cr6.eq) goto loc_82189B48;
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
	ctx.lr = 0x82189B48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82189B48:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r27,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, r27.u32);
loc_82189B50:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82189af8
	if (cr6.lt) goto loc_82189AF8;
loc_82189B64:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82189B6C"))) PPC_WEAK_FUNC(sub_82189B6C);
PPC_FUNC_IMPL(__imp__sub_82189B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189B70"))) PPC_WEAK_FUNC(sub_82189B70);
PPC_FUNC_IMPL(__imp__sub_82189B70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
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
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189B94"))) PPC_WEAK_FUNC(sub_82189B94);
PPC_FUNC_IMPL(__imp__sub_82189B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189B98"))) PPC_WEAK_FUNC(sub_82189B98);
PPC_FUNC_IMPL(__imp__sub_82189B98) {
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
	// bl 0x82189ad0
	ctx.lr = 0x82189BB0;
	sub_82189AD0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82189BB8;
	sub_82130588(ctx, base);
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

__attribute__((alias("__imp__sub_82189BCC"))) PPC_WEAK_FUNC(sub_82189BCC);
PPC_FUNC_IMPL(__imp__sub_82189BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189BD0"))) PPC_WEAK_FUNC(sub_82189BD0);
PPC_FUNC_IMPL(__imp__sub_82189BD0) {
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
	ctx.lr = 0x82189BD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stw r8,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r8.u32);
	// lhz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// sth r7,8(r30)
	PPC_STORE_U16(r30.u32 + 8, ctx.r7.u16);
	// lhz r4,58(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// sth r4,10(r30)
	PPC_STORE_U16(r30.u32 + 10, ctx.r4.u16);
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lhz r4,58(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82189C34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lhz r5,58(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x823da950
	ctx.lr = 0x82189C48;
	sub_823DA950(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// subf r27,r9,r29
	r27.s64 = r29.s64 - ctx.r9.s64;
	// li r28,0
	r28.s64 = 0;
	// add r8,r11,r27
	ctx.r8.u64 = r11.u64 + r27.u64;
	// stw r8,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r8.u32);
	// lhz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82189ccc
	if (cr6.eq) goto loc_82189CCC;
	// li r29,0
	r29.s64 = 0;
loc_82189C70:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lbzx r10,r28,r11
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r11.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bne cr6,0x82189cac
	if (!cr6.eq) goto loc_82189CAC;
	// lwzx r9,r29,r11
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// stwx r9,r29,r10
	PPC_STORE_U32(r29.u32 + ctx.r10.u32, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r11,r29,r8
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82189cb8
	if (cr6.eq) goto loc_82189CB8;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x82189CA8;
	sub_821CE0D8(ctx, base);
	// b 0x82189cb8
	goto loc_82189CB8;
loc_82189CAC:
	// lwzx r11,r29,r11
	r11.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// add r9,r11,r27
	ctx.r9.u64 = r11.u64 + r27.u64;
	// stwx r9,r29,r10
	PPC_STORE_U32(r29.u32 + ctx.r10.u32, ctx.r9.u32);
loc_82189CB8:
	// lhz r11,56(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82189c70
	if (cr6.lt) goto loc_82189C70;
loc_82189CCC:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82189CE0"))) PPC_WEAK_FUNC(sub_82189CE0);
PPC_FUNC_IMPL(__imp__sub_82189CE0) {
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
	ctx.lr = 0x82189CE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82189d5c
	if (cr6.eq) goto loc_82189D5C;
	// addi r11,r5,-1
	r11.s64 = ctx.r5.s64 + -1;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// beq cr6,0x82189d40
	if (cr6.eq) goto loc_82189D40;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82189d24
	if (cr6.eq) goto loc_82189D24;
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x82189D24;
	sub_821CE0D8(ctx, base);
loc_82189D24:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82189d38
	if (cr6.eq) goto loc_82189D38;
	// bl 0x82177a08
	ctx.lr = 0x82189D38;
	sub_82177A08(ctx, base);
loc_82189D38:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r29,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r29.u32);
loc_82189D40:
	// bl 0x821789d8
	ctx.lr = 0x82189D44;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82189d5c
	if (cr6.eq) goto loc_82189D5C;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21080(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21080, r11.u32);
loc_82189D5C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82189D64"))) PPC_WEAK_FUNC(sub_82189D64);
PPC_FUNC_IMPL(__imp__sub_82189D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189D68"))) PPC_WEAK_FUNC(sub_82189D68);
PPC_FUNC_IMPL(__imp__sub_82189D68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82189da4
	if (cr6.eq) goto loc_82189DA4;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// lbz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// lbz r4,1(r7)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// lbz r3,2(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// lbz r11,3(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 3);
	// stb r5,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r5.u8);
	// stb r4,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r4.u8);
	// stb r3,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r3.u8);
	// stb r11,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, r11.u8);
loc_82189DA4:
	// lwz r11,-16(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stb r8,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189DBC"))) PPC_WEAK_FUNC(sub_82189DBC);
PPC_FUNC_IMPL(__imp__sub_82189DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189DC0"))) PPC_WEAK_FUNC(sub_82189DC0);
PPC_FUNC_IMPL(__imp__sub_82189DC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,24408
	ctx.r9.s64 = r11.s64 + 24408;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189DD4"))) PPC_WEAK_FUNC(sub_82189DD4);
PPC_FUNC_IMPL(__imp__sub_82189DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189DD8"))) PPC_WEAK_FUNC(sub_82189DD8);
PPC_FUNC_IMPL(__imp__sub_82189DD8) {
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
	ctx.lr = 0x82189DE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r11,23744
	r29.s64 = r11.s64 + 23744;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_82189DF4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8218cc70
	ctx.lr = 0x82189E00;
	sub_8218CC70(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,180
	r11.s64 = r29.s64 + 180;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82189df4
	if (cr6.lt) goto loc_82189DF4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82189E1C"))) PPC_WEAK_FUNC(sub_82189E1C);
PPC_FUNC_IMPL(__imp__sub_82189E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189E20"))) PPC_WEAK_FUNC(sub_82189E20);
PPC_FUNC_IMPL(__imp__sub_82189E20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,24128
	ctx.r9.s64 = r11.s64 + 24128;
	// stwx r4,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189E34"))) PPC_WEAK_FUNC(sub_82189E34);
PPC_FUNC_IMPL(__imp__sub_82189E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189E38"))) PPC_WEAK_FUNC(sub_82189E38);
PPC_FUNC_IMPL(__imp__sub_82189E38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,24128
	ctx.r10.s64 = ctx.r10.s64 + 24128;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r8,r9,24192
	ctx.r8.s64 = ctx.r9.s64 + 24192;
	// lwzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stwx r4,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r4.u32);
	// stwx r7,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189E5C"))) PPC_WEAK_FUNC(sub_82189E5C);
PPC_FUNC_IMPL(__imp__sub_82189E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189E60"))) PPC_WEAK_FUNC(sub_82189E60);
PPC_FUNC_IMPL(__imp__sub_82189E60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,24192
	ctx.r9.s64 = r11.s64 + 24192;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r7,r8,24128
	ctx.r7.s64 = ctx.r8.s64 + 24128;
	// lwzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stwx r6,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189E80"))) PPC_WEAK_FUNC(sub_82189E80);
PPC_FUNC_IMPL(__imp__sub_82189E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,23744
	ctx.r9.s64 = r11.s64 + 23744;
	// stwx r4,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
	// b 0x8218cc70
	sub_8218CC70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189E94"))) PPC_WEAK_FUNC(sub_82189E94);
PPC_FUNC_IMPL(__imp__sub_82189E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189E98"))) PPC_WEAK_FUNC(sub_82189E98);
PPC_FUNC_IMPL(__imp__sub_82189E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,23744
	ctx.r10.s64 = ctx.r10.s64 + 23744;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r8,r9,23936
	ctx.r8.s64 = ctx.r9.s64 + 23936;
	// lwzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stwx r4,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r4.u32);
	// stwx r7,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r7.u32);
	// b 0x8218cc70
	sub_8218CC70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189EBC"))) PPC_WEAK_FUNC(sub_82189EBC);
PPC_FUNC_IMPL(__imp__sub_82189EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189EC0"))) PPC_WEAK_FUNC(sub_82189EC0);
PPC_FUNC_IMPL(__imp__sub_82189EC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,23936
	ctx.r9.s64 = r11.s64 + 23936;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r7,r8,23744
	ctx.r7.s64 = ctx.r8.s64 + 23744;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stwx r4,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r4.u32);
	// b 0x8218cc70
	sub_8218CC70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189EE0"))) PPC_WEAK_FUNC(sub_82189EE0);
PPC_FUNC_IMPL(__imp__sub_82189EE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stfs f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,-16(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// addi r8,r11,24128
	ctx.r8.s64 = r11.s64 + 24128;
	// stwx r10,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189EFC"))) PPC_WEAK_FUNC(sub_82189EFC);
PPC_FUNC_IMPL(__imp__sub_82189EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189F00"))) PPC_WEAK_FUNC(sub_82189F00);
PPC_FUNC_IMPL(__imp__sub_82189F00) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,12
	ctx.r9.s64 = 12;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r4,r11,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r11,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r11.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82189F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82189f9c
	if (!cr6.gt) goto loc_82189F9C;
	// li r8,0
	ctx.r8.s64 = 0;
	// lis r11,0
	r11.s64 = 0;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// ori r9,r11,65535
	ctx.r9.u64 = r11.u64 | 65535;
loc_82189F6C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82189f90
	if (cr0.eq) goto loc_82189F90;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// sth r9,28(r11)
	PPC_STORE_U16(r11.u32 + 28, ctx.r9.u16);
	// sth r9,30(r11)
	PPC_STORE_U16(r11.u32 + 30, ctx.r9.u16);
loc_82189F90:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bne 0x82189f6c
	if (!cr0.eq) goto loc_82189F6C;
loc_82189F9C:
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

__attribute__((alias("__imp__sub_82189FB4"))) PPC_WEAK_FUNC(sub_82189FB4);
PPC_FUNC_IMPL(__imp__sub_82189FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189FB8"))) PPC_WEAK_FUNC(sub_82189FB8);
PPC_FUNC_IMPL(__imp__sub_82189FB8) {
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
	ctx.lr = 0x82189FC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lhz r31,28(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 28);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218a000
	if (!cr6.gt) goto loc_8218A000;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r11,23744
	r29.s64 = r11.s64 + 23744;
loc_82189FE0:
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r29
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// bl 0x8218cc70
	ctx.lr = 0x82189FF4;
	sub_8218CC70(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x82189fe0
	if (!cr0.eq) goto loc_82189FE0;
loc_8218A000:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218A008"))) PPC_WEAK_FUNC(sub_8218A008);
PPC_FUNC_IMPL(__imp__sub_8218A008) {
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
	ctx.lr = 0x8218A010;
	// stwu r1,-896(r1)
	ea = -896 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218A024;
	sub_821BE4F0(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r3,255
	cr6.compare<int32_t>(ctx.r3.s32, 255, xer);
	// bne cr6,0x8218a07c
	if (!cr6.eq) goto loc_8218A07C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218A038;
	sub_821BE4F0(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218A044;
	sub_821BE4F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be250
	ctx.lr = 0x8218A054;
	sub_821BE250(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r5,r10,-19112
	ctx.r5.s64 = ctx.r10.s64 + -19112;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lwz r6,-21084(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -21084);
	// bl 0x82137a08
	ctx.lr = 0x8218A074;
	sub_82137A08(ctx, base);
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// b 0x8218a0a0
	goto loc_8218A0A0;
loc_8218A07C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// addi r5,r10,-19120
	ctx.r5.s64 = ctx.r10.s64 + -19120;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
	// lwz r6,-21084(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -21084);
	// bl 0x82137a08
	ctx.lr = 0x8218A09C;
	sub_82137A08(ctx, base);
	// addi r4,r1,592
	ctx.r4.s64 = ctx.r1.s64 + 592;
loc_8218A0A0:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821d2a58
	ctx.lr = 0x8218A0A8;
	sub_821D2A58(ctx, base);
	// lis r10,8191
	ctx.r10.s64 = 536805376;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x8218a0c4
	if (!cr6.gt) goto loc_8218A0C4;
	// li r4,-1
	ctx.r4.s64 = -1;
loc_8218A0C4:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8218A0E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8218a188
	if (!cr6.gt) goto loc_8218A188;
	// li r30,0
	r30.s64 = 0;
loc_8218A100:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218A108;
	sub_821BE4F0(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stbx r10,r11,r30
	PPC_STORE_U8(r11.u32 + r30.u32, ctx.r10.u8);
	// bl 0x821be4f0
	ctx.lr = 0x8218A11C;
	sub_821BE4F0(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// add r8,r11,r30
	ctx.r8.u64 = r11.u64 + r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r9,1(r8)
	PPC_STORE_U8(ctx.r8.u32 + 1, ctx.r9.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// bl 0x821be6a8
	ctx.lr = 0x8218A144;
	sub_821BE6A8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218A14C;
	sub_821BE4F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be250
	ctx.lr = 0x8218A15C;
	sub_821BE250(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x8218A168;
	sub_821C9790(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// add r7,r11,r30
	ctx.r7.u64 = r11.u64 + r30.u64;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// stw r3,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r3.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpw cr6,r28,r6
	cr6.compare<int32_t>(r28.s32, ctx.r6.s32, xer);
	// blt cr6,0x8218a100
	if (cr6.lt) goto loc_8218A100;
loc_8218A188:
	// addi r1,r1,896
	ctx.r1.s64 = ctx.r1.s64 + 896;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218A190"))) PPC_WEAK_FUNC(sub_8218A190);
PPC_FUNC_IMPL(__imp__sub_8218A190) {
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
	ctx.lr = 0x8218A198;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8218a008
	ctx.lr = 0x8218A1AC;
	sub_8218A008(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// bl 0x821be6a8
	ctx.lr = 0x8218A1BC;
	sub_821BE6A8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,82
	ctx.r4.s64 = r31.s64 + 82;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be6a8
	ctx.lr = 0x8218A1CC;
	sub_821BE6A8(ctx, base);
	// lhz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// bl 0x82130528
	ctx.lr = 0x8218A1D4;
	sub_82130528(ctx, base);
	// lhz r10,82(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// lhz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplw cr6,r5,r10
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, xer);
	// beq cr6,0x8218a228
	if (cr6.eq) goto loc_8218A228;
	// neg r11,r10
	r11.s64 = -ctx.r10.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8218A1F4;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821be250
	ctx.lr = 0x8218A210;
	sub_821BE250(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r6,82(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// lhz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// bl 0x821d2e28
	ctx.lr = 0x8218A224;
	sub_821D2E28(ctx, base);
	// b 0x8218a234
	goto loc_8218A234;
loc_8218A228:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be250
	ctx.lr = 0x8218A234;
	sub_821BE250(ctx, base);
loc_8218A234:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r30,r28,12
	r30.s64 = r28.s64 + 12;
	// stw r10,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r10.u32);
	// lwz r11,-28076(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218a25c
	if (cr6.eq) goto loc_8218A25C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82418210
	ctx.lr = 0x8218A258;
	sub_82418210(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8218A25C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8218A264;
	sub_82130588(ctx, base);
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218A26C"))) PPC_WEAK_FUNC(sub_8218A26C);
PPC_FUNC_IMPL(__imp__sub_8218A26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218A270"))) PPC_WEAK_FUNC(sub_8218A270);
PPC_FUNC_IMPL(__imp__sub_8218A270) {
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
	ctx.lr = 0x8218A278;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8218a008
	ctx.lr = 0x8218A288;
	sub_8218A008(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// bl 0x821be6a8
	ctx.lr = 0x8218A298;
	sub_821BE6A8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be6a8
	ctx.lr = 0x8218A2A8;
	sub_821BE6A8(ctx, base);
	// lhz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8218a2c4
	if (!cr6.eq) goto loc_8218A2C4;
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8218A2C4:
	// lhz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// bl 0x82130528
	ctx.lr = 0x8218A2CC;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821be250
	ctx.lr = 0x8218A2E0;
	sub_821BE250(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r31,r29,12
	r31.s64 = r29.s64 + 12;
	// stw r8,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r8.u32);
	// lwz r11,-28076(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28076);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218a308
	if (cr6.eq) goto loc_8218A308;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82418100
	ctx.lr = 0x8218A304;
	sub_82418100(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8218A308:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8218A310;
	sub_82130588(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218A318"))) PPC_WEAK_FUNC(sub_8218A318);
PPC_FUNC_IMPL(__imp__sub_8218A318) {
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
	ctx.lr = 0x8218A320;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// li r21,0
	r21.s64 = 0;
	// addi r23,r10,24256
	r23.s64 = ctx.r10.s64 + 24256;
	// lhz r25,12(r30)
	r25.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r11,r25,3
	r11.s64 = r25.s64 + 3;
	// lwz r9,76(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// addi r8,r25,15
	ctx.r8.s64 = r25.s64 + 15;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// rlwinm r29,r11,2,0,27
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFF0;
	// sth r25,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r25.u16);
	// rlwinm r11,r8,0,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// add r22,r29,r11
	r22.u64 = r29.u64 + r11.u64;
	// mr r28,r11
	r28.u64 = r11.u64;
	// sth r22,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r22.u16);
	// ble cr6,0x8218a3b0
	if (!cr6.gt) goto loc_8218A3B0;
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8218A37C:
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lhz r8,10(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r6,1(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r5,r7,r23
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + r23.u32);
	// rotlwi r4,r5,4
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 4);
	// mullw r9,r4,r6
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r3,10(r31)
	PPC_STORE_U16(r31.u32 + 10, ctx.r3.u16);
	// bne 0x8218a37c
	if (!cr0.eq) goto loc_8218A37C;
loc_8218A3B0:
	// lhz r3,10(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// bl 0x82130528
	ctx.lr = 0x8218A3B8;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lhz r5,10(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r24,r29
	r11.u64 = r24.u64 + r29.u64;
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
	// add r10,r24,r28
	ctx.r10.u64 = r24.u64 + r28.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// bl 0x823d9890
	ctx.lr = 0x8218A3DC;
	sub_823D9890(ctx, base);
	// mr r27,r21
	r27.u64 = r21.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x8218a4a0
	if (!cr6.gt) goto loc_8218A4A0;
	// mr r28,r21
	r28.u64 = r21.u64;
	// mr r29,r21
	r29.u64 = r21.u64;
loc_8218A3F0:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbzx r8,r10,r23
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r23.u32);
	// rotlwi r7,r8,4
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 4);
	// mullw. r26,r7,r9
	r26.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// beq 0x8218a468
	if (cr0.eq) goto loc_8218A468;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r10,r24,r22
	ctx.r10.u64 = r24.u64 + r22.u64;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r8,r29,r11
	ctx.r8.u64 = r29.u64 + r11.u64;
	// lbz r7,1(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// stbx r7,r9,r27
	PPC_STORE_U8(ctx.r9.u32 + r27.u32, ctx.r7.u8);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r10,r28,r6
	PPC_STORE_U32(r28.u32 + ctx.r6.u32, ctx.r10.u32);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r5,r29,r11
	ctx.r5.u64 = r29.u64 + r11.u64;
	// lwz r4,24(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218a460
	if (cr6.eq) goto loc_8218A460;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// add r9,r29,r11
	ctx.r9.u64 = r29.u64 + r11.u64;
	// lwzx r3,r28,r10
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	// lwz r4,24(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// bl 0x823da950
	ctx.lr = 0x8218A460;
	sub_823DA950(ctx, base);
loc_8218A460:
	// add r22,r26,r22
	r22.u64 = r26.u64 + r22.u64;
	// b 0x8218a478
	goto loc_8218A478;
loc_8218A468:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r21,r28,r11
	PPC_STORE_U32(r28.u32 + r11.u32, r21.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stbx r21,r10,r27
	PPC_STORE_U8(ctx.r10.u32 + r27.u32, r21.u8);
loc_8218A478:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r9,r29,r11
	ctx.r9.u64 = r29.u64 + r11.u64;
	// addi r29,r29,32
	r29.s64 = r29.s64 + 32;
	// cmpw cr6,r27,r25
	cr6.compare<int32_t>(r27.s32, r25.s32, xer);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stwx r8,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r8.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// blt cr6,0x8218a3f0
	if (cr6.lt) goto loc_8218A3F0;
loc_8218A4A0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8218A4A8"))) PPC_WEAK_FUNC(sub_8218A4A8);
PPC_FUNC_IMPL(__imp__sub_8218A4A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8218a4d8
	if (!cr6.gt) goto loc_8218A4D8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8218A4BC:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x8218a4e0
	if (cr6.eq) goto loc_8218A4E0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8218a4bc
	if (cr6.lt) goto loc_8218A4BC;
loc_8218A4D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8218A4E0:
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A4E8"))) PPC_WEAK_FUNC(sub_8218A4E8);
PPC_FUNC_IMPL(__imp__sub_8218A4E8) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8218A4FC;
	sub_821C9790(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-17992
	r11.s64 = r11.s64 + -17992;
	// lwz r9,3072(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 3072);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8218a540
	if (!cr6.gt) goto loc_8218A540;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
loc_8218A518:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// beq cr6,0x8218a554
	if (cr6.eq) goto loc_8218A554;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// beq cr6,0x8218a554
	if (cr6.eq) goto loc_8218A554;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8218a518
	if (cr6.lt) goto loc_8218A518;
loc_8218A540:
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
loc_8218A554:
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A568"))) PPC_WEAK_FUNC(sub_8218A568);
PPC_FUNC_IMPL(__imp__sub_8218A568) {
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
	// bl 0x821c9790
	ctx.lr = 0x8218A588;
	sub_821C9790(ctx, base);
	// lhz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8218a5c8
	if (!cr6.gt) goto loc_8218A5C8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
loc_8218A5A0:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// beq cr6,0x8218a5e0
	if (cr6.eq) goto loc_8218A5E0;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// beq cr6,0x8218a5e0
	if (cr6.eq) goto loc_8218A5E0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8218a5a0
	if (cr6.lt) goto loc_8218A5A0;
loc_8218A5C8:
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
loc_8218A5E0:
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
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

__attribute__((alias("__imp__sub_8218A5F8"))) PPC_WEAK_FUNC(sub_8218A5F8);
PPC_FUNC_IMPL(__imp__sub_8218A5F8) {
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
	ctx.lr = 0x8218A600;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218a698
	if (cr6.eq) goto loc_8218A698;
	// li r31,0
	r31.s64 = 0;
loc_8218A620:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lbzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8218a684
	if (!cr6.eq) goto loc_8218A684;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r11,r31,r10
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8218a65c
	if (cr6.lt) goto loc_8218A65C;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x8218a65c
	if (!cr6.lt) goto loc_8218A65C;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// stwx r11,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r11.u32);
loc_8218A65C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r11,r31,r10
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218a684
	if (cr6.eq) goto loc_8218A684;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218A684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8218A684:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8218a620
	if (cr6.lt) goto loc_8218A620;
loc_8218A698:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218A6A0"))) PPC_WEAK_FUNC(sub_8218A6A0);
PPC_FUNC_IMPL(__imp__sub_8218A6A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r4,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,-24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24);
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// lbz r10,-32(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// stb r4,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r4.u8);
	// lbz r8,-29(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -29);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,-28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A6E0"))) PPC_WEAK_FUNC(sub_8218A6E0);
PPC_FUNC_IMPL(__imp__sub_8218A6E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r11,r5,-1
	r11.s64 = ctx.r5.s64 + -1;
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// rlwinm r4,r11,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r3,r6,24256
	ctx.r3.s64 = ctx.r6.s64 + 24256;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r10,r4,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// lwzx r11,r11,r5
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// lbzx r6,r10,r3
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r3.u32);
	// rotlwi r5,r6,4
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 4);
	// subf r4,r7,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r7.s64;
	// srawi r10,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 2;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8218A72C:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_8218A730:
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addic. r10,r10,-4
	xer.ca = ctx.r10.u32 > 3;
	ctx.r10.s64 = ctx.r10.s64 + -4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8218a730
	if (!cr0.eq) goto loc_8218A730;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// bne 0x8218a72c
	if (!cr0.eq) goto loc_8218A72C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A758"))) PPC_WEAK_FUNC(sub_8218A758);
PPC_FUNC_IMPL(__imp__sub_8218A758) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r11,r5,-1
	r11.s64 = ctx.r5.s64 + -1;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// rlwinm r9,r6,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// addi r10,r10,24272
	ctx.r10.s64 = ctx.r10.s64 + 24272;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stw r6,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A788"))) PPC_WEAK_FUNC(sub_8218A788);
PPC_FUNC_IMPL(__imp__sub_8218A788) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r11,r5,-1
	r11.s64 = ctx.r5.s64 + -1;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A7A8"))) PPC_WEAK_FUNC(sub_8218A7A8);
PPC_FUNC_IMPL(__imp__sub_8218A7A8) {
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
	ctx.lr = 0x8218A7B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8218a810
	if (cr6.eq) goto loc_8218A810;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// li r30,0
	r30.s64 = 0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r31,r11,-32
	r31.s64 = r11.s64 + -32;
	// lbz r11,-29(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -29);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218a810
	if (cr6.eq) goto loc_8218A810;
	// li r29,0
	r29.s64 = 0;
loc_8218A7E4:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x823db730
	ctx.lr = 0x8218A7F4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8218a81c
	if (cr6.eq) goto loc_8218A81C;
	// lbz r11,3(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8218a7e4
	if (cr6.lt) goto loc_8218A7E4;
loc_8218A810:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8218A81C:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218A838"))) PPC_WEAK_FUNC(sub_8218A838);
PPC_FUNC_IMPL(__imp__sub_8218A838) {
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
	// bl 0x8218a7a8
	ctx.lr = 0x8218A848;
	sub_8218A7A8(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A864"))) PPC_WEAK_FUNC(sub_8218A864);
PPC_FUNC_IMPL(__imp__sub_8218A864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218A868"))) PPC_WEAK_FUNC(sub_8218A868);
PPC_FUNC_IMPL(__imp__sub_8218A868) {
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
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x8218a7a8
	ctx.lr = 0x8218A880;
	sub_8218A7A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218a8ac
	if (cr6.eq) goto loc_8218A8AC;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8218a8ac
	if (!cr6.eq) goto loc_8218A8AC;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
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
loc_8218A8AC:
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

__attribute__((alias("__imp__sub_8218A8C4"))) PPC_WEAK_FUNC(sub_8218A8C4);
PPC_FUNC_IMPL(__imp__sub_8218A8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218A8C8"))) PPC_WEAK_FUNC(sub_8218A8C8);
PPC_FUNC_IMPL(__imp__sub_8218A8C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x8218a7a8
	ctx.lr = 0x8218A8E0;
	sub_8218A7A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218a940
	if (cr6.eq) goto loc_8218A940;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8218a90c
	if (!cr6.eq) goto loc_8218A90C;
	// lfs f1,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8218A90C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8218a940
	if (!cr6.eq) goto loc_8218A940;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8218A940:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A958"))) PPC_WEAK_FUNC(sub_8218A958);
PPC_FUNC_IMPL(__imp__sub_8218A958) {
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
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x8218a7a8
	ctx.lr = 0x8218A970;
	sub_8218A7A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218a9c8
	if (cr6.eq) goto loc_8218A9C8;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8218a9a8
	if (!cr6.eq) goto loc_8218A9A8;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
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
loc_8218A9A8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8218a9c8
	if (!cr6.eq) goto loc_8218A9C8;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
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
loc_8218A9C8:
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

__attribute__((alias("__imp__sub_8218A9E0"))) PPC_WEAK_FUNC(sub_8218A9E0);
PPC_FUNC_IMPL(__imp__sub_8218A9E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r10,127
	ctx.r10.s64 = 127;
	// addi r9,r11,24280
	ctx.r9.s64 = r11.s64 + 24280;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r9,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r9.s64;
loc_8218A9F8:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218aa10
	if (cr6.eq) goto loc_8218AA10;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8218a9f8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8218A9F8;
loc_8218AA10:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218AA1C"))) PPC_WEAK_FUNC(sub_8218AA1C);
PPC_FUNC_IMPL(__imp__sub_8218AA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218AA20"))) PPC_WEAK_FUNC(sub_8218AA20);
PPC_FUNC_IMPL(__imp__sub_8218AA20) {
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
	ctx.lr = 0x8218AA28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x8218c8d8
	ctx.lr = 0x8218AA44;
	sub_8218C8D8(ctx, base);
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8218aae8
	if (!cr6.gt) goto loc_8218AAE8;
	// li r31,0
	r31.s64 = 0;
	// mr r26,r11
	r26.u64 = r11.u64;
loc_8218AA58:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// lbzx r11,r11,r31
	r11.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8218aab4
	if (!cr6.eq) goto loc_8218AAB4;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218aa90
	if (cr6.eq) goto loc_8218AA90;
	// lwz r5,16(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
loc_8218AA90:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbz r4,1(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lbz r6,2(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// bl 0x8218cb28
	ctx.lr = 0x8218AAB0;
	sub_8218CB28(ctx, base);
	// b 0x8218aadc
	goto loc_8218AADC;
loc_8218AAB4:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lbzx r6,r8,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// lwzx r5,r7,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// bl 0x8218cce0
	ctx.lr = 0x8218AADC;
	sub_8218CCE0(ctx, base);
loc_8218AADC:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// bne 0x8218aa58
	if (!cr0.eq) goto loc_8218AA58;
loc_8218AAE8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8218AAF0"))) PPC_WEAK_FUNC(sub_8218AAF0);
PPC_FUNC_IMPL(__imp__sub_8218AAF0) {
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
	ctx.lr = 0x8218AAF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lhz r31,8(r27)
	r31.u64 = PPC_LOAD_U16(r27.u32 + 8);
	// bl 0x8218c900
	ctx.lr = 0x8218AB18;
	sub_8218C900(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218ab9c
	if (!cr6.gt) goto loc_8218AB9C;
	// li r28,0
	r28.s64 = 0;
loc_8218AB24:
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// add r10,r11,r28
	ctx.r10.u64 = r11.u64 + r28.u64;
	// lbzx r11,r11,r28
	r11.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r6,r9,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8218ab80
	if (!cr6.eq) goto loc_8218AB80;
	// lwzx r9,r8,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8218ab5c
	if (cr6.eq) goto loc_8218AB5C;
	// lwz r5,16(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
loc_8218AB5C:
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lbz r6,2(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// bl 0x8218cbd0
	ctx.lr = 0x8218AB7C;
	sub_8218CBD0(ctx, base);
	// b 0x8218ab90
	goto loc_8218AB90;
loc_8218AB80:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lwzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x8218ccf8
	ctx.lr = 0x8218AB90;
	sub_8218CCF8(ctx, base);
loc_8218AB90:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// bne 0x8218ab24
	if (!cr0.eq) goto loc_8218AB24;
loc_8218AB9C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8218ABA4"))) PPC_WEAK_FUNC(sub_8218ABA4);
PPC_FUNC_IMPL(__imp__sub_8218ABA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218ABA8"))) PPC_WEAK_FUNC(sub_8218ABA8);
PPC_FUNC_IMPL(__imp__sub_8218ABA8) {
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
	ctx.lr = 0x8218ABB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8218ac50
	if (!cr6.gt) goto loc_8218AC50;
	// li r31,0
	r31.s64 = 0;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_8218ABD4:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// lbzx r11,r11,r31
	r11.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8218ac1c
	if (!cr6.eq) goto loc_8218AC1C;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r11,r8,r10
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218ac0c
	if (cr6.eq) goto loc_8218AC0C;
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
loc_8218AC0C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lbz r4,1(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// bl 0x8218cc08
	ctx.lr = 0x8218AC18;
	sub_8218CC08(ctx, base);
	// b 0x8218ac44
	goto loc_8218AC44;
loc_8218AC1C:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lbzx r6,r8,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// lwzx r5,r7,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// bl 0x8218cce0
	ctx.lr = 0x8218AC44;
	sub_8218CCE0(ctx, base);
loc_8218AC44:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// bne 0x8218abd4
	if (!cr0.eq) goto loc_8218ABD4;
loc_8218AC50:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8218AC58"))) PPC_WEAK_FUNC(sub_8218AC58);
PPC_FUNC_IMPL(__imp__sub_8218AC58) {
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
	ctx.lr = 0x8218AC60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8218ace8
	if (!cr6.gt) goto loc_8218ACE8;
	// li r30,0
	r30.s64 = 0;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_8218AC84:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lbzx r11,r11,r30
	r11.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r6,r9,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8218accc
	if (!cr6.eq) goto loc_8218ACCC;
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218acbc
	if (cr6.eq) goto loc_8218ACBC;
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
loc_8218ACBC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lbz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// bl 0x8218cc40
	ctx.lr = 0x8218ACC8;
	sub_8218CC40(ctx, base);
	// b 0x8218acdc
	goto loc_8218ACDC;
loc_8218ACCC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lbz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lwzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x8218ccf8
	ctx.lr = 0x8218ACDC;
	sub_8218CCF8(ctx, base);
loc_8218ACDC:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// bne 0x8218ac84
	if (!cr0.eq) goto loc_8218AC84;
loc_8218ACE8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8218ACF0"))) PPC_WEAK_FUNC(sub_8218ACF0);
PPC_FUNC_IMPL(__imp__sub_8218ACF0) {
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
	ctx.lr = 0x8218ACF8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r31,-21092(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -21092);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x8218aba8
	ctx.lr = 0x8218AD24;
	sub_8218ABA8(ctx, base);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8218ac58
	ctx.lr = 0x8218AD40;
	sub_8218AC58(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218AD48"))) PPC_WEAK_FUNC(sub_8218AD48);
PPC_FUNC_IMPL(__imp__sub_8218AD48) {
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
	// lbz r10,-21095(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -21095);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218ad90
	if (cr6.eq) goto loc_8218AD90;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lwz r3,-21092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -21092);
	// bl 0x82189fb8
	ctx.lr = 0x8218AD74;
	sub_82189FB8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21092(r31)
	PPC_STORE_U32(r31.u32 + -21092, r11.u32);
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
loc_8218AD90:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21092(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21092, r11.u32);
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

__attribute__((alias("__imp__sub_8218ADB0"))) PPC_WEAK_FUNC(sub_8218ADB0);
PPC_FUNC_IMPL(__imp__sub_8218ADB0) {
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
	ctx.lr = 0x8218ADB8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r30,28(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8218ae00
	if (!cr6.gt) goto loc_8218AE00;
	// li r29,0
	r29.s64 = 0;
loc_8218ADE0:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8218cc70
	ctx.lr = 0x8218ADF4;
	sub_8218CC70(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bne 0x8218ade0
	if (!cr0.eq) goto loc_8218ADE0;
loc_8218AE00:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8218aa20
	ctx.lr = 0x8218AE20;
	sub_8218AA20(ctx, base);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8218aaf0
	ctx.lr = 0x8218AE40;
	sub_8218AAF0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8218AE48"))) PPC_WEAK_FUNC(sub_8218AE48);
PPC_FUNC_IMPL(__imp__sub_8218AE48) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-27780(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27780);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218aee0
	if (!cr6.eq) goto loc_8218AEE0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8218aee0
	if (cr6.eq) goto loc_8218AEE0;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// rlwinm r10,r3,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r11,r11,-17992
	r11.s64 = r11.s64 + -17992;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// lhz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + -4);
	// cmplwi cr6,r3,65535
	cr6.compare<uint32_t>(ctx.r3.u32, 65535, xer);
	// beq cr6,0x8218aeb4
	if (cr6.eq) goto loc_8218AEB4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// beq cr6,0x8218aea4
	if (cr6.eq) goto loc_8218AEA4;
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
loc_8218AEA4:
	// lwz r7,-8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// lbz r6,-30(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + -30);
	// lbz r4,-32(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + -32);
	// bl 0x8218cb10
	ctx.lr = 0x8218AEB4;
	sub_8218CB10(ctx, base);
loc_8218AEB4:
	// lhz r3,-2(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + -2);
	// cmplwi cr6,r3,65535
	cr6.compare<uint32_t>(ctx.r3.u32, 65535, xer);
	// beq cr6,0x8218aee0
	if (cr6.eq) goto loc_8218AEE0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// beq cr6,0x8218aed0
	if (cr6.eq) goto loc_8218AED0;
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
loc_8218AED0:
	// lwz r7,-8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// lbz r6,-30(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + -30);
	// lbz r4,-32(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + -32);
	// bl 0x8218cbf8
	ctx.lr = 0x8218AEE0;
	sub_8218CBF8(ctx, base);
loc_8218AEE0:
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

__attribute__((alias("__imp__sub_8218AEF8"))) PPC_WEAK_FUNC(sub_8218AEF8);
PPC_FUNC_IMPL(__imp__sub_8218AEF8) {
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
	ctx.lr = 0x8218AF00;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8218af5c
	if (cr6.eq) goto loc_8218AF5C;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r10,r10,-17992
	ctx.r10.s64 = ctx.r10.s64 + -17992;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// lhz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + -4);
	// cmplwi cr6,r3,65535
	cr6.compare<uint32_t>(ctx.r3.u32, 65535, xer);
	// beq cr6,0x8218af40
	if (cr6.eq) goto loc_8218AF40;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lbz r4,-32(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + -32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8218c928
	ctx.lr = 0x8218AF40;
	sub_8218C928(ctx, base);
loc_8218AF40:
	// lhz r3,-2(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + -2);
	// cmplwi cr6,r3,65535
	cr6.compare<uint32_t>(ctx.r3.u32, 65535, xer);
	// beq cr6,0x8218af5c
	if (cr6.eq) goto loc_8218AF5C;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lbz r4,-32(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + -32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8218cb50
	ctx.lr = 0x8218AF5C;
	sub_8218CB50(ctx, base);
loc_8218AF5C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218AF64"))) PPC_WEAK_FUNC(sub_8218AF64);
PPC_FUNC_IMPL(__imp__sub_8218AF64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218AF68"))) PPC_WEAK_FUNC(sub_8218AF68);
PPC_FUNC_IMPL(__imp__sub_8218AF68) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,12
	ctx.r9.s64 = 12;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r4,r11,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r11,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r11.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218AFB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218afe8
	if (!cr6.gt) goto loc_8218AFE8;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8218AFCC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8218afdc
	if (cr0.eq) goto loc_8218AFDC;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
loc_8218AFDC:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8218afcc
	if (!cr0.eq) goto loc_8218AFCC;
loc_8218AFE8:
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

__attribute__((alias("__imp__sub_8218B000"))) PPC_WEAK_FUNC(sub_8218B000);
PPC_FUNC_IMPL(__imp__sub_8218B000) {
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
	ctx.lr = 0x8218B008;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B01C;
	sub_821BE4F0(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B028;
	sub_821BE4F0(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B034;
	sub_821BE4F0(ctx, base);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// rlwinm r4,r30,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8218B070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8218b0bc
	if (!cr6.gt) goto loc_8218B0BC;
loc_8218B07C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821be710
	ctx.lr = 0x8218B0A4;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r29,4
	ctx.r4.s64 = r29.s64 + 4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be710
	ctx.lr = 0x8218B0B4;
	sub_821BE710(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8218b07c
	if (!cr0.eq) goto loc_8218B07C;
loc_8218B0BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218B0C4"))) PPC_WEAK_FUNC(sub_8218B0C4);
PPC_FUNC_IMPL(__imp__sub_8218B0C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B0C8"))) PPC_WEAK_FUNC(sub_8218B0C8);
PPC_FUNC_IMPL(__imp__sub_8218B0C8) {
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
	ctx.lr = 0x8218B0D0;
	// stwu r1,-944(r1)
	ea = -944 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B0E4;
	sub_821BE4F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// bl 0x821be4f0
	ctx.lr = 0x8218B0F4;
	sub_821BE4F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,1(r31)
	PPC_STORE_U8(r31.u32 + 1, ctx.r10.u8);
	// bne cr6,0x8218b118
	if (!cr6.eq) goto loc_8218B118;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// beq cr6,0x8218b118
	if (cr6.eq) goto loc_8218B118;
	// li r11,1
	r11.s64 = 1;
	// stb r11,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r11.u8);
loc_8218B118:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B120;
	sub_821BE4F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be250
	ctx.lr = 0x8218B130;
	sub_821BE250(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// bl 0x821d2a58
	ctx.lr = 0x8218B13C;
	sub_821D2A58(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821c9790
	ctx.lr = 0x8218B148;
	sub_821C9790(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B154;
	sub_821BE4F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be250
	ctx.lr = 0x8218B164;
	sub_821BE250(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2a58
	ctx.lr = 0x8218B170;
	sub_821D2A58(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821c9790
	ctx.lr = 0x8218B17C;
	sub_821C9790(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B188;
	sub_821BE4F0(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stb r3,3(r31)
	PPC_STORE_U8(r31.u32 + 3, ctx.r3.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218b1e8
	if (cr6.eq) goto loc_8218B1E8;
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addi r28,r10,-4
	r28.s64 = ctx.r10.s64 + -4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r30,r11,-1
	xer.ca = r11.u32 > 0;
	r30.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// blt 0x8218b1e0
	if (cr0.lt) goto loc_8218B1E0;
loc_8218B1B8:
	// addi r29,r29,-12
	r29.s64 = r29.s64 + -12;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8218b1d0
	if (!cr6.eq) goto loc_8218B1D0;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8218B1D0;
	sub_82130588(ctx, base);
loc_8218B1D0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8218B1D8;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8218b1b8
	if (!cr0.lt) goto loc_8218B1B8;
loc_8218B1E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x8218B1E8;
	sub_82130588(ctx, base);
loc_8218B1E8:
	// lis r11,5461
	r11.s64 = 357892096;
	// lbz r29,3(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 3);
	// li r23,-1
	r23.s64 = -1;
	// ori r10,r11,21845
	ctx.r10.u64 = r11.u64 | 21845;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8218b21c
	if (cr6.gt) goto loc_8218B21C;
	// rlwinm r11,r29,1,0,30
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-5
	ctx.r10.s64 = -5;
	// add r9,r29,r11
	ctx.r9.u64 = r29.u64 + r11.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// ble cr6,0x8218b220
	if (!cr6.gt) goto loc_8218B220;
loc_8218B21C:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
loc_8218B220:
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r24,12
	r24.s64 = 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r24,r25
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218B244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r30,0
	r30.s64 = 0;
	// beq cr6,0x8218b284
	if (cr6.eq) goto loc_8218B284;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// addic. r10,r29,-1
	xer.ca = r29.u32 > 0;
	ctx.r10.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// blt 0x8218b27c
	if (cr0.lt) goto loc_8218B27C;
loc_8218B264:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x8218b264
	if (!cr0.lt) goto loc_8218B264;
loc_8218B27C:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// b 0x8218b288
	goto loc_8218B288;
loc_8218B284:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8218B288:
	// lbz r10,3(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 3);
	// mr r27,r30
	r27.u64 = r30.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218b328
	if (cr6.eq) goto loc_8218B328;
	// mr r28,r30
	r28.u64 = r30.u64;
loc_8218B2A0:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// add r29,r28,r11
	r29.u64 = r28.u64 + r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B2B0;
	sub_821BE4F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,592
	ctx.r4.s64 = ctx.r1.s64 + 592;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be250
	ctx.lr = 0x8218B2C0;
	sub_821BE250(ctx, base);
	// addi r4,r1,592
	ctx.r4.s64 = ctx.r1.s64 + 592;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2a58
	ctx.lr = 0x8218B2CC;
	sub_821D2A58(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B2D4;
	sub_821BE4F0(ctx, base);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bne cr6,0x8218b308
	if (!cr6.eq) goto loc_8218B308;
	// bl 0x821be4f0
	ctx.lr = 0x8218B2E8;
	sub_821BE4F0(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// bl 0x82130528
	ctx.lr = 0x8218B2F0;
	sub_82130528(ctx, base);
	// stw r3,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be250
	ctx.lr = 0x8218B304;
	sub_821BE250(ctx, base);
	// b 0x8218b314
	goto loc_8218B314;
loc_8218B308:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r29,8
	ctx.r4.s64 = r29.s64 + 8;
	// bl 0x821be710
	ctx.lr = 0x8218B314;
	sub_821BE710(ctx, base);
loc_8218B314:
	// lbz r11,3(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8218b2a0
	if (cr6.lt) goto loc_8218B2A0;
loc_8218B328:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218B330;
	sub_821BE4F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stb r11,2(r31)
	PPC_STORE_U8(r31.u32 + 2, r11.u8);
	// bl 0x82130588
	ctx.lr = 0x8218B340;
	sub_82130588(ctx, base);
	// lbz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// cmplwi cr6,r9,6
	cr6.compare<uint32_t>(ctx.r9.u32, 6, xer);
	// bne cr6,0x8218b3d0
	if (!cr6.eq) goto loc_8218B3D0;
	// lbz r11,2(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218b4b4
	if (cr6.eq) goto loc_8218B4B4;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x8218b37c
	if (!cr6.gt) goto loc_8218B37C;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
loc_8218B37C:
	// lwzx r3,r24,r25
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218B398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// rotlwi r5,r9,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// bl 0x823d9890
	ctx.lr = 0x8218B3AC;
	sub_823D9890(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lbz r5,2(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821be710
	ctx.lr = 0x8218B3BC;
	sub_821BE710(ctx, base);
	// lbz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// rlwinm r7,r8,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// stb r7,2(r31)
	PPC_STORE_U8(r31.u32 + 2, ctx.r7.u8);
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9230
	return;
loc_8218B3D0:
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// lbz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// addi r7,r8,24256
	ctx.r7.s64 = ctx.r8.s64 + 24256;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lbzx r6,r9,r7
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
	// mullw r5,r6,r11
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(r11.s32);
	// rlwinm r29,r5,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// beq cr6,0x8218b4b4
	if (cr6.eq) goto loc_8218B4B4;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// rotlwi r8,r29,1
	ctx.r8.u64 = __builtin_rotateleft32(r29.u32, 1);
	// lis r7,16383
	ctx.r7.s64 = 1073676288;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// ori r4,r7,65535
	ctx.r4.u64 = ctx.r7.u64 | 65535;
	// andc r6,r11,r9
	ctx.r6.u64 = r11.u64 & ~ctx.r9.u64;
	// andc r5,r11,r8
	ctx.r5.u64 = r11.u64 & ~ctx.r8.u64;
	// cmplw cr6,r29,r4
	cr6.compare<uint32_t>(r29.u32, ctx.r4.u32, xer);
	// divw r27,r10,r11
	r27.s32 = ctx.r10.s32 / r11.s32;
	// twllei r11,0
	// twlgei r6,-1
	// divw r28,r29,r11
	r28.s32 = r29.s32 / r11.s32;
	// twllei r11,0
	// twlgei r5,-1
	// rlwinm r4,r29,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8218b43c
	if (!cr6.gt) goto loc_8218B43C;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
loc_8218B43C:
	// lwzx r3,r24,r25
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218B458;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// srawi r9,r29,2
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x3) != 0);
	ctx.r9.s64 = r29.s32 >> 2;
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r9,2(r31)
	PPC_STORE_U8(r31.u32 + 2, ctx.r9.u8);
	// lbz r7,1(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// mullw r6,r7,r28
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r28.s32);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823d9890
	ctx.lr = 0x8218B47C;
	sub_823D9890(ctx, base);
	// lbz r5,1(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// lwz r29,24(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8218b4b4
	if (cr6.eq) goto loc_8218B4B4;
	// rlwinm r28,r28,2,0,29
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
loc_8218B490:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be710
	ctx.lr = 0x8218B4A0;
	sub_821BE710(ctx, base);
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// add r29,r28,r29
	r29.u64 = r28.u64 + r29.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8218b490
	if (cr6.lt) goto loc_8218B490;
loc_8218B4B4:
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8218B4BC"))) PPC_WEAK_FUNC(sub_8218B4BC);
PPC_FUNC_IMPL(__imp__sub_8218B4BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B4C0"))) PPC_WEAK_FUNC(sub_8218B4C0);
PPC_FUNC_IMPL(__imp__sub_8218B4C0) {
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
	ctx.lr = 0x8218B4C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r28,0(r4)
	r28.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r11,12
	r11.s64 = 12;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r31,4(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r30,r3,4
	r30.s64 = ctx.r3.s64 + 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// lhz r27,4(r29)
	r27.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r5,16
	ctx.r5.s64 = 16;
	// sth r9,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r9.u16);
	// rlwinm r4,r28,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r28,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r28.u16);
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8218B514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x8218b5c4
	if (!cr6.gt) goto loc_8218B5C4;
	// li r6,2
	ctx.r6.s64 = 2;
loc_8218B528:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8218b5b4
	if (!cr6.gt) goto loc_8218B5B4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
loc_8218B540:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8218b560
	if (cr6.eq) goto loc_8218B560;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r10,r27
	cr6.compare<int32_t>(ctx.r10.s32, r27.s32, xer);
	// blt cr6,0x8218b540
	if (cr6.lt) goto loc_8218B540;
	// b 0x8218b5b4
	goto loc_8218B5B4;
loc_8218B560:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// rotlwi r11,r11,1
	r11.u64 = __builtin_rotateleft32(r11.u32, 1);
	// sth r5,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r5.u16);
	// lbz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// add r8,r11,r9
	ctx.r8.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r4,2
	cr6.compare<uint32_t>(ctx.r4.u32, 2, xer);
	// bne cr6,0x8218b59c
	if (!cr6.eq) goto loc_8218B59C;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lbzx r5,r11,r9
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r5,7
	cr6.compare<uint32_t>(ctx.r5.u32, 7, xer);
	// bne cr6,0x8218b59c
	if (!cr6.eq) goto loc_8218B59C;
	// stbx r6,r11,r9
	PPC_STORE_U8(r11.u32 + ctx.r9.u32, ctx.r6.u8);
loc_8218B59C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r9,r10,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lbzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stb r3,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r3.u8);
	// stb r7,1(r8)
	PPC_STORE_U8(ctx.r8.u32 + 1, ctx.r7.u8);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
loc_8218B5B4:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpw cr6,r7,r28
	cr6.compare<int32_t>(ctx.r7.s32, r28.s32, xer);
	// blt cr6,0x8218b528
	if (cr6.lt) goto loc_8218B528;
loc_8218B5C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8218B5CC"))) PPC_WEAK_FUNC(sub_8218B5CC);
PPC_FUNC_IMPL(__imp__sub_8218B5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B5D0"))) PPC_WEAK_FUNC(sub_8218B5D0);
PPC_FUNC_IMPL(__imp__sub_8218B5D0) {
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
	ctx.lr = 0x8218B5D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218b67c
	if (cr6.eq) goto loc_8218B67C;
	// li r25,0
	r25.s64 = 0;
loc_8218B5F4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// add r27,r25,r11
	r27.u64 = r25.u64 + r11.u64;
	// lhz r11,12(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218b668
	if (cr6.eq) goto loc_8218B668;
	// addi r26,r28,8
	r26.s64 = r28.s64 + 8;
	// li r30,0
	r30.s64 = 0;
loc_8218B614:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8218b4c0
	ctx.lr = 0x8218B638;
	sub_8218B4C0(ctx, base);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8218b4c0
	ctx.lr = 0x8218B654;
	sub_8218B4C0(ctx, base);
	// lhz r8,12(r27)
	ctx.r8.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x8218b614
	if (cr6.lt) goto loc_8218B614;
loc_8218B668:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,16
	r25.s64 = r25.s64 + 16;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x8218b5f4
	if (cr6.lt) goto loc_8218B5F4;
loc_8218B67C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8218B684"))) PPC_WEAK_FUNC(sub_8218B684);
PPC_FUNC_IMPL(__imp__sub_8218B684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B688"))) PPC_WEAK_FUNC(sub_8218B688);
PPC_FUNC_IMPL(__imp__sub_8218B688) {
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
	// bl 0x821c9790
	ctx.lr = 0x8218B6A8;
	sub_821C9790(ctx, base);
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8218b6d8
	if (!cr6.gt) goto loc_8218B6D8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_8218B6BC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// beq cr6,0x8218b6f0
	if (cr6.eq) goto loc_8218B6F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8218b6bc
	if (cr6.lt) goto loc_8218B6BC;
loc_8218B6D8:
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
loc_8218B6F0:
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
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

__attribute__((alias("__imp__sub_8218B708"))) PPC_WEAK_FUNC(sub_8218B708);
PPC_FUNC_IMPL(__imp__sub_8218B708) {
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
	ctx.lr = 0x8218B710;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218b73c
	if (cr6.eq) goto loc_8218B73C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8217d890
	ctx.lr = 0x8218B730;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_8218B73C:
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218b75c
	if (cr6.eq) goto loc_8218B75C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8217d890
	ctx.lr = 0x8218B750;
	sub_8217D890(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
loc_8218B75C:
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218b77c
	if (cr6.eq) goto loc_8218B77C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8217d890
	ctx.lr = 0x8218B770;
	sub_8217D890(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
loc_8218B77C:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821899f8
	ctx.lr = 0x8218B784;
	sub_821899F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// bne cr6,0x8218b7a0
	if (!cr6.eq) goto loc_8218B7A0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r4,8(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// addi r3,r11,-18832
	ctx.r3.s64 = r11.s64 + -18832;
	// bl 0x821bd618
	ctx.lr = 0x8218B7A0;
	sub_821BD618(ctx, base);
loc_8218B7A0:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r26,0
	r26.s64 = 0;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lhz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x8218b8cc
	if (!cr6.eq) goto loc_8218B8CC;
	// li r26,1
	r26.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8218b8cc
	if (!cr6.gt) goto loc_8218B8CC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r30,0
	r30.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// addi r25,r11,-18876
	r25.s64 = r11.s64 + -18876;
	// addi r24,r10,-18916
	r24.s64 = ctx.r10.s64 + -18916;
loc_8218B7E0:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218b8cc
	if (cr6.eq) goto loc_8218B8CC;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lbzx r7,r29,r10
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + ctx.r10.u32);
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lwzx r6,r27,r8
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + ctx.r8.u32);
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lbzx r11,r11,r30
	r11.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// addi r3,r11,-6
	ctx.r3.s64 = r11.s64 + -6;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cntlzw r8,r3
	ctx.r8.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// subf r7,r11,r6
	ctx.r7.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// subf r4,r6,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r6.s64;
	// rlwinm r28,r5,27,31,31
	r28.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218b854
	if (cr6.eq) goto loc_8218B854;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// li r8,1
	ctx.r8.s64 = 1;
	// bne cr6,0x8218b858
	if (!cr6.eq) goto loc_8218B858;
loc_8218B854:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8218B858:
	// clrlwi r26,r8,24
	r26.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218b880
	if (!cr6.eq) goto loc_8218B880;
	// lwz r3,72(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// lwz r22,4(r10)
	r22.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x821c9ab0
	ctx.lr = 0x8218B870;
	sub_821C9AB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x8218B880;
	sub_82130000(ctx, base);
loc_8218B880:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218b8b4
	if (!cr6.eq) goto loc_8218B8B4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,72(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// lwz r28,4(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x821c9ab0
	ctx.lr = 0x8218B8A4;
	sub_821C9AB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x8218B8B4;
	sub_82130000(ctx, base);
loc_8218B8B4:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8218b7e0
	if (cr6.lt) goto loc_8218B7E0;
loc_8218B8CC:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218b928
	if (!cr6.eq) goto loc_8218B928;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r11,-14884(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14884);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-14884(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14884, r11.u32);
	// cmpwi cr6,r11,25
	cr6.compare<int32_t>(r11.s32, 25, xer);
	// bge cr6,0x8218b924
	if (!cr6.lt) goto loc_8218B924;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,8(r23)
	r30.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// lhz r31,8(r31)
	r31.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lhz r29,12(r11)
	r29.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// bl 0x821c9ab0
	ctx.lr = 0x8218B908;
	sub_821C9AB0(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r10,-19104
	ctx.r3.s64 = ctx.r10.s64 + -19104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x8218B924;
	sub_82130000(ctx, base);
loc_8218B924:
	// b 0x8218b924
	goto loc_8218B924;
loc_8218B928:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r26,0
	r26.s64 = 0;
	// lbz r11,-21096(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + -21096);
	// stb r11,-21096(r10)
	PPC_STORE_U8(ctx.r10.u32 + -21096, r11.u8);
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8218ba14
	if (cr6.eq) goto loc_8218BA14;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r27,0
	r27.s64 = 0;
	// lis r24,-32124
	r24.s64 = -2105278464;
	// addi r25,r11,-26560
	r25.s64 = r11.s64 + -26560;
loc_8218B954:
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r30,r27,r28
	r30.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8218b9bc
	if (cr6.eq) goto loc_8218B9BC;
	// lwz r29,0(r23)
	r29.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d828
	ctx.lr = 0x8218B974;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8218b99c
	if (cr6.eq) goto loc_8218B99C;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x8218b9b0
	goto loc_8218B9B0;
loc_8218B99C:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821d2378
	ctx.lr = 0x8218B9AC;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_8218B9B0:
	// lwzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, r11.u32);
loc_8218B9BC:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lbzx r10,r26,r11
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8218ba00
	if (!cr6.eq) goto loc_8218BA00;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r5,r27,r11
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8218ba00
	if (cr6.eq) goto loc_8218BA00;
	// lhz r11,12(r5)
	r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 12);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8218ba00
	if (!cr6.eq) goto loc_8218BA00;
	// lwz r3,-25232(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -25232);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218BA00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8218BA00:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8218b954
	if (cr6.lt) goto loc_8218B954;
loc_8218BA14:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8218BA20"))) PPC_WEAK_FUNC(sub_8218BA20);
PPC_FUNC_IMPL(__imp__sub_8218BA20) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x8218ba88
	if (cr6.eq) goto loc_8218BA88;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// rlwinm r10,r3,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r11,r11,-17992
	r11.s64 = r11.s64 + -17992;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// lhz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + -4);
	// cmplwi cr6,r3,65535
	cr6.compare<uint32_t>(ctx.r3.u32, 65535, xer);
	// beq cr6,0x8218ba6c
	if (cr6.eq) goto loc_8218BA6C;
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r4,-32(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + -32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8218c928
	ctx.lr = 0x8218BA6C;
	sub_8218C928(ctx, base);
loc_8218BA6C:
	// lhz r3,-2(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + -2);
	// cmplwi cr6,r3,65535
	cr6.compare<uint32_t>(ctx.r3.u32, 65535, xer);
	// beq cr6,0x8218ba88
	if (cr6.eq) goto loc_8218BA88;
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r4,-32(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + -32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8218cb50
	ctx.lr = 0x8218BA88;
	sub_8218CB50(ctx, base);
loc_8218BA88:
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

__attribute__((alias("__imp__sub_8218BA9C"))) PPC_WEAK_FUNC(sub_8218BA9C);
PPC_FUNC_IMPL(__imp__sub_8218BA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218BAA0"))) PPC_WEAK_FUNC(sub_8218BAA0);
PPC_FUNC_IMPL(__imp__sub_8218BAA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r4,-21076(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21076, ctx.r4.u32);
	// beq cr6,0x8218baec
	if (cr6.eq) goto loc_8218BAEC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r8,r4,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r9,-21080(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21080);
	// lwz r3,-8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stw r3,-21080(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21080, ctx.r3.u32);
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// addi r6,r11,48
	ctx.r6.s64 = r11.s64 + 48;
	// addi r5,r11,24
	ctx.r5.s64 = r11.s64 + 24;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// b 0x8218adb0
	sub_8218ADB0(ctx, base);
	return;
loc_8218BAEC:
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-21080(r9)
	PPC_STORE_U32(ctx.r9.u32 + -21080, r11.u32);
	// stw r10,-21092(r8)
	PPC_STORE_U32(ctx.r8.u32 + -21092, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218BB08"))) PPC_WEAK_FUNC(sub_8218BB08);
PPC_FUNC_IMPL(__imp__sub_8218BB08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// rlwinm r10,r4,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r11,-21088(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21088);
	// addi r7,r3,8
	ctx.r7.s64 = ctx.r3.s64 + 8;
	// stw r4,-21100(r9)
	PPC_STORE_U32(ctx.r9.u32 + -21100, ctx.r4.u32);
	// addi r5,r3,24
	ctx.r5.s64 = ctx.r3.s64 + 24;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// stw r3,-21092(r8)
	PPC_STORE_U32(ctx.r8.u32 + -21092, ctx.r3.u32);
	// b 0x8218adb0
	sub_8218ADB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218BB40"))) PPC_WEAK_FUNC(sub_8218BB40);
PPC_FUNC_IMPL(__imp__sub_8218BB40) {
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
	ctx.lr = 0x8218BB48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218bbac
	if (cr6.eq) goto loc_8218BBAC;
	// lis r11,0
	r11.s64 = 0;
	// ori r29,r11,65535
	r29.u64 = r11.u64 | 65535;
loc_8218BB64:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r11,r8,4,12,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFF0;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218bb90
	if (cr6.eq) goto loc_8218BB90;
	// bl 0x824221d8
	ctx.lr = 0x8218BB90;
	sub_824221D8(ctx, base);
loc_8218BB90:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8218BB98;
	sub_82130588(ctx, base);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821d2aa0
	ctx.lr = 0x8218BBA0;
	sub_821D2AA0(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218bb64
	if (!cr6.eq) goto loc_8218BB64;
loc_8218BBAC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8218BBB4;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218BBC8"))) PPC_WEAK_FUNC(sub_8218BBC8);
PPC_FUNC_IMPL(__imp__sub_8218BBC8) {
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
	ctx.lr = 0x8218BBD0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218bc34
	if (cr6.eq) goto loc_8218BC34;
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addi r29,r10,-4
	r29.s64 = ctx.r10.s64 + -4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// blt 0x8218bc2c
	if (cr0.lt) goto loc_8218BC2C;
loc_8218BC04:
	// addi r30,r30,-12
	r30.s64 = r30.s64 + -12;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8218bc1c
	if (!cr6.eq) goto loc_8218BC1C;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8218BC1C;
	sub_82130588(ctx, base);
loc_8218BC1C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8218BC24;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8218bc04
	if (!cr0.lt) goto loc_8218BC04;
loc_8218BC2C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8218BC34;
	sub_82130588(ctx, base);
loc_8218BC34:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,24(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// addi r11,r11,-21072
	r11.s64 = r11.s64 + -21072;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x8218bc58
	if (cr6.lt) goto loc_8218BC58;
	// addi r11,r11,3072
	r11.s64 = r11.s64 + 3072;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8218bc5c
	if (cr6.lt) goto loc_8218BC5C;
loc_8218BC58:
	// li r11,0
	r11.s64 = 0;
loc_8218BC5C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218bc6c
	if (!cr6.eq) goto loc_8218BC6C;
	// bl 0x82130588
	ctx.lr = 0x8218BC6C;
	sub_82130588(ctx, base);
loc_8218BC6C:
	// addi r3,r28,8
	ctx.r3.s64 = r28.s64 + 8;
	// bl 0x821d2aa0
	ctx.lr = 0x8218BC74;
	sub_821D2AA0(ctx, base);
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x8218BC7C;
	sub_821D2AA0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218BC84"))) PPC_WEAK_FUNC(sub_8218BC84);
PPC_FUNC_IMPL(__imp__sub_8218BC84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218BC88"))) PPC_WEAK_FUNC(sub_8218BC88);
PPC_FUNC_IMPL(__imp__sub_8218BC88) {
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
	// addi r31,r3,3072
	r31.s64 = ctx.r3.s64 + 3072;
	// li r30,95
	r30.s64 = 95;
loc_8218BCA4:
	// addi r31,r31,-32
	r31.s64 = r31.s64 + -32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218bbc8
	ctx.lr = 0x8218BCB0;
	sub_8218BBC8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8218bca4
	if (!cr0.lt) goto loc_8218BCA4;
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

__attribute__((alias("__imp__sub_8218BCD0"))) PPC_WEAK_FUNC(sub_8218BCD0);
PPC_FUNC_IMPL(__imp__sub_8218BCD0) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,12
	ctx.r9.s64 = 12;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r4,r11,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r11,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r11.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218BD20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218bd70
	if (!cr6.gt) goto loc_8218BD70;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8218BD34:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add. r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8218bd64
	if (cr0.eq) goto loc_8218BD64;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// sth r10,10(r11)
	PPC_STORE_U16(r11.u32 + 10, ctx.r10.u16);
	// sth r10,8(r11)
	PPC_STORE_U16(r11.u32 + 8, ctx.r10.u16);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// sth r10,22(r11)
	PPC_STORE_U16(r11.u32 + 22, ctx.r10.u16);
	// sth r10,20(r11)
	PPC_STORE_U16(r11.u32 + 20, ctx.r10.u16);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// sth r10,30(r11)
	PPC_STORE_U16(r11.u32 + 30, ctx.r10.u16);
	// sth r10,28(r11)
	PPC_STORE_U16(r11.u32 + 28, ctx.r10.u16);
loc_8218BD64:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// bne 0x8218bd34
	if (!cr0.eq) goto loc_8218BD34;
loc_8218BD70:
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

__attribute__((alias("__imp__sub_8218BD88"))) PPC_WEAK_FUNC(sub_8218BD88);
PPC_FUNC_IMPL(__imp__sub_8218BD88) {
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218bde0
	if (cr6.eq) goto loc_8218BDE0;
	// lis r11,0
	r11.s64 = 0;
	// ori r30,r11,65535
	r30.u64 = r11.u64 | 65535;
loc_8218BDB4:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r8,5,11,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0x1FFFE0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8218bbc8
	ctx.lr = 0x8218BDD4;
	sub_8218BBC8(ctx, base);
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8218bdb4
	if (!cr6.eq) goto loc_8218BDB4;
loc_8218BDE0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8218BDE8;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
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

__attribute__((alias("__imp__sub_8218BE0C"))) PPC_WEAK_FUNC(sub_8218BE0C);
PPC_FUNC_IMPL(__imp__sub_8218BE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218BE10"))) PPC_WEAK_FUNC(sub_8218BE10);
PPC_FUNC_IMPL(__imp__sub_8218BE10) {
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
	ctx.lr = 0x8218BE18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218bf08
	if (cr6.eq) goto loc_8218BF08;
	// lis r11,0
	r11.s64 = 0;
	// ori r29,r11,65535
	r29.u64 = r11.u64 | 65535;
loc_8218BE38:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r11,r8,5,11,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0x1FFFE0;
	// sth r8,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r8.u16);
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// addi r31,r28,24
	r31.s64 = r28.s64 + 24;
	// lhz r7,28(r28)
	ctx.r7.u64 = PPC_LOAD_U16(r28.u32 + 28);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8218be7c
	if (cr6.eq) goto loc_8218BE7C;
loc_8218BE64:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8218be64
	if (!cr6.eq) goto loc_8218BE64;
loc_8218BE7C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8218BE84;
	sub_82130588(ctx, base);
	// sth r26,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r26.u16);
	// addi r30,r28,16
	r30.s64 = r28.s64 + 16;
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// lhz r11,20(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218beb4
	if (cr6.eq) goto loc_8218BEB4;
loc_8218BE9C:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8218be9c
	if (!cr6.eq) goto loc_8218BE9C;
loc_8218BEB4:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8218BEBC;
	sub_82130588(ctx, base);
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
	// sth r26,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r26.u16);
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218beec
	if (cr6.eq) goto loc_8218BEEC;
loc_8218BED4:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8218bed4
	if (!cr6.eq) goto loc_8218BED4;
loc_8218BEEC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8218BEF4;
	sub_82130588(ctx, base);
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// sth r26,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r26.u16);
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218be38
	if (!cr6.eq) goto loc_8218BE38;
loc_8218BF08:
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8218BF10;
	sub_82130588(ctx, base);
	// stw r26,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r26.u32);
	// sth r26,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r26.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8218BF20"))) PPC_WEAK_FUNC(sub_8218BF20);
PPC_FUNC_IMPL(__imp__sub_8218BF20) {
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
	ctx.lr = 0x8218BF28;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218BF3C;
	sub_821BE4F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821be250
	ctx.lr = 0x8218BF4C;
	sub_821BE250(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2a58
	ctx.lr = 0x8218BF58;
	sub_821D2A58(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821c9790
	ctx.lr = 0x8218BF64;
	sub_821C9790(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218BF70;
	sub_821BE4F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218bcd0
	ctx.lr = 0x8218BF88;
	sub_8218BCD0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8218bfe8
	if (!cr6.gt) goto loc_8218BFE8;
	// mr r28,r30
	r28.u64 = r30.u64;
	// li r30,0
	r30.s64 = 0;
loc_8218BF98:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,5
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 5);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add. r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// beq 0x8218bfd8
	if (cr0.eq) goto loc_8218BFD8;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// sth r30,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r30.u16);
	// sth r30,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r30.u16);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// sth r30,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, r30.u16);
	// sth r30,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, r30.u16);
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r30.u32);
	// sth r30,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, r30.u16);
	// sth r30,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, r30.u16);
loc_8218BFD8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218b000
	ctx.lr = 0x8218BFE0;
	sub_8218B000(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bne 0x8218bf98
	if (!cr0.eq) goto loc_8218BF98;
loc_8218BFE8:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218BFF0"))) PPC_WEAK_FUNC(sub_8218BFF0);
PPC_FUNC_IMPL(__imp__sub_8218BFF0) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,12
	ctx.r9.s64 = 12;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r4,r11,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r11,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r11.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218C040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218c080
	if (!cr6.gt) goto loc_8218C080;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8218C054:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8218c074
	if (cr0.eq) goto loc_8218C074;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// sth r9,14(r11)
	PPC_STORE_U16(r11.u32 + 14, ctx.r9.u16);
	// sth r9,12(r11)
	PPC_STORE_U16(r11.u32 + 12, ctx.r9.u16);
loc_8218C074:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8218c054
	if (!cr0.eq) goto loc_8218C054;
loc_8218C080:
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

__attribute__((alias("__imp__sub_8218C098"))) PPC_WEAK_FUNC(sub_8218C098);
PPC_FUNC_IMPL(__imp__sub_8218C098) {
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
	ctx.lr = 0x8218C0A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218c0f4
	if (cr6.eq) goto loc_8218C0F4;
	// lis r11,0
	r11.s64 = 0;
	// ori r29,r11,65535
	r29.u64 = r11.u64 | 65535;
loc_8218C0BC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r8,4,12,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFF0;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x8218be10
	ctx.lr = 0x8218C0E0;
	sub_8218BE10(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x8218C0E8;
	sub_821D2AA0(ctx, base);
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8218c0bc
	if (!cr6.eq) goto loc_8218C0BC;
loc_8218C0F4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8218C0FC;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218C110"))) PPC_WEAK_FUNC(sub_8218C110);
PPC_FUNC_IMPL(__imp__sub_8218C110) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-14916
	ctx.r4.s64 = ctx.r10.s64 + -14916;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// sth r11,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r11.u16);
	// sth r11,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r11.u16);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// sth r11,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r11.u16);
	// sth r11,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r11.u16);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// sth r11,56(r31)
	PPC_STORE_U16(r31.u32 + 56, r11.u16);
	// sth r11,58(r31)
	PPC_STORE_U16(r31.u32 + 58, r11.u16);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// bl 0x821c8fe0
	ctx.lr = 0x8218C190;
	sub_821C8FE0(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,-18000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18000);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stw r31,-18000(r9)
	PPC_STORE_U32(ctx.r9.u32 + -18000, r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x8218C1A8;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_8218C1C0"))) PPC_WEAK_FUNC(sub_8218C1C0);
PPC_FUNC_IMPL(__imp__sub_8218C1C0) {
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
	ctx.lr = 0x8218C1C8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218C1DC;
	sub_821BE4F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r15,r22,16
	r15.s64 = r22.s64 + 16;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x8218af68
	ctx.lr = 0x8218C1F4;
	sub_8218AF68(ctx, base);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218c234
	if (!cr6.gt) goto loc_8218C234;
loc_8218C200:
	// lhz r9,4(r15)
	ctx.r9.u64 = PPC_LOAD_U16(r15.u32 + 4);
	// lwz r10,0(r15)
	ctx.r10.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,4
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add. r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// sth r8,4(r15)
	PPC_STORE_U16(r15.u32 + 4, ctx.r8.u16);
	// beq 0x8218c224
	if (cr0.eq) goto loc_8218C224;
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
loc_8218C224:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x8218a190
	ctx.lr = 0x8218C22C;
	sub_8218A190(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8218c200
	if (!cr0.eq) goto loc_8218C200;
loc_8218C234:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218C23C;
	sub_821BE4F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r23,r22,24
	r23.s64 = r22.s64 + 24;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8218af68
	ctx.lr = 0x8218C254;
	sub_8218AF68(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218c290
	if (!cr6.gt) goto loc_8218C290;
loc_8218C25C:
	// lhz r9,4(r23)
	ctx.r9.u64 = PPC_LOAD_U16(r23.u32 + 4);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,4
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add. r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// sth r8,4(r23)
	PPC_STORE_U16(r23.u32 + 4, ctx.r8.u16);
	// beq 0x8218c280
	if (cr0.eq) goto loc_8218C280;
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
loc_8218C280:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x8218a270
	ctx.lr = 0x8218C288;
	sub_8218A270(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8218c25c
	if (!cr0.eq) goto loc_8218C25C;
loc_8218C290:
	// lwz r21,0(r13)
	r21.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r11,28
	r11.s64 = 28;
	// li r20,12
	r20.s64 = 12;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lwzx r10,r21,r11
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + r11.u32);
	// lwzx r17,r21,r20
	r17.u64 = PPC_LOAD_U32(r21.u32 + r20.u32);
	// stwx r10,r21,r20
	PPC_STORE_U32(r21.u32 + r20.u32, ctx.r10.u32);
	// bl 0x821be4f0
	ctx.lr = 0x8218C2B0;
	sub_821BE4F0(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ori r27,r9,65535
	r27.u64 = ctx.r9.u64 | 65535;
	// ble cr6,0x8218c53c
	if (!cr6.gt) goto loc_8218C53C;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// lis r25,-32124
	r25.s64 = -2105278464;
	// addi r19,r9,-18620
	r19.s64 = ctx.r9.s64 + -18620;
	// addi r24,r10,-21072
	r24.s64 = ctx.r10.s64 + -21072;
	// addi r28,r11,-17992
	r28.s64 = r11.s64 + -17992;
loc_8218C2E0:
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// sth r27,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r27.u16);
	// sth r27,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r27.u16);
	// bl 0x8218b0c8
	ctx.lr = 0x8218C308;
	sub_8218B0C8(ctx, base);
	// lhz r11,20(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 20);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// sth r5,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, ctx.r5.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r6,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, ctx.r6.u16);
	// beq cr6,0x8218c370
	if (cr6.eq) goto loc_8218C370;
	// lwz r9,0(r15)
	ctx.r9.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// clrlwi r8,r11,16
	ctx.r8.u64 = r11.u32 & 0xFFFF;
loc_8218C330:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8218c364
	if (!cr6.gt) goto loc_8218C364;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_8218C344:
	// lwz r4,2(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 2);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// bne cr6,0x8218c358
	if (!cr6.eq) goto loc_8218C358;
	// lhz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// sth r6,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, ctx.r6.u16);
loc_8218C358:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8218c344
	if (!cr0.eq) goto loc_8218C344;
loc_8218C364:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x8218c330
	if (!cr0.eq) goto loc_8218C330;
loc_8218C370:
	// lhz r11,28(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218c3c4
	if (cr6.eq) goto loc_8218C3C4;
	// lwz r9,0(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// clrlwi r8,r11,16
	ctx.r8.u64 = r11.u32 & 0xFFFF;
loc_8218C384:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8218c3b8
	if (!cr6.gt) goto loc_8218C3B8;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_8218C398:
	// lwz r4,2(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 2);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// bne cr6,0x8218c3ac
	if (!cr6.eq) goto loc_8218C3AC;
	// lhz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// sth r5,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, ctx.r5.u16);
loc_8218C3AC:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8218c398
	if (!cr0.eq) goto loc_8218C398;
loc_8218C3B8:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x8218c384
	if (!cr0.eq) goto loc_8218C384;
loc_8218C3C4:
	// lwz r11,3072(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3072);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8218c434
	if (!cr6.gt) goto loc_8218C434;
	// addi r9,r28,12
	ctx.r9.s64 = r28.s64 + 12;
loc_8218C3DC:
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// beq cr6,0x8218c3fc
	if (cr6.eq) goto loc_8218C3FC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x8218c3dc
	if (cr6.lt) goto loc_8218C3DC;
	// b 0x8218c434
	goto loc_8218C434;
loc_8218C3FC:
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r28,28
	ctx.r9.s64 = r28.s64 + 28;
	// lhzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// bne cr6,0x8218c418
	if (!cr6.eq) goto loc_8218C418;
	// sthx r6,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u16);
	// lwz r11,3072(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3072);
loc_8218C418:
	// addi r9,r28,30
	ctx.r9.s64 = r28.s64 + 30;
	// lhzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// bne cr6,0x8218c430
	if (!cr6.eq) goto loc_8218C430;
	// sthx r5,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u16);
	// lwz r11,3072(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3072);
loc_8218C430:
	// li r8,1
	ctx.r8.s64 = 1;
loc_8218C434:
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8218c52c
	if (!cr6.eq) goto loc_8218C52C;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// cmplwi cr6,r9,6
	cr6.compare<uint32_t>(ctx.r9.u32, 6, xer);
	// bne cr6,0x8218c45c
	if (!cr6.eq) goto loc_8218C45C;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r30,r9,3,0,27
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF0;
	// b 0x8218c460
	goto loc_8218C460;
loc_8218C45C:
	// rotlwi r30,r10,4
	r30.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
loc_8218C460:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8218c4ac
	if (cr6.eq) goto loc_8218C4AC;
	// lwz r11,-21104(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -21104);
	// add r31,r11,r24
	r31.u64 = r11.u64 + r24.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,-21104(r25)
	PPC_STORE_U32(r25.u32 + -21104, r11.u32);
	// cmplwi cr6,r11,3072
	cr6.compare<uint32_t>(r11.u32, 3072, xer);
	// ble cr6,0x8218c488
	if (!cr6.gt) goto loc_8218C488;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821bd618
	ctx.lr = 0x8218C488;
	sub_821BD618(ctx, base);
loc_8218C488:
	// lwz r29,104(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x8218C49C;
	sub_823DA950(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8218C4A4;
	sub_82130588(ctx, base);
	// lwz r11,3072(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3072);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
loc_8218C4AC:
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lbz r9,81(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r8,83(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// add r31,r10,r28
	r31.u64 = ctx.r10.u64 + r28.u64;
	// lbz r6,82(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// stw r11,3072(r28)
	PPC_STORE_U32(r28.u32 + 3072, r11.u32);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stbx r7,r10,r28
	PPC_STORE_U8(ctx.r10.u32 + r28.u32, ctx.r7.u8);
	// stb r9,1(r31)
	PPC_STORE_U8(r31.u32 + 1, ctx.r9.u8);
	// stb r6,2(r31)
	PPC_STORE_U8(r31.u32 + 2, ctx.r6.u8);
	// stb r8,3(r31)
	PPC_STORE_U8(r31.u32 + 3, ctx.r8.u8);
	// bl 0x821d2a58
	ctx.lr = 0x8218C4E8;
	sub_821D2A58(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x821d2a58
	ctx.lr = 0x8218C4F4;
	sub_821D2A58(ctx, base);
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lhz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 108);
	// lhz r9,110(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 110);
	// stw r5,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r5.u32);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// stw r4,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r4.u32);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// sth r10,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r10.u16);
	// sth r9,30(r31)
	PPC_STORE_U16(r31.u32 + 30, ctx.r9.u16);
loc_8218C52C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8218bbc8
	ctx.lr = 0x8218C534;
	sub_8218BBC8(ctx, base);
	// addic. r16,r16,-1
	xer.ca = r16.u32 > 0;
	r16.s64 = r16.s64 + -1;
	cr0.compare<int32_t>(r16.s32, 0, xer);
	// bne 0x8218c2e0
	if (!cr0.eq) goto loc_8218C2E0;
loc_8218C53C:
	// stwx r17,r21,r20
	PPC_STORE_U32(r21.u32 + r20.u32, r17.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218C548;
	sub_821BE4F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r22,8
	r31.s64 = r22.s64 + 8;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82189f00
	ctx.lr = 0x8218C560;
	sub_82189F00(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8218c5b4
	if (!cr6.gt) goto loc_8218C5B4;
loc_8218C568:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,5
	r11.u64 = __builtin_rotateleft32(r11.u32, 5);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add. r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// beq 0x8218c5a0
	if (cr0.eq) goto loc_8218C5A0;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
	// stw r26,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r26.u32);
	// stw r26,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r26.u32);
	// sth r27,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, r27.u16);
	// sth r27,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, r27.u16);
loc_8218C5A0:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x8218b0c8
	ctx.lr = 0x8218C5AC;
	sub_8218B0C8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8218c568
	if (!cr0.eq) goto loc_8218C568;
loc_8218C5B4:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8218C5BC;
	sub_821BE4F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8218bff0
	ctx.lr = 0x8218C5D0;
	sub_8218BFF0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218c61c
	if (!cr6.gt) goto loc_8218C61C;
loc_8218C5D8:
	// lhz r11,4(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 4);
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add. r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// sth r9,4(r22)
	PPC_STORE_U16(r22.u32 + 4, ctx.r9.u16);
	// beq 0x8218c60c
	if (cr0.eq) goto loc_8218C60C;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
	// sth r26,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r26.u16);
	// sth r26,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r26.u16);
loc_8218C60C:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x8218bf20
	ctx.lr = 0x8218C614;
	sub_8218BF20(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8218c5d8
	if (!cr0.eq) goto loc_8218C5D8;
loc_8218C61C:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8218b5d0
	ctx.lr = 0x8218C624;
	sub_8218B5D0(ctx, base);
	// addi r4,r22,48
	ctx.r4.s64 = r22.s64 + 48;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8218a318
	ctx.lr = 0x8218C630;
	sub_8218A318(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8218C638"))) PPC_WEAK_FUNC(sub_8218C638);
PPC_FUNC_IMPL(__imp__sub_8218C638) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// bl 0x821d31f8
	ctx.lr = 0x8218C658;
	sub_821D31F8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d3170
	ctx.lr = 0x8218C660;
	sub_821D3170(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218c098
	ctx.lr = 0x8218C668;
	sub_8218C098(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x8218bd88
	ctx.lr = 0x8218C670;
	sub_8218BD88(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8218bb40
	ctx.lr = 0x8218C678;
	sub_8218BB40(ctx, base);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x8218bb40
	ctx.lr = 0x8218C680;
	sub_8218BB40(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d3188
	ctx.lr = 0x8218C688;
	sub_821D3188(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82189ad0
	ctx.lr = 0x8218C690;
	sub_82189AD0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2f58
	ctx.lr = 0x8218C698;
	sub_821D2F58(ctx, base);
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

__attribute__((alias("__imp__sub_8218C6AC"))) PPC_WEAK_FUNC(sub_8218C6AC);
PPC_FUNC_IMPL(__imp__sub_8218C6AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218C6B0"))) PPC_WEAK_FUNC(sub_8218C6B0);
PPC_FUNC_IMPL(__imp__sub_8218C6B0) {
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
	// bl 0x8218c638
	ctx.lr = 0x8218C6C8;
	sub_8218C638(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-14916
	ctx.r4.s64 = r11.s64 + -14916;
	// bl 0x821c8fe0
	ctx.lr = 0x8218C6D8;
	sub_821C8FE0(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r11,r10,-18000
	r11.s64 = ctx.r10.s64 + -18000;
	// lwz r10,-18000(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18000);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// beq cr6,0x8218c700
	if (cr6.eq) goto loc_8218C700;
loc_8218C6EC:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x8218c6ec
	if (!cr6.eq) goto loc_8218C6EC;
loc_8218C700:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bl 0x821c9030
	ctx.lr = 0x8218C714;
	sub_821C9030(ctx, base);
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// bl 0x821d2aa0
	ctx.lr = 0x8218C71C;
	sub_821D2AA0(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82189ad0
	ctx.lr = 0x8218C724;
	sub_82189AD0(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x82130588
	ctx.lr = 0x8218C72C;
	sub_82130588(ctx, base);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x8218bb40
	ctx.lr = 0x8218C734;
	sub_8218BB40(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8218bb40
	ctx.lr = 0x8218C73C;
	sub_8218BB40(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x8218bd88
	ctx.lr = 0x8218C744;
	sub_8218BD88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218c098
	ctx.lr = 0x8218C74C;
	sub_8218C098(ctx, base);
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

__attribute__((alias("__imp__sub_8218C760"))) PPC_WEAK_FUNC(sub_8218C760);
PPC_FUNC_IMPL(__imp__sub_8218C760) {
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
	ctx.lr = 0x8218C768;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x8218c638
	ctx.lr = 0x8218C77C;
	sub_8218C638(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8218c7e8
	if (cr6.eq) goto loc_8218C7E8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r7,r11,-18496
	ctx.r7.s64 = r11.s64 + -18496;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x821ca2f8
	ctx.lr = 0x8218C7A8;
	sub_821CA2F8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r5,r9,-18508
	ctx.r5.s64 = ctx.r9.s64 + -18508;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c9c50
	ctx.lr = 0x8218C7BC;
	sub_821C9C50(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8218c86c
	if (cr6.eq) goto loc_8218C86C;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// bl 0x821d2a58
	ctx.lr = 0x8218C7D4;
	sub_821D2A58(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9ab0
	ctx.lr = 0x8218C7DC;
	sub_821C9AB0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8218C7E4;
	sub_821C9790(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
loc_8218C7E8:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x821bdf20
	ctx.lr = 0x8218C7F4;
	sub_821BDF20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8218c86c
	if (cr6.eq) goto loc_8218C86C;
	// bl 0x821be8d8
	ctx.lr = 0x8218C804;
	sub_821BE8D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218c86c
	if (cr6.eq) goto loc_8218C86C;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x821cb488
	ctx.lr = 0x8218C818;
	sub_821CB488(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218C82C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// std r3,40(r31)
	PPC_STORE_U64(r31.u32 + 40, ctx.r3.u64);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be710
	ctx.lr = 0x8218C840;
	sub_821BE710(ctx, base);
	// lis r9,24952
	ctx.r9.s64 = 1635254272;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ori r8,r9,26482
	ctx.r8.u64 = ctx.r9.u64 | 26482;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// beq cr6,0x8218c878
	if (cr6.eq) goto loc_8218C878;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r3,r11,-18584
	ctx.r3.s64 = r11.s64 + -18584;
	// bl 0x821bd618
	ctx.lr = 0x8218C864;
	sub_821BD618(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x8218C86C;
	sub_821BE610(ctx, base);
loc_8218C86C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9248
	return;
loc_8218C878:
	// lis r28,-32124
	r28.s64 = -2105278464;
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r29,-21084(r28)
	PPC_STORE_U32(r28.u32 + -21084, r29.u32);
	// bl 0x821d31f8
	ctx.lr = 0x8218C88C;
	sub_821D31F8(ctx, base);
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// bl 0x821d3070
	ctx.lr = 0x8218C89C;
	sub_821D3070(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218c1c0
	ctx.lr = 0x8218C8A8;
	sub_8218C1C0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d30e8
	ctx.lr = 0x8218C8B0;
	sub_821D30E8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,-21084(r28)
	PPC_STORE_U32(r28.u32 + -21084, r11.u32);
	// bl 0x821be610
	ctx.lr = 0x8218C8C0;
	sub_821BE610(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d2f58
	ctx.lr = 0x8218C8C8;
	sub_821D2F58(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218C8D4"))) PPC_WEAK_FUNC(sub_8218C8D4);
PPC_FUNC_IMPL(__imp__sub_8218C8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218C8D8"))) PPC_WEAK_FUNC(sub_8218C8D8);
PPC_FUNC_IMPL(__imp__sub_8218C8D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,-13528(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -13528);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stw r4,-13528(r11)
	PPC_STORE_U32(r11.u32 + -13528, ctx.r4.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x82417c70
	sub_82417C70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C8FC"))) PPC_WEAK_FUNC(sub_8218C8FC);
PPC_FUNC_IMPL(__imp__sub_8218C8FC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218C900"))) PPC_WEAK_FUNC(sub_8218C900);
PPC_FUNC_IMPL(__imp__sub_8218C900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,24456(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24456);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stw r4,24456(r11)
	PPC_STORE_U32(r11.u32 + 24456, ctx.r4.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// b 0x824179b8
	sub_824179B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C924"))) PPC_WEAK_FUNC(sub_8218C924);
PPC_FUNC_IMPL(__imp__sub_8218C924) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218C928"))) PPC_WEAK_FUNC(sub_8218C928);
PPC_FUNC_IMPL(__imp__sub_8218C928) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// beq cr6,0x8218c998
	if (cr6.eq) goto loc_8218C998;
	// cmpwi cr6,r10,7
	cr6.compare<int32_t>(ctx.r10.s32, 7, xer);
	// beq cr6,0x8218c988
	if (cr6.eq) goto loc_8218C988;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// rlwinm r8,r11,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r7,r9,24256
	ctx.r7.s64 = ctx.r9.s64 + 24256;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// lbzx r7,r10,r7
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r7.u32);
	// rldicr r10,r9,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mullw r6,r7,r6
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// lwz r3,-28076(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -28076);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// rlwinm r7,r9,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r11,r8,r7
	r11.s64 = ctx.r7.s64 - ctx.r8.s64;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// srad r7,r10,r9
	temp.u64 = ctx.r9.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	xer.ca = (ctx.r10.s64 < 0) & (((ctx.r10.s64 >> temp.u64) << temp.u64) != ctx.r10.s64);
	ctx.r7.s64 = ctx.r10.s64 >> temp.u64;
	// srd r7,r7,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r7.u64 >> (ctx.r8.u8 & 0x7F));
	// b 0x82417678
	sub_82417678(ctx, base);
	return;
loc_8218C988:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-28076(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// b 0x82417838
	sub_82417838(ctx, base);
	return;
loc_8218C998:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-28076(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// b 0x824178f8
	sub_824178F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C9A8"))) PPC_WEAK_FUNC(sub_8218C9A8);
PPC_FUNC_IMPL(__imp__sub_8218C9A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r8,r11,-14880
	ctx.r8.s64 = r11.s64 + -14880;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// li r5,1352
	ctx.r5.s64 = 1352;
	// stw r10,24456(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24456, ctx.r10.u32);
	// li r4,205
	ctx.r4.s64 = 205;
	// stw r11,1352(r8)
	PPC_STORE_U32(ctx.r8.u32 + 1352, r11.u32);
	// b 0x823d9890
	sub_823D9890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C9D4"))) PPC_WEAK_FUNC(sub_8218C9D4);
PPC_FUNC_IMPL(__imp__sub_8218C9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218C9D8"))) PPC_WEAK_FUNC(sub_8218C9D8);
PPC_FUNC_IMPL(__imp__sub_8218C9D8) {
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
	ctx.lr = 0x8218C9E0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8218ca28
	if (!cr6.eq) goto loc_8218CA28;
	// addi r10,r29,32
	ctx.r10.s64 = r29.s64 + 32;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r7,r9,63,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// srd r6,r7,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r7.u64 >> (ctx.r8.u8 & 0x7F));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82410f88
	ctx.lr = 0x8218CA20;
	sub_82410F88(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
loc_8218CA28:
	// addi r11,r29,32
	r11.s64 = r29.s64 + 32;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// rldicr r8,r10,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// srd r6,r8,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r9.u8 & 0x7F));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-28076(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -28076);
	// bl 0x82410f88
	ctx.lr = 0x8218CA50;
	sub_82410F88(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,24128
	r11.s64 = r11.s64 + 24128;
	// li r9,13
	ctx.r9.s64 = 13;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8218CA64:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8218ca64
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8218CA64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218caa8
	if (!cr6.gt) goto loc_8218CAA8;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8218CA88:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stwx r7,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r7.u32);
	// bne 0x8218ca88
	if (!cr0.eq) goto loc_8218CA88;
loc_8218CAA8:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mulli r10,r29,52
	ctx.r10.s64 = r29.s64 * 52;
	// addi r11,r11,-14880
	r11.s64 = r11.s64 + -14880;
	// li r31,0
	r31.s64 = 0;
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r28,r11,24460
	r28.s64 = r11.s64 + 24460;
loc_8218CAC4:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r5,r31,r11
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// beq cr6,0x8218caf8
	if (cr6.eq) goto loc_8218CAF8;
	// lwz r3,-28076(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -28076);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwzx r11,r31,r28
	r11.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218CAF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8218CAF8:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,48
	cr6.compare<int32_t>(r31.s32, 48, xer);
	// blt cr6,0x8218cac4
	if (cr6.lt) goto loc_8218CAC4;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8218CB10"))) PPC_WEAK_FUNC(sub_8218CB10);
PPC_FUNC_IMPL(__imp__sub_8218CB10) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x8218c9d8
	sub_8218C9D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CB24"))) PPC_WEAK_FUNC(sub_8218CB24);
PPC_FUNC_IMPL(__imp__sub_8218CB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CB28"))) PPC_WEAK_FUNC(sub_8218CB28);
PPC_FUNC_IMPL(__imp__sub_8218CB28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// lhz r11,2(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// b 0x8218c9d8
	sub_8218C9D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CB50"))) PPC_WEAK_FUNC(sub_8218CB50);
PPC_FUNC_IMPL(__imp__sub_8218CB50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// beq cr6,0x8218cbc0
	if (cr6.eq) goto loc_8218CBC0;
	// cmpwi cr6,r10,7
	cr6.compare<int32_t>(ctx.r10.s32, 7, xer);
	// beq cr6,0x8218cbb0
	if (cr6.eq) goto loc_8218CBB0;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// rlwinm r8,r11,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r7,r9,24256
	ctx.r7.s64 = ctx.r9.s64 + 24256;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// lbzx r7,r10,r7
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r7.u32);
	// rldicr r10,r9,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mullw r6,r7,r6
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// lwz r3,-28076(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -28076);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// rlwinm r7,r9,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r11,r8,r7
	r11.s64 = ctx.r7.s64 - ctx.r8.s64;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// srad r7,r10,r9
	temp.u64 = ctx.r9.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	xer.ca = (ctx.r10.s64 < 0) & (((ctx.r10.s64 >> temp.u64) << temp.u64) != ctx.r10.s64);
	ctx.r7.s64 = ctx.r10.s64 >> temp.u64;
	// srd r7,r7,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r7.u64 >> (ctx.r8.u8 & 0x7F));
	// b 0x82417758
	sub_82417758(ctx, base);
	return;
loc_8218CBB0:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-28076(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// b 0x82417898
	sub_82417898(ctx, base);
	return;
loc_8218CBC0:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-28076(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// b 0x82417950
	sub_82417950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CBD0"))) PPC_WEAK_FUNC(sub_8218CBD0);
PPC_FUNC_IMPL(__imp__sub_8218CBD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// lhz r3,2(r8)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// b 0x8218c9d8
	sub_8218C9D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CBF4"))) PPC_WEAK_FUNC(sub_8218CBF4);
PPC_FUNC_IMPL(__imp__sub_8218CBF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CBF8"))) PPC_WEAK_FUNC(sub_8218CBF8);
PPC_FUNC_IMPL(__imp__sub_8218CBF8) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// b 0x8218c9d8
	sub_8218C9D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CC08"))) PPC_WEAK_FUNC(sub_8218CC08);
PPC_FUNC_IMPL(__imp__sub_8218CC08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// rldicr r6,r7,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r3,-28076(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28076);
	// lhz r11,2(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// addi r11,r4,32
	r11.s64 = ctx.r4.s64 + 32;
	// clrldi r10,r11,32
	ctx.r10.u64 = r11.u64 & 0xFFFFFFFF;
	// srd r6,r6,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r10.u8 & 0x7F));
	// b 0x82410f88
	sub_82410F88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CC3C"))) PPC_WEAK_FUNC(sub_8218CC3C);
PPC_FUNC_IMPL(__imp__sub_8218CC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CC40"))) PPC_WEAK_FUNC(sub_8218CC40);
PPC_FUNC_IMPL(__imp__sub_8218CC40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// rldicr r6,r7,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r3,-28076(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28076);
	// lhz r4,2(r8)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// addi r11,r4,32
	r11.s64 = ctx.r4.s64 + 32;
	// clrldi r10,r11,32
	ctx.r10.u64 = r11.u64 & 0xFFFFFFFF;
	// srd r6,r6,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r10.u8 & 0x7F));
	// b 0x82410f88
	sub_82410F88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CC70"))) PPC_WEAK_FUNC(sub_8218CC70);
PPC_FUNC_IMPL(__imp__sub_8218CC70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,24512
	ctx.r9.s64 = r11.s64 + 24512;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r3,-28076(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28076);
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + r11.u64;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// SAFETY: validate targetFn AND basePtr before indirect branch
	// targetFn must be aligned, non-NULL, in recomp code range
	if ((ctx.r8.u32 & 3u) != 0 || ctx.r8.u32 == 0 ||
	    ctx.r8.u32 < 0x82130000u || ctx.r8.u32 >= 0x83000000u) {
		return;
	}
	// Validate basePtr (r3) is in a reasonable heap range
	// Only allow heap (0xA0000000) or image data (0x82800000-0x82FFFFFF)
	// Reject GPU memory (0x40000000), dead patterns (CABABAB0, DEADBEEF), NULL
	if (ctx.r3.u32 == 0 ||
	    (ctx.r3.u32 >= 0x40000000u && ctx.r3.u32 < 0x50000000u) ||
	    (ctx.r3.u32 & 0xFFF00000u) == 0xCAB00000u ||
	    (ctx.r3.u32 & 0xFFF00000u) == 0xDEAD0000u) {
		return;
	}
	// Validate that targetFn has a recompiled function entry
	// If no recompiled function exists, the lookup returns NULL → bctr would crash
	{
		const uint64_t fnIdx = (uint64_t)(ctx.r8.u32 - 0x82130000u) * 2;
		uint8_t* fnSlot = base + 0x82000000ull + 0x9E0000ull + fnIdx;
		const void* fnPtr = *reinterpret_cast<void**>(fnSlot);
		if (fnPtr == nullptr) {
			return;
		}
	}
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218CCA0"))) PPC_WEAK_FUNC(sub_8218CCA0);
PPC_FUNC_IMPL(__imp__sub_8218CCA0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218CCA4"))) PPC_WEAK_FUNC(sub_8218CCA4);
PPC_FUNC_IMPL(__imp__sub_8218CCA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CCA8"))) PPC_WEAK_FUNC(sub_8218CCA8);
PPC_FUNC_IMPL(__imp__sub_8218CCA8) {
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
	// bl 0x82189dd8
	ctx.lr = 0x8218CCB8;
	sub_82189DD8(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,1352
	ctx.r5.s64 = 1352;
	// addi r3,r11,-14880
	ctx.r3.s64 = r11.s64 + -14880;
	// li r4,205
	ctx.r4.s64 = 205;
	// bl 0x823d9890
	ctx.lr = 0x8218CCCC;
	sub_823D9890(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218CCDC"))) PPC_WEAK_FUNC(sub_8218CCDC);
PPC_FUNC_IMPL(__imp__sub_8218CCDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CCE0"))) PPC_WEAK_FUNC(sub_8218CCE0);
PPC_FUNC_IMPL(__imp__sub_8218CCE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lhz r3,2(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// b 0x8218c928
	sub_8218C928(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CCF8"))) PPC_WEAK_FUNC(sub_8218CCF8);
PPC_FUNC_IMPL(__imp__sub_8218CCF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lhz r3,2(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// b 0x8218cb50
	sub_8218CB50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CD10"))) PPC_WEAK_FUNC(sub_8218CD10);
PPC_FUNC_IMPL(__imp__sub_8218CD10) {
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
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218cd34
	if (cr6.eq) goto loc_8218CD34;
	// bl 0x8217f540
	ctx.lr = 0x8218CD34;
	sub_8217F540(ctx, base);
loc_8218CD34:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8218CD3C;
	sub_82130588(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218cd5c
	if (!cr6.eq) goto loc_8218CD5C;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218cd5c
	if (!cr6.eq) goto loc_8218CD5C;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x8218CD5C;
	sub_82130588(ctx, base);
loc_8218CD5C:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218cd6c
	if (cr6.eq) goto loc_8218CD6C;
	// bl 0x8217f540
	ctx.lr = 0x8218CD6C;
	sub_8217F540(ctx, base);
loc_8218CD6C:
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

__attribute__((alias("__imp__sub_8218CD80"))) PPC_WEAK_FUNC(sub_8218CD80);
PPC_FUNC_IMPL(__imp__sub_8218CD80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8218CD90:
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8218cd90
	if (!cr6.eq) goto loc_8218CD90;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218CDA4"))) PPC_WEAK_FUNC(sub_8218CDA4);
PPC_FUNC_IMPL(__imp__sub_8218CDA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CDA8"))) PPC_WEAK_FUNC(sub_8218CDA8);
PPC_FUNC_IMPL(__imp__sub_8218CDA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r24{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8218CDB0;
	// lbz r10,7(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// li r8,255
	ctx.r8.s64 = 255;
	// rotlwi r5,r10,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r10,5(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// lbz r31,4(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// or r11,r5,r9
	r11.u64 = ctx.r5.u64 | ctx.r9.u64;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rlwinm r5,r4,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r4,3(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r30,0(r3)
	r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r3,2(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stb r8,3(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3, ctx.r8.u8);
	// rotlwi r10,r4,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// rlwinm r8,r11,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r9,r30
	ctx.r4.u64 = ctx.r9.u64 | r30.u64;
	// or r11,r8,r31
	r11.u64 = ctx.r8.u64 | r31.u64;
	// or r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 | ctx.r3.u64;
	// srw r5,r11,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r5.u8 & 0x3F));
	// clrlwi r9,r5,30
	ctx.r9.u64 = ctx.r5.u32 & 0x3;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// bgt cr6,0x8218d070
	if (cr6.gt) goto loc_8218D070;
	// lis r12,-32231
	r12.s64 = -2112290816;
	// addi r12,r12,-12740
	r12.s64 = r12.s64 + -12740;
	// rlwinm r0,r9,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r9.u64) {
	case 0:
		goto loc_8218CE4C;
	case 1:
		goto loc_8218CE80;
	case 2:
		goto loc_8218CEB4;
	case 3:
		goto loc_8218CFB8;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-12724(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -12724);
	// lwz r16,-12672(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -12672);
	// lwz r16,-12620(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -12620);
	// lwz r16,-12360(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -12360);
loc_8218CE4C:
	// rlwinm r11,r10,24,24,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// rlwinm r9,r10,19,29,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x7;
	// rlwinm r8,r10,29,19,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFF;
	// rlwinm r6,r10,23,25,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x7F;
	// rlwinm r5,r10,30,18,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFF;
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r11,r9,0,29,31
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x7) | (r11.u64 & 0xFFFFFFFFFFFFFFF8);
	// rlwimi r8,r6,0,30,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0x3) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFFC);
	// rlwimi r5,r4,3,24,28
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 3) & 0xF8) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFF07);
	// stb r11,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, r11.u8);
	// stb r8,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, ctx.r8.u8);
	// stb r5,2(r7)
	PPC_STORE_U8(ctx.r7.u32 + 2, ctx.r5.u8);
	// b 0x823d924c
	return;
loc_8218CE80:
	// rlwinm r10,r11,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// rlwinm r9,r11,19,29,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x7;
	// rlwinm r8,r11,29,19,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFF;
	// rlwinm r6,r11,23,25,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 23) & 0x7F;
	// rlwinm r5,r11,30,18,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFF;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// rlwimi r10,r9,0,29,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x7) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFF8);
	// rlwimi r8,r6,0,30,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0x3) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFFC);
	// rlwimi r5,r4,3,24,28
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 3) & 0xF8) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFF07);
	// stb r10,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, ctx.r10.u8);
	// stb r8,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, ctx.r8.u8);
	// stb r5,2(r7)
	PPC_STORE_U8(ctx.r7.u32 + 2, ctx.r5.u8);
	// b 0x823d924c
	return;
loc_8218CEB4:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r6,r11,0,16,20
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF800;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// rlwinm r9,r10,0,16,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xF800;
	// rlwinm r8,r10,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r5,r11,27,5,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// ble cr6,0x8218cf44
	if (!cr6.gt) goto loc_8218CF44;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r8,r6,r5
	ctx.r8.u64 = ctx.r6.u64 | ctx.r5.u64;
	// rlwinm r31,r10,30,29,31
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x7;
	// rlwinm r30,r10,3,24,28
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xF8;
	// rlwimi r4,r10,26,27,28
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r10.u32, 26) & 0x18) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFE7);
	// rlwimi r3,r11,26,27,28
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 26) & 0x18) | (ctx.r3.u64 & 0xFFFFFFFFFFFFFFE7);
	// rlwinm r10,r11,30,29,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x7;
	// rlwinm r29,r11,3,24,28
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xF8;
	// rlwinm r6,r8,24,8,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFFFF;
	// or r11,r31,r30
	r11.u64 = r31.u64 | r30.u64;
	// rlwinm r5,r9,25,7,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFE;
	// rlwinm r8,r4,30,23,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x1FE;
	// rlwinm r4,r3,29,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0xFF;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// or r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 | r29.u64;
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// add r5,r8,r4
	ctx.r5.u64 = ctx.r8.u64 + ctx.r4.u64;
	// li r9,3
	ctx.r9.s64 = 3;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// divw r3,r6,r9
	ctx.r3.s32 = ctx.r6.s32 / ctx.r9.s32;
	// divw r11,r5,r9
	r11.s32 = ctx.r5.s32 / ctx.r9.s32;
	// divw r10,r4,r9
	ctx.r10.s32 = ctx.r4.s32 / ctx.r9.s32;
	// stb r3,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, ctx.r3.u8);
	// stb r11,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, r11.u8);
	// stb r10,2(r7)
	PPC_STORE_U8(ctx.r7.u32 + 2, ctx.r10.u8);
	// b 0x823d924c
	return;
loc_8218CF44:
	// or r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 | ctx.r8.u64;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// rlwinm r9,r4,24,8,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r8,r3,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// rlwimi r6,r11,26,27,28
	ctx.r6.u64 = (__builtin_rotateleft32(r11.u32, 26) & 0x18) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFE7);
	// rlwimi r5,r10,26,27,28
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 26) & 0x18) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFE7);
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r8,r5,29,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0xFF;
	// rlwinm r9,r6,29,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0xFF;
	// rlwinm r3,r11,30,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x7;
	// rlwinm r6,r10,30,29,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x7;
	// rlwinm r5,r10,3,24,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xF8;
	// rlwinm r11,r11,3,24,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xF8;
	// srawi r4,r4,1
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 1;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// or r10,r6,r5
	ctx.r10.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r11,r3,r11
	r11.u64 = ctx.r3.u64 | r11.u64;
	// addze r8,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r6,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 1;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// stb r8,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, ctx.r8.u8);
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// srawi r3,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 1;
	// stb r4,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, ctx.r4.u8);
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// stb r10,2(r7)
	PPC_STORE_U8(ctx.r7.u32 + 2, ctx.r10.u8);
	// b 0x823d924c
	return;
loc_8218CFB8:
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// bgt cr6,0x8218cff0
	if (cr6.gt) goto loc_8218CFF0;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8218cff0
	if (cr6.gt) goto loc_8218CFF0;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// stb r11,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, r11.u8);
	// stb r11,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, r11.u8);
	// stb r11,2(r7)
	PPC_STORE_U8(ctx.r7.u32 + 2, r11.u8);
	// bne cr6,0x8218d070
	if (!cr6.eq) goto loc_8218D070;
	// stb r11,3(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3, r11.u8);
	// b 0x823d924c
	return;
loc_8218CFF0:
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r6,r11,27,21,31
	ctx.r6.u64 = (__builtin_rotateleft32(r11.u32, 27) & 0x7FF) | (ctx.r6.u64 & 0xFFFFFFFFFFFFF800);
	// rlwinm r4,r11,30,29,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x7;
	// rlwinm r3,r11,3,24,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xF8;
	// rlwimi r5,r10,27,21,31
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 27) & 0x7FF) | (ctx.r5.u64 & 0xFFFFFFFFFFFFF800);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// rlwimi r11,r9,26,27,28
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 26) & 0x18) | (r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// rlwinm r9,r10,30,29,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x7;
	// rlwimi r31,r8,26,27,28
	r31.u64 = (__builtin_rotateleft32(ctx.r8.u32, 26) & 0x18) | (r31.u64 & 0xFFFFFFFFFFFFFFE7);
	// or r3,r4,r3
	ctx.r3.u64 = ctx.r4.u64 | ctx.r3.u64;
	// rlwinm r10,r10,3,24,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xF8;
	// rlwinm r5,r6,25,23,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0x1FE;
	// rlwinm r4,r30,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF;
	// rlwinm r8,r11,30,23,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1FE;
	// rlwinm r6,r31,29,24,31
	ctx.r6.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 29) & 0xFF;
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// li r9,3
	ctx.r9.s64 = 3;
	// add r4,r8,r6
	ctx.r4.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// divw r11,r5,r9
	r11.s32 = ctx.r5.s32 / ctx.r9.s32;
	// divw r10,r4,r9
	ctx.r10.s32 = ctx.r4.s32 / ctx.r9.s32;
	// divw r9,r3,r9
	ctx.r9.s32 = ctx.r3.s32 / ctx.r9.s32;
	// stb r11,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, r11.u8);
	// stb r10,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, ctx.r10.u8);
	// stb r9,2(r7)
	PPC_STORE_U8(ctx.r7.u32 + 2, ctx.r9.u8);
loc_8218D070:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218D074"))) PPC_WEAK_FUNC(sub_8218D074);
PPC_FUNC_IMPL(__imp__sub_8218D074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

