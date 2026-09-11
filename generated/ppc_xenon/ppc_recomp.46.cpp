#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822C8680"))) PPC_WEAK_FUNC(sub_822C8680);
PPC_FUNC_IMPL(__imp__sub_822C8680) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82553a18
	ctx.lr = 0x822C869C;
	sub_82553A18(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x8268d518
	ctx.lr = 0x822C86A4;
	sub_8268D518(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ce210
	ctx.lr = 0x822C86AC;
	sub_821CE210(ctx, base);
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

__attribute__((alias("__imp__sub_822C86C0"))) PPC_WEAK_FUNC(sub_822C86C0);
PPC_FUNC_IMPL(__imp__sub_822C86C0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822c83b0
	ctx.lr = 0x822C86E4;
	sub_822C83B0(ctx, base);
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

__attribute__((alias("__imp__sub_822C8700"))) PPC_WEAK_FUNC(sub_822C8700);
PPC_FUNC_IMPL(__imp__sub_822C8700) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822c8458
	ctx.lr = 0x822C8724;
	sub_822C8458(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C8740"))) PPC_WEAK_FUNC(sub_822C8740);
PPC_FUNC_IMPL(__imp__sub_822C8740) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x822c84f8
	ctx.lr = 0x822C8768;
	sub_822C84F8(ctx, base);
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

__attribute__((alias("__imp__sub_822C8784"))) PPC_WEAK_FUNC(sub_822C8784);
PPC_FUNC_IMPL(__imp__sub_822C8784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8788"))) PPC_WEAK_FUNC(sub_822C8788);
PPC_FUNC_IMPL(__imp__sub_822C8788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// lfs f30,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f30.f64 = double(temp.f32);
	// bl 0x82553a18
	ctx.lr = 0x822C87B4;
	sub_82553A18(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x8268d518
	ctx.lr = 0x822C87BC;
	sub_8268D518(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x821ce328
	ctx.lr = 0x822C87C8;
	sub_821CE328(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C87EC"))) PPC_WEAK_FUNC(sub_822C87EC);
PPC_FUNC_IMPL(__imp__sub_822C87EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C87F0"))) PPC_WEAK_FUNC(sub_822C87F0);
PPC_FUNC_IMPL(__imp__sub_822C87F0) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,27644(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x821bb3d8
	ctx.lr = 0x822C8824;
	sub_821BB3D8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,30288(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f11,0(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C884C"))) PPC_WEAK_FUNC(sub_822C884C);
PPC_FUNC_IMPL(__imp__sub_822C884C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8850"))) PPC_WEAK_FUNC(sub_822C8850);
PPC_FUNC_IMPL(__imp__sub_822C8850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822C8858;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82387b90
	ctx.lr = 0x822C886C;
	sub_82387B90(ctx, base);
	// extsh r5,r30
	ctx.r5.s64 = r30.s16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x8238af98
	ctx.lr = 0x822C887C;
	sub_8238AF98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238b128
	ctx.lr = 0x822C8888;
	sub_8238B128(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C8890"))) PPC_WEAK_FUNC(sub_822C8890);
PPC_FUNC_IMPL(__imp__sub_822C8890) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82388580
	ctx.lr = 0x822C88B0;
	sub_82388580(ctx, base);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
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

__attribute__((alias("__imp__sub_822C88C8"))) PPC_WEAK_FUNC(sub_822C88C8);
PPC_FUNC_IMPL(__imp__sub_822C88C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82728100
	sub_82728100(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C88D4"))) PPC_WEAK_FUNC(sub_822C88D4);
PPC_FUNC_IMPL(__imp__sub_822C88D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C88D8"))) PPC_WEAK_FUNC(sub_822C88D8);
PPC_FUNC_IMPL(__imp__sub_822C88D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82728090
	sub_82728090(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C88E4"))) PPC_WEAK_FUNC(sub_822C88E4);
PPC_FUNC_IMPL(__imp__sub_822C88E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C88E8"))) PPC_WEAK_FUNC(sub_822C88E8);
PPC_FUNC_IMPL(__imp__sub_822C88E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x827280c8
	sub_827280C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C88F4"))) PPC_WEAK_FUNC(sub_822C88F4);
PPC_FUNC_IMPL(__imp__sub_822C88F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C88F8"))) PPC_WEAK_FUNC(sub_822C88F8);
PPC_FUNC_IMPL(__imp__sub_822C88F8) {
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
	// bl 0x82728178
	ctx.lr = 0x822C8910;
	sub_82728178(ctx, base);
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

__attribute__((alias("__imp__sub_822C8930"))) PPC_WEAK_FUNC(sub_822C8930);
PPC_FUNC_IMPL(__imp__sub_822C8930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822cad80
	sub_822CAD80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C893C"))) PPC_WEAK_FUNC(sub_822C893C);
PPC_FUNC_IMPL(__imp__sub_822C893C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8940"))) PPC_WEAK_FUNC(sub_822C8940);
PPC_FUNC_IMPL(__imp__sub_822C8940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,3656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3656);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,3656(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 3656, temp.u32);
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C8960"))) PPC_WEAK_FUNC(sub_822C8960);
PPC_FUNC_IMPL(__imp__sub_822C8960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,3528
	ctx.r9.s64 = r11.s64 + 3528;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,24(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 24, temp.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C8984"))) PPC_WEAK_FUNC(sub_822C8984);
PPC_FUNC_IMPL(__imp__sub_822C8984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8988"))) PPC_WEAK_FUNC(sub_822C8988);
PPC_FUNC_IMPL(__imp__sub_822C8988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r10,3528
	ctx.r9.s64 = ctx.r10.s64 + 3528;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// stb r11,28(r9)
	PPC_STORE_U8(ctx.r9.u32 + 28, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C89B8"))) PPC_WEAK_FUNC(sub_822C89B8);
PPC_FUNC_IMPL(__imp__sub_822C89B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x822d67e0
	sub_822D67E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C89D4"))) PPC_WEAK_FUNC(sub_822C89D4);
PPC_FUNC_IMPL(__imp__sub_822C89D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C89D8"))) PPC_WEAK_FUNC(sub_822C89D8);
PPC_FUNC_IMPL(__imp__sub_822C89D8) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,3528(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822d52a0
	ctx.lr = 0x822C8A00;
	sub_822D52A0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_822C8A20"))) PPC_WEAK_FUNC(sub_822C8A20);
PPC_FUNC_IMPL(__imp__sub_822C8A20) {
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
	// bl 0x822bf228
	ctx.lr = 0x822C8A38;
	sub_822BF228(ctx, base);
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

__attribute__((alias("__imp__sub_822C8A58"))) PPC_WEAK_FUNC(sub_822C8A58);
PPC_FUNC_IMPL(__imp__sub_822C8A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x822bfb70
	sub_822BFB70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8A74"))) PPC_WEAK_FUNC(sub_822C8A74);
PPC_FUNC_IMPL(__imp__sub_822C8A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8A78"))) PPC_WEAK_FUNC(sub_822C8A78);
PPC_FUNC_IMPL(__imp__sub_822C8A78) {
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
	// bl 0x822bfb50
	ctx.lr = 0x822C8A90;
	sub_822BFB50(ctx, base);
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

__attribute__((alias("__imp__sub_822C8AB0"))) PPC_WEAK_FUNC(sub_822C8AB0);
PPC_FUNC_IMPL(__imp__sub_822C8AB0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822c7fc8
	ctx.lr = 0x822C8AD4;
	sub_822C7FC8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822C8AF4"))) PPC_WEAK_FUNC(sub_822C8AF4);
PPC_FUNC_IMPL(__imp__sub_822C8AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8AF8"))) PPC_WEAK_FUNC(sub_822C8AF8);
PPC_FUNC_IMPL(__imp__sub_822C8AF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r11,r9,21384
	r11.s64 = ctx.r9.s64 + 21384;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r10,r6,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// slw r4,r8,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r5.u8 & 0x3F));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// xor r10,r11,r3
	ctx.r10.u64 = r11.u64 ^ ctx.r3.u64;
	// and r9,r4,r10
	ctx.r9.u64 = ctx.r4.u64 & ctx.r10.u64;
	// and r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 & ctx.r3.u64;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C8B4C"))) PPC_WEAK_FUNC(sub_822C8B4C);
PPC_FUNC_IMPL(__imp__sub_822C8B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8B50"))) PPC_WEAK_FUNC(sub_822C8B50);
PPC_FUNC_IMPL(__imp__sub_822C8B50) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822c8058
	ctx.lr = 0x822C8B70;
	sub_822C8058(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C8B8C"))) PPC_WEAK_FUNC(sub_822C8B8C);
PPC_FUNC_IMPL(__imp__sub_822C8B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8B90"))) PPC_WEAK_FUNC(sub_822C8B90);
PPC_FUNC_IMPL(__imp__sub_822C8B90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// b 0x8269c298
	sub_8269C298(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8BB0"))) PPC_WEAK_FUNC(sub_822C8BB0);
PPC_FUNC_IMPL(__imp__sub_822C8BB0) {
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
	// bl 0x8269c3d8
	ctx.lr = 0x822C8BC8;
	sub_8269C3D8(ctx, base);
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

__attribute__((alias("__imp__sub_822C8BE8"))) PPC_WEAK_FUNC(sub_822C8BE8);
PPC_FUNC_IMPL(__imp__sub_822C8BE8) {
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
	// bl 0x82388050
	ctx.lr = 0x822C8C00;
	sub_82388050(ctx, base);
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

__attribute__((alias("__imp__sub_822C8C20"))) PPC_WEAK_FUNC(sub_822C8C20);
PPC_FUNC_IMPL(__imp__sub_822C8C20) {
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
	// bl 0x82387d28
	ctx.lr = 0x822C8C38;
	sub_82387D28(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8C54"))) PPC_WEAK_FUNC(sub_822C8C54);
PPC_FUNC_IMPL(__imp__sub_822C8C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8C58"))) PPC_WEAK_FUNC(sub_822C8C58);
PPC_FUNC_IMPL(__imp__sub_822C8C58) {
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
	// bl 0x82387d70
	ctx.lr = 0x822C8C70;
	sub_82387D70(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8C8C"))) PPC_WEAK_FUNC(sub_822C8C8C);
PPC_FUNC_IMPL(__imp__sub_822C8C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8C90"))) PPC_WEAK_FUNC(sub_822C8C90);
PPC_FUNC_IMPL(__imp__sub_822C8C90) {
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
	// bl 0x82387db8
	ctx.lr = 0x822C8CA8;
	sub_82387DB8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8CC4"))) PPC_WEAK_FUNC(sub_822C8CC4);
PPC_FUNC_IMPL(__imp__sub_822C8CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8CC8"))) PPC_WEAK_FUNC(sub_822C8CC8);
PPC_FUNC_IMPL(__imp__sub_822C8CC8) {
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
	// bl 0x82387dd0
	ctx.lr = 0x822C8CE0;
	sub_82387DD0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8CFC"))) PPC_WEAK_FUNC(sub_822C8CFC);
PPC_FUNC_IMPL(__imp__sub_822C8CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8D00"))) PPC_WEAK_FUNC(sub_822C8D00);
PPC_FUNC_IMPL(__imp__sub_822C8D00) {
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
	// bl 0x823885b8
	ctx.lr = 0x822C8D18;
	sub_823885B8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8D34"))) PPC_WEAK_FUNC(sub_822C8D34);
PPC_FUNC_IMPL(__imp__sub_822C8D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8D38"))) PPC_WEAK_FUNC(sub_822C8D38);
PPC_FUNC_IMPL(__imp__sub_822C8D38) {
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
	// bl 0x82387e80
	ctx.lr = 0x822C8D50;
	sub_82387E80(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C8D6C"))) PPC_WEAK_FUNC(sub_822C8D6C);
PPC_FUNC_IMPL(__imp__sub_822C8D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8D70"))) PPC_WEAK_FUNC(sub_822C8D70);
PPC_FUNC_IMPL(__imp__sub_822C8D70) {
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
	// bl 0x823885f0
	ctx.lr = 0x822C8D88;
	sub_823885F0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8DA4"))) PPC_WEAK_FUNC(sub_822C8DA4);
PPC_FUNC_IMPL(__imp__sub_822C8DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8DA8"))) PPC_WEAK_FUNC(sub_822C8DA8);
PPC_FUNC_IMPL(__imp__sub_822C8DA8) {
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
	// bl 0x82387ec0
	ctx.lr = 0x822C8DC0;
	sub_82387EC0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8DDC"))) PPC_WEAK_FUNC(sub_822C8DDC);
PPC_FUNC_IMPL(__imp__sub_822C8DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8DE0"))) PPC_WEAK_FUNC(sub_822C8DE0);
PPC_FUNC_IMPL(__imp__sub_822C8DE0) {
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
	// bl 0x82388070
	ctx.lr = 0x822C8DF8;
	sub_82388070(ctx, base);
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

__attribute__((alias("__imp__sub_822C8E18"))) PPC_WEAK_FUNC(sub_822C8E18);
PPC_FUNC_IMPL(__imp__sub_822C8E18) {
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
	// bl 0x823880a0
	ctx.lr = 0x822C8E30;
	sub_823880A0(ctx, base);
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

__attribute__((alias("__imp__sub_822C8E50"))) PPC_WEAK_FUNC(sub_822C8E50);
PPC_FUNC_IMPL(__imp__sub_822C8E50) {
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
	// bl 0x82387e38
	ctx.lr = 0x822C8E68;
	sub_82387E38(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8E84"))) PPC_WEAK_FUNC(sub_822C8E84);
PPC_FUNC_IMPL(__imp__sub_822C8E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8E88"))) PPC_WEAK_FUNC(sub_822C8E88);
PPC_FUNC_IMPL(__imp__sub_822C8E88) {
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
	// bl 0x823880c0
	ctx.lr = 0x822C8EA0;
	sub_823880C0(ctx, base);
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

__attribute__((alias("__imp__sub_822C8EC0"))) PPC_WEAK_FUNC(sub_822C8EC0);
PPC_FUNC_IMPL(__imp__sub_822C8EC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r11,8109
	ctx.r9.s64 = r11.s64 + 8109;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C8ED8"))) PPC_WEAK_FUNC(sub_822C8ED8);
PPC_FUNC_IMPL(__imp__sub_822C8ED8) {
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
	// bl 0x82727e38
	ctx.lr = 0x822C8EF8;
	sub_82727E38(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822C8F18"))) PPC_WEAK_FUNC(sub_822C8F18);
PPC_FUNC_IMPL(__imp__sub_822C8F18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82728138
	sub_82728138(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8F28"))) PPC_WEAK_FUNC(sub_822C8F28);
PPC_FUNC_IMPL(__imp__sub_822C8F28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x827281a0
	sub_827281A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8F34"))) PPC_WEAK_FUNC(sub_822C8F34);
PPC_FUNC_IMPL(__imp__sub_822C8F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8F38"))) PPC_WEAK_FUNC(sub_822C8F38);
PPC_FUNC_IMPL(__imp__sub_822C8F38) {
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
	// bl 0x827281d8
	ctx.lr = 0x822C8F50;
	sub_827281D8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8F6C"))) PPC_WEAK_FUNC(sub_822C8F6C);
PPC_FUNC_IMPL(__imp__sub_822C8F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8F70"))) PPC_WEAK_FUNC(sub_822C8F70);
PPC_FUNC_IMPL(__imp__sub_822C8F70) {
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
	// bl 0x82728228
	ctx.lr = 0x822C8F90;
	sub_82728228(ctx, base);
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

__attribute__((alias("__imp__sub_822C8FAC"))) PPC_WEAK_FUNC(sub_822C8FAC);
PPC_FUNC_IMPL(__imp__sub_822C8FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8FB0"))) PPC_WEAK_FUNC(sub_822C8FB0);
PPC_FUNC_IMPL(__imp__sub_822C8FB0) {
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
	// bl 0x822c75f8
	ctx.lr = 0x822C8FC8;
	sub_822C75F8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8FE4"))) PPC_WEAK_FUNC(sub_822C8FE4);
PPC_FUNC_IMPL(__imp__sub_822C8FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8FE8"))) PPC_WEAK_FUNC(sub_822C8FE8);
PPC_FUNC_IMPL(__imp__sub_822C8FE8) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82388c48
	ctx.lr = 0x822C900C;
	sub_82388C48(ctx, base);
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

__attribute__((alias("__imp__sub_822C9028"))) PPC_WEAK_FUNC(sub_822C9028);
PPC_FUNC_IMPL(__imp__sub_822C9028) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389de8
	ctx.lr = 0x822C9050;
	sub_82389DE8(ctx, base);
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

__attribute__((alias("__imp__sub_822C906C"))) PPC_WEAK_FUNC(sub_822C906C);
PPC_FUNC_IMPL(__imp__sub_822C906C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9070"))) PPC_WEAK_FUNC(sub_822C9070);
PPC_FUNC_IMPL(__imp__sub_822C9070) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82388c60
	ctx.lr = 0x822C9094;
	sub_82388C60(ctx, base);
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

__attribute__((alias("__imp__sub_822C90B0"))) PPC_WEAK_FUNC(sub_822C90B0);
PPC_FUNC_IMPL(__imp__sub_822C90B0) {
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
	// bl 0x825c1da0
	ctx.lr = 0x822C90D0;
	sub_825C1DA0(ctx, base);
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

__attribute__((alias("__imp__sub_822C90EC"))) PPC_WEAK_FUNC(sub_822C90EC);
PPC_FUNC_IMPL(__imp__sub_822C90EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C90F0"))) PPC_WEAK_FUNC(sub_822C90F0);
PPC_FUNC_IMPL(__imp__sub_822C90F0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823889c0
	ctx.lr = 0x822C9110;
	sub_823889C0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C912C"))) PPC_WEAK_FUNC(sub_822C912C);
PPC_FUNC_IMPL(__imp__sub_822C912C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9130"))) PPC_WEAK_FUNC(sub_822C9130);
PPC_FUNC_IMPL(__imp__sub_822C9130) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823889c8
	ctx.lr = 0x822C9150;
	sub_823889C8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C916C"))) PPC_WEAK_FUNC(sub_822C916C);
PPC_FUNC_IMPL(__imp__sub_822C916C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9170"))) PPC_WEAK_FUNC(sub_822C9170);
PPC_FUNC_IMPL(__imp__sub_822C9170) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823889d0
	ctx.lr = 0x822C9194;
	sub_823889D0(ctx, base);
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

__attribute__((alias("__imp__sub_822C91B0"))) PPC_WEAK_FUNC(sub_822C91B0);
PPC_FUNC_IMPL(__imp__sub_822C91B0) {
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
	// bl 0x8263b728
	ctx.lr = 0x822C91D0;
	sub_8263B728(ctx, base);
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

__attribute__((alias("__imp__sub_822C91EC"))) PPC_WEAK_FUNC(sub_822C91EC);
PPC_FUNC_IMPL(__imp__sub_822C91EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C91F0"))) PPC_WEAK_FUNC(sub_822C91F0);
PPC_FUNC_IMPL(__imp__sub_822C91F0) {
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
	// bl 0x823889e0
	ctx.lr = 0x822C9210;
	sub_823889E0(ctx, base);
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

__attribute__((alias("__imp__sub_822C922C"))) PPC_WEAK_FUNC(sub_822C922C);
PPC_FUNC_IMPL(__imp__sub_822C922C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9230"))) PPC_WEAK_FUNC(sub_822C9230);
PPC_FUNC_IMPL(__imp__sub_822C9230) {
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
	// bl 0x82618670
	ctx.lr = 0x822C9250;
	sub_82618670(ctx, base);
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

__attribute__((alias("__imp__sub_822C926C"))) PPC_WEAK_FUNC(sub_822C926C);
PPC_FUNC_IMPL(__imp__sub_822C926C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9270"))) PPC_WEAK_FUNC(sub_822C9270);
PPC_FUNC_IMPL(__imp__sub_822C9270) {
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
	// bl 0x823eaef8
	ctx.lr = 0x822C9290;
	sub_823EAEF8(ctx, base);
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

__attribute__((alias("__imp__sub_822C92AC"))) PPC_WEAK_FUNC(sub_822C92AC);
PPC_FUNC_IMPL(__imp__sub_822C92AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C92B0"))) PPC_WEAK_FUNC(sub_822C92B0);
PPC_FUNC_IMPL(__imp__sub_822C92B0) {
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
	// bl 0x823889f0
	ctx.lr = 0x822C92D0;
	sub_823889F0(ctx, base);
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

__attribute__((alias("__imp__sub_822C92EC"))) PPC_WEAK_FUNC(sub_822C92EC);
PPC_FUNC_IMPL(__imp__sub_822C92EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C92F0"))) PPC_WEAK_FUNC(sub_822C92F0);
PPC_FUNC_IMPL(__imp__sub_822C92F0) {
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
	// bl 0x82656bf8
	ctx.lr = 0x822C9310;
	sub_82656BF8(ctx, base);
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

__attribute__((alias("__imp__sub_822C932C"))) PPC_WEAK_FUNC(sub_822C932C);
PPC_FUNC_IMPL(__imp__sub_822C932C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9330"))) PPC_WEAK_FUNC(sub_822C9330);
PPC_FUNC_IMPL(__imp__sub_822C9330) {
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
	// bl 0x82388a08
	ctx.lr = 0x822C9350;
	sub_82388A08(ctx, base);
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

__attribute__((alias("__imp__sub_822C936C"))) PPC_WEAK_FUNC(sub_822C936C);
PPC_FUNC_IMPL(__imp__sub_822C936C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9370"))) PPC_WEAK_FUNC(sub_822C9370);
PPC_FUNC_IMPL(__imp__sub_822C9370) {
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
	// bl 0x82388a10
	ctx.lr = 0x822C9390;
	sub_82388A10(ctx, base);
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

__attribute__((alias("__imp__sub_822C93AC"))) PPC_WEAK_FUNC(sub_822C93AC);
PPC_FUNC_IMPL(__imp__sub_822C93AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C93B0"))) PPC_WEAK_FUNC(sub_822C93B0);
PPC_FUNC_IMPL(__imp__sub_822C93B0) {
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
	// bl 0x82388a28
	ctx.lr = 0x822C93D0;
	sub_82388A28(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822C93F0"))) PPC_WEAK_FUNC(sub_822C93F0);
PPC_FUNC_IMPL(__imp__sub_822C93F0) {
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
	// bl 0x82388a40
	ctx.lr = 0x822C9410;
	sub_82388A40(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822C9430"))) PPC_WEAK_FUNC(sub_822C9430);
PPC_FUNC_IMPL(__imp__sub_822C9430) {
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
	// bl 0x82496208
	ctx.lr = 0x822C9448;
	sub_82496208(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C9464"))) PPC_WEAK_FUNC(sub_822C9464);
PPC_FUNC_IMPL(__imp__sub_822C9464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9468"))) PPC_WEAK_FUNC(sub_822C9468);
PPC_FUNC_IMPL(__imp__sub_822C9468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8273fbf8
	sub_8273FBF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9474"))) PPC_WEAK_FUNC(sub_822C9474);
PPC_FUNC_IMPL(__imp__sub_822C9474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9478"))) PPC_WEAK_FUNC(sub_822C9478);
PPC_FUNC_IMPL(__imp__sub_822C9478) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x8273fbd8
	ctx.lr = 0x822C94A4;
	sub_8273FBD8(ctx, base);
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

__attribute__((alias("__imp__sub_822C94C0"))) PPC_WEAK_FUNC(sub_822C94C0);
PPC_FUNC_IMPL(__imp__sub_822C94C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8273eff8
	sub_8273EFF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C94CC"))) PPC_WEAK_FUNC(sub_822C94CC);
PPC_FUNC_IMPL(__imp__sub_822C94CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C94D0"))) PPC_WEAK_FUNC(sub_822C94D0);
PPC_FUNC_IMPL(__imp__sub_822C94D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8273fbe0
	sub_8273FBE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C94E0"))) PPC_WEAK_FUNC(sub_822C94E0);
PPC_FUNC_IMPL(__imp__sub_822C94E0) {
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
	// bl 0x8273eff0
	ctx.lr = 0x822C9500;
	sub_8273EFF0(ctx, base);
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

__attribute__((alias("__imp__sub_822C951C"))) PPC_WEAK_FUNC(sub_822C951C);
PPC_FUNC_IMPL(__imp__sub_822C951C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9520"))) PPC_WEAK_FUNC(sub_822C9520);
PPC_FUNC_IMPL(__imp__sub_822C9520) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8273fbe8
	ctx.lr = 0x822C954C;
	sub_8273FBE8(ctx, base);
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

__attribute__((alias("__imp__sub_822C9568"))) PPC_WEAK_FUNC(sub_822C9568);
PPC_FUNC_IMPL(__imp__sub_822C9568) {
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
	// b 0x8273fbf0
	sub_8273FBF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C957C"))) PPC_WEAK_FUNC(sub_822C957C);
PPC_FUNC_IMPL(__imp__sub_822C957C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9580"))) PPC_WEAK_FUNC(sub_822C9580);
PPC_FUNC_IMPL(__imp__sub_822C9580) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8273ef48
	ctx.lr = 0x822C95A4;
	sub_8273EF48(ctx, base);
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

__attribute__((alias("__imp__sub_822C95C0"))) PPC_WEAK_FUNC(sub_822C95C0);
PPC_FUNC_IMPL(__imp__sub_822C95C0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8273ef60
	ctx.lr = 0x822C95E4;
	sub_8273EF60(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822C9604"))) PPC_WEAK_FUNC(sub_822C9604);
PPC_FUNC_IMPL(__imp__sub_822C9604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9608"))) PPC_WEAK_FUNC(sub_822C9608);
PPC_FUNC_IMPL(__imp__sub_822C9608) {
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
	// b 0x8273ef70
	sub_8273EF70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C962C"))) PPC_WEAK_FUNC(sub_822C962C);
PPC_FUNC_IMPL(__imp__sub_822C962C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9630"))) PPC_WEAK_FUNC(sub_822C9630);
PPC_FUNC_IMPL(__imp__sub_822C9630) {
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
	// bl 0x8273ef80
	ctx.lr = 0x822C9650;
	sub_8273EF80(ctx, base);
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

__attribute__((alias("__imp__sub_822C966C"))) PPC_WEAK_FUNC(sub_822C966C);
PPC_FUNC_IMPL(__imp__sub_822C966C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9670"))) PPC_WEAK_FUNC(sub_822C9670);
PPC_FUNC_IMPL(__imp__sub_822C9670) {
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
	// bl 0x824e6270
	ctx.lr = 0x822C9690;
	sub_824E6270(ctx, base);
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

__attribute__((alias("__imp__sub_822C96AC"))) PPC_WEAK_FUNC(sub_822C96AC);
PPC_FUNC_IMPL(__imp__sub_822C96AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C96B0"))) PPC_WEAK_FUNC(sub_822C96B0);
PPC_FUNC_IMPL(__imp__sub_822C96B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8247a8d0
	sub_8247A8D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C96C4"))) PPC_WEAK_FUNC(sub_822C96C4);
PPC_FUNC_IMPL(__imp__sub_822C96C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C96C8"))) PPC_WEAK_FUNC(sub_822C96C8);
PPC_FUNC_IMPL(__imp__sub_822C96C8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stwx r5,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, ctx.r5.u32);
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f11,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r8,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r8.u32);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C9794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C97B0"))) PPC_WEAK_FUNC(sub_822C97B0);
PPC_FUNC_IMPL(__imp__sub_822C97B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stwx r6,r5,r11
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
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
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
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
	// lfs f1,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9828"))) PPC_WEAK_FUNC(sub_822C9828);
PPC_FUNC_IMPL(__imp__sub_822C9828) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stwx r8,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r8.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
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
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// lwz r5,20(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cntlzw r8,r5
	ctx.r8.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lfs f1,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C98B8"))) PPC_WEAK_FUNC(sub_822C98B8);
PPC_FUNC_IMPL(__imp__sub_822C98B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
	// lwz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// cntlzw r3,r7
	ctx.r3.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r3,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// rlwinm r8,r5,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// xori r6,r8,1
	ctx.r6.u64 = ctx.r8.u64 ^ 1;
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9948"))) PPC_WEAK_FUNC(sub_822C9948);
PPC_FUNC_IMPL(__imp__sub_822C9948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stwx r3,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r3.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r6,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r6.u32);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,2
	r11.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// lwz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cntlzw r9,r6
	ctx.r9.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// cntlzw r10,r5
	ctx.r10.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r6,r5,24
	ctx.r6.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9A2C"))) PPC_WEAK_FUNC(sub_822C9A2C);
PPC_FUNC_IMPL(__imp__sub_822C9A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9A30"))) PPC_WEAK_FUNC(sub_822C9A30);
PPC_FUNC_IMPL(__imp__sub_822C9A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stwx r3,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r3.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r6,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r6.u32);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,2
	r11.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r5,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// lfs f1,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f3,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// lfs f2,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9B0C"))) PPC_WEAK_FUNC(sub_822C9B0C);
PPC_FUNC_IMPL(__imp__sub_822C9B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9B10"))) PPC_WEAK_FUNC(sub_822C9B10);
PPC_FUNC_IMPL(__imp__sub_822C9B10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r5,r11
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
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
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
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
	// lwz r6,12(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9B88"))) PPC_WEAK_FUNC(sub_822C9B88);
PPC_FUNC_IMPL(__imp__sub_822C9B88) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C9C04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C9C20"))) PPC_WEAK_FUNC(sub_822C9C20);
PPC_FUNC_IMPL(__imp__sub_822C9C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32212
	r11.s64 = -2111045632;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,32336
	ctx.r3.s64 = r11.s64 + 32336;
	// b 0x822c96c8
	sub_822C96C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9C30"))) PPC_WEAK_FUNC(sub_822C9C30);
PPC_FUNC_IMPL(__imp__sub_822C9C30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c9c74
	if (!cr6.eq) goto loc_822C9C74;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c9c5c
	if (cr6.eq) goto loc_822C9C5C;
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822c9c60
	if (!cr6.eq) goto loc_822C9C60;
loc_822C9C5C:
	// li r11,1
	r11.s64 = 1;
loc_822C9C60:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822C9C74:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822c9c98
	if (cr6.eq) goto loc_822C9C98;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822c9c74
	if (cr6.eq) goto loc_822C9C74;
loc_822C9C98:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C9CB0"))) PPC_WEAK_FUNC(sub_822C9CB0);
PPC_FUNC_IMPL(__imp__sub_822C9CB0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822c9cfc
	if (!cr6.eq) goto loc_822C9CFC;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822c9cf0
	if (cr6.eq) goto loc_822C9CF0;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822c9cf4
	if (!cr6.eq) goto loc_822C9CF4;
loc_822C9CF0:
	// li r11,1
	r11.s64 = 1;
loc_822C9CF4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x822c9d08
	goto loc_822C9D08;
loc_822C9CFC:
	// bl 0x823db730
	ctx.lr = 0x822C9D00;
	sub_823DB730(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_822C9D08:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822C9D28"))) PPC_WEAK_FUNC(sub_822C9D28);
PPC_FUNC_IMPL(__imp__sub_822C9D28) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822c7eb8
	ctx.lr = 0x822C9D4C;
	sub_822C7EB8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822C9D6C"))) PPC_WEAK_FUNC(sub_822C9D6C);
PPC_FUNC_IMPL(__imp__sub_822C9D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9D70"))) PPC_WEAK_FUNC(sub_822C9D70);
PPC_FUNC_IMPL(__imp__sub_822C9D70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_822C9D84:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c9d84
	if (!cr6.eq) goto loc_822C9D84;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_822C9D98:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x822c9d98
	if (!cr6.eq) goto loc_822C9D98;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C9DB4"))) PPC_WEAK_FUNC(sub_822C9DB4);
PPC_FUNC_IMPL(__imp__sub_822C9DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9DB8"))) PPC_WEAK_FUNC(sub_822C9DB8);
PPC_FUNC_IMPL(__imp__sub_822C9DB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-18344
	ctx.r3.s64 = r11.s64 + -18344;
	// b 0x822c97b0
	sub_822C97B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9DC8"))) PPC_WEAK_FUNC(sub_822C9DC8);
PPC_FUNC_IMPL(__imp__sub_822C9DC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-18240
	ctx.r3.s64 = r11.s64 + -18240;
	// b 0x822c9828
	sub_822C9828(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9DD8"))) PPC_WEAK_FUNC(sub_822C9DD8);
PPC_FUNC_IMPL(__imp__sub_822C9DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822c7568
	sub_822C7568(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9DE4"))) PPC_WEAK_FUNC(sub_822C9DE4);
PPC_FUNC_IMPL(__imp__sub_822C9DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9DE8"))) PPC_WEAK_FUNC(sub_822C9DE8);
PPC_FUNC_IMPL(__imp__sub_822C9DE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822d39d0
	sub_822D39D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9DF4"))) PPC_WEAK_FUNC(sub_822C9DF4);
PPC_FUNC_IMPL(__imp__sub_822C9DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9DF8"))) PPC_WEAK_FUNC(sub_822C9DF8);
PPC_FUNC_IMPL(__imp__sub_822C9DF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-32488
	ctx.r3.s64 = r11.s64 + -32488;
	// b 0x822c98b8
	sub_822C98B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9E08"))) PPC_WEAK_FUNC(sub_822C9E08);
PPC_FUNC_IMPL(__imp__sub_822C9E08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-32272
	ctx.r3.s64 = r11.s64 + -32272;
	// b 0x822c9948
	sub_822C9948(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9E18"))) PPC_WEAK_FUNC(sub_822C9E18);
PPC_FUNC_IMPL(__imp__sub_822C9E18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32212
	r11.s64 = -2111045632;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-1112
	ctx.r3.s64 = r11.s64 + -1112;
	// b 0x822c9a30
	sub_822C9A30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9E28"))) PPC_WEAK_FUNC(sub_822C9E28);
PPC_FUNC_IMPL(__imp__sub_822C9E28) {
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
	// bl 0x8238ec00
	ctx.lr = 0x822C9E48;
	sub_8238EC00(ctx, base);
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

__attribute__((alias("__imp__sub_822C9E64"))) PPC_WEAK_FUNC(sub_822C9E64);
PPC_FUNC_IMPL(__imp__sub_822C9E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9E68"))) PPC_WEAK_FUNC(sub_822C9E68);
PPC_FUNC_IMPL(__imp__sub_822C9E68) {
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
	// bl 0x82396408
	ctx.lr = 0x822C9E88;
	sub_82396408(ctx, base);
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

__attribute__((alias("__imp__sub_822C9EA4"))) PPC_WEAK_FUNC(sub_822C9EA4);
PPC_FUNC_IMPL(__imp__sub_822C9EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9EA8"))) PPC_WEAK_FUNC(sub_822C9EA8);
PPC_FUNC_IMPL(__imp__sub_822C9EA8) {
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
	// bl 0x82397018
	ctx.lr = 0x822C9EC8;
	sub_82397018(ctx, base);
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

__attribute__((alias("__imp__sub_822C9EE4"))) PPC_WEAK_FUNC(sub_822C9EE4);
PPC_FUNC_IMPL(__imp__sub_822C9EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9EE8"))) PPC_WEAK_FUNC(sub_822C9EE8);
PPC_FUNC_IMPL(__imp__sub_822C9EE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r7,r6,r11
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, ctx.r7.u32);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
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
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82388908
	sub_82388908(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9F54"))) PPC_WEAK_FUNC(sub_822C9F54);
PPC_FUNC_IMPL(__imp__sub_822C9F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9F58"))) PPC_WEAK_FUNC(sub_822C9F58);
PPC_FUNC_IMPL(__imp__sub_822C9F58) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389800
	ctx.lr = 0x822C9F7C;
	sub_82389800(ctx, base);
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

__attribute__((alias("__imp__sub_822C9F98"))) PPC_WEAK_FUNC(sub_822C9F98);
PPC_FUNC_IMPL(__imp__sub_822C9F98) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389880
	ctx.lr = 0x822C9FBC;
	sub_82389880(ctx, base);
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

__attribute__((alias("__imp__sub_822C9FD8"))) PPC_WEAK_FUNC(sub_822C9FD8);
PPC_FUNC_IMPL(__imp__sub_822C9FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32199
	r11.s64 = -2110193664;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-29560
	ctx.r3.s64 = r11.s64 + -29560;
	// b 0x822c9b10
	sub_822C9B10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9FE8"))) PPC_WEAK_FUNC(sub_822C9FE8);
PPC_FUNC_IMPL(__imp__sub_822C9FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
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
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// b 0x823889b0
	sub_823889B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CA04C"))) PPC_WEAK_FUNC(sub_822CA04C);
PPC_FUNC_IMPL(__imp__sub_822CA04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA050"))) PPC_WEAK_FUNC(sub_822CA050);
PPC_FUNC_IMPL(__imp__sub_822CA050) {
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
	// b 0x8273f218
	sub_8273F218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CA064"))) PPC_WEAK_FUNC(sub_822CA064);
PPC_FUNC_IMPL(__imp__sub_822CA064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA068"))) PPC_WEAK_FUNC(sub_822CA068);
PPC_FUNC_IMPL(__imp__sub_822CA068) {
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
	// bl 0x82387bc0
	ctx.lr = 0x822CA088;
	sub_82387BC0(ctx, base);
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

__attribute__((alias("__imp__sub_822CA0A4"))) PPC_WEAK_FUNC(sub_822CA0A4);
PPC_FUNC_IMPL(__imp__sub_822CA0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA0A8"))) PPC_WEAK_FUNC(sub_822CA0A8);
PPC_FUNC_IMPL(__imp__sub_822CA0A8) {
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
	// bl 0x82387c08
	ctx.lr = 0x822CA0C8;
	sub_82387C08(ctx, base);
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

__attribute__((alias("__imp__sub_822CA0E4"))) PPC_WEAK_FUNC(sub_822CA0E4);
PPC_FUNC_IMPL(__imp__sub_822CA0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA0E8"))) PPC_WEAK_FUNC(sub_822CA0E8);
PPC_FUNC_IMPL(__imp__sub_822CA0E8) {
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
	// bl 0x82387c50
	ctx.lr = 0x822CA108;
	sub_82387C50(ctx, base);
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

__attribute__((alias("__imp__sub_822CA124"))) PPC_WEAK_FUNC(sub_822CA124);
PPC_FUNC_IMPL(__imp__sub_822CA124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA128"))) PPC_WEAK_FUNC(sub_822CA128);
PPC_FUNC_IMPL(__imp__sub_822CA128) {
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
	// bl 0x82387c98
	ctx.lr = 0x822CA148;
	sub_82387C98(ctx, base);
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

__attribute__((alias("__imp__sub_822CA164"))) PPC_WEAK_FUNC(sub_822CA164);
PPC_FUNC_IMPL(__imp__sub_822CA164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA168"))) PPC_WEAK_FUNC(sub_822CA168);
PPC_FUNC_IMPL(__imp__sub_822CA168) {
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
	// bl 0x82387ce0
	ctx.lr = 0x822CA188;
	sub_82387CE0(ctx, base);
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

__attribute__((alias("__imp__sub_822CA1A4"))) PPC_WEAK_FUNC(sub_822CA1A4);
PPC_FUNC_IMPL(__imp__sub_822CA1A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA1A8"))) PPC_WEAK_FUNC(sub_822CA1A8);
PPC_FUNC_IMPL(__imp__sub_822CA1A8) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82387ef8
	ctx.lr = 0x822CA1CC;
	sub_82387EF8(ctx, base);
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

__attribute__((alias("__imp__sub_822CA1E8"))) PPC_WEAK_FUNC(sub_822CA1E8);
PPC_FUNC_IMPL(__imp__sub_822CA1E8) {
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
	// bl 0x82388090
	ctx.lr = 0x822CA208;
	sub_82388090(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822CA228"))) PPC_WEAK_FUNC(sub_822CA228);
PPC_FUNC_IMPL(__imp__sub_822CA228) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-31320
	ctx.r3.s64 = r11.s64 + -31320;
	// b 0x822c9b88
	sub_822C9B88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CA238"))) PPC_WEAK_FUNC(sub_822CA238);
PPC_FUNC_IMPL(__imp__sub_822CA238) {
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
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-31208
	ctx.r4.s64 = r11.s64 + -31208;
	// addi r3,r10,-20804
	ctx.r3.s64 = ctx.r10.s64 + -20804;
	// bl 0x82554798
	ctx.lr = 0x822CA258;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-31104
	ctx.r4.s64 = ctx.r9.s64 + -31104;
	// addi r3,r8,-20820
	ctx.r3.s64 = ctx.r8.s64 + -20820;
	// bl 0x82554798
	ctx.lr = 0x822CA26C;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-31040
	ctx.r4.s64 = ctx.r7.s64 + -31040;
	// addi r3,r6,-20836
	ctx.r3.s64 = ctx.r6.s64 + -20836;
	// bl 0x82554798
	ctx.lr = 0x822CA280;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30976
	ctx.r4.s64 = ctx.r5.s64 + -30976;
	// addi r3,r3,-20856
	ctx.r3.s64 = ctx.r3.s64 + -20856;
	// bl 0x82554798
	ctx.lr = 0x822CA294;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30912
	ctx.r4.s64 = r11.s64 + -30912;
	// addi r3,r10,-20884
	ctx.r3.s64 = ctx.r10.s64 + -20884;
	// bl 0x82554798
	ctx.lr = 0x822CA2A8;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30840
	ctx.r4.s64 = ctx.r9.s64 + -30840;
	// addi r3,r8,-20904
	ctx.r3.s64 = ctx.r8.s64 + -20904;
	// bl 0x82554798
	ctx.lr = 0x822CA2BC;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30736
	ctx.r4.s64 = ctx.r7.s64 + -30736;
	// addi r3,r6,-20928
	ctx.r3.s64 = ctx.r6.s64 + -20928;
	// bl 0x82554798
	ctx.lr = 0x822CA2D0;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25568
	ctx.r4.s64 = ctx.r5.s64 + -25568;
	// addi r3,r3,-20940
	ctx.r3.s64 = ctx.r3.s64 + -20940;
	// bl 0x82554798
	ctx.lr = 0x822CA2E4;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-25552
	ctx.r4.s64 = r11.s64 + -25552;
	// addi r3,r10,-20956
	ctx.r3.s64 = ctx.r10.s64 + -20956;
	// bl 0x82554798
	ctx.lr = 0x822CA2F8;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-25424
	ctx.r4.s64 = ctx.r9.s64 + -25424;
	// addi r3,r8,-20976
	ctx.r3.s64 = ctx.r8.s64 + -20976;
	// bl 0x82554798
	ctx.lr = 0x822CA30C;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-25304
	ctx.r4.s64 = ctx.r7.s64 + -25304;
	// addi r3,r6,-20996
	ctx.r3.s64 = ctx.r6.s64 + -20996;
	// bl 0x82554798
	ctx.lr = 0x822CA320;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25232
	ctx.r4.s64 = ctx.r5.s64 + -25232;
	// addi r3,r3,-21008
	ctx.r3.s64 = ctx.r3.s64 + -21008;
	// bl 0x82554798
	ctx.lr = 0x822CA334;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30640
	ctx.r4.s64 = r11.s64 + -30640;
	// addi r3,r10,-21032
	ctx.r3.s64 = ctx.r10.s64 + -21032;
	// bl 0x82554798
	ctx.lr = 0x822CA348;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30576
	ctx.r4.s64 = ctx.r9.s64 + -30576;
	// addi r3,r8,-21052
	ctx.r3.s64 = ctx.r8.s64 + -21052;
	// bl 0x82554798
	ctx.lr = 0x822CA35C;
	sub_82554798(ctx, base);
	// bl 0x8238ce90
	ctx.lr = 0x822CA360;
	sub_8238CE90(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28992
	ctx.r4.s64 = ctx.r7.s64 + -28992;
	// addi r3,r6,-21084
	ctx.r3.s64 = ctx.r6.s64 + -21084;
	// bl 0x82554798
	ctx.lr = 0x822CA374;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28968
	ctx.r4.s64 = ctx.r5.s64 + -28968;
	// addi r3,r3,-21100
	ctx.r3.s64 = ctx.r3.s64 + -21100;
	// bl 0x82554798
	ctx.lr = 0x822CA388;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28904
	ctx.r4.s64 = r11.s64 + -28904;
	// addi r3,r10,-21124
	ctx.r3.s64 = ctx.r10.s64 + -21124;
	// bl 0x82554798
	ctx.lr = 0x822CA39C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30520
	ctx.r4.s64 = ctx.r9.s64 + -30520;
	// addi r3,r8,-21140
	ctx.r3.s64 = ctx.r8.s64 + -21140;
	// bl 0x82554798
	ctx.lr = 0x822CA3B0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30504
	ctx.r4.s64 = ctx.r7.s64 + -30504;
	// addi r3,r6,-21160
	ctx.r3.s64 = ctx.r6.s64 + -21160;
	// bl 0x82554798
	ctx.lr = 0x822CA3C4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30488
	ctx.r4.s64 = ctx.r5.s64 + -30488;
	// addi r3,r3,-21188
	ctx.r3.s64 = ctx.r3.s64 + -21188;
	// bl 0x82554798
	ctx.lr = 0x822CA3D8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30472
	ctx.r4.s64 = r11.s64 + -30472;
	// addi r3,r10,-21204
	ctx.r3.s64 = ctx.r10.s64 + -21204;
	// bl 0x82554798
	ctx.lr = 0x822CA3EC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28888
	ctx.r4.s64 = ctx.r9.s64 + -28888;
	// addi r3,r8,-21216
	ctx.r3.s64 = ctx.r8.s64 + -21216;
	// bl 0x82554798
	ctx.lr = 0x822CA400;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28872
	ctx.r4.s64 = ctx.r7.s64 + -28872;
	// addi r3,r6,-21232
	ctx.r3.s64 = ctx.r6.s64 + -21232;
	// bl 0x82554798
	ctx.lr = 0x822CA414;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28816
	ctx.r4.s64 = ctx.r5.s64 + -28816;
	// addi r3,r3,-21252
	ctx.r3.s64 = ctx.r3.s64 + -21252;
	// bl 0x82554798
	ctx.lr = 0x822CA428;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-25160
	ctx.r4.s64 = r11.s64 + -25160;
	// addi r3,r10,-21276
	ctx.r3.s64 = ctx.r10.s64 + -21276;
	// bl 0x82554798
	ctx.lr = 0x822CA43C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30416
	ctx.r4.s64 = ctx.r9.s64 + -30416;
	// addi r3,r8,-21300
	ctx.r3.s64 = ctx.r8.s64 + -21300;
	// bl 0x82554798
	ctx.lr = 0x822CA450;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-25144
	ctx.r4.s64 = ctx.r7.s64 + -25144;
	// addi r3,r6,-21332
	ctx.r3.s64 = ctx.r6.s64 + -21332;
	// bl 0x82554798
	ctx.lr = 0x822CA464;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25128
	ctx.r4.s64 = ctx.r5.s64 + -25128;
	// addi r3,r3,-21352
	ctx.r3.s64 = ctx.r3.s64 + -21352;
	// bl 0x82554798
	ctx.lr = 0x822CA478;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-32072
	ctx.r4.s64 = r11.s64 + -32072;
	// addi r3,r10,-21376
	ctx.r3.s64 = ctx.r10.s64 + -21376;
	// bl 0x82554798
	ctx.lr = 0x822CA48C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-25112
	ctx.r4.s64 = ctx.r9.s64 + -25112;
	// addi r3,r8,-21404
	ctx.r3.s64 = ctx.r8.s64 + -21404;
	// bl 0x82554798
	ctx.lr = 0x822CA4A0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-32064
	ctx.r4.s64 = ctx.r7.s64 + -32064;
	// addi r3,r6,-21436
	ctx.r3.s64 = ctx.r6.s64 + -21436;
	// bl 0x82554798
	ctx.lr = 0x822CA4B4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25096
	ctx.r4.s64 = ctx.r5.s64 + -25096;
	// addi r3,r3,-21464
	ctx.r3.s64 = ctx.r3.s64 + -21464;
	// bl 0x82554798
	ctx.lr = 0x822CA4C8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-25080
	ctx.r4.s64 = r11.s64 + -25080;
	// addi r3,r10,-21496
	ctx.r3.s64 = ctx.r10.s64 + -21496;
	// bl 0x82554798
	ctx.lr = 0x822CA4DC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30400
	ctx.r4.s64 = ctx.r9.s64 + -30400;
	// addi r3,r8,-21528
	ctx.r3.s64 = ctx.r8.s64 + -21528;
	// bl 0x82554798
	ctx.lr = 0x822CA4F0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30368
	ctx.r4.s64 = ctx.r7.s64 + -30368;
	// addi r3,r6,-21560
	ctx.r3.s64 = ctx.r6.s64 + -21560;
	// bl 0x82554798
	ctx.lr = 0x822CA504;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30328
	ctx.r4.s64 = ctx.r5.s64 + -30328;
	// addi r3,r3,-21584
	ctx.r3.s64 = ctx.r3.s64 + -21584;
	// bl 0x82554798
	ctx.lr = 0x822CA518;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30280
	ctx.r4.s64 = r11.s64 + -30280;
	// addi r3,r10,-21612
	ctx.r3.s64 = ctx.r10.s64 + -21612;
	// bl 0x82554798
	ctx.lr = 0x822CA52C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30248
	ctx.r4.s64 = ctx.r9.s64 + -30248;
	// addi r3,r8,-21632
	ctx.r3.s64 = ctx.r8.s64 + -21632;
	// bl 0x82554798
	ctx.lr = 0x822CA540;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-32056
	ctx.r4.s64 = ctx.r7.s64 + -32056;
	// addi r3,r6,-21652
	ctx.r3.s64 = ctx.r6.s64 + -21652;
	// bl 0x82554798
	ctx.lr = 0x822CA554;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25064
	ctx.r4.s64 = ctx.r5.s64 + -25064;
	// addi r3,r3,-21668
	ctx.r3.s64 = ctx.r3.s64 + -21668;
	// bl 0x82554798
	ctx.lr = 0x822CA568;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30176
	ctx.r4.s64 = r11.s64 + -30176;
	// addi r3,r10,-21684
	ctx.r3.s64 = ctx.r10.s64 + -21684;
	// bl 0x82554798
	ctx.lr = 0x822CA57C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-32048
	ctx.r4.s64 = ctx.r9.s64 + -32048;
	// addi r3,r8,-21704
	ctx.r3.s64 = ctx.r8.s64 + -21704;
	// bl 0x82554798
	ctx.lr = 0x822CA590;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30120
	ctx.r4.s64 = ctx.r7.s64 + -30120;
	// addi r3,r6,-21728
	ctx.r3.s64 = ctx.r6.s64 + -21728;
	// bl 0x82554798
	ctx.lr = 0x822CA5A4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30088
	ctx.r4.s64 = ctx.r5.s64 + -30088;
	// addi r3,r3,-21748
	ctx.r3.s64 = ctx.r3.s64 + -21748;
	// bl 0x82554798
	ctx.lr = 0x822CA5B8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-32040
	ctx.r4.s64 = r11.s64 + -32040;
	// addi r3,r10,-21772
	ctx.r3.s64 = ctx.r10.s64 + -21772;
	// bl 0x82554798
	ctx.lr = 0x822CA5CC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30032
	ctx.r4.s64 = ctx.r9.s64 + -30032;
	// addi r3,r8,-21788
	ctx.r3.s64 = ctx.r8.s64 + -21788;
	// bl 0x82554798
	ctx.lr = 0x822CA5E0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-29960
	ctx.r4.s64 = ctx.r7.s64 + -29960;
	// addi r3,r6,-21808
	ctx.r3.s64 = ctx.r6.s64 + -21808;
	// bl 0x82554798
	ctx.lr = 0x822CA5F4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-29872
	ctx.r4.s64 = ctx.r5.s64 + -29872;
	// addi r3,r3,-21832
	ctx.r3.s64 = ctx.r3.s64 + -21832;
	// bl 0x82554798
	ctx.lr = 0x822CA608;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// addi r4,r11,-32032
	ctx.r4.s64 = r11.s64 + -32032;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-21864
	ctx.r3.s64 = ctx.r10.s64 + -21864;
	// bl 0x82554798
	ctx.lr = 0x822CA61C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-32024
	ctx.r4.s64 = ctx.r9.s64 + -32024;
	// addi r3,r8,-21900
	ctx.r3.s64 = ctx.r8.s64 + -21900;
	// bl 0x82554798
	ctx.lr = 0x822CA630;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-32016
	ctx.r4.s64 = ctx.r7.s64 + -32016;
	// addi r3,r6,-21928
	ctx.r3.s64 = ctx.r6.s64 + -21928;
	// bl 0x82554798
	ctx.lr = 0x822CA644;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-32008
	ctx.r4.s64 = ctx.r5.s64 + -32008;
	// addi r3,r3,-21960
	ctx.r3.s64 = ctx.r3.s64 + -21960;
	// bl 0x82554798
	ctx.lr = 0x822CA658;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-32000
	ctx.r4.s64 = r11.s64 + -32000;
	// addi r3,r10,-21992
	ctx.r3.s64 = ctx.r10.s64 + -21992;
	// bl 0x82554798
	ctx.lr = 0x822CA66C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-31992
	ctx.r4.s64 = ctx.r9.s64 + -31992;
	// addi r3,r8,-22024
	ctx.r3.s64 = ctx.r8.s64 + -22024;
	// bl 0x82554798
	ctx.lr = 0x822CA680;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-31984
	ctx.r4.s64 = ctx.r7.s64 + -31984;
	// addi r3,r6,-22064
	ctx.r3.s64 = ctx.r6.s64 + -22064;
	// bl 0x82554798
	ctx.lr = 0x822CA694;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-29808
	ctx.r4.s64 = ctx.r5.s64 + -29808;
	// addi r3,r3,-22100
	ctx.r3.s64 = ctx.r3.s64 + -22100;
	// bl 0x82554798
	ctx.lr = 0x822CA6A8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29776
	ctx.r4.s64 = r11.s64 + -29776;
	// addi r3,r10,-22124
	ctx.r3.s64 = ctx.r10.s64 + -22124;
	// bl 0x82554798
	ctx.lr = 0x822CA6BC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-31976
	ctx.r4.s64 = ctx.r9.s64 + -31976;
	// addi r3,r8,-22140
	ctx.r3.s64 = ctx.r8.s64 + -22140;
	// bl 0x82554798
	ctx.lr = 0x822CA6D0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28752
	ctx.r4.s64 = ctx.r7.s64 + -28752;
	// addi r3,r6,-22156
	ctx.r3.s64 = ctx.r6.s64 + -22156;
	// bl 0x82554798
	ctx.lr = 0x822CA6E4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25048
	ctx.r4.s64 = ctx.r5.s64 + -25048;
	// addi r3,r3,-22168
	ctx.r3.s64 = ctx.r3.s64 + -22168;
	// bl 0x82554798
	ctx.lr = 0x822CA6F8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-24984
	ctx.r4.s64 = r11.s64 + -24984;
	// addi r3,r10,-22180
	ctx.r3.s64 = ctx.r10.s64 + -22180;
	// bl 0x82554798
	ctx.lr = 0x822CA70C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-24920
	ctx.r4.s64 = ctx.r9.s64 + -24920;
	// addi r3,r8,-22196
	ctx.r3.s64 = ctx.r8.s64 + -22196;
	// bl 0x82554798
	ctx.lr = 0x822CA720;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24856
	ctx.r4.s64 = ctx.r7.s64 + -24856;
	// addi r3,r6,-22236
	ctx.r3.s64 = ctx.r6.s64 + -22236;
	// bl 0x82554798
	ctx.lr = 0x822CA734;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-24744
	ctx.r4.s64 = ctx.r5.s64 + -24744;
	// addi r3,r3,-22264
	ctx.r3.s64 = ctx.r3.s64 + -22264;
	// bl 0x82554798
	ctx.lr = 0x822CA748;
	sub_82554798(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r3,r11,-22300
	ctx.r3.s64 = r11.s64 + -22300;
	// addi r4,r10,-28696
	ctx.r4.s64 = ctx.r10.s64 + -28696;
	// bl 0x82554798
	ctx.lr = 0x822CA75C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28632
	ctx.r4.s64 = ctx.r9.s64 + -28632;
	// addi r3,r8,-22340
	ctx.r3.s64 = ctx.r8.s64 + -22340;
	// bl 0x82554798
	ctx.lr = 0x822CA770;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24680
	ctx.r4.s64 = ctx.r7.s64 + -24680;
	// addi r3,r6,-22376
	ctx.r3.s64 = ctx.r6.s64 + -22376;
	// bl 0x82554798
	ctx.lr = 0x822CA784;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28560
	ctx.r4.s64 = ctx.r5.s64 + -28560;
	// addi r3,r3,-22412
	ctx.r3.s64 = ctx.r3.s64 + -22412;
	// bl 0x82554798
	ctx.lr = 0x822CA798;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28496
	ctx.r4.s64 = r11.s64 + -28496;
	// addi r3,r10,-22448
	ctx.r3.s64 = ctx.r10.s64 + -22448;
	// bl 0x82554798
	ctx.lr = 0x822CA7AC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-24616
	ctx.r4.s64 = ctx.r9.s64 + -24616;
	// addi r3,r8,-22480
	ctx.r3.s64 = ctx.r8.s64 + -22480;
	// bl 0x82554798
	ctx.lr = 0x822CA7C0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24600
	ctx.r4.s64 = ctx.r7.s64 + -24600;
	// addi r3,r6,-22520
	ctx.r3.s64 = ctx.r6.s64 + -22520;
	// bl 0x82554798
	ctx.lr = 0x822CA7D4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28432
	ctx.r4.s64 = ctx.r5.s64 + -28432;
	// addi r3,r3,-22556
	ctx.r3.s64 = ctx.r3.s64 + -22556;
	// bl 0x82554798
	ctx.lr = 0x822CA7E8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28368
	ctx.r4.s64 = r11.s64 + -28368;
	// addi r3,r10,-22592
	ctx.r3.s64 = ctx.r10.s64 + -22592;
	// bl 0x82554798
	ctx.lr = 0x822CA7FC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28304
	ctx.r4.s64 = ctx.r9.s64 + -28304;
	// addi r3,r8,-22624
	ctx.r3.s64 = ctx.r8.s64 + -22624;
	// bl 0x82554798
	ctx.lr = 0x822CA810;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28240
	ctx.r4.s64 = ctx.r7.s64 + -28240;
	// addi r3,r6,-22656
	ctx.r3.s64 = ctx.r6.s64 + -22656;
	// bl 0x82554798
	ctx.lr = 0x822CA824;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28176
	ctx.r4.s64 = ctx.r5.s64 + -28176;
	// addi r3,r3,-22692
	ctx.r3.s64 = ctx.r3.s64 + -22692;
	// bl 0x82554798
	ctx.lr = 0x822CA838;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28112
	ctx.r4.s64 = r11.s64 + -28112;
	// addi r3,r10,-22720
	ctx.r3.s64 = ctx.r10.s64 + -22720;
	// bl 0x82554798
	ctx.lr = 0x822CA84C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28048
	ctx.r4.s64 = ctx.r9.s64 + -28048;
	// addi r3,r8,-22752
	ctx.r3.s64 = ctx.r8.s64 + -22752;
	// bl 0x82554798
	ctx.lr = 0x822CA860;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27984
	ctx.r4.s64 = ctx.r7.s64 + -27984;
	// addi r3,r6,-22784
	ctx.r3.s64 = ctx.r6.s64 + -22784;
	// bl 0x82554798
	ctx.lr = 0x822CA874;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27920
	ctx.r4.s64 = ctx.r5.s64 + -27920;
	// addi r3,r3,-22816
	ctx.r3.s64 = ctx.r3.s64 + -22816;
	// bl 0x82554798
	ctx.lr = 0x822CA888;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27856
	ctx.r4.s64 = r11.s64 + -27856;
	// addi r3,r10,-22852
	ctx.r3.s64 = ctx.r10.s64 + -22852;
	// bl 0x82554798
	ctx.lr = 0x822CA89C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-27792
	ctx.r4.s64 = ctx.r9.s64 + -27792;
	// addi r3,r8,-22884
	ctx.r3.s64 = ctx.r8.s64 + -22884;
	// bl 0x82554798
	ctx.lr = 0x822CA8B0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27728
	ctx.r4.s64 = ctx.r7.s64 + -27728;
	// addi r3,r6,-22920
	ctx.r3.s64 = ctx.r6.s64 + -22920;
	// bl 0x82554798
	ctx.lr = 0x822CA8C4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27664
	ctx.r4.s64 = ctx.r5.s64 + -27664;
	// addi r3,r3,-22952
	ctx.r3.s64 = ctx.r3.s64 + -22952;
	// bl 0x82554798
	ctx.lr = 0x822CA8D8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27600
	ctx.r4.s64 = r11.s64 + -27600;
	// addi r3,r10,-22972
	ctx.r3.s64 = ctx.r10.s64 + -22972;
	// bl 0x82554798
	ctx.lr = 0x822CA8EC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-27544
	ctx.r4.s64 = ctx.r9.s64 + -27544;
	// addi r3,r8,-22992
	ctx.r3.s64 = ctx.r8.s64 + -22992;
	// bl 0x82554798
	ctx.lr = 0x822CA900;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27528
	ctx.r4.s64 = ctx.r7.s64 + -27528;
	// addi r3,r6,-23012
	ctx.r3.s64 = ctx.r6.s64 + -23012;
	// bl 0x82554798
	ctx.lr = 0x822CA914;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27456
	ctx.r4.s64 = ctx.r5.s64 + -27456;
	// addi r3,r3,-23032
	ctx.r3.s64 = ctx.r3.s64 + -23032;
	// bl 0x82554798
	ctx.lr = 0x822CA928;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27440
	ctx.r4.s64 = r11.s64 + -27440;
	// addi r3,r10,-23060
	ctx.r3.s64 = ctx.r10.s64 + -23060;
	// bl 0x82554798
	ctx.lr = 0x822CA93C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-27424
	ctx.r4.s64 = ctx.r9.s64 + -27424;
	// addi r3,r8,-23092
	ctx.r3.s64 = ctx.r8.s64 + -23092;
	// bl 0x82554798
	ctx.lr = 0x822CA950;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27360
	ctx.r4.s64 = ctx.r7.s64 + -27360;
	// addi r3,r6,-23132
	ctx.r3.s64 = ctx.r6.s64 + -23132;
	// bl 0x82554798
	ctx.lr = 0x822CA964;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27288
	ctx.r4.s64 = ctx.r5.s64 + -27288;
	// addi r3,r3,-23164
	ctx.r3.s64 = ctx.r3.s64 + -23164;
	// bl 0x82554798
	ctx.lr = 0x822CA978;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27264
	ctx.r4.s64 = r11.s64 + -27264;
	// addi r3,r10,-23192
	ctx.r3.s64 = ctx.r10.s64 + -23192;
	// bl 0x82554798
	ctx.lr = 0x822CA98C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-27200
	ctx.r4.s64 = ctx.r9.s64 + -27200;
	// addi r3,r8,-23212
	ctx.r3.s64 = ctx.r8.s64 + -23212;
	// bl 0x82554798
	ctx.lr = 0x822CA9A0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27128
	ctx.r4.s64 = ctx.r7.s64 + -27128;
	// addi r3,r6,-23232
	ctx.r3.s64 = ctx.r6.s64 + -23232;
	// bl 0x82554798
	ctx.lr = 0x822CA9B4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27088
	ctx.r4.s64 = ctx.r5.s64 + -27088;
	// addi r3,r3,-23264
	ctx.r3.s64 = ctx.r3.s64 + -23264;
	// bl 0x82554798
	ctx.lr = 0x822CA9C8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27024
	ctx.r4.s64 = r11.s64 + -27024;
	// addi r3,r10,-23288
	ctx.r3.s64 = ctx.r10.s64 + -23288;
	// bl 0x82554798
	ctx.lr = 0x822CA9DC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-24496
	ctx.r4.s64 = ctx.r9.s64 + -24496;
	// addi r3,r8,-23308
	ctx.r3.s64 = ctx.r8.s64 + -23308;
	// bl 0x82554798
	ctx.lr = 0x822CA9F0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24472
	ctx.r4.s64 = ctx.r7.s64 + -24472;
	// addi r3,r6,-23328
	ctx.r3.s64 = ctx.r6.s64 + -23328;
	// bl 0x82554798
	ctx.lr = 0x822CAA04;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-24408
	ctx.r4.s64 = ctx.r5.s64 + -24408;
	// addi r3,r3,-23348
	ctx.r3.s64 = ctx.r3.s64 + -23348;
	// bl 0x82554798
	ctx.lr = 0x822CAA18;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-24344
	ctx.r4.s64 = r11.s64 + -24344;
	// addi r3,r10,-23372
	ctx.r3.s64 = ctx.r10.s64 + -23372;
	// bl 0x82554798
	ctx.lr = 0x822CAA2C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29720
	ctx.r4.s64 = ctx.r9.s64 + -29720;
	// addi r3,r8,-23396
	ctx.r3.s64 = ctx.r8.s64 + -23396;
	// bl 0x82554798
	ctx.lr = 0x822CAA40;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24280
	ctx.r4.s64 = ctx.r7.s64 + -24280;
	// addi r3,r6,-23420
	ctx.r3.s64 = ctx.r6.s64 + -23420;
	// bl 0x82554798
	ctx.lr = 0x822CAA54;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-24216
	ctx.r4.s64 = ctx.r5.s64 + -24216;
	// addi r3,r3,-23444
	ctx.r3.s64 = ctx.r3.s64 + -23444;
	// bl 0x82554798
	ctx.lr = 0x822CAA68;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29664
	ctx.r4.s64 = r11.s64 + -29664;
	// addi r3,r10,-23472
	ctx.r3.s64 = ctx.r10.s64 + -23472;
	// bl 0x82554798
	ctx.lr = 0x822CAA7C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29608
	ctx.r4.s64 = ctx.r9.s64 + -29608;
	// addi r3,r8,-23496
	ctx.r3.s64 = ctx.r8.s64 + -23496;
	// bl 0x82554798
	ctx.lr = 0x822CAA90;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-29552
	ctx.r4.s64 = ctx.r7.s64 + -29552;
	// addi r3,r6,-23520
	ctx.r3.s64 = ctx.r6.s64 + -23520;
	// bl 0x82554798
	ctx.lr = 0x822CAAA4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-24152
	ctx.r4.s64 = ctx.r5.s64 + -24152;
	// addi r3,r3,-23548
	ctx.r3.s64 = ctx.r3.s64 + -23548;
	// bl 0x82554798
	ctx.lr = 0x822CAAB8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29496
	ctx.r4.s64 = r11.s64 + -29496;
	// addi r3,r10,-23580
	ctx.r3.s64 = ctx.r10.s64 + -23580;
	// bl 0x82554798
	ctx.lr = 0x822CAACC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29440
	ctx.r4.s64 = ctx.r9.s64 + -29440;
	// addi r3,r8,-23616
	ctx.r3.s64 = ctx.r8.s64 + -23616;
	// bl 0x82554798
	ctx.lr = 0x822CAAE0;
	sub_82554798(ctx, base);
	// lis r5,-32131
	ctx.r5.s64 = -2105737216;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r3,r5,30576
	ctx.r3.s64 = ctx.r5.s64 + 30576;
	// addi r7,r7,-23620
	ctx.r7.s64 = ctx.r7.s64 + -23620;
	// addi r6,r6,-23664
	ctx.r6.s64 = ctx.r6.s64 + -23664;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca2f8
	ctx.lr = 0x822CAB08;
	sub_821CA2F8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cb488
	ctx.lr = 0x822CAB14;
	sub_821CB488(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cab58
	if (cr6.eq) goto loc_822CAB58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CAB30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// cmpldi cr6,r3,3184
	cr6.compare<uint64_t>(ctx.r3.u64, 3184, xer);
	// addi r3,r10,-23696
	ctx.r3.s64 = ctx.r10.s64 + -23696;
	// bne cr6,0x822cab4c
	if (!cr6.eq) goto loc_822CAB4C;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// addi r4,r11,-29384
	ctx.r4.s64 = r11.s64 + -29384;
	// b 0x822cab68
	goto loc_822CAB68;
loc_822CAB4C:
	// lis r11,-32211
	r11.s64 = -2110980096;
	// addi r4,r11,-29328
	ctx.r4.s64 = r11.s64 + -29328;
	// b 0x822cab68
	goto loc_822CAB68;
loc_822CAB58:
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29328
	ctx.r4.s64 = r11.s64 + -29328;
	// addi r3,r10,-23696
	ctx.r3.s64 = ctx.r10.s64 + -23696;
loc_822CAB68:
	// bl 0x82554798
	ctx.lr = 0x822CAB6C;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29272
	ctx.r4.s64 = r11.s64 + -29272;
	// addi r3,r10,-23720
	ctx.r3.s64 = ctx.r10.s64 + -23720;
	// bl 0x82554798
	ctx.lr = 0x822CAB80;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29216
	ctx.r4.s64 = ctx.r9.s64 + -29216;
	// addi r3,r8,-23740
	ctx.r3.s64 = ctx.r8.s64 + -23740;
	// bl 0x82554798
	ctx.lr = 0x822CAB94;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24088
	ctx.r4.s64 = ctx.r7.s64 + -24088;
	// addi r3,r6,-23768
	ctx.r3.s64 = ctx.r6.s64 + -23768;
	// bl 0x82554798
	ctx.lr = 0x822CABA8;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-29160
	ctx.r4.s64 = ctx.r5.s64 + -29160;
	// addi r3,r3,-23788
	ctx.r3.s64 = ctx.r3.s64 + -23788;
	// bl 0x82554798
	ctx.lr = 0x822CABBC;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29160
	ctx.r4.s64 = r11.s64 + -29160;
	// addi r3,r10,-23812
	ctx.r3.s64 = ctx.r10.s64 + -23812;
	// bl 0x82554798
	ctx.lr = 0x822CABD0;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29104
	ctx.r4.s64 = ctx.r9.s64 + -29104;
	// addi r3,r8,-23840
	ctx.r3.s64 = ctx.r8.s64 + -23840;
	// bl 0x82554798
	ctx.lr = 0x822CABE4;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-29048
	ctx.r4.s64 = ctx.r7.s64 + -29048;
	// addi r3,r6,-23864
	ctx.r3.s64 = ctx.r6.s64 + -23864;
	// bl 0x82554798
	ctx.lr = 0x822CABF8;
	sub_82554798(ctx, base);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,0
	ctx.r4.s64 = ctx.r5.s64 + 0;
	// addi r3,r3,-23880
	ctx.r3.s64 = ctx.r3.s64 + -23880;
	// bl 0x82554798
	ctx.lr = 0x822CAC0C;
	sub_82554798(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r10,-23896
	ctx.r3.s64 = ctx.r10.s64 + -23896;
	// bl 0x82554798
	ctx.lr = 0x822CAC20;
	sub_82554798(ctx, base);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,0
	ctx.r4.s64 = ctx.r9.s64 + 0;
	// addi r3,r8,-23908
	ctx.r3.s64 = ctx.r8.s64 + -23908;
	// bl 0x82554798
	ctx.lr = 0x822CAC34;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24024
	ctx.r4.s64 = ctx.r7.s64 + -24024;
	// addi r3,r6,-23940
	ctx.r3.s64 = ctx.r6.s64 + -23940;
	// bl 0x82554798
	ctx.lr = 0x822CAC48;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-26960
	ctx.r4.s64 = ctx.r5.s64 + -26960;
	// addi r3,r3,-23972
	ctx.r3.s64 = ctx.r3.s64 + -23972;
	// bl 0x82554798
	ctx.lr = 0x822CAC5C;
	sub_82554798(ctx, base);
	// bl 0x822c7018
	ctx.lr = 0x822CAC60;
	sub_822C7018(ctx, base);
	// bl 0x82305468
	ctx.lr = 0x822CAC64;
	sub_82305468(ctx, base);
	// bl 0x821e7e08
	ctx.lr = 0x822CAC68;
	sub_821E7E08(ctx, base);
	// bl 0x8268bb28
	ctx.lr = 0x822CAC6C;
	sub_8268BB28(ctx, base);
	// bl 0x822a7b20
	ctx.lr = 0x822CAC70;
	sub_822A7B20(ctx, base);
	// bl 0x822a4500
	ctx.lr = 0x822CAC74;
	sub_822A4500(ctx, base);
	// bl 0x822b9d28
	ctx.lr = 0x822CAC78;
	sub_822B9D28(ctx, base);
	// bl 0x822b8f48
	ctx.lr = 0x822CAC7C;
	sub_822B8F48(ctx, base);
	// bl 0x82744130
	ctx.lr = 0x822CAC80;
	sub_82744130(ctx, base);
	// bl 0x822624e8
	ctx.lr = 0x822CAC84;
	sub_822624E8(ctx, base);
	// bl 0x827096c8
	ctx.lr = 0x822CAC88;
	sub_827096C8(ctx, base);
	// bl 0x82742b10
	ctx.lr = 0x822CAC8C;
	sub_82742B10(ctx, base);
	// bl 0x822b6578
	ctx.lr = 0x822CAC90;
	sub_822B6578(ctx, base);
	// bl 0x8239d8d0
	ctx.lr = 0x822CAC94;
	sub_8239D8D0(ctx, base);
	// bl 0x82721540
	ctx.lr = 0x822CAC98;
	sub_82721540(ctx, base);
	// bl 0x821fdac8
	ctx.lr = 0x822CAC9C;
	sub_821FDAC8(ctx, base);
	// bl 0x82628270
	ctx.lr = 0x822CACA0;
	sub_82628270(ctx, base);
	// bl 0x82238b68
	ctx.lr = 0x822CACA4;
	sub_82238B68(ctx, base);
	// bl 0x82234f28
	ctx.lr = 0x822CACA8;
	sub_82234F28(ctx, base);
	// bl 0x82721fd8
	ctx.lr = 0x822CACAC;
	sub_82721FD8(ctx, base);
	// bl 0x8223de38
	ctx.lr = 0x822CACB0;
	sub_8223DE38(ctx, base);
	// bl 0x82212750
	ctx.lr = 0x822CACB4;
	sub_82212750(ctx, base);
	// bl 0x82218b98
	ctx.lr = 0x822CACB8;
	sub_82218B98(ctx, base);
	// bl 0x8272cfe8
	ctx.lr = 0x822CACBC;
	sub_8272CFE8(ctx, base);
	// bl 0x82255cb0
	ctx.lr = 0x822CACC0;
	sub_82255CB0(ctx, base);
	// bl 0x82256e60
	ctx.lr = 0x822CACC4;
	sub_82256E60(ctx, base);
	// bl 0x822671c8
	ctx.lr = 0x822CACC8;
	sub_822671C8(ctx, base);
	// bl 0x82264418
	ctx.lr = 0x822CACCC;
	sub_82264418(ctx, base);
	// bl 0x82267be0
	ctx.lr = 0x822CACD0;
	sub_82267BE0(ctx, base);
	// bl 0x82264780
	ctx.lr = 0x822CACD4;
	sub_82264780(ctx, base);
	// bl 0x823c6ef8
	ctx.lr = 0x822CACD8;
	sub_823C6EF8(ctx, base);
	// bl 0x826c2160
	ctx.lr = 0x822CACDC;
	sub_826C2160(ctx, base);
	// bl 0x826bb680
	ctx.lr = 0x822CACE0;
	sub_826BB680(ctx, base);
	// bl 0x826b6278
	ctx.lr = 0x822CACE4;
	sub_826B6278(ctx, base);
	// bl 0x826b50d0
	ctx.lr = 0x822CACE8;
	sub_826B50D0(ctx, base);
	// bl 0x82293988
	ctx.lr = 0x822CACEC;
	sub_82293988(ctx, base);
	// bl 0x826d8cc0
	ctx.lr = 0x822CACF0;
	sub_826D8CC0(ctx, base);
	// bl 0x82692268
	ctx.lr = 0x822CACF4;
	sub_82692268(ctx, base);
	// bl 0x82684998
	ctx.lr = 0x822CACF8;
	sub_82684998(ctx, base);
	// bl 0x82687090
	ctx.lr = 0x822CACFC;
	sub_82687090(ctx, base);
	// bl 0x826869a8
	ctx.lr = 0x822CAD00;
	sub_826869A8(ctx, base);
	// bl 0x82685188
	ctx.lr = 0x822CAD04;
	sub_82685188(ctx, base);
	// bl 0x82680fd8
	ctx.lr = 0x822CAD08;
	sub_82680FD8(ctx, base);
	// bl 0x8239d638
	ctx.lr = 0x822CAD0C;
	sub_8239D638(ctx, base);
	// bl 0x82398f80
	ctx.lr = 0x822CAD10;
	sub_82398F80(ctx, base);
	// bl 0x8239cd98
	ctx.lr = 0x822CAD14;
	sub_8239CD98(ctx, base);
	// bl 0x82390c00
	ctx.lr = 0x822CAD18;
	sub_82390C00(ctx, base);
	// bl 0x82260938
	ctx.lr = 0x822CAD1C;
	sub_82260938(ctx, base);
	// bl 0x8225d1f0
	ctx.lr = 0x822CAD20;
	sub_8225D1F0(ctx, base);
	// bl 0x822ccc00
	ctx.lr = 0x822CAD24;
	sub_822CCC00(ctx, base);
	// bl 0x8273bb38
	ctx.lr = 0x822CAD28;
	sub_8273BB38(ctx, base);
	// bl 0x8273aed8
	ctx.lr = 0x822CAD2C;
	sub_8273AED8(ctx, base);
	// bl 0x82397838
	ctx.lr = 0x822CAD30;
	sub_82397838(ctx, base);
	// bl 0x82269520
	ctx.lr = 0x822CAD34;
	sub_82269520(ctx, base);
	// bl 0x82269538
	ctx.lr = 0x822CAD38;
	sub_82269538(ctx, base);
	// bl 0x822d1648
	ctx.lr = 0x822CAD3C;
	sub_822D1648(ctx, base);
	// bl 0x826c3b50
	ctx.lr = 0x822CAD40;
	sub_826C3B50(ctx, base);
	// bl 0x821f0c60
	ctx.lr = 0x822CAD44;
	sub_821F0C60(ctx, base);
	// bl 0x82633b50
	ctx.lr = 0x822CAD48;
	sub_82633B50(ctx, base);
	// bl 0x821f2a08
	ctx.lr = 0x822CAD4C;
	sub_821F2A08(ctx, base);
	// bl 0x822e9118
	ctx.lr = 0x822CAD50;
	sub_822E9118(ctx, base);
	// bl 0x82307c98
	ctx.lr = 0x822CAD54;
	sub_82307C98(ctx, base);
	// bl 0x82328fb8
	ctx.lr = 0x822CAD58;
	sub_82328FB8(ctx, base);
	// bl 0x822f3bc0
	ctx.lr = 0x822CAD5C;
	sub_822F3BC0(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CAD6C"))) PPC_WEAK_FUNC(sub_822CAD6C);
PPC_FUNC_IMPL(__imp__sub_822CAD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CAD70"))) PPC_WEAK_FUNC(sub_822CAD70);
PPC_FUNC_IMPL(__imp__sub_822CAD70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,21364
	ctx.r3.s64 = r11.s64 + 21364;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CAD7C"))) PPC_WEAK_FUNC(sub_822CAD7C);
PPC_FUNC_IMPL(__imp__sub_822CAD7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CAD80"))) PPC_WEAK_FUNC(sub_822CAD80);
PPC_FUNC_IMPL(__imp__sub_822CAD80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// b 0x822a4570
	sub_822A4570(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CAD90"))) PPC_WEAK_FUNC(sub_822CAD90);
PPC_FUNC_IMPL(__imp__sub_822CAD90) {
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
	// li r3,1232
	ctx.r3.s64 = 1232;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x822CADAC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// beq cr6,0x822cadc8
	if (cr6.eq) goto loc_822CADC8;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a6e88
	ctx.lr = 0x822CADC4;
	sub_822A6E88(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_822CADC8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a4718
	ctx.lr = 0x822CADD8;
	sub_822A4718(ctx, base);
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

__attribute__((alias("__imp__sub_822CADEC"))) PPC_WEAK_FUNC(sub_822CADEC);
PPC_FUNC_IMPL(__imp__sub_822CADEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CADF0"))) PPC_WEAK_FUNC(sub_822CADF0);
PPC_FUNC_IMPL(__imp__sub_822CADF0) {
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
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822CADF8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822CAE28;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cae98
	if (cr6.eq) goto loc_822CAE98;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822CAE40;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stb r26,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r26.u8);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8238efe0
	ctx.lr = 0x822CAE54;
	sub_8238EFE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822a8e18
	ctx.lr = 0x822CAE60;
	sub_822A8E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x822ae7c8
	ctx.lr = 0x822CAE6C;
	sub_822AE7C8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,27644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x822abd10
	ctx.lr = 0x822CAE98;
	sub_822ABD10(ctx, base);
loc_822CAE98:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822CAEA4"))) PPC_WEAK_FUNC(sub_822CAEA4);
PPC_FUNC_IMPL(__imp__sub_822CAEA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CAEA8"))) PPC_WEAK_FUNC(sub_822CAEA8);
PPC_FUNC_IMPL(__imp__sub_822CAEA8) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,17436(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822caf10
	if (!cr6.eq) goto loc_822CAF10;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x822CAED0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822caef4
	if (cr6.eq) goto loc_822CAEF4;
	// bl 0x82360fa0
	ctx.lr = 0x822CAEDC;
	sub_82360FA0(ctx, base);
	// stw r3,17436(r31)
	PPC_STORE_U32(r31.u32 + 17436, ctx.r3.u32);
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
loc_822CAEF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,17436(r31)
	PPC_STORE_U32(r31.u32 + 17436, ctx.r3.u32);
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
loc_822CAF10:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,17436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17436);
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

__attribute__((alias("__imp__sub_822CAF34"))) PPC_WEAK_FUNC(sub_822CAF34);
PPC_FUNC_IMPL(__imp__sub_822CAF34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CAF38"))) PPC_WEAK_FUNC(sub_822CAF38);
PPC_FUNC_IMPL(__imp__sub_822CAF38) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-3664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cafa0
	if (!cr6.eq) goto loc_822CAFA0;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x822CAF60;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822caf84
	if (cr6.eq) goto loc_822CAF84;
	// bl 0x8226a470
	ctx.lr = 0x822CAF6C;
	sub_8226A470(ctx, base);
	// stw r3,-3664(r31)
	PPC_STORE_U32(r31.u32 + -3664, ctx.r3.u32);
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
loc_822CAF84:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,-3664(r31)
	PPC_STORE_U32(r31.u32 + -3664, ctx.r3.u32);
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
loc_822CAFA0:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,-3664(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3664);
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

__attribute__((alias("__imp__sub_822CAFC4"))) PPC_WEAK_FUNC(sub_822CAFC4);
PPC_FUNC_IMPL(__imp__sub_822CAFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CAFC8"))) PPC_WEAK_FUNC(sub_822CAFC8);
PPC_FUNC_IMPL(__imp__sub_822CAFC8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-20428
	ctx.r10.s64 = r11.s64 + -20428;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822b8178
	ctx.lr = 0x822CAFF4;
	sub_822B8178(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cb00c
	if (cr6.eq) goto loc_822CB00C;
	// bl 0x82130588
	ctx.lr = 0x822CB008;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822CB00C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CB024"))) PPC_WEAK_FUNC(sub_822CB024);
PPC_FUNC_IMPL(__imp__sub_822CB024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CB028"))) PPC_WEAK_FUNC(sub_822CB028);
PPC_FUNC_IMPL(__imp__sub_822CB028) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-20420
	ctx.r10.s64 = r11.s64 + -20420;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8270ad40
	ctx.lr = 0x822CB054;
	sub_8270AD40(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cb06c
	if (cr6.eq) goto loc_822CB06C;
	// bl 0x82130588
	ctx.lr = 0x822CB068;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822CB06C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CB084"))) PPC_WEAK_FUNC(sub_822CB084);
PPC_FUNC_IMPL(__imp__sub_822CB084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CB088"))) PPC_WEAK_FUNC(sub_822CB088);
PPC_FUNC_IMPL(__imp__sub_822CB088) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-20480
	ctx.r10.s64 = r11.s64 + -20480;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82257430
	ctx.lr = 0x822CB0B4;
	sub_82257430(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d2bb8
	ctx.lr = 0x822CB0BC;
	sub_822D2BB8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cb0d4
	if (cr6.eq) goto loc_822CB0D4;
	// bl 0x82130588
	ctx.lr = 0x822CB0D0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822CB0D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CB0EC"))) PPC_WEAK_FUNC(sub_822CB0EC);
PPC_FUNC_IMPL(__imp__sub_822CB0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CB0F0"))) PPC_WEAK_FUNC(sub_822CB0F0);
PPC_FUNC_IMPL(__imp__sub_822CB0F0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r3,-12040(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12040);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822cb130
	if (!cr6.eq) goto loc_822CB130;
	// li r3,784
	ctx.r3.s64 = 784;
	// bl 0x82130528
	ctx.lr = 0x822CB118;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb128
	if (cr6.eq) goto loc_822CB128;
	// bl 0x8239b148
	ctx.lr = 0x822CB124;
	sub_8239B148(ctx, base);
	// b 0x822cb12c
	goto loc_822CB12C;
loc_822CB128:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822CB12C:
	// stw r3,-12040(r31)
	PPC_STORE_U32(r31.u32 + -12040, ctx.r3.u32);
loc_822CB130:
	// bl 0x82399618
	ctx.lr = 0x822CB134;
	sub_82399618(ctx, base);
	// lwz r3,-12040(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12040);
	// bl 0x82399490
	ctx.lr = 0x822CB13C;
	sub_82399490(ctx, base);
	// lwz r3,-12040(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12040);
	// bl 0x8239aca0
	ctx.lr = 0x822CB144;
	sub_8239ACA0(ctx, base);
	// lwz r3,-12040(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12040);
	// bl 0x8239a5d8
	ctx.lr = 0x822CB14C;
	sub_8239A5D8(ctx, base);
	// lwz r3,-12040(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12040);
	// bl 0x82399e08
	ctx.lr = 0x822CB154;
	sub_82399E08(ctx, base);
	// lwz r3,-12040(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12040);
	// bl 0x8239a9f0
	ctx.lr = 0x822CB15C;
	sub_8239A9F0(ctx, base);
	// lwz r3,-12040(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12040);
	// bl 0x82399f88
	ctx.lr = 0x822CB164;
	sub_82399F88(ctx, base);
	// bl 0x82337db8
	ctx.lr = 0x822CB168;
	sub_82337DB8(ctx, base);
	// bl 0x822caea8
	ctx.lr = 0x822CB16C;
	sub_822CAEA8(ctx, base);
	// bl 0x823614f0
	ctx.lr = 0x822CB170;
	sub_823614F0(ctx, base);
	// bl 0x823746c8
	ctx.lr = 0x822CB174;
	sub_823746C8(ctx, base);
	// bl 0x823736b8
	ctx.lr = 0x822CB178;
	sub_823736B8(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-8252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8252);
	// bl 0x8236e400
	ctx.lr = 0x822CB184;
	sub_8236E400(ctx, base);
	// bl 0x82740188
	ctx.lr = 0x822CB188;
	sub_82740188(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,-21528(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21528);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CB1A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,17892(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17892);
	// bl 0x822b5a58
	ctx.lr = 0x822CB1AC;
	sub_822B5A58(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,-10016(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10016);
	// bl 0x827060d0
	ctx.lr = 0x822CB1C0;
	sub_827060D0(ctx, base);
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

__attribute__((alias("__imp__sub_822CB1D4"))) PPC_WEAK_FUNC(sub_822CB1D4);
PPC_FUNC_IMPL(__imp__sub_822CB1D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CB1D8"))) PPC_WEAK_FUNC(sub_822CB1D8);
PPC_FUNC_IMPL(__imp__sub_822CB1D8) {
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
	ctx.lr = 0x822CB1E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x822a38b0
	ctx.lr = 0x822CB1EC;
	sub_822A38B0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-5148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -5148);
	// bl 0x822b8e00
	ctx.lr = 0x822CB1F8;
	sub_822B8E00(ctx, base);
	// lwz r3,-5148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -5148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb218
	if (cr6.eq) goto loc_822CB218;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CB218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CB218:
	// li r29,0
	r29.s64 = 0;
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-5148(r31)
	PPC_STORE_U32(r31.u32 + -5148, r11.u32);
	// bl 0x82742bc8
	ctx.lr = 0x822CB228;
	sub_82742BC8(ctx, base);
	// bl 0x82260ca0
	ctx.lr = 0x822CB22C;
	sub_82260CA0(ctx, base);
	// bl 0x823916e0
	ctx.lr = 0x822CB230;
	sub_823916E0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// bl 0x82706618
	ctx.lr = 0x822CB23C;
	sub_82706618(ctx, base);
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb25c
	if (cr6.eq) goto loc_822CB25C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CB25C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CB25C:
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-10016(r31)
	PPC_STORE_U32(r31.u32 + -10016, r11.u32);
	// bl 0x822b64e8
	ctx.lr = 0x822CB268;
	sub_822B64E8(ctx, base);
	// bl 0x822bee98
	ctx.lr = 0x822CB26C;
	sub_822BEE98(ctx, base);
	// bl 0x82373750
	ctx.lr = 0x822CB270;
	sub_82373750(ctx, base);
	// bl 0x823752c8
	ctx.lr = 0x822CB274;
	sub_823752C8(ctx, base);
	// bl 0x82360c68
	ctx.lr = 0x822CB278;
	sub_82360C68(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,17436(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17436);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r3,17436(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17436);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822cb2b0
	if (!cr6.eq) goto loc_822CB2B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CB2B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CB2B0:
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r30,-12040(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -12040);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822cb2d0
	if (cr6.eq) goto loc_822CB2D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239b400
	ctx.lr = 0x822CB2C8;
	sub_8239B400(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822CB2D0;
	sub_82130588(ctx, base);
loc_822CB2D0:
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12040(r31)
	PPC_STORE_U32(r31.u32 + -12040, r11.u32);
	// bl 0x82699088
	ctx.lr = 0x822CB2DC;
	sub_82699088(ctx, base);
	// bl 0x82250448
	ctx.lr = 0x822CB2E0;
	sub_82250448(ctx, base);
	// bl 0x82264528
	ctx.lr = 0x822CB2E4;
	sub_82264528(ctx, base);
	// lwz r3,32(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb304
	if (cr6.eq) goto loc_822CB304;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CB304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CB304:
	// stw r29,32(r28)
	PPC_STORE_U32(r28.u32 + 32, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822CB310"))) PPC_WEAK_FUNC(sub_822CB310);
PPC_FUNC_IMPL(__imp__sub_822CB310) {
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
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3bb0
	ctx.lr = 0x822CB328;
	sub_822A3BB0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-5148(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5148);
	// bl 0x822b7710
	ctx.lr = 0x822CB334;
	sub_822B7710(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,-10016(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10016);
	// bl 0x82702808
	ctx.lr = 0x822CB340;
	sub_82702808(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CB350"))) PPC_WEAK_FUNC(sub_822CB350);
PPC_FUNC_IMPL(__imp__sub_822CB350) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-12640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cb38c
	if (cr6.eq) goto loc_822CB38C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822cb390
	if (cr6.eq) goto loc_822CB390;
loc_822CB38C:
	// li r11,0
	r11.s64 = 0;
loc_822CB390:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cb3a8
	if (!cr6.eq) goto loc_822CB3A8;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21492(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21492);
	// bl 0x82743e28
	ctx.lr = 0x822CB3A8;
	sub_82743E28(ctx, base);
loc_822CB3A8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a43c8
	ctx.lr = 0x822CB3B4;
	sub_822A43C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-5148(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5148);
	// bl 0x822b7c90
	ctx.lr = 0x822CB3C0;
	sub_822B7C90(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// addi r8,r9,-6420
	ctx.r8.s64 = ctx.r9.s64 + -6420;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cb3e0
	if (!cr6.eq) goto loc_822CB3E0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x8270ae38
	ctx.lr = 0x822CB3E0;
	sub_8270AE38(ctx, base);
loc_822CB3E0:
	// lwz r11,-12640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cb400
	if (cr6.eq) goto loc_822CB400;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822cb404
	if (cr6.eq) goto loc_822CB404;
loc_822CB400:
	// li r11,0
	r11.s64 = 0;
loc_822CB404:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cb424
	if (!cr6.eq) goto loc_822CB424;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CB424;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CB424:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CB43C"))) PPC_WEAK_FUNC(sub_822CB43C);
PPC_FUNC_IMPL(__imp__sub_822CB43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CB440"))) PPC_WEAK_FUNC(sub_822CB440);
PPC_FUNC_IMPL(__imp__sub_822CB440) {
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
	ctx.lr = 0x822CB448;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-8176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8176);
	// bl 0x82375320
	ctx.lr = 0x822CB458;
	sub_82375320(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r3,-8224(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8224);
	// bl 0x82373570
	ctx.lr = 0x822CB464;
	sub_82373570(ctx, base);
	// bl 0x82323b08
	ctx.lr = 0x822CB468;
	sub_82323B08(ctx, base);
	// bl 0x82322e30
	ctx.lr = 0x822CB46C;
	sub_82322E30(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// addi r24,r11,-6420
	r24.s64 = r11.s64 + -6420;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb580
	if (cr6.eq) goto loc_822CB580;
	// bl 0x822a3a48
	ctx.lr = 0x822CB490;
	sub_822A3A48(ctx, base);
	// lwz r3,-5148(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -5148);
	// bl 0x822b78d8
	ctx.lr = 0x822CB498;
	sub_822B78D8(ctx, base);
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cb4ac
	if (!cr6.eq) goto loc_822CB4AC;
	// lwz r3,-10016(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10016);
	// bl 0x82700300
	ctx.lr = 0x822CB4AC;
	sub_82700300(ctx, base);
loc_822CB4AC:
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,72
	r27.s64 = 72;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// li r31,0
	r31.s64 = 0;
	// li r29,8
	r29.s64 = 8;
loc_822CB4C0:
	// lbzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cb4d4
	if (cr6.eq) goto loc_822CB4D4;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x822cb4d8
	goto loc_822CB4D8;
loc_822CB4D4:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_822CB4D8:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822cb580
	if (!cr6.lt) goto loc_822CB580;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cb50c
	if (cr6.eq) goto loc_822CB50C;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822cb530
	if (cr6.lt) goto loc_822CB530;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822cb530
	if (!cr6.lt) goto loc_822CB530;
	// add r11,r29,r3
	r11.u64 = r29.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x822cb528
	goto loc_822CB528;
loc_822CB50C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822cb530
	if (cr6.lt) goto loc_822CB530;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822cb530
	if (!cr6.lt) goto loc_822CB530;
	// lwzx r11,r29,r3
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_822CB528:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822cb534
	if (!cr6.eq) goto loc_822CB534;
loc_822CB530:
	// li r11,0
	r11.s64 = 0;
loc_822CB534:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cb574
	if (cr6.eq) goto loc_822CB574;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x822CB548;
	sub_822A3998(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822cb570
	if (!cr6.eq) goto loc_822CB570;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822CB560;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb570
	if (cr6.eq) goto loc_822CB570;
	// bl 0x823328e0
	ctx.lr = 0x822CB570;
	sub_823328E0(ctx, base);
loc_822CB570:
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
loc_822CB574:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// b 0x822cb4c0
	goto loc_822CB4C0;
loc_822CB580:
	// lwz r11,-5148(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -5148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cb638
	if (cr6.eq) goto loc_822CB638;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,72
	r29.s64 = 72;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
loc_822CB59C:
	// lbzx r9,r29,r28
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + r28.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cb5b0
	if (cr6.eq) goto loc_822CB5B0;
	// lhz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// b 0x822cb5b4
	goto loc_822CB5B4;
loc_822CB5B0:
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
loc_822CB5B4:
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x822cb638
	if (!cr6.lt) goto loc_822CB638;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cb5cc
	if (cr6.eq) goto loc_822CB5CC;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822cb5d0
	goto loc_822CB5D0;
loc_822CB5CC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822CB5D0:
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cb62c
	if (cr6.eq) goto loc_822CB62C;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cb5ec
	if (cr6.eq) goto loc_822CB5EC;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822cb5f0
	goto loc_822CB5F0;
loc_822CB5EC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822CB5F0:
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r10,656(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x822cb62c
	if (!cr6.eq) goto loc_822CB62C;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cb610
	if (cr6.eq) goto loc_822CB610;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822cb614
	goto loc_822CB614;
loc_822CB610:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822CB614:
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb62c
	if (cr6.eq) goto loc_822CB62C;
	// bl 0x823328e0
	ctx.lr = 0x822CB628;
	sub_823328E0(ctx, base);
	// lwz r11,-5148(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -5148);
loc_822CB62C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// b 0x822cb59c
	goto loc_822CB59C;
loc_822CB638:
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cb6b4
	if (!cr6.eq) goto loc_822CB6B4;
	// lwz r3,-10016(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10016);
	// li r31,0
	r31.s64 = 0;
	// bl 0x82701080
	ctx.lr = 0x822CB650;
	sub_82701080(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x822cb6b4
	if (!cr6.gt) goto loc_822CB6B4;
loc_822CB658:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10016);
	// bl 0x827010e8
	ctx.lr = 0x822CB664;
	sub_827010E8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb6a0
	if (cr6.eq) goto loc_822CB6A0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10016);
	// bl 0x827010e8
	ctx.lr = 0x822CB678;
	sub_827010E8(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822cb6a0
	if (!cr6.eq) goto loc_822CB6A0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10016);
	// bl 0x827010e8
	ctx.lr = 0x822CB690;
	sub_827010E8(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb6a0
	if (cr6.eq) goto loc_822CB6A0;
	// bl 0x823328e0
	ctx.lr = 0x822CB6A0;
	sub_823328E0(ctx, base);
loc_822CB6A0:
	// lwz r3,-10016(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10016);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x82701080
	ctx.lr = 0x822CB6AC;
	sub_82701080(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x822cb658
	if (cr6.lt) goto loc_822CB658;
loc_822CB6B4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822CB6BC"))) PPC_WEAK_FUNC(sub_822CB6BC);
PPC_FUNC_IMPL(__imp__sub_822CB6BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CB6C0"))) PPC_WEAK_FUNC(sub_822CB6C0);
PPC_FUNC_IMPL(__imp__sub_822CB6C0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb6e0
	if (cr6.eq) goto loc_822CB6E0;
	// bl 0x822a3aa8
	ctx.lr = 0x822CB6E0;
	sub_822A3AA8(ctx, base);
loc_822CB6E0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-6420
	ctx.r10.s64 = r11.s64 + -6420;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cb700
	if (!cr6.eq) goto loc_822CB700;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x82704130
	ctx.lr = 0x822CB700;
	sub_82704130(ctx, base);
loc_822CB700:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb714
	if (cr6.eq) goto loc_822CB714;
	// bl 0x822b81f8
	ctx.lr = 0x822CB714;
	sub_822B81F8(ctx, base);
loc_822CB714:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb728
	if (cr6.eq) goto loc_822CB728;
	// bl 0x822b6380
	ctx.lr = 0x822CB728;
	sub_822B6380(ctx, base);
loc_822CB728:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CB738"))) PPC_WEAK_FUNC(sub_822CB738);
PPC_FUNC_IMPL(__imp__sub_822CB738) {
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
	ctx.lr = 0x822CB740;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82388580
	ctx.lr = 0x822CB75C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r26,r8,1
	r26.u64 = ctx.r8.u64 ^ 1;
	// bl 0x82388580
	ctx.lr = 0x822CB77C;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r3,1232
	ctx.r3.s64 = 1232;
	// lwz r28,4(r7)
	r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82130528
	ctx.lr = 0x822CB78C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb7a8
	if (cr6.eq) goto loc_822CB7A8;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a6e88
	ctx.lr = 0x822CB7A4;
	sub_822A6E88(ctx, base);
	// b 0x822cb7ac
	goto loc_822CB7AC;
loc_822CB7A8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822CB7AC:
	// stw r3,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x822abd10
	ctx.lr = 0x822CB7BC;
	sub_822ABD10(ctx, base);
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cb7f4
	if (cr6.eq) goto loc_822CB7F4;
	// li r3,156
	ctx.r3.s64 = 156;
	// bl 0x82130528
	ctx.lr = 0x822CB7D0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cb7e4
	if (cr6.eq) goto loc_822CB7E4;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x822b1b58
	ctx.lr = 0x822CB7E0;
	sub_822B1B58(ctx, base);
	// b 0x822cb7e8
	goto loc_822CB7E8;
loc_822CB7E4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822CB7E8:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
	// stw r3,880(r11)
	PPC_STORE_U32(r11.u32 + 880, ctx.r3.u32);
loc_822CB7F4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a4718
	ctx.lr = 0x822CB808;
	sub_822A4718(ctx, base);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CB81C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822cb850
	if (cr6.eq) goto loc_822CB850;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822CB830;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822CB844;
	sub_82270170(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x822a5d20
	ctx.lr = 0x822CB850;
	sub_822A5D20(ctx, base);
loc_822CB850:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822CB858"))) PPC_WEAK_FUNC(sub_822CB858);
PPC_FUNC_IMPL(__imp__sub_822CB858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822CB860;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x822c4eb8
	ctx.lr = 0x822CB87C;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x822CB884;
	sub_822C4EC8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f0,27644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x822cb738
	ctx.lr = 0x822CB8B0;
	sub_822CB738(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822CB8BC"))) PPC_WEAK_FUNC(sub_822CB8BC);
PPC_FUNC_IMPL(__imp__sub_822CB8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CB8C0"))) PPC_WEAK_FUNC(sub_822CB8C0);
PPC_FUNC_IMPL(__imp__sub_822CB8C0) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822CB8C8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x822c4eb8
	ctx.lr = 0x822CB8EC;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x822CB8F4;
	sub_822C4EC8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,1232
	ctx.r3.s64 = 1232;
	// bl 0x82130528
	ctx.lr = 0x822CB900;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// beq cr6,0x822cb91c
	if (cr6.eq) goto loc_822CB91C;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a6e88
	ctx.lr = 0x822CB918;
	sub_822A6E88(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_822CB91C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a4718
	ctx.lr = 0x822CB92C;
	sub_822A4718(ctx, base);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822cadf0
	ctx.lr = 0x822CB94C;
	sub_822CADF0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822CB958"))) PPC_WEAK_FUNC(sub_822CB958);
PPC_FUNC_IMPL(__imp__sub_822CB958) {
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
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822CB970;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822cb9a8
	if (cr6.eq) goto loc_822CB9A8;
	// bl 0x822b80d8
	ctx.lr = 0x822CB980;
	sub_822B80D8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-20428
	ctx.r9.s64 = r11.s64 + -20428;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-5148(r10)
	PPC_STORE_U32(ctx.r10.u32 + -5148, r31.u32);
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
loc_822CB9A8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-5148(r10)
	PPC_STORE_U32(ctx.r10.u32 + -5148, r11.u32);
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

__attribute__((alias("__imp__sub_822CB9C8"))) PPC_WEAK_FUNC(sub_822CB9C8);
PPC_FUNC_IMPL(__imp__sub_822CB9C8) {
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
	// li r3,228
	ctx.r3.s64 = 228;
	// bl 0x82130528
	ctx.lr = 0x822CB9E0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822cba18
	if (cr6.eq) goto loc_822CBA18;
	// bl 0x8270b0f0
	ctx.lr = 0x822CB9F0;
	sub_8270B0F0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-20420
	ctx.r9.s64 = r11.s64 + -20420;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-10016(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10016, r31.u32);
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
loc_822CBA18:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10016(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10016, r11.u32);
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

__attribute__((alias("__imp__sub_822CBA38"))) PPC_WEAK_FUNC(sub_822CBA38);
PPC_FUNC_IMPL(__imp__sub_822CBA38) {
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
	// bl 0x822d2d00
	ctx.lr = 0x822CBA54;
	sub_822D2D00(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-20480
	ctx.r10.s64 = r11.s64 + -20480;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// bl 0x822a4860
	ctx.lr = 0x822CBA78;
	sub_822A4860(ctx, base);
	// bl 0x82262768
	ctx.lr = 0x822CBA7C;
	sub_82262768(ctx, base);
	// bl 0x82253e60
	ctx.lr = 0x822CBA80;
	sub_82253E60(ctx, base);
	// bl 0x826a0860
	ctx.lr = 0x822CBA84;
	sub_826A0860(ctx, base);
	// li r3,604
	ctx.r3.s64 = 604;
	// bl 0x82130528
	ctx.lr = 0x822CBA8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cba9c
	if (cr6.eq) goto loc_822CBA9C;
	// bl 0x82683ca0
	ctx.lr = 0x822CBA98;
	sub_82683CA0(ctx, base);
	// b 0x822cbaa0
	goto loc_822CBAA0;
loc_822CBA9C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822CBAA0:
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// bl 0x822caf38
	ctx.lr = 0x822CBAA8;
	sub_822CAF38(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x822CBAB0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cbac0
	if (cr6.eq) goto loc_822CBAC0;
	// bl 0x82269f88
	ctx.lr = 0x822CBABC;
	sub_82269F88(ctx, base);
	// b 0x822cbac4
	goto loc_822CBAC4;
loc_822CBAC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822CBAC4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CBADC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x822a4a58
	ctx.lr = 0x822CBAE0;
	sub_822A4A58(ctx, base);
	// bl 0x822bedd0
	ctx.lr = 0x822CBAE4;
	sub_822BEDD0(ctx, base);
	// bl 0x822b63e0
	ctx.lr = 0x822CBAE8;
	sub_822B63E0(ctx, base);
	// bl 0x822cb958
	ctx.lr = 0x822CBAEC;
	sub_822CB958(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,-5148(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -5148);
	// bl 0x822b8d70
	ctx.lr = 0x822CBAF8;
	sub_822B8D70(ctx, base);
	// bl 0x827440e8
	ctx.lr = 0x822CBAFC;
	sub_827440E8(ctx, base);
	// bl 0x823915d0
	ctx.lr = 0x822CBB00;
	sub_823915D0(ctx, base);
	// bl 0x82261128
	ctx.lr = 0x822CBB04;
	sub_82261128(ctx, base);
	// bl 0x8270b630
	ctx.lr = 0x822CBB08;
	sub_8270B630(ctx, base);
	// bl 0x822cb9c8
	ctx.lr = 0x822CBB0C;
	sub_822CB9C8(ctx, base);
	// bl 0x8225baa8
	ctx.lr = 0x822CBB10;
	sub_8225BAA8(ctx, base);
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

__attribute__((alias("__imp__sub_822CBB2C"))) PPC_WEAK_FUNC(sub_822CBB2C);
PPC_FUNC_IMPL(__imp__sub_822CBB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CBB30"))) PPC_WEAK_FUNC(sub_822CBB30);
PPC_FUNC_IMPL(__imp__sub_822CBB30) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// li r10,8
	ctx.r10.s64 = 8;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stb r30,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r30.u8);
	// stb r30,52(r31)
	PPC_STORE_U8(r31.u32 + 52, r30.u8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822CBB78:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822cbb78
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822CBB78;
	// li r3,992
	ctx.r3.s64 = 992;
	// bl 0x82130528
	ctx.lr = 0x822CBB8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cbb9c
	if (cr6.eq) goto loc_822CBB9C;
	// bl 0x8217d5e8
	ctx.lr = 0x822CBB98;
	sub_8217D5E8(ctx, base);
	// b 0x822cbba0
	goto loc_822CBBA0;
loc_822CBB9C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822CBBA0:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// bl 0x8217d098
	ctx.lr = 0x822CBBA8;
	sub_8217D098(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-20084
	ctx.r3.s64 = r11.s64 + -20084;
	// bl 0x821c9790
	ctx.lr = 0x822CBBB8;
	sub_821C9790(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// bl 0x8214a200
	ctx.lr = 0x822CBBC8;
	sub_8214A200(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stb r30,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r30.u8);
	// stb r30,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r30.u8);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r31,-27632(r9)
	PPC_STORE_U32(ctx.r9.u32 + -27632, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CBC0C"))) PPC_WEAK_FUNC(sub_822CBC0C);
PPC_FUNC_IMPL(__imp__sub_822CBC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CBC10"))) PPC_WEAK_FUNC(sub_822CBC10);
PPC_FUNC_IMPL(__imp__sub_822CBC10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822cbc70
	if (cr6.eq) goto loc_822CBC70;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r5,r31,64
	ctx.r5.s64 = r31.s64 + 64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cbc54
	if (!cr6.eq) goto loc_822CBC54;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee370
	ctx.lr = 0x822CBC54;
	sub_821EE370(ctx, base);
loc_822CBC54:
	// li r11,0
	r11.s64 = 0;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
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
loc_822CBC70:
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cbc98
	if (cr6.eq) goto loc_822CBC98;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cbc90
	if (cr6.eq) goto loc_822CBC90;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x822CBC90;
	sub_821EC060(ctx, base);
loc_822CBC90:
	// li r11,0
	r11.s64 = 0;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
loc_822CBC98:
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

__attribute__((alias("__imp__sub_822CBCAC"))) PPC_WEAK_FUNC(sub_822CBCAC);
PPC_FUNC_IMPL(__imp__sub_822CBCAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CBCB0"))) PPC_WEAK_FUNC(sub_822CBCB0);
PPC_FUNC_IMPL(__imp__sub_822CBCB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cbd70
	if (cr6.eq) goto loc_822CBD70;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822cbd08
	if (cr6.eq) goto loc_822CBD08;
	// lhz r11,82(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r8,r10
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	f31.f64 = double(temp.f32);
loc_822CBD08:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cbd38
	if (cr6.eq) goto loc_822CBD38;
	// lhz r11,14(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f31,f11,f0,f31
	f31.f64 = double(float(ctx.f11.f64 * f0.f64 + f31.f64));
loc_822CBD38:
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cbd64
	if (cr6.eq) goto loc_822CBD64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a30
	ctx.lr = 0x822CBD50;
	sub_82144A30(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cbd64
	if (cr6.eq) goto loc_822CBD64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f31,-20072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20072);
	f31.f64 = double(temp.f32);
loc_822CBD64:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82468ba8
	ctx.lr = 0x822CBD70;
	sub_82468BA8(ctx, base);
loc_822CBD70:
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

__attribute__((alias("__imp__sub_822CBD88"))) PPC_WEAK_FUNC(sub_822CBD88);
PPC_FUNC_IMPL(__imp__sub_822CBD88) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-20052
	ctx.r3.s64 = r11.s64 + -20052;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130000
	ctx.lr = 0x822CBDB0;
	sub_82130000(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// bl 0x82144a50
	ctx.lr = 0x822CBDBC;
	sub_82144A50(ctx, base);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r9,72(r31)
	PPC_STORE_U8(r31.u32 + 72, ctx.r9.u8);
	// beq cr6,0x822cbe14
	if (cr6.eq) goto loc_822CBE14;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cbdf8
	if (cr6.eq) goto loc_822CBDF8;
	// bl 0x824687b0
	ctx.lr = 0x822CBDE8;
	sub_824687B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x821bc848
	ctx.lr = 0x822CBDF8;
	sub_821BC848(ctx, base);
loc_822CBDF8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// bl 0x821c31b8
	ctx.lr = 0x822CBE08;
	sub_821C31B8(ctx, base);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// b 0x822cbe18
	goto loc_822CBE18;
loc_822CBE14:
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
loc_822CBE18:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CBE30"))) PPC_WEAK_FUNC(sub_822CBE30);
PPC_FUNC_IMPL(__imp__sub_822CBE30) {
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
	ctx.lr = 0x822CBE38;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r11,-27632(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27632, r11.u32);
	// bl 0x822cbd88
	ctx.lr = 0x822CBE54;
	sub_822CBD88(ctx, base);
	// lwz r29,4(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822cbe74
	if (cr6.eq) goto loc_822CBE74;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82469580
	ctx.lr = 0x822CBE68;
	sub_82469580(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822CBE70;
	sub_82130588(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_822CBE74:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cbe88
	if (cr6.eq) goto loc_822CBE88;
	// bl 0x821be610
	ctx.lr = 0x822CBE84;
	sub_821BE610(ctx, base);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_822CBE88:
	// lwz r29,16(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822cbea4
	if (cr6.eq) goto loc_822CBEA4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217cb48
	ctx.lr = 0x822CBE9C;
	sub_8217CB48(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822CBEA4;
	sub_82130588(ctx, base);
loc_822CBEA4:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cbeb8
	if (cr6.eq) goto loc_822CBEB8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821ec060
	ctx.lr = 0x822CBEB8;
	sub_821EC060(ctx, base);
loc_822CBEB8:
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// lis r29,-32121
	r29.s64 = -2105081856;
loc_822CBEC0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cbedc
	if (cr6.eq) goto loc_822CBEDC;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x822CBEDC;
	sub_82213650(ctx, base);
loc_822CBEDC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x822cbec0
	if (cr6.lt) goto loc_822CBEC0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822CBEF4"))) PPC_WEAK_FUNC(sub_822CBEF4);
PPC_FUNC_IMPL(__imp__sub_822CBEF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CBEF8"))) PPC_WEAK_FUNC(sub_822CBEF8);
PPC_FUNC_IMPL(__imp__sub_822CBEF8) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x822CBF00;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r10,-19724
	ctx.r4.s64 = ctx.r10.s64 + -19724;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// bl 0x823d90b0
	ctx.lr = 0x822CBF28;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cbf44
	if (cr6.eq) goto loc_822CBF44;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822CBF40;
	sub_82137A08(ctx, base);
	// b 0x822cbfb8
	goto loc_822CBFB8;
loc_822CBF44:
	// bl 0x82178848
	ctx.lr = 0x822CBF48;
	sub_82178848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cbf98
	if (cr6.eq) goto loc_822CBF98;
	// bl 0x82178880
	ctx.lr = 0x822CBF58;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// beq cr6,0x822cbf80
	if (cr6.eq) goto loc_822CBF80;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,-19736
	ctx.r5.s64 = r11.s64 + -19736;
	// bl 0x82137a08
	ctx.lr = 0x822CBF7C;
	sub_82137A08(ctx, base);
	// b 0x822cbfb8
	goto loc_822CBFB8;
loc_822CBF80:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,-19752
	ctx.r5.s64 = r11.s64 + -19752;
	// bl 0x82137a08
	ctx.lr = 0x822CBF8C;
	sub_82137A08(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r29,r11,-19764
	r29.s64 = r11.s64 + -19764;
	// b 0x822cbfb8
	goto loc_822CBFB8;
loc_822CBF98:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,-19780
	ctx.r5.s64 = r11.s64 + -19780;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822CBFB0;
	sub_82137A08(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r29,r11,-19792
	r29.s64 = r11.s64 + -19792;
loc_822CBFB8:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r11,-19808
	ctx.r3.s64 = r11.s64 + -19808;
	// bl 0x82130000
	ctx.lr = 0x822CBFC8;
	sub_82130000(ctx, base);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cbfe0
	if (cr6.eq) goto loc_822CBFE0;
loc_822CBFD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9230
	return;
loc_822CBFE0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-19812
	ctx.r5.s64 = r11.s64 + -19812;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x821ca6a8
	ctx.lr = 0x822CC000;
	sub_821CA6A8(ctx, base);
	// stw r3,8(r27)
	PPC_STORE_U32(r27.u32 + 8, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cbfd4
	if (cr6.eq) goto loc_822CBFD4;
	// bl 0x821c31c8
	ctx.lr = 0x822CC010;
	sub_821C31C8(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-19832
	ctx.r5.s64 = r11.s64 + -19832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213058
	ctx.lr = 0x822CC030;
	sub_82213058(ctx, base);
	// stw r3,20(r27)
	PPC_STORE_U32(r27.u32 + 20, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r5,r10,-19852
	ctx.r5.s64 = ctx.r10.s64 + -19852;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82213058
	ctx.lr = 0x822CC050;
	sub_82213058(ctx, base);
	// stw r3,24(r27)
	PPC_STORE_U32(r27.u32 + 24, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r5,r9,-19872
	ctx.r5.s64 = ctx.r9.s64 + -19872;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82213058
	ctx.lr = 0x822CC070;
	sub_82213058(ctx, base);
	// stw r3,28(r27)
	PPC_STORE_U32(r27.u32 + 28, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r5,r8,-19892
	ctx.r5.s64 = ctx.r8.s64 + -19892;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82213058
	ctx.lr = 0x822CC090;
	sub_82213058(ctx, base);
	// stw r3,32(r27)
	PPC_STORE_U32(r27.u32 + 32, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r5,r7,-19912
	ctx.r5.s64 = ctx.r7.s64 + -19912;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82213058
	ctx.lr = 0x822CC0B0;
	sub_82213058(ctx, base);
	// stw r3,36(r27)
	PPC_STORE_U32(r27.u32 + 36, ctx.r3.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r5,r5,-19932
	ctx.r5.s64 = ctx.r5.s64 + -19932;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82213058
	ctx.lr = 0x822CC0D0;
	sub_82213058(ctx, base);
	// stw r3,40(r27)
	PPC_STORE_U32(r27.u32 + 40, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r5,r4,-19952
	ctx.r5.s64 = ctx.r4.s64 + -19952;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x82213058
	ctx.lr = 0x822CC0F0;
	sub_82213058(ctx, base);
	// stw r3,44(r27)
	PPC_STORE_U32(r27.u32 + 44, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r5,r10,-19972
	ctx.r5.s64 = ctx.r10.s64 + -19972;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x82213058
	ctx.lr = 0x822CC110;
	sub_82213058(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r3,48(r27)
	PPC_STORE_U32(r27.u32 + 48, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// addi r26,r11,-19984
	r26.s64 = r11.s64 + -19984;
	// addi r25,r10,-19996
	r25.s64 = ctx.r10.s64 + -19996;
	// addi r24,r9,-20008
	r24.s64 = ctx.r9.s64 + -20008;
	// addi r23,r8,-20020
	r23.s64 = ctx.r8.s64 + -20020;
loc_822CC13C:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822CC154;
	sub_82137A08(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x822CC168;
	sub_82213B80(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// bl 0x82137a08
	ctx.lr = 0x822CC184;
	sub_82137A08(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x822CC198;
	sub_82213B80(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// bl 0x82137a08
	ctx.lr = 0x822CC1B4;
	sub_82137A08(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x822CC1C8;
	sub_82213B80(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// bl 0x82137a08
	ctx.lr = 0x822CC1E4;
	sub_82137A08(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x822CC1F8;
	sub_82213B80(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// blt cr6,0x822cc13c
	if (cr6.lt) goto loc_822CC13C;
	// li r11,1
	r11.s64 = 1;
	// stb r22,53(r27)
	PPC_STORE_U8(r27.u32 + 53, r22.u8);
	// li r4,47
	ctx.r4.s64 = 47;
	// stb r11,52(r27)
	PPC_STORE_U8(r27.u32 + 52, r11.u8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823db6d0
	ctx.lr = 0x822CC220;
	sub_823DB6D0(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// beq cr6,0x822cc2b0
	if (cr6.eq) goto loc_822CC2B0;
	// lbz r11,1(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// addi r6,r3,1
	ctx.r6.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc2b0
	if (cr6.eq) goto loc_822CC2B0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,-20028
	ctx.r5.s64 = r11.s64 + -20028;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82137a08
	ctx.lr = 0x822CC254;
	sub_82137A08(ctx, base);
	// lbz r9,245(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 245);
	// addi r10,r1,245
	ctx.r10.s64 = ctx.r1.s64 + 245;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cc2a0
	if (cr6.eq) goto loc_822CC2A0;
loc_822CC264:
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,48
	cr6.compare<int32_t>(r11.s32, 48, xer);
	// blt cr6,0x822cc27c
	if (cr6.lt) goto loc_822CC27C;
	// cmpwi cr6,r11,57
	cr6.compare<int32_t>(r11.s32, 57, xer);
	// ble cr6,0x822cc298
	if (!cr6.gt) goto loc_822CC298;
loc_822CC27C:
	// cmpwi cr6,r11,46
	cr6.compare<int32_t>(r11.s32, 46, xer);
	// beq cr6,0x822cc298
	if (cr6.eq) goto loc_822CC298;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cc264
	if (!cr6.eq) goto loc_822CC264;
	// b 0x822cc2a0
	goto loc_822CC2A0;
loc_822CC298:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
loc_822CC2A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// bl 0x82144a20
	ctx.lr = 0x822CC2AC;
	sub_82144A20(ctx, base);
	// stw r3,60(r27)
	PPC_STORE_U32(r27.u32 + 60, ctx.r3.u32);
loc_822CC2B0:
	// lwz r11,60(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc2d8
	if (cr6.eq) goto loc_822CC2D8;
	// lbz r10,53(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 53);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822cc2d8
	if (!cr6.eq) goto loc_822CC2D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// bl 0x82144a28
	ctx.lr = 0x822CC2D4;
	sub_82144A28(ctx, base);
	// stw r3,68(r27)
	PPC_STORE_U32(r27.u32 + 68, ctx.r3.u32);
loc_822CC2D8:
	// li r11,2
	r11.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,76(r27)
	PPC_STORE_U32(r27.u32 + 76, r11.u32);
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_822CC2EC"))) PPC_WEAK_FUNC(sub_822CC2EC);
PPC_FUNC_IMPL(__imp__sub_822CC2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CC2F0"))) PPC_WEAK_FUNC(sub_822CC2F0);
PPC_FUNC_IMPL(__imp__sub_822CC2F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-19656
	ctx.r3.s64 = r11.s64 + -19656;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x822CC31C;
	sub_82130000(ctx, base);
	// bl 0x821bc858
	ctx.lr = 0x822CC320;
	sub_821BC858(ctx, base);
	// bl 0x82469658
	ctx.lr = 0x822CC324;
	sub_82469658(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r5,16
	ctx.r5.s64 = 1048576;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82468c28
	ctx.lr = 0x822CC334;
	sub_82468C28(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8217d098
	ctx.lr = 0x822CC33C;
	sub_8217D098(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lbz r9,2156(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2156);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cc408
	if (cr6.eq) goto loc_822CC408;
	// bl 0x821789d8
	ctx.lr = 0x822CC350;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc368
	if (cr6.eq) goto loc_822CC368;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x822cc370
	goto loc_822CC370;
loc_822CC368:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_822CC370:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f31,f13
	f31.f64 = double(float(ctx.f13.f64));
	// bl 0x821789d8
	ctx.lr = 0x822CC388;
	sub_821789D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cc3a0
	if (cr6.eq) goto loc_822CC3A0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x822cc3a8
	goto loc_822CC3A8;
loc_822CC3A0:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_822CC3A8:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// stfs f31,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f31,208(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f0,152(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stfs f0,212(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,216(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// b 0x822cc478
	goto loc_822CC478;
loc_822CC408:
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r30,-32253
	r30.s64 = -2113732608;
	// lfs f10,-19660(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19660);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,-19664(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19664);
	f0.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f13,-31640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31640);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f12,-19668(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19668);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lfs f11,-19672(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -19672);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lfs f9,-3172(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -3172);
	ctx.f9.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f9,164(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f11,192(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f9,196(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f10,200(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
loc_822CC478:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82468738
	ctx.lr = 0x822CC480;
	sub_82468738(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r9,53(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// li r8,112
	ctx.r8.s64 = 112;
	// addi r7,r11,-32240
	ctx.r7.s64 = r11.s64 + -32240;
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r9,102(r10)
	PPC_STORE_U8(ctx.r10.u32 + 102, ctx.r9.u8);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stvx128 v63,r5,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r6,73(r31)
	PPC_STORE_U8(r31.u32 + 73, ctx.r6.u8);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc4e8
	if (cr6.eq) goto loc_822CC4E8;
	// lwz r11,5(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822cc4d8
	if (!cr6.eq) goto loc_822CC4D8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a40
	ctx.lr = 0x822CC4D4;
	sub_82144A40(ctx, base);
	// b 0x822cc4e8
	goto loc_822CC4E8;
loc_822CC4D8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822cc4e8
	if (!cr6.eq) goto loc_822CC4E8;
	// li r11,1
	r11.s64 = 1;
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
loc_822CC4E8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822cbcb0
	ctx.lr = 0x822CC4F0;
	sub_822CBCB0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82468770
	ctx.lr = 0x822CC4F8;
	sub_82468770(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82468800
	ctx.lr = 0x822CC500;
	sub_82468800(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,-25448
	ctx.r4.s64 = r11.s64 + -25448;
	// bl 0x823d90b0
	ctx.lr = 0x822CC510;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cc56c
	if (cr6.eq) goto loc_822CC56C;
	// bl 0x82178880
	ctx.lr = 0x822CC51C;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc534
	if (cr6.eq) goto loc_822CC534;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,-19684
	ctx.r5.s64 = r11.s64 + -19684;
	// b 0x822cc53c
	goto loc_822CC53C;
loc_822CC534:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,-19700
	ctx.r5.s64 = r11.s64 + -19700;
loc_822CC53C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r6,r11,-19716
	ctx.r6.s64 = r11.s64 + -19716;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82137a08
	ctx.lr = 0x822CC550;
	sub_82137A08(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// addi r4,r10,-25460
	ctx.r4.s64 = ctx.r10.s64 + -25460;
	// bl 0x821f97f0
	ctx.lr = 0x822CC560;
	sub_821F97F0(ctx, base);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r9.u32);
	// b 0x822cc574
	goto loc_822CC574;
loc_822CC56C:
	// li r11,3
	r11.s64 = 3;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
loc_822CC574:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
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

__attribute__((alias("__imp__sub_822CC590"))) PPC_WEAK_FUNC(sub_822CC590);
PPC_FUNC_IMPL(__imp__sub_822CC590) {
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
	// bl 0x822cbc10
	ctx.lr = 0x822CC5A8;
	sub_822CBC10(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822cc5c4
	if (!cr6.eq) goto loc_822CC5C4;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x822cc5c4
	if (cr6.eq) goto loc_822CC5C4;
	// bl 0x821f97d0
	ctx.lr = 0x822CC5C4;
	sub_821F97D0(ctx, base);
loc_822CC5C4:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
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

__attribute__((alias("__imp__sub_822CC5E0"))) PPC_WEAK_FUNC(sub_822CC5E0);
PPC_FUNC_IMPL(__imp__sub_822CC5E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822CC5E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822cc628
	if (!cr6.eq) goto loc_822CC628;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822cc628
	if (cr6.eq) goto loc_822CC628;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822cc61c
	if (!cr6.eq) goto loc_822CC61C;
	// stw r11,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r11.u32);
	// b 0x822cc624
	goto loc_822CC624;
loc_822CC61C:
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x822cc628
	if (!cr6.eq) goto loc_822CC628;
loc_822CC624:
	// stw r27,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r27.u32);
loc_822CC628:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x822cc7f4
	if (cr6.gt) goto loc_822CC7F4;
	// lis r12,-32211
	r12.s64 = -2110980096;
	// addi r12,r12,-14768
	r12.s64 = r12.s64 + -14768;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822CC7BC;
	case 1:
		goto loc_822CC6FC;
	case 2:
		goto loc_822CC76C;
	case 3:
		goto loc_822CC664;
	case 4:
		goto loc_822CC7EC;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-14404(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + -14404);
	// lwz r17,-14596(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + -14596);
	// lwz r17,-14484(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + -14484);
	// lwz r17,-14748(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + -14748);
	// lwz r17,-14356(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + -14356);
loc_822CC664:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc6e8
	if (cr6.eq) goto loc_822CC6E8;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822cc6a8
	if (cr6.eq) goto loc_822CC6A8;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-19580
	ctx.r3.s64 = r11.s64 + -19580;
	// bl 0x82130000
	ctx.lr = 0x822CC688;
	sub_82130000(ctx, base);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822cc6a4
	if (cr6.eq) goto loc_822CC6A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82469580
	ctx.lr = 0x822CC69C;
	sub_82469580(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822CC6A4;
	sub_82130588(ctx, base);
loc_822CC6A4:
	// stw r27,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r27.u32);
loc_822CC6A8:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x821be610
	ctx.lr = 0x822CC6B0;
	sub_821BE610(ctx, base);
	// mr r31,r27
	r31.u64 = r27.u64;
	// stw r27,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r27.u32);
	// addi r29,r30,20
	r29.s64 = r30.s64 + 20;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_822CC6C0:
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x822CC6D0;
	sub_82213650(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// blt cr6,0x822cc6c0
	if (cr6.lt) goto loc_822CC6C0;
	// stb r27,52(r30)
	PPC_STORE_U8(r30.u32 + 52, r27.u8);
loc_822CC6E8:
	// stw r27,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbcb0
	ctx.lr = 0x822CC6F4;
	sub_822CBCB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822CC6FC:
	// lbz r11,52(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc7f4
	if (cr6.eq) goto loc_822CC7F4;
	// mr r31,r27
	r31.u64 = r27.u64;
	// addi r29,r30,20
	r29.s64 = r30.s64 + 20;
loc_822CC710:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CC724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cc758
	if (cr6.eq) goto loc_822CC758;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// blt cr6,0x822cc710
	if (cr6.lt) goto loc_822CC710;
	// stb r27,52(r30)
	PPC_STORE_U8(r30.u32 + 52, r27.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cc2f0
	ctx.lr = 0x822CC748;
	sub_822CC2F0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbcb0
	ctx.lr = 0x822CC750;
	sub_822CBCB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822CC758:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-19624
	ctx.r3.s64 = r11.s64 + -19624;
	// bl 0x82130000
	ctx.lr = 0x822CC764;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822CC76C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cc7f4
	if (cr6.eq) goto loc_822CC7F4;
	// bl 0x82468800
	ctx.lr = 0x822CC77C;
	sub_82468800(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc79c
	if (cr6.eq) goto loc_822CC79C;
	// lbz r11,101(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 101);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cc79c
	if (!cr6.eq) goto loc_822CC79C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbd88
	ctx.lr = 0x822CC79C;
	sub_822CBD88(ctx, base);
loc_822CC79C:
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x822cc7f4
	if (!cr6.eq) goto loc_822CC7F4;
	// stw r11,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbcb0
	ctx.lr = 0x822CC7B4;
	sub_822CBCB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822CC7BC:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,88
	ctx.r4.s64 = r30.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbef8
	ctx.lr = 0x822CC7CC;
	sub_822CBEF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cc7f4
	if (!cr6.eq) goto loc_822CC7F4;
	// stw r27,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbcb0
	ctx.lr = 0x822CC7E4;
	sub_822CBCB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822CC7EC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbd88
	ctx.lr = 0x822CC7F4;
	sub_822CBD88(ctx, base);
loc_822CC7F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbcb0
	ctx.lr = 0x822CC7FC;
	sub_822CBCB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822CC804"))) PPC_WEAK_FUNC(sub_822CC804);
PPC_FUNC_IMPL(__imp__sub_822CC804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CC808"))) PPC_WEAK_FUNC(sub_822CC808);
PPC_FUNC_IMPL(__imp__sub_822CC808) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-20068
	ctx.r3.s64 = ctx.r10.s64 + -20068;
	// lwz r31,-27632(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -27632);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130000
	ctx.lr = 0x822CC830;
	sub_82130000(ctx, base);
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// bl 0x821f97e0
	ctx.lr = 0x822CC83C;
	sub_821F97E0(ctx, base);
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

__attribute__((alias("__imp__sub_822CC850"))) PPC_WEAK_FUNC(sub_822CC850);
PPC_FUNC_IMPL(__imp__sub_822CC850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-27632(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27632);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CC878"))) PPC_WEAK_FUNC(sub_822CC878);
PPC_FUNC_IMPL(__imp__sub_822CC878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,-27632(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27632);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// li r8,112
	ctx.r8.s64 = 112;
	// lfs f11,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f11,-4(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CC8C4"))) PPC_WEAK_FUNC(sub_822CC8C4);
PPC_FUNC_IMPL(__imp__sub_822CC8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CC8C8"))) PPC_WEAK_FUNC(sub_822CC8C8);
PPC_FUNC_IMPL(__imp__sub_822CC8C8) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822CC8D0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ccb90
	if (cr6.eq) goto loc_822CCB90;
	// bl 0x821789d8
	ctx.lr = 0x822CC8EC;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cc904
	if (cr6.eq) goto loc_822CC904;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x822cc90c
	goto loc_822CC90C;
loc_822CC904:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_822CC90C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f31,f13
	f31.f64 = double(float(ctx.f13.f64));
	// bl 0x821789d8
	ctx.lr = 0x822CC924;
	sub_821789D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cc93c
	if (cr6.eq) goto loc_822CC93C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r8,17008(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x822cc944
	goto loc_822CC944;
loc_822CC93C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r8,17016(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_822CC944:
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// lwz r10,-26876(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r29,r1,256
	r29.s64 = ctx.r1.s64 + 256;
	// lbz r9,2156(r6)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + 2156);
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// li r27,48
	r27.s64 = 48;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822cca40
	if (cr6.eq) goto loc_822CCA40;
	// extsw r9,r8
	ctx.r9.s64 = ctx.r8.s32;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f5,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// lfs f6,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f6.f64 = double(temp.f32);
	// frsp f3,f13
	ctx.f3.f64 = double(float(ctx.f13.f64));
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// fmr f1,f5
	ctx.f1.f64 = ctx.f5.f64;
	// bl 0x8217cc80
	ctx.lr = 0x822CC9DC;
	sub_8217CC80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x8217c658
	ctx.lr = 0x822CC9E8;
	sub_8217C658(ctx, base);
	// bl 0x8217d900
	ctx.lr = 0x822CC9EC;
	sub_8217D900(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r6,16
	ctx.r6.s64 = 16;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// addi r5,r7,-31280
	ctx.r5.s64 = ctx.r7.s64 + -31280;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lvx128 v61,r5,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r5,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lvx128 v60,r5,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x822CCA3C;
	sub_8217CE80(ctx, base);
	// b 0x822cca44
	goto loc_822CCA44;
loc_822CCA40:
	// bl 0x8217d900
	ctx.lr = 0x822CCA44;
	sub_8217D900(ctx, base);
loc_822CCA44:
	// li r11,11
	r11.s64 = 11;
	// li r3,11
	ctx.r3.s64 = 11;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822CCA54;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,11
	ctx.r3.s64 = 11;
	// std r10,100(r1)
	PPC_STORE_U64(ctx.r1.u32 + 100, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x822CCA6C;
	sub_8217F768(ctx, base);
	// li r9,6
	ctx.r9.s64 = 6;
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822CCA7C;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,6
	ctx.r3.s64 = 6;
	// std r8,108(r1)
	PPC_STORE_U64(ctx.r1.u32 + 108, ctx.r8.u64);
	// bl 0x8217f768
	ctx.lr = 0x822CCA94;
	sub_8217F768(ctx, base);
	// li r7,8
	ctx.r7.s64 = 8;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822CCAA4;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,8
	ctx.r3.s64 = 8;
	// std r6,116(r1)
	PPC_STORE_U64(ctx.r1.u32 + 116, ctx.r6.u64);
	// bl 0x8217f768
	ctx.lr = 0x822CCABC;
	sub_8217F768(ctx, base);
	// li r29,7
	r29.s64 = 7;
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822CCACC;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,7
	ctx.r3.s64 = 7;
	// std r5,124(r1)
	PPC_STORE_U64(ctx.r1.u32 + 124, ctx.r5.u64);
	// bl 0x8217f768
	ctx.lr = 0x822CCAE4;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822CCAF4;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// std r11,132(r1)
	PPC_STORE_U64(ctx.r1.u32 + 132, r11.u64);
	// bl 0x8217f768
	ctx.lr = 0x822CCB0C;
	sub_8217F768(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822CCB1C;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// std r9,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r9.u64);
	// bl 0x8217f768
	ctx.lr = 0x822CCB34;
	sub_8217F768(ctx, base);
	// li r8,2
	ctx.r8.s64 = 2;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822CCB44;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,2
	ctx.r3.s64 = 2;
	// std r7,148(r1)
	PPC_STORE_U64(ctx.r1.u32 + 148, ctx.r7.u64);
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// bl 0x8217f768
	ctx.lr = 0x822CCB60;
	sub_8217F768(ctx, base);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82468978
	ctx.lr = 0x822CCB68;
	sub_82468978(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ccb7c
	if (cr6.eq) goto loc_822CCB7C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c658
	ctx.lr = 0x822CCB7C;
	sub_8217C658(ctx, base);
loc_822CCB7C:
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// bl 0x8217ce80
	ctx.lr = 0x822CCB88;
	sub_8217CE80(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82491668
	ctx.lr = 0x822CCB90;
	sub_82491668(ctx, base);
loc_822CCB90:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822CCB9C"))) PPC_WEAK_FUNC(sub_822CCB9C);
PPC_FUNC_IMPL(__imp__sub_822CCB9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CCBA0"))) PPC_WEAK_FUNC(sub_822CCBA0);
PPC_FUNC_IMPL(__imp__sub_822CCBA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r31,-27632(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -27632);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x82137a08
	ctx.lr = 0x822CCBD4;
	sub_82137A08(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CCBFC"))) PPC_WEAK_FUNC(sub_822CCBFC);
PPC_FUNC_IMPL(__imp__sub_822CCBFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CCC00"))) PPC_WEAK_FUNC(sub_822CCC00);
PPC_FUNC_IMPL(__imp__sub_822CCC00) {
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
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-13408
	ctx.r4.s64 = r11.s64 + -13408;
	// addi r3,r10,-19480
	ctx.r3.s64 = ctx.r10.s64 + -19480;
	// bl 0x82554798
	ctx.lr = 0x822CCC20;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-14328
	ctx.r4.s64 = ctx.r9.s64 + -14328;
	// addi r3,r8,-19504
	ctx.r3.s64 = ctx.r8.s64 + -19504;
	// bl 0x82554798
	ctx.lr = 0x822CCC34;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-14256
	ctx.r4.s64 = ctx.r7.s64 + -14256;
	// addi r3,r6,-19532
	ctx.r3.s64 = ctx.r6.s64 + -19532;
	// bl 0x82554798
	ctx.lr = 0x822CCC48;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-14216
	ctx.r4.s64 = ctx.r5.s64 + -14216;
	// addi r3,r3,-19560
	ctx.r3.s64 = ctx.r3.s64 + -19560;
	// bl 0x82554798
	ctx.lr = 0x822CCC5C;
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

__attribute__((alias("__imp__sub_822CCC6C"))) PPC_WEAK_FUNC(sub_822CCC6C);
PPC_FUNC_IMPL(__imp__sub_822CCC6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CCC70"))) PPC_WEAK_FUNC(sub_822CCC70);
PPC_FUNC_IMPL(__imp__sub_822CCC70) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ccca4
	if (cr6.eq) goto loc_822CCCA4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CCCA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCCA4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12440(r31)
	PPC_STORE_U32(r31.u32 + -12440, r11.u32);
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

__attribute__((alias("__imp__sub_822CCCC0"))) PPC_WEAK_FUNC(sub_822CCCC0);
PPC_FUNC_IMPL(__imp__sub_822CCCC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,16908
	r11.s64 = 16908;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// b 0x8238d3f8
	sub_8238D3F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CCCCC"))) PPC_WEAK_FUNC(sub_822CCCCC);
PPC_FUNC_IMPL(__imp__sub_822CCCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CCCD0"))) PPC_WEAK_FUNC(sub_822CCCD0);
PPC_FUNC_IMPL(__imp__sub_822CCCD0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822CCCD8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-18788
	ctx.r4.s64 = ctx.r9.s64 + -18788;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,-12440(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12440);
	// lwz r8,80(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CCD08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f31,27636(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27636);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// blt cr6,0x822ccd3c
	if (cr6.lt) goto loc_822CCD3C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18796
	ctx.r4.s64 = ctx.r10.s64 + -18796;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCD3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCD3C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,-18804
	r29.s64 = r11.s64 + -18804;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCD60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,30
	cr6.compare<int32_t>(ctx.r3.s32, 30, xer);
	// blt cr6,0x822ccd8c
	if (cr6.lt) goto loc_822CCD8C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18812
	ctx.r4.s64 = ctx.r10.s64 + -18812;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCD8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCD8C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CCDA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,60
	cr6.compare<int32_t>(ctx.r3.s32, 60, xer);
	// bne cr6,0x822ccdd4
	if (!cr6.eq) goto loc_822CCDD4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18820
	ctx.r4.s64 = ctx.r10.s64 + -18820;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCDD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCDD4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18828
	ctx.r4.s64 = ctx.r10.s64 + -18828;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCDF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,15
	cr6.compare<int32_t>(ctx.r3.s32, 15, xer);
	// bne cr6,0x822cce20
	if (!cr6.eq) goto loc_822CCE20;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18836
	ctx.r4.s64 = ctx.r10.s64 + -18836;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCE20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCE20:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18844
	ctx.r4.s64 = ctx.r10.s64 + -18844;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCE40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,15
	cr6.compare<int32_t>(ctx.r3.s32, 15, xer);
	// bne cr6,0x822cce6c
	if (!cr6.eq) goto loc_822CCE6C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18852
	ctx.r4.s64 = ctx.r10.s64 + -18852;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCE6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCE6C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18860
	ctx.r4.s64 = ctx.r10.s64 + -18860;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCE8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,180
	cr6.compare<int32_t>(ctx.r3.s32, 180, xer);
	// bne cr6,0x822cceb8
	if (!cr6.eq) goto loc_822CCEB8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18868
	ctx.r4.s64 = ctx.r10.s64 + -18868;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCEB8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18876
	ctx.r4.s64 = ctx.r10.s64 + -18876;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,300
	cr6.compare<int32_t>(ctx.r3.s32, 300, xer);
	// bne cr6,0x822ccf04
	if (!cr6.eq) goto loc_822CCF04;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18884
	ctx.r4.s64 = ctx.r10.s64 + -18884;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCF04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCF04:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18892
	ctx.r4.s64 = ctx.r10.s64 + -18892;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCF24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// blt cr6,0x822ccf50
	if (cr6.lt) goto loc_822CCF50;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18900
	ctx.r4.s64 = ctx.r10.s64 + -18900;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCF50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCF50:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18908
	ctx.r4.s64 = ctx.r10.s64 + -18908;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCF70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// blt cr6,0x822ccf9c
	if (cr6.lt) goto loc_822CCF9C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18916
	ctx.r4.s64 = ctx.r10.s64 + -18916;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCF9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCF9C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,23008
	ctx.r4.s64 = ctx.r10.s64 + 23008;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCFBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,-18920(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x822ccff0
	if (cr6.lt) goto loc_822CCFF0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18928
	ctx.r4.s64 = ctx.r10.s64 + -18928;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CCFF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CCFF0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18936
	ctx.r4.s64 = ctx.r10.s64 + -18936;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,-18940(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18940);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x822cd044
	if (cr6.lt) goto loc_822CD044;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18948
	ctx.r4.s64 = ctx.r10.s64 + -18948;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD044;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD044:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18956
	ctx.r4.s64 = ctx.r10.s64 + -18956;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lfs f0,-1760(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -1760);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x822cd098
	if (cr6.lt) goto loc_822CD098;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18964
	ctx.r4.s64 = ctx.r10.s64 + -18964;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD098;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD098:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18972
	ctx.r4.s64 = ctx.r10.s64 + -18972;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD0B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// blt cr6,0x822cd0e4
	if (cr6.lt) goto loc_822CD0E4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18980
	ctx.r4.s64 = ctx.r10.s64 + -18980;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD0E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD0E4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18988
	ctx.r4.s64 = ctx.r10.s64 + -18988;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,15
	cr6.compare<int32_t>(ctx.r3.s32, 15, xer);
	// blt cr6,0x822cd130
	if (cr6.lt) goto loc_822CD130;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18996
	ctx.r4.s64 = ctx.r10.s64 + -18996;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD130;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD130:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-19004
	ctx.r4.s64 = ctx.r10.s64 + -19004;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,100
	cr6.compare<int32_t>(ctx.r3.s32, 100, xer);
	// blt cr6,0x822cd17c
	if (cr6.lt) goto loc_822CD17C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19012
	ctx.r4.s64 = ctx.r10.s64 + -19012;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD17C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD17C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-19020
	ctx.r4.s64 = ctx.r10.s64 + -19020;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD19C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,80
	cr6.compare<int32_t>(ctx.r3.s32, 80, xer);
	// blt cr6,0x822cd1c8
	if (cr6.lt) goto loc_822CD1C8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19028
	ctx.r4.s64 = ctx.r10.s64 + -19028;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD1C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD1C8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-19036
	ctx.r4.s64 = ctx.r10.s64 + -19036;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD1E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,50
	cr6.compare<int32_t>(ctx.r3.s32, 50, xer);
	// blt cr6,0x822cd214
	if (cr6.lt) goto loc_822CD214;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19044
	ctx.r4.s64 = ctx.r10.s64 + -19044;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD214:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,18668
	ctx.r4.s64 = ctx.r10.s64 + 18668;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD234;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,20
	cr6.compare<int32_t>(ctx.r3.s32, 20, xer);
	// blt cr6,0x822cd260
	if (cr6.lt) goto loc_822CD260;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19052
	ctx.r4.s64 = ctx.r10.s64 + -19052;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD260;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD260:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-19060
	ctx.r4.s64 = ctx.r10.s64 + -19060;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD280;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,25
	cr6.compare<int32_t>(ctx.r3.s32, 25, xer);
	// blt cr6,0x822cd2ac
	if (cr6.lt) goto loc_822CD2AC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19068
	ctx.r4.s64 = ctx.r10.s64 + -19068;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD2AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD2AC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-19076
	ctx.r4.s64 = ctx.r10.s64 + -19076;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD2CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,15
	cr6.compare<int32_t>(ctx.r3.s32, 15, xer);
	// blt cr6,0x822cd2f8
	if (cr6.lt) goto loc_822CD2F8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19084
	ctx.r4.s64 = ctx.r10.s64 + -19084;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD2F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD2F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,542
	ctx.r5.s64 = 542;
	// addi r4,r10,-19092
	ctx.r4.s64 = ctx.r10.s64 + -19092;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// blt cr6,0x822cd344
	if (cr6.lt) goto loc_822CD344;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19100
	ctx.r4.s64 = ctx.r10.s64 + -19100;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD344;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD344:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-19108
	ctx.r4.s64 = ctx.r10.s64 + -19108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// blt cr6,0x822cd390
	if (cr6.lt) goto loc_822CD390;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19116
	ctx.r4.s64 = ctx.r10.s64 + -19116;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD390;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD390:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-19124
	ctx.r4.s64 = ctx.r10.s64 + -19124;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD3B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// blt cr6,0x822cd3dc
	if (cr6.lt) goto loc_822CD3DC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19132
	ctx.r4.s64 = ctx.r10.s64 + -19132;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD3DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD3DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822CD3E8"))) PPC_WEAK_FUNC(sub_822CD3E8);
PPC_FUNC_IMPL(__imp__sub_822CD3E8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238d9b8
	ctx.lr = 0x822CD414;
	sub_8238D9B8(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822cd434
	if (cr6.eq) goto loc_822CD434;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bne cr6,0x822cd44c
	if (!cr6.eq) goto loc_822CD44C;
loc_822CD434:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x822cd454
	if (cr6.eq) goto loc_822CD454;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x822cd454
	if (cr6.eq) goto loc_822CD454;
loc_822CD44C:
	// li r11,0
	r11.s64 = 0;
	// b 0x822cd458
	goto loc_822CD458;
loc_822CD454:
	// li r11,1
	r11.s64 = 1;
loc_822CD458:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_822CD474"))) PPC_WEAK_FUNC(sub_822CD474);
PPC_FUNC_IMPL(__imp__sub_822CD474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CD478"))) PPC_WEAK_FUNC(sub_822CD478);
PPC_FUNC_IMPL(__imp__sub_822CD478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CD490"))) PPC_WEAK_FUNC(sub_822CD490);
PPC_FUNC_IMPL(__imp__sub_822CD490) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,12336
	ctx.r9.s64 = 808452096;
	// li r11,0
	r11.s64 = 0;
	// ori r8,r9,13568
	ctx.r8.u64 = ctx.r9.u64 | 13568;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stfs f0,184(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stfs f0,188(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stfs f0,216(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
	// stfs f0,220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// stfs f0,224(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// stfs f0,228(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// stfs f0,232(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// stw r11,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r11.u32);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// stw r11,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r11.u32);
	// stw r11,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r11.u32);
	// stw r11,244(r31)
	PPC_STORE_U32(r31.u32 + 244, r11.u32);
	// stw r11,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r11.u32);
	// stw r11,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r11.u32);
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// stw r11,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r11.u32);
	// stw r11,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r11.u32);
	// stw r11,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r11.u32);
	// stw r11,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r11.u32);
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
	// stw r11,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r11.u32);
	// stw r11,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r11.u32);
	// stw r11,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r11.u32);
	// stw r11,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r11.u32);
	// stw r11,296(r31)
	PPC_STORE_U32(r31.u32 + 296, r11.u32);
	// stw r11,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r11.u32);
	// bl 0x823d9890
	ctx.lr = 0x822CD578;
	sub_823D9890(ctx, base);
	// addi r3,r31,304
	ctx.r3.s64 = r31.s64 + 304;
	// li r5,400
	ctx.r5.s64 = 400;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x822CD588;
	sub_823D9890(ctx, base);
	// addi r3,r31,704
	ctx.r3.s64 = r31.s64 + 704;
	// li r5,200
	ctx.r5.s64 = 200;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x822CD598;
	sub_823D9890(ctx, base);
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

__attribute__((alias("__imp__sub_822CD5B0"))) PPC_WEAK_FUNC(sub_822CD5B0);
PPC_FUNC_IMPL(__imp__sub_822CD5B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822CD5B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x822CD5C8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822cd5f4
	if (!cr6.gt) goto loc_822CD5F4;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_822CD5D8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822cd5e8
	if (cr6.eq) goto loc_822CD5E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d4c8
	ctx.lr = 0x822CD5E8;
	sub_8238D4C8(ctx, base);
loc_822CD5E8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x822cd5d8
	if (!cr0.eq) goto loc_822CD5D8;
loc_822CD5F4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822CD600"))) PPC_WEAK_FUNC(sub_822CD600);
PPC_FUNC_IMPL(__imp__sub_822CD600) {
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
	ctx.lr = 0x822CD608;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,11(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cd6d0
	if (cr6.eq) goto loc_822CD6D0;
	// rlwinm r3,r28,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r31,r28,16
	r31.u64 = r28.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x822CD62C;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822cd650
	if (cr6.eq) goto loc_822CD650;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_822CD644:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822cd644
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822CD644;
loc_822CD650:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cd6c0
	if (cr6.eq) goto loc_822CD6C0;
	// li r8,0
	ctx.r8.s64 = 0;
loc_822CD664:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r11,r8,r11
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cd6ac
	if (cr6.eq) goto loc_822CD6AC;
loc_822CD674:
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r9,r11,12
	ctx.r9.s64 = r11.s64 + 12;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// twllei r31,0
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// divwu r4,r5,r31
	ctx.r4.u32 = ctx.r5.u32 / r31.u32;
	// mullw r3,r4,r31
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r31.s32);
	// subf r10,r3,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stwx r6,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r6.u32);
	// bne cr6,0x822cd674
	if (!cr6.eq) goto loc_822CD674;
loc_822CD6AC:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x822cd664
	if (cr6.lt) goto loc_822CD664;
loc_822CD6C0:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822CD6CC;
	sub_82130588(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_822CD6D0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822CD6D8"))) PPC_WEAK_FUNC(sub_822CD6D8);
PPC_FUNC_IMPL(__imp__sub_822CD6D8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-19152
	ctx.r9.s64 = r11.s64 + -19152;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822cd70c
	if (cr6.eq) goto loc_822CD70C;
	// bl 0x82130588
	ctx.lr = 0x822CD708;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822CD70C:
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

__attribute__((alias("__imp__sub_822CD720"))) PPC_WEAK_FUNC(sub_822CD720);
PPC_FUNC_IMPL(__imp__sub_822CD720) {
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
	ctx.lr = 0x822CD728;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r25,r6,24
	r25.u64 = ctx.r6.u32 & 0xFF;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822cd77c
	if (cr6.eq) goto loc_822CD77C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r11,-18732
	ctx.r4.s64 = r11.s64 + -18732;
	// li r6,2
	ctx.r6.s64 = 2;
	// clrlwi r5,r29,16
	ctx.r5.u64 = r29.u32 & 0xFFFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238da80
	ctx.lr = 0x822CD768;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CD77C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD77C:
	// clrlwi r26,r30,24
	r26.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822cd7bc
	if (cr6.eq) goto loc_822CD7BC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r11,-18740
	ctx.r4.s64 = r11.s64 + -18740;
	// li r6,2
	ctx.r6.s64 = 2;
	// clrlwi r5,r29,16
	ctx.r5.u64 = r29.u32 & 0xFFFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238da80
	ctx.lr = 0x822CD7A8;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CD7BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD7BC:
	// clrlwi r30,r27,24
	r30.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822cd7fc
	if (cr6.eq) goto loc_822CD7FC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r11,-18748
	ctx.r4.s64 = r11.s64 + -18748;
	// li r6,2
	ctx.r6.s64 = 2;
	// clrlwi r5,r29,16
	ctx.r5.u64 = r29.u32 & 0xFFFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238da80
	ctx.lr = 0x822CD7E8;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CD7FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CD7FC:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822cdac0
	if (cr6.eq) goto loc_822CDAC0;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822cdac0
	if (cr6.eq) goto loc_822CDAC0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822cdac0
	if (cr6.eq) goto loc_822CDAC0;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x822CD820;
	sub_8238EC00(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r27,0(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// clrlwi r31,r29,16
	r31.u64 = r29.u32 & 0xFFFF;
	// addi r25,r11,-18756
	r25.s64 = r11.s64 + -18756;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238da80
	ctx.lr = 0x822CD84C;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CD860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-18764
	ctx.r4.s64 = ctx.r9.s64 + -18764;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r27,0(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822CD87C;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CD890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r11,r29,2,14,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x3FFFC;
	// add r7,r31,r11
	ctx.r7.u64 = r31.u64 + r11.u64;
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,144(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 144);
	// clrlwi r5,r11,31
	ctx.r5.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822cd990
	if (cr6.eq) goto loc_822CD990;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r26,r11,-18772
	r26.s64 = r11.s64 + -18772;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD8D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822cdac0
	if (cr6.eq) goto loc_822CDAC0;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r27,1
	r27.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822cda88
	if (!cr6.gt) goto loc_822CDA88;
	// li r31,0
	r31.s64 = 0;
loc_822CD8F8:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r10,r31,r11
	ctx.r10.u64 = r31.u64 + r11.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822cd924
	if (cr6.eq) goto loc_822CD924;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x822cd924
	if (cr6.eq) goto loc_822CD924;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// beq cr6,0x822cd924
	if (cr6.eq) goto loc_822CD924;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822cd978
	if (!cr6.eq) goto loc_822CD978;
loc_822CD924:
	// lbz r11,96(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cd978
	if (!cr6.eq) goto loc_822CD978;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CD94C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822cd978
	if (cr6.eq) goto loc_822CD978;
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822cd978
	if (!cr6.eq) goto loc_822CD978;
	// lwz r11,144(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822cda84
	if (!cr6.eq) goto loc_822CDA84;
loc_822CD978:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,160
	r31.s64 = r31.s64 + 160;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822cd8f8
	if (cr6.lt) goto loc_822CD8F8;
	// b 0x822cda88
	goto loc_822CDA88;
loc_822CD990:
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822cdac0
	if (cr6.eq) goto loc_822CDAC0;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r26,r11,-18780
	r26.s64 = r11.s64 + -18780;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CD9C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822cdac0
	if (cr6.eq) goto loc_822CDAC0;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r27,1
	r27.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822cda88
	if (!cr6.gt) goto loc_822CDA88;
	// li r31,0
	r31.s64 = 0;
loc_822CD9E0:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bne cr6,0x822cda6c
	if (!cr6.eq) goto loc_822CDA6C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x822cda18
	if (cr6.eq) goto loc_822CDA18;
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// beq cr6,0x822cda18
	if (cr6.eq) goto loc_822CDA18;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// beq cr6,0x822cda18
	if (cr6.eq) goto loc_822CDA18;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x822cda6c
	if (!cr6.eq) goto loc_822CDA6C;
loc_822CDA18:
	// lbz r11,96(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cda6c
	if (!cr6.eq) goto loc_822CDA6C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CDA40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822cda6c
	if (cr6.eq) goto loc_822CDA6C;
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822cda6c
	if (!cr6.eq) goto loc_822CDA6C;
	// lwz r11,144(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822cda84
	if (!cr6.eq) goto loc_822CDA84;
loc_822CDA6C:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,160
	r31.s64 = r31.s64 + 160;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822cd9e0
	if (cr6.lt) goto loc_822CD9E0;
	// b 0x822cda88
	goto loc_822CDA88;
loc_822CDA84:
	// li r27,0
	r27.s64 = 0;
loc_822CDA88:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cdac0
	if (cr6.eq) goto loc_822CDAC0;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238dbb0
	ctx.lr = 0x822CDAAC;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CDAC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CDAC0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822CDAC8"))) PPC_WEAK_FUNC(sub_822CDAC8);
PPC_FUNC_IMPL(__imp__sub_822CDAC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r11,-12440(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12440);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stfs f0,704(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 704, temp.u32);
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,701(r11)
	PPC_STORE_U8(r11.u32 + 701, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CDB04"))) PPC_WEAK_FUNC(sub_822CDB04);
PPC_FUNC_IMPL(__imp__sub_822CDB04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CDB08"))) PPC_WEAK_FUNC(sub_822CDB08);
PPC_FUNC_IMPL(__imp__sub_822CDB08) {
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
	ctx.lr = 0x822CDB10;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32115
	r29.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lwz r3,-12440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// clrlwi r5,r30,16
	ctx.r5.u64 = r30.u32 & 0xFFFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CDB48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822CDB64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r5,-18708
	ctx.r3.s64 = ctx.r5.s64 + -18708;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x822CDB7C;
	sub_82130000(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-18724
	ctx.r4.s64 = r11.s64 + -18724;
	// lwz r3,-10224(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x822CDB94;
	sub_8268B770(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822CDB9C"))) PPC_WEAK_FUNC(sub_822CDB9C);
PPC_FUNC_IMPL(__imp__sub_822CDB9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CDBA0"))) PPC_WEAK_FUNC(sub_822CDBA0);
PPC_FUNC_IMPL(__imp__sub_822CDBA0) {
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
	ctx.lr = 0x822CDBA8;
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
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cdc00
	if (cr6.eq) goto loc_822CDC00;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_822CDBC8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822cdbec
	if (cr6.eq) goto loc_822CDBEC;
loc_822CDBD8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x822CDBE4;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822cdbd8
	if (!cr6.eq) goto loc_822CDBD8;
loc_822CDBEC:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x822cdbc8
	if (cr6.lt) goto loc_822CDBC8;
loc_822CDC00:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822CDC08;
	sub_82130588(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

