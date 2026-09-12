#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827B4588"))) PPC_WEAK_FUNC(sub_827B4588);
PPC_FUNC_IMPL(__imp__sub_827B4588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14480
	ctx.r3.s64 = r11.s64 + -14480;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4594"))) PPC_WEAK_FUNC(sub_827B4594);
PPC_FUNC_IMPL(__imp__sub_827B4594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4598"))) PPC_WEAK_FUNC(sub_827B4598);
PPC_FUNC_IMPL(__imp__sub_827B4598) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7540
	ctx.r7.s64 = ctx.r8.s64 + 7540;
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

__attribute__((alias("__imp__sub_827B45B8"))) PPC_WEAK_FUNC(sub_827B45B8);
PPC_FUNC_IMPL(__imp__sub_827B45B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7548
	ctx.r7.s64 = ctx.r8.s64 + 7548;
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

__attribute__((alias("__imp__sub_827B45D8"))) PPC_WEAK_FUNC(sub_827B45D8);
PPC_FUNC_IMPL(__imp__sub_827B45D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7556
	ctx.r7.s64 = ctx.r8.s64 + 7556;
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

__attribute__((alias("__imp__sub_827B45F8"))) PPC_WEAK_FUNC(sub_827B45F8);
PPC_FUNC_IMPL(__imp__sub_827B45F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7660
	ctx.r7.s64 = ctx.r8.s64 + 7660;
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

__attribute__((alias("__imp__sub_827B4618"))) PPC_WEAK_FUNC(sub_827B4618);
PPC_FUNC_IMPL(__imp__sub_827B4618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7668
	ctx.r7.s64 = ctx.r8.s64 + 7668;
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

__attribute__((alias("__imp__sub_827B4638"))) PPC_WEAK_FUNC(sub_827B4638);
PPC_FUNC_IMPL(__imp__sub_827B4638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7676
	ctx.r7.s64 = ctx.r8.s64 + 7676;
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

__attribute__((alias("__imp__sub_827B4658"))) PPC_WEAK_FUNC(sub_827B4658);
PPC_FUNC_IMPL(__imp__sub_827B4658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7684
	ctx.r7.s64 = ctx.r8.s64 + 7684;
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

__attribute__((alias("__imp__sub_827B4678"))) PPC_WEAK_FUNC(sub_827B4678);
PPC_FUNC_IMPL(__imp__sub_827B4678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7692
	ctx.r7.s64 = ctx.r8.s64 + 7692;
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

__attribute__((alias("__imp__sub_827B4698"))) PPC_WEAK_FUNC(sub_827B4698);
PPC_FUNC_IMPL(__imp__sub_827B4698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,7860
	ctx.r7.s64 = ctx.r8.s64 + 7860;
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

__attribute__((alias("__imp__sub_827B46B8"))) PPC_WEAK_FUNC(sub_827B46B8);
PPC_FUNC_IMPL(__imp__sub_827B46B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,8324
	ctx.r7.s64 = ctx.r8.s64 + 8324;
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

__attribute__((alias("__imp__sub_827B46D8"))) PPC_WEAK_FUNC(sub_827B46D8);
PPC_FUNC_IMPL(__imp__sub_827B46D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,8340
	ctx.r7.s64 = ctx.r8.s64 + 8340;
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

__attribute__((alias("__imp__sub_827B46F8"))) PPC_WEAK_FUNC(sub_827B46F8);
PPC_FUNC_IMPL(__imp__sub_827B46F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,8716
	ctx.r7.s64 = ctx.r8.s64 + 8716;
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

__attribute__((alias("__imp__sub_827B4718"))) PPC_WEAK_FUNC(sub_827B4718);
PPC_FUNC_IMPL(__imp__sub_827B4718) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r5,r11,-2284
	ctx.r5.s64 = r11.s64 + -2284;
	// addi r3,r10,-23428
	ctx.r3.s64 = ctx.r10.s64 + -23428;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4734"))) PPC_WEAK_FUNC(sub_827B4734);
PPC_FUNC_IMPL(__imp__sub_827B4734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4738"))) PPC_WEAK_FUNC(sub_827B4738);
PPC_FUNC_IMPL(__imp__sub_827B4738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r5,r11,-2272
	ctx.r5.s64 = r11.s64 + -2272;
	// addi r3,r10,-23448
	ctx.r3.s64 = ctx.r10.s64 + -23448;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4754"))) PPC_WEAK_FUNC(sub_827B4754);
PPC_FUNC_IMPL(__imp__sub_827B4754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4758"))) PPC_WEAK_FUNC(sub_827B4758);
PPC_FUNC_IMPL(__imp__sub_827B4758) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23388
	ctx.r3.s64 = r11.s64 + -23388;
	// bl 0x821c8ed8
	ctx.lr = 0x827B4770;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-14424
	ctx.r3.s64 = ctx.r10.s64 + -14424;
	// bl 0x823d9a98
	ctx.lr = 0x827B477C;
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

__attribute__((alias("__imp__sub_827B478C"))) PPC_WEAK_FUNC(sub_827B478C);
PPC_FUNC_IMPL(__imp__sub_827B478C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4790"))) PPC_WEAK_FUNC(sub_827B4790);
PPC_FUNC_IMPL(__imp__sub_827B4790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,1976
	ctx.r5.s64 = r11.s64 + 1976;
	// addi r3,r10,-2208
	ctx.r3.s64 = ctx.r10.s64 + -2208;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B47AC"))) PPC_WEAK_FUNC(sub_827B47AC);
PPC_FUNC_IMPL(__imp__sub_827B47AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B47B0"))) PPC_WEAK_FUNC(sub_827B47B0);
PPC_FUNC_IMPL(__imp__sub_827B47B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,1988
	ctx.r5.s64 = r11.s64 + 1988;
	// addi r3,r10,-2228
	ctx.r3.s64 = ctx.r10.s64 + -2228;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B47CC"))) PPC_WEAK_FUNC(sub_827B47CC);
PPC_FUNC_IMPL(__imp__sub_827B47CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B47D0"))) PPC_WEAK_FUNC(sub_827B47D0);
PPC_FUNC_IMPL(__imp__sub_827B47D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3624
	ctx.r5.s64 = r11.s64 + 3624;
	// addi r3,r10,-2144
	ctx.r3.s64 = ctx.r10.s64 + -2144;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B47EC"))) PPC_WEAK_FUNC(sub_827B47EC);
PPC_FUNC_IMPL(__imp__sub_827B47EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B47F0"))) PPC_WEAK_FUNC(sub_827B47F0);
PPC_FUNC_IMPL(__imp__sub_827B47F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3648
	ctx.r5.s64 = r11.s64 + 3648;
	// addi r3,r10,-2164
	ctx.r3.s64 = ctx.r10.s64 + -2164;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B480C"))) PPC_WEAK_FUNC(sub_827B480C);
PPC_FUNC_IMPL(__imp__sub_827B480C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4810"))) PPC_WEAK_FUNC(sub_827B4810);
PPC_FUNC_IMPL(__imp__sub_827B4810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3668
	ctx.r5.s64 = r11.s64 + 3668;
	// addi r3,r10,-2104
	ctx.r3.s64 = ctx.r10.s64 + -2104;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B482C"))) PPC_WEAK_FUNC(sub_827B482C);
PPC_FUNC_IMPL(__imp__sub_827B482C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4830"))) PPC_WEAK_FUNC(sub_827B4830);
PPC_FUNC_IMPL(__imp__sub_827B4830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,3688
	ctx.r5.s64 = r11.s64 + 3688;
	// addi r3,r10,-2124
	ctx.r3.s64 = ctx.r10.s64 + -2124;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B484C"))) PPC_WEAK_FUNC(sub_827B484C);
PPC_FUNC_IMPL(__imp__sub_827B484C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4850"))) PPC_WEAK_FUNC(sub_827B4850);
PPC_FUNC_IMPL(__imp__sub_827B4850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r8,r9,-1984
	ctx.r8.s64 = ctx.r9.s64 + -1984;
	// lfs f0,10256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 10256);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4878"))) PPC_WEAK_FUNC(sub_827B4878);
PPC_FUNC_IMPL(__imp__sub_827B4878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14408
	ctx.r3.s64 = r11.s64 + -14408;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4884"))) PPC_WEAK_FUNC(sub_827B4884);
PPC_FUNC_IMPL(__imp__sub_827B4884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4888"))) PPC_WEAK_FUNC(sub_827B4888);
PPC_FUNC_IMPL(__imp__sub_827B4888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14384
	ctx.r3.s64 = r11.s64 + -14384;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4894"))) PPC_WEAK_FUNC(sub_827B4894);
PPC_FUNC_IMPL(__imp__sub_827B4894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4898"))) PPC_WEAK_FUNC(sub_827B4898);
PPC_FUNC_IMPL(__imp__sub_827B4898) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14360
	ctx.r3.s64 = r11.s64 + -14360;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B48A4"))) PPC_WEAK_FUNC(sub_827B48A4);
PPC_FUNC_IMPL(__imp__sub_827B48A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B48A8"))) PPC_WEAK_FUNC(sub_827B48A8);
PPC_FUNC_IMPL(__imp__sub_827B48A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14336
	ctx.r3.s64 = r11.s64 + -14336;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B48B4"))) PPC_WEAK_FUNC(sub_827B48B4);
PPC_FUNC_IMPL(__imp__sub_827B48B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B48B8"))) PPC_WEAK_FUNC(sub_827B48B8);
PPC_FUNC_IMPL(__imp__sub_827B48B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14312
	ctx.r3.s64 = r11.s64 + -14312;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B48C4"))) PPC_WEAK_FUNC(sub_827B48C4);
PPC_FUNC_IMPL(__imp__sub_827B48C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B48C8"))) PPC_WEAK_FUNC(sub_827B48C8);
PPC_FUNC_IMPL(__imp__sub_827B48C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r8,r9,-1952
	ctx.r8.s64 = ctx.r9.s64 + -1952;
	// lfs f0,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B48F0"))) PPC_WEAK_FUNC(sub_827B48F0);
PPC_FUNC_IMPL(__imp__sub_827B48F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-22976
	ctx.r9.s64 = r11.s64 + -22976;
	// addi r8,r10,-1904
	ctx.r8.s64 = ctx.r10.s64 + -1904;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B490C"))) PPC_WEAK_FUNC(sub_827B490C);
PPC_FUNC_IMPL(__imp__sub_827B490C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4910"))) PPC_WEAK_FUNC(sub_827B4910);
PPC_FUNC_IMPL(__imp__sub_827B4910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f0,14348(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14348);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r6,r7,-1824
	ctx.r6.s64 = ctx.r7.s64 + -1824;
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v62,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v60,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v59,v63,7,0
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 228), 7));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vrlimi128 v58,v59,11,0
	simde_mm_store_ps(v58.f32, simde_mm_blend_ps(simde_mm_load_ps(v58.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 228), 11));
	// vrlimi128 v63,v58,13,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v58.f32), 228), 13));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4968"))) PPC_WEAK_FUNC(sub_827B4968);
PPC_FUNC_IMPL(__imp__sub_827B4968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f0,19360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 19360);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r6,r7,-1808
	ctx.r6.s64 = ctx.r7.s64 + -1808;
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v62,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v60,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v59,v63,7,0
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 228), 7));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vrlimi128 v58,v59,11,0
	simde_mm_store_ps(v58.f32, simde_mm_blend_ps(simde_mm_load_ps(v58.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 228), 11));
	// vrlimi128 v63,v58,13,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v58.f32), 228), 13));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B49C0"))) PPC_WEAK_FUNC(sub_827B49C0);
PPC_FUNC_IMPL(__imp__sub_827B49C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,13752
	ctx.r9.s64 = r11.s64 + 13752;
	// addi r8,r10,-1840
	ctx.r8.s64 = ctx.r10.s64 + -1840;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvlx128 v58,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v58,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vrlimi128 v61,v62,7,0
	simde_mm_store_ps(v61.f32, simde_mm_blend_ps(simde_mm_load_ps(v61.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 228), 7));
	// vrlimi128 v59,v61,11,0
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 228), 11));
	// vrlimi128 v63,v59,13,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 228), 13));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4A00"))) PPC_WEAK_FUNC(sub_827B4A00);
PPC_FUNC_IMPL(__imp__sub_827B4A00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f0,18612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r6,r7,-1856
	ctx.r6.s64 = ctx.r7.s64 + -1856;
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v62,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v60,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v59,v63,7,0
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 228), 7));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vrlimi128 v58,v59,11,0
	simde_mm_store_ps(v58.f32, simde_mm_blend_ps(simde_mm_load_ps(v58.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 228), 11));
	// vrlimi128 v63,v58,13,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v58.f32), 228), 13));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4A58"))) PPC_WEAK_FUNC(sub_827B4A58);
PPC_FUNC_IMPL(__imp__sub_827B4A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f0,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r6,r7,-1792
	ctx.r6.s64 = ctx.r7.s64 + -1792;
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v62,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v60,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v59,v63,7,0
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 228), 7));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vrlimi128 v58,v59,11,0
	simde_mm_store_ps(v58.f32, simde_mm_blend_ps(simde_mm_load_ps(v58.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 228), 11));
	// vrlimi128 v63,v58,13,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v58.f32), 228), 13));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4AB0"))) PPC_WEAK_FUNC(sub_827B4AB0);
PPC_FUNC_IMPL(__imp__sub_827B4AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14288
	ctx.r3.s64 = r11.s64 + -14288;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4ABC"))) PPC_WEAK_FUNC(sub_827B4ABC);
PPC_FUNC_IMPL(__imp__sub_827B4ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4AC0"))) PPC_WEAK_FUNC(sub_827B4AC0);
PPC_FUNC_IMPL(__imp__sub_827B4AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14264
	ctx.r3.s64 = r11.s64 + -14264;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4ACC"))) PPC_WEAK_FUNC(sub_827B4ACC);
PPC_FUNC_IMPL(__imp__sub_827B4ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4AD0"))) PPC_WEAK_FUNC(sub_827B4AD0);
PPC_FUNC_IMPL(__imp__sub_827B4AD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14240
	ctx.r3.s64 = r11.s64 + -14240;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4ADC"))) PPC_WEAK_FUNC(sub_827B4ADC);
PPC_FUNC_IMPL(__imp__sub_827B4ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4AE0"))) PPC_WEAK_FUNC(sub_827B4AE0);
PPC_FUNC_IMPL(__imp__sub_827B4AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14200
	ctx.r3.s64 = r11.s64 + -14200;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4AEC"))) PPC_WEAK_FUNC(sub_827B4AEC);
PPC_FUNC_IMPL(__imp__sub_827B4AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4AF0"))) PPC_WEAK_FUNC(sub_827B4AF0);
PPC_FUNC_IMPL(__imp__sub_827B4AF0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r3,r11,6556
	ctx.r3.s64 = r11.s64 + 6556;
	// bl 0x821c8ed8
	ctx.lr = 0x827B4B08;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-14216
	ctx.r3.s64 = ctx.r10.s64 + -14216;
	// bl 0x823d9a98
	ctx.lr = 0x827B4B14;
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

__attribute__((alias("__imp__sub_827B4B24"))) PPC_WEAK_FUNC(sub_827B4B24);
PPC_FUNC_IMPL(__imp__sub_827B4B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4B28"))) PPC_WEAK_FUNC(sub_827B4B28);
PPC_FUNC_IMPL(__imp__sub_827B4B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14104
	ctx.r3.s64 = r11.s64 + -14104;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4B34"))) PPC_WEAK_FUNC(sub_827B4B34);
PPC_FUNC_IMPL(__imp__sub_827B4B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4B38"))) PPC_WEAK_FUNC(sub_827B4B38);
PPC_FUNC_IMPL(__imp__sub_827B4B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r5,r11,14600
	ctx.r5.s64 = r11.s64 + 14600;
	// addi r4,r10,25216
	ctx.r4.s64 = ctx.r10.s64 + 25216;
	// addi r3,r9,6636
	ctx.r3.s64 = ctx.r9.s64 + 6636;
	// li r6,5112
	ctx.r6.s64 = 5112;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4B58"))) PPC_WEAK_FUNC(sub_827B4B58);
PPC_FUNC_IMPL(__imp__sub_827B4B58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r5,r11,19712
	ctx.r5.s64 = r11.s64 + 19712;
	// addi r4,r10,25252
	ctx.r4.s64 = ctx.r10.s64 + 25252;
	// addi r3,r9,6652
	ctx.r3.s64 = ctx.r9.s64 + 6652;
	// li r6,4347
	ctx.r6.s64 = 4347;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4B78"))) PPC_WEAK_FUNC(sub_827B4B78);
PPC_FUNC_IMPL(__imp__sub_827B4B78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r5,r11,24136
	ctx.r5.s64 = r11.s64 + 24136;
	// addi r4,r10,26232
	ctx.r4.s64 = ctx.r10.s64 + 26232;
	// addi r3,r9,6684
	ctx.r3.s64 = ctx.r9.s64 + 6684;
	// li r6,18323
	ctx.r6.s64 = 18323;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4B98"))) PPC_WEAK_FUNC(sub_827B4B98);
PPC_FUNC_IMPL(__imp__sub_827B4B98) {
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
	ctx.lr = 0x827B4BC0;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,-22212
	r11.s64 = ctx.r7.s64 + -22212;
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

__attribute__((alias("__imp__sub_827B4C0C"))) PPC_WEAK_FUNC(sub_827B4C0C);
PPC_FUNC_IMPL(__imp__sub_827B4C0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4C10"))) PPC_WEAK_FUNC(sub_827B4C10);
PPC_FUNC_IMPL(__imp__sub_827B4C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r7,r8,-22164
	ctx.r7.s64 = ctx.r8.s64 + -22164;
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

__attribute__((alias("__imp__sub_827B4C30"))) PPC_WEAK_FUNC(sub_827B4C30);
PPC_FUNC_IMPL(__imp__sub_827B4C30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r7,r8,-22156
	ctx.r7.s64 = ctx.r8.s64 + -22156;
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

__attribute__((alias("__imp__sub_827B4C50"))) PPC_WEAK_FUNC(sub_827B4C50);
PPC_FUNC_IMPL(__imp__sub_827B4C50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r10,95
	ctx.r10.s64 = 95;
	// addi r11,r11,20112
	r11.s64 = r11.s64 + 20112;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
loc_827B4C64:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x827b4c64
	if (!cr0.lt) goto loc_827B4C64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4C7C"))) PPC_WEAK_FUNC(sub_827B4C7C);
PPC_FUNC_IMPL(__imp__sub_827B4C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4C80"))) PPC_WEAK_FUNC(sub_827B4C80);
PPC_FUNC_IMPL(__imp__sub_827B4C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14096
	ctx.r3.s64 = r11.s64 + -14096;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4C8C"))) PPC_WEAK_FUNC(sub_827B4C8C);
PPC_FUNC_IMPL(__imp__sub_827B4C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4C90"))) PPC_WEAK_FUNC(sub_827B4C90);
PPC_FUNC_IMPL(__imp__sub_827B4C90) {
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
	// addi r3,r11,30700
	ctx.r3.s64 = r11.s64 + 30700;
	// bl 0x821c9790
	ctx.lr = 0x827B4CAC;
	sub_821C9790(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r11,1
	r11.s64 = 1;
	// addi r9,r10,-18432
	ctx.r9.s64 = ctx.r10.s64 + -18432;
	// stw r3,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r3.u32);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4CD0"))) PPC_WEAK_FUNC(sub_827B4CD0);
PPC_FUNC_IMPL(__imp__sub_827B4CD0) {
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
	// addi r3,r11,30708
	ctx.r3.s64 = r11.s64 + 30708;
	// bl 0x821c9790
	ctx.lr = 0x827B4CEC;
	sub_821C9790(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r11,1
	r11.s64 = 1;
	// addi r9,r10,-18420
	ctx.r9.s64 = ctx.r10.s64 + -18420;
	// stw r3,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r3.u32);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4D10"))) PPC_WEAK_FUNC(sub_827B4D10);
PPC_FUNC_IMPL(__imp__sub_827B4D10) {
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
	// addi r3,r11,28664
	ctx.r3.s64 = r11.s64 + 28664;
	// bl 0x821c9790
	ctx.lr = 0x827B4D2C;
	sub_821C9790(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r11,1
	r11.s64 = 1;
	// addi r9,r10,-18408
	ctx.r9.s64 = ctx.r10.s64 + -18408;
	// stw r3,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r3.u32);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4D50"))) PPC_WEAK_FUNC(sub_827B4D50);
PPC_FUNC_IMPL(__imp__sub_827B4D50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14064
	ctx.r3.s64 = r11.s64 + -14064;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4D5C"))) PPC_WEAK_FUNC(sub_827B4D5C);
PPC_FUNC_IMPL(__imp__sub_827B4D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4D60"))) PPC_WEAK_FUNC(sub_827B4D60);
PPC_FUNC_IMPL(__imp__sub_827B4D60) {
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
	// addi r3,r11,31640
	ctx.r3.s64 = r11.s64 + 31640;
	// bl 0x821c9790
	ctx.lr = 0x827B4D7C;
	sub_821C9790(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,21304(r10)
	PPC_STORE_U32(ctx.r10.u32 + 21304, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4D94"))) PPC_WEAK_FUNC(sub_827B4D94);
PPC_FUNC_IMPL(__imp__sub_827B4D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4D98"))) PPC_WEAK_FUNC(sub_827B4D98);
PPC_FUNC_IMPL(__imp__sub_827B4D98) {
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
	// addi r3,r11,31648
	ctx.r3.s64 = r11.s64 + 31648;
	// bl 0x821c9790
	ctx.lr = 0x827B4DB4;
	sub_821C9790(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,21308(r10)
	PPC_STORE_U32(ctx.r10.u32 + 21308, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4DCC"))) PPC_WEAK_FUNC(sub_827B4DCC);
PPC_FUNC_IMPL(__imp__sub_827B4DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4DD0"))) PPC_WEAK_FUNC(sub_827B4DD0);
PPC_FUNC_IMPL(__imp__sub_827B4DD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,128
	ctx.r9.s64 = 128;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-30600
	ctx.r4.s64 = ctx.r8.s64 + -30600;
loc_827B4DF8:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// addi r8,r11,12
	ctx.r8.s64 = r11.s64 + 12;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r4,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r4.u32);
	// stb r9,11(r11)
	PPC_STORE_U8(r11.u32 + 11, ctx.r9.u8);
	// stb r9,10(r11)
	PPC_STORE_U8(r11.u32 + 10, ctx.r9.u8);
	// stb r9,9(r11)
	PPC_STORE_U8(r11.u32 + 9, ctx.r9.u8);
	// stb r9,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r9.u8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_827B4E20:
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bdnz 0x827b4e20
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_827B4E20;
	// sth r5,28(r11)
	PPC_STORE_U16(r11.u32 + 28, ctx.r5.u16);
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// sth r5,30(r11)
	PPC_STORE_U16(r11.u32 + 30, ctx.r5.u16);
	// sth r5,32(r11)
	PPC_STORE_U16(r11.u32 + 32, ctx.r5.u16);
	// sth r5,34(r11)
	PPC_STORE_U16(r11.u32 + 34, ctx.r5.u16);
	// stb r6,36(r11)
	PPC_STORE_U8(r11.u32 + 36, ctx.r6.u8);
	// stb r6,37(r11)
	PPC_STORE_U8(r11.u32 + 37, ctx.r6.u8);
	// stb r6,38(r11)
	PPC_STORE_U8(r11.u32 + 38, ctx.r6.u8);
	// sth r10,52(r11)
	PPC_STORE_U16(r11.u32 + 52, ctx.r10.u16);
	// sth r10,50(r11)
	PPC_STORE_U16(r11.u32 + 50, ctx.r10.u16);
	// stw r10,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r10.u32);
	// stb r10,39(r11)
	PPC_STORE_U8(r11.u32 + 39, ctx.r10.u8);
	// stb r10,40(r11)
	PPC_STORE_U8(r11.u32 + 40, ctx.r10.u8);
	// stb r10,41(r11)
	PPC_STORE_U8(r11.u32 + 41, ctx.r10.u8);
	// stb r6,48(r11)
	PPC_STORE_U8(r11.u32 + 48, ctx.r6.u8);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bge 0x827b4df8
	if (!cr0.lt) goto loc_827B4DF8;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14048
	ctx.r3.s64 = r11.s64 + -14048;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4E7C"))) PPC_WEAK_FUNC(sub_827B4E7C);
PPC_FUNC_IMPL(__imp__sub_827B4E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4E80"))) PPC_WEAK_FUNC(sub_827B4E80);
PPC_FUNC_IMPL(__imp__sub_827B4E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-17664
	ctx.r5.s64 = r11.s64 + -17664;
	// addi r4,r10,-27756
	ctx.r4.s64 = ctx.r10.s64 + -27756;
	// addi r3,r9,21696
	ctx.r3.s64 = ctx.r9.s64 + 21696;
	// ori r6,r6,38024
	ctx.r6.u64 = ctx.r6.u64 | 38024;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4EA4"))) PPC_WEAK_FUNC(sub_827B4EA4);
PPC_FUNC_IMPL(__imp__sub_827B4EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4EA8"))) PPC_WEAK_FUNC(sub_827B4EA8);
PPC_FUNC_IMPL(__imp__sub_827B4EA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-27648
	ctx.r5.s64 = r11.s64 + -27648;
	// addi r3,r10,21676
	ctx.r3.s64 = ctx.r10.s64 + 21676;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4EC4"))) PPC_WEAK_FUNC(sub_827B4EC4);
PPC_FUNC_IMPL(__imp__sub_827B4EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4EC8"))) PPC_WEAK_FUNC(sub_827B4EC8);
PPC_FUNC_IMPL(__imp__sub_827B4EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-27200
	ctx.r5.s64 = r11.s64 + -27200;
	// addi r3,r10,21724
	ctx.r3.s64 = ctx.r10.s64 + 21724;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4EE4"))) PPC_WEAK_FUNC(sub_827B4EE4);
PPC_FUNC_IMPL(__imp__sub_827B4EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4EE8"))) PPC_WEAK_FUNC(sub_827B4EE8);
PPC_FUNC_IMPL(__imp__sub_827B4EE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-27180
	ctx.r5.s64 = r11.s64 + -27180;
	// addi r3,r10,21744
	ctx.r3.s64 = ctx.r10.s64 + 21744;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4F04"))) PPC_WEAK_FUNC(sub_827B4F04);
PPC_FUNC_IMPL(__imp__sub_827B4F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4F08"))) PPC_WEAK_FUNC(sub_827B4F08);
PPC_FUNC_IMPL(__imp__sub_827B4F08) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r3,r11,23584
	ctx.r3.s64 = r11.s64 + 23584;
	// bl 0x82618268
	ctx.lr = 0x827B4F20;
	sub_82618268(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-13976
	ctx.r3.s64 = ctx.r10.s64 + -13976;
	// bl 0x823d9a98
	ctx.lr = 0x827B4F2C;
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

__attribute__((alias("__imp__sub_827B4F3C"))) PPC_WEAK_FUNC(sub_827B4F3C);
PPC_FUNC_IMPL(__imp__sub_827B4F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4F40"))) PPC_WEAK_FUNC(sub_827B4F40);
PPC_FUNC_IMPL(__imp__sub_827B4F40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r10,21088
	ctx.r8.s64 = ctx.r10.s64 + 21088;
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-8(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r8,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B4F70"))) PPC_WEAK_FUNC(sub_827B4F70);
PPC_FUNC_IMPL(__imp__sub_827B4F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13960
	ctx.r3.s64 = r11.s64 + -13960;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4F7C"))) PPC_WEAK_FUNC(sub_827B4F7C);
PPC_FUNC_IMPL(__imp__sub_827B4F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4F80"))) PPC_WEAK_FUNC(sub_827B4F80);
PPC_FUNC_IMPL(__imp__sub_827B4F80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13944
	ctx.r3.s64 = r11.s64 + -13944;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4F8C"))) PPC_WEAK_FUNC(sub_827B4F8C);
PPC_FUNC_IMPL(__imp__sub_827B4F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4F90"))) PPC_WEAK_FUNC(sub_827B4F90);
PPC_FUNC_IMPL(__imp__sub_827B4F90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13936
	ctx.r3.s64 = r11.s64 + -13936;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4F9C"))) PPC_WEAK_FUNC(sub_827B4F9C);
PPC_FUNC_IMPL(__imp__sub_827B4F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4FA0"))) PPC_WEAK_FUNC(sub_827B4FA0);
PPC_FUNC_IMPL(__imp__sub_827B4FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,-4584
	ctx.r5.s64 = r11.s64 + -4584;
	// addi r3,r10,25020
	ctx.r3.s64 = ctx.r10.s64 + 25020;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4FBC"))) PPC_WEAK_FUNC(sub_827B4FBC);
PPC_FUNC_IMPL(__imp__sub_827B4FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4FC0"))) PPC_WEAK_FUNC(sub_827B4FC0);
PPC_FUNC_IMPL(__imp__sub_827B4FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r3,r11,27576
	ctx.r3.s64 = r11.s64 + 27576;
	// b 0x824f5c00
	sub_824F5C00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B4FCC"))) PPC_WEAK_FUNC(sub_827B4FCC);
PPC_FUNC_IMPL(__imp__sub_827B4FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B4FD0"))) PPC_WEAK_FUNC(sub_827B4FD0);
PPC_FUNC_IMPL(__imp__sub_827B4FD0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r31,15
	r31.s64 = 15;
	// addi r30,r11,25144
	r30.s64 = r11.s64 + 25144;
loc_827B4FF0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f5c00
	ctx.lr = 0x827B4FF8;
	sub_824F5C00(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,152
	r30.s64 = r30.s64 + 152;
	// bge 0x827b4ff0
	if (!cr0.lt) goto loc_827B4FF0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B501C"))) PPC_WEAK_FUNC(sub_827B501C);
PPC_FUNC_IMPL(__imp__sub_827B501C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5020"))) PPC_WEAK_FUNC(sub_827B5020);
PPC_FUNC_IMPL(__imp__sub_827B5020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-13912
	ctx.r3.s64 = r11.s64 + -13912;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B502C"))) PPC_WEAK_FUNC(sub_827B502C);
PPC_FUNC_IMPL(__imp__sub_827B502C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5030"))) PPC_WEAK_FUNC(sub_827B5030);
PPC_FUNC_IMPL(__imp__sub_827B5030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,10332
	ctx.r5.s64 = r11.s64 + 10332;
	// addi r3,r10,27808
	ctx.r3.s64 = ctx.r10.s64 + 27808;
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x82630ca0
	sub_82630CA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827B5048"))) PPC_WEAK_FUNC(sub_827B5048);
PPC_FUNC_IMPL(__imp__sub_827B5048) {
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
	// addi r31,r11,27904
	r31.s64 = r11.s64 + 27904;
	// addi r5,r10,-5512
	ctx.r5.s64 = ctx.r10.s64 + -5512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5074;
	sub_82630CA0(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-4548
	ctx.r5.s64 = ctx.r9.s64 + -4548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5088;
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

__attribute__((alias("__imp__sub_827B509C"))) PPC_WEAK_FUNC(sub_827B509C);
PPC_FUNC_IMPL(__imp__sub_827B509C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B50A0"))) PPC_WEAK_FUNC(sub_827B50A0);
PPC_FUNC_IMPL(__imp__sub_827B50A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r7,r11,-28096
	ctx.r7.s64 = r11.s64 + -28096;
	// addi r6,r10,28244
	ctx.r6.s64 = ctx.r10.s64 + 28244;
	// lwz r11,-28096(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28096);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r9,8(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// stw r9,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r9.u32);
	// stw r8,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r8.u32);
	// stw r7,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B50DC"))) PPC_WEAK_FUNC(sub_827B50DC);
PPC_FUNC_IMPL(__imp__sub_827B50DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B50E0"))) PPC_WEAK_FUNC(sub_827B50E0);
PPC_FUNC_IMPL(__imp__sub_827B50E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r7,r11,-28076
	ctx.r7.s64 = r11.s64 + -28076;
	// addi r6,r10,28220
	ctx.r6.s64 = ctx.r10.s64 + 28220;
	// lwz r11,-28076(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r9,8(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// stw r9,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r9.u32);
	// stw r8,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r8.u32);
	// stw r7,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B511C"))) PPC_WEAK_FUNC(sub_827B511C);
PPC_FUNC_IMPL(__imp__sub_827B511C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5120"))) PPC_WEAK_FUNC(sub_827B5120);
PPC_FUNC_IMPL(__imp__sub_827B5120) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r9,r11,28024
	ctx.r9.s64 = r11.s64 + 28024;
	// addi r8,r10,28268
	ctx.r8.s64 = ctx.r10.s64 + 28268;
	// lwz r11,28024(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28024);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827B5144"))) PPC_WEAK_FUNC(sub_827B5144);
PPC_FUNC_IMPL(__imp__sub_827B5144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5148"))) PPC_WEAK_FUNC(sub_827B5148);
PPC_FUNC_IMPL(__imp__sub_827B5148) {
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
	// addi r31,r11,28388
	r31.s64 = r11.s64 + 28388;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5174;
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
	ctx.lr = 0x827B5188;
	sub_82630CA0(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r5,r8,-11168
	ctx.r5.s64 = ctx.r8.s64 + -11168;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B519C;
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

__attribute__((alias("__imp__sub_827B51B0"))) PPC_WEAK_FUNC(sub_827B51B0);
PPC_FUNC_IMPL(__imp__sub_827B51B0) {
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
	// addi r31,r11,28004
	r31.s64 = r11.s64 + 28004;
	// addi r5,r10,3184
	ctx.r5.s64 = ctx.r10.s64 + 3184;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B51DC;
	sub_82630CA0(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-4548
	ctx.r5.s64 = ctx.r9.s64 + -4548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B51F0;
	sub_82630CA0(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,-11536
	ctx.r5.s64 = ctx.r8.s64 + -11536;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5204;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,15
	ctx.r4.s64 = 15;
	// addi r5,r7,3160
	ctx.r5.s64 = ctx.r7.s64 + 3160;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5218;
	sub_82630CA0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r6,3148
	ctx.r5.s64 = ctx.r6.s64 + 3148;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82630ca0
	ctx.lr = 0x827B522C;
	sub_82630CA0(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// li r4,11
	ctx.r4.s64 = 11;
	// addi r5,r5,3144
	ctx.r5.s64 = ctx.r5.s64 + 3144;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x82630ca0
	ctx.lr = 0x827B5240;
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

__attribute__((alias("__imp__sub_827B5254"))) PPC_WEAK_FUNC(sub_827B5254);
PPC_FUNC_IMPL(__imp__sub_827B5254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5258"))) PPC_WEAK_FUNC(sub_827B5258);
PPC_FUNC_IMPL(__imp__sub_827B5258) {
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
	// addi r31,r11,28668
	r31.s64 = r11.s64 + 28668;
	// addi r5,r10,-10644
	ctx.r5.s64 = ctx.r10.s64 + -10644;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B5284;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,-11108
	ctx.r5.s64 = ctx.r9.s64 + -11108;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5298;
	sub_82630CA0(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r8,-11096
	ctx.r5.s64 = ctx.r8.s64 + -11096;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B52AC;
	sub_82630CA0(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r4,19
	ctx.r4.s64 = 19;
	// addi r5,r7,-11080
	ctx.r5.s64 = ctx.r7.s64 + -11080;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B52C0;
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

__attribute__((alias("__imp__sub_827B52D4"))) PPC_WEAK_FUNC(sub_827B52D4);
PPC_FUNC_IMPL(__imp__sub_827B52D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B52D8"))) PPC_WEAK_FUNC(sub_827B52D8);
PPC_FUNC_IMPL(__imp__sub_827B52D8) {
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
	// addi r31,r11,28700
	r31.s64 = r11.s64 + 28700;
	// addi r5,r10,-4548
	ctx.r5.s64 = ctx.r10.s64 + -4548;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B5304;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r9,3200
	ctx.r5.s64 = ctx.r9.s64 + 3200;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5318;
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

__attribute__((alias("__imp__sub_827B532C"))) PPC_WEAK_FUNC(sub_827B532C);
PPC_FUNC_IMPL(__imp__sub_827B532C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5330"))) PPC_WEAK_FUNC(sub_827B5330);
PPC_FUNC_IMPL(__imp__sub_827B5330) {
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
	// addi r31,r11,28324
	r31.s64 = r11.s64 + 28324;
	// addi r5,r10,-11536
	ctx.r5.s64 = ctx.r10.s64 + -11536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B535C;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,-11108
	ctx.r5.s64 = ctx.r9.s64 + -11108;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5370;
	sub_82630CA0(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r5,r8,-11244
	ctx.r5.s64 = ctx.r8.s64 + -11244;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5384;
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

__attribute__((alias("__imp__sub_827B5398"))) PPC_WEAK_FUNC(sub_827B5398);
PPC_FUNC_IMPL(__imp__sub_827B5398) {
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
	// addi r31,r11,28284
	r31.s64 = r11.s64 + 28284;
	// addi r5,r10,-4548
	ctx.r5.s64 = ctx.r10.s64 + -4548;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B53C4;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r9,3216
	ctx.r5.s64 = ctx.r9.s64 + 3216;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B53D8;
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

__attribute__((alias("__imp__sub_827B53EC"))) PPC_WEAK_FUNC(sub_827B53EC);
PPC_FUNC_IMPL(__imp__sub_827B53EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B53F0"))) PPC_WEAK_FUNC(sub_827B53F0);
PPC_FUNC_IMPL(__imp__sub_827B53F0) {
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
	// addi r31,r11,29276
	r31.s64 = r11.s64 + 29276;
	// addi r5,r10,3244
	ctx.r5.s64 = ctx.r10.s64 + 3244;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B541C;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,3232
	ctx.r5.s64 = ctx.r9.s64 + 3232;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5430;
	sub_82630CA0(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r8,-11548
	ctx.r5.s64 = ctx.r8.s64 + -11548;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5444;
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

__attribute__((alias("__imp__sub_827B5458"))) PPC_WEAK_FUNC(sub_827B5458);
PPC_FUNC_IMPL(__imp__sub_827B5458) {
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
	// addi r31,r11,28124
	r31.s64 = r11.s64 + 28124;
	// addi r5,r10,3284
	ctx.r5.s64 = ctx.r10.s64 + 3284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5484;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-11548
	ctx.r5.s64 = ctx.r9.s64 + -11548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5498;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3232
	ctx.r5.s64 = ctx.r8.s64 + 3232;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B54AC;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3260
	ctx.r5.s64 = ctx.r7.s64 + 3260;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B54C0;
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

__attribute__((alias("__imp__sub_827B54D4"))) PPC_WEAK_FUNC(sub_827B54D4);
PPC_FUNC_IMPL(__imp__sub_827B54D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B54D8"))) PPC_WEAK_FUNC(sub_827B54D8);
PPC_FUNC_IMPL(__imp__sub_827B54D8) {
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
	// addi r31,r11,29396
	r31.s64 = r11.s64 + 29396;
	// addi r5,r10,3284
	ctx.r5.s64 = ctx.r10.s64 + 3284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5504;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-11548
	ctx.r5.s64 = ctx.r9.s64 + -11548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5518;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r8,3232
	ctx.r5.s64 = ctx.r8.s64 + 3232;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B552C;
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

__attribute__((alias("__imp__sub_827B5540"))) PPC_WEAK_FUNC(sub_827B5540);
PPC_FUNC_IMPL(__imp__sub_827B5540) {
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
	// addi r31,r11,28572
	r31.s64 = r11.s64 + 28572;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B556C;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-11548
	ctx.r5.s64 = ctx.r9.s64 + -11548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5580;
	sub_82630CA0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r8,3260
	ctx.r5.s64 = ctx.r8.s64 + 3260;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B5594;
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

__attribute__((alias("__imp__sub_827B55A8"))) PPC_WEAK_FUNC(sub_827B55A8);
PPC_FUNC_IMPL(__imp__sub_827B55A8) {
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
	// addi r31,r11,28900
	r31.s64 = r11.s64 + 28900;
	// addi r5,r10,3284
	ctx.r5.s64 = ctx.r10.s64 + 3284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B55D4;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-11548
	ctx.r5.s64 = ctx.r9.s64 + -11548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B55E8;
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
	ctx.lr = 0x827B55FC;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3260
	ctx.r5.s64 = ctx.r7.s64 + 3260;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5610;
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

__attribute__((alias("__imp__sub_827B5624"))) PPC_WEAK_FUNC(sub_827B5624);
PPC_FUNC_IMPL(__imp__sub_827B5624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5628"))) PPC_WEAK_FUNC(sub_827B5628);
PPC_FUNC_IMPL(__imp__sub_827B5628) {
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
	// addi r31,r11,28860
	r31.s64 = r11.s64 + 28860;
	// addi r5,r10,3284
	ctx.r5.s64 = ctx.r10.s64 + 3284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5654;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-11548
	ctx.r5.s64 = ctx.r9.s64 + -11548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5668;
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
	ctx.lr = 0x827B567C;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3260
	ctx.r5.s64 = ctx.r7.s64 + 3260;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5690;
	sub_82630CA0(ctx, base);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// lwz r5,28868(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28868);
	// bl 0x82630ca0
	ctx.lr = 0x827B56A4;
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

__attribute__((alias("__imp__sub_827B56B8"))) PPC_WEAK_FUNC(sub_827B56B8);
PPC_FUNC_IMPL(__imp__sub_827B56B8) {
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
	// addi r31,r11,28500
	r31.s64 = r11.s64 + 28500;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B56E4;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-11548
	ctx.r5.s64 = ctx.r9.s64 + -11548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B56F8;
	sub_82630CA0(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// lwz r5,28868(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28868);
	// bl 0x82630ca0
	ctx.lr = 0x827B570C;
	sub_82630CA0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r7,3260
	ctx.r5.s64 = ctx.r7.s64 + 3260;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82630ca0
	ctx.lr = 0x827B5720;
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

__attribute__((alias("__imp__sub_827B5734"))) PPC_WEAK_FUNC(sub_827B5734);
PPC_FUNC_IMPL(__imp__sub_827B5734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5738"))) PPC_WEAK_FUNC(sub_827B5738);
PPC_FUNC_IMPL(__imp__sub_827B5738) {
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
	// addi r31,r11,28548
	r31.s64 = r11.s64 + 28548;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5764;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-11548
	ctx.r5.s64 = ctx.r9.s64 + -11548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5778;
	sub_82630CA0(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r5,r8,-11572
	ctx.r5.s64 = ctx.r8.s64 + -11572;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82630ca0
	ctx.lr = 0x827B578C;
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

__attribute__((alias("__imp__sub_827B57A0"))) PPC_WEAK_FUNC(sub_827B57A0);
PPC_FUNC_IMPL(__imp__sub_827B57A0) {
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
	// addi r31,r11,27988
	r31.s64 = r11.s64 + 27988;
	// addi r5,r10,-10492
	ctx.r5.s64 = ctx.r10.s64 + -10492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B57CC;
	sub_82630CA0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,-11548
	ctx.r5.s64 = ctx.r9.s64 + -11548;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B57E0;
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

__attribute__((alias("__imp__sub_827B57F4"))) PPC_WEAK_FUNC(sub_827B57F4);
PPC_FUNC_IMPL(__imp__sub_827B57F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B57F8"))) PPC_WEAK_FUNC(sub_827B57F8);
PPC_FUNC_IMPL(__imp__sub_827B57F8) {
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
	// addi r31,r11,29180
	r31.s64 = r11.s64 + 29180;
	// addi r5,r10,3328
	ctx.r5.s64 = ctx.r10.s64 + 3328;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82630ca0
	ctx.lr = 0x827B5824;
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
	ctx.lr = 0x827B5838;
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

__attribute__((alias("__imp__sub_827B584C"))) PPC_WEAK_FUNC(sub_827B584C);
PPC_FUNC_IMPL(__imp__sub_827B584C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5850"))) PPC_WEAK_FUNC(sub_827B5850);
PPC_FUNC_IMPL(__imp__sub_827B5850) {
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
	// addi r31,r11,28356
	r31.s64 = r11.s64 + 28356;
	// addi r5,r10,-10336
	ctx.r5.s64 = ctx.r10.s64 + -10336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82630ca0
	ctx.lr = 0x827B587C;
	sub_82630CA0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r9,3340
	ctx.r5.s64 = ctx.r9.s64 + 3340;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82630ca0
	ctx.lr = 0x827B5890;
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

__attribute__((alias("__imp__sub_827B58A4"))) PPC_WEAK_FUNC(sub_827B58A4);
PPC_FUNC_IMPL(__imp__sub_827B58A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B58A8"))) PPC_WEAK_FUNC(sub_827B58A8);
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

__attribute__((alias("__imp__sub_827B58FC"))) PPC_WEAK_FUNC(sub_827B58FC);
PPC_FUNC_IMPL(__imp__sub_827B58FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5900"))) PPC_WEAK_FUNC(sub_827B5900);
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

__attribute__((alias("__imp__sub_827B5918"))) PPC_WEAK_FUNC(sub_827B5918);
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

__attribute__((alias("__imp__sub_827B5980"))) PPC_WEAK_FUNC(sub_827B5980);
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

__attribute__((alias("__imp__sub_827B59E8"))) PPC_WEAK_FUNC(sub_827B59E8);
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

__attribute__((alias("__imp__sub_827B5A00"))) PPC_WEAK_FUNC(sub_827B5A00);
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

__attribute__((alias("__imp__sub_827B5A54"))) PPC_WEAK_FUNC(sub_827B5A54);
PPC_FUNC_IMPL(__imp__sub_827B5A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5A58"))) PPC_WEAK_FUNC(sub_827B5A58);
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

__attribute__((alias("__imp__sub_827B5A70"))) PPC_WEAK_FUNC(sub_827B5A70);
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

__attribute__((alias("__imp__sub_827B5A88"))) PPC_WEAK_FUNC(sub_827B5A88);
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

__attribute__((alias("__imp__sub_827B5B2C"))) PPC_WEAK_FUNC(sub_827B5B2C);
PPC_FUNC_IMPL(__imp__sub_827B5B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5B30"))) PPC_WEAK_FUNC(sub_827B5B30);
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

__attribute__((alias("__imp__sub_827B5BD4"))) PPC_WEAK_FUNC(sub_827B5BD4);
PPC_FUNC_IMPL(__imp__sub_827B5BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5BD8"))) PPC_WEAK_FUNC(sub_827B5BD8);
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

__attribute__((alias("__imp__sub_827B5C7C"))) PPC_WEAK_FUNC(sub_827B5C7C);
PPC_FUNC_IMPL(__imp__sub_827B5C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5C80"))) PPC_WEAK_FUNC(sub_827B5C80);
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

__attribute__((alias("__imp__sub_827B5D10"))) PPC_WEAK_FUNC(sub_827B5D10);
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

__attribute__((alias("__imp__sub_827B5DA0"))) PPC_WEAK_FUNC(sub_827B5DA0);
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

__attribute__((alias("__imp__sub_827B5E30"))) PPC_WEAK_FUNC(sub_827B5E30);
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

__attribute__((alias("__imp__sub_827B5E84"))) PPC_WEAK_FUNC(sub_827B5E84);
PPC_FUNC_IMPL(__imp__sub_827B5E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5E88"))) PPC_WEAK_FUNC(sub_827B5E88);
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

__attribute__((alias("__imp__sub_827B5EA0"))) PPC_WEAK_FUNC(sub_827B5EA0);
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

__attribute__((alias("__imp__sub_827B5EF4"))) PPC_WEAK_FUNC(sub_827B5EF4);
PPC_FUNC_IMPL(__imp__sub_827B5EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B5EF8"))) PPC_WEAK_FUNC(sub_827B5EF8);
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

__attribute__((alias("__imp__sub_827B5F88"))) PPC_WEAK_FUNC(sub_827B5F88);
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

__attribute__((alias("__imp__sub_827B6018"))) PPC_WEAK_FUNC(sub_827B6018);
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

__attribute__((alias("__imp__sub_827B60A8"))) PPC_WEAK_FUNC(sub_827B60A8);
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

__attribute__((alias("__imp__sub_827B6124"))) PPC_WEAK_FUNC(sub_827B6124);
PPC_FUNC_IMPL(__imp__sub_827B6124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6128"))) PPC_WEAK_FUNC(sub_827B6128);
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

__attribute__((alias("__imp__sub_827B61A4"))) PPC_WEAK_FUNC(sub_827B61A4);
PPC_FUNC_IMPL(__imp__sub_827B61A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B61A8"))) PPC_WEAK_FUNC(sub_827B61A8);
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

__attribute__((alias("__imp__sub_827B6224"))) PPC_WEAK_FUNC(sub_827B6224);
PPC_FUNC_IMPL(__imp__sub_827B6224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6228"))) PPC_WEAK_FUNC(sub_827B6228);
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

__attribute__((alias("__imp__sub_827B627C"))) PPC_WEAK_FUNC(sub_827B627C);
PPC_FUNC_IMPL(__imp__sub_827B627C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6280"))) PPC_WEAK_FUNC(sub_827B6280);
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

__attribute__((alias("__imp__sub_827B6298"))) PPC_WEAK_FUNC(sub_827B6298);
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

__attribute__((alias("__imp__sub_827B62B0"))) PPC_WEAK_FUNC(sub_827B62B0);
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

__attribute__((alias("__imp__sub_827B632C"))) PPC_WEAK_FUNC(sub_827B632C);
PPC_FUNC_IMPL(__imp__sub_827B632C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6330"))) PPC_WEAK_FUNC(sub_827B6330);
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

__attribute__((alias("__imp__sub_827B63D4"))) PPC_WEAK_FUNC(sub_827B63D4);
PPC_FUNC_IMPL(__imp__sub_827B63D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B63D8"))) PPC_WEAK_FUNC(sub_827B63D8);
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

__attribute__((alias("__imp__sub_827B6490"))) PPC_WEAK_FUNC(sub_827B6490);
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

__attribute__((alias("__imp__sub_827B64A8"))) PPC_WEAK_FUNC(sub_827B64A8);
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

__attribute__((alias("__imp__sub_827B64C0"))) PPC_WEAK_FUNC(sub_827B64C0);
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

__attribute__((alias("__imp__sub_827B6528"))) PPC_WEAK_FUNC(sub_827B6528);
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

__attribute__((alias("__imp__sub_827B6590"))) PPC_WEAK_FUNC(sub_827B6590);
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

__attribute__((alias("__imp__sub_827B65E4"))) PPC_WEAK_FUNC(sub_827B65E4);
PPC_FUNC_IMPL(__imp__sub_827B65E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B65E8"))) PPC_WEAK_FUNC(sub_827B65E8);
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

__attribute__((alias("__imp__sub_827B663C"))) PPC_WEAK_FUNC(sub_827B663C);
PPC_FUNC_IMPL(__imp__sub_827B663C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6640"))) PPC_WEAK_FUNC(sub_827B6640);
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

__attribute__((alias("__imp__sub_827B66A8"))) PPC_WEAK_FUNC(sub_827B66A8);
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

__attribute__((alias("__imp__sub_827B66FC"))) PPC_WEAK_FUNC(sub_827B66FC);
PPC_FUNC_IMPL(__imp__sub_827B66FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6700"))) PPC_WEAK_FUNC(sub_827B6700);
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

__attribute__((alias("__imp__sub_827B6754"))) PPC_WEAK_FUNC(sub_827B6754);
PPC_FUNC_IMPL(__imp__sub_827B6754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6758"))) PPC_WEAK_FUNC(sub_827B6758);
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

__attribute__((alias("__imp__sub_827B6770"))) PPC_WEAK_FUNC(sub_827B6770);
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

__attribute__((alias("__imp__sub_827B6788"))) PPC_WEAK_FUNC(sub_827B6788);
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

__attribute__((alias("__imp__sub_827B67A0"))) PPC_WEAK_FUNC(sub_827B67A0);
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

__attribute__((alias("__imp__sub_827B67F4"))) PPC_WEAK_FUNC(sub_827B67F4);
PPC_FUNC_IMPL(__imp__sub_827B67F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B67F8"))) PPC_WEAK_FUNC(sub_827B67F8);
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

__attribute__((alias("__imp__sub_827B684C"))) PPC_WEAK_FUNC(sub_827B684C);
PPC_FUNC_IMPL(__imp__sub_827B684C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6850"))) PPC_WEAK_FUNC(sub_827B6850);
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

__attribute__((alias("__imp__sub_827B6868"))) PPC_WEAK_FUNC(sub_827B6868);
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

__attribute__((alias("__imp__sub_827B6880"))) PPC_WEAK_FUNC(sub_827B6880);
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

__attribute__((alias("__imp__sub_827B6898"))) PPC_WEAK_FUNC(sub_827B6898);
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

__attribute__((alias("__imp__sub_827B68B0"))) PPC_WEAK_FUNC(sub_827B68B0);
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

__attribute__((alias("__imp__sub_827B6918"))) PPC_WEAK_FUNC(sub_827B6918);
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

__attribute__((alias("__imp__sub_827B6980"))) PPC_WEAK_FUNC(sub_827B6980);
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

__attribute__((alias("__imp__sub_827B699C"))) PPC_WEAK_FUNC(sub_827B699C);
PPC_FUNC_IMPL(__imp__sub_827B699C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B69A0"))) PPC_WEAK_FUNC(sub_827B69A0);
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

__attribute__((alias("__imp__sub_827B69BC"))) PPC_WEAK_FUNC(sub_827B69BC);
PPC_FUNC_IMPL(__imp__sub_827B69BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B69C0"))) PPC_WEAK_FUNC(sub_827B69C0);
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

__attribute__((alias("__imp__sub_827B69E0"))) PPC_WEAK_FUNC(sub_827B69E0);
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

__attribute__((alias("__imp__sub_827B6A00"))) PPC_WEAK_FUNC(sub_827B6A00);
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

__attribute__((alias("__imp__sub_827B6A20"))) PPC_WEAK_FUNC(sub_827B6A20);
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

__attribute__((alias("__imp__sub_827B6A40"))) PPC_WEAK_FUNC(sub_827B6A40);
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

__attribute__((alias("__imp__sub_827B6A60"))) PPC_WEAK_FUNC(sub_827B6A60);
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

__attribute__((alias("__imp__sub_827B6A80"))) PPC_WEAK_FUNC(sub_827B6A80);
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

__attribute__((alias("__imp__sub_827B6AA0"))) PPC_WEAK_FUNC(sub_827B6AA0);
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

__attribute__((alias("__imp__sub_827B6AC0"))) PPC_WEAK_FUNC(sub_827B6AC0);
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

__attribute__((alias("__imp__sub_827B6AE0"))) PPC_WEAK_FUNC(sub_827B6AE0);
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

__attribute__((alias("__imp__sub_827B6B00"))) PPC_WEAK_FUNC(sub_827B6B00);
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

__attribute__((alias("__imp__sub_827B6B18"))) PPC_WEAK_FUNC(sub_827B6B18);
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

__attribute__((alias("__imp__sub_827B6B38"))) PPC_WEAK_FUNC(sub_827B6B38);
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

__attribute__((alias("__imp__sub_827B6B58"))) PPC_WEAK_FUNC(sub_827B6B58);
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

__attribute__((alias("__imp__sub_827B6B74"))) PPC_WEAK_FUNC(sub_827B6B74);
PPC_FUNC_IMPL(__imp__sub_827B6B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6B78"))) PPC_WEAK_FUNC(sub_827B6B78);
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

__attribute__((alias("__imp__sub_827B6B94"))) PPC_WEAK_FUNC(sub_827B6B94);
PPC_FUNC_IMPL(__imp__sub_827B6B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6B98"))) PPC_WEAK_FUNC(sub_827B6B98);
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

__attribute__((alias("__imp__sub_827B6BB4"))) PPC_WEAK_FUNC(sub_827B6BB4);
PPC_FUNC_IMPL(__imp__sub_827B6BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6BB8"))) PPC_WEAK_FUNC(sub_827B6BB8);
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

__attribute__((alias("__imp__sub_827B6BD4"))) PPC_WEAK_FUNC(sub_827B6BD4);
PPC_FUNC_IMPL(__imp__sub_827B6BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6BD8"))) PPC_WEAK_FUNC(sub_827B6BD8);
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

__attribute__((alias("__imp__sub_827B6BF4"))) PPC_WEAK_FUNC(sub_827B6BF4);
PPC_FUNC_IMPL(__imp__sub_827B6BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6BF8"))) PPC_WEAK_FUNC(sub_827B6BF8);
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

__attribute__((alias("__imp__sub_827B6C44"))) PPC_WEAK_FUNC(sub_827B6C44);
PPC_FUNC_IMPL(__imp__sub_827B6C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6C48"))) PPC_WEAK_FUNC(sub_827B6C48);
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

__attribute__((alias("__imp__sub_827B6C64"))) PPC_WEAK_FUNC(sub_827B6C64);
PPC_FUNC_IMPL(__imp__sub_827B6C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6C68"))) PPC_WEAK_FUNC(sub_827B6C68);
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

__attribute__((alias("__imp__sub_827B6C84"))) PPC_WEAK_FUNC(sub_827B6C84);
PPC_FUNC_IMPL(__imp__sub_827B6C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6C88"))) PPC_WEAK_FUNC(sub_827B6C88);
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

__attribute__((alias("__imp__sub_827B6CA4"))) PPC_WEAK_FUNC(sub_827B6CA4);
PPC_FUNC_IMPL(__imp__sub_827B6CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6CA8"))) PPC_WEAK_FUNC(sub_827B6CA8);
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

__attribute__((alias("__imp__sub_827B6CC4"))) PPC_WEAK_FUNC(sub_827B6CC4);
PPC_FUNC_IMPL(__imp__sub_827B6CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6CC8"))) PPC_WEAK_FUNC(sub_827B6CC8);
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

__attribute__((alias("__imp__sub_827B6CE4"))) PPC_WEAK_FUNC(sub_827B6CE4);
PPC_FUNC_IMPL(__imp__sub_827B6CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6CE8"))) PPC_WEAK_FUNC(sub_827B6CE8);
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

__attribute__((alias("__imp__sub_827B6D04"))) PPC_WEAK_FUNC(sub_827B6D04);
PPC_FUNC_IMPL(__imp__sub_827B6D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827B6D08"))) PPC_WEAK_FUNC(sub_827B6D08);
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

