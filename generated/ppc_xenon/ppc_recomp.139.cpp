#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_826B5FA4"))) PPC_WEAK_FUNC(sub_826B5FA4);
PPC_FUNC_IMPL(__imp__sub_826B5FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B5FA8"))) PPC_WEAK_FUNC(sub_826B5FA8);
PPC_FUNC_IMPL(__imp__sub_826B5FA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32149
	r11.s64 = -2106916864;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,21048
	ctx.r3.s64 = r11.s64 + 21048;
	// b 0x826b5d88
	sub_826B5D88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B5FB8"))) PPC_WEAK_FUNC(sub_826B5FB8);
PPC_FUNC_IMPL(__imp__sub_826B5FB8) {
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
	ctx.lr = 0x826B5FC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,92
	ctx.r3.s64 = 92;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// xori r29,r4,1
	r29.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x82130528
	ctx.lr = 0x826B6000;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6028
	if (cr6.eq) goto loc_826B6028;
	// clrlwi r6,r29,24
	ctx.r6.u64 = r29.u32 & 0xFF;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826b74b0
	ctx.lr = 0x826B6018;
	sub_826B74B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826B6028:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B603C"))) PPC_WEAK_FUNC(sub_826B603C);
PPC_FUNC_IMPL(__imp__sub_826B603C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6040"))) PPC_WEAK_FUNC(sub_826B6040);
PPC_FUNC_IMPL(__imp__sub_826B6040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32149
	r11.s64 = -2106916864;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,21136
	ctx.r3.s64 = r11.s64 + 21136;
	// b 0x826b5e00
	sub_826B5E00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B6050"))) PPC_WEAK_FUNC(sub_826B6050);
PPC_FUNC_IMPL(__imp__sub_826B6050) {
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
	ctx.lr = 0x826B6058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,128
	ctx.r3.s64 = 128;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// xori r29,r4,1
	r29.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x82130528
	ctx.lr = 0x826B6098;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b60c0
	if (cr6.eq) goto loc_826B60C0;
	// clrlwi r6,r29,24
	ctx.r6.u64 = r29.u32 & 0xFF;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826b76d8
	ctx.lr = 0x826B60B0;
	sub_826B76D8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826B60C0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B60D4"))) PPC_WEAK_FUNC(sub_826B60D4);
PPC_FUNC_IMPL(__imp__sub_826B60D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B60D8"))) PPC_WEAK_FUNC(sub_826B60D8);
PPC_FUNC_IMPL(__imp__sub_826B60D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32149
	r11.s64 = -2106916864;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,21232
	ctx.r3.s64 = r11.s64 + 21232;
	// b 0x826b5d88
	sub_826B5D88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B60E8"))) PPC_WEAK_FUNC(sub_826B60E8);
PPC_FUNC_IMPL(__imp__sub_826B60E8) {
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
	ctx.lr = 0x826B60F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,92
	ctx.r3.s64 = 92;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// xori r29,r4,1
	r29.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x82130528
	ctx.lr = 0x826B6130;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6158
	if (cr6.eq) goto loc_826B6158;
	// clrlwi r6,r29,24
	ctx.r6.u64 = r29.u32 & 0xFF;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826b7dc8
	ctx.lr = 0x826B6148;
	sub_826B7DC8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826B6158:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B616C"))) PPC_WEAK_FUNC(sub_826B616C);
PPC_FUNC_IMPL(__imp__sub_826B616C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6170"))) PPC_WEAK_FUNC(sub_826B6170);
PPC_FUNC_IMPL(__imp__sub_826B6170) {
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
	ctx.lr = 0x826B6178;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,96
	ctx.r3.s64 = 96;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// xori r29,r4,1
	r29.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x82130528
	ctx.lr = 0x826B61B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b61e0
	if (cr6.eq) goto loc_826B61E0;
	// clrlwi r6,r29,24
	ctx.r6.u64 = r29.u32 & 0xFF;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826b7e38
	ctx.lr = 0x826B61D0;
	sub_826B7E38(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826B61E0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B61F4"))) PPC_WEAK_FUNC(sub_826B61F4);
PPC_FUNC_IMPL(__imp__sub_826B61F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B61F8"))) PPC_WEAK_FUNC(sub_826B61F8);
PPC_FUNC_IMPL(__imp__sub_826B61F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32149
	r11.s64 = -2106916864;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,21408
	ctx.r3.s64 = r11.s64 + 21408;
	// b 0x826b5d88
	sub_826B5D88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B6208"))) PPC_WEAK_FUNC(sub_826B6208);
PPC_FUNC_IMPL(__imp__sub_826B6208) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18504(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// b 0x826b5cf0
	sub_826B5CF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B6224"))) PPC_WEAK_FUNC(sub_826B6224);
PPC_FUNC_IMPL(__imp__sub_826B6224) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6228"))) PPC_WEAK_FUNC(sub_826B6228);
PPC_FUNC_IMPL(__imp__sub_826B6228) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, xer);
	// beq cr6,0x826b625c
	if (cr6.eq) goto loc_826B625C;
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_826B6248:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r7,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r7.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x826b6248
	if (!cr6.eq) goto loc_826B6248;
loc_826B625C:
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r8.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6274"))) PPC_WEAK_FUNC(sub_826B6274);
PPC_FUNC_IMPL(__imp__sub_826B6274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6278"))) PPC_WEAK_FUNC(sub_826B6278);
PPC_FUNC_IMPL(__imp__sub_826B6278) {
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
	// lis r11,-32149
	r11.s64 = -2106916864;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,24200
	ctx.r4.s64 = r11.s64 + 24200;
	// addi r3,r10,-19240
	ctx.r3.s64 = ctx.r10.s64 + -19240;
	// bl 0x82554798
	ctx.lr = 0x826B6298;
	sub_82554798(ctx, base);
	// lis r9,-32149
	ctx.r9.s64 = -2106916864;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,24216
	ctx.r4.s64 = ctx.r9.s64 + 24216;
	// addi r3,r8,-19272
	ctx.r3.s64 = ctx.r8.s64 + -19272;
	// bl 0x82554798
	ctx.lr = 0x826B62AC;
	sub_82554798(ctx, base);
	// lis r7,-32149
	ctx.r7.s64 = -2106916864;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,24352
	ctx.r4.s64 = ctx.r7.s64 + 24352;
	// addi r3,r6,-19312
	ctx.r3.s64 = ctx.r6.s64 + -19312;
	// bl 0x82554798
	ctx.lr = 0x826B62C0;
	sub_82554798(ctx, base);
	// lis r5,-32149
	ctx.r5.s64 = -2106916864;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,23264
	ctx.r4.s64 = ctx.r5.s64 + 23264;
	// addi r3,r3,-19352
	ctx.r3.s64 = ctx.r3.s64 + -19352;
	// bl 0x82554798
	ctx.lr = 0x826B62D4;
	sub_82554798(ctx, base);
	// lis r11,-32149
	r11.s64 = -2106916864;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,23400
	ctx.r4.s64 = r11.s64 + 23400;
	// addi r3,r10,-19384
	ctx.r3.s64 = ctx.r10.s64 + -19384;
	// bl 0x82554798
	ctx.lr = 0x826B62E8;
	sub_82554798(ctx, base);
	// lis r9,-32149
	ctx.r9.s64 = -2106916864;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,24488
	ctx.r4.s64 = ctx.r9.s64 + 24488;
	// addi r3,r8,-19416
	ctx.r3.s64 = ctx.r8.s64 + -19416;
	// bl 0x82554798
	ctx.lr = 0x826B62FC;
	sub_82554798(ctx, base);
	// lis r7,-32149
	ctx.r7.s64 = -2106916864;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,23536
	ctx.r4.s64 = ctx.r7.s64 + 23536;
	// addi r3,r6,-19452
	ctx.r3.s64 = ctx.r6.s64 + -19452;
	// bl 0x82554798
	ctx.lr = 0x826B6310;
	sub_82554798(ctx, base);
	// lis r5,-32149
	ctx.r5.s64 = -2106916864;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,24504
	ctx.r4.s64 = ctx.r5.s64 + 24504;
	// addi r3,r3,-19492
	ctx.r3.s64 = ctx.r3.s64 + -19492;
	// bl 0x82554798
	ctx.lr = 0x826B6324;
	sub_82554798(ctx, base);
	// lis r11,-32149
	r11.s64 = -2106916864;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,24640
	ctx.r4.s64 = r11.s64 + 24640;
	// addi r3,r10,-19528
	ctx.r3.s64 = ctx.r10.s64 + -19528;
	// bl 0x82554798
	ctx.lr = 0x826B6338;
	sub_82554798(ctx, base);
	// lis r9,-32149
	ctx.r9.s64 = -2106916864;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,24656
	ctx.r4.s64 = ctx.r9.s64 + 24656;
	// addi r3,r8,-19564
	ctx.r3.s64 = ctx.r8.s64 + -19564;
	// bl 0x82554798
	ctx.lr = 0x826B634C;
	sub_82554798(ctx, base);
	// lis r7,-32149
	ctx.r7.s64 = -2106916864;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,24792
	ctx.r4.s64 = ctx.r7.s64 + 24792;
	// addi r3,r6,-19604
	ctx.r3.s64 = ctx.r6.s64 + -19604;
	// bl 0x82554798
	ctx.lr = 0x826B6360;
	sub_82554798(ctx, base);
	// lis r5,-32149
	ctx.r5.s64 = -2106916864;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,24808
	ctx.r4.s64 = ctx.r5.s64 + 24808;
	// addi r3,r3,-19648
	ctx.r3.s64 = ctx.r3.s64 + -19648;
	// bl 0x82554798
	ctx.lr = 0x826B6374;
	sub_82554798(ctx, base);
	// lis r11,-32149
	r11.s64 = -2106916864;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,24944
	ctx.r4.s64 = r11.s64 + 24944;
	// addi r3,r10,-19696
	ctx.r3.s64 = ctx.r10.s64 + -19696;
	// bl 0x82554798
	ctx.lr = 0x826B6388;
	sub_82554798(ctx, base);
	// lis r9,-32149
	ctx.r9.s64 = -2106916864;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,23672
	ctx.r4.s64 = ctx.r9.s64 + 23672;
	// addi r3,r8,-19736
	ctx.r3.s64 = ctx.r8.s64 + -19736;
	// bl 0x82554798
	ctx.lr = 0x826B639C;
	sub_82554798(ctx, base);
	// lis r7,-32149
	ctx.r7.s64 = -2106916864;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,25080
	ctx.r4.s64 = ctx.r7.s64 + 25080;
	// addi r3,r6,-19780
	ctx.r3.s64 = ctx.r6.s64 + -19780;
	// bl 0x82554798
	ctx.lr = 0x826B63B0;
	sub_82554798(ctx, base);
	// lis r5,-32199
	ctx.r5.s64 = -2110193664;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,1456
	ctx.r4.s64 = ctx.r5.s64 + 1456;
	// addi r3,r3,-19812
	ctx.r3.s64 = ctx.r3.s64 + -19812;
	// bl 0x82554798
	ctx.lr = 0x826B63C4;
	sub_82554798(ctx, base);
	// lis r11,-32149
	r11.s64 = -2106916864;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,25096
	ctx.r4.s64 = r11.s64 + 25096;
	// addi r3,r10,-19840
	ctx.r3.s64 = ctx.r10.s64 + -19840;
	// bl 0x82554798
	ctx.lr = 0x826B63D8;
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

__attribute__((alias("__imp__sub_826B63E8"))) PPC_WEAK_FUNC(sub_826B63E8);
PPC_FUNC_IMPL(__imp__sub_826B63E8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-18460
	ctx.r3.s64 = r11.s64 + -18460;
	// bl 0x823d9750
	ctx.lr = 0x826B640C;
	sub_823D9750(ctx, base);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r10,-27048
	ctx.r8.s64 = ctx.r10.s64 + -27048;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r30,r9,-18472
	r30.s64 = ctx.r9.s64 + -18472;
	// addi r4,r7,10380
	ctx.r4.s64 = ctx.r7.s64 + 10380;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r5,r5,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// bl 0x823d9750
	ctx.lr = 0x826B6438;
	sub_823D9750(ctx, base);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r4,-18484
	ctx.r4.s64 = ctx.r4.s64 + -18484;
	// addi r5,r31,10
	ctx.r5.s64 = r31.s64 + 10;
	// bl 0x823d9750
	ctx.lr = 0x826B644C;
	sub_823D9750(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6464"))) PPC_WEAK_FUNC(sub_826B6464);
PPC_FUNC_IMPL(__imp__sub_826B6464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6468"))) PPC_WEAK_FUNC(sub_826B6468);
PPC_FUNC_IMPL(__imp__sub_826B6468) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r6,r11,-27048
	ctx.r6.s64 = r11.s64 + -27048;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_826B6488:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_826B6490:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x826b64b4
	if (cr6.eq) goto loc_826B64B4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826b6490
	if (cr6.eq) goto loc_826B6490;
loc_826B64B4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826b64f0
	if (cr6.eq) goto loc_826B64F0;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r11,r6,56
	r11.s64 = ctx.r6.s64 + 56;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// blt cr6,0x826b6488
	if (cr6.lt) goto loc_826B6488;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-18440
	ctx.r3.s64 = r11.s64 + -18440;
	// bl 0x82130000
	ctx.lr = 0x826B64DC;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B64F0:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6504"))) PPC_WEAK_FUNC(sub_826B6504);
PPC_FUNC_IMPL(__imp__sub_826B6504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6508"))) PPC_WEAK_FUNC(sub_826B6508);
PPC_FUNC_IMPL(__imp__sub_826B6508) {
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
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-18352
	ctx.r9.s64 = ctx.r10.s64 + -18352;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r3,r31,10
	ctx.r3.s64 = r31.s64 + 10;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// addi r4,r8,3998
	ctx.r4.s64 = ctx.r8.s64 + 3998;
	// stb r11,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r11.u8);
	// stb r11,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r11.u8);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// bl 0x823db670
	ctx.lr = 0x826B6554;
	sub_823DB670(ctx, base);
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

__attribute__((alias("__imp__sub_826B656C"))) PPC_WEAK_FUNC(sub_826B656C);
PPC_FUNC_IMPL(__imp__sub_826B656C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6570"))) PPC_WEAK_FUNC(sub_826B6570);
PPC_FUNC_IMPL(__imp__sub_826B6570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27560(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27560);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B657C"))) PPC_WEAK_FUNC(sub_826B657C);
PPC_FUNC_IMPL(__imp__sub_826B657C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6580"))) PPC_WEAK_FUNC(sub_826B6580);
PPC_FUNC_IMPL(__imp__sub_826B6580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r4,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r4.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826B6594"))) PPC_WEAK_FUNC(sub_826B6594);
PPC_FUNC_IMPL(__imp__sub_826B6594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6598"))) PPC_WEAK_FUNC(sub_826B6598);
PPC_FUNC_IMPL(__imp__sub_826B6598) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B65B0;
	sub_826B63E8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-15196
	ctx.r4.s64 = r11.s64 + -15196;
	// addi r3,r10,-18472
	ctx.r3.s64 = ctx.r10.s64 + -18472;
	// addi r5,r31,60
	ctx.r5.s64 = r31.s64 + 60;
	// bl 0x823d9750
	ctx.lr = 0x826B65C8;
	sub_823D9750(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r4,r9,-19880
	ctx.r4.s64 = ctx.r9.s64 + -19880;
	// addi r3,r8,-18332
	ctx.r3.s64 = ctx.r8.s64 + -18332;
	// bl 0x823d9750
	ctx.lr = 0x826B65E0;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B65F4"))) PPC_WEAK_FUNC(sub_826B65F4);
PPC_FUNC_IMPL(__imp__sub_826B65F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B65F8"))) PPC_WEAK_FUNC(sub_826B65F8);
PPC_FUNC_IMPL(__imp__sub_826B65F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27556(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27556);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6604"))) PPC_WEAK_FUNC(sub_826B6604);
PPC_FUNC_IMPL(__imp__sub_826B6604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6608"))) PPC_WEAK_FUNC(sub_826B6608);
PPC_FUNC_IMPL(__imp__sub_826B6608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27552(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27552);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6614"))) PPC_WEAK_FUNC(sub_826B6614);
PPC_FUNC_IMPL(__imp__sub_826B6614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6618"))) PPC_WEAK_FUNC(sub_826B6618);
PPC_FUNC_IMPL(__imp__sub_826B6618) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B6630;
	sub_826B63E8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-19084
	ctx.r4.s64 = r11.s64 + -19084;
	// addi r3,r10,-18472
	ctx.r3.s64 = ctx.r10.s64 + -18472;
	// addi r5,r31,60
	ctx.r5.s64 = r31.s64 + 60;
	// bl 0x823d9750
	ctx.lr = 0x826B6648;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B665C"))) PPC_WEAK_FUNC(sub_826B665C);
PPC_FUNC_IMPL(__imp__sub_826B665C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6660"))) PPC_WEAK_FUNC(sub_826B6660);
PPC_FUNC_IMPL(__imp__sub_826B6660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27548(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27548);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B666C"))) PPC_WEAK_FUNC(sub_826B666C);
PPC_FUNC_IMPL(__imp__sub_826B666C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6670"))) PPC_WEAK_FUNC(sub_826B6670);
PPC_FUNC_IMPL(__imp__sub_826B6670) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x826b66b4
	if (cr6.eq) goto loc_826B66B4;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b66d0
	if (!cr6.gt) goto loc_826B66D0;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x826b66c4
	goto loc_826B66C4;
loc_826B66B4:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b66d0
	if (!cr6.gt) goto loc_826B66D0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_826B66C4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826b66d4
	if (!cr6.eq) goto loc_826B66D4;
loc_826B66D0:
	// li r11,0
	r11.s64 = 0;
loc_826B66D4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b6708
	if (cr6.eq) goto loc_826B6708;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r3,-29340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// bl 0x8269dbf8
	ctx.lr = 0x826B66F0;
	sub_8269DBF8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826B6708;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826B6708:
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

__attribute__((alias("__imp__sub_826B671C"))) PPC_WEAK_FUNC(sub_826B671C);
PPC_FUNC_IMPL(__imp__sub_826B671C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6720"))) PPC_WEAK_FUNC(sub_826B6720);
PPC_FUNC_IMPL(__imp__sub_826B6720) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B6738;
	sub_826B63E8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-18248
	ctx.r4.s64 = r11.s64 + -18248;
	// addi r3,r10,-18332
	ctx.r3.s64 = ctx.r10.s64 + -18332;
	// bl 0x823d9750
	ctx.lr = 0x826B6750;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B6764"))) PPC_WEAK_FUNC(sub_826B6764);
PPC_FUNC_IMPL(__imp__sub_826B6764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6768"))) PPC_WEAK_FUNC(sub_826B6768);
PPC_FUNC_IMPL(__imp__sub_826B6768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27544(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27544);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6774"))) PPC_WEAK_FUNC(sub_826B6774);
PPC_FUNC_IMPL(__imp__sub_826B6774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6778"))) PPC_WEAK_FUNC(sub_826B6778);
PPC_FUNC_IMPL(__imp__sub_826B6778) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x826b67bc
	if (cr6.eq) goto loc_826B67BC;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b67d8
	if (!cr6.gt) goto loc_826B67D8;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x826b67cc
	goto loc_826B67CC;
loc_826B67BC:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b67d8
	if (!cr6.gt) goto loc_826B67D8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_826B67CC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826b67dc
	if (!cr6.eq) goto loc_826B67DC;
loc_826B67D8:
	// li r11,0
	r11.s64 = 0;
loc_826B67DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b681c
	if (cr6.eq) goto loc_826B681C;
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b6814
	if (cr6.eq) goto loc_826B6814;
	// bl 0x82387b90
	ctx.lr = 0x826B67F8;
	sub_82387B90(ctx, base);
	// lwz r4,160(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// bl 0x8238b6e8
	ctx.lr = 0x826B6800;
	sub_8238B6E8(ctx, base);
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
loc_826B6814:
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x8238c4f8
	ctx.lr = 0x826B681C;
	sub_8238C4F8(ctx, base);
loc_826B681C:
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

__attribute__((alias("__imp__sub_826B6830"))) PPC_WEAK_FUNC(sub_826B6830);
PPC_FUNC_IMPL(__imp__sub_826B6830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r8,r10,-18208
	ctx.r8.s64 = ctx.r10.s64 + -18208;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B685C"))) PPC_WEAK_FUNC(sub_826B685C);
PPC_FUNC_IMPL(__imp__sub_826B685C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6860"))) PPC_WEAK_FUNC(sub_826B6860);
PPC_FUNC_IMPL(__imp__sub_826B6860) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27540(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27540);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B686C"))) PPC_WEAK_FUNC(sub_826B686C);
PPC_FUNC_IMPL(__imp__sub_826B686C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6870"))) PPC_WEAK_FUNC(sub_826B6870);
PPC_FUNC_IMPL(__imp__sub_826B6870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r4,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r4.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826B6884"))) PPC_WEAK_FUNC(sub_826B6884);
PPC_FUNC_IMPL(__imp__sub_826B6884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6888"))) PPC_WEAK_FUNC(sub_826B6888);
PPC_FUNC_IMPL(__imp__sub_826B6888) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B68A0;
	sub_826B63E8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-19880
	ctx.r4.s64 = r11.s64 + -19880;
	// addi r3,r10,-18332
	ctx.r3.s64 = ctx.r10.s64 + -18332;
	// bl 0x823d9750
	ctx.lr = 0x826B68B8;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B68CC"))) PPC_WEAK_FUNC(sub_826B68CC);
PPC_FUNC_IMPL(__imp__sub_826B68CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B68D0"))) PPC_WEAK_FUNC(sub_826B68D0);
PPC_FUNC_IMPL(__imp__sub_826B68D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27536(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27536);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B68DC"))) PPC_WEAK_FUNC(sub_826B68DC);
PPC_FUNC_IMPL(__imp__sub_826B68DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B68E0"))) PPC_WEAK_FUNC(sub_826B68E0);
PPC_FUNC_IMPL(__imp__sub_826B68E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x826b6910
	if (cr6.eq) goto loc_826B6910;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b692c
	if (!cr6.gt) goto loc_826B692C;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x826b6920
	goto loc_826B6920;
loc_826B6910:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b692c
	if (!cr6.gt) goto loc_826B692C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_826B6920:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826b6930
	if (!cr6.eq) goto loc_826B6930;
loc_826B692C:
	// li r11,0
	r11.s64 = 0;
loc_826B6930:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r4,r3,60
	ctx.r4.s64 = ctx.r3.s64 + 60;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826B6960"))) PPC_WEAK_FUNC(sub_826B6960);
PPC_FUNC_IMPL(__imp__sub_826B6960) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6964"))) PPC_WEAK_FUNC(sub_826B6964);
PPC_FUNC_IMPL(__imp__sub_826B6964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6968"))) PPC_WEAK_FUNC(sub_826B6968);
PPC_FUNC_IMPL(__imp__sub_826B6968) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B6980;
	sub_826B63E8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,9848
	ctx.r4.s64 = r11.s64 + 9848;
	// addi r3,r10,-18472
	ctx.r3.s64 = ctx.r10.s64 + -18472;
	// addi r5,r31,60
	ctx.r5.s64 = r31.s64 + 60;
	// bl 0x823d9750
	ctx.lr = 0x826B6998;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B69AC"))) PPC_WEAK_FUNC(sub_826B69AC);
PPC_FUNC_IMPL(__imp__sub_826B69AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B69B0"))) PPC_WEAK_FUNC(sub_826B69B0);
PPC_FUNC_IMPL(__imp__sub_826B69B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27532(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27532);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B69BC"))) PPC_WEAK_FUNC(sub_826B69BC);
PPC_FUNC_IMPL(__imp__sub_826B69BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B69C0"))) PPC_WEAK_FUNC(sub_826B69C0);
PPC_FUNC_IMPL(__imp__sub_826B69C0) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B69D8;
	sub_826B63E8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-18140
	ctx.r4.s64 = r11.s64 + -18140;
	// addi r3,r10,-18472
	ctx.r3.s64 = ctx.r10.s64 + -18472;
	// addi r5,r31,92
	ctx.r5.s64 = r31.s64 + 92;
	// bl 0x823d9750
	ctx.lr = 0x826B69F0;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B6A04"))) PPC_WEAK_FUNC(sub_826B6A04);
PPC_FUNC_IMPL(__imp__sub_826B6A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6A08"))) PPC_WEAK_FUNC(sub_826B6A08);
PPC_FUNC_IMPL(__imp__sub_826B6A08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27528(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27528);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6A14"))) PPC_WEAK_FUNC(sub_826B6A14);
PPC_FUNC_IMPL(__imp__sub_826B6A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6A18"))) PPC_WEAK_FUNC(sub_826B6A18);
PPC_FUNC_IMPL(__imp__sub_826B6A18) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,-18116
	ctx.r10.s64 = r11.s64 + -18116;
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6a68
	if (cr6.eq) goto loc_826B6A68;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82727cc0
	ctx.lr = 0x826B6A4C;
	sub_82727CC0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x82727bb0
	ctx.lr = 0x826B6A58;
	sub_82727BB0(ctx, base);
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x82727d40
	ctx.lr = 0x826B6A60;
	sub_82727D40(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
loc_826B6A68:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,3888
	ctx.r10.s64 = r11.s64 + 3888;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826B6A7C;
	sub_821D2028(ctx, base);
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

__attribute__((alias("__imp__sub_826B6A90"))) PPC_WEAK_FUNC(sub_826B6A90);
PPC_FUNC_IMPL(__imp__sub_826B6A90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27524(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27524);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6A9C"))) PPC_WEAK_FUNC(sub_826B6A9C);
PPC_FUNC_IMPL(__imp__sub_826B6A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6AA0"))) PPC_WEAK_FUNC(sub_826B6AA0);
PPC_FUNC_IMPL(__imp__sub_826B6AA0) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B6AB8;
	sub_826B63E8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-7904
	ctx.r4.s64 = r11.s64 + -7904;
	// addi r3,r10,-18472
	ctx.r3.s64 = ctx.r10.s64 + -18472;
	// addi r5,r31,60
	ctx.r5.s64 = r31.s64 + 60;
	// bl 0x823d9750
	ctx.lr = 0x826B6AD0;
	sub_823D9750(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r4,r9,-19900
	ctx.r4.s64 = ctx.r9.s64 + -19900;
	// addi r3,r8,-18332
	ctx.r3.s64 = ctx.r8.s64 + -18332;
	// bl 0x823d9750
	ctx.lr = 0x826B6AE8;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B6AFC"))) PPC_WEAK_FUNC(sub_826B6AFC);
PPC_FUNC_IMPL(__imp__sub_826B6AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6B00"))) PPC_WEAK_FUNC(sub_826B6B00);
PPC_FUNC_IMPL(__imp__sub_826B6B00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27520(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27520);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6B0C"))) PPC_WEAK_FUNC(sub_826B6B0C);
PPC_FUNC_IMPL(__imp__sub_826B6B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6B10"))) PPC_WEAK_FUNC(sub_826B6B10);
PPC_FUNC_IMPL(__imp__sub_826B6B10) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B6B28;
	sub_826B63E8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-7904
	ctx.r4.s64 = r11.s64 + -7904;
	// addi r3,r10,-18472
	ctx.r3.s64 = ctx.r10.s64 + -18472;
	// addi r5,r31,60
	ctx.r5.s64 = r31.s64 + 60;
	// bl 0x823d9750
	ctx.lr = 0x826B6B40;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B6B54"))) PPC_WEAK_FUNC(sub_826B6B54);
PPC_FUNC_IMPL(__imp__sub_826B6B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6B58"))) PPC_WEAK_FUNC(sub_826B6B58);
PPC_FUNC_IMPL(__imp__sub_826B6B58) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B6B70;
	sub_826B63E8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-15196
	ctx.r4.s64 = r11.s64 + -15196;
	// addi r3,r10,-18472
	ctx.r3.s64 = ctx.r10.s64 + -18472;
	// addi r5,r31,60
	ctx.r5.s64 = r31.s64 + 60;
	// bl 0x823d9750
	ctx.lr = 0x826B6B88;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B6B9C"))) PPC_WEAK_FUNC(sub_826B6B9C);
PPC_FUNC_IMPL(__imp__sub_826B6B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6BA0"))) PPC_WEAK_FUNC(sub_826B6BA0);
PPC_FUNC_IMPL(__imp__sub_826B6BA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,12
	ctx.r9.s64 = 12;
	// addi r8,r10,-18020
	ctx.r8.s64 = ctx.r10.s64 + -18020;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6BCC"))) PPC_WEAK_FUNC(sub_826B6BCC);
PPC_FUNC_IMPL(__imp__sub_826B6BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6BD0"))) PPC_WEAK_FUNC(sub_826B6BD0);
PPC_FUNC_IMPL(__imp__sub_826B6BD0) {
	PPC_FUNC_PROLOGUE();
	// b 0x826b63e8
	sub_826B63E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B6BD4"))) PPC_WEAK_FUNC(sub_826B6BD4);
PPC_FUNC_IMPL(__imp__sub_826B6BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6BD8"))) PPC_WEAK_FUNC(sub_826B6BD8);
PPC_FUNC_IMPL(__imp__sub_826B6BD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27516(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27516);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6BE4"))) PPC_WEAK_FUNC(sub_826B6BE4);
PPC_FUNC_IMPL(__imp__sub_826B6BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6BE8"))) PPC_WEAK_FUNC(sub_826B6BE8);
PPC_FUNC_IMPL(__imp__sub_826B6BE8) {
	PPC_FUNC_PROLOGUE();
	// addi r4,r3,60
	ctx.r4.s64 = ctx.r3.s64 + 60;
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r3,r3,10
	ctx.r3.s64 = ctx.r3.s64 + 10;
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B6BF8"))) PPC_WEAK_FUNC(sub_826B6BF8);
PPC_FUNC_IMPL(__imp__sub_826B6BF8) {
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
	// bl 0x826b63e8
	ctx.lr = 0x826B6C10;
	sub_826B63E8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-17976
	ctx.r4.s64 = r11.s64 + -17976;
	// addi r3,r10,-18472
	ctx.r3.s64 = ctx.r10.s64 + -18472;
	// addi r5,r31,60
	ctx.r5.s64 = r31.s64 + 60;
	// bl 0x823d9750
	ctx.lr = 0x826B6C28;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826B6C3C"))) PPC_WEAK_FUNC(sub_826B6C3C);
PPC_FUNC_IMPL(__imp__sub_826B6C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6C40"))) PPC_WEAK_FUNC(sub_826B6C40);
PPC_FUNC_IMPL(__imp__sub_826B6C40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x826B6C54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6c70
	if (cr6.eq) goto loc_826B6C70;
	// bl 0x826b6508
	ctx.lr = 0x826B6C60;
	sub_826B6508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6C70:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6C84"))) PPC_WEAK_FUNC(sub_826B6C84);
PPC_FUNC_IMPL(__imp__sub_826B6C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6C88"))) PPC_WEAK_FUNC(sub_826B6C88);
PPC_FUNC_IMPL(__imp__sub_826B6C88) {
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
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x826B6C9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6cdc
	if (cr6.eq) goto loc_826B6CDC;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,-18316
	ctx.r8.s64 = ctx.r10.s64 + -18316;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6CDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6CF0"))) PPC_WEAK_FUNC(sub_826B6CF0);
PPC_FUNC_IMPL(__imp__sub_826B6CF0) {
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
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x826B6D04;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6d44
	if (cr6.eq) goto loc_826B6D44;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r8,r10,-18292
	ctx.r8.s64 = ctx.r10.s64 + -18292;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6D44:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6D58"))) PPC_WEAK_FUNC(sub_826B6D58);
PPC_FUNC_IMPL(__imp__sub_826B6D58) {
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
	// li r3,68
	ctx.r3.s64 = 68;
	// bl 0x82130528
	ctx.lr = 0x826B6D6C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6db4
	if (cr6.eq) goto loc_826B6DB4;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r8,3
	ctx.r8.s64 = 3;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// addi r7,r9,-18268
	ctx.r7.s64 = ctx.r9.s64 + -18268;
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6DB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6DC8"))) PPC_WEAK_FUNC(sub_826B6DC8);
PPC_FUNC_IMPL(__imp__sub_826B6DC8) {
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
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x826B6DDC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6e20
	if (cr6.eq) goto loc_826B6E20;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r8,r10,-18232
	ctx.r8.s64 = ctx.r10.s64 + -18232;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// stb r11,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6E20:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6E34"))) PPC_WEAK_FUNC(sub_826B6E34);
PPC_FUNC_IMPL(__imp__sub_826B6E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6E38"))) PPC_WEAK_FUNC(sub_826B6E38);
PPC_FUNC_IMPL(__imp__sub_826B6E38) {
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
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B6E4C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6e8c
	if (cr6.eq) goto loc_826B6E8C;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r8,r10,-18208
	ctx.r8.s64 = ctx.r10.s64 + -18208;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6E8C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6EA0"))) PPC_WEAK_FUNC(sub_826B6EA0);
PPC_FUNC_IMPL(__imp__sub_826B6EA0) {
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
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x826B6EB4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6ef8
	if (cr6.eq) goto loc_826B6EF8;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r8,r10,-18184
	ctx.r8.s64 = ctx.r10.s64 + -18184;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r7,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r7.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6EF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6F0C"))) PPC_WEAK_FUNC(sub_826B6F0C);
PPC_FUNC_IMPL(__imp__sub_826B6F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6F10"))) PPC_WEAK_FUNC(sub_826B6F10);
PPC_FUNC_IMPL(__imp__sub_826B6F10) {
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
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x826B6F24;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6f70
	if (cr6.eq) goto loc_826B6F70;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r8,r10,-18160
	ctx.r8.s64 = ctx.r10.s64 + -18160;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r7,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r7.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,124(r3)
	PPC_STORE_U8(ctx.r3.u32 + 124, r11.u8);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// stb r11,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6F70:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6F84"))) PPC_WEAK_FUNC(sub_826B6F84);
PPC_FUNC_IMPL(__imp__sub_826B6F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B6F88"))) PPC_WEAK_FUNC(sub_826B6F88);
PPC_FUNC_IMPL(__imp__sub_826B6F88) {
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
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x826B6F9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b6fe4
	if (cr6.eq) goto loc_826B6FE4;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r8,8
	ctx.r8.s64 = 8;
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// addi r7,r9,-18116
	ctx.r7.s64 = ctx.r9.s64 + -18116;
	// stb r10,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r10.u8);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stb r10,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r10.u8);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r11.u32);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B6FE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B6FF8"))) PPC_WEAK_FUNC(sub_826B6FF8);
PPC_FUNC_IMPL(__imp__sub_826B6FF8) {
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
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x826B700C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b7054
	if (cr6.eq) goto loc_826B7054;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,9
	ctx.r9.s64 = 9;
	// addi r8,r10,-18092
	ctx.r8.s64 = ctx.r10.s64 + -18092;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stw r7,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r7.u32);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B7054:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B7068"))) PPC_WEAK_FUNC(sub_826B7068);
PPC_FUNC_IMPL(__imp__sub_826B7068) {
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
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x826B707C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b70bc
	if (cr6.eq) goto loc_826B70BC;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r8,r10,-18068
	ctx.r8.s64 = ctx.r10.s64 + -18068;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B70BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B70D0"))) PPC_WEAK_FUNC(sub_826B70D0);
PPC_FUNC_IMPL(__imp__sub_826B70D0) {
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
	// li r3,156
	ctx.r3.s64 = 156;
	// bl 0x82130528
	ctx.lr = 0x826B70E4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b7124
	if (cr6.eq) goto loc_826B7124;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,13
	ctx.r9.s64 = 13;
	// addi r8,r10,-17996
	ctx.r8.s64 = ctx.r10.s64 + -17996;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826B7124:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B7138"))) PPC_WEAK_FUNC(sub_826B7138);
PPC_FUNC_IMPL(__imp__sub_826B7138) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-18352
	ctx.r9.s64 = ctx.r10.s64 + -18352;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stb r6,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r6.u8);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// stb r7,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r7.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r11.u8);
	// bl 0x823db670
	ctx.lr = 0x826B7180;
	sub_823DB670(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826B7198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_826B71B4"))) PPC_WEAK_FUNC(sub_826B71B4);
PPC_FUNC_IMPL(__imp__sub_826B71B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B71B8"))) PPC_WEAK_FUNC(sub_826B71B8);
PPC_FUNC_IMPL(__imp__sub_826B71B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r6,r3,60
	ctx.r6.s64 = ctx.r3.s64 + 60;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r3,r3,10
	ctx.r3.s64 = ctx.r3.s64 + 10;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B71D0"))) PPC_WEAK_FUNC(sub_826B71D0);
PPC_FUNC_IMPL(__imp__sub_826B71D0) {
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
	ctx.lr = 0x826B71D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x826b7214
	if (cr6.eq) goto loc_826B7214;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826b7230
	if (!cr6.gt) goto loc_826B7230;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x826b7224
	goto loc_826B7224;
loc_826B7214:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826b7230
	if (!cr6.gt) goto loc_826B7230;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_826B7224:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826b7234
	if (!cr6.eq) goto loc_826B7234;
loc_826B7230:
	// li r11,0
	r11.s64 = 0;
loc_826B7234:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b728c
	if (cr6.eq) goto loc_826B728C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x826B7248;
	sub_822A3998(ctx, base);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238f998
	ctx.lr = 0x826B7250;
	sub_8238F998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// lwz r31,24(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x8238ea08
	ctx.lr = 0x826B7260;
	sub_8238EA08(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-10020(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10020);
	// bl 0x826bce98
	ctx.lr = 0x826B7278;
	sub_826BCE98(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-10020(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10020);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x826bceb8
	ctx.lr = 0x826B728C;
	sub_826BCEB8(ctx, base);
loc_826B728C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826B7294"))) PPC_WEAK_FUNC(sub_826B7294);
PPC_FUNC_IMPL(__imp__sub_826B7294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7298"))) PPC_WEAK_FUNC(sub_826B7298);
PPC_FUNC_IMPL(__imp__sub_826B7298) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x826b72bc
	if (!cr6.eq) goto loc_826B72BC;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r6,60(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r5,r11,-17956
	ctx.r5.s64 = r11.s64 + -17956;
	// addi r3,r3,10
	ctx.r3.s64 = ctx.r3.s64 + 10;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
loc_826B72BC:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-24960
	ctx.r8.s64 = ctx.r10.s64 + -24960;
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r3,r3,10
	ctx.r3.s64 = ctx.r3.s64 + 10;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B72D8"))) PPC_WEAK_FUNC(sub_826B72D8);
PPC_FUNC_IMPL(__imp__sub_826B72D8) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,3888
	ctx.r10.s64 = r11.s64 + 3888;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826B7304;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826b731c
	if (cr6.eq) goto loc_826B731C;
	// bl 0x82130588
	ctx.lr = 0x826B7318;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826B731C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B7334"))) PPC_WEAK_FUNC(sub_826B7334);
PPC_FUNC_IMPL(__imp__sub_826B7334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7338"))) PPC_WEAK_FUNC(sub_826B7338);
PPC_FUNC_IMPL(__imp__sub_826B7338) {
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
	ctx.lr = 0x826B7340;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r11,-18232
	ctx.r9.s64 = r11.s64 + -18232;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r4,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r4.u32);
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// addi r29,r4,8109
	r29.s64 = ctx.r4.s64 + 8109;
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stb r7,156(r31)
	PPC_STORE_U8(r31.u32 + 156, ctx.r7.u8);
	// addi r28,r31,10
	r28.s64 = r31.s64 + 10;
	// bl 0x823db670
	ctx.lr = 0x826B7394;
	sub_823DB670(ctx, base);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823db670
	ctx.lr = 0x826B73A4;
	sub_823DB670(ctx, base);
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823db670
	ctx.lr = 0x826B73B4;
	sub_823DB670(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B73C0"))) PPC_WEAK_FUNC(sub_826B73C0);
PPC_FUNC_IMPL(__imp__sub_826B73C0) {
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
	ctx.lr = 0x826B73C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r8,r10,-18232
	ctx.r8.s64 = ctx.r10.s64 + -18232;
	// stb r6,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r6.u8);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stb r7,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r7.u8);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// stb r11,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r11.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r29,r31,10
	r29.s64 = r31.s64 + 10;
	// stb r11,156(r31)
	PPC_STORE_U8(r31.u32 + 156, r11.u8);
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// bl 0x823db670
	ctx.lr = 0x826B7414;
	sub_823DB670(ctx, base);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823db670
	ctx.lr = 0x826B7424;
	sub_823DB670(ctx, base);
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823db670
	ctx.lr = 0x826B7434;
	sub_823DB670(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B7440"))) PPC_WEAK_FUNC(sub_826B7440);
PPC_FUNC_IMPL(__imp__sub_826B7440) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r9,r11,-18208
	ctx.r9.s64 = r11.s64 + -18208;
	// li r10,5
	ctx.r10.s64 = 5;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// stw r4,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r4.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826B7488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_826B74A0"))) PPC_WEAK_FUNC(sub_826B74A0);
PPC_FUNC_IMPL(__imp__sub_826B74A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,60(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// b 0x826b93e0
	sub_826B93E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B74B0"))) PPC_WEAK_FUNC(sub_826B74B0);
PPC_FUNC_IMPL(__imp__sub_826B74B0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r9,r11,-18184
	ctx.r9.s64 = r11.s64 + -18184;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// bl 0x823db670
	ctx.lr = 0x826B74F4;
	sub_823DB670(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826B7508;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_826B7520"))) PPC_WEAK_FUNC(sub_826B7520);
PPC_FUNC_IMPL(__imp__sub_826B7520) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r9,r11,-18160
	ctx.r9.s64 = r11.s64 + -18160;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stb r8,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r8.u8);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r7,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r7.u8);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// stb r6,124(r31)
	PPC_STORE_U8(r31.u32 + 124, ctx.r6.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// bl 0x823db670
	ctx.lr = 0x826B7570;
	sub_823DB670(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826B7584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823db670
	ctx.lr = 0x826B7594;
	sub_823DB670(ctx, base);
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

__attribute__((alias("__imp__sub_826B75B0"))) PPC_WEAK_FUNC(sub_826B75B0);
PPC_FUNC_IMPL(__imp__sub_826B75B0) {
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
	// addi r3,r30,60
	ctx.r3.s64 = r30.s64 + 60;
	// bl 0x826c5850
	ctx.lr = 0x826B75D0;
	sub_826C5850(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826b7670
	if (cr6.eq) goto loc_826B7670;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b75f8
	if (!cr6.gt) goto loc_826B75F8;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x826b75fc
	if (cr6.lt) goto loc_826B75FC;
loc_826B75F8:
	// li r11,0
	r11.s64 = 0;
loc_826B75FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b7670
	if (!cr6.eq) goto loc_826B7670;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826b761c
	if (!cr6.eq) goto loc_826B761C;
	// lbz r11,693(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 693);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b7670
	if (cr6.eq) goto loc_826B7670;
loc_826B761C:
	// addi r3,r30,92
	ctx.r3.s64 = r30.s64 + 92;
	// bl 0x826cd4b8
	ctx.lr = 0x826B7624;
	sub_826CD4B8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x826b7648
	if (cr6.eq) goto loc_826B7648;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r30,124(r30)
	r30.u64 = PPC_LOAD_U8(r30.u32 + 124);
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826B7640;
	sub_826C3D98(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// b 0x826b7664
	goto loc_826B7664;
loc_826B7648:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6f40
	ctx.lr = 0x826B7650;
	sub_826C6F40(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826B7660;
	sub_826C3D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
loc_826B7664:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c67f8
	ctx.lr = 0x826B7670;
	sub_826C67F8(ctx, base);
loc_826B7670:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B7688"))) PPC_WEAK_FUNC(sub_826B7688);
PPC_FUNC_IMPL(__imp__sub_826B7688) {
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
	// bl 0x826b6a18
	ctx.lr = 0x826B76A8;
	sub_826B6A18(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b76c0
	if (cr6.eq) goto loc_826B76C0;
	// bl 0x82130588
	ctx.lr = 0x826B76BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826B76C0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B76D8"))) PPC_WEAK_FUNC(sub_826B76D8);
PPC_FUNC_IMPL(__imp__sub_826B76D8) {
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
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r8,r10,-18116
	ctx.r8.s64 = ctx.r10.s64 + -18116;
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// li r5,64
	ctx.r5.s64 = 64;
	// stb r11,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r11.u8);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// bl 0x823db670
	ctx.lr = 0x826B7720;
	sub_823DB670(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826B7734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_826B774C"))) PPC_WEAK_FUNC(sub_826B774C);
PPC_FUNC_IMPL(__imp__sub_826B774C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7750"))) PPC_WEAK_FUNC(sub_826B7750);
PPC_FUNC_IMPL(__imp__sub_826B7750) {
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
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b7780
	if (!cr6.eq) goto loc_826B7780;
	// li r4,300
	ctx.r4.s64 = 300;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x826bd870
	ctx.lr = 0x826B777C;
	sub_826BD870(ctx, base);
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
loc_826B7780:
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

__attribute__((alias("__imp__sub_826B7794"))) PPC_WEAK_FUNC(sub_826B7794);
PPC_FUNC_IMPL(__imp__sub_826B7794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7798"))) PPC_WEAK_FUNC(sub_826B7798);
PPC_FUNC_IMPL(__imp__sub_826B7798) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r7,92(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addi r6,r3,60
	ctx.r6.s64 = ctx.r3.s64 + 60;
	// addi r5,r11,-17940
	ctx.r5.s64 = r11.s64 + -17940;
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r3,r3,10
	ctx.r3.s64 = ctx.r3.s64 + 10;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B77B4"))) PPC_WEAK_FUNC(sub_826B77B4);
PPC_FUNC_IMPL(__imp__sub_826B77B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B77B8"))) PPC_WEAK_FUNC(sub_826B77B8);
PPC_FUNC_IMPL(__imp__sub_826B77B8) {
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
	ctx.lr = 0x826B77C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,17268
	r31.s64 = r11.s64 + 17268;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x826b77fc
	if (cr6.eq) goto loc_826B77FC;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b7818
	if (!cr6.gt) goto loc_826B7818;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x826b780c
	goto loc_826B780C;
loc_826B77FC:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b7818
	if (!cr6.gt) goto loc_826B7818;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_826B780C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826b781c
	if (!cr6.eq) goto loc_826B781C;
loc_826B7818:
	// li r11,0
	r11.s64 = 0;
loc_826B781C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b7880
	if (cr6.eq) goto loc_826B7880;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r5,r10,-17928
	ctx.r5.s64 = ctx.r10.s64 + -17928;
	// addi r4,r9,-24808
	ctx.r4.s64 = ctx.r9.s64 + -24808;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826B7844;
	sub_8268B770(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x826B7848;
	sub_82387B90(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r30,60
	ctx.r3.s64 = r30.s64 + 60;
	// lwz r30,92(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// bl 0x8238e998
	ctx.lr = 0x826B7858;
	sub_8238E998(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8238ad58
	ctx.lr = 0x826B7868;
	sub_8238AD58(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822a3998
	ctx.lr = 0x826B7874;
	sub_822A3998(ctx, base);
	// li r4,16512
	ctx.r4.s64 = 16512;
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238ef30
	ctx.lr = 0x826B7880;
	sub_8238EF30(ctx, base);
loc_826B7880:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826B7888"))) PPC_WEAK_FUNC(sub_826B7888);
PPC_FUNC_IMPL(__imp__sub_826B7888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r6,r3,60
	ctx.r6.s64 = ctx.r3.s64 + 60;
	// addi r5,r11,-17912
	ctx.r5.s64 = r11.s64 + -17912;
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r3,r3,10
	ctx.r3.s64 = ctx.r3.s64 + 10;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B78A0"))) PPC_WEAK_FUNC(sub_826B78A0);
PPC_FUNC_IMPL(__imp__sub_826B78A0) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x826b78e0
	if (cr6.eq) goto loc_826B78E0;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b78fc
	if (!cr6.gt) goto loc_826B78FC;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x826b78f0
	goto loc_826B78F0;
loc_826B78E0:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b78fc
	if (!cr6.gt) goto loc_826B78FC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_826B78F0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826b7900
	if (!cr6.eq) goto loc_826B7900;
loc_826B78FC:
	// li r11,0
	r11.s64 = 0;
loc_826B7900:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b7928
	if (cr6.eq) goto loc_826B7928;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r3,60
	ctx.r3.s64 = ctx.r3.s64 + 60;
	// lwz r31,-10020(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x82395fe8
	ctx.lr = 0x826B791C;
	sub_82395FE8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826bce80
	ctx.lr = 0x826B7928;
	sub_826BCE80(ctx, base);
loc_826B7928:
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

__attribute__((alias("__imp__sub_826B793C"))) PPC_WEAK_FUNC(sub_826B793C);
PPC_FUNC_IMPL(__imp__sub_826B793C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7940"))) PPC_WEAK_FUNC(sub_826B7940);
PPC_FUNC_IMPL(__imp__sub_826B7940) {
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
	PPCRegister f0{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826B7948;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x826B7964;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b79a8
	if (cr6.eq) goto loc_826B79A8;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x826B7978;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b79a8
	if (cr6.eq) goto loc_826B79A8;
	// lwz r3,132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// bl 0x8238efe8
	ctx.lr = 0x826B798C;
	sub_8238EFE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826b95c0
	ctx.lr = 0x826B799C;
	sub_826B95C0(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_826B79A8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,92(r28)
	PPC_STORE_U32(r28.u32 + 92, r30.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826B79C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B79C8"))) PPC_WEAK_FUNC(sub_826B79C8);
PPC_FUNC_IMPL(__imp__sub_826B79C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r6,92(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addi r7,r3,60
	ctx.r7.s64 = ctx.r3.s64 + 60;
	// addi r5,r11,-17964
	ctx.r5.s64 = r11.s64 + -17964;
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r3,r3,10
	ctx.r3.s64 = ctx.r3.s64 + 10;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B79E4"))) PPC_WEAK_FUNC(sub_826B79E4);
PPC_FUNC_IMPL(__imp__sub_826B79E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B79E8"))) PPC_WEAK_FUNC(sub_826B79E8);
PPC_FUNC_IMPL(__imp__sub_826B79E8) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x826b7a2c
	if (cr6.eq) goto loc_826B7A2C;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b7a48
	if (!cr6.gt) goto loc_826B7A48;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x826b7a3c
	goto loc_826B7A3C;
loc_826B7A2C:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826b7a48
	if (!cr6.gt) goto loc_826B7A48;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_826B7A3C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826b7a4c
	if (!cr6.eq) goto loc_826B7A4C;
loc_826B7A48:
	// li r11,0
	r11.s64 = 0;
loc_826B7A4C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b7a7c
	if (cr6.eq) goto loc_826B7A7C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r31,60
	ctx.r4.s64 = r31.s64 + 60;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826baf40
	ctx.lr = 0x826B7A68;
	sub_826BAF40(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b7a7c
	if (cr6.eq) goto loc_826B7A7C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x826bc348
	ctx.lr = 0x826B7A7C;
	sub_826BC348(ctx, base);
loc_826B7A7C:
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

__attribute__((alias("__imp__sub_826B7A90"))) PPC_WEAK_FUNC(sub_826B7A90);
PPC_FUNC_IMPL(__imp__sub_826B7A90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r6,60(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addi r4,r3,10
	ctx.r4.s64 = ctx.r3.s64 + 10;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,48
	ctx.r5.s64 = 48;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// b 0x82217b70
	sub_82217B70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B7AAC"))) PPC_WEAK_FUNC(sub_826B7AAC);
PPC_FUNC_IMPL(__imp__sub_826B7AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7AB0"))) PPC_WEAK_FUNC(sub_826B7AB0);
PPC_FUNC_IMPL(__imp__sub_826B7AB0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826B7AB8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x826B7ADC;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b7b30
	if (cr6.eq) goto loc_826B7B30;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x826B7AF0;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b7b30
	if (cr6.eq) goto loc_826B7B30;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// lwz r31,18508(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18508);
	// bl 0x8238f6b0
	ctx.lr = 0x826B7B0C;
	sub_8238F6B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x826b96c8
	ctx.lr = 0x826B7B20;
	sub_826B96C8(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_826B7B30:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,60(r28)
	PPC_STORE_U32(r28.u32 + 60, r30.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826B7B48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B7B54"))) PPC_WEAK_FUNC(sub_826B7B54);
PPC_FUNC_IMPL(__imp__sub_826B7B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7B58"))) PPC_WEAK_FUNC(sub_826B7B58);
PPC_FUNC_IMPL(__imp__sub_826B7B58) {
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
	ctx.lr = 0x826B7B60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,13
	ctx.r10.s64 = 13;
	// addi r9,r11,-17996
	ctx.r9.s64 = r11.s64 + -17996;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r6,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r6.u8);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stb r7,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r7.u8);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// addi r29,r31,10
	r29.s64 = r31.s64 + 10;
	// bl 0x823db670
	ctx.lr = 0x826B7BA4;
	sub_823DB670(ctx, base);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823db670
	ctx.lr = 0x826B7BB4;
	sub_823DB670(ctx, base);
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823db670
	ctx.lr = 0x826B7BC4;
	sub_823DB670(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B7BD0"))) PPC_WEAK_FUNC(sub_826B7BD0);
PPC_FUNC_IMPL(__imp__sub_826B7BD0) {
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
	ctx.lr = 0x826B7BD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-18316
	ctx.r9.s64 = r11.s64 + -18316;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r29,r31,10
	r29.s64 = r31.s64 + 10;
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// bl 0x823db670
	ctx.lr = 0x826B7C18;
	sub_823DB670(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r7,9572
	ctx.r5.s64 = ctx.r7.s64 + 9572;
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826B7C30;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826B7C3C"))) PPC_WEAK_FUNC(sub_826B7C3C);
PPC_FUNC_IMPL(__imp__sub_826B7C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7C40"))) PPC_WEAK_FUNC(sub_826B7C40);
PPC_FUNC_IMPL(__imp__sub_826B7C40) {
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
	ctx.lr = 0x826B7C48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,-18292
	ctx.r9.s64 = r11.s64 + -18292;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r29,r31,10
	r29.s64 = r31.s64 + 10;
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// bl 0x823db670
	ctx.lr = 0x826B7C88;
	sub_823DB670(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r7,9572
	ctx.r5.s64 = ctx.r7.s64 + 9572;
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826B7CA0;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826B7CAC"))) PPC_WEAK_FUNC(sub_826B7CAC);
PPC_FUNC_IMPL(__imp__sub_826B7CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7CB0"))) PPC_WEAK_FUNC(sub_826B7CB0);
PPC_FUNC_IMPL(__imp__sub_826B7CB0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r11,-18268
	ctx.r9.s64 = r11.s64 + -18268;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// stw r4,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r4.u32);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// addi r3,r31,10
	ctx.r3.s64 = r31.s64 + 10;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r5,r5,-17956
	ctx.r5.s64 = ctx.r5.s64 + -17956;
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// li r4,48
	ctx.r4.s64 = 48;
	// stw r7,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r7.u32);
	// bl 0x82137a08
	ctx.lr = 0x826B7D0C;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_826B7D24"))) PPC_WEAK_FUNC(sub_826B7D24);
PPC_FUNC_IMPL(__imp__sub_826B7D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7D28"))) PPC_WEAK_FUNC(sub_826B7D28);
PPC_FUNC_IMPL(__imp__sub_826B7D28) {
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
	ctx.lr = 0x826B7D30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r9,r11,-18092
	ctx.r9.s64 = r11.s64 + -18092;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r6,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r6.u8);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stb r7,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r7.u8);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// addi r29,r31,10
	r29.s64 = r31.s64 + 10;
	// bl 0x823db670
	ctx.lr = 0x826B7D74;
	sub_823DB670(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826B7D88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x826B7DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r7,92(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r5,r3,-17940
	ctx.r5.s64 = ctx.r3.s64 + -17940;
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826B7DBC;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B7DC8"))) PPC_WEAK_FUNC(sub_826B7DC8);
PPC_FUNC_IMPL(__imp__sub_826B7DC8) {
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
	ctx.lr = 0x826B7DD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r9,r11,-18068
	ctx.r9.s64 = r11.s64 + -18068;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r29,r31,10
	r29.s64 = r31.s64 + 10;
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// bl 0x823db670
	ctx.lr = 0x826B7E10;
	sub_823DB670(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r7,-17912
	ctx.r5.s64 = ctx.r7.s64 + -17912;
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826B7E28;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826B7E34"))) PPC_WEAK_FUNC(sub_826B7E34);
PPC_FUNC_IMPL(__imp__sub_826B7E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B7E38"))) PPC_WEAK_FUNC(sub_826B7E38);
PPC_FUNC_IMPL(__imp__sub_826B7E38) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,11
	ctx.r10.s64 = 11;
	// addi r9,r11,-18044
	ctx.r9.s64 = r11.s64 + -18044;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// bl 0x823db670
	ctx.lr = 0x826B7E7C;
	sub_823DB670(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826b7940
	ctx.lr = 0x826B7E88;
	sub_826B7940(ctx, base);
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

__attribute__((alias("__imp__sub_826B7EA0"))) PPC_WEAK_FUNC(sub_826B7EA0);
PPC_FUNC_IMPL(__imp__sub_826B7EA0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,12
	ctx.r10.s64 = 12;
	// addi r9,r11,-18020
	ctx.r9.s64 = r11.s64 + -18020;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r4,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r4.u8);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r5,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r5.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r8,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r8.u8);
	// lfs f1,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826b7ab0
	ctx.lr = 0x826B7EE8;
	sub_826B7AB0(ctx, base);
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

__attribute__((alias("__imp__sub_826B7F00"))) PPC_WEAK_FUNC(sub_826B7F00);
PPC_FUNC_IMPL(__imp__sub_826B7F00) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27564
	r31.s64 = r11.s64 + -27564;
	// lwz r11,-27564(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8000
	if (!cr6.eq) goto loc_826B8000;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B7F2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b7f3c
	if (cr6.eq) goto loc_826B7F3C;
	// bl 0x821d5408
	ctx.lr = 0x826B7F38;
	sub_821D5408(ctx, base);
	// b 0x826b7f40
	goto loc_826B7F40;
loc_826B7F3C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826B7F40:
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// addi r4,r8,-17888
	ctx.r4.s64 = ctx.r8.s64 + -17888;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,60
	ctx.r10.s64 = 60;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r8,r7,-27688
	ctx.r8.s64 = ctx.r7.s64 + -27688;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r7,r5,-27664
	ctx.r7.s64 = ctx.r5.s64 + -27664;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,8
	ctx.r10.s64 = 8;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x826B7FAC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826B7FBC;
	sub_821D4100(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B7FD8;
	sub_821D41D0(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r4,-27640
	ctx.r4.s64 = ctx.r4.s64 + -27640;
	// bl 0x821d4b00
	ctx.lr = 0x826B7FE8;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8000;
	sub_821C0548(ctx, base);
loc_826B8000:
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

__attribute__((alias("__imp__sub_826B8014"))) PPC_WEAK_FUNC(sub_826B8014);
PPC_FUNC_IMPL(__imp__sub_826B8014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8018"))) PPC_WEAK_FUNC(sub_826B8018);
PPC_FUNC_IMPL(__imp__sub_826B8018) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27560
	r31.s64 = r11.s64 + -27560;
	// lwz r11,-27560(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27560);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8154
	if (!cr6.eq) goto loc_826B8154;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8048;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b805c
	if (cr6.eq) goto loc_826B805C;
	// bl 0x821d5408
	ctx.lr = 0x826B8058;
	sub_821D5408(ctx, base);
	// b 0x826b8060
	goto loc_826B8060;
loc_826B805C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8060:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17876
	ctx.r7.s64 = ctx.r10.s64 + -17876;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,27712
	ctx.r4.s64 = ctx.r8.s64 + 27712;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r5,r10,-27604
	ctx.r5.s64 = ctx.r10.s64 + -27604;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r8,r3,-27628
	ctx.r8.s64 = ctx.r3.s64 + -27628;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,92
	ctx.r9.s64 = 92;
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// bne cr6,0x826b80ec
	if (!cr6.eq) goto loc_826B80EC;
	// bl 0x826b7f00
	ctx.lr = 0x826B80E8;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B80EC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B80F8;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8110;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B812C;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27580
	ctx.r4.s64 = ctx.r8.s64 + -27580;
	// bl 0x821d4b00
	ctx.lr = 0x826B813C;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8154;
	sub_821C0548(ctx, base);
loc_826B8154:
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

__attribute__((alias("__imp__sub_826B816C"))) PPC_WEAK_FUNC(sub_826B816C);
PPC_FUNC_IMPL(__imp__sub_826B816C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8170"))) PPC_WEAK_FUNC(sub_826B8170);
PPC_FUNC_IMPL(__imp__sub_826B8170) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27556
	r31.s64 = r11.s64 + -27556;
	// lwz r11,-27556(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27556);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b829c
	if (!cr6.eq) goto loc_826B829C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B81A0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b81b4
	if (cr6.eq) goto loc_826B81B4;
	// bl 0x821d5408
	ctx.lr = 0x826B81B0;
	sub_821D5408(ctx, base);
	// b 0x826b81b8
	goto loc_826B81B8;
loc_826B81B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B81B8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17856
	ctx.r7.s64 = ctx.r10.s64 + -17856;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,92
	ctx.r5.s64 = 92;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,27784
	ctx.r4.s64 = ctx.r8.s64 + 27784;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-27568
	ctx.r9.s64 = ctx.r3.s64 + -27568;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826b8234
	if (!cr6.eq) goto loc_826B8234;
	// bl 0x826b7f00
	ctx.lr = 0x826B8230;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B8234:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8240;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8258;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B8274;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27544
	ctx.r4.s64 = ctx.r8.s64 + -27544;
	// bl 0x821d4b00
	ctx.lr = 0x826B8284;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B829C;
	sub_821C0548(ctx, base);
loc_826B829C:
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

__attribute__((alias("__imp__sub_826B82B4"))) PPC_WEAK_FUNC(sub_826B82B4);
PPC_FUNC_IMPL(__imp__sub_826B82B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B82B8"))) PPC_WEAK_FUNC(sub_826B82B8);
PPC_FUNC_IMPL(__imp__sub_826B82B8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27552
	r31.s64 = r11.s64 + -27552;
	// lwz r11,-27552(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27552);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b83e4
	if (!cr6.eq) goto loc_826B83E4;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B82E8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b82fc
	if (cr6.eq) goto loc_826B82FC;
	// bl 0x821d5408
	ctx.lr = 0x826B82F8;
	sub_821D5408(ctx, base);
	// b 0x826b8300
	goto loc_826B8300;
loc_826B82FC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8300:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17840
	ctx.r7.s64 = ctx.r10.s64 + -17840;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,92
	ctx.r5.s64 = 92;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,27888
	ctx.r4.s64 = ctx.r8.s64 + 27888;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-27536
	ctx.r9.s64 = ctx.r3.s64 + -27536;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826b837c
	if (!cr6.eq) goto loc_826B837C;
	// bl 0x826b7f00
	ctx.lr = 0x826B8378;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B837C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8388;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B83A0;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B83BC;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27512
	ctx.r4.s64 = ctx.r8.s64 + -27512;
	// bl 0x821d4b00
	ctx.lr = 0x826B83CC;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B83E4;
	sub_821C0548(ctx, base);
loc_826B83E4:
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

__attribute__((alias("__imp__sub_826B83FC"))) PPC_WEAK_FUNC(sub_826B83FC);
PPC_FUNC_IMPL(__imp__sub_826B83FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8400"))) PPC_WEAK_FUNC(sub_826B8400);
PPC_FUNC_IMPL(__imp__sub_826B8400) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27548
	r31.s64 = r11.s64 + -27548;
	// lwz r11,-27548(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27548);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b852c
	if (!cr6.eq) goto loc_826B852C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8430;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b8444
	if (cr6.eq) goto loc_826B8444;
	// bl 0x821d5408
	ctx.lr = 0x826B8440;
	sub_821D5408(ctx, base);
	// b 0x826b8448
	goto loc_826B8448;
loc_826B8444:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8448:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17820
	ctx.r7.s64 = ctx.r10.s64 + -17820;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,68
	ctx.r5.s64 = 68;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,27992
	ctx.r4.s64 = ctx.r8.s64 + 27992;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-27504
	ctx.r9.s64 = ctx.r3.s64 + -27504;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826b84c4
	if (!cr6.eq) goto loc_826B84C4;
	// bl 0x826b7f00
	ctx.lr = 0x826B84C0;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B84C4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B84D0;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B84E8;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B8504;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27480
	ctx.r4.s64 = ctx.r8.s64 + -27480;
	// bl 0x821d4b00
	ctx.lr = 0x826B8514;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B852C;
	sub_821C0548(ctx, base);
loc_826B852C:
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

__attribute__((alias("__imp__sub_826B8544"))) PPC_WEAK_FUNC(sub_826B8544);
PPC_FUNC_IMPL(__imp__sub_826B8544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8548"))) PPC_WEAK_FUNC(sub_826B8548);
PPC_FUNC_IMPL(__imp__sub_826B8548) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27544
	r31.s64 = r11.s64 + -27544;
	// lwz r11,-27544(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8694
	if (!cr6.eq) goto loc_826B8694;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8578;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b858c
	if (cr6.eq) goto loc_826B858C;
	// bl 0x821d5408
	ctx.lr = 0x826B8588;
	sub_821D5408(ctx, base);
	// b 0x826b8590
	goto loc_826B8590;
loc_826B858C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8590:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17800
	ctx.r7.s64 = ctx.r10.s64 + -17800;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,164
	ctx.r5.s64 = 164;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,28104
	ctx.r4.s64 = ctx.r8.s64 + 28104;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-27472
	ctx.r7.s64 = ctx.r3.s64 + -27472;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r10,-27448
	ctx.r5.s64 = ctx.r10.s64 + -27448;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r9,-27424
	ctx.r3.s64 = ctx.r9.s64 + -27424;
	// li r10,60
	ctx.r10.s64 = 60;
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r9,92
	ctx.r9.s64 = 92;
	// li r8,156
	ctx.r8.s64 = 156;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// bne cr6,0x826b862c
	if (!cr6.eq) goto loc_826B862C;
	// bl 0x826b7f00
	ctx.lr = 0x826B8628;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B862C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8638;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8650;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B866C;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27400
	ctx.r4.s64 = ctx.r8.s64 + -27400;
	// bl 0x821d4b00
	ctx.lr = 0x826B867C;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8694;
	sub_821C0548(ctx, base);
loc_826B8694:
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

__attribute__((alias("__imp__sub_826B86AC"))) PPC_WEAK_FUNC(sub_826B86AC);
PPC_FUNC_IMPL(__imp__sub_826B86AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B86B0"))) PPC_WEAK_FUNC(sub_826B86B0);
PPC_FUNC_IMPL(__imp__sub_826B86B0) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27540
	r31.s64 = r11.s64 + -27540;
	// lwz r11,-27540(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27540);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b87dc
	if (!cr6.eq) goto loc_826B87DC;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B86E0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b86f4
	if (cr6.eq) goto loc_826B86F4;
	// bl 0x821d5408
	ctx.lr = 0x826B86F0;
	sub_821D5408(ctx, base);
	// b 0x826b86f8
	goto loc_826B86F8;
loc_826B86F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B86F8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17788
	ctx.r7.s64 = ctx.r10.s64 + -17788;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,28216
	ctx.r4.s64 = ctx.r8.s64 + 28216;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-27384
	ctx.r9.s64 = ctx.r3.s64 + -27384;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826b8774
	if (!cr6.eq) goto loc_826B8774;
	// bl 0x826b7f00
	ctx.lr = 0x826B8770;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B8774:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8780;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8798;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B87B4;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27360
	ctx.r4.s64 = ctx.r8.s64 + -27360;
	// bl 0x821d4b00
	ctx.lr = 0x826B87C4;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B87DC;
	sub_821C0548(ctx, base);
loc_826B87DC:
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

__attribute__((alias("__imp__sub_826B87F4"))) PPC_WEAK_FUNC(sub_826B87F4);
PPC_FUNC_IMPL(__imp__sub_826B87F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B87F8"))) PPC_WEAK_FUNC(sub_826B87F8);
PPC_FUNC_IMPL(__imp__sub_826B87F8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27536
	r31.s64 = r11.s64 + -27536;
	// lwz r11,-27536(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27536);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8924
	if (!cr6.eq) goto loc_826B8924;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8828;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b883c
	if (cr6.eq) goto loc_826B883C;
	// bl 0x821d5408
	ctx.lr = 0x826B8838;
	sub_821D5408(ctx, base);
	// b 0x826b8840
	goto loc_826B8840;
loc_826B883C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8840:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17772
	ctx.r7.s64 = ctx.r10.s64 + -17772;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,92
	ctx.r5.s64 = 92;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,28320
	ctx.r4.s64 = ctx.r8.s64 + 28320;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-27352
	ctx.r9.s64 = ctx.r3.s64 + -27352;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826b88bc
	if (!cr6.eq) goto loc_826B88BC;
	// bl 0x826b7f00
	ctx.lr = 0x826B88B8;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B88BC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B88C8;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B88E0;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B88FC;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27328
	ctx.r4.s64 = ctx.r8.s64 + -27328;
	// bl 0x821d4b00
	ctx.lr = 0x826B890C;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8924;
	sub_821C0548(ctx, base);
loc_826B8924:
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

__attribute__((alias("__imp__sub_826B893C"))) PPC_WEAK_FUNC(sub_826B893C);
PPC_FUNC_IMPL(__imp__sub_826B893C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8940"))) PPC_WEAK_FUNC(sub_826B8940);
PPC_FUNC_IMPL(__imp__sub_826B8940) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27532
	r31.s64 = r11.s64 + -27532;
	// lwz r11,-27532(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27532);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8a8c
	if (!cr6.eq) goto loc_826B8A8C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8970;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b8984
	if (cr6.eq) goto loc_826B8984;
	// bl 0x821d5408
	ctx.lr = 0x826B8980;
	sub_821D5408(ctx, base);
	// b 0x826b8988
	goto loc_826B8988;
loc_826B8984:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8988:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17752
	ctx.r7.s64 = ctx.r10.s64 + -17752;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,28432
	ctx.r4.s64 = ctx.r8.s64 + 28432;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-27320
	ctx.r7.s64 = ctx.r3.s64 + -27320;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r10,-27296
	ctx.r5.s64 = ctx.r10.s64 + -27296;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r9,-27272
	ctx.r3.s64 = ctx.r9.s64 + -27272;
	// li r10,60
	ctx.r10.s64 = 60;
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r9,92
	ctx.r9.s64 = 92;
	// li r8,124
	ctx.r8.s64 = 124;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// bne cr6,0x826b8a24
	if (!cr6.eq) goto loc_826B8A24;
	// bl 0x826b7f00
	ctx.lr = 0x826B8A20;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B8A24:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8A30;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8A48;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B8A64;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27248
	ctx.r4.s64 = ctx.r8.s64 + -27248;
	// bl 0x821d4b00
	ctx.lr = 0x826B8A74;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8A8C;
	sub_821C0548(ctx, base);
loc_826B8A8C:
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

__attribute__((alias("__imp__sub_826B8AA4"))) PPC_WEAK_FUNC(sub_826B8AA4);
PPC_FUNC_IMPL(__imp__sub_826B8AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8AA8"))) PPC_WEAK_FUNC(sub_826B8AA8);
PPC_FUNC_IMPL(__imp__sub_826B8AA8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27528
	r31.s64 = r11.s64 + -27528;
	// lwz r11,-27528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27528);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8bd4
	if (!cr6.eq) goto loc_826B8BD4;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8AD8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b8aec
	if (cr6.eq) goto loc_826B8AEC;
	// bl 0x821d5408
	ctx.lr = 0x826B8AE8;
	sub_821D5408(ctx, base);
	// b 0x826b8af0
	goto loc_826B8AF0;
loc_826B8AEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8AF0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17736
	ctx.r7.s64 = ctx.r10.s64 + -17736;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,28552
	ctx.r4.s64 = ctx.r8.s64 + 28552;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-27232
	ctx.r9.s64 = ctx.r3.s64 + -27232;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826b8b6c
	if (!cr6.eq) goto loc_826B8B6C;
	// bl 0x826b7f00
	ctx.lr = 0x826B8B68;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B8B6C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8B78;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8B90;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B8BAC;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27208
	ctx.r4.s64 = ctx.r8.s64 + -27208;
	// bl 0x821d4b00
	ctx.lr = 0x826B8BBC;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8BD4;
	sub_821C0548(ctx, base);
loc_826B8BD4:
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

__attribute__((alias("__imp__sub_826B8BEC"))) PPC_WEAK_FUNC(sub_826B8BEC);
PPC_FUNC_IMPL(__imp__sub_826B8BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8BF0"))) PPC_WEAK_FUNC(sub_826B8BF0);
PPC_FUNC_IMPL(__imp__sub_826B8BF0) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27524
	r31.s64 = r11.s64 + -27524;
	// lwz r11,-27524(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8d2c
	if (!cr6.eq) goto loc_826B8D2C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8C20;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b8c34
	if (cr6.eq) goto loc_826B8C34;
	// bl 0x821d5408
	ctx.lr = 0x826B8C30;
	sub_821D5408(ctx, base);
	// b 0x826b8c38
	goto loc_826B8C38;
loc_826B8C34:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8C38:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17720
	ctx.r7.s64 = ctx.r10.s64 + -17720;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,28664
	ctx.r4.s64 = ctx.r8.s64 + 28664;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r5,r10,-27176
	ctx.r5.s64 = ctx.r10.s64 + -27176;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r8,r3,-27200
	ctx.r8.s64 = ctx.r3.s64 + -27200;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,92
	ctx.r9.s64 = 92;
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// bne cr6,0x826b8cc4
	if (!cr6.eq) goto loc_826B8CC4;
	// bl 0x826b7f00
	ctx.lr = 0x826B8CC0;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B8CC4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8CD0;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8CE8;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B8D04;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27152
	ctx.r4.s64 = ctx.r8.s64 + -27152;
	// bl 0x821d4b00
	ctx.lr = 0x826B8D14;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8D2C;
	sub_821C0548(ctx, base);
loc_826B8D2C:
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

__attribute__((alias("__imp__sub_826B8D44"))) PPC_WEAK_FUNC(sub_826B8D44);
PPC_FUNC_IMPL(__imp__sub_826B8D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8D48"))) PPC_WEAK_FUNC(sub_826B8D48);
PPC_FUNC_IMPL(__imp__sub_826B8D48) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27520
	r31.s64 = r11.s64 + -27520;
	// lwz r11,-27520(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27520);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8e74
	if (!cr6.eq) goto loc_826B8E74;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8D78;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b8d8c
	if (cr6.eq) goto loc_826B8D8C;
	// bl 0x821d5408
	ctx.lr = 0x826B8D88;
	sub_821D5408(ctx, base);
	// b 0x826b8d90
	goto loc_826B8D90;
loc_826B8D8C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8D90:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17696
	ctx.r7.s64 = ctx.r10.s64 + -17696;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,92
	ctx.r5.s64 = 92;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,28776
	ctx.r4.s64 = ctx.r8.s64 + 28776;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-27140
	ctx.r9.s64 = ctx.r3.s64 + -27140;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826b8e0c
	if (!cr6.eq) goto loc_826B8E0C;
	// bl 0x826b7f00
	ctx.lr = 0x826B8E08;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B8E0C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8E18;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8E30;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B8E4C;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27116
	ctx.r4.s64 = ctx.r8.s64 + -27116;
	// bl 0x821d4b00
	ctx.lr = 0x826B8E5C;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8E74;
	sub_821C0548(ctx, base);
loc_826B8E74:
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

__attribute__((alias("__imp__sub_826B8E8C"))) PPC_WEAK_FUNC(sub_826B8E8C);
PPC_FUNC_IMPL(__imp__sub_826B8E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8E90"))) PPC_WEAK_FUNC(sub_826B8E90);
PPC_FUNC_IMPL(__imp__sub_826B8E90) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27516
	r31.s64 = r11.s64 + -27516;
	// lwz r11,-27516(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b8fcc
	if (!cr6.eq) goto loc_826B8FCC;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826B8EC0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b8ed4
	if (cr6.eq) goto loc_826B8ED4;
	// bl 0x821d5408
	ctx.lr = 0x826B8ED0;
	sub_821D5408(ctx, base);
	// b 0x826b8ed8
	goto loc_826B8ED8;
loc_826B8ED4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826B8ED8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17668
	ctx.r7.s64 = ctx.r10.s64 + -17668;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,156
	ctx.r5.s64 = 156;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32149
	ctx.r8.s64 = -2106916864;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,28880
	ctx.r4.s64 = ctx.r8.s64 + 28880;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r5,r10,-27084
	ctx.r5.s64 = ctx.r10.s64 + -27084;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r8,r3,-27108
	ctx.r8.s64 = ctx.r3.s64 + -27108;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,60
	ctx.r10.s64 = 60;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,92
	ctx.r9.s64 = 92;
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// bne cr6,0x826b8f64
	if (!cr6.eq) goto loc_826B8F64;
	// bl 0x826b7f00
	ctx.lr = 0x826B8F60;
	sub_826B7F00(ctx, base);
	// lwz r4,-27564(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826B8F64:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826B8F70;
	sub_821D4458(ctx, base);
	// lwz r11,-27564(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826B8F88;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x826B8FA4;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-27060
	ctx.r4.s64 = ctx.r8.s64 + -27060;
	// bl 0x821d4b00
	ctx.lr = 0x826B8FB4;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x826B8FCC;
	sub_821C0548(ctx, base);
loc_826B8FCC:
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

__attribute__((alias("__imp__sub_826B8FE4"))) PPC_WEAK_FUNC(sub_826B8FE4);
PPC_FUNC_IMPL(__imp__sub_826B8FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B8FE8"))) PPC_WEAK_FUNC(sub_826B8FE8);
PPC_FUNC_IMPL(__imp__sub_826B8FE8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-17104
	ctx.r10.s64 = r11.s64 + -17104;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826bc3b0
	ctx.lr = 0x826B9014;
	sub_826BC3B0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826b902c
	if (cr6.eq) goto loc_826B902C;
	// bl 0x82130588
	ctx.lr = 0x826B9028;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826B902C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B9044"))) PPC_WEAK_FUNC(sub_826B9044);
PPC_FUNC_IMPL(__imp__sub_826B9044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B9048"))) PPC_WEAK_FUNC(sub_826B9048);
PPC_FUNC_IMPL(__imp__sub_826B9048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x826b9064
	if (cr6.lt) goto loc_826B9064;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_826B9064:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r10,26214
	ctx.r10.s64 = 1717960704;
	// li r9,10
	ctx.r9.s64 = 10;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// li r11,3
	r11.s64 = 3;
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r11,-52(r1)
	PPC_STORE_U32(ctx.r1.u32 + -52, r11.u32);
	// lfs f12,11368(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11368);
	ctx.f12.f64 = double(temp.f32);
	// ori r8,r10,26215
	ctx.r8.u64 = ctx.r10.u64 | 26215;
	// stw r7,-48(r1)
	PPC_STORE_U32(ctx.r1.u32 + -48, ctx.r7.u32);
	// li r6,6
	ctx.r6.s64 = 6;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r6,-40(r1)
	PPC_STORE_U32(ctx.r1.u32 + -40, ctx.r6.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r5,-60(r1)
	PPC_STORE_U32(ctx.r1.u32 + -60, ctx.r5.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r4,-56(r1)
	PPC_STORE_U32(ctx.r1.u32 + -56, ctx.r4.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// stw r5,-36(r1)
	PPC_STORE_U32(ctx.r1.u32 + -36, ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r4,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, ctx.r4.u32);
	// li r31,5
	r31.s64 = 5;
	// fctiwz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f11.u64);
	// lwz r11,-76(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// mulhw r8,r7,r8
	ctx.r8.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32)) >> 32;
	// stw r10,-64(r1)
	PPC_STORE_U32(ctx.r1.u32 + -64, ctx.r10.u32);
	// stw r31,-44(r1)
	PPC_STORE_U32(ctx.r1.u32 + -44, r31.u32);
	// divw r6,r11,r9
	ctx.r6.s32 = r11.s32 / ctx.r9.s32;
	// srawi r11,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	r11.s64 = ctx.r8.s32 >> 2;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// std r5,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r5.u64);
	// lfd f10,-80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f13,f9
	ctx.f13.f64 = double(float(ctx.f9.f64));
	// li r30,9
	r30.s64 = 9;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// stw r30,-28(r1)
	PPC_STORE_U32(ctx.r1.u32 + -28, r30.u32);
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r9,r11,r7
	ctx.r9.s64 = ctx.r7.s64 - r11.s64;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r8.u64);
	// lfd f8,-80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f9,f7
	ctx.f9.f64 = double(float(ctx.f7.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826b9190
	if (!cr6.gt) goto loc_826B9190;
	// lfs f11,96(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r1,-64
	r11.s64 = ctx.r1.s64 + -64;
	// lfs f10,92(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f10.f64 = double(temp.f32);
loc_826B914C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// std r8,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r8.u64);
	// lfd f8,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// std r7,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r7.u64);
	// lfd f7,-72(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fcfid f4,f8
	ctx.f4.f64 = double(ctx.f8.s64);
	// fmadds f3,f5,f11,f10
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f11.f64 + ctx.f10.f64));
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// fmadds f0,f3,f12,f0
	f0.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f2,f13
	cr6.compare(ctx.f2.f64, ctx.f13.f64);
	// blt cr6,0x826b914c
	if (cr6.lt) goto loc_826B914C;
loc_826B9190:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f11,96(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r1,-64
	ctx.r10.s64 = ctx.r1.s64 + -64;
	// lfs f10,92(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lfs f13,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r7.u64);
	// lfd f8,-72(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmadds f5,f6,f11,f10
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fmadds f4,f5,f12,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + f0.f64));
	// fsubs f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 - f0.f64));
	// fmuls f2,f3,f13
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fmadds f1,f2,f9,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f9.f64 + f0.f64));
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B91E0"))) PPC_WEAK_FUNC(sub_826B91E0);
PPC_FUNC_IMPL(__imp__sub_826B91E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-17100
	ctx.r3.s64 = r11.s64 + -17100;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B91EC"))) PPC_WEAK_FUNC(sub_826B91EC);
PPC_FUNC_IMPL(__imp__sub_826B91EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B91F0"))) PPC_WEAK_FUNC(sub_826B91F0);
PPC_FUNC_IMPL(__imp__sub_826B91F0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-17068
	ctx.r5.s64 = r11.s64 + -17068;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,92
	ctx.r6.s64 = r31.s64 + 92;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x826B922C;
	sub_824DF200(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-17088
	ctx.r5.s64 = ctx.r10.s64 + -17088;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826B924C;
	sub_824DF200(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B9264"))) PPC_WEAK_FUNC(sub_826B9264);
PPC_FUNC_IMPL(__imp__sub_826B9264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B9268"))) PPC_WEAK_FUNC(sub_826B9268);
PPC_FUNC_IMPL(__imp__sub_826B9268) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r7,r11,-26412
	ctx.r7.s64 = r11.s64 + -26412;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
loc_826B9278:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_826B9280:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x826b92a4
	if (cr6.eq) goto loc_826B92A4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826b9280
	if (cr6.eq) goto loc_826B9280;
loc_826B92A4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r11,r7,8
	r11.s64 = ctx.r7.s64 + 8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// blt cr6,0x826b9278
	if (cr6.lt) goto loc_826B9278;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B92C8"))) PPC_WEAK_FUNC(sub_826B92C8);
PPC_FUNC_IMPL(__imp__sub_826B92C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r10,12
	ctx.r10.s64 = 12;
	// addi r11,r3,200
	r11.s64 = ctx.r3.s64 + 200;
	// lfs f0,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
loc_826B92D8:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// cmpw cr6,r4,r9
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r9.s32, xer);
	// bge cr6,0x826b9308
	if (!cr6.lt) goto loc_826B9308;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bne 0x826b92d8
	if (!cr0.eq) goto loc_826B92D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826B9308:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B9310"))) PPC_WEAK_FUNC(sub_826B9310);
PPC_FUNC_IMPL(__imp__sub_826B9310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// addi r11,r4,25
	r11.s64 = ctx.r4.s64 + 25;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r10,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B9320"))) PPC_WEAK_FUNC(sub_826B9320);
PPC_FUNC_IMPL(__imp__sub_826B9320) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826B9328;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x826b9364
	if (!cr6.eq) goto loc_826B9364;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r3,52(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826B9358;
	sub_8238EFE8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_826B9364:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// ble cr6,0x826b93b4
	if (!cr6.gt) goto loc_826B93B4;
	// addi r30,r29,8
	r30.s64 = r29.s64 + 8;
loc_826B937C:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826b939c
	if (cr6.eq) goto loc_826B939C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826B9394;
	sub_8238EFE8(ctx, base);
	// fadds f31,f1,f31
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64 + f31.f64));
	// b 0x826b93a0
	goto loc_826B93A0;
loc_826B939C:
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
loc_826B93A0:
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x826b937c
	if (cr6.lt) goto loc_826B937C;
loc_826B93B4:
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f1,f31,f12
	ctx.f1.f64 = double(float(f31.f64 / ctx.f12.f64));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B93E0"))) PPC_WEAK_FUNC(sub_826B93E0);
PPC_FUNC_IMPL(__imp__sub_826B93E0) {
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
	ctx.lr = 0x826B93E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,32653
	r11.s64 = 2139947008;
	// ori r11,r11,52992
	r11.u64 = r11.u64 | 52992;
	// lwz r10,508(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 508);
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x826b9414
	if (!cr6.gt) goto loc_826B9414;
	// stw r11,508(r31)
	PPC_STORE_U32(r31.u32 + 508, r11.u32);
	// b 0x826b9418
	goto loc_826B9418;
loc_826B9414:
	// stw r10,508(r31)
	PPC_STORE_U32(r31.u32 + 508, ctx.r10.u32);
loc_826B9418:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r6,508(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 508);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r11,-17044
	ctx.r3.s64 = r11.s64 + -17044;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x826B9430;
	sub_822CDB08(ctx, base);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18216
	ctx.r4.s64 = ctx.r10.s64 + -18216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r30,-12440(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// lwz r28,0(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x826B9454;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,40(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826B9468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,15
	ctx.r8.s64 = 983040;
	// lwz r6,508(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 508);
	// ori r7,r8,16960
	ctx.r7.u64 = ctx.r8.u64 | 16960;
	// cmpw cr6,r6,r7
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, xer);
	// blt cr6,0x826b94a0
	if (cr6.lt) goto loc_826B94A0;
	// lwz r3,-12440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-17052
	ctx.r4.s64 = r11.s64 + -17052;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826B94A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826B94A0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B94A8"))) PPC_WEAK_FUNC(sub_826B94A8);
PPC_FUNC_IMPL(__imp__sub_826B94A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,508(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 508);
	// lis r9,-32654
	ctx.r9.s64 = -2140012544;
	// ori r11,r9,12544
	r11.u64 = ctx.r9.u64 | 12544;
	// subf r10,r4,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r4.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x826b94c8
	if (!cr6.lt) goto loc_826B94C8;
	// stw r11,508(r3)
	PPC_STORE_U32(ctx.r3.u32 + 508, r11.u32);
	// b 0x826b94cc
	goto loc_826B94CC;
loc_826B94C8:
	// stw r10,508(r3)
	PPC_STORE_U32(ctx.r3.u32 + 508, ctx.r10.u32);
loc_826B94CC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r6,508(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 508);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r11,-17044
	ctx.r3.s64 = r11.s64 + -17044;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x822cdb08
	sub_822CDB08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B94E4"))) PPC_WEAK_FUNC(sub_826B94E4);
PPC_FUNC_IMPL(__imp__sub_826B94E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B94E8"))) PPC_WEAK_FUNC(sub_826B94E8);
PPC_FUNC_IMPL(__imp__sub_826B94E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,508(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 508);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x826b94fc
	if (!cr6.lt) goto loc_826B94FC;
	// li r11,0
	r11.s64 = 0;
loc_826B94FC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B9504"))) PPC_WEAK_FUNC(sub_826B9504);
PPC_FUNC_IMPL(__imp__sub_826B9504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B9508"))) PPC_WEAK_FUNC(sub_826B9508);
PPC_FUNC_IMPL(__imp__sub_826B9508) {
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
	ctx.lr = 0x826B9510;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mulli r3,r30,28
	ctx.r3.s64 = r30.s64 * 28;
	// bl 0x82130528
	ctx.lr = 0x826B9520;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826b954c
	if (!cr6.gt) goto loc_826B954C;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_826B9530:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826b9540
	if (cr6.eq) goto loc_826B9540;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826bbe70
	ctx.lr = 0x826B9540;
	sub_826BBE70(ctx, base);
loc_826B9540:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// bne 0x826b9530
	if (!cr0.eq) goto loc_826B9530;
loc_826B954C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826B9558"))) PPC_WEAK_FUNC(sub_826B9558);
PPC_FUNC_IMPL(__imp__sub_826B9558) {
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
	ctx.lr = 0x826B9560;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826b959c
	if (!cr6.gt) goto loc_826B959C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_826B9578:
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
	ctx.lr = 0x826B9590;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// bne 0x826b9578
	if (!cr0.eq) goto loc_826B9578;
loc_826B959C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826B95A4;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826B95AC"))) PPC_WEAK_FUNC(sub_826B95AC);
PPC_FUNC_IMPL(__imp__sub_826B95AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B95B0"))) PPC_WEAK_FUNC(sub_826B95B0);
PPC_FUNC_IMPL(__imp__sub_826B95B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mulli r11,r4,28
	r11.s64 = ctx.r4.s64 * 28;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B95C0"))) PPC_WEAK_FUNC(sub_826B95C0);
PPC_FUNC_IMPL(__imp__sub_826B95C0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
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
	// stfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f29.u64);
	// stfd f30,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x826bbcf0
	ctx.lr = 0x826B95F0;
	sub_826BBCF0(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x826b9610
	if (cr6.lt) goto loc_826B9610;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f1,-28012(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28012);
	ctx.f1.f64 = double(temp.f32);
	// b 0x826b9614
	goto loc_826B9614;
loc_826B9610:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_826B9614:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b9048
	ctx.lr = 0x826B961C;
	sub_826B9048(ctx, base);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x826b9630
	if (cr6.lt) goto loc_826B9630;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// b 0x826b963c
	goto loc_826B963C;
loc_826B9630:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f0,-17036(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17036);
	f0.f64 = double(temp.f32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 + f0.f64));
loc_826B963C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b9048
	ctx.lr = 0x826B9644;
	sub_826B9048(ctx, base);
	// fsubs f12,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64 - f29.f64));
	// addi r11,r30,123
	r11.s64 = r30.s64 + 123;
	// lfs f11,96(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,-26928(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -26928);
	f0.f64 = double(temp.f32);
	// lfsx f10,r9,r31
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f10,f11,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f12.f64));
	// lfs f12,14988(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f5,80(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fmuls f1,f3,f12
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-48(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f30,-40(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B96C4"))) PPC_WEAK_FUNC(sub_826B96C4);
PPC_FUNC_IMPL(__imp__sub_826B96C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B96C8"))) PPC_WEAK_FUNC(sub_826B96C8);
PPC_FUNC_IMPL(__imp__sub_826B96C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f8
	ctx.lr = 0x826B96D0;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82387a98
	ctx.lr = 0x826B96F0;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b9714
	if (cr6.eq) goto loc_826B9714;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_826B9714:
	// addi r11,r29,134
	r11.s64 = r29.s64 + 134;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r10,r28,130
	ctx.r10.s64 = r28.s64 + 130;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r9,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	f31.f64 = double(temp.f32);
	// lfsx f30,r8,r31
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	f30.f64 = double(temp.f32);
	// bl 0x826bbcf0
	ctx.lr = 0x826B9734;
	sub_826BBCF0(ctx, base);
	// lfs f0,516(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 516);
	f0.f64 = double(temp.f32);
	// twllei r30,0
	// lfs f13,512(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 512);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f1,f0,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmuls f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 * f30.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// divw r6,r7,r30
	ctx.r6.s32 = ctx.r7.s32 / r30.s32;
	// mullw r5,r6,r30
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(r30.s32);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// rotlwi r11,r7,1
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// andc r11,r30,r3
	r11.u64 = r30.u64 & ~ctx.r3.u64;
	// frsp f1,f7
	ctx.f1.f64 = double(float(ctx.f7.f64));
	// twlgei r11,-1
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826B9794"))) PPC_WEAK_FUNC(sub_826B9794);
PPC_FUNC_IMPL(__imp__sub_826B9794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B9798"))) PPC_WEAK_FUNC(sub_826B9798);
PPC_FUNC_IMPL(__imp__sub_826B9798) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// sth r9,6(r11)
	PPC_STORE_U16(r11.u32 + 6, ctx.r9.u16);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// beq cr6,0x826b97c4
	if (cr6.eq) goto loc_826B97C4;
	// b 0x826bc650
	sub_826BC650(ctx, base);
	return;
loc_826B97C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B97CC"))) PPC_WEAK_FUNC(sub_826B97CC);
PPC_FUNC_IMPL(__imp__sub_826B97CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B97D0"))) PPC_WEAK_FUNC(sub_826B97D0);
PPC_FUNC_IMPL(__imp__sub_826B97D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
	// sth r9,6(r11)
	PPC_STORE_U16(r11.u32 + 6, ctx.r9.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B97F8"))) PPC_WEAK_FUNC(sub_826B97F8);
PPC_FUNC_IMPL(__imp__sub_826B97F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,18508(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mulli r10,r8,28
	ctx.r10.s64 = ctx.r8.s64 * 28;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B9820"))) PPC_WEAK_FUNC(sub_826B9820);
PPC_FUNC_IMPL(__imp__sub_826B9820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,18508(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r9,508(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B9838"))) PPC_WEAK_FUNC(sub_826B9838);
PPC_FUNC_IMPL(__imp__sub_826B9838) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x826b96c8
	ctx.lr = 0x826B9868;
	sub_826B96C8(ctx, base);
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

__attribute__((alias("__imp__sub_826B9884"))) PPC_WEAK_FUNC(sub_826B9884);
PPC_FUNC_IMPL(__imp__sub_826B9884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B9888"))) PPC_WEAK_FUNC(sub_826B9888);
PPC_FUNC_IMPL(__imp__sub_826B9888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x826b93e0
	sub_826B93E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B989C"))) PPC_WEAK_FUNC(sub_826B989C);
PPC_FUNC_IMPL(__imp__sub_826B989C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B98A0"))) PPC_WEAK_FUNC(sub_826B98A0);
PPC_FUNC_IMPL(__imp__sub_826B98A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r8,-32654
	ctx.r8.s64 = -2140012544;
	// ori r10,r8,12544
	ctx.r10.u64 = ctx.r8.u64 | 12544;
	// lwz r11,18508(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r6,508(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// subf r9,r7,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r7.s64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bge cr6,0x826b98d0
	if (!cr6.lt) goto loc_826B98D0;
	// stw r10,508(r11)
	PPC_STORE_U32(r11.u32 + 508, ctx.r10.u32);
	// b 0x826b98d4
	goto loc_826B98D4;
loc_826B98D0:
	// stw r9,508(r11)
	PPC_STORE_U32(r11.u32 + 508, ctx.r9.u32);
loc_826B98D4:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r6,508(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r10,-17044
	ctx.r3.s64 = ctx.r10.s64 + -17044;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x822cdb08
	sub_822CDB08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826B98EC"))) PPC_WEAK_FUNC(sub_826B98EC);
PPC_FUNC_IMPL(__imp__sub_826B98EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B98F0"))) PPC_WEAK_FUNC(sub_826B98F0);
PPC_FUNC_IMPL(__imp__sub_826B98F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,18508(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,508(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bge cr6,0x826b9914
	if (!cr6.lt) goto loc_826B9914;
	// li r11,0
	r11.s64 = 0;
loc_826B9914:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826B9924"))) PPC_WEAK_FUNC(sub_826B9924);
PPC_FUNC_IMPL(__imp__sub_826B9924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B9928"))) PPC_WEAK_FUNC(sub_826B9928);
PPC_FUNC_IMPL(__imp__sub_826B9928) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826B9948;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x826bddb0
	ctx.lr = 0x826B9958;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b9978
	if (cr6.eq) goto loc_826B9978;
loc_826B9960:
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
loc_826B9978:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// bl 0x826bddb0
	ctx.lr = 0x826B9984;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826b9960
	if (!cr6.eq) goto loc_826B9960;
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

__attribute__((alias("__imp__sub_826B99A0"))) PPC_WEAK_FUNC(sub_826B99A0);
PPC_FUNC_IMPL(__imp__sub_826B99A0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x826B99A8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r29,3100(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 3100);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826B99C8;
	sub_8238EFE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x826b95c0
	ctx.lr = 0x826B99D4;
	sub_826B95C0(ctx, base);
	// lwz r10,3080(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 3080);
	// lwz r9,172(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// lfs f0,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lfs f13,17032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14988(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f11,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 / ctx.f10.f64));
	// fmuls f5,f6,f1
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmuls f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f1,80(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// fmuls f31,f13,f12
	f31.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f31,f11
	cr6.compare(f31.f64, ctx.f11.f64);
	// ble cr6,0x826b9adc
	if (!cr6.gt) goto loc_826B9ADC;
	// bl 0x82387a18
	ctx.lr = 0x826B9A6C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b9adc
	if (!cr6.eq) goto loc_826B9ADC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r31,296
	ctx.r3.s64 = r31.s64 + 296;
	// lwz r4,-26412(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -26412);
	// bl 0x823db670
	ctx.lr = 0x826B9A8C;
	sub_823DB670(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// addi r30,r31,236
	r30.s64 = r31.s64 + 236;
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b6580
	ctx.lr = 0x826B9AA8;
	sub_826B6580(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stb r10,245(r31)
	PPC_STORE_U8(r31.u32 + 245, ctx.r10.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,18504(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826B9AC0;
	sub_826B5CF0(ctx, base);
	// li r3,54
	ctx.r3.s64 = 54;
	// bl 0x82204a48
	ctx.lr = 0x826B9AC8;
	sub_82204A48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b9adc
	if (cr6.eq) goto loc_826B9ADC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822048b0
	ctx.lr = 0x826B9ADC;
	sub_822048B0(ctx, base);
loc_826B9ADC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826B9AE8"))) PPC_WEAK_FUNC(sub_826B9AE8);
PPC_FUNC_IMPL(__imp__sub_826B9AE8) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826B9AF0;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d8
	ctx.lr = 0x826B9AF8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,3140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826b9de4
	if (!cr6.eq) goto loc_826B9DE4;
	// li r11,-1
	r11.s64 = -1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x826b9320
	ctx.lr = 0x826B9B20;
	sub_826B9320(ctx, base);
	// lwz r26,3100(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 3100);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x826b95c0
	ctx.lr = 0x826B9B30;
	sub_826B95C0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r27,r11,r30
	r27.u64 = r11.u64 + r30.u64;
	// lwz r9,8(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r3,52(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// bl 0x8238f6b0
	ctx.lr = 0x826B9B54;
	sub_8238F6B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x826b96c8
	ctx.lr = 0x826B9B68;
	sub_826B96C8(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r7,3132(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 3132);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f28,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f28.f64 = double(temp.f32);
	// fmr f31,f28
	f31.f64 = f28.f64;
	// beq cr6,0x826b9b90
	if (cr6.eq) goto loc_826B9B90;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f31,-6176(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6176);
	f31.f64 = double(temp.f32);
	// b 0x826b9ba8
	goto loc_826B9BA8;
loc_826B9B90:
	// bl 0x82387a18
	ctx.lr = 0x826B9B94;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826b9ba8
	if (cr6.eq) goto loc_826B9BA8;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f31,-11316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11316);
	f31.f64 = double(temp.f32);
loc_826B9BA8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,3096(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 3096);
	// fmuls f0,f31,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 * f29.f64));
	// fmuls f13,f31,f30
	ctx.f13.f64 = double(float(f31.f64 * f30.f64));
	// cmpwi cr6,r10,10
	cr6.compare<int32_t>(ctx.r10.s32, 10, xer);
	// lfs f11,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// bne cr6,0x826b9bc8
	if (!cr6.eq) goto loc_826B9BC8;
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
loc_826B9BC8:
	// lwz r11,3080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3080);
	// lwz r10,172(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 172);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fdivs f5,f6,f9
	ctx.f5.f64 = double(float(ctx.f6.f64 / ctx.f9.f64));
	// fmuls f13,f5,f13
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fmuls f12,f5,f0
	ctx.f12.f64 = double(float(ctx.f5.f64 * f0.f64));
	// ble cr6,0x826b9c18
	if (!cr6.gt) goto loc_826B9C18;
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
loc_826B9C18:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lfs f0,17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f10,f12
	ctx.f10.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f10.u64);
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f9,f11
	ctx.f9.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// lfd f8,88(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f6,88(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// fmuls f0,f4,f13
	f0.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fmuls f31,f3,f13
	f31.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x826b9ca8
	if (!cr6.gt) goto loc_826B9CA8;
	// addi r30,r31,428
	r30.s64 = r31.s64 + 428;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b6870
	ctx.lr = 0x826B9C9C;
	sub_826B6870(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,18504(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826B9CA8;
	sub_826B5CF0(ctx, base);
loc_826B9CA8:
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f28.f64);
	// ble cr6,0x826b9d40
	if (!cr6.gt) goto loc_826B9D40;
	// bl 0x82387a18
	ctx.lr = 0x826B9CB4;
	sub_82387A18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r28,r11,-26412
	r28.s64 = r11.s64 + -26412;
	// bne cr6,0x826b9d04
	if (!cr6.eq) goto loc_826B9D04;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r3,r31,296
	ctx.r3.s64 = r31.s64 + 296;
	// bl 0x823db670
	ctx.lr = 0x826B9CD8;
	sub_823DB670(ctx, base);
	// addi r30,r31,236
	r30.s64 = r31.s64 + 236;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x826b6580
	ctx.lr = 0x826B9CF0;
	sub_826B6580(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,245(r31)
	PPC_STORE_U8(r31.u32 + 245, r11.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,18504(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826B9D04;
	sub_826B5CF0(ctx, base);
loc_826B9D04:
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r3,r31,392
	ctx.r3.s64 = r31.s64 + 392;
	// bl 0x823db670
	ctx.lr = 0x826B9D14;
	sub_823DB670(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// addi r30,r31,332
	r30.s64 = r31.s64 + 332;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x826b6580
	ctx.lr = 0x826B9D2C;
	sub_826B6580(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r11,340(r31)
	PPC_STORE_U8(r31.u32 + 340, r11.u8);
	// lwz r3,18504(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826B9D40;
	sub_826B5CF0(ctx, base);
loc_826B9D40:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r30,52(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238f998
	ctx.lr = 0x826B9D50;
	sub_8238F998(ctx, base);
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// bl 0x82396058
	ctx.lr = 0x826B9D58;
	sub_82396058(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b9928
	ctx.lr = 0x826B9D64;
	sub_826B9928(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b9d78
	if (cr6.eq) goto loc_826B9D78;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826bc348
	ctx.lr = 0x826B9D78;
	sub_826BC348(ctx, base);
loc_826B9D78:
	// lbz r11,8108(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8108);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x826b9db4
	if (cr6.eq) goto loc_826B9DB4;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-28116
	ctx.r8.s64 = ctx.r10.s64 + -28116;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// bl 0x826b9928
	ctx.lr = 0x826B9DA0;
	sub_826B9928(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826b9db4
	if (cr6.eq) goto loc_826B9DB4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826bc348
	ctx.lr = 0x826B9DB4;
	sub_826BC348(ctx, base);
loc_826B9DB4:
	// bl 0x82387a18
	ctx.lr = 0x826B9DB8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826b9de4
	if (!cr6.eq) goto loc_826B9DE4;
	// lwz r11,172(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 172);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r3,-21492(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21492);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x82742f28
	ctx.lr = 0x826B9DE4;
	sub_82742F28(ctx, base);
loc_826B9DE4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x826B9DF0;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826B9DF4"))) PPC_WEAK_FUNC(sub_826B9DF4);
PPC_FUNC_IMPL(__imp__sub_826B9DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826B9DF8"))) PPC_WEAK_FUNC(sub_826B9DF8);
PPC_FUNC_IMPL(__imp__sub_826B9DF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387b90
	ctx.lr = 0x826B9E1C;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// lwz r30,3100(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 3100);
	// mulli r11,r11,8176
	r11.s64 = r11.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238f6b0
	ctx.lr = 0x826B9E34;
	sub_8238F6B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x826b96c8
	ctx.lr = 0x826B9E48;
	sub_826B96C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826B9E5C;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// bne cr6,0x826b9e74
	if (!cr6.eq) goto loc_826B9E74;
	// li r10,0
	ctx.r10.s64 = 0;
loc_826B9E74:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,4120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826b9e90
	if (!cr6.gt) goto loc_826B9E90;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// b 0x826b9e94
	goto loc_826B9E94;
loc_826B9E90:
	// fmr f11,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f13.f64;
loc_826B9E94:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// bne cr6,0x826b9ea4
	if (!cr6.eq) goto loc_826B9EA4;
	// li r10,0
	ctx.r10.s64 = 0;
loc_826B9EA4:
	// lfs f13,4116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826b9eb8
	if (!cr6.gt) goto loc_826B9EB8;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// b 0x826b9ebc
	goto loc_826B9EBC;
loc_826B9EB8:
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
loc_826B9EBC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x826b9ecc
	if (!cr6.eq) goto loc_826B9ECC;
	// li r11,0
	r11.s64 = 0;
loc_826B9ECC:
	// lfs f13,4112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826b9edc
	if (!cr6.gt) goto loc_826B9EDC;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_826B9EDC:
	// fcmpu cr6,f31,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x826b9f24
	if (!cr6.gt) goto loc_826B9F24;
	// fadds f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r31,428
	r31.s64 = r31.s64 + 428;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,32688(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32688);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f11
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fnmsubs f10,f11,f13,f0
	ctx.f10.f64 = double(float(-(ctx.f11.f64 * ctx.f13.f64 - f0.f64)));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x826b6870
	ctx.lr = 0x826B9F14;
	sub_826B6870(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,18504(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826B9F24;
	sub_826B5CF0(ctx, base);
loc_826B9F24:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_826B9F40"))) PPC_WEAK_FUNC(sub_826B9F40);
PPC_FUNC_IMPL(__imp__sub_826B9F40) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x826B9F48;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d8
	ctx.lr = 0x826B9F50;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-29360
	ctx.r3.s64 = r11.s64 + -29360;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x821fa230
	ctx.lr = 0x826B9F68;
	sub_821FA230(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r28,r11,-20892
	r28.s64 = r11.s64 + -20892;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8268e5b8
	ctx.lr = 0x826B9F7C;
	sub_8268E5B8(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r3,-1
	r30.s64 = ctx.r3.s64 + -1;
	// addi r4,r10,-17032
	ctx.r4.s64 = ctx.r10.s64 + -17032;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268e5b8
	ctx.lr = 0x826B9F90;
	sub_8268E5B8(ctx, base);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// bne cr6,0x826ba188
	if (!cr6.eq) goto loc_826BA188;
	// lwz r11,200(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 200);
	// lwz r30,3100(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826B9FA8;
	sub_8238EFE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x826b95c0
	ctx.lr = 0x826B9FB4;
	sub_826B95C0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8268e5b8
	ctx.lr = 0x826B9FC4;
	sub_8268E5B8(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lfs f13,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lfs f30,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f31,f6,f13
	f31.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x826ba0a4
	if (!cr6.gt) goto loc_826BA0A4;
	// lis r25,-32125
	r25.s64 = -2105344000;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r11,r25,-26412
	r11.s64 = r25.s64 + -26412;
	// addi r3,r31,392
	ctx.r3.s64 = r31.s64 + 392;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823db670
	ctx.lr = 0x826BA040;
	sub_823DB670(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// addi r30,r31,332
	r30.s64 = r31.s64 + 332;
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r24,84(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b6580
	ctx.lr = 0x826BA05C;
	sub_826B6580(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r10,340(r31)
	PPC_STORE_U8(r31.u32 + 340, ctx.r10.u8);
	// lwz r3,18504(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826BA070;
	sub_826B5CF0(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r31,296
	ctx.r3.s64 = r31.s64 + 296;
	// lwz r4,-26412(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + -26412);
	// bl 0x823db670
	ctx.lr = 0x826BA080;
	sub_823DB670(ctx, base);
	// addi r30,r31,236
	r30.s64 = r31.s64 + 236;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b6580
	ctx.lr = 0x826BA090;
	sub_826B6580(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r9,245(r31)
	PPC_STORE_U8(r31.u32 + 245, ctx.r9.u8);
	// lwz r3,18504(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826BA0A4;
	sub_826B5CF0(ctx, base);
loc_826BA0A4:
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,3100(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x826b96c8
	ctx.lr = 0x826BA0BC;
	sub_826B96C8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmr f31,f30
	f31.f64 = f30.f64;
	// bl 0x8268e5b8
	ctx.lr = 0x826BA0D8;
	sub_8268E5B8(ctx, base);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f30
	cr6.compare(ctx.f11.f64, f30.f64);
	// blt cr6,0x826ba15c
	if (cr6.lt) goto loc_826BA15C;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f28,f0
	f28.f64 = double(f0.s64);
	// lfd f29,32(r11)
	f29.u64 = PPC_LOAD_U64(r11.u32 + 32);
loc_826BA10C:
	// fadds f31,f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f31.f64 + f30.f64));
	// extsw r11,r30
	r11.s64 = r30.s32;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmul f12,f31,f29
	ctx.f12.f64 = f31.f64 * f29.f64;
	// fmadd f11,f12,f28,f13
	ctx.f11.f64 = ctx.f12.f64 * f28.f64 + ctx.f13.f64;
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f10.u64);
	// lwz r30,92(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x8268e5b8
	ctx.lr = 0x826BA140;
	sub_8268E5B8(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f9,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fcmpu cr6,f31,f7
	cr6.compare(f31.f64, ctx.f7.f64);
	// ble cr6,0x826ba10c
	if (!cr6.gt) goto loc_826BA10C;
loc_826BA15C:
	// addi r31,r31,428
	r31.s64 = r31.s64 + 428;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b6870
	ctx.lr = 0x826BA16C;
	sub_826B6870(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,18504(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826BA178;
	sub_826B5CF0(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-30240
	ctx.r3.s64 = r11.s64 + -30240;
	// bl 0x82218838
	ctx.lr = 0x826BA188;
	sub_82218838(ctx, base);
loc_826BA188:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba24
	ctx.lr = 0x826BA194;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826BA198"))) PPC_WEAK_FUNC(sub_826BA198);
PPC_FUNC_IMPL(__imp__sub_826BA198) {
	PPC_FUNC_PROLOGUE();
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387b90
	ctx.lr = 0x826BA1B8;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// lwz r30,3100(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 3100);
	// mulli r11,r11,8176
	r11.s64 = r11.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238f6b0
	ctx.lr = 0x826BA1D0;
	sub_8238F6B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x826b96c8
	ctx.lr = 0x826BA1E4;
	sub_826B96C8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x826ba21c
	if (!cr6.gt) goto loc_826BA21C;
	// addi r31,r31,428
	r31.s64 = r31.s64 + 428;
	// fctiwz f0,f1
	f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b6870
	ctx.lr = 0x826BA20C;
	sub_826B6870(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,18504(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826BA21C;
	sub_826B5CF0(ctx, base);
loc_826BA21C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BA234"))) PPC_WEAK_FUNC(sub_826BA234);
PPC_FUNC_IMPL(__imp__sub_826BA234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BA238"))) PPC_WEAK_FUNC(sub_826BA238);
PPC_FUNC_IMPL(__imp__sub_826BA238) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826BA240;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,18504(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 18504);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ba474
	if (cr6.eq) goto loc_826BA474;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ba474
	if (cr6.eq) goto loc_826BA474;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826ba290
	if (cr6.eq) goto loc_826BA290;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x826ba294
	goto loc_826BA294;
loc_826BA290:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_826BA294:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x826ba474
	if (cr6.lt) goto loc_826BA474;
	// bl 0x822a39c0
	ctx.lr = 0x826BA2A0;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ba474
	if (cr6.eq) goto loc_826BA474;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x826BA2B4;
	sub_822A39C8(ctx, base);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826BA2BC;
	sub_8238EFE8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x826b95c0
	ctx.lr = 0x826BA2C8;
	sub_826B95C0(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lfs f13,4400(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4400);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f30,f1,f0
	f30.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmuls f1,f31,f13
	ctx.f1.f64 = double(float(f31.f64 * ctx.f13.f64));
	// bl 0x823dbaa8
	ctx.lr = 0x826BA2E4;
	sub_823DBAA8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,27640(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f0,f11,f0,f12
	f0.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// bge cr6,0x826ba324
	if (!cr6.lt) goto loc_826BA324;
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x826ba334
	goto loc_826BA334;
loc_826BA324:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_826BA334:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,14988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f31,f6,f13
	f31.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// bl 0x826b6508
	ctx.lr = 0x826BA38C;
	sub_826B6508(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r1,156
	ctx.r3.s64 = ctx.r1.s64 + 156;
	// lwz r4,-26412(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + -26412);
	// bl 0x823db670
	ctx.lr = 0x826BA3A0;
	sub_823DB670(ctx, base);
	// fctiwz f5,f31
	ctx.fpscr.disableFlushMode();
	ctx.f5.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x826b6580
	ctx.lr = 0x826BA3B8;
	sub_826B6580(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,18504(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 18504);
	// stb r5,105(r1)
	PPC_STORE_U8(ctx.r1.u32 + 105, ctx.r5.u8);
	// bl 0x826b5cf0
	ctx.lr = 0x826BA3CC;
	sub_826B5CF0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ba43c
	if (cr6.eq) goto loc_826BA43C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826BA3F4;
	sub_82137A08(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-16996
	ctx.r4.s64 = ctx.r9.s64 + -16996;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826BA40C;
	sub_822183B0(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r6,r7,-17012
	ctx.r6.s64 = ctx.r7.s64 + -17012;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f1,3732(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82234a10
	ctx.lr = 0x826BA43C;
	sub_82234A10(ctx, base);
loc_826BA43C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-14960
	ctx.r4.s64 = ctx.r10.s64 + -14960;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826BA460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r6,r7,3888
	ctx.r6.s64 = ctx.r7.s64 + 3888;
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// bl 0x821d2028
	ctx.lr = 0x826BA474;
	sub_821D2028(ctx, base);
loc_826BA474:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826BA484"))) PPC_WEAK_FUNC(sub_826BA484);
PPC_FUNC_IMPL(__imp__sub_826BA484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BA488"))) PPC_WEAK_FUNC(sub_826BA488);
PPC_FUNC_IMPL(__imp__sub_826BA488) {
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
	// li r11,0
	r11.s64 = 0;
	// li r9,64
	ctx.r9.s64 = 64;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// beq cr6,0x826ba4d4
	if (cr6.eq) goto loc_826BA4D4;
	// rlwinm r3,r10,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// bl 0x82130528
	ctx.lr = 0x826BA4D0;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826BA4D4:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x826BA4E4;
	sub_821F10E0(ctx, base);
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

__attribute__((alias("__imp__sub_826BA4FC"))) PPC_WEAK_FUNC(sub_826BA4FC);
PPC_FUNC_IMPL(__imp__sub_826BA4FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BA500"))) PPC_WEAK_FUNC(sub_826BA500);
PPC_FUNC_IMPL(__imp__sub_826BA500) {
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
	// li r11,0
	r11.s64 = 0;
	// li r9,88
	ctx.r9.s64 = 88;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// beq cr6,0x826ba54c
	if (cr6.eq) goto loc_826BA54C;
	// mulli r3,r10,88
	ctx.r3.s64 = ctx.r10.s64 * 88;
	// bl 0x82130528
	ctx.lr = 0x826BA548;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826BA54C:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x826BA55C;
	sub_821F10E0(ctx, base);
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

__attribute__((alias("__imp__sub_826BA574"))) PPC_WEAK_FUNC(sub_826BA574);
PPC_FUNC_IMPL(__imp__sub_826BA574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BA578"))) PPC_WEAK_FUNC(sub_826BA578);
PPC_FUNC_IMPL(__imp__sub_826BA578) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826BA580;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x826BA598;
	sub_824E0648(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r9,r10,-21868
	ctx.r9.s64 = ctx.r10.s64 + -21868;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r8,-28552
	ctx.r4.s64 = ctx.r8.s64 + -28552;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x826BA5BC;
	sub_823DB670(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r5,r7,-16956
	ctx.r5.s64 = ctx.r7.s64 + -16956;
	// addi r4,r6,-16968
	ctx.r4.s64 = ctx.r6.s64 + -16968;
	// li r30,0
	r30.s64 = 0;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stw r4,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r4.u32);
	// addi r3,r31,236
	ctx.r3.s64 = r31.s64 + 236;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// sth r30,52(r31)
	PPC_STORE_U16(r31.u32 + 52, r30.u16);
	// sth r30,54(r31)
	PPC_STORE_U16(r31.u32 + 54, r30.u16);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// sth r30,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r30.u16);
	// sth r30,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r30.u16);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stb r30,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r30.u8);
	// sth r30,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r30.u16);
	// sth r30,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r30.u16);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stb r30,83(r31)
	PPC_STORE_U8(r31.u32 + 83, r30.u8);
	// stb r30,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r30.u8);
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
	// stw r30,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r30.u32);
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// stw r30,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r30.u32);
	// stw r30,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r30.u32);
	// stw r30,228(r31)
	PPC_STORE_U32(r31.u32 + 228, r30.u32);
	// stw r30,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r30.u32);
	// bl 0x826b6508
	ctx.lr = 0x826BA638;
	sub_826B6508(ctx, base);
	// addi r3,r31,332
	ctx.r3.s64 = r31.s64 + 332;
	// bl 0x826b6508
	ctx.lr = 0x826BA640;
	sub_826B6508(ctx, base);
	// addi r3,r31,428
	ctx.r3.s64 = r31.s64 + 428;
	// bl 0x826b6830
	ctx.lr = 0x826BA648;
	sub_826B6830(ctx, base);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r26,5000
	r26.s64 = 5000;
	// addi r27,r31,508
	r27.s64 = r31.s64 + 508;
	// stw r26,508(r31)
	PPC_STORE_U32(r31.u32 + 508, r26.u32);
	// li r28,2
	r28.s64 = 2;
	// lfs f0,-12072(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -12072);
	f0.f64 = double(temp.f32);
	// lfs f13,-2376(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2376);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,512(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 512, temp.u32);
	// stfs f13,516(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 516, temp.u32);
	// lhz r10,54(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 54);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826ba690
	if (!cr6.eq) goto loc_826BA690;
	// sth r28,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r28.u16);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826b9508
	ctx.lr = 0x826BA68C;
	sub_826B9508(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_826BA690:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826BA69C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ba6b0
	if (cr6.eq) goto loc_826BA6B0;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x826ba488
	ctx.lr = 0x826BA6AC;
	sub_826BA488(ctx, base);
	// b 0x826ba6b4
	goto loc_826BA6B4;
loc_826BA6B0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826BA6B4:
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826BA6C0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ba6d4
	if (cr6.eq) goto loc_826BA6D4;
	// li r4,300
	ctx.r4.s64 = 300;
	// bl 0x826ba500
	ctx.lr = 0x826BA6D0;
	sub_826BA500(ctx, base);
	// b 0x826ba6d8
	goto loc_826BA6D8;
loc_826BA6D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826BA6D8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lfs f12,32668(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32668);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f11,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lfs f31,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f10,30712(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 30712);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lfs f9,-26236(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -26236);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f8,17032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	ctx.f8.f64 = double(temp.f32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f7,-20056(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -20056);
	ctx.f7.f64 = double(temp.f32);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lfs f6,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f6.f64 = double(temp.f32);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lfs f5,-16976(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16976);
	ctx.f5.f64 = double(temp.f32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lfs f4,31952(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31952);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,31312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31312);
	ctx.f3.f64 = double(temp.f32);
	// addi r30,r31,152
	r30.s64 = r31.s64 + 152;
	// lfs f2,-6176(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -6176);
	ctx.f2.f64 = double(temp.f32);
	// li r29,13
	r29.s64 = 13;
	// lfs f1,-16980(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -16980);
	ctx.f1.f64 = double(temp.f32);
	// lfs f30,-16984(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -16984);
	f30.f64 = double(temp.f32);
	// lfs f29,-32024(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -32024);
	f29.f64 = double(temp.f32);
	// stfs f13,92(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f12,96(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f11,492(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 492, temp.u32);
	// stfs f0,496(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 496, temp.u32);
	// stfs f31,500(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// stfs f10,504(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 504, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f9,104(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f8,108(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f7,112(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f6,116(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f5,120(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f4,124(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f3,128(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f2,132(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f1,136(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f30,140(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// stfs f29,144(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stfs f31,148(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
loc_826BA7B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,-52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -52);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826b9048
	ctx.lr = 0x826BA7C4;
	sub_826B9048(ctx, base);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x826ba7b8
	if (!cr0.eq) goto loc_826BA7B8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stfs f31,524(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 524, temp.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stfs f31,548(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 548, temp.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f13,-32032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// lfs f0,-9152(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -9152);
	f0.f64 = double(temp.f32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lfs f12,-28964(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28964);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r6,-27500
	ctx.r3.s64 = ctx.r6.s64 + -27500;
	// lfs f11,-31384(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31384);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	ctx.f10.f64 = double(temp.f32);
	// stfs f13,520(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 520, temp.u32);
	// stfs f0,528(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// stfs f12,532(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// stfs f0,544(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 544, temp.u32);
	// stfs f11,540(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 540, temp.u32);
	// stfs f10,536(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// bl 0x821c0750
	ctx.lr = 0x826BA82C;
	sub_821C0750(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826ba840
	if (!cr6.eq) goto loc_826BA840;
	// stw r26,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r26.u32);
loc_826BA840:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826BA854"))) PPC_WEAK_FUNC(sub_826BA854);
PPC_FUNC_IMPL(__imp__sub_826BA854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BA858"))) PPC_WEAK_FUNC(sub_826BA858);
PPC_FUNC_IMPL(__imp__sub_826BA858) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x826bb5e8
	sub_826BB5E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826BA860"))) PPC_WEAK_FUNC(sub_826BA860);
PPC_FUNC_IMPL(__imp__sub_826BA860) {
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
	ctx.lr = 0x826BA868;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r4,r30,12
	ctx.r4.s64 = r30.s64 + 12;
	// bne cr6,0x826ba884
	if (!cr6.eq) goto loc_826BA884;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
loc_826BA884:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r5,204(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x826BA894;
	sub_8268B6D0(ctx, base);
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,208(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b6d0
	ctx.lr = 0x826BA8A8;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,212(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// bl 0x8268b6d0
	ctx.lr = 0x826BA8B8;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,216(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// bl 0x8268b6d0
	ctx.lr = 0x826BA8C8;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,220(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// bl 0x8268b6d0
	ctx.lr = 0x826BA8D8;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,224(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 224);
	// bl 0x8268b6d0
	ctx.lr = 0x826BA8E8;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,228(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// bl 0x8268b6d0
	ctx.lr = 0x826BA8F8;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,232(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// bl 0x8268b6d0
	ctx.lr = 0x826BA908;
	sub_8268B6D0(ctx, base);
	// lhz r11,52(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 52);
	// mr r31,r27
	r31.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ba94c
	if (cr6.eq) goto loc_826BA94C;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_826BA91C:
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// lwzx r11,r11,r29
	r11.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826BA938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,52(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 52);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,28
	r29.s64 = r29.s64 + 28;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x826ba91c
	if (cr6.lt) goto loc_826BA91C;
loc_826BA94C:
	// lhz r8,64(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 64);
	// addi r28,r30,60
	r28.s64 = r30.s64 + 60;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826baa18
	if (!cr6.gt) goto loc_826BAA18;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_826BA964:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ba984
	if (!cr6.eq) goto loc_826BA984;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x826ba964
	if (cr6.lt) goto loc_826BA964;
	// b 0x826baa18
	goto loc_826BAA18;
loc_826BA984:
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r31,60
	ctx.r4.s64 = r31.s64 + 60;
	// bl 0x822b7bd0
	ctx.lr = 0x826BA994;
	sub_822B7BD0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r29,56(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// beq cr6,0x826ba9d0
	if (cr6.eq) goto loc_826BA9D0;
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
	ctx.lr = 0x826BA9B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r31,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r31.u32);
	// sth r8,6(r29)
	PPC_STORE_U16(r29.u32 + 6, ctx.r8.u16);
loc_826BA9D0:
	// lhz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826baa04
	if (!cr6.gt) goto loc_826BAA04;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_826BA9E8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826baa04
	if (!cr6.eq) goto loc_826BAA04;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x826ba9e8
	if (cr6.lt) goto loc_826BA9E8;
loc_826BAA04:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826ba984
	if (!cr6.eq) goto loc_826BA984;
loc_826BAA18:
	// lhz r8,76(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// addi r28,r30,72
	r28.s64 = r30.s64 + 72;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826baa50
	if (!cr6.gt) goto loc_826BAA50;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_826BAA34:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826baa50
	if (!cr6.eq) goto loc_826BAA50;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x826baa34
	if (cr6.lt) goto loc_826BAA34;
loc_826BAA50:
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// beq cr6,0x826baaf4
	if (cr6.eq) goto loc_826BAAF4;
loc_826BAA60:
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r31,60
	ctx.r4.s64 = r31.s64 + 60;
	// bl 0x822b7bd0
	ctx.lr = 0x826BAA70;
	sub_822B7BD0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r29,56(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// beq cr6,0x826baaac
	if (cr6.eq) goto loc_826BAAAC;
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
	ctx.lr = 0x826BAA94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r31,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r31.u32);
	// sth r8,6(r29)
	PPC_STORE_U16(r29.u32 + 6, ctx.r8.u16);
loc_826BAAAC:
	// lhz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826baae0
	if (!cr6.gt) goto loc_826BAAE0;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_826BAAC4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826baae0
	if (!cr6.eq) goto loc_826BAAE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x826baac4
	if (cr6.lt) goto loc_826BAAC4;
loc_826BAAE0:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826baa60
	if (!cr6.eq) goto loc_826BAA60;
loc_826BAAF4:
	// stb r27,84(r30)
	PPC_STORE_U8(r30.u32 + 84, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826BAB00"))) PPC_WEAK_FUNC(sub_826BAB00);
PPC_FUNC_IMPL(__imp__sub_826BAB00) {
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
	ctx.lr = 0x826BAB08;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r10,r30,508
	ctx.r10.s64 = r30.s64 + 508;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbz r9,508(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 508);
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r8,509(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 509);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,510(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 510);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,511(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 511);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// lhz r31,52(r30)
	r31.u64 = PPC_LOAD_U16(r30.u32 + 52);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// stwx r31,r11,r26
	PPC_STORE_U32(r11.u32 + r26.u32, r31.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// stw r5,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r5.u32);
	// ble cr6,0x826bab90
	if (!cr6.gt) goto loc_826BAB90;
	// li r29,0
	r29.s64 = 0;
loc_826BAB70:
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x826bbb98
	ctx.lr = 0x826BAB84;
	sub_826BBB98(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,28
	r29.s64 = r29.s64 + 28;
	// bne 0x826bab70
	if (!cr0.eq) goto loc_826BAB70;
loc_826BAB90:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r27,r30,60
	r27.s64 = r30.s64 + 60;
	// lhz r10,66(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 66);
	// li r31,0
	r31.s64 = 0;
	// stwx r10,r11,r26
	PPC_STORE_U32(r11.u32 + r26.u32, ctx.r10.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// lhz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 64);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826bac38
	if (!cr6.gt) goto loc_826BAC38;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
loc_826BABC0:
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826babe0
	if (!cr6.eq) goto loc_826BABE0;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x826babc0
	if (cr6.lt) goto loc_826BABC0;
	// b 0x826bac38
	goto loc_826BAC38;
loc_826BABE0:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x826bbb98
	ctx.lr = 0x826BABF0;
	sub_826BBB98(ctx, base);
	// lwz r29,8(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826babe0
	if (!cr6.eq) goto loc_826BABE0;
	// lhz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_826BAC08:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x826bac30
	if (!cr6.lt) goto loc_826BAC30;
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r29,r8,r11
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826bac08
	if (cr6.eq) goto loc_826BAC08;
	// b 0x826babe0
	goto loc_826BABE0;
loc_826BAC30:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826babe0
	if (!cr6.eq) goto loc_826BABE0;
loc_826BAC38:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// lhz r10,78(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 78);
	// li r29,0
	r29.s64 = 0;
	// stwx r10,r11,r26
	PPC_STORE_U32(r11.u32 + r26.u32, ctx.r10.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// lhz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826bac84
	if (!cr6.gt) goto loc_826BAC84;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
loc_826BAC68:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826bac8c
	if (!cr6.eq) goto loc_826BAC8C;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x826bac68
	if (cr6.lt) goto loc_826BAC68;
loc_826BAC84:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bace4
	if (cr6.eq) goto loc_826BACE4;
loc_826BAC8C:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x826bbb98
	ctx.lr = 0x826BAC9C;
	sub_826BBB98(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826bac8c
	if (!cr6.eq) goto loc_826BAC8C;
	// lhz r9,76(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
loc_826BACB4:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x826bacdc
	if (!cr6.lt) goto loc_826BACDC;
	// lwz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r31,r8,r11
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bacb4
	if (cr6.eq) goto loc_826BACB4;
	// b 0x826bac8c
	goto loc_826BAC8C;
loc_826BACDC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826bac8c
	if (!cr6.eq) goto loc_826BAC8C;
loc_826BACE4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826BACEC"))) PPC_WEAK_FUNC(sub_826BACEC);
PPC_FUNC_IMPL(__imp__sub_826BACEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BACF0"))) PPC_WEAK_FUNC(sub_826BACF0);
PPC_FUNC_IMPL(__imp__sub_826BACF0) {
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
	ctx.lr = 0x826BACF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r31,r26,508
	r31.s64 = r26.s64 + 508;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r11,r25
	ctx.r10.u64 = r11.u64 + r25.u64;
	// lbzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r25.u32);
	// stb r9,508(r26)
	PPC_STORE_U8(r26.u32 + 508, ctx.r9.u8);
	// lbz r8,1(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// stb r8,509(r26)
	PPC_STORE_U8(r26.u32 + 509, ctx.r8.u8);
	// lbz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// stb r7,510(r26)
	PPC_STORE_U8(r26.u32 + 510, ctx.r7.u8);
	// lbz r6,3(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// stb r6,511(r26)
	PPC_STORE_U8(r26.u32 + 511, ctx.r6.u8);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// stw r5,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r5.u32);
	// bl 0x82387b90
	ctx.lr = 0x826BAD44;
	sub_82387B90(ctx, base);
	// bl 0x8238c5a0
	ctx.lr = 0x826BAD48;
	sub_8238C5A0(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r3,r11,-27500
	ctx.r3.s64 = r11.s64 + -27500;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bad64
	if (cr6.eq) goto loc_826BAD64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c0750
	ctx.lr = 0x826BAD64;
	sub_821C0750(ctx, base);
loc_826BAD64:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r31,r11,r25
	r31.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826bada4
	if (!cr6.gt) goto loc_826BADA4;
	// li r30,0
	r30.s64 = 0;
loc_826BAD80:
	// lwz r11,48(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826bc408
	ctx.lr = 0x826BAD98;
	sub_826BC408(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,28
	r30.s64 = r30.s64 + 28;
	// bne 0x826bad80
	if (!cr0.eq) goto loc_826BAD80;
loc_826BADA4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r29,r26,60
	r29.s64 = r26.s64 + 60;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// li r31,0
	r31.s64 = 0;
	// lwzx r27,r11,r25
	r27.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// lhz r11,64(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826badec
	if (!cr6.gt) goto loc_826BADEC;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_826BADD0:
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826badec
	if (!cr6.eq) goto loc_826BADEC;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x826badd0
	if (cr6.lt) goto loc_826BADD0;
loc_826BADEC:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x826bae50
	if (cr6.eq) goto loc_826BAE50;
loc_826BADF4:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826bc408
	ctx.lr = 0x826BAE08;
	sub_826BC408(ctx, base);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826bae48
	if (!cr6.eq) goto loc_826BAE48;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_826BAE24:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x826bae48
	if (!cr6.lt) goto loc_826BAE48;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r30,r8,r11
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826bae24
	if (cr6.eq) goto loc_826BAE24;
loc_826BAE48:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x826badf4
	if (!cr6.eq) goto loc_826BADF4;
loc_826BAE50:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r29,r11,r25
	r29.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// lhz r10,76(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 76);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826bae94
	if (!cr6.gt) goto loc_826BAE94;
	// lwz r11,72(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 72);
loc_826BAE78:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826bae94
	if (!cr6.eq) goto loc_826BAE94;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x826bae78
	if (cr6.lt) goto loc_826BAE78;
loc_826BAE94:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x826baef8
	if (cr6.eq) goto loc_826BAEF8;
loc_826BAE9C:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826bc408
	ctx.lr = 0x826BAEB0;
	sub_826BC408(ctx, base);
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826baef0
	if (!cr6.eq) goto loc_826BAEF0;
	// lhz r9,76(r26)
	ctx.r9.u64 = PPC_LOAD_U16(r26.u32 + 76);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
loc_826BAECC:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x826baef0
	if (!cr6.lt) goto loc_826BAEF0;
	// lwz r8,72(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 72);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r31,r8,r11
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826baecc
	if (cr6.eq) goto loc_826BAECC;
loc_826BAEF0:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x826bae9c
	if (!cr6.eq) goto loc_826BAE9C;
loc_826BAEF8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826BAF00"))) PPC_WEAK_FUNC(sub_826BAF00);
PPC_FUNC_IMPL(__imp__sub_826BAF00) {
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
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r3,18508(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 18508);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826b9268
	ctx.lr = 0x826BAF24;
	sub_826B9268(ctx, base);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BAF3C"))) PPC_WEAK_FUNC(sub_826BAF3C);
PPC_FUNC_IMPL(__imp__sub_826BAF3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BAF40"))) PPC_WEAK_FUNC(sub_826BAF40);
PPC_FUNC_IMPL(__imp__sub_826BAF40) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r6,r11,-26412
	ctx.r6.s64 = r11.s64 + -26412;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_826BAF68:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_826BAF70:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x826baf94
	if (cr6.eq) goto loc_826BAF94;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826baf70
	if (cr6.eq) goto loc_826BAF70;
loc_826BAF94:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bb004
	if (cr6.eq) goto loc_826BB004;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r11,r6,8
	r11.s64 = ctx.r6.s64 + 8;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// blt cr6,0x826baf68
	if (cr6.lt) goto loc_826BAF68;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826BAFB8;
	sub_821C9790(ctx, base);
	// lhz r11,64(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb030
	if (cr6.eq) goto loc_826BB030;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// twllei r11,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb030
	if (cr6.eq) goto loc_826BB030;
loc_826BAFE8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x826bb024
	if (cr6.eq) goto loc_826BB024;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bafe8
	if (!cr6.eq) goto loc_826BAFE8;
	// b 0x826bb030
	goto loc_826BB030;
loc_826BB004:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mulli r11,r7,28
	r11.s64 = ctx.r7.s64 * 28;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
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
loc_826BB024:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bb09c
	if (!cr6.eq) goto loc_826BB09C;
loc_826BB030:
	// lhz r11,76(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb078
	if (cr6.eq) goto loc_826BB078;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// twllei r11,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb078
	if (cr6.eq) goto loc_826BB078;
loc_826BB060:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x826bb090
	if (cr6.eq) goto loc_826BB090;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bb060
	if (!cr6.eq) goto loc_826BB060;
loc_826BB078:
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_826BB090:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb078
	if (cr6.eq) goto loc_826BB078;
loc_826BB09C:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
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

__attribute__((alias("__imp__sub_826BB0B4"))) PPC_WEAK_FUNC(sub_826BB0B4);
PPC_FUNC_IMPL(__imp__sub_826BB0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BB0B8"))) PPC_WEAK_FUNC(sub_826BB0B8);
PPC_FUNC_IMPL(__imp__sub_826BB0B8) {
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
	ctx.lr = 0x826BB0C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,-16956
	ctx.r9.s64 = r11.s64 + -16956;
	// addi r8,r10,-16968
	ctx.r8.s64 = ctx.r10.s64 + -16968;
	// lwz r29,56(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r30,0
	r30.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r28,r31,12
	r28.s64 = r31.s64 + 12;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826bb128
	if (cr6.eq) goto loc_826BB128;
	// lbz r11,16(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb108
	if (cr6.eq) goto loc_826BB108;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826BB108;
	sub_82130588(ctx, base);
loc_826BB108:
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r30,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r30.u16);
	// sth r30,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r30.u16);
	// stw r30,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r30.u32);
	// stb r30,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r30.u8);
	// bl 0x82130588
	ctx.lr = 0x826BB124;
	sub_82130588(ctx, base);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
loc_826BB128:
	// lwz r29,88(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826bb168
	if (cr6.eq) goto loc_826BB168;
	// lbz r11,16(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb148
	if (cr6.eq) goto loc_826BB148;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826BB148;
	sub_82130588(ctx, base);
loc_826BB148:
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r30,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r30.u16);
	// sth r30,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r30.u16);
	// stw r30,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r30.u32);
	// stb r30,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r30.u8);
	// bl 0x82130588
	ctx.lr = 0x826BB164;
	sub_82130588(ctx, base);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
loc_826BB168:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r31,428
	ctx.r3.s64 = r31.s64 + 428;
	// addi r30,r11,3888
	r30.s64 = r11.s64 + 3888;
	// stw r30,428(r31)
	PPC_STORE_U32(r31.u32 + 428, r30.u32);
	// bl 0x821d2028
	ctx.lr = 0x826BB17C;
	sub_821D2028(ctx, base);
	// stw r30,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r30.u32);
	// addi r3,r31,332
	ctx.r3.s64 = r31.s64 + 332;
	// bl 0x821d2028
	ctx.lr = 0x826BB188;
	sub_821D2028(ctx, base);
	// stw r30,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r30.u32);
	// addi r3,r31,236
	ctx.r3.s64 = r31.s64 + 236;
	// bl 0x821d2028
	ctx.lr = 0x826BB194;
	sub_821D2028(ctx, base);
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// bl 0x82608de8
	ctx.lr = 0x826BB19C;
	sub_82608DE8(ctx, base);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x82608de8
	ctx.lr = 0x826BB1A4;
	sub_82608DE8(ctx, base);
	// lhz r5,54(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 54);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826bb1bc
	if (cr6.eq) goto loc_826BB1BC;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x826b9558
	ctx.lr = 0x826BB1BC;
	sub_826B9558(ctx, base);
loc_826BB1BC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x824e0430
	ctx.lr = 0x826BB1D0;
	sub_824E0430(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826BB1D8"))) PPC_WEAK_FUNC(sub_826BB1D8);
PPC_FUNC_IMPL(__imp__sub_826BB1D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x826BB1E0;
	// stwu r1,-896(r1)
	ea = -896 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r19,r11,30576
	r19.s64 = r11.s64 + 30576;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r4,r10,-16884
	ctx.r4.s64 = ctx.r10.s64 + -16884;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821ca540
	ctx.lr = 0x826BB200;
	sub_821CA540(ctx, base);
	// li r18,0
	r18.s64 = 0;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r20,r18
	r20.u64 = r18.u64;
	// addi r21,r3,-30140
	r21.s64 = ctx.r3.s64 + -30140;
	// addi r26,r4,-29924
	r26.s64 = ctx.r4.s64 + -29924;
	// addi r29,r5,-29628
	r29.s64 = ctx.r5.s64 + -29628;
	// addi r28,r6,10380
	r28.s64 = ctx.r6.s64 + 10380;
	// addi r27,r7,-29624
	r27.s64 = ctx.r7.s64 + -29624;
	// addi r31,r8,-15196
	r31.s64 = ctx.r8.s64 + -15196;
	// addi r25,r9,-16904
	r25.s64 = ctx.r9.s64 + -16904;
	// addi r24,r10,-32764
	r24.s64 = ctx.r10.s64 + -32764;
	// addi r23,r11,-16924
	r23.s64 = r11.s64 + -16924;
loc_826BB250:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82137a08
	ctx.lr = 0x826BB264;
	sub_82137A08(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x821ca6a8
	ctx.lr = 0x826BB27C;
	sub_821CA6A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826bb348
	if (cr6.eq) goto loc_826BB348;
	// stw r26,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r26.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// stw r18,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, r18.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cf7b8
	ctx.lr = 0x826BB2A0;
	sub_821CF7B8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cff40
	ctx.lr = 0x826BB2B0;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb33c
	if (cr6.eq) goto loc_826BB33C;
loc_826BB2BC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe20
	ctx.lr = 0x826BB2C8;
	sub_821CFE20(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x826BB2D4;
	sub_821D0898(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe20
	ctx.lr = 0x826BB2E0;
	sub_821CFE20(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826BB2F0;
	sub_821CFAA8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826baf40
	ctx.lr = 0x826BB2FC;
	sub_826BAF40(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// bl 0x826bbcb8
	ctx.lr = 0x826BB308;
	sub_826BBCB8(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x826bc128
	ctx.lr = 0x826BB314;
	sub_826BC128(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe20
	ctx.lr = 0x826BB320;
	sub_821CFE20(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cff40
	ctx.lr = 0x826BB330;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bb2bc
	if (!cr6.eq) goto loc_826BB2BC;
loc_826BB33C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x826BB344;
	sub_821BE610(ctx, base);
	// stw r21,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r21.u32);
loc_826BB348:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// cmpwi cr6,r20,5
	cr6.compare<int32_t>(r20.s32, 5, xer);
	// blt cr6,0x826bb250
	if (cr6.lt) goto loc_826BB250;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826BB35C;
	sub_821C9A90(ctx, base);
	// addi r1,r1,896
	ctx.r1.s64 = ctx.r1.s64 + 896;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_826BB364"))) PPC_WEAK_FUNC(sub_826BB364);
PPC_FUNC_IMPL(__imp__sub_826BB364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BB368"))) PPC_WEAK_FUNC(sub_826BB368);
PPC_FUNC_IMPL(__imp__sub_826BB368) {
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
	ctx.lr = 0x826BB370;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// bne cr6,0x826bb38c
	if (!cr6.eq) goto loc_826BB38C;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
loc_826BB38C:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-18544
	ctx.r5.s64 = r11.s64 + -18544;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x826BB3A4;
	sub_8268B960(ctx, base);
	// stw r3,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r3.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// addi r5,r10,-16808
	ctx.r5.s64 = ctx.r10.s64 + -16808;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x8268b960
	ctx.lr = 0x826BB3C4;
	sub_8268B960(ctx, base);
	// stw r3,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r3.u32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r9,-16832
	ctx.r5.s64 = ctx.r9.s64 + -16832;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x8268b960
	ctx.lr = 0x826BB3E0;
	sub_8268B960(ctx, base);
	// stw r3,212(r31)
	PPC_STORE_U32(r31.u32 + 212, ctx.r3.u32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r8,-16856
	ctx.r5.s64 = ctx.r8.s64 + -16856;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x8268b960
	ctx.lr = 0x826BB3FC;
	sub_8268B960(ctx, base);
	// stw r3,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,-18584
	ctx.r5.s64 = ctx.r7.s64 + -18584;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x8268b960
	ctx.lr = 0x826BB418;
	sub_8268B960(ctx, base);
	// stw r3,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r6,-18628
	ctx.r5.s64 = ctx.r6.s64 + -18628;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x8268b960
	ctx.lr = 0x826BB434;
	sub_8268B960(ctx, base);
	// stw r3,224(r31)
	PPC_STORE_U32(r31.u32 + 224, ctx.r3.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r5,-18608
	ctx.r5.s64 = ctx.r5.s64 + -18608;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x8268b960
	ctx.lr = 0x826BB450;
	sub_8268B960(ctx, base);
	// stw r3,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r3.u32);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r4,-16868
	ctx.r5.s64 = ctx.r4.s64 + -16868;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268b960
	ctx.lr = 0x826BB46C;
	sub_8268B960(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r28,r11,-25924
	r28.s64 = r11.s64 + -25924;
	// stw r3,232(r31)
	PPC_STORE_U32(r31.u32 + 232, ctx.r3.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r27,r31,60
	r27.s64 = r31.s64 + 60;
	// mr r29,r28
	r29.u64 = r28.u64;
	// ori r26,r10,65535
	r26.u64 = ctx.r10.u64 | 65535;
	// addi r25,r11,-17104
	r25.s64 = r11.s64 + -17104;
loc_826BB490:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r30,12(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// add r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 + r26.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// sth r9,6(r11)
	PPC_STORE_U16(r11.u32 + 6, ctx.r9.u16);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// beq cr6,0x826bb4c8
	if (cr6.eq) goto loc_826BB4C8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826bbe70
	ctx.lr = 0x826BB4BC;
	sub_826BBE70(ctx, base);
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// stw r24,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r24.u32);
	// b 0x826bb4cc
	goto loc_826BB4CC;
loc_826BB4C8:
	// mr r30,r24
	r30.u64 = r24.u64;
loc_826BB4CC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// bl 0x826bbb48
	ctx.lr = 0x826BB4DC;
	sub_826BBB48(ctx, base);
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82389998
	ctx.lr = 0x826BB4F4;
	sub_82389998(ctx, base);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r10,r28,36
	ctx.r10.s64 = r28.s64 + 36;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x826bb490
	if (cr6.lt) goto loc_826BB490;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r27,r31,72
	r27.s64 = r31.s64 + 72;
	// addi r28,r11,-28116
	r28.s64 = r11.s64 + -28116;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_826BB514:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r30,12(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// add r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 + r26.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// sth r9,6(r11)
	PPC_STORE_U16(r11.u32 + 6, ctx.r9.u16);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// beq cr6,0x826bb54c
	if (cr6.eq) goto loc_826BB54C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826bbe70
	ctx.lr = 0x826BB540;
	sub_826BBE70(ctx, base);
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// stw r24,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r24.u32);
	// b 0x826bb550
	goto loc_826BB550;
loc_826BB54C:
	// mr r30,r24
	r30.u64 = r24.u64;
loc_826BB550:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// bl 0x826bbb48
	ctx.lr = 0x826BB560;
	sub_826BBB48(ctx, base);
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82389998
	ctx.lr = 0x826BB578;
	sub_82389998(ctx, base);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r10,r28,20
	ctx.r10.s64 = r28.s64 + 20;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x826bb514
	if (cr6.lt) goto loc_826BB514;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826bb1d8
	ctx.lr = 0x826BB590;
	sub_826BB1D8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826BB5A0"))) PPC_WEAK_FUNC(sub_826BB5A0);
PPC_FUNC_IMPL(__imp__sub_826BB5A0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x826b9928
	ctx.lr = 0x826BB5C8;
	sub_826B9928(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_826BB5E4"))) PPC_WEAK_FUNC(sub_826BB5E4);
PPC_FUNC_IMPL(__imp__sub_826BB5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BB5E8"))) PPC_WEAK_FUNC(sub_826BB5E8);
PPC_FUNC_IMPL(__imp__sub_826BB5E8) {
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
	// bl 0x826bb0b8
	ctx.lr = 0x826BB608;
	sub_826BB0B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bb620
	if (cr6.eq) goto loc_826BB620;
	// bl 0x82130588
	ctx.lr = 0x826BB61C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826BB620:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BB638"))) PPC_WEAK_FUNC(sub_826BB638);
PPC_FUNC_IMPL(__imp__sub_826BB638) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x826baf40
	ctx.lr = 0x826BB660;
	sub_826BAF40(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_826BB67C"))) PPC_WEAK_FUNC(sub_826BB67C);
PPC_FUNC_IMPL(__imp__sub_826BB67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BB680"))) PPC_WEAK_FUNC(sub_826BB680);
PPC_FUNC_IMPL(__imp__sub_826BB680) {
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
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-26632
	ctx.r4.s64 = r11.s64 + -26632;
	// addi r3,r10,-16484
	ctx.r3.s64 = ctx.r10.s64 + -16484;
	// bl 0x82554798
	ctx.lr = 0x826BB6A0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-20736
	ctx.r4.s64 = ctx.r9.s64 + -20736;
	// addi r3,r8,-16524
	ctx.r3.s64 = ctx.r8.s64 + -16524;
	// bl 0x82554798
	ctx.lr = 0x826BB6B4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-18888
	ctx.r4.s64 = ctx.r7.s64 + -18888;
	// addi r3,r6,-16564
	ctx.r3.s64 = ctx.r6.s64 + -16564;
	// bl 0x82554798
	ctx.lr = 0x826BB6C8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-19040
	ctx.r4.s64 = ctx.r5.s64 + -19040;
	// addi r3,r3,-16608
	ctx.r3.s64 = ctx.r3.s64 + -16608;
	// bl 0x82554798
	ctx.lr = 0x826BB6DC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-26592
	ctx.r4.s64 = r11.s64 + -26592;
	// addi r3,r10,-16640
	ctx.r3.s64 = ctx.r10.s64 + -16640;
	// bl 0x82554798
	ctx.lr = 0x826BB6F0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-26568
	ctx.r4.s64 = ctx.r9.s64 + -26568;
	// addi r3,r8,-16680
	ctx.r3.s64 = ctx.r8.s64 + -16680;
	// bl 0x82554798
	ctx.lr = 0x826BB704;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-26488
	ctx.r4.s64 = ctx.r7.s64 + -26488;
	// addi r3,r6,-16712
	ctx.r3.s64 = ctx.r6.s64 + -16712;
	// bl 0x82554798
	ctx.lr = 0x826BB718;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-26464
	ctx.r4.s64 = ctx.r5.s64 + -26464;
	// addi r3,r3,-16744
	ctx.r3.s64 = ctx.r3.s64 + -16744;
	// bl 0x82554798
	ctx.lr = 0x826BB72C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-26384
	ctx.r4.s64 = r11.s64 + -26384;
	// addi r3,r10,-16780
	ctx.r3.s64 = ctx.r10.s64 + -16780;
	// bl 0x82554798
	ctx.lr = 0x826BB740;
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

__attribute__((alias("__imp__sub_826BB750"))) PPC_WEAK_FUNC(sub_826BB750);
PPC_FUNC_IMPL(__imp__sub_826BB750) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x826BB758;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,200(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 200);
	// lwz r10,8(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r24,3100(r27)
	r24.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r25,52(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826BB780;
	sub_8238EFE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x826b95c0
	ctx.lr = 0x826BB78C;
	sub_826B95C0(ctx, base);
	// lwz r9,3080(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 3080);
	// lwz r8,172(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 172);
	// li r26,0
	r26.s64 = 0;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// subf r11,r8,r9
	r11.s64 = ctx.r9.s64 - ctx.r8.s64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lis r29,-32121
	r29.s64 = -2105081856;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fdivs f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 / ctx.f12.f64));
	// fmuls f31,f8,f1
	f31.f64 = double(float(ctx.f8.f64 * ctx.f1.f64));
	// bne cr6,0x826bb860
	if (!cr6.eq) goto loc_826BB860;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,9720
	ctx.r4.s64 = ctx.r9.s64 + 9720;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x826BB804;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,10248(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821fd7c0
	ctx.lr = 0x826BB818;
	sub_821FD7C0(ctx, base);
	// lwz r3,324(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r26,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r26.u8);
	// stw r26,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r26.u32);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// stw r8,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r8.u32);
	// beq cr6,0x826bb848
	if (cr6.eq) goto loc_826BB848;
	// bl 0x822031a8
	ctx.lr = 0x826BB844;
	sub_822031A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_826BB848:
	// addi r30,r31,428
	r30.s64 = r31.s64 + 428;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b6870
	ctx.lr = 0x826BB854;
	sub_826B6870(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,18504(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826BB860;
	sub_826B5CF0(ctx, base);
loc_826BB860:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x826bb934
	if (!cr6.gt) goto loc_826BB934;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fmuls f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 * f0.f64));
	// lfs f0,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f31,f9,f0
	f31.f64 = double(float(ctx.f9.f64 * f0.f64));
	// bl 0x82387a18
	ctx.lr = 0x826BB8AC;
	sub_82387A18(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r28,r11,-26412
	r28.s64 = r11.s64 + -26412;
	// bne cr6,0x826bb8f8
	if (!cr6.eq) goto loc_826BB8F8;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r3,r31,296
	ctx.r3.s64 = r31.s64 + 296;
	// bl 0x823db670
	ctx.lr = 0x826BB8D0;
	sub_823DB670(ctx, base);
	// addi r30,r31,236
	r30.s64 = r31.s64 + 236;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x826b6580
	ctx.lr = 0x826BB8E8;
	sub_826B6580(ctx, base);
	// stb r26,245(r31)
	PPC_STORE_U8(r31.u32 + 245, r26.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,18504(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826BB8F8;
	sub_826B5CF0(ctx, base);
loc_826BB8F8:
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r3,r31,392
	ctx.r3.s64 = r31.s64 + 392;
	// bl 0x823db670
	ctx.lr = 0x826BB908;
	sub_823DB670(ctx, base);
	// addi r30,r31,332
	r30.s64 = r31.s64 + 332;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x826b6580
	ctx.lr = 0x826BB920;
	sub_826B6580(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,340(r31)
	PPC_STORE_U8(r31.u32 + 340, r11.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,18504(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 18504);
	// bl 0x826b5cf0
	ctx.lr = 0x826BB934;
	sub_826B5CF0(ctx, base);
loc_826BB934:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8238f998
	ctx.lr = 0x826BB93C;
	sub_8238F998(ctx, base);
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// bl 0x82396058
	ctx.lr = 0x826BB944;
	sub_82396058(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b9928
	ctx.lr = 0x826BB950;
	sub_826B9928(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bb964
	if (cr6.eq) goto loc_826BB964;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826bc348
	ctx.lr = 0x826BB964;
	sub_826BC348(ctx, base);
loc_826BB964:
	// lbz r11,8108(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 8108);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x826bb9a0
	if (cr6.eq) goto loc_826BB9A0;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-28116
	ctx.r8.s64 = ctx.r10.s64 + -28116;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// bl 0x826b9928
	ctx.lr = 0x826BB98C;
	sub_826B9928(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bb9a0
	if (cr6.eq) goto loc_826BB9A0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826bc348
	ctx.lr = 0x826BB9A0;
	sub_826BC348(ctx, base);
loc_826BB9A0:
	// bl 0x82387a18
	ctx.lr = 0x826BB9A4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bb9d0
	if (!cr6.eq) goto loc_826BB9D0;
	// lwz r11,172(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 172);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r3,-21492(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21492);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x82742f28
	ctx.lr = 0x826BB9D0;
	sub_82742F28(ctx, base);
loc_826BB9D0:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826BB9DC"))) PPC_WEAK_FUNC(sub_826BB9DC);
PPC_FUNC_IMPL(__imp__sub_826BB9DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BB9E0"))) PPC_WEAK_FUNC(sub_826BB9E0);
PPC_FUNC_IMPL(__imp__sub_826BB9E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x826BB9E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r29,48(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82387a98
	ctx.lr = 0x826BBA08;
	sub_82387A98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826bbb38
	if (!cr6.eq) goto loc_826BBB38;
	// bl 0x82387a18
	ctx.lr = 0x826BBA18;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bba3c
	if (!cr6.eq) goto loc_826BBA3C;
	// addis r3,r29,3
	ctx.r3.s64 = r29.s64 + 196608;
	// addi r3,r3,-21024
	ctx.r3.s64 = ctx.r3.s64 + -21024;
	// bl 0x82397470
	ctx.lr = 0x826BBA30;
	sub_82397470(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bbb38
	if (!cr6.eq) goto loc_826BBB38;
loc_826BBA3C:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x826bbb2c
	if (cr6.eq) goto loc_826BBB2C;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x826bbb2c
	if (cr6.eq) goto loc_826BBB2C;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x826bba78
	if (!cr6.eq) goto loc_826BBA78;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,-12
	ctx.r3.s64 = r31.s64 + -12;
	// bl 0x826b99a0
	ctx.lr = 0x826BBA6C;
	sub_826B99A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826BBA78:
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x826bba9c
	if (!cr6.eq) goto loc_826BBA9C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,-12
	ctx.r3.s64 = r31.s64 + -12;
	// bl 0x826b9df8
	ctx.lr = 0x826BBA90;
	sub_826B9DF8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826BBA9C:
	// lwz r11,204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x826bbac0
	if (!cr6.eq) goto loc_826BBAC0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,-12
	ctx.r3.s64 = r31.s64 + -12;
	// bl 0x826b9f40
	ctx.lr = 0x826BBAB4;
	sub_826B9F40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826BBAC0:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x826bbae4
	if (!cr6.eq) goto loc_826BBAE4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,-12
	ctx.r3.s64 = r31.s64 + -12;
	// bl 0x826ba198
	ctx.lr = 0x826BBAD8;
	sub_826BA198(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826BBAE4:
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x826bbb08
	if (!cr6.eq) goto loc_826BBB08;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,-12
	ctx.r3.s64 = r31.s64 + -12;
	// bl 0x826bb750
	ctx.lr = 0x826BBAFC;
	sub_826BB750(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826BBB08:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x826bbb38
	if (!cr6.eq) goto loc_826BBB38;
	// addi r3,r31,-12
	ctx.r3.s64 = r31.s64 + -12;
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826ba238
	ctx.lr = 0x826BBB20;
	sub_826BA238(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826BBB2C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,-12
	ctx.r3.s64 = r31.s64 + -12;
	// bl 0x826b9ae8
	ctx.lr = 0x826BBB38;
	sub_826B9AE8(ctx, base);
loc_826BBB38:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826BBB44"))) PPC_WEAK_FUNC(sub_826BBB44);
PPC_FUNC_IMPL(__imp__sub_826BBB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BBB48"))) PPC_WEAK_FUNC(sub_826BBB48);
PPC_FUNC_IMPL(__imp__sub_826BBB48) {
	PPC_FUNC_PROLOGUE();
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
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823db670
	ctx.lr = 0x826BBB70;
	sub_823DB670(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x826BBB7C;
	sub_821C9790(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BBB98"))) PPC_WEAK_FUNC(sub_826BBB98);
PPC_FUNC_IMPL(__imp__sub_826BBB98) {
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
	ctx.lr = 0x826BBBA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r8,9(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 9);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,10(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,11(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 11);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lhz r28,20(r31)
	r28.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stwx r28,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, r28.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
	// ble cr6,0x826bbc28
	if (!cr6.gt) goto loc_826BBC28;
	// li r27,0
	r27.s64 = 0;
loc_826BBC08:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x826bc590
	ctx.lr = 0x826BBC1C;
	sub_826BC590(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x826bbc08
	if (!cr0.eq) goto loc_826BBC08;
loc_826BBC28:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826BBC30"))) PPC_WEAK_FUNC(sub_826BBC30);
PPC_FUNC_IMPL(__imp__sub_826BBC30) {
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
	ctx.lr = 0x826BBC38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826bbc94
	if (cr6.eq) goto loc_826BBC94;
	// lhz r11,20(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bbc94
	if (cr6.eq) goto loc_826BBC94;
	// li r31,0
	r31.s64 = 0;
loc_826BBC60:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bl 0x823dd800
	ctx.lr = 0x826BBC78;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826bbca0
	if (cr6.eq) goto loc_826BBCA0;
	// lhz r11,20(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826bbc60
	if (cr6.lt) goto loc_826BBC60;
loc_826BBC94:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826BBCA0:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826BBCB4"))) PPC_WEAK_FUNC(sub_826BBCB4);
PPC_FUNC_IMPL(__imp__sub_826BBCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BBCB8"))) PPC_WEAK_FUNC(sub_826BBCB8);
PPC_FUNC_IMPL(__imp__sub_826BBCB8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826b9268
	ctx.lr = 0x826BBCD8;
	sub_826B9268(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_826BBCF0"))) PPC_WEAK_FUNC(sub_826BBCF0);
PPC_FUNC_IMPL(__imp__sub_826BBCF0) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826BBCF8;
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// blt cr6,0x826bbd90
	if (cr6.lt) goto loc_826BBD90;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826bbd74
	if (!cr6.gt) goto loc_826BBD74;
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x826bbd34
	if (!cr6.gt) goto loc_826BBD34;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_826BBD34:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fdivs f1,f10,f9
	ctx.f1.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-64(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_826BBD74:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-64(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_826BBD90:
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// ble cr6,0x826bbda0
	if (!cr6.gt) goto loc_826BBDA0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_826BBDA0:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,18508(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 18508);
	// bl 0x826b92c8
	ctx.lr = 0x826BBDAC;
	sub_826B92C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,18508(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 18508);
	// addi r11,r30,38
	r11.s64 = r30.s64 + 38;
	// addic. r4,r30,1
	xer.ca = r30.u32 > 4294967294;
	ctx.r4.s64 = r30.s64 + 1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r10,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	f30.f64 = double(temp.f32);
	// bge 0x826bbdd0
	if (!cr0.lt) goto loc_826BBDD0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x826bbddc
	goto loc_826BBDDC;
loc_826BBDD0:
	// cmpwi cr6,r4,12
	cr6.compare<int32_t>(ctx.r4.s32, 12, xer);
	// ble cr6,0x826bbddc
	if (!cr6.gt) goto loc_826BBDDC;
	// li r4,12
	ctx.r4.s64 = 12;
loc_826BBDDC:
	// addi r11,r4,38
	r11.s64 = ctx.r4.s64 + 38;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r10,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	f31.f64 = double(temp.f32);
	// bl 0x826b9310
	ctx.lr = 0x826BBDF0;
	sub_826B9310(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b9310
	ctx.lr = 0x826BBE00;
	sub_826B9310(ctx, base);
	// fsubs f0,f31,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - f30.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f31,f29,f1
	f31.f64 = double(float(f29.f64 - ctx.f1.f64));
	// lfs f13,8884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x826bbe4c
	if (!cr6.gt) goto loc_826BBE4C;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x826bbe2c
	if (!cr6.gt) goto loc_826BBE2C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_826BBE2C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 - f30.f64));
	// fdivs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 / f0.f64));
	// fmuls f31,f9,f31
	f31.f64 = double(float(ctx.f9.f64 * f31.f64));
loc_826BBE4C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,18508(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 18508);
	// bl 0x826b9310
	ctx.lr = 0x826BBE58;
	sub_826B9310(ctx, base);
	// fadds f1,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 + f31.f64));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-64(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

