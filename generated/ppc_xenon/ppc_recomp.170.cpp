#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827B1088"))) PPC_WEAK_FUNC(sub_827B1088);
PPC_FUNC_IMPL(__imp__sub_827B1088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,18196
	ctx.r7.s64 = ctx.r8.s64 + 18196;
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

__attribute__((alias("__imp__sub_827B10A8"))) PPC_WEAK_FUNC(sub_827B10A8);
PPC_FUNC_IMPL(__imp__sub_827B10A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r5,r11,13632
	ctx.r5.s64 = r11.s64 + 13632;
	// addi r4,r10,160
	ctx.r4.s64 = ctx.r10.s64 + 160;
	// addi r3,r9,20596
	ctx.r3.s64 = ctx.r9.s64 + 20596;
	// li r6,4564
	ctx.r6.s64 = 4564;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B10C8"))) PPC_WEAK_FUNC(sub_827B10C8);
PPC_FUNC_IMPL(__imp__sub_827B10C8) {
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
	ctx.lr = 0x827B10F0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,18304
	r11.s64 = ctx.r7.s64 + 18304;
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

__attribute__((alias("__imp__sub_827B113C"))) PPC_WEAK_FUNC(sub_827B113C);
PPC_FUNC_IMPL(__imp__sub_827B113C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B1140"))) PPC_WEAK_FUNC(sub_827B1140);
PPC_FUNC_IMPL(__imp__sub_827B1140) {
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
	// addi r31,r11,20720
	r31.s64 = r11.s64 + 20720;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b5a70
	ctx.lr = 0x827B1160;
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
	// addi r3,r10,-21320
	ctx.r3.s64 = ctx.r10.s64 + -21320;
	// bl 0x823d9a98
	ctx.lr = 0x827B1184;
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

__attribute__((alias("__imp__sub_827B1198"))) PPC_WEAK_FUNC(sub_827B1198);
PPC_FUNC_IMPL(__imp__sub_827B1198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,3708
	ctx.r5.s64 = r11.s64 + 3708;
	// addi r3,r10,20744
	ctx.r3.s64 = ctx.r10.s64 + 20744;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B11B4"))) PPC_WEAK_FUNC(sub_827B11B4);
PPC_FUNC_IMPL(__imp__sub_827B11B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B11B8"))) PPC_WEAK_FUNC(sub_827B11B8);
PPC_FUNC_IMPL(__imp__sub_827B11B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,4220
	ctx.r5.s64 = r11.s64 + 4220;
	// addi r3,r10,20804
	ctx.r3.s64 = ctx.r10.s64 + 20804;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B11D4"))) PPC_WEAK_FUNC(sub_827B11D4);
PPC_FUNC_IMPL(__imp__sub_827B11D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B11D8"))) PPC_WEAK_FUNC(sub_827B11D8);
PPC_FUNC_IMPL(__imp__sub_827B11D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,4232
	ctx.r5.s64 = r11.s64 + 4232;
	// addi r3,r10,20784
	ctx.r3.s64 = ctx.r10.s64 + 20784;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B11F4"))) PPC_WEAK_FUNC(sub_827B11F4);
PPC_FUNC_IMPL(__imp__sub_827B11F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B11F8"))) PPC_WEAK_FUNC(sub_827B11F8);
PPC_FUNC_IMPL(__imp__sub_827B11F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,4244
	ctx.r5.s64 = r11.s64 + 4244;
	// addi r3,r10,20764
	ctx.r3.s64 = ctx.r10.s64 + 20764;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B1214"))) PPC_WEAK_FUNC(sub_827B1214);
PPC_FUNC_IMPL(__imp__sub_827B1214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B1218"))) PPC_WEAK_FUNC(sub_827B1218);
PPC_FUNC_IMPL(__imp__sub_827B1218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19012
	ctx.r7.s64 = ctx.r8.s64 + 19012;
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

__attribute__((alias("__imp__sub_827B1238"))) PPC_WEAK_FUNC(sub_827B1238);
PPC_FUNC_IMPL(__imp__sub_827B1238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19020
	ctx.r7.s64 = ctx.r8.s64 + 19020;
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

__attribute__((alias("__imp__sub_827B1258"))) PPC_WEAK_FUNC(sub_827B1258);
PPC_FUNC_IMPL(__imp__sub_827B1258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19028
	ctx.r7.s64 = ctx.r8.s64 + 19028;
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

__attribute__((alias("__imp__sub_827B1278"))) PPC_WEAK_FUNC(sub_827B1278);
PPC_FUNC_IMPL(__imp__sub_827B1278) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19036
	ctx.r7.s64 = ctx.r8.s64 + 19036;
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

__attribute__((alias("__imp__sub_827B1298"))) PPC_WEAK_FUNC(sub_827B1298);
PPC_FUNC_IMPL(__imp__sub_827B1298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19044
	ctx.r7.s64 = ctx.r8.s64 + 19044;
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

__attribute__((alias("__imp__sub_827B12B8"))) PPC_WEAK_FUNC(sub_827B12B8);
PPC_FUNC_IMPL(__imp__sub_827B12B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19052
	ctx.r7.s64 = ctx.r8.s64 + 19052;
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

__attribute__((alias("__imp__sub_827B12D8"))) PPC_WEAK_FUNC(sub_827B12D8);
PPC_FUNC_IMPL(__imp__sub_827B12D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19060
	ctx.r7.s64 = ctx.r8.s64 + 19060;
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

__attribute__((alias("__imp__sub_827B12F8"))) PPC_WEAK_FUNC(sub_827B12F8);
PPC_FUNC_IMPL(__imp__sub_827B12F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19068
	ctx.r7.s64 = ctx.r8.s64 + 19068;
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

__attribute__((alias("__imp__sub_827B1318"))) PPC_WEAK_FUNC(sub_827B1318);
PPC_FUNC_IMPL(__imp__sub_827B1318) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19076
	ctx.r7.s64 = ctx.r8.s64 + 19076;
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

__attribute__((alias("__imp__sub_827B1338"))) PPC_WEAK_FUNC(sub_827B1338);
PPC_FUNC_IMPL(__imp__sub_827B1338) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19156
	ctx.r7.s64 = ctx.r8.s64 + 19156;
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

__attribute__((alias("__imp__sub_827B1358"))) PPC_WEAK_FUNC(sub_827B1358);
PPC_FUNC_IMPL(__imp__sub_827B1358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,19464
	ctx.r7.s64 = ctx.r8.s64 + 19464;
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

__attribute__((alias("__imp__sub_827B1378"))) PPC_WEAK_FUNC(sub_827B1378);
PPC_FUNC_IMPL(__imp__sub_827B1378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,20568
	ctx.r7.s64 = ctx.r8.s64 + 20568;
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

__attribute__((alias("__imp__sub_827B1398"))) PPC_WEAK_FUNC(sub_827B1398);
PPC_FUNC_IMPL(__imp__sub_827B1398) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
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

__attribute__((alias("__imp__sub_827B13B8"))) PPC_WEAK_FUNC(sub_827B13B8);
PPC_FUNC_IMPL(__imp__sub_827B13B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
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

__attribute__((alias("__imp__sub_827B13D8"))) PPC_WEAK_FUNC(sub_827B13D8);
PPC_FUNC_IMPL(__imp__sub_827B13D8) {
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
	// lis r11,-32180
	r11.s64 = -2108948480;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-28360
	ctx.r5.s64 = r11.s64 + -28360;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B1400;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,21704
	r11.s64 = ctx.r7.s64 + 21704;
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

__attribute__((alias("__imp__sub_827B144C"))) PPC_WEAK_FUNC(sub_827B144C);
PPC_FUNC_IMPL(__imp__sub_827B144C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B1450"))) PPC_WEAK_FUNC(sub_827B1450);
PPC_FUNC_IMPL(__imp__sub_827B1450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,21752
	ctx.r7.s64 = ctx.r8.s64 + 21752;
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

__attribute__((alias("__imp__sub_827B1470"))) PPC_WEAK_FUNC(sub_827B1470);
PPC_FUNC_IMPL(__imp__sub_827B1470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,21760
	ctx.r7.s64 = ctx.r8.s64 + 21760;
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

__attribute__((alias("__imp__sub_827B1490"))) PPC_WEAK_FUNC(sub_827B1490);
PPC_FUNC_IMPL(__imp__sub_827B1490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,22232
	ctx.r7.s64 = ctx.r8.s64 + 22232;
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

__attribute__((alias("__imp__sub_827B14B0"))) PPC_WEAK_FUNC(sub_827B14B0);
PPC_FUNC_IMPL(__imp__sub_827B14B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lfs f0,22228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 22228);
	f0.f64 = double(temp.f32);
	// lfs f13,31016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// stw r11,20944(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20944, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B14DC"))) PPC_WEAK_FUNC(sub_827B14DC);
PPC_FUNC_IMPL(__imp__sub_827B14DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B14E0"))) PPC_WEAK_FUNC(sub_827B14E0);
PPC_FUNC_IMPL(__imp__sub_827B14E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,20928
	ctx.r9.s64 = r11.s64 + 20928;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,20928(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20928, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B14FC"))) PPC_WEAK_FUNC(sub_827B14FC);
PPC_FUNC_IMPL(__imp__sub_827B14FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B1500"))) PPC_WEAK_FUNC(sub_827B1500);
PPC_FUNC_IMPL(__imp__sub_827B1500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,24240
	ctx.r7.s64 = ctx.r8.s64 + 24240;
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

__attribute__((alias("__imp__sub_827B1520"))) PPC_WEAK_FUNC(sub_827B1520);
PPC_FUNC_IMPL(__imp__sub_827B1520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,24248
	ctx.r7.s64 = ctx.r8.s64 + 24248;
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

__attribute__((alias("__imp__sub_827B1540"))) PPC_WEAK_FUNC(sub_827B1540);
PPC_FUNC_IMPL(__imp__sub_827B1540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,24256
	ctx.r7.s64 = ctx.r8.s64 + 24256;
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

__attribute__((alias("__imp__sub_827B1560"))) PPC_WEAK_FUNC(sub_827B1560);
PPC_FUNC_IMPL(__imp__sub_827B1560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,24988
	ctx.r7.s64 = ctx.r8.s64 + 24988;
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

__attribute__((alias("__imp__sub_827B1580"))) PPC_WEAK_FUNC(sub_827B1580);
PPC_FUNC_IMPL(__imp__sub_827B1580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,24996
	ctx.r7.s64 = ctx.r8.s64 + 24996;
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

__attribute__((alias("__imp__sub_827B15A0"))) PPC_WEAK_FUNC(sub_827B15A0);
PPC_FUNC_IMPL(__imp__sub_827B15A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,25004
	ctx.r7.s64 = ctx.r8.s64 + 25004;
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

__attribute__((alias("__imp__sub_827B15C0"))) PPC_WEAK_FUNC(sub_827B15C0);
PPC_FUNC_IMPL(__imp__sub_827B15C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,25012
	ctx.r7.s64 = ctx.r8.s64 + 25012;
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

__attribute__((alias("__imp__sub_827B15E0"))) PPC_WEAK_FUNC(sub_827B15E0);
PPC_FUNC_IMPL(__imp__sub_827B15E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,25020
	ctx.r7.s64 = ctx.r8.s64 + 25020;
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

__attribute__((alias("__imp__sub_827B1600"))) PPC_WEAK_FUNC(sub_827B1600);
PPC_FUNC_IMPL(__imp__sub_827B1600) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,25028
	ctx.r7.s64 = ctx.r8.s64 + 25028;
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

__attribute__((alias("__imp__sub_827B1620"))) PPC_WEAK_FUNC(sub_827B1620);
PPC_FUNC_IMPL(__imp__sub_827B1620) {
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
	// addi r30,r31,22380
	r30.s64 = r31.s64 + 22380;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13068
	ctx.r5.s64 = ctx.r10.s64 + 13068;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1658;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22380(r31)
	PPC_STORE_U32(r31.u32 + 22380, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1668;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1670;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13064
	r11.s64 = r11.s64 + 13064;
	// addi r3,r9,-21248
	ctx.r3.s64 = ctx.r9.s64 + -21248;
	// stw r11,22380(r31)
	PPC_STORE_U32(r31.u32 + 22380, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1688;
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

__attribute__((alias("__imp__sub_827B16A0"))) PPC_WEAK_FUNC(sub_827B16A0);
PPC_FUNC_IMPL(__imp__sub_827B16A0) {
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
	// addi r30,r31,22508
	r30.s64 = r31.s64 + 22508;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13096
	ctx.r5.s64 = ctx.r10.s64 + 13096;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B16D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22508(r31)
	PPC_STORE_U32(r31.u32 + 22508, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B16E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B16F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13092
	r11.s64 = r11.s64 + 13092;
	// addi r3,r9,-21160
	ctx.r3.s64 = ctx.r9.s64 + -21160;
	// stw r11,22508(r31)
	PPC_STORE_U32(r31.u32 + 22508, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1708;
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

__attribute__((alias("__imp__sub_827B1720"))) PPC_WEAK_FUNC(sub_827B1720);
PPC_FUNC_IMPL(__imp__sub_827B1720) {
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
	// addi r30,r31,22092
	r30.s64 = r31.s64 + 22092;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13124
	ctx.r5.s64 = ctx.r10.s64 + 13124;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1758;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22092(r31)
	PPC_STORE_U32(r31.u32 + 22092, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1768;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1770;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13120
	r11.s64 = r11.s64 + 13120;
	// addi r3,r9,-21072
	ctx.r3.s64 = ctx.r9.s64 + -21072;
	// stw r11,22092(r31)
	PPC_STORE_U32(r31.u32 + 22092, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1788;
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

__attribute__((alias("__imp__sub_827B17A0"))) PPC_WEAK_FUNC(sub_827B17A0);
PPC_FUNC_IMPL(__imp__sub_827B17A0) {
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
	// addi r30,r31,22476
	r30.s64 = r31.s64 + 22476;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13144
	ctx.r5.s64 = ctx.r10.s64 + 13144;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B17D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22476(r31)
	PPC_STORE_U32(r31.u32 + 22476, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B17E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B17F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13140
	r11.s64 = r11.s64 + 13140;
	// addi r3,r9,-20984
	ctx.r3.s64 = ctx.r9.s64 + -20984;
	// stw r11,22476(r31)
	PPC_STORE_U32(r31.u32 + 22476, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1808;
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

__attribute__((alias("__imp__sub_827B1820"))) PPC_WEAK_FUNC(sub_827B1820);
PPC_FUNC_IMPL(__imp__sub_827B1820) {
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
	// addi r30,r31,22412
	r30.s64 = r31.s64 + 22412;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13172
	ctx.r5.s64 = ctx.r10.s64 + 13172;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1858;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22412(r31)
	PPC_STORE_U32(r31.u32 + 22412, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1868;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1870;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13168
	r11.s64 = r11.s64 + 13168;
	// addi r3,r9,-20896
	ctx.r3.s64 = ctx.r9.s64 + -20896;
	// stw r11,22412(r31)
	PPC_STORE_U32(r31.u32 + 22412, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1888;
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

__attribute__((alias("__imp__sub_827B18A0"))) PPC_WEAK_FUNC(sub_827B18A0);
PPC_FUNC_IMPL(__imp__sub_827B18A0) {
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
	// addi r30,r31,22156
	r30.s64 = r31.s64 + 22156;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13200
	ctx.r5.s64 = ctx.r10.s64 + 13200;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B18D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22156(r31)
	PPC_STORE_U32(r31.u32 + 22156, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B18E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B18F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13196
	r11.s64 = r11.s64 + 13196;
	// addi r3,r9,-20808
	ctx.r3.s64 = ctx.r9.s64 + -20808;
	// stw r11,22156(r31)
	PPC_STORE_U32(r31.u32 + 22156, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1908;
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

__attribute__((alias("__imp__sub_827B1920"))) PPC_WEAK_FUNC(sub_827B1920);
PPC_FUNC_IMPL(__imp__sub_827B1920) {
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
	// addi r30,r31,22316
	r30.s64 = r31.s64 + 22316;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13236
	ctx.r5.s64 = ctx.r10.s64 + 13236;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1958;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22316(r31)
	PPC_STORE_U32(r31.u32 + 22316, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1968;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1970;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13232
	r11.s64 = r11.s64 + 13232;
	// addi r3,r9,-20720
	ctx.r3.s64 = ctx.r9.s64 + -20720;
	// stw r11,22316(r31)
	PPC_STORE_U32(r31.u32 + 22316, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1988;
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

__attribute__((alias("__imp__sub_827B19A0"))) PPC_WEAK_FUNC(sub_827B19A0);
PPC_FUNC_IMPL(__imp__sub_827B19A0) {
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
	// addi r30,r31,22028
	r30.s64 = r31.s64 + 22028;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13424
	ctx.r5.s64 = ctx.r10.s64 + 13424;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B19D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22028(r31)
	PPC_STORE_U32(r31.u32 + 22028, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B19E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B19F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13420
	r11.s64 = r11.s64 + 13420;
	// addi r3,r9,-20632
	ctx.r3.s64 = ctx.r9.s64 + -20632;
	// stw r11,22028(r31)
	PPC_STORE_U32(r31.u32 + 22028, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1A08;
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

__attribute__((alias("__imp__sub_827B1A20"))) PPC_WEAK_FUNC(sub_827B1A20);
PPC_FUNC_IMPL(__imp__sub_827B1A20) {
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
	// addi r30,r31,22188
	r30.s64 = r31.s64 + 22188;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13276
	ctx.r5.s64 = ctx.r10.s64 + 13276;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1A58;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22188(r31)
	PPC_STORE_U32(r31.u32 + 22188, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1A68;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1A70;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13272
	r11.s64 = r11.s64 + 13272;
	// addi r3,r9,-20544
	ctx.r3.s64 = ctx.r9.s64 + -20544;
	// stw r11,22188(r31)
	PPC_STORE_U32(r31.u32 + 22188, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1A88;
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

__attribute__((alias("__imp__sub_827B1AA0"))) PPC_WEAK_FUNC(sub_827B1AA0);
PPC_FUNC_IMPL(__imp__sub_827B1AA0) {
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
	// addi r30,r31,22540
	r30.s64 = r31.s64 + 22540;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13308
	ctx.r5.s64 = ctx.r10.s64 + 13308;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1AD8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22540(r31)
	PPC_STORE_U32(r31.u32 + 22540, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1AE8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1AF0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13304
	r11.s64 = r11.s64 + 13304;
	// addi r3,r9,-20456
	ctx.r3.s64 = ctx.r9.s64 + -20456;
	// stw r11,22540(r31)
	PPC_STORE_U32(r31.u32 + 22540, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1B08;
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

__attribute__((alias("__imp__sub_827B1B20"))) PPC_WEAK_FUNC(sub_827B1B20);
PPC_FUNC_IMPL(__imp__sub_827B1B20) {
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
	// addi r30,r31,22348
	r30.s64 = r31.s64 + 22348;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13344
	ctx.r5.s64 = ctx.r10.s64 + 13344;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1B58;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22348(r31)
	PPC_STORE_U32(r31.u32 + 22348, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1B68;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1B70;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13340
	r11.s64 = r11.s64 + 13340;
	// addi r3,r9,-20368
	ctx.r3.s64 = ctx.r9.s64 + -20368;
	// stw r11,22348(r31)
	PPC_STORE_U32(r31.u32 + 22348, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1B88;
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

__attribute__((alias("__imp__sub_827B1BA0"))) PPC_WEAK_FUNC(sub_827B1BA0);
PPC_FUNC_IMPL(__imp__sub_827B1BA0) {
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
	// addi r30,r31,22124
	r30.s64 = r31.s64 + 22124;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13384
	ctx.r5.s64 = ctx.r10.s64 + 13384;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1BD8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22124(r31)
	PPC_STORE_U32(r31.u32 + 22124, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1BE8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1BF0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13380
	r11.s64 = r11.s64 + 13380;
	// addi r3,r9,-20280
	ctx.r3.s64 = ctx.r9.s64 + -20280;
	// stw r11,22124(r31)
	PPC_STORE_U32(r31.u32 + 22124, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1C08;
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

__attribute__((alias("__imp__sub_827B1C20"))) PPC_WEAK_FUNC(sub_827B1C20);
PPC_FUNC_IMPL(__imp__sub_827B1C20) {
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
	// addi r30,r31,22252
	r30.s64 = r31.s64 + 22252;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13452
	ctx.r5.s64 = ctx.r10.s64 + 13452;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1C58;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22252(r31)
	PPC_STORE_U32(r31.u32 + 22252, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1C68;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1C70;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13448
	r11.s64 = r11.s64 + 13448;
	// addi r3,r9,-20192
	ctx.r3.s64 = ctx.r9.s64 + -20192;
	// stw r11,22252(r31)
	PPC_STORE_U32(r31.u32 + 22252, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1C88;
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

__attribute__((alias("__imp__sub_827B1CA0"))) PPC_WEAK_FUNC(sub_827B1CA0);
PPC_FUNC_IMPL(__imp__sub_827B1CA0) {
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
	// addi r30,r31,22060
	r30.s64 = r31.s64 + 22060;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13488
	ctx.r5.s64 = ctx.r10.s64 + 13488;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1CD8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22060(r31)
	PPC_STORE_U32(r31.u32 + 22060, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1CE8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1CF0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13484
	r11.s64 = r11.s64 + 13484;
	// addi r3,r9,-20104
	ctx.r3.s64 = ctx.r9.s64 + -20104;
	// stw r11,22060(r31)
	PPC_STORE_U32(r31.u32 + 22060, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1D08;
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

__attribute__((alias("__imp__sub_827B1D20"))) PPC_WEAK_FUNC(sub_827B1D20);
PPC_FUNC_IMPL(__imp__sub_827B1D20) {
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
	// addi r30,r31,22444
	r30.s64 = r31.s64 + 22444;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13524
	ctx.r5.s64 = ctx.r10.s64 + 13524;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1D58;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22444(r31)
	PPC_STORE_U32(r31.u32 + 22444, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1D68;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1D70;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13520
	r11.s64 = r11.s64 + 13520;
	// addi r3,r9,-20016
	ctx.r3.s64 = ctx.r9.s64 + -20016;
	// stw r11,22444(r31)
	PPC_STORE_U32(r31.u32 + 22444, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1D88;
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

__attribute__((alias("__imp__sub_827B1DA0"))) PPC_WEAK_FUNC(sub_827B1DA0);
PPC_FUNC_IMPL(__imp__sub_827B1DA0) {
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
	// addi r30,r31,22284
	r30.s64 = r31.s64 + 22284;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13564
	ctx.r5.s64 = ctx.r10.s64 + 13564;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1DD8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22284(r31)
	PPC_STORE_U32(r31.u32 + 22284, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1DE8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1DF0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13560
	r11.s64 = r11.s64 + 13560;
	// addi r3,r9,-19928
	ctx.r3.s64 = ctx.r9.s64 + -19928;
	// stw r11,22284(r31)
	PPC_STORE_U32(r31.u32 + 22284, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1E08;
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

__attribute__((alias("__imp__sub_827B1E20"))) PPC_WEAK_FUNC(sub_827B1E20);
PPC_FUNC_IMPL(__imp__sub_827B1E20) {
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
	// addi r30,r31,22220
	r30.s64 = r31.s64 + 22220;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,13596
	ctx.r5.s64 = ctx.r10.s64 + 13596;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B1E58;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22220(r31)
	PPC_STORE_U32(r31.u32 + 22220, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B1E68;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B1E70;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,13592
	r11.s64 = r11.s64 + 13592;
	// addi r3,r9,-19840
	ctx.r3.s64 = ctx.r9.s64 + -19840;
	// stw r11,22220(r31)
	PPC_STORE_U32(r31.u32 + 22220, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B1E88;
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

__attribute__((alias("__imp__sub_827B1EA0"))) PPC_WEAK_FUNC(sub_827B1EA0);
PPC_FUNC_IMPL(__imp__sub_827B1EA0) {
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
	// addi r31,r11,22584
	r31.s64 = r11.s64 + 22584;
loc_827B1EC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82501b00
	ctx.lr = 0x827B1EC8;
	sub_82501B00(ctx, base);
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x8252fa48
	ctx.lr = 0x827B1ED0;
	sub_8252FA48(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,112
	r31.s64 = r31.s64 + 112;
	// bge 0x827b1ec0
	if (!cr0.lt) goto loc_827B1EC0;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-19752
	ctx.r3.s64 = r11.s64 + -19752;
	// bl 0x823d9a98
	ctx.lr = 0x827B1EE8;
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

__attribute__((alias("__imp__sub_827B1F00"))) PPC_WEAK_FUNC(sub_827B1F00);
PPC_FUNC_IMPL(__imp__sub_827B1F00) {
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
	// addi r31,r11,29868
	r31.s64 = r11.s64 + 29868;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b5a70
	ctx.lr = 0x827B1F20;
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
	// addi r3,r10,-19528
	ctx.r3.s64 = ctx.r10.s64 + -19528;
	// bl 0x823d9a98
	ctx.lr = 0x827B1F44;
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

__attribute__((alias("__imp__sub_827B1F58"))) PPC_WEAK_FUNC(sub_827B1F58);
PPC_FUNC_IMPL(__imp__sub_827B1F58) {
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
	// addi r31,r11,29848
	r31.s64 = r11.s64 + 29848;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b5a70
	ctx.lr = 0x827B1F78;
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
	// addi r3,r10,-19672
	ctx.r3.s64 = ctx.r10.s64 + -19672;
	// bl 0x823d9a98
	ctx.lr = 0x827B1F9C;
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

__attribute__((alias("__imp__sub_827B1FB0"))) PPC_WEAK_FUNC(sub_827B1FB0);
PPC_FUNC_IMPL(__imp__sub_827B1FB0) {
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
	// addi r31,r11,29888
	r31.s64 = r11.s64 + 29888;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b5a70
	ctx.lr = 0x827B1FD0;
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
	// addi r3,r10,-19600
	ctx.r3.s64 = ctx.r10.s64 + -19600;
	// bl 0x823d9a98
	ctx.lr = 0x827B1FF4;
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

__attribute__((alias("__imp__sub_827B2008"))) PPC_WEAK_FUNC(sub_827B2008);
PPC_FUNC_IMPL(__imp__sub_827B2008) {
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
	// lis r11,-32179
	r11.s64 = -2108882944;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,12224
	ctx.r5.s64 = r11.s64 + 12224;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B2030;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,27432
	r11.s64 = ctx.r7.s64 + 27432;
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

__attribute__((alias("__imp__sub_827B207C"))) PPC_WEAK_FUNC(sub_827B207C);
PPC_FUNC_IMPL(__imp__sub_827B207C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2080"))) PPC_WEAK_FUNC(sub_827B2080);
PPC_FUNC_IMPL(__imp__sub_827B2080) {
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
	ctx.lr = 0x827B20A8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,27480
	r11.s64 = ctx.r7.s64 + 27480;
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

__attribute__((alias("__imp__sub_827B20F4"))) PPC_WEAK_FUNC(sub_827B20F4);
PPC_FUNC_IMPL(__imp__sub_827B20F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B20F8"))) PPC_WEAK_FUNC(sub_827B20F8);
PPC_FUNC_IMPL(__imp__sub_827B20F8) {
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
	ctx.lr = 0x827B2120;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,27528
	r11.s64 = ctx.r7.s64 + 27528;
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

__attribute__((alias("__imp__sub_827B216C"))) PPC_WEAK_FUNC(sub_827B216C);
PPC_FUNC_IMPL(__imp__sub_827B216C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2170"))) PPC_WEAK_FUNC(sub_827B2170);
PPC_FUNC_IMPL(__imp__sub_827B2170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,27576
	ctx.r7.s64 = ctx.r8.s64 + 27576;
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

__attribute__((alias("__imp__sub_827B2190"))) PPC_WEAK_FUNC(sub_827B2190);
PPC_FUNC_IMPL(__imp__sub_827B2190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,27584
	ctx.r7.s64 = ctx.r8.s64 + 27584;
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

__attribute__((alias("__imp__sub_827B21B0"))) PPC_WEAK_FUNC(sub_827B21B0);
PPC_FUNC_IMPL(__imp__sub_827B21B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,27592
	ctx.r7.s64 = ctx.r8.s64 + 27592;
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

__attribute__((alias("__imp__sub_827B21D0"))) PPC_WEAK_FUNC(sub_827B21D0);
PPC_FUNC_IMPL(__imp__sub_827B21D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28756
	ctx.r7.s64 = ctx.r8.s64 + 28756;
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

__attribute__((alias("__imp__sub_827B21F0"))) PPC_WEAK_FUNC(sub_827B21F0);
PPC_FUNC_IMPL(__imp__sub_827B21F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28764
	ctx.r7.s64 = ctx.r8.s64 + 28764;
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

__attribute__((alias("__imp__sub_827B2210"))) PPC_WEAK_FUNC(sub_827B2210);
PPC_FUNC_IMPL(__imp__sub_827B2210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28772
	ctx.r7.s64 = ctx.r8.s64 + 28772;
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

__attribute__((alias("__imp__sub_827B2230"))) PPC_WEAK_FUNC(sub_827B2230);
PPC_FUNC_IMPL(__imp__sub_827B2230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28780
	ctx.r7.s64 = ctx.r8.s64 + 28780;
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

__attribute__((alias("__imp__sub_827B2250"))) PPC_WEAK_FUNC(sub_827B2250);
PPC_FUNC_IMPL(__imp__sub_827B2250) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28788
	ctx.r7.s64 = ctx.r8.s64 + 28788;
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

__attribute__((alias("__imp__sub_827B2270"))) PPC_WEAK_FUNC(sub_827B2270);
PPC_FUNC_IMPL(__imp__sub_827B2270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28796
	ctx.r7.s64 = ctx.r8.s64 + 28796;
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

__attribute__((alias("__imp__sub_827B2290"))) PPC_WEAK_FUNC(sub_827B2290);
PPC_FUNC_IMPL(__imp__sub_827B2290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28804
	ctx.r7.s64 = ctx.r8.s64 + 28804;
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

__attribute__((alias("__imp__sub_827B22B0"))) PPC_WEAK_FUNC(sub_827B22B0);
PPC_FUNC_IMPL(__imp__sub_827B22B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28812
	ctx.r7.s64 = ctx.r8.s64 + 28812;
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

__attribute__((alias("__imp__sub_827B22D0"))) PPC_WEAK_FUNC(sub_827B22D0);
PPC_FUNC_IMPL(__imp__sub_827B22D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28820
	ctx.r7.s64 = ctx.r8.s64 + 28820;
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

__attribute__((alias("__imp__sub_827B22F0"))) PPC_WEAK_FUNC(sub_827B22F0);
PPC_FUNC_IMPL(__imp__sub_827B22F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// addi r7,r8,28828
	ctx.r7.s64 = ctx.r8.s64 + 28828;
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

__attribute__((alias("__imp__sub_827B2310"))) PPC_WEAK_FUNC(sub_827B2310);
PPC_FUNC_IMPL(__imp__sub_827B2310) {
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
	ctx.lr = 0x827B2338;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-9792
	r11.s64 = ctx.r7.s64 + -9792;
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

__attribute__((alias("__imp__sub_827B2384"))) PPC_WEAK_FUNC(sub_827B2384);
PPC_FUNC_IMPL(__imp__sub_827B2384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2388"))) PPC_WEAK_FUNC(sub_827B2388);
PPC_FUNC_IMPL(__imp__sub_827B2388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,1944
	ctx.r5.s64 = r11.s64 + 1944;
	// addi r3,r10,29968
	ctx.r3.s64 = ctx.r10.s64 + 29968;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B23A4"))) PPC_WEAK_FUNC(sub_827B23A4);
PPC_FUNC_IMPL(__imp__sub_827B23A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B23A8"))) PPC_WEAK_FUNC(sub_827B23A8);
PPC_FUNC_IMPL(__imp__sub_827B23A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-19456
	ctx.r3.s64 = r11.s64 + -19456;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B23B4"))) PPC_WEAK_FUNC(sub_827B23B4);
PPC_FUNC_IMPL(__imp__sub_827B23B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B23B8"))) PPC_WEAK_FUNC(sub_827B23B8);
PPC_FUNC_IMPL(__imp__sub_827B23B8) {
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
	ctx.lr = 0x827B23E0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-9480
	r11.s64 = ctx.r7.s64 + -9480;
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

__attribute__((alias("__imp__sub_827B242C"))) PPC_WEAK_FUNC(sub_827B242C);
PPC_FUNC_IMPL(__imp__sub_827B242C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2430"))) PPC_WEAK_FUNC(sub_827B2430);
PPC_FUNC_IMPL(__imp__sub_827B2430) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-9432
	ctx.r7.s64 = ctx.r8.s64 + -9432;
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

__attribute__((alias("__imp__sub_827B2450"))) PPC_WEAK_FUNC(sub_827B2450);
PPC_FUNC_IMPL(__imp__sub_827B2450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-8844
	ctx.r7.s64 = ctx.r8.s64 + -8844;
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

__attribute__((alias("__imp__sub_827B2470"))) PPC_WEAK_FUNC(sub_827B2470);
PPC_FUNC_IMPL(__imp__sub_827B2470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-8836
	ctx.r7.s64 = ctx.r8.s64 + -8836;
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

__attribute__((alias("__imp__sub_827B2490"))) PPC_WEAK_FUNC(sub_827B2490);
PPC_FUNC_IMPL(__imp__sub_827B2490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-8828
	ctx.r7.s64 = ctx.r8.s64 + -8828;
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

__attribute__((alias("__imp__sub_827B24B0"))) PPC_WEAK_FUNC(sub_827B24B0);
PPC_FUNC_IMPL(__imp__sub_827B24B0) {
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
	ctx.lr = 0x827B24D8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-7200
	r11.s64 = ctx.r7.s64 + -7200;
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

__attribute__((alias("__imp__sub_827B2524"))) PPC_WEAK_FUNC(sub_827B2524);
PPC_FUNC_IMPL(__imp__sub_827B2524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2528"))) PPC_WEAK_FUNC(sub_827B2528);
PPC_FUNC_IMPL(__imp__sub_827B2528) {
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
	// lis r11,-32178
	r11.s64 = -2108817408;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-8888
	ctx.r5.s64 = r11.s64 + -8888;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827B2550;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-7152
	r11.s64 = ctx.r7.s64 + -7152;
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

__attribute__((alias("__imp__sub_827B259C"))) PPC_WEAK_FUNC(sub_827B259C);
PPC_FUNC_IMPL(__imp__sub_827B259C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B25A0"))) PPC_WEAK_FUNC(sub_827B25A0);
PPC_FUNC_IMPL(__imp__sub_827B25A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-7104
	ctx.r7.s64 = ctx.r8.s64 + -7104;
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

__attribute__((alias("__imp__sub_827B25C0"))) PPC_WEAK_FUNC(sub_827B25C0);
PPC_FUNC_IMPL(__imp__sub_827B25C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-7096
	ctx.r7.s64 = ctx.r8.s64 + -7096;
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

__attribute__((alias("__imp__sub_827B25E0"))) PPC_WEAK_FUNC(sub_827B25E0);
PPC_FUNC_IMPL(__imp__sub_827B25E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-7088
	ctx.r7.s64 = ctx.r8.s64 + -7088;
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

__attribute__((alias("__imp__sub_827B2600"))) PPC_WEAK_FUNC(sub_827B2600);
PPC_FUNC_IMPL(__imp__sub_827B2600) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-7080
	ctx.r7.s64 = ctx.r8.s64 + -7080;
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

__attribute__((alias("__imp__sub_827B2620"))) PPC_WEAK_FUNC(sub_827B2620);
PPC_FUNC_IMPL(__imp__sub_827B2620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-7072
	ctx.r7.s64 = ctx.r8.s64 + -7072;
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

__attribute__((alias("__imp__sub_827B2640"))) PPC_WEAK_FUNC(sub_827B2640);
PPC_FUNC_IMPL(__imp__sub_827B2640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-6876
	ctx.r7.s64 = ctx.r8.s64 + -6876;
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

__attribute__((alias("__imp__sub_827B2660"))) PPC_WEAK_FUNC(sub_827B2660);
PPC_FUNC_IMPL(__imp__sub_827B2660) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,30036
	ctx.r3.s64 = r11.s64 + 30036;
	// bl 0x821973a8
	ctx.lr = 0x827B2678;
	sub_821973A8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-19440
	ctx.r3.s64 = ctx.r10.s64 + -19440;
	// bl 0x823d9a98
	ctx.lr = 0x827B2684;
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

__attribute__((alias("__imp__sub_827B2694"))) PPC_WEAK_FUNC(sub_827B2694);
PPC_FUNC_IMPL(__imp__sub_827B2694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2698"))) PPC_WEAK_FUNC(sub_827B2698);
PPC_FUNC_IMPL(__imp__sub_827B2698) {
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
	// addi r5,r11,26280
	ctx.r5.s64 = r11.s64 + 26280;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824fa650
	ctx.lr = 0x827B26CC;
	sub_824FA650(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30340(r31)
	PPC_STORE_U32(r31.u32 + 30340, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B26DC;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B26E4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r11,r11,26276
	r11.s64 = r11.s64 + 26276;
	// addi r3,r10,-19408
	ctx.r3.s64 = ctx.r10.s64 + -19408;
	// stw r11,30340(r31)
	PPC_STORE_U32(r31.u32 + 30340, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B26FC;
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

__attribute__((alias("__imp__sub_827B2714"))) PPC_WEAK_FUNC(sub_827B2714);
PPC_FUNC_IMPL(__imp__sub_827B2714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2718"))) PPC_WEAK_FUNC(sub_827B2718);
PPC_FUNC_IMPL(__imp__sub_827B2718) {
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
	// addi r30,r31,30180
	r30.s64 = r31.s64 + 30180;
	// addi r7,r11,30340
	ctx.r7.s64 = r11.s64 + 30340;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,26344
	ctx.r6.s64 = ctx.r10.s64 + 26344;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2754;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30180(r31)
	PPC_STORE_U32(r31.u32 + 30180, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B2764;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B276C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,26340
	r11.s64 = r11.s64 + 26340;
	// addi r3,r9,-19320
	ctx.r3.s64 = ctx.r9.s64 + -19320;
	// stw r11,30180(r31)
	PPC_STORE_U32(r31.u32 + 30180, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2784;
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

__attribute__((alias("__imp__sub_827B279C"))) PPC_WEAK_FUNC(sub_827B279C);
PPC_FUNC_IMPL(__imp__sub_827B279C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B27A0"))) PPC_WEAK_FUNC(sub_827B27A0);
PPC_FUNC_IMPL(__imp__sub_827B27A0) {
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
	// addi r30,r31,30212
	r30.s64 = r31.s64 + 30212;
	// addi r7,r11,30340
	ctx.r7.s64 = r11.s64 + 30340;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,26388
	ctx.r6.s64 = ctx.r10.s64 + 26388;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B27DC;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30212(r31)
	PPC_STORE_U32(r31.u32 + 30212, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B27EC;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B27F4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,26384
	r11.s64 = r11.s64 + 26384;
	// addi r3,r9,-19232
	ctx.r3.s64 = ctx.r9.s64 + -19232;
	// stw r11,30212(r31)
	PPC_STORE_U32(r31.u32 + 30212, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B280C;
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

__attribute__((alias("__imp__sub_827B2824"))) PPC_WEAK_FUNC(sub_827B2824);
PPC_FUNC_IMPL(__imp__sub_827B2824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2828"))) PPC_WEAK_FUNC(sub_827B2828);
PPC_FUNC_IMPL(__imp__sub_827B2828) {
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
	// addi r30,r31,30404
	r30.s64 = r31.s64 + 30404;
	// addi r7,r11,30340
	ctx.r7.s64 = r11.s64 + 30340;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,26304
	ctx.r6.s64 = ctx.r10.s64 + 26304;
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2864;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30404(r31)
	PPC_STORE_U32(r31.u32 + 30404, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B2874;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B287C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,26300
	r11.s64 = r11.s64 + 26300;
	// addi r3,r9,-19144
	ctx.r3.s64 = ctx.r9.s64 + -19144;
	// stw r11,30404(r31)
	PPC_STORE_U32(r31.u32 + 30404, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2894;
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

__attribute__((alias("__imp__sub_827B28AC"))) PPC_WEAK_FUNC(sub_827B28AC);
PPC_FUNC_IMPL(__imp__sub_827B28AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B28B0"))) PPC_WEAK_FUNC(sub_827B28B0);
PPC_FUNC_IMPL(__imp__sub_827B28B0) {
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
	// addi r30,r31,30244
	r30.s64 = r31.s64 + 30244;
	// addi r7,r11,30340
	ctx.r7.s64 = r11.s64 + 30340;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,26428
	ctx.r6.s64 = ctx.r10.s64 + 26428;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B28EC;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30244(r31)
	PPC_STORE_U32(r31.u32 + 30244, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B28FC;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2904;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,26424
	r11.s64 = r11.s64 + 26424;
	// addi r3,r9,-19056
	ctx.r3.s64 = ctx.r9.s64 + -19056;
	// stw r11,30244(r31)
	PPC_STORE_U32(r31.u32 + 30244, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B291C;
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

__attribute__((alias("__imp__sub_827B2934"))) PPC_WEAK_FUNC(sub_827B2934);
PPC_FUNC_IMPL(__imp__sub_827B2934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2938"))) PPC_WEAK_FUNC(sub_827B2938);
PPC_FUNC_IMPL(__imp__sub_827B2938) {
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
	// addi r30,r31,30308
	r30.s64 = r31.s64 + 30308;
	// addi r7,r11,30340
	ctx.r7.s64 = r11.s64 + 30340;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,26472
	ctx.r6.s64 = ctx.r10.s64 + 26472;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2974;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30308(r31)
	PPC_STORE_U32(r31.u32 + 30308, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B2984;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B298C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,26468
	r11.s64 = r11.s64 + 26468;
	// addi r3,r9,-18968
	ctx.r3.s64 = ctx.r9.s64 + -18968;
	// stw r11,30308(r31)
	PPC_STORE_U32(r31.u32 + 30308, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B29A4;
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

__attribute__((alias("__imp__sub_827B29BC"))) PPC_WEAK_FUNC(sub_827B29BC);
PPC_FUNC_IMPL(__imp__sub_827B29BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B29C0"))) PPC_WEAK_FUNC(sub_827B29C0);
PPC_FUNC_IMPL(__imp__sub_827B29C0) {
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
	// addi r30,r31,30148
	r30.s64 = r31.s64 + 30148;
	// addi r7,r11,30340
	ctx.r7.s64 = r11.s64 + 30340;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,26512
	ctx.r6.s64 = ctx.r10.s64 + 26512;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B29FC;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30148(r31)
	PPC_STORE_U32(r31.u32 + 30148, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B2A0C;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2A14;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,26508
	r11.s64 = r11.s64 + 26508;
	// addi r3,r9,-18880
	ctx.r3.s64 = ctx.r9.s64 + -18880;
	// stw r11,30148(r31)
	PPC_STORE_U32(r31.u32 + 30148, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2A2C;
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

__attribute__((alias("__imp__sub_827B2A44"))) PPC_WEAK_FUNC(sub_827B2A44);
PPC_FUNC_IMPL(__imp__sub_827B2A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2A48"))) PPC_WEAK_FUNC(sub_827B2A48);
PPC_FUNC_IMPL(__imp__sub_827B2A48) {
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
	// addi r30,r31,30276
	r30.s64 = r31.s64 + 30276;
	// addi r7,r11,30340
	ctx.r7.s64 = r11.s64 + 30340;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,26556
	ctx.r6.s64 = ctx.r10.s64 + 26556;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2A84;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30276(r31)
	PPC_STORE_U32(r31.u32 + 30276, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B2A94;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2A9C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,26552
	r11.s64 = r11.s64 + 26552;
	// addi r3,r9,-18792
	ctx.r3.s64 = ctx.r9.s64 + -18792;
	// stw r11,30276(r31)
	PPC_STORE_U32(r31.u32 + 30276, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2AB4;
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

__attribute__((alias("__imp__sub_827B2ACC"))) PPC_WEAK_FUNC(sub_827B2ACC);
PPC_FUNC_IMPL(__imp__sub_827B2ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2AD0"))) PPC_WEAK_FUNC(sub_827B2AD0);
PPC_FUNC_IMPL(__imp__sub_827B2AD0) {
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
	// addi r30,r31,30372
	r30.s64 = r31.s64 + 30372;
	// addi r7,r11,30340
	ctx.r7.s64 = r11.s64 + 30340;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,26596
	ctx.r6.s64 = ctx.r10.s64 + 26596;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2B0C;
	sub_824FA688(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r11,r11,26268
	r11.s64 = r11.s64 + 26268;
	// stw r11,30372(r31)
	PPC_STORE_U32(r31.u32 + 30372, r11.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x827B2B1C;
	sub_824E7BC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2B24;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,26592
	r11.s64 = r11.s64 + 26592;
	// addi r3,r9,-18704
	ctx.r3.s64 = ctx.r9.s64 + -18704;
	// stw r11,30372(r31)
	PPC_STORE_U32(r31.u32 + 30372, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2B3C;
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

__attribute__((alias("__imp__sub_827B2B54"))) PPC_WEAK_FUNC(sub_827B2B54);
PPC_FUNC_IMPL(__imp__sub_827B2B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2B58"))) PPC_WEAK_FUNC(sub_827B2B58);
PPC_FUNC_IMPL(__imp__sub_827B2B58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,30468
	ctx.r3.s64 = r11.s64 + 30468;
	// b 0x824e6310
	sub_824E6310(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B2B64"))) PPC_WEAK_FUNC(sub_827B2B64);
PPC_FUNC_IMPL(__imp__sub_827B2B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2B68"))) PPC_WEAK_FUNC(sub_827B2B68);
PPC_FUNC_IMPL(__imp__sub_827B2B68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,27068
	ctx.r5.s64 = r11.s64 + 27068;
	// addi r3,r10,30448
	ctx.r3.s64 = ctx.r10.s64 + 30448;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B2B84"))) PPC_WEAK_FUNC(sub_827B2B84);
PPC_FUNC_IMPL(__imp__sub_827B2B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2B88"))) PPC_WEAK_FUNC(sub_827B2B88);
PPC_FUNC_IMPL(__imp__sub_827B2B88) {
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
	// addi r30,r31,30480
	r30.s64 = r31.s64 + 30480;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,27432
	ctx.r5.s64 = ctx.r10.s64 + 27432;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B2BC0;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30480(r31)
	PPC_STORE_U32(r31.u32 + 30480, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B2BD0;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2BD8;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27428
	r11.s64 = r11.s64 + 27428;
	// addi r3,r9,-18616
	ctx.r3.s64 = ctx.r9.s64 + -18616;
	// stw r11,30480(r31)
	PPC_STORE_U32(r31.u32 + 30480, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2BF0;
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

__attribute__((alias("__imp__sub_827B2C08"))) PPC_WEAK_FUNC(sub_827B2C08);
PPC_FUNC_IMPL(__imp__sub_827B2C08) {
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
	// addi r30,r31,32120
	r30.s64 = r31.s64 + 32120;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27604
	ctx.r6.s64 = ctx.r10.s64 + 27604;
	// li r5,100
	ctx.r5.s64 = 100;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2C44;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32120(r31)
	PPC_STORE_U32(r31.u32 + 32120, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B2C54;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2C5C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27600
	r11.s64 = r11.s64 + 27600;
	// addi r3,r9,-18448
	ctx.r3.s64 = ctx.r9.s64 + -18448;
	// stw r11,32120(r31)
	PPC_STORE_U32(r31.u32 + 32120, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2C74;
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

__attribute__((alias("__imp__sub_827B2C8C"))) PPC_WEAK_FUNC(sub_827B2C8C);
PPC_FUNC_IMPL(__imp__sub_827B2C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2C90"))) PPC_WEAK_FUNC(sub_827B2C90);
PPC_FUNC_IMPL(__imp__sub_827B2C90) {
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
	// addi r30,r31,31896
	r30.s64 = r31.s64 + 31896;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27632
	ctx.r6.s64 = ctx.r10.s64 + 27632;
	// li r5,101
	ctx.r5.s64 = 101;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2CCC;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31896(r31)
	PPC_STORE_U32(r31.u32 + 31896, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B2CDC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2CE4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27628
	r11.s64 = r11.s64 + 27628;
	// addi r3,r9,-18360
	ctx.r3.s64 = ctx.r9.s64 + -18360;
	// stw r11,31896(r31)
	PPC_STORE_U32(r31.u32 + 31896, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2CFC;
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

__attribute__((alias("__imp__sub_827B2D14"))) PPC_WEAK_FUNC(sub_827B2D14);
PPC_FUNC_IMPL(__imp__sub_827B2D14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2D18"))) PPC_WEAK_FUNC(sub_827B2D18);
PPC_FUNC_IMPL(__imp__sub_827B2D18) {
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
	// addi r30,r31,31960
	r30.s64 = r31.s64 + 31960;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27672
	ctx.r6.s64 = ctx.r10.s64 + 27672;
	// li r5,102
	ctx.r5.s64 = 102;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2D54;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31960(r31)
	PPC_STORE_U32(r31.u32 + 31960, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B2D64;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2D6C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27668
	r11.s64 = r11.s64 + 27668;
	// addi r3,r9,-18272
	ctx.r3.s64 = ctx.r9.s64 + -18272;
	// stw r11,31960(r31)
	PPC_STORE_U32(r31.u32 + 31960, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2D84;
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

__attribute__((alias("__imp__sub_827B2D9C"))) PPC_WEAK_FUNC(sub_827B2D9C);
PPC_FUNC_IMPL(__imp__sub_827B2D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2DA0"))) PPC_WEAK_FUNC(sub_827B2DA0);
PPC_FUNC_IMPL(__imp__sub_827B2DA0) {
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
	// addi r30,r31,31704
	r30.s64 = r31.s64 + 31704;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27712
	ctx.r6.s64 = ctx.r10.s64 + 27712;
	// li r5,103
	ctx.r5.s64 = 103;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2DDC;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31704(r31)
	PPC_STORE_U32(r31.u32 + 31704, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B2DEC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2DF4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27708
	r11.s64 = r11.s64 + 27708;
	// addi r3,r9,-18184
	ctx.r3.s64 = ctx.r9.s64 + -18184;
	// stw r11,31704(r31)
	PPC_STORE_U32(r31.u32 + 31704, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2E0C;
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

__attribute__((alias("__imp__sub_827B2E24"))) PPC_WEAK_FUNC(sub_827B2E24);
PPC_FUNC_IMPL(__imp__sub_827B2E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2E28"))) PPC_WEAK_FUNC(sub_827B2E28);
PPC_FUNC_IMPL(__imp__sub_827B2E28) {
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
	// addi r30,r31,31576
	r30.s64 = r31.s64 + 31576;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27752
	ctx.r6.s64 = ctx.r10.s64 + 27752;
	// li r5,104
	ctx.r5.s64 = 104;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2E64;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31576(r31)
	PPC_STORE_U32(r31.u32 + 31576, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B2E74;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2E7C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27748
	r11.s64 = r11.s64 + 27748;
	// addi r3,r9,-18096
	ctx.r3.s64 = ctx.r9.s64 + -18096;
	// stw r11,31576(r31)
	PPC_STORE_U32(r31.u32 + 31576, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2E94;
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

__attribute__((alias("__imp__sub_827B2EAC"))) PPC_WEAK_FUNC(sub_827B2EAC);
PPC_FUNC_IMPL(__imp__sub_827B2EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2EB0"))) PPC_WEAK_FUNC(sub_827B2EB0);
PPC_FUNC_IMPL(__imp__sub_827B2EB0) {
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
	// addi r30,r31,31800
	r30.s64 = r31.s64 + 31800;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27788
	ctx.r6.s64 = ctx.r10.s64 + 27788;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2EEC;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31800(r31)
	PPC_STORE_U32(r31.u32 + 31800, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B2EFC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2F04;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27784
	r11.s64 = r11.s64 + 27784;
	// addi r3,r9,-18008
	ctx.r3.s64 = ctx.r9.s64 + -18008;
	// stw r11,31800(r31)
	PPC_STORE_U32(r31.u32 + 31800, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2F1C;
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

__attribute__((alias("__imp__sub_827B2F34"))) PPC_WEAK_FUNC(sub_827B2F34);
PPC_FUNC_IMPL(__imp__sub_827B2F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2F38"))) PPC_WEAK_FUNC(sub_827B2F38);
PPC_FUNC_IMPL(__imp__sub_827B2F38) {
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
	// addi r30,r31,30580
	r30.s64 = r31.s64 + 30580;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27836
	ctx.r6.s64 = ctx.r10.s64 + 27836;
	// li r5,106
	ctx.r5.s64 = 106;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2F74;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30580(r31)
	PPC_STORE_U32(r31.u32 + 30580, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B2F84;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B2F8C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27832
	r11.s64 = r11.s64 + 27832;
	// addi r3,r9,-17920
	ctx.r3.s64 = ctx.r9.s64 + -17920;
	// stw r11,30580(r31)
	PPC_STORE_U32(r31.u32 + 30580, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B2FA4;
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

__attribute__((alias("__imp__sub_827B2FBC"))) PPC_WEAK_FUNC(sub_827B2FBC);
PPC_FUNC_IMPL(__imp__sub_827B2FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B2FC0"))) PPC_WEAK_FUNC(sub_827B2FC0);
PPC_FUNC_IMPL(__imp__sub_827B2FC0) {
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
	// addi r30,r31,32024
	r30.s64 = r31.s64 + 32024;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27880
	ctx.r6.s64 = ctx.r10.s64 + 27880;
	// li r5,107
	ctx.r5.s64 = 107;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B2FFC;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32024(r31)
	PPC_STORE_U32(r31.u32 + 32024, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B300C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3014;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27876
	r11.s64 = r11.s64 + 27876;
	// addi r3,r9,-17832
	ctx.r3.s64 = ctx.r9.s64 + -17832;
	// stw r11,32024(r31)
	PPC_STORE_U32(r31.u32 + 32024, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B302C;
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

__attribute__((alias("__imp__sub_827B3044"))) PPC_WEAK_FUNC(sub_827B3044);
PPC_FUNC_IMPL(__imp__sub_827B3044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3048"))) PPC_WEAK_FUNC(sub_827B3048);
PPC_FUNC_IMPL(__imp__sub_827B3048) {
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
	// addi r30,r31,31608
	r30.s64 = r31.s64 + 31608;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27924
	ctx.r6.s64 = ctx.r10.s64 + 27924;
	// li r5,108
	ctx.r5.s64 = 108;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B3084;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31608(r31)
	PPC_STORE_U32(r31.u32 + 31608, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3094;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B309C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27920
	r11.s64 = r11.s64 + 27920;
	// addi r3,r9,-17744
	ctx.r3.s64 = ctx.r9.s64 + -17744;
	// stw r11,31608(r31)
	PPC_STORE_U32(r31.u32 + 31608, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B30B4;
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

__attribute__((alias("__imp__sub_827B30CC"))) PPC_WEAK_FUNC(sub_827B30CC);
PPC_FUNC_IMPL(__imp__sub_827B30CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B30D0"))) PPC_WEAK_FUNC(sub_827B30D0);
PPC_FUNC_IMPL(__imp__sub_827B30D0) {
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
	// addi r30,r31,32184
	r30.s64 = r31.s64 + 32184;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,27968
	ctx.r6.s64 = ctx.r10.s64 + 27968;
	// li r5,109
	ctx.r5.s64 = 109;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B310C;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32184(r31)
	PPC_STORE_U32(r31.u32 + 32184, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B311C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3124;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,27964
	r11.s64 = r11.s64 + 27964;
	// addi r3,r9,-17656
	ctx.r3.s64 = ctx.r9.s64 + -17656;
	// stw r11,32184(r31)
	PPC_STORE_U32(r31.u32 + 32184, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B313C;
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

__attribute__((alias("__imp__sub_827B3154"))) PPC_WEAK_FUNC(sub_827B3154);
PPC_FUNC_IMPL(__imp__sub_827B3154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3158"))) PPC_WEAK_FUNC(sub_827B3158);
PPC_FUNC_IMPL(__imp__sub_827B3158) {
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
	// addi r30,r31,31544
	r30.s64 = r31.s64 + 31544;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28012
	ctx.r6.s64 = ctx.r10.s64 + 28012;
	// li r5,110
	ctx.r5.s64 = 110;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B3194;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31544(r31)
	PPC_STORE_U32(r31.u32 + 31544, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B31A4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B31AC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28008
	r11.s64 = r11.s64 + 28008;
	// addi r3,r9,-17568
	ctx.r3.s64 = ctx.r9.s64 + -17568;
	// stw r11,31544(r31)
	PPC_STORE_U32(r31.u32 + 31544, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B31C4;
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

__attribute__((alias("__imp__sub_827B31DC"))) PPC_WEAK_FUNC(sub_827B31DC);
PPC_FUNC_IMPL(__imp__sub_827B31DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B31E0"))) PPC_WEAK_FUNC(sub_827B31E0);
PPC_FUNC_IMPL(__imp__sub_827B31E0) {
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
	// addi r30,r31,31992
	r30.s64 = r31.s64 + 31992;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28056
	ctx.r6.s64 = ctx.r10.s64 + 28056;
	// li r5,111
	ctx.r5.s64 = 111;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B321C;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31992(r31)
	PPC_STORE_U32(r31.u32 + 31992, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B322C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3234;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28052
	r11.s64 = r11.s64 + 28052;
	// addi r3,r9,-17480
	ctx.r3.s64 = ctx.r9.s64 + -17480;
	// stw r11,31992(r31)
	PPC_STORE_U32(r31.u32 + 31992, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B324C;
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

__attribute__((alias("__imp__sub_827B3264"))) PPC_WEAK_FUNC(sub_827B3264);
PPC_FUNC_IMPL(__imp__sub_827B3264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3268"))) PPC_WEAK_FUNC(sub_827B3268);
PPC_FUNC_IMPL(__imp__sub_827B3268) {
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
	// addi r30,r31,30612
	r30.s64 = r31.s64 + 30612;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28096
	ctx.r6.s64 = ctx.r10.s64 + 28096;
	// li r5,112
	ctx.r5.s64 = 112;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B32A4;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30612(r31)
	PPC_STORE_U32(r31.u32 + 30612, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B32B4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B32BC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28092
	r11.s64 = r11.s64 + 28092;
	// addi r3,r9,-17392
	ctx.r3.s64 = ctx.r9.s64 + -17392;
	// stw r11,30612(r31)
	PPC_STORE_U32(r31.u32 + 30612, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B32D4;
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

__attribute__((alias("__imp__sub_827B32EC"))) PPC_WEAK_FUNC(sub_827B32EC);
PPC_FUNC_IMPL(__imp__sub_827B32EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B32F0"))) PPC_WEAK_FUNC(sub_827B32F0);
PPC_FUNC_IMPL(__imp__sub_827B32F0) {
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
	// addi r30,r31,32152
	r30.s64 = r31.s64 + 32152;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28132
	ctx.r6.s64 = ctx.r10.s64 + 28132;
	// li r5,113
	ctx.r5.s64 = 113;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B332C;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32152(r31)
	PPC_STORE_U32(r31.u32 + 32152, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B333C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3344;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28128
	r11.s64 = r11.s64 + 28128;
	// addi r3,r9,-17304
	ctx.r3.s64 = ctx.r9.s64 + -17304;
	// stw r11,32152(r31)
	PPC_STORE_U32(r31.u32 + 32152, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B335C;
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

__attribute__((alias("__imp__sub_827B3374"))) PPC_WEAK_FUNC(sub_827B3374);
PPC_FUNC_IMPL(__imp__sub_827B3374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3378"))) PPC_WEAK_FUNC(sub_827B3378);
PPC_FUNC_IMPL(__imp__sub_827B3378) {
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
	// addi r30,r31,32056
	r30.s64 = r31.s64 + 32056;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28172
	ctx.r6.s64 = ctx.r10.s64 + 28172;
	// li r5,114
	ctx.r5.s64 = 114;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B33B4;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32056(r31)
	PPC_STORE_U32(r31.u32 + 32056, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B33C4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B33CC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28168
	r11.s64 = r11.s64 + 28168;
	// addi r3,r9,-17216
	ctx.r3.s64 = ctx.r9.s64 + -17216;
	// stw r11,32056(r31)
	PPC_STORE_U32(r31.u32 + 32056, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B33E4;
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

__attribute__((alias("__imp__sub_827B33FC"))) PPC_WEAK_FUNC(sub_827B33FC);
PPC_FUNC_IMPL(__imp__sub_827B33FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3400"))) PPC_WEAK_FUNC(sub_827B3400);
PPC_FUNC_IMPL(__imp__sub_827B3400) {
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
	// addi r30,r31,30516
	r30.s64 = r31.s64 + 30516;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28208
	ctx.r6.s64 = ctx.r10.s64 + 28208;
	// li r5,115
	ctx.r5.s64 = 115;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B343C;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30516(r31)
	PPC_STORE_U32(r31.u32 + 30516, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B344C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3454;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28204
	r11.s64 = r11.s64 + 28204;
	// addi r3,r9,-17128
	ctx.r3.s64 = ctx.r9.s64 + -17128;
	// stw r11,30516(r31)
	PPC_STORE_U32(r31.u32 + 30516, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B346C;
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

__attribute__((alias("__imp__sub_827B3484"))) PPC_WEAK_FUNC(sub_827B3484);
PPC_FUNC_IMPL(__imp__sub_827B3484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3488"))) PPC_WEAK_FUNC(sub_827B3488);
PPC_FUNC_IMPL(__imp__sub_827B3488) {
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
	// addi r30,r31,30548
	r30.s64 = r31.s64 + 30548;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28248
	ctx.r6.s64 = ctx.r10.s64 + 28248;
	// li r5,116
	ctx.r5.s64 = 116;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B34C4;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,30548(r31)
	PPC_STORE_U32(r31.u32 + 30548, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B34D4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B34DC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28244
	r11.s64 = r11.s64 + 28244;
	// addi r3,r9,-17040
	ctx.r3.s64 = ctx.r9.s64 + -17040;
	// stw r11,30548(r31)
	PPC_STORE_U32(r31.u32 + 30548, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B34F4;
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

__attribute__((alias("__imp__sub_827B350C"))) PPC_WEAK_FUNC(sub_827B350C);
PPC_FUNC_IMPL(__imp__sub_827B350C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3510"))) PPC_WEAK_FUNC(sub_827B3510);
PPC_FUNC_IMPL(__imp__sub_827B3510) {
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
	// addi r30,r31,31736
	r30.s64 = r31.s64 + 31736;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28288
	ctx.r6.s64 = ctx.r10.s64 + 28288;
	// li r5,117
	ctx.r5.s64 = 117;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B354C;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31736(r31)
	PPC_STORE_U32(r31.u32 + 31736, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B355C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3564;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28284
	r11.s64 = r11.s64 + 28284;
	// addi r3,r9,-16952
	ctx.r3.s64 = ctx.r9.s64 + -16952;
	// stw r11,31736(r31)
	PPC_STORE_U32(r31.u32 + 31736, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B357C;
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

__attribute__((alias("__imp__sub_827B3594"))) PPC_WEAK_FUNC(sub_827B3594);
PPC_FUNC_IMPL(__imp__sub_827B3594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3598"))) PPC_WEAK_FUNC(sub_827B3598);
PPC_FUNC_IMPL(__imp__sub_827B3598) {
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
	// addi r30,r31,31640
	r30.s64 = r31.s64 + 31640;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28328
	ctx.r6.s64 = ctx.r10.s64 + 28328;
	// li r5,118
	ctx.r5.s64 = 118;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B35D4;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31640(r31)
	PPC_STORE_U32(r31.u32 + 31640, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B35E4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B35EC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28324
	r11.s64 = r11.s64 + 28324;
	// addi r3,r9,-16864
	ctx.r3.s64 = ctx.r9.s64 + -16864;
	// stw r11,31640(r31)
	PPC_STORE_U32(r31.u32 + 31640, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3604;
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

__attribute__((alias("__imp__sub_827B361C"))) PPC_WEAK_FUNC(sub_827B361C);
PPC_FUNC_IMPL(__imp__sub_827B361C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3620"))) PPC_WEAK_FUNC(sub_827B3620);
PPC_FUNC_IMPL(__imp__sub_827B3620) {
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
	// addi r30,r31,31672
	r30.s64 = r31.s64 + 31672;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28364
	ctx.r6.s64 = ctx.r10.s64 + 28364;
	// li r5,119
	ctx.r5.s64 = 119;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B365C;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31672(r31)
	PPC_STORE_U32(r31.u32 + 31672, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B366C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3674;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28360
	r11.s64 = r11.s64 + 28360;
	// addi r3,r9,-16776
	ctx.r3.s64 = ctx.r9.s64 + -16776;
	// stw r11,31672(r31)
	PPC_STORE_U32(r31.u32 + 31672, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B368C;
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

__attribute__((alias("__imp__sub_827B36A4"))) PPC_WEAK_FUNC(sub_827B36A4);
PPC_FUNC_IMPL(__imp__sub_827B36A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B36A8"))) PPC_WEAK_FUNC(sub_827B36A8);
PPC_FUNC_IMPL(__imp__sub_827B36A8) {
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
	// addi r30,r31,32088
	r30.s64 = r31.s64 + 32088;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28404
	ctx.r6.s64 = ctx.r10.s64 + 28404;
	// li r5,120
	ctx.r5.s64 = 120;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B36E4;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32088(r31)
	PPC_STORE_U32(r31.u32 + 32088, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B36F4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B36FC;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28400
	r11.s64 = r11.s64 + 28400;
	// addi r3,r9,-16688
	ctx.r3.s64 = ctx.r9.s64 + -16688;
	// stw r11,32088(r31)
	PPC_STORE_U32(r31.u32 + 32088, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3714;
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

__attribute__((alias("__imp__sub_827B372C"))) PPC_WEAK_FUNC(sub_827B372C);
PPC_FUNC_IMPL(__imp__sub_827B372C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3730"))) PPC_WEAK_FUNC(sub_827B3730);
PPC_FUNC_IMPL(__imp__sub_827B3730) {
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
	// addi r30,r31,31832
	r30.s64 = r31.s64 + 31832;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28444
	ctx.r6.s64 = ctx.r10.s64 + 28444;
	// li r5,121
	ctx.r5.s64 = 121;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B376C;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31832(r31)
	PPC_STORE_U32(r31.u32 + 31832, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B377C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3784;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28440
	r11.s64 = r11.s64 + 28440;
	// addi r3,r9,-16600
	ctx.r3.s64 = ctx.r9.s64 + -16600;
	// stw r11,31832(r31)
	PPC_STORE_U32(r31.u32 + 31832, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B379C;
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

__attribute__((alias("__imp__sub_827B37B4"))) PPC_WEAK_FUNC(sub_827B37B4);
PPC_FUNC_IMPL(__imp__sub_827B37B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B37B8"))) PPC_WEAK_FUNC(sub_827B37B8);
PPC_FUNC_IMPL(__imp__sub_827B37B8) {
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
	// addi r30,r31,31864
	r30.s64 = r31.s64 + 31864;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28484
	ctx.r6.s64 = ctx.r10.s64 + 28484;
	// li r5,122
	ctx.r5.s64 = 122;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B37F4;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31864(r31)
	PPC_STORE_U32(r31.u32 + 31864, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3804;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B380C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28480
	r11.s64 = r11.s64 + 28480;
	// addi r3,r9,-16512
	ctx.r3.s64 = ctx.r9.s64 + -16512;
	// stw r11,31864(r31)
	PPC_STORE_U32(r31.u32 + 31864, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3824;
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

__attribute__((alias("__imp__sub_827B383C"))) PPC_WEAK_FUNC(sub_827B383C);
PPC_FUNC_IMPL(__imp__sub_827B383C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3840"))) PPC_WEAK_FUNC(sub_827B3840);
PPC_FUNC_IMPL(__imp__sub_827B3840) {
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
	// addi r30,r31,31768
	r30.s64 = r31.s64 + 31768;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28524
	ctx.r6.s64 = ctx.r10.s64 + 28524;
	// li r5,123
	ctx.r5.s64 = 123;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B387C;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31768(r31)
	PPC_STORE_U32(r31.u32 + 31768, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B388C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3894;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28520
	r11.s64 = r11.s64 + 28520;
	// addi r3,r9,-16424
	ctx.r3.s64 = ctx.r9.s64 + -16424;
	// stw r11,31768(r31)
	PPC_STORE_U32(r31.u32 + 31768, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B38AC;
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

__attribute__((alias("__imp__sub_827B38C4"))) PPC_WEAK_FUNC(sub_827B38C4);
PPC_FUNC_IMPL(__imp__sub_827B38C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B38C8"))) PPC_WEAK_FUNC(sub_827B38C8);
PPC_FUNC_IMPL(__imp__sub_827B38C8) {
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
	// addi r30,r31,31928
	r30.s64 = r31.s64 + 31928;
	// addi r7,r11,32428
	ctx.r7.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,28568
	ctx.r6.s64 = ctx.r10.s64 + 28568;
	// li r5,124
	ctx.r5.s64 = 124;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B3904;
	sub_824FA688(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,31928(r31)
	PPC_STORE_U32(r31.u32 + 31928, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3914;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B391C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,28564
	r11.s64 = r11.s64 + 28564;
	// addi r3,r9,-16336
	ctx.r3.s64 = ctx.r9.s64 + -16336;
	// stw r11,31928(r31)
	PPC_STORE_U32(r31.u32 + 31928, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3934;
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

__attribute__((alias("__imp__sub_827B394C"))) PPC_WEAK_FUNC(sub_827B394C);
PPC_FUNC_IMPL(__imp__sub_827B394C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3950"))) PPC_WEAK_FUNC(sub_827B3950);
PPC_FUNC_IMPL(__imp__sub_827B3950) {
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
	// li r31,3
	r31.s64 = 3;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
loc_827B3970:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534b38
	ctx.lr = 0x827B3978;
	sub_82534B38(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bge 0x827b3970
	if (!cr0.lt) goto loc_827B3970;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-18528
	ctx.r3.s64 = r11.s64 + -18528;
	// bl 0x823d9a98
	ctx.lr = 0x827B3990;
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

__attribute__((alias("__imp__sub_827B39A8"))) PPC_WEAK_FUNC(sub_827B39A8);
PPC_FUNC_IMPL(__imp__sub_827B39A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,28956
	ctx.r5.s64 = r11.s64 + 28956;
	// addi r3,r10,32220
	ctx.r3.s64 = ctx.r10.s64 + 32220;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B39C4"))) PPC_WEAK_FUNC(sub_827B39C4);
PPC_FUNC_IMPL(__imp__sub_827B39C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B39C8"))) PPC_WEAK_FUNC(sub_827B39C8);
PPC_FUNC_IMPL(__imp__sub_827B39C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,29264
	ctx.r5.s64 = r11.s64 + 29264;
	// addi r3,r10,32280
	ctx.r3.s64 = ctx.r10.s64 + 32280;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B39E4"))) PPC_WEAK_FUNC(sub_827B39E4);
PPC_FUNC_IMPL(__imp__sub_827B39E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B39E8"))) PPC_WEAK_FUNC(sub_827B39E8);
PPC_FUNC_IMPL(__imp__sub_827B39E8) {
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
	// addi r30,r31,32332
	r30.s64 = r31.s64 + 32332;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,29588
	ctx.r5.s64 = ctx.r10.s64 + 29588;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B3A20;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32332(r31)
	PPC_STORE_U32(r31.u32 + 32332, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3A30;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3A38;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,29584
	r11.s64 = r11.s64 + 29584;
	// addi r3,r9,-16248
	ctx.r3.s64 = ctx.r9.s64 + -16248;
	// stw r11,32332(r31)
	PPC_STORE_U32(r31.u32 + 32332, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3A50;
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

__attribute__((alias("__imp__sub_827B3A68"))) PPC_WEAK_FUNC(sub_827B3A68);
PPC_FUNC_IMPL(__imp__sub_827B3A68) {
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
	// addi r30,r31,32300
	r30.s64 = r31.s64 + 32300;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,29616
	ctx.r5.s64 = ctx.r10.s64 + 29616;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B3AA0;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32300(r31)
	PPC_STORE_U32(r31.u32 + 32300, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3AB0;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3AB8;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,29612
	r11.s64 = r11.s64 + 29612;
	// addi r3,r9,-16160
	ctx.r3.s64 = ctx.r9.s64 + -16160;
	// stw r11,32300(r31)
	PPC_STORE_U32(r31.u32 + 32300, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3AD0;
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

__attribute__((alias("__imp__sub_827B3AE8"))) PPC_WEAK_FUNC(sub_827B3AE8);
PPC_FUNC_IMPL(__imp__sub_827B3AE8) {
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
	// addi r30,r31,32364
	r30.s64 = r31.s64 + 32364;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,29928
	ctx.r5.s64 = ctx.r10.s64 + 29928;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B3B20;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32364(r31)
	PPC_STORE_U32(r31.u32 + 32364, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3B30;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3B38;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,29924
	r11.s64 = r11.s64 + 29924;
	// addi r3,r9,-16072
	ctx.r3.s64 = ctx.r9.s64 + -16072;
	// stw r11,32364(r31)
	PPC_STORE_U32(r31.u32 + 32364, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3B50;
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

__attribute__((alias("__imp__sub_827B3B68"))) PPC_WEAK_FUNC(sub_827B3B68);
PPC_FUNC_IMPL(__imp__sub_827B3B68) {
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
	// addi r30,r31,32396
	r30.s64 = r31.s64 + 32396;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,29960
	ctx.r5.s64 = ctx.r10.s64 + 29960;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B3BA0;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32396(r31)
	PPC_STORE_U32(r31.u32 + 32396, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3BB0;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3BB8;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,29956
	r11.s64 = r11.s64 + 29956;
	// addi r3,r9,-15984
	ctx.r3.s64 = ctx.r9.s64 + -15984;
	// stw r11,32396(r31)
	PPC_STORE_U32(r31.u32 + 32396, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3BD0;
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

__attribute__((alias("__imp__sub_827B3BE8"))) PPC_WEAK_FUNC(sub_827B3BE8);
PPC_FUNC_IMPL(__imp__sub_827B3BE8) {
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
	// addi r30,r31,32428
	r30.s64 = r31.s64 + 32428;
	// addi r5,r11,30016
	ctx.r5.s64 = r11.s64 + 30016;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824fa650
	ctx.lr = 0x827B3C1C;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32428(r31)
	PPC_STORE_U32(r31.u32 + 32428, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3C2C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3C34;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r11,r11,30012
	r11.s64 = r11.s64 + 30012;
	// addi r3,r10,-15896
	ctx.r3.s64 = ctx.r10.s64 + -15896;
	// stw r11,32428(r31)
	PPC_STORE_U32(r31.u32 + 32428, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3C4C;
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

__attribute__((alias("__imp__sub_827B3C64"))) PPC_WEAK_FUNC(sub_827B3C64);
PPC_FUNC_IMPL(__imp__sub_827B3C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3C68"))) PPC_WEAK_FUNC(sub_827B3C68);
PPC_FUNC_IMPL(__imp__sub_827B3C68) {
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
	// addi r30,r31,32468
	r30.s64 = r31.s64 + 32468;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,31148
	ctx.r5.s64 = ctx.r10.s64 + 31148;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827B3CA0;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,32468(r31)
	PPC_STORE_U32(r31.u32 + 32468, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B3CB0;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3CB8;
	sub_824FA6C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,31144
	r11.s64 = r11.s64 + 31144;
	// addi r3,r9,-15808
	ctx.r3.s64 = ctx.r9.s64 + -15808;
	// stw r11,32468(r31)
	PPC_STORE_U32(r31.u32 + 32468, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3CD0;
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

__attribute__((alias("__imp__sub_827B3CE8"))) PPC_WEAK_FUNC(sub_827B3CE8);
PPC_FUNC_IMPL(__imp__sub_827B3CE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,31864
	ctx.r5.s64 = r11.s64 + 31864;
	// addi r3,r10,32540
	ctx.r3.s64 = ctx.r10.s64 + 32540;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B3D04"))) PPC_WEAK_FUNC(sub_827B3D04);
PPC_FUNC_IMPL(__imp__sub_827B3D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3D08"))) PPC_WEAK_FUNC(sub_827B3D08);
PPC_FUNC_IMPL(__imp__sub_827B3D08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,31872
	ctx.r5.s64 = r11.s64 + 31872;
	// addi r3,r10,32520
	ctx.r3.s64 = ctx.r10.s64 + 32520;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B3D24"))) PPC_WEAK_FUNC(sub_827B3D24);
PPC_FUNC_IMPL(__imp__sub_827B3D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3D28"))) PPC_WEAK_FUNC(sub_827B3D28);
PPC_FUNC_IMPL(__imp__sub_827B3D28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,31884
	ctx.r5.s64 = r11.s64 + 31884;
	// addi r3,r10,32500
	ctx.r3.s64 = ctx.r10.s64 + 32500;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B3D44"))) PPC_WEAK_FUNC(sub_827B3D44);
PPC_FUNC_IMPL(__imp__sub_827B3D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3D48"))) PPC_WEAK_FUNC(sub_827B3D48);
PPC_FUNC_IMPL(__imp__sub_827B3D48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-15720
	ctx.r3.s64 = r11.s64 + -15720;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B3D54"))) PPC_WEAK_FUNC(sub_827B3D54);
PPC_FUNC_IMPL(__imp__sub_827B3D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3D58"))) PPC_WEAK_FUNC(sub_827B3D58);
PPC_FUNC_IMPL(__imp__sub_827B3D58) {
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
	// addi r5,r11,-30036
	ctx.r5.s64 = r11.s64 + -30036;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824fa650
	ctx.lr = 0x827B3D8C;
	sub_824FA650(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32628(r31)
	PPC_STORE_U32(r31.u32 + 32628, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B3D9C;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3DA4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r11,r11,-30040
	r11.s64 = r11.s64 + -30040;
	// addi r3,r10,-15688
	ctx.r3.s64 = ctx.r10.s64 + -15688;
	// stw r11,32628(r31)
	PPC_STORE_U32(r31.u32 + 32628, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3DBC;
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

__attribute__((alias("__imp__sub_827B3DD4"))) PPC_WEAK_FUNC(sub_827B3DD4);
PPC_FUNC_IMPL(__imp__sub_827B3DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3DD8"))) PPC_WEAK_FUNC(sub_827B3DD8);
PPC_FUNC_IMPL(__imp__sub_827B3DD8) {
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
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r31,32724
	r30.s64 = r31.s64 + 32724;
	// addi r7,r11,32628
	ctx.r7.s64 = r11.s64 + 32628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-29976
	ctx.r6.s64 = ctx.r10.s64 + -29976;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B3E14;
	sub_824FA688(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32724(r31)
	PPC_STORE_U32(r31.u32 + 32724, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B3E24;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3E2C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-29980
	r11.s64 = r11.s64 + -29980;
	// addi r3,r9,-15600
	ctx.r3.s64 = ctx.r9.s64 + -15600;
	// stw r11,32724(r31)
	PPC_STORE_U32(r31.u32 + 32724, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3E44;
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

__attribute__((alias("__imp__sub_827B3E5C"))) PPC_WEAK_FUNC(sub_827B3E5C);
PPC_FUNC_IMPL(__imp__sub_827B3E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3E60"))) PPC_WEAK_FUNC(sub_827B3E60);
PPC_FUNC_IMPL(__imp__sub_827B3E60) {
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
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r31,32660
	r30.s64 = r31.s64 + 32660;
	// addi r7,r11,32628
	ctx.r7.s64 = r11.s64 + 32628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-30016
	ctx.r6.s64 = ctx.r10.s64 + -30016;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B3E9C;
	sub_824FA688(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32660(r31)
	PPC_STORE_U32(r31.u32 + 32660, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B3EAC;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3EB4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-30020
	r11.s64 = r11.s64 + -30020;
	// addi r3,r9,-15512
	ctx.r3.s64 = ctx.r9.s64 + -15512;
	// stw r11,32660(r31)
	PPC_STORE_U32(r31.u32 + 32660, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3ECC;
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

__attribute__((alias("__imp__sub_827B3EE4"))) PPC_WEAK_FUNC(sub_827B3EE4);
PPC_FUNC_IMPL(__imp__sub_827B3EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3EE8"))) PPC_WEAK_FUNC(sub_827B3EE8);
PPC_FUNC_IMPL(__imp__sub_827B3EE8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r31,-32716
	r30.s64 = r31.s64 + -32716;
	// addi r7,r11,32628
	ctx.r7.s64 = r11.s64 + 32628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-29940
	ctx.r6.s64 = ctx.r10.s64 + -29940;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B3F24;
	sub_824FA688(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,-32716(r31)
	PPC_STORE_U32(r31.u32 + -32716, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B3F34;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3F3C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-29944
	r11.s64 = r11.s64 + -29944;
	// addi r3,r9,-15424
	ctx.r3.s64 = ctx.r9.s64 + -15424;
	// stw r11,-32716(r31)
	PPC_STORE_U32(r31.u32 + -32716, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3F54;
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

__attribute__((alias("__imp__sub_827B3F6C"))) PPC_WEAK_FUNC(sub_827B3F6C);
PPC_FUNC_IMPL(__imp__sub_827B3F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3F70"))) PPC_WEAK_FUNC(sub_827B3F70);
PPC_FUNC_IMPL(__imp__sub_827B3F70) {
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
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r31,32692
	r30.s64 = r31.s64 + 32692;
	// addi r7,r11,32628
	ctx.r7.s64 = r11.s64 + 32628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-29908
	ctx.r6.s64 = ctx.r10.s64 + -29908;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B3FAC;
	sub_824FA688(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32692(r31)
	PPC_STORE_U32(r31.u32 + 32692, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B3FBC;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B3FC4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-29912
	r11.s64 = r11.s64 + -29912;
	// addi r3,r9,-15336
	ctx.r3.s64 = ctx.r9.s64 + -15336;
	// stw r11,32692(r31)
	PPC_STORE_U32(r31.u32 + 32692, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B3FDC;
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

__attribute__((alias("__imp__sub_827B3FF4"))) PPC_WEAK_FUNC(sub_827B3FF4);
PPC_FUNC_IMPL(__imp__sub_827B3FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B3FF8"))) PPC_WEAK_FUNC(sub_827B3FF8);
PPC_FUNC_IMPL(__imp__sub_827B3FF8) {
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
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r31,32596
	r30.s64 = r31.s64 + 32596;
	// addi r7,r11,32628
	ctx.r7.s64 = r11.s64 + 32628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-29872
	ctx.r6.s64 = ctx.r10.s64 + -29872;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B4034;
	sub_824FA688(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32596(r31)
	PPC_STORE_U32(r31.u32 + 32596, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B4044;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B404C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-29876
	r11.s64 = r11.s64 + -29876;
	// addi r3,r9,-15248
	ctx.r3.s64 = ctx.r9.s64 + -15248;
	// stw r11,32596(r31)
	PPC_STORE_U32(r31.u32 + 32596, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B4064;
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

__attribute__((alias("__imp__sub_827B407C"))) PPC_WEAK_FUNC(sub_827B407C);
PPC_FUNC_IMPL(__imp__sub_827B407C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4080"))) PPC_WEAK_FUNC(sub_827B4080);
PPC_FUNC_IMPL(__imp__sub_827B4080) {
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
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r31,32756
	r30.s64 = r31.s64 + 32756;
	// addi r7,r11,32628
	ctx.r7.s64 = r11.s64 + 32628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-29840
	ctx.r6.s64 = ctx.r10.s64 + -29840;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B40BC;
	sub_824FA688(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,32756(r31)
	PPC_STORE_U32(r31.u32 + 32756, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B40CC;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B40D4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-29844
	r11.s64 = r11.s64 + -29844;
	// addi r3,r9,-15160
	ctx.r3.s64 = ctx.r9.s64 + -15160;
	// stw r11,32756(r31)
	PPC_STORE_U32(r31.u32 + 32756, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B40EC;
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

__attribute__((alias("__imp__sub_827B4104"))) PPC_WEAK_FUNC(sub_827B4104);
PPC_FUNC_IMPL(__imp__sub_827B4104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4108"))) PPC_WEAK_FUNC(sub_827B4108);
PPC_FUNC_IMPL(__imp__sub_827B4108) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r31,-32684
	r30.s64 = r31.s64 + -32684;
	// addi r7,r11,32628
	ctx.r7.s64 = r11.s64 + 32628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-29812
	ctx.r6.s64 = ctx.r10.s64 + -29812;
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B4144;
	sub_824FA688(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,-32684(r31)
	PPC_STORE_U32(r31.u32 + -32684, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B4154;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B415C;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-29816
	r11.s64 = r11.s64 + -29816;
	// addi r3,r9,-15072
	ctx.r3.s64 = ctx.r9.s64 + -15072;
	// stw r11,-32684(r31)
	PPC_STORE_U32(r31.u32 + -32684, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B4174;
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

__attribute__((alias("__imp__sub_827B418C"))) PPC_WEAK_FUNC(sub_827B418C);
PPC_FUNC_IMPL(__imp__sub_827B418C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4190"))) PPC_WEAK_FUNC(sub_827B4190);
PPC_FUNC_IMPL(__imp__sub_827B4190) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r31,-32748
	r30.s64 = r31.s64 + -32748;
	// addi r7,r11,32628
	ctx.r7.s64 = r11.s64 + 32628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-29776
	ctx.r6.s64 = ctx.r10.s64 + -29776;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa688
	ctx.lr = 0x827B41CC;
	sub_824FA688(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r11,r11,-30048
	r11.s64 = r11.s64 + -30048;
	// stw r11,-32748(r31)
	PPC_STORE_U32(r31.u32 + -32748, r11.u32);
	// bl 0x82530238
	ctx.lr = 0x827B41DC;
	sub_82530238(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827B41E4;
	sub_824FA6C0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-29780
	r11.s64 = r11.s64 + -29780;
	// addi r3,r9,-14984
	ctx.r3.s64 = ctx.r9.s64 + -14984;
	// stw r11,-32748(r31)
	PPC_STORE_U32(r31.u32 + -32748, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827B41FC;
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

__attribute__((alias("__imp__sub_827B4214"))) PPC_WEAK_FUNC(sub_827B4214);
PPC_FUNC_IMPL(__imp__sub_827B4214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4218"))) PPC_WEAK_FUNC(sub_827B4218);
PPC_FUNC_IMPL(__imp__sub_827B4218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r5,r11,-29376
	ctx.r5.s64 = r11.s64 + -29376;
	// addi r3,r10,-32584
	ctx.r3.s64 = ctx.r10.s64 + -32584;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4234"))) PPC_WEAK_FUNC(sub_827B4234);
PPC_FUNC_IMPL(__imp__sub_827B4234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4238"))) PPC_WEAK_FUNC(sub_827B4238);
PPC_FUNC_IMPL(__imp__sub_827B4238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r5,r11,-29360
	ctx.r5.s64 = r11.s64 + -29360;
	// addi r3,r10,-32644
	ctx.r3.s64 = ctx.r10.s64 + -32644;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4254"))) PPC_WEAK_FUNC(sub_827B4254);
PPC_FUNC_IMPL(__imp__sub_827B4254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4258"))) PPC_WEAK_FUNC(sub_827B4258);
PPC_FUNC_IMPL(__imp__sub_827B4258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r5,r11,-29344
	ctx.r5.s64 = r11.s64 + -29344;
	// addi r3,r10,-32604
	ctx.r3.s64 = ctx.r10.s64 + -32604;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4274"))) PPC_WEAK_FUNC(sub_827B4274);
PPC_FUNC_IMPL(__imp__sub_827B4274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4278"))) PPC_WEAK_FUNC(sub_827B4278);
PPC_FUNC_IMPL(__imp__sub_827B4278) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r5,r11,-29320
	ctx.r5.s64 = r11.s64 + -29320;
	// addi r3,r10,-32624
	ctx.r3.s64 = ctx.r10.s64 + -32624;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4294"))) PPC_WEAK_FUNC(sub_827B4294);
PPC_FUNC_IMPL(__imp__sub_827B4294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4298"))) PPC_WEAK_FUNC(sub_827B4298);
PPC_FUNC_IMPL(__imp__sub_827B4298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14896
	ctx.r3.s64 = r11.s64 + -14896;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B42A4"))) PPC_WEAK_FUNC(sub_827B42A4);
PPC_FUNC_IMPL(__imp__sub_827B42A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B42A8"))) PPC_WEAK_FUNC(sub_827B42A8);
PPC_FUNC_IMPL(__imp__sub_827B42A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14872
	ctx.r3.s64 = r11.s64 + -14872;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B42B4"))) PPC_WEAK_FUNC(sub_827B42B4);
PPC_FUNC_IMPL(__imp__sub_827B42B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B42B8"))) PPC_WEAK_FUNC(sub_827B42B8);
PPC_FUNC_IMPL(__imp__sub_827B42B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14840
	ctx.r3.s64 = r11.s64 + -14840;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B42C4"))) PPC_WEAK_FUNC(sub_827B42C4);
PPC_FUNC_IMPL(__imp__sub_827B42C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B42C8"))) PPC_WEAK_FUNC(sub_827B42C8);
PPC_FUNC_IMPL(__imp__sub_827B42C8) {
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
	// lis r11,-32172
	r11.s64 = -2108424192;
	// lis r10,-32172
	ctx.r10.s64 = -2108424192;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// addi r5,r9,-23692
	ctx.r5.s64 = ctx.r9.s64 + -23692;
	// addi r3,r8,-32536
	ctx.r3.s64 = ctx.r8.s64 + -32536;
	// addi r7,r11,-5392
	ctx.r7.s64 = r11.s64 + -5392;
	// addi r6,r10,-5520
	ctx.r6.s64 = ctx.r10.s64 + -5520;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8253da78
	ctx.lr = 0x827B42FC;
	sub_8253DA78(ctx, base);
	// lis r7,-32132
	ctx.r7.s64 = -2105802752;
	// addi r3,r7,-14808
	ctx.r3.s64 = ctx.r7.s64 + -14808;
	// bl 0x823d9a98
	ctx.lr = 0x827B4308;
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

__attribute__((alias("__imp__sub_827B4318"))) PPC_WEAK_FUNC(sub_827B4318);
PPC_FUNC_IMPL(__imp__sub_827B4318) {
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
	// lis r11,-32172
	r11.s64 = -2108424192;
	// lis r10,-32172
	ctx.r10.s64 = -2108424192;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// addi r5,r9,-23300
	ctx.r5.s64 = ctx.r9.s64 + -23300;
	// addi r3,r8,-32520
	ctx.r3.s64 = ctx.r8.s64 + -32520;
	// addi r7,r11,-1728
	ctx.r7.s64 = r11.s64 + -1728;
	// addi r6,r10,-1800
	ctx.r6.s64 = ctx.r10.s64 + -1800;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8253da78
	ctx.lr = 0x827B434C;
	sub_8253DA78(ctx, base);
	// lis r7,-32132
	ctx.r7.s64 = -2105802752;
	// addi r3,r7,-14792
	ctx.r3.s64 = ctx.r7.s64 + -14792;
	// bl 0x823d9a98
	ctx.lr = 0x827B4358;
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

__attribute__((alias("__imp__sub_827B4368"))) PPC_WEAK_FUNC(sub_827B4368);
PPC_FUNC_IMPL(__imp__sub_827B4368) {
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
	// lis r11,-32172
	r11.s64 = -2108424192;
	// lis r10,-32172
	ctx.r10.s64 = -2108424192;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// addi r5,r9,-22924
	ctx.r5.s64 = ctx.r9.s64 + -22924;
	// addi r3,r8,-32504
	ctx.r3.s64 = ctx.r8.s64 + -32504;
	// addi r7,r11,-368
	ctx.r7.s64 = r11.s64 + -368;
	// addi r6,r10,-1136
	ctx.r6.s64 = ctx.r10.s64 + -1136;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8253da78
	ctx.lr = 0x827B439C;
	sub_8253DA78(ctx, base);
	// lis r7,-32132
	ctx.r7.s64 = -2105802752;
	// addi r3,r7,-14776
	ctx.r3.s64 = ctx.r7.s64 + -14776;
	// bl 0x823d9a98
	ctx.lr = 0x827B43A8;
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

__attribute__((alias("__imp__sub_827B43B8"))) PPC_WEAK_FUNC(sub_827B43B8);
PPC_FUNC_IMPL(__imp__sub_827B43B8) {
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
	// lis r11,-32172
	r11.s64 = -2108424192;
	// lis r10,-32172
	ctx.r10.s64 = -2108424192;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// addi r5,r9,-22556
	ctx.r5.s64 = ctx.r9.s64 + -22556;
	// addi r3,r8,-32488
	ctx.r3.s64 = ctx.r8.s64 + -32488;
	// addi r7,r11,1400
	ctx.r7.s64 = r11.s64 + 1400;
	// addi r6,r10,-32
	ctx.r6.s64 = ctx.r10.s64 + -32;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8253da78
	ctx.lr = 0x827B43EC;
	sub_8253DA78(ctx, base);
	// lis r7,-32132
	ctx.r7.s64 = -2105802752;
	// addi r3,r7,-14760
	ctx.r3.s64 = ctx.r7.s64 + -14760;
	// bl 0x823d9a98
	ctx.lr = 0x827B43F8;
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

__attribute__((alias("__imp__sub_827B4408"))) PPC_WEAK_FUNC(sub_827B4408);
PPC_FUNC_IMPL(__imp__sub_827B4408) {
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
	// lis r11,-32172
	r11.s64 = -2108424192;
	// lis r10,-32172
	ctx.r10.s64 = -2108424192;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// addi r5,r9,-19244
	ctx.r5.s64 = ctx.r9.s64 + -19244;
	// addi r3,r8,-32472
	ctx.r3.s64 = ctx.r8.s64 + -32472;
	// addi r7,r11,28904
	ctx.r7.s64 = r11.s64 + 28904;
	// addi r6,r10,28784
	ctx.r6.s64 = ctx.r10.s64 + 28784;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x8253da78
	ctx.lr = 0x827B443C;
	sub_8253DA78(ctx, base);
	// lis r7,-32132
	ctx.r7.s64 = -2105802752;
	// addi r3,r7,-14744
	ctx.r3.s64 = ctx.r7.s64 + -14744;
	// bl 0x823d9a98
	ctx.lr = 0x827B4448;
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

__attribute__((alias("__imp__sub_827B4458"))) PPC_WEAK_FUNC(sub_827B4458);
PPC_FUNC_IMPL(__imp__sub_827B4458) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-18196
	ctx.r3.s64 = r11.s64 + -18196;
	// bl 0x821c9790
	ctx.lr = 0x827B4474;
	sub_821C9790(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// stw r3,-32452(r10)
	PPC_STORE_U32(ctx.r10.u32 + -32452, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B448C"))) PPC_WEAK_FUNC(sub_827B448C);
PPC_FUNC_IMPL(__imp__sub_827B448C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4490"))) PPC_WEAK_FUNC(sub_827B4490);
PPC_FUNC_IMPL(__imp__sub_827B4490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,3760
	ctx.r7.s64 = ctx.r8.s64 + 3760;
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

__attribute__((alias("__imp__sub_827B44B0"))) PPC_WEAK_FUNC(sub_827B44B0);
PPC_FUNC_IMPL(__imp__sub_827B44B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,3768
	ctx.r7.s64 = ctx.r8.s64 + 3768;
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

__attribute__((alias("__imp__sub_827B44D0"))) PPC_WEAK_FUNC(sub_827B44D0);
PPC_FUNC_IMPL(__imp__sub_827B44D0) {
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
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r31,r11,3780
	r31.s64 = r11.s64 + 3780;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x82550d08
	ctx.lr = 0x827B44F0;
	sub_82550D08(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// addi r3,r10,-14728
	ctx.r3.s64 = ctx.r10.s64 + -14728;
	// bl 0x823d9a98
	ctx.lr = 0x827B4504;
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

__attribute__((alias("__imp__sub_827B4518"))) PPC_WEAK_FUNC(sub_827B4518);
PPC_FUNC_IMPL(__imp__sub_827B4518) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r5,r11,-16716
	ctx.r5.s64 = r11.s64 + -16716;
	// addi r3,r10,-32440
	ctx.r3.s64 = ctx.r10.s64 + -32440;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4534"))) PPC_WEAK_FUNC(sub_827B4534);
PPC_FUNC_IMPL(__imp__sub_827B4534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4538"))) PPC_WEAK_FUNC(sub_827B4538);
PPC_FUNC_IMPL(__imp__sub_827B4538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32416
	ctx.r3.s64 = r11.s64 + -32416;
	// b 0x82549a28
	sub_82549A28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4544"))) PPC_WEAK_FUNC(sub_827B4544);
PPC_FUNC_IMPL(__imp__sub_827B4544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4548"))) PPC_WEAK_FUNC(sub_827B4548);
PPC_FUNC_IMPL(__imp__sub_827B4548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14592
	ctx.r3.s64 = r11.s64 + -14592;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4554"))) PPC_WEAK_FUNC(sub_827B4554);
PPC_FUNC_IMPL(__imp__sub_827B4554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4558"))) PPC_WEAK_FUNC(sub_827B4558);
PPC_FUNC_IMPL(__imp__sub_827B4558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14560
	ctx.r3.s64 = r11.s64 + -14560;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4564"))) PPC_WEAK_FUNC(sub_827B4564);
PPC_FUNC_IMPL(__imp__sub_827B4564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4568"))) PPC_WEAK_FUNC(sub_827B4568);
PPC_FUNC_IMPL(__imp__sub_827B4568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14528
	ctx.r3.s64 = r11.s64 + -14528;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4574"))) PPC_WEAK_FUNC(sub_827B4574);
PPC_FUNC_IMPL(__imp__sub_827B4574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4578"))) PPC_WEAK_FUNC(sub_827B4578);
PPC_FUNC_IMPL(__imp__sub_827B4578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14648
	ctx.r3.s64 = r11.s64 + -14648;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4584"))) PPC_WEAK_FUNC(sub_827B4584);
PPC_FUNC_IMPL(__imp__sub_827B4584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

