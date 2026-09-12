#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827B6D24"))) PPC_WEAK_FUNC(sub_827B6D24);
PPC_FUNC_IMPL(__imp__sub_827B6D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6D28"))) PPC_WEAK_FUNC(sub_827B6D28);
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

__attribute__((alias("__imp__sub_827B6D44"))) PPC_WEAK_FUNC(sub_827B6D44);
PPC_FUNC_IMPL(__imp__sub_827B6D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6D48"))) PPC_WEAK_FUNC(sub_827B6D48);
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

__attribute__((alias("__imp__sub_827B6D64"))) PPC_WEAK_FUNC(sub_827B6D64);
PPC_FUNC_IMPL(__imp__sub_827B6D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6D68"))) PPC_WEAK_FUNC(sub_827B6D68);
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

__attribute__((alias("__imp__sub_827B6D84"))) PPC_WEAK_FUNC(sub_827B6D84);
PPC_FUNC_IMPL(__imp__sub_827B6D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6D88"))) PPC_WEAK_FUNC(sub_827B6D88);
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

__attribute__((alias("__imp__sub_827B6DA4"))) PPC_WEAK_FUNC(sub_827B6DA4);
PPC_FUNC_IMPL(__imp__sub_827B6DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6DA8"))) PPC_WEAK_FUNC(sub_827B6DA8);
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

__attribute__((alias("__imp__sub_827B6E1C"))) PPC_WEAK_FUNC(sub_827B6E1C);
PPC_FUNC_IMPL(__imp__sub_827B6E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6E20"))) PPC_WEAK_FUNC(sub_827B6E20);
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

__attribute__((alias("__imp__sub_827B6E94"))) PPC_WEAK_FUNC(sub_827B6E94);
PPC_FUNC_IMPL(__imp__sub_827B6E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6E98"))) PPC_WEAK_FUNC(sub_827B6E98);
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

__attribute__((alias("__imp__sub_827B6F0C"))) PPC_WEAK_FUNC(sub_827B6F0C);
PPC_FUNC_IMPL(__imp__sub_827B6F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6F10"))) PPC_WEAK_FUNC(sub_827B6F10);
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

__attribute__((alias("__imp__sub_827B6F84"))) PPC_WEAK_FUNC(sub_827B6F84);
PPC_FUNC_IMPL(__imp__sub_827B6F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6F88"))) PPC_WEAK_FUNC(sub_827B6F88);
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

__attribute__((alias("__imp__sub_827B6FFC"))) PPC_WEAK_FUNC(sub_827B6FFC);
PPC_FUNC_IMPL(__imp__sub_827B6FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7000"))) PPC_WEAK_FUNC(sub_827B7000);
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

__attribute__((alias("__imp__sub_827B7074"))) PPC_WEAK_FUNC(sub_827B7074);
PPC_FUNC_IMPL(__imp__sub_827B7074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7078"))) PPC_WEAK_FUNC(sub_827B7078);
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

__attribute__((alias("__imp__sub_827B70EC"))) PPC_WEAK_FUNC(sub_827B70EC);
PPC_FUNC_IMPL(__imp__sub_827B70EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B70F0"))) PPC_WEAK_FUNC(sub_827B70F0);
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

__attribute__((alias("__imp__sub_827B7164"))) PPC_WEAK_FUNC(sub_827B7164);
PPC_FUNC_IMPL(__imp__sub_827B7164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7168"))) PPC_WEAK_FUNC(sub_827B7168);
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

__attribute__((alias("__imp__sub_827B7184"))) PPC_WEAK_FUNC(sub_827B7184);
PPC_FUNC_IMPL(__imp__sub_827B7184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7188"))) PPC_WEAK_FUNC(sub_827B7188);
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

__attribute__((alias("__imp__sub_827B71A4"))) PPC_WEAK_FUNC(sub_827B71A4);
PPC_FUNC_IMPL(__imp__sub_827B71A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B71A8"))) PPC_WEAK_FUNC(sub_827B71A8);
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

__attribute__((alias("__imp__sub_827B71E8"))) PPC_WEAK_FUNC(sub_827B71E8);
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

__attribute__((alias("__imp__sub_827B725C"))) PPC_WEAK_FUNC(sub_827B725C);
PPC_FUNC_IMPL(__imp__sub_827B725C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7260"))) PPC_WEAK_FUNC(sub_827B7260);
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

__attribute__((alias("__imp__sub_827B72D4"))) PPC_WEAK_FUNC(sub_827B72D4);
PPC_FUNC_IMPL(__imp__sub_827B72D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B72D8"))) PPC_WEAK_FUNC(sub_827B72D8);
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

__attribute__((alias("__imp__sub_827B734C"))) PPC_WEAK_FUNC(sub_827B734C);
PPC_FUNC_IMPL(__imp__sub_827B734C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7350"))) PPC_WEAK_FUNC(sub_827B7350);
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

__attribute__((alias("__imp__sub_827B73C4"))) PPC_WEAK_FUNC(sub_827B73C4);
PPC_FUNC_IMPL(__imp__sub_827B73C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B73C8"))) PPC_WEAK_FUNC(sub_827B73C8);
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

__attribute__((alias("__imp__sub_827B73E8"))) PPC_WEAK_FUNC(sub_827B73E8);
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

__attribute__((alias("__imp__sub_827B7408"))) PPC_WEAK_FUNC(sub_827B7408);
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

__attribute__((alias("__imp__sub_827B7428"))) PPC_WEAK_FUNC(sub_827B7428);
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

__attribute__((alias("__imp__sub_827B7448"))) PPC_WEAK_FUNC(sub_827B7448);
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

__attribute__((alias("__imp__sub_827B7468"))) PPC_WEAK_FUNC(sub_827B7468);
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

__attribute__((alias("__imp__sub_827B7488"))) PPC_WEAK_FUNC(sub_827B7488);
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

__attribute__((alias("__imp__sub_827B74A8"))) PPC_WEAK_FUNC(sub_827B74A8);
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

__attribute__((alias("__imp__sub_827B74C4"))) PPC_WEAK_FUNC(sub_827B74C4);
PPC_FUNC_IMPL(__imp__sub_827B74C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B74C8"))) PPC_WEAK_FUNC(sub_827B74C8);
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

__attribute__((alias("__imp__sub_827B7548"))) PPC_WEAK_FUNC(sub_827B7548);
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

__attribute__((alias("__imp__sub_827B75C8"))) PPC_WEAK_FUNC(sub_827B75C8);
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

__attribute__((alias("__imp__sub_827B7648"))) PPC_WEAK_FUNC(sub_827B7648);
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

__attribute__((alias("__imp__sub_827B76C8"))) PPC_WEAK_FUNC(sub_827B76C8);
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

__attribute__((alias("__imp__sub_827B7748"))) PPC_WEAK_FUNC(sub_827B7748);
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

__attribute__((alias("__imp__sub_827B7754"))) PPC_WEAK_FUNC(sub_827B7754);
PPC_FUNC_IMPL(__imp__sub_827B7754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7758"))) PPC_WEAK_FUNC(sub_827B7758);
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

__attribute__((alias("__imp__sub_827B7778"))) PPC_WEAK_FUNC(sub_827B7778);
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

__attribute__((alias("__imp__sub_827B77EC"))) PPC_WEAK_FUNC(sub_827B77EC);
PPC_FUNC_IMPL(__imp__sub_827B77EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B77F0"))) PPC_WEAK_FUNC(sub_827B77F0);
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

__attribute__((alias("__imp__sub_827B7810"))) PPC_WEAK_FUNC(sub_827B7810);
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

__attribute__((alias("__imp__sub_827B7830"))) PPC_WEAK_FUNC(sub_827B7830);
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

__attribute__((alias("__imp__sub_827B784C"))) PPC_WEAK_FUNC(sub_827B784C);
PPC_FUNC_IMPL(__imp__sub_827B784C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7850"))) PPC_WEAK_FUNC(sub_827B7850);
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

__attribute__((alias("__imp__sub_827B786C"))) PPC_WEAK_FUNC(sub_827B786C);
PPC_FUNC_IMPL(__imp__sub_827B786C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7870"))) PPC_WEAK_FUNC(sub_827B7870);
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

__attribute__((alias("__imp__sub_827B787C"))) PPC_WEAK_FUNC(sub_827B787C);
PPC_FUNC_IMPL(__imp__sub_827B787C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7880"))) PPC_WEAK_FUNC(sub_827B7880);
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

__attribute__((alias("__imp__sub_827B788C"))) PPC_WEAK_FUNC(sub_827B788C);
PPC_FUNC_IMPL(__imp__sub_827B788C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7890"))) PPC_WEAK_FUNC(sub_827B7890);
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

__attribute__((alias("__imp__sub_827B789C"))) PPC_WEAK_FUNC(sub_827B789C);
PPC_FUNC_IMPL(__imp__sub_827B789C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B78A0"))) PPC_WEAK_FUNC(sub_827B78A0);
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

__attribute__((alias("__imp__sub_827B78AC"))) PPC_WEAK_FUNC(sub_827B78AC);
PPC_FUNC_IMPL(__imp__sub_827B78AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B78B0"))) PPC_WEAK_FUNC(sub_827B78B0);
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

__attribute__((alias("__imp__sub_827B78CC"))) PPC_WEAK_FUNC(sub_827B78CC);
PPC_FUNC_IMPL(__imp__sub_827B78CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B78D0"))) PPC_WEAK_FUNC(sub_827B78D0);
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

__attribute__((alias("__imp__sub_827B78EC"))) PPC_WEAK_FUNC(sub_827B78EC);
PPC_FUNC_IMPL(__imp__sub_827B78EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B78F0"))) PPC_WEAK_FUNC(sub_827B78F0);
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

__attribute__((alias("__imp__sub_827B7910"))) PPC_WEAK_FUNC(sub_827B7910);
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

__attribute__((alias("__imp__sub_827B7938"))) PPC_WEAK_FUNC(sub_827B7938);
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

__attribute__((alias("__imp__sub_827B7944"))) PPC_WEAK_FUNC(sub_827B7944);
PPC_FUNC_IMPL(__imp__sub_827B7944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7948"))) PPC_WEAK_FUNC(sub_827B7948);
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

__attribute__((alias("__imp__sub_827B7954"))) PPC_WEAK_FUNC(sub_827B7954);
PPC_FUNC_IMPL(__imp__sub_827B7954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7958"))) PPC_WEAK_FUNC(sub_827B7958);
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

__attribute__((alias("__imp__sub_827B7964"))) PPC_WEAK_FUNC(sub_827B7964);
PPC_FUNC_IMPL(__imp__sub_827B7964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7968"))) PPC_WEAK_FUNC(sub_827B7968);
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

__attribute__((alias("__imp__sub_827B79DC"))) PPC_WEAK_FUNC(sub_827B79DC);
PPC_FUNC_IMPL(__imp__sub_827B79DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B79E0"))) PPC_WEAK_FUNC(sub_827B79E0);
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

__attribute__((alias("__imp__sub_827B7A54"))) PPC_WEAK_FUNC(sub_827B7A54);
PPC_FUNC_IMPL(__imp__sub_827B7A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7A58"))) PPC_WEAK_FUNC(sub_827B7A58);
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

__attribute__((alias("__imp__sub_827B7ACC"))) PPC_WEAK_FUNC(sub_827B7ACC);
PPC_FUNC_IMPL(__imp__sub_827B7ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7AD0"))) PPC_WEAK_FUNC(sub_827B7AD0);
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

__attribute__((alias("__imp__sub_827B7B44"))) PPC_WEAK_FUNC(sub_827B7B44);
PPC_FUNC_IMPL(__imp__sub_827B7B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7B48"))) PPC_WEAK_FUNC(sub_827B7B48);
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

__attribute__((alias("__imp__sub_827B7B68"))) PPC_WEAK_FUNC(sub_827B7B68);
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

__attribute__((alias("__imp__sub_827B7B88"))) PPC_WEAK_FUNC(sub_827B7B88);
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

__attribute__((alias("__imp__sub_827B7BA8"))) PPC_WEAK_FUNC(sub_827B7BA8);
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

__attribute__((alias("__imp__sub_827B7BB4"))) PPC_WEAK_FUNC(sub_827B7BB4);
PPC_FUNC_IMPL(__imp__sub_827B7BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7BB8"))) PPC_WEAK_FUNC(sub_827B7BB8);
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

__attribute__((alias("__imp__sub_827B7BD4"))) PPC_WEAK_FUNC(sub_827B7BD4);
PPC_FUNC_IMPL(__imp__sub_827B7BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7BD8"))) PPC_WEAK_FUNC(sub_827B7BD8);
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

__attribute__((alias("__imp__sub_827B7BE4"))) PPC_WEAK_FUNC(sub_827B7BE4);
PPC_FUNC_IMPL(__imp__sub_827B7BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7BE8"))) PPC_WEAK_FUNC(sub_827B7BE8);
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

__attribute__((alias("__imp__sub_827B7C1C"))) PPC_WEAK_FUNC(sub_827B7C1C);
PPC_FUNC_IMPL(__imp__sub_827B7C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7C20"))) PPC_WEAK_FUNC(sub_827B7C20);
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

__attribute__((alias("__imp__sub_827B7C3C"))) PPC_WEAK_FUNC(sub_827B7C3C);
PPC_FUNC_IMPL(__imp__sub_827B7C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7C40"))) PPC_WEAK_FUNC(sub_827B7C40);
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

__attribute__((alias("__imp__sub_827B7C5C"))) PPC_WEAK_FUNC(sub_827B7C5C);
PPC_FUNC_IMPL(__imp__sub_827B7C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7C60"))) PPC_WEAK_FUNC(sub_827B7C60);
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

__attribute__((alias("__imp__sub_827B7C7C"))) PPC_WEAK_FUNC(sub_827B7C7C);
PPC_FUNC_IMPL(__imp__sub_827B7C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7C80"))) PPC_WEAK_FUNC(sub_827B7C80);
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

__attribute__((alias("__imp__sub_827B7C9C"))) PPC_WEAK_FUNC(sub_827B7C9C);
PPC_FUNC_IMPL(__imp__sub_827B7C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7CA0"))) PPC_WEAK_FUNC(sub_827B7CA0);
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

__attribute__((alias("__imp__sub_827B7CBC"))) PPC_WEAK_FUNC(sub_827B7CBC);
PPC_FUNC_IMPL(__imp__sub_827B7CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7CC0"))) PPC_WEAK_FUNC(sub_827B7CC0);
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

__attribute__((alias("__imp__sub_827B7CDC"))) PPC_WEAK_FUNC(sub_827B7CDC);
PPC_FUNC_IMPL(__imp__sub_827B7CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7CE0"))) PPC_WEAK_FUNC(sub_827B7CE0);
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

__attribute__((alias("__imp__sub_827B7CFC"))) PPC_WEAK_FUNC(sub_827B7CFC);
PPC_FUNC_IMPL(__imp__sub_827B7CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7D00"))) PPC_WEAK_FUNC(sub_827B7D00);
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

__attribute__((alias("__imp__sub_827B7D1C"))) PPC_WEAK_FUNC(sub_827B7D1C);
PPC_FUNC_IMPL(__imp__sub_827B7D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7D20"))) PPC_WEAK_FUNC(sub_827B7D20);
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

__attribute__((alias("__imp__sub_827B7D3C"))) PPC_WEAK_FUNC(sub_827B7D3C);
PPC_FUNC_IMPL(__imp__sub_827B7D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7D40"))) PPC_WEAK_FUNC(sub_827B7D40);
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

__attribute__((alias("__imp__sub_827B7DB4"))) PPC_WEAK_FUNC(sub_827B7DB4);
PPC_FUNC_IMPL(__imp__sub_827B7DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7DB8"))) PPC_WEAK_FUNC(sub_827B7DB8);
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

__attribute__((alias("__imp__sub_827B7E2C"))) PPC_WEAK_FUNC(sub_827B7E2C);
PPC_FUNC_IMPL(__imp__sub_827B7E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7E30"))) PPC_WEAK_FUNC(sub_827B7E30);
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

__attribute__((alias("__imp__sub_827B7EA4"))) PPC_WEAK_FUNC(sub_827B7EA4);
PPC_FUNC_IMPL(__imp__sub_827B7EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7EA8"))) PPC_WEAK_FUNC(sub_827B7EA8);
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

__attribute__((alias("__imp__sub_827B7EC8"))) PPC_WEAK_FUNC(sub_827B7EC8);
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

__attribute__((alias("__imp__sub_827B7EE8"))) PPC_WEAK_FUNC(sub_827B7EE8);
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

__attribute__((alias("__imp__sub_827B7F20"))) PPC_WEAK_FUNC(sub_827B7F20);
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

__attribute__((alias("__imp__sub_827B7F3C"))) PPC_WEAK_FUNC(sub_827B7F3C);
PPC_FUNC_IMPL(__imp__sub_827B7F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7F40"))) PPC_WEAK_FUNC(sub_827B7F40);
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

__attribute__((alias("__imp__sub_827B7F5C"))) PPC_WEAK_FUNC(sub_827B7F5C);
PPC_FUNC_IMPL(__imp__sub_827B7F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7F60"))) PPC_WEAK_FUNC(sub_827B7F60);
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

__attribute__((alias("__imp__sub_827B7F7C"))) PPC_WEAK_FUNC(sub_827B7F7C);
PPC_FUNC_IMPL(__imp__sub_827B7F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7F80"))) PPC_WEAK_FUNC(sub_827B7F80);
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

__attribute__((alias("__imp__sub_827B7F9C"))) PPC_WEAK_FUNC(sub_827B7F9C);
PPC_FUNC_IMPL(__imp__sub_827B7F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7FA0"))) PPC_WEAK_FUNC(sub_827B7FA0);
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

__attribute__((alias("__imp__sub_827B7FAC"))) PPC_WEAK_FUNC(sub_827B7FAC);
PPC_FUNC_IMPL(__imp__sub_827B7FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B7FB0"))) PPC_WEAK_FUNC(sub_827B7FB0);
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

__attribute__((alias("__imp__sub_827B8024"))) PPC_WEAK_FUNC(sub_827B8024);
PPC_FUNC_IMPL(__imp__sub_827B8024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8028"))) PPC_WEAK_FUNC(sub_827B8028);
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

__attribute__((alias("__imp__sub_827B8048"))) PPC_WEAK_FUNC(sub_827B8048);
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

__attribute__((alias("__imp__sub_827B807C"))) PPC_WEAK_FUNC(sub_827B807C);
PPC_FUNC_IMPL(__imp__sub_827B807C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8080"))) PPC_WEAK_FUNC(sub_827B8080);
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

__attribute__((alias("__imp__sub_827B80B4"))) PPC_WEAK_FUNC(sub_827B80B4);
PPC_FUNC_IMPL(__imp__sub_827B80B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B80B8"))) PPC_WEAK_FUNC(sub_827B80B8);
PPC_FUNC_IMPL(__imp__sub_827B80B8) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,642
	ctx.r4.s64 = 642;
	// addi r3,r11,17196
	ctx.r3.s64 = r11.s64 + 17196;
	// bl 0x8275c7b8
	ctx.lr = 0x827B80D4;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21224(r11)
	PPC_STORE_U32(r11.u32 + -21224, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B80EC"))) PPC_WEAK_FUNC(sub_827B80EC);
PPC_FUNC_IMPL(__imp__sub_827B80EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B80F0"))) PPC_WEAK_FUNC(sub_827B80F0);
PPC_FUNC_IMPL(__imp__sub_827B80F0) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,643
	ctx.r4.s64 = 643;
	// addi r3,r11,17196
	ctx.r3.s64 = r11.s64 + 17196;
	// bl 0x8275c7b8
	ctx.lr = 0x827B810C;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21204(r11)
	PPC_STORE_U32(r11.u32 + -21204, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8124"))) PPC_WEAK_FUNC(sub_827B8124);
PPC_FUNC_IMPL(__imp__sub_827B8124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8128"))) PPC_WEAK_FUNC(sub_827B8128);
PPC_FUNC_IMPL(__imp__sub_827B8128) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,644
	ctx.r4.s64 = 644;
	// addi r3,r11,17196
	ctx.r3.s64 = r11.s64 + 17196;
	// bl 0x8275c7b8
	ctx.lr = 0x827B8144;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21196(r11)
	PPC_STORE_U32(r11.u32 + -21196, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B815C"))) PPC_WEAK_FUNC(sub_827B815C);
PPC_FUNC_IMPL(__imp__sub_827B815C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8160"))) PPC_WEAK_FUNC(sub_827B8160);
PPC_FUNC_IMPL(__imp__sub_827B8160) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,645
	ctx.r4.s64 = 645;
	// addi r3,r11,17196
	ctx.r3.s64 = r11.s64 + 17196;
	// bl 0x8275c7b8
	ctx.lr = 0x827B817C;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21212(r11)
	PPC_STORE_U32(r11.u32 + -21212, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8194"))) PPC_WEAK_FUNC(sub_827B8194);
PPC_FUNC_IMPL(__imp__sub_827B8194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8198"))) PPC_WEAK_FUNC(sub_827B8198);
PPC_FUNC_IMPL(__imp__sub_827B8198) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,646
	ctx.r4.s64 = 646;
	// addi r3,r11,17196
	ctx.r3.s64 = r11.s64 + 17196;
	// bl 0x8275c7b8
	ctx.lr = 0x827B81B4;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21216(r11)
	PPC_STORE_U32(r11.u32 + -21216, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B81CC"))) PPC_WEAK_FUNC(sub_827B81CC);
PPC_FUNC_IMPL(__imp__sub_827B81CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B81D0"))) PPC_WEAK_FUNC(sub_827B81D0);
PPC_FUNC_IMPL(__imp__sub_827B81D0) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,647
	ctx.r4.s64 = 647;
	// addi r3,r11,17196
	ctx.r3.s64 = r11.s64 + 17196;
	// bl 0x8275c7b8
	ctx.lr = 0x827B81EC;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21220(r11)
	PPC_STORE_U32(r11.u32 + -21220, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8204"))) PPC_WEAK_FUNC(sub_827B8204);
PPC_FUNC_IMPL(__imp__sub_827B8204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8208"))) PPC_WEAK_FUNC(sub_827B8208);
PPC_FUNC_IMPL(__imp__sub_827B8208) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,648
	ctx.r4.s64 = 648;
	// addi r3,r11,17196
	ctx.r3.s64 = r11.s64 + 17196;
	// bl 0x8275c7b8
	ctx.lr = 0x827B8224;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21208(r11)
	PPC_STORE_U32(r11.u32 + -21208, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B823C"))) PPC_WEAK_FUNC(sub_827B823C);
PPC_FUNC_IMPL(__imp__sub_827B823C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8240"))) PPC_WEAK_FUNC(sub_827B8240);
PPC_FUNC_IMPL(__imp__sub_827B8240) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,649
	ctx.r4.s64 = 649;
	// addi r3,r11,17196
	ctx.r3.s64 = r11.s64 + 17196;
	// bl 0x8275c7b8
	ctx.lr = 0x827B825C;
	sub_8275C7B8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21232(r11)
	PPC_STORE_U32(r11.u32 + -21232, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8274"))) PPC_WEAK_FUNC(sub_827B8274);
PPC_FUNC_IMPL(__imp__sub_827B8274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8278"))) PPC_WEAK_FUNC(sub_827B8278);
PPC_FUNC_IMPL(__imp__sub_827B8278) {
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
	// lis r11,-32138
	r11.s64 = -2106195968;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-7912
	ctx.r5.s64 = r11.s64 + -7912;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B82A0;
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
	// addi r11,r7,-2776
	r11.s64 = ctx.r7.s64 + -2776;
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

__attribute__((alias("__imp__sub_827B82EC"))) PPC_WEAK_FUNC(sub_827B82EC);
PPC_FUNC_IMPL(__imp__sub_827B82EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B82F0"))) PPC_WEAK_FUNC(sub_827B82F0);
PPC_FUNC_IMPL(__imp__sub_827B82F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,19048
	ctx.r5.s64 = r11.s64 + 19048;
	// addi r3,r10,-21152
	ctx.r3.s64 = ctx.r10.s64 + -21152;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B830C"))) PPC_WEAK_FUNC(sub_827B830C);
PPC_FUNC_IMPL(__imp__sub_827B830C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8310"))) PPC_WEAK_FUNC(sub_827B8310);
PPC_FUNC_IMPL(__imp__sub_827B8310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,19060
	ctx.r5.s64 = r11.s64 + 19060;
	// addi r3,r10,-21172
	ctx.r3.s64 = ctx.r10.s64 + -21172;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B832C"))) PPC_WEAK_FUNC(sub_827B832C);
PPC_FUNC_IMPL(__imp__sub_827B832C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8330"))) PPC_WEAK_FUNC(sub_827B8330);
PPC_FUNC_IMPL(__imp__sub_827B8330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,-21096
	ctx.r3.s64 = r11.s64 + -21096;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821ce460
	sub_821CE460(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8344"))) PPC_WEAK_FUNC(sub_827B8344);
PPC_FUNC_IMPL(__imp__sub_827B8344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8348"))) PPC_WEAK_FUNC(sub_827B8348);
PPC_FUNC_IMPL(__imp__sub_827B8348) {
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
	// addi r3,r11,-21076
	ctx.r3.s64 = r11.s64 + -21076;
	// bl 0x82763bb8
	ctx.lr = 0x827B8360;
	sub_82763BB8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-13160
	ctx.r3.s64 = ctx.r10.s64 + -13160;
	// bl 0x823d9a98
	ctx.lr = 0x827B836C;
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

__attribute__((alias("__imp__sub_827B837C"))) PPC_WEAK_FUNC(sub_827B837C);
PPC_FUNC_IMPL(__imp__sub_827B837C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8380"))) PPC_WEAK_FUNC(sub_827B8380);
PPC_FUNC_IMPL(__imp__sub_827B8380) {
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
	// addi r3,r11,-15952
	ctx.r3.s64 = r11.s64 + -15952;
	// bl 0x82763c68
	ctx.lr = 0x827B8398;
	sub_82763C68(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-13208
	ctx.r3.s64 = ctx.r10.s64 + -13208;
	// bl 0x823d9a98
	ctx.lr = 0x827B83A4;
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

__attribute__((alias("__imp__sub_827B83B4"))) PPC_WEAK_FUNC(sub_827B83B4);
PPC_FUNC_IMPL(__imp__sub_827B83B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B83B8"))) PPC_WEAK_FUNC(sub_827B83B8);
PPC_FUNC_IMPL(__imp__sub_827B83B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,-15552
	ctx.r3.s64 = r11.s64 + -15552;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821ce460
	sub_821CE460(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B83CC"))) PPC_WEAK_FUNC(sub_827B83CC);
PPC_FUNC_IMPL(__imp__sub_827B83CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B83D0"))) PPC_WEAK_FUNC(sub_827B83D0);
PPC_FUNC_IMPL(__imp__sub_827B83D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r9,r11,-160
	ctx.r9.s64 = r11.s64 + -160;
	// addi r3,r10,-13112
	ctx.r3.s64 = ctx.r10.s64 + -13112;
	// lbz r11,28(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 28);
	// clrlwi r11,r11,26
	r11.u64 = r11.u32 & 0x3F;
	// stb r11,28(r9)
	PPC_STORE_U8(ctx.r9.u32 + 28, r11.u8);
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B83F0"))) PPC_WEAK_FUNC(sub_827B83F0);
PPC_FUNC_IMPL(__imp__sub_827B83F0) {
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
	// addi r3,r11,-15532
	ctx.r3.s64 = r11.s64 + -15532;
	// bl 0x82771588
	ctx.lr = 0x827B8408;
	sub_82771588(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-13040
	ctx.r3.s64 = ctx.r10.s64 + -13040;
	// bl 0x823d9a98
	ctx.lr = 0x827B8414;
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

__attribute__((alias("__imp__sub_827B8424"))) PPC_WEAK_FUNC(sub_827B8424);
PPC_FUNC_IMPL(__imp__sub_827B8424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8428"))) PPC_WEAK_FUNC(sub_827B8428);
PPC_FUNC_IMPL(__imp__sub_827B8428) {
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
	// addi r3,r11,-15272
	ctx.r3.s64 = r11.s64 + -15272;
	// bl 0x82771608
	ctx.lr = 0x827B8440;
	sub_82771608(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-13088
	ctx.r3.s64 = ctx.r10.s64 + -13088;
	// bl 0x823d9a98
	ctx.lr = 0x827B844C;
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

__attribute__((alias("__imp__sub_827B845C"))) PPC_WEAK_FUNC(sub_827B845C);
PPC_FUNC_IMPL(__imp__sub_827B845C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8460"))) PPC_WEAK_FUNC(sub_827B8460);
PPC_FUNC_IMPL(__imp__sub_827B8460) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfd f1,27872(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + 27872);
	// bl 0x823dbae8
	ctx.lr = 0x827B8478;
	sub_823DBAE8(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r5,r10,760
	ctx.r5.s64 = ctx.r10.s64 + 760;
	// lfs f11,11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11364);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,31492(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31492);
	ctx.f10.f64 = double(temp.f32);
	// stfs f12,12(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 12, temp.u32);
	// stfs f11,16(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 16, temp.u32);
	// stfs f0,20(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 20, temp.u32);
	// stfs f13,24(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 24, temp.u32);
	// stfs f13,28(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 28, temp.u32);
	// stfs f10,32(r5)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r5.u32 + 32, temp.u32);
	// stfs f0,36(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 36, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B84D0"))) PPC_WEAK_FUNC(sub_827B84D0);
PPC_FUNC_IMPL(__imp__sub_827B84D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,1136
	ctx.r7.s64 = ctx.r8.s64 + 1136;
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

__attribute__((alias("__imp__sub_827B84F0"))) PPC_WEAK_FUNC(sub_827B84F0);
PPC_FUNC_IMPL(__imp__sub_827B84F0) {
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
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,7600
	ctx.r5.s64 = r11.s64 + 7600;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B8518;
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
	// addi r11,r7,1376
	r11.s64 = ctx.r7.s64 + 1376;
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

__attribute__((alias("__imp__sub_827B8564"))) PPC_WEAK_FUNC(sub_827B8564);
PPC_FUNC_IMPL(__imp__sub_827B8564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8568"))) PPC_WEAK_FUNC(sub_827B8568);
PPC_FUNC_IMPL(__imp__sub_827B8568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,1424
	ctx.r7.s64 = ctx.r8.s64 + 1424;
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

__attribute__((alias("__imp__sub_827B8588"))) PPC_WEAK_FUNC(sub_827B8588);
PPC_FUNC_IMPL(__imp__sub_827B8588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r5,r11,-28452
	ctx.r5.s64 = r11.s64 + -28452;
	// addi r3,r10,-3024
	ctx.r3.s64 = ctx.r10.s64 + -3024;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B85A4"))) PPC_WEAK_FUNC(sub_827B85A4);
PPC_FUNC_IMPL(__imp__sub_827B85A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B85A8"))) PPC_WEAK_FUNC(sub_827B85A8);
PPC_FUNC_IMPL(__imp__sub_827B85A8) {
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
	ctx.lr = 0x827B85D0;
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
	// addi r11,r7,1708
	r11.s64 = ctx.r7.s64 + 1708;
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

__attribute__((alias("__imp__sub_827B861C"))) PPC_WEAK_FUNC(sub_827B861C);
PPC_FUNC_IMPL(__imp__sub_827B861C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8620"))) PPC_WEAK_FUNC(sub_827B8620);
PPC_FUNC_IMPL(__imp__sub_827B8620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r8,1756
	ctx.r7.s64 = ctx.r8.s64 + 1756;
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

__attribute__((alias("__imp__sub_827B8640"))) PPC_WEAK_FUNC(sub_827B8640);
PPC_FUNC_IMPL(__imp__sub_827B8640) {
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
	// addi r3,r11,-2928
	ctx.r3.s64 = r11.s64 + -2928;
	// bl 0x82797680
	ctx.lr = 0x827B8658;
	sub_82797680(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-12936
	ctx.r3.s64 = ctx.r10.s64 + -12936;
	// bl 0x823d9a98
	ctx.lr = 0x827B8664;
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

__attribute__((alias("__imp__sub_827B8674"))) PPC_WEAK_FUNC(sub_827B8674);
PPC_FUNC_IMPL(__imp__sub_827B8674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8678"))) PPC_WEAK_FUNC(sub_827B8678);
PPC_FUNC_IMPL(__imp__sub_827B8678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32107
	ctx.r8.s64 = -2104164352;
	// lfs f0,2168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 2168);
	f0.f64 = double(temp.f32);
	// lfs f13,3804(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3804);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f0,30280(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30280);
	f0.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f0,-23212(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + -23212, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B86A4"))) PPC_WEAK_FUNC(sub_827B86A4);
PPC_FUNC_IMPL(__imp__sub_827B86A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B86A8"))) PPC_WEAK_FUNC(sub_827B86A8);
PPC_FUNC_IMPL(__imp__sub_827B86A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,2840
	ctx.r3.s64 = r11.s64 + 2840;
	// b 0x821c08c0
	sub_821C08C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B86B4"))) PPC_WEAK_FUNC(sub_827B86B4);
PPC_FUNC_IMPL(__imp__sub_827B86B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B86B8"))) PPC_WEAK_FUNC(sub_827B86B8);
PPC_FUNC_IMPL(__imp__sub_827B86B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r10,2880
	ctx.r3.s64 = ctx.r10.s64 + 2880;
	// addi r11,r11,3236
	r11.s64 = r11.s64 + 3236;
	// stw r11,2880(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2880, r11.u32);
	// b 0x821bbe30
	sub_821BBE30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B86D0"))) PPC_WEAK_FUNC(sub_827B86D0);
PPC_FUNC_IMPL(__imp__sub_827B86D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,2896
	ctx.r3.s64 = r11.s64 + 2896;
	// b 0x821c1008
	sub_821C1008(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B86DC"))) PPC_WEAK_FUNC(sub_827B86DC);
PPC_FUNC_IMPL(__imp__sub_827B86DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B86E0"))) PPC_WEAK_FUNC(sub_827B86E0);
PPC_FUNC_IMPL(__imp__sub_827B86E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,3088
	ctx.r3.s64 = r11.s64 + 3088;
	// b 0x821c1008
	sub_821C1008(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B86EC"))) PPC_WEAK_FUNC(sub_827B86EC);
PPC_FUNC_IMPL(__imp__sub_827B86EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B86F0"))) PPC_WEAK_FUNC(sub_827B86F0);
PPC_FUNC_IMPL(__imp__sub_827B86F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,3288
	ctx.r3.s64 = r11.s64 + 3288;
	// b 0x821c1ab8
	sub_821C1AB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B86FC"))) PPC_WEAK_FUNC(sub_827B86FC);
PPC_FUNC_IMPL(__imp__sub_827B86FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8700"))) PPC_WEAK_FUNC(sub_827B8700);
PPC_FUNC_IMPL(__imp__sub_827B8700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,3568
	ctx.r4.s64 = ctx.r9.s64 + 3568;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827B8728"))) PPC_WEAK_FUNC(sub_827B8728);
PPC_FUNC_IMPL(__imp__sub_827B8728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8734"))) PPC_WEAK_FUNC(sub_827B8734);
PPC_FUNC_IMPL(__imp__sub_827B8734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8738"))) PPC_WEAK_FUNC(sub_827B8738);
PPC_FUNC_IMPL(__imp__sub_827B8738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r11,r11,5608
	r11.s64 = r11.s64 + 5608;
	// addi r3,r11,44
	ctx.r3.s64 = r11.s64 + 44;
	// b 0x821362c0
	sub_821362C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8748"))) PPC_WEAK_FUNC(sub_827B8748);
PPC_FUNC_IMPL(__imp__sub_827B8748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5924
	ctx.r3.s64 = r11.s64 + 5924;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8754"))) PPC_WEAK_FUNC(sub_827B8754);
PPC_FUNC_IMPL(__imp__sub_827B8754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8758"))) PPC_WEAK_FUNC(sub_827B8758);
PPC_FUNC_IMPL(__imp__sub_827B8758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5892
	ctx.r3.s64 = r11.s64 + 5892;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8764"))) PPC_WEAK_FUNC(sub_827B8764);
PPC_FUNC_IMPL(__imp__sub_827B8764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8768"))) PPC_WEAK_FUNC(sub_827B8768);
PPC_FUNC_IMPL(__imp__sub_827B8768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5976
	ctx.r3.s64 = r11.s64 + 5976;
	// b 0x82608de8
	sub_82608DE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8774"))) PPC_WEAK_FUNC(sub_827B8774);
PPC_FUNC_IMPL(__imp__sub_827B8774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8778"))) PPC_WEAK_FUNC(sub_827B8778);
PPC_FUNC_IMPL(__imp__sub_827B8778) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5880
	ctx.r3.s64 = r11.s64 + 5880;
	// b 0x82138a18
	sub_82138A18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8784"))) PPC_WEAK_FUNC(sub_827B8784);
PPC_FUNC_IMPL(__imp__sub_827B8784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8788"))) PPC_WEAK_FUNC(sub_827B8788);
PPC_FUNC_IMPL(__imp__sub_827B8788) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,6036
	r11.s64 = r11.s64 + 6036;
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

__attribute__((alias("__imp__sub_827B87A4"))) PPC_WEAK_FUNC(sub_827B87A4);
PPC_FUNC_IMPL(__imp__sub_827B87A4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B87A8"))) PPC_WEAK_FUNC(sub_827B87A8);
PPC_FUNC_IMPL(__imp__sub_827B87A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,5988
	r11.s64 = r11.s64 + 5988;
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

__attribute__((alias("__imp__sub_827B87C4"))) PPC_WEAK_FUNC(sub_827B87C4);
PPC_FUNC_IMPL(__imp__sub_827B87C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B87C8"))) PPC_WEAK_FUNC(sub_827B87C8);
PPC_FUNC_IMPL(__imp__sub_827B87C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B87D4"))) PPC_WEAK_FUNC(sub_827B87D4);
PPC_FUNC_IMPL(__imp__sub_827B87D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B87D8"))) PPC_WEAK_FUNC(sub_827B87D8);
PPC_FUNC_IMPL(__imp__sub_827B87D8) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x82130000
	ctx.lr = 0x827B87F8;
	sub_82130000(ctx, base);
	// addi r3,r31,1300
	ctx.r3.s64 = r31.s64 + 1300;
	// bl 0x821362c0
	ctx.lr = 0x827B8800;
	sub_821362C0(ctx, base);
	// addi r3,r31,700
	ctx.r3.s64 = r31.s64 + 700;
	// bl 0x8214df00
	ctx.lr = 0x827B8808;
	sub_8214DF00(ctx, base);
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// bl 0x8215ff40
	ctx.lr = 0x827B8810;
	sub_8215FF40(ctx, base);
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// bl 0x8214ced8
	ctx.lr = 0x827B8818;
	sub_8214CED8(ctx, base);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x821602f0
	ctx.lr = 0x827B8820;
	sub_821602F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821602f0
	ctx.lr = 0x827B8828;
	sub_821602F0(ctx, base);
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

__attribute__((alias("__imp__sub_827B883C"))) PPC_WEAK_FUNC(sub_827B883C);
PPC_FUNC_IMPL(__imp__sub_827B883C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8840"))) PPC_WEAK_FUNC(sub_827B8840);
PPC_FUNC_IMPL(__imp__sub_827B8840) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-27296
	ctx.r3.s64 = r11.s64 + -27296;
	// b 0x8218c6b0
	sub_8218C6B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B884C"))) PPC_WEAK_FUNC(sub_827B884C);
PPC_FUNC_IMPL(__imp__sub_827B884C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8850"))) PPC_WEAK_FUNC(sub_827B8850);
PPC_FUNC_IMPL(__imp__sub_827B8850) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8854"))) PPC_WEAK_FUNC(sub_827B8854);
PPC_FUNC_IMPL(__imp__sub_827B8854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8858"))) PPC_WEAK_FUNC(sub_827B8858);
PPC_FUNC_IMPL(__imp__sub_827B8858) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r31,r11,-25200
	r31.s64 = r11.s64 + -25200;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x8218c638
	ctx.lr = 0x827B8878;
	sub_8218C638(ctx, base);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x8218c6b0
	ctx.lr = 0x827B8880;
	sub_8218C6B0(ctx, base);
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

__attribute__((alias("__imp__sub_827B8894"))) PPC_WEAK_FUNC(sub_827B8894);
PPC_FUNC_IMPL(__imp__sub_827B8894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8898"))) PPC_WEAK_FUNC(sub_827B8898);
PPC_FUNC_IMPL(__imp__sub_827B8898) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B889C"))) PPC_WEAK_FUNC(sub_827B889C);
PPC_FUNC_IMPL(__imp__sub_827B889C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B88A0"))) PPC_WEAK_FUNC(sub_827B88A0);
PPC_FUNC_IMPL(__imp__sub_827B88A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r11,r11,-25080
	r11.s64 = r11.s64 + -25080;
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

__attribute__((alias("__imp__sub_827B88BC"))) PPC_WEAK_FUNC(sub_827B88BC);
PPC_FUNC_IMPL(__imp__sub_827B88BC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B88C0"))) PPC_WEAK_FUNC(sub_827B88C0);
PPC_FUNC_IMPL(__imp__sub_827B88C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r11,r11,-25072
	r11.s64 = r11.s64 + -25072;
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

__attribute__((alias("__imp__sub_827B88DC"))) PPC_WEAK_FUNC(sub_827B88DC);
PPC_FUNC_IMPL(__imp__sub_827B88DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B88E0"))) PPC_WEAK_FUNC(sub_827B88E0);
PPC_FUNC_IMPL(__imp__sub_827B88E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-25044
	ctx.r3.s64 = r11.s64 + -25044;
	// b 0x8229d838
	sub_8229D838(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B88EC"))) PPC_WEAK_FUNC(sub_827B88EC);
PPC_FUNC_IMPL(__imp__sub_827B88EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B88F0"))) PPC_WEAK_FUNC(sub_827B88F0);
PPC_FUNC_IMPL(__imp__sub_827B88F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-24892
	ctx.r3.s64 = r11.s64 + -24892;
	// b 0x82181a88
	sub_82181A88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B88FC"))) PPC_WEAK_FUNC(sub_827B88FC);
PPC_FUNC_IMPL(__imp__sub_827B88FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8900"))) PPC_WEAK_FUNC(sub_827B8900);
PPC_FUNC_IMPL(__imp__sub_827B8900) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8904"))) PPC_WEAK_FUNC(sub_827B8904);
PPC_FUNC_IMPL(__imp__sub_827B8904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8908"))) PPC_WEAK_FUNC(sub_827B8908);
PPC_FUNC_IMPL(__imp__sub_827B8908) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-24772
	ctx.r3.s64 = r11.s64 + -24772;
	// b 0x8229d838
	sub_8229D838(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8914"))) PPC_WEAK_FUNC(sub_827B8914);
PPC_FUNC_IMPL(__imp__sub_827B8914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8918"))) PPC_WEAK_FUNC(sub_827B8918);
PPC_FUNC_IMPL(__imp__sub_827B8918) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B891C"))) PPC_WEAK_FUNC(sub_827B891C);
PPC_FUNC_IMPL(__imp__sub_827B891C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8920"))) PPC_WEAK_FUNC(sub_827B8920);
PPC_FUNC_IMPL(__imp__sub_827B8920) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8924"))) PPC_WEAK_FUNC(sub_827B8924);
PPC_FUNC_IMPL(__imp__sub_827B8924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8928"))) PPC_WEAK_FUNC(sub_827B8928);
PPC_FUNC_IMPL(__imp__sub_827B8928) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-14916
	ctx.r3.s64 = r11.s64 + -14916;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8934"))) PPC_WEAK_FUNC(sub_827B8934);
PPC_FUNC_IMPL(__imp__sub_827B8934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8938"))) PPC_WEAK_FUNC(sub_827B8938);
PPC_FUNC_IMPL(__imp__sub_827B8938) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-17992
	ctx.r3.s64 = r11.s64 + -17992;
	// b 0x8218bc88
	sub_8218BC88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8944"))) PPC_WEAK_FUNC(sub_827B8944);
PPC_FUNC_IMPL(__imp__sub_827B8944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8948"))) PPC_WEAK_FUNC(sub_827B8948);
PPC_FUNC_IMPL(__imp__sub_827B8948) {
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
	// addi r31,r11,-13352
	r31.s64 = r11.s64 + -13352;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827b8990
	if (cr6.eq) goto loc_827B8990;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82194380
	ctx.lr = 0x827B8978;
	sub_82194380(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r31.u32);
	// stw r31,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r31.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_827B8990:
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

__attribute__((alias("__imp__sub_827B89A4"))) PPC_WEAK_FUNC(sub_827B89A4);
PPC_FUNC_IMPL(__imp__sub_827B89A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B89A8"))) PPC_WEAK_FUNC(sub_827B89A8);
PPC_FUNC_IMPL(__imp__sub_827B89A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r3,r11,25480
	ctx.r3.s64 = r11.s64 + 25480;
	// b 0x821966b8
	sub_821966B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B89B4"))) PPC_WEAK_FUNC(sub_827B89B4);
PPC_FUNC_IMPL(__imp__sub_827B89B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

