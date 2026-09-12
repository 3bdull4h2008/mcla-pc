#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827AF020"))) PPC_WEAK_FUNC(sub_827AF020);
PPC_FUNC_IMPL(__imp__sub_827AF020) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r3,r11,-5856
	ctx.r3.s64 = r11.s64 + -5856;
	// bl 0x8238cfc8
	ctx.lr = 0x827AF038;
	sub_8238CFC8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-23456
	ctx.r3.s64 = ctx.r10.s64 + -23456;
	// bl 0x823d9a98
	ctx.lr = 0x827AF044;
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

__attribute__((alias("__imp__sub_827AF054"))) PPC_WEAK_FUNC(sub_827AF054);
PPC_FUNC_IMPL(__imp__sub_827AF054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF058"))) PPC_WEAK_FUNC(sub_827AF058);
PPC_FUNC_IMPL(__imp__sub_827AF058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,-13772
	ctx.r3.s64 = r11.s64 + -13772;
	// b 0x82398548
	sub_82398548(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF064"))) PPC_WEAK_FUNC(sub_827AF064);
PPC_FUNC_IMPL(__imp__sub_827AF064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF068"))) PPC_WEAK_FUNC(sub_827AF068);
PPC_FUNC_IMPL(__imp__sub_827AF068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-7764
	ctx.r5.s64 = r11.s64 + -7764;
	// addi r3,r10,-12668
	ctx.r3.s64 = ctx.r10.s64 + -12668;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF084"))) PPC_WEAK_FUNC(sub_827AF084);
PPC_FUNC_IMPL(__imp__sub_827AF084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF088"))) PPC_WEAK_FUNC(sub_827AF088);
PPC_FUNC_IMPL(__imp__sub_827AF088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-7752
	ctx.r5.s64 = r11.s64 + -7752;
	// addi r3,r10,-12692
	ctx.r3.s64 = ctx.r10.s64 + -12692;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF0A4"))) PPC_WEAK_FUNC(sub_827AF0A4);
PPC_FUNC_IMPL(__imp__sub_827AF0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF0A8"))) PPC_WEAK_FUNC(sub_827AF0A8);
PPC_FUNC_IMPL(__imp__sub_827AF0A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-7736
	ctx.r5.s64 = r11.s64 + -7736;
	// addi r3,r10,-12712
	ctx.r3.s64 = ctx.r10.s64 + -12712;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF0C4"))) PPC_WEAK_FUNC(sub_827AF0C4);
PPC_FUNC_IMPL(__imp__sub_827AF0C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF0C8"))) PPC_WEAK_FUNC(sub_827AF0C8);
PPC_FUNC_IMPL(__imp__sub_827AF0C8) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28256);
	// bl 0x821c9790
	ctx.lr = 0x827AF0E4;
	sub_821C9790(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r3,-12672(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12672, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827AF0FC"))) PPC_WEAK_FUNC(sub_827AF0FC);
PPC_FUNC_IMPL(__imp__sub_827AF0FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF100"))) PPC_WEAK_FUNC(sub_827AF100);
PPC_FUNC_IMPL(__imp__sub_827AF100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-23352
	ctx.r3.s64 = r11.s64 + -23352;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF10C"))) PPC_WEAK_FUNC(sub_827AF10C);
PPC_FUNC_IMPL(__imp__sub_827AF10C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF110"))) PPC_WEAK_FUNC(sub_827AF110);
PPC_FUNC_IMPL(__imp__sub_827AF110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-6728
	ctx.r5.s64 = r11.s64 + -6728;
	// addi r3,r10,-12600
	ctx.r3.s64 = ctx.r10.s64 + -12600;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF12C"))) PPC_WEAK_FUNC(sub_827AF12C);
PPC_FUNC_IMPL(__imp__sub_827AF12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF130"))) PPC_WEAK_FUNC(sub_827AF130);
PPC_FUNC_IMPL(__imp__sub_827AF130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-6716
	ctx.r5.s64 = r11.s64 + -6716;
	// addi r3,r10,-12540
	ctx.r3.s64 = ctx.r10.s64 + -12540;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF14C"))) PPC_WEAK_FUNC(sub_827AF14C);
PPC_FUNC_IMPL(__imp__sub_827AF14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF150"))) PPC_WEAK_FUNC(sub_827AF150);
PPC_FUNC_IMPL(__imp__sub_827AF150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-6708
	ctx.r5.s64 = r11.s64 + -6708;
	// addi r3,r10,-12560
	ctx.r3.s64 = ctx.r10.s64 + -12560;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF16C"))) PPC_WEAK_FUNC(sub_827AF16C);
PPC_FUNC_IMPL(__imp__sub_827AF16C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF170"))) PPC_WEAK_FUNC(sub_827AF170);
PPC_FUNC_IMPL(__imp__sub_827AF170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-6704
	ctx.r5.s64 = r11.s64 + -6704;
	// addi r3,r10,-12620
	ctx.r3.s64 = ctx.r10.s64 + -12620;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF18C"))) PPC_WEAK_FUNC(sub_827AF18C);
PPC_FUNC_IMPL(__imp__sub_827AF18C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF190"))) PPC_WEAK_FUNC(sub_827AF190);
PPC_FUNC_IMPL(__imp__sub_827AF190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-6692
	ctx.r5.s64 = r11.s64 + -6692;
	// addi r3,r10,-12520
	ctx.r3.s64 = ctx.r10.s64 + -12520;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF1AC"))) PPC_WEAK_FUNC(sub_827AF1AC);
PPC_FUNC_IMPL(__imp__sub_827AF1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF1B0"))) PPC_WEAK_FUNC(sub_827AF1B0);
PPC_FUNC_IMPL(__imp__sub_827AF1B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-6680
	ctx.r5.s64 = r11.s64 + -6680;
	// addi r3,r10,-12460
	ctx.r3.s64 = ctx.r10.s64 + -12460;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF1CC"))) PPC_WEAK_FUNC(sub_827AF1CC);
PPC_FUNC_IMPL(__imp__sub_827AF1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF1D0"))) PPC_WEAK_FUNC(sub_827AF1D0);
PPC_FUNC_IMPL(__imp__sub_827AF1D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-6668
	ctx.r5.s64 = r11.s64 + -6668;
	// addi r3,r10,-12580
	ctx.r3.s64 = ctx.r10.s64 + -12580;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF1EC"))) PPC_WEAK_FUNC(sub_827AF1EC);
PPC_FUNC_IMPL(__imp__sub_827AF1EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF1F0"))) PPC_WEAK_FUNC(sub_827AF1F0);
PPC_FUNC_IMPL(__imp__sub_827AF1F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-6188
	ctx.r5.s64 = r11.s64 + -6188;
	// addi r3,r10,-12500
	ctx.r3.s64 = ctx.r10.s64 + -12500;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF20C"))) PPC_WEAK_FUNC(sub_827AF20C);
PPC_FUNC_IMPL(__imp__sub_827AF20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF210"))) PPC_WEAK_FUNC(sub_827AF210);
PPC_FUNC_IMPL(__imp__sub_827AF210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-21520
	ctx.r5.s64 = r11.s64 + -21520;
	// addi r3,r10,-12480
	ctx.r3.s64 = ctx.r10.s64 + -12480;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF22C"))) PPC_WEAK_FUNC(sub_827AF22C);
PPC_FUNC_IMPL(__imp__sub_827AF22C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF230"))) PPC_WEAK_FUNC(sub_827AF230);
PPC_FUNC_IMPL(__imp__sub_827AF230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-2372
	ctx.r5.s64 = r11.s64 + -2372;
	// addi r3,r10,-12396
	ctx.r3.s64 = ctx.r10.s64 + -12396;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF24C"))) PPC_WEAK_FUNC(sub_827AF24C);
PPC_FUNC_IMPL(__imp__sub_827AF24C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF250"))) PPC_WEAK_FUNC(sub_827AF250);
PPC_FUNC_IMPL(__imp__sub_827AF250) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-2356
	ctx.r5.s64 = r11.s64 + -2356;
	// addi r3,r10,-12436
	ctx.r3.s64 = ctx.r10.s64 + -12436;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF26C"))) PPC_WEAK_FUNC(sub_827AF26C);
PPC_FUNC_IMPL(__imp__sub_827AF26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF270"))) PPC_WEAK_FUNC(sub_827AF270);
PPC_FUNC_IMPL(__imp__sub_827AF270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-2340
	ctx.r5.s64 = r11.s64 + -2340;
	// addi r3,r10,-12416
	ctx.r3.s64 = ctx.r10.s64 + -12416;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF28C"))) PPC_WEAK_FUNC(sub_827AF28C);
PPC_FUNC_IMPL(__imp__sub_827AF28C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF290"))) PPC_WEAK_FUNC(sub_827AF290);
PPC_FUNC_IMPL(__imp__sub_827AF290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-2324
	ctx.r5.s64 = r11.s64 + -2324;
	// addi r3,r10,-12376
	ctx.r3.s64 = ctx.r10.s64 + -12376;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF2AC"))) PPC_WEAK_FUNC(sub_827AF2AC);
PPC_FUNC_IMPL(__imp__sub_827AF2AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF2B0"))) PPC_WEAK_FUNC(sub_827AF2B0);
PPC_FUNC_IMPL(__imp__sub_827AF2B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-1940
	ctx.r5.s64 = r11.s64 + -1940;
	// addi r3,r10,-12344
	ctx.r3.s64 = ctx.r10.s64 + -12344;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF2CC"))) PPC_WEAK_FUNC(sub_827AF2CC);
PPC_FUNC_IMPL(__imp__sub_827AF2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF2D0"))) PPC_WEAK_FUNC(sub_827AF2D0);
PPC_FUNC_IMPL(__imp__sub_827AF2D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,432
	ctx.r5.s64 = r11.s64 + 432;
	// addi r3,r10,-12324
	ctx.r3.s64 = ctx.r10.s64 + -12324;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF2EC"))) PPC_WEAK_FUNC(sub_827AF2EC);
PPC_FUNC_IMPL(__imp__sub_827AF2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF2F0"))) PPC_WEAK_FUNC(sub_827AF2F0);
PPC_FUNC_IMPL(__imp__sub_827AF2F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-26056
	ctx.r7.s64 = ctx.r8.s64 + -26056;
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

__attribute__((alias("__imp__sub_827AF310"))) PPC_WEAK_FUNC(sub_827AF310);
PPC_FUNC_IMPL(__imp__sub_827AF310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,6728
	ctx.r5.s64 = r11.s64 + 6728;
	// addi r3,r10,-12288
	ctx.r3.s64 = ctx.r10.s64 + -12288;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF32C"))) PPC_WEAK_FUNC(sub_827AF32C);
PPC_FUNC_IMPL(__imp__sub_827AF32C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF330"))) PPC_WEAK_FUNC(sub_827AF330);
PPC_FUNC_IMPL(__imp__sub_827AF330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,7928
	ctx.r5.s64 = r11.s64 + 7928;
	// addi r3,r10,-12208
	ctx.r3.s64 = ctx.r10.s64 + -12208;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF34C"))) PPC_WEAK_FUNC(sub_827AF34C);
PPC_FUNC_IMPL(__imp__sub_827AF34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF350"))) PPC_WEAK_FUNC(sub_827AF350);
PPC_FUNC_IMPL(__imp__sub_827AF350) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,7948
	ctx.r5.s64 = r11.s64 + 7948;
	// addi r3,r10,-12248
	ctx.r3.s64 = ctx.r10.s64 + -12248;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF36C"))) PPC_WEAK_FUNC(sub_827AF36C);
PPC_FUNC_IMPL(__imp__sub_827AF36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF370"))) PPC_WEAK_FUNC(sub_827AF370);
PPC_FUNC_IMPL(__imp__sub_827AF370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,7956
	ctx.r5.s64 = r11.s64 + 7956;
	// addi r3,r10,-12140
	ctx.r3.s64 = ctx.r10.s64 + -12140;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF38C"))) PPC_WEAK_FUNC(sub_827AF38C);
PPC_FUNC_IMPL(__imp__sub_827AF38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF390"))) PPC_WEAK_FUNC(sub_827AF390);
PPC_FUNC_IMPL(__imp__sub_827AF390) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,7964
	ctx.r5.s64 = r11.s64 + 7964;
	// addi r3,r10,-12228
	ctx.r3.s64 = ctx.r10.s64 + -12228;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF3AC"))) PPC_WEAK_FUNC(sub_827AF3AC);
PPC_FUNC_IMPL(__imp__sub_827AF3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF3B0"))) PPC_WEAK_FUNC(sub_827AF3B0);
PPC_FUNC_IMPL(__imp__sub_827AF3B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,7972
	ctx.r5.s64 = r11.s64 + 7972;
	// addi r3,r10,-12160
	ctx.r3.s64 = ctx.r10.s64 + -12160;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF3CC"))) PPC_WEAK_FUNC(sub_827AF3CC);
PPC_FUNC_IMPL(__imp__sub_827AF3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF3D0"))) PPC_WEAK_FUNC(sub_827AF3D0);
PPC_FUNC_IMPL(__imp__sub_827AF3D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,7980
	ctx.r5.s64 = r11.s64 + 7980;
	// addi r3,r10,-12268
	ctx.r3.s64 = ctx.r10.s64 + -12268;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF3EC"))) PPC_WEAK_FUNC(sub_827AF3EC);
PPC_FUNC_IMPL(__imp__sub_827AF3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF3F0"))) PPC_WEAK_FUNC(sub_827AF3F0);
PPC_FUNC_IMPL(__imp__sub_827AF3F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-23264
	ctx.r3.s64 = r11.s64 + -23264;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF3FC"))) PPC_WEAK_FUNC(sub_827AF3FC);
PPC_FUNC_IMPL(__imp__sub_827AF3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF400"))) PPC_WEAK_FUNC(sub_827AF400);
PPC_FUNC_IMPL(__imp__sub_827AF400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-23200
	ctx.r3.s64 = r11.s64 + -23200;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF40C"))) PPC_WEAK_FUNC(sub_827AF40C);
PPC_FUNC_IMPL(__imp__sub_827AF40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF410"))) PPC_WEAK_FUNC(sub_827AF410);
PPC_FUNC_IMPL(__imp__sub_827AF410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-23232
	ctx.r3.s64 = r11.s64 + -23232;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF41C"))) PPC_WEAK_FUNC(sub_827AF41C);
PPC_FUNC_IMPL(__imp__sub_827AF41C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF420"))) PPC_WEAK_FUNC(sub_827AF420);
PPC_FUNC_IMPL(__imp__sub_827AF420) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,8472
	ctx.r5.s64 = r11.s64 + 8472;
	// addi r3,r10,-12112
	ctx.r3.s64 = ctx.r10.s64 + -12112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF43C"))) PPC_WEAK_FUNC(sub_827AF43C);
PPC_FUNC_IMPL(__imp__sub_827AF43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF440"))) PPC_WEAK_FUNC(sub_827AF440);
PPC_FUNC_IMPL(__imp__sub_827AF440) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,8488
	ctx.r5.s64 = r11.s64 + 8488;
	// addi r3,r10,-12072
	ctx.r3.s64 = ctx.r10.s64 + -12072;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF45C"))) PPC_WEAK_FUNC(sub_827AF45C);
PPC_FUNC_IMPL(__imp__sub_827AF45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF460"))) PPC_WEAK_FUNC(sub_827AF460);
PPC_FUNC_IMPL(__imp__sub_827AF460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,8504
	ctx.r5.s64 = r11.s64 + 8504;
	// addi r3,r10,-12092
	ctx.r3.s64 = ctx.r10.s64 + -12092;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF47C"))) PPC_WEAK_FUNC(sub_827AF47C);
PPC_FUNC_IMPL(__imp__sub_827AF47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF480"))) PPC_WEAK_FUNC(sub_827AF480);
PPC_FUNC_IMPL(__imp__sub_827AF480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-25000
	ctx.r7.s64 = ctx.r8.s64 + -25000;
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

__attribute__((alias("__imp__sub_827AF4A0"))) PPC_WEAK_FUNC(sub_827AF4A0);
PPC_FUNC_IMPL(__imp__sub_827AF4A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-23112
	ctx.r3.s64 = r11.s64 + -23112;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF4AC"))) PPC_WEAK_FUNC(sub_827AF4AC);
PPC_FUNC_IMPL(__imp__sub_827AF4AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF4B0"))) PPC_WEAK_FUNC(sub_827AF4B0);
PPC_FUNC_IMPL(__imp__sub_827AF4B0) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// lis r6,-32198
	ctx.r6.s64 = -2110128128;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// addi r3,r4,-12016
	ctx.r3.s64 = ctx.r4.s64 + -12016;
	// addi r5,r5,16540
	ctx.r5.s64 = ctx.r5.s64 + 16540;
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r11,-4736
	ctx.r8.s64 = r11.s64 + -4736;
	// addi r7,r10,-4808
	ctx.r7.s64 = ctx.r10.s64 + -4808;
	// addi r6,r6,-4952
	ctx.r6.s64 = ctx.r6.s64 + -4952;
	// li r4,129
	ctx.r4.s64 = 129;
	// bl 0x8246a038
	ctx.lr = 0x827AF4F0;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-23096
	ctx.r3.s64 = ctx.r3.s64 + -23096;
	// bl 0x823d9a98
	ctx.lr = 0x827AF4FC;
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

__attribute__((alias("__imp__sub_827AF50C"))) PPC_WEAK_FUNC(sub_827AF50C);
PPC_FUNC_IMPL(__imp__sub_827AF50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF510"))) PPC_WEAK_FUNC(sub_827AF510);
PPC_FUNC_IMPL(__imp__sub_827AF510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19020
	ctx.r5.s64 = r11.s64 + 19020;
	// addi r3,r10,-11908
	ctx.r3.s64 = ctx.r10.s64 + -11908;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF52C"))) PPC_WEAK_FUNC(sub_827AF52C);
PPC_FUNC_IMPL(__imp__sub_827AF52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF530"))) PPC_WEAK_FUNC(sub_827AF530);
PPC_FUNC_IMPL(__imp__sub_827AF530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19032
	ctx.r5.s64 = r11.s64 + 19032;
	// addi r3,r10,-11968
	ctx.r3.s64 = ctx.r10.s64 + -11968;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF54C"))) PPC_WEAK_FUNC(sub_827AF54C);
PPC_FUNC_IMPL(__imp__sub_827AF54C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF550"))) PPC_WEAK_FUNC(sub_827AF550);
PPC_FUNC_IMPL(__imp__sub_827AF550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19048
	ctx.r5.s64 = r11.s64 + 19048;
	// addi r3,r10,-11848
	ctx.r3.s64 = ctx.r10.s64 + -11848;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF56C"))) PPC_WEAK_FUNC(sub_827AF56C);
PPC_FUNC_IMPL(__imp__sub_827AF56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF570"))) PPC_WEAK_FUNC(sub_827AF570);
PPC_FUNC_IMPL(__imp__sub_827AF570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19064
	ctx.r5.s64 = r11.s64 + 19064;
	// addi r3,r10,-11868
	ctx.r3.s64 = ctx.r10.s64 + -11868;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF58C"))) PPC_WEAK_FUNC(sub_827AF58C);
PPC_FUNC_IMPL(__imp__sub_827AF58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF590"))) PPC_WEAK_FUNC(sub_827AF590);
PPC_FUNC_IMPL(__imp__sub_827AF590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19084
	ctx.r5.s64 = r11.s64 + 19084;
	// addi r3,r10,-11828
	ctx.r3.s64 = ctx.r10.s64 + -11828;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF5AC"))) PPC_WEAK_FUNC(sub_827AF5AC);
PPC_FUNC_IMPL(__imp__sub_827AF5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF5B0"))) PPC_WEAK_FUNC(sub_827AF5B0);
PPC_FUNC_IMPL(__imp__sub_827AF5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19104
	ctx.r5.s64 = r11.s64 + 19104;
	// addi r3,r10,-11808
	ctx.r3.s64 = ctx.r10.s64 + -11808;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF5CC"))) PPC_WEAK_FUNC(sub_827AF5CC);
PPC_FUNC_IMPL(__imp__sub_827AF5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF5D0"))) PPC_WEAK_FUNC(sub_827AF5D0);
PPC_FUNC_IMPL(__imp__sub_827AF5D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19120
	ctx.r5.s64 = r11.s64 + 19120;
	// addi r3,r10,-11928
	ctx.r3.s64 = ctx.r10.s64 + -11928;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF5EC"))) PPC_WEAK_FUNC(sub_827AF5EC);
PPC_FUNC_IMPL(__imp__sub_827AF5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF5F0"))) PPC_WEAK_FUNC(sub_827AF5F0);
PPC_FUNC_IMPL(__imp__sub_827AF5F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19140
	ctx.r5.s64 = r11.s64 + 19140;
	// addi r3,r10,-11988
	ctx.r3.s64 = ctx.r10.s64 + -11988;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF60C"))) PPC_WEAK_FUNC(sub_827AF60C);
PPC_FUNC_IMPL(__imp__sub_827AF60C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF610"))) PPC_WEAK_FUNC(sub_827AF610);
PPC_FUNC_IMPL(__imp__sub_827AF610) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19164
	ctx.r5.s64 = r11.s64 + 19164;
	// addi r3,r10,-11888
	ctx.r3.s64 = ctx.r10.s64 + -11888;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF62C"))) PPC_WEAK_FUNC(sub_827AF62C);
PPC_FUNC_IMPL(__imp__sub_827AF62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF630"))) PPC_WEAK_FUNC(sub_827AF630);
PPC_FUNC_IMPL(__imp__sub_827AF630) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19184
	ctx.r5.s64 = r11.s64 + 19184;
	// addi r3,r10,-11948
	ctx.r3.s64 = ctx.r10.s64 + -11948;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF64C"))) PPC_WEAK_FUNC(sub_827AF64C);
PPC_FUNC_IMPL(__imp__sub_827AF64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF650"))) PPC_WEAK_FUNC(sub_827AF650);
PPC_FUNC_IMPL(__imp__sub_827AF650) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19204
	ctx.r5.s64 = r11.s64 + 19204;
	// addi r3,r10,-11788
	ctx.r3.s64 = ctx.r10.s64 + -11788;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF66C"))) PPC_WEAK_FUNC(sub_827AF66C);
PPC_FUNC_IMPL(__imp__sub_827AF66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF670"))) PPC_WEAK_FUNC(sub_827AF670);
PPC_FUNC_IMPL(__imp__sub_827AF670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19648
	ctx.r5.s64 = r11.s64 + 19648;
	// addi r3,r10,-11712
	ctx.r3.s64 = ctx.r10.s64 + -11712;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF68C"))) PPC_WEAK_FUNC(sub_827AF68C);
PPC_FUNC_IMPL(__imp__sub_827AF68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF690"))) PPC_WEAK_FUNC(sub_827AF690);
PPC_FUNC_IMPL(__imp__sub_827AF690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19668
	ctx.r5.s64 = r11.s64 + 19668;
	// addi r3,r10,-11752
	ctx.r3.s64 = ctx.r10.s64 + -11752;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF6AC"))) PPC_WEAK_FUNC(sub_827AF6AC);
PPC_FUNC_IMPL(__imp__sub_827AF6AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF6B0"))) PPC_WEAK_FUNC(sub_827AF6B0);
PPC_FUNC_IMPL(__imp__sub_827AF6B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19692
	ctx.r5.s64 = r11.s64 + 19692;
	// addi r3,r10,-11732
	ctx.r3.s64 = ctx.r10.s64 + -11732;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF6CC"))) PPC_WEAK_FUNC(sub_827AF6CC);
PPC_FUNC_IMPL(__imp__sub_827AF6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF6D0"))) PPC_WEAK_FUNC(sub_827AF6D0);
PPC_FUNC_IMPL(__imp__sub_827AF6D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,21856
	ctx.r5.s64 = r11.s64 + 21856;
	// addi r3,r10,-11672
	ctx.r3.s64 = ctx.r10.s64 + -11672;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF6EC"))) PPC_WEAK_FUNC(sub_827AF6EC);
PPC_FUNC_IMPL(__imp__sub_827AF6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF6F0"))) PPC_WEAK_FUNC(sub_827AF6F0);
PPC_FUNC_IMPL(__imp__sub_827AF6F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,21868
	ctx.r5.s64 = r11.s64 + 21868;
	// addi r3,r10,-11652
	ctx.r3.s64 = ctx.r10.s64 + -11652;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF70C"))) PPC_WEAK_FUNC(sub_827AF70C);
PPC_FUNC_IMPL(__imp__sub_827AF70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF710"))) PPC_WEAK_FUNC(sub_827AF710);
PPC_FUNC_IMPL(__imp__sub_827AF710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,21880
	ctx.r5.s64 = r11.s64 + 21880;
	// addi r3,r10,-11692
	ctx.r3.s64 = ctx.r10.s64 + -11692;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF72C"))) PPC_WEAK_FUNC(sub_827AF72C);
PPC_FUNC_IMPL(__imp__sub_827AF72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF730"))) PPC_WEAK_FUNC(sub_827AF730);
PPC_FUNC_IMPL(__imp__sub_827AF730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,32616
	ctx.r5.s64 = r11.s64 + 32616;
	// addi r3,r10,-11592
	ctx.r3.s64 = ctx.r10.s64 + -11592;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF74C"))) PPC_WEAK_FUNC(sub_827AF74C);
PPC_FUNC_IMPL(__imp__sub_827AF74C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF750"))) PPC_WEAK_FUNC(sub_827AF750);
PPC_FUNC_IMPL(__imp__sub_827AF750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,32628
	ctx.r5.s64 = r11.s64 + 32628;
	// addi r3,r10,-11632
	ctx.r3.s64 = ctx.r10.s64 + -11632;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF76C"))) PPC_WEAK_FUNC(sub_827AF76C);
PPC_FUNC_IMPL(__imp__sub_827AF76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF770"))) PPC_WEAK_FUNC(sub_827AF770);
PPC_FUNC_IMPL(__imp__sub_827AF770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,32644
	ctx.r5.s64 = r11.s64 + 32644;
	// addi r3,r10,-11612
	ctx.r3.s64 = ctx.r10.s64 + -11612;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF78C"))) PPC_WEAK_FUNC(sub_827AF78C);
PPC_FUNC_IMPL(__imp__sub_827AF78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF790"))) PPC_WEAK_FUNC(sub_827AF790);
PPC_FUNC_IMPL(__imp__sub_827AF790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,32660
	ctx.r5.s64 = r11.s64 + 32660;
	// addi r3,r10,-11572
	ctx.r3.s64 = ctx.r10.s64 + -11572;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF7AC"))) PPC_WEAK_FUNC(sub_827AF7AC);
PPC_FUNC_IMPL(__imp__sub_827AF7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF7B0"))) PPC_WEAK_FUNC(sub_827AF7B0);
PPC_FUNC_IMPL(__imp__sub_827AF7B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-29196
	ctx.r5.s64 = r11.s64 + -29196;
	// addi r3,r10,-11532
	ctx.r3.s64 = ctx.r10.s64 + -11532;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF7CC"))) PPC_WEAK_FUNC(sub_827AF7CC);
PPC_FUNC_IMPL(__imp__sub_827AF7CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF7D0"))) PPC_WEAK_FUNC(sub_827AF7D0);
PPC_FUNC_IMPL(__imp__sub_827AF7D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-29184
	ctx.r5.s64 = r11.s64 + -29184;
	// addi r3,r10,-11512
	ctx.r3.s64 = ctx.r10.s64 + -11512;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF7EC"))) PPC_WEAK_FUNC(sub_827AF7EC);
PPC_FUNC_IMPL(__imp__sub_827AF7EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF7F0"))) PPC_WEAK_FUNC(sub_827AF7F0);
PPC_FUNC_IMPL(__imp__sub_827AF7F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18452
	ctx.r5.s64 = r11.s64 + -18452;
	// addi r3,r10,-11076
	ctx.r3.s64 = ctx.r10.s64 + -11076;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF80C"))) PPC_WEAK_FUNC(sub_827AF80C);
PPC_FUNC_IMPL(__imp__sub_827AF80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF810"))) PPC_WEAK_FUNC(sub_827AF810);
PPC_FUNC_IMPL(__imp__sub_827AF810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18436
	ctx.r5.s64 = r11.s64 + -18436;
	// addi r3,r10,-11096
	ctx.r3.s64 = ctx.r10.s64 + -11096;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF82C"))) PPC_WEAK_FUNC(sub_827AF82C);
PPC_FUNC_IMPL(__imp__sub_827AF82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF830"))) PPC_WEAK_FUNC(sub_827AF830);
PPC_FUNC_IMPL(__imp__sub_827AF830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18420
	ctx.r5.s64 = r11.s64 + -18420;
	// addi r3,r10,-11056
	ctx.r3.s64 = ctx.r10.s64 + -11056;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF84C"))) PPC_WEAK_FUNC(sub_827AF84C);
PPC_FUNC_IMPL(__imp__sub_827AF84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF850"))) PPC_WEAK_FUNC(sub_827AF850);
PPC_FUNC_IMPL(__imp__sub_827AF850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18400
	ctx.r5.s64 = r11.s64 + -18400;
	// addi r3,r10,-11036
	ctx.r3.s64 = ctx.r10.s64 + -11036;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF86C"))) PPC_WEAK_FUNC(sub_827AF86C);
PPC_FUNC_IMPL(__imp__sub_827AF86C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF870"))) PPC_WEAK_FUNC(sub_827AF870);
PPC_FUNC_IMPL(__imp__sub_827AF870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18380
	ctx.r5.s64 = r11.s64 + -18380;
	// addi r3,r10,-11176
	ctx.r3.s64 = ctx.r10.s64 + -11176;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF88C"))) PPC_WEAK_FUNC(sub_827AF88C);
PPC_FUNC_IMPL(__imp__sub_827AF88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF890"))) PPC_WEAK_FUNC(sub_827AF890);
PPC_FUNC_IMPL(__imp__sub_827AF890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18368
	ctx.r5.s64 = r11.s64 + -18368;
	// addi r3,r10,-11136
	ctx.r3.s64 = ctx.r10.s64 + -11136;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF8AC"))) PPC_WEAK_FUNC(sub_827AF8AC);
PPC_FUNC_IMPL(__imp__sub_827AF8AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF8B0"))) PPC_WEAK_FUNC(sub_827AF8B0);
PPC_FUNC_IMPL(__imp__sub_827AF8B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18352
	ctx.r5.s64 = r11.s64 + -18352;
	// addi r3,r10,-11116
	ctx.r3.s64 = ctx.r10.s64 + -11116;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF8CC"))) PPC_WEAK_FUNC(sub_827AF8CC);
PPC_FUNC_IMPL(__imp__sub_827AF8CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF8D0"))) PPC_WEAK_FUNC(sub_827AF8D0);
PPC_FUNC_IMPL(__imp__sub_827AF8D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18336
	ctx.r5.s64 = r11.s64 + -18336;
	// addi r3,r10,-11016
	ctx.r3.s64 = ctx.r10.s64 + -11016;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF8EC"))) PPC_WEAK_FUNC(sub_827AF8EC);
PPC_FUNC_IMPL(__imp__sub_827AF8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF8F0"))) PPC_WEAK_FUNC(sub_827AF8F0);
PPC_FUNC_IMPL(__imp__sub_827AF8F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-18320
	ctx.r5.s64 = r11.s64 + -18320;
	// addi r3,r10,-11156
	ctx.r3.s64 = ctx.r10.s64 + -11156;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF90C"))) PPC_WEAK_FUNC(sub_827AF90C);
PPC_FUNC_IMPL(__imp__sub_827AF90C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF910"))) PPC_WEAK_FUNC(sub_827AF910);
PPC_FUNC_IMPL(__imp__sub_827AF910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-17372
	ctx.r5.s64 = r11.s64 + -17372;
	// addi r3,r10,-10996
	ctx.r3.s64 = ctx.r10.s64 + -10996;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF92C"))) PPC_WEAK_FUNC(sub_827AF92C);
PPC_FUNC_IMPL(__imp__sub_827AF92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF930"))) PPC_WEAK_FUNC(sub_827AF930);
PPC_FUNC_IMPL(__imp__sub_827AF930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-16868
	ctx.r5.s64 = r11.s64 + -16868;
	// addi r3,r10,-10920
	ctx.r3.s64 = ctx.r10.s64 + -10920;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF94C"))) PPC_WEAK_FUNC(sub_827AF94C);
PPC_FUNC_IMPL(__imp__sub_827AF94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF950"))) PPC_WEAK_FUNC(sub_827AF950);
PPC_FUNC_IMPL(__imp__sub_827AF950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-16848
	ctx.r5.s64 = r11.s64 + -16848;
	// addi r3,r10,-10940
	ctx.r3.s64 = ctx.r10.s64 + -10940;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF96C"))) PPC_WEAK_FUNC(sub_827AF96C);
PPC_FUNC_IMPL(__imp__sub_827AF96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF970"))) PPC_WEAK_FUNC(sub_827AF970);
PPC_FUNC_IMPL(__imp__sub_827AF970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-15964
	ctx.r5.s64 = r11.s64 + -15964;
	// addi r3,r10,-10800
	ctx.r3.s64 = ctx.r10.s64 + -10800;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF98C"))) PPC_WEAK_FUNC(sub_827AF98C);
PPC_FUNC_IMPL(__imp__sub_827AF98C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF990"))) PPC_WEAK_FUNC(sub_827AF990);
PPC_FUNC_IMPL(__imp__sub_827AF990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-15952
	ctx.r5.s64 = r11.s64 + -15952;
	// addi r3,r10,-10840
	ctx.r3.s64 = ctx.r10.s64 + -10840;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF9AC"))) PPC_WEAK_FUNC(sub_827AF9AC);
PPC_FUNC_IMPL(__imp__sub_827AF9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF9B0"))) PPC_WEAK_FUNC(sub_827AF9B0);
PPC_FUNC_IMPL(__imp__sub_827AF9B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-15944
	ctx.r5.s64 = r11.s64 + -15944;
	// addi r3,r10,-10860
	ctx.r3.s64 = ctx.r10.s64 + -10860;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF9CC"))) PPC_WEAK_FUNC(sub_827AF9CC);
PPC_FUNC_IMPL(__imp__sub_827AF9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF9D0"))) PPC_WEAK_FUNC(sub_827AF9D0);
PPC_FUNC_IMPL(__imp__sub_827AF9D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-15928
	ctx.r5.s64 = r11.s64 + -15928;
	// addi r3,r10,-10820
	ctx.r3.s64 = ctx.r10.s64 + -10820;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF9EC"))) PPC_WEAK_FUNC(sub_827AF9EC);
PPC_FUNC_IMPL(__imp__sub_827AF9EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF9F0"))) PPC_WEAK_FUNC(sub_827AF9F0);
PPC_FUNC_IMPL(__imp__sub_827AF9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-12620
	ctx.r5.s64 = r11.s64 + -12620;
	// addi r3,r10,-10724
	ctx.r3.s64 = ctx.r10.s64 + -10724;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AFA0C"))) PPC_WEAK_FUNC(sub_827AFA0C);
PPC_FUNC_IMPL(__imp__sub_827AFA0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFA10"))) PPC_WEAK_FUNC(sub_827AFA10);
PPC_FUNC_IMPL(__imp__sub_827AFA10) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,-10744
	r31.s64 = r11.s64 + -10744;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b5a70
	ctx.lr = 0x827AFA30;
	sub_826B5A70(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// sth r10,16(r31)
	PPC_STORE_U16(r31.u32 + 16, ctx.r10.u16);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// sth r9,18(r31)
	PPC_STORE_U16(r31.u32 + 18, ctx.r9.u16);
	// addi r3,r10,-23080
	ctx.r3.s64 = ctx.r10.s64 + -23080;
	// bl 0x823d9a98
	ctx.lr = 0x827AFA54;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_827AFA68"))) PPC_WEAK_FUNC(sub_827AFA68);
PPC_FUNC_IMPL(__imp__sub_827AFA68) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-15672
	r11.s64 = r11.s64 + -15672;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x827bcff4
	ctx.lr = 0x827AFA84;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-23008
	ctx.r3.s64 = ctx.r10.s64 + -23008;
	// bl 0x823d9a98
	ctx.lr = 0x827AFA90;
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

__attribute__((alias("__imp__sub_827AFAA0"))) PPC_WEAK_FUNC(sub_827AFAA0);
PPC_FUNC_IMPL(__imp__sub_827AFAA0) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-15640
	r11.s64 = r11.s64 + -15640;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x827bcff4
	ctx.lr = 0x827AFABC;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-22984
	ctx.r3.s64 = ctx.r10.s64 + -22984;
	// bl 0x823d9a98
	ctx.lr = 0x827AFAC8;
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

__attribute__((alias("__imp__sub_827AFAD8"))) PPC_WEAK_FUNC(sub_827AFAD8);
PPC_FUNC_IMPL(__imp__sub_827AFAD8) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-15548
	r11.s64 = r11.s64 + -15548;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x827bcff4
	ctx.lr = 0x827AFAF4;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-22960
	ctx.r3.s64 = r11.s64 + -22960;
	// bl 0x823d9a98
	ctx.lr = 0x827AFB00;
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

__attribute__((alias("__imp__sub_827AFB10"))) PPC_WEAK_FUNC(sub_827AFB10);
PPC_FUNC_IMPL(__imp__sub_827AFB10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r11,12280
	ctx.r3.s64 = r11.s64 + 12280;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9890
	sub_823D9890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AFB24"))) PPC_WEAK_FUNC(sub_827AFB24);
PPC_FUNC_IMPL(__imp__sub_827AFB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFB28"))) PPC_WEAK_FUNC(sub_827AFB28);
PPC_FUNC_IMPL(__imp__sub_827AFB28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x827AFB30;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r27,3
	r27.s64 = 3;
	// addi r11,r11,14576
	r11.s64 = r11.s64 + 14576;
	// li r28,1
	r28.s64 = 1;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_827AFB5C:
	// lis r11,-32186
	r11.s64 = -2109341696;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r6,r11,20752
	ctx.r6.s64 = r11.s64 + 20752;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x821305f0
	ctx.lr = 0x827AFB74;
	sub_821305F0(ctx, base);
	// lwz r9,14568(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 14568);
	// stfs f31,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// addi r11,r31,45
	r11.s64 = r31.s64 + 45;
	// stb r28,-4(r31)
	PPC_STORE_U8(r31.u32 + -4, r28.u8);
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,14568(r29)
	PPC_STORE_U32(r29.u32 + 14568, ctx.r9.u32);
loc_827AFB94:
	// stb r30,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r30.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// stb r30,1(r11)
	PPC_STORE_U8(r11.u32 + 1, r30.u8);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bne 0x827afb94
	if (!cr0.eq) goto loc_827AFB94;
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r30.u32);
	// addi r31,r31,120
	r31.s64 = r31.s64 + 120;
	// bge 0x827afb5c
	if (!cr0.lt) goto loc_827AFB5C;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-22936
	ctx.r3.s64 = r11.s64 + -22936;
	// bl 0x823d9a98
	ctx.lr = 0x827AFBD8;
	sub_823D9A98(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827AFBE4"))) PPC_WEAK_FUNC(sub_827AFBE4);
PPC_FUNC_IMPL(__imp__sub_827AFBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFBE8"))) PPC_WEAK_FUNC(sub_827AFBE8);
PPC_FUNC_IMPL(__imp__sub_827AFBE8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,16112
	r31.s64 = r11.s64 + 16112;
	// addi r3,r31,2176
	ctx.r3.s64 = r31.s64 + 2176;
	// bl 0x821c8ed8
	ctx.lr = 0x827AFC08;
	sub_821C8ED8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x827AFC10;
	sub_821C9060(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,31
	ctx.r3.s64 = 31;
	// stw r11,2220(r31)
	PPC_STORE_U32(r31.u32 + 2220, r11.u32);
	// bl 0x821c9060
	ctx.lr = 0x827AFC20;
	sub_821C9060(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r3,2224(r31)
	PPC_STORE_U32(r31.u32 + 2224, ctx.r3.u32);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// stw r11,2216(r31)
	PPC_STORE_U32(r31.u32 + 2216, r11.u32);
	// stw r11,2212(r31)
	PPC_STORE_U32(r31.u32 + 2212, r11.u32);
	// addi r3,r10,-22928
	ctx.r3.s64 = ctx.r10.s64 + -22928;
	// stw r11,2208(r31)
	PPC_STORE_U32(r31.u32 + 2208, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AFC40;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_827AFC54"))) PPC_WEAK_FUNC(sub_827AFC54);
PPC_FUNC_IMPL(__imp__sub_827AFC54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFC58"))) PPC_WEAK_FUNC(sub_827AFC58);
PPC_FUNC_IMPL(__imp__sub_827AFC58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r5,r11,15432
	ctx.r5.s64 = r11.s64 + 15432;
	// addi r4,r10,-21540
	ctx.r4.s64 = ctx.r10.s64 + -21540;
	// addi r3,r9,18340
	ctx.r3.s64 = ctx.r9.s64 + 18340;
	// li r6,3187
	ctx.r6.s64 = 3187;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AFC78"))) PPC_WEAK_FUNC(sub_827AFC78);
PPC_FUNC_IMPL(__imp__sub_827AFC78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-22856
	ctx.r3.s64 = r11.s64 + -22856;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AFC84"))) PPC_WEAK_FUNC(sub_827AFC84);
PPC_FUNC_IMPL(__imp__sub_827AFC84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFC88"))) PPC_WEAK_FUNC(sub_827AFC88);
PPC_FUNC_IMPL(__imp__sub_827AFC88) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19332
	ctx.r3.s64 = ctx.r4.s64 + 19332;
	// addi r5,r5,-18524
	ctx.r5.s64 = ctx.r5.s64 + -18524;
	// li r9,60
	ctx.r9.s64 = 60;
	// addi r8,r11,-15840
	ctx.r8.s64 = r11.s64 + -15840;
	// addi r7,r10,-15928
	ctx.r7.s64 = ctx.r10.s64 + -15928;
	// addi r6,r6,-16056
	ctx.r6.s64 = ctx.r6.s64 + -16056;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x8246a038
	ctx.lr = 0x827AFCC8;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22824
	ctx.r3.s64 = ctx.r3.s64 + -22824;
	// bl 0x823d9a98
	ctx.lr = 0x827AFCD4;
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

__attribute__((alias("__imp__sub_827AFCE4"))) PPC_WEAK_FUNC(sub_827AFCE4);
PPC_FUNC_IMPL(__imp__sub_827AFCE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFCE8"))) PPC_WEAK_FUNC(sub_827AFCE8);
PPC_FUNC_IMPL(__imp__sub_827AFCE8) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19356
	ctx.r3.s64 = ctx.r4.s64 + 19356;
	// addi r5,r5,-16564
	ctx.r5.s64 = ctx.r5.s64 + -16564;
	// li r9,28
	ctx.r9.s64 = 28;
	// addi r8,r11,9816
	ctx.r8.s64 = r11.s64 + 9816;
	// addi r7,r10,9744
	ctx.r7.s64 = ctx.r10.s64 + 9744;
	// addi r6,r6,9600
	ctx.r6.s64 = ctx.r6.s64 + 9600;
	// li r4,23
	ctx.r4.s64 = 23;
	// bl 0x8246a038
	ctx.lr = 0x827AFD28;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22808
	ctx.r3.s64 = ctx.r3.s64 + -22808;
	// bl 0x823d9a98
	ctx.lr = 0x827AFD34;
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

__attribute__((alias("__imp__sub_827AFD44"))) PPC_WEAK_FUNC(sub_827AFD44);
PPC_FUNC_IMPL(__imp__sub_827AFD44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFD48"))) PPC_WEAK_FUNC(sub_827AFD48);
PPC_FUNC_IMPL(__imp__sub_827AFD48) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19380
	ctx.r3.s64 = ctx.r4.s64 + 19380;
	// addi r5,r5,-16212
	ctx.r5.s64 = ctx.r5.s64 + -16212;
	// li r9,296
	ctx.r9.s64 = 296;
	// addi r8,r11,10296
	ctx.r8.s64 = r11.s64 + 10296;
	// addi r7,r10,10224
	ctx.r7.s64 = ctx.r10.s64 + 10224;
	// addi r6,r6,10088
	ctx.r6.s64 = ctx.r6.s64 + 10088;
	// li r4,22
	ctx.r4.s64 = 22;
	// bl 0x8246a038
	ctx.lr = 0x827AFD88;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22792
	ctx.r3.s64 = ctx.r3.s64 + -22792;
	// bl 0x823d9a98
	ctx.lr = 0x827AFD94;
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

__attribute__((alias("__imp__sub_827AFDA4"))) PPC_WEAK_FUNC(sub_827AFDA4);
PPC_FUNC_IMPL(__imp__sub_827AFDA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFDA8"))) PPC_WEAK_FUNC(sub_827AFDA8);
PPC_FUNC_IMPL(__imp__sub_827AFDA8) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19404
	ctx.r3.s64 = ctx.r4.s64 + 19404;
	// addi r5,r5,-15860
	ctx.r5.s64 = ctx.r5.s64 + -15860;
	// li r9,44
	ctx.r9.s64 = 44;
	// addi r8,r11,11152
	ctx.r8.s64 = r11.s64 + 11152;
	// addi r7,r10,11136
	ctx.r7.s64 = ctx.r10.s64 + 11136;
	// addi r6,r6,11016
	ctx.r6.s64 = ctx.r6.s64 + 11016;
	// li r4,21
	ctx.r4.s64 = 21;
	// bl 0x8246a038
	ctx.lr = 0x827AFDE8;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22776
	ctx.r3.s64 = ctx.r3.s64 + -22776;
	// bl 0x823d9a98
	ctx.lr = 0x827AFDF4;
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

__attribute__((alias("__imp__sub_827AFE04"))) PPC_WEAK_FUNC(sub_827AFE04);
PPC_FUNC_IMPL(__imp__sub_827AFE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFE08"))) PPC_WEAK_FUNC(sub_827AFE08);
PPC_FUNC_IMPL(__imp__sub_827AFE08) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19428
	ctx.r3.s64 = ctx.r4.s64 + 19428;
	// addi r5,r5,-15508
	ctx.r5.s64 = ctx.r5.s64 + -15508;
	// li r9,40
	ctx.r9.s64 = 40;
	// addi r8,r11,11768
	ctx.r8.s64 = r11.s64 + 11768;
	// addi r7,r10,11688
	ctx.r7.s64 = ctx.r10.s64 + 11688;
	// addi r6,r6,11536
	ctx.r6.s64 = ctx.r6.s64 + 11536;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x8246a038
	ctx.lr = 0x827AFE48;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22760
	ctx.r3.s64 = ctx.r3.s64 + -22760;
	// bl 0x823d9a98
	ctx.lr = 0x827AFE54;
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

__attribute__((alias("__imp__sub_827AFE64"))) PPC_WEAK_FUNC(sub_827AFE64);
PPC_FUNC_IMPL(__imp__sub_827AFE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFE68"))) PPC_WEAK_FUNC(sub_827AFE68);
PPC_FUNC_IMPL(__imp__sub_827AFE68) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19452
	ctx.r3.s64 = ctx.r4.s64 + 19452;
	// addi r5,r5,-15156
	ctx.r5.s64 = ctx.r5.s64 + -15156;
	// li r9,52
	ctx.r9.s64 = 52;
	// addi r8,r11,12608
	ctx.r8.s64 = r11.s64 + 12608;
	// addi r7,r10,12592
	ctx.r7.s64 = ctx.r10.s64 + 12592;
	// addi r6,r6,12472
	ctx.r6.s64 = ctx.r6.s64 + 12472;
	// li r4,18
	ctx.r4.s64 = 18;
	// bl 0x8246a038
	ctx.lr = 0x827AFEA8;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22744
	ctx.r3.s64 = ctx.r3.s64 + -22744;
	// bl 0x823d9a98
	ctx.lr = 0x827AFEB4;
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

__attribute__((alias("__imp__sub_827AFEC4"))) PPC_WEAK_FUNC(sub_827AFEC4);
PPC_FUNC_IMPL(__imp__sub_827AFEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFEC8"))) PPC_WEAK_FUNC(sub_827AFEC8);
PPC_FUNC_IMPL(__imp__sub_827AFEC8) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19476
	ctx.r3.s64 = ctx.r4.s64 + 19476;
	// addi r5,r5,-14720
	ctx.r5.s64 = ctx.r5.s64 + -14720;
	// li r9,296
	ctx.r9.s64 = 296;
	// addi r8,r11,15072
	ctx.r8.s64 = r11.s64 + 15072;
	// addi r7,r10,15000
	ctx.r7.s64 = ctx.r10.s64 + 15000;
	// addi r6,r6,14864
	ctx.r6.s64 = ctx.r6.s64 + 14864;
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8246a038
	ctx.lr = 0x827AFF08;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22728
	ctx.r3.s64 = ctx.r3.s64 + -22728;
	// bl 0x823d9a98
	ctx.lr = 0x827AFF14;
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

__attribute__((alias("__imp__sub_827AFF24"))) PPC_WEAK_FUNC(sub_827AFF24);
PPC_FUNC_IMPL(__imp__sub_827AFF24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFF28"))) PPC_WEAK_FUNC(sub_827AFF28);
PPC_FUNC_IMPL(__imp__sub_827AFF28) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19500
	ctx.r3.s64 = ctx.r4.s64 + 19500;
	// addi r5,r5,-14372
	ctx.r5.s64 = ctx.r5.s64 + -14372;
	// li r9,36
	ctx.r9.s64 = 36;
	// addi r8,r11,15592
	ctx.r8.s64 = r11.s64 + 15592;
	// addi r7,r10,15512
	ctx.r7.s64 = ctx.r10.s64 + 15512;
	// addi r6,r6,15360
	ctx.r6.s64 = ctx.r6.s64 + 15360;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8246a038
	ctx.lr = 0x827AFF68;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22712
	ctx.r3.s64 = ctx.r3.s64 + -22712;
	// bl 0x823d9a98
	ctx.lr = 0x827AFF74;
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

__attribute__((alias("__imp__sub_827AFF84"))) PPC_WEAK_FUNC(sub_827AFF84);
PPC_FUNC_IMPL(__imp__sub_827AFF84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFF88"))) PPC_WEAK_FUNC(sub_827AFF88);
PPC_FUNC_IMPL(__imp__sub_827AFF88) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19524
	ctx.r3.s64 = ctx.r4.s64 + 19524;
	// addi r5,r5,-14020
	ctx.r5.s64 = ctx.r5.s64 + -14020;
	// li r9,36
	ctx.r9.s64 = 36;
	// addi r8,r11,16320
	ctx.r8.s64 = r11.s64 + 16320;
	// addi r7,r10,16240
	ctx.r7.s64 = ctx.r10.s64 + 16240;
	// addi r6,r6,16096
	ctx.r6.s64 = ctx.r6.s64 + 16096;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8246a038
	ctx.lr = 0x827AFFC8;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22696
	ctx.r3.s64 = ctx.r3.s64 + -22696;
	// bl 0x823d9a98
	ctx.lr = 0x827AFFD4;
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

__attribute__((alias("__imp__sub_827AFFE4"))) PPC_WEAK_FUNC(sub_827AFFE4);
PPC_FUNC_IMPL(__imp__sub_827AFFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AFFE8"))) PPC_WEAK_FUNC(sub_827AFFE8);
PPC_FUNC_IMPL(__imp__sub_827AFFE8) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19548
	ctx.r3.s64 = ctx.r4.s64 + 19548;
	// addi r5,r5,-13668
	ctx.r5.s64 = ctx.r5.s64 + -13668;
	// li r9,36
	ctx.r9.s64 = 36;
	// addi r8,r11,16968
	ctx.r8.s64 = r11.s64 + 16968;
	// addi r7,r10,16888
	ctx.r7.s64 = ctx.r10.s64 + 16888;
	// addi r6,r6,16736
	ctx.r6.s64 = ctx.r6.s64 + 16736;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x8246a038
	ctx.lr = 0x827B0028;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22680
	ctx.r3.s64 = ctx.r3.s64 + -22680;
	// bl 0x823d9a98
	ctx.lr = 0x827B0034;
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

__attribute__((alias("__imp__sub_827B0044"))) PPC_WEAK_FUNC(sub_827B0044);
PPC_FUNC_IMPL(__imp__sub_827B0044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0048"))) PPC_WEAK_FUNC(sub_827B0048);
PPC_FUNC_IMPL(__imp__sub_827B0048) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19572
	ctx.r3.s64 = ctx.r4.s64 + 19572;
	// addi r5,r5,-13312
	ctx.r5.s64 = ctx.r5.s64 + -13312;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r11,17624
	ctx.r8.s64 = r11.s64 + 17624;
	// addi r7,r10,17552
	ctx.r7.s64 = ctx.r10.s64 + 17552;
	// addi r6,r6,17408
	ctx.r6.s64 = ctx.r6.s64 + 17408;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8246a038
	ctx.lr = 0x827B0088;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22664
	ctx.r3.s64 = ctx.r3.s64 + -22664;
	// bl 0x823d9a98
	ctx.lr = 0x827B0094;
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

__attribute__((alias("__imp__sub_827B00A4"))) PPC_WEAK_FUNC(sub_827B00A4);
PPC_FUNC_IMPL(__imp__sub_827B00A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B00A8"))) PPC_WEAK_FUNC(sub_827B00A8);
PPC_FUNC_IMPL(__imp__sub_827B00A8) {
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
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lis r11,-32185
	r11.s64 = -2109276160;
	// lis r10,-32185
	ctx.r10.s64 = -2109276160;
	// lis r6,-32185
	ctx.r6.s64 = -2109276160;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r3,r4,19596
	ctx.r3.s64 = ctx.r4.s64 + 19596;
	// addi r5,r5,-12816
	ctx.r5.s64 = ctx.r5.s64 + -12816;
	// li r9,52
	ctx.r9.s64 = 52;
	// addi r8,r11,19648
	ctx.r8.s64 = r11.s64 + 19648;
	// addi r7,r10,19632
	ctx.r7.s64 = ctx.r10.s64 + 19632;
	// addi r6,r6,19504
	ctx.r6.s64 = ctx.r6.s64 + 19504;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8246a038
	ctx.lr = 0x827B00E8;
	sub_8246A038(ctx, base);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// addi r3,r3,-22648
	ctx.r3.s64 = ctx.r3.s64 + -22648;
	// bl 0x823d9a98
	ctx.lr = 0x827B00F4;
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

__attribute__((alias("__imp__sub_827B0104"))) PPC_WEAK_FUNC(sub_827B0104);
PPC_FUNC_IMPL(__imp__sub_827B0104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0108"))) PPC_WEAK_FUNC(sub_827B0108);
PPC_FUNC_IMPL(__imp__sub_827B0108) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-12044
	ctx.r5.s64 = r11.s64 + -12044;
	// addi r3,r10,19664
	ctx.r3.s64 = ctx.r10.s64 + 19664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B0124"))) PPC_WEAK_FUNC(sub_827B0124);
PPC_FUNC_IMPL(__imp__sub_827B0124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0128"))) PPC_WEAK_FUNC(sub_827B0128);
PPC_FUNC_IMPL(__imp__sub_827B0128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-12032
	ctx.r5.s64 = r11.s64 + -12032;
	// addi r3,r10,19624
	ctx.r3.s64 = ctx.r10.s64 + 19624;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B0144"))) PPC_WEAK_FUNC(sub_827B0144);
PPC_FUNC_IMPL(__imp__sub_827B0144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0148"))) PPC_WEAK_FUNC(sub_827B0148);
PPC_FUNC_IMPL(__imp__sub_827B0148) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,13544
	ctx.r5.s64 = r11.s64 + 13544;
	// addi r3,r10,19644
	ctx.r3.s64 = ctx.r10.s64 + 19644;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B0164"))) PPC_WEAK_FUNC(sub_827B0164);
PPC_FUNC_IMPL(__imp__sub_827B0164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0168"))) PPC_WEAK_FUNC(sub_827B0168);
PPC_FUNC_IMPL(__imp__sub_827B0168) {
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
	ctx.lr = 0x827B0190;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,20300
	r11.s64 = ctx.r7.s64 + 20300;
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

__attribute__((alias("__imp__sub_827B01DC"))) PPC_WEAK_FUNC(sub_827B01DC);
PPC_FUNC_IMPL(__imp__sub_827B01DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B01E0"))) PPC_WEAK_FUNC(sub_827B01E0);
PPC_FUNC_IMPL(__imp__sub_827B01E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,20348
	ctx.r7.s64 = ctx.r8.s64 + 20348;
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

__attribute__((alias("__imp__sub_827B0200"))) PPC_WEAK_FUNC(sub_827B0200);
PPC_FUNC_IMPL(__imp__sub_827B0200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-22632
	ctx.r3.s64 = r11.s64 + -22632;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B020C"))) PPC_WEAK_FUNC(sub_827B020C);
PPC_FUNC_IMPL(__imp__sub_827B020C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0210"))) PPC_WEAK_FUNC(sub_827B0210);
PPC_FUNC_IMPL(__imp__sub_827B0210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-22600
	ctx.r3.s64 = r11.s64 + -22600;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B021C"))) PPC_WEAK_FUNC(sub_827B021C);
PPC_FUNC_IMPL(__imp__sub_827B021C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0220"))) PPC_WEAK_FUNC(sub_827B0220);
PPC_FUNC_IMPL(__imp__sub_827B0220) {
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
	ctx.lr = 0x827B0248;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,21064
	r11.s64 = ctx.r7.s64 + 21064;
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

__attribute__((alias("__imp__sub_827B0294"))) PPC_WEAK_FUNC(sub_827B0294);
PPC_FUNC_IMPL(__imp__sub_827B0294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0298"))) PPC_WEAK_FUNC(sub_827B0298);
PPC_FUNC_IMPL(__imp__sub_827B0298) {
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
	ctx.lr = 0x827B02C0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,21112
	r11.s64 = ctx.r7.s64 + 21112;
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

__attribute__((alias("__imp__sub_827B030C"))) PPC_WEAK_FUNC(sub_827B030C);
PPC_FUNC_IMPL(__imp__sub_827B030C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0310"))) PPC_WEAK_FUNC(sub_827B0310);
PPC_FUNC_IMPL(__imp__sub_827B0310) {
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
	ctx.lr = 0x827B0338;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,21160
	r11.s64 = ctx.r7.s64 + 21160;
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

__attribute__((alias("__imp__sub_827B0384"))) PPC_WEAK_FUNC(sub_827B0384);
PPC_FUNC_IMPL(__imp__sub_827B0384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0388"))) PPC_WEAK_FUNC(sub_827B0388);
PPC_FUNC_IMPL(__imp__sub_827B0388) {
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
	ctx.lr = 0x827B03B0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,21208
	r11.s64 = ctx.r7.s64 + 21208;
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

__attribute__((alias("__imp__sub_827B03FC"))) PPC_WEAK_FUNC(sub_827B03FC);
PPC_FUNC_IMPL(__imp__sub_827B03FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0400"))) PPC_WEAK_FUNC(sub_827B0400);
PPC_FUNC_IMPL(__imp__sub_827B0400) {
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
	// addi r5,r11,-17376
	ctx.r5.s64 = r11.s64 + -17376;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B0428;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,21256
	r11.s64 = ctx.r7.s64 + 21256;
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

__attribute__((alias("__imp__sub_827B0474"))) PPC_WEAK_FUNC(sub_827B0474);
PPC_FUNC_IMPL(__imp__sub_827B0474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0478"))) PPC_WEAK_FUNC(sub_827B0478);
PPC_FUNC_IMPL(__imp__sub_827B0478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,21304
	ctx.r7.s64 = ctx.r8.s64 + 21304;
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

__attribute__((alias("__imp__sub_827B0498"))) PPC_WEAK_FUNC(sub_827B0498);
PPC_FUNC_IMPL(__imp__sub_827B0498) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,21312
	ctx.r7.s64 = ctx.r8.s64 + 21312;
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

__attribute__((alias("__imp__sub_827B04B8"))) PPC_WEAK_FUNC(sub_827B04B8);
PPC_FUNC_IMPL(__imp__sub_827B04B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,21320
	ctx.r7.s64 = ctx.r8.s64 + 21320;
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

__attribute__((alias("__imp__sub_827B04D8"))) PPC_WEAK_FUNC(sub_827B04D8);
PPC_FUNC_IMPL(__imp__sub_827B04D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,21328
	ctx.r7.s64 = ctx.r8.s64 + 21328;
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

__attribute__((alias("__imp__sub_827B04F8"))) PPC_WEAK_FUNC(sub_827B04F8);
PPC_FUNC_IMPL(__imp__sub_827B04F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,-31648
	ctx.r7.s64 = ctx.r8.s64 + -31648;
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

__attribute__((alias("__imp__sub_827B0518"))) PPC_WEAK_FUNC(sub_827B0518);
PPC_FUNC_IMPL(__imp__sub_827B0518) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r5,r11,21376
	ctx.r5.s64 = r11.s64 + 21376;
	// addi r4,r10,-8912
	ctx.r4.s64 = ctx.r10.s64 + -8912;
	// addi r3,r9,19756
	ctx.r3.s64 = ctx.r9.s64 + 19756;
	// li r6,3612
	ctx.r6.s64 = 3612;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B0538"))) PPC_WEAK_FUNC(sub_827B0538);
PPC_FUNC_IMPL(__imp__sub_827B0538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r5,r11,24992
	ctx.r5.s64 = r11.s64 + 24992;
	// addi r4,r10,-8880
	ctx.r4.s64 = ctx.r10.s64 + -8880;
	// addi r3,r9,19808
	ctx.r3.s64 = ctx.r9.s64 + 19808;
	// li r6,8133
	ctx.r6.s64 = 8133;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B0558"))) PPC_WEAK_FUNC(sub_827B0558);
PPC_FUNC_IMPL(__imp__sub_827B0558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r5,r11,-32408
	ctx.r5.s64 = r11.s64 + -32408;
	// addi r4,r10,-8848
	ctx.r4.s64 = ctx.r10.s64 + -8848;
	// addi r3,r9,19772
	ctx.r3.s64 = ctx.r9.s64 + 19772;
	// li r6,138
	ctx.r6.s64 = 138;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B0578"))) PPC_WEAK_FUNC(sub_827B0578);
PPC_FUNC_IMPL(__imp__sub_827B0578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r5,r11,-32264
	ctx.r5.s64 = r11.s64 + -32264;
	// addi r4,r10,-8824
	ctx.r4.s64 = ctx.r10.s64 + -8824;
	// addi r3,r9,19740
	ctx.r3.s64 = ctx.r9.s64 + 19740;
	// li r6,138
	ctx.r6.s64 = 138;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B0598"))) PPC_WEAK_FUNC(sub_827B0598);
PPC_FUNC_IMPL(__imp__sub_827B0598) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8796
	ctx.r5.s64 = r11.s64 + -8796;
	// addi r3,r10,19824
	ctx.r3.s64 = ctx.r10.s64 + 19824;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B05B4"))) PPC_WEAK_FUNC(sub_827B05B4);
PPC_FUNC_IMPL(__imp__sub_827B05B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B05B8"))) PPC_WEAK_FUNC(sub_827B05B8);
PPC_FUNC_IMPL(__imp__sub_827B05B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8780
	ctx.r5.s64 = r11.s64 + -8780;
	// addi r3,r10,19788
	ctx.r3.s64 = ctx.r10.s64 + 19788;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B05D4"))) PPC_WEAK_FUNC(sub_827B05D4);
PPC_FUNC_IMPL(__imp__sub_827B05D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B05D8"))) PPC_WEAK_FUNC(sub_827B05D8);
PPC_FUNC_IMPL(__imp__sub_827B05D8) {
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
	// addi r30,r31,20296
	r30.s64 = r31.s64 + 20296;
	// addi r5,r11,-7900
	ctx.r5.s64 = r11.s64 + -7900;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824fa650
	ctx.lr = 0x827B060C;
	sub_824FA650(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20296(r31)
	PPC_STORE_U32(r31.u32 + 20296, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B061C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0624;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r11,r11,-7904
	r11.s64 = r11.s64 + -7904;
	// addi r3,r10,-22552
	ctx.r3.s64 = ctx.r10.s64 + -22552;
	// stw r11,20296(r31)
	PPC_STORE_U32(r31.u32 + 20296, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B063C;
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

__attribute__((alias("__imp__sub_827B0654"))) PPC_WEAK_FUNC(sub_827B0654);
PPC_FUNC_IMPL(__imp__sub_827B0654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0658"))) PPC_WEAK_FUNC(sub_827B0658);
PPC_FUNC_IMPL(__imp__sub_827B0658) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20168
	r30.s64 = r31.s64 + 20168;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7884
	ctx.r6.s64 = ctx.r10.s64 + -7884;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B0694;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20168(r31)
	PPC_STORE_U32(r31.u32 + 20168, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B06A4;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B06AC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7888
	r11.s64 = r11.s64 + -7888;
	// addi r3,r9,-22464
	ctx.r3.s64 = ctx.r9.s64 + -22464;
	// stw r11,20168(r31)
	PPC_STORE_U32(r31.u32 + 20168, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B06C4;
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

__attribute__((alias("__imp__sub_827B06DC"))) PPC_WEAK_FUNC(sub_827B06DC);
PPC_FUNC_IMPL(__imp__sub_827B06DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B06E0"))) PPC_WEAK_FUNC(sub_827B06E0);
PPC_FUNC_IMPL(__imp__sub_827B06E0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20104
	r30.s64 = r31.s64 + 20104;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7856
	ctx.r6.s64 = ctx.r10.s64 + -7856;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B071C;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20104(r31)
	PPC_STORE_U32(r31.u32 + 20104, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B072C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0734;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7860
	r11.s64 = r11.s64 + -7860;
	// addi r3,r9,-22376
	ctx.r3.s64 = ctx.r9.s64 + -22376;
	// stw r11,20104(r31)
	PPC_STORE_U32(r31.u32 + 20104, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B074C;
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

__attribute__((alias("__imp__sub_827B0764"))) PPC_WEAK_FUNC(sub_827B0764);
PPC_FUNC_IMPL(__imp__sub_827B0764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0768"))) PPC_WEAK_FUNC(sub_827B0768);
PPC_FUNC_IMPL(__imp__sub_827B0768) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,19944
	r30.s64 = r31.s64 + 19944;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7824
	ctx.r6.s64 = ctx.r10.s64 + -7824;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B07A4;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,19944(r31)
	PPC_STORE_U32(r31.u32 + 19944, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B07B4;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B07BC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7828
	r11.s64 = r11.s64 + -7828;
	// addi r3,r9,-22288
	ctx.r3.s64 = ctx.r9.s64 + -22288;
	// stw r11,19944(r31)
	PPC_STORE_U32(r31.u32 + 19944, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B07D4;
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

__attribute__((alias("__imp__sub_827B07EC"))) PPC_WEAK_FUNC(sub_827B07EC);
PPC_FUNC_IMPL(__imp__sub_827B07EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B07F0"))) PPC_WEAK_FUNC(sub_827B07F0);
PPC_FUNC_IMPL(__imp__sub_827B07F0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20232
	r30.s64 = r31.s64 + 20232;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7792
	ctx.r6.s64 = ctx.r10.s64 + -7792;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B082C;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20232(r31)
	PPC_STORE_U32(r31.u32 + 20232, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B083C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0844;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7796
	r11.s64 = r11.s64 + -7796;
	// addi r3,r9,-22200
	ctx.r3.s64 = ctx.r9.s64 + -22200;
	// stw r11,20232(r31)
	PPC_STORE_U32(r31.u32 + 20232, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B085C;
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

__attribute__((alias("__imp__sub_827B0874"))) PPC_WEAK_FUNC(sub_827B0874);
PPC_FUNC_IMPL(__imp__sub_827B0874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0878"))) PPC_WEAK_FUNC(sub_827B0878);
PPC_FUNC_IMPL(__imp__sub_827B0878) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,19912
	r30.s64 = r31.s64 + 19912;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7764
	ctx.r6.s64 = ctx.r10.s64 + -7764;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B08B4;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,19912(r31)
	PPC_STORE_U32(r31.u32 + 19912, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B08C4;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B08CC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7768
	r11.s64 = r11.s64 + -7768;
	// addi r3,r9,-22112
	ctx.r3.s64 = ctx.r9.s64 + -22112;
	// stw r11,19912(r31)
	PPC_STORE_U32(r31.u32 + 19912, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B08E4;
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

__attribute__((alias("__imp__sub_827B08FC"))) PPC_WEAK_FUNC(sub_827B08FC);
PPC_FUNC_IMPL(__imp__sub_827B08FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0900"))) PPC_WEAK_FUNC(sub_827B0900);
PPC_FUNC_IMPL(__imp__sub_827B0900) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20008
	r30.s64 = r31.s64 + 20008;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7736
	ctx.r6.s64 = ctx.r10.s64 + -7736;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B093C;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20008(r31)
	PPC_STORE_U32(r31.u32 + 20008, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B094C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0954;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7740
	r11.s64 = r11.s64 + -7740;
	// addi r3,r9,-22024
	ctx.r3.s64 = ctx.r9.s64 + -22024;
	// stw r11,20008(r31)
	PPC_STORE_U32(r31.u32 + 20008, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B096C;
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

__attribute__((alias("__imp__sub_827B0984"))) PPC_WEAK_FUNC(sub_827B0984);
PPC_FUNC_IMPL(__imp__sub_827B0984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0988"))) PPC_WEAK_FUNC(sub_827B0988);
PPC_FUNC_IMPL(__imp__sub_827B0988) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,19880
	r30.s64 = r31.s64 + 19880;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7708
	ctx.r6.s64 = ctx.r10.s64 + -7708;
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B09C4;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,19880(r31)
	PPC_STORE_U32(r31.u32 + 19880, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B09D4;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B09DC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7712
	r11.s64 = r11.s64 + -7712;
	// addi r3,r9,-21936
	ctx.r3.s64 = ctx.r9.s64 + -21936;
	// stw r11,19880(r31)
	PPC_STORE_U32(r31.u32 + 19880, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B09F4;
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

__attribute__((alias("__imp__sub_827B0A0C"))) PPC_WEAK_FUNC(sub_827B0A0C);
PPC_FUNC_IMPL(__imp__sub_827B0A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0A10"))) PPC_WEAK_FUNC(sub_827B0A10);
PPC_FUNC_IMPL(__imp__sub_827B0A10) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20136
	r30.s64 = r31.s64 + 20136;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7680
	ctx.r6.s64 = ctx.r10.s64 + -7680;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B0A4C;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20136(r31)
	PPC_STORE_U32(r31.u32 + 20136, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B0A5C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0A64;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7684
	r11.s64 = r11.s64 + -7684;
	// addi r3,r9,-21848
	ctx.r3.s64 = ctx.r9.s64 + -21848;
	// stw r11,20136(r31)
	PPC_STORE_U32(r31.u32 + 20136, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B0A7C;
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

__attribute__((alias("__imp__sub_827B0A94"))) PPC_WEAK_FUNC(sub_827B0A94);
PPC_FUNC_IMPL(__imp__sub_827B0A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0A98"))) PPC_WEAK_FUNC(sub_827B0A98);
PPC_FUNC_IMPL(__imp__sub_827B0A98) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20072
	r30.s64 = r31.s64 + 20072;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7648
	ctx.r6.s64 = ctx.r10.s64 + -7648;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B0AD4;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20072(r31)
	PPC_STORE_U32(r31.u32 + 20072, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B0AE4;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0AEC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7652
	r11.s64 = r11.s64 + -7652;
	// addi r3,r9,-21760
	ctx.r3.s64 = ctx.r9.s64 + -21760;
	// stw r11,20072(r31)
	PPC_STORE_U32(r31.u32 + 20072, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B0B04;
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

__attribute__((alias("__imp__sub_827B0B1C"))) PPC_WEAK_FUNC(sub_827B0B1C);
PPC_FUNC_IMPL(__imp__sub_827B0B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0B20"))) PPC_WEAK_FUNC(sub_827B0B20);
PPC_FUNC_IMPL(__imp__sub_827B0B20) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20040
	r30.s64 = r31.s64 + 20040;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7620
	ctx.r6.s64 = ctx.r10.s64 + -7620;
	// li r5,9
	ctx.r5.s64 = 9;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B0B5C;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20040(r31)
	PPC_STORE_U32(r31.u32 + 20040, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B0B6C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0B74;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7624
	r11.s64 = r11.s64 + -7624;
	// addi r3,r9,-21672
	ctx.r3.s64 = ctx.r9.s64 + -21672;
	// stw r11,20040(r31)
	PPC_STORE_U32(r31.u32 + 20040, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B0B8C;
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

__attribute__((alias("__imp__sub_827B0BA4"))) PPC_WEAK_FUNC(sub_827B0BA4);
PPC_FUNC_IMPL(__imp__sub_827B0BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0BA8"))) PPC_WEAK_FUNC(sub_827B0BA8);
PPC_FUNC_IMPL(__imp__sub_827B0BA8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20200
	r30.s64 = r31.s64 + 20200;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7584
	ctx.r6.s64 = ctx.r10.s64 + -7584;
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B0BE4;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20200(r31)
	PPC_STORE_U32(r31.u32 + 20200, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B0BF4;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0BFC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7588
	r11.s64 = r11.s64 + -7588;
	// addi r3,r9,-21584
	ctx.r3.s64 = ctx.r9.s64 + -21584;
	// stw r11,20200(r31)
	PPC_STORE_U32(r31.u32 + 20200, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B0C14;
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

__attribute__((alias("__imp__sub_827B0C2C"))) PPC_WEAK_FUNC(sub_827B0C2C);
PPC_FUNC_IMPL(__imp__sub_827B0C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0C30"))) PPC_WEAK_FUNC(sub_827B0C30);
PPC_FUNC_IMPL(__imp__sub_827B0C30) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,19976
	r30.s64 = r31.s64 + 19976;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7548
	ctx.r6.s64 = ctx.r10.s64 + -7548;
	// li r5,11
	ctx.r5.s64 = 11;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B0C6C;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,19976(r31)
	PPC_STORE_U32(r31.u32 + 19976, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B0C7C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0C84;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7552
	r11.s64 = r11.s64 + -7552;
	// addi r3,r9,-21496
	ctx.r3.s64 = ctx.r9.s64 + -21496;
	// stw r11,19976(r31)
	PPC_STORE_U32(r31.u32 + 19976, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B0C9C;
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

__attribute__((alias("__imp__sub_827B0CB4"))) PPC_WEAK_FUNC(sub_827B0CB4);
PPC_FUNC_IMPL(__imp__sub_827B0CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B0CB8"))) PPC_WEAK_FUNC(sub_827B0CB8);
PPC_FUNC_IMPL(__imp__sub_827B0CB8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,20264
	r30.s64 = r31.s64 + 20264;
	// addi r7,r11,20296
	ctx.r7.s64 = r11.s64 + 20296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-7512
	ctx.r6.s64 = ctx.r10.s64 + -7512;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B0CF4;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20264(r31)
	PPC_STORE_U32(r31.u32 + 20264, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827B0D04;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B0D0C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-7516
	r11.s64 = r11.s64 + -7516;
	// addi r3,r9,-21408
	ctx.r3.s64 = ctx.r9.s64 + -21408;
	// stw r11,20264(r31)
	PPC_STORE_U32(r31.u32 + 20264, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B0D24;
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

