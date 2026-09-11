#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_827B58A8) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,29492
	r31.s64 = r11.s64 + 29492;
	// addi r5,r10,3356
	ctx.r5.s64 = ctx.r10.s64 + 3356;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B58D4;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B58E8;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B58A8) {
	__imp__sub_827B58A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B58FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B58FC) {
	__imp__sub_827B58FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-10336
	ctx.r5.s64 = r11.s64 + -10336;
	// addi r3,r10,28956
	ctx.r3.s64 = ctx.r10.s64 + 28956;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B5900) {
	__imp__sub_827B5900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5918) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,28300
	r31.s64 = r11.s64 + 28300;
	// addi r5,r10,3372
	ctx.r5.s64 = ctx.r10.s64 + 3372;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5944;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5958;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3328
	ctx.r5.s64 = ctx.r8.s64 + 3328;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B596C;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5918) {
	__imp__sub_827B5918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5980) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,28932
	r31.s64 = r11.s64 + 28932;
	// addi r5,r10,3372
	ctx.r5.s64 = ctx.r10.s64 + 3372;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B59AC;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B59C0;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3384
	ctx.r5.s64 = ctx.r8.s64 + 3384;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B59D4;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5980) {
	__imp__sub_827B5980(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B59E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-3672
	ctx.r5.s64 = r11.s64 + -3672;
	// addi r3,r10,28644
	ctx.r3.s64 = ctx.r10.s64 + 28644;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B59E8) {
	__imp__sub_827B59E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5A00) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29196
	r31.s64 = r11.s64 + 29196;
	// addi r5,r10,-10336
	ctx.r5.s64 = ctx.r10.s64 + -10336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B5A2C;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r9,-11144
	ctx.r5.s64 = ctx.r9.s64 + -11144;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5A40;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5A00) {
	__imp__sub_827B5A00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B5A54) {
	__imp__sub_827B5A54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-10336
	ctx.r5.s64 = r11.s64 + -10336;
	// addi r3,r10,27980
	ctx.r3.s64 = ctx.r10.s64 + 27980;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B5A58) {
	__imp__sub_827B5A58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5A70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3396
	ctx.r5.s64 = r11.s64 + 3396;
	// addi r3,r10,28540
	ctx.r3.s64 = ctx.r10.s64 + 28540;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B5A70) {
	__imp__sub_827B5A70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5A88) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29060
	r31.s64 = r11.s64 + 29060;
	// addi r5,r10,-11288
	ctx.r5.s64 = ctx.r10.s64 + -11288;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5AB4;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5AC8;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3476
	ctx.r5.s64 = ctx.r8.s64 + 3476;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5ADC;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3456
	ctx.r5.s64 = ctx.r7.s64 + 3456;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5AF0;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r6,3436
	ctx.r5.s64 = ctx.r6.s64 + 3436;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B5B04;
	sub_82630CA0(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r5,3416
	ctx.r5.s64 = ctx.r5.s64 + 3416;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x82630ca0
	ctx.lr = 0x827B5B18;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5A88) {
	__imp__sub_827B5A88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B5B2C) {
	__imp__sub_827B5B2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5B30) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28596
	r31.s64 = r11.s64 + 28596;
	// addi r5,r10,-11288
	ctx.r5.s64 = ctx.r10.s64 + -11288;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5B5C;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,3532
	ctx.r5.s64 = ctx.r9.s64 + 3532;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5B70;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3512
	ctx.r5.s64 = ctx.r8.s64 + 3512;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5B84;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3496
	ctx.r5.s64 = ctx.r7.s64 + 3496;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5B98;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r6,3436
	ctx.r5.s64 = ctx.r6.s64 + 3436;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B5BAC;
	sub_82630CA0(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r5,3416
	ctx.r5.s64 = ctx.r5.s64 + 3416;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x82630ca0
	ctx.lr = 0x827B5BC0;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5B30) {
	__imp__sub_827B5B30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B5BD4) {
	__imp__sub_827B5BD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5BD8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29420
	r31.s64 = r11.s64 + 29420;
	// addi r5,r10,-11288
	ctx.r5.s64 = ctx.r10.s64 + -11288;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5C04;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5C18;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3476
	ctx.r5.s64 = ctx.r8.s64 + 3476;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5C2C;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3496
	ctx.r5.s64 = ctx.r7.s64 + 3496;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5C40;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r6,3436
	ctx.r5.s64 = ctx.r6.s64 + 3436;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B5C54;
	sub_82630CA0(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r5,3416
	ctx.r5.s64 = ctx.r5.s64 + 3416;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x82630ca0
	ctx.lr = 0x827B5C68;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5BD8) {
	__imp__sub_827B5BD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B5C7C) {
	__imp__sub_827B5C7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5C80) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29236
	r31.s64 = r11.s64 + 29236;
	// addi r5,r10,-10336
	ctx.r5.s64 = ctx.r10.s64 + -10336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B5CAC;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,3476
	ctx.r5.s64 = ctx.r9.s64 + 3476;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5CC0;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3456
	ctx.r5.s64 = ctx.r8.s64 + 3456;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5CD4;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r7,3436
	ctx.r5.s64 = ctx.r7.s64 + 3436;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5CE8;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r6,3416
	ctx.r5.s64 = ctx.r6.s64 + 3416;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B5CFC;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5C80) {
	__imp__sub_827B5C80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5D10) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,28756
	r31.s64 = r11.s64 + 28756;
	// addi r5,r10,3532
	ctx.r5.s64 = ctx.r10.s64 + 3532;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B5D3C;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,3512
	ctx.r5.s64 = ctx.r9.s64 + 3512;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5D50;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3496
	ctx.r5.s64 = ctx.r8.s64 + 3496;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5D64;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r7,3436
	ctx.r5.s64 = ctx.r7.s64 + 3436;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5D78;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r6,3416
	ctx.r5.s64 = ctx.r6.s64 + 3416;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B5D8C;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5D10) {
	__imp__sub_827B5D10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5DA0) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29020
	r31.s64 = r11.s64 + 29020;
	// addi r5,r10,-10336
	ctx.r5.s64 = ctx.r10.s64 + -10336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B5DCC;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,3476
	ctx.r5.s64 = ctx.r9.s64 + 3476;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5DE0;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3496
	ctx.r5.s64 = ctx.r8.s64 + 3496;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5DF4;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r7,3436
	ctx.r5.s64 = ctx.r7.s64 + 3436;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5E08;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r6,3416
	ctx.r5.s64 = ctx.r6.s64 + 3416;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B5E1C;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5DA0) {
	__imp__sub_827B5DA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5E30) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28652
	r31.s64 = r11.s64 + 28652;
	// addi r5,r10,-11288
	ctx.r5.s64 = ctx.r10.s64 + -11288;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5E5C;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5E70;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5E30) {
	__imp__sub_827B5E30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B5E84) {
	__imp__sub_827B5E84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5E88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-10336
	ctx.r5.s64 = r11.s64 + -10336;
	// addi r3,r10,29012
	ctx.r3.s64 = ctx.r10.s64 + 29012;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B5E88) {
	__imp__sub_827B5E88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5EA0) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29148
	r31.s64 = r11.s64 + 29148;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5ECC;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5EE0;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5EA0) {
	__imp__sub_827B5EA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B5EF4) {
	__imp__sub_827B5EF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5EF8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28180
	r31.s64 = r11.s64 + 28180;
	// addi r5,r10,-11288
	ctx.r5.s64 = ctx.r10.s64 + -11288;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5F24;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5F38;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3476
	ctx.r5.s64 = ctx.r8.s64 + 3476;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5F4C;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3456
	ctx.r5.s64 = ctx.r7.s64 + 3456;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5F60;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r6,3436
	ctx.r5.s64 = ctx.r6.s64 + 3436;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B5F74;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5EF8) {
	__imp__sub_827B5EF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B5F88) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28220
	r31.s64 = r11.s64 + 28220;
	// addi r5,r10,-11288
	ctx.r5.s64 = ctx.r10.s64 + -11288;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5FB4;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,3532
	ctx.r5.s64 = ctx.r9.s64 + 3532;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5FC8;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3512
	ctx.r5.s64 = ctx.r8.s64 + 3512;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5FDC;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3496
	ctx.r5.s64 = ctx.r7.s64 + 3496;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5FF0;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r6,3436
	ctx.r5.s64 = ctx.r6.s64 + 3436;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B6004;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B5F88) {
	__imp__sub_827B5F88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6018) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28444
	r31.s64 = r11.s64 + 28444;
	// addi r5,r10,-11288
	ctx.r5.s64 = ctx.r10.s64 + -11288;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B6044;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6058;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3476
	ctx.r5.s64 = ctx.r8.s64 + 3476;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B606C;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3496
	ctx.r5.s64 = ctx.r7.s64 + 3496;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B6080;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r6,3436
	ctx.r5.s64 = ctx.r6.s64 + 3436;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B6094;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6018) {
	__imp__sub_827B6018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B60A8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28828
	r31.s64 = r11.s64 + 28828;
	// addi r5,r10,-10336
	ctx.r5.s64 = ctx.r10.s64 + -10336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B60D4;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,3476
	ctx.r5.s64 = ctx.r9.s64 + 3476;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B60E8;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3456
	ctx.r5.s64 = ctx.r8.s64 + 3456;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B60FC;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r7,3436
	ctx.r5.s64 = ctx.r7.s64 + 3436;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B6110;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B60A8) {
	__imp__sub_827B60A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6124) {
	__imp__sub_827B6124(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6128) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,28796
	r31.s64 = r11.s64 + 28796;
	// addi r5,r10,3532
	ctx.r5.s64 = ctx.r10.s64 + 3532;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B6154;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,3512
	ctx.r5.s64 = ctx.r9.s64 + 3512;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6168;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3496
	ctx.r5.s64 = ctx.r8.s64 + 3496;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B617C;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r7,3436
	ctx.r5.s64 = ctx.r7.s64 + 3436;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B6190;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6128) {
	__imp__sub_827B6128(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B61A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B61A4) {
	__imp__sub_827B61A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B61A8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29116
	r31.s64 = r11.s64 + 29116;
	// addi r5,r10,-10336
	ctx.r5.s64 = ctx.r10.s64 + -10336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B61D4;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,3476
	ctx.r5.s64 = ctx.r9.s64 + 3476;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B61E8;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3496
	ctx.r5.s64 = ctx.r8.s64 + 3496;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B61FC;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r7,3436
	ctx.r5.s64 = ctx.r7.s64 + 3436;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B6210;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B61A8) {
	__imp__sub_827B61A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6224) {
	__imp__sub_827B6224(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6228) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,28164
	r31.s64 = r11.s64 + 28164;
	// addi r5,r10,3544
	ctx.r5.s64 = ctx.r10.s64 + 3544;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B6254;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6268;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6228) {
	__imp__sub_827B6228(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B627C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B627C) {
	__imp__sub_827B627C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-10336
	ctx.r5.s64 = r11.s64 + -10336;
	// addi r3,r10,28716
	ctx.r3.s64 = ctx.r10.s64 + 28716;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6280) {
	__imp__sub_827B6280(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3576
	ctx.r5.s64 = r11.s64 + 3576;
	// addi r3,r10,28156
	ctx.r3.s64 = ctx.r10.s64 + 28156;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6298) {
	__imp__sub_827B6298(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B62B0) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,29364
	r31.s64 = r11.s64 + 29364;
	// addi r5,r10,3544
	ctx.r5.s64 = ctx.r10.s64 + 3544;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B62DC;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B62F0;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3608
	ctx.r5.s64 = ctx.r8.s64 + 3608;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B6304;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r7,3340
	ctx.r5.s64 = ctx.r7.s64 + 3340;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B6318;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B62B0) {
	__imp__sub_827B62B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B632C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B632C) {
	__imp__sub_827B632C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6330) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r31,r10,28052
	r31.s64 = ctx.r10.s64 + 28052;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,28872(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28872);
	// bl 0x82630ca0
	ctx.lr = 0x827B635C;
	sub_82630CA0(ctx, base);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// lwz r5,28876(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28876);
	// bl 0x82630ca0
	ctx.lr = 0x827B6370;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r8,3640
	ctx.r5.s64 = ctx.r8.s64 + 3640;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B6384;
	sub_82630CA0(ctx, base);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// li r4,9
	ctx.r4.s64 = 9;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// lwz r5,28880(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28880);
	// bl 0x82630ca0
	ctx.lr = 0x827B6398;
	sub_82630CA0(ctx, base);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// lwz r5,28884(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28884);
	// bl 0x82630ca0
	ctx.lr = 0x827B63AC;
	sub_82630CA0(ctx, base);
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// lwz r5,28888(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28888);
	// bl 0x82630ca0
	ctx.lr = 0x827B63C0;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6330) {
	__imp__sub_827B6330(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B63D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B63D4) {
	__imp__sub_827B63D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B63D8) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r31,r10,29300
	r31.s64 = ctx.r10.s64 + 29300;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,28872(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28872);
	// bl 0x82630ca0
	ctx.lr = 0x827B6404;
	sub_82630CA0(ctx, base);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// lwz r5,28876(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28876);
	// bl 0x82630ca0
	ctx.lr = 0x827B6418;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r8,3680
	ctx.r5.s64 = ctx.r8.s64 + 3680;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B642C;
	sub_82630CA0(ctx, base);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// li r4,9
	ctx.r4.s64 = 9;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// lwz r5,28880(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28880);
	// bl 0x82630ca0
	ctx.lr = 0x827B6440;
	sub_82630CA0(ctx, base);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// lwz r5,28884(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28884);
	// bl 0x82630ca0
	ctx.lr = 0x827B6454;
	sub_82630CA0(ctx, base);
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// lwz r5,28888(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28888);
	// bl 0x82630ca0
	ctx.lr = 0x827B6468;
	sub_82630CA0(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// li r4,11
	ctx.r4.s64 = 11;
	// addi r5,r3,3660
	ctx.r5.s64 = ctx.r3.s64 + 3660;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82630ca0
	ctx.lr = 0x827B647C;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B63D8) {
	__imp__sub_827B63D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3704
	ctx.r5.s64 = r11.s64 + 3704;
	// addi r3,r10,29484
	ctx.r3.s64 = ctx.r10.s64 + 29484;
	// li r4,10
	ctx.r4.s64 = 10;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6490) {
	__imp__sub_827B6490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B64A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-10336
	ctx.r5.s64 = r11.s64 + -10336;
	// addi r3,r10,29228
	ctx.r3.s64 = ctx.r10.s64 + 29228;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B64A8) {
	__imp__sub_827B64A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B64C0) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,28964
	r31.s64 = r11.s64 + 28964;
	// addi r5,r10,3728
	ctx.r5.s64 = ctx.r10.s64 + 3728;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B64EC;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6500;
	sub_82630CA0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,5716
	ctx.r5.s64 = ctx.r8.s64 + 5716;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B6514;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B64C0) {
	__imp__sub_827B64C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6528) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,28100
	r31.s64 = r11.s64 + 28100;
	// addi r5,r10,3752
	ctx.r5.s64 = ctx.r10.s64 + 3752;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B6554;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6568;
	sub_82630CA0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3968
	ctx.r5.s64 = ctx.r8.s64 + 3968;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B657C;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6528) {
	__imp__sub_827B6528(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6590) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28372
	r31.s64 = r11.s64 + 28372;
	// addi r5,r10,-10336
	ctx.r5.s64 = ctx.r10.s64 + -10336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B65BC;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r9,3416
	ctx.r5.s64 = ctx.r9.s64 + 3416;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B65D0;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6590) {
	__imp__sub_827B6590(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B65E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B65E4) {
	__imp__sub_827B65E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B65E8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29164
	r31.s64 = r11.s64 + 29164;
	// addi r5,r10,-10336
	ctx.r5.s64 = ctx.r10.s64 + -10336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B6614;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r9,-10592
	ctx.r5.s64 = ctx.r9.s64 + -10592;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6628;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B65E8) {
	__imp__sub_827B65E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B663C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B663C) {
	__imp__sub_827B663C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6640) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,28988
	r31.s64 = r11.s64 + 28988;
	// addi r5,r10,3356
	ctx.r5.s64 = ctx.r10.s64 + 3356;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B666C;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6680;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3300
	ctx.r5.s64 = ctx.r8.s64 + 3300;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B6694;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6640) {
	__imp__sub_827B6640(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B66A8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28484
	r31.s64 = r11.s64 + 28484;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B66D4;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,3776
	ctx.r5.s64 = ctx.r9.s64 + 3776;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B66E8;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B66A8) {
	__imp__sub_827B66A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B66FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B66FC) {
	__imp__sub_827B66FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6700) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,29212
	r31.s64 = r11.s64 + 29212;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B672C;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10644
	ctx.r5.s64 = ctx.r9.s64 + -10644;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6740;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6700) {
	__imp__sub_827B6700(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6754) {
	__imp__sub_827B6754(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3796
	ctx.r5.s64 = r11.s64 + 3796;
	// addi r3,r10,28532
	ctx.r3.s64 = ctx.r10.s64 + 28532;
	// li r4,10
	ctx.r4.s64 = 10;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6758) {
	__imp__sub_827B6758(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-3672
	ctx.r5.s64 = r11.s64 + -3672;
	// addi r3,r10,28348
	ctx.r3.s64 = ctx.r10.s64 + 28348;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6770) {
	__imp__sub_827B6770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3816
	ctx.r5.s64 = r11.s64 + 3816;
	// addi r3,r10,28436
	ctx.r3.s64 = ctx.r10.s64 + 28436;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6788) {
	__imp__sub_827B6788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B67A0) {
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
	// addi r31,r11,28412
	r31.s64 = r11.s64 + 28412;
	// addi r5,r10,-3672
	ctx.r5.s64 = ctx.r10.s64 + -3672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B67CC;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r5,r9,3840
	ctx.r5.s64 = ctx.r9.s64 + 3840;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B67E0;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B67A0) {
	__imp__sub_827B67A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B67F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B67F4) {
	__imp__sub_827B67F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B67F8) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r31,r11,29468
	r31.s64 = r11.s64 + 29468;
	// addi r5,r10,3840
	ctx.r5.s64 = ctx.r10.s64 + 3840;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82630ca0
	ctx.lr = 0x827B6824;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r5,r9,3872
	ctx.r5.s64 = ctx.r9.s64 + 3872;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6838;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B67F8) {
	__imp__sub_827B67F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B684C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B684C) {
	__imp__sub_827B684C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3872
	ctx.r5.s64 = r11.s64 + 3872;
	// addi r3,r10,29356
	ctx.r3.s64 = ctx.r10.s64 + 29356;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6850) {
	__imp__sub_827B6850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6868) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-10492
	ctx.r5.s64 = r11.s64 + -10492;
	// addi r3,r10,28724
	ctx.r3.s64 = ctx.r10.s64 + 28724;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6868) {
	__imp__sub_827B6868(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6880) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-10492
	ctx.r5.s64 = r11.s64 + -10492;
	// addi r3,r10,28428
	ctx.r3.s64 = ctx.r10.s64 + 28428;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6880) {
	__imp__sub_827B6880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6898) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3896
	ctx.r5.s64 = r11.s64 + 3896;
	// addi r3,r10,29108
	ctx.r3.s64 = ctx.r10.s64 + 29108;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6898) {
	__imp__sub_827B6898(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B68B0) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28260
	r31.s64 = r11.s64 + 28260;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B68DC;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B68F0;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3920
	ctx.r5.s64 = ctx.r8.s64 + 3920;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B6904;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B68B0) {
	__imp__sub_827B68B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6918) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,28732
	r31.s64 = r11.s64 + 28732;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B6944;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-10336
	ctx.r5.s64 = ctx.r9.s64 + -10336;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B6958;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3936
	ctx.r5.s64 = ctx.r8.s64 + 3936;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B696C;
	sub_82630CA0(ctx, base);
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

PPC_WEAK_FUNC(sub_827B6918) {
	__imp__sub_827B6918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,13892
	ctx.r5.s64 = r11.s64 + 13892;
	// addi r3,r10,29540
	ctx.r3.s64 = ctx.r10.s64 + 29540;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6980) {
	__imp__sub_827B6980(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B699C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B699C) {
	__imp__sub_827B699C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B69A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,13904
	ctx.r5.s64 = r11.s64 + 13904;
	// addi r3,r10,29520
	ctx.r3.s64 = ctx.r10.s64 + 29520;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B69A0) {
	__imp__sub_827B69A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B69BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B69BC) {
	__imp__sub_827B69BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B69C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-31824
	ctx.r7.s64 = ctx.r8.s64 + -31824;
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

PPC_WEAK_FUNC(sub_827B69C0) {
	__imp__sub_827B69C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B69E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-31524
	ctx.r7.s64 = ctx.r8.s64 + -31524;
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

PPC_WEAK_FUNC(sub_827B69E0) {
	__imp__sub_827B69E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6A00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-31228
	ctx.r7.s64 = ctx.r8.s64 + -31228;
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

PPC_WEAK_FUNC(sub_827B6A00) {
	__imp__sub_827B6A00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6A20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-31032
	ctx.r7.s64 = ctx.r8.s64 + -31032;
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

PPC_WEAK_FUNC(sub_827B6A20) {
	__imp__sub_827B6A20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6A40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-30988
	ctx.r7.s64 = ctx.r8.s64 + -30988;
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

PPC_WEAK_FUNC(sub_827B6A40) {
	__imp__sub_827B6A40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6A60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-30772
	ctx.r7.s64 = ctx.r8.s64 + -30772;
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

PPC_WEAK_FUNC(sub_827B6A60) {
	__imp__sub_827B6A60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6A80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-30700
	ctx.r7.s64 = ctx.r8.s64 + -30700;
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

PPC_WEAK_FUNC(sub_827B6A80) {
	__imp__sub_827B6A80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-30584
	ctx.r7.s64 = ctx.r8.s64 + -30584;
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

PPC_WEAK_FUNC(sub_827B6AA0) {
	__imp__sub_827B6AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-30500
	ctx.r7.s64 = ctx.r8.s64 + -30500;
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

PPC_WEAK_FUNC(sub_827B6AC0) {
	__imp__sub_827B6AC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-30344
	ctx.r7.s64 = ctx.r8.s64 + -30344;
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

PPC_WEAK_FUNC(sub_827B6AE0) {
	__imp__sub_827B6AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6B00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,30480
	ctx.r9.s64 = ctx.r10.s64 + 30480;
	// stw r11,30480(r10)
	PPC_STORE_U32(ctx.r10.u32 + 30480, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827B6B00) {
	__imp__sub_827B6B00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6B18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-30236
	ctx.r7.s64 = ctx.r8.s64 + -30236;
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

PPC_WEAK_FUNC(sub_827B6B18) {
	__imp__sub_827B6B18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-30068
	ctx.r7.s64 = ctx.r8.s64 + -30068;
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

PPC_WEAK_FUNC(sub_827B6B38) {
	__imp__sub_827B6B38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6B58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,28896
	ctx.r5.s64 = r11.s64 + 28896;
	// addi r3,r10,-30864
	ctx.r3.s64 = ctx.r10.s64 + -30864;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6B58) {
	__imp__sub_827B6B58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6B74) {
	__imp__sub_827B6B74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6B78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,31504
	ctx.r5.s64 = r11.s64 + 31504;
	// addi r3,r10,-29548
	ctx.r3.s64 = ctx.r10.s64 + -29548;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6B78) {
	__imp__sub_827B6B78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6B94) {
	__imp__sub_827B6B94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6B98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,32248
	ctx.r5.s64 = r11.s64 + 32248;
	// addi r3,r10,-29520
	ctx.r3.s64 = ctx.r10.s64 + -29520;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6B98) {
	__imp__sub_827B6B98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6BB4) {
	__imp__sub_827B6BB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-22892
	ctx.r5.s64 = r11.s64 + -22892;
	// addi r3,r10,-29332
	ctx.r3.s64 = ctx.r10.s64 + -29332;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6BB8) {
	__imp__sub_827B6BB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6BD4) {
	__imp__sub_827B6BD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6BD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-22876
	ctx.r5.s64 = r11.s64 + -22876;
	// addi r3,r10,-29168
	ctx.r3.s64 = ctx.r10.s64 + -29168;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6BD8) {
	__imp__sub_827B6BD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6BF4) {
	__imp__sub_827B6BF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6BF8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r31,9
	r31.s64 = 9;
	// addi r30,r11,-29096
	r30.s64 = r11.s64 + -29096;
loc_827B6C18:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f5c00
	ctx.lr = 0x827B6C20;
	sub_824F5C00(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,152
	r30.s64 = r30.s64 + 152;
	// bge 0x827b6c18
	if (!cr0.lt) goto loc_827B6C18;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827B6BF8) {
	__imp__sub_827B6BF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6C44) {
	__imp__sub_827B6C44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,13184
	ctx.r5.s64 = r11.s64 + 13184;
	// addi r3,r10,-27500
	ctx.r3.s64 = ctx.r10.s64 + -27500;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6C48) {
	__imp__sub_827B6C48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6C64) {
	__imp__sub_827B6C64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10616
	ctx.r5.s64 = r11.s64 + -10616;
	// addi r3,r10,-27408
	ctx.r3.s64 = ctx.r10.s64 + -27408;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6C68) {
	__imp__sub_827B6C68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6C84) {
	__imp__sub_827B6C84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6C88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10604
	ctx.r5.s64 = r11.s64 + -10604;
	// addi r3,r10,-27328
	ctx.r3.s64 = ctx.r10.s64 + -27328;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6C88) {
	__imp__sub_827B6C88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6CA4) {
	__imp__sub_827B6CA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6CA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10596
	ctx.r5.s64 = r11.s64 + -10596;
	// addi r3,r10,-27308
	ctx.r3.s64 = ctx.r10.s64 + -27308;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6CA8) {
	__imp__sub_827B6CA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6CC4) {
	__imp__sub_827B6CC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6CC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10584
	ctx.r5.s64 = r11.s64 + -10584;
	// addi r3,r10,-27348
	ctx.r3.s64 = ctx.r10.s64 + -27348;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6CC8) {
	__imp__sub_827B6CC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6CE4) {
	__imp__sub_827B6CE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6CE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10568
	ctx.r5.s64 = r11.s64 + -10568;
	// addi r3,r10,-27448
	ctx.r3.s64 = ctx.r10.s64 + -27448;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6CE8) {
	__imp__sub_827B6CE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6D04) {
	__imp__sub_827B6D04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10552
	ctx.r5.s64 = r11.s64 + -10552;
	// addi r3,r10,-27368
	ctx.r3.s64 = ctx.r10.s64 + -27368;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6D08) {
	__imp__sub_827B6D08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6D24) {
	__imp__sub_827B6D24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10540
	ctx.r5.s64 = r11.s64 + -10540;
	// addi r3,r10,-27428
	ctx.r3.s64 = ctx.r10.s64 + -27428;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6D28) {
	__imp__sub_827B6D28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6D44) {
	__imp__sub_827B6D44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10520
	ctx.r5.s64 = r11.s64 + -10520;
	// addi r3,r10,-27468
	ctx.r3.s64 = ctx.r10.s64 + -27468;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6D48) {
	__imp__sub_827B6D48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6D64) {
	__imp__sub_827B6D64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-10508
	ctx.r5.s64 = r11.s64 + -10508;
	// addi r3,r10,-27388
	ctx.r3.s64 = ctx.r10.s64 + -27388;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6D68) {
	__imp__sub_827B6D68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6D84) {
	__imp__sub_827B6D84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6D88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-7648
	ctx.r5.s64 = r11.s64 + -7648;
	// addi r3,r10,-27256
	ctx.r3.s64 = ctx.r10.s64 + -27256;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B6D88) {
	__imp__sub_827B6D88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6DA4) {
	__imp__sub_827B6DA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6DA8) {
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
	// lis r11,-32148
	r11.s64 = -2106851328;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,31536
	ctx.r5.s64 = r11.s64 + 31536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B6DD0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-25236
	r11.s64 = ctx.r7.s64 + -25236;
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

PPC_WEAK_FUNC(sub_827B6DA8) {
	__imp__sub_827B6DA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6E1C) {
	__imp__sub_827B6E1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6E20) {
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
	// lis r11,-32148
	r11.s64 = -2106851328;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,31536
	ctx.r5.s64 = r11.s64 + 31536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B6E48;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-25188
	r11.s64 = ctx.r7.s64 + -25188;
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

PPC_WEAK_FUNC(sub_827B6E20) {
	__imp__sub_827B6E20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6E94) {
	__imp__sub_827B6E94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6E98) {
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
	ctx.lr = 0x827B6EC0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-25140
	r11.s64 = ctx.r7.s64 + -25140;
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

PPC_WEAK_FUNC(sub_827B6E98) {
	__imp__sub_827B6E98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6F0C) {
	__imp__sub_827B6F0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6F10) {
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
	ctx.lr = 0x827B6F38;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-25092
	r11.s64 = ctx.r7.s64 + -25092;
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

PPC_WEAK_FUNC(sub_827B6F10) {
	__imp__sub_827B6F10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6F84) {
	__imp__sub_827B6F84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6F88) {
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
	ctx.lr = 0x827B6FB0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-25044
	r11.s64 = ctx.r7.s64 + -25044;
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

PPC_WEAK_FUNC(sub_827B6F88) {
	__imp__sub_827B6F88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B6FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B6FFC) {
	__imp__sub_827B6FFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7000) {
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
	ctx.lr = 0x827B7028;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-24452
	r11.s64 = ctx.r7.s64 + -24452;
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

PPC_WEAK_FUNC(sub_827B7000) {
	__imp__sub_827B7000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7074) {
	__imp__sub_827B7074(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7078) {
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
	ctx.lr = 0x827B70A0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-24404
	r11.s64 = ctx.r7.s64 + -24404;
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

PPC_WEAK_FUNC(sub_827B7078) {
	__imp__sub_827B7078(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B70EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B70EC) {
	__imp__sub_827B70EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B70F0) {
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
	ctx.lr = 0x827B7118;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-22808
	r11.s64 = ctx.r7.s64 + -22808;
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

PPC_WEAK_FUNC(sub_827B70F0) {
	__imp__sub_827B70F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7164) {
	__imp__sub_827B7164(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,5592
	ctx.r5.s64 = r11.s64 + 5592;
	// addi r3,r10,-27116
	ctx.r3.s64 = ctx.r10.s64 + -27116;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7168) {
	__imp__sub_827B7168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7184) {
	__imp__sub_827B7184(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,5612
	ctx.r5.s64 = r11.s64 + 5612;
	// addi r3,r10,-27136
	ctx.r3.s64 = ctx.r10.s64 + -27136;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7188) {
	__imp__sub_827B7188(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B71A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B71A4) {
	__imp__sub_827B71A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B71A8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r11,-27096
	ctx.r3.s64 = r11.s64 + -27096;
	// li r5,4
	ctx.r5.s64 = 4;
	// lis r4,184
	ctx.r4.s64 = 12058624;
	// bl 0x821c2e60
	ctx.lr = 0x827B71CC;
	sub_821C2E60(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-13888
	ctx.r3.s64 = ctx.r10.s64 + -13888;
	// bl 0x823d9a98
	ctx.lr = 0x827B71D8;
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

PPC_WEAK_FUNC(sub_827B71A8) {
	__imp__sub_827B71A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B71E8) {
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
	// lis r11,-32146
	r11.s64 = -2106720256;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-20248
	ctx.r5.s64 = r11.s64 + -20248;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7210;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-21488
	r11.s64 = ctx.r7.s64 + -21488;
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

PPC_WEAK_FUNC(sub_827B71E8) {
	__imp__sub_827B71E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B725C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B725C) {
	__imp__sub_827B725C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7260) {
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
	// lis r11,-32146
	r11.s64 = -2106720256;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-16048
	ctx.r5.s64 = r11.s64 + -16048;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7288;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-21440
	r11.s64 = ctx.r7.s64 + -21440;
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

PPC_WEAK_FUNC(sub_827B7260) {
	__imp__sub_827B7260(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B72D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B72D4) {
	__imp__sub_827B72D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B72D8) {
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
	// lis r11,-32146
	r11.s64 = -2106720256;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-20248
	ctx.r5.s64 = r11.s64 + -20248;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7300;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-21392
	r11.s64 = ctx.r7.s64 + -21392;
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

PPC_WEAK_FUNC(sub_827B72D8) {
	__imp__sub_827B72D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B734C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B734C) {
	__imp__sub_827B734C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7350) {
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
	// lis r11,-32232
	r11.s64 = -2112356352;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,21256
	ctx.r5.s64 = r11.s64 + 21256;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7378;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-21344
	r11.s64 = ctx.r7.s64 + -21344;
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

PPC_WEAK_FUNC(sub_827B7350) {
	__imp__sub_827B7350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B73C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B73C4) {
	__imp__sub_827B73C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B73C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-21296
	ctx.r7.s64 = ctx.r8.s64 + -21296;
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

PPC_WEAK_FUNC(sub_827B73C8) {
	__imp__sub_827B73C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B73E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-21288
	ctx.r7.s64 = ctx.r8.s64 + -21288;
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

PPC_WEAK_FUNC(sub_827B73E8) {
	__imp__sub_827B73E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7408) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-21280
	ctx.r7.s64 = ctx.r8.s64 + -21280;
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

PPC_WEAK_FUNC(sub_827B7408) {
	__imp__sub_827B7408(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-21272
	ctx.r7.s64 = ctx.r8.s64 + -21272;
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

PPC_WEAK_FUNC(sub_827B7428) {
	__imp__sub_827B7428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-19816
	ctx.r7.s64 = ctx.r8.s64 + -19816;
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

PPC_WEAK_FUNC(sub_827B7448) {
	__imp__sub_827B7448(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-19808
	ctx.r7.s64 = ctx.r8.s64 + -19808;
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

PPC_WEAK_FUNC(sub_827B7468) {
	__imp__sub_827B7468(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-19496
	ctx.r7.s64 = ctx.r8.s64 + -19496;
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

PPC_WEAK_FUNC(sub_827B7488) {
	__imp__sub_827B7488(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B74A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,12952
	ctx.r5.s64 = r11.s64 + 12952;
	// addi r3,r10,-24696
	ctx.r3.s64 = ctx.r10.s64 + -24696;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B74A8) {
	__imp__sub_827B74A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B74C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B74C4) {
	__imp__sub_827B74C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B74C8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r31,-24664
	r30.s64 = r31.s64 + -24664;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13364
	ctx.r5.s64 = ctx.r10.s64 + 13364;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B7500;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24664(r31)
	PPC_STORE_U32(r31.u32 + -24664, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B7510;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B7518;
	sub_824FA6C0(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13360
	r11.s64 = r11.s64 + 13360;
	// addi r3,r9,-13848
	ctx.r3.s64 = ctx.r9.s64 + -13848;
	// stw r11,-24664(r31)
	PPC_STORE_U32(r31.u32 + -24664, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B7530;
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

PPC_WEAK_FUNC(sub_827B74C8) {
	__imp__sub_827B74C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7548) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r31,-24632
	r30.s64 = r31.s64 + -24632;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13392
	ctx.r5.s64 = ctx.r10.s64 + 13392;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B7580;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24632(r31)
	PPC_STORE_U32(r31.u32 + -24632, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B7590;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B7598;
	sub_824FA6C0(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13388
	r11.s64 = r11.s64 + 13388;
	// addi r3,r9,-13760
	ctx.r3.s64 = ctx.r9.s64 + -13760;
	// stw r11,-24632(r31)
	PPC_STORE_U32(r31.u32 + -24632, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B75B0;
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

PPC_WEAK_FUNC(sub_827B7548) {
	__imp__sub_827B7548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B75C8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r31,-24600
	r30.s64 = r31.s64 + -24600;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13428
	ctx.r5.s64 = ctx.r10.s64 + 13428;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B7600;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24600(r31)
	PPC_STORE_U32(r31.u32 + -24600, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B7610;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B7618;
	sub_824FA6C0(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13424
	r11.s64 = r11.s64 + 13424;
	// addi r3,r9,-13672
	ctx.r3.s64 = ctx.r9.s64 + -13672;
	// stw r11,-24600(r31)
	PPC_STORE_U32(r31.u32 + -24600, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B7630;
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

PPC_WEAK_FUNC(sub_827B75C8) {
	__imp__sub_827B75C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7648) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r31,-24568
	r30.s64 = r31.s64 + -24568;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13464
	ctx.r5.s64 = ctx.r10.s64 + 13464;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B7680;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24568(r31)
	PPC_STORE_U32(r31.u32 + -24568, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B7690;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B7698;
	sub_824FA6C0(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13460
	r11.s64 = r11.s64 + 13460;
	// addi r3,r9,-13584
	ctx.r3.s64 = ctx.r9.s64 + -13584;
	// stw r11,-24568(r31)
	PPC_STORE_U32(r31.u32 + -24568, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B76B0;
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

PPC_WEAK_FUNC(sub_827B7648) {
	__imp__sub_827B7648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B76C8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r31,-24536
	r30.s64 = r31.s64 + -24536;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13500
	ctx.r5.s64 = ctx.r10.s64 + 13500;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B7700;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,-24536(r31)
	PPC_STORE_U32(r31.u32 + -24536, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B7710;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B7718;
	sub_824FA6C0(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13496
	r11.s64 = r11.s64 + 13496;
	// addi r3,r9,-13496
	ctx.r3.s64 = ctx.r9.s64 + -13496;
	// stw r11,-24536(r31)
	PPC_STORE_U32(r31.u32 + -24536, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B7730;
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

PPC_WEAK_FUNC(sub_827B76C8) {
	__imp__sub_827B76C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13872
	ctx.r3.s64 = r11.s64 + -13872;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7748) {
	__imp__sub_827B7748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7754) {
	__imp__sub_827B7754(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-17680
	ctx.r7.s64 = ctx.r8.s64 + -17680;
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

PPC_WEAK_FUNC(sub_827B7758) {
	__imp__sub_827B7758(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7778) {
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
	// lis r11,-32144
	r11.s64 = -2106589184;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-30432
	ctx.r5.s64 = r11.s64 + -30432;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B77A0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-17360
	r11.s64 = ctx.r7.s64 + -17360;
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

PPC_WEAK_FUNC(sub_827B7778) {
	__imp__sub_827B7778(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B77EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B77EC) {
	__imp__sub_827B77EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B77F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-17312
	ctx.r7.s64 = ctx.r8.s64 + -17312;
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

PPC_WEAK_FUNC(sub_827B77F0) {
	__imp__sub_827B77F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-17304
	ctx.r7.s64 = ctx.r8.s64 + -17304;
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

PPC_WEAK_FUNC(sub_827B7810) {
	__imp__sub_827B7810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,18452
	ctx.r5.s64 = r11.s64 + 18452;
	// addi r3,r10,-24440
	ctx.r3.s64 = ctx.r10.s64 + -24440;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7830) {
	__imp__sub_827B7830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B784C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B784C) {
	__imp__sub_827B784C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,19416
	ctx.r5.s64 = r11.s64 + 19416;
	// addi r3,r10,-24420
	ctx.r3.s64 = ctx.r10.s64 + -24420;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7850) {
	__imp__sub_827B7850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B786C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B786C) {
	__imp__sub_827B786C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13336
	ctx.r3.s64 = r11.s64 + -13336;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7870) {
	__imp__sub_827B7870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B787C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B787C) {
	__imp__sub_827B787C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7880) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13408
	ctx.r3.s64 = r11.s64 + -13408;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7880) {
	__imp__sub_827B7880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B788C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B788C) {
	__imp__sub_827B788C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13384
	ctx.r3.s64 = r11.s64 + -13384;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7890) {
	__imp__sub_827B7890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B789C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B789C) {
	__imp__sub_827B789C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B78A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13360
	ctx.r3.s64 = r11.s64 + -13360;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B78A0) {
	__imp__sub_827B78A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B78AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B78AC) {
	__imp__sub_827B78AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B78B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,21216
	ctx.r5.s64 = r11.s64 + 21216;
	// addi r3,r10,-24376
	ctx.r3.s64 = ctx.r10.s64 + -24376;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B78B0) {
	__imp__sub_827B78B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B78CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B78CC) {
	__imp__sub_827B78CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B78D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,21232
	ctx.r5.s64 = r11.s64 + 21232;
	// addi r3,r10,-24396
	ctx.r3.s64 = ctx.r10.s64 + -24396;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B78D0) {
	__imp__sub_827B78D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B78EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B78EC) {
	__imp__sub_827B78EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B78F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-13636
	ctx.r7.s64 = ctx.r8.s64 + -13636;
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

PPC_WEAK_FUNC(sub_827B78F0) {
	__imp__sub_827B78F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,100
	ctx.r10.s64 = 100;
	// addi r11,r11,-13624
	r11.s64 = r11.s64 + -13624;
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_827B7928:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x827b7928
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_827B7928;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827B7910) {
	__imp__sub_827B7910(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7938) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13312
	ctx.r3.s64 = r11.s64 + -13312;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7938) {
	__imp__sub_827B7938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7944) {
	__imp__sub_827B7944(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13304
	ctx.r3.s64 = r11.s64 + -13304;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7948) {
	__imp__sub_827B7948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7954) {
	__imp__sub_827B7954(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13296
	ctx.r3.s64 = r11.s64 + -13296;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7958) {
	__imp__sub_827B7958(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7964) {
	__imp__sub_827B7964(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7968) {
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
	// lis r11,-32176
	r11.s64 = -2108686336;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,15128
	ctx.r5.s64 = r11.s64 + 15128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7990;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-12964
	r11.s64 = ctx.r7.s64 + -12964;
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

PPC_WEAK_FUNC(sub_827B7968) {
	__imp__sub_827B7968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B79DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B79DC) {
	__imp__sub_827B79DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B79E0) {
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
	// lis r11,-32232
	r11.s64 = -2112356352;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,21256
	ctx.r5.s64 = r11.s64 + 21256;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7A08;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-12916
	r11.s64 = ctx.r7.s64 + -12916;
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

PPC_WEAK_FUNC(sub_827B79E0) {
	__imp__sub_827B79E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7A54) {
	__imp__sub_827B7A54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7A58) {
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
	// lis r11,-32143
	r11.s64 = -2106523648;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-8240
	ctx.r5.s64 = r11.s64 + -8240;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7A80;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-12868
	r11.s64 = ctx.r7.s64 + -12868;
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

PPC_WEAK_FUNC(sub_827B7A58) {
	__imp__sub_827B7A58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7ACC) {
	__imp__sub_827B7ACC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7AD0) {
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
	// lis r11,-32143
	r11.s64 = -2106523648;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-8144
	ctx.r5.s64 = r11.s64 + -8144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7AF8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-12820
	r11.s64 = ctx.r7.s64 + -12820;
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

PPC_WEAK_FUNC(sub_827B7AD0) {
	__imp__sub_827B7AD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7B44) {
	__imp__sub_827B7B44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7B48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-12772
	ctx.r7.s64 = ctx.r8.s64 + -12772;
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

PPC_WEAK_FUNC(sub_827B7B48) {
	__imp__sub_827B7B48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7B68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-12764
	ctx.r7.s64 = ctx.r8.s64 + -12764;
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

PPC_WEAK_FUNC(sub_827B7B68) {
	__imp__sub_827B7B68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7B88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-12756
	ctx.r7.s64 = ctx.r8.s64 + -12756;
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

PPC_WEAK_FUNC(sub_827B7B88) {
	__imp__sub_827B7B88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7BA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13288
	ctx.r3.s64 = r11.s64 + -13288;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7BA8) {
	__imp__sub_827B7BA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7BB4) {
	__imp__sub_827B7BB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-22052
	ctx.r5.s64 = r11.s64 + -22052;
	// addi r3,r10,-23172
	ctx.r3.s64 = ctx.r10.s64 + -23172;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7BB8) {
	__imp__sub_827B7BB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7BD4) {
	__imp__sub_827B7BD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7BD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7BD8) {
	__imp__sub_827B7BD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7BE4) {
	__imp__sub_827B7BE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7BE8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r3,r11,-24176
	ctx.r3.s64 = r11.s64 + -24176;
	// bl 0x8217d5e8
	ctx.lr = 0x827B7C00;
	sub_8217D5E8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-13264
	ctx.r3.s64 = ctx.r10.s64 + -13264;
	// bl 0x823d9a98
	ctx.lr = 0x827B7C0C;
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

PPC_WEAK_FUNC(sub_827B7BE8) {
	__imp__sub_827B7BE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7C1C) {
	__imp__sub_827B7C1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-21248
	ctx.r5.s64 = r11.s64 + -21248;
	// addi r3,r10,-22044
	ctx.r3.s64 = ctx.r10.s64 + -22044;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7C20) {
	__imp__sub_827B7C20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7C3C) {
	__imp__sub_827B7C3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-20336
	ctx.r5.s64 = r11.s64 + -20336;
	// addi r3,r10,-22020
	ctx.r3.s64 = ctx.r10.s64 + -22020;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7C40) {
	__imp__sub_827B7C40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7C5C) {
	__imp__sub_827B7C5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,13604
	ctx.r5.s64 = r11.s64 + 13604;
	// addi r3,r10,-21976
	ctx.r3.s64 = ctx.r10.s64 + -21976;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7C60) {
	__imp__sub_827B7C60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7C7C) {
	__imp__sub_827B7C7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-17732
	ctx.r5.s64 = r11.s64 + -17732;
	// addi r3,r10,-21936
	ctx.r3.s64 = ctx.r10.s64 + -21936;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7C80) {
	__imp__sub_827B7C80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7C9C) {
	__imp__sub_827B7C9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-17720
	ctx.r5.s64 = r11.s64 + -17720;
	// addi r3,r10,-21996
	ctx.r3.s64 = ctx.r10.s64 + -21996;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7CA0) {
	__imp__sub_827B7CA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7CBC) {
	__imp__sub_827B7CBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7CC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-17712
	ctx.r5.s64 = r11.s64 + -17712;
	// addi r3,r10,-21956
	ctx.r3.s64 = ctx.r10.s64 + -21956;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7CC0) {
	__imp__sub_827B7CC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7CDC) {
	__imp__sub_827B7CDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7CE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-17348
	ctx.r5.s64 = r11.s64 + -17348;
	// addi r3,r10,-21648
	ctx.r3.s64 = ctx.r10.s64 + -21648;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7CE0) {
	__imp__sub_827B7CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7CFC) {
	__imp__sub_827B7CFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-15872
	ctx.r5.s64 = r11.s64 + -15872;
	// addi r3,r10,-21604
	ctx.r3.s64 = ctx.r10.s64 + -21604;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7D00) {
	__imp__sub_827B7D00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7D1C) {
	__imp__sub_827B7D1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7D20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-15860
	ctx.r5.s64 = r11.s64 + -15860;
	// addi r3,r10,-21584
	ctx.r3.s64 = ctx.r10.s64 + -21584;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7D20) {
	__imp__sub_827B7D20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7D3C) {
	__imp__sub_827B7D3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7D40) {
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
	// lis r11,-32176
	r11.s64 = -2108686336;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,15128
	ctx.r5.s64 = r11.s64 + 15128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7D68;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-6184
	r11.s64 = ctx.r7.s64 + -6184;
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

PPC_WEAK_FUNC(sub_827B7D40) {
	__imp__sub_827B7D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7DB4) {
	__imp__sub_827B7DB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7DB8) {
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
	// addi r5,r11,-30904
	ctx.r5.s64 = r11.s64 + -30904;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7DE0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-6136
	r11.s64 = ctx.r7.s64 + -6136;
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

PPC_WEAK_FUNC(sub_827B7DB8) {
	__imp__sub_827B7DB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7E2C) {
	__imp__sub_827B7E2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7E30) {
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
	// lis r11,-32140
	r11.s64 = -2106327040;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-26728
	ctx.r5.s64 = r11.s64 + -26728;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7E58;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-6088
	r11.s64 = ctx.r7.s64 + -6088;
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

PPC_WEAK_FUNC(sub_827B7E30) {
	__imp__sub_827B7E30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7EA4) {
	__imp__sub_827B7EA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7EA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-6040
	ctx.r7.s64 = ctx.r8.s64 + -6040;
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

PPC_WEAK_FUNC(sub_827B7EA8) {
	__imp__sub_827B7EA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-6032
	ctx.r7.s64 = ctx.r8.s64 + -6032;
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

PPC_WEAK_FUNC(sub_827B7EC8) {
	__imp__sub_827B7EC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7EE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lfs f0,-5852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5852);
	f0.f64 = double(temp.f32);
	// lfs f13,-5856(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5856);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f0,-5860(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -5860);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fadds f0,f11,f13
	f0.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f0,-21532(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -21532, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827B7EE8) {
	__imp__sub_827B7EE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7F20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-8256
	ctx.r5.s64 = r11.s64 + -8256;
	// addi r3,r10,-21524
	ctx.r3.s64 = ctx.r10.s64 + -21524;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7F20) {
	__imp__sub_827B7F20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7F3C) {
	__imp__sub_827B7F3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7F40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-5036
	ctx.r5.s64 = r11.s64 + -5036;
	// addi r3,r10,-21468
	ctx.r3.s64 = ctx.r10.s64 + -21468;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7F40) {
	__imp__sub_827B7F40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7F5C) {
	__imp__sub_827B7F5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7F60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-5020
	ctx.r5.s64 = r11.s64 + -5020;
	// addi r3,r10,-21488
	ctx.r3.s64 = ctx.r10.s64 + -21488;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7F60) {
	__imp__sub_827B7F60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7F7C) {
	__imp__sub_827B7F7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7F80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-3876
	ctx.r5.s64 = r11.s64 + -3876;
	// addi r3,r10,-21448
	ctx.r3.s64 = ctx.r10.s64 + -21448;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7F80) {
	__imp__sub_827B7F80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7F9C) {
	__imp__sub_827B7F9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13232
	ctx.r3.s64 = r11.s64 + -13232;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827B7FA0) {
	__imp__sub_827B7FA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B7FAC) {
	__imp__sub_827B7FAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B7FB0) {
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
	// lis r11,-32232
	r11.s64 = -2112356352;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,21256
	ctx.r5.s64 = r11.s64 + 21256;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B7FD8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-5296
	r11.s64 = ctx.r7.s64 + -5296;
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

PPC_WEAK_FUNC(sub_827B7FB0) {
	__imp__sub_827B7FB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B8024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B8024) {
	__imp__sub_827B8024(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B8028) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,-5248
	ctx.r7.s64 = ctx.r8.s64 + -5248;
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

PPC_WEAK_FUNC(sub_827B8028) {
	__imp__sub_827B8028(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B8048) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r4,442
	ctx.r4.s64 = 442;
	// addi r3,r11,-23056
	ctx.r3.s64 = r11.s64 + -23056;
	// bl 0x8275c7b8
	ctx.lr = 0x827B8064;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21200(r11)
	PPC_STORE_U32(r11.u32 + -21200, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827B8048) {
	__imp__sub_827B8048(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B807C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B807C) {
	__imp__sub_827B807C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B8080) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r4,520
	ctx.r4.s64 = 520;
	// addi r3,r11,-23056
	ctx.r3.s64 = r11.s64 + -23056;
	// bl 0x8275c7b8
	ctx.lr = 0x827B809C;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21228(r11)
	PPC_STORE_U32(r11.u32 + -21228, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827B8080) {
	__imp__sub_827B8080(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827B80B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827B80B4) {
	__imp__sub_827B80B4(ctx, base);
}

