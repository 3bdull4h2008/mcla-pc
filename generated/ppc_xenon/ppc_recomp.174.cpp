#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827BAFC0"))) PPC_WEAK_FUNC(sub_827BAFC0);
PPC_FUNC_IMPL(__imp__sub_827BAFC0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22188
	r30.s64 = r31.s64 + 22188;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22188(r31)
	PPC_STORE_U32(r31.u32 + 22188, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BAFEC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAFF4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22188(r31)
	PPC_STORE_U32(r31.u32 + 22188, r11.u32);
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

__attribute__((alias("__imp__sub_827BB018"))) PPC_WEAK_FUNC(sub_827BB018);
PPC_FUNC_IMPL(__imp__sub_827BB018) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22540
	r30.s64 = r31.s64 + 22540;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22540(r31)
	PPC_STORE_U32(r31.u32 + 22540, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB044;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB04C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22540(r31)
	PPC_STORE_U32(r31.u32 + 22540, r11.u32);
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

__attribute__((alias("__imp__sub_827BB070"))) PPC_WEAK_FUNC(sub_827BB070);
PPC_FUNC_IMPL(__imp__sub_827BB070) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22348
	r30.s64 = r31.s64 + 22348;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22348(r31)
	PPC_STORE_U32(r31.u32 + 22348, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB09C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB0A4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22348(r31)
	PPC_STORE_U32(r31.u32 + 22348, r11.u32);
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

__attribute__((alias("__imp__sub_827BB0C8"))) PPC_WEAK_FUNC(sub_827BB0C8);
PPC_FUNC_IMPL(__imp__sub_827BB0C8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22124
	r30.s64 = r31.s64 + 22124;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22124(r31)
	PPC_STORE_U32(r31.u32 + 22124, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB0F4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB0FC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22124(r31)
	PPC_STORE_U32(r31.u32 + 22124, r11.u32);
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

__attribute__((alias("__imp__sub_827BB120"))) PPC_WEAK_FUNC(sub_827BB120);
PPC_FUNC_IMPL(__imp__sub_827BB120) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22252
	r30.s64 = r31.s64 + 22252;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22252(r31)
	PPC_STORE_U32(r31.u32 + 22252, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB14C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB154;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22252(r31)
	PPC_STORE_U32(r31.u32 + 22252, r11.u32);
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

__attribute__((alias("__imp__sub_827BB178"))) PPC_WEAK_FUNC(sub_827BB178);
PPC_FUNC_IMPL(__imp__sub_827BB178) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22060
	r30.s64 = r31.s64 + 22060;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22060(r31)
	PPC_STORE_U32(r31.u32 + 22060, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB1A4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB1AC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22060(r31)
	PPC_STORE_U32(r31.u32 + 22060, r11.u32);
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

__attribute__((alias("__imp__sub_827BB1D0"))) PPC_WEAK_FUNC(sub_827BB1D0);
PPC_FUNC_IMPL(__imp__sub_827BB1D0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22444
	r30.s64 = r31.s64 + 22444;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22444(r31)
	PPC_STORE_U32(r31.u32 + 22444, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB1FC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB204;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22444(r31)
	PPC_STORE_U32(r31.u32 + 22444, r11.u32);
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

__attribute__((alias("__imp__sub_827BB228"))) PPC_WEAK_FUNC(sub_827BB228);
PPC_FUNC_IMPL(__imp__sub_827BB228) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22284
	r30.s64 = r31.s64 + 22284;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22284(r31)
	PPC_STORE_U32(r31.u32 + 22284, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB254;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB25C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22284(r31)
	PPC_STORE_U32(r31.u32 + 22284, r11.u32);
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

__attribute__((alias("__imp__sub_827BB280"))) PPC_WEAK_FUNC(sub_827BB280);
PPC_FUNC_IMPL(__imp__sub_827BB280) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,22220
	r30.s64 = r31.s64 + 22220;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22220(r31)
	PPC_STORE_U32(r31.u32 + 22220, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB2AC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB2B4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22220(r31)
	PPC_STORE_U32(r31.u32 + 22220, r11.u32);
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

__attribute__((alias("__imp__sub_827BB2D8"))) PPC_WEAK_FUNC(sub_827BB2D8);
PPC_FUNC_IMPL(__imp__sub_827BB2D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r30,63
	r30.s64 = 63;
	// addi r11,r11,22584
	r11.s64 = r11.s64 + 22584;
	// addi r31,r11,7204
	r31.s64 = r11.s64 + 7204;
loc_827BB2FC:
	// addi r31,r31,-112
	r31.s64 = r31.s64 + -112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8252f840
	ctx.lr = 0x827BB308;
	sub_8252F840(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827bb2fc
	if (!cr0.lt) goto loc_827BB2FC;
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

__attribute__((alias("__imp__sub_827BB328"))) PPC_WEAK_FUNC(sub_827BB328);
PPC_FUNC_IMPL(__imp__sub_827BB328) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,29848
	r31.s64 = r11.s64 + 29848;
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bb354
	if (cr6.eq) goto loc_827BB354;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x827BB354;
	sub_82130588(ctx, base);
loc_827BB354:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a6030
	ctx.lr = 0x827BB35C;
	sub_824A6030(ctx, base);
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

__attribute__((alias("__imp__sub_827BB370"))) PPC_WEAK_FUNC(sub_827BB370);
PPC_FUNC_IMPL(__imp__sub_827BB370) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,29888
	r31.s64 = r11.s64 + 29888;
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bb39c
	if (cr6.eq) goto loc_827BB39C;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x827BB39C;
	sub_82130588(ctx, base);
loc_827BB39C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a6030
	ctx.lr = 0x827BB3A4;
	sub_824A6030(ctx, base);
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

__attribute__((alias("__imp__sub_827BB3B8"))) PPC_WEAK_FUNC(sub_827BB3B8);
PPC_FUNC_IMPL(__imp__sub_827BB3B8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,29868
	r31.s64 = r11.s64 + 29868;
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bb3e4
	if (cr6.eq) goto loc_827BB3E4;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x827BB3E4;
	sub_82130588(ctx, base);
loc_827BB3E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a6030
	ctx.lr = 0x827BB3EC;
	sub_824A6030(ctx, base);
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

__attribute__((alias("__imp__sub_827BB400"))) PPC_WEAK_FUNC(sub_827BB400);
PPC_FUNC_IMPL(__imp__sub_827BB400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r3,r11,-9628
	ctx.r3.s64 = r11.s64 + -9628;
	// b 0x821bbe30
	sub_821BBE30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BB40C"))) PPC_WEAK_FUNC(sub_827BB40C);
PPC_FUNC_IMPL(__imp__sub_827BB40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BB410"))) PPC_WEAK_FUNC(sub_827BB410);
PPC_FUNC_IMPL(__imp__sub_827BB410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,30036
	ctx.r3.s64 = r11.s64 + 30036;
	// b 0x82197448
	sub_82197448(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BB41C"))) PPC_WEAK_FUNC(sub_827BB41C);
PPC_FUNC_IMPL(__imp__sub_827BB41C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BB420"))) PPC_WEAK_FUNC(sub_827BB420);
PPC_FUNC_IMPL(__imp__sub_827BB420) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,30120
	ctx.r3.s64 = r11.s64 + 30120;
	// b 0x824fa9b0
	sub_824FA9B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BB42C"))) PPC_WEAK_FUNC(sub_827BB42C);
PPC_FUNC_IMPL(__imp__sub_827BB42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BB430"))) PPC_WEAK_FUNC(sub_827BB430);
PPC_FUNC_IMPL(__imp__sub_827BB430) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30340
	r30.s64 = r31.s64 + 30340;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30340(r31)
	PPC_STORE_U32(r31.u32 + 30340, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB45C;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB464;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30340(r31)
	PPC_STORE_U32(r31.u32 + 30340, r11.u32);
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

__attribute__((alias("__imp__sub_827BB488"))) PPC_WEAK_FUNC(sub_827BB488);
PPC_FUNC_IMPL(__imp__sub_827BB488) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30180
	r30.s64 = r31.s64 + 30180;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30180(r31)
	PPC_STORE_U32(r31.u32 + 30180, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB4B4;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB4BC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30180(r31)
	PPC_STORE_U32(r31.u32 + 30180, r11.u32);
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

__attribute__((alias("__imp__sub_827BB4E0"))) PPC_WEAK_FUNC(sub_827BB4E0);
PPC_FUNC_IMPL(__imp__sub_827BB4E0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30212
	r30.s64 = r31.s64 + 30212;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30212(r31)
	PPC_STORE_U32(r31.u32 + 30212, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB50C;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB514;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30212(r31)
	PPC_STORE_U32(r31.u32 + 30212, r11.u32);
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

__attribute__((alias("__imp__sub_827BB538"))) PPC_WEAK_FUNC(sub_827BB538);
PPC_FUNC_IMPL(__imp__sub_827BB538) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30404
	r30.s64 = r31.s64 + 30404;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30404(r31)
	PPC_STORE_U32(r31.u32 + 30404, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB564;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB56C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30404(r31)
	PPC_STORE_U32(r31.u32 + 30404, r11.u32);
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

__attribute__((alias("__imp__sub_827BB590"))) PPC_WEAK_FUNC(sub_827BB590);
PPC_FUNC_IMPL(__imp__sub_827BB590) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30244
	r30.s64 = r31.s64 + 30244;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30244(r31)
	PPC_STORE_U32(r31.u32 + 30244, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB5BC;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB5C4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30244(r31)
	PPC_STORE_U32(r31.u32 + 30244, r11.u32);
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

__attribute__((alias("__imp__sub_827BB5E8"))) PPC_WEAK_FUNC(sub_827BB5E8);
PPC_FUNC_IMPL(__imp__sub_827BB5E8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30308
	r30.s64 = r31.s64 + 30308;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30308(r31)
	PPC_STORE_U32(r31.u32 + 30308, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB614;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB61C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30308(r31)
	PPC_STORE_U32(r31.u32 + 30308, r11.u32);
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

__attribute__((alias("__imp__sub_827BB640"))) PPC_WEAK_FUNC(sub_827BB640);
PPC_FUNC_IMPL(__imp__sub_827BB640) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30148
	r30.s64 = r31.s64 + 30148;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30148(r31)
	PPC_STORE_U32(r31.u32 + 30148, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB66C;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB674;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30148(r31)
	PPC_STORE_U32(r31.u32 + 30148, r11.u32);
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

__attribute__((alias("__imp__sub_827BB698"))) PPC_WEAK_FUNC(sub_827BB698);
PPC_FUNC_IMPL(__imp__sub_827BB698) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30276
	r30.s64 = r31.s64 + 30276;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30276(r31)
	PPC_STORE_U32(r31.u32 + 30276, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB6C4;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB6CC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30276(r31)
	PPC_STORE_U32(r31.u32 + 30276, r11.u32);
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

__attribute__((alias("__imp__sub_827BB6F0"))) PPC_WEAK_FUNC(sub_827BB6F0);
PPC_FUNC_IMPL(__imp__sub_827BB6F0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,30372
	r30.s64 = r31.s64 + 30372;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30372(r31)
	PPC_STORE_U32(r31.u32 + 30372, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827BB71C;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB724;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30372(r31)
	PPC_STORE_U32(r31.u32 + 30372, r11.u32);
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

__attribute__((alias("__imp__sub_827BB748"))) PPC_WEAK_FUNC(sub_827BB748);
PPC_FUNC_IMPL(__imp__sub_827BB748) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,30480
	r30.s64 = r31.s64 + 30480;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30480(r31)
	PPC_STORE_U32(r31.u32 + 30480, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB774;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB77C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30480(r31)
	PPC_STORE_U32(r31.u32 + 30480, r11.u32);
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

__attribute__((alias("__imp__sub_827BB7A0"))) PPC_WEAK_FUNC(sub_827BB7A0);
PPC_FUNC_IMPL(__imp__sub_827BB7A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,30648
	r11.s64 = r11.s64 + 30648;
	// addi r31,r11,896
	r31.s64 = r11.s64 + 896;
loc_827BB7C4:
	// addi r31,r31,-224
	r31.s64 = r31.s64 + -224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534698
	ctx.lr = 0x827BB7D0;
	sub_82534698(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827bb7c4
	if (!cr0.lt) goto loc_827BB7C4;
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

__attribute__((alias("__imp__sub_827BB7F0"))) PPC_WEAK_FUNC(sub_827BB7F0);
PPC_FUNC_IMPL(__imp__sub_827BB7F0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32120
	r30.s64 = r31.s64 + 32120;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32120(r31)
	PPC_STORE_U32(r31.u32 + 32120, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB81C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB824;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32120(r31)
	PPC_STORE_U32(r31.u32 + 32120, r11.u32);
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

__attribute__((alias("__imp__sub_827BB848"))) PPC_WEAK_FUNC(sub_827BB848);
PPC_FUNC_IMPL(__imp__sub_827BB848) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31896
	r30.s64 = r31.s64 + 31896;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31896(r31)
	PPC_STORE_U32(r31.u32 + 31896, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB874;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB87C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31896(r31)
	PPC_STORE_U32(r31.u32 + 31896, r11.u32);
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

__attribute__((alias("__imp__sub_827BB8A0"))) PPC_WEAK_FUNC(sub_827BB8A0);
PPC_FUNC_IMPL(__imp__sub_827BB8A0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31960
	r30.s64 = r31.s64 + 31960;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31960(r31)
	PPC_STORE_U32(r31.u32 + 31960, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB8CC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB8D4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31960(r31)
	PPC_STORE_U32(r31.u32 + 31960, r11.u32);
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

__attribute__((alias("__imp__sub_827BB8F8"))) PPC_WEAK_FUNC(sub_827BB8F8);
PPC_FUNC_IMPL(__imp__sub_827BB8F8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31704
	r30.s64 = r31.s64 + 31704;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31704(r31)
	PPC_STORE_U32(r31.u32 + 31704, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB924;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB92C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31704(r31)
	PPC_STORE_U32(r31.u32 + 31704, r11.u32);
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

__attribute__((alias("__imp__sub_827BB950"))) PPC_WEAK_FUNC(sub_827BB950);
PPC_FUNC_IMPL(__imp__sub_827BB950) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31576
	r30.s64 = r31.s64 + 31576;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31576(r31)
	PPC_STORE_U32(r31.u32 + 31576, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB97C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB984;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31576(r31)
	PPC_STORE_U32(r31.u32 + 31576, r11.u32);
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

__attribute__((alias("__imp__sub_827BB9A8"))) PPC_WEAK_FUNC(sub_827BB9A8);
PPC_FUNC_IMPL(__imp__sub_827BB9A8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31800
	r30.s64 = r31.s64 + 31800;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31800(r31)
	PPC_STORE_U32(r31.u32 + 31800, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BB9D4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BB9DC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31800(r31)
	PPC_STORE_U32(r31.u32 + 31800, r11.u32);
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

__attribute__((alias("__imp__sub_827BBA00"))) PPC_WEAK_FUNC(sub_827BBA00);
PPC_FUNC_IMPL(__imp__sub_827BBA00) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,30580
	r30.s64 = r31.s64 + 30580;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30580(r31)
	PPC_STORE_U32(r31.u32 + 30580, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBA2C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBA34;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30580(r31)
	PPC_STORE_U32(r31.u32 + 30580, r11.u32);
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

__attribute__((alias("__imp__sub_827BBA58"))) PPC_WEAK_FUNC(sub_827BBA58);
PPC_FUNC_IMPL(__imp__sub_827BBA58) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32024
	r30.s64 = r31.s64 + 32024;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32024(r31)
	PPC_STORE_U32(r31.u32 + 32024, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBA84;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBA8C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32024(r31)
	PPC_STORE_U32(r31.u32 + 32024, r11.u32);
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

__attribute__((alias("__imp__sub_827BBAB0"))) PPC_WEAK_FUNC(sub_827BBAB0);
PPC_FUNC_IMPL(__imp__sub_827BBAB0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31608
	r30.s64 = r31.s64 + 31608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31608(r31)
	PPC_STORE_U32(r31.u32 + 31608, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBADC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBAE4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31608(r31)
	PPC_STORE_U32(r31.u32 + 31608, r11.u32);
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

__attribute__((alias("__imp__sub_827BBB08"))) PPC_WEAK_FUNC(sub_827BBB08);
PPC_FUNC_IMPL(__imp__sub_827BBB08) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32184
	r30.s64 = r31.s64 + 32184;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32184(r31)
	PPC_STORE_U32(r31.u32 + 32184, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBB34;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBB3C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32184(r31)
	PPC_STORE_U32(r31.u32 + 32184, r11.u32);
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

__attribute__((alias("__imp__sub_827BBB60"))) PPC_WEAK_FUNC(sub_827BBB60);
PPC_FUNC_IMPL(__imp__sub_827BBB60) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31544
	r30.s64 = r31.s64 + 31544;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31544(r31)
	PPC_STORE_U32(r31.u32 + 31544, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBB8C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBB94;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31544(r31)
	PPC_STORE_U32(r31.u32 + 31544, r11.u32);
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

__attribute__((alias("__imp__sub_827BBBB8"))) PPC_WEAK_FUNC(sub_827BBBB8);
PPC_FUNC_IMPL(__imp__sub_827BBBB8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31992
	r30.s64 = r31.s64 + 31992;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31992(r31)
	PPC_STORE_U32(r31.u32 + 31992, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBBE4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBBEC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31992(r31)
	PPC_STORE_U32(r31.u32 + 31992, r11.u32);
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

__attribute__((alias("__imp__sub_827BBC10"))) PPC_WEAK_FUNC(sub_827BBC10);
PPC_FUNC_IMPL(__imp__sub_827BBC10) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,30612
	r30.s64 = r31.s64 + 30612;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30612(r31)
	PPC_STORE_U32(r31.u32 + 30612, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBC3C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBC44;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30612(r31)
	PPC_STORE_U32(r31.u32 + 30612, r11.u32);
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

__attribute__((alias("__imp__sub_827BBC68"))) PPC_WEAK_FUNC(sub_827BBC68);
PPC_FUNC_IMPL(__imp__sub_827BBC68) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32152
	r30.s64 = r31.s64 + 32152;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32152(r31)
	PPC_STORE_U32(r31.u32 + 32152, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBC94;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBC9C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32152(r31)
	PPC_STORE_U32(r31.u32 + 32152, r11.u32);
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

__attribute__((alias("__imp__sub_827BBCC0"))) PPC_WEAK_FUNC(sub_827BBCC0);
PPC_FUNC_IMPL(__imp__sub_827BBCC0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32056
	r30.s64 = r31.s64 + 32056;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32056(r31)
	PPC_STORE_U32(r31.u32 + 32056, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBCEC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBCF4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32056(r31)
	PPC_STORE_U32(r31.u32 + 32056, r11.u32);
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

__attribute__((alias("__imp__sub_827BBD18"))) PPC_WEAK_FUNC(sub_827BBD18);
PPC_FUNC_IMPL(__imp__sub_827BBD18) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,30516
	r30.s64 = r31.s64 + 30516;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30516(r31)
	PPC_STORE_U32(r31.u32 + 30516, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBD44;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBD4C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30516(r31)
	PPC_STORE_U32(r31.u32 + 30516, r11.u32);
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

__attribute__((alias("__imp__sub_827BBD70"))) PPC_WEAK_FUNC(sub_827BBD70);
PPC_FUNC_IMPL(__imp__sub_827BBD70) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,30548
	r30.s64 = r31.s64 + 30548;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30548(r31)
	PPC_STORE_U32(r31.u32 + 30548, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBD9C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBDA4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,30548(r31)
	PPC_STORE_U32(r31.u32 + 30548, r11.u32);
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

__attribute__((alias("__imp__sub_827BBDC8"))) PPC_WEAK_FUNC(sub_827BBDC8);
PPC_FUNC_IMPL(__imp__sub_827BBDC8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31736
	r30.s64 = r31.s64 + 31736;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31736(r31)
	PPC_STORE_U32(r31.u32 + 31736, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBDF4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBDFC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31736(r31)
	PPC_STORE_U32(r31.u32 + 31736, r11.u32);
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

__attribute__((alias("__imp__sub_827BBE20"))) PPC_WEAK_FUNC(sub_827BBE20);
PPC_FUNC_IMPL(__imp__sub_827BBE20) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31640
	r30.s64 = r31.s64 + 31640;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31640(r31)
	PPC_STORE_U32(r31.u32 + 31640, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBE4C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBE54;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31640(r31)
	PPC_STORE_U32(r31.u32 + 31640, r11.u32);
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

__attribute__((alias("__imp__sub_827BBE78"))) PPC_WEAK_FUNC(sub_827BBE78);
PPC_FUNC_IMPL(__imp__sub_827BBE78) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31672
	r30.s64 = r31.s64 + 31672;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31672(r31)
	PPC_STORE_U32(r31.u32 + 31672, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBEA4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBEAC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31672(r31)
	PPC_STORE_U32(r31.u32 + 31672, r11.u32);
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

__attribute__((alias("__imp__sub_827BBED0"))) PPC_WEAK_FUNC(sub_827BBED0);
PPC_FUNC_IMPL(__imp__sub_827BBED0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32088
	r30.s64 = r31.s64 + 32088;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32088(r31)
	PPC_STORE_U32(r31.u32 + 32088, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBEFC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBF04;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32088(r31)
	PPC_STORE_U32(r31.u32 + 32088, r11.u32);
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

__attribute__((alias("__imp__sub_827BBF28"))) PPC_WEAK_FUNC(sub_827BBF28);
PPC_FUNC_IMPL(__imp__sub_827BBF28) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31832
	r30.s64 = r31.s64 + 31832;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31832(r31)
	PPC_STORE_U32(r31.u32 + 31832, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBF54;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBF5C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31832(r31)
	PPC_STORE_U32(r31.u32 + 31832, r11.u32);
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

__attribute__((alias("__imp__sub_827BBF80"))) PPC_WEAK_FUNC(sub_827BBF80);
PPC_FUNC_IMPL(__imp__sub_827BBF80) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31864
	r30.s64 = r31.s64 + 31864;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31864(r31)
	PPC_STORE_U32(r31.u32 + 31864, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BBFAC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BBFB4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31864(r31)
	PPC_STORE_U32(r31.u32 + 31864, r11.u32);
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

__attribute__((alias("__imp__sub_827BBFD8"))) PPC_WEAK_FUNC(sub_827BBFD8);
PPC_FUNC_IMPL(__imp__sub_827BBFD8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31768
	r30.s64 = r31.s64 + 31768;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31768(r31)
	PPC_STORE_U32(r31.u32 + 31768, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BC004;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC00C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31768(r31)
	PPC_STORE_U32(r31.u32 + 31768, r11.u32);
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

__attribute__((alias("__imp__sub_827BC030"))) PPC_WEAK_FUNC(sub_827BC030);
PPC_FUNC_IMPL(__imp__sub_827BC030) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,31928
	r30.s64 = r31.s64 + 31928;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31928(r31)
	PPC_STORE_U32(r31.u32 + 31928, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BC05C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC064;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,31928(r31)
	PPC_STORE_U32(r31.u32 + 31928, r11.u32);
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

__attribute__((alias("__imp__sub_827BC088"))) PPC_WEAK_FUNC(sub_827BC088);
PPC_FUNC_IMPL(__imp__sub_827BC088) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32332
	r30.s64 = r31.s64 + 32332;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32332(r31)
	PPC_STORE_U32(r31.u32 + 32332, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BC0B4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC0BC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32332(r31)
	PPC_STORE_U32(r31.u32 + 32332, r11.u32);
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

__attribute__((alias("__imp__sub_827BC0E0"))) PPC_WEAK_FUNC(sub_827BC0E0);
PPC_FUNC_IMPL(__imp__sub_827BC0E0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32300
	r30.s64 = r31.s64 + 32300;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32300(r31)
	PPC_STORE_U32(r31.u32 + 32300, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BC10C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC114;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32300(r31)
	PPC_STORE_U32(r31.u32 + 32300, r11.u32);
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

__attribute__((alias("__imp__sub_827BC138"))) PPC_WEAK_FUNC(sub_827BC138);
PPC_FUNC_IMPL(__imp__sub_827BC138) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32364
	r30.s64 = r31.s64 + 32364;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32364(r31)
	PPC_STORE_U32(r31.u32 + 32364, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BC164;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC16C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32364(r31)
	PPC_STORE_U32(r31.u32 + 32364, r11.u32);
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

__attribute__((alias("__imp__sub_827BC190"))) PPC_WEAK_FUNC(sub_827BC190);
PPC_FUNC_IMPL(__imp__sub_827BC190) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32396
	r30.s64 = r31.s64 + 32396;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32396(r31)
	PPC_STORE_U32(r31.u32 + 32396, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BC1BC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC1C4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32396(r31)
	PPC_STORE_U32(r31.u32 + 32396, r11.u32);
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

__attribute__((alias("__imp__sub_827BC1E8"))) PPC_WEAK_FUNC(sub_827BC1E8);
PPC_FUNC_IMPL(__imp__sub_827BC1E8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32428
	r30.s64 = r31.s64 + 32428;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32428(r31)
	PPC_STORE_U32(r31.u32 + 32428, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BC214;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC21C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32428(r31)
	PPC_STORE_U32(r31.u32 + 32428, r11.u32);
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

__attribute__((alias("__imp__sub_827BC240"))) PPC_WEAK_FUNC(sub_827BC240);
PPC_FUNC_IMPL(__imp__sub_827BC240) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,32468
	r30.s64 = r31.s64 + 32468;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32468(r31)
	PPC_STORE_U32(r31.u32 + 32468, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BC26C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC274;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32468(r31)
	PPC_STORE_U32(r31.u32 + 32468, r11.u32);
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

__attribute__((alias("__imp__sub_827BC298"))) PPC_WEAK_FUNC(sub_827BC298);
PPC_FUNC_IMPL(__imp__sub_827BC298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r3,r11,-992
	ctx.r3.s64 = r11.s64 + -992;
	// b 0x821bbe30
	sub_821BBE30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC2A4"))) PPC_WEAK_FUNC(sub_827BC2A4);
PPC_FUNC_IMPL(__imp__sub_827BC2A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC2A8"))) PPC_WEAK_FUNC(sub_827BC2A8);
PPC_FUNC_IMPL(__imp__sub_827BC2A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,32568
	ctx.r3.s64 = r11.s64 + 32568;
	// b 0x824fa9b0
	sub_824FA9B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC2B4"))) PPC_WEAK_FUNC(sub_827BC2B4);
PPC_FUNC_IMPL(__imp__sub_827BC2B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC2B8"))) PPC_WEAK_FUNC(sub_827BC2B8);
PPC_FUNC_IMPL(__imp__sub_827BC2B8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,32628
	r30.s64 = r31.s64 + 32628;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32628(r31)
	PPC_STORE_U32(r31.u32 + 32628, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC2E4;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC2EC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32628(r31)
	PPC_STORE_U32(r31.u32 + 32628, r11.u32);
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

__attribute__((alias("__imp__sub_827BC310"))) PPC_WEAK_FUNC(sub_827BC310);
PPC_FUNC_IMPL(__imp__sub_827BC310) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,32724
	r30.s64 = r31.s64 + 32724;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32724(r31)
	PPC_STORE_U32(r31.u32 + 32724, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC33C;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC344;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32724(r31)
	PPC_STORE_U32(r31.u32 + 32724, r11.u32);
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

__attribute__((alias("__imp__sub_827BC368"))) PPC_WEAK_FUNC(sub_827BC368);
PPC_FUNC_IMPL(__imp__sub_827BC368) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,32660
	r30.s64 = r31.s64 + 32660;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32660(r31)
	PPC_STORE_U32(r31.u32 + 32660, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC394;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC39C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32660(r31)
	PPC_STORE_U32(r31.u32 + 32660, r11.u32);
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

__attribute__((alias("__imp__sub_827BC3C0"))) PPC_WEAK_FUNC(sub_827BC3C0);
PPC_FUNC_IMPL(__imp__sub_827BC3C0) {
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
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,-32716
	r30.s64 = r31.s64 + -32716;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,-32716(r31)
	PPC_STORE_U32(r31.u32 + -32716, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC3EC;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC3F4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,-32716(r31)
	PPC_STORE_U32(r31.u32 + -32716, r11.u32);
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

__attribute__((alias("__imp__sub_827BC418"))) PPC_WEAK_FUNC(sub_827BC418);
PPC_FUNC_IMPL(__imp__sub_827BC418) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,32692
	r30.s64 = r31.s64 + 32692;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32692(r31)
	PPC_STORE_U32(r31.u32 + 32692, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC444;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC44C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32692(r31)
	PPC_STORE_U32(r31.u32 + 32692, r11.u32);
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

__attribute__((alias("__imp__sub_827BC470"))) PPC_WEAK_FUNC(sub_827BC470);
PPC_FUNC_IMPL(__imp__sub_827BC470) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,32596
	r30.s64 = r31.s64 + 32596;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32596(r31)
	PPC_STORE_U32(r31.u32 + 32596, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC49C;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC4A4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32596(r31)
	PPC_STORE_U32(r31.u32 + 32596, r11.u32);
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

__attribute__((alias("__imp__sub_827BC4C8"))) PPC_WEAK_FUNC(sub_827BC4C8);
PPC_FUNC_IMPL(__imp__sub_827BC4C8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,32756
	r30.s64 = r31.s64 + 32756;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32756(r31)
	PPC_STORE_U32(r31.u32 + 32756, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC4F4;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC4FC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,32756(r31)
	PPC_STORE_U32(r31.u32 + 32756, r11.u32);
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

__attribute__((alias("__imp__sub_827BC520"))) PPC_WEAK_FUNC(sub_827BC520);
PPC_FUNC_IMPL(__imp__sub_827BC520) {
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
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,-32684
	r30.s64 = r31.s64 + -32684;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,-32684(r31)
	PPC_STORE_U32(r31.u32 + -32684, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC54C;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC554;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,-32684(r31)
	PPC_STORE_U32(r31.u32 + -32684, r11.u32);
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

__attribute__((alias("__imp__sub_827BC578"))) PPC_WEAK_FUNC(sub_827BC578);
PPC_FUNC_IMPL(__imp__sub_827BC578) {
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
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,-32748
	r30.s64 = r31.s64 + -32748;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,-32748(r31)
	PPC_STORE_U32(r31.u32 + -32748, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827BC5A4;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BC5AC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,-32748(r31)
	PPC_STORE_U32(r31.u32 + -32748, r11.u32);
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

__attribute__((alias("__imp__sub_827BC5D0"))) PPC_WEAK_FUNC(sub_827BC5D0);
PPC_FUNC_IMPL(__imp__sub_827BC5D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-25536
	r11.s64 = r11.s64 + -25536;
	// stw r11,584(r10)
	PPC_STORE_U32(ctx.r10.u32 + 584, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC5E4"))) PPC_WEAK_FUNC(sub_827BC5E4);
PPC_FUNC_IMPL(__imp__sub_827BC5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC5E8"))) PPC_WEAK_FUNC(sub_827BC5E8);
PPC_FUNC_IMPL(__imp__sub_827BC5E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r11,r11,-32556
	r11.s64 = r11.s64 + -32556;
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC604"))) PPC_WEAK_FUNC(sub_827BC604);
PPC_FUNC_IMPL(__imp__sub_827BC604) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC608"))) PPC_WEAK_FUNC(sub_827BC608);
PPC_FUNC_IMPL(__imp__sub_827BC608) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r11,r11,-32544
	r11.s64 = r11.s64 + -32544;
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC624"))) PPC_WEAK_FUNC(sub_827BC624);
PPC_FUNC_IMPL(__imp__sub_827BC624) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC628"))) PPC_WEAK_FUNC(sub_827BC628);
PPC_FUNC_IMPL(__imp__sub_827BC628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32536
	ctx.r3.s64 = r11.s64 + -32536;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC634"))) PPC_WEAK_FUNC(sub_827BC634);
PPC_FUNC_IMPL(__imp__sub_827BC634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC638"))) PPC_WEAK_FUNC(sub_827BC638);
PPC_FUNC_IMPL(__imp__sub_827BC638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32520
	ctx.r3.s64 = r11.s64 + -32520;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC644"))) PPC_WEAK_FUNC(sub_827BC644);
PPC_FUNC_IMPL(__imp__sub_827BC644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC648"))) PPC_WEAK_FUNC(sub_827BC648);
PPC_FUNC_IMPL(__imp__sub_827BC648) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32504
	ctx.r3.s64 = r11.s64 + -32504;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC654"))) PPC_WEAK_FUNC(sub_827BC654);
PPC_FUNC_IMPL(__imp__sub_827BC654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC658"))) PPC_WEAK_FUNC(sub_827BC658);
PPC_FUNC_IMPL(__imp__sub_827BC658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32488
	ctx.r3.s64 = r11.s64 + -32488;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC664"))) PPC_WEAK_FUNC(sub_827BC664);
PPC_FUNC_IMPL(__imp__sub_827BC664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC668"))) PPC_WEAK_FUNC(sub_827BC668);
PPC_FUNC_IMPL(__imp__sub_827BC668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32472
	ctx.r3.s64 = r11.s64 + -32472;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC674"))) PPC_WEAK_FUNC(sub_827BC674);
PPC_FUNC_IMPL(__imp__sub_827BC674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC678"))) PPC_WEAK_FUNC(sub_827BC678);
PPC_FUNC_IMPL(__imp__sub_827BC678) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r11,r11,3780
	r11.s64 = r11.s64 + 3780;
	// addi r9,r10,-17020
	ctx.r9.s64 = ctx.r10.s64 + -17020;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827bc6ac
	if (cr6.eq) goto loc_827BC6AC;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
loc_827BC6AC:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r10,-30128
	ctx.r9.s64 = ctx.r10.s64 + -30128;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC6C4"))) PPC_WEAK_FUNC(sub_827BC6C4);
PPC_FUNC_IMPL(__imp__sub_827BC6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC6C8"))) PPC_WEAK_FUNC(sub_827BC6C8);
PPC_FUNC_IMPL(__imp__sub_827BC6C8) {
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
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lwz r3,-23584(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23584);
	// bl 0x82130588
	ctx.lr = 0x827BC6E4;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-23584(r31)
	PPC_STORE_U32(r31.u32 + -23584, r11.u32);
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

__attribute__((alias("__imp__sub_827BC700"))) PPC_WEAK_FUNC(sub_827BC700);
PPC_FUNC_IMPL(__imp__sub_827BC700) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r11,r11,-23608
	r11.s64 = r11.s64 + -23608;
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC71C"))) PPC_WEAK_FUNC(sub_827BC71C);
PPC_FUNC_IMPL(__imp__sub_827BC71C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC720"))) PPC_WEAK_FUNC(sub_827BC720);
PPC_FUNC_IMPL(__imp__sub_827BC720) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r11,r11,-23592
	r11.s64 = r11.s64 + -23592;
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC73C"))) PPC_WEAK_FUNC(sub_827BC73C);
PPC_FUNC_IMPL(__imp__sub_827BC73C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC740"))) PPC_WEAK_FUNC(sub_827BC740);
PPC_FUNC_IMPL(__imp__sub_827BC740) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r11,r11,-23600
	r11.s64 = r11.s64 + -23600;
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC75C"))) PPC_WEAK_FUNC(sub_827BC75C);
PPC_FUNC_IMPL(__imp__sub_827BC75C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC760"))) PPC_WEAK_FUNC(sub_827BC760);
PPC_FUNC_IMPL(__imp__sub_827BC760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23548
	ctx.r3.s64 = r11.s64 + -23548;
	// b 0x821d2aa0
	sub_821D2AA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC76C"))) PPC_WEAK_FUNC(sub_827BC76C);
PPC_FUNC_IMPL(__imp__sub_827BC76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC770"))) PPC_WEAK_FUNC(sub_827BC770);
PPC_FUNC_IMPL(__imp__sub_827BC770) {
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
	// lis r31,-32127
	r31.s64 = -2105475072;
	// lwz r3,4404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4404);
	// bl 0x82130588
	ctx.lr = 0x827BC78C;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4404(r31)
	PPC_STORE_U32(r31.u32 + 4404, r11.u32);
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

__attribute__((alias("__imp__sub_827BC7A8"))) PPC_WEAK_FUNC(sub_827BC7A8);
PPC_FUNC_IMPL(__imp__sub_827BC7A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23388
	ctx.r3.s64 = r11.s64 + -23388;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC7B4"))) PPC_WEAK_FUNC(sub_827BC7B4);
PPC_FUNC_IMPL(__imp__sub_827BC7B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC7B8"))) PPC_WEAK_FUNC(sub_827BC7B8);
PPC_FUNC_IMPL(__imp__sub_827BC7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-1408
	r11.s64 = r11.s64 + -1408;
	// stw r11,13092(r10)
	PPC_STORE_U32(ctx.r10.u32 + 13092, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC7CC"))) PPC_WEAK_FUNC(sub_827BC7CC);
PPC_FUNC_IMPL(__imp__sub_827BC7CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC7D0"))) PPC_WEAK_FUNC(sub_827BC7D0);
PPC_FUNC_IMPL(__imp__sub_827BC7D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-1408
	r11.s64 = r11.s64 + -1408;
	// stw r11,13096(r10)
	PPC_STORE_U32(ctx.r10.u32 + 13096, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC7E4"))) PPC_WEAK_FUNC(sub_827BC7E4);
PPC_FUNC_IMPL(__imp__sub_827BC7E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC7E8"))) PPC_WEAK_FUNC(sub_827BC7E8);
PPC_FUNC_IMPL(__imp__sub_827BC7E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-1408
	r11.s64 = r11.s64 + -1408;
	// stw r11,13100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 13100, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC7FC"))) PPC_WEAK_FUNC(sub_827BC7FC);
PPC_FUNC_IMPL(__imp__sub_827BC7FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC800"))) PPC_WEAK_FUNC(sub_827BC800);
PPC_FUNC_IMPL(__imp__sub_827BC800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-1408
	r11.s64 = r11.s64 + -1408;
	// stw r11,13204(r10)
	PPC_STORE_U32(ctx.r10.u32 + 13204, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC814"))) PPC_WEAK_FUNC(sub_827BC814);
PPC_FUNC_IMPL(__imp__sub_827BC814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC818"))) PPC_WEAK_FUNC(sub_827BC818);
PPC_FUNC_IMPL(__imp__sub_827BC818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-1408
	r11.s64 = r11.s64 + -1408;
	// stw r11,13208(r10)
	PPC_STORE_U32(ctx.r10.u32 + 13208, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC82C"))) PPC_WEAK_FUNC(sub_827BC82C);
PPC_FUNC_IMPL(__imp__sub_827BC82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC830"))) PPC_WEAK_FUNC(sub_827BC830);
PPC_FUNC_IMPL(__imp__sub_827BC830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-1408
	r11.s64 = r11.s64 + -1408;
	// stw r11,13992(r10)
	PPC_STORE_U32(ctx.r10.u32 + 13992, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC844"))) PPC_WEAK_FUNC(sub_827BC844);
PPC_FUNC_IMPL(__imp__sub_827BC844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC848"))) PPC_WEAK_FUNC(sub_827BC848);
PPC_FUNC_IMPL(__imp__sub_827BC848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-1408
	r11.s64 = r11.s64 + -1408;
	// stw r11,13996(r10)
	PPC_STORE_U32(ctx.r10.u32 + 13996, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC85C"))) PPC_WEAK_FUNC(sub_827BC85C);
PPC_FUNC_IMPL(__imp__sub_827BC85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC860"))) PPC_WEAK_FUNC(sub_827BC860);
PPC_FUNC_IMPL(__imp__sub_827BC860) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,-1408
	r11.s64 = r11.s64 + -1408;
	// stw r11,14000(r10)
	PPC_STORE_U32(ctx.r10.u32 + 14000, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC874"))) PPC_WEAK_FUNC(sub_827BC874);
PPC_FUNC_IMPL(__imp__sub_827BC874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC878"))) PPC_WEAK_FUNC(sub_827BC878);
PPC_FUNC_IMPL(__imp__sub_827BC878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r3,r11,6556
	ctx.r3.s64 = r11.s64 + 6556;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC884"))) PPC_WEAK_FUNC(sub_827BC884);
PPC_FUNC_IMPL(__imp__sub_827BC884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC888"))) PPC_WEAK_FUNC(sub_827BC888);
PPC_FUNC_IMPL(__imp__sub_827BC888) {
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
	// lis r30,-32127
	r30.s64 = -2105475072;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r31,r30,14064
	r31.s64 = r30.s64 + 14064;
	// addi r11,r11,21260
	r11.s64 = r11.s64 + 21260;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r11,14064(r30)
	PPC_STORE_U32(r30.u32 + 14064, r11.u32);
	// bl 0x825fc480
	ctx.lr = 0x827BC8B8;
	sub_825FC480(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x825eea48
	ctx.lr = 0x827BC8C0;
	sub_825EEA48(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,20884
	r11.s64 = r11.s64 + 20884;
	// stw r11,14064(r30)
	PPC_STORE_U32(r30.u32 + 14064, r11.u32);
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

__attribute__((alias("__imp__sub_827BC8E4"))) PPC_WEAK_FUNC(sub_827BC8E4);
PPC_FUNC_IMPL(__imp__sub_827BC8E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC8E8"))) PPC_WEAK_FUNC(sub_827BC8E8);
PPC_FUNC_IMPL(__imp__sub_827BC8E8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC8EC"))) PPC_WEAK_FUNC(sub_827BC8EC);
PPC_FUNC_IMPL(__imp__sub_827BC8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC8F0"))) PPC_WEAK_FUNC(sub_827BC8F0);
PPC_FUNC_IMPL(__imp__sub_827BC8F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r3,r11,21264
	ctx.r3.s64 = r11.s64 + 21264;
	// lhz r5,6(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x825fde48
	sub_825FDE48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC90C"))) PPC_WEAK_FUNC(sub_827BC90C);
PPC_FUNC_IMPL(__imp__sub_827BC90C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC910"))) PPC_WEAK_FUNC(sub_827BC910);
PPC_FUNC_IMPL(__imp__sub_827BC910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r3,r11,21312
	ctx.r3.s64 = r11.s64 + 21312;
	// b 0x822cdba0
	sub_822CDBA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC91C"))) PPC_WEAK_FUNC(sub_827BC91C);
PPC_FUNC_IMPL(__imp__sub_827BC91C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC920"))) PPC_WEAK_FUNC(sub_827BC920);
PPC_FUNC_IMPL(__imp__sub_827BC920) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827BC928;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// addi r31,r11,256
	r31.s64 = r11.s64 + 256;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r29,r11,-30600
	r29.s64 = r11.s64 + -30600;
loc_827BC944:
	// addi r31,r31,-64
	r31.s64 = r31.s64 + -64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// bl 0x821d2028
	ctx.lr = 0x827BC954;
	sub_821D2028(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827bc944
	if (!cr0.lt) goto loc_827BC944;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827BC964"))) PPC_WEAK_FUNC(sub_827BC964);
PPC_FUNC_IMPL(__imp__sub_827BC964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC968"))) PPC_WEAK_FUNC(sub_827BC968);
PPC_FUNC_IMPL(__imp__sub_827BC968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r3,r11,23584
	ctx.r3.s64 = r11.s64 + 23584;
	// b 0x826182c0
	sub_826182C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC974"))) PPC_WEAK_FUNC(sub_827BC974);
PPC_FUNC_IMPL(__imp__sub_827BC974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC978"))) PPC_WEAK_FUNC(sub_827BC978);
PPC_FUNC_IMPL(__imp__sub_827BC978) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r3,r11,23540
	ctx.r3.s64 = r11.s64 + 23540;
	// b 0x821bbe30
	sub_821BBE30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC984"))) PPC_WEAK_FUNC(sub_827BC984);
PPC_FUNC_IMPL(__imp__sub_827BC984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC988"))) PPC_WEAK_FUNC(sub_827BC988);
PPC_FUNC_IMPL(__imp__sub_827BC988) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC98C"))) PPC_WEAK_FUNC(sub_827BC98C);
PPC_FUNC_IMPL(__imp__sub_827BC98C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC990"))) PPC_WEAK_FUNC(sub_827BC990);
PPC_FUNC_IMPL(__imp__sub_827BC990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r11,r11,-21856
	r11.s64 = r11.s64 + -21856;
	// stw r11,23708(r10)
	PPC_STORE_U32(ctx.r10.u32 + 23708, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC9A4"))) PPC_WEAK_FUNC(sub_827BC9A4);
PPC_FUNC_IMPL(__imp__sub_827BC9A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC9A8"))) PPC_WEAK_FUNC(sub_827BC9A8);
PPC_FUNC_IMPL(__imp__sub_827BC9A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r11,r11,-21856
	r11.s64 = r11.s64 + -21856;
	// stw r11,24884(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24884, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC9BC"))) PPC_WEAK_FUNC(sub_827BC9BC);
PPC_FUNC_IMPL(__imp__sub_827BC9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC9C0"))) PPC_WEAK_FUNC(sub_827BC9C0);
PPC_FUNC_IMPL(__imp__sub_827BC9C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r3,r11,-27096
	ctx.r3.s64 = r11.s64 + -27096;
	// b 0x821c1ab8
	sub_821C1AB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BC9CC"))) PPC_WEAK_FUNC(sub_827BC9CC);
PPC_FUNC_IMPL(__imp__sub_827BC9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC9D0"))) PPC_WEAK_FUNC(sub_827BC9D0);
PPC_FUNC_IMPL(__imp__sub_827BC9D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r11,-18952
	r11.s64 = r11.s64 + -18952;
	// stw r11,-19044(r10)
	PPC_STORE_U32(ctx.r10.u32 + -19044, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BC9E4"))) PPC_WEAK_FUNC(sub_827BC9E4);
PPC_FUNC_IMPL(__imp__sub_827BC9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BC9E8"))) PPC_WEAK_FUNC(sub_827BC9E8);
PPC_FUNC_IMPL(__imp__sub_827BC9E8) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,-24664
	r30.s64 = r31.s64 + -24664;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24664(r31)
	PPC_STORE_U32(r31.u32 + -24664, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BCA14;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BCA1C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,-24664(r31)
	PPC_STORE_U32(r31.u32 + -24664, r11.u32);
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

__attribute__((alias("__imp__sub_827BCA40"))) PPC_WEAK_FUNC(sub_827BCA40);
PPC_FUNC_IMPL(__imp__sub_827BCA40) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,-24632
	r30.s64 = r31.s64 + -24632;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24632(r31)
	PPC_STORE_U32(r31.u32 + -24632, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BCA6C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BCA74;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,-24632(r31)
	PPC_STORE_U32(r31.u32 + -24632, r11.u32);
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

__attribute__((alias("__imp__sub_827BCA98"))) PPC_WEAK_FUNC(sub_827BCA98);
PPC_FUNC_IMPL(__imp__sub_827BCA98) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,-24600
	r30.s64 = r31.s64 + -24600;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24600(r31)
	PPC_STORE_U32(r31.u32 + -24600, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BCAC4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BCACC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,-24600(r31)
	PPC_STORE_U32(r31.u32 + -24600, r11.u32);
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

__attribute__((alias("__imp__sub_827BCAF0"))) PPC_WEAK_FUNC(sub_827BCAF0);
PPC_FUNC_IMPL(__imp__sub_827BCAF0) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,-24568
	r30.s64 = r31.s64 + -24568;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24568(r31)
	PPC_STORE_U32(r31.u32 + -24568, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BCB1C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BCB24;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,-24568(r31)
	PPC_STORE_U32(r31.u32 + -24568, r11.u32);
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

__attribute__((alias("__imp__sub_827BCB48"))) PPC_WEAK_FUNC(sub_827BCB48);
PPC_FUNC_IMPL(__imp__sub_827BCB48) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,-24536
	r30.s64 = r31.s64 + -24536;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24536(r31)
	PPC_STORE_U32(r31.u32 + -24536, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BCB74;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BCB7C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,-24536(r31)
	PPC_STORE_U32(r31.u32 + -24536, r11.u32);
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

__attribute__((alias("__imp__sub_827BCBA0"))) PPC_WEAK_FUNC(sub_827BCBA0);
PPC_FUNC_IMPL(__imp__sub_827BCBA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r11,-30128
	r11.s64 = r11.s64 + -30128;
	// stw r11,-16616(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16616, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCBB4"))) PPC_WEAK_FUNC(sub_827BCBB4);
PPC_FUNC_IMPL(__imp__sub_827BCBB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCBB8"))) PPC_WEAK_FUNC(sub_827BCBB8);
PPC_FUNC_IMPL(__imp__sub_827BCBB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r11,-30128
	r11.s64 = r11.s64 + -30128;
	// stw r11,-16608(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16608, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCBCC"))) PPC_WEAK_FUNC(sub_827BCBCC);
PPC_FUNC_IMPL(__imp__sub_827BCBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCBD0"))) PPC_WEAK_FUNC(sub_827BCBD0);
PPC_FUNC_IMPL(__imp__sub_827BCBD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r11,-30128
	r11.s64 = r11.s64 + -30128;
	// stw r11,-16600(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16600, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCBE4"))) PPC_WEAK_FUNC(sub_827BCBE4);
PPC_FUNC_IMPL(__imp__sub_827BCBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCBE8"))) PPC_WEAK_FUNC(sub_827BCBE8);
PPC_FUNC_IMPL(__imp__sub_827BCBE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r11,-30128
	r11.s64 = r11.s64 + -30128;
	// stw r11,-16624(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16624, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCBFC"))) PPC_WEAK_FUNC(sub_827BCBFC);
PPC_FUNC_IMPL(__imp__sub_827BCBFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC00"))) PPC_WEAK_FUNC(sub_827BCC00);
PPC_FUNC_IMPL(__imp__sub_827BCC00) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCC04"))) PPC_WEAK_FUNC(sub_827BCC04);
PPC_FUNC_IMPL(__imp__sub_827BCC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC08"))) PPC_WEAK_FUNC(sub_827BCC08);
PPC_FUNC_IMPL(__imp__sub_827BCC08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCC0C"))) PPC_WEAK_FUNC(sub_827BCC0C);
PPC_FUNC_IMPL(__imp__sub_827BCC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC10"))) PPC_WEAK_FUNC(sub_827BCC10);
PPC_FUNC_IMPL(__imp__sub_827BCC10) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCC14"))) PPC_WEAK_FUNC(sub_827BCC14);
PPC_FUNC_IMPL(__imp__sub_827BCC14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC18"))) PPC_WEAK_FUNC(sub_827BCC18);
PPC_FUNC_IMPL(__imp__sub_827BCC18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r11,-30128
	r11.s64 = r11.s64 + -30128;
	// stw r11,-12740(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12740, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCC2C"))) PPC_WEAK_FUNC(sub_827BCC2C);
PPC_FUNC_IMPL(__imp__sub_827BCC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC30"))) PPC_WEAK_FUNC(sub_827BCC30);
PPC_FUNC_IMPL(__imp__sub_827BCC30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r3,r11,-24176
	ctx.r3.s64 = r11.s64 + -24176;
	// b 0x8217cb48
	sub_8217CB48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BCC3C"))) PPC_WEAK_FUNC(sub_827BCC3C);
PPC_FUNC_IMPL(__imp__sub_827BCC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC40"))) PPC_WEAK_FUNC(sub_827BCC40);
PPC_FUNC_IMPL(__imp__sub_827BCC40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r3,r11,-23184
	ctx.r3.s64 = r11.s64 + -23184;
	// b 0x82696e00
	sub_82696E00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BCC4C"))) PPC_WEAK_FUNC(sub_827BCC4C);
PPC_FUNC_IMPL(__imp__sub_827BCC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC50"))) PPC_WEAK_FUNC(sub_827BCC50);
PPC_FUNC_IMPL(__imp__sub_827BCC50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r11,-18952
	r11.s64 = r11.s64 + -18952;
	// stw r11,-5456(r10)
	PPC_STORE_U32(ctx.r10.u32 + -5456, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCC64"))) PPC_WEAK_FUNC(sub_827BCC64);
PPC_FUNC_IMPL(__imp__sub_827BCC64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC68"))) PPC_WEAK_FUNC(sub_827BCC68);
PPC_FUNC_IMPL(__imp__sub_827BCC68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r11,-15952
	ctx.r3.s64 = r11.s64 + -15952;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r11,r3,388
	r11.s64 = ctx.r3.s64 + 388;
	// addi r9,r9,21288
	ctx.r9.s64 = ctx.r9.s64 + 21288;
loc_827BCC80:
	// addi r11,r11,-20
	r11.s64 = r11.s64 + -20;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x827bcc80
	if (!cr0.lt) goto loc_827BCC80;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BCC94"))) PPC_WEAK_FUNC(sub_827BCC94);
PPC_FUNC_IMPL(__imp__sub_827BCC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCC98"))) PPC_WEAK_FUNC(sub_827BCC98);
PPC_FUNC_IMPL(__imp__sub_827BCC98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r11,-21076
	ctx.r3.s64 = r11.s64 + -21076;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r11,r3,5124
	r11.s64 = ctx.r3.s64 + 5124;
	// addi r9,r9,21288
	ctx.r9.s64 = ctx.r9.s64 + 21288;
loc_827BCCB0:
	// addi r11,r11,-316
	r11.s64 = r11.s64 + -316;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x827bccb0
	if (!cr0.lt) goto loc_827BCCB0;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BCCC4"))) PPC_WEAK_FUNC(sub_827BCCC4);
PPC_FUNC_IMPL(__imp__sub_827BCCC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCCC8"))) PPC_WEAK_FUNC(sub_827BCCC8);
PPC_FUNC_IMPL(__imp__sub_827BCCC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r11,23636
	r11.s64 = r11.s64 + 23636;
	// stw r11,-160(r10)
	PPC_STORE_U32(ctx.r10.u32 + -160, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BCCDC"))) PPC_WEAK_FUNC(sub_827BCCDC);
PPC_FUNC_IMPL(__imp__sub_827BCCDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCCE0"))) PPC_WEAK_FUNC(sub_827BCCE0);
PPC_FUNC_IMPL(__imp__sub_827BCCE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r11,-15272
	ctx.r3.s64 = r11.s64 + -15272;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r11,r3,11460
	r11.s64 = ctx.r3.s64 + 11460;
	// addi r9,r9,21288
	ctx.r9.s64 = ctx.r9.s64 + 21288;
loc_827BCCF8:
	// addi r11,r11,-712
	r11.s64 = r11.s64 + -712;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x827bccf8
	if (!cr0.lt) goto loc_827BCCF8;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BCD0C"))) PPC_WEAK_FUNC(sub_827BCD0C);
PPC_FUNC_IMPL(__imp__sub_827BCD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCD10"))) PPC_WEAK_FUNC(sub_827BCD10);
PPC_FUNC_IMPL(__imp__sub_827BCD10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r11,-15532
	ctx.r3.s64 = r11.s64 + -15532;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r11,r3,260
	r11.s64 = ctx.r3.s64 + 260;
	// addi r9,r9,21288
	ctx.r9.s64 = ctx.r9.s64 + 21288;
loc_827BCD28:
	// addi r11,r11,-12
	r11.s64 = r11.s64 + -12;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x827bcd28
	if (!cr0.lt) goto loc_827BCD28;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BCD3C"))) PPC_WEAK_FUNC(sub_827BCD3C);
PPC_FUNC_IMPL(__imp__sub_827BCD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BCD40"))) PPC_WEAK_FUNC(sub_827BCD40);
PPC_FUNC_IMPL(__imp__sub_827BCD40) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r3,-3004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3004);
	// bl 0x82130588
	ctx.lr = 0x827BCD5C;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-3004(r31)
	PPC_STORE_U32(r31.u32 + -3004, r11.u32);
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

__attribute__((alias("__imp__sub_827BCD78"))) PPC_WEAK_FUNC(sub_827BCD78);
PPC_FUNC_IMPL(__imp__sub_827BCD78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r3,r11,-2928
	ctx.r3.s64 = r11.s64 + -2928;
	// b 0x82797460
	sub_82797460(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BDE00"))) PPC_WEAK_FUNC(sub_827BDE00);
PPC_FUNC_IMPL(__imp__sub_827BDE00) {
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
	// bl 0x827c1798
	ctx.lr = 0x827BDE20;
	sub_827C1798(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 732);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,732(r31)
	PPC_STORE_U32(r31.u32 + 732, r11.u32);
	// bl 0x827c17a8
	ctx.lr = 0x827BDE3C;
	sub_827C17A8(ctx, base);
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

__attribute__((alias("__imp__sub_827BDE54"))) PPC_WEAK_FUNC(sub_827BDE54);
PPC_FUNC_IMPL(__imp__sub_827BDE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BDE58"))) PPC_WEAK_FUNC(sub_827BDE58);
PPC_FUNC_IMPL(__imp__sub_827BDE58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r11,18368
	r11.s64 = r11.s64 + 18368;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// subfic r10,r11,1
	xer.ca = r11.u32 <= 1;
	ctx.r10.s64 = 1 - r11.s64;
loc_827BDE6C:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmpwi cr6,r8,255
	cr6.compare<int32_t>(ctx.r8.s32, 255, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// bne cr6,0x827bde6c
	if (!cr6.eq) goto loc_827BDE6C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BDEA0"))) PPC_WEAK_FUNC(sub_827BDEA0);
PPC_FUNC_IMPL(__imp__sub_827BDEA0) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827bded4
	if (!cr6.eq) goto loc_827BDED4;
loc_827BDEBC:
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
loc_827BDED4:
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r31,r11,-21504
	r31.s64 = r11.s64 + -21504;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bdefc
	if (cr6.eq) goto loc_827BDEFC;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x827bdf00
	if (cr6.eq) goto loc_827BDF00;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827bdebc
	if (!cr6.eq) goto loc_827BDEBC;
loc_827BDEFC:
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_827BDF00:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BDF10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bdf24
	if (cr6.eq) goto loc_827BDF24;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// b 0x827bdf28
	goto loc_827BDF28;
loc_827BDF24:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_827BDF28:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
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

__attribute__((alias("__imp__sub_827BDF48"))) PPC_WEAK_FUNC(sub_827BDF48);
PPC_FUNC_IMPL(__imp__sub_827BDF48) {
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
	ctx.lr = 0x827BDF50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827bdf74
	if (!cr6.lt) goto loc_827BDF74;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_827BDF74:
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x827be004
	if (!cr6.lt) goto loc_827BE004;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - r11.s64;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// rlwinm r10,r11,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r11,r5,r9
	r11.s64 = ctx.r9.s64 - ctx.r5.s64;
	// mulli r9,r5,1000
	ctx.r9.s64 = ctx.r5.s64 * 1000;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// divwu r29,r9,r10
	r29.u32 = ctx.r9.u32 / ctx.r10.u32;
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bge cr6,0x827bdff0
	if (!cr6.lt) goto loc_827BDFF0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subf r30,r11,r3
	r30.s64 = ctx.r3.s64 - r11.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// subf r5,r30,r5
	ctx.r5.s64 = ctx.r5.s64 - r30.s64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// bl 0x823d9890
	ctx.lr = 0x827BDFD4;
	sub_823D9890(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x827BDFE4;
	sub_823D9890(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_827BDFF0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823d9890
	ctx.lr = 0x827BDFF8;
	sub_823D9890(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_827BE004:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827BE010"))) PPC_WEAK_FUNC(sub_827BE010);
PPC_FUNC_IMPL(__imp__sub_827BE010) {
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
	ctx.lr = 0x827BE018;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,276(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// lwz r10,280(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 280);
	// mulli r11,r11,388
	r11.s64 = r11.s64 * 388;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,-40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be308
	if (cr6.eq) goto loc_827BE308;
	// lwz r11,692(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 692);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be308
	if (cr6.eq) goto loc_827BE308;
	// lis r25,-32107
	r25.s64 = -2104164352;
	// addi r26,r29,852
	r26.s64 = r29.s64 + 852;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-21488(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -21488);
	// bl 0x827c1f08
	ctx.lr = 0x827BE05C;
	sub_827C1F08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827be308
	if (cr6.eq) goto loc_827BE308;
	// lwz r11,276(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827be2fc
	if (!cr6.gt) goto loc_827BE2FC;
	// li r28,0
	r28.s64 = 0;
loc_827BE078:
	// lwz r11,280(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 280);
	// add r30,r28,r11
	r30.u64 = r28.u64 + r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,348(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 348);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BE090;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827be2e8
	if (cr6.eq) goto loc_827BE2E8;
loc_827BE098:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// subf r31,r10,r11
	r31.s64 = r11.s64 - ctx.r10.s64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x827be0b4
	if (!cr6.lt) goto loc_827BE0B4;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_827BE0B4:
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bgt cr6,0x827be0d8
	if (cr6.gt) goto loc_827BE0D8;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x827be2e8
	if (!cr6.gt) goto loc_827BE2E8;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x827be2e8
	if (cr6.eq) goto loc_827BE2E8;
loc_827BE0D8:
	// lwz r11,352(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 352);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BE0F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827be2e8
	if (cr6.eq) goto loc_827BE2E8;
	// lwz r11,88(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be114
	if (cr6.eq) goto loc_827BE114;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// b 0x827be118
	goto loc_827BE118;
loc_827BE114:
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_827BE118:
	// cmplw cr6,r5,r31
	cr6.compare<uint32_t>(ctx.r5.u32, r31.u32, xer);
	// ble cr6,0x827be128
	if (!cr6.gt) goto loc_827BE128;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
loc_827BE128:
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bgt cr6,0x827be148
	if (cr6.gt) goto loc_827BE148;
	// lwz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// and r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 & ctx.r5.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
loc_827BE148:
	// lwz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// subf r31,r4,r10
	r31.s64 = ctx.r10.s64 - ctx.r4.s64;
	// cmplw cr6,r31,r5
	cr6.compare<uint32_t>(r31.u32, ctx.r5.u32, xer);
	// bge cr6,0x827be24c
	if (!cr6.lt) goto loc_827BE24C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827be1d4
	if (cr6.eq) goto loc_827BE1D4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be1b4
	if (cr6.eq) goto loc_827BE1B4;
	// rlwinm r11,r31,31,1,31
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be1a8
	if (cr6.eq) goto loc_827BE1A8;
loc_827BE180:
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lbz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,128
	ctx.r8.s64 = ctx.r8.s64 + 128;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x827be180
	if (!cr6.eq) goto loc_827BE180;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_827BE1A8:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// b 0x827be1d8
	goto loc_827BE1D8;
loc_827BE1B4:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823da950
	ctx.lr = 0x827BE1C0;
	sub_823DA950(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// b 0x827be1d8
	goto loc_827BE1D8;
loc_827BE1D4:
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_827BE1D8:
	// lwz r11,88(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be22c
	if (cr6.eq) goto loc_827BE22C;
	// subf r11,r31,r5
	r11.s64 = ctx.r5.s64 - r31.s64;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be240
	if (cr6.eq) goto loc_827BE240;
loc_827BE1F8:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lbz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,128
	ctx.r8.s64 = ctx.r8.s64 + 128;
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bne cr6,0x827be1f8
	if (!cr6.eq) goto loc_827BE1F8;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// b 0x827be2a0
	goto loc_827BE2A0;
loc_827BE22C:
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// bl 0x823da950
	ctx.lr = 0x827BE23C;
	sub_823DA950(ctx, base);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_827BE240:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// b 0x827be2a0
	goto loc_827BE2A0;
loc_827BE24C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be290
	if (cr6.eq) goto loc_827BE290;
	// rlwinm r11,r5,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be29c
	if (cr6.eq) goto loc_827BE29C;
loc_827BE268:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lbz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,128
	ctx.r8.s64 = ctx.r8.s64 + 128;
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bne cr6,0x827be268
	if (!cr6.eq) goto loc_827BE268;
	// b 0x827be298
	goto loc_827BE298;
loc_827BE290:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823da950
	ctx.lr = 0x827BE298;
	sub_823DA950(ctx, base);
loc_827BE298:
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_827BE29C:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
loc_827BE2A0:
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// lwz r11,88(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be2bc
	if (cr6.eq) goto loc_827BE2BC;
	// rlwinm r5,r5,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
loc_827BE2BC:
	// lwz r11,356(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 356);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BE2D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,348(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 348);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BE2E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x827be098
	if (!cr6.eq) goto loc_827BE098;
loc_827BE2E8:
	// lwz r11,276(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,388
	r28.s64 = r28.s64 + 388;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x827be078
	if (cr6.lt) goto loc_827BE078;
loc_827BE2FC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-21488(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -21488);
	// bl 0x827c1f90
	ctx.lr = 0x827BE308;
	sub_827C1F90(ctx, base);
loc_827BE308:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_827BE310"))) PPC_WEAK_FUNC(sub_827BE310);
PPC_FUNC_IMPL(__imp__sub_827BE310) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827be338
	if (cr6.eq) goto loc_827BE338;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
loc_827BE338:
	// li r11,0
	r11.s64 = 0;
	// lwz r10,276(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,820(r31)
	PPC_STORE_U32(r31.u32 + 820, r11.u32);
	// beq cr6,0x827be354
	if (cr6.eq) goto loc_827BE354;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be010
	ctx.lr = 0x827BE354;
	sub_827BE010(ctx, base);
loc_827BE354:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// bne cr6,0x827be39c
	if (!cr6.eq) goto loc_827BE39C;
	// bl 0x827c2300
	ctx.lr = 0x827BE368;
	sub_827C2300(ctx, base);
	// lwz r11,808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 808);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827be378
	if (!cr6.eq) goto loc_827BE378;
	// stw r3,808(r31)
	PPC_STORE_U32(r31.u32 + 808, ctx.r3.u32);
loc_827BE378:
	// lwz r11,808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 808);
	// lis r10,4
	ctx.r10.s64 = 262144;
	// ori r10,r10,37856
	ctx.r10.u64 = ctx.r10.u64 | 37856;
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x827be39c
	if (!cr6.gt) goto loc_827BE39C;
	// li r11,1
	r11.s64 = 1;
	// stw r3,808(r31)
	PPC_STORE_U32(r31.u32 + 808, ctx.r3.u32);
	// stw r11,812(r31)
	PPC_STORE_U32(r31.u32 + 812, r11.u32);
loc_827BE39C:
	// lwz r10,332(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,328(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r8,r8,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// rotlwi r5,r8,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,264(r31)
	PPC_STORE_U32(r31.u32 + 264, ctx.r8.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	// stw r8,268(r31)
	PPC_STORE_U32(r31.u32 + 268, ctx.r8.u32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// subf r7,r5,r11
	ctx.r7.s64 = r11.s64 - ctx.r5.s64;
	// stw r7,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r7.u32);
	// beq cr6,0x827be3f8
	if (cr6.eq) goto loc_827BE3F8;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// b 0x827be410
	goto loc_827BE410;
loc_827BE3F8:
	// lwz r6,256(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// addi r3,r31,336
	ctx.r3.s64 = r31.s64 + 336;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BE410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827BE410:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be424
	if (cr6.eq) goto loc_827BE424;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be010
	ctx.lr = 0x827BE424;
	sub_827BE010(ctx, base);
loc_827BE424:
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
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

__attribute__((alias("__imp__sub_827BE444"))) PPC_WEAK_FUNC(sub_827BE444);
PPC_FUNC_IMPL(__imp__sub_827BE444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BE448"))) PPC_WEAK_FUNC(sub_827BE448);
PPC_FUNC_IMPL(__imp__sub_827BE448) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,32
	cr6.compare<uint32_t>(ctx.r10.u32, 32, xer);
	// ble cr6,0x827be458
	if (!cr6.gt) goto loc_827BE458;
	// li r10,32
	ctx.r10.s64 = 32;
loc_827BE458:
	// lis r11,-32107
	r11.s64 = -2104164352;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r11,r11,-21464
	r11.s64 = r11.s64 + -21464;
	// stw r10,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r10.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// subf r9,r11,r4
	ctx.r9.s64 = ctx.r4.s64 - r11.s64;
loc_827BE470:
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne cr6,0x827be470
	if (!cr6.eq) goto loc_827BE470;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BE48C"))) PPC_WEAK_FUNC(sub_827BE48C);
PPC_FUNC_IMPL(__imp__sub_827BE48C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BE490"))) PPC_WEAK_FUNC(sub_827BE490);
PPC_FUNC_IMPL(__imp__sub_827BE490) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x827BE498;
	// subf r30,r5,r3
	r30.s64 = ctx.r3.s64 - ctx.r5.s64;
	// li r28,0
	r28.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x827be4b4
	if (!cr6.lt) goto loc_827BE4B4;
	// li r30,0
	r30.s64 = 0;
loc_827BE4B4:
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x827be518
	if (!cr6.gt) goto loc_827BE518;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// add r8,r11,r4
	ctx.r8.u64 = r11.u64 + ctx.r4.u64;
loc_827BE4CC:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r26,4(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// and r29,r11,r29
	r29.u64 = r11.u64 & r29.u64;
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// clrlwi r29,r29,31
	r29.u64 = r29.u32 & 0x1;
	// ble cr6,0x827be588
	if (!cr6.gt) goto loc_827BE588;
	// cmplw cr6,r9,r28
	cr6.compare<uint32_t>(ctx.r9.u32, r28.u32, xer);
	// ble cr6,0x827be4fc
	if (!cr6.gt) goto loc_827BE4FC;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r27,r31
	r27.u64 = r31.u64;
loc_827BE4FC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x827be4cc
	if (cr6.lt) goto loc_827BE4CC;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827be53c
	if (!cr6.eq) goto loc_827BE53C;
loc_827BE518:
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// clrldi r9,r5,32
	ctx.r9.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// clrldi r8,r3,32
	ctx.r8.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lwzx r11,r11,r4
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// mulld r11,r11,r9
	r11.s64 = r11.s64 * ctx.r9.s64;
	// divdu r11,r11,r8
	r11.u64 = r11.u64 / ctx.r8.u64;
	// rotlwi r28,r11,0
	r28.u64 = __builtin_rotateleft32(r11.u32, 0);
loc_827BE53C:
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bge cr6,0x827be578
	if (!cr6.lt) goto loc_827BE578;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
loc_827BE550:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// and r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 & r29.u64;
	// clrlwi r29,r10,31
	r29.u64 = ctx.r10.u32 & 0x1;
	// ble cr6,0x827be588
	if (!cr6.gt) goto loc_827BE588;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// blt cr6,0x827be550
	if (cr6.lt) goto loc_827BE550;
loc_827BE578:
	// stw r29,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r29.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r27,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r27.u32);
	// b 0x823d9240
	return;
loc_827BE588:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827BE590"))) PPC_WEAK_FUNC(sub_827BE590);
PPC_FUNC_IMPL(__imp__sub_827BE590) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,-228(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -228);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827be5dc
	if (!cr6.eq) goto loc_827BE5DC;
	// lwz r10,-184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + -184);
	// lwz r11,-188(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -188);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mulli r10,r10,100
	ctx.r10.s64 = ctx.r10.s64 * 100;
	// divwu r11,r10,r11
	r11.u32 = ctx.r10.u32 / r11.u32;
	// cmplwi cr6,r11,50
	cr6.compare<uint32_t>(r11.u32, 50, xer);
	// bge cr6,0x827be5c4
	if (!cr6.lt) goto loc_827BE5C4;
	// subfic r3,r11,-1
	xer.ca = r11.u32 <= 4294967295;
	ctx.r3.s64 = -1 - r11.s64;
	// blr 
	return;
loc_827BE5C4:
	// lwz r11,248(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x827be5dc
	if (cr6.eq) goto loc_827BE5DC;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// subf r3,r11,r10
	ctx.r3.s64 = ctx.r10.s64 - r11.s64;
	// blr 
	return;
loc_827BE5DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BE5E4"))) PPC_WEAK_FUNC(sub_827BE5E4);
PPC_FUNC_IMPL(__imp__sub_827BE5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BE5E8"))) PPC_WEAK_FUNC(sub_827BE5E8);
PPC_FUNC_IMPL(__imp__sub_827BE5E8) {
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
	// addi r31,r3,-596
	r31.s64 = ctx.r3.s64 + -596;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r31,336
	ctx.r3.s64 = r31.s64 + 336;
	// lwz r11,352(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BE614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,844(r31)
	PPC_STORE_U32(r31.u32 + 844, r30.u32);
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

__attribute__((alias("__imp__sub_827BE630"))) PPC_WEAK_FUNC(sub_827BE630);
PPC_FUNC_IMPL(__imp__sub_827BE630) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r4,r3,260
	ctx.r4.s64 = ctx.r3.s64 + 260;
	// lwz r3,-21492(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21492);
	// b 0x827c1f60
	sub_827C1F60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BE640"))) PPC_WEAK_FUNC(sub_827BE640);
PPC_FUNC_IMPL(__imp__sub_827BE640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r4,r3,260
	ctx.r4.s64 = ctx.r3.s64 + 260;
	// lwz r3,-21492(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21492);
	// b 0x827c1f08
	sub_827C1F08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BE650"))) PPC_WEAK_FUNC(sub_827BE650);
PPC_FUNC_IMPL(__imp__sub_827BE650) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r4,r3,260
	ctx.r4.s64 = ctx.r3.s64 + 260;
	// lwz r3,-21492(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21492);
	// b 0x827c1f90
	sub_827C1F90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BE660"))) PPC_WEAK_FUNC(sub_827BE660);
PPC_FUNC_IMPL(__imp__sub_827BE660) {
	PPC_FUNC_PROLOGUE();
	// b 0x827c2058
	sub_827C2058(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BE664"))) PPC_WEAK_FUNC(sub_827BE664);
PPC_FUNC_IMPL(__imp__sub_827BE664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BE668"))) PPC_WEAK_FUNC(sub_827BE668);
PPC_FUNC_IMPL(__imp__sub_827BE668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,-4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// subfic r3,r11,-1
	xer.ca = r11.u32 <= 4294967295;
	ctx.r3.s64 = -1 - r11.s64;
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BE680"))) PPC_WEAK_FUNC(sub_827BE680);
PPC_FUNC_IMPL(__imp__sub_827BE680) {
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
	// addi r31,r3,-852
	r31.s64 = ctx.r3.s64 + -852;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be6b0
	if (cr6.eq) goto loc_827BE6B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be010
	ctx.lr = 0x827BE6B0;
	sub_827BE010(ctx, base);
loc_827BE6B0:
	// stw r30,848(r31)
	PPC_STORE_U32(r31.u32 + 848, r30.u32);
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

__attribute__((alias("__imp__sub_827BE6CC"))) PPC_WEAK_FUNC(sub_827BE6CC);
PPC_FUNC_IMPL(__imp__sub_827BE6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BE6D0"))) PPC_WEAK_FUNC(sub_827BE6D0);
PPC_FUNC_IMPL(__imp__sub_827BE6D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r4,r11,24
	ctx.r4.s64 = r11.s64 + 24;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,668(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 668);
	// addi r8,r8,7
	ctx.r8.s64 = ctx.r8.s64 + 7;
	// rlwinm r8,r8,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r8,672(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// addi r8,r8,7
	ctx.r8.s64 = ctx.r8.s64 + 7;
	// rlwinm r8,r8,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r8,668(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 668);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r8,r8,7
	ctx.r8.s64 = ctx.r8.s64 + 7;
	// rlwinm r8,r8,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r8,672(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// stw r9,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r9.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
	// stw r9,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r9.u32);
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r8,r8,7
	ctx.r8.s64 = ctx.r8.s64 + 7;
	// rlwinm r8,r8,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// rlwinm r8,r8,12,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0x1;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r10,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r10.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// stw r10,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r10.u32);
	// stw r8,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r8.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r10.u32);
	// stw r10,68(r11)
	PPC_STORE_U32(r11.u32 + 68, ctx.r10.u32);
	// lwz r10,916(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 916);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827be790
	if (cr6.eq) goto loc_827BE790;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_827BE790:
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r3,r11,72
	ctx.r3.s64 = r11.s64 + 72;
	// li r5,48
	ctx.r5.s64 = 48;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823da950
	sub_823DA950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BE7A4"))) PPC_WEAK_FUNC(sub_827BE7A4);
PPC_FUNC_IMPL(__imp__sub_827BE7A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BE7A8"))) PPC_WEAK_FUNC(sub_827BE7A8);
PPC_FUNC_IMPL(__imp__sub_827BE7A8) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827be7e8
	if (cr6.eq) goto loc_827BE7E8;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827be7e8
	if (cr6.eq) goto loc_827BE7E8;
	// stw r4,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, ctx.r4.u32);
	// lwz r3,28(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// bl 0x82132618
	ctx.lr = 0x827BE7D0;
	sub_82132618(ctx, base);
	// rlwinm r11,r3,0,21,21
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be7e8
	if (cr6.eq) goto loc_827BE7E8;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21512
	ctx.r3.s64 = r11.s64 + -21512;
	// bl 0x82457b48
	ctx.lr = 0x827BE7E8;
	sub_82457B48(ctx, base);
loc_827BE7E8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BE7F8"))) PPC_WEAK_FUNC(sub_827BE7F8);
PPC_FUNC_IMPL(__imp__sub_827BE7F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x827BE800;
	// stwu r1,-1392(r1)
	ea = -1392 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// mr r16,r4
	r16.u64 = ctx.r4.u64;
	// addi r31,r11,31728
	r31.s64 = r11.s64 + 31728;
	// rlwinm r10,r16,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x4000;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// li r17,1
	r17.s64 = 1;
	// li r18,0
	r18.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r19,r11,-21492
	r19.s64 = r11.s64 + -21492;
	// bne cr6,0x827be840
	if (!cr6.eq) goto loc_827BE840;
	// mr r11,r17
	r11.u64 = r17.u64;
	// stw r11,20(r19)
	PPC_STORE_U32(r19.u32 + 20, r11.u32);
	// mr r11,r18
	r11.u64 = r18.u64;
	// stw r11,28(r19)
	PPC_STORE_U32(r19.u32 + 28, r11.u32);
loc_827BE840:
	// li r5,924
	ctx.r5.s64 = 924;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x823d9890
	ctx.lr = 0x827BE850;
	sub_823D9890(ctx, base);
	// bl 0x827c2300
	ctx.lr = 0x827BE854;
	sub_827C2300(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// rlwinm r21,r16,0,5,5
	r21.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x4000000;
	// stw r3,1068(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1068, ctx.r3.u32);
	// addi r23,r11,18360
	r23.s64 = r11.s64 + 18360;
	// mr r11,r18
	r11.u64 = r18.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// stb r11,8(r23)
	PPC_STORE_U8(r23.u32 + 8, r11.u8);
	// beq cr6,0x827be888
	if (cr6.eq) goto loc_827BE888;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x823da950
	ctx.lr = 0x827BE884;
	sub_823DA950(ctx, base);
	// b 0x827be908
	goto loc_827BE908;
loc_827BE888:
	// rlwinm r11,r16,0,6,6
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x2000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be8a4
	if (cr6.eq) goto loc_827BE8A4;
	// lwz r11,24(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be8a4
	if (cr6.eq) goto loc_827BE8A4;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_827BE8A4:
	// mr r11,r18
	r11.u64 = r18.u64;
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// stw r11,24(r19)
	PPC_STORE_U32(r19.u32 + 24, r11.u32);
	// mtctr r31
	ctr.u64 = r31.u64;
	// bctrl 
	ctx.lr = 0x827BE8C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x827be8ec
	if (!cr6.eq) goto loc_827BE8EC;
	// lbz r11,8(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf7c4
	if (!cr6.eq) goto loc_827BF7C4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21112
	ctx.r3.s64 = r11.s64 + -21112;
	// bl 0x827bde58
	ctx.lr = 0x827BE8E0;
	sub_827BDE58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x823d9218
	return;
loc_827BE8EC:
	// lwz r11,656(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 656);
	// li r6,44
	ctx.r6.s64 = 44;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BE908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827BE908:
	// lis r11,26187
	r11.s64 = 1716191232;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// ori r30,r11,18754
	r30.u64 = r11.u64 | 18754;
	// lis r11,26443
	r11.s64 = 1732968448;
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// ori r29,r11,18754
	r29.u64 = r11.u64 | 18754;
	// lis r11,26699
	r11.s64 = 1749745664;
	// ori r25,r11,18754
	r25.u64 = r11.u64 | 18754;
	// beq cr6,0x827be94c
	if (cr6.eq) goto loc_827BE94C;
	// cmplw cr6,r4,r29
	cr6.compare<uint32_t>(ctx.r4.u32, r29.u32, xer);
	// beq cr6,0x827be94c
	if (cr6.eq) goto loc_827BE94C;
	// cmplw cr6,r4,r25
	cr6.compare<uint32_t>(ctx.r4.u32, r25.u32, xer);
	// beq cr6,0x827be94c
	if (cr6.eq) goto loc_827BE94C;
	// lis r11,26955
	r11.s64 = 1766522880;
	// ori r11,r11,18754
	r11.u64 = r11.u64 | 18754;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x827be958
	if (!cr6.eq) goto loc_827BE958;
loc_827BE94C:
	// lwz r11,688(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 688);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827be964
	if (cr6.eq) goto loc_827BE964;
loc_827BE958:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21132
	ctx.r3.s64 = r11.s64 + -21132;
	// b 0x827bf7a4
	goto loc_827BF7A4;
loc_827BE964:
	// lwz r28,104(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827be97c
	if (!cr6.eq) goto loc_827BE97C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21184
	ctx.r3.s64 = r11.s64 + -21184;
	// b 0x827bf7a4
	goto loc_827BF7A4;
loc_827BE97C:
	// lwz r31,112(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// blt cr6,0x827bf79c
	if (cr6.lt) goto loc_827BF79C;
	// lis r11,15
	r11.s64 = 983040;
	// ori r11,r11,16960
	r11.u64 = r11.u64 | 16960;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bgt cr6,0x827bf79c
	if (cr6.gt) goto loc_827BF79C;
	// lwz r24,108(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r26,100(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplw cr6,r24,r26
	cr6.compare<uint32_t>(r24.u32, r26.u32, xer);
	// bgt cr6,0x827bf79c
	if (cr6.gt) goto loc_827BF79C;
	// lwz r27,136(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r27,256
	cr6.compare<uint32_t>(r27.u32, 256, xer);
	// bgt cr6,0x827bf79c
	if (cr6.gt) goto loc_827BF79C;
	// addi r11,r27,1
	r11.s64 = r27.s64 + 1;
	// mullw r11,r11,r31
	r11.s64 = int64_t(r11.s32) * int64_t(r31.s32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x827bf79c
	if (cr6.lt) goto loc_827BF79C;
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r9,32767
	cr6.compare<uint32_t>(ctx.r9.u32, 32767, xer);
	// bgt cr6,0x827bf79c
	if (cr6.gt) goto loc_827BF79C;
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r8,32767
	cr6.compare<uint32_t>(ctx.r8.u32, 32767, xer);
	// bgt cr6,0x827bf79c
	if (cr6.gt) goto loc_827BF79C;
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827bf79c
	if (cr6.eq) goto loc_827BF79C;
	// lwz r6,128(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x827bf79c
	if (cr6.eq) goto loc_827BF79C;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r10,r9,15
	ctx.r10.s64 = ctx.r9.s64 + 15;
	// stw r9,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r9.u32);
	// rlwinm r7,r11,0,14,14
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// stw r8,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r8.u32);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r9,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r9.u32);
	// or r7,r7,r16
	ctx.r7.u64 = ctx.r7.u64 | r16.u64;
	// stw r8,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, ctx.r8.u32);
	// addi r10,r10,15
	ctx.r10.s64 = ctx.r10.s64 + 15;
	// stw r11,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r11.u32);
	// rlwinm r7,r7,0,4,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFF8FFFFFFF;
	// rlwinm r5,r10,0,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// rlwinm r20,r11,0,11,11
	r20.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r7,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r7.u32);
	// stw r5,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r5.u32);
	// bne cr6,0x827bea48
	if (!cr6.eq) goto loc_827BEA48;
	// rlwinm r7,r7,0,12,10
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// stw r7,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r7.u32);
loc_827BEA48:
	// rlwinm r10,r16,0,1,3
	ctx.r10.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x70000000;
	// lis r20,28672
	r20.s64 = 1879048192;
	// cmplw cr6,r10,r20
	cr6.compare<uint32_t>(ctx.r10.u32, r20.u32, xer);
	// beq cr6,0x827bead8
	if (cr6.eq) goto loc_827BEAD8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827bea68
	if (cr6.eq) goto loc_827BEA68;
	// or r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 | ctx.r7.u64;
	// b 0x827bea70
	goto loc_827BEA70;
loc_827BEA68:
	// rlwinm r11,r11,0,1,3
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x70000000;
	// or r7,r11,r7
	ctx.r7.u64 = r11.u64 | ctx.r7.u64;
loc_827BEA70:
	// rlwinm r11,r7,0,1,3
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x70000000;
	// stw r7,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r7.u32);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x827beab0
	if (cr6.gt) goto loc_827BEAB0;
	// beq cr6,0x827beaa4
	if (cr6.eq) goto loc_827BEAA4;
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x827bead0
	if (cr6.eq) goto loc_827BEAD0;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x827bead8
	if (!cr6.eq) goto loc_827BEAD8;
	// b 0x827bead0
	goto loc_827BEAD0;
loc_827BEAA4:
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r11.u32);
	// b 0x827bead8
	goto loc_827BEAD8;
loc_827BEAB0:
	// lis r10,16384
	ctx.r10.s64 = 1073741824;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x827beac8
	if (cr6.eq) goto loc_827BEAC8;
	// lis r10,20480
	ctx.r10.s64 = 1342177280;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x827bead8
	if (!cr6.eq) goto loc_827BEAD8;
loc_827BEAC8:
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r11.u32);
loc_827BEAD0:
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r8.u32);
loc_827BEAD8:
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// beq cr6,0x827beaf8
	if (cr6.eq) goto loc_827BEAF8;
	// cmplw cr6,r4,r29
	cr6.compare<uint32_t>(ctx.r4.u32, r29.u32, xer);
	// beq cr6,0x827beaf8
	if (cr6.eq) goto loc_827BEAF8;
	// cmplw cr6,r4,r25
	cr6.compare<uint32_t>(ctx.r4.u32, r25.u32, xer);
	// bne cr6,0x827beb04
	if (!cr6.eq) goto loc_827BEB04;
	// ori r11,r7,32768
	r11.u64 = ctx.r7.u64 | 32768;
	// b 0x827beb00
	goto loc_827BEB00;
loc_827BEAF8:
	// oris r11,r7,1
	r11.u64 = ctx.r7.u64 | 65536;
	// ori r11,r11,32768
	r11.u64 = r11.u64 | 32768;
loc_827BEB00:
	// stw r11,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r11.u32);
loc_827BEB04:
	// rlwinm r11,r16,0,19,19
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x1000;
	// stw r28,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, r28.u32);
	// stw r31,540(r1)
	PPC_STORE_U32(ctx.r1.u32 + 540, r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827beb3c
	if (cr6.eq) goto loc_827BEB3C;
	// lwz r11,8(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827beb3c
	if (cr6.eq) goto loc_827BEB3C;
	// stw r11,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, r11.u32);
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// stw r11,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r11.u32);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,8(r19)
	PPC_STORE_U32(r19.u32 + 8, r11.u32);
	// b 0x827beb44
	goto loc_827BEB44;
loc_827BEB3C:
	// stw r3,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r3.u32);
	// stw r6,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r6.u32);
loc_827BEB44:
	// rlwinm r11,r6,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r3,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r3.u32);
	// addi r10,r8,15
	ctx.r10.s64 = ctx.r8.s64 + 15;
	// stw r6,1076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1076, ctx.r6.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stw r26,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, r26.u32);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r27,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, r27.u32);
	// divwu r11,r11,r6
	r11.u32 = r11.u32 / ctx.r6.u32;
	// stw r24,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, r24.u32);
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// stw r11,1080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1080, r11.u32);
	// stw r10,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827beb88
	if (!cr6.eq) goto loc_827BEB88;
	// mr r11,r17
	r11.u64 = r17.u64;
	// stw r11,1080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1080, r11.u32);
loc_827BEB88:
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x827c16b0
	ctx.lr = 0x827BEB94;
	sub_827C16B0(ctx, base);
	// lwz r11,1080(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1080);
	// addi r3,r1,1092
	ctx.r3.s64 = ctx.r1.s64 + 1092;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEBA4;
	sub_827C16B0(ctx, base);
	// lwz r11,1080(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1080);
	// addi r3,r1,1096
	ctx.r3.s64 = ctx.r1.s64 + 1096;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEBB4;
	sub_827C16B0(ctx, base);
	// lwz r11,1080(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1080);
	// addi r3,r1,1100
	ctx.r3.s64 = ctx.r1.s64 + 1100;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEBC4;
	sub_827C16B0(ctx, base);
	// lwz r11,1080(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1080);
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEBD4;
	sub_827C16B0(ctx, base);
	// lwz r11,1080(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1080);
	// addi r3,r1,1108
	ctx.r3.s64 = ctx.r1.s64 + 1108;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEBE4;
	sub_827C16B0(ctx, base);
	// lwz r11,1080(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1080);
	// addi r3,r1,1112
	ctx.r3.s64 = ctx.r1.s64 + 1112;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEBF4;
	sub_827C16B0(ctx, base);
	// lwz r11,20(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bec04
	if (!cr6.eq) goto loc_827BEC04;
	// mr r11,r17
	r11.u64 = r17.u64;
loc_827BEC04:
	// mulli r4,r11,388
	ctx.r4.s64 = r11.s64 * 388;
	// addi r3,r1,600
	ctx.r3.s64 = ctx.r1.s64 + 600;
	// bl 0x827c16b0
	ctx.lr = 0x827BEC10;
	sub_827C16B0(ctx, base);
	// lwz r11,20(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 20);
	// addi r3,r1,604
	ctx.r3.s64 = ctx.r1.s64 + 604;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEC20;
	sub_827C16B0(ctx, base);
	// lwz r11,320(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// addi r11,r11,15
	r11.s64 = r11.s64 + 15;
	// rlwinm r4,r11,0,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x827c4b08
	ctx.lr = 0x827BEC34;
	sub_827C4B08(ctx, base);
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x827bec80
	if (!cr6.eq) goto loc_827BEC80;
	// lwz r11,540(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 540);
	// addi r3,r1,652
	ctx.r3.s64 = ctx.r1.s64 + 652;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEC50;
	sub_827C16B0(ctx, base);
	// lwz r11,544(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 544);
	// addi r3,r1,996
	ctx.r3.s64 = ctx.r1.s64 + 996;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEC60;
	sub_827C16B0(ctx, base);
	// lwz r11,544(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 544);
	// addi r3,r1,1000
	ctx.r3.s64 = ctx.r1.s64 + 1000;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEC70;
	sub_827C16B0(ctx, base);
	// lwz r11,544(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 544);
	// addi r3,r1,1004
	ctx.r3.s64 = ctx.r1.s64 + 1004;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827c16b0
	ctx.lr = 0x827BEC80;
	sub_827C16B0(ctx, base);
loc_827BEC80:
	// li r4,924
	ctx.r4.s64 = 924;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x827bde00
	ctx.lr = 0x827BEC8C;
	sub_827BDE00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827bf124
	if (cr6.eq) goto loc_827BF124;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// li r5,924
	ctx.r5.s64 = 924;
	// bl 0x823da950
	ctx.lr = 0x827BECA4;
	sub_823DA950(ctx, base);
	// lwz r11,772(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 772);
	// stw r31,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r31.u32);
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// stw r18,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r18.u32);
	// lwz r11,776(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// stw r18,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r18.u32);
	// lwz r11,780(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 780);
	// stw r18,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r18.u32);
	// lwz r11,784(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 784);
	// stw r18,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r18.u32);
	// lwz r11,788(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 788);
	// stw r18,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r18.u32);
	// lwz r11,792(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 792);
	// stw r18,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r18.u32);
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// beq cr6,0x827bed68
	if (cr6.eq) goto loc_827BED68;
	// addi r10,r22,44
	ctx.r10.s64 = r22.s64 + 44;
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,676(r31)
	PPC_STORE_U32(r31.u32 + 676, ctx.r10.u32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r22
	ctx.r9.u64 = ctx.r9.u64 + r22.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 + r22.u64;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// stw r9,680(r31)
	PPC_STORE_U32(r31.u32 + 680, ctx.r9.u32);
	// addi r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 + 44;
	// addi r11,r11,44
	r11.s64 = r11.s64 + 44;
	// stw r10,684(r31)
	PPC_STORE_U32(r31.u32 + 684, ctx.r10.u32);
	// stw r11,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r11.u32);
loc_827BED24:
	// addi r7,r31,916
	ctx.r7.s64 = r31.s64 + 916;
	// lwz r5,760(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 760);
	// addi r6,r31,232
	ctx.r6.s64 = r31.s64 + 232;
	// lwz r4,332(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x827be490
	ctx.lr = 0x827BED3C;
	sub_827BE490(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// stw r3,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r3.u32);
	// bne cr6,0x827bee18
	if (!cr6.eq) goto loc_827BEE18;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21220
	ctx.r3.s64 = r11.s64 + -21220;
	// bl 0x827bde58
	ctx.lr = 0x827BED54;
	sub_827BDE58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82469780
	ctx.lr = 0x827BED5C;
	sub_82469780(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21236
	ctx.r3.s64 = r11.s64 + -21236;
	// b 0x827bf7a4
	goto loc_827BF7A4;
loc_827BED68:
	// addi r30,r31,336
	r30.s64 = r31.s64 + 336;
	// lwz r5,676(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 676);
	// lwz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827BED88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// lwz r5,680(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827BEDA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// lwz r5,684(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 684);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827BEDC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lwz r5,332(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827BEDEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bed24
	if (cr6.eq) goto loc_827BED24;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21264
	ctx.r3.s64 = r11.s64 + -21264;
	// bl 0x827bde58
	ctx.lr = 0x827BEE04;
	sub_827BDE58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82469780
	ctx.lr = 0x827BEE0C;
	sub_82469780(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21236
	ctx.r3.s64 = r11.s64 + -21236;
	// b 0x827bf7a4
	goto loc_827BF7A4;
loc_827BEE18:
	// rlwinm r11,r16,0,21,21
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bef74
	if (!cr6.eq) goto loc_827BEF74;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be6d0
	ctx.lr = 0x827BEE30;
	sub_827BE6D0(ctx, base);
	// lwz r11,192(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// mr r9,r18
	ctx.r9.u64 = r18.u64;
	// mr r28,r18
	r28.u64 = r18.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827bef10
	if (!cr6.gt) goto loc_827BEF10;
	// addi r30,r1,220
	r30.s64 = ctx.r1.s64 + 220;
loc_827BEE48:
	// lwz r10,204(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r11,-4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// addi r10,r10,15
	ctx.r10.s64 = ctx.r10.s64 + 15;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r29,r10,0,0,27
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// beq cr6,0x827bee80
	if (cr6.eq) goto loc_827BEE80;
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,200(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// mullw r4,r10,r11
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// bl 0x827c16b0
	ctx.lr = 0x827BEE74;
	sub_827C16B0(ctx, base);
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// mr r9,r17
	ctx.r9.u64 = r17.u64;
loc_827BEE80:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827beea4
	if (cr6.eq) goto loc_827BEEA4;
	// lwz r11,208(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// mullw r4,r11,r29
	ctx.r4.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// bl 0x827c16b0
	ctx.lr = 0x827BEE9C;
	sub_827C16B0(ctx, base);
	// stw r29,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r29.u32);
	// mr r9,r17
	ctx.r9.u64 = r17.u64;
loc_827BEEA4:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827beec8
	if (cr6.eq) goto loc_827BEEC8;
	// lwz r11,208(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// mullw r4,r11,r29
	ctx.r4.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// bl 0x827c16b0
	ctx.lr = 0x827BEEC0;
	sub_827C16B0(ctx, base);
	// stw r29,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r29.u32);
	// mr r9,r17
	ctx.r9.u64 = r17.u64;
loc_827BEEC8:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827beef4
	if (cr6.eq) goto loc_827BEEF4;
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// addi r3,r30,36
	ctx.r3.s64 = r30.s64 + 36;
	// lwz r10,200(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// mullw r4,r10,r11
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// bl 0x827c16b0
	ctx.lr = 0x827BEEE8;
	sub_827C16B0(ctx, base);
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// stw r11,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r11.u32);
	// mr r9,r17
	ctx.r9.u64 = r17.u64;
loc_827BEEF4:
	// lwz r11,192(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,48
	r30.s64 = r30.s64 + 48;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x827bee48
	if (cr6.lt) goto loc_827BEE48;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// bge cr6,0x827bef44
	if (!cr6.lt) goto loc_827BEF44;
loc_827BEF10:
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r1,244
	ctx.r8.s64 = ctx.r1.s64 + 244;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// subfic r10,r28,2
	xer.ca = r28.u32 <= 2;
	ctx.r10.s64 = 2 - r28.s64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
loc_827BEF28:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r18,-12(r11)
	PPC_STORE_U32(r11.u32 + -12, r18.u32);
	// stw r18,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r18.u32);
	// stw r18,-24(r11)
	PPC_STORE_U32(r11.u32 + -24, r18.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// bne cr6,0x827bef28
	if (!cr6.eq) goto loc_827BEF28;
loc_827BEF44:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x827bef74
	if (cr6.eq) goto loc_827BEF74;
	// li r4,120
	ctx.r4.s64 = 120;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bde00
	ctx.lr = 0x827BEF58;
	sub_827BDE00(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,920(r31)
	PPC_STORE_U32(r31.u32 + 920, ctx.r3.u32);
	// beq cr6,0x827bf11c
	if (cr6.eq) goto loc_827BF11C;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// li r5,120
	ctx.r5.s64 = 120;
	// bl 0x823da950
	ctx.lr = 0x827BEF74;
	sub_823DA950(ctx, base);
loc_827BEF74:
	// rlwinm r11,r16,0,7,7
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x1000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827befa0
	if (cr6.eq) goto loc_827BEFA0;
	// lwz r11,12(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 12);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827befa0
	if (cr6.eq) goto loc_827BEFA0;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// li r11,-1
	r11.s64 = -1;
	// stw r10,664(r31)
	PPC_STORE_U32(r31.u32 + 664, ctx.r10.u32);
	// stw r11,12(r19)
	PPC_STORE_U32(r19.u32 + 12, r11.u32);
	// b 0x827befa8
	goto loc_827BEFA8;
loc_827BEFA0:
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// stw r11,664(r31)
	PPC_STORE_U32(r31.u32 + 664, r11.u32);
loc_827BEFA8:
	// rlwinm r11,r16,0,9,9
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x400000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827befd0
	if (cr6.eq) goto loc_827BEFD0;
	// lwz r11,16(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 16);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827befd0
	if (cr6.eq) goto loc_827BEFD0;
	// mr r28,r11
	r28.u64 = r11.u64;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,16(r19)
	PPC_STORE_U32(r19.u32 + 16, r11.u32);
	// b 0x827befd4
	goto loc_827BEFD4;
loc_827BEFD0:
	// mr r28,r18
	r28.u64 = r18.u64;
loc_827BEFD4:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x827beff4
	if (cr6.eq) goto loc_827BEFF4;
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// stw r11,328(r31)
	PPC_STORE_U32(r31.u32 + 328, r11.u32);
	// b 0x827bf150
	goto loc_827BF150;
loc_827BEFF4:
	// addi r30,r31,336
	r30.s64 = r31.s64 + 336;
	// lwz r4,664(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// lwz r11,344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 344);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BF00C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-13108
	r11.s64 = -859045888;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r11,r11,52429
	r11.u64 = r11.u64 | 52429;
	// stw r3,664(r31)
	PPC_STORE_U32(r31.u32 + 664, ctx.r3.u32);
	// mulhwu r11,r10,r11
	r11.u64 = (uint64_t(ctx.r10.u32) * uint64_t(r11.u32)) >> 32;
	// rlwinm r11,r11,29,3,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x827bf044
	if (cr6.lt) goto loc_827BF044;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// ori r16,r16,8192
	r16.u64 = r16.u64 | 8192;
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_827BF044:
	// rlwinm r11,r16,0,18,18
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bf0e0
	if (cr6.eq) goto loc_827BF0E0;
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// addi r29,r11,8
	r29.s64 = r11.s64 + 8;
	// addi r4,r29,1024
	ctx.r4.s64 = r29.s64 + 1024;
	// bl 0x827bde00
	ctx.lr = 0x827BF070;
	sub_827BDE00(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,328(r31)
	PPC_STORE_U32(r31.u32 + 328, ctx.r3.u32);
	// beq cr6,0x827bf10c
	if (cr6.eq) goto loc_827BF10C;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r10,348(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r6,r11,8
	ctx.r6.s64 = r11.s64 + 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827BF0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// lwz r6,328(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r10,340(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r5,r11,0,0,30
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827BF0C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,356(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BF0D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r18,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r18.u32);
	// b 0x827bf150
	goto loc_827BF150;
loc_827BF0E0:
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// addi r4,r11,1024
	ctx.r4.s64 = r11.s64 + 1024;
	// bl 0x827c16b0
	ctx.lr = 0x827BF0F0;
	sub_827C16B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,664(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// bl 0x827bde00
	ctx.lr = 0x827BF0FC;
	sub_827BDE00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r4,660(r31)
	PPC_STORE_U32(r31.u32 + 660, ctx.r4.u32);
	// bne cr6,0x827bf130
	if (!cr6.eq) goto loc_827BF130;
loc_827BF10C:
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827bf11c
	if (cr6.eq) goto loc_827BF11C;
	// bl 0x82469780
	ctx.lr = 0x827BF11C;
	sub_82469780(ctx, base);
loc_827BF11C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82469780
	ctx.lr = 0x827BF124;
	sub_82469780(ctx, base);
loc_827BF124:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21236
	ctx.r3.s64 = r11.s64 + -21236;
	// b 0x827bf7a4
	goto loc_827BF7A4;
loc_827BF130:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r5,664(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,348(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// addi r6,r11,8
	ctx.r6.s64 = r11.s64 + 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827BF150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827BF150:
	// li r20,-1
	r20.s64 = -1;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r20,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r20.u32);
	// beq cr6,0x827bf178
	if (cr6.eq) goto loc_827BF178;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// mulli r10,r10,2000
	ctx.r10.s64 = ctx.r10.s64 * 2000;
	// divdu r11,r10,r11
	r11.u64 = ctx.r10.u64 / r11.u64;
	// b 0x827bf17c
	goto loc_827BF17C;
loc_827BF178:
	// li r11,2000
	r11.s64 = 2000;
loc_827BF17C:
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,712(r31)
	PPC_STORE_U32(r31.u32 + 712, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r17,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r17.u32);
	// bl 0x827be310
	ctx.lr = 0x827BF190;
	sub_827BE310(ctx, base);
	// bl 0x827c2300
	ctx.lr = 0x827BF194;
	sub_827C2300(ctx, base);
	// lwz r11,748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 748);
	// lwz r10,280(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// lis r21,1
	r21.s64 = 65536;
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// stw r11,748(r31)
	PPC_STORE_U32(r31.u32 + 748, r11.u32);
	// stw r21,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, r21.u32);
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// stw r18,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r18.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827bf238
	if (cr6.eq) goto loc_827BF238;
	// lwz r11,20(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bf238
	if (cr6.eq) goto loc_827BF238;
	// addi r8,r19,28
	ctx.r8.s64 = r19.s64 + 28;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_827BF1D0:
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827bf228
	if (!cr6.gt) goto loc_827BF228;
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r11,684(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 684);
loc_827BF1E8:
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r6,r9
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, xer);
	// beq cr6,0x827bf20c
	if (cr6.eq) goto loc_827BF20C;
	// lwz r6,224(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x827bf1e8
	if (cr6.lt) goto loc_827BF1E8;
	// b 0x827bf228
	goto loc_827BF228;
loc_827BF20C:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r9,284(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r10.u32);
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
loc_827BF228:
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x827bf1d0
	if (!cr6.eq) goto loc_827BF1D0;
loc_827BF238:
	// mr r11,r18
	r11.u64 = r18.u64;
	// mr r23,r18
	r23.u64 = r18.u64;
	// stw r11,28(r19)
	PPC_STORE_U32(r19.u32 + 28, r11.u32);
	// mr r11,r17
	r11.u64 = r17.u64;
	// lwz r10,276(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,20(r19)
	PPC_STORE_U32(r19.u32 + 20, r11.u32);
	// ble cr6,0x827bf660
	if (!cr6.gt) goto loc_827BF660;
	// lis r11,3
	r11.s64 = 196608;
	// mr r24,r18
	r24.u64 = r18.u64;
	// mr r30,r18
	r30.u64 = r18.u64;
	// ori r22,r11,59392
	r22.u64 = r11.u64 | 59392;
loc_827BF268:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r18,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r18.u32);
	// lwz r11,284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// lwz r9,680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwzx r10,r24,r11
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r8,r10,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x827bf2a0
	if (!cr6.eq) goto loc_827BF2A0;
	// rlwinm r8,r10,0,3,3
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827bf5f4
	if (cr6.eq) goto loc_827BF5F4;
loc_827BF2A0:
	// lwz r8,-8(r19)
	ctx.r8.u64 = PPC_LOAD_U32(r19.u32 + -8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827bf5f4
	if (cr6.eq) goto loc_827BF5F4;
	// clrlwi r28,r10,16
	r28.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r28,r22
	cr6.compare<uint32_t>(r28.u32, r22.u32, xer);
	// bgt cr6,0x827bf5f4
	if (cr6.gt) goto loc_827BF5F4;
	// lwzx r11,r24,r11
	r11.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
	// lwz r10,676(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 676);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,340(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwzx r11,r9,r11
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,5,28,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0x8;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r11,r11,3,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x1;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r27,r9,8
	r27.s64 = ctx.r9.s64 + 8;
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// addi r26,r11,1
	r26.s64 = r11.s64 + 1;
	// rlwinm r25,r10,0,0,23
	r25.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// beq cr6,0x827bf388
	if (cr6.eq) goto loc_827BF388;
	// lwz r11,344(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 344);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bf388
	if (cr6.eq) goto loc_827BF388;
	// lwz r9,1076(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1076);
	// extsw r10,r28
	ctx.r10.s64 = r28.s32;
	// extsw r8,r7
	ctx.r8.s64 = ctx.r7.s32;
	// lwz r7,1072(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1072);
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r10,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r10.u64);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// std r8,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r8.u64);
	// std r9,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r9.u64);
	// std r7,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r7.u64);
	// std r11,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, r11.u64);
	// lfd f0,168(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// lfd f12,176(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// lfd f13,160(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfd f11,144(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// lfd f10,152(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fmul f0,f0,f13
	f0.f64 = f0.f64 * ctx.f13.f64;
	// fmul f13,f11,f10
	ctx.f13.f64 = ctx.f11.f64 * ctx.f10.f64;
	// fmul f0,f0,f12
	f0.f64 = f0.f64 * ctx.f12.f64;
	// fdiv f0,f0,f13
	f0.f64 = f0.f64 / ctx.f13.f64;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfiwx f0,0,r10
	PPC_STORE_U32(ctx.r10.u32, f0.u32);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_827BF388:
	// cmplw cr6,r29,r22
	cr6.compare<uint32_t>(r29.u32, r22.u32, xer);
	// ble cr6,0x827bf394
	if (!cr6.gt) goto loc_827BF394;
	// mr r29,r22
	r29.u64 = r22.u64;
loc_827BF394:
	// mullw r11,r26,r27
	r11.s64 = int64_t(r26.s32) * int64_t(r27.s32);
	// mullw r11,r11,r28
	r11.s64 = int64_t(r11.s32) * int64_t(r28.s32);
	// rlwinm r11,r11,30,3,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1FFFFFFF;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bgt cr6,0x827bf5f4
	if (cr6.gt) goto loc_827BF5F4;
	// addi r10,r19,-8
	ctx.r10.s64 = r19.s64 + -8;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BF3D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827bf5f4
	if (cr6.eq) goto loc_827BF5F4;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r28,32(r11)
	PPC_STORE_U32(r11.u32 + 32, r28.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827bf400
	if (!cr6.eq) goto loc_827BF400;
	// stw r20,52(r11)
	PPC_STORE_U32(r11.u32 + 52, r20.u32);
loc_827BF400:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// addi r10,r25,16
	ctx.r10.s64 = r25.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x827bde00
	ctx.lr = 0x827BF424;
	sub_827BDE00(ctx, base);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r3,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r3.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf454
	if (!cr6.eq) goto loc_827BF454;
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BF450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827bf5f4
	goto loc_827BF5F4;
loc_827BF454:
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// subfic r11,r11,750
	xer.ca = r11.u32 <= 750;
	r11.s64 = 750 - r11.s64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827bf468
	if (!cr6.lt) goto loc_827BF468;
	// mr r11,r18
	r11.u64 = r18.u64;
loc_827BF468:
	// addi r10,r27,-8
	ctx.r10.s64 = r27.s64 + -8;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// clrldi r9,r29,32
	ctx.r9.u64 = r29.u64 & 0xFFFFFFFF;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mulld r9,r11,r9
	ctx.r9.s64 = r11.s64 * ctx.r9.s64;
	// stw r10,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r10.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// lis r8,6815
	ctx.r8.s64 = 446627840;
	// lis r7,1572
	ctx.r7.s64 = 103022592;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// ori r8,r8,48759
	ctx.r8.u64 = ctx.r8.u64 | 48759;
	// ori r7,r7,56623
	ctx.r7.u64 = ctx.r7.u64 | 56623;
	// clrldi r10,r26,32
	ctx.r10.u64 = r26.u64 & 0xFFFFFFFF;
	// rldimi r8,r7,32,0
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r8.u64 & 0xFFFFFFFF);
	// mulld r10,r9,r10
	ctx.r10.s64 = ctx.r9.s64 * ctx.r10.s64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rldicr r10,r10,1,62
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// mulhdu r9,r10,r7
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rldicl r10,r10,63,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0x7FFFFFFFFFFFFFFF;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rldicl r10,r10,55,9
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 55) & 0x7FFFFFFFFFFFFF;
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r9.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r10,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r10.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// subf r9,r9,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// bge cr6,0x827bf528
	if (!cr6.lt) goto loc_827BF528;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// stw r10,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r10.u32);
loc_827BF528:
	// lwz r11,284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// lwz r10,680(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwzx r11,r24,r11
	r11.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827bf558
	if (!cr6.eq) goto loc_827BF558;
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10000000;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827bf55c
	if (!cr6.eq) goto loc_827BF55C;
loc_827BF558:
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
loc_827BF55C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = r11.u32 & 0xFFFF;
	// bl 0x827c2bd8
	ctx.lr = 0x827BF568;
	sub_827C2BD8(ctx, base);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r3,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r3.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf5a0
	if (!cr6.eq) goto loc_827BF5A0;
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BF594;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r18,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r18.u32);
loc_827BF5A0:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x827c3028
	ctx.lr = 0x827BF5B0;
	sub_827C3028(ctx, base);
	// lwz r11,-4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -4);
	// lwz r10,280(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-4(r19)
	PPC_STORE_U32(r19.u32 + -4, r11.u32);
	// add r11,r10,r30
	r11.u64 = ctx.r10.u64 + r30.u64;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// lwz r10,756(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 756);
	// lwz r11,752(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 752);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,280(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r7,r10,r30
	ctx.r7.u64 = ctx.r10.u64 + r30.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// divwu r11,r11,r8
	r11.u32 = r11.u32 / ctx.r8.u32;
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// stw r11,68(r7)
	PPC_STORE_U32(ctx.r7.u32 + 68, r11.u32);
loc_827BF5F4:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827bf60c
	if (!cr6.eq) goto loc_827BF60C;
	// stw r21,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r21.u32);
loc_827BF60C:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf648
	if (!cr6.eq) goto loc_827BF648;
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r10,284(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// add r3,r24,r10
	ctx.r3.u64 = r24.u64 + ctx.r10.u64;
	// subf r10,r23,r11
	ctx.r10.s64 = r11.s64 - r23.s64;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x827BF644;
	sub_823DA950(ctx, base);
	// b 0x827bf654
	goto loc_827BF654;
loc_827BF648:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r30,r30,388
	r30.s64 = r30.s64 + 388;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
loc_827BF654:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// blt cr6,0x827bf268
	if (cr6.lt) goto loc_827BF268;
loc_827BF660:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bf6c8
	if (cr6.eq) goto loc_827BF6C8;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// stw r17,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r17.u32);
	// lwz r11,80(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827bf6c8
	if (!cr6.eq) goto loc_827BF6C8;
	// lwz r3,4(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827bf6b0
	if (!cr6.eq) goto loc_827BF6B0;
	// li r3,-13
	ctx.r3.s64 = -13;
	// bl 0x827c1b80
	ctx.lr = 0x827BF694;
	sub_827C1B80(ctx, base);
	// stw r3,4(r19)
	PPC_STORE_U32(r19.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827bf6c8
	if (cr6.eq) goto loc_827BF6C8;
	// bl 0x827c1ee0
	ctx.lr = 0x827BF6A4;
	sub_827C1EE0(ctx, base);
	// lwz r3,4(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827bf6c8
	if (cr6.eq) goto loc_827BF6C8;
loc_827BF6B0:
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r6,r10,-6528
	ctx.r6.s64 = ctx.r10.s64 + -6528;
	// addi r5,r11,-6552
	ctx.r5.s64 = r11.s64 + -6552;
	// addi r4,r31,852
	ctx.r4.s64 = r31.s64 + 852;
	// bl 0x827c1cd0
	ctx.lr = 0x827BF6C8;
	sub_827C1CD0(ctx, base);
loc_827BF6C8:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r11,r11,0,4,4
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf72c
	if (!cr6.eq) goto loc_827BF72C;
	// lwz r11,328(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf72c
	if (!cr6.eq) goto loc_827BF72C;
	// lwz r3,0(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827bf714
	if (!cr6.eq) goto loc_827BF714;
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x827c1b80
	ctx.lr = 0x827BF6F8;
	sub_827C1B80(ctx, base);
	// stw r3,0(r19)
	PPC_STORE_U32(r19.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827bf72c
	if (cr6.eq) goto loc_827BF72C;
	// bl 0x827c1ee0
	ctx.lr = 0x827BF708;
	sub_827C1EE0(ctx, base);
	// lwz r3,0(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827bf72c
	if (cr6.eq) goto loc_827BF72C;
loc_827BF714:
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r6,r10,-6680
	ctx.r6.s64 = ctx.r10.s64 + -6680;
	// addi r5,r11,-6768
	ctx.r5.s64 = r11.s64 + -6768;
	// addi r4,r31,596
	ctx.r4.s64 = r31.s64 + 596;
	// bl 0x827c1cd0
	ctx.lr = 0x827BF72C;
	sub_827C1CD0(ctx, base);
loc_827BF72C:
	// lis r8,-32132
	ctx.r8.s64 = -2105802752;
	// lwz r7,328(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r8,r8,-6576
	ctx.r8.s64 = ctx.r8.s64 + -6576;
	// addi r9,r9,-6608
	ctx.r9.s64 = ctx.r9.s64 + -6608;
	// addi r10,r10,-6592
	ctx.r10.s64 = ctx.r10.s64 + -6592;
	// addi r11,r11,-6560
	r11.s64 = r11.s64 + -6560;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r8,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r8.u32);
	// stw r9,580(r31)
	PPC_STORE_U32(r31.u32 + 580, ctx.r9.u32);
	// stw r10,584(r31)
	PPC_STORE_U32(r31.u32 + 584, ctx.r10.u32);
	// stw r11,592(r31)
	PPC_STORE_U32(r31.u32 + 592, r11.u32);
	// bne cr6,0x827bf790
	if (!cr6.eq) goto loc_827BF790;
	// rlwinm r11,r16,0,10,10
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf790
	if (!cr6.eq) goto loc_827BF790;
	// addi r30,r31,336
	r30.s64 = r31.s64 + 336;
loc_827BF778:
	// lwz r11,352(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BF788;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827bf778
	if (!cr6.eq) goto loc_827BF778;
loc_827BF790:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x823d9218
	return;
loc_827BF79C:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-21296
	ctx.r3.s64 = r11.s64 + -21296;
loc_827BF7A4:
	// bl 0x827bde58
	ctx.lr = 0x827BF7A8;
	sub_827BDE58(ctx, base);
	// rlwinm r11,r16,0,5,5
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 0) & 0x4000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf7c4
	if (!cr6.eq) goto loc_827BF7C4;
	// lwz r11,676(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 676);
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BF7C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827BF7C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_827BF7D0"))) PPC_WEAK_FUNC(sub_827BF7D0);
PPC_FUNC_IMPL(__imp__sub_827BF7D0) {
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
	ctx.lr = 0x827BF7D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,704(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 704);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bf80c
	if (!cr6.eq) goto loc_827BF80C;
	// bl 0x827c2300
	ctx.lr = 0x827BF7F8;
	sub_827C2300(ctx, base);
	// lwz r11,692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// stw r3,704(r31)
	PPC_STORE_U32(r31.u32 + 704, ctx.r3.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r30,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r30.u32);
	// stw r11,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r11.u32);
loc_827BF80C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bf898
	if (cr6.eq) goto loc_827BF898;
	// bl 0x827c2300
	ctx.lr = 0x827BF820;
	sub_827C2300(ctx, base);
	// lwz r10,692(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// lwz r11,708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r7,280(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// lwz r6,704(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 704);
	// mulld r11,r11,r9
	r11.s64 = r11.s64 * ctx.r9.s64;
	// lwz r7,64(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mulli r11,r11,1000
	r11.s64 = r11.s64 * 1000;
	// divdu r11,r11,r8
	r11.u64 = r11.u64 / ctx.r8.u64;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// mulld r11,r11,r7
	r11.s64 = r11.s64 * ctx.r7.s64;
	// rldicl r11,r11,48,16
	r11.u64 = __builtin_rotateleft64(r11.u64, 48) & 0xFFFFFFFFFFFF;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// subf r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x827bf898
	if (cr6.lt) goto loc_827BF898;
	// lwz r9,712(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 712);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x827bf898
	if (!cr6.gt) goto loc_827BF898;
	// lwz r9,276(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827bf8a8
	if (!cr6.eq) goto loc_827BF8A8;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// stw r3,704(r31)
	PPC_STORE_U32(r31.u32 + 704, ctx.r3.u32);
	// stw r30,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r30.u32);
	// stw r11,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r11.u32);
loc_827BF898:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r28,820(r31)
	PPC_STORE_U32(r31.u32 + 820, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827BF8A8:
	// cmpwi cr6,r11,725
	cr6.compare<int32_t>(r11.s32, 725, xer);
	// ble cr6,0x827bf8b4
	if (!cr6.gt) goto loc_827BF8B4;
	// stw r28,824(r31)
	PPC_STORE_U32(r31.u32 + 824, r28.u32);
loc_827BF8B4:
	// lwz r11,832(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x827bf8d4
	if (cr6.lt) goto loc_827BF8D4;
	// stw r30,832(r31)
	PPC_STORE_U32(r31.u32 + 832, r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r28,820(r31)
	PPC_STORE_U32(r31.u32 + 820, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827BF8D4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r11,832(r31)
	PPC_STORE_U32(r31.u32 + 832, r11.u32);
	// bne cr6,0x827bf8fc
	if (!cr6.eq) goto loc_827BF8FC;
	// lwz r11,828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 828);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r28,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r28.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,820(r31)
	PPC_STORE_U32(r31.u32 + 820, ctx.r10.u32);
	// stw r11,828(r31)
	PPC_STORE_U32(r31.u32 + 828, r11.u32);
loc_827BF8FC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827BF908"))) PPC_WEAK_FUNC(sub_827BF908);
PPC_FUNC_IMPL(__imp__sub_827BF908) {
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
	// lwz r9,764(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 764);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,764(r31)
	PPC_STORE_U32(r31.u32 + 764, r11.u32);
	// bge 0x827bf93c
	if (!cr0.lt) goto loc_827BF93C;
	// lwz r11,760(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 760);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,764(r31)
	PPC_STORE_U32(r31.u32 + 764, r11.u32);
loc_827BF93C:
	// lwz r10,804(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 804);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827bf98c
	if (cr6.eq) goto loc_827BF98C;
	// lwz r11,716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 716);
	// subf r10,r10,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r10.s64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x827bf974
	if (!cr6.gt) goto loc_827BF974;
	// lwz r8,720(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 720);
	// lwz r7,800(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 800);
	// stw r11,724(r31)
	PPC_STORE_U32(r31.u32 + 724, r11.u32);
	// stw r10,716(r31)
	PPC_STORE_U32(r31.u32 + 716, ctx.r10.u32);
	// stw r8,728(r31)
	PPC_STORE_U32(r31.u32 + 728, ctx.r8.u32);
	// stw r7,720(r31)
	PPC_STORE_U32(r31.u32 + 720, ctx.r7.u32);
	// b 0x827bf98c
	goto loc_827BF98C;
loc_827BF974:
	// lwz r11,724(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 724);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// ble cr6,0x827bf98c
	if (!cr6.gt) goto loc_827BF98C;
	// lwz r11,800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 800);
	// stw r10,724(r31)
	PPC_STORE_U32(r31.u32 + 724, ctx.r10.u32);
	// stw r11,728(r31)
	PPC_STORE_U32(r31.u32 + 728, r11.u32);
loc_827BF98C:
	// lwz r11,764(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 764);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,768(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 768);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r4,804(r31)
	PPC_STORE_U32(r31.u32 + 804, ctx.r4.u32);
	// stwx r4,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r11,764(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 764);
	// lwz r10,776(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,736(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r8.u32);
	// lwz r11,764(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 764);
	// lwz r10,772(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 772);
	// lwz r8,740(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 740);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r8.u32);
	// lwz r11,764(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 764);
	// lwz r10,780(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 780);
	// lwz r8,744(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r8.u32);
	// lwz r11,764(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 764);
	// lwz r10,388(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// lwz r8,784(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 784);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r10.u32);
	// lwz r11,764(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 764);
	// lwz r10,392(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r8,788(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 788);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r10.u32);
	// lwz r11,764(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 764);
	// lwz r10,792(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 792);
	// lwz r8,396(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r8.u32);
	// lwz r11,696(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 696);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bfa5c
	if (!cr6.eq) goto loc_827BFA5C;
	// lwz r11,756(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 756);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,752(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 752);
	// mulli r11,r11,1000
	r11.s64 = r11.s64 * 1000;
	// lwz r8,768(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 768);
	// divdu r11,r11,r10
	r11.u64 = r11.u64 / ctx.r10.u64;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
	// stwx r11,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r11.u32);
	// stw r30,396(r31)
	PPC_STORE_U32(r31.u32 + 396, r30.u32);
	// stw r4,696(r31)
	PPC_STORE_U32(r31.u32 + 696, ctx.r4.u32);
	// stw r30,392(r31)
	PPC_STORE_U32(r31.u32 + 392, r30.u32);
	// b 0x827bfa70
	goto loc_827BFA70;
loc_827BFA5C:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfa70
	if (cr6.eq) goto loc_827BFA70;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be010
	ctx.lr = 0x827BFA70;
	sub_827BE010(ctx, base);
loc_827BFA70:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// beq cr6,0x827bfa88
	if (cr6.eq) goto loc_827BFA88;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
loc_827BFA88:
	// lwz r11,692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// lwz r10,704(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 704);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r11.u32);
	// bne cr6,0x827bfab8
	if (!cr6.eq) goto loc_827BFAB8;
	// bl 0x827c2300
	ctx.lr = 0x827BFAA4;
	sub_827C2300(ctx, base);
	// lwz r11,692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// stw r3,704(r31)
	PPC_STORE_U32(r31.u32 + 704, ctx.r3.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r30,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r30.u32);
	// stw r11,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r11.u32);
loc_827BFAB8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r9,324(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// stw r10,700(r31)
	PPC_STORE_U32(r31.u32 + 700, ctx.r10.u32);
	// stw r9,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r9.u32);
	// stw r11,800(r31)
	PPC_STORE_U32(r31.u32 + 800, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
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

__attribute__((alias("__imp__sub_827BFAF4"))) PPC_WEAK_FUNC(sub_827BFAF4);
PPC_FUNC_IMPL(__imp__sub_827BFAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BFAF8"))) PPC_WEAK_FUNC(sub_827BFAF8);
PPC_FUNC_IMPL(__imp__sub_827BFAF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827bfb50
	if (cr6.eq) goto loc_827BFB50;
	// lwz r11,236(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 236);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827bfb50
	if (!cr6.eq) goto loc_827BFB50;
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfb50
	if (cr6.eq) goto loc_827BFB50;
	// lwz r11,248(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfb50
	if (cr6.eq) goto loc_827BFB50;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x827bfb50
	if (!cr6.lt) goto loc_827BFB50;
	// lwz r11,820(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 820);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfb48
	if (cr6.eq) goto loc_827BFB48;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// blr 
	return;
loc_827BFB48:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x827bf7d0
	sub_827BF7D0(ctx, base);
	return;
loc_827BFB50:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BFB58"))) PPC_WEAK_FUNC(sub_827BFB58);
PPC_FUNC_IMPL(__imp__sub_827BFB58) {
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
	ctx.lr = 0x827BFB60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827bfb7c
	if (!cr6.eq) goto loc_827BFB7C;
loc_827BFB70:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_827BFB7C:
	// lwz r11,692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bfb94
	if (!cr6.eq) goto loc_827BFB94;
	// lwz r11,236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827bfb70
	if (cr6.eq) goto loc_827BFB70;
loc_827BFB94:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bfb70
	if (!cr6.eq) goto loc_827BFB70;
	// lwz r11,704(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 704);
	// li r30,0
	r30.s64 = 0;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x827bfbd8
	if (!cr6.eq) goto loc_827BFBD8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bfbd4
	if (!cr6.eq) goto loc_827BFBD4;
	// bl 0x827c2300
	ctx.lr = 0x827BFBC0;
	sub_827C2300(ctx, base);
	// lwz r11,692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// stw r3,704(r31)
	PPC_STORE_U32(r31.u32 + 704, ctx.r3.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r30,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r30.u32);
	// stw r11,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r11.u32);
loc_827BFBD4:
	// lwz r29,704(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 704);
loc_827BFBD8:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfbec
	if (cr6.eq) goto loc_827BFBEC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be010
	ctx.lr = 0x827BFBEC;
	sub_827BE010(ctx, base);
loc_827BFBEC:
	// bl 0x827c2300
	ctx.lr = 0x827BFBF0;
	sub_827C2300(ctx, base);
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfc18
	if (cr6.eq) goto loc_827BFC18;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827bfc18
	if (cr6.eq) goto loc_827BFC18;
	// lwz r10,744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// stw r30,700(r31)
	PPC_STORE_U32(r31.u32 + 700, r30.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r11.u32);
loc_827BFC18:
	// lwz r11,236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827bfc90
	if (!cr6.eq) goto loc_827BFC90;
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfc3c
	if (cr6.eq) goto loc_827BFC3C;
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfc90
	if (cr6.eq) goto loc_827BFC90;
loc_827BFC3C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfb70
	if (cr6.eq) goto loc_827BFB70;
	// lwz r9,708(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// lwz r10,692(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r9,280(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// mulld r10,r10,r8
	ctx.r10.s64 = ctx.r10.s64 * ctx.r8.s64;
	// lwz r9,64(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mulli r10,r10,1000
	ctx.r10.s64 = ctx.r10.s64 * 1000;
	// divdu r11,r10,r11
	r11.u64 = ctx.r10.u64 / r11.u64;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// mulld r11,r11,r9
	r11.s64 = r11.s64 * ctx.r9.s64;
	// rldicl r11,r11,48,16
	r11.u64 = __builtin_rotateleft64(r11.u64, 48) & 0xFFFFFFFFFFFF;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// subf. r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x827bfb70
	if (!cr0.lt) goto loc_827BFB70;
loc_827BFC90:
	// lwz r11,328(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bfd08
	if (!cr6.eq) goto loc_827BFD08;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r11,r11,0,4,4
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827bfcd0
	if (!cr6.eq) goto loc_827BFCD0;
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r10,408(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x827bfcc0
	if (cr6.lt) goto loc_827BFCC0;
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
loc_827BFCC0:
	// lwz r10,412(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x827bfd08
	if (!cr6.lt) goto loc_827BFD08;
loc_827BFCD0:
	// lis r29,-32107
	r29.s64 = -2104164352;
	// addi r30,r31,596
	r30.s64 = r31.s64 + 596;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-21492(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -21492);
	// bl 0x827c1f08
	ctx.lr = 0x827BFCE4;
	sub_827C1F08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827bfd08
	if (cr6.eq) goto loc_827BFD08;
	// lwz r11,352(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// addi r3,r31,336
	ctx.r3.s64 = r31.s64 + 336;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BFCFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-21492(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -21492);
	// bl 0x827c1f90
	ctx.lr = 0x827BFD08;
	sub_827C1F90(ctx, base);
loc_827BFD08:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827BFD14"))) PPC_WEAK_FUNC(sub_827BFD14);
PPC_FUNC_IMPL(__imp__sub_827BFD14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BFD18"))) PPC_WEAK_FUNC(sub_827BFD18);
PPC_FUNC_IMPL(__imp__sub_827BFD18) {
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
	ctx.lr = 0x827BFD20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827bfd40
	if (!cr6.eq) goto loc_827BFD40;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_827BFD40:
	// bl 0x827c2300
	ctx.lr = 0x827BFD44;
	sub_827C2300(ctx, base);
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfd6c
	if (cr6.eq) goto loc_827BFD6C;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827bfd6c
	if (cr6.eq) goto loc_827BFD6C;
	// lwz r10,744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// stw r24,700(r31)
	PPC_STORE_U32(r31.u32 + 700, r24.u32);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stw r11,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r11.u32);
loc_827BFD6C:
	// lis r25,-32107
	r25.s64 = -2104164352;
	// lwz r26,236(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// addi r27,r31,852
	r27.s64 = r31.s64 + 852;
	// stw r24,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r24.u32);
	// stw r28,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r28.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-21488(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -21488);
	// bl 0x827c1f60
	ctx.lr = 0x827BFD8C;
	sub_827C1F60(ctx, base);
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// mr r30,r24
	r30.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827bfdcc
	if (!cr6.gt) goto loc_827BFDCC;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_827BFDA0:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// lwz r11,368(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827BFDB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,388
	r29.s64 = r29.s64 + 388;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x827bfda0
	if (cr6.lt) goto loc_827BFDA0;
loc_827BFDCC:
	// bl 0x827c2300
	ctx.lr = 0x827BFDD0;
	sub_827C2300(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x827bfdec
	if (!cr6.eq) goto loc_827BFDEC;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x827bfe10
	if (cr6.eq) goto loc_827BFE10;
	// li r24,1
	r24.s64 = 1;
	// b 0x827bfe10
	goto loc_827BFE10;
loc_827BFDEC:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x827bfe10
	if (!cr6.eq) goto loc_827BFE10;
	// lwz r11,704(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 704);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfe0c
	if (cr6.eq) goto loc_827BFE0C;
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// stw r11,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r11.u32);
	// b 0x827bfe10
	goto loc_827BFE10;
loc_827BFE0C:
	// stw r24,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r24.u32);
loc_827BFE10:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-21488(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -21488);
	// bl 0x827c1f90
	ctx.lr = 0x827BFE1C;
	sub_827C1F90(ctx, base);
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bfe30
	if (cr6.eq) goto loc_827BFE30;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be010
	ctx.lr = 0x827BFE30;
	sub_827BE010(ctx, base);
loc_827BFE30:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x827bfe44
	if (cr6.eq) goto loc_827BFE44;
	// lwz r11,836(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 836);
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// stw r11,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r11.u32);
loc_827BFE44:
	// lwz r3,236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_827BFE50"))) PPC_WEAK_FUNC(sub_827BFE50);
PPC_FUNC_IMPL(__imp__sub_827BFE50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r8,276(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r9,684(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 684);
	// lwz r11,284(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
loc_827BFE7C:
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r6,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmpw cr6,r6,r7
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, xer);
	// beq cr6,0x827bfea4
	if (cr6.eq) goto loc_827BFEA4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x827bfe7c
	if (cr6.lt) goto loc_827BFE7C;
	// blr 
	return;
loc_827BFEA4:
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mulli r11,r10,388
	r11.s64 = ctx.r10.s64 * 388;
	// lwz r10,280(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,360(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 360);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,280(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,360(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827BFEDC"))) PPC_WEAK_FUNC(sub_827BFEDC);
PPC_FUNC_IMPL(__imp__sub_827BFEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BFEE0"))) PPC_WEAK_FUNC(sub_827BFEE0);
PPC_FUNC_IMPL(__imp__sub_827BFEE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r8,276(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r9,684(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 684);
	// lwz r11,284(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
loc_827BFF10:
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r5,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// cmpw cr6,r5,r7
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, xer);
	// beq cr6,0x827bff38
	if (cr6.eq) goto loc_827BFF38;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x827bff10
	if (cr6.lt) goto loc_827BFF10;
	// blr 
	return;
loc_827BFF38:
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mulli r11,r10,388
	r11.s64 = ctx.r10.s64 * 388;
	// lwz r10,280(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,380(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 380);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,280(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827BFF70"))) PPC_WEAK_FUNC(sub_827BFF70);
PPC_FUNC_IMPL(__imp__sub_827BFF70) {
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
	ctx.lr = 0x827BFF78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r23,r25
	r23.u64 = r25.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827c004c
	if (cr6.eq) goto loc_827C004C;
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// mr r28,r25
	r28.u64 = r25.u64;
	// mr r26,r25
	r26.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827c004c
	if (!cr6.gt) goto loc_827C004C;
	// mr r30,r25
	r30.u64 = r25.u64;
	// lis r27,-32107
	r27.s64 = -2104164352;
	// li r29,1
	r29.s64 = 1;
loc_827BFFB4:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r11,372(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c0024
	if (cr6.eq) goto loc_827C0024;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x827bffe0
	if (!cr6.eq) goto loc_827BFFE0;
	// addi r4,r31,852
	ctx.r4.s64 = r31.s64 + 852;
	// lwz r3,-21488(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -21488);
	// mr r28,r29
	r28.u64 = r29.u64;
	// bl 0x827c1f60
	ctx.lr = 0x827BFFE0;
	sub_827C1F60(ctx, base);
loc_827BFFE0:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cntlzw r10,r24
	ctx.r10.u64 = r24.u32 == 0 ? 32 : __builtin_clz(r24.u32);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r11,1
	ctx.r4.u64 = r11.u64 ^ 1;
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827C0000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827c0058
	if (cr6.eq) goto loc_827C0058;
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// mr r23,r29
	r23.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c0024
	if (!cr6.eq) goto loc_827C0024;
	// stw r29,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r29.u32);
	// stw r25,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r25.u32);
	// stw r25,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r25.u32);
loc_827C0024:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,388
	r30.s64 = r30.s64 + 388;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x827bffb4
	if (cr6.lt) goto loc_827BFFB4;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x827c004c
	if (cr6.eq) goto loc_827C004C;
	// addi r4,r31,852
	ctx.r4.s64 = r31.s64 + 852;
	// lwz r3,-21488(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -21488);
	// bl 0x827c1f90
	ctx.lr = 0x827C004C;
	sub_827C1F90(ctx, base);
loc_827C004C:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_827C0058:
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c0024
	if (cr6.eq) goto loc_827C0024;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x827c009c
	if (!cr6.eq) goto loc_827C009C;
	// lwz r11,800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 800);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x827c00a8
	if (!cr6.eq) goto loc_827C00A8;
loc_827C009C:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x827bdf48
	ctx.lr = 0x827C00A8;
	sub_827BDF48(ctx, base);
loc_827C00A8:
	// stw r25,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r25.u32);
	// b 0x827c0024
	goto loc_827C0024;
}

__attribute__((alias("__imp__sub_827C00B0"))) PPC_WEAK_FUNC(sub_827C00B0);
PPC_FUNC_IMPL(__imp__sub_827C00B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x824696a0
	sub_824696A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827C00B4"))) PPC_WEAK_FUNC(sub_827C00B4);
PPC_FUNC_IMPL(__imp__sub_827C00B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C00B8"))) PPC_WEAK_FUNC(sub_827C00B8);
PPC_FUNC_IMPL(__imp__sub_827C00B8) {
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
	ctx.lr = 0x827C00C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827c00dc
	if (!cr6.eq) goto loc_827C00DC;
loc_827C00D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_827C00DC:
	// lwz r11,800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 800);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x827c00d0
	if (cr6.eq) goto loc_827C00D0;
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c0100
	if (cr6.eq) goto loc_827C0100;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
loc_827C0100:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c00d0
	if (!cr6.eq) goto loc_827C00D0;
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c0138
	if (cr6.eq) goto loc_827C0138;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827c0138
	if (cr6.eq) goto loc_827C0138;
	// lwz r10,744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
	// stw r30,700(r31)
	PPC_STORE_U32(r31.u32 + 700, r30.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r11.u32);
loc_827C0138:
	// lwz r11,812(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 812);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c0174
	if (cr6.eq) goto loc_827C0174;
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// stw r30,812(r31)
	PPC_STORE_U32(r31.u32 + 812, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c016c
	if (cr6.eq) goto loc_827C016C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bff70
	ctx.lr = 0x827C0160;
	sub_827BFF70(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bff70
	ctx.lr = 0x827C016C;
	sub_827BFF70(ctx, base);
loc_827C016C:
	// stw r30,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r30.u32);
	// stw r30,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r30.u32);
loc_827C0174:
	// lwz r11,236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827c0188
	if (cr6.eq) goto loc_827C0188;
	// stw r30,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r30.u32);
	// stw r30,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r30.u32);
loc_827C0188:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r30,820(r31)
	PPC_STORE_U32(r31.u32 + 820, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r29,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r29.u32);
	// beq cr6,0x827c01cc
	if (cr6.eq) goto loc_827C01CC;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c01cc
	if (cr6.eq) goto loc_827C01CC;
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c01cc
	if (!cr6.eq) goto loc_827C01CC;
	// lwz r3,204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827c01cc
	if (cr6.eq) goto loc_827C01CC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,200(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// bl 0x823d9890
	ctx.lr = 0x827C01CC;
	sub_823D9890(ctx, base);
loc_827C01CC:
	// lwz r11,204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r30.u32);
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827C01E4"))) PPC_WEAK_FUNC(sub_827C01E4);
PPC_FUNC_IMPL(__imp__sub_827C01E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C01E8"))) PPC_WEAK_FUNC(sub_827C01E8);
PPC_FUNC_IMPL(__imp__sub_827C01E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x827C01F0;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r21,0
	r21.s64 = 0;
	// bl 0x827c2300
	ctx.lr = 0x827C0200;
	sub_827C2300(ctx, base);
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// bl 0x827c00b8
	ctx.lr = 0x827C0210;
	sub_827C00B8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x827c0224
	if (!cr6.eq) goto loc_827C0224;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9214
	return;
loc_827C0224:
	// lwz r18,256(r29)
	r18.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// li r23,0
	r23.s64 = 0;
	// lwz r11,260(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 260);
	// lwz r10,224(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 224);
	// mr r31,r18
	r31.u64 = r18.u64;
	// add r20,r11,r18
	r20.u64 = r11.u64 + r18.u64;
	// lwz r15,188(r29)
	r15.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r17,284(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 284);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r19,r11,-21492
	r19.s64 = r11.s64 + -21492;
	// ble cr6,0x827c0428
	if (!cr6.gt) goto loc_827C0428;
loc_827C0254:
	// cmplw cr6,r31,r20
	cr6.compare<uint32_t>(r31.u32, r20.u32, xer);
	// bgt cr6,0x827c0414
	if (cr6.gt) goto loc_827C0414;
	// cmplw cr6,r31,r18
	cr6.compare<uint32_t>(r31.u32, r18.u32, xer);
	// blt cr6,0x827c0414
	if (cr6.lt) goto loc_827C0414;
	// lwz r10,276(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// li r11,0
	r11.s64 = 0;
	// lwz r22,0(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r24,r31,4
	r24.s64 = r31.s64 + 4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x827c0400
	if (!cr6.gt) goto loc_827C0400;
	// mr r10,r17
	ctx.r10.u64 = r17.u64;
loc_827C0280:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r23
	cr6.compare<int32_t>(ctx.r9.s32, r23.s32, xer);
	// beq cr6,0x827c02a4
	if (cr6.eq) goto loc_827C02A4;
	// lwz r9,276(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x827c0280
	if (cr6.lt) goto loc_827C0280;
	// b 0x827c0400
	goto loc_827C0400;
loc_827C02A4:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827c0400
	if (cr6.eq) goto loc_827C0400;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x827c0400
	if (cr6.eq) goto loc_827C0400;
	// addi r6,r24,4
	ctx.r6.s64 = r24.s64 + 4;
	// lwz r28,0(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// add r25,r6,r22
	r25.u64 = ctx.r6.u64 + r22.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// beq cr6,0x827c0400
	if (cr6.eq) goto loc_827C0400;
	// lwz r10,280(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 280);
	// mulli r11,r11,388
	r11.s64 = r11.s64 * 388;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// lwz r26,20(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bne cr6,0x827c02f8
	if (!cr6.eq) goto loc_827C02F8;
	// addi r4,r29,852
	ctx.r4.s64 = r29.s64 + 852;
	// lwz r3,4(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// li r21,1
	r21.s64 = 1;
	// bl 0x827c1f60
	ctx.lr = 0x827C02F4;
	sub_827C1F60(ctx, base);
	// lwz r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_827C02F8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// subf r27,r10,r11
	r27.s64 = r11.s64 - ctx.r10.s64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bge cr6,0x827c031c
	if (!cr6.lt) goto loc_827C031C;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r27,r11,r27
	r27.u64 = r11.u64 + r27.u64;
	// b 0x827c031c
	goto loc_827C031C;
loc_827C0318:
	// lwz r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_827C031C:
	// cmplw cr6,r6,r20
	cr6.compare<uint32_t>(ctx.r6.u32, r20.u32, xer);
	// bgt cr6,0x827c0400
	if (cr6.gt) goto loc_827C0400;
	// cmplw cr6,r6,r18
	cr6.compare<uint32_t>(ctx.r6.u32, r18.u32, xer);
	// blt cr6,0x827c0400
	if (cr6.lt) goto loc_827C0400;
	// cmplw cr6,r25,r20
	cr6.compare<uint32_t>(r25.u32, r20.u32, xer);
	// bgt cr6,0x827c0400
	if (cr6.gt) goto loc_827C0400;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
	// rlwinm r31,r11,0,0,27
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// ble cr6,0x827c034c
	if (!cr6.gt) goto loc_827C034C;
	// addi r31,r31,-16
	r31.s64 = r31.s64 + -16;
loc_827C034C:
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827c2ef8
	ctx.lr = 0x827C0364;
	sub_827C2EF8(ctx, base);
	// lwz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplw cr6,r5,r28
	cr6.compare<uint32_t>(ctx.r5.u32, r28.u32, xer);
	// ble cr6,0x827c0378
	if (!cr6.gt) goto loc_827C0378;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
loc_827C0378:
	// subf r28,r5,r28
	r28.s64 = r28.s64 - ctx.r5.s64;
	// cmplw cr6,r5,r31
	cr6.compare<uint32_t>(ctx.r5.u32, r31.u32, xer);
	// ble cr6,0x827c038c
	if (!cr6.gt) goto loc_827C038C;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
loc_827C038C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// subf r31,r3,r11
	r31.s64 = r11.s64 - ctx.r3.s64;
	// cmplw cr6,r31,r5
	cr6.compare<uint32_t>(r31.u32, ctx.r5.u32, xer);
	// bge cr6,0x827c03e0
	if (!cr6.lt) goto loc_827C03E0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827c03cc
	if (cr6.eq) goto loc_827C03CC;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823da950
	ctx.lr = 0x827C03B4;
	sub_823DA950(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// subf r5,r31,r11
	ctx.r5.s64 = r11.s64 - r31.s64;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
loc_827C03CC:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823da950
	ctx.lr = 0x827C03D8;
	sub_823DA950(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// b 0x827c03ec
	goto loc_827C03EC;
loc_827C03E0:
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823da950
	ctx.lr = 0x827C03E8;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_827C03EC:
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// bne cr6,0x827c0318
	if (!cr6.eq) goto loc_827C0318;
loc_827C0400:
	// lwz r11,224(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 224);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// add r31,r22,r24
	r31.u64 = r22.u64 + r24.u64;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x827c0254
	if (cr6.lt) goto loc_827C0254;
loc_827C0414:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x827c0428
	if (cr6.eq) goto loc_827C0428;
	// addi r4,r29,852
	ctx.r4.s64 = r29.s64 + 852;
	// lwz r3,4(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// bl 0x827c1f90
	ctx.lr = 0x827C0428;
	sub_827C1F90(ctx, base);
loc_827C0428:
	// bl 0x827c2300
	ctx.lr = 0x827C042C;
	sub_827C2300(ctx, base);
	// lwz r11,252(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 252);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// subf r27,r16,r28
	r27.s64 = r28.s64 - r16.s64;
	// beq cr6,0x827c051c
	if (cr6.eq) goto loc_827C051C;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x827c051c
	if (cr6.eq) goto loc_827C051C;
	// lwz r11,328(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 328);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c04d8
	if (!cr6.eq) goto loc_827C04D8;
	// lwz r11,372(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c04d8
	if (!cr6.eq) goto loc_827C04D8;
	// lwz r11,228(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 228);
	// lwz r10,408(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 408);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x827c0474
	if (cr6.lt) goto loc_827C0474;
	// lwz r11,408(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 408);
loc_827C0474:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,412(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 412);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bge cr6,0x827c04d8
	if (!cr6.lt) goto loc_827C04D8;
	// addi r30,r29,596
	r30.s64 = r29.s64 + 596;
	// lwz r3,0(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x827c1f08
	ctx.lr = 0x827C049C;
	sub_827C1F08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827c04c4
	if (cr6.eq) goto loc_827C04C4;
	// lwz r11,352(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 352);
	// addi r3,r29,336
	ctx.r3.s64 = r29.s64 + 336;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827C04B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// bl 0x827c1f90
	ctx.lr = 0x827C04C0;
	sub_827C1F90(ctx, base);
	// b 0x827c04d8
	goto loc_827C04D8;
loc_827C04C4:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// rlwinm r11,r11,0,4,4
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c04d8
	if (!cr6.eq) goto loc_827C04D8;
	// bl 0x827c2058
	ctx.lr = 0x827C04D8;
	sub_827C2058(ctx, base);
loc_827C04D8:
	// lwz r23,32(r29)
	r23.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplw cr6,r31,r20
	cr6.compare<uint32_t>(r31.u32, r20.u32, xer);
	// bgt cr6,0x827c051c
	if (cr6.gt) goto loc_827C051C;
	// cmplw cr6,r31,r18
	cr6.compare<uint32_t>(r31.u32, r18.u32, xer);
	// blt cr6,0x827c051c
	if (cr6.lt) goto loc_827C051C;
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// addi r9,r29,288
	ctx.r9.s64 = r29.s64 + 288;
	// lwz r7,268(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 268);
	// mr r8,r20
	ctx.r8.u64 = r20.u64;
	// lwz r5,196(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 196);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,208(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 208);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x827c6ea8
	ctx.lr = 0x827C0518;
	sub_827C6EA8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
loc_827C051C:
	// lwz r11,740(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 740);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// stw r11,740(r29)
	PPC_STORE_U32(r29.u32 + 740, r11.u32);
	// bl 0x827c2300
	ctx.lr = 0x827C052C;
	sub_827C2300(ctx, base);
	// lwz r11,736(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 736);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,324(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 324);
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// cmplw cr6,r23,r10
	cr6.compare<uint32_t>(r23.u32, ctx.r10.u32, xer);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stw r11,736(r29)
	PPC_STORE_U32(r29.u32 + 736, r11.u32);
	// ble cr6,0x827c0550
	if (!cr6.gt) goto loc_827C0550;
	// stw r23,324(r29)
	PPC_STORE_U32(r29.u32 + 324, r23.u32);
loc_827C0550:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bf908
	ctx.lr = 0x827C0558;
	sub_827BF908(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_827C0560"))) PPC_WEAK_FUNC(sub_827C0560);
PPC_FUNC_IMPL(__imp__sub_827C0560) {
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
	ctx.lr = 0x827C0568;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mr r30,r26
	r30.u64 = r26.u64;
	// beq cr6,0x827c073c
	if (cr6.eq) goto loc_827C073C;
	// lwz r11,820(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 820);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c0594
	if (!cr6.eq) goto loc_827C0594;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bf7d0
	ctx.lr = 0x827C0594;
	sub_827BF7D0(ctx, base);
loc_827C0594:
	// lwz r11,824(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 824);
	// stw r26,820(r31)
	PPC_STORE_U32(r31.u32 + 820, r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r26,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r26.u32);
	// beq cr6,0x827c05b0
	if (cr6.eq) goto loc_827C05B0;
	// stw r26,824(r31)
	PPC_STORE_U32(r31.u32 + 824, r26.u32);
	// b 0x827c061c
	goto loc_827C061C;
loc_827C05B0:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827c06d0
	if (!cr6.gt) goto loc_827C06D0;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_827C05C4:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827c0600
	if (cr6.eq) goto loc_827C0600;
	// stw r26,84(r11)
	PPC_STORE_U32(r11.u32 + 84, r26.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x827c0600
	if (!cr6.gt) goto loc_827C0600;
	// lwz r9,280(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,68(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bgt cr6,0x827c0600
	if (cr6.gt) goto loc_827C0600;
	// li r30,1
	r30.s64 = 1;
loc_827C0600:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,388
	ctx.r10.s64 = ctx.r10.s64 + 388;
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// blt cr6,0x827c05c4
	if (cr6.lt) goto loc_827C05C4;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x827c06d0
	if (cr6.eq) goto loc_827C06D0;
loc_827C061C:
	// lwz r11,816(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 816);
	// addi r29,r31,596
	r29.s64 = r31.s64 + 596;
	// addi r28,r31,852
	r28.s64 = r31.s64 + 852;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r30,r11,-21488
	r30.s64 = r11.s64 + -21488;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r10,816(r31)
	PPC_STORE_U32(r31.u32 + 816, ctx.r10.u32);
	// lwz r5,-4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x827c1f80
	ctx.lr = 0x827C064C;
	sub_827C1F80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bff70
	ctx.lr = 0x827C0658;
	sub_827BFF70(ctx, base);
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lwz r10,412(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// mulli r11,r11,29
	r11.s64 = r11.s64 * 29;
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x827c06a4
	if (!cr6.lt) goto loc_827C06A4;
	// addi r27,r31,336
	r27.s64 = r31.s64 + 336;
loc_827C0674:
	// lwz r11,352(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827C0684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827c06a4
	if (cr6.eq) goto loc_827C06A4;
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lwz r10,412(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// mulli r11,r11,29
	r11.s64 = r11.s64 * 29;
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x827c0674
	if (cr6.lt) goto loc_827C0674;
loc_827C06A4:
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r26,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r26.u32);
	// bl 0x827bff70
	ctx.lr = 0x827C06B8;
	sub_827BFF70(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x827c1f90
	ctx.lr = 0x827C06C4;
	sub_827C1F90(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// bl 0x827c1f90
	ctx.lr = 0x827C06D0;
	sub_827C1F90(ctx, base);
loc_827C06D0:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// stw r11,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r11.u32);
	// beq cr6,0x827c06ec
	if (cr6.eq) goto loc_827C06EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be010
	ctx.lr = 0x827C06EC;
	sub_827BE010(ctx, base);
loc_827C06EC:
	// bl 0x827c2300
	ctx.lr = 0x827C06F0;
	sub_827C2300(ctx, base);
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c0718
	if (cr6.eq) goto loc_827C0718;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827c0718
	if (cr6.eq) goto loc_827C0718;
	// lwz r10,744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// stw r26,700(r31)
	PPC_STORE_U32(r31.u32 + 700, r26.u32);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stw r11,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r11.u32);
loc_827C0718:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x827c0730
	if (!cr6.lt) goto loc_827C0730;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
loc_827C0730:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827be310
	ctx.lr = 0x827C0738;
	sub_827BE310(ctx, base);
	// stw r26,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r26.u32);
loc_827C073C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827C0744"))) PPC_WEAK_FUNC(sub_827C0744);
PPC_FUNC_IMPL(__imp__sub_827C0744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C0748"))) PPC_WEAK_FUNC(sub_827C0748);
PPC_FUNC_IMPL(__imp__sub_827C0748) {
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
	ctx.lr = 0x827C0750;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827c0904
	if (cr6.eq) goto loc_827C0904;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bfd18
	ctx.lr = 0x827C0768;
	sub_827BFD18(ctx, base);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r10,-21336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -21336);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827c0788
	if (cr6.eq) goto loc_827C0788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827C0788;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827C0788:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r11,r11,0,4,4
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r30,r11,-21488
	r30.s64 = r11.s64 + -21488;
	// bne cr6,0x827c07b4
	if (!cr6.eq) goto loc_827C07B4;
	// lwz r11,328(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c07b4
	if (!cr6.eq) goto loc_827C07B4;
	// lwz r3,-4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// b 0x827c07b8
	goto loc_827C07B8;
loc_827C07B4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827C07B8:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c07cc
	if (cr6.eq) goto loc_827C07CC;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x827c07d0
	goto loc_827C07D0;
loc_827C07CC:
	// li r5,0
	ctx.r5.s64 = 0;
loc_827C07D0:
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,852
	ctx.r6.s64 = r31.s64 + 852;
	// addi r4,r31,596
	ctx.r4.s64 = r31.s64 + 596;
	// bl 0x827c2118
	ctx.lr = 0x827C07E0;
	sub_827C2118(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x827c080c
	if (cr6.eq) goto loc_827C080C;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x827c0800
	if (cr6.eq) goto loc_827C0800;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x827c0814
	if (!cr6.eq) goto loc_827C0814;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r11.u32);
loc_827C0800:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x827c0814
	goto loc_827C0814;
loc_827C080C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r11.u32);
loc_827C0814:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827c0878
	if (!cr6.gt) goto loc_827C0878;
	// li r30,0
	r30.s64 = 0;
loc_827C0828:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827C083C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x827c2ef0
	ctx.lr = 0x827C084C;
	sub_827C2EF0(ctx, base);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827c0864
	if (cr6.eq) goto loc_827C0864;
	// bl 0x82469780
	ctx.lr = 0x827C0864;
	sub_82469780(ctx, base);
loc_827C0864:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,388
	r30.s64 = r30.s64 + 388;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827c0828
	if (cr6.lt) goto loc_827C0828;
loc_827C0878:
	// lwz r3,328(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827c0898
	if (cr6.eq) goto loc_827C0898;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r11,r11,0,5,5
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c08b0
	if (!cr6.eq) goto loc_827C08B0;
	// b 0x827c08ac
	goto loc_827C08AC;
loc_827C0898:
	// lwz r11,356(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// addi r3,r31,336
	ctx.r3.s64 = r31.s64 + 336;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827C08A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,660(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 660);
loc_827C08AC:
	// bl 0x82469780
	ctx.lr = 0x827C08B0;
	sub_82469780(ctx, base);
loc_827C08B0:
	// lwz r3,920(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 920);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827c08c0
	if (cr6.eq) goto loc_827C08C0;
	// bl 0x82469780
	ctx.lr = 0x827C08C0;
	sub_82469780(ctx, base);
loc_827C08C0:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827c08d0
	if (cr6.eq) goto loc_827C08D0;
	// bl 0x82469780
	ctx.lr = 0x827C08D0;
	sub_82469780(ctx, base);
loc_827C08D0:
	// lwz r3,204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827c08ec
	if (cr6.eq) goto loc_827C08EC;
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x827c08ec
	if (cr6.eq) goto loc_827C08EC;
	// bl 0x82469780
	ctx.lr = 0x827C08EC;
	sub_82469780(ctx, base);
loc_827C08EC:
	// li r5,924
	ctx.r5.s64 = 924;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x827C08FC;
	sub_823D9890(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82469780
	ctx.lr = 0x827C0904;
	sub_82469780(ctx, base);
loc_827C0904:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827C090C"))) PPC_WEAK_FUNC(sub_827C090C);
PPC_FUNC_IMPL(__imp__sub_827C090C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C0910"))) PPC_WEAK_FUNC(sub_827C0910);
PPC_FUNC_IMPL(__imp__sub_827C0910) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c0bb8
	if (cr6.eq) goto loc_827C0BB8;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x827c0944
	if (!cr6.gt) goto loc_827C0944;
	// li r11,32767
	r11.s64 = 32767;
loc_827C0944:
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// lfd f2,-21088(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + -21088);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lfs f0,-124(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -124);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dc480
	ctx.lr = 0x827C0970;
	sub_823DC480(ctx, base);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// bl 0x823ea640
	ctx.lr = 0x827C097C;
	sub_823EA640(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fdiv f1,f13,f0
	ctx.f1.f64 = ctx.f13.f64 / f0.f64;
	// bl 0x823db788
	ctx.lr = 0x827C09A4;
	sub_823DB788(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lfd f0,12368(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 12368);
	// fmul f0,f1,f0
	f0.f64 = ctx.f1.f64 * f0.f64;
	// frsp f1,f0
	ctx.f1.f64 = double(float(f0.f64));
	// bl 0x823ea6b8
	ctx.lr = 0x827C09BC;
	sub_823EA6B8(ctx, base);
	// lwz r9,248(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x827c09d4
	if (!cr6.eq) goto loc_827C09D4;
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827c0bb8
	if (cr6.eq) goto loc_827C0BB8;
loc_827C09D4:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// li r11,1
	r11.s64 = 1;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r11.u8);
	// li r7,4
	ctx.r7.s64 = 4;
	// stb r11,121(r1)
	PPC_STORE_U8(ctx.r1.u32 + 121, r11.u8);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r11,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r11.u8);
	// stb r11,168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 168, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,169(r1)
	PPC_STORE_U8(ctx.r1.u32 + 169, r11.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r11.u8);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r11,184(r1)
	PPC_STORE_U8(ctx.r1.u32 + 184, r11.u8);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stb r11,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, r11.u8);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stb r11,200(r1)
	PPC_STORE_U8(ctx.r1.u32 + 200, r11.u8);
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// li r8,5
	ctx.r8.s64 = 5;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stb r10,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, ctx.r10.u8);
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stb r10,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, ctx.r10.u8);
	// stfs f0,180(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stb r10,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r10.u8);
	// stfs f0,188(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stb r10,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r10.u8);
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stb r5,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, ctx.r5.u8);
	// stfs f0,204(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stb r10,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, ctx.r10.u8);
	// stb r6,137(r1)
	PPC_STORE_U8(ctx.r1.u32 + 137, ctx.r6.u8);
	// stb r10,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, ctx.r10.u8);
	// stb r7,145(r1)
	PPC_STORE_U8(ctx.r1.u32 + 145, ctx.r7.u8);
	// stb r10,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, ctx.r10.u8);
	// stb r8,153(r1)
	PPC_STORE_U8(ctx.r1.u32 + 153, ctx.r8.u8);
	// stb r10,161(r1)
	PPC_STORE_U8(ctx.r1.u32 + 161, ctx.r10.u8);
	// stb r5,177(r1)
	PPC_STORE_U8(ctx.r1.u32 + 177, ctx.r5.u8);
	// stb r6,185(r1)
	PPC_STORE_U8(ctx.r1.u32 + 185, ctx.r6.u8);
	// stb r7,193(r1)
	PPC_STORE_U8(ctx.r1.u32 + 193, ctx.r7.u8);
	// stb r8,201(r1)
	PPC_STORE_U8(ctx.r1.u32 + 201, ctx.r8.u8);
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// beq cr6,0x827c0b4c
	if (cr6.eq) goto loc_827C0B4C;
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// stw r10,248(r31)
	PPC_STORE_U32(r31.u32 + 248, ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827c0af8
	if (!cr6.eq) goto loc_827C0AF8;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// li r11,12
	r11.s64 = 12;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_827C0AE0:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c0ae0
	if (!cr6.eq) goto loc_827C0AE0;
	// b 0x827c0b4c
	goto loc_827C0B4C;
loc_827C0AF8:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827c0b4c
	if (cr6.eq) goto loc_827C0B4C;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r5,256(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r4,r3,-1
	ctx.r4.s64 = ctx.r3.s64 + -1;
	// addi r9,r31,264
	ctx.r9.s64 = r31.s64 + 264;
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_827C0B18:
	// and r8,r4,r11
	ctx.r8.u64 = ctx.r4.u64 & r11.u64;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r30,r1,116
	r30.s64 = ctx.r1.s64 + 116;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r8,r8,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stfsx f0,r8,r30
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + r30.u32, temp.u32);
	// blt cr6,0x827c0b18
	if (cr6.lt) goto loc_827C0B18;
loc_827C0B4C:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827c0bac
	if (cr6.eq) goto loc_827C0BAC;
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827c0bac
	if (!cr6.gt) goto loc_827C0BAC;
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r5,r3,-1
	ctx.r5.s64 = ctx.r3.s64 + -1;
	// addi r11,r31,312
	r11.s64 = r31.s64 + 312;
loc_827C0B74:
	// and r9,r5,r10
	ctx.r9.u64 = ctx.r5.u64 & ctx.r10.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// lfs f0,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f0.f64 = double(temp.f32);
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stfsx f0,r9,r4
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r4.u32, temp.u32);
	// blt cr6,0x827c0b74
	if (cr6.lt) goto loc_827C0B74;
loc_827C0BAC:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x823ea218
	ctx.lr = 0x827C0BB8;
	sub_823EA218(ctx, base);
loc_827C0BB8:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827C0BD0"))) PPC_WEAK_FUNC(sub_827C0BD0);
PPC_FUNC_IMPL(__imp__sub_827C0BD0) {
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
	ctx.lr = 0x827C0BD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r30,r29
	r30.u64 = r29.u64;
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x827c0c00
	if (!cr6.gt) goto loc_827C0C00;
	// subf r30,r11,r10
	r30.s64 = ctx.r10.s64 - r11.s64;
loc_827C0C00:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,152(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823d9890
	ctx.lr = 0x827C0C14;
	sub_823D9890(ctx, base);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// bge cr6,0x827c0c2c
	if (!cr6.lt) goto loc_827C0C2C;
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// lwz r4,152(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x823d9890
	ctx.lr = 0x827C0C2C;
	sub_823D9890(ctx, base);
loc_827C0C2C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827C0C34"))) PPC_WEAK_FUNC(sub_827C0C34);
PPC_FUNC_IMPL(__imp__sub_827C0C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C0C38"))) PPC_WEAK_FUNC(sub_827C0C38);
PPC_FUNC_IMPL(__imp__sub_827C0C38) {
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
	ctx.lr = 0x827C0C40;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827c0df8
	if (!cr6.eq) goto loc_827C0DF8;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827c0df8
	if (cr6.eq) goto loc_827C0DF8;
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827c0c78
	if (!cr6.eq) goto loc_827C0C78;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
loc_827C0C78:
	// lwz r30,228(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// bl 0x827c2300
	ctx.lr = 0x827C0C80;
	sub_827C2300(ctx, base);
	// lwz r11,236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// li r27,0
	r27.s64 = 0;
	// li r26,1
	r26.s64 = 1;
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x827c0d7c
	if (cr6.gt) goto loc_827C0D7C;
loc_827C0C98:
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bge cr6,0x827c0cb4
	if (!cr6.lt) goto loc_827C0CB4;
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// b 0x827c0cb8
	goto loc_827C0CB8;
loc_827C0CB4:
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
loc_827C0CB8:
	// cmplwi cr6,r11,1024
	cr6.compare<uint32_t>(r11.u32, 1024, xer);
	// bge cr6,0x827c0cc8
	if (!cr6.lt) goto loc_827C0CC8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x827c0cd0
	goto loc_827C0CD0;
loc_827C0CC8:
	// addi r11,r11,-1024
	r11.s64 = r11.s64 + -1024;
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
loc_827C0CD0:
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x827c0cf0
	if (!cr6.lt) goto loc_827C0CF0;
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827c0df8
	if (cr6.eq) goto loc_827C0DF8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c0df8
	if (cr6.eq) goto loc_827C0DF8;
loc_827C0CF0:
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x827c0de8
	if (cr6.lt) goto loc_827C0DE8;
loc_827C0CFC:
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r30,r31,92
	r30.s64 = r31.s64 + 92;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// rlwinm r29,r10,1,0,30
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r26,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r26.u32);
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// lwz r10,96(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x827c0d28
	if (!cr6.gt) goto loc_827C0D28;
	// subf r28,r11,r10
	r28.s64 = ctx.r10.s64 - r11.s64;
loc_827C0D28:
	// lwz r10,92(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r4,152(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 152);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823d9890
	ctx.lr = 0x827C0D3C;
	sub_823D9890(ctx, base);
	// cmplw cr6,r28,r29
	cr6.compare<uint32_t>(r28.u32, r29.u32, xer);
	// bge cr6,0x827c0d54
	if (!cr6.lt) goto loc_827C0D54;
	// subf r5,r28,r29
	ctx.r5.s64 = r29.s64 - r28.s64;
	// lwz r4,152(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 152);
	// lwz r3,92(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// bl 0x823d9890
	ctx.lr = 0x827C0D54;
	sub_823D9890(ctx, base);
loc_827C0D54:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r9,216(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r11,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r11.u32);
	// blt cr6,0x827c0d7c
	if (cr6.lt) goto loc_827C0D7C;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stw r11,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r11.u32);
loc_827C0D7C:
	// lwz r30,92(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 92);
loc_827C0D80:
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r27,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r27.u32);
	// bl 0x823ea4e0
	ctx.lr = 0x827C0D94;
	sub_823EA4E0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ea4e0
	ctx.lr = 0x827C0DA0;
	sub_823EA4E0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ea4e0
	ctx.lr = 0x827C0DAC;
	sub_823EA4E0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// cmplwi cr6,r10,1024
	cr6.compare<uint32_t>(ctx.r10.u32, 1024, xer);
	// bge cr6,0x827c0d80
	if (!cr6.lt) goto loc_827C0D80;
	// mr r30,r11
	r30.u64 = r11.u64;
	// bl 0x827c2300
	ctx.lr = 0x827C0DC8;
	sub_827C2300(ctx, base);
	// lwz r11,236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lwz r10,240(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// stw r30,228(r31)
	PPC_STORE_U32(r31.u32 + 228, r30.u32);
	// stw r3,236(r31)
	PPC_STORE_U32(r31.u32 + 236, ctx.r3.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x827c0cfc
	if (!cr6.lt) goto loc_827C0CFC;
	// b 0x827c0c98
	goto loc_827C0C98;
loc_827C0DE8:
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
loc_827C0DF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827C0E04"))) PPC_WEAK_FUNC(sub_827C0E04);
PPC_FUNC_IMPL(__imp__sub_827C0E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C0E08"))) PPC_WEAK_FUNC(sub_827C0E08);
PPC_FUNC_IMPL(__imp__sub_827C0E08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// lwz r10,216(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// lwz r9,188(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// ble cr6,0x827c0e24
	if (!cr6.gt) goto loc_827C0E24;
	// subf r11,r10,r9
	r11.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_827C0E24:
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// li r3,1
	ctx.r3.s64 = 1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827C0E3C"))) PPC_WEAK_FUNC(sub_827C0E3C);
PPC_FUNC_IMPL(__imp__sub_827C0E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C0E40"))) PPC_WEAK_FUNC(sub_827C0E40);
PPC_FUNC_IMPL(__imp__sub_827C0E40) {
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
	ctx.lr = 0x827C0E48;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// bl 0x823ea380
	ctx.lr = 0x827C0E68;
	sub_823EA380(ctx, base);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// li r29,-1
	r29.s64 = -1;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x823ea320
	ctx.lr = 0x827C0E98;
	sub_823EA320(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823ea590
	ctx.lr = 0x827C0EA4;
	sub_823EA590(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823ea538
	ctx.lr = 0x827C0EB0;
	sub_823EA538(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823ea3d8
	ctx.lr = 0x827C0EBC;
	sub_823EA3D8(ctx, base);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// bl 0x827c2300
	ctx.lr = 0x827C0EC4;
	sub_827C2300(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823ea4e0
	ctx.lr = 0x827C0ED4;
	sub_823EA4E0(ctx, base);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r28,r30
	r28.u64 = r30.u64;
loc_827C0EDC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// bl 0x823ea4e0
	ctx.lr = 0x827C0EEC;
	sub_823EA4E0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// beq cr6,0x827c0f04
	if (cr6.eq) goto loc_827C0F04;
	// li r28,1
	r28.s64 = 1;
	// b 0x827c0f4c
	goto loc_827C0F4C;
loc_827C0F04:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827c0f4c
	if (!cr6.eq) goto loc_827C0F4C;
	// bl 0x827c2300
	ctx.lr = 0x827C0F10;
	sub_827C2300(ctx, base);
	// subf r11,r27,r3
	r11.s64 = ctx.r3.s64 - r27.s64;
	// cmplwi cr6,r11,50
	cr6.compare<uint32_t>(r11.u32, 50, xer);
	// ble cr6,0x827c0f4c
	if (!cr6.gt) goto loc_827C0F4C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823ea3d8
	ctx.lr = 0x827C0F28;
	sub_823EA3D8(ctx, base);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// bl 0x827c2300
	ctx.lr = 0x827C0F30;
	sub_827C2300(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// bl 0x823ea4e0
	ctx.lr = 0x827C0F44;
	sub_823EA4E0(ctx, base);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r28,r30
	r28.u64 = r30.u64;
loc_827C0F4C:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x827c0edc
	if (cr6.gt) goto loc_827C0EDC;
	// bl 0x827c2300
	ctx.lr = 0x827C0F60;
	sub_827C2300(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827C0F6C"))) PPC_WEAK_FUNC(sub_827C0F6C);
PPC_FUNC_IMPL(__imp__sub_827C0F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C0F70"))) PPC_WEAK_FUNC(sub_827C0F70);
PPC_FUNC_IMPL(__imp__sub_827C0F70) {
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
	// lwz r11,216(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// lwz r10,188(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r11,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, r11.u32);
	// blt cr6,0x827c0f9c
	if (cr6.lt) goto loc_827C0F9C;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stw r11,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, r11.u32);
loc_827C0F9C:
	// lwz r11,220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,220(r3)
	PPC_STORE_U32(ctx.r3.u32 + 220, r11.u32);
	// bne cr6,0x827c0fd0
	if (!cr6.eq) goto loc_827C0FD0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c0fd0
	if (!cr6.eq) goto loc_827C0FD0;
	// lwz r11,212(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827c0fd0
	if (!cr6.eq) goto loc_827C0FD0;
	// addi r3,r3,92
	ctx.r3.s64 = ctx.r3.s64 + 92;
	// bl 0x827c0e40
	ctx.lr = 0x827C0FD0;
	sub_827C0E40(ctx, base);
loc_827C0FD0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827C0FE4"))) PPC_WEAK_FUNC(sub_827C0FE4);
PPC_FUNC_IMPL(__imp__sub_827C0FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C0FE8"))) PPC_WEAK_FUNC(sub_827C0FE8);
PPC_FUNC_IMPL(__imp__sub_827C0FE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,32767
	cr6.compare<int32_t>(ctx.r4.s32, 32767, xer);
	// ble cr6,0x827c0ff4
	if (!cr6.gt) goto loc_827C0FF4;
	// li r4,32767
	ctx.r4.s64 = 32767;
loc_827C0FF4:
	// stw r4,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r4.u32);
	// b 0x827c0910
	sub_827C0910(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827C0FFC"))) PPC_WEAK_FUNC(sub_827C0FFC);
PPC_FUNC_IMPL(__imp__sub_827C0FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C1000"))) PPC_WEAK_FUNC(sub_827C1000);
PPC_FUNC_IMPL(__imp__sub_827C1000) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,1
	r11.s64 = 65536;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// ble cr6,0x827c1010
	if (!cr6.gt) goto loc_827C1010;
	// lis r4,1
	ctx.r4.s64 = 65536;
loc_827C1010:
	// stw r4,204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 204, ctx.r4.u32);
	// b 0x827c0910
	sub_827C0910(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827C1018"))) PPC_WEAK_FUNC(sub_827C1018);
PPC_FUNC_IMPL(__imp__sub_827C1018) {
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
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// ble cr6,0x827c103c
	if (!cr6.gt) goto loc_827C103C;
	// li r11,12
	r11.s64 = 12;
loc_827C103C:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r31,264
	ctx.r3.s64 = r31.s64 + 264;
	// stw r10,248(r31)
	PPC_STORE_U32(r31.u32 + 248, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x827C1054;
	sub_823DA950(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827c0910
	ctx.lr = 0x827C105C;
	sub_827C0910(ctx, base);
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

__attribute__((alias("__imp__sub_827C1070"))) PPC_WEAK_FUNC(sub_827C1070);
PPC_FUNC_IMPL(__imp__sub_827C1070) {
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
	ctx.lr = 0x827C1078;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,12
	cr6.compare<uint32_t>(r31.u32, 12, xer);
	// ble cr6,0x827c1094
	if (!cr6.gt) goto loc_827C1094;
	// li r31,12
	r31.s64 = 12;
loc_827C1094:
	// li r11,1
	r11.s64 = 1;
	// stw r31,260(r30)
	PPC_STORE_U32(r30.u32 + 260, r31.u32);
	// rlwinm r5,r31,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r30,312
	ctx.r3.s64 = r30.s64 + 312;
	// stw r11,252(r30)
	PPC_STORE_U32(r30.u32 + 252, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x827C10AC;
	sub_823DA950(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// lfs f0,-124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -124);
	f0.f64 = double(temp.f32);
	// blt cr6,0x827c119c
	if (cr6.lt) goto loc_827C119C;
	// addi r10,r31,-4
	ctx.r10.s64 = r31.s64 + -4;
	// addi r11,r29,8
	r11.s64 = r29.s64 + 8;
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r30,364
	ctx.r10.s64 = r30.s64 + 364;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_827C10D8:
	// lwz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// cmpwi cr6,r9,32767
	cr6.compare<int32_t>(ctx.r9.s32, 32767, xer);
	// ble cr6,0x827c10e8
	if (!cr6.gt) goto loc_827C10E8;
	// li r9,32767
	ctx.r9.s64 = 32767;
loc_827C10E8:
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,-4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpwi cr6,r9,32767
	cr6.compare<int32_t>(ctx.r9.s32, 32767, xer);
	// ble cr6,0x827c1114
	if (!cr6.gt) goto loc_827C1114;
	// li r9,32767
	ctx.r9.s64 = 32767;
loc_827C1114:
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,32767
	cr6.compare<int32_t>(ctx.r9.s32, 32767, xer);
	// ble cr6,0x827c1140
	if (!cr6.gt) goto loc_827C1140;
	// li r9,32767
	ctx.r9.s64 = 32767;
loc_827C1140:
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r9,32767
	cr6.compare<int32_t>(ctx.r9.s32, 32767, xer);
	// ble cr6,0x827c116c
	if (!cr6.gt) goto loc_827C116C;
	// li r9,32767
	ctx.r9.s64 = 32767;
loc_827C116C:
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f13,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,8(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne cr6,0x827c10d8
	if (!cr6.eq) goto loc_827C10D8;
loc_827C119C:
	// cmplw cr6,r7,r31
	cr6.compare<uint32_t>(ctx.r7.u32, r31.u32, xer);
	// bge cr6,0x827c11fc
	if (!cr6.lt) goto loc_827C11FC;
	// addi r11,r7,90
	r11.s64 = ctx.r7.s64 + 90;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// subf r11,r7,r31
	r11.s64 = r31.s64 - ctx.r7.s64;
loc_827C11BC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,32767
	cr6.compare<int32_t>(ctx.r8.s32, 32767, xer);
	// ble cr6,0x827c11cc
	if (!cr6.gt) goto loc_827C11CC;
	// li r8,32767
	ctx.r8.s64 = 32767;
loc_827C11CC:
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// std r8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f13,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne cr6,0x827c11bc
	if (!cr6.eq) goto loc_827C11BC;
loc_827C11FC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827c0910
	ctx.lr = 0x827C1204;
	sub_827C0910(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827C120C"))) PPC_WEAK_FUNC(sub_827C120C);
PPC_FUNC_IMPL(__imp__sub_827C120C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C1210"))) PPC_WEAK_FUNC(sub_827C1210);
PPC_FUNC_IMPL(__imp__sub_827C1210) {
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
	ctx.lr = 0x827C1218;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// beq cr6,0x827c125c
	if (cr6.eq) goto loc_827C125C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827c12c0
	if (!cr6.eq) goto loc_827C12C0;
	// lwz r10,224(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// li r11,1
	r11.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r30,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r30.u32);
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// stw r10,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_827C125C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827c12c0
	if (cr6.eq) goto loc_827C12C0;
	// li r30,0
	r30.s64 = 0;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r29,r31,92
	r29.s64 = r31.s64 + 92;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// bl 0x823ea420
	ctx.lr = 0x827C127C;
	sub_823EA420(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x827c12a0
	if (cr6.lt) goto loc_827C12A0;
loc_827C1284:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// bl 0x823ea2c8
	ctx.lr = 0x827C1294;
	sub_823EA2C8(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x827c1284
	if (cr6.eq) goto loc_827C1284;
loc_827C12A0:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x823ea538
	ctx.lr = 0x827C12AC;
	sub_823EA538(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,188(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x827c0bd0
	ctx.lr = 0x827C12BC;
	sub_827C0BD0(ctx, base);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
loc_827C12C0:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827C12CC"))) PPC_WEAK_FUNC(sub_827C12CC);
PPC_FUNC_IMPL(__imp__sub_827C12CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C12D0"))) PPC_WEAK_FUNC(sub_827C12D0);
PPC_FUNC_IMPL(__imp__sub_827C12D0) {
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
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// beq cr6,0x827c1310
	if (cr6.eq) goto loc_827C1310;
	// li r30,1
	r30.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827c134c
	if (cr6.eq) goto loc_827C134C;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x823ea420
	ctx.lr = 0x827C130C;
	sub_823EA420(ctx, base);
	// b 0x827c1348
	goto loc_827C1348;
loc_827C1310:
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827c1334
	if (!cr6.eq) goto loc_827C1334;
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827c134c
	if (!cr6.eq) goto loc_827C134C;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x827c0e40
	ctx.lr = 0x827C1330;
	sub_827C0E40(ctx, base);
	// b 0x827c134c
	goto loc_827C134C;
loc_827C1334:
	// bl 0x827c2300
	ctx.lr = 0x827C1338;
	sub_827C2300(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,236(r31)
	PPC_STORE_U32(r31.u32 + 236, ctx.r3.u32);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x823ea3d8
	ctx.lr = 0x827C1348;
	sub_823EA3D8(ctx, base);
loc_827C1348:
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
loc_827C134C:
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
	// rotlwi r3,r30,0
	ctx.r3.u64 = __builtin_rotateleft32(r30.u32, 0);
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

__attribute__((alias("__imp__sub_827C136C"))) PPC_WEAK_FUNC(sub_827C136C);
PPC_FUNC_IMPL(__imp__sub_827C136C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C1370"))) PPC_WEAK_FUNC(sub_827C1370);
PPC_FUNC_IMPL(__imp__sub_827C1370) {
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
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827c13cc
	if (cr6.eq) goto loc_827C13CC;
	// li r4,1
	ctx.r4.s64 = 1;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x823ea420
	ctx.lr = 0x827C139C;
	sub_823EA420(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x823ea140
	ctx.lr = 0x827C13AC;
	sub_823EA140(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// bl 0x82469780
	ctx.lr = 0x827C13BC;
	sub_82469780(ctx, base);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r10,-6480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -6480);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,-6480(r11)
	PPC_STORE_U32(r11.u32 + -6480, ctx.r10.u32);
loc_827C13CC:
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

__attribute__((alias("__imp__sub_827C13E0"))) PPC_WEAK_FUNC(sub_827C13E0);
PPC_FUNC_IMPL(__imp__sub_827C13E0) {
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
	ctx.lr = 0x827C13E8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// li r5,388
	ctx.r5.s64 = 388;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// bl 0x823d9890
	ctx.lr = 0x827C140C;
	sub_823D9890(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// li r5,88
	ctx.r5.s64 = 88;
	// stw r26,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r26.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r29.u32);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// stw r27,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r27.u32);
	// bl 0x823d9890
	ctx.lr = 0x827C1430;
	sub_823D9890(ctx, base);
	// addi r11,r26,-16
	r11.s64 = r26.s64 + -16;
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r29.u8);
	// li r24,1
	r24.s64 = 1;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r25,r31,92
	r25.s64 = r31.s64 + 92;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stb r24,139(r1)
	PPC_STORE_U8(ctx.r1.u32 + 139, r24.u8);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// li r11,12
	r11.s64 = 12;
	// stb r11,138(r1)
	PPC_STORE_U8(ctx.r1.u32 + 138, r11.u8);
	// bl 0x823eaa90
	ctx.lr = 0x827C1470;
	sub_823EAA90(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x827c1484
	if (!cr6.lt) goto loc_827C1484;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9238
	return;
loc_827C1484:
	// lis r11,4194
	r11.s64 = 274857984;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r8,44(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lis r6,20971
	ctx.r6.s64 = 1374355456;
	// ori r11,r11,19923
	r11.u64 = r11.u64 | 19923;
	// stw r30,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r30.u32);
	// ori r6,r6,34079
	ctx.r6.u64 = ctx.r6.u64 | 34079;
	// stw r27,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r27.u32);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// srawi r11,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	r11.s64 = ctx.r10.s32 >> 3;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// li r10,540
	ctx.r10.s64 = 540;
	// stw r10,240(r31)
	PPC_STORE_U32(r31.u32 + 240, ctx.r10.u32);
	// mulli r10,r11,600
	ctx.r10.s64 = r11.s64 * 600;
	// mulhwu r10,r10,r9
	ctx.r10.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r9.u32)) >> 32;
	// rlwinm r10,r10,26,6,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x3FFFFFF;
	// mulli r9,r11,50
	ctx.r9.s64 = r11.s64 * 50;
	// addi r10,r10,1023
	ctx.r10.s64 = ctx.r10.s64 + 1023;
	// mulhwu r9,r9,r7
	ctx.r9.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r3,r10,0,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFC00;
	// rlwinm r10,r9,26,6,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3FFFFFF;
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// rlwinm r10,r10,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// stw r10,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r10.u32);
	// mulli r10,r3,90
	ctx.r10.s64 = ctx.r3.s64 * 90;
	// mulhwu r10,r10,r6
	ctx.r10.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r10,r10,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// stw r10,232(r31)
	PPC_STORE_U32(r31.u32 + 232, ctx.r10.u32);
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827c1540
	if (cr6.eq) goto loc_827C1540;
	// lwz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827c1540
	if (cr6.eq) goto loc_827C1540;
	// lwz r8,8(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// mulld r9,r8,r9
	ctx.r9.s64 = ctx.r8.s64 * ctx.r9.s64;
	// mulld r11,r9,r11
	r11.s64 = ctx.r9.s64 * r11.s64;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// divdu r11,r11,r10
	r11.u64 = r11.u64 / ctx.r10.u64;
	// rotlwi r28,r11,0
	r28.u64 = __builtin_rotateleft32(r11.u32, 0);
	// b 0x827c1544
	goto loc_827C1544;
loc_827C1540:
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_827C1544:
	// bl 0x824696b8
	ctx.lr = 0x827C1548;
	sub_824696B8(ctx, base);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bne cr6,0x827c1568
	if (!cr6.eq) goto loc_827C1568;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
loc_827C1568:
	// li r11,32767
	r11.s64 = 32767;
	// stw r27,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r27.u32);
	// cmpwi cr6,r26,16
	cr6.compare<int32_t>(r26.s32, 16, xer);
	// stw r27,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r27.u32);
	// stw r11,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r11.u32);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// bne cr6,0x827c158c
	if (!cr6.eq) goto loc_827C158C;
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x827c1594
	goto loc_827C1594;
loc_827C158C:
	// lis r11,-32640
	r11.s64 = -2139095040;
	// ori r11,r11,32896
	r11.u64 = r11.u64 | 32896;
loc_827C1594:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,244(r31)
	PPC_STORE_U32(r31.u32 + 244, r11.u32);
	// bl 0x827c0910
	ctx.lr = 0x827C15A0;
	sub_827C0910(ctx, base);
	// lwz r30,188(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r11,96(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 96);
	// mr r29,r30
	r29.u64 = r30.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x827c15b8
	if (!cr6.gt) goto loc_827C15B8;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_827C15B8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,152(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 152);
	// lwz r3,92(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 92);
	// bl 0x823d9890
	ctx.lr = 0x827C15C8;
	sub_823D9890(ctx, base);
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// bge cr6,0x827c15e0
	if (!cr6.lt) goto loc_827C15E0;
	// subf r5,r29,r30
	ctx.r5.s64 = r30.s64 - r29.s64;
	// lwz r4,152(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 152);
	// lwz r3,92(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 92);
	// bl 0x823d9890
	ctx.lr = 0x827C15E0;
	sub_823D9890(ctx, base);
loc_827C15E0:
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// stw r27,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r27.u32);
	// stw r27,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r27.u32);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bge cr6,0x827c15f8
	if (!cr6.lt) goto loc_827C15F8;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_827C15F8:
	// lis r4,-32132
	ctx.r4.s64 = -2105802752;
	// stw r11,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r11.u32);
	// stw r11,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r11.u32);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r11,r4,4072
	r11.s64 = ctx.r4.s64 + 4072;
	// stw r27,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r27.u32);
	// addi r4,r10,4208
	ctx.r4.s64 = ctx.r10.s64 + 4208;
	// stw r24,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r24.u32);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// lis r29,-32132
	r29.s64 = -2105802752;
	// lis r30,-32132
	r30.s64 = -2105802752;
	// stw r11,360(r31)
	PPC_STORE_U32(r31.u32 + 360, r11.u32);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lis r5,-32132
	ctx.r5.s64 = -2105802752;
	// stw r4,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r4.u32);
	// lis r6,-32132
	ctx.r6.s64 = -2105802752;
	// lis r7,-32132
	ctx.r7.s64 = -2105802752;
	// lis r8,-32132
	ctx.r8.s64 = -2105802752;
	// lwz r10,-6480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -6480);
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r3,r3,3952
	ctx.r3.s64 = ctx.r3.s64 + 3952;
	// addi r29,r29,3128
	r29.s64 = r29.s64 + 3128;
	// addi r30,r30,3592
	r30.s64 = r30.s64 + 3592;
	// addi r5,r5,4096
	ctx.r5.s64 = ctx.r5.s64 + 4096;
	// addi r6,r6,4816
	ctx.r6.s64 = ctx.r6.s64 + 4816;
	// addi r7,r7,4624
	ctx.r7.s64 = ctx.r7.s64 + 4624;
	// stw r3,356(r31)
	PPC_STORE_U32(r31.u32 + 356, ctx.r3.u32);
	// addi r8,r8,4976
	ctx.r8.s64 = ctx.r8.s64 + 4976;
	// stw r29,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r29.u32);
	// addi r9,r9,4120
	ctx.r9.s64 = ctx.r9.s64 + 4120;
	// stw r30,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r30.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r5,364(r31)
	PPC_STORE_U32(r31.u32 + 364, ctx.r5.u32);
	// stw r6,368(r31)
	PPC_STORE_U32(r31.u32 + 368, ctx.r6.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,372(r31)
	PPC_STORE_U32(r31.u32 + 372, ctx.r7.u32);
	// stw r8,376(r31)
	PPC_STORE_U32(r31.u32 + 376, ctx.r8.u32);
	// stw r9,380(r31)
	PPC_STORE_U32(r31.u32 + 380, ctx.r9.u32);
	// stw r10,-6480(r11)
	PPC_STORE_U32(r11.u32 + -6480, ctx.r10.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_827C169C"))) PPC_WEAK_FUNC(sub_827C169C);
PPC_FUNC_IMPL(__imp__sub_827C169C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827C16A0"))) PPC_WEAK_FUNC(sub_827C16A0);
PPC_FUNC_IMPL(__imp__sub_827C16A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,5088
	ctx.r3.s64 = r11.s64 + 5088;
	// blr 
	return;
}

