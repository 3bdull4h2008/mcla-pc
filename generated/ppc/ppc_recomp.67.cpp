#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_823B1FD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B1FD0) {
	__imp__sub_823B1FD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B1FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B1FE4) {
	__imp__sub_823B1FE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B1FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B1FE8) {
	__imp__sub_823B1FE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B1FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B1FFC) {
	__imp__sub_823B1FFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-5
	r11.s64 = r11.s64 + -5;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2000) {
	__imp__sub_823B2000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2014) {
	__imp__sub_823B2014(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-6
	r11.s64 = r11.s64 + -6;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2018) {
	__imp__sub_823B2018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B202C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B202C) {
	__imp__sub_823B202C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-7
	r11.s64 = r11.s64 + -7;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2030) {
	__imp__sub_823B2030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2044) {
	__imp__sub_823B2044(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2048) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2048) {
	__imp__sub_823B2048(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B205C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B205C) {
	__imp__sub_823B205C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-9
	r11.s64 = r11.s64 + -9;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2060) {
	__imp__sub_823B2060(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2074) {
	__imp__sub_823B2074(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2078) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-10
	r11.s64 = r11.s64 + -10;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2078) {
	__imp__sub_823B2078(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B208C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B208C) {
	__imp__sub_823B208C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-11
	r11.s64 = r11.s64 + -11;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2090) {
	__imp__sub_823B2090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B20A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B20A4) {
	__imp__sub_823B20A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B20A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-13
	r11.s64 = r11.s64 + -13;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B20A8) {
	__imp__sub_823B20A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B20BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B20BC) {
	__imp__sub_823B20BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B20C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-17
	r11.s64 = r11.s64 + -17;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B20C0) {
	__imp__sub_823B20C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B20D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B20D4) {
	__imp__sub_823B20D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B20D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-18
	r11.s64 = r11.s64 + -18;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B20D8) {
	__imp__sub_823B20D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B20EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B20EC) {
	__imp__sub_823B20EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B20F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b2110
	if (!cr6.eq) goto loc_823B2110;
	// rlwinm r11,r11,29,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x823b2114
	if (cr6.eq) goto loc_823B2114;
loc_823B2110:
	// li r11,1
	r11.s64 = 1;
loc_823B2114:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B20F0) {
	__imp__sub_823B20F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B211C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B211C) {
	__imp__sub_823B211C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2120) {
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
	// bl 0x823b7570
	ctx.lr = 0x823B2138;
	sub_823B7570(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-32544
	ctx.r9.s64 = ctx.r10.s64 + -32544;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
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

PPC_WEAK_FUNC(sub_823B2120) {
	__imp__sub_823B2120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B218C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B218C) {
	__imp__sub_823B218C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2190) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-32544
	ctx.r10.s64 = r11.s64 + -32544;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b7a18
	ctx.lr = 0x823B21BC;
	sub_823B7A18(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b21d4
	if (cr6.eq) goto loc_823B21D4;
	// bl 0x82130588
	ctx.lr = 0x823B21D0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823B21D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2190) {
	__imp__sub_823B2190(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B21EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B21EC) {
	__imp__sub_823B21EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B21F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B21F0) {
	__imp__sub_823B21F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B21FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B21FC) {
	__imp__sub_823B21FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r3,5(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2200) {
	__imp__sub_823B2200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B220C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B220C) {
	__imp__sub_823B220C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r3,6(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2210) {
	__imp__sub_823B2210(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B221C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B221C) {
	__imp__sub_823B221C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2220) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f0,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,29964(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29964);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x823b225c
	if (cr6.gt) goto loc_823B225C;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blelr cr6
	if (!cr6.gt) return;
loc_823B225C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2220) {
	__imp__sub_823B2220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2264) {
	__imp__sub_823B2264(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2268) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,32668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32668);
	f0.f64 = double(temp.f32);
	// lfs f13,148(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b22d4
	if (!cr6.gt) goto loc_823B22D4;
	// rotlwi r11,r3,0
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b22d4
	if (!cr6.lt) goto loc_823B22D4;
	// bl 0x823a3d60
	ctx.lr = 0x823B22B4;
	sub_823A3D60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b22d4
	if (!cr6.eq) goto loc_823B22D4;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r10,49(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b22d8
	if (cr6.eq) goto loc_823B22D8;
loc_823B22D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B22D8:
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

PPC_WEAK_FUNC(sub_823B2268) {
	__imp__sub_823B2268(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B22EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B22EC) {
	__imp__sub_823B22EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B22F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,16,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b233c
	if (cr6.eq) goto loc_823B233C;
	// rlwinm r9,r10,21,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823b233c
	if (!cr6.eq) goto loc_823B233C;
	// lbz r9,49(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823b233c
	if (!cr6.eq) goto loc_823B233C;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,9(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b233c
	if (cr6.eq) goto loc_823B233C;
	// rlwinm r11,r10,14,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B233C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B22F0) {
	__imp__sub_823B22F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2344) {
	__imp__sub_823B2344(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2348) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,16,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b2394
	if (cr6.eq) goto loc_823B2394;
	// rlwinm r9,r10,21,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b2394
	if (cr6.eq) goto loc_823B2394;
	// lbz r9,49(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823b2394
	if (!cr6.eq) goto loc_823B2394;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,9(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b2394
	if (cr6.eq) goto loc_823B2394;
	// rlwinm r11,r10,14,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B2394:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2348) {
	__imp__sub_823B2348(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B239C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B239C) {
	__imp__sub_823B239C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B23A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,18,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b23e0
	if (cr6.eq) goto loc_823B23E0;
	// lbz r9,49(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823b23e0
	if (!cr6.eq) goto loc_823B23E0;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,9(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b23e0
	if (cr6.eq) goto loc_823B23E0;
	// rlwinm r11,r10,14,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B23E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B23A0) {
	__imp__sub_823B23A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B23E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B23E8) {
	__imp__sub_823B23E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B240C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B240C) {
	__imp__sub_823B240C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2410) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b2478
	if (!cr6.lt) goto loc_823B2478;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b2478
	if (cr6.eq) goto loc_823B2478;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,148(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b2478
	if (!cr6.gt) goto loc_823B2478;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b2478
	if (!cr6.lt) goto loc_823B2478;
	// lbz r11,49(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B2478:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2410) {
	__imp__sub_823B2410(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2480) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f0,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,29964(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29964);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b24e8
	if (!cr6.lt) goto loc_823B24E8;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x823b24e8
	if (!cr6.lt) goto loc_823B24E8;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b24e8
	if (!cr6.lt) goto loc_823B24E8;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,148(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
loc_823B24E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2480) {
	__imp__sub_823B2480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B24F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,23,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b2524
	if (cr6.eq) goto loc_823B2524;
	// lbz r10,49(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b2524
	if (!cr6.eq) goto loc_823B2524;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r10,9(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_823B2524:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B24F0) {
	__imp__sub_823B24F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B252C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B252C) {
	__imp__sub_823B252C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b25c8
	if (!cr6.gt) goto loc_823B25C8;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lfs f13,76(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x823b256c
	if (cr6.lt) goto loc_823B256C;
	// lfs f13,152(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b25c8
	if (!cr6.gt) goto loc_823B25C8;
loc_823B256C:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b25c8
	if (!cr6.gt) goto loc_823B25C8;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-6172(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6172);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b25c8
	if (!cr6.lt) goto loc_823B25C8;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-32524(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -32524);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b25c8
	if (!cr6.lt) goto loc_823B25C8;
	// lbz r10,49(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b25c8
	if (!cr6.eq) goto loc_823B25C8;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_823B25C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2530) {
	__imp__sub_823B2530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B25D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b2668
	if (!cr6.gt) goto loc_823B2668;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lfs f13,76(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x823b260c
	if (cr6.lt) goto loc_823B260C;
	// lfs f13,152(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b2668
	if (!cr6.gt) goto loc_823B2668;
loc_823B260C:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b2668
	if (!cr6.gt) goto loc_823B2668;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-6172(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6172);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b2668
	if (!cr6.lt) goto loc_823B2668;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,32680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b2668
	if (!cr6.gt) goto loc_823B2668;
	// lbz r10,49(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b2668
	if (!cr6.eq) goto loc_823B2668;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_823B2668:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B25D0) {
	__imp__sub_823B25D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2670) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x823b2688
	if (cr6.eq) goto loc_823B2688;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x823b26d0
	if (!cr6.eq) goto loc_823B26D0;
loc_823B2688:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x823b26d0
	if (cr6.lt) goto loc_823B26D0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,148(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b26d0
	if (!cr6.gt) goto loc_823B26D0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,7(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b26d0
	if (cr6.eq) goto loc_823B26D0;
	// lbz r11,49(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B26D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2670) {
	__imp__sub_823B2670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B26D8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-1684(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1684);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b2708
	if (!cr6.gt) goto loc_823B2708;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bltlr cr6
	if (cr6.lt) return;
loc_823B2708:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B26D8) {
	__imp__sub_823B26D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2710) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfs f13,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-32524(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -32524);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x823b2740
	if (cr6.gt) goto loc_823B2740;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgelr cr6
	if (!cr6.lt) return;
loc_823B2740:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2710) {
	__imp__sub_823B2710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2748) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,25724(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 25724);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2748) {
	__imp__sub_823B2748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B276C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B276C) {
	__imp__sub_823B276C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2770) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// bl 0x823a7158
	ctx.lr = 0x823B2784;
	sub_823A7158(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,28636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28636);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x823b279c
	if (cr6.lt) goto loc_823B279C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B279C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2770) {
	__imp__sub_823B2770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B27AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B27AC) {
	__imp__sub_823B27AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B27B0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-31392(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31392);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b27e0
	if (!cr6.lt) goto loc_823B27E0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bltlr cr6
	if (cr6.lt) return;
loc_823B27E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B27B0) {
	__imp__sub_823B27B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B27E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,32680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x823b2818
	if (cr6.lt) goto loc_823B2818;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgelr cr6
	if (!cr6.lt) return;
loc_823B2818:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B27E8) {
	__imp__sub_823B27E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2820) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2820) {
	__imp__sub_823B2820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2844) {
	__imp__sub_823B2844(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2848) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lfs f13,148(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x823b288c
	if (cr6.lt) goto loc_823B288C;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823b288c
	if (!cr6.eq) goto loc_823B288C;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x823b28ac
	if (cr6.lt) goto loc_823B28AC;
loc_823B288C:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,16,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b28ac
	if (!cr6.eq) goto loc_823B28AC;
	// rlwinm r11,r11,18,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B28AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2848) {
	__imp__sub_823B2848(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B28B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B28B4) {
	__imp__sub_823B28B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B28B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r9,r11,16,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b28f8
	if (cr6.eq) goto loc_823B28F8;
	// rlwinm r9,r11,21,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823b28f8
	if (!cr6.eq) goto loc_823B28F8;
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lbz r9,9(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b28f8
	if (cr6.eq) goto loc_823B28F8;
	// rlwinm r11,r11,14,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B28F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B28B8) {
	__imp__sub_823B28B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r9,r11,16,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b2940
	if (cr6.eq) goto loc_823B2940;
	// rlwinm r9,r11,21,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b2940
	if (cr6.eq) goto loc_823B2940;
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lbz r9,9(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b2940
	if (cr6.eq) goto loc_823B2940;
	// rlwinm r11,r11,14,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B2940:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2900) {
	__imp__sub_823B2900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2948) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,18,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b297c
	if (cr6.eq) goto loc_823B297C;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,9(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b297c
	if (cr6.eq) goto loc_823B297C;
	// rlwinm r11,r10,14,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B297C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2948) {
	__imp__sub_823B2948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2984) {
	__imp__sub_823B2984(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2988) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2988) {
	__imp__sub_823B2988(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B29AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B29AC) {
	__imp__sub_823B29AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B29B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,3,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823b29dc
	if (!cr6.eq) goto loc_823B29DC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blelr cr6
	if (!cr6.gt) return;
loc_823B29DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B29B0) {
	__imp__sub_823B29B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B29E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B29E4) {
	__imp__sub_823B29E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B29E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823B2A14;
	sub_823A3558(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,29436
	ctx.r4.s64 = ctx.r9.s64 + 29436;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,156(r8)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 156, temp.u32);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b7890
	ctx.lr = 0x823B2A38;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823B2A44;
	sub_823A5E30(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,-32520
	ctx.r4.s64 = ctx.r7.s64 + -32520;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B2A58;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x823a5c10
	ctx.lr = 0x823B2A70;
	sub_823A5C10(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823a4b68
	ctx.lr = 0x823B2A7C;
	sub_823A4B68(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r6,44(r31)
	PPC_STORE_U8(r31.u32 + 44, ctx.r6.u8);
	// stb r5,45(r31)
	PPC_STORE_U8(r31.u32 + 45, ctx.r5.u8);
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

PPC_WEAK_FUNC(sub_823B29E8) {
	__imp__sub_823B29E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2AA8) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,28956
	ctx.r4.s64 = r11.s64 + 28956;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b78f0
	ctx.lr = 0x823B2AD0;
	sub_823B78F0(ctx, base);
	// stw r3,104(r30)
	PPC_STORE_U32(r30.u32 + 104, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r10,-32520
	ctx.r4.s64 = ctx.r10.s64 + -32520;
	// bl 0x823b87d8
	ctx.lr = 0x823B2AE8;
	sub_823B87D8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B2B04;
	sub_823A5C10(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,148(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// lfs f2,11368(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11368);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3b90
	ctx.lr = 0x823B2B28;
	sub_823A3B90(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2AA8) {
	__imp__sub_823B2AA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2B40) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,28956
	ctx.r4.s64 = r11.s64 + 28956;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b78f0
	ctx.lr = 0x823B2B68;
	sub_823B78F0(ctx, base);
	// stw r3,104(r30)
	PPC_STORE_U32(r30.u32 + 104, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r10,-32520
	ctx.r4.s64 = ctx.r10.s64 + -32520;
	// bl 0x823b87d8
	ctx.lr = 0x823B2B80;
	sub_823B87D8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B2B9C;
	sub_823A5C10(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,148(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// lfs f2,11368(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11368);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3b90
	ctx.lr = 0x823B2BC0;
	sub_823A3B90(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r4,r5,8
	ctx.r4.u64 = ctx.r5.u64 | 8;
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2B40) {
	__imp__sub_823B2B40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2BE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823B2C0C;
	sub_823A5E30(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-32504
	ctx.r4.s64 = r11.s64 + -32504;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B2C20;
	sub_823B87D8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B2C3C;
	sub_823A5C10(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2BE8) {
	__imp__sub_823B2BE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2C54) {
	__imp__sub_823B2C54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2C58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r4,r11,-32496
	ctx.r4.s64 = r11.s64 + -32496;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B2C84;
	sub_823B87D8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B2CA0;
	sub_823A5C10(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a6ee0
	ctx.lr = 0x823B2CB4;
	sub_823A6EE0(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,76(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823B2CC4;
	sub_823A3558(ctx, base);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,148(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 148, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2C58) {
	__imp__sub_823B2C58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2CE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,72(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// b 0x823a3558
	sub_823A3558(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B2CE8) {
	__imp__sub_823B2CE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2CF8) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x823a6e58
	ctx.lr = 0x823B2D34;
	sub_823A6E58(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r7,r8,25,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x823b2d54
	if (!cr6.eq) goto loc_823B2D54;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
loc_823B2D54:
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

PPC_WEAK_FUNC(sub_823B2CF8) {
	__imp__sub_823B2CF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2D68) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r4,r9,-32504
	ctx.r4.s64 = ctx.r9.s64 + -32504;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stfs f0,156(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 156, temp.u32);
	// bl 0x823b87d8
	ctx.lr = 0x823B2DA0;
	sub_823B87D8(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,-29232(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B2DBC;
	sub_823A5C10(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6e58
	ctx.lr = 0x823B2DCC;
	sub_823A6E58(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,14192(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6ee0
	ctx.lr = 0x823B2DDC;
	sub_823A6EE0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2D68) {
	__imp__sub_823B2D68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2DF4) {
	__imp__sub_823B2DF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2DF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f0
	ctx.lr = 0x823B2E00;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r4,r11,-32396
	ctx.r4.s64 = r11.s64 + -32396;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B2E18;
	sub_823B87D8(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r10,-32420
	ctx.r4.s64 = ctx.r10.s64 + -32420;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B2E2C;
	sub_823B87D8(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r9,-32432
	ctx.r4.s64 = ctx.r9.s64 + -32432;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B2E40;
	sub_823B87D8(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r8,-32456
	ctx.r4.s64 = ctx.r8.s64 + -32456;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B2E54;
	sub_823B87D8(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r4,r7,-32480
	ctx.r4.s64 = ctx.r7.s64 + -32480;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B2E68;
	sub_823B87D8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lfs f1,12424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12424);
	ctx.f1.f64 = double(temp.f32);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x823a5f60
	ctx.lr = 0x823B2E90;
	sub_823A5F60(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_823B2DF8) {
	__imp__sub_823B2DF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2EA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r9,r10,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2EA8) {
	__imp__sub_823B2EA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2EBC) {
	__imp__sub_823B2EBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2EC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f0,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 + f31.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x823a4b98
	ctx.lr = 0x823B2F08;
	sub_823A4B98(ctx, base);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,20124(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 20124);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,96(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f12,20120(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 20120);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f11,27640(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 27640);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fsel f7,f8,f8,f0
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsel f6,f8,f8,f0
	ctx.f6.f64 = ctx.f8.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsubs f5,f7,f31
	ctx.f5.f64 = double(float(ctx.f7.f64 - f31.f64));
	// fsel f4,f5,f31,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? f31.f64 : ctx.f6.f64;
	// fmadds f1,f4,f11,f31
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + f31.f64));
	// bl 0x823a6f38
	ctx.lr = 0x823B2F54;
	sub_823A6F38(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B2EC0) {
	__imp__sub_823B2EC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B2F6C) {
	__imp__sub_823B2F6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2F70) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// lfs f2,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// stfs f0,148(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 148, temp.u32);
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f0,152(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 152, temp.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x823a3b90
	ctx.lr = 0x823B2FBC;
	sub_823A3B90(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r4,r5,32
	ctx.r4.u64 = ctx.r5.u64 | 32;
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
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

PPC_WEAK_FUNC(sub_823B2F70) {
	__imp__sub_823B2F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B2FE0) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823B2FE8;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d4
	ctx.lr = 0x823B2FF0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r28,1
	r28.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lfs f27,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f27.f64 = double(temp.f32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f30,96(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	f30.f64 = double(temp.f32);
	// beq cr6,0x823b3050
	if (cr6.eq) goto loc_823B3050;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823b3050
	if (cr6.eq) goto loc_823B3050;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823b3050
	if (cr6.eq) goto loc_823B3050;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B3044;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f27.f64);
	// ble cr6,0x823b3050
	if (!cr6.gt) goto loc_823B3050;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_823B3050:
	// lwz r9,108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r10,28956
	r30.s64 = ctx.r10.s64 + 28956;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823b307c
	if (!cr6.eq) goto loc_823B307C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b78f0
	ctx.lr = 0x823B3074;
	sub_823B78F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r28,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r28.u32);
loc_823B307C:
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// lfs f28,20124(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20124);
	f28.f64 = double(temp.f32);
	// beq cr6,0x823b3110
	if (cr6.eq) goto loc_823B3110;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// beq cr6,0x823b30d0
	if (cr6.eq) goto loc_823B30D0;
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823b3160
	if (!cr6.eq) goto loc_823B3160;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b3160
	if (!cr6.eq) goto loc_823B3160;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-32356(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32356);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bgt cr6,0x823b3148
	if (cr6.gt) goto loc_823B3148;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823b78f0
	ctx.lr = 0x823B30C8;
	sub_823B78F0(ctx, base);
	// stw r28,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r28.u32);
	// b 0x823b315c
	goto loc_823B315C;
loc_823B30D0:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b30f4
	if (cr6.eq) goto loc_823B30F4;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29016
	ctx.r4.s64 = r11.s64 + 29016;
	// bl 0x823b78f0
	ctx.lr = 0x823B30EC;
	sub_823B78F0(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x823b3158
	goto loc_823B3158;
loc_823B30F4:
	// fcmpu cr6,f30,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f28.f64);
	// bge cr6,0x823b3160
	if (!cr6.lt) goto loc_823B3160;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b78f0
	ctx.lr = 0x823B3108;
	sub_823B78F0(ctx, base);
	// stw r28,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r28.u32);
	// b 0x823b315c
	goto loc_823B315C;
loc_823B3110:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b3134
	if (cr6.eq) goto loc_823B3134;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29016
	ctx.r4.s64 = r11.s64 + 29016;
	// bl 0x823b78f0
	ctx.lr = 0x823B312C;
	sub_823B78F0(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x823b3158
	goto loc_823B3158;
loc_823B3134:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfs f0,-32356(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -32356);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// ble cr6,0x823b3160
	if (!cr6.gt) goto loc_823B3160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823B3148:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,28996
	ctx.r4.s64 = r11.s64 + 28996;
	// bl 0x823b78f0
	ctx.lr = 0x823B3154;
	sub_823B78F0(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
loc_823B3158:
	// stw r10,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r10.u32);
loc_823B315C:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_823B3160:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f29,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f29.f64 = double(temp.f32);
	// beq cr6,0x823b31c8
	if (cr6.eq) goto loc_823B31C8;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r9,-32372
	r30.s64 = ctx.r9.s64 + -32372;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r11.u32);
	// lwz r29,32(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B3190;
	sub_823B87D8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B31A0;
	sub_823B87D8(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5e50
	ctx.lr = 0x823B31BC;
	sub_823A5E50(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x823a6ee0
	ctx.lr = 0x823B31C8;
	sub_823A6EE0(ctx, base);
loc_823B31C8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,49(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b31e8
	if (cr6.eq) goto loc_823B31E8;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// b 0x823b3204
	goto loc_823B3204;
loc_823B31E8:
	// fsubs f13,f30,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f30.f64 - f28.f64));
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lfs f0,20120(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20120);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fsel f11,f12,f12,f29
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f29.f64;
	// fsubs f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fsel f1,f10,f31,f11
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? f31.f64 : ctx.f11.f64;
loc_823B3204:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a4b38
	ctx.lr = 0x823B320C;
	sub_823A4B38(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f0,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fadds f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 + f31.f64));
	// fmuls f1,f11,f27
	ctx.f1.f64 = double(float(ctx.f11.f64 * f27.f64));
	// bl 0x823a6fc0
	ctx.lr = 0x823B322C;
	sub_823A6FC0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,-11304(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11304);
	f0.f64 = double(temp.f32);
	// lfs f10,128(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 128);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// ble cr6,0x823b3260
	if (!cr6.gt) goto loc_823B3260;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f0,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// lfs f13,-11624(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11624);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,56(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stfs f13,60(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// b 0x823b3274
	goto loc_823B3274;
loc_823B3260:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f0,68(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,64(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stfs f0,60(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
loc_823B3274:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,32692(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32692);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823b3294
	if (!cr6.lt) goto loc_823B3294;
	// stfs f29,152(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
loc_823B3294:
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,108(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823b32b4
	if (!cr6.eq) goto loc_823B32B4;
	// lwz r11,112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x823b32b8
	if (cr6.eq) goto loc_823B32B8;
loc_823B32B4:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823B32B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b32f8
	if (!cr6.eq) goto loc_823B32F8;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-13148(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823b32f8
	if (!cr6.gt) goto loc_823B32F8;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29436
	ctx.r4.s64 = r11.s64 + 29436;
	// bl 0x823b7890
	ctx.lr = 0x823B32EC;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823B32F8;
	sub_823A5E30(ctx, base);
loc_823B32F8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b3318
	if (cr6.eq) goto loc_823B3318;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
loc_823B3318:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba20
	ctx.lr = 0x823B3324;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_823B2FE0) {
	__imp__sub_823B2FE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3328) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r4,r11,-32352
	ctx.r4.s64 = r11.s64 + -32352;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B3350;
	sub_823B87D8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B336C;
	sub_823A5C10(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,84(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823B337C;
	sub_823A3558(ctx, base);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,104(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 56, temp.u32);
	// stfs f0,60(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 60, temp.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6ee0
	ctx.lr = 0x823B33A4;
	sub_823A6EE0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3328) {
	__imp__sub_823B3328(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B33BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B33BC) {
	__imp__sub_823B33BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B33C0) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r4,r11,-32332
	ctx.r4.s64 = r11.s64 + -32332;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B33E8;
	sub_823B87D8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B3404;
	sub_823A5C10(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,84(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823B3414;
	sub_823A3558(ctx, base);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,104(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 56, temp.u32);
	// stfs f0,60(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 60, temp.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6ee0
	ctx.lr = 0x823B343C;
	sub_823A6EE0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B33C0) {
	__imp__sub_823B33C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B3454) {
	__imp__sub_823B3454(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3458) {
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
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,72(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823B347C;
	sub_823A3558(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lfs f0,68(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,64(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 56, temp.u32);
	// stfs f0,60(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 60, temp.u32);
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

PPC_WEAK_FUNC(sub_823B3458) {
	__imp__sub_823B3458(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B34A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fsel f11,f12,f12,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsel f10,f12,f12,f13
	ctx.f10.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// lfs f9,96(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsubs f7,f11,f0
	ctx.f7.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f6,f7,f0,f10
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f0.f64 : ctx.f10.f64;
	// fsubs f5,f6,f9
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f9.f64));
	// fdivs f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 / ctx.f8.f64));
	// fsel f3,f4,f4,f13
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// fsel f2,f4,f4,f13
	ctx.f2.f64 = ctx.f4.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// fsubs f1,f3,f0
	ctx.f1.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsel f1,f1,f0,f2
	ctx.f1.f64 = ctx.f1.f64 >= 0.0 ? f0.f64 : ctx.f2.f64;
	// b 0x823a6e58
	sub_823A6E58(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B34A8) {
	__imp__sub_823B34A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B34FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B34FC) {
	__imp__sub_823B34FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3500) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,84(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823B3528;
	sub_823A3558(ctx, base);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-32352
	ctx.r4.s64 = ctx.r10.s64 + -32352;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lfs f0,112(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 112);
	f0.f64 = double(temp.f32);
	// lfs f13,108(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 56, temp.u32);
	// stfs f0,60(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 60, temp.u32);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B3554;
	sub_823B87D8(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B3570;
	sub_823A5C10(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6ee0
	ctx.lr = 0x823B3580;
	sub_823A6EE0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3500) {
	__imp__sub_823B3500(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3598) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,84(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823B35C0;
	sub_823A3558(ctx, base);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-32332
	ctx.r4.s64 = ctx.r10.s64 + -32332;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lfs f0,112(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 112);
	f0.f64 = double(temp.f32);
	// lfs f13,108(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 56, temp.u32);
	// stfs f0,60(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 60, temp.u32);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B35EC;
	sub_823B87D8(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B3608;
	sub_823A5C10(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6ee0
	ctx.lr = 0x823B3618;
	sub_823A6EE0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3598) {
	__imp__sub_823B3598(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3630) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f11,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f12,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f9,96(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsel f7,f10,f11,f12
	ctx.f7.f64 = ctx.f10.f64 >= 0.0 ? ctx.f11.f64 : ctx.f12.f64;
	// fsel f6,f7,f13,f7
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f7.f64;
	// fneg f5,f6
	ctx.f5.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// fsubs f4,f5,f9
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f9.f64));
	// fdivs f3,f4,f8
	ctx.f3.f64 = double(float(ctx.f4.f64 / ctx.f8.f64));
	// fsel f2,f3,f3,f13
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f3.f64 : ctx.f13.f64;
	// fsel f1,f3,f3,f13
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f3.f64 : ctx.f13.f64;
	// fsubs f13,f2,f0
	ctx.f13.f64 = double(float(ctx.f2.f64 - f0.f64));
	// fsel f1,f13,f0,f1
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f1.f64;
	// b 0x823a6e58
	sub_823A6E58(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B3630) {
	__imp__sub_823B3630(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B368C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B368C) {
	__imp__sub_823B368C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f0
	ctx.lr = 0x823B3698;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r10,-32216
	ctx.r4.s64 = ctx.r10.s64 + -32216;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f0,120(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,116(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stfs f0,60(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B36C8;
	sub_823B87D8(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-32240
	ctx.r4.s64 = ctx.r8.s64 + -32240;
	// bl 0x823b87d8
	ctx.lr = 0x823B36DC;
	sub_823B87D8(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,-32264
	ctx.r4.s64 = ctx.r7.s64 + -32264;
	// bl 0x823b87d8
	ctx.lr = 0x823B36F0;
	sub_823B87D8(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-32288
	ctx.r4.s64 = ctx.r6.s64 + -32288;
	// bl 0x823b87d8
	ctx.lr = 0x823B3704;
	sub_823B87D8(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r4,r5,-32312
	ctx.r4.s64 = ctx.r5.s64 + -32312;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B3718;
	sub_823B87D8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lfs f1,12424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12424);
	ctx.f1.f64 = double(temp.f32);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x823a5f60
	ctx.lr = 0x823B3740;
	sub_823A5F60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_823B3690) {
	__imp__sub_823B3690(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f0
	ctx.lr = 0x823B3750;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r10,-32096
	ctx.r4.s64 = ctx.r10.s64 + -32096;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f0,120(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,116(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stfs f0,60(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B3780;
	sub_823B87D8(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-32120
	ctx.r4.s64 = ctx.r8.s64 + -32120;
	// bl 0x823b87d8
	ctx.lr = 0x823B3794;
	sub_823B87D8(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,-32144
	ctx.r4.s64 = ctx.r7.s64 + -32144;
	// bl 0x823b87d8
	ctx.lr = 0x823B37A8;
	sub_823B87D8(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-32168
	ctx.r4.s64 = ctx.r6.s64 + -32168;
	// bl 0x823b87d8
	ctx.lr = 0x823B37BC;
	sub_823B87D8(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r4,r5,-32192
	ctx.r4.s64 = ctx.r5.s64 + -32192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B37D0;
	sub_823B87D8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lfs f1,12424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12424);
	ctx.f1.f64 = double(temp.f32);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x823a5f60
	ctx.lr = 0x823B37F8;
	sub_823A5F60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_823B3748) {
	__imp__sub_823B3748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f0,68(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,64(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stfs f0,60(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3800) {
	__imp__sub_823B3800(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B381C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B381C) {
	__imp__sub_823B381C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f11,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fsel f9,f10,f11,f13
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f11.f64 : ctx.f13.f64;
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsel f7,f8,f0,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// fadds f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 + f0.f64));
	// fmuls f1,f6,f12
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// b 0x823a4b98
	sub_823A4B98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B3820) {
	__imp__sub_823B3820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3860) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,29016
	ctx.r4.s64 = r11.s64 + 29016;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b78f0
	ctx.lr = 0x823B3888;
	sub_823B78F0(ctx, base);
	// stw r3,104(r30)
	PPC_STORE_U32(r30.u32 + 104, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r10,-32072
	ctx.r4.s64 = ctx.r10.s64 + -32072;
	// bl 0x823b87d8
	ctx.lr = 0x823B38A0;
	sub_823B87D8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B38BC;
	sub_823A5C10(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6ee0
	ctx.lr = 0x823B38CC;
	sub_823A6EE0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3860) {
	__imp__sub_823B3860(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B38E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B38E4) {
	__imp__sub_823B38E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B38E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lfs f0,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fmuls f1,f11,f13
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// b 0x823a6e58
	sub_823A6E58(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B38E8) {
	__imp__sub_823B38E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3918) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,28996
	ctx.r4.s64 = r11.s64 + 28996;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b78f0
	ctx.lr = 0x823B3940;
	sub_823B78F0(ctx, base);
	// stw r3,104(r30)
	PPC_STORE_U32(r30.u32 + 104, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r10,28368
	ctx.r4.s64 = ctx.r10.s64 + 28368;
	// bl 0x823b87d8
	ctx.lr = 0x823B3958;
	sub_823B87D8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,12424(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B3974;
	sub_823A5C10(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6ee0
	ctx.lr = 0x823B3984;
	sub_823A6EE0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3918) {
	__imp__sub_823B3918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B399C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B399C) {
	__imp__sub_823B399C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B39A0) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a7368
	ctx.lr = 0x823B39BC;
	sub_823A7368(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// rlwinm r11,r9,5,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0x1;
	// ble cr6,0x823b39fc
	if (!cr6.gt) goto loc_823B39FC;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b39fc
	if (cr6.eq) goto loc_823B39FC;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// bl 0x823a6e58
	ctx.lr = 0x823B39F0;
	sub_823A6E58(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// b 0x823b3a10
	goto loc_823B3A10;
loc_823B39FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b3a18
	if (!cr6.eq) goto loc_823B3A18;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
loc_823B3A10:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6ee0
	ctx.lr = 0x823B3A18;
	sub_823A6EE0(ctx, base);
loc_823B3A18:
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

PPC_WEAK_FUNC(sub_823B39A0) {
	__imp__sub_823B39A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B3A2C) {
	__imp__sub_823B3A2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r4,r11,-32052
	ctx.r4.s64 = r11.s64 + -32052;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B3A58;
	sub_823B87D8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B3A74;
	sub_823A5C10(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r8,r9,4
	ctx.r8.u64 = ctx.r9.u64 | 4;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3A30) {
	__imp__sub_823B3A30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B3A9C) {
	__imp__sub_823B3A9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,29016
	ctx.r4.s64 = r11.s64 + 29016;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b78f0
	ctx.lr = 0x823B3AC8;
	sub_823B78F0(ctx, base);
	// stw r3,104(r30)
	PPC_STORE_U32(r30.u32 + 104, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r10,-32040
	ctx.r4.s64 = ctx.r10.s64 + -32040;
	// bl 0x823b87d8
	ctx.lr = 0x823B3AE0;
	sub_823B87D8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B3AFC;
	sub_823A5C10(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r7,r8,4
	ctx.r7.u64 = ctx.r8.u64 | 4;
	// stw r7,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r7.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3AA0) {
	__imp__sub_823B3AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B3B24) {
	__imp__sub_823B3B24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r9,0,30,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stfs f0,156(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 156, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3B28) {
	__imp__sub_823B3B28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B3B4C) {
	__imp__sub_823B3B4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3B50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r9,0,30,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stfs f0,156(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 156, temp.u32);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// rlwinm r5,r6,7,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,40(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// b 0x823bb7b0
	sub_823BB7B0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B3B50) {
	__imp__sub_823B3B50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3B90) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3B90) {
	__imp__sub_823B3B90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B3B94) {
	__imp__sub_823B3B94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3B98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r30,1
	r30.s64 = 1;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stfs f0,156(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 156, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b3c20
	if (cr6.eq) goto loc_823B3C20;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b3bf4
	if (cr6.eq) goto loc_823B3BF4;
	// lwz r10,592(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823b3bf4
	if (cr6.eq) goto loc_823B3BF4;
	// li r30,0
	r30.s64 = 0;
loc_823B3BF4:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b3c20
	if (cr6.eq) goto loc_823B3C20;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b3c20
	if (cr6.eq) goto loc_823B3C20;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B3C20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823B3C20:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b3c40
	if (cr6.eq) goto loc_823B3C40;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r4,r11,-32028
	ctx.r4.s64 = r11.s64 + -32028;
	// b 0x823b3c48
	goto loc_823B3C48;
loc_823B3C40:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,22112
	ctx.r4.s64 = r11.s64 + 22112;
loc_823B3C48:
	// bl 0x823b87d8
	ctx.lr = 0x823B3C4C;
	sub_823B87D8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B3C68;
	sub_823A5C10(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3B98) {
	__imp__sub_823B3B98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3C80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,156(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 156, temp.u32);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r8,r9,7,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,40(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// b 0x823bb7b0
	sub_823BB7B0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B3C80) {
	__imp__sub_823B3C80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3CB0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3CB0) {
	__imp__sub_823B3CB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B3CB4) {
	__imp__sub_823B3CB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r9,0,30,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r6,28(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stfs f0,156(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 156, temp.u32);
	// lwz r11,48(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_823B3CB8) {
	__imp__sub_823B3CB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3D08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B3D08) {
	__imp__sub_823B3D08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B3D0C) {
	__imp__sub_823B3D0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3D10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823B3D30;
	sub_823A5E30(ctx, base);
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r31,32(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823abb68
	ctx.lr = 0x823B3D40;
	sub_823ABB68(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823B3D5C;
	sub_823A5C10(ctx, base);
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

PPC_WEAK_FUNC(sub_823B3D10) {
	__imp__sub_823B3D10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B3D70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r27{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823B3D78;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823B3D90;
	sub_823A5E30(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x822a86e8
	ctx.lr = 0x823B3D98;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b3dbc
	if (cr6.eq) goto loc_823B3DBC;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x822a88d8
	ctx.lr = 0x823B3DAC;
	sub_822A88D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b3dc0
	if (!cr6.eq) goto loc_823B3DC0;
loc_823B3DBC:
	// li r5,0
	ctx.r5.s64 = 0;
loc_823B3DC0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r30,0
	r30.s64 = 0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,19
	cr6.compare<uint32_t>(r11.u32, 19, xer);
	// bgt cr6,0x823b404c
	if (cr6.gt) goto loc_823B404C;
	// lis r12,-32197
	r12.s64 = -2110062592;
	// addi r12,r12,15852
	r12.s64 = r12.s64 + 15852;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,15932(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 15932);
	// lwz r17,15952(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 15952);
	// lwz r17,15972(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 15972);
	// lwz r17,15992(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 15992);
	// lwz r17,16012(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16012);
	// lwz r17,16032(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16032);
	// lwz r17,16052(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16052);
	// lwz r17,16072(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16072);
	// lwz r17,16096(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16096);
	// lwz r17,16120(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16120);
	// lwz r17,16144(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16144);
	// lwz r17,16168(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16168);
	// lwz r17,16216(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16216);
	// lwz r17,16192(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16192);
	// lwz r17,16460(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16460);
	// lwz r17,16240(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16240);
	// lwz r17,16460(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16460);
	// lwz r17,16288(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16288);
	// lwz r17,16308(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16308);
	// lwz r17,16332(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 16332);
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823ab860
	ctx.lr = 0x823B3E48;
	sub_823AB860(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// addi r4,r31,72
	ctx.r4.s64 = r31.s64 + 72;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823ab958
	ctx.lr = 0x823B3E5C;
	sub_823AB958(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// addi r4,r31,76
	ctx.r4.s64 = r31.s64 + 76;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823ab9c0
	ctx.lr = 0x823B3E70;
	sub_823AB9C0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823aba28
	ctx.lr = 0x823B3E84;
	sub_823ABA28(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823aba78
	ctx.lr = 0x823B3E98;
	sub_823ABA78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823abac8
	ctx.lr = 0x823B3EAC;
	sub_823ABAC8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// addi r4,r31,92
	ctx.r4.s64 = r31.s64 + 92;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823abb18
	ctx.lr = 0x823B3EC0;
	sub_823ABB18(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b4054
	goto loc_823B4054;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22536
	ctx.r4.s64 = r11.s64 + 22536;
	// bl 0x823b87d8
	ctx.lr = 0x823B3ED8;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22516
	ctx.r4.s64 = r11.s64 + 22516;
	// bl 0x823b87d8
	ctx.lr = 0x823B3EF0;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22068
	ctx.r4.s64 = r11.s64 + 22068;
	// bl 0x823b87d8
	ctx.lr = 0x823B3F08;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,21964
	ctx.r4.s64 = r11.s64 + 21964;
	// bl 0x823b87d8
	ctx.lr = 0x823B3F20;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,23512
	ctx.r4.s64 = r11.s64 + 23512;
	// bl 0x823b87d8
	ctx.lr = 0x823B3F38;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,23556
	ctx.r4.s64 = r11.s64 + 23556;
	// bl 0x823b87d8
	ctx.lr = 0x823B3F50;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,21924
	ctx.r4.s64 = r11.s64 + 21924;
	// bl 0x823b87d8
	ctx.lr = 0x823B3F68;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,28996
	ctx.r4.s64 = r11.s64 + 28996;
	// bl 0x823b78f0
	ctx.lr = 0x823B3F84;
	sub_823B78F0(ctx, base);
	// stw r3,104(r30)
	PPC_STORE_U32(r30.u32 + 104, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,29052
	ctx.r4.s64 = ctx.r10.s64 + 29052;
	// bl 0x823b87d8
	ctx.lr = 0x823B3F98;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// addi r4,r31,100
	ctx.r4.s64 = r31.s64 + 100;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823abbb8
	ctx.lr = 0x823B3FAC;
	sub_823ABBB8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,28868
	ctx.r4.s64 = r11.s64 + 28868;
	// bl 0x823b87d8
	ctx.lr = 0x823B3FC4;
	sub_823B87D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823b406c
	goto loc_823B406C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,22476
	ctx.r4.s64 = ctx.r9.s64 + 22476;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stw r10,300(r11)
	PPC_STORE_U32(r11.u32 + 300, ctx.r10.u32);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823B3FF0;
	sub_823B87D8(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f31,-29232(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a5c98
	ctx.lr = 0x823B4010;
	sub_823A5C98(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,29544
	ctx.r4.s64 = ctx.r7.s64 + 29544;
	// addi r3,r6,29464
	ctx.r3.s64 = ctx.r6.s64 + 29464;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r31,32(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823bf2f0
	ctx.lr = 0x823B402C;
	sub_823BF2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x823a7ca8
	ctx.lr = 0x823B4040;
	sub_823A7CA8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_823B404C:
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bne cr6,0x823b40c8
	if (!cr6.eq) goto loc_823B40C8;
loc_823B4054:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r29,32(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,28920
	ctx.r4.s64 = r11.s64 + 28920;
	// bl 0x823b78f0
	ctx.lr = 0x823B4068;
	sub_823B78F0(ctx, base);
	// stw r3,104(r29)
	PPC_STORE_U32(r29.u32 + 104, ctx.r3.u32);
loc_823B406C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b40c8
	if (cr6.eq) goto loc_823B40C8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f31,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a5c10
	ctx.lr = 0x823B4094;
	sub_823A5C10(ctx, base);
	// lbz r10,45(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 45);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b40c8
	if (cr6.eq) goto loc_823B40C8;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-32012
	ctx.r4.s64 = r11.s64 + -32012;
	// bl 0x823b87d8
	ctx.lr = 0x823B40B4;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x823a7ca8
	ctx.lr = 0x823B40C8;
	sub_823A7CA8(ctx, base);
loc_823B40C8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B3D70) {
	__imp__sub_823B3D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B40D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B40D4) {
	__imp__sub_823B40D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B40D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,29436
	ctx.r4.s64 = r11.s64 + 29436;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b7890
	ctx.lr = 0x823B4104;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823B4110;
	sub_823A5E30(ctx, base);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r10,104(r7)
	PPC_STORE_U32(ctx.r7.u32 + 104, ctx.r10.u32);
	// lwz r11,-10000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r6,300(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 300);
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// bne cr6,0x823b4168
	if (!cr6.eq) goto loc_823B4168;
	// stw r10,300(r11)
	PPC_STORE_U32(r11.u32 + 300, ctx.r10.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r11,-32520
	ctx.r4.s64 = r11.s64 + -32520;
	// bl 0x823b87d8
	ctx.lr = 0x823B4150;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x823a5c10
	ctx.lr = 0x823B4168;
	sub_823A5C10(ctx, base);
loc_823B4168:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x822a9090
	ctx.lr = 0x823B4170;
	sub_822A9090(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r11,20
	r11.s64 = 20;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,148(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 148, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B40D8) {
	__imp__sub_823B40D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B41A0) {
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
	ctx.lr = 0x823B41A8;
	// stwu r1,-2864(r1)
	ea = -2864 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32197
	r11.s64 = -2110062592;
	// addi r10,r11,8688
	ctx.r10.s64 = r11.s64 + 8688;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B41C4;
	sub_82130000(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2112
	ctx.r3.s64 = ctx.r1.s64 + 2112;
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,-31484
	ctx.r4.s64 = ctx.r9.s64 + -31484;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B41E0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B41EC;
	sub_823BA7F8(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lwz r3,2120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2120);
	// addi r30,r8,29432
	r30.s64 = ctx.r8.s64 + 29432;
	// stw r30,2112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2112, r30.u32);
	// bl 0x82130588
	ctx.lr = 0x823B4200;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,8704
	ctx.r6.s64 = ctx.r7.s64 + 8704;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4214;
	sub_82130000(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1472
	ctx.r3.s64 = ctx.r1.s64 + 1472;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,-31524
	ctx.r4.s64 = ctx.r5.s64 + -31524;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4230;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B423C;
	sub_823BA7F8(ctx, base);
	// stw r30,1472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1472, r30.u32);
	// lwz r3,1480(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1480);
	// bl 0x82130588
	ctx.lr = 0x823B4248;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,8720
	r11.s64 = ctx.r4.s64 + 8720;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B425C;
	sub_82130000(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,-31548
	ctx.r4.s64 = ctx.r10.s64 + -31548;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4278;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4284;
	sub_823BA7F8(ctx, base);
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r30.u32);
	// lwz r3,200(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// bl 0x82130588
	ctx.lr = 0x823B4290;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-16480
	ctx.r8.s64 = ctx.r9.s64 + -16480;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B42A4;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2624
	ctx.r3.s64 = ctx.r1.s64 + 2624;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30972
	ctx.r4.s64 = ctx.r7.s64 + 30972;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B42C0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B42CC;
	sub_823BA7F8(ctx, base);
	// stw r30,2624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2624, r30.u32);
	// lwz r3,2632(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2632);
	// bl 0x82130588
	ctx.lr = 0x823B42D8;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-16464
	ctx.r5.s64 = ctx.r6.s64 + -16464;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B42EC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r4,30952
	ctx.r4.s64 = ctx.r4.s64 + 30952;
	// bl 0x823b9e00
	ctx.lr = 0x823B4308;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4314;
	sub_823BA7F8(ctx, base);
	// stw r30,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r30.u32);
	// lwz r3,264(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// bl 0x82130588
	ctx.lr = 0x823B4320;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16448
	ctx.r10.s64 = r11.s64 + -16448;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4334;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1536
	ctx.r3.s64 = ctx.r1.s64 + 1536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30932
	ctx.r4.s64 = ctx.r9.s64 + 30932;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4350;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B435C;
	sub_823BA7F8(ctx, base);
	// stw r30,1536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1536, r30.u32);
	// lwz r3,1544(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1544);
	// bl 0x82130588
	ctx.lr = 0x823B4368;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-17328
	ctx.r7.s64 = ctx.r8.s64 + -17328;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B437C;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30912
	ctx.r4.s64 = ctx.r6.s64 + 30912;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4398;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B43A4;
	sub_823BA7F8(ctx, base);
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r30.u32);
	// lwz r3,328(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	// bl 0x82130588
	ctx.lr = 0x823B43B0;
	sub_82130588(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,14928
	ctx.r4.s64 = ctx.r5.s64 + 14928;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B43C4;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2176
	ctx.r3.s64 = ctx.r1.s64 + 2176;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30856
	ctx.r4.s64 = r11.s64 + 30856;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B43E0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B43EC;
	sub_823BA7F8(ctx, base);
	// stw r30,2176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2176, r30.u32);
	// lwz r3,2184(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2184);
	// bl 0x82130588
	ctx.lr = 0x823B43F8;
	sub_82130588(ctx, base);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,14976
	ctx.r9.s64 = ctx.r10.s64 + 14976;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B440C;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30840
	ctx.r4.s64 = ctx.r8.s64 + 30840;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4428;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4434;
	sub_823BA7F8(ctx, base);
	// stw r30,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, r30.u32);
	// lwz r3,392(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 392);
	// bl 0x82130588
	ctx.lr = 0x823B4440;
	sub_82130588(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,15048
	ctx.r6.s64 = ctx.r7.s64 + 15048;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4454;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1600
	ctx.r3.s64 = ctx.r1.s64 + 1600;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30820
	ctx.r4.s64 = ctx.r5.s64 + 30820;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4470;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B447C;
	sub_823BA7F8(ctx, base);
	// stw r30,1600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1600, r30.u32);
	// lwz r3,1608(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1608);
	// bl 0x82130588
	ctx.lr = 0x823B4488;
	sub_82130588(ctx, base);
	// lis r4,-32198
	ctx.r4.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,15120
	r11.s64 = ctx.r4.s64 + 15120;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B449C;
	sub_82130000(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30800
	ctx.r4.s64 = ctx.r10.s64 + 30800;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B44B8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B44C4;
	sub_823BA7F8(ctx, base);
	// stw r30,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, r30.u32);
	// lwz r3,456(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 456);
	// bl 0x82130588
	ctx.lr = 0x823B44D0;
	sub_82130588(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,15192
	ctx.r8.s64 = ctx.r9.s64 + 15192;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B44E4;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2496
	ctx.r3.s64 = ctx.r1.s64 + 2496;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30780
	ctx.r4.s64 = ctx.r7.s64 + 30780;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4500;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B450C;
	sub_823BA7F8(ctx, base);
	// stw r30,2496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2496, r30.u32);
	// lwz r3,2504(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2504);
	// bl 0x82130588
	ctx.lr = 0x823B4518;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-16416
	ctx.r5.s64 = ctx.r6.s64 + -16416;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B452C;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,30752
	ctx.r4.s64 = ctx.r4.s64 + 30752;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B4548;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4554;
	sub_823BA7F8(ctx, base);
	// stw r30,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, r30.u32);
	// lwz r3,520(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 520);
	// bl 0x82130588
	ctx.lr = 0x823B4560;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16400
	ctx.r10.s64 = r11.s64 + -16400;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4574;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,1664
	ctx.r3.s64 = ctx.r1.s64 + 1664;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r9,30724
	ctx.r4.s64 = ctx.r9.s64 + 30724;
	// bl 0x823b9c20
	ctx.lr = 0x823B4590;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B459C;
	sub_823BA7F8(ctx, base);
	// stw r30,1664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1664, r30.u32);
	// lwz r3,1672(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1672);
	// bl 0x82130588
	ctx.lr = 0x823B45A8;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-16384
	ctx.r7.s64 = ctx.r8.s64 + -16384;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B45BC;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30696
	ctx.r4.s64 = ctx.r6.s64 + 30696;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B45D8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B45E4;
	sub_823BA7F8(ctx, base);
	// stw r30,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, r30.u32);
	// lwz r3,584(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 584);
	// bl 0x82130588
	ctx.lr = 0x823B45F0;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-16888
	ctx.r4.s64 = ctx.r5.s64 + -16888;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4604;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2240
	ctx.r3.s64 = ctx.r1.s64 + 2240;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30468
	ctx.r4.s64 = r11.s64 + 30468;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4620;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B462C;
	sub_823BA7F8(ctx, base);
	// stw r30,2240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2240, r30.u32);
	// lwz r3,2248(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2248);
	// bl 0x82130588
	ctx.lr = 0x823B4638;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-16872
	ctx.r9.s64 = ctx.r10.s64 + -16872;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B464C;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30448
	ctx.r4.s64 = ctx.r8.s64 + 30448;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4668;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4674;
	sub_823BA7F8(ctx, base);
	// stw r30,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, r30.u32);
	// lwz r3,648(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 648);
	// bl 0x82130588
	ctx.lr = 0x823B4680;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,8080
	ctx.r6.s64 = ctx.r7.s64 + 8080;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4694;
	sub_82130000(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1728
	ctx.r3.s64 = ctx.r1.s64 + 1728;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,-31572
	ctx.r4.s64 = ctx.r5.s64 + -31572;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B46B0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B46BC;
	sub_823BA7F8(ctx, base);
	// stw r30,1728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1728, r30.u32);
	// lwz r3,1736(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1736);
	// bl 0x82130588
	ctx.lr = 0x823B46C8;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-16856
	r11.s64 = ctx.r4.s64 + -16856;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B46DC;
	sub_82130000(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30488
	ctx.r4.s64 = ctx.r10.s64 + 30488;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B46F8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4704;
	sub_823BA7F8(ctx, base);
	// stw r30,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r30.u32);
	// lwz r3,712(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 712);
	// bl 0x82130588
	ctx.lr = 0x823B4710;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,8432
	ctx.r8.s64 = ctx.r9.s64 + 8432;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4724;
	sub_82130000(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2752
	ctx.r3.s64 = ctx.r1.s64 + 2752;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,-31592
	ctx.r4.s64 = ctx.r7.s64 + -31592;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4740;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B474C;
	sub_823BA7F8(ctx, base);
	// stw r30,2752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2752, r30.u32);
	// lwz r3,2760(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2760);
	// bl 0x82130588
	ctx.lr = 0x823B4758;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-16792
	ctx.r5.s64 = ctx.r6.s64 + -16792;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B476C;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,30676
	ctx.r4.s64 = ctx.r4.s64 + 30676;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4788;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4794;
	sub_823BA7F8(ctx, base);
	// stw r30,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, r30.u32);
	// lwz r3,776(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 776);
	// bl 0x82130588
	ctx.lr = 0x823B47A0;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16784
	ctx.r10.s64 = r11.s64 + -16784;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B47B4;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1792
	ctx.r3.s64 = ctx.r1.s64 + 1792;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30656
	ctx.r4.s64 = ctx.r9.s64 + 30656;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B47D0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B47DC;
	sub_823BA7F8(ctx, base);
	// stw r30,1792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1792, r30.u32);
	// lwz r3,1800(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1800);
	// bl 0x82130588
	ctx.lr = 0x823B47E8;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-17248
	ctx.r7.s64 = ctx.r8.s64 + -17248;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B47FC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r6,30640
	ctx.r4.s64 = ctx.r6.s64 + 30640;
	// bl 0x823b9e00
	ctx.lr = 0x823B4818;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4824;
	sub_823BA7F8(ctx, base);
	// stw r30,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, r30.u32);
	// lwz r3,840(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 840);
	// bl 0x82130588
	ctx.lr = 0x823B4830;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-17224
	ctx.r4.s64 = ctx.r5.s64 + -17224;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4844;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2304
	ctx.r3.s64 = ctx.r1.s64 + 2304;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30624
	ctx.r4.s64 = r11.s64 + 30624;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4860;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B486C;
	sub_823BA7F8(ctx, base);
	// stw r30,2304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2304, r30.u32);
	// lwz r3,2312(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2312);
	// bl 0x82130588
	ctx.lr = 0x823B4878;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,8064
	ctx.r9.s64 = ctx.r10.s64 + 8064;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B488C;
	sub_82130000(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,-31608
	ctx.r4.s64 = ctx.r8.s64 + -31608;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B48A8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B48B4;
	sub_823BA7F8(ctx, base);
	// stw r30,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, r30.u32);
	// lwz r3,904(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 904);
	// bl 0x82130588
	ctx.lr = 0x823B48C0;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-17200
	ctx.r6.s64 = ctx.r7.s64 + -17200;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B48D4;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1856
	ctx.r3.s64 = ctx.r1.s64 + 1856;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30512
	ctx.r4.s64 = ctx.r5.s64 + 30512;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B48F0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B48FC;
	sub_823BA7F8(ctx, base);
	// stw r30,1856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1856, r30.u32);
	// lwz r3,1864(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1864);
	// bl 0x82130588
	ctx.lr = 0x823B4908;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,8016
	r11.s64 = ctx.r4.s64 + 8016;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B491C;
	sub_82130000(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,960
	ctx.r3.s64 = ctx.r1.s64 + 960;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,-31628
	ctx.r4.s64 = ctx.r10.s64 + -31628;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4938;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4944;
	sub_823BA7F8(ctx, base);
	// stw r30,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, r30.u32);
	// lwz r3,968(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 968);
	// bl 0x82130588
	ctx.lr = 0x823B4950;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-17184
	ctx.r8.s64 = ctx.r9.s64 + -17184;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4964;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2560
	ctx.r3.s64 = ctx.r1.s64 + 2560;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30536
	ctx.r4.s64 = ctx.r7.s64 + 30536;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4980;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B498C;
	sub_823BA7F8(ctx, base);
	// stw r30,2560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2560, r30.u32);
	// lwz r3,2568(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2568);
	// bl 0x82130588
	ctx.lr = 0x823B4998;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-17168
	ctx.r5.s64 = ctx.r6.s64 + -17168;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B49AC;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1024
	ctx.r3.s64 = ctx.r1.s64 + 1024;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,30524
	ctx.r4.s64 = ctx.r4.s64 + 30524;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B49C8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B49D4;
	sub_823BA7F8(ctx, base);
	// stw r30,1024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1024, r30.u32);
	// lwz r3,1032(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1032);
	// bl 0x82130588
	ctx.lr = 0x823B49E0;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,8032
	ctx.r10.s64 = r11.s64 + 8032;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B49F4;
	sub_82130000(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1920
	ctx.r3.s64 = ctx.r1.s64 + 1920;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,-31644
	ctx.r4.s64 = ctx.r9.s64 + -31644;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4A10;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4A1C;
	sub_823BA7F8(ctx, base);
	// stw r30,1920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1920, r30.u32);
	// lwz r3,1928(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1928);
	// bl 0x82130588
	ctx.lr = 0x823B4A28;
	sub_82130588(ctx, base);
	// lis r8,-32198
	ctx.r8.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,4928
	ctx.r7.s64 = ctx.r8.s64 + 4928;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4A3C;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30396
	ctx.r4.s64 = ctx.r6.s64 + 30396;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4A58;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4A64;
	sub_823BA7F8(ctx, base);
	// stw r30,1088(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1088, r30.u32);
	// lwz r3,1096(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1096);
	// bl 0x82130588
	ctx.lr = 0x823B4A70;
	sub_82130588(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,4944
	ctx.r4.s64 = ctx.r5.s64 + 4944;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4A84;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r3,30376
	ctx.r4.s64 = ctx.r3.s64 + 30376;
	// addi r3,r1,2368
	ctx.r3.s64 = ctx.r1.s64 + 2368;
	// bl 0x823b9e00
	ctx.lr = 0x823B4AA0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4AAC;
	sub_823BA7F8(ctx, base);
	// stw r30,2368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2368, r30.u32);
	// lwz r3,2376(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2376);
	// bl 0x82130588
	ctx.lr = 0x823B4AB8;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16968
	ctx.r10.s64 = r11.s64 + -16968;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4ACC;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1152
	ctx.r3.s64 = ctx.r1.s64 + 1152;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30300
	ctx.r4.s64 = ctx.r9.s64 + 30300;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4AE8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4AF4;
	sub_823BA7F8(ctx, base);
	// stw r30,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, r30.u32);
	// lwz r3,1160(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1160);
	// bl 0x82130588
	ctx.lr = 0x823B4B00;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-16936
	ctx.r7.s64 = ctx.r8.s64 + -16936;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4B14;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1984
	ctx.r3.s64 = ctx.r1.s64 + 1984;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30284
	ctx.r4.s64 = ctx.r6.s64 + 30284;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4B30;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4B3C;
	sub_823BA7F8(ctx, base);
	// stw r30,1984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1984, r30.u32);
	// lwz r3,1992(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1992);
	// bl 0x82130588
	ctx.lr = 0x823B4B48;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-16904
	ctx.r4.s64 = ctx.r5.s64 + -16904;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4B5C;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1216
	ctx.r3.s64 = ctx.r1.s64 + 1216;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30244
	ctx.r4.s64 = r11.s64 + 30244;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4B78;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4B84;
	sub_823BA7F8(ctx, base);
	// stw r30,1216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1216, r30.u32);
	// lwz r3,1224(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1224);
	// bl 0x82130588
	ctx.lr = 0x823B4B90;
	sub_82130588(ctx, base);
	// lis r10,-32140
	ctx.r10.s64 = -2106327040;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,1824
	ctx.r9.s64 = ctx.r10.s64 + 1824;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4BA4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r3,r1,2688
	ctx.r3.s64 = ctx.r1.s64 + 2688;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,-31664
	ctx.r4.s64 = ctx.r8.s64 + -31664;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4BC0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4BCC;
	sub_823BA7F8(ctx, base);
	// stw r30,2688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2688, r30.u32);
	// lwz r3,2696(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2696);
	// bl 0x82130588
	ctx.lr = 0x823B4BD8;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,8096
	ctx.r6.s64 = ctx.r7.s64 + 8096;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4BEC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// addi r3,r1,1280
	ctx.r3.s64 = ctx.r1.s64 + 1280;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,-31680
	ctx.r4.s64 = ctx.r5.s64 + -31680;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4C08;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4C14;
	sub_823BA7F8(ctx, base);
	// stw r30,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, r30.u32);
	// lwz r3,1288(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1288);
	// bl 0x82130588
	ctx.lr = 0x823B4C20;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,8120
	r11.s64 = ctx.r4.s64 + 8120;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4C34;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r3,r1,2048
	ctx.r3.s64 = ctx.r1.s64 + 2048;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,-31696
	ctx.r4.s64 = ctx.r10.s64 + -31696;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4C50;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4C5C;
	sub_823BA7F8(ctx, base);
	// stw r30,2048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2048, r30.u32);
	// lwz r3,2056(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2056);
	// bl 0x82130588
	ctx.lr = 0x823B4C68;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,8144
	ctx.r8.s64 = ctx.r9.s64 + 8144;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4C7C;
	sub_82130000(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1344
	ctx.r3.s64 = ctx.r1.s64 + 1344;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,-31716
	ctx.r4.s64 = ctx.r7.s64 + -31716;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4C98;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4CA4;
	sub_823BA7F8(ctx, base);
	// stw r30,1344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1344, r30.u32);
	// lwz r3,1352(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1352);
	// bl 0x82130588
	ctx.lr = 0x823B4CB0;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,8168
	ctx.r5.s64 = ctx.r6.s64 + 8168;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4CC4;
	sub_82130000(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2432
	ctx.r3.s64 = ctx.r1.s64 + 2432;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,-31736
	ctx.r4.s64 = ctx.r4.s64 + -31736;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4CE0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4CEC;
	sub_823BA7F8(ctx, base);
	// stw r30,2432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2432, r30.u32);
	// lwz r3,2440(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2440);
	// bl 0x82130588
	ctx.lr = 0x823B4CF8;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,8192
	ctx.r10.s64 = r11.s64 + 8192;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4D0C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,1408
	ctx.r3.s64 = ctx.r1.s64 + 1408;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r9,-31752
	ctx.r4.s64 = ctx.r9.s64 + -31752;
	// bl 0x823b9e00
	ctx.lr = 0x823B4D28;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4D34;
	sub_823BA7F8(ctx, base);
	// stw r30,1408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1408, r30.u32);
	// lwz r3,1416(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1416);
	// bl 0x82130588
	ctx.lr = 0x823B4D40;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,8216
	ctx.r7.s64 = ctx.r8.s64 + 8216;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4D54;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r28,r6,-31768
	r28.s64 = ctx.r6.s64 + -31768;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4D74;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4D80;
	sub_823BA7F8(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x82130588
	ctx.lr = 0x823B4D8C;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,8240
	ctx.r4.s64 = ctx.r5.s64 + 8240;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4DA0;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,-31788
	ctx.r4.s64 = r11.s64 + -31788;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4DBC;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4DC8;
	sub_823BA7F8(ctx, base);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x82130588
	ctx.lr = 0x823B4DD4;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,8264
	ctx.r9.s64 = ctx.r10.s64 + 8264;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4DE8;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,-31812
	ctx.r4.s64 = ctx.r8.s64 + -31812;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4E04;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4E10;
	sub_823BA7F8(ctx, base);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// lwz r3,168(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// bl 0x82130588
	ctx.lr = 0x823B4E1C;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,8288
	ctx.r6.s64 = ctx.r7.s64 + 8288;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4E30;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,-31836
	ctx.r4.s64 = ctx.r5.s64 + -31836;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4E4C;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4E58;
	sub_823BA7F8(ctx, base);
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r30.u32);
	// lwz r3,232(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// bl 0x82130588
	ctx.lr = 0x823B4E64;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,8312
	r11.s64 = ctx.r4.s64 + 8312;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4E78;
	sub_82130000(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,-31860
	ctx.r4.s64 = ctx.r10.s64 + -31860;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4E94;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4EA0;
	sub_823BA7F8(ctx, base);
	// stw r30,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r30.u32);
	// lwz r3,296(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	// bl 0x82130588
	ctx.lr = 0x823B4EAC;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,8336
	ctx.r8.s64 = ctx.r9.s64 + 8336;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4EC0;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,-31884
	ctx.r4.s64 = ctx.r7.s64 + -31884;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4EDC;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4EE8;
	sub_823BA7F8(ctx, base);
	// stw r30,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r30.u32);
	// lwz r3,360(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 360);
	// bl 0x82130588
	ctx.lr = 0x823B4EF4;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,8360
	ctx.r5.s64 = ctx.r6.s64 + 8360;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4F08;
	sub_82130000(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,-31904
	ctx.r4.s64 = ctx.r4.s64 + -31904;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4F24;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4F30;
	sub_823BA7F8(ctx, base);
	// stw r30,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r30.u32);
	// lwz r3,424(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 424);
	// bl 0x82130588
	ctx.lr = 0x823B4F3C;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,8216
	ctx.r10.s64 = r11.s64 + 8216;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4F50;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4F68;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4F74;
	sub_823BA7F8(ctx, base);
	// stw r30,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, r30.u32);
	// lwz r3,488(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 488);
	// bl 0x82130588
	ctx.lr = 0x823B4F80;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,8384
	ctx.r8.s64 = ctx.r9.s64 + 8384;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4F94;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r7,-31924
	ctx.r4.s64 = ctx.r7.s64 + -31924;
	// bl 0x823b9e00
	ctx.lr = 0x823B4FB0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B4FBC;
	sub_823BA7F8(ctx, base);
	// stw r30,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, r30.u32);
	// lwz r3,552(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 552);
	// bl 0x82130588
	ctx.lr = 0x823B4FC8;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,8408
	ctx.r5.s64 = ctx.r6.s64 + 8408;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B4FDC;
	sub_82130000(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,-31944
	ctx.r4.s64 = ctx.r4.s64 + -31944;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B4FF8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5004;
	sub_823BA7F8(ctx, base);
	// stw r30,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, r30.u32);
	// lwz r3,616(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 616);
	// bl 0x82130588
	ctx.lr = 0x823B5010;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16816
	ctx.r10.s64 = r11.s64 + -16816;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5024;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,672
	ctx.r3.s64 = ctx.r1.s64 + 672;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30156
	ctx.r4.s64 = ctx.r9.s64 + 30156;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B5040;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B504C;
	sub_823BA7F8(ctx, base);
	// stw r30,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, r30.u32);
	// lwz r3,680(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 680);
	// bl 0x82130588
	ctx.lr = 0x823B5058;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,8048
	ctx.r7.s64 = ctx.r8.s64 + 8048;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B506C;
	sub_82130000(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,-31956
	ctx.r4.s64 = ctx.r6.s64 + -31956;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B5088;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5094;
	sub_823BA7F8(ctx, base);
	// stw r30,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, r30.u32);
	// lwz r3,744(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 744);
	// bl 0x82130588
	ctx.lr = 0x823B50A0;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-17152
	ctx.r4.s64 = ctx.r5.s64 + -17152;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B50B4;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,29588
	ctx.r4.s64 = r11.s64 + 29588;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B50D0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B50DC;
	sub_823BA7F8(ctx, base);
	// stw r30,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, r30.u32);
	// lwz r3,808(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 808);
	// bl 0x82130588
	ctx.lr = 0x823B50E8;
	sub_82130588(ctx, base);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,15712
	ctx.r9.s64 = ctx.r10.s64 + 15712;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B50FC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30892
	ctx.r4.s64 = ctx.r8.s64 + 30892;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B5118;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5124;
	sub_823BA7F8(ctx, base);
	// stw r30,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, r30.u32);
	// lwz r3,872(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 872);
	// bl 0x82130588
	ctx.lr = 0x823B5130;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-16840
	ctx.r6.s64 = ctx.r7.s64 + -16840;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5144;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,928
	ctx.r3.s64 = ctx.r1.s64 + 928;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30872
	ctx.r4.s64 = ctx.r5.s64 + 30872;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B5160;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B516C;
	sub_823BA7F8(ctx, base);
	// stw r30,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, r30.u32);
	// lwz r3,936(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 936);
	// bl 0x82130588
	ctx.lr = 0x823B5178;
	sub_82130588(ctx, base);
	// lis r4,-32198
	ctx.r4.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,4872
	r11.s64 = ctx.r4.s64 + 4872;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B518C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,992
	ctx.r3.s64 = ctx.r1.s64 + 992;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30140
	ctx.r4.s64 = ctx.r10.s64 + 30140;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823B51A8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B51B4;
	sub_823BA7F8(ctx, base);
	// stw r30,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, r30.u32);
	// lwz r3,1000(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1000);
	// bl 0x82130588
	ctx.lr = 0x823B51C0;
	sub_82130588(ctx, base);
	// lis r9,-32222
	ctx.r9.s64 = -2111700992;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-12384
	ctx.r8.s64 = ctx.r9.s64 + -12384;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B51D4;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1056
	ctx.r3.s64 = ctx.r1.s64 + 1056;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30112
	ctx.r4.s64 = ctx.r7.s64 + 30112;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B51F0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B51FC;
	sub_823BA7F8(ctx, base);
	// stw r30,1056(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1056, r30.u32);
	// lwz r3,1064(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1064);
	// bl 0x82130588
	ctx.lr = 0x823B5208;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-17320
	ctx.r5.s64 = ctx.r6.s64 + -17320;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B521C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,1120
	ctx.r3.s64 = ctx.r1.s64 + 1120;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r4,30092
	ctx.r4.s64 = ctx.r4.s64 + 30092;
	// bl 0x823b9c20
	ctx.lr = 0x823B5238;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5244;
	sub_823BA7F8(ctx, base);
	// stw r30,1120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1120, r30.u32);
	// lwz r3,1128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1128);
	// bl 0x82130588
	ctx.lr = 0x823B5250;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-17312
	ctx.r10.s64 = r11.s64 + -17312;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5264;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1184
	ctx.r3.s64 = ctx.r1.s64 + 1184;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30076
	ctx.r4.s64 = ctx.r9.s64 + 30076;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5280;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B528C;
	sub_823BA7F8(ctx, base);
	// stw r30,1184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1184, r30.u32);
	// lwz r3,1192(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1192);
	// bl 0x82130588
	ctx.lr = 0x823B5298;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,8008
	ctx.r7.s64 = ctx.r8.s64 + 8008;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B52AC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r3,r1,1248
	ctx.r3.s64 = ctx.r1.s64 + 1248;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,-31992
	ctx.r4.s64 = ctx.r6.s64 + -31992;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B52C8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B52D4;
	sub_823BA7F8(ctx, base);
	// stw r30,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, r30.u32);
	// lwz r3,1256(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1256);
	// bl 0x82130588
	ctx.lr = 0x823B52E0;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-17272
	ctx.r4.s64 = ctx.r5.s64 + -17272;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B52F4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,1312
	ctx.r3.s64 = ctx.r1.s64 + 1312;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30056
	ctx.r4.s64 = r11.s64 + 30056;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5310;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B531C;
	sub_823BA7F8(ctx, base);
	// stw r30,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, r30.u32);
	// lwz r3,1320(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1320);
	// bl 0x82130588
	ctx.lr = 0x823B5328;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-17264
	ctx.r9.s64 = ctx.r10.s64 + -17264;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B533C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r1,1376
	ctx.r3.s64 = ctx.r1.s64 + 1376;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30032
	ctx.r4.s64 = ctx.r8.s64 + 30032;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5358;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5364;
	sub_823BA7F8(ctx, base);
	// stw r30,1376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1376, r30.u32);
	// lwz r3,1384(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1384);
	// bl 0x82130588
	ctx.lr = 0x823B5370;
	sub_82130588(ctx, base);
	// lis r7,-32235
	ctx.r7.s64 = -2112552960;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-27520
	ctx.r6.s64 = ctx.r7.s64 + -27520;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5384;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// addi r3,r1,1440
	ctx.r3.s64 = ctx.r1.s64 + 1440;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30016
	ctx.r4.s64 = ctx.r5.s64 + 30016;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B53A0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B53AC;
	sub_823BA7F8(ctx, base);
	// stw r30,1440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1440, r30.u32);
	// lwz r3,1448(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1448);
	// bl 0x82130588
	ctx.lr = 0x823B53B8;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-17256
	r11.s64 = ctx.r4.s64 + -17256;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B53CC;
	sub_82130000(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1504
	ctx.r3.s64 = ctx.r1.s64 + 1504;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30000
	ctx.r4.s64 = ctx.r10.s64 + 30000;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B53E8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B53F4;
	sub_823BA7F8(ctx, base);
	// stw r30,1504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1504, r30.u32);
	// lwz r3,1512(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1512);
	// bl 0x82130588
	ctx.lr = 0x823B5400;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-16776
	ctx.r8.s64 = ctx.r9.s64 + -16776;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5414;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1568
	ctx.r3.s64 = ctx.r1.s64 + 1568;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,29988
	ctx.r4.s64 = ctx.r7.s64 + 29988;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5430;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B543C;
	sub_823BA7F8(ctx, base);
	// stw r30,1568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1568, r30.u32);
	// lwz r3,1576(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1576);
	// bl 0x82130588
	ctx.lr = 0x823B5448;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-16768
	ctx.r5.s64 = ctx.r6.s64 + -16768;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B545C;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1632
	ctx.r3.s64 = ctx.r1.s64 + 1632;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,29976
	ctx.r4.s64 = ctx.r4.s64 + 29976;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5478;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5484;
	sub_823BA7F8(ctx, base);
	// stw r30,1632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1632, r30.u32);
	// lwz r3,1640(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1640);
	// bl 0x82130588
	ctx.lr = 0x823B5490;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16760
	ctx.r10.s64 = r11.s64 + -16760;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B54A4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,1696
	ctx.r3.s64 = ctx.r1.s64 + 1696;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r9,29964
	ctx.r4.s64 = ctx.r9.s64 + 29964;
	// bl 0x823b9c20
	ctx.lr = 0x823B54C0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B54CC;
	sub_823BA7F8(ctx, base);
	// stw r30,1696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1696, r30.u32);
	// lwz r3,1704(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1704);
	// bl 0x82130588
	ctx.lr = 0x823B54D8;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-16432
	ctx.r7.s64 = ctx.r8.s64 + -16432;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B54EC;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1760
	ctx.r3.s64 = ctx.r1.s64 + 1760;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,29936
	ctx.r4.s64 = ctx.r6.s64 + 29936;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5508;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5514;
	sub_823BA7F8(ctx, base);
	// stw r30,1760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1760, r30.u32);
	// lwz r3,1768(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1768);
	// bl 0x82130588
	ctx.lr = 0x823B5520;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-16752
	ctx.r4.s64 = ctx.r5.s64 + -16752;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5534;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1824
	ctx.r3.s64 = ctx.r1.s64 + 1824;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,29920
	ctx.r4.s64 = r11.s64 + 29920;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5550;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B555C;
	sub_823BA7F8(ctx, base);
	// stw r30,1824(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1824, r30.u32);
	// lwz r3,1832(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1832);
	// bl 0x82130588
	ctx.lr = 0x823B5568;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-16744
	ctx.r9.s64 = ctx.r10.s64 + -16744;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B557C;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1888
	ctx.r3.s64 = ctx.r1.s64 + 1888;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,29892
	ctx.r4.s64 = ctx.r8.s64 + 29892;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5598;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B55A4;
	sub_823BA7F8(ctx, base);
	// stw r30,1888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1888, r30.u32);
	// lwz r3,1896(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1896);
	// bl 0x82130588
	ctx.lr = 0x823B55B0;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-16736
	ctx.r6.s64 = ctx.r7.s64 + -16736;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B55C4;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1952
	ctx.r3.s64 = ctx.r1.s64 + 1952;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,29868
	ctx.r4.s64 = ctx.r5.s64 + 29868;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B55E0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B55EC;
	sub_823BA7F8(ctx, base);
	// stw r30,1952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1952, r30.u32);
	// lwz r3,1960(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1960);
	// bl 0x82130588
	ctx.lr = 0x823B55F8;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-16688
	r11.s64 = ctx.r4.s64 + -16688;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B560C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,29852
	ctx.r4.s64 = ctx.r10.s64 + 29852;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5628;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5634;
	sub_823BA7F8(ctx, base);
	// stw r30,2016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2016, r30.u32);
	// lwz r3,2024(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2024);
	// bl 0x82130588
	ctx.lr = 0x823B5640;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-16680
	ctx.r8.s64 = ctx.r9.s64 + -16680;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5654;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,29844
	ctx.r4.s64 = ctx.r7.s64 + 29844;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5670;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B567C;
	sub_823BA7F8(ctx, base);
	// stw r30,2080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2080, r30.u32);
	// lwz r3,2088(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2088);
	// bl 0x82130588
	ctx.lr = 0x823B5688;
	sub_82130588(ctx, base);
	// lis r6,-32198
	ctx.r6.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,13720
	ctx.r5.s64 = ctx.r6.s64 + 13720;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B569C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// addi r3,r1,2144
	ctx.r3.s64 = ctx.r1.s64 + 2144;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,29816
	ctx.r4.s64 = ctx.r4.s64 + 29816;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B56B8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B56C4;
	sub_823BA7F8(ctx, base);
	// stw r30,2144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2144, r30.u32);
	// lwz r3,2152(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2152);
	// bl 0x82130588
	ctx.lr = 0x823B56D0;
	sub_82130588(ctx, base);
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,13744
	ctx.r10.s64 = r11.s64 + 13744;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B56E4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r1,2208
	ctx.r3.s64 = ctx.r1.s64 + 2208;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,29788
	ctx.r4.s64 = ctx.r9.s64 + 29788;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5700;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B570C;
	sub_823BA7F8(ctx, base);
	// stw r30,2208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2208, r30.u32);
	// lwz r3,2216(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2216);
	// bl 0x82130588
	ctx.lr = 0x823B5718;
	sub_82130588(ctx, base);
	// lis r8,-32198
	ctx.r8.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,13768
	ctx.r7.s64 = ctx.r8.s64 + 13768;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B572C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,2272
	ctx.r3.s64 = ctx.r1.s64 + 2272;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r6,29760
	ctx.r4.s64 = ctx.r6.s64 + 29760;
	// bl 0x823b9c20
	ctx.lr = 0x823B5748;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5754;
	sub_823BA7F8(ctx, base);
	// stw r30,2272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2272, r30.u32);
	// lwz r3,2280(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2280);
	// bl 0x82130588
	ctx.lr = 0x823B5760;
	sub_82130588(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,13792
	ctx.r4.s64 = ctx.r5.s64 + 13792;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5774;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2336
	ctx.r3.s64 = ctx.r1.s64 + 2336;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,29732
	ctx.r4.s64 = r11.s64 + 29732;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5790;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B579C;
	sub_823BA7F8(ctx, base);
	// stw r30,2336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2336, r30.u32);
	// lwz r3,2344(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2344);
	// bl 0x82130588
	ctx.lr = 0x823B57A8;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-16728
	ctx.r9.s64 = ctx.r10.s64 + -16728;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B57BC;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2400
	ctx.r3.s64 = ctx.r1.s64 + 2400;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,29728
	ctx.r4.s64 = ctx.r8.s64 + 29728;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9cc0
	ctx.lr = 0x823B57D8;
	sub_823B9CC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B57E4;
	sub_823BA7F8(ctx, base);
	// stw r30,2400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2400, r30.u32);
	// lwz r3,2408(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2408);
	// bl 0x82130588
	ctx.lr = 0x823B57F0;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-16720
	ctx.r6.s64 = ctx.r7.s64 + -16720;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5804;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2464
	ctx.r3.s64 = ctx.r1.s64 + 2464;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,29724
	ctx.r4.s64 = ctx.r5.s64 + 29724;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9d60
	ctx.lr = 0x823B5820;
	sub_823B9D60(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B582C;
	sub_823BA7F8(ctx, base);
	// stw r30,2464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2464, r30.u32);
	// lwz r3,2472(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2472);
	// bl 0x82130588
	ctx.lr = 0x823B5838;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-16704
	r11.s64 = ctx.r4.s64 + -16704;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B584C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,2528
	ctx.r3.s64 = ctx.r1.s64 + 2528;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,29720
	ctx.r4.s64 = ctx.r10.s64 + 29720;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9d60
	ctx.lr = 0x823B5868;
	sub_823B9D60(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5874;
	sub_823BA7F8(ctx, base);
	// stw r30,2528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2528, r30.u32);
	// lwz r3,2536(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2536);
	// bl 0x82130588
	ctx.lr = 0x823B5880;
	sub_82130588(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r8,r9,29016
	ctx.r8.s64 = ctx.r9.s64 + 29016;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5894;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2592
	ctx.r3.s64 = ctx.r1.s64 + 2592;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,29700
	ctx.r4.s64 = ctx.r7.s64 + 29700;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B58B0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B58BC;
	sub_823BA7F8(ctx, base);
	// stw r30,2592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2592, r30.u32);
	// lwz r3,2600(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2600);
	// bl 0x82130588
	ctx.lr = 0x823B58C8;
	sub_82130588(ctx, base);
	// lis r6,-32198
	ctx.r6.s64 = -2110128128;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r5,r6,29544
	ctx.r5.s64 = ctx.r6.s64 + 29544;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B58DC;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2656
	ctx.r3.s64 = ctx.r1.s64 + 2656;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,29656
	ctx.r4.s64 = ctx.r4.s64 + 29656;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B58F8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5904;
	sub_823BA7F8(ctx, base);
	// stw r30,2656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2656, r30.u32);
	// lwz r3,2664(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2664);
	// bl 0x82130588
	ctx.lr = 0x823B5910;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-17304
	ctx.r10.s64 = r11.s64 + -17304;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5924;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r1,2720
	ctx.r3.s64 = ctx.r1.s64 + 2720;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,29632
	ctx.r4.s64 = ctx.r9.s64 + 29632;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5940;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B594C;
	sub_823BA7F8(ctx, base);
	// stw r30,2720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2720, r30.u32);
	// lwz r3,2728(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2728);
	// bl 0x82130588
	ctx.lr = 0x823B5958;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-17288
	ctx.r7.s64 = ctx.r8.s64 + -17288;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B596C;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2784
	ctx.r3.s64 = ctx.r1.s64 + 2784;
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,29604
	ctx.r4.s64 = ctx.r6.s64 + 29604;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823B5988;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823B5994;
	sub_823BA7F8(ctx, base);
	// stw r30,2784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2784, r30.u32);
	// lwz r3,2792(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2792);
	// bl 0x82130588
	ctx.lr = 0x823B59A0;
	sub_82130588(ctx, base);
	// addi r1,r1,2864
	ctx.r1.s64 = ctx.r1.s64 + 2864;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823B41A0) {
	__imp__sub_823B41A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B59A8) {
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
	ctx.lr = 0x823B59B0;
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,32604
	ctx.r4.s64 = r11.s64 + 32604;
	// bl 0x823b9960
	ctx.lr = 0x823B59C4;
	sub_823B9960(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,32588
	ctx.r4.s64 = ctx.r10.s64 + 32588;
	// stw r15,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r15.u32);
	// bl 0x823b9960
	ctx.lr = 0x823B59DC;
	sub_823B9960(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-30528
	ctx.r4.s64 = ctx.r9.s64 + -30528;
	// bl 0x823b9960
	ctx.lr = 0x823B59F0;
	sub_823B9960(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-25488
	ctx.r4.s64 = ctx.r8.s64 + -25488;
	// bl 0x823b9960
	ctx.lr = 0x823B5A04;
	sub_823B9960(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,32544
	ctx.r4.s64 = ctx.r7.s64 + 32544;
	// bl 0x823b9960
	ctx.lr = 0x823B5A18;
	sub_823B9960(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-30560
	ctx.r4.s64 = ctx.r6.s64 + -30560;
	// bl 0x823b9960
	ctx.lr = 0x823B5A2C;
	sub_823B9960(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-30596
	ctx.r4.s64 = ctx.r5.s64 + -30596;
	// bl 0x823b9960
	ctx.lr = 0x823B5A40;
	sub_823B9960(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,-30628
	ctx.r4.s64 = ctx.r4.s64 + -30628;
	// bl 0x823b9960
	ctx.lr = 0x823B5A54;
	sub_823B9960(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-30660
	ctx.r4.s64 = r11.s64 + -30660;
	// bl 0x823b9960
	ctx.lr = 0x823B5A68;
	sub_823B9960(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-30696
	ctx.r4.s64 = ctx.r10.s64 + -30696;
	// bl 0x823b9960
	ctx.lr = 0x823B5A7C;
	sub_823B9960(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-30728
	ctx.r4.s64 = ctx.r9.s64 + -30728;
	// bl 0x823b9960
	ctx.lr = 0x823B5A90;
	sub_823B9960(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-30740
	ctx.r4.s64 = ctx.r8.s64 + -30740;
	// bl 0x823b9960
	ctx.lr = 0x823B5AA4;
	sub_823B9960(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,-30756
	ctx.r4.s64 = ctx.r7.s64 + -30756;
	// bl 0x823b9960
	ctx.lr = 0x823B5AB8;
	sub_823B9960(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-30768
	ctx.r4.s64 = ctx.r6.s64 + -30768;
	// bl 0x823b9960
	ctx.lr = 0x823B5ACC;
	sub_823B9960(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-30784
	ctx.r4.s64 = ctx.r5.s64 + -30784;
	// bl 0x823b9960
	ctx.lr = 0x823B5AE0;
	sub_823B9960(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,32460
	ctx.r4.s64 = ctx.r4.s64 + 32460;
	// bl 0x823b9960
	ctx.lr = 0x823B5AF4;
	sub_823B9960(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-30800
	ctx.r4.s64 = r11.s64 + -30800;
	// bl 0x823b9960
	ctx.lr = 0x823B5B08;
	sub_823B9960(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-30812
	ctx.r4.s64 = ctx.r10.s64 + -30812;
	// bl 0x823b9960
	ctx.lr = 0x823B5B1C;
	sub_823B9960(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-30832
	ctx.r4.s64 = ctx.r9.s64 + -30832;
	// bl 0x823b9960
	ctx.lr = 0x823B5B30;
	sub_823B9960(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-30852
	ctx.r4.s64 = ctx.r8.s64 + -30852;
	// bl 0x823b9960
	ctx.lr = 0x823B5B44;
	sub_823B9960(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,-30880
	ctx.r4.s64 = ctx.r7.s64 + -30880;
	// bl 0x823b9960
	ctx.lr = 0x823B5B58;
	sub_823B9960(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-30916
	ctx.r4.s64 = ctx.r6.s64 + -30916;
	// bl 0x823b9960
	ctx.lr = 0x823B5B6C;
	sub_823B9960(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// stw r3,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-30936
	ctx.r4.s64 = ctx.r5.s64 + -30936;
	// bl 0x823b9960
	ctx.lr = 0x823B5B80;
	sub_823B9960(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// stw r3,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,-30960
	ctx.r4.s64 = ctx.r4.s64 + -30960;
	// bl 0x823b9960
	ctx.lr = 0x823B5B94;
	sub_823B9960(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,32132
	ctx.r4.s64 = r11.s64 + 32132;
	// bl 0x823b9960
	ctx.lr = 0x823B5BA8;
	sub_823B9960(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,32116
	ctx.r4.s64 = ctx.r10.s64 + 32116;
	// bl 0x823b9960
	ctx.lr = 0x823B5BBC;
	sub_823B9960(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r8,r9,-11868
	ctx.r8.s64 = ctx.r9.s64 + -11868;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b5c04
	if (cr6.eq) goto loc_823B5C04;
	// lis r11,-32198
	r11.s64 = -2110128128;
	// stw r30,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r30.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r10,r11,23968
	ctx.r10.s64 = r11.s64 + 23968;
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5BF0;
	sub_82130000(ctx, base);
	// stw r3,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// addi r4,r1,168
	ctx.r4.s64 = ctx.r1.s64 + 168;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B5C00;
	sub_823B8660(ctx, base);
	// b 0x823b5c5c
	goto loc_823B5C5C;
loc_823B5C04:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// stw r30,1008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1008, r30.u32);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 904, r30.u32);
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// addi r8,r10,10728
	ctx.r8.s64 = ctx.r10.s64 + 10728;
	// stw r9,1012(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1012, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,908(r1)
	PPC_STORE_U32(ctx.r1.u32 + 908, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5C2C;
	sub_82130000(ctx, base);
	// stw r3,904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 904, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,904
	r15.s64 = ctx.r1.s64 + 904;
	// addi r14,r1,1008
	r14.s64 = ctx.r1.s64 + 1008;
	// bl 0x823b99d0
	ctx.lr = 0x823B5C40;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x823b9430
	ctx.lr = 0x823B5C4C;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x823b86b8
	ctx.lr = 0x823B5C5C;
	sub_823B86B8(ctx, base);
loc_823B5C5C:
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,10920
	ctx.r10.s64 = r11.s64 + 10920;
	// stw r10,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5C74;
	sub_82130000(ctx, base);
	// stw r3,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r3.u32);
	// addi r4,r1,184
	ctx.r4.s64 = ctx.r1.s64 + 184;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B5C84;
	sub_823B8660(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// stw r30,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, r30.u32);
	// addi r8,r9,13632
	ctx.r8.s64 = ctx.r9.s64 + 13632;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r8,604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 604, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5C9C;
	sub_82130000(ctx, base);
	// stw r3,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,600
	r15.s64 = ctx.r1.s64 + 600;
	// bl 0x823b99d0
	ctx.lr = 0x823B5CAC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5CB8;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5CC4;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r30.u32);
	// addi r6,r7,8016
	ctx.r6.s64 = ctx.r7.s64 + 8016;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r6,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5CDC;
	sub_82130000(ctx, base);
	// stw r3,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,200
	r15.s64 = ctx.r1.s64 + 200;
	// bl 0x823b99d0
	ctx.lr = 0x823B5CEC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5CF8;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5D04;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,8736
	ctx.r4.s64 = ctx.r5.s64 + 8736;
	// stw r4,812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 812, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5D1C;
	sub_82130000(ctx, base);
	// stw r3,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,808
	r15.s64 = ctx.r1.s64 + 808;
	// bl 0x823b99d0
	ctx.lr = 0x823B5D2C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5D38;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5D44;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,8808
	ctx.r10.s64 = r11.s64 + 8808;
	// stw r10,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5D5C;
	sub_82130000(ctx, base);
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,216
	r15.s64 = ctx.r1.s64 + 216;
	// bl 0x823b99d0
	ctx.lr = 0x823B5D6C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5D78;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,112(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x823b86a0
	ctx.lr = 0x823B5D84;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,8944
	ctx.r8.s64 = ctx.r9.s64 + 8944;
	// stw r8,620(r1)
	PPC_STORE_U32(ctx.r1.u32 + 620, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5D9C;
	sub_82130000(ctx, base);
	// stw r3,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,616
	r15.s64 = ctx.r1.s64 + 616;
	// bl 0x823b99d0
	ctx.lr = 0x823B5DAC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5DB8;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5DC4;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,9032
	ctx.r6.s64 = ctx.r7.s64 + 9032;
	// stw r6,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5DDC;
	sub_82130000(ctx, base);
	// stw r3,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,232
	r15.s64 = ctx.r1.s64 + 232;
	// bl 0x823b99d0
	ctx.lr = 0x823B5DEC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5DF8;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5E04;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,9120
	ctx.r4.s64 = ctx.r5.s64 + 9120;
	// stw r4,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5E1C;
	sub_82130000(ctx, base);
	// stw r3,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,984
	r15.s64 = ctx.r1.s64 + 984;
	// bl 0x823b99d0
	ctx.lr = 0x823B5E2C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5E38;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5E44;
	sub_823B86A0(ctx, base);
	// lis r3,-32196
	ctx.r3.s64 = -2109997056;
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, r30.u32);
	// addi r11,r3,-22472
	r11.s64 = ctx.r3.s64 + -22472;
	// stw r11,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, r11.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x82130000
	ctx.lr = 0x823B5E5C;
	sub_82130000(ctx, base);
	// stw r3,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r10,-31048
	r15.s64 = ctx.r10.s64 + -31048;
	// addi r14,r1,248
	r14.s64 = ctx.r1.s64 + 248;
	// bl 0x823b99d0
	ctx.lr = 0x823B5E74;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5E80;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x823b86e0
	ctx.lr = 0x823B5E90;
	sub_823B86E0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,11072
	ctx.r8.s64 = ctx.r9.s64 + 11072;
	// stw r8,636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 636, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5EA8;
	sub_82130000(ctx, base);
	// stw r3,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r3.u32);
	// addi r4,r1,632
	ctx.r4.s64 = ctx.r1.s64 + 632;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B5EB8;
	sub_823B8660(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-12296
	ctx.r6.s64 = ctx.r7.s64 + -12296;
	// stw r6,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5ED0;
	sub_82130000(ctx, base);
	// stw r3,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r3.u32);
	// addi r4,r1,264
	ctx.r4.s64 = ctx.r1.s64 + 264;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B5EE0;
	sub_823B8678(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// addi r4,r5,9192
	ctx.r4.s64 = ctx.r5.s64 + 9192;
	// stw r30,824(r1)
	PPC_STORE_U32(ctx.r1.u32 + 824, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,828(r1)
	PPC_STORE_U32(ctx.r1.u32 + 828, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5EF8;
	sub_82130000(ctx, base);
	// stw r3,824(r1)
	PPC_STORE_U32(ctx.r1.u32 + 824, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,824
	r14.s64 = ctx.r1.s64 + 824;
	// bl 0x823b99d0
	ctx.lr = 0x823B5F08;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5F14;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5F20;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,9232
	ctx.r10.s64 = r11.s64 + 9232;
	// stw r10,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5F38;
	sub_82130000(ctx, base);
	// stw r3,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,280
	r14.s64 = ctx.r1.s64 + 280;
	// bl 0x823b99d0
	ctx.lr = 0x823B5F48;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5F54;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x823b86a0
	ctx.lr = 0x823B5F60;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 648, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,8944
	ctx.r8.s64 = ctx.r9.s64 + 8944;
	// stw r8,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5F78;
	sub_82130000(ctx, base);
	// stw r3,648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 648, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,648
	r14.s64 = ctx.r1.s64 + 648;
	// bl 0x823b99d0
	ctx.lr = 0x823B5F88;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5F94;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5FA0;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,9032
	ctx.r6.s64 = ctx.r7.s64 + 9032;
	// stw r6,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5FB8;
	sub_82130000(ctx, base);
	// stw r3,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,296
	r14.s64 = ctx.r1.s64 + 296;
	// bl 0x823b99d0
	ctx.lr = 0x823B5FC8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B5FD4;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B5FE0;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,9120
	ctx.r4.s64 = ctx.r5.s64 + 9120;
	// stw r4,924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 924, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B5FF8;
	sub_82130000(ctx, base);
	// stw r3,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,920
	r14.s64 = ctx.r1.s64 + 920;
	// bl 0x823b99d0
	ctx.lr = 0x823B6008;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6014;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6020;
	sub_823B86A0(ctx, base);
	// lis r3,-32196
	ctx.r3.s64 = -2109997056;
	// stw r30,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, r30.u32);
	// addi r11,r3,-22472
	r11.s64 = ctx.r3.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6038;
	sub_82130000(ctx, base);
	// stw r3,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,312
	r14.s64 = ctx.r1.s64 + 312;
	// bl 0x823b99d0
	ctx.lr = 0x823B6048;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6054;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x823b86e0
	ctx.lr = 0x823B6064;
	sub_823B86E0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,12144
	ctx.r9.s64 = ctx.r10.s64 + 12144;
	// stw r9,668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 668, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B607C;
	sub_82130000(ctx, base);
	// stw r3,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, ctx.r3.u32);
	// addi r4,r1,664
	ctx.r4.s64 = ctx.r1.s64 + 664;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B608C;
	sub_823B8660(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,11944
	ctx.r7.s64 = ctx.r8.s64 + 11944;
	// stw r7,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B60A4;
	sub_82130000(ctx, base);
	// stw r3,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r3.u32);
	// addi r4,r1,328
	ctx.r4.s64 = ctx.r1.s64 + 328;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B60B4;
	sub_823B8678(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,12256
	ctx.r5.s64 = ctx.r6.s64 + 12256;
	// stw r5,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B60C8;
	sub_82130000(ctx, base);
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ld r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// bl 0x823b8658
	ctx.lr = 0x823B60D8;
	sub_823B8658(ctx, base);
	// lis r4,-32198
	ctx.r4.s64 = -2110128128;
	// addi r11,r4,4872
	r11.s64 = ctx.r4.s64 + 4872;
	// stw r30,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r11,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B60F0;
	sub_82130000(ctx, base);
	// stw r3,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,840
	r15.s64 = ctx.r1.s64 + 840;
	// bl 0x823b99d0
	ctx.lr = 0x823B6100;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B610C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6118;
	sub_823B86A0(ctx, base);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// stw r30,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r30.u32);
	// addi r9,r10,13632
	ctx.r9.s64 = ctx.r10.s64 + 13632;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r9,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6130;
	sub_82130000(ctx, base);
	// stw r3,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,344
	r15.s64 = ctx.r1.s64 + 344;
	// bl 0x823b99d0
	ctx.lr = 0x823B6140;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B614C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6158;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,8016
	ctx.r7.s64 = ctx.r8.s64 + 8016;
	// stw r30,680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 680, r30.u32);
	// stw r7,684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 684, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6170;
	sub_82130000(ctx, base);
	// stw r3,680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 680, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,680
	r15.s64 = ctx.r1.s64 + 680;
	// bl 0x823b99d0
	ctx.lr = 0x823B6180;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B618C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6198;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,9344
	ctx.r5.s64 = ctx.r6.s64 + 9344;
	// stw r5,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B61B0;
	sub_82130000(ctx, base);
	// stw r3,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,360
	r15.s64 = ctx.r1.s64 + 360;
	// bl 0x823b99d0
	ctx.lr = 0x823B61C0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B61CC;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B61D8;
	sub_823B86A0(ctx, base);
	// lis r4,-32196
	ctx.r4.s64 = -2109997056;
	// stw r30,968(r1)
	PPC_STORE_U32(ctx.r1.u32 + 968, r30.u32);
	// addi r11,r4,-22472
	r11.s64 = ctx.r4.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,972(r1)
	PPC_STORE_U32(ctx.r1.u32 + 972, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B61F0;
	sub_82130000(ctx, base);
	// stw r3,968(r1)
	PPC_STORE_U32(ctx.r1.u32 + 968, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r10,-31168
	r15.s64 = ctx.r10.s64 + -31168;
	// addi r14,r1,968
	r14.s64 = ctx.r1.s64 + 968;
	// bl 0x823b99d0
	ctx.lr = 0x823B6208;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6214;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B6224;
	sub_823B86E0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,9032
	ctx.r8.s64 = ctx.r9.s64 + 9032;
	// stw r8,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B623C;
	sub_82130000(ctx, base);
	// stw r3,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,376
	r15.s64 = ctx.r1.s64 + 376;
	// bl 0x823b99d0
	ctx.lr = 0x823B624C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6258;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6264;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,9120
	ctx.r6.s64 = ctx.r7.s64 + 9120;
	// stw r6,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B627C;
	sub_82130000(ctx, base);
	// stw r3,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,696
	r15.s64 = ctx.r1.s64 + 696;
	// bl 0x823b99d0
	ctx.lr = 0x823B628C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6298;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B62A4;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,9456
	ctx.r4.s64 = ctx.r5.s64 + 9456;
	// stw r4,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B62BC;
	sub_82130000(ctx, base);
	// stw r3,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,392
	r15.s64 = ctx.r1.s64 + 392;
	// bl 0x823b99d0
	ctx.lr = 0x823B62CC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B62D8;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,116(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823b86a0
	ctx.lr = 0x823B62E4;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-15808
	ctx.r10.s64 = r11.s64 + -15808;
	// stw r10,860(r1)
	PPC_STORE_U32(ctx.r1.u32 + 860, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B62FC;
	sub_82130000(ctx, base);
	// stw r3,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,856
	r15.s64 = ctx.r1.s64 + 856;
	// bl 0x823b99d0
	ctx.lr = 0x823B630C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6318;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6324;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,9520
	ctx.r8.s64 = ctx.r9.s64 + 9520;
	// stw r8,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B633C;
	sub_82130000(ctx, base);
	// stw r3,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,408
	r15.s64 = ctx.r1.s64 + 408;
	// bl 0x823b99d0
	ctx.lr = 0x823B634C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6358;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6364;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,9680
	ctx.r6.s64 = ctx.r7.s64 + 9680;
	// stw r6,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B637C;
	sub_82130000(ctx, base);
	// stw r3,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,712
	r15.s64 = ctx.r1.s64 + 712;
	// bl 0x823b99d0
	ctx.lr = 0x823B638C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6398;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B63A4;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,9840
	ctx.r4.s64 = ctx.r5.s64 + 9840;
	// stw r4,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B63BC;
	sub_82130000(ctx, base);
	// stw r3,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,424
	r14.s64 = ctx.r1.s64 + 424;
	// bl 0x823b99d0
	ctx.lr = 0x823B63CC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B63D8;
	sub_823B9430(ctx, base);
	// lwz r15,80(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B63E8;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,936(r1)
	PPC_STORE_U32(ctx.r1.u32 + 936, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,9232
	ctx.r10.s64 = r11.s64 + 9232;
	// stw r10,940(r1)
	PPC_STORE_U32(ctx.r1.u32 + 940, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6400;
	sub_82130000(ctx, base);
	// stw r3,936(r1)
	PPC_STORE_U32(ctx.r1.u32 + 936, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,936
	r14.s64 = ctx.r1.s64 + 936;
	// bl 0x823b99d0
	ctx.lr = 0x823B6410;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B641C;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x823b86a0
	ctx.lr = 0x823B6428;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 440, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,13096
	ctx.r8.s64 = ctx.r9.s64 + 13096;
	// stw r8,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6440;
	sub_82130000(ctx, base);
	// stw r3,440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 440, ctx.r3.u32);
	// addi r4,r1,440
	ctx.r4.s64 = ctx.r1.s64 + 440;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B6450;
	sub_823B8660(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,13400
	ctx.r6.s64 = ctx.r7.s64 + 13400;
	// stw r6,732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 732, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6468;
	sub_82130000(ctx, base);
	// stw r3,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, ctx.r3.u32);
	// addi r4,r1,728
	ctx.r4.s64 = ctx.r1.s64 + 728;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B6478;
	sub_823B8678(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,13872
	ctx.r4.s64 = ctx.r5.s64 + 13872;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B648C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B649C;
	sub_823B8658(ctx, base);
	// lis r3,-32197
	ctx.r3.s64 = -2110062592;
	// addi r11,r3,9944
	r11.s64 = ctx.r3.s64 + 9944;
	// stw r30,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B64B4;
	sub_82130000(ctx, base);
	// stw r3,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,456
	r14.s64 = ctx.r1.s64 + 456;
	// bl 0x823b99d0
	ctx.lr = 0x823B64C4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B64D0;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B64DC;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,10000
	ctx.r9.s64 = ctx.r10.s64 + 10000;
	// stw r9,876(r1)
	PPC_STORE_U32(ctx.r1.u32 + 876, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B64F4;
	sub_82130000(ctx, base);
	// stw r3,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,872
	r14.s64 = ctx.r1.s64 + 872;
	// bl 0x823b99d0
	ctx.lr = 0x823B6504;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6510;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B651C;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,13568
	ctx.r7.s64 = ctx.r8.s64 + 13568;
	// stw r7,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6534;
	sub_82130000(ctx, base);
	// stw r3,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r3.u32);
	// addi r4,r1,472
	ctx.r4.s64 = ctx.r1.s64 + 472;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B6544;
	sub_823B8660(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,13400
	ctx.r5.s64 = ctx.r6.s64 + 13400;
	// stw r5,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B655C;
	sub_82130000(ctx, base);
	// stw r3,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r3.u32);
	// addi r4,r1,744
	ctx.r4.s64 = ctx.r1.s64 + 744;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B656C;
	sub_823B8678(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,13872
	r11.s64 = ctx.r4.s64 + 13872;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6580;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B6590;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// addi r9,r10,10056
	ctx.r9.s64 = ctx.r10.s64 + 10056;
	// stw r30,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B65A8;
	sub_82130000(ctx, base);
	// stw r3,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,488
	r20.s64 = ctx.r1.s64 + 488;
	// bl 0x823b99d0
	ctx.lr = 0x823B65B8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B65C4;
	sub_823B9430(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B65D0;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,1000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1000, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,13968
	ctx.r7.s64 = ctx.r8.s64 + 13968;
	// stw r7,1004(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1004, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B65E8;
	sub_82130000(ctx, base);
	// stw r3,1000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1000, ctx.r3.u32);
	// addi r4,r1,1000
	ctx.r4.s64 = ctx.r1.s64 + 1000;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B65F8;
	sub_823B8660(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,14336
	ctx.r5.s64 = ctx.r6.s64 + 14336;
	// stw r5,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6610;
	sub_82130000(ctx, base);
	// stw r3,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r3.u32);
	// addi r4,r1,504
	ctx.r4.s64 = ctx.r1.s64 + 504;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B6620;
	sub_823B8678(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,14368
	r11.s64 = ctx.r4.s64 + 14368;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6634;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B6644;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// addi r9,r10,10096
	ctx.r9.s64 = ctx.r10.s64 + 10096;
	// stw r30,760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 760, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,764(r1)
	PPC_STORE_U32(ctx.r1.u32 + 764, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B665C;
	sub_82130000(ctx, base);
	// stw r3,760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 760, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,760
	r20.s64 = ctx.r1.s64 + 760;
	// bl 0x823b99d0
	ctx.lr = 0x823B666C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6678;
	sub_823B9430(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6684;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,13248
	ctx.r7.s64 = ctx.r8.s64 + 13248;
	// stw r7,524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 524, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B669C;
	sub_82130000(ctx, base);
	// stw r3,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r3.u32);
	// addi r4,r1,520
	ctx.r4.s64 = ctx.r1.s64 + 520;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B66AC;
	sub_823B8660(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 888, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,13400
	ctx.r5.s64 = ctx.r6.s64 + 13400;
	// stw r5,892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 892, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B66C4;
	sub_82130000(ctx, base);
	// stw r3,888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 888, ctx.r3.u32);
	// addi r4,r1,888
	ctx.r4.s64 = ctx.r1.s64 + 888;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B66D4;
	sub_823B8678(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,13480
	r11.s64 = ctx.r4.s64 + 13480;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B66E8;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B66F8;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// addi r9,r10,10160
	ctx.r9.s64 = ctx.r10.s64 + 10160;
	// stw r30,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,540(r1)
	PPC_STORE_U32(ctx.r1.u32 + 540, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6710;
	sub_82130000(ctx, base);
	// stw r3,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,536
	r18.s64 = ctx.r1.s64 + 536;
	// bl 0x823b99d0
	ctx.lr = 0x823B6720;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B672C;
	sub_823B9430(ctx, base);
	// lwz r20,96(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B673C;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,10216
	ctx.r7.s64 = ctx.r8.s64 + 10216;
	// stw r7,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6754;
	sub_82130000(ctx, base);
	// stw r3,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,144
	r18.s64 = ctx.r1.s64 + 144;
	// bl 0x823b99d0
	ctx.lr = 0x823B6764;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6770;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B677C;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,13720
	ctx.r5.s64 = ctx.r6.s64 + 13720;
	// stw r5,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6794;
	sub_82130000(ctx, base);
	// stw r3,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r3.u32);
	// addi r4,r1,552
	ctx.r4.s64 = ctx.r1.s64 + 552;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B67A4;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 952, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,13400
	r11.s64 = ctx.r4.s64 + 13400;
	// stw r11,956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 956, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B67BC;
	sub_82130000(ctx, base);
	// stw r3,952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 952, ctx.r3.u32);
	// addi r4,r1,952
	ctx.r4.s64 = ctx.r1.s64 + 952;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B67CC;
	sub_823B8678(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,13480
	ctx.r9.s64 = ctx.r10.s64 + 13480;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B67E0;
	sub_82130000(ctx, base);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x823b8658
	ctx.lr = 0x823B67F0;
	sub_823B8658(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// addi r7,r8,10272
	ctx.r7.s64 = ctx.r8.s64 + 10272;
	// stw r30,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6808;
	sub_82130000(ctx, base);
	// stw r3,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r19,r1,568
	r19.s64 = ctx.r1.s64 + 568;
	// bl 0x823b99d0
	ctx.lr = 0x823B6818;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6824;
	sub_823B9430(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6830;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 792, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,14152
	ctx.r5.s64 = ctx.r6.s64 + 14152;
	// stw r5,796(r1)
	PPC_STORE_U32(ctx.r1.u32 + 796, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6848;
	sub_82130000(ctx, base);
	// stw r3,792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 792, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r4,r1,792
	ctx.r4.s64 = ctx.r1.s64 + 792;
	// bl 0x823b8660
	ctx.lr = 0x823B6858;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,14336
	r11.s64 = ctx.r4.s64 + 14336;
	// stw r11,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6870;
	sub_82130000(ctx, base);
	// stw r3,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r3.u32);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B6880;
	sub_823B8678(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,14368
	ctx.r9.s64 = ctx.r10.s64 + 14368;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6894;
	sub_82130000(ctx, base);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x823b8658
	ctx.lr = 0x823B68A4;
	sub_823B8658(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// addi r7,r8,10096
	ctx.r7.s64 = ctx.r8.s64 + 10096;
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B68BC;
	sub_82130000(ctx, base);
	// stw r3,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r19,r1,160
	r19.s64 = ctx.r1.s64 + 160;
	// bl 0x823b99d0
	ctx.lr = 0x823B68CC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B68D8;
	sub_823B9430(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B68E4;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,11768
	ctx.r5.s64 = ctx.r6.s64 + 11768;
	// stw r5,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B68FC;
	sub_82130000(ctx, base);
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// bl 0x823b8660
	ctx.lr = 0x823B690C;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,11944
	r11.s64 = ctx.r4.s64 + 11944;
	// stw r11,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6924;
	sub_82130000(ctx, base);
	// stw r3,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r3.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// bl 0x823b8678
	ctx.lr = 0x823B6934;
	sub_823B8678(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,11968
	ctx.r9.s64 = ctx.r10.s64 + 11968;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6948;
	sub_82130000(ctx, base);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x823b8658
	ctx.lr = 0x823B6958;
	sub_823B8658(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// addi r7,r8,10096
	ctx.r7.s64 = ctx.r8.s64 + 10096;
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6970;
	sub_82130000(ctx, base);
	// stw r3,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,208
	r20.s64 = ctx.r1.s64 + 208;
	// bl 0x823b99d0
	ctx.lr = 0x823B6980;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B698C;
	sub_823B9430(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6998;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,11240
	ctx.r5.s64 = ctx.r6.s64 + 11240;
	// stw r5,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B69B0;
	sub_82130000(ctx, base);
	// stw r3,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r3.u32);
	// lwz r20,104(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B69C4;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-12296
	r11.s64 = ctx.r4.s64 + -12296;
	// stw r11,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B69DC;
	sub_82130000(ctx, base);
	// stw r3,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// bl 0x823b8678
	ctx.lr = 0x823B69EC;
	sub_823B8678(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,10096
	ctx.r9.s64 = ctx.r10.s64 + 10096;
	// stw r9,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6A04;
	sub_82130000(ctx, base);
	// stw r3,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r19,r1,256
	r19.s64 = ctx.r1.s64 + 256;
	// bl 0x823b99d0
	ctx.lr = 0x823B6A14;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6A20;
	sub_823B9430(ctx, base);
	// lwz r20,128(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6A30;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,11352
	ctx.r7.s64 = ctx.r8.s64 + 11352;
	// stw r7,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6A48;
	sub_82130000(ctx, base);
	// stw r3,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// bl 0x823b8660
	ctx.lr = 0x823B6A58;
	sub_823B8660(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,11496
	ctx.r5.s64 = ctx.r6.s64 + 11496;
	// stw r5,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6A70;
	sub_82130000(ctx, base);
	// stw r3,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// bl 0x823b8678
	ctx.lr = 0x823B6A80;
	sub_823B8678(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,11512
	r11.s64 = ctx.r4.s64 + 11512;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6A94;
	sub_82130000(ctx, base);
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// ld r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// bl 0x823b8658
	ctx.lr = 0x823B6AA4;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// addi r9,r10,10312
	ctx.r9.s64 = ctx.r10.s64 + 10312;
	// stw r30,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6ABC;
	sub_82130000(ctx, base);
	// stw r3,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r19,r1,304
	r19.s64 = ctx.r1.s64 + 304;
	// bl 0x823b99d0
	ctx.lr = 0x823B6ACC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6AD8;
	sub_823B9430(ctx, base);
	// lwz r20,88(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6AE8;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,11624
	ctx.r7.s64 = ctx.r8.s64 + 11624;
	// stw r7,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6B00;
	sub_82130000(ctx, base);
	// stw r3,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// bl 0x823b8660
	ctx.lr = 0x823B6B10;
	sub_823B8660(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-12296
	ctx.r5.s64 = ctx.r6.s64 + -12296;
	// stw r5,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6B28;
	sub_82130000(ctx, base);
	// stw r3,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// bl 0x823b8678
	ctx.lr = 0x823B6B38;
	sub_823B8678(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,10096
	r11.s64 = ctx.r4.s64 + 10096;
	// stw r11,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6B50;
	sub_82130000(ctx, base);
	// stw r3,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r19,r1,352
	r19.s64 = ctx.r1.s64 + 352;
	// bl 0x823b99d0
	ctx.lr = 0x823B6B60;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6B6C;
	sub_823B9430(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6B78;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,14432
	ctx.r9.s64 = ctx.r10.s64 + 14432;
	// stw r9,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6B90;
	sub_82130000(ctx, base);
	// stw r3,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r3.u32);
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B6BA0;
	sub_823B8660(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,14568
	ctx.r7.s64 = ctx.r8.s64 + 14568;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6BB4;
	sub_82130000(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x823b8658
	ctx.lr = 0x823B6BC4;
	sub_823B8658(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// addi r5,r6,10424
	ctx.r5.s64 = ctx.r6.s64 + 10424;
	// stw r30,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6BDC;
	sub_82130000(ctx, base);
	// stw r3,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,384
	r20.s64 = ctx.r1.s64 + 384;
	// bl 0x823b99d0
	ctx.lr = 0x823B6BEC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6BF8;
	sub_823B9430(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6C04;
	sub_823B86A0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,10496
	r11.s64 = ctx.r4.s64 + 10496;
	// stw r11,404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 404, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6C1C;
	sub_82130000(ctx, base);
	// stw r3,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,400
	r20.s64 = ctx.r1.s64 + 400;
	// bl 0x823b99d0
	ctx.lr = 0x823B6C2C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6C38;
	sub_823B9430(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6C44;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,10568
	ctx.r9.s64 = ctx.r10.s64 + 10568;
	// stw r9,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6C5C;
	sub_82130000(ctx, base);
	// stw r3,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,416
	r20.s64 = ctx.r1.s64 + 416;
	// bl 0x823b99d0
	ctx.lr = 0x823B6C6C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6C78;
	sub_823B9430(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6C84;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-15512
	ctx.r7.s64 = ctx.r8.s64 + -15512;
	// stw r7,436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 436, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6C9C;
	sub_82130000(ctx, base);
	// stw r3,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,432
	r20.s64 = ctx.r1.s64 + 432;
	// bl 0x823b99d0
	ctx.lr = 0x823B6CAC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6CB8;
	sub_823B9430(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6CC4;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,14616
	ctx.r5.s64 = ctx.r6.s64 + 14616;
	// stw r5,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6CDC;
	sub_82130000(ctx, base);
	// stw r3,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r3.u32);
	// lwz r23,108(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r4,r1,448
	ctx.r4.s64 = ctx.r1.s64 + 448;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B6CF0;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,14752
	r11.s64 = ctx.r4.s64 + 14752;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6D04;
	sub_82130000(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x823b8658
	ctx.lr = 0x823B6D14;
	sub_823B8658(ctx, base);
	// lis r10,-32196
	ctx.r10.s64 = -2109997056;
	// addi r9,r10,-22472
	ctx.r9.s64 = ctx.r10.s64 + -22472;
	// stw r30,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r9,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6D2C;
	sub_82130000(ctx, base);
	// stw r3,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, ctx.r3.u32);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r8,-31272
	r20.s64 = ctx.r8.s64 + -31272;
	// addi r19,r1,464
	r19.s64 = ctx.r1.s64 + 464;
	// bl 0x823b99d0
	ctx.lr = 0x823B6D44;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6D50;
	sub_823B9430(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B6D60;
	sub_823B86E0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,15008
	ctx.r6.s64 = ctx.r7.s64 + 15008;
	// stw r6,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6D78;
	sub_82130000(ctx, base);
	// stw r3,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r3.u32);
	// lwz r27,116(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B6D8C;
	sub_823B8660(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,15144
	ctx.r4.s64 = ctx.r5.s64 + 15144;
	// stw r4,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6DA4;
	sub_82130000(ctx, base);
	// stw r3,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r1,496
	ctx.r4.s64 = ctx.r1.s64 + 496;
	// bl 0x823b8678
	ctx.lr = 0x823B6DB4;
	sub_823B8678(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,0
	ctx.r10.s64 = r11.s64 + 0;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6DC8;
	sub_82130000(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x823b8658
	ctx.lr = 0x823B6DD8;
	sub_823B8658(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// addi r8,r9,10096
	ctx.r8.s64 = ctx.r9.s64 + 10096;
	// stw r30,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6DF0;
	sub_82130000(ctx, base);
	// stw r3,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r23,r1,512
	r23.s64 = ctx.r1.s64 + 512;
	// bl 0x823b99d0
	ctx.lr = 0x823B6E00;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6E0C;
	sub_823B9430(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6E18;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,14896
	ctx.r6.s64 = ctx.r7.s64 + 14896;
	// stw r6,532(r1)
	PPC_STORE_U32(ctx.r1.u32 + 532, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6E30;
	sub_82130000(ctx, base);
	// stw r3,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r3.u32);
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B6E40;
	sub_823B8660(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,15144
	ctx.r4.s64 = ctx.r5.s64 + 15144;
	// stw r4,548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 548, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6E58;
	sub_82130000(ctx, base);
	// stw r3,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, ctx.r3.u32);
	// addi r4,r1,544
	ctx.r4.s64 = ctx.r1.s64 + 544;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B6E68;
	sub_823B8678(ctx, base);
	// lis r3,-32196
	ctx.r3.s64 = -2109997056;
	// stw r30,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, r30.u32);
	// addi r11,r3,-22472
	r11.s64 = ctx.r3.s64 + -22472;
	// stw r11,564(r1)
	PPC_STORE_U32(ctx.r1.u32 + 564, r11.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x82130000
	ctx.lr = 0x823B6E80;
	sub_82130000(ctx, base);
	// stw r3,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r10,-31292
	r20.s64 = ctx.r10.s64 + -31292;
	// addi r27,r1,560
	r27.s64 = ctx.r1.s64 + 560;
	// bl 0x823b99d0
	ctx.lr = 0x823B6E98;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6EA4;
	sub_823B9430(ctx, base);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B6EB4;
	sub_823B86E0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,10096
	ctx.r8.s64 = ctx.r9.s64 + 10096;
	// stw r8,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6ECC;
	sub_82130000(ctx, base);
	// stw r3,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r23,r1,576
	r23.s64 = ctx.r1.s64 + 576;
	// bl 0x823b99d0
	ctx.lr = 0x823B6EDC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6EE8;
	sub_823B9430(ctx, base);
	// lwz r27,584(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 584);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B6EF8;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,14896
	ctx.r6.s64 = ctx.r7.s64 + 14896;
	// stw r6,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6F10;
	sub_82130000(ctx, base);
	// stw r3,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r3.u32);
	// addi r4,r1,592
	ctx.r4.s64 = ctx.r1.s64 + 592;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B6F20;
	sub_823B8660(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,15184
	ctx.r4.s64 = ctx.r5.s64 + 15184;
	// stw r4,612(r1)
	PPC_STORE_U32(ctx.r1.u32 + 612, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6F38;
	sub_82130000(ctx, base);
	// stw r3,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, ctx.r3.u32);
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B6F48;
	sub_823B8678(ctx, base);
	// lis r3,-32196
	ctx.r3.s64 = -2109997056;
	// stw r30,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, r30.u32);
	// addi r11,r3,-22472
	r11.s64 = ctx.r3.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6F60;
	sub_82130000(ctx, base);
	// stw r3,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r23,r1,624
	r23.s64 = ctx.r1.s64 + 624;
	// bl 0x823b99d0
	ctx.lr = 0x823B6F70;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6F7C;
	sub_823B9430(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B6F8C;
	sub_823B86E0(ctx, base);
	// lis r10,-32196
	ctx.r10.s64 = -2109997056;
	// stw r30,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, r30.u32);
	// addi r9,r10,-22472
	ctx.r9.s64 = ctx.r10.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r9,644(r1)
	PPC_STORE_U32(ctx.r1.u32 + 644, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6FA4;
	sub_82130000(ctx, base);
	// stw r3,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, ctx.r3.u32);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r19,r8,-31340
	r19.s64 = ctx.r8.s64 + -31340;
	// addi r18,r1,640
	r18.s64 = ctx.r1.s64 + 640;
	// bl 0x823b99d0
	ctx.lr = 0x823B6FBC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B6FC8;
	sub_823B9430(ctx, base);
	// lwz r23,776(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 776);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B6FDC;
	sub_823B86E0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,14896
	ctx.r6.s64 = ctx.r7.s64 + 14896;
	// stw r6,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B6FF4;
	sub_82130000(ctx, base);
	// stw r3,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r3.u32);
	// addi r4,r1,656
	ctx.r4.s64 = ctx.r1.s64 + 656;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B7004;
	sub_823B8660(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,15144
	ctx.r4.s64 = ctx.r5.s64 + 15144;
	// stw r4,676(r1)
	PPC_STORE_U32(ctx.r1.u32 + 676, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B701C;
	sub_82130000(ctx, base);
	// stw r3,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, ctx.r3.u32);
	// addi r4,r1,672
	ctx.r4.s64 = ctx.r1.s64 + 672;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B702C;
	sub_823B8678(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,10096
	ctx.r10.s64 = r11.s64 + 10096;
	// stw r10,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7044;
	sub_82130000(ctx, base);
	// stw r3,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r19,r1,688
	r19.s64 = ctx.r1.s64 + 688;
	// bl 0x823b99d0
	ctx.lr = 0x823B7054;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B7060;
	sub_823B9430(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B706C;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,15256
	ctx.r8.s64 = ctx.r9.s64 + 15256;
	// stw r8,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7084;
	sub_82130000(ctx, base);
	// stw r3,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r1,704
	ctx.r4.s64 = ctx.r1.s64 + 704;
	// bl 0x823b8660
	ctx.lr = 0x823B7094;
	sub_823B8660(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r30.u32);
	// addi r6,r7,15488
	ctx.r6.s64 = ctx.r7.s64 + 15488;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B70AC;
	sub_82130000(ctx, base);
	// stw r3,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r1,720
	ctx.r4.s64 = ctx.r1.s64 + 720;
	// bl 0x823b8678
	ctx.lr = 0x823B70BC;
	sub_823B8678(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// stw r30,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, r30.u32);
	// addi r4,r5,-22472
	ctx.r4.s64 = ctx.r5.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r4,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B70D4;
	sub_82130000(ctx, base);
	// stw r3,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r19,r1,736
	r19.s64 = ctx.r1.s64 + 736;
	// bl 0x823b99d0
	ctx.lr = 0x823B70E4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B70F0;
	sub_823B9430(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B7100;
	sub_823B86E0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,10632
	ctx.r10.s64 = r11.s64 + 10632;
	// stw r10,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7118;
	sub_82130000(ctx, base);
	// stw r3,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,752
	r20.s64 = ctx.r1.s64 + 752;
	// bl 0x823b99d0
	ctx.lr = 0x823B7128;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B7134;
	sub_823B9430(ctx, base);
	// lwz r27,136(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B7144;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,15544
	ctx.r8.s64 = ctx.r9.s64 + 15544;
	// stw r8,772(r1)
	PPC_STORE_U32(ctx.r1.u32 + 772, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B715C;
	sub_82130000(ctx, base);
	// stw r3,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r1,768
	ctx.r4.s64 = ctx.r1.s64 + 768;
	// bl 0x823b8678
	ctx.lr = 0x823B716C;
	sub_823B8678(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 784, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,10672
	ctx.r6.s64 = ctx.r7.s64 + 10672;
	// stw r6,788(r1)
	PPC_STORE_U32(ctx.r1.u32 + 788, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7184;
	sub_82130000(ctx, base);
	// stw r3,784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 784, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r20,r1,784
	r20.s64 = ctx.r1.s64 + 784;
	// bl 0x823b99d0
	ctx.lr = 0x823B7194;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B71A0;
	sub_823B9430(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B71AC;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,10672
	ctx.r4.s64 = ctx.r5.s64 + 10672;
	// stw r4,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B71C4;
	sub_82130000(ctx, base);
	// stw r3,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r27,r1,800
	r27.s64 = ctx.r1.s64 + 800;
	// bl 0x823b99d0
	ctx.lr = 0x823B71D4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B71E0;
	sub_823B9430(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B71EC;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 816, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,15728
	ctx.r10.s64 = r11.s64 + 15728;
	// stw r10,820(r1)
	PPC_STORE_U32(ctx.r1.u32 + 820, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7204;
	sub_82130000(ctx, base);
	// stw r3,816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 816, ctx.r3.u32);
	// addi r4,r1,816
	ctx.r4.s64 = ctx.r1.s64 + 816;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B7214;
	sub_823B8660(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,16600
	ctx.r8.s64 = ctx.r9.s64 + 16600;
	// stw r8,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B722C;
	sub_82130000(ctx, base);
	// stw r3,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r3.u32);
	// addi r4,r1,832
	ctx.r4.s64 = ctx.r1.s64 + 832;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B723C;
	sub_823B8678(ctx, base);
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,0
	ctx.r6.s64 = ctx.r7.s64 + 0;
	// stw r6,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7250;
	sub_82130000(ctx, base);
	// stw r3,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r3.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// ld r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// bl 0x823b8658
	ctx.lr = 0x823B7260;
	sub_823B8658(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// addi r4,r5,-22472
	ctx.r4.s64 = ctx.r5.s64 + -22472;
	// stw r30,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r4,852(r1)
	PPC_STORE_U32(ctx.r1.u32 + 852, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7278;
	sub_82130000(ctx, base);
	// stw r3,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r27,r11,-31456
	r27.s64 = r11.s64 + -31456;
	// addi r23,r1,848
	r23.s64 = ctx.r1.s64 + 848;
	// bl 0x823b99d0
	ctx.lr = 0x823B7290;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B729C;
	sub_823B9430(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B72AC;
	sub_823B86E0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,15632
	ctx.r9.s64 = ctx.r10.s64 + 15632;
	// stw r9,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B72C4;
	sub_82130000(ctx, base);
	// stw r3,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, ctx.r3.u32);
	// lwz r27,112(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r4,r1,864
	ctx.r4.s64 = ctx.r1.s64 + 864;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B72D8;
	sub_823B8660(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,880(r1)
	PPC_STORE_U32(ctx.r1.u32 + 880, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,16600
	ctx.r7.s64 = ctx.r8.s64 + 16600;
	// stw r7,884(r1)
	PPC_STORE_U32(ctx.r1.u32 + 884, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B72F0;
	sub_82130000(ctx, base);
	// stw r3,880(r1)
	PPC_STORE_U32(ctx.r1.u32 + 880, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r1,880
	ctx.r4.s64 = ctx.r1.s64 + 880;
	// bl 0x823b8678
	ctx.lr = 0x823B7300;
	sub_823B8678(ctx, base);
	// lis r6,-32198
	ctx.r6.s64 = -2110128128;
	// stw r30,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, r30.u32);
	// addi r5,r6,13632
	ctx.r5.s64 = ctx.r6.s64 + 13632;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r5,900(r1)
	PPC_STORE_U32(ctx.r1.u32 + 900, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7318;
	sub_82130000(ctx, base);
	// stw r3,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r23,r1,896
	r23.s64 = ctx.r1.s64 + 896;
	// bl 0x823b99d0
	ctx.lr = 0x823B7328;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B7334;
	sub_823B9430(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B7340;
	sub_823B86A0(ctx, base);
	// lis r4,-32196
	ctx.r4.s64 = -2109997056;
	// stw r30,912(r1)
	PPC_STORE_U32(ctx.r1.u32 + 912, r30.u32);
	// addi r11,r4,-22472
	r11.s64 = ctx.r4.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,916(r1)
	PPC_STORE_U32(ctx.r1.u32 + 916, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B7358;
	sub_82130000(ctx, base);
	// stw r3,912(r1)
	PPC_STORE_U32(ctx.r1.u32 + 912, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r23,r10,31016
	r23.s64 = ctx.r10.s64 + 31016;
	// addi r22,r1,912
	r22.s64 = ctx.r1.s64 + 912;
	// bl 0x823b99d0
	ctx.lr = 0x823B7370;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B737C;
	sub_823B9430(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B738C;
	sub_823B86E0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,10920
	ctx.r8.s64 = ctx.r9.s64 + 10920;
	// stw r8,932(r1)
	PPC_STORE_U32(ctx.r1.u32 + 932, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B73A4;
	sub_82130000(ctx, base);
	// stw r3,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, ctx.r3.u32);
	// addi r4,r1,928
	ctx.r4.s64 = ctx.r1.s64 + 928;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B73B4;
	sub_823B8660(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,944(r1)
	PPC_STORE_U32(ctx.r1.u32 + 944, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,8944
	ctx.r6.s64 = ctx.r7.s64 + 8944;
	// stw r6,948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 948, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B73CC;
	sub_82130000(ctx, base);
	// stw r3,944(r1)
	PPC_STORE_U32(ctx.r1.u32 + 944, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r1,944
	r28.s64 = ctx.r1.s64 + 944;
	// bl 0x823b99d0
	ctx.lr = 0x823B73DC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B73E8;
	sub_823B9430(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B73F4;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,9032
	ctx.r4.s64 = ctx.r5.s64 + 9032;
	// stw r4,964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 964, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B740C;
	sub_82130000(ctx, base);
	// stw r3,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r1,960
	r28.s64 = ctx.r1.s64 + 960;
	// bl 0x823b99d0
	ctx.lr = 0x823B741C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B7428;
	sub_823B9430(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B7434;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,9120
	ctx.r10.s64 = r11.s64 + 9120;
	// stw r10,980(r1)
	PPC_STORE_U32(ctx.r1.u32 + 980, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B744C;
	sub_82130000(ctx, base);
	// stw r3,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r1,976
	r28.s64 = ctx.r1.s64 + 976;
	// bl 0x823b99d0
	ctx.lr = 0x823B745C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B7468;
	sub_823B9430(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B7474;
	sub_823B86A0(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// stw r30,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, r30.u32);
	// addi r8,r9,-22472
	ctx.r8.s64 = ctx.r9.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r8,996(r1)
	PPC_STORE_U32(ctx.r1.u32 + 996, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B748C;
	sub_82130000(ctx, base);
	// stw r3,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, ctx.r3.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r7,30992
	r31.s64 = ctx.r7.s64 + 30992;
	// addi r30,r1,992
	r30.s64 = ctx.r1.s64 + 992;
	// bl 0x823b99d0
	ctx.lr = 0x823B74A4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B74B0;
	sub_823B9430(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B74C0;
	sub_823B86E0(ctx, base);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_823B59A8) {
	__imp__sub_823B59A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B74C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f13,31300(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31300);
	ctx.f13.f64 = double(temp.f32);
	// fabs f11,f12
	ctx.f11.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// blt cr6,0x823b74ec
	if (cr6.lt) goto loc_823B74EC;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823B74EC:
	// lfs f12,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fabs f11,f0
	ctx.f11.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// blt cr6,0x823b7508
	if (cr6.lt) goto loc_823B7508;
	// li r11,0
	r11.s64 = 0;
loc_823B7508:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b7528
	if (cr6.eq) goto loc_823B7528;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7528
	if (cr6.eq) goto loc_823B7528;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
loc_823B7528:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x823b7544
	if (cr6.lt) goto loc_823B7544;
	// fsubs f0,f0,f2
	f0.f64 = double(float(f0.f64 - ctx.f2.f64));
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
loc_823B7544:
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x823b7564
	if (!cr6.lt) goto loc_823B7564;
	// fsubs f0,f1,f12
	f0.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmadds f10,f11,f2,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f2.f64 + ctx.f12.f64));
	// stfs f10,12(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
loc_823B7564:
	// lfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B74C8) {
	__imp__sub_823B74C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B756C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B756C) {
	__imp__sub_823B756C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7570) {
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
	// bl 0x823b8d88
	ctx.lr = 0x823B7588;
	sub_823B8D88(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-30192
	ctx.r9.s64 = ctx.r10.s64 + -30192;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// lfs f0,14884(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stb r11,44(r31)
	PPC_STORE_U8(r31.u32 + 44, r11.u8);
	// lfs f13,27640(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,45(r31)
	PPC_STORE_U8(r31.u32 + 45, r11.u8);
	// lfs f12,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f12,64(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
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

PPC_WEAK_FUNC(sub_823B7570) {
	__imp__sub_823B7570(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B75F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B75F4) {
	__imp__sub_823B75F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B75F8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,256
	ctx.r3.s64 = 256;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r6,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r6.u32);
	// stw r4,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r4.u32);
	// bl 0x82130528
	ctx.lr = 0x823B7624;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b7634
	if (cr6.eq) goto loc_823B7634;
	// bl 0x823ba000
	ctx.lr = 0x823B7630;
	sub_823BA000(ctx, base);
	// b 0x823b7638
	goto loc_823B7638;
loc_823B7634:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B7638:
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b8768
	ctx.lr = 0x823B7648;
	sub_823B8768(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B75F8) {
	__imp__sub_823B75F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7660) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823b87b8
	ctx.lr = 0x823B7678;
	sub_823B87B8(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823b768c
	if (cr6.eq) goto loc_823B768C;
	// stw r10,252(r11)
	PPC_STORE_U32(r11.u32 + 252, ctx.r10.u32);
loc_823B768C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// stb r10,44(r31)
	PPC_STORE_U8(r31.u32 + 44, ctx.r10.u8);
	// stb r10,45(r31)
	PPC_STORE_U8(r31.u32 + 45, ctx.r10.u8);
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
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

PPC_WEAK_FUNC(sub_823B7660) {
	__imp__sub_823B7660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B76C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lbz r11,44(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7784
	if (cr6.eq) goto loc_823B7784;
	// lbz r11,45(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 45);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b7750
	if (!cr6.eq) goto loc_823B7750;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lbz r10,688(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 688);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b7750
	if (cr6.eq) goto loc_823B7750;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a61a0
	ctx.lr = 0x823B770C;
	sub_823A61A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7750
	if (cr6.eq) goto loc_823B7750;
	// li r11,1
	r11.s64 = 1;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stb r11,45(r31)
	PPC_STORE_U8(r31.u32 + 45, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-32012
	ctx.r4.s64 = ctx.r10.s64 + -32012;
	// bl 0x823b87d8
	ctx.lr = 0x823B7734;
	sub_823B87D8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a7ca8
	ctx.lr = 0x823B774C;
	sub_823A7CA8(ctx, base);
	// b 0x823b7784
	goto loc_823B7784;
loc_823B7750:
	// lbz r11,45(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 45);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7784
	if (cr6.eq) goto loc_823B7784;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lbz r10,688(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 688);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b7784
	if (!cr6.eq) goto loc_823B7784;
	// li r11,0
	r11.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stb r11,45(r31)
	PPC_STORE_U8(r31.u32 + 45, r11.u8);
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a7e30
	ctx.lr = 0x823B7784;
	sub_823A7E30(ctx, base);
loc_823B7784:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B76C0) {
	__imp__sub_823B76C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B779C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B779C) {
	__imp__sub_823B779C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B77A0) {
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
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a8020
	ctx.lr = 0x823B77C8;
	sub_823A8020(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x822a86e8
	ctx.lr = 0x823B77D0;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b77e4
	if (cr6.eq) goto loc_823B77E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b76c0
	ctx.lr = 0x823B77E4;
	sub_823B76C0(ctx, base);
loc_823B77E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823b8ea0
	ctx.lr = 0x823B77F0;
	sub_823B8EA0(ctx, base);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,108(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823b7810
	if (!cr6.eq) goto loc_823B7810;
	// lwz r11,112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x823b7814
	if (cr6.eq) goto loc_823B7814;
loc_823B7810:
	// li r11,1
	r11.s64 = 1;
loc_823B7814:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b783c
	if (cr6.eq) goto loc_823B783C;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x823a3580
	ctx.lr = 0x823B7828;
	sub_823A3580(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x823b74c8
	ctx.lr = 0x823B7834;
	sub_823B74C8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a70d0
	ctx.lr = 0x823B783C;
	sub_823A70D0(ctx, base);
loc_823B783C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b7860
	if (!cr6.eq) goto loc_823B7860;
	// rlwinm r11,r11,12,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7864
	if (cr6.eq) goto loc_823B7864;
loc_823B7860:
	// li r5,1
	ctx.r5.s64 = 1;
loc_823B7864:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823a6498
	ctx.lr = 0x823B7870;
	sub_823A6498(ctx, base);
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

PPC_WEAK_FUNC(sub_823B77A0) {
	__imp__sub_823B77A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B788C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B788C) {
	__imp__sub_823B788C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7890) {
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
	ctx.lr = 0x823B7898;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823b78e4
	if (cr6.eq) goto loc_823B78E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B78C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b78e4
	if (cr6.eq) goto loc_823B78E4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B78DC;
	sub_823B87D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823B78E4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B7890) {
	__imp__sub_823B7890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B78F0) {
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
	ctx.lr = 0x823B78F8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823b7964
	if (cr6.eq) goto loc_823B7964;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B7924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b7964
	if (cr6.eq) goto loc_823B7964;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r10,-26992
	ctx.r5.s64 = ctx.r10.s64 + -26992;
	// addi r7,r11,144
	ctx.r7.s64 = r11.s64 + 144;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823B7950;
	sub_82137A08(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823B795C;
	sub_823B87D8(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
loc_823B7964:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B78F0) {
	__imp__sub_823B78F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823b7990
	if (cr6.eq) goto loc_823B7990;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823B7990:
	// b 0x823b8690
	sub_823B8690(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B7970) {
	__imp__sub_823B7970(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B7994) {
	__imp__sub_823B7994(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7998) {
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
	ctx.lr = 0x823B79A0;
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
	// beq cr6,0x823b7a04
	if (cr6.eq) goto loc_823B7A04;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823b7a04
	if (cr6.eq) goto loc_823B7A04;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B79D4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b7a04
	if (cr6.eq) goto loc_823B7A04;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B79E8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x823ba168
	ctx.lr = 0x823B79FC;
	sub_823BA168(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823B7A04:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_823B7998) {
	__imp__sub_823B7998(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B7A14) {
	__imp__sub_823B7A14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7A18) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-30192
	ctx.r10.s64 = r11.s64 + -30192;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b7a58
	if (cr6.eq) goto loc_823B7A58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B7A58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823B7A58:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// bl 0x823b9348
	ctx.lr = 0x823B7A74;
	sub_823B9348(ctx, base);
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

PPC_WEAK_FUNC(sub_823B7A18) {
	__imp__sub_823B7A18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7A88) {
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
	// bl 0x823b7a18
	ctx.lr = 0x823B7AA8;
	sub_823B7A18(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7ac0
	if (cr6.eq) goto loc_823B7AC0;
	// bl 0x82130588
	ctx.lr = 0x823B7ABC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823B7AC0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B7A88) {
	__imp__sub_823B7A88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7AD8) {
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
	// bl 0x823b9790
	ctx.lr = 0x823B7AF0;
	sub_823B9790(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r10,r11,-30192
	ctx.r10.s64 = r11.s64 + -30192;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x823B7B04;
	sub_821B5A60(ctx, base);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x821b5a60
	ctx.lr = 0x823B7B0C;
	sub_821B5A60(ctx, base);
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x823b7998
	ctx.lr = 0x823B7B14;
	sub_823B7998(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x821b5a60
	ctx.lr = 0x823B7B1C;
	sub_821B5A60(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f12,64(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
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

PPC_WEAK_FUNC(sub_823B7AD8) {
	__imp__sub_823B7AD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7B60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823b7ad8
	sub_823B7AD8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B7B60) {
	__imp__sub_823B7B60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7B6C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B7B6C) {
	__imp__sub_823B7B6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7B70) {
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
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x821ce100
	ctx.lr = 0x823B7B8C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823b7bb8
	if (!cr6.eq) goto loc_823B7BB8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823b7bb4
	if (cr6.eq) goto loc_823B7BB4;
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
	ctx.lr = 0x823B7BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823B7BB4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B7BB8:
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

PPC_WEAK_FUNC(sub_823B7B70) {
	__imp__sub_823B7B70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B7BCC) {
	__imp__sub_823B7BCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7BD0) {
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
	ctx.lr = 0x823B7BD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7c00
	if (cr6.eq) goto loc_823B7C00;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r30,r11,-29828
	r30.s64 = r11.s64 + -29828;
	// b 0x823b7c08
	goto loc_823B7C08;
loc_823B7C00:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r30,r11,-29836
	r30.s64 = r11.s64 + -29836;
loc_823B7C08:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,-29860
	ctx.r4.s64 = r11.s64 + -29860;
	// bl 0x823dd800
	ctx.lr = 0x823B7C1C;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823b7c2c
	if (!cr6.eq) goto loc_823B7C2C;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// b 0x823b7c44
	goto loc_823B7C44;
loc_823B7C2C:
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// ble cr6,0x823b7c3c
	if (!cr6.gt) goto loc_823B7C3C;
	// li r10,3
	ctx.r10.s64 = 3;
loc_823B7C3C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
loc_823B7C44:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,-29856
	ctx.r5.s64 = r11.s64 + -29856;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x823B7C5C;
	sub_82137A08(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823B7BD0) {
	__imp__sub_823B7BD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7C68) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// bl 0x82137a08
	ctx.lr = 0x823B7C9C;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823de4d8
	ctx.lr = 0x823B7CA4;
	sub_823DE4D8(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,-29820
	ctx.r4.s64 = ctx.r10.s64 + -29820;
	// bl 0x823d90b0
	ctx.lr = 0x823B7CB4;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b7ce4
	if (cr6.eq) goto loc_823B7CE4;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823B7CC0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b7cc0
	if (!cr6.eq) goto loc_823B7CC0;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stb r10,-4(r8)
	PPC_STORE_U8(ctx.r8.u32 + -4, ctx.r10.u8);
loc_823B7CE4:
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

PPC_WEAK_FUNC(sub_823B7C68) {
	__imp__sub_823B7C68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7D00) {
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
	ctx.lr = 0x823B7D08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// rlwinm r5,r9,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823B7D38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823b7d5c
	if (cr6.eq) goto loc_823B7D5C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r5,776(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-29812
	ctx.r3.s64 = r11.s64 + -29812;
	// bl 0x82130000
	ctx.lr = 0x823B7D5C;
	sub_82130000(ctx, base);
loc_823B7D5C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B7D00) {
	__imp__sub_823B7D00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7D68) {
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
	ctx.lr = 0x823B7D70;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,1548(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1548);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823b7ddc
	if (!cr6.gt) goto loc_823B7DDC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r29,780
	r30.s64 = r29.s64 + 780;
	// addi r28,r11,3998
	r28.s64 = r11.s64 + 3998;
loc_823B7D9C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b7e00
	if (cr6.eq) goto loc_823B7E00;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b7dc8
	if (cr6.eq) goto loc_823B7DC8;
loc_823B7DB8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823db730
	ctx.lr = 0x823B7DC0;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823b7e08
	if (cr6.eq) goto loc_823B7E08;
loc_823B7DC8:
	// lwz r11,1548(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1548);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823b7d9c
	if (cr6.lt) goto loc_823B7D9C;
loc_823B7DDC:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7df4
	if (cr6.eq) goto loc_823B7DF4;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-29756
	ctx.r3.s64 = r11.s64 + -29756;
	// bl 0x821bd618
	ctx.lr = 0x823B7DF4;
	sub_821BD618(ctx, base);
loc_823B7DF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823B7E00:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// b 0x823b7db8
	goto loc_823B7DB8;
loc_823B7E08:
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_823B7D68) {
	__imp__sub_823B7D68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B7E1C) {
	__imp__sub_823B7E1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B7E20) {
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
	ctx.lr = 0x823B7E28;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r29,r11,3664
	r29.s64 = r11.s64 + 3664;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r26,r10,30576
	r26.s64 = ctx.r10.s64 + 30576;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r30,r9,-26992
	r30.s64 = ctx.r9.s64 + -26992;
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// mr r25,r11
	r25.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b7f38
	if (!cr6.eq) goto loc_823B7F38;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x823b7e94
	if (cr6.eq) goto loc_823B7E94;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r5,r11,23492
	ctx.r5.s64 = r11.s64 + 23492;
	// b 0x823b7e98
	goto loc_823B7E98;
loc_823B7E94:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
loc_823B7E98:
	// bl 0x82137a08
	ctx.lr = 0x823B7E9C;
	sub_82137A08(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca778
	ctx.lr = 0x823B7EAC;
	sub_821CA778(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b7f38
	if (cr6.eq) goto loc_823B7F38;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82507720
	ctx.lr = 0x823B7ECC;
	sub_82507720(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823b7f38
	if (cr6.eq) goto loc_823B7F38;
	// lwz r11,776(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// li r3,8
	ctx.r3.s64 = 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,776(r31)
	PPC_STORE_U32(r31.u32 + 776, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82130528
	ctx.lr = 0x823B7EF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b7f10
	if (cr6.eq) goto loc_823B7F10;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82137248
	ctx.lr = 0x823B7F08;
	sub_82137248(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// b 0x823b7f14
	goto loc_823B7F14;
loc_823B7F10:
	// li r8,0
	ctx.r8.s64 = 0;
loc_823B7F14:
	// lwz r11,1548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1548);
	// addi r10,r31,780
	ctx.r10.s64 = r31.s64 + 780;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1548(r31)
	PPC_STORE_U32(r31.u32 + 1548, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
loc_823B7F38:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r6,r11,-29576
	ctx.r6.s64 = r11.s64 + -29576;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823B7F54;
	sub_82137A08(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r10,-29612
	ctx.r4.s64 = ctx.r10.s64 + -29612;
	// bl 0x821ca540
	ctx.lr = 0x823B7F64;
	sub_821CA540(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca778
	ctx.lr = 0x823B7F74;
	sub_821CA778(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b8028
	if (cr6.eq) goto loc_823B8028;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82507720
	ctx.lr = 0x823B7F94;
	sub_82507720(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823b8028
	if (cr6.eq) goto loc_823B8028;
	// lwz r11,776(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// li r3,8
	ctx.r3.s64 = 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,776(r31)
	PPC_STORE_U32(r31.u32 + 776, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82130528
	ctx.lr = 0x823B7FC0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b7fd4
	if (cr6.eq) goto loc_823B7FD4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82137248
	ctx.lr = 0x823B7FD0;
	sub_82137248(ctx, base);
	// b 0x823b7fd8
	goto loc_823B7FD8;
loc_823B7FD4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B7FD8:
	// lwz r11,1548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1548);
	// addi r10,r31,780
	ctx.r10.s64 = r31.s64 + 780;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1548(r31)
	PPC_STORE_U32(r31.u32 + 1548, r11.u32);
	// stwx r3,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r3.u32);
	// bne cr6,0x823b8010
	if (!cr6.eq) goto loc_823B8010;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-29688
	ctx.r3.s64 = r11.s64 + -29688;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x823B8010;
	sub_82130000(ctx, base);
loc_823B8010:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r31,1
	r31.s64 = 1;
	// bl 0x821c9a90
	ctx.lr = 0x823B801C;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
loc_823B8028:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-29728
	ctx.r3.s64 = r11.s64 + -29728;
	// bl 0x82130000
	ctx.lr = 0x823B8038;
	sub_82130000(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x821c9a90
	ctx.lr = 0x823B8044;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_823B7E20) {
	__imp__sub_823B7E20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8050) {
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
	ctx.lr = 0x823B8058;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823B807C;
	sub_82137A08(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r29,r11,3664
	r29.s64 = r11.s64 + 3664;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823B8090;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b80c8
	if (cr6.eq) goto loc_823B80C8;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823B809C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b809c
	if (!cr6.eq) goto loc_823B809C;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stb r9,-5(r8)
	PPC_STORE_U8(ctx.r8.u32 + -5, ctx.r9.u8);
loc_823B80C8:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r11,30576
	ctx.r3.s64 = r11.s64 + 30576;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca778
	ctx.lr = 0x823B80DC;
	sub_821CA778(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b8168
	if (cr6.eq) goto loc_823B8168;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82507720
	ctx.lr = 0x823B80FC;
	sub_82507720(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823b8168
	if (cr6.eq) goto loc_823B8168;
	// lwz r11,776(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// li r3,8
	ctx.r3.s64 = 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,776(r31)
	PPC_STORE_U32(r31.u32 + 776, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82130528
	ctx.lr = 0x823B8128;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b8140
	if (cr6.eq) goto loc_823B8140;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82137248
	ctx.lr = 0x823B8138;
	sub_82137248(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// b 0x823b8144
	goto loc_823B8144;
loc_823B8140:
	// li r8,0
	ctx.r8.s64 = 0;
loc_823B8144:
	// lwz r11,1548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1548);
	// addi r10,r31,780
	ctx.r10.s64 = r31.s64 + 780;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1548(r31)
	PPC_STORE_U32(r31.u32 + 1548, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d924c
	return;
loc_823B8168:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B8050) {
	__imp__sub_823B8050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8174) {
	__imp__sub_823B8174(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8178) {
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
	ctx.lr = 0x823B8180;
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
	// lwz r11,776(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 776);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823b81f0
	if (!cr6.gt) goto loc_823B81F0;
	// addi r29,r30,8
	r29.s64 = r30.s64 + 8;
loc_823B81A0:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x823b81dc
	if (cr6.eq) goto loc_823B81DC;
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x821ce100
	ctx.lr = 0x823B81B4;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823b81dc
	if (!cr6.eq) goto loc_823B81DC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823b81dc
	if (cr6.eq) goto loc_823B81DC;
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
	ctx.lr = 0x823B81DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823B81DC:
	// lwz r11,776(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 776);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x823b81a0
	if (cr6.lt) goto loc_823B81A0;
loc_823B81F0:
	// lwz r11,1548(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1548);
	// mr r29,r27
	r29.u64 = r27.u64;
	// stw r27,776(r30)
	PPC_STORE_U32(r30.u32 + 776, r27.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823b8238
	if (!cr6.gt) goto loc_823B8238;
	// addi r31,r30,780
	r31.s64 = r30.s64 + 780;
loc_823B8208:
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823b8224
	if (cr6.eq) goto loc_823B8224;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823B821C;
	sub_82130588(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x823B8224;
	sub_82130588(ctx, base);
loc_823B8224:
	// lwz r11,1548(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1548);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823b8208
	if (cr6.lt) goto loc_823B8208;
loc_823B8238:
	// stw r27,1548(r30)
	PPC_STORE_U32(r30.u32 + 1548, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_823B8178) {
	__imp__sub_823B8178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8244) {
	__imp__sub_823B8244(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8248) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-29552
	ctx.r10.s64 = r11.s64 + -29552;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b8178
	ctx.lr = 0x823B826C;
	sub_823B8178(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x823B8274;
	sub_821D2810(ctx, base);
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

PPC_WEAK_FUNC(sub_823B8248) {
	__imp__sub_823B8248(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8288) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-29552
	ctx.r10.s64 = r11.s64 + -29552;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b8178
	ctx.lr = 0x823B82B4;
	sub_823B8178(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x823B82BC;
	sub_821D2810(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b82d4
	if (cr6.eq) goto loc_823B82D4;
	// bl 0x82130588
	ctx.lr = 0x823B82D0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823B82D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8288) {
	__imp__sub_823B8288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B82EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B82EC) {
	__imp__sub_823B82EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B82F0) {
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
	ctx.lr = 0x823B82F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r26,191
	r26.s64 = 191;
	// li r24,0
	r24.s64 = 0;
loc_823B8314:
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b8364
	if (cr6.eq) goto loc_823B8364;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823b8364
	if (cr6.eq) goto loc_823B8364;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B8338;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b8364
	if (cr6.eq) goto loc_823B8364;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B834C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x82504be0
	ctx.lr = 0x823B8360;
	sub_82504BE0(ctx, base);
	// b 0x823b8368
	goto loc_823B8368;
loc_823B8364:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_823B8368:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bge 0x823b8314
	if (!cr0.lt) goto loc_823B8314;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r24,768(r25)
	PPC_STORE_U32(r25.u32 + 768, r24.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823B82F0) {
	__imp__sub_823B82F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8384) {
	__imp__sub_823B8384(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8388) {
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
	ctx.lr = 0x823B8390;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r26,191
	r26.s64 = 191;
	// li r24,0
	r24.s64 = 0;
loc_823B83AC:
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b83fc
	if (cr6.eq) goto loc_823B83FC;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823b83fc
	if (cr6.eq) goto loc_823B83FC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B83D0;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b83fc
	if (cr6.eq) goto loc_823B83FC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B83E4;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x82504be0
	ctx.lr = 0x823B83F8;
	sub_82504BE0(ctx, base);
	// b 0x823b8400
	goto loc_823B8400;
loc_823B83FC:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_823B8400:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bge 0x823b83ac
	if (!cr0.lt) goto loc_823B83AC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823B8388) {
	__imp__sub_823B8388(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8418) {
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
	ctx.lr = 0x823B8420;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r26,191
	r26.s64 = 191;
	// li r24,0
	r24.s64 = 0;
loc_823B843C:
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b848c
	if (cr6.eq) goto loc_823B848C;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823b848c
	if (cr6.eq) goto loc_823B848C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B8460;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b848c
	if (cr6.eq) goto loc_823B848C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B8474;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x821c96f8
	ctx.lr = 0x823B8488;
	sub_821C96F8(ctx, base);
	// b 0x823b8490
	goto loc_823B8490;
loc_823B848C:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_823B8490:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bge 0x823b843c
	if (!cr0.lt) goto loc_823B843C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r24,768(r25)
	PPC_STORE_U32(r25.u32 + 768, r24.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823B8418) {
	__imp__sub_823B8418(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B84AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B84AC) {
	__imp__sub_823B84AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B84B0) {
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
	ctx.lr = 0x823B84B8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r26,191
	r26.s64 = 191;
	// li r24,0
	r24.s64 = 0;
loc_823B84D4:
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b8524
	if (cr6.eq) goto loc_823B8524;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823b8524
	if (cr6.eq) goto loc_823B8524;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B84F8;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b8524
	if (cr6.eq) goto loc_823B8524;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B850C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x821c96f8
	ctx.lr = 0x823B8520;
	sub_821C96F8(ctx, base);
	// b 0x823b8528
	goto loc_823B8528;
loc_823B8524:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_823B8528:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bge 0x823b84d4
	if (!cr0.lt) goto loc_823B84D4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823B84B0) {
	__imp__sub_823B84B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8540) {
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
	// bl 0x821d2970
	ctx.lr = 0x823B8558;
	sub_821D2970(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-29552
	ctx.r10.s64 = r11.s64 + -29552;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b82f0
	ctx.lr = 0x823B856C;
	sub_823B82F0(ctx, base);
	// addi r3,r31,780
	ctx.r3.s64 = r31.s64 + 780;
	// bl 0x823b8418
	ctx.lr = 0x823B8574;
	sub_823B8418(ctx, base);
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

PPC_WEAK_FUNC(sub_823B8540) {
	__imp__sub_823B8540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B858C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B858C) {
	__imp__sub_823B858C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
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
	ctx.lr = 0x823B85B0;
	sub_821D2970(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,-29552
	ctx.r10.s64 = r11.s64 + -29552;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x823b8388
	ctx.lr = 0x823B85CC;
	sub_823B8388(ctx, base);
	// addi r3,r31,780
	ctx.r3.s64 = r31.s64 + 780;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823b84b0
	ctx.lr = 0x823B85DC;
	sub_823B84B0(ctx, base);
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

PPC_WEAK_FUNC(sub_823B8590) {
	__imp__sub_823B8590(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B85F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823b8590
	sub_823B8590(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B85F8) {
	__imp__sub_823B85F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8604) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8604) {
	__imp__sub_823B8604(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8608) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823B8624:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,97
	cr6.compare<int32_t>(ctx.r10.s32, 97, xer);
	// blt cr6,0x823b8644
	if (cr6.lt) goto loc_823B8644;
	// cmpwi cr6,r10,122
	cr6.compare<int32_t>(ctx.r10.s32, 122, xer);
	// bgt cr6,0x823b8644
	if (cr6.gt) goto loc_823B8644;
	// addi r10,r10,-32
	ctx.r10.s64 = ctx.r10.s64 + -32;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_823B8644:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b8624
	if (!cr6.eq) goto loc_823B8624;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8608) {
	__imp__sub_823B8608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8658) {
	PPC_FUNC_PROLOGUE();
	// std r4,12(r3)
	PPC_STORE_U64(ctx.r3.u32 + 12, ctx.r4.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8658) {
	__imp__sub_823B8658(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8660) {
	__imp__sub_823B8660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8674) {
	__imp__sub_823B8674(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8678) {
	__imp__sub_823B8678(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B868C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B868C) {
	__imp__sub_823B868C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8690) {
	__imp__sub_823B8690(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B869C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B869C) {
	__imp__sub_823B869C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B86A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r5,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B86A0) {
	__imp__sub_823B86A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B86B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r9,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// lwz r8,4(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// stw r6,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r6.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B86B8) {
	__imp__sub_823B86B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B86E0) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// sth r10,24(r31)
	PPC_STORE_U16(r31.u32 + 24, ctx.r10.u16);
	// beq cr6,0x823b8748
	if (cr6.eq) goto loc_823B8748;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_823B8724:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b8724
	if (!cr6.eq) goto loc_823B8724;
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823B8748;
	sub_821C9650(ctx, base);
loc_823B8748:
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B86E0) {
	__imp__sub_823B86E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8764) {
	__imp__sub_823B8764(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8768) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r4,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r4.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B8790;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823B87A4;
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

PPC_WEAK_FUNC(sub_823B8768) {
	__imp__sub_823B8768(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B87B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B87B8) {
	__imp__sub_823B87B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B87D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B87D4) {
	__imp__sub_823B87D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B87D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,-11512
	ctx.r10.s64 = r11.s64 + -11512;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b87f4
	if (cr6.eq) goto loc_823B87F4;
	// li r5,1
	ctx.r5.s64 = 1;
loc_823B87F4:
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823B87D8) {
	__imp__sub_823B87D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B87FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B87FC) {
	__imp__sub_823B87FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8800) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b887c
	if (cr6.eq) goto loc_823B887C;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b8830
	if (cr6.eq) goto loc_823B8830;
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x823b8838
	goto loc_823B8838;
loc_823B8830:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
loc_823B8838:
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b8860
	if (cr6.eq) goto loc_823B8860;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823B8850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823B8860:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823B8868:
	// bctrl 
	ctx.lr = 0x823B886C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823B887C:
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bne cr6,0x823b8868
	if (!cr6.eq) goto loc_823B8868;
	// bctrl 
	ctx.lr = 0x823B8894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8800) {
	__imp__sub_823B8800(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B88A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B88A4) {
	__imp__sub_823B88A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B88A8) {
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
	ctx.lr = 0x823B88B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lhz r11,64(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b895c
	if (cr6.eq) goto loc_823B895C;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// beq cr6,0x823b88e4
	if (cr6.eq) goto loc_823B88E4;
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// b 0x823b88e8
	goto loc_823B88E8;
loc_823B88E4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_823B88E8:
	// lhz r11,56(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b88f8
	if (cr6.eq) goto loc_823B88F8;
	// lwz r29,52(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 52);
loc_823B88F8:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8904;
	sub_823B7D68(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8918;
	sub_823B7D68(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8944
	if (cr6.eq) goto loc_823B8944;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B893C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8944:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823B8954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B895C:
	// lhz r11,56(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b89cc
	if (cr6.eq) goto loc_823B89CC;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b897c
	if (cr6.eq) goto loc_823B897C;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// b 0x823b8984
	goto loc_823B8984;
loc_823B897C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
loc_823B8984:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8990;
	sub_823B7D68(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b89b8
	if (cr6.eq) goto loc_823B89B8;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B89B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B89B8:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823B89C0:
	// bctrl 
	ctx.lr = 0x823B89C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B89CC:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bne cr6,0x823b89c0
	if (!cr6.eq) goto loc_823B89C0;
	// bctrl 
	ctx.lr = 0x823B89E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823B88A8) {
	__imp__sub_823B88A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B89EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B89EC) {
	__imp__sub_823B89EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B89F0) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r30,r31,100
	r30.s64 = r31.s64 + 100;
	// addi r10,r11,-29228
	ctx.r10.s64 = r11.s64 + -29228;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x823B8A20;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// sth r11,104(r31)
	PPC_STORE_U16(r31.u32 + 104, r11.u16);
	// sth r11,106(r31)
	PPC_STORE_U16(r31.u32 + 106, r11.u16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b8a44
	if (cr6.eq) goto loc_823B8A44;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823B8A44;
	sub_82130588(ctx, base);
loc_823B8A44:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x823B8A4C;
	sub_82130588(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82130588
	ctx.lr = 0x823B8A54;
	sub_82130588(ctx, base);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82130588
	ctx.lr = 0x823B8A5C;
	sub_82130588(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82130588
	ctx.lr = 0x823B8A64;
	sub_82130588(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823B8A6C;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B89F0) {
	__imp__sub_823B89F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8A84) {
	__imp__sub_823B8A84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8A88) {
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
	ctx.lr = 0x823B8A90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,104(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8ad8
	if (cr6.eq) goto loc_823B8AD8;
	// li r31,0
	r31.s64 = 0;
loc_823B8AAC:
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x823b8800
	ctx.lr = 0x823B8AB8;
	sub_823B8800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b8ae4
	if (!cr6.eq) goto loc_823B8AE4;
	// lhz r11,104(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 104);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x823b8aac
	if (cr6.lt) goto loc_823B8AAC;
loc_823B8AD8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823B8AE4:
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B8A88) {
	__imp__sub_823B8A88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8AF8) {
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
	ctx.lr = 0x823B8B00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lhz r11,96(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8bac
	if (cr6.eq) goto loc_823B8BAC;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// beq cr6,0x823b8b34
	if (cr6.eq) goto loc_823B8B34;
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// b 0x823b8b38
	goto loc_823B8B38;
loc_823B8B34:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_823B8B38:
	// lhz r11,88(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8b48
	if (cr6.eq) goto loc_823B8B48;
	// lwz r29,84(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 84);
loc_823B8B48:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8B54;
	sub_823B7D68(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8B68;
	sub_823B7D68(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8b94
	if (cr6.eq) goto loc_823B8B94;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B8B8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8B94:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823B8BA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8BAC:
	// lhz r11,88(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8c1c
	if (cr6.eq) goto loc_823B8C1C;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8bcc
	if (cr6.eq) goto loc_823B8BCC;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// b 0x823b8bd4
	goto loc_823B8BD4;
loc_823B8BCC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
loc_823B8BD4:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8BE0;
	sub_823B7D68(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8c08
	if (cr6.eq) goto loc_823B8C08;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B8C00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8C08:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823B8C10:
	// bctrl 
	ctx.lr = 0x823B8C14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8C1C:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bne cr6,0x823b8c10
	if (!cr6.eq) goto loc_823B8C10;
	// bctrl 
	ctx.lr = 0x823B8C34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823B8AF8) {
	__imp__sub_823B8AF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8C3C) {
	__imp__sub_823B8C3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8C40) {
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
	ctx.lr = 0x823B8C48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lhz r11,56(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8cf4
	if (cr6.eq) goto loc_823B8CF4;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// beq cr6,0x823b8c7c
	if (cr6.eq) goto loc_823B8C7C;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// b 0x823b8c80
	goto loc_823B8C80;
loc_823B8C7C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_823B8C80:
	// lhz r11,48(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8c90
	if (cr6.eq) goto loc_823B8C90;
	// lwz r29,44(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 44);
loc_823B8C90:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8C9C;
	sub_823B7D68(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8CB0;
	sub_823B7D68(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8cdc
	if (cr6.eq) goto loc_823B8CDC;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B8CD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8CDC:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823B8CEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8CF4:
	// lhz r11,48(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8d64
	if (cr6.eq) goto loc_823B8D64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8d14
	if (cr6.eq) goto loc_823B8D14;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// b 0x823b8d1c
	goto loc_823B8D1C;
loc_823B8D14:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
loc_823B8D1C:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b7d68
	ctx.lr = 0x823B8D28;
	sub_823B7D68(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8d50
	if (cr6.eq) goto loc_823B8D50;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B8D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8D50:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823B8D58:
	// bctrl 
	ctx.lr = 0x823B8D5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823B8D64:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bne cr6,0x823b8d58
	if (!cr6.eq) goto loc_823B8D58;
	// bctrl 
	ctx.lr = 0x823B8D7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823B8C40) {
	__imp__sub_823B8C40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8D84) {
	__imp__sub_823B8D84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8D88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-29220
	ctx.r9.s64 = ctx.r10.s64 + -29220;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// sth r11,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r11.u16);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r11.u16);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8D88) {
	__imp__sub_823B8D88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8DBC) {
	__imp__sub_823B8DBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8DC0) {
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
	ctx.lr = 0x823B8DC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8e20
	if (cr6.eq) goto loc_823B8E20;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_823B8DE8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b8e0c
	if (cr6.eq) goto loc_823B8E0C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B8E0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823B8E0C:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823b8de8
	if (cr6.lt) goto loc_823B8DE8;
loc_823B8E20:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823B8E28;
	sub_82130588(ctx, base);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
	// sth r28,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r28.u16);
	// sth r28,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r28.u16);
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b8e80
	if (cr6.eq) goto loc_823B8E80;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_823B8E48:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b8e6c
	if (cr6.eq) goto loc_823B8E6C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B8E6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823B8E6C:
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823b8e48
	if (cr6.lt) goto loc_823B8E48;
loc_823B8E80:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x823B8E88;
	sub_82130588(ctx, base);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// sth r28,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r28.u16);
	// sth r28,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r28.u16);
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823B8DC0) {
	__imp__sub_823B8DC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8EA0) {
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
	ctx.lr = 0x823B8EA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823b8f64
	if (cr6.eq) goto loc_823B8F64;
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823b8ed8
	if (cr6.eq) goto loc_823B8ED8;
	// bctrl 
	ctx.lr = 0x823B8ED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823b8edc
	goto loc_823B8EDC;
loc_823B8ED8:
	// bctrl 
	ctx.lr = 0x823B8EDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823B8EDC:
	// li r28,3
	r28.s64 = 3;
loc_823B8EE0:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// bl 0x823b8a88
	ctx.lr = 0x823B8EEC;
	sub_823B8A88(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b8f58
	if (cr6.eq) goto loc_823B8F58;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x823b8af8
	ctx.lr = 0x823B8F04;
	sub_823B8AF8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823b88a8
	ctx.lr = 0x823B8F10;
	sub_823B88A8(ctx, base);
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823b8c40
	ctx.lr = 0x823B8F24;
	sub_823B8C40(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823b8f44
	if (cr6.eq) goto loc_823B8F44;
	// bctrl 
	ctx.lr = 0x823B8F40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823b8f48
	goto loc_823B8F48;
loc_823B8F44:
	// bctrl 
	ctx.lr = 0x823B8F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823B8F48:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// li r29,1
	r29.s64 = 1;
	// bgt 0x823b8f58
	if (cr0.gt) goto loc_823B8F58;
	// li r29,0
	r29.s64 = 0;
loc_823B8F58:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b8ee0
	if (!cr6.eq) goto loc_823B8EE0;
loc_823B8F64:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823B8EA0) {
	__imp__sub_823B8EA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B8F6C) {
	__imp__sub_823B8F6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8F70) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-29200
	ctx.r10.s64 = r11.s64 + -29200;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x82130588
	ctx.lr = 0x823B8FA0;
	sub_82130588(ctx, base);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82130588
	ctx.lr = 0x823B8FA8;
	sub_82130588(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x823B8FB0;
	sub_82130588(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b8fc8
	if (cr6.eq) goto loc_823B8FC8;
	// bl 0x82130588
	ctx.lr = 0x823B8FC4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823B8FC8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B8F70) {
	__imp__sub_823B8F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B8FE0) {
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
	ctx.lr = 0x823B8FE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-29200
	ctx.r10.s64 = r11.s64 + -29200;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b9034
	if (cr6.eq) goto loc_823B9034;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9028;
	sub_8217D890(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
loc_823B9034:
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b906c
	if (cr6.eq) goto loc_823B906C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9060;
	sub_8217D890(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
loc_823B906C:
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b908c
	if (cr6.eq) goto loc_823B908C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9080;
	sub_8217D890(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r10.u32);
loc_823B908C:
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// bl 0x821b5a60
	ctx.lr = 0x823B9094;
	sub_821B5A60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B8FE0) {
	__imp__sub_823B8FE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B90A0) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-29228
	ctx.r10.s64 = r11.s64 + -29228;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// sth r30,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r30.u16);
	// sth r30,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r30.u16);
	// beq cr6,0x823b9104
	if (cr6.eq) goto loc_823B9104;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823B90E4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b90e4
	if (!cr6.eq) goto loc_823B90E4;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823B9104;
	sub_821C9650(ctx, base);
loc_823B9104:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// addi r6,r10,0
	ctx.r6.s64 = ctx.r10.s64 + 0;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// addi r5,r9,0
	ctx.r5.s64 = ctx.r9.s64 + 0;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// addi r4,r7,0
	ctx.r4.s64 = ctx.r7.s64 + 0;
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
	// lis r3,-32237
	ctx.r3.s64 = -2112684032;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// stw r5,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r5.u32);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r4,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r4.u32);
	// addi r9,r3,0
	ctx.r9.s64 = ctx.r3.s64 + 0;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// sth r30,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r30.u16);
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// sth r30,50(r31)
	PPC_STORE_U16(r31.u32 + 50, r30.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// sth r30,56(r31)
	PPC_STORE_U16(r31.u32 + 56, r30.u16);
	// sth r30,58(r31)
	PPC_STORE_U16(r31.u32 + 58, r30.u16);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r7,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r7.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// sth r30,88(r31)
	PPC_STORE_U16(r31.u32 + 88, r30.u16);
	// sth r30,90(r31)
	PPC_STORE_U16(r31.u32 + 90, r30.u16);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// sth r30,96(r31)
	PPC_STORE_U16(r31.u32 + 96, r30.u16);
	// sth r30,98(r31)
	PPC_STORE_U16(r31.u32 + 98, r30.u16);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// sth r30,104(r31)
	PPC_STORE_U16(r31.u32 + 104, r30.u16);
	// sth r30,106(r31)
	PPC_STORE_U16(r31.u32 + 106, r30.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B90A0) {
	__imp__sub_823B90A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B91CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B91CC) {
	__imp__sub_823B91CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B91D0) {
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
	// bl 0x823b89f0
	ctx.lr = 0x823B91F0;
	sub_823B89F0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b9208
	if (cr6.eq) goto loc_823B9208;
	// bl 0x82130588
	ctx.lr = 0x823B9204;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823B9208:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B91D0) {
	__imp__sub_823B91D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9220) {
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
	ctx.lr = 0x823B9228;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r11,-29228
	ctx.r10.s64 = r11.s64 + -29228;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b9260
	if (cr6.eq) goto loc_823B9260;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9254;
	sub_8217D890(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_823B9260:
	// li r30,0
	r30.s64 = 0;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b92a4
	if (cr6.eq) goto loc_823B92A4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9298;
	sub_8217D890(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
loc_823B92A4:
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b92c4
	if (cr6.eq) goto loc_823B92C4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B92B8;
	sub_8217D890(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
loc_823B92C4:
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b92fc
	if (cr6.eq) goto loc_823B92FC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B92F0;
	sub_8217D890(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
loc_823B92FC:
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b931c
	if (cr6.eq) goto loc_823B931C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9310;
	sub_8217D890(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
loc_823B931C:
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823b933c
	if (cr6.eq) goto loc_823B933C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9330;
	sub_8217D890(ctx, base);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
loc_823B933C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B9220) {
	__imp__sub_823B9220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9348) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-29220
	ctx.r10.s64 = r11.s64 + -29220;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b8dc0
	ctx.lr = 0x823B936C;
	sub_823B8DC0(ctx, base);
	// lhz r9,18(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b9380
	if (cr6.eq) goto loc_823B9380;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x823B9380;
	sub_82130588(ctx, base);
loc_823B9380:
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b9394
	if (cr6.eq) goto loc_823B9394;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823B9394;
	sub_82130588(ctx, base);
loc_823B9394:
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

PPC_WEAK_FUNC(sub_823B9348) {
	__imp__sub_823B9348(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B93A8) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-29220
	ctx.r10.s64 = r11.s64 + -29220;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b8dc0
	ctx.lr = 0x823B93D4;
	sub_823B8DC0(ctx, base);
	// lhz r9,18(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b93e8
	if (cr6.eq) goto loc_823B93E8;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x823B93E8;
	sub_82130588(ctx, base);
loc_823B93E8:
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b93fc
	if (cr6.eq) goto loc_823B93FC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823B93FC;
	sub_82130588(ctx, base);
loc_823B93FC:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b9414
	if (cr6.eq) goto loc_823B9414;
	// bl 0x82130588
	ctx.lr = 0x823B9410;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823B9414:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B93A8) {
	__imp__sub_823B93A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B942C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B942C) {
	__imp__sub_823B942C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9430) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r3,100
	ctx.r3.s64 = ctx.r3.s64 + 100;
	// bl 0x82504dd8
	ctx.lr = 0x823B9450;
	sub_82504DD8(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
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

PPC_WEAK_FUNC(sub_823B9430) {
	__imp__sub_823B9430(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B946C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B946C) {
	__imp__sub_823B946C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9470) {
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
	ctx.lr = 0x823B9478;
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
	// beq cr6,0x823b94a0
	if (cr6.eq) goto loc_823B94A0;
	// bl 0x8217d890
	ctx.lr = 0x823B9494;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_823B94A0:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b9538
	if (cr6.eq) goto loc_823B9538;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,60
	r26.s64 = 60;
	// mr r27,r23
	r27.u64 = r23.u64;
loc_823B94C0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r26,r25
	r30.u64 = PPC_LOAD_U32(r26.u32 + r25.u32);
	// add r31,r27,r11
	r31.u64 = r27.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b9520
	if (cr6.eq) goto loc_823B9520;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823b9520
	if (cr6.eq) goto loc_823B9520;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B94EC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b9520
	if (cr6.eq) goto loc_823B9520;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9500;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b9524
	if (cr6.eq) goto loc_823B9524;
	// lwzx r4,r26,r25
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + r25.u32);
	// bl 0x823b9220
	ctx.lr = 0x823B951C;
	sub_823B9220(ctx, base);
	// b 0x823b9524
	goto loc_823B9524;
loc_823B9520:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_823B9524:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x823b94c0
	if (cr6.lt) goto loc_823B94C0;
loc_823B9538:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_823B9470) {
	__imp__sub_823B9470(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B9544) {
	__imp__sub_823B9544(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9548) {
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
	ctx.lr = 0x823B9550;
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
	// beq cr6,0x823b9578
	if (cr6.eq) goto loc_823B9578;
	// bl 0x8217d890
	ctx.lr = 0x823B956C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_823B9578:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b9610
	if (cr6.eq) goto loc_823B9610;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,60
	r26.s64 = 60;
	// mr r27,r23
	r27.u64 = r23.u64;
loc_823B9598:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r26,r25
	r30.u64 = PPC_LOAD_U32(r26.u32 + r25.u32);
	// add r31,r27,r11
	r31.u64 = r27.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b95f8
	if (cr6.eq) goto loc_823B95F8;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823b95f8
	if (cr6.eq) goto loc_823B95F8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B95C4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b95f8
	if (cr6.eq) goto loc_823B95F8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B95D8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b95fc
	if (cr6.eq) goto loc_823B95FC;
	// lwzx r4,r26,r25
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + r25.u32);
	// bl 0x823b8fe0
	ctx.lr = 0x823B95F4;
	sub_823B8FE0(ctx, base);
	// b 0x823b95fc
	goto loc_823B95FC;
loc_823B95F8:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_823B95FC:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x823b9598
	if (cr6.lt) goto loc_823B9598;
loc_823B9610:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_823B9548) {
	__imp__sub_823B9548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B961C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B961C) {
	__imp__sub_823B961C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9620) {
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
	ctx.lr = 0x823B9628;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x823B9638;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x823b96c8
	if (!cr6.gt) goto loc_823B96C8;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_823B9650:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823b96bc
	if (cr6.eq) goto loc_823B96BC;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b96b8
	if (cr6.eq) goto loc_823B96B8;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823b96b8
	if (cr6.eq) goto loc_823B96B8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B9684;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b96b8
	if (cr6.eq) goto loc_823B96B8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9698;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b96bc
	if (cr6.eq) goto loc_823B96BC;
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x823b9220
	ctx.lr = 0x823B96B4;
	sub_823B9220(ctx, base);
	// b 0x823b96bc
	goto loc_823B96BC;
loc_823B96B8:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_823B96BC:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823b9650
	if (!cr0.eq) goto loc_823B9650;
loc_823B96C8:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823B9620) {
	__imp__sub_823B9620(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B96D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B96D4) {
	__imp__sub_823B96D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B96D8) {
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
	ctx.lr = 0x823B96E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x823B96F0;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x823b9780
	if (!cr6.gt) goto loc_823B9780;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_823B9708:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823b9774
	if (cr6.eq) goto loc_823B9774;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823b9770
	if (cr6.eq) goto loc_823B9770;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823b9770
	if (cr6.eq) goto loc_823B9770;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823B973C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823b9770
	if (cr6.eq) goto loc_823B9770;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823B9750;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b9774
	if (cr6.eq) goto loc_823B9774;
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x823b8fe0
	ctx.lr = 0x823B976C;
	sub_823B8FE0(ctx, base);
	// b 0x823b9774
	goto loc_823B9774;
loc_823B9770:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_823B9774:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823b9708
	if (!cr0.eq) goto loc_823B9708;
loc_823B9780:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823B96D8) {
	__imp__sub_823B96D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B978C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B978C) {
	__imp__sub_823B978C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-29220
	ctx.r10.s64 = r11.s64 + -29220;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823b9470
	ctx.lr = 0x823B97C4;
	sub_823B9470(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823b9548
	ctx.lr = 0x823B97D4;
	sub_823B9548(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x821b5a60
	ctx.lr = 0x823B97DC;
	sub_821B5A60(ctx, base);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x821b5a60
	ctx.lr = 0x823B97E4;
	sub_821B5A60(ctx, base);
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

PPC_WEAK_FUNC(sub_823B9790) {
	__imp__sub_823B9790(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9800) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823b987c
	if (!cr6.eq) goto loc_823B987C;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x823b9620
	ctx.lr = 0x823B9838;
	sub_823B9620(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b9870
	if (cr6.eq) goto loc_823B9870;
	// li r11,0
	r11.s64 = 0;
loc_823B984C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stwx r7,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, ctx.r7.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// blt cr6,0x823b984c
	if (cr6.lt) goto loc_823B984C;
loc_823B9870:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823B9878;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_823B987C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B9800) {
	__imp__sub_823B9800(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B98AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B98AC) {
	__imp__sub_823B98AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B98B0) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823b992c
	if (!cr6.eq) goto loc_823B992C;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x823b96d8
	ctx.lr = 0x823B98E8;
	sub_823B96D8(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823b9920
	if (cr6.eq) goto loc_823B9920;
	// li r11,0
	r11.s64 = 0;
loc_823B98FC:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stwx r7,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, ctx.r7.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// blt cr6,0x823b98fc
	if (cr6.lt) goto loc_823B98FC;
loc_823B9920:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823B9928;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_823B992C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B98B0) {
	__imp__sub_823B98B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B995C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B995C) {
	__imp__sub_823B995C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9960) {
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
	ctx.lr = 0x823B9968;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,108
	ctx.r3.s64 = 108;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x823B997C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b9994
	if (cr6.eq) goto loc_823B9994;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823b90a0
	ctx.lr = 0x823B998C;
	sub_823B90A0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x823b9998
	goto loc_823B9998;
loc_823B9994:
	// li r31,0
	r31.s64 = 0;
loc_823B9998:
	// addi r30,r29,4
	r30.s64 = r29.s64 + 4;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823b9800
	ctx.lr = 0x823B99A8;
	sub_823B9800(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x823b99c8
	if (!cr6.eq) goto loc_823B99C8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,20(r29)
	PPC_STORE_U32(r29.u32 + 20, ctx.r10.u32);
loc_823B99C8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B9960) {
	__imp__sub_823B9960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B99D0) {
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
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x82130528
	ctx.lr = 0x823B99F0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823b9a88
	if (cr6.eq) goto loc_823B9A88;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32230
	ctx.r10.s64 = -2112225280;
	// lis r9,-32230
	ctx.r9.s64 = -2112225280;
	// addi r8,r11,-29200
	ctx.r8.s64 = r11.s64 + -29200;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r10,23744
	ctx.r7.s64 = ctx.r10.s64 + 23744;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// addi r5,r9,23744
	ctx.r5.s64 = ctx.r9.s64 + 23744;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// lis r4,-32237
	ctx.r4.s64 = -2112684032;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// addi r9,r6,0
	ctx.r9.s64 = ctx.r6.s64 + 0;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// addi r8,r4,0
	ctx.r8.s64 = ctx.r4.s64 + 0;
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r8,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// sth r11,56(r3)
	PPC_STORE_U16(ctx.r3.u32 + 56, r11.u16);
	// sth r11,58(r3)
	PPC_STORE_U16(ctx.r3.u32 + 58, r11.u16);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// sth r11,64(r3)
	PPC_STORE_U16(ctx.r3.u32 + 64, r11.u16);
	// sth r11,66(r3)
	PPC_STORE_U16(ctx.r3.u32 + 66, r11.u16);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// b 0x823b9a8c
	goto loc_823B9A8C;
loc_823B9A88:
	// li r31,0
	r31.s64 = 0;
loc_823B9A8C:
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// bl 0x823b98b0
	ctx.lr = 0x823B9A98;
	sub_823B98B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B99D0) {
	__imp__sub_823B99D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B9ABC) {
	__imp__sub_823B9ABC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9AC0) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-29168
	ctx.r9.s64 = r11.s64 + -29168;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823b9af4
	if (cr6.eq) goto loc_823B9AF4;
	// bl 0x82130588
	ctx.lr = 0x823B9AF0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823B9AF4:
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

PPC_WEAK_FUNC(sub_823B9AC0) {
	__imp__sub_823B9AC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x823b9b64
	if (cr6.gt) {
		sub_823B9B64(ctx, base);
		return;
	}
	// lis r12,-32196
	r12.s64 = -2109997056;
	// addi r12,r12,-25808
	r12.s64 = r12.s64 + -25808;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_823B9B08) {
	__imp__sub_823B9B08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9B30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r17{};
	PPCRegister r27{};
	// lwz r17,-25780(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -25780);
	// lwz r17,-25772(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -25772);
	// lwz r17,-25764(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -25764);
	// lwz r17,-25780(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -25780);
	// lwz r17,-25772(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -25772);
	// lwz r17,-25772(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -25772);
	// lwz r17,-25764(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -25764);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B9B30) {
	__imp__sub_823B9B30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9B54) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B9B54) {
	__imp__sub_823B9B54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9B5C) {
	PPC_FUNC_PROLOGUE();
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B9B5C) {
	__imp__sub_823B9B5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9B64) {
	PPC_FUNC_PROLOGUE();
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B9B64) {
	__imp__sub_823B9B64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B9B6C) {
	__imp__sub_823B9B6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9B70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// lbz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b9b94
	if (!cr6.eq) goto loc_823B9B94;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823b9ba0
	if (cr6.eq) goto loc_823B9BA0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b9bb4
	if (cr6.eq) goto loc_823B9BB4;
loc_823B9B94:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b9bb4
	if (cr6.eq) goto loc_823B9BB4;
loc_823B9BA0:
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, r11.u8);
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// blr 
	return;
loc_823B9BB4:
	// li r11,1
	r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, r11.u8);
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B9B70) {
	__imp__sub_823B9B70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9BC8) {
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
	ctx.lr = 0x823B9BD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x823b9c0c
	if (!cr6.gt) goto loc_823B9C0C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_823B9BE8:
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
	ctx.lr = 0x823B9C00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// bne 0x823b9be8
	if (!cr0.eq) goto loc_823B9BE8;
loc_823B9C0C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823B9C14;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823B9BC8) {
	__imp__sub_823B9BC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B9C1C) {
	__imp__sub_823B9C1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9C20) {
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
	// std r5,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r5.u64);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,29432
	ctx.r9.s64 = ctx.r10.s64 + 29432;
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// beq cr6,0x823b9c90
	if (cr6.eq) goto loc_823B9C90;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823B9C70:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b9c70
	if (!cr6.eq) goto loc_823B9C70;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823B9C90;
	sub_821C9650(ctx, base);
loc_823B9C90:
	// li r11,1
	r11.s64 = 1;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8244d5c0
	ctx.lr = 0x823B9CA8;
	sub_8244D5C0(ctx, base);
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

PPC_WEAK_FUNC(sub_823B9C20) {
	__imp__sub_823B9C20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9CC0) {
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
	// std r5,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r5.u64);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,29432
	ctx.r9.s64 = ctx.r10.s64 + 29432;
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// beq cr6,0x823b9d30
	if (cr6.eq) goto loc_823B9D30;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823B9D10:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b9d10
	if (!cr6.eq) goto loc_823B9D10;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823B9D30;
	sub_821C9650(ctx, base);
loc_823B9D30:
	// li r11,2
	r11.s64 = 2;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8244d5c0
	ctx.lr = 0x823B9D48;
	sub_8244D5C0(ctx, base);
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

PPC_WEAK_FUNC(sub_823B9CC0) {
	__imp__sub_823B9CC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9D60) {
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
	// std r5,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r5.u64);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,29432
	ctx.r9.s64 = ctx.r10.s64 + 29432;
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// beq cr6,0x823b9dd0
	if (cr6.eq) goto loc_823B9DD0;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823B9DB0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b9db0
	if (!cr6.eq) goto loc_823B9DB0;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823B9DD0;
	sub_821C9650(ctx, base);
loc_823B9DD0:
	// li r11,3
	r11.s64 = 3;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8244d5c0
	ctx.lr = 0x823B9DE8;
	sub_8244D5C0(ctx, base);
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

PPC_WEAK_FUNC(sub_823B9D60) {
	__imp__sub_823B9D60(ctx, base);
}

