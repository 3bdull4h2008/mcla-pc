#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82415254"))) PPC_WEAK_FUNC(sub_82415254);
PPC_FUNC_IMPL(__imp__sub_82415254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415258"))) PPC_WEAK_FUNC(sub_82415258);
PPC_FUNC_IMPL(__imp__sub_82415258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82415260;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lbz r9,11924(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11924);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r8,7088
	ctx.r8.s64 = ctx.r8.s64 + 7088;
	// rlwinm r7,r5,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// lwz r31,12(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r30,1
	r30.s64 = 1;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// rlwinm r6,r6,22,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 22) & 0x1;
	// lwzx r8,r9,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwimi r29,r7,11,20,20
	r29.u64 = (__builtin_rotateleft32(ctx.r7.u32, 11) & 0x800) | (r29.u64 & 0xFFFFFFFFFFFFF7FF);
	// or r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
	// rldicr r6,r30,63,63
	ctx.r6.u64 = __builtin_rotateleft64(r30.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// clrldi r8,r4,32
	ctx.r8.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// srd r8,r6,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r8.u8 & 0x7F));
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r31,r9,21,9,10
	r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 21) & 0x600000) | (r31.u64 & 0xFFFFFFFFFF9FFFFF);
	// rlwimi r31,r9,21,4,6
	r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 21) & 0xE000000) | (r31.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// lbz r9,12002(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12002);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 0);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// rlwinm r10,r9,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwimi r6,r7,31,13,31
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FFFF) | (ctx.r6.u64 & 0xFFFFFFFFFFF80000);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwimi r6,r7,31,1,11
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FF00000) | (ctx.r6.u64 & 0xFFFFFFFF800FFFFF);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// rlwinm r7,r6,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFF;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwimi r10,r29,0,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(r29.u32, 0) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	r11.u64 = ctx.r8.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82415320"))) PPC_WEAK_FUNC(sub_82415320);
PPC_FUNC_IMPL(__imp__sub_82415320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r11,r10,21,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// rlwinm r10,r9,11,21,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0x7FF;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & r11.u64;
	// not r11,r11
	r11.u64 = ~r11.u64;
	// rlwimi r10,r11,0,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// clrlwi r3,r10,29
	ctx.r3.u64 = ctx.r10.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415354"))) PPC_WEAK_FUNC(sub_82415354);
PPC_FUNC_IMPL(__imp__sub_82415354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415358"))) PPC_WEAK_FUNC(sub_82415358);
PPC_FUNC_IMPL(__imp__sub_82415358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12002(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,31,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rldicr r5,r5,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r30,r31,31,13,31
	r30.u64 = (__builtin_rotateleft32(r31.u32, 31) & 0x7FFFF) | (r30.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r30,r31,31,1,11
	r30.u64 = (__builtin_rotateleft32(r31.u32, 31) & 0x7FF00000) | (r30.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r31,r30,13,20,31
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 13) & 0xFFF;
	// srd r7,r5,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r7.u8 & 0x7F));
	// and r9,r31,r9
	ctx.r9.u64 = r31.u64 & ctx.r9.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r11,12002
	ctx.r9.s64 = r11.s64 + 12002;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12002(r11)
	PPC_STORE_U8(r11.u32 + 12002, ctx.r6.u8);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r7,r11
	r11.u64 = ctx.r7.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824153EC"))) PPC_WEAK_FUNC(sub_824153EC);
PPC_FUNC_IMPL(__imp__sub_824153EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824153F0"))) PPC_WEAK_FUNC(sub_824153F0);
PPC_FUNC_IMPL(__imp__sub_824153F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12002(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// rlwinm r3,r11,31,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415400"))) PPC_WEAK_FUNC(sub_82415400);
PPC_FUNC_IMPL(__imp__sub_82415400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82415408;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lbz r9,11924(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11924);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r8,7088
	ctx.r8.s64 = ctx.r8.s64 + 7088;
	// rlwinm r7,r5,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// lwz r31,12(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r30,1
	r30.s64 = 1;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// rlwinm r6,r6,21,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 21) & 0x1;
	// lwzx r8,r9,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwimi r29,r7,10,21,21
	r29.u64 = (__builtin_rotateleft32(ctx.r7.u32, 10) & 0x400) | (r29.u64 & 0xFFFFFFFFFFFFFBFF);
	// or r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
	// rldicr r6,r30,63,63
	ctx.r6.u64 = __builtin_rotateleft64(r30.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// clrldi r8,r4,32
	ctx.r8.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// srd r8,r6,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r8.u8 & 0x7F));
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r31,r9,19,11,12
	r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 19) & 0x180000) | (r31.u64 & 0xFFFFFFFFFFE7FFFF);
	// rlwimi r31,r9,19,4,6
	r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 19) & 0xE000000) | (r31.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// lbz r9,12002(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12002);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 0);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// rlwinm r10,r9,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwimi r6,r7,31,13,31
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FFFF) | (ctx.r6.u64 & 0xFFFFFFFFFFF80000);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwimi r6,r7,31,1,11
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FF00000) | (ctx.r6.u64 & 0xFFFFFFFF800FFFFF);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// rlwinm r7,r6,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFF;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwimi r10,r29,0,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(r29.u32, 0) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	r11.u64 = ctx.r8.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824154C8"))) PPC_WEAK_FUNC(sub_824154C8);
PPC_FUNC_IMPL(__imp__sub_824154C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r11,r10,22,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// rlwinm r10,r9,13,19,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1FFF;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & r11.u64;
	// not r11,r11
	r11.u64 = ~r11.u64;
	// rlwimi r10,r11,0,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// clrlwi r3,r10,29
	ctx.r3.u64 = ctx.r10.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824154FC"))) PPC_WEAK_FUNC(sub_824154FC);
PPC_FUNC_IMPL(__imp__sub_824154FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415500"))) PPC_WEAK_FUNC(sub_82415500);
PPC_FUNC_IMPL(__imp__sub_82415500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12002(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// li r8,1
	ctx.r8.s64 = 1;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rldicr r31,r8,63,63
	r31.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r5,r30,31,13,31
	ctx.r5.u64 = (__builtin_rotateleft32(r30.u32, 31) & 0x7FFFF) | (ctx.r5.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r5,r30,31,1,11
	ctx.r5.u64 = (__builtin_rotateleft32(r30.u32, 31) & 0x7FF00000) | (ctx.r5.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r30,r7,32
	r30.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r7,r5,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 13) & 0xFFF;
	// srd r5,r31,r30
	ctx.r5.u64 = r30.u8 & 0x40 ? 0 : (r31.u64 >> (r30.u8 & 0x7F));
	// and r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 & ctx.r9.u64;
	// addi r9,r11,12002
	ctx.r9.s64 = r11.s64 + 12002;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12002(r11)
	PPC_STORE_U8(r11.u32 + 12002, ctx.r6.u8);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r5,r11
	r11.u64 = ctx.r5.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241558C"))) PPC_WEAK_FUNC(sub_8241558C);
PPC_FUNC_IMPL(__imp__sub_8241558C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415590"))) PPC_WEAK_FUNC(sub_82415590);
PPC_FUNC_IMPL(__imp__sub_82415590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12002(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824155A0"))) PPC_WEAK_FUNC(sub_824155A0);
PPC_FUNC_IMPL(__imp__sub_824155A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwimi r8,r5,23,7,8
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 23) & 0x1800000) | (ctx.r8.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824155DC"))) PPC_WEAK_FUNC(sub_824155DC);
PPC_FUNC_IMPL(__imp__sub_824155DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824155E0"))) PPC_WEAK_FUNC(sub_824155E0);
PPC_FUNC_IMPL(__imp__sub_824155E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1164(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1164);
	// rlwinm r3,r11,9,30,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824155F4"))) PPC_WEAK_FUNC(sub_824155F4);
PPC_FUNC_IMPL(__imp__sub_824155F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824155F8"))) PPC_WEAK_FUNC(sub_824155F8);
PPC_FUNC_IMPL(__imp__sub_824155F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12002(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,30,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rldicr r5,r5,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r30,r31,31,13,31
	r30.u64 = (__builtin_rotateleft32(r31.u32, 31) & 0x7FFFF) | (r30.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r30,r31,31,1,11
	r30.u64 = (__builtin_rotateleft32(r31.u32, 31) & 0x7FF00000) | (r30.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r31,r30,13,20,31
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 13) & 0xFFF;
	// srd r7,r5,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r7.u8 & 0x7F));
	// and r9,r31,r9
	ctx.r9.u64 = r31.u64 & ctx.r9.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r11,12002
	ctx.r9.s64 = r11.s64 + 12002;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12002(r11)
	PPC_STORE_U8(r11.u32 + 12002, ctx.r6.u8);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r7,r11
	r11.u64 = ctx.r7.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241568C"))) PPC_WEAK_FUNC(sub_8241568C);
PPC_FUNC_IMPL(__imp__sub_8241568C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415690"))) PPC_WEAK_FUNC(sub_82415690);
PPC_FUNC_IMPL(__imp__sub_82415690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12002(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824156A0"))) PPC_WEAK_FUNC(sub_824156A0);
PPC_FUNC_IMPL(__imp__sub_824156A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm. r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x824156c0
	if (!cr0.eq) goto loc_824156C0;
	// rlwinm. r10,r10,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824156fc
	if (cr0.eq) goto loc_824156FC;
loc_824156C0:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,7088
	ctx.r10.s64 = ctx.r10.s64 + 7088;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// li r6,1
	ctx.r6.s64 = 1;
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rldicr r6,r6,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// srd r8,r6,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r7.u8 & 0x7F));
	// rlwimi r9,r10,25,4,6
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 25) & 0xE000000) | (ctx.r9.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	r11.u64 = ctx.r8.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
loc_824156FC:
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,11924(r11)
	PPC_STORE_U8(r11.u32 + 11924, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415708"))) PPC_WEAK_FUNC(sub_82415708);
PPC_FUNC_IMPL(__imp__sub_82415708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,11924(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 11924);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415714"))) PPC_WEAK_FUNC(sub_82415714);
PPC_FUNC_IMPL(__imp__sub_82415714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415718"))) PPC_WEAK_FUNC(sub_82415718);
PPC_FUNC_IMPL(__imp__sub_82415718) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r5,36(r1)
	PPC_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lfs f0,7156(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7156);
	f0.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r10,r10,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// srd r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r9.u8 & 0x7F));
	// lfs f13,36(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwimi r8,r9,5,23,26
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x1E0) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFE1F);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415774"))) PPC_WEAK_FUNC(sub_82415774);
PPC_FUNC_IMPL(__imp__sub_82415774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415778"))) PPC_WEAK_FUNC(sub_82415778);
PPC_FUNC_IMPL(__imp__sub_82415778) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,1172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1172);
	// lfs f0,12424(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12424);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r11,23,0,8
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 23) & 0xFF800000;
	// srawi r11,r11,28
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFFFFF) != 0);
	r11.s64 = r11.s32 >> 28;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824157BC"))) PPC_WEAK_FUNC(sub_824157BC);
PPC_FUNC_IMPL(__imp__sub_824157BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824157C0"))) PPC_WEAK_FUNC(sub_824157C0);
PPC_FUNC_IMPL(__imp__sub_824157C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r5,36(r1)
	PPC_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lfs f0,-10992(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -10992);
	f0.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r10,r10,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// srd r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r9.u8 & 0x7F));
	// lfs f13,36(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwimi r8,r9,12,10,19
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 12) & 0x3FF000) | (ctx.r8.u64 & 0xFFFFFFFFFFC00FFF);
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241581C"))) PPC_WEAK_FUNC(sub_8241581C);
PPC_FUNC_IMPL(__imp__sub_8241581C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415820"))) PPC_WEAK_FUNC(sub_82415820);
PPC_FUNC_IMPL(__imp__sub_82415820) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lwz r11,1168(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1168);
	// lfs f0,7160(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7160);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r11,10,0,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// srawi r11,r11,22
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FFFFF) != 0);
	r11.s64 = r11.s32 >> 22;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415860"))) PPC_WEAK_FUNC(sub_82415860);
PPC_FUNC_IMPL(__imp__sub_82415860) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,3136
	r11.s64 = ctx.r4.s64 + 3136;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824158c0
	if (cr6.eq) goto loc_824158C0;
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r11,r11,30,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0xF;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// bgt cr6,0x82415894
	if (cr6.gt) goto loc_82415894;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_82415894:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwimi r9,r11,2,26,29
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 2) & 0x3C) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFC3);
	// rldicr r11,r7,63,63
	r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// clrldi r10,r8,32
	ctx.r10.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// srd r11,r11,r10
	r11.u64 = ctx.r10.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r10.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
loc_824158C0:
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,11950(r11)
	PPC_STORE_U8(r11.u32 + 11950, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824158CC"))) PPC_WEAK_FUNC(sub_824158CC);
PPC_FUNC_IMPL(__imp__sub_824158CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824158D0"))) PPC_WEAK_FUNC(sub_824158D0);
PPC_FUNC_IMPL(__imp__sub_824158D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,11950(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 11950);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824158DC"))) PPC_WEAK_FUNC(sub_824158DC);
PPC_FUNC_IMPL(__imp__sub_824158DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824158E0"))) PPC_WEAK_FUNC(sub_824158E0);
PPC_FUNC_IMPL(__imp__sub_824158E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,3136
	r11.s64 = ctx.r4.s64 + 3136;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82415940
	if (cr6.eq) goto loc_82415940;
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r11,r11,26,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0xF;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// blt cr6,0x82415914
	if (cr6.lt) goto loc_82415914;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_82415914:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwimi r9,r11,6,22,25
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 6) & 0x3C0) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFC3F);
	// rldicr r11,r7,63,63
	r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// clrldi r10,r8,32
	ctx.r10.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// srd r11,r11,r10
	r11.u64 = ctx.r10.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r10.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
loc_82415940:
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,11976(r11)
	PPC_STORE_U8(r11.u32 + 11976, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241594C"))) PPC_WEAK_FUNC(sub_8241594C);
PPC_FUNC_IMPL(__imp__sub_8241594C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415950"))) PPC_WEAK_FUNC(sub_82415950);
PPC_FUNC_IMPL(__imp__sub_82415950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,11976(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 11976);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241595C"))) PPC_WEAK_FUNC(sub_8241595C);
PPC_FUNC_IMPL(__imp__sub_8241595C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415960"))) PPC_WEAK_FUNC(sub_82415960);
PPC_FUNC_IMPL(__imp__sub_82415960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// cntlzw r10,r5
	ctx.r10.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// li r8,1
	ctx.r8.s64 = 1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r8,r8,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r7,r7,0,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// srd r9,r8,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r9.u8 & 0x7F));
	// or r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 | ctx.r7.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824159AC"))) PPC_WEAK_FUNC(sub_824159AC);
PPC_FUNC_IMPL(__imp__sub_824159AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824159B0"))) PPC_WEAK_FUNC(sub_824159B0);
PPC_FUNC_IMPL(__imp__sub_824159B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1172);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// subfic r11,r11,0
	xer.ca = r11.u32 <= 0;
	r11.s64 = 0 - r11.s64;
	// subfe r3,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r3.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824159CC"))) PPC_WEAK_FUNC(sub_824159CC);
PPC_FUNC_IMPL(__imp__sub_824159CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824159D0"))) PPC_WEAK_FUNC(sub_824159D0);
PPC_FUNC_IMPL(__imp__sub_824159D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lwzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwimi r9,r5,10,19,21
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 10) & 0x1C00) | (ctx.r9.u64 & 0xFFFFFFFFFFFFE3FF);
	// li r8,1
	ctx.r8.s64 = 1;
	// stwx r9,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// clrldi r11,r10,32
	r11.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r10,r8,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r11,r10,r11
	r11.u64 = r11.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (r11.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415A08"))) PPC_WEAK_FUNC(sub_82415A08);
PPC_FUNC_IMPL(__imp__sub_82415A08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwinm r3,r11,22,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415A1C"))) PPC_WEAK_FUNC(sub_82415A1C);
PPC_FUNC_IMPL(__imp__sub_82415A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415A20"))) PPC_WEAK_FUNC(sub_82415A20);
PPC_FUNC_IMPL(__imp__sub_82415A20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lwzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwimi r9,r5,13,16,18
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 13) & 0xE000) | (ctx.r9.u64 & 0xFFFFFFFFFFFF1FFF);
	// li r8,1
	ctx.r8.s64 = 1;
	// stwx r9,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// clrldi r11,r10,32
	r11.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r10,r8,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r11,r10,r11
	r11.u64 = r11.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (r11.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415A58"))) PPC_WEAK_FUNC(sub_82415A58);
PPC_FUNC_IMPL(__imp__sub_82415A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwinm r3,r11,19,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415A6C"))) PPC_WEAK_FUNC(sub_82415A6C);
PPC_FUNC_IMPL(__imp__sub_82415A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415A70"))) PPC_WEAK_FUNC(sub_82415A70);
PPC_FUNC_IMPL(__imp__sub_82415A70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lwzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwimi r9,r5,16,13,15
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 16) & 0x70000) | (ctx.r9.u64 & 0xFFFFFFFFFFF8FFFF);
	// li r8,1
	ctx.r8.s64 = 1;
	// stwx r9,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// clrldi r11,r10,32
	r11.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r10,r8,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r11,r10,r11
	r11.u64 = r11.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (r11.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415AA8"))) PPC_WEAK_FUNC(sub_82415AA8);
PPC_FUNC_IMPL(__imp__sub_82415AA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lhzx r11,r11,r3
	r11.u64 = PPC_LOAD_U16(r11.u32 + ctx.r3.u32);
	// clrlwi r3,r11,29
	ctx.r3.u64 = r11.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415ABC"))) PPC_WEAK_FUNC(sub_82415ABC);
PPC_FUNC_IMPL(__imp__sub_82415ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415AC0"))) PPC_WEAK_FUNC(sub_82415AC0);
PPC_FUNC_IMPL(__imp__sub_82415AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwimi r8,r5,3,27,28
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 3) & 0x18) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415AFC"))) PPC_WEAK_FUNC(sub_82415AFC);
PPC_FUNC_IMPL(__imp__sub_82415AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415B00"))) PPC_WEAK_FUNC(sub_82415B00);
PPC_FUNC_IMPL(__imp__sub_82415B00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1172);
	// rlwinm r3,r11,29,30,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415B14"))) PPC_WEAK_FUNC(sub_82415B14);
PPC_FUNC_IMPL(__imp__sub_82415B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415B18"))) PPC_WEAK_FUNC(sub_82415B18);
PPC_FUNC_IMPL(__imp__sub_82415B18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwimi r8,r5,22,5,9
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 22) & 0x7C00000) | (ctx.r8.u64 & 0xFFFFFFFFF83FFFFF);
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415B54"))) PPC_WEAK_FUNC(sub_82415B54);
PPC_FUNC_IMPL(__imp__sub_82415B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415B58"))) PPC_WEAK_FUNC(sub_82415B58);
PPC_FUNC_IMPL(__imp__sub_82415B58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1168(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1168);
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// srawi r3,r11,27
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFFFFF) != 0);
	ctx.r3.s64 = r11.s32 >> 27;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415B70"))) PPC_WEAK_FUNC(sub_82415B70);
PPC_FUNC_IMPL(__imp__sub_82415B70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwimi r8,r5,27,0,4
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 27) & 0xF8000000) | (ctx.r8.u64 & 0xFFFFFFFF07FFFFFF);
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415BAC"))) PPC_WEAK_FUNC(sub_82415BAC);
PPC_FUNC_IMPL(__imp__sub_82415BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415BB0"))) PPC_WEAK_FUNC(sub_82415BB0);
PPC_FUNC_IMPL(__imp__sub_82415BB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1168(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1168);
	// srawi r3,r11,27
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFFFFF) != 0);
	ctx.r3.s64 = r11.s32 >> 27;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415BC4"))) PPC_WEAK_FUNC(sub_82415BC4);
PPC_FUNC_IMPL(__imp__sub_82415BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415BC8"))) PPC_WEAK_FUNC(sub_82415BC8);
PPC_FUNC_IMPL(__imp__sub_82415BC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwimi r8,r5,2,29,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 2) & 0x4) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFFB);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415C04"))) PPC_WEAK_FUNC(sub_82415C04);
PPC_FUNC_IMPL(__imp__sub_82415C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415C08"))) PPC_WEAK_FUNC(sub_82415C08);
PPC_FUNC_IMPL(__imp__sub_82415C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1172);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415C1C"))) PPC_WEAK_FUNC(sub_82415C1C);
PPC_FUNC_IMPL(__imp__sub_82415C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415C20"))) PPC_WEAK_FUNC(sub_82415C20);
PPC_FUNC_IMPL(__imp__sub_82415C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// cntlzw r10,r5
	ctx.r10.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// li r8,1
	ctx.r8.s64 = 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r8,r8,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// rlwimi r7,r10,11,20,20
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 11) & 0x800) | (ctx.r7.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// srd r11,r8,r9
	r11.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r9.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415C64"))) PPC_WEAK_FUNC(sub_82415C64);
PPC_FUNC_IMPL(__imp__sub_82415C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415C68"))) PPC_WEAK_FUNC(sub_82415C68);
PPC_FUNC_IMPL(__imp__sub_82415C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1156(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1156);
	// not r11,r11
	r11.u64 = ~r11.u64;
	// rlwinm r3,r11,21,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415C80"))) PPC_WEAK_FUNC(sub_82415C80);
PPC_FUNC_IMPL(__imp__sub_82415C80) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,12648(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12648);
	f0.f64 = double(temp.f32);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lfs f13,12656(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12656);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f0,12660(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12660);
	f0.f64 = double(temp.f32);
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lfs f13,12652(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12652);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r31,8(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r30,12(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r6,11856(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11856);
	// stw r11,12676(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12676, r11.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stw r10,12680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12680, ctx.r10.u32);
	// add r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 + ctx.r4.u64;
	// stw r31,12684(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12684, r31.u32);
	// stw r30,12688(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12688, r30.u32);
	// add r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 + ctx.r5.u64;
	// beq cr6,0x82415d3c
	if (cr6.eq) goto loc_82415D3C;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bgt cr6,0x82415d18
	if (cr6.gt) goto loc_82415D18;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_82415D18:
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82415d24
	if (cr6.gt) goto loc_82415D24;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
loc_82415D24:
	// cmpw cr6,r6,r31
	cr6.compare<int32_t>(ctx.r6.s32, r31.s32, xer);
	// blt cr6,0x82415d30
	if (cr6.lt) goto loc_82415D30;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
loc_82415D30:
	// cmpw cr6,r7,r30
	cr6.compare<int32_t>(ctx.r7.s32, r30.s32, xer);
	// blt cr6,0x82415d3c
	if (cr6.lt) goto loc_82415D3C;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
loc_82415D3C:
	// lwz r11,10436(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10436);
	// lwz r10,10440(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10440);
	// rlwimi r11,r5,16,1,15
	r11.u64 = (__builtin_rotateleft32(ctx.r5.u32, 16) & 0x7FFF0000) | (r11.u64 & 0xFFFFFFFF8000FFFF);
	// rlwimi r10,r7,16,1,15
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r7.u32, 16) & 0x7FFF0000) | (ctx.r10.u64 & 0xFFFFFFFF8000FFFF);
	// rlwimi r11,r4,0,17,31
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x7FFF) | (r11.u64 & 0xFFFFFFFFFFFF8000);
	// rlwimi r10,r6,0,17,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0x7FFF) | (ctx.r10.u64 & 0xFFFFFFFFFFFF8000);
	// stw r11,10436(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10436, r11.u32);
	// stw r10,10440(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10440, ctx.r10.u32);
	// bl 0x82413660
	ctx.lr = 0x82415D60;
	sub_82413660(ctx, base);
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

__attribute__((alias("__imp__sub_82415D78"))) PPC_WEAK_FUNC(sub_82415D78);
PPC_FUNC_IMPL(__imp__sub_82415D78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,12648(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12648);
	f0.f64 = double(temp.f32);
	// li r11,4
	r11.s64 = 4;
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfiwx f0,0,r4
	PPC_STORE_U32(ctx.r4.u32, f0.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// lfs f0,12652(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12652);
	f0.f64 = double(temp.f32);
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// li r9,12
	ctx.r9.s64 = 12;
	// stfiwx f0,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, f0.u32);
	// lfs f0,12656(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12656);
	f0.f64 = double(temp.f32);
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfiwx f0,r4,r10
	PPC_STORE_U32(ctx.r4.u32 + ctx.r10.u32, f0.u32);
	// lfs f0,12660(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12660);
	f0.f64 = double(temp.f32);
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfiwx f0,r4,r9
	PPC_STORE_U32(ctx.r4.u32 + ctx.r9.u32, f0.u32);
	// lfs f0,12664(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12664);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// lfs f0,12668(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12668);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415DC8"))) PPC_WEAK_FUNC(sub_82415DC8);
PPC_FUNC_IMPL(__imp__sub_82415DC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82415DD0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82415e38
	if (cr6.eq) goto loc_82415E38;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// subfic r11,r29,17
	xer.ca = r29.u32 <= 17;
	r11.s64 = 17 - r29.s64;
	// lwz r5,28(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r4,r11,222
	ctx.r4.s64 = r11.s64 + 222;
	// rlwinm r7,r10,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r7,512
	r11.s64 = ctx.r7.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// rlwinm r7,r4,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r6,r6,r5
	ctx.r6.s64 = ctx.r5.s64 - ctx.r6.s64;
	// stwx r11,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, r11.u32);
	// stw r6,1780(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1780, ctx.r6.u32);
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
loc_82415E38:
	// addi r11,r29,3115
	r11.s64 = r29.s64 + 3115;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r27,r31
	r28.u64 = PPC_LOAD_U32(r27.u32 + r31.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82415eb0
	if (cr6.eq) goto loc_82415EB0;
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82415e60
	if (cr6.eq) goto loc_82415E60;
	// stw r11,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r11.u32);
	// b 0x82415eb0
	goto loc_82415EB0;
loc_82415E60:
	// lwz r11,10912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10912);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82415eb0
	if (cr0.eq) goto loc_82415EB0;
	// lwz r11,13528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13528);
	// lwz r3,13524(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13524);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x82415e88
	if (cr6.lt) goto loc_82415E88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a630
	ctx.lr = 0x82415E88;
	sub_8241A630(ctx, base);
loc_82415E88:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// rlwimi r11,r28,30,2,31
	r11.u64 = (__builtin_rotateleft32(r28.u32, 30) & 0x3FFFFFFF) | (r11.u64 & 0xFFFFFFFFC0000000);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// rlwinm r11,r11,0,2,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// stw r9,13524(r31)
	PPC_STORE_U32(r31.u32 + 13524, ctx.r9.u32);
loc_82415EB0:
	// add r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	// stwx r30,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r30.u32);
	// rlwinm r9,r26,30,24,31
	ctx.r9.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 30) & 0xFF;
	// rlwinm. r10,r26,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 30) & 0x3FFFFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r9,12528(r11)
	PPC_STORE_U8(r11.u32 + 12528, ctx.r9.u8);
	// beq 0x82415ee0
	if (cr0.eq) goto loc_82415EE0;
	// lbz r11,11832(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 11832);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82415ee0
	if (cr6.eq) goto loc_82415EE0;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82415EE0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82415EE8"))) PPC_WEAK_FUNC(sub_82415EE8);
PPC_FUNC_IMPL(__imp__sub_82415EE8) {
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
	ctx.lr = 0x82415EF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r30,12436(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12436);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82415f6c
	if (cr6.eq) goto loc_82415F6C;
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82415f1c
	if (cr6.eq) goto loc_82415F1C;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// b 0x82415f6c
	goto loc_82415F6C;
loc_82415F1C:
	// lwz r11,10912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10912);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82415f6c
	if (cr0.eq) goto loc_82415F6C;
	// lwz r11,13528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13528);
	// lwz r3,13524(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13524);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x82415f44
	if (cr6.lt) goto loc_82415F44;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a630
	ctx.lr = 0x82415F44;
	sub_8241A630(ctx, base);
loc_82415F44:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// rlwimi r11,r30,30,2,31
	r11.u64 = (__builtin_rotateleft32(r30.u32, 30) & 0x3FFFFFFF) | (r11.u64 & 0xFFFFFFFFC0000000);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// rlwinm r11,r11,0,2,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// stw r9,13524(r31)
	PPC_STORE_U32(r31.u32 + 13524, ctx.r9.u32);
loc_82415F6C:
	// stw r29,12436(r31)
	PPC_STORE_U32(r31.u32 + 12436, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82415F78"))) PPC_WEAK_FUNC(sub_82415F78);
PPC_FUNC_IMPL(__imp__sub_82415F78) {
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
	// addi r11,r4,3110
	r11.s64 = ctx.r4.s64 + 3110;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r3
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82415fa4
	if (cr6.eq) goto loc_82415FA4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82422160
	ctx.lr = 0x82415FA4;
	sub_82422160(ctx, base);
loc_82415FA4:
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

__attribute__((alias("__imp__sub_82415FBC"))) PPC_WEAK_FUNC(sub_82415FBC);
PPC_FUNC_IMPL(__imp__sub_82415FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415FC0"))) PPC_WEAK_FUNC(sub_82415FC0);
PPC_FUNC_IMPL(__imp__sub_82415FC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lwz r31,12456(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12456);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82415fe4
	if (cr6.eq) goto loc_82415FE4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82422160
	ctx.lr = 0x82415FE4;
	sub_82422160(ctx, base);
loc_82415FE4:
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

__attribute__((alias("__imp__sub_82415FFC"))) PPC_WEAK_FUNC(sub_82415FFC);
PPC_FUNC_IMPL(__imp__sub_82415FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82416000"))) PPC_WEAK_FUNC(sub_82416000);
PPC_FUNC_IMPL(__imp__sub_82416000) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-1648(r1)
	ea = -1648 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82426cf0
	ctx.lr = 0x82416028;
	sub_82426CF0(ctx, base);
	// addi r30,r31,15004
	r30.s64 = r31.s64 + 15004;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r8,r11,1536
	ctx.r8.s64 = r11.s64 + 1536;
loc_82416038:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x82416058
	if (!cr0.eq) goto loc_82416058;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x82416038
	if (!cr6.eq) goto loc_82416038;
loc_82416058:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x824160ac
	if (cr0.eq) goto loc_824160AC;
	// lwz r3,23904(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 23904);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82416084
	if (cr6.eq) goto loc_82416084;
	// lwz r11,23908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23908);
	// rlwinm. r11,r11,0,0,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82416084
	if (!cr0.eq) goto loc_82416084;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x82416084;
	sub_8244D5C0(ctx, base);
loc_82416084:
	// lwz r11,23908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23908);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// oris r11,r11,32768
	r11.u64 = r11.u64 | 2147483648;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,23908(r31)
	PPC_STORE_U32(r31.u32 + 23908, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x824160A0;
	sub_823DA950(ctx, base);
	// lwz r11,16708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16708);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stw r11,16708(r31)
	PPC_STORE_U32(r31.u32 + 16708, r11.u32);
loc_824160AC:
	// addi r1,r1,1648
	ctx.r1.s64 = ctx.r1.s64 + 1648;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824160C4"))) PPC_WEAK_FUNC(sub_824160C4);
PPC_FUNC_IMPL(__imp__sub_824160C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824160C8"))) PPC_WEAK_FUNC(sub_824160C8);
PPC_FUNC_IMPL(__imp__sub_824160C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-1648(r1)
	ea = -1648 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82426d88
	ctx.lr = 0x824160F0;
	sub_82426D88(ctx, base);
	// addi r30,r31,15004
	r30.s64 = r31.s64 + 15004;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r8,r11,1536
	ctx.r8.s64 = r11.s64 + 1536;
loc_82416100:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x82416120
	if (!cr0.eq) goto loc_82416120;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x82416100
	if (!cr6.eq) goto loc_82416100;
loc_82416120:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82416174
	if (cr0.eq) goto loc_82416174;
	// lwz r3,23904(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 23904);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8241614c
	if (cr6.eq) goto loc_8241614C;
	// lwz r11,23908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23908);
	// rlwinm. r11,r11,0,0,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241614c
	if (!cr0.eq) goto loc_8241614C;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x8241614C;
	sub_8244D5C0(ctx, base);
loc_8241614C:
	// lwz r11,23908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23908);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// oris r11,r11,32768
	r11.u64 = r11.u64 | 2147483648;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,23908(r31)
	PPC_STORE_U32(r31.u32 + 23908, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x82416168;
	sub_823DA950(ctx, base);
	// lwz r11,16708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16708);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stw r11,16708(r31)
	PPC_STORE_U32(r31.u32 + 16708, r11.u32);
loc_82416174:
	// addi r1,r1,1648
	ctx.r1.s64 = ctx.r1.s64 + 1648;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241618C"))) PPC_WEAK_FUNC(sub_8241618C);
PPC_FUNC_IMPL(__imp__sub_8241618C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82416190"))) PPC_WEAK_FUNC(sub_82416190);
PPC_FUNC_IMPL(__imp__sub_82416190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,642
	r11.s64 = ctx.r4.s64 + 642;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r9,r4,9
	ctx.r9.s64 = ctx.r4.s64 + 9;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// li r8,1
	ctx.r8.s64 = 1;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r8,r8,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// srd r10,r8,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r9.u8 & 0x7F));
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,8(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r9,12(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824161E0"))) PPC_WEAK_FUNC(sub_824161E0);
PPC_FUNC_IMPL(__imp__sub_824161E0) {
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
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x82416268
	if (!cr6.eq) goto loc_82416268;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82416214
	if (!cr6.gt) goto loc_82416214;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82416214;
	sub_82412710(ctx, base);
loc_82416214:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// ori r11,r11,24576
	r11.u64 = r11.u64 | 24576;
	// ori r10,r10,25088
	ctx.r10.u64 = ctx.r10.u64 | 25088;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,-1
	r11.s64 = -1;
	// lwz r9,12708(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12708);
	// lis r8,-16384
	ctx.r8.s64 = -1073741824;
	// lis r7,-16384
	ctx.r7.s64 = -1073741824;
	// ori r8,r8,24832
	ctx.r8.u64 = ctx.r8.u64 | 24832;
	// ori r7,r7,25344
	ctx.r7.u64 = ctx.r7.u64 | 25344;
	// li r6,0
	ctx.r6.s64 = 0;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12712(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12712);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
loc_82416268:
	// lwz r11,10440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10440);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10436);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,17,0,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r7,r9,17
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 17;
	// rlwinm r10,r10,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0xFFFE0000;
	// srawi r6,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	ctx.r6.s64 = r11.s32 >> 17;
	// srawi r5,r8,17
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 17;
	// srawi r4,r10,17
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 17;
	// bl 0x82413660
	ctx.lr = 0x82416298;
	sub_82413660(ctx, base);
	// lwz r11,10916(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10916);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r4,r11,20,30,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x3;
	// bl 0x8241e428
	ctx.lr = 0x824162A8;
	sub_8241E428(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// std r11,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r11.u64);
	// std r11,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r11.u64);
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
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

__attribute__((alias("__imp__sub_824162D4"))) PPC_WEAK_FUNC(sub_824162D4);
PPC_FUNC_IMPL(__imp__sub_824162D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824162D8"))) PPC_WEAK_FUNC(sub_824162D8);
PPC_FUNC_IMPL(__imp__sub_824162D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
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
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d0
	ctx.lr = 0x824162EC;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// fmr f29,f5
	f29.f64 = ctx.f5.f64;
	// fmr f28,f6
	f28.f64 = ctx.f6.f64;
	// lwz r10,12440(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne 0x82416320
	if (!cr0.eq) goto loc_82416320;
	// lwz r9,12456(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82416514
	if (cr6.eq) goto loc_82416514;
loc_82416320:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r8,r11,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82416334
	if (cr0.eq) goto loc_82416334;
	// li r11,1
	r11.s64 = 1;
	// b 0x824163c0
	goto loc_824163C0;
loc_82416334:
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824163b8
	if (cr0.eq) goto loc_824163B8;
	// lwz r11,12728(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82416350
	if (cr6.eq) goto loc_82416350;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824163b8
	if (!cr6.eq) goto loc_824163B8;
loc_82416350:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416368
	if (cr6.eq) goto loc_82416368;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824163b8
	if (!cr6.eq) goto loc_824163B8;
loc_82416368:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416380
	if (cr6.eq) goto loc_82416380;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824163b8
	if (!cr6.eq) goto loc_824163B8;
loc_82416380:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416398
	if (cr6.eq) goto loc_82416398;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824163b8
	if (!cr6.eq) goto loc_824163B8;
loc_82416398:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824163b0
	if (cr6.eq) goto loc_824163B0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824163b8
	if (!cr6.eq) goto loc_824163B8;
loc_824163B0:
	// li r11,1
	r11.s64 = 1;
	// b 0x824163bc
	goto loc_824163BC;
loc_824163B8:
	// li r11,0
	r11.s64 = 0;
loc_824163BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_824163C0:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824163d4
	if (cr0.eq) goto loc_824163D4;
	// lwz r11,13180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13180);
	// lwz r7,13184(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 13184);
	// b 0x824163e8
	goto loc_824163E8;
loc_824163D4:
	// lwz r10,36(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// rlwinm r11,r10,14,18,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x3FFF;
	// rlwinm r10,r10,29,17,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x7FFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
loc_824163E8:
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// fctiwz f0,f3
	f0.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f0,f30
	f0.s64 = (f30.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f30.f64));
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x8241641c
	if (!cr6.lt) goto loc_8241641C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8241641C:
	// fctiwz f0,f4
	ctx.fpscr.disableFlushMode();
	f0.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// blt cr6,0x82416438
	if (cr6.lt) goto loc_82416438;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_82416438:
	// subf. r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	// blt 0x8241644c
	if (cr0.lt) goto loc_8241644C;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x82416454
	if (!cr6.lt) goto loc_82416454;
loc_8241644C:
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82416454:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// stfs f31,12648(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12648, temp.u32);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// stfs f30,12652(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 12652, temp.u32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// li r11,0
	r11.s64 = 0;
	// frsp f27,f0
	f27.f64 = double(float(f0.f64));
	// stfs f29,12664(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 12664, temp.u32);
	// fcfid f0,f13
	f0.f64 = double(ctx.f13.s64);
	// stfs f28,12668(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 12668, temp.u32);
	// stfs f27,12660(r31)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r31.u32 + 12660, temp.u32);
	// stw r11,12672(r31)
	PPC_STORE_U32(r31.u32 + 12672, r11.u32);
	// addi r4,r31,12676
	ctx.r4.s64 = r31.s64 + 12676;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f26,f0
	f26.f64 = double(float(f0.f64));
	// stfs f26,12656(r31)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r31.u32 + 12656, temp.u32);
	// bl 0x82415c80
	ctx.lr = 0x824164A8;
	sub_82415C80(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f0,f28,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f28.f64 - f29.f64));
	// stfs f0,10520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 10520, temp.u32);
	// stfs f29,10524(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 10524, temp.u32);
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f13,f26,f0
	ctx.f13.f64 = double(float(f26.f64 * f0.f64));
	// stfs f13,10504(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 10504, temp.u32);
	// fmuls f0,f27,f0
	f0.f64 = double(float(f27.f64 * f0.f64));
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + f31.f64));
	// stfs f13,10508(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 10508, temp.u32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,10512(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 10512, temp.u32);
	// fadds f0,f0,f30
	f0.f64 = double(float(f0.f64 + f30.f64));
	// stfs f0,10516(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 10516, temp.u32);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r11,r11,1024
	r11.u64 = r11.u64 | 67108864;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,512
	r11.u64 = r11.u64 | 33554432;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,256
	r11.u64 = r11.u64 | 16777216;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,128
	r11.u64 = r11.u64 | 8388608;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,64
	r11.u64 = r11.u64 | 4194304;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,32
	r11.u64 = r11.u64 | 2097152;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82416514:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba1c
	ctx.lr = 0x82416520;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82416530"))) PPC_WEAK_FUNC(sub_82416530);
PPC_FUNC_IMPL(__imp__sub_82416530) {
	PPC_FUNC_PROLOGUE();
	// stw r4,11856(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11856, ctx.r4.u32);
	// addi r4,r3,12676
	ctx.r4.s64 = ctx.r3.s64 + 12676;
	// b 0x82415c80
	sub_82415C80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8241653C"))) PPC_WEAK_FUNC(sub_8241653C);
PPC_FUNC_IMPL(__imp__sub_8241653C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82416540"))) PPC_WEAK_FUNC(sub_82416540);
PPC_FUNC_IMPL(__imp__sub_82416540) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lfs f6,20(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lfs f5,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f2,f11
	ctx.f2.f64 = double(float(ctx.f11.f64));
	// frsp f3,f12
	ctx.f3.f64 = double(float(ctx.f12.f64));
	// frsp f4,f13
	ctx.f4.f64 = double(float(ctx.f13.f64));
	// frsp f1,f0
	ctx.f1.f64 = double(float(f0.f64));
	// bl 0x824162d8
	ctx.lr = 0x824165B0;
	sub_824162D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824165C0"))) PPC_WEAK_FUNC(sub_824165C0);
PPC_FUNC_IMPL(__imp__sub_824165C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,24(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// lfs f6,20(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// b 0x824162d8
	sub_824162D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824165E0"))) PPC_WEAK_FUNC(sub_824165E0);
PPC_FUNC_IMPL(__imp__sub_824165E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r10,24(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// rlwinm. r11,r10,16,30,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x3;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x824165f4
	if (!cr0.eq) goto loc_824165F4;
	// li r11,0
	r11.s64 = 0;
	// b 0x8241660c
	goto loc_8241660C;
loc_824165F4:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// lis r11,0
	r11.s64 = 0;
	// bne cr6,0x82416608
	if (!cr6.eq) goto loc_82416608;
	// ori r11,r11,32769
	r11.u64 = r11.u64 | 32769;
	// b 0x8241660c
	goto loc_8241660C;
loc_82416608:
	// ori r11,r11,49155
	r11.u64 = r11.u64 | 49155;
loc_8241660C:
	// li r12,1
	r12.s64 = 1;
	// stw r11,10684(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10684, r11.u32);
	// stw r10,10368(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10368, ctx.r10.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// rldicr r12,r12,57,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 57) & 0xFFFFFFFFFFFFFFFF;
	// ld r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// or r9,r9,r12
	ctx.r9.u64 = ctx.r9.u64 | r12.u64;
	// std r9,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r9.u64);
	// li r12,1
	r12.s64 = 1;
	// ld r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// addi r9,r11,7072
	ctx.r9.s64 = r11.s64 + 7072;
	// rldicr r12,r12,36,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 36) & 0xFFFFFFFFFFFFFFFF;
	// addi r4,r10,7048
	ctx.r4.s64 = ctx.r10.s64 + 7048;
	// or r8,r8,r12
	ctx.r8.u64 = ctx.r8.u64 | r12.u64;
	// std r8,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r8.u64);
	// lwz r11,7072(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 7072);
	// stw r11,12676(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12676, r11.u32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r11,12680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12680, r11.u32);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r11,12684(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12684, r11.u32);
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stw r11,12688(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12688, r11.u32);
	// b 0x82416540
	sub_82416540(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82416670"))) PPC_WEAK_FUNC(sub_82416670);
PPC_FUNC_IMPL(__imp__sub_82416670) {
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
	ctx.lr = 0x82416678;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,3110
	r11.s64 = ctx.r4.s64 + 3110;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stwx r5,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r5.u32);
	// beq cr6,0x824167b4
	if (cr6.eq) goto loc_824167B4;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x824166a4
	if (cr6.eq) goto loc_824166A4;
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
loc_824166A4:
	// addi r10,r11,2593
	ctx.r10.s64 = r11.s64 + 2593;
	// lwz r6,28(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// lis r9,2
	ctx.r9.s64 = 131072;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r8,r9,263
	ctx.r8.u64 = ctx.r9.u64 | 263;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stwx r6,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r6.u32);
	// srawi r11,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	r11.s64 = ctx.r3.s32 >> 16;
	// clrldi r10,r3,56
	ctx.r10.u64 = ctx.r3.u64 & 0xFF;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// srd r6,r9,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// addi r10,r4,3007
	ctx.r10.s64 = ctx.r4.s64 + 3007;
	// ldx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// or r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 | ctx.r3.u64;
	// stdx r6,r11,r31
	PPC_STORE_U64(r11.u32 + r31.u32, ctx.r6.u64);
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// stwx r6,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r6.u32);
	// beq cr6,0x824167b4
	if (cr6.eq) goto loc_824167B4;
	// lwz r7,28(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r10,r7,16,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// beq cr6,0x82416728
	if (cr6.eq) goto loc_82416728;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// beq cr6,0x82416728
	if (cr6.eq) goto loc_82416728;
	// cmplwi cr6,r10,10
	cr6.compare<uint32_t>(ctx.r10.u32, 10, xer);
	// beq cr6,0x82416728
	if (cr6.eq) goto loc_82416728;
	// cmplwi cr6,r10,12
	cr6.compare<uint32_t>(ctx.r10.u32, 12, xer);
	// bne cr6,0x824167b4
	if (!cr6.eq) goto loc_824167B4;
loc_82416728:
	// rlwinm r10,r7,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 13) & 0x1;
	// xor. r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824167b4
	if (cr0.eq) goto loc_824167B4;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r7,0
	ctx.r7.s64 = 0;
	// beq cr6,0x82416744
	if (cr6.eq) goto loc_82416744;
	// addi r7,r4,1
	ctx.r7.s64 = ctx.r4.s64 + 1;
loc_82416744:
	// lwz r30,28(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r6,-1
	ctx.r10.s64 = ctx.r6.s64 + -1;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwinm r6,r30,16,28,31
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xF;
	// rlwinm r3,r30,15,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 15) & 0x7;
	// addi r6,r6,3
	ctx.r6.s64 = ctx.r6.s64 + 3;
	// addi r3,r3,-3
	ctx.r3.s64 = ctx.r3.s64 + -3;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// and r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 & ctx.r10.u64;
	// andc r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r10.u64;
	// rlwinm r6,r30,0,16,11
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 | ctx.r3.u64;
	// addi r29,r7,2593
	r29.s64 = ctx.r7.s64 + 2593;
	// rlwinm r3,r3,16,12,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xF0000;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// or r7,r6,r3
	ctx.r7.u64 = ctx.r6.u64 | ctx.r3.u64;
	// clrldi r6,r8,56
	ctx.r6.u64 = ctx.r8.u64 & 0xFF;
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// srawi r11,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	r11.s64 = ctx.r8.s32 >> 16;
	// srd r9,r9,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r6.u8 & 0x7F));
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r10,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// rlwinm r8,r8,0,16,11
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 | ctx.r3.u64;
	// stwx r8,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r8.u32);
	// ldx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stdx r10,r11,r31
	PPC_STORE_U64(r11.u32 + r31.u32, ctx.r10.u64);
loc_824167B4:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82416930
	if (!cr6.eq) goto loc_82416930;
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// andi. r10,r11,247
	ctx.r10.u64 = r11.u64 & 247;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r10,10943(r31)
	PPC_STORE_U8(r31.u32 + 10943, ctx.r10.u8);
	// beq cr6,0x8241680c
	if (cr6.eq) goto loc_8241680C;
	// lhz r11,28(r5)
	r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 28);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// beq cr6,0x824167f0
	if (cr6.eq) goto loc_824167F0;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// beq cr6,0x824167f0
	if (cr6.eq) goto loc_824167F0;
	// cmplwi cr6,r11,15
	cr6.compare<uint32_t>(r11.u32, 15, xer);
	// bne cr6,0x82416804
	if (!cr6.eq) goto loc_82416804;
loc_824167F0:
	// ori r11,r10,8
	r11.u64 = ctx.r10.u64 | 8;
	// stb r11,10943(r31)
	PPC_STORE_U8(r31.u32 + 10943, r11.u8);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r11,r11,16
	r11.u64 = r11.u64 | 1048576;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82416804:
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x82416818
	goto loc_82416818;
loc_8241680C:
	// lwz r4,12456(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82416820
	if (cr6.eq) goto loc_82416820;
loc_82416818:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824165e0
	ctx.lr = 0x82416820;
	sub_824165E0(ctx, base);
loc_82416820:
	// lwz r11,12716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12716);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824168f8
	if (!cr6.eq) goto loc_824168F8;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x824168f8
	if (!cr0.eq) goto loc_824168F8;
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x824168f8
	if (!cr0.eq) goto loc_824168F8;
	// lbz r10,12187(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne 0x824168f8
	if (!cr0.eq) goto loc_824168F8;
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8241685c
	if (cr0.eq) goto loc_8241685C;
	// li r11,1
	r11.s64 = 1;
	// b 0x824168ec
	goto loc_824168EC;
loc_8241685C:
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824168e4
	if (cr0.eq) goto loc_824168E4;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241687c
	if (cr6.eq) goto loc_8241687C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824168e4
	if (!cr6.eq) goto loc_824168E4;
loc_8241687C:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416894
	if (cr6.eq) goto loc_82416894;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824168e4
	if (!cr6.eq) goto loc_824168E4;
loc_82416894:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824168ac
	if (cr6.eq) goto loc_824168AC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824168e4
	if (!cr6.eq) goto loc_824168E4;
loc_824168AC:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824168c4
	if (cr6.eq) goto loc_824168C4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824168e4
	if (!cr6.eq) goto loc_824168E4;
loc_824168C4:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824168dc
	if (cr6.eq) goto loc_824168DC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824168e4
	if (!cr6.eq) goto loc_824168E4;
loc_824168DC:
	// li r11,1
	r11.s64 = 1;
	// b 0x824168e8
	goto loc_824168E8;
loc_824168E4:
	// li r11,0
	r11.s64 = 0;
loc_824168E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_824168EC:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne 0x824168fc
	if (!cr0.eq) goto loc_824168FC;
loc_824168F8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824168FC:
	// lbz r9,10940(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// lwz r11,11860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11860);
	// rlwimi r9,r10,0,31,31
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x1) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFE);
	// stb r9,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, ctx.r9.u8);
	// lwz r10,12440(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,11860(r31)
	PPC_STORE_U32(r31.u32 + 11860, r11.u32);
	// bne cr6,0x82416920
	if (!cr6.eq) goto loc_82416920;
	// li r11,0
	r11.s64 = 0;
loc_82416920:
	// lwz r10,10460(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10460);
	// rlwimi r11,r10,0,0,27
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFFFFFF0) | (r11.u64 & 0xFFFFFFFF0000000F);
	// stw r11,10460(r31)
	PPC_STORE_U32(r31.u32 + 10460, r11.u32);
	// b 0x824169b4
	goto loc_824169B4;
loc_82416930:
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// bne cr6,0x8241695c
	if (!cr6.eq) goto loc_8241695C;
	// lwz r11,11864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11864);
	// lwz r10,12444(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,11864(r31)
	PPC_STORE_U32(r31.u32 + 11864, r11.u32);
	// bne cr6,0x82416950
	if (!cr6.eq) goto loc_82416950;
	// li r11,0
	r11.s64 = 0;
loc_82416950:
	// lwz r10,10460(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10460);
	// rlwimi r10,r11,4,24,27
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xF0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF0F);
	// b 0x824169b0
	goto loc_824169B0;
loc_8241695C:
	// cmplwi cr6,r4,2
	cr6.compare<uint32_t>(ctx.r4.u32, 2, xer);
	// bne cr6,0x82416988
	if (!cr6.eq) goto loc_82416988;
	// lwz r11,11868(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11868);
	// lwz r10,12448(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,11868(r31)
	PPC_STORE_U32(r31.u32 + 11868, r11.u32);
	// bne cr6,0x8241697c
	if (!cr6.eq) goto loc_8241697C;
	// li r11,0
	r11.s64 = 0;
loc_8241697C:
	// lwz r10,10460(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10460);
	// rlwimi r10,r11,8,20,23
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF0FF);
	// b 0x824169b0
	goto loc_824169B0;
loc_82416988:
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bne cr6,0x824169c8
	if (!cr6.eq) goto loc_824169C8;
	// lwz r11,11872(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11872);
	// lwz r10,12452(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,11872(r31)
	PPC_STORE_U32(r31.u32 + 11872, r11.u32);
	// bne cr6,0x824169a8
	if (!cr6.eq) goto loc_824169A8;
	// li r11,0
	r11.s64 = 0;
loc_824169A8:
	// lwz r10,10460(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10460);
	// rlwimi r10,r11,12,16,19
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 12) & 0xF000) | (ctx.r10.u64 & 0xFFFFFFFFFFFF0FFF);
loc_824169B0:
	// stw r10,10460(r31)
	PPC_STORE_U32(r31.u32 + 10460, ctx.r10.u32);
loc_824169B4:
	// li r12,1
	r12.s64 = 1;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_824169C8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824169D0"))) PPC_WEAK_FUNC(sub_824169D0);
PPC_FUNC_IMPL(__imp__sub_824169D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r30,12456(r31)
	PPC_STORE_U32(r31.u32 + 12456, r30.u32);
	// beq cr6,0x82416b14
	if (cr6.eq) goto loc_82416B14;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416a08
	if (!cr6.eq) goto loc_82416A08;
	// bl 0x824165e0
	ctx.lr = 0x82416A08;
	sub_824165E0(ctx, base);
loc_82416A08:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// stw r11,10376(r31)
	PPC_STORE_U32(r31.u32 + 10376, r11.u32);
	// lbz r10,10942(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// lbz r9,10943(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// rlwinm. r9,r9,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// stw r11,10560(r31)
	PPC_STORE_U32(r31.u32 + 10560, r11.u32);
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// rlwimi r10,r11,5,26,26
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 5) & 0x20) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r10,10942(r31)
	PPC_STORE_U8(r31.u32 + 10942, ctx.r10.u8);
	// beq 0x82416af0
	if (cr0.eq) goto loc_82416AF0;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82416a48
	if (cr0.eq) goto loc_82416A48;
	// li r11,1
	r11.s64 = 1;
	// b 0x82416ad8
	goto loc_82416AD8;
loc_82416A48:
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82416ad0
	if (cr0.eq) goto loc_82416AD0;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416a68
	if (cr6.eq) goto loc_82416A68;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416ad0
	if (!cr6.eq) goto loc_82416AD0;
loc_82416A68:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416a80
	if (cr6.eq) goto loc_82416A80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416ad0
	if (!cr6.eq) goto loc_82416AD0;
loc_82416A80:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416a98
	if (cr6.eq) goto loc_82416A98;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416ad0
	if (!cr6.eq) goto loc_82416AD0;
loc_82416A98:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416ab0
	if (cr6.eq) goto loc_82416AB0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416ad0
	if (!cr6.eq) goto loc_82416AD0;
loc_82416AB0:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416ac8
	if (cr6.eq) goto loc_82416AC8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416ad0
	if (!cr6.eq) goto loc_82416AD0;
loc_82416AC8:
	// li r11,1
	r11.s64 = 1;
	// b 0x82416ad4
	goto loc_82416AD4;
loc_82416AD0:
	// li r11,0
	r11.s64 = 0;
loc_82416AD4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_82416AD8:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82416af0
	if (cr0.eq) goto loc_82416AF0;
	// lwz r11,10368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10368);
	// lwz r10,13172(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13172);
	// rlwimi r11,r10,18,0,13
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 18) & 0xFFFC0000) | (r11.u64 & 0xFFFFFFFF0003FFFF);
	// stw r11,10368(r31)
	PPC_STORE_U32(r31.u32 + 10368, r11.u32);
loc_82416AF0:
	// li r12,1
	r12.s64 = 1;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// rldicr r12,r12,55,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 55) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// b 0x82416b34
	goto loc_82416B34;
loc_82416B14:
	// lwz r11,10560(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// lbz r10,10942(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// rlwinm r11,r11,0,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// andi. r10,r10,223
	ctx.r10.u64 = ctx.r10.u64 & 223;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,10560(r31)
	PPC_STORE_U32(r31.u32 + 10560, r11.u32);
	// stb r10,10942(r31)
	PPC_STORE_U8(r31.u32 + 10942, ctx.r10.u8);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
loc_82416B34:
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// lwz r11,12716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12716);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416c10
	if (!cr6.eq) goto loc_82416C10;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82416c10
	if (!cr0.eq) goto loc_82416C10;
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82416c10
	if (!cr0.eq) goto loc_82416C10;
	// lbz r10,12187(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne 0x82416c10
	if (!cr0.eq) goto loc_82416C10;
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82416b74
	if (cr0.eq) goto loc_82416B74;
	// li r11,1
	r11.s64 = 1;
	// b 0x82416c04
	goto loc_82416C04;
loc_82416B74:
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82416bfc
	if (cr0.eq) goto loc_82416BFC;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416b94
	if (cr6.eq) goto loc_82416B94;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416bfc
	if (!cr6.eq) goto loc_82416BFC;
loc_82416B94:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416bac
	if (cr6.eq) goto loc_82416BAC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416bfc
	if (!cr6.eq) goto loc_82416BFC;
loc_82416BAC:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416bc4
	if (cr6.eq) goto loc_82416BC4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416bfc
	if (!cr6.eq) goto loc_82416BFC;
loc_82416BC4:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416bdc
	if (cr6.eq) goto loc_82416BDC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416bfc
	if (!cr6.eq) goto loc_82416BFC;
loc_82416BDC:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82416bf4
	if (cr6.eq) goto loc_82416BF4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82416bfc
	if (!cr6.eq) goto loc_82416BFC;
loc_82416BF4:
	// li r11,1
	r11.s64 = 1;
	// b 0x82416c00
	goto loc_82416C00;
loc_82416BFC:
	// li r11,0
	r11.s64 = 0;
loc_82416C00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_82416C04:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne 0x82416c14
	if (!cr0.eq) goto loc_82416C14;
loc_82416C10:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82416C14:
	// lbz r9,10940(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// lwz r11,11876(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11876);
	// rlwimi r9,r10,0,31,31
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x1) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFE);
	// stb r9,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, ctx.r9.u8);
	// lwz r10,12456(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,11876(r31)
	PPC_STORE_U32(r31.u32 + 11876, r11.u32);
	// bne cr6,0x82416c38
	if (!cr6.eq) goto loc_82416C38;
	// li r11,0
	r11.s64 = 0;
loc_82416C38:
	// lwz r10,10548(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10548);
	// rlwimi r10,r11,1,30,30
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 1) & 0x2) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFD);
	// stw r10,10548(r31)
	PPC_STORE_U32(r31.u32 + 10548, ctx.r10.u32);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// lwz r10,12456(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r11,11880(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11880);
	// stw r11,11880(r31)
	PPC_STORE_U32(r31.u32 + 11880, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82416c70
	if (!cr6.eq) goto loc_82416C70;
	// li r11,0
	r11.s64 = 0;
loc_82416C70:
	// lwz r10,10548(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10548);
	// rlwimi r11,r10,0,0,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFFFFFFE) | (r11.u64 & 0xFFFFFFFF00000001);
	// stw r11,10548(r31)
	PPC_STORE_U32(r31.u32 + 10548, r11.u32);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
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

__attribute__((alias("__imp__sub_82416CA8"))) PPC_WEAK_FUNC(sub_82416CA8);
PPC_FUNC_IMPL(__imp__sub_82416CA8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82416670
	sub_82416670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82416CAC"))) PPC_WEAK_FUNC(sub_82416CAC);
PPC_FUNC_IMPL(__imp__sub_82416CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82416CB0"))) PPC_WEAK_FUNC(sub_82416CB0);
PPC_FUNC_IMPL(__imp__sub_82416CB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82416CB8;
	// lis r10,42
	ctx.r10.s64 = 2752512;
	// lis r9,24
	ctx.r9.s64 = 1572864;
	// lis r5,44
	ctx.r5.s64 = 2883584;
	// li r11,0
	r11.s64 = 0;
	// andi. r7,r3,16398
	ctx.r7.u64 = ctx.r3.u64 & 16398;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ori r6,r10,9145
	ctx.r6.u64 = ctx.r10.u64 | 9145;
	// ori r31,r9,10374
	r31.u64 = ctx.r9.u64 | 10374;
	// ori r30,r5,33700
	r30.u64 = ctx.r5.u64 | 33700;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r10,r4,52
	ctx.r10.s64 = ctx.r4.s64 + 52;
	// cmplwi cr6,r7,2
	cr6.compare<uint32_t>(ctx.r7.u32, 2, xer);
	// beq cr6,0x82417030
	if (cr6.eq) goto loc_82417030;
	// cmplwi cr6,r7,6
	cr6.compare<uint32_t>(ctx.r7.u32, 6, xer);
	// beq cr6,0x82416fb0
	if (cr6.eq) goto loc_82416FB0;
	// cmplwi cr6,r7,8
	cr6.compare<uint32_t>(ctx.r7.u32, 8, xer);
	// beq cr6,0x82416f34
	if (cr6.eq) goto loc_82416F34;
	// cmplwi cr6,r7,10
	cr6.compare<uint32_t>(ctx.r7.u32, 10, xer);
	// beq cr6,0x82416ea0
	if (cr6.eq) goto loc_82416EA0;
	// cmplwi cr6,r7,12
	cr6.compare<uint32_t>(ctx.r7.u32, 12, xer);
	// beq cr6,0x82416ddc
	if (cr6.eq) goto loc_82416DDC;
	// cmplwi cr6,r7,14
	cr6.compare<uint32_t>(ctx.r7.u32, 14, xer);
	// beq cr6,0x82416d34
	if (cr6.eq) goto loc_82416D34;
	// cmplwi cr6,r7,16386
	cr6.compare<uint32_t>(ctx.r7.u32, 16386, xer);
	// bne cr6,0x82417054
	if (!cr6.eq) goto loc_82417054;
	// lis r9,26
	ctx.r9.s64 = 1703936;
	// ori r7,r9,9126
	ctx.r7.u64 = ctx.r9.u64 | 9126;
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// b 0x82417038
	goto loc_82417038;
loc_82416D34:
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// lis r9,26
	ctx.r9.s64 = 1703936;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// ori r9,r9,9126
	ctx.r9.u64 = ctx.r9.u64 | 9126;
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// rlwinm. r7,r3,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stb r11,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r11.u8);
	// li r7,2
	ctx.r7.s64 = 2;
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// sth r8,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r8.u16);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r5,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r5.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// stb r7,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r7.u8);
	// beq 0x82416da8
	if (cr0.eq) goto loc_82416DA8;
	// lis r9,26
	ctx.r9.s64 = 1703936;
	// li r8,28
	ctx.r8.s64 = 28;
	// ori r9,r9,8838
	ctx.r9.u64 = ctx.r9.u64 | 8838;
	// sth r8,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r8.u16);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// b 0x82417044
	goto loc_82417044;
loc_82416DA8:
	// rlwinm. r9,r3,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// li r9,28
	ctx.r9.s64 = 28;
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// li r8,3
	ctx.r8.s64 = 3;
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// li r9,32
	ctx.r9.s64 = 32;
	// beq 0x82416dd4
	if (cr0.eq) goto loc_82416DD4;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x82417050
	goto loc_82417050;
loc_82416DD4:
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
	// b 0x82417050
	goto loc_82417050;
loc_82416DDC:
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// rlwinm. r9,r3,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r11,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r11.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r5,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r5.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// beq 0x82416e48
	if (cr0.eq) goto loc_82416E48;
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// li r7,24
	ctx.r7.s64 = 24;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// li r9,28
	ctx.r9.s64 = 28;
loc_82416E24:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// lis r8,26
	ctx.r8.s64 = 1703936;
	// li r28,2
	r28.s64 = 2;
	// ori r29,r8,8838
	r29.u64 = ctx.r8.u64 | 8838;
	// li r8,3
	ctx.r8.s64 = 3;
	// sth r7,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r7.u16);
	// stw r29,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r29.u32);
	// stb r28,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r28.u8);
	// b 0x82417044
	goto loc_82417044;
loc_82416E48:
	// rlwinm. r9,r3,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82416e80
	if (cr0.eq) goto loc_82416E80;
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// li r7,24
	ctx.r7.s64 = 24;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// li r9,28
	ctx.r9.s64 = 28;
loc_82416E64:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// li r29,2
	r29.s64 = 2;
	// li r8,3
	ctx.r8.s64 = 3;
	// sth r7,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r7.u16);
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// stb r29,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r29.u8);
	// b 0x82417044
	goto loc_82417044;
loc_82416E80:
	// lis r9,26
	ctx.r9.s64 = 1703936;
	// li r8,12
	ctx.r8.s64 = 12;
	// ori r9,r9,9126
	ctx.r9.u64 = ctx.r9.u64 | 9126;
	// sth r8,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r8.u16);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// li r9,28
	ctx.r9.s64 = 28;
	// b 0x82417050
	goto loc_82417050;
loc_82416EA0:
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// rlwinm. r9,r3,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r11,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r11.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r5,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r5.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// beq 0x82416ef4
	if (cr0.eq) goto loc_82416EF4;
	// lis r9,44
	ctx.r9.s64 = 2883584;
	// li r8,12
	ctx.r8.s64 = 12;
	// ori r9,r9,9125
	ctx.r9.u64 = ctx.r9.u64 | 9125;
	// sth r8,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r8.u16);
	// li r7,20
	ctx.r7.s64 = 20;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// li r9,24
	ctx.r9.s64 = 24;
	// b 0x82416e24
	goto loc_82416E24;
loc_82416EF4:
	// rlwinm. r9,r3,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82416f1c
	if (cr0.eq) goto loc_82416F1C;
	// lis r9,44
	ctx.r9.s64 = 2883584;
	// li r8,12
	ctx.r8.s64 = 12;
	// ori r9,r9,9125
	ctx.r9.u64 = ctx.r9.u64 | 9125;
	// sth r8,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r8.u16);
	// li r7,20
	ctx.r7.s64 = 20;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// li r9,24
	ctx.r9.s64 = 24;
	// b 0x82416e64
	goto loc_82416E64;
loc_82416F1C:
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// li r9,24
	ctx.r9.s64 = 24;
	// b 0x82417050
	goto loc_82417050;
loc_82416F34:
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// rlwinm. r9,r3,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r11,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r11.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r5,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r5.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// beq 0x82416f80
	if (cr0.eq) goto loc_82416F80;
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
loc_82416F6C:
	// li r9,12
	ctx.r9.s64 = 12;
	// li r7,16
	ctx.r7.s64 = 16;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// li r9,20
	ctx.r9.s64 = 20;
	// b 0x82416e24
	goto loc_82416E24;
loc_82416F80:
	// rlwinm. r9,r3,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82416f90
	if (cr0.eq) goto loc_82416F90;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x82416f6c
	goto loc_82416F6C;
loc_82416F90:
	// lis r9,44
	ctx.r9.s64 = 2883584;
	// li r8,12
	ctx.r8.s64 = 12;
	// ori r9,r9,9125
	ctx.r9.u64 = ctx.r9.u64 | 9125;
	// sth r8,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r8.u16);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// li r9,20
	ctx.r9.s64 = 20;
	// b 0x82417050
	goto loc_82417050;
loc_82416FB0:
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// rlwinm. r9,r3,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r11,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r11.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// beq 0x82416ff8
	if (cr0.eq) goto loc_82416FF8;
	// lis r9,26
	ctx.r9.s64 = 1703936;
	// stb r8,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r8.u8);
	// li r7,12
	ctx.r7.s64 = 12;
	// ori r9,r9,8838
	ctx.r9.u64 = ctx.r9.u64 | 8838;
	// sth r7,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r7.u16);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// b 0x82417044
	goto loc_82417044;
loc_82416FF8:
	// rlwinm. r9,r3,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// li r9,12
	ctx.r9.s64 = 12;
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// li r9,16
	ctx.r9.s64 = 16;
	// beq 0x82417024
	if (cr0.eq) goto loc_82417024;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// stb r8,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r8.u8);
	// b 0x82417050
	goto loc_82417050;
loc_82417024:
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
	// stb r5,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r5.u8);
	// b 0x82417050
	goto loc_82417050;
loc_82417030:
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
loc_82417038:
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// stb r11,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r11.u8);
loc_82417044:
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
loc_82417050:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_82417054:
	// rlwinm. r7,r3,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq 0x8241708c
	if (cr0.eq) goto loc_8241708C;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// li r9,3
	ctx.r9.s64 = 3;
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// addi r7,r7,12
	ctx.r7.s64 = ctx.r7.s64 + 12;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stb r9,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r9.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// clrlwi r9,r7,16
	ctx.r9.u64 = ctx.r7.u32 & 0xFFFF;
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_8241708C:
	// rlwinm. r7,r3,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq 0x824170c4
	if (cr0.eq) goto loc_824170C4;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// li r9,4
	ctx.r9.s64 = 4;
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
	// stb r9,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r9.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// clrlwi r9,r7,16
	ctx.r9.u64 = ctx.r7.u32 & 0xFFFF;
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_824170C4:
	// rlwinm. r7,r3,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// li r6,10
	ctx.r6.s64 = 10;
	// beq 0x824170fc
	if (cr0.eq) goto loc_824170FC;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r7,4
	ctx.r9.s64 = ctx.r7.s64 + 4;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r6,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r6.u8);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// stb r11,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r11.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_824170FC:
	// rlwinm. r7,r3,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq 0x82417130
	if (cr0.eq) goto loc_82417130;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r7,4
	ctx.r9.s64 = ctx.r7.s64 + 4;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r6,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, ctx.r6.u8);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// stb r5,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, ctx.r5.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_82417130:
	// rlwinm. r31,r3,24,28,31
	r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xF;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// rlwinm r6,r3,16,16,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// beq 0x824171a4
	if (cr0.eq) goto loc_824171A4;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// add r8,r31,r8
	ctx.r8.u64 = r31.u64 + ctx.r8.u64;
	// addi r5,r5,7304
	ctx.r5.s64 = ctx.r5.s64 + 7304;
loc_8241714C:
	// clrlwi r30,r6,30
	r30.u64 = ctx.r6.u32 & 0x3;
	// addi r29,r5,-4
	r29.s64 = ctx.r5.s64 + -4;
	// clrlwi r3,r9,16
	ctx.r3.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// li r27,5
	r27.s64 = 5;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lbzx r30,r30,r29
	r30.u64 = PPC_LOAD_U8(r30.u32 + r29.u32);
	// rlwinm r6,r6,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// cmplw cr6,r7,r31
	cr6.compare<uint32_t>(ctx.r7.u32, r31.u32, xer);
	// rlwinm r9,r30,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFC;
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// add r30,r9,r5
	r30.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r9,r3,r9
	ctx.r9.u64 = ctx.r3.u64 + ctx.r9.u64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r3,-4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// stb r11,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, r11.u8);
	// stb r27,9(r10)
	PPC_STORE_U8(ctx.r10.u32 + 9, r27.u8);
	// stb r28,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, r28.u8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// blt cr6,0x8241714c
	if (cr6.lt) goto loc_8241714C;
loc_824171A4:
	// li r7,255
	ctx.r7.s64 = 255;
	// sth r11,-62(r1)
	PPC_STORE_U16(ctx.r1.u32 + -62, r11.u16);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r11,-56(r1)
	PPC_STORE_U8(ctx.r1.u32 + -56, r11.u8);
	// sth r7,-64(r1)
	PPC_STORE_U16(ctx.r1.u32 + -64, ctx.r7.u16);
	// lwz r7,-64(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -64);
	// stb r11,-55(r1)
	PPC_STORE_U8(ctx.r1.u32 + -55, r11.u8);
	// stb r11,-54(r1)
	PPC_STORE_U8(ctx.r1.u32 + -54, r11.u8);
	// lwz r6,-56(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -56);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// stw r8,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r8.u32);
	// stw r11,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, r11.u32);
	// stw r11,48(r4)
	PPC_STORE_U32(ctx.r4.u32 + 48, r11.u32);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824171E4"))) PPC_WEAK_FUNC(sub_824171E4);
PPC_FUNC_IMPL(__imp__sub_824171E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824171E8"))) PPC_WEAK_FUNC(sub_824171E8);
PPC_FUNC_IMPL(__imp__sub_824171E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91cc
	ctx.lr = 0x824171F0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// addi r11,r31,-4
	r11.s64 = r31.s64 + -4;
	// ori r10,r10,15104
	ctx.r10.u64 = ctx.r10.u64 | 15104;
	// li r9,768
	ctx.r9.s64 = 768;
	// lis r8,-16359
	ctx.r8.s64 = -1072103424;
	// li r7,24
	ctx.r7.s64 = 24;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// ori r8,r8,11008
	ctx.r8.u64 = ctx.r8.u64 | 11008;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r29,r6,7168
	r29.s64 = ctx.r6.s64 + 7168;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// mr r30,r11
	r30.u64 = r11.u64;
	// stwu r7,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r30.u32 = ea;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x82417248;
	sub_823DA950(ctx, base);
	// addi r11,r30,96
	r11.s64 = r30.s64 + 96;
	// lis r10,-16374
	ctx.r10.s64 = -1073086464;
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r10,r10,11008
	ctx.r10.u64 = ctx.r10.u64 | 11008;
	// li r8,9
	ctx.r8.s64 = 9;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// addi r4,r29,96
	ctx.r4.s64 = r29.s64 + 96;
	// li r5,36
	ctx.r5.s64 = 36;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// mr r30,r11
	r30.u64 = r11.u64;
	// stwu r8,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r30.u32 = ea;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x8241727C;
	sub_823DA950(ctx, base);
	// addi r11,r30,36
	r11.s64 = r30.s64 + 36;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// ori r10,r10,8576
	ctx.r10.u64 = ctx.r10.u64 | 8576;
	// ori r9,r9,14
	ctx.r9.u64 = ctx.r9.u64 | 14;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r8,r8,8448
	ctx.r8.u64 = ctx.r8.u64 | 8448;
	// ori r7,r7,65535
	ctx.r7.u64 = ctx.r7.u64 | 65535;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r5,8851
	ctx.r5.s64 = 8851;
	// li r4,0
	ctx.r4.s64 = 0;
	// lis r3,2
	ctx.r3.s64 = 131072;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lis r30,0
	r30.s64 = 0;
	// ori r3,r3,8708
	ctx.r3.u64 = ctx.r3.u64 | 8708;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r22,8
	r22.s64 = 524288;
	// lis r29,1
	r29.s64 = 65536;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// li r28,768
	r28.s64 = 768;
	// li r27,8978
	r27.s64 = 8978;
	// ori r30,r30,65535
	r30.u64 = r30.u64 | 65535;
	// li r26,8205
	r26.s64 = 8205;
	// li r8,0
	ctx.r8.s64 = 0;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// li r25,8704
	r25.s64 = 8704;
	// li r24,0
	r24.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r23,8832
	r23.s64 = 8832;
	// li r21,8962
	r21.s64 = 8962;
	// stwu r6,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r11.u32 = ea;
	// li r6,8712
	ctx.r6.s64 = 8712;
	// ori r22,r22,8
	r22.u64 = r22.u64 | 8;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// li r9,8707
	ctx.r9.s64 = 8707;
	// stwu r5,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	r11.u32 = ea;
	// li r5,4
	ctx.r5.s64 = 4;
	// stwu r4,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r11.u32 = ea;
	// li r4,8452
	ctx.r4.s64 = 8452;
	// stwu r3,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	r11.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r29,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r29.u32);
	r11.u32 = ea;
	// li r10,4
	ctx.r10.s64 = 4;
	// lis r20,2
	r20.s64 = 131072;
	// li r19,0
	r19.s64 = 0;
	// ori r20,r20,8320
	r20.u64 = r20.u64 | 8320;
	// li r18,0
	r18.s64 = 0;
	// stwu r28,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r28.u32);
	r11.u32 = ea;
	// lis r17,16
	r17.s64 = 1048576;
	// ori r29,r17,16
	r29.u64 = r17.u64 | 16;
	// stwu r27,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r27.u32);
	r11.u32 = ea;
	// stwu r30,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r30.u32);
	r11.u32 = ea;
	// stwu r26,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r26.u32);
	r11.u32 = ea;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r25,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r25.u32);
	r11.u32 = ea;
	// stwu r24,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r24.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// stwu r6,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r11.u32 = ea;
	// stwu r5,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	r11.u32 = ea;
	// stwu r4,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r11.u32 = ea;
	// stwu r3,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	r11.u32 = ea;
	// stwu r23,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r23.u32);
	r11.u32 = ea;
	// stwu r22,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r22.u32);
	r11.u32 = ea;
	// stwu r21,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r21.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r20,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r20.u32);
	r11.u32 = ea;
	// stwu r19,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r19.u32);
	r11.u32 = ea;
	// stwu r18,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r18.u32);
	r11.u32 = ea;
	// stwu r29,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r29.u32);
	r11.u32 = ea;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// srawi r3,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r3.s64 = r11.s32 >> 2;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_824173C0"))) PPC_WEAK_FUNC(sub_824173C0);
PPC_FUNC_IMPL(__imp__sub_824173C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister r12{};
	// li r12,1
	r12.s64 = 1;
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// li r10,1
	ctx.r10.s64 = 1;
	// rldicr r12,r12,41,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 41) & 0xFFFFFFFFFFFFFFFF;
	// or r9,r11,r12
	ctx.r9.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// rldicr r11,r10,35,63
	r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 35) & 0xFFFFFFFFFFFFFFFF;
	// std r9,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r9.u64);
	// rldicr r12,r12,40,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 40) & 0xFFFFFFFFFFFFFFFF;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// rldicr r12,r12,39,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 39) & 0xFFFFFFFFFFFFFFFF;
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | r11.u64;
	// std r10,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r10.u64);
	// rldicr r12,r12,44,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 44) & 0xFFFFFFFFFFFFFFFF;
	// ld r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// ori r10,r10,64
	ctx.r10.u64 = ctx.r10.u64 | 64;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// ld r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// oris r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 524288;
	// std r10,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r10.u64);
	// ld r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// oris r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 524288;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// oris r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 1048576;
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// ori r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 2048;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// ori r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 256;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// ori r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 8;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// rldicr r12,r12,54,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 54) & 0xFFFFFFFFFFFFFFFF;
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// std r10,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r10.u64);
	// ld r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// oris r11,r11,32768
	r11.u64 = r11.u64 | 2147483648;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// lwz r11,10436(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10436);
	// lwz r10,10440(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10440);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r10,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r7,r9,17
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 17;
	// rlwinm r11,r11,17,0,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// srawi r6,r10,17
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 17;
	// srawi r5,r8,17
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 17;
	// srawi r4,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	ctx.r4.s64 = r11.s32 >> 17;
	// b 0x82413660
	sub_82413660(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824174D8"))) PPC_WEAK_FUNC(sub_824174D8);
PPC_FUNC_IMPL(__imp__sub_824174D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	uint32_t ea{};
	// addi r11,r5,-4
	r11.s64 = ctx.r5.s64 + -4;
	// li r10,1480
	ctx.r10.s64 = 1480;
	// neg r9,r4
	ctx.r9.s64 = -ctx.r4.s64;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// rlwimi r9,r4,8,17,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0x7F00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF80FF);
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// rlwinm r9,r9,4,13,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0x7FFF0;
	// ori r7,r10,36096
	ctx.r7.u64 = ctx.r10.u64 | 36096;
	// rlwinm r9,r9,0,21,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// li r10,8
	ctx.r10.s64 = 8;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
loc_82417510:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// bne 0x82417510
	if (!cr0.eq) goto loc_82417510;
	// li r10,3328
	ctx.r10.s64 = 3328;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// srawi r3,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r3.s64 = r11.s32 >> 2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82417538"))) PPC_WEAK_FUNC(sub_82417538);
PPC_FUNC_IMPL(__imp__sub_82417538) {
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
	ctx.lr = 0x82417540;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// li r3,8192
	ctx.r3.s64 = 8192;
	// bl 0x82130b50
	ctx.lr = 0x82417554;
	sub_82130B50(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r30,8192
	r29.s64 = r30.s64 + 8192;
	// bne 0x82417568
	if (!cr0.eq) goto loc_82417568;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82417660
	goto loc_82417660;
loc_82417568:
	// stw r30,13780(r31)
	PPC_STORE_U32(r31.u32 + 13780, r30.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824171e8
	ctx.lr = 0x8241757C;
	sub_824171E8(ctx, base);
	// rlwinm r11,r30,12,20,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r30,3
	ctx.r10.u64 = r30.u32 & 0x1FFFFFFF;
	// lwz r9,13784(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 13784);
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// addi r8,r3,7
	ctx.r8.s64 = ctx.r3.s64 + 7;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// rlwimi r3,r9,0,0,7
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFF000000) | (ctx.r3.u64 & 0xFFFFFFFF00FFFFFF);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFE0;
	// stw r3,13784(r31)
	PPC_STORE_U32(r31.u32 + 13784, ctx.r3.u32);
	// stw r10,13788(r31)
	PPC_STORE_U32(r31.u32 + 13788, ctx.r10.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// add r5,r11,r30
	ctx.r5.u64 = r11.u64 + r30.u64;
	// addi r30,r31,13920
	r30.s64 = r31.s64 + 13920;
loc_824175B4:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824174d8
	ctx.lr = 0x824175C0;
	sub_824174D8(ctx, base);
	// rlwinm r11,r5,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 12) & 0xFFF;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r10,r5,3
	ctx.r10.u64 = ctx.r5.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// addi r7,r3,7
	ctx.r7.s64 = ctx.r3.s64 + 7;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwimi r8,r9,0,0,7
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFF000000) | (ctx.r8.u64 & 0xFFFFFFFF00FFFFFF);
	// rlwinm r11,r7,2,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFE0;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// add r5,r11,r5
	ctx.r5.u64 = r11.u64 + ctx.r5.u64;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplwi cr6,r4,112
	cr6.compare<uint32_t>(ctx.r4.u32, 112, xer);
	// ble cr6,0x824175b4
	if (!cr6.gt) goto loc_824175B4;
	// addi r11,r5,-4
	r11.s64 = ctx.r5.s64 + -4;
	// li r10,24
	ctx.r10.s64 = 24;
loc_8241760C:
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// ori r9,r9,13824
	ctx.r9.u64 = ctx.r9.u64 | 13824;
	// ori r8,r8,129
	ctx.r8.u64 = ctx.r8.u64 | 129;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// bne 0x8241760c
	if (!cr0.eq) goto loc_8241760C;
	// rlwinm r10,r5,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 12) & 0xFFF;
	// lwz r9,14816(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 14816);
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r11,r10,0,19,19
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// clrlwi r10,r5,3
	ctx.r10.u64 = ctx.r5.u32 & 0x1FFFFFFF;
	// srawi r8,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwimi r8,r9,0,0,7
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFF000000) | (ctx.r8.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r11,14820(r31)
	PPC_STORE_U32(r31.u32 + 14820, r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,14816(r31)
	PPC_STORE_U32(r31.u32 + 14816, ctx.r8.u32);
loc_82417660:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82417668"))) PPC_WEAK_FUNC(sub_82417668);
PPC_FUNC_IMPL(__imp__sub_82417668) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,13780(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13780);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// b 0x821310f8
	sub_821310F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82417674"))) PPC_WEAK_FUNC(sub_82417674);
PPC_FUNC_IMPL(__imp__sub_82417674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82417678"))) PPC_WEAK_FUNC(sub_82417678);
PPC_FUNC_IMPL(__imp__sub_82417678) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r10,r4,120
	ctx.r10.s64 = ctx.r4.s64 + 120;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// dcbt r0,r11
	// li r8,128
	ctx.r8.s64 = 128;
	// dcbt r8,r11
	// li r4,16
	ctx.r4.s64 = 16;
	// cmplwi cr6,r6,3
	cr6.compare<uint32_t>(ctx.r6.u32, 3, xer);
	// ble cr6,0x8241771c
	if (!cr6.gt) goto loc_8241771C;
	// addi r8,r6,-4
	ctx.r8.s64 = ctx.r6.s64 + -4;
	// li r5,32
	ctx.r5.s64 = 32;
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_824176BC:
	// li r31,256
	r31.s64 = 256;
	// dcbt r31,r11
	// lvrx128 v62,r4,r11
	temp.u32 = ctx.r4.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// li r31,64
	r31.s64 = 64;
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvlx128 v61,r4,r11
	temp.u32 = ctx.r4.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v62,r5,r11
	temp.u32 = ctx.r5.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// vor128 v62,v61,v62
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvlx128 v60,r5,r11
	temp.u32 = ctx.r5.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v61,r6,r11
	temp.u32 = ctx.r6.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v61,v60,v61
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// lvlx128 v59,r6,r11
	temp.u32 = ctx.r6.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v60,r31,r11
	temp.u32 = r31.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// vor128 v60,v59,v60
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// bne 0x824176bc
	if (!cr0.eq) goto loc_824176BC;
loc_8241771C:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82417744
	if (cr6.eq) goto loc_82417744;
loc_82417724:
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lvrx128 v62,r4,r11
	temp.u32 = ctx.r4.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x82417724
	if (!cr0.eq) goto loc_82417724;
loc_82417744:
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// or r11,r11,r7
	r11.u64 = r11.u64 | ctx.r7.u64;
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82417758"))) PPC_WEAK_FUNC(sub_82417758);
PPC_FUNC_IMPL(__imp__sub_82417758) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r10,r4,376
	ctx.r10.s64 = ctx.r4.s64 + 376;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// dcbt r0,r11
	// li r8,128
	ctx.r8.s64 = 128;
	// dcbt r8,r11
	// li r4,16
	ctx.r4.s64 = 16;
	// cmplwi cr6,r6,3
	cr6.compare<uint32_t>(ctx.r6.u32, 3, xer);
	// ble cr6,0x824177fc
	if (!cr6.gt) goto loc_824177FC;
	// addi r8,r6,-4
	ctx.r8.s64 = ctx.r6.s64 + -4;
	// li r5,32
	ctx.r5.s64 = 32;
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_8241779C:
	// li r31,256
	r31.s64 = 256;
	// dcbt r31,r11
	// lvrx128 v62,r4,r11
	temp.u32 = ctx.r4.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// li r31,64
	r31.s64 = 64;
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvlx128 v61,r4,r11
	temp.u32 = ctx.r4.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v62,r5,r11
	temp.u32 = ctx.r5.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// vor128 v62,v61,v62
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvlx128 v60,r5,r11
	temp.u32 = ctx.r5.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v61,r6,r11
	temp.u32 = ctx.r6.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v61,v60,v61
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// lvlx128 v59,r6,r11
	temp.u32 = ctx.r6.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v60,r31,r11
	temp.u32 = r31.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// vor128 v60,v59,v60
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// bne 0x8241779c
	if (!cr0.eq) goto loc_8241779C;
loc_824177FC:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82417824
	if (cr6.eq) goto loc_82417824;
loc_82417804:
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lvrx128 v62,r4,r11
	temp.u32 = ctx.r4.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x82417804
	if (!cr0.eq) goto loc_82417804;
loc_82417824:
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// or r11,r7,r11
	r11.u64 = ctx.r7.u64 | r11.u64;
	// std r11,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, r11.u64);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82417838"))) PPC_WEAK_FUNC(sub_82417838);
PPC_FUNC_IMPL(__imp__sub_82417838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
loc_82417838:
	// rlwinm r11,r4,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x7FFFFFF;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// clrlwi r9,r4,27
	ctx.r9.u64 = ctx.r4.u32 & 0x1F;
	// addi r11,r11,2528
	r11.s64 = r11.s64 + 2528;
	// li r8,1
	ctx.r8.s64 = 1;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r11,r3
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// andc r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 & ~ctx.r8.u64;
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// stwx r10,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r10.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// bne 0x82417838
	if (!cr0.eq) goto loc_82417838;
	// li r12,1
	r12.s64 = 1;
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82417894"))) PPC_WEAK_FUNC(sub_82417894);
PPC_FUNC_IMPL(__imp__sub_82417894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82417898"))) PPC_WEAK_FUNC(sub_82417898);
PPC_FUNC_IMPL(__imp__sub_82417898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
loc_82417898:
	// rlwinm r11,r4,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x7FFFFFF;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// clrlwi r9,r4,27
	ctx.r9.u64 = ctx.r4.u32 & 0x1F;
	// addi r11,r11,2532
	r11.s64 = r11.s64 + 2532;
	// li r8,1
	ctx.r8.s64 = 1;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r11,r3
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// andc r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 & ~ctx.r8.u64;
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// stwx r10,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r10.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// bne 0x82417898
	if (!cr0.eq) goto loc_82417898;
	// li r12,1
	r12.s64 = 1;
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824178F4"))) PPC_WEAK_FUNC(sub_824178F4);
PPC_FUNC_IMPL(__imp__sub_824178F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824178F8"))) PPC_WEAK_FUNC(sub_824178F8);
PPC_FUNC_IMPL(__imp__sub_824178F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// addi r11,r4,2536
	r11.s64 = ctx.r4.s64 + 2536;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
loc_82417904:
	// lbz r10,11(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 11);
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lbz r9,7(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 7);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r8,3(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 3);
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82417904
	if (!cr0.eq) goto loc_82417904;
	// li r12,1
	r12.s64 = 1;
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241794C"))) PPC_WEAK_FUNC(sub_8241794C);
PPC_FUNC_IMPL(__imp__sub_8241794C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82417950"))) PPC_WEAK_FUNC(sub_82417950);
PPC_FUNC_IMPL(__imp__sub_82417950) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// addi r11,r4,2552
	r11.s64 = ctx.r4.s64 + 2552;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
loc_8241795C:
	// lbz r10,11(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 11);
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lbz r9,7(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 7);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r8,3(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 3);
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8241795c
	if (!cr0.eq) goto loc_8241795C;
	// li r12,1
	r12.s64 = 1;
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824179A4"))) PPC_WEAK_FUNC(sub_824179A4);
PPC_FUNC_IMPL(__imp__sub_824179A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824179A8"))) PPC_WEAK_FUNC(sub_824179A8);
PPC_FUNC_IMPL(__imp__sub_824179A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,872(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 872);
	// rlwinm r3,r11,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824179B4"))) PPC_WEAK_FUNC(sub_824179B4);
PPC_FUNC_IMPL(__imp__sub_824179B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824179B8"))) PPC_WEAK_FUNC(sub_824179B8);
PPC_FUNC_IMPL(__imp__sub_824179B8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824179C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r31,12692(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 12692);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82417a3c
	if (cr6.eq) goto loc_82417A3C;
	// lwz r11,10908(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824179ec
	if (cr6.eq) goto loc_824179EC;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// b 0x82417a3c
	goto loc_82417A3C;
loc_824179EC:
	// lwz r11,10912(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10912);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82417a3c
	if (cr0.eq) goto loc_82417A3C;
	// lwz r11,13528(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 13528);
	// lwz r3,13524(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 13524);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x82417a14
	if (cr6.lt) goto loc_82417A14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8241a630
	ctx.lr = 0x82417A14;
	sub_8241A630(ctx, base);
loc_82417A14:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// rlwimi r11,r31,30,2,31
	r11.u64 = (__builtin_rotateleft32(r31.u32, 30) & 0x3FFFFFFF) | (r11.u64 & 0xFFFFFFFFC0000000);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// rlwinm r11,r11,0,2,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// stw r9,13524(r30)
	PPC_STORE_U32(r30.u32 + 13524, ctx.r9.u32);
loc_82417A3C:
	// stw r29,12692(r30)
	PPC_STORE_U32(r30.u32 + 12692, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// ld r11,16(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 16);
	// oris r11,r11,16
	r11.u64 = r11.u64 | 1048576;
	// std r11,16(r30)
	PPC_STORE_U64(r30.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r30)
	PPC_STORE_U64(r30.u32 + 16, r11.u64);
	// beq cr6,0x82417b6c
	if (cr6.eq) goto loc_82417B6C;
	// lwz r10,60(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// addi r11,r29,40
	r11.s64 = r29.s64 + 40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82417b6c
	if (cr6.eq) goto loc_82417B6C;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// andc r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r9.u64;
	// std r10,8(r30)
	PPC_STORE_U64(r30.u32 + 8, ctx.r10.u64);
	// ld r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82417aa0
	if (cr6.eq) goto loc_82417AA0;
	// li r12,1
	r12.s64 = 1;
	// ld r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 32);
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// std r10,32(r30)
	PPC_STORE_U64(r30.u32 + 32, ctx.r10.u64);
loc_82417AA0:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r31,r11,20
	r31.s64 = r11.s64 + 20;
	// addi r28,r30,1152
	r28.s64 = r30.s64 + 1152;
	// add r29,r10,r31
	r29.u64 = ctx.r10.u64 + r31.u64;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x82417b6c
	if (!cr6.lt) goto loc_82417B6C;
loc_82417AB8:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82417ad4
	if (cr0.eq) goto loc_82417AD4;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// blt cr6,0x82417ab8
	if (cr6.lt) goto loc_82417AB8;
loc_82417AD4:
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x82417b6c
	if (!cr6.lt) goto loc_82417B6C;
loc_82417ADC:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82417b64
	if (cr0.eq) goto loc_82417B64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x823da950
	ctx.lr = 0x82417B08;
	sub_823DA950(ctx, base);
	// add r31,r30,r31
	r31.u64 = r30.u64 + r31.u64;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// blt cr6,0x82417adc
	if (cr6.lt) goto loc_82417ADC;
	// b 0x82417b64
	goto loc_82417B64;
loc_82417B18:
	// lhz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x82417b6c
	if (cr0.eq) goto loc_82417B6C;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
loc_82417B34:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addis r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 65536;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// and r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ctx.r8.u64;
	// clrlwi. r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82417b34
	if (!cr0.eq) goto loc_82417B34;
loc_82417B64:
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// blt cr6,0x82417b18
	if (cr6.lt) goto loc_82417B18;
loc_82417B6C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82417B74"))) PPC_WEAK_FUNC(sub_82417B74);
PPC_FUNC_IMPL(__imp__sub_82417B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82417B78"))) PPC_WEAK_FUNC(sub_82417B78);
PPC_FUNC_IMPL(__imp__sub_82417B78) {
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
	ctx.lr = 0x82417B80;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r5,872
	ctx.r5.s64 = 872;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823d9890
	ctx.lr = 0x82417B98;
	sub_823D9890(ctx, base);
	// li r11,6
	r11.s64 = 6;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// lwz r11,872(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 872);
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// addic. r11,r11,1
	xer.ca = r11.u32 > 4294967294;
	r11.s64 = r11.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82417c68
	if (cr0.eq) goto loc_82417C68;
	// addi r25,r31,40
	r25.s64 = r31.s64 + 40;
	// addi r27,r31,896
	r27.s64 = r31.s64 + 896;
	// mr r24,r11
	r24.u64 = r11.u64;
loc_82417BDC:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r11,872
	ctx.r10.s64 = r11.s64 + 872;
	// lwz r7,896(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 896);
	// lwz r8,872(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 872);
	// addi r7,r7,9
	ctx.r7.s64 = ctx.r7.s64 + 9;
	// lwz r11,900(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 900);
	// add r26,r9,r8
	r26.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// beq cr6,0x82417c50
	if (cr6.eq) goto loc_82417C50;
	// addi r30,r25,28
	r30.s64 = r25.s64 + 28;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82417C1C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// clrlwi r11,r11,20
	r11.u64 = r11.u32 & 0xFFF;
	// mulli r11,r11,12
	r11.s64 = r11.s64 * 12;
	// add r4,r11,r26
	ctx.r4.u64 = r11.u64 + r26.u64;
	// cmplw cr6,r30,r4
	cr6.compare<uint32_t>(r30.u32, ctx.r4.u32, xer);
	// beq cr6,0x82417c40
	if (cr6.eq) goto loc_82417C40;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82417C40;
	sub_823DA950(ctx, base);
loc_82417C40:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// bne 0x82417c1c
	if (!cr0.eq) goto loc_82417C1C;
loc_82417C50:
	// li r11,-1
	r11.s64 = -1;
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
	// addi r27,r27,8
	r27.s64 = r27.s64 + 8;
	// addi r25,r25,416
	r25.s64 = r25.s64 + 416;
	// bne 0x82417bdc
	if (!cr0.eq) goto loc_82417BDC;
loc_82417C68:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82417C70"))) PPC_WEAK_FUNC(sub_82417C70);
PPC_FUNC_IMPL(__imp__sub_82417C70) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82417C78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82417c98
	if (cr6.eq) goto loc_82417C98;
	// ld r11,16(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 16);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,16(r30)
	PPC_STORE_U64(r30.u32 + 16, r11.u64);
loc_82417C98:
	// lwz r31,12696(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 12696);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82417d08
	if (cr6.eq) goto loc_82417D08;
	// lwz r11,10908(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82417cb8
	if (cr6.eq) goto loc_82417CB8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// b 0x82417d08
	goto loc_82417D08;
loc_82417CB8:
	// lwz r11,10912(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10912);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82417d08
	if (cr0.eq) goto loc_82417D08;
	// lwz r11,13528(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 13528);
	// lwz r3,13524(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 13524);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x82417ce0
	if (cr6.lt) goto loc_82417CE0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8241a630
	ctx.lr = 0x82417CE0;
	sub_8241A630(ctx, base);
loc_82417CE0:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// rlwimi r11,r31,30,2,31
	r11.u64 = (__builtin_rotateleft32(r31.u32, 30) & 0x3FFFFFFF) | (r11.u64 & 0xFFFFFFFFC0000000);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// rlwinm r11,r11,0,2,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// stw r9,13524(r30)
	PPC_STORE_U32(r30.u32 + 13524, ctx.r9.u32);
loc_82417D08:
	// lbz r11,10942(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10942);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r29,12696(r30)
	PPC_STORE_U32(r30.u32 + 12696, r29.u32);
	// clrlwi r11,r11,25
	r11.u64 = r11.u32 & 0x7F;
	// stb r11,10942(r30)
	PPC_STORE_U8(r30.u32 + 10942, r11.u8);
	// beq cr6,0x82417e34
	if (cr6.eq) goto loc_82417E34;
	// addic. r11,r29,872
	xer.ca = r29.u32 > 4294966423;
	r11.s64 = r29.s64 + 872;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82417e34
	if (cr0.eq) goto loc_82417E34;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82417e34
	if (cr6.eq) goto loc_82417E34;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ld r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// andc r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r9.u64;
	// std r10,0(r30)
	PPC_STORE_U64(r30.u32 + 0, ctx.r10.u64);
	// ld r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82417d68
	if (cr6.eq) goto loc_82417D68;
	// li r12,1
	r12.s64 = 1;
	// ld r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 32);
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// std r10,32(r30)
	PPC_STORE_U64(r30.u32 + 32, ctx.r10.u64);
loc_82417D68:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r31,r11,20
	r31.s64 = r11.s64 + 20;
	// addi r28,r30,1152
	r28.s64 = r30.s64 + 1152;
	// add r29,r10,r31
	r29.u64 = ctx.r10.u64 + r31.u64;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x82417e34
	if (!cr6.lt) goto loc_82417E34;
loc_82417D80:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82417d9c
	if (cr0.eq) goto loc_82417D9C;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// blt cr6,0x82417d80
	if (cr6.lt) goto loc_82417D80;
loc_82417D9C:
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x82417e34
	if (!cr6.lt) goto loc_82417E34;
loc_82417DA4:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82417e2c
	if (cr0.eq) goto loc_82417E2C;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x823da950
	ctx.lr = 0x82417DD0;
	sub_823DA950(ctx, base);
	// add r31,r30,r31
	r31.u64 = r30.u64 + r31.u64;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// blt cr6,0x82417da4
	if (cr6.lt) goto loc_82417DA4;
	// b 0x82417e2c
	goto loc_82417E2C;
loc_82417DE0:
	// lhz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x82417e34
	if (cr0.eq) goto loc_82417E34;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
loc_82417DFC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addis r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 65536;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// and r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ctx.r8.u64;
	// clrlwi. r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82417dfc
	if (!cr0.eq) goto loc_82417DFC;
loc_82417E2C:
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// blt cr6,0x82417de0
	if (cr6.lt) goto loc_82417DE0;
loc_82417E34:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82417E3C"))) PPC_WEAK_FUNC(sub_82417E3C);
PPC_FUNC_IMPL(__imp__sub_82417E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82417E40"))) PPC_WEAK_FUNC(sub_82417E40);
PPC_FUNC_IMPL(__imp__sub_82417E40) {
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
	// lwz r31,12696(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12696);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82417e6c
	if (cr6.eq) goto loc_82417E6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82422160
	ctx.lr = 0x82417E6C;
	sub_82422160(ctx, base);
loc_82417E6C:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
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

__attribute__((alias("__imp__sub_82417E88"))) PPC_WEAK_FUNC(sub_82417E88);
PPC_FUNC_IMPL(__imp__sub_82417E88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stw r4,11820(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11820, ctx.r4.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82417E9C"))) PPC_WEAK_FUNC(sub_82417E9C);
PPC_FUNC_IMPL(__imp__sub_82417E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82417EA0"))) PPC_WEAK_FUNC(sub_82417EA0);
PPC_FUNC_IMPL(__imp__sub_82417EA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82417EA8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// std r27,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r27.u64);
	// mr r30,r27
	r30.u64 = r27.u64;
	// std r27,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r27.u64);
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// mr r28,r27
	r28.u64 = r27.u64;
	// b 0x82417ef8
	goto loc_82417EF8;
loc_82417ED4:
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bgt cr6,0x82417ee0
	if (cr6.gt) goto loc_82417EE0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82417EE0:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// li r8,255
	ctx.r8.s64 = 255;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stbx r8,r11,r9
	PPC_STORE_U8(r11.u32 + ctx.r9.u32, ctx.r8.u8);
	// lhz r11,0(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
loc_82417EF8:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bne cr6,0x82417ed4
	if (!cr6.eq) goto loc_82417ED4;
	// mulli r11,r30,12
	r11.s64 = r30.s64 * 12;
	// addi r5,r11,56
	ctx.r5.s64 = r11.s64 + 56;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x82417F14;
	sub_823D9890(ctx, base);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// ori r9,r9,5
	ctx.r9.u64 = ctx.r9.u64 | 5;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// lis r7,-1
	ctx.r7.s64 = -65536;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// stw r27,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r27.u32);
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
	// std r10,40(r31)
	PPC_STORE_U64(r31.u32 + 40, ctx.r10.u64);
	// beq cr6,0x82417f84
	if (cr6.eq) goto loc_82417F84;
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r10,r31,52
	ctx.r10.s64 = r31.s64 + 52;
loc_82417F5C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bne 0x82417f5c
	if (!cr0.eq) goto loc_82417F5C;
loc_82417F84:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82417F8C"))) PPC_WEAK_FUNC(sub_82417F8C);
PPC_FUNC_IMPL(__imp__sub_82417F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82417F90"))) PPC_WEAK_FUNC(sub_82417F90);
PPC_FUNC_IMPL(__imp__sub_82417F90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r11,0
	r11.s64 = 0;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// b 0x82417fc4
	goto loc_82417FC4;
loc_82417FB8:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
loc_82417FC4:
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// bne cr6,0x82417fb8
	if (!cr6.eq) goto loc_82417FB8;
	// mulli r11,r11,12
	r11.s64 = r11.s64 * 12;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// addi r3,r11,56
	ctx.r3.s64 = r11.s64 + 56;
	// bl 0x82130b50
	ctx.lr = 0x82417FDC;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x82417fec
	if (!cr0.eq) goto loc_82417FEC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82417ffc
	goto loc_82417FFC;
loc_82417FEC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82417ea0
	ctx.lr = 0x82417FF8;
	sub_82417EA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82417FFC:
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

__attribute__((alias("__imp__sub_82418014"))) PPC_WEAK_FUNC(sub_82418014);
PPC_FUNC_IMPL(__imp__sub_82418014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82418018"))) PPC_WEAK_FUNC(sub_82418018);
PPC_FUNC_IMPL(__imp__sub_82418018) {
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
	ctx.lr = 0x82418020;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82418044
	if (!cr6.eq) goto loc_82418044;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82418044
	if (!cr6.eq) goto loc_82418044;
	// li r30,64
	r30.s64 = 64;
	// li r6,64
	ctx.r6.s64 = 64;
loc_82418044:
	// clrlwi. r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82418054
	if (cr0.eq) goto loc_82418054;
	// li r11,0
	r11.s64 = 0;
	// b 0x82418064
	goto loc_82418064;
loc_82418054:
	// lwz r11,10920(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10920);
	// rlwimi r6,r30,8,17,23
	ctx.r6.u64 = (__builtin_rotateleft32(r30.u32, 8) & 0x7F00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF80FF);
	// rlwimi r11,r6,4,21,27
	r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 4) & 0x7F0) | (r11.u64 & 0xFFFFFFFFFFFFF80F);
	// rlwimi r11,r6,4,13,19
	r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 4) & 0x7F000) | (r11.u64 & 0xFFFFFFFFFFF80FFF);
loc_82418064:
	// stw r11,10920(r31)
	PPC_STORE_U32(r31.u32 + 10920, r11.u32);
	// lwz r10,12716(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12716);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// and r29,r10,r4
	r29.u64 = ctx.r10.u64 & ctx.r4.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x8241808c
	if (!cr6.gt) goto loc_8241808C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82418088;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241808C:
	// oris r9,r29,49153
	ctx.r9.u64 = r29.u64 | 3221291008;
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r9,r9,16128
	ctx.r9.u64 = ctx.r9.u64 | 16128;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// addi r8,r30,1724
	ctx.r8.s64 = r30.s64 + 1724;
	// lwz r7,13788(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 13788);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r8,r8,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// lwz r7,13784(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 13784);
	// clrlwi r7,r7,8
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFFFF;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// lwz r10,13796(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13796);
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// clrlwi r10,r10,8
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFFFF;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// lwz r10,14820(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 14820);
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lwz r10,14816(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 14816);
	// clrlwi r10,r10,8
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFFFF;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x824173c0
	ctx.lr = 0x824180F8;
	sub_824173C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82418100"))) PPC_WEAK_FUNC(sub_82418100);
PPC_FUNC_IMPL(__imp__sub_82418100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82418108;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r10,-9712(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -9712);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8241813c
	if (cr6.eq) goto loc_8241813C;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8241812C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8241813c
	if (!cr0.eq) goto loc_8241813C;
loc_82418134:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82418208
	goto loc_82418208;
loc_8241813C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// lwz r28,8(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r27,r11,r29
	r27.u64 = r11.u64 + r29.u64;
	// subfic r10,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r10.s64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r10,r10,832
	ctx.r10.u64 = ctx.r10.u64 & 832;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82130b50
	ctx.lr = 0x8241816C;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82418134
	if (cr0.eq) goto loc_82418134;
	// li r30,0
	r30.s64 = 0;
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// std r30,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r30.u64);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// std r30,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r30.u64);
	// std r30,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r30.u64);
	// std r30,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r30.u64);
	// std r30,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r30.u64);
	// bl 0x8244d5c0
	ctx.lr = 0x8241819C;
	sub_8244D5C0(ctx, base);
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130b50
	ctx.lr = 0x824181A8;
	sub_82130B50(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x824181c0
	if (!cr0.eq) goto loc_824181C0;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x824181BC;
	sub_821310F8(ctx, base);
	// b 0x82418134
	goto loc_82418134;
loc_824181C0:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824181D0;
	sub_823DA950(ctx, base);
	// std r30,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r30.u64);
	// lis r11,16
	r11.s64 = 1048576;
	// std r30,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r30.u64);
	// std r30,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r30.u64);
	// li r10,1
	ctx.r10.s64 = 1;
	// std r30,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r30.u64);
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// ori r11,r11,7
	r11.u64 = r11.u64 | 7;
	// std r30,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r30.u64);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82418208:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82418210"))) PPC_WEAK_FUNC(sub_82418210);
PPC_FUNC_IMPL(__imp__sub_82418210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82418218;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,-9708(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -9708);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8241824c
	if (cr6.eq) goto loc_8241824C;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8241823C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8241824c
	if (!cr0.eq) goto loc_8241824C;
loc_82418244:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824182f8
	goto loc_824182F8;
loc_8241824C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r28,r11,r31
	r28.u64 = r11.u64 + r31.u64;
	// subfic r10,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r10.s64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r10,r10,832
	ctx.r10.u64 = ctx.r10.u64 & 832;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82130b50
	ctx.lr = 0x8241827C;
	sub_82130B50(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x82418244
	if (cr0.eq) goto loc_82418244;
	// li r5,872
	ctx.r5.s64 = 872;
	// lwz r27,4(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x82418298;
	sub_823D9890(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,872
	ctx.r3.s64 = r30.s64 + 872;
	// bl 0x8244d5c0
	ctx.lr = 0x824182A8;
	sub_8244D5C0(ctx, base);
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130b50
	ctx.lr = 0x824182B4;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x824182cc
	if (!cr0.eq) goto loc_824182CC;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821310f8
	ctx.lr = 0x824182C8;
	sub_821310F8(ctx, base);
	// b 0x82418244
	goto loc_82418244;
loc_824182CC:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x824182DC;
	sub_823DA950(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82417b78
	ctx.lr = 0x824182E8;
	sub_82417B78(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// oris r11,r11,16
	r11.u64 = r11.u64 | 1048576;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_824182F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82418300"))) PPC_WEAK_FUNC(sub_82418300);
PPC_FUNC_IMPL(__imp__sub_82418300) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r4,r31,12192
	ctx.r4.s64 = r31.s64 + 12192;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r11,12432(r31)
	PPC_STORE_U32(r31.u32 + 12432, r11.u32);
	// bl 0x82416cb0
	ctx.lr = 0x82418328;
	sub_82416CB0(ctx, base);
	// stw r4,11820(r31)
	PPC_STORE_U32(r31.u32 + 11820, ctx.r4.u32);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
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

__attribute__((alias("__imp__sub_8241834C"))) PPC_WEAK_FUNC(sub_8241834C);
PPC_FUNC_IMPL(__imp__sub_8241834C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82418350"))) PPC_WEAK_FUNC(sub_82418350);
PPC_FUNC_IMPL(__imp__sub_82418350) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82418358;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// lwz r11,10688(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10688);
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241839c
	if (!cr0.eq) goto loc_8241839C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f31.f64 = double(temp.f32);
	// b 0x824183a4
	goto loc_824183A4;
loc_8241839C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_824183A4:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r29,48(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// ble cr6,0x824183c0
	if (!cr6.gt) goto loc_824183C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824183BC;
	sub_82412710(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_824183C0:
	// mulli r27,r28,21
	r27.s64 = r28.s64 * 21;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411840
	ctx.lr = 0x824183D4;
	sub_82411840(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x824183e4
	if (!cr0.eq) goto loc_824183E4;
	// stw r29,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r29.u32);
	// b 0x82418630
	goto loc_82418630;
loc_824183E4:
	// rlwinm r11,r3,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 12) & 0xFFF;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// clrlwi r10,r3,3
	ctx.r10.u64 = ctx.r3.u32 & 0x1FFFFFFF;
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// lfs f12,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x824184e4
	if (cr6.eq) goto loc_824184E4;
	// addi r11,r25,8
	r11.s64 = r25.s64 + 8;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_82418418:
	// lwa r8,-4(r11)
	ctx.r8.s64 = int32_t(PPC_LOAD_U32(r11.u32 + -4));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwa r5,-8(r11)
	ctx.r5.s64 = int32_t(PPC_LOAD_U32(r11.u32 + -8));
	// lwa r7,0(r11)
	ctx.r7.s64 = int32_t(PPC_LOAD_U32(r11.u32 + 0));
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// std r7,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwa r6,4(r11)
	ctx.r6.s64 = int32_t(PPC_LOAD_U32(r11.u32 + 4));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// lfd f9,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfd f7,104(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f8,96(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// frsp f7,f7
	ctx.f7.f64 = double(float(ctx.f7.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// fsubs f7,f7,f31
	ctx.f7.f64 = double(float(ctx.f7.f64 - f31.f64));
	// stfs f7,0(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fsubs f10,f10,f31
	ctx.f10.f64 = double(float(ctx.f10.f64 - f31.f64));
	// stfs f10,4(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f30,8(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fsubs f9,f9,f31
	ctx.f9.f64 = double(float(ctx.f9.f64 - f31.f64));
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fsubs f8,f8,f31
	ctx.f8.f64 = double(float(ctx.f8.f64 - f31.f64));
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f12,20(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f11,24(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f9,28(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f10,32(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f30,36(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f12,48(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f11,52(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f9,56(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f8,60(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f30,64(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f13,72(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f12,76(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f11,80(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// addi r3,r3,84
	ctx.r3.s64 = ctx.r3.s64 + 84;
	// bne 0x82418418
	if (!cr0.eq) goto loc_82418418;
loc_824184E4:
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r9,3
	ctx.r10.u64 = ctx.r9.u64 | 3;
	// ori r11,r11,18432
	r11.u64 = r11.u64 | 18432;
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stwu r11,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, r11.u32);
	r29.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// ori r9,r9,2
	ctx.r9.u64 = ctx.r9.u64 | 2;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwimi r9,r27,2,6,29
	ctx.r9.u64 = (__builtin_rotateleft32(r27.u32, 2) & 0x3FFFFFC) | (ctx.r9.u64 & 0xFFFFFFFFFC000003);
	// li r7,0
	ctx.r7.s64 = 0;
	// stwu r10,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r29.u32 = ea;
	// li r6,0
	ctx.r6.s64 = 0;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r10,20480
	ctx.r4.u64 = ctx.r10.u64 | 20480;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwu r9,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r29.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r9,8961
	ctx.r9.s64 = 8961;
	// ori r27,r10,8192
	r27.u64 = ctx.r10.u64 | 8192;
	// rlwinm. r10,r26,16,30,31
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 16) & 0x3;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwu r11,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, r11.u32);
	r29.u32 = ea;
	// stwu r8,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r29.u32 = ea;
	// stwu r7,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r29.u32 = ea;
	// stwu r6,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r29.u32 = ea;
	// stwu r4,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r29.u32 = ea;
	// stwu r5,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	r29.u32 = ea;
	// stwu r3,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	r29.u32 = ea;
	// stwu r30,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, r30.u32);
	r29.u32 = ea;
	// stwu r27,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, r27.u32);
	r29.u32 = ea;
	// stwu r26,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, r26.u32);
	r29.u32 = ea;
	// stwu r24,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, r24.u32);
	r29.u32 = ea;
	// mr r11,r29
	r11.u64 = r29.u64;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// bne 0x8241857c
	if (!cr0.eq) goto loc_8241857C;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82418594
	goto loc_82418594;
loc_8241857C:
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// lis r10,0
	ctx.r10.s64 = 0;
	// bne cr6,0x82418590
	if (!cr6.eq) goto loc_82418590;
	// ori r10,r10,32769
	ctx.r10.u64 = ctx.r10.u64 | 32769;
	// b 0x82418594
	goto loc_82418594;
loc_82418590:
	// ori r10,r10,49155
	ctx.r10.u64 = ctx.r10.u64 | 49155;
loc_82418594:
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r10,8704
	ctx.r10.s64 = 8704;
	// li r9,8712
	ctx.r9.s64 = 8712;
	// lwz r8,292(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// lis r7,-16384
	ctx.r7.s64 = -1073741824;
	// lis r6,3
	ctx.r6.s64 = 196608;
	// ori r7,r7,13825
	ctx.r7.u64 = ctx.r7.u64 | 13825;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r5,17
	ctx.r5.s64 = 17;
	// mullw r10,r28,r6
	ctx.r10.s64 = int64_t(r28.s32) * int64_t(ctx.r6.s32);
	// stwu r23,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r23.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// rlwimi r10,r5,3,16,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 3) & 0xFFFF) | (ctx.r10.u64 & 0xFFFFFFFFFFFF0000);
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,57,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 57) & 0xFFFFFFFFFFFFFFFF;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// oris r11,r11,32768
	r11.u64 = r11.u64 | 2147483648;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,36,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 36) & 0xFFFFFFFFFFFFFFFF;
	// ld r11,32(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82418630:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82418640"))) PPC_WEAK_FUNC(sub_82418640);
PPC_FUNC_IMPL(__imp__sub_82418640) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82418648;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r21,r8
	r21.u64 = ctx.r8.u64;
	// rlwinm. r11,r23,16,30,31
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 16) & 0x3;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r27,1
	r27.s64 = 1;
	// bne 0x82418680
	if (!cr0.eq) goto loc_82418680;
	// li r26,1
	r26.s64 = 1;
	// b 0x82418690
	goto loc_82418690;
loc_82418680:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r26,0
	r26.s64 = 0;
	// beq cr6,0x82418690
	if (cr6.eq) goto loc_82418690;
	// li r27,0
	r27.s64 = 0;
loc_82418690:
	// li r11,40
	r11.s64 = 40;
	// li r10,8
	ctx.r10.s64 = 8;
	// slw r11,r11,r27
	r11.u64 = r27.u8 & 0x20 ? 0 : (r11.u32 << (r27.u8 & 0x3F));
	// slw r10,r10,r26
	ctx.r10.u64 = r26.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r26.u8 & 0x3F));
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// add r8,r10,r28
	ctx.r8.u64 = ctx.r10.u64 + r28.u64;
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// addi r30,r8,-1
	r30.s64 = ctx.r8.s64 + -1;
	// rotlwi r9,r4,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// rotlwi r6,r29,1
	ctx.r6.u64 = __builtin_rotateleft32(r29.u32, 1);
	// divw r4,r4,r11
	ctx.r4.s32 = ctx.r4.s32 / r11.s32;
	// rotlwi r8,r30,1
	ctx.r8.u64 = __builtin_rotateleft32(r30.u32, 1);
	// rotlwi r5,r7,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r25,r29,r11
	r25.s32 = r29.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// mullw r31,r4,r11
	r31.s64 = int64_t(ctx.r4.s32) * int64_t(r11.s32);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// divw r4,r30,r10
	ctx.r4.s32 = r30.s32 / ctx.r10.s32;
	// mullw r30,r25,r11
	r30.s64 = int64_t(r25.s32) * int64_t(r11.s32);
	// andc r9,r11,r9
	ctx.r9.u64 = r11.u64 & ~ctx.r9.u64;
	// andc r6,r11,r6
	ctx.r6.u64 = r11.u64 & ~ctx.r6.u64;
	// twllei r11,0
	// twllei r11,0
	// andc r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 & ~ctx.r8.u64;
	// divw r11,r7,r10
	r11.s32 = ctx.r7.s32 / ctx.r10.s32;
	// andc r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 & ~ctx.r5.u64;
	// twllei r10,0
	// twllei r10,0
	// twlgei r9,-1
	// twlgei r8,-1
	// mullw r25,r4,r10
	r25.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// twlgei r6,-1
	// twlgei r5,-1
	// mullw r24,r11,r10
	r24.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x82418894
	if (!cr6.lt) goto loc_82418894;
	// cmpw cr6,r25,r24
	cr6.compare<int32_t>(r25.s32, r24.s32, xer);
	// bge cr6,0x82418894
	if (!cr6.lt) goto loc_82418894;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r11,-13972(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -13972);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82418894
	if (cr6.eq) goto loc_82418894;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// ble cr6,0x82418760
	if (!cr6.gt) goto loc_82418760;
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
loc_82418760:
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// bge cr6,0x82418790
	if (!cr6.lt) goto loc_82418790;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r6,r1,124
	ctx.r6.s64 = ctx.r1.s64 + 124;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stwx r30,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r30.u32);
	// stwx r28,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, r28.u32);
	// stwx r29,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, r29.u32);
	// stwx r7,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, ctx.r7.u32);
loc_82418790:
	// cmpw cr6,r25,r28
	cr6.compare<int32_t>(r25.s32, r28.s32, xer);
	// ble cr6,0x824187c0
	if (!cr6.gt) goto loc_824187C0;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r6,r1,124
	ctx.r6.s64 = ctx.r1.s64 + 124;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stwx r31,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r31.u32);
	// stwx r28,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, r28.u32);
	// stwx r30,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, r30.u32);
	// stwx r25,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, r25.u32);
loc_824187C0:
	// cmpw cr6,r24,r7
	cr6.compare<int32_t>(r24.s32, ctx.r7.s32, xer);
	// bge cr6,0x824187f0
	if (!cr6.lt) goto loc_824187F0;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r6,r1,124
	ctx.r6.s64 = ctx.r1.s64 + 124;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stwx r31,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r31.u32);
	// stwx r24,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, r24.u32);
	// stwx r30,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, r30.u32);
	// stwx r7,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, ctx.r7.u32);
loc_824187F0:
	// lwz r29,372(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82418824
	if (cr6.eq) goto loc_82418824;
	// lwz r11,396(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// lwz r10,380(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82418350
	ctx.lr = 0x82418824;
	sub_82418350(ctx, base);
loc_82418824:
	// li r11,1
	r11.s64 = 1;
	// lwz r9,404(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	// sraw r8,r31,r27
	temp.u32 = r27.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r31.s32 < 0) & (((r31.s32 >> temp.u32) << temp.u32) != r31.s32);
	ctx.r8.s64 = r31.s32 >> temp.u32;
	// lwz r10,388(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// rlwimi r23,r11,17,14,15
	r23.u64 = (__builtin_rotateleft32(r11.u32, 17) & 0x30000) | (r23.u64 & 0xFFFFFFFFFFFCFFFF);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// sraw r11,r25,r26
	temp.u32 = r26.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	r11.s64 = r25.s32 >> temp.u32;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// sraw r11,r30,r27
	temp.u32 = r27.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r30.s32 < 0) & (((r30.s32 >> temp.u32) << temp.u32) != r30.s32);
	r11.s64 = r30.s32 >> temp.u32;
	// sraw r9,r24,r26
	temp.u32 = r26.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r24.s32 < 0) & (((r24.s32 >> temp.u32) << temp.u32) != r24.s32);
	ctx.r9.s64 = r24.s32 >> temp.u32;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// clrlwi r11,r23,18
	r11.u64 = r23.u32 & 0x3FFF;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// srw r11,r11,r27
	r11.u64 = r27.u8 & 0x20 ? 0 : (r11.u32 >> (r27.u8 & 0x3F));
	// rlwimi r11,r23,0,0,17
	r11.u64 = (__builtin_rotateleft32(r23.u32, 0) & 0xFFFFC000) | (r11.u64 & 0xFFFFFFFF00003FFF);
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r8,14,18,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 14) & 0x3FFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// srw r11,r11,r27
	r11.u64 = r27.u8 & 0x20 ? 0 : (r11.u32 >> (r27.u8 & 0x3F));
	// rlwimi r8,r11,18,0,13
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 18) & 0xFFFC0000) | (ctx.r8.u64 & 0xFFFFFFFF0003FFFF);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82418350
	ctx.lr = 0x82418890;
	sub_82418350(ctx, base);
	// b 0x824188d0
	goto loc_824188D0;
loc_82418894:
	// lwz r11,396(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r10,380(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,372(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// bl 0x82418350
	ctx.lr = 0x824188D0;
	sub_82418350(ctx, base);
loc_824188D0:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824188DC"))) PPC_WEAK_FUNC(sub_824188DC);
PPC_FUNC_IMPL(__imp__sub_824188DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824188E0"))) PPC_WEAK_FUNC(sub_824188E0);
PPC_FUNC_IMPL(__imp__sub_824188E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f0{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824188E8;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// stw r25,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, r25.u32);
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// stw r26,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r26.u32);
	// li r27,5
	r27.s64 = 5;
	// lwz r15,10368(r31)
	r15.u64 = PPC_LOAD_U32(r31.u32 + 10368);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r24,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, r24.u32);
	// stw r23,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, r23.u32);
	// mr r16,r10
	r16.u64 = ctx.r10.u64;
	// li r21,0
	r21.s64 = 0;
	// mr r14,r27
	r14.u64 = r27.u64;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// beq cr6,0x8241897c
	if (cr6.eq) goto loc_8241897C;
	// addi r11,r5,3110
	r11.s64 = ctx.r5.s64 + 3110;
	// lis r10,10
	ctx.r10.s64 = 655360;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r14,4
	r14.s64 = 4;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r21,28(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r11,r21,0,12,15
	r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 0) & 0xF0000;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82418964
	if (!cr6.eq) goto loc_82418964;
	// li r11,1
	r11.s64 = 1;
	// rlwimi r21,r11,17,12,15
	r21.u64 = (__builtin_rotateleft32(r11.u32, 17) & 0xF0000) | (r21.u64 & 0xFFFFFFFFFFF0FFFF);
loc_82418964:
	// rlwinm r11,r21,0,12,15
	r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 0) & 0xF0000;
	// lis r10,12
	ctx.r10.s64 = 786432;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8241897c
	if (!cr6.eq) goto loc_8241897C;
	// li r11,3
	r11.s64 = 3;
	// rlwimi r21,r11,16,12,15
	r21.u64 = (__builtin_rotateleft32(r11.u32, 16) & 0xF0000) | (r21.u64 & 0xFFFFFFFFFFF0FFFF);
loc_8241897C:
	// lwz r11,10560(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// rlwinm. r10,r28,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// li r20,0
	r20.s64 = 0;
	// rlwinm r30,r11,0,0,27
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// beq 0x82418998
	if (cr0.eq) goto loc_82418998;
	// li r20,118
	r20.s64 = 118;
	// ori r30,r30,1
	r30.u64 = r30.u64 | 1;
loc_82418998:
	// rlwinm. r11,r28,0,26,26
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82418a0c
	if (cr0.eq) goto loc_82418A0C;
	// lwz r29,396(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// rlwinm. r11,r28,0,25,25
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ori r20,r20,34561
	r20.u64 = r20.u64 | 34561;
	// ori r30,r30,4
	r30.u64 = r30.u64 | 4;
	// beq 0x824189c0
	if (cr0.eq) goto loc_824189C0;
	// rlwimi r30,r29,8,16,23
	r30.u64 = (__builtin_rotateleft32(r29.u32, 8) & 0xFF00) | (r30.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwinm r30,r30,0,27,25
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// b 0x824189d0
	goto loc_824189D0;
loc_824189C0:
	// rlwinm. r11,r28,0,24,24
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824189d0
	if (cr0.eq) goto loc_824189D0;
	// rlwimi r30,r29,8,16,23
	r30.u64 = (__builtin_rotateleft32(r29.u32, 8) & 0xFF00) | (r30.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r30,r30,32
	r30.u64 = r30.u64 | 32;
loc_824189D0:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824189e8
	if (!cr6.gt) goto loc_824189E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824189E8;
	sub_82412710(ctx, base);
loc_824189E8:
	// li r11,8461
	r11.s64 = 8461;
	// li r10,255
	ctx.r10.s64 = 255;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// rlwimi r29,r10,16,0,23
	r29.u64 = (__builtin_rotateleft32(ctx.r10.u32, 16) & 0xFFFFFF00) | (r29.u64 & 0xFFFFFFFF000000FF);
	// stwu r29,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r11,r11,4096
	r11.u64 = r11.u64 | 268435456;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82418A0C:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824231b0
	ctx.lr = 0x82418A1C;
	sub_824231B0(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82418a34
	if (!cr6.gt) goto loc_82418A34;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82418A34;
	sub_82412710(ctx, base);
loc_82418A34:
	// lis r11,2
	r11.s64 = 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,8320
	r11.u64 = r11.u64 | 8320;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lis r11,8192
	r11.s64 = 536870912;
	// rlwinm. r28,r28,0,26,27
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x30;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// mr r17,r20
	r17.u64 = r20.u64;
	// mr r18,r14
	r18.u64 = r14.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stwu r11,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, r11.u32);
	r29.u32 = ea;
	// bne 0x82418b74
	if (!cr0.eq) goto loc_82418B74;
	// rlwinm r3,r21,16,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r3,5
	cr6.compare<uint32_t>(ctx.r3.u32, 5, xer);
	// beq cr6,0x82418b74
	if (cr6.eq) goto loc_82418B74;
	// cmplwi cr6,r3,7
	cr6.compare<uint32_t>(ctx.r3.u32, 7, xer);
	// beq cr6,0x82418b74
	if (cr6.eq) goto loc_82418B74;
	// cmplwi cr6,r3,15
	cr6.compare<uint32_t>(ctx.r3.u32, 15, xer);
	// beq cr6,0x82418b74
	if (cr6.eq) goto loc_82418B74;
	// rlwinm. r11,r15,16,30,31
	r11.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 16) & 0x3;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82418aa0
	if (!cr0.eq) goto loc_82418AA0;
	// li r11,80
	r11.s64 = 80;
	// li r10,16
	ctx.r10.s64 = 16;
	// b 0x82418ab4
	goto loc_82418AB4;
loc_82418AA0:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r11,80
	r11.s64 = 80;
	// beq cr6,0x82418ab4
	if (cr6.eq) goto loc_82418AB4;
	// li r11,40
	r11.s64 = 40;
loc_82418AB4:
	// subf r9,r25,r24
	ctx.r9.s64 = r24.s64 - r25.s64;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blt cr6,0x82418b74
	if (cr6.lt) goto loc_82418B74;
	// subf r11,r26,r23
	r11.s64 = r23.s64 - r26.s64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82418b74
	if (cr6.lt) goto loc_82418B74;
	// addi r6,r1,132
	ctx.r6.s64 = ctx.r1.s64 + 132;
	// lvx128 v1,r0,r16
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// rlwinm r4,r21,12,26,31
	ctx.r4.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 12) & 0x3F;
	// bl 0x824206a8
	ctx.lr = 0x82418AE0;
	sub_824206A8(ctx, base);
	// li r10,8707
	ctx.r10.s64 = 8707;
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stwu r10,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r29.u32 = ea;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// rlwinm r5,r11,24,8,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFFFFFF;
	// li r7,8194
	ctx.r7.s64 = 8194;
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// lfd f0,136(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stwu r8,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r29.u32 = ea;
	// lfd f0,-11560(r9)
	f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + -11560);
	// clrlwi r6,r21,20
	ctx.r6.u64 = r21.u32 & 0xFFF;
	// fsub f0,f12,f0
	f0.f64 = ctx.f12.f64 - f0.f64;
	// stwu r7,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r29.u32 = ea;
	// lfd f13,7808(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + 7808);
	// li r4,8461
	ctx.r4.s64 = 8461;
	// fmul f0,f0,f13
	f0.f64 = f0.f64 * ctx.f13.f64;
	// stwu r6,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r29.u32 = ea;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r12,1
	r12.s64 = 1;
	// frsp f31,f0
	f31.f64 = double(float(f0.f64));
	// oris r11,r11,255
	r11.u64 = r11.u64 | 16711680;
	// rldicr r12,r12,55,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 55) & 0xFFFFFFFFFFFFFFFF;
	// lis r17,0
	r17.s64 = 0;
	// stwu r4,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r29.u32 = ea;
	// mr r18,r27
	r18.u64 = r27.u64;
	// ori r17,r17,34679
	r17.u64 = r17.u64 | 34679;
	// stwu r11,4(r29)
	ea = 4 + r29.u32;
	PPC_STORE_U32(ea, r11.u32);
	r29.u32 = ea;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,4096
	r11.u64 = r11.u64 | 268435456;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82418B74:
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// stw r29,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r29.u32);
	// rlwinm. r11,r10,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82418b8c
	if (cr0.eq) goto loc_82418B8C;
	// li r11,1
	r11.s64 = 1;
	// b 0x82418c1c
	goto loc_82418C1C;
loc_82418B8C:
	// rlwinm. r11,r10,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82418c14
	if (cr0.eq) goto loc_82418C14;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r9,12728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x82418bac
	if (cr6.eq) goto loc_82418BAC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82418c14
	if (!cr6.eq) goto loc_82418C14;
loc_82418BAC:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r9,12732(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x82418bc4
	if (cr6.eq) goto loc_82418BC4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82418c14
	if (!cr6.eq) goto loc_82418C14;
loc_82418BC4:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r9,12736(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x82418bdc
	if (cr6.eq) goto loc_82418BDC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82418c14
	if (!cr6.eq) goto loc_82418C14;
loc_82418BDC:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r9,12740(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x82418bf4
	if (cr6.eq) goto loc_82418BF4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82418c14
	if (!cr6.eq) goto loc_82418C14;
loc_82418BF4:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r9,12744(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x82418c0c
	if (cr6.eq) goto loc_82418C0C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82418c14
	if (!cr6.eq) goto loc_82418C14;
loc_82418C0C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82418c18
	goto loc_82418C18;
loc_82418C14:
	// li r11,0
	r11.s64 = 0;
loc_82418C18:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_82418C1C:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82418c60
	if (!cr0.eq) goto loc_82418C60;
	// stw r17,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r17.u32);
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// mr r8,r16
	ctx.r8.u64 = r16.u64;
	// stw r18,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r18.u32);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// stw r14,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r14.u32);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// stw r20,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r20.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r21.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82418640
	ctx.lr = 0x82418C5C;
	sub_82418640(ctx, base);
	// b 0x82418e3c
	goto loc_82418E3C;
loc_82418C60:
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// lwz r19,12708(r31)
	r19.u64 = PPC_LOAD_U32(r31.u32 + 12708);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82418d20
	if (cr0.eq) goto loc_82418D20;
	// rlwinm. r11,r10,0,25,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82418d20
	if (cr0.eq) goto loc_82418D20;
	// lis r12,5461
	r12.s64 = 357892096;
	// ori r12,r12,21845
	r12.u64 = r12.u64 | 21845;
	// and. r30,r19,r12
	r30.u64 = r19.u64 & r12.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x82418d20
	if (cr0.eq) goto loc_82418D20;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82418d14
	if (cr6.eq) goto loc_82418D14;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x82418cac
	if (!cr6.gt) goto loc_82418CAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82418CA8;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82418CAC:
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// stw r20,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r20.u32);
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r21.u32);
	// mr r9,r15
	ctx.r9.u64 = r15.u64;
	// ori r10,r10,24576
	ctx.r10.u64 = ctx.r10.u64 | 24576;
	// stw r20,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r20.u32);
	// mr r8,r16
	ctx.r8.u64 = r16.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// stwu r30,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r30.u32);
	r11.u32 = ea;
	// lwz r10,13172(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13172);
	// lwz r6,13176(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 13176);
	// rlwimi r9,r10,18,0,13
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 18) & 0xFFFC0000) | (ctx.r9.u64 & 0xFFFFFFFF0003FFFF);
	// lwz r4,12992(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12992);
	// lwz r5,12996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12996);
	// rlwinm r10,r9,0,0,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFC000;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// subf r7,r5,r23
	ctx.r7.s64 = r23.s64 - ctx.r5.s64;
	// rlwimi r10,r6,0,18,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0x3FFF) | (ctx.r10.u64 & 0xFFFFFFFFFFFFC000);
	// subf r6,r4,r24
	ctx.r6.s64 = r24.s64 - ctx.r4.s64;
	// subf r5,r5,r26
	ctx.r5.s64 = r26.s64 - ctx.r5.s64;
	// subf r4,r4,r25
	ctx.r4.s64 = r25.s64 - ctx.r4.s64;
	// bl 0x82418640
	ctx.lr = 0x82418D14;
	sub_82418640(ctx, base);
loc_82418D14:
	// lis r12,-5462
	r12.s64 = -357957632;
	// ori r12,r12,43690
	r12.u64 = r12.u64 | 43690;
	// and r19,r19,r12
	r19.u64 = r19.u64 & r12.u64;
loc_82418D20:
	// lwz r11,12748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82418e3c
	if (!cr6.gt) goto loc_82418E3C;
	// li r23,0
	r23.s64 = 0;
	// addi r28,r31,12996
	r28.s64 = r31.s64 + 12996;
	// addi r24,r31,12756
	r24.s64 = r31.s64 + 12756;
	// b 0x82418d48
	goto loc_82418D48;
loc_82418D40:
	// lwz r26,356(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// lwz r25,348(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
loc_82418D48:
	// lwz r11,-4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -4);
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// bgt cr6,0x82418d58
	if (cr6.gt) goto loc_82418D58;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_82418D58:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// bgt cr6,0x82418d68
	if (cr6.gt) goto loc_82418D68;
	// mr r26,r11
	r26.u64 = r11.u64;
loc_82418D68:
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// lwz r27,364(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82418d7c
	if (cr6.lt) goto loc_82418D7C;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_82418D7C:
	// lwz r29,8(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// lwz r11,372(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bge cr6,0x82418d90
	if (!cr6.lt) goto loc_82418D90;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82418D90:
	// cmpw cr6,r25,r27
	cr6.compare<int32_t>(r25.s32, r27.s32, xer);
	// bge cr6,0x82418e20
	if (!cr6.lt) goto loc_82418E20;
	// cmpw cr6,r26,r29
	cr6.compare<int32_t>(r26.s32, r29.s32, xer);
	// bge cr6,0x82418e20
	if (!cr6.lt) goto loc_82418E20;
	// li r11,3
	r11.s64 = 3;
	// slw r11,r11,r23
	r11.u64 = r23.u8 & 0x20 ? 0 : (r11.u32 << (r23.u8 & 0x3F));
	// and. r30,r11,r19
	r30.u64 = r11.u64 & r19.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x82418e20
	if (cr0.eq) goto loc_82418E20;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82418dcc
	if (!cr6.gt) goto loc_82418DCC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82418DC8;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82418DCC:
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// stw r18,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r18.u32);
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// stw r14,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r14.u32);
	// ori r9,r9,24576
	ctx.r9.u64 = ctx.r9.u64 | 24576;
	// stw r17,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r17.u32);
	// mr r8,r16
	ctx.r8.u64 = r16.u64;
	// stw r20,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r20.u32);
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r21.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stwu r30,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r30.u32);
	r11.u32 = ea;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// subf r7,r9,r29
	ctx.r7.s64 = r29.s64 - ctx.r9.s64;
	// lwz r11,-4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4);
	// subf r5,r9,r26
	ctx.r5.s64 = r26.s64 - ctx.r9.s64;
	// subf r6,r11,r27
	ctx.r6.s64 = r27.s64 - r11.s64;
	// subf r4,r11,r25
	ctx.r4.s64 = r25.s64 - r11.s64;
	// bl 0x82418640
	ctx.lr = 0x82418E20;
	sub_82418640(ctx, base);
loc_82418E20:
	// lwz r11,12748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// addi r23,r23,2
	r23.s64 = r23.s64 + 2;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmplw cr6,r22,r11
	cr6.compare<uint32_t>(r22.u32, r11.u32, xer);
	// blt cr6,0x82418d40
	if (cr6.lt) goto loc_82418D40;
loc_82418E3C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82418E48"))) PPC_WEAK_FUNC(sub_82418E48);
PPC_FUNC_IMPL(__imp__sub_82418E48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82418E50;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x82418e8c
	if (!cr6.eq) goto loc_82418E8C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-32224
	r11.s64 = r11.s64 + -32224;
	// addi r23,r1,112
	r23.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82418E8C:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82418ea0
	if (!cr6.eq) goto loc_82418EA0;
	// rlwinm. r27,r27,0,28,23
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// beq 0x824194b0
	if (cr0.eq) goto loc_824194B0;
loc_82418EA0:
	// lfs f0,12648(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12648);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lfs f13,12652(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12652);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f12,12656(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12656);
	ctx.f12.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lfs f11,12660(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12660);
	ctx.f11.f64 = double(temp.f32);
	// fctiwz f12,f12
	ctx.f12.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f11
	f0.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f12,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f12.u64);
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// mr r24,r11
	r24.u64 = r11.u64;
	// bgt cr6,0x82418ef4
	if (cr6.gt) goto loc_82418EF4;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
loc_82418EF4:
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// mr r25,r11
	r25.u64 = r11.u64;
	// bgt cr6,0x82418f08
	if (cr6.gt) goto loc_82418F08;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
loc_82418F08:
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// mr r26,r11
	r26.u64 = r11.u64;
	// blt cr6,0x82418f20
	if (cr6.lt) goto loc_82418F20;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
loc_82418F20:
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// add r10,r7,r9
	ctx.r10.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// mr r28,r11
	r28.u64 = r11.u64;
	// blt cr6,0x82418f38
	if (cr6.lt) goto loc_82418F38;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
loc_82418F38:
	// lwz r11,11856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11856);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82418f84
	if (cr6.eq) goto loc_82418F84;
	// lwz r11,12676(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12676);
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// bgt cr6,0x82418f54
	if (cr6.gt) goto loc_82418F54;
	// mr r24,r11
	r24.u64 = r11.u64;
loc_82418F54:
	// lwz r11,12680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12680);
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// bgt cr6,0x82418f64
	if (cr6.gt) goto loc_82418F64;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_82418F64:
	// lwz r11,12684(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12684);
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x82418f74
	if (cr6.lt) goto loc_82418F74;
	// mr r26,r11
	r26.u64 = r11.u64;
loc_82418F74:
	// lwz r11,12688(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12688);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82418f84
	if (cr6.lt) goto loc_82418F84;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82418F84:
	// cmpw cr6,r26,r24
	cr6.compare<int32_t>(r26.s32, r24.s32, xer);
	// ble cr6,0x824194b0
	if (!cr6.gt) goto loc_824194B0;
	// cmpw cr6,r28,r25
	cr6.compare<int32_t>(r28.s32, r25.s32, xer);
	// ble cr6,0x824194b0
	if (!cr6.gt) goto loc_824194B0;
	// ld r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// beq cr6,0x824190b4
	if (cr6.eq) goto loc_824190B4;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// and r11,r11,r4
	r11.u64 = r11.u64 & ctx.r4.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x82418fc0
	if (cr6.eq) goto loc_82418FC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,10560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// bl 0x824231b0
	ctx.lr = 0x82418FBC;
	sub_824231B0(ctx, base);
	// std r3,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r3.u64);
loc_82418FC0:
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// clrldi r10,r11,52
	ctx.r10.u64 = r11.u64 & 0xFFF;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82418ff0
	if (cr6.eq) goto loc_82418FF0;
	// addi r6,r31,10548
	ctx.r6.s64 = r31.s64 + 10548;
	// li r5,8704
	ctx.r5.s64 = 8704;
	// rldicr r4,r11,52,11
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 52) & 0xFFF0000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x82418FE4;
	sub_82423548(ctx, base);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// rldicr r11,r11,0,51
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFFFFFFFFFF000;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82418FF0:
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// rlwinm r10,r11,0,15,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1F000;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82419028
	if (cr6.eq) goto loc_82419028;
	// addi r6,r31,10528
	ctx.r6.s64 = r31.s64 + 10528;
	// li r5,8576
	ctx.r5.s64 = 8576;
	// rldicr r4,r11,47,4
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 47) & 0xF800000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x82419014;
	sub_82423548(ctx, base);
	// lis r12,-2
	r12.s64 = -131072;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r12,r12,4095
	r12.u64 = r12.u64 | 4095;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82419028:
	// lis r12,0
	r12.s64 = 0;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,42,21
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFC0000000000;
	// and r10,r11,r12
	ctx.r10.u64 = r11.u64 & r12.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82419070
	if (cr6.eq) goto loc_82419070;
	// addi r6,r31,10368
	ctx.r6.s64 = r31.s64 + 10368;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// rldicr r4,r11,6,15
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 6) & 0xFFFF000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x82419058;
	sub_82423548(ctx, base);
	// lis r12,-1
	r12.s64 = -65536;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// rldicr r12,r12,42,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82419070:
	// lis r12,-32
	r12.s64 = -2097152;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// clrldi r12,r12,22
	r12.u64 = r12.u64 & 0x3FFFFFFFFFF;
	// and r10,r11,r12
	ctx.r10.u64 = r11.u64 & r12.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x824190b4
	if (cr6.eq) goto loc_824190B4;
	// addi r6,r31,10444
	ctx.r6.s64 = r31.s64 + 10444;
	// li r5,8448
	ctx.r5.s64 = 8448;
	// rldicr r4,r11,22,20
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 22) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241909C;
	sub_82423548(ctx, base);
	// lis r12,-32
	r12.s64 = -2097152;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// rldicr r12,r12,21,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 21) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_824190B4:
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x82419104
	if (cr6.eq) goto loc_82419104;
	// lis r12,31
	r12.s64 = 2031616;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,34,29
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFC00000000;
	// and r10,r11,r12
	ctx.r10.u64 = r11.u64 & r12.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82419104
	if (cr6.eq) goto loc_82419104;
	// addi r6,r31,10596
	ctx.r6.s64 = r31.s64 + 10596;
	// li r5,8832
	ctx.r5.s64 = 8832;
	// rldicr r4,r11,9,20
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 9) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x824190EC;
	sub_82423548(ctx, base);
	// lis r12,-32
	r12.s64 = -2097152;
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// rldicr r12,r12,34,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
loc_82419104:
	// ld r11,32(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241913c
	if (cr6.eq) goto loc_8241913C;
	// clrldi r10,r11,26
	ctx.r10.u64 = r11.u64 & 0x3FFFFFFFFF;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x8241913c
	if (cr6.eq) goto loc_8241913C;
	// addi r6,r31,10680
	ctx.r6.s64 = r31.s64 + 10680;
	// li r5,8960
	ctx.r5.s64 = 8960;
	// rldicr r4,r11,26,37
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 26) & 0xFFFFFFFFFC000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x82419130;
	sub_82423548(ctx, base);
	// ld r11,32(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// rldicr r11,r11,0,25
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFFFC000000000;
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
loc_8241913C:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82419154
	if (!cr6.gt) goto loc_82419154;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82419154;
	sub_82412710(ctx, base);
loc_82419154:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// ori r11,r11,24576
	r11.u64 = r11.u64 | 24576;
	// ori r10,r10,15104
	ctx.r10.u64 = ctx.r10.u64 | 15104;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r9,768
	ctx.r9.s64 = 768;
	// lwz r8,12708(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12708);
	// lis r11,-16356
	r11.s64 = -1071906816;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r7,r11,11008
	ctx.r7.u64 = r11.u64 | 11008;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,27
	r30.s64 = 27;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// addi r29,r11,7624
	r29.s64 = r11.s64 + 7624;
	// li r5,108
	ctx.r5.s64 = 108;
	// addi r4,r29,40
	ctx.r4.s64 = r29.s64 + 40;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stwu r30,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r30.u32);
	r11.u32 = ea;
	// mr r30,r11
	r30.u64 = r11.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x824191B8;
	sub_823DA950(ctx, base);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r3,r30,108
	ctx.r3.s64 = r30.s64 + 108;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824191d4
	if (!cr6.gt) goto loc_824191D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824191D4;
	sub_82412710(ctx, base);
loc_824191D4:
	// lis r11,-16374
	r11.s64 = -1073086464;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,11008
	r11.u64 = r11.u64 | 11008;
	// li r9,9
	ctx.r9.s64 = 9;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stwu r9,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r30.u32 = ea;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x82419204;
	sub_823DA950(ctx, base);
	// addi r11,r30,36
	r11.s64 = r30.s64 + 36;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,4097
	ctx.r9.s64 = 268500992;
	// ori r10,r10,8576
	ctx.r10.u64 = ctx.r10.u64 | 8576;
	// ori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 | 1;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82419244
	if (!cr6.gt) goto loc_82419244;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82419244;
	sub_82412710(ctx, base);
loc_82419244:
	// lis r11,2
	r11.s64 = 131072;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,8448
	r11.u64 = r11.u64 | 8448;
	// ori r30,r10,65535
	r30.u64 = ctx.r10.u64 | 65535;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,8851
	ctx.r8.s64 = 8851;
	// li r7,0
	ctx.r7.s64 = 0;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lis r6,2
	ctx.r6.s64 = 131072;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r6,r6,8708
	ctx.r6.u64 = ctx.r6.u64 | 8708;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,768
	ctx.r4.s64 = 768;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r29,8978
	r29.s64 = 8978;
	// mr r21,r30
	r21.u64 = r30.u64;
	// li r11,8205
	r11.s64 = 8205;
	// li r20,0
	r20.s64 = 0;
	// li r12,1
	r12.s64 = 1;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// clrlwi. r19,r27,28
	r19.u64 = r27.u32 & 0xF;
	cr0.compare<int32_t>(r19.s32, 0, xer);
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rldicr r12,r12,41,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 41) & 0xFFFFFFFFFFFFFFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r29,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r3.u32 = ea;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r20,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r20.u32);
	ctx.r3.u32 = ea;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,40,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 40) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,39,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 39) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,35,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 35) & 0xFFFFFFFFFFFFFFFF;
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
	// li r12,1
	r12.s64 = 1;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// rldicr r12,r12,44,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 44) & 0xFFFFFFFFFFFFFFFF;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ld r11,32(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// oris r11,r11,16
	r11.u64 = r11.u64 | 1048576;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// bne 0x82419394
	if (!cr0.eq) goto loc_82419394;
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// stw r22,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r22.u32);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824188e0
	ctx.lr = 0x82419390;
	sub_824188E0(ctx, base);
	// b 0x82419468
	goto loc_82419468;
loc_82419394:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824193a8
	if (!cr6.gt) goto loc_824193A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824193A8;
	sub_82412710(ctx, base);
loc_824193A8:
	// li r11,8452
	r11.s64 = 8452;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,8706
	r11.s64 = 8706;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,8705
	ctx.r8.s64 = 8705;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// li r12,1
	r12.s64 = 1;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// ori r7,r7,1
	ctx.r7.u64 = ctx.r7.u64 | 1;
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,12440
	r29.s64 = r31.s64 + 12440;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,512
	r11.u64 = r11.u64 | 512;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_8241940C:
	// li r11,1
	r11.s64 = 1;
	// slw r11,r11,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// and. r11,r11,r27
	r11.u64 = r11.u64 & r27.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82419458
	if (cr0.eq) goto loc_82419458;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82419458
	if (cr6.eq) goto loc_82419458;
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// stw r22,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r22.u32);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824188e0
	ctx.lr = 0x82419454;
	sub_824188E0(ctx, base);
	// rlwinm r27,r27,0,28,23
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
loc_82419458:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplwi cr6,r30,4
	cr6.compare<uint32_t>(r30.u32, 4, xer);
	// blt cr6,0x8241940c
	if (cr6.lt) goto loc_8241940C;
loc_82419468:
	// lwz r11,10440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10440);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10436);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,17,0,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r7,r9,17
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 17;
	// rlwinm r10,r10,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0xFFFE0000;
	// srawi r6,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	ctx.r6.s64 = r11.s32 >> 17;
	// srawi r5,r8,17
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 17;
	// srawi r4,r10,17
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 17;
	// bl 0x82413660
	ctx.lr = 0x82419498;
	sub_82413660(ctx, base);
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_824194B0:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_824194BC"))) PPC_WEAK_FUNC(sub_824194BC);
PPC_FUNC_IMPL(__imp__sub_824194BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824194C0"))) PPC_WEAK_FUNC(sub_824194C0);
PPC_FUNC_IMPL(__imp__sub_824194C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824195d0
	if (!cr6.eq) goto loc_824195D0;
	// lwz r7,12440(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12440);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// cmplwi r7,0
	cr0.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne 0x824194ec
	if (!cr0.eq) goto loc_824194EC;
	// lwz r11,12456(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12456);
loc_824194EC:
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r11,10940(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10940);
	// rlwinm r10,r9,14,18,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 14) & 0x3FFF;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// rlwinm r9,r9,29,17,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x7FFF;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm. r31,r11,0,27,27
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// beq 0x82419528
	if (cr0.eq) goto loc_82419528;
	// li r11,1
	r11.s64 = 1;
	// b 0x824195b4
	goto loc_824195B4;
loc_82419528:
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824195ac
	if (cr0.eq) goto loc_824195AC;
	// lwz r11,12728(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12728);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// beq cr6,0x82419544
	if (cr6.eq) goto loc_82419544;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824195ac
	if (!cr6.eq) goto loc_824195AC;
loc_82419544:
	// lwz r11,12444(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12444);
	// lwz r10,12732(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241955c
	if (cr6.eq) goto loc_8241955C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824195ac
	if (!cr6.eq) goto loc_824195AC;
loc_8241955C:
	// lwz r11,12448(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12448);
	// lwz r10,12736(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82419574
	if (cr6.eq) goto loc_82419574;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824195ac
	if (!cr6.eq) goto loc_824195AC;
loc_82419574:
	// lwz r11,12452(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12452);
	// lwz r10,12740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241958c
	if (cr6.eq) goto loc_8241958C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824195ac
	if (!cr6.eq) goto loc_824195AC;
loc_8241958C:
	// lwz r11,12456(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12456);
	// lwz r10,12744(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824195a4
	if (cr6.eq) goto loc_824195A4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824195ac
	if (!cr6.eq) goto loc_824195AC;
loc_824195A4:
	// li r11,1
	r11.s64 = 1;
	// b 0x824195b0
	goto loc_824195B0;
loc_824195AC:
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_824195B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_824195B4:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824195cc
	if (cr0.eq) goto loc_824195CC;
	// lwz r11,13180(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13180);
	// lwz r10,13184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13184);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_824195CC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
loc_824195D0:
	// bl 0x82418e48
	ctx.lr = 0x824195D4;
	sub_82418E48(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824195E8"))) PPC_WEAK_FUNC(sub_824195E8);
PPC_FUNC_IMPL(__imp__sub_824195E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824195F0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,212
	r11.s64 = ctx.r1.s64 + 212;
	// stw r7,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r7.u32);
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r10,r10,7792
	ctx.r10.s64 = ctx.r10.s64 + 7792;
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsldoi128 v63,v63,v63,4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v63.u8), 12));
	// addi r9,r9,7776
	ctx.r9.s64 = ctx.r9.s64 + 7776;
	// vupkd3d128 v12,v63,0
	vTemp.u32[0] = v63.u8[3] | 0x3F800000;
	vTemp.u32[1] = v63.u8[0] | 0x3F800000;
	vTemp.u32[2] = v63.u8[1] | 0x3F800000;
	vTemp.u32[3] = v63.u8[2] | 0x3F800000;
	ctx.v12 = vTemp;
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82419660
	if (!cr6.eq) goto loc_82419660;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824194c0
	ctx.lr = 0x8241965C;
	sub_824194C0(ctx, base);
	// b 0x82419698
	goto loc_82419698;
loc_82419660:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82419698
	if (cr6.eq) goto loc_82419698;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_82419670:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824194c0
	ctx.lr = 0x8241968C;
	sub_824194C0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x82419670
	if (!cr0.eq) goto loc_82419670;
loc_82419698:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824196A4"))) PPC_WEAK_FUNC(sub_824196A4);
PPC_FUNC_IMPL(__imp__sub_824196A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824196A8"))) PPC_WEAK_FUNC(sub_824196A8);
PPC_FUNC_IMPL(__imp__sub_824196A8) {
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
	ctx.lr = 0x824196B0;
	// stwu r1,-1648(r1)
	ea = -1648 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lis r11,10280
	r11.s64 = 673710080;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// ori r30,r11,310
	r30.u64 = r11.u64 | 310;
	// bne cr6,0x824196f4
	if (!cr6.eq) goto loc_824196F4;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bne cr6,0x824196ec
	if (!cr6.eq) goto loc_824196EC;
	// bl 0x82427058
	ctx.lr = 0x824196E4;
	sub_82427058(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// b 0x824196fc
	goto loc_824196FC;
loc_824196EC:
	// bl 0x82427008
	ctx.lr = 0x824196F0;
	sub_82427008(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
loc_824196F4:
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bne cr6,0x82419708
	if (!cr6.eq) goto loc_82419708;
loc_824196FC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82426f08
	ctx.lr = 0x82419704;
	sub_82426F08(ctx, base);
	// b 0x82419710
	goto loc_82419710;
loc_82419708:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82426e10
	ctx.lr = 0x82419710;
	sub_82426E10(ctx, base);
loc_82419710:
	// addi r1,r1,1648
	ctx.r1.s64 = ctx.r1.s64 + 1648;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82419718"))) PPC_WEAK_FUNC(sub_82419718);
PPC_FUNC_IMPL(__imp__sub_82419718) {
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
	ctx.lr = 0x82419720;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r31,16712
	r30.s64 = r31.s64 + 16712;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd684
	ctx.lr = 0x82419734;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,16548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16548);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16548(r31)
	PPC_STORE_U32(r31.u32 + 16548, r11.u32);
	// mftb r11
	r11.u64 = __rdtsc();
	// lwz r10,16704(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16704);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16700(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16700);
	// stw r11,16552(r31)
	PPC_STORE_U32(r31.u32 + 16552, r11.u32);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// beq cr6,0x824197d8
	if (cr6.eq) goto loc_824197D8;
loc_82419760:
	// lwz r11,16700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16700);
	// lwz r8,16548(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16548);
	// rlwinm r11,r11,3,25,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x78;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r11,16572
	ctx.r10.s64 = r11.s64 + 16572;
	// lwz r10,16576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16576);
	// lwz r11,16572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16572);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bgt cr6,0x824197d8
	if (cr6.gt) goto loc_824197D8;
	// lwz r10,16568(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16568);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,16568(r31)
	PPC_STORE_U32(r31.u32 + 16568, ctx.r10.u32);
	// bne cr6,0x824197a4
	if (!cr6.eq) goto loc_824197A4;
	// lwz r11,10900(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// b 0x824197b4
	goto loc_824197B4;
loc_824197A4:
	// lis r10,32712
	ctx.r10.s64 = 2143813632;
	// stw r11,24848(r10)
	PPC_MM_STORE_U32(ctx.r10.u32 + 24848, r11.u32);
	// eieio 
	// sync 
loc_824197B4:
	// mftb r10
	ctx.r10.u64 = __rdtsc();
	// lwz r11,16700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16700);
	// stw r10,23328(r31)
	PPC_STORE_U32(r31.u32 + 23328, ctx.r10.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16700(r31)
	PPC_STORE_U32(r31.u32 + 16700, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,16704(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16704);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82419760
	if (!cr6.eq) goto loc_82419760;
loc_824197D8:
	// lwz r11,16544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82419804
	if (cr6.eq) goto loc_82419804;
	// lwz r10,16568(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16568);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r8,16548(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16548);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82419804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82419804:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd674
	ctx.lr = 0x82419810;
	__imp__KfReleaseSpinLock(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82419818"))) PPC_WEAK_FUNC(sub_82419818);
PPC_FUNC_IMPL(__imp__sub_82419818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82419820;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,2148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r26,r31,16712
	r26.s64 = r31.s64 + 16712;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd684
	ctx.lr = 0x82419840;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r10,16564(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16564);
	// lwz r11,21556(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21556);
	// rlwinm r30,r29,24,28,31
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r27,r29,24
	r27.u64 = r29.u32 & 0xFF;
	// rlwinm r28,r29,0,0,19
	r28.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFF000;
	// stw r10,16564(r31)
	PPC_STORE_U32(r31.u32 + 16564, ctx.r10.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r29,r11
	r29.u64 = r11.u64;
	// bne cr6,0x82419870
	if (!cr6.eq) goto loc_82419870;
	// li r29,60
	r29.s64 = 60;
loc_82419870:
	// mftb r11
	r11.u64 = __rdtsc();
	// lwz r10,16552(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16552);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// subf r24,r10,r11
	r24.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x827bd624
	ctx.lr = 0x82419884;
	__imp__KeQueryPerformanceFrequency(ctx, base);
	// rotlwi r11,r3,0
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// mulli r10,r24,100
	ctx.r10.s64 = r24.s64 * 100;
	// divwu r11,r11,r29
	r11.u32 = r11.u32 / r29.u32;
	// twllei r29,0
	// twllei r11,0
	// divwu r11,r10,r11
	r11.u32 = ctx.r10.u32 / r11.u32;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// cmplwi cr6,r7,100
	cr6.compare<uint32_t>(ctx.r7.u32, 100, xer);
	// ble cr6,0x824198ac
	if (!cr6.gt) goto loc_824198AC;
	// li r7,100
	ctx.r7.s64 = 100;
loc_824198AC:
	// lwz r8,16556(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16556);
	// lwz r10,16548(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16548);
	// add r11,r8,r30
	r11.u64 = ctx.r8.u64 + r30.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x824198d8
	if (cr6.gt) goto loc_824198D8;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824198d8
	if (cr6.eq) goto loc_824198D8;
	// cmplw cr6,r7,r27
	cr6.compare<uint32_t>(ctx.r7.u32, r27.u32, xer);
	// ble cr6,0x824198d8
	if (!cr6.gt) goto loc_824198D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_824198D8:
	// lwz r9,16540(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16540);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8241991c
	if (cr6.eq) goto loc_8241991C;
	// cntlzw r6,r28
	ctx.r6.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lwz r5,16564(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 16564);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r6,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82419918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_8241991C:
	// lwz r10,16548(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16548);
	// stw r11,16556(r31)
	PPC_STORE_U32(r31.u32 + 16556, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82419960
	if (cr6.eq) goto loc_82419960;
	// lwz r10,16564(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16564);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82419960
	if (cr6.eq) goto loc_82419960;
	// lwz r10,16704(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16704);
	// rlwinm r10,r10,3,25,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x78;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// addi r9,r10,16572
	ctx.r9.s64 = ctx.r10.s64 + 16572;
	// stw r11,16576(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16576, r11.u32);
	// stw r28,16572(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16572, r28.u32);
	// lwz r11,16704(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16704);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16704(r31)
	PPC_STORE_U32(r31.u32 + 16704, r11.u32);
	// b 0x8241999c
	goto loc_8241999C;
loc_82419960:
	// lwz r11,16568(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16568);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16568(r31)
	PPC_STORE_U32(r31.u32 + 16568, r11.u32);
	// beq cr6,0x82419988
	if (cr6.eq) goto loc_82419988;
	// lis r11,32712
	r11.s64 = 2143813632;
	// stw r28,24848(r11)
	PPC_MM_STORE_U32(r11.u32 + 24848, r28.u32);
	// eieio 
	// sync 
	// b 0x82419994
	goto loc_82419994;
loc_82419988:
	// lwz r11,10900(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_82419994:
	// mftb r11
	r11.u64 = __rdtsc();
	// stw r11,23328(r31)
	PPC_STORE_U32(r31.u32 + 23328, r11.u32);
loc_8241999C:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd674
	ctx.lr = 0x824199A8;
	__imp__KfReleaseSpinLock(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824199B0"))) PPC_WEAK_FUNC(sub_824199B0);
PPC_FUNC_IMPL(__imp__sub_824199B0) {
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
	ctx.lr = 0x824199B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82429570
	ctx.lr = 0x824199CC;
	sub_82429570(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241bd08
	ctx.lr = 0x824199D8;
	sub_8241BD08(ctx, base);
	// li r28,-1
	r28.s64 = -1;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82419a60
	if (!cr6.eq) goto loc_82419A60;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824199fc
	if (!cr6.gt) goto loc_824199FC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824199FC;
	sub_82412710(ctx, base);
loc_824199FC:
	// li r11,1401
	r11.s64 = 1401;
	// li r10,1
	ctx.r10.s64 = 1;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lis r11,-16380
	r11.s64 = -1073479680;
	// li r9,19
	ctx.r9.s64 = 19;
	// ori r11,r11,15360
	r11.u64 = r11.u64 | 15360;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// li r6,256
	ctx.r6.s64 = 256;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10900(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	r11.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
loc_82419A60:
	// lwz r11,13596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13596);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82419aa8
	if (cr6.eq) goto loc_82419AA8;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82419aa8
	if (cr6.eq) goto loc_82419AA8;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x82419aa0
	if (cr6.eq) goto loc_82419AA0;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x82419a98
	if (cr6.eq) goto loc_82419A98;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82419ab0
	if (!cr6.eq) goto loc_82419AB0;
	// li r11,0
	r11.s64 = 0;
	// b 0x82419ab4
	goto loc_82419AB4;
loc_82419A98:
	// li r11,3
	r11.s64 = 3;
	// b 0x82419ab4
	goto loc_82419AB4;
loc_82419AA0:
	// li r11,2
	r11.s64 = 2;
	// b 0x82419ab4
	goto loc_82419AB4;
loc_82419AA8:
	// li r11,1
	r11.s64 = 1;
	// b 0x82419ab4
	goto loc_82419AB4;
loc_82419AB0:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82419AB4:
	// lwz r10,11852(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 11852);
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwinm r10,r10,9,25,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x7F;
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// or r30,r11,r29
	r30.u64 = r11.u64 | r29.u64;
	// ble cr6,0x82419ae4
	if (!cr6.gt) goto loc_82419AE4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82419AE0;
	sub_82412710(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82419AE4:
	// lis r11,-32190
	r11.s64 = -2109603840;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r6,r11,-26600
	ctx.r6.s64 = r11.s64 + -26600;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411f68
	ctx.lr = 0x82419AFC;
	sub_82411F68(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// bne cr6,0x82419b6c
	if (!cr6.eq) goto loc_82419B6C;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82419b1c
	if (!cr6.gt) goto loc_82419B1C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82419B1C;
	sub_82412710(ctx, base);
loc_82419B1C:
	// lis r11,-16380
	r11.s64 = -1073479680;
	// li r10,19
	ctx.r10.s64 = 19;
	// ori r11,r11,15360
	r11.u64 = r11.u64 | 15360;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r8,256
	ctx.r8.s64 = 256;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10900(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	r11.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
loc_82419B6C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82429570
	ctx.lr = 0x82419B78;
	sub_82429570(ctx, base);
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82419B8C"))) PPC_WEAK_FUNC(sub_82419B8C);
PPC_FUNC_IMPL(__imp__sub_82419B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82419B90"))) PPC_WEAK_FUNC(sub_82419B90);
PPC_FUNC_IMPL(__imp__sub_82419B90) {
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
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lwz r3,48(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82419bc4
	if (!cr6.gt) goto loc_82419BC4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82412710
	ctx.lr = 0x82419BC4;
	sub_82412710(ctx, base);
loc_82419BC4:
	// lis r11,-16382
	r11.s64 = -1073610752;
	// li r10,6209
	ctx.r10.s64 = 6209;
	// ori r11,r11,8448
	r11.u64 = r11.u64 | 8448;
	// lis r9,10280
	ctx.r9.s64 = 673710080;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r8,-1793
	ctx.r8.s64 = -1793;
	// ori r11,r9,310
	r11.u64 = ctx.r9.u64 | 310;
	// li r7,6448
	ctx.r7.s64 = 6448;
	// subf r9,r31,r11
	ctx.r9.s64 = r11.s64 - r31.s64;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// rlwinm r11,r9,3,23,23
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0x100;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// beq cr6,0x82419c14
	if (cr6.eq) goto loc_82419C14;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82419C14:
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
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

__attribute__((alias("__imp__sub_82419C34"))) PPC_WEAK_FUNC(sub_82419C34);
PPC_FUNC_IMPL(__imp__sub_82419C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82419C38"))) PPC_WEAK_FUNC(sub_82419C38);
PPC_FUNC_IMPL(__imp__sub_82419C38) {
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
	ctx.lr = 0x82419C40;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,23932(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23932);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82419c64
	if (cr0.eq) goto loc_82419C64;
	// bl 0x824199b0
	ctx.lr = 0x82419C60;
	sub_824199B0(ctx, base);
	// b 0x82419cb0
	goto loc_82419CB0;
loc_82419C64:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82419c7c
	if (!cr6.gt) goto loc_82419C7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82419C7C;
	sub_82412710(ctx, base);
loc_82419C7C:
	// li r10,6212
	ctx.r10.s64 = 6212;
	// rlwinm r11,r30,12,20,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r30,3
	ctx.r10.u64 = r30.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r9.u32 = ea;
	// stw r9,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r9.u32);
	// bl 0x82419b90
	ctx.lr = 0x82419CB0;
	sub_82419B90(ctx, base);
loc_82419CB0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82419CB8"))) PPC_WEAK_FUNC(sub_82419CB8);
PPC_FUNC_IMPL(__imp__sub_82419CB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82419CC0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// lwz r11,23932(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23932);
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82419cf8
	if (cr0.eq) goto loc_82419CF8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824199b0
	ctx.lr = 0x82419CF8;
	sub_824199B0(ctx, base);
loc_82419CF8:
	// rlwinm. r27,r25,0,29,29
	r27.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// beq 0x82419dc4
	if (cr0.eq) goto loc_82419DC4;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82419d18
	if (!cr6.gt) goto loc_82419D18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82419D18;
	sub_82412710(ctx, base);
loc_82419D18:
	// li r11,6515
	r11.s64 = 6515;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,6500
	r11.s64 = 6500;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,6515
	ctx.r8.s64 = 6515;
	// li r22,0
	r22.s64 = 0;
	// lis r7,-16380
	ctx.r7.s64 = -1073479680;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// li r21,3
	r21.s64 = 3;
	// ori r10,r7,15360
	ctx.r10.u64 = ctx.r7.u64 | 15360;
	// li r20,6515
	r20.s64 = 6515;
	// li r19,0
	r19.s64 = 0;
	// li r18,1
	r18.s64 = 1;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// li r17,256
	r17.s64 = 256;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// li r16,6226
	r16.s64 = 6226;
	// li r11,0
	r11.s64 = 0;
	// li r15,6200
	r15.s64 = 6200;
	// li r7,0
	ctx.r7.s64 = 0;
	// stwu r9,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r14.u32 = ea;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwu r8,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r14.u32 = ea;
	// stwu r22,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r22.u32);
	r14.u32 = ea;
	// stwu r10,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r14.u32 = ea;
	// stwu r21,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r21.u32);
	r14.u32 = ea;
	// stwu r20,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r20.u32);
	r14.u32 = ea;
	// stwu r19,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r19.u32);
	r14.u32 = ea;
	// stwu r18,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r18.u32);
	r14.u32 = ea;
	// stwu r17,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r17.u32);
	r14.u32 = ea;
	// stwu r16,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r16.u32);
	r14.u32 = ea;
	// stwu r11,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r11.u32);
	r14.u32 = ea;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stwu r15,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r15.u32);
	r14.u32 = ea;
	// stwu r11,4(r14)
	ea = 4 + r14.u32;
	PPC_STORE_U32(ea, r11.u32);
	r14.u32 = ea;
	// stw r14,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r14.u32);
	// bl 0x8242c318
	ctx.lr = 0x82419DC4;
	sub_8242C318(ctx, base);
loc_82419DC4:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82419b90
	ctx.lr = 0x82419DD0;
	sub_82419B90(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82419de8
	if (!cr6.gt) goto loc_82419DE8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82419DE8;
	sub_82412710(ctx, base);
loc_82419DE8:
	// rlwinm r11,r26,12,20,31
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 12) & 0xFFF;
	// li r10,6212
	ctx.r10.s64 = 6212;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r26,3
	ctx.r10.u64 = r26.u32 & 0x1FFFFFFF;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// beq cr6,0x82419e68
	if (cr6.eq) goto loc_82419E68;
	// li r10,6200
	ctx.r10.s64 = 6200;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lis r8,-16380
	ctx.r8.s64 = -1073479680;
	// li r7,3
	ctx.r7.s64 = 3;
	// ori r10,r8,15360
	ctx.r10.u64 = ctx.r8.u64 | 15360;
	// li r8,6515
	ctx.r8.s64 = 6515;
	// li r6,0
	ctx.r6.s64 = 0;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,256
	ctx.r4.s64 = 256;
	// li r3,6226
	ctx.r3.s64 = 6226;
	// li r9,1
	ctx.r9.s64 = 1;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r6,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r11.u32 = ea;
	// stwu r5,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	r11.u32 = ea;
	// stwu r4,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r11.u32 = ea;
	// stwu r3,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
loc_82419E68:
	// rlwinm. r10,r25,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// beq 0x82419e84
	if (cr0.eq) goto loc_82419E84;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824196a8
	ctx.lr = 0x82419E84;
	sub_824196A8(ctx, base);
loc_82419E84:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82419E8C"))) PPC_WEAK_FUNC(sub_82419E8C);
PPC_FUNC_IMPL(__imp__sub_82419E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82419E90"))) PPC_WEAK_FUNC(sub_82419E90);
PPC_FUNC_IMPL(__imp__sub_82419E90) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x824199b0
	sub_824199B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82419E98"))) PPC_WEAK_FUNC(sub_82419E98);
PPC_FUNC_IMPL(__imp__sub_82419E98) {
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
	ctx.lr = 0x82419EA0;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// addi r4,r28,28
	ctx.r4.s64 = r28.s64 + 28;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r11,16560(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16560);
	// li r5,24
	ctx.r5.s64 = 24;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16560(r31)
	PPC_STORE_U32(r31.u32 + 16560, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x82419ECC;
	sub_823DA950(ctx, base);
	// lwz r11,13608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13608);
	// lwz r29,132(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi r10,r29,26
	ctx.r10.u64 = r29.u32 & 0x3F;
	// cmplwi cr6,r10,50
	cr6.compare<uint32_t>(ctx.r10.u32, 50, xer);
	// bne cr6,0x82419ee8
	if (!cr6.eq) goto loc_82419EE8;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x82419ef4
	goto loc_82419EF4;
loc_82419EE8:
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bne cr6,0x82419efc
	if (!cr6.eq) goto loc_82419EFC;
	// li r10,27
	ctx.r10.s64 = 27;
loc_82419EF4:
	// rlwimi r29,r10,1,26,31
	r29.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0x3F) | (r29.u64 & 0xFFFFFFFFFFFFFFC0);
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r29.u32);
loc_82419EFC:
	// lwz r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// rlwinm r30,r11,15,17,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x7FFF;
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r3,r31,14844
	ctx.r3.s64 = r31.s64 + 14844;
	// rlwimi r10,r30,0,19,30
	ctx.r10.u64 = (__builtin_rotateleft32(r30.u32, 0) & 0x1FFE) | (ctx.r10.u64 & 0xFFFFFFFFFFFFE001);
	// rlwimi r9,r11,25,22,29
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 25) & 0x3FC) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFC03);
	// rlwimi r30,r10,0,0,30
	r30.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFFFFFFE) | (r30.u64 & 0xFFFFFFFF00000001);
	// li r5,52
	ctx.r5.s64 = 52;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// bl 0x823da950
	ctx.lr = 0x82419F2C;
	sub_823DA950(ctx, base);
	// lwz r9,136(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// rlwinm r11,r30,2,30,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x2;
	// lwz r10,13612(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13612);
	// clrlwi r8,r9,19
	ctx.r8.u64 = ctx.r9.u32 & 0x1FFF;
	// lwz r7,21632(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 21632);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r9,r9,19,19,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0x1FFF;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r6,r29,0,0,19
	ctx.r6.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFF000;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// clrlwi r5,r29,26
	ctx.r5.u64 = r29.u32 & 0x3F;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// li r24,0
	r24.s64 = 0;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// mr r29,r24
	r29.u64 = r24.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// beq cr6,0x82419fe8
	if (cr6.eq) goto loc_82419FE8;
	// lwz r10,21624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 21624);
	// lwz r11,21628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21628);
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// cmplwi cr6,r10,6
	cr6.compare<uint32_t>(ctx.r10.u32, 6, xer);
	// bge cr6,0x82419fe8
	if (!cr6.lt) goto loc_82419FE8;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// lwz r10,10896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r24,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r24.u32);
	// lwz r10,10896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lwz r11,21628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21628);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r24,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r24.u32);
	// lwz r11,21628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21628);
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x824294e0
	ctx.lr = 0x82419FE4;
	sub_824294E0(ctx, base);
	// li r29,1
	r29.s64 = 1;
loc_82419FE8:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8241a028
	if (cr6.eq) goto loc_8241A028;
	// addi r10,r31,13640
	ctx.r10.s64 = r31.s64 + 13640;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r8,r26,28
	ctx.r8.s64 = r26.s64 + 28;
loc_82419FFC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8241a01c
	if (!cr0.eq) goto loc_8241A01C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x82419ffc
	if (!cr6.eq) goto loc_82419FFC;
loc_8241A01C:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r27,1
	r27.s64 = 1;
	// bne 0x8241a02c
	if (!cr0.eq) goto loc_8241A02C;
loc_8241A028:
	// mr r27,r24
	r27.u64 = r24.u64;
loc_8241A02C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-9704(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9704);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8241a058
	if (cr6.eq) goto loc_8241A058;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241a054
	if (!cr6.gt) goto loc_8241A054;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241A054;
	sub_82412710(ctx, base);
loc_8241A054:
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
loc_8241A058:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x8241a06c
	if (cr6.eq) goto loc_8241A06C;
	// lwz r11,23908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23908);
	// oris r11,r11,16384
	r11.u64 = r11.u64 | 1073741824;
	// stw r11,23908(r31)
	PPC_STORE_U32(r31.u32 + 23908, r11.u32);
loc_8241A06C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8242eab0
	ctx.lr = 0x8241A078;
	sub_8242EAB0(ctx, base);
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x827bd6f4
	ctx.lr = 0x8241A084;
	__imp__VdGetSystemCommandBuffer(ctx, base);
	// lwz r11,21532(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21532);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241a0a0
	if (cr6.eq) goto loc_8241A0A0;
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r10,10896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// b 0x8241a0f0
	goto loc_8241A0F0;
loc_8241A0A0:
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412928
	ctx.lr = 0x8241A0AC;
	sub_82412928(ctx, base);
	// addi r9,r1,100
	ctx.r9.s64 = ctx.r1.s64 + 100;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r7,116(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r11,8
	ctx.r5.s64 = r11.s64 + 8;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x827bd6e4
	ctx.lr = 0x8241A0E8;
	__imp__VdSwap(ctx, base);
	// addi r11,r30,256
	r11.s64 = r30.s64 + 256;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
loc_8241A0F0:
	// lwz r11,212(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r11,23300(r31)
	PPC_STORE_U32(r31.u32 + 23300, r11.u32);
	// beq cr6,0x8241a130
	if (cr6.eq) goto loc_8241A130;
	// lwz r11,21628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21628);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x824294e0
	ctx.lr = 0x8241A124;
	sub_824294E0(ctx, base);
	// lwz r11,21628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21628);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stw r11,21628(r31)
	PPC_STORE_U32(r31.u32 + 21628, r11.u32);
loc_8241A130:
	// lwz r11,216(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241a140
	if (cr6.eq) goto loc_8241A140;
	// stw r11,23928(r31)
	PPC_STORE_U32(r31.u32 + 23928, r11.u32);
loc_8241A140:
	// lwz r30,16708(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16708);
	// stw r24,16708(r31)
	PPC_STORE_U32(r31.u32 + 16708, r24.u32);
	// rlwinm. r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a160
	if (cr0.eq) goto loc_8241A160;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,13544
	ctx.r4.s64 = r31.s64 + 13544;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82426360
	ctx.lr = 0x8241A160;
	sub_82426360(ctx, base);
loc_8241A160:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x8241a184
	if (cr6.eq) goto loc_8241A184;
	// addi r3,r31,13640
	ctx.r3.s64 = r31.s64 + 13640;
	// li r5,28
	ctx.r5.s64 = 28;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x823da950
	ctx.lr = 0x8241A178;
	sub_823DA950(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8242c540
	ctx.lr = 0x8241A184;
	sub_8242C540(ctx, base);
loc_8241A184:
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r8,216(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r26,r11,r10
	r26.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x8241a270
	if (cr6.eq) goto loc_8241A270;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplw cr6,r11,r25
	cr6.compare<uint32_t>(r11.u32, r25.u32, xer);
	// bne cr6,0x8241a270
	if (!cr6.eq) goto loc_8241A270;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r3,r31,13668
	ctx.r3.s64 = r31.s64 + 13668;
	// mr r27,r24
	r27.u64 = r24.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// lis r28,10280
	r28.s64 = 673710080;
	// bne cr6,0x8241a1d8
	if (!cr6.eq) goto loc_8241A1D8;
	// ori r28,r28,310
	r28.u64 = r28.u64 | 310;
	// b 0x8241a1dc
	goto loc_8241A1DC;
loc_8241A1D8:
	// ori r28,r28,262
	r28.u64 = r28.u64 | 262;
loc_8241A1DC:
	// lwz r11,236(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241a238
	if (cr6.eq) goto loc_8241A238;
	// addi r11,r1,240
	r11.s64 = ctx.r1.s64 + 240;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r8,r11,56
	ctx.r8.s64 = r11.s64 + 56;
loc_8241A1F4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8241a214
	if (!cr0.eq) goto loc_8241A214;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x8241a1f4
	if (!cr6.eq) goto loc_8241A1F4;
loc_8241A214:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8241a238
	if (cr0.eq) goto loc_8241A238;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x823da950
	ctx.lr = 0x8241A228;
	sub_823DA950(ctx, base);
	// lbz r11,10942(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,10942(r31)
	PPC_STORE_U8(r31.u32 + 10942, r11.u8);
	// b 0x8241a254
	goto loc_8241A254;
loc_8241A238:
	// lbz r11,10942(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a258
	if (cr0.eq) goto loc_8241A258;
	// lwz r11,352(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241a258
	if (!cr6.eq) goto loc_8241A258;
	// addi r29,r31,13724
	r29.s64 = r31.s64 + 13724;
loc_8241A254:
	// ori r30,r30,4
	r30.u64 = r30.u64 | 4;
loc_8241A258:
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8241a268
	if (!cr0.eq) goto loc_8241A268;
	// ori r30,r30,3
	r30.u64 = r30.u64 | 3;
loc_8241A268:
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// b 0x8241a2bc
	goto loc_8241A2BC;
loc_8241A270:
	// lbz r11,10942(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// addi r29,r31,13724
	r29.s64 = r31.s64 + 13724;
	// lwz r28,13608(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 13608);
	// addi r27,r31,15004
	r27.s64 = r31.s64 + 15004;
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a2a8
	if (cr0.eq) goto loc_8241A2A8;
	// li r5,56
	ctx.r5.s64 = 56;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,13668
	ctx.r3.s64 = r31.s64 + 13668;
	// bl 0x823d9890
	ctx.lr = 0x8241A298;
	sub_823D9890(ctx, base);
	// lbz r11,10942(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// ori r30,r30,4
	r30.u64 = r30.u64 | 4;
	// andi. r11,r11,239
	r11.u64 = r11.u64 & 239;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,10942(r31)
	PPC_STORE_U8(r31.u32 + 10942, r11.u8);
loc_8241A2A8:
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8241a2b8
	if (cr0.eq) goto loc_8241A2B8;
	// ori r30,r30,3
	r30.u64 = r30.u64 | 3;
loc_8241A2B8:
	// andi. r11,r11,191
	r11.u64 = r11.u64 & 191;
	cr0.compare<int32_t>(r11.s32, 0, xer);
loc_8241A2BC:
	// stb r11,10943(r31)
	PPC_STORE_U8(r31.u32 + 10943, r11.u8);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-9716(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9716);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8241a2dc
	if (!cr6.eq) goto loc_8241A2DC;
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a2e0
	if (cr0.eq) goto loc_8241A2E0;
loc_8241A2DC:
	// mr r30,r24
	r30.u64 = r24.u64;
loc_8241A2E0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8241a310
	if (cr6.eq) goto loc_8241A310;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lwz r7,96(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82419cb8
	ctx.lr = 0x8241A30C;
	sub_82419CB8(ctx, base);
	// b 0x8241a31c
	goto loc_8241A31C;
loc_8241A310:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82419c38
	ctx.lr = 0x8241A31C;
	sub_82419C38(ctx, base);
loc_8241A31C:
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lwz r7,96(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8242a6e8
	ctx.lr = 0x8241A340;
	sub_8242A6E8(ctx, base);
	// rlwinm. r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a3b8
	if (cr0.eq) goto loc_8241A3B8;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241a360
	if (!cr6.gt) goto loc_8241A360;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241A360;
	sub_82412710(ctx, base);
loc_8241A360:
	// lis r11,-16382
	r11.s64 = -1073610752;
	// li r10,7758
	ctx.r10.s64 = 7758;
	// ori r11,r11,8448
	r11.u64 = r11.u64 | 8448;
	// li r9,-2
	ctx.r9.s64 = -2;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// mr r11,r24
	r11.u64 = r24.u64;
	// addi r8,r1,184
	ctx.r8.s64 = ctx.r1.s64 + 184;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// stwu r10,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r7.u32 = ea;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r7.u32 = ea;
	// std r24,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, r24.u64);
	// stw r24,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r24.u32);
	// stw r7,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r7.u32);
	// bl 0x827bd6d4
	ctx.lr = 0x8241A3A4;
	__imp__VdPersistDisplay(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8241a3b8
	if (cr0.eq) goto loc_8241A3B8;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r4,160(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// bl 0x827bcf34
	ctx.lr = 0x8241A3B8;
	__imp__MmFreePhysicalMemory(ctx, base);
loc_8241A3B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,10908(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// bl 0x82412710
	ctx.lr = 0x8241A3C4;
	sub_82412710(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8242c570
	ctx.lr = 0x8241A3D4;
	sub_8242C570(ctx, base);
	// lwz r11,14912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14912);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r4,r11,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x82412318
	ctx.lr = 0x8241A3E4;
	sub_82412318(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,14940(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 14940);
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411e98
	ctx.lr = 0x8241A3FC;
	sub_82411E98(ctx, base);
	// lwz r11,23932(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23932);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a448
	if (cr0.eq) goto loc_8241A448;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82412ea0
	ctx.lr = 0x8241A418;
	sub_82412EA0(ctx, base);
loc_8241A418:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82412f98
	ctx.lr = 0x8241A420;
	sub_82412F98(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8241a43c
	if (cr0.eq) goto loc_8241A43C;
	// lwz r11,16568(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16568);
	// lwz r10,16560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16560);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// cmplwi cr6,r11,15
	cr6.compare<uint32_t>(r11.u32, 15, xer);
	// bge cr6,0x8241a418
	if (!cr6.lt) goto loc_8241A418;
loc_8241A43C:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82412ed0
	ctx.lr = 0x8241A444;
	sub_82412ED0(ctx, base);
	// b 0x8241a44c
	goto loc_8241A44C;
loc_8241A448:
	// stw r30,14940(r31)
	PPC_STORE_U32(r31.u32 + 14940, r30.u32);
loc_8241A44C:
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// andi. r11,r11,239
	r11.u64 = r11.u64 & 239;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
	// bl 0x824296e8
	ctx.lr = 0x8241A460;
	sub_824296E8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824161e0
	ctx.lr = 0x8241A46C;
	sub_824161E0(ctx, base);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8241A474"))) PPC_WEAK_FUNC(sub_8241A474);
PPC_FUNC_IMPL(__imp__sub_8241A474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241A478"))) PPC_WEAK_FUNC(sub_8241A478);
PPC_FUNC_IMPL(__imp__sub_8241A478) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,13516(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 13516);
	// beq 0x8241a500
	if (cr0.eq) goto loc_8241A500;
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r10,14916(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 14916);
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8241a4ac
	if (!cr6.eq) goto loc_8241A4AC;
	// lwz r7,156(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r10,152(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// rlwinm r9,r7,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_8241A4AC:
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r7,r6,-1
	ctx.r7.s64 = ctx.r6.s64 + -1;
	// subf r8,r8,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r8.s64;
	// addi r9,r9,164
	ctx.r9.s64 = ctx.r9.s64 + 164;
	// andc r3,r8,r7
	ctx.r3.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bge cr6,0x8241a4d4
	if (!cr6.lt) goto loc_8241A4D4;
loc_8241A4CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8241A4D4:
	// subf r10,r3,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r3.s64;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r8,56(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// srawi r10,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// stw r3,14916(r11)
	PPC_STORE_U32(r11.u32 + 14916, ctx.r3.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// subf r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	// stw r9,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r9.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r10.u32);
	// blr 
	return;
loc_8241A500:
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8241a4cc
	if (!cr6.eq) goto loc_8241A4CC;
	// lwz r10,152(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// stw r10,14928(r11)
	PPC_STORE_U32(r11.u32 + 14928, ctx.r10.u32);
	// lwz r11,156(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lwz r3,152(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241A524"))) PPC_WEAK_FUNC(sub_8241A524);
PPC_FUNC_IMPL(__imp__sub_8241A524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241A528"))) PPC_WEAK_FUNC(sub_8241A528);
PPC_FUNC_IMPL(__imp__sub_8241A528) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8241A530;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8241a54c
	if (!cr6.eq) goto loc_8241A54C;
	// li r29,-1
	r29.s64 = -1;
loc_8241A54C:
	// lwz r30,4(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r31,r27,8
	r31.s64 = r27.s64 + 8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8241a5bc
	if (cr6.eq) goto loc_8241A5BC;
loc_8241A55C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm. r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a5b0
	if (cr0.eq) goto loc_8241A5B0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// and. r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 & r29.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8241a578
	if (cr0.eq) goto loc_8241A578;
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
loc_8241A578:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8241a588
	if (cr0.eq) goto loc_8241A588;
	// stw r28,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r28.u32);
loc_8241A588:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// cmplwi cr6,r10,9
	cr6.compare<uint32_t>(ctx.r10.u32, 9, xer);
	// bne cr6,0x8241a5b0
	if (!cr6.eq) goto loc_8241A5B0;
	// lwz r4,112(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8241a5b0
	if (cr6.eq) goto loc_8241A5B0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8241a528
	ctx.lr = 0x8241A5B0;
	sub_8241A528(ctx, base);
loc_8241A5B0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x8241a55c
	if (!cr0.eq) goto loc_8241A55C;
loc_8241A5BC:
	// lwz r27,0(r27)
	r27.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8241a54c
	if (!cr6.eq) goto loc_8241A54C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8241A5D0"))) PPC_WEAK_FUNC(sub_8241A5D0);
PPC_FUNC_IMPL(__imp__sub_8241A5D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,156(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,16384
	ctx.r10.s64 = 1073741824;
	// lwz r11,152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r4,r9,512
	ctx.r4.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r10,r4,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x1000;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// clrlwi r11,r11,3
	r11.u64 = r11.u32 & 0x1FFFFFFF;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// subf r4,r7,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r7.s64;
	// subf r3,r6,r11
	ctx.r3.s64 = r11.s64 - ctx.r6.s64;
	// b 0x82425cd8
	sub_82425CD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8241A62C"))) PPC_WEAK_FUNC(sub_8241A62C);
PPC_FUNC_IMPL(__imp__sub_8241A62C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241A630"))) PPC_WEAK_FUNC(sub_8241A630);
PPC_FUNC_IMPL(__imp__sub_8241A630) {
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
	ctx.lr = 0x8241A638;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,502
	ctx.r4.s64 = 502;
	// lwz r29,13520(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 13520);
	// bl 0x82411840
	ctx.lr = 0x8241A650;
	sub_82411840(ctx, base);
	// lbz r11,10941(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10941);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a668
	if (cr0.eq) goto loc_8241A668;
	// lwz r31,16728(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16728);
	// b 0x8241a6c4
	goto loc_8241A6C4;
loc_8241A668:
	// rlwinm r11,r31,12,20,31
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 12) & 0xFFF;
	// stw r31,13520(r30)
	PPC_STORE_U32(r30.u32 + 13520, r31.u32);
	// clrlwi r10,r31,3
	ctx.r10.u64 = r31.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addis r3,r11,-16384
	ctx.r3.s64 = r11.s64 + -1073741824;
	// bne cr6,0x8241a6a0
	if (!cr6.eq) goto loc_8241A6A0;
	// lwz r11,13516(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 13516);
	// stw r3,112(r11)
	PPC_STORE_U32(r11.u32 + 112, ctx.r3.u32);
	// b 0x8241a6b8
	goto loc_8241A6B8;
loc_8241A6A0:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwz r11,13524(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 13524);
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// srawi r11,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r11.s64 = r11.s32 >> 3;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_8241A6B8:
	// addi r4,r3,2008
	ctx.r4.s64 = ctx.r3.s64 + 2008;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82425cd8
	ctx.lr = 0x8241A6C4;
	sub_82425CD8(ctx, base);
loc_8241A6C4:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r11,r31,2008
	r11.s64 = r31.s64 + 2008;
	// stw r3,13524(r30)
	PPC_STORE_U32(r30.u32 + 13524, ctx.r3.u32);
	// stw r11,13528(r30)
	PPC_STORE_U32(r30.u32 + 13528, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8241A6DC"))) PPC_WEAK_FUNC(sub_8241A6DC);
PPC_FUNC_IMPL(__imp__sub_8241A6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241A6E0"))) PPC_WEAK_FUNC(sub_8241A6E0);
PPC_FUNC_IMPL(__imp__sub_8241A6E0) {
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
	ctx.lr = 0x8241A6E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,34
	ctx.r4.s64 = 34;
	// lwz r29,13532(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 13532);
	// bl 0x82411840
	ctx.lr = 0x8241A700;
	sub_82411840(ctx, base);
	// lbz r11,10941(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10941);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241a718
	if (cr0.eq) goto loc_8241A718;
	// lwz r31,16728(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16728);
	// b 0x8241a774
	goto loc_8241A774;
loc_8241A718:
	// rlwinm r11,r31,12,20,31
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 12) & 0xFFF;
	// stw r31,13532(r30)
	PPC_STORE_U32(r30.u32 + 13532, r31.u32);
	// clrlwi r10,r31,3
	ctx.r10.u64 = r31.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addis r3,r11,-16384
	ctx.r3.s64 = r11.s64 + -1073741824;
	// bne cr6,0x8241a750
	if (!cr6.eq) goto loc_8241A750;
	// lwz r11,13516(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 13516);
	// stw r3,116(r11)
	PPC_STORE_U32(r11.u32 + 116, ctx.r3.u32);
	// b 0x8241a768
	goto loc_8241A768;
loc_8241A750:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwz r11,13536(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 13536);
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// srawi r11,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r11.s64 = r11.s32 >> 3;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_8241A768:
	// addi r4,r3,136
	ctx.r4.s64 = ctx.r3.s64 + 136;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82425cd8
	ctx.lr = 0x8241A774;
	sub_82425CD8(ctx, base);
loc_8241A774:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r11,r31,136
	r11.s64 = r31.s64 + 136;
	// stw r3,13536(r30)
	PPC_STORE_U32(r30.u32 + 13536, ctx.r3.u32);
	// stw r11,13540(r30)
	PPC_STORE_U32(r30.u32 + 13540, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8241A78C"))) PPC_WEAK_FUNC(sub_8241A78C);
PPC_FUNC_IMPL(__imp__sub_8241A78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241A790"))) PPC_WEAK_FUNC(sub_8241A790);
PPC_FUNC_IMPL(__imp__sub_8241A790) {
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
	ctx.lr = 0x8241A798;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r10,2148(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2148);
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bge cr6,0x8241a7cc
	if (!cr6.lt) goto loc_8241A7CC;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_8241A7CC:
	// addi r29,r10,14972
	r29.s64 = ctx.r10.s64 + 14972;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8241A7D8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,164(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8241A7F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8241A800;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8241A80C"))) PPC_WEAK_FUNC(sub_8241A80C);
PPC_FUNC_IMPL(__imp__sub_8241A80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241A810"))) PPC_WEAK_FUNC(sub_8241A810);
PPC_FUNC_IMPL(__imp__sub_8241A810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,2148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r31,r11,14972
	r31.s64 = r11.s64 + 14972;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8241A840;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,164(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// lwz r11,176(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8241A850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8241A858;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_8241A870"))) PPC_WEAK_FUNC(sub_8241A870);
PPC_FUNC_IMPL(__imp__sub_8241A870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8241A878;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,2148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r31,r11,14972
	r31.s64 = r11.s64 + 14972;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8241A8A0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,164(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// lwz r11,180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8241A8B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8241A8C0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8241A8C8"))) PPC_WEAK_FUNC(sub_8241A8C8);
PPC_FUNC_IMPL(__imp__sub_8241A8C8) {
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
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241a8f0
	if (!cr6.eq) goto loc_8241A8F0;
	// bl 0x8241a810
	ctx.lr = 0x8241A8EC;
	sub_8241A810(ctx, base);
	// b 0x8241a900
	goto loc_8241A900;
loc_8241A8F0:
	// bl 0x8241a5d0
	ctx.lr = 0x8241A8F4;
	sub_8241A5D0(ctx, base);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// bl 0x821310f8
	ctx.lr = 0x8241A900;
	sub_821310F8(ctx, base);
loc_8241A900:
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

__attribute__((alias("__imp__sub_8241A914"))) PPC_WEAK_FUNC(sub_8241A914);
PPC_FUNC_IMPL(__imp__sub_8241A914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241A918"))) PPC_WEAK_FUNC(sub_8241A918);
PPC_FUNC_IMPL(__imp__sub_8241A918) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,184
	ctx.r3.s64 = 184;
	// bl 0x82130b50
	ctx.lr = 0x8241A93C;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8241a94c
	if (!cr0.eq) goto loc_8241A94C;
loc_8241A944:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8241a9a8
	goto loc_8241A9A8;
loc_8241A94C:
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// lis r4,-31360
	ctx.r4.s64 = -2055208960;
	// subfic r11,r11,0
	xer.ca = r11.u32 <= 0;
	r11.s64 = 0 - r11.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwimi r4,r11,28,2,3
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 28) & 0x30000000) | (ctx.r4.u64 & 0xFFFFFFFFCFFFFFFF);
	// bl 0x82130b50
	ctx.lr = 0x8241A968;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8241a980
	if (!cr0.eq) goto loc_8241A980;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x8241A97C;
	sub_821310F8(ctx, base);
	// b 0x8241a944
	goto loc_8241A944;
loc_8241A980:
	// lis r11,80
	r11.s64 = 5242880;
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
	// ori r11,r11,9
	r11.u64 = r11.u64 | 9;
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
loc_8241A9A8:
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

__attribute__((alias("__imp__sub_8241A9C0"))) PPC_WEAK_FUNC(sub_8241A9C0);
PPC_FUNC_IMPL(__imp__sub_8241A9C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91d8
	ctx.lr = 0x8241A9C8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// lwz r23,116(r26)
	r23.u64 = PPC_LOAD_U32(r26.u32 + 116);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lwz r11,8(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// rlwinm r25,r11,2,6,29
	r25.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FFFFFC;
	// beq cr6,0x8241aa54
	if (cr6.eq) goto loc_8241AA54;
	// lwz r10,152(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 152);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addis r30,r11,-16384
	r30.s64 = r11.s64 + -1073741824;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8241AA24;
	sub_823DA950(ctx, base);
	// add r4,r30,r25
	ctx.r4.u64 = r30.u64 + r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82425cd8
	ctx.lr = 0x8241AA34;
	sub_82425CD8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf44
	ctx.lr = 0x8241AA3C;
	__imp__MmQueryAddressProtect(ctx, base);
	// rlwinm. r11,r3,0,21,22
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x600;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241aa54
	if (!cr0.eq) goto loc_8241AA54;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r25,r29
	ctx.r4.u64 = r25.u64 + r29.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82425cd8
	ctx.lr = 0x8241AA54;
	sub_82425CD8(ctx, base);
loc_8241AA54:
	// li r30,0
	r30.s64 = 0;
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// lwz r10,112(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// beq cr6,0x8241aa88
	if (cr6.eq) goto loc_8241AA88;
	// li r11,8
	r11.s64 = 8;
loc_8241AA70:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// bne cr6,0x8241aa70
	if (!cr6.eq) goto loc_8241AA70;
loc_8241AA88:
	// rlwinm. r10,r27,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r22,r30
	r22.u64 = r30.u64;
	// beq 0x8241aaa4
	if (cr0.eq) goto loc_8241AAA4;
	// lwz r10,128(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 128);
	// lwz r9,124(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 124);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r22,r10,2,0,29
	r22.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8241AAA4:
	// add r10,r22,r11
	ctx.r10.u64 = r22.u64 + r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r21,r10,200
	r21.s64 = ctx.r10.s64 + 200;
	// beq cr6,0x8241abac
	if (cr6.eq) goto loc_8241ABAC;
	// addi r27,r31,184
	r27.s64 = r31.s64 + 184;
	// li r5,184
	ctx.r5.s64 = 184;
	// addi r28,r27,16
	r28.s64 = r27.s64 + 16;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r24,r28,r11
	r24.u64 = r28.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8241AAD0;
	sub_823DA950(ctx, base);
	// rlwinm r11,r29,12,20,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r29,3
	ctx.r10.u64 = r29.u32 & 0x1FFFFFFF;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// stw r29,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r29.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r25,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r25.u32);
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// rlwinm r8,r8,0,12,10
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// ori r10,r10,512
	ctx.r10.u64 = ctx.r10.u64 | 512;
	// stw r10,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r10.u32);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// stw r30,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r30.u32);
	// stw r9,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r9.u32);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r10,8(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// rlwimi r11,r10,0,8,31
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFFFFF) | (r11.u64 & 0xFFFFFFFFFF000000);
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// stw r27,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r27.u32);
	// lwz r29,112(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 112);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8241ab88
	if (cr6.eq) goto loc_8241AB88;
	// mr r27,r30
	r27.u64 = r30.u64;
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
loc_8241AB50:
	// addi r11,r27,1
	r11.s64 = r27.s64 + 1;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r29,8
	ctx.r4.s64 = r29.s64 + 8;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x823da950
	ctx.lr = 0x8241AB6C;
	sub_823DA950(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// add r27,r11,r27
	r27.u64 = r11.u64 + r27.u64;
	// lwz r29,0(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8241ab50
	if (!cr6.eq) goto loc_8241AB50;
	// stw r27,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r27.u32);
	// stw r28,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r28.u32);
loc_8241AB88:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8241abac
	if (cr6.eq) goto loc_8241ABAC;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r4,144(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 144);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823da950
	ctx.lr = 0x8241ABA0;
	sub_823DA950(ctx, base);
	// stw r24,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r24.u32);
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
loc_8241ABAC:
	// stw r21,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r21.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8241ABB8"))) PPC_WEAK_FUNC(sub_8241ABB8);
PPC_FUNC_IMPL(__imp__sub_8241ABB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8241ABC0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,108(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// rlwimi r11,r10,1,28,31
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0xF) | (r11.u64 & 0xFFFFFFFFFFFFFFF0);
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// li r29,0
	r29.s64 = 0;
	// stw r11,108(r30)
	PPC_STORE_U32(r30.u32 + 108, r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8241ac20
	if (cr6.eq) goto loc_8241AC20;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,2148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82411e98
	ctx.lr = 0x8241AC1C;
	sub_82411E98(ctx, base);
	// stw r29,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r29.u32);
loc_8241AC20:
	// lwz r11,152(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241ac34
	if (!cr6.eq) goto loc_8241AC34;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8241a810
	ctx.lr = 0x8241AC34;
	sub_8241A810(ctx, base);
loc_8241AC34:
	// stw r30,13516(r31)
	PPC_STORE_U32(r31.u32 + 13516, r30.u32);
	// li r11,4
	r11.s64 = 4;
	// lwz r10,108(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// rlwinm r10,r10,0,28,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF8F;
	// stw r10,108(r30)
	PPC_STORE_U32(r30.u32 + 108, ctx.r10.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r29,124(r30)
	PPC_STORE_U32(r30.u32 + 124, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,128(r30)
	PPC_STORE_U32(r30.u32 + 128, r29.u32);
	// stw r29,132(r30)
	PPC_STORE_U32(r30.u32 + 132, r29.u32);
	// stw r29,112(r30)
	PPC_STORE_U32(r30.u32 + 112, r29.u32);
	// stw r29,116(r30)
	PPC_STORE_U32(r30.u32 + 116, r29.u32);
	// stw r29,120(r30)
	PPC_STORE_U32(r30.u32 + 120, r29.u32);
	// stw r29,144(r30)
	PPC_STORE_U32(r30.u32 + 144, r29.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r9,14928(r31)
	PPC_STORE_U32(r31.u32 + 14928, ctx.r9.u32);
	// lbz r10,10941(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// andi. r10,r10,223
	ctx.r10.u64 = ctx.r10.u64 & 223;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r29,14916(r31)
	PPC_STORE_U32(r31.u32 + 14916, r29.u32);
	// stw r29,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r29.u32);
	// lwz r11,168(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// stw r11,14912(r31)
	PPC_STORE_U32(r31.u32 + 14912, r11.u32);
	// stw r29,13520(r31)
	PPC_STORE_U32(r31.u32 + 13520, r29.u32);
	// stw r29,13524(r31)
	PPC_STORE_U32(r31.u32 + 13524, r29.u32);
	// stw r29,13528(r31)
	PPC_STORE_U32(r31.u32 + 13528, r29.u32);
	// stw r29,13532(r31)
	PPC_STORE_U32(r31.u32 + 13532, r29.u32);
	// stw r29,13536(r31)
	PPC_STORE_U32(r31.u32 + 13536, r29.u32);
	// stw r29,13540(r31)
	PPC_STORE_U32(r31.u32 + 13540, r29.u32);
	// stb r10,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, ctx.r10.u8);
	// bl 0x82412710
	ctx.lr = 0x8241ACB0;
	sub_82412710(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// addi r24,r30,24
	r24.s64 = r30.s64 + 24;
	// beq cr6,0x8241ace0
	if (cr6.eq) goto loc_8241ACE0;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// li r11,5
	r11.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_8241ACC8:
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x8241acc8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8241ACC8;
	// b 0x8241acf4
	goto loc_8241ACF4;
loc_8241ACE0:
	// std r29,24(r30)
	PPC_STORE_U64(r30.u32 + 24, r29.u64);
	// std r29,32(r30)
	PPC_STORE_U64(r30.u32 + 32, r29.u64);
	// std r29,40(r30)
	PPC_STORE_U64(r30.u32 + 40, r29.u64);
	// std r29,48(r30)
	PPC_STORE_U64(r30.u32 + 48, r29.u64);
	// std r29,56(r30)
	PPC_STORE_U64(r30.u32 + 56, r29.u64);
loc_8241ACF4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r10,r30,64
	ctx.r10.s64 = r30.s64 + 64;
	// li r9,5
	ctx.r9.s64 = 5;
	// beq cr6,0x8241ad24
	if (cr6.eq) goto loc_8241AD24;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8241AD0C:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x8241ad0c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8241AD0C;
	// b 0x8241ad40
	goto loc_8241AD40;
loc_8241AD24:
	// mr r11,r24
	r11.u64 = r24.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8241AD2C:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x8241ad2c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8241AD2C;
loc_8241AD40:
	// lwz r10,108(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// rlwinm r9,r26,28,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 28) & 0x1;
	// rlwinm r11,r26,3,23,23
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 3) & 0x100;
	// rlwinm r10,r10,0,25,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// rlwinm r10,r10,0,17,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// rlwinm r11,r11,7,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm. r9,r26,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// li r28,-1
	r28.s64 = -1;
	// stw r11,108(r30)
	PPC_STORE_U32(r30.u32 + 108, r11.u32);
	// beq 0x8241ad80
	if (cr0.eq) goto loc_8241AD80;
	// stw r28,10912(r31)
	PPC_STORE_U32(r31.u32 + 10912, r28.u32);
	// lwz r11,108(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// b 0x8241ad90
	goto loc_8241AD90;
loc_8241AD80:
	// lis r11,64
	r11.s64 = 4194304;
	// stw r11,10912(r31)
	PPC_STORE_U32(r31.u32 + 10912, r11.u32);
	// lwz r11,108(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// rlwinm r11,r11,0,22,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
loc_8241AD90:
	// stw r11,108(r30)
	PPC_STORE_U32(r30.u32 + 108, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r29,120(r30)
	PPC_STORE_U32(r30.u32 + 120, r29.u32);
	// clrlwi. r10,r26,30
	ctx.r10.u64 = r26.u32 & 0x3;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r11,r11,0,21,18
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFE7FF;
	// stw r11,108(r30)
	PPC_STORE_U32(r30.u32 + 108, r11.u32);
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r11,r11,0,29,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFC7;
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// beq 0x8241aea4
	if (cr0.eq) goto loc_8241AEA4;
	// rlwinm. r11,r26,0,30,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,108(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// beq 0x8241ade0
	if (cr0.eq) goto loc_8241ADE0;
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// stw r11,108(r30)
	PPC_STORE_U32(r30.u32 + 108, r11.u32);
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// b 0x8241adf4
	goto loc_8241ADF4;
loc_8241ADE0:
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,108(r30)
	PPC_STORE_U32(r30.u32 + 108, r11.u32);
	// addi r3,r31,13248
	ctx.r3.s64 = r31.s64 + 13248;
	// bl 0x82412568
	ctx.lr = 0x8241ADF4;
	sub_82412568(ctx, base);
loc_8241ADF4:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r25,12748(r31)
	PPC_STORE_U32(r31.u32 + 12748, r25.u32);
	// ori r11,r11,48
	r11.u64 = r11.u64 | 48;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// beq cr6,0x8241ae90
	if (cr6.eq) goto loc_8241AE90;
	// addi r9,r31,12996
	ctx.r9.s64 = r31.s64 + 12996;
	// addi r11,r23,12
	r11.s64 = r23.s64 + 12;
	// addi r10,r31,12756
	ctx.r10.s64 = r31.s64 + 12756;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
loc_8241AE24:
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmplw cr6,r5,r7
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, xer);
	// bgt cr6,0x8241ae34
	if (cr6.gt) goto loc_8241AE34;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
loc_8241AE34:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// bgt cr6,0x8241ae44
	if (cr6.gt) goto loc_8241AE44;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
loc_8241AE44:
	// lwz r7,-12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r7,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r7.u32);
	// lwz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lwz r7,-12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// rlwinm r7,r7,0,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r7,-4(r9)
	PPC_STORE_U32(ctx.r9.u32 + -4, ctx.r7.u32);
	// lwz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// rlwinm r7,r7,0,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// bne 0x8241ae24
	if (!cr0.eq) goto loc_8241AE24;
loc_8241AE90:
	// li r11,2
	r11.s64 = 2;
	// stw r5,13180(r31)
	PPC_STORE_U32(r31.u32 + 13180, ctx.r5.u32);
	// stw r6,13184(r31)
	PPC_STORE_U32(r31.u32 + 13184, ctx.r6.u32);
	// stw r29,13188(r31)
	PPC_STORE_U32(r31.u32 + 13188, r29.u32);
	// stw r11,12720(r31)
	PPC_STORE_U32(r31.u32 + 12720, r11.u32);
loc_8241AEA4:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// stw r29,12716(r31)
	PPC_STORE_U32(r31.u32 + 12716, r29.u32);
	// rlwinm. r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241af80
	if (!cr0.eq) goto loc_8241AF80;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241af80
	if (!cr0.eq) goto loc_8241AF80;
	// lbz r11,12187(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8241af80
	if (!cr0.eq) goto loc_8241AF80;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241aee0
	if (cr0.eq) goto loc_8241AEE0;
	// li r11,1
	r11.s64 = 1;
	// b 0x8241af74
	goto loc_8241AF74;
loc_8241AEE0:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241af6c
	if (cr0.eq) goto loc_8241AF6C;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241af04
	if (cr6.eq) goto loc_8241AF04;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241af6c
	if (!cr6.eq) goto loc_8241AF6C;
loc_8241AF04:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241af1c
	if (cr6.eq) goto loc_8241AF1C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241af6c
	if (!cr6.eq) goto loc_8241AF6C;
loc_8241AF1C:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241af34
	if (cr6.eq) goto loc_8241AF34;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241af6c
	if (!cr6.eq) goto loc_8241AF6C;
loc_8241AF34:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241af4c
	if (cr6.eq) goto loc_8241AF4C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241af6c
	if (!cr6.eq) goto loc_8241AF6C;
loc_8241AF4C:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241af64
	if (cr6.eq) goto loc_8241AF64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241af6c
	if (!cr6.eq) goto loc_8241AF6C;
loc_8241AF64:
	// li r11,1
	r11.s64 = 1;
	// b 0x8241af70
	goto loc_8241AF70;
loc_8241AF6C:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8241AF70:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8241AF74:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne 0x8241af84
	if (!cr0.eq) goto loc_8241AF84;
loc_8241AF80:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8241AF84:
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// li r5,768
	ctx.r5.s64 = 768;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r28,12708(r31)
	PPC_STORE_U32(r31.u32 + 12708, r28.u32);
	// rlwimi r11,r10,0,24,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFE) | (r11.u64 & 0xFFFFFFFFFFFFFF01);
	// stw r29,12712(r31)
	PPC_STORE_U32(r31.u32 + 12712, r29.u32);
	// addi r3,r31,1152
	ctx.r3.s64 = r31.s64 + 1152;
	// stw r29,10932(r31)
	PPC_STORE_U32(r31.u32 + 10932, r29.u32);
	// stw r29,10936(r31)
	PPC_STORE_U32(r31.u32 + 10936, r29.u32);
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// bl 0x823d9890
	ctx.lr = 0x8241AFB0;
	sub_823D9890(ctx, base);
	// li r12,7
	r12.s64 = 7;
	// ld r10,32(r24)
	ctx.r10.u64 = PPC_LOAD_U64(r24.u32 + 32);
	// li r11,7
	r11.s64 = 7;
	// rldicr r12,r12,46,17
	r12.u64 = __builtin_rotateleft64(r12.u64, 46) & 0xFFFFC00000000000;
	// rldicr r11,r11,46,17
	r11.u64 = __builtin_rotateleft64(r11.u64, 46) & 0xFFFFC00000000000;
	// and r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 & r12.u64;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// beq cr6,0x8241b000
	if (cr6.eq) goto loc_8241B000;
	// lwz r11,10440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10440);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10436);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,17,0,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r7,r9,17
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 17;
	// rlwinm r10,r10,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0xFFFE0000;
	// srawi r6,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	ctx.r6.s64 = r11.s32 >> 17;
	// srawi r5,r8,17
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 17;
	// srawi r4,r10,17
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 17;
	// bl 0x82413660
	ctx.lr = 0x8241B000;
	sub_82413660(ctx, base);
loc_8241B000:
	// ld r11,0(r24)
	r11.u64 = PPC_LOAD_U64(r24.u32 + 0);
	// not r11,r11
	r11.u64 = ~r11.u64;
	// std r11,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r11.u64);
	// ld r11,8(r24)
	r11.u64 = PPC_LOAD_U64(r24.u32 + 8);
	// not r11,r11
	r11.u64 = ~r11.u64;
	// std r11,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r11.u64);
	// ld r11,16(r24)
	r11.u64 = PPC_LOAD_U64(r24.u32 + 16);
	// not r11,r11
	r11.u64 = ~r11.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ld r11,24(r24)
	r11.u64 = PPC_LOAD_U64(r24.u32 + 24);
	// not r11,r11
	r11.u64 = ~r11.u64;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
	// ld r11,32(r24)
	r11.u64 = PPC_LOAD_U64(r24.u32 + 32);
	// not r11,r11
	r11.u64 = ~r11.u64;
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8241B044"))) PPC_WEAK_FUNC(sub_8241B044);
PPC_FUNC_IMPL(__imp__sub_8241B044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241B048"))) PPC_WEAK_FUNC(sub_8241B048);
PPC_FUNC_IMPL(__imp__sub_8241B048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r8,13232(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 13232);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8241b0ec
	if (cr6.eq) goto loc_8241B0EC;
	// lwz r9,14904(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 14904);
	// lwz r10,14908(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 14908);
	// lbz r7,10941(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 10941);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rlwinm. r9,r7,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// srawi r10,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// beq 0x8241b0b0
	if (cr0.eq) goto loc_8241B0B0;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8241b154
	goto loc_8241B154;
loc_8241B0B0:
	// lwz r10,14920(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 14920);
	// lwz r9,13236(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 13236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8241b0d8
	if (!cr6.eq) goto loc_8241B0D8;
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r10,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r10.s64;
	// b 0x8241b154
	goto loc_8241B154;
loc_8241B0D8:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r9,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r9.s64;
	// b 0x8241b154
	goto loc_8241B154;
loc_8241B0EC:
	// lbz r8,10940(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 10940);
	// rlwinm. r8,r8,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8241b154
	if (cr0.eq) goto loc_8241B154;
	// lwz r3,13516(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 13516);
	// lwz r10,152(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8241b120
	if (!cr6.eq) goto loc_8241B120;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x8241a870
	ctx.lr = 0x8241B114;
	sub_8241A870(ctx, base);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8241b154
	goto loc_8241B154;
loc_8241B120:
	// lbz r10,10941(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10941);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8241b134
	if (cr0.eq) goto loc_8241B134;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8241b148
	goto loc_8241B148;
loc_8241B134:
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_8241B148:
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r11,156(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
loc_8241B154:
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8241B174"))) PPC_WEAK_FUNC(sub_8241B174);
PPC_FUNC_IMPL(__imp__sub_8241B174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241B178"))) PPC_WEAK_FUNC(sub_8241B178);
PPC_FUNC_IMPL(__imp__sub_8241B178) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lwz r11,13516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13516);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// ori r10,r10,64
	ctx.r10.u64 = ctx.r10.u64 | 64;
	// stw r10,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r10.u32);
	// bne cr6,0x8241b298
	if (!cr6.eq) goto loc_8241B298;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8241b298
	if (!cr6.eq) goto loc_8241B298;
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm. r11,r10,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r9,12716(r31)
	PPC_STORE_U32(r31.u32 + 12716, ctx.r9.u32);
	// bne 0x8241b280
	if (!cr0.eq) goto loc_8241B280;
	// rlwinm. r11,r10,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241b280
	if (!cr0.eq) goto loc_8241B280;
	// lbz r11,12187(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8241b280
	if (!cr0.eq) goto loc_8241B280;
	// rlwinm. r11,r10,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241b1e4
	if (cr0.eq) goto loc_8241B1E4;
	// li r11,1
	r11.s64 = 1;
	// b 0x8241b274
	goto loc_8241B274;
loc_8241B1E4:
	// rlwinm. r11,r10,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241b26c
	if (cr0.eq) goto loc_8241B26C;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r8,12728(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241b204
	if (cr6.eq) goto loc_8241B204;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241b26c
	if (!cr6.eq) goto loc_8241B26C;
loc_8241B204:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r8,12732(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241b21c
	if (cr6.eq) goto loc_8241B21C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241b26c
	if (!cr6.eq) goto loc_8241B26C;
loc_8241B21C:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r8,12736(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241b234
	if (cr6.eq) goto loc_8241B234;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241b26c
	if (!cr6.eq) goto loc_8241B26C;
loc_8241B234:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r8,12740(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241b24c
	if (cr6.eq) goto loc_8241B24C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241b26c
	if (!cr6.eq) goto loc_8241B26C;
loc_8241B24C:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r8,12744(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241b264
	if (cr6.eq) goto loc_8241B264;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241b26c
	if (!cr6.eq) goto loc_8241B26C;
loc_8241B264:
	// li r11,1
	r11.s64 = 1;
	// b 0x8241b270
	goto loc_8241B270;
loc_8241B26C:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8241B270:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8241B274:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne 0x8241b284
	if (!cr0.eq) goto loc_8241B284;
loc_8241B280:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8241B284:
	// rlwimi r11,r10,0,24,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFE) | (r11.u64 & 0xFFFFFFFFFFFFFF01);
	// stw r9,12712(r31)
	PPC_STORE_U32(r31.u32 + 12712, ctx.r9.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,12708(r31)
	PPC_STORE_U32(r31.u32 + 12708, ctx.r10.u32);
	// b 0x8241b2b0
	goto loc_8241B2B0;
loc_8241B298:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,12708(r31)
	PPC_STORE_U32(r31.u32 + 12708, ctx.r4.u32);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,12716(r31)
	PPC_STORE_U32(r31.u32 + 12716, ctx.r10.u32);
	// stw r5,12712(r31)
	PPC_STORE_U32(r31.u32 + 12712, ctx.r5.u32);
loc_8241B2B0:
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stw r4,10932(r31)
	PPC_STORE_U32(r31.u32 + 10932, ctx.r4.u32);
	// stw r5,10936(r31)
	PPC_STORE_U32(r31.u32 + 10936, ctx.r5.u32);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241b2d4
	if (!cr6.gt) goto loc_8241B2D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241B2D4;
	sub_82412710(ctx, base);
loc_8241B2D4:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// ori r11,r11,24576
	r11.u64 = r11.u64 | 24576;
	// ori r10,r10,24832
	ctx.r10.u64 = ctx.r10.u64 | 24832;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12708);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12712(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12712);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8241B314"))) PPC_WEAK_FUNC(sub_8241B314);
PPC_FUNC_IMPL(__imp__sub_8241B314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241B318"))) PPC_WEAK_FUNC(sub_8241B318);
PPC_FUNC_IMPL(__imp__sub_8241B318) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8241B320;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// lwz r26,13516(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 13516);
	// lwz r11,108(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 108);
	// rlwinm. r11,r11,0,16,16
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241b554
	if (cr0.eq) goto loc_8241B554;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// ld r27,32(r31)
	r27.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// ld r28,24(r31)
	r28.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// ld r30,16(r31)
	r30.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r29,8(r31)
	r29.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// beq cr6,0x8241b368
	if (cr6.eq) goto loc_8241B368;
	// addi r6,r31,1920
	ctx.r6.s64 = r31.s64 + 1920;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// bl 0x824238e0
	ctx.lr = 0x8241B364;
	sub_824238E0(ctx, base);
	// std r25,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r25.u64);
loc_8241B368:
	// cmpldi cr6,r29,0
	cr6.compare<uint64_t>(r29.u64, 0, xer);
	// beq cr6,0x8241b388
	if (cr6.eq) goto loc_8241B388;
	// addi r6,r31,6016
	ctx.r6.s64 = r31.s64 + 6016;
	// li r5,17408
	ctx.r5.s64 = 17408;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824238e0
	ctx.lr = 0x8241B384;
	sub_824238E0(ctx, base);
	// std r25,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r25.u64);
loc_8241B388:
	// cmpldi cr6,r30,0
	cr6.compare<uint64_t>(r30.u64, 0, xer);
	// beq cr6,0x8241b468
	if (cr6.eq) goto loc_8241B468;
	// rlwinm r11,r30,0,11,14
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1E0000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b3ac
	if (cr6.eq) goto loc_8241B3AC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82424670
	ctx.lr = 0x8241B3A8;
	sub_82424670(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241B3AC:
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// and r11,r11,r30
	r11.u64 = r11.u64 & r30.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b3d0
	if (cr6.eq) goto loc_8241B3D0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,10560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824231b0
	ctx.lr = 0x8241B3CC;
	sub_824231B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241B3D0:
	// clrldi r11,r30,52
	r11.u64 = r30.u64 & 0xFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b3f0
	if (cr6.eq) goto loc_8241B3F0;
	// addi r6,r31,10548
	ctx.r6.s64 = r31.s64 + 10548;
	// li r5,8704
	ctx.r5.s64 = 8704;
	// rldicr r4,r30,52,11
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 52) & 0xFFF0000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B3F0;
	sub_82423548(ctx, base);
loc_8241B3F0:
	// rlwinm r11,r30,0,15,19
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b410
	if (cr6.eq) goto loc_8241B410;
	// addi r6,r31,10528
	ctx.r6.s64 = r31.s64 + 10528;
	// li r5,8576
	ctx.r5.s64 = 8576;
	// rldicr r4,r30,47,4
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 47) & 0xF800000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B410;
	sub_82423548(ctx, base);
loc_8241B410:
	// lis r12,0
	r12.s64 = 0;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,42,21
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFC0000000000;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b43c
	if (cr6.eq) goto loc_8241B43C;
	// addi r6,r31,10368
	ctx.r6.s64 = r31.s64 + 10368;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// rldicr r4,r30,6,15
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 6) & 0xFFFF000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B43C;
	sub_82423548(ctx, base);
loc_8241B43C:
	// lis r12,-32
	r12.s64 = -2097152;
	// clrldi r12,r12,22
	r12.u64 = r12.u64 & 0x3FFFFFFFFFF;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b464
	if (cr6.eq) goto loc_8241B464;
	// addi r6,r31,10444
	ctx.r6.s64 = r31.s64 + 10444;
	// li r5,8448
	ctx.r5.s64 = 8448;
	// rldicr r4,r30,22,20
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 22) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B464;
	sub_82423548(ctx, base);
loc_8241B464:
	// std r25,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r25.u64);
loc_8241B468:
	// cmpldi cr6,r28,0
	cr6.compare<uint64_t>(r28.u64, 0, xer);
	// beq cr6,0x8241b4b8
	if (cr6.eq) goto loc_8241B4B8;
	// clrldi r11,r28,32
	r11.u64 = r28.u64 & 0xFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b488
	if (cr6.eq) goto loc_8241B488;
	// rldicr r4,r28,32,31
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 32) & 0xFFFFFFFF00000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423788
	ctx.lr = 0x8241B488;
	sub_82423788(ctx, base);
loc_8241B488:
	// lis r12,31
	r12.s64 = 2031616;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,34,29
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFC00000000;
	// and r11,r28,r12
	r11.u64 = r28.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b4b4
	if (cr6.eq) goto loc_8241B4B4;
	// addi r6,r31,10596
	ctx.r6.s64 = r31.s64 + 10596;
	// li r5,8832
	ctx.r5.s64 = 8832;
	// rldicr r4,r28,9,20
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 9) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B4B4;
	sub_82423548(ctx, base);
loc_8241B4B4:
	// std r25,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r25.u64);
loc_8241B4B8:
	// cmpldi cr6,r27,0
	cr6.compare<uint64_t>(r27.u64, 0, xer);
	// beq cr6,0x8241b554
	if (cr6.eq) goto loc_8241B554;
	// clrldi r11,r27,26
	r11.u64 = r27.u64 & 0x3FFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b4e0
	if (cr6.eq) goto loc_8241B4E0;
	// addi r6,r31,10680
	ctx.r6.s64 = r31.s64 + 10680;
	// li r5,8960
	ctx.r5.s64 = 8960;
	// rldicr r4,r27,26,37
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 26) & 0xFFFFFFFFFC000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B4E0;
	sub_82423548(ctx, base);
loc_8241B4E0:
	// li r12,255
	r12.s64 = 255;
	// rldicr r12,r12,38,25
	r12.u64 = __builtin_rotateleft64(r12.u64, 38) & 0xFFFFFFC000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b508
	if (cr6.eq) goto loc_8241B508;
	// addi r6,r31,10832
	ctx.r6.s64 = r31.s64 + 10832;
	// li r5,9088
	ctx.r5.s64 = 9088;
	// rldicr r4,r27,18,7
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 18) & 0xFF00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B508;
	sub_82423548(ctx, base);
loc_8241B508:
	// li r12,63
	r12.s64 = 63;
	// rldicr r12,r12,49,14
	r12.u64 = __builtin_rotateleft64(r12.u64, 49) & 0xFFFE000000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b528
	if (cr6.eq) goto loc_8241B528;
	// rldicr r4,r27,9,5
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 9) & 0xFC00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423608
	ctx.lr = 0x8241B528;
	sub_82423608(ctx, base);
loc_8241B528:
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b550
	if (cr6.eq) goto loc_8241B550;
	// addi r6,r31,10112
	ctx.r6.s64 = r31.s64 + 10112;
	// li r5,18688
	ctx.r5.s64 = 18688;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B550;
	sub_82423548(ctx, base);
loc_8241B550:
	// std r25,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r25.u64);
loc_8241B554:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824133d0
	ctx.lr = 0x8241B55C;
	sub_824133D0(ctx, base);
	// lwz r11,152(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241b5dc
	if (cr6.eq) goto loc_8241B5DC;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// lwz r9,14928(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 14928);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// srawi r29,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r29.s64 = r11.s32 >> 2;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241b594
	if (!cr6.gt) goto loc_8241B594;
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
loc_8241B594:
	// lwz r11,13540(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13540);
	// lwz r3,13536(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13536);
	// lwz r30,152(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 152);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x8241b5b0
	if (cr6.lt) goto loc_8241B5B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a6e0
	ctx.lr = 0x8241B5B0;
	sub_8241A6E0(ctx, base);
loc_8241B5B0:
	// rlwinm r11,r30,12,20,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r30,3
	ctx.r10.u64 = r30.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// oris r9,r29,33024
	ctx.r9.u64 = r29.u64 | 2164260864;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// addi r8,r3,8
	ctx.r8.s64 = ctx.r3.s64 + 8;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r8,13536(r31)
	PPC_STORE_U32(r31.u32 + 13536, ctx.r8.u32);
	// b 0x8241b5e4
	goto loc_8241B5E4;
loc_8241B5DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412588
	ctx.lr = 0x8241B5E4;
	sub_82412588(ctx, base);
loc_8241B5E4:
	// lwz r11,13520(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13520);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241b604
	if (cr6.eq) goto loc_8241B604;
	// lwz r10,13524(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13524);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// srawi r10,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 3;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8241B604:
	// lwz r11,13532(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13532);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241b624
	if (cr6.eq) goto loc_8241B624;
	// lwz r10,13536(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13536);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// srawi r10,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 3;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8241B624:
	// lwz r11,108(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 108);
	// lis r30,16384
	r30.s64 = 1073741824;
	// rlwinm. r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241b66c
	if (cr0.eq) goto loc_8241B66C;
	// addi r3,r31,13248
	ctx.r3.s64 = r31.s64 + 13248;
	// bl 0x82411530
	ctx.lr = 0x8241B63C;
	sub_82411530(ctx, base);
	// lwz r11,13248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241b650
	if (!cr6.eq) goto loc_8241B650;
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x8241b668
	goto loc_8241B668;
loc_8241B650:
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
loc_8241B668:
	// stw r11,120(r26)
	PPC_STORE_U32(r26.u32 + 120, r11.u32);
loc_8241B66C:
	// stw r25,13516(r31)
	PPC_STORE_U32(r31.u32 + 13516, r25.u32);
	// sync 
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,136(r26)
	PPC_STORE_U32(r26.u32 + 136, r11.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r11,r9,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// stw r10,140(r26)
	PPC_STORE_U32(r26.u32 + 140, ctx.r10.u32);
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// clrlwi r10,r9,3
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// stw r11,144(r26)
	PPC_STORE_U32(r26.u32 + 144, r11.u32);
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,108(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 108);
	// beq 0x8241b6c8
	if (cr0.eq) goto loc_8241B6C8;
	// lis r30,-32761
	r30.s64 = -2147024896;
	// li r10,7
	ctx.r10.s64 = 7;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x8241b6d0
	goto loc_8241B6D0;
loc_8241B6C8:
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_8241B6D0:
	// rlwimi r11,r10,0,28,31
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xF) | (r11.u64 & 0xFFFFFFFFFFFFFFF0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,108(r26)
	PPC_STORE_U32(r26.u32 + 108, r11.u32);
	// bl 0x82411618
	ctx.lr = 0x8241B6E0;
	sub_82411618(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8241B6EC"))) PPC_WEAK_FUNC(sub_8241B6EC);
PPC_FUNC_IMPL(__imp__sub_8241B6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241B6F0"))) PPC_WEAK_FUNC(sub_8241B6F0);
PPC_FUNC_IMPL(__imp__sub_8241B6F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91d0
	ctx.lr = 0x8241B6F8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r18,r5
	r18.u64 = ctx.r5.u64;
	// li r20,0
	r20.s64 = 0;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// ld r11,24(r24)
	r11.u64 = PPC_LOAD_U64(r24.u32 + 24);
	// ld r9,56(r24)
	ctx.r9.u64 = PPC_LOAD_U64(r24.u32 + 56);
	// and r4,r11,r10
	ctx.r4.u64 = r11.u64 & ctx.r10.u64;
	// ld r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// ld r8,48(r24)
	ctx.r8.u64 = PPC_LOAD_U64(r24.u32 + 48);
	// and r27,r9,r10
	r27.u64 = ctx.r9.u64 & ctx.r10.u64;
	// ld r11,40(r24)
	r11.u64 = PPC_LOAD_U64(r24.u32 + 40);
	// ld r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// ld r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r10,32(r24)
	ctx.r10.u64 = PPC_LOAD_U64(r24.u32 + 32);
	// and r28,r8,r7
	r28.u64 = ctx.r8.u64 & ctx.r7.u64;
	// ld r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// and r30,r11,r6
	r30.u64 = r11.u64 & ctx.r6.u64;
	// lwz r19,13516(r31)
	r19.u64 = PPC_LOAD_U32(r31.u32 + 13516);
	// and r29,r10,r9
	r29.u64 = ctx.r10.u64 & ctx.r9.u64;
	// beq cr6,0x8241b764
	if (cr6.eq) goto loc_8241B764;
	// addi r6,r31,1920
	ctx.r6.s64 = r31.s64 + 1920;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// bl 0x824238e0
	ctx.lr = 0x8241B760;
	sub_824238E0(ctx, base);
	// std r20,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r20.u64);
loc_8241B764:
	// cmpldi cr6,r29,0
	cr6.compare<uint64_t>(r29.u64, 0, xer);
	// beq cr6,0x8241b784
	if (cr6.eq) goto loc_8241B784;
	// addi r6,r31,6016
	ctx.r6.s64 = r31.s64 + 6016;
	// li r5,17408
	ctx.r5.s64 = 17408;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824238e0
	ctx.lr = 0x8241B780;
	sub_824238E0(ctx, base);
	// std r20,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r20.u64);
loc_8241B784:
	// cmpldi cr6,r30,0
	cr6.compare<uint64_t>(r30.u64, 0, xer);
	// beq cr6,0x8241b864
	if (cr6.eq) goto loc_8241B864;
	// rlwinm r11,r30,0,11,14
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1E0000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b7a8
	if (cr6.eq) goto loc_8241B7A8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82424670
	ctx.lr = 0x8241B7A4;
	sub_82424670(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241B7A8:
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// and r11,r11,r30
	r11.u64 = r11.u64 & r30.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b7cc
	if (cr6.eq) goto loc_8241B7CC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,10560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824231b0
	ctx.lr = 0x8241B7C8;
	sub_824231B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241B7CC:
	// clrldi r11,r30,52
	r11.u64 = r30.u64 & 0xFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b7ec
	if (cr6.eq) goto loc_8241B7EC;
	// addi r6,r31,10548
	ctx.r6.s64 = r31.s64 + 10548;
	// li r5,8704
	ctx.r5.s64 = 8704;
	// rldicr r4,r30,52,11
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 52) & 0xFFF0000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B7EC;
	sub_82423548(ctx, base);
loc_8241B7EC:
	// rlwinm r11,r30,0,15,19
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b80c
	if (cr6.eq) goto loc_8241B80C;
	// addi r6,r31,10528
	ctx.r6.s64 = r31.s64 + 10528;
	// li r5,8576
	ctx.r5.s64 = 8576;
	// rldicr r4,r30,47,4
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 47) & 0xF800000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B80C;
	sub_82423548(ctx, base);
loc_8241B80C:
	// lis r12,0
	r12.s64 = 0;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,42,21
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFC0000000000;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b838
	if (cr6.eq) goto loc_8241B838;
	// addi r6,r31,10368
	ctx.r6.s64 = r31.s64 + 10368;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// rldicr r4,r30,6,15
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 6) & 0xFFFF000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B838;
	sub_82423548(ctx, base);
loc_8241B838:
	// lis r12,-32
	r12.s64 = -2097152;
	// clrldi r12,r12,22
	r12.u64 = r12.u64 & 0x3FFFFFFFFFF;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b860
	if (cr6.eq) goto loc_8241B860;
	// addi r6,r31,10444
	ctx.r6.s64 = r31.s64 + 10444;
	// li r5,8448
	ctx.r5.s64 = 8448;
	// rldicr r4,r30,22,20
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 22) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B860;
	sub_82423548(ctx, base);
loc_8241B860:
	// std r20,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r20.u64);
loc_8241B864:
	// cmpldi cr6,r28,0
	cr6.compare<uint64_t>(r28.u64, 0, xer);
	// beq cr6,0x8241b8b4
	if (cr6.eq) goto loc_8241B8B4;
	// clrldi r11,r28,32
	r11.u64 = r28.u64 & 0xFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b884
	if (cr6.eq) goto loc_8241B884;
	// rldicr r4,r28,32,31
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 32) & 0xFFFFFFFF00000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423788
	ctx.lr = 0x8241B884;
	sub_82423788(ctx, base);
loc_8241B884:
	// lis r12,31
	r12.s64 = 2031616;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,34,29
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFC00000000;
	// and r11,r28,r12
	r11.u64 = r28.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b8b0
	if (cr6.eq) goto loc_8241B8B0;
	// addi r6,r31,10596
	ctx.r6.s64 = r31.s64 + 10596;
	// li r5,8832
	ctx.r5.s64 = 8832;
	// rldicr r4,r28,9,20
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 9) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B8B0;
	sub_82423548(ctx, base);
loc_8241B8B0:
	// std r20,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r20.u64);
loc_8241B8B4:
	// cmpldi cr6,r27,0
	cr6.compare<uint64_t>(r27.u64, 0, xer);
	// beq cr6,0x8241b950
	if (cr6.eq) goto loc_8241B950;
	// clrldi r11,r27,26
	r11.u64 = r27.u64 & 0x3FFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b8dc
	if (cr6.eq) goto loc_8241B8DC;
	// addi r6,r31,10680
	ctx.r6.s64 = r31.s64 + 10680;
	// li r5,8960
	ctx.r5.s64 = 8960;
	// rldicr r4,r27,26,37
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 26) & 0xFFFFFFFFFC000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B8DC;
	sub_82423548(ctx, base);
loc_8241B8DC:
	// li r12,255
	r12.s64 = 255;
	// rldicr r12,r12,38,25
	r12.u64 = __builtin_rotateleft64(r12.u64, 38) & 0xFFFFFFC000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b904
	if (cr6.eq) goto loc_8241B904;
	// addi r6,r31,10832
	ctx.r6.s64 = r31.s64 + 10832;
	// li r5,9088
	ctx.r5.s64 = 9088;
	// rldicr r4,r27,18,7
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 18) & 0xFF00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B904;
	sub_82423548(ctx, base);
loc_8241B904:
	// li r12,63
	r12.s64 = 63;
	// rldicr r12,r12,49,14
	r12.u64 = __builtin_rotateleft64(r12.u64, 49) & 0xFFFE000000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b924
	if (cr6.eq) goto loc_8241B924;
	// rldicr r4,r27,9,5
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 9) & 0xFC00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423608
	ctx.lr = 0x8241B924;
	sub_82423608(ctx, base);
loc_8241B924:
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241b94c
	if (cr6.eq) goto loc_8241B94C;
	// addi r6,r31,10112
	ctx.r6.s64 = r31.s64 + 10112;
	// li r5,18688
	ctx.r5.s64 = 18688;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241B94C;
	sub_82423548(ctx, base);
loc_8241B94C:
	// std r20,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r20.u64);
loc_8241B950:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241b968
	if (!cr6.gt) goto loc_8241B968;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241B968;
	sub_82412710(ctx, base);
loc_8241B968:
	// lwz r22,108(r24)
	r22.u64 = PPC_LOAD_U32(r24.u32 + 108);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r11,r22,25,0,6
	r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 25) & 0xFE000000;
	// srawi. r21,r11,31
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFFFFFF) != 0);
	r21.s64 = r11.s32 >> 31;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// beq 0x8241b99c
	if (cr0.eq) goto loc_8241B99C;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241b99c
	if (!cr0.eq) goto loc_8241B99C;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,25344
	r11.u64 = r11.u64 | 25344;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r18,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r18.u32);
	ctx.r3.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241B99C:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// lwz r27,12716(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 12716);
	// li r23,-1
	r23.s64 = -1;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ori r25,r10,24576
	r25.u64 = ctx.r10.u64 | 24576;
	// mr r26,r20
	r26.u64 = r20.u64;
	// beq 0x8241ba10
	if (cr0.eq) goto loc_8241BA10;
	// rlwinm. r11,r22,0,20,20
	r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241ba10
	if (cr0.eq) goto loc_8241BA10;
	// lwz r11,13256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13256);
	// addi r3,r31,13248
	ctx.r3.s64 = r31.s64 + 13248;
	// lwz r10,13260(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13260);
	// li r27,1
	r27.s64 = 1;
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241b9e8
	if (!cr6.gt) goto loc_8241B9E8;
	// bl 0x82412198
	ctx.lr = 0x8241B9E4;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241B9E8:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// stw r9,13256(r31)
	PPC_STORE_U32(r31.u32 + 13256, ctx.r9.u32);
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r26,r11
	r26.u64 = r11.u64;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// stwu r9,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r30.u32 = ea;
loc_8241BA10:
	// rlwinm. r11,r22,0,26,26
	r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241bb88
	if (cr0.eq) goto loc_8241BB88;
	// lwz r11,14928(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14928);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x8241ba34
	if (cr6.eq) goto loc_8241BA34;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241BA34;
	sub_82412710(ctx, base);
loc_8241BA34:
	// lwz r30,116(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 116);
loc_8241BA38:
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412488
	ctx.lr = 0x8241BA48;
	sub_82412488(ctx, base);
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8241ba38
	if (!cr6.eq) goto loc_8241BA38;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241ba70
	if (!cr6.gt) goto loc_8241BA70;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241BA6C;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241BA70:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8241bad8
	if (cr6.eq) goto loc_8241BAD8;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// lis r8,-32768
	ctx.r8.s64 = -2147483648;
	// addi r11,r26,4
	r11.s64 = r26.s64 + 4;
	// lis r7,-16383
	ctx.r7.s64 = -1073676288;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// ori r7,r7,23041
	ctx.r7.u64 = ctx.r7.u64 | 23041;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r11,r11,0,3,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1FFFFFFE;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// li r6,26
	ctx.r6.s64 = 26;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-16384
	ctx.r8.s64 = -1073741824;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// ori r10,r8,17921
	ctx.r10.u64 = ctx.r8.u64 | 17921;
	// stwu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r9.u32 = ea;
	// li r8,25
	ctx.r8.s64 = 25;
	// stwu r6,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r9.u32 = ea;
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r9.u32 = ea;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
loc_8241BAD8:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x8241bb00
	if (cr6.eq) goto loc_8241BB00;
	// stwu r25,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r25.u32);
	r11.u32 = ea;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// lwz r9,12708(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12708);
	// ori r10,r10,24832
	ctx.r10.u64 = ctx.r10.u64 | 24832;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lwz r10,12712(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12712);
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
loc_8241BB00:
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// rlwinm. r11,r10,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241bc08
	if (cr0.eq) goto loc_8241BC08;
	// lwz r11,108(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 108);
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// lwz r10,10912(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10912);
	// or r8,r22,r11
	ctx.r8.u64 = r22.u64 | r11.u64;
	// and. r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 & ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r8,25,0,6
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0xFE000000;
	// srawi r10,r9,25
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFFFF) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 25;
	// rlwimi r10,r11,0,26,24
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFFFFFFFFFFFBF) | (ctx.r10.u64 & 0x40);
	// stw r10,108(r19)
	PPC_STORE_U32(r19.u32 + 108, ctx.r10.u32);
	// bne 0x8241bb48
	if (!cr0.eq) goto loc_8241BB48;
	// lwz r11,112(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241bc74
	if (cr6.eq) goto loc_8241BC74;
loc_8241BB48:
	// lwz r11,13528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13528);
	// lwz r3,13524(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13524);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x8241bb60
	if (cr6.lt) goto loc_8241BB60;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a630
	ctx.lr = 0x8241BB60;
	sub_8241A630(ctx, base);
loc_8241BB60:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r23.u32);
	// rlwimi r11,r24,30,2,31
	r11.u64 = (__builtin_rotateleft32(r24.u32, 30) & 0x3FFFFFFF) | (r11.u64 & 0xFFFFFFFFC0000000);
	// rlwinm r11,r11,0,2,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// stw r10,13524(r31)
	PPC_STORE_U32(r31.u32 + 13524, ctx.r10.u32);
	// b 0x8241bc74
	goto loc_8241BC74;
loc_8241BB88:
	// oris r27,r27,49153
	r27.u64 = r27.u64 | 3221291008;
	// lwz r28,116(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 116);
	// mr r29,r20
	r29.u64 = r20.u64;
	// ori r27,r27,16128
	r27.u64 = r27.u64 | 16128;
loc_8241BB98:
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwu r27,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r27.u32);
	r30.u32 = ea;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r11,r11,8
	r11.u64 = r11.u32 & 0xFFFFFF;
	// stwu r10,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r30.u32 = ea;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r10.u32 = ea;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// bne cr6,0x8241bbe4
	if (!cr6.eq) goto loc_8241BBE4;
	// lwz r28,0(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r29,r20
	r29.u64 = r20.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8241ba70
	if (cr6.eq) goto loc_8241BA70;
loc_8241BBE4:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241bc00
	if (!cr6.gt) goto loc_8241BC00;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241BC00;
	sub_82412710(ctx, base);
loc_8241BC00:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8241bb98
	goto loc_8241BB98;
loc_8241BC08:
	// lwz r30,120(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 120);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8241bc58
	if (cr6.eq) goto loc_8241BC58;
	// rlwinm. r11,r10,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241bc58
	if (cr0.eq) goto loc_8241BC58;
	// lwz r11,8(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// lwz r10,10908(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8241bc58
	if (cr6.eq) goto loc_8241BC58;
	// lwz r11,13356(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13356);
	// addi r3,r31,13348
	ctx.r3.s64 = r31.s64 + 13348;
	// lwz r10,13360(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13360);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241bc4c
	if (!cr6.gt) goto loc_8241BC4C;
	// bl 0x82412198
	ctx.lr = 0x8241BC48;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241BC4C:
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r10,13356(r31)
	PPC_STORE_U32(r31.u32 + 13356, ctx.r10.u32);
loc_8241BC58:
	// lwz r3,10908(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// lwz r4,112(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 112);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r3,8(r24)
	PPC_STORE_U32(r24.u32 + 8, ctx.r3.u32);
	// beq cr6,0x8241bc74
	if (cr6.eq) goto loc_8241BC74;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// bl 0x8241a528
	ctx.lr = 0x8241BC74;
	sub_8241A528(ctx, base);
loc_8241BC74:
	// li r12,7
	r12.s64 = 7;
	// ld r30,96(r24)
	r30.u64 = PPC_LOAD_U64(r24.u32 + 96);
	// li r11,7
	r11.s64 = 7;
	// rldicr r12,r12,46,17
	r12.u64 = __builtin_rotateleft64(r12.u64, 46) & 0xFFFFC00000000000;
	// rldicr r11,r11,46,17
	r11.u64 = __builtin_rotateleft64(r11.u64, 46) & 0xFFFFC00000000000;
	// and r10,r30,r12
	ctx.r10.u64 = r30.u64 & r12.u64;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// beq cr6,0x8241bcc4
	if (cr6.eq) goto loc_8241BCC4;
	// lwz r11,10440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10440);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10436);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,17,0,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r7,r9,17
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 17;
	// rlwinm r10,r10,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0xFFFE0000;
	// srawi r6,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	ctx.r6.s64 = r11.s32 >> 17;
	// srawi r5,r8,17
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 17;
	// srawi r4,r10,17
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 17;
	// bl 0x82413660
	ctx.lr = 0x8241BCC4;
	sub_82413660(ctx, base);
loc_8241BCC4:
	// ld r11,64(r24)
	r11.u64 = PPC_LOAD_U64(r24.u32 + 64);
	// not r10,r30
	ctx.r10.u64 = ~r30.u64;
	// ld r9,72(r24)
	ctx.r9.u64 = PPC_LOAD_U64(r24.u32 + 72);
	// not r11,r11
	r11.u64 = ~r11.u64;
	// ld r8,80(r24)
	ctx.r8.u64 = PPC_LOAD_U64(r24.u32 + 80);
	// ld r7,88(r24)
	ctx.r7.u64 = PPC_LOAD_U64(r24.u32 + 88);
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// std r11,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r11.u64);
	// not r8,r8
	ctx.r8.u64 = ~ctx.r8.u64;
	// not r11,r7
	r11.u64 = ~ctx.r7.u64;
	// std r9,8(r31)
	PPC_STORE_U64(r31.u32 + 8, ctx.r9.u64);
	// std r8,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r8.u64);
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
	// std r10,32(r31)
	PPC_STORE_U64(r31.u32 + 32, ctx.r10.u64);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8241BD04"))) PPC_WEAK_FUNC(sub_8241BD04);
PPC_FUNC_IMPL(__imp__sub_8241BD04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241BD08"))) PPC_WEAK_FUNC(sub_8241BD08);
PPC_FUNC_IMPL(__imp__sub_8241BD08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// bne cr6,0x8241be0c
	if (!cr6.eq) goto loc_8241BE0C;
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// stw r9,12716(r31)
	PPC_STORE_U32(r31.u32 + 12716, ctx.r9.u32);
	// rlwinm. r11,r10,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241bdf8
	if (!cr0.eq) goto loc_8241BDF8;
	// rlwinm. r11,r10,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241bdf8
	if (!cr0.eq) goto loc_8241BDF8;
	// lbz r11,12187(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8241bdf8
	if (!cr0.eq) goto loc_8241BDF8;
	// rlwinm. r11,r10,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241bd5c
	if (cr0.eq) goto loc_8241BD5C;
	// li r11,1
	r11.s64 = 1;
	// b 0x8241bdec
	goto loc_8241BDEC;
loc_8241BD5C:
	// rlwinm. r11,r10,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241bde4
	if (cr0.eq) goto loc_8241BDE4;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r8,12728(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241bd7c
	if (cr6.eq) goto loc_8241BD7C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241bde4
	if (!cr6.eq) goto loc_8241BDE4;
loc_8241BD7C:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r8,12732(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241bd94
	if (cr6.eq) goto loc_8241BD94;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241bde4
	if (!cr6.eq) goto loc_8241BDE4;
loc_8241BD94:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r8,12736(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241bdac
	if (cr6.eq) goto loc_8241BDAC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241bde4
	if (!cr6.eq) goto loc_8241BDE4;
loc_8241BDAC:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r8,12740(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241bdc4
	if (cr6.eq) goto loc_8241BDC4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241bde4
	if (!cr6.eq) goto loc_8241BDE4;
loc_8241BDC4:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r8,12744(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x8241bddc
	if (cr6.eq) goto loc_8241BDDC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241bde4
	if (!cr6.eq) goto loc_8241BDE4;
loc_8241BDDC:
	// li r11,1
	r11.s64 = 1;
	// b 0x8241bde8
	goto loc_8241BDE8;
loc_8241BDE4:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8241BDE8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8241BDEC:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne 0x8241bdfc
	if (!cr0.eq) goto loc_8241BDFC;
loc_8241BDF8:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8241BDFC:
	// rlwimi r11,r10,0,24,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFE) | (r11.u64 & 0xFFFFFFFFFFFFFF01);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,12708(r31)
	PPC_STORE_U32(r31.u32 + 12708, ctx.r10.u32);
	// b 0x8241be20
	goto loc_8241BE20;
loc_8241BE0C:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,12708(r31)
	PPC_STORE_U32(r31.u32 + 12708, ctx.r4.u32);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,12716(r31)
	PPC_STORE_U32(r31.u32 + 12716, ctx.r10.u32);
loc_8241BE20:
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stw r9,12712(r31)
	PPC_STORE_U32(r31.u32 + 12712, ctx.r9.u32);
	// stw r4,10932(r31)
	PPC_STORE_U32(r31.u32 + 10932, ctx.r4.u32);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// stw r9,10936(r31)
	PPC_STORE_U32(r31.u32 + 10936, ctx.r9.u32);
	// ble cr6,0x8241be48
	if (!cr6.gt) goto loc_8241BE48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241BE48;
	sub_82412710(ctx, base);
loc_8241BE48:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,24576
	r11.u64 = r11.u64 | 24576;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12708);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8241BE74"))) PPC_WEAK_FUNC(sub_8241BE74);
PPC_FUNC_IMPL(__imp__sub_8241BE74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241BE78"))) PPC_WEAK_FUNC(sub_8241BE78);
PPC_FUNC_IMPL(__imp__sub_8241BE78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8241BE80;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// stw r27,12748(r31)
	PPC_STORE_U32(r31.u32 + 12748, r27.u32);
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// mr r29,r25
	r29.u64 = r25.u64;
	// mr r28,r25
	r28.u64 = r25.u64;
	// beq cr6,0x8241bf38
	if (cr6.eq) goto loc_8241BF38;
	// addi r9,r31,12996
	ctx.r9.s64 = r31.s64 + 12996;
	// addi r11,r22,12
	r11.s64 = r22.s64 + 12;
	// addi r10,r31,12756
	ctx.r10.s64 = r31.s64 + 12756;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_8241BECC:
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmplw cr6,r29,r7
	cr6.compare<uint32_t>(r29.u32, ctx.r7.u32, xer);
	// bgt cr6,0x8241bedc
	if (cr6.gt) goto loc_8241BEDC;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
loc_8241BEDC:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r28,r7
	cr6.compare<uint32_t>(r28.u32, ctx.r7.u32, xer);
	// bgt cr6,0x8241beec
	if (cr6.gt) goto loc_8241BEEC;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
loc_8241BEEC:
	// lwz r7,-12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r7,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r7.u32);
	// lwz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lwz r7,-12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// rlwinm r7,r7,0,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r7,-4(r9)
	PPC_STORE_U32(ctx.r9.u32 + -4, ctx.r7.u32);
	// lwz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// rlwinm r7,r7,0,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// bne 0x8241becc
	if (!cr0.eq) goto loc_8241BECC;
loc_8241BF38:
	// rlwinm. r11,r23,0,30,30
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241c060
	if (cr0.eq) goto loc_8241C060;
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// rlwinm. r10,r23,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// stb r11,10943(r31)
	PPC_STORE_U8(r31.u32 + 10943, r11.u8);
	// beq 0x8241bf5c
	if (cr0.eq) goto loc_8241BF5C;
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,10943(r31)
	PPC_STORE_U8(r31.u32 + 10943, r11.u8);
loc_8241BF5C:
	// lhz r11,10368(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10368);
	// clrlwi. r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241bf70
	if (!cr0.eq) goto loc_8241BF70;
	// li r3,16
	ctx.r3.s64 = 16;
	// b 0x8241bf7c
	goto loc_8241BF7C;
loc_8241BF70:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r3,8
	ctx.r3.s64 = 8;
	// bne cr6,0x8241bf88
	if (!cr6.eq) goto loc_8241BF88;
loc_8241BF7C:
	// li r10,32
	ctx.r10.s64 = 32;
	// li r30,80
	r30.s64 = 80;
	// b 0x8241bf90
	goto loc_8241BF90;
loc_8241BF88:
	// li r10,16
	ctx.r10.s64 = 16;
	// li r30,40
	r30.s64 = 40;
loc_8241BF90:
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// andc r5,r11,r9
	ctx.r5.u64 = r11.u64 & ~ctx.r9.u64;
	// twllei r10,0
	// divwu r4,r5,r10
	ctx.r4.u32 = ctx.r5.u32 / ctx.r10.u32;
	// beq cr6,0x8241bff0
	if (cr6.eq) goto loc_8241BFF0;
	// addi r8,r31,13112
	ctx.r8.s64 = r31.s64 + 13112;
	// addi r11,r31,12992
	r11.s64 = r31.s64 + 12992;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
loc_8241BFBC:
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// divwu r21,r7,r3
	r21.u32 = ctx.r7.u32 / ctx.r3.u32;
	// divwu r7,r6,r10
	ctx.r7.u32 = ctx.r6.u32 / ctx.r10.u32;
	// mullw r6,r21,r4
	ctx.r6.s64 = int64_t(r21.s32) * int64_t(ctx.r4.s32);
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// twllei r3,0
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// twllei r10,0
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8241bfbc
	if (!cr0.eq) goto loc_8241BFBC;
loc_8241BFF0:
	// lwz r10,10368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10368);
	// add r11,r30,r29
	r11.u64 = r30.u64 + r29.u64;
	// stw r5,13172(r31)
	PPC_STORE_U32(r31.u32 + 13172, ctx.r5.u32);
	// twllei r30,0
	// rlwimi r10,r5,18,0,13
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 18) & 0xFFFC0000) | (ctx.r10.u64 & 0xFFFFFFFF0003FFFF);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r10,10368(r31)
	PPC_STORE_U32(r31.u32 + 10368, ctx.r10.u32);
	// ld r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// divwu r11,r11,r30
	r11.u32 = r11.u32 / r30.u32;
	// ori r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 256;
	// mullw r11,r11,r30
	r11.s64 = int64_t(r11.s32) * int64_t(r30.s32);
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// lbz r10,10943(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// stw r11,13176(r31)
	PPC_STORE_U32(r31.u32 + 13176, r11.u32);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8241c054
	if (!cr0.eq) goto loc_8241C054;
	// lwz r11,11852(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11852);
	// lis r10,4
	ctx.r10.s64 = 262144;
	// rlwinm r11,r11,0,12,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xE0000;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8241c054
	if (!cr6.eq) goto loc_8241C054;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// li r12,-257
	r12.s64 = -257;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// b 0x8241c05c
	goto loc_8241C05C;
loc_8241C054:
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
loc_8241C05C:
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
loc_8241C060:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r29,13180(r31)
	PPC_STORE_U32(r31.u32 + 13180, r29.u32);
	// clrlwi. r10,r23,31
	ctx.r10.u64 = r23.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r28,13184(r31)
	PPC_STORE_U32(r31.u32 + 13184, r28.u32);
	// stw r23,13188(r31)
	PPC_STORE_U32(r31.u32 + 13188, r23.u32);
	// addi r30,r11,7048
	r30.s64 = r11.s64 + 7048;
	// bne 0x8241c178
	if (!cr0.eq) goto loc_8241C178;
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241c178
	if (!cr0.eq) goto loc_8241C178;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8241c0e4
	if (cr6.eq) goto loc_8241C0E4;
	// addi r10,r31,12764
	ctx.r10.s64 = r31.s64 + 12764;
	// addi r11,r31,12996
	r11.s64 = r31.s64 + 12996;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
loc_8241C0A4:
	// lwz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r8,r3,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r3.s64;
	// cmplw cr6,r7,r9
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8241c0c8
	if (cr6.gt) goto loc_8241C0C8;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
loc_8241C0C8:
	// cmplw cr6,r5,r8
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, xer);
	// bgt cr6,0x8241c0d4
	if (cr6.gt) goto loc_8241C0D4;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
loc_8241C0D4:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8241c0a4
	if (!cr0.eq) goto loc_8241C0A4;
loc_8241C0E4:
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// addi r4,r31,12648
	ctx.r4.s64 = r31.s64 + 12648;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// bl 0x823da950
	ctx.lr = 0x8241C104;
	sub_823DA950(ctx, base);
	// lwz r11,12676(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12676);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r9,12680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12680);
	// lwz r8,12684(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12684);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,12688(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12688);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// bl 0x82416540
	ctx.lr = 0x8241C134;
	sub_82416540(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,7072
	ctx.r4.s64 = r11.s64 + 7072;
	// bl 0x82415c80
	ctx.lr = 0x8241C144;
	sub_82415C80(ctx, base);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,63
	ctx.r4.s64 = 63;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824194c0
	ctx.lr = 0x8241C160;
	sub_824194C0(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824165c0
	ctx.lr = 0x8241C16C;
	sub_824165C0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82415c80
	ctx.lr = 0x8241C178;
	sub_82415C80(ctx, base);
loc_8241C178:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8241c190
	if (cr6.eq) goto loc_8241C190;
	// li r11,13200
	r11.s64 = 13200;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8241c198
	goto loc_8241C198;
loc_8241C190:
	// std r25,13200(r31)
	PPC_STORE_U64(r31.u32 + 13200, r25.u64);
	// std r25,13208(r31)
	PPC_STORE_U64(r31.u32 + 13208, r25.u64);
loc_8241C198:
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// stfs f31,13216(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 13216, temp.u32);
	// stw r24,13220(r31)
	PPC_STORE_U32(r31.u32 + 13220, r24.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// bne cr6,0x8241c1b4
	if (!cr6.eq) goto loc_8241C1B4;
	// lwz r10,12456(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12456);
loc_8241C1B4:
	// lbz r9,10940(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// li r8,2
	ctx.r8.s64 = 2;
	// lwz r7,12444(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r6,12448(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// ori r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 | 32;
	// lwz r5,12452(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r4,12456(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// rlwinm. r3,r9,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r10,12724(r31)
	PPC_STORE_U32(r31.u32 + 12724, ctx.r10.u32);
	// stw r11,12728(r31)
	PPC_STORE_U32(r31.u32 + 12728, r11.u32);
	// stw r7,12732(r31)
	PPC_STORE_U32(r31.u32 + 12732, ctx.r7.u32);
	// stw r6,12736(r31)
	PPC_STORE_U32(r31.u32 + 12736, ctx.r6.u32);
	// stw r5,12740(r31)
	PPC_STORE_U32(r31.u32 + 12740, ctx.r5.u32);
	// stw r4,12744(r31)
	PPC_STORE_U32(r31.u32 + 12744, ctx.r4.u32);
	// stw r8,12720(r31)
	PPC_STORE_U32(r31.u32 + 12720, ctx.r8.u32);
	// stb r9,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, ctx.r9.u8);
	// stw r25,12716(r31)
	PPC_STORE_U32(r31.u32 + 12716, r25.u32);
	// bne 0x8241c23c
	if (!cr0.eq) goto loc_8241C23C;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241c23c
	if (!cr0.eq) goto loc_8241C23C;
	// lbz r11,12187(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8241c23c
	if (!cr0.eq) goto loc_8241C23C;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241c228
	if (cr0.eq) goto loc_8241C228;
	// li r11,1
	r11.s64 = 1;
	// b 0x8241c230
	goto loc_8241C230;
loc_8241C228:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_8241C230:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne 0x8241c240
	if (!cr0.eq) goto loc_8241C240;
loc_8241C23C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8241C240:
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r25,12712(r31)
	PPC_STORE_U32(r31.u32 + 12712, r25.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwimi r11,r10,0,24,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFE) | (r11.u64 & 0xFFFFFFFFFFFFFF01);
	// stw r9,12708(r31)
	PPC_STORE_U32(r31.u32 + 12708, ctx.r9.u32);
	// stw r25,10932(r31)
	PPC_STORE_U32(r31.u32 + 10932, r25.u32);
	// stw r25,10936(r31)
	PPC_STORE_U32(r31.u32 + 10936, r25.u32);
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// bl 0x8242fd88
	ctx.lr = 0x8241C268;
	sub_8242FD88(ctx, base);
	// lwz r11,13376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13376);
	// lwz r9,13380(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 13380);
	// addi r3,r31,13368
	ctx.r3.s64 = r31.s64 + 13368;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x8241c288
	if (!cr6.gt) goto loc_8241C288;
	// bl 0x82412198
	ctx.lr = 0x8241C284;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241C288:
	// lis r10,-31232
	ctx.r10.s64 = -2046820352;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r9,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r9.u32);
	// ble cr6,0x8241c2b4
	if (!cr6.gt) goto loc_8241C2B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241C2B0;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241C2B4:
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// li r9,25
	ctx.r9.s64 = 25;
	// ori r10,r10,17920
	ctx.r10.u64 = ctx.r10.u64 | 17920;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x82429988
	ctx.lr = 0x8241C2E0;
	sub_82429988(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82416540
	ctx.lr = 0x8241C2EC;
	sub_82416540(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824161e0
	ctx.lr = 0x8241C2F8;
	sub_824161E0(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8241C304"))) PPC_WEAK_FUNC(sub_8241C304);
PPC_FUNC_IMPL(__imp__sub_8241C304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241C308"))) PPC_WEAK_FUNC(sub_8241C308);
PPC_FUNC_IMPL(__imp__sub_8241C308) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8241C310;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// li r22,0
	r22.s64 = 0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bne cr6,0x8241c354
	if (!cr6.eq) goto loc_8241C354;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8241c4b4
	if (cr6.eq) goto loc_8241C4B4;
	// addi r5,r31,12752
	ctx.r5.s64 = r31.s64 + 12752;
loc_8241C354:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8241c4b4
	if (cr6.eq) goto loc_8241C4B4;
	// lwz r11,12748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// mr r27,r22
	r27.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8241c4b4
	if (!cr6.gt) goto loc_8241C4B4;
	// mr r28,r22
	r28.u64 = r22.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_8241C374:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r6,12(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r11,12724(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12724);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r6,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r6.u32);
	// lwz r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// rlwinm r10,r10,14,18,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x3FFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8241c3c0
	if (!cr6.eq) goto loc_8241C3C0;
	// addi r10,r9,7
	ctx.r10.s64 = ctx.r9.s64 + 7;
	// rlwinm r10,r10,0,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
loc_8241C3C0:
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// rlwinm r11,r11,29,17,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x7FFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8241c3e4
	if (!cr6.eq) goto loc_8241C3E4;
	// addi r11,r10,7
	r11.s64 = ctx.r10.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
loc_8241C3E4:
	// li r11,3
	r11.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// slw r4,r11,r28
	ctx.r4.u64 = r28.u8 & 0x20 ? 0 : (r11.u32 << (r28.u8 & 0x3F));
	// bl 0x8241bd08
	ctx.lr = 0x8241C3F4;
	sub_8241BD08(ctx, base);
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// not r11,r11
	r11.u64 = ~r11.u64;
	// rlwinm r4,r11,28,30,30
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x2;
	// bl 0x82415110
	ctx.lr = 0x8241C408;
	sub_82415110(ctx, base);
	// lwz r11,12748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bge cr6,0x8241c470
	if (!cr6.lt) goto loc_8241C470;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241c42c
	if (cr6.eq) goto loc_8241C42C;
	// ori r4,r26,256
	ctx.r4.u64 = r26.u64 | 256;
loc_8241C42C:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241c43c
	if (cr6.eq) goto loc_8241C43C;
	// ori r4,r4,512
	ctx.r4.u64 = ctx.r4.u64 | 512;
loc_8241C43C:
	// lwz r11,13220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13220);
	// addi r10,r31,13200
	ctx.r10.s64 = r31.s64 + 13200;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f1,13216(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 13216);
	ctx.f1.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r22.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82420ba8
	ctx.lr = 0x8241C46C;
	sub_82420BA8(ctx, base);
	// b 0x8241c49c
	goto loc_8241C49C;
loc_8241C470:
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// stw r24,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r24.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r23,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r23.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82420ba8
	ctx.lr = 0x8241C49C;
	sub_82420BA8(ctx, base);
loc_8241C49C:
	// lwz r11,12748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8241c374
	if (cr6.lt) goto loc_8241C374;
loc_8241C4B4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241bd08
	ctx.lr = 0x8241C4C0;
	sub_8241BD08(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82415110
	ctx.lr = 0x8241C4CC;
	sub_82415110(ctx, base);
	// lwz r11,13188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13188);
	// lwz r9,11320(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 11320);
	// lis r10,256
	ctx.r10.s64 = 16777216;
	// rlwinm. r11,r11,0,2,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3F000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// slw r27,r10,r9
	r27.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// beq 0x8241c4e8
	if (cr0.eq) goto loc_8241C4E8;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_8241C4E8:
	// lwz r11,12748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8241c620
	if (cr6.eq) goto loc_8241C620;
	// lis r29,-32768
	r29.s64 = -2147483648;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8241bd08
	ctx.lr = 0x8241C504;
	sub_8241BD08(ctx, base);
	// lwz r11,13368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13368);
	// addi r30,r31,13368
	r30.s64 = r31.s64 + 13368;
	// lis r28,16384
	r28.s64 = 1073741824;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241c520
	if (!cr6.eq) goto loc_8241C520;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// b 0x8241c538
	goto loc_8241C538;
loc_8241C520:
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r6,r28,r11
	ctx.r6.s64 = r11.s64 - r28.s64;
loc_8241C538:
	// lis r11,-32189
	r11.s64 = -2109538304;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r5,r11,-768
	ctx.r5.s64 = r11.s64 + -768;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412a08
	ctx.lr = 0x8241C54C;
	sub_82412A08(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241bd08
	ctx.lr = 0x8241C558;
	sub_8241BD08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241C560;
	sub_82412710(ctx, base);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241c57c
	if (!cr6.gt) goto loc_8241C57C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82412198
	ctx.lr = 0x8241C57C;
	sub_82412198(ctx, base);
loc_8241C57C:
	// lis r11,-30720
	r11.s64 = -2013265920;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r10.u32);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r11,r3,12
	r11.s64 = ctx.r3.s64 + 12;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241c5ac
	if (!cr6.gt) goto loc_8241C5AC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82412198
	ctx.lr = 0x8241C5AC;
	sub_82412198(ctx, base);
loc_8241C5AC:
	// lis r11,-30464
	r11.s64 = -1996488704;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r11,13248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241c5c8
	if (!cr6.eq) goto loc_8241C5C8;
	// mr r11,r22
	r11.u64 = r22.u64;
	// b 0x8241c5e0
	goto loc_8241C5E0;
loc_8241C5C8:
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
loc_8241C5E0:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,13348(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13348);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241c5f8
	if (!cr6.eq) goto loc_8241C5F8;
	// mr r11,r22
	r11.u64 = r22.u64;
	// b 0x8241c610
	goto loc_8241C610;
loc_8241C5F8:
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
loc_8241C610:
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r10,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r10.u32);
	// b 0x8241c624
	goto loc_8241C624;
loc_8241C620:
	// bl 0x82412710
	ctx.lr = 0x8241C624;
	sub_82412710(ctx, base);
loc_8241C624:
	// lwz r11,13376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13376);
	// addi r3,r31,13368
	ctx.r3.s64 = r31.s64 + 13368;
	// lwz r10,13380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13380);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241c644
	if (!cr6.gt) goto loc_8241C644;
	// bl 0x82412198
	ctx.lr = 0x8241C640;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241C644:
	// lis r10,-30976
	ctx.r10.s64 = -2030043136;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// andi. r11,r11,207
	r11.u64 = r11.u64 & 207;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// stw r9,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r9.u32);
	// andi. r10,r10,223
	ctx.r10.u64 = ctx.r10.u64 & 223;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r22,12724(r31)
	PPC_STORE_U32(r31.u32 + 12724, r22.u32);
	// stw r22,12716(r31)
	PPC_STORE_U32(r31.u32 + 12716, r22.u32);
	// rlwinm. r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, ctx.r10.u8);
	// stb r11,10943(r31)
	PPC_STORE_U8(r31.u32 + 10943, r11.u8);
	// bne 0x8241c748
	if (!cr0.eq) goto loc_8241C748;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241c748
	if (!cr0.eq) goto loc_8241C748;
	// lbz r11,12187(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8241c748
	if (!cr0.eq) goto loc_8241C748;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241c6a8
	if (cr0.eq) goto loc_8241C6A8;
	// li r11,1
	r11.s64 = 1;
	// b 0x8241c73c
	goto loc_8241C73C;
loc_8241C6A8:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241c734
	if (cr0.eq) goto loc_8241C734;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241c6cc
	if (cr6.eq) goto loc_8241C6CC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241c734
	if (!cr6.eq) goto loc_8241C734;
loc_8241C6CC:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241c6e4
	if (cr6.eq) goto loc_8241C6E4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241c734
	if (!cr6.eq) goto loc_8241C734;
loc_8241C6E4:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241c6fc
	if (cr6.eq) goto loc_8241C6FC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241c734
	if (!cr6.eq) goto loc_8241C734;
loc_8241C6FC:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241c714
	if (cr6.eq) goto loc_8241C714;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241c734
	if (!cr6.eq) goto loc_8241C734;
loc_8241C714:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241c72c
	if (cr6.eq) goto loc_8241C72C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241c734
	if (!cr6.eq) goto loc_8241C734;
loc_8241C72C:
	// li r11,1
	r11.s64 = 1;
	// b 0x8241c738
	goto loc_8241C738;
loc_8241C734:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8241C738:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8241C73C:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne 0x8241c74c
	if (!cr0.eq) goto loc_8241C74C;
loc_8241C748:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8241C74C:
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r22,12712(r31)
	PPC_STORE_U32(r31.u32 + 12712, r22.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// rlwimi r11,r10,0,24,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFE) | (r11.u64 & 0xFFFFFFFFFFFFFF01);
	// stw r9,12708(r31)
	PPC_STORE_U32(r31.u32 + 12708, ctx.r9.u32);
	// stw r22,10932(r31)
	PPC_STORE_U32(r31.u32 + 10932, r22.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r22,10936(r31)
	PPC_STORE_U32(r31.u32 + 10936, r22.u32);
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// lwz r4,12748(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// bl 0x8242fef8
	ctx.lr = 0x8241C77C;
	sub_8242FEF8(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r11,7048
	ctx.r4.s64 = r11.s64 + 7048;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82416540
	ctx.lr = 0x8241C790;
	sub_82416540(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8241c7b0
	if (cr6.eq) goto loc_8241C7B0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824161e0
	ctx.lr = 0x8241C7A4;
	sub_824161E0(ctx, base);
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8241c7b4
	goto loc_8241C7B4;
loc_8241C7B0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8241C7B4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8241C7C0"))) PPC_WEAK_FUNC(sub_8241C7C0);
PPC_FUNC_IMPL(__imp__sub_8241C7C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x8241C7C8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241c7f0
	if (!cr0.eq) goto loc_8241C7F0;
	// li r11,1
	r11.s64 = 1;
	// stw r11,12720(r31)
	PPC_STORE_U32(r31.u32 + 12720, r11.u32);
	// bl 0x8242fd88
	ctx.lr = 0x8241C7EC;
	sub_8242FD88(ctx, base);
	// b 0x8241c7f4
	goto loc_8241C7F4;
loc_8241C7F0:
	// bl 0x82412710
	ctx.lr = 0x8241C7F4;
	sub_82412710(ctx, base);
loc_8241C7F4:
	// lwz r11,13376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13376);
	// addi r3,r31,13368
	ctx.r3.s64 = r31.s64 + 13368;
	// lwz r10,13380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13380);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241c814
	if (!cr6.gt) goto loc_8241C814;
	// bl 0x82412198
	ctx.lr = 0x8241C810;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241C814:
	// lis r10,-32000
	ctx.r10.s64 = -2097152000;
	// not r9,r30
	ctx.r9.u64 = ~r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lbz r6,10941(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// lwz r8,10548(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 10548);
	// lbz r7,10943(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// ori r10,r10,64
	ctx.r10.u64 = ctx.r10.u64 | 64;
	// rlwimi r6,r9,6,25,25
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r9.u32, 6) & 0x40) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r10,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, ctx.r10.u8);
	// rlwinm r9,r8,28,29,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0x7;
	// stw r11,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, r11.u32);
	// rlwinm. r10,r7,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r6,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, ctx.r6.u8);
	// stw r9,12704(r31)
	PPC_STORE_U32(r31.u32 + 12704, ctx.r9.u32);
	// beq 0x8241c890
	if (cr0.eq) goto loc_8241C890;
	// li r12,1
	r12.s64 = 1;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// lwz r10,10368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10368);
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// lwz r9,13176(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 13176);
	// clrlwi r10,r10,18
	ctx.r10.u64 = ctx.r10.u32 & 0x3FFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// beq cr6,0x8241c890
	if (cr6.eq) goto loc_8241C890;
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,57,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 57) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
loc_8241C890:
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// stw r10,12700(r31)
	PPC_STORE_U32(r31.u32 + 12700, ctx.r10.u32);
	// bl 0x824161e0
	ctx.lr = 0x8241C8B0;
	sub_824161E0(ctx, base);
	// lwz r11,13188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13188);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241ca34
	if (!cr0.eq) goto loc_8241CA34;
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241ca34
	if (cr0.eq) goto loc_8241CA34;
	// lwz r11,12748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// mr r26,r27
	r26.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8241c92c
	if (!cr6.gt) goto loc_8241C92C;
	// rotlwi r7,r11,0
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r31,12764
	ctx.r10.s64 = r31.s64 + 12764;
	// addi r11,r31,12996
	r11.s64 = r31.s64 + 12996;
loc_8241C8EC:
	// lwz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r8,r5,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r5.s64;
	// cmplw cr6,r28,r9
	cr6.compare<uint32_t>(r28.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8241c910
	if (cr6.gt) goto loc_8241C910;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
loc_8241C910:
	// cmplw cr6,r26,r8
	cr6.compare<uint32_t>(r26.u32, ctx.r8.u32, xer);
	// bgt cr6,0x8241c91c
	if (cr6.gt) goto loc_8241C91C;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
loc_8241C91C:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8241c8ec
	if (!cr0.eq) goto loc_8241C8EC;
loc_8241C92C:
	// addi r4,r31,12648
	ctx.r4.s64 = r31.s64 + 12648;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// li r5,28
	ctx.r5.s64 = 28;
	// bl 0x823da950
	ctx.lr = 0x8241C93C;
	sub_823DA950(ctx, base);
	// lwz r11,12676(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12676);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r9,12680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12680);
	// lwz r8,12684(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12684);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lwz r6,12688(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12688);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,7048
	ctx.r4.s64 = ctx.r7.s64 + 7048;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// bl 0x82416540
	ctx.lr = 0x8241C970;
	sub_82416540(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,7072
	ctx.r4.s64 = r11.s64 + 7072;
	// bl 0x82415c80
	ctx.lr = 0x8241C980;
	sub_82415C80(ctx, base);
	// lwz r11,13180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13180);
	// lwz r10,13184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13184);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// bl 0x8241bd08
	ctx.lr = 0x8241C9A4;
	sub_8241BD08(ctx, base);
	// addi r30,r31,13200
	r30.s64 = r31.s64 + 13200;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,13220(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 13220);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lfs f1,13216(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 13216);
	ctx.f1.f64 = double(temp.f32);
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824194c0
	ctx.lr = 0x8241C9C4;
	sub_824194C0(ctx, base);
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// li r29,15
	r29.s64 = 15;
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241c9d8
	if (!cr0.eq) goto loc_8241C9D8;
	// li r29,63
	r29.s64 = 63;
loc_8241C9D8:
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// bl 0x8241bd08
	ctx.lr = 0x8241C9F4;
	sub_8241BD08(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r8,13220(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 13220);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f1,13216(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 13216);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824194c0
	ctx.lr = 0x8241CA10;
	sub_824194C0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241bd08
	ctx.lr = 0x8241CA1C;
	sub_8241BD08(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824165c0
	ctx.lr = 0x8241CA28;
	sub_824165C0(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82415c80
	ctx.lr = 0x8241CA34;
	sub_82415C80(ctx, base);
loc_8241CA34:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8241CA3C"))) PPC_WEAK_FUNC(sub_8241CA3C);
PPC_FUNC_IMPL(__imp__sub_8241CA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241CA40"))) PPC_WEAK_FUNC(sub_8241CA40);
PPC_FUNC_IMPL(__imp__sub_8241CA40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// clrlwi r11,r11,25
	r11.u64 = r11.u32 & 0x7F;
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
	// bl 0x82412710
	ctx.lr = 0x8241CA64;
	sub_82412710(ctx, base);
	// lwz r11,13376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13376);
	// lwz r9,13380(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 13380);
	// addi r3,r31,13368
	ctx.r3.s64 = r31.s64 + 13368;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x8241ca84
	if (!cr6.gt) goto loc_8241CA84;
	// bl 0x82412198
	ctx.lr = 0x8241CA80;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241CA84:
	// lis r10,-31488
	ctx.r10.s64 = -2063597568;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r9,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r9.u32);
	// bne 0x8241caf0
	if (!cr0.eq) goto loc_8241CAF0;
	// lwz r11,11320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11320);
	// lis r10,256
	ctx.r10.s64 = 16777216;
	// li r4,1
	ctx.r4.s64 = 1;
	// slw r5,r10,r11
	ctx.r5.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8242fef8
	ctx.lr = 0x8241CAB8;
	sub_8242FEF8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8241cad8
	if (cr0.eq) goto loc_8241CAD8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824161e0
	ctx.lr = 0x8241CACC;
	sub_824161E0(ctx, base);
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8241caf4
	goto loc_8241CAF4;
loc_8241CAD8:
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241caf0
	if (!cr0.eq) goto loc_8241CAF0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824161e0
	ctx.lr = 0x8241CAF0;
	sub_824161E0(ctx, base);
loc_8241CAF0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8241CAF4:
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

__attribute__((alias("__imp__sub_8241CB08"))) PPC_WEAK_FUNC(sub_8241CB08);
PPC_FUNC_IMPL(__imp__sub_8241CB08) {
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
	ctx.lr = 0x8241CB10;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq 0x8241cc98
	if (cr0.eq) goto loc_8241CC98;
	// addi r25,r31,13248
	r25.s64 = r31.s64 + 13248;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82411530
	ctx.lr = 0x8241CB3C;
	sub_82411530(ctx, base);
	// addi r26,r31,13348
	r26.s64 = r31.s64 + 13348;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82411530
	ctx.lr = 0x8241CB48;
	sub_82411530(ctx, base);
	// lwz r11,13188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13188);
	// lwz r9,11320(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 11320);
	// lis r10,256
	ctx.r10.s64 = 16777216;
	// rlwinm. r11,r11,0,2,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3F000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// slw r28,r10,r9
	r28.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// beq 0x8241cb64
	if (cr0.eq) goto loc_8241CB64;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_8241CB64:
	// lis r29,-32768
	r29.s64 = -2147483648;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8241bd08
	ctx.lr = 0x8241CB74;
	sub_8241BD08(ctx, base);
	// lwz r11,13368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13368);
	// addi r30,r31,13368
	r30.s64 = r31.s64 + 13368;
	// lis r27,16384
	r27.s64 = 1073741824;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241cb90
	if (!cr6.eq) goto loc_8241CB90;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8241cba8
	goto loc_8241CBA8;
loc_8241CB90:
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r6,r27,r11
	ctx.r6.s64 = r11.s64 - r27.s64;
loc_8241CBA8:
	// lis r11,-32189
	r11.s64 = -2109538304;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r11,-768
	ctx.r5.s64 = r11.s64 + -768;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412a08
	ctx.lr = 0x8241CBBC;
	sub_82412A08(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241bd08
	ctx.lr = 0x8241CBC8;
	sub_8241BD08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241CBD0;
	sub_82412710(ctx, base);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241cbec
	if (!cr6.gt) goto loc_8241CBEC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82412198
	ctx.lr = 0x8241CBEC;
	sub_82412198(ctx, base);
loc_8241CBEC:
	// lis r11,-30720
	r11.s64 = -2013265920;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r10.u32);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x8241cc1c
	if (!cr6.gt) goto loc_8241CC1C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82412198
	ctx.lr = 0x8241CC1C;
	sub_82412198(ctx, base);
loc_8241CC1C:
	// lis r11,-30464
	r11.s64 = -1996488704;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241cc48
	if (cr6.eq) goto loc_8241CC48;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
loc_8241CC48:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241cc70
	if (cr6.eq) goto loc_8241CC70;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
loc_8241CC70:
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r10,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82412568
	ctx.lr = 0x8241CC88;
	sub_82412568(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82412568
	ctx.lr = 0x8241CC94;
	sub_82412568(ctx, base);
	// b 0x8241cca0
	goto loc_8241CCA0;
loc_8241CC98:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241CCA0;
	sub_82412710(ctx, base);
loc_8241CCA0:
	// lwz r11,13376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13376);
	// addi r3,r31,13368
	ctx.r3.s64 = r31.s64 + 13368;
	// lwz r10,13380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13380);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241ccc0
	if (!cr6.gt) goto loc_8241CCC0;
	// bl 0x82412198
	ctx.lr = 0x8241CCBC;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241CCC0:
	// lis r10,-31744
	ctx.r10.s64 = -2080374784;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// li r12,1
	r12.s64 = 1;
	// stw r9,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r9.u32);
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
	// andi. r10,r10,191
	ctx.r10.u64 = ctx.r10.u64 & 191;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r10,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, ctx.r10.u8);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241cd60
	if (cr0.eq) goto loc_8241CD60;
	// addi r4,r31,12676
	ctx.r4.s64 = r31.s64 + 12676;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82415c80
	ctx.lr = 0x8241CD1C;
	sub_82415C80(ctx, base);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// li r12,1
	r12.s64 = 1;
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,57,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 57) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// lis r12,-17
	r12.s64 = -1114112;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r12,r12,65534
	r12.u64 = r12.u64 | 65534;
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
loc_8241CD60:
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241cd78
	if (cr0.eq) goto loc_8241CD78;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241ca40
	ctx.lr = 0x8241CD74;
	sub_8241CA40(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
loc_8241CD78:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8241CD84"))) PPC_WEAK_FUNC(sub_8241CD84);
PPC_FUNC_IMPL(__imp__sub_8241CD84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241CD88"))) PPC_WEAK_FUNC(sub_8241CD88);
PPC_FUNC_IMPL(__imp__sub_8241CD88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8241CD90;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// rlwinm r10,r6,30,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0xFF;
	// mullw r9,r24,r6
	ctx.r9.s64 = int64_t(r24.s32) * int64_t(ctx.r6.s32);
	// lbz r11,11832(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11832);
	// lbz r25,12528(r31)
	r25.u64 = PPC_LOAD_U8(r31.u32 + 12528);
	// stb r10,12528(r31)
	PPC_STORE_U8(r31.u32 + 12528, ctx.r10.u8);
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// rlwinm r23,r9,30,2,31
	r23.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241cdd8
	if (cr6.eq) goto loc_8241CDD8;
	// lwz r11,12696(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12696);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241cdd8
	if (cr6.eq) goto loc_8241CDD8;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_8241CDD8:
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// li r26,0
	r26.s64 = 0;
	// rldicr r11,r11,0,62
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFFFFFFFFFFFFE;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
	// mr r28,r11
	r28.u64 = r11.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// ld r27,32(r31)
	r27.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// ld r30,16(r31)
	r30.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r29,8(r31)
	r29.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// beq cr6,0x8241ce18
	if (cr6.eq) goto loc_8241CE18;
	// addi r6,r31,1920
	ctx.r6.s64 = r31.s64 + 1920;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824238e0
	ctx.lr = 0x8241CE14;
	sub_824238E0(ctx, base);
	// std r26,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r26.u64);
loc_8241CE18:
	// cmpldi cr6,r29,0
	cr6.compare<uint64_t>(r29.u64, 0, xer);
	// beq cr6,0x8241ce38
	if (cr6.eq) goto loc_8241CE38;
	// addi r6,r31,6016
	ctx.r6.s64 = r31.s64 + 6016;
	// li r5,17408
	ctx.r5.s64 = 17408;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824238e0
	ctx.lr = 0x8241CE34;
	sub_824238E0(ctx, base);
	// std r26,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r26.u64);
loc_8241CE38:
	// cmpldi cr6,r30,0
	cr6.compare<uint64_t>(r30.u64, 0, xer);
	// beq cr6,0x8241cf18
	if (cr6.eq) goto loc_8241CF18;
	// rlwinm r11,r30,0,11,14
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1E0000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241ce5c
	if (cr6.eq) goto loc_8241CE5C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82424670
	ctx.lr = 0x8241CE58;
	sub_82424670(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241CE5C:
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// and r11,r11,r30
	r11.u64 = r11.u64 & r30.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241ce80
	if (cr6.eq) goto loc_8241CE80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,10560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824231b0
	ctx.lr = 0x8241CE7C;
	sub_824231B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241CE80:
	// clrldi r11,r30,52
	r11.u64 = r30.u64 & 0xFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241cea0
	if (cr6.eq) goto loc_8241CEA0;
	// addi r6,r31,10548
	ctx.r6.s64 = r31.s64 + 10548;
	// li r5,8704
	ctx.r5.s64 = 8704;
	// rldicr r4,r30,52,11
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 52) & 0xFFF0000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241CEA0;
	sub_82423548(ctx, base);
loc_8241CEA0:
	// rlwinm r11,r30,0,15,19
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241cec0
	if (cr6.eq) goto loc_8241CEC0;
	// addi r6,r31,10528
	ctx.r6.s64 = r31.s64 + 10528;
	// li r5,8576
	ctx.r5.s64 = 8576;
	// rldicr r4,r30,47,4
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 47) & 0xF800000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241CEC0;
	sub_82423548(ctx, base);
loc_8241CEC0:
	// lis r12,0
	r12.s64 = 0;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,42,21
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFC0000000000;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241ceec
	if (cr6.eq) goto loc_8241CEEC;
	// addi r6,r31,10368
	ctx.r6.s64 = r31.s64 + 10368;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// rldicr r4,r30,6,15
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 6) & 0xFFFF000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241CEEC;
	sub_82423548(ctx, base);
loc_8241CEEC:
	// lis r12,-32
	r12.s64 = -2097152;
	// clrldi r12,r12,22
	r12.u64 = r12.u64 & 0x3FFFFFFFFFF;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241cf14
	if (cr6.eq) goto loc_8241CF14;
	// addi r6,r31,10444
	ctx.r6.s64 = r31.s64 + 10444;
	// li r5,8448
	ctx.r5.s64 = 8448;
	// rldicr r4,r30,22,20
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 22) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241CF14;
	sub_82423548(ctx, base);
loc_8241CF14:
	// std r26,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r26.u64);
loc_8241CF18:
	// cmpldi cr6,r28,0
	cr6.compare<uint64_t>(r28.u64, 0, xer);
	// beq cr6,0x8241cf68
	if (cr6.eq) goto loc_8241CF68;
	// clrldi r11,r28,32
	r11.u64 = r28.u64 & 0xFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241cf38
	if (cr6.eq) goto loc_8241CF38;
	// rldicr r4,r28,32,31
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 32) & 0xFFFFFFFF00000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423788
	ctx.lr = 0x8241CF38;
	sub_82423788(ctx, base);
loc_8241CF38:
	// lis r12,31
	r12.s64 = 2031616;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,34,29
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFC00000000;
	// and r11,r28,r12
	r11.u64 = r28.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241cf64
	if (cr6.eq) goto loc_8241CF64;
	// addi r6,r31,10596
	ctx.r6.s64 = r31.s64 + 10596;
	// li r5,8832
	ctx.r5.s64 = 8832;
	// rldicr r4,r28,9,20
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 9) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241CF64;
	sub_82423548(ctx, base);
loc_8241CF64:
	// std r26,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r26.u64);
loc_8241CF68:
	// cmpldi cr6,r27,0
	cr6.compare<uint64_t>(r27.u64, 0, xer);
	// beq cr6,0x8241d004
	if (cr6.eq) goto loc_8241D004;
	// clrldi r11,r27,26
	r11.u64 = r27.u64 & 0x3FFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241cf90
	if (cr6.eq) goto loc_8241CF90;
	// addi r6,r31,10680
	ctx.r6.s64 = r31.s64 + 10680;
	// li r5,8960
	ctx.r5.s64 = 8960;
	// rldicr r4,r27,26,37
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 26) & 0xFFFFFFFFFC000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241CF90;
	sub_82423548(ctx, base);
loc_8241CF90:
	// li r12,255
	r12.s64 = 255;
	// rldicr r12,r12,38,25
	r12.u64 = __builtin_rotateleft64(r12.u64, 38) & 0xFFFFFFC000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241cfb8
	if (cr6.eq) goto loc_8241CFB8;
	// addi r6,r31,10832
	ctx.r6.s64 = r31.s64 + 10832;
	// li r5,9088
	ctx.r5.s64 = 9088;
	// rldicr r4,r27,18,7
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 18) & 0xFF00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241CFB8;
	sub_82423548(ctx, base);
loc_8241CFB8:
	// li r12,63
	r12.s64 = 63;
	// rldicr r12,r12,49,14
	r12.u64 = __builtin_rotateleft64(r12.u64, 49) & 0xFFFE000000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241cfd8
	if (cr6.eq) goto loc_8241CFD8;
	// rldicr r4,r27,9,5
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 9) & 0xFC00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423608
	ctx.lr = 0x8241CFD8;
	sub_82423608(ctx, base);
loc_8241CFD8:
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d000
	if (cr6.eq) goto loc_8241D000;
	// addi r6,r31,10112
	ctx.r6.s64 = r31.s64 + 10112;
	// li r5,18688
	ctx.r5.s64 = 18688;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D000;
	sub_82423548(ctx, base);
loc_8241D000:
	// std r26,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r26.u64);
loc_8241D004:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r30,48(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stb r25,12528(r31)
	PPC_STORE_U8(r31.u32 + 12528, r25.u8);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8241d024
	if (!cr6.gt) goto loc_8241D024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241D020;
	sub_82412710(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241D024:
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411840
	ctx.lr = 0x8241D034;
	sub_82411840(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bne 0x8241d048
	if (!cr0.eq) goto loc_8241D048;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8241d218
	goto loc_8241D218;
loc_8241D048:
	// li r11,8450
	r11.s64 = 8450;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stwu r11,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r11.u32);
	r30.u32 = ea;
	// lis r11,5
	r11.s64 = 327680;
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r8,r11,18618
	ctx.r8.u64 = r11.u64 | 18618;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// rlwinm r11,r28,12,20,31
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 12) & 0xFFF;
	// stwu r10,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r30.u32 = ea;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r10,r11,512
	ctx.r10.s64 = r11.s64 + 512;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// clrlwi r11,r28,3
	r11.u64 = r28.u32 & 0x1FFFFFFF;
	// stwu r8,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r30.u32 = ea;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ori r10,r4,2
	ctx.r10.u64 = ctx.r4.u64 | 2;
	// ori r11,r11,3
	r11.u64 = r11.u64 | 3;
	// rlwimi r10,r23,2,6,29
	ctx.r10.u64 = (__builtin_rotateleft32(r23.u32, 2) & 0x3FFFFFC) | (ctx.r10.u64 & 0xFFFFFFFFFC000003);
	// stwu r9,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r30.u32 = ea;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// ori r8,r8,20480
	ctx.r8.u64 = ctx.r8.u64 | 20480;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// stwu r7,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r30.u32 = ea;
	// stwu r6,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r30.u32 = ea;
	// stwu r5,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	r30.u32 = ea;
	// stwu r11,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r11.u32);
	r30.u32 = ea;
	// stwu r10,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r30.u32 = ea;
	// stwu r8,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r30.u32 = ea;
	// stwu r4,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r30.u32 = ea;
	// stwu r9,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r30.u32 = ea;
	// stwu r26,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r26.u32);
	r30.u32 = ea;
	// lbz r11,12187(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// subfic r11,r11,0
	xer.ca = r11.u32 <= 0;
	r11.s64 = 0 - r11.s64;
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// lbz r10,12122(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12122);
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// rlwimi r10,r11,8,23,23
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0x100) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFEFF);
	// clrlwi r29,r10,23
	r29.u64 = ctx.r10.u32 & 0x1FF;
	// rlwinm r29,r29,0,26,23
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFFFFFFFFFFF3F;
	// bne 0x8241d130
	if (!cr0.eq) goto loc_8241D130;
	// lis r11,-16383
	r11.s64 = -1073676288;
	// clrlwi r10,r22,26
	ctx.r10.u64 = r22.u32 & 0x3F;
	// ori r11,r11,8705
	r11.u64 = r11.u64 | 8705;
	// rlwinm r9,r24,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 16) & 0xFFFF0000;
	// stwu r11,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r11.u32);
	r30.u32 = ea;
	// or r11,r10,r9
	r11.u64 = ctx.r10.u64 | ctx.r9.u64;
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// stwu r29,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r29.u32);
	r30.u32 = ea;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r10.u32 = ea;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// b 0x8241d1fc
	goto loc_8241D1FC;
loc_8241D130:
	// lwz r11,13256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13256);
	// addi r3,r31,13248
	ctx.r3.s64 = r31.s64 + 13248;
	// lwz r10,13260(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13260);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241d150
	if (!cr6.gt) goto loc_8241D150;
	// bl 0x82412198
	ctx.lr = 0x8241D14C;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241D150:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// ori r9,r9,24576
	ctx.r9.u64 = ctx.r9.u64 | 24576;
	// stw r8,13256(r31)
	PPC_STORE_U32(r31.u32 + 13256, ctx.r8.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// rlwinm r6,r24,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r7,r22,26
	ctx.r7.u64 = r22.u32 & 0x3F;
	// lis r9,-16383
	ctx.r9.s64 = -1073676288;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// ori r9,r9,8705
	ctx.r9.u64 = ctx.r9.u64 | 8705;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// ori r7,r7,128
	ctx.r7.u64 = ctx.r7.u64 | 128;
	// lis r5,-16384
	ctx.r5.s64 = -1073741824;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// ori r8,r5,24576
	ctx.r8.u64 = ctx.r5.u64 | 24576;
	// lis r5,-32768
	ctx.r5.s64 = -2147483648;
	// lis r10,-16383
	ctx.r10.s64 = -1073676288;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stwu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r6.u32 = ea;
	// ori r4,r10,23041
	ctx.r4.u64 = ctx.r10.u64 | 23041;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// rlwinm r11,r11,0,3,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1FFFFFFE;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// li r9,26
	ctx.r9.s64 = 26;
	// stwu r29,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r6.u32 = ea;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ori r10,r3,17921
	ctx.r10.u64 = ctx.r3.u64 | 17921;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stwu r7,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r6.u32 = ea;
	// li r3,25
	ctx.r3.s64 = 25;
	// stwu r8,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r6.u32 = ea;
	// stwu r5,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r6.u32 = ea;
	// stwu r4,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r6.u32 = ea;
	// stwu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r6.u32 = ea;
	// stwu r11,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r6.u32 = ea;
	// stwu r10,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r6.u32 = ea;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// stwu r3,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	r11.u32 = ea;
loc_8241D1FC:
	// ld r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// std r10,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r10.u64);
	// stw r11,13444(r31)
	PPC_STORE_U32(r31.u32 + 13444, r11.u32);
	// stw r28,13448(r31)
	PPC_STORE_U32(r31.u32 + 13448, r28.u32);
	// stw r23,13456(r31)
	PPC_STORE_U32(r31.u32 + 13456, r23.u32);
loc_8241D218:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8241D220"))) PPC_WEAK_FUNC(sub_8241D220);
PPC_FUNC_IMPL(__imp__sub_8241D220) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,13444(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13444);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241D22C"))) PPC_WEAK_FUNC(sub_8241D22C);
PPC_FUNC_IMPL(__imp__sub_8241D22C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241D230"))) PPC_WEAK_FUNC(sub_8241D230);
PPC_FUNC_IMPL(__imp__sub_8241D230) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8241D238;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// li r26,0
	r26.s64 = 0;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// ld r27,32(r31)
	r27.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// ld r28,24(r31)
	r28.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// ld r30,16(r31)
	r30.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r29,8(r31)
	r29.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// beq cr6,0x8241d27c
	if (cr6.eq) goto loc_8241D27C;
	// addi r6,r31,1920
	ctx.r6.s64 = r31.s64 + 1920;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// bl 0x824238e0
	ctx.lr = 0x8241D278;
	sub_824238E0(ctx, base);
	// std r26,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r26.u64);
loc_8241D27C:
	// cmpldi cr6,r29,0
	cr6.compare<uint64_t>(r29.u64, 0, xer);
	// beq cr6,0x8241d29c
	if (cr6.eq) goto loc_8241D29C;
	// addi r6,r31,6016
	ctx.r6.s64 = r31.s64 + 6016;
	// li r5,17408
	ctx.r5.s64 = 17408;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824238e0
	ctx.lr = 0x8241D298;
	sub_824238E0(ctx, base);
	// std r26,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r26.u64);
loc_8241D29C:
	// cmpldi cr6,r30,0
	cr6.compare<uint64_t>(r30.u64, 0, xer);
	// beq cr6,0x8241d37c
	if (cr6.eq) goto loc_8241D37C;
	// rlwinm r11,r30,0,11,14
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1E0000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d2c0
	if (cr6.eq) goto loc_8241D2C0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82424670
	ctx.lr = 0x8241D2BC;
	sub_82424670(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241D2C0:
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// and r11,r11,r30
	r11.u64 = r11.u64 & r30.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d2e4
	if (cr6.eq) goto loc_8241D2E4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,10560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824231b0
	ctx.lr = 0x8241D2E0;
	sub_824231B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241D2E4:
	// clrldi r11,r30,52
	r11.u64 = r30.u64 & 0xFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d304
	if (cr6.eq) goto loc_8241D304;
	// addi r6,r31,10548
	ctx.r6.s64 = r31.s64 + 10548;
	// li r5,8704
	ctx.r5.s64 = 8704;
	// rldicr r4,r30,52,11
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 52) & 0xFFF0000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D304;
	sub_82423548(ctx, base);
loc_8241D304:
	// rlwinm r11,r30,0,15,19
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d324
	if (cr6.eq) goto loc_8241D324;
	// addi r6,r31,10528
	ctx.r6.s64 = r31.s64 + 10528;
	// li r5,8576
	ctx.r5.s64 = 8576;
	// rldicr r4,r30,47,4
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 47) & 0xF800000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D324;
	sub_82423548(ctx, base);
loc_8241D324:
	// lis r12,0
	r12.s64 = 0;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,42,21
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFC0000000000;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d350
	if (cr6.eq) goto loc_8241D350;
	// addi r6,r31,10368
	ctx.r6.s64 = r31.s64 + 10368;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// rldicr r4,r30,6,15
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 6) & 0xFFFF000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D350;
	sub_82423548(ctx, base);
loc_8241D350:
	// lis r12,-32
	r12.s64 = -2097152;
	// clrldi r12,r12,22
	r12.u64 = r12.u64 & 0x3FFFFFFFFFF;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d378
	if (cr6.eq) goto loc_8241D378;
	// addi r6,r31,10444
	ctx.r6.s64 = r31.s64 + 10444;
	// li r5,8448
	ctx.r5.s64 = 8448;
	// rldicr r4,r30,22,20
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 22) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D378;
	sub_82423548(ctx, base);
loc_8241D378:
	// std r26,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r26.u64);
loc_8241D37C:
	// cmpldi cr6,r28,0
	cr6.compare<uint64_t>(r28.u64, 0, xer);
	// beq cr6,0x8241d3cc
	if (cr6.eq) goto loc_8241D3CC;
	// clrldi r11,r28,32
	r11.u64 = r28.u64 & 0xFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d39c
	if (cr6.eq) goto loc_8241D39C;
	// rldicr r4,r28,32,31
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 32) & 0xFFFFFFFF00000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423788
	ctx.lr = 0x8241D39C;
	sub_82423788(ctx, base);
loc_8241D39C:
	// lis r12,31
	r12.s64 = 2031616;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,34,29
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFC00000000;
	// and r11,r28,r12
	r11.u64 = r28.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d3c8
	if (cr6.eq) goto loc_8241D3C8;
	// addi r6,r31,10596
	ctx.r6.s64 = r31.s64 + 10596;
	// li r5,8832
	ctx.r5.s64 = 8832;
	// rldicr r4,r28,9,20
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 9) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D3C8;
	sub_82423548(ctx, base);
loc_8241D3C8:
	// std r26,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r26.u64);
loc_8241D3CC:
	// cmpldi cr6,r27,0
	cr6.compare<uint64_t>(r27.u64, 0, xer);
	// beq cr6,0x8241d468
	if (cr6.eq) goto loc_8241D468;
	// clrldi r11,r27,26
	r11.u64 = r27.u64 & 0x3FFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d3f4
	if (cr6.eq) goto loc_8241D3F4;
	// addi r6,r31,10680
	ctx.r6.s64 = r31.s64 + 10680;
	// li r5,8960
	ctx.r5.s64 = 8960;
	// rldicr r4,r27,26,37
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 26) & 0xFFFFFFFFFC000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D3F4;
	sub_82423548(ctx, base);
loc_8241D3F4:
	// li r12,255
	r12.s64 = 255;
	// rldicr r12,r12,38,25
	r12.u64 = __builtin_rotateleft64(r12.u64, 38) & 0xFFFFFFC000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d41c
	if (cr6.eq) goto loc_8241D41C;
	// addi r6,r31,10832
	ctx.r6.s64 = r31.s64 + 10832;
	// li r5,9088
	ctx.r5.s64 = 9088;
	// rldicr r4,r27,18,7
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 18) & 0xFF00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D41C;
	sub_82423548(ctx, base);
loc_8241D41C:
	// li r12,63
	r12.s64 = 63;
	// rldicr r12,r12,49,14
	r12.u64 = __builtin_rotateleft64(r12.u64, 49) & 0xFFFE000000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d43c
	if (cr6.eq) goto loc_8241D43C;
	// rldicr r4,r27,9,5
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 9) & 0xFC00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423608
	ctx.lr = 0x8241D43C;
	sub_82423608(ctx, base);
loc_8241D43C:
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d464
	if (cr6.eq) goto loc_8241D464;
	// addi r6,r31,10112
	ctx.r6.s64 = r31.s64 + 10112;
	// li r5,18688
	ctx.r5.s64 = 18688;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D464;
	sub_82423548(ctx, base);
loc_8241D464:
	// std r26,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r26.u64);
loc_8241D468:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r26,r31,12122
	r26.s64 = r31.s64 + 12122;
	// addi r27,r11,3064
	r27.s64 = r11.s64 + 3064;
loc_8241D474:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241d48c
	if (!cr6.gt) goto loc_8241D48C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241D48C;
	sub_82412710(ctx, base);
loc_8241D48C:
	// li r11,8450
	r11.s64 = 8450;
	// mr r29,r24
	r29.u64 = r24.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// cmplwi cr6,r24,65535
	cr6.compare<uint32_t>(r24.u32, 65535, xer);
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ble cr6,0x8241d4c8
	if (!cr6.gt) goto loc_8241D4C8;
	// rlwinm r11,r25,3,0,28
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// lwzx r11,r11,r27
	r11.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// divwu r10,r10,r11
	ctx.r10.u32 = ctx.r10.u32 / r11.u32;
	// twllei r11,0
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// mullw r29,r10,r11
	r29.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
loc_8241D4C8:
	// lbz r11,12187(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// subfic r9,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r9.s64 = 0 - r11.s64;
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// lbzx r11,r26,r11
	r11.u64 = PPC_LOAD_U8(r26.u32 + r11.u32);
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// rlwimi r11,r10,8,23,23
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0x100) | (r11.u64 & 0xFFFFFFFFFFFFFEFF);
	// clrlwi r28,r11,23
	r28.u64 = r11.u32 & 0x1FF;
	// rlwinm r28,r28,0,26,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFF3F;
	// bne 0x8241d524
	if (!cr0.eq) goto loc_8241D524;
	// lis r11,-16383
	r11.s64 = -1073676288;
	// rlwinm r10,r29,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 16) & 0xFFFF0000;
	// ori r11,r11,8705
	r11.u64 = r11.u64 | 8705;
	// clrlwi r9,r25,26
	ctx.r9.u64 = r25.u32 & 0x3F;
	// stwu r11,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r11.u32);
	r30.u32 = ea;
	// or r11,r10,r9
	r11.u64 = ctx.r10.u64 | ctx.r9.u64;
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// stwu r28,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r28.u32);
	r30.u32 = ea;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r10.u32 = ea;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// b 0x8241d5f0
	goto loc_8241D5F0;
loc_8241D524:
	// lwz r11,13256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13256);
	// addi r3,r31,13248
	ctx.r3.s64 = r31.s64 + 13248;
	// lwz r10,13260(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13260);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241d544
	if (!cr6.gt) goto loc_8241D544;
	// bl 0x82412198
	ctx.lr = 0x8241D540;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241D544:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// ori r9,r9,24576
	ctx.r9.u64 = ctx.r9.u64 | 24576;
	// stw r8,13256(r31)
	PPC_STORE_U32(r31.u32 + 13256, ctx.r8.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// clrlwi r6,r25,26
	ctx.r6.u64 = r25.u32 & 0x3F;
	// rlwinm r7,r29,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 16) & 0xFFFF0000;
	// lis r9,-16383
	ctx.r9.s64 = -1073676288;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// ori r9,r9,8705
	ctx.r9.u64 = ctx.r9.u64 | 8705;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// ori r7,r7,128
	ctx.r7.u64 = ctx.r7.u64 | 128;
	// lis r5,-16384
	ctx.r5.s64 = -1073741824;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// ori r8,r5,24576
	ctx.r8.u64 = ctx.r5.u64 | 24576;
	// lis r5,-32768
	ctx.r5.s64 = -2147483648;
	// lis r10,-16383
	ctx.r10.s64 = -1073676288;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stwu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r6.u32 = ea;
	// ori r4,r10,23041
	ctx.r4.u64 = ctx.r10.u64 | 23041;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// rlwinm r11,r11,0,3,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1FFFFFFE;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// li r9,26
	ctx.r9.s64 = 26;
	// stwu r28,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r6.u32 = ea;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ori r10,r3,17921
	ctx.r10.u64 = ctx.r3.u64 | 17921;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stwu r7,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r6.u32 = ea;
	// li r3,25
	ctx.r3.s64 = 25;
	// stwu r8,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r6.u32 = ea;
	// stwu r5,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r6.u32 = ea;
	// stwu r4,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r6.u32 = ea;
	// stwu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r6.u32 = ea;
	// stwu r11,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r6.u32 = ea;
	// stwu r10,4(r6)
	ea = 4 + ctx.r6.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r6.u32 = ea;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// stwu r3,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	r11.u32 = ea;
loc_8241D5F0:
	// subf. r10,r29,r24
	ctx.r10.s64 = r24.s64 - r29.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// beq 0x8241d618
	if (cr0.eq) goto loc_8241D618;
	// addi r9,r27,4
	ctx.r9.s64 = r27.s64 + 4;
	// rlwinm r11,r25,3,0,28
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r11,r11,r9
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// subf r9,r11,r29
	ctx.r9.s64 = r29.s64 - r11.s64;
	// add r24,r11,r10
	r24.u64 = r11.u64 + ctx.r10.u64;
	// add r23,r9,r23
	r23.u64 = ctx.r9.u64 + r23.u64;
	// b 0x8241d474
	goto loc_8241D474;
loc_8241D618:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8241D620"))) PPC_WEAK_FUNC(sub_8241D620);
PPC_FUNC_IMPL(__imp__sub_8241D620) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x8241D628;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// mr r17,r5
	r17.u64 = ctx.r5.u64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// mr r19,r7
	r19.u64 = ctx.r7.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// li r26,0
	r26.s64 = 0;
	// ld r27,32(r31)
	r27.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// ld r28,24(r31)
	r28.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// ld r30,16(r31)
	r30.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r29,8(r31)
	r29.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// beq cr6,0x8241d670
	if (cr6.eq) goto loc_8241D670;
	// addi r6,r31,1920
	ctx.r6.s64 = r31.s64 + 1920;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// bl 0x824238e0
	ctx.lr = 0x8241D66C;
	sub_824238E0(ctx, base);
	// std r26,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r26.u64);
loc_8241D670:
	// cmpldi cr6,r29,0
	cr6.compare<uint64_t>(r29.u64, 0, xer);
	// beq cr6,0x8241d690
	if (cr6.eq) goto loc_8241D690;
	// addi r6,r31,6016
	ctx.r6.s64 = r31.s64 + 6016;
	// li r5,17408
	ctx.r5.s64 = 17408;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824238e0
	ctx.lr = 0x8241D68C;
	sub_824238E0(ctx, base);
	// std r26,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r26.u64);
loc_8241D690:
	// cmpldi cr6,r30,0
	cr6.compare<uint64_t>(r30.u64, 0, xer);
	// beq cr6,0x8241d770
	if (cr6.eq) goto loc_8241D770;
	// rlwinm r11,r30,0,11,14
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1E0000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d6b4
	if (cr6.eq) goto loc_8241D6B4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82424670
	ctx.lr = 0x8241D6B0;
	sub_82424670(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241D6B4:
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// and r11,r11,r30
	r11.u64 = r11.u64 & r30.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d6d8
	if (cr6.eq) goto loc_8241D6D8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,10560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824231b0
	ctx.lr = 0x8241D6D4;
	sub_824231B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8241D6D8:
	// clrldi r11,r30,52
	r11.u64 = r30.u64 & 0xFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d6f8
	if (cr6.eq) goto loc_8241D6F8;
	// addi r6,r31,10548
	ctx.r6.s64 = r31.s64 + 10548;
	// li r5,8704
	ctx.r5.s64 = 8704;
	// rldicr r4,r30,52,11
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 52) & 0xFFF0000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D6F8;
	sub_82423548(ctx, base);
loc_8241D6F8:
	// rlwinm r11,r30,0,15,19
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d718
	if (cr6.eq) goto loc_8241D718;
	// addi r6,r31,10528
	ctx.r6.s64 = r31.s64 + 10528;
	// li r5,8576
	ctx.r5.s64 = 8576;
	// rldicr r4,r30,47,4
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 47) & 0xF800000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D718;
	sub_82423548(ctx, base);
loc_8241D718:
	// lis r12,0
	r12.s64 = 0;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,42,21
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFC0000000000;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d744
	if (cr6.eq) goto loc_8241D744;
	// addi r6,r31,10368
	ctx.r6.s64 = r31.s64 + 10368;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// rldicr r4,r30,6,15
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 6) & 0xFFFF000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D744;
	sub_82423548(ctx, base);
loc_8241D744:
	// lis r12,-32
	r12.s64 = -2097152;
	// clrldi r12,r12,22
	r12.u64 = r12.u64 & 0x3FFFFFFFFFF;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d76c
	if (cr6.eq) goto loc_8241D76C;
	// addi r6,r31,10444
	ctx.r6.s64 = r31.s64 + 10444;
	// li r5,8448
	ctx.r5.s64 = 8448;
	// rldicr r4,r30,22,20
	ctx.r4.u64 = __builtin_rotateleft64(r30.u64, 22) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D76C;
	sub_82423548(ctx, base);
loc_8241D76C:
	// std r26,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r26.u64);
loc_8241D770:
	// cmpldi cr6,r28,0
	cr6.compare<uint64_t>(r28.u64, 0, xer);
	// beq cr6,0x8241d7c0
	if (cr6.eq) goto loc_8241D7C0;
	// clrldi r11,r28,32
	r11.u64 = r28.u64 & 0xFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d790
	if (cr6.eq) goto loc_8241D790;
	// rldicr r4,r28,32,31
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 32) & 0xFFFFFFFF00000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423788
	ctx.lr = 0x8241D790;
	sub_82423788(ctx, base);
loc_8241D790:
	// lis r12,31
	r12.s64 = 2031616;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,34,29
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFC00000000;
	// and r11,r28,r12
	r11.u64 = r28.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d7bc
	if (cr6.eq) goto loc_8241D7BC;
	// addi r6,r31,10596
	ctx.r6.s64 = r31.s64 + 10596;
	// li r5,8832
	ctx.r5.s64 = 8832;
	// rldicr r4,r28,9,20
	ctx.r4.u64 = __builtin_rotateleft64(r28.u64, 9) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D7BC;
	sub_82423548(ctx, base);
loc_8241D7BC:
	// std r26,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r26.u64);
loc_8241D7C0:
	// cmpldi cr6,r27,0
	cr6.compare<uint64_t>(r27.u64, 0, xer);
	// beq cr6,0x8241d85c
	if (cr6.eq) goto loc_8241D85C;
	// clrldi r11,r27,26
	r11.u64 = r27.u64 & 0x3FFFFFFFFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d7e8
	if (cr6.eq) goto loc_8241D7E8;
	// addi r6,r31,10680
	ctx.r6.s64 = r31.s64 + 10680;
	// li r5,8960
	ctx.r5.s64 = 8960;
	// rldicr r4,r27,26,37
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 26) & 0xFFFFFFFFFC000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D7E8;
	sub_82423548(ctx, base);
loc_8241D7E8:
	// li r12,255
	r12.s64 = 255;
	// rldicr r12,r12,38,25
	r12.u64 = __builtin_rotateleft64(r12.u64, 38) & 0xFFFFFFC000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d810
	if (cr6.eq) goto loc_8241D810;
	// addi r6,r31,10832
	ctx.r6.s64 = r31.s64 + 10832;
	// li r5,9088
	ctx.r5.s64 = 9088;
	// rldicr r4,r27,18,7
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 18) & 0xFF00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D810;
	sub_82423548(ctx, base);
loc_8241D810:
	// li r12,63
	r12.s64 = 63;
	// rldicr r12,r12,49,14
	r12.u64 = __builtin_rotateleft64(r12.u64, 49) & 0xFFFE000000000000;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d830
	if (cr6.eq) goto loc_8241D830;
	// rldicr r4,r27,9,5
	ctx.r4.u64 = __builtin_rotateleft64(r27.u64, 9) & 0xFC00000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423608
	ctx.lr = 0x8241D830;
	sub_82423608(ctx, base);
loc_8241D830:
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r27,r12
	r11.u64 = r27.u64 & r12.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8241d858
	if (cr6.eq) goto loc_8241D858;
	// addi r6,r31,10112
	ctx.r6.s64 = r31.s64 + 10112;
	// li r5,18688
	ctx.r5.s64 = 18688;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8241D858;
	sub_82423548(ctx, base);
loc_8241D858:
	// std r26,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r26.u64);
loc_8241D85C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r24,12436(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 12436);
	// addi r23,r31,12122
	r23.s64 = r31.s64 + 12122;
	// clrlwi r22,r18,26
	r22.u64 = r18.u32 & 0x3F;
	// addi r20,r11,3064
	r20.s64 = r11.s64 + 3064;
loc_8241D870:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241d888
	if (!cr6.gt) goto loc_8241D888;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241D888;
	sub_82412710(ctx, base);
loc_8241D888:
	// li r11,8450
	r11.s64 = 8450;
	// mr r27,r19
	r27.u64 = r19.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// cmplwi cr6,r19,65535
	cr6.compare<uint32_t>(r19.u32, 65535, xer);
	// stwu r17,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r17.u32);
	ctx.r3.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// ble cr6,0x8241d8c4
	if (!cr6.gt) goto loc_8241D8C4;
	// rlwinm r11,r18,3,0,28
	r11.u64 = __builtin_rotateleft64(r18.u32 | (r18.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// lwzx r11,r11,r20
	r11.u64 = PPC_LOAD_U32(r11.u32 + r20.u32);
	// divwu r10,r10,r11
	ctx.r10.u32 = ctx.r10.u32 / r11.u32;
	// twllei r11,0
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// mullw r27,r10,r11
	r27.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
loc_8241D8C4:
	// lbz r8,12187(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 12187);
	// rlwinm r11,r21,1,0,30
	r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,24(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// rlwinm r7,r27,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 16) & 0xFFFF0000;
	// subfic r9,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r8.s64;
	// lwz r6,0(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subfe r5,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// lbzx r4,r23,r8
	ctx.r4.u64 = PPC_LOAD_U8(r23.u32 + ctx.r8.u32);
	// clrlwi r8,r5,31
	ctx.r8.u64 = ctx.r5.u32 & 0x1;
	// addi r5,r9,512
	ctx.r5.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r11,3
	ctx.r9.u64 = r11.u32 & 0x1FFFFFFF;
	// rlwimi r4,r8,8,23,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0x100) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFEFF);
	// rlwinm r8,r5,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x1000;
	// rlwinm r11,r6,1,0,1
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xC0000000;
	// clrlwi r5,r27,8
	ctx.r5.u64 = r27.u32 & 0xFFFFFF;
	// rlwinm r6,r6,0,0,0
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80000000;
	// andi. r26,r4,319
	r26.u64 = ctx.r4.u64 & 319;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// or r30,r7,r22
	r30.u64 = ctx.r7.u64 | r22.u64;
	// add r28,r8,r9
	r28.u64 = ctx.r8.u64 + ctx.r9.u64;
	// or r29,r5,r11
	r29.u64 = ctx.r5.u64 | r11.u64;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq 0x8241d94c
	if (cr0.eq) goto loc_8241D94C;
	// rlwinm r9,r21,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r27,1,8,30
	ctx.r8.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFE;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// or r29,r8,r11
	r29.u64 = ctx.r8.u64 | r11.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// ori r30,r30,2048
	r30.u64 = r30.u64 | 2048;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
loc_8241D94C:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241d97c
	if (!cr0.eq) goto loc_8241D97C;
	// lis r11,-16381
	r11.s64 = -1073545216;
	// ori r11,r11,8705
	r11.u64 = r11.u64 | 8705;
	// stwu r11,4(r25)
	ea = 4 + r25.u32;
	PPC_STORE_U32(ea, r11.u32);
	r25.u32 = ea;
	// stwu r26,4(r25)
	ea = 4 + r25.u32;
	PPC_STORE_U32(ea, r26.u32);
	r25.u32 = ea;
	// stwu r30,4(r25)
	ea = 4 + r25.u32;
	PPC_STORE_U32(ea, r30.u32);
	r25.u32 = ea;
	// stwu r28,4(r25)
	ea = 4 + r25.u32;
	PPC_STORE_U32(ea, r28.u32);
	r25.u32 = ea;
	// mr r11,r25
	r11.u64 = r25.u64;
	// stwu r29,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r29.u32);
	r11.u32 = ea;
	// b 0x8241da40
	goto loc_8241DA40;
loc_8241D97C:
	// lwz r11,13256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13256);
	// addi r3,r31,13248
	ctx.r3.s64 = r31.s64 + 13248;
	// lwz r10,13260(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13260);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8241d99c
	if (!cr6.gt) goto loc_8241D99C;
	// bl 0x82412198
	ctx.lr = 0x8241D998;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8241D99C:
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// ori r9,r9,24576
	ctx.r9.u64 = ctx.r9.u64 | 24576;
	// stw r8,13256(r31)
	PPC_STORE_U32(r31.u32 + 13256, ctx.r8.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// lis r5,-16383
	ctx.r5.s64 = -1073676288;
	// lis r9,-16381
	ctx.r9.s64 = -1073545216;
	// lis r7,-16384
	ctx.r7.s64 = -1073741824;
	// ori r9,r9,8705
	ctx.r9.u64 = ctx.r9.u64 | 8705;
	// ori r7,r7,24576
	ctx.r7.u64 = ctx.r7.u64 | 24576;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// ori r8,r5,23041
	ctx.r8.u64 = ctx.r5.u64 | 23041;
	// lis r6,-32768
	ctx.r6.s64 = -2147483648;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// li r4,26
	ctx.r4.s64 = 26;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// rlwinm r11,r11,0,3,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1FFFFFFE;
	// stwu r9,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r5.u32 = ea;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwu r26,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r5.u32 = ea;
	// ori r10,r9,17921
	ctx.r10.u64 = ctx.r9.u64 | 17921;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// li r9,25
	ctx.r9.s64 = 25;
	// stwu r30,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r5.u32 = ea;
	// stwu r28,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r5.u32 = ea;
	// stwu r29,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r5.u32 = ea;
	// stwu r7,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r5.u32 = ea;
	// stwu r6,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r5.u32 = ea;
	// stwu r8,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r5.u32 = ea;
	// stwu r4,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r5.u32 = ea;
	// stwu r11,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r5.u32 = ea;
	// stwu r10,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r5.u32 = ea;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
loc_8241DA40:
	// subf. r10,r27,r19
	ctx.r10.s64 = r19.s64 - r27.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// beq 0x8241da68
	if (cr0.eq) goto loc_8241DA68;
	// addi r9,r20,4
	ctx.r9.s64 = r20.s64 + 4;
	// rlwinm r11,r18,3,0,28
	r11.u64 = __builtin_rotateleft64(r18.u32 | (r18.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r11,r11,r9
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// add r19,r11,r10
	r19.u64 = r11.u64 + ctx.r10.u64;
	// add r21,r9,r21
	r21.u64 = ctx.r9.u64 + r21.u64;
	// b 0x8241d870
	goto loc_8241D870;
loc_8241DA68:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8241DA70"))) PPC_WEAK_FUNC(sub_8241DA70);
PPC_FUNC_IMPL(__imp__sub_8241DA70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm. r11,r3,24,8,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241da80
	if (!cr0.eq) goto loc_8241DA80;
	// li r11,0
	r11.s64 = 0;
	// b 0x8241dac8
	goto loc_8241DAC8;
loc_8241DA80:
	// rlwinm. r10,r11,0,8,11
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF00000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8241daa4
	if (cr0.eq) goto loc_8241DAA4;
	// not r10,r11
	ctx.r10.u64 = ~r11.u64;
	// rlwinm r11,r11,3,9,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x7FFFF8;
	// rlwinm r10,r10,12,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xF;
	// subfic r10,r10,127
	xer.ca = ctx.r10.u32 <= 127;
	ctx.r10.s64 = 127 - ctx.r10.s64;
	// rlwinm r10,r10,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0xFF800000;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// b 0x8241dac8
	goto loc_8241DAC8;
loc_8241DAA4:
	// rlwinm r10,r11,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r10,3
	ctx.r9.s64 = ctx.r10.s64 + 3;
	// subfic r10,r10,113
	xer.ca = ctx.r10.u32 <= 113;
	ctx.r10.s64 = 113 - ctx.r10.s64;
	// slw r11,r11,r9
	r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r9.u8 & 0x3F));
	// clrlwi r11,r11,9
	r11.u64 = r11.u32 & 0x7FFFFF;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
loc_8241DAC8:
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r11.u32);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241DAE0"))) PPC_WEAK_FUNC(sub_8241DAE0);
PPC_FUNC_IMPL(__imp__sub_8241DAE0) {
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
	ctx.lr = 0x8241DAE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r3,21560
	r30.s64 = ctx.r3.s64 + 21560;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x8241db68
	if (cr6.eq) goto loc_8241DB68;
	// b 0x8241db5c
	goto loc_8241DB5C;
loc_8241DB00:
	// lwz r31,12(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x8241db58
	if (!cr6.eq) goto loc_8241DB58;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addis r3,r11,-16384
	ctx.r3.s64 = r11.s64 + -1073741824;
	// addi r4,r3,4096
	ctx.r4.s64 = ctx.r3.s64 + 4096;
	// bl 0x82425cd8
	ctx.lr = 0x8241DB34;
	sub_82425CD8(ctx, base);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821310f8
	ctx.lr = 0x8241DB40;
	sub_821310F8(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// bl 0x821310f8
	ctx.lr = 0x8241DB54;
	sub_821310F8(ctx, base);
	// b 0x8241db5c
	goto loc_8241DB5C;
loc_8241DB58:
	// mr r30,r31
	r30.u64 = r31.u64;
loc_8241DB5C:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241db00
	if (!cr6.eq) goto loc_8241DB00;
loc_8241DB68:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8241DB70"))) PPC_WEAK_FUNC(sub_8241DB70);
PPC_FUNC_IMPL(__imp__sub_8241DB70) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8241DB78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r3,21560
	r31.s64 = ctx.r3.s64 + 21560;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r11,21560(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 21560);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8241dc18
	if (!cr6.eq) goto loc_8241DC18;
loc_8241DB9C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8241dc18
	if (!cr6.eq) goto loc_8241DC18;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241dbc8
	if (cr6.eq) goto loc_8241DBC8;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x8241db9c
	if (cr6.eq) goto loc_8241DB9C;
	// b 0x8241dc18
	goto loc_8241DC18;
loc_8241DBC8:
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,6016
	ctx.r3.s64 = 6016;
	// bl 0x82130b50
	ctx.lr = 0x8241DBD4;
	sub_82130B50(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8241dbe8
	if (!cr0.eq) goto loc_8241DBE8;
loc_8241DBDC:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8241dc8c
	goto loc_8241DC8C;
loc_8241DBE8:
	// lis r4,-17280
	ctx.r4.s64 = -1132462080;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// bl 0x82130b50
	ctx.lr = 0x8241DBF4;
	sub_82130B50(ctx, base);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8241dc10
	if (!cr0.eq) goto loc_8241DC10;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821310f8
	ctx.lr = 0x8241DC0C;
	sub_821310F8(ctx, base);
	// b 0x8241dbdc
	goto loc_8241DBDC;
loc_8241DC10:
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// mr r31,r30
	r31.u64 = r30.u64;
loc_8241DC18:
	// li r11,0
	r11.s64 = 0;
loc_8241DC1C:
	// lbzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// bne cr6,0x8241dc34
	if (!cr6.eq) goto loc_8241DC34;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// blt cr6,0x8241dc1c
	if (cr6.lt) goto loc_8241DC1C;
loc_8241DC34:
	// lbzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// li r10,0
	ctx.r10.s64 = 0;
loc_8241DC3C:
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// srw r8,r9,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// clrlwi. r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8241dc58
	if (cr0.eq) goto loc_8241DC58;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// blt cr6,0x8241dc3c
	if (cr6.lt) goto loc_8241DC3C;
loc_8241DC58:
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// slw r8,r8,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stbx r9,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r9.u8);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8241DC8C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8241DC94"))) PPC_WEAK_FUNC(sub_8241DC94);
PPC_FUNC_IMPL(__imp__sub_8241DC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241DC98"))) PPC_WEAK_FUNC(sub_8241DC98);
PPC_FUNC_IMPL(__imp__sub_8241DC98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8241DCA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addic. r3,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r3.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// bne 0x8241ddfc
	if (!cr0.eq) goto loc_8241DDFC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// bne cr6,0x8241dd54
	if (!cr6.eq) goto loc_8241DD54;
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8241dde0
	if (!cr6.gt) goto loc_8241DDE0;
	// addi r30,r31,88
	r30.s64 = r31.s64 + 88;
loc_8241DCDC:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,-60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -60);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// srawi r11,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	r11.s64 = r11.s32 >> 4;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// slw r11,r9,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// lbzx r9,r10,r8
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// andc r11,r9,r11
	r11.u64 = ctx.r9.u64 & ~r11.u64;
	// stbx r11,r10,r8
	PPC_STORE_U8(ctx.r10.u32 + ctx.r8.u32, r11.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241dd3c
	if (!cr6.eq) goto loc_8241DD3C;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241dd3c
	if (!cr6.eq) goto loc_8241DD3C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8241dae0
	ctx.lr = 0x8241DD3C;
	sub_8241DAE0(ctx, base);
loc_8241DD3C:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8241dcdc
	if (cr6.lt) goto loc_8241DCDC;
	// b 0x8241dde0
	goto loc_8241DDE0;
loc_8241DD54:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x8241dde0
	if (!cr6.eq) goto loc_8241DDE0;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241dd9c
	if (cr6.eq) goto loc_8241DD9C;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// srawi r11,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	r11.s64 = r11.s32 >> 4;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// slw r11,r9,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// lbzx r9,r10,r8
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// andc r11,r9,r11
	r11.u64 = ctx.r9.u64 & ~r11.u64;
	// stbx r11,r10,r8
	PPC_STORE_U8(ctx.r10.u32 + ctx.r8.u32, r11.u8);
loc_8241DD9C:
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241ddc0
	if (!cr6.eq) goto loc_8241DDC0;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241ddc0
	if (!cr6.eq) goto loc_8241DDC0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8241dae0
	ctx.lr = 0x8241DDC0;
	sub_8241DAE0(ctx, base);
loc_8241DDC0:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r10,512
	ctx.r10.s64 = 33554432;
	// rlwinm r11,r11,0,0,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFF000000;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8241dde0
	if (!cr6.eq) goto loc_8241DDE0;
	// lbz r11,10943(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 10943);
	// clrlwi r11,r11,25
	r11.u64 = r11.u32 & 0x7F;
	// stb r11,10943(r28)
	PPC_STORE_U8(r28.u32 + 10943, r11.u8);
loc_8241DDE0:
	// lis r11,30840
	r11.s64 = 2021130240;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// ori r11,r11,30840
	r11.u64 = r11.u64 | 30840;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x821310f8
	ctx.lr = 0x8241DDF8;
	sub_821310F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8241DDFC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8241DE04"))) PPC_WEAK_FUNC(sub_8241DE04);
PPC_FUNC_IMPL(__imp__sub_8241DE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241DE08"))) PPC_WEAK_FUNC(sub_8241DE08);
PPC_FUNC_IMPL(__imp__sub_8241DE08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8241DE10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// rlwinm. r11,r4,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq 0x8241deb0
	if (cr0.eq) goto loc_8241DEB0;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241de38
	if (cr0.eq) goto loc_8241DE38;
	// lwz r11,12748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// b 0x8241de3c
	goto loc_8241DE3C;
loc_8241DE38:
	// li r11,1
	r11.s64 = 1;
loc_8241DE3C:
	// stw r11,148(r29)
	PPC_STORE_U32(r29.u32 + 148, r11.u32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// bne cr6,0x8241de60
	if (!cr6.eq) goto loc_8241DE60;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824302f0
	ctx.lr = 0x8241DE5C;
	sub_824302F0(ctx, base);
	// b 0x8241dea4
	goto loc_8241DEA4;
loc_8241DE60:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x8241dea4
	if (!cr6.eq) goto loc_8241DEA4;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241de80
	if (!cr6.gt) goto loc_8241DE80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241DE80;
	sub_82412710(ctx, base);
loc_8241DE80:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// li r10,25
	ctx.r10.s64 = 25;
	// ori r11,r11,17920
	r11.u64 = r11.u64 | 17920;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// stb r11,10943(r31)
	PPC_STORE_U8(r31.u32 + 10943, r11.u8);
loc_8241DEA4:
	// li r11,2
	r11.s64 = 2;
	// stb r11,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r11.u8);
	// b 0x8241e07c
	goto loc_8241E07C;
loc_8241DEB0:
	// clrlwi. r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241e07c
	if (cr0.eq) goto loc_8241E07C;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x8241e074
	if (cr6.eq) goto loc_8241E074;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// bne cr6,0x8241e008
	if (!cr6.eq) goto loc_8241E008;
	// lwz r11,148(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 148);
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r11,r29
	r30.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// beq cr6,0x8241dfdc
	if (cr6.eq) goto loc_8241DFDC;
	// lbz r11,20(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 20);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241dfdc
	if (!cr0.eq) goto loc_8241DFDC;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241df0c
	if (!cr6.gt) goto loc_8241DF0C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241DF0C;
	sub_82412710(ctx, base);
loc_8241DF0C:
	// addi r10,r30,16
	ctx.r10.s64 = r30.s64 + 16;
	// lis r11,-16383
	r11.s64 = -1073676288;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// ori r11,r11,15616
	r11.u64 = r11.u64 | 15616;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,-275
	r11.s64 = -275;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// ori r7,r10,2
	ctx.r7.u64 = ctx.r10.u64 | 2;
	// addi r10,r30,20
	ctx.r10.s64 = r30.s64 + 20;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// lis r6,-16383
	ctx.r6.s64 = -1073676288;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// ori r6,r6,15616
	ctx.r6.u64 = ctx.r6.u64 | 15616;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lis r9,-16380
	ctx.r9.s64 = -1073479680;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// ori r9,r9,15360
	ctx.r9.u64 = ctx.r9.u64 | 15360;
	// li r6,19
	ctx.r6.s64 = 19;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r30,256
	r30.s64 = 256;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// lis r27,-16380
	r27.s64 = -1073479680;
	// li r26,19
	r26.s64 = 19;
	// ori r27,r27,15360
	r27.u64 = r27.u64 | 15360;
	// li r25,256
	r25.s64 = 256;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r30,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r3.u32 = ea;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// b 0x8241dff4
	goto loc_8241DFF4;
loc_8241DFDC:
	// lbz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 20);
	// li r11,-275
	r11.s64 = -275;
	// clrlwi r10,r10,25
	ctx.r10.u64 = ctx.r10.u32 & 0x7F;
	// stb r10,20(r29)
	PPC_STORE_U8(r29.u32 + 20, ctx.r10.u8);
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
loc_8241DFF4:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824302f0
	ctx.lr = 0x8241E004;
	sub_824302F0(ctx, base);
	// b 0x8241e06c
	goto loc_8241E06C;
loc_8241E008:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x8241e06c
	if (!cr6.eq) goto loc_8241E06C;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241e028
	if (!cr6.gt) goto loc_8241E028;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241E028;
	sub_82412710(ctx, base);
loc_8241E028:
	// lis r11,-16383
	r11.s64 = -1073676288;
	// li r10,26
	ctx.r10.s64 = 26;
	// ori r11,r11,23040
	r11.u64 = r11.u64 | 23040;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// rlwinm r10,r10,0,3,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1FFFFFFE;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,10943(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// clrlwi r11,r11,25
	r11.u64 = r11.u32 & 0x7F;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// stb r11,10943(r31)
	PPC_STORE_U8(r31.u32 + 10943, r11.u8);
loc_8241E06C:
	// li r11,1
	r11.s64 = 1;
	// stb r11,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r11.u8);
loc_8241E074:
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// stw r11,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r11.u32);
loc_8241E07C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8241E084"))) PPC_WEAK_FUNC(sub_8241E084);
PPC_FUNC_IMPL(__imp__sub_8241E084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241E088"))) PPC_WEAK_FUNC(sub_8241E088);
PPC_FUNC_IMPL(__imp__sub_8241E088) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8241E090;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// bne cr6,0x8241e2b0
	if (!cr6.eq) goto loc_8241E2B0;
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8241e110
	if (cr6.eq) goto loc_8241E110;
	// lwz r10,10896(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10896);
	// lwz r9,10908(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10908);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bge cr6,0x8241e110
	if (!cr6.lt) goto loc_8241E110;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8241e0e8
	if (!cr6.eq) goto loc_8241E0E8;
	// bl 0x82412710
	ctx.lr = 0x8241E0E8;
	sub_82412710(ctx, base);
loc_8241E0E8:
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r22,16
	cr6.compare<uint32_t>(r22.u32, 16, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// blt cr6,0x8241e108
	if (cr6.lt) goto loc_8241E108;
	// li r24,0
	r24.s64 = 0;
loc_8241E0FC:
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// stw r24,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r24.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_8241E108:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8241e420
	goto loc_8241E420;
loc_8241E110:
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r22,16
	cr6.compare<uint32_t>(r22.u32, 16, xer);
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
	// blt cr6,0x8241e12c
	if (cr6.lt) goto loc_8241E12C;
	// stw r24,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r24.u32);
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// stw r24,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r24.u32);
loc_8241E12C:
	// lwz r23,148(r26)
	r23.u64 = PPC_LOAD_U32(r26.u32 + 148);
	// mr r25,r24
	r25.u64 = r24.u64;
	// addi r27,r26,28
	r27.s64 = r26.s64 + 28;
loc_8241E138:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addis r11,r11,-16384
	r11.s64 = r11.s64 + -1073741824;
	// dcbf r0,r11
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r8,r11,48
	ctx.r8.s64 = r11.s64 + 48;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r7,r11,52
	ctx.r7.s64 = r11.s64 + 52;
	// rlwinm r6,r9,8,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r4,r10,8,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// rlwimi r6,r9,24,16,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r9.u32, 24) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// lwbrx r8,0,r8
	ctx.r8.u64 = __builtin_bswap32(PPC_LOAD_U32(ctx.r8.u32));
	// rlwimi r4,r10,24,16,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// lwbrx r7,0,r7
	ctx.r7.u64 = __builtin_bswap32(PPC_LOAD_U32(ctx.r7.u32));
	// rlwimi r6,r9,8,8,15
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF0000) | (ctx.r6.u64 & 0xFFFFFFFFFF00FFFF);
	// subf r8,r8,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r8.s64;
	// rlwimi r6,r9,24,0,7
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r9.u32, 24) & 0xFF000000) | (ctx.r6.u64 & 0xFFFFFFFF00FFFFFF);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// rlwimi r4,r10,8,8,15
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF0000) | (ctx.r4.u64 & 0xFFFFFFFFFF00FFFF);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// rlwimi r4,r10,24,0,7
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r4.u64 & 0xFFFFFFFF00FFFFFF);
	// cmplwi cr6,r22,16
	cr6.compare<uint32_t>(r22.u32, 16, xer);
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// blt cr6,0x8241e254
	if (cr6.lt) goto loc_8241E254;
	// addi r7,r11,40
	ctx.r7.s64 = r11.s64 + 40;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r30,r11,32
	r30.s64 = r11.s64 + 32;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r11,56
	ctx.r5.s64 = r11.s64 + 56;
	// lwz r29,12(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r28,r11,44
	r28.s64 = r11.s64 + 44;
	// lwbrx r8,0,r11
	ctx.r8.u64 = __builtin_bswap32(PPC_LOAD_U32(r11.u32));
	// addi r19,r11,12
	r19.s64 = r11.s64 + 12;
	// addi r21,r11,60
	r21.s64 = r11.s64 + 60;
	// lwbrx r7,0,r7
	ctx.r7.u64 = __builtin_bswap32(PPC_LOAD_U32(ctx.r7.u32));
	// addi r20,r11,36
	r20.s64 = r11.s64 + 36;
	// lwbrx r18,0,r30
	r18.u64 = __builtin_bswap32(PPC_LOAD_U32(r30.u32));
	// lwbrx r5,0,r5
	ctx.r5.u64 = __builtin_bswap32(PPC_LOAD_U32(ctx.r5.u32));
	// addi r30,r11,28
	r30.s64 = r11.s64 + 28;
	// addi r17,r11,4
	r17.s64 = r11.s64 + 4;
	// lwbrx r16,0,r28
	r16.u64 = __builtin_bswap32(PPC_LOAD_U32(r28.u32));
	// subf r6,r7,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r7.s64;
	// lwbrx r7,0,r19
	ctx.r7.u64 = __builtin_bswap32(PPC_LOAD_U32(r19.u32));
	// addi r15,r11,8
	r15.s64 = r11.s64 + 8;
	// lwbrx r21,0,r21
	r21.u64 = __builtin_bswap32(PPC_LOAD_U32(r21.u32));
	// addi r14,r11,24
	r14.s64 = r11.s64 + 24;
	// lwbrx r20,0,r20
	r20.u64 = __builtin_bswap32(PPC_LOAD_U32(r20.u32));
	// subf r11,r5,r4
	r11.s64 = ctx.r4.s64 - ctx.r5.s64;
	// lwbrx r30,0,r30
	r30.u64 = __builtin_bswap32(PPC_LOAD_U32(r30.u32));
	// subf r19,r18,r29
	r19.s64 = r29.s64 - r18.s64;
	// lwbrx r28,0,r17
	r28.u64 = __builtin_bswap32(PPC_LOAD_U32(r17.u32));
	// subf r29,r21,r11
	r29.s64 = r11.s64 - r21.s64;
	// subf r5,r16,r6
	ctx.r5.s64 = ctx.r6.s64 - r16.s64;
	// lwbrx r4,0,r15
	ctx.r4.u64 = __builtin_bswap32(PPC_LOAD_U32(r15.u32));
	// subf r11,r20,r19
	r11.s64 = r19.s64 - r20.s64;
	// lwbrx r6,0,r14
	ctx.r6.u64 = __builtin_bswap32(PPC_LOAD_U32(r14.u32));
	// add r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r7,r29,r30
	ctx.r7.u64 = r29.u64 + r30.u64;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_8241E254:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmplw cr6,r25,r23
	cr6.compare<uint32_t>(r25.u32, r23.u32, xer);
	// blt cr6,0x8241e138
	if (cr6.lt) goto loc_8241E138;
	// lbz r8,10941(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10941);
	// li r11,1
	r11.s64 = 1;
	// rlwinm. r8,r8,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8241e280
	if (cr0.eq) goto loc_8241E280;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
loc_8241E280:
	// cmpwi cr6,r10,-275
	cr6.compare<int32_t>(ctx.r10.s32, -275, xer);
	// bne cr6,0x8241e2a0
	if (!cr6.eq) goto loc_8241E2A0;
	// cmpwi cr6,r9,-275
	cr6.compare<int32_t>(ctx.r9.s32, -275, xer);
	// bne cr6,0x8241e2a0
	if (!cr6.eq) goto loc_8241E2A0;
	// cmplwi cr6,r22,16
	cr6.compare<uint32_t>(r22.u32, 16, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// blt cr6,0x8241e108
	if (cr6.lt) goto loc_8241E108;
	// b 0x8241e0fc
	goto loc_8241E0FC;
loc_8241E2A0:
	// lbz r11,20(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 20);
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// stb r11,20(r26)
	PPC_STORE_U8(r26.u32 + 20, r11.u8);
	// b 0x8241e41c
	goto loc_8241E41C;
loc_8241E2B0:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x8241e3ec
	if (!cr6.eq) goto loc_8241E3EC;
	// lbz r11,10941(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10941);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241e2d8
	if (cr0.eq) goto loc_8241E2D8;
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8241E2D4;
	sub_823D9890(ctx, base);
	// b 0x8241e41c
	goto loc_8241E41C;
loc_8241E2D8:
	// lwz r10,10896(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10896);
	// lwz r9,10908(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10908);
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bge cr6,0x8241e30c
	if (!cr6.lt) goto loc_8241E30C;
loc_8241E2F8:
	// lwz r10,10908(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10908);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8241e108
	if (!cr6.eq) goto loc_8241E108;
	// bl 0x82412710
	ctx.lr = 0x8241E308;
	sub_82412710(ctx, base);
	// b 0x8241e108
	goto loc_8241E108;
loc_8241E30C:
	// lwz r10,28(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 28);
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addis r30,r11,-16384
	r30.s64 = r11.s64 + -1073741824;
	// dcbf r0,r30
	// lhz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// lhz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r7,10376(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10376);
	// rotlwi r9,r9,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// rotlwi r8,r8,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// clrlwi r10,r7,31
	ctx.r10.u64 = ctx.r7.u32 & 0x1;
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x8241e3a4
	if (!cr6.eq) goto loc_8241E3A4;
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// rlwinm r3,r11,21,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0xFFFFFFE0;
	// bl 0x8241da70
	ctx.lr = 0x8241E388;
	sub_8241DA70(ctx, base);
	// lhz r11,10(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// rlwinm r3,r11,21,0,10
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0xFFE00000;
	// bl 0x8241da70
	ctx.lr = 0x8241E3A0;
	sub_8241DA70(ctx, base);
	// b 0x8241e41c
	goto loc_8241E41C;
loc_8241E3A4:
	// lhz r11,10(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// lhz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r10,r10,13
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 13);
	// rlwinm r11,r11,13,0,18
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0xFFFFE000;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	f0.f64 = double(float(f0.f64));
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// frsp f0,f13
	f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// b 0x8241e41c
	goto loc_8241E41C;
loc_8241E3EC:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x8241e41c
	if (!cr6.eq) goto loc_8241E41C;
	// li r11,1
	r11.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,10896(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10896);
	// lwz r9,10908(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10908);
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// blt cr6,0x8241e2f8
	if (cr6.lt) goto loc_8241E2F8;
loc_8241E41C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8241E420:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8241E428"))) PPC_WEAK_FUNC(sub_8241E428);
PPC_FUNC_IMPL(__imp__sub_8241E428) {
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
	// lwz r11,10916(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10916);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwimi r11,r4,12,18,19
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 12) & 0x3000) | (r11.u64 & 0xFFFFFFFFFFFFCFFF);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// stw r11,10916(r31)
	PPC_STORE_U32(r31.u32 + 10916, r11.u32);
	// ble cr6,0x8241e460
	if (!cr6.gt) goto loc_8241E460;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241E460;
	sub_82412710(ctx, base);
loc_8241E460:
	// li r11,1480
	r11.s64 = 1480;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,3841
	r11.s64 = 3841;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10916(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10916);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8241E498"))) PPC_WEAK_FUNC(sub_8241E498);
PPC_FUNC_IMPL(__imp__sub_8241E498) {
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
	// lbz r11,10942(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// beq cr6,0x8241e550
	if (cr6.eq) goto loc_8241E550;
	// bl 0x82412990
	ctx.lr = 0x8241E4C8;
	sub_82412990(ctx, base);
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// bl 0x827bd714
	ctx.lr = 0x8241E4D4;
	__imp__VdEnableDisableClockGating(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8241e550
	if (!cr6.eq) goto loc_8241E550;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241e4f4
	if (!cr6.gt) goto loc_8241E4F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241E4F4;
	sub_82412710(ctx, base);
loc_8241E4F4:
	// lis r11,-16382
	r11.s64 = -1073610752;
	// li r10,129
	ctx.r10.s64 = 129;
	// ori r9,r11,8448
	ctx.r9.u64 = r11.u64 | 8448;
	// li r11,-1
	r11.s64 = -1;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// lis r11,-16382
	r11.s64 = -1073610752;
	// li r6,130
	ctx.r6.s64 = 130;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// ori r5,r11,8448
	ctx.r5.u64 = r11.u64 | 8448;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12244(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12244);
	// oris r11,r11,32769
	r11.u64 = r11.u64 | 2147549184;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12248(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12248);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
loc_8241E550:
	// addi r11,r30,-1
	r11.s64 = r30.s64 + -1;
	// lbz r10,10942(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwimi r10,r11,27,31,31
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 27) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// stb r10,10942(r31)
	PPC_STORE_U8(r31.u32 + 10942, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8241E57C"))) PPC_WEAK_FUNC(sub_8241E57C);
PPC_FUNC_IMPL(__imp__sub_8241E57C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241E580"))) PPC_WEAK_FUNC(sub_8241E580);
PPC_FUNC_IMPL(__imp__sub_8241E580) {
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
	ctx.lr = 0x8241E588;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8241e5bc
	if (!cr6.eq) goto loc_8241E5BC;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130b50
	ctx.lr = 0x8241E5AC;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8241e5bc
	if (!cr0.eq) goto loc_8241E5BC;
loc_8241E5B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8241e5f0
	goto loc_8241E5F0;
loc_8241E5BC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8241e5f8
	if (cr6.eq) goto loc_8241E5F8;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_8241E5C8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r3,480
	ctx.r4.s64 = ctx.r3.s64 + 480;
	// bl 0x82425cd8
	ctx.lr = 0x8241E5D8;
	sub_82425CD8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
loc_8241E5F0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8241E5F8:
	// lis r4,-23936
	ctx.r4.s64 = -1568669696;
	// li r3,480
	ctx.r3.s64 = 480;
	// bl 0x82130b50
	ctx.lr = 0x8241E604;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// bne 0x8241e5c8
	if (!cr0.eq) goto loc_8241E5C8;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x8241E61C;
	sub_821310F8(ctx, base);
	// b 0x8241e5b4
	goto loc_8241E5B4;
}

__attribute__((alias("__imp__sub_8241E620"))) PPC_WEAK_FUNC(sub_8241E620);
PPC_FUNC_IMPL(__imp__sub_8241E620) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91dc
	ctx.lr = 0x8241E628;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,120
	ctx.r4.s64 = 120;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82412928
	ctx.lr = 0x8241E63C;
	sub_82412928(ctx, base);
	// li r11,486
	r11.s64 = 486;
	// lbz r10,3(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// li r9,917
	ctx.r9.s64 = 917;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r7,918
	ctx.r7.s64 = 918;
	// rlwinm r8,r10,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// li r11,3528
	r11.s64 = 3528;
	// li r6,3529
	ctx.r6.s64 = 3529;
	// li r5,3530
	ctx.r5.s64 = 3530;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// li r4,3531
	ctx.r4.s64 = 3531;
	// lbz r27,7(r30)
	r27.u64 = PPC_LOAD_U8(r30.u32 + 7);
	// li r29,3144
	r29.s64 = 3144;
	// li r28,3145
	r28.s64 = 3145;
	// or r8,r27,r8
	ctx.r8.u64 = r27.u64 | ctx.r8.u64;
	// li r10,3146
	ctx.r10.s64 = 3146;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r25,r8,0,0,23
	r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF00;
	// li r26,3147
	r26.s64 = 3147;
	// li r27,3656
	r27.s64 = 3656;
	// li r24,3659
	r24.s64 = 3659;
	// li r9,3662
	ctx.r9.s64 = 3662;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// li r23,3665
	r23.s64 = 3665;
	// lbz r8,11(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 11);
	// li r22,3208
	r22.s64 = 3208;
	// or r8,r8,r25
	ctx.r8.u64 = ctx.r8.u64 | r25.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r25,r8,0,0,23
	r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lbz r8,15(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 15);
	// or r8,r8,r25
	ctx.r8.u64 = ctx.r8.u64 | r25.u64;
	// li r25,4100
	r25.s64 = 4100;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r8,0,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lbz r11,19(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 19);
	// or r11,r11,r7
	r11.u64 = r11.u64 | ctx.r7.u64;
	// li r7,3209
	ctx.r7.s64 = 3209;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,23(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 23);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r5,3224
	ctx.r5.s64 = 3224;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,27(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 27);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r4,3225
	ctx.r4.s64 = 3225;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,31(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 31);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stwu r29,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r29,3226
	r29.s64 = 3226;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,35(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 35);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r28,3227
	r28.s64 = 3227;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,39(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 39);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// li r8,3210
	ctx.r8.s64 = 3210;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// rlwinm r6,r11,0,0,23
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r10,3211
	ctx.r10.s64 = 3211;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,43(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 43);
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// rlwinm r6,r11,0,0,23
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r26,3677
	r26.s64 = 3677;
	// lbz r11,47(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 47);
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// rlwinm r6,r11,0,0,23
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,51(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 51);
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// rlwinm r6,r11,0,0,23
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,55(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 55);
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r6,r11,0,0,23
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,59(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 59);
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// li r6,3668
	ctx.r6.s64 = 3668;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r11,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,63(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 63);
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r11,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,67(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 67);
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r11,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r7,3592
	ctx.r7.s64 = 3592;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,71(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 71);
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r11,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r8,3589
	ctx.r8.s64 = 3589;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,75(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 75);
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r11,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,79(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 79);
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// li r9,4103
	ctx.r9.s64 = 4103;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r5,3671
	ctx.r5.s64 = 3671;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,3674
	r11.s64 = 3674;
	// lbz r27,83(r30)
	r27.u64 = PPC_LOAD_U8(r30.u32 + 83);
	// or r10,r27,r10
	ctx.r10.u64 = r27.u64 | ctx.r10.u64;
	// li r27,3680
	r27.s64 = 3680;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r24,r10,0,0,23
	r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,87(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 87);
	// or r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 | r24.u64;
	// stwu r29,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r3.u32 = ea;
	// rlwinm r4,r10,0,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,91(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 91);
	// or r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r4,r10,0,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,95(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 95);
	// or r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// rlwinm r4,r10,0,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,99(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 99);
	// or r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r4,r10,0,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,103(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 103);
	// or r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// li r8,3686
	ctx.r8.s64 = 3686;
	// li r4,3698
	ctx.r4.s64 = 3698;
	// li r29,3701
	r29.s64 = 3701;
	// li r28,3704
	r28.s64 = 3704;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,107(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 107);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,111(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 111);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// li r6,3692
	ctx.r6.s64 = 3692;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,115(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 115);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// li r5,3695
	ctx.r5.s64 = 3695;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,119(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 119);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// li r11,3683
	r11.s64 = 3683;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,123(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 123);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// li r9,3689
	ctx.r9.s64 = 3689;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r10,0,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,127(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 127);
	// or r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 | ctx.r7.u64;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r10,0,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r10,131(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 131);
	// or r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 | ctx.r7.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r10,0,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lbz r11,135(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 135);
	// or r11,r11,r7
	r11.u64 = r11.u64 | ctx.r7.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,139(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 139);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,143(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 143);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,147(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 147);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,151(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 151);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,155(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 155);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r29,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,159(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 159);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r9,3707
	ctx.r9.s64 = 3707;
	// lbz r11,163(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 163);
	// li r8,3618
	ctx.r8.s64 = 3618;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// li r10,3615
	ctx.r10.s64 = 3615;
	// rlwinm r9,r11,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// li r7,3624
	ctx.r7.s64 = 3624;
	// li r6,3627
	ctx.r6.s64 = 3627;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r5,3633
	ctx.r5.s64 = 3633;
	// lbz r4,167(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 167);
	// li r11,3636
	r11.s64 = 3636;
	// li r29,3642
	r29.s64 = 3642;
	// or r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 | ctx.r9.u64;
	// li r4,3645
	ctx.r4.s64 = 3645;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// rlwinm r28,r9,0,0,23
	r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF00;
	// li r27,3540
	r27.s64 = 3540;
	// li r10,3844
	ctx.r10.s64 = 3844;
	// li r26,3845
	r26.s64 = 3845;
	// li r25,3846
	r25.s64 = 3846;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// li r24,3847
	r24.s64 = 3847;
	// lbz r21,171(r30)
	r21.u64 = PPC_LOAD_U8(r30.u32 + 171);
	// li r23,2069
	r23.s64 = 2069;
	// li r22,2133
	r22.s64 = 2133;
	// or r28,r21,r28
	r28.u64 = r21.u64 | r28.u64;
	// li r9,2584
	ctx.r9.s64 = 2584;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r21,r28,0,0,23
	r21.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// lbz r8,175(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 175);
	// or r8,r8,r21
	ctx.r8.u64 = ctx.r8.u64 | r21.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r28,r8,0,0,23
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lbz r8,179(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 179);
	// or r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 | r28.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r8,0,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF00;
	// li r6,2590
	ctx.r6.s64 = 2590;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lbz r8,183(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 183);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r8,0,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF00;
	// li r5,72
	ctx.r5.s64 = 72;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lbz r8,187(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 187);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r8,0,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lbz r11,191(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 191);
	// or r11,r11,r7
	r11.u64 = r11.u64 | ctx.r7.u64;
	// li r7,2587
	ctx.r7.s64 = 2587;
	// stwu r29,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,195(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 195);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,199(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 199);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,203(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 203);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,207(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 207);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,211(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 211);
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,215(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 215);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,219(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 219);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,223(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 223);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,227(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 227);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,231(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 231);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,235(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 235);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lbz r11,239(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 239);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// ble cr6,0x8241ebec
	if (!cr6.gt) goto loc_8241EBEC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8241EBEC;
	sub_82412710(ctx, base);
loc_8241EBEC:
	// li r11,501
	r11.s64 = 501;
	// li r10,0
	ctx.r10.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,8697
	r11.s64 = 8697;
	// li r9,23
	ctx.r9.s64 = 23;
	// li r8,501
	ctx.r8.s64 = 501;
	// li r7,1
	ctx.r7.s64 = 1;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8241EC28"))) PPC_WEAK_FUNC(sub_8241EC28);
PPC_FUNC_IMPL(__imp__sub_8241EC28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8241ec38
	if (!cr6.eq) goto loc_8241EC38;
	// blr 
	return;
loc_8241EC38:
	// b 0x82412848
	sub_82412848(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8241EC3C"))) PPC_WEAK_FUNC(sub_8241EC3C);
PPC_FUNC_IMPL(__imp__sub_8241EC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8241EC40"))) PPC_WEAK_FUNC(sub_8241EC40);
PPC_FUNC_IMPL(__imp__sub_8241EC40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8241EC48;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,156
	ctx.r3.s64 = 156;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82130b50
	ctx.lr = 0x8241EC64;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8241ec74
	if (!cr0.eq) goto loc_8241EC74;
loc_8241EC6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8241ed28
	goto loc_8241ED28;
loc_8241EC74:
	// li r26,1
	r26.s64 = 1;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// stw r26,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r26.u32);
	// stw r26,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r26.u32);
	// stw r29,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r29.u32);
	// beq cr6,0x8241ed14
	if (cr6.eq) goto loc_8241ED14;
	// cmpwi cr6,r30,9
	cr6.compare<int32_t>(r30.s32, 9, xer);
	// beq cr6,0x8241ecc4
	if (cr6.eq) goto loc_8241ECC4;
	// cmpwi cr6,r30,10
	cr6.compare<int32_t>(r30.s32, 10, xer);
	// bne cr6,0x8241ed24
	if (!cr6.eq) goto loc_8241ED24;
	// addi r5,r31,28
	ctx.r5.s64 = r31.s64 + 28;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8241db70
	ctx.lr = 0x8241ECB4;
	sub_8241DB70(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8241ed08
	if (cr0.lt) goto loc_8241ED08;
loc_8241ECBC:
	// stb r26,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r26.u8);
	// b 0x8241ed24
	goto loc_8241ED24;
loc_8241ECC4:
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8241ecbc
	if (cr6.eq) goto loc_8241ECBC;
	// addi r30,r31,88
	r30.s64 = r31.s64 + 88;
loc_8241ECD4:
	// addi r5,r30,-60
	ctx.r5.s64 = r30.s64 + -60;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8241db70
	ctx.lr = 0x8241ECE4;
	sub_8241DB70(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8241ed04
	if (cr0.lt) goto loc_8241ED04;
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x8241ecd4
	if (cr6.lt) goto loc_8241ECD4;
	// b 0x8241ecbc
	goto loc_8241ECBC;
loc_8241ED04:
	// stw r28,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r28.u32);
loc_8241ED08:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241dc98
	ctx.lr = 0x8241ED10;
	sub_8241DC98(ctx, base);
	// b 0x8241ec6c
	goto loc_8241EC6C;
loc_8241ED14:
	// lwz r11,10908(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 10908);
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
loc_8241ED24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8241ED28:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8241ED30"))) PPC_WEAK_FUNC(sub_8241ED30);
PPC_FUNC_IMPL(__imp__sub_8241ED30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91d4
	ctx.lr = 0x8241ED38;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8241ed58
	if (cr6.eq) goto loc_8241ED58;
	// bl 0x82412158
	ctx.lr = 0x8241ED58;
	sub_82412158(ctx, base);
loc_8241ED58:
	// clrlwi. r11,r31,31
	r11.u64 = r31.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241ed90
	if (cr0.eq) goto loc_8241ED90;
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lwz r3,48(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8241ed78
	if (!cr6.gt) goto loc_8241ED78;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82412710
	ctx.lr = 0x8241ED78;
	sub_82412710(ctx, base);
loc_8241ED78:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,9728
	r11.u64 = r11.u64 | 9728;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r3.u32);
loc_8241ED90:
	// li r4,360
	ctx.r4.s64 = 360;
	// lwz r31,4(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82412928
	ctx.lr = 0x8241EDA0;
	sub_82412928(ctx, base);
	// lis r11,-16383
	r11.s64 = -1073676288;
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// ori r11,r11,15872
	r11.u64 = r11.u64 | 15872;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r8,487
	ctx.r8.s64 = 487;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// ori r8,r9,2
	ctx.r8.u64 = ctx.r9.u64 | 2;
	// rlwinm r10,r31,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 12) & 0xFFF;
	// li r6,488
	ctx.r6.s64 = 488;
	// addi r9,r10,512
	ctx.r9.s64 = ctx.r10.s64 + 512;
	// clrlwi r10,r31,3
	ctx.r10.u64 = r31.u32 & 0x1FFFFFFF;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r28,919
	r28.s64 = 919;
	// ori r4,r10,2
	ctx.r4.u64 = ctx.r10.u64 | 2;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,12
	ctx.r10.s64 = r31.s64 + 12;
	// li r27,920
	r27.s64 = 920;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,20
	ctx.r10.s64 = r31.s64 + 20;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// ori r8,r9,2
	ctx.r8.u64 = ctx.r9.u64 | 2;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r28,922
	r28.s64 = 922;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// li r6,3532
	ctx.r6.s64 = 3532;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r9,921
	ctx.r9.s64 = 921;
	// ori r26,r10,2
	r26.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,16
	ctx.r10.s64 = r31.s64 + 16;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// addi r10,r9,512
	ctx.r10.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// addi r10,r31,28
	ctx.r10.s64 = r31.s64 + 28;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,24
	ctx.r10.s64 = r31.s64 + 24;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// ori r4,r9,2
	ctx.r4.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r28,3533
	r28.s64 = 3533;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r27,r11
	r27.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r25,3534
	r25.s64 = 3534;
	// ori r26,r10,2
	r26.u64 = ctx.r10.u64 | 2;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,36
	ctx.r10.s64 = r31.s64 + 36;
	// mr r24,r11
	r24.u64 = r11.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// mr r23,r11
	r23.u64 = r11.u64;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// addi r9,r31,44
	ctx.r9.s64 = r31.s64 + 44;
	// addi r8,r8,512
	ctx.r8.s64 = ctx.r8.s64 + 512;
	// rlwinm r7,r9,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// clrlwi r10,r9,3
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// rlwinm r9,r7,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// li r4,3535
	ctx.r4.s64 = 3535;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// li r5,3536
	ctx.r5.s64 = 3536;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// mr r28,r11
	r28.u64 = r11.u64;
	// li r26,3538
	r26.s64 = 3538;
	// li r22,3539
	r22.s64 = 3539;
	// mr r21,r11
	r21.u64 = r11.u64;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// mr r25,r11
	r25.u64 = r11.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// ori r6,r10,2
	ctx.r6.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,40
	ctx.r10.s64 = r31.s64 + 40;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,52
	ctx.r10.s64 = r31.s64 + 52;
	// ori r27,r9,2
	r27.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// li r4,3537
	ctx.r4.s64 = 3537;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// ori r24,r10,2
	r24.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,60
	ctx.r10.s64 = r31.s64 + 60;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// addi r9,r31,56
	ctx.r9.s64 = r31.s64 + 56;
	// rlwinm r7,r10,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// rlwinm r6,r9,12,20,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// ori r23,r8,2
	r23.u64 = ctx.r8.u64 | 2;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// addi r6,r6,512
	ctx.r6.s64 = ctx.r6.s64 + 512;
	// addi r8,r31,68
	ctx.r8.s64 = r31.s64 + 68;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r7,r7,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r6,r6,0,19,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x1000;
	// rlwinm r5,r8,12,20,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFF;
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// addi r7,r5,512
	ctx.r7.s64 = ctx.r5.s64 + 512;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// ori r20,r9,2
	r20.u64 = ctx.r9.u64 | 2;
	// ori r4,r10,2
	ctx.r4.u64 = ctx.r10.u64 | 2;
	// rlwinm r9,r7,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// clrlwi r10,r8,3
	ctx.r10.u64 = ctx.r8.u32 & 0x1FFFFFFF;
	// li r6,3148
	ctx.r6.s64 = 3148;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// ori r7,r10,2
	ctx.r7.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,64
	ctx.r10.s64 = r31.s64 + 64;
	// li r28,3149
	r28.s64 = 3149;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// mr r27,r11
	r27.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// li r19,3150
	r19.s64 = 3150;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,76
	ctx.r10.s64 = r31.s64 + 76;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// li r26,3152
	r26.s64 = 3152;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// li r24,3153
	r24.s64 = 3153;
	// mr r23,r11
	r23.u64 = r11.u64;
	// li r22,3154
	r22.s64 = 3154;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// li r6,3151
	ctx.r6.s64 = 3151;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// ori r5,r9,2
	ctx.r5.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// mr r28,r11
	r28.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r25,r10,2
	r25.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,72
	ctx.r10.s64 = r31.s64 + 72;
	// stwu r20,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r20.u32);
	ctx.r3.u32 = ea;
	// li r20,3155
	r20.s64 = 3155;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,84
	ctx.r10.s64 = r31.s64 + 84;
	// ori r27,r9,2
	r27.u64 = ctx.r9.u64 | 2;
	// stwu r19,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r19.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r9,r10,2
	ctx.r9.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// li r7,3658
	ctx.r7.s64 = 3658;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// li r4,3657
	ctx.r4.s64 = 3657;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// mr r25,r11
	r25.u64 = r11.u64;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// li r27,3661
	r27.s64 = 3661;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,92
	ctx.r10.s64 = r31.s64 + 92;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r20,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r20.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,88
	ctx.r10.s64 = r31.s64 + 88;
	// ori r5,r9,2
	ctx.r5.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,100
	ctx.r10.s64 = r31.s64 + 100;
	// ori r7,r9,2
	ctx.r7.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,96
	ctx.r10.s64 = r31.s64 + 96;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// ori r26,r9,2
	r26.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// li r6,3660
	ctx.r6.s64 = 3660;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,108
	ctx.r10.s64 = r31.s64 + 108;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// li r7,3664
	ctx.r7.s64 = 3664;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// li r6,3663
	ctx.r6.s64 = 3663;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// ori r8,r10,2
	ctx.r8.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,104
	ctx.r10.s64 = r31.s64 + 104;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r4,3667
	ctx.r4.s64 = 3667;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,116
	ctx.r10.s64 = r31.s64 + 116;
	// ori r7,r9,2
	ctx.r7.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// li r26,3666
	r26.s64 = 3666;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r23,3212
	r23.s64 = 3212;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,112
	ctx.r10.s64 = r31.s64 + 112;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// ori r27,r9,2
	r27.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r22,3214
	r22.s64 = 3214;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,124
	ctx.r10.s64 = r31.s64 + 124;
	// ori r24,r9,2
	r24.u64 = ctx.r9.u64 | 2;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// addi r9,r31,120
	ctx.r9.s64 = r31.s64 + 120;
	// addi r7,r8,512
	ctx.r7.s64 = ctx.r8.s64 + 512;
	// rlwinm r6,r9,12,20,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r7,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// addi r6,r6,512
	ctx.r6.s64 = ctx.r6.s64 + 512;
	// addi r10,r31,132
	ctx.r10.s64 = r31.s64 + 132;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r6,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x1000;
	// rlwinm r7,r10,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r8,r7,512
	ctx.r8.s64 = ctx.r7.s64 + 512;
	// ori r27,r9,2
	r27.u64 = ctx.r9.u64 | 2;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r9,r8,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// ori r6,r5,2
	ctx.r6.u64 = ctx.r5.u64 | 2;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// ori r28,r10,2
	r28.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,128
	ctx.r10.s64 = r31.s64 + 128;
	// li r5,3213
	ctx.r5.s64 = 3213;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r26,3215
	r26.s64 = 3215;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,140
	ctx.r10.s64 = r31.s64 + 140;
	// li r24,3216
	r24.s64 = 3216;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// ori r5,r9,2
	ctx.r5.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// mr r27,r11
	r27.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// ori r23,r10,2
	r23.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,136
	ctx.r10.s64 = r31.s64 + 136;
	// li r4,3217
	ctx.r4.s64 = 3217;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// addi r10,r31,148
	ctx.r10.s64 = r31.s64 + 148;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r21,3219
	r21.s64 = 3219;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// addi r9,r31,144
	ctx.r9.s64 = r31.s64 + 144;
	// ori r22,r8,2
	r22.u64 = ctx.r8.u64 | 2;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// rlwinm r7,r9,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// addi r8,r8,512
	ctx.r8.s64 = ctx.r8.s64 + 512;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// mr r28,r11
	r28.u64 = r11.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// rlwinm r7,r7,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// ori r6,r10,2
	ctx.r6.u64 = ctx.r10.u64 | 2;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// addi r10,r31,156
	ctx.r10.s64 = r31.s64 + 156;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// li r8,3218
	ctx.r8.s64 = 3218;
	// ori r20,r9,2
	r20.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// mr r26,r11
	r26.u64 = r11.u64;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// li r5,3228
	ctx.r5.s64 = 3228;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// li r23,3231
	r23.s64 = 3231;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// li r27,3230
	r27.s64 = 3230;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r10,r9,512
	ctx.r10.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// addi r10,r31,152
	ctx.r10.s64 = r31.s64 + 152;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// li r7,3229
	ctx.r7.s64 = 3229;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// ori r28,r9,2
	r28.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r20,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r20.u32);
	ctx.r3.u32 = ea;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r24,r10,2
	r24.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,160
	ctx.r10.s64 = r31.s64 + 160;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,172
	ctx.r10.s64 = r31.s64 + 172;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// ori r5,r9,2
	ctx.r5.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r22,3232
	r22.s64 = 3232;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// ori r7,r10,2
	ctx.r7.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,168
	ctx.r10.s64 = r31.s64 + 168;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r28,3235
	r28.s64 = 3235;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,180
	ctx.r10.s64 = r31.s64 + 180;
	// li r6,3233
	ctx.r6.s64 = 3233;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// mr r27,r11
	r27.u64 = r11.u64;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// li r23,4105
	r23.s64 = 4105;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// li r5,3234
	ctx.r5.s64 = 3234;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// li r26,4102
	r26.s64 = 4102;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// mr r22,r11
	r22.u64 = r11.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// ori r8,r9,2
	ctx.r8.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r4,r10,2
	ctx.r4.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,176
	ctx.r10.s64 = r31.s64 + 176;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,188
	ctx.r10.s64 = r31.s64 + 188;
	// ori r7,r9,2
	ctx.r7.u64 = ctx.r9.u64 | 2;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// li r4,4101
	ctx.r4.s64 = 4101;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,184
	ctx.r10.s64 = r31.s64 + 184;
	// ori r25,r9,2
	r25.u64 = ctx.r9.u64 | 2;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r8,r8,512
	ctx.r8.s64 = ctx.r8.s64 + 512;
	// addi r9,r31,196
	ctx.r9.s64 = r31.s64 + 196;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r10,r9,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// ori r24,r8,2
	r24.u64 = ctx.r8.u64 | 2;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r10,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// addi r10,r31,192
	ctx.r10.s64 = r31.s64 + 192;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r28,3591
	r28.s64 = 3591;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,204
	ctx.r10.s64 = r31.s64 + 204;
	// li r21,3670
	r21.s64 = 3670;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// li r25,3590
	r25.s64 = 3590;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// li r5,4104
	ctx.r5.s64 = 4104;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// mr r24,r11
	r24.u64 = r11.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r26,r10,2
	r26.u64 = ctx.r10.u64 | 2;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,200
	ctx.r10.s64 = r31.s64 + 200;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,212
	ctx.r10.s64 = r31.s64 + 212;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r31,208
	ctx.r9.s64 = r31.s64 + 208;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// ori r23,r8,2
	r23.u64 = ctx.r8.u64 | 2;
	// rlwinm r7,r9,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// addi r8,r8,512
	ctx.r8.s64 = ctx.r8.s64 + 512;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// rlwinm r7,r7,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// addi r10,r31,220
	ctx.r10.s64 = r31.s64 + 220;
	// ori r4,r9,2
	ctx.r4.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// li r7,3594
	ctx.r7.s64 = 3594;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,216
	ctx.r10.s64 = r31.s64 + 216;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// li r5,3593
	ctx.r5.s64 = 3593;
	// li r28,3669
	r28.s64 = 3669;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// ori r8,r9,2
	ctx.r8.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// li r26,3673
	r26.s64 = 3673;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r25,3672
	r25.s64 = 3672;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// ori r27,r10,2
	r27.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,228
	ctx.r10.s64 = r31.s64 + 228;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r20,3675
	r20.s64 = 3675;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,224
	ctx.r10.s64 = r31.s64 + 224;
	// ori r4,r9,2
	ctx.r4.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// li r22,3676
	r22.s64 = 3676;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r21,r11
	r21.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// ori r23,r10,2
	r23.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,236
	ctx.r10.s64 = r31.s64 + 236;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// mr r28,r11
	r28.u64 = r11.u64;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// li r27,3682
	r27.s64 = 3682;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,232
	ctx.r10.s64 = r31.s64 + 232;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// addi r10,r31,244
	ctx.r10.s64 = r31.s64 + 244;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// rlwinm r7,r10,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// ori r5,r9,2
	ctx.r5.u64 = ctx.r9.u64 | 2;
	// stwu r20,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r20.u32);
	ctx.r3.u32 = ea;
	// addi r9,r7,512
	ctx.r9.s64 = ctx.r7.s64 + 512;
	// li r8,3679
	ctx.r8.s64 = 3679;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// li r5,3678
	ctx.r5.s64 = 3678;
	// ori r4,r10,2
	ctx.r4.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,240
	ctx.r10.s64 = r31.s64 + 240;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,252
	ctx.r10.s64 = r31.s64 + 252;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r26,r11
	r26.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// li r4,3681
	ctx.r4.s64 = 3681;
	// ori r25,r10,2
	r25.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,248
	ctx.r10.s64 = r31.s64 + 248;
	// li r24,3685
	r24.s64 = 3685;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,260
	ctx.r10.s64 = r31.s64 + 260;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r6,r10,2
	ctx.r6.u64 = ctx.r10.u64 | 2;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,256
	ctx.r10.s64 = r31.s64 + 256;
	// li r28,3688
	r28.s64 = 3688;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,268
	ctx.r10.s64 = r31.s64 + 268;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// mr r25,r11
	r25.u64 = r11.u64;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// li r26,3687
	r26.s64 = 3687;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// ori r4,r9,2
	ctx.r4.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r27,r10,2
	r27.u64 = ctx.r10.u64 | 2;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,264
	ctx.r10.s64 = r31.s64 + 264;
	// li r7,3684
	ctx.r7.s64 = 3684;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,276
	ctx.r10.s64 = r31.s64 + 276;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// ori r24,r9,2
	r24.u64 = ctx.r9.u64 | 2;
	// addi r9,r31,272
	ctx.r9.s64 = r31.s64 + 272;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r8,r8,512
	ctx.r8.s64 = ctx.r8.s64 + 512;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r9,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// rlwinm r8,r7,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// li r4,3691
	ctx.r4.s64 = 3691;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// ori r8,r10,2
	ctx.r8.u64 = ctx.r10.u64 | 2;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// li r5,3690
	ctx.r5.s64 = 3690;
	// ori r23,r9,2
	r23.u64 = ctx.r9.u64 | 2;
	// addi r10,r31,284
	ctx.r10.s64 = r31.s64 + 284;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// mr r28,r11
	r28.u64 = r11.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r22,3694
	r22.s64 = 3694;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,280
	ctx.r10.s64 = r31.s64 + 280;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// li r26,3697
	r26.s64 = 3697;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// li r24,3696
	r24.s64 = 3696;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// li r4,3693
	ctx.r4.s64 = 3693;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// ori r7,r9,2
	ctx.r7.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r27,r10,2
	r27.u64 = ctx.r10.u64 | 2;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,292
	ctx.r10.s64 = r31.s64 + 292;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,288
	ctx.r10.s64 = r31.s64 + 288;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// ori r28,r9,2
	r28.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// mr r22,r11
	r22.u64 = r11.u64;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,300
	ctx.r10.s64 = r31.s64 + 300;
	// add r23,r8,r9
	r23.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// addi r9,r31,296
	ctx.r9.s64 = r31.s64 + 296;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// addi r8,r8,512
	ctx.r8.s64 = ctx.r8.s64 + 512;
	// rlwinm r7,r9,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// ori r23,r23,2
	r23.u64 = r23.u64 | 2;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// clrlwi r10,r9,3
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// rlwinm r9,r7,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r6,3700
	ctx.r6.s64 = 3700;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// li r4,3699
	ctx.r4.s64 = 3699;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// ori r7,r10,2
	ctx.r7.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,308
	ctx.r10.s64 = r31.s64 + 308;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r5,3703
	ctx.r5.s64 = 3703;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,304
	ctx.r10.s64 = r31.s64 + 304;
	// ori r28,r9,2
	r28.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r8,3702
	ctx.r8.s64 = 3702;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r27,r11
	r27.u64 = r11.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,316
	ctx.r10.s64 = r31.s64 + 316;
	// ori r26,r9,2
	r26.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r25,3706
	r25.s64 = 3706;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,312
	ctx.r10.s64 = r31.s64 + 312;
	// ori r24,r9,2
	r24.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// li r7,3705
	ctx.r7.s64 = 3705;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r23,r11
	r23.u64 = r11.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,324
	ctx.r10.s64 = r31.s64 + 324;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// ori r22,r9,2
	r22.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r21,3709
	r21.s64 = 3709;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r6,3708
	ctx.r6.s64 = 3708;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r5,3617
	ctx.r5.s64 = 3617;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// ori r7,r10,2
	ctx.r7.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,320
	ctx.r10.s64 = r31.s64 + 320;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,332
	ctx.r10.s64 = r31.s64 + 332;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// ori r8,r9,2
	ctx.r8.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// ori r4,r10,2
	ctx.r4.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,328
	ctx.r10.s64 = r31.s64 + 328;
	// li r28,3616
	r28.s64 = 3616;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// li r27,3620
	r27.s64 = 3620;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,340
	ctx.r10.s64 = r31.s64 + 340;
	// ori r7,r9,2
	ctx.r7.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r25,3619
	r25.s64 = 3619;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// ori r26,r10,2
	r26.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,336
	ctx.r10.s64 = r31.s64 + 336;
	// li r24,3626
	r24.s64 = 3626;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r28,3629
	r28.s64 = 3629;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,348
	ctx.r10.s64 = r31.s64 + 348;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r10,r9,512
	ctx.r10.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// addi r10,r31,344
	ctx.r10.s64 = r31.s64 + 344;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r27,r11
	r27.u64 = r11.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,356
	ctx.r10.s64 = r31.s64 + 356;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// li r25,3628
	r25.s64 = 3628;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// li r6,3625
	ctx.r6.s64 = 3625;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// ori r4,r9,2
	ctx.r4.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// mr r24,r11
	r24.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r26,r10,2
	r26.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,352
	ctx.r10.s64 = r31.s64 + 352;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,364
	ctx.r10.s64 = r31.s64 + 364;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// addi r9,r31,360
	ctx.r9.s64 = r31.s64 + 360;
	// addi r8,r8,512
	ctx.r8.s64 = ctx.r8.s64 + 512;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r9,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r9,3
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// rlwinm r9,r7,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// li r4,3635
	ctx.r4.s64 = 3635;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// li r5,3634
	ctx.r5.s64 = 3634;
	// mr r28,r11
	r28.u64 = r11.u64;
	// li r22,3644
	r22.s64 = 3644;
	// mr r21,r11
	r21.u64 = r11.u64;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// li r26,3637
	r26.s64 = 3637;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// mr r25,r11
	r25.u64 = r11.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// ori r6,r10,2
	ctx.r6.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,372
	ctx.r10.s64 = r31.s64 + 372;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,368
	ctx.r10.s64 = r31.s64 + 368;
	// ori r27,r9,2
	r27.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// li r4,3638
	ctx.r4.s64 = 3638;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// ori r24,r10,2
	r24.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,380
	ctx.r10.s64 = r31.s64 + 380;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,376
	ctx.r10.s64 = r31.s64 + 376;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// addi r9,r31,388
	ctx.r9.s64 = r31.s64 + 388;
	// rlwinm r7,r10,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// rlwinm r6,r9,12,20,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// addi r6,r6,512
	ctx.r6.s64 = ctx.r6.s64 + 512;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// ori r23,r8,2
	r23.u64 = ctx.r8.u64 | 2;
	// addi r8,r31,384
	ctx.r8.s64 = r31.s64 + 384;
	// rlwinm r7,r7,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r6,r6,0,19,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x1000;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r5,r8,12,20,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r7,r5,512
	ctx.r7.s64 = ctx.r5.s64 + 512;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// li r6,3643
	ctx.r6.s64 = 3643;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// ori r4,r10,2
	ctx.r4.u64 = ctx.r10.u64 | 2;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// li r28,3647
	r28.s64 = 3647;
	// ori r20,r9,2
	r20.u64 = ctx.r9.u64 | 2;
	// mr r27,r11
	r27.u64 = r11.u64;
	// rlwinm r9,r7,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// clrlwi r10,r8,3
	ctx.r10.u64 = ctx.r8.u32 & 0x1FFFFFFF;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// li r19,3646
	r19.s64 = 3646;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// ori r7,r10,2
	ctx.r7.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,396
	ctx.r10.s64 = r31.s64 + 396;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// li r26,3545
	r26.s64 = 3545;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r24,3848
	r24.s64 = 3848;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r22,3849
	r22.s64 = 3849;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,392
	ctx.r10.s64 = r31.s64 + 392;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// mr r23,r11
	r23.u64 = r11.u64;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// li r6,3544
	ctx.r6.s64 = 3544;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// ori r5,r9,2
	ctx.r5.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r28,r11
	r28.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r25,r10,2
	r25.u64 = ctx.r10.u64 | 2;
	// stwu r20,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r20.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,404
	ctx.r10.s64 = r31.s64 + 404;
	// li r20,3850
	r20.s64 = 3850;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,400
	ctx.r10.s64 = r31.s64 + 400;
	// stwu r19,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r19.u32);
	ctx.r3.u32 = ea;
	// ori r27,r9,2
	r27.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r7,3851
	ctx.r7.s64 = 3851;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r9,r10,2
	ctx.r9.u64 = ctx.r10.u64 | 2;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,412
	ctx.r10.s64 = r31.s64 + 412;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,408
	ctx.r10.s64 = r31.s64 + 408;
	// stwu r20,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r20.u32);
	ctx.r3.u32 = ea;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r4,3852
	ctx.r4.s64 = 3852;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,420
	ctx.r10.s64 = r31.s64 + 420;
	// ori r5,r9,2
	ctx.r5.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r27,3853
	r27.s64 = 3853;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// mr r25,r11
	r25.u64 = r11.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,416
	ctx.r10.s64 = r31.s64 + 416;
	// ori r7,r9,2
	ctx.r7.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r6,3854
	ctx.r6.s64 = 3854;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,428
	ctx.r10.s64 = r31.s64 + 428;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// ori r26,r9,2
	r26.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r8,r9,512
	ctx.r8.s64 = ctx.r9.s64 + 512;
	// clrlwi r9,r10,3
	ctx.r9.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// addi r10,r31,424
	ctx.r10.s64 = r31.s64 + 424;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r7,3855
	ctx.r7.s64 = 3855;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// li r26,2135
	r26.s64 = 2135;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// li r6,2071
	ctx.r6.s64 = 2071;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// ori r8,r10,2
	ctx.r8.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,436
	ctx.r10.s64 = r31.s64 + 436;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// li r4,2070
	ctx.r4.s64 = 2070;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,432
	ctx.r10.s64 = r31.s64 + 432;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// ori r7,r9,2
	ctx.r7.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,444
	ctx.r10.s64 = r31.s64 + 444;
	// ori r27,r9,2
	r27.u64 = ctx.r9.u64 | 2;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r23,2134
	r23.s64 = 2134;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r31,440
	ctx.r10.s64 = r31.s64 + 440;
	// ori r24,r9,2
	r24.u64 = ctx.r9.u64 | 2;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// addi r9,r31,452
	ctx.r9.s64 = r31.s64 + 452;
	// addi r7,r8,512
	ctx.r7.s64 = ctx.r8.s64 + 512;
	// rlwinm r6,r9,12,20,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// rlwinm r7,r7,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// addi r6,r6,512
	ctx.r6.s64 = ctx.r6.s64 + 512;
	// addi r10,r31,448
	ctx.r10.s64 = r31.s64 + 448;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r6,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x1000;
	// rlwinm r7,r10,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r8,r7,512
	ctx.r8.s64 = ctx.r7.s64 + 512;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// ori r27,r9,2
	r27.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r8,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// ori r6,r5,2
	ctx.r6.u64 = ctx.r5.u64 | 2;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// ori r28,r10,2
	r28.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,460
	ctx.r10.s64 = r31.s64 + 460;
	// li r5,2586
	ctx.r5.s64 = 2586;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// li r22,2585
	r22.s64 = 2585;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// addi r10,r31,456
	ctx.r10.s64 = r31.s64 + 456;
	// li r26,2589
	r26.s64 = 2589;
	// li r24,2588
	r24.s64 = 2588;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// ori r5,r9,2
	ctx.r5.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// mr r27,r11
	r27.u64 = r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r23,r10,2
	r23.u64 = ctx.r10.u64 | 2;
	// addi r10,r31,468
	ctx.r10.s64 = r31.s64 + 468;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// li r4,2592
	ctx.r4.s64 = 2592;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// addi r10,r31,464
	ctx.r10.s64 = r31.s64 + 464;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r31,476
	ctx.r9.s64 = r31.s64 + 476;
	// ori r22,r8,2
	r22.u64 = ctx.r8.u64 | 2;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// rlwinm r8,r10,12,20,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// rlwinm r7,r9,12,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// addi r8,r8,512
	ctx.r8.s64 = ctx.r8.s64 + 512;
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// mr r28,r11
	r28.u64 = r11.u64;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r8,r8,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// li r8,2591
	ctx.r8.s64 = 2591;
	// ori r6,r10,2
	ctx.r6.u64 = ctx.r10.u64 | 2;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// rlwinm r7,r7,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// li r21,74
	r21.s64 = 74;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// ori r9,r9,2
	ctx.r9.u64 = ctx.r9.u64 | 2;
	// mr r26,r11
	r26.u64 = r11.u64;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// addi r11,r31,472
	r11.s64 = r31.s64 + 472;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	r11.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// li r8,73
	ctx.r8.s64 = 73;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10908(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10908);
	// stw r3,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r3.u32);
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_824203B8"))) PPC_WEAK_FUNC(sub_824203B8);
PPC_FUNC_IMPL(__imp__sub_824203B8) {
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
	ctx.lr = 0x824203C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824203e0
	if (cr6.eq) goto loc_824203E0;
	// bl 0x82412158
	ctx.lr = 0x824203E0;
	sub_82412158(ctx, base);
loc_824203E0:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,480
	ctx.r5.s64 = 480;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x824203F4;
	sub_823DA950(ctx, base);
	// addi r4,r31,480
	ctx.r4.s64 = r31.s64 + 480;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82425cd8
	ctx.lr = 0x82420404;
	sub_82425CD8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82420418
	if (cr6.eq) goto loc_82420418;
	// lis r11,10922
	r11.s64 = 715784192;
	// ori r11,r11,43690
	r11.u64 = r11.u64 | 43690;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_82420418:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82420424"))) PPC_WEAK_FUNC(sub_82420424);
PPC_FUNC_IMPL(__imp__sub_82420424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82420428"))) PPC_WEAK_FUNC(sub_82420428);
PPC_FUNC_IMPL(__imp__sub_82420428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,30
	cr6.compare<uint32_t>(ctx.r3.u32, 30, xer);
	// beq cr6,0x8242046c
	if (cr6.eq) goto loc_8242046C;
	// cmplwi cr6,r3,31
	cr6.compare<uint32_t>(ctx.r3.u32, 31, xer);
	// beq cr6,0x8242046c
	if (cr6.eq) goto loc_8242046C;
	// cmplwi cr6,r3,32
	cr6.compare<uint32_t>(ctx.r3.u32, 32, xer);
	// beq cr6,0x8242046c
	if (cr6.eq) goto loc_8242046C;
	// cmplwi cr6,r3,36
	cr6.compare<uint32_t>(ctx.r3.u32, 36, xer);
	// beq cr6,0x8242046c
	if (cr6.eq) goto loc_8242046C;
	// cmplwi cr6,r3,37
	cr6.compare<uint32_t>(ctx.r3.u32, 37, xer);
	// beq cr6,0x8242046c
	if (cr6.eq) goto loc_8242046C;
	// cmplwi cr6,r3,38
	cr6.compare<uint32_t>(ctx.r3.u32, 38, xer);
	// beq cr6,0x8242046c
	if (cr6.eq) goto loc_8242046C;
	// cmplwi cr6,r3,57
	cr6.compare<uint32_t>(ctx.r3.u32, 57, xer);
	// beq cr6,0x8242046c
	if (cr6.eq) goto loc_8242046C;
	// cmplwi cr6,r3,63
	cr6.compare<uint32_t>(ctx.r3.u32, 63, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bnelr cr6
	if (!cr6.eq) return;
loc_8242046C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82420474"))) PPC_WEAK_FUNC(sub_82420474);
PPC_FUNC_IMPL(__imp__sub_82420474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82420478"))) PPC_WEAK_FUNC(sub_82420478);
PPC_FUNC_IMPL(__imp__sub_82420478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// vor128 v60,v1,v1
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r11,r11,7968
	r11.s64 = r11.s64 + 7968;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r10,r10,7952
	ctx.r10.s64 = ctx.r10.s64 + 7952;
	// addi r9,r9,7936
	ctx.r9.s64 = ctx.r9.s64 + 7936;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v63,2
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v58,v63,3
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v63,1
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vmulfp128 v59,v60,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v0,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x0));
	// vmulfp128 v58,v60,v58
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v58.f32)));
	// vspltw128 v56,v62,2
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vmulfp128 v57,v60,v57
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v13,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vmulfp128 v63,v60,v63
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// vspltw128 v12,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x0));
	// vspltw128 v55,v62,1
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vcmpgtfp128 v11,v56,v60
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v10,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vcmpgtfp128 v9,v55,v60
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v60.f32)));
	// vcmpgtfp128 v8,v62,v60
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// vrfiz128 v7,v59
	simde_mm_store_ps(ctx.v7.f32, simde_mm_round_ps(simde_mm_load_ps(v59.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vrfiz128 v6,v58
	simde_mm_store_ps(ctx.v6.f32, simde_mm_round_ps(simde_mm_load_ps(v58.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vrfiz128 v5,v57
	simde_mm_store_ps(ctx.v5.f32, simde_mm_round_ps(simde_mm_load_ps(v57.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vrfiz128 v63,v63
	simde_mm_store_ps(v63.f32, simde_mm_round_ps(simde_mm_load_ps(v63.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vmaddfp v13,v7,v0,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v12,v6,v0,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v10,v5,v0,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmulfp128 v0,v63,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v12,v13,v11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsel v13,v13,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vsel v1,v13,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vrlimi128 v1,v60,1,0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_permute_ps(simde_mm_load_ps(v60.f32), 228), 1));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8242051C"))) PPC_WEAK_FUNC(sub_8242051C);
PPC_FUNC_IMPL(__imp__sub_8242051C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82420520"))) PPC_WEAK_FUNC(sub_82420520);
PPC_FUNC_IMPL(__imp__sub_82420520) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// stfs f1,20(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 20, temp.u32);
	// lwz r10,20(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// rlwinm. r11,r10,0,0,0
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82420538
	if (cr0.eq) goto loc_82420538;
	// li r11,0
	r11.s64 = 0;
	// b 0x8242057c
	goto loc_8242057C;
loc_82420538:
	// rlwinm r11,r10,9,23,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// cmplwi cr6,r11,113
	cr6.compare<uint32_t>(r11.u32, 113, xer);
	// blt cr6,0x82420558
	if (cr6.lt) goto loc_82420558;
	// rlwinm r11,r10,0,5,8
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7800000;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm r11,r11,29,3,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// b 0x8242057c
	goto loc_8242057C;
loc_82420558:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r9,r10,9
	ctx.r9.u64 = ctx.r10.u32 & 0x7FFFFF;
	// subfic r11,r11,113
	xer.ca = r11.u32 <= 113;
	r11.s64 = 113 - r11.s64;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// oris r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 8388608;
	// srw r11,r10,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (r11.u8 & 0x3F));
loc_8242057C:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwimi r3,r11,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82420588"))) PPC_WEAK_FUNC(sub_82420588);
PPC_FUNC_IMPL(__imp__sub_82420588) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824205f0
	if (!cr6.eq) goto loc_824205F0;
	// lhz r11,10376(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 10376);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82420648
	if (!cr0.eq) goto loc_82420648;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfs f0,7988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7988);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f0,7984(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7984);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctidz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x82420640
	goto loc_82420640;
loc_824205F0:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// rlwinm r11,r11,1,25,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x7E;
	// addi r10,r10,6712
	ctx.r10.s64 = ctx.r10.s64 + 6712;
	// lhzx r11,r11,r10
	r11.u64 = PPC_LOAD_U16(r11.u32 + ctx.r10.u32);
	// rlwinm. r11,r11,0,20,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF00;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82420648
	if (!cr0.eq) goto loc_82420648;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfs f0,7984(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7984);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f0,7988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7988);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctidz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82420640:
	// or r3,r10,r31
	ctx.r3.u64 = ctx.r10.u64 | r31.u64;
	// b 0x82420654
	goto loc_82420654;
loc_82420648:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82420520
	ctx.lr = 0x82420650;
	sub_82420520(ctx, base);
	// rlwinm r11,r3,11,21,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 11) & 0x7FF;
loc_82420654:
	// lbz r10,10562(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 10562);
	// lwz r9,10560(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 10560);
	// subf r10,r10,r31
	ctx.r10.s64 = r31.s64 - ctx.r10.s64;
	// stw r3,10796(r30)
	PPC_STORE_U32(r30.u32 + 10796, ctx.r3.u32);
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r9,r9,6,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0x800;
	// rlwinm r10,r10,6,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0x800;
	// xori r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 ^ 2048;
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,10792(r30)
	PPC_STORE_U32(r30.u32 + 10792, r11.u32);
	// ld r11,32(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 32);
	// ori r11,r11,768
	r11.u64 = r11.u64 | 768;
	// std r11,32(r30)
	PPC_STORE_U64(r30.u32 + 32, r11.u64);
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

__attribute__((alias("__imp__sub_824206A8"))) PPC_WEAK_FUNC(sub_824206A8);
PPC_FUNC_IMPL(__imp__sub_824206A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824206B0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r30,1
	r30.s64 = 1;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,32
	r29.s64 = 32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8242076c
	if (cr6.eq) goto loc_8242076C;
	// rlwinm r11,r4,29,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x4;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r7,-64
	ctx.r7.s64 = -64;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// lwzx r11,r11,r9
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// or r5,r11,r4
	ctx.r5.u64 = r11.u64 | ctx.r4.u64;
loc_82420704:
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// rlwinm r11,r7,9,24,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 9) & 0xFF;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmplwi cr6,r9,253
	cr6.compare<uint32_t>(ctx.r9.u32, 253, xer);
	// bgt cr6,0x82420758
	if (cr6.gt) goto loc_82420758;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// bgt cr6,0x8242072c
	if (cr6.gt) goto loc_8242072C;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
loc_8242072C:
	// cmpwi cr6,r9,254
	cr6.compare<int32_t>(ctx.r9.s32, 254, xer);
	// bge cr6,0x82420744
	if (!cr6.lt) goto loc_82420744;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bgt cr6,0x82420748
	if (cr6.gt) goto loc_82420748;
	// mr r11,r30
	r11.u64 = r30.u64;
	// b 0x82420748
	goto loc_82420748;
loc_82420744:
	// li r11,254
	r11.s64 = 254;
loc_82420748:
	// rlwinm r9,r7,0,9,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFF807FFFFF;
	// rlwinm r11,r11,23,0,8
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 23) & 0xFF800000;
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
loc_82420758:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x82420704
	if (!cr0.eq) goto loc_82420704;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8242076C:
	// cmplwi cr6,r31,15
	cr6.compare<uint32_t>(r31.u32, 15, xer);
	// bgt cr6,0x82420ab4
	if (cr6.gt) goto loc_82420AB4;
	// lis r12,-32250
	r12.s64 = -2113536000;
	// addi r12,r12,7896
	r12.s64 = r12.s64 + 7896;
	// lbzx r0,r12,r31
	r0.u64 = PPC_LOAD_U8(r12.u32 + r31.u32);
	// rlwinm r0,r0,2,0,29
	r0.u64 = __builtin_rotateleft64(r0.u32 | (r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32190
	r12.s64 = -2109603840;
	// addi r12,r12,1948
	r12.s64 = r12.s64 + 1948;
	// add r12,r12,r0
	r12.u64 = r12.u64 + r0.u64;
	// mtctr r12
	ctr.u64 = r12.u64;
	// nop 
	// bctr 
	switch (r31.u64) {
	case 0:
		goto loc_824207A0;
	case 1:
		goto loc_8242079C;
	case 2:
		goto loc_824207A0;
	case 3:
		goto loc_82420944;
	case 4:
		goto loc_82420878;
	case 5:
		goto loc_82420878;
	case 6:
		goto loc_82420A30;
	case 7:
		goto loc_82420A54;
	case 8:
		goto loc_82420AB4;
	case 9:
		goto loc_82420AB4;
	case 10:
		goto loc_824207A0;
	case 11:
		goto loc_82420AB4;
	case 12:
		goto loc_82420944;
	case 13:
		goto loc_82420AB4;
	case 14:
		goto loc_82420A98;
	case 15:
		goto loc_82420AA4;
	default:
		__builtin_unreachable();
	}
loc_8242079C:
	// bl 0x82420478
	ctx.lr = 0x824207A0;
	sub_82420478(ctx, base);
loc_824207A0:
	// cmplwi cr6,r31,10
	cr6.compare<uint32_t>(r31.u32, 10, xer);
	// li r11,2
	r11.s64 = 2;
	// beq cr6,0x824207b0
	if (cr6.eq) goto loc_824207B0;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_824207B0:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r10,r10,8052
	ctx.r10.s64 = ctx.r10.s64 + 8052;
	// addi r9,r9,8048
	ctx.r9.s64 = ctx.r9.s64 + 8048;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lbzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// lbzx r11,r11,r9
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// slw r9,r30,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 << (ctx.r10.u8 & 0x3F));
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// slw r11,r30,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 << (r11.u8 & 0x3F));
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// extsw r11,r11
	r11.s64 = r11.s32;
	// mulli r9,r10,3
	ctx.r9.s64 = ctx.r10.s64 * 3;
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v1,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v63.f32)));
	// vmaxfp128 v62,v62,v61
	simde_mm_store_ps(v62.f32, simde_mm_max_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// vminfp128 v63,v63,v62
	simde_mm_store_ps(v63.f32, simde_mm_min_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// vrfin128 v63,v63
	simde_mm_store_ps(v63.f32, simde_mm_round_ps(simde_mm_load_ps(v63.f32), SIMDE_MM_FROUND_TO_NEAREST_INT | SIMDE_MM_FROUND_NO_EXC));
	// vcfpsxws128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.s32, simde_mm_vctsxs(simde_mm_load_ps(v63.f32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// slw r9,r8,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// slw r11,r5,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (r11.u8 & 0x3F));
	// slw r10,r7,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// or r10,r11,r6
	ctx.r10.u64 = r11.u64 | ctx.r6.u64;
loc_82420870:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// b 0x82420ab8
	goto loc_82420AB8;
loc_82420878:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lfs f0,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r6,8032
	ctx.r6.s64 = ctx.r6.s64 + 8032;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v63,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f0,7160(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7160);
	f0.f64 = double(temp.f32);
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r10,8016
	ctx.r10.s64 = ctx.r10.s64 + 8016;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// cmplwi cr6,r31,5
	cr6.compare<uint32_t>(r31.u32, 5, xer);
	// addi r9,r9,8000
	ctx.r9.s64 = ctx.r9.s64 + 8000;
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v61,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmulfp128 v61,v1,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v61.f32)));
	// vmaxfp128 v61,v60,v61
	simde_mm_store_ps(v61.f32, simde_mm_max_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vminfp128 v12,v62,v61
	simde_mm_store_ps(ctx.v12.f32, simde_mm_min_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// vmaddfp v0,v12,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vrfin128 v62,v0
	simde_mm_store_ps(v62.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v0.f32), SIMDE_MM_FROUND_TO_NEAREST_INT | SIMDE_MM_FROUND_NO_EXC));
	// vcfpsxws128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)v62.s32, simde_mm_vctsxs(simde_mm_load_ps(v62.f32)));
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r11,r11,16,0,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF0000;
	// bne cr6,0x82420938
	if (!cr6.eq) goto loc_82420938;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r29,64
	r29.s64 = 64;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r7,r10,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// or r10,r11,r9
	ctx.r10.u64 = r11.u64 | ctx.r9.u64;
	// or r11,r7,r8
	r11.u64 = ctx.r7.u64 | ctx.r8.u64;
	// b 0x82420ab8
	goto loc_82420AB8;
loc_82420938:
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// or r10,r11,r10
	ctx.r10.u64 = r11.u64 | ctx.r10.u64;
	// b 0x82420870
	goto loc_82420870;
loc_82420944:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82420950:
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// li r4,-124
	ctx.r4.s64 = -124;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// lfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823e6d40
	ctx.lr = 0x82420964;
	sub_823E6D40(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfsx f0,r31,r30
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + r30.u32, temp.u32);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addis r11,r11,1
	r11.s64 = r11.s64 + 65536;
	// addi r11,r11,-32768
	r11.s64 = r11.s64 + -32768;
	// rlwinm. r10,r11,0,1,5
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7C000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// beq 0x8242099c
	if (cr0.eq) goto loc_8242099C;
	// lfsx f0,r31,r30
	temp.u32 = PPC_LOAD_U32(r31.u32 + r30.u32);
	f0.f64 = double(temp.f32);
	// li r11,1023
	r11.s64 = 1023;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x824209a0
	if (cr6.lt) goto loc_824209A0;
	// li r11,511
	r11.s64 = 511;
	// b 0x824209a0
	goto loc_824209A0;
loc_8242099C:
	// rlwinm r11,r11,16,22,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
loc_824209A0:
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r31,12
	cr6.compare<uint32_t>(r31.u32, 12, xer);
	// blt cr6,0x82420950
	if (cr6.lt) goto loc_82420950;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,220(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	f0.f64 = double(temp.f32);
	// lfs f12,30712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x824209d0
	if (!cr6.gt) goto loc_824209D0;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// b 0x824209d4
	goto loc_824209D4;
loc_824209D0:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_824209D4:
	// fcmpu cr6,f13,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x824209ec
	if (!cr6.lt) goto loc_824209EC;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x824209f0
	if (cr6.gt) goto loc_824209F0;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x824209f0
	goto loc_824209F0;
loc_824209EC:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_824209F0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r8,96(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f13,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r11,r11,10,0,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm r11,r11,10,0,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// rlwinm r11,r11,10,0,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// or r10,r11,r8
	ctx.r10.u64 = r11.u64 | ctx.r8.u64;
	// b 0x82420870
	goto loc_82420870;
loc_82420A30:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vpkd3d128 v63,v1,3,1,3
	ctx.fpscr.enableFlushMode();
	__builtin_debugtrap();
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// stvewx128 v63,r0,r11
	ea = (r11.u32) & ~0x3;
	PPC_STORE_U32(ea, v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lhz r11,82(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// rlwimi r10,r11,16,0,15
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 16) & 0xFFFF0000) | (ctx.r10.u64 & 0xFFFFFFFF0000FFFF);
	// b 0x82420870
	goto loc_82420870;
loc_82420A54:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r29,64
	r29.s64 = 64;
	// vpkd3d128 v63,v1,5,2,2
	ctx.fpscr.enableFlushMode();
	temp.u32 = (ctx.v1.u32[0]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v1.u32[0]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v1.u32[0]&0x7FE000)>>13) : 0x0;
	v63.u16[4] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v63.u16[4] |= ((ctx.v1.u32[0]&0x80000000)>>16);
	temp.u32 = (ctx.v1.u32[1]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v1.u32[1]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v1.u32[1]&0x7FE000)>>13) : 0x0;
	v63.u16[5] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v63.u16[5] |= ((ctx.v1.u32[1]&0x80000000)>>16);
	temp.u32 = (ctx.v1.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v1.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v1.u32[2]&0x7FE000)>>13) : 0x0;
	v63.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v63.u16[6] |= ((ctx.v1.u32[2]&0x80000000)>>16);
	temp.u32 = (ctx.v1.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v1.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v1.u32[3]&0x7FE000)>>13) : 0x0;
	v63.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v63.u16[7] |= ((ctx.v1.u32[3]&0x80000000)>>16);
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v63,v63,1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// stvewx128 v62,r0,r11
	ea = (r11.u32) & ~0x3;
	PPC_STORE_U32(ea, v62.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r9,r10
	ea = (ctx.r9.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lhz r8,102(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// lhz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 96);
	// lhz r11,100(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// lhz r9,98(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 98);
	// rlwimi r10,r9,16,0,15
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFFFF0000) | (ctx.r10.u64 & 0xFFFFFFFF0000FFFF);
	// rlwimi r11,r8,16,0,15
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 16) & 0xFFFF0000) | (r11.u64 & 0xFFFFFFFF0000FFFF);
	// b 0x82420ab8
	goto loc_82420AB8;
loc_82420A98:
	// lwz r11,208(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// b 0x82420ab8
	goto loc_82420AB8;
loc_82420AA4:
	// lwz r10,208(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// li r29,64
	r29.s64 = 64;
	// lwz r11,212(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// b 0x82420ab8
	goto loc_82420AB8;
loc_82420AB4:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_82420AB8:
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82420AD0"))) PPC_WEAK_FUNC(sub_82420AD0);
PPC_FUNC_IMPL(__imp__sub_82420AD0) {
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
	ctx.lr = 0x82420AD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82420af0
	if (!cr6.eq) goto loc_82420AF0;
	// addi r11,r30,10372
	r11.s64 = r30.s64 + 10372;
	// b 0x82420afc
	goto loc_82420AFC;
loc_82420AF0:
	// addi r11,r5,2594
	r11.s64 = ctx.r5.s64 + 2594;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
loc_82420AFC:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// rlwinm r3,r11,16,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xF;
	// bne cr6,0x82420b20
	if (!cr6.eq) goto loc_82420B20;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r4,r11,12,26,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x3F;
	// bl 0x824206a8
	ctx.lr = 0x82420B1C;
	sub_824206A8(ctx, base);
	// b 0x82420b84
	goto loc_82420B84;
loc_82420B20:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r8,r10,7912
	ctx.r8.s64 = ctx.r10.s64 + 7912;
	// addi r10,r11,6712
	ctx.r10.s64 = r11.s64 + 6712;
	// clrlwi r11,r9,26
	r11.u64 = ctx.r9.u32 & 0x3F;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,54
	cr6.compare<uint32_t>(r11.u32, 54, xer);
	// lbzx r8,r3,r8
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r8.u32);
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lbzx r31,r8,r9
	r31.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// bne cr6,0x82420b54
	if (!cr6.eq) goto loc_82420B54;
	// li r11,7
	r11.s64 = 7;
loc_82420B54:
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lhzx r11,r11,r10
	r11.u64 = PPC_LOAD_U16(r11.u32 + ctx.r10.u32);
	// rlwinm r3,r11,24,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xF;
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// bl 0x824206a8
	ctx.lr = 0x82420B74;
	sub_824206A8(ctx, base);
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// ble cr6,0x82420b84
	if (!cr6.gt) goto loc_82420B84;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
loc_82420B84:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,10800(r30)
	PPC_STORE_U32(r30.u32 + 10800, r11.u32);
	// stw r10,10804(r30)
	PPC_STORE_U32(r30.u32 + 10804, ctx.r10.u32);
	// ld r11,32(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 32);
	// ori r11,r11,192
	r11.u64 = r11.u64 | 192;
	// std r11,32(r30)
	PPC_STORE_U64(r30.u32 + 32, r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82420BA8"))) PPC_WEAK_FUNC(sub_82420BA8);
PPC_FUNC_IMPL(__imp__sub_82420BA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82420BB0;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// clrlwi r14,r22,29
	r14.u64 = r22.u32 & 0x7;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// stw r14,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r14.u32);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// mr r21,r9
	r21.u64 = ctx.r9.u64;
	// mr r19,r10
	r19.u64 = ctx.r10.u64;
	// rlwinm. r11,r22,0,25,27
	r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0x70;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82420c34
	if (!cr0.eq) goto loc_82420C34;
	// cmplwi cr6,r14,4
	cr6.compare<uint32_t>(r14.u32, 4, xer);
	// bne cr6,0x82420bfc
	if (!cr6.eq) goto loc_82420BFC;
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// b 0x82420c08
	goto loc_82420C08;
loc_82420BFC:
	// addi r11,r14,3110
	r11.s64 = r14.s64 + 3110;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
loc_82420C08:
	// lhz r11,24(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 24);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82420c20
	if (!cr6.eq) goto loc_82420C20;
	// ori r22,r22,16
	r22.u64 = r22.u64 | 16;
	// b 0x82420c34
	goto loc_82420C34;
loc_82420C20:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82420c30
	if (!cr6.eq) goto loc_82420C30;
	// ori r22,r22,80
	r22.u64 = r22.u64 | 80;
	// b 0x82420c34
	goto loc_82420C34;
loc_82420C30:
	// ori r22,r22,112
	r22.u64 = r22.u64 | 112;
loc_82420C34:
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x82420c54
	if (!cr6.eq) goto loc_82420C54;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,-32224
	r11.s64 = r11.s64 + -32224;
	// addi r19,r1,192
	r19.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82420C54:
	// lwz r11,40(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 40);
	// lwz r10,48(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 48);
	// rlwinm r11,r11,2,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x2;
	// lwz r9,36(r18)
	ctx.r9.u64 = PPC_LOAD_U32(r18.u32 + 36);
	// rlwinm r10,r10,0,21,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x600;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,1024
	cr6.compare<uint32_t>(ctx.r10.u32, 1024, xer);
	// beq cr6,0x82420c84
	if (cr6.eq) goto loc_82420C84;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
	// li r15,1
	r15.s64 = 1;
	// rlwinm r9,r9,19,19,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0x1FFF;
	// b 0x82420c90
	goto loc_82420C90;
loc_82420C84:
	// clrlwi r10,r9,21
	ctx.r10.u64 = ctx.r9.u32 & 0x7FF;
	// li r15,8
	r15.s64 = 8;
	// rlwinm r9,r9,21,21,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 21) & 0x7FF;
loc_82420C90:
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r15,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r15.u32);
	// add r24,r9,r11
	r24.u64 = ctx.r9.u64 + r11.u64;
	// lwz r11,32(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 32);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// rlwinm r7,r11,1,25,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x7E;
	// lwz r9,28(r18)
	ctx.r9.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// addi r8,r10,6712
	ctx.r8.s64 = ctx.r10.s64 + 6712;
	// stw r24,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r24.u32);
	// rlwinm r10,r11,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// rlwinm r16,r9,15,18,26
	r16.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 15) & 0x3FE0;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// lhzx r11,r7,r8
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r28,r11,29,27,31
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1F;
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r28.u32);
	// bne cr6,0x82420ce0
	if (!cr6.eq) goto loc_82420CE0;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x82420d30
	if (cr6.eq) goto loc_82420D30;
loc_82420CE0:
	// addi r10,r1,120
	ctx.r10.s64 = ctx.r1.s64 + 120;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// addi r11,r15,-1
	r11.s64 = r15.s64 + -1;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r10,r1,116
	ctx.r10.s64 = ctx.r1.s64 + 116;
	// addi r9,r1,152
	ctx.r9.s64 = ctx.r1.s64 + 152;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r6,r1,132
	ctx.r6.s64 = ctx.r1.s64 + 132;
	// andc r4,r21,r11
	ctx.r4.u64 = r21.u64 & ~r11.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8240ff78
	ctx.lr = 0x82420D1C;
	sub_8240FF78(ctx, base);
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// twllei r28,0
	// divwu r16,r11,r28
	r16.u32 = r11.u32 / r28.u32;
	// lwz r24,112(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
loc_82420D30:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x82420d54
	if (!cr6.eq) goto loc_82420D54;
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r23,r1,176
	r23.s64 = ctx.r1.s64 + 176;
	// stw r24,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r24.u32);
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r11.u32);
	// stw r11,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r11.u32);
	// stw r9,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
loc_82420D54:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82420d64
	if (!cr6.eq) goto loc_82420D64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r30,r11,-3324
	r30.s64 = r11.s64 + -3324;
loc_82420D64:
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r8,r10,3
	ctx.r8.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r5,r11,512
	ctx.r5.s64 = r11.s64 + 512;
	// lwz r6,4(r23)
	ctx.r6.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// rlwinm r27,r22,6,26,31
	r27.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 6) & 0x3F;
	// subf r10,r6,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r6.s64;
	// lwz r4,40(r18)
	ctx.r4.u64 = PPC_LOAD_U32(r18.u32 + 40);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// lwz r29,32(r18)
	r29.u64 = PPC_LOAD_U32(r18.u32 + 32);
	// mullw r10,r10,r16
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r16.s32);
	// lwz r3,28(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r30,r4,0,28,30
	r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r9,r5,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x1000;
	// mullw r11,r11,r28
	r11.s64 = int64_t(r11.s32) * int64_t(r28.s32);
	// cntlzw r5,r30
	ctx.r5.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// subf r10,r7,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r7.s64;
	// clrlwi r30,r29,26
	r30.u64 = r29.u32 & 0x3F;
	// rlwinm r9,r5,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// add r20,r11,r8
	r20.u64 = r11.u64 + ctx.r8.u64;
	// add r26,r10,r24
	r26.u64 = ctx.r10.u64 + r24.u64;
	// clrlwi r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	// rlwinm r17,r3,30,30,31
	r17.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3;
	// xori r25,r9,1
	r25.u64 = ctx.r9.u64 ^ 1;
	// cmplwi cr6,r30,54
	cr6.compare<uint32_t>(r30.u32, 54, xer);
	// bne cr6,0x82420de8
	if (!cr6.eq) goto loc_82420DE8;
	// li r30,7
	r30.s64 = 7;
	// b 0x82420e4c
	goto loc_82420E4C;
loc_82420DE8:
	// cmplwi cr6,r30,55
	cr6.compare<uint32_t>(r30.u32, 55, xer);
	// bne cr6,0x82420df8
	if (!cr6.eq) goto loc_82420DF8;
	// li r30,16
	r30.s64 = 16;
	// b 0x82420e4c
	goto loc_82420E4C;
loc_82420DF8:
	// cmplwi cr6,r30,56
	cr6.compare<uint32_t>(r30.u32, 56, xer);
	// bne cr6,0x82420e08
	if (!cr6.eq) goto loc_82420E08;
	// li r30,17
	r30.s64 = 17;
	// b 0x82420e4c
	goto loc_82420E4C;
loc_82420E08:
	// cmplwi cr6,r30,27
	cr6.compare<uint32_t>(r30.u32, 27, xer);
	// bne cr6,0x82420e18
	if (!cr6.eq) goto loc_82420E18;
	// li r30,30
	r30.s64 = 30;
	// b 0x82420e4c
	goto loc_82420E4C;
loc_82420E18:
	// cmplwi cr6,r30,28
	cr6.compare<uint32_t>(r30.u32, 28, xer);
	// bne cr6,0x82420e28
	if (!cr6.eq) goto loc_82420E28;
	// li r30,31
	r30.s64 = 31;
	// b 0x82420e4c
	goto loc_82420E4C;
loc_82420E28:
	// cmplwi cr6,r30,29
	cr6.compare<uint32_t>(r30.u32, 29, xer);
	// bne cr6,0x82420e38
	if (!cr6.eq) goto loc_82420E38;
	// li r30,32
	r30.s64 = 32;
	// b 0x82420e4c
	goto loc_82420E4C;
loc_82420E38:
	// cmplwi cr6,r30,22
	cr6.compare<uint32_t>(r30.u32, 22, xer);
	// beq cr6,0x82420e48
	if (cr6.eq) goto loc_82420E48;
	// cmplwi cr6,r30,23
	cr6.compare<uint32_t>(r30.u32, 23, xer);
	// bne cr6,0x82420e4c
	if (!cr6.eq) goto loc_82420E4C;
loc_82420E48:
	// li r30,6
	r30.s64 = 6;
loc_82420E4C:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// addi r11,r17,-1
	r11.s64 = r17.s64 + -1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// bne cr6,0x82420e68
	if (!cr6.eq) goto loc_82420E68;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r28,r11,2
	r28.s64 = r11.s64 + 2;
	// b 0x82420e6c
	goto loc_82420E6C;
loc_82420E68:
	// rlwinm r28,r11,27,31,31
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_82420E6C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82420428
	ctx.lr = 0x82420E74;
	sub_82420428(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82420e80
	if (cr0.eq) goto loc_82420E80;
	// li r28,7
	r28.s64 = 7;
loc_82420E80:
	// rlwimi r27,r25,8,23,23
	r27.u64 = (__builtin_rotateleft32(r25.u32, 8) & 0x100) | (r27.u64 & 0xFFFFFFFFFFFFFEFF);
	// lwz r11,48(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 48);
	// rlwinm r10,r26,16,2,15
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 16) & 0x3FFF0000;
	// andi. r9,r27,319
	ctx.r9.u64 = r27.u64 & 319;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwimi r28,r9,3,0,28
	r28.u64 = (__builtin_rotateleft32(ctx.r9.u32, 3) & 0xFFFFFFF8) | (r28.u64 & 0xFFFFFFFF00000007);
	// rlwinm r7,r11,0,21,22
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x600;
	// rlwimi r30,r28,6,0,25
	r30.u64 = (__builtin_rotateleft32(r28.u32, 6) & 0xFFFFFFC0) | (r30.u64 & 0xFFFFFFFF0000003F);
	// clrlwi r8,r16,18
	ctx.r8.u64 = r16.u32 & 0x3FFF;
	// rlwinm r9,r29,26,30,31
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 26) & 0x3;
	// rlwinm r11,r30,7,0,24
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 7) & 0xFFFFFF80;
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// cmplwi cr6,r7,1024
	cr6.compare<uint32_t>(ctx.r7.u32, 1024, xer);
	// bne cr6,0x82420ee0
	if (!cr6.eq) goto loc_82420EE0;
	// addi r9,r15,-1
	ctx.r9.s64 = r15.s64 + -1;
	// mullw r8,r16,r24
	ctx.r8.s64 = int64_t(r16.s32) * int64_t(r24.s32);
	// stw r8,10820(r31)
	PPC_STORE_U32(r31.u32 + 10820, ctx.r8.u32);
	// ld r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// and r9,r9,r21
	ctx.r9.u64 = ctx.r9.u64 & r21.u64;
	// ori r8,r8,4
	ctx.r8.u64 = ctx.r8.u64 | 4;
	// rlwinm r9,r9,4,25,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0x70;
	// std r8,32(r31)
	PPC_STORE_U64(r31.u32 + 32, ctx.r8.u64);
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
loc_82420EE0:
	// rlwinm. r8,r22,0,18,18
	ctx.r8.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0x2000;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// beq 0x82420ef4
	if (cr0.eq) goto loc_82420EF4;
	// li r9,3
	ctx.r9.s64 = 3;
	// b 0x82420f00
	goto loc_82420F00;
loc_82420EF4:
	// cmplwi cr6,r14,4
	cr6.compare<uint32_t>(r14.u32, 4, xer);
	// bne cr6,0x82420f00
	if (!cr6.eq) goto loc_82420F00;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82420F00:
	// stw r11,10788(r31)
	PPC_STORE_U32(r31.u32 + 10788, r11.u32);
	// rlwinm r9,r9,20,10,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 20) & 0x300000;
	// stw r10,10784(r31)
	PPC_STORE_U32(r31.u32 + 10784, ctx.r10.u32);
	// andi. r10,r22,887
	ctx.r10.u64 = r22.u64 & 887;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r20,10780(r31)
	PPC_STORE_U32(r31.u32 + 10780, r20.u32);
	// addi r11,r10,-16
	r11.s64 = ctx.r10.s64 + -16;
	// lwz r29,468(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// rlwinm. r26,r22,0,22,22
	r26.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0x200;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// or r30,r9,r11
	r30.u64 = ctx.r9.u64 | r11.u64;
	// stw r30,10776(r31)
	PPC_STORE_U32(r31.u32 + 10776, r30.u32);
	// ld r11,32(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// ori r11,r11,15360
	r11.u64 = r11.u64 | 15360;
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
	// beq 0x82420f4c
	if (cr0.eq) goto loc_82420F4C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,460(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 460);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82420588
	ctx.lr = 0x82420F4C;
	sub_82420588(ctx, base);
loc_82420F4C:
	// rlwinm. r11,r22,0,23,23
	r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0x100;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82420f68
	if (cr0.eq) goto loc_82420F68;
	// clrlwi r5,r30,29
	ctx.r5.u64 = r30.u32 & 0x7;
	// lvx128 v1,r0,r19
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82420ad0
	ctx.lr = 0x82420F68;
	sub_82420AD0(ctx, base);
loc_82420F68:
	// lwz r11,8(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// li r21,0
	r21.s64 = 0;
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// addi r9,r11,7
	ctx.r9.s64 = r11.s64 + 7;
	// lwz r11,10436(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10436);
	// lwz r25,0(r23)
	r25.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r10,r10,7
	ctx.r10.s64 = ctx.r10.s64 + 7;
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// lwz r24,4(r23)
	r24.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// rlwinm r23,r9,0,0,28
	r23.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// srawi r9,r8,17
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFF) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 17;
	// rlwinm r22,r10,0,0,28
	r22.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// cmpw cr6,r25,r9
	cr6.compare<int32_t>(r25.s32, ctx.r9.s32, xer);
	// blt cr6,0x82420fd4
	if (cr6.lt) goto loc_82420FD4;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r11,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	r11.s64 = r11.s32 >> 17;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82420fd4
	if (cr6.lt) goto loc_82420FD4;
	// lwz r11,10440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10440);
	// rlwinm r10,r11,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// srawi r10,r10,17
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 17;
	// cmpw cr6,r23,r10
	cr6.compare<int32_t>(r23.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82420fd4
	if (cr6.gt) goto loc_82420FD4;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r11,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	r11.s64 = r11.s32 >> 17;
	// cmpw cr6,r22,r11
	cr6.compare<int32_t>(r22.s32, r11.s32, xer);
	// ble cr6,0x82420ff0
	if (!cr6.gt) goto loc_82420FF0;
loc_82420FD4:
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82413660
	ctx.lr = 0x82420FEC;
	sub_82413660(ctx, base);
	// li r21,1
	r21.s64 = 1;
loc_82420FF0:
	// ld r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// beq cr6,0x82421110
	if (cr6.eq) goto loc_82421110;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// and r11,r11,r4
	r11.u64 = r11.u64 & ctx.r4.u64;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8242101c
	if (cr6.eq) goto loc_8242101C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,10560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// bl 0x824231b0
	ctx.lr = 0x82421018;
	sub_824231B0(ctx, base);
	// std r3,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r3.u64);
loc_8242101C:
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// clrldi r10,r11,52
	ctx.r10.u64 = r11.u64 & 0xFFF;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x8242104c
	if (cr6.eq) goto loc_8242104C;
	// addi r6,r31,10548
	ctx.r6.s64 = r31.s64 + 10548;
	// li r5,8704
	ctx.r5.s64 = 8704;
	// rldicr r4,r11,52,11
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 52) & 0xFFF0000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x82421040;
	sub_82423548(ctx, base);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// rldicr r11,r11,0,51
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFFFFFFFFFF000;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_8242104C:
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// rlwinm r10,r11,0,15,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1F000;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82421084
	if (cr6.eq) goto loc_82421084;
	// addi r6,r31,10528
	ctx.r6.s64 = r31.s64 + 10528;
	// li r5,8576
	ctx.r5.s64 = 8576;
	// rldicr r4,r11,47,4
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 47) & 0xF800000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x82421070;
	sub_82423548(ctx, base);
	// lis r12,-2
	r12.s64 = -131072;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r12,r12,4095
	r12.u64 = r12.u64 | 4095;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82421084:
	// lis r12,0
	r12.s64 = 0;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,42,21
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFC0000000000;
	// and r10,r11,r12
	ctx.r10.u64 = r11.u64 & r12.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x824210cc
	if (cr6.eq) goto loc_824210CC;
	// addi r6,r31,10368
	ctx.r6.s64 = r31.s64 + 10368;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// rldicr r4,r11,6,15
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 6) & 0xFFFF000000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x824210B4;
	sub_82423548(ctx, base);
	// lis r12,-1
	r12.s64 = -65536;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// rldicr r12,r12,42,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_824210CC:
	// lis r12,-32
	r12.s64 = -2097152;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// clrldi r12,r12,22
	r12.u64 = r12.u64 & 0x3FFFFFFFFFF;
	// and r10,r11,r12
	ctx.r10.u64 = r11.u64 & r12.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82421110
	if (cr6.eq) goto loc_82421110;
	// addi r6,r31,10444
	ctx.r6.s64 = r31.s64 + 10444;
	// li r5,8448
	ctx.r5.s64 = 8448;
	// rldicr r4,r11,22,20
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 22) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x824210F8;
	sub_82423548(ctx, base);
	// lis r12,-32
	r12.s64 = -2097152;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// rldicr r12,r12,21,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 21) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
loc_82421110:
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x82421160
	if (cr6.eq) goto loc_82421160;
	// lis r12,31
	r12.s64 = 2031616;
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r12,r12,34,29
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFC00000000;
	// and r10,r11,r12
	ctx.r10.u64 = r11.u64 & r12.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82421160
	if (cr6.eq) goto loc_82421160;
	// addi r6,r31,10596
	ctx.r6.s64 = r31.s64 + 10596;
	// li r5,8832
	ctx.r5.s64 = 8832;
	// rldicr r4,r11,9,20
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 9) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x82421148;
	sub_82423548(ctx, base);
	// lis r12,-32
	r12.s64 = -2097152;
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// rldicr r12,r12,34,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
loc_82421160:
	// ld r11,32(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x82421198
	if (cr6.eq) goto loc_82421198;
	// clrldi r10,r11,26
	ctx.r10.u64 = r11.u64 & 0x3FFFFFFFFF;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x82421198
	if (cr6.eq) goto loc_82421198;
	// addi r6,r31,10680
	ctx.r6.s64 = r31.s64 + 10680;
	// li r5,8960
	ctx.r5.s64 = 8960;
	// rldicr r4,r11,26,37
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 26) & 0xFFFFFFFFFC000000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82423548
	ctx.lr = 0x8242118C;
	sub_82423548(ctx, base);
	// ld r11,32(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// rldicr r11,r11,0,25
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFFFC000000000;
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
loc_82421198:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824211ac
	if (cr0.eq) goto loc_824211AC;
	// li r11,1
	r11.s64 = 1;
	// b 0x8242123c
	goto loc_8242123C;
loc_824211AC:
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82421234
	if (cr0.eq) goto loc_82421234;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824211cc
	if (cr6.eq) goto loc_824211CC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82421234
	if (!cr6.eq) goto loc_82421234;
loc_824211CC:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824211e4
	if (cr6.eq) goto loc_824211E4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82421234
	if (!cr6.eq) goto loc_82421234;
loc_824211E4:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824211fc
	if (cr6.eq) goto loc_824211FC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82421234
	if (!cr6.eq) goto loc_82421234;
loc_824211FC:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82421214
	if (cr6.eq) goto loc_82421214;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82421234
	if (!cr6.eq) goto loc_82421234;
loc_82421214:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8242122c
	if (cr6.eq) goto loc_8242122C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82421234
	if (!cr6.eq) goto loc_82421234;
loc_8242122C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82421238
	goto loc_82421238;
loc_82421234:
	// li r11,0
	r11.s64 = 0;
loc_82421238:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8242123C:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8242134c
	if (cr0.eq) goto loc_8242134C;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8242125c
	if (!cr6.gt) goto loc_8242125C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8242125C;
	sub_82412710(ctx, base);
loc_8242125C:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,24832
	r11.u64 = r11.u64 | 24832;
	// li r28,0
	r28.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r10,12748(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82421320
	if (!cr6.gt) goto loc_82421320;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,12992
	r30.s64 = r31.s64 + 12992;
loc_8242128C:
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r7,3
	ctx.r7.s64 = 3;
	// ori r10,r10,24576
	ctx.r10.u64 = ctx.r10.u64 | 24576;
	// lwz r6,124(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// slw r7,r7,r29
	ctx.r7.u64 = r29.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r29.u8 & 0x3F));
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lis r10,-16383
	ctx.r10.s64 = -1073676288;
	// lis r5,4
	ctx.r5.s64 = 262144;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// ori r3,r10,11521
	ctx.r3.u64 = ctx.r10.u64 | 11521;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// mullw r10,r9,r16
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(r16.s32);
	// stwu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r4.u32 = ea;
	// stwu r3,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r4.u32 = ea;
	// ori r8,r5,793
	ctx.r8.u64 = ctx.r5.u64 | 793;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwu r8,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r4.u32 = ea;
	// mullw r11,r11,r6
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r6.s32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r10.u32 = ea;
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x82421308
	if (!cr6.gt) goto loc_82421308;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82421304;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82421308:
	// lwz r10,12748(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// blt cr6,0x8242128c
	if (cr6.lt) goto loc_8242128C;
loc_82421320:
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// ori r10,r10,24576
	ctx.r10.u64 = ctx.r10.u64 | 24576;
	// ori r9,r9,24832
	ctx.r9.u64 = ctx.r9.u64 | 24832;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lwz r10,12708(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12708);
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// lwz r10,12712(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12712);
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
loc_8242134C:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82421368
	if (!cr6.gt) goto loc_82421368;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82421364;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82421368:
	// lbz r10,10942(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// rlwinm. r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ori r27,r9,17920
	r27.u64 = ctx.r9.u64 | 17920;
	// beq 0x824213b4
	if (cr0.eq) goto loc_824213B4;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r8,6
	ctx.r8.s64 = 6;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r6,6
	ctx.r6.s64 = 6;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// stwu r6,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r11.u32 = ea;
	// lbz r10,10942(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// andi. r10,r10,247
	ctx.r10.u64 = ctx.r10.u64 & 247;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r10,10942(r31)
	PPC_STORE_U8(r31.u32 + 10942, ctx.r10.u8);
loc_824213B4:
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// li r9,256
	ctx.r9.s64 = 256;
	// ori r10,r10,15104
	ctx.r10.u64 = ctx.r10.u64 | 15104;
	// lis r8,-16368
	ctx.r8.s64 = -1072693248;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r8,r8,11008
	ctx.r8.u64 = ctx.r8.u64 | 11008;
	// li r7,15
	ctx.r7.s64 = 15;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,60
	ctx.r5.s64 = 60;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// addi r4,r6,7832
	ctx.r4.s64 = ctx.r6.s64 + 7832;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// mr r30,r11
	r30.u64 = r11.u64;
	// stwu r7,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r30.u32 = ea;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x824213FC;
	sub_823DA950(ctx, base);
	// addi r11,r30,60
	r11.s64 = r30.s64 + 60;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r10,r10,8576
	ctx.r10.u64 = ctx.r10.u64 | 8576;
	// ori r9,r9,2
	ctx.r9.u64 = ctx.r9.u64 | 2;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,8712
	ctx.r8.s64 = 8712;
	// li r7,6
	ctx.r7.s64 = 6;
	// li r6,8704
	ctx.r6.s64 = 8704;
	// li r4,0
	ctx.r4.s64 = 0;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// stwu r6,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r11.u32 = ea;
	// stwu r4,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r11.u32 = ea;
	// beq cr6,0x82421484
	if (cr6.eq) goto loc_82421484;
	// lbz r10,10942(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// lbz r9,10941(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lwz r7,10560(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 10560);
	// ori r9,r9,4
	ctx.r9.u64 = ctx.r9.u64 | 4;
	// rlwimi r8,r10,30,28,28
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 30) & 0x8) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFF7);
	// stb r9,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, ctx.r9.u8);
	// rlwinm r10,r7,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF0;
	// rlwinm r8,r8,29,29,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x7;
	// ld r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r9,r9,2
	ctx.r9.u64 = ctx.r9.u64 | 131072;
	// rlwinm r8,r8,0,31,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// std r9,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r9.u64);
	// or r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 | ctx.r10.u64;
loc_82421484:
	// li r10,1480
	ctx.r10.s64 = 1480;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r4,256
	ctx.r4.s64 = 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x824231b0
	ctx.lr = 0x824214A4;
	sub_824231B0(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824214bc
	if (!cr6.gt) goto loc_824214BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824214BC;
	sub_82412710(ctx, base);
loc_824214BC:
	// lis r11,2
	r11.s64 = 131072;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,8448
	r11.u64 = r11.u64 | 8448;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,8851
	ctx.r8.s64 = 8851;
	// li r7,0
	ctx.r7.s64 = 0;
	// lis r6,2
	ctx.r6.s64 = 131072;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// ori r10,r6,8708
	ctx.r10.u64 = ctx.r6.u64 | 8708;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// li r4,768
	ctx.r4.s64 = 768;
	// li r30,8978
	r30.s64 = 8978;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lis r29,0
	r29.s64 = 0;
	// li r28,8205
	r28.s64 = 8205;
	// ori r11,r29,65535
	r11.u64 = r29.u64 | 65535;
	// li r29,0
	r29.s64 = 0;
	// li r12,1
	r12.s64 = 1;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// cmplwi cr6,r17,3
	cr6.compare<uint32_t>(r17.u32, 3, xer);
	// rldicr r12,r12,41,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 41) & 0xFFFFFFFFFFFFFFFF;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r30,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stwu r29,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r29.u32);
	r30.u32 = ea;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,40,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 40) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,39,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 39) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// rldicr r12,r12,35,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 35) & 0xFFFFFFFFFFFFFFFF;
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
	// li r12,1
	r12.s64 = 1;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// rldicr r12,r12,44,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 44) & 0xFFFFFFFFFFFFFFFF;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ld r11,32(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// bne cr6,0x82421664
	if (!cr6.eq) goto loc_82421664;
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x82421664
	if (cr6.eq) goto loc_82421664;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824215e8
	if (cr6.eq) goto loc_824215E8;
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
loc_824215E8:
	// addi r11,r29,2593
	r11.s64 = r29.s64 + 2593;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r11,r31
	r28.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// rlwinm r11,r28,0,12,15
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xF0000;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82421664
	if (!cr6.eq) goto loc_82421664;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8242161c
	if (!cr6.gt) goto loc_8242161C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8242161C;
	sub_82412710(ctx, base);
loc_8242161C:
	// addis r10,r29,2
	ctx.r10.s64 = r29.s64 + 131072;
	// addi r11,r29,8193
	r11.s64 = r29.s64 + 8193;
	// addi r10,r10,263
	ctx.r10.s64 = ctx.r10.s64 + 263;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// clrlwi r8,r28,6
	ctx.r8.u64 = r28.u32 & 0x3FFFFFF;
	// srawi r11,r10,16
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	r11.s64 = ctx.r10.s32 >> 16;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r8,0,20,11
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFF00FFF;
	// clrldi r10,r10,56
	ctx.r10.u64 = ctx.r10.u64 & 0xFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// ldx r8,r11,r31
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stdx r10,r11,r31
	PPC_STORE_U64(r11.u32 + r31.u32, ctx.r10.u64);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
loc_82421664:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8242167c
	if (!cr6.gt) goto loc_8242167C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82421678;
	sub_82412710(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8242167C:
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411840
	ctx.lr = 0x8242168C;
	sub_82411840(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8242169c
	if (!cr0.eq) goto loc_8242169C;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// b 0x824219e8
	goto loc_824219E8;
loc_8242169C:
	// rlwinm r11,r3,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 12) & 0xFFF;
	// lwz r9,10688(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10688);
	// clrlwi r10,r3,3
	ctx.r10.u64 = ctx.r3.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// clrlwi. r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// bne 0x824216c8
	if (!cr0.eq) goto loc_824216C8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// b 0x824216d0
	goto loc_824216D0;
loc_824216C8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_824216D0:
	// extsw r10,r25
	ctx.r10.s64 = r25.s32;
	// extsw r9,r24
	ctx.r9.s64 = r24.s32;
	// std r10,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r10.u64);
	// subf r10,r25,r23
	ctx.r10.s64 = r23.s64 - r25.s64;
	// std r9,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r9.u64);
	// subf r9,r24,r22
	ctx.r9.s64 = r22.s64 - r24.s64;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r10.u64);
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// std r10,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r11,r11,3
	r11.u64 = r11.u64 | 3;
	// ori r10,r10,18432
	ctx.r10.u64 = ctx.r10.u64 | 18432;
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// li r28,0
	r28.s64 = 0;
	// ori r9,r9,26
	ctx.r9.u64 = ctx.r9.u64 | 26;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// mr r29,r28
	r29.u64 = r28.u64;
	// ori r4,r4,20480
	ctx.r4.u64 = ctx.r4.u64 | 20480;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r25,r28
	r25.u64 = r28.u64;
	// lis r24,3
	r24.s64 = 196608;
	// lfd f13,176(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfd f12,160(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lfd f11,152(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfd f10,144(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// ori r24,r24,136
	r24.u64 = r24.u64 | 136;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f13,0(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fsubs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 - f0.f64));
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fadds f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 + f0.f64));
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stwu r10,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r30.u32 = ea;
	// stwu r11,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r11.u32);
	r30.u32 = ea;
	// stwu r9,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r30.u32 = ea;
	// stwu r8,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r30.u32 = ea;
	// stwu r7,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r30.u32 = ea;
	// stwu r6,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r30.u32 = ea;
	// stwu r5,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	r30.u32 = ea;
	// stwu r4,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r30.u32 = ea;
	// stwu r29,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r29.u32);
	r30.u32 = ea;
	// stwu r26,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r26.u32);
	r30.u32 = ea;
	// stwu r25,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r25.u32);
	r30.u32 = ea;
	// lwz r11,12716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12716);
	// oris r11,r11,49152
	r11.u64 = r11.u64 | 3221225472;
	// ori r11,r11,13824
	r11.u64 = r11.u64 | 13824;
	// stwu r11,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, r11.u32);
	r30.u32 = ea;
	// mr r11,r30
	r11.u64 = r30.u64;
	// stwu r24,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r24.u32);
	r11.u32 = ea;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// ble cr6,0x824217f4
	if (!cr6.gt) goto loc_824217F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824217F4;
	sub_82412710(ctx, base);
loc_824217F4:
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// li r11,6
	r11.s64 = 6;
	// li r10,8199
	ctx.r10.s64 = 8199;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10396(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10396);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// beq cr6,0x8242184c
	if (cr6.eq) goto loc_8242184C;
	// lwz r11,10440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10440);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10436);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,17,0,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r7,r9,17
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 17;
	// rlwinm r10,r10,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0xFFFE0000;
	// srawi r6,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	ctx.r6.s64 = r11.s32 >> 17;
	// srawi r5,r8,17
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 17;
	// srawi r4,r10,17
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 17;
	// bl 0x82413660
	ctx.lr = 0x8242184C;
	sub_82413660(ctx, base);
loc_8242184C:
	// lwz r9,10908(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// lwz r8,124(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r7,128(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mullw r8,r16,r8
	ctx.r8.s64 = int64_t(r16.s32) * int64_t(ctx.r8.s32);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r9,8(r18)
	PPC_STORE_U32(r18.u32 + 8, ctx.r9.u32);
	// mullw r9,r8,r7
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// mullw r30,r9,r6
	r30.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// ld r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r8,r8,8
	ctx.r8.u64 = ctx.r8.u64 | 524288;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// std r8,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r8.u64);
	// clrlwi r11,r11,3
	r11.u64 = r11.u32 & 0x1FFFFFFF;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// ori r9,r9,8
	ctx.r9.u64 = ctx.r9.u64 | 8;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// std r9,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r9.u64);
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// oris r11,r11,32768
	r11.u64 = r11.u64 | 2147483648;
	// std r11,24(r31)
	PPC_STORE_U64(r31.u32 + 24, r11.u64);
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r11,r11,1
	r11.u64 = r11.u64 | 65536;
	// ori r11,r11,32768
	r11.u64 = r11.u64 | 32768;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824218e0
	if (!cr6.gt) goto loc_824218E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824218E0;
	sub_82412710(ctx, base);
loc_824218E0:
	// li r11,2609
	r11.s64 = 2609;
	// lis r10,768
	ctx.r10.s64 = 50331648;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lis r11,1
	r11.s64 = 65536;
	// addi r9,r30,8191
	ctx.r9.s64 = r30.s64 + 8191;
	// ori r11,r11,2607
	r11.u64 = r11.u64 | 2607;
	// rlwinm r9,r9,0,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFF000;
	// rlwinm r8,r29,0,0,19
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFF000;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lis r7,-16380
	ctx.r7.s64 = -1073479680;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r7,r7,15360
	ctx.r7.u64 = ctx.r7.u64 | 15360;
	// li r6,2609
	ctx.r6.s64 = 2609;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// li r30,8
	r30.s64 = 8;
	// li r11,1480
	r11.s64 = 1480;
	// lis r29,2
	r29.s64 = 131072;
	// li r27,8984
	r27.s64 = 8984;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// mr r26,r28
	r26.u64 = r28.u64;
	// li r25,8987
	r25.s64 = 8987;
	// mr r24,r28
	r24.u64 = r28.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r30,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r29,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r3.u32 = ea;
	// stw r28,10776(r31)
	PPC_STORE_U32(r31.u32 + 10776, r28.u32);
	// stw r28,10788(r31)
	PPC_STORE_U32(r31.u32 + 10788, r28.u32);
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// stwu r24,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r24.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// beq cr6,0x82421998
	if (cr6.eq) goto loc_82421998;
	// stw r11,8(r18)
	PPC_STORE_U32(r18.u32 + 8, r11.u32);
	// stw r11,12(r18)
	PPC_STORE_U32(r18.u32 + 12, r11.u32);
	// b 0x824219e8
	goto loc_824219E8;
loc_82421998:
	// lwz r11,10912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10912);
	// lwz r10,0(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824219e8
	if (cr0.eq) goto loc_824219E8;
	// lwz r11,13528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13528);
	// lwz r3,13524(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13524);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x824219c0
	if (cr6.lt) goto loc_824219C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a630
	ctx.lr = 0x824219C0;
	sub_8241A630(ctx, base);
loc_824219C0:
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// rlwimi r11,r18,30,2,31
	r11.u64 = (__builtin_rotateleft32(r18.u32, 30) & 0x3FFFFFFF) | (r11.u64 & 0xFFFFFFFFC0000000);
	// stw r10,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r10.u32);
	// oris r11,r11,16384
	r11.u64 = r11.u64 | 1073741824;
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r11.u32);
	// ld r11,176(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// stw r9,13524(r31)
	PPC_STORE_U32(r31.u32 + 13524, ctx.r9.u32);
loc_824219E8:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824219F4"))) PPC_WEAK_FUNC(sub_824219F4);
PPC_FUNC_IMPL(__imp__sub_824219F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824219F8"))) PPC_WEAK_FUNC(sub_824219F8);
PPC_FUNC_IMPL(__imp__sub_824219F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,-1
	r11.s64 = -1;
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// std r11,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, r11.u64);
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82421A14"))) PPC_WEAK_FUNC(sub_82421A14);
PPC_FUNC_IMPL(__imp__sub_82421A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82421A18"))) PPC_WEAK_FUNC(sub_82421A18);
PPC_FUNC_IMPL(__imp__sub_82421A18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r11,r10,28
	r11.u64 = ctx.r10.u32 & 0xF;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82421a74
	if (!cr6.eq) goto loc_82421A74;
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r10,r10,23,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x3;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x82421a40
	if (!cr6.eq) goto loc_82421A40;
	// li r11,18
	r11.s64 = 18;
	// b 0x82421a9c
	goto loc_82421A9C;
loc_82421A40:
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x82421a50
	if (!cr6.eq) goto loc_82421A50;
	// li r11,17
	r11.s64 = 17;
	// b 0x82421a9c
	goto loc_82421A9C;
loc_82421A50:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82421a60
	if (!cr6.eq) goto loc_82421A60;
	// li r11,20
	r11.s64 = 20;
	// b 0x82421a9c
	goto loc_82421A9C;
loc_82421A60:
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// rlwinm. r10,r10,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82421a9c
	if (cr0.eq) goto loc_82421A9C;
	// li r11,19
	r11.s64 = 19;
	// b 0x82421a9c
	goto loc_82421A9C;
loc_82421A74:
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x82421a9c
	if (!cr6.eq) goto loc_82421A9C;
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82421a9c
	if (cr0.eq) goto loc_82421A9C;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// rlwinm r10,r10,0,21,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x600;
	// cmplwi cr6,r10,1024
	cr6.compare<uint32_t>(ctx.r10.u32, 1024, xer);
	// bne cr6,0x82421a9c
	if (!cr6.eq) goto loc_82421A9C;
	// li r11,16
	r11.s64 = 16;
loc_82421A9C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82421AA4"))) PPC_WEAK_FUNC(sub_82421AA4);
PPC_FUNC_IMPL(__imp__sub_82421AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82421AA8"))) PPC_WEAK_FUNC(sub_82421AA8);
PPC_FUNC_IMPL(__imp__sub_82421AA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82421AB0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,2148(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2148);
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// bgt cr6,0x82421c8c
	if (cr6.gt) goto loc_82421C8C;
	// lis r12,-32250
	r12.s64 = -2113536000;
	// addi r12,r12,8248
	r12.s64 = r12.s64 + 8248;
	// lbzx r0,r12,r10
	r0.u64 = PPC_LOAD_U8(r12.u32 + ctx.r10.u32);
	// rlwinm r0,r0,2,0,29
	r0.u64 = __builtin_rotateleft64(r0.u32 | (r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32190
	r12.s64 = -2109603840;
	// addi r12,r12,6912
	r12.s64 = r12.s64 + 6912;
	// add r12,r12,r0
	r12.u64 = r12.u64 + r0.u64;
	// mtctr r12
	ctr.u64 = r12.u64;
	// nop 
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_82421B94;
	case 1:
		goto loc_82421BC8;
	case 2:
		goto loc_82421B44;
	case 3:
		goto loc_82421B00;
	case 4:
		goto loc_82421C8C;
	case 5:
		goto loc_82421BF8;
	case 6:
		goto loc_82421C28;
	case 7:
		goto loc_82421C44;
	case 8:
		goto loc_82421C60;
	default:
		__builtin_unreachable();
	}
loc_82421B00:
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82421c8c
	if (!cr0.eq) goto loc_82421C8C;
	// rlwinm. r11,r11,0,0,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82421b28
	if (cr0.eq) goto loc_82421B28;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r10,5120
	ctx.r10.s64 = 5120;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// divwu r4,r11,r10
	ctx.r4.u32 = r11.u32 / ctx.r10.u32;
	// clrlwi r3,r9,20
	ctx.r3.u64 = ctx.r9.u32 & 0xFFF;
	// bl 0x82425258
	ctx.lr = 0x82421B28;
	sub_82425258(ctx, base);
loc_82421B28:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82421c8c
	if (cr0.eq) goto loc_82421C8C;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-9720(r10)
	PPC_STORE_U32(ctx.r10.u32 + -9720, r11.u32);
	// b 0x82421c8c
	goto loc_82421C8C;
loc_82421B44:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82421b68
	if (cr6.eq) goto loc_82421B68;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82421b68
	if (cr6.eq) goto loc_82421B68;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,13
	ctx.r5.s64 = 13;
	// bl 0x82411e98
	ctx.lr = 0x82421B68;
	sub_82411E98(ctx, base);
loc_82421B68:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r30,-20096
	r30.s64 = -1317011456;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r3,r11,0,0,19
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// rlwinm r29,r10,0,0,19
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// bl 0x821310f8
	ctx.lr = 0x82421B84;
	sub_821310F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82421B8C:
	// bl 0x821310f8
	ctx.lr = 0x82421B90;
	sub_821310F8(ctx, base);
	// b 0x82421c8c
	goto loc_82421C8C;
loc_82421B94:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82421bb8
	if (cr6.eq) goto loc_82421BB8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82421bb8
	if (cr6.eq) goto loc_82421BB8;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,9
	ctx.r5.s64 = 9;
	// bl 0x82411e98
	ctx.lr = 0x82421BB8;
	sub_82411E98(ctx, base);
loc_82421BB8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// rlwinm r3,r11,0,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// b 0x82421b8c
	goto loc_82421B8C;
loc_82421BC8:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82421bec
	if (cr6.eq) goto loc_82421BEC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82421bec
	if (cr6.eq) goto loc_82421BEC;
	// li r5,11
	ctx.r5.s64 = 11;
loc_82421BE0:
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x82411e98
	ctx.lr = 0x82421BEC;
	sub_82411E98(ctx, base);
loc_82421BEC:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// b 0x82421b8c
	goto loc_82421B8C;
loc_82421BF8:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82421c1c
	if (cr6.eq) goto loc_82421C1C;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82421c1c
	if (cr6.eq) goto loc_82421C1C;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,7
	ctx.r5.s64 = 7;
	// bl 0x82411e98
	ctx.lr = 0x82421C1C;
	sub_82411E98(ctx, base);
loc_82421C1C:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// b 0x82421b8c
	goto loc_82421B8C;
loc_82421C28:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82421bec
	if (cr6.eq) goto loc_82421BEC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82421bec
	if (cr6.eq) goto loc_82421BEC;
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x82421be0
	goto loc_82421BE0;
loc_82421C44:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82421bec
	if (cr6.eq) goto loc_82421BEC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82421bec
	if (cr6.eq) goto loc_82421BEC;
	// li r5,17
	ctx.r5.s64 = 17;
	// b 0x82421be0
	goto loc_82421BE0;
loc_82421C60:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82421c84
	if (cr6.eq) goto loc_82421C84;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82421c84
	if (cr6.eq) goto loc_82421C84;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,15
	ctx.r5.s64 = 15;
	// bl 0x82411e98
	ctx.lr = 0x82421C84;
	sub_82411E98(ctx, base);
loc_82421C84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a8c8
	ctx.lr = 0x82421C8C;
	sub_8241A8C8(ctx, base);
loc_82421C8C:
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x82421C98;
	sub_821310F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82421CA0"))) PPC_WEAK_FUNC(sub_82421CA0);
PPC_FUNC_IMPL(__imp__sub_82421CA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82421CA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32256
	r31.s64 = -2113929216;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lwz r9,2148(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2148);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// rldicl r11,r4,32,32
	r11.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFF;
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// beq cr6,0x82421ce8
	if (cr6.eq) goto loc_82421CE8;
	// lwz r10,260(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// ori r25,r10,2
	r25.u64 = ctx.r10.u64 | 2;
	// b 0x82421cec
	goto loc_82421CEC;
loc_82421CE8:
	// lwz r25,260(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
loc_82421CEC:
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// clrlwi r7,r10,28
	ctx.r7.u64 = ctx.r10.u32 & 0xF;
	// cmplwi cr6,r7,4
	cr6.compare<uint32_t>(ctx.r7.u32, 4, xer);
	// bne cr6,0x82421d18
	if (!cr6.eq) goto loc_82421D18;
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82421d18
	if (cr0.eq) goto loc_82421D18;
	// lwz r10,24(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82421d18
	if (cr6.eq) goto loc_82421D18;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_82421D18:
	// andi. r10,r25,4112
	ctx.r10.u64 = r25.u64 & 4112;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// beq 0x82421d48
	if (cr0.eq) goto loc_82421D48;
	// beq cr6,0x82421d40
	if (cr6.eq) goto loc_82421D40;
	// lwz r10,23944(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23944);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x82421d64
	goto loc_82421D64;
loc_82421D40:
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// b 0x82421d64
	goto loc_82421D64;
loc_82421D48:
	// beq cr6,0x82421d60
	if (cr6.eq) goto loc_82421D60;
	// lwz r10,23944(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23944);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x82421d64
	goto loc_82421D64;
loc_82421D60:
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
loc_82421D64:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82421d98
	if (cr6.eq) goto loc_82421D98;
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// bne cr6,0x82421d80
	if (!cr6.eq) goto loc_82421D80;
	// li r7,0
	ctx.r7.s64 = 0;
	// beq cr6,0x82421d88
	if (cr6.eq) goto loc_82421D88;
loc_82421D80:
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x82421d8c
	goto loc_82421D8C;
loc_82421D88:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
loc_82421D8C:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// bl 0x82411e98
	ctx.lr = 0x82421D94;
	sub_82411E98(ctx, base);
	// lwz r9,2148(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2148);
loc_82421D98:
	// andi. r11,r25,18
	r11.u64 = r25.u64 & 18;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x82421e68
	if (!cr0.eq) goto loc_82421E68;
	// rlwinm r11,r28,12,20,31
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 12) & 0xFFF;
	// lwz r31,0(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r10,r28,3
	ctx.r10.u64 = r28.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// add r29,r30,r27
	r29.u64 = r30.u64 + r27.u64;
	// bl 0x8244fec8
	ctx.lr = 0x82421DC4;
	sub_8244FEC8(ctx, base);
	// lwz r11,10888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10888);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// beq cr6,0x82421de4
	if (cr6.eq) goto loc_82421DE4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,11824
	ctx.r3.s64 = r31.s64 + 11824;
	// bl 0x824113b8
	ctx.lr = 0x82421DE0;
	sub_824113B8(ctx, base);
	// b 0x82421e68
	goto loc_82421E68;
loc_82421DE4:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82421dfc
	if (!cr6.gt) goto loc_82421DFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82421DFC;
	sub_82412710(ctx, base);
loc_82421DFC:
	// li r11,2609
	r11.s64 = 2609;
	// lwz r10,268(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// addi r11,r29,4095
	r11.s64 = r29.s64 + 4095;
	// ori r9,r9,2607
	ctx.r9.u64 = ctx.r9.u64 | 2607;
	// rlwinm r8,r30,0,0,19
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFF000;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// lis r7,-16380
	ctx.r7.s64 = -1073479680;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// ori r10,r7,15360
	ctx.r10.u64 = ctx.r7.u64 | 15360;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,2609
	ctx.r6.s64 = 2609;
	// li r5,0
	ctx.r5.s64 = 0;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// li r30,8
	r30.s64 = 8;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r30,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
loc_82421E68:
	// rlwinm. r6,r25,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne 0x82421e7c
	if (!cr0.eq) goto loc_82421E7C;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm. r11,r11,0,10,10
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82421f08
	if (cr0.eq) goto loc_82421F08;
loc_82421E7C:
	// clrlwi. r11,r25,31
	r11.u64 = r25.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82421ee8
	if (!cr0.eq) goto loc_82421EE8;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82421ea0
	if (cr6.eq) goto loc_82421EA0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82421ea0
	if (cr6.eq) goto loc_82421EA0;
	// subf r11,r26,r28
	r11.s64 = r28.s64 - r26.s64;
	// addi r9,r24,24
	ctx.r9.s64 = r24.s64 + 24;
	// b 0x82421ea8
	goto loc_82421EA8;
loc_82421EA0:
	// subf r11,r23,r28
	r11.s64 = r28.s64 - r23.s64;
	// addi r9,r24,20
	ctx.r9.s64 = r24.s64 + 20;
loc_82421EA8:
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r8,r11,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// addi r10,r10,127
	ctx.r10.s64 = ctx.r10.s64 + 127;
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// rlwinm r7,r7,16,16,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x82421ed0
	if (!cr6.gt) goto loc_82421ED0;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82421ED0:
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// blt cr6,0x82421edc
	if (cr6.lt) goto loc_82421EDC;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
loc_82421EDC:
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
loc_82421EE8:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82421f08
	if (cr6.eq) goto loc_82421F08;
	// rlwinm r11,r28,12,20,31
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r28,3
	ctx.r10.u64 = r28.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addis r28,r11,-16384
	r28.s64 = r11.s64 + -1073741824;
loc_82421F08:
	// li r11,256
	r11.s64 = 256;
loc_82421F0C:
	// mfmsr r8
	ctx.r8.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r24
	reserved.u32 = *(uint32_t*)(base + r24.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// stwcx. r9,0,r24
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r24.u32), reserved.s32, __builtin_bswap32(ctx.r9.s32));
	cr0.so = xer.so;
	// mtmsrd r8,1
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82421f0c
	if (!cr0.eq) goto loc_82421F0C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82421F34"))) PPC_WEAK_FUNC(sub_82421F34);
PPC_FUNC_IMPL(__imp__sub_82421F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82421F38"))) PPC_WEAK_FUNC(sub_82421F38);
PPC_FUNC_IMPL(__imp__sub_82421F38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	ctx.lr = 0x82421F40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r11,-256
	r11.s64 = -256;
loc_82421F54:
	// mfmsr r7
	ctx.r7.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r9,0,r31
	reserved.u32 = *(uint32_t*)(base + r31.u32);
	ctx.r9.u64 = __builtin_bswap32(reserved.u32);
	// add r8,r11,r9
	ctx.r8.u64 = r11.u64 + ctx.r9.u64;
	// stwcx. r8,0,r31
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r31.u32), reserved.s32, __builtin_bswap32(ctx.r8.s32));
	cr0.so = xer.so;
	// mtmsrd r7,1
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82421f54
	if (!cr0.eq) goto loc_82421F54;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rlwinm r11,r11,0,20,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF00;
	// cmplwi cr6,r11,256
	cr6.compare<uint32_t>(r11.u32, 256, xer);
	// bne cr6,0x82422038
	if (!cr6.eq) goto loc_82422038;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r30,-1
	r30.s64 = -65536;
	// lis r28,16384
	r28.s64 = 1073741824;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x82421fdc
	if (cr6.eq) goto loc_82421FDC;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r8,r11,16,16,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// rlwinm. r11,r7,0,10,10
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x200000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82421fc4
	if (!cr0.eq) goto loc_82421FC4;
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
loc_82421FC4:
	// rlwinm r9,r9,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r11,r8,7,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82425cd8
	ctx.lr = 0x82421FDC;
	sub_82425CD8(ctx, base);
loc_82421FDC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82422038
	if (cr6.eq) goto loc_82422038;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x82422038
	if (cr6.eq) goto loc_82422038;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,16,16,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// clrlwi r8,r11,16
	ctx.r8.u64 = r11.u32 & 0xFFFF;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// rlwinm. r11,r10,0,10,10
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x200000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82422020
	if (!cr0.eq) goto loc_82422020;
	// rlwinm r11,r29,12,20,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r29,3
	ctx.r10.u64 = r29.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r29,r28,r11
	r29.s64 = r11.s64 - r28.s64;
loc_82422020:
	// rlwinm r10,r8,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r11,r9,7,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r10,r29
	ctx.r4.u64 = ctx.r10.u64 + r29.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x82425cd8
	ctx.lr = 0x82422038;
	sub_82425CD8(ctx, base);
loc_82422038:
	// sync 
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82422044"))) PPC_WEAK_FUNC(sub_82422044);
PPC_FUNC_IMPL(__imp__sub_82422044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82422048"))) PPC_WEAK_FUNC(sub_82422048);
PPC_FUNC_IMPL(__imp__sub_82422048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82422064
	if (!cr6.eq) goto loc_82422064;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// b 0x82422088
	goto loc_82422088;
loc_82422064:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82422084
	if (!cr6.eq) goto loc_82422084;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// rlwinm. r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82422088
	if (!cr0.eq) goto loc_82422088;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// b 0x82422088
	goto loc_82422088;
loc_82422084:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
loc_82422088:
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824220A0"))) PPC_WEAK_FUNC(sub_824220A0);
PPC_FUNC_IMPL(__imp__sub_824220A0) {
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
	ctx.lr = 0x824220A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824220d0
	if (!cr6.gt) goto loc_824220D0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824220D0;
	sub_82412710(ctx, base);
loc_824220D0:
	// li r10,2609
	ctx.r10.s64 = 2609;
	// rlwinm r11,r30,12,20,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lis r10,768
	ctx.r10.s64 = 50331648;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// ori r9,r10,512
	ctx.r9.u64 = ctx.r10.u64 | 512;
	// rlwinm r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// clrlwi r11,r30,3
	r11.u64 = r30.u32 & 0x1FFFFFFF;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ori r9,r8,2607
	ctx.r9.u64 = ctx.r8.u64 | 2607;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// addi r10,r10,4095
	ctx.r10.s64 = ctx.r10.s64 + 4095;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// lis r8,-16380
	ctx.r8.s64 = -1073479680;
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// ori r9,r8,15360
	ctx.r9.u64 = ctx.r8.u64 | 15360;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// li r8,3
	ctx.r8.s64 = 3;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// li r7,2609
	ctx.r7.s64 = 2609;
	// li r6,0
	ctx.r6.s64 = 0;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// li r5,8
	ctx.r5.s64 = 8;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82422160"))) PPC_WEAK_FUNC(sub_82422160);
PPC_FUNC_IMPL(__imp__sub_82422160) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
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
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
loc_82422174:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82422174
	if (!cr0.eq) goto loc_82422174;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// bne cr6,0x824221bc
	if (!cr6.eq) goto loc_824221BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// bne cr6,0x824221bc
	if (!cr6.eq) goto loc_824221BC;
	// rlwinm. r11,r11,0,1,1
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824221bc
	if (cr0.eq) goto loc_824221BC;
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// bl 0x82422160
	ctx.lr = 0x824221BC;
	sub_82422160(ctx, base);
loc_824221BC:
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

__attribute__((alias("__imp__sub_824221D4"))) PPC_WEAK_FUNC(sub_824221D4);
PPC_FUNC_IMPL(__imp__sub_824221D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824221D8"))) PPC_WEAK_FUNC(sub_824221D8);
PPC_FUNC_IMPL(__imp__sub_824221D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
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
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
loc_824221F0:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x824221f0
	if (!cr0.eq) goto loc_824221F0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82422244
	if (!cr6.eq) goto loc_82422244;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// bne cr6,0x82422238
	if (!cr6.eq) goto loc_82422238;
	// rlwinm. r11,r11,0,1,1
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82422238
	if (cr0.eq) goto loc_82422238;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x824221d8
	ctx.lr = 0x82422238;
	sub_824221D8(ctx, base);
loc_82422238:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82421aa8
	ctx.lr = 0x82422240;
	sub_82421AA8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82422244:
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

__attribute__((alias("__imp__sub_82422258"))) PPC_WEAK_FUNC(sub_82422258);
PPC_FUNC_IMPL(__imp__sub_82422258) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82422260;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130b50
	ctx.lr = 0x82422278;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x82422288
	if (!cr0.eq) goto loc_82422288;
loc_82422280:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82422318
	goto loc_82422318;
loc_82422288:
	// lis r30,16
	r30.s64 = 1048576;
	// rlwinm. r10,r29,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// li r11,3
	r11.s64 = 3;
	// ori r30,r30,1
	r30.u64 = r30.u64 | 1;
	// beq 0x824222a8
	if (cr0.eq) goto loc_824222A8;
	// lis r30,48
	r30.s64 = 3145728;
	// li r11,2
	r11.s64 = 2;
	// ori r30,r30,1
	r30.u64 = r30.u64 | 1;
loc_824222A8:
	// rlwinm. r10,r29,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x200;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824222b4
	if (cr0.eq) goto loc_824222B4;
	// oris r30,r30,64
	r30.u64 = r30.u64 | 4194304;
loc_824222B4:
	// lis r4,-32128
	ctx.r4.s64 = -2105540608;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwimi r4,r11,28,1,3
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 28) & 0x70000000) | (ctx.r4.u64 & 0xFFFFFFFF8FFFFFFF);
	// bl 0x82130b50
	ctx.lr = 0x824222C4;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x824222dc
	if (!cr0.eq) goto loc_824222DC;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x824222D8;
	sub_821310F8(ctx, base);
	// b 0x82422280
	goto loc_82422280;
loc_824222DC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r10,r28,0,6,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x3FFFFFC;
	// ori r9,r3,3
	ctx.r9.u64 = ctx.r3.u64 | 3;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// rlwinm r11,r11,0,4,4
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000000;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// oris r11,r11,4096
	r11.u64 = r11.u64 | 268435456;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
loc_82422318:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82422320"))) PPC_WEAK_FUNC(sub_82422320);
PPC_FUNC_IMPL(__imp__sub_82422320) {
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
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lis r9,768
	ctx.r9.s64 = 50331648;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r7,r11,0,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// rlwinm r10,r10,0,6,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3FFFFFC;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82421ca0
	ctx.lr = 0x82422360;
	sub_82421CA0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82422370"))) PPC_WEAK_FUNC(sub_82422370);
PPC_FUNC_IMPL(__imp__sub_82422370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r4,r11,0,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// b 0x82421f38
	sub_82421F38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82422380"))) PPC_WEAK_FUNC(sub_82422380);
PPC_FUNC_IMPL(__imp__sub_82422380) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82422388;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,32
	ctx.r3.s64 = 32;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82130b50
	ctx.lr = 0x824223A4;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x824223b4
	if (!cr0.eq) goto loc_824223B4;
loc_824223AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82422424
	goto loc_82422424;
loc_824223B4:
	// rlwinm r10,r30,29,0,2
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 29) & 0xE0000000;
	// rlwinm. r9,r29,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// oris r30,r10,16
	r30.u64 = ctx.r10.u64 | 1048576;
	// li r11,3
	r11.s64 = 3;
	// ori r30,r30,2
	r30.u64 = r30.u64 | 2;
	// beq 0x824223d4
	if (cr0.eq) goto loc_824223D4;
	// li r11,2
	r11.s64 = 2;
	// oris r30,r30,32
	r30.u64 = r30.u64 | 2097152;
loc_824223D4:
	// rlwinm. r10,r29,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x200;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824223e0
	if (cr0.eq) goto loc_824223E0;
	// oris r30,r30,64
	r30.u64 = r30.u64 | 4194304;
loc_824223E0:
	// lis r4,-32128
	ctx.r4.s64 = -2105540608;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwimi r4,r11,28,1,3
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 28) & 0x70000000) | (ctx.r4.u64 & 0xFFFFFFFF8FFFFFFF);
	// bl 0x82130b50
	ctx.lr = 0x824223F0;
	sub_82130B50(ctx, base);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne 0x82422408
	if (!cr0.eq) goto loc_82422408;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// bl 0x821310f8
	ctx.lr = 0x82422404;
	sub_821310F8(ctx, base);
	// b 0x824223ac
	goto loc_824223AC;
loc_82422408:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
loc_82422424:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8242242C"))) PPC_WEAK_FUNC(sub_8242242C);
PPC_FUNC_IMPL(__imp__sub_8242242C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82422430"))) PPC_WEAK_FUNC(sub_82422430);
PPC_FUNC_IMPL(__imp__sub_82422430) {
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
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// ori r11,r6,2
	r11.u64 = ctx.r6.u64 | 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82421ca0
	ctx.lr = 0x82422468;
	sub_82421CA0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82422478"))) PPC_WEAK_FUNC(sub_82422478);
PPC_FUNC_IMPL(__imp__sub_82422478) {
	PPC_FUNC_PROLOGUE();
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82421f38
	sub_82421F38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82422484"))) PPC_WEAK_FUNC(sub_82422484);
PPC_FUNC_IMPL(__imp__sub_82422484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82422488"))) PPC_WEAK_FUNC(sub_82422488);
PPC_FUNC_IMPL(__imp__sub_82422488) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-9688(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9688);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824225c4
	if (!cr6.eq) goto loc_824225C4;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824224c8
	if (!cr6.gt) goto loc_824224C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824224C8;
	sub_82412710(ctx, base);
loc_824224C8:
	// lis r11,2
	r11.s64 = 131072;
	// li r10,15
	ctx.r10.s64 = 15;
	// ori r11,r11,8448
	r11.u64 = r11.u64 | 8448;
	// li r9,14
	ctx.r9.s64 = 14;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,16
	r11.s64 = 16;
	// lis r8,-16384
	ctx.r8.s64 = -1073741824;
	// li r7,256
	ctx.r7.s64 = 256;
	// ori r8,r8,15104
	ctx.r8.u64 = ctx.r8.u64 | 15104;
	// lis r6,-16368
	ctx.r6.s64 = -1072693248;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// ori r10,r6,11008
	ctx.r10.u64 = ctx.r6.u64 | 11008;
	// li r6,15
	ctx.r6.s64 = 15;
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// li r5,60
	ctx.r5.s64 = 60;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// addi r4,r4,8188
	ctx.r4.s64 = ctx.r4.s64 + 8188;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r30,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r3.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stwu r6,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r30.u32 = ea;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x82422534;
	sub_823DA950(ctx, base);
	// addi r11,r30,60
	r11.s64 = r30.s64 + 60;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1792
	ctx.r9.s64 = 117440512;
	// ori r10,r10,8576
	ctx.r10.u64 = ctx.r10.u64 | 8576;
	// li r8,0
	ctx.r8.s64 = 0;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r10,8712
	ctx.r10.s64 = 8712;
	// li r7,4
	ctx.r7.s64 = 4;
	// lis r6,-16384
	ctx.r6.s64 = -1073741824;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// ori r6,r6,13824
	ctx.r6.u64 = ctx.r6.u64 | 13824;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// ori r5,r5,129
	ctx.r5.u64 = ctx.r5.u64 | 129;
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,41,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 41) & 0xFFFFFFFFFFFFFFFF;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// stwu r6,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r11.u32 = ea;
	// stwu r5,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	r11.u32 = ea;
	// ld r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// oris r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 524288;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// rldicr r12,r12,40,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 40) & 0xFFFFFFFFFFFFFFFF;
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// rldicr r12,r12,39,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 39) & 0xFFFFFFFFFFFFFFFF;
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// ori r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 8;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
loc_824225C4:
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

__attribute__((alias("__imp__sub_824225DC"))) PPC_WEAK_FUNC(sub_824225DC);
PPC_FUNC_IMPL(__imp__sub_824225DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824225E0"))) PPC_WEAK_FUNC(sub_824225E0);
PPC_FUNC_IMPL(__imp__sub_824225E0) {
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
	ctx.lr = 0x824225E8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r31,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, r31.u32);
	// lwz r11,-9684(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9684);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82422960
	if (!cr6.eq) goto loc_82422960;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x8242261c
	if (!cr6.gt) goto loc_8242261C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x8242261C;
	sub_82412710(ctx, base);
loc_8242261C:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// li r10,768
	ctx.r10.s64 = 768;
	// ori r11,r11,15104
	r11.u64 = r11.u64 | 15104;
	// lis r9,-16359
	ctx.r9.s64 = -1072103424;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r8,0
	ctx.r8.s64 = 0;
	// ori r9,r9,11008
	ctx.r9.u64 = ctx.r9.u64 | 11008;
	// li r7,24
	ctx.r7.s64 = 24;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r5,96
	ctx.r5.s64 = 96;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// addi r29,r11,8056
	r29.s64 = r11.s64 + 8056;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stwu r7,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r30.u32 = ea;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x82422668;
	sub_823DA950(ctx, base);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r11,r30,96
	r11.s64 = r30.s64 + 96;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82422688
	if (!cr6.gt) goto loc_82422688;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82422688;
	sub_82412710(ctx, base);
loc_82422688:
	// lis r11,-16374
	r11.s64 = -1073086464;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,11008
	r11.u64 = r11.u64 | 11008;
	// li r9,9
	ctx.r9.s64 = 9;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// addi r4,r29,96
	ctx.r4.s64 = r29.s64 + 96;
	// li r5,36
	ctx.r5.s64 = 36;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stwu r9,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r30.u32 = ea;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x824226B8;
	sub_823DA950(ctx, base);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r3,r30,36
	ctx.r3.s64 = r30.s64 + 36;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824226d4
	if (!cr6.gt) goto loc_824226D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824226D4;
	sub_82412710(ctx, base);
loc_824226D4:
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// ori r11,r11,8576
	r11.u64 = r11.u64 | 8576;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r8,8851
	ctx.r8.s64 = 8851;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// ori r9,r9,8448
	ctx.r9.u64 = ctx.r9.u64 | 8448;
	// ori r10,r7,65535
	ctx.r10.u64 = ctx.r7.u64 | 65535;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lis r6,2
	ctx.r6.s64 = 131072;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// ori r6,r6,8708
	ctx.r6.u64 = ctx.r6.u64 | 8708;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,768
	ctx.r4.s64 = 768;
	// li r31,8978
	r31.s64 = 8978;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// lis r30,0
	r30.s64 = 0;
	// li r29,8205
	r29.s64 = 8205;
	// ori r30,r30,65535
	r30.u64 = r30.u64 | 65535;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r28,8704
	r28.s64 = 8704;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// li r23,0
	r23.s64 = 0;
	// li r10,8707
	ctx.r10.s64 = 8707;
	// lwz r25,80(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r21,0
	r21.s64 = 0;
	// li r20,8712
	r20.s64 = 8712;
	// lwz r22,84(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r19,4
	r19.s64 = 4;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// li r18,8452
	r18.s64 = 8452;
	// li r17,0
	r17.s64 = 0;
	// li r8,8832
	ctx.r8.s64 = 8832;
	// lis r27,8
	r27.s64 = 524288;
	// li r16,8962
	r16.s64 = 8962;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// ori r27,r27,8
	r27.u64 = r27.u64 | 8;
	// li r15,4
	r15.s64 = 4;
	// lis r26,2
	r26.s64 = 131072;
	// li r14,0
	r14.s64 = 0;
	// ori r26,r26,8320
	r26.u64 = r26.u64 | 8320;
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r22.u32);
	ctx.r3.u32 = ea;
	// li r25,0
	r25.s64 = 0;
	// lis r24,16
	r24.s64 = 1048576;
	// ori r24,r24,16
	r24.u64 = r24.u64 | 16;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r31,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r31.u32);
	ctx.r3.u32 = ea;
	// lwz r31,260(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// stwu r30,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r3.u32 = ea;
	// stwu r29,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r29.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r28.u32);
	ctx.r3.u32 = ea;
	// stwu r23,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r23.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r21,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r21.u32);
	ctx.r3.u32 = ea;
	// stwu r20,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r20.u32);
	ctx.r3.u32 = ea;
	// stwu r19,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r19.u32);
	ctx.r3.u32 = ea;
	// stwu r18,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r18.u32);
	ctx.r3.u32 = ea;
	// stwu r17,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r17.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r27,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r27.u32);
	ctx.r3.u32 = ea;
	// stwu r16,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r16.u32);
	ctx.r3.u32 = ea;
	// stwu r15,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r15.u32);
	ctx.r3.u32 = ea;
	// stwu r26,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r3.u32 = ea;
	// stwu r14,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r14.u32);
	ctx.r3.u32 = ea;
	// stwu r25,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r25.u32);
	ctx.r3.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stwu r24,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r24.u32);
	r11.u32 = ea;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82422834
	if (!cr6.gt) goto loc_82422834;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82422834;
	sub_82412710(ctx, base);
loc_82422834:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// lis r10,512
	ctx.r10.s64 = 33554432;
	// ori r11,r11,13824
	r11.u64 = r11.u64 | 13824;
	// ori r10,r10,129
	ctx.r10.u64 = ctx.r10.u64 | 129;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r12,1
	r12.s64 = 1;
	// li r11,1
	r11.s64 = 1;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// rldicr r12,r12,41,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 41) & 0xFFFFFFFFFFFFFFFF;
	// rldicr r11,r11,35,63
	r11.u64 = __builtin_rotateleft64(r11.u64, 35) & 0xFFFFFFFFFFFFFFFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// stw r9,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r9.u32);
	// ld r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// rldicr r12,r12,40,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 40) & 0xFFFFFFFFFFFFFFFF;
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// rldicr r12,r12,39,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 39) & 0xFFFFFFFFFFFFFFFF;
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// ld r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | r11.u64;
	// std r10,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r10.u64);
	// rldicr r12,r12,44,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 44) & 0xFFFFFFFFFFFFFFFF;
	// ld r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// ori r10,r10,64
	ctx.r10.u64 = ctx.r10.u64 | 64;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// ld r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// oris r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 524288;
	// std r10,32(r31)
	PPC_STORE_U64(r31.u32 + 32, ctx.r10.u64);
	// ld r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// oris r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 524288;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// oris r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 1048576;
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// ori r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 2048;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// ori r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 256;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// ori r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 8;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// rldicr r12,r12,54,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 54) & 0xFFFFFFFFFFFFFFFF;
	// ld r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// or r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 | r12.u64;
	// std r10,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r10.u64);
	// ld r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r11.u64);
	// lwz r11,10436(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10436);
	// lwz r10,10440(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10440);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r10,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r7,r9,17
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 17;
	// rlwinm r11,r11,17,0,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFFFE0000;
	// srawi r6,r10,17
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 17;
	// srawi r5,r8,17
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 17;
	// srawi r4,r11,17
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFF) != 0);
	ctx.r4.s64 = r11.s32 >> 17;
	// bl 0x82413660
	ctx.lr = 0x82422960;
	sub_82413660(ctx, base);
loc_82422960:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82422968"))) PPC_WEAK_FUNC(sub_82422968);
PPC_FUNC_IMPL(__imp__sub_82422968) {
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
	ctx.lr = 0x82422970;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// clrlwi r27,r28,30
	r27.u64 = r28.u32 & 0x3;
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// ble cr6,0x824229a0
	if (!cr6.gt) goto loc_824229A0;
	// bl 0x82412710
	ctx.lr = 0x8242299C;
	sub_82412710(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
loc_824229A0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82422048
	ctx.lr = 0x824229A8;
	sub_82422048(ctx, base);
	// addi r11,r30,2598
	r11.s64 = r30.s64 + 2598;
	// addi r10,r30,12
	ctx.r10.s64 = r30.s64 + 12;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// li r7,1480
	ctx.r7.s64 = 1480;
	// stwx r3,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r3.u32);
	// srd r11,r9,r10
	r11.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// lis r10,2
	ctx.r10.s64 = 131072;
	// ld r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// stwu r10,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r8.u32 = ea;
	// lwz r11,13504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13504);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// bne cr6,0x82422a48
	if (!cr6.eq) goto loc_82422A48;
	// cmplwi cr6,r28,10
	cr6.compare<uint32_t>(r28.u32, 10, xer);
	// bne cr6,0x82422a14
	if (!cr6.eq) goto loc_82422A14;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// li r9,15
	ctx.r9.s64 = 15;
	// ori r10,r10,17920
	ctx.r10.u64 = ctx.r10.u64 | 17920;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// b 0x82422a20
	goto loc_82422A20;
loc_82422A14:
	// lwz r10,13508(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13508);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82422a48
	if (!cr6.eq) goto loc_82422A48;
loc_82422A20:
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82422488
	ctx.lr = 0x82422A2C;
	sub_82422488(ctx, base);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82422a48
	if (!cr6.gt) goto loc_82422A48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82422A44;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82422A48:
	// lwz r10,13504(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13504);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r27,13512(r31)
	PPC_STORE_U32(r31.u32 + 13512, r27.u32);
	// stw r9,13508(r31)
	PPC_STORE_U32(r31.u32 + 13508, ctx.r9.u32);
	// stw r11,13504(r31)
	PPC_STORE_U32(r31.u32 + 13504, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82422A6C"))) PPC_WEAK_FUNC(sub_82422A6C);
PPC_FUNC_IMPL(__imp__sub_82422A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82422A70"))) PPC_WEAK_FUNC(sub_82422A70);
PPC_FUNC_IMPL(__imp__sub_82422A70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82422A78;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r29,2598
	r11.s64 = r29.s64 + 2598;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82422ab4
	if (!cr6.gt) goto loc_82422AB4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82422AB4;
	sub_82412710(ctx, base);
loc_82422AB4:
	// addi r11,r29,8198
	r11.s64 = r29.s64 + 8198;
	// li r10,0
	ctx.r10.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// beq cr6,0x82422ae0
	if (cr6.eq) goto loc_82422AE0;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// b 0x82422b30
	goto loc_82422B30;
loc_82422AE0:
	// lwz r11,10912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10912);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82422b30
	if (cr0.eq) goto loc_82422B30;
	// lwz r11,13528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13528);
	// lwz r3,13524(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13524);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x82422b08
	if (cr6.lt) goto loc_82422B08;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a630
	ctx.lr = 0x82422B08;
	sub_8241A630(ctx, base);
loc_82422B08:
	// lwz r11,144(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// rlwimi r11,r30,30,2,31
	r11.u64 = (__builtin_rotateleft32(r30.u32, 30) & 0x3FFFFFFF) | (r11.u64 & 0xFFFFFFFFC0000000);
	// stw r10,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// oris r11,r11,16384
	r11.u64 = r11.u64 | 1073741824;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// ld r11,144(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// stw r9,13524(r31)
	PPC_STORE_U32(r31.u32 + 13524, ctx.r9.u32);
loc_82422B30:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82422b5c
	if (!cr6.eq) goto loc_82422B5C;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r9,r11,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r5,r10,0,6,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3FFFFFC;
	// rlwinm r11,r9,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r9,3
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// b 0x82422be4
	goto loc_82422BE4;
loc_82422B5C:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82422bf8
	if (!cr6.eq) goto loc_82422BF8;
	// addi r10,r1,116
	ctx.r10.s64 = ctx.r1.s64 + 116;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r9,r1,120
	ctx.r9.s64 = ctx.r1.s64 + 120;
	// lwz r29,48(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r8,r1,124
	ctx.r8.s64 = ctx.r1.s64 + 124;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,132
	ctx.r9.s64 = ctx.r1.s64 + 132;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,136
	ctx.r7.s64 = ctx.r1.s64 + 136;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r27,r11,0,0,19
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// rlwinm r30,r29,0,0,19
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFF000;
	// bl 0x8240ff78
	ctx.lr = 0x82422BB0;
	sub_8240FF78(ctx, base);
	// rlwinm r11,r27,12,20,31
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 12) & 0xFFF;
	// lwz r5,112(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// clrlwi r10,r27,3
	ctx.r10.u64 = r27.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x824220a0
	ctx.lr = 0x82422BD0;
	sub_824220A0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82422bf8
	if (cr6.eq) goto loc_82422BF8;
	// lwz r5,112(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// rlwinm r11,r30,12,20,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r30,3
	ctx.r10.u64 = r30.u32 & 0x1FFFFFFF;
loc_82422BE4:
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x824220a0
	ctx.lr = 0x82422BF8;
	sub_824220A0(ctx, base);
loc_82422BF8:
	// lwz r11,13504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13504);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// stw r11,13504(r31)
	PPC_STORE_U32(r31.u32 + 13504, r11.u32);
	// ble cr6,0x82422c1c
	if (!cr6.gt) goto loc_82422C1C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82422C1C;
	sub_82412710(ctx, base);
loc_82422C1C:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// li r10,6
	ctx.r10.s64 = 6;
	// ori r11,r11,17920
	r11.u64 = r11.u64 | 17920;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r11,13504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13504);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// bne cr6,0x82422c84
	if (!cr6.eq) goto loc_82422C84;
	// cmplwi cr6,r28,1
	cr6.compare<uint32_t>(r28.u32, 1, xer);
	// beq cr6,0x82422c84
	if (cr6.eq) goto loc_82422C84;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82422c5c
	if (!cr6.gt) goto loc_82422C5C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82422C5C;
	sub_82412710(ctx, base);
loc_82422C5C:
	// li r11,1480
	r11.s64 = 1480;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// cmplwi cr6,r28,2
	cr6.compare<uint32_t>(r28.u32, 2, xer);
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// beq cr6,0x82422c8c
	if (cr6.eq) goto loc_82422C8C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824225e0
	ctx.lr = 0x82422C80;
	sub_824225E0(ctx, base);
	// b 0x82422c8c
	goto loc_82422C8C;
loc_82422C84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82422488
	ctx.lr = 0x82422C8C;
	sub_82422488(ctx, base);
loc_82422C8C:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82422ca4
	if (!cr6.gt) goto loc_82422CA4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82422CA4;
	sub_82412710(ctx, base);
loc_82422CA4:
	// lwz r11,13504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13504);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82422cc0
	if (!cr6.eq) goto loc_82422CC0;
	// cmplwi cr6,r28,1
	cr6.compare<uint32_t>(r28.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82422cc4
	if (cr6.eq) goto loc_82422CC4;
loc_82422CC0:
	// li r11,0
	r11.s64 = 0;
loc_82422CC4:
	// stw r11,13508(r31)
	PPC_STORE_U32(r31.u32 + 13508, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82422CD0"))) PPC_WEAK_FUNC(sub_82422CD0);
PPC_FUNC_IMPL(__imp__sub_82422CD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// beq cr6,0x82422de4
	if (cr6.eq) goto loc_82422DE4;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm. r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82422de4
	if (!cr0.eq) goto loc_82422DE4;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82422d08
	if (cr6.eq) goto loc_82422D08;
	// lwz r10,20(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// rlwinm. r10,r10,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82422de4
	if (!cr0.eq) goto loc_82422DE4;
loc_82422D08:
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r7,r11,27,27,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1F;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r11,0
	r11.s64 = 0;
	// lwz r6,20(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm. r9,r6,27,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1F;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,9
	ctx.r10.s64 = ctx.r10.s64 + 9;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,0
	ctx.r6.s64 = 0;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// beq 0x82422dc0
	if (cr0.eq) goto loc_82422DC0;
loc_82422D40:
	// lwz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// bge cr6,0x82422ddc
	if (!cr6.lt) goto loc_82422DDC;
loc_82422D50:
	// lbz r5,3(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// cmplw cr6,r5,r4
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, xer);
	// bge cr6,0x82422d6c
	if (!cr6.lt) goto loc_82422D6C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x82422d50
	if (cr6.lt) goto loc_82422D50;
loc_82422D6C:
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bge cr6,0x82422ddc
	if (!cr6.lt) goto loc_82422DDC;
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r30,r5,24
	r30.u64 = ctx.r5.u32 & 0xFF;
	// cmplw cr6,r30,r4
	cr6.compare<uint32_t>(r30.u32, ctx.r4.u32, xer);
	// bgt cr6,0x82422ddc
	if (cr6.gt) goto loc_82422DDC;
	// rlwinm r4,r5,20,12,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 20) & 0xFFFFF;
	// rlwinm r30,r3,20,12,31
	r30.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 20) & 0xFFFFF;
	// andc r4,r30,r4
	ctx.r4.u64 = r30.u64 & ~ctx.r4.u64;
	// clrlwi. r4,r4,28
	ctx.r4.u64 = ctx.r4.u32 & 0xF;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x82422ddc
	if (!cr0.eq) goto loc_82422DDC;
	// xor r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 ^ ctx.r3.u64;
	// rlwinm. r5,r5,0,20,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xF00;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x82422da8
	if (cr0.eq) goto loc_82422DA8;
	// li r31,1
	r31.s64 = 1;
loc_82422DA8:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r6,r9
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, xer);
	// blt cr6,0x82422d40
	if (cr6.lt) goto loc_82422D40;
loc_82422DC0:
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bge cr6,0x82422dcc
	if (!cr6.lt) goto loc_82422DCC;
	// li r31,1
	r31.s64 = 1;
loc_82422DCC:
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// b 0x82422de8
	goto loc_82422DE8;
loc_82422DDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82422de8
	goto loc_82422DE8;
loc_82422DE4:
	// li r3,2
	ctx.r3.s64 = 2;
loc_82422DE8:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82422DF4"))) PPC_WEAK_FUNC(sub_82422DF4);
PPC_FUNC_IMPL(__imp__sub_82422DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82422DF8"))) PPC_WEAK_FUNC(sub_82422DF8);
PPC_FUNC_IMPL(__imp__sub_82422DF8) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82422E00;
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// beq cr6,0x82422ef0
	if (cr6.eq) goto loc_82422EF0;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm. r11,r10,0,13,13
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82422ef0
	if (!cr0.eq) goto loc_82422EF0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82422e30
	if (cr6.eq) goto loc_82422E30;
	// lwz r11,20(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// rlwinm. r11,r11,0,14,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82422ef0
	if (!cr0.eq) goto loc_82422EF0;
loc_82422E30:
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r6,r10,27,27,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1F;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,20(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r31,0
	r31.s64 = 0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm. r9,r8,27,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1F;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,9
	r11.s64 = r11.s64 + 9;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// beq 0x82422eb4
	if (cr0.eq) goto loc_82422EB4;
	// mr r31,r9
	r31.u64 = ctx.r9.u64;
loc_82422E6C:
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// clrlwi r30,r5,24
	r30.u64 = ctx.r5.u32 & 0xFF;
	// b 0x82422e8c
	goto loc_82422E8C;
loc_82422E78:
	// lbz r29,3(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// bge cr6,0x82422e94
	if (!cr6.lt) goto loc_82422E94;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_82422E8C:
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// blt cr6,0x82422e78
	if (cr6.lt) goto loc_82422E78;
loc_82422E94:
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne 0x82422e6c
	if (!cr0.eq) goto loc_82422E6C;
loc_82422EB4:
	// cmplw cr6,r31,r6
	cr6.compare<uint32_t>(r31.u32, ctx.r6.u32, xer);
	// bge cr6,0x82422ed8
	if (!cr6.lt) goto loc_82422ED8;
	// subf. r11,r31,r6
	r11.s64 = ctx.r6.s64 - r31.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq 0x82422ed8
	if (cr0.eq) goto loc_82422ED8;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_82422ECC:
	// stw r10,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x82422ecc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82422ECC;
loc_82422ED8:
	// li r11,0
	r11.s64 = 0;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// lwz r11,20(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// rlwimi r10,r11,0,13,31
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x7FFFF) | (ctx.r10.u64 & 0xFFFFFFFFFFF80000);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
loc_82422EF0:
	// b 0x823d924c
	return;
}

