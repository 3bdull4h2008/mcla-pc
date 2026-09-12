#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827A9A84"))) PPC_WEAK_FUNC(sub_827A9A84);
PPC_FUNC_IMPL(__imp__sub_827A9A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9A88"))) PPC_WEAK_FUNC(sub_827A9A88);
PPC_FUNC_IMPL(__imp__sub_827A9A88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-3100
	ctx.r5.s64 = r11.s64 + -3100;
	// addi r3,r10,-7068
	ctx.r3.s64 = ctx.r10.s64 + -7068;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9AA4"))) PPC_WEAK_FUNC(sub_827A9AA4);
PPC_FUNC_IMPL(__imp__sub_827A9AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9AA8"))) PPC_WEAK_FUNC(sub_827A9AA8);
PPC_FUNC_IMPL(__imp__sub_827A9AA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-3088
	ctx.r5.s64 = r11.s64 + -3088;
	// addi r3,r10,-7088
	ctx.r3.s64 = ctx.r10.s64 + -7088;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9AC4"))) PPC_WEAK_FUNC(sub_827A9AC4);
PPC_FUNC_IMPL(__imp__sub_827A9AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9AC8"))) PPC_WEAK_FUNC(sub_827A9AC8);
PPC_FUNC_IMPL(__imp__sub_827A9AC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,23
	ctx.r9.s64 = 23;
	// addi r11,r11,-6984
	r11.s64 = r11.s64 + -6984;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_827A9ADC:
	// stb r10,-2(r11)
	PPC_STORE_U8(r11.u32 + -2, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r10.u8);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// stb r10,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r10.u8);
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// stw r10,6(r11)
	PPC_STORE_U32(r11.u32 + 6, ctx.r10.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x827a9adc
	if (!cr0.lt) goto loc_827A9ADC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A9B04"))) PPC_WEAK_FUNC(sub_827A9B04);
PPC_FUNC_IMPL(__imp__sub_827A9B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9B08"))) PPC_WEAK_FUNC(sub_827A9B08);
PPC_FUNC_IMPL(__imp__sub_827A9B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23552
	ctx.r5.s64 = r11.s64 + 23552;
	// addi r3,r10,-6680
	ctx.r3.s64 = ctx.r10.s64 + -6680;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9B24"))) PPC_WEAK_FUNC(sub_827A9B24);
PPC_FUNC_IMPL(__imp__sub_827A9B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9B28"))) PPC_WEAK_FUNC(sub_827A9B28);
PPC_FUNC_IMPL(__imp__sub_827A9B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-27408
	ctx.r5.s64 = r11.s64 + -27408;
	// addi r3,r10,-6428
	ctx.r3.s64 = ctx.r10.s64 + -6428;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9B44"))) PPC_WEAK_FUNC(sub_827A9B44);
PPC_FUNC_IMPL(__imp__sub_827A9B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9B48"))) PPC_WEAK_FUNC(sub_827A9B48);
PPC_FUNC_IMPL(__imp__sub_827A9B48) {
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
	ctx.lr = 0x827A9B70;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-15152
	r11.s64 = ctx.r7.s64 + -15152;
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

__attribute__((alias("__imp__sub_827A9BBC"))) PPC_WEAK_FUNC(sub_827A9BBC);
PPC_FUNC_IMPL(__imp__sub_827A9BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9BC0"))) PPC_WEAK_FUNC(sub_827A9BC0);
PPC_FUNC_IMPL(__imp__sub_827A9BC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-15104
	ctx.r7.s64 = ctx.r8.s64 + -15104;
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

__attribute__((alias("__imp__sub_827A9BE0"))) PPC_WEAK_FUNC(sub_827A9BE0);
PPC_FUNC_IMPL(__imp__sub_827A9BE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17828
	ctx.r5.s64 = r11.s64 + -17828;
	// addi r3,r10,-6208
	ctx.r3.s64 = ctx.r10.s64 + -6208;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9BFC"))) PPC_WEAK_FUNC(sub_827A9BFC);
PPC_FUNC_IMPL(__imp__sub_827A9BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9C00"))) PPC_WEAK_FUNC(sub_827A9C00);
PPC_FUNC_IMPL(__imp__sub_827A9C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17816
	ctx.r5.s64 = r11.s64 + -17816;
	// addi r3,r10,-6188
	ctx.r3.s64 = ctx.r10.s64 + -6188;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9C1C"))) PPC_WEAK_FUNC(sub_827A9C1C);
PPC_FUNC_IMPL(__imp__sub_827A9C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9C20"))) PPC_WEAK_FUNC(sub_827A9C20);
PPC_FUNC_IMPL(__imp__sub_827A9C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-17800
	ctx.r5.s64 = r11.s64 + -17800;
	// addi r3,r10,-6228
	ctx.r3.s64 = ctx.r10.s64 + -6228;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9C3C"))) PPC_WEAK_FUNC(sub_827A9C3C);
PPC_FUNC_IMPL(__imp__sub_827A9C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9C40"))) PPC_WEAK_FUNC(sub_827A9C40);
PPC_FUNC_IMPL(__imp__sub_827A9C40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-13588
	ctx.r7.s64 = ctx.r8.s64 + -13588;
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

__attribute__((alias("__imp__sub_827A9C60"))) PPC_WEAK_FUNC(sub_827A9C60);
PPC_FUNC_IMPL(__imp__sub_827A9C60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-13580
	ctx.r7.s64 = ctx.r8.s64 + -13580;
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

__attribute__((alias("__imp__sub_827A9C80"))) PPC_WEAK_FUNC(sub_827A9C80);
PPC_FUNC_IMPL(__imp__sub_827A9C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-15872
	ctx.r5.s64 = r11.s64 + -15872;
	// addi r3,r10,-5168
	ctx.r3.s64 = ctx.r10.s64 + -5168;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9C9C"))) PPC_WEAK_FUNC(sub_827A9C9C);
PPC_FUNC_IMPL(__imp__sub_827A9C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9CA0"))) PPC_WEAK_FUNC(sub_827A9CA0);
PPC_FUNC_IMPL(__imp__sub_827A9CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-14120
	ctx.r5.s64 = r11.s64 + -14120;
	// addi r3,r10,-5124
	ctx.r3.s64 = ctx.r10.s64 + -5124;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9CBC"))) PPC_WEAK_FUNC(sub_827A9CBC);
PPC_FUNC_IMPL(__imp__sub_827A9CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9CC0"))) PPC_WEAK_FUNC(sub_827A9CC0);
PPC_FUNC_IMPL(__imp__sub_827A9CC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-12672
	ctx.r7.s64 = ctx.r8.s64 + -12672;
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

__attribute__((alias("__imp__sub_827A9CE0"))) PPC_WEAK_FUNC(sub_827A9CE0);
PPC_FUNC_IMPL(__imp__sub_827A9CE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-12664
	ctx.r7.s64 = ctx.r8.s64 + -12664;
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

__attribute__((alias("__imp__sub_827A9D00"))) PPC_WEAK_FUNC(sub_827A9D00);
PPC_FUNC_IMPL(__imp__sub_827A9D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-10168
	ctx.r5.s64 = r11.s64 + -10168;
	// addi r3,r10,-5028
	ctx.r3.s64 = ctx.r10.s64 + -5028;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9D1C"))) PPC_WEAK_FUNC(sub_827A9D1C);
PPC_FUNC_IMPL(__imp__sub_827A9D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9D20"))) PPC_WEAK_FUNC(sub_827A9D20);
PPC_FUNC_IMPL(__imp__sub_827A9D20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-10152
	ctx.r5.s64 = r11.s64 + -10152;
	// addi r3,r10,-5048
	ctx.r3.s64 = ctx.r10.s64 + -5048;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9D3C"))) PPC_WEAK_FUNC(sub_827A9D3C);
PPC_FUNC_IMPL(__imp__sub_827A9D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9D40"))) PPC_WEAK_FUNC(sub_827A9D40);
PPC_FUNC_IMPL(__imp__sub_827A9D40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-9656
	ctx.r5.s64 = r11.s64 + -9656;
	// addi r3,r10,-4984
	ctx.r3.s64 = ctx.r10.s64 + -4984;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9D5C"))) PPC_WEAK_FUNC(sub_827A9D5C);
PPC_FUNC_IMPL(__imp__sub_827A9D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9D60"))) PPC_WEAK_FUNC(sub_827A9D60);
PPC_FUNC_IMPL(__imp__sub_827A9D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-9644
	ctx.r5.s64 = r11.s64 + -9644;
	// addi r3,r10,-5004
	ctx.r3.s64 = ctx.r10.s64 + -5004;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9D7C"))) PPC_WEAK_FUNC(sub_827A9D7C);
PPC_FUNC_IMPL(__imp__sub_827A9D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9D80"))) PPC_WEAK_FUNC(sub_827A9D80);
PPC_FUNC_IMPL(__imp__sub_827A9D80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-7352
	ctx.r5.s64 = r11.s64 + -7352;
	// addi r3,r10,-4868
	ctx.r3.s64 = ctx.r10.s64 + -4868;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9D9C"))) PPC_WEAK_FUNC(sub_827A9D9C);
PPC_FUNC_IMPL(__imp__sub_827A9D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9DA0"))) PPC_WEAK_FUNC(sub_827A9DA0);
PPC_FUNC_IMPL(__imp__sub_827A9DA0) {
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
	// addi r3,r11,-4336
	ctx.r3.s64 = r11.s64 + -4336;
	// bl 0x821c8ed8
	ctx.lr = 0x827A9DB8;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29664
	ctx.r3.s64 = ctx.r10.s64 + -29664;
	// bl 0x823d9a98
	ctx.lr = 0x827A9DC4;
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

__attribute__((alias("__imp__sub_827A9DD4"))) PPC_WEAK_FUNC(sub_827A9DD4);
PPC_FUNC_IMPL(__imp__sub_827A9DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9DD8"))) PPC_WEAK_FUNC(sub_827A9DD8);
PPC_FUNC_IMPL(__imp__sub_827A9DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-3120
	ctx.r5.s64 = r11.s64 + -3120;
	// addi r3,r10,-4204
	ctx.r3.s64 = ctx.r10.s64 + -4204;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9DF4"))) PPC_WEAK_FUNC(sub_827A9DF4);
PPC_FUNC_IMPL(__imp__sub_827A9DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9DF8"))) PPC_WEAK_FUNC(sub_827A9DF8);
PPC_FUNC_IMPL(__imp__sub_827A9DF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-11596
	ctx.r7.s64 = ctx.r8.s64 + -11596;
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

__attribute__((alias("__imp__sub_827A9E18"))) PPC_WEAK_FUNC(sub_827A9E18);
PPC_FUNC_IMPL(__imp__sub_827A9E18) {
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
	// addi r3,r11,-3556
	ctx.r3.s64 = r11.s64 + -3556;
	// bl 0x824f09d0
	ctx.lr = 0x827A9E30;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29552
	ctx.r3.s64 = ctx.r10.s64 + -29552;
	// bl 0x823d9a98
	ctx.lr = 0x827A9E3C;
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

__attribute__((alias("__imp__sub_827A9E4C"))) PPC_WEAK_FUNC(sub_827A9E4C);
PPC_FUNC_IMPL(__imp__sub_827A9E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9E50"))) PPC_WEAK_FUNC(sub_827A9E50);
PPC_FUNC_IMPL(__imp__sub_827A9E50) {
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
	// addi r3,r11,-3040
	ctx.r3.s64 = r11.s64 + -3040;
	// bl 0x824f09d0
	ctx.lr = 0x827A9E68;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29648
	ctx.r3.s64 = ctx.r10.s64 + -29648;
	// bl 0x823d9a98
	ctx.lr = 0x827A9E74;
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

__attribute__((alias("__imp__sub_827A9E84"))) PPC_WEAK_FUNC(sub_827A9E84);
PPC_FUNC_IMPL(__imp__sub_827A9E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9E88"))) PPC_WEAK_FUNC(sub_827A9E88);
PPC_FUNC_IMPL(__imp__sub_827A9E88) {
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
	// addi r3,r11,-3348
	ctx.r3.s64 = r11.s64 + -3348;
	// bl 0x824f09d0
	ctx.lr = 0x827A9EA0;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29632
	ctx.r3.s64 = ctx.r10.s64 + -29632;
	// bl 0x823d9a98
	ctx.lr = 0x827A9EAC;
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

__attribute__((alias("__imp__sub_827A9EBC"))) PPC_WEAK_FUNC(sub_827A9EBC);
PPC_FUNC_IMPL(__imp__sub_827A9EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9EC0"))) PPC_WEAK_FUNC(sub_827A9EC0);
PPC_FUNC_IMPL(__imp__sub_827A9EC0) {
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
	// addi r3,r11,-3404
	ctx.r3.s64 = r11.s64 + -3404;
	// bl 0x824f09d0
	ctx.lr = 0x827A9ED8;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29616
	ctx.r3.s64 = ctx.r10.s64 + -29616;
	// bl 0x823d9a98
	ctx.lr = 0x827A9EE4;
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

__attribute__((alias("__imp__sub_827A9EF4"))) PPC_WEAK_FUNC(sub_827A9EF4);
PPC_FUNC_IMPL(__imp__sub_827A9EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9EF8"))) PPC_WEAK_FUNC(sub_827A9EF8);
PPC_FUNC_IMPL(__imp__sub_827A9EF8) {
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
	// addi r3,r11,-3096
	ctx.r3.s64 = r11.s64 + -3096;
	// bl 0x824f09d0
	ctx.lr = 0x827A9F10;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29600
	ctx.r3.s64 = ctx.r10.s64 + -29600;
	// bl 0x823d9a98
	ctx.lr = 0x827A9F1C;
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

__attribute__((alias("__imp__sub_827A9F2C"))) PPC_WEAK_FUNC(sub_827A9F2C);
PPC_FUNC_IMPL(__imp__sub_827A9F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9F30"))) PPC_WEAK_FUNC(sub_827A9F30);
PPC_FUNC_IMPL(__imp__sub_827A9F30) {
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
	// addi r3,r11,-3232
	ctx.r3.s64 = r11.s64 + -3232;
	// bl 0x824f09d0
	ctx.lr = 0x827A9F48;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29584
	ctx.r3.s64 = ctx.r10.s64 + -29584;
	// bl 0x823d9a98
	ctx.lr = 0x827A9F54;
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

__attribute__((alias("__imp__sub_827A9F64"))) PPC_WEAK_FUNC(sub_827A9F64);
PPC_FUNC_IMPL(__imp__sub_827A9F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9F68"))) PPC_WEAK_FUNC(sub_827A9F68);
PPC_FUNC_IMPL(__imp__sub_827A9F68) {
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
	// addi r3,r11,-3500
	ctx.r3.s64 = r11.s64 + -3500;
	// bl 0x824f09d0
	ctx.lr = 0x827A9F80;
	sub_824F09D0(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29568
	ctx.r3.s64 = ctx.r10.s64 + -29568;
	// bl 0x823d9a98
	ctx.lr = 0x827A9F8C;
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

__attribute__((alias("__imp__sub_827A9F9C"))) PPC_WEAK_FUNC(sub_827A9F9C);
PPC_FUNC_IMPL(__imp__sub_827A9F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9FA0"))) PPC_WEAK_FUNC(sub_827A9FA0);
PPC_FUNC_IMPL(__imp__sub_827A9FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29536
	ctx.r3.s64 = r11.s64 + -29536;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9FAC"))) PPC_WEAK_FUNC(sub_827A9FAC);
PPC_FUNC_IMPL(__imp__sub_827A9FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9FB0"))) PPC_WEAK_FUNC(sub_827A9FB0);
PPC_FUNC_IMPL(__imp__sub_827A9FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1828
	ctx.r5.s64 = r11.s64 + -1828;
	// addi r3,r10,-3156
	ctx.r3.s64 = ctx.r10.s64 + -3156;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9FCC"))) PPC_WEAK_FUNC(sub_827A9FCC);
PPC_FUNC_IMPL(__imp__sub_827A9FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9FD0"))) PPC_WEAK_FUNC(sub_827A9FD0);
PPC_FUNC_IMPL(__imp__sub_827A9FD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1812
	ctx.r5.s64 = r11.s64 + -1812;
	// addi r3,r10,-3424
	ctx.r3.s64 = ctx.r10.s64 + -3424;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A9FEC"))) PPC_WEAK_FUNC(sub_827A9FEC);
PPC_FUNC_IMPL(__imp__sub_827A9FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A9FF0"))) PPC_WEAK_FUNC(sub_827A9FF0);
PPC_FUNC_IMPL(__imp__sub_827A9FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1792
	ctx.r5.s64 = r11.s64 + -1792;
	// addi r3,r10,-3576
	ctx.r3.s64 = ctx.r10.s64 + -3576;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA00C"))) PPC_WEAK_FUNC(sub_827AA00C);
PPC_FUNC_IMPL(__imp__sub_827AA00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA010"))) PPC_WEAK_FUNC(sub_827AA010);
PPC_FUNC_IMPL(__imp__sub_827AA010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1784
	ctx.r5.s64 = r11.s64 + -1784;
	// addi r3,r10,-3176
	ctx.r3.s64 = ctx.r10.s64 + -3176;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA02C"))) PPC_WEAK_FUNC(sub_827AA02C);
PPC_FUNC_IMPL(__imp__sub_827AA02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA030"))) PPC_WEAK_FUNC(sub_827AA030);
PPC_FUNC_IMPL(__imp__sub_827AA030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1768
	ctx.r5.s64 = r11.s64 + -1768;
	// addi r3,r10,-3292
	ctx.r3.s64 = ctx.r10.s64 + -3292;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA04C"))) PPC_WEAK_FUNC(sub_827AA04C);
PPC_FUNC_IMPL(__imp__sub_827AA04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA050"))) PPC_WEAK_FUNC(sub_827AA050);
PPC_FUNC_IMPL(__imp__sub_827AA050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1756
	ctx.r5.s64 = r11.s64 + -1756;
	// addi r3,r10,-3616
	ctx.r3.s64 = ctx.r10.s64 + -3616;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA06C"))) PPC_WEAK_FUNC(sub_827AA06C);
PPC_FUNC_IMPL(__imp__sub_827AA06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA070"))) PPC_WEAK_FUNC(sub_827AA070);
PPC_FUNC_IMPL(__imp__sub_827AA070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1740
	ctx.r5.s64 = r11.s64 + -1740;
	// addi r3,r10,-3444
	ctx.r3.s64 = ctx.r10.s64 + -3444;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA08C"))) PPC_WEAK_FUNC(sub_827AA08C);
PPC_FUNC_IMPL(__imp__sub_827AA08C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA090"))) PPC_WEAK_FUNC(sub_827AA090);
PPC_FUNC_IMPL(__imp__sub_827AA090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1724
	ctx.r5.s64 = r11.s64 + -1724;
	// addi r3,r10,-3272
	ctx.r3.s64 = ctx.r10.s64 + -3272;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA0AC"))) PPC_WEAK_FUNC(sub_827AA0AC);
PPC_FUNC_IMPL(__imp__sub_827AA0AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA0B0"))) PPC_WEAK_FUNC(sub_827AA0B0);
PPC_FUNC_IMPL(__imp__sub_827AA0B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1712
	ctx.r5.s64 = r11.s64 + -1712;
	// addi r3,r10,-3596
	ctx.r3.s64 = ctx.r10.s64 + -3596;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA0CC"))) PPC_WEAK_FUNC(sub_827AA0CC);
PPC_FUNC_IMPL(__imp__sub_827AA0CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA0D0"))) PPC_WEAK_FUNC(sub_827AA0D0);
PPC_FUNC_IMPL(__imp__sub_827AA0D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1704
	ctx.r5.s64 = r11.s64 + -1704;
	// addi r3,r10,-3116
	ctx.r3.s64 = ctx.r10.s64 + -3116;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA0EC"))) PPC_WEAK_FUNC(sub_827AA0EC);
PPC_FUNC_IMPL(__imp__sub_827AA0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA0F0"))) PPC_WEAK_FUNC(sub_827AA0F0);
PPC_FUNC_IMPL(__imp__sub_827AA0F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1692
	ctx.r5.s64 = r11.s64 + -1692;
	// addi r3,r10,-3136
	ctx.r3.s64 = ctx.r10.s64 + -3136;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA10C"))) PPC_WEAK_FUNC(sub_827AA10C);
PPC_FUNC_IMPL(__imp__sub_827AA10C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA110"))) PPC_WEAK_FUNC(sub_827AA110);
PPC_FUNC_IMPL(__imp__sub_827AA110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1676
	ctx.r5.s64 = r11.s64 + -1676;
	// addi r3,r10,-3252
	ctx.r3.s64 = ctx.r10.s64 + -3252;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA12C"))) PPC_WEAK_FUNC(sub_827AA12C);
PPC_FUNC_IMPL(__imp__sub_827AA12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA130"))) PPC_WEAK_FUNC(sub_827AA130);
PPC_FUNC_IMPL(__imp__sub_827AA130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-1316
	ctx.r5.s64 = r11.s64 + -1316;
	// addi r3,r10,8632
	ctx.r3.s64 = ctx.r10.s64 + 8632;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA14C"))) PPC_WEAK_FUNC(sub_827AA14C);
PPC_FUNC_IMPL(__imp__sub_827AA14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA150"))) PPC_WEAK_FUNC(sub_827AA150);
PPC_FUNC_IMPL(__imp__sub_827AA150) {
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
	// addi r3,r11,-2984
	ctx.r3.s64 = r11.s64 + -2984;
	// bl 0x82489428
	ctx.lr = 0x827AA168;
	sub_82489428(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29512
	ctx.r3.s64 = ctx.r10.s64 + -29512;
	// bl 0x823d9a98
	ctx.lr = 0x827AA174;
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

__attribute__((alias("__imp__sub_827AA184"))) PPC_WEAK_FUNC(sub_827AA184);
PPC_FUNC_IMPL(__imp__sub_827AA184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA188"))) PPC_WEAK_FUNC(sub_827AA188);
PPC_FUNC_IMPL(__imp__sub_827AA188) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,8796
	r30.s64 = r31.s64 + 8796;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-952
	ctx.r5.s64 = ctx.r10.s64 + -952;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA1C0;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8796(r31)
	PPC_STORE_U32(r31.u32 + 8796, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA1D0;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA1D8;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-956
	r11.s64 = r11.s64 + -956;
	// addi r3,r9,-29480
	ctx.r3.s64 = ctx.r9.s64 + -29480;
	// stw r11,8796(r31)
	PPC_STORE_U32(r31.u32 + 8796, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA1F0;
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

__attribute__((alias("__imp__sub_827AA208"))) PPC_WEAK_FUNC(sub_827AA208);
PPC_FUNC_IMPL(__imp__sub_827AA208) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,8828
	r30.s64 = r31.s64 + 8828;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-928
	ctx.r5.s64 = ctx.r10.s64 + -928;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA240;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA250;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA258;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-932
	r11.s64 = r11.s64 + -932;
	// addi r3,r9,-29392
	ctx.r3.s64 = ctx.r9.s64 + -29392;
	// stw r11,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA270;
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

__attribute__((alias("__imp__sub_827AA288"))) PPC_WEAK_FUNC(sub_827AA288);
PPC_FUNC_IMPL(__imp__sub_827AA288) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,8860
	r30.s64 = r31.s64 + 8860;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-900
	ctx.r5.s64 = ctx.r10.s64 + -900;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA2C0;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8860(r31)
	PPC_STORE_U32(r31.u32 + 8860, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA2D0;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA2D8;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,-904
	r11.s64 = r11.s64 + -904;
	// addi r3,r9,-29304
	ctx.r3.s64 = ctx.r9.s64 + -29304;
	// stw r11,8860(r31)
	PPC_STORE_U32(r31.u32 + 8860, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA2F0;
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

__attribute__((alias("__imp__sub_827AA308"))) PPC_WEAK_FUNC(sub_827AA308);
PPC_FUNC_IMPL(__imp__sub_827AA308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r10,9000
	ctx.r3.s64 = ctx.r10.s64 + 9000;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82293e30
	sub_82293E30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA31C"))) PPC_WEAK_FUNC(sub_827AA31C);
PPC_FUNC_IMPL(__imp__sub_827AA31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA320"))) PPC_WEAK_FUNC(sub_827AA320);
PPC_FUNC_IMPL(__imp__sub_827AA320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,836
	ctx.r5.s64 = r11.s64 + 836;
	// addi r3,r10,9028
	ctx.r3.s64 = ctx.r10.s64 + 9028;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA33C"))) PPC_WEAK_FUNC(sub_827AA33C);
PPC_FUNC_IMPL(__imp__sub_827AA33C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA340"))) PPC_WEAK_FUNC(sub_827AA340);
PPC_FUNC_IMPL(__imp__sub_827AA340) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,860
	ctx.r5.s64 = r11.s64 + 860;
	// addi r3,r10,8980
	ctx.r3.s64 = ctx.r10.s64 + 8980;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA35C"))) PPC_WEAK_FUNC(sub_827AA35C);
PPC_FUNC_IMPL(__imp__sub_827AA35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA360"))) PPC_WEAK_FUNC(sub_827AA360);
PPC_FUNC_IMPL(__imp__sub_827AA360) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,888
	ctx.r5.s64 = r11.s64 + 888;
	// addi r3,r10,9048
	ctx.r3.s64 = ctx.r10.s64 + 9048;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA37C"))) PPC_WEAK_FUNC(sub_827AA37C);
PPC_FUNC_IMPL(__imp__sub_827AA37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA380"))) PPC_WEAK_FUNC(sub_827AA380);
PPC_FUNC_IMPL(__imp__sub_827AA380) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,908
	ctx.r5.s64 = r11.s64 + 908;
	// addi r3,r10,9008
	ctx.r3.s64 = ctx.r10.s64 + 9008;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA39C"))) PPC_WEAK_FUNC(sub_827AA39C);
PPC_FUNC_IMPL(__imp__sub_827AA39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA3A0"))) PPC_WEAK_FUNC(sub_827AA3A0);
PPC_FUNC_IMPL(__imp__sub_827AA3A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,928
	ctx.r5.s64 = r11.s64 + 928;
	// addi r3,r10,8960
	ctx.r3.s64 = ctx.r10.s64 + 8960;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA3BC"))) PPC_WEAK_FUNC(sub_827AA3BC);
PPC_FUNC_IMPL(__imp__sub_827AA3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA3C0"))) PPC_WEAK_FUNC(sub_827AA3C0);
PPC_FUNC_IMPL(__imp__sub_827AA3C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// b 0x82293e18
	sub_82293E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA3CC"))) PPC_WEAK_FUNC(sub_827AA3CC);
PPC_FUNC_IMPL(__imp__sub_827AA3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA3D0"))) PPC_WEAK_FUNC(sub_827AA3D0);
PPC_FUNC_IMPL(__imp__sub_827AA3D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29176
	ctx.r3.s64 = r11.s64 + -29176;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AA3DC"))) PPC_WEAK_FUNC(sub_827AA3DC);
PPC_FUNC_IMPL(__imp__sub_827AA3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AA3E0"))) PPC_WEAK_FUNC(sub_827AA3E0);
PPC_FUNC_IMPL(__imp__sub_827AA3E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,15992
	r30.s64 = r31.s64 + 15992;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11632
	ctx.r5.s64 = ctx.r10.s64 + 11632;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA418;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,15992(r31)
	PPC_STORE_U32(r31.u32 + 15992, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA428;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA430;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11628
	r11.s64 = r11.s64 + 11628;
	// addi r3,r9,-29168
	ctx.r3.s64 = ctx.r9.s64 + -29168;
	// stw r11,15992(r31)
	PPC_STORE_U32(r31.u32 + 15992, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA448;
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

__attribute__((alias("__imp__sub_827AA460"))) PPC_WEAK_FUNC(sub_827AA460);
PPC_FUNC_IMPL(__imp__sub_827AA460) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16088
	r30.s64 = r31.s64 + 16088;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11664
	ctx.r5.s64 = ctx.r10.s64 + 11664;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA498;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16088(r31)
	PPC_STORE_U32(r31.u32 + 16088, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA4A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA4B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11660
	r11.s64 = r11.s64 + 11660;
	// addi r3,r9,-29080
	ctx.r3.s64 = ctx.r9.s64 + -29080;
	// stw r11,16088(r31)
	PPC_STORE_U32(r31.u32 + 16088, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA4C8;
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

__attribute__((alias("__imp__sub_827AA4E0"))) PPC_WEAK_FUNC(sub_827AA4E0);
PPC_FUNC_IMPL(__imp__sub_827AA4E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16376
	r30.s64 = r31.s64 + 16376;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11704
	ctx.r5.s64 = ctx.r10.s64 + 11704;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA518;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16376(r31)
	PPC_STORE_U32(r31.u32 + 16376, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA528;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA530;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11700
	r11.s64 = r11.s64 + 11700;
	// addi r3,r9,-28992
	ctx.r3.s64 = ctx.r9.s64 + -28992;
	// stw r11,16376(r31)
	PPC_STORE_U32(r31.u32 + 16376, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA548;
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

__attribute__((alias("__imp__sub_827AA560"))) PPC_WEAK_FUNC(sub_827AA560);
PPC_FUNC_IMPL(__imp__sub_827AA560) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16664
	r30.s64 = r31.s64 + 16664;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11732
	ctx.r5.s64 = ctx.r10.s64 + 11732;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA598;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16664(r31)
	PPC_STORE_U32(r31.u32 + 16664, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA5A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA5B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11728
	r11.s64 = r11.s64 + 11728;
	// addi r3,r9,-28904
	ctx.r3.s64 = ctx.r9.s64 + -28904;
	// stw r11,16664(r31)
	PPC_STORE_U32(r31.u32 + 16664, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA5C8;
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

__attribute__((alias("__imp__sub_827AA5E0"))) PPC_WEAK_FUNC(sub_827AA5E0);
PPC_FUNC_IMPL(__imp__sub_827AA5E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16312
	r30.s64 = r31.s64 + 16312;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11760
	ctx.r5.s64 = ctx.r10.s64 + 11760;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA618;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16312(r31)
	PPC_STORE_U32(r31.u32 + 16312, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA628;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA630;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11756
	r11.s64 = r11.s64 + 11756;
	// addi r3,r9,-28816
	ctx.r3.s64 = ctx.r9.s64 + -28816;
	// stw r11,16312(r31)
	PPC_STORE_U32(r31.u32 + 16312, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA648;
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

__attribute__((alias("__imp__sub_827AA660"))) PPC_WEAK_FUNC(sub_827AA660);
PPC_FUNC_IMPL(__imp__sub_827AA660) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16536
	r30.s64 = r31.s64 + 16536;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11796
	ctx.r5.s64 = ctx.r10.s64 + 11796;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA698;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16536(r31)
	PPC_STORE_U32(r31.u32 + 16536, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA6A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA6B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11792
	r11.s64 = r11.s64 + 11792;
	// addi r3,r9,-28728
	ctx.r3.s64 = ctx.r9.s64 + -28728;
	// stw r11,16536(r31)
	PPC_STORE_U32(r31.u32 + 16536, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA6C8;
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

__attribute__((alias("__imp__sub_827AA6E0"))) PPC_WEAK_FUNC(sub_827AA6E0);
PPC_FUNC_IMPL(__imp__sub_827AA6E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16600
	r30.s64 = r31.s64 + 16600;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11828
	ctx.r5.s64 = ctx.r10.s64 + 11828;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA718;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16600(r31)
	PPC_STORE_U32(r31.u32 + 16600, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA728;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA730;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11824
	r11.s64 = r11.s64 + 11824;
	// addi r3,r9,-28640
	ctx.r3.s64 = ctx.r9.s64 + -28640;
	// stw r11,16600(r31)
	PPC_STORE_U32(r31.u32 + 16600, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA748;
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

__attribute__((alias("__imp__sub_827AA760"))) PPC_WEAK_FUNC(sub_827AA760);
PPC_FUNC_IMPL(__imp__sub_827AA760) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16152
	r30.s64 = r31.s64 + 16152;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11852
	ctx.r5.s64 = ctx.r10.s64 + 11852;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA798;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16152(r31)
	PPC_STORE_U32(r31.u32 + 16152, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA7A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA7B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11848
	r11.s64 = r11.s64 + 11848;
	// addi r3,r9,-28552
	ctx.r3.s64 = ctx.r9.s64 + -28552;
	// stw r11,16152(r31)
	PPC_STORE_U32(r31.u32 + 16152, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA7C8;
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

__attribute__((alias("__imp__sub_827AA7E0"))) PPC_WEAK_FUNC(sub_827AA7E0);
PPC_FUNC_IMPL(__imp__sub_827AA7E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16408
	r30.s64 = r31.s64 + 16408;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11880
	ctx.r5.s64 = ctx.r10.s64 + 11880;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA818;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16408(r31)
	PPC_STORE_U32(r31.u32 + 16408, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA828;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA830;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11876
	r11.s64 = r11.s64 + 11876;
	// addi r3,r9,-28464
	ctx.r3.s64 = ctx.r9.s64 + -28464;
	// stw r11,16408(r31)
	PPC_STORE_U32(r31.u32 + 16408, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA848;
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

__attribute__((alias("__imp__sub_827AA860"))) PPC_WEAK_FUNC(sub_827AA860);
PPC_FUNC_IMPL(__imp__sub_827AA860) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16280
	r30.s64 = r31.s64 + 16280;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11904
	ctx.r5.s64 = ctx.r10.s64 + 11904;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA898;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16280(r31)
	PPC_STORE_U32(r31.u32 + 16280, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA8A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA8B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11900
	r11.s64 = r11.s64 + 11900;
	// addi r3,r9,-28376
	ctx.r3.s64 = ctx.r9.s64 + -28376;
	// stw r11,16280(r31)
	PPC_STORE_U32(r31.u32 + 16280, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA8C8;
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

__attribute__((alias("__imp__sub_827AA8E0"))) PPC_WEAK_FUNC(sub_827AA8E0);
PPC_FUNC_IMPL(__imp__sub_827AA8E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16568
	r30.s64 = r31.s64 + 16568;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11928
	ctx.r5.s64 = ctx.r10.s64 + 11928;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA918;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16568(r31)
	PPC_STORE_U32(r31.u32 + 16568, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA928;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA930;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11924
	r11.s64 = r11.s64 + 11924;
	// addi r3,r9,-28288
	ctx.r3.s64 = ctx.r9.s64 + -28288;
	// stw r11,16568(r31)
	PPC_STORE_U32(r31.u32 + 16568, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA948;
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

__attribute__((alias("__imp__sub_827AA960"))) PPC_WEAK_FUNC(sub_827AA960);
PPC_FUNC_IMPL(__imp__sub_827AA960) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16216
	r30.s64 = r31.s64 + 16216;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13380
	ctx.r5.s64 = ctx.r10.s64 + -13380;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AA998;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16216(r31)
	PPC_STORE_U32(r31.u32 + 16216, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AA9A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AA9B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11948
	r11.s64 = r11.s64 + 11948;
	// addi r3,r9,-28200
	ctx.r3.s64 = ctx.r9.s64 + -28200;
	// stw r11,16216(r31)
	PPC_STORE_U32(r31.u32 + 16216, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AA9C8;
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

__attribute__((alias("__imp__sub_827AA9E0"))) PPC_WEAK_FUNC(sub_827AA9E0);
PPC_FUNC_IMPL(__imp__sub_827AA9E0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16440
	r30.s64 = r31.s64 + 16440;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13364
	ctx.r5.s64 = ctx.r10.s64 + -13364;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAA18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16440(r31)
	PPC_STORE_U32(r31.u32 + 16440, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAA28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAA30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11956
	r11.s64 = r11.s64 + 11956;
	// addi r3,r9,-28112
	ctx.r3.s64 = ctx.r9.s64 + -28112;
	// stw r11,16440(r31)
	PPC_STORE_U32(r31.u32 + 16440, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAA48;
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

__attribute__((alias("__imp__sub_827AAA60"))) PPC_WEAK_FUNC(sub_827AAA60);
PPC_FUNC_IMPL(__imp__sub_827AAA60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16056
	r30.s64 = r31.s64 + 16056;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13348
	ctx.r5.s64 = ctx.r10.s64 + -13348;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAA98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16056(r31)
	PPC_STORE_U32(r31.u32 + 16056, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAAA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAAB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11964
	r11.s64 = r11.s64 + 11964;
	// addi r3,r9,-28024
	ctx.r3.s64 = ctx.r9.s64 + -28024;
	// stw r11,16056(r31)
	PPC_STORE_U32(r31.u32 + 16056, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAAC8;
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

__attribute__((alias("__imp__sub_827AAAE0"))) PPC_WEAK_FUNC(sub_827AAAE0);
PPC_FUNC_IMPL(__imp__sub_827AAAE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16472
	r30.s64 = r31.s64 + 16472;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13336
	ctx.r5.s64 = ctx.r10.s64 + -13336;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAB18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16472(r31)
	PPC_STORE_U32(r31.u32 + 16472, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAB28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAB30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11972
	r11.s64 = r11.s64 + 11972;
	// addi r3,r9,-27936
	ctx.r3.s64 = ctx.r9.s64 + -27936;
	// stw r11,16472(r31)
	PPC_STORE_U32(r31.u32 + 16472, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAB48;
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

__attribute__((alias("__imp__sub_827AAB60"))) PPC_WEAK_FUNC(sub_827AAB60);
PPC_FUNC_IMPL(__imp__sub_827AAB60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16120
	r30.s64 = r31.s64 + 16120;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,11984
	ctx.r5.s64 = ctx.r10.s64 + 11984;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAB98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16120(r31)
	PPC_STORE_U32(r31.u32 + 16120, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AABA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AABB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,11980
	r11.s64 = r11.s64 + 11980;
	// addi r3,r9,-27848
	ctx.r3.s64 = ctx.r9.s64 + -27848;
	// stw r11,16120(r31)
	PPC_STORE_U32(r31.u32 + 16120, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AABC8;
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

__attribute__((alias("__imp__sub_827AABE0"))) PPC_WEAK_FUNC(sub_827AABE0);
PPC_FUNC_IMPL(__imp__sub_827AABE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16696
	r30.s64 = r31.s64 + 16696;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12016
	ctx.r5.s64 = ctx.r10.s64 + 12016;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAC18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16696(r31)
	PPC_STORE_U32(r31.u32 + 16696, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAC28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAC30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12012
	r11.s64 = r11.s64 + 12012;
	// addi r3,r9,-27760
	ctx.r3.s64 = ctx.r9.s64 + -27760;
	// stw r11,16696(r31)
	PPC_STORE_U32(r31.u32 + 16696, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAC48;
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

__attribute__((alias("__imp__sub_827AAC60"))) PPC_WEAK_FUNC(sub_827AAC60);
PPC_FUNC_IMPL(__imp__sub_827AAC60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16184
	r30.s64 = r31.s64 + 16184;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-13320
	ctx.r5.s64 = ctx.r10.s64 + -13320;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAC98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16184(r31)
	PPC_STORE_U32(r31.u32 + 16184, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AACA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AACB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12048
	r11.s64 = r11.s64 + 12048;
	// addi r3,r9,-27672
	ctx.r3.s64 = ctx.r9.s64 + -27672;
	// stw r11,16184(r31)
	PPC_STORE_U32(r31.u32 + 16184, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AACC8;
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

__attribute__((alias("__imp__sub_827AACE0"))) PPC_WEAK_FUNC(sub_827AACE0);
PPC_FUNC_IMPL(__imp__sub_827AACE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16248
	r30.s64 = r31.s64 + 16248;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12060
	ctx.r5.s64 = ctx.r10.s64 + 12060;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAD18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16248(r31)
	PPC_STORE_U32(r31.u32 + 16248, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAD28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAD30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12056
	r11.s64 = r11.s64 + 12056;
	// addi r3,r9,-27584
	ctx.r3.s64 = ctx.r9.s64 + -27584;
	// stw r11,16248(r31)
	PPC_STORE_U32(r31.u32 + 16248, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAD48;
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

__attribute__((alias("__imp__sub_827AAD60"))) PPC_WEAK_FUNC(sub_827AAD60);
PPC_FUNC_IMPL(__imp__sub_827AAD60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16792
	r30.s64 = r31.s64 + 16792;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12084
	ctx.r5.s64 = ctx.r10.s64 + 12084;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAD98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16792(r31)
	PPC_STORE_U32(r31.u32 + 16792, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AADA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AADB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12080
	r11.s64 = r11.s64 + 12080;
	// addi r3,r9,-27496
	ctx.r3.s64 = ctx.r9.s64 + -27496;
	// stw r11,16792(r31)
	PPC_STORE_U32(r31.u32 + 16792, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AADC8;
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

__attribute__((alias("__imp__sub_827AADE0"))) PPC_WEAK_FUNC(sub_827AADE0);
PPC_FUNC_IMPL(__imp__sub_827AADE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16344
	r30.s64 = r31.s64 + 16344;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12112
	ctx.r5.s64 = ctx.r10.s64 + 12112;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAE18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16344(r31)
	PPC_STORE_U32(r31.u32 + 16344, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAE28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAE30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12108
	r11.s64 = r11.s64 + 12108;
	// addi r3,r9,-27408
	ctx.r3.s64 = ctx.r9.s64 + -27408;
	// stw r11,16344(r31)
	PPC_STORE_U32(r31.u32 + 16344, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAE48;
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

__attribute__((alias("__imp__sub_827AAE60"))) PPC_WEAK_FUNC(sub_827AAE60);
PPC_FUNC_IMPL(__imp__sub_827AAE60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16504
	r30.s64 = r31.s64 + 16504;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12136
	ctx.r5.s64 = ctx.r10.s64 + 12136;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAE98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16504(r31)
	PPC_STORE_U32(r31.u32 + 16504, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAEA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAEB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12132
	r11.s64 = r11.s64 + 12132;
	// addi r3,r9,-27320
	ctx.r3.s64 = ctx.r9.s64 + -27320;
	// stw r11,16504(r31)
	PPC_STORE_U32(r31.u32 + 16504, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAEC8;
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

__attribute__((alias("__imp__sub_827AAEE0"))) PPC_WEAK_FUNC(sub_827AAEE0);
PPC_FUNC_IMPL(__imp__sub_827AAEE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16024
	r30.s64 = r31.s64 + 16024;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12156
	ctx.r5.s64 = ctx.r10.s64 + 12156;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAF18;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16024(r31)
	PPC_STORE_U32(r31.u32 + 16024, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAF28;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAF30;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12152
	r11.s64 = r11.s64 + 12152;
	// addi r3,r9,-27232
	ctx.r3.s64 = ctx.r9.s64 + -27232;
	// stw r11,16024(r31)
	PPC_STORE_U32(r31.u32 + 16024, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAF48;
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

__attribute__((alias("__imp__sub_827AAF60"))) PPC_WEAK_FUNC(sub_827AAF60);
PPC_FUNC_IMPL(__imp__sub_827AAF60) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16760
	r30.s64 = r31.s64 + 16760;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12176
	ctx.r5.s64 = ctx.r10.s64 + 12176;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AAF98;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16760(r31)
	PPC_STORE_U32(r31.u32 + 16760, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AAFA8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AAFB0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12172
	r11.s64 = r11.s64 + 12172;
	// addi r3,r9,-27144
	ctx.r3.s64 = ctx.r9.s64 + -27144;
	// stw r11,16760(r31)
	PPC_STORE_U32(r31.u32 + 16760, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AAFC8;
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

__attribute__((alias("__imp__sub_827AAFE0"))) PPC_WEAK_FUNC(sub_827AAFE0);
PPC_FUNC_IMPL(__imp__sub_827AAFE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16728
	r30.s64 = r31.s64 + 16728;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12192
	ctx.r5.s64 = ctx.r10.s64 + 12192;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB018;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16728(r31)
	PPC_STORE_U32(r31.u32 + 16728, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB028;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB030;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12188
	r11.s64 = r11.s64 + 12188;
	// addi r3,r9,-27056
	ctx.r3.s64 = ctx.r9.s64 + -27056;
	// stw r11,16728(r31)
	PPC_STORE_U32(r31.u32 + 16728, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB048;
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

__attribute__((alias("__imp__sub_827AB060"))) PPC_WEAK_FUNC(sub_827AB060);
PPC_FUNC_IMPL(__imp__sub_827AB060) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16632
	r30.s64 = r31.s64 + 16632;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,12212
	ctx.r5.s64 = ctx.r10.s64 + 12212;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB098;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16632(r31)
	PPC_STORE_U32(r31.u32 + 16632, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB0A8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB0B0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,12208
	r11.s64 = r11.s64 + 12208;
	// addi r3,r9,-26968
	ctx.r3.s64 = ctx.r9.s64 + -26968;
	// stw r11,16632(r31)
	PPC_STORE_U32(r31.u32 + 16632, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB0C8;
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

__attribute__((alias("__imp__sub_827AB0E0"))) PPC_WEAK_FUNC(sub_827AB0E0);
PPC_FUNC_IMPL(__imp__sub_827AB0E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4760
	ctx.r7.s64 = ctx.r8.s64 + -4760;
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

__attribute__((alias("__imp__sub_827AB100"))) PPC_WEAK_FUNC(sub_827AB100);
PPC_FUNC_IMPL(__imp__sub_827AB100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4752
	ctx.r7.s64 = ctx.r8.s64 + -4752;
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

__attribute__((alias("__imp__sub_827AB120"))) PPC_WEAK_FUNC(sub_827AB120);
PPC_FUNC_IMPL(__imp__sub_827AB120) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4744
	ctx.r7.s64 = ctx.r8.s64 + -4744;
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

__attribute__((alias("__imp__sub_827AB140"))) PPC_WEAK_FUNC(sub_827AB140);
PPC_FUNC_IMPL(__imp__sub_827AB140) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4736
	ctx.r7.s64 = ctx.r8.s64 + -4736;
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

__attribute__((alias("__imp__sub_827AB160"))) PPC_WEAK_FUNC(sub_827AB160);
PPC_FUNC_IMPL(__imp__sub_827AB160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-4728
	ctx.r7.s64 = ctx.r8.s64 + -4728;
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

__attribute__((alias("__imp__sub_827AB180"))) PPC_WEAK_FUNC(sub_827AB180);
PPC_FUNC_IMPL(__imp__sub_827AB180) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16844
	r30.s64 = r31.s64 + 16844;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,14260
	ctx.r5.s64 = ctx.r10.s64 + 14260;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB1B8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16844(r31)
	PPC_STORE_U32(r31.u32 + 16844, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB1C8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB1D0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,14256
	r11.s64 = r11.s64 + 14256;
	// addi r3,r9,-26880
	ctx.r3.s64 = ctx.r9.s64 + -26880;
	// stw r11,16844(r31)
	PPC_STORE_U32(r31.u32 + 16844, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB1E8;
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

__attribute__((alias("__imp__sub_827AB200"))) PPC_WEAK_FUNC(sub_827AB200);
PPC_FUNC_IMPL(__imp__sub_827AB200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,16376
	ctx.r5.s64 = r11.s64 + 16376;
	// addi r3,r10,16876
	ctx.r3.s64 = ctx.r10.s64 + 16876;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB21C"))) PPC_WEAK_FUNC(sub_827AB21C);
PPC_FUNC_IMPL(__imp__sub_827AB21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB220"))) PPC_WEAK_FUNC(sub_827AB220);
PPC_FUNC_IMPL(__imp__sub_827AB220) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16896
	r30.s64 = r31.s64 + 16896;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,16360
	ctx.r5.s64 = ctx.r10.s64 + 16360;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB258;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16896(r31)
	PPC_STORE_U32(r31.u32 + 16896, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB268;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB270;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,16356
	r11.s64 = r11.s64 + 16356;
	// addi r3,r9,-26792
	ctx.r3.s64 = ctx.r9.s64 + -26792;
	// stw r11,16896(r31)
	PPC_STORE_U32(r31.u32 + 16896, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB288;
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

__attribute__((alias("__imp__sub_827AB2A0"))) PPC_WEAK_FUNC(sub_827AB2A0);
PPC_FUNC_IMPL(__imp__sub_827AB2A0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16928
	r30.s64 = r31.s64 + 16928;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17264
	ctx.r5.s64 = ctx.r10.s64 + 17264;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB2D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16928(r31)
	PPC_STORE_U32(r31.u32 + 16928, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB2E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB2F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17260
	r11.s64 = r11.s64 + 17260;
	// addi r3,r9,-26704
	ctx.r3.s64 = ctx.r9.s64 + -26704;
	// stw r11,16928(r31)
	PPC_STORE_U32(r31.u32 + 16928, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB308;
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

__attribute__((alias("__imp__sub_827AB320"))) PPC_WEAK_FUNC(sub_827AB320);
PPC_FUNC_IMPL(__imp__sub_827AB320) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16960
	r30.s64 = r31.s64 + 16960;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17296
	ctx.r5.s64 = ctx.r10.s64 + 17296;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB358;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16960(r31)
	PPC_STORE_U32(r31.u32 + 16960, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB368;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB370;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17292
	r11.s64 = r11.s64 + 17292;
	// addi r3,r9,-26616
	ctx.r3.s64 = ctx.r9.s64 + -26616;
	// stw r11,16960(r31)
	PPC_STORE_U32(r31.u32 + 16960, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB388;
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

__attribute__((alias("__imp__sub_827AB3A0"))) PPC_WEAK_FUNC(sub_827AB3A0);
PPC_FUNC_IMPL(__imp__sub_827AB3A0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,17024
	r30.s64 = r31.s64 + 17024;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17632
	ctx.r5.s64 = ctx.r10.s64 + 17632;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB3D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,17024(r31)
	PPC_STORE_U32(r31.u32 + 17024, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB3E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB3F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17628
	r11.s64 = r11.s64 + 17628;
	// addi r3,r9,-26528
	ctx.r3.s64 = ctx.r9.s64 + -26528;
	// stw r11,17024(r31)
	PPC_STORE_U32(r31.u32 + 17024, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB408;
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

__attribute__((alias("__imp__sub_827AB420"))) PPC_WEAK_FUNC(sub_827AB420);
PPC_FUNC_IMPL(__imp__sub_827AB420) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,16992
	r30.s64 = r31.s64 + 16992;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17680
	ctx.r5.s64 = ctx.r10.s64 + 17680;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB458;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16992(r31)
	PPC_STORE_U32(r31.u32 + 16992, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB468;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB470;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17676
	r11.s64 = r11.s64 + 17676;
	// addi r3,r9,-26440
	ctx.r3.s64 = ctx.r9.s64 + -26440;
	// stw r11,16992(r31)
	PPC_STORE_U32(r31.u32 + 16992, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB488;
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

__attribute__((alias("__imp__sub_827AB4A0"))) PPC_WEAK_FUNC(sub_827AB4A0);
PPC_FUNC_IMPL(__imp__sub_827AB4A0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,17056
	r30.s64 = r31.s64 + 17056;
	// addi r6,r11,32428
	ctx.r6.s64 = r11.s64 + 32428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,17724
	ctx.r5.s64 = ctx.r10.s64 + 17724;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824fa650
	ctx.lr = 0x827AB4D8;
	sub_824FA650(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,17056(r31)
	PPC_STORE_U32(r31.u32 + 17056, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827AB4E8;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa6c0
	ctx.lr = 0x827AB4F0;
	sub_824FA6C0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r11,r11,17720
	r11.s64 = r11.s64 + 17720;
	// addi r3,r9,-26352
	ctx.r3.s64 = ctx.r9.s64 + -26352;
	// stw r11,17056(r31)
	PPC_STORE_U32(r31.u32 + 17056, r11.u32);
	// bl 0x823d9a98
	ctx.lr = 0x827AB508;
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

__attribute__((alias("__imp__sub_827AB520"))) PPC_WEAK_FUNC(sub_827AB520);
PPC_FUNC_IMPL(__imp__sub_827AB520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,19860
	ctx.r5.s64 = r11.s64 + 19860;
	// addi r3,r10,17124
	ctx.r3.s64 = ctx.r10.s64 + 17124;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB53C"))) PPC_WEAK_FUNC(sub_827AB53C);
PPC_FUNC_IMPL(__imp__sub_827AB53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB540"))) PPC_WEAK_FUNC(sub_827AB540);
PPC_FUNC_IMPL(__imp__sub_827AB540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,21608
	ctx.r5.s64 = r11.s64 + 21608;
	// addi r3,r10,17236
	ctx.r3.s64 = ctx.r10.s64 + 17236;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB55C"))) PPC_WEAK_FUNC(sub_827AB55C);
PPC_FUNC_IMPL(__imp__sub_827AB55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB560"))) PPC_WEAK_FUNC(sub_827AB560);
PPC_FUNC_IMPL(__imp__sub_827AB560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,21620
	ctx.r5.s64 = r11.s64 + 21620;
	// addi r3,r10,17216
	ctx.r3.s64 = ctx.r10.s64 + 17216;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB57C"))) PPC_WEAK_FUNC(sub_827AB57C);
PPC_FUNC_IMPL(__imp__sub_827AB57C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB580"))) PPC_WEAK_FUNC(sub_827AB580);
PPC_FUNC_IMPL(__imp__sub_827AB580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,21636
	ctx.r5.s64 = r11.s64 + 21636;
	// addi r3,r10,17196
	ctx.r3.s64 = ctx.r10.s64 + 17196;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB59C"))) PPC_WEAK_FUNC(sub_827AB59C);
PPC_FUNC_IMPL(__imp__sub_827AB59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB5A0"))) PPC_WEAK_FUNC(sub_827AB5A0);
PPC_FUNC_IMPL(__imp__sub_827AB5A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,22088
	ctx.r5.s64 = r11.s64 + 22088;
	// addi r3,r10,17272
	ctx.r3.s64 = ctx.r10.s64 + 17272;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB5BC"))) PPC_WEAK_FUNC(sub_827AB5BC);
PPC_FUNC_IMPL(__imp__sub_827AB5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB5C0"))) PPC_WEAK_FUNC(sub_827AB5C0);
PPC_FUNC_IMPL(__imp__sub_827AB5C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,22416
	ctx.r5.s64 = r11.s64 + 22416;
	// addi r3,r10,17300
	ctx.r3.s64 = ctx.r10.s64 + 17300;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB5DC"))) PPC_WEAK_FUNC(sub_827AB5DC);
PPC_FUNC_IMPL(__imp__sub_827AB5DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB5E0"))) PPC_WEAK_FUNC(sub_827AB5E0);
PPC_FUNC_IMPL(__imp__sub_827AB5E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23504
	ctx.r5.s64 = r11.s64 + 23504;
	// addi r3,r10,17392
	ctx.r3.s64 = ctx.r10.s64 + 17392;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB5FC"))) PPC_WEAK_FUNC(sub_827AB5FC);
PPC_FUNC_IMPL(__imp__sub_827AB5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB600"))) PPC_WEAK_FUNC(sub_827AB600);
PPC_FUNC_IMPL(__imp__sub_827AB600) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23516
	ctx.r5.s64 = r11.s64 + 23516;
	// addi r3,r10,17352
	ctx.r3.s64 = ctx.r10.s64 + 17352;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB61C"))) PPC_WEAK_FUNC(sub_827AB61C);
PPC_FUNC_IMPL(__imp__sub_827AB61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB620"))) PPC_WEAK_FUNC(sub_827AB620);
PPC_FUNC_IMPL(__imp__sub_827AB620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23528
	ctx.r5.s64 = r11.s64 + 23528;
	// addi r3,r10,17372
	ctx.r3.s64 = ctx.r10.s64 + 17372;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB63C"))) PPC_WEAK_FUNC(sub_827AB63C);
PPC_FUNC_IMPL(__imp__sub_827AB63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB640"))) PPC_WEAK_FUNC(sub_827AB640);
PPC_FUNC_IMPL(__imp__sub_827AB640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23540
	ctx.r5.s64 = r11.s64 + 23540;
	// addi r3,r10,17412
	ctx.r3.s64 = ctx.r10.s64 + 17412;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB65C"))) PPC_WEAK_FUNC(sub_827AB65C);
PPC_FUNC_IMPL(__imp__sub_827AB65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB660"))) PPC_WEAK_FUNC(sub_827AB660);
PPC_FUNC_IMPL(__imp__sub_827AB660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,23552
	ctx.r5.s64 = r11.s64 + 23552;
	// addi r3,r10,17332
	ctx.r3.s64 = ctx.r10.s64 + 17332;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB67C"))) PPC_WEAK_FUNC(sub_827AB67C);
PPC_FUNC_IMPL(__imp__sub_827AB67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB680"))) PPC_WEAK_FUNC(sub_827AB680);
PPC_FUNC_IMPL(__imp__sub_827AB680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29248
	ctx.r5.s64 = r11.s64 + 29248;
	// addi r3,r10,17708
	ctx.r3.s64 = ctx.r10.s64 + 17708;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB69C"))) PPC_WEAK_FUNC(sub_827AB69C);
PPC_FUNC_IMPL(__imp__sub_827AB69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB6A0"))) PPC_WEAK_FUNC(sub_827AB6A0);
PPC_FUNC_IMPL(__imp__sub_827AB6A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29264
	ctx.r5.s64 = r11.s64 + 29264;
	// addi r3,r10,17492
	ctx.r3.s64 = ctx.r10.s64 + 17492;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB6BC"))) PPC_WEAK_FUNC(sub_827AB6BC);
PPC_FUNC_IMPL(__imp__sub_827AB6BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB6C0"))) PPC_WEAK_FUNC(sub_827AB6C0);
PPC_FUNC_IMPL(__imp__sub_827AB6C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29288
	ctx.r5.s64 = r11.s64 + 29288;
	// addi r3,r10,17572
	ctx.r3.s64 = ctx.r10.s64 + 17572;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB6DC"))) PPC_WEAK_FUNC(sub_827AB6DC);
PPC_FUNC_IMPL(__imp__sub_827AB6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB6E0"))) PPC_WEAK_FUNC(sub_827AB6E0);
PPC_FUNC_IMPL(__imp__sub_827AB6E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29300
	ctx.r5.s64 = r11.s64 + 29300;
	// addi r3,r10,17452
	ctx.r3.s64 = ctx.r10.s64 + 17452;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB6FC"))) PPC_WEAK_FUNC(sub_827AB6FC);
PPC_FUNC_IMPL(__imp__sub_827AB6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB700"))) PPC_WEAK_FUNC(sub_827AB700);
PPC_FUNC_IMPL(__imp__sub_827AB700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29324
	ctx.r5.s64 = r11.s64 + 29324;
	// addi r3,r10,17628
	ctx.r3.s64 = ctx.r10.s64 + 17628;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB71C"))) PPC_WEAK_FUNC(sub_827AB71C);
PPC_FUNC_IMPL(__imp__sub_827AB71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB720"))) PPC_WEAK_FUNC(sub_827AB720);
PPC_FUNC_IMPL(__imp__sub_827AB720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29340
	ctx.r5.s64 = r11.s64 + 29340;
	// addi r3,r10,17512
	ctx.r3.s64 = ctx.r10.s64 + 17512;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB73C"))) PPC_WEAK_FUNC(sub_827AB73C);
PPC_FUNC_IMPL(__imp__sub_827AB73C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB740"))) PPC_WEAK_FUNC(sub_827AB740);
PPC_FUNC_IMPL(__imp__sub_827AB740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29356
	ctx.r5.s64 = r11.s64 + 29356;
	// addi r3,r10,17688
	ctx.r3.s64 = ctx.r10.s64 + 17688;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB75C"))) PPC_WEAK_FUNC(sub_827AB75C);
PPC_FUNC_IMPL(__imp__sub_827AB75C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB760"))) PPC_WEAK_FUNC(sub_827AB760);
PPC_FUNC_IMPL(__imp__sub_827AB760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29372
	ctx.r5.s64 = r11.s64 + 29372;
	// addi r3,r10,17648
	ctx.r3.s64 = ctx.r10.s64 + 17648;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB77C"))) PPC_WEAK_FUNC(sub_827AB77C);
PPC_FUNC_IMPL(__imp__sub_827AB77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB780"))) PPC_WEAK_FUNC(sub_827AB780);
PPC_FUNC_IMPL(__imp__sub_827AB780) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29388
	ctx.r5.s64 = r11.s64 + 29388;
	// addi r3,r10,17472
	ctx.r3.s64 = ctx.r10.s64 + 17472;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB79C"))) PPC_WEAK_FUNC(sub_827AB79C);
PPC_FUNC_IMPL(__imp__sub_827AB79C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB7A0"))) PPC_WEAK_FUNC(sub_827AB7A0);
PPC_FUNC_IMPL(__imp__sub_827AB7A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29404
	ctx.r5.s64 = r11.s64 + 29404;
	// addi r3,r10,17668
	ctx.r3.s64 = ctx.r10.s64 + 17668;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB7BC"))) PPC_WEAK_FUNC(sub_827AB7BC);
PPC_FUNC_IMPL(__imp__sub_827AB7BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB7C0"))) PPC_WEAK_FUNC(sub_827AB7C0);
PPC_FUNC_IMPL(__imp__sub_827AB7C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29420
	ctx.r5.s64 = r11.s64 + 29420;
	// addi r3,r10,17728
	ctx.r3.s64 = ctx.r10.s64 + 17728;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB7DC"))) PPC_WEAK_FUNC(sub_827AB7DC);
PPC_FUNC_IMPL(__imp__sub_827AB7DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB7E0"))) PPC_WEAK_FUNC(sub_827AB7E0);
PPC_FUNC_IMPL(__imp__sub_827AB7E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29436
	ctx.r5.s64 = r11.s64 + 29436;
	// addi r3,r10,17532
	ctx.r3.s64 = ctx.r10.s64 + 17532;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB7FC"))) PPC_WEAK_FUNC(sub_827AB7FC);
PPC_FUNC_IMPL(__imp__sub_827AB7FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB800"))) PPC_WEAK_FUNC(sub_827AB800);
PPC_FUNC_IMPL(__imp__sub_827AB800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29452
	ctx.r5.s64 = r11.s64 + 29452;
	// addi r3,r10,17552
	ctx.r3.s64 = ctx.r10.s64 + 17552;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB81C"))) PPC_WEAK_FUNC(sub_827AB81C);
PPC_FUNC_IMPL(__imp__sub_827AB81C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB820"))) PPC_WEAK_FUNC(sub_827AB820);
PPC_FUNC_IMPL(__imp__sub_827AB820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,29468
	ctx.r5.s64 = r11.s64 + 29468;
	// addi r3,r10,17748
	ctx.r3.s64 = ctx.r10.s64 + 17748;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB83C"))) PPC_WEAK_FUNC(sub_827AB83C);
PPC_FUNC_IMPL(__imp__sub_827AB83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB840"))) PPC_WEAK_FUNC(sub_827AB840);
PPC_FUNC_IMPL(__imp__sub_827AB840) {
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
	// addi r3,r11,17592
	ctx.r3.s64 = r11.s64 + 17592;
	// bl 0x822eba70
	ctx.lr = 0x827AB858;
	sub_822EBA70(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-26224
	ctx.r3.s64 = ctx.r10.s64 + -26224;
	// bl 0x823d9a98
	ctx.lr = 0x827AB864;
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

__attribute__((alias("__imp__sub_827AB874"))) PPC_WEAK_FUNC(sub_827AB874);
PPC_FUNC_IMPL(__imp__sub_827AB874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB878"))) PPC_WEAK_FUNC(sub_827AB878);
PPC_FUNC_IMPL(__imp__sub_827AB878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,30140
	ctx.r5.s64 = r11.s64 + 30140;
	// addi r3,r10,17780
	ctx.r3.s64 = ctx.r10.s64 + 17780;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB894"))) PPC_WEAK_FUNC(sub_827AB894);
PPC_FUNC_IMPL(__imp__sub_827AB894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB898"))) PPC_WEAK_FUNC(sub_827AB898);
PPC_FUNC_IMPL(__imp__sub_827AB898) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,30156
	ctx.r5.s64 = r11.s64 + 30156;
	// addi r3,r10,17820
	ctx.r3.s64 = ctx.r10.s64 + 17820;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB8B4"))) PPC_WEAK_FUNC(sub_827AB8B4);
PPC_FUNC_IMPL(__imp__sub_827AB8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB8B8"))) PPC_WEAK_FUNC(sub_827AB8B8);
PPC_FUNC_IMPL(__imp__sub_827AB8B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,30168
	ctx.r5.s64 = r11.s64 + 30168;
	// addi r3,r10,17800
	ctx.r3.s64 = ctx.r10.s64 + 17800;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB8D4"))) PPC_WEAK_FUNC(sub_827AB8D4);
PPC_FUNC_IMPL(__imp__sub_827AB8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB8D8"))) PPC_WEAK_FUNC(sub_827AB8D8);
PPC_FUNC_IMPL(__imp__sub_827AB8D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,30188
	ctx.r5.s64 = r11.s64 + 30188;
	// addi r3,r10,17860
	ctx.r3.s64 = ctx.r10.s64 + 17860;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB8F4"))) PPC_WEAK_FUNC(sub_827AB8F4);
PPC_FUNC_IMPL(__imp__sub_827AB8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB8F8"))) PPC_WEAK_FUNC(sub_827AB8F8);
PPC_FUNC_IMPL(__imp__sub_827AB8F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,30204
	ctx.r5.s64 = r11.s64 + 30204;
	// addi r3,r10,17840
	ctx.r3.s64 = ctx.r10.s64 + 17840;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB914"))) PPC_WEAK_FUNC(sub_827AB914);
PPC_FUNC_IMPL(__imp__sub_827AB914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB918"))) PPC_WEAK_FUNC(sub_827AB918);
PPC_FUNC_IMPL(__imp__sub_827AB918) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,31156
	ctx.r5.s64 = r11.s64 + 31156;
	// addi r3,r10,17896
	ctx.r3.s64 = ctx.r10.s64 + 17896;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB934"))) PPC_WEAK_FUNC(sub_827AB934);
PPC_FUNC_IMPL(__imp__sub_827AB934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB938"))) PPC_WEAK_FUNC(sub_827AB938);
PPC_FUNC_IMPL(__imp__sub_827AB938) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,644
	ctx.r7.s64 = ctx.r8.s64 + 644;
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

__attribute__((alias("__imp__sub_827AB958"))) PPC_WEAK_FUNC(sub_827AB958);
PPC_FUNC_IMPL(__imp__sub_827AB958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-32076
	ctx.r5.s64 = r11.s64 + -32076;
	// addi r3,r10,18000
	ctx.r3.s64 = ctx.r10.s64 + 18000;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB974"))) PPC_WEAK_FUNC(sub_827AB974);
PPC_FUNC_IMPL(__imp__sub_827AB974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB978"))) PPC_WEAK_FUNC(sub_827AB978);
PPC_FUNC_IMPL(__imp__sub_827AB978) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-32056
	ctx.r5.s64 = r11.s64 + -32056;
	// addi r3,r10,17980
	ctx.r3.s64 = ctx.r10.s64 + 17980;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB994"))) PPC_WEAK_FUNC(sub_827AB994);
PPC_FUNC_IMPL(__imp__sub_827AB994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB998"))) PPC_WEAK_FUNC(sub_827AB998);
PPC_FUNC_IMPL(__imp__sub_827AB998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-32036
	ctx.r5.s64 = r11.s64 + -32036;
	// addi r3,r10,17920
	ctx.r3.s64 = ctx.r10.s64 + 17920;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB9B4"))) PPC_WEAK_FUNC(sub_827AB9B4);
PPC_FUNC_IMPL(__imp__sub_827AB9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB9B8"))) PPC_WEAK_FUNC(sub_827AB9B8);
PPC_FUNC_IMPL(__imp__sub_827AB9B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-32016
	ctx.r5.s64 = r11.s64 + -32016;
	// addi r3,r10,17960
	ctx.r3.s64 = ctx.r10.s64 + 17960;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB9D4"))) PPC_WEAK_FUNC(sub_827AB9D4);
PPC_FUNC_IMPL(__imp__sub_827AB9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB9D8"))) PPC_WEAK_FUNC(sub_827AB9D8);
PPC_FUNC_IMPL(__imp__sub_827AB9D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-31996
	ctx.r5.s64 = r11.s64 + -31996;
	// addi r3,r10,17940
	ctx.r3.s64 = ctx.r10.s64 + 17940;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AB9F4"))) PPC_WEAK_FUNC(sub_827AB9F4);
PPC_FUNC_IMPL(__imp__sub_827AB9F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AB9F8"))) PPC_WEAK_FUNC(sub_827AB9F8);
PPC_FUNC_IMPL(__imp__sub_827AB9F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-31976
	ctx.r5.s64 = r11.s64 + -31976;
	// addi r3,r10,18020
	ctx.r3.s64 = ctx.r10.s64 + 18020;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABA14"))) PPC_WEAK_FUNC(sub_827ABA14);
PPC_FUNC_IMPL(__imp__sub_827ABA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABA18"))) PPC_WEAK_FUNC(sub_827ABA18);
PPC_FUNC_IMPL(__imp__sub_827ABA18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29200
	ctx.r5.s64 = r11.s64 + -29200;
	// addi r3,r10,18080
	ctx.r3.s64 = ctx.r10.s64 + 18080;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABA34"))) PPC_WEAK_FUNC(sub_827ABA34);
PPC_FUNC_IMPL(__imp__sub_827ABA34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABA38"))) PPC_WEAK_FUNC(sub_827ABA38);
PPC_FUNC_IMPL(__imp__sub_827ABA38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29188
	ctx.r5.s64 = r11.s64 + -29188;
	// addi r3,r10,18192
	ctx.r3.s64 = ctx.r10.s64 + 18192;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABA54"))) PPC_WEAK_FUNC(sub_827ABA54);
PPC_FUNC_IMPL(__imp__sub_827ABA54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABA58"))) PPC_WEAK_FUNC(sub_827ABA58);
PPC_FUNC_IMPL(__imp__sub_827ABA58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29172
	ctx.r5.s64 = r11.s64 + -29172;
	// addi r3,r10,18212
	ctx.r3.s64 = ctx.r10.s64 + 18212;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABA74"))) PPC_WEAK_FUNC(sub_827ABA74);
PPC_FUNC_IMPL(__imp__sub_827ABA74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABA78"))) PPC_WEAK_FUNC(sub_827ABA78);
PPC_FUNC_IMPL(__imp__sub_827ABA78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29156
	ctx.r5.s64 = r11.s64 + -29156;
	// addi r3,r10,18160
	ctx.r3.s64 = ctx.r10.s64 + 18160;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABA94"))) PPC_WEAK_FUNC(sub_827ABA94);
PPC_FUNC_IMPL(__imp__sub_827ABA94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABA98"))) PPC_WEAK_FUNC(sub_827ABA98);
PPC_FUNC_IMPL(__imp__sub_827ABA98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29144
	ctx.r5.s64 = r11.s64 + -29144;
	// addi r3,r10,18100
	ctx.r3.s64 = ctx.r10.s64 + 18100;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABAB4"))) PPC_WEAK_FUNC(sub_827ABAB4);
PPC_FUNC_IMPL(__imp__sub_827ABAB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABAB8"))) PPC_WEAK_FUNC(sub_827ABAB8);
PPC_FUNC_IMPL(__imp__sub_827ABAB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29128
	ctx.r5.s64 = r11.s64 + -29128;
	// addi r3,r10,18232
	ctx.r3.s64 = ctx.r10.s64 + 18232;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABAD4"))) PPC_WEAK_FUNC(sub_827ABAD4);
PPC_FUNC_IMPL(__imp__sub_827ABAD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABAD8"))) PPC_WEAK_FUNC(sub_827ABAD8);
PPC_FUNC_IMPL(__imp__sub_827ABAD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29112
	ctx.r5.s64 = r11.s64 + -29112;
	// addi r3,r10,18120
	ctx.r3.s64 = ctx.r10.s64 + 18120;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABAF4"))) PPC_WEAK_FUNC(sub_827ABAF4);
PPC_FUNC_IMPL(__imp__sub_827ABAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABAF8"))) PPC_WEAK_FUNC(sub_827ABAF8);
PPC_FUNC_IMPL(__imp__sub_827ABAF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29096
	ctx.r5.s64 = r11.s64 + -29096;
	// addi r3,r10,18040
	ctx.r3.s64 = ctx.r10.s64 + 18040;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABB14"))) PPC_WEAK_FUNC(sub_827ABB14);
PPC_FUNC_IMPL(__imp__sub_827ABB14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABB18"))) PPC_WEAK_FUNC(sub_827ABB18);
PPC_FUNC_IMPL(__imp__sub_827ABB18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29076
	ctx.r5.s64 = r11.s64 + -29076;
	// addi r3,r10,18140
	ctx.r3.s64 = ctx.r10.s64 + 18140;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABB34"))) PPC_WEAK_FUNC(sub_827ABB34);
PPC_FUNC_IMPL(__imp__sub_827ABB34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABB38"))) PPC_WEAK_FUNC(sub_827ABB38);
PPC_FUNC_IMPL(__imp__sub_827ABB38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-29060
	ctx.r5.s64 = r11.s64 + -29060;
	// addi r3,r10,18060
	ctx.r3.s64 = ctx.r10.s64 + 18060;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABB54"))) PPC_WEAK_FUNC(sub_827ABB54);
PPC_FUNC_IMPL(__imp__sub_827ABB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABB58"))) PPC_WEAK_FUNC(sub_827ABB58);
PPC_FUNC_IMPL(__imp__sub_827ABB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-26208
	ctx.r3.s64 = r11.s64 + -26208;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABB64"))) PPC_WEAK_FUNC(sub_827ABB64);
PPC_FUNC_IMPL(__imp__sub_827ABB64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABB68"))) PPC_WEAK_FUNC(sub_827ABB68);
PPC_FUNC_IMPL(__imp__sub_827ABB68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-28372
	ctx.r5.s64 = r11.s64 + -28372;
	// addi r3,r10,18292
	ctx.r3.s64 = ctx.r10.s64 + 18292;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABB84"))) PPC_WEAK_FUNC(sub_827ABB84);
PPC_FUNC_IMPL(__imp__sub_827ABB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABB88"))) PPC_WEAK_FUNC(sub_827ABB88);
PPC_FUNC_IMPL(__imp__sub_827ABB88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-28360
	ctx.r5.s64 = r11.s64 + -28360;
	// addi r3,r10,18464
	ctx.r3.s64 = ctx.r10.s64 + 18464;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABBA4"))) PPC_WEAK_FUNC(sub_827ABBA4);
PPC_FUNC_IMPL(__imp__sub_827ABBA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABBA8"))) PPC_WEAK_FUNC(sub_827ABBA8);
PPC_FUNC_IMPL(__imp__sub_827ABBA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-28352
	ctx.r5.s64 = r11.s64 + -28352;
	// addi r3,r10,18272
	ctx.r3.s64 = ctx.r10.s64 + 18272;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABBC4"))) PPC_WEAK_FUNC(sub_827ABBC4);
PPC_FUNC_IMPL(__imp__sub_827ABBC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABBC8"))) PPC_WEAK_FUNC(sub_827ABBC8);
PPC_FUNC_IMPL(__imp__sub_827ABBC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-28344
	ctx.r5.s64 = r11.s64 + -28344;
	// addi r3,r10,18484
	ctx.r3.s64 = ctx.r10.s64 + 18484;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABBE4"))) PPC_WEAK_FUNC(sub_827ABBE4);
PPC_FUNC_IMPL(__imp__sub_827ABBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABBE8"))) PPC_WEAK_FUNC(sub_827ABBE8);
PPC_FUNC_IMPL(__imp__sub_827ABBE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-28332
	ctx.r5.s64 = r11.s64 + -28332;
	// addi r3,r10,18424
	ctx.r3.s64 = ctx.r10.s64 + 18424;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827ABC04"))) PPC_WEAK_FUNC(sub_827ABC04);
PPC_FUNC_IMPL(__imp__sub_827ABC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827ABC08"))) PPC_WEAK_FUNC(sub_827ABC08);
PPC_FUNC_IMPL(__imp__sub_827ABC08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r11,-28324
	ctx.r5.s64 = r11.s64 + -28324;
	// addi r3,r10,18332
	ctx.r3.s64 = ctx.r10.s64 + 18332;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

