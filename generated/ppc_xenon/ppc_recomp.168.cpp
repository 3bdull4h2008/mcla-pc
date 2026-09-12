#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827AE110"))) PPC_WEAK_FUNC(sub_827AE110);
PPC_FUNC_IMPL(__imp__sub_827AE110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-25976
	ctx.r5.s64 = r11.s64 + -25976;
	// addi r3,r10,-8196
	ctx.r3.s64 = ctx.r10.s64 + -8196;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE12C"))) PPC_WEAK_FUNC(sub_827AE12C);
PPC_FUNC_IMPL(__imp__sub_827AE12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE130"))) PPC_WEAK_FUNC(sub_827AE130);
PPC_FUNC_IMPL(__imp__sub_827AE130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-25964
	ctx.r5.s64 = r11.s64 + -25964;
	// addi r3,r10,-8216
	ctx.r3.s64 = ctx.r10.s64 + -8216;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE14C"))) PPC_WEAK_FUNC(sub_827AE14C);
PPC_FUNC_IMPL(__imp__sub_827AE14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE150"))) PPC_WEAK_FUNC(sub_827AE150);
PPC_FUNC_IMPL(__imp__sub_827AE150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,31652
	ctx.r7.s64 = ctx.r8.s64 + 31652;
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

__attribute__((alias("__imp__sub_827AE170"))) PPC_WEAK_FUNC(sub_827AE170);
PPC_FUNC_IMPL(__imp__sub_827AE170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,32156
	ctx.r7.s64 = ctx.r8.s64 + 32156;
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

__attribute__((alias("__imp__sub_827AE190"))) PPC_WEAK_FUNC(sub_827AE190);
PPC_FUNC_IMPL(__imp__sub_827AE190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,32324
	ctx.r7.s64 = ctx.r8.s64 + 32324;
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

__attribute__((alias("__imp__sub_827AE1B0"))) PPC_WEAK_FUNC(sub_827AE1B0);
PPC_FUNC_IMPL(__imp__sub_827AE1B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-32468
	ctx.r7.s64 = ctx.r8.s64 + -32468;
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

__attribute__((alias("__imp__sub_827AE1D0"))) PPC_WEAK_FUNC(sub_827AE1D0);
PPC_FUNC_IMPL(__imp__sub_827AE1D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-15732
	ctx.r5.s64 = r11.s64 + -15732;
	// addi r3,r10,-7920
	ctx.r3.s64 = ctx.r10.s64 + -7920;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE1EC"))) PPC_WEAK_FUNC(sub_827AE1EC);
PPC_FUNC_IMPL(__imp__sub_827AE1EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE1F0"))) PPC_WEAK_FUNC(sub_827AE1F0);
PPC_FUNC_IMPL(__imp__sub_827AE1F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-30688
	ctx.r7.s64 = ctx.r8.s64 + -30688;
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

__attribute__((alias("__imp__sub_827AE210"))) PPC_WEAK_FUNC(sub_827AE210);
PPC_FUNC_IMPL(__imp__sub_827AE210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-30444
	ctx.r7.s64 = ctx.r8.s64 + -30444;
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

__attribute__((alias("__imp__sub_827AE230"))) PPC_WEAK_FUNC(sub_827AE230);
PPC_FUNC_IMPL(__imp__sub_827AE230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-30224
	ctx.r7.s64 = ctx.r8.s64 + -30224;
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

__attribute__((alias("__imp__sub_827AE250"))) PPC_WEAK_FUNC(sub_827AE250);
PPC_FUNC_IMPL(__imp__sub_827AE250) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-30008
	ctx.r7.s64 = ctx.r8.s64 + -30008;
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

__attribute__((alias("__imp__sub_827AE270"))) PPC_WEAK_FUNC(sub_827AE270);
PPC_FUNC_IMPL(__imp__sub_827AE270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-29676
	ctx.r7.s64 = ctx.r8.s64 + -29676;
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

__attribute__((alias("__imp__sub_827AE290"))) PPC_WEAK_FUNC(sub_827AE290);
PPC_FUNC_IMPL(__imp__sub_827AE290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-29012
	ctx.r7.s64 = ctx.r8.s64 + -29012;
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

__attribute__((alias("__imp__sub_827AE2B0"))) PPC_WEAK_FUNC(sub_827AE2B0);
PPC_FUNC_IMPL(__imp__sub_827AE2B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-28828
	ctx.r7.s64 = ctx.r8.s64 + -28828;
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

__attribute__((alias("__imp__sub_827AE2D0"))) PPC_WEAK_FUNC(sub_827AE2D0);
PPC_FUNC_IMPL(__imp__sub_827AE2D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-28504
	ctx.r7.s64 = ctx.r8.s64 + -28504;
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

__attribute__((alias("__imp__sub_827AE2F0"))) PPC_WEAK_FUNC(sub_827AE2F0);
PPC_FUNC_IMPL(__imp__sub_827AE2F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r7,r8,-28348
	ctx.r7.s64 = ctx.r8.s64 + -28348;
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

__attribute__((alias("__imp__sub_827AE310"))) PPC_WEAK_FUNC(sub_827AE310);
PPC_FUNC_IMPL(__imp__sub_827AE310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10204
	ctx.r5.s64 = r11.s64 + -10204;
	// addi r3,r10,-12872
	ctx.r3.s64 = ctx.r10.s64 + -12872;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE32C"))) PPC_WEAK_FUNC(sub_827AE32C);
PPC_FUNC_IMPL(__imp__sub_827AE32C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE330"))) PPC_WEAK_FUNC(sub_827AE330);
PPC_FUNC_IMPL(__imp__sub_827AE330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-10188
	ctx.r5.s64 = r11.s64 + -10188;
	// addi r3,r10,-6180
	ctx.r3.s64 = ctx.r10.s64 + -6180;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE34C"))) PPC_WEAK_FUNC(sub_827AE34C);
PPC_FUNC_IMPL(__imp__sub_827AE34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE350"))) PPC_WEAK_FUNC(sub_827AE350);
PPC_FUNC_IMPL(__imp__sub_827AE350) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10176
	ctx.r5.s64 = r11.s64 + -10176;
	// addi r3,r10,-13312
	ctx.r3.s64 = ctx.r10.s64 + -13312;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE36C"))) PPC_WEAK_FUNC(sub_827AE36C);
PPC_FUNC_IMPL(__imp__sub_827AE36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE370"))) PPC_WEAK_FUNC(sub_827AE370);
PPC_FUNC_IMPL(__imp__sub_827AE370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10160
	ctx.r5.s64 = r11.s64 + -10160;
	// addi r3,r10,-12932
	ctx.r3.s64 = ctx.r10.s64 + -12932;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE38C"))) PPC_WEAK_FUNC(sub_827AE38C);
PPC_FUNC_IMPL(__imp__sub_827AE38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE390"))) PPC_WEAK_FUNC(sub_827AE390);
PPC_FUNC_IMPL(__imp__sub_827AE390) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10144
	ctx.r5.s64 = r11.s64 + -10144;
	// addi r3,r10,-12892
	ctx.r3.s64 = ctx.r10.s64 + -12892;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE3AC"))) PPC_WEAK_FUNC(sub_827AE3AC);
PPC_FUNC_IMPL(__imp__sub_827AE3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE3B0"))) PPC_WEAK_FUNC(sub_827AE3B0);
PPC_FUNC_IMPL(__imp__sub_827AE3B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10124
	ctx.r5.s64 = r11.s64 + -10124;
	// addi r3,r10,-13852
	ctx.r3.s64 = ctx.r10.s64 + -13852;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE3CC"))) PPC_WEAK_FUNC(sub_827AE3CC);
PPC_FUNC_IMPL(__imp__sub_827AE3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE3D0"))) PPC_WEAK_FUNC(sub_827AE3D0);
PPC_FUNC_IMPL(__imp__sub_827AE3D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10108
	ctx.r5.s64 = r11.s64 + -10108;
	// addi r3,r10,-12832
	ctx.r3.s64 = ctx.r10.s64 + -12832;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE3EC"))) PPC_WEAK_FUNC(sub_827AE3EC);
PPC_FUNC_IMPL(__imp__sub_827AE3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE3F0"))) PPC_WEAK_FUNC(sub_827AE3F0);
PPC_FUNC_IMPL(__imp__sub_827AE3F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-10092
	ctx.r5.s64 = r11.s64 + -10092;
	// addi r3,r10,-6580
	ctx.r3.s64 = ctx.r10.s64 + -6580;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE40C"))) PPC_WEAK_FUNC(sub_827AE40C);
PPC_FUNC_IMPL(__imp__sub_827AE40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE410"))) PPC_WEAK_FUNC(sub_827AE410);
PPC_FUNC_IMPL(__imp__sub_827AE410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-10072
	ctx.r5.s64 = r11.s64 + -10072;
	// addi r3,r10,-6620
	ctx.r3.s64 = ctx.r10.s64 + -6620;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE42C"))) PPC_WEAK_FUNC(sub_827AE42C);
PPC_FUNC_IMPL(__imp__sub_827AE42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE430"))) PPC_WEAK_FUNC(sub_827AE430);
PPC_FUNC_IMPL(__imp__sub_827AE430) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10052
	ctx.r5.s64 = r11.s64 + -10052;
	// addi r3,r10,-13560
	ctx.r3.s64 = ctx.r10.s64 + -13560;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE44C"))) PPC_WEAK_FUNC(sub_827AE44C);
PPC_FUNC_IMPL(__imp__sub_827AE44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE450"))) PPC_WEAK_FUNC(sub_827AE450);
PPC_FUNC_IMPL(__imp__sub_827AE450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10044
	ctx.r5.s64 = r11.s64 + -10044;
	// addi r3,r10,-13092
	ctx.r3.s64 = ctx.r10.s64 + -13092;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE46C"))) PPC_WEAK_FUNC(sub_827AE46C);
PPC_FUNC_IMPL(__imp__sub_827AE46C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE470"))) PPC_WEAK_FUNC(sub_827AE470);
PPC_FUNC_IMPL(__imp__sub_827AE470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-10028
	ctx.r5.s64 = r11.s64 + -10028;
	// addi r3,r10,-6260
	ctx.r3.s64 = ctx.r10.s64 + -6260;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE48C"))) PPC_WEAK_FUNC(sub_827AE48C);
PPC_FUNC_IMPL(__imp__sub_827AE48C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE490"))) PPC_WEAK_FUNC(sub_827AE490);
PPC_FUNC_IMPL(__imp__sub_827AE490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10012
	ctx.r5.s64 = r11.s64 + -10012;
	// addi r3,r10,-13792
	ctx.r3.s64 = ctx.r10.s64 + -13792;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE4AC"))) PPC_WEAK_FUNC(sub_827AE4AC);
PPC_FUNC_IMPL(__imp__sub_827AE4AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE4B0"))) PPC_WEAK_FUNC(sub_827AE4B0);
PPC_FUNC_IMPL(__imp__sub_827AE4B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-10000
	ctx.r5.s64 = r11.s64 + -10000;
	// addi r3,r10,-13620
	ctx.r3.s64 = ctx.r10.s64 + -13620;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE4CC"))) PPC_WEAK_FUNC(sub_827AE4CC);
PPC_FUNC_IMPL(__imp__sub_827AE4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE4D0"))) PPC_WEAK_FUNC(sub_827AE4D0);
PPC_FUNC_IMPL(__imp__sub_827AE4D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9980
	ctx.r5.s64 = r11.s64 + -9980;
	// addi r3,r10,-13072
	ctx.r3.s64 = ctx.r10.s64 + -13072;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE4EC"))) PPC_WEAK_FUNC(sub_827AE4EC);
PPC_FUNC_IMPL(__imp__sub_827AE4EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE4F0"))) PPC_WEAK_FUNC(sub_827AE4F0);
PPC_FUNC_IMPL(__imp__sub_827AE4F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9960
	ctx.r5.s64 = r11.s64 + -9960;
	// addi r3,r10,-13952
	ctx.r3.s64 = ctx.r10.s64 + -13952;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE50C"))) PPC_WEAK_FUNC(sub_827AE50C);
PPC_FUNC_IMPL(__imp__sub_827AE50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE510"))) PPC_WEAK_FUNC(sub_827AE510);
PPC_FUNC_IMPL(__imp__sub_827AE510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9940
	ctx.r5.s64 = r11.s64 + -9940;
	// addi r3,r10,-13640
	ctx.r3.s64 = ctx.r10.s64 + -13640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE52C"))) PPC_WEAK_FUNC(sub_827AE52C);
PPC_FUNC_IMPL(__imp__sub_827AE52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE530"))) PPC_WEAK_FUNC(sub_827AE530);
PPC_FUNC_IMPL(__imp__sub_827AE530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9920
	ctx.r5.s64 = r11.s64 + -9920;
	// addi r3,r10,-13052
	ctx.r3.s64 = ctx.r10.s64 + -13052;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE54C"))) PPC_WEAK_FUNC(sub_827AE54C);
PPC_FUNC_IMPL(__imp__sub_827AE54C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE550"))) PPC_WEAK_FUNC(sub_827AE550);
PPC_FUNC_IMPL(__imp__sub_827AE550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9892
	ctx.r5.s64 = r11.s64 + -9892;
	// addi r3,r10,-12752
	ctx.r3.s64 = ctx.r10.s64 + -12752;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE56C"))) PPC_WEAK_FUNC(sub_827AE56C);
PPC_FUNC_IMPL(__imp__sub_827AE56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE570"))) PPC_WEAK_FUNC(sub_827AE570);
PPC_FUNC_IMPL(__imp__sub_827AE570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9868
	ctx.r5.s64 = r11.s64 + -9868;
	// addi r3,r10,-12852
	ctx.r3.s64 = ctx.r10.s64 + -12852;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE58C"))) PPC_WEAK_FUNC(sub_827AE58C);
PPC_FUNC_IMPL(__imp__sub_827AE58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE590"))) PPC_WEAK_FUNC(sub_827AE590);
PPC_FUNC_IMPL(__imp__sub_827AE590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9844
	ctx.r5.s64 = r11.s64 + -9844;
	// addi r3,r10,-6280
	ctx.r3.s64 = ctx.r10.s64 + -6280;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE5AC"))) PPC_WEAK_FUNC(sub_827AE5AC);
PPC_FUNC_IMPL(__imp__sub_827AE5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE5B0"))) PPC_WEAK_FUNC(sub_827AE5B0);
PPC_FUNC_IMPL(__imp__sub_827AE5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9824
	ctx.r5.s64 = r11.s64 + -9824;
	// addi r3,r10,-13352
	ctx.r3.s64 = ctx.r10.s64 + -13352;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE5CC"))) PPC_WEAK_FUNC(sub_827AE5CC);
PPC_FUNC_IMPL(__imp__sub_827AE5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE5D0"))) PPC_WEAK_FUNC(sub_827AE5D0);
PPC_FUNC_IMPL(__imp__sub_827AE5D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9800
	ctx.r5.s64 = r11.s64 + -9800;
	// addi r3,r10,-13252
	ctx.r3.s64 = ctx.r10.s64 + -13252;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE5EC"))) PPC_WEAK_FUNC(sub_827AE5EC);
PPC_FUNC_IMPL(__imp__sub_827AE5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE5F0"))) PPC_WEAK_FUNC(sub_827AE5F0);
PPC_FUNC_IMPL(__imp__sub_827AE5F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9776
	ctx.r5.s64 = r11.s64 + -9776;
	// addi r3,r10,-6440
	ctx.r3.s64 = ctx.r10.s64 + -6440;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE60C"))) PPC_WEAK_FUNC(sub_827AE60C);
PPC_FUNC_IMPL(__imp__sub_827AE60C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE610"))) PPC_WEAK_FUNC(sub_827AE610);
PPC_FUNC_IMPL(__imp__sub_827AE610) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9752
	ctx.r5.s64 = r11.s64 + -9752;
	// addi r3,r10,-13540
	ctx.r3.s64 = ctx.r10.s64 + -13540;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE62C"))) PPC_WEAK_FUNC(sub_827AE62C);
PPC_FUNC_IMPL(__imp__sub_827AE62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE630"))) PPC_WEAK_FUNC(sub_827AE630);
PPC_FUNC_IMPL(__imp__sub_827AE630) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9728
	ctx.r5.s64 = r11.s64 + -9728;
	// addi r3,r10,-6100
	ctx.r3.s64 = ctx.r10.s64 + -6100;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE64C"))) PPC_WEAK_FUNC(sub_827AE64C);
PPC_FUNC_IMPL(__imp__sub_827AE64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE650"))) PPC_WEAK_FUNC(sub_827AE650);
PPC_FUNC_IMPL(__imp__sub_827AE650) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9704
	ctx.r5.s64 = r11.s64 + -9704;
	// addi r3,r10,-6480
	ctx.r3.s64 = ctx.r10.s64 + -6480;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE66C"))) PPC_WEAK_FUNC(sub_827AE66C);
PPC_FUNC_IMPL(__imp__sub_827AE66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE670"))) PPC_WEAK_FUNC(sub_827AE670);
PPC_FUNC_IMPL(__imp__sub_827AE670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9680
	ctx.r5.s64 = r11.s64 + -9680;
	// addi r3,r10,-13292
	ctx.r3.s64 = ctx.r10.s64 + -13292;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE68C"))) PPC_WEAK_FUNC(sub_827AE68C);
PPC_FUNC_IMPL(__imp__sub_827AE68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE690"))) PPC_WEAK_FUNC(sub_827AE690);
PPC_FUNC_IMPL(__imp__sub_827AE690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9656
	ctx.r5.s64 = r11.s64 + -9656;
	// addi r3,r10,-13432
	ctx.r3.s64 = ctx.r10.s64 + -13432;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE6AC"))) PPC_WEAK_FUNC(sub_827AE6AC);
PPC_FUNC_IMPL(__imp__sub_827AE6AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE6B0"))) PPC_WEAK_FUNC(sub_827AE6B0);
PPC_FUNC_IMPL(__imp__sub_827AE6B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9632
	ctx.r5.s64 = r11.s64 + -9632;
	// addi r3,r10,-5900
	ctx.r3.s64 = ctx.r10.s64 + -5900;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE6CC"))) PPC_WEAK_FUNC(sub_827AE6CC);
PPC_FUNC_IMPL(__imp__sub_827AE6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE6D0"))) PPC_WEAK_FUNC(sub_827AE6D0);
PPC_FUNC_IMPL(__imp__sub_827AE6D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9612
	ctx.r5.s64 = r11.s64 + -9612;
	// addi r3,r10,-12992
	ctx.r3.s64 = ctx.r10.s64 + -12992;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE6EC"))) PPC_WEAK_FUNC(sub_827AE6EC);
PPC_FUNC_IMPL(__imp__sub_827AE6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE6F0"))) PPC_WEAK_FUNC(sub_827AE6F0);
PPC_FUNC_IMPL(__imp__sub_827AE6F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9600
	ctx.r5.s64 = r11.s64 + -9600;
	// addi r3,r10,-6220
	ctx.r3.s64 = ctx.r10.s64 + -6220;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE70C"))) PPC_WEAK_FUNC(sub_827AE70C);
PPC_FUNC_IMPL(__imp__sub_827AE70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE710"))) PPC_WEAK_FUNC(sub_827AE710);
PPC_FUNC_IMPL(__imp__sub_827AE710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9580
	ctx.r5.s64 = r11.s64 + -9580;
	// addi r3,r10,-13812
	ctx.r3.s64 = ctx.r10.s64 + -13812;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE72C"))) PPC_WEAK_FUNC(sub_827AE72C);
PPC_FUNC_IMPL(__imp__sub_827AE72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE730"))) PPC_WEAK_FUNC(sub_827AE730);
PPC_FUNC_IMPL(__imp__sub_827AE730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9564
	ctx.r5.s64 = r11.s64 + -9564;
	// addi r3,r10,-6140
	ctx.r3.s64 = ctx.r10.s64 + -6140;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE74C"))) PPC_WEAK_FUNC(sub_827AE74C);
PPC_FUNC_IMPL(__imp__sub_827AE74C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE750"))) PPC_WEAK_FUNC(sub_827AE750);
PPC_FUNC_IMPL(__imp__sub_827AE750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9548
	ctx.r5.s64 = r11.s64 + -9548;
	// addi r3,r10,-5960
	ctx.r3.s64 = ctx.r10.s64 + -5960;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE76C"))) PPC_WEAK_FUNC(sub_827AE76C);
PPC_FUNC_IMPL(__imp__sub_827AE76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE770"))) PPC_WEAK_FUNC(sub_827AE770);
PPC_FUNC_IMPL(__imp__sub_827AE770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9532
	ctx.r5.s64 = r11.s64 + -9532;
	// addi r3,r10,-6040
	ctx.r3.s64 = ctx.r10.s64 + -6040;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE78C"))) PPC_WEAK_FUNC(sub_827AE78C);
PPC_FUNC_IMPL(__imp__sub_827AE78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE790"))) PPC_WEAK_FUNC(sub_827AE790);
PPC_FUNC_IMPL(__imp__sub_827AE790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9516
	ctx.r5.s64 = r11.s64 + -9516;
	// addi r3,r10,-13272
	ctx.r3.s64 = ctx.r10.s64 + -13272;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE7AC"))) PPC_WEAK_FUNC(sub_827AE7AC);
PPC_FUNC_IMPL(__imp__sub_827AE7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE7B0"))) PPC_WEAK_FUNC(sub_827AE7B0);
PPC_FUNC_IMPL(__imp__sub_827AE7B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9496
	ctx.r5.s64 = r11.s64 + -9496;
	// addi r3,r10,-6240
	ctx.r3.s64 = ctx.r10.s64 + -6240;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE7CC"))) PPC_WEAK_FUNC(sub_827AE7CC);
PPC_FUNC_IMPL(__imp__sub_827AE7CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE7D0"))) PPC_WEAK_FUNC(sub_827AE7D0);
PPC_FUNC_IMPL(__imp__sub_827AE7D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9476
	ctx.r5.s64 = r11.s64 + -9476;
	// addi r3,r10,-13392
	ctx.r3.s64 = ctx.r10.s64 + -13392;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE7EC"))) PPC_WEAK_FUNC(sub_827AE7EC);
PPC_FUNC_IMPL(__imp__sub_827AE7EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE7F0"))) PPC_WEAK_FUNC(sub_827AE7F0);
PPC_FUNC_IMPL(__imp__sub_827AE7F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9460
	ctx.r5.s64 = r11.s64 + -9460;
	// addi r3,r10,-6120
	ctx.r3.s64 = ctx.r10.s64 + -6120;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE80C"))) PPC_WEAK_FUNC(sub_827AE80C);
PPC_FUNC_IMPL(__imp__sub_827AE80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE810"))) PPC_WEAK_FUNC(sub_827AE810);
PPC_FUNC_IMPL(__imp__sub_827AE810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9444
	ctx.r5.s64 = r11.s64 + -9444;
	// addi r3,r10,-13932
	ctx.r3.s64 = ctx.r10.s64 + -13932;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE82C"))) PPC_WEAK_FUNC(sub_827AE82C);
PPC_FUNC_IMPL(__imp__sub_827AE82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE830"))) PPC_WEAK_FUNC(sub_827AE830);
PPC_FUNC_IMPL(__imp__sub_827AE830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9432
	ctx.r5.s64 = r11.s64 + -9432;
	// addi r3,r10,-13412
	ctx.r3.s64 = ctx.r10.s64 + -13412;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE84C"))) PPC_WEAK_FUNC(sub_827AE84C);
PPC_FUNC_IMPL(__imp__sub_827AE84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE850"))) PPC_WEAK_FUNC(sub_827AE850);
PPC_FUNC_IMPL(__imp__sub_827AE850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9412
	ctx.r5.s64 = r11.s64 + -9412;
	// addi r3,r10,-6000
	ctx.r3.s64 = ctx.r10.s64 + -6000;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE86C"))) PPC_WEAK_FUNC(sub_827AE86C);
PPC_FUNC_IMPL(__imp__sub_827AE86C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE870"))) PPC_WEAK_FUNC(sub_827AE870);
PPC_FUNC_IMPL(__imp__sub_827AE870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9400
	ctx.r5.s64 = r11.s64 + -9400;
	// addi r3,r10,-13112
	ctx.r3.s64 = ctx.r10.s64 + -13112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE88C"))) PPC_WEAK_FUNC(sub_827AE88C);
PPC_FUNC_IMPL(__imp__sub_827AE88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE890"))) PPC_WEAK_FUNC(sub_827AE890);
PPC_FUNC_IMPL(__imp__sub_827AE890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9380
	ctx.r5.s64 = r11.s64 + -9380;
	// addi r3,r10,-6540
	ctx.r3.s64 = ctx.r10.s64 + -6540;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE8AC"))) PPC_WEAK_FUNC(sub_827AE8AC);
PPC_FUNC_IMPL(__imp__sub_827AE8AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE8B0"))) PPC_WEAK_FUNC(sub_827AE8B0);
PPC_FUNC_IMPL(__imp__sub_827AE8B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9372
	ctx.r5.s64 = r11.s64 + -9372;
	// addi r3,r10,-12812
	ctx.r3.s64 = ctx.r10.s64 + -12812;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE8CC"))) PPC_WEAK_FUNC(sub_827AE8CC);
PPC_FUNC_IMPL(__imp__sub_827AE8CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE8D0"))) PPC_WEAK_FUNC(sub_827AE8D0);
PPC_FUNC_IMPL(__imp__sub_827AE8D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9364
	ctx.r5.s64 = r11.s64 + -9364;
	// addi r3,r10,-13600
	ctx.r3.s64 = ctx.r10.s64 + -13600;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE8EC"))) PPC_WEAK_FUNC(sub_827AE8EC);
PPC_FUNC_IMPL(__imp__sub_827AE8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE8F0"))) PPC_WEAK_FUNC(sub_827AE8F0);
PPC_FUNC_IMPL(__imp__sub_827AE8F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9352
	ctx.r5.s64 = r11.s64 + -9352;
	// addi r3,r10,-13512
	ctx.r3.s64 = ctx.r10.s64 + -13512;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE90C"))) PPC_WEAK_FUNC(sub_827AE90C);
PPC_FUNC_IMPL(__imp__sub_827AE90C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE910"))) PPC_WEAK_FUNC(sub_827AE910);
PPC_FUNC_IMPL(__imp__sub_827AE910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9344
	ctx.r5.s64 = r11.s64 + -9344;
	// addi r3,r10,-5920
	ctx.r3.s64 = ctx.r10.s64 + -5920;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE92C"))) PPC_WEAK_FUNC(sub_827AE92C);
PPC_FUNC_IMPL(__imp__sub_827AE92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE930"))) PPC_WEAK_FUNC(sub_827AE930);
PPC_FUNC_IMPL(__imp__sub_827AE930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9336
	ctx.r5.s64 = r11.s64 + -9336;
	// addi r3,r10,-6640
	ctx.r3.s64 = ctx.r10.s64 + -6640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE94C"))) PPC_WEAK_FUNC(sub_827AE94C);
PPC_FUNC_IMPL(__imp__sub_827AE94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE950"))) PPC_WEAK_FUNC(sub_827AE950);
PPC_FUNC_IMPL(__imp__sub_827AE950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9324
	ctx.r5.s64 = r11.s64 + -9324;
	// addi r3,r10,-13332
	ctx.r3.s64 = ctx.r10.s64 + -13332;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE96C"))) PPC_WEAK_FUNC(sub_827AE96C);
PPC_FUNC_IMPL(__imp__sub_827AE96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE970"))) PPC_WEAK_FUNC(sub_827AE970);
PPC_FUNC_IMPL(__imp__sub_827AE970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9312
	ctx.r5.s64 = r11.s64 + -9312;
	// addi r3,r10,-13660
	ctx.r3.s64 = ctx.r10.s64 + -13660;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE98C"))) PPC_WEAK_FUNC(sub_827AE98C);
PPC_FUNC_IMPL(__imp__sub_827AE98C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE990"))) PPC_WEAK_FUNC(sub_827AE990);
PPC_FUNC_IMPL(__imp__sub_827AE990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9300
	ctx.r5.s64 = r11.s64 + -9300;
	// addi r3,r10,-13032
	ctx.r3.s64 = ctx.r10.s64 + -13032;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE9AC"))) PPC_WEAK_FUNC(sub_827AE9AC);
PPC_FUNC_IMPL(__imp__sub_827AE9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE9B0"))) PPC_WEAK_FUNC(sub_827AE9B0);
PPC_FUNC_IMPL(__imp__sub_827AE9B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9292
	ctx.r5.s64 = r11.s64 + -9292;
	// addi r3,r10,-13172
	ctx.r3.s64 = ctx.r10.s64 + -13172;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE9CC"))) PPC_WEAK_FUNC(sub_827AE9CC);
PPC_FUNC_IMPL(__imp__sub_827AE9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE9D0"))) PPC_WEAK_FUNC(sub_827AE9D0);
PPC_FUNC_IMPL(__imp__sub_827AE9D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9280
	ctx.r5.s64 = r11.s64 + -9280;
	// addi r3,r10,-6600
	ctx.r3.s64 = ctx.r10.s64 + -6600;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AE9EC"))) PPC_WEAK_FUNC(sub_827AE9EC);
PPC_FUNC_IMPL(__imp__sub_827AE9EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AE9F0"))) PPC_WEAK_FUNC(sub_827AE9F0);
PPC_FUNC_IMPL(__imp__sub_827AE9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9264
	ctx.r5.s64 = r11.s64 + -9264;
	// addi r3,r10,-12952
	ctx.r3.s64 = ctx.r10.s64 + -12952;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEA0C"))) PPC_WEAK_FUNC(sub_827AEA0C);
PPC_FUNC_IMPL(__imp__sub_827AEA0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEA10"))) PPC_WEAK_FUNC(sub_827AEA10);
PPC_FUNC_IMPL(__imp__sub_827AEA10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9256
	ctx.r5.s64 = r11.s64 + -9256;
	// addi r3,r10,-12972
	ctx.r3.s64 = ctx.r10.s64 + -12972;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEA2C"))) PPC_WEAK_FUNC(sub_827AEA2C);
PPC_FUNC_IMPL(__imp__sub_827AEA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEA30"))) PPC_WEAK_FUNC(sub_827AEA30);
PPC_FUNC_IMPL(__imp__sub_827AEA30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9244
	ctx.r5.s64 = r11.s64 + -9244;
	// addi r3,r10,-5880
	ctx.r3.s64 = ctx.r10.s64 + -5880;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEA4C"))) PPC_WEAK_FUNC(sub_827AEA4C);
PPC_FUNC_IMPL(__imp__sub_827AEA4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEA50"))) PPC_WEAK_FUNC(sub_827AEA50);
PPC_FUNC_IMPL(__imp__sub_827AEA50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9232
	ctx.r5.s64 = r11.s64 + -9232;
	// addi r3,r10,-6460
	ctx.r3.s64 = ctx.r10.s64 + -6460;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEA6C"))) PPC_WEAK_FUNC(sub_827AEA6C);
PPC_FUNC_IMPL(__imp__sub_827AEA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEA70"))) PPC_WEAK_FUNC(sub_827AEA70);
PPC_FUNC_IMPL(__imp__sub_827AEA70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9220
	ctx.r5.s64 = r11.s64 + -9220;
	// addi r3,r10,-6020
	ctx.r3.s64 = ctx.r10.s64 + -6020;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEA8C"))) PPC_WEAK_FUNC(sub_827AEA8C);
PPC_FUNC_IMPL(__imp__sub_827AEA8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEA90"))) PPC_WEAK_FUNC(sub_827AEA90);
PPC_FUNC_IMPL(__imp__sub_827AEA90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9208
	ctx.r5.s64 = r11.s64 + -9208;
	// addi r3,r10,-13720
	ctx.r3.s64 = ctx.r10.s64 + -13720;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEAAC"))) PPC_WEAK_FUNC(sub_827AEAAC);
PPC_FUNC_IMPL(__imp__sub_827AEAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEAB0"))) PPC_WEAK_FUNC(sub_827AEAB0);
PPC_FUNC_IMPL(__imp__sub_827AEAB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9196
	ctx.r5.s64 = r11.s64 + -9196;
	// addi r3,r10,-6080
	ctx.r3.s64 = ctx.r10.s64 + -6080;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEACC"))) PPC_WEAK_FUNC(sub_827AEACC);
PPC_FUNC_IMPL(__imp__sub_827AEACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEAD0"))) PPC_WEAK_FUNC(sub_827AEAD0);
PPC_FUNC_IMPL(__imp__sub_827AEAD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9184
	ctx.r5.s64 = r11.s64 + -9184;
	// addi r3,r10,-13132
	ctx.r3.s64 = ctx.r10.s64 + -13132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEAEC"))) PPC_WEAK_FUNC(sub_827AEAEC);
PPC_FUNC_IMPL(__imp__sub_827AEAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEAF0"))) PPC_WEAK_FUNC(sub_827AEAF0);
PPC_FUNC_IMPL(__imp__sub_827AEAF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9172
	ctx.r5.s64 = r11.s64 + -9172;
	// addi r3,r10,-6060
	ctx.r3.s64 = ctx.r10.s64 + -6060;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEB0C"))) PPC_WEAK_FUNC(sub_827AEB0C);
PPC_FUNC_IMPL(__imp__sub_827AEB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEB10"))) PPC_WEAK_FUNC(sub_827AEB10);
PPC_FUNC_IMPL(__imp__sub_827AEB10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9160
	ctx.r5.s64 = r11.s64 + -9160;
	// addi r3,r10,-6360
	ctx.r3.s64 = ctx.r10.s64 + -6360;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEB2C"))) PPC_WEAK_FUNC(sub_827AEB2C);
PPC_FUNC_IMPL(__imp__sub_827AEB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEB30"))) PPC_WEAK_FUNC(sub_827AEB30);
PPC_FUNC_IMPL(__imp__sub_827AEB30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9148
	ctx.r5.s64 = r11.s64 + -9148;
	// addi r3,r10,-6500
	ctx.r3.s64 = ctx.r10.s64 + -6500;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEB4C"))) PPC_WEAK_FUNC(sub_827AEB4C);
PPC_FUNC_IMPL(__imp__sub_827AEB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEB50"))) PPC_WEAK_FUNC(sub_827AEB50);
PPC_FUNC_IMPL(__imp__sub_827AEB50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9132
	ctx.r5.s64 = r11.s64 + -9132;
	// addi r3,r10,-13740
	ctx.r3.s64 = ctx.r10.s64 + -13740;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEB6C"))) PPC_WEAK_FUNC(sub_827AEB6C);
PPC_FUNC_IMPL(__imp__sub_827AEB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEB70"))) PPC_WEAK_FUNC(sub_827AEB70);
PPC_FUNC_IMPL(__imp__sub_827AEB70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9128
	ctx.r5.s64 = r11.s64 + -9128;
	// addi r3,r10,-6320
	ctx.r3.s64 = ctx.r10.s64 + -6320;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEB8C"))) PPC_WEAK_FUNC(sub_827AEB8C);
PPC_FUNC_IMPL(__imp__sub_827AEB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEB90"))) PPC_WEAK_FUNC(sub_827AEB90);
PPC_FUNC_IMPL(__imp__sub_827AEB90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9112
	ctx.r5.s64 = r11.s64 + -9112;
	// addi r3,r10,-13760
	ctx.r3.s64 = ctx.r10.s64 + -13760;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEBAC"))) PPC_WEAK_FUNC(sub_827AEBAC);
PPC_FUNC_IMPL(__imp__sub_827AEBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEBB0"))) PPC_WEAK_FUNC(sub_827AEBB0);
PPC_FUNC_IMPL(__imp__sub_827AEBB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9104
	ctx.r5.s64 = r11.s64 + -9104;
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

__attribute__((alias("__imp__sub_827AEBCC"))) PPC_WEAK_FUNC(sub_827AEBCC);
PPC_FUNC_IMPL(__imp__sub_827AEBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEBD0"))) PPC_WEAK_FUNC(sub_827AEBD0);
PPC_FUNC_IMPL(__imp__sub_827AEBD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9096
	ctx.r5.s64 = r11.s64 + -9096;
	// addi r3,r10,-6300
	ctx.r3.s64 = ctx.r10.s64 + -6300;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEBEC"))) PPC_WEAK_FUNC(sub_827AEBEC);
PPC_FUNC_IMPL(__imp__sub_827AEBEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEBF0"))) PPC_WEAK_FUNC(sub_827AEBF0);
PPC_FUNC_IMPL(__imp__sub_827AEBF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9080
	ctx.r5.s64 = r11.s64 + -9080;
	// addi r3,r10,-5980
	ctx.r3.s64 = ctx.r10.s64 + -5980;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEC0C"))) PPC_WEAK_FUNC(sub_827AEC0C);
PPC_FUNC_IMPL(__imp__sub_827AEC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEC10"))) PPC_WEAK_FUNC(sub_827AEC10);
PPC_FUNC_IMPL(__imp__sub_827AEC10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9068
	ctx.r5.s64 = r11.s64 + -9068;
	// addi r3,r10,-13680
	ctx.r3.s64 = ctx.r10.s64 + -13680;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEC2C"))) PPC_WEAK_FUNC(sub_827AEC2C);
PPC_FUNC_IMPL(__imp__sub_827AEC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEC30"))) PPC_WEAK_FUNC(sub_827AEC30);
PPC_FUNC_IMPL(__imp__sub_827AEC30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9052
	ctx.r5.s64 = r11.s64 + -9052;
	// addi r3,r10,-12772
	ctx.r3.s64 = ctx.r10.s64 + -12772;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEC4C"))) PPC_WEAK_FUNC(sub_827AEC4C);
PPC_FUNC_IMPL(__imp__sub_827AEC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEC50"))) PPC_WEAK_FUNC(sub_827AEC50);
PPC_FUNC_IMPL(__imp__sub_827AEC50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9036
	ctx.r5.s64 = r11.s64 + -9036;
	// addi r3,r10,-13872
	ctx.r3.s64 = ctx.r10.s64 + -13872;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEC6C"))) PPC_WEAK_FUNC(sub_827AEC6C);
PPC_FUNC_IMPL(__imp__sub_827AEC6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEC70"))) PPC_WEAK_FUNC(sub_827AEC70);
PPC_FUNC_IMPL(__imp__sub_827AEC70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-9020
	ctx.r5.s64 = r11.s64 + -9020;
	// addi r3,r10,-12732
	ctx.r3.s64 = ctx.r10.s64 + -12732;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEC8C"))) PPC_WEAK_FUNC(sub_827AEC8C);
PPC_FUNC_IMPL(__imp__sub_827AEC8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEC90"))) PPC_WEAK_FUNC(sub_827AEC90);
PPC_FUNC_IMPL(__imp__sub_827AEC90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-9004
	ctx.r5.s64 = r11.s64 + -9004;
	// addi r3,r10,-6520
	ctx.r3.s64 = ctx.r10.s64 + -6520;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AECAC"))) PPC_WEAK_FUNC(sub_827AECAC);
PPC_FUNC_IMPL(__imp__sub_827AECAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AECB0"))) PPC_WEAK_FUNC(sub_827AECB0);
PPC_FUNC_IMPL(__imp__sub_827AECB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8992
	ctx.r5.s64 = r11.s64 + -8992;
	// addi r3,r10,-6400
	ctx.r3.s64 = ctx.r10.s64 + -6400;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AECCC"))) PPC_WEAK_FUNC(sub_827AECCC);
PPC_FUNC_IMPL(__imp__sub_827AECCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AECD0"))) PPC_WEAK_FUNC(sub_827AECD0);
PPC_FUNC_IMPL(__imp__sub_827AECD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8972
	ctx.r5.s64 = r11.s64 + -8972;
	// addi r3,r10,-13152
	ctx.r3.s64 = ctx.r10.s64 + -13152;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AECEC"))) PPC_WEAK_FUNC(sub_827AECEC);
PPC_FUNC_IMPL(__imp__sub_827AECEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AECF0"))) PPC_WEAK_FUNC(sub_827AECF0);
PPC_FUNC_IMPL(__imp__sub_827AECF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8952
	ctx.r5.s64 = r11.s64 + -8952;
	// addi r3,r10,-13912
	ctx.r3.s64 = ctx.r10.s64 + -13912;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AED0C"))) PPC_WEAK_FUNC(sub_827AED0C);
PPC_FUNC_IMPL(__imp__sub_827AED0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AED10"))) PPC_WEAK_FUNC(sub_827AED10);
PPC_FUNC_IMPL(__imp__sub_827AED10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,3656
	ctx.r5.s64 = r11.s64 + 3656;
	// addi r3,r10,-13012
	ctx.r3.s64 = ctx.r10.s64 + -13012;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AED2C"))) PPC_WEAK_FUNC(sub_827AED2C);
PPC_FUNC_IMPL(__imp__sub_827AED2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AED30"))) PPC_WEAK_FUNC(sub_827AED30);
PPC_FUNC_IMPL(__imp__sub_827AED30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8940
	ctx.r5.s64 = r11.s64 + -8940;
	// addi r3,r10,-13452
	ctx.r3.s64 = ctx.r10.s64 + -13452;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AED4C"))) PPC_WEAK_FUNC(sub_827AED4C);
PPC_FUNC_IMPL(__imp__sub_827AED4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AED50"))) PPC_WEAK_FUNC(sub_827AED50);
PPC_FUNC_IMPL(__imp__sub_827AED50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8932
	ctx.r5.s64 = r11.s64 + -8932;
	// addi r3,r10,-6340
	ctx.r3.s64 = ctx.r10.s64 + -6340;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AED6C"))) PPC_WEAK_FUNC(sub_827AED6C);
PPC_FUNC_IMPL(__imp__sub_827AED6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AED70"))) PPC_WEAK_FUNC(sub_827AED70);
PPC_FUNC_IMPL(__imp__sub_827AED70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8920
	ctx.r5.s64 = r11.s64 + -8920;
	// addi r3,r10,-13212
	ctx.r3.s64 = ctx.r10.s64 + -13212;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AED8C"))) PPC_WEAK_FUNC(sub_827AED8C);
PPC_FUNC_IMPL(__imp__sub_827AED8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AED90"))) PPC_WEAK_FUNC(sub_827AED90);
PPC_FUNC_IMPL(__imp__sub_827AED90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8912
	ctx.r5.s64 = r11.s64 + -8912;
	// addi r3,r10,-13580
	ctx.r3.s64 = ctx.r10.s64 + -13580;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEDAC"))) PPC_WEAK_FUNC(sub_827AEDAC);
PPC_FUNC_IMPL(__imp__sub_827AEDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEDB0"))) PPC_WEAK_FUNC(sub_827AEDB0);
PPC_FUNC_IMPL(__imp__sub_827AEDB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8904
	ctx.r5.s64 = r11.s64 + -8904;
	// addi r3,r10,-13472
	ctx.r3.s64 = ctx.r10.s64 + -13472;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEDCC"))) PPC_WEAK_FUNC(sub_827AEDCC);
PPC_FUNC_IMPL(__imp__sub_827AEDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEDD0"))) PPC_WEAK_FUNC(sub_827AEDD0);
PPC_FUNC_IMPL(__imp__sub_827AEDD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8892
	ctx.r5.s64 = r11.s64 + -8892;
	// addi r3,r10,-6660
	ctx.r3.s64 = ctx.r10.s64 + -6660;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEDEC"))) PPC_WEAK_FUNC(sub_827AEDEC);
PPC_FUNC_IMPL(__imp__sub_827AEDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEDF0"))) PPC_WEAK_FUNC(sub_827AEDF0);
PPC_FUNC_IMPL(__imp__sub_827AEDF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8880
	ctx.r5.s64 = r11.s64 + -8880;
	// addi r3,r10,-13232
	ctx.r3.s64 = ctx.r10.s64 + -13232;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEE0C"))) PPC_WEAK_FUNC(sub_827AEE0C);
PPC_FUNC_IMPL(__imp__sub_827AEE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEE10"))) PPC_WEAK_FUNC(sub_827AEE10);
PPC_FUNC_IMPL(__imp__sub_827AEE10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8868
	ctx.r5.s64 = r11.s64 + -8868;
	// addi r3,r10,-6160
	ctx.r3.s64 = ctx.r10.s64 + -6160;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEE2C"))) PPC_WEAK_FUNC(sub_827AEE2C);
PPC_FUNC_IMPL(__imp__sub_827AEE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEE30"))) PPC_WEAK_FUNC(sub_827AEE30);
PPC_FUNC_IMPL(__imp__sub_827AEE30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8856
	ctx.r5.s64 = r11.s64 + -8856;
	// addi r3,r10,-6380
	ctx.r3.s64 = ctx.r10.s64 + -6380;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEE4C"))) PPC_WEAK_FUNC(sub_827AEE4C);
PPC_FUNC_IMPL(__imp__sub_827AEE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEE50"))) PPC_WEAK_FUNC(sub_827AEE50);
PPC_FUNC_IMPL(__imp__sub_827AEE50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8844
	ctx.r5.s64 = r11.s64 + -8844;
	// addi r3,r10,-6560
	ctx.r3.s64 = ctx.r10.s64 + -6560;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEE6C"))) PPC_WEAK_FUNC(sub_827AEE6C);
PPC_FUNC_IMPL(__imp__sub_827AEE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEE70"))) PPC_WEAK_FUNC(sub_827AEE70);
PPC_FUNC_IMPL(__imp__sub_827AEE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8832
	ctx.r5.s64 = r11.s64 + -8832;
	// addi r3,r10,-12792
	ctx.r3.s64 = ctx.r10.s64 + -12792;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEE8C"))) PPC_WEAK_FUNC(sub_827AEE8C);
PPC_FUNC_IMPL(__imp__sub_827AEE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEE90"))) PPC_WEAK_FUNC(sub_827AEE90);
PPC_FUNC_IMPL(__imp__sub_827AEE90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8820
	ctx.r5.s64 = r11.s64 + -8820;
	// addi r3,r10,-13492
	ctx.r3.s64 = ctx.r10.s64 + -13492;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEEAC"))) PPC_WEAK_FUNC(sub_827AEEAC);
PPC_FUNC_IMPL(__imp__sub_827AEEAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEEB0"))) PPC_WEAK_FUNC(sub_827AEEB0);
PPC_FUNC_IMPL(__imp__sub_827AEEB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8808
	ctx.r5.s64 = r11.s64 + -8808;
	// addi r3,r10,-13192
	ctx.r3.s64 = ctx.r10.s64 + -13192;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEECC"))) PPC_WEAK_FUNC(sub_827AEECC);
PPC_FUNC_IMPL(__imp__sub_827AEECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEED0"))) PPC_WEAK_FUNC(sub_827AEED0);
PPC_FUNC_IMPL(__imp__sub_827AEED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8796
	ctx.r5.s64 = r11.s64 + -8796;
	// addi r3,r10,-12912
	ctx.r3.s64 = ctx.r10.s64 + -12912;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEEEC"))) PPC_WEAK_FUNC(sub_827AEEEC);
PPC_FUNC_IMPL(__imp__sub_827AEEEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEEF0"))) PPC_WEAK_FUNC(sub_827AEEF0);
PPC_FUNC_IMPL(__imp__sub_827AEEF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8784
	ctx.r5.s64 = r11.s64 + -8784;
	// addi r3,r10,-5940
	ctx.r3.s64 = ctx.r10.s64 + -5940;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEF0C"))) PPC_WEAK_FUNC(sub_827AEF0C);
PPC_FUNC_IMPL(__imp__sub_827AEF0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEF10"))) PPC_WEAK_FUNC(sub_827AEF10);
PPC_FUNC_IMPL(__imp__sub_827AEF10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8772
	ctx.r5.s64 = r11.s64 + -8772;
	// addi r3,r10,-13700
	ctx.r3.s64 = ctx.r10.s64 + -13700;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEF2C"))) PPC_WEAK_FUNC(sub_827AEF2C);
PPC_FUNC_IMPL(__imp__sub_827AEF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEF30"))) PPC_WEAK_FUNC(sub_827AEF30);
PPC_FUNC_IMPL(__imp__sub_827AEF30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8756
	ctx.r5.s64 = r11.s64 + -8756;
	// addi r3,r10,-6200
	ctx.r3.s64 = ctx.r10.s64 + -6200;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEF4C"))) PPC_WEAK_FUNC(sub_827AEF4C);
PPC_FUNC_IMPL(__imp__sub_827AEF4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEF50"))) PPC_WEAK_FUNC(sub_827AEF50);
PPC_FUNC_IMPL(__imp__sub_827AEF50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,19612
	ctx.r5.s64 = r11.s64 + 19612;
	// addi r3,r10,-13372
	ctx.r3.s64 = ctx.r10.s64 + -13372;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEF6C"))) PPC_WEAK_FUNC(sub_827AEF6C);
PPC_FUNC_IMPL(__imp__sub_827AEF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEF70"))) PPC_WEAK_FUNC(sub_827AEF70);
PPC_FUNC_IMPL(__imp__sub_827AEF70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8744
	ctx.r5.s64 = r11.s64 + -8744;
	// addi r3,r10,-13892
	ctx.r3.s64 = ctx.r10.s64 + -13892;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEF8C"))) PPC_WEAK_FUNC(sub_827AEF8C);
PPC_FUNC_IMPL(__imp__sub_827AEF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEF90"))) PPC_WEAK_FUNC(sub_827AEF90);
PPC_FUNC_IMPL(__imp__sub_827AEF90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8736
	ctx.r5.s64 = r11.s64 + -8736;
	// addi r3,r10,-6720
	ctx.r3.s64 = ctx.r10.s64 + -6720;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEFAC"))) PPC_WEAK_FUNC(sub_827AEFAC);
PPC_FUNC_IMPL(__imp__sub_827AEFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEFB0"))) PPC_WEAK_FUNC(sub_827AEFB0);
PPC_FUNC_IMPL(__imp__sub_827AEFB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8720
	ctx.r5.s64 = r11.s64 + -8720;
	// addi r3,r10,-6420
	ctx.r3.s64 = ctx.r10.s64 + -6420;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEFCC"))) PPC_WEAK_FUNC(sub_827AEFCC);
PPC_FUNC_IMPL(__imp__sub_827AEFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEFD0"))) PPC_WEAK_FUNC(sub_827AEFD0);
PPC_FUNC_IMPL(__imp__sub_827AEFD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r5,r11,-8704
	ctx.r5.s64 = r11.s64 + -8704;
	// addi r3,r10,-6700
	ctx.r3.s64 = ctx.r10.s64 + -6700;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AEFEC"))) PPC_WEAK_FUNC(sub_827AEFEC);
PPC_FUNC_IMPL(__imp__sub_827AEFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AEFF0"))) PPC_WEAK_FUNC(sub_827AEFF0);
PPC_FUNC_IMPL(__imp__sub_827AEFF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r5,r11,-8688
	ctx.r5.s64 = r11.s64 + -8688;
	// addi r3,r10,-13832
	ctx.r3.s64 = ctx.r10.s64 + -13832;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF00C"))) PPC_WEAK_FUNC(sub_827AF00C);
PPC_FUNC_IMPL(__imp__sub_827AF00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827AF010"))) PPC_WEAK_FUNC(sub_827AF010);
PPC_FUNC_IMPL(__imp__sub_827AF010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-23440
	ctx.r3.s64 = r11.s64 + -23440;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827AF01C"))) PPC_WEAK_FUNC(sub_827AF01C);
PPC_FUNC_IMPL(__imp__sub_827AF01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

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

