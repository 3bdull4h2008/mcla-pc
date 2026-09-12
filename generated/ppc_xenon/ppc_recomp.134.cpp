#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8267E0D0"))) PPC_WEAK_FUNC(sub_8267E0D0);
PPC_FUNC_IMPL(__imp__sub_8267E0D0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-13072
	ctx.r4.s64 = ctx.r9.s64 + -13072;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,-13100
	ctx.r5.s64 = ctx.r10.s64 + -13100;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E10C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-13900
	ctx.r7.s64 = ctx.r8.s64 + -13900;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E138;
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

__attribute__((alias("__imp__sub_8267E150"))) PPC_WEAK_FUNC(sub_8267E150);
PPC_FUNC_IMPL(__imp__sub_8267E150) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-12204
	ctx.r4.s64 = ctx.r9.s64 + -12204;
	// addi r8,r11,28436
	ctx.r8.s64 = r11.s64 + 28436;
	// addi r5,r10,-12236
	ctx.r5.s64 = ctx.r10.s64 + -12236;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E18C;
	sub_8228F920(ctx, base);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r7,r8,-13036
	ctx.r7.s64 = ctx.r8.s64 + -13036;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r6,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267E1C0;
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

__attribute__((alias("__imp__sub_8267E1D8"))) PPC_WEAK_FUNC(sub_8267E1D8);
PPC_FUNC_IMPL(__imp__sub_8267E1D8) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-11340
	ctx.r4.s64 = ctx.r9.s64 + -11340;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-11364
	ctx.r5.s64 = ctx.r10.s64 + -11364;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E214;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-12164
	ctx.r7.s64 = ctx.r8.s64 + -12164;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E240;
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

__attribute__((alias("__imp__sub_8267E258"))) PPC_WEAK_FUNC(sub_8267E258);
PPC_FUNC_IMPL(__imp__sub_8267E258) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-10476
	ctx.r4.s64 = ctx.r9.s64 + -10476;
	// addi r8,r11,29468
	ctx.r8.s64 = r11.s64 + 29468;
	// addi r5,r10,-10508
	ctx.r5.s64 = ctx.r10.s64 + -10508;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E294;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-11308
	ctx.r7.s64 = ctx.r8.s64 + -11308;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E2C0;
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

__attribute__((alias("__imp__sub_8267E2D8"))) PPC_WEAK_FUNC(sub_8267E2D8);
PPC_FUNC_IMPL(__imp__sub_8267E2D8) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r30,r11,29356
	r30.s64 = r11.s64 + 29356;
	// addi r4,r9,-9612
	ctx.r4.s64 = ctx.r9.s64 + -9612;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r5,r10,-9636
	ctx.r5.s64 = ctx.r10.s64 + -9636;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E31C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-10436
	ctx.r7.s64 = ctx.r8.s64 + -10436;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
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

__attribute__((alias("__imp__sub_8267E368"))) PPC_WEAK_FUNC(sub_8267E368);
PPC_FUNC_IMPL(__imp__sub_8267E368) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r30,r11,29356
	r30.s64 = r11.s64 + 29356;
	// addi r4,r9,-8760
	ctx.r4.s64 = ctx.r9.s64 + -8760;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r5,r10,-8780
	ctx.r5.s64 = ctx.r10.s64 + -8780;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E3AC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-9580
	ctx.r7.s64 = ctx.r8.s64 + -9580;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E3D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
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

__attribute__((alias("__imp__sub_8267E3F8"))) PPC_WEAK_FUNC(sub_8267E3F8);
PPC_FUNC_IMPL(__imp__sub_8267E3F8) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r30,r11,28724
	r30.s64 = r11.s64 + 28724;
	// addi r4,r9,-7908
	ctx.r4.s64 = ctx.r9.s64 + -7908;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r5,r10,-7932
	ctx.r5.s64 = ctx.r10.s64 + -7932;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E43C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-8732
	ctx.r7.s64 = ctx.r8.s64 + -8732;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
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

__attribute__((alias("__imp__sub_8267E488"))) PPC_WEAK_FUNC(sub_8267E488);
PPC_FUNC_IMPL(__imp__sub_8267E488) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,-7048
	ctx.r5.s64 = r11.s64 + -7048;
	// addi r4,r10,-7076
	ctx.r4.s64 = ctx.r10.s64 + -7076;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E4C0;
	sub_8228F920(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-7876
	ctx.r7.s64 = ctx.r8.s64 + -7876;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E4F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,29108
	ctx.r9.s64 = ctx.r10.s64 + 29108;
	// stw r9,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8267E51C"))) PPC_WEAK_FUNC(sub_8267E51C);
PPC_FUNC_IMPL(__imp__sub_8267E51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267E520"))) PPC_WEAK_FUNC(sub_8267E520);
PPC_FUNC_IMPL(__imp__sub_8267E520) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-6180
	ctx.r4.s64 = ctx.r9.s64 + -6180;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-6212
	ctx.r5.s64 = ctx.r10.s64 + -6212;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E55C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-7012
	ctx.r7.s64 = ctx.r8.s64 + -7012;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E588;
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

__attribute__((alias("__imp__sub_8267E5A0"))) PPC_WEAK_FUNC(sub_8267E5A0);
PPC_FUNC_IMPL(__imp__sub_8267E5A0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-5312
	ctx.r4.s64 = ctx.r9.s64 + -5312;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-5340
	ctx.r5.s64 = ctx.r10.s64 + -5340;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E5DC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-6140
	ctx.r7.s64 = ctx.r8.s64 + -6140;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E608;
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

__attribute__((alias("__imp__sub_8267E620"))) PPC_WEAK_FUNC(sub_8267E620);
PPC_FUNC_IMPL(__imp__sub_8267E620) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-4448
	ctx.r4.s64 = ctx.r9.s64 + -4448;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-4476
	ctx.r5.s64 = ctx.r10.s64 + -4476;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E65C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-5276
	ctx.r7.s64 = ctx.r8.s64 + -5276;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E688;
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

__attribute__((alias("__imp__sub_8267E6A0"))) PPC_WEAK_FUNC(sub_8267E6A0);
PPC_FUNC_IMPL(__imp__sub_8267E6A0) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,-3576
	ctx.r5.s64 = r11.s64 + -3576;
	// addi r4,r10,-3612
	ctx.r4.s64 = ctx.r10.s64 + -3612;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E6D8;
	sub_8228F920(ctx, base);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r8,r9,-4412
	ctx.r8.s64 = ctx.r9.s64 + -4412;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r7,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r7.u8);
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267E704;
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

__attribute__((alias("__imp__sub_8267E71C"))) PPC_WEAK_FUNC(sub_8267E71C);
PPC_FUNC_IMPL(__imp__sub_8267E71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267E720"))) PPC_WEAK_FUNC(sub_8267E720);
PPC_FUNC_IMPL(__imp__sub_8267E720) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-2712
	ctx.r4.s64 = ctx.r9.s64 + -2712;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-2732
	ctx.r5.s64 = ctx.r10.s64 + -2732;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E75C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-3532
	ctx.r7.s64 = ctx.r8.s64 + -3532;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E788;
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

__attribute__((alias("__imp__sub_8267E7A0"))) PPC_WEAK_FUNC(sub_8267E7A0);
PPC_FUNC_IMPL(__imp__sub_8267E7A0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-1864
	ctx.r4.s64 = ctx.r9.s64 + -1864;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-1884
	ctx.r5.s64 = ctx.r10.s64 + -1884;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E7DC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-2684
	ctx.r7.s64 = ctx.r8.s64 + -2684;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E808;
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

__attribute__((alias("__imp__sub_8267E820"))) PPC_WEAK_FUNC(sub_8267E820);
PPC_FUNC_IMPL(__imp__sub_8267E820) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-1016
	ctx.r4.s64 = ctx.r9.s64 + -1016;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-1036
	ctx.r5.s64 = ctx.r10.s64 + -1036;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E85C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-1836
	ctx.r7.s64 = ctx.r8.s64 + -1836;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E888;
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

__attribute__((alias("__imp__sub_8267E8A0"))) PPC_WEAK_FUNC(sub_8267E8A0);
PPC_FUNC_IMPL(__imp__sub_8267E8A0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-168
	ctx.r4.s64 = ctx.r9.s64 + -168;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-188
	ctx.r5.s64 = ctx.r10.s64 + -188;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E8DC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-988
	ctx.r7.s64 = ctx.r8.s64 + -988;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E908;
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

__attribute__((alias("__imp__sub_8267E920"))) PPC_WEAK_FUNC(sub_8267E920);
PPC_FUNC_IMPL(__imp__sub_8267E920) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,688
	ctx.r4.s64 = ctx.r9.s64 + 688;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,660
	ctx.r5.s64 = ctx.r10.s64 + 660;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E95C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-140
	ctx.r7.s64 = ctx.r8.s64 + -140;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E988;
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

__attribute__((alias("__imp__sub_8267E9A0"))) PPC_WEAK_FUNC(sub_8267E9A0);
PPC_FUNC_IMPL(__imp__sub_8267E9A0) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,1552
	ctx.r4.s64 = ctx.r9.s64 + 1552;
	// addi r8,r11,28532
	ctx.r8.s64 = r11.s64 + 28532;
	// addi r5,r10,1524
	ctx.r5.s64 = ctx.r10.s64 + 1524;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E9DC;
	sub_8228F920(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,724
	ctx.r6.s64 = ctx.r7.s64 + 724;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267EA14;
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

__attribute__((alias("__imp__sub_8267EA2C"))) PPC_WEAK_FUNC(sub_8267EA2C);
PPC_FUNC_IMPL(__imp__sub_8267EA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EA30"))) PPC_WEAK_FUNC(sub_8267EA30);
PPC_FUNC_IMPL(__imp__sub_8267EA30) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,2416
	ctx.r4.s64 = ctx.r9.s64 + 2416;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,2388
	ctx.r5.s64 = ctx.r10.s64 + 2388;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EA6C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,1588
	ctx.r7.s64 = ctx.r8.s64 + 1588;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EA98;
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

__attribute__((alias("__imp__sub_8267EAB0"))) PPC_WEAK_FUNC(sub_8267EAB0);
PPC_FUNC_IMPL(__imp__sub_8267EAB0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,3280
	ctx.r4.s64 = ctx.r9.s64 + 3280;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,3252
	ctx.r5.s64 = ctx.r10.s64 + 3252;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EAEC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,2452
	ctx.r7.s64 = ctx.r8.s64 + 2452;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EB18;
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

__attribute__((alias("__imp__sub_8267EB30"))) PPC_WEAK_FUNC(sub_8267EB30);
PPC_FUNC_IMPL(__imp__sub_8267EB30) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,4140
	ctx.r4.s64 = ctx.r9.s64 + 4140;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,4116
	ctx.r5.s64 = ctx.r10.s64 + 4116;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EB6C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,3316
	ctx.r7.s64 = ctx.r8.s64 + 3316;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EB98;
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

__attribute__((alias("__imp__sub_8267EBB0"))) PPC_WEAK_FUNC(sub_8267EBB0);
PPC_FUNC_IMPL(__imp__sub_8267EBB0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,4992
	ctx.r4.s64 = ctx.r9.s64 + 4992;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,4972
	ctx.r5.s64 = ctx.r10.s64 + 4972;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EBEC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,4172
	ctx.r7.s64 = ctx.r8.s64 + 4172;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EC18;
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

__attribute__((alias("__imp__sub_8267EC30"))) PPC_WEAK_FUNC(sub_8267EC30);
PPC_FUNC_IMPL(__imp__sub_8267EC30) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,5844
	ctx.r4.s64 = ctx.r9.s64 + 5844;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,5820
	ctx.r5.s64 = ctx.r10.s64 + 5820;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EC6C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,5020
	ctx.r7.s64 = ctx.r8.s64 + 5020;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EC98;
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

__attribute__((alias("__imp__sub_8267ECB0"))) PPC_WEAK_FUNC(sub_8267ECB0);
PPC_FUNC_IMPL(__imp__sub_8267ECB0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,6700
	ctx.r4.s64 = ctx.r9.s64 + 6700;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,6676
	ctx.r5.s64 = ctx.r10.s64 + 6676;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267ECEC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,5876
	ctx.r7.s64 = ctx.r8.s64 + 5876;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267ED18;
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

__attribute__((alias("__imp__sub_8267ED30"))) PPC_WEAK_FUNC(sub_8267ED30);
PPC_FUNC_IMPL(__imp__sub_8267ED30) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,7556
	ctx.r4.s64 = ctx.r9.s64 + 7556;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,7532
	ctx.r5.s64 = ctx.r10.s64 + 7532;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267ED6C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,6732
	ctx.r7.s64 = ctx.r8.s64 + 6732;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267ED98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,29356
	ctx.r9.s64 = ctx.r10.s64 + 29356;
	// stw r9,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8267EDBC"))) PPC_WEAK_FUNC(sub_8267EDBC);
PPC_FUNC_IMPL(__imp__sub_8267EDBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EDC0"))) PPC_WEAK_FUNC(sub_8267EDC0);
PPC_FUNC_IMPL(__imp__sub_8267EDC0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,8416
	ctx.r4.s64 = ctx.r9.s64 + 8416;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,8388
	ctx.r5.s64 = ctx.r10.s64 + 8388;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EDFC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,7588
	ctx.r7.s64 = ctx.r8.s64 + 7588;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EE28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,29356
	ctx.r9.s64 = ctx.r10.s64 + 29356;
	// stw r9,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8267EE4C"))) PPC_WEAK_FUNC(sub_8267EE4C);
PPC_FUNC_IMPL(__imp__sub_8267EE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EE50"))) PPC_WEAK_FUNC(sub_8267EE50);
PPC_FUNC_IMPL(__imp__sub_8267EE50) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,9284
	ctx.r4.s64 = ctx.r9.s64 + 9284;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,9252
	ctx.r5.s64 = ctx.r10.s64 + 9252;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EE8C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,8452
	ctx.r7.s64 = ctx.r8.s64 + 8452;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,29356
	ctx.r9.s64 = ctx.r10.s64 + 29356;
	// stw r9,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8267EEDC"))) PPC_WEAK_FUNC(sub_8267EEDC);
PPC_FUNC_IMPL(__imp__sub_8267EEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EEE0"))) PPC_WEAK_FUNC(sub_8267EEE0);
PPC_FUNC_IMPL(__imp__sub_8267EEE0) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,10160
	ctx.r4.s64 = ctx.r9.s64 + 10160;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,10124
	ctx.r5.s64 = ctx.r10.s64 + 10124;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EF1C;
	sub_8228F920(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,9324
	ctx.r6.s64 = ctx.r7.s64 + 9324;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267EF54;
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

__attribute__((alias("__imp__sub_8267EF6C"))) PPC_WEAK_FUNC(sub_8267EF6C);
PPC_FUNC_IMPL(__imp__sub_8267EF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EF70"))) PPC_WEAK_FUNC(sub_8267EF70);
PPC_FUNC_IMPL(__imp__sub_8267EF70) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,11028
	ctx.r5.s64 = r11.s64 + 11028;
	// addi r4,r10,11004
	ctx.r4.s64 = ctx.r10.s64 + 11004;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EFA8;
	sub_8228F920(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,10204
	ctx.r7.s64 = ctx.r8.s64 + 10204;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EFE0;
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

__attribute__((alias("__imp__sub_8267EFF8"))) PPC_WEAK_FUNC(sub_8267EFF8);
PPC_FUNC_IMPL(__imp__sub_8267EFF8) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,11888
	ctx.r4.s64 = ctx.r9.s64 + 11888;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,11860
	ctx.r5.s64 = ctx.r10.s64 + 11860;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267F034;
	sub_8228F920(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,11060
	ctx.r6.s64 = ctx.r7.s64 + 11060;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F06C;
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

__attribute__((alias("__imp__sub_8267F084"))) PPC_WEAK_FUNC(sub_8267F084);
PPC_FUNC_IMPL(__imp__sub_8267F084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F088"))) PPC_WEAK_FUNC(sub_8267F088);
PPC_FUNC_IMPL(__imp__sub_8267F088) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-15664
	ctx.r4.s64 = ctx.r9.s64 + -15664;
	// addi r8,r11,28428
	ctx.r8.s64 = r11.s64 + 28428;
	// addi r5,r10,-15700
	ctx.r5.s64 = ctx.r10.s64 + -15700;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267F0C4;
	sub_8228F920(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,11924
	ctx.r6.s64 = ctx.r7.s64 + 11924;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F0FC;
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

__attribute__((alias("__imp__sub_8267F114"))) PPC_WEAK_FUNC(sub_8267F114);
PPC_FUNC_IMPL(__imp__sub_8267F114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F118"))) PPC_WEAK_FUNC(sub_8267F118);
PPC_FUNC_IMPL(__imp__sub_8267F118) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267f148
	if (cr6.eq) goto loc_8267F148;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8267f170
	if (cr6.eq) goto loc_8267F170;
	// bl 0x826537d0
	ctx.lr = 0x8267F144;
	sub_826537D0(ctx, base);
	// b 0x8267f2c4
	goto loc_8267F2C4;
loc_8267F148:
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8267F154;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8267f164
	if (cr6.lt) goto loc_8267F164;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8267F164:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8267f254
	if (cr6.lt) goto loc_8267F254;
	// beq cr6,0x8267f1a0
	if (cr6.eq) goto loc_8267F1A0;
loc_8267F170:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267F17C;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267F188;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267F19C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267f2c0
	goto loc_8267F2C0;
loc_8267F1A0:
	// lwz r11,1200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// addi r3,r31,1200
	ctx.r3.s64 = r31.s64 + 1200;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F1B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267f2b4
	if (cr6.eq) goto loc_8267F2B4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267F1CC;
	sub_821E6800(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8267F1D0;
	sub_82387B90(ctx, base);
	// lwz r10,1340(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x8267f200
	if (!cr6.gt) goto loc_8267F200;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267F1E8;
	sub_826304B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F1FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267f2c0
	goto loc_8267F2C0;
loc_8267F200:
	// lis r11,-32123
	r11.s64 = -2105212928;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r11,23088
	ctx.r4.s64 = r11.s64 + 23088;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r10,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r10.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x823da950
	ctx.lr = 0x8267F21C;
	sub_823DA950(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// addi r9,r9,3998
	ctx.r9.s64 = ctx.r9.s64 + 3998;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// addi r6,r7,13148
	ctx.r6.s64 = ctx.r7.s64 + 13148;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// addi r8,r8,5928
	ctx.r8.s64 = ctx.r8.s64 + 5928;
	// addi r5,r5,13116
	ctx.r5.s64 = ctx.r5.s64 + 13116;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// bl 0x82634db0
	ctx.lr = 0x8267F250;
	sub_82634DB0(ctx, base);
	// b 0x8267f2c0
	goto loc_8267F2C0;
loc_8267F254:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8267F25C;
	sub_82203240(ctx, base);
	// mulli r11,r3,208
	r11.s64 = ctx.r3.s64 * 208;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,992
	ctx.r3.s64 = r11.s64 + 992;
	// lwz r11,992(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 992);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267f2b4
	if (cr6.eq) goto loc_8267F2B4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267F290;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267F29C;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267F2B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267f2c0
	goto loc_8267F2C0;
loc_8267F2B4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8267F2C0;
	sub_821E6800(ctx, base);
loc_8267F2C0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8267F2C4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267F2DC"))) PPC_WEAK_FUNC(sub_8267F2DC);
PPC_FUNC_IMPL(__imp__sub_8267F2DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F2E0"))) PPC_WEAK_FUNC(sub_8267F2E0);
PPC_FUNC_IMPL(__imp__sub_8267F2E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267F2E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,1504
	ctx.r3.s64 = r31.s64 + 1504;
	// lwz r30,1216(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826b7ab0
	ctx.lr = 0x8267F308;
	sub_826B7AB0(ctx, base);
	// lwz r9,1564(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1564);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,-28964(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28964);
	f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// beq cr6,0x8267f35c
	if (cr6.eq) goto loc_8267F35C;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// beq cr6,0x8267f350
	if (cr6.eq) goto loc_8267F350;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// bne cr6,0x8267f368
	if (!cr6.eq) goto loc_8267F368;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,19404(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 19404);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8267f364
	goto loc_8267F364;
loc_8267F350:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,31932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31932);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8267f364
	goto loc_8267F364;
loc_8267F35C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,-26928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26928);
	ctx.f13.f64 = double(temp.f32);
loc_8267F364:
	// fmuls f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8267F368:
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// li r11,20
	r11.s64 = 20;
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// divw r11,r10,r11
	r11.s32 = ctx.r10.s32 / r11.s32;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// li r6,-20
	ctx.r6.s64 = -20;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,5
	ctx.r7.s64 = 5;
	// extsw r5,r11
	ctx.r5.s64 = r11.s32;
	// lfs f0,18892(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 18892);
	f0.f64 = double(temp.f32);
	// addi r10,r31,1248
	ctx.r10.s64 = r31.s64 + 1248;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// divw r9,r4,r6
	ctx.r9.s32 = ctx.r4.s32 / ctx.r6.s32;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r9,r11
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// divw r6,r8,r7
	ctx.r6.s32 = ctx.r8.s32 / ctx.r7.s32;
	// divw r9,r6,r7
	ctx.r9.s32 = ctx.r6.s32 / ctx.r7.s32;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r9,r8
	r30.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r30,r9
	ctx.r9.u64 = r30.u64 + ctx.r9.u64;
	// subf r5,r9,r11
	ctx.r5.s64 = r11.s64 - ctx.r9.s64;
	// add r29,r9,r11
	r29.u64 = ctx.r9.u64 + r11.u64;
	// stw r5,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, ctx.r5.u32);
	// lwz r4,1464(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1464);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// stw r11,1464(r31)
	PPC_STORE_U32(r31.u32 + 1464, r11.u32);
	// beq cr6,0x8267f414
	if (cr6.eq) goto loc_8267F414;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,228
	ctx.r3.s64 = ctx.r10.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8267F414;
	sub_821C3048(ctx, base);
loc_8267F414:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r29,1460(r31)
	PPC_STORE_U32(r31.u32 + 1460, r29.u32);
	// stw r30,1468(r31)
	PPC_STORE_U32(r31.u32 + 1468, r30.u32);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267F438"))) PPC_WEAK_FUNC(sub_8267F438);
PPC_FUNC_IMPL(__imp__sub_8267F438) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// bl 0x8262fff0
	ctx.lr = 0x8267F458;
	sub_8262FFF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267f2e0
	ctx.lr = 0x8267F460;
	sub_8267F2E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653b30
	ctx.lr = 0x8267F468;
	sub_82653B30(ctx, base);
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

__attribute__((alias("__imp__sub_8267F47C"))) PPC_WEAK_FUNC(sub_8267F47C);
PPC_FUNC_IMPL(__imp__sub_8267F47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F480"))) PPC_WEAK_FUNC(sub_8267F480);
PPC_FUNC_IMPL(__imp__sub_8267F480) {
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
	// beq cr6,0x8267f4d0
	if (cr6.eq) goto loc_8267F4D0;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8267f4bc
	if (cr6.eq) goto loc_8267F4BC;
	// bl 0x826537d0
	ctx.lr = 0x8267F4A8;
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
loc_8267F4BC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267F4C8;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8267f4e0
	goto loc_8267F4E0;
loc_8267F4D0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267F4DC;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
loc_8267F4E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267F4E8;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267F4FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267F514"))) PPC_WEAK_FUNC(sub_8267F514);
PPC_FUNC_IMPL(__imp__sub_8267F514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F518"))) PPC_WEAK_FUNC(sub_8267F518);
PPC_FUNC_IMPL(__imp__sub_8267F518) {
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
	// bl 0x826535f8
	ctx.lr = 0x8267F530;
	sub_826535F8(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267f590
	if (cr6.eq) goto loc_8267F590;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14556
	ctx.r4.s64 = ctx.r10.s64 + -14556;
	// lwz r11,18508(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r5,508(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// bl 0x825ee0e0
	ctx.lr = 0x8267F554;
	sub_825EE0E0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r4,r8,13184
	ctx.r4.s64 = ctx.r8.s64 + 13184;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8267F568;
	sub_82218310(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r7,13172
	ctx.r4.s64 = ctx.r7.s64 + 13172;
	// bl 0x825ee2d8
	ctx.lr = 0x8267F57C;
	sub_825EE2D8(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r6,-10268
	ctx.r4.s64 = ctx.r6.s64 + -10268;
	// bl 0x825ee0e0
	ctx.lr = 0x8267F590;
	sub_825EE0E0(ctx, base);
loc_8267F590:
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

__attribute__((alias("__imp__sub_8267F5A4"))) PPC_WEAK_FUNC(sub_8267F5A4);
PPC_FUNC_IMPL(__imp__sub_8267F5A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F5A8"))) PPC_WEAK_FUNC(sub_8267F5A8);
PPC_FUNC_IMPL(__imp__sub_8267F5A8) {
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
	ctx.lr = 0x8267F5B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267F5D4;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r30.u32);
	// li r11,1
	r11.s64 = 1;
	// stw r29,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r29.u32);
	// addi r9,r10,-29700
	ctx.r9.s64 = ctx.r10.s64 + -29700;
	// stw r28,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r28.u32);
	// stw r11,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r11.u32);
	// addi r3,r31,228
	ctx.r3.s64 = r31.s64 + 228;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,224(r31)
	PPC_STORE_U8(r31.u32 + 224, r11.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8267F600;
	sub_821C2F70(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,13196
	ctx.r4.s64 = ctx.r6.s64 + 13196;
	// lwz r11,24600(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24600);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r11.u32);
	// lwz r11,24596(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24596);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stb r5,224(r31)
	PPC_STORE_U8(r31.u32 + 224, ctx.r5.u8);
	// stw r11,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267F638"))) PPC_WEAK_FUNC(sub_8267F638);
PPC_FUNC_IMPL(__imp__sub_8267F638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8267F640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,14700
	ctx.r4.s64 = ctx.r9.s64 + 14700;
	// addi r8,r11,28484
	ctx.r8.s64 = r11.s64 + 28484;
	// addi r5,r10,14680
	ctx.r5.s64 = ctx.r10.s64 + 14680;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267F670;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
	// addi r7,r8,13876
	ctx.r7.s64 = ctx.r8.s64 + 13876;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r29
	r28.u64 = r29.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r30,1
	r30.s64 = 1;
	// addi r27,r11,3998
	r27.s64 = r11.s64 + 3998;
loc_8267F690:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267F6A0;
	sub_82633D40(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r28,r28,208
	r28.s64 = r28.s64 + 208;
	// bge 0x8267f690
	if (!cr0.lt) goto loc_8267F690;
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// bl 0x82634b60
	ctx.lr = 0x8267F6B4;
	sub_82634B60(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,13860
	ctx.r4.s64 = r11.s64 + 13860;
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267F6D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1200(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,13848
	ctx.r4.s64 = ctx.r8.s64 + 13848;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267F6F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,852(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8267F738"))) PPC_WEAK_FUNC(sub_8267F738);
PPC_FUNC_IMPL(__imp__sub_8267F738) {
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
	// bl 0x82646c40
	ctx.lr = 0x8267F758;
	sub_82646C40(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267f770
	if (cr6.eq) goto loc_8267F770;
	// bl 0x82130588
	ctx.lr = 0x8267F76C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267F770:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267F788"))) PPC_WEAK_FUNC(sub_8267F788);
PPC_FUNC_IMPL(__imp__sub_8267F788) {
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
	ctx.lr = 0x8267F790;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,15548
	ctx.r4.s64 = ctx.r9.s64 + 15548;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,15528
	ctx.r5.s64 = ctx.r10.s64 + 15528;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267F7C0;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,14724
	ctx.r5.s64 = ctx.r8.s64 + 14724;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// addi r30,r31,1008
	r30.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x826349f0
	ctx.lr = 0x8267F810;
	sub_826349F0(ctx, base);
	// addi r29,r31,1248
	r29.s64 = r31.s64 + 1248;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8267f5a8
	ctx.lr = 0x8267F828;
	sub_8267F5A8(ctx, base);
	// addi r3,r31,1504
	ctx.r3.s64 = r31.s64 + 1504;
	// bl 0x826b6ba0
	ctx.lr = 0x8267F830;
	sub_826B6BA0(ctx, base);
	// lwz r8,1008(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267F848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267F854;
	sub_8262FFF0(ctx, base);
	// lis r6,-32152
	ctx.r6.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r6,-3360
	ctx.r4.s64 = ctx.r6.s64 + -3360;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267F868;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267F878:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267f878
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267F878;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267F89C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267f89c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267F89C;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
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
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267F8EC"))) PPC_WEAK_FUNC(sub_8267F8EC);
PPC_FUNC_IMPL(__imp__sub_8267F8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F8F0"))) PPC_WEAK_FUNC(sub_8267F8F0);
PPC_FUNC_IMPL(__imp__sub_8267F8F0) {
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
	// bl 0x82646c98
	ctx.lr = 0x8267F910;
	sub_82646C98(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267f928
	if (cr6.eq) goto loc_8267F928;
	// bl 0x82130588
	ctx.lr = 0x8267F924;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267F928:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267F940"))) PPC_WEAK_FUNC(sub_8267F940);
PPC_FUNC_IMPL(__imp__sub_8267F940) {
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
	ctx.lr = 0x8267F948;
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,15568
	ctx.r4.s64 = ctx.r9.s64 + 15568;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x8267F974;
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
	ctx.lr = 0x8267F988;
	sub_821FD7C0(ctx, base);
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r31,0
	r31.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r31.u8);
	// stw r31,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r31.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// beq cr6,0x8267f9d0
	if (cr6.eq) goto loc_8267F9D0;
	// bl 0x822031a8
	ctx.lr = 0x8267F9B4;
	sub_822031A8(ctx, base);
	// bl 0x826be6d0
	ctx.lr = 0x8267F9B8;
	sub_826BE6D0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8267f9c4
	if (!cr6.gt) goto loc_8267F9C4;
	// li r31,1
	r31.s64 = 1;
loc_8267F9C4:
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_8267F9D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267F9DC"))) PPC_WEAK_FUNC(sub_8267F9DC);
PPC_FUNC_IMPL(__imp__sub_8267F9DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F9E0"))) PPC_WEAK_FUNC(sub_8267F9E0);
PPC_FUNC_IMPL(__imp__sub_8267F9E0) {
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
	ctx.lr = 0x8267F9E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x8267F9F4;
	sub_82653B30(ctx, base);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267FA0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// lwz r29,1200(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// bl 0x8267f940
	ctx.lr = 0x8267FA1C;
	sub_8267F940(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,76(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267FA30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267FA38"))) PPC_WEAK_FUNC(sub_8267FA38);
PPC_FUNC_IMPL(__imp__sub_8267FA38) {
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
	ctx.lr = 0x8267FA40;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r5,31
	ctx.r5.s64 = 31;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x823d9890
	ctx.lr = 0x8267FA60;
	sub_823D9890(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x8267FA88;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r4,10248(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821fd7c0
	ctx.lr = 0x8267FA9C;
	sub_821FD7C0(ctx, base);
	// lwz r11,340(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r30,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, r30.u8);
	// stw r30,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, r30.u32);
	// stw r29,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r29.u32);
	// stw r8,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r8.u32);
	// beq cr6,0x8267fb2c
	if (cr6.eq) goto loc_8267FB2C;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267FAD0;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267fb2c
	if (cr6.eq) goto loc_8267FB2C;
	// lwz r29,1216(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826cd180
	ctx.lr = 0x8267FAE4;
	sub_826CD180(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// beq cr6,0x8267fb10
	if (cr6.eq) goto loc_8267FB10;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bne cr6,0x8267fb1c
	if (!cr6.eq) goto loc_8267FB1C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f1,-31384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826b7ab0
	ctx.lr = 0x8267FB0C;
	sub_826B7AB0(ctx, base);
	// b 0x8267fb1c
	goto loc_8267FB1C;
loc_8267FB10:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b7940
	ctx.lr = 0x8267FB1C;
	sub_826B7940(ctx, base);
loc_8267FB1C:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,10
	ctx.r4.s64 = r30.s64 + 10;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db670
	ctx.lr = 0x8267FB2C;
	sub_823DB670(ctx, base);
loc_8267FB2C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-21312
	ctx.r4.s64 = ctx.r10.s64 + -21312;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8267FB44;
	sub_822183B0(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lwz r8,1456(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1456);
	// addi r3,r31,1456
	ctx.r3.s64 = r31.s64 + 1456;
	// addi r30,r9,-32520
	r30.s64 = ctx.r9.s64 + -32520;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267FB64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1680(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1680);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r3,r31,1680
	ctx.r3.s64 = r31.s64 + 1680;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267FB7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r11,184(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267FB90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267FB98"))) PPC_WEAK_FUNC(sub_8267FB98);
PPC_FUNC_IMPL(__imp__sub_8267FB98) {
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
	ctx.lr = 0x8267FBA0;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r31,r11,-21500
	r31.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// lwz r30,-24180(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x8267FBD0;
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
	ctx.lr = 0x8267FBE4;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267fc98
	if (cr6.eq) goto loc_8267FC98;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,92
	r31.s64 = r11.s64 + 92;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267FC20;
	sub_826BE498(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8267fc7c
	if (cr6.eq) goto loc_8267FC7C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8267fc7c
	if (cr6.eq) goto loc_8267FC7C;
	// addi r31,r29,1008
	r31.s64 = r29.s64 + 1008;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267FC44;
	sub_8262FFF0(ctx, base);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// ble cr6,0x8267fc6c
	if (!cr6.gt) goto loc_8267FC6C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267FC68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267fca4
	goto loc_8267FCA4;
loc_8267FC6C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267FC78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267fca4
	goto loc_8267FCA4;
loc_8267FC7C:
	// lwz r11,1008(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1008);
	// addi r3,r29,1008
	ctx.r3.s64 = r29.s64 + 1008;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267FC94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267fca4
	goto loc_8267FCA4;
loc_8267FC98:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r29,1008
	ctx.r3.s64 = r29.s64 + 1008;
	// bl 0x8262fff0
	ctx.lr = 0x8267FCA4;
	sub_8262FFF0(ctx, base);
loc_8267FCA4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8267fa38
	ctx.lr = 0x8267FCAC;
	sub_8267FA38(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82653b30
	ctx.lr = 0x8267FCB4;
	sub_82653B30(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267FCBC"))) PPC_WEAK_FUNC(sub_8267FCBC);
PPC_FUNC_IMPL(__imp__sub_8267FCBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267FCC0"))) PPC_WEAK_FUNC(sub_8267FCC0);
PPC_FUNC_IMPL(__imp__sub_8267FCC0) {
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
	// bl 0x82653670
	ctx.lr = 0x8267FCDC;
	sub_82653670(ctx, base);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8267FCE4;
	sub_82631F88(ctx, base);
	// lwz r31,856(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x8267fcf4
	if (cr6.lt) goto loc_8267FCF4;
	// addi r31,r3,-1
	r31.s64 = ctx.r3.s64 + -1;
loc_8267FCF4:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,2476
	ctx.r4.s64 = ctx.r10.s64 + 2476;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x8267FD0C;
	sub_821FD980(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,32684
	ctx.r4.s64 = ctx.r9.s64 + 32684;
	// addi r3,r30,92
	ctx.r3.s64 = r30.s64 + 92;
	// stw r31,88(r30)
	PPC_STORE_U32(r30.u32 + 88, r31.u32);
	// bl 0x823dc018
	ctx.lr = 0x8267FD28;
	sub_823DC018(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r8,156(r30)
	PPC_STORE_U32(r30.u32 + 156, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267FD48"))) PPC_WEAK_FUNC(sub_8267FD48);
PPC_FUNC_IMPL(__imp__sub_8267FD48) {
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
	// bl 0x82653670
	ctx.lr = 0x8267FD64;
	sub_82653670(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267fd98
	if (cr6.eq) goto loc_8267FD98;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-10268
	ctx.r4.s64 = r11.s64 + -10268;
	// bl 0x825ee0e0
	ctx.lr = 0x8267FD80;
	sub_825EE0E0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// addi r4,r9,13172
	ctx.r4.s64 = ctx.r9.s64 + 13172;
	// bl 0x825ee2d8
	ctx.lr = 0x8267FD98;
	sub_825EE2D8(ctx, base);
loc_8267FD98:
	// lwz r11,1248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1248);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r3,r31,1248
	ctx.r3.s64 = r31.s64 + 1248;
	// lwz r31,-24180(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// lwz r9,336(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267FDB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r8,9720
	ctx.r4.s64 = ctx.r8.s64 + 9720;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fd980
	ctx.lr = 0x8267FDCC;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r7,32684
	ctx.r4.s64 = ctx.r7.s64 + 32684;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// bl 0x823dc018
	ctx.lr = 0x8267FDE8;
	sub_823DC018(ctx, base);
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r6,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267FE08"))) PPC_WEAK_FUNC(sub_8267FE08);
PPC_FUNC_IMPL(__imp__sub_8267FE08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267FE10;
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
	// addi r4,r9,16412
	ctx.r4.s64 = ctx.r9.s64 + 16412;
	// addi r8,r11,28484
	ctx.r8.s64 = r11.s64 + 28484;
	// addi r5,r10,16392
	ctx.r5.s64 = ctx.r10.s64 + 16392;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267FE40;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,15588
	ctx.r5.s64 = ctx.r8.s64 + 15588;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// addi r29,r31,1008
	r29.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// bl 0x826349f0
	ctx.lr = 0x8267FE90;
	sub_826349F0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r28,r31,1248
	r28.s64 = r31.s64 + 1248;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r30,r8,-32520
	r30.s64 = ctx.r8.s64 + -32520;
	// lwz r4,-32520(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32520);
	// bl 0x82633d40
	ctx.lr = 0x8267FEAC;
	sub_82633D40(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r25,r7,-20868
	r25.s64 = ctx.r7.s64 + -20868;
	// addi r24,r6,5568
	r24.s64 = ctx.r6.s64 + 5568;
	// stw r25,1248(r31)
	PPC_STORE_U32(r31.u32 + 1248, r25.u32);
	// addi r27,r31,1456
	r27.s64 = r31.s64 + 1456;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r24,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, r24.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267FED4;
	sub_826311F8(ctx, base);
	// addi r26,r31,1472
	r26.s64 = r31.s64 + 1472;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267FEE8;
	sub_82633D40(ctx, base);
	// stw r25,1472(r31)
	PPC_STORE_U32(r31.u32 + 1472, r25.u32);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r25,r31,1680
	r25.s64 = r31.s64 + 1680;
	// stw r24,1680(r31)
	PPC_STORE_U32(r31.u32 + 1680, r24.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267FF00;
	sub_826311F8(ctx, base);
	// addi r24,r31,672
	r24.s64 = r31.s64 + 672;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r4,-32536
	ctx.r4.s64 = ctx.r4.s64 + -32536;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826347f0
	ctx.lr = 0x8267FF18;
	sub_826347F0(ctx, base);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r11,852(r31)
	PPC_STORE_U16(r31.u32 + 852, r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r7,1008(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267FF4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267FF58;
	sub_8262FFF0(ctx, base);
	// lis r4,-32152
	ctx.r4.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-1480
	ctx.r4.s64 = ctx.r4.s64 + -1480;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267FF6C;
	sub_821C2F90(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,5
	r11.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_8267FF78:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267ff78
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267FF78;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267FF9C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267ff9c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267FF9C;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r10,r31,1436
	ctx.r10.s64 = r31.s64 + 1436;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r31,1660
	ctx.r9.s64 = r31.s64 + 1660;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// sth r9,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r9.u16);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stwx r28,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r28.u32);
	// lwz r10,1436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1436);
	// lhz r11,1440(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1440);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,1440(r31)
	PPC_STORE_U16(r31.u32 + 1440, ctx.r6.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,1660(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1660);
	// lhz r11,1664(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1664);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,1664(r31)
	PPC_STORE_U16(r31.u32 + 1664, ctx.r6.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82680030;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r9,876(r31)
	PPC_STORE_U8(r31.u32 + 876, ctx.r9.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82680044"))) PPC_WEAK_FUNC(sub_82680044);
PPC_FUNC_IMPL(__imp__sub_82680044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680048"))) PPC_WEAK_FUNC(sub_82680048);
PPC_FUNC_IMPL(__imp__sub_82680048) {
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
	// bl 0x82646d30
	ctx.lr = 0x82680068;
	sub_82646D30(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680080
	if (cr6.eq) goto loc_82680080;
	// bl 0x82130588
	ctx.lr = 0x8268007C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82680080:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82680098"))) PPC_WEAK_FUNC(sub_82680098);
PPC_FUNC_IMPL(__imp__sub_82680098) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x826800A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// lfs f13,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fdivs f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 / ctx.f13.f64));
	// bl 0x823dba38
	ctx.lr = 0x826800C4;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,0,r29
	PPC_STORE_U32(r29.u32, ctx.f11.u32);
	// lfs f10,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// fdivs f1,f10,f9
	ctx.f1.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// bl 0x823dba38
	ctx.lr = 0x826800E0;
	sub_823DBA38(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,0,r28
	PPC_STORE_U32(r28.u32, ctx.f7.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// stw r6,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r6.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82680114"))) PPC_WEAK_FUNC(sub_82680114);
PPC_FUNC_IMPL(__imp__sub_82680114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680118"))) PPC_WEAK_FUNC(sub_82680118);
PPC_FUNC_IMPL(__imp__sub_82680118) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8268012C"))) PPC_WEAK_FUNC(sub_8268012C);
PPC_FUNC_IMPL(__imp__sub_8268012C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680130"))) PPC_WEAK_FUNC(sub_82680130);
PPC_FUNC_IMPL(__imp__sub_82680130) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r11,2384
	ctx.r10.s64 = r11.s64 + 2384;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v59,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82680160
	if (cr6.eq) goto loc_82680160;
	// b 0x82682970
	sub_82682970(ctx, base);
	return;
loc_82680160:
	// b 0x82682bf8
	sub_82682BF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82680164"))) PPC_WEAK_FUNC(sub_82680164);
PPC_FUNC_IMPL(__imp__sub_82680164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680168"))) PPC_WEAK_FUNC(sub_82680168);
PPC_FUNC_IMPL(__imp__sub_82680168) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,16736
	ctx.r9.s64 = r11.s64 + 16736;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x826801A0;
	sub_822E5148(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,29608(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29608, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x826801B4;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826801cc
	if (cr6.eq) goto loc_826801CC;
	// bl 0x82130588
	ctx.lr = 0x826801C8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826801CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826801E4"))) PPC_WEAK_FUNC(sub_826801E4);
PPC_FUNC_IMPL(__imp__sub_826801E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826801E8"))) PPC_WEAK_FUNC(sub_826801E8);
PPC_FUNC_IMPL(__imp__sub_826801E8) {
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
	ctx.lr = 0x826801F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8268022c
	if (!cr6.gt) goto loc_8268022C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_82680208:
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
	ctx.lr = 0x82680220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,160
	r31.s64 = r31.s64 + 160;
	// bne 0x82680208
	if (!cr0.eq) goto loc_82680208;
loc_8268022C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82680234;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8268023C"))) PPC_WEAK_FUNC(sub_8268023C);
PPC_FUNC_IMPL(__imp__sub_8268023C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680240"))) PPC_WEAK_FUNC(sub_82680240);
PPC_FUNC_IMPL(__imp__sub_82680240) {
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
	// bl 0x822e6b38
	ctx.lr = 0x82680260;
	sub_822E6B38(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,16736
	ctx.r9.s64 = r11.s64 + 16736;
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,-8092(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x82680290;
	sub_822E5138(ctx, base);
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// li r11,0
	r11.s64 = 0;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// addi r5,r6,16760
	ctx.r5.s64 = ctx.r6.s64 + 16760;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lis r4,16383
	ctx.r4.s64 = 1073676288;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// ori r3,r4,65535
	ctx.r3.u64 = ctx.r4.u64 | 65535;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// srawi r8,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x826802e8
	if (!cr6.gt) goto loc_826802E8;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_826802E8:
	// bl 0x82130528
	ctx.lr = 0x826802EC;
	sub_82130528(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823d9890
	ctx.lr = 0x82680300;
	sub_823D9890(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,29604(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29604, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82680324"))) PPC_WEAK_FUNC(sub_82680324);
PPC_FUNC_IMPL(__imp__sub_82680324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680328"))) PPC_WEAK_FUNC(sub_82680328);
PPC_FUNC_IMPL(__imp__sub_82680328) {
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
	ctx.lr = 0x82680330;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826803e4
	if (cr6.eq) goto loc_826803E4;
	// lhz r28,4(r11)
	r28.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// bl 0x82387a18
	ctx.lr = 0x8268034C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680380
	if (cr6.eq) goto loc_82680380;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x82680364;
	sub_82293F60(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,11364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x826803b0
	goto loc_826803B0;
loc_82680380:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lwz r4,2192(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
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
	// clrlwi r29,r11,1
	r29.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
loc_826803B0:
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x826803e4
	if (!cr6.gt) goto loc_826803E4;
	// li r30,0
	r30.s64 = 0;
loc_826803C0:
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// add r4,r31,r29
	ctx.r4.u64 = r31.u64 + r29.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82683b28
	ctx.lr = 0x826803D4;
	sub_82683B28(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,160
	r30.s64 = r30.s64 + 160;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x826803c0
	if (cr6.lt) goto loc_826803C0;
loc_826803E4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826803EC"))) PPC_WEAK_FUNC(sub_826803EC);
PPC_FUNC_IMPL(__imp__sub_826803EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826803F0"))) PPC_WEAK_FUNC(sub_826803F0);
PPC_FUNC_IMPL(__imp__sub_826803F0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x826803F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r4,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r4.u32);
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826804e4
	if (cr6.eq) goto loc_826804E4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826804e4
	if (!cr6.gt) goto loc_826804E4;
	// clrlwi r27,r5,24
	r27.u64 = ctx.r5.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82680424:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r26,36(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,44(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 44);
	f0.f64 = double(temp.f32);
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// lfs f13,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 / f0.f64));
	// bl 0x823dba38
	ctx.lr = 0x82680444;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,44(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// fdivs f1,f11,f10
	ctx.f1.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fctiwz f9,f12
	ctx.f9.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r25,84(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823dba38
	ctx.lr = 0x82680464;
	sub_823DBA38(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// lwz r10,52(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 52);
	// lwz r9,48(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 48);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// subf r7,r9,r25
	ctx.r7.s64 = r25.s64 - ctx.r9.s64;
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r5,r10,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r10.s64;
	// srawi r4,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 1;
	// srawi r11,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r11.s64 = ctx.r7.s32 >> 1;
	// mullw r10,r4,r8
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x826804c0
	if (cr0.lt) goto loc_826804C0;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x826804c0
	if (!cr6.lt) goto loc_826804C0;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r8.u32);
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stwx r31,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, r31.u32);
loc_826804C0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x826804d8
	if (!cr6.eq) goto loc_826804D8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x826804D8;
	sub_82683C10(ctx, base);
loc_826804D8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,160
	r29.s64 = r29.s64 + 160;
	// bne 0x82680424
	if (!cr0.eq) goto loc_82680424;
loc_826804E4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826804EC"))) PPC_WEAK_FUNC(sub_826804EC);
PPC_FUNC_IMPL(__imp__sub_826804EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826804F0"))) PPC_WEAK_FUNC(sub_826804F0);
PPC_FUNC_IMPL(__imp__sub_826804F0) {
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
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82680564
	if (cr6.eq) goto loc_82680564;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,48(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,68(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x8232b540
	ctx.lr = 0x82680544;
	sub_8232B540(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82680564
	if (cr6.eq) goto loc_82680564;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683828
	ctx.lr = 0x82680558;
	sub_82683828(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683a28
	ctx.lr = 0x82680564;
	sub_82683A28(ctx, base);
loc_82680564:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8268057C"))) PPC_WEAK_FUNC(sub_8268057C);
PPC_FUNC_IMPL(__imp__sub_8268057C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680580"))) PPC_WEAK_FUNC(sub_82680580);
PPC_FUNC_IMPL(__imp__sub_82680580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,29604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29604);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82680598"))) PPC_WEAK_FUNC(sub_82680598);
PPC_FUNC_IMPL(__imp__sub_82680598) {
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
	ctx.lr = 0x826805A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lwz r10,29604(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 29604);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82680618
	if (cr6.eq) goto loc_82680618;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add. r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82680618
	if (cr0.eq) goto loc_82680618;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82680608
	if (cr6.eq) goto loc_82680608;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82680608
	if (cr6.eq) goto loc_82680608;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8232b540
	ctx.lr = 0x82680608;
	sub_8232B540(ctx, base);
loc_82680608:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683828
	ctx.lr = 0x82680610;
	sub_82683828(ctx, base);
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// stb r29,144(r31)
	PPC_STORE_U8(r31.u32 + 144, r29.u8);
loc_82680618:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82680620"))) PPC_WEAK_FUNC(sub_82680620);
PPC_FUNC_IMPL(__imp__sub_82680620) {
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
	ctx.lr = 0x82680628;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8268071c
	if (!cr6.eq) goto loc_8268071C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8268065C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8268071c
	if (cr6.eq) goto loc_8268071C;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x8232a820
	ctx.lr = 0x82680678;
	sub_8232A820(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8268071c
	if (cr6.eq) goto loc_8268071C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x82682758
	ctx.lr = 0x82680690;
	sub_82682758(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82387a18
	ctx.lr = 0x82680698;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826806d0
	if (cr6.eq) goto loc_826806D0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b968
	ctx.lr = 0x826806BC;
	sub_8227B968(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683828
	ctx.lr = 0x826806C4;
	sub_82683828(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826806D0:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r31,r8,2192
	r31.s64 = ctx.r8.s64 + 2192;
	// ori r6,r7,64167
	ctx.r6.u64 = ctx.r7.u64 | 64167;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r9,2192(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r10,r9,r6
	ctx.r10.s64 = ctx.r9.s64 * ctx.r6.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// bl 0x826804f0
	ctx.lr = 0x82680710;
	sub_826804F0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8268071C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82680728"))) PPC_WEAK_FUNC(sub_82680728);
PPC_FUNC_IMPL(__imp__sub_82680728) {
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
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82680730;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680924
	if (cr6.eq) goto loc_82680924;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82680770
	if (cr6.eq) goto loc_82680770;
	// addi r10,r4,101
	ctx.r10.s64 = ctx.r4.s64 + 101;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r23,r9,r11
	r23.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x82680778
	goto loc_82680778;
loc_82680770:
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r23,r10,r11
	r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_82680778:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82680924
	if (cr6.eq) goto loc_82680924;
	// lwz r9,48(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82680924
	if (cr6.eq) goto loc_82680924;
	// lwz r10,68(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,140(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 140);
	// cmpwi cr6,r11,25
	cr6.compare<int32_t>(r11.s32, 25, xer);
	// beq cr6,0x826807b8
	if (cr6.eq) goto loc_826807B8;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// blt cr6,0x826807b8
	if (cr6.lt) goto loc_826807B8;
	// lwz r11,136(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x826807bc
	if (!cr6.lt) goto loc_826807BC;
loc_826807B8:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826807BC:
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// clrlwi r22,r11,24
	r22.u64 = r11.u32 & 0xFF;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwz r11,664(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826807f0
	if (cr6.eq) goto loc_826807F0;
	// lhz r6,18(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// lhz r5,14(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// blt cr6,0x826807f0
	if (cr6.lt) goto loc_826807F0;
	// li r10,1
	ctx.r10.s64 = 1;
loc_826807F0:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680808
	if (cr6.eq) goto loc_82680808;
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82680924
	if (!cr6.eq) goto loc_82680924;
loc_82680808:
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// beq cr6,0x82680820
	if (cr6.eq) goto loc_82680820;
	// addi r11,r9,272
	r11.s64 = ctx.r9.s64 + 272;
	// b 0x82680828
	goto loc_82680828;
loc_82680820:
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82680828:
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,31304(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31304);
	f0.f64 = double(temp.f32);
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82680098
	ctx.lr = 0x8268086C;
	sub_82680098(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// srawi r26,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r26.s64 = ctx.r7.s32 >> 1;
	// srawi r25,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	r25.s64 = ctx.r6.s32 >> 1;
	// addi r27,r25,-1
	r27.s64 = r25.s64 + -1;
	// cmpw cr6,r27,r25
	cr6.compare<int32_t>(r27.s32, r25.s32, xer);
	// bgt cr6,0x82680924
	if (cr6.gt) goto loc_82680924;
	// addi r24,r26,-1
	r24.s64 = r26.s64 + -1;
loc_8268088C:
	// mr r28,r24
	r28.u64 = r24.u64;
	// cmpw cr6,r24,r26
	cr6.compare<int32_t>(r24.s32, r26.s32, xer);
	// bgt cr6,0x82680918
	if (cr6.gt) goto loc_82680918;
loc_82680898:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// mullw r11,r27,r11
	r11.s64 = int64_t(r27.s32) * int64_t(r11.s32);
	// add. r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8268090c
	if (cr0.lt) goto loc_8268090C;
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8268090c
	if (!cr6.lt) goto loc_8268090C;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8268090c
	if (cr6.eq) goto loc_8268090C;
	// clrlwi r30,r22,24
	r30.u64 = r22.u32 & 0xFF;
loc_826808CC:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82680900
	if (!cr6.eq) goto loc_82680900;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82680900
	if (cr6.eq) goto loc_82680900;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82680620
	ctx.lr = 0x826808F4;
	sub_82680620(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82680924
	if (!cr6.eq) goto loc_82680924;
loc_82680900:
	// lwz r31,156(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826808cc
	if (!cr6.eq) goto loc_826808CC;
loc_8268090C:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// ble cr6,0x82680898
	if (!cr6.gt) goto loc_82680898;
loc_82680918:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r27,r25
	cr6.compare<int32_t>(r27.s32, r25.s32, xer);
	// ble cr6,0x8268088c
	if (!cr6.gt) goto loc_8268088C;
loc_82680924:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8268092C"))) PPC_WEAK_FUNC(sub_8268092C);
PPC_FUNC_IMPL(__imp__sub_8268092C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680930"))) PPC_WEAK_FUNC(sub_82680930);
PPC_FUNC_IMPL(__imp__sub_82680930) {
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
	// bl 0x826830a0
	ctx.lr = 0x82680964;
	sub_826830A0(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82680980"))) PPC_WEAK_FUNC(sub_82680980);
PPC_FUNC_IMPL(__imp__sub_82680980) {
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
	// bl 0x82683650
	ctx.lr = 0x826809A0;
	sub_82683650(ctx, base);
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

__attribute__((alias("__imp__sub_826809BC"))) PPC_WEAK_FUNC(sub_826809BC);
PPC_FUNC_IMPL(__imp__sub_826809BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826809C0"))) PPC_WEAK_FUNC(sub_826809C0);
PPC_FUNC_IMPL(__imp__sub_826809C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,29604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29604);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826809E0"))) PPC_WEAK_FUNC(sub_826809E0);
PPC_FUNC_IMPL(__imp__sub_826809E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,29604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29604);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x826803f0
	sub_826803F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826809F8"))) PPC_WEAK_FUNC(sub_826809F8);
PPC_FUNC_IMPL(__imp__sub_826809F8) {
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
	ctx.lr = 0x82680A00;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,29604(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 29604);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82680ae4
	if (cr6.eq) goto loc_82680AE4;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r29,r11
	ctx.r8.u64 = r29.u64 + r11.u64;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r10,r8,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add. r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82680ae4
	if (cr0.eq) goto loc_82680AE4;
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82680ae4
	if (!cr6.eq) goto loc_82680AE4;
	// lwz r30,136(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r30,25
	cr6.compare<int32_t>(r30.s32, 25, xer);
	// beq cr6,0x82680ae4
	if (cr6.eq) goto loc_82680AE4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x82680A60;
	sub_822B62A0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683828
	ctx.lr = 0x82680A6C;
	sub_82683828(ctx, base);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,2192(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
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
	// clrlwi r4,r11,1
	ctx.r4.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// bl 0x82683a28
	ctx.lr = 0x82680AA4;
	sub_82683A28(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lbz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stb r10,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r10.u8);
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227cac8
	ctx.lr = 0x82680AD4;
	sub_8227CAC8(ctx, base);
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82276438
	ctx.lr = 0x82680AE4;
	sub_82276438(ctx, base);
loc_82680AE4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82680AEC"))) PPC_WEAK_FUNC(sub_82680AEC);
PPC_FUNC_IMPL(__imp__sub_82680AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680AF0"))) PPC_WEAK_FUNC(sub_82680AF0);
PPC_FUNC_IMPL(__imp__sub_82680AF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
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
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f1,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
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
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82680B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82680B64"))) PPC_WEAK_FUNC(sub_82680B64);
PPC_FUNC_IMPL(__imp__sub_82680B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680B68"))) PPC_WEAK_FUNC(sub_82680B68);
PPC_FUNC_IMPL(__imp__sub_82680B68) {
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
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82680B70;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680d60
	if (cr6.eq) goto loc_82680D60;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39f0
	ctx.lr = 0x82680B94;
	sub_822A39F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680d60
	if (cr6.eq) goto loc_82680D60;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82680BAC;
	sub_822A3998(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r10,48(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 48);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82680d60
	if (cr6.eq) goto loc_82680D60;
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,140(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 140);
	// cmpwi cr6,r11,25
	cr6.compare<int32_t>(r11.s32, 25, xer);
	// beq cr6,0x82680be8
	if (cr6.eq) goto loc_82680BE8;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// blt cr6,0x82680be8
	if (cr6.lt) goto loc_82680BE8;
	// lwz r11,136(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 136);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82680bec
	if (!cr6.lt) goto loc_82680BEC;
loc_82680BE8:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82680BEC:
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// clrlwi r21,r11,24
	r21.u64 = r11.u32 & 0xFF;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// lwz r11,664(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680c20
	if (cr6.eq) goto loc_82680C20;
	// lhz r7,18(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// lhz r6,14(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// cmpw cr6,r5,r4
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, xer);
	// blt cr6,0x82680c20
	if (cr6.lt) goto loc_82680C20;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82680C20:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680c38
	if (cr6.eq) goto loc_82680C38;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82680d60
	if (!cr6.eq) goto loc_82680D60;
loc_82680C38:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82680c5c
	if (cr6.eq) goto loc_82680C5C;
	// addi r11,r10,272
	r11.s64 = ctx.r10.s64 + 272;
	// b 0x82680c64
	goto loc_82680C64;
loc_82680C5C:
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82680C64:
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,31304(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31304);
	f0.f64 = double(temp.f32);
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82680098
	ctx.lr = 0x82680CA8;
	sub_82680098(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// srawi r26,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r26.s64 = ctx.r7.s32 >> 1;
	// srawi r23,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	r23.s64 = ctx.r6.s32 >> 1;
	// addi r27,r23,-1
	r27.s64 = r23.s64 + -1;
	// cmpw cr6,r27,r23
	cr6.compare<int32_t>(r27.s32, r23.s32, xer);
	// bgt cr6,0x82680d60
	if (cr6.gt) goto loc_82680D60;
	// addi r22,r26,-1
	r22.s64 = r26.s64 + -1;
loc_82680CC8:
	// mr r28,r22
	r28.u64 = r22.u64;
	// cmpw cr6,r22,r26
	cr6.compare<int32_t>(r22.s32, r26.s32, xer);
	// bgt cr6,0x82680d54
	if (cr6.gt) goto loc_82680D54;
loc_82680CD4:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mullw r11,r27,r11
	r11.s64 = int64_t(r27.s32) * int64_t(r11.s32);
	// add. r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x82680d48
	if (cr0.lt) goto loc_82680D48;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82680d48
	if (!cr6.lt) goto loc_82680D48;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82680d48
	if (cr6.eq) goto loc_82680D48;
	// clrlwi r29,r21,24
	r29.u64 = r21.u32 & 0xFF;
loc_82680D08:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82680d1c
	if (cr6.eq) goto loc_82680D1C;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82680d3c
	if (!cr6.eq) goto loc_82680D3C;
loc_82680D1C:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82680620
	ctx.lr = 0x82680D30;
	sub_82680620(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82680d60
	if (!cr6.eq) goto loc_82680D60;
loc_82680D3C:
	// lwz r31,156(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82680d08
	if (!cr6.eq) goto loc_82680D08;
loc_82680D48:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// ble cr6,0x82680cd4
	if (!cr6.gt) goto loc_82680CD4;
loc_82680D54:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r27,r23
	cr6.compare<int32_t>(r27.s32, r23.s32, xer);
	// ble cr6,0x82680cc8
	if (!cr6.gt) goto loc_82680CC8;
loc_82680D60:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82680D68"))) PPC_WEAK_FUNC(sub_82680D68);
PPC_FUNC_IMPL(__imp__sub_82680D68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32152
	r11.s64 = -2107113472;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,304
	ctx.r3.s64 = r11.s64 + 304;
	// b 0x82680af0
	sub_82680AF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82680D78"))) PPC_WEAK_FUNC(sub_82680D78);
PPC_FUNC_IMPL(__imp__sub_82680D78) {
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
	ctx.lr = 0x82680D80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680e74
	if (cr6.eq) goto loc_82680E74;
	// bl 0x82387a18
	ctx.lr = 0x82680D98;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680db4
	if (cr6.eq) goto loc_82680DB4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82680b68
	ctx.lr = 0x82680DB0;
	sub_82680B68(ctx, base);
	// b 0x82680e38
	goto loc_82680E38;
loc_82680DB4:
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// li r31,0
	r31.s64 = 0;
	// lis r30,-32121
	r30.s64 = -2105081856;
loc_82680DC4:
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,17268(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// beq cr6,0x82680ddc
	if (cr6.eq) goto loc_82680DDC;
	// lwz r11,260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// b 0x82680de0
	goto loc_82680DE0;
loc_82680DDC:
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
loc_82680DE0:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82680dfc
	if (!cr6.lt) goto loc_82680DFC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82680b68
	ctx.lr = 0x82680DF4;
	sub_82680B68(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// b 0x82680dc4
	goto loc_82680DC4;
loc_82680DFC:
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82680e18
	if (cr6.eq) goto loc_82680E18;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82680e1c
	goto loc_82680E1C;
loc_82680E18:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82680E1C:
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x82680e38
	if (cr0.lt) goto loc_82680E38;
loc_82680E24:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82680728
	ctx.lr = 0x82680E30;
	sub_82680728(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x82680e24
	if (!cr0.lt) goto loc_82680E24;
loc_82680E38:
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lhz r31,4(r11)
	r31.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82680e74
	if (!cr6.gt) goto loc_82680E74;
	// li r30,0
	r30.s64 = 0;
loc_82680E4C:
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82680E68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,160
	r30.s64 = r30.s64 + 160;
	// bne 0x82680e4c
	if (!cr0.eq) goto loc_82680E4C;
loc_82680E74:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82680E7C"))) PPC_WEAK_FUNC(sub_82680E7C);
PPC_FUNC_IMPL(__imp__sub_82680E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680E80"))) PPC_WEAK_FUNC(sub_82680E80);
PPC_FUNC_IMPL(__imp__sub_82680E80) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82680E88;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r30,20(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82680ec4
	if (cr6.eq) goto loc_82680EC4;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82680eb8
	if (cr6.eq) goto loc_82680EB8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x826801e8
	ctx.lr = 0x82680EB8;
	sub_826801E8(ctx, base);
loc_82680EB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82680EC0;
	sub_82130588(ctx, base);
	// stw r31,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r31.u32);
loc_82680EC4:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680fcc
	if (cr6.eq) goto loc_82680FCC;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r10,112
	ctx.r10.s64 = 112;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f0,31304(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31304);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82680098
	ctx.lr = 0x82680F24;
	sub_82680098(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// srawi r10,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 1;
	// srawi r11,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	r11.s64 = ctx.r6.s32 >> 1;
	// addi r28,r11,-4
	r28.s64 = r11.s64 + -4;
	// addi r26,r11,4
	r26.s64 = r11.s64 + 4;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// bgt cr6,0x82680fcc
	if (cr6.gt) goto loc_82680FCC;
	// addi r25,r10,-4
	r25.s64 = ctx.r10.s64 + -4;
	// addi r27,r10,4
	r27.s64 = ctx.r10.s64 + 4;
loc_82680F4C:
	// mr r30,r25
	r30.u64 = r25.u64;
	// cmpw cr6,r25,r27
	cr6.compare<int32_t>(r25.s32, r27.s32, xer);
	// bgt cr6,0x82680fc0
	if (cr6.gt) goto loc_82680FC0;
loc_82680F58:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// mullw r11,r28,r11
	r11.s64 = int64_t(r28.s32) * int64_t(r11.s32);
	// add. r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82680fb4
	if (!cr0.gt) goto loc_82680FB4;
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82680fb4
	if (!cr6.lt) goto loc_82680FB4;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82680fb4
	if (cr6.eq) goto loc_82680FB4;
loc_82680F88:
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82680fa8
	if (!cr6.eq) goto loc_82680FA8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82680FA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82680FA8:
	// lwz r31,156(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82680f88
	if (!cr6.eq) goto loc_82680F88;
loc_82680FB4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// ble cr6,0x82680f58
	if (!cr6.gt) goto loc_82680F58;
loc_82680FC0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// ble cr6,0x82680f4c
	if (!cr6.gt) goto loc_82680F4C;
loc_82680FCC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82680FD4"))) PPC_WEAK_FUNC(sub_82680FD4);
PPC_FUNC_IMPL(__imp__sub_82680FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680FD8"))) PPC_WEAK_FUNC(sub_82680FD8);
PPC_FUNC_IMPL(__imp__sub_82680FD8) {
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
	// lis r11,-32152
	r11.s64 = -2107113472;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r11,2352
	ctx.r4.s64 = r11.s64 + 2352;
	// addi r3,r10,16964
	ctx.r3.s64 = ctx.r10.s64 + 16964;
	// bl 0x82554798
	ctx.lr = 0x82680FF8;
	sub_82554798(ctx, base);
	// lis r9,-32152
	ctx.r9.s64 = -2107113472;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r4,r9,2432
	ctx.r4.s64 = ctx.r9.s64 + 2432;
	// addi r3,r8,16928
	ctx.r3.s64 = ctx.r8.s64 + 16928;
	// bl 0x82554798
	ctx.lr = 0x8268100C;
	sub_82554798(ctx, base);
	// lis r7,-32152
	ctx.r7.s64 = -2107113472;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// addi r4,r7,3432
	ctx.r4.s64 = ctx.r7.s64 + 3432;
	// addi r3,r6,16896
	ctx.r3.s64 = ctx.r6.s64 + 16896;
	// bl 0x82554798
	ctx.lr = 0x82681020;
	sub_82554798(ctx, base);
	// lis r5,-32152
	ctx.r5.s64 = -2107113472;
	// lis r3,-32245
	ctx.r3.s64 = -2113208320;
	// addi r4,r5,2496
	ctx.r4.s64 = ctx.r5.s64 + 2496;
	// addi r3,r3,16860
	ctx.r3.s64 = ctx.r3.s64 + 16860;
	// bl 0x82554798
	ctx.lr = 0x82681034;
	sub_82554798(ctx, base);
	// lis r11,-32152
	r11.s64 = -2107113472;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r11,2528
	ctx.r4.s64 = r11.s64 + 2528;
	// addi r3,r10,16824
	ctx.r3.s64 = ctx.r10.s64 + 16824;
	// bl 0x82554798
	ctx.lr = 0x82681048;
	sub_82554798(ctx, base);
	// lis r9,-32152
	ctx.r9.s64 = -2107113472;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r4,r9,1408
	ctx.r4.s64 = ctx.r9.s64 + 1408;
	// addi r3,r8,16796
	ctx.r3.s64 = ctx.r8.s64 + 16796;
	// bl 0x82554798
	ctx.lr = 0x8268105C;
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

__attribute__((alias("__imp__sub_8268106C"))) PPC_WEAK_FUNC(sub_8268106C);
PPC_FUNC_IMPL(__imp__sub_8268106C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82681070"))) PPC_WEAK_FUNC(sub_82681070);
PPC_FUNC_IMPL(__imp__sub_82681070) {
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
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x826810bc
	if (!cr6.eq) goto loc_826810BC;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
	// bl 0x823d9890
	ctx.lr = 0x826810B4;
	sub_823D9890(ctx, base);
	// stw r31,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r31.u32);
	// b 0x826810e4
	goto loc_826810E4;
loc_826810BC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826810e4
	if (cr6.eq) goto loc_826810E4;
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826810dc
	if (cr6.eq) goto loc_826810DC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x826801e8
	ctx.lr = 0x826810DC;
	sub_826801E8(ctx, base);
loc_826810DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x826810E4;
	sub_82130588(ctx, base);
loc_826810E4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826810FC"))) PPC_WEAK_FUNC(sub_826810FC);
PPC_FUNC_IMPL(__imp__sub_826810FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82681100"))) PPC_WEAK_FUNC(sub_82681100);
PPC_FUNC_IMPL(__imp__sub_82681100) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,16760
	ctx.r9.s64 = r11.s64 + 16760;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,29604(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29604, r11.u32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82681070
	ctx.lr = 0x82681134;
	sub_82681070(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x8268113C;
	sub_82130588(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// addi r6,r8,16736
	ctx.r6.s64 = ctx.r8.s64 + 16736;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r3,-8092(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x82681158;
	sub_822E5148(ctx, base);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,29608(r5)
	PPC_STORE_U32(ctx.r5.u32 + 29608, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x8268116C;
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

__attribute__((alias("__imp__sub_82681180"))) PPC_WEAK_FUNC(sub_82681180);
PPC_FUNC_IMPL(__imp__sub_82681180) {
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
	// bl 0x82681100
	ctx.lr = 0x826811A0;
	sub_82681100(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826811b8
	if (cr6.eq) goto loc_826811B8;
	// bl 0x82130588
	ctx.lr = 0x826811B4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826811B8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826811D0"))) PPC_WEAK_FUNC(sub_826811D0);
PPC_FUNC_IMPL(__imp__sub_826811D0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x826811D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x826811E4;
	sub_824E0648(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r8,17352
	ctx.r6.s64 = ctx.r8.s64 + 17352;
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// stfs f13,44(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f13,48(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lis r30,-32245
	r30.s64 = -2113208320;
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lis r29,-32245
	r29.s64 = -2113208320;
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lis r28,-32245
	r28.s64 = -2113208320;
	// lfs f13,-13148(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,24(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,124(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f0,120(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// lfs f13,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31960(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31960);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,140(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f0,132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f0,136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f13,144(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stfs f13,156(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stfs f0,148(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// lfs f12,-28880(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -28880);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,160(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// stfs f12,164(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lfs f11,32692(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32692);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,168(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// lfs f12,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,176(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f12,180(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stfs f11,184(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// stfs f13,188(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// lfs f13,17344(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17344);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17340(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17340);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,17336(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17336);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,17332(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 17332);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,17328(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 17328);
	ctx.f9.f64 = double(temp.f32);
	// stfs f13,192(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stfs f12,196(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f11,200(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// stfs f0,204(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// stfs f10,208(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f9,212(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// lfs f13,17324(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 17324);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f13,216(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f0,220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82681338"))) PPC_WEAK_FUNC(sub_82681338);
PPC_FUNC_IMPL(__imp__sub_82681338) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,17384
	ctx.r3.s64 = r11.s64 + 17384;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82681344"))) PPC_WEAK_FUNC(sub_82681344);
PPC_FUNC_IMPL(__imp__sub_82681344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82681348"))) PPC_WEAK_FUNC(sub_82681348);
PPC_FUNC_IMPL(__imp__sub_82681348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,17400
	ctx.r3.s64 = r11.s64 + 17400;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82681354"))) PPC_WEAK_FUNC(sub_82681354);
PPC_FUNC_IMPL(__imp__sub_82681354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82681358"))) PPC_WEAK_FUNC(sub_82681358);
PPC_FUNC_IMPL(__imp__sub_82681358) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,17688
	ctx.r5.s64 = r11.s64 + 17688;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82681394;
	sub_824DF200(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17676
	ctx.r5.s64 = ctx.r10.s64 + 17676;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x826813B4;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-3464
	ctx.r5.s64 = ctx.r9.s64 + -3464;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x826813D4;
	sub_824DF200(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,17660
	ctx.r5.s64 = ctx.r8.s64 + 17660;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x826813F4;
	sub_824DF200(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,17640
	ctx.r5.s64 = ctx.r7.s64 + 17640;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,28
	ctx.r6.s64 = r31.s64 + 28;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82681414;
	sub_824DF200(ctx, base);
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,17624
	ctx.r5.s64 = ctx.r6.s64 + 17624;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82681434;
	sub_824DF200(ctx, base);
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,17612
	ctx.r5.s64 = ctx.r5.s64 + 17612;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,36
	ctx.r6.s64 = r31.s64 + 36;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82681454;
	sub_824DF200(ctx, base);
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,17596
	ctx.r5.s64 = ctx.r4.s64 + 17596;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,40
	ctx.r6.s64 = r31.s64 + 40;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82681474;
	sub_824DF200(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,17580
	ctx.r5.s64 = r11.s64 + 17580;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,44
	ctx.r6.s64 = r31.s64 + 44;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82681494;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-3480
	ctx.r5.s64 = ctx.r10.s64 + -3480;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,48
	ctx.r6.s64 = r31.s64 + 48;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826814B4;
	sub_824DF200(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,17564
	ctx.r5.s64 = ctx.r9.s64 + 17564;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,52
	ctx.r6.s64 = r31.s64 + 52;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x826814D4;
	sub_824DF200(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,17552
	ctx.r5.s64 = ctx.r8.s64 + 17552;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,64
	ctx.r6.s64 = r31.s64 + 64;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x826814F4;
	sub_824DF200(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,17536
	ctx.r5.s64 = ctx.r7.s64 + 17536;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,80
	ctx.r6.s64 = r31.s64 + 80;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82681514;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-3452
	ctx.r5.s64 = ctx.r6.s64 + -3452;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82681534;
	sub_824DF200(ctx, base);
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,17520
	ctx.r5.s64 = ctx.r5.s64 + 17520;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82681554;
	sub_824DF200(ctx, base);
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,17500
	ctx.r5.s64 = ctx.r4.s64 + 17500;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82681574;
	sub_824DF200(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,17480
	ctx.r5.s64 = r11.s64 + 17480;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82681594;
	sub_824DF200(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17460
	ctx.r5.s64 = ctx.r10.s64 + 17460;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x826815B4;
	sub_824DF200(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,17440
	ctx.r5.s64 = ctx.r9.s64 + 17440;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,176
	ctx.r6.s64 = r31.s64 + 176;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x826815D4;
	sub_824DF200(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,17424
	ctx.r5.s64 = ctx.r7.s64 + 17424;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,208
	ctx.r6.s64 = r31.s64 + 208;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826815F4;
	sub_824DF200(ctx, base);
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,192
	ctx.r6.s64 = r31.s64 + 192;
	// addi r5,r5,17412
	ctx.r5.s64 = ctx.r5.s64 + 17412;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82681614;
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

__attribute__((alias("__imp__sub_8268162C"))) PPC_WEAK_FUNC(sub_8268162C);
PPC_FUNC_IMPL(__imp__sub_8268162C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82681630"))) PPC_WEAK_FUNC(sub_82681630);
PPC_FUNC_IMPL(__imp__sub_82681630) {
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
	ctx.lr = 0x82681638;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32112
	r26.s64 = -2104492032;
	// lbz r11,29884(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 29884);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82681754
	if (cr6.eq) goto loc_82681754;
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lwz r3,29912(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 29912);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82681670
	if (cr6.eq) goto loc_82681670;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82681670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82681670:
	// lis r31,-32112
	r31.s64 = -2104492032;
	// li r28,0
	r28.s64 = 0;
	// mr r11,r28
	r11.u64 = r28.u64;
	// lwz r3,29888(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stw r11,29912(r30)
	PPC_STORE_U32(r30.u32 + 29912, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826816a0
	if (cr6.eq) goto loc_826816A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826816A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826816A0:
	// lis r30,-32112
	r30.s64 = -2104492032;
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,29888(r31)
	PPC_STORE_U32(r31.u32 + 29888, r11.u32);
	// lwz r3,29616(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 29616);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826816bc
	if (cr6.eq) goto loc_826816BC;
	// bl 0x82177a08
	ctx.lr = 0x826816BC;
	sub_82177A08(ctx, base);
loc_826816BC:
	// mr r11,r28
	r11.u64 = r28.u64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r11,29616(r30)
	PPC_STORE_U32(r30.u32 + 29616, r11.u32);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r31,r28
	r31.u64 = r28.u64;
	// addi r27,r10,29736
	r27.s64 = ctx.r10.s64 + 29736;
	// addi r29,r11,29640
	r29.s64 = r11.s64 + 29640;
loc_826816D8:
	// lwzx r30,r31,r29
	r30.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82681714
	if (cr6.eq) goto loc_82681714;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x826816EC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82681714
	if (!cr6.eq) goto loc_82681714;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82681714
	if (cr6.eq) goto loc_82681714;
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
	ctx.lr = 0x82681714;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82681714:
	// lwzx r3,r31,r27
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r27.u32);
	// add r30,r31,r27
	r30.u64 = r31.u64 + r27.u64;
	// stwx r28,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, r28.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8268173c
	if (cr6.eq) goto loc_8268173C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8268173C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8268173C:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// cmpwi cr6,r31,96
	cr6.compare<int32_t>(r31.s32, 96, xer);
	// blt cr6,0x826816d8
	if (cr6.lt) goto loc_826816D8;
	// mr r11,r28
	r11.u64 = r28.u64;
	// stb r11,29884(r26)
	PPC_STORE_U8(r26.u32 + 29884, r11.u8);
loc_82681754:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8268175C"))) PPC_WEAK_FUNC(sub_8268175C);
PPC_FUNC_IMPL(__imp__sub_8268175C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82681760"))) PPC_WEAK_FUNC(sub_82681760);
PPC_FUNC_IMPL(__imp__sub_82681760) {
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
	PPCRegister f0{};
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
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91e4
	ctx.lr = 0x82681768;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9b0
	ctx.lr = 0x82681770;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// fmr f31,f3
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f3.f64;
	// addi r8,r11,29736
	ctx.r8.s64 = r11.s64 + 29736;
	// rlwinm r28,r4,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r9,-26876(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r29,r28,r8
	r29.u64 = PPC_LOAD_U32(r28.u32 + ctx.r8.u32);
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// lvx128 v62,r3,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r29,32
	r11.s64 = r29.s64 + 32;
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// addi r10,r29,52
	ctx.r10.s64 = r29.s64 + 52;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f13,48(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// vsubfp128 v11,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v61,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v9,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvlx128 v59,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v8,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvlx128 v58,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v7,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vspltw128 v6,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// fadds f11,f12,f1
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// lvx128 v13,r9,r5
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vsubfp128 v10,v63,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v12,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v5,v0,v8,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v4,v11,v9,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// lvlx128 v57,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp v3,v11,v7,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// lvlx128 v56,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp v2,v0,v6,v12
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// lvlx128 v55,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v54,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v1,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v31,v56,0
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// li r3,1
	ctx.r3.s64 = 1;
	// vspltw128 v30,v55,0
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vspltw128 v29,v54,0
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vmaddfp v28,v13,v31,v5
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v27,v13,v1,v4
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v26,v10,v30,v3
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v25,v10,v29,v2
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// stvx128 v28,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v27,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v26,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217fed0
	ctx.lr = 0x82681868;
	sub_8217FED0(ctx, base);
	// lis r26,-32131
	r26.s64 = -2105737216;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,17320(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82681884
	if (!cr6.lt) goto loc_82681884;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_82681884:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x8268188C;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x82681898;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x826818A4;
	sub_8217F768(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x826818B0;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x826818BC;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x826818C8;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x826818D4;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x826818E0;
	sub_8217F768(ctx, base);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// li r11,112
	r11.s64 = 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f13,30432(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 30432);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f12,-11620(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -11620);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v53,r29,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f13,30432(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 30432, temp.u32);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lis r27,-32112
	r27.s64 = -2104492032;
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f6,f12,f31
	ctx.f6.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lwz r3,29912(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 29912);
	// lfs f0,15360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 15360);
	f0.f64 = double(temp.f32);
	// lwz r6,29852(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 29852);
	// stvx128 v53,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fctiwz f7,f9
	ctx.f7.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f7.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f4,f8
	ctx.f4.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f4.u64);
	// lwz r29,100(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fmuls f5,f11,f0
	ctx.f5.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fctiwz f2,f5
	ctx.f2.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f2,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f2.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f1,f3
	ctx.f1.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f1,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f1.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwimi r10,r9,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r11,r8,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r29,r11,8,0,23
	r29.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (r29.u64 & 0xFFFFFFFF000000FF);
	// bl 0x82187f40
	ctx.lr = 0x826819A8;
	sub_82187F40(ctx, base);
	// lfs f0,30432(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 30432);
	f0.f64 = double(temp.f32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// srawi r6,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r11,r5,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r10,r11,r7
	ctx.r10.s64 = ctx.r7.s64 - r11.s64;
	// lfs f31,30280(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 30280);
	f31.f64 = double(temp.f32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f30,f11,f31
	f30.f64 = double(float(ctx.f11.f64 * f31.f64));
	// fmr f27,f30
	f27.f64 = f30.f64;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x826819F8;
	sub_823DBBC8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82681A04;
	sub_823DBAE8(ctx, base);
	// frsp f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82681A10;
	sub_823DBAE8(ctx, base);
	// frsp f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82681A1C;
	sub_823DBBC8(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fneg f13,f26
	ctx.f13.u64 = f26.u64 ^ 0x8000000000000000;
	// addi r24,r8,-32224
	r24.s64 = ctx.r8.s64 + -32224;
	// fadds f27,f30,f31
	f27.f64 = double(float(f30.f64 + f31.f64));
	// stfs f0,-32224(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + -32224, temp.u32);
	// stfs f28,4(r24)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r24.u32 + 4, temp.u32);
	// stfs f13,8(r24)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r24.u32 + 8, temp.u32);
	// stfs f29,12(r24)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r24.u32 + 12, temp.u32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82681A48;
	sub_823DBBC8(ctx, base);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82681A54;
	sub_823DBAE8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82681A60;
	sub_823DBAE8(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82681A6C;
	sub_823DBBC8(ctx, base);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fneg f13,f29
	ctx.f13.u64 = f29.u64 ^ 0x8000000000000000;
	// lwz r11,29912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29912);
	// addi r23,r7,-32208
	r23.s64 = ctx.r7.s64 + -32208;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stfs f0,-32208(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -32208, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stfs f31,12(r23)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r23.u32 + 12, temp.u32);
	// stfs f30,4(r23)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r23.u32 + 4, temp.u32);
	// lwz r6,29616(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 29616);
	// stfs f13,8(r23)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r23.u32 + 8, temp.u32);
	// lwz r5,29876(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 29876);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82681AAC;
	sub_82189CE0(ctx, base);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// lis r3,-32112
	ctx.r3.s64 = -2104492032;
	// lwz r11,29912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29912);
	// lwz r5,29872(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 29872);
	// addi r10,r3,29640
	ctx.r10.s64 = ctx.r3.s64 + 29640;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwzx r6,r28,r10
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	// bl 0x82189ce0
	ctx.lr = 0x82681AD0;
	sub_82189CE0(ctx, base);
	// lwz r11,29912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29912);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r5,29836(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 29836);
	// bl 0x8218a6e0
	ctx.lr = 0x82681AF8;
	sub_8218A6E0(ctx, base);
	// lwz r11,29912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29912);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,29624(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 29624);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82681B20;
	sub_8218A6E0(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82681c3c
	if (!cr6.gt) goto loc_82681C3C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f29,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f29.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f28,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f28.f64 = double(temp.f32);
	// lfs f27,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f27.f64 = double(temp.f32);
	// lfs f26,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f26.f64 = double(temp.f32);
	// lfs f25,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f25.f64 = double(temp.f32);
	// lfs f24,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f24.f64 = double(temp.f32);
	// lfs f23,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f23.f64 = double(temp.f32);
	// lfs f22,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	f22.f64 = double(temp.f32);
	// lfs f21,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f21.f64 = double(temp.f32);
	// lfs f20,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f20.f64 = double(temp.f32);
	// lfs f19,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f19.f64 = double(temp.f32);
	// lfs f18,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f18.f64 = double(temp.f32);
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82681B6C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,29912(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 29912);
	// bl 0x82187b88
	ctx.lr = 0x82681B78;
	sub_82187B88(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x82681B84;
	sub_8217BB68(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lfs f4,30432(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 30432);
	ctx.f4.f64 = double(temp.f32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82681BAC;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lfs f4,30432(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 30432);
	ctx.f4.f64 = double(temp.f32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f3,f26
	ctx.f3.f64 = f26.f64;
	// fmr f2,f25
	ctx.f2.f64 = f25.f64;
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82681BD4;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lfs f4,30432(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 30432);
	ctx.f4.f64 = double(temp.f32);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f3,f23
	ctx.f3.f64 = f23.f64;
	// fmr f2,f22
	ctx.f2.f64 = f22.f64;
	// fmr f1,f21
	ctx.f1.f64 = f21.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82681BFC;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lfs f4,30432(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 30432);
	ctx.f4.f64 = double(temp.f32);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f3,f20
	ctx.f3.f64 = f20.f64;
	// fmr f2,f19
	ctx.f2.f64 = f19.f64;
	// fmr f1,f18
	ctx.f1.f64 = f18.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82681C24;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x82681C28;
	sub_8217BC98(ctx, base);
	// lwz r3,29912(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 29912);
	// bl 0x82187ba8
	ctx.lr = 0x82681C30;
	sub_82187BA8(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r27
	cr6.compare<int32_t>(r28.s32, r27.s32, xer);
	// blt cr6,0x82681b6c
	if (cr6.lt) goto loc_82681B6C;
loc_82681C3C:
	// lwz r3,29912(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 29912);
	// bl 0x82187bd0
	ctx.lr = 0x82681C44;
	sub_82187BD0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x82681C4C;
	sub_8217D9A0(ctx, base);
	// lwz r11,17320(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 17320);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// ble cr6,0x82681c60
	if (!cr6.gt) goto loc_82681C60;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_82681C60:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x82681C68;
	sub_8217F768(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9fc
	ctx.lr = 0x82681C74;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82681C78"))) PPC_WEAK_FUNC(sub_82681C78);
PPC_FUNC_IMPL(__imp__sub_82681C78) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,17352
	ctx.r10.s64 = r11.s64 + 17352;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e0430
	ctx.lr = 0x82681CA4;
	sub_824E0430(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82681cbc
	if (cr6.eq) goto loc_82681CBC;
	// bl 0x82130588
	ctx.lr = 0x82681CB8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82681CBC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82681CD4"))) PPC_WEAK_FUNC(sub_82681CD4);
PPC_FUNC_IMPL(__imp__sub_82681CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82681CD8"))) PPC_WEAK_FUNC(sub_82681CD8);
PPC_FUNC_IMPL(__imp__sub_82681CD8) {
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
	// bl 0x823d91e4
	ctx.lr = 0x82681CE0;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d0
	ctx.lr = 0x82681CE8;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// addi r4,r10,18112
	ctx.r4.s64 = ctx.r10.s64 + 18112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x82681D04;
	sub_821CA540(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x82681D0C;
	sub_82130528(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82681d20
	if (cr6.eq) goto loc_82681D20;
	// bl 0x82611298
	ctx.lr = 0x82681D1C;
	sub_82611298(ctx, base);
	// b 0x82681d24
	goto loc_82681D24;
loc_82681D20:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82681D24:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r11,r11,29892
	r11.s64 = r11.s64 + 29892;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r11,-5792
	r31.s64 = r11.s64 + -5792;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82681D54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r3,r8,18104
	ctx.r3.s64 = ctx.r8.s64 + 18104;
	// bl 0x8217d9f8
	ctx.lr = 0x82681D60;
	sub_8217D9F8(ctx, base);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,29900(r7)
	PPC_STORE_U32(ctx.r7.u32 + 29900, r11.u32);
	// bl 0x821c9a90
	ctx.lr = 0x82681D74;
	sub_821C9A90(ctx, base);
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r6,18068
	ctx.r4.s64 = ctx.r6.s64 + 18068;
	// bl 0x821ca540
	ctx.lr = 0x82681D84;
	sub_821CA540(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x82681D8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82681d9c
	if (cr6.eq) goto loc_82681D9C;
	// bl 0x82611298
	ctx.lr = 0x82681D98;
	sub_82611298(ctx, base);
	// b 0x82681da0
	goto loc_82681DA0;
loc_82681D9C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82681DA0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r11,r11,29896
	r11.s64 = r11.s64 + 29896;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82681DC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r3,r9,18048
	ctx.r3.s64 = ctx.r9.s64 + 18048;
	// bl 0x8217d9f8
	ctx.lr = 0x82681DD4;
	sub_8217D9F8(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,29904(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29904, r11.u32);
	// bl 0x821c9a90
	ctx.lr = 0x82681DE8;
	sub_821C9A90(ctx, base);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r31,r7,18032
	r31.s64 = ctx.r7.s64 + 18032;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24728);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82681E14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r29,-32112
	r29.s64 = -2104492032;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,29888(r29)
	PPC_STORE_U32(r29.u32 + 29888, ctx.r3.u32);
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
	ctx.lr = 0x82681E4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-24728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24728);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,18012
	ctx.r4.s64 = ctx.r10.s64 + 18012;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82681E70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r7,17988
	ctx.r4.s64 = ctx.r7.s64 + 17988;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,29908(r31)
	PPC_STORE_U32(r31.u32 + 29908, ctx.r3.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82681EAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,6744
	ctx.r3.s64 = ctx.r10.s64 + 6744;
	// bl 0x821881b8
	ctx.lr = 0x82681EB8;
	sub_821881B8(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r3,-32236(r9)
	PPC_STORE_U32(ctx.r9.u32 + -32236, ctx.r3.u32);
	// addi r3,r8,6728
	ctx.r3.s64 = ctx.r8.s64 + 6728;
	// bl 0x821881b8
	ctx.lr = 0x82681ECC;
	sub_821881B8(ctx, base);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r3,r6,6708
	ctx.r3.s64 = ctx.r6.s64 + 6708;
	// stw r11,-32232(r7)
	PPC_STORE_U32(ctx.r7.u32 + -32232, r11.u32);
	// bl 0x821881b8
	ctx.lr = 0x82681EE4;
	sub_821881B8(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-27840
	ctx.r4.s64 = ctx.r9.s64 + -27840;
	// stw r3,-32228(r10)
	PPC_STORE_U32(ctx.r10.u32 + -32228, ctx.r3.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82681F04;
	sub_8218A568(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stw r3,29860(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29860, ctx.r3.u32);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,17976
	ctx.r4.s64 = ctx.r7.s64 + 17976;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82681F24;
	sub_8218A568(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// stw r3,29844(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29844, ctx.r3.u32);
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,17960
	ctx.r4.s64 = ctx.r4.s64 + 17960;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82681F44;
	sub_8218A568(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,29620(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29620, ctx.r3.u32);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,17948
	ctx.r4.s64 = ctx.r9.s64 + 17948;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82681F64;
	sub_8218A568(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stw r3,29848(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29848, ctx.r3.u32);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,17932
	ctx.r4.s64 = ctx.r7.s64 + 17932;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82681F84;
	sub_8218A568(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// stw r3,29880(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29880, ctx.r3.u32);
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,17920
	ctx.r4.s64 = ctx.r4.s64 + 17920;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82681FA4;
	sub_8218A568(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,29868(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29868, ctx.r3.u32);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,17908
	ctx.r4.s64 = ctx.r9.s64 + 17908;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82681FC4;
	sub_8218A568(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stw r3,29840(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29840, ctx.r3.u32);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,17892
	ctx.r4.s64 = ctx.r7.s64 + 17892;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82681FE4;
	sub_8218A568(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// stw r3,29636(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29636, ctx.r3.u32);
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,17876
	ctx.r4.s64 = ctx.r4.s64 + 17876;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82682004;
	sub_8218A568(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,29832(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29832, ctx.r3.u32);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,17860
	ctx.r4.s64 = ctx.r9.s64 + 17860;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82682024;
	sub_8218A568(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stw r3,29628(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29628, ctx.r3.u32);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,17844
	ctx.r4.s64 = ctx.r7.s64 + 17844;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82682044;
	sub_8218A568(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// stw r3,29864(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29864, ctx.r3.u32);
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// lwz r11,29888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29888);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r4,17832
	r29.s64 = ctx.r4.s64 + 17832;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82682068;
	sub_8218A568(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,29856(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29856, ctx.r3.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,29908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29908);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82682084;
	sub_8218A568(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stw r3,29632(r9)
	PPC_STORE_U32(ctx.r9.u32 + 29632, ctx.r3.u32);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r3,r8,17796
	ctx.r3.s64 = ctx.r8.s64 + 17796;
	// bl 0x8217d9f8
	ctx.lr = 0x82682098;
	sub_8217D9F8(ctx, base);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// stw r3,29616(r7)
	PPC_STORE_U32(ctx.r7.u32 + 29616, ctx.r3.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// mr r31,r28
	r31.u64 = r28.u64;
	// addi r27,r11,29640
	r27.s64 = r11.s64 + 29640;
	// addi r26,r10,17772
	r26.s64 = ctx.r10.s64 + 17772;
	// addi r25,r9,-32056
	r25.s64 = ctx.r9.s64 + -32056;
	// addi r24,r8,17760
	r24.s64 = ctx.r8.s64 + 17760;
	// addi r23,r7,-32160
	r23.s64 = ctx.r7.s64 + -32160;
	// addi r29,r6,29736
	r29.s64 = ctx.r6.s64 + 29736;
loc_826820D4:
	// li r3,224
	ctx.r3.s64 = 224;
	// bl 0x82130528
	ctx.lr = 0x826820DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826820ec
	if (cr6.eq) goto loc_826820EC;
	// bl 0x826811d0
	ctx.lr = 0x826820E8;
	sub_826811D0(ctx, base);
	// b 0x826820f0
	goto loc_826820F0;
loc_826820EC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_826820F0:
	// stwx r3,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r3.u32);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r6,r31,r23
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r23.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// add r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x8268210C;
	sub_82137A08(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// bl 0x824e06e0
	ctx.lr = 0x82682118;
	sub_824E06E0(ctx, base);
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8268212C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r6,r31,r25
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r25.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x82682140;
	sub_82137A08(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8217d9f8
	ctx.lr = 0x82682148;
	sub_8217D9F8(ctx, base);
	// stwx r3,r31,r27
	PPC_STORE_U32(r31.u32 + r27.u32, ctx.r3.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r31,96
	cr6.compare<int32_t>(r31.s32, 96, xer);
	// blt cr6,0x826820d4
	if (cr6.lt) goto loc_826820D4;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r27,r11,29920
	r27.s64 = r11.s64 + 29920;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f29,-7864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7864);
	f29.f64 = double(temp.f32);
	// mr r29,r28
	r29.u64 = r28.u64;
	// addi r31,r27,8
	r31.s64 = r27.s64 + 8;
	// lfs f28,18204(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	f28.f64 = double(temp.f32);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
loc_82682188:
	// extsw r11,r29
	r11.s64 = r29.s32;
	// stfs f30,-8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// stfs f31,-4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -4, temp.u32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 * f29.f64));
	// fmuls f27,f11,f28
	f27.f64 = double(float(ctx.f11.f64 * f28.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbae8
	ctx.lr = 0x826821B8;
	sub_823DBAE8(ctx, base);
	// frsp f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x826821C4;
	sub_823DBBC8(ctx, base);
	// lfs f10,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// frsp f9,f1
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lfs f8,-8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f26
	ctx.f7.f64 = double(float(ctx.f10.f64 * f26.f64));
	// fmuls f6,f8,f26
	ctx.f6.f64 = double(float(ctx.f8.f64 * f26.f64));
	// addi r10,r27,520
	ctx.r10.s64 = r27.s64 + 520;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// fmadds f5,f8,f9,f7
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f7.f64));
	// stfs f5,-8(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// fmsubs f4,f10,f9,f6
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 - ctx.f6.f64));
	// stfs f4,0(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x82682188
	if (cr6.lt) goto loc_82682188;
	// lwz r3,-24728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24728);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r31,r11,17752
	r31.s64 = r11.s64 + 17752;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82682224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,29912(r30)
	PPC_STORE_U32(r30.u32 + 29912, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8268225C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,29912(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29912);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,17744
	ctx.r4.s64 = ctx.r10.s64 + 17744;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82682274;
	sub_8218A568(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r11,29912(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29912);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,17732
	ctx.r4.s64 = ctx.r8.s64 + 17732;
	// stw r3,29872(r9)
	PPC_STORE_U32(ctx.r9.u32 + 29872, ctx.r3.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82682294;
	sub_8218A568(ctx, base);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// stw r3,29876(r7)
	PPC_STORE_U32(ctx.r7.u32 + 29876, ctx.r3.u32);
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// lwz r11,29912(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29912);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,17724
	ctx.r4.s64 = ctx.r6.s64 + 17724;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x826822B4;
	sub_8218A568(ctx, base);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stw r3,29836(r5)
	PPC_STORE_U32(ctx.r5.u32 + 29836, ctx.r3.u32);
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// lwz r11,29912(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29912);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,17716
	ctx.r4.s64 = ctx.r4.s64 + 17716;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x826822D4;
	sub_8218A568(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,29624(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29624, ctx.r3.u32);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lwz r11,29912(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29912);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,17704
	ctx.r4.s64 = ctx.r9.s64 + 17704;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x826822F4;
	sub_8218B688(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// stw r3,29852(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29852, ctx.r3.u32);
	// li r11,1
	r11.s64 = 1;
	// stb r11,29884(r7)
	PPC_STORE_U8(ctx.r7.u32 + 29884, r11.u8);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba1c
	ctx.lr = 0x82682314;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82682318"))) PPC_WEAK_FUNC(sub_82682318);
PPC_FUNC_IMPL(__imp__sub_82682318) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82682320;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d4
	ctx.lr = 0x82682328;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// fmr f31,f3
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f3.f64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,-27692(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27692);
	// lfs f1,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82179778
	ctx.lr = 0x8268234C;
	sub_82179778(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// fdivs f29,f31,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(f31.f64 / ctx.f1.f64));
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r9,29736
	ctx.r7.s64 = ctx.r9.s64 + 29736;
	// li r3,6
	ctx.r3.s64 = 6;
	// lwzx r30,r8,r7
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82682368;
	sub_8217FED0(ctx, base);
	// cntlzw r6,r3
	ctx.r6.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// li r3,6
	ctx.r3.s64 = 6;
	// xori r26,r5,1
	r26.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8217f768
	ctx.lr = 0x82682380;
	sub_8217F768(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x8268238C;
	sub_8217F768(ctx, base);
	// lis r27,-32124
	r27.s64 = -2105278464;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-26876(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8268239C;
	sub_8217C088(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x826823A4;
	sub_8217D9A0(ctx, base);
	// li r4,33
	ctx.r4.s64 = 33;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217bb68
	ctx.lr = 0x826823B0;
	sub_8217BB68(ctx, base);
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r30,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 * f29.f64));
	// lfs f30,15360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15360);
	f30.f64 = double(temp.f32);
	// fmuls f9,f0,f30
	ctx.f9.f64 = double(float(f0.f64 * f30.f64));
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmuls f0,f10,f30
	f0.f64 = double(float(ctx.f10.f64 * f30.f64));
	// lfs f28,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f28.f64 = double(temp.f32);
	// fmuls f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 * f30.f64));
	// lfs f27,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	f27.f64 = double(temp.f32);
	// fmuls f12,f12,f30
	ctx.f12.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f5,f28
	ctx.f5.f64 = f28.f64;
	// fctiwz f11,f9
	ctx.f11.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// fctiwz f10,f0
	ctx.f10.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.f10.u64);
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fctiwz f9,f13
	ctx.f9.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.f9.u64);
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fctiwz f0,f12
	f0.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// rlwimi r4,r3,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwimi r11,r10,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r11,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// bl 0x8217bc28
	ctx.lr = 0x82682480;
	sub_8217BC28(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r28,r30,144
	r28.s64 = r30.s64 + 144;
	// addi r29,r11,29920
	r29.s64 = r11.s64 + 29920;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
loc_82682490:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	f0.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f3,f13,f0
	ctx.f3.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f2,f12,f27
	ctx.f2.f64 = double(float(ctx.f12.f64 + f27.f64));
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// lfs f9,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f9.f64 = double(temp.f32);
	// fmr f5,f28
	ctx.f5.f64 = f28.f64;
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmuls f10,f10,f30
	ctx.f10.f64 = double(float(ctx.f10.f64 * f30.f64));
	// fctiwz f0,f11
	f0.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// lwz r7,116(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fmuls f12,f9,f29
	ctx.f12.f64 = double(float(ctx.f9.f64 * f29.f64));
	// fmuls f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 * f30.f64));
	// fctiwz f10,f10
	ctx.f10.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.f10.u64);
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fmuls f9,f12,f30
	ctx.f9.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fctiwz f0,f11
	f0.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// lwz r6,116(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fctiwz f13,f9
	ctx.f13.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f13,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rlwimi r6,r5,8,16,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r6,16
	ctx.r4.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwimi r7,r4,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r7,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// bl 0x8217bc28
	ctx.lr = 0x8268254C;
	sub_8217BC28(ctx, base);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r3,r29,516
	ctx.r3.s64 = r29.s64 + 516;
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x82682490
	if (cr6.lt) goto loc_82682490;
	// bl 0x8217bc98
	ctx.lr = 0x82682560;
	sub_8217BC98(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,-26876(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -26876);
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// bl 0x8217c088
	ctx.lr = 0x82682570;
	sub_8217C088(ctx, base);
	// clrlwi r4,r26,24
	ctx.r4.u64 = r26.u32 & 0xFF;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x8268257C;
	sub_8217F768(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba20
	ctx.lr = 0x82682588;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8268258C"))) PPC_WEAK_FUNC(sub_8268258C);
PPC_FUNC_IMPL(__imp__sub_8268258C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82682590"))) PPC_WEAK_FUNC(sub_82682590);
PPC_FUNC_IMPL(__imp__sub_82682590) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82682598;
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// bl 0x8217c088
	ctx.lr = 0x826825D0;
	sub_8217C088(ctx, base);
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// lfs f10,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f7,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f7.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f4,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f4.f64 = double(temp.f32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f9,116(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f6,120(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// lfs f3,112(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,12196(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12196);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// lfs f12,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f1,f8,f8
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f10,f5,f5,f1
	ctx.f10.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f1.f64));
	// fmadds f9,f2,f2,f10
	ctx.f9.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fnmsubs f7,f8,f13,f0
	ctx.f7.f64 = double(float(-(ctx.f8.f64 * ctx.f13.f64 - f0.f64)));
	// fmuls f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fsel f5,f6,f6,f11
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : ctx.f11.f64;
	// fsubs f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsel f29,f4,f0,f5
	f29.f64 = ctx.f4.f64 >= 0.0 ? f0.f64 : ctx.f5.f64;
	// blt cr6,0x826826c4
	if (cr6.lt) goto loc_826826C4;
	// cmpwi cr6,r30,24
	cr6.compare<int32_t>(r30.s32, 24, xer);
	// bge cr6,0x826826c4
	if (!cr6.lt) goto loc_826826C4;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,29736
	ctx.r8.s64 = ctx.r10.s64 + 29736;
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x826826c4
	if (cr6.eq) goto loc_826826C4;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f3,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217c328
	ctx.lr = 0x82682680;
	sub_8217C328(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826826c4
	if (cr6.eq) goto loc_826826C4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f29.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82681760
	ctx.lr = 0x826826A0;
	sub_82681760(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826826c4
	if (cr6.eq) goto loc_826826C4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f29.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82682318
	ctx.lr = 0x826826C4;
	sub_82682318(ctx, base);
loc_826826C4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826826D8"))) PPC_WEAK_FUNC(sub_826826D8);
PPC_FUNC_IMPL(__imp__sub_826826D8) {
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
	ctx.lr = 0x826826E0;
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
	// rlwinm r3,r11,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x826826F8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82682724
	if (!cr6.gt) goto loc_82682724;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_82682708:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82682718
	if (cr6.eq) goto loc_82682718;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c48
	ctx.lr = 0x82682718;
	sub_82683C48(ctx, base);
loc_82682718:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,160
	r31.s64 = r31.s64 + 160;
	// bne 0x82682708
	if (!cr0.eq) goto loc_82682708;
loc_82682724:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82682730"))) PPC_WEAK_FUNC(sub_82682730);
PPC_FUNC_IMPL(__imp__sub_82682730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82682754"))) PPC_WEAK_FUNC(sub_82682754);
PPC_FUNC_IMPL(__imp__sub_82682754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82682758"))) PPC_WEAK_FUNC(sub_82682758);
PPC_FUNC_IMPL(__imp__sub_82682758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,160
	ctx.r10.s64 = 160;
	// subf r9,r11,r4
	ctx.r9.s64 = ctx.r4.s64 - r11.s64;
	// divw r3,r9,r10
	ctx.r3.s32 = ctx.r9.s32 / ctx.r10.s32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8268276C"))) PPC_WEAK_FUNC(sub_8268276C);
PPC_FUNC_IMPL(__imp__sub_8268276C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82682770"))) PPC_WEAK_FUNC(sub_82682770);
PPC_FUNC_IMPL(__imp__sub_82682770) {
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
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// li r11,1
	r11.s64 = 1;
	// addis r30,r10,3
	r30.s64 = ctx.r10.s64 + 196608;
	// addi r30,r30,-21024
	r30.s64 = r30.s64 + -21024;
	// lbz r9,1(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826827b4
	if (!cr6.eq) goto loc_826827B4;
	// li r11,0
	r11.s64 = 0;
loc_826827B4:
	// stb r11,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r11.u8);
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826827d8
	if (cr6.eq) goto loc_826827D8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x826827D8;
	sub_82683C10(ctx, base);
loc_826827D8:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826827f8
	if (cr6.eq) goto loc_826827F8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x826827F8;
	sub_82683C10(ctx, base);
loc_826827F8:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82682818
	if (cr6.eq) goto loc_82682818;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x82682818;
	sub_82683C10(ctx, base);
loc_82682818:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82682838
	if (cr6.eq) goto loc_82682838;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x82682838;
	sub_82683C10(ctx, base);
loc_82682838:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82682858
	if (cr6.eq) goto loc_82682858;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x82682858;
	sub_82683C10(ctx, base);
loc_82682858:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82682878
	if (cr6.eq) goto loc_82682878;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x82682878;
	sub_82683C10(ctx, base);
loc_82682878:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82682898
	if (cr6.eq) goto loc_82682898;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x82682898;
	sub_82683C10(ctx, base);
loc_82682898:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826828b8
	if (cr6.eq) goto loc_826828B8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x826828B8;
	sub_82683C10(ctx, base);
loc_826828B8:
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826828d8
	if (cr6.eq) goto loc_826828D8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x826828D8;
	sub_82683C10(ctx, base);
loc_826828D8:
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826828f8
	if (cr6.eq) goto loc_826828F8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x826828F8;
	sub_82683C10(ctx, base);
loc_826828F8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82682910"))) PPC_WEAK_FUNC(sub_82682910);
PPC_FUNC_IMPL(__imp__sub_82682910) {
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
	// li r11,0
	r11.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// beq cr6,0x8268294c
	if (cr6.eq) goto loc_8268294C;
	// bl 0x826826d8
	ctx.lr = 0x82682948;
	sub_826826D8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8268294C:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82682970"))) PPC_WEAK_FUNC(sub_82682970);
PPC_FUNC_IMPL(__imp__sub_82682970) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823d91c8
	ctx.lr = 0x82682978;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823db9b8
	ctx.lr = 0x82682980;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// li r20,3
	r20.s64 = 3;
	// lfs f0,32668(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32668);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	cr6.compare(f29.f64, f0.f64);
	// blt cr6,0x826829ac
	if (cr6.lt) goto loc_826829AC;
	// li r20,5
	r20.s64 = 5;
	// b 0x826829c0
	goto loc_826829C0;
loc_826829AC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	cr6.compare(f29.f64, f0.f64);
	// blt cr6,0x826829c0
	if (cr6.lt) goto loc_826829C0;
	// li r20,4
	r20.s64 = 4;
loc_826829C0:
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// mr r26,r30
	r26.u64 = r30.u64;
	// ble cr6,0x82682be8
	if (!cr6.gt) goto loc_82682BE8;
	// extsw r11,r20
	r11.s64 = r20.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f22,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f22.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f23,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	f23.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// frsp f25,f13
	f25.f64 = double(float(ctx.f13.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f24,-30580(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30580);
	f24.f64 = double(temp.f32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lfs f26,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	f26.f64 = double(temp.f32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f30,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	f30.f64 = double(temp.f32);
	// lfs f27,27644(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27644);
	f27.f64 = double(temp.f32);
	// ori r27,r3,65535
	r27.u64 = ctx.r3.u64 | 65535;
	// lfs f28,30284(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 30284);
	f28.f64 = double(temp.f32);
	// li r28,-1
	r28.s64 = -1;
	// lfs f31,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r22,32
	r22.s64 = 32;
	// li r23,1
	r23.s64 = 1;
	// lis r24,-32114
	r24.s64 = -2104623104;
	// addi r25,r11,2256
	r25.s64 = r11.s64 + 2256;
loc_82682A44:
	// extsw r11,r26
	r11.s64 = r26.s32;
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f12,f25
	ctx.f11.f64 = double(float(ctx.f12.f64 / f25.f64));
	// fmuls f10,f11,f28
	ctx.f10.f64 = double(float(ctx.f11.f64 * f28.f64));
	// fmuls f21,f10,f27
	f21.f64 = double(float(ctx.f10.f64 * f27.f64));
	// fmr f1,f21
	ctx.f1.f64 = f21.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82682A70;
	sub_823DBAE8(ctx, base);
	// frsp f20,f1
	ctx.fpscr.disableFlushMode();
	f20.f64 = double(float(ctx.f1.f64));
	// fmr f1,f21
	ctx.f1.f64 = f21.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82682A7C;
	sub_823DBBC8(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmuls f8,f20,f29
	ctx.f8.f64 = double(float(f20.f64 * f29.f64));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// fmuls f7,f20,f31
	ctx.f7.f64 = double(float(f20.f64 * f31.f64));
	// lvx128 v62,r0,r21
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,144
	r31.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// addi r19,r1,192
	r19.s64 = ctx.r1.s64 + 192;
	// lwz r3,-23452(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -23452);
	// addi r18,r1,208
	r18.s64 = ctx.r1.s64 + 208;
	// addi r17,r1,256
	r17.s64 = ctx.r1.s64 + 256;
	// addi r16,r1,272
	r16.s64 = ctx.r1.s64 + 272;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,1
	ctx.r10.s64 = 1;
	// fmsubs f6,f9,f31,f8
	ctx.f6.f64 = double(float(ctx.f9.f64 * f31.f64 - ctx.f8.f64));
	// stfs f6,120(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmadds f5,f9,f29,f7
	ctx.f5.f64 = double(float(ctx.f9.f64 * f29.f64 + ctx.f7.f64));
	// stfs f5,112(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,7
	ctx.r9.s64 = 7;
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// fadds f3,f13,f30
	ctx.f3.f64 = double(float(ctx.f13.f64 + f30.f64));
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fsubs f4,f13,f26
	ctx.f4.f64 = double(float(ctx.f13.f64 - f26.f64));
	// stfs f3,148(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// lvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,224(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stvx128 v63,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f4,132(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stvx128 v63,r0,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r27,236(r1)
	PPC_STORE_U16(ctx.r1.u32 + 236, r27.u16);
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r30,238(r1)
	PPC_STORE_U16(ctx.r1.u32 + 238, r30.u16);
	// stvx128 v59,r0,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,240(r1)
	PPC_STORE_U8(ctx.r1.u32 + 240, r30.u8);
	// sth r30,242(r1)
	PPC_STORE_U16(ctx.r1.u32 + 242, r30.u16);
	// stvx128 v58,r0,r17
	simde_mm_store_si128((simde__m128i*)(base + ((r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r30.u32);
	// bl 0x82574418
	ctx.lr = 0x82682B60;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82682bdc
	if (cr6.eq) goto loc_82682BDC;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmr f1,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f24.f64;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r7,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r7.u16);
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v57,r31,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826836c0
	ctx.lr = 0x82682BA0;
	sub_826836C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f23
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f23.f64;
	// bl 0x826836b0
	ctx.lr = 0x82682BAC;
	sub_826836B0(ctx, base);
	// stfs f22,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825ae378
	ctx.lr = 0x82682BBC;
	sub_825AE378(ctx, base);
	// stb r23,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r23.u8);
	// stb r30,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r30.u8);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x82683878
	ctx.lr = 0x82682BD4;
	sub_82683878(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82682770
	ctx.lr = 0x82682BDC;
	sub_82682770(ctx, base);
loc_82682BDC:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpw cr6,r26,r20
	cr6.compare<int32_t>(r26.s32, r20.s32, xer);
	// blt cr6,0x82682a44
	if (cr6.lt) goto loc_82682A44;
loc_82682BE8:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823dba04
	ctx.lr = 0x82682BF4;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82682BF8"))) PPC_WEAK_FUNC(sub_82682BF8);
PPC_FUNC_IMPL(__imp__sub_82682BF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-848(r1)
	ea = -848 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r3.u32);
	// stw r4,876(r1)
	PPC_STORE_U32(ctx.r1.u32 + 876, ctx.r4.u32);
	// stfs f1,884(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 884, temp.u32);
	// stw r6,892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 892, ctx.r6.u32);
	// lfs f0,884(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 884);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lwz r10,876(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 876);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,892(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 892);
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,416
	ctx.r5.s64 = ctx.r1.s64 + 416;
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,416
	r11.s64 = ctx.r1.s64 + 416;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,400
	ctx.r10.s64 = ctx.r1.s64 + 400;
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,384
	ctx.r8.s64 = ctx.r1.s64 + 384;
	// lvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v55,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r6,r1,432
	ctx.r6.s64 = ctx.r1.s64 + 432;
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// addi r4,r5,2384
	ctx.r4.s64 = ctx.r5.s64 + 2384;
	// lvx128 v54,r0,r4
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// stvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,464
	r11.s64 = ctx.r1.s64 + 464;
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v51,v52,v53
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// addi r9,r1,448
	ctx.r9.s64 = ctx.r1.s64 + 448;
	// stvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,432
	ctx.r8.s64 = ctx.r1.s64 + 432;
	// lvx128 v2,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,448
	ctx.r7.s64 = ctx.r1.s64 + 448;
	// lvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215dff0
	ctx.lr = 0x82682CEC;
	sub_8215DFF0(ctx, base);
	// cntlzw r6,r3
	ctx.r6.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82682d94
	if (!cr6.eq) goto loc_82682D94;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lvx128 v49,r0,r9
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v48,v49,v50
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// addi r8,r1,512
	ctx.r8.s64 = ctx.r1.s64 + 512;
	// stvx128 v48,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,512
	ctx.r7.s64 = ctx.r1.s64 + 512;
	// lvx128 v47,r0,r7
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,560
	ctx.r6.s64 = ctx.r1.s64 + 560;
	// stvx128 v47,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,560
	ctx.r5.s64 = ctx.r1.s64 + 560;
	// lvx128 v46,r0,r5
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v45,v46
	simde_mm_store_ps(v45.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v46.f32))));
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// stvx128 v45,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// lvx128 v44,r0,r3
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,576
	r11.s64 = ctx.r1.s64 + 576;
	// stvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,576
	ctx.r10.s64 = ctx.r1.s64 + 576;
	// lvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lvx128 v42,r0,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v41,v42,v43
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v43.f32)));
	// addi r8,r1,544
	ctx.r8.s64 = ctx.r1.s64 + 544;
	// stvx128 v41,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,544
	ctx.r7.s64 = ctx.r1.s64 + 544;
	// lvx128 v40,r0,r7
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stvx128 v40,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f1,26468(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 26468);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8216c890
	ctx.lr = 0x82682D94;
	sub_8216C890(ctx, base);
loc_82682D94:
	// lfs f11,884(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 884);
	ctx.f11.f64 = double(temp.f32);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f10,172(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f9,884(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 884);
	ctx.f9.f64 = double(temp.f32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f8,-3168(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -3168);
	ctx.f8.f64 = double(temp.f32);
	// fcmpu cr6,f9,f8
	cr6.compare(ctx.f9.f64, ctx.f8.f64);
	// blt cr6,0x82682dc0
	if (cr6.lt) goto loc_82682DC0;
	// li r3,5
	ctx.r3.s64 = 5;
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// b 0x82682e34
	goto loc_82682E34;
loc_82682DC0:
	// lfs f7,884(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 884);
	ctx.f7.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f6,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f6.f64 = double(temp.f32);
	// fcmpu cr6,f7,f6
	cr6.compare(ctx.f7.f64, ctx.f6.f64);
	// blt cr6,0x82682de0
	if (cr6.lt) goto loc_82682DE0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// b 0x82682e34
	goto loc_82682E34;
loc_82682DE0:
	// lfs f5,884(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 884);
	ctx.f5.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f4,-15944(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -15944);
	ctx.f4.f64 = double(temp.f32);
	// fcmpu cr6,f5,f4
	cr6.compare(ctx.f5.f64, ctx.f4.f64);
	// blt cr6,0x82682e00
	if (cr6.lt) goto loc_82682E00;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r8,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// b 0x82682e34
	goto loc_82682E34;
loc_82682E00:
	// lfs f3,884(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 884);
	ctx.f3.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f2,30712(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f3,f2
	cr6.compare(ctx.f3.f64, ctx.f2.f64);
	// blt cr6,0x82682e20
	if (cr6.lt) goto loc_82682E20;
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r6,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r6.u32);
	// b 0x82682e34
	goto loc_82682E34;
loc_82682E20:
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f1,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,172(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_82682E34:
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ble cr6,0x82682e6c
	if (!cr6.gt) goto loc_82682E6C;
	// lwz r11,164(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,808(r1)
	PPC_STORE_U64(ctx.r1.u32 + 808, ctx.r9.u64);
	// lfd f0,808(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 808);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// stfs f10,816(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 816, temp.u32);
	// b 0x82682e78
	goto loc_82682E78;
loc_82682E6C:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f9,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,816(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 816, temp.u32);
loc_82682E78:
	// lfs f8,816(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 816);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,168(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r7,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r7.u32);
	// b 0x82682e98
	goto loc_82682E98;
loc_82682E8C:
	// lwz r6,176(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// addi r5,r6,1
	ctx.r5.s64 = ctx.r6.s64 + 1;
	// stw r5,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r5.u32);
loc_82682E98:
	// lwz r4,176(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// bge cr6,0x82683088
	if (!cr6.lt) goto loc_82683088;
	// lwz r11,876(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 876);
	// lvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stvx128 v39,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lvx128 v38,r0,r9
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,704
	ctx.r8.s64 = ctx.r1.s64 + 704;
	// stvx128 v38,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v37,r0,r7
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,688
	ctx.r6.s64 = ctx.r1.s64 + 688;
	// stvx128 v37,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82148928
	ctx.lr = 0x82682EE0;
	sub_82148928(ctx, base);
	// addi r5,r1,608
	ctx.r5.s64 = ctx.r1.s64 + 608;
	// stvx128 v1,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// lvx128 v36,r0,r4
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// stvx128 v36,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,688
	r11.s64 = ctx.r1.s64 + 688;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,640
	ctx.r10.s64 = ctx.r1.s64 + 640;
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,704
	ctx.r9.s64 = ctx.r1.s64 + 704;
	// lvx128 v12,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r8,r1,624
	ctx.r8.s64 = ctx.r1.s64 + 624;
	// stvx128 v11,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,624
	ctx.r7.s64 = ctx.r1.s64 + 624;
	// lvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,352
	ctx.r6.s64 = ctx.r1.s64 + 352;
	// stvx128 v35,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,360(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f7,356(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	ctx.f7.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f6,3732(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	ctx.f6.f64 = double(temp.f32);
	// fadds f2,f7,f6
	ctx.f2.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// lfs f1,352(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x8216c880
	ctx.lr = 0x82682F4C;
	sub_8216C880(ctx, base);
	// lfs f3,360(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f5,356(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	ctx.f5.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f4,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f2,f5,f4
	ctx.f2.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// lfs f1,352(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x8216c880
	ctx.lr = 0x82682F6C;
	sub_8216C880(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821f6c78
	ctx.lr = 0x82682F74;
	sub_821F6C78(ctx, base);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x82130000
	ctx.lr = 0x82682F7C;
	sub_82130000(ctx, base);
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x822502f8
	ctx.lr = 0x82682F8C;
	sub_822502F8(ctx, base);
	// addi r31,r1,192
	r31.s64 = ctx.r1.s64 + 192;
	// addi r30,r1,304
	r30.s64 = ctx.r1.s64 + 304;
	// bl 0x82203378
	ctx.lr = 0x82682F98;
	sub_82203378(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r9,7
	ctx.r9.s64 = 7;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82574418
	ctx.lr = 0x82682FC0;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82683074
	if (cr6.eq) goto loc_82683074;
	// lwz r3,868(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 868);
	// bl 0x82682730
	ctx.lr = 0x82682FD0;
	sub_82682730(ctx, base);
	// stw r3,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r3.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821f6828
	ctx.lr = 0x82682FDC;
	sub_821F6828(ctx, base);
	// stw r3,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r3.u32);
	// lwz r10,368(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// addi r9,r10,32
	ctx.r9.s64 = ctx.r10.s64 + 32;
	// stw r9,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, ctx.r9.u32);
	// lwz r8,804(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 804);
	// lvx128 v34,r0,r8
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,800(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 800);
	// stvx128 v34,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f1,-30580(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -30580);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,368(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// bl 0x826836c0
	ctx.lr = 0x8268300C;
	sub_826836C0(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f1,12428(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,368(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// bl 0x826836b0
	ctx.lr = 0x8268301C;
	sub_826836B0(ctx, base);
	// lwz r4,368(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f3,27640(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 27640);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,112(r4)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r4.u32 + 112, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,368(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// bl 0x825ae378
	ctx.lr = 0x82683038;
	sub_825AE378(ctx, base);
	// lwz r11,368(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r10.u8);
	// lwz r9,368(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,21(r9)
	PPC_STORE_U8(ctx.r9.u32 + 21, ctx.r8.u8);
	// lwz r7,368(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r6,23(r7)
	PPC_STORE_U8(ctx.r7.u32 + 23, ctx.r6.u8);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f1,3732(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,368(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// bl 0x82683878
	ctx.lr = 0x8268306C;
	sub_82683878(ctx, base);
	// lwz r3,368(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// bl 0x82682770
	ctx.lr = 0x82683074;
	sub_82682770(ctx, base);
loc_82683074:
	// lfs f2,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f1.f64 = double(temp.f32);
	// fadds f0,f2,f1
	f0.f64 = double(float(ctx.f2.f64 + ctx.f1.f64));
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// b 0x82682e8c
	goto loc_82682E8C;
loc_82683088:
	// addi r1,r1,848
	ctx.r1.s64 = ctx.r1.s64 + 848;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826830A0"))) PPC_WEAK_FUNC(sub_826830A0);
PPC_FUNC_IMPL(__imp__sub_826830A0) {
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
	ctx.lr = 0x826830A8;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9b8
	ctx.lr = 0x826830B0;
	// stwu r1,-576(r1)
	ea = -576 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// stw r26,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, r26.u32);
	// stb r25,607(r1)
	PPC_STORE_U8(ctx.r1.u32 + 607, r25.u8);
	// bl 0x82640ad8
	ctx.lr = 0x826830C8;
	sub_82640AD8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// rlwinm r11,r23,2,0,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r23,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r23.u32);
	// add. r31,r23,r11
	r31.u64 = r23.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x826830f0
	if (!cr0.eq) goto loc_826830F0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba04
	ctx.lr = 0x826830EC;
	// b 0x823d9210
	return;
loc_826830F0:
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826830F8;
	sub_82130528(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82683114
	if (cr6.eq) goto loc_82683114;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82682910
	ctx.lr = 0x8268310C;
	sub_82682910(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// b 0x82683118
	goto loc_82683118;
loc_82683114:
	// mr r22,r29
	r22.u64 = r29.u64;
loc_82683118:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r16,r29
	r16.u64 = r29.u64;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// ble cr6,0x82683638
	if (!cr6.gt) goto loc_82683638;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f26,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	f26.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f27,-30580(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30580);
	f27.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f30,-31376(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31376);
	f30.f64 = double(temp.f32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lfs f25,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f25.f64 = double(temp.f32);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lfs f28,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f28.f64 = double(temp.f32);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lfs f24,30712(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 30712);
	f24.f64 = double(temp.f32);
	// lfs f22,32688(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32688);
	f22.f64 = double(temp.f32);
	// addi r5,r23,-1
	ctx.r5.s64 = r23.s64 + -1;
	// lfs f23,27640(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	f23.f64 = double(temp.f32);
	// mr r27,r29
	r27.u64 = r29.u64;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lfd f29,3456(r3)
	f29.u64 = PPC_LOAD_U64(ctx.r3.u32 + 3456);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// stw r5,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r30,r7,2240
	r30.s64 = ctx.r7.s64 + 2240;
	// addi r28,r6,2528
	r28.s64 = ctx.r6.s64 + 2528;
	// ori r19,r4,65535
	r19.u64 = ctx.r4.u64 | 65535;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// li r20,-1
	r20.s64 = -1;
	// stw r28,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r28.u32);
	// lis r17,-32114
	r17.s64 = -2104623104;
	// addi r21,r11,18872
	r21.s64 = r11.s64 + 18872;
	// addi r18,r10,2256
	r18.s64 = ctx.r10.s64 + 2256;
	// addi r15,r9,-31664
	r15.s64 = ctx.r9.s64 + -31664;
	// addi r14,r8,-31648
	r14.s64 = ctx.r8.s64 + -31648;
	// b 0x826831e0
	goto loc_826831E0;
loc_826831D8:
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
loc_826831E0:
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmpw cr6,r16,r5
	cr6.compare<int32_t>(r16.s32, ctx.r5.s32, xer);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r24,r11,-368
	r24.s64 = r11.s64 + -368;
	// beq cr6,0x826831f8
	if (cr6.eq) goto loc_826831F8;
	// mr r24,r11
	r24.u64 = r11.u64;
loc_826831F8:
	// lbz r10,330(r24)
	ctx.r10.u64 = PPC_LOAD_U8(r24.u32 + 330);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r10.u32);
	// beq cr6,0x8268331c
	if (cr6.eq) goto loc_8268331C;
	// lfs f0,80(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 80);
	f0.f64 = double(temp.f32);
	// addi r11,r24,80
	r11.s64 = r24.s64 + 80;
	// lfs f13,64(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r24,64
	ctx.r10.s64 = r24.s64 + 64;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,72(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 72);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,88(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,68(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 68);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,84(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 84);
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
	// fcmpu cr6,f0,f23
	cr6.compare(f0.f64, f23.f64);
	// blt cr6,0x82683250
	if (cr6.lt) goto loc_82683250;
	// fsubs f0,f0,f23
	f0.f64 = double(float(f0.f64 - f23.f64));
loc_82683250:
	// fmuls f0,f0,f22
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f22.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.f13.u64);
	// lwz r31,148(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// bge cr6,0x82683270
	if (!cr6.lt) goto loc_82683270;
	// li r31,1
	r31.s64 = 1;
	// b 0x8268327c
	goto loc_8268327C;
loc_82683270:
	// cmpwi cr6,r31,5
	cr6.compare<int32_t>(r31.s32, 5, xer);
	// ble cr6,0x8268327c
	if (!cr6.gt) goto loc_8268327C;
	// li r31,5
	r31.s64 = 5;
loc_8268327C:
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dbae8
	ctx.lr = 0x82683298;
	sub_823DBAE8(ctx, base);
	// frsp f21,f1
	ctx.fpscr.disableFlushMode();
	f21.f64 = double(float(ctx.f1.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x826832A4;
	sub_823DBBC8(ctx, base);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// frsp f12,f1
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f21,f0
	ctx.f11.f64 = double(float(f21.f64 * f0.f64));
	// fmuls f10,f21,f13
	ctx.f10.f64 = double(float(f21.f64 * ctx.f13.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v60,r0,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r14
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r15
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmsubs f9,f12,f13,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 - ctx.f11.f64));
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmadds f8,f12,f0,f10
	ctx.f8.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f10.f64));
	// stfs f8,112(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v58,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v57,v58
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vor128 v12,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vcmpeqfp128 v11,v57,v60
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vor128 v10,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v59,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v56,v63,v6
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826833e4
	goto loc_826833E4;
loc_8268331C:
	// lfs f0,168(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 168);
	f0.f64 = double(temp.f32);
	// fsubs f0,f0,f24
	f0.f64 = double(float(f0.f64 - f24.f64));
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// blt cr6,0x82683330
	if (cr6.lt) goto loc_82683330;
	// fsubs f0,f0,f24
	f0.f64 = double(float(f0.f64 - f24.f64));
loc_82683330:
	// fmuls f0,f0,f22
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f22.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.f13.u64);
	// lwz r31,148(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// bge cr6,0x82683350
	if (!cr6.lt) goto loc_82683350;
	// li r31,1
	r31.s64 = 1;
	// b 0x8268335c
	goto loc_8268335C;
loc_82683350:
	// cmpwi cr6,r31,5
	cr6.compare<int32_t>(r31.s32, 5, xer);
	// ble cr6,0x8268335c
	if (!cr6.gt) goto loc_8268335C;
	// li r31,5
	r31.s64 = 5;
loc_8268335C:
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826833e4
	if (cr6.eq) goto loc_826833E4;
	// cmpw cr6,r16,r5
	cr6.compare<int32_t>(r16.s32, ctx.r5.s32, xer);
	// bne cr6,0x82683378
	if (!cr6.eq) goto loc_82683378;
	// addi r11,r11,-368
	r11.s64 = r11.s64 + -368;
	// b 0x8268337c
	goto loc_8268337C;
loc_82683378:
	// addi r11,r11,368
	r11.s64 = r11.s64 + 368;
loc_8268337C:
	// li r10,64
	ctx.r10.s64 = 64;
	// lvx128 v55,r0,r28
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v54,r0,r14
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v13,r0,r15
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r24,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r11,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v51,v52,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v50,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v49,v50
	simde_mm_store_ps(v49.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v50.f32))));
	// vor128 v12,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vcmpeqfp128 v11,v49,v55
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v55.f32)));
	// vor128 v10,v49,v49
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v54,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v48,v63,v6
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v48,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826833E4:
	// clrlwi r11,r31,31
	r11.u64 = r31.u32 & 0x1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82683400
	if (!cr6.eq) goto loc_82683400;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82683400
	if (cr6.eq) goto loc_82683400;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82683400:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82683624
	if (!cr6.gt) goto loc_82683624;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f20,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f20.f64 = double(temp.f32);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f21,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f21.f64 = double(temp.f32);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// add r9,r31,r10
	ctx.r9.u64 = r31.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r21,-104
	r11.s64 = r21.s64 + -104;
	// addi r9,r21,4
	ctx.r9.s64 = r21.s64 + 4;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r26,r24,112
	r26.s64 = r24.s64 + 112;
	// clrlwi r25,r25,24
	r25.u64 = r25.u32 & 0xFF;
	// addi r27,r11,-20
	r27.s64 = r11.s64 + -20;
	// addi r28,r10,-40
	r28.s64 = ctx.r10.s64 + -40;
	// mr r23,r31
	r23.u64 = r31.u64;
loc_8268344C:
	// lhz r11,4(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 4);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// lwz r9,0(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// sth r8,4(r22)
	PPC_STORE_U16(r22.u32 + 4, ctx.r8.u16);
	// lvx128 v47,r0,r26
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// stvx128 v47,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x826834b0
	if (!cr6.eq) goto loc_826834B0;
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826834b0
	if (!cr6.eq) goto loc_826834B0;
	// lfs f0,-4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f30,f13
	ctx.f12.f64 = double(float(f0.f64 * f30.f64 + ctx.f13.f64));
	// lfs f11,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f10,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f10,f30,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * f30.f64 + ctx.f11.f64));
	// stfs f9,40(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// b 0x826834d8
	goto loc_826834D8;
loc_826834B0:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f21
	ctx.f13.f64 = double(float(f0.f64 * f21.f64));
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f13,f30,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 * f30.f64 + ctx.f12.f64));
	// stfs f10,0(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f9,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f20
	ctx.f8.f64 = double(float(ctx.f9.f64 * f20.f64));
	// fnmsubs f7,f8,f30,f11
	ctx.f7.f64 = double(float(-(ctx.f8.f64 * f30.f64 - ctx.f11.f64)));
	// stfs f7,40(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
loc_826834D8:
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lfs f0,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// lfs f11,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// fadds f12,f0,f28
	ctx.f12.f64 = double(float(f0.f64 + f28.f64));
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fsubs f10,f0,f28
	ctx.f10.f64 = double(float(f0.f64 - f28.f64));
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f10,180(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// stfs f11,184(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stw r29,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r29.u32);
	// lvx128 v63,r0,r18
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// lvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,1
	ctx.r10.s64 = 1;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,7
	ctx.r9.s64 = 7;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r8,r20
	ctx.r8.u64 = r20.u64;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// lwz r3,-23452(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + -23452);
	// stfs f31,256(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// sth r19,268(r1)
	PPC_STORE_U16(ctx.r1.u32 + 268, r19.u16);
	// stfs f31,260(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// sth r29,270(r1)
	PPC_STORE_U16(ctx.r1.u32 + 270, r29.u16);
	// stb r29,272(r1)
	PPC_STORE_U8(ctx.r1.u32 + 272, r29.u8);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// sth r29,274(r1)
	PPC_STORE_U16(ctx.r1.u32 + 274, r29.u16);
	// stw r29,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r29.u32);
	// lvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// stvx128 v45,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// stvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x82683588;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826835fc
	if (cr6.eq) goto loc_826835FC;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826836c0
	ctx.lr = 0x826835A8;
	sub_826836C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f26
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f26.f64;
	// bl 0x826836b0
	ctx.lr = 0x826835B4;
	sub_826836B0(ctx, base);
	// lfs f0,176(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 176);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ae378
	ctx.lr = 0x826835C8;
	sub_825AE378(ctx, base);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r29,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r29.u8);
	// subf r8,r16,r10
	ctx.r8.s64 = ctx.r10.s64 - r16.s64;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// stb r9,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r6,21(r31)
	PPC_STORE_U8(r31.u32 + 21, ctx.r6.u8);
	// bl 0x82683878
	ctx.lr = 0x826835F4;
	sub_82683878(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82682770
	ctx.lr = 0x826835FC;
	sub_82682770(ctx, base);
loc_826835FC:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x8268344c
	if (!cr0.eq) goto loc_8268344C;
	// lwz r23,136(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r28,156(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r30,132(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r26,596(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 596);
	// lbz r25,607(r1)
	r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 607);
loc_82683624:
	// addi r16,r16,1
	r16.s64 = r16.s64 + 1;
	// addi r11,r27,368
	r11.s64 = r27.s64 + 368;
	// cmpw cr6,r16,r23
	cr6.compare<int32_t>(r16.s32, r23.s32, xer);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// blt cr6,0x826831d8
	if (cr6.lt) goto loc_826831D8;
loc_82683638:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba04
	ctx.lr = 0x82683648;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8268364C"))) PPC_WEAK_FUNC(sub_8268364C);
PPC_FUNC_IMPL(__imp__sub_8268364C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683650"))) PPC_WEAK_FUNC(sub_82683650);
PPC_FUNC_IMPL(__imp__sub_82683650) {
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
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add. r31,r3,r11
	r31.u64 = ctx.r3.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82683698
	if (cr0.eq) goto loc_82683698;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82683674;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82683698
	if (cr6.eq) goto loc_82683698;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82682910
	ctx.lr = 0x82683684;
	sub_82682910(ctx, base);
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
loc_82683698:
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

__attribute__((alias("__imp__sub_826836B0"))) PPC_WEAK_FUNC(sub_826836B0);
PPC_FUNC_IMPL(__imp__sub_826836B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// fmuls f0,f1,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// stfs f1,116(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stfs f0,120(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826836C0"))) PPC_WEAK_FUNC(sub_826836C0);
PPC_FUNC_IMPL(__imp__sub_826836C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,124(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826836C8"))) PPC_WEAK_FUNC(sub_826836C8);
PPC_FUNC_IMPL(__imp__sub_826836C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,140(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82683708
	if (cr6.eq) goto loc_82683708;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,152(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,148(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82683708:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,148(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82683728
	if (!cr6.gt) goto loc_82683728;
	// li r11,0
	r11.s64 = 0;
loc_82683728:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82683748"))) PPC_WEAK_FUNC(sub_82683748);
PPC_FUNC_IMPL(__imp__sub_82683748) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8268374C"))) PPC_WEAK_FUNC(sub_8268374C);
PPC_FUNC_IMPL(__imp__sub_8268374C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683750"))) PPC_WEAK_FUNC(sub_82683750);
PPC_FUNC_IMPL(__imp__sub_82683750) {
	PPC_FUNC_PROLOGUE();
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x82683774;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// blt cr6,0x82683800
	if (cr6.lt) goto loc_82683800;
	// lfs f12,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bgt cr6,0x82683800
	if (cr6.gt) goto loc_82683800;
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// lfs f13,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lfs f0,120(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	f0.f64 = double(temp.f32);
	// fmuls f8,f12,f12
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f0
	cr6.compare(ctx.f7.f64, f0.f64);
	// bge cr6,0x82683800
	if (!cr6.lt) goto loc_82683800;
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f12,400(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 400);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,408(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 408);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// fmuls f7,f11,f11
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f6,f8,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x82683804
	if (cr6.gt) goto loc_82683804;
loc_82683800:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82683804:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8268381C"))) PPC_WEAK_FUNC(sub_8268381C);
PPC_FUNC_IMPL(__imp__sub_8268381C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683820"))) PPC_WEAK_FUNC(sub_82683820);
PPC_FUNC_IMPL(__imp__sub_82683820) {
	PPC_FUNC_PROLOGUE();
	// stw r4,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82683828"))) PPC_WEAK_FUNC(sub_82683828);
PPC_FUNC_IMPL(__imp__sub_82683828) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,152(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,148(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f10,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bge cr6,0x82683868
	if (!cr6.lt) goto loc_82683868;
	// li r4,3
	ctx.r4.s64 = 3;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82683868:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82683874"))) PPC_WEAK_FUNC(sub_82683874);
PPC_FUNC_IMPL(__imp__sub_82683874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683878"))) PPC_WEAK_FUNC(sub_82683878);
PPC_FUNC_IMPL(__imp__sub_82683878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f1,152(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82683884"))) PPC_WEAK_FUNC(sub_82683884);
PPC_FUNC_IMPL(__imp__sub_82683884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683888"))) PPC_WEAK_FUNC(sub_82683888);
PPC_FUNC_IMPL(__imp__sub_82683888) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,136(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// cmpwi cr6,r4,24
	cr6.compare<int32_t>(ctx.r4.s32, 24, xer);
	// bge cr6,0x82683914
	if (!cr6.lt) goto loc_82683914;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,32
	r11.s64 = 32;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lbz r9,144(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
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
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r3,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// vpermwi128 v59,v62,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// vpermwi128 v60,v62,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stb r5,132(r3)
	PPC_STORE_U8(ctx.r3.u32 + 132, ctx.r5.u8);
	// vpermwi128 v58,v62,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lfs f2,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,48
	ctx.r7.s64 = ctx.r3.s64 + 48;
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,1
	ctx.r8.s64 = 1;
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x82683910
	if (cr6.eq) goto loc_82683910;
	// li r4,22
	ctx.r4.s64 = 22;
loc_82683910:
	// bl 0x82682590
	ctx.lr = 0x82683914;
	sub_82682590(ctx, base);
loc_82683914:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82683924"))) PPC_WEAK_FUNC(sub_82683924);
PPC_FUNC_IMPL(__imp__sub_82683924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683928"))) PPC_WEAK_FUNC(sub_82683928);
PPC_FUNC_IMPL(__imp__sub_82683928) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r11,19088
	ctx.r6.s64 = r11.s64 + 19088;
loc_82683944:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826839a0
	if (cr6.eq) goto loc_826839A0;
	// li r7,3
	ctx.r7.s64 = 3;
loc_82683954:
	// lbzx r9,r3,r7
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r7.u32);
	// lbzx r11,r9,r6
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// ble cr6,0x82683994
	if (!cr6.gt) goto loc_82683994;
	// subf r8,r4,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r4.s64;
	// li r11,7
	r11.s64 = 7;
loc_82683970:
	// slw r30,r5,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (r11.u8 & 0x3F));
	// and r30,r30,r9
	r30.u64 = r30.u64 & ctx.r9.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82683984
	if (cr6.eq) goto loc_82683984;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
loc_82683984:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x826839c0
	if (cr6.eq) goto loc_826839C0;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x82683970
	if (!cr0.lt) goto loc_82683970;
loc_82683994:
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// cmpwi cr6,r7,-1
	cr6.compare<int32_t>(ctx.r7.s32, -1, xer);
	// bne cr6,0x82683954
	if (!cr6.eq) goto loc_82683954;
loc_826839A0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// blt cr6,0x82683944
	if (cr6.lt) goto loc_82683944;
	// li r3,-1
	ctx.r3.s64 = -1;
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_826839C0:
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// addi r9,r10,3
	ctx.r9.s64 = ctx.r10.s64 + 3;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826839E0"))) PPC_WEAK_FUNC(sub_826839E0);
PPC_FUNC_IMPL(__imp__sub_826839E0) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,19372
	ctx.r9.s64 = r11.s64 + 19372;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82683a14
	if (cr6.eq) goto loc_82683A14;
	// bl 0x82130588
	ctx.lr = 0x82683A10;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82683A14:
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

__attribute__((alias("__imp__sub_82683A28"))) PPC_WEAK_FUNC(sub_82683A28);
PPC_FUNC_IMPL(__imp__sub_82683A28) {
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
	// lbz r11,22(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82683a58
	if (cr6.eq) goto loc_82683A58;
	// clrlwi r11,r4,30
	r11.u64 = ctx.r4.u32 & 0x3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,144(r31)
	PPC_STORE_U8(r31.u32 + 144, ctx.r9.u8);
loc_82683A58:
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r12,-10923
	r12.s64 = -715849728;
	// lis r10,257
	ctx.r10.s64 = 16842752;
	// ori r12,r12,21845
	r12.u64 = r12.u64 | 21845;
	// rlwinm r9,r11,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// ori r8,r10,257
	ctx.r8.u64 = ctx.r10.u64 | 257;
	// and r9,r9,r12
	ctx.r9.u64 = ctx.r9.u64 & r12.u64;
	// lis r12,-3277
	r12.s64 = -214761472;
	// subf r7,r9,r11
	ctx.r7.s64 = r11.s64 - ctx.r9.s64;
	// ori r12,r12,13107
	r12.u64 = r12.u64 | 13107;
	// rlwinm r10,r7,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// and r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 & r12.u64;
	// lis r12,13107
	r12.s64 = 858980352;
	// ori r12,r12,13107
	r12.u64 = r12.u64 | 13107;
	// and r11,r7,r12
	r11.u64 = ctx.r7.u64 & r12.u64;
	// lis r12,3855
	r12.s64 = 252641280;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ori r12,r12,3855
	r12.u64 = r12.u64 | 3855;
	// rlwinm r10,r11,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// and r5,r6,r12
	ctx.r5.u64 = ctx.r6.u64 & r12.u64;
	// mullw r11,r5,r8
	r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// rlwinm r11,r11,8,24,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82683af0
	if (cr6.eq) goto loc_82683AF0;
	// srawi r9,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 2;
	// twllei r11,0
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r8,r9,r11
	ctx.r8.s32 = ctx.r9.s32 / r11.s32;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// mullw r6,r8,r11
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// andc r5,r11,r7
	ctx.r5.u64 = r11.u64 & ~ctx.r7.u64;
	// subf r4,r6,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// bl 0x82683928
	ctx.lr = 0x82683AE8;
	sub_82683928(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// b 0x82683af8
	goto loc_82683AF8;
loc_82683AF0:
	// li r11,25
	r11.s64 = 25;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_82683AF8:
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82683b14
	if (cr6.eq) goto loc_82683B14;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82683b14
	if (!cr6.eq) goto loc_82683B14;
	// stb r11,144(r31)
	PPC_STORE_U8(r31.u32 + 144, r11.u8);
loc_82683B14:
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

__attribute__((alias("__imp__sub_82683B28"))) PPC_WEAK_FUNC(sub_82683B28);
PPC_FUNC_IMPL(__imp__sub_82683B28) {
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
	// bl 0x82683a28
	ctx.lr = 0x82683B40;
	sub_82683A28(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// stw r10,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r10.u32);
	// lfs f13,152(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,148(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
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

__attribute__((alias("__imp__sub_82683B74"))) PPC_WEAK_FUNC(sub_82683B74);
PPC_FUNC_IMPL(__imp__sub_82683B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683B78"))) PPC_WEAK_FUNC(sub_82683B78);
PPC_FUNC_IMPL(__imp__sub_82683B78) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82683B80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r30,1
	r30.s64 = 1;
	// stfs f0,24(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 24, temp.u32);
	// stb r31,21(r29)
	PPC_STORE_U8(r29.u32 + 21, r31.u8);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stb r30,20(r29)
	PPC_STORE_U8(r29.u32 + 20, r30.u8);
	// lfs f13,3732(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// stb r31,22(r29)
	PPC_STORE_U8(r29.u32 + 22, r31.u8);
	// lfs f12,12428(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// stb r31,144(r29)
	PPC_STORE_U8(r29.u32 + 144, r31.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,23(r29)
	PPC_STORE_U8(r29.u32 + 23, r31.u8);
	// stw r31,128(r29)
	PPC_STORE_U32(r29.u32 + 128, r31.u32);
	// stfs f0,124(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 124, temp.u32);
	// stfs f13,116(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 116, temp.u32);
	// stfs f12,120(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 120, temp.u32);
	// bl 0x82683a28
	ctx.lr = 0x82683BE0;
	sub_82683A28(ctx, base);
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r30,140(r29)
	PPC_STORE_U32(r29.u32 + 140, r30.u32);
	// lfs f13,152(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r7,29952
	ctx.r6.s64 = ctx.r7.s64 + 29952;
	// lfs f0,24(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,148(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 148, temp.u32);
	// stb r31,132(r29)
	PPC_STORE_U8(r29.u32 + 132, r31.u8);
	// stb r31,145(r29)
	PPC_STORE_U8(r29.u32 + 145, r31.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82683C0C"))) PPC_WEAK_FUNC(sub_82683C0C);
PPC_FUNC_IMPL(__imp__sub_82683C0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683C10"))) PPC_WEAK_FUNC(sub_82683C10);
PPC_FUNC_IMPL(__imp__sub_82683C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r3,128
	r11.s64 = ctx.r3.s64 + 128;
	// rlwinm r10,r4,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r8,r4,27
	ctx.r8.u64 = ctx.r4.u32 & 0x1F;
	// li r7,1
	ctx.r7.s64 = 1;
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// slw r4,r7,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// xor r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// and r8,r4,r3
	ctx.r8.u64 = ctx.r4.u64 & ctx.r3.u64;
	// xor r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82683C48"))) PPC_WEAK_FUNC(sub_82683C48);
PPC_FUNC_IMPL(__imp__sub_82683C48) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,19372
	ctx.r9.s64 = r11.s64 + 19372;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r8.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,148(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// bl 0x82683b78
	ctx.lr = 0x82683C84;
	sub_82683B78(ctx, base);
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

__attribute__((alias("__imp__sub_82683C9C"))) PPC_WEAK_FUNC(sub_82683C9C);
PPC_FUNC_IMPL(__imp__sub_82683C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683CA0"))) PPC_WEAK_FUNC(sub_82683CA0);
PPC_FUNC_IMPL(__imp__sub_82683CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,19692
	ctx.r9.s64 = r11.s64 + 19692;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// stw r11,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, r11.u32);
	// stw r3,30436(r8)
	PPC_STORE_U32(ctx.r8.u32 + 30436, ctx.r3.u32);
	// stb r11,516(r3)
	PPC_STORE_U8(ctx.r3.u32 + 516, r11.u8);
	// stb r11,517(r3)
	PPC_STORE_U8(ctx.r3.u32 + 517, r11.u8);
	// stw r11,520(r3)
	PPC_STORE_U32(ctx.r3.u32 + 520, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82683CD8"))) PPC_WEAK_FUNC(sub_82683CD8);
PPC_FUNC_IMPL(__imp__sub_82683CD8) {
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
	ctx.lr = 0x82683CE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r31,524
	r11.s64 = r31.s64 + 524;
	// li r10,10
	ctx.r10.s64 = 10;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82683CF8:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82683cf8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82683CF8;
	// addi r11,r31,564
	r11.s64 = r31.s64 + 564;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,10
	ctx.r10.s64 = 10;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82683D14:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82683d14
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82683D14;
	// lwz r28,108(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82683d48
	if (!cr6.gt) goto loc_82683D48;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_82683D34:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82685578
	ctx.lr = 0x82683D3C;
	sub_82685578(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82683d34
	if (!cr0.eq) goto loc_82683D34;
loc_82683D48:
	// li r11,0
	r11.s64 = 0;
	// lwz r3,520(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 520);
	// stw r11,512(r31)
	PPC_STORE_U32(r31.u32 + 512, r11.u32);
	// bl 0x82686110
	ctx.lr = 0x82683D58;
	sub_82686110(ctx, base);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82683d7c
	if (!cr6.gt) goto loc_82683D7C;
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_82683D68:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82686670
	ctx.lr = 0x82683D70;
	sub_82686670(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82683d68
	if (!cr0.eq) goto loc_82683D68;
loc_82683D7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82683D84"))) PPC_WEAK_FUNC(sub_82683D84);
PPC_FUNC_IMPL(__imp__sub_82683D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683D88"))) PPC_WEAK_FUNC(sub_82683D88);
PPC_FUNC_IMPL(__imp__sub_82683D88) {
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
	ctx.lr = 0x82683D90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,512(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 512);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82683e10
	if (cr6.eq) goto loc_82683E10;
	// li r27,0
	r27.s64 = 0;
	// ble cr6,0x82683e10
	if (!cr6.gt) goto loc_82683E10;
	// addi r11,r30,27
	r11.s64 = r30.s64 + 27;
	// addi r31,r3,112
	r31.s64 = ctx.r3.s64 + 112;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r28,r31
	r28.u64 = r31.u64;
	// add r29,r11,r3
	r29.u64 = r11.u64 + ctx.r3.u64;
loc_82683DBC:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82683DD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// beq cr6,0x82683e00
	if (cr6.eq) goto loc_82683E00;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// addi r29,r29,-4
	r29.s64 = r29.s64 + -4;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stw r10,400(r31)
	PPC_STORE_U32(r31.u32 + 400, ctx.r10.u32);
	// b 0x82683e08
	goto loc_82683E08;
loc_82683E00:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
loc_82683E08:
	// cmpw cr6,r27,r30
	cr6.compare<int32_t>(r27.s32, r30.s32, xer);
	// blt cr6,0x82683dbc
	if (cr6.lt) goto loc_82683DBC;
loc_82683E10:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82683E1C"))) PPC_WEAK_FUNC(sub_82683E1C);
PPC_FUNC_IMPL(__imp__sub_82683E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683E20"))) PPC_WEAK_FUNC(sub_82683E20);
PPC_FUNC_IMPL(__imp__sub_82683E20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,108(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
loc_82683E38:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lhz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// add r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 + ctx.r3.u64;
	// bne 0x82683e38
	if (!cr0.eq) goto loc_82683E38;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82683E54"))) PPC_WEAK_FUNC(sub_82683E54);
PPC_FUNC_IMPL(__imp__sub_82683E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683E58"))) PPC_WEAK_FUNC(sub_82683E58);
PPC_FUNC_IMPL(__imp__sub_82683E58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r7,108(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82683e94
	if (!cr6.gt) goto loc_82683E94;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
loc_82683E70:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// subf. r8,r6,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt 0x82683e9c
	if (cr0.lt) goto loc_82683E9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82683e70
	if (cr6.lt) goto loc_82683E70;
loc_82683E94:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82683E9C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82683EB8"))) PPC_WEAK_FUNC(sub_82683EB8);
PPC_FUNC_IMPL(__imp__sub_82683EB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,30436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 30436);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82683ED0"))) PPC_WEAK_FUNC(sub_82683ED0);
PPC_FUNC_IMPL(__imp__sub_82683ED0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,36
	ctx.r3.s64 = 36;
	// lwz r31,30436(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 30436);
	// bl 0x82130528
	ctx.lr = 0x82683EF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82683f10
	if (cr6.eq) goto loc_82683F10;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,520(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 520);
	// bl 0x82686040
	ctx.lr = 0x82683F0C;
	sub_82686040(ctx, base);
	// b 0x82683f14
	goto loc_82683F14;
loc_82683F10:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82683F14:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// stwx r3,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82683F44"))) PPC_WEAK_FUNC(sub_82683F44);
PPC_FUNC_IMPL(__imp__sub_82683F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683F48"))) PPC_WEAK_FUNC(sub_82683F48);
PPC_FUNC_IMPL(__imp__sub_82683F48) {
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
	ctx.lr = 0x82683F64;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82683f90
	if (!cr6.gt) goto loc_82683F90;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82683F74:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82683f84
	if (cr6.eq) goto loc_82683F84;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_82683F84:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x82683f74
	if (!cr0.eq) goto loc_82683F74;
loc_82683F90:
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

__attribute__((alias("__imp__sub_82683FA4"))) PPC_WEAK_FUNC(sub_82683FA4);
PPC_FUNC_IMPL(__imp__sub_82683FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82683FA8"))) PPC_WEAK_FUNC(sub_82683FA8);
PPC_FUNC_IMPL(__imp__sub_82683FA8) {
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
	ctx.lr = 0x82683FB0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r28,10
	cr6.compare<int32_t>(r28.s32, 10, xer);
	// bge cr6,0x82683fd4
	if (!cr6.lt) goto loc_82683FD4;
	// addi r11,r28,141
	r11.s64 = r28.s64 + 141;
	// addi r10,r27,1
	ctx.r10.s64 = r27.s64 + 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
loc_82683FD4:
	// lwz r11,108(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82684034
	if (!cr6.gt) goto loc_82684034;
	// addi r26,r3,8
	r26.s64 = ctx.r3.s64 + 8;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_82683FE8:
	// lwz r29,0(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lhz r31,20(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 20);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82684028
	if (!cr6.gt) goto loc_82684028;
	// li r30,0
	r30.s64 = 0;
loc_82683FFC:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8268401C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82683ffc
	if (!cr0.eq) goto loc_82683FFC;
loc_82684028:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x82683fe8
	if (!cr0.eq) goto loc_82683FE8;
loc_82684034:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8268403C"))) PPC_WEAK_FUNC(sub_8268403C);
PPC_FUNC_IMPL(__imp__sub_8268403C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684040"))) PPC_WEAK_FUNC(sub_82684040);
PPC_FUNC_IMPL(__imp__sub_82684040) {
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
	// bl 0x82683ed0
	ctx.lr = 0x82684060;
	sub_82683ED0(ctx, base);
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

__attribute__((alias("__imp__sub_8268407C"))) PPC_WEAK_FUNC(sub_8268407C);
PPC_FUNC_IMPL(__imp__sub_8268407C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684080"))) PPC_WEAK_FUNC(sub_82684080);
PPC_FUNC_IMPL(__imp__sub_82684080) {
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
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826840AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826840e0
	if (cr6.eq) goto loc_826840E0;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bge cr6,0x826840f4
	if (!cr6.lt) goto loc_826840F4;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,131
	ctx.r9.s64 = r11.s64 + 131;
	// addi r8,r30,1
	ctx.r8.s64 = r30.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,30436(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30436);
	// stwx r8,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r8.u32);
	// b 0x826840f4
	goto loc_826840F4;
loc_826840E0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,30436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 30436);
	// bl 0x82683fa8
	ctx.lr = 0x826840F4;
	sub_82683FA8(ctx, base);
loc_826840F4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8268410C"))) PPC_WEAK_FUNC(sub_8268410C);
PPC_FUNC_IMPL(__imp__sub_8268410C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684110"))) PPC_WEAK_FUNC(sub_82684110);
PPC_FUNC_IMPL(__imp__sub_82684110) {
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
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r9,r10,24532
	ctx.r9.s64 = ctx.r10.s64 + 24532;
	// addi r30,r31,56
	r30.s64 = r31.s64 + 56;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r5,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r5.u32);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r4,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r4.u32);
	// lfs f0,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// rotlwi r4,r8,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lfs f11,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,36(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lfs f10,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,40(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// lfs f9,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,44(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// lfs f8,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,48(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lfs f7,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,52(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// sth r4,60(r31)
	PPC_STORE_U16(r31.u32 + 60, ctx.r4.u16);
	// sth r4,62(r31)
	PPC_STORE_U16(r31.u32 + 62, ctx.r4.u16);
	// beq cr6,0x826841c8
	if (cr6.eq) goto loc_826841C8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82683f48
	ctx.lr = 0x826841C0;
	sub_82683F48(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x826841cc
	goto loc_826841CC;
loc_826841C8:
	// li r11,0
	r11.s64 = 0;
loc_826841CC:
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_826841EC"))) PPC_WEAK_FUNC(sub_826841EC);
PPC_FUNC_IMPL(__imp__sub_826841EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826841F0"))) PPC_WEAK_FUNC(sub_826841F0);
PPC_FUNC_IMPL(__imp__sub_826841F0) {
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
	// li r3,64
	ctx.r3.s64 = 64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x82684214;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8268422c
	if (cr6.eq) goto loc_8268422C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82684110
	ctx.lr = 0x82684224;
	sub_82684110(ctx, base);
	// stw r3,520(r31)
	PPC_STORE_U32(r31.u32 + 520, ctx.r3.u32);
	// b 0x82684234
	goto loc_82684234;
loc_8268422C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,520(r31)
	PPC_STORE_U32(r31.u32 + 520, r11.u32);
loc_82684234:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8268424C"))) PPC_WEAK_FUNC(sub_8268424C);
PPC_FUNC_IMPL(__imp__sub_8268424C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684250"))) PPC_WEAK_FUNC(sub_82684250);
PPC_FUNC_IMPL(__imp__sub_82684250) {
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
	ctx.lr = 0x82684258;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,108(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r3,8
	r30.s64 = ctx.r3.s64 + 8;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82684294
	if (!cr6.gt) goto loc_82684294;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_82684278:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// beq cr6,0x826842f0
	if (cr6.eq) goto loc_826842F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82684278
	if (cr6.lt) goto loc_82684278;
loc_82684294:
	// li r29,-1
	r29.s64 = -1;
loc_82684298:
	// lwz r11,512(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 512);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82684320
	if (!cr6.gt) goto loc_82684320;
	// addi r11,r3,112
	r11.s64 = ctx.r3.s64 + 112;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_826842B8:
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// lwz r8,0(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82684300
	if (!cr6.gt) goto loc_82684300;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_826842D0:
	// lwz r28,0(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r28,r8
	cr6.compare<uint32_t>(r28.u32, ctx.r8.u32, xer);
	// beq cr6,0x826842f8
	if (cr6.eq) goto loc_826842F8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x826842d0
	if (cr6.lt) goto loc_826842D0;
	// b 0x82684300
	goto loc_82684300;
loc_826842F0:
	// mr r29,r11
	r29.u64 = r11.u64;
	// b 0x82684298
	goto loc_82684298;
loc_826842F8:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8268430c
	if (!cr6.eq) goto loc_8268430C;
loc_82684300:
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
loc_8268430C:
	// lwz r11,512(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 512);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// blt cr6,0x826842b8
	if (cr6.lt) goto loc_826842B8;
loc_82684320:
	// stw r4,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, ctx.r4.u32);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x82684358
	if (!cr6.lt) goto loc_82684358;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
loc_8268433C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r8,100(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x8268433c
	if (cr6.lt) goto loc_8268433C;
loc_82684358:
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,100(r30)
	PPC_STORE_U32(r30.u32 + 100, r11.u32);
	// beq cr6,0x826843cc
	if (cr6.eq) goto loc_826843CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826865a8
	ctx.lr = 0x82684374;
	sub_826865A8(ctx, base);
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82684388
	if (cr6.eq) goto loc_82684388;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x82684388;
	sub_82130588(ctx, base);
loc_82684388:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8268439c
	if (cr6.eq) goto loc_8268439C;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8268439C;
	sub_82130588(ctx, base);
loc_8268439C:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826843b0
	if (cr6.eq) goto loc_826843B0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x826843B0;
	sub_82130588(ctx, base);
loc_826843B0:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826843c4
	if (cr6.eq) goto loc_826843C4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826843C4;
	sub_82130588(ctx, base);
loc_826843C4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x826843CC;
	sub_82130588(ctx, base);
loc_826843CC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826843D4"))) PPC_WEAK_FUNC(sub_826843D4);
PPC_FUNC_IMPL(__imp__sub_826843D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826843D8"))) PPC_WEAK_FUNC(sub_826843D8);
PPC_FUNC_IMPL(__imp__sub_826843D8) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x826843E0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r25,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,-5148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// beq cr6,0x82684414
	if (cr6.eq) goto loc_82684414;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x82684418
	goto loc_82684418;
loc_82684414:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82684418:
	// lwzx r28,r9,r10
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8268452c
	if (cr6.eq) goto loc_8268452C;
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8268452c
	if (cr6.eq) goto loc_8268452C;
	// li r11,400
	r11.s64 = 400;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v63,r28,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x82684448;
	sub_822A8108(ctx, base);
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// cmpwi cr6,r25,10
	cr6.compare<int32_t>(r25.s32, 10, xer);
	// lvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x82684470
	if (!cr6.lt) goto loc_82684470;
	// addi r11,r25,141
	r11.s64 = r25.s64 + 141;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r26,r10,r30
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// b 0x82684474
	goto loc_82684474;
loc_82684470:
	// li r26,0
	r26.s64 = 0;
loc_82684474:
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r3,520(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 520);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x826855c8
	ctx.lr = 0x82684488;
	sub_826855C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8268452c
	if (!cr6.gt) goto loc_8268452C;
	// addi r27,r1,112
	r27.s64 = ctx.r1.s64 + 112;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
loc_82684498:
	// lwz r29,0(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82684520
	if (cr6.eq) goto loc_82684520;
loc_826844A4:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82684514
	if (!cr6.eq) goto loc_82684514;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826844c8
	if (cr6.eq) goto loc_826844C8;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// bne cr6,0x82684514
	if (!cr6.eq) goto loc_82684514;
loc_826844C8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826844E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82684514
	if (cr6.eq) goto loc_82684514;
	// lwz r11,512(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 512);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82684514
	if (cr6.eq) goto loc_82684514;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r30,112
	ctx.r10.s64 = r30.s64 + 112;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,512(r30)
	PPC_STORE_U32(r30.u32 + 512, r11.u32);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
loc_82684514:
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826844a4
	if (!cr6.eq) goto loc_826844A4;
loc_82684520:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x82684498
	if (!cr0.eq) goto loc_82684498;
loc_8268452C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82684534"))) PPC_WEAK_FUNC(sub_82684534);
PPC_FUNC_IMPL(__imp__sub_82684534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684538"))) PPC_WEAK_FUNC(sub_82684538);
PPC_FUNC_IMPL(__imp__sub_82684538) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82684540;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5948
	ctx.lr = 0x82684554;
	sub_822A5948(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826846ac
	if (cr6.eq) goto loc_826846AC;
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826846ac
	if (cr6.eq) goto loc_826846AC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8268457C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826846ac
	if (cr6.eq) goto loc_826846AC;
	// li r11,400
	r11.s64 = 400;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v63,r28,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x826845A0;
	sub_822A8108(ctx, base);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826845C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,10
	cr6.compare<int32_t>(r31.s32, 10, xer);
	// bge cr6,0x826845e0
	if (!cr6.lt) goto loc_826845E0;
	// addi r11,r31,131
	r11.s64 = r31.s64 + 131;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r26,r10,r30
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// b 0x826845e4
	goto loc_826845E4;
loc_826845E0:
	// li r26,0
	r26.s64 = 0;
loc_826845E4:
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r3,520(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 520);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x826855c8
	ctx.lr = 0x826845F8;
	sub_826855C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826846ac
	if (!cr6.gt) goto loc_826846AC;
	// addi r27,r1,112
	r27.s64 = ctx.r1.s64 + 112;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
loc_82684608:
	// lwz r29,0(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826846a0
	if (cr6.eq) goto loc_826846A0;
loc_82684614:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r11,17(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82684694
	if (cr6.eq) goto loc_82684694;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82684694
	if (!cr6.eq) goto loc_82684694;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82684648
	if (!cr6.eq) goto loc_82684648;
	// lbz r11,18(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82684694
	if (cr6.eq) goto loc_82684694;
loc_82684648:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82684694
	if (cr6.eq) goto loc_82684694;
	// lwz r11,512(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 512);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82684694
	if (cr6.eq) goto loc_82684694;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r30,112
	ctx.r10.s64 = r30.s64 + 112;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,512(r30)
	PPC_STORE_U32(r30.u32 + 512, r11.u32);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
loc_82684694:
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82684614
	if (!cr6.eq) goto loc_82684614;
loc_826846A0:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x82684608
	if (!cr0.eq) goto loc_82684608;
loc_826846AC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826846B4"))) PPC_WEAK_FUNC(sub_826846B4);
PPC_FUNC_IMPL(__imp__sub_826846B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826846B8"))) PPC_WEAK_FUNC(sub_826846B8);
PPC_FUNC_IMPL(__imp__sub_826846B8) {
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
	ctx.lr = 0x826846C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,108(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8268476c
	if (!cr6.gt) goto loc_8268476C;
	// addi r26,r30,8
	r26.s64 = r30.s64 + 8;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_826846DC:
	// lwz r27,0(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lhz r11,28(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82684760
	if (!cr6.gt) goto loc_82684760;
	// li r29,0
	r29.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_826846F4:
	// lwz r11,24(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwzx r31,r11,r29
	r31.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82684754
	if (!cr6.eq) goto loc_82684754;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82684754
	if (cr6.eq) goto loc_82684754;
	// lwz r11,512(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 512);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82684754
	if (cr6.eq) goto loc_82684754;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r30,112
	ctx.r10.s64 = r30.s64 + 112;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,512(r30)
	PPC_STORE_U32(r30.u32 + 512, r11.u32);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
loc_82684754:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x826846f4
	if (!cr0.eq) goto loc_826846F4;
loc_82684760:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x826846dc
	if (!cr0.eq) goto loc_826846DC;
loc_8268476C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82684774"))) PPC_WEAK_FUNC(sub_82684774);
PPC_FUNC_IMPL(__imp__sub_82684774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684778"))) PPC_WEAK_FUNC(sub_82684778);
PPC_FUNC_IMPL(__imp__sub_82684778) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82684080
	sub_82684080(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82684788"))) PPC_WEAK_FUNC(sub_82684788);
PPC_FUNC_IMPL(__imp__sub_82684788) {
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
	ctx.lr = 0x82684790;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,108(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// stb r10,4(r28)
	PPC_STORE_U8(r28.u32 + 4, ctx.r10.u8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82684834
	if (!cr6.gt) goto loc_82684834;
	// addi r30,r28,8
	r30.s64 = r28.s64 + 8;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_826847B4:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x826865a8
	ctx.lr = 0x826847BC;
	sub_826865A8(ctx, base);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82684828
	if (cr6.eq) goto loc_82684828;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826865a8
	ctx.lr = 0x826847D0;
	sub_826865A8(ctx, base);
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826847e4
	if (cr6.eq) goto loc_826847E4;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x826847E4;
	sub_82130588(ctx, base);
loc_826847E4:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826847f8
	if (cr6.eq) goto loc_826847F8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x826847F8;
	sub_82130588(ctx, base);
loc_826847F8:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8268480c
	if (cr6.eq) goto loc_8268480C;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8268480C;
	sub_82130588(ctx, base);
loc_8268480C:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82684820
	if (cr6.eq) goto loc_82684820;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82684820;
	sub_82130588(ctx, base);
loc_82684820:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82684828;
	sub_82130588(ctx, base);
loc_82684828:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x826847b4
	if (!cr0.eq) goto loc_826847B4;
loc_82684834:
	// li r11,0
	r11.s64 = 0;
	// stw r11,108(r28)
	PPC_STORE_U32(r28.u32 + 108, r11.u32);
	// stw r11,512(r28)
	PPC_STORE_U32(r28.u32 + 512, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82684848"))) PPC_WEAK_FUNC(sub_82684848);
PPC_FUNC_IMPL(__imp__sub_82684848) {
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
	ctx.lr = 0x82684850;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lbz r11,4(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82684978
	if (cr6.eq) goto loc_82684978;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17268
	r29.s64 = r11.s64 + 17268;
	// lwz r10,17268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x8268488c
	if (cr6.eq) goto loc_8268488C;
	// lwz r28,260(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 260);
	// b 0x82684890
	goto loc_82684890;
loc_8268488C:
	// lwz r28,132(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
loc_82684890:
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82684924
	if (!cr6.gt) goto loc_82684924;
	// li r30,8
	r30.s64 = 8;
loc_826848A0:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826848d0
	if (cr6.eq) goto loc_826848D0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x826848f4
	if (cr6.lt) goto loc_826848F4;
	// lwz r11,260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 260);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x826848f4
	if (!cr6.lt) goto loc_826848F4;
	// add r11,r30,r10
	r11.u64 = r30.u64 + ctx.r10.u64;
	// lwz r9,128(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// b 0x826848ec
	goto loc_826848EC;
loc_826848D0:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x826848f4
	if (cr6.lt) goto loc_826848F4;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x826848f4
	if (!cr6.lt) goto loc_826848F4;
	// lwzx r11,r30,r10
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_826848EC:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826848f8
	if (!cr6.eq) goto loc_826848F8;
loc_826848F4:
	// li r11,0
	r11.s64 = 0;
loc_826848F8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82684914
	if (cr6.eq) goto loc_82684914;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82684538
	ctx.lr = 0x82684910;
	sub_82684538(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_82684914:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x826848a0
	if (cr6.lt) goto loc_826848A0;
loc_82684924:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// beq cr6,0x82684940
	if (cr6.eq) goto loc_82684940;
	// lhz r30,20(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// b 0x82684944
	goto loc_82684944;
loc_82684940:
	// lhz r30,12(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 12);
loc_82684944:
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82684968
	if (!cr6.gt) goto loc_82684968;
loc_82684950:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826843d8
	ctx.lr = 0x8268495C;
	sub_826843D8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x82684950
	if (cr6.lt) goto loc_82684950;
loc_82684968:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826846b8
	ctx.lr = 0x82684970;
	sub_826846B8(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82683d88
	ctx.lr = 0x82684978;
	sub_82683D88(ctx, base);
loc_82684978:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82684980"))) PPC_WEAK_FUNC(sub_82684980);
PPC_FUNC_IMPL(__imp__sub_82684980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,30436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 30436);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82684250
	sub_82684250(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82684994"))) PPC_WEAK_FUNC(sub_82684994);
PPC_FUNC_IMPL(__imp__sub_82684994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684998"))) PPC_WEAK_FUNC(sub_82684998);
PPC_FUNC_IMPL(__imp__sub_82684998) {
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
	// lis r11,-32152
	r11.s64 = -2107113472;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r11,16448
	ctx.r4.s64 = r11.s64 + 16448;
	// addi r3,r10,19812
	ctx.r3.s64 = ctx.r10.s64 + 19812;
	// bl 0x82554798
	ctx.lr = 0x826849B8;
	sub_82554798(ctx, base);
	// lis r9,-32152
	ctx.r9.s64 = -2107113472;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r4,r9,18816
	ctx.r4.s64 = ctx.r9.s64 + 18816;
	// addi r3,r8,19776
	ctx.r3.s64 = ctx.r8.s64 + 19776;
	// bl 0x82554798
	ctx.lr = 0x826849CC;
	sub_82554798(ctx, base);
	// lis r7,-32152
	ctx.r7.s64 = -2107113472;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// addi r4,r7,16056
	ctx.r4.s64 = ctx.r7.s64 + 16056;
	// addi r3,r6,19744
	ctx.r3.s64 = ctx.r6.s64 + 19744;
	// bl 0x82554798
	ctx.lr = 0x826849E0;
	sub_82554798(ctx, base);
	// lis r5,-32152
	ctx.r5.s64 = -2107113472;
	// lis r3,-32245
	ctx.r3.s64 = -2113208320;
	// addi r4,r5,18296
	ctx.r4.s64 = ctx.r5.s64 + 18296;
	// addi r3,r3,19712
	ctx.r3.s64 = ctx.r3.s64 + 19712;
	// bl 0x82554798
	ctx.lr = 0x826849F4;
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

__attribute__((alias("__imp__sub_82684A04"))) PPC_WEAK_FUNC(sub_82684A04);
PPC_FUNC_IMPL(__imp__sub_82684A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684A08"))) PPC_WEAK_FUNC(sub_82684A08);
PPC_FUNC_IMPL(__imp__sub_82684A08) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,19692
	ctx.r10.s64 = r11.s64 + 19692;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82684788
	ctx.lr = 0x82684A34;
	sub_82684788(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,30436(r9)
	PPC_STORE_U32(ctx.r9.u32 + 30436, r11.u32);
	// bl 0x821d2028
	ctx.lr = 0x82684A48;
	sub_821D2028(ctx, base);
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82684a60
	if (cr6.eq) goto loc_82684A60;
	// bl 0x82130588
	ctx.lr = 0x82684A5C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82684A60:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82684A78"))) PPC_WEAK_FUNC(sub_82684A78);
PPC_FUNC_IMPL(__imp__sub_82684A78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,20148
	ctx.r8.s64 = ctx.r10.s64 + 20148;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82684AA0"))) PPC_WEAK_FUNC(sub_82684AA0);
PPC_FUNC_IMPL(__imp__sub_82684AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,30440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 30440);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82684AAC"))) PPC_WEAK_FUNC(sub_82684AAC);
PPC_FUNC_IMPL(__imp__sub_82684AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684AB0"))) PPC_WEAK_FUNC(sub_82684AB0);
PPC_FUNC_IMPL(__imp__sub_82684AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82684AC8"))) PPC_WEAK_FUNC(sub_82684AC8);
PPC_FUNC_IMPL(__imp__sub_82684AC8) {
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
	// li r11,0
	r11.s64 = 0;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// bl 0x82256058
	ctx.lr = 0x82684AF0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82684b24
	if (cr6.eq) goto loc_82684B24;
	// bl 0x82256058
	ctx.lr = 0x82684AFC;
	sub_82256058(ctx, base);
	// bl 0x82256028
	ctx.lr = 0x82684B00;
	sub_82256028(ctx, base);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// b 0x82684b30
	goto loc_82684B30;
loc_82684B24:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	f0.f64 = double(temp.f32);
loc_82684B30:
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
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

__attribute__((alias("__imp__sub_82684B50"))) PPC_WEAK_FUNC(sub_82684B50);
PPC_FUNC_IMPL(__imp__sub_82684B50) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684B78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82684B80:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82684ba4
	if (cr6.eq) goto loc_82684BA4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d4c50
	ctx.lr = 0x82684B94;
	sub_821D4C50(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82684ba4
	if (!cr6.eq) goto loc_82684BA4;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// b 0x82684b80
	goto loc_82684B80;
loc_82684BA4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82684BBC"))) PPC_WEAK_FUNC(sub_82684BBC);
PPC_FUNC_IMPL(__imp__sub_82684BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684BC0"))) PPC_WEAK_FUNC(sub_82684BC0);
PPC_FUNC_IMPL(__imp__sub_82684BC0) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82684BD4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82684c10
	if (cr6.eq) goto loc_82684C10;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r11,1
	r11.s64 = 1;
	// addi r8,r9,20148
	ctx.r8.s64 = ctx.r9.s64 + 20148;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82684C10:
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

__attribute__((alias("__imp__sub_82684C24"))) PPC_WEAK_FUNC(sub_82684C24);
PPC_FUNC_IMPL(__imp__sub_82684C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684C28"))) PPC_WEAK_FUNC(sub_82684C28);
PPC_FUNC_IMPL(__imp__sub_82684C28) {
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
	ctx.lr = 0x82684C30;
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
	// bl 0x82684b50
	ctx.lr = 0x82684C44;
	sub_82684B50(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82684ca0
	if (cr6.eq) goto loc_82684CA0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684C60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// beq cr6,0x82684c80
	if (cr6.eq) goto loc_82684C80;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20256
	ctx.r3.s64 = r11.s64 + 20256;
	// bl 0x82130000
	ctx.lr = 0x82684C78;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82684C80:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684C94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r28,r3,r30
	PPC_STORE_U32(ctx.r3.u32 + r30.u32, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82684CA0:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20192
	ctx.r3.s64 = r11.s64 + 20192;
	// bl 0x82130000
	ctx.lr = 0x82684CB0;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82684CB8"))) PPC_WEAK_FUNC(sub_82684CB8);
PPC_FUNC_IMPL(__imp__sub_82684CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82684CC0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82684b50
	ctx.lr = 0x82684CD8;
	sub_82684B50(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82684d3c
	if (cr6.eq) goto loc_82684D3C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,7
	cr6.compare<int32_t>(ctx.r3.s32, 7, xer);
	// beq cr6,0x82684d18
	if (cr6.eq) goto loc_82684D18;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20256
	ctx.r3.s64 = r11.s64 + 20256;
	// bl 0x82130000
	ctx.lr = 0x82684D0C;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_82684D18:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684D2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfsx f31,r3,r30
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + r30.u32, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_82684D3C:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20192
	ctx.r3.s64 = r11.s64 + 20192;
	// bl 0x82130000
	ctx.lr = 0x82684D4C;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82684D58"))) PPC_WEAK_FUNC(sub_82684D58);
PPC_FUNC_IMPL(__imp__sub_82684D58) {
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
	ctx.lr = 0x82684D60;
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
	// bl 0x82684b50
	ctx.lr = 0x82684D74;
	sub_82684B50(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82684dd0
	if (cr6.eq) goto loc_82684DD0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684D90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82684db0
	if (cr6.eq) goto loc_82684DB0;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20256
	ctx.r3.s64 = r11.s64 + 20256;
	// bl 0x82130000
	ctx.lr = 0x82684DA8;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82684DB0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684DC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stbx r28,r3,r30
	PPC_STORE_U8(ctx.r3.u32 + r30.u32, r28.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82684DD0:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20192
	ctx.r3.s64 = r11.s64 + 20192;
	// bl 0x82130000
	ctx.lr = 0x82684DE0;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82684DE8"))) PPC_WEAK_FUNC(sub_82684DE8);
PPC_FUNC_IMPL(__imp__sub_82684DE8) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82684DF0;
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
	// bl 0x82684b50
	ctx.lr = 0x82684E04;
	sub_82684B50(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82684e68
	if (cr6.eq) goto loc_82684E68;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684E20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,9
	cr6.compare<int32_t>(ctx.r3.s32, 9, xer);
	// beq cr6,0x82684e40
	if (cr6.eq) goto loc_82684E40;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20256
	ctx.r3.s64 = r11.s64 + 20256;
	// bl 0x82130000
	ctx.lr = 0x82684E38;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82684E40:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684E54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r9,r3,r30
	ctx.r9.u64 = ctx.r3.u64 + r30.u64;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82684E68:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20192
	ctx.r3.s64 = r11.s64 + 20192;
	// bl 0x82130000
	ctx.lr = 0x82684E78;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82684E80"))) PPC_WEAK_FUNC(sub_82684E80);
PPC_FUNC_IMPL(__imp__sub_82684E80) {
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
	ctx.lr = 0x82684E88;
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
	// bl 0x82684b50
	ctx.lr = 0x82684E9C;
	sub_82684B50(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82684f3c
	if (cr6.eq) goto loc_82684F3C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684EB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,11
	cr6.compare<int32_t>(ctx.r3.s32, 11, xer);
	// beq cr6,0x82684ed8
	if (cr6.eq) goto loc_82684ED8;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20256
	ctx.r3.s64 = r11.s64 + 20256;
	// bl 0x82130000
	ctx.lr = 0x82684ED0;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82684ED8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684EEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82684f4c
	if (!cr6.eq) goto loc_82684F4C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82684F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// addi r31,r11,-1
	r31.s64 = r11.s64 + -1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823db670
	ctx.lr = 0x82684F2C;
	sub_823DB670(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// stbx r8,r31,r30
	PPC_STORE_U8(r31.u32 + r30.u32, ctx.r8.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82684F3C:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20192
	ctx.r3.s64 = r11.s64 + 20192;
	// bl 0x82130000
	ctx.lr = 0x82684F4C;
	sub_82130000(ctx, base);
loc_82684F4C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82684F54"))) PPC_WEAK_FUNC(sub_82684F54);
PPC_FUNC_IMPL(__imp__sub_82684F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684F58"))) PPC_WEAK_FUNC(sub_82684F58);
PPC_FUNC_IMPL(__imp__sub_82684F58) {
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
	// b 0x82684c28
	sub_82684C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82684F6C"))) PPC_WEAK_FUNC(sub_82684F6C);
PPC_FUNC_IMPL(__imp__sub_82684F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684F70"))) PPC_WEAK_FUNC(sub_82684F70);
PPC_FUNC_IMPL(__imp__sub_82684F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82684cb8
	sub_82684CB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82684F84"))) PPC_WEAK_FUNC(sub_82684F84);
PPC_FUNC_IMPL(__imp__sub_82684F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684F88"))) PPC_WEAK_FUNC(sub_82684F88);
PPC_FUNC_IMPL(__imp__sub_82684F88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// b 0x82684d58
	sub_82684D58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82684FAC"))) PPC_WEAK_FUNC(sub_82684FAC);
PPC_FUNC_IMPL(__imp__sub_82684FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82684FB0"))) PPC_WEAK_FUNC(sub_82684FB0);
PPC_FUNC_IMPL(__imp__sub_82684FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stwx r6,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
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
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82684de8
	ctx.lr = 0x82685034;
	sub_82684DE8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82685044"))) PPC_WEAK_FUNC(sub_82685044);
PPC_FUNC_IMPL(__imp__sub_82685044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82685048"))) PPC_WEAK_FUNC(sub_82685048);
PPC_FUNC_IMPL(__imp__sub_82685048) {
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
	// b 0x82684e80
	sub_82684E80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8268505C"))) PPC_WEAK_FUNC(sub_8268505C);
PPC_FUNC_IMPL(__imp__sub_8268505C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82685060"))) PPC_WEAK_FUNC(sub_82685060);
PPC_FUNC_IMPL(__imp__sub_82685060) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r31,r11,30440
	r31.s64 = r11.s64 + 30440;
	// lwz r11,30440(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30440);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82685170
	if (!cr6.eq) goto loc_82685170;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82685090;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826850a4
	if (cr6.eq) goto loc_826850A4;
	// bl 0x821d5408
	ctx.lr = 0x826850A0;
	sub_821D5408(ctx, base);
	// b 0x826850a8
	goto loc_826850A8;
loc_826850A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826850A8:
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,20332
	ctx.r7.s64 = ctx.r10.s64 + 20332;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10288
	ctx.r9.s64 = r11.s64 + 10288;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32152
	ctx.r8.s64 = -2107113472;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,19392
	ctx.r4.s64 = ctx.r8.s64 + 19392;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r3,-31856
	ctx.r9.s64 = ctx.r3.s64 + -31856;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8268511C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8268512C;
	sub_821D4100(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x821d41d0
	ctx.lr = 0x82685148;
	sub_821D41D0(ctx, base);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,-31832
	ctx.r4.s64 = ctx.r5.s64 + -31832;
	// bl 0x821d4b00
	ctx.lr = 0x82685158;
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
	ctx.lr = 0x82685170;
	sub_821C0548(ctx, base);
loc_82685170:
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

__attribute__((alias("__imp__sub_82685188"))) PPC_WEAK_FUNC(sub_82685188);
PPC_FUNC_IMPL(__imp__sub_82685188) {
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
	// lis r11,-32152
	r11.s64 = -2107113472;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r11,20312
	ctx.r4.s64 = r11.s64 + 20312;
	// addi r3,r10,20460
	ctx.r3.s64 = ctx.r10.s64 + 20460;
	// bl 0x82554798
	ctx.lr = 0x826851A8;
	sub_82554798(ctx, base);
	// lis r9,-32152
	ctx.r9.s64 = -2107113472;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r4,r9,20336
	ctx.r4.s64 = ctx.r9.s64 + 20336;
	// addi r3,r8,20432
	ctx.r3.s64 = ctx.r8.s64 + 20432;
	// bl 0x82554798
	ctx.lr = 0x826851BC;
	sub_82554798(ctx, base);
	// lis r7,-32152
	ctx.r7.s64 = -2107113472;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// addi r4,r7,20360
	ctx.r4.s64 = ctx.r7.s64 + 20360;
	// addi r3,r6,20404
	ctx.r3.s64 = ctx.r6.s64 + 20404;
	// bl 0x82554798
	ctx.lr = 0x826851D0;
	sub_82554798(ctx, base);
	// lis r5,-32152
	ctx.r5.s64 = -2107113472;
	// lis r3,-32245
	ctx.r3.s64 = -2113208320;
	// addi r4,r5,20400
	ctx.r4.s64 = ctx.r5.s64 + 20400;
	// addi r3,r3,20376
	ctx.r3.s64 = ctx.r3.s64 + 20376;
	// bl 0x82554798
	ctx.lr = 0x826851E4;
	sub_82554798(ctx, base);
	// lis r11,-32152
	r11.s64 = -2107113472;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r11,20552
	ctx.r4.s64 = r11.s64 + 20552;
	// addi r3,r10,20348
	ctx.r3.s64 = ctx.r10.s64 + 20348;
	// bl 0x82554798
	ctx.lr = 0x826851F8;
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

__attribute__((alias("__imp__sub_82685208"))) PPC_WEAK_FUNC(sub_82685208);
PPC_FUNC_IMPL(__imp__sub_82685208) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82685238:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8268525c
	if (cr6.eq) goto loc_8268525C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d4c50
	ctx.lr = 0x8268524C;
	sub_821D4C50(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8268525c
	if (!cr6.eq) goto loc_8268525C;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// b 0x82685238
	goto loc_82685238;
loc_8268525C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82685274"))) PPC_WEAK_FUNC(sub_82685274);
PPC_FUNC_IMPL(__imp__sub_82685274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82685278"))) PPC_WEAK_FUNC(sub_82685278);
PPC_FUNC_IMPL(__imp__sub_82685278) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8268529C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826852c0
	if (!cr6.eq) goto loc_826852C0;
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
loc_826852C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826852D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_826852EC"))) PPC_WEAK_FUNC(sub_826852EC);
PPC_FUNC_IMPL(__imp__sub_826852EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826852F0"))) PPC_WEAK_FUNC(sub_826852F0);
PPC_FUNC_IMPL(__imp__sub_826852F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82685300"))) PPC_WEAK_FUNC(sub_82685300);
PPC_FUNC_IMPL(__imp__sub_82685300) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82685308;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x82685318;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82685360
	if (cr6.eq) goto loc_82685360;
	// bl 0x82256058
	ctx.lr = 0x82685324;
	sub_82256058(ctx, base);
	// bl 0x82256078
	ctx.lr = 0x82685328;
	sub_82256078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82685360
	if (cr6.eq) goto loc_82685360;
	// bl 0x82256058
	ctx.lr = 0x82685338;
	sub_82256058(ctx, base);
	// bl 0x82256028
	ctx.lr = 0x8268533C;
	sub_82256028(ctx, base);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fmuls f31,f12,f0
	f31.f64 = double(float(ctx.f12.f64 * f0.f64));
	// b 0x8268536c
	goto loc_8268536C;
loc_82685360:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f31,24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	f31.f64 = double(temp.f32);
loc_8268536C:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r28,1
	r28.s64 = 1;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826853dc
	if (!cr6.eq) goto loc_826853DC;
	// lhz r11,44(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 44);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826853dc
	if (!cr6.gt) goto loc_826853DC;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82685390:
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x826853b8
	if (cr6.eq) goto loc_826853B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826853B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826853B8:
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x826853d0
	if (cr6.eq) goto loc_826853D0;
	// li r28,0
	r28.s64 = 0;
loc_826853D0:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82685390
	if (!cr0.eq) goto loc_82685390;
loc_826853DC:
	// clrlwi r31,r28,24
	r31.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8268543c
	if (cr6.eq) goto loc_8268543C;
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bne cr6,0x8268541c
	if (!cr6.eq) goto loc_8268541C;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685408;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r31
	ctx.r9.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8268541C:
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r31
	ctx.r9.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8268543C:
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82685450"))) PPC_WEAK_FUNC(sub_82685450);
PPC_FUNC_IMPL(__imp__sub_82685450) {
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
	ctx.lr = 0x82685458;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x826854b0
	if (!cr6.eq) goto loc_826854B0;
	// lhz r31,44(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 44);
	// li r11,2
	r11.s64 = 2;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
	// ble cr6,0x826854b0
	if (!cr6.gt) goto loc_826854B0;
	// li r30,0
	r30.s64 = 0;
loc_82685488:
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826854A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82685488
	if (!cr0.eq) goto loc_82685488;
loc_826854B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826854B8"))) PPC_WEAK_FUNC(sub_826854B8);
PPC_FUNC_IMPL(__imp__sub_826854B8) {
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
	ctx.lr = 0x826854C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// lhz r31,8(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82685504
	if (!cr6.gt) goto loc_82685504;
	// li r30,0
	r30.s64 = 0;
loc_826854E0:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826854F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x826854e0
	if (!cr0.eq) goto loc_826854E0;
loc_82685504:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685518;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82685520"))) PPC_WEAK_FUNC(sub_82685520);
PPC_FUNC_IMPL(__imp__sub_82685520) {
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
	// lhz r11,44(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82685564
	if (cr6.eq) goto loc_82685564;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82685550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_82685564:
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

__attribute__((alias("__imp__sub_82685578"))) PPC_WEAK_FUNC(sub_82685578);
PPC_FUNC_IMPL(__imp__sub_82685578) {
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
	ctx.lr = 0x82685580;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826855bc
	if (!cr6.gt) goto loc_826855BC;
	// li r30,0
	r30.s64 = 0;
loc_82685598:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826855B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82685598
	if (!cr0.eq) goto loc_82685598;
loc_826855BC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826855C4"))) PPC_WEAK_FUNC(sub_826855C4);
PPC_FUNC_IMPL(__imp__sub_826855C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826855C8"))) PPC_WEAK_FUNC(sub_826855C8);
PPC_FUNC_IMPL(__imp__sub_826855C8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826855D0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lfs f13,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f31,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f31.f64 = double(temp.f32);
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x825f3a30
	ctx.lr = 0x82685608;
	sub_825F3A30(ctx, base);
	// lfs f11,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lfs f10,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fadds f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f10.f64));
	// fmuls f1,f9,f31
	ctx.f1.f64 = double(float(ctx.f9.f64 * f31.f64));
	// bl 0x825f3aa8
	ctx.lr = 0x82685624;
	sub_825F3AA8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// bgt cr6,0x826856f4
	if (cr6.gt) goto loc_826856F4;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
loc_82685648:
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// cmpw cr6,r6,r7
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, xer);
	// bgt cr6,0x826856e8
	if (cr6.gt) goto loc_826856E8;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
loc_8268565C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// blt cr6,0x82685690
	if (cr6.lt) goto loc_82685690;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// bgt cr6,0x82685690
	if (cr6.gt) goto loc_82685690;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blt cr6,0x82685690
	if (cr6.lt) goto loc_82685690;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x82685694
	if (!cr6.gt) goto loc_82685694;
loc_82685690:
	// li r11,0
	r11.s64 = 0;
loc_82685694:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826856dc
	if (cr6.eq) goto loc_826856DC;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r29,16(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// lwz r28,56(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// subf r29,r29,r9
	r29.s64 = ctx.r9.s64 - r29.s64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mullw r11,r29,r11
	r11.s64 = int64_t(r29.s32) * int64_t(r11.s32);
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// add r4,r11,r8
	ctx.r4.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r11,r28
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_826856DC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// ble cr6,0x8268565c
	if (!cr6.gt) goto loc_8268565C;
loc_826856E8:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// ble cr6,0x82685648
	if (!cr6.gt) goto loc_82685648;
loc_826856F4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82685700"))) PPC_WEAK_FUNC(sub_82685700);
PPC_FUNC_IMPL(__imp__sub_82685700) {
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
	ctx.lr = 0x82685708;
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
	// bl 0x82685208
	ctx.lr = 0x8268571C;
	sub_82685208(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82685778
	if (cr6.eq) goto loc_82685778;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685738;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// beq cr6,0x82685758
	if (cr6.eq) goto loc_82685758;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,21000
	ctx.r3.s64 = r11.s64 + 21000;
	// bl 0x82130000
	ctx.lr = 0x82685750;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82685758:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8268576C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r28,r3,r30
	PPC_STORE_U32(ctx.r3.u32 + r30.u32, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82685778:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20944
	ctx.r3.s64 = r11.s64 + 20944;
	// bl 0x82130000
	ctx.lr = 0x82685788;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82685790"))) PPC_WEAK_FUNC(sub_82685790);
PPC_FUNC_IMPL(__imp__sub_82685790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82685798;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82685208
	ctx.lr = 0x826857B0;
	sub_82685208(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82685814
	if (cr6.eq) goto loc_82685814;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826857CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,7
	cr6.compare<int32_t>(ctx.r3.s32, 7, xer);
	// beq cr6,0x826857f0
	if (cr6.eq) goto loc_826857F0;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,21000
	ctx.r3.s64 = r11.s64 + 21000;
	// bl 0x82130000
	ctx.lr = 0x826857E4;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_826857F0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfsx f31,r3,r30
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + r30.u32, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_82685814:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20944
	ctx.r3.s64 = r11.s64 + 20944;
	// bl 0x82130000
	ctx.lr = 0x82685824;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82685830"))) PPC_WEAK_FUNC(sub_82685830);
PPC_FUNC_IMPL(__imp__sub_82685830) {
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
	ctx.lr = 0x82685838;
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
	// bl 0x82685208
	ctx.lr = 0x8268584C;
	sub_82685208(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826858a8
	if (cr6.eq) goto loc_826858A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82685888
	if (cr6.eq) goto loc_82685888;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,21000
	ctx.r3.s64 = r11.s64 + 21000;
	// bl 0x82130000
	ctx.lr = 0x82685880;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82685888:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8268589C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stbx r28,r3,r30
	PPC_STORE_U8(ctx.r3.u32 + r30.u32, r28.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826858A8:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20944
	ctx.r3.s64 = r11.s64 + 20944;
	// bl 0x82130000
	ctx.lr = 0x826858B8;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826858C0"))) PPC_WEAK_FUNC(sub_826858C0);
PPC_FUNC_IMPL(__imp__sub_826858C0) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826858C8;
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
	// bl 0x82685208
	ctx.lr = 0x826858DC;
	sub_82685208(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82685940
	if (cr6.eq) goto loc_82685940;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826858F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,9
	cr6.compare<int32_t>(ctx.r3.s32, 9, xer);
	// beq cr6,0x82685918
	if (cr6.eq) goto loc_82685918;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,21000
	ctx.r3.s64 = r11.s64 + 21000;
	// bl 0x82130000
	ctx.lr = 0x82685910;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82685918:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8268592C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r9,r3,r30
	ctx.r9.u64 = ctx.r3.u64 + r30.u64;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82685940:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,20944
	ctx.r3.s64 = r11.s64 + 20944;
	// bl 0x82130000
	ctx.lr = 0x82685950;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82685958"))) PPC_WEAK_FUNC(sub_82685958);
PPC_FUNC_IMPL(__imp__sub_82685958) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// stw r10,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r10.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82685988;
	sub_82130588(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// sth r31,8(r30)
	PPC_STORE_U16(r30.u32 + 8, r31.u16);
	// sth r31,10(r30)
	PPC_STORE_U16(r30.u32 + 10, r31.u16);
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// bl 0x82130588
	ctx.lr = 0x826859A0;
	sub_82130588(ctx, base);
	// stw r31,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r31.u32);
	// sth r31,44(r30)
	PPC_STORE_U16(r30.u32 + 44, r31.u16);
	// sth r31,46(r30)
	PPC_STORE_U16(r30.u32 + 46, r31.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826859C4"))) PPC_WEAK_FUNC(sub_826859C4);
PPC_FUNC_IMPL(__imp__sub_826859C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826859C8"))) PPC_WEAK_FUNC(sub_826859C8);
PPC_FUNC_IMPL(__imp__sub_826859C8) {
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
	ctx.lr = 0x826859D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r29,8(r30)
	r29.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82685a24
	if (!cr6.gt) goto loc_82685A24;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_826859EC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82685a10
	if (cr6.eq) goto loc_82685A10;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82685A10:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stwx r28,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r28.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826859ec
	if (!cr0.eq) goto loc_826859EC;
loc_82685A24:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82685A2C;
	sub_82130588(ctx, base);
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
	// sth r28,8(r30)
	PPC_STORE_U16(r30.u32 + 8, r28.u16);
	// sth r28,10(r30)
	PPC_STORE_U16(r30.u32 + 10, r28.u16);
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// bl 0x82130588
	ctx.lr = 0x82685A40;
	sub_82130588(ctx, base);
	// stw r28,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r28.u32);
	// sth r28,44(r30)
	PPC_STORE_U16(r30.u32 + 44, r28.u16);
	// sth r28,46(r30)
	PPC_STORE_U16(r30.u32 + 46, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82685A54"))) PPC_WEAK_FUNC(sub_82685A54);
PPC_FUNC_IMPL(__imp__sub_82685A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82685A58"))) PPC_WEAK_FUNC(sub_82685A58);
PPC_FUNC_IMPL(__imp__sub_82685A58) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82685aa0
	if (cr6.eq) goto loc_82685AA0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82685aa0
	if (cr6.eq) goto loc_82685AA0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685A9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82685aa4
	goto loc_82685AA4;
loc_82685AA0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82685AA4:
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

__attribute__((alias("__imp__sub_82685AC4"))) PPC_WEAK_FUNC(sub_82685AC4);
PPC_FUNC_IMPL(__imp__sub_82685AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82685AC8"))) PPC_WEAK_FUNC(sub_82685AC8);
PPC_FUNC_IMPL(__imp__sub_82685AC8) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x8262e420
	ctx.lr = 0x82685AF0;
	sub_8262E420(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82685B08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,7
	cr6.compare<int32_t>(ctx.r3.s32, 7, xer);
	// bne cr6,0x82685b18
	if (!cr6.eq) goto loc_82685B18;
	// li r11,1
	r11.s64 = 1;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
loc_82685B18:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82685B30"))) PPC_WEAK_FUNC(sub_82685B30);
PPC_FUNC_IMPL(__imp__sub_82685B30) {
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
	ctx.lr = 0x82685B38;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82685b5c
	if (!cr6.lt) goto loc_82685B5C;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x82685b68
	if (!cr6.lt) goto loc_82685B68;
loc_82685B5C:
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82685b6c
	if (cr6.lt) goto loc_82685B6C;
loc_82685B68:
	// stw r25,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r25.u32);
loc_82685B6C:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82685b84
	if (!cr6.lt) goto loc_82685B84;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x82685b90
	if (!cr6.lt) goto loc_82685B90;
loc_82685B84:
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82685b98
	if (cr6.lt) goto loc_82685B98;
loc_82685B90:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
loc_82685B98:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// addi r30,r11,2192
	r30.s64 = r11.s64 + 2192;
	// ori r29,r10,64167
	r29.u64 = ctx.r10.u64 | 64167;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,2192(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 2192);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mulld r10,r8,r29
	ctx.r10.s64 = ctx.r8.s64 * r29.s64;
	// lfs f0,14348(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lfs f13,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bge cr6,0x82685fa4
	if (!cr6.lt) goto loc_82685FA4;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r28,r25
	r28.u64 = r25.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82685c3c
	if (cr6.eq) goto loc_82685C3C;
	// mr r27,r25
	r27.u64 = r25.u64;
loc_82685C10:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r27,r11
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82685C28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r28,r8
	cr6.compare<int32_t>(r28.s32, ctx.r8.s32, xer);
	// blt cr6,0x82685c10
	if (cr6.lt) goto loc_82685C10;
loc_82685C3C:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x82685cc8
	if (!cr6.lt) goto loc_82685CC8;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82685cc8
	if (!cr6.lt) goto loc_82685CC8;
	// lhz r11,46(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// addi r26,r31,40
	r26.s64 = r31.s64 + 40;
	// lhz r30,8(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82685c88
	if (!cr6.eq) goto loc_82685C88;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r30.u16);
	// beq cr6,0x82685c80
	if (cr6.eq) goto loc_82685C80;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82685C7C;
	sub_82130528(ctx, base);
	// b 0x82685c84
	goto loc_82685C84;
loc_82685C80:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_82685C84:
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
loc_82685C88:
	// sth r30,4(r26)
	PPC_STORE_U16(r26.u32 + 4, r30.u16);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// lhz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82685f5c
	if (cr6.eq) goto loc_82685F5C;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_82685CA0:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stwx r7,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r7.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x82685ca0
	if (cr6.lt) goto loc_82685CA0;
	// b 0x82685f5c
	goto loc_82685F5C;
loc_82685CC8:
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r26,r31,40
	r26.s64 = r31.s64 + 40;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mulld r9,r8,r29
	ctx.r9.s64 = ctx.r8.s64 * r29.s64;
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// subf r7,r10,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r10.s64;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r8,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r8.u32);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// twllei r5,0
	// rotlwi r11,r6,1
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r4,r6,r5
	ctx.r4.s32 = ctx.r6.s32 / ctx.r5.s32;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// mullw r8,r4,r5
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// subf r11,r8,r6
	r11.s64 = ctx.r6.s64 - ctx.r8.s64;
	// andc r7,r5,r3
	ctx.r7.u64 = ctx.r5.u64 & ~ctx.r3.u64;
	// add r27,r11,r10
	r27.u64 = r11.u64 + ctx.r10.u64;
	// twlgei r7,-1
	// lhz r9,46(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// lwz r28,36(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82685d50
	if (!cr6.eq) goto loc_82685D50;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// sth r28,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r28.u16);
	// beq cr6,0x82685d48
	if (cr6.eq) goto loc_82685D48;
	// rlwinm r3,r28,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82685D44;
	sub_82130528(ctx, base);
	// b 0x82685d4c
	goto loc_82685D4C;
loc_82685D48:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_82685D4C:
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
loc_82685D50:
	// sth r28,4(r26)
	PPC_STORE_U16(r26.u32 + 4, r28.u16);
	// lhz r10,6(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82685d80
	if (!cr6.eq) goto loc_82685D80;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r27,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r27.u16);
	// beq cr6,0x82685d78
	if (cr6.eq) goto loc_82685D78;
	// rlwinm r3,r27,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82685D74;
	sub_82130528(ctx, base);
	// b 0x82685d7c
	goto loc_82685D7C;
loc_82685D78:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_82685D7C:
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
loc_82685D80:
	// sth r27,4(r26)
	PPC_STORE_U16(r26.u32 + 4, r27.u16);
	// lhz r11,44(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// bne cr6,0x82685dcc
	if (!cr6.eq) goto loc_82685DCC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82685f5c
	if (cr6.eq) goto loc_82685F5C;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_82685DA4:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stwx r7,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r7.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x82685da4
	if (cr6.lt) goto loc_82685DA4;
	// b 0x82685f5c
	goto loc_82685F5C;
loc_82685DCC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82685df4
	if (cr6.eq) goto loc_82685DF4;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_82685DD8:
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r25,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, r25.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r8,44(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82685dd8
	if (cr6.lt) goto loc_82685DD8;
loc_82685DF4:
	// lhz r11,44(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// li r8,-1
	ctx.r8.s64 = -1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82685f5c
	if (cr6.eq) goto loc_82685F5C;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_82685E14:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// clrldi r10,r11,32
	ctx.r10.u64 = r11.u64 & 0xFFFFFFFF;
	// bge cr6,0x82685e60
	if (!cr6.lt) goto loc_82685E60;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// mulld r11,r9,r29
	r11.s64 = ctx.r9.s64 * r29.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// twllei r8,0
	// clrlwi r7,r11,1
	ctx.r7.u64 = r11.u32 & 0x7FFFFFFF;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r6,r7,r8
	ctx.r6.s32 = ctx.r7.s32 / ctx.r8.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// mullw r10,r6,r8
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// andc r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// twlgei r8,-1
	// subf r8,r10,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r10.s64;
	// b 0x82685ecc
	goto loc_82685ECC;
loc_82685E60:
	// clrldi r7,r9,32
	ctx.r7.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// mulld r11,r7,r29
	r11.s64 = ctx.r7.s64 * r29.s64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r9,-1
	r11.s64 = ctx.r9.s64 + -1;
	// clrlwi r6,r10,1
	ctx.r6.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// divw r9,r6,r11
	ctx.r9.s32 = ctx.r6.s32 / r11.s32;
	// rotlwi r7,r6,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r9,r9,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r9.s64;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// andc r6,r11,r7
	ctx.r6.u64 = r11.u64 & ~ctx.r7.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// twllei r11,0
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r7,r8,r5
	ctx.r7.s32 = ctx.r8.s32 / ctx.r5.s32;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mullw r7,r7,r5
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// twllei r5,0
	// andc r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 & ~r11.u64;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rldicl r11,r10,32,32
	r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// twlgei r6,-1
	// twlgei r5,-1
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
loc_82685ECC:
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// lhz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82685f20
	if (cr6.eq) goto loc_82685F20;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r28,r8,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwzx r6,r28,r6
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + ctx.r6.u32);
loc_82685EF8:
	// lwz r28,0(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r28,r6
	cr6.compare<uint32_t>(r28.u32, ctx.r6.u32, xer);
	// beq cr6,0x82685f1c
	if (cr6.eq) goto loc_82685F1C;
	// lhz r28,44(r31)
	r28.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r7,r28
	cr6.compare<int32_t>(ctx.r7.s32, r28.s32, xer);
	// blt cr6,0x82685ef8
	if (cr6.lt) goto loc_82685EF8;
	// b 0x82685f20
	goto loc_82685F20;
loc_82685F1C:
	// li r5,1
	ctx.r5.s64 = 1;
loc_82685F20:
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82685f50
	if (!cr6.eq) goto loc_82685F50;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stwx r7,r4,r9
	PPC_STORE_U32(ctx.r4.u32 + ctx.r9.u32, ctx.r7.u32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_82685F50:
	// lhz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// blt cr6,0x82685e14
	if (cr6.lt) goto loc_82685E14;
loc_82685F5C:
	// lhz r11,44(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82686000
	if (cr6.eq) goto loc_82686000;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_82685F70:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82685F88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,44(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x82685f70
	if (cr6.lt) goto loc_82685F70;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82685FA4:
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82685fe0
	if (cr6.eq) goto loc_82685FE0;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_82685FB4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82685FCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x82685fb4
	if (cr6.lt) goto loc_82685FB4;
loc_82685FE0:
	// lhz r10,46(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82685ff8
	if (!cr6.eq) goto loc_82685FF8;
	// sth r25,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r25.u16);
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
loc_82685FF8:
	// sth r25,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r25.u16);
	// stw r25,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r25.u32);
loc_82686000:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82686008"))) PPC_WEAK_FUNC(sub_82686008);
PPC_FUNC_IMPL(__imp__sub_82686008) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// beq cr6,0x8268601c
	if (cr6.eq) goto loc_8268601C;
loc_82686014:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8268601C:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82686014
	if (cr6.eq) goto loc_82686014;
	// cmpwi cr6,r11,-2
	cr6.compare<int32_t>(r11.s32, -2, xer);
	// beq cr6,0x82686038
	if (cr6.eq) goto loc_82686038;
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// bne cr6,0x82686014
	if (!cr6.eq) goto loc_82686014;
loc_82686038:
	// b 0x82685520
	sub_82685520(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8268603C"))) PPC_WEAK_FUNC(sub_8268603C);
PPC_FUNC_IMPL(__imp__sub_8268603C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82686040"))) PPC_WEAK_FUNC(sub_82686040);
PPC_FUNC_IMPL(__imp__sub_82686040) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x82686048;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// clrlwi r28,r30,16
	r28.u64 = r30.u32 & 0xFFFF;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
	// beq cr6,0x8268607c
	if (cr6.eq) goto loc_8268607C;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82686078;
	sub_82130528(ctx, base);
	// b 0x82686080
	goto loc_82686080;
loc_8268607C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82686080:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r29,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r29.u16);
	// sth r28,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r28.u16);
	// beq cr6,0x826860a0
	if (cr6.eq) goto loc_826860A0;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8268609C;
	sub_82130528(ctx, base);
	// b 0x826860a4
	goto loc_826860A4;
loc_826860A0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_826860A4:
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r29,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r29.u16);
	// sth r28,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r28.u16);
	// beq cr6,0x826860c4
	if (cr6.eq) goto loc_826860C4;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826860C0;
	sub_82130528(ctx, base);
	// b 0x826860c8
	goto loc_826860C8;
loc_826860C4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_826860C8:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r29,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r29.u16);
	// sth r28,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r28.u16);
	// beq cr6,0x826860f8
	if (cr6.eq) goto loc_826860F8;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826860E4;
	sub_82130528(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826860F8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82686110"))) PPC_WEAK_FUNC(sub_82686110);
PPC_FUNC_IMPL(__imp__sub_82686110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,60(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 60);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
loc_82686128:
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// add r8,r11,r7
	ctx.r8.u64 = r11.u64 + ctx.r7.u64;
	// lwzx r11,r11,r7
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82686154
	if (cr6.eq) goto loc_82686154;
loc_8268613C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// bne cr6,0x8268613c
	if (!cr6.eq) goto loc_8268613C;
loc_82686154:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// lhz r11,60(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 60);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x82686128
	if (cr6.lt) goto loc_82686128;
	// blr 
	return;
}

