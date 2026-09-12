#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82727F48"))) PPC_WEAK_FUNC(sub_82727F48);
PPC_FUNC_IMPL(__imp__sub_82727F48) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-20364
	ctx.r10.s64 = r11.s64 + -20364;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82727fc8
	if (cr6.eq) goto loc_82727FC8;
loc_82727F7C:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82727fa8
	if (cr6.eq) goto loc_82727FA8;
loc_82727F88:
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82727f88
	if (!cr6.eq) goto loc_82727F88;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82727fa8
	if (cr6.eq) goto loc_82727FA8;
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
loc_82727FA8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82727FBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82727f7c
	if (!cr6.eq) goto loc_82727F7C;
loc_82727FC8:
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82727d40
	ctx.lr = 0x82727FD4;
	sub_82727D40(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82727FDC;
	sub_82130588(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x82727FE4;
	sub_82130588(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82727ff8
	if (cr6.eq) goto loc_82727FF8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82727de0
	ctx.lr = 0x82727FF8;
	sub_82727DE0(ctx, base);
loc_82727FF8:
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

__attribute__((alias("__imp__sub_82728010"))) PPC_WEAK_FUNC(sub_82728010);
PPC_FUNC_IMPL(__imp__sub_82728010) {
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
	ctx.lr = 0x82728018;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,-20352
	ctx.r4.s64 = ctx.r10.s64 + -20352;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821ca540
	ctx.lr = 0x82728040;
	sub_821CA540(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82556ba8
	ctx.lr = 0x82728054;
	sub_82556BA8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82728060;
	sub_821C9A90(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82728074
	if (!cr6.eq) goto loc_82728074;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82728074:
	// bl 0x82554d48
	ctx.lr = 0x82728078;
	sub_82554D48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728084
	if (cr6.eq) goto loc_82728084;
	// stw r31,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r31.u32);
loc_82728084:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82728090"))) PPC_WEAK_FUNC(sub_82728090);
PPC_FUNC_IMPL(__imp__sub_82728090) {
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
	// bl 0x82553a18
	ctx.lr = 0x827280A8;
	sub_82553A18(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stw r31,32(r11)
	PPC_STORE_U32(r11.u32 + 32, r31.u32);
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

__attribute__((alias("__imp__sub_827280C4"))) PPC_WEAK_FUNC(sub_827280C4);
PPC_FUNC_IMPL(__imp__sub_827280C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827280C8"))) PPC_WEAK_FUNC(sub_827280C8);
PPC_FUNC_IMPL(__imp__sub_827280C8) {
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
	// bl 0x82553a18
	ctx.lr = 0x827280E0;
	sub_82553A18(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stw r31,36(r11)
	PPC_STORE_U32(r11.u32 + 36, r31.u32);
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

__attribute__((alias("__imp__sub_827280FC"))) PPC_WEAK_FUNC(sub_827280FC);
PPC_FUNC_IMPL(__imp__sub_827280FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728100"))) PPC_WEAK_FUNC(sub_82728100);
PPC_FUNC_IMPL(__imp__sub_82728100) {
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
	// bl 0x82553a18
	ctx.lr = 0x82728118;
	sub_82553A18(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82727cc0
	ctx.lr = 0x82728124;
	sub_82727CC0(ctx, base);
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

__attribute__((alias("__imp__sub_82728138"))) PPC_WEAK_FUNC(sub_82728138);
PPC_FUNC_IMPL(__imp__sub_82728138) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82554d48
	ctx.lr = 0x82728150;
	sub_82554D48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728164
	if (cr6.eq) goto loc_82728164;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82727cc0
	ctx.lr = 0x82728164;
	sub_82727CC0(ctx, base);
loc_82728164:
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

__attribute__((alias("__imp__sub_82728178"))) PPC_WEAK_FUNC(sub_82728178);
PPC_FUNC_IMPL(__imp__sub_82728178) {
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
	// bl 0x82553a18
	ctx.lr = 0x82728188;
	sub_82553A18(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lbz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827281A0"))) PPC_WEAK_FUNC(sub_827281A0);
PPC_FUNC_IMPL(__imp__sub_827281A0) {
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
	// bl 0x82554d48
	ctx.lr = 0x827281B0;
	sub_82554D48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827281c8
	if (cr6.eq) goto loc_827281C8;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82727a58
	ctx.lr = 0x827281C8;
	sub_82727A58(ctx, base);
loc_827281C8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827281D8"))) PPC_WEAK_FUNC(sub_827281D8);
PPC_FUNC_IMPL(__imp__sub_827281D8) {
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
	// bl 0x82553a18
	ctx.lr = 0x827281E8;
	sub_82553A18(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82728214
	if (cr6.eq) goto loc_82728214;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82728214
	if (cr6.eq) goto loc_82728214;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82728214:
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

__attribute__((alias("__imp__sub_82728228"))) PPC_WEAK_FUNC(sub_82728228);
PPC_FUNC_IMPL(__imp__sub_82728228) {
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
	// bl 0x82554d48
	ctx.lr = 0x82728238;
	sub_82554D48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728264
	if (cr6.eq) goto loc_82728264;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82728264
	if (cr6.eq) goto loc_82728264;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82728264:
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

__attribute__((alias("__imp__sub_82728278"))) PPC_WEAK_FUNC(sub_82728278);
PPC_FUNC_IMPL(__imp__sub_82728278) {
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
	// bl 0x82727f48
	ctx.lr = 0x82728298;
	sub_82727F48(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827282b0
	if (cr6.eq) goto loc_827282B0;
	// bl 0x82130588
	ctx.lr = 0x827282AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827282B0:
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

__attribute__((alias("__imp__sub_827282C8"))) PPC_WEAK_FUNC(sub_827282C8);
PPC_FUNC_IMPL(__imp__sub_827282C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82728324
	if (cr6.eq) goto loc_82728324;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r10.u32);
	// beq cr6,0x82728308
	if (cr6.eq) goto loc_82728308;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_82728308:
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_82728324:
	// li r11,0
	r11.s64 = 0;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728348"))) PPC_WEAK_FUNC(sub_82728348);
PPC_FUNC_IMPL(__imp__sub_82728348) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8272838c
	if (!cr6.eq) goto loc_8272838C;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82728384
	if (cr6.eq) goto loc_82728384;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// b 0x827283b0
	goto loc_827283B0;
loc_82728384:
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// b 0x827283b0
	goto loc_827283B0;
loc_8272838C:
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827283a8
	if (cr6.eq) goto loc_827283A8;
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// b 0x827283b0
	goto loc_827283B0;
loc_827283A8:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_827283B0:
	// stw r8,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r8.u32);
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827283C8"))) PPC_WEAK_FUNC(sub_827283C8);
PPC_FUNC_IMPL(__imp__sub_827283C8) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82728424
	if (cr6.eq) goto loc_82728424;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82728424
	if (cr6.eq) goto loc_82728424;
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stb r9,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r9.u8);
	// bl 0x827282c8
	ctx.lr = 0x82728410;
	sub_827282C8(ctx, base);
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
loc_82728424:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272843c
	if (cr6.eq) goto loc_8272843C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82728348
	ctx.lr = 0x8272843C;
	sub_82728348(ctx, base);
loc_8272843C:
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stb r9,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_82728468"))) PPC_WEAK_FUNC(sub_82728468);
PPC_FUNC_IMPL(__imp__sub_82728468) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r11,-20284
	ctx.r9.s64 = r11.s64 + -20284;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82728484:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82728504
	if (cr6.eq) goto loc_82728504;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x827284c8
	if (!cr6.eq) goto loc_827284C8;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x827284c0
	if (cr6.eq) goto loc_827284C0;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// b 0x827284f0
	goto loc_827284F0;
loc_827284C0:
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// b 0x827284f0
	goto loc_827284F0;
loc_827284C8:
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x827284e8
	if (cr6.eq) goto loc_827284E8;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// b 0x827284f0
	goto loc_827284F0;
loc_827284E8:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_827284F0:
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
loc_82728504:
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
	// bne cr6,0x82728484
	if (!cr6.eq) goto loc_82728484;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728528"))) PPC_WEAK_FUNC(sub_82728528);
PPC_FUNC_IMPL(__imp__sub_82728528) {
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
	// bl 0x82728468
	ctx.lr = 0x82728548;
	sub_82728468(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82728560
	if (cr6.eq) goto loc_82728560;
	// bl 0x82130588
	ctx.lr = 0x8272855C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82728560:
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

__attribute__((alias("__imp__sub_82728578"))) PPC_WEAK_FUNC(sub_82728578);
PPC_FUNC_IMPL(__imp__sub_82728578) {
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
	// addi r10,r11,-20276
	ctx.r10.s64 = r11.s64 + -20276;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82728468
	ctx.lr = 0x827285A4;
	sub_82728468(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827285bc
	if (cr6.eq) goto loc_827285BC;
	// bl 0x82130588
	ctx.lr = 0x827285B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827285BC:
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

__attribute__((alias("__imp__sub_827285D4"))) PPC_WEAK_FUNC(sub_827285D4);
PPC_FUNC_IMPL(__imp__sub_827285D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827285D8"))) PPC_WEAK_FUNC(sub_827285D8);
PPC_FUNC_IMPL(__imp__sub_827285D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-20276
	ctx.r10.s64 = r11.s64 + -20276;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82728468
	sub_82728468(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827285E8"))) PPC_WEAK_FUNC(sub_827285E8);
PPC_FUNC_IMPL(__imp__sub_827285E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,-9996(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -9996);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x822990d8
	sub_822990D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82728604"))) PPC_WEAK_FUNC(sub_82728604);
PPC_FUNC_IMPL(__imp__sub_82728604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728608"))) PPC_WEAK_FUNC(sub_82728608);
PPC_FUNC_IMPL(__imp__sub_82728608) {
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
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-20276
	ctx.r9.s64 = ctx.r10.s64 + -20276;
	// lis r8,-32141
	ctx.r8.s64 = -2106392576;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r4,r8,-31256
	ctx.r4.s64 = ctx.r8.s64 + -31256;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r3,r7,-20272
	ctx.r3.s64 = ctx.r7.s64 + -20272;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x82554798
	ctx.lr = 0x82728658;
	sub_82554798(ctx, base);
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

__attribute__((alias("__imp__sub_82728670"))) PPC_WEAK_FUNC(sub_82728670);
PPC_FUNC_IMPL(__imp__sub_82728670) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728678"))) PPC_WEAK_FUNC(sub_82728678);
PPC_FUNC_IMPL(__imp__sub_82728678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21192(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21192);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728684"))) PPC_WEAK_FUNC(sub_82728684);
PPC_FUNC_IMPL(__imp__sub_82728684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728688"))) PPC_WEAK_FUNC(sub_82728688);
PPC_FUNC_IMPL(__imp__sub_82728688) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824905e0
	ctx.lr = 0x827286A0;
	sub_824905E0(ctx, base);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r10,-19592
	ctx.r7.s64 = ctx.r10.s64 + -19592;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r6.u32);
	// stb r5,52(r31)
	PPC_STORE_U8(r31.u32 + 52, ctx.r5.u8);
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

__attribute__((alias("__imp__sub_827286E8"))) PPC_WEAK_FUNC(sub_827286E8);
PPC_FUNC_IMPL(__imp__sub_827286E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-19576
	ctx.r3.s64 = r11.s64 + -19576;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827286F4"))) PPC_WEAK_FUNC(sub_827286F4);
PPC_FUNC_IMPL(__imp__sub_827286F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827286F8"))) PPC_WEAK_FUNC(sub_827286F8);
PPC_FUNC_IMPL(__imp__sub_827286F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21188);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728704"))) PPC_WEAK_FUNC(sub_82728704);
PPC_FUNC_IMPL(__imp__sub_82728704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728708"))) PPC_WEAK_FUNC(sub_82728708);
PPC_FUNC_IMPL(__imp__sub_82728708) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r4,96
	ctx.r3.s64 = ctx.r4.s64 + 96;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728710"))) PPC_WEAK_FUNC(sub_82728710);
PPC_FUNC_IMPL(__imp__sub_82728710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,17032(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f11,-17876(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -17876);
	ctx.f11.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f10,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lfs f9,-13148(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -13148);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f8.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,-19560
	ctx.r7.s64 = ctx.r8.s64 + -19560;
	// lfs f7,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-11316(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11316);
	ctx.f5.f64 = double(temp.f32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f11,16(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f10,20(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f9,24(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f8,28(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f7,32(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f6,36(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f5,40(r3)
	temp.f32 = float(ctx.f5.f64);
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
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f0,72(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827287C0"))) PPC_WEAK_FUNC(sub_827287C0);
PPC_FUNC_IMPL(__imp__sub_827287C0) {
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
	// bl 0x8272fa18
	ctx.lr = 0x827287E0;
	sub_8272FA18(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827287f8
	if (cr6.eq) goto loc_827287F8;
	// bl 0x82130588
	ctx.lr = 0x827287F4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827287F8:
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

__attribute__((alias("__imp__sub_82728810"))) PPC_WEAK_FUNC(sub_82728810);
PPC_FUNC_IMPL(__imp__sub_82728810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,20600
	ctx.r3.s64 = r11.s64 + 20600;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272881C"))) PPC_WEAK_FUNC(sub_8272881C);
PPC_FUNC_IMPL(__imp__sub_8272881C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728820"))) PPC_WEAK_FUNC(sub_82728820);
PPC_FUNC_IMPL(__imp__sub_82728820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21184(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21184);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272882C"))) PPC_WEAK_FUNC(sub_8272882C);
PPC_FUNC_IMPL(__imp__sub_8272882C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728830"))) PPC_WEAK_FUNC(sub_82728830);
PPC_FUNC_IMPL(__imp__sub_82728830) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,-17944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17944);
	// bl 0x823057e8
	ctx.lr = 0x82728858;
	sub_823057E8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82728878
	if (cr6.eq) goto loc_82728878;
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
	ctx.lr = 0x82728878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82728878:
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
loc_82728880:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// beq cr6,0x827288a0
	if (cr6.eq) goto loc_827288A0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,20
	cr6.compare<int32_t>(r11.s32, 20, xer);
	// blt cr6,0x82728880
	if (cr6.lt) goto loc_82728880;
	// b 0x827288bc
	goto loc_827288BC;
loc_827288A0:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, ctx.r10.u32);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stw r8,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r8.u32);
loc_827288BC:
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

__attribute__((alias("__imp__sub_827288D4"))) PPC_WEAK_FUNC(sub_827288D4);
PPC_FUNC_IMPL(__imp__sub_827288D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827288D8"))) PPC_WEAK_FUNC(sub_827288D8);
PPC_FUNC_IMPL(__imp__sub_827288D8) {
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
	ctx.lr = 0x827288E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728908
	if (cr6.eq) goto loc_82728908;
	// bl 0x82732b28
	ctx.lr = 0x82728904;
	sub_82732B28(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82728908:
	// lwz r11,88(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82728954
	if (cr6.eq) goto loc_82728954;
	// li r27,0
	r27.s64 = 0;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
loc_8272891C:
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// bge cr6,0x82728954
	if (!cr6.lt) goto loc_82728954;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728944
	if (cr6.eq) goto loc_82728944;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r31,r29
	ctx.r5.s64 = r29.s64 - r31.s64;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// bl 0x82732d90
	ctx.lr = 0x82728940;
	sub_82732D90(ctx, base);
	// add r31,r3,r31
	r31.u64 = ctx.r3.u64 + r31.u64;
loc_82728944:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r27,20
	cr6.compare<int32_t>(r27.s32, 20, xer);
	// blt cr6,0x8272891c
	if (cr6.lt) goto loc_8272891C;
loc_82728954:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8272895C"))) PPC_WEAK_FUNC(sub_8272895C);
PPC_FUNC_IMPL(__imp__sub_8272895C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728960"))) PPC_WEAK_FUNC(sub_82728960);
PPC_FUNC_IMPL(__imp__sub_82728960) {
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
	ctx.lr = 0x82728968;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728990
	if (cr6.eq) goto loc_82728990;
	// bl 0x82732bd0
	ctx.lr = 0x8272898C;
	sub_82732BD0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82728990:
	// lwz r11,88(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827289dc
	if (cr6.eq) goto loc_827289DC;
	// li r27,0
	r27.s64 = 0;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
loc_827289A4:
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// bge cr6,0x827289dc
	if (!cr6.lt) goto loc_827289DC;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827289cc
	if (cr6.eq) goto loc_827289CC;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r31,r29
	ctx.r5.s64 = r29.s64 - r31.s64;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// bl 0x82732e20
	ctx.lr = 0x827289C8;
	sub_82732E20(ctx, base);
	// add r31,r3,r31
	r31.u64 = ctx.r3.u64 + r31.u64;
loc_827289CC:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r27,20
	cr6.compare<int32_t>(r27.s32, 20, xer);
	// blt cr6,0x827289a4
	if (cr6.lt) goto loc_827289A4;
loc_827289DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827289E4"))) PPC_WEAK_FUNC(sub_827289E4);
PPC_FUNC_IMPL(__imp__sub_827289E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827289E8"))) PPC_WEAK_FUNC(sub_827289E8);
PPC_FUNC_IMPL(__imp__sub_827289E8) {
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
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// bl 0x821a5cc0
	ctx.lr = 0x82728A08;
	sub_821A5CC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82728a18
	if (cr6.eq) goto loc_82728A18;
	// bl 0x821bbea8
	ctx.lr = 0x82728A18;
	sub_821BBEA8(ctx, base);
loc_82728A18:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x82728A20;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728a38
	if (cr6.eq) goto loc_82728A38;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82735510
	ctx.lr = 0x82728A30;
	sub_82735510(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82728a3c
	goto loc_82728A3C;
loc_82728A38:
	// li r31,0
	r31.s64 = 0;
loc_82728A3C:
	// bl 0x821a5cc0
	ctx.lr = 0x82728A40;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82728a50
	if (cr6.eq) goto loc_82728A50;
	// bl 0x821bbf00
	ctx.lr = 0x82728A50;
	sub_821BBF00(ctx, base);
loc_82728A50:
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

__attribute__((alias("__imp__sub_82728A68"))) PPC_WEAK_FUNC(sub_82728A68);
PPC_FUNC_IMPL(__imp__sub_82728A68) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x82728A80;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82728a90
	if (cr6.eq) goto loc_82728A90;
	// bl 0x821bbea8
	ctx.lr = 0x82728A90;
	sub_821BBEA8(ctx, base);
loc_82728A90:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82728ab0
	if (cr6.eq) goto loc_82728AB0;
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
	ctx.lr = 0x82728AB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82728AB0:
	// bl 0x821a5cc0
	ctx.lr = 0x82728AB4;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82728ac4
	if (cr6.eq) goto loc_82728AC4;
	// bl 0x821bbf00
	ctx.lr = 0x82728AC4;
	sub_821BBF00(ctx, base);
loc_82728AC4:
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

__attribute__((alias("__imp__sub_82728AD8"))) PPC_WEAK_FUNC(sub_82728AD8);
PPC_FUNC_IMPL(__imp__sub_82728AD8) {
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
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82728b2c
	if (!cr6.eq) goto loc_82728B2C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x82735580
	ctx.lr = 0x82728B10;
	sub_82735580(ctx, base);
	// lhz r9,30(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// li r11,-32768
	r11.s64 = -32768;
	// li r4,0
	ctx.r4.s64 = 0;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r8,30(r31)
	PPC_STORE_U16(r31.u32 + 30, ctx.r8.u16);
	// bl 0x82130000
	ctx.lr = 0x82728B2C;
	sub_82130000(ctx, base);
loc_82728B2C:
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

__attribute__((alias("__imp__sub_82728B40"))) PPC_WEAK_FUNC(sub_82728B40);
PPC_FUNC_IMPL(__imp__sub_82728B40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lis r9,21845
	ctx.r9.s64 = 1431633920;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// ori r7,r9,21846
	ctx.r7.u64 = ctx.r9.u64 | 21846;
	// mulhw r9,r8,r7
	ctx.r9.s64 = (int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32)) >> 32;
	// stw r11,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, r11.u32);
	// rlwinm r11,r9,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// subf r11,r6,r8
	r11.s64 = ctx.r8.s64 - ctx.r6.s64;
	// addi r5,r11,34
	ctx.r5.s64 = r11.s64 + 34;
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// addi r4,r11,37
	ctx.r4.s64 = r11.s64 + 37;
	// addi r9,r11,40
	ctx.r9.s64 = r11.s64 + 40;
	// addi r7,r11,46
	ctx.r7.s64 = r11.s64 + 46;
	// rlwinm r6,r5,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,43
	ctx.r8.s64 = r11.s64 + 43;
	// rlwinm r5,r4,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r6,r3
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, ctx.r10.u32);
	// stwx r10,r5,r3
	PPC_STORE_U32(ctx.r5.u32 + ctx.r3.u32, ctx.r10.u32);
	// stwx r10,r4,r3
	PPC_STORE_U32(ctx.r4.u32 + ctx.r3.u32, ctx.r10.u32);
	// stwx r10,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r10.u32);
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728BB4"))) PPC_WEAK_FUNC(sub_82728BB4);
PPC_FUNC_IMPL(__imp__sub_82728BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728BB8"))) PPC_WEAK_FUNC(sub_82728BB8);
PPC_FUNC_IMPL(__imp__sub_82728BB8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lfs f0,-19956(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19956);
	f0.f64 = double(temp.f32);
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// lfs f13,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82728c20
	if (!cr6.lt) goto loc_82728C20;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// rotlwi r10,r4,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// lwz r11,-23452(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23452);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// clrlwi r6,r7,30
	ctx.r6.u64 = ctx.r7.u32 & 0x3;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x82728c20
	if (!cr6.eq) goto loc_82728C20;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,-2288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// bl 0x82588d90
	ctx.lr = 0x82728C20;
	sub_82588D90(ctx, base);
loc_82728C20:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735580
	ctx.lr = 0x82728C2C;
	sub_82735580(ctx, base);
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

__attribute__((alias("__imp__sub_82728C44"))) PPC_WEAK_FUNC(sub_82728C44);
PPC_FUNC_IMPL(__imp__sub_82728C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728C48"))) PPC_WEAK_FUNC(sub_82728C48);
PPC_FUNC_IMPL(__imp__sub_82728C48) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17944);
	// bl 0x823057e8
	ctx.lr = 0x82728C68;
	sub_823057E8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,160(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82728C80;
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

__attribute__((alias("__imp__sub_82728C94"))) PPC_WEAK_FUNC(sub_82728C94);
PPC_FUNC_IMPL(__imp__sub_82728C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728C98"))) PPC_WEAK_FUNC(sub_82728C98);
PPC_FUNC_IMPL(__imp__sub_82728C98) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r31,0
	r31.s64 = 0;
	// addi r4,r11,13536
	ctx.r4.s64 = r11.s64 + 13536;
	// bl 0x823db730
	ctx.lr = 0x82728CB8;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x82728cc8
	if (cr6.eq) goto loc_82728CC8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82728CC8:
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

__attribute__((alias("__imp__sub_82728CDC"))) PPC_WEAK_FUNC(sub_82728CDC);
PPC_FUNC_IMPL(__imp__sub_82728CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728CE0"))) PPC_WEAK_FUNC(sub_82728CE0);
PPC_FUNC_IMPL(__imp__sub_82728CE0) {
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
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r11,-10404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10404);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82728d48
	if (!cr6.eq) goto loc_82728D48;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82728D08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728d2c
	if (cr6.eq) goto loc_82728D2C;
	// bl 0x82734040
	ctx.lr = 0x82728D14;
	sub_82734040(ctx, base);
	// stw r3,-10404(r31)
	PPC_STORE_U32(r31.u32 + -10404, ctx.r3.u32);
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
loc_82728D2C:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,-10404(r31)
	PPC_STORE_U32(r31.u32 + -10404, ctx.r3.u32);
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
loc_82728D48:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,-10404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10404);
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

__attribute__((alias("__imp__sub_82728D6C"))) PPC_WEAK_FUNC(sub_82728D6C);
PPC_FUNC_IMPL(__imp__sub_82728D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728D70"))) PPC_WEAK_FUNC(sub_82728D70);
PPC_FUNC_IMPL(__imp__sub_82728D70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21176);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728D7C"))) PPC_WEAK_FUNC(sub_82728D7C);
PPC_FUNC_IMPL(__imp__sub_82728D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728D80"))) PPC_WEAK_FUNC(sub_82728D80);
PPC_FUNC_IMPL(__imp__sub_82728D80) {
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
	// addi r10,r11,-19528
	ctx.r10.s64 = r11.s64 + -19528;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8275e048
	ctx.lr = 0x82728DAC;
	sub_8275E048(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82728dc4
	if (cr6.eq) goto loc_82728DC4;
	// bl 0x82130588
	ctx.lr = 0x82728DC0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82728DC4:
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

__attribute__((alias("__imp__sub_82728DDC"))) PPC_WEAK_FUNC(sub_82728DDC);
PPC_FUNC_IMPL(__imp__sub_82728DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728DE0"))) PPC_WEAK_FUNC(sub_82728DE0);
PPC_FUNC_IMPL(__imp__sub_82728DE0) {
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
	ctx.lr = 0x82728DE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82728e24
	if (!cr6.gt) goto loc_82728E24;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_82728E00:
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
	ctx.lr = 0x82728E18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x82728e00
	if (!cr0.eq) goto loc_82728E00;
loc_82728E24:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82728E2C;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82728E34"))) PPC_WEAK_FUNC(sub_82728E34);
PPC_FUNC_IMPL(__imp__sub_82728E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728E38"))) PPC_WEAK_FUNC(sub_82728E38);
PPC_FUNC_IMPL(__imp__sub_82728E38) {
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
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82728E4C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728e68
	if (cr6.eq) goto loc_82728E68;
	// bl 0x82728688
	ctx.lr = 0x82728E58;
	sub_82728688(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82728E68:
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

__attribute__((alias("__imp__sub_82728E7C"))) PPC_WEAK_FUNC(sub_82728E7C);
PPC_FUNC_IMPL(__imp__sub_82728E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728E80"))) PPC_WEAK_FUNC(sub_82728E80);
PPC_FUNC_IMPL(__imp__sub_82728E80) {
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
	// beq cr6,0x82728eac
	if (cr6.eq) goto loc_82728EAC;
	// bl 0x824905e0
	ctx.lr = 0x82728EA0;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-19592
	ctx.r10.s64 = r11.s64 + -19592;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82728EAC:
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

__attribute__((alias("__imp__sub_82728EC0"))) PPC_WEAK_FUNC(sub_82728EC0);
PPC_FUNC_IMPL(__imp__sub_82728EC0) {
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
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x82728ED4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728ef0
	if (cr6.eq) goto loc_82728EF0;
	// bl 0x8275d8d0
	ctx.lr = 0x82728EE0;
	sub_8275D8D0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82728EF0:
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

__attribute__((alias("__imp__sub_82728F04"))) PPC_WEAK_FUNC(sub_82728F04);
PPC_FUNC_IMPL(__imp__sub_82728F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82728F08"))) PPC_WEAK_FUNC(sub_82728F08);
PPC_FUNC_IMPL(__imp__sub_82728F08) {
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
	// beq cr6,0x82728f34
	if (cr6.eq) goto loc_82728F34;
	// bl 0x824905e0
	ctx.lr = 0x82728F28;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-19552
	ctx.r10.s64 = r11.s64 + -19552;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82728F34:
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

__attribute__((alias("__imp__sub_82728F48"))) PPC_WEAK_FUNC(sub_82728F48);
PPC_FUNC_IMPL(__imp__sub_82728F48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82728f88
	if (cr6.eq) goto loc_82728F88;
loc_82728F54:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r10,30(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 30);
	// rlwinm r9,r10,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82728f7c
	if (cr6.eq) goto loc_82728F7C;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// rlwinm r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_82728F7C:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82728f54
	if (!cr6.eq) goto loc_82728F54;
loc_82728F88:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82728F90"))) PPC_WEAK_FUNC(sub_82728F90);
PPC_FUNC_IMPL(__imp__sub_82728F90) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82728F98;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stw r26,424(r29)
	PPC_STORE_U32(r29.u32 + 424, r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827290e0
	if (cr6.eq) goto loc_827290E0;
	// lhz r11,16(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827290e0
	if (cr6.eq) goto loc_827290E0;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// mr r28,r26
	r28.u64 = r26.u64;
	// addi r25,r11,-19476
	r25.s64 = r11.s64 + -19476;
	// addi r24,r10,-19500
	r24.s64 = ctx.r10.s64 + -19500;
	// addi r27,r9,-19520
	r27.s64 = ctx.r9.s64 + -19520;
loc_82728FDC:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwzx r31,r10,r28
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827290c8
	if (cr6.eq) goto loc_827290C8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82729004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827290c8
	if (cr6.eq) goto loc_827290C8;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,408(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 408);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827290c8
	if (cr6.eq) goto loc_827290C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x82729024;
	sub_8248A510(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82729048
	if (cr6.eq) goto loc_82729048;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x8272903C;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x8272904c
	if (!cr6.eq) goto loc_8272904C;
loc_82729048:
	// lwz r4,176(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 176);
loc_8272904C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x82729054;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x8272905C;
	sub_8248A510(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82729080
	if (cr6.eq) goto loc_82729080;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x82729074;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x82729084
	if (!cr6.eq) goto loc_82729084;
loc_82729080:
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
loc_82729084:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x823db730
	ctx.lr = 0x8272908C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827290b0
	if (cr6.eq) goto loc_827290B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x8272909C;
	sub_8248A510(ctx, base);
	// bl 0x824896e8
	ctx.lr = 0x827290A0;
	sub_824896E8(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x823db730
	ctx.lr = 0x827290A8;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x827290c8
	if (!cr6.eq) goto loc_827290C8;
loc_827290B0:
	// lwz r11,424(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 424);
	// addi r10,r29,264
	ctx.r10.s64 = r29.s64 + 264;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,424(r29)
	PPC_STORE_U32(r29.u32 + 424, r11.u32);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
loc_827290C8:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// blt cr6,0x82728fdc
	if (cr6.lt) goto loc_82728FDC;
loc_827290E0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_827290E8"))) PPC_WEAK_FUNC(sub_827290E8);
PPC_FUNC_IMPL(__imp__sub_827290E8) {
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
	ctx.lr = 0x827290F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729158
	if (cr6.eq) goto loc_82729158;
	// lhz r11,16(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82729158
	if (!cr6.gt) goto loc_82729158;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82729118:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272914c
	if (cr6.eq) goto loc_8272914C;
	// lbz r11,145(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 145);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8272914c
	if (cr6.eq) goto loc_8272914C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 156);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272914C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272914C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82729118
	if (!cr0.eq) goto loc_82729118;
loc_82729158:
	// addi r30,r29,8
	r30.s64 = r29.s64 + 8;
	// li r29,20
	r29.s64 = 20;
loc_82729160:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827291bc
	if (cr6.eq) goto loc_827291BC;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827291bc
	if (cr6.eq) goto loc_827291BC;
loc_82729178:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827291b0
	if (cr6.eq) goto loc_827291B0;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827291b0
	if (cr6.eq) goto loc_827291B0;
	// lbz r11,145(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 145);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x827291b0
	if (cr6.eq) goto loc_827291B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 156);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827291B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827291B0:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82729178
	if (!cr6.eq) goto loc_82729178;
loc_827291BC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82729160
	if (!cr0.eq) goto loc_82729160;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827291D0"))) PPC_WEAK_FUNC(sub_827291D0);
PPC_FUNC_IMPL(__imp__sub_827291D0) {
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
	ctx.lr = 0x827291D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r28,r10,65535
	r28.u64 = ctx.r10.u64 | 65535;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729260
	if (cr6.eq) goto loc_82729260;
	// lhz r11,16(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82729260
	if (!cr6.gt) goto loc_82729260;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82729208:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwzx r11,r10,r31
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82729254
	if (cr6.eq) goto loc_82729254;
	// lbz r11,145(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 145);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82729254
	if (cr6.eq) goto loc_82729254;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// sth r28,8(r9)
	PPC_STORE_U16(ctx.r9.u32 + 8, r28.u16);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwzx r3,r7,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,160(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 160);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82729254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82729254:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82729208
	if (!cr0.eq) goto loc_82729208;
loc_82729260:
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// li r29,20
	r29.s64 = 20;
loc_82729268:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827292cc
	if (cr6.eq) goto loc_827292CC;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827292cc
	if (cr6.eq) goto loc_827292CC;
loc_82729280:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827292c0
	if (cr6.eq) goto loc_827292C0;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827292c0
	if (cr6.eq) goto loc_827292C0;
	// lbz r10,145(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 145);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x827292c0
	if (cr6.eq) goto loc_827292C0;
	// sth r28,8(r11)
	PPC_STORE_U16(r11.u32 + 8, r28.u16);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827292C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827292C0:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82729280
	if (!cr6.eq) goto loc_82729280;
loc_827292CC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82729268
	if (!cr0.eq) goto loc_82729268;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827292E0"))) PPC_WEAK_FUNC(sub_827292E0);
PPC_FUNC_IMPL(__imp__sub_827292E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,30(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 30);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// clrlwi r9,r11,17
	ctx.r9.u64 = r11.u32 & 0x7FFF;
	// sth r9,30(r4)
	PPC_STORE_U16(ctx.r4.u32 + 30, ctx.r9.u16);
	// lwz r3,-10404(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10404);
	// b 0x827349d8
	sub_827349D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827292F8"))) PPC_WEAK_FUNC(sub_827292F8);
PPC_FUNC_IMPL(__imp__sub_827292F8) {
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
	ctx.lr = 0x82729300;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r29,0
	r29.s64 = 0;
	// li r27,-1
	r27.s64 = -1;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// cmpwi cr6,r3,2048
	cr6.compare<int32_t>(ctx.r3.s32, 2048, xer);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// stw r27,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r27.u32);
	// bgt cr6,0x827293ac
	if (cr6.gt) goto loc_827293AC;
	// beq cr6,0x8272934c
	if (cr6.eq) goto loc_8272934C;
	// cmpwi cr6,r3,128
	cr6.compare<int32_t>(ctx.r3.s32, 128, xer);
	// bgt cr6,0x82729368
	if (cr6.gt) goto loc_82729368;
	// beq cr6,0x8272934c
	if (cr6.eq) goto loc_8272934C;
	// cmpwi cr6,r3,32
	cr6.compare<int32_t>(ctx.r3.s32, 32, xer);
	// beq cr6,0x8272934c
	if (cr6.eq) goto loc_8272934C;
	// cmpwi cr6,r3,64
	cr6.compare<int32_t>(ctx.r3.s32, 64, xer);
	// bne cr6,0x8272942c
	if (!cr6.eq) goto loc_8272942C;
loc_8272934C:
	// li r11,1
	r11.s64 = 1;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82729368:
	// cmpwi cr6,r3,256
	cr6.compare<int32_t>(ctx.r3.s32, 256, xer);
	// beq cr6,0x8272934c
	if (cr6.eq) goto loc_8272934C;
	// cmpwi cr6,r3,1024
	cr6.compare<int32_t>(ctx.r3.s32, 1024, xer);
	// bne cr6,0x8272942c
	if (!cr6.eq) goto loc_8272942C;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x82729384;
	sub_82205248(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827293d4
	if (cr6.eq) goto loc_827293D4;
	// li r11,1
	r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827293AC:
	// lis r11,4
	r11.s64 = 262144;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bgt cr6,0x827293e0
	if (cr6.gt) goto loc_827293E0;
	// beq cr6,0x827293d0
	if (cr6.eq) goto loc_827293D0;
	// cmpwi cr6,r3,4096
	cr6.compare<int32_t>(ctx.r3.s32, 4096, xer);
	// beq cr6,0x8272934c
	if (cr6.eq) goto loc_8272934C;
	// lis r11,2
	r11.s64 = 131072;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x8272942c
	if (!cr6.eq) goto loc_8272942C;
loc_827293D0:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_827293D4:
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827293E0:
	// lis r11,8
	r11.s64 = 524288;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// beq cr6,0x82729418
	if (cr6.eq) goto loc_82729418;
	// lis r11,16
	r11.s64 = 1048576;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x8272942c
	if (!cr6.eq) goto loc_8272942C;
	// li r11,1
	r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82729418:
	// li r11,2
	r11.s64 = 2;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_8272942C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82729434"))) PPC_WEAK_FUNC(sub_82729434);
PPC_FUNC_IMPL(__imp__sub_82729434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82729438"))) PPC_WEAK_FUNC(sub_82729438);
PPC_FUNC_IMPL(__imp__sub_82729438) {
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
	ctx.lr = 0x82729440;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9c0
	ctx.lr = 0x82729448;
	// addi r12,r1,-240
	r12.s64 = ctx.r1.s64 + -240;
	// bl 0x823dd52c
	ctx.lr = 0x82729450;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32112
	r30.s64 = -2104492032;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729a04
	if (cr6.eq) goto loc_82729A04;
	// lis r22,-32120
	r22.s64 = -2105016320;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-7572(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -7572);
	// lfs f0,17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lfs f13,14568(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14568);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14564(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14564);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f24,f13,f0
	f24.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fadds f23,f12,f0
	f23.f64 = double(float(ctx.f12.f64 + f0.f64));
	// bl 0x822f10d0
	ctx.lr = 0x82729490;
	sub_822F10D0(ctx, base);
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f1.f64;
	// lwz r30,44(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827294B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// std r8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f11,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f31,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// fdivs f30,f31,f9
	f30.f64 = double(float(f31.f64 / ctx.f9.f64));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827294E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// std r4,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r4.u64);
	// lfd f8,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// lis r14,-32124
	r14.s64 = -2105278464;
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// addi r19,r11,-31280
	r19.s64 = r11.s64 + -31280;
	// lwz r3,-26876(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + -26876);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// stw r19,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r19.u32);
	// fdivs f29,f31,f6
	f29.f64 = double(float(f31.f64 / ctx.f6.f64));
	// bl 0x8217c088
	ctx.lr = 0x82729518;
	sub_8217C088(ctx, base);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// clrlwi r3,r29,24
	ctx.r3.u64 = r29.u32 & 0xFF;
	// addi r10,r11,55
	ctx.r10.s64 = r11.s64 + 55;
	// addi r9,r11,40
	ctx.r9.s64 = r11.s64 + 40;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwzx r30,r8,r31
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwzx r31,r7,r31
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// beq cr6,0x82729720
	if (cr6.eq) goto loc_82729720;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x822f1160
	ctx.lr = 0x82729548;
	sub_822F1160(ctx, base);
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r9,48
	ctx.r9.s64 = 48;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// fmuls f29,f0,f29
	f29.f64 = double(float(f0.f64 * f29.f64));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lvx128 v62,r19,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// lvx128 v61,r19,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r19,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// fmuls f28,f13,f30
	f28.f64 = double(float(ctx.f13.f64 * f30.f64));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x827299f8
	if (!cr6.gt) goto loc_827299F8;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r21,r30
	r21.u64 = r30.u64;
	// mr r20,r31
	r20.u64 = r31.u64;
	// lfs f30,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f30.f64 = double(temp.f32);
	// lfs f31,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f31.f64 = double(temp.f32);
loc_827295B4:
	// lwz r31,0(r21)
	r31.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82729710
	if (cr6.eq) goto loc_82729710;
	// lwz r3,-7572(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x827295C8;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827296e4
	if (cr6.eq) goto loc_827296E4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827295E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bne cr6,0x827296e4
	if (!cr6.eq) goto loc_827296E4;
	// lwz r28,156(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x827296e4
	if (cr6.eq) goto loc_827296E4;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827296e4
	if (cr6.eq) goto loc_827296E4;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// addi r27,r31,64
	r27.s64 = r31.s64 + 64;
	// addi r26,r30,48
	r26.s64 = r30.s64 + 48;
	// addi r25,r30,16
	r25.s64 = r30.s64 + 16;
	// addi r24,r30,32
	r24.s64 = r30.s64 + 32;
	// li r29,0
	r29.s64 = 0;
loc_82729624:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r0,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v126,v62,v63
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v60,r0,r25
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v59,v62,v63
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v125,v60,v61
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lvx128 v123,r0,r27
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v58,v60,v61
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lvx128 v127,r11,r29
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lwz r3,-26876(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + -26876);
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// vmrghw128 v57,v126,v125
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// vmrghw128 v56,v59,v58
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmsum3fp128 v55,v127,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vmsum3fp128 v54,v127,v56
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vmrghw128 v124,v55,v54
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// bl 0x8217c088
	ctx.lr = 0x82729680;
	sub_8217C088(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x82729688;
	sub_8248A510(ctx, base);
	// lwz r11,348(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827296d0
	if (cr6.eq) goto loc_827296D0;
	// stfs f29,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stfs f28,124(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x821d2398
	ctx.lr = 0x827296A8;
	sub_821D2398(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// bl 0x822f1180
	ctx.lr = 0x827296B0;
	sub_822F1180(ctx, base);
	// vmrglw128 v53,v126,v125
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// vmsum3fp128 v52,v127,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmrghw128 v51,v52,v124
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v50,v124,v51
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v124.u32)));
	// vaddfp128 v1,v50,v123
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v123.f32)));
	// bl 0x822fb508
	ctx.lr = 0x827296D0;
	sub_822FB508(ctx, base);
loc_827296D0:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82729624
	if (cr6.lt) goto loc_82729624;
loc_827296E4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827296F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x82729710
	if (!cr6.eq) goto loc_82729710;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82739f70
	ctx.lr = 0x82729710;
	sub_82739F70(ctx, base);
loc_82729710:
	// addic. r20,r20,-1
	xer.ca = r20.u32 > 0;
	r20.s64 = r20.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// addi r21,r21,28
	r21.s64 = r21.s64 + 28;
	// bne 0x827295b4
	if (!cr0.eq) goto loc_827295B4;
	// b 0x827299f8
	goto loc_827299F8;
loc_82729720:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x827299f8
	if (!cr6.gt) goto loc_827299F8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f27,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f27.f64 = double(temp.f32);
	// lfs f28,3804(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3804);
	f28.f64 = double(temp.f32);
	// li r15,368
	r15.s64 = 368;
	// lfs f29,27632(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27632);
	f29.f64 = double(temp.f32);
	// lis r18,-32130
	r18.s64 = -2105671680;
	// lfs f30,21588(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 21588);
	f30.f64 = double(temp.f32);
	// lis r17,-32130
	r17.s64 = -2105671680;
	// lfs f25,-19448(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19448);
	f25.f64 = double(temp.f32);
	// lis r16,-32115
	r16.s64 = -2104688640;
	// addi r23,r11,9680
	r23.s64 = r11.s64 + 9680;
loc_82729770:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827299dc
	if (cr6.eq) goto loc_827299DC;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x822fe3a8
	ctx.lr = 0x82729788;
	sub_822FE3A8(ctx, base);
	// rlwinm r10,r31,0,24,27
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xF0;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f12,f25
	f0.f64 = double(float(ctx.f12.f64 * f25.f64));
	// fsubs f11,f24,f0
	ctx.f11.f64 = double(float(f24.f64 - f0.f64));
	// fcmpu cr6,f26,f11
	cr6.compare(f26.f64, ctx.f11.f64);
	// bgt cr6,0x827297bc
	if (cr6.gt) goto loc_827297BC;
	// fadds f0,f0,f23
	f0.f64 = double(float(f0.f64 + f23.f64));
	// li r11,0
	r11.s64 = 0;
	// fcmpu cr6,f26,f0
	cr6.compare(f26.f64, f0.f64);
	// bge cr6,0x827297c0
	if (!cr6.lt) goto loc_827297C0;
loc_827297BC:
	// li r11,1
	r11.s64 = 1;
loc_827297C0:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// lbz r10,393(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 393);
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827299b0
	if (cr6.eq) goto loc_827299B0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827297F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x82729814
	if (cr6.eq) goto loc_82729814;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272980C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x827299b0
	if (!cr6.eq) goto loc_827299B0;
loc_82729814:
	// lwz r22,156(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x827299b0
	if (cr6.eq) goto loc_827299B0;
	// lhz r11,4(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 4);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827299b0
	if (cr6.eq) goto loc_827299B0;
	// addi r25,r31,16
	r25.s64 = r31.s64 + 16;
	// addi r27,r31,64
	r27.s64 = r31.s64 + 64;
	// addi r21,r25,48
	r21.s64 = r25.s64 + 48;
	// addi r20,r25,16
	r20.s64 = r25.s64 + 16;
	// addi r19,r25,32
	r19.s64 = r25.s64 + 32;
	// li r30,0
	r30.s64 = 0;
	// li r24,0
	r24.s64 = 0;
loc_8272984C:
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r11,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r21
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r20
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r19
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r25
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v44,v48,v49
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v45,v46,v47
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrglw128 v43,v48,v49
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v42,v46,v47
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v41,v44,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrglw128 v40,v44,v45
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v39,v43,v42
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmsum3fp128 v38,v63,v41
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v41.f32), 0xEF));
	// vmsum3fp128 v37,v63,v40
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v40.f32), 0xEF));
	// vmsum3fp128 v36,v63,v39
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v39.f32), 0xEF));
	// vmrghw128 v35,v38,v36
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v34,v37,v35
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v63,v35,v34
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r0,r27
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v32,v63,v33
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v33.f32)));
	// stvx128 v32,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8248a510
	ctx.lr = 0x827298C0;
	sub_8248A510(ctx, base);
	// lwz r11,348(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729994
	if (cr6.eq) goto loc_82729994;
	// lwz r9,-26876(r14)
	ctx.r9.u64 = PPC_LOAD_U32(r14.u32 + -26876);
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,152(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lfs f13,4(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,19684(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 19684);
	// lfs f0,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lvx128 v62,r9,r15
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lwz r29,0(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stfs f13,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r28,0(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 - f30.f64));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f0.f64 = double(temp.f32);
	// fmadds f9,f0,f0,f11
	ctx.f9.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f8,f13,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fsubs f10,f12,f29
	ctx.f10.f64 = double(float(ctx.f12.f64 - f29.f64));
	// fsqrts f7,f8
	ctx.f7.f64 = double(float(sqrt(ctx.f8.f64)));
	// fsubs f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fmuls f5,f6,f28
	ctx.f5.f64 = double(float(ctx.f6.f64 * f28.f64));
	// fsel f4,f5,f5,f27
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f5.f64 : f27.f64;
	// fsubs f3,f4,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 - f31.f64));
	// fsel f2,f3,f31,f4
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? f31.f64 : ctx.f4.f64;
	// fsubs f22,f31,f2
	f22.f64 = double(float(f31.f64 - ctx.f2.f64));
	// bl 0x821d2398
	ctx.lr = 0x82729950;
	sub_821D2398(ctx, base);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lfs f0,8484(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r18.u32 + 8484);
	f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f2,8488(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + 8488);
	ctx.f2.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwzx r7,r29,r30
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// add r8,r26,r31
	ctx.r8.u64 = r26.u64 + r31.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// fmuls f1,f22,f0
	ctx.f1.f64 = double(float(f22.f64 * f0.f64));
	// lvx128 v1,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fc250
	ctx.lr = 0x82729980;
	sub_822FC250(ctx, base);
	// stwx r3,r28,r30
	PPC_STORE_U32(r28.u32 + r30.u32, ctx.r3.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lhz r3,146(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 146);
	// fmr f1,f22
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f22.f64;
	// bl 0x823029d0
	ctx.lr = 0x82729994;
	sub_823029D0(ctx, base);
loc_82729994:
	// lhz r11,4(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 4);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8272984c
	if (cr6.lt) goto loc_8272984C;
	// lwz r19,116(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
loc_827299B0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827299C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x827299dc
	if (!cr6.eq) goto loc_827299DC;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82739f70
	ctx.lr = 0x827299DC;
	sub_82739F70(ctx, base);
loc_827299DC:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r9,r10,28
	ctx.r9.s64 = ctx.r10.s64 + 28;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// bne 0x82729770
	if (!cr0.eq) goto loc_82729770;
loc_827299F8:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r3,-26876(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82729A04;
	sub_8217C088(ctx, base);
loc_82729A04:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// addi r12,r1,-240
	r12.s64 = ctx.r1.s64 + -240;
	// bl 0x823dd7c4
	ctx.lr = 0x82729A10;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba0c
	ctx.lr = 0x82729A18;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82729A1C"))) PPC_WEAK_FUNC(sub_82729A1C);
PPC_FUNC_IMPL(__imp__sub_82729A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82729A20"))) PPC_WEAK_FUNC(sub_82729A20);
PPC_FUNC_IMPL(__imp__sub_82729A20) {
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
	ctx.lr = 0x82729A28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82729a48
	if (!cr6.eq) goto loc_82729A48;
loc_82729A3C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82729A48:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82729A5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,9
	cr6.compare<int32_t>(r29.s32, 9, xer);
	// bne cr6,0x82729a74
	if (!cr6.eq) goto loc_82729A74;
	// lbz r11,160(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82729a3c
	if (!cr6.eq) goto loc_82729A3C;
loc_82729A74:
	// rlwinm r11,r30,0,11,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FFFFE;
	// rlwinm r11,r11,0,30,12
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFF80003;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729b00
	if (cr6.eq) goto loc_82729B00;
	// lis r11,8
	r11.s64 = 524288;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x82729aa4
	if (!cr6.eq) goto loc_82729AA4;
	// cmpwi cr6,r29,5
	cr6.compare<int32_t>(r29.s32, 5, xer);
	// bne cr6,0x82729aa4
	if (!cr6.eq) goto loc_82729AA4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// bl 0x82739d80
	ctx.lr = 0x82729AA4;
	sub_82739D80(ctx, base);
loc_82729AA4:
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x82729AB0;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729b00
	if (cr6.eq) goto loc_82729B00;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// beq cr6,0x82729aec
	if (cr6.eq) goto loc_82729AEC;
	// cmpwi cr6,r29,5
	cr6.compare<int32_t>(r29.s32, 5, xer);
	// beq cr6,0x82729aec
	if (cr6.eq) goto loc_82729AEC;
	// li r11,0
	r11.s64 = 0;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x822f3ba8
	ctx.lr = 0x82729AE0;
	sub_822F3BA8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82729AEC:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x822f3ba8
	ctx.lr = 0x82729B00;
	sub_822F3BA8(ctx, base);
loc_82729B00:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82729B0C"))) PPC_WEAK_FUNC(sub_82729B0C);
PPC_FUNC_IMPL(__imp__sub_82729B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82729B10"))) PPC_WEAK_FUNC(sub_82729B10);
PPC_FUNC_IMPL(__imp__sub_82729B10) {
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
	// li r3,1448
	ctx.r3.s64 = 1448;
	// bl 0x82130528
	ctx.lr = 0x82729B28;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82729b60
	if (cr6.eq) goto loc_82729B60;
	// bl 0x8275e518
	ctx.lr = 0x82729B38;
	sub_8275E518(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r11,-19528
	ctx.r9.s64 = r11.s64 + -19528;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,19684(r10)
	PPC_STORE_U32(ctx.r10.u32 + 19684, r31.u32);
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
loc_82729B60:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stw r11,19684(r10)
	PPC_STORE_U32(ctx.r10.u32 + 19684, r11.u32);
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

__attribute__((alias("__imp__sub_82729B80"))) PPC_WEAK_FUNC(sub_82729B80);
PPC_FUNC_IMPL(__imp__sub_82729B80) {
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
	ctx.lr = 0x82729B88;
	// stwu r1,-1712(r1)
	ea = -1712 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// sth r28,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, r28.u16);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// sth r28,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r28.u16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821e5fd0
	ctx.lr = 0x82729BBC;
	sub_821E5FD0(ctx, base);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// li r29,60
	r29.s64 = 60;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// stb r28,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r28.u8);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82729c28
	if (cr6.eq) goto loc_82729C28;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82733ba0
	ctx.lr = 0x82729C0C;
	sub_82733BA0(ctx, base);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
loc_82729C28:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r10,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82729C3C"))) PPC_WEAK_FUNC(sub_82729C3C);
PPC_FUNC_IMPL(__imp__sub_82729C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82729C40"))) PPC_WEAK_FUNC(sub_82729C40);
PPC_FUNC_IMPL(__imp__sub_82729C40) {
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
	// beq cr6,0x82729c6c
	if (cr6.eq) goto loc_82729C6C;
	// bl 0x824905e0
	ctx.lr = 0x82729C60;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-19612
	ctx.r10.s64 = r11.s64 + -19612;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82729C6C:
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

__attribute__((alias("__imp__sub_82729C80"))) PPC_WEAK_FUNC(sub_82729C80);
PPC_FUNC_IMPL(__imp__sub_82729C80) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82729C88;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stb r28,256(r29)
	PPC_STORE_U8(r29.u32 + 256, r28.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82729ca8
	if (cr6.eq) goto loc_82729CA8;
	// bl 0x82732cf8
	ctx.lr = 0x82729CA8;
	sub_82732CF8(ctx, base);
loc_82729CA8:
	// lwz r11,88(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82729cdc
	if (cr6.eq) goto loc_82729CDC;
	// addi r31,r29,8
	r31.s64 = r29.s64 + 8;
	// li r30,20
	r30.s64 = 20;
loc_82729CBC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82729cd0
	if (cr6.eq) goto loc_82729CD0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82732f30
	ctx.lr = 0x82729CD0;
	sub_82732F30(ctx, base);
loc_82729CD0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82729cbc
	if (!cr0.eq) goto loc_82729CBC;
loc_82729CDC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,156
	ctx.r5.s64 = 156;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x823d9890
	ctx.lr = 0x82729CF8;
	sub_823D9890(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82728960
	ctx.lr = 0x82729D08;
	sub_82728960(ctx, base);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82729d20
	if (cr6.eq) goto loc_82729D20;
	// li r11,0
	r11.s64 = 0;
	// stw r11,428(r29)
	PPC_STORE_U32(r29.u32 + 428, r11.u32);
	// stw r11,432(r29)
	PPC_STORE_U32(r29.u32 + 432, r11.u32);
loc_82729D20:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82729D28"))) PPC_WEAK_FUNC(sub_82729D28);
PPC_FUNC_IMPL(__imp__sub_82729D28) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82729D30;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lfs f0,-19444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19444);
	f0.f64 = double(temp.f32);
	// lfs f13,10504(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 10504);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 96, temp.u32);
	// stfs f13,100(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 100, temp.u32);
	// lwz r3,-4960(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4960);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82729d64
	if (cr6.eq) goto loc_82729D64;
	// bl 0x823c9950
	ctx.lr = 0x82729D64;
	sub_823C9950(ctx, base);
loc_82729D64:
	// lbz r11,256(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729d80
	if (cr6.eq) goto loc_82729D80;
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827288d8
	ctx.lr = 0x82729D80;
	sub_827288D8(ctx, base);
loc_82729D80:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,19620(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// bl 0x82475df8
	ctx.lr = 0x82729D8C;
	sub_82475DF8(ctx, base);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82729da8
	if (cr6.eq) goto loc_82729DA8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82729DA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82729DA8:
	// lwz r11,88(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82729de8
	if (cr6.eq) goto loc_82729DE8;
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// li r29,20
	r29.s64 = 20;
loc_82729DBC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729ddc
	if (cr6.eq) goto loc_82729DDC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82729DDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82729DDC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82729dbc
	if (!cr0.eq) goto loc_82729DBC;
loc_82729DE8:
	// lbz r11,256(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 256);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82729e08
	if (cr6.eq) goto loc_82729E08;
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82728960
	ctx.lr = 0x82729E04;
	sub_82728960(ctx, base);
	// b 0x82729e10
	goto loc_82729E10;
loc_82729E08:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82729c80
	ctx.lr = 0x82729E10;
	sub_82729C80(ctx, base);
loc_82729E10:
	// li r11,0
	r11.s64 = 0;
	// stw r11,260(r30)
	PPC_STORE_U32(r30.u32 + 260, r11.u32);
	// stw r11,428(r30)
	PPC_STORE_U32(r30.u32 + 428, r11.u32);
	// stw r11,432(r30)
	PPC_STORE_U32(r30.u32 + 432, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82729E28"))) PPC_WEAK_FUNC(sub_82729E28);
PPC_FUNC_IMPL(__imp__sub_82729E28) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82729E30;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8272a124
	if (cr6.eq) goto loc_8272A124;
	// addi r11,r26,16
	r11.s64 = r26.s64 + 16;
	// li r25,0
	r25.s64 = 0;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
loc_82729E64:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82729e7c
	if (cr6.gt) goto loc_82729E7C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82729e8c
	if (!cr6.eq) goto loc_82729E8C;
loc_82729E7C:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r25,3
	cr6.compare<int32_t>(r25.s32, 3, xer);
	// blt cr6,0x82729e64
	if (cr6.lt) goto loc_82729E64;
loc_82729E8C:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82729EA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r24,-1
	cr6.compare<int32_t>(r24.s32, -1, xer);
	// beq cr6,0x8272a124
	if (cr6.eq) goto loc_8272A124;
	// rlwinm r11,r24,0,28,28
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8272a124
	if (!cr6.eq) goto loc_8272A124;
	// addi r11,r25,16
	r11.s64 = r25.s64 + 16;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r26
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// lhz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8272a124
	if (cr6.eq) goto loc_8272A124;
	// lwz r29,128(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82729f2c
	if (cr6.eq) goto loc_82729F2C;
	// addi r11,r29,43
	r11.s64 = r29.s64 + 43;
	// addi r9,r29,61
	ctx.r9.s64 = r29.s64 + 61;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r11,r10,r31
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwzx r27,r7,r5
	r27.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// stwx r3,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r3.u32);
	// lwz r11,64(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 64);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r8,21(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 21);
	// clrlwi r5,r8,31
	ctx.r5.u64 = ctx.r8.u32 & 0x1;
	// bl 0x821a1848
	ctx.lr = 0x82729F2C;
	sub_821A1848(ctx, base);
loc_82729F2C:
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82729fb8
	if (!cr6.eq) goto loc_82729FB8;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82729fb8
	if (cr6.eq) goto loc_82729FB8;
	// addi r11,r29,46
	r11.s64 = r29.s64 + 46;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r31
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// cmpwi cr6,r11,155
	cr6.compare<int32_t>(r11.s32, 155, xer);
	// bge cr6,0x82729fb4
	if (!cr6.lt) goto loc_82729FB4;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82729fb4
	if (cr6.eq) goto loc_82729FB4;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r9,r29,58
	ctx.r9.s64 = r29.s64 + 58;
	// stwx r10,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, ctx.r10.u32);
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lwzx r11,r6,r31
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r28,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r30,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r28,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r28,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82729fb8
	goto loc_82729FB8;
loc_82729FB4:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_82729FB8:
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x82489da8
	ctx.lr = 0x82729FC0;
	sub_82489DA8(ctx, base);
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,124(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// sth r25,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, r25.u16);
	// sth r24,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, r24.u16);
	// beq cr6,0x8272a04c
	if (cr6.eq) goto loc_8272A04C;
	// addi r11,r29,34
	r11.s64 = r29.s64 + 34;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// cmpwi cr6,r11,155
	cr6.compare<int32_t>(r11.s32, 155, xer);
	// bge cr6,0x8272a04c
	if (!cr6.lt) goto loc_8272A04C;
	// addi r10,r29,49
	ctx.r10.s64 = r29.s64 + 49;
	// mulli r8,r11,28
	ctx.r8.s64 = r11.s64 * 28;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,7
	ctx.r9.s64 = 7;
	// lwzx r10,r6,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8272A02C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8272a02c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8272A02C;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, r11.u32);
loc_8272A04C:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8272a0b0
	if (cr6.eq) goto loc_8272A0B0;
	// addi r11,r29,37
	r11.s64 = r29.s64 + 37;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// cmpwi cr6,r11,155
	cr6.compare<int32_t>(r11.s32, 155, xer);
	// bge cr6,0x8272a0b0
	if (!cr6.lt) goto loc_8272A0B0;
	// addi r10,r29,52
	ctx.r10.s64 = r29.s64 + 52;
	// mulli r8,r11,28
	ctx.r8.s64 = r11.s64 * 28;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,7
	ctx.r9.s64 = 7;
	// lwzx r10,r6,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8272A090:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8272a090
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8272A090;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, r11.u32);
loc_8272A0B0:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// rlwinm r10,r11,0,26,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3E;
	// rlwinm r10,r10,0,30,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8272a118
	if (cr6.eq) goto loc_8272A118;
	// addi r11,r29,40
	r11.s64 = r29.s64 + 40;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// cmpwi cr6,r11,155
	cr6.compare<int32_t>(r11.s32, 155, xer);
	// bge cr6,0x8272a118
	if (!cr6.lt) goto loc_8272A118;
	// addi r10,r29,55
	ctx.r10.s64 = r29.s64 + 55;
	// mulli r8,r11,28
	ctx.r8.s64 = r11.s64 * 28;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,7
	ctx.r9.s64 = 7;
	// lwzx r10,r6,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8272A0F8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8272a0f8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8272A0F8;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, r11.u32);
loc_8272A118:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_8272A124:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8272A130"))) PPC_WEAK_FUNC(sub_8272A130);
PPC_FUNC_IMPL(__imp__sub_8272A130) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8272A138;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lbz r11,256(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272a2e8
	if (cr6.eq) goto loc_8272A2E8;
	// lwz r11,424(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 424);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8272a2e8
	if (!cr6.gt) goto loc_8272A2E8;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r27,r30,436
	r27.s64 = r30.s64 + 436;
	// li r24,1
	r24.s64 = 1;
	// lfs f30,-19440(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19440);
	f30.f64 = double(temp.f32);
	// lfs f31,14780(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14780);
	f31.f64 = double(temp.f32);
loc_8272A180:
	// lwz r31,-172(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + -172);
	// lfs f0,4(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r11,r26,27,5,31
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 27) & 0x7FFFFFF;
	// lfs f12,0(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi r10,r26,27
	ctx.r10.u64 = r26.u32 & 0x1F;
	// addi r9,r11,107
	ctx.r9.s64 = r11.s64 + 107;
	// lbz r11,257(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 257);
	// slw r28,r24,r10
	r28.u64 = ctx.r10.u8 & 0x20 ? 0 : (r24.u32 << (ctx.r10.u8 & 0x3F));
	// lfs f11,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r29,r9,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f9,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// lwzx r8,r29,r30
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// and r7,r28,r8
	ctx.r7.u64 = r28.u64 & ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f0,f6,f6,f4
	f0.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// beq cr6,0x8272a2a4
	if (cr6.eq) goto loc_8272A2A4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272a1ec
	if (cr6.eq) goto loc_8272A1EC;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8272a2d4
	if (!cr6.lt) goto loc_8272A2D4;
loc_8272A1EC:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x824a8e40
	ctx.lr = 0x8272A1F4;
	sub_824A8E40(ctx, base);
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// andc r10,r11,r28
	ctx.r10.u64 = r11.u64 & ~r28.u64;
	// stwx r10,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,232(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 232);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8272A214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lfs f1,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f1,416(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 416, temp.u32);
	// lwz r5,408(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 408);
	// lwz r4,412(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 412);
	// lwz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r28,276(r4)
	r28.u64 = PPC_LOAD_U32(ctx.r4.u32 + 276);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825031a8
	ctx.lr = 0x8272A244;
	sub_825031A8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272A258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825286e8
	ctx.lr = 0x8272A268;
	sub_825286E8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821b4de0
	ctx.lr = 0x8272A270;
	sub_821B4DE0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8272A28C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,188(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 188);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8272A2A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8272a2d4
	goto loc_8272A2D4;
loc_8272A2A4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272a2d4
	if (cr6.eq) goto loc_8272A2D4;
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8272a2d4
	if (!cr6.gt) goto loc_8272A2D4;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lfs f0,416(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 416);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x824a8f08
	ctx.lr = 0x8272A2C8;
	sub_824A8F08(ctx, base);
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// or r9,r28,r10
	ctx.r9.u64 = r28.u64 | ctx.r10.u64;
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
loc_8272A2D4:
	// lwz r11,424(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 424);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8272a180
	if (cr6.lt) goto loc_8272A180;
loc_8272A2E8:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-10404(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10404);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272a300
	if (cr6.eq) goto loc_8272A300;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82734db8
	ctx.lr = 0x8272A300;
	sub_82734DB8(ctx, base);
loc_8272A300:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8272A310"))) PPC_WEAK_FUNC(sub_8272A310);
PPC_FUNC_IMPL(__imp__sub_8272A310) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8272A318;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r29,308(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// rlwinm r11,r28,0,23,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x1F0;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8272a374
	if (cr6.eq) goto loc_8272A374;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,96
	ctx.r10.s64 = 96;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// lvx128 v1,r29,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c148
	ctx.lr = 0x8272A368;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272a4d0
	if (cr6.eq) goto loc_8272A4D0;
	// b 0x8272a390
	goto loc_8272A390;
loc_8272A374:
	// rlwinm r11,r28,0,19,19
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x1000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8272a390
	if (cr6.eq) goto loc_8272A390;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-29924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29924);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// bgt cr6,0x8272a4d0
	if (cr6.gt) goto loc_8272A4D0;
loc_8272A390:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8248a510
	ctx.lr = 0x8272A398;
	sub_8248A510(ctx, base);
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8272a3b8
	if (cr6.eq) goto loc_8272A3B8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// b 0x8272a3c0
	goto loc_8272A3C0;
loc_8272A3B8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f0,-8048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8048);
	f0.f64 = double(temp.f32);
loc_8272A3C0:
	// fsubs f13,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-22000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -22000);
	// fsel f12,f13,f13,f0
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8218aef8
	ctx.lr = 0x8272A3F0;
	sub_8218AEF8(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-8092(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// lwz r5,356(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 356);
	// bl 0x82729a20
	ctx.lr = 0x8272A408;
	sub_82729A20(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8272a4d0
	if (cr6.eq) goto loc_8272A4D0;
	// li r11,1
	r11.s64 = 1;
	// li r26,0
	r26.s64 = 0;
	// slw r30,r11,r31
	r30.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// cmpw cr6,r31,r25
	cr6.compare<int32_t>(r31.s32, r25.s32, xer);
	// bgt cr6,0x8272a4b0
	if (cr6.gt) goto loc_8272A4B0;
	// lwz r22,300(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// lwz r29,292(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
loc_8272A430:
	// cmpw cr6,r31,r21
	cr6.compare<int32_t>(r31.s32, r21.s32, xer);
	// beq cr6,0x8272a4a0
	if (cr6.eq) goto loc_8272A4A0;
	// and r11,r30,r22
	r11.u64 = r30.u64 & r22.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8272a4a0
	if (cr6.eq) goto loc_8272A4A0;
	// rlwinm r11,r28,0,17,20
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x7800;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8272a468
	if (!cr6.eq) goto loc_8272A468;
	// rlwinm r11,r28,0,19,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8272a480
	if (cr6.eq) goto loc_8272A480;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8272a480
	if (!cr6.gt) goto loc_8272A480;
loc_8272A468:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823112c0
	ctx.lr = 0x8272A47C;
	sub_823112C0(ctx, base);
	// li r26,1
	r26.s64 = 1;
loc_8272A480:
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,8(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x82613200
	ctx.lr = 0x8272A4A0;
	sub_82613200(ctx, base);
loc_8272A4A0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rlwinm r30,r30,1,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r31,r25
	cr6.compare<int32_t>(r31.s32, r25.s32, xer);
	// ble cr6,0x8272a430
	if (!cr6.gt) goto loc_8272A430;
loc_8272A4B0:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272a4d0
	if (cr6.eq) goto loc_8272A4D0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823112c0
	ctx.lr = 0x8272A4D0;
	sub_823112C0(ctx, base);
loc_8272A4D0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8272A4DC"))) PPC_WEAK_FUNC(sub_8272A4DC);
PPC_FUNC_IMPL(__imp__sub_8272A4DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272A4E0"))) PPC_WEAK_FUNC(sub_8272A4E0);
PPC_FUNC_IMPL(__imp__sub_8272A4E0) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17944);
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823057e8
	ctx.lr = 0x8272A504;
	sub_823057E8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r31,140(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735580
	ctx.lr = 0x8272A51C;
	sub_82735580(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735280
	ctx.lr = 0x8272A524;
	sub_82735280(ctx, base);
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

__attribute__((alias("__imp__sub_8272A538"))) PPC_WEAK_FUNC(sub_8272A538);
PPC_FUNC_IMPL(__imp__sub_8272A538) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17944);
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823057e8
	ctx.lr = 0x8272A55C;
	sub_823057E8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,16(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,160(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 160);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8272A574;
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

__attribute__((alias("__imp__sub_8272A588"))) PPC_WEAK_FUNC(sub_8272A588);
PPC_FUNC_IMPL(__imp__sub_8272A588) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272A5C0"))) PPC_WEAK_FUNC(sub_8272A5C0);
PPC_FUNC_IMPL(__imp__sub_8272A5C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82728830
	sub_82728830(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8272A5D4"))) PPC_WEAK_FUNC(sub_8272A5D4);
PPC_FUNC_IMPL(__imp__sub_8272A5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272A5D8"))) PPC_WEAK_FUNC(sub_8272A5D8);
PPC_FUNC_IMPL(__imp__sub_8272A5D8) {
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
	// bl 0x82728f48
	ctx.lr = 0x8272A5F8;
	sub_82728F48(ctx, base);
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

__attribute__((alias("__imp__sub_8272A614"))) PPC_WEAK_FUNC(sub_8272A614);
PPC_FUNC_IMPL(__imp__sub_8272A614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272A618"))) PPC_WEAK_FUNC(sub_8272A618);
PPC_FUNC_IMPL(__imp__sub_8272A618) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-4964(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4964);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272a6a0
	if (cr6.eq) goto loc_8272A6A0;
loc_8272A644:
	// lhz r11,16(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// lwz r10,260(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x8272a65c
	if (cr6.lt) goto loc_8272A65C;
	// bl 0x82729d28
	ctx.lr = 0x8272A658;
	sub_82729D28(ctx, base);
	// lwz r3,-4964(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4964);
loc_8272A65C:
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, ctx.r10.u32);
	// lwz r3,-4964(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4964);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r7,128(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// beq cr6,0x8272a694
	if (cr6.eq) goto loc_8272A694;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272a644
	if (!cr6.eq) goto loc_8272A644;
	// b 0x8272a6a0
	goto loc_8272A6A0;
loc_8272A694:
	// li r11,64
	r11.s64 = 64;
	// lvx128 v63,r10,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8272A6A0:
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

__attribute__((alias("__imp__sub_8272A6B8"))) PPC_WEAK_FUNC(sub_8272A6B8);
PPC_FUNC_IMPL(__imp__sub_8272A6B8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f11,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272A728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8272A744"))) PPC_WEAK_FUNC(sub_8272A744);
PPC_FUNC_IMPL(__imp__sub_8272A744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272A748"))) PPC_WEAK_FUNC(sub_8272A748);
PPC_FUNC_IMPL(__imp__sub_8272A748) {
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
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272A780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lhz r9,34(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 34);
	// addi r10,r31,28
	ctx.r10.s64 = r31.s64 + 28;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// sth r8,34(r31)
	PPC_STORE_U16(r31.u32 + 34, ctx.r8.u16);
	// stw r7,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r7.u32);
	// beq cr6,0x8272a7b8
	if (cr6.eq) goto loc_8272A7B8;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8272A7B8:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r31,20
	ctx.r8.s64 = r31.s64 + 20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272a7ec
	if (cr6.eq) goto loc_8272A7EC;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8272a7e4
	if (cr6.eq) goto loc_8272A7E4;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
loc_8272A7E4:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x8272a7f0
	goto loc_8272A7F0;
loc_8272A7EC:
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
loc_8272A7F0:
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
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

__attribute__((alias("__imp__sub_8272A80C"))) PPC_WEAK_FUNC(sub_8272A80C);
PPC_FUNC_IMPL(__imp__sub_8272A80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272A810"))) PPC_WEAK_FUNC(sub_8272A810);
PPC_FUNC_IMPL(__imp__sub_8272A810) {
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
	ctx.lr = 0x8272A818;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r11,r30,20
	r11.s64 = r30.s64 + 20;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x8272a83c
	if (!cr6.eq) goto loc_8272A83C;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_8272A83C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x8272a850
	if (!cr6.eq) goto loc_8272A850;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8272A850:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272a864
	if (cr6.eq) goto loc_8272A864;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8272A864:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272a878
	if (cr6.eq) goto loc_8272A878;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8272A878:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r29,16(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,160(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8272A8A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8272A8B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,40(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r11,r30,28
	r11.s64 = r30.s64 + 28;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stw r31,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r31.u32);
	// lhz r11,34(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 34);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,34(r30)
	PPC_STORE_U16(r30.u32 + 34, ctx.r4.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8272A8DC"))) PPC_WEAK_FUNC(sub_8272A8DC);
PPC_FUNC_IMPL(__imp__sub_8272A8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272A8E0"))) PPC_WEAK_FUNC(sub_8272A8E0);
PPC_FUNC_IMPL(__imp__sub_8272A8E0) {
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
	ctx.lr = 0x8272A8E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-19340
	ctx.r10.s64 = r11.s64 + -19340;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x82729d28
	ctx.lr = 0x8272A900;
	sub_82729D28(ctx, base);
	// li r29,2
	r29.s64 = 2;
	// addi r30,r28,252
	r30.s64 = r28.s64 + 252;
loc_8272A908:
	// li r31,0
	r31.s64 = 0;
loc_8272A90C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82130588
	ctx.lr = 0x8272A918;
	sub_82130588(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r31,640
	cr6.compare<int32_t>(r31.s32, 640, xer);
	// blt cr6,0x8272a90c
	if (cr6.lt) goto loc_8272A90C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8272A92C;
	sub_82130588(ctx, base);
	// lwz r3,-12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12);
	// bl 0x82130588
	ctx.lr = 0x8272A934;
	sub_82130588(ctx, base);
	// lwz r3,-36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -36);
	// bl 0x82130588
	ctx.lr = 0x8272A93C;
	sub_82130588(ctx, base);
	// lwz r3,-48(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -48);
	// bl 0x82130588
	ctx.lr = 0x8272A944;
	sub_82130588(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// bge 0x8272a908
	if (!cr0.lt) goto loc_8272A908;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272a9a0
	if (cr6.eq) goto loc_8272A9A0;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r30,40
	r30.s64 = 40;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// beq cr6,0x8272a98c
	if (cr6.eq) goto loc_8272A98C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272A98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272A98C:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// stw r10,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r10.u32);
loc_8272A9A0:
	// lbz r11,92(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8272a9e4
	if (!cr6.eq) goto loc_8272A9E4;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r11,-10404(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10404);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r3,-10404(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10404);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x8272a9e4
	if (!cr6.eq) goto loc_8272A9E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272A9E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272A9E4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,19620(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272aa08
	if (cr6.eq) goto loc_8272AA08;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272AA08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272AA08:
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r3,19684(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 19684);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272aa2c
	if (cr6.eq) goto loc_8272AA2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272AA2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272AA2C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,19684(r31)
	PPC_STORE_U32(r31.u32 + 19684, r11.u32);
	// bl 0x824a5500
	ctx.lr = 0x8272AA38;
	sub_824A5500(ctx, base);
	// bl 0x824d0108
	ctx.lr = 0x8272AA3C;
	sub_824D0108(ctx, base);
	// bl 0x824d0118
	ctx.lr = 0x8272AA40;
	sub_824D0118(ctx, base);
	// bl 0x824d00f8
	ctx.lr = 0x8272AA44;
	sub_824D00F8(ctx, base);
	// bl 0x82736c08
	ctx.lr = 0x8272AA48;
	sub_82736C08(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272aa6c
	if (cr6.eq) goto loc_8272AA6C;
	// bl 0x821bbea8
	ctx.lr = 0x8272AA68;
	sub_821BBEA8(ctx, base);
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
loc_8272AA6C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21184(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21184);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8272aa84
	if (cr6.eq) goto loc_8272AA84;
	// bl 0x821bfa90
	ctx.lr = 0x8272AA80;
	sub_821BFA90(ctx, base);
	// b 0x8272aa90
	goto loc_8272AA90;
loc_8272AA84:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-19408
	ctx.r3.s64 = r11.s64 + -19408;
	// bl 0x82130000
	ctx.lr = 0x8272AA90;
	sub_82130000(ctx, base);
loc_8272AA90:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272aa9c
	if (cr6.eq) goto loc_8272AA9C;
	// bl 0x821bbf00
	ctx.lr = 0x8272AA9C;
	sub_821BBF00(ctx, base);
loc_8272AA9C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2028
	ctx.lr = 0x8272AAA4;
	sub_821D2028(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8272AAAC"))) PPC_WEAK_FUNC(sub_8272AAAC);
PPC_FUNC_IMPL(__imp__sub_8272AAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272AAB0"))) PPC_WEAK_FUNC(sub_8272AAB0);
PPC_FUNC_IMPL(__imp__sub_8272AAB0) {
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
	ctx.lr = 0x8272AAB8;
	// stwu r1,-1264(r1)
	ea = -1264 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r27,r11,30576
	r27.s64 = r11.s64 + 30576;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r10,13612
	ctx.r4.s64 = ctx.r10.s64 + 13612;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821ca540
	ctx.lr = 0x8272AAE0;
	sub_821CA540(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x8272AAEC;
	sub_821CA540(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r5,r9,13604
	ctx.r5.s64 = ctx.r9.s64 + 13604;
	// addi r4,r8,19612
	ctx.r4.s64 = ctx.r8.s64 + 19612;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8272AB0C;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272AB18;
	sub_821C9A90(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272AB20;
	sub_821C9A90(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bne cr6,0x8272ab40
	if (!cr6.eq) goto loc_8272AB40;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,13560
	ctx.r3.s64 = r11.s64 + 13560;
	// bl 0x82130000
	ctx.lr = 0x8272AB38;
	sub_82130000(ctx, base);
	// addi r1,r1,1264
	ctx.r1.s64 = ctx.r1.s64 + 1264;
	// b 0x823d9244
	return;
loc_8272AB40:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d1ce8
	ctx.lr = 0x8272AB4C;
	sub_821D1CE8(ctx, base);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82732700
	ctx.lr = 0x8272AB64;
	sub_82732700(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x821be568
	ctx.lr = 0x8272AB7C;
	sub_821BE568(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x821d1ce8
	ctx.lr = 0x8272AB8C;
	sub_821D1CE8(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x8272AB94;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272aba8
	if (cr6.eq) goto loc_8272ABA8;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82733650
	ctx.lr = 0x8272ABA4;
	sub_82733650(ctx, base);
	// b 0x8272abac
	goto loc_8272ABAC;
loc_8272ABA8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8272ABAC:
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// li r6,256
	ctx.r6.s64 = 256;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,656
	ctx.r4.s64 = ctx.r1.s64 + 656;
	// bl 0x82733738
	ctx.lr = 0x8272ABC0;
	sub_82733738(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x8272ABC8;
	sub_821BE610(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,24576
	cr6.compare<int32_t>(r11.s32, 24576, xer);
	// ble cr6,0x8272abe4
	if (!cr6.gt) goto loc_8272ABE4;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,24576
	ctx.r4.s64 = 24576;
	// addi r3,r11,-19272
	ctx.r3.s64 = r11.s64 + -19272;
	// bl 0x82130000
	ctx.lr = 0x8272ABE4;
	sub_82130000(ctx, base);
loc_8272ABE4:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// ble cr6,0x8272ac00
	if (!cr6.gt) goto loc_8272AC00;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,512
	ctx.r4.s64 = 512;
	// addi r3,r11,-19336
	ctx.r3.s64 = r11.s64 + -19336;
	// bl 0x82130000
	ctx.lr = 0x8272AC00;
	sub_82130000(ctx, base);
loc_8272AC00:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-8892
	ctx.r10.s64 = r11.s64 + -8892;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272ac20
	if (cr6.eq) goto loc_8272AC20;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82729c80
	ctx.lr = 0x8272AC20;
	sub_82729C80(ctx, base);
loc_8272AC20:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82728f90
	ctx.lr = 0x8272AC28;
	sub_82728F90(ctx, base);
	// addi r1,r1,1264
	ctx.r1.s64 = ctx.r1.s64 + 1264;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8272AC30"))) PPC_WEAK_FUNC(sub_8272AC30);
PPC_FUNC_IMPL(__imp__sub_8272AC30) {
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
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8272ac84
	if (!cr6.eq) goto loc_8272AC84;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
loc_8272AC54:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8272ac54
	if (!cr6.eq) goto loc_8272AC54;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8272aab0
	ctx.lr = 0x8272AC70;
	sub_8272AAB0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8272AC84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272AC98"))) PPC_WEAK_FUNC(sub_8272AC98);
PPC_FUNC_IMPL(__imp__sub_8272AC98) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8272ACA0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r6,r1,136
	ctx.r6.s64 = ctx.r1.s64 + 136;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lwz r27,356(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 356);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827292f8
	ctx.lr = 0x8272ACC8;
	sub_827292F8(ctx, base);
	// lwz r26,128(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r25,132(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// cmpw cr6,r26,r25
	cr6.compare<int32_t>(r26.s32, r25.s32, xer);
	// bge cr6,0x8272ace4
	if (!cr6.lt) goto loc_8272ACE4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
loc_8272ACE4:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// rlwinm r9,r27,0,23,27
	ctx.r9.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r11,52
	ctx.r10.s64 = r11.s64 + 52;
	// bne cr6,0x8272acfc
	if (!cr6.eq) goto loc_8272ACFC;
	// addi r10,r11,49
	ctx.r10.s64 = r11.s64 + 49;
loc_8272ACFC:
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwzx r10,r8,r29
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	// beq cr6,0x8272ad14
	if (cr6.eq) goto loc_8272AD14;
	// addi r11,r11,37
	r11.s64 = r11.s64 + 37;
	// b 0x8272ad18
	goto loc_8272AD18;
loc_8272AD14:
	// addi r11,r11,34
	r11.s64 = r11.s64 + 34;
loc_8272AD18:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r24,r9,r29
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x8272ad84
	if (!cr6.gt) goto loc_8272AD84;
	// lwz r28,136(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r31,r10,20
	r31.s64 = ctx.r10.s64 + 20;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_8272AD34:
	// lwz r11,-20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lhz r23,-2(r31)
	r23.u64 = PPC_LOAD_U16(r31.u32 + -2);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// lhz r22,-4(r31)
	r22.u64 = PPC_LOAD_U16(r31.u32 + -4);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lfs f2,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r10,-8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// lwz r9,-12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -12);
	// lwz r8,-16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r23,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r23.u32);
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// bl 0x8272a310
	ctx.lr = 0x8272AD78;
	sub_8272A310(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// bne 0x8272ad34
	if (!cr0.eq) goto loc_8272AD34;
loc_8272AD84:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8272AD90"))) PPC_WEAK_FUNC(sub_8272AD90);
PPC_FUNC_IMPL(__imp__sub_8272AD90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// b 0x82729d28
	sub_82729D28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8272AD9C"))) PPC_WEAK_FUNC(sub_8272AD9C);
PPC_FUNC_IMPL(__imp__sub_8272AD9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272ADA0"))) PPC_WEAK_FUNC(sub_8272ADA0);
PPC_FUNC_IMPL(__imp__sub_8272ADA0) {
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
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// b 0x8272a618
	sub_8272A618(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8272ADFC"))) PPC_WEAK_FUNC(sub_8272ADFC);
PPC_FUNC_IMPL(__imp__sub_8272ADFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272AE00"))) PPC_WEAK_FUNC(sub_8272AE00);
PPC_FUNC_IMPL(__imp__sub_8272AE00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// bl 0x823d91f0
	ctx.lr = 0x8272AE08;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r3,-17944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17944);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x823057e8
	ctx.lr = 0x8272AE2C;
	sub_823057E8(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r26,r10,30576
	r26.s64 = ctx.r10.s64 + 30576;
	// addi r4,r9,-3312
	ctx.r4.s64 = ctx.r9.s64 + -3312;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821ca540
	ctx.lr = 0x8272AE44;
	sub_821CA540(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x8272AE50;
	sub_821CA540(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
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
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821b4b00
	ctx.lr = 0x8272AE90;
	sub_821B4B00(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vaddfp128 v56,v58,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8272a748
	ctx.lr = 0x8272AEBC;
	sub_8272A748(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272AEC8;
	sub_821C9A90(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272AED0;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8272AEDC"))) PPC_WEAK_FUNC(sub_8272AEDC);
PPC_FUNC_IMPL(__imp__sub_8272AEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272AEE0"))) PPC_WEAK_FUNC(sub_8272AEE0);
PPC_FUNC_IMPL(__imp__sub_8272AEE0) {
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
	ctx.lr = 0x8272AEE8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8272AEF8;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8272af80
	if (!cr6.gt) goto loc_8272AF80;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_8272AF10:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272af74
	if (cr6.eq) goto loc_8272AF74;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272af70
	if (cr6.eq) goto loc_8272AF70;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8272af70
	if (cr6.eq) goto loc_8272AF70;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8272AF44;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8272af70
	if (cr6.eq) goto loc_8272AF70;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8272AF58;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x82735f60
	ctx.lr = 0x8272AF6C;
	sub_82735F60(ctx, base);
	// b 0x8272af74
	goto loc_8272AF74;
loc_8272AF70:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_8272AF74:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8272af10
	if (!cr0.eq) goto loc_8272AF10;
loc_8272AF80:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8272AF8C"))) PPC_WEAK_FUNC(sub_8272AF8C);
PPC_FUNC_IMPL(__imp__sub_8272AF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272AF90"))) PPC_WEAK_FUNC(sub_8272AF90);
PPC_FUNC_IMPL(__imp__sub_8272AF90) {
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
	// lis r11,-32138
	r11.s64 = -2106195968;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-11432
	ctx.r5.s64 = r11.s64 + -11432;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x8272AFC0;
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
	// addi r5,r5,-25536
	ctx.r5.s64 = ctx.r5.s64 + -25536;
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
	ctx.lr = 0x8272B010;
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
	ctx.lr = 0x8272B054;
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

__attribute__((alias("__imp__sub_8272B068"))) PPC_WEAK_FUNC(sub_8272B068);
PPC_FUNC_IMPL(__imp__sub_8272B068) {
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
	// addi r5,r11,-29128
	ctx.r5.s64 = r11.s64 + -29128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x8272B098;
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
	// addi r5,r5,-29056
	ctx.r5.s64 = ctx.r5.s64 + -29056;
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
	ctx.lr = 0x8272B0E8;
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
	ctx.lr = 0x8272B12C;
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

__attribute__((alias("__imp__sub_8272B140"))) PPC_WEAK_FUNC(sub_8272B140);
PPC_FUNC_IMPL(__imp__sub_8272B140) {
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
	// addi r5,r11,-28992
	ctx.r5.s64 = r11.s64 + -28992;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x8272B170;
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
	// addi r5,r5,-28920
	ctx.r5.s64 = ctx.r5.s64 + -28920;
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
	ctx.lr = 0x8272B1C0;
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
	ctx.lr = 0x8272B204;
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

__attribute__((alias("__imp__sub_8272B218"))) PPC_WEAK_FUNC(sub_8272B218);
PPC_FUNC_IMPL(__imp__sub_8272B218) {
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
	ctx.lr = 0x8272B220;
	// stwu r1,-640(r1)
	ea = -640 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r29,0
	r29.s64 = 0;
	// addi r10,r11,-19340
	ctx.r10.s64 = r11.s64 + -19340;
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r10,r31,428
	ctx.r10.s64 = r31.s64 + 428;
	// stw r29,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r29.u32);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r29,428(r31)
	PPC_STORE_U32(r31.u32 + 428, r29.u32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// stw r29,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r29.u32);
	// stw r29,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r29.u32);
	// stw r29,604(r31)
	PPC_STORE_U32(r31.u32 + 604, r29.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8272B264:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8272b264
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8272B264;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r29,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r29.u32);
	// li r30,1
	r30.s64 = 1;
	// stb r29,104(r31)
	PPC_STORE_U8(r31.u32 + 104, r29.u8);
	// stw r29,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r29.u32);
	// li r3,1040
	ctx.r3.s64 = 1040;
	// stb r30,256(r31)
	PPC_STORE_U8(r31.u32 + 256, r30.u8);
	// lfs f0,11364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	f0.f64 = double(temp.f32);
	// stb r30,257(r31)
	PPC_STORE_U8(r31.u32 + 257, r30.u8);
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// stfs f0,120(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stw r29,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r29.u32);
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x8272B2B4;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8272b68c
	if (cr6.eq) goto loc_8272B68C;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-29544
	ctx.r5.s64 = r11.s64 + -29544;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x821d4268
	ctx.lr = 0x8272B2DC;
	sub_821D4268(ctx, base);
	// lis r10,-32209
	ctx.r10.s64 = -2110849024;
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// lis r7,-32141
	ctx.r7.s64 = -2106392576;
	// addi r8,r10,-13432
	ctx.r8.s64 = ctx.r10.s64 + -13432;
	// addi r10,r7,-25048
	ctx.r10.s64 = ctx.r7.s64 + -25048;
	// stw r8,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r8.u32);
	// addi r11,r1,544
	r11.s64 = ctx.r1.s64 + 544;
	// stw r10,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r10.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,244
	ctx.r6.s64 = ctx.r1.s64 + 244;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r27,12(r9)
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r27,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r27.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B334;
	sub_821D4268(ctx, base);
	// lis r8,-32184
	ctx.r8.s64 = -2109210624;
	// addi r11,r1,320
	r11.s64 = ctx.r1.s64 + 320;
	// addi r10,r8,-10648
	ctx.r10.s64 = ctx.r8.s64 + -10648;
	// lis r9,-32141
	ctx.r9.s64 = -2106392576;
	// stw r10,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r10.u32);
	// addi r8,r1,496
	ctx.r8.s64 = ctx.r1.s64 + 496;
	// addi r6,r9,-30104
	ctx.r6.s64 = ctx.r9.s64 + -30104;
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r6,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r6.u32);
	// addi r6,r1,260
	ctx.r6.s64 = ctx.r1.s64 + 260;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r27,12(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r27,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, r27.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B38C;
	sub_821D4268(ctx, base);
	// lis r10,-32184
	ctx.r10.s64 = -2109210624;
	// addi r9,r1,400
	ctx.r9.s64 = ctx.r1.s64 + 400;
	// lis r7,-32141
	ctx.r7.s64 = -2106392576;
	// addi r8,r10,-10648
	ctx.r8.s64 = ctx.r10.s64 + -10648;
	// addi r10,r7,-30232
	ctx.r10.s64 = ctx.r7.s64 + -30232;
	// stw r8,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, ctx.r8.u32);
	// addi r11,r1,528
	r11.s64 = ctx.r1.s64 + 528;
	// stw r10,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r10.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,252
	ctx.r6.s64 = ctx.r1.s64 + 252;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r27,12(r9)
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r27,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r27.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B3E4;
	sub_821D4268(ctx, base);
	// lis r8,-32184
	ctx.r8.s64 = -2109210624;
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// addi r4,r8,-10648
	ctx.r4.s64 = ctx.r8.s64 + -10648;
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// stw r4,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r4.u32);
	// addi r11,r1,560
	r11.s64 = ctx.r1.s64 + 560;
	// addi r8,r10,-29768
	ctx.r8.s64 = ctx.r10.s64 + -29768;
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r8,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r8.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,4(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// lwz r10,8(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,12(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B43C;
	sub_821D4268(ctx, base);
	// lis r7,-32184
	ctx.r7.s64 = -2109210624;
	// addi r11,r1,432
	r11.s64 = ctx.r1.s64 + 432;
	// addi r10,r7,-10648
	ctx.r10.s64 = ctx.r7.s64 + -10648;
	// lis r9,-32141
	ctx.r9.s64 = -2106392576;
	// stw r10,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r10.u32);
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// addi r6,r9,-27936
	ctx.r6.s64 = ctx.r9.s64 + -27936;
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r6,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r6.u32);
	// addi r6,r1,248
	ctx.r6.s64 = ctx.r1.s64 + 248;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r27,12(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r27,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, r27.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B494;
	sub_821D4268(ctx, base);
	// lis r10,-32184
	ctx.r10.s64 = -2109210624;
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// lis r7,-32141
	ctx.r7.s64 = -2106392576;
	// addi r8,r10,-10648
	ctx.r8.s64 = ctx.r10.s64 + -10648;
	// addi r10,r7,-29992
	ctx.r10.s64 = ctx.r7.s64 + -29992;
	// stw r8,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r8.u32);
	// addi r11,r1,336
	r11.s64 = ctx.r1.s64 + 336;
	// stw r10,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r10.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r27,12(r9)
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r27,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r27.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B4EC;
	sub_821D4268(ctx, base);
	// lis r8,-32184
	ctx.r8.s64 = -2109210624;
	// addi r11,r1,464
	r11.s64 = ctx.r1.s64 + 464;
	// addi r10,r8,-10648
	ctx.r10.s64 = ctx.r8.s64 + -10648;
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// stw r10,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r10.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// addi r5,r8,0
	ctx.r5.s64 = ctx.r8.s64 + 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r27,12(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// stw r27,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r27.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B53C;
	sub_821D4268(ctx, base);
	// lis r10,-32209
	ctx.r10.s64 = -2110849024;
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// addi r8,r10,-13432
	ctx.r8.s64 = ctx.r10.s64 + -13432;
	// stw r8,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r8.u32);
	// addi r11,r1,480
	r11.s64 = ctx.r1.s64 + 480;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lwz r27,8(r9)
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r26,12(r9)
	r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r5,r10,0
	ctx.r5.s64 = ctx.r10.s64 + 0;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// stw r27,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r27.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r26.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B58C;
	sub_821D4268(ctx, base);
	// lis r11,-32209
	r11.s64 = -2110849024;
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// addi r9,r11,-13432
	ctx.r9.s64 = r11.s64 + -13432;
	// addi r8,r1,512
	ctx.r8.s64 = ctx.r1.s64 + 512;
	// stw r9,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, ctx.r9.u32);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,0
	ctx.r5.s64 = ctx.r5.s64 + 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r27,12(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r10,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r27,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, r27.u32);
	// bl 0x821d4268
	ctx.lr = 0x8272B5DC;
	sub_821D4268(ctx, base);
	// lis r9,-32209
	ctx.r9.s64 = -2110849024;
	// stb r29,231(r1)
	PPC_STORE_U8(ctx.r1.u32 + 231, r29.u8);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r8,r9,-13432
	ctx.r8.s64 = ctx.r9.s64 + -13432;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r8,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r8.u32);
	// bl 0x823da950
	ctx.lr = 0x8272B5FC;
	sub_823DA950(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x823da950
	ctx.lr = 0x8272B60C;
	sub_823DA950(ctx, base);
	// li r7,128
	ctx.r7.s64 = 128;
	// li r6,160
	ctx.r6.s64 = 160;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// sth r7,190(r1)
	PPC_STORE_U16(ctx.r1.u32 + 190, ctx.r7.u16);
	// addi r4,r1,544
	ctx.r4.s64 = ctx.r1.s64 + 544;
	// stw r6,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r6.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x823da950
	ctx.lr = 0x8272B62C;
	sub_823DA950(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,496
	ctx.r4.s64 = ctx.r1.s64 + 496;
	// stw r29,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r29.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x823da950
	ctx.lr = 0x8272B640;
	sub_823DA950(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x823da950
	ctx.lr = 0x8272B650;
	sub_823DA950(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,560
	ctx.r4.s64 = ctx.r1.s64 + 560;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x823da950
	ctx.lr = 0x8272B660;
	sub_823DA950(ctx, base);
	// ld r11,312(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 312);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// ld r10,304(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 304);
	// ld r8,336(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 336);
	// ld r9,344(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 344);
	// ld r6,368(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 368);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// ld r7,376(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 376);
	// ld r4,272(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 272);
	// ld r5,280(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 280);
	// bl 0x82476b30
	ctx.lr = 0x8272B68C;
	sub_82476B30(ctx, base);
loc_8272B68C:
	// lis r28,-32115
	r28.s64 = -2104688640;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,-16385
	ctx.r9.s64 = -16385;
	// li r5,80
	ctx.r5.s64 = 80;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// lwz r11,19620(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// stb r30,778(r11)
	PPC_STORE_U8(r11.u32 + 778, r30.u8);
	// lwz r11,19620(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// stw r10,768(r11)
	PPC_STORE_U32(r11.u32 + 768, ctx.r10.u32);
	// lwz r11,19620(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// stw r9,772(r11)
	PPC_STORE_U32(r11.u32 + 772, ctx.r9.u32);
	// lwz r3,19620(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// bl 0x82475de0
	ctx.lr = 0x8272B6C0;
	sub_82475DE0(ctx, base);
	// li r5,60
	ctx.r5.s64 = 60;
	// lwz r3,19620(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// li r4,2048
	ctx.r4.s64 = 2048;
	// bl 0x82475de0
	ctx.lr = 0x8272B6D0;
	sub_82475DE0(ctx, base);
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// lwz r3,19620(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// bl 0x82475de0
	ctx.lr = 0x8272B6E0;
	sub_82475DE0(ctx, base);
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,5120
	ctx.r4.s64 = 5120;
	// lwz r3,19620(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// bl 0x82475de0
	ctx.lr = 0x8272B6F0;
	sub_82475DE0(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,7168
	ctx.r4.s64 = 7168;
	// lwz r3,19620(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// bl 0x82475de0
	ctx.lr = 0x8272B700;
	sub_82475DE0(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,8192
	ctx.r4.s64 = 8192;
	// lwz r3,19620(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 19620);
	// bl 0x82475de0
	ctx.lr = 0x8272B710;
	sub_82475DE0(ctx, base);
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,28
	r25.s64 = 28;
	// lwzx r3,r25,r26
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + r26.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8272B72C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r31,208
	r30.s64 = r31.s64 + 208;
	// li r27,3
	r27.s64 = 3;
loc_8272B734:
	// li r3,4368
	ctx.r3.s64 = 4368;
	// bl 0x82130528
	ctx.lr = 0x8272B73C;
	sub_82130528(ctx, base);
	// stw r3,-12(r30)
	PPC_STORE_U32(r30.u32 + -12, ctx.r3.u32);
	// li r3,4368
	ctx.r3.s64 = 4368;
	// bl 0x82130528
	ctx.lr = 0x8272B748;
	sub_82130528(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r3,4368
	ctx.r3.s64 = 4368;
	// bl 0x82130528
	ctx.lr = 0x8272B754;
	sub_82130528(ctx, base);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// li r3,9984
	ctx.r3.s64 = 9984;
	// bl 0x82130528
	ctx.lr = 0x8272B760;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,640
	ctx.r3.s64 = 640;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8272B770;
	sub_82130528(ctx, base);
	// stw r3,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r3.u32);
	// mr r28,r29
	r28.u64 = r29.u64;
loc_8272B778:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x821a15b8
	ctx.lr = 0x8272B780;
	sub_821A15B8(ctx, base);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// stwx r3,r28,r11
	PPC_STORE_U32(r28.u32 + r11.u32, ctx.r3.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r28,640
	cr6.compare<int32_t>(r28.s32, 640, xer);
	// blt cr6,0x8272b778
	if (cr6.lt) goto loc_8272B778;
	// stw r29,-72(r30)
	PPC_STORE_U32(r30.u32 + -72, r29.u32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// stw r29,-60(r30)
	PPC_STORE_U32(r30.u32 + -60, r29.u32);
	// stw r29,-48(r30)
	PPC_STORE_U32(r30.u32 + -48, r29.u32);
	// stw r29,-36(r30)
	PPC_STORE_U32(r30.u32 + -36, r29.u32);
	// stw r29,-24(r30)
	PPC_STORE_U32(r30.u32 + -24, r29.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8272b734
	if (!cr0.eq) goto loc_8272B734;
	// lwzx r3,r25,r26
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + r26.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272B7C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82729d28
	ctx.lr = 0x8272B7D0;
	sub_82729D28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8272B7DC"))) PPC_WEAK_FUNC(sub_8272B7DC);
PPC_FUNC_IMPL(__imp__sub_8272B7DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272B7E0"))) PPC_WEAK_FUNC(sub_8272B7E0);
PPC_FUNC_IMPL(__imp__sub_8272B7E0) {
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
	// bl 0x8272a8e0
	ctx.lr = 0x8272B800;
	sub_8272A8E0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272b818
	if (cr6.eq) goto loc_8272B818;
	// bl 0x82130588
	ctx.lr = 0x8272B814;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8272B818:
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

__attribute__((alias("__imp__sub_8272B830"))) PPC_WEAK_FUNC(sub_8272B830);
PPC_FUNC_IMPL(__imp__sub_8272B830) {
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
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272b870
	if (cr6.eq) goto loc_8272B870;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17944);
	// bl 0x823057e8
	ctx.lr = 0x8272B864;
	sub_823057E8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8272a810
	ctx.lr = 0x8272B870;
	sub_8272A810(ctx, base);
loc_8272B870:
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

__attribute__((alias("__imp__sub_8272B888"))) PPC_WEAK_FUNC(sub_8272B888);
PPC_FUNC_IMPL(__imp__sub_8272B888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-20992
	ctx.r3.s64 = r11.s64 + -20992;
	// b 0x8272a6b8
	sub_8272A6B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8272B898"))) PPC_WEAK_FUNC(sub_8272B898);
PPC_FUNC_IMPL(__imp__sub_8272B898) {
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
	// bl 0x823d91f0
	ctx.lr = 0x8272B8A0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
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
	// lwz r11,-4964(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8272b8d8
	if (!cr6.eq) goto loc_8272B8D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_8272B8D8:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17944);
	// bl 0x823057e8
	ctx.lr = 0x8272B8E4;
	sub_823057E8(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r26,r10,30576
	r26.s64 = ctx.r10.s64 + 30576;
	// addi r4,r9,-3312
	ctx.r4.s64 = ctx.r9.s64 + -3312;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821ca540
	ctx.lr = 0x8272B8FC;
	sub_821CA540(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x8272B908;
	sub_821CA540(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
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
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821b4b00
	ctx.lr = 0x8272B948;
	sub_821B4B00(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vaddfp128 v56,v58,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8272a748
	ctx.lr = 0x8272B974;
	sub_8272A748(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r30,140(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82735580
	ctx.lr = 0x8272B990;
	sub_82735580(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82735280
	ctx.lr = 0x8272B998;
	sub_82735280(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272B9A0;
	sub_821C9A90(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8272B9A8;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8272B9B4"))) PPC_WEAK_FUNC(sub_8272B9B4);
PPC_FUNC_IMPL(__imp__sub_8272B9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272B9B8"))) PPC_WEAK_FUNC(sub_8272B9B8);
PPC_FUNC_IMPL(__imp__sub_8272B9B8) {
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
	ctx.lr = 0x8272B9C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,100
	ctx.r3.s64 = 100;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82130528
	ctx.lr = 0x8272B9D8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272ba08
	if (cr6.eq) goto loc_8272BA08;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-19432
	ctx.r9.s64 = ctx.r10.s64 + -19432;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8272ba0c
	goto loc_8272BA0C;
loc_8272BA08:
	// li r31,0
	r31.s64 = 0;
loc_8272BA0C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272af90
	ctx.lr = 0x8272BA14;
	sub_8272AF90(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82490a08
	ctx.lr = 0x8272BA28;
	sub_82490A08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8272BA30"))) PPC_WEAK_FUNC(sub_8272BA30);
PPC_FUNC_IMPL(__imp__sub_8272BA30) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-19204
	ctx.r10.s64 = r11.s64 + -19204;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82590440
	ctx.lr = 0x8272BA64;
	sub_82590440(ctx, base);
	// sth r30,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r30.u16);
	// sth r30,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r30.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stb r30,39(r31)
	PPC_STORE_U8(r31.u32 + 39, r30.u8);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// sth r30,44(r31)
	PPC_STORE_U16(r31.u32 + 44, r30.u16);
	// sth r30,46(r31)
	PPC_STORE_U16(r31.u32 + 46, r30.u16);
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

__attribute__((alias("__imp__sub_8272BA9C"))) PPC_WEAK_FUNC(sub_8272BA9C);
PPC_FUNC_IMPL(__imp__sub_8272BA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272BAA0"))) PPC_WEAK_FUNC(sub_8272BAA0);
PPC_FUNC_IMPL(__imp__sub_8272BAA0) {
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
	ctx.lr = 0x8272BAA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8272BAC0;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8272baec
	if (!cr6.gt) goto loc_8272BAEC;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8272BAD0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272bae0
	if (cr6.eq) goto loc_8272BAE0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82590440
	ctx.lr = 0x8272BAE0;
	sub_82590440(ctx, base);
loc_8272BAE0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x8272bad0
	if (!cr0.eq) goto loc_8272BAD0;
loc_8272BAEC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8272BAF8"))) PPC_WEAK_FUNC(sub_8272BAF8);
PPC_FUNC_IMPL(__imp__sub_8272BAF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,44(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 44);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272BB04"))) PPC_WEAK_FUNC(sub_8272BB04);
PPC_FUNC_IMPL(__imp__sub_8272BB04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272BB08"))) PPC_WEAK_FUNC(sub_8272BB08);
PPC_FUNC_IMPL(__imp__sub_8272BB08) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82183870
	ctx.lr = 0x8272BB28;
	sub_82183870(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_8272BB30:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8272bb54
	if (cr6.eq) goto loc_8272BB54;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8272bb30
	if (cr6.eq) goto loc_8272BB30;
loc_8272BB54:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8272bb88
	if (cr6.eq) goto loc_8272BB88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x8258f990
	ctx.lr = 0x8272BB68;
	sub_8258F990(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272bb88
	if (cr6.eq) goto loc_8272BB88;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8272BB88:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272BBA0"))) PPC_WEAK_FUNC(sub_8272BBA0);
PPC_FUNC_IMPL(__imp__sub_8272BBA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x8272bbe0
	if (cr6.eq) goto loc_8272BBE0;
	// lhz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 44);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8272bbe0
	if (cr6.eq) goto loc_8272BBE0;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// li r9,20
	ctx.r9.s64 = 20;
	// subf r8,r11,r4
	ctx.r8.s64 = ctx.r4.s64 - r11.s64;
	// divw r11,r8,r9
	r11.s32 = ctx.r8.s32 / ctx.r9.s32;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8272bbd8
	if (cr6.gt) goto loc_8272BBD8;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
loc_8272BBD8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8272BBE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272BBE8"))) PPC_WEAK_FUNC(sub_8272BBE8);
PPC_FUNC_IMPL(__imp__sub_8272BBE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x8272bc18
	if (!cr6.gt) goto loc_8272BC18;
	// lhz r11,44(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 44);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bgt cr6,0x8272bc18
	if (cr6.gt) goto loc_8272BC18;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r11,-20
	ctx.r3.s64 = r11.s64 + -20;
	// blr 
	return;
loc_8272BC18:
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272BC20"))) PPC_WEAK_FUNC(sub_8272BC20);
PPC_FUNC_IMPL(__imp__sub_8272BC20) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82183870
	ctx.lr = 0x8272BC40;
	sub_82183870(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_8272BC48:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8272bc6c
	if (cr6.eq) goto loc_8272BC6C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8272bc48
	if (cr6.eq) goto loc_8272BC48;
loc_8272BC6C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8272bc8c
	if (!cr6.eq) goto loc_8272BC8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8272BC8C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x8258f990
	ctx.lr = 0x8272BC98;
	sub_8258F990(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272bcd0
	if (cr6.eq) goto loc_8272BCD0;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8272BCBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8272BCD0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272BCE8"))) PPC_WEAK_FUNC(sub_8272BCE8);
PPC_FUNC_IMPL(__imp__sub_8272BCE8) {
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
	ctx.lr = 0x8272BCF0;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-29924
	ctx.r8.s64 = ctx.r10.s64 + -29924;
	// stw r9,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r9.u32);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x8272BD24;
	sub_821CF7B8(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r7,-20156
	ctx.r4.s64 = ctx.r7.s64 + -20156;
	// bl 0x823db730
	ctx.lr = 0x8272BD34;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8272bd60
	if (!cr6.eq) goto loc_8272BD60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272BD58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9248
	return;
loc_8272BD60:
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8272BD7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,64(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272BD94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8272BD9C"))) PPC_WEAK_FUNC(sub_8272BD9C);
PPC_FUNC_IMPL(__imp__sub_8272BD9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272BDA0"))) PPC_WEAK_FUNC(sub_8272BDA0);
PPC_FUNC_IMPL(__imp__sub_8272BDA0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8272BDA8;
	// stwu r1,-1632(r1)
	ea = -1632 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r6,r10,3998
	ctx.r6.s64 = ctx.r10.s64 + 3998;
	// addi r24,r11,30576
	r24.s64 = r11.s64 + 30576;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// bl 0x821ca2f8
	ctx.lr = 0x8272BDDC;
	sub_821CA2F8(ctx, base);
	// addi r11,r1,480
	r11.s64 = ctx.r1.s64 + 480;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8272BDE4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8272bde4
	if (!cr6.eq) goto loc_8272BDE4;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// li r25,0
	r25.s64 = 0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8272be24
	if (!cr6.gt) goto loc_8272BE24;
	// addi r10,r1,480
	ctx.r10.s64 = ctx.r1.s64 + 480;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r10,46
	cr6.compare<uint32_t>(ctx.r10.u32, 46, xer);
	// bne cr6,0x8272be24
	if (!cr6.eq) goto loc_8272BE24;
	// stb r25,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r25.u8);
loc_8272BE24:
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r27,4
	ctx.r3.s64 = r27.s64 + 4;
	// bl 0x821d2a58
	ctx.lr = 0x8272BE30;
	sub_821D2A58(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r29,r11,19792
	r29.s64 = r11.s64 + 19792;
	// addi r5,r10,-24488
	ctx.r5.s64 = ctx.r10.s64 + -24488;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x821ca6a8
	ctx.lr = 0x8272BE54;
	sub_821CA6A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8272bfa8
	if (cr6.eq) goto loc_8272BFA8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r25,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, r25.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r10,r11,-29924
	ctx.r10.s64 = r11.s64 + -29924;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r10,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, ctx.r10.u32);
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cf7b8
	ctx.lr = 0x8272BE80;
	sub_821CF7B8(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cfaa8
	ctx.lr = 0x8272BE90;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272beb4
	if (cr6.eq) goto loc_8272BEB4;
loc_8272BE98:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x821cfaa8
	ctx.lr = 0x8272BEAC;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8272be98
	if (!cr6.eq) goto loc_8272BE98;
loc_8272BEB4:
	// clrlwi r3,r31,16
	ctx.r3.u64 = r31.u32 & 0xFFFF;
	// bl 0x821c9438
	ctx.lr = 0x8272BEBC;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r27,28
	ctx.r3.s64 = r27.s64 + 28;
	// bl 0x821bed68
	ctx.lr = 0x8272BEC8;
	sub_821BED68(ctx, base);
	// addi r30,r27,40
	r30.s64 = r27.s64 + 40;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272bee4
	if (cr6.eq) goto loc_8272BEE4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8272baa0
	ctx.lr = 0x8272BEE0;
	sub_8272BAA0(ctx, base);
	// b 0x8272bee8
	goto loc_8272BEE8;
loc_8272BEE4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_8272BEE8:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be568
	ctx.lr = 0x8272BEFC;
	sub_821BE568(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cf7b8
	ctx.lr = 0x8272BF0C;
	sub_821CF7B8(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cfaa8
	ctx.lr = 0x8272BF1C;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272bf98
	if (cr6.eq) goto loc_8272BF98;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r29,r10,19720
	r29.s64 = ctx.r10.s64 + 19720;
	// addi r30,r11,19716
	r30.s64 = r11.s64 + 19716;
loc_8272BF34:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca6a8
	ctx.lr = 0x8272BF4C;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272bf74
	if (cr6.eq) goto loc_8272BF74;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8272bce8
	ctx.lr = 0x8272BF68;
	sub_8272BCE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x8272BF70;
	sub_821BE610(ctx, base);
	// b 0x8272bf80
	goto loc_8272BF80;
loc_8272BF74:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82130000
	ctx.lr = 0x8272BF80;
	sub_82130000(ctx, base);
loc_8272BF80:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cfaa8
	ctx.lr = 0x8272BF90;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8272bf34
	if (!cr6.eq) goto loc_8272BF34;
loc_8272BF98:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x8272BFA0;
	sub_821BE610(ctx, base);
	// addi r1,r1,1632
	ctx.r1.s64 = ctx.r1.s64 + 1632;
	// b 0x823d9238
	return;
loc_8272BFA8:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x821cb488
	ctx.lr = 0x8272BFB4;
	sub_821CB488(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8272c178
	if (cr6.eq) goto loc_8272C178;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272BFD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x8272c178
	if (cr6.eq) goto loc_8272C178;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r26,r11,19716
	r26.s64 = r11.s64 + 19716;
loc_8272BFEC:
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x823db6d0
	ctx.lr = 0x8272BFF8;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c018
	if (cr6.eq) goto loc_8272C018;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bl 0x823db730
	ctx.lr = 0x8272C00C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8272c018
	if (!cr6.eq) goto loc_8272C018;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_8272C018:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272C034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8272bfec
	if (!cr6.eq) goto loc_8272BFEC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272C058;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r3,r31,16
	ctx.r3.u64 = r31.u32 & 0xFFFF;
	// bl 0x821c9438
	ctx.lr = 0x8272C060;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r27,28
	ctx.r3.s64 = r27.s64 + 28;
	// bl 0x821bed68
	ctx.lr = 0x8272C06C;
	sub_821BED68(ctx, base);
	// addi r30,r27,40
	r30.s64 = r27.s64 + 40;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272c088
	if (cr6.eq) goto loc_8272C088;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8272baa0
	ctx.lr = 0x8272C084;
	sub_8272BAA0(ctx, base);
	// b 0x8272c08c
	goto loc_8272C08C;
loc_8272C088:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_8272C08C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,96(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8272C0B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8272C0B4:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// bl 0x821ca6a8
	ctx.lr = 0x8272C0CC;
	sub_821CA6A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8272c130
	if (cr6.eq) goto loc_8272C130;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8272C0E0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8272c0e0
	if (!cr6.eq) goto loc_8272C0E0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,1296
	ctx.r3.s64 = ctx.r1.s64 + 1296;
	// rotlwi r31,r11,0
	r31.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r5,r31,-4
	ctx.r5.s64 = r31.s64 + -4;
	// bl 0x823db670
	ctx.lr = 0x8272C10C;
	sub_823DB670(ctx, base);
	// addi r11,r1,1296
	r11.s64 = ctx.r1.s64 + 1296;
	// addi r5,r1,1296
	ctx.r5.s64 = ctx.r1.s64 + 1296;
	// add r10,r31,r11
	ctx.r10.u64 = r31.u64 + r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r25,-4(r10)
	PPC_STORE_U8(ctx.r10.u32 + -4, r25.u8);
	// bl 0x8272bce8
	ctx.lr = 0x8272C128;
	sub_8272BCE8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x8272C130;
	sub_821BE610(ctx, base);
loc_8272C130:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272C14C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8272c0b4
	if (!cr6.eq) goto loc_8272C0B4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272C170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,1632
	ctx.r1.s64 = ctx.r1.s64 + 1632;
	// b 0x823d9238
	return;
loc_8272C178:
	// clrlwi r3,r31,16
	ctx.r3.u64 = r31.u32 & 0xFFFF;
	// bl 0x821c9438
	ctx.lr = 0x8272C180;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r27,28
	ctx.r3.s64 = r27.s64 + 28;
	// bl 0x821bed68
	ctx.lr = 0x8272C18C;
	sub_821BED68(ctx, base);
	// addi r30,r27,40
	r30.s64 = r27.s64 + 40;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8272c1b4
	if (cr6.eq) goto loc_8272C1B4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8272baa0
	ctx.lr = 0x8272C1A4;
	sub_8272BAA0(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// addi r1,r1,1632
	ctx.r1.s64 = ctx.r1.s64 + 1632;
	// b 0x823d9238
	return;
loc_8272C1B4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r1,r1,1632
	ctx.r1.s64 = ctx.r1.s64 + 1632;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8272C1C8"))) PPC_WEAK_FUNC(sub_8272C1C8);
PPC_FUNC_IMPL(__imp__sub_8272C1C8) {
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r11,44(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r8,44(r31)
	PPC_STORE_U16(r31.u32 + 44, ctx.r8.u16);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r10,r9
	r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bl 0x82183870
	ctx.lr = 0x8272C210;
	sub_82183870(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x824a5248
	ctx.lr = 0x8272C224;
	sub_824A5248(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// bl 0x8238d0d0
	ctx.lr = 0x8272C234;
	sub_8238D0D0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272C250"))) PPC_WEAK_FUNC(sub_8272C250);
PPC_FUNC_IMPL(__imp__sub_8272C250) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-18280
	ctx.r3.s64 = r11.s64 + -18280;
	// b 0x8272a6b8
	sub_8272A6B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8272C260"))) PPC_WEAK_FUNC(sub_8272C260);
PPC_FUNC_IMPL(__imp__sub_8272C260) {
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
	ctx.lr = 0x8272C268;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x8272C278;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-19128
	ctx.r10.s64 = r11.s64 + -19128;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r27,r31,16
	r27.s64 = r31.s64 + 16;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// addi r28,r31,24
	r28.s64 = r31.s64 + 24;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
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
	// beq cr6,0x8272c2c8
	if (cr6.eq) goto loc_8272C2C8;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8272C2C4;
	sub_82130528(ctx, base);
	// b 0x8272c2cc
	goto loc_8272C2CC;
loc_8272C2C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8272C2CC:
	// clrlwi r26,r29,16
	r26.u64 = r29.u32 & 0xFFFF;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r26,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r26.u16);
	// beq cr6,0x8272c300
	if (cr6.eq) goto loc_8272C300;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8272aee0
	ctx.lr = 0x8272C2EC;
	sub_8272AEE0(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r26,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r26.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8272C300:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r26,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r26.u16);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8272C318"))) PPC_WEAK_FUNC(sub_8272C318);
PPC_FUNC_IMPL(__imp__sub_8272C318) {
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
	ctx.lr = 0x8272C320;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-19128
	ctx.r10.s64 = r11.s64 + -19128;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8272c364
	if (cr6.eq) goto loc_8272C364;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x8272c364
	if (!cr0.eq) goto loc_8272C364;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272C364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272C364:
	// li r29,0
	r29.s64 = 0;
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// lhz r11,28(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c3b4
	if (cr6.eq) goto loc_8272C3B4;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8272C37C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c3a0
	if (cr6.eq) goto loc_8272C3A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8272C3A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8272C3A0:
	// lhz r11,28(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8272c37c
	if (cr6.lt) goto loc_8272C37C;
loc_8272C3B4:
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c3c8
	if (cr6.eq) goto loc_8272C3C8;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x8272C3C8;
	sub_82130588(ctx, base);
loc_8272C3C8:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c3dc
	if (cr6.eq) goto loc_8272C3DC;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8272C3DC;
	sub_82130588(ctx, base);
loc_8272C3DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x8272C3E4;
	sub_821D2810(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8272C3EC"))) PPC_WEAK_FUNC(sub_8272C3EC);
PPC_FUNC_IMPL(__imp__sub_8272C3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272C3F0"))) PPC_WEAK_FUNC(sub_8272C3F0);
PPC_FUNC_IMPL(__imp__sub_8272C3F0) {
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
	// bl 0x8272c318
	ctx.lr = 0x8272C410;
	sub_8272C318(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c428
	if (cr6.eq) goto loc_8272C428;
	// bl 0x82130588
	ctx.lr = 0x8272C424;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8272C428:
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

__attribute__((alias("__imp__sub_8272C440"))) PPC_WEAK_FUNC(sub_8272C440);
PPC_FUNC_IMPL(__imp__sub_8272C440) {
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x8272C458;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c46c
	if (cr6.eq) goto loc_8272C46C;
	// bl 0x8272ba30
	ctx.lr = 0x8272C464;
	sub_8272BA30(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8272c470
	goto loc_8272C470;
loc_8272C46C:
	// li r31,0
	r31.s64 = 0;
loc_8272C470:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r4,r10,-20156
	ctx.r4.s64 = ctx.r10.s64 + -20156;
	// stw r31,-23464(r11)
	PPC_STORE_U32(r11.u32 + -23464, r31.u32);
	// bl 0x8238d0d0
	ctx.lr = 0x8272C488;
	sub_8238D0D0(ctx, base);
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

__attribute__((alias("__imp__sub_8272C4A0"))) PPC_WEAK_FUNC(sub_8272C4A0);
PPC_FUNC_IMPL(__imp__sub_8272C4A0) {
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
	// addi r10,r11,-19204
	ctx.r10.s64 = r11.s64 + -19204;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r5,46(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8272c4e0
	if (cr6.eq) goto loc_8272C4E0;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82728de0
	ctx.lr = 0x8272C4E0;
	sub_82728DE0(ctx, base);
loc_8272C4E0:
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x8229d838
	ctx.lr = 0x8272C4E8;
	sub_8229D838(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82590238
	ctx.lr = 0x8272C4F0;
	sub_82590238(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256b4f8
	ctx.lr = 0x8272C4F8;
	sub_8256B4F8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8272c510
	if (cr6.eq) goto loc_8272C510;
	// bl 0x82130588
	ctx.lr = 0x8272C50C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8272C510:
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

__attribute__((alias("__imp__sub_8272C528"))) PPC_WEAK_FUNC(sub_8272C528);
PPC_FUNC_IMPL(__imp__sub_8272C528) {
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
	ctx.lr = 0x8272C530;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82733650
	ctx.lr = 0x8272C548;
	sub_82733650(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-19112
	ctx.r10.s64 = r11.s64 + -19112;
	// clrlwi r4,r28,16
	ctx.r4.u64 = r28.u32 & 0xFFFF;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// bl 0x8268b650
	ctx.lr = 0x8272C56C;
	sub_8268B650(ctx, base);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8272C574;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8272c598
	if (cr6.eq) goto loc_8272C598;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8272c260
	ctx.lr = 0x8272C584;
	sub_8272C260(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8272C598:
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8272C5A8"))) PPC_WEAK_FUNC(sub_8272C5A8);
PPC_FUNC_IMPL(__imp__sub_8272C5A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8272C5C8"))) PPC_WEAK_FUNC(sub_8272C5C8);
PPC_FUNC_IMPL(__imp__sub_8272C5C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8272C5CC"))) PPC_WEAK_FUNC(sub_8272C5CC);
PPC_FUNC_IMPL(__imp__sub_8272C5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272C5D0"))) PPC_WEAK_FUNC(sub_8272C5D0);
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

__attribute__((alias("__imp__sub_8272C620"))) PPC_WEAK_FUNC(sub_8272C620);
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

__attribute__((alias("__imp__sub_8272C6B0"))) PPC_WEAK_FUNC(sub_8272C6B0);
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

__attribute__((alias("__imp__sub_8272C840"))) PPC_WEAK_FUNC(sub_8272C840);
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

__attribute__((alias("__imp__sub_8272C89C"))) PPC_WEAK_FUNC(sub_8272C89C);
PPC_FUNC_IMPL(__imp__sub_8272C89C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272C8A0"))) PPC_WEAK_FUNC(sub_8272C8A0);
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

__attribute__((alias("__imp__sub_8272C970"))) PPC_WEAK_FUNC(sub_8272C970);
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

__attribute__((alias("__imp__sub_8272C9C0"))) PPC_WEAK_FUNC(sub_8272C9C0);
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

__attribute__((alias("__imp__sub_8272CA5C"))) PPC_WEAK_FUNC(sub_8272CA5C);
PPC_FUNC_IMPL(__imp__sub_8272CA5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272CA60"))) PPC_WEAK_FUNC(sub_8272CA60);
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

__attribute__((alias("__imp__sub_8272CE4C"))) PPC_WEAK_FUNC(sub_8272CE4C);
PPC_FUNC_IMPL(__imp__sub_8272CE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272CE50"))) PPC_WEAK_FUNC(sub_8272CE50);
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

__attribute__((alias("__imp__sub_8272CFA0"))) PPC_WEAK_FUNC(sub_8272CFA0);
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

__attribute__((alias("__imp__sub_8272CFE8"))) PPC_WEAK_FUNC(sub_8272CFE8);
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

__attribute__((alias("__imp__sub_8272D0E0"))) PPC_WEAK_FUNC(sub_8272D0E0);
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

__attribute__((alias("__imp__sub_8272D180"))) PPC_WEAK_FUNC(sub_8272D180);
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

__attribute__((alias("__imp__sub_8272D190"))) PPC_WEAK_FUNC(sub_8272D190);
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

__attribute__((alias("__imp__sub_8272D2D4"))) PPC_WEAK_FUNC(sub_8272D2D4);
PPC_FUNC_IMPL(__imp__sub_8272D2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272D2D8"))) PPC_WEAK_FUNC(sub_8272D2D8);
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

__attribute__((alias("__imp__sub_8272D340"))) PPC_WEAK_FUNC(sub_8272D340);
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

__attribute__((alias("__imp__sub_8272D36C"))) PPC_WEAK_FUNC(sub_8272D36C);
PPC_FUNC_IMPL(__imp__sub_8272D36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272D370"))) PPC_WEAK_FUNC(sub_8272D370);
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

__attribute__((alias("__imp__sub_8272D3D8"))) PPC_WEAK_FUNC(sub_8272D3D8);
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

__attribute__((alias("__imp__sub_8272D500"))) PPC_WEAK_FUNC(sub_8272D500);
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

__attribute__((alias("__imp__sub_8272D5EC"))) PPC_WEAK_FUNC(sub_8272D5EC);
PPC_FUNC_IMPL(__imp__sub_8272D5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272D5F0"))) PPC_WEAK_FUNC(sub_8272D5F0);
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

__attribute__((alias("__imp__sub_8272D934"))) PPC_WEAK_FUNC(sub_8272D934);
PPC_FUNC_IMPL(__imp__sub_8272D934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272D938"))) PPC_WEAK_FUNC(sub_8272D938);
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

__attribute__((alias("__imp__sub_8272DA30"))) PPC_WEAK_FUNC(sub_8272DA30);
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

__attribute__((alias("__imp__sub_8272DAE8"))) PPC_WEAK_FUNC(sub_8272DAE8);
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

__attribute__((alias("__imp__sub_8272DB24"))) PPC_WEAK_FUNC(sub_8272DB24);
PPC_FUNC_IMPL(__imp__sub_8272DB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272DB28"))) PPC_WEAK_FUNC(sub_8272DB28);
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

__attribute__((alias("__imp__sub_8272DB80"))) PPC_WEAK_FUNC(sub_8272DB80);
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

__attribute__((alias("__imp__sub_8272DC1C"))) PPC_WEAK_FUNC(sub_8272DC1C);
PPC_FUNC_IMPL(__imp__sub_8272DC1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272DC20"))) PPC_WEAK_FUNC(sub_8272DC20);
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

__attribute__((alias("__imp__sub_8272DD04"))) PPC_WEAK_FUNC(sub_8272DD04);
PPC_FUNC_IMPL(__imp__sub_8272DD04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272DD08"))) PPC_WEAK_FUNC(sub_8272DD08);
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

__attribute__((alias("__imp__sub_8272DDA8"))) PPC_WEAK_FUNC(sub_8272DDA8);
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

__attribute__((alias("__imp__sub_8272DE4C"))) PPC_WEAK_FUNC(sub_8272DE4C);
PPC_FUNC_IMPL(__imp__sub_8272DE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272DE50"))) PPC_WEAK_FUNC(sub_8272DE50);
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

__attribute__((alias("__imp__sub_8272E9B0"))) PPC_WEAK_FUNC(sub_8272E9B0);
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

__attribute__((alias("__imp__sub_8272EC04"))) PPC_WEAK_FUNC(sub_8272EC04);
PPC_FUNC_IMPL(__imp__sub_8272EC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272EC08"))) PPC_WEAK_FUNC(sub_8272EC08);
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

__attribute__((alias("__imp__sub_8272EDF8"))) PPC_WEAK_FUNC(sub_8272EDF8);
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

__attribute__((alias("__imp__sub_8272F000"))) PPC_WEAK_FUNC(sub_8272F000);
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

__attribute__((alias("__imp__sub_8272F30C"))) PPC_WEAK_FUNC(sub_8272F30C);
PPC_FUNC_IMPL(__imp__sub_8272F30C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272F310"))) PPC_WEAK_FUNC(sub_8272F310);
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

__attribute__((alias("__imp__sub_8272F4B0"))) PPC_WEAK_FUNC(sub_8272F4B0);
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

__attribute__((alias("__imp__sub_8272F540"))) PPC_WEAK_FUNC(sub_8272F540);
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

__attribute__((alias("__imp__sub_8272F5EC"))) PPC_WEAK_FUNC(sub_8272F5EC);
PPC_FUNC_IMPL(__imp__sub_8272F5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272F5F0"))) PPC_WEAK_FUNC(sub_8272F5F0);
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

__attribute__((alias("__imp__sub_8272F69C"))) PPC_WEAK_FUNC(sub_8272F69C);
PPC_FUNC_IMPL(__imp__sub_8272F69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272F6A0"))) PPC_WEAK_FUNC(sub_8272F6A0);
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

__attribute__((alias("__imp__sub_8272F750"))) PPC_WEAK_FUNC(sub_8272F750);
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

__attribute__((alias("__imp__sub_8272F7F8"))) PPC_WEAK_FUNC(sub_8272F7F8);
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

__attribute__((alias("__imp__sub_8272F878"))) PPC_WEAK_FUNC(sub_8272F878);
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

__attribute__((alias("__imp__sub_8272F908"))) PPC_WEAK_FUNC(sub_8272F908);
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

__attribute__((alias("__imp__sub_8272F9B8"))) PPC_WEAK_FUNC(sub_8272F9B8);
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

__attribute__((alias("__imp__sub_8272F9FC"))) PPC_WEAK_FUNC(sub_8272F9FC);
PPC_FUNC_IMPL(__imp__sub_8272F9FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272FA00"))) PPC_WEAK_FUNC(sub_8272FA00);
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

__attribute__((alias("__imp__sub_8272FA0C"))) PPC_WEAK_FUNC(sub_8272FA0C);
PPC_FUNC_IMPL(__imp__sub_8272FA0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272FA10"))) PPC_WEAK_FUNC(sub_8272FA10);
PPC_FUNC_IMPL(__imp__sub_8272FA10) {
	PPC_FUNC_PROLOGUE();
	// b 0x8248bf08
	sub_8248BF08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8272FA14"))) PPC_WEAK_FUNC(sub_8272FA14);
PPC_FUNC_IMPL(__imp__sub_8272FA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272FA18"))) PPC_WEAK_FUNC(sub_8272FA18);
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

__attribute__((alias("__imp__sub_8272FB60"))) PPC_WEAK_FUNC(sub_8272FB60);
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

__attribute__((alias("__imp__sub_8272FC94"))) PPC_WEAK_FUNC(sub_8272FC94);
PPC_FUNC_IMPL(__imp__sub_8272FC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8272FC98"))) PPC_WEAK_FUNC(sub_8272FC98);
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

__attribute__((alias("__imp__sub_8272FEE0"))) PPC_WEAK_FUNC(sub_8272FEE0);
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

__attribute__((alias("__imp__sub_8273014C"))) PPC_WEAK_FUNC(sub_8273014C);
PPC_FUNC_IMPL(__imp__sub_8273014C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82730150"))) PPC_WEAK_FUNC(sub_82730150);
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

__attribute__((alias("__imp__sub_8273022C"))) PPC_WEAK_FUNC(sub_8273022C);
PPC_FUNC_IMPL(__imp__sub_8273022C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82730230"))) PPC_WEAK_FUNC(sub_82730230);
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

__attribute__((alias("__imp__sub_82730424"))) PPC_WEAK_FUNC(sub_82730424);
PPC_FUNC_IMPL(__imp__sub_82730424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82730428"))) PPC_WEAK_FUNC(sub_82730428);
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

__attribute__((alias("__imp__sub_827309E8"))) PPC_WEAK_FUNC(sub_827309E8);
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

__attribute__((alias("__imp__sub_82730C88"))) PPC_WEAK_FUNC(sub_82730C88);
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

__attribute__((alias("__imp__sub_82730ECC"))) PPC_WEAK_FUNC(sub_82730ECC);
PPC_FUNC_IMPL(__imp__sub_82730ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82730ED0"))) PPC_WEAK_FUNC(sub_82730ED0);
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

__attribute__((alias("__imp__sub_827318F0"))) PPC_WEAK_FUNC(sub_827318F0);
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

__attribute__((alias("__imp__sub_82731CD4"))) PPC_WEAK_FUNC(sub_82731CD4);
PPC_FUNC_IMPL(__imp__sub_82731CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82731CD8"))) PPC_WEAK_FUNC(sub_82731CD8);
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

__attribute__((alias("__imp__sub_827322E4"))) PPC_WEAK_FUNC(sub_827322E4);
PPC_FUNC_IMPL(__imp__sub_827322E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827322E8"))) PPC_WEAK_FUNC(sub_827322E8);
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

__attribute__((alias("__imp__sub_827326FC"))) PPC_WEAK_FUNC(sub_827326FC);
PPC_FUNC_IMPL(__imp__sub_827326FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82732700"))) PPC_WEAK_FUNC(sub_82732700);
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

__attribute__((alias("__imp__sub_82732978"))) PPC_WEAK_FUNC(sub_82732978);
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

__attribute__((alias("__imp__sub_82732A1C"))) PPC_WEAK_FUNC(sub_82732A1C);
PPC_FUNC_IMPL(__imp__sub_82732A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82732A20"))) PPC_WEAK_FUNC(sub_82732A20);
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

__attribute__((alias("__imp__sub_82732AD4"))) PPC_WEAK_FUNC(sub_82732AD4);
PPC_FUNC_IMPL(__imp__sub_82732AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82732AD8"))) PPC_WEAK_FUNC(sub_82732AD8);
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

__attribute__((alias("__imp__sub_82732B24"))) PPC_WEAK_FUNC(sub_82732B24);
PPC_FUNC_IMPL(__imp__sub_82732B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82732B28"))) PPC_WEAK_FUNC(sub_82732B28);
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

__attribute__((alias("__imp__sub_82732BCC"))) PPC_WEAK_FUNC(sub_82732BCC);
PPC_FUNC_IMPL(__imp__sub_82732BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82732BD0"))) PPC_WEAK_FUNC(sub_82732BD0);
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

__attribute__((alias("__imp__sub_82732CF4"))) PPC_WEAK_FUNC(sub_82732CF4);
PPC_FUNC_IMPL(__imp__sub_82732CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82732CF8"))) PPC_WEAK_FUNC(sub_82732CF8);
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

__attribute__((alias("__imp__sub_82732D90"))) PPC_WEAK_FUNC(sub_82732D90);
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

__attribute__((alias("__imp__sub_82732E20"))) PPC_WEAK_FUNC(sub_82732E20);
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

__attribute__((alias("__imp__sub_82732F30"))) PPC_WEAK_FUNC(sub_82732F30);
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

__attribute__((alias("__imp__sub_82732FB4"))) PPC_WEAK_FUNC(sub_82732FB4);
PPC_FUNC_IMPL(__imp__sub_82732FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82732FB8"))) PPC_WEAK_FUNC(sub_82732FB8);
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

__attribute__((alias("__imp__sub_82733090"))) PPC_WEAK_FUNC(sub_82733090);
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

__attribute__((alias("__imp__sub_8273315C"))) PPC_WEAK_FUNC(sub_8273315C);
PPC_FUNC_IMPL(__imp__sub_8273315C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

