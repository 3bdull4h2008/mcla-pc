#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827B89B8"))) PPC_WEAK_FUNC(sub_827B89B8);
PPC_FUNC_IMPL(__imp__sub_827B89B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r3,r11,25648
	ctx.r3.s64 = r11.s64 + 25648;
	// b 0x82199450
	sub_82199450(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B89C4"))) PPC_WEAK_FUNC(sub_827B89C4);
PPC_FUNC_IMPL(__imp__sub_827B89C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B89C8"))) PPC_WEAK_FUNC(sub_827B89C8);
PPC_FUNC_IMPL(__imp__sub_827B89C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-11804
	ctx.r3.s64 = r11.s64 + -11804;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B89D4"))) PPC_WEAK_FUNC(sub_827B89D4);
PPC_FUNC_IMPL(__imp__sub_827B89D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B89D8"))) PPC_WEAK_FUNC(sub_827B89D8);
PPC_FUNC_IMPL(__imp__sub_827B89D8) {
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
	// lis r11,-32123
	r11.s64 = -2105212928;
	// li r30,1
	r30.s64 = 1;
	// addi r10,r11,-27368
	ctx.r10.s64 = r11.s64 + -27368;
	// addis r11,r10,1
	r11.s64 = ctx.r10.s64 + 65536;
	// addi r31,r11,9256
	r31.s64 = r11.s64 + 9256;
loc_827B8A00:
	// addi r31,r31,-24948
	r31.s64 = r31.s64 + -24948;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x821c9158
	ctx.lr = 0x827B8A0C;
	sub_821C9158(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x827B8A14;
	sub_82130000(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b8a00
	if (!cr0.lt) goto loc_827B8A00;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8A34"))) PPC_WEAK_FUNC(sub_827B8A34);
PPC_FUNC_IMPL(__imp__sub_827B8A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8A38"))) PPC_WEAK_FUNC(sub_827B8A38);
PPC_FUNC_IMPL(__imp__sub_827B8A38) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r30,1
	r30.s64 = 1;
	// addi r10,r11,-11752
	ctx.r10.s64 = r11.s64 + -11752;
	// addis r11,r10,1
	r11.s64 = ctx.r10.s64 + 65536;
	// addi r31,r11,9256
	r31.s64 = r11.s64 + 9256;
loc_827B8A60:
	// addi r31,r31,-24948
	r31.s64 = r31.s64 + -24948;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x821c9158
	ctx.lr = 0x827B8A6C;
	sub_821C9158(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x827B8A74;
	sub_82130000(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b8a60
	if (!cr0.lt) goto loc_827B8A60;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8A94"))) PPC_WEAK_FUNC(sub_827B8A94);
PPC_FUNC_IMPL(__imp__sub_827B8A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8A98"))) PPC_WEAK_FUNC(sub_827B8A98);
PPC_FUNC_IMPL(__imp__sub_827B8A98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r11,r11,4388
	r11.s64 = r11.s64 + 4388;
	// stw r11,29952(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29952, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8AAC"))) PPC_WEAK_FUNC(sub_827B8AAC);
PPC_FUNC_IMPL(__imp__sub_827B8AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8AB0"))) PPC_WEAK_FUNC(sub_827B8AB0);
PPC_FUNC_IMPL(__imp__sub_827B8AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r3,r11,22936
	ctx.r3.s64 = r11.s64 + 22936;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8ABC"))) PPC_WEAK_FUNC(sub_827B8ABC);
PPC_FUNC_IMPL(__imp__sub_827B8ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8AC0"))) PPC_WEAK_FUNC(sub_827B8AC0);
PPC_FUNC_IMPL(__imp__sub_827B8AC0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8AC4"))) PPC_WEAK_FUNC(sub_827B8AC4);
PPC_FUNC_IMPL(__imp__sub_827B8AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8AC8"))) PPC_WEAK_FUNC(sub_827B8AC8);
PPC_FUNC_IMPL(__imp__sub_827B8AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r3,r11,23016
	ctx.r3.s64 = r11.s64 + 23016;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8AD4"))) PPC_WEAK_FUNC(sub_827B8AD4);
PPC_FUNC_IMPL(__imp__sub_827B8AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8AD8"))) PPC_WEAK_FUNC(sub_827B8AD8);
PPC_FUNC_IMPL(__imp__sub_827B8AD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r3,r11,23052
	ctx.r3.s64 = r11.s64 + 23052;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8AE4"))) PPC_WEAK_FUNC(sub_827B8AE4);
PPC_FUNC_IMPL(__imp__sub_827B8AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8AE8"))) PPC_WEAK_FUNC(sub_827B8AE8);
PPC_FUNC_IMPL(__imp__sub_827B8AE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r3,r11,24108
	ctx.r3.s64 = r11.s64 + 24108;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8AF4"))) PPC_WEAK_FUNC(sub_827B8AF4);
PPC_FUNC_IMPL(__imp__sub_827B8AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8AF8"))) PPC_WEAK_FUNC(sub_827B8AF8);
PPC_FUNC_IMPL(__imp__sub_827B8AF8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8AFC"))) PPC_WEAK_FUNC(sub_827B8AFC);
PPC_FUNC_IMPL(__imp__sub_827B8AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8B00"))) PPC_WEAK_FUNC(sub_827B8B00);
PPC_FUNC_IMPL(__imp__sub_827B8B00) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8B04"))) PPC_WEAK_FUNC(sub_827B8B04);
PPC_FUNC_IMPL(__imp__sub_827B8B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8B08"))) PPC_WEAK_FUNC(sub_827B8B08);
PPC_FUNC_IMPL(__imp__sub_827B8B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,1812
	ctx.r3.s64 = r11.s64 + 1812;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8B14"))) PPC_WEAK_FUNC(sub_827B8B14);
PPC_FUNC_IMPL(__imp__sub_827B8B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8B18"))) PPC_WEAK_FUNC(sub_827B8B18);
PPC_FUNC_IMPL(__imp__sub_827B8B18) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8B1C"))) PPC_WEAK_FUNC(sub_827B8B1C);
PPC_FUNC_IMPL(__imp__sub_827B8B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8B20"))) PPC_WEAK_FUNC(sub_827B8B20);
PPC_FUNC_IMPL(__imp__sub_827B8B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r11,r11,8300
	r11.s64 = r11.s64 + 8300;
	// stw r11,-31864(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31864, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8B34"))) PPC_WEAK_FUNC(sub_827B8B34);
PPC_FUNC_IMPL(__imp__sub_827B8B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8B38"))) PPC_WEAK_FUNC(sub_827B8B38);
PPC_FUNC_IMPL(__imp__sub_827B8B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r11,r11,8300
	r11.s64 = r11.s64 + 8300;
	// stw r11,-31860(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31860, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8B4C"))) PPC_WEAK_FUNC(sub_827B8B4C);
PPC_FUNC_IMPL(__imp__sub_827B8B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8B50"))) PPC_WEAK_FUNC(sub_827B8B50);
PPC_FUNC_IMPL(__imp__sub_827B8B50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2116
	ctx.r3.s64 = r11.s64 + 2116;
	// lhz r5,6(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x821cb988
	sub_821CB988(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8B6C"))) PPC_WEAK_FUNC(sub_827B8B6C);
PPC_FUNC_IMPL(__imp__sub_827B8B6C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8B70"))) PPC_WEAK_FUNC(sub_827B8B70);
PPC_FUNC_IMPL(__imp__sub_827B8B70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2772
	ctx.r3.s64 = r11.s64 + 2772;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8B7C"))) PPC_WEAK_FUNC(sub_827B8B7C);
PPC_FUNC_IMPL(__imp__sub_827B8B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8B80"))) PPC_WEAK_FUNC(sub_827B8B80);
PPC_FUNC_IMPL(__imp__sub_827B8B80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r11,r11,8300
	r11.s64 = r11.s64 + 8300;
	// stw r11,-30668(r10)
	PPC_STORE_U32(ctx.r10.u32 + -30668, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8B94"))) PPC_WEAK_FUNC(sub_827B8B94);
PPC_FUNC_IMPL(__imp__sub_827B8B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8B98"))) PPC_WEAK_FUNC(sub_827B8B98);
PPC_FUNC_IMPL(__imp__sub_827B8B98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r11,r11,-30104
	r11.s64 = r11.s64 + -30104;
	// lhz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8BB4"))) PPC_WEAK_FUNC(sub_827B8BB4);
PPC_FUNC_IMPL(__imp__sub_827B8BB4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8BB8"))) PPC_WEAK_FUNC(sub_827B8BB8);
PPC_FUNC_IMPL(__imp__sub_827B8BB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r7,r8,-29884
	ctx.r7.s64 = ctx.r8.s64 + -29884;
	// addi r10,r10,31476
	ctx.r10.s64 = ctx.r10.s64 + 31476;
	// lwz r9,-12720(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -12720);
	// stw r10,-29884(r8)
	PPC_STORE_U32(ctx.r8.u32 + -29884, ctx.r10.u32);
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-12720(r11)
	PPC_STORE_U32(r11.u32 + -12720, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8BE8"))) PPC_WEAK_FUNC(sub_827B8BE8);
PPC_FUNC_IMPL(__imp__sub_827B8BE8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8BEC"))) PPC_WEAK_FUNC(sub_827B8BEC);
PPC_FUNC_IMPL(__imp__sub_827B8BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8BF0"))) PPC_WEAK_FUNC(sub_827B8BF0);
PPC_FUNC_IMPL(__imp__sub_827B8BF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8BF4"))) PPC_WEAK_FUNC(sub_827B8BF4);
PPC_FUNC_IMPL(__imp__sub_827B8BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8BF8"))) PPC_WEAK_FUNC(sub_827B8BF8);
PPC_FUNC_IMPL(__imp__sub_827B8BF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r11,r11,-21856
	r11.s64 = r11.s64 + -21856;
	// stw r11,-22444(r10)
	PPC_STORE_U32(ctx.r10.u32 + -22444, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8C0C"))) PPC_WEAK_FUNC(sub_827B8C0C);
PPC_FUNC_IMPL(__imp__sub_827B8C0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C10"))) PPC_WEAK_FUNC(sub_827B8C10);
PPC_FUNC_IMPL(__imp__sub_827B8C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-7824
	ctx.r3.s64 = r11.s64 + -7824;
	// b 0x824e6b58
	sub_824E6B58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C1C"))) PPC_WEAK_FUNC(sub_827B8C1C);
PPC_FUNC_IMPL(__imp__sub_827B8C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C20"))) PPC_WEAK_FUNC(sub_827B8C20);
PPC_FUNC_IMPL(__imp__sub_827B8C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-4336
	ctx.r3.s64 = r11.s64 + -4336;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C2C"))) PPC_WEAK_FUNC(sub_827B8C2C);
PPC_FUNC_IMPL(__imp__sub_827B8C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C30"))) PPC_WEAK_FUNC(sub_827B8C30);
PPC_FUNC_IMPL(__imp__sub_827B8C30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3040
	ctx.r3.s64 = r11.s64 + -3040;
	// b 0x824f0700
	sub_824F0700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C3C"))) PPC_WEAK_FUNC(sub_827B8C3C);
PPC_FUNC_IMPL(__imp__sub_827B8C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C40"))) PPC_WEAK_FUNC(sub_827B8C40);
PPC_FUNC_IMPL(__imp__sub_827B8C40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3348
	ctx.r3.s64 = r11.s64 + -3348;
	// b 0x824f0700
	sub_824F0700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C4C"))) PPC_WEAK_FUNC(sub_827B8C4C);
PPC_FUNC_IMPL(__imp__sub_827B8C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C50"))) PPC_WEAK_FUNC(sub_827B8C50);
PPC_FUNC_IMPL(__imp__sub_827B8C50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3404
	ctx.r3.s64 = r11.s64 + -3404;
	// b 0x824f0700
	sub_824F0700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C5C"))) PPC_WEAK_FUNC(sub_827B8C5C);
PPC_FUNC_IMPL(__imp__sub_827B8C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C60"))) PPC_WEAK_FUNC(sub_827B8C60);
PPC_FUNC_IMPL(__imp__sub_827B8C60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3096
	ctx.r3.s64 = r11.s64 + -3096;
	// b 0x824f0700
	sub_824F0700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C6C"))) PPC_WEAK_FUNC(sub_827B8C6C);
PPC_FUNC_IMPL(__imp__sub_827B8C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C70"))) PPC_WEAK_FUNC(sub_827B8C70);
PPC_FUNC_IMPL(__imp__sub_827B8C70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3232
	ctx.r3.s64 = r11.s64 + -3232;
	// b 0x824f0700
	sub_824F0700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C7C"))) PPC_WEAK_FUNC(sub_827B8C7C);
PPC_FUNC_IMPL(__imp__sub_827B8C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C80"))) PPC_WEAK_FUNC(sub_827B8C80);
PPC_FUNC_IMPL(__imp__sub_827B8C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3500
	ctx.r3.s64 = r11.s64 + -3500;
	// b 0x824f0700
	sub_824F0700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C8C"))) PPC_WEAK_FUNC(sub_827B8C8C);
PPC_FUNC_IMPL(__imp__sub_827B8C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8C90"))) PPC_WEAK_FUNC(sub_827B8C90);
PPC_FUNC_IMPL(__imp__sub_827B8C90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3556
	ctx.r3.s64 = r11.s64 + -3556;
	// b 0x824f0700
	sub_824F0700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8C9C"))) PPC_WEAK_FUNC(sub_827B8C9C);
PPC_FUNC_IMPL(__imp__sub_827B8C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8CA0"))) PPC_WEAK_FUNC(sub_827B8CA0);
PPC_FUNC_IMPL(__imp__sub_827B8CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r11,r11,-2620
	r11.s64 = r11.s64 + -2620;
	// stw r11,-11588(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11588, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8CB4"))) PPC_WEAK_FUNC(sub_827B8CB4);
PPC_FUNC_IMPL(__imp__sub_827B8CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8CB8"))) PPC_WEAK_FUNC(sub_827B8CB8);
PPC_FUNC_IMPL(__imp__sub_827B8CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-2984
	ctx.r3.s64 = r11.s64 + -2984;
	// b 0x82489608
	sub_82489608(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8CC4"))) PPC_WEAK_FUNC(sub_827B8CC4);
PPC_FUNC_IMPL(__imp__sub_827B8CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8CC8"))) PPC_WEAK_FUNC(sub_827B8CC8);
PPC_FUNC_IMPL(__imp__sub_827B8CC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,8892
	ctx.r3.s64 = r11.s64 + 8892;
	// b 0x824fa9b0
	sub_824FA9B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B8CD4"))) PPC_WEAK_FUNC(sub_827B8CD4);
PPC_FUNC_IMPL(__imp__sub_827B8CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8CD8"))) PPC_WEAK_FUNC(sub_827B8CD8);
PPC_FUNC_IMPL(__imp__sub_827B8CD8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,8796
	r30.s64 = r31.s64 + 8796;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8796(r31)
	PPC_STORE_U32(r31.u32 + 8796, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8D04;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8D0C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,8796(r31)
	PPC_STORE_U32(r31.u32 + 8796, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8D30"))) PPC_WEAK_FUNC(sub_827B8D30);
PPC_FUNC_IMPL(__imp__sub_827B8D30) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,8828
	r30.s64 = r31.s64 + 8828;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8D5C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8D64;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8D88"))) PPC_WEAK_FUNC(sub_827B8D88);
PPC_FUNC_IMPL(__imp__sub_827B8D88) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,8860
	r30.s64 = r31.s64 + 8860;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,8860(r31)
	PPC_STORE_U32(r31.u32 + 8860, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8DB4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8DBC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,8860(r31)
	PPC_STORE_U32(r31.u32 + 8860, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8DE0"))) PPC_WEAK_FUNC(sub_827B8DE0);
PPC_FUNC_IMPL(__imp__sub_827B8DE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r8,r9,8924
	ctx.r8.s64 = ctx.r9.s64 + 8924;
	// addi r11,r11,-28
	r11.s64 = r11.s64 + -28;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// stw r10,8924(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8924, ctx.r10.u32);
	// stw r11,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8E04"))) PPC_WEAK_FUNC(sub_827B8E04);
PPC_FUNC_IMPL(__imp__sub_827B8E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8E08"))) PPC_WEAK_FUNC(sub_827B8E08);
PPC_FUNC_IMPL(__imp__sub_827B8E08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8E0C"))) PPC_WEAK_FUNC(sub_827B8E0C);
PPC_FUNC_IMPL(__imp__sub_827B8E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B8E10"))) PPC_WEAK_FUNC(sub_827B8E10);
PPC_FUNC_IMPL(__imp__sub_827B8E10) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,15992
	r30.s64 = r31.s64 + 15992;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,15992(r31)
	PPC_STORE_U32(r31.u32 + 15992, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8E3C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8E44;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,15992(r31)
	PPC_STORE_U32(r31.u32 + 15992, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8E68"))) PPC_WEAK_FUNC(sub_827B8E68);
PPC_FUNC_IMPL(__imp__sub_827B8E68) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16088
	r30.s64 = r31.s64 + 16088;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16088(r31)
	PPC_STORE_U32(r31.u32 + 16088, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8E94;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8E9C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16088(r31)
	PPC_STORE_U32(r31.u32 + 16088, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8EC0"))) PPC_WEAK_FUNC(sub_827B8EC0);
PPC_FUNC_IMPL(__imp__sub_827B8EC0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16376
	r30.s64 = r31.s64 + 16376;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16376(r31)
	PPC_STORE_U32(r31.u32 + 16376, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8EEC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8EF4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16376(r31)
	PPC_STORE_U32(r31.u32 + 16376, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8F18"))) PPC_WEAK_FUNC(sub_827B8F18);
PPC_FUNC_IMPL(__imp__sub_827B8F18) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16664
	r30.s64 = r31.s64 + 16664;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16664(r31)
	PPC_STORE_U32(r31.u32 + 16664, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8F44;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8F4C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16664(r31)
	PPC_STORE_U32(r31.u32 + 16664, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8F70"))) PPC_WEAK_FUNC(sub_827B8F70);
PPC_FUNC_IMPL(__imp__sub_827B8F70) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16312
	r30.s64 = r31.s64 + 16312;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16312(r31)
	PPC_STORE_U32(r31.u32 + 16312, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8F9C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8FA4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16312(r31)
	PPC_STORE_U32(r31.u32 + 16312, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B8FC8"))) PPC_WEAK_FUNC(sub_827B8FC8);
PPC_FUNC_IMPL(__imp__sub_827B8FC8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16536
	r30.s64 = r31.s64 + 16536;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16536(r31)
	PPC_STORE_U32(r31.u32 + 16536, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B8FF4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B8FFC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16536(r31)
	PPC_STORE_U32(r31.u32 + 16536, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9020"))) PPC_WEAK_FUNC(sub_827B9020);
PPC_FUNC_IMPL(__imp__sub_827B9020) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16600
	r30.s64 = r31.s64 + 16600;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16600(r31)
	PPC_STORE_U32(r31.u32 + 16600, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B904C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9054;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16600(r31)
	PPC_STORE_U32(r31.u32 + 16600, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9078"))) PPC_WEAK_FUNC(sub_827B9078);
PPC_FUNC_IMPL(__imp__sub_827B9078) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16152
	r30.s64 = r31.s64 + 16152;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16152(r31)
	PPC_STORE_U32(r31.u32 + 16152, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B90A4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B90AC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16152(r31)
	PPC_STORE_U32(r31.u32 + 16152, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B90D0"))) PPC_WEAK_FUNC(sub_827B90D0);
PPC_FUNC_IMPL(__imp__sub_827B90D0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16408
	r30.s64 = r31.s64 + 16408;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16408(r31)
	PPC_STORE_U32(r31.u32 + 16408, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B90FC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9104;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16408(r31)
	PPC_STORE_U32(r31.u32 + 16408, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9128"))) PPC_WEAK_FUNC(sub_827B9128);
PPC_FUNC_IMPL(__imp__sub_827B9128) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16280
	r30.s64 = r31.s64 + 16280;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16280(r31)
	PPC_STORE_U32(r31.u32 + 16280, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B9154;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B915C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16280(r31)
	PPC_STORE_U32(r31.u32 + 16280, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9180"))) PPC_WEAK_FUNC(sub_827B9180);
PPC_FUNC_IMPL(__imp__sub_827B9180) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16568
	r30.s64 = r31.s64 + 16568;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16568(r31)
	PPC_STORE_U32(r31.u32 + 16568, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B91AC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B91B4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16568(r31)
	PPC_STORE_U32(r31.u32 + 16568, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B91D8"))) PPC_WEAK_FUNC(sub_827B91D8);
PPC_FUNC_IMPL(__imp__sub_827B91D8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16216
	r30.s64 = r31.s64 + 16216;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16216(r31)
	PPC_STORE_U32(r31.u32 + 16216, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B9204;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B920C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16216(r31)
	PPC_STORE_U32(r31.u32 + 16216, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9230"))) PPC_WEAK_FUNC(sub_827B9230);
PPC_FUNC_IMPL(__imp__sub_827B9230) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16440
	r30.s64 = r31.s64 + 16440;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16440(r31)
	PPC_STORE_U32(r31.u32 + 16440, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B925C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9264;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16440(r31)
	PPC_STORE_U32(r31.u32 + 16440, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9288"))) PPC_WEAK_FUNC(sub_827B9288);
PPC_FUNC_IMPL(__imp__sub_827B9288) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16056
	r30.s64 = r31.s64 + 16056;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16056(r31)
	PPC_STORE_U32(r31.u32 + 16056, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B92B4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B92BC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16056(r31)
	PPC_STORE_U32(r31.u32 + 16056, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B92E0"))) PPC_WEAK_FUNC(sub_827B92E0);
PPC_FUNC_IMPL(__imp__sub_827B92E0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16472
	r30.s64 = r31.s64 + 16472;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16472(r31)
	PPC_STORE_U32(r31.u32 + 16472, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B930C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9314;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16472(r31)
	PPC_STORE_U32(r31.u32 + 16472, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9338"))) PPC_WEAK_FUNC(sub_827B9338);
PPC_FUNC_IMPL(__imp__sub_827B9338) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16120
	r30.s64 = r31.s64 + 16120;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16120(r31)
	PPC_STORE_U32(r31.u32 + 16120, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B9364;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B936C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16120(r31)
	PPC_STORE_U32(r31.u32 + 16120, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9390"))) PPC_WEAK_FUNC(sub_827B9390);
PPC_FUNC_IMPL(__imp__sub_827B9390) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16696
	r30.s64 = r31.s64 + 16696;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16696(r31)
	PPC_STORE_U32(r31.u32 + 16696, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B93BC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B93C4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16696(r31)
	PPC_STORE_U32(r31.u32 + 16696, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B93E8"))) PPC_WEAK_FUNC(sub_827B93E8);
PPC_FUNC_IMPL(__imp__sub_827B93E8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16184
	r30.s64 = r31.s64 + 16184;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16184(r31)
	PPC_STORE_U32(r31.u32 + 16184, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B9414;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B941C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16184(r31)
	PPC_STORE_U32(r31.u32 + 16184, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9440"))) PPC_WEAK_FUNC(sub_827B9440);
PPC_FUNC_IMPL(__imp__sub_827B9440) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16248
	r30.s64 = r31.s64 + 16248;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16248(r31)
	PPC_STORE_U32(r31.u32 + 16248, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B946C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9474;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16248(r31)
	PPC_STORE_U32(r31.u32 + 16248, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9498"))) PPC_WEAK_FUNC(sub_827B9498);
PPC_FUNC_IMPL(__imp__sub_827B9498) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16792
	r30.s64 = r31.s64 + 16792;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16792(r31)
	PPC_STORE_U32(r31.u32 + 16792, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B94C4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B94CC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16792(r31)
	PPC_STORE_U32(r31.u32 + 16792, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B94F0"))) PPC_WEAK_FUNC(sub_827B94F0);
PPC_FUNC_IMPL(__imp__sub_827B94F0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16344
	r30.s64 = r31.s64 + 16344;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16344(r31)
	PPC_STORE_U32(r31.u32 + 16344, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B951C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9524;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16344(r31)
	PPC_STORE_U32(r31.u32 + 16344, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9548"))) PPC_WEAK_FUNC(sub_827B9548);
PPC_FUNC_IMPL(__imp__sub_827B9548) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16504
	r30.s64 = r31.s64 + 16504;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16504(r31)
	PPC_STORE_U32(r31.u32 + 16504, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B9574;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B957C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16504(r31)
	PPC_STORE_U32(r31.u32 + 16504, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B95A0"))) PPC_WEAK_FUNC(sub_827B95A0);
PPC_FUNC_IMPL(__imp__sub_827B95A0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16024
	r30.s64 = r31.s64 + 16024;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16024(r31)
	PPC_STORE_U32(r31.u32 + 16024, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B95CC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B95D4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16024(r31)
	PPC_STORE_U32(r31.u32 + 16024, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B95F8"))) PPC_WEAK_FUNC(sub_827B95F8);
PPC_FUNC_IMPL(__imp__sub_827B95F8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16760
	r30.s64 = r31.s64 + 16760;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16760(r31)
	PPC_STORE_U32(r31.u32 + 16760, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B9624;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B962C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16760(r31)
	PPC_STORE_U32(r31.u32 + 16760, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9650"))) PPC_WEAK_FUNC(sub_827B9650);
PPC_FUNC_IMPL(__imp__sub_827B9650) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16728
	r30.s64 = r31.s64 + 16728;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16728(r31)
	PPC_STORE_U32(r31.u32 + 16728, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B967C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9684;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16728(r31)
	PPC_STORE_U32(r31.u32 + 16728, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B96A8"))) PPC_WEAK_FUNC(sub_827B96A8);
PPC_FUNC_IMPL(__imp__sub_827B96A8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16632
	r30.s64 = r31.s64 + 16632;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16632(r31)
	PPC_STORE_U32(r31.u32 + 16632, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B96D4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B96DC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16632(r31)
	PPC_STORE_U32(r31.u32 + 16632, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9700"))) PPC_WEAK_FUNC(sub_827B9700);
PPC_FUNC_IMPL(__imp__sub_827B9700) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16844
	r30.s64 = r31.s64 + 16844;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16844(r31)
	PPC_STORE_U32(r31.u32 + 16844, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B972C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9734;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16844(r31)
	PPC_STORE_U32(r31.u32 + 16844, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9758"))) PPC_WEAK_FUNC(sub_827B9758);
PPC_FUNC_IMPL(__imp__sub_827B9758) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16896
	r30.s64 = r31.s64 + 16896;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16896(r31)
	PPC_STORE_U32(r31.u32 + 16896, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B9784;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B978C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16896(r31)
	PPC_STORE_U32(r31.u32 + 16896, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B97B0"))) PPC_WEAK_FUNC(sub_827B97B0);
PPC_FUNC_IMPL(__imp__sub_827B97B0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16928
	r30.s64 = r31.s64 + 16928;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16928(r31)
	PPC_STORE_U32(r31.u32 + 16928, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B97DC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B97E4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16928(r31)
	PPC_STORE_U32(r31.u32 + 16928, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9808"))) PPC_WEAK_FUNC(sub_827B9808);
PPC_FUNC_IMPL(__imp__sub_827B9808) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16960
	r30.s64 = r31.s64 + 16960;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16960(r31)
	PPC_STORE_U32(r31.u32 + 16960, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B9834;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B983C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16960(r31)
	PPC_STORE_U32(r31.u32 + 16960, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9860"))) PPC_WEAK_FUNC(sub_827B9860);
PPC_FUNC_IMPL(__imp__sub_827B9860) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,17024
	r30.s64 = r31.s64 + 17024;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,17024(r31)
	PPC_STORE_U32(r31.u32 + 17024, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B988C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9894;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,17024(r31)
	PPC_STORE_U32(r31.u32 + 17024, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B98B8"))) PPC_WEAK_FUNC(sub_827B98B8);
PPC_FUNC_IMPL(__imp__sub_827B98B8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,16992
	r30.s64 = r31.s64 + 16992;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,16992(r31)
	PPC_STORE_U32(r31.u32 + 16992, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B98E4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B98EC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,16992(r31)
	PPC_STORE_U32(r31.u32 + 16992, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9910"))) PPC_WEAK_FUNC(sub_827B9910);
PPC_FUNC_IMPL(__imp__sub_827B9910) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,17056
	r30.s64 = r31.s64 + 17056;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,17056(r31)
	PPC_STORE_U32(r31.u32 + 17056, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827B993C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827B9944;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,17056(r31)
	PPC_STORE_U32(r31.u32 + 17056, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9968"))) PPC_WEAK_FUNC(sub_827B9968);
PPC_FUNC_IMPL(__imp__sub_827B9968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r8,r9,17088
	ctx.r8.s64 = ctx.r9.s64 + 17088;
	// addi r11,r11,-28
	r11.s64 = r11.s64 + -28;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// stw r10,17088(r9)
	PPC_STORE_U32(ctx.r9.u32 + 17088, ctx.r10.u32);
	// stw r11,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B998C"))) PPC_WEAK_FUNC(sub_827B998C);
PPC_FUNC_IMPL(__imp__sub_827B998C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B9990"))) PPC_WEAK_FUNC(sub_827B9990);
PPC_FUNC_IMPL(__imp__sub_827B9990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,17592
	ctx.r3.s64 = r11.s64 + 17592;
	// b 0x824e0430
	sub_824E0430(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B999C"))) PPC_WEAK_FUNC(sub_827B999C);
PPC_FUNC_IMPL(__imp__sub_827B999C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B99A0"))) PPC_WEAK_FUNC(sub_827B99A0);
PPC_FUNC_IMPL(__imp__sub_827B99A0) {
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
	// addi r30,r31,18180
	r30.s64 = r31.s64 + 18180;
	// lwz r3,18180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18180);
	// bl 0x82130588
	ctx.lr = 0x827B99C4;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,18180(r31)
	PPC_STORE_U32(r31.u32 + 18180, r11.u32);
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B99F4"))) PPC_WEAK_FUNC(sub_827B99F4);
PPC_FUNC_IMPL(__imp__sub_827B99F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B99F8"))) PPC_WEAK_FUNC(sub_827B99F8);
PPC_FUNC_IMPL(__imp__sub_827B99F8) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-30432
	r31.s64 = r11.s64 + -30432;
	// lbz r11,410(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 410);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827b9a24
	if (cr6.eq) goto loc_827B9A24;
	// lwz r3,276(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// bl 0x82130588
	ctx.lr = 0x827B9A24;
	sub_82130588(ctx, base);
loc_827B9A24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x827B9A2C;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_827B9A40"))) PPC_WEAK_FUNC(sub_827B9A40);
PPC_FUNC_IMPL(__imp__sub_827B9A40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-14240
	ctx.r3.s64 = r11.s64 + -14240;
	// b 0x8217cb48
	sub_8217CB48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B9A4C"))) PPC_WEAK_FUNC(sub_827B9A4C);
PPC_FUNC_IMPL(__imp__sub_827B9A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B9A50"))) PPC_WEAK_FUNC(sub_827B9A50);
PPC_FUNC_IMPL(__imp__sub_827B9A50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-12976
	ctx.r3.s64 = r11.s64 + -12976;
	// b 0x8217cb48
	sub_8217CB48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B9A5C"))) PPC_WEAK_FUNC(sub_827B9A5C);
PPC_FUNC_IMPL(__imp__sub_827B9A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B9A60"))) PPC_WEAK_FUNC(sub_827B9A60);
PPC_FUNC_IMPL(__imp__sub_827B9A60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// b 0x822d8c78
	sub_822D8C78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B9A6C"))) PPC_WEAK_FUNC(sub_827B9A6C);
PPC_FUNC_IMPL(__imp__sub_827B9A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B9A70"))) PPC_WEAK_FUNC(sub_827B9A70);
PPC_FUNC_IMPL(__imp__sub_827B9A70) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-11552
	r11.s64 = r11.s64 + -11552;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9A94:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9AA0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9a94
	if (!cr0.lt) goto loc_827B9A94;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9AC0"))) PPC_WEAK_FUNC(sub_827B9AC0);
PPC_FUNC_IMPL(__imp__sub_827B9AC0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-11712
	r11.s64 = r11.s64 + -11712;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9AE4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9AF0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9ae4
	if (!cr0.lt) goto loc_827B9AE4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9B10"))) PPC_WEAK_FUNC(sub_827B9B10);
PPC_FUNC_IMPL(__imp__sub_827B9B10) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-11052
	r11.s64 = r11.s64 + -11052;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9B34:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9B40;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9b34
	if (!cr0.lt) goto loc_827B9B34;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9B60"))) PPC_WEAK_FUNC(sub_827B9B60);
PPC_FUNC_IMPL(__imp__sub_827B9B60) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-10252
	r11.s64 = r11.s64 + -10252;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9B84:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9B90;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9b84
	if (!cr0.lt) goto loc_827B9B84;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9BB0"))) PPC_WEAK_FUNC(sub_827B9BB0);
PPC_FUNC_IMPL(__imp__sub_827B9BB0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-10892
	r11.s64 = r11.s64 + -10892;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9BD4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9BE0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9bd4
	if (!cr0.lt) goto loc_827B9BD4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9C00"))) PPC_WEAK_FUNC(sub_827B9C00);
PPC_FUNC_IMPL(__imp__sub_827B9C00) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-9932
	r11.s64 = r11.s64 + -9932;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9C24:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9C30;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9c24
	if (!cr0.lt) goto loc_827B9C24;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9C50"))) PPC_WEAK_FUNC(sub_827B9C50);
PPC_FUNC_IMPL(__imp__sub_827B9C50) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-10732
	r11.s64 = r11.s64 + -10732;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9C74:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9C80;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9c74
	if (!cr0.lt) goto loc_827B9C74;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9CA0"))) PPC_WEAK_FUNC(sub_827B9CA0);
PPC_FUNC_IMPL(__imp__sub_827B9CA0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-10092
	r11.s64 = r11.s64 + -10092;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9CC4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9CD0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9cc4
	if (!cr0.lt) goto loc_827B9CC4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9CF0"))) PPC_WEAK_FUNC(sub_827B9CF0);
PPC_FUNC_IMPL(__imp__sub_827B9CF0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-11372
	r11.s64 = r11.s64 + -11372;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9D14:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9D20;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9d14
	if (!cr0.lt) goto loc_827B9D14;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9D40"))) PPC_WEAK_FUNC(sub_827B9D40);
PPC_FUNC_IMPL(__imp__sub_827B9D40) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-10572
	r11.s64 = r11.s64 + -10572;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9D64:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9D70;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9d64
	if (!cr0.lt) goto loc_827B9D64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9D90"))) PPC_WEAK_FUNC(sub_827B9D90);
PPC_FUNC_IMPL(__imp__sub_827B9D90) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-11212
	r11.s64 = r11.s64 + -11212;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9DB4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9DC0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9db4
	if (!cr0.lt) goto loc_827B9DB4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9DE0"))) PPC_WEAK_FUNC(sub_827B9DE0);
PPC_FUNC_IMPL(__imp__sub_827B9DE0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-10412
	r11.s64 = r11.s64 + -10412;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9E04:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9E10;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9e04
	if (!cr0.lt) goto loc_827B9E04;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9E30"))) PPC_WEAK_FUNC(sub_827B9E30);
PPC_FUNC_IMPL(__imp__sub_827B9E30) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-8288
	r11.s64 = r11.s64 + -8288;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9E54:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9E60;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9e54
	if (!cr0.lt) goto loc_827B9E54;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9E80"))) PPC_WEAK_FUNC(sub_827B9E80);
PPC_FUNC_IMPL(__imp__sub_827B9E80) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-9248
	r11.s64 = r11.s64 + -9248;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9EA4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9EB0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9ea4
	if (!cr0.lt) goto loc_827B9EA4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9ED0"))) PPC_WEAK_FUNC(sub_827B9ED0);
PPC_FUNC_IMPL(__imp__sub_827B9ED0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-9568
	r11.s64 = r11.s64 + -9568;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9EF4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9F00;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9ef4
	if (!cr0.lt) goto loc_827B9EF4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9F20"))) PPC_WEAK_FUNC(sub_827B9F20);
PPC_FUNC_IMPL(__imp__sub_827B9F20) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-9408
	r11.s64 = r11.s64 + -9408;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9F44:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9F50;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9f44
	if (!cr0.lt) goto loc_827B9F44;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9F70"))) PPC_WEAK_FUNC(sub_827B9F70);
PPC_FUNC_IMPL(__imp__sub_827B9F70) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-8608
	r11.s64 = r11.s64 + -8608;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9F94:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9FA0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9f94
	if (!cr0.lt) goto loc_827B9F94;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B9FC0"))) PPC_WEAK_FUNC(sub_827B9FC0);
PPC_FUNC_IMPL(__imp__sub_827B9FC0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-8768
	r11.s64 = r11.s64 + -8768;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827B9FE4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827B9FF0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827b9fe4
	if (!cr0.lt) goto loc_827B9FE4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA010"))) PPC_WEAK_FUNC(sub_827BA010);
PPC_FUNC_IMPL(__imp__sub_827BA010) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-8448
	r11.s64 = r11.s64 + -8448;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827BA034:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827BA040;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827ba034
	if (!cr0.lt) goto loc_827BA034;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA060"))) PPC_WEAK_FUNC(sub_827BA060);
PPC_FUNC_IMPL(__imp__sub_827BA060) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-9088
	r11.s64 = r11.s64 + -9088;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827BA084:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827BA090;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827ba084
	if (!cr0.lt) goto loc_827BA084;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA0B0"))) PPC_WEAK_FUNC(sub_827BA0B0);
PPC_FUNC_IMPL(__imp__sub_827BA0B0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-8928
	r11.s64 = r11.s64 + -8928;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827BA0D4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827BA0E0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827ba0d4
	if (!cr0.lt) goto loc_827BA0D4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA100"))) PPC_WEAK_FUNC(sub_827BA100);
PPC_FUNC_IMPL(__imp__sub_827BA100) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,3
	r30.s64 = 3;
	// addi r11,r11,-9728
	r11.s64 = r11.s64 + -9728;
	// addi r31,r11,160
	r31.s64 = r11.s64 + 160;
loc_827BA124:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x827BA130;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827ba124
	if (!cr0.lt) goto loc_827BA124;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA150"))) PPC_WEAK_FUNC(sub_827BA150);
PPC_FUNC_IMPL(__imp__sub_827BA150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7680(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7680);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827BA170"))) PPC_WEAK_FUNC(sub_827BA170);
PPC_FUNC_IMPL(__imp__sub_827BA170) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA174"))) PPC_WEAK_FUNC(sub_827BA174);
PPC_FUNC_IMPL(__imp__sub_827BA174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA178"))) PPC_WEAK_FUNC(sub_827BA178);
PPC_FUNC_IMPL(__imp__sub_827BA178) {
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
	ctx.lr = 0x827BA180;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r11,r11,7456
	r11.s64 = r11.s64 + 7456;
	// lhz r31,10(r11)
	r31.u64 = PPC_LOAD_U16(r11.u32 + 10);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827ba1c4
	if (cr6.eq) goto loc_827BA1C4;
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x827ba1bc
	if (!cr6.gt) goto loc_827BA1BC;
	// addi r30,r29,4
	r30.s64 = r29.s64 + 4;
loc_827BA1A8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x827BA1B0;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x827ba1a8
	if (!cr0.eq) goto loc_827BA1A8;
loc_827BA1BC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x827BA1C4;
	sub_82130588(ctx, base);
loc_827BA1C4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827BA1CC"))) PPC_WEAK_FUNC(sub_827BA1CC);
PPC_FUNC_IMPL(__imp__sub_827BA1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA1D0"))) PPC_WEAK_FUNC(sub_827BA1D0);
PPC_FUNC_IMPL(__imp__sub_827BA1D0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,95
	r30.s64 = 95;
	// addi r11,r11,3952
	r11.s64 = r11.s64 + 3952;
	// addi r31,r11,10752
	r31.s64 = r11.s64 + 10752;
loc_827BA1F4:
	// addi r31,r31,-112
	r31.s64 = r31.s64 + -112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x827BA200;
	sub_821D2028(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827ba1f4
	if (!cr0.lt) goto loc_827BA1F4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA220"))) PPC_WEAK_FUNC(sub_827BA220);
PPC_FUNC_IMPL(__imp__sub_827BA220) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,95
	r30.s64 = 95;
	// addi r11,r11,-7248
	r11.s64 = r11.s64 + -7248;
	// addi r31,r11,10752
	r31.s64 = r11.s64 + 10752;
loc_827BA244:
	// addi r31,r31,-112
	r31.s64 = r31.s64 + -112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x827BA250;
	sub_821D2028(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827ba244
	if (!cr0.lt) goto loc_827BA244;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA270"))) PPC_WEAK_FUNC(sub_827BA270);
PPC_FUNC_IMPL(__imp__sub_827BA270) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,95
	r30.s64 = 95;
	// addi r11,r11,14704
	r11.s64 = r11.s64 + 14704;
	// addi r31,r11,32256
	r31.s64 = r11.s64 + 32256;
loc_827BA294:
	// addi r31,r31,-336
	r31.s64 = r31.s64 + -336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x827BA2A0;
	sub_821D2028(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x827ba294
	if (!cr0.lt) goto loc_827BA294;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA2C0"))) PPC_WEAK_FUNC(sub_827BA2C0);
PPC_FUNC_IMPL(__imp__sub_827BA2C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA2C4"))) PPC_WEAK_FUNC(sub_827BA2C4);
PPC_FUNC_IMPL(__imp__sub_827BA2C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA2C8"))) PPC_WEAK_FUNC(sub_827BA2C8);
PPC_FUNC_IMPL(__imp__sub_827BA2C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r11,r11,-18216
	r11.s64 = r11.s64 + -18216;
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

__attribute__((alias("__imp__sub_827BA2E4"))) PPC_WEAK_FUNC(sub_827BA2E4);
PPC_FUNC_IMPL(__imp__sub_827BA2E4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA2E8"))) PPC_WEAK_FUNC(sub_827BA2E8);
PPC_FUNC_IMPL(__imp__sub_827BA2E8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA2EC"))) PPC_WEAK_FUNC(sub_827BA2EC);
PPC_FUNC_IMPL(__imp__sub_827BA2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA2F0"))) PPC_WEAK_FUNC(sub_827BA2F0);
PPC_FUNC_IMPL(__imp__sub_827BA2F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r11,r11,-10744
	r11.s64 = r11.s64 + -10744;
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

__attribute__((alias("__imp__sub_827BA30C"))) PPC_WEAK_FUNC(sub_827BA30C);
PPC_FUNC_IMPL(__imp__sub_827BA30C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA310"))) PPC_WEAK_FUNC(sub_827BA310);
PPC_FUNC_IMPL(__imp__sub_827BA310) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-9632
	r31.s64 = r11.s64 + -9632;
	// addi r3,r31,180
	ctx.r3.s64 = r31.s64 + 180;
	// bl 0x824e0430
	ctx.lr = 0x827BA330;
	sub_824E0430(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0430
	ctx.lr = 0x827BA338;
	sub_824E0430(ctx, base);
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

__attribute__((alias("__imp__sub_827BA34C"))) PPC_WEAK_FUNC(sub_827BA34C);
PPC_FUNC_IMPL(__imp__sub_827BA34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA350"))) PPC_WEAK_FUNC(sub_827BA350);
PPC_FUNC_IMPL(__imp__sub_827BA350) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-10352
	r31.s64 = r11.s64 + -10352;
	// addi r3,r31,180
	ctx.r3.s64 = r31.s64 + 180;
	// bl 0x824e0430
	ctx.lr = 0x827BA370;
	sub_824E0430(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0430
	ctx.lr = 0x827BA378;
	sub_824E0430(ctx, base);
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

__attribute__((alias("__imp__sub_827BA38C"))) PPC_WEAK_FUNC(sub_827BA38C);
PPC_FUNC_IMPL(__imp__sub_827BA38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA390"))) PPC_WEAK_FUNC(sub_827BA390);
PPC_FUNC_IMPL(__imp__sub_827BA390) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-9424
	r31.s64 = r11.s64 + -9424;
	// addi r3,r31,180
	ctx.r3.s64 = r31.s64 + 180;
	// bl 0x824e0430
	ctx.lr = 0x827BA3B0;
	sub_824E0430(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0430
	ctx.lr = 0x827BA3B8;
	sub_824E0430(ctx, base);
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

__attribute__((alias("__imp__sub_827BA3CC"))) PPC_WEAK_FUNC(sub_827BA3CC);
PPC_FUNC_IMPL(__imp__sub_827BA3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA3D0"))) PPC_WEAK_FUNC(sub_827BA3D0);
PPC_FUNC_IMPL(__imp__sub_827BA3D0) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-10096
	r31.s64 = r11.s64 + -10096;
	// addi r3,r31,180
	ctx.r3.s64 = r31.s64 + 180;
	// bl 0x824e0430
	ctx.lr = 0x827BA3F0;
	sub_824E0430(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0430
	ctx.lr = 0x827BA3F8;
	sub_824E0430(ctx, base);
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

__attribute__((alias("__imp__sub_827BA40C"))) PPC_WEAK_FUNC(sub_827BA40C);
PPC_FUNC_IMPL(__imp__sub_827BA40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA410"))) PPC_WEAK_FUNC(sub_827BA410);
PPC_FUNC_IMPL(__imp__sub_827BA410) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-9840
	r31.s64 = r11.s64 + -9840;
	// addi r3,r31,180
	ctx.r3.s64 = r31.s64 + 180;
	// bl 0x824e0430
	ctx.lr = 0x827BA430;
	sub_824E0430(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0430
	ctx.lr = 0x827BA438;
	sub_824E0430(ctx, base);
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

__attribute__((alias("__imp__sub_827BA44C"))) PPC_WEAK_FUNC(sub_827BA44C);
PPC_FUNC_IMPL(__imp__sub_827BA44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA450"))) PPC_WEAK_FUNC(sub_827BA450);
PPC_FUNC_IMPL(__imp__sub_827BA450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r3,r11,-8296
	ctx.r3.s64 = r11.s64 + -8296;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA45C"))) PPC_WEAK_FUNC(sub_827BA45C);
PPC_FUNC_IMPL(__imp__sub_827BA45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA460"))) PPC_WEAK_FUNC(sub_827BA460);
PPC_FUNC_IMPL(__imp__sub_827BA460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r3,r11,-5856
	ctx.r3.s64 = r11.s64 + -5856;
	// b 0x823877f8
	sub_823877F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA46C"))) PPC_WEAK_FUNC(sub_827BA46C);
PPC_FUNC_IMPL(__imp__sub_827BA46C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA470"))) PPC_WEAK_FUNC(sub_827BA470);
PPC_FUNC_IMPL(__imp__sub_827BA470) {
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
	ctx.lr = 0x827BA478;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r11,r11,-13520
	r11.s64 = r11.s64 + -13520;
	// lhz r31,6(r11)
	r31.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827ba4bc
	if (cr6.eq) goto loc_827BA4BC;
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x827ba4b4
	if (!cr6.gt) goto loc_827BA4B4;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_827BA4A0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x827BA4A8;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x827ba4a0
	if (!cr0.eq) goto loc_827BA4A0;
loc_827BA4B4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x827BA4BC;
	sub_82130588(ctx, base);
loc_827BA4BC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827BA4C4"))) PPC_WEAK_FUNC(sub_827BA4C4);
PPC_FUNC_IMPL(__imp__sub_827BA4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA4C8"))) PPC_WEAK_FUNC(sub_827BA4C8);
PPC_FUNC_IMPL(__imp__sub_827BA4C8) {
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
	ctx.lr = 0x827BA4D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r11,r11,-12648
	r11.s64 = r11.s64 + -12648;
	// lhz r31,6(r11)
	r31.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827ba514
	if (cr6.eq) goto loc_827BA514;
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x827ba50c
	if (!cr6.gt) goto loc_827BA50C;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_827BA4F8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238a288
	ctx.lr = 0x827BA500;
	sub_8238A288(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// bne 0x827ba4f8
	if (!cr0.eq) goto loc_827BA4F8;
loc_827BA50C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x827BA514;
	sub_82130588(ctx, base);
loc_827BA514:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827BA51C"))) PPC_WEAK_FUNC(sub_827BA51C);
PPC_FUNC_IMPL(__imp__sub_827BA51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA520"))) PPC_WEAK_FUNC(sub_827BA520);
PPC_FUNC_IMPL(__imp__sub_827BA520) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r11,r11,-12120
	r11.s64 = r11.s64 + -12120;
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

__attribute__((alias("__imp__sub_827BA53C"))) PPC_WEAK_FUNC(sub_827BA53C);
PPC_FUNC_IMPL(__imp__sub_827BA53C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA540"))) PPC_WEAK_FUNC(sub_827BA540);
PPC_FUNC_IMPL(__imp__sub_827BA540) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r11,r11,-12168
	r11.s64 = r11.s64 + -12168;
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

__attribute__((alias("__imp__sub_827BA55C"))) PPC_WEAK_FUNC(sub_827BA55C);
PPC_FUNC_IMPL(__imp__sub_827BA55C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA560"))) PPC_WEAK_FUNC(sub_827BA560);
PPC_FUNC_IMPL(__imp__sub_827BA560) {
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
	// addi r31,r11,-12188
	r31.s64 = r11.s64 + -12188;
	// lwz r11,-12188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827ba5a0
	if (cr6.eq) goto loc_827BA5A0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x827BA58C;
	sub_82130588(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827ba5a0
	if (cr6.eq) goto loc_827BA5A0;
	// addi r3,r11,-4
	ctx.r3.s64 = r11.s64 + -4;
	// bl 0x82130588
	ctx.lr = 0x827BA5A0;
	sub_82130588(ctx, base);
loc_827BA5A0:
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

__attribute__((alias("__imp__sub_827BA5B4"))) PPC_WEAK_FUNC(sub_827BA5B4);
PPC_FUNC_IMPL(__imp__sub_827BA5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA5B8"))) PPC_WEAK_FUNC(sub_827BA5B8);
PPC_FUNC_IMPL(__imp__sub_827BA5B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,-12036
	ctx.r3.s64 = r11.s64 + -12036;
	// b 0x82608de8
	sub_82608DE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA5C4"))) PPC_WEAK_FUNC(sub_827BA5C4);
PPC_FUNC_IMPL(__imp__sub_827BA5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA5C8"))) PPC_WEAK_FUNC(sub_827BA5C8);
PPC_FUNC_IMPL(__imp__sub_827BA5C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,-12016
	ctx.r3.s64 = r11.s64 + -12016;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA5D4"))) PPC_WEAK_FUNC(sub_827BA5D4);
PPC_FUNC_IMPL(__imp__sub_827BA5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA5D8"))) PPC_WEAK_FUNC(sub_827BA5D8);
PPC_FUNC_IMPL(__imp__sub_827BA5D8) {
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
	// addi r31,r11,-10744
	r31.s64 = r11.s64 + -10744;
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827ba604
	if (cr6.eq) goto loc_827BA604;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x827BA604;
	sub_82130588(ctx, base);
loc_827BA604:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a6030
	ctx.lr = 0x827BA60C;
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

__attribute__((alias("__imp__sub_827BA620"))) PPC_WEAK_FUNC(sub_827BA620);
PPC_FUNC_IMPL(__imp__sub_827BA620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r11,r11,-4368
	r11.s64 = r11.s64 + -4368;
	// stw r11,-15672(r10)
	PPC_STORE_U32(ctx.r10.u32 + -15672, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA634"))) PPC_WEAK_FUNC(sub_827BA634);
PPC_FUNC_IMPL(__imp__sub_827BA634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA638"))) PPC_WEAK_FUNC(sub_827BA638);
PPC_FUNC_IMPL(__imp__sub_827BA638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r11,r11,-4368
	r11.s64 = r11.s64 + -4368;
	// stw r11,-15640(r10)
	PPC_STORE_U32(ctx.r10.u32 + -15640, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA64C"))) PPC_WEAK_FUNC(sub_827BA64C);
PPC_FUNC_IMPL(__imp__sub_827BA64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA650"))) PPC_WEAK_FUNC(sub_827BA650);
PPC_FUNC_IMPL(__imp__sub_827BA650) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r11,r11,6704
	r11.s64 = r11.s64 + 6704;
	// stw r11,-15548(r10)
	PPC_STORE_U32(ctx.r10.u32 + -15548, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA664"))) PPC_WEAK_FUNC(sub_827BA664);
PPC_FUNC_IMPL(__imp__sub_827BA664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA668"))) PPC_WEAK_FUNC(sub_827BA668);
PPC_FUNC_IMPL(__imp__sub_827BA668) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA66C"))) PPC_WEAK_FUNC(sub_827BA66C);
PPC_FUNC_IMPL(__imp__sub_827BA66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA670"))) PPC_WEAK_FUNC(sub_827BA670);
PPC_FUNC_IMPL(__imp__sub_827BA670) {
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
	// lwz r3,2220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2220);
	// bl 0x821c9158
	ctx.lr = 0x827BA690;
	sub_821C9158(ctx, base);
	// lwz r3,2224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2224);
	// bl 0x821c9158
	ctx.lr = 0x827BA698;
	sub_821C9158(ctx, base);
	// addi r3,r31,2176
	ctx.r3.s64 = r31.s64 + 2176;
	// bl 0x82130000
	ctx.lr = 0x827BA6A0;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_827BA6B4"))) PPC_WEAK_FUNC(sub_827BA6B4);
PPC_FUNC_IMPL(__imp__sub_827BA6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA6B8"))) PPC_WEAK_FUNC(sub_827BA6B8);
PPC_FUNC_IMPL(__imp__sub_827BA6B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r11,r11,19324
	r11.s64 = r11.s64 + 19324;
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

__attribute__((alias("__imp__sub_827BA6D4"))) PPC_WEAK_FUNC(sub_827BA6D4);
PPC_FUNC_IMPL(__imp__sub_827BA6D4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA6D8"))) PPC_WEAK_FUNC(sub_827BA6D8);
PPC_FUNC_IMPL(__imp__sub_827BA6D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19332
	ctx.r3.s64 = r11.s64 + 19332;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA6E4"))) PPC_WEAK_FUNC(sub_827BA6E4);
PPC_FUNC_IMPL(__imp__sub_827BA6E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA6E8"))) PPC_WEAK_FUNC(sub_827BA6E8);
PPC_FUNC_IMPL(__imp__sub_827BA6E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19356
	ctx.r3.s64 = r11.s64 + 19356;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA6F4"))) PPC_WEAK_FUNC(sub_827BA6F4);
PPC_FUNC_IMPL(__imp__sub_827BA6F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA6F8"))) PPC_WEAK_FUNC(sub_827BA6F8);
PPC_FUNC_IMPL(__imp__sub_827BA6F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19380
	ctx.r3.s64 = r11.s64 + 19380;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA704"))) PPC_WEAK_FUNC(sub_827BA704);
PPC_FUNC_IMPL(__imp__sub_827BA704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA708"))) PPC_WEAK_FUNC(sub_827BA708);
PPC_FUNC_IMPL(__imp__sub_827BA708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19404
	ctx.r3.s64 = r11.s64 + 19404;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA714"))) PPC_WEAK_FUNC(sub_827BA714);
PPC_FUNC_IMPL(__imp__sub_827BA714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA718"))) PPC_WEAK_FUNC(sub_827BA718);
PPC_FUNC_IMPL(__imp__sub_827BA718) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19428
	ctx.r3.s64 = r11.s64 + 19428;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA724"))) PPC_WEAK_FUNC(sub_827BA724);
PPC_FUNC_IMPL(__imp__sub_827BA724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA728"))) PPC_WEAK_FUNC(sub_827BA728);
PPC_FUNC_IMPL(__imp__sub_827BA728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19452
	ctx.r3.s64 = r11.s64 + 19452;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA734"))) PPC_WEAK_FUNC(sub_827BA734);
PPC_FUNC_IMPL(__imp__sub_827BA734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA738"))) PPC_WEAK_FUNC(sub_827BA738);
PPC_FUNC_IMPL(__imp__sub_827BA738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19476
	ctx.r3.s64 = r11.s64 + 19476;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA744"))) PPC_WEAK_FUNC(sub_827BA744);
PPC_FUNC_IMPL(__imp__sub_827BA744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA748"))) PPC_WEAK_FUNC(sub_827BA748);
PPC_FUNC_IMPL(__imp__sub_827BA748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19500
	ctx.r3.s64 = r11.s64 + 19500;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA754"))) PPC_WEAK_FUNC(sub_827BA754);
PPC_FUNC_IMPL(__imp__sub_827BA754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA758"))) PPC_WEAK_FUNC(sub_827BA758);
PPC_FUNC_IMPL(__imp__sub_827BA758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19524
	ctx.r3.s64 = r11.s64 + 19524;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA764"))) PPC_WEAK_FUNC(sub_827BA764);
PPC_FUNC_IMPL(__imp__sub_827BA764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA768"))) PPC_WEAK_FUNC(sub_827BA768);
PPC_FUNC_IMPL(__imp__sub_827BA768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19548
	ctx.r3.s64 = r11.s64 + 19548;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA774"))) PPC_WEAK_FUNC(sub_827BA774);
PPC_FUNC_IMPL(__imp__sub_827BA774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA778"))) PPC_WEAK_FUNC(sub_827BA778);
PPC_FUNC_IMPL(__imp__sub_827BA778) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19572
	ctx.r3.s64 = r11.s64 + 19572;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA784"))) PPC_WEAK_FUNC(sub_827BA784);
PPC_FUNC_IMPL(__imp__sub_827BA784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA788"))) PPC_WEAK_FUNC(sub_827BA788);
PPC_FUNC_IMPL(__imp__sub_827BA788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19596
	ctx.r3.s64 = r11.s64 + 19596;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA794"))) PPC_WEAK_FUNC(sub_827BA794);
PPC_FUNC_IMPL(__imp__sub_827BA794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA798"))) PPC_WEAK_FUNC(sub_827BA798);
PPC_FUNC_IMPL(__imp__sub_827BA798) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,20356
	r11.s64 = r11.s64 + 20356;
	// lhz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA7B4"))) PPC_WEAK_FUNC(sub_827BA7B4);
PPC_FUNC_IMPL(__imp__sub_827BA7B4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA7B8"))) PPC_WEAK_FUNC(sub_827BA7B8);
PPC_FUNC_IMPL(__imp__sub_827BA7B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,20368
	r11.s64 = r11.s64 + 20368;
	// lhz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA7D4"))) PPC_WEAK_FUNC(sub_827BA7D4);
PPC_FUNC_IMPL(__imp__sub_827BA7D4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA7D8"))) PPC_WEAK_FUNC(sub_827BA7D8);
PPC_FUNC_IMPL(__imp__sub_827BA7D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,19852
	ctx.r3.s64 = r11.s64 + 19852;
	// b 0x824fa9b0
	sub_824FA9B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827BA7E4"))) PPC_WEAK_FUNC(sub_827BA7E4);
PPC_FUNC_IMPL(__imp__sub_827BA7E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827BA7E8"))) PPC_WEAK_FUNC(sub_827BA7E8);
PPC_FUNC_IMPL(__imp__sub_827BA7E8) {
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
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20296(r31)
	PPC_STORE_U32(r31.u32 + 20296, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BA814;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BA81C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20296(r31)
	PPC_STORE_U32(r31.u32 + 20296, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA840"))) PPC_WEAK_FUNC(sub_827BA840);
PPC_FUNC_IMPL(__imp__sub_827BA840) {
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
	// addi r30,r31,20168
	r30.s64 = r31.s64 + 20168;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20168(r31)
	PPC_STORE_U32(r31.u32 + 20168, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BA86C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BA874;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20168(r31)
	PPC_STORE_U32(r31.u32 + 20168, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA898"))) PPC_WEAK_FUNC(sub_827BA898);
PPC_FUNC_IMPL(__imp__sub_827BA898) {
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
	// addi r30,r31,20104
	r30.s64 = r31.s64 + 20104;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20104(r31)
	PPC_STORE_U32(r31.u32 + 20104, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BA8C4;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BA8CC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20104(r31)
	PPC_STORE_U32(r31.u32 + 20104, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA8F0"))) PPC_WEAK_FUNC(sub_827BA8F0);
PPC_FUNC_IMPL(__imp__sub_827BA8F0) {
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
	// addi r30,r31,19944
	r30.s64 = r31.s64 + 19944;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,19944(r31)
	PPC_STORE_U32(r31.u32 + 19944, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BA91C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BA924;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,19944(r31)
	PPC_STORE_U32(r31.u32 + 19944, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA948"))) PPC_WEAK_FUNC(sub_827BA948);
PPC_FUNC_IMPL(__imp__sub_827BA948) {
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
	// addi r30,r31,20232
	r30.s64 = r31.s64 + 20232;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20232(r31)
	PPC_STORE_U32(r31.u32 + 20232, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BA974;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BA97C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20232(r31)
	PPC_STORE_U32(r31.u32 + 20232, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA9A0"))) PPC_WEAK_FUNC(sub_827BA9A0);
PPC_FUNC_IMPL(__imp__sub_827BA9A0) {
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
	// addi r30,r31,19912
	r30.s64 = r31.s64 + 19912;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,19912(r31)
	PPC_STORE_U32(r31.u32 + 19912, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BA9CC;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BA9D4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,19912(r31)
	PPC_STORE_U32(r31.u32 + 19912, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BA9F8"))) PPC_WEAK_FUNC(sub_827BA9F8);
PPC_FUNC_IMPL(__imp__sub_827BA9F8) {
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
	// addi r30,r31,20008
	r30.s64 = r31.s64 + 20008;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20008(r31)
	PPC_STORE_U32(r31.u32 + 20008, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BAA24;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAA2C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20008(r31)
	PPC_STORE_U32(r31.u32 + 20008, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAA50"))) PPC_WEAK_FUNC(sub_827BAA50);
PPC_FUNC_IMPL(__imp__sub_827BAA50) {
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
	// addi r30,r31,19880
	r30.s64 = r31.s64 + 19880;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,19880(r31)
	PPC_STORE_U32(r31.u32 + 19880, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BAA7C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAA84;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,19880(r31)
	PPC_STORE_U32(r31.u32 + 19880, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAAA8"))) PPC_WEAK_FUNC(sub_827BAAA8);
PPC_FUNC_IMPL(__imp__sub_827BAAA8) {
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
	// addi r30,r31,20136
	r30.s64 = r31.s64 + 20136;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20136(r31)
	PPC_STORE_U32(r31.u32 + 20136, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BAAD4;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAADC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20136(r31)
	PPC_STORE_U32(r31.u32 + 20136, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAB00"))) PPC_WEAK_FUNC(sub_827BAB00);
PPC_FUNC_IMPL(__imp__sub_827BAB00) {
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
	// addi r30,r31,20072
	r30.s64 = r31.s64 + 20072;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20072(r31)
	PPC_STORE_U32(r31.u32 + 20072, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BAB2C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAB34;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20072(r31)
	PPC_STORE_U32(r31.u32 + 20072, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAB58"))) PPC_WEAK_FUNC(sub_827BAB58);
PPC_FUNC_IMPL(__imp__sub_827BAB58) {
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
	// addi r30,r31,20040
	r30.s64 = r31.s64 + 20040;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20040(r31)
	PPC_STORE_U32(r31.u32 + 20040, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BAB84;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAB8C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20040(r31)
	PPC_STORE_U32(r31.u32 + 20040, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BABB0"))) PPC_WEAK_FUNC(sub_827BABB0);
PPC_FUNC_IMPL(__imp__sub_827BABB0) {
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
	// addi r30,r31,20200
	r30.s64 = r31.s64 + 20200;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20200(r31)
	PPC_STORE_U32(r31.u32 + 20200, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BABDC;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BABE4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20200(r31)
	PPC_STORE_U32(r31.u32 + 20200, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAC08"))) PPC_WEAK_FUNC(sub_827BAC08);
PPC_FUNC_IMPL(__imp__sub_827BAC08) {
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
	// addi r30,r31,19976
	r30.s64 = r31.s64 + 19976;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,19976(r31)
	PPC_STORE_U32(r31.u32 + 19976, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BAC34;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAC3C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,19976(r31)
	PPC_STORE_U32(r31.u32 + 19976, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAC60"))) PPC_WEAK_FUNC(sub_827BAC60);
PPC_FUNC_IMPL(__imp__sub_827BAC60) {
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
	// addi r30,r31,20264
	r30.s64 = r31.s64 + 20264;
	// addi r11,r11,-7912
	r11.s64 = r11.s64 + -7912;
	// stw r11,20264(r31)
	PPC_STORE_U32(r31.u32 + 20264, r11.u32);
	// bl 0x824827b0
	ctx.lr = 0x827BAC8C;
	sub_824827B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAC94;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,20264(r31)
	PPC_STORE_U32(r31.u32 + 20264, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BACB8"))) PPC_WEAK_FUNC(sub_827BACB8);
PPC_FUNC_IMPL(__imp__sub_827BACB8) {
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
	// addi r31,r11,20720
	r31.s64 = r11.s64 + 20720;
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827bace4
	if (cr6.eq) goto loc_827BACE4;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x827BACE4;
	sub_82130588(ctx, base);
loc_827BACE4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a6030
	ctx.lr = 0x827BACEC;
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

__attribute__((alias("__imp__sub_827BAD00"))) PPC_WEAK_FUNC(sub_827BAD00);
PPC_FUNC_IMPL(__imp__sub_827BAD00) {
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
	// addi r30,r31,22380
	r30.s64 = r31.s64 + 22380;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22380(r31)
	PPC_STORE_U32(r31.u32 + 22380, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BAD2C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAD34;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22380(r31)
	PPC_STORE_U32(r31.u32 + 22380, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAD58"))) PPC_WEAK_FUNC(sub_827BAD58);
PPC_FUNC_IMPL(__imp__sub_827BAD58) {
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
	// addi r30,r31,22508
	r30.s64 = r31.s64 + 22508;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22508(r31)
	PPC_STORE_U32(r31.u32 + 22508, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BAD84;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAD8C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22508(r31)
	PPC_STORE_U32(r31.u32 + 22508, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BADB0"))) PPC_WEAK_FUNC(sub_827BADB0);
PPC_FUNC_IMPL(__imp__sub_827BADB0) {
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
	// addi r30,r31,22092
	r30.s64 = r31.s64 + 22092;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22092(r31)
	PPC_STORE_U32(r31.u32 + 22092, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BADDC;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BADE4;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22092(r31)
	PPC_STORE_U32(r31.u32 + 22092, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAE08"))) PPC_WEAK_FUNC(sub_827BAE08);
PPC_FUNC_IMPL(__imp__sub_827BAE08) {
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
	// addi r30,r31,22476
	r30.s64 = r31.s64 + 22476;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22476(r31)
	PPC_STORE_U32(r31.u32 + 22476, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BAE34;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAE3C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22476(r31)
	PPC_STORE_U32(r31.u32 + 22476, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAE60"))) PPC_WEAK_FUNC(sub_827BAE60);
PPC_FUNC_IMPL(__imp__sub_827BAE60) {
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
	// addi r30,r31,22412
	r30.s64 = r31.s64 + 22412;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22412(r31)
	PPC_STORE_U32(r31.u32 + 22412, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BAE8C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAE94;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22412(r31)
	PPC_STORE_U32(r31.u32 + 22412, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAEB8"))) PPC_WEAK_FUNC(sub_827BAEB8);
PPC_FUNC_IMPL(__imp__sub_827BAEB8) {
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
	// addi r30,r31,22156
	r30.s64 = r31.s64 + 22156;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22156(r31)
	PPC_STORE_U32(r31.u32 + 22156, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BAEE4;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAEEC;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22156(r31)
	PPC_STORE_U32(r31.u32 + 22156, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAF10"))) PPC_WEAK_FUNC(sub_827BAF10);
PPC_FUNC_IMPL(__imp__sub_827BAF10) {
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
	// addi r30,r31,22316
	r30.s64 = r31.s64 + 22316;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22316(r31)
	PPC_STORE_U32(r31.u32 + 22316, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BAF3C;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAF44;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22316(r31)
	PPC_STORE_U32(r31.u32 + 22316, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827BAF68"))) PPC_WEAK_FUNC(sub_827BAF68);
PPC_FUNC_IMPL(__imp__sub_827BAF68) {
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
	// addi r30,r31,22028
	r30.s64 = r31.s64 + 22028;
	// addi r11,r11,-964
	r11.s64 = r11.s64 + -964;
	// stw r11,22028(r31)
	PPC_STORE_U32(r31.u32 + 22028, r11.u32);
	// bl 0x82273a60
	ctx.lr = 0x827BAF94;
	sub_82273A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824fa710
	ctx.lr = 0x827BAF9C;
	sub_824FA710(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,-1028
	r11.s64 = r11.s64 + -1028;
	// stw r11,22028(r31)
	PPC_STORE_U32(r31.u32 + 22028, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

